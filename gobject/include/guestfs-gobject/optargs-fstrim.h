/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
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

#ifndef GUESTFS_GOBJECT_OPTARGS_FSTRIM_H__
#define GUESTFS_GOBJECT_OPTARGS_FSTRIM_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_FSTRIM (guestfs_fstrim_get_type ())
#define GUESTFS_FSTRIM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_FSTRIM, GuestfsFstrim))
#define GUESTFS_FSTRIM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_FSTRIM, GuestfsFstrimClass))
#define GUESTFS_IS_FSTRIM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_FSTRIM))
#define GUESTFS_IS_FSTRIM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_FSTRIM))
#define GUESTFS_FSTRIM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_FSTRIM, GuestfsFstrimClass))

typedef struct _GuestfsFstrimPrivate GuestfsFstrimPrivate;

/**
 * GuestfsFstrim:
 *
 * An object encapsulating optional arguments for guestfs_session_fstrim.
 */
typedef struct _GuestfsFstrim GuestfsFstrim;
struct _GuestfsFstrim {
  GObject parent;
  GuestfsFstrimPrivate *priv;
};

/**
 * GuestfsFstrimClass:
 * @parent_class: The superclass of GuestfsFstrimClass
 *
 * A class metadata object for GuestfsFstrim.
 */
typedef struct _GuestfsFstrimClass GuestfsFstrimClass;
struct _GuestfsFstrimClass {
  GObjectClass parent_class;
};

GType guestfs_fstrim_get_type (void);
GuestfsFstrim *guestfs_fstrim_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_FSTRIM_H__ */
