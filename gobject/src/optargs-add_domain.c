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
 * SECTION:optargs-add_domain
 * @short_description: An object encapsulating optional arguments for guestfs_session_add_domain
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_add_domain
 */

#include <string.h>

#define GUESTFS_ADD_DOMAIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DOMAIN, GuestfsAddDomainPrivate))

struct _GuestfsAddDomainPrivate {
  gchar *libvirturi;
  GuestfsTristate readonly;
  gchar *iface;
  GuestfsTristate live;
  GuestfsTristate allowuuid;
  gchar *readonlydisk;
};

G_DEFINE_TYPE(GuestfsAddDomain, guestfs_add_domain, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_ADD_DOMAIN_PROP0,
  PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI,
  PROP_GUESTFS_ADD_DOMAIN_READONLY,
  PROP_GUESTFS_ADD_DOMAIN_IFACE,
  PROP_GUESTFS_ADD_DOMAIN_LIVE,
  PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID,
  PROP_GUESTFS_ADD_DOMAIN_READONLYDISK
};

static void
guestfs_add_domain_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      g_free(priv->libvirturi);
      priv->libvirturi = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLY:
      priv->readonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_IFACE:
      g_free(priv->iface);
      priv->iface = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_LIVE:
      priv->live = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID:
      priv->allowuuid = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLYDISK:
      g_free(priv->readonlydisk);
      priv->readonlydisk = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_domain_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      g_value_set_string(value, priv->libvirturi);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLY:
      g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_IFACE:
      g_value_set_string(value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_LIVE:
      g_value_set_enum(value, priv->live);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID:
      g_value_set_enum(value, priv->allowuuid);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLYDISK:
      g_value_set_string(value, priv->readonlydisk);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_domain_finalize(GObject *object)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  g_free(priv->libvirturi);
  g_free(priv->iface);
  g_free(priv->readonlydisk);

  G_OBJECT_CLASS(guestfs_add_domain_parent_class)->finalize(object);
}

static void
guestfs_add_domain_class_init(GuestfsAddDomainClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  object_class->set_property = guestfs_add_domain_set_property;
  object_class->get_property = guestfs_add_domain_get_property;

  /**
   * GuestfsAddDomain:libvirturi:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI,
    g_param_spec_string(
      "libvirturi",
      "libvirturi",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDomain:readonly:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_READONLY,
    g_param_spec_enum(
      "readonly",
      "readonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDomain:iface:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_IFACE,
    g_param_spec_string(
      "iface",
      "iface",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDomain:live:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_LIVE,
    g_param_spec_enum(
      "live",
      "live",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDomain:allowuuid:
   *
   * A boolean.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID,
    g_param_spec_enum(
      "allowuuid",
      "allowuuid",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddDomain:readonlydisk:
   *
   * A string.
   */
  g_object_class_install_property(
    object_class,
    PROP_GUESTFS_ADD_DOMAIN_READONLYDISK,
    g_param_spec_string(
      "readonlydisk",
      "readonlydisk",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_add_domain_finalize;
  g_type_class_add_private(klass, sizeof(GuestfsAddDomainPrivate));
}

static void
guestfs_add_domain_init(GuestfsAddDomain *o)
{
  o->priv = GUESTFS_ADD_DOMAIN_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof(GuestfsAddDomainPrivate));
}

/**
 * guestfs_add_domain_new:
 *
 * Create a new GuestfsAddDomain object
 *
 * Returns: (transfer full): a new GuestfsAddDomain object
 */
GuestfsAddDomain *
guestfs_add_domain_new(void)
{
  return GUESTFS_ADD_DOMAIN(g_object_new(GUESTFS_TYPE_ADD_DOMAIN, NULL));
}
