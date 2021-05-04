/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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
 * SECTION:optargs-btrfs_image
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_image
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_image
 */

#include <string.h>

#define GUESTFS_BTRFS_IMAGE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_BTRFS_IMAGE, GuestfsBTRFSImagePrivate))

struct _GuestfsBTRFSImagePrivate {
  gint compresslevel;
};

G_DEFINE_TYPE (GuestfsBTRFSImage, guestfs_btrfs_image, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_IMAGE_PROP0,
  PROP_GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL
};

static void
guestfs_btrfs_image_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSImage *self = GUESTFS_BTRFS_IMAGE (object);
  GuestfsBTRFSImagePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL:
      priv->compresslevel = g_value_get_int (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_image_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSImage *self = GUESTFS_BTRFS_IMAGE (object);
  GuestfsBTRFSImagePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL:
      g_value_set_int (value, priv->compresslevel);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_btrfs_image_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_btrfs_image_parent_class)->finalize (object);
}

static void
guestfs_btrfs_image_class_init (GuestfsBTRFSImageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_btrfs_image_set_property;
  object_class->get_property = guestfs_btrfs_image_get_property;

  /**
   * GuestfsBTRFSImage:compresslevel:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL,
    g_param_spec_int (
      "compresslevel",
      "compresslevel",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_image_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsBTRFSImagePrivate));
}

static void
guestfs_btrfs_image_init (GuestfsBTRFSImage *o)
{
  o->priv = GUESTFS_BTRFS_IMAGE_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsBTRFSImagePrivate));
}

/**
 * guestfs_btrfs_image_new:
 *
 * Create a new GuestfsBTRFSImage object
 *
 * Returns: (transfer full): a new GuestfsBTRFSImage object
 */
GuestfsBTRFSImage *
guestfs_btrfs_image_new (void)
{
  return GUESTFS_BTRFS_IMAGE (g_object_new (GUESTFS_TYPE_BTRFS_IMAGE, NULL));
}
