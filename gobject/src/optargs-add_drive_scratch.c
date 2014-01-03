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
 * SECTION:optargs-add_drive_scratch
 * @short_description: An object encapsulating optional arguments for guestfs_session_add_drive_scratch
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_add_drive_scratch
 */

#include <string.h>

#define GUESTFS_ADD_DRIVE_SCRATCH_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DRIVE_SCRATCH, GuestfsAddDriveScratchPrivate))

struct _GuestfsAddDriveScratchPrivate {
  gchar *name;
  gchar *label;
};

G_DEFINE_TYPE(GuestfsAddDriveScratch, guestfs_add_drive_scratch, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_ADD_DRIVE_SCRATCH_PROP0,
  PROP_GUESTFS_ADD_DRIVE_SCRATCH_NAME,
  PROP_GUESTFS_ADD_DRIVE_SCRATCH_LABEL
};

static void
guestfs_add_drive_scratch_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveScratch *self = GUESTFS_ADD_DRIVE_SCRATCH(object);
  GuestfsAddDriveScratchPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_SCRATCH_NAME:
      g_free(priv->name);
      priv->name = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_SCRATCH_LABEL:
      g_free(priv->label);
      priv->label = g_value_dup_string (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_scratch_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveScratch *self = GUESTFS_ADD_DRIVE_SCRATCH(object);
  GuestfsAddDriveScratchPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_SCRATCH_NAME:
      g_value_set_string(value, priv->name);
      break;

    case PROP_GUESTFS_ADD_DRIVE_SCRATCH_LABEL:
      g_value_set_string(value, priv->label);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_scratch_finalize(GObject *object)
{
  GuestfsAddDriveScratch *self = GUESTFS_ADD_DRIVE_SCRATCH(object);
  GuestfsAddDriveScratchPrivate *priv = self->priv;

  g_free(priv->name);
  g_free(priv->label);

  G_OBJECT_CLASS(guestfs_add_drive_scratch_parent_class)->finalize(object);
}

static void
guestfs_add_drive_scratch_class_init(GuestfsAddDriveScratchClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_add_drive_scratch_set_property;
  object_class->get_property = guestfs_add_drive_scratch_get_property;

  /**
   * GuestfsAddDriveScratch:name:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_SCRATCH_NAME,
    g_param_spec_string(
      "name",
      "name",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDriveScratch:label:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DRIVE_SCRATCH_LABEL,
    g_param_spec_string(
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_add_drive_scratch_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsAddDriveScratchPrivate));
}

static void
guestfs_add_drive_scratch_init(GuestfsAddDriveScratch *o)
{
  o->priv = GUESTFS_ADD_DRIVE_SCRATCH_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsAddDriveScratchPrivate));
}

/**
 * guestfs_add_drive_scratch_new:
 *
 * Create a new GuestfsAddDriveScratch object
 *
 * Returns: (transfer full): a new GuestfsAddDriveScratch object
 */
GuestfsAddDriveScratch *
guestfs_add_drive_scratch_new(void)
{
  return GUESTFS_ADD_DRIVE_SCRATCH(g_object_new(GUESTFS_TYPE_ADD_DRIVE_SCRATCH, NULL));
}
