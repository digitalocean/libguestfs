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

#ifndef GUESTFS_GOBJECT_STRUCT_MDSTAT_H__
#define GUESTFS_GOBJECT_STRUCT_MDSTAT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsMDStat:
 * @mdstat_device: A NULL-terminated string
 * @mdstat_index: A signed 32-bit integer
 * @mdstat_flags: A NULL-terminated string
 */
typedef struct _GuestfsMDStat GuestfsMDStat;
struct _GuestfsMDStat {
  gchar *mdstat_device;
  gint32 mdstat_index;
  gchar *mdstat_flags;
};
GType guestfs_mdstat_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_MDSTAT_H__ */
