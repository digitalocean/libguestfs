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

#ifndef GUESTFS_GOBJECT_STRUCT_STAT_H__
#define GUESTFS_GOBJECT_STRUCT_STAT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsStat:
 * @dev: A signed 64-bit integer
 * @ino: A signed 64-bit integer
 * @mode: A signed 64-bit integer
 * @nlink: A signed 64-bit integer
 * @uid: A signed 64-bit integer
 * @gid: A signed 64-bit integer
 * @rdev: A signed 64-bit integer
 * @size: A signed 64-bit integer
 * @blksize: A signed 64-bit integer
 * @blocks: A signed 64-bit integer
 * @atime: A signed 64-bit integer
 * @mtime: A signed 64-bit integer
 * @ctime: A signed 64-bit integer
 */
typedef struct _GuestfsStat GuestfsStat;
struct _GuestfsStat {
  gint64 dev;
  gint64 ino;
  gint64 mode;
  gint64 nlink;
  gint64 uid;
  gint64 gid;
  gint64 rdev;
  gint64 size;
  gint64 blksize;
  gint64 blocks;
  gint64 atime;
  gint64 mtime;
  gint64 ctime;
};
GType guestfs_stat_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_STAT_H__ */
