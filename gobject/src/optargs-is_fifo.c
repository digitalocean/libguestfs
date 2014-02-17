/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
 * SECTION:optargs-is_fifo
 * @short_description: An object encapsulating optional arguments for guestfs_session_is_fifo
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_is_fifo
 */

#include <string.h>

#define GUESTFS_IS_FIFO_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_IS_FIFO, GuestfsIsFifoPrivate))

struct _GuestfsIsFifoPrivate {
  GuestfsTristate followsymlinks;
};

G_DEFINE_TYPE (GuestfsIsFifo, guestfs_is_fifo, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_IS_FIFO_PROP0,
  PROP_GUESTFS_IS_FIFO_FOLLOWSYMLINKS
};

static void
guestfs_is_fifo_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsIsFifo *self = GUESTFS_IS_FIFO (object);
  GuestfsIsFifoPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_IS_FIFO_FOLLOWSYMLINKS:
      priv->followsymlinks = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_is_fifo_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsIsFifo *self = GUESTFS_IS_FIFO (object);
  GuestfsIsFifoPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_IS_FIFO_FOLLOWSYMLINKS:
      g_value_set_enum (value, priv->followsymlinks);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_is_fifo_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_is_fifo_parent_class)->finalize (object);
}

static void
guestfs_is_fifo_class_init (GuestfsIsFifoClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_is_fifo_set_property;
  object_class->get_property = guestfs_is_fifo_get_property;

  /**
   * GuestfsIsFifo:followsymlinks:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_IS_FIFO_FOLLOWSYMLINKS,
    g_param_spec_enum (
      "followsymlinks",
      "followsymlinks",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_is_fifo_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsIsFifoPrivate));
}

static void
guestfs_is_fifo_init (GuestfsIsFifo *o)
{
  o->priv = GUESTFS_IS_FIFO_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsIsFifoPrivate));
}

/**
 * guestfs_is_fifo_new:
 *
 * Create a new GuestfsIsFifo object
 *
 * Returns: (transfer full): a new GuestfsIsFifo object
 */
GuestfsIsFifo *
guestfs_is_fifo_new (void)
{
  return GUESTFS_IS_FIFO (g_object_new (GUESTFS_TYPE_IS_FIFO, NULL));
}
