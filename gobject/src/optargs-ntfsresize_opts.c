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

#include "guestfs-gobject.h"

/**
 * SECTION:optargs-ntfsresize_opts
 * @short_description: An object encapsulating optional arguments for guestfs_session_ntfsresize_opts
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_ntfsresize_opts
 */

#include <string.h>

#define GUESTFS_NTFSRESIZE_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsPrivate))

struct _GuestfsNTFSResizeOptsPrivate {
  gint64 size;
  GuestfsTristate force;
};

G_DEFINE_TYPE(GuestfsNTFSResizeOpts, guestfs_ntfsresize_opts, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_NTFSRESIZE_OPTS_PROP0,
  PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE,
  PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE
};

static void
guestfs_ntfsresize_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE:
      priv->force = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsresize_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE:
      g_value_set_int64(value, priv->size);
      break;

    case PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE:
      g_value_set_enum(value, priv->force);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsresize_opts_finalize(GObject *object)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_ntfsresize_opts_parent_class)->finalize(object);
}

static void
guestfs_ntfsresize_opts_class_init(GuestfsNTFSResizeOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_ntfsresize_opts_set_property;
  object_class->get_property = guestfs_ntfsresize_opts_get_property;

  /**
   * GuestfsNTFSResizeOpts:size:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE,
    g_param_spec_int64(
      "size",
      "size",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsNTFSResizeOpts:force:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE,
    g_param_spec_enum(
      "force",
      "force",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_ntfsresize_opts_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsNTFSResizeOptsPrivate));
}

static void
guestfs_ntfsresize_opts_init(GuestfsNTFSResizeOpts *o)
{
  o->priv = GUESTFS_NTFSRESIZE_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsNTFSResizeOptsPrivate));
}

/**
 * guestfs_ntfsresize_opts_new:
 *
 * Create a new GuestfsNTFSResizeOpts object
 *
 * Returns: (transfer full): a new GuestfsNTFSResizeOpts object
 */
GuestfsNTFSResizeOpts *
guestfs_ntfsresize_opts_new(void)
{
  return GUESTFS_NTFSRESIZE_OPTS(g_object_new(GUESTFS_TYPE_NTFSRESIZE_OPTS, NULL));
}
