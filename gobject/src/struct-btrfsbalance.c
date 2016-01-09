/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
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

#include "guestfs-gobject.h"

/**
 * SECTION:struct-btrfsbalance
 * @title: GuestfsBTRFSBalance
 * @include: guestfs-gobject.h
 */

static GuestfsBTRFSBalance *
guestfs_btrfsbalance_copy (GuestfsBTRFSBalance *src)
{
  return g_slice_dup (GuestfsBTRFSBalance, src);
}

static void
guestfs_btrfsbalance_free (GuestfsBTRFSBalance *src)
{
  g_slice_free (GuestfsBTRFSBalance, src);
}

G_DEFINE_BOXED_TYPE (GuestfsBTRFSBalance, guestfs_btrfsbalance, guestfs_btrfsbalance_copy, guestfs_btrfsbalance_free)
