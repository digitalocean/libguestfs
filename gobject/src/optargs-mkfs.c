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
 * SECTION:optargs-mkfs
 * @short_description: An object encapsulating optional arguments for guestfs_session_mkfs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mkfs
 */

#include <string.h>

#define GUESTFS_MKFS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_MKFS, GuestfsMkfsPrivate))

struct _GuestfsMkfsPrivate {
  gint blocksize;
  gchar *features;
  gint inode;
  gint sectorsize;
  gchar *label;
};

G_DEFINE_TYPE (GuestfsMkfs, guestfs_mkfs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKFS_PROP0,
  PROP_GUESTFS_MKFS_BLOCKSIZE,
  PROP_GUESTFS_MKFS_FEATURES,
  PROP_GUESTFS_MKFS_INODE,
  PROP_GUESTFS_MKFS_SECTORSIZE,
  PROP_GUESTFS_MKFS_LABEL
};

static void
guestfs_mkfs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMkfs *self = GUESTFS_MKFS (object);
  GuestfsMkfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_BLOCKSIZE:
      priv->blocksize = g_value_get_int (value);
      break;

    case PROP_GUESTFS_MKFS_FEATURES:
      g_free (priv->features);
      priv->features = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKFS_INODE:
      priv->inode = g_value_get_int (value);
      break;

    case PROP_GUESTFS_MKFS_SECTORSIZE:
      priv->sectorsize = g_value_get_int (value);
      break;

    case PROP_GUESTFS_MKFS_LABEL:
      g_free (priv->label);
      priv->label = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mkfs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMkfs *self = GUESTFS_MKFS (object);
  GuestfsMkfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_BLOCKSIZE:
      g_value_set_int (value, priv->blocksize);
      break;

    case PROP_GUESTFS_MKFS_FEATURES:
      g_value_set_string (value, priv->features);
      break;

    case PROP_GUESTFS_MKFS_INODE:
      g_value_set_int (value, priv->inode);
      break;

    case PROP_GUESTFS_MKFS_SECTORSIZE:
      g_value_set_int (value, priv->sectorsize);
      break;

    case PROP_GUESTFS_MKFS_LABEL:
      g_value_set_string (value, priv->label);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mkfs_finalize (GObject *object)
{
  GuestfsMkfs *self = GUESTFS_MKFS (object);
  GuestfsMkfsPrivate *priv = self->priv;

  g_free (priv->features);
  g_free (priv->label);
  G_OBJECT_CLASS (guestfs_mkfs_parent_class)->finalize (object);
}

static void
guestfs_mkfs_class_init (GuestfsMkfsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_mkfs_set_property;
  object_class->get_property = guestfs_mkfs_get_property;

  /**
   * GuestfsMkfs:blocksize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKFS_BLOCKSIZE,
    g_param_spec_int (
      "blocksize",
      "blocksize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfs:features:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKFS_FEATURES,
    g_param_spec_string (
      "features",
      "features",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfs:inode:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKFS_INODE,
    g_param_spec_int (
      "inode",
      "inode",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfs:sectorsize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKFS_SECTORSIZE,
    g_param_spec_int (
      "sectorsize",
      "sectorsize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfs:label:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKFS_LABEL,
    g_param_spec_string (
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mkfs_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsMkfsPrivate));
}

static void
guestfs_mkfs_init (GuestfsMkfs *o)
{
  o->priv = GUESTFS_MKFS_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsMkfsPrivate));
}

/**
 * guestfs_mkfs_new:
 *
 * Create a new GuestfsMkfs object
 *
 * Returns: (transfer full): a new GuestfsMkfs object
 */
GuestfsMkfs *
guestfs_mkfs_new (void)
{
  return GUESTFS_MKFS (g_object_new (GUESTFS_TYPE_MKFS, NULL));
}
