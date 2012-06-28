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
 * SECTION:optargs-btrfs_filesystem_resize
 * @short_description: An object encapsulating optional arguments for guestfs_session_btrfs_filesystem_resize
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_btrfs_filesystem_resize
 */

#include <string.h>

#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, GuestfsBTRFSFilesystemResizePrivate))

struct _GuestfsBTRFSFilesystemResizePrivate {
  gint64 size;
};

G_DEFINE_TYPE(GuestfsBTRFSFilesystemResize, guestfs_btrfs_filesystem_resize, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_PROP0,
  PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE
};

static void
guestfs_btrfs_filesystem_resize_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_resize_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_resize_finalize(GObject *object)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_btrfs_filesystem_resize_parent_class)->finalize(object);
}

static void
guestfs_btrfs_filesystem_resize_class_init(GuestfsBTRFSFilesystemResizeClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_btrfs_filesystem_resize_set_property;
  object_class->get_property = guestfs_btrfs_filesystem_resize_get_property;

  /**
   * GuestfsBTRFSFilesystemResize:size:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE,
    g_param_spec_int64(
      "size",
      "size",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_btrfs_filesystem_resize_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsBTRFSFilesystemResizePrivate));
}

static void
guestfs_btrfs_filesystem_resize_init(GuestfsBTRFSFilesystemResize *o)
{
  o->priv = GUESTFS_BTRFS_FILESYSTEM_RESIZE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsBTRFSFilesystemResizePrivate));
}

/**
 * guestfs_btrfs_filesystem_resize_new:
 *
 * Create a new GuestfsBTRFSFilesystemResize object
 *
 * Returns: (transfer full): a new GuestfsBTRFSFilesystemResize object
 */
GuestfsBTRFSFilesystemResize *
guestfs_btrfs_filesystem_resize_new(void)
{
  return GUESTFS_BTRFS_FILESYSTEM_RESIZE(g_object_new(GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, NULL));
}
