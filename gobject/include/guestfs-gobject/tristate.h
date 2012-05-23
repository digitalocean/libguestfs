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

#ifndef GUESTFS_GOBJECT_TRISTATE_H__
#define GUESTFS_GOBJECT_TRISTATE_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsTristate:
 * @GUESTFS_TRISTATE_FALSE: False
 * @GUESTFS_TRISTATE_TRUE: True
 * @GUESTFS_TRISTATE_NONE: Unset
 *
 * An object representing a tristate: i.e. true, false, or unset. If a language
 * binding has a native concept of true and false which also correspond to the
 * integer values 1 and 0 respectively, these will also correspond to
 * GUESTFS_TRISTATE_TRUE and GUESTFS_TRISTATE_FALSE.
 */
typedef enum
{
  GUESTFS_TRISTATE_FALSE,
  GUESTFS_TRISTATE_TRUE,
  GUESTFS_TRISTATE_NONE
} GuestfsTristate;

GType guestfs_tristate_get_type(void);
#define GUESTFS_TYPE_TRISTATE (guestfs_tristate_get_type())

G_END_DECLS

#endif /* GUESTFS_GOBJECT_TRISTATE_H__ */
