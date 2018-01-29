/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * SECTION:optargs-btrfs_subvolume_create
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_subvolume_create
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_subvolume_create
 */

#include <string.h>

#define GUESTFS_BTRFS_SUBVOLUME_CREATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_BTRFS_SUBVOLUME_CREATE, GuestfsBTRFSSubvolumeCreatePrivate))

struct _GuestfsBTRFSSubvolumeCreatePrivate {
  gchar *qgroupid;
};

G_DEFINE_TYPE (GuestfsBTRFSSubvolumeCreate, guestfs_btrfs_subvolume_create, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_SUBVOLUME_CREATE_PROP0,
  PROP_GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID
};

static void
guestfs_btrfs_subvolume_create_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSSubvolumeCreate *self = GUESTFS_BTRFS_SUBVOLUME_CREATE (object);
  GuestfsBTRFSSubvolumeCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID:
      g_free (priv->qgroupid);
      priv->qgroupid = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_subvolume_create_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSSubvolumeCreate *self = GUESTFS_BTRFS_SUBVOLUME_CREATE (object);
  GuestfsBTRFSSubvolumeCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID:
      g_value_set_string (value, priv->qgroupid);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_subvolume_create_finalize (GObject *object)
{
  GuestfsBTRFSSubvolumeCreate *self = GUESTFS_BTRFS_SUBVOLUME_CREATE (object);
  GuestfsBTRFSSubvolumeCreatePrivate *priv = self->priv;

  g_free (priv->qgroupid);
  G_OBJECT_CLASS (guestfs_btrfs_subvolume_create_parent_class)->finalize (object);
}

static void
guestfs_btrfs_subvolume_create_class_init (GuestfsBTRFSSubvolumeCreateClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_btrfs_subvolume_create_set_property;
  object_class->get_property = guestfs_btrfs_subvolume_create_get_property;

  /**
   * GuestfsBTRFSSubvolumeCreate:qgroupid:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID,
    g_param_spec_string (
      "qgroupid",
      "qgroupid",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_subvolume_create_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsBTRFSSubvolumeCreatePrivate));
}

static void
guestfs_btrfs_subvolume_create_init (GuestfsBTRFSSubvolumeCreate *o)
{
  o->priv = GUESTFS_BTRFS_SUBVOLUME_CREATE_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsBTRFSSubvolumeCreatePrivate));
}

/**
 * guestfs_btrfs_subvolume_create_new:
 *
 * Create a new GuestfsBTRFSSubvolumeCreate object
 *
 * Returns: (transfer full): a new GuestfsBTRFSSubvolumeCreate object
 */
GuestfsBTRFSSubvolumeCreate *
guestfs_btrfs_subvolume_create_new (void)
{
  return GUESTFS_BTRFS_SUBVOLUME_CREATE (g_object_new (GUESTFS_TYPE_BTRFS_SUBVOLUME_CREATE, NULL));
}
