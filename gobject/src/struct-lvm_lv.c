/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#include "guestfs-gobject.h"

/**
 * SECTION:struct-lvm_lv
 * @title: GuestfsLV
 * @include: guestfs-gobject.h
 */

static GuestfsLV *
guestfs_lvm_lv_copy(GuestfsLV *src)
{
  return g_slice_dup(GuestfsLV, src);
}

static void
guestfs_lvm_lv_free(GuestfsLV *src)
{
  g_slice_free(GuestfsLV, src);
}

G_DEFINE_BOXED_TYPE(GuestfsLV, guestfs_lvm_lv, guestfs_lvm_lv_copy, guestfs_lvm_lv_free)
