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

#ifndef GUESTFS_GOBJECT_OPTARGS_NTFSCLONE_OUT_H__
#define GUESTFS_GOBJECT_OPTARGS_NTFSCLONE_OUT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_NTFSCLONE_OUT (guestfs_ntfsclone_out_get_type())
#define GUESTFS_NTFSCLONE_OUT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_NTFSCLONE_OUT, GuestfsNtfscloneOut))
#define GUESTFS_NTFSCLONE_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_NTFSCLONE_OUT, GuestfsNtfscloneOutClass))
#define GUESTFS_IS_NTFSCLONE_OUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_NTFSCLONE_OUT))
#define GUESTFS_IS_NTFSCLONE_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_NTFSCLONE_OUT))
#define GUESTFS_NTFSCLONE_OUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_NTFSCLONE_OUT, GuestfsNtfscloneOutClass))

typedef struct _GuestfsNtfscloneOutPrivate GuestfsNtfscloneOutPrivate;

/**
 * GuestfsNtfscloneOut:
 *
 * An object encapsulating optional arguments for guestfs_session_ntfsclone_out.
 */
typedef struct _GuestfsNtfscloneOut GuestfsNtfscloneOut;
struct _GuestfsNtfscloneOut {
  GObject parent;
  GuestfsNtfscloneOutPrivate *priv;
};

/**
 * GuestfsNtfscloneOutClass:
 * @parent_class: The superclass of GuestfsNtfscloneOutClass
 *
 * A class metadata object for GuestfsNtfscloneOut.
 */
typedef struct _GuestfsNtfscloneOutClass GuestfsNtfscloneOutClass;
struct _GuestfsNtfscloneOutClass {
  GObjectClass parent_class;
};

GType guestfs_ntfsclone_out_get_type(void);
GuestfsNtfscloneOut *guestfs_ntfsclone_out_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_NTFSCLONE_OUT_H__ */
