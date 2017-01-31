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
 * SECTION:optargs-btrfs_filesystem_defragment
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_filesystem_defragment
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_filesystem_defragment
 */

#include <string.h>

#define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_BTRFS_FILESYSTEM_DEFRAGMENT, GuestfsBTRFSFilesystemDefragmentPrivate))

struct _GuestfsBTRFSFilesystemDefragmentPrivate {
  GuestfsTristate flush;
  gchar *compress;
};

G_DEFINE_TYPE (GuestfsBTRFSFilesystemDefragment, guestfs_btrfs_filesystem_defragment, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_PROP0,
  PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH,
  PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS
};

static void
guestfs_btrfs_filesystem_defragment_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemDefragment *self = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT (object);
  GuestfsBTRFSFilesystemDefragmentPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH:
      priv->flush = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS:
      g_free (priv->compress);
      priv->compress = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_defragment_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemDefragment *self = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT (object);
  GuestfsBTRFSFilesystemDefragmentPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH:
      g_value_set_enum (value, priv->flush);
      break;

    case PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS:
      g_value_set_string (value, priv->compress);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_defragment_finalize (GObject *object)
{
  GuestfsBTRFSFilesystemDefragment *self = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT (object);
  GuestfsBTRFSFilesystemDefragmentPrivate *priv = self->priv;

  g_free (priv->compress);
  G_OBJECT_CLASS (guestfs_btrfs_filesystem_defragment_parent_class)->finalize (object);
}

static void
guestfs_btrfs_filesystem_defragment_class_init (GuestfsBTRFSFilesystemDefragmentClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_btrfs_filesystem_defragment_set_property;
  object_class->get_property = guestfs_btrfs_filesystem_defragment_get_property;

  /**
   * GuestfsBTRFSFilesystemDefragment:flush:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH,
    g_param_spec_enum (
      "flush",
      "flush",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsBTRFSFilesystemDefragment:compress:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS,
    g_param_spec_string (
      "compress",
      "compress",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_filesystem_defragment_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsBTRFSFilesystemDefragmentPrivate));
}

static void
guestfs_btrfs_filesystem_defragment_init (GuestfsBTRFSFilesystemDefragment *o)
{
  o->priv = GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsBTRFSFilesystemDefragmentPrivate));
}

/**
 * guestfs_btrfs_filesystem_defragment_new:
 *
 * Create a new GuestfsBTRFSFilesystemDefragment object
 *
 * Returns: (transfer full): a new GuestfsBTRFSFilesystemDefragment object
 */
GuestfsBTRFSFilesystemDefragment *
guestfs_btrfs_filesystem_defragment_new (void)
{
  return GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT (g_object_new (GUESTFS_TYPE_BTRFS_FILESYSTEM_DEFRAGMENT, NULL));
}
