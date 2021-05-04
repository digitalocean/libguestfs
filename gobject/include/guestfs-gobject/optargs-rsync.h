/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_OPTARGS_RSYNC_H__
#define GUESTFS_GOBJECT_OPTARGS_RSYNC_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_RSYNC (guestfs_rsync_get_type ())
#define GUESTFS_RSYNC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_RSYNC, GuestfsRsync))
#define GUESTFS_RSYNC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_RSYNC, GuestfsRsyncClass))
#define GUESTFS_IS_RSYNC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_RSYNC))
#define GUESTFS_IS_RSYNC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_RSYNC))
#define GUESTFS_RSYNC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_RSYNC, GuestfsRsyncClass))

typedef struct _GuestfsRsyncPrivate GuestfsRsyncPrivate;

/**
 * GuestfsRsync:
 *
 * An object encapsulating optional arguments for guestfs_session_rsync.
 */
typedef struct _GuestfsRsync GuestfsRsync;
struct _GuestfsRsync {
  GObject parent;
  GuestfsRsyncPrivate *priv;
};

/**
 * GuestfsRsyncClass:
 * @parent_class: The superclass of GuestfsRsyncClass
 *
 * A class metadata object for GuestfsRsync.
 */
typedef struct _GuestfsRsyncClass GuestfsRsyncClass;
struct _GuestfsRsyncClass {
  GObjectClass parent_class;
};

GType guestfs_rsync_get_type (void);
GuestfsRsync *guestfs_rsync_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_RSYNC_H__ */
