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

#ifndef GUESTFS_GOBJECT_STRUCT_LVM_VG_H__
#define GUESTFS_GOBJECT_STRUCT_LVM_VG_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsVG:
 * @vg_name: A NULL-terminated string
 * @vg_uuid: A 32 byte UUID. Note that this is not NULL-terminated
 * @vg_fmt: A NULL-terminated string
 * @vg_attr: A NULL-terminated string
 * @vg_size: An unsigned 64-bit integer
 * @vg_free: An unsigned 64-bit integer
 * @vg_sysid: A NULL-terminated string
 * @vg_extent_size: An unsigned 64-bit integer
 * @vg_extent_count: A signed 64-bit integer
 * @vg_free_count: A signed 64-bit integer
 * @max_lv: A signed 64-bit integer
 * @max_pv: A signed 64-bit integer
 * @pv_count: A signed 64-bit integer
 * @lv_count: A signed 64-bit integer
 * @snap_count: A signed 64-bit integer
 * @vg_seqno: A signed 64-bit integer
 * @vg_tags: A NULL-terminated string
 * @vg_mda_count: A signed 64-bit integer
 * @vg_mda_free: An unsigned 64-bit integer
 */
typedef struct _GuestfsVG GuestfsVG;
struct _GuestfsVG {
  gchar *vg_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar vg_uuid[32];
  gchar *vg_fmt;
  gchar *vg_attr;
  guint64 vg_size;
  guint64 vg_free;
  gchar *vg_sysid;
  guint64 vg_extent_size;
  gint64 vg_extent_count;
  gint64 vg_free_count;
  gint64 max_lv;
  gint64 max_pv;
  gint64 pv_count;
  gint64 lv_count;
  gint64 snap_count;
  gint64 vg_seqno;
  gchar *vg_tags;
  gint64 vg_mda_count;
  guint64 vg_mda_free;
};
GType guestfs_lvm_vg_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_LVM_VG_H__ */
