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

#ifndef GUESTFS_GOBJECT_OPTARGS_TUNE2FS_H__
#define GUESTFS_GOBJECT_OPTARGS_TUNE2FS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_TUNE2FS (guestfs_tune2fs_get_type())
#define GUESTFS_TUNE2FS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FS))
#define GUESTFS_TUNE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSClass))
#define GUESTFS_IS_TUNE2FS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_TUNE2FS))
#define GUESTFS_IS_TUNE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_TUNE2FS))
#define GUESTFS_TUNE2FS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSClass))

typedef struct _GuestfsTune2FSPrivate GuestfsTune2FSPrivate;

/**
 * GuestfsTune2FS:
 *
 * An object encapsulating optional arguments for guestfs_session_tune2fs.
 */
typedef struct _GuestfsTune2FS GuestfsTune2FS;
struct _GuestfsTune2FS {
  GObject parent;
  GuestfsTune2FSPrivate *priv;
};

/**
 * GuestfsTune2FSClass:
 * @parent_class: The superclass of GuestfsTune2FSClass
 *
 * A class metadata object for GuestfsTune2FS.
 */
typedef struct _GuestfsTune2FSClass GuestfsTune2FSClass;
struct _GuestfsTune2FSClass {
  GObjectClass parent_class;
};

GType guestfs_tune2fs_get_type(void);
GuestfsTune2FS *guestfs_tune2fs_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_TUNE2FS_H__ */
