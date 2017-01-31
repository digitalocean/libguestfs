/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
 * SECTION:optargs-disk_create
 * @short_description: An object encapsulating optional arguments for guestfs_session_disk_create
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_disk_create
 */

#include <string.h>

#define GUESTFS_DISK_CREATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_DISK_CREATE, GuestfsDiskCreatePrivate))

struct _GuestfsDiskCreatePrivate {
  gchar *backingfile;
  gchar *backingformat;
  gchar *preallocation;
  gchar *compat;
  gint clustersize;
};

G_DEFINE_TYPE (GuestfsDiskCreate, guestfs_disk_create, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_DISK_CREATE_PROP0,
  PROP_GUESTFS_DISK_CREATE_BACKINGFILE,
  PROP_GUESTFS_DISK_CREATE_BACKINGFORMAT,
  PROP_GUESTFS_DISK_CREATE_PREALLOCATION,
  PROP_GUESTFS_DISK_CREATE_COMPAT,
  PROP_GUESTFS_DISK_CREATE_CLUSTERSIZE
};

static void
guestfs_disk_create_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsDiskCreate *self = GUESTFS_DISK_CREATE (object);
  GuestfsDiskCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_DISK_CREATE_BACKINGFILE:
      g_free (priv->backingfile);
      priv->backingfile = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_DISK_CREATE_BACKINGFORMAT:
      g_free (priv->backingformat);
      priv->backingformat = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_DISK_CREATE_PREALLOCATION:
      g_free (priv->preallocation);
      priv->preallocation = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_DISK_CREATE_COMPAT:
      g_free (priv->compat);
      priv->compat = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_DISK_CREATE_CLUSTERSIZE:
      priv->clustersize = g_value_get_int (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_disk_create_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsDiskCreate *self = GUESTFS_DISK_CREATE (object);
  GuestfsDiskCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_DISK_CREATE_BACKINGFILE:
      g_value_set_string (value, priv->backingfile);
      break;

    case PROP_GUESTFS_DISK_CREATE_BACKINGFORMAT:
      g_value_set_string (value, priv->backingformat);
      break;

    case PROP_GUESTFS_DISK_CREATE_PREALLOCATION:
      g_value_set_string (value, priv->preallocation);
      break;

    case PROP_GUESTFS_DISK_CREATE_COMPAT:
      g_value_set_string (value, priv->compat);
      break;

    case PROP_GUESTFS_DISK_CREATE_CLUSTERSIZE:
      g_value_set_int (value, priv->clustersize);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_disk_create_finalize (GObject *object)
{
  GuestfsDiskCreate *self = GUESTFS_DISK_CREATE (object);
  GuestfsDiskCreatePrivate *priv = self->priv;

  g_free (priv->backingfile);
  g_free (priv->backingformat);
  g_free (priv->preallocation);
  g_free (priv->compat);
  G_OBJECT_CLASS (guestfs_disk_create_parent_class)->finalize (object);
}

static void
guestfs_disk_create_class_init (GuestfsDiskCreateClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_disk_create_set_property;
  object_class->get_property = guestfs_disk_create_get_property;

  /**
   * GuestfsDiskCreate:backingfile:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DISK_CREATE_BACKINGFILE,
    g_param_spec_string (
      "backingfile",
      "backingfile",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsDiskCreate:backingformat:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DISK_CREATE_BACKINGFORMAT,
    g_param_spec_string (
      "backingformat",
      "backingformat",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsDiskCreate:preallocation:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DISK_CREATE_PREALLOCATION,
    g_param_spec_string (
      "preallocation",
      "preallocation",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsDiskCreate:compat:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DISK_CREATE_COMPAT,
    g_param_spec_string (
      "compat",
      "compat",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsDiskCreate:clustersize:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_DISK_CREATE_CLUSTERSIZE,
    g_param_spec_int (
      "clustersize",
      "clustersize",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_disk_create_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsDiskCreatePrivate));
}

static void
guestfs_disk_create_init (GuestfsDiskCreate *o)
{
  o->priv = GUESTFS_DISK_CREATE_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsDiskCreatePrivate));
}

/**
 * guestfs_disk_create_new:
 *
 * Create a new GuestfsDiskCreate object
 *
 * Returns: (transfer full): a new GuestfsDiskCreate object
 */
GuestfsDiskCreate *
guestfs_disk_create_new (void)
{
  return GUESTFS_DISK_CREATE (g_object_new (GUESTFS_TYPE_DISK_CREATE, NULL));
}
