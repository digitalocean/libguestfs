/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_OPTARGS_IS_SOCKET_H__
#define GUESTFS_GOBJECT_OPTARGS_IS_SOCKET_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_IS_SOCKET (guestfs_is_socket_get_type())
#define GUESTFS_IS_SOCKET(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_IS_SOCKET, GuestfsIsSocket))
#define GUESTFS_IS_SOCKET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_IS_SOCKET, GuestfsIsSocketClass))
#define GUESTFS_IS_IS_SOCKET(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_IS_SOCKET))
#define GUESTFS_IS_IS_SOCKET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_IS_SOCKET))
#define GUESTFS_IS_SOCKET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_IS_SOCKET, GuestfsIsSocketClass))

typedef struct _GuestfsIsSocketPrivate GuestfsIsSocketPrivate;

/**
 * GuestfsIsSocket:
 *
 * An object encapsulating optional arguments for guestfs_session_is_socket.
 */
typedef struct _GuestfsIsSocket GuestfsIsSocket;
struct _GuestfsIsSocket {
  GObject parent;
  GuestfsIsSocketPrivate *priv;
};

/**
 * GuestfsIsSocketClass:
 * @parent_class: The superclass of GuestfsIsSocketClass
 *
 * A class metadata object for GuestfsIsSocket.
 */
typedef struct _GuestfsIsSocketClass GuestfsIsSocketClass;
struct _GuestfsIsSocketClass {
  GObjectClass parent_class;
};

GType guestfs_is_socket_get_type(void);
GuestfsIsSocket *guestfs_is_socket_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_IS_SOCKET_H__ */
