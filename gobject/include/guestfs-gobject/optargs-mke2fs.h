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

#ifndef GUESTFS_GOBJECT_OPTARGS_MKE2FS_H__
#define GUESTFS_GOBJECT_OPTARGS_MKE2FS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_MKE2FS (guestfs_mke2fs_get_type ())
#define GUESTFS_MKE2FS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_MKE2FS, GuestfsMke2fs))
#define GUESTFS_MKE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_MKE2FS, GuestfsMke2fsClass))
#define GUESTFS_IS_MKE2FS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_MKE2FS))
#define GUESTFS_IS_MKE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_MKE2FS))
#define GUESTFS_MKE2FS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_MKE2FS, GuestfsMke2fsClass))

typedef struct _GuestfsMke2fsPrivate GuestfsMke2fsPrivate;

/**
 * GuestfsMke2fs:
 *
 * An object encapsulating optional arguments for guestfs_session_mke2fs.
 */
typedef struct _GuestfsMke2fs GuestfsMke2fs;
struct _GuestfsMke2fs {
  GObject parent;
  GuestfsMke2fsPrivate *priv;
};

/**
 * GuestfsMke2fsClass:
 * @parent_class: The superclass of GuestfsMke2fsClass
 *
 * A class metadata object for GuestfsMke2fs.
 */
typedef struct _GuestfsMke2fsClass GuestfsMke2fsClass;
struct _GuestfsMke2fsClass {
  GObjectClass parent_class;
};

GType guestfs_mke2fs_get_type (void);
GuestfsMke2fs *guestfs_mke2fs_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_MKE2FS_H__ */
