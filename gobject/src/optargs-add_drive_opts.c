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
 * SECTION:optargs-add_drive_opts
 * @short_description: An object encapsulating optional arguments for guestfs_session_add_drive_opts
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_add_drive_opts
 */

#include <string.h>

#define GUESTFS_ADD_DRIVE_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DRIVE_OPTS, GuestfsAddDriveOptsPrivate))

struct _GuestfsAddDriveOptsPrivate {
  GuestfsTristate readonly;
  gchar *format;
  gchar *iface;
  gchar *name;
};

G_DEFINE_TYPE(GuestfsAddDriveOpts, guestfs_add_drive_opts, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_ADD_DRIVE_OPTS_PROP0,
  PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY,
  PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT,
  PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE,
  PROP_GUESTFS_ADD_DRIVE_OPTS_NAME
};

static void
guestfs_add_drive_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY:
      priv->readonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      g_free(priv->format);
      priv->format = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE:
      g_free(priv->iface);
      priv->iface = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_NAME:
      g_free(priv->name);
      priv->name = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY:
      g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      g_value_set_string(value, priv->format);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE:
      g_value_set_string(value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_NAME:
      g_value_set_string(value, priv->name);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_opts_finalize(GObject *object)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  g_free(priv->format);
  g_free(priv->iface);
  g_free(priv->name);

  G_OBJECT_CLASS(guestfs_add_drive_opts_parent_class)->finalize(object);
}

static void
guestfs_add_drive_opts_class_init(GuestfsAddDriveOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_add_drive_opts_set_property;
  object_class->get_property = guestfs_add_drive_opts_get_property;

  /**
   * GuestfsAddDriveOpts:readonly:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY,
    g_param_spec_enum(
      "readonly",
      "readonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDriveOpts:format:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT,
    g_param_spec_string(
      "format",
      "format",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDriveOpts:iface:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE,
    g_param_spec_string(
      "iface",
      "iface",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDriveOpts:name:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_OPTS_NAME,
    g_param_spec_string(
      "name",
      "name",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_add_drive_opts_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsAddDriveOptsPrivate));
}

static void
guestfs_add_drive_opts_init(GuestfsAddDriveOpts *o)
{
  o->priv = GUESTFS_ADD_DRIVE_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsAddDriveOptsPrivate));
}

/**
 * guestfs_add_drive_opts_new:
 *
 * Create a new GuestfsAddDriveOpts object
 *
 * Returns: (transfer full): a new GuestfsAddDriveOpts object
 */
GuestfsAddDriveOpts *
guestfs_add_drive_opts_new(void)
{
  return GUESTFS_ADD_DRIVE_OPTS(g_object_new(GUESTFS_TYPE_ADD_DRIVE_OPTS, NULL));
}
