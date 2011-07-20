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
#include <limits.h>

#include "daemon.h"
#include "actions.h"

static char *
get_blkid_tag (const char *device, const char *tag)
{
  char *out, *err;
  int r;

  /* Kill the cache file, forcing blkid to reread values from the
   * original filesystems.  In blkid there is a '-p' option which is
   * supposed to do this, but (a) it doesn't work and (b) that option
   * is not supported in RHEL 5.
   */
  unlink ("/etc/blkid/blkid.tab"); /* Red Hat, Fedora */
  unlink ("/etc/blkid.tab"); /* Debian */

  r = command (&out, &err,
               "blkid", "-o", "value", "-s", tag, device, NULL);
  if (r == -1) {
    reply_with_error ("%s: %s", device, err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  /* Trim trailing \n if present. */
  size_t len = strlen (out);
  if (len > 0 && out[len-1] == '\n')
    out[len-1] = '\0';

  return out;                   /* caller frees */
}

char *
do_vfs_type (const char *device)
{
  return get_blkid_tag (device, "TYPE");
}

char *
do_vfs_label (const char *device)
{
  return get_blkid_tag (device, "LABEL");
}

char *
do_vfs_uuid (const char *device)
{
  return get_blkid_tag (device, "UUID");
}
