/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

/* Cleanup functions used by CLEANUP_* macros.  Do not call
 * these functions directly.
 */

void
guestfs___cleanup_free_int_bool (void *ptr)
{
  guestfs_free_int_bool (* (struct guestfs_int_bool **) ptr);
}

void
guestfs___cleanup_free_int_bool_list (void *ptr)
{
  guestfs_free_int_bool_list (* (struct guestfs_int_bool_list **) ptr);
}

void
guestfs___cleanup_free_lvm_pv (void *ptr)
{
  guestfs_free_lvm_pv (* (struct guestfs_lvm_pv **) ptr);
}

void
guestfs___cleanup_free_lvm_pv_list (void *ptr)
{
  guestfs_free_lvm_pv_list (* (struct guestfs_lvm_pv_list **) ptr);
}

void
guestfs___cleanup_free_lvm_vg (void *ptr)
{
  guestfs_free_lvm_vg (* (struct guestfs_lvm_vg **) ptr);
}

void
guestfs___cleanup_free_lvm_vg_list (void *ptr)
{
  guestfs_free_lvm_vg_list (* (struct guestfs_lvm_vg_list **) ptr);
}

void
guestfs___cleanup_free_lvm_lv (void *ptr)
{
  guestfs_free_lvm_lv (* (struct guestfs_lvm_lv **) ptr);
}

void
guestfs___cleanup_free_lvm_lv_list (void *ptr)
{
  guestfs_free_lvm_lv_list (* (struct guestfs_lvm_lv_list **) ptr);
}

void
guestfs___cleanup_free_stat (void *ptr)
{
  guestfs_free_stat (* (struct guestfs_stat **) ptr);
}

void
guestfs___cleanup_free_stat_list (void *ptr)
{
  guestfs_free_stat_list (* (struct guestfs_stat_list **) ptr);
}

void
guestfs___cleanup_free_statvfs (void *ptr)
{
  guestfs_free_statvfs (* (struct guestfs_statvfs **) ptr);
}

void
guestfs___cleanup_free_statvfs_list (void *ptr)
{
  guestfs_free_statvfs_list (* (struct guestfs_statvfs_list **) ptr);
}

void
guestfs___cleanup_free_dirent (void *ptr)
{
  guestfs_free_dirent (* (struct guestfs_dirent **) ptr);
}

void
guestfs___cleanup_free_dirent_list (void *ptr)
{
  guestfs_free_dirent_list (* (struct guestfs_dirent_list **) ptr);
}

void
guestfs___cleanup_free_version (void *ptr)
{
  guestfs_free_version (* (struct guestfs_version **) ptr);
}

void
guestfs___cleanup_free_version_list (void *ptr)
{
  guestfs_free_version_list (* (struct guestfs_version_list **) ptr);
}

void
guestfs___cleanup_free_xattr (void *ptr)
{
  guestfs_free_xattr (* (struct guestfs_xattr **) ptr);
}

void
guestfs___cleanup_free_xattr_list (void *ptr)
{
  guestfs_free_xattr_list (* (struct guestfs_xattr_list **) ptr);
}

void
guestfs___cleanup_free_inotify_event (void *ptr)
{
  guestfs_free_inotify_event (* (struct guestfs_inotify_event **) ptr);
}

void
guestfs___cleanup_free_inotify_event_list (void *ptr)
{
  guestfs_free_inotify_event_list (* (struct guestfs_inotify_event_list **) ptr);
}

void
guestfs___cleanup_free_partition (void *ptr)
{
  guestfs_free_partition (* (struct guestfs_partition **) ptr);
}

void
guestfs___cleanup_free_partition_list (void *ptr)
{
  guestfs_free_partition_list (* (struct guestfs_partition_list **) ptr);
}

void
guestfs___cleanup_free_application (void *ptr)
{
  guestfs_free_application (* (struct guestfs_application **) ptr);
}

void
guestfs___cleanup_free_application_list (void *ptr)
{
  guestfs_free_application_list (* (struct guestfs_application_list **) ptr);
}

void
guestfs___cleanup_free_application2 (void *ptr)
{
  guestfs_free_application2 (* (struct guestfs_application2 **) ptr);
}

void
guestfs___cleanup_free_application2_list (void *ptr)
{
  guestfs_free_application2_list (* (struct guestfs_application2_list **) ptr);
}

void
guestfs___cleanup_free_isoinfo (void *ptr)
{
  guestfs_free_isoinfo (* (struct guestfs_isoinfo **) ptr);
}

void
guestfs___cleanup_free_isoinfo_list (void *ptr)
{
  guestfs_free_isoinfo_list (* (struct guestfs_isoinfo_list **) ptr);
}

void
guestfs___cleanup_free_mdstat (void *ptr)
{
  guestfs_free_mdstat (* (struct guestfs_mdstat **) ptr);
}

void
guestfs___cleanup_free_mdstat_list (void *ptr)
{
  guestfs_free_mdstat_list (* (struct guestfs_mdstat_list **) ptr);
}

void
guestfs___cleanup_free_btrfssubvolume (void *ptr)
{
  guestfs_free_btrfssubvolume (* (struct guestfs_btrfssubvolume **) ptr);
}

void
guestfs___cleanup_free_btrfssubvolume_list (void *ptr)
{
  guestfs_free_btrfssubvolume_list (* (struct guestfs_btrfssubvolume_list **) ptr);
}

void
guestfs___cleanup_free_xfsinfo (void *ptr)
{
  guestfs_free_xfsinfo (* (struct guestfs_xfsinfo **) ptr);
}

void
guestfs___cleanup_free_xfsinfo_list (void *ptr)
{
  guestfs_free_xfsinfo_list (* (struct guestfs_xfsinfo_list **) ptr);
}

void
guestfs___cleanup_free_utsname (void *ptr)
{
  guestfs_free_utsname (* (struct guestfs_utsname **) ptr);
}

void
guestfs___cleanup_free_utsname_list (void *ptr)
{
  guestfs_free_utsname_list (* (struct guestfs_utsname_list **) ptr);
}

void
guestfs___cleanup_free_hivex_node (void *ptr)
{
  guestfs_free_hivex_node (* (struct guestfs_hivex_node **) ptr);
}

void
guestfs___cleanup_free_hivex_node_list (void *ptr)
{
  guestfs_free_hivex_node_list (* (struct guestfs_hivex_node_list **) ptr);
}

void
guestfs___cleanup_free_hivex_value (void *ptr)
{
  guestfs_free_hivex_value (* (struct guestfs_hivex_value **) ptr);
}

void
guestfs___cleanup_free_hivex_value_list (void *ptr)
{
  guestfs_free_hivex_value_list (* (struct guestfs_hivex_value_list **) ptr);
}

void
guestfs___cleanup_free_internal_mountable (void *ptr)
{
  guestfs_free_internal_mountable (* (struct guestfs_internal_mountable **) ptr);
}

void
guestfs___cleanup_free_internal_mountable_list (void *ptr)
{
  guestfs_free_internal_mountable_list (* (struct guestfs_internal_mountable_list **) ptr);
}

