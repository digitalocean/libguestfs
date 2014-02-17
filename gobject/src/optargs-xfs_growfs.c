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
 * SECTION:optargs-xfs_growfs
 * @short_description: An object encapsulating optional arguments for guestfs_session_xfs_growfs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_xfs_growfs
 */

#include <string.h>

#define GUESTFS_XFS_GROWFS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_XFS_GROWFS, GuestfsXfsGrowfsPrivate))

struct _GuestfsXfsGrowfsPrivate {
  GuestfsTristate datasec;
  GuestfsTristate logsec;
  GuestfsTristate rtsec;
  gint64 datasize;
  gint64 logsize;
  gint64 rtsize;
  gint64 rtextsize;
  gint maxpct;
};

G_DEFINE_TYPE (GuestfsXfsGrowfs, guestfs_xfs_growfs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_XFS_GROWFS_PROP0,
  PROP_GUESTFS_XFS_GROWFS_DATASEC,
  PROP_GUESTFS_XFS_GROWFS_LOGSEC,
  PROP_GUESTFS_XFS_GROWFS_RTSEC,
  PROP_GUESTFS_XFS_GROWFS_DATASIZE,
  PROP_GUESTFS_XFS_GROWFS_LOGSIZE,
  PROP_GUESTFS_XFS_GROWFS_RTSIZE,
  PROP_GUESTFS_XFS_GROWFS_RTEXTSIZE,
  PROP_GUESTFS_XFS_GROWFS_MAXPCT
};

static void
guestfs_xfs_growfs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsXfsGrowfs *self = GUESTFS_XFS_GROWFS (object);
  GuestfsXfsGrowfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_GROWFS_DATASEC:
      priv->datasec = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_LOGSEC:
      priv->logsec = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTSEC:
      priv->rtsec = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_DATASIZE:
      priv->datasize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_LOGSIZE:
      priv->logsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTSIZE:
      priv->rtsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTEXTSIZE:
      priv->rtextsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_GROWFS_MAXPCT:
      priv->maxpct = g_value_get_int (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_growfs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsXfsGrowfs *self = GUESTFS_XFS_GROWFS (object);
  GuestfsXfsGrowfsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_GROWFS_DATASEC:
      g_value_set_enum (value, priv->datasec);
      break;

    case PROP_GUESTFS_XFS_GROWFS_LOGSEC:
      g_value_set_enum (value, priv->logsec);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTSEC:
      g_value_set_enum (value, priv->rtsec);
      break;

    case PROP_GUESTFS_XFS_GROWFS_DATASIZE:
      g_value_set_int64 (value, priv->datasize);
      break;

    case PROP_GUESTFS_XFS_GROWFS_LOGSIZE:
      g_value_set_int64 (value, priv->logsize);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTSIZE:
      g_value_set_int64 (value, priv->rtsize);
      break;

    case PROP_GUESTFS_XFS_GROWFS_RTEXTSIZE:
      g_value_set_int64 (value, priv->rtextsize);
      break;

    case PROP_GUESTFS_XFS_GROWFS_MAXPCT:
      g_value_set_int (value, priv->maxpct);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_growfs_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_xfs_growfs_parent_class)->finalize (object);
}

static void
guestfs_xfs_growfs_class_init (GuestfsXfsGrowfsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_xfs_growfs_set_property;
  object_class->get_property = guestfs_xfs_growfs_get_property;

  /**
   * GuestfsXfsGrowfs:datasec:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_DATASEC,
    g_param_spec_enum (
      "datasec",
      "datasec",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:logsec:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_LOGSEC,
    g_param_spec_enum (
      "logsec",
      "logsec",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:rtsec:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_RTSEC,
    g_param_spec_enum (
      "rtsec",
      "rtsec",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:datasize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_DATASIZE,
    g_param_spec_int64 (
      "datasize",
      "datasize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:logsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_LOGSIZE,
    g_param_spec_int64 (
      "logsize",
      "logsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:rtsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_RTSIZE,
    g_param_spec_int64 (
      "rtsize",
      "rtsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:rtextsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_RTEXTSIZE,
    g_param_spec_int64 (
      "rtextsize",
      "rtextsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsGrowfs:maxpct:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_GROWFS_MAXPCT,
    g_param_spec_int (
      "maxpct",
      "maxpct",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_xfs_growfs_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsXfsGrowfsPrivate));
}

static void
guestfs_xfs_growfs_init (GuestfsXfsGrowfs *o)
{
  o->priv = GUESTFS_XFS_GROWFS_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsXfsGrowfsPrivate));
}

/**
 * guestfs_xfs_growfs_new:
 *
 * Create a new GuestfsXfsGrowfs object
 *
 * Returns: (transfer full): a new GuestfsXfsGrowfs object
 */
GuestfsXfsGrowfs *
guestfs_xfs_growfs_new (void)
{
  return GUESTFS_XFS_GROWFS (g_object_new (GUESTFS_TYPE_XFS_GROWFS, NULL));
}
