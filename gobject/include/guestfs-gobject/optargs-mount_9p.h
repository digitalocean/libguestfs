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

#ifndef GUESTFS_GOBJECT_OPTARGS_MOUNT_9P_H__
#define GUESTFS_GOBJECT_OPTARGS_MOUNT_9P_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_MOUNT_9P (guestfs_mount_9p_get_type())
#define GUESTFS_MOUNT_9P(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9P))
#define GUESTFS_MOUNT_9P_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PClass))
#define GUESTFS_IS_MOUNT_9P(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_MOUNT_9P))
#define GUESTFS_IS_MOUNT_9P_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_MOUNT_9P))
#define GUESTFS_MOUNT_9P_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PClass))

typedef struct _GuestfsMount9PPrivate GuestfsMount9PPrivate;

/**
 * GuestfsMount9P:
 *
 * An object encapsulating optional arguments for guestfs_session_mount_9p.
 */
typedef struct _GuestfsMount9P GuestfsMount9P;
struct _GuestfsMount9P {
  GObject parent;
  GuestfsMount9PPrivate *priv;
};

/**
 * GuestfsMount9PClass:
 * @parent_class: The superclass of GuestfsMount9PClass
 *
 * A class metadata object for GuestfsMount9P.
 */
typedef struct _GuestfsMount9PClass GuestfsMount9PClass;
struct _GuestfsMount9PClass {
  GObjectClass parent_class;
};

GType guestfs_mount_9p_get_type(void);
GuestfsMount9P *guestfs_mount_9p_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_MOUNT_9P_H__ */
