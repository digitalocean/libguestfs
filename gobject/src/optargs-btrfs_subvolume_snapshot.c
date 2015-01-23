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
 * SECTION:optargs-btrfs_subvolume_snapshot
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_subvolume_snapshot
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_subvolume_snapshot
 */

#include <string.h>

#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT, GuestfsBTRFSSubvolumeSnapshotPrivate))

struct _GuestfsBTRFSSubvolumeSnapshotPrivate {
  GuestfsTristate ro;
  gchar *qgroupid;
};

G_DEFINE_TYPE (GuestfsBTRFSSubvolumeSnapshot, guestfs_btrfs_subvolume_snapshot, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_PROP0,
  PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO,
  PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID
};

static void
guestfs_btrfs_subvolume_snapshot_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSSubvolumeSnapshot *self = GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT (object);
  GuestfsBTRFSSubvolumeSnapshotPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO:
      priv->ro = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID:
      g_free (priv->qgroupid);
      priv->qgroupid = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_subvolume_snapshot_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSSubvolumeSnapshot *self = GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT (object);
  GuestfsBTRFSSubvolumeSnapshotPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO:
      g_value_set_enum (value, priv->ro);
      break;

    case PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID:
      g_value_set_string (value, priv->qgroupid);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_subvolume_snapshot_finalize (GObject *object)
{
  GuestfsBTRFSSubvolumeSnapshot *self = GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT (object);
  GuestfsBTRFSSubvolumeSnapshotPrivate *priv = self->priv;

  g_free (priv->qgroupid);
  G_OBJECT_CLASS (guestfs_btrfs_subvolume_snapshot_parent_class)->finalize (object);
}

static void
guestfs_btrfs_subvolume_snapshot_class_init (GuestfsBTRFSSubvolumeSnapshotClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_btrfs_subvolume_snapshot_set_property;
  object_class->get_property = guestfs_btrfs_subvolume_snapshot_get_property;

  /**
   * GuestfsBTRFSSubvolumeSnapshot:ro:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO,
    g_param_spec_enum (
      "ro",
      "ro",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsBTRFSSubvolumeSnapshot:qgroupid:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID,
    g_param_spec_string (
      "qgroupid",
      "qgroupid",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_subvolume_snapshot_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsBTRFSSubvolumeSnapshotPrivate));
}

static void
guestfs_btrfs_subvolume_snapshot_init (GuestfsBTRFSSubvolumeSnapshot *o)
{
  o->priv = GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsBTRFSSubvolumeSnapshotPrivate));
}

/**
 * guestfs_btrfs_subvolume_snapshot_new:
 *
 * Create a new GuestfsBTRFSSubvolumeSnapshot object
 *
 * Returns: (transfer full): a new GuestfsBTRFSSubvolumeSnapshot object
 */
GuestfsBTRFSSubvolumeSnapshot *
guestfs_btrfs_subvolume_snapshot_new (void)
{
  return GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT (g_object_new (GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT, NULL));
}
