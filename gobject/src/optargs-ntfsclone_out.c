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
 * SECTION:optargs-ntfsclone_out
 * @short_description: An object encapsulating optional arguments for guestfs_session_ntfsclone_out
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_ntfsclone_out
 */

#include <string.h>

#define GUESTFS_NTFSCLONE_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_NTFSCLONE_OUT, GuestfsNtfscloneOutPrivate))

struct _GuestfsNtfscloneOutPrivate {
  GuestfsTristate metadataonly;
  GuestfsTristate rescue;
  GuestfsTristate ignorefscheck;
  GuestfsTristate preservetimestamps;
  GuestfsTristate force;
};

G_DEFINE_TYPE(GuestfsNtfscloneOut, guestfs_ntfsclone_out, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_NTFSCLONE_OUT_PROP0,
  PROP_GUESTFS_NTFSCLONE_OUT_METADATAONLY,
  PROP_GUESTFS_NTFSCLONE_OUT_RESCUE,
  PROP_GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK,
  PROP_GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS,
  PROP_GUESTFS_NTFSCLONE_OUT_FORCE
};

static void
guestfs_ntfsclone_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsNtfscloneOut *self = GUESTFS_NTFSCLONE_OUT(object);
  GuestfsNtfscloneOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSCLONE_OUT_METADATAONLY:
      priv->metadataonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_RESCUE:
      priv->rescue = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK:
      priv->ignorefscheck = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS:
      priv->preservetimestamps = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_FORCE:
      priv->force = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsclone_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsNtfscloneOut *self = GUESTFS_NTFSCLONE_OUT(object);
  GuestfsNtfscloneOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSCLONE_OUT_METADATAONLY:
      g_value_set_enum(value, priv->metadataonly);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_RESCUE:
      g_value_set_enum(value, priv->rescue);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK:
      g_value_set_enum(value, priv->ignorefscheck);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS:
      g_value_set_enum(value, priv->preservetimestamps);
      break;

    case PROP_GUESTFS_NTFSCLONE_OUT_FORCE:
      g_value_set_enum(value, priv->force);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsclone_out_finalize(GObject *object)
{
  GuestfsNtfscloneOut *self = GUESTFS_NTFSCLONE_OUT(object);
  GuestfsNtfscloneOutPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_ntfsclone_out_parent_class)->finalize(object);
}

static void
guestfs_ntfsclone_out_class_init(GuestfsNtfscloneOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_ntfsclone_out_set_property;
  object_class->get_property = guestfs_ntfsclone_out_get_property;

  /**
   * GuestfsNtfscloneOut:metadataonly:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSCLONE_OUT_METADATAONLY,
    g_param_spec_enum(
      "metadataonly",
      "metadataonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsNtfscloneOut:rescue:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSCLONE_OUT_RESCUE,
    g_param_spec_enum(
      "rescue",
      "rescue",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsNtfscloneOut:ignorefscheck:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK,
    g_param_spec_enum(
      "ignorefscheck",
      "ignorefscheck",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsNtfscloneOut:preservetimestamps:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS,
    g_param_spec_enum(
      "preservetimestamps",
      "preservetimestamps",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsNtfscloneOut:force:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSCLONE_OUT_FORCE,
    g_param_spec_enum(
      "force",
      "force",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_ntfsclone_out_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsNtfscloneOutPrivate));
}

static void
guestfs_ntfsclone_out_init(GuestfsNtfscloneOut *o)
{
  o->priv = GUESTFS_NTFSCLONE_OUT_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsNtfscloneOutPrivate));
}

/**
 * guestfs_ntfsclone_out_new:
 *
 * Create a new GuestfsNtfscloneOut object
 *
 * Returns: (transfer full): a new GuestfsNtfscloneOut object
 */
GuestfsNtfscloneOut *
guestfs_ntfsclone_out_new(void)
{
  return GUESTFS_NTFSCLONE_OUT(g_object_new(GUESTFS_TYPE_NTFSCLONE_OUT, NULL));
}
