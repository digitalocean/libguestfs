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
 * SECTION:optargs-mount_9p
 * @short_description: An object encapsulating optional arguments for guestfs_session_mount_9p
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mount_9p
 */

#include <string.h>

#define GUESTFS_MOUNT_9P_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PPrivate))

struct _GuestfsMount9PPrivate {
  gchar *options;
};

G_DEFINE_TYPE(GuestfsMount9P, guestfs_mount_9p, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MOUNT_9P_PROP0,
  PROP_GUESTFS_MOUNT_9P_OPTIONS
};

static void
guestfs_mount_9p_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_9P_OPTIONS:
      g_free(priv->options);
      priv->options = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_9p_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_9P_OPTIONS:
      g_value_set_string(value, priv->options);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_9p_finalize(GObject *object)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  g_free(priv->options);

  G_OBJECT_CLASS(guestfs_mount_9p_parent_class)->finalize(object);
}

static void
guestfs_mount_9p_class_init(GuestfsMount9PClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_mount_9p_set_property;
  object_class->get_property = guestfs_mount_9p_get_property;

  /**
   * GuestfsMount9P:options:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MOUNT_9P_OPTIONS,
    g_param_spec_string(
      "options",
      "options",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mount_9p_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsMount9PPrivate));
}

static void
guestfs_mount_9p_init(GuestfsMount9P *o)
{
  o->priv = GUESTFS_MOUNT_9P_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsMount9PPrivate));
}

/**
 * guestfs_mount_9p_new:
 *
 * Create a new GuestfsMount9P object
 *
 * Returns: (transfer full): a new GuestfsMount9P object
 */
GuestfsMount9P *
guestfs_mount_9p_new(void)
{
  return GUESTFS_MOUNT_9P(g_object_new(GUESTFS_TYPE_MOUNT_9P, NULL));
}
