/* guestfish - guest filesystem shell
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
#include <string.h>
#include <unistd.h>
#include <libintl.h>

#include "fish.h"

/* guestfish lcd command (similar to the lcd command in BSD ftp) */

int
run_lcd (const char *cmd, size_t argc, char *argv[])
{
  if (argc != 1) {
    fprintf (stderr, _("use 'lcd directory' to change local directory\n"));
    return -1;
  }

  if (chdir (argv[0]) == -1) {
    perror (argv[0]);
    return -1;
  }

  return 0;
}
