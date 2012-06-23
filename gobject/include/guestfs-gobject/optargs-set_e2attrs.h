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

#ifndef GUESTFS_GOBJECT_OPTARGS_SET_E2ATTRS_H__
#define GUESTFS_GOBJECT_OPTARGS_SET_E2ATTRS_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_SET_E2ATTRS (guestfs_set_e2attrs_get_type())
#define GUESTFS_SET_E2ATTRS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_SET_E2ATTRS, GuestfsSetE2attrs))
#define GUESTFS_SET_E2ATTRS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_SET_E2ATTRS, GuestfsSetE2attrsClass))
#define GUESTFS_IS_SET_E2ATTRS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_SET_E2ATTRS))
#define GUESTFS_IS_SET_E2ATTRS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_SET_E2ATTRS))
#define GUESTFS_SET_E2ATTRS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_SET_E2ATTRS, GuestfsSetE2attrsClass))

typedef struct _GuestfsSetE2attrsPrivate GuestfsSetE2attrsPrivate;

/**
 * GuestfsSetE2attrs:
 *
 * An object encapsulating optional arguments for guestfs_session_set_e2attrs.
 */
typedef struct _GuestfsSetE2attrs GuestfsSetE2attrs;
struct _GuestfsSetE2attrs {
  GObject parent;
  GuestfsSetE2attrsPrivate *priv;
};

/**
 * GuestfsSetE2attrsClass:
 * @parent_class: The superclass of GuestfsSetE2attrsClass
 *
 * A class metadata object for GuestfsSetE2attrs.
 */
typedef struct _GuestfsSetE2attrsClass GuestfsSetE2attrsClass;
struct _GuestfsSetE2attrsClass {
  GObjectClass parent_class;
};

GType guestfs_set_e2attrs_get_type(void);
GuestfsSetE2attrs *guestfs_set_e2attrs_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_SET_E2ATTRS_H__ */
