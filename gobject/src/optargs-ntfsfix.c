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
 * SECTION:optargs-ntfsfix
 * @short_description: An object encapsulating optional arguments for guestfs_session_ntfsfix
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_ntfsfix
 */

#include <string.h>

#define GUESTFS_NTFSFIX_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_NTFSFIX, GuestfsNtfsfixPrivate))

struct _GuestfsNtfsfixPrivate {
  GuestfsTristate clearbadsectors;
};

G_DEFINE_TYPE(GuestfsNtfsfix, guestfs_ntfsfix, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_NTFSFIX_PROP0,
  PROP_GUESTFS_NTFSFIX_CLEARBADSECTORS
};

static void
guestfs_ntfsfix_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsNtfsfix *self = GUESTFS_NTFSFIX(object);
  GuestfsNtfsfixPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSFIX_CLEARBADSECTORS:
      priv->clearbadsectors = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsfix_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsNtfsfix *self = GUESTFS_NTFSFIX(object);
  GuestfsNtfsfixPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSFIX_CLEARBADSECTORS:
      g_value_set_enum(value, priv->clearbadsectors);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsfix_finalize(GObject *object)
{
  GuestfsNtfsfix *self = GUESTFS_NTFSFIX(object);
  GuestfsNtfsfixPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_ntfsfix_parent_class)->finalize(object);
}

static void
guestfs_ntfsfix_class_init(GuestfsNtfsfixClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_ntfsfix_set_property;
  object_class->get_property = guestfs_ntfsfix_get_property;

  /**
   * GuestfsNtfsfix:clearbadsectors:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_NTFSFIX_CLEARBADSECTORS,
    g_param_spec_enum(
      "clearbadsectors",
      "clearbadsectors",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_ntfsfix_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsNtfsfixPrivate));
}

static void
guestfs_ntfsfix_init(GuestfsNtfsfix *o)
{
  o->priv = GUESTFS_NTFSFIX_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsNtfsfixPrivate));
}

/**
 * guestfs_ntfsfix_new:
 *
 * Create a new GuestfsNtfsfix object
 *
 * Returns: (transfer full): a new GuestfsNtfsfix object
 */
GuestfsNtfsfix *
guestfs_ntfsfix_new(void)
{
  return GUESTFS_NTFSFIX(g_object_new(GUESTFS_TYPE_NTFSFIX, NULL));
}
