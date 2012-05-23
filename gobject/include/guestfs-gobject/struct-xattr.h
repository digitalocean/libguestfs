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

#ifndef GUESTFS_GOBJECT_STRUCT_XATTR_H__
#define GUESTFS_GOBJECT_STRUCT_XATTR_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsXAttr:
 * @attrname: A NULL-terminated string
 * @attrval: A GByteArray
 */
typedef struct _GuestfsXAttr GuestfsXAttr;
struct _GuestfsXAttr {
  gchar *attrname;
  GByteArray *attrval;
};
GType guestfs_xattr_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_XATTR_H__ */
