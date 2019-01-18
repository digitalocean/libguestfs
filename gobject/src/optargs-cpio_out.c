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
 * SECTION:optargs-cpio_out
 * @short_description: An object encapsulating optional arguments for guestfs_session_cpio_out
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_cpio_out
 */

#include <string.h>

#define GUESTFS_CPIO_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_CPIO_OUT, GuestfsCpioOutPrivate))

struct _GuestfsCpioOutPrivate {
  gchar *format;
};

G_DEFINE_TYPE (GuestfsCpioOut, guestfs_cpio_out, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_CPIO_OUT_PROP0,
  PROP_GUESTFS_CPIO_OUT_FORMAT
};

static void
guestfs_cpio_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCpioOut *self = GUESTFS_CPIO_OUT (object);
  GuestfsCpioOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_CPIO_OUT_FORMAT:
      g_free (priv->format);
      priv->format = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_cpio_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCpioOut *self = GUESTFS_CPIO_OUT (object);
  GuestfsCpioOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_CPIO_OUT_FORMAT:
      g_value_set_string (value, priv->format);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_cpio_out_finalize (GObject *object)
{
  GuestfsCpioOut *self = GUESTFS_CPIO_OUT (object);
  GuestfsCpioOutPrivate *priv = self->priv;

  g_free (priv->format);
  G_OBJECT_CLASS (guestfs_cpio_out_parent_class)->finalize (object);
}

static void
guestfs_cpio_out_class_init (GuestfsCpioOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_cpio_out_set_property;
  object_class->get_property = guestfs_cpio_out_get_property;

  /**
   * GuestfsCpioOut:format:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_CPIO_OUT_FORMAT,
    g_param_spec_string (
      "format",
      "format",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_cpio_out_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsCpioOutPrivate));
}

static void
guestfs_cpio_out_init (GuestfsCpioOut *o)
{
  o->priv = GUESTFS_CPIO_OUT_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsCpioOutPrivate));
}

/**
 * guestfs_cpio_out_new:
 *
 * Create a new GuestfsCpioOut object
 *
 * Returns: (transfer full): a new GuestfsCpioOut object
 */
GuestfsCpioOut *
guestfs_cpio_out_new (void)
{
  return GUESTFS_CPIO_OUT (g_object_new (GUESTFS_TYPE_CPIO_OUT, NULL));
}
