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
 * SECTION:optargs-btrfs_fsck
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_fsck
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_fsck
 */

#include <string.h>

#define GUESTFS_BTRFS_FSCK_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_BTRFS_FSCK, GuestfsBtrfsFsckPrivate))

struct _GuestfsBtrfsFsckPrivate {
  gint64 superblock;
  GuestfsTristate repair;
};

G_DEFINE_TYPE(GuestfsBtrfsFsck, guestfs_btrfs_fsck, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_FSCK_PROP0,
  PROP_GUESTFS_BTRFS_FSCK_SUPERBLOCK,
  PROP_GUESTFS_BTRFS_FSCK_REPAIR
};

static void
guestfs_btrfs_fsck_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBtrfsFsck *self = GUESTFS_BTRFS_FSCK(object);
  GuestfsBtrfsFsckPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FSCK_SUPERBLOCK:
      priv->superblock = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_BTRFS_FSCK_REPAIR:
      priv->repair = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_fsck_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBtrfsFsck *self = GUESTFS_BTRFS_FSCK(object);
  GuestfsBtrfsFsckPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FSCK_SUPERBLOCK:
      g_value_set_int64(value, priv->superblock);
      break;

    case PROP_GUESTFS_BTRFS_FSCK_REPAIR:
      g_value_set_enum(value, priv->repair);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_fsck_finalize(GObject *object)
{
  GuestfsBtrfsFsck *self = GUESTFS_BTRFS_FSCK(object);
  GuestfsBtrfsFsckPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_btrfs_fsck_parent_class)->finalize(object);
}

static void
guestfs_btrfs_fsck_class_init(GuestfsBtrfsFsckClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_btrfs_fsck_set_property;
  object_class->get_property = guestfs_btrfs_fsck_get_property;

  /**
   * GuestfsBtrfsFsck:superblock:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_BTRFS_FSCK_SUPERBLOCK,
    g_param_spec_int64(
      "superblock",
      "superblock",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsBtrfsFsck:repair:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_BTRFS_FSCK_REPAIR,
    g_param_spec_enum(
      "repair",
      "repair",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_fsck_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsBtrfsFsckPrivate));
}

static void
guestfs_btrfs_fsck_init(GuestfsBtrfsFsck *o)
{
  o->priv = GUESTFS_BTRFS_FSCK_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsBtrfsFsckPrivate));
}

/**
 * guestfs_btrfs_fsck_new:
 *
 * Create a new GuestfsBtrfsFsck object
 *
 * Returns: (transfer full): a new GuestfsBtrfsFsck object
 */
GuestfsBtrfsFsck *
guestfs_btrfs_fsck_new(void)
{
  return GUESTFS_BTRFS_FSCK(g_object_new(GUESTFS_TYPE_BTRFS_FSCK, NULL));
}
