/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_OPTARGS_IS_FILE_H__
#define GUESTFS_GOBJECT_OPTARGS_IS_FILE_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_IS_FILE (guestfs_is_file_get_type ())
#define GUESTFS_IS_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_IS_FILE, GuestfsIsFile))
#define GUESTFS_IS_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_IS_FILE, GuestfsIsFileClass))
#define GUESTFS_IS_IS_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_IS_FILE))
#define GUESTFS_IS_IS_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_IS_FILE))
#define GUESTFS_IS_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_IS_FILE, GuestfsIsFileClass))

typedef struct _GuestfsIsFilePrivate GuestfsIsFilePrivate;

/**
 * GuestfsIsFile:
 *
 * An object encapsulating optional arguments for guestfs_session_is_file.
 */
typedef struct _GuestfsIsFile GuestfsIsFile;
struct _GuestfsIsFile {
  GObject parent;
  GuestfsIsFilePrivate *priv;
};

/**
 * GuestfsIsFileClass:
 * @parent_class: The superclass of GuestfsIsFileClass
 *
 * A class metadata object for GuestfsIsFile.
 */
typedef struct _GuestfsIsFileClass GuestfsIsFileClass;
struct _GuestfsIsFileClass {
  GObjectClass parent_class;
};

GType guestfs_is_file_get_type (void);
GuestfsIsFile *guestfs_is_file_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_IS_FILE_H__ */
