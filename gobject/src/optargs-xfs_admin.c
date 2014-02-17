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
 * SECTION:optargs-xfs_admin
 * @short_description: An object encapsulating optional arguments for guestfs_session_xfs_admin
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_xfs_admin
 */

#include <string.h>

#define GUESTFS_XFS_ADMIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_XFS_ADMIN, GuestfsXfsAdminPrivate))

struct _GuestfsXfsAdminPrivate {
  GuestfsTristate extunwritten;
  GuestfsTristate imgfile;
  GuestfsTristate v2log;
  GuestfsTristate projid32bit;
  GuestfsTristate lazycounter;
  gchar *label;
  gchar *uuid;
};

G_DEFINE_TYPE (GuestfsXfsAdmin, guestfs_xfs_admin, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_XFS_ADMIN_PROP0,
  PROP_GUESTFS_XFS_ADMIN_EXTUNWRITTEN,
  PROP_GUESTFS_XFS_ADMIN_IMGFILE,
  PROP_GUESTFS_XFS_ADMIN_V2LOG,
  PROP_GUESTFS_XFS_ADMIN_PROJID32BIT,
  PROP_GUESTFS_XFS_ADMIN_LAZYCOUNTER,
  PROP_GUESTFS_XFS_ADMIN_LABEL,
  PROP_GUESTFS_XFS_ADMIN_UUID
};

static void
guestfs_xfs_admin_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsXfsAdmin *self = GUESTFS_XFS_ADMIN (object);
  GuestfsXfsAdminPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_ADMIN_EXTUNWRITTEN:
      priv->extunwritten = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_IMGFILE:
      priv->imgfile = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_V2LOG:
      priv->v2log = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_PROJID32BIT:
      priv->projid32bit = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_LAZYCOUNTER:
      priv->lazycounter = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_LABEL:
      g_free (priv->label);
      priv->label = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_XFS_ADMIN_UUID:
      g_free (priv->uuid);
      priv->uuid = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_admin_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsXfsAdmin *self = GUESTFS_XFS_ADMIN (object);
  GuestfsXfsAdminPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_ADMIN_EXTUNWRITTEN:
      g_value_set_enum (value, priv->extunwritten);
      break;

    case PROP_GUESTFS_XFS_ADMIN_IMGFILE:
      g_value_set_enum (value, priv->imgfile);
      break;

    case PROP_GUESTFS_XFS_ADMIN_V2LOG:
      g_value_set_enum (value, priv->v2log);
      break;

    case PROP_GUESTFS_XFS_ADMIN_PROJID32BIT:
      g_value_set_enum (value, priv->projid32bit);
      break;

    case PROP_GUESTFS_XFS_ADMIN_LAZYCOUNTER:
      g_value_set_enum (value, priv->lazycounter);
      break;

    case PROP_GUESTFS_XFS_ADMIN_LABEL:
      g_value_set_string (value, priv->label);
      break;

    case PROP_GUESTFS_XFS_ADMIN_UUID:
      g_value_set_string (value, priv->uuid);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_admin_finalize (GObject *object)
{
  GuestfsXfsAdmin *self = GUESTFS_XFS_ADMIN (object);
  GuestfsXfsAdminPrivate *priv = self->priv;

  g_free (priv->label);
  g_free (priv->uuid);
  G_OBJECT_CLASS (guestfs_xfs_admin_parent_class)->finalize (object);
}

static void
guestfs_xfs_admin_class_init (GuestfsXfsAdminClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_xfs_admin_set_property;
  object_class->get_property = guestfs_xfs_admin_get_property;

  /**
   * GuestfsXfsAdmin:extunwritten:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_EXTUNWRITTEN,
    g_param_spec_enum (
      "extunwritten",
      "extunwritten",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:imgfile:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_IMGFILE,
    g_param_spec_enum (
      "imgfile",
      "imgfile",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:v2log:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_V2LOG,
    g_param_spec_enum (
      "v2log",
      "v2log",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:projid32bit:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_PROJID32BIT,
    g_param_spec_enum (
      "projid32bit",
      "projid32bit",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:lazycounter:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_LAZYCOUNTER,
    g_param_spec_enum (
      "lazycounter",
      "lazycounter",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:label:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_LABEL,
    g_param_spec_string (
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsAdmin:uuid:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_ADMIN_UUID,
    g_param_spec_string (
      "uuid",
      "uuid",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_xfs_admin_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsXfsAdminPrivate));
}

static void
guestfs_xfs_admin_init (GuestfsXfsAdmin *o)
{
  o->priv = GUESTFS_XFS_ADMIN_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsXfsAdminPrivate));
}

/**
 * guestfs_xfs_admin_new:
 *
 * Create a new GuestfsXfsAdmin object
 *
 * Returns: (transfer full): a new GuestfsXfsAdmin object
 */
GuestfsXfsAdmin *
guestfs_xfs_admin_new (void)
{
  return GUESTFS_XFS_ADMIN (g_object_new (GUESTFS_TYPE_XFS_ADMIN, NULL));
}
