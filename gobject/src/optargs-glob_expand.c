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
 * SECTION:optargs-glob_expand
 * @short_description: An object encapsulating optional arguments for guestfs_session_glob_expand
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_glob_expand
 */

#include <string.h>

#define GUESTFS_GLOB_EXPAND_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_GLOB_EXPAND, GuestfsGlobExpandPrivate))

struct _GuestfsGlobExpandPrivate {
  GuestfsTristate directoryslash;
};

G_DEFINE_TYPE (GuestfsGlobExpand, guestfs_glob_expand, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_GLOB_EXPAND_PROP0,
  PROP_GUESTFS_GLOB_EXPAND_DIRECTORYSLASH
};

static void
guestfs_glob_expand_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsGlobExpand *self = GUESTFS_GLOB_EXPAND (object);
  GuestfsGlobExpandPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_GLOB_EXPAND_DIRECTORYSLASH:
      priv->directoryslash = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_glob_expand_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsGlobExpand *self = GUESTFS_GLOB_EXPAND (object);
  GuestfsGlobExpandPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_GLOB_EXPAND_DIRECTORYSLASH:
      g_value_set_enum (value, priv->directoryslash);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_glob_expand_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_glob_expand_parent_class)->finalize (object);
}

static void
guestfs_glob_expand_class_init (GuestfsGlobExpandClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_glob_expand_set_property;
  object_class->get_property = guestfs_glob_expand_get_property;

  /**
   * GuestfsGlobExpand:directoryslash:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_GLOB_EXPAND_DIRECTORYSLASH,
    g_param_spec_enum (
      "directoryslash",
      "directoryslash",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_glob_expand_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsGlobExpandPrivate));
}

static void
guestfs_glob_expand_init (GuestfsGlobExpand *o)
{
  o->priv = GUESTFS_GLOB_EXPAND_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsGlobExpandPrivate));
}

/**
 * guestfs_glob_expand_new:
 *
 * Create a new GuestfsGlobExpand object
 *
 * Returns: (transfer full): a new GuestfsGlobExpand object
 */
GuestfsGlobExpand *
guestfs_glob_expand_new (void)
{
  return GUESTFS_GLOB_EXPAND (g_object_new (GUESTFS_TYPE_GLOB_EXPAND, NULL));
}
