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

#ifndef GUESTFS_GOBJECT_STRUCT_INOTIFY_EVENT_H__
#define GUESTFS_GOBJECT_STRUCT_INOTIFY_EVENT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsINotifyEvent:
 * @in_wd: A signed 64-bit integer
 * @in_mask: An unsigned 32-bit integer
 * @in_cookie: An unsigned 32-bit integer
 * @in_name: A NULL-terminated string
 */
typedef struct _GuestfsINotifyEvent GuestfsINotifyEvent;
struct _GuestfsINotifyEvent {
  gint64 in_wd;
  guint32 in_mask;
  guint32 in_cookie;
  gchar *in_name;
};
GType guestfs_inotify_event_get_type(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_INOTIFY_EVENT_H__ */
