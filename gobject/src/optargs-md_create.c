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
 * SECTION:optargs-md_create
 * @short_description: An object encapsulating optional arguments for guestfs_session_md_create
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_md_create
 */

#include <string.h>

#define GUESTFS_MD_CREATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MD_CREATE, GuestfsMDCreatePrivate))

struct _GuestfsMDCreatePrivate {
  gint64 missingbitmap;
  gint nrdevices;
  gint spare;
  gint64 chunk;
  gchar *level;
};

G_DEFINE_TYPE(GuestfsMDCreate, guestfs_md_create, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MD_CREATE_PROP0,
  PROP_GUESTFS_MD_CREATE_MISSINGBITMAP,
  PROP_GUESTFS_MD_CREATE_NRDEVICES,
  PROP_GUESTFS_MD_CREATE_SPARE,
  PROP_GUESTFS_MD_CREATE_CHUNK,
  PROP_GUESTFS_MD_CREATE_LEVEL
};

static void
guestfs_md_create_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MD_CREATE_MISSINGBITMAP:
      priv->missingbitmap = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MD_CREATE_NRDEVICES:
      priv->nrdevices = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MD_CREATE_SPARE:
      priv->spare = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MD_CREATE_CHUNK:
      priv->chunk = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MD_CREATE_LEVEL:
      g_free(priv->level);
      priv->level = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_md_create_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MD_CREATE_MISSINGBITMAP:
      g_value_set_int64(value, priv->missingbitmap);
      break;

    case PROP_GUESTFS_MD_CREATE_NRDEVICES:
      g_value_set_int(value, priv->nrdevices);
      break;

    case PROP_GUESTFS_MD_CREATE_SPARE:
      g_value_set_int(value, priv->spare);
      break;

    case PROP_GUESTFS_MD_CREATE_CHUNK:
      g_value_set_int64(value, priv->chunk);
      break;

    case PROP_GUESTFS_MD_CREATE_LEVEL:
      g_value_set_string(value, priv->level);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_md_create_finalize(GObject *object)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  g_free(priv->level);

  G_OBJECT_CLASS(guestfs_md_create_parent_class)->finalize(object);
}

static void
guestfs_md_create_class_init(GuestfsMDCreateClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_md_create_set_property;
  object_class->get_property = guestfs_md_create_get_property;

  /**
   * GuestfsMDCreate:missingbitmap:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MD_CREATE_MISSINGBITMAP,
    g_param_spec_int64(
      "missingbitmap",
      "missingbitmap",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMDCreate:nrdevices:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MD_CREATE_NRDEVICES,
    g_param_spec_int(
      "nrdevices",
      "nrdevices",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMDCreate:spare:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MD_CREATE_SPARE,
    g_param_spec_int(
      "spare",
      "spare",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMDCreate:chunk:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MD_CREATE_CHUNK,
    g_param_spec_int64(
      "chunk",
      "chunk",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMDCreate:level:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_MD_CREATE_LEVEL,
    g_param_spec_string(
      "level",
      "level",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_md_create_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsMDCreatePrivate));
}

static void
guestfs_md_create_init(GuestfsMDCreate *o)
{
  o->priv = GUESTFS_MD_CREATE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsMDCreatePrivate));
}

/**
 * guestfs_md_create_new:
 *
 * Create a new GuestfsMDCreate object
 *
 * Returns: (transfer full): a new GuestfsMDCreate object
 */
GuestfsMDCreate *
guestfs_md_create_new(void)
{
  return GUESTFS_MD_CREATE(g_object_new(GUESTFS_TYPE_MD_CREATE, NULL));
}
