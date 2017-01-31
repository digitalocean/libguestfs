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
 * SECTION:optargs-copy_device_to_file
 * @short_description: An object encapsulating optional arguments for guestfs_session_copy_device_to_file
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_copy_device_to_file
 */

#include <string.h>

#define GUESTFS_COPY_DEVICE_TO_FILE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_COPY_DEVICE_TO_FILE, GuestfsCopyDeviceToFilePrivate))

struct _GuestfsCopyDeviceToFilePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
  GuestfsTristate sparse;
  GuestfsTristate append;
};

G_DEFINE_TYPE (GuestfsCopyDeviceToFile, guestfs_copy_device_to_file, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_PROP0,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_SPARSE,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_APPEND
};

static void
guestfs_copy_device_to_file_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToFile *self = GUESTFS_COPY_DEVICE_TO_FILE (object);
  GuestfsCopyDeviceToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      priv->destoffset = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      priv->size = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SPARSE:
      priv->sparse = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_APPEND:
      priv->append = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_file_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToFile *self = GUESTFS_COPY_DEVICE_TO_FILE (object);
  GuestfsCopyDeviceToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      g_value_set_int64 (value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      g_value_set_int64 (value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      g_value_set_int64 (value, priv->size);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SPARSE:
      g_value_set_enum (value, priv->sparse);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_APPEND:
      g_value_set_enum (value, priv->append);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_file_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_copy_device_to_file_parent_class)->finalize (object);
}

static void
guestfs_copy_device_to_file_class_init (GuestfsCopyDeviceToFileClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_copy_device_to_file_set_property;
  object_class->get_property = guestfs_copy_device_to_file_get_property;

  /**
   * GuestfsCopyDeviceToFile:srcoffset:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET,
    g_param_spec_int64 (
      "srcoffset",
      "srcoffset",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToFile:destoffset:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET,
    g_param_spec_int64 (
      "destoffset",
      "destoffset",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToFile:size:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE,
    g_param_spec_int64 (
      "size",
      "size",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToFile:sparse:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_FILE_SPARSE,
    g_param_spec_enum (
      "sparse",
      "sparse",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsCopyDeviceToFile:append:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_COPY_DEVICE_TO_FILE_APPEND,
    g_param_spec_enum (
      "append",
      "append",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_copy_device_to_file_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsCopyDeviceToFilePrivate));
}

static void
guestfs_copy_device_to_file_init (GuestfsCopyDeviceToFile *o)
{
  o->priv = GUESTFS_COPY_DEVICE_TO_FILE_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsCopyDeviceToFilePrivate));
}

/**
 * guestfs_copy_device_to_file_new:
 *
 * Create a new GuestfsCopyDeviceToFile object
 *
 * Returns: (transfer full): a new GuestfsCopyDeviceToFile object
 */
GuestfsCopyDeviceToFile *
guestfs_copy_device_to_file_new (void)
{
  return GUESTFS_COPY_DEVICE_TO_FILE (g_object_new (GUESTFS_TYPE_COPY_DEVICE_TO_FILE, NULL));
}
