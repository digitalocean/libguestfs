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

#ifndef GUESTFS_GOBJECT_OPTARGS_INTERNAL_TEST_H__
#define GUESTFS_GOBJECT_OPTARGS_INTERNAL_TEST_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_INTERNAL_TEST (guestfs_internal_test_get_type())
#define GUESTFS_INTERNAL_TEST(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_INTERNAL_TEST, GuestfsInternalTest))
#define GUESTFS_INTERNAL_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_INTERNAL_TEST, GuestfsInternalTestClass))
#define GUESTFS_IS_INTERNAL_TEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_INTERNAL_TEST))
#define GUESTFS_IS_INTERNAL_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_INTERNAL_TEST))
#define GUESTFS_INTERNAL_TEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_INTERNAL_TEST, GuestfsInternalTestClass))

typedef struct _GuestfsInternalTestPrivate GuestfsInternalTestPrivate;

/**
 * GuestfsInternalTest:
 *
 * An object encapsulating optional arguments for guestfs_session_internal_test.
 */
typedef struct _GuestfsInternalTest GuestfsInternalTest;
struct _GuestfsInternalTest {
  GObject parent;
  GuestfsInternalTestPrivate *priv;
};

/**
 * GuestfsInternalTestClass:
 * @parent_class: The superclass of GuestfsInternalTestClass
 *
 * A class metadata object for GuestfsInternalTest.
 */
typedef struct _GuestfsInternalTestClass GuestfsInternalTestClass;
struct _GuestfsInternalTestClass {
  GObjectClass parent_class;
};

GType guestfs_internal_test_get_type(void);
GuestfsInternalTest *guestfs_internal_test_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_INTERNAL_TEST_H__ */
