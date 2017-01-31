/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/c.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
#include "guestfs-internal.h"
#include "guestfs_protocol.h"

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the XDR format.  See note in
 * generator.ml.
 */

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat (struct guestfs_stat *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns (struct guestfs_statns *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statns, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statns_list (struct guestfs_statns_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statns_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version (struct guestfs_version *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition (struct guestfs_partition *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application (struct guestfs_application *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application_list (struct guestfs_application_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2 (struct guestfs_application2 *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2_list (struct guestfs_application2_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo (struct guestfs_isoinfo *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo_list (struct guestfs_isoinfo_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat (struct guestfs_mdstat *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat_list (struct guestfs_mdstat_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume (struct guestfs_btrfssubvolume *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsqgroup (struct guestfs_btrfsqgroup *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsqgroup, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsqgroup_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsbalance (struct guestfs_btrfsbalance *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsbalance, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsbalance_list (struct guestfs_btrfsbalance_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsbalance_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsscrub (struct guestfs_btrfsscrub *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsscrub, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfsscrub_list (struct guestfs_btrfsscrub_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfsscrub_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo (struct guestfs_xfsinfo *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo_list (struct guestfs_xfsinfo_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname (struct guestfs_utsname *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname_list (struct guestfs_utsname_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node (struct guestfs_hivex_node *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node_list (struct guestfs_hivex_node_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value (struct guestfs_hivex_value *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value_list (struct guestfs_hivex_value_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable (struct guestfs_internal_mountable *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable_list (struct guestfs_internal_mountable_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_tsk_dirent (struct guestfs_tsk_dirent *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_tsk_dirent, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_tsk_dirent_list (struct guestfs_tsk_dirent_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_tsk_dirent_list, (char *) x);
    free (x);
  }
}

