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
 * SECTION:optargs-copy_attributes
 * @short_description: An object encapsulating optional arguments for guestfs_session_copy_attributes
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_copy_attributes
 */

#include <string.h>

#define GUESTFS_COPY_ATTRIBUTES_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_COPY_ATTRIBUTES, GuestfsCopyAttributesPrivate))

struct _GuestfsCopyAttributesPrivate {
  GuestfsTristate all;
  GuestfsTristate mode;
  GuestfsTristate xattributes;
  GuestfsTristate ownership;
};

G_DEFINE_TYPE (GuestfsCopyAttributes, guestfs_copy_attributes, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_COPY_ATTRIBUTES_PROP0,
  PROP_GUESTFS_COPY_ATTRIBUTES_ALL,
  PROP_GUESTFS_COPY_ATTRIBUTES_MODE,
  PROP_GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES,
  PROP_GUESTFS_COPY_ATTRIBUTES_OWNERSHIP
};

static void
guestfs_copy_attributes_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyAttributes *self = GUESTFS_COPY_ATTRIBUTES (object);
  GuestfsCopyAttributesPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_ATTRIBUTES_ALL:
      priv->all = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_MODE:
      priv->mode = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES:
      priv->xattributes = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_OWNERSHIP:
      priv->ownership = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_copy_attributes_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyAttributes *self = GUESTFS_COPY_ATTRIBUTES (object);
  GuestfsCopyAttributesPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_ATTRIBUTES_ALL:
      g_value_set_enum (value, priv->all);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_MODE:
      g_value_set_enum (value, priv->mode);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES:
      g_value_set_enum (value, priv->xattributes);
      break;

    case PROP_GUESTFS_COPY_ATTRIBUTES_OWNERSHIP:
      g_value_set_enum (value, priv->ownership);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_copy_attributes_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_copy_attributes_parent_class)->finalize (object);
}

static void
guestfs_copy_attributes_class_init (GuestfsCopyAttributesClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_copy_attributes_set_property;
  object_class->get_property = guestfs_copy_attributes_get_property;

  /**
   * GuestfsCopyAttributes:all:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_ATTRIBUTES_ALL,
    g_param_spec_enum (
      "all",
      "all",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyAttributes:mode:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_ATTRIBUTES_MODE,
    g_param_spec_enum (
      "mode",
      "mode",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyAttributes:xattributes:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES,
    g_param_spec_enum (
      "xattributes",
      "xattributes",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyAttributes:ownership:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_ATTRIBUTES_OWNERSHIP,
    g_param_spec_enum (
      "ownership",
      "ownership",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_copy_attributes_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsCopyAttributesPrivate));
}

static void
guestfs_copy_attributes_init (GuestfsCopyAttributes *o)
{
  o->priv = GUESTFS_COPY_ATTRIBUTES_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsCopyAttributesPrivate));
}

/**
 * guestfs_copy_attributes_new:
 *
 * Create a new GuestfsCopyAttributes object
 *
 * Returns: (transfer full): a new GuestfsCopyAttributes object
 */
GuestfsCopyAttributes *
guestfs_copy_attributes_new (void)
{
  return GUESTFS_COPY_ATTRIBUTES (g_object_new (GUESTFS_TYPE_COPY_ATTRIBUTES, NULL));
}
