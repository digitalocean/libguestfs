/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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
 * SECTION:optargs-mktemp
 * @short_description: An object encapsulating optional arguments for guestfs_session_mktemp
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mktemp
 */

#include <string.h>

#define GUESTFS_MKTEMP_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_MKTEMP, GuestfsMktempPrivate))

struct _GuestfsMktempPrivate {
  gchar *suffix;
};

G_DEFINE_TYPE (GuestfsMktemp, guestfs_mktemp, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKTEMP_PROP0,
  PROP_GUESTFS_MKTEMP_SUFFIX
};

static void
guestfs_mktemp_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMktemp *self = GUESTFS_MKTEMP (object);
  GuestfsMktempPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKTEMP_SUFFIX:
      g_free (priv->suffix);
      priv->suffix = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mktemp_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMktemp *self = GUESTFS_MKTEMP (object);
  GuestfsMktempPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKTEMP_SUFFIX:
      g_value_set_string (value, priv->suffix);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mktemp_finalize (GObject *object)
{
  GuestfsMktemp *self = GUESTFS_MKTEMP (object);
  GuestfsMktempPrivate *priv = self->priv;

  g_free (priv->suffix);
  G_OBJECT_CLASS (guestfs_mktemp_parent_class)->finalize (object);
}

static void
guestfs_mktemp_class_init (GuestfsMktempClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_mktemp_set_property;
  object_class->get_property = guestfs_mktemp_get_property;

  /**
   * GuestfsMktemp:suffix:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKTEMP_SUFFIX,
    g_param_spec_string (
      "suffix",
      "suffix",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mktemp_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsMktempPrivate));
}

static void
guestfs_mktemp_init (GuestfsMktemp *o)
{
  o->priv = GUESTFS_MKTEMP_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsMktempPrivate));
}

/**
 * guestfs_mktemp_new:
 *
 * Create a new GuestfsMktemp object
 *
 * Returns: (transfer full): a new GuestfsMktemp object
 */
GuestfsMktemp *
guestfs_mktemp_new (void)
{
  return GUESTFS_MKTEMP (g_object_new (GUESTFS_TYPE_MKTEMP, NULL));
}
