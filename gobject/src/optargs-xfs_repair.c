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
 * SECTION:optargs-xfs_repair
 * @short_description: An object encapsulating optional arguments for guestfs_session_xfs_repair
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_xfs_repair
 */

#include <string.h>

#define GUESTFS_XFS_REPAIR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_XFS_REPAIR, GuestfsXfsRepairPrivate))

struct _GuestfsXfsRepairPrivate {
  GuestfsTristate forcelogzero;
  GuestfsTristate nomodify;
  GuestfsTristate noprefetch;
  GuestfsTristate forcegeometry;
  gint64 maxmem;
  gint64 ihashsize;
  gint64 bhashsize;
  gint64 agstride;
  gchar *logdev;
  gchar *rtdev;
};

G_DEFINE_TYPE (GuestfsXfsRepair, guestfs_xfs_repair, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_XFS_REPAIR_PROP0,
  PROP_GUESTFS_XFS_REPAIR_FORCELOGZERO,
  PROP_GUESTFS_XFS_REPAIR_NOMODIFY,
  PROP_GUESTFS_XFS_REPAIR_NOPREFETCH,
  PROP_GUESTFS_XFS_REPAIR_FORCEGEOMETRY,
  PROP_GUESTFS_XFS_REPAIR_MAXMEM,
  PROP_GUESTFS_XFS_REPAIR_IHASHSIZE,
  PROP_GUESTFS_XFS_REPAIR_BHASHSIZE,
  PROP_GUESTFS_XFS_REPAIR_AGSTRIDE,
  PROP_GUESTFS_XFS_REPAIR_LOGDEV,
  PROP_GUESTFS_XFS_REPAIR_RTDEV
};

static void
guestfs_xfs_repair_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsXfsRepair *self = GUESTFS_XFS_REPAIR (object);
  GuestfsXfsRepairPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_REPAIR_FORCELOGZERO:
      priv->forcelogzero = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_NOMODIFY:
      priv->nomodify = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_NOPREFETCH:
      priv->noprefetch = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_FORCEGEOMETRY:
      priv->forcegeometry = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_MAXMEM:
      priv->maxmem = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_IHASHSIZE:
      priv->ihashsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_BHASHSIZE:
      priv->bhashsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_AGSTRIDE:
      priv->agstride = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_LOGDEV:
      g_free (priv->logdev);
      priv->logdev = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_XFS_REPAIR_RTDEV:
      g_free (priv->rtdev);
      priv->rtdev = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_repair_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsXfsRepair *self = GUESTFS_XFS_REPAIR (object);
  GuestfsXfsRepairPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_XFS_REPAIR_FORCELOGZERO:
      g_value_set_enum (value, priv->forcelogzero);
      break;

    case PROP_GUESTFS_XFS_REPAIR_NOMODIFY:
      g_value_set_enum (value, priv->nomodify);
      break;

    case PROP_GUESTFS_XFS_REPAIR_NOPREFETCH:
      g_value_set_enum (value, priv->noprefetch);
      break;

    case PROP_GUESTFS_XFS_REPAIR_FORCEGEOMETRY:
      g_value_set_enum (value, priv->forcegeometry);
      break;

    case PROP_GUESTFS_XFS_REPAIR_MAXMEM:
      g_value_set_int64 (value, priv->maxmem);
      break;

    case PROP_GUESTFS_XFS_REPAIR_IHASHSIZE:
      g_value_set_int64 (value, priv->ihashsize);
      break;

    case PROP_GUESTFS_XFS_REPAIR_BHASHSIZE:
      g_value_set_int64 (value, priv->bhashsize);
      break;

    case PROP_GUESTFS_XFS_REPAIR_AGSTRIDE:
      g_value_set_int64 (value, priv->agstride);
      break;

    case PROP_GUESTFS_XFS_REPAIR_LOGDEV:
      g_value_set_string (value, priv->logdev);
      break;

    case PROP_GUESTFS_XFS_REPAIR_RTDEV:
      g_value_set_string (value, priv->rtdev);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_xfs_repair_finalize (GObject *object)
{
  GuestfsXfsRepair *self = GUESTFS_XFS_REPAIR (object);
  GuestfsXfsRepairPrivate *priv = self->priv;

  g_free (priv->logdev);
  g_free (priv->rtdev);
  G_OBJECT_CLASS (guestfs_xfs_repair_parent_class)->finalize (object);
}

static void
guestfs_xfs_repair_class_init (GuestfsXfsRepairClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_xfs_repair_set_property;
  object_class->get_property = guestfs_xfs_repair_get_property;

  /**
   * GuestfsXfsRepair:forcelogzero:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_FORCELOGZERO,
    g_param_spec_enum (
      "forcelogzero",
      "forcelogzero",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:nomodify:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_NOMODIFY,
    g_param_spec_enum (
      "nomodify",
      "nomodify",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:noprefetch:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_NOPREFETCH,
    g_param_spec_enum (
      "noprefetch",
      "noprefetch",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:forcegeometry:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_FORCEGEOMETRY,
    g_param_spec_enum (
      "forcegeometry",
      "forcegeometry",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:maxmem:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_MAXMEM,
    g_param_spec_int64 (
      "maxmem",
      "maxmem",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:ihashsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_IHASHSIZE,
    g_param_spec_int64 (
      "ihashsize",
      "ihashsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:bhashsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_BHASHSIZE,
    g_param_spec_int64 (
      "bhashsize",
      "bhashsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:agstride:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_AGSTRIDE,
    g_param_spec_int64 (
      "agstride",
      "agstride",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:logdev:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_LOGDEV,
    g_param_spec_string (
      "logdev",
      "logdev",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsXfsRepair:rtdev:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_XFS_REPAIR_RTDEV,
    g_param_spec_string (
      "rtdev",
      "rtdev",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_xfs_repair_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsXfsRepairPrivate));
}

static void
guestfs_xfs_repair_init (GuestfsXfsRepair *o)
{
  o->priv = GUESTFS_XFS_REPAIR_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsXfsRepairPrivate));
}

/**
 * guestfs_xfs_repair_new:
 *
 * Create a new GuestfsXfsRepair object
 *
 * Returns: (transfer full): a new GuestfsXfsRepair object
 */
GuestfsXfsRepair *
guestfs_xfs_repair_new (void)
{
  return GUESTFS_XFS_REPAIR (g_object_new (GUESTFS_TYPE_XFS_REPAIR, NULL));
}
