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

#ifndef GUESTFS_GOBJECT_STRUCT_ISOINFO_H__
#define GUESTFS_GOBJECT_STRUCT_ISOINFO_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsISOInfo:
 * @iso_system_id: A NULL-terminated string
 * @iso_volume_id: A NULL-terminated string
 * @iso_volume_space_size: An unsigned 32-bit integer
 * @iso_volume_set_size: An unsigned 32-bit integer
 * @iso_volume_sequence_number: An unsigned 32-bit integer
 * @iso_logical_block_size: An unsigned 32-bit integer
 * @iso_volume_set_id: A NULL-terminated string
 * @iso_publisher_id: A NULL-terminated string
 * @iso_data_preparer_id: A NULL-terminated string
 * @iso_application_id: A NULL-terminated string
 * @iso_copyright_file_id: A NULL-terminated string
 * @iso_abstract_file_id: A NULL-terminated string
 * @iso_bibliographic_file_id: A NULL-terminated string
 * @iso_volume_creation_t: A signed 64-bit integer
 * @iso_volume_modification_t: A signed 64-bit integer
 * @iso_volume_expiration_t: A signed 64-bit integer
 * @iso_volume_effective_t: A signed 64-bit integer
 */
typedef struct _GuestfsISOInfo GuestfsISOInfo;
struct _GuestfsISOInfo {
  gchar *iso_system_id;
  gchar *iso_volume_id;
  guint32 iso_volume_space_size;
  guint32 iso_volume_set_size;
  guint32 iso_volume_sequence_number;
  guint32 iso_logical_block_size;
  gchar *iso_volume_set_id;
  gchar *iso_publisher_id;
  gchar *iso_data_preparer_id;
  gchar *iso_application_id;
  gchar *iso_copyright_file_id;
  gchar *iso_abstract_file_id;
  gchar *iso_bibliographic_file_id;
  gint64 iso_volume_creation_t;
  gint64 iso_volume_modification_t;
  gint64 iso_volume_expiration_t;
  gint64 iso_volume_effective_t;
};
GType guestfs_isoinfo_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_ISOINFO_H__ */
