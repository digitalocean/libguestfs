/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * SECTION:optargs-fstrim
 * @short_description: An object encapsulating optional arguments for guestfs_session_fstrim
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_fstrim
 */

#include <string.h>

#define GUESTFS_FSTRIM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_FSTRIM, GuestfsFstrimPrivate))

struct _GuestfsFstrimPrivate {
  gint64 offset;
  gint64 length;
  gint64 minimumfreeextent;
};

G_DEFINE_TYPE (GuestfsFstrim, guestfs_fstrim, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_FSTRIM_PROP0,
  PROP_GUESTFS_FSTRIM_OFFSET,
  PROP_GUESTFS_FSTRIM_LENGTH,
  PROP_GUESTFS_FSTRIM_MINIMUMFREEEXTENT
};

static void
guestfs_fstrim_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsFstrim *self = GUESTFS_FSTRIM (object);
  GuestfsFstrimPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_FSTRIM_OFFSET:
      priv->offset = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_FSTRIM_LENGTH:
      priv->length = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_FSTRIM_MINIMUMFREEEXTENT:
      priv->minimumfreeextent = g_value_get_int64 (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_fstrim_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsFstrim *self = GUESTFS_FSTRIM (object);
  GuestfsFstrimPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_FSTRIM_OFFSET:
      g_value_set_int64 (value, priv->offset);
      break;

    case PROP_GUESTFS_FSTRIM_LENGTH:
      g_value_set_int64 (value, priv->length);
      break;

    case PROP_GUESTFS_FSTRIM_MINIMUMFREEEXTENT:
      g_value_set_int64 (value, priv->minimumfreeextent);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_fstrim_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_fstrim_parent_class)->finalize (object);
}

static void
guestfs_fstrim_class_init (GuestfsFstrimClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_fstrim_set_property;
  object_class->get_property = guestfs_fstrim_get_property;

  /**
   * GuestfsFstrim:offset:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_FSTRIM_OFFSET,
    g_param_spec_int64 (
      "offset",
      "offset",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsFstrim:length:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_FSTRIM_LENGTH,
    g_param_spec_int64 (
      "length",
      "length",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsFstrim:minimumfreeextent:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_FSTRIM_MINIMUMFREEEXTENT,
    g_param_spec_int64 (
      "minimumfreeextent",
      "minimumfreeextent",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_fstrim_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsFstrimPrivate));
}

static void
guestfs_fstrim_init (GuestfsFstrim *o)
{
  o->priv = GUESTFS_FSTRIM_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsFstrimPrivate));
}

/**
 * guestfs_fstrim_new:
 *
 * Create a new GuestfsFstrim object
 *
 * Returns: (transfer full): a new GuestfsFstrim object
 */
GuestfsFstrim *
guestfs_fstrim_new (void)
{
  return GUESTFS_FSTRIM (g_object_new (GUESTFS_TYPE_FSTRIM, NULL));
}
