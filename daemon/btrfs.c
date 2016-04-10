/* libguestfs - the guestfsd daemon
 * Copyright (C) 2011-2012 Red Hat Inc.
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
#include <pcre.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "daemon.h"
#include "actions.h"
#include "optgroups.h"
#include "xstrtol.h"
#include "c-ctype.h"
#include "ignore-value.h"

GUESTFSD_EXT_CMD(str_btrfs, btrfs);
GUESTFSD_EXT_CMD(str_btrfstune, btrfstune);
GUESTFSD_EXT_CMD(str_btrfsck, btrfsck);
GUESTFSD_EXT_CMD(str_mkfs_btrfs, mkfs.btrfs);
GUESTFSD_EXT_CMD(str_umount, umount);
GUESTFSD_EXT_CMD(str_btrfsimage, btrfs-image);

COMPILE_REGEXP (re_btrfs_subvolume_list,
                "ID\\s+(\\d+).*\\s"
                "top level\\s+(\\d+).*\\s"
                "path\\s(.*)",
                0)
COMPILE_REGEXP (re_btrfs_balance_status, "Balance on '.*' is (.*)", 0)

int
optgroup_btrfs_available (void)
{
  return test_mode ||
    (prog_exists (str_btrfs) && filesystem_available ("btrfs") > 0);
}

char *
btrfs_get_label (const char *device)
{
  int r;
  CLEANUP_FREE char *err = NULL;
  char *out = NULL;
  size_t len;

  r = command (&out, &err, str_btrfs, "filesystem", "label",
               device, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    return NULL;
  }

  /* Trim trailing \n if present. */
  len = strlen (out);
  if (len > 0 && out[len-1] == '\n')
    out[len-1] = '\0';

  return out;
}

int
btrfs_set_label (const char *device, const char *label)
{
  int r;
  CLEANUP_FREE char *err = NULL;

  r = command (NULL, &err, str_btrfs, "filesystem", "label",
               device, label, NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

  return 0;
}

/* Takes optional arguments, consult optargs_bitmask. */
int
do_btrfs_filesystem_resize (const char *filesystem, int64_t size)
{
  const size_t MAX_ARGS = 64;
  CLEANUP_FREE char *buf = NULL, *err = NULL;
  int r;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  char size_str[32];

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "filesystem");
  ADD_ARG (argv, i, "resize");

  if (optargs_bitmask & GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK) {
    if (size <= 0) {
      reply_with_error ("size is zero or negative");
      return -1;
    }

    snprintf (size_str, sizeof size_str, "%" PRIi64, size);
    ADD_ARG (argv, i, size_str);
  }
  else
    ADD_ARG (argv, i, "max");

  buf = sysroot_path (filesystem);
  if (!buf) {
    reply_with_error ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);

  if (r == -1) {
    reply_with_error ("%s: %s", filesystem, err);
    return -1;
  }

  return 0;
}

/* Takes optional arguments, consult optargs_bitmask. */
int
do_mkfs_btrfs (char *const *devices,
               int64_t allocstart, int64_t bytecount, const char *datatype,
               int leafsize, const char *label, const char *metadata,
               int nodesize, int sectorsize)
{
  size_t nr_devices = count_strings (devices);
  size_t MAX_ARGS = nr_devices + 64;
  const char *argv[MAX_ARGS];
  size_t i = 0, j;
  int r;
  CLEANUP_FREE char *err = NULL;
  char allocstart_s[64];
  char bytecount_s[64];
  char leafsize_s[64];
  char nodesize_s[64];
  char sectorsize_s[64];

  if (nr_devices == 0) {
    reply_with_error ("list of devices must be non-empty");
    return -1;
  }

  ADD_ARG (argv, i, str_mkfs_btrfs);

  /* Optional arguments. */
  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK) {
    if (allocstart < 0) {
      reply_with_error ("allocstart must be >= 0");
      return -1;
    }
    snprintf (allocstart_s, sizeof allocstart_s, "%" PRIi64, allocstart);
    ADD_ARG (argv, i, "--alloc-start");
    ADD_ARG (argv, i, allocstart_s);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK) {
    if (bytecount <= 0) { /* actually the minimum is 256MB */
      reply_with_error ("bytecount must be > 0");
      return -1;
    }
    snprintf (bytecount_s, sizeof bytecount_s, "%" PRIi64, bytecount);
    ADD_ARG (argv, i, "--byte-count");
    ADD_ARG (argv, i, bytecount_s);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK) {
    if (STRNEQ (datatype, "raid0") && STRNEQ (datatype, "raid1") &&
        STRNEQ (datatype, "raid10") && STRNEQ (datatype, "single")) {
      reply_with_error ("datatype not one of the allowed values");
      return -1;
    }
    ADD_ARG (argv, i, "--data");
    ADD_ARG (argv, i, datatype);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK) {
    if (!is_power_of_2 (leafsize) || leafsize <= 0) {
      reply_with_error ("leafsize must be > 0 and a power of two");
      return -1;
    }
    snprintf (leafsize_s, sizeof leafsize_s, "%d", leafsize);
    ADD_ARG (argv, i, "--leafsize");
    ADD_ARG (argv, i, leafsize_s);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK) {
    ADD_ARG (argv, i, "--label");
    ADD_ARG (argv, i, label);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK) {
    if (STRNEQ (metadata, "raid0") && STRNEQ (metadata, "raid1") &&
        STRNEQ (metadata, "raid10") && STRNEQ (metadata, "single")) {
      reply_with_error ("metadata not one of the allowed values");
      return -1;
    }
    ADD_ARG (argv, i, "--metadata");
    ADD_ARG (argv, i, metadata);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK) {
    if (!is_power_of_2 (nodesize) || nodesize <= 0) {
      reply_with_error ("nodesize must be > 0 and a power of two");
      return -1;
    }
    snprintf (nodesize_s, sizeof nodesize_s, "%d", nodesize);
    ADD_ARG (argv, i, "--nodesize");
    ADD_ARG (argv, i, nodesize_s);
  }

  if (optargs_bitmask & GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK) {
    if (!is_power_of_2 (sectorsize) || sectorsize <= 0) {
      reply_with_error ("sectorsize must be > 0 and a power of two");
      return -1;
    }
    snprintf (sectorsize_s, sizeof sectorsize_s, "%d", sectorsize);
    ADD_ARG (argv, i, "--sectorsize");
    ADD_ARG (argv, i, sectorsize_s);
  }

  for (j = 0; j < nr_devices; ++j)
    ADD_ARG (argv, i, devices[j]);

  ADD_ARG (argv, i, NULL);

  for (j = 0; j < nr_devices; ++j)
    wipe_device_before_mkfs (devices[j]);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", devices[0], err);
    return -1;
  }

  return 0;
}

int
do_btrfs_subvolume_snapshot (const char *source, const char *dest, int ro,
                             const char *qgroupid)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *source_buf = NULL, *dest_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  source_buf = sysroot_path (source);
  if (source_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }
  dest_buf = sysroot_path (dest);
  if (dest_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "snapshot");

  /* Optional arguments. */
  if ((optargs_bitmask & GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO_BITMASK) &&
      ro)
    ADD_ARG (argv, i, "-r");

  if (optargs_bitmask & GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID_BITMASK) {
    ADD_ARG (argv, i, "-i");
    ADD_ARG (argv, i, qgroupid);
  }

  ADD_ARG (argv, i, source_buf);
  ADD_ARG (argv, i, dest_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s: %s", source, dest, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_subvolume_delete (const char *subvolume)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *subvolume_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  subvolume_buf = sysroot_path (subvolume);
  if (subvolume_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "delete");
  ADD_ARG (argv, i, subvolume_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", subvolume, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_subvolume_create (const char *dest, const char *qgroupid)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *dest_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  dest_buf = sysroot_path (dest);
  if (dest_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "create");

  /* Optional arguments. */
  if (optargs_bitmask & GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID_BITMASK) {
    ADD_ARG (argv, i, "-i");
    ADD_ARG (argv, i, qgroupid);
  }


  ADD_ARG (argv, i, dest_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", dest, err);
    return -1;
  }

  return 0;
}

static char *
mount (const mountable_t *fs)
{
  char *fs_buf;

  if (fs->type == MOUNTABLE_PATH) {
    fs_buf = sysroot_path (fs->device);
    if (fs_buf == NULL)
      reply_with_perror ("malloc");
  } else {
    fs_buf = strdup ("/tmp/btrfs.XXXXXX");
    if (fs_buf == NULL) {
      reply_with_perror ("strdup");
      return NULL;
    }

    if (mkdtemp (fs_buf) == NULL) {
      reply_with_perror ("mkdtemp");
      free (fs_buf);
      return NULL;
    }

    if (mount_vfs_nochroot ("", NULL, fs, fs_buf, "<internal>") == -1) {
      if (rmdir (fs_buf) == -1 && errno != ENOENT)
        perror ("rmdir");
      free (fs_buf);
      return NULL;
    }
  }

  return fs_buf;
}

static int
umount (char *fs_buf, const mountable_t *fs)
{
  if (fs->type != MOUNTABLE_PATH) {
    CLEANUP_FREE char *err = NULL;

    if (command (NULL, &err, str_umount, fs_buf, NULL) == -1) {
      reply_with_error ("umount: %s", err);
      return -1;
    }

    if (rmdir (fs_buf) == -1 && errno != ENOENT) {
      reply_with_perror ("rmdir");
      return -1;
    }
  }
  free (fs_buf);
  return 0;
}

guestfs_int_btrfssubvolume_list *
do_btrfs_subvolume_list (const mountable_t *fs)
{
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  size_t i = 0;
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];

  /* Execute 'btrfs subvolume list <fs>', and split the output into lines */
  {
    char *fs_buf = mount (fs);

    if (!fs_buf)
      return NULL;

    ADD_ARG (argv, i, str_btrfs);
    ADD_ARG (argv, i, "subvolume");
    ADD_ARG (argv, i, "list");
    ADD_ARG (argv, i, fs_buf);
    ADD_ARG (argv, i, NULL);

    CLEANUP_FREE char *out = NULL, *errout = NULL;
    int r = commandv (&out, &errout, argv);

    if (umount (fs_buf, fs) != 0)
      return NULL;

    if (r == -1) {
      CLEANUP_FREE char *fs_desc = mountable_to_string (fs);
      if (fs_desc == NULL) {
        fprintf (stderr, "malloc: %m");
      }
      reply_with_error ("%s: %s", fs_desc ? fs_desc : "malloc", errout);
      return NULL;
    }

    lines = split_lines (out);
    if (!lines) return NULL;
  }

  /* Output is:
   *
   * ID 256 gen 30 top level 5 path test1
   * ID 257 gen 30 top level 5 path dir/test2
   * ID 258 gen 30 top level 5 path test3
   *
   * "ID <n>" is the subvolume ID.
   * "gen <n>" is the generation when the root was created or last
   * updated.
   * "top level <n>" is the top level subvolume ID.
   * "path <str>" is the subvolume path, relative to the top of the
   * filesystem.
   *
   * Note that the order that each of the above is fixed, but
   * different versions of btrfs may display different sets of data.
   * Specifically, older versions of btrfs do not display gen.
   */

  guestfs_int_btrfssubvolume_list *ret = NULL;

  size_t nr_subvolumes = count_strings (lines);

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_btrfssubvolume_list_len = nr_subvolumes;
  ret->guestfs_int_btrfssubvolume_list_val =
    calloc (nr_subvolumes, sizeof (struct guestfs_int_btrfssubvolume));
  if (ret->guestfs_int_btrfssubvolume_list_val == NULL) {
    reply_with_perror ("calloc");
    goto error;
  }

  for (i = 0; i < nr_subvolumes; ++i) {
    /* To avoid allocations, reuse the 'line' buffer to store the
     * path.  Thus we don't need to free 'line', since it will be
     * freed by the calling (XDR) code.
     */
    char *line = lines[i];
#define N_MATCHES 4
    int ovector[N_MATCHES * 3];

    if (pcre_exec (re_btrfs_subvolume_list, NULL, line, strlen (line), 0, 0,
                   ovector, N_MATCHES * 3) < 0)
#undef N_MATCHES
      {
      unexpected_output:
	reply_with_error ("unexpected output from 'btrfs subvolume list' command: %s", line);
	goto error;
      }

    struct guestfs_int_btrfssubvolume *this =
      &ret->guestfs_int_btrfssubvolume_list_val[i];

#if __WORDSIZE == 64
#define XSTRTOU64 xstrtoul
#else
#define XSTRTOU64 xstrtoull
#endif

    if (XSTRTOU64 (line + ovector[2], NULL, 10,
                   &this->btrfssubvolume_id, NULL) != LONGINT_OK)
      goto unexpected_output;
    if (XSTRTOU64 (line + ovector[4], NULL, 10,
                   &this->btrfssubvolume_top_level_id, NULL) != LONGINT_OK)
      goto unexpected_output;

#undef XSTRTOU64

    this->btrfssubvolume_path =
      strndup (line + ovector[6], ovector[7] - ovector[6]);
    if (this->btrfssubvolume_path == NULL)
      goto error;
  }

  return ret;

 error:
  if (ret->guestfs_int_btrfssubvolume_list_val) {
    for (i = 0; i < nr_subvolumes; ++i)
      free (ret->guestfs_int_btrfssubvolume_list_val[i].btrfssubvolume_path);
    free (ret->guestfs_int_btrfssubvolume_list_val);
  }
  free (ret);

  return NULL;
}

int
do_btrfs_subvolume_set_default (int64_t id, const char *fs)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *fs_buf = NULL;
  char buf[64];
  CLEANUP_FREE char *err = NULL;
  int r;

  snprintf (buf, sizeof buf, "%" PRIi64, id);

  fs_buf = sysroot_path (fs);
  if (fs_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "set-default");
  ADD_ARG (argv, i, buf);
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs, err);
    return -1;
  }

  return 0;
}

int64_t
do_btrfs_subvolume_get_default (const mountable_t *fs)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *out = NULL;
  int r;
  int64_t ret = -1;

  fs_buf = mount (fs);
  if (fs_buf == NULL)
    goto error;

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "get-default");
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs_buf, err);
    goto error;
  }
  if (sscanf (out, "ID %" SCNi64, &ret) != 1) {
    reply_with_error ("%s: could not parse subvolume id: %s", argv[0], out);
    ret = -1;
    goto error;
  }

 error:
  if (fs_buf && umount (fs_buf, fs) != 0)
    return -1;
  return ret;
}

int
do_btrfs_filesystem_sync (const char *fs)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  fs_buf = sysroot_path (fs);
  if (fs_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "filesystem");
  ADD_ARG (argv, i, "sync");
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_filesystem_balance (const char *fs)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  fs_buf = sysroot_path (fs);
  if (fs_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "balance");
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs, err);
    return -1;
  }

  return 0;
}

/* Test if 'btrfs device add' needs the --force option (added
 * c.2013-09) in order to work.
 */
static int
test_btrfs_device_add_needs_force (void)
{
  int r;
  CLEANUP_FREE char *out = NULL, *err = NULL;

  r = command (&out, &err, str_btrfs, "device", "add", "--help", NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", "btrfs device add --help", err);
    return -1;
  }

  return strstr (out, "--force") != NULL;
}

int
do_btrfs_device_add (char *const *devices, const char *fs)
{
  static int btrfs_device_add_needs_force = -1;
  size_t nr_devices = count_strings (devices);
  size_t MAX_ARGS = nr_devices + 8;
  const char *argv[MAX_ARGS];
  size_t i = 0, j;
  CLEANUP_FREE char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  if (nr_devices == 0)
    return 0;

  if (btrfs_device_add_needs_force == -1) {
    btrfs_device_add_needs_force = test_btrfs_device_add_needs_force ();
    if (btrfs_device_add_needs_force == -1)
      return -1;
  }

  fs_buf = sysroot_path (fs);
  if (fs_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "device");
  ADD_ARG (argv, i, "add");

  if (btrfs_device_add_needs_force)
    ADD_ARG (argv, i, "--force");

  for (j = 0; j < nr_devices; ++j)
    ADD_ARG (argv, i, devices[j]);

  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_device_delete (char *const *devices, const char *fs)
{
  size_t nr_devices = count_strings (devices);

  if (nr_devices == 0)
    return 0;

  size_t MAX_ARGS = nr_devices + 8;
  const char *argv[MAX_ARGS];
  size_t i = 0, j;
  CLEANUP_FREE char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  fs_buf = sysroot_path (fs);
  if (fs_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "device");
  ADD_ARG (argv, i, "delete");

  for (j = 0; j < nr_devices; ++j)
    ADD_ARG (argv, i, devices[j]);

  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs, err);
    return -1;
  }

  return 0;
}


/* btrfstune command add two new options
 * -U UUID      change fsid to UUID
 * -u           change fsid, use a random one
 * since v4.1
 * We could check wheter 'btrfstune' support
 * '-u' and '-U UUID' option by checking the output of
 * 'btrfstune' command.
 */
static int
test_btrfstune_uuid_opt (void)
{
  static int result = -1;
  if (result != -1)
    return result;

  CLEANUP_FREE char *err = NULL;

  int r = commandr (NULL, &err, str_btrfstune, "--help", NULL);

  if (r == -1) {
    reply_with_error ("btrfstune: %s", err);
    return -1;
  }

  /* FIXME currently btrfstune do not support '--help'.
   * If got an invalid options, it will print its usage
   * in stderr.
   * We had to check it there.
   */
  if (strstr (err, "-U") == NULL || strstr (err, "-u") == NULL)
    result = 0;
  else
    result = 1;

  return result;
}

int
do_btrfs_set_seeding (const char *device, int svalue)
{
  CLEANUP_FREE char *err = NULL;
  int r;

  const char *s_value = svalue ? "1" : "0";

  r = commandr (NULL, &err, str_btrfstune, "-S", s_value, device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
btrfs_set_uuid (const char *device, const char *uuid)
{
  CLEANUP_FREE char *err = NULL;
  int r;
  int has_uuid_opts = test_btrfstune_uuid_opt ();

  if (has_uuid_opts <= 0)
    NOT_SUPPORTED (-1, "btrfs filesystems' UUID cannot be changed");

  r = commandr (NULL, &err, str_btrfstune, "-f", "-U", uuid, device, NULL);

  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
btrfs_set_uuid_random (const char *device)
{
  CLEANUP_FREE char *err = NULL;
  int r;
  int has_uuid_opts = test_btrfstune_uuid_opt ();

  if (has_uuid_opts <= 0)
    NOT_SUPPORTED (-1, "btrfs filesystems' UUID cannot be changed");

  r = commandr (NULL, &err, str_btrfstune, "-f", "-u", device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

/* Takes optional arguments, consult optargs_bitmask. */
int
do_btrfs_fsck (const char *device, int64_t superblock, int repair)
{
  CLEANUP_FREE char *err = NULL;
  int r;
  size_t i = 0;
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  char super_s[64];

  ADD_ARG (argv, i, str_btrfsck);

  /* Optional arguments. */
  if (optargs_bitmask & GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK) {
    if (superblock < 0) {
      reply_with_error ("super block offset must be >= 0");
      return -1;
    }
    snprintf (super_s, sizeof super_s, "%" PRIi64, superblock);
    ADD_ARG (argv, i, "--super");
    ADD_ARG (argv, i, super_s);
  }

  if (!(optargs_bitmask & GUESTFS_BTRFS_FSCK_REPAIR_BITMASK))
    repair = 0;

  if (repair)
    ADD_ARG (argv, i, "--repair");

  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

/* analyze_line: analyze one line contains key:value pair.
 * returns the next position following \n.
 */
static char *
analyze_line (char *line, char **key, char **value, char delimiter)
{
  char *p = line;
  char *next = NULL;
  char *del_pos = NULL;

  if (!line || *line == '\0') {
    *key = NULL;
    *value = NULL;
    return NULL;
  }

  next = strchr (p, '\n');
  if (next) {
    *next = '\0';
    ++next;
  }

  /* leading spaces and tabs */
  while (*p && c_isspace (*p))
    ++p;

  assert (key);
  if (*p == delimiter)
    *key = NULL;
  else
    *key = p;

  del_pos = strchr (p, delimiter);
  if (del_pos) {
    *del_pos = '\0';

    /* leading spaces and tabs */
    do {
      ++del_pos;
    } while (*del_pos && c_isspace (*del_pos));
    assert (value);
    *value = del_pos;
  } else
    *value = NULL;

  return next;
}

char **
do_btrfs_subvolume_show (const char *subvolume)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *subvolume_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *out = NULL;
  char *p, *key = NULL, *value = NULL;
  DECLARE_STRINGSBUF (ret);
  int r;

  subvolume_buf = sysroot_path (subvolume);
  if (subvolume_buf == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "subvolume");
  ADD_ARG (argv, i, "show");
  ADD_ARG (argv, i, subvolume_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", subvolume, err);
    return NULL;
  }

  /* If the path is the btrfs root, `btrfs subvolume show' reports:
   *   <path> is btrfs root [in btrfs-progs < 4.4]
   *   <path> is toplevel subvolume
   */
  if (out &&
      (strstr (out, "is btrfs root") != NULL ||
       strstr (out, "is toplevel subvolume") != NULL)) {
    reply_with_error ("%s is btrfs root", subvolume);
    return NULL;
  }

  /* If the path is a normal directory, `btrfs subvolume show' reports:
   *   ERROR: <path> is not a subvolume
   */
  if (err && strstr (err, "is not a subvolume")) {
    reply_with_error ("%s is not a subvolume", subvolume);
    return NULL;
  }

  /* Output is:
   *
   * /
   *         Name:                   root
   *         uuid:                   c875169e-cf4e-a04d-9959-b667dec36234
   *         Parent uuid:            -
   *         Creation time:          2014-11-13 10:13:08
   *         Object ID:              256
   *         Generation (Gen):       6579
   *         Gen at creation:        5
   *         Parent:                 5
   *         Top Level:              5
   *         Flags:                  -
   *         Snapshot(s):
   *                                 snapshots/test1
   *                                 snapshots/test2
   *                                 snapshots/test3
   *
   */
  p = analyze_line (out, &key, &value, ':');
  if (!p) {
    reply_with_error ("truncated output: %s", out);
    return NULL;
  }

  /* The first line is the path of the subvolume. */
  if (key && !value) {
    if (add_string (&ret, "path") == -1)
      return NULL;
    if (add_string (&ret, key) == -1)
      return NULL;
  } else {
    if (add_string (&ret, key) == -1)
      return NULL;
    if (add_string (&ret, value) == -1)
      return NULL;
  }

  /* Read the lines and split into "key: value". */
  p = analyze_line (p, &key, &value, ':');
  while (key) {
    /* snapshot is special, see the output above */
    if (STREQLEN (key, "Snapshot(s)", sizeof ("Snapshot(s)") - 1)) {
      char *ss = NULL;
      int ss_len = 0;

      if (add_string (&ret, key) == -1)
        return NULL;

      p = analyze_line (p, &key, &value, ':');

      while (key && !value) {
	ss = realloc (ss, ss_len + strlen (key) + 1);
	if (!ss)
	  return NULL;

	if (ss_len != 0)
	  ss[ss_len++] = ',';

	memcpy (ss + ss_len, key, strlen (key));
	ss_len += strlen (key);
	ss[ss_len] = '\0';

	p = analyze_line (p, &key, &value, ':');
      }

      if (ss) {
        if (add_string_nodup (&ret, ss) == -1) {
          free (ss);
          return NULL;
        }
      } else {
        if (add_string (&ret, "") == -1)
          return NULL;
      }
    } else {
      if (add_string (&ret, key ? key : "") == -1)
        return NULL;
      if (value && !STREQ (value, "-")) {
        if (add_string (&ret, value) == -1)
          return NULL;
      } else {
        if (add_string (&ret, "") == -1)
          return NULL;
      }

      p = analyze_line (p, &key, &value, ':');
    }
  }

  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

int
do_btrfs_quota_enable (const mountable_t *fs, int enable)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r = -1;

  fs_buf = mount (fs);
  if (fs_buf == NULL)
    goto error;

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "quota");
  if (enable)
    ADD_ARG (argv, i, "enable");
  else
    ADD_ARG (argv, i, "disable");
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs_buf, err);
    goto error;
  }

 error:
  if (fs_buf && umount (fs_buf, fs) != 0)
    return -1;
  return r;
}

int
do_btrfs_quota_rescan (const mountable_t *fs)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  char *fs_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r = -1;

  fs_buf = mount (fs);
  if (fs_buf == NULL)
    goto error;

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "quota");
  ADD_ARG (argv, i, "rescan");
  ADD_ARG (argv, i, fs_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", fs_buf, err);
    goto error;
  }

 error:
  if (fs_buf && umount (fs_buf, fs) != 0)
    return -1;
  return r;
}

int
do_btrfs_qgroup_limit (const char *subvolume, int64_t size)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *subvolume_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  char size_str[32];
  int r;

  subvolume_buf = sysroot_path (subvolume);
  if (subvolume_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "limit");
  snprintf (size_str, sizeof size_str, "%" PRIi64, size);
  ADD_ARG (argv, i, size_str);
  ADD_ARG (argv, i, subvolume_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", subvolume, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_qgroup_create (const char *qgroupid, const char *subvolume)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *subvolume_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  subvolume_buf = sysroot_path (subvolume);
  if (subvolume_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "create");
  ADD_ARG (argv, i, qgroupid);
  ADD_ARG (argv, i, subvolume_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", subvolume, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_qgroup_destroy (const char *qgroupid, const char *subvolume)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *subvolume_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  subvolume_buf = sysroot_path (subvolume);
  if (subvolume_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "destroy");
  ADD_ARG (argv, i, qgroupid);
  ADD_ARG (argv, i, subvolume_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", subvolume, err);
    return -1;
  }

  return 0;
}

/* btrfs qgroup show command change default output to
 * binary prefix since v3.18.2, such as KiB;
 * also introduced '--raw' to keep traditional behaviour.
 * We could check wheter 'btrfs qgroup show' support '--raw'
 * option by checking the output of
 * 'btrfs qgroup show' support --help' command.
 */
static int
test_btrfs_qgroup_show_raw_opt (void)
{
  static int result = -1;
  if (result != -1)
    return result;

  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *out = NULL;

  int r = commandr (&out, &err, str_btrfs, "qgroup", "show", "--help", NULL);

  if (r == -1) {
    reply_with_error ("btrfs qgroup show --help: %s", err);
    return -1;
  }

  if (strstr (out, "--raw") == NULL)
    result = 0;
  else
    result = 1;

  return result;
}

guestfs_int_btrfsqgroup_list *
do_btrfs_qgroup_show (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  int has_raw_opt = test_btrfs_qgroup_show_raw_opt ();
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *out = NULL;
  int r;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "show");
  if (has_raw_opt > 0)
    ADD_ARG (argv, i, "--raw");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return NULL;
  }

  lines = split_lines (out);
  if (!lines)
    return NULL;

  /* Output of `btrfs qgroup show' is like:
   *
   *  qgroupid         rfer         excl
   *  --------         ----         ----
   *  0/5        9249849344   9249849344
   *
   */
  size_t nr_qgroups = count_strings (lines) - 2;
  guestfs_int_btrfsqgroup_list *ret = NULL;
  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_btrfsqgroup_list_len = nr_qgroups;
  ret->guestfs_int_btrfsqgroup_list_val =
    calloc (nr_qgroups, sizeof (struct guestfs_int_btrfsqgroup));
  if (ret->guestfs_int_btrfsqgroup_list_val == NULL) {
    reply_with_perror ("calloc");
    goto error;
  }

  for (i = 0; i < nr_qgroups; ++i) {
    char *line = lines[i + 2];
    struct guestfs_int_btrfsqgroup *this =
      &ret->guestfs_int_btrfsqgroup_list_val[i];

    if (sscanf (line, "%m[0-9/] %" SCNu64 " %" SCNu64,
                &this->btrfsqgroup_id, &this->btrfsqgroup_rfer,
                &this->btrfsqgroup_excl) != 3) {
      reply_with_error ("cannot parse output of qgroup show command: %s", line);
      goto error;
    }
  }

  return ret;

 error:
  if (ret->guestfs_int_btrfsqgroup_list_val) {
    for (i = 0; i < nr_qgroups; ++i)
      free (ret->guestfs_int_btrfsqgroup_list_val[i].btrfsqgroup_id);
    free (ret->guestfs_int_btrfsqgroup_list_val);
  }
  free (ret);

  return NULL;
}

int
do_btrfs_qgroup_assign (const char *src, const char *dst, const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "assign");
  ADD_ARG (argv, i, src);
  ADD_ARG (argv, i, dst);
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_qgroup_remove (const char *src, const char *dst, const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "qgroup");
  ADD_ARG (argv, i, "remove");
  ADD_ARG (argv, i, src);
  ADD_ARG (argv, i, dst);
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_scrub_start (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "scrub");
  ADD_ARG (argv, i, "start");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_scrub_cancel (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "scrub");
  ADD_ARG (argv, i, "cancel");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_scrub_resume (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "scrub");
  ADD_ARG (argv, i, "resume");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_balance_pause (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "balance");
  ADD_ARG (argv, i, "pause");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_balance_cancel (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "balance");
  ADD_ARG (argv, i, "cancel");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_balance_resume (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "balance");
  ADD_ARG (argv, i, "resume");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

/* Takes optional arguments, consult optargs_bitmask. */
int
do_btrfs_filesystem_defragment (const char *path, int flush, const char *compress)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "filesystem");
  ADD_ARG (argv, i, "defragment");
  ADD_ARG (argv, i, "-r");

  /* Optional arguments. */
  if ((optargs_bitmask & GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK) && flush)
    ADD_ARG (argv, i, "-f");
  if (optargs_bitmask & GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK) {
    if (STREQ (compress, "zlib"))
      ADD_ARG (argv, i, "-czlib");
    else if (STREQ (compress, "lzo"))
      ADD_ARG (argv, i, "-clzo");
    else {
      reply_with_error ("unknown compress method: %s", compress);
      return -1;
    }
  }

  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_rescue_chunk_recover (const char *device)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  int r;

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "rescue");
  ADD_ARG (argv, i, "chunk-recover");
  ADD_ARG (argv, i, "-y");
  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_rescue_super_recover (const char *device)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  int r;

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "rescue");
  ADD_ARG (argv, i, "super-recover");
  ADD_ARG (argv, i, "-y");
  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

guestfs_int_btrfsbalance *
do_btrfs_balance_status (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *out = NULL;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  int r;
  guestfs_int_btrfsbalance *ret;
  size_t nlines;
#define N_MATCH 2
  int ovector[N_MATCH * 3];

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "balance");
  ADD_ARG (argv, i, "status");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return NULL;
  }

  lines = split_lines (out);
  if (!lines)
    return NULL;

  nlines = count_strings (lines);

  ret = calloc (1, sizeof *ret);
  if (ret == NULL) {
    reply_with_perror ("calloc");
    goto error;
  }

  /* Output of `btrfs balance status' is like:
   *
   * running:
   *
   *   Balance on '/' is running
   *   3 out of about 8 chunks balanced (3 considered), 62% left
   *
   * paused:
   *
   *   Balance on '/' is paused
   *   3 out of about 8 chunks balanced (3 considered), 62% left
   *
   * no balance running:
   *
   *   No Balance found on '/'
   *
   */
  if (nlines < 1) {
    reply_with_perror ("No balance status output");
    return NULL;
  }

  if (strstr (lines[0], "No balance found on")) {
    ret->btrfsbalance_status = strdup ("none");
    if (ret->btrfsbalance_status == NULL) {
      reply_with_perror ("strdup");
      return NULL;
    }
    return ret;
  }

  if (pcre_exec (re_btrfs_balance_status,
                 NULL, lines[0], strlen (lines[0]), 0, 0,
                 ovector, N_MATCH * 3) < 0) {
    reply_with_error ("unexpected output from 'btrfs balance status' command: %s", lines[0]);
    goto error;
  }
#undef N_MATCH

  if (STREQ (lines[0] + ovector[2], "running"))
    ret->btrfsbalance_status = strdup ("running");
  else if (STREQ (lines[0] + ovector[2], "paused"))
    ret->btrfsbalance_status = strdup ("paused");
  else {
    reply_with_error ("unexpected output from 'btrfs balance status' command: %s", lines[0]);
    goto error;
  }

  if (nlines < 2) {
    reply_with_error ("truncated output from 'btrfs balance status' command");
    goto error;
  }

  if (sscanf (lines[1], "%" SCNu64 " out of about %" SCNu64
              " chunks balanced (%" SCNu64 " considered), %" SCNu64 "%% left",
              &ret->btrfsbalance_balanced, &ret->btrfsbalance_total,
              &ret->btrfsbalance_considered, &ret->btrfsbalance_left) != 4) {
    reply_with_perror ("sscanf");
    goto error;
  }

  return ret;

 error:
  free (ret->btrfsbalance_status);
  free (ret);

  return NULL;
}

guestfs_int_btrfsscrub *
do_btrfs_scrub_status (const char *path)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *path_buf = NULL;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE_STRING_LIST char **lines = NULL;
  CLEANUP_FREE char *out = NULL;
  int r;
  guestfs_int_btrfsscrub *ret;

  path_buf = sysroot_path (path);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "scrub");
  ADD_ARG (argv, i, "status");
  ADD_ARG (argv, i, "-R");
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, NULL);

  r = commandv (&out, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", path, err);
    return NULL;
  }

  if (verbose)
    fprintf (stderr, "output from 'btrfs scrub status -R %s' is:\n%s", path, out);

  lines = split_lines (out);
  if (!lines)
    return NULL;

  if (count_strings (lines) < 2) {
    reply_with_error ("truncated output from 'btrfs scrub status -R' command");
    return NULL;
  }

  ret = calloc (1, sizeof *ret);
  if (ret == NULL) {
    reply_with_perror ("calloc");
    return NULL;
  }

  /* Output of `btrfs scrub -R status' is like:
   *
   *   scrub status for 346121d1-1847-40f8-9b7b-2bf3d539c68f
   *           scrub started at Mon Feb  2 17:39:38 2015, running for 93 seconds
   *           data_extents_scrubbed: 136670
   *           tree_extents_scrubbed: 30023
   *           data_bytes_scrubbed: 4474441728
   *           tree_bytes_scrubbed: 491896832
   *           read_errors: 0
   *           csum_errors: 0
   *           verify_errors: 0
   *           no_csum: 17760
   *           csum_discards: 197622
   *           super_errors: 0
   *           malloc_errors: 0
   *           uncorrectable_errors: 0
   *           unverified_errors: 0
   *           corrected_errors: 0
   *           last_physical: 10301341696
   *
   * or:
   *
   *   scrub status for 346121d1-1847-40f8-9b7b-2bf3d539c68f
   *           no stats available
   */
  for (i = 1; lines[i] != NULL; ++i) {
    if ((i == 1) && STREQ (lines[i], "\tno stats available"))
      return ret;
    else if (STRPREFIX (lines[i], "\tscrub started at"))
      continue;
    else if (sscanf (lines[i], "\tdata_extents_scrubbed: %" SCNu64,
		     &ret->btrfsscrub_data_extents_scrubbed) == 1)
      continue;
    else if (sscanf (lines[i], "\ttree_extents_scrubbed: %" SCNu64,
		     &ret->btrfsscrub_tree_extents_scrubbed) == 1)
      continue;
    else if (sscanf (lines[i], "\tdata_bytes_scrubbed: %" SCNu64,
		     &ret->btrfsscrub_data_bytes_scrubbed) == 1)
      continue;
    else if (sscanf (lines[i], "\ttree_bytes_scrubbed: %" SCNu64,
		     &ret->btrfsscrub_tree_bytes_scrubbed) == 1)
      continue;
    else if (sscanf (lines[i], "\tread_errors: %" SCNu64,
		     &ret->btrfsscrub_read_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tcsum_errors: %" SCNu64,
		     &ret->btrfsscrub_csum_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tverify_errors: %" SCNu64,
		     &ret->btrfsscrub_verify_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tno_csum: %" SCNu64,
		     &ret->btrfsscrub_no_csum) == 1)
      continue;
    else if (sscanf (lines[i], "\tcsum_discards: %" SCNu64,
		     &ret->btrfsscrub_csum_discards) == 1)
      continue;
    else if (sscanf (lines[i], "\tsuper_errors: %" SCNu64,
		     &ret->btrfsscrub_super_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tmalloc_errors: %" SCNu64,
		     &ret->btrfsscrub_malloc_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tuncorrectable_errors: %" SCNu64,
		     &ret->btrfsscrub_uncorrectable_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tunverified_errors: %" SCNu64,
		     &ret->btrfsscrub_unverified_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tcorrected_errors: %" SCNu64,
		     &ret->btrfsscrub_corrected_errors) == 1)
      continue;
    else if (sscanf (lines[i], "\tlast_physical: %" SCNu64,
		     &ret->btrfsscrub_last_physical) == 1)
      continue;
    else
      goto error;
  }

  if (i < 17) {
    reply_with_error ("truncated output from 'btrfs scrub status -R' command");
    free (ret);
    return NULL;
  }

  return ret;

 error:
  reply_with_error ("%s: could not parse btrfs scrub status.", lines[i]);
  free (ret);
  return NULL;
}

int
do_btrfstune_seeding (const char *device, int svalue)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  int r;
  const char *s_value = svalue ? "1" : "0";

  ADD_ARG (argv, i, str_btrfstune);
  ADD_ARG (argv, i, "-S");
  ADD_ARG (argv, i, s_value);
  if (svalue == 0)
    ADD_ARG (argv, i, "-f");
  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_btrfstune_enable_extended_inode_refs (const char *device)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  int r;

  ADD_ARG (argv, i, str_btrfstune);
  ADD_ARG (argv, i, "-r");
  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_btrfstune_enable_skinny_metadata_extent_refs (const char *device)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  int r;

  ADD_ARG (argv, i, str_btrfstune);
  ADD_ARG (argv, i, "-x");
  ADD_ARG (argv, i, device);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_image (char *const *sources, const char *image,
		int compresslevel)
{
  size_t nr_sources =  count_strings (sources);
  const size_t MAX_ARGS = 64 + nr_sources;
  const char *argv[MAX_ARGS];
  size_t i = 0, j;
  CLEANUP_FREE char *err = NULL;
  char compresslevel_s[64];
  int r;

  if (nr_sources == 0) {
    reply_with_error ("list of sources must be non-empty");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfsimage);

  if ((optargs_bitmask & GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK)
      && compresslevel >= 0) {
    snprintf (compresslevel_s, sizeof compresslevel_s, "%d", compresslevel);
    ADD_ARG (argv, i, "-c");
    ADD_ARG (argv, i, compresslevel_s);
  }

  for (j = 0; j < nr_sources; ++j)
    ADD_ARG (argv, i, sources[j]);

  ADD_ARG (argv, i, image);
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s %s: %s", sources[0], image, err);
    return -1;
  }

  return 0;
}

int
do_btrfs_replace (const char *srcdev, const char *targetdev,
		  const char* mntpoint)
{
  const size_t MAX_ARGS = 64;
  const char *argv[MAX_ARGS];
  size_t i = 0;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *path_buf = NULL;
  int r;

  path_buf = sysroot_path (mntpoint);
  if (path_buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  ADD_ARG (argv, i, str_btrfs);
  ADD_ARG (argv, i, "replace");
  ADD_ARG (argv, i, "start");
  ADD_ARG (argv, i, srcdev);
  ADD_ARG (argv, i, targetdev);
  ADD_ARG (argv, i, path_buf);
  ADD_ARG (argv, i, "-B");
  ADD_ARG (argv, i, "-f");
  ADD_ARG (argv, i, NULL);

  r = commandv (NULL, &err, argv);
  if (r == -1) {
    reply_with_error ("%s: %s", mntpoint, err);
    return -1;
  }

  return 0;
}

/* btrfs command add a new command
 * inspect-internal min-dev-size <path>
 * since v4.2
 * We could check whether 'btrfs' supports
 * 'min-dev-size' command by checking the output of
 * 'btrfs --help' command.
 */
static int
test_btrfs_min_dev_size (void)
{
  CLEANUP_FREE char *err = NULL, *out = NULL;
  static int result = -1;
  const char *cmd_pattern = "btrfs inspect-internal min-dev-size";
  int r;

  if (result != -1)
    return result;

  r = commandr (&out, &err, str_btrfs, "--help", NULL);

  if (r == -1) {
    reply_with_error ("btrfs: %s", err);
    return -1;
  }

  if (strstr (out, cmd_pattern) == NULL)
    result = 0;
  else
    result = 1;

  return result;
}

int64_t
btrfs_minimum_size (const char *path)
{
  CLEANUP_FREE char *buf = NULL, *err = NULL, *out = NULL;
  int64_t ret = 0;
  int r;
  int min_size_supported = test_btrfs_min_dev_size ();

  if (min_size_supported == -1)
    return -1;
  else if (min_size_supported == 0)
    NOT_SUPPORTED (-1, "'btrfs inspect-internal min-dev-size' "
                       "needs btrfs-progs >= 4.2");

  buf = sysroot_path (path);
  if (buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  r = command (&out, &err, str_btrfs, "inspect-internal",
               "min-dev-size", buf, NULL);

  if (r == -1) {
    reply_with_error ("%s", err);
    return -1;
  }

#if __WORDSIZE == 64
#define XSTRTOD64 xstrtol
#else
#define XSTRTOD64 xstrtoll
#endif

  if (XSTRTOD64 (out, NULL, 10, &ret, NULL) != LONGINT_OK) {
    reply_with_error ("cannot parse minimum size");
    return -1;
  }

#undef XSTRTOD64

  return ret;
}
