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

#ifndef GUESTFS_GOBJECT_OPTARGS_NTFSRESIZE_OPTS_H__
#define GUESTFS_GOBJECT_OPTARGS_NTFSRESIZE_OPTS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_NTFSRESIZE_OPTS (guestfs_ntfsresize_opts_get_type())
#define GUESTFS_NTFSRESIZE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOpts))
#define GUESTFS_NTFSRESIZE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsClass))
#define GUESTFS_IS_NTFSRESIZE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS))
#define GUESTFS_IS_NTFSRESIZE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS))
#define GUESTFS_NTFSRESIZE_OPTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsClass))

typedef struct _GuestfsNTFSResizeOptsPrivate GuestfsNTFSResizeOptsPrivate;

/**
 * GuestfsNTFSResizeOpts:
 *
 * An object encapsulating optional arguments for guestfs_session_ntfsresize_opts.
 */
typedef struct _GuestfsNTFSResizeOpts GuestfsNTFSResizeOpts;
struct _GuestfsNTFSResizeOpts {
  GObject parent;
  GuestfsNTFSResizeOptsPrivate *priv;
};

/**
 * GuestfsNTFSResizeOptsClass:
 * @parent_class: The superclass of GuestfsNTFSResizeOptsClass
 *
 * A class metadata object for GuestfsNTFSResizeOpts.
 */
typedef struct _GuestfsNTFSResizeOptsClass GuestfsNTFSResizeOptsClass;
struct _GuestfsNTFSResizeOptsClass {
  GObjectClass parent_class;
};

GType guestfs_ntfsresize_opts_get_type(void);
GuestfsNTFSResizeOpts *guestfs_ntfsresize_opts_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_NTFSRESIZE_OPTS_H__ */
