/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_STRUCT_XFSINFO_H__
#define GUESTFS_GOBJECT_STRUCT_XFSINFO_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsXFSInfo:
 * @xfs_mntpoint: A NULL-terminated string
 * @xfs_inodesize: An unsigned 32-bit integer
 * @xfs_agcount: An unsigned 32-bit integer
 * @xfs_agsize: An unsigned 32-bit integer
 * @xfs_sectsize: An unsigned 32-bit integer
 * @xfs_attr: An unsigned 32-bit integer
 * @xfs_blocksize: An unsigned 32-bit integer
 * @xfs_datablocks: An unsigned 64-bit integer
 * @xfs_imaxpct: An unsigned 32-bit integer
 * @xfs_sunit: An unsigned 32-bit integer
 * @xfs_swidth: An unsigned 32-bit integer
 * @xfs_dirversion: An unsigned 32-bit integer
 * @xfs_dirblocksize: An unsigned 32-bit integer
 * @xfs_cimode: An unsigned 32-bit integer
 * @xfs_logname: A NULL-terminated string
 * @xfs_logblocksize: An unsigned 32-bit integer
 * @xfs_logblocks: An unsigned 32-bit integer
 * @xfs_logversion: An unsigned 32-bit integer
 * @xfs_logsectsize: An unsigned 32-bit integer
 * @xfs_logsunit: An unsigned 32-bit integer
 * @xfs_lazycount: An unsigned 32-bit integer
 * @xfs_rtname: A NULL-terminated string
 * @xfs_rtextsize: An unsigned 32-bit integer
 * @xfs_rtblocks: An unsigned 64-bit integer
 * @xfs_rtextents: An unsigned 64-bit integer
 */
typedef struct _GuestfsXFSInfo GuestfsXFSInfo;
struct _GuestfsXFSInfo {
  gchar *xfs_mntpoint;
  guint32 xfs_inodesize;
  guint32 xfs_agcount;
  guint32 xfs_agsize;
  guint32 xfs_sectsize;
  guint32 xfs_attr;
  guint32 xfs_blocksize;
  guint64 xfs_datablocks;
  guint32 xfs_imaxpct;
  guint32 xfs_sunit;
  guint32 xfs_swidth;
  guint32 xfs_dirversion;
  guint32 xfs_dirblocksize;
  guint32 xfs_cimode;
  gchar *xfs_logname;
  guint32 xfs_logblocksize;
  guint32 xfs_logblocks;
  guint32 xfs_logversion;
  guint32 xfs_logsectsize;
  guint32 xfs_logsunit;
  guint32 xfs_lazycount;
  gchar *xfs_rtname;
  guint32 xfs_rtextsize;
  guint64 xfs_rtblocks;
  guint64 xfs_rtextents;
};
GType guestfs_xfsinfo_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_XFSINFO_H__ */
