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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "daemon.h"
#include "actions.h"

int
do_equal (const char *file1, const char *file2)
{
  char *file1buf, *file2buf;
  int file1len, file2len;
  char *err;
  int r;

  NEED_ROOT (-1);
  ABS_PATH (file1, -1);
  ABS_PATH (file2, -1);

  file1len = strlen (file1) + 32;
  file1buf = malloc (file1len);
  if (file1buf == NULL) {
    reply_with_perror ("malloc");
    return -1;
  }

  file2len = strlen (file2) + 32;
  file2buf = malloc (file2len);
  if (file2buf == NULL) {
    reply_with_perror ("malloc");
    free (file1buf);
    return -1;
  }

  snprintf (file1buf, file1len, "/sysroot%s", file1);
  snprintf (file2buf, file2len, "/sysroot%s", file2);

  r = commandr (NULL, &err, "cmp", "-s", file1buf, file2buf, NULL);

  free (file1buf);
  free (file2buf);

  if (r == -1 || r > 1) {
    reply_with_error ("cmp: %s", err);
    free (err);
    return -1;
  }

  free (err);

  return r == 0;
}
