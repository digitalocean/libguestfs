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

#ifndef GUESTFS_GOBJECT_STRUCT_BTRFSBALANCE_H__
#define GUESTFS_GOBJECT_STRUCT_BTRFSBALANCE_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsBTRFSBalance:
 * @btrfsbalance_status: A NULL-terminated string
 * @btrfsbalance_total: An unsigned 64-bit integer
 * @btrfsbalance_balanced: An unsigned 64-bit integer
 * @btrfsbalance_considered: An unsigned 64-bit integer
 * @btrfsbalance_left: An unsigned 64-bit integer
 */
typedef struct _GuestfsBTRFSBalance GuestfsBTRFSBalance;
struct _GuestfsBTRFSBalance {
  gchar *btrfsbalance_status;
  guint64 btrfsbalance_total;
  guint64 btrfsbalance_balanced;
  guint64 btrfsbalance_considered;
  guint64 btrfsbalance_left;
};
GType guestfs_btrfsbalance_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_BTRFSBALANCE_H__ */
