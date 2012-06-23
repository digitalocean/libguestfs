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
 * SECTION:tristate
 * @title: GuestfsTristate
 * @short_description: An object representing a tristate value
 * @include: guestfs-gobject.h
 */

GType
guestfs_tristate_get_type(void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GUESTFS_TRISTATE_FALSE, "GUESTFS_TRISTATE_FALSE", "false" },
      { GUESTFS_TRISTATE_TRUE,  "GUESTFS_TRISTATE_TRUE",  "true" },
      { GUESTFS_TRISTATE_NONE,  "GUESTFS_TRISTATE_NONE",  "none" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static("GuestfsTristate", values);
  }
  return etype;
}
