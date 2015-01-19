/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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
 * SECTION:optargs-rsync_in
 * @short_description: An object encapsulating optional arguments for guestfs_session_rsync_in
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_rsync_in
 */

#include <string.h>

#define GUESTFS_RSYNC_IN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_RSYNC_IN, GuestfsRsyncInPrivate))

struct _GuestfsRsyncInPrivate {
  GuestfsTristate archive;
  GuestfsTristate deletedest;
};

G_DEFINE_TYPE (GuestfsRsyncIn, guestfs_rsync_in, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_RSYNC_IN_PROP0,
  PROP_GUESTFS_RSYNC_IN_ARCHIVE,
  PROP_GUESTFS_RSYNC_IN_DELETEDEST
};

static void
guestfs_rsync_in_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsRsyncIn *self = GUESTFS_RSYNC_IN (object);
  GuestfsRsyncInPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_RSYNC_IN_ARCHIVE:
      priv->archive = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_RSYNC_IN_DELETEDEST:
      priv->deletedest = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_rsync_in_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsRsyncIn *self = GUESTFS_RSYNC_IN (object);
  GuestfsRsyncInPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_RSYNC_IN_ARCHIVE:
      g_value_set_enum (value, priv->archive);
      break;

    case PROP_GUESTFS_RSYNC_IN_DELETEDEST:
      g_value_set_enum (value, priv->deletedest);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_rsync_in_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_rsync_in_parent_class)->finalize (object);
}

static void
guestfs_rsync_in_class_init (GuestfsRsyncInClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_rsync_in_set_property;
  object_class->get_property = guestfs_rsync_in_get_property;

  /**
   * GuestfsRsyncIn:archive:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_RSYNC_IN_ARCHIVE,
    g_param_spec_enum (
      "archive",
      "archive",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsRsyncIn:deletedest:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_RSYNC_IN_DELETEDEST,
    g_param_spec_enum (
      "deletedest",
      "deletedest",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_rsync_in_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsRsyncInPrivate));
}

static void
guestfs_rsync_in_init (GuestfsRsyncIn *o)
{
  o->priv = GUESTFS_RSYNC_IN_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsRsyncInPrivate));
}

/**
 * guestfs_rsync_in_new:
 *
 * Create a new GuestfsRsyncIn object
 *
 * Returns: (transfer full): a new GuestfsRsyncIn object
 */
GuestfsRsyncIn *
guestfs_rsync_in_new (void)
{
  return GUESTFS_RSYNC_IN (g_object_new (GUESTFS_TYPE_RSYNC_IN, NULL));
}
