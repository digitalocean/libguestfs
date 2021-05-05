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
 * SECTION:optargs-aug_transform
 * @short_description: An object encapsulating optional arguments for guestfs_session_aug_transform
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_aug_transform
 */

#include <string.h>

#define GUESTFS_AUG_TRANSFORM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_AUG_TRANSFORM, GuestfsAugTransformPrivate))

struct _GuestfsAugTransformPrivate {
  GuestfsTristate remove;
};

G_DEFINE_TYPE (GuestfsAugTransform, guestfs_aug_transform, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_AUG_TRANSFORM_PROP0,
  PROP_GUESTFS_AUG_TRANSFORM_REMOVE
};

static void
guestfs_aug_transform_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAugTransform *self = GUESTFS_AUG_TRANSFORM (object);
  GuestfsAugTransformPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_AUG_TRANSFORM_REMOVE:
      priv->remove = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_aug_transform_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAugTransform *self = GUESTFS_AUG_TRANSFORM (object);
  GuestfsAugTransformPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_AUG_TRANSFORM_REMOVE:
      g_value_set_enum (value, priv->remove);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_aug_transform_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_aug_transform_parent_class)->finalize (object);
}

static void
guestfs_aug_transform_class_init (GuestfsAugTransformClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_aug_transform_set_property;
  object_class->get_property = guestfs_aug_transform_get_property;

  /**
   * GuestfsAugTransform:remove:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_AUG_TRANSFORM_REMOVE,
    g_param_spec_enum (
      "remove",
      "remove",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_aug_transform_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsAugTransformPrivate));
}

static void
guestfs_aug_transform_init (GuestfsAugTransform *o)
{
  o->priv = GUESTFS_AUG_TRANSFORM_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsAugTransformPrivate));
}

/**
 * guestfs_aug_transform_new:
 *
 * Create a new GuestfsAugTransform object
 *
 * Returns: (transfer full): a new GuestfsAugTransform object
 */
GuestfsAugTransform *
guestfs_aug_transform_new (void)
{
  return GUESTFS_AUG_TRANSFORM (g_object_new (GUESTFS_TYPE_AUG_TRANSFORM, NULL));
}
