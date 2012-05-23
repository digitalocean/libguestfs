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
 * SECTION:optargs-umount_local
 * @short_description: An object encapsulating optional arguments for guestfs_session_umount_local
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_umount_local
 */

#include <string.h>

#define GUESTFS_UMOUNT_LOCAL_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_UMOUNT_LOCAL, GuestfsUmountLocalPrivate))

struct _GuestfsUmountLocalPrivate {
  GuestfsTristate retry;
};

G_DEFINE_TYPE(GuestfsUmountLocal, guestfs_umount_local, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_UMOUNT_LOCAL_PROP0,
  PROP_GUESTFS_UMOUNT_LOCAL_RETRY
};

static void
guestfs_umount_local_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsUmountLocal *self = GUESTFS_UMOUNT_LOCAL(object);
  GuestfsUmountLocalPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_UMOUNT_LOCAL_RETRY:
      priv->retry = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_umount_local_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsUmountLocal *self = GUESTFS_UMOUNT_LOCAL(object);
  GuestfsUmountLocalPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_UMOUNT_LOCAL_RETRY:
      g_value_set_enum(value, priv->retry);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_umount_local_finalize(GObject *object)
{
  GuestfsUmountLocal *self = GUESTFS_UMOUNT_LOCAL(object);
  GuestfsUmountLocalPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_umount_local_parent_class)->finalize(object);
}

static void
guestfs_umount_local_class_init(GuestfsUmountLocalClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_umount_local_set_property;
  object_class->get_property = guestfs_umount_local_get_property;

  /**
   * GuestfsUmountLocal:retry:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_UMOUNT_LOCAL_RETRY,
    g_param_spec_enum(
      "retry",
      "retry",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_umount_local_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsUmountLocalPrivate));
}

static void
guestfs_umount_local_init(GuestfsUmountLocal *o)
{
  o->priv = GUESTFS_UMOUNT_LOCAL_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsUmountLocalPrivate));
}

/**
 * guestfs_umount_local_new:
 *
 * Create a new GuestfsUmountLocal object
 *
 * Returns: (transfer full): a new GuestfsUmountLocal object
 */
GuestfsUmountLocal *
guestfs_umount_local_new(void)
{
  return GUESTFS_UMOUNT_LOCAL(g_object_new(GUESTFS_TYPE_UMOUNT_LOCAL, NULL));
}
