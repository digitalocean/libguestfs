/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
 * SECTION:optargs-rsync_out
 * @short_description: An object encapsulating optional arguments for guestfs_session_rsync_out
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_rsync_out
 */

#include <string.h>

#define GUESTFS_RSYNC_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_RSYNC_OUT, GuestfsRsyncOutPrivate))

struct _GuestfsRsyncOutPrivate {
  GuestfsTristate archive;
  GuestfsTristate deletedest;
};

G_DEFINE_TYPE (GuestfsRsyncOut, guestfs_rsync_out, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_RSYNC_OUT_PROP0,
  PROP_GUESTFS_RSYNC_OUT_ARCHIVE,
  PROP_GUESTFS_RSYNC_OUT_DELETEDEST
};

static void
guestfs_rsync_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsRsyncOut *self = GUESTFS_RSYNC_OUT (object);
  GuestfsRsyncOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_RSYNC_OUT_ARCHIVE:
      priv->archive = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_RSYNC_OUT_DELETEDEST:
      priv->deletedest = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_rsync_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsRsyncOut *self = GUESTFS_RSYNC_OUT (object);
  GuestfsRsyncOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_RSYNC_OUT_ARCHIVE:
      g_value_set_enum (value, priv->archive);
      break;

    case PROP_GUESTFS_RSYNC_OUT_DELETEDEST:
      g_value_set_enum (value, priv->deletedest);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_rsync_out_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_rsync_out_parent_class)->finalize (object);
}

static void
guestfs_rsync_out_class_init (GuestfsRsyncOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_rsync_out_set_property;
  object_class->get_property = guestfs_rsync_out_get_property;

  /**
   * GuestfsRsyncOut:archive:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_RSYNC_OUT_ARCHIVE,
    g_param_spec_enum (
      "archive",
      "archive",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsRsyncOut:deletedest:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_RSYNC_OUT_DELETEDEST,
    g_param_spec_enum (
      "deletedest",
      "deletedest",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_rsync_out_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsRsyncOutPrivate));
}

static void
guestfs_rsync_out_init (GuestfsRsyncOut *o)
{
  o->priv = GUESTFS_RSYNC_OUT_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsRsyncOutPrivate));
}

/**
 * guestfs_rsync_out_new:
 *
 * Create a new GuestfsRsyncOut object
 *
 * Returns: (transfer full): a new GuestfsRsyncOut object
 */
GuestfsRsyncOut *
guestfs_rsync_out_new (void)
{
  return GUESTFS_RSYNC_OUT (g_object_new (GUESTFS_TYPE_RSYNC_OUT, NULL));
}
