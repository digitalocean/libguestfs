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

#include <config.h>

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-internal_test_only_optargs
 * @short_description: An object encapsulating optional arguments for guestfs_session_internal_test_only_optargs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_internal_test_only_optargs
 */

#include <string.h>

#define GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_INTERNAL_TEST_ONLY_OPTARGS, GuestfsInternalTestOnlyOptargsPrivate))

struct _GuestfsInternalTestOnlyOptargsPrivate {
  gint test;
};

G_DEFINE_TYPE(GuestfsInternalTestOnlyOptargs, guestfs_internal_test_only_optargs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_PROP0,
  PROP_GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST
};

static void
guestfs_internal_test_only_optargs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTestOnlyOptargs *self = GUESTFS_INTERNAL_TEST_ONLY_OPTARGS(object);
  GuestfsInternalTestOnlyOptargsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST:
      priv->test = g_value_get_int (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_internal_test_only_optargs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTestOnlyOptargs *self = GUESTFS_INTERNAL_TEST_ONLY_OPTARGS(object);
  GuestfsInternalTestOnlyOptargsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST:
      g_value_set_int(value, priv->test);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_internal_test_only_optargs_finalize(GObject *object)
{
  GuestfsInternalTestOnlyOptargs *self = GUESTFS_INTERNAL_TEST_ONLY_OPTARGS(object);
  GuestfsInternalTestOnlyOptargsPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_internal_test_only_optargs_parent_class)->finalize(object);
}

static void
guestfs_internal_test_only_optargs_class_init(GuestfsInternalTestOnlyOptargsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_internal_test_only_optargs_set_property;
  object_class->get_property = guestfs_internal_test_only_optargs_get_property;

  /**
   * GuestfsInternalTestOnlyOptargs:test:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST,
    g_param_spec_int(
      "test",
      "test",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_internal_test_only_optargs_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsInternalTestOnlyOptargsPrivate));
}

static void
guestfs_internal_test_only_optargs_init(GuestfsInternalTestOnlyOptargs *o)
{
  o->priv = GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsInternalTestOnlyOptargsPrivate));
}

/**
 * guestfs_internal_test_only_optargs_new:
 *
 * Create a new GuestfsInternalTestOnlyOptargs object
 *
 * Returns: (transfer full): a new GuestfsInternalTestOnlyOptargs object
 */
GuestfsInternalTestOnlyOptargs *
guestfs_internal_test_only_optargs_new(void)
{
  return GUESTFS_INTERNAL_TEST_ONLY_OPTARGS(g_object_new(GUESTFS_TYPE_INTERNAL_TEST_ONLY_OPTARGS, NULL));
}
