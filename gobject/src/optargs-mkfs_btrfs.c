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
 * SECTION:optargs-mkfs_btrfs
 * @short_description: An object encapsulating optional arguments for guestfs_session_mkfs_btrfs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mkfs_btrfs
 */

#include <string.h>

#define GUESTFS_MKFS_BTRFS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MKFS_BTRFS, GuestfsMkfsBtrfsPrivate))

struct _GuestfsMkfsBtrfsPrivate {
  gint64 allocstart;
  gint64 bytecount;
  gchar *datatype;
  gint leafsize;
  gchar *label;
  gchar *metadata;
  gint nodesize;
  gint sectorsize;
};

G_DEFINE_TYPE(GuestfsMkfsBtrfs, guestfs_mkfs_btrfs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKFS_BTRFS_PROP0,
  PROP_GUESTFS_MKFS_BTRFS_ALLOCSTART,
  PROP_GUESTFS_MKFS_BTRFS_BYTECOUNT,
  PROP_GUESTFS_MKFS_BTRFS_DATATYPE,
  PROP_GUESTFS_MKFS_BTRFS_LEAFSIZE,
  PROP_GUESTFS_MKFS_BTRFS_LABEL,
  PROP_GUESTFS_MKFS_BTRFS_METADATA,
  PROP_GUESTFS_MKFS_BTRFS_NODESIZE,
  PROP_GUESTFS_MKFS_BTRFS_SECTORSIZE
};

static void
guestfs_mkfs_btrfs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsBtrfs *self = GUESTFS_MKFS_BTRFS(object);
  GuestfsMkfsBtrfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_BTRFS_ALLOCSTART:
      priv->allocstart = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_BYTECOUNT:
      priv->bytecount = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_DATATYPE:
      g_free(priv->datatype);
      priv->datatype = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_LEAFSIZE:
      priv->leafsize = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_LABEL:
      g_free(priv->label);
      priv->label = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_METADATA:
      g_free(priv->metadata);
      priv->metadata = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_NODESIZE:
      priv->nodesize = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_SECTORSIZE:
      priv->sectorsize = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_btrfs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsBtrfs *self = GUESTFS_MKFS_BTRFS(object);
  GuestfsMkfsBtrfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_BTRFS_ALLOCSTART:
      g_value_set_int64(value, priv->allocstart);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_BYTECOUNT:
      g_value_set_int64(value, priv->bytecount);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_DATATYPE:
      g_value_set_string(value, priv->datatype);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_LEAFSIZE:
      g_value_set_int(value, priv->leafsize);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_LABEL:
      g_value_set_string(value, priv->label);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_METADATA:
      g_value_set_string(value, priv->metadata);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_NODESIZE:
      g_value_set_int(value, priv->nodesize);
      break;

    case PROP_GUESTFS_MKFS_BTRFS_SECTORSIZE:
      g_value_set_int(value, priv->sectorsize);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_btrfs_finalize(GObject *object)
{
  GuestfsMkfsBtrfs *self = GUESTFS_MKFS_BTRFS(object);
  GuestfsMkfsBtrfsPrivate *priv = self->priv;

  g_free(priv->datatype);
  g_free(priv->label);
  g_free(priv->metadata);

  G_OBJECT_CLASS(guestfs_mkfs_btrfs_parent_class)->finalize(object);
}

static void
guestfs_mkfs_btrfs_class_init(GuestfsMkfsBtrfsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_mkfs_btrfs_set_property;
  object_class->get_property = guestfs_mkfs_btrfs_get_property;

  /**
   * GuestfsMkfsBtrfs:allocstart:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_ALLOCSTART,
    g_param_spec_int64(
      "allocstart",
      "allocstart",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:bytecount:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_BYTECOUNT,
    g_param_spec_int64(
      "bytecount",
      "bytecount",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:datatype:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_DATATYPE,
    g_param_spec_string(
      "datatype",
      "datatype",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:leafsize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_LEAFSIZE,
    g_param_spec_int(
      "leafsize",
      "leafsize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:label:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_LABEL,
    g_param_spec_string(
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:metadata:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_METADATA,
    g_param_spec_string(
      "metadata",
      "metadata",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:nodesize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_NODESIZE,
    g_param_spec_int(
      "nodesize",
      "nodesize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsBtrfs:sectorsize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_BTRFS_SECTORSIZE,
    g_param_spec_int(
      "sectorsize",
      "sectorsize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mkfs_btrfs_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsMkfsBtrfsPrivate));
}

static void
guestfs_mkfs_btrfs_init(GuestfsMkfsBtrfs *o)
{
  o->priv = GUESTFS_MKFS_BTRFS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsMkfsBtrfsPrivate));
}

/**
 * guestfs_mkfs_btrfs_new:
 *
 * Create a new GuestfsMkfsBtrfs object
 *
 * Returns: (transfer full): a new GuestfsMkfsBtrfs object
 */
GuestfsMkfsBtrfs *
guestfs_mkfs_btrfs_new(void)
{
  return GUESTFS_MKFS_BTRFS(g_object_new(GUESTFS_TYPE_MKFS_BTRFS, NULL));
}
