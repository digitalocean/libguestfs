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
 * SECTION:optargs-download_blocks
 * @short_description: An object encapsulating optional arguments for guestfs_session_download_blocks
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_download_blocks
 */

#include <string.h>

#define GUESTFS_DOWNLOAD_BLOCKS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_DOWNLOAD_BLOCKS, GuestfsDownloadBlocksPrivate))

struct _GuestfsDownloadBlocksPrivate {
  GuestfsTristate unallocated;
};

G_DEFINE_TYPE (GuestfsDownloadBlocks, guestfs_download_blocks, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_DOWNLOAD_BLOCKS_PROP0,
  PROP_GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED
};

static void
guestfs_download_blocks_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsDownloadBlocks *self = GUESTFS_DOWNLOAD_BLOCKS (object);
  GuestfsDownloadBlocksPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED:
      priv->unallocated = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_download_blocks_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsDownloadBlocks *self = GUESTFS_DOWNLOAD_BLOCKS (object);
  GuestfsDownloadBlocksPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED:
      g_value_set_enum (value, priv->unallocated);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_download_blocks_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_download_blocks_parent_class)->finalize (object);
}

static void
guestfs_download_blocks_class_init (GuestfsDownloadBlocksClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_download_blocks_set_property;
  object_class->get_property = guestfs_download_blocks_get_property;

  /**
   * GuestfsDownloadBlocks:unallocated:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED,
    g_param_spec_enum (
      "unallocated",
      "unallocated",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_download_blocks_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsDownloadBlocksPrivate));
}

static void
guestfs_download_blocks_init (GuestfsDownloadBlocks *o)
{
  o->priv = GUESTFS_DOWNLOAD_BLOCKS_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsDownloadBlocksPrivate));
}

/**
 * guestfs_download_blocks_new:
 *
 * Create a new GuestfsDownloadBlocks object
 *
 * Returns: (transfer full): a new GuestfsDownloadBlocks object
 */
GuestfsDownloadBlocks *
guestfs_download_blocks_new (void)
{
  return GUESTFS_DOWNLOAD_BLOCKS (g_object_new (GUESTFS_TYPE_DOWNLOAD_BLOCKS, NULL));
}
