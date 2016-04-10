/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>

#include "fish.h"

int
event_bitmask_of_event_set (const char *arg, uint64_t *eventset_r)
{
  size_t n;

  if (STREQ (arg, "*")) {
    *eventset_r = GUESTFS_EVENT_ALL;
    return 0;
  }

  *eventset_r = 0;

  while (*arg) {
    n = strcspn (arg, ",");

    if (STREQLEN (arg, "close", n))
      *eventset_r |= GUESTFS_EVENT_CLOSE;
    else if (STREQLEN (arg, "subprocess_quit", n))
      *eventset_r |= GUESTFS_EVENT_SUBPROCESS_QUIT;
    else if (STREQLEN (arg, "launch_done", n))
      *eventset_r |= GUESTFS_EVENT_LAUNCH_DONE;
    else if (STREQLEN (arg, "progress", n))
      *eventset_r |= GUESTFS_EVENT_PROGRESS;
    else if (STREQLEN (arg, "appliance", n))
      *eventset_r |= GUESTFS_EVENT_APPLIANCE;
    else if (STREQLEN (arg, "library", n))
      *eventset_r |= GUESTFS_EVENT_LIBRARY;
    else if (STREQLEN (arg, "trace", n))
      *eventset_r |= GUESTFS_EVENT_TRACE;
    else if (STREQLEN (arg, "enter", n))
      *eventset_r |= GUESTFS_EVENT_ENTER;
    else if (STREQLEN (arg, "libvirt_auth", n))
      *eventset_r |= GUESTFS_EVENT_LIBVIRT_AUTH;
    else if (STREQLEN (arg, "warning", n))
      *eventset_r |= GUESTFS_EVENT_WARNING;
    else {
      fprintf (stderr, _("unknown event name: %s\n"), arg);
      return -1;
    }

    arg += n;
    if (*arg == ',')
      arg++;
  }

  return 0;
}
