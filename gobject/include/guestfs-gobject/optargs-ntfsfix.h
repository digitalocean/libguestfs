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

#ifndef GUESTFS_GOBJECT_OPTARGS_NTFSFIX_H__
#define GUESTFS_GOBJECT_OPTARGS_NTFSFIX_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_NTFSFIX (guestfs_ntfsfix_get_type())
#define GUESTFS_NTFSFIX(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_NTFSFIX, GuestfsNtfsfix))
#define GUESTFS_NTFSFIX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_NTFSFIX, GuestfsNtfsfixClass))
#define GUESTFS_IS_NTFSFIX(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_NTFSFIX))
#define GUESTFS_IS_NTFSFIX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_NTFSFIX))
#define GUESTFS_NTFSFIX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_NTFSFIX, GuestfsNtfsfixClass))

typedef struct _GuestfsNtfsfixPrivate GuestfsNtfsfixPrivate;

/**
 * GuestfsNtfsfix:
 *
 * An object encapsulating optional arguments for guestfs_session_ntfsfix.
 */
typedef struct _GuestfsNtfsfix GuestfsNtfsfix;
struct _GuestfsNtfsfix {
  GObject parent;
  GuestfsNtfsfixPrivate *priv;
};

/**
 * GuestfsNtfsfixClass:
 * @parent_class: The superclass of GuestfsNtfsfixClass
 *
 * A class metadata object for GuestfsNtfsfix.
 */
typedef struct _GuestfsNtfsfixClass GuestfsNtfsfixClass;
struct _GuestfsNtfsfixClass {
  GObjectClass parent_class;
};

GType guestfs_ntfsfix_get_type(void);
GuestfsNtfsfix *guestfs_ntfsfix_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_NTFSFIX_H__ */
