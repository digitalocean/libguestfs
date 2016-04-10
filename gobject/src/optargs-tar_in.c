/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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
 * SECTION:optargs-tar_in
 * @short_description: An object encapsulating optional arguments for guestfs_session_tar_in
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_tar_in
 */

#include <string.h>

#define GUESTFS_TAR_IN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_TAR_IN, GuestfsTarInPrivate))

struct _GuestfsTarInPrivate {
  gchar *compress;
  GuestfsTristate xattrs;
  GuestfsTristate selinux;
  GuestfsTristate acls;
};

G_DEFINE_TYPE (GuestfsTarIn, guestfs_tar_in, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_TAR_IN_PROP0,
  PROP_GUESTFS_TAR_IN_COMPRESS,
  PROP_GUESTFS_TAR_IN_XATTRS,
  PROP_GUESTFS_TAR_IN_SELINUX,
  PROP_GUESTFS_TAR_IN_ACLS
};

static void
guestfs_tar_in_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsTarIn *self = GUESTFS_TAR_IN (object);
  GuestfsTarInPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TAR_IN_COMPRESS:
      g_free (priv->compress);
      priv->compress = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_TAR_IN_XATTRS:
      priv->xattrs = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_TAR_IN_SELINUX:
      priv->selinux = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_TAR_IN_ACLS:
      priv->acls = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_tar_in_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsTarIn *self = GUESTFS_TAR_IN (object);
  GuestfsTarInPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TAR_IN_COMPRESS:
      g_value_set_string (value, priv->compress);
      break;

    case PROP_GUESTFS_TAR_IN_XATTRS:
      g_value_set_enum (value, priv->xattrs);
      break;

    case PROP_GUESTFS_TAR_IN_SELINUX:
      g_value_set_enum (value, priv->selinux);
      break;

    case PROP_GUESTFS_TAR_IN_ACLS:
      g_value_set_enum (value, priv->acls);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_tar_in_finalize (GObject *object)
{
  GuestfsTarIn *self = GUESTFS_TAR_IN (object);
  GuestfsTarInPrivate *priv = self->priv;

  g_free (priv->compress);
  G_OBJECT_CLASS (guestfs_tar_in_parent_class)->finalize (object);
}

static void
guestfs_tar_in_class_init (GuestfsTarInClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_tar_in_set_property;
  object_class->get_property = guestfs_tar_in_get_property;

  /**
   * GuestfsTarIn:compress:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_TAR_IN_COMPRESS,
    g_param_spec_string (
      "compress",
      "compress",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTarIn:xattrs:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_TAR_IN_XATTRS,
    g_param_spec_enum (
      "xattrs",
      "xattrs",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTarIn:selinux:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_TAR_IN_SELINUX,
    g_param_spec_enum (
      "selinux",
      "selinux",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTarIn:acls:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_TAR_IN_ACLS,
    g_param_spec_enum (
      "acls",
      "acls",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_tar_in_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsTarInPrivate));
}

static void
guestfs_tar_in_init (GuestfsTarIn *o)
{
  o->priv = GUESTFS_TAR_IN_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsTarInPrivate));
}

/**
 * guestfs_tar_in_new:
 *
 * Create a new GuestfsTarIn object
 *
 * Returns: (transfer full): a new GuestfsTarIn object
 */
GuestfsTarIn *
guestfs_tar_in_new (void)
{
  return GUESTFS_TAR_IN (g_object_new (GUESTFS_TYPE_TAR_IN, NULL));
}
