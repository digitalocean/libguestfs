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
 * SECTION:optargs-e2fsck
 * @short_description: An object encapsulating optional arguments for guestfs_session_e2fsck
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_e2fsck
 */

#include <string.h>

#define GUESTFS_E2FSCK_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_E2FSCK, GuestfsE2fsckPrivate))

struct _GuestfsE2fsckPrivate {
  GuestfsTristate correct;
  GuestfsTristate forceall;
};

G_DEFINE_TYPE(GuestfsE2fsck, guestfs_e2fsck, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_E2FSCK_PROP0,
  PROP_GUESTFS_E2FSCK_CORRECT,
  PROP_GUESTFS_E2FSCK_FORCEALL
};

static void
guestfs_e2fsck_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsE2fsck *self = GUESTFS_E2FSCK(object);
  GuestfsE2fsckPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_E2FSCK_CORRECT:
      priv->correct = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_E2FSCK_FORCEALL:
      priv->forceall = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_e2fsck_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsE2fsck *self = GUESTFS_E2FSCK(object);
  GuestfsE2fsckPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_E2FSCK_CORRECT:
      g_value_set_enum(value, priv->correct);
      break;

    case PROP_GUESTFS_E2FSCK_FORCEALL:
      g_value_set_enum(value, priv->forceall);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_e2fsck_finalize(GObject *object)
{
  GuestfsE2fsck *self = GUESTFS_E2FSCK(object);
  GuestfsE2fsckPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_e2fsck_parent_class)->finalize(object);
}

static void
guestfs_e2fsck_class_init(GuestfsE2fsckClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_e2fsck_set_property;
  object_class->get_property = guestfs_e2fsck_get_property;

  /**
   * GuestfsE2fsck:correct:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_E2FSCK_CORRECT,
    g_param_spec_enum(
      "correct",
      "correct",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsE2fsck:forceall:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_E2FSCK_FORCEALL,
    g_param_spec_enum(
      "forceall",
      "forceall",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_e2fsck_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsE2fsckPrivate));
}

static void
guestfs_e2fsck_init(GuestfsE2fsck *o)
{
  o->priv = GUESTFS_E2FSCK_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsE2fsckPrivate));
}

/**
 * guestfs_e2fsck_new:
 *
 * Create a new GuestfsE2fsck object
 *
 * Returns: (transfer full): a new GuestfsE2fsck object
 */
GuestfsE2fsck *
guestfs_e2fsck_new(void)
{
  return GUESTFS_E2FSCK(g_object_new(GUESTFS_TYPE_E2FSCK, NULL));
}
