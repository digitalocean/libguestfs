/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
 * SECTION:optargs-syslinux
 * @short_description: An object encapsulating optional arguments for guestfs_session_syslinux
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_syslinux
 */

#include <string.h>

#define GUESTFS_SYSLINUX_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_SYSLINUX, GuestfsSyslinuxPrivate))

struct _GuestfsSyslinuxPrivate {
  gchar *directory;
};

G_DEFINE_TYPE (GuestfsSyslinux, guestfs_syslinux, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_SYSLINUX_PROP0,
  PROP_GUESTFS_SYSLINUX_DIRECTORY
};

static void
guestfs_syslinux_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsSyslinux *self = GUESTFS_SYSLINUX (object);
  GuestfsSyslinuxPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_SYSLINUX_DIRECTORY:
      g_free (priv->directory);
      priv->directory = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_syslinux_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsSyslinux *self = GUESTFS_SYSLINUX (object);
  GuestfsSyslinuxPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_SYSLINUX_DIRECTORY:
      g_value_set_string (value, priv->directory);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_syslinux_finalize (GObject *object)
{
  GuestfsSyslinux *self = GUESTFS_SYSLINUX (object);
  GuestfsSyslinuxPrivate *priv = self->priv;

  g_free (priv->directory);
  G_OBJECT_CLASS (guestfs_syslinux_parent_class)->finalize (object);
}

static void
guestfs_syslinux_class_init (GuestfsSyslinuxClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_syslinux_set_property;
  object_class->get_property = guestfs_syslinux_get_property;

  /**
   * GuestfsSyslinux:directory:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_SYSLINUX_DIRECTORY,
    g_param_spec_string (
      "directory",
      "directory",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_syslinux_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsSyslinuxPrivate));
}

static void
guestfs_syslinux_init (GuestfsSyslinux *o)
{
  o->priv = GUESTFS_SYSLINUX_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsSyslinuxPrivate));
}

/**
 * guestfs_syslinux_new:
 *
 * Create a new GuestfsSyslinux object
 *
 * Returns: (transfer full): a new GuestfsSyslinux object
 */
GuestfsSyslinux *
guestfs_syslinux_new (void)
{
  return GUESTFS_SYSLINUX (g_object_new (GUESTFS_TYPE_SYSLINUX, NULL));
}
