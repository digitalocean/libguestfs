/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2016 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#include "daemon.h"
#include "c-ctype.h"
#include "actions.h"
#include "optgroups.h"

GUESTFSD_EXT_CMD(str_lvm, lvm);

int
optgroup_lvm2_available (void)
{
  return prog_exists (str_lvm);
}

/* LVM actions.  Keep an eye on liblvm, although at the time
 * of writing it hasn't progressed very far.
 */

static char **
convert_lvm_output (char *out, const char *prefix)
{
  char *p, *pend;
  DECLARE_STRINGSBUF (ret);
  size_t len;
  char buf[256];
  char *str;

  p = out;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    /* Sigh, skip trailing whitespace too.  "pvs", I'm looking at you. */
    len = strlen (p)-1;
    while (*p && c_isspace (p[len]))
      p[len--] = '\0';

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Prefix? */
    if (prefix) {
      snprintf (buf, sizeof buf, "%s%s", prefix, p);
      str = buf;
    } else
      str = p;

    /* Ignore "unknown device" message (RHBZ#1054761). */
    if (STRNEQ (str, "unknown device")) {
      if (add_string (&ret, str) == -1) {
        free (out);
        return NULL;
      }
    }

    p = pend;
  }

  free (out);

  if (ret.size > 0)
    sort_strings (ret.argv, ret.size);

  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

/* Filter a colon-separated output of
 *   lvs -o lv_attr,vg_name,lv_name
 * removing thin layouts, and building the device path as we expect it.
 *
 * This is used only when lvm has no -S.
 */
static char **
filter_convert_old_lvs_output (char *out)
{
  char *p, *pend;
  DECLARE_STRINGSBUF (ret);

  p = out;
  while (p) {
    size_t len;
    char *saveptr;
    char *lv_attr, *vg_name, *lv_name;

    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    /* Sigh, skip trailing whitespace too.  "pvs", I'm looking at you. */
    len = strlen (p)-1;
    while (*p && c_isspace (p[len]))
      p[len--] = '\0';

    if (!*p) {			/* Empty line?  Skip it. */
    skip_line:
      p = pend;
      continue;
    }

    lv_attr = strtok_r (p, ":", &saveptr);
    if (!lv_attr)
      goto skip_line;

    vg_name = strtok_r (NULL, ":", &saveptr);
    if (!vg_name)
      goto skip_line;

    lv_name = strtok_r (NULL, ":", &saveptr);
    if (!lv_name)
      goto skip_line;

    /* Ignore thin layouts (RHBZ#1278878). */
    if (lv_attr[0] == 't')
      goto skip_line;

    /* Ignore activationskip (RHBZ#1306666). */
    if (strlen (lv_attr) >= 10 && lv_attr[9] == 'k')
      goto skip_line;

    /* Ignore "unknown device" message (RHBZ#1054761). */
    if (STRNEQ (p, "unknown device")) {
      char buf[256];

      snprintf (buf, sizeof buf, "/dev/%s/%s", vg_name, lv_name);
      if (add_string (&ret, buf) == -1) {
        free (out);
        return NULL;
      }
    }

    p = pend;
  }

  free (out);

  if (ret.size > 0)
    sort_strings (ret.argv, ret.size);

  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

char **
do_pvs (void)
{
  char *out;
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (&out, &err,
               str_lvm, "pvs", "-o", "pv_name", "--noheadings", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    return NULL;
  }

  return convert_lvm_output (out, NULL);
}

char **
do_vgs (void)
{
  char *out;
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (&out, &err,
               str_lvm, "vgs", "-o", "vg_name", "--noheadings", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    return NULL;
  }

  return convert_lvm_output (out, NULL);
}

/* Check whether lvs has -S to filter its output.
 * It is available only in lvm2 >= 2.02.107.
 */
static int
test_lvs_has_S_opt (void)
{
  static int result = -1;
  if (result != -1)
    return result;

  CLEANUP_FREE char *out = NULL;
  CLEANUP_FREE char *err = NULL;

  int r = command (&out, &err, str_lvm, "lvs", "--help", NULL);
  if (r == -1) {
    reply_with_error ("lvm lvs --help: %s", err);
    return -1;
  }

  if (strstr (out, "-S") == NULL)
    result = 0;
  else
    result = 1;

  return result;
}

char **
do_lvs (void)
{
  char *out;
  CLEANUP_FREE char *err = NULL;
  int r;
  int has_S = test_lvs_has_S_opt ();

  if (has_S < 0)
    return NULL;

  if (has_S > 0) {
    r = command (&out, &err,
                 str_lvm, "lvs",
                 "-o", "vg_name,lv_name",
                 "-S", "lv_role=public && lv_active=active",
                 "--noheadings",
                 "--separator", "/", NULL);
    if (r == -1) {
      reply_with_error ("%s", err);
      free (out);
      return NULL;
    }

    return convert_lvm_output (out, "/dev/");
  } else {
    r = command (&out, &err,
                 str_lvm, "lvs",
                 "-o", "lv_attr,vg_name,lv_name",
                 "--noheadings",
                 "--separator", ":", NULL);
    if (r == -1) {
      reply_with_error ("%s", err);
      free (out);
      return NULL;
    }

    return filter_convert_old_lvs_output (out);
  }
}

/* These were so complex to implement that I ended up auto-generating
 * the code.  That code is in stubs.c, and it is generated as usual
 * by generator.ml.
 */
guestfs_int_lvm_pv_list *
do_pvs_full (void)
{
  return parse_command_line_pvs ();
}

guestfs_int_lvm_vg_list *
do_vgs_full (void)
{
  return parse_command_line_vgs ();
}

guestfs_int_lvm_lv_list *
do_lvs_full (void)
{
  return parse_command_line_lvs ();
}

int
do_pvcreate (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "pvcreate", "--force", device, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vgcreate (const char *volgroup, char *const *physvols)
{
  int r, argc, i;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE const char **argv = NULL;

  argc = count_strings (physvols) + 3;
  argv = malloc (sizeof (char *) * (argc + 1));
  if (argv == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }
  argv[0] = str_lvm;
  argv[1] = "vgcreate";
  argv[2] = volgroup;
  for (i = 3; i < argc+1; ++i)
    argv[i] = physvols[i-3];

  r = commandv (NULL, &err, (const char * const*) argv);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_lvcreate (const char *logvol, const char *volgroup, int mbytes)
{
  CLEANUP_FREE char *err = NULL;
  int r;
  char size[64];

  snprintf (size, sizeof size, "%d", mbytes);

  r = command (NULL, &err,
               str_lvm, "lvcreate",
               "-L", size, "-n", logvol, volgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_lvcreate_free (const char *logvol, const char *volgroup, int percent)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  if (percent < 0 || percent > 100) {
    reply_with_error ("percentage must be [0..100] (was %d)", percent);
    return -1;
  }

  char size[64];
  snprintf (size, sizeof size, "%d%%FREE", percent);

  r = command (NULL, &err,
               str_lvm, "lvcreate",
               "-l", size, "-n", logvol, volgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

/* The lvresize command unnecessarily gives an error if you don't
 * change the size of the LV.  Suppress this error.
 * https://bugzilla.redhat.com/show_bug.cgi?id=834712
 */
static int
ignore_same_size_error (const char *err)
{
  return strstr (err, "New size (") != NULL &&
    strstr (err, "extents) matches existing size (") != NULL;
}

int
do_lvresize (const char *logvol, int mbytes)
{
  CLEANUP_FREE char *err = NULL;
  int r;
  char size[64];

  snprintf (size, sizeof size, "%d", mbytes);

  r = command (NULL, &err,
               str_lvm, "lvresize",
               "--force", "-L", size, logvol, NULL);
  if (r == -1) {
    if (!ignore_same_size_error (err)) {
      reply_with_error ("%s", err);
      return -1;
    }
  }

  return 0;
}

int
do_lvresize_free (const char *logvol, int percent)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  if (percent < 0 || percent > 100) {
    reply_with_error ("percentage must be [0..100] (was %d)", percent);
    return -1;
  }

  char size[64];
  snprintf (size, sizeof size, "+%d%%FREE", percent);

  r = command (NULL, &err,
               str_lvm, "lvresize", "-l", size, logvol, NULL);
  if (r == -1) {
    if (!ignore_same_size_error (err)) {
      reply_with_error ("%s", err);
      return -1;
    }
  }

  return 0;
}

/* Super-dangerous command used for testing.  It removes all
 * LVs, VGs and PVs permanently.
 */
int
do_lvm_remove_all (void)
{
  size_t i;
  int r;

  {
    /* Remove LVs. */
    CLEANUP_FREE_STRING_LIST char **xs = do_lvs ();
    if (xs == NULL)
      return -1;

    for (i = 0; xs[i] != NULL; ++i) {
      CLEANUP_FREE char *err = NULL;

      /* Deactivate the LV first.  On Ubuntu, lvremove '-f' option
       * does not remove active LVs reliably.
       */
      (void) command (NULL, NULL, str_lvm, "lvchange", "-an", xs[i], NULL);
      udev_settle ();

      r = command (NULL, &err, str_lvm, "lvremove", "-f", xs[i], NULL);
      if (r == -1) {
        reply_with_error ("lvremove: %s: %s", xs[i], err);
        return -1;
      }
    }
  }

  {
    /* Remove VGs. */
    CLEANUP_FREE_STRING_LIST char **xs = do_vgs ();
    if (xs == NULL)
      return -1;

    for (i = 0; xs[i] != NULL; ++i) {
      CLEANUP_FREE char *err = NULL;

      /* Deactivate the VG first, see note above. */
      (void) command (NULL, NULL, str_lvm, "vgchange", "-an", xs[i], NULL);
      udev_settle ();

      r = command (NULL, &err, str_lvm, "vgremove", "-f", xs[i], NULL);
      if (r == -1) {
        reply_with_error ("vgremove: %s: %s", xs[i], err);
        return -1;
      }
    }
  }

  {
    /* Remove PVs. */
    CLEANUP_FREE_STRING_LIST char **xs = do_pvs ();
    if (xs == NULL)
      return -1;

    for (i = 0; xs[i] != NULL; ++i) {
      CLEANUP_FREE char *err = NULL;

      r = command (NULL, &err, str_lvm, "pvremove", "-f", xs[i], NULL);
      if (r == -1) {
        reply_with_error ("pvremove: %s: %s", xs[i], err);
        return -1;
      }
    }
  }

  udev_settle ();

  /* There, that was easy, sorry about your data. */
  return 0;
}

int
do_lvremove (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "lvremove", "-f", device, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vgremove (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "vgremove", "-f", device, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_pvremove (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "pvremove", "-ff", device, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_pvresize (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "pvresize", device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_pvresize_size (const char *device, int64_t size)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  char buf[32];
  snprintf (buf, sizeof buf, "%" PRIi64 "b", size);

  r = command (NULL, &err,
               str_lvm, "pvresize",
               "--setphysicalvolumesize", buf,
               device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_vg_activate (int activate, char *const *volgroups)
{
  int r, i, argc;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE const char **argv = NULL;

  argc = count_strings (volgroups) + 4;
  argv = malloc (sizeof (char *) * (argc+1));
  if (argv == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  argv[0] = str_lvm;
  argv[1] = "vgchange";
  argv[2] = "-a";
  argv[3] = activate ? "y" : "n";
  for (i = 4; i < argc+1; ++i)
    argv[i] = volgroups[i-4];

  r = commandv (NULL, &err, (const char * const*) argv);
  if (r == -1) {
    reply_with_error ("vgchange: %s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vg_activate_all (int activate)
{
  char *empty[] = { NULL };
  return do_vg_activate (activate, empty);
}

int
do_lvrename (const char *logvol, const char *newlogvol)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "lvrename",
               logvol, newlogvol, NULL);
  if (r == -1) {
    reply_with_error ("%s -> %s: %s", logvol, newlogvol, err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vgrename (const char *volgroup, const char *newvolgroup)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "vgrename",
               volgroup, newvolgroup, NULL);
  if (r == -1) {
    reply_with_error ("%s -> %s: %s", volgroup, newvolgroup, err);
    return -1;
  }

  udev_settle ();

  return 0;
}

static char *
get_lvm_field (const char *cmd, const char *field, const char *device)
{
  char *out;
  CLEANUP_FREE char *err = NULL;
  int r = command (&out, &err,
                   str_lvm, cmd,
                   "--unbuffered", "--noheadings", "-o", field,
                   device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    free (out);
    return NULL;
  }

  trim (out);
  return out;                   /* Caller frees. */
}

char *
do_pvuuid (const char *device)
{
  return get_lvm_field ("pvs", "pv_uuid", device);
}

char *
do_vguuid (const char *vgname)
{
  return get_lvm_field ("vgs", "vg_uuid", vgname);
}

char *
do_lvuuid (const char *device)
{
  return get_lvm_field ("lvs", "lv_uuid", device);
}

static char **
get_lvm_fields (const char *cmd, const char *field, const char *device)
{
  CLEANUP_FREE char *out = NULL, *err = NULL;

  int r = command (&out, &err,
                   str_lvm, cmd,
                   "--unbuffered", "--noheadings", "-o", field,
                   device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return NULL;
  }

  char **ret = split_lines (out);

  if (ret == NULL)
    return NULL;

  size_t i;
  for (i = 0; ret[i] != NULL; ++i)
    trim (ret[i]);

  return ret;
}

char **
do_vgpvuuids (const char *vgname)
{
  return get_lvm_fields ("vgs", "pv_uuid", vgname);
}

char **
do_vglvuuids (const char *vgname)
{
  return get_lvm_fields ("vgs", "lv_uuid", vgname);
}

int
do_vgscan (void)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "vgscan", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  return 0;
}

/* Convert a non-canonical LV path like /dev/mapper/vg-lv or /dev/dm-0
 * to a canonical one.
 *
 * This is harder than it should be.  A LV device like /dev/VG/LV is
 * really a symlink to a device-mapper device like /dev/dm-0.  However
 * at the device-mapper (kernel) level, nothing is really known about
 * LVM (a userspace concept).  Therefore we use a convoluted method to
 * determine this, by listing out known LVs and checking whether the
 * rdev (major/minor) of the device we are passed matches any of them.
 *
 * Note use of 'stat' instead of 'lstat' so that symlinks are fully
 * resolved.
 *
 * Returns:
 *   1  =  conversion was successful, path is an LV
 *         '*ret' is set to the updated path if 'ret' is non-NULL.
 *   0  =  path is not an LV
 *  -1  =  error, reply_with_* has been called
 *
 */
int
lv_canonical (const char *device, char **ret)
{
  struct stat stat1, stat2;

  int r = stat (device, &stat1);
  if (r == -1) {
    reply_with_perror ("stat: %s", device);
    return -1;
  }

  CLEANUP_FREE_STRING_LIST char **lvs = do_lvs ();
  if (lvs == NULL)
    return -1;

  size_t i;
  for (i = 0; lvs[i] != NULL; ++i) {
    r = stat (lvs[i], &stat2);
    if (r == -1) {
      reply_with_perror ("stat: %s", lvs[i]);
      return -1;
    }
    if (stat1.st_rdev == stat2.st_rdev) { /* found it */
      if (ret) {
        *ret = strdup (lvs[i]);
        if (*ret == NULL) {
          reply_with_perror ("strdup");
          return -1;
        }
      }
      return 1;
    }
  }

  /* not found */
  return 0;
}

/* Test if a device is a logical volume (RHBZ#619793). */
int
do_is_lv (const char *device)
{
  return lv_canonical (device, NULL);
}

/* Return canonical name of LV to caller (RHBZ#638899). */
char *
do_lvm_canonical_lv_name (const char *device)
{
  char *canonical;
  int r = lv_canonical (device, &canonical);
  if (r == -1)
    return NULL;

  if (r == 0) {
    reply_with_error ("%s: not a logical volume", device);
    return NULL;
  }

  return canonical;             /* caller frees */
}

/* List everything in /dev/mapper which *isn't* an LV (RHBZ#688062). */
char **
do_list_dm_devices (void)
{
  DECLARE_STRINGSBUF (ret);
  struct dirent *d;
  DIR *dir;
  int r;

  dir = opendir ("/dev/mapper");
  if (!dir) {
    reply_with_perror ("opendir: /dev/mapper");
    return NULL;
  }

  while (1) {
    errno = 0;
    d = readdir (dir);
    if (d == NULL) break;

    /* Ignore . and .. */
    if (STREQ (d->d_name, ".") || STREQ (d->d_name, ".."))
      continue;

    /* Ignore /dev/mapper/control which is used internally by dm. */
    if (STREQ (d->d_name, "control"))
      continue;

    size_t len = strlen (d->d_name);
    char devname[len+64];

    snprintf (devname, len+64, "/dev/mapper/%s", d->d_name);

    /* Ignore dm devices which are LVs. */
    r = lv_canonical (devname, NULL);
    if (r == -1) {
      free_stringslen (ret.argv, ret.size);
      closedir (dir);
      return NULL;
    }
    if (r)
      continue;

    /* Not an LV, so add it. */
    if (add_string (&ret, devname) == -1) {
      closedir (dir);
      return NULL;
    }
  }

  /* Did readdir fail? */
  if (errno != 0) {
    reply_with_perror ("readdir: /dev/mapper");
    free_stringslen (ret.argv, ret.size);
    closedir (dir);
    return NULL;
  }

  /* Close the directory handle. */
  if (closedir (dir) == -1) {
    reply_with_perror ("closedir: /dev/mapper");
    free_stringslen (ret.argv, ret.size);
    return NULL;
  }

  /* Sort the output (may be empty). */
  if (ret.size > 0)
    sort_strings (ret.argv, ret.size);

  /* NULL-terminate the list. */
  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

char *
do_vgmeta (const char *vg, size_t *size_r)
{
  CLEANUP_FREE char *err = NULL;
  int fd, r;
  char tmp[] = "/tmp/vgmetaXXXXXX";
  size_t alloc, size, max;
  ssize_t rs;
  char *buf, *buf2;

  /* Make a temporary file. */
  fd = mkstemp (tmp);
  if (fd == -1) {
    reply_with_perror ("mkstemp");
    return NULL;
  }

  close (fd);

  r = command (NULL, &err, str_lvm, "vgcfgbackup", "-f", tmp, vg, NULL);
  if (r == -1) {
    reply_with_error ("vgcfgbackup: %s", err);
    return NULL;
  }

  /* Now read back the temporary file. */
  fd = open (tmp, O_RDONLY|O_CLOEXEC);
  if (fd == -1) {
    reply_with_error ("%s", tmp);
    return NULL;
  }

  /* Read up to GUESTFS_MESSAGE_MAX - <overhead> bytes.  If it's
   * larger than that, we need to return an error instead (for
   * correctness).
   */
  max = GUESTFS_MESSAGE_MAX - 1000;
  buf = NULL;
  size = alloc = 0;

  for (;;) {
    if (size >= alloc) {
      alloc += 8192;
      if (alloc > max) {
        reply_with_error ("metadata is too large for message buffer");
        free (buf);
        close (fd);
        return NULL;
      }
      buf2 = realloc (buf, alloc);
      if (buf2 == NULL) {
        reply_with_perror ("realloc");
        free (buf);
        close (fd);
        return NULL;
      }
      buf = buf2;
    }

    rs = read (fd, buf + size, alloc - size);
    if (rs == -1) {
      reply_with_perror ("read: %s", tmp);
      free (buf);
      close (fd);
      return NULL;
    }
    if (rs == 0)
      break;
    if (rs > 0)
      size += rs;
  }

  if (close (fd) == -1) {
    reply_with_perror ("close: %s", tmp);
    free (buf);
    return NULL;
  }

  unlink (tmp);

  *size_r = size;

  return buf;			/* caller will free */
}

int
do_pvchange_uuid (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "pvchange", "-u", device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_pvchange_uuid_all (void)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "pvchange", "-u", "-a", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vgchange_uuid (const char *vg)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "vgchange", "-u", vg, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", vg, err);
    return -1;
  }

  udev_settle ();

  return 0;
}

int
do_vgchange_uuid_all (void)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  r = command (NULL, &err,
               str_lvm, "vgchange", "-u", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  udev_settle ();

  return 0;
}
