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

#include "daemon.h"
#include "actions.h"

int
do_ntfs_3g_probe (int rw, char *device)
{
  char *err;
  int r;
  const char *rw_flag;

  IS_DEVICE (device, -1);

  rw_flag = rw ? "-w" : "-r";

  r = commandr (NULL, &err, "ntfs-3g.probe", rw_flag, device, NULL);
  if (r == -1) {
    reply_with_error ("ntfs-3g.probe: %s: %s", device, err);
    free (err);
    return -1;
  }

  return r;
}
