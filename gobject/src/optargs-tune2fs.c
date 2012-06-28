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
 * SECTION:optargs-tune2fs
 * @short_description: An object encapsulating optional arguments for guestfs_session_tune2fs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_tune2fs
 */

#include <string.h>

#define GUESTFS_TUNE2FS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSPrivate))

struct _GuestfsTune2FSPrivate {
  GuestfsTristate force;
  gint maxmountcount;
  gint mountcount;
  gchar *errorbehavior;
  gint64 group;
  gint intervalbetweenchecks;
  gint reservedblockspercentage;
  gchar *lastmounteddirectory;
  gint64 reservedblockscount;
  gint64 user;
};

G_DEFINE_TYPE(GuestfsTune2FS, guestfs_tune2fs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_TUNE2FS_PROP0,
  PROP_GUESTFS_TUNE2FS_FORCE,
  PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT,
  PROP_GUESTFS_TUNE2FS_MOUNTCOUNT,
  PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR,
  PROP_GUESTFS_TUNE2FS_GROUP,
  PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS,
  PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE,
  PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY,
  PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT,
  PROP_GUESTFS_TUNE2FS_USER
};

static void
guestfs_tune2fs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TUNE2FS_FORCE:
      priv->force = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT:
      priv->maxmountcount = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_MOUNTCOUNT:
      priv->mountcount = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR:
      g_free(priv->errorbehavior);
      priv->errorbehavior = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_TUNE2FS_GROUP:
      priv->group = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS:
      priv->intervalbetweenchecks = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE:
      priv->reservedblockspercentage = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY:
      g_free(priv->lastmounteddirectory);
      priv->lastmounteddirectory = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT:
      priv->reservedblockscount = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_TUNE2FS_USER:
      priv->user = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tune2fs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TUNE2FS_FORCE:
      g_value_set_enum(value, priv->force);
      break;

    case PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT:
      g_value_set_int(value, priv->maxmountcount);
      break;

    case PROP_GUESTFS_TUNE2FS_MOUNTCOUNT:
      g_value_set_int(value, priv->mountcount);
      break;

    case PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR:
      g_value_set_string(value, priv->errorbehavior);
      break;

    case PROP_GUESTFS_TUNE2FS_GROUP:
      g_value_set_int64(value, priv->group);
      break;

    case PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS:
      g_value_set_int(value, priv->intervalbetweenchecks);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE:
      g_value_set_int(value, priv->reservedblockspercentage);
      break;

    case PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY:
      g_value_set_string(value, priv->lastmounteddirectory);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT:
      g_value_set_int64(value, priv->reservedblockscount);
      break;

    case PROP_GUESTFS_TUNE2FS_USER:
      g_value_set_int64(value, priv->user);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tune2fs_finalize(GObject *object)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  g_free(priv->errorbehavior);
  g_free(priv->lastmounteddirectory);

  G_OBJECT_CLASS(guestfs_tune2fs_parent_class)->finalize(object);
}

static void
guestfs_tune2fs_class_init(GuestfsTune2FSClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_tune2fs_set_property;
  object_class->get_property = guestfs_tune2fs_get_property;

  /**
   * GuestfsTune2FS:force:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_FORCE,
    g_param_spec_enum(
      "force",
      "force",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:maxmountcount:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT,
    g_param_spec_int(
      "maxmountcount",
      "maxmountcount",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:mountcount:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_MOUNTCOUNT,
    g_param_spec_int(
      "mountcount",
      "mountcount",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:errorbehavior:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR,
    g_param_spec_string(
      "errorbehavior",
      "errorbehavior",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:group:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_GROUP,
    g_param_spec_int64(
      "group",
      "group",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:intervalbetweenchecks:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS,
    g_param_spec_int(
      "intervalbetweenchecks",
      "intervalbetweenchecks",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:reservedblockspercentage:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE,
    g_param_spec_int(
      "reservedblockspercentage",
      "reservedblockspercentage",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:lastmounteddirectory:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY,
    g_param_spec_string(
      "lastmounteddirectory",
      "lastmounteddirectory",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:reservedblockscount:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT,
    g_param_spec_int64(
      "reservedblockscount",
      "reservedblockscount",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsTune2FS:user:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_TUNE2FS_USER,
    g_param_spec_int64(
      "user",
      "user",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_tune2fs_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsTune2FSPrivate));
}

static void
guestfs_tune2fs_init(GuestfsTune2FS *o)
{
  o->priv = GUESTFS_TUNE2FS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsTune2FSPrivate));
}

/**
 * guestfs_tune2fs_new:
 *
 * Create a new GuestfsTune2FS object
 *
 * Returns: (transfer full): a new GuestfsTune2FS object
 */
GuestfsTune2FS *
guestfs_tune2fs_new(void)
{
  return GUESTFS_TUNE2FS(g_object_new(GUESTFS_TYPE_TUNE2FS, NULL));
}
