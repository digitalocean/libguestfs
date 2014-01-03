/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
 * SECTION:struct-mdstat
 * @title: GuestfsMDStat
 * @include: guestfs-gobject.h
 */

static GuestfsMDStat *
guestfs_mdstat_copy(GuestfsMDStat *src)
{
  return g_slice_dup(GuestfsMDStat, src);
}

static void
guestfs_mdstat_free(GuestfsMDStat *src)
{
  g_slice_free(GuestfsMDStat, src);
}

G_DEFINE_BOXED_TYPE(GuestfsMDStat, guestfs_mdstat, guestfs_mdstat_copy, guestfs_mdstat_free)
