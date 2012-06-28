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
 * SECTION:optargs-compress_out
 * @short_description: An object encapsulating optional arguments for guestfs_session_compress_out
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_compress_out
 */

#include <string.h>

#define GUESTFS_COMPRESS_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COMPRESS_OUT, GuestfsCompressOutPrivate))

struct _GuestfsCompressOutPrivate {
  gint level;
};

G_DEFINE_TYPE(GuestfsCompressOut, guestfs_compress_out, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_COMPRESS_OUT_PROP0,
  PROP_GUESTFS_COMPRESS_OUT_LEVEL
};

static void
guestfs_compress_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_OUT_LEVEL:
      priv->level = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_OUT_LEVEL:
      g_value_set_int(value, priv->level);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_out_finalize(GObject *object)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_compress_out_parent_class)->finalize(object);
}

static void
guestfs_compress_out_class_init(GuestfsCompressOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_compress_out_set_property;
  object_class->get_property = guestfs_compress_out_get_property;

  /**
   * GuestfsCompressOut:level:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_COMPRESS_OUT_LEVEL,
    g_param_spec_int(
      "level",
      "level",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_compress_out_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsCompressOutPrivate));
}

static void
guestfs_compress_out_init(GuestfsCompressOut *o)
{
  o->priv = GUESTFS_COMPRESS_OUT_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsCompressOutPrivate));
}

/**
 * guestfs_compress_out_new:
 *
 * Create a new GuestfsCompressOut object
 *
 * Returns: (transfer full): a new GuestfsCompressOut object
 */
GuestfsCompressOut *
guestfs_compress_out_new(void)
{
  return GUESTFS_COMPRESS_OUT(g_object_new(GUESTFS_TYPE_COMPRESS_OUT, NULL));
}
