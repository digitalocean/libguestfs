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
 * SECTION:optargs-hivex_open
 * @short_description: An object encapsulating optional arguments for guestfs_session_hivex_open
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_hivex_open
 */

#include <string.h>

#define GUESTFS_HIVEX_OPEN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_HIVEX_OPEN, GuestfsHivexOpenPrivate))

struct _GuestfsHivexOpenPrivate {
  GuestfsTristate verbose;
  GuestfsTristate debug;
  GuestfsTristate write;
};

G_DEFINE_TYPE (GuestfsHivexOpen, guestfs_hivex_open, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_HIVEX_OPEN_PROP0,
  PROP_GUESTFS_HIVEX_OPEN_VERBOSE,
  PROP_GUESTFS_HIVEX_OPEN_DEBUG,
  PROP_GUESTFS_HIVEX_OPEN_WRITE
};

static void
guestfs_hivex_open_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsHivexOpen *self = GUESTFS_HIVEX_OPEN (object);
  GuestfsHivexOpenPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_HIVEX_OPEN_VERBOSE:
      priv->verbose = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_HIVEX_OPEN_DEBUG:
      priv->debug = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_HIVEX_OPEN_WRITE:
      priv->write = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_hivex_open_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsHivexOpen *self = GUESTFS_HIVEX_OPEN (object);
  GuestfsHivexOpenPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_HIVEX_OPEN_VERBOSE:
      g_value_set_enum (value, priv->verbose);
      break;

    case PROP_GUESTFS_HIVEX_OPEN_DEBUG:
      g_value_set_enum (value, priv->debug);
      break;

    case PROP_GUESTFS_HIVEX_OPEN_WRITE:
      g_value_set_enum (value, priv->write);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_hivex_open_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_hivex_open_parent_class)->finalize (object);
}

static void
guestfs_hivex_open_class_init (GuestfsHivexOpenClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_hivex_open_set_property;
  object_class->get_property = guestfs_hivex_open_get_property;

  /**
   * GuestfsHivexOpen:verbose:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_HIVEX_OPEN_VERBOSE,
    g_param_spec_enum (
      "verbose",
      "verbose",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsHivexOpen:debug:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_HIVEX_OPEN_DEBUG,
    g_param_spec_enum (
      "debug",
      "debug",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsHivexOpen:write:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_HIVEX_OPEN_WRITE,
    g_param_spec_enum (
      "write",
      "write",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_hivex_open_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsHivexOpenPrivate));
}

static void
guestfs_hivex_open_init (GuestfsHivexOpen *o)
{
  o->priv = GUESTFS_HIVEX_OPEN_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsHivexOpenPrivate));
}

/**
 * guestfs_hivex_open_new:
 *
 * Create a new GuestfsHivexOpen object
 *
 * Returns: (transfer full): a new GuestfsHivexOpen object
 */
GuestfsHivexOpen *
guestfs_hivex_open_new (void)
{
  return GUESTFS_HIVEX_OPEN (g_object_new (GUESTFS_TYPE_HIVEX_OPEN, NULL));
}
