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

#ifndef GUESTFS_GOBJECT_OPTARGS_E2FSCK_H__
#define GUESTFS_GOBJECT_OPTARGS_E2FSCK_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_E2FSCK (guestfs_e2fsck_get_type())
#define GUESTFS_E2FSCK(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_E2FSCK, GuestfsE2fsck))
#define GUESTFS_E2FSCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_E2FSCK, GuestfsE2fsckClass))
#define GUESTFS_IS_E2FSCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_E2FSCK))
#define GUESTFS_IS_E2FSCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_E2FSCK))
#define GUESTFS_E2FSCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_E2FSCK, GuestfsE2fsckClass))

typedef struct _GuestfsE2fsckPrivate GuestfsE2fsckPrivate;

/**
 * GuestfsE2fsck:
 *
 * An object encapsulating optional arguments for guestfs_session_e2fsck.
 */
typedef struct _GuestfsE2fsck GuestfsE2fsck;
struct _GuestfsE2fsck {
  GObject parent;
  GuestfsE2fsckPrivate *priv;
};

/**
 * GuestfsE2fsckClass:
 * @parent_class: The superclass of GuestfsE2fsckClass
 *
 * A class metadata object for GuestfsE2fsck.
 */
typedef struct _GuestfsE2fsckClass GuestfsE2fsckClass;
struct _GuestfsE2fsckClass {
  GObjectClass parent_class;
};

GType guestfs_e2fsck_get_type(void);
GuestfsE2fsck *guestfs_e2fsck_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_E2FSCK_H__ */
