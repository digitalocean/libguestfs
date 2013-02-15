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
#include <unistd.h>
#include <fcntl.h>

#include "daemon.h"
#include "actions.h"

GUESTFSD_EXT_CMD(str_cmp, cmp);

int
do_equal (const char *file1, const char *file2)
{
  CLEANUP_FREE char *file1buf = NULL, *file2buf = NULL;
  CLEANUP_FREE char *err = NULL;
  int r;

  file1buf = sysroot_path (file1);
  if (file1buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  file2buf = sysroot_path (file2);
  if (file2buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  r = commandr (NULL, &err, str_cmp, "-s", file1buf, file2buf, NULL);
  if (r == -1 || r > 1) {
    reply_with_error ("%s", err);
    return -1;
  }

  return r == 0;
}
