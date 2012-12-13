/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
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
 * SECTION:optargs-add_drive
 * @short_description: An object encapsulating optional arguments for guestfs_session_add_drive
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_add_drive
 */

#include <string.h>

#define GUESTFS_ADD_DRIVE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DRIVE, GuestfsAddDrivePrivate))

struct _GuestfsAddDrivePrivate {
  GuestfsTristate readonly;
  gchar *format;
  gchar *iface;
  gchar *name;
  gchar *label;
};

G_DEFINE_TYPE(GuestfsAddDrive, guestfs_add_drive, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_ADD_DRIVE_PROP0,
  PROP_GUESTFS_ADD_DRIVE_READONLY,
  PROP_GUESTFS_ADD_DRIVE_FORMAT,
  PROP_GUESTFS_ADD_DRIVE_IFACE,
  PROP_GUESTFS_ADD_DRIVE_NAME,
  PROP_GUESTFS_ADD_DRIVE_LABEL
};

static void
guestfs_add_drive_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDrive *self = GUESTFS_ADD_DRIVE(object);
  GuestfsAddDrivePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_READONLY:
      priv->readonly = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_FORMAT:
      g_free(priv->format);
      priv->format = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_IFACE:
      g_free(priv->iface);
      priv->iface = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_NAME:
      g_free(priv->name);
      priv->name = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_LABEL:
      g_free(priv->label);
      priv->label = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDrive *self = GUESTFS_ADD_DRIVE(object);
  GuestfsAddDrivePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_READONLY:
      g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_DRIVE_FORMAT:
      g_value_set_string(value, priv->format);
      break;

    case PROP_GUESTFS_ADD_DRIVE_IFACE:
      g_value_set_string(value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_DRIVE_NAME:
      g_value_set_string(value, priv->name);
      break;

    case PROP_GUESTFS_ADD_DRIVE_LABEL:
      g_value_set_string(value, priv->label);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_finalize(GObject *object)
{
  GuestfsAddDrive *self = GUESTFS_ADD_DRIVE(object);
  GuestfsAddDrivePrivate *priv = self->priv;

  g_free(priv->format);
  g_free(priv->iface);
  g_free(priv->name);
  g_free(priv->label);

  G_OBJECT_CLASS(guestfs_add_drive_parent_class)->finalize(object);
}

static void
guestfs_add_drive_class_init(GuestfsAddDriveClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_add_drive_set_property;
  object_class->get_property = guestfs_add_drive_get_property;

  /**
   * GuestfsAddDrive:readonly:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_READONLY,
    g_param_spec_enum(
      "readonly",
      "readonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDrive:format:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_FORMAT,
    g_param_spec_string(
      "format",
      "format",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDrive:iface:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_IFACE,
    g_param_spec_string(
      "iface",
      "iface",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDrive:name:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_NAME,
    g_param_spec_string(
      "name",
      "name",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDrive:label:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_LABEL,
    g_param_spec_string(
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_add_drive_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsAddDrivePrivate));
}

static void
guestfs_add_drive_init(GuestfsAddDrive *o)
{
  o->priv = GUESTFS_ADD_DRIVE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsAddDrivePrivate));
}

/**
 * guestfs_add_drive_new:
 *
 * Create a new GuestfsAddDrive object
 *
 * Returns: (transfer full): a new GuestfsAddDrive object
 */
GuestfsAddDrive *
guestfs_add_drive_new(void)
{
  return GUESTFS_ADD_DRIVE(g_object_new(GUESTFS_TYPE_ADD_DRIVE, NULL));
}
