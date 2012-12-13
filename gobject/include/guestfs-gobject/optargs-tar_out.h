/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
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

#ifndef GUESTFS_GOBJECT_OPTARGS_TAR_OUT_H__
#define GUESTFS_GOBJECT_OPTARGS_TAR_OUT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_TAR_OUT (guestfs_tar_out_get_type())
#define GUESTFS_TAR_OUT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_TAR_OUT, GuestfsTarOut))
#define GUESTFS_TAR_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_TAR_OUT, GuestfsTarOutClass))
#define GUESTFS_IS_TAR_OUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_TAR_OUT))
#define GUESTFS_IS_TAR_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_TAR_OUT))
#define GUESTFS_TAR_OUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_TAR_OUT, GuestfsTarOutClass))

typedef struct _GuestfsTarOutPrivate GuestfsTarOutPrivate;

/**
 * GuestfsTarOut:
 *
 * An object encapsulating optional arguments for guestfs_session_tar_out.
 */
typedef struct _GuestfsTarOut GuestfsTarOut;
struct _GuestfsTarOut {
  GObject parent;
  GuestfsTarOutPrivate *priv;
};

/**
 * GuestfsTarOutClass:
 * @parent_class: The superclass of GuestfsTarOutClass
 *
 * A class metadata object for GuestfsTarOut.
 */
typedef struct _GuestfsTarOutClass GuestfsTarOutClass;
struct _GuestfsTarOutClass {
  GObjectClass parent_class;
};

GType guestfs_tar_out_get_type(void);
GuestfsTarOut *guestfs_tar_out_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_TAR_OUT_H__ */
