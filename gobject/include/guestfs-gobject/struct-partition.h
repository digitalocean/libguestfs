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

#ifndef GUESTFS_GOBJECT_STRUCT_PARTITION_H__
#define GUESTFS_GOBJECT_STRUCT_PARTITION_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsPartition:
 * @part_num: A signed 32-bit integer
 * @part_start: An unsigned 64-bit integer
 * @part_end: An unsigned 64-bit integer
 * @part_size: An unsigned 64-bit integer
 */
typedef struct _GuestfsPartition GuestfsPartition;
struct _GuestfsPartition {
  gint32 part_num;
  guint64 part_start;
  guint64 part_end;
  guint64 part_size;
};
GType guestfs_partition_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_PARTITION_H__ */
