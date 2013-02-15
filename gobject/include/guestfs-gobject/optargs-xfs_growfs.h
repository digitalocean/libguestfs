/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_OPTARGS_XFS_GROWFS_H__
#define GUESTFS_GOBJECT_OPTARGS_XFS_GROWFS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_XFS_GROWFS (guestfs_xfs_growfs_get_type())
#define GUESTFS_XFS_GROWFS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_XFS_GROWFS, GuestfsXfsGrowfs))
#define GUESTFS_XFS_GROWFS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_XFS_GROWFS, GuestfsXfsGrowfsClass))
#define GUESTFS_IS_XFS_GROWFS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_XFS_GROWFS))
#define GUESTFS_IS_XFS_GROWFS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_XFS_GROWFS))
#define GUESTFS_XFS_GROWFS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_XFS_GROWFS, GuestfsXfsGrowfsClass))

typedef struct _GuestfsXfsGrowfsPrivate GuestfsXfsGrowfsPrivate;

/**
 * GuestfsXfsGrowfs:
 *
 * An object encapsulating optional arguments for guestfs_session_xfs_growfs.
 */
typedef struct _GuestfsXfsGrowfs GuestfsXfsGrowfs;
struct _GuestfsXfsGrowfs {
  GObject parent;
  GuestfsXfsGrowfsPrivate *priv;
};

/**
 * GuestfsXfsGrowfsClass:
 * @parent_class: The superclass of GuestfsXfsGrowfsClass
 *
 * A class metadata object for GuestfsXfsGrowfs.
 */
typedef struct _GuestfsXfsGrowfsClass GuestfsXfsGrowfsClass;
struct _GuestfsXfsGrowfsClass {
  GObjectClass parent_class;
};

GType guestfs_xfs_growfs_get_type(void);
GuestfsXfsGrowfs *guestfs_xfs_growfs_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_XFS_GROWFS_H__ */
