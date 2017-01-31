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

#ifndef GUESTFS_GOBJECT_STRUCT_UTSNAME_H__
#define GUESTFS_GOBJECT_STRUCT_UTSNAME_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

/**
 * GuestfsUTSName:
 * @uts_sysname: A NULL-terminated string
 * @uts_release: A NULL-terminated string
 * @uts_version: A NULL-terminated string
 * @uts_machine: A NULL-terminated string
 */
typedef struct _GuestfsUTSName GuestfsUTSName;
struct _GuestfsUTSName {
  gchar *uts_sysname;
  gchar *uts_release;
  gchar *uts_version;
  gchar *uts_machine;
};
GType guestfs_utsname_get_type (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_STRUCT_UTSNAME_H__ */
