/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/c.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>

#include "guestfs.h"
#include "guestfs-internal.h"

GUESTFS_DLL_PUBLIC char *
guestfs_event_to_string (uint64_t event)
{
  char *ret;
  uint64_t i;
  size_t len;

  /* Count how long the final string will be. */
  len = 1;
  for (i = 0; i < 10; ++i) {
    if ((event & (UINT64_C(1) << i)) != 0)
      len += 16; /* overestimate */
  }

  /* Allocate the final string and construct it. */
  ret = malloc (len);
  if (!ret)
    return NULL;

  len = 0;

  if ((event & GUESTFS_EVENT_APPLIANCE) != 0) {
    strcpy (&ret[len], "appliance,");
    len += 9 + 1;
  }
  if ((event & GUESTFS_EVENT_CLOSE) != 0) {
    strcpy (&ret[len], "close,");
    len += 5 + 1;
  }
  if ((event & GUESTFS_EVENT_ENTER) != 0) {
    strcpy (&ret[len], "enter,");
    len += 5 + 1;
  }
  if ((event & GUESTFS_EVENT_LAUNCH_DONE) != 0) {
    strcpy (&ret[len], "launch_done,");
    len += 11 + 1;
  }
  if ((event & GUESTFS_EVENT_LIBRARY) != 0) {
    strcpy (&ret[len], "library,");
    len += 7 + 1;
  }
  if ((event & GUESTFS_EVENT_LIBVIRT_AUTH) != 0) {
    strcpy (&ret[len], "libvirt_auth,");
    len += 12 + 1;
  }
  if ((event & GUESTFS_EVENT_PROGRESS) != 0) {
    strcpy (&ret[len], "progress,");
    len += 8 + 1;
  }
  if ((event & GUESTFS_EVENT_SUBPROCESS_QUIT) != 0) {
    strcpy (&ret[len], "subprocess_quit,");
    len += 15 + 1;
  }
  if ((event & GUESTFS_EVENT_TRACE) != 0) {
    strcpy (&ret[len], "trace,");
    len += 5 + 1;
  }
  if ((event & GUESTFS_EVENT_WARNING) != 0) {
    strcpy (&ret[len], "warning,");
    len += 7 + 1;
  }

  if (len > 0)
    ret[len-1] = '\0'; /* truncates the final trailing comma */
  else
    ret[0] = '\0';

  return ret;
}
