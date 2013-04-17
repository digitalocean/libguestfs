/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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
 * SECTION:optargs-internal_test
 * @short_description: An object encapsulating optional arguments for guestfs_session_internal_test
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_internal_test
 */

#include <string.h>

#define GUESTFS_INTERNAL_TEST_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_INTERNAL_TEST, GuestfsInternalTestPrivate))

struct _GuestfsInternalTestPrivate {
  GuestfsTristate obool;
  gint oint;
  gint64 oint64;
  gchar *ostring;
  /* OStringList not implemented yet */
};

G_DEFINE_TYPE(GuestfsInternalTest, guestfs_internal_test, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_INTERNAL_TEST_PROP0,
  PROP_GUESTFS_INTERNAL_TEST_OBOOL,
  PROP_GUESTFS_INTERNAL_TEST_OINT,
  PROP_GUESTFS_INTERNAL_TEST_OINT64,
  PROP_GUESTFS_INTERNAL_TEST_OSTRING,
  PROP_GUESTFS_INTERNAL_TEST_OSTRINGLIST
};

static void
guestfs_internal_test_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTest *self = GUESTFS_INTERNAL_TEST(object);
  GuestfsInternalTestPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_OBOOL:
      priv->obool = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OINT:
      priv->oint = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OINT64:
      priv->oint64 = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OSTRING:
      g_free(priv->ostring);
      priv->ostring = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_internal_test_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTest *self = GUESTFS_INTERNAL_TEST(object);
  GuestfsInternalTestPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_OBOOL:
      g_value_set_enum(value, priv->obool);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OINT:
      g_value_set_int(value, priv->oint);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OINT64:
      g_value_set_int64(value, priv->oint64);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_OSTRING:
      g_value_set_string(value, priv->ostring);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_internal_test_finalize(GObject *object)
{
  GuestfsInternalTest *self = GUESTFS_INTERNAL_TEST(object);
  GuestfsInternalTestPrivate *priv = self->priv;

  g_free(priv->ostring);

  G_OBJECT_CLASS(guestfs_internal_test_parent_class)->finalize(object);
}

static void
guestfs_internal_test_class_init(GuestfsInternalTestClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_internal_test_set_property;
  object_class->get_property = guestfs_internal_test_get_property;

  /**
   * GuestfsInternalTest:obool:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_OBOOL,
    g_param_spec_enum(
      "obool",
      "obool",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest:oint:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_OINT,
    g_param_spec_int(
      "oint",
      "oint",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest:oint64:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_OINT64,
    g_param_spec_int64(
      "oint64",
      "oint64",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest:ostring:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_OSTRING,
    g_param_spec_string(
      "ostring",
      "ostring",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_internal_test_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsInternalTestPrivate));
}

static void
guestfs_internal_test_init(GuestfsInternalTest *o)
{
  o->priv = GUESTFS_INTERNAL_TEST_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsInternalTestPrivate));
}

/**
 * guestfs_internal_test_new:
 *
 * Create a new GuestfsInternalTest object
 *
 * Returns: (transfer full): a new GuestfsInternalTest object
 */
GuestfsInternalTest *
guestfs_internal_test_new(void)
{
  return GUESTFS_INTERNAL_TEST(g_object_new(GUESTFS_TYPE_INTERNAL_TEST, NULL));
}
