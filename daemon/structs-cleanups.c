/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>

#include "daemon.h"
#include "guestfs_protocol.h"

/* Cleanup functions used by CLEANUP_* macros.  Do not call
 * these functions directly.
 */

void
cleanup_free_int_int_bool (void *ptr)
{
  struct guestfs_int_int_bool *x = (* (struct guestfs_int_int_bool **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_int_bool_list (void *ptr)
{
  struct guestfs_int_int_bool_list *x = (* (struct guestfs_int_int_bool_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_pv (void *ptr)
{
  struct guestfs_int_lvm_pv *x = (* (struct guestfs_int_lvm_pv **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_pv_list (void *ptr)
{
  struct guestfs_int_lvm_pv_list *x = (* (struct guestfs_int_lvm_pv_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_vg (void *ptr)
{
  struct guestfs_int_lvm_vg *x = (* (struct guestfs_int_lvm_vg **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_vg_list (void *ptr)
{
  struct guestfs_int_lvm_vg_list *x = (* (struct guestfs_int_lvm_vg_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_lv (void *ptr)
{
  struct guestfs_int_lvm_lv *x = (* (struct guestfs_int_lvm_lv **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_lvm_lv_list (void *ptr)
{
  struct guestfs_int_lvm_lv_list *x = (* (struct guestfs_int_lvm_lv_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_stat (void *ptr)
{
  struct guestfs_int_stat *x = (* (struct guestfs_int_stat **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_stat_list (void *ptr)
{
  struct guestfs_int_stat_list *x = (* (struct guestfs_int_stat_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_statns (void *ptr)
{
  struct guestfs_int_statns *x = (* (struct guestfs_int_statns **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statns, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_statns_list (void *ptr)
{
  struct guestfs_int_statns_list *x = (* (struct guestfs_int_statns_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statns_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_statvfs (void *ptr)
{
  struct guestfs_int_statvfs *x = (* (struct guestfs_int_statvfs **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_statvfs_list (void *ptr)
{
  struct guestfs_int_statvfs_list *x = (* (struct guestfs_int_statvfs_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_dirent (void *ptr)
{
  struct guestfs_int_dirent *x = (* (struct guestfs_int_dirent **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_dirent_list (void *ptr)
{
  struct guestfs_int_dirent_list *x = (* (struct guestfs_int_dirent_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_version (void *ptr)
{
  struct guestfs_int_version *x = (* (struct guestfs_int_version **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_version_list (void *ptr)
{
  struct guestfs_int_version_list *x = (* (struct guestfs_int_version_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_xattr (void *ptr)
{
  struct guestfs_int_xattr *x = (* (struct guestfs_int_xattr **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_xattr_list (void *ptr)
{
  struct guestfs_int_xattr_list *x = (* (struct guestfs_int_xattr_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_inotify_event (void *ptr)
{
  struct guestfs_int_inotify_event *x = (* (struct guestfs_int_inotify_event **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_inotify_event_list (void *ptr)
{
  struct guestfs_int_inotify_event_list *x = (* (struct guestfs_int_inotify_event_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_partition (void *ptr)
{
  struct guestfs_int_partition *x = (* (struct guestfs_int_partition **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_partition_list (void *ptr)
{
  struct guestfs_int_partition_list *x = (* (struct guestfs_int_partition_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_application (void *ptr)
{
  struct guestfs_int_application *x = (* (struct guestfs_int_application **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_application_list (void *ptr)
{
  struct guestfs_int_application_list *x = (* (struct guestfs_int_application_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_application2 (void *ptr)
{
  struct guestfs_int_application2 *x = (* (struct guestfs_int_application2 **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_application2_list (void *ptr)
{
  struct guestfs_int_application2_list *x = (* (struct guestfs_int_application2_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_isoinfo (void *ptr)
{
  struct guestfs_int_isoinfo *x = (* (struct guestfs_int_isoinfo **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_isoinfo_list (void *ptr)
{
  struct guestfs_int_isoinfo_list *x = (* (struct guestfs_int_isoinfo_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_mdstat (void *ptr)
{
  struct guestfs_int_mdstat *x = (* (struct guestfs_int_mdstat **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_mdstat_list (void *ptr)
{
  struct guestfs_int_mdstat_list *x = (* (struct guestfs_int_mdstat_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfssubvolume (void *ptr)
{
  struct guestfs_int_btrfssubvolume *x = (* (struct guestfs_int_btrfssubvolume **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfssubvolume_list (void *ptr)
{
  struct guestfs_int_btrfssubvolume_list *x = (* (struct guestfs_int_btrfssubvolume_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsqgroup (void *ptr)
{
  struct guestfs_int_btrfsqgroup *x = (* (struct guestfs_int_btrfsqgroup **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsqgroup, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsqgroup_list (void *ptr)
{
  struct guestfs_int_btrfsqgroup_list *x = (* (struct guestfs_int_btrfsqgroup_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsqgroup_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsbalance (void *ptr)
{
  struct guestfs_int_btrfsbalance *x = (* (struct guestfs_int_btrfsbalance **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsbalance, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsbalance_list (void *ptr)
{
  struct guestfs_int_btrfsbalance_list *x = (* (struct guestfs_int_btrfsbalance_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsbalance_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsscrub (void *ptr)
{
  struct guestfs_int_btrfsscrub *x = (* (struct guestfs_int_btrfsscrub **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsscrub, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_btrfsscrub_list (void *ptr)
{
  struct guestfs_int_btrfsscrub_list *x = (* (struct guestfs_int_btrfsscrub_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsscrub_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_xfsinfo (void *ptr)
{
  struct guestfs_int_xfsinfo *x = (* (struct guestfs_int_xfsinfo **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_xfsinfo_list (void *ptr)
{
  struct guestfs_int_xfsinfo_list *x = (* (struct guestfs_int_xfsinfo_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_utsname (void *ptr)
{
  struct guestfs_int_utsname *x = (* (struct guestfs_int_utsname **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_utsname_list (void *ptr)
{
  struct guestfs_int_utsname_list *x = (* (struct guestfs_int_utsname_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_hivex_node (void *ptr)
{
  struct guestfs_int_hivex_node *x = (* (struct guestfs_int_hivex_node **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_hivex_node_list (void *ptr)
{
  struct guestfs_int_hivex_node_list *x = (* (struct guestfs_int_hivex_node_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_hivex_value (void *ptr)
{
  struct guestfs_int_hivex_value *x = (* (struct guestfs_int_hivex_value **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_hivex_value_list (void *ptr)
{
  struct guestfs_int_hivex_value_list *x = (* (struct guestfs_int_hivex_value_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_internal_mountable (void *ptr)
{
  struct guestfs_int_internal_mountable *x = (* (struct guestfs_int_internal_mountable **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_internal_mountable_list (void *ptr)
{
  struct guestfs_int_internal_mountable_list *x = (* (struct guestfs_int_internal_mountable_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_tsk_dirent (void *ptr)
{
  struct guestfs_int_tsk_dirent *x = (* (struct guestfs_int_tsk_dirent **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_tsk_dirent, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_tsk_dirent_list (void *ptr)
{
  struct guestfs_int_tsk_dirent_list *x = (* (struct guestfs_int_tsk_dirent_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_tsk_dirent_list, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_yara_detection (void *ptr)
{
  struct guestfs_int_yara_detection *x = (* (struct guestfs_int_yara_detection **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_yara_detection, (char *) x);
    free (x);
  }
}

void
cleanup_free_int_yara_detection_list (void *ptr)
{
  struct guestfs_int_yara_detection_list *x = (* (struct guestfs_int_yara_detection_list **) ptr);

  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_yara_detection_list, (char *) x);
    free (x);
  }
}

