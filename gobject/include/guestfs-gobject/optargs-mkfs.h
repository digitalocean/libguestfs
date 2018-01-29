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

#ifndef GUESTFS_GOBJECT_OPTARGS_MKFS_H__
#define GUESTFS_GOBJECT_OPTARGS_MKFS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_MKFS (guestfs_mkfs_get_type ())
#define GUESTFS_MKFS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_MKFS, GuestfsMkfs))
#define GUESTFS_MKFS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_MKFS, GuestfsMkfsClass))
#define GUESTFS_IS_MKFS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_MKFS))
#define GUESTFS_IS_MKFS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_MKFS))
#define GUESTFS_MKFS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_MKFS, GuestfsMkfsClass))

typedef struct _GuestfsMkfsPrivate GuestfsMkfsPrivate;

/**
 * GuestfsMkfs:
 *
 * An object encapsulating optional arguments for guestfs_session_mkfs.
 */
typedef struct _GuestfsMkfs GuestfsMkfs;
struct _GuestfsMkfs {
  GObject parent;
  GuestfsMkfsPrivate *priv;
};

/**
 * GuestfsMkfsClass:
 * @parent_class: The superclass of GuestfsMkfsClass
 *
 * A class metadata object for GuestfsMkfs.
 */
typedef struct _GuestfsMkfsClass GuestfsMkfsClass;
struct _GuestfsMkfsClass {
  GObjectClass parent_class;
};

GType guestfs_mkfs_get_type (void);
GuestfsMkfs *guestfs_mkfs_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_MKFS_H__ */
