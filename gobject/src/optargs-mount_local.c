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
 * SECTION:optargs-mount_local
 * @short_description: An object encapsulating optional arguments for guestfs_session_mount_local
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mount_local
 */

#include <string.h>

#define GUESTFS_MOUNT_LOCAL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MOUNT_LOCAL, GuestfsMountLocalPrivate))

struct _GuestfsMountLocalPrivate {
  GuestfsTristate readonly;
  gchar *options;
  gint cachetimeout;
  GuestfsTristate debugcalls;
};

G_DEFINE_TYPE(GuestfsMountLocal, guestfs_mount_local, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MOUNT_LOCAL_PROP0,
  PROP_GUESTFS_MOUNT_LOCAL_READONLY,
  PROP_GUESTFS_MOUNT_LOCAL_OPTIONS,
  PROP_GUESTFS_MOUNT_LOCAL_CACHETIMEOUT,
  PROP_GUESTFS_MOUNT_LOCAL_DEBUGCALLS
};

static void
guestfs_mount_local_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMountLocal *self = GUESTFS_MOUNT_LOCAL(object);
  GuestfsMountLocalPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_LOCAL_READONLY:
      priv->readonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_OPTIONS:
      g_free(priv->options);
      priv->options = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_CACHETIMEOUT:
      priv->cachetimeout = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_DEBUGCALLS:
      priv->debugcalls = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_local_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMountLocal *self = GUESTFS_MOUNT_LOCAL(object);
  GuestfsMountLocalPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_LOCAL_READONLY:
      g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_OPTIONS:
      g_value_set_string(value, priv->options);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_CACHETIMEOUT:
      g_value_set_int(value, priv->cachetimeout);
      break;

    case PROP_GUESTFS_MOUNT_LOCAL_DEBUGCALLS:
      g_value_set_enum(value, priv->debugcalls);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_local_finalize(GObject *object)
{
  GuestfsMountLocal *self = GUESTFS_MOUNT_LOCAL(object);
  GuestfsMountLocalPrivate *priv = self->priv;

  g_free(priv->options);

  G_OBJECT_CLASS(guestfs_mount_local_parent_class)->finalize(object);
}

static void
guestfs_mount_local_class_init(GuestfsMountLocalClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_mount_local_set_property;
  object_class->get_property = guestfs_mount_local_get_property;

  /**
   * GuestfsMountLocal:readonly:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MOUNT_LOCAL_READONLY,
    g_param_spec_enum(
      "readonly",
      "readonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMountLocal:options:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MOUNT_LOCAL_OPTIONS,
    g_param_spec_string(
      "options",
      "options",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMountLocal:cachetimeout:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MOUNT_LOCAL_CACHETIMEOUT,
    g_param_spec_int(
      "cachetimeout",
      "cachetimeout",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMountLocal:debugcalls:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MOUNT_LOCAL_DEBUGCALLS,
    g_param_spec_enum(
      "debugcalls",
      "debugcalls",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mount_local_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsMountLocalPrivate));
}

static void
guestfs_mount_local_init(GuestfsMountLocal *o)
{
  o->priv = GUESTFS_MOUNT_LOCAL_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsMountLocalPrivate));
}

/**
 * guestfs_mount_local_new:
 *
 * Create a new GuestfsMountLocal object
 *
 * Returns: (transfer full): a new GuestfsMountLocal object
 */
GuestfsMountLocal *
guestfs_mount_local_new(void)
{
  return GUESTFS_MOUNT_LOCAL(g_object_new(GUESTFS_TYPE_MOUNT_LOCAL, NULL));
}
