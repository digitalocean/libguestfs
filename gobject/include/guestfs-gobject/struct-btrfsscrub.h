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

#ifndef GUESTFS_GOBJECT_STRUCT_BTRFSSCRUB_H__
#define GUESTFS_GOBJECT_STRUCT_BTRFSSCRUB_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsBTRFSScrub:
 * @btrfsscrub_data_extents_scrubbed: An unsigned 64-bit integer
 * @btrfsscrub_tree_extents_scrubbed: An unsigned 64-bit integer
 * @btrfsscrub_data_bytes_scrubbed: An unsigned 64-bit integer
 * @btrfsscrub_tree_bytes_scrubbed: An unsigned 64-bit integer
 * @btrfsscrub_read_errors: An unsigned 64-bit integer
 * @btrfsscrub_csum_errors: An unsigned 64-bit integer
 * @btrfsscrub_verify_errors: An unsigned 64-bit integer
 * @btrfsscrub_no_csum: An unsigned 64-bit integer
 * @btrfsscrub_csum_discards: An unsigned 64-bit integer
 * @btrfsscrub_super_errors: An unsigned 64-bit integer
 * @btrfsscrub_malloc_errors: An unsigned 64-bit integer
 * @btrfsscrub_uncorrectable_errors: An unsigned 64-bit integer
 * @btrfsscrub_unverified_errors: An unsigned 64-bit integer
 * @btrfsscrub_corrected_errors: An unsigned 64-bit integer
 * @btrfsscrub_last_physical: An unsigned 64-bit integer
 */
typedef struct _GuestfsBTRFSScrub GuestfsBTRFSScrub;
struct _GuestfsBTRFSScrub {
  guint64 btrfsscrub_data_extents_scrubbed;
  guint64 btrfsscrub_tree_extents_scrubbed;
  guint64 btrfsscrub_data_bytes_scrubbed;
  guint64 btrfsscrub_tree_bytes_scrubbed;
  guint64 btrfsscrub_read_errors;
  guint64 btrfsscrub_csum_errors;
  guint64 btrfsscrub_verify_errors;
  guint64 btrfsscrub_no_csum;
  guint64 btrfsscrub_csum_discards;
  guint64 btrfsscrub_super_errors;
  guint64 btrfsscrub_malloc_errors;
  guint64 btrfsscrub_uncorrectable_errors;
  guint64 btrfsscrub_unverified_errors;
  guint64 btrfsscrub_corrected_errors;
  guint64 btrfsscrub_last_physical;
};
GType guestfs_btrfsscrub_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_BTRFSSCRUB_H__ */
