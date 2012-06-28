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
 * SECTION:optargs-mkfs_opts
 * @short_description: An object encapsulating optional arguments for guestfs_session_mkfs_opts
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mkfs_opts
 */

#include <string.h>

#define GUESTFS_MKFS_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MKFS_OPTS, GuestfsMkfsOptsPrivate))

struct _GuestfsMkfsOptsPrivate {
  gint blocksize;
  gchar *features;
  gint inode;
  gint sectorsize;
};

G_DEFINE_TYPE(GuestfsMkfsOpts, guestfs_mkfs_opts, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKFS_OPTS_PROP0,
  PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE,
  PROP_GUESTFS_MKFS_OPTS_FEATURES,
  PROP_GUESTFS_MKFS_OPTS_INODE,
  PROP_GUESTFS_MKFS_OPTS_SECTORSIZE
};

static void
guestfs_mkfs_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE:
      priv->blocksize = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_FEATURES:
      g_free(priv->features);
      priv->features = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_INODE:
      priv->inode = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_SECTORSIZE:
      priv->sectorsize = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE:
      g_value_set_int(value, priv->blocksize);
      break;

    case PROP_GUESTFS_MKFS_OPTS_FEATURES:
      g_value_set_string(value, priv->features);
      break;

    case PROP_GUESTFS_MKFS_OPTS_INODE:
      g_value_set_int(value, priv->inode);
      break;

    case PROP_GUESTFS_MKFS_OPTS_SECTORSIZE:
      g_value_set_int(value, priv->sectorsize);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_opts_finalize(GObject *object)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  g_free(priv->features);

  G_OBJECT_CLASS(guestfs_mkfs_opts_parent_class)->finalize(object);
}

static void
guestfs_mkfs_opts_class_init(GuestfsMkfsOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_mkfs_opts_set_property;
  object_class->get_property = guestfs_mkfs_opts_get_property;

  /**
   * GuestfsMkfsOpts:blocksize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE,
    g_param_spec_int(
      "blocksize",
      "blocksize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsOpts:features:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_OPTS_FEATURES,
    g_param_spec_string(
      "features",
      "features",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsOpts:inode:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_OPTS_INODE,
    g_param_spec_int(
      "inode",
      "inode",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMkfsOpts:sectorsize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MKFS_OPTS_SECTORSIZE,
    g_param_spec_int(
      "sectorsize",
      "sectorsize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mkfs_opts_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsMkfsOptsPrivate));
}

static void
guestfs_mkfs_opts_init(GuestfsMkfsOpts *o)
{
  o->priv = GUESTFS_MKFS_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsMkfsOptsPrivate));
}

/**
 * guestfs_mkfs_opts_new:
 *
 * Create a new GuestfsMkfsOpts object
 *
 * Returns: (transfer full): a new GuestfsMkfsOpts object
 */
GuestfsMkfsOpts *
guestfs_mkfs_opts_new(void)
{
  return GUESTFS_MKFS_OPTS(g_object_new(GUESTFS_TYPE_MKFS_OPTS, NULL));
}
