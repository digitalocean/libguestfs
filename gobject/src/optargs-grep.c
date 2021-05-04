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

#include <config.h>

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-grep
 * @short_description: An object encapsulating optional arguments for guestfs_session_grep
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_grep
 */

#include <string.h>

#define GUESTFS_GREP_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_GREP, GuestfsGrepPrivate))

struct _GuestfsGrepPrivate {
  GuestfsTristate extended;
  GuestfsTristate fixed;
  GuestfsTristate insensitive;
  GuestfsTristate compressed;
};

G_DEFINE_TYPE (GuestfsGrep, guestfs_grep, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_GREP_PROP0,
  PROP_GUESTFS_GREP_EXTENDED,
  PROP_GUESTFS_GREP_FIXED,
  PROP_GUESTFS_GREP_INSENSITIVE,
  PROP_GUESTFS_GREP_COMPRESSED
};

static void
guestfs_grep_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsGrep *self = GUESTFS_GREP (object);
  GuestfsGrepPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_GREP_EXTENDED:
      priv->extended = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_GREP_FIXED:
      priv->fixed = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_GREP_INSENSITIVE:
      priv->insensitive = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_GREP_COMPRESSED:
      priv->compressed = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_grep_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsGrep *self = GUESTFS_GREP (object);
  GuestfsGrepPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_GREP_EXTENDED:
      g_value_set_enum (value, priv->extended);
      break;

    case PROP_GUESTFS_GREP_FIXED:
      g_value_set_enum (value, priv->fixed);
      break;

    case PROP_GUESTFS_GREP_INSENSITIVE:
      g_value_set_enum (value, priv->insensitive);
      break;

    case PROP_GUESTFS_GREP_COMPRESSED:
      g_value_set_enum (value, priv->compressed);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_grep_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_grep_parent_class)->finalize (object);
}

static void
guestfs_grep_class_init (GuestfsGrepClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_grep_set_property;
  object_class->get_property = guestfs_grep_get_property;

  /**
   * GuestfsGrep:extended:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_GREP_EXTENDED,
    g_param_spec_enum (
      "extended",
      "extended",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsGrep:fixed:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_GREP_FIXED,
    g_param_spec_enum (
      "fixed",
      "fixed",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsGrep:insensitive:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_GREP_INSENSITIVE,
    g_param_spec_enum (
      "insensitive",
      "insensitive",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsGrep:compressed:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_GREP_COMPRESSED,
    g_param_spec_enum (
      "compressed",
      "compressed",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_grep_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsGrepPrivate));
}

static void
guestfs_grep_init (GuestfsGrep *o)
{
  o->priv = GUESTFS_GREP_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsGrepPrivate));
}

/**
 * guestfs_grep_new:
 *
 * Create a new GuestfsGrep object
 *
 * Returns: (transfer full): a new GuestfsGrep object
 */
GuestfsGrep *
guestfs_grep_new (void)
{
  return GUESTFS_GREP (g_object_new (GUESTFS_TYPE_GREP, NULL));
}
