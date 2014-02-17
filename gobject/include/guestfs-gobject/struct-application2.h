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

#ifndef GUESTFS_GOBJECT_STRUCT_APPLICATION2_H__
#define GUESTFS_GOBJECT_STRUCT_APPLICATION2_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsApplication2:
 * @app2_name: A NULL-terminated string
 * @app2_display_name: A NULL-terminated string
 * @app2_epoch: A signed 32-bit integer
 * @app2_version: A NULL-terminated string
 * @app2_release: A NULL-terminated string
 * @app2_arch: A NULL-terminated string
 * @app2_install_path: A NULL-terminated string
 * @app2_trans_path: A NULL-terminated string
 * @app2_publisher: A NULL-terminated string
 * @app2_url: A NULL-terminated string
 * @app2_source_package: A NULL-terminated string
 * @app2_summary: A NULL-terminated string
 * @app2_description: A NULL-terminated string
 * @app2_spare1: A NULL-terminated string
 * @app2_spare2: A NULL-terminated string
 * @app2_spare3: A NULL-terminated string
 * @app2_spare4: A NULL-terminated string
 */
typedef struct _GuestfsApplication2 GuestfsApplication2;
struct _GuestfsApplication2 {
  gchar *app2_name;
  gchar *app2_display_name;
  gint32 app2_epoch;
  gchar *app2_version;
  gchar *app2_release;
  gchar *app2_arch;
  gchar *app2_install_path;
  gchar *app2_trans_path;
  gchar *app2_publisher;
  gchar *app2_url;
  gchar *app2_source_package;
  gchar *app2_summary;
  gchar *app2_description;
  gchar *app2_spare1;
  gchar *app2_spare2;
  gchar *app2_spare3;
  gchar *app2_spare4;
};
GType guestfs_application2_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_APPLICATION2_H__ */
