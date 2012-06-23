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

#ifndef GUESTFS_GOBJECT_STRUCT_APPLICATION_H__
#define GUESTFS_GOBJECT_STRUCT_APPLICATION_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsApplication:
 * @app_name: A NULL-terminated string
 * @app_display_name: A NULL-terminated string
 * @app_epoch: A signed 32-bit integer
 * @app_version: A NULL-terminated string
 * @app_release: A NULL-terminated string
 * @app_install_path: A NULL-terminated string
 * @app_trans_path: A NULL-terminated string
 * @app_publisher: A NULL-terminated string
 * @app_url: A NULL-terminated string
 * @app_source_package: A NULL-terminated string
 * @app_summary: A NULL-terminated string
 * @app_description: A NULL-terminated string
 */
typedef struct _GuestfsApplication GuestfsApplication;
struct _GuestfsApplication {
  gchar *app_name;
  gchar *app_display_name;
  gint32 app_epoch;
  gchar *app_version;
  gchar *app_release;
  gchar *app_install_path;
  gchar *app_trans_path;
  gchar *app_publisher;
  gchar *app_url;
  gchar *app_source_package;
  gchar *app_summary;
  gchar *app_description;
};
GType guestfs_application_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_APPLICATION_H__ */
