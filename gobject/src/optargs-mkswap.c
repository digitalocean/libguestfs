/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
 * SECTION:optargs-mkswap
 * @short_description: An object encapsulating optional arguments for guestfs_session_mkswap
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mkswap
 */

#include <string.h>

#define GUESTFS_MKSWAP_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_MKSWAP, GuestfsMkswapPrivate))

struct _GuestfsMkswapPrivate {
  gchar *label;
  gchar *uuid;
};

G_DEFINE_TYPE (GuestfsMkswap, guestfs_mkswap, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKSWAP_PROP0,
  PROP_GUESTFS_MKSWAP_LABEL,
  PROP_GUESTFS_MKSWAP_UUID
};

static void
guestfs_mkswap_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMkswap *self = GUESTFS_MKSWAP (object);
  GuestfsMkswapPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKSWAP_LABEL:
      g_free (priv->label);
      priv->label = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKSWAP_UUID:
      g_free (priv->uuid);
      priv->uuid = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mkswap_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMkswap *self = GUESTFS_MKSWAP (object);
  GuestfsMkswapPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKSWAP_LABEL:
      g_value_set_string (value, priv->label);
      break;

    case PROP_GUESTFS_MKSWAP_UUID:
      g_value_set_string (value, priv->uuid);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mkswap_finalize (GObject *object)
{
  GuestfsMkswap *self = GUESTFS_MKSWAP (object);
  GuestfsMkswapPrivate *priv = self->priv;

  g_free (priv->label);
  g_free (priv->uuid);
  G_OBJECT_CLASS (guestfs_mkswap_parent_class)->finalize (object);
}

static void
guestfs_mkswap_class_init (GuestfsMkswapClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_mkswap_set_property;
  object_class->get_property = guestfs_mkswap_get_property;

  /**
   * GuestfsMkswap:label:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKSWAP_LABEL,
    g_param_spec_string (
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkswap:uuid:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKSWAP_UUID,
    g_param_spec_string (
      "uuid",
      "uuid",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mkswap_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsMkswapPrivate));
}

static void
guestfs_mkswap_init (GuestfsMkswap *o)
{
  o->priv = GUESTFS_MKSWAP_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsMkswapPrivate));
}

/**
 * guestfs_mkswap_new:
 *
 * Create a new GuestfsMkswap object
 *
 * Returns: (transfer full): a new GuestfsMkswap object
 */
GuestfsMkswap *
guestfs_mkswap_new (void)
{
  return GUESTFS_MKSWAP (g_object_new (GUESTFS_TYPE_MKSWAP, NULL));
}
