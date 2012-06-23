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
 * SECTION:optargs-copy_device_to_device
 * @short_description: An object encapsulating optional arguments for guestfs_session_copy_device_to_device
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_copy_device_to_device
 */

#include <string.h>

#define GUESTFS_COPY_DEVICE_TO_DEVICE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDevicePrivate))

struct _GuestfsCopyDeviceToDevicePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
};

G_DEFINE_TYPE(GuestfsCopyDeviceToDevice, guestfs_copy_device_to_device, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_PROP0,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE
};

static void
guestfs_copy_device_to_device_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      priv->destoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_device_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      g_value_set_int64(value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      g_value_set_int64(value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_device_finalize(GObject *object)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_copy_device_to_device_parent_class)->finalize(object);
}

static void
guestfs_copy_device_to_device_class_init(GuestfsCopyDeviceToDeviceClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_copy_device_to_device_set_property;
  object_class->get_property = guestfs_copy_device_to_device_get_property;

  /**
   * GuestfsCopyDeviceToDevice:srcoffset:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET,
    g_param_spec_int64(
      "srcoffset",
      "srcoffset",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToDevice:destoffset:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET,
    g_param_spec_int64(
      "destoffset",
      "destoffset",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToDevice:size:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE,
    g_param_spec_int64(
      "size",
      "size",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_copy_device_to_device_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsCopyDeviceToDevicePrivate));
}

static void
guestfs_copy_device_to_device_init(GuestfsCopyDeviceToDevice *o)
{
  o->priv = GUESTFS_COPY_DEVICE_TO_DEVICE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsCopyDeviceToDevicePrivate));
}

/**
 * guestfs_copy_device_to_device_new:
 *
 * Create a new GuestfsCopyDeviceToDevice object
 *
 * Returns: (transfer full): a new GuestfsCopyDeviceToDevice object
 */
GuestfsCopyDeviceToDevice *
guestfs_copy_device_to_device_new(void)
{
  return GUESTFS_COPY_DEVICE_TO_DEVICE(g_object_new(GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, NULL));
}
