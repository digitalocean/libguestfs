/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * SECTION:struct-yara_detection
 * @title: GuestfsYaraDetection
 * @include: guestfs-gobject.h
 */

static GuestfsYaraDetection *
guestfs_yara_detection_copy (GuestfsYaraDetection *src)
{
  return g_slice_dup (GuestfsYaraDetection, src);
}

static void
guestfs_yara_detection_free (GuestfsYaraDetection *src)
{
  g_slice_free (GuestfsYaraDetection, src);
}

G_DEFINE_BOXED_TYPE (GuestfsYaraDetection, guestfs_yara_detection, guestfs_yara_detection_copy, guestfs_yara_detection_free)
