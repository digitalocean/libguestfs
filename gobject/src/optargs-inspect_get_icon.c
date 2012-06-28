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

#include <config.h>

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-inspect_get_icon
 * @short_description: An object encapsulating optional arguments for guestfs_session_inspect_get_icon
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_inspect_get_icon
 */

#include <string.h>

#define GUESTFS_INSPECT_GET_ICON_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_INSPECT_GET_ICON, GuestfsInspectGetIconPrivate))

struct _GuestfsInspectGetIconPrivate {
  GuestfsTristate favicon;
  GuestfsTristate highquality;
};

G_DEFINE_TYPE(GuestfsInspectGetIcon, guestfs_inspect_get_icon, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_INSPECT_GET_ICON_PROP0,
  PROP_GUESTFS_INSPECT_GET_ICON_FAVICON,
  PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY
};

static void
guestfs_inspect_get_icon_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INSPECT_GET_ICON_FAVICON:
      priv->favicon = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      priv->highquality = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_inspect_get_icon_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INSPECT_GET_ICON_FAVICON:
      g_value_set_enum(value, priv->favicon);
      break;

    case PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      g_value_set_enum(value, priv->highquality);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_inspect_get_icon_finalize(GObject *object)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_inspect_get_icon_parent_class)->finalize(object);
}

static void
guestfs_inspect_get_icon_class_init(GuestfsInspectGetIconClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_inspect_get_icon_set_property;
  object_class->get_property = guestfs_inspect_get_icon_get_property;

  /**
   * GuestfsInspectGetIcon:favicon:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INSPECT_GET_ICON_FAVICON,
    g_param_spec_enum(
      "favicon",
      "favicon",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInspectGetIcon:highquality:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY,
    g_param_spec_enum(
      "highquality",
      "highquality",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_inspect_get_icon_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsInspectGetIconPrivate));
}

static void
guestfs_inspect_get_icon_init(GuestfsInspectGetIcon *o)
{
  o->priv = GUESTFS_INSPECT_GET_ICON_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsInspectGetIconPrivate));
}

/**
 * guestfs_inspect_get_icon_new:
 *
 * Create a new GuestfsInspectGetIcon object
 *
 * Returns: (transfer full): a new GuestfsInspectGetIcon object
 */
GuestfsInspectGetIcon *
guestfs_inspect_get_icon_new(void)
{
  return GUESTFS_INSPECT_GET_ICON(g_object_new(GUESTFS_TYPE_INSPECT_GET_ICON, NULL));
}
