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

#ifndef GUESTFS_GOBJECT_STRUCT_STATNS_H__
#define GUESTFS_GOBJECT_STRUCT_STATNS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsStatNS:
 * @st_dev: A signed 64-bit integer
 * @st_ino: A signed 64-bit integer
 * @st_mode: A signed 64-bit integer
 * @st_nlink: A signed 64-bit integer
 * @st_uid: A signed 64-bit integer
 * @st_gid: A signed 64-bit integer
 * @st_rdev: A signed 64-bit integer
 * @st_size: A signed 64-bit integer
 * @st_blksize: A signed 64-bit integer
 * @st_blocks: A signed 64-bit integer
 * @st_atime_sec: A signed 64-bit integer
 * @st_atime_nsec: A signed 64-bit integer
 * @st_mtime_sec: A signed 64-bit integer
 * @st_mtime_nsec: A signed 64-bit integer
 * @st_ctime_sec: A signed 64-bit integer
 * @st_ctime_nsec: A signed 64-bit integer
 * @st_spare1: A signed 64-bit integer
 * @st_spare2: A signed 64-bit integer
 * @st_spare3: A signed 64-bit integer
 * @st_spare4: A signed 64-bit integer
 * @st_spare5: A signed 64-bit integer
 * @st_spare6: A signed 64-bit integer
 */
typedef struct _GuestfsStatNS GuestfsStatNS;
struct _GuestfsStatNS {
  gint64 st_dev;
  gint64 st_ino;
  gint64 st_mode;
  gint64 st_nlink;
  gint64 st_uid;
  gint64 st_gid;
  gint64 st_rdev;
  gint64 st_size;
  gint64 st_blksize;
  gint64 st_blocks;
  gint64 st_atime_sec;
  gint64 st_atime_nsec;
  gint64 st_mtime_sec;
  gint64 st_mtime_nsec;
  gint64 st_ctime_sec;
  gint64 st_ctime_nsec;
  gint64 st_spare1;
  gint64 st_spare2;
  gint64 st_spare3;
  gint64 st_spare4;
  gint64 st_spare5;
  gint64 st_spare6;
};
GType guestfs_statns_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_STATNS_H__ */
