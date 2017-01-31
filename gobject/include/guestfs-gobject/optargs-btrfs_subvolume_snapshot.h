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

#ifndef GUESTFS_GOBJECT_OPTARGS_BTRFS_SUBVOLUME_SNAPSHOT_H__
#define GUESTFS_GOBJECT_OPTARGS_BTRFS_SUBVOLUME_SNAPSHOT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include <guestfs-gobject.h>

G_BEGIN_DECLS

#define GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT (guestfs_btrfs_subvolume_snapshot_get_type ())
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT, GuestfsBTRFSSubvolumeSnapshot))
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT, GuestfsBTRFSSubvolumeSnapshotClass))
#define GUESTFS_IS_BTRFS_SUBVOLUME_SNAPSHOT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((klass), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT))
#define GUESTFS_IS_BTRFS_SUBVOLUME_SNAPSHOT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT))
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GUESTFS_TYPE_BTRFS_SUBVOLUME_SNAPSHOT, GuestfsBTRFSSubvolumeSnapshotClass))

typedef struct _GuestfsBTRFSSubvolumeSnapshotPrivate GuestfsBTRFSSubvolumeSnapshotPrivate;

/**
 * GuestfsBTRFSSubvolumeSnapshot:
 *
 * An object encapsulating optional arguments for guestfs_session_btrfs_subvolume_snapshot.
 */
typedef struct _GuestfsBTRFSSubvolumeSnapshot GuestfsBTRFSSubvolumeSnapshot;
struct _GuestfsBTRFSSubvolumeSnapshot {
  GObject parent;
  GuestfsBTRFSSubvolumeSnapshotPrivate *priv;
};

/**
 * GuestfsBTRFSSubvolumeSnapshotClass:
 * @parent_class: The superclass of GuestfsBTRFSSubvolumeSnapshotClass
 *
 * A class metadata object for GuestfsBTRFSSubvolumeSnapshot.
 */
typedef struct _GuestfsBTRFSSubvolumeSnapshotClass GuestfsBTRFSSubvolumeSnapshotClass;
struct _GuestfsBTRFSSubvolumeSnapshotClass {
  GObjectClass parent_class;
};

GType guestfs_btrfs_subvolume_snapshot_get_type (void);
GuestfsBTRFSSubvolumeSnapshot *guestfs_btrfs_subvolume_snapshot_new (void);

G_END_DECLS

#endif /* GUESTFS_GOBJECT_OPTARGS_BTRFS_SUBVOLUME_SNAPSHOT_H__ */
