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
 * SECTION:optargs-internal_test_63_optargs
 * @short_description: An object encapsulating optional arguments for guestfs_session_internal_test_63_optargs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_internal_test_63_optargs
 */

#include <string.h>

#define GUESTFS_INTERNAL_TEST_63_OPTARGS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_INTERNAL_TEST_63_OPTARGS, GuestfsInternalTest63OptargsPrivate))

struct _GuestfsInternalTest63OptargsPrivate {
  gint opt1;
  gint opt2;
  gint opt3;
  gint opt4;
  gint opt5;
  gint opt6;
  gint opt7;
  gint opt8;
  gint opt9;
  gint opt10;
  gint opt11;
  gint opt12;
  gint opt13;
  gint opt14;
  gint opt15;
  gint opt16;
  gint opt17;
  gint opt18;
  gint opt19;
  gint opt20;
  gint opt21;
  gint opt22;
  gint opt23;
  gint opt24;
  gint opt25;
  gint opt26;
  gint opt27;
  gint opt28;
  gint opt29;
  gint opt30;
  gint opt31;
  gint opt32;
  gint opt33;
  gint opt34;
  gint opt35;
  gint opt36;
  gint opt37;
  gint opt38;
  gint opt39;
  gint opt40;
  gint opt41;
  gint opt42;
  gint opt43;
  gint opt44;
  gint opt45;
  gint opt46;
  gint opt47;
  gint opt48;
  gint opt49;
  gint opt50;
  gint opt51;
  gint opt52;
  gint opt53;
  gint opt54;
  gint opt55;
  gint opt56;
  gint opt57;
  gint opt58;
  gint opt59;
  gint opt60;
  gint opt61;
  gint opt62;
  gint opt63;
};

G_DEFINE_TYPE (GuestfsInternalTest63Optargs, guestfs_internal_test_63_optargs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_PROP0,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62,
  PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63
};

static void
guestfs_internal_test_63_optargs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTest63Optargs *self = GUESTFS_INTERNAL_TEST_63_OPTARGS (object);
  GuestfsInternalTest63OptargsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1:
      priv->opt1 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2:
      priv->opt2 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3:
      priv->opt3 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4:
      priv->opt4 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5:
      priv->opt5 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6:
      priv->opt6 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7:
      priv->opt7 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8:
      priv->opt8 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9:
      priv->opt9 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10:
      priv->opt10 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11:
      priv->opt11 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12:
      priv->opt12 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13:
      priv->opt13 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14:
      priv->opt14 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15:
      priv->opt15 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16:
      priv->opt16 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17:
      priv->opt17 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18:
      priv->opt18 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19:
      priv->opt19 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20:
      priv->opt20 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21:
      priv->opt21 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22:
      priv->opt22 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23:
      priv->opt23 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24:
      priv->opt24 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25:
      priv->opt25 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26:
      priv->opt26 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27:
      priv->opt27 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28:
      priv->opt28 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29:
      priv->opt29 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30:
      priv->opt30 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31:
      priv->opt31 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32:
      priv->opt32 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33:
      priv->opt33 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34:
      priv->opt34 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35:
      priv->opt35 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36:
      priv->opt36 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37:
      priv->opt37 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38:
      priv->opt38 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39:
      priv->opt39 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40:
      priv->opt40 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41:
      priv->opt41 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42:
      priv->opt42 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43:
      priv->opt43 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44:
      priv->opt44 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45:
      priv->opt45 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46:
      priv->opt46 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47:
      priv->opt47 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48:
      priv->opt48 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49:
      priv->opt49 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50:
      priv->opt50 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51:
      priv->opt51 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52:
      priv->opt52 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53:
      priv->opt53 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54:
      priv->opt54 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55:
      priv->opt55 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56:
      priv->opt56 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57:
      priv->opt57 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58:
      priv->opt58 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59:
      priv->opt59 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60:
      priv->opt60 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61:
      priv->opt61 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62:
      priv->opt62 = g_value_get_int (value);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63:
      priv->opt63 = g_value_get_int (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_internal_test_63_optargs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsInternalTest63Optargs *self = GUESTFS_INTERNAL_TEST_63_OPTARGS (object);
  GuestfsInternalTest63OptargsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1:
      g_value_set_int (value, priv->opt1);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2:
      g_value_set_int (value, priv->opt2);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3:
      g_value_set_int (value, priv->opt3);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4:
      g_value_set_int (value, priv->opt4);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5:
      g_value_set_int (value, priv->opt5);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6:
      g_value_set_int (value, priv->opt6);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7:
      g_value_set_int (value, priv->opt7);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8:
      g_value_set_int (value, priv->opt8);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9:
      g_value_set_int (value, priv->opt9);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10:
      g_value_set_int (value, priv->opt10);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11:
      g_value_set_int (value, priv->opt11);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12:
      g_value_set_int (value, priv->opt12);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13:
      g_value_set_int (value, priv->opt13);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14:
      g_value_set_int (value, priv->opt14);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15:
      g_value_set_int (value, priv->opt15);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16:
      g_value_set_int (value, priv->opt16);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17:
      g_value_set_int (value, priv->opt17);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18:
      g_value_set_int (value, priv->opt18);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19:
      g_value_set_int (value, priv->opt19);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20:
      g_value_set_int (value, priv->opt20);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21:
      g_value_set_int (value, priv->opt21);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22:
      g_value_set_int (value, priv->opt22);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23:
      g_value_set_int (value, priv->opt23);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24:
      g_value_set_int (value, priv->opt24);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25:
      g_value_set_int (value, priv->opt25);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26:
      g_value_set_int (value, priv->opt26);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27:
      g_value_set_int (value, priv->opt27);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28:
      g_value_set_int (value, priv->opt28);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29:
      g_value_set_int (value, priv->opt29);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30:
      g_value_set_int (value, priv->opt30);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31:
      g_value_set_int (value, priv->opt31);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32:
      g_value_set_int (value, priv->opt32);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33:
      g_value_set_int (value, priv->opt33);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34:
      g_value_set_int (value, priv->opt34);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35:
      g_value_set_int (value, priv->opt35);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36:
      g_value_set_int (value, priv->opt36);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37:
      g_value_set_int (value, priv->opt37);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38:
      g_value_set_int (value, priv->opt38);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39:
      g_value_set_int (value, priv->opt39);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40:
      g_value_set_int (value, priv->opt40);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41:
      g_value_set_int (value, priv->opt41);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42:
      g_value_set_int (value, priv->opt42);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43:
      g_value_set_int (value, priv->opt43);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44:
      g_value_set_int (value, priv->opt44);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45:
      g_value_set_int (value, priv->opt45);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46:
      g_value_set_int (value, priv->opt46);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47:
      g_value_set_int (value, priv->opt47);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48:
      g_value_set_int (value, priv->opt48);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49:
      g_value_set_int (value, priv->opt49);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50:
      g_value_set_int (value, priv->opt50);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51:
      g_value_set_int (value, priv->opt51);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52:
      g_value_set_int (value, priv->opt52);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53:
      g_value_set_int (value, priv->opt53);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54:
      g_value_set_int (value, priv->opt54);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55:
      g_value_set_int (value, priv->opt55);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56:
      g_value_set_int (value, priv->opt56);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57:
      g_value_set_int (value, priv->opt57);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58:
      g_value_set_int (value, priv->opt58);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59:
      g_value_set_int (value, priv->opt59);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60:
      g_value_set_int (value, priv->opt60);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61:
      g_value_set_int (value, priv->opt61);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62:
      g_value_set_int (value, priv->opt62);
      break;

    case PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63:
      g_value_set_int (value, priv->opt63);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_internal_test_63_optargs_finalize (GObject *object)
{
  G_OBJECT_CLASS (guestfs_internal_test_63_optargs_parent_class)->finalize (object);
}

static void
guestfs_internal_test_63_optargs_class_init (GuestfsInternalTest63OptargsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_internal_test_63_optargs_set_property;
  object_class->get_property = guestfs_internal_test_63_optargs_get_property;

  /**
   * GuestfsInternalTest63Optargs:opt1:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1,
    g_param_spec_int (
      "opt1",
      "opt1",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt2:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2,
    g_param_spec_int (
      "opt2",
      "opt2",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt3:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3,
    g_param_spec_int (
      "opt3",
      "opt3",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt4:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4,
    g_param_spec_int (
      "opt4",
      "opt4",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt5:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5,
    g_param_spec_int (
      "opt5",
      "opt5",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt6:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6,
    g_param_spec_int (
      "opt6",
      "opt6",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt7:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7,
    g_param_spec_int (
      "opt7",
      "opt7",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt8:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8,
    g_param_spec_int (
      "opt8",
      "opt8",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt9:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9,
    g_param_spec_int (
      "opt9",
      "opt9",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt10:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10,
    g_param_spec_int (
      "opt10",
      "opt10",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt11:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11,
    g_param_spec_int (
      "opt11",
      "opt11",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt12:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12,
    g_param_spec_int (
      "opt12",
      "opt12",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt13:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13,
    g_param_spec_int (
      "opt13",
      "opt13",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt14:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14,
    g_param_spec_int (
      "opt14",
      "opt14",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt15:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15,
    g_param_spec_int (
      "opt15",
      "opt15",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt16:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16,
    g_param_spec_int (
      "opt16",
      "opt16",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt17:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17,
    g_param_spec_int (
      "opt17",
      "opt17",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt18:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18,
    g_param_spec_int (
      "opt18",
      "opt18",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt19:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19,
    g_param_spec_int (
      "opt19",
      "opt19",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt20:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20,
    g_param_spec_int (
      "opt20",
      "opt20",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt21:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21,
    g_param_spec_int (
      "opt21",
      "opt21",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt22:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22,
    g_param_spec_int (
      "opt22",
      "opt22",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt23:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23,
    g_param_spec_int (
      "opt23",
      "opt23",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt24:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24,
    g_param_spec_int (
      "opt24",
      "opt24",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt25:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25,
    g_param_spec_int (
      "opt25",
      "opt25",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt26:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26,
    g_param_spec_int (
      "opt26",
      "opt26",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt27:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27,
    g_param_spec_int (
      "opt27",
      "opt27",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt28:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28,
    g_param_spec_int (
      "opt28",
      "opt28",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt29:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29,
    g_param_spec_int (
      "opt29",
      "opt29",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt30:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30,
    g_param_spec_int (
      "opt30",
      "opt30",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt31:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31,
    g_param_spec_int (
      "opt31",
      "opt31",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt32:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32,
    g_param_spec_int (
      "opt32",
      "opt32",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt33:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33,
    g_param_spec_int (
      "opt33",
      "opt33",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt34:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34,
    g_param_spec_int (
      "opt34",
      "opt34",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt35:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35,
    g_param_spec_int (
      "opt35",
      "opt35",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt36:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36,
    g_param_spec_int (
      "opt36",
      "opt36",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt37:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37,
    g_param_spec_int (
      "opt37",
      "opt37",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt38:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38,
    g_param_spec_int (
      "opt38",
      "opt38",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt39:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39,
    g_param_spec_int (
      "opt39",
      "opt39",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt40:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40,
    g_param_spec_int (
      "opt40",
      "opt40",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt41:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41,
    g_param_spec_int (
      "opt41",
      "opt41",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt42:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42,
    g_param_spec_int (
      "opt42",
      "opt42",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt43:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43,
    g_param_spec_int (
      "opt43",
      "opt43",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt44:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44,
    g_param_spec_int (
      "opt44",
      "opt44",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt45:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45,
    g_param_spec_int (
      "opt45",
      "opt45",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt46:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46,
    g_param_spec_int (
      "opt46",
      "opt46",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt47:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47,
    g_param_spec_int (
      "opt47",
      "opt47",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt48:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48,
    g_param_spec_int (
      "opt48",
      "opt48",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt49:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49,
    g_param_spec_int (
      "opt49",
      "opt49",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt50:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50,
    g_param_spec_int (
      "opt50",
      "opt50",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt51:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51,
    g_param_spec_int (
      "opt51",
      "opt51",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt52:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52,
    g_param_spec_int (
      "opt52",
      "opt52",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt53:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53,
    g_param_spec_int (
      "opt53",
      "opt53",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt54:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54,
    g_param_spec_int (
      "opt54",
      "opt54",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt55:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55,
    g_param_spec_int (
      "opt55",
      "opt55",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt56:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56,
    g_param_spec_int (
      "opt56",
      "opt56",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt57:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57,
    g_param_spec_int (
      "opt57",
      "opt57",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt58:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58,
    g_param_spec_int (
      "opt58",
      "opt58",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt59:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59,
    g_param_spec_int (
      "opt59",
      "opt59",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt60:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60,
    g_param_spec_int (
      "opt60",
      "opt60",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt61:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61,
    g_param_spec_int (
      "opt61",
      "opt61",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt62:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62,
    g_param_spec_int (
      "opt62",
      "opt62",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsInternalTest63Optargs:opt63:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63,
    g_param_spec_int (
      "opt63",
      "opt63",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_internal_test_63_optargs_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsInternalTest63OptargsPrivate));
}

static void
guestfs_internal_test_63_optargs_init (GuestfsInternalTest63Optargs *o)
{
  o->priv = GUESTFS_INTERNAL_TEST_63_OPTARGS_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsInternalTest63OptargsPrivate));
}

/**
 * guestfs_internal_test_63_optargs_new:
 *
 * Create a new GuestfsInternalTest63Optargs object
 *
 * Returns: (transfer full): a new GuestfsInternalTest63Optargs object
 */
GuestfsInternalTest63Optargs *
guestfs_internal_test_63_optargs_new (void)
{
  return GUESTFS_INTERNAL_TEST_63_OPTARGS (g_object_new (GUESTFS_TYPE_INTERNAL_TEST_63_OPTARGS, NULL));
}
