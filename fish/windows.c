/* libguestfs - shared Windows path for tools
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

#include "windows.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <langinfo.h>
#include <libintl.h>

#include "guestfs-internal-frontend.h"

#include "c-ctype.h"

static void mount_drive_letter (guestfs_h *g, char drive_letter,
                                const char *root, int readonly);

int
is_windows (guestfs_h *g, const char *root)
{
  int w;
  CLEANUP_FREE char *type = guestfs_inspect_get_type (g, root);
  if (!type)
    return 0;

  w = STREQ (type, "windows");
  return w;
}

char *
windows_path (guestfs_h *g, const char *root, const char *path, int readonly)
{
  char *ret;
  size_t i;

  /* If there is a drive letter, rewrite the path. */
  if (c_isalpha (path[0]) && path[1] == ':') {
    char drive_letter = c_tolower (path[0]);
    /* This returns the newly allocated string. */
    mount_drive_letter (g, drive_letter, root, readonly);
    ret = strdup (path + 2);
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }
  else if (!*path) {
    ret = strdup ("/");
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }
  else {
    ret = strdup (path);
    if (ret == NULL) {
      perror ("strdup");
      exit (EXIT_FAILURE);
    }
  }

  /* Blindly convert any backslashes into forward slashes.  Is this good? */
  for (i = 0; i < strlen (ret); ++i)
    if (ret[i] == '\\')
      ret[i] = '/';

  /* If this fails, we want to return NULL. */
  char *t = guestfs_case_sensitive_path (g, ret);
  free (ret);
  ret = t;

  return ret;
}

static void
mount_drive_letter (guestfs_h *g, char drive_letter, const char *root,
                    int readonly)
{
  char *device;
  size_t i;

  /* Resolve the drive letter using the drive mappings table. */
  CLEANUP_FREE_STRING_LIST char **drives =
    guestfs_inspect_get_drive_mappings (g, root);
  if (drives == NULL || drives[0] == NULL) {
    fprintf (stderr, _("%s: to use Windows drive letters, this must be a Windows guest\n"),
             guestfs_int_program_name);
    exit (EXIT_FAILURE);
  }

  device = NULL;
  for (i = 0; drives[i] != NULL; i += 2) {
    if (c_tolower (drives[i][0]) == drive_letter && drives[i][1] == '\0') {
      device = drives[i+1];
      break;
    }
  }

  if (device == NULL) {
    fprintf (stderr, _("%s: drive '%c:' not found.\n"),
             guestfs_int_program_name, drive_letter);
    exit (EXIT_FAILURE);
  }

  /* Unmount current disk and remount device. */
  if (guestfs_umount_all (g) == -1)
    exit (EXIT_FAILURE);

  if ((readonly ? guestfs_mount_ro : guestfs_mount) (g, device, "/") == -1)
    exit (EXIT_FAILURE);

  /* Don't need to free (device) because that string was in the
   * drives array.
   */
}
