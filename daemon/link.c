/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009 Red Hat Inc.
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
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#include "areadlink.h"

#include "daemon.h"
#include "actions.h"

GUESTFSD_EXT_CMD(str_ln, ln);

char *
do_readlink (const char *path)
{
  char *link;

  CHROOT_IN;
  link = areadlink (path);
  CHROOT_OUT;
  if (link == NULL) {
    reply_with_perror ("%s", path);
    return NULL;
  }

  return link;			/* caller frees */
}

char **
do_internal_readlinklist (const char *path, char *const *names)
{
  int fd_cwd;
  size_t i;
  DECLARE_STRINGSBUF (ret);

  CHROOT_IN;
  fd_cwd = open (path, O_RDONLY|O_DIRECTORY|O_CLOEXEC);
  CHROOT_OUT;

  if (fd_cwd == -1) {
    reply_with_perror ("open: %s", path);
    return NULL;
  }

  for (i = 0; names[i] != NULL; ++i) {
    /* Because of the way this function is intended to be used,
     * we actually expect to see errors here, and they are not fatal.
     */
    CLEANUP_FREE char *link = areadlinkat (fd_cwd, names[i]);

    if (link != NULL) {
      if (add_string (&ret, link) == -1) {
      add_string_failed:
        close (fd_cwd);
        return NULL;
      }
    } else {
      if (add_string (&ret, "") == -1)
        goto add_string_failed;
    }
  }

  close (fd_cwd);

  if (end_stringsbuf (&ret) == -1)
    return NULL;

  return ret.argv;
}

int
do_ln (const char *target, const char *linkname)
{
  int r;

  CHROOT_IN;
  r = link (target, linkname);
  CHROOT_OUT;

  if (r == -1) {
    reply_with_perror ("link: %s: %s", target, linkname);
    return -1;
  }

  return 0;
}

int
do_ln_f (const char *target, const char *linkname)
{
  int r;

  CHROOT_IN;
  unlink (linkname);
  r = link (target, linkname);
  CHROOT_OUT;

  if (r == -1) {
    reply_with_perror ("link: %s: %s", target, linkname);
    return -1;
  }

  return 0;
}

static int
_symlink (const char *flag, const char *target, const char *linkname)
{
  int r;
  CLEANUP_FREE char *err = NULL;
  CLEANUP_FREE char *buf_linkname = NULL;

  /* Prefix linkname with sysroot. */
  buf_linkname = sysroot_path (linkname);
  if (!buf_linkname) {
    reply_with_perror ("malloc");
    return -1;
  }

  r = command (NULL, &err,
               str_ln, flag, "--", /* target could begin with '-' */
               target, buf_linkname, NULL);
  if (r == -1) {
    reply_with_error ("ln %s: %s: %s: %s",
                      flag, target, linkname, err);
    return -1;
  }

  return 0;
}

int
do_ln_s (const char *target, const char *linkname)
{
  return _symlink ("-s", target, linkname);
}

int
do_ln_sf (const char *target, const char *linkname)
{
  return _symlink ("-sf", target, linkname);
}
