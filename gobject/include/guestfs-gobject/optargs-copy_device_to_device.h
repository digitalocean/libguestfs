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

#ifndef GUESTFS_GOBJECT_OPTARGS_COPY_DEVICE_TO_DEVICE_H__
#define GUESTFS_GOBJECT_OPTARGS_COPY_DEVICE_TO_DEVICE_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE (guestfs_copy_device_to_device_get_type())
#define GUESTFS_COPY_DEVICE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDevice))
#define GUESTFS_COPY_DEVICE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDeviceClass))
#define GUESTFS_IS_COPY_DEVICE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE))
#define GUESTFS_IS_COPY_DEVICE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE))
#define GUESTFS_COPY_DEVICE_TO_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDeviceClass))

typedef struct _GuestfsCopyDeviceToDevicePrivate GuestfsCopyDeviceToDevicePrivate;

/**
 * GuestfsCopyDeviceToDevice:
 *
 * An object encapsulating optional arguments for guestfs_session_copy_device_to_device.
 */
typedef struct _GuestfsCopyDeviceToDevice GuestfsCopyDeviceToDevice;
struct _GuestfsCopyDeviceToDevice {
  GObject parent;
  GuestfsCopyDeviceToDevicePrivate *priv;
};

/**
 * GuestfsCopyDeviceToDeviceClass:
 * @parent_class: The superclass of GuestfsCopyDeviceToDeviceClass
 *
 * A class metadata object for GuestfsCopyDeviceToDevice.
 */
typedef struct _GuestfsCopyDeviceToDeviceClass GuestfsCopyDeviceToDeviceClass;
struct _GuestfsCopyDeviceToDeviceClass {
  GObjectClass parent_class;
};

GType guestfs_copy_device_to_device_get_type(void);
GuestfsCopyDeviceToDevice *guestfs_copy_device_to_device_new(void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_COPY_DEVICE_TO_DEVICE_H__ */
