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

#ifndef GUESTFS_GOBJECT_STRUCT_LVM_PV_H__
#define GUESTFS_GOBJECT_STRUCT_LVM_PV_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsPV:
 * @pv_name: A NULL-terminated string
 * @pv_uuid: A 32 byte UUID. Note that this is not NULL-terminated
 * @pv_fmt: A NULL-terminated string
 * @pv_size: An unsigned 64-bit integer
 * @dev_size: An unsigned 64-bit integer
 * @pv_free: An unsigned 64-bit integer
 * @pv_used: An unsigned 64-bit integer
 * @pv_attr: A NULL-terminated string
 * @pv_pe_count: A signed 64-bit integer
 * @pv_pe_alloc_count: A signed 64-bit integer
 * @pv_tags: A NULL-terminated string
 * @pe_start: An unsigned 64-bit integer
 * @pv_mda_count: A signed 64-bit integer
 * @pv_mda_free: An unsigned 64-bit integer
 */
typedef struct _GuestfsPV GuestfsPV;
struct _GuestfsPV {
  gchar *pv_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar pv_uuid[32];
  gchar *pv_fmt;
  guint64 pv_size;
  guint64 dev_size;
  guint64 pv_free;
  guint64 pv_used;
  gchar *pv_attr;
  gint64 pv_pe_count;
  gint64 pv_pe_alloc_count;
  gchar *pv_tags;
  guint64 pe_start;
  gint64 pv_mda_count;
  guint64 pv_mda_free;
};
GType guestfs_lvm_pv_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_LVM_PV_H__ */
