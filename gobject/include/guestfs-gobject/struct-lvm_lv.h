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

#ifndef GUESTFS_GOBJECT_STRUCT_LVM_LV_H__
#define GUESTFS_GOBJECT_STRUCT_LVM_LV_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsLV:
 * @lv_name: A NULL-terminated string
 * @lv_uuid: A 32 byte UUID. Note that this is not NULL-terminated
 * @lv_attr: A NULL-terminated string
 * @lv_major: A signed 64-bit integer
 * @lv_minor: A signed 64-bit integer
 * @lv_kernel_major: A signed 64-bit integer
 * @lv_kernel_minor: A signed 64-bit integer
 * @lv_size: An unsigned 64-bit integer
 * @seg_count: A signed 64-bit integer
 * @origin: A NULL-terminated string
 * @snap_percent: A floating point number. A value between 0 and 100 represents a percentage. A value of -1 represents 'not present'
 * @copy_percent: A floating point number. A value between 0 and 100 represents a percentage. A value of -1 represents 'not present'
 * @move_pv: A NULL-terminated string
 * @lv_tags: A NULL-terminated string
 * @mirror_log: A NULL-terminated string
 * @modules: A NULL-terminated string
 */
typedef struct _GuestfsLV GuestfsLV;
struct _GuestfsLV {
  gchar *lv_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar lv_uuid[32];
  gchar *lv_attr;
  gint64 lv_major;
  gint64 lv_minor;
  gint64 lv_kernel_major;
  gint64 lv_kernel_minor;
  guint64 lv_size;
  gint64 seg_count;
  gchar *origin;
  /* The next field is [0..100] or -1 meaning 'not present': */
  gfloat snap_percent;
  /* The next field is [0..100] or -1 meaning 'not present': */
  gfloat copy_percent;
  gchar *move_pv;
  gchar *lv_tags;
  gchar *mirror_log;
  gchar *modules;
};
GType guestfs_lvm_lv_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_LVM_LV_H__ */
