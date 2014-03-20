/* libguestfs - the guestfsd daemon
 * Copyright (C) 2011 Red Hat Inc.
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
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#include "daemon.h"
#include "actions.h"

#define BUS_PATH "/sys/bus/virtio/drivers/9pnet_virtio"
GUESTFSD_EXT_CMD(str_mount, mount);

static char *read_whole_file (const char *filename);

/* https://bugzilla.redhat.com/show_bug.cgi?id=714981#c1 */
char **
do_list_9p (void)
{
  DECLARE_STRINGSBUF (r);

  DIR *dir;

  dir = opendir (BUS_PATH);
  if (!dir) {
    perror ("opendir: " BUS_PATH);
    if (errno != ENOENT) {
      reply_with_perror ("opendir: " BUS_PATH);
      return NULL;
    }

    /* If this directory doesn't exist, it probably means that
     * the virtio driver isn't loaded.  Don't return an error
     * in this case, but return an empty list.
     */
    if (end_stringsbuf (&r) == -1)
      return NULL;

    return r.argv;
  }

  while (1) {
    struct dirent *d;

    errno = 0;
    d = readdir (dir);
    if (d == NULL) break;

    if (STRPREFIX (d->d_name, "virtio")) {
      char mount_tag_path[256];
      snprintf (mount_tag_path, sizeof mount_tag_path,
                BUS_PATH "/%s/mount_tag", d->d_name);

      /* A bit unclear, but it looks like the virtio transport allows
       * the mount tag length to be unlimited (or up to 65536 bytes).
       * See: linux/include/linux/virtio_9p.h
       */
      CLEANUP_FREE char *mount_tag = read_whole_file (mount_tag_path);
      if (mount_tag == 0)
        continue;

      if (add_string (&r, mount_tag) == -1) {
        closedir (dir);
        return NULL;
      }
    }
  }

  /* Check readdir didn't fail */
  if (errno != 0) {
    reply_with_perror ("readdir: /sys/block");
    free_stringslen (r.argv, r.size);
    closedir (dir);
    return NULL;
  }

  /* Close the directory handle */
  if (closedir (dir) == -1) {
    reply_with_perror ("closedir: /sys/block");
    free_stringslen (r.argv, r.size);
    return NULL;
  }

  /* Sort the tags. */
  if (r.size > 0)
    sort_strings (r.argv, r.size);

  /* NULL terminate the list */
  if (end_stringsbuf (&r) == -1)
    return NULL;

  return r.argv;
}

/* Read whole file into dynamically allocated array.  If there is an
 * error, DON'T call reply_with_perror, just return NULL.  Returns a
 * \0-terminated string.
 */
static char *
read_whole_file (const char *filename)
{
  char *r = NULL;
  size_t alloc = 0, size = 0;
  int fd;

  fd = open (filename, O_RDONLY|O_CLOEXEC);
  if (fd == -1) {
    perror (filename);
    return NULL;
  }

  while (1) {
    alloc += 256;
    char *r2 = realloc (r, alloc);
    if (r2 == NULL) {
      perror ("realloc");
      free (r);
      close (fd);
      return NULL;
    }
    r = r2;

    /* The '- 1' in the size calculation ensures there is space below
     * to add \0 to the end of the input.
     */
    ssize_t n = read (fd, r + size, alloc - size - 1);
    if (n == -1) {
      fprintf (stderr, "read: %s: %m\n", filename);
      free (r);
      close (fd);
      return NULL;
    }
    if (n == 0)
      break;
    size += n;
  }

  if (close (fd) == -1) {
    fprintf (stderr, "close: %s: %m\n", filename);
    free (r);
    return NULL;
  }

  r[size] = '\0';

  return r;
}

/* Takes optional arguments, consult optargs_bitmask. */
int
do_mount_9p (const char *mount_tag, const char *mountpoint, const char *options)
{
  CLEANUP_FREE char *mp = NULL, *opts = NULL, *err = NULL;
  struct stat statbuf;
  int r;

  ABS_PATH (mountpoint, , return -1);

  mp = sysroot_path (mountpoint);
  if (!mp) {
    reply_with_perror ("malloc");
    return -1;
  }

  /* Check the mountpoint exists and is a directory. */
  if (stat (mp, &statbuf) == -1) {
    reply_with_perror ("%s", mountpoint);
    return -1;
  }
  if (!S_ISDIR (statbuf.st_mode)) {
    reply_with_perror ("%s: mount point is not a directory", mountpoint);
    return -1;
  }

  /* Add trans=virtio to the options. */
  if ((optargs_bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK) &&
      STRNEQ (options, "")) {
    if (asprintf (&opts, "trans=virtio,%s", options) == -1) {
      reply_with_perror ("asprintf");
      return -1;
    }
  }
  else {
    opts = strdup ("trans=virtio");
    if (opts == NULL) {
      reply_with_perror ("strdup");
      return -1;
    }
  }

  r = command (NULL, &err,
               str_mount, "-o", opts, "-t", "9p", mount_tag, mp, NULL);
  if (r == -1) {
    reply_with_error ("%s on %s: %s", mount_tag, mountpoint, err);
    return -1;
  }

  return 0;
}
