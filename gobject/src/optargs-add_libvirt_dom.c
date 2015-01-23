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
 * SECTION:optargs-add_libvirt_dom
 * @short_description: An object encapsulating optional arguments for guestfs_session_add_libvirt_dom
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_add_libvirt_dom
 */

#include <string.h>

#define GUESTFS_ADD_LIBVIRT_DOM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_ADD_LIBVIRT_DOM, GuestfsAddLibvirtDomPrivate))

struct _GuestfsAddLibvirtDomPrivate {
  GuestfsTristate readonly;
  gchar *iface;
  GuestfsTristate live;
  gchar *readonlydisk;
  gchar *cachemode;
  gchar *discard;
  GuestfsTristate copyonread;
};

G_DEFINE_TYPE (GuestfsAddLibvirtDom, guestfs_add_libvirt_dom, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_ADD_LIBVIRT_DOM_PROP0,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLY,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_IFACE,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_LIVE,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_DISCARD,
  PROP_GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD
};

static void
guestfs_add_libvirt_dom_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddLibvirtDom *self = GUESTFS_ADD_LIBVIRT_DOM (object);
  GuestfsAddLibvirtDomPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLY:
      priv->readonly = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_IFACE:
      g_free (priv->iface);
      priv->iface = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_LIVE:
      priv->live = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK:
      g_free (priv->readonlydisk);
      priv->readonlydisk = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE:
      g_free (priv->cachemode);
      priv->cachemode = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_DISCARD:
      g_free (priv->discard);
      priv->discard = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD:
      priv->copyonread = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_add_libvirt_dom_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddLibvirtDom *self = GUESTFS_ADD_LIBVIRT_DOM (object);
  GuestfsAddLibvirtDomPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLY:
      g_value_set_enum (value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_IFACE:
      g_value_set_string (value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_LIVE:
      g_value_set_enum (value, priv->live);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK:
      g_value_set_string (value, priv->readonlydisk);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE:
      g_value_set_string (value, priv->cachemode);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_DISCARD:
      g_value_set_string (value, priv->discard);
      break;

    case PROP_GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD:
      g_value_set_enum (value, priv->copyonread);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_add_libvirt_dom_finalize (GObject *object)
{
  GuestfsAddLibvirtDom *self = GUESTFS_ADD_LIBVIRT_DOM (object);
  GuestfsAddLibvirtDomPrivate *priv = self->priv;

  g_free (priv->iface);
  g_free (priv->readonlydisk);
  g_free (priv->cachemode);
  g_free (priv->discard);
  G_OBJECT_CLASS (guestfs_add_libvirt_dom_parent_class)->finalize (object);
}

static void
guestfs_add_libvirt_dom_class_init (GuestfsAddLibvirtDomClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_add_libvirt_dom_set_property;
  object_class->get_property = guestfs_add_libvirt_dom_get_property;

  /**
   * GuestfsAddLibvirtDom:readonly:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLY,
    g_param_spec_enum (
      "readonly",
      "readonly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:iface:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_IFACE,
    g_param_spec_string (
      "iface",
      "iface",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:live:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_LIVE,
    g_param_spec_enum (
      "live",
      "live",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:readonlydisk:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK,
    g_param_spec_string (
      "readonlydisk",
      "readonlydisk",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:cachemode:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE,
    g_param_spec_string (
      "cachemode",
      "cachemode",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:discard:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_DISCARD,
    g_param_spec_string (
      "discard",
      "discard",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsAddLibvirtDom:copyonread:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD,
    g_param_spec_enum (
      "copyonread",
      "copyonread",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_add_libvirt_dom_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsAddLibvirtDomPrivate));
}

static void
guestfs_add_libvirt_dom_init (GuestfsAddLibvirtDom *o)
{
  o->priv = GUESTFS_ADD_LIBVIRT_DOM_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsAddLibvirtDomPrivate));
}

/**
 * guestfs_add_libvirt_dom_new:
 *
 * Create a new GuestfsAddLibvirtDom object
 *
 * Returns: (transfer full): a new GuestfsAddLibvirtDom object
 */
GuestfsAddLibvirtDom *
guestfs_add_libvirt_dom_new (void)
{
  return GUESTFS_ADD_LIBVIRT_DOM (g_object_new (GUESTFS_TYPE_ADD_LIBVIRT_DOM, NULL));
}
