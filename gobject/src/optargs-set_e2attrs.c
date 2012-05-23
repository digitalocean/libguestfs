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

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-set_e2attrs
 * @short_description: An object encapsulating optional arguments for guestfs_session_set_e2attrs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_set_e2attrs
 */

#include <string.h>

#define GUESTFS_SET_E2ATTRS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_SET_E2ATTRS, GuestfsSetE2attrsPrivate))

struct _GuestfsSetE2attrsPrivate {
  GuestfsTristate clear;
};

G_DEFINE_TYPE(GuestfsSetE2attrs, guestfs_set_e2attrs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_SET_E2ATTRS_PROP0,
  PROP_GUESTFS_SET_E2ATTRS_CLEAR
};

static void
guestfs_set_e2attrs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsSetE2attrs *self = GUESTFS_SET_E2ATTRS(object);
  GuestfsSetE2attrsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_SET_E2ATTRS_CLEAR:
      priv->clear = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_set_e2attrs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsSetE2attrs *self = GUESTFS_SET_E2ATTRS(object);
  GuestfsSetE2attrsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_SET_E2ATTRS_CLEAR:
      g_value_set_enum(value, priv->clear);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_set_e2attrs_finalize(GObject *object)
{
  GuestfsSetE2attrs *self = GUESTFS_SET_E2ATTRS(object);
  GuestfsSetE2attrsPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_set_e2attrs_parent_class)->finalize(object);
}

static void
guestfs_set_e2attrs_class_init(GuestfsSetE2attrsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_set_e2attrs_set_property;
  object_class->get_property = guestfs_set_e2attrs_get_property;

  /**
   * GuestfsSetE2attrs:clear:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_SET_E2ATTRS_CLEAR,
    g_param_spec_enum(
      "clear",
      "clear",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_set_e2attrs_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsSetE2attrsPrivate));
}

static void
guestfs_set_e2attrs_init(GuestfsSetE2attrs *o)
{
  o->priv = GUESTFS_SET_E2ATTRS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsSetE2attrsPrivate));
}

/**
 * guestfs_set_e2attrs_new:
 *
 * Create a new GuestfsSetE2attrs object
 *
 * Returns: (transfer full): a new GuestfsSetE2attrs object
 */
GuestfsSetE2attrs *
guestfs_set_e2attrs_new(void)
{
  return GUESTFS_SET_E2ATTRS(g_object_new(GUESTFS_TYPE_SET_E2ATTRS, NULL));
}
