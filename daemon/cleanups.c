/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009-2015 Red Hat Inc.
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
#include <unistd.h>

#include <augeas.h>

#include "cleanups.h"

/* Use by the CLEANUP_* macros.  Do not call these directly. */
void
cleanup_free (void *ptr)
{
  free (* (void **) ptr);
}

extern void free_strings (char **argv);

void
cleanup_free_string_list (void *ptr)
{
  free_strings (* (char ***) ptr);
}

void
cleanup_unlink_free (void *ptr)
{
  char *filename = * (char **) ptr;

  if (filename) {
    unlink (filename);
    free (filename);
  }
}

void
cleanup_close (void *ptr)
{
  int fd = * (int *) ptr;

  if (fd >= 0)
    close (fd);
}

void
cleanup_aug_close (void *ptr)
{
  augeas *aug = * (augeas **) ptr;

  if (aug != NULL)
    aug_close (aug);
}

struct stringsbuf;
extern void free_stringsbuf (struct stringsbuf *sb);

void
cleanup_free_stringsbuf (void *ptr)
{
  free_stringsbuf ((struct stringsbuf *) ptr);
}
