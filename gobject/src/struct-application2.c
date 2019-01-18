/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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
 * SECTION:struct-application2
 * @title: GuestfsApplication2
 * @include: guestfs-gobject.h
 */

static GuestfsApplication2 *
guestfs_application2_copy (GuestfsApplication2 *src)
{
  return g_slice_dup (GuestfsApplication2, src);
}

static void
guestfs_application2_free (GuestfsApplication2 *src)
{
  g_slice_free (GuestfsApplication2, src);
}

G_DEFINE_BOXED_TYPE (GuestfsApplication2, guestfs_application2, guestfs_application2_copy, guestfs_application2_free)
