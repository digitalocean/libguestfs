/* libguestfs - the guestfsd daemon
 * Copyright (C) 2010-2012 Red Hat Inc.
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
#include <sys/stat.h>

#include "c-ctype.h"
#include "ignore-value.h"

#include "daemon.h"
#include "actions.h"

GUESTFSD_EXT_CMD(str_lvm, lvm);
GUESTFSD_EXT_CMD(str_cp, cp);
GUESTFSD_EXT_CMD(str_rm, rm);

/* This runs during daemon start up and creates a complete copy of
 * /etc/lvm so that we can modify it as we desire.  We set
 * LVM_SYSTEM_DIR to point to the copy.  Note that the final directory
 * layout is:
 *   /tmp/lvmXXXXXX                 (lvm_system_dir set to this)
 *   /tmp/lvmXXXXXX/lvm             ($LVM_SYSTEM_DIR set to this)
 *   /tmp/lvmXXXXXX/lvm/lvm.conf    (configuration file)
 *   /tmp/lvmXXXXXX/lvm/cache
 *   etc.
 */
static char lvm_system_dir[] = "/tmp/lvmXXXXXX";

static void rm_lvm_system_dir (void);

void
copy_lvm (void)
{
  struct stat statbuf;
  char cmd[64], env[64];
  int r;

  /* If /etc/lvm directory doesn't exist (or isn't a directory) assume
   * that this system doesn't support LVM and do nothing.
   */
  r = stat ("/etc/lvm", &statbuf);
  if (r == -1) {
    perror ("copy_lvm: stat: /etc/lvm");
    return;
  }
  if (! S_ISDIR (statbuf.st_mode)) {
    fprintf (stderr, "copy_lvm: warning: /etc/lvm is not a directory\n");
    return;
  }

  if (mkdtemp (lvm_system_dir) == NULL) {
    fprintf (stderr, "mkdtemp: %s: %m\n", lvm_system_dir);
    exit (EXIT_FAILURE);
  }

  /* Copy the entire directory */
  snprintf (cmd, sizeof cmd, "%s -a /etc/lvm/ %s", str_cp, lvm_system_dir);
  r = system (cmd);
  if (r == -1) {
    perror (cmd);
    rmdir (lvm_system_dir);
    exit (EXIT_FAILURE);
  }

  if (WEXITSTATUS (r) != 0) {
    fprintf (stderr, "cp command failed with return code %d\n",
             WEXITSTATUS (r));
    rmdir (lvm_system_dir);
    exit (EXIT_FAILURE);
  }

  /* Set environment variable so we use the copy. */
  snprintf (env, sizeof env, "%s/lvm", lvm_system_dir);
  setenv ("LVM_SYSTEM_DIR", env, 1);

  /* Set a handler to remove the temporary directory at exit. */
  atexit (rm_lvm_system_dir);
}

static void
rm_lvm_system_dir (void)
{
  char cmd[64];

  snprintf (cmd, sizeof cmd, "%s -rf %s", str_rm, lvm_system_dir);
  ignore_value (system (cmd));
}

/* Does the current line match the regexp /^\s*filter\s*=/ */
static int
is_filter_line (const char *line)
{
  while (*line && c_isspace (*line))
    line++;
  if (!*line)
    return 0;

  if (! STRPREFIX (line, "filter"))
    return 0;
  line += 6;

  while (*line && c_isspace (*line))
    line++;
  if (!*line)
    return 0;

  if (*line != '=')
    return 0;

  return 1;
}

/* Rewrite the 'filter = [ ... ]' line in lvm.conf. */
static int
set_filter (const char *filter)
{
  char lvm_conf[64];
  snprintf (lvm_conf, sizeof lvm_conf, "%s/lvm/lvm.conf", lvm_system_dir);

  char lvm_conf_new[64];
  snprintf (lvm_conf_new, sizeof lvm_conf, "%s/lvm/lvm.conf.new",
            lvm_system_dir);

  FILE *ifp = fopen (lvm_conf, "r");
  if (ifp == NULL) {
    reply_with_perror ("open: %s", lvm_conf);
    return -1;
  }
  FILE *ofp = fopen (lvm_conf_new, "w");
  if (ofp == NULL) {
    reply_with_perror ("open: %s", lvm_conf_new);
    fclose (ifp);
    return -1;
  }

  CLEANUP_FREE char *line = NULL;
  size_t allocsize = 0;
  while (getline (&line, &allocsize, ifp) != -1) {
    int r;
    if (is_filter_line (line)) {
      r = fprintf (ofp, "    filter = [ %s ]\n", filter);
    } else {
      r = fprintf (ofp, "%s", line);
    }
    if (r < 0) {
      /* NB. fprintf doesn't set errno on error. */
      reply_with_error ("%s: write failed", lvm_conf_new);
      fclose (ifp);
      fclose (ofp);
      unlink (lvm_conf_new);
      return -1;
    }
  }

  if (fclose (ifp) == EOF) {
    reply_with_perror ("close: %s", lvm_conf);
    unlink (lvm_conf_new);
    fclose (ofp);
    return -1;
  }
  if (fclose (ofp) == EOF) {
    reply_with_perror ("close: %s", lvm_conf_new);
    unlink (lvm_conf_new);
    return -1;
  }

  if (rename (lvm_conf_new, lvm_conf) == -1) {
    reply_with_perror ("rename: %s", lvm_conf);
    unlink (lvm_conf_new);
    return -1;
  }

  return 0;
}

static int
vgchange (const char *vgchange_flag)
{
  CLEANUP_FREE char *err = NULL;
  int r = command (NULL, &err, str_lvm, "vgchange", vgchange_flag, NULL);
  if (r == -1) {
    reply_with_error ("vgchange: %s", err);
    return -1;
  }

  return 0;
}

/* Deactivate all VGs. */
static int
deactivate (void)
{
  return vgchange ("-an");
}

/* Reactivate all VGs. */
static int
reactivate (void)
{
  return vgchange ("-ay");
}

/* Clear the cache and rescan. */
static int
rescan (void)
{
  char lvm_cache[64];
  snprintf (lvm_cache, sizeof lvm_cache, "%s/lvm/cache/.cache", lvm_system_dir);

  unlink (lvm_cache);

  CLEANUP_FREE char *err = NULL;
  int r = command (NULL, &err, str_lvm, "vgscan", NULL);
  if (r == -1) {
    reply_with_error ("vgscan: %s", err);
    return -1;
  }

  return 0;
}

/* Construct the new, specific filter string.  We can assume that
 * the 'devices' array does not contain any regexp metachars,
 * because it's already been checked by the stub code.
 */
static char *
make_filter_string (char *const *devices)
{
  size_t i;
  size_t len = 64;
  for (i = 0; devices[i] != NULL; ++i)
    len += 2 * strlen (devices[i]) + 64;

  char *filter = malloc (len);
  if (filter == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  char *p = filter;
  for (i = 0; devices[i] != NULL; ++i) {
    /* Because of the way matching works in LVM (yes, they wrote their
     * own regular expression engine!), each match clause should be either:
     *
     *   for single partitions:
     *     "a|^/dev/sda1$|",
     *   for whole block devices:
     *     "a|^/dev/sda$|", "a|^/dev/sda[0-9]|",
     */
    size_t slen = strlen (devices[i]);
    char str[2*slen+64];

    if (c_isdigit (devices[i][slen-1])) /* single partition */
      snprintf (str, 2*slen+64, "\"a|^%s$|\", ", devices[i]);
    else                        /* whole block device */
      snprintf (str, 2*slen+64, "\"a|^%s$|\", \"a|^%s[0-9]|\", ",
                devices[i], devices[i]);

    strcpy (p, str);
    p += strlen (str);
  }
  strcpy (p, "\"r|.*|\"");

  return filter;                /* Caller must free. */
}

int
do_lvm_set_filter (char *const *devices)
{
  CLEANUP_FREE char *filter = make_filter_string (devices);
  if (filter == NULL)
    return -1;

  if (deactivate () == -1)
    return -1;

  int r = set_filter (filter);
  if (r == -1)
    return -1;

  if (rescan () == -1)
    return -1;

  return reactivate ();
}

int
do_lvm_clear_filter (void)
{
  if (deactivate () == -1)
    return -1;

  if (set_filter ("\"a/.*/\"") == -1)
    return -1;

  if (rescan () == -1)
    return -1;

  return reactivate ();
}
