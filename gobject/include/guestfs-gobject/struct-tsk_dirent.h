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

#ifndef GUESTFS_GOBJECT_STRUCT_TSK_DIRENT_H__
#define GUESTFS_GOBJECT_STRUCT_TSK_DIRENT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsTSKDirent:
 * @tsk_inode: An unsigned 64-bit integer
 * @tsk_type: A character
 * @tsk_size: A signed 64-bit integer
 * @tsk_name: A NULL-terminated string
 * @tsk_flags: An unsigned 32-bit integer
 * @tsk_atime_sec: A signed 64-bit integer
 * @tsk_atime_nsec: A signed 64-bit integer
 * @tsk_mtime_sec: A signed 64-bit integer
 * @tsk_mtime_nsec: A signed 64-bit integer
 * @tsk_ctime_sec: A signed 64-bit integer
 * @tsk_ctime_nsec: A signed 64-bit integer
 * @tsk_crtime_sec: A signed 64-bit integer
 * @tsk_crtime_nsec: A signed 64-bit integer
 * @tsk_nlink: A signed 64-bit integer
 * @tsk_link: A NULL-terminated string
 * @tsk_spare1: A signed 64-bit integer
 */
typedef struct _GuestfsTSKDirent GuestfsTSKDirent;
struct _GuestfsTSKDirent {
  guint64 tsk_inode;
  gchar tsk_type;
  gint64 tsk_size;
  gchar *tsk_name;
  guint32 tsk_flags;
  gint64 tsk_atime_sec;
  gint64 tsk_atime_nsec;
  gint64 tsk_mtime_sec;
  gint64 tsk_mtime_nsec;
  gint64 tsk_ctime_sec;
  gint64 tsk_ctime_nsec;
  gint64 tsk_crtime_sec;
  gint64 tsk_crtime_nsec;
  gint64 tsk_nlink;
  gchar *tsk_link;
  gint64 tsk_spare1;
};
GType guestfs_tsk_dirent_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_TSK_DIRENT_H__ */
