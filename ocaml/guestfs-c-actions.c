/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ocaml.ml
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
#include <string.h>
#include <stdint.h>

#include <caml/config.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>
#include <caml/signals.h>

#include <guestfs.h>
#include "guestfs-internal-frontend.h"

#include "guestfs-c.h"

/* Copy a hashtable of string pairs into an assoc-list.  We return
 * the list in reverse order, but hashtables aren't supposed to be
 * ordered anyway.
 */
static value
copy_table (char * const * argv)
{
  CAMLparam0 ();
  CAMLlocal5 (rv, pairv, kv, vv, cons);
  size_t i;

  rv = Val_int (0);
  for (i = 0; argv[i] != NULL; i += 2) {
    kv = caml_copy_string (argv[i]);
    vv = caml_copy_string (argv[i+1]);
    pairv = caml_alloc (2, 0);
    Store_field (pairv, 0, kv);
    Store_field (pairv, 1, vv);
    cons = caml_alloc (2, 0);
    Store_field (cons, 1, rv);
    rv = cons;
    Store_field (cons, 0, pairv);
  }

  CAMLreturn (rv);
}

static value
copy_application (const struct guestfs_application *application)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (12, 0);
  v = caml_copy_string (application->app_name);
  Store_field (rv, 0, v);
  v = caml_copy_string (application->app_display_name);
  Store_field (rv, 1, v);
  v = caml_copy_int32 (application->app_epoch);
  Store_field (rv, 2, v);
  v = caml_copy_string (application->app_version);
  Store_field (rv, 3, v);
  v = caml_copy_string (application->app_release);
  Store_field (rv, 4, v);
  v = caml_copy_string (application->app_install_path);
  Store_field (rv, 5, v);
  v = caml_copy_string (application->app_trans_path);
  Store_field (rv, 6, v);
  v = caml_copy_string (application->app_publisher);
  Store_field (rv, 7, v);
  v = caml_copy_string (application->app_url);
  Store_field (rv, 8, v);
  v = caml_copy_string (application->app_source_package);
  Store_field (rv, 9, v);
  v = caml_copy_string (application->app_summary);
  Store_field (rv, 10, v);
  v = caml_copy_string (application->app_description);
  Store_field (rv, 11, v);
  CAMLreturn (rv);
}

static value
copy_application2 (const struct guestfs_application2 *application2)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (17, 0);
  v = caml_copy_string (application2->app2_name);
  Store_field (rv, 0, v);
  v = caml_copy_string (application2->app2_display_name);
  Store_field (rv, 1, v);
  v = caml_copy_int32 (application2->app2_epoch);
  Store_field (rv, 2, v);
  v = caml_copy_string (application2->app2_version);
  Store_field (rv, 3, v);
  v = caml_copy_string (application2->app2_release);
  Store_field (rv, 4, v);
  v = caml_copy_string (application2->app2_arch);
  Store_field (rv, 5, v);
  v = caml_copy_string (application2->app2_install_path);
  Store_field (rv, 6, v);
  v = caml_copy_string (application2->app2_trans_path);
  Store_field (rv, 7, v);
  v = caml_copy_string (application2->app2_publisher);
  Store_field (rv, 8, v);
  v = caml_copy_string (application2->app2_url);
  Store_field (rv, 9, v);
  v = caml_copy_string (application2->app2_source_package);
  Store_field (rv, 10, v);
  v = caml_copy_string (application2->app2_summary);
  Store_field (rv, 11, v);
  v = caml_copy_string (application2->app2_description);
  Store_field (rv, 12, v);
  v = caml_copy_string (application2->app2_spare1);
  Store_field (rv, 13, v);
  v = caml_copy_string (application2->app2_spare2);
  Store_field (rv, 14, v);
  v = caml_copy_string (application2->app2_spare3);
  Store_field (rv, 15, v);
  v = caml_copy_string (application2->app2_spare4);
  Store_field (rv, 16, v);
  CAMLreturn (rv);
}

static value
copy_btrfsbalance (const struct guestfs_btrfsbalance *btrfsbalance)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (5, 0);
  v = caml_copy_string (btrfsbalance->btrfsbalance_status);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (btrfsbalance->btrfsbalance_total);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (btrfsbalance->btrfsbalance_balanced);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (btrfsbalance->btrfsbalance_considered);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (btrfsbalance->btrfsbalance_left);
  Store_field (rv, 4, v);
  CAMLreturn (rv);
}

static value
copy_btrfsqgroup (const struct guestfs_btrfsqgroup *btrfsqgroup)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (3, 0);
  v = caml_copy_string (btrfsqgroup->btrfsqgroup_id);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (btrfsqgroup->btrfsqgroup_rfer);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (btrfsqgroup->btrfsqgroup_excl);
  Store_field (rv, 2, v);
  CAMLreturn (rv);
}

static value
copy_btrfsscrub (const struct guestfs_btrfsscrub *btrfsscrub)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (15, 0);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_data_extents_scrubbed);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_tree_extents_scrubbed);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_data_bytes_scrubbed);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_tree_bytes_scrubbed);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_read_errors);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_csum_errors);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_verify_errors);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_no_csum);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_csum_discards);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_super_errors);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_malloc_errors);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_uncorrectable_errors);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_unverified_errors);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_corrected_errors);
  Store_field (rv, 13, v);
  v = caml_copy_int64 (btrfsscrub->btrfsscrub_last_physical);
  Store_field (rv, 14, v);
  CAMLreturn (rv);
}

static value
copy_btrfssubvolume (const struct guestfs_btrfssubvolume *btrfssubvolume)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (3, 0);
  v = caml_copy_int64 (btrfssubvolume->btrfssubvolume_id);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (btrfssubvolume->btrfssubvolume_top_level_id);
  Store_field (rv, 1, v);
  v = caml_copy_string (btrfssubvolume->btrfssubvolume_path);
  Store_field (rv, 2, v);
  CAMLreturn (rv);
}

static value
copy_dirent (const struct guestfs_dirent *dirent)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (3, 0);
  v = caml_copy_int64 (dirent->ino);
  Store_field (rv, 0, v);
  v = Val_int (dirent->ftyp);
  Store_field (rv, 1, v);
  v = caml_copy_string (dirent->name);
  Store_field (rv, 2, v);
  CAMLreturn (rv);
}

static value
copy_hivex_node (const struct guestfs_hivex_node *hivex_node)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (1, 0);
  v = caml_copy_int64 (hivex_node->hivex_node_h);
  Store_field (rv, 0, v);
  CAMLreturn (rv);
}

static value
copy_hivex_value (const struct guestfs_hivex_value *hivex_value)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (1, 0);
  v = caml_copy_int64 (hivex_value->hivex_value_h);
  Store_field (rv, 0, v);
  CAMLreturn (rv);
}

static value
copy_inotify_event (const struct guestfs_inotify_event *inotify_event)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (4, 0);
  v = caml_copy_int64 (inotify_event->in_wd);
  Store_field (rv, 0, v);
  v = caml_copy_int32 (inotify_event->in_mask);
  Store_field (rv, 1, v);
  v = caml_copy_int32 (inotify_event->in_cookie);
  Store_field (rv, 2, v);
  v = caml_copy_string (inotify_event->in_name);
  Store_field (rv, 3, v);
  CAMLreturn (rv);
}

static value
copy_int_bool (const struct guestfs_int_bool *int_bool)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (2, 0);
  v = caml_copy_int32 (int_bool->i);
  Store_field (rv, 0, v);
  v = caml_copy_int32 (int_bool->b);
  Store_field (rv, 1, v);
  CAMLreturn (rv);
}

static value
copy_isoinfo (const struct guestfs_isoinfo *isoinfo)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (17, 0);
  v = caml_copy_string (isoinfo->iso_system_id);
  Store_field (rv, 0, v);
  v = caml_copy_string (isoinfo->iso_volume_id);
  Store_field (rv, 1, v);
  v = caml_copy_int32 (isoinfo->iso_volume_space_size);
  Store_field (rv, 2, v);
  v = caml_copy_int32 (isoinfo->iso_volume_set_size);
  Store_field (rv, 3, v);
  v = caml_copy_int32 (isoinfo->iso_volume_sequence_number);
  Store_field (rv, 4, v);
  v = caml_copy_int32 (isoinfo->iso_logical_block_size);
  Store_field (rv, 5, v);
  v = caml_copy_string (isoinfo->iso_volume_set_id);
  Store_field (rv, 6, v);
  v = caml_copy_string (isoinfo->iso_publisher_id);
  Store_field (rv, 7, v);
  v = caml_copy_string (isoinfo->iso_data_preparer_id);
  Store_field (rv, 8, v);
  v = caml_copy_string (isoinfo->iso_application_id);
  Store_field (rv, 9, v);
  v = caml_copy_string (isoinfo->iso_copyright_file_id);
  Store_field (rv, 10, v);
  v = caml_copy_string (isoinfo->iso_abstract_file_id);
  Store_field (rv, 11, v);
  v = caml_copy_string (isoinfo->iso_bibliographic_file_id);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (isoinfo->iso_volume_creation_t);
  Store_field (rv, 13, v);
  v = caml_copy_int64 (isoinfo->iso_volume_modification_t);
  Store_field (rv, 14, v);
  v = caml_copy_int64 (isoinfo->iso_volume_expiration_t);
  Store_field (rv, 15, v);
  v = caml_copy_int64 (isoinfo->iso_volume_effective_t);
  Store_field (rv, 16, v);
  CAMLreturn (rv);
}

static value
copy_lvm_lv (const struct guestfs_lvm_lv *lvm_lv)
{
  CAMLparam0 ();
  CAMLlocal3 (rv, v, v2);

  rv = caml_alloc (16, 0);
  v = caml_copy_string (lvm_lv->lv_name);
  Store_field (rv, 0, v);
  v = caml_alloc_string (32);
  memcpy (String_val (v), lvm_lv->lv_uuid, 32);
  Store_field (rv, 1, v);
  v = caml_copy_string (lvm_lv->lv_attr);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (lvm_lv->lv_major);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (lvm_lv->lv_minor);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (lvm_lv->lv_kernel_major);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (lvm_lv->lv_kernel_minor);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (lvm_lv->lv_size);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (lvm_lv->seg_count);
  Store_field (rv, 8, v);
  v = caml_copy_string (lvm_lv->origin);
  Store_field (rv, 9, v);
  if (lvm_lv->snap_percent >= 0) { /* Some snap_percent */
    v2 = caml_copy_double (lvm_lv->snap_percent);
    v = caml_alloc (1, 0);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  Store_field (rv, 10, v);
  if (lvm_lv->copy_percent >= 0) { /* Some copy_percent */
    v2 = caml_copy_double (lvm_lv->copy_percent);
    v = caml_alloc (1, 0);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  Store_field (rv, 11, v);
  v = caml_copy_string (lvm_lv->move_pv);
  Store_field (rv, 12, v);
  v = caml_copy_string (lvm_lv->lv_tags);
  Store_field (rv, 13, v);
  v = caml_copy_string (lvm_lv->mirror_log);
  Store_field (rv, 14, v);
  v = caml_copy_string (lvm_lv->modules);
  Store_field (rv, 15, v);
  CAMLreturn (rv);
}

static value
copy_lvm_pv (const struct guestfs_lvm_pv *lvm_pv)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (14, 0);
  v = caml_copy_string (lvm_pv->pv_name);
  Store_field (rv, 0, v);
  v = caml_alloc_string (32);
  memcpy (String_val (v), lvm_pv->pv_uuid, 32);
  Store_field (rv, 1, v);
  v = caml_copy_string (lvm_pv->pv_fmt);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (lvm_pv->pv_size);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (lvm_pv->dev_size);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (lvm_pv->pv_free);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (lvm_pv->pv_used);
  Store_field (rv, 6, v);
  v = caml_copy_string (lvm_pv->pv_attr);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (lvm_pv->pv_pe_count);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (lvm_pv->pv_pe_alloc_count);
  Store_field (rv, 9, v);
  v = caml_copy_string (lvm_pv->pv_tags);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (lvm_pv->pe_start);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (lvm_pv->pv_mda_count);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (lvm_pv->pv_mda_free);
  Store_field (rv, 13, v);
  CAMLreturn (rv);
}

static value
copy_lvm_vg (const struct guestfs_lvm_vg *lvm_vg)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (19, 0);
  v = caml_copy_string (lvm_vg->vg_name);
  Store_field (rv, 0, v);
  v = caml_alloc_string (32);
  memcpy (String_val (v), lvm_vg->vg_uuid, 32);
  Store_field (rv, 1, v);
  v = caml_copy_string (lvm_vg->vg_fmt);
  Store_field (rv, 2, v);
  v = caml_copy_string (lvm_vg->vg_attr);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (lvm_vg->vg_size);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (lvm_vg->vg_free);
  Store_field (rv, 5, v);
  v = caml_copy_string (lvm_vg->vg_sysid);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (lvm_vg->vg_extent_size);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (lvm_vg->vg_extent_count);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (lvm_vg->vg_free_count);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (lvm_vg->max_lv);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (lvm_vg->max_pv);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (lvm_vg->pv_count);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (lvm_vg->lv_count);
  Store_field (rv, 13, v);
  v = caml_copy_int64 (lvm_vg->snap_count);
  Store_field (rv, 14, v);
  v = caml_copy_int64 (lvm_vg->vg_seqno);
  Store_field (rv, 15, v);
  v = caml_copy_string (lvm_vg->vg_tags);
  Store_field (rv, 16, v);
  v = caml_copy_int64 (lvm_vg->vg_mda_count);
  Store_field (rv, 17, v);
  v = caml_copy_int64 (lvm_vg->vg_mda_free);
  Store_field (rv, 18, v);
  CAMLreturn (rv);
}

static value
copy_mdstat (const struct guestfs_mdstat *mdstat)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (3, 0);
  v = caml_copy_string (mdstat->mdstat_device);
  Store_field (rv, 0, v);
  v = caml_copy_int32 (mdstat->mdstat_index);
  Store_field (rv, 1, v);
  v = caml_copy_string (mdstat->mdstat_flags);
  Store_field (rv, 2, v);
  CAMLreturn (rv);
}

static value
copy_partition (const struct guestfs_partition *partition)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (4, 0);
  v = caml_copy_int32 (partition->part_num);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (partition->part_start);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (partition->part_end);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (partition->part_size);
  Store_field (rv, 3, v);
  CAMLreturn (rv);
}

static value
copy_stat (const struct guestfs_stat *stat)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (13, 0);
  v = caml_copy_int64 (stat->dev);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (stat->ino);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (stat->mode);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (stat->nlink);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (stat->uid);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (stat->gid);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (stat->rdev);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (stat->size);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (stat->blksize);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (stat->blocks);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (stat->atime);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (stat->mtime);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (stat->ctime);
  Store_field (rv, 12, v);
  CAMLreturn (rv);
}

static value
copy_statns (const struct guestfs_statns *statns)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (22, 0);
  v = caml_copy_int64 (statns->st_dev);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (statns->st_ino);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (statns->st_mode);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (statns->st_nlink);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (statns->st_uid);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (statns->st_gid);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (statns->st_rdev);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (statns->st_size);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (statns->st_blksize);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (statns->st_blocks);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (statns->st_atime_sec);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (statns->st_atime_nsec);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (statns->st_mtime_sec);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (statns->st_mtime_nsec);
  Store_field (rv, 13, v);
  v = caml_copy_int64 (statns->st_ctime_sec);
  Store_field (rv, 14, v);
  v = caml_copy_int64 (statns->st_ctime_nsec);
  Store_field (rv, 15, v);
  v = caml_copy_int64 (statns->st_spare1);
  Store_field (rv, 16, v);
  v = caml_copy_int64 (statns->st_spare2);
  Store_field (rv, 17, v);
  v = caml_copy_int64 (statns->st_spare3);
  Store_field (rv, 18, v);
  v = caml_copy_int64 (statns->st_spare4);
  Store_field (rv, 19, v);
  v = caml_copy_int64 (statns->st_spare5);
  Store_field (rv, 20, v);
  v = caml_copy_int64 (statns->st_spare6);
  Store_field (rv, 21, v);
  CAMLreturn (rv);
}

static value
copy_statvfs (const struct guestfs_statvfs *statvfs)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (11, 0);
  v = caml_copy_int64 (statvfs->bsize);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (statvfs->frsize);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (statvfs->blocks);
  Store_field (rv, 2, v);
  v = caml_copy_int64 (statvfs->bfree);
  Store_field (rv, 3, v);
  v = caml_copy_int64 (statvfs->bavail);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (statvfs->files);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (statvfs->ffree);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (statvfs->favail);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (statvfs->fsid);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (statvfs->flag);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (statvfs->namemax);
  Store_field (rv, 10, v);
  CAMLreturn (rv);
}

static value
copy_tsk_dirent (const struct guestfs_tsk_dirent *tsk_dirent)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (16, 0);
  v = caml_copy_int64 (tsk_dirent->tsk_inode);
  Store_field (rv, 0, v);
  v = Val_int (tsk_dirent->tsk_type);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (tsk_dirent->tsk_size);
  Store_field (rv, 2, v);
  v = caml_copy_string (tsk_dirent->tsk_name);
  Store_field (rv, 3, v);
  v = caml_copy_int32 (tsk_dirent->tsk_flags);
  Store_field (rv, 4, v);
  v = caml_copy_int64 (tsk_dirent->tsk_atime_sec);
  Store_field (rv, 5, v);
  v = caml_copy_int64 (tsk_dirent->tsk_atime_nsec);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (tsk_dirent->tsk_mtime_sec);
  Store_field (rv, 7, v);
  v = caml_copy_int64 (tsk_dirent->tsk_mtime_nsec);
  Store_field (rv, 8, v);
  v = caml_copy_int64 (tsk_dirent->tsk_ctime_sec);
  Store_field (rv, 9, v);
  v = caml_copy_int64 (tsk_dirent->tsk_ctime_nsec);
  Store_field (rv, 10, v);
  v = caml_copy_int64 (tsk_dirent->tsk_crtime_sec);
  Store_field (rv, 11, v);
  v = caml_copy_int64 (tsk_dirent->tsk_crtime_nsec);
  Store_field (rv, 12, v);
  v = caml_copy_int64 (tsk_dirent->tsk_nlink);
  Store_field (rv, 13, v);
  v = caml_copy_string (tsk_dirent->tsk_link);
  Store_field (rv, 14, v);
  v = caml_copy_int64 (tsk_dirent->tsk_spare1);
  Store_field (rv, 15, v);
  CAMLreturn (rv);
}

static value
copy_utsname (const struct guestfs_utsname *utsname)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (4, 0);
  v = caml_copy_string (utsname->uts_sysname);
  Store_field (rv, 0, v);
  v = caml_copy_string (utsname->uts_release);
  Store_field (rv, 1, v);
  v = caml_copy_string (utsname->uts_version);
  Store_field (rv, 2, v);
  v = caml_copy_string (utsname->uts_machine);
  Store_field (rv, 3, v);
  CAMLreturn (rv);
}

static value
copy_version (const struct guestfs_version *version)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (4, 0);
  v = caml_copy_int64 (version->major);
  Store_field (rv, 0, v);
  v = caml_copy_int64 (version->minor);
  Store_field (rv, 1, v);
  v = caml_copy_int64 (version->release);
  Store_field (rv, 2, v);
  v = caml_copy_string (version->extra);
  Store_field (rv, 3, v);
  CAMLreturn (rv);
}

static value
copy_xattr (const struct guestfs_xattr *xattr)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (2, 0);
  v = caml_copy_string (xattr->attrname);
  Store_field (rv, 0, v);
  v = caml_alloc_string (xattr->attrval_len);
  memcpy (String_val (v), xattr->attrval, xattr->attrval_len);
  Store_field (rv, 1, v);
  CAMLreturn (rv);
}

static value
copy_xfsinfo (const struct guestfs_xfsinfo *xfsinfo)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);

  rv = caml_alloc (25, 0);
  v = caml_copy_string (xfsinfo->xfs_mntpoint);
  Store_field (rv, 0, v);
  v = caml_copy_int32 (xfsinfo->xfs_inodesize);
  Store_field (rv, 1, v);
  v = caml_copy_int32 (xfsinfo->xfs_agcount);
  Store_field (rv, 2, v);
  v = caml_copy_int32 (xfsinfo->xfs_agsize);
  Store_field (rv, 3, v);
  v = caml_copy_int32 (xfsinfo->xfs_sectsize);
  Store_field (rv, 4, v);
  v = caml_copy_int32 (xfsinfo->xfs_attr);
  Store_field (rv, 5, v);
  v = caml_copy_int32 (xfsinfo->xfs_blocksize);
  Store_field (rv, 6, v);
  v = caml_copy_int64 (xfsinfo->xfs_datablocks);
  Store_field (rv, 7, v);
  v = caml_copy_int32 (xfsinfo->xfs_imaxpct);
  Store_field (rv, 8, v);
  v = caml_copy_int32 (xfsinfo->xfs_sunit);
  Store_field (rv, 9, v);
  v = caml_copy_int32 (xfsinfo->xfs_swidth);
  Store_field (rv, 10, v);
  v = caml_copy_int32 (xfsinfo->xfs_dirversion);
  Store_field (rv, 11, v);
  v = caml_copy_int32 (xfsinfo->xfs_dirblocksize);
  Store_field (rv, 12, v);
  v = caml_copy_int32 (xfsinfo->xfs_cimode);
  Store_field (rv, 13, v);
  v = caml_copy_string (xfsinfo->xfs_logname);
  Store_field (rv, 14, v);
  v = caml_copy_int32 (xfsinfo->xfs_logblocksize);
  Store_field (rv, 15, v);
  v = caml_copy_int32 (xfsinfo->xfs_logblocks);
  Store_field (rv, 16, v);
  v = caml_copy_int32 (xfsinfo->xfs_logversion);
  Store_field (rv, 17, v);
  v = caml_copy_int32 (xfsinfo->xfs_logsectsize);
  Store_field (rv, 18, v);
  v = caml_copy_int32 (xfsinfo->xfs_logsunit);
  Store_field (rv, 19, v);
  v = caml_copy_int32 (xfsinfo->xfs_lazycount);
  Store_field (rv, 20, v);
  v = caml_copy_string (xfsinfo->xfs_rtname);
  Store_field (rv, 21, v);
  v = caml_copy_int32 (xfsinfo->xfs_rtextsize);
  Store_field (rv, 22, v);
  v = caml_copy_int64 (xfsinfo->xfs_rtblocks);
  Store_field (rv, 23, v);
  v = caml_copy_int64 (xfsinfo->xfs_rtextents);
  Store_field (rv, 24, v);
  CAMLreturn (rv);
}

static value
copy_lvm_lv_list (const struct guestfs_lvm_lv_list *lvm_lvs)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (lvm_lvs->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (lvm_lvs->len, 0);
    for (i = 0; i < lvm_lvs->len; ++i) {
      v = copy_lvm_lv (&lvm_lvs->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_dirent_list (const struct guestfs_dirent_list *dirents)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (dirents->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (dirents->len, 0);
    for (i = 0; i < dirents->len; ++i) {
      v = copy_dirent (&dirents->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *btrfsqgroups)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (btrfsqgroups->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (btrfsqgroups->len, 0);
    for (i = 0; i < btrfsqgroups->len; ++i) {
      v = copy_btrfsqgroup (&btrfsqgroups->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_tsk_dirent_list (const struct guestfs_tsk_dirent_list *tsk_dirents)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (tsk_dirents->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (tsk_dirents->len, 0);
    for (i = 0; i < tsk_dirents->len; ++i) {
      v = copy_tsk_dirent (&tsk_dirents->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_partition_list (const struct guestfs_partition_list *partitions)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (partitions->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (partitions->len, 0);
    for (i = 0; i < partitions->len; ++i) {
      v = copy_partition (&partitions->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_statns_list (const struct guestfs_statns_list *statnss)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (statnss->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (statnss->len, 0);
    for (i = 0; i < statnss->len; ++i) {
      v = copy_statns (&statnss->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_application2_list (const struct guestfs_application2_list *application2s)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (application2s->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (application2s->len, 0);
    for (i = 0; i < application2s->len; ++i) {
      v = copy_application2 (&application2s->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_inotify_event_list (const struct guestfs_inotify_event_list *inotify_events)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (inotify_events->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (inotify_events->len, 0);
    for (i = 0; i < inotify_events->len; ++i) {
      v = copy_inotify_event (&inotify_events->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_application_list (const struct guestfs_application_list *applications)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (applications->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (applications->len, 0);
    for (i = 0; i < applications->len; ++i) {
      v = copy_application (&applications->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_hivex_value_list (const struct guestfs_hivex_value_list *hivex_values)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (hivex_values->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (hivex_values->len, 0);
    for (i = 0; i < hivex_values->len; ++i) {
      v = copy_hivex_value (&hivex_values->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_xattr_list (const struct guestfs_xattr_list *xattrs)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (xattrs->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (xattrs->len, 0);
    for (i = 0; i < xattrs->len; ++i) {
      v = copy_xattr (&xattrs->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_lvm_pv_list (const struct guestfs_lvm_pv_list *lvm_pvs)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (lvm_pvs->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (lvm_pvs->len, 0);
    for (i = 0; i < lvm_pvs->len; ++i) {
      v = copy_lvm_pv (&lvm_pvs->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_lvm_vg_list (const struct guestfs_lvm_vg_list *lvm_vgs)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (lvm_vgs->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (lvm_vgs->len, 0);
    for (i = 0; i < lvm_vgs->len; ++i) {
      v = copy_lvm_vg (&lvm_vgs->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (btrfssubvolumes->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (btrfssubvolumes->len, 0);
    for (i = 0; i < btrfssubvolumes->len; ++i) {
      v = copy_btrfssubvolume (&btrfssubvolumes->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_mdstat_list (const struct guestfs_mdstat_list *mdstats)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (mdstats->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (mdstats->len, 0);
    for (i = 0; i < mdstats->len; ++i) {
      v = copy_mdstat (&mdstats->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_hivex_node_list (const struct guestfs_hivex_node_list *hivex_nodes)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (hivex_nodes->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (hivex_nodes->len, 0);
    for (i = 0; i < hivex_nodes->len; ++i) {
      v = copy_hivex_node (&hivex_nodes->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

static value
copy_stat_list (const struct guestfs_stat_list *stats)
{
  CAMLparam0 ();
  CAMLlocal2 (rv, v);
  unsigned int i;

  if (stats->len == 0)
    CAMLreturn (Atom (0));
  else {
    rv = caml_alloc (stats->len, 0);
    for (i = 0; i < stats->len; ++i) {
      v = copy_stat (&stats->val[i]);
      Store_field (rv, i, v);
    }
    CAMLreturn (rv);
  }
}

/* Automatically generated wrapper for function
 * val acl_delete_def_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_acl_delete_def_file (value gv, value dirv);

value
guestfs_int_ocaml_acl_delete_def_file (value gv, value dirv)
{
  CAMLparam2 (gv, dirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("acl_delete_def_file");

  char *dir;
  dir = strdup (String_val (dirv));
  if (dir == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_acl_delete_def_file (g, dir);
  caml_leave_blocking_section ();
  free (dir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "acl_delete_def_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val acl_get_file : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_acl_get_file (value gv, value pathv, value acltypev);

value
guestfs_int_ocaml_acl_get_file (value gv, value pathv, value acltypev)
{
  CAMLparam3 (gv, pathv, acltypev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("acl_get_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *acltype;
  acltype = strdup (String_val (acltypev));
  if (acltype == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_acl_get_file (g, path, acltype);
  caml_leave_blocking_section ();
  free (path);
  free (acltype);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "acl_get_file");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val acl_set_file : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_acl_set_file (value gv, value pathv, value acltypev, value aclv);

value
guestfs_int_ocaml_acl_set_file (value gv, value pathv, value acltypev, value aclv)
{
  CAMLparam4 (gv, pathv, acltypev, aclv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("acl_set_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *acltype;
  acltype = strdup (String_val (acltypev));
  if (acltype == NULL) caml_raise_out_of_memory ();
  char *acl;
  acl = strdup (String_val (aclv));
  if (acl == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_acl_set_file (g, path, acltype, acl);
  caml_leave_blocking_section ();
  free (path);
  free (acltype);
  free (acl);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "acl_set_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_cdrom : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_cdrom (value gv, value filenamev);

value
guestfs_int_ocaml_add_cdrom (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_cdrom");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_add_cdrom (g, filename);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_cdrom");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_domain : t -> ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_domain (value gv, value libvirturiv, value readonlyv, value ifacev, value livev, value allowuuidv, value readonlydiskv, value cachemodev, value discardv, value copyonreadv, value domv);

value
guestfs_int_ocaml_add_domain (value gv, value libvirturiv, value readonlyv, value ifacev, value livev, value allowuuidv, value readonlydiskv, value cachemodev, value discardv, value copyonreadv, value domv)
{
  CAMLparam5 (gv, libvirturiv, readonlyv, ifacev, livev);
  CAMLxparam5 (allowuuidv, readonlydiskv, cachemodev, discardv, copyonreadv);
  CAMLxparam1 (domv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_domain");

  char *dom;
  dom = strdup (String_val (domv));
  if (dom == NULL) caml_raise_out_of_memory ();
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  if (libvirturiv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
    optargs_s.libvirturi = strdup (String_val (Field (libvirturiv, 0)));
    if (optargs_s.libvirturi == NULL) caml_raise_out_of_memory ();
  }
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (ifacev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
    optargs_s.iface = strdup (String_val (Field (ifacev, 0)));
    if (optargs_s.iface == NULL) caml_raise_out_of_memory ();
  }
  if (livev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
    optargs_s.live = Bool_val (Field (livev, 0));
  }
  if (allowuuidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
    optargs_s.allowuuid = Bool_val (Field (allowuuidv, 0));
  }
  if (readonlydiskv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
    optargs_s.readonlydisk = strdup (String_val (Field (readonlydiskv, 0)));
    if (optargs_s.readonlydisk == NULL) caml_raise_out_of_memory ();
  }
  if (cachemodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK;
    optargs_s.cachemode = strdup (String_val (Field (cachemodev, 0)));
    if (optargs_s.cachemode == NULL) caml_raise_out_of_memory ();
  }
  if (discardv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_DISCARD_BITMASK;
    optargs_s.discard = strdup (String_val (Field (discardv, 0)));
    if (optargs_s.discard == NULL) caml_raise_out_of_memory ();
  }
  if (copyonreadv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK;
    optargs_s.copyonread = Bool_val (Field (copyonreadv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_domain_argv (g, dom, optargs);
  caml_leave_blocking_section ();
  free (dom);
  if (libvirturiv != Val_int (0))
    free ((char *) optargs_s.libvirturi);
  if (ifacev != Val_int (0))
    free ((char *) optargs_s.iface);
  if (readonlydiskv != Val_int (0))
    free ((char *) optargs_s.readonlydisk);
  if (cachemodev != Val_int (0))
    free ((char *) optargs_s.cachemode);
  if (discardv != Val_int (0))
    free ((char *) optargs_s.discard);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_domain");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_domain_byte (value *argv, int argn);

value
guestfs_int_ocaml_add_domain_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_add_domain (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
}

/* Automatically generated wrapper for function
 * val add_drive : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive (value gv, value readonlyv, value formatv, value ifacev, value namev, value labelv, value protocolv, value serverv, value usernamev, value secretv, value cachemodev, value discardv, value copyonreadv, value filenamev);

value
guestfs_int_ocaml_add_drive (value gv, value readonlyv, value formatv, value ifacev, value namev, value labelv, value protocolv, value serverv, value usernamev, value secretv, value cachemodev, value discardv, value copyonreadv, value filenamev)
{
  CAMLparam5 (gv, readonlyv, formatv, ifacev, namev);
  CAMLxparam5 (labelv, protocolv, serverv, usernamev, secretv);
  CAMLxparam4 (cachemodev, discardv, copyonreadv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_drive");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (formatv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
    optargs_s.format = strdup (String_val (Field (formatv, 0)));
    if (optargs_s.format == NULL) caml_raise_out_of_memory ();
  }
  if (ifacev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
    optargs_s.iface = strdup (String_val (Field (ifacev, 0)));
    if (optargs_s.iface == NULL) caml_raise_out_of_memory ();
  }
  if (namev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
    optargs_s.name = strdup (String_val (Field (namev, 0)));
    if (optargs_s.name == NULL) caml_raise_out_of_memory ();
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  if (protocolv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
    optargs_s.protocol = strdup (String_val (Field (protocolv, 0)));
    if (optargs_s.protocol == NULL) caml_raise_out_of_memory ();
  }
  if (serverv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
    optargs_s.server = guestfs_int_ocaml_strings_val (g, Field (serverv, 0));
  }
  if (usernamev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
    optargs_s.username = strdup (String_val (Field (usernamev, 0)));
    if (optargs_s.username == NULL) caml_raise_out_of_memory ();
  }
  if (secretv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
    optargs_s.secret = strdup (String_val (Field (secretv, 0)));
    if (optargs_s.secret == NULL) caml_raise_out_of_memory ();
  }
  if (cachemodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
    optargs_s.cachemode = strdup (String_val (Field (cachemodev, 0)));
    if (optargs_s.cachemode == NULL) caml_raise_out_of_memory ();
  }
  if (discardv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
    optargs_s.discard = strdup (String_val (Field (discardv, 0)));
    if (optargs_s.discard == NULL) caml_raise_out_of_memory ();
  }
  if (copyonreadv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
    optargs_s.copyonread = Bool_val (Field (copyonreadv, 0));
  }
  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  free (filename);
  if (formatv != Val_int (0))
    free ((char *) optargs_s.format);
  if (ifacev != Val_int (0))
    free ((char *) optargs_s.iface);
  if (namev != Val_int (0))
    free ((char *) optargs_s.name);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (protocolv != Val_int (0))
    free ((char *) optargs_s.protocol);
  if (serverv != Val_int (0))
    guestfs_int_free_string_list ((char **) optargs_s.server);
  if (usernamev != Val_int (0))
    free ((char *) optargs_s.username);
  if (secretv != Val_int (0))
    free ((char *) optargs_s.secret);
  if (cachemodev != Val_int (0))
    free ((char *) optargs_s.cachemode);
  if (discardv != Val_int (0))
    free ((char *) optargs_s.discard);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_drive");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive_byte (value *argv, int argn);

value
guestfs_int_ocaml_add_drive_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_add_drive (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]);
}

/* Automatically generated wrapper for function
 * val add_drive_ro : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive_ro (value gv, value filenamev);

value
guestfs_int_ocaml_add_drive_ro (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_drive_ro");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_add_drive_ro (g, filename);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_drive_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_ro_with_if : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive_ro_with_if (value gv, value filenamev, value ifacev);

value
guestfs_int_ocaml_add_drive_ro_with_if (value gv, value filenamev, value ifacev)
{
  CAMLparam3 (gv, filenamev, ifacev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_drive_ro_with_if");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *iface;
  iface = strdup (String_val (ifacev));
  if (iface == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  free (filename);
  free (iface);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_drive_ro_with_if");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_scratch : t -> ?name:string -> ?label:string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive_scratch (value gv, value namev, value labelv, value sizev);

value
guestfs_int_ocaml_add_drive_scratch (value gv, value namev, value labelv, value sizev)
{
  CAMLparam4 (gv, namev, labelv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_drive_scratch");

  int64_t size = Int64_val (sizev);
  struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  if (namev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
    optargs_s.name = strdup (String_val (Field (namev, 0)));
    if (optargs_s.name == NULL) caml_raise_out_of_memory ();
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_add_drive_scratch_argv (g, size, optargs);
  if (namev != Val_int (0))
    free ((char *) optargs_s.name);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_drive_scratch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_with_if : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_drive_with_if (value gv, value filenamev, value ifacev);

value
guestfs_int_ocaml_add_drive_with_if (value gv, value filenamev, value ifacev)
{
  CAMLparam3 (gv, filenamev, ifacev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_drive_with_if");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *iface;
  iface = strdup (String_val (ifacev));
  if (iface == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  free (filename);
  free (iface);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_drive_with_if");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_libvirt_dom : t -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> int64 -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_libvirt_dom (value gv, value readonlyv, value ifacev, value livev, value readonlydiskv, value cachemodev, value discardv, value copyonreadv, value domv);

value
guestfs_int_ocaml_add_libvirt_dom (value gv, value readonlyv, value ifacev, value livev, value readonlydiskv, value cachemodev, value discardv, value copyonreadv, value domv)
{
  CAMLparam5 (gv, readonlyv, ifacev, livev, readonlydiskv);
  CAMLxparam4 (cachemodev, discardv, copyonreadv, domv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("add_libvirt_dom");

  void * /* virDomainPtr */ dom = POINTER_NOT_IMPLEMENTED ("virDomainPtr");
  struct guestfs_add_libvirt_dom_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (ifacev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK;
    optargs_s.iface = strdup (String_val (Field (ifacev, 0)));
    if (optargs_s.iface == NULL) caml_raise_out_of_memory ();
  }
  if (livev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK;
    optargs_s.live = Bool_val (Field (livev, 0));
  }
  if (readonlydiskv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK;
    optargs_s.readonlydisk = strdup (String_val (Field (readonlydiskv, 0)));
    if (optargs_s.readonlydisk == NULL) caml_raise_out_of_memory ();
  }
  if (cachemodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
    optargs_s.cachemode = strdup (String_val (Field (cachemodev, 0)));
    if (optargs_s.cachemode == NULL) caml_raise_out_of_memory ();
  }
  if (discardv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
    optargs_s.discard = strdup (String_val (Field (discardv, 0)));
    if (optargs_s.discard == NULL) caml_raise_out_of_memory ();
  }
  if (copyonreadv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK;
    optargs_s.copyonread = Bool_val (Field (copyonreadv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_libvirt_dom_argv (g, dom, optargs);
  caml_leave_blocking_section ();
  if (ifacev != Val_int (0))
    free ((char *) optargs_s.iface);
  if (readonlydiskv != Val_int (0))
    free ((char *) optargs_s.readonlydisk);
  if (cachemodev != Val_int (0))
    free ((char *) optargs_s.cachemode);
  if (discardv != Val_int (0))
    free ((char *) optargs_s.discard);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "add_libvirt_dom");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_add_libvirt_dom_byte (value *argv, int argn);

value
guestfs_int_ocaml_add_libvirt_dom_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_add_libvirt_dom (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

/* Automatically generated wrapper for function
 * val aug_clear : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_clear (value gv, value augpathv);

value
guestfs_int_ocaml_aug_clear (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_clear");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_clear (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_clear");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_close (value gv);

value
guestfs_int_ocaml_aug_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_defnode : t -> string -> string -> string -> int_bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_defnode (value gv, value namev, value exprv, value valv);

value
guestfs_int_ocaml_aug_defnode (value gv, value namev, value exprv, value valv)
{
  CAMLparam4 (gv, namev, exprv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_defnode");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *expr;
  expr = strdup (String_val (exprv));
  if (expr == NULL) caml_raise_out_of_memory ();
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  struct guestfs_int_bool *r;

  caml_enter_blocking_section ();
  r = guestfs_aug_defnode (g, name, expr, val);
  caml_leave_blocking_section ();
  free (name);
  free (expr);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "aug_defnode");

  rv = copy_int_bool (r);
  guestfs_free_int_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_defvar : t -> string -> string option -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_defvar (value gv, value namev, value exprv);

value
guestfs_int_ocaml_aug_defvar (value gv, value namev, value exprv)
{
  CAMLparam3 (gv, namev, exprv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_defvar");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *expr;
  if (exprv == Val_int (0))
    expr = NULL;
  else {
    expr = strdup (String_val (Field (exprv, 0)));
    if (expr == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_defvar (g, name, expr);
  caml_leave_blocking_section ();
  free (name);
  free (expr);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_defvar");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_get : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_get (value gv, value augpathv);

value
guestfs_int_ocaml_aug_get (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_get");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_aug_get (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "aug_get");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_init : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_init (value gv, value rootv, value flagsv);

value
guestfs_int_ocaml_aug_init (value gv, value rootv, value flagsv)
{
  CAMLparam3 (gv, rootv, flagsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_init");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int flags = Int_val (flagsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_init (g, root, flags);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_insert : t -> string -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_insert (value gv, value augpathv, value labelv, value beforev);

value
guestfs_int_ocaml_aug_insert (value gv, value augpathv, value labelv, value beforev)
{
  CAMLparam4 (gv, augpathv, labelv, beforev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_insert");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int before = Bool_val (beforev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_insert (g, augpath, label, before);
  caml_leave_blocking_section ();
  free (augpath);
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_insert");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_label (value gv, value augpathv);

value
guestfs_int_ocaml_aug_label (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_label");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_aug_label (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "aug_label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_load : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_load (value gv);

value
guestfs_int_ocaml_aug_load (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_load");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_load (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_load");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_ls : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_ls (value gv, value augpathv);

value
guestfs_int_ocaml_aug_ls (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_ls");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_aug_ls (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "aug_ls");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_match : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_match (value gv, value augpathv);

value
guestfs_int_ocaml_aug_match (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_match");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_aug_match (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "aug_match");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_mv : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_mv (value gv, value srcv, value destv);

value
guestfs_int_ocaml_aug_mv (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_mv");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_mv (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_mv");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_rm : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_rm (value gv, value augpathv);

value
guestfs_int_ocaml_aug_rm (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_rm");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_rm (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_rm");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_save : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_save (value gv);

value
guestfs_int_ocaml_aug_save (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_save");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_save (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_save");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_set : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_set (value gv, value augpathv, value valv);

value
guestfs_int_ocaml_aug_set (value gv, value augpathv, value valv)
{
  CAMLparam3 (gv, augpathv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_set");

  char *augpath;
  augpath = strdup (String_val (augpathv));
  if (augpath == NULL) caml_raise_out_of_memory ();
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_set (g, augpath, val);
  caml_leave_blocking_section ();
  free (augpath);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_set");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_setm : t -> string -> string option -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_setm (value gv, value basev, value subv, value valv);

value
guestfs_int_ocaml_aug_setm (value gv, value basev, value subv, value valv)
{
  CAMLparam4 (gv, basev, subv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_setm");

  char *base;
  base = strdup (String_val (basev));
  if (base == NULL) caml_raise_out_of_memory ();
  char *sub;
  if (subv == Val_int (0))
    sub = NULL;
  else {
    sub = strdup (String_val (Field (subv, 0)));
    if (sub == NULL) caml_raise_out_of_memory ();
  }
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_setm (g, base, sub, val);
  caml_leave_blocking_section ();
  free (base);
  free (sub);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_setm");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_transform : t -> ?remove:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_aug_transform (value gv, value removev, value lensv, value filev);

value
guestfs_int_ocaml_aug_transform (value gv, value removev, value lensv, value filev)
{
  CAMLparam4 (gv, removev, lensv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("aug_transform");

  char *lens;
  lens = strdup (String_val (lensv));
  if (lens == NULL) caml_raise_out_of_memory ();
  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  struct guestfs_aug_transform_argv optargs_s = { .bitmask = 0 };
  struct guestfs_aug_transform_argv *optargs = &optargs_s;
  if (removev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_AUG_TRANSFORM_REMOVE_BITMASK;
    optargs_s.remove = Bool_val (Field (removev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_transform_argv (g, lens, file, optargs);
  caml_leave_blocking_section ();
  free (lens);
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "aug_transform");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val available : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_available (value gv, value groupsv);

value
guestfs_int_ocaml_available (value gv, value groupsv)
{
  CAMLparam2 (gv, groupsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("available");

  char **groups = guestfs_int_ocaml_strings_val (g, groupsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_available (g, groups);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (groups);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "available");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val available_all_groups : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_available_all_groups (value gv);

value
guestfs_int_ocaml_available_all_groups (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("available_all_groups");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_available_all_groups (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "available_all_groups");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val base64_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_base64_in (value gv, value base64filev, value filenamev);

value
guestfs_int_ocaml_base64_in (value gv, value base64filev, value filenamev)
{
  CAMLparam3 (gv, base64filev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("base64_in");

  char *base64file;
  base64file = strdup (String_val (base64filev));
  if (base64file == NULL) caml_raise_out_of_memory ();
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_base64_in (g, base64file, filename);
  caml_leave_blocking_section ();
  free (base64file);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "base64_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val base64_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_base64_out (value gv, value filenamev, value base64filev);

value
guestfs_int_ocaml_base64_out (value gv, value filenamev, value base64filev)
{
  CAMLparam3 (gv, filenamev, base64filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("base64_out");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *base64file;
  base64file = strdup (String_val (base64filev));
  if (base64file == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_base64_out (g, filename, base64file);
  caml_leave_blocking_section ();
  free (filename);
  free (base64file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "base64_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blkdiscard : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blkdiscard (value gv, value devicev);

value
guestfs_int_ocaml_blkdiscard (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blkdiscard");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blkdiscard (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blkdiscard");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blkdiscardzeroes : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blkdiscardzeroes (value gv, value devicev);

value
guestfs_int_ocaml_blkdiscardzeroes (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blkdiscardzeroes");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blkdiscardzeroes (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blkdiscardzeroes");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blkid : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blkid (value gv, value devicev);

value
guestfs_int_ocaml_blkid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blkid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_blkid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "blkid");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_flushbufs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_flushbufs (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_flushbufs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_flushbufs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_flushbufs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_flushbufs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getbsz : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_getbsz (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_getbsz (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_getbsz");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getbsz (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_getbsz");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getro : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_getro (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_getro (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_getro");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getro (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_getro");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getsize64 : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_getsize64 (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_getsize64 (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_getsize64");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getsize64 (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_getsize64");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getss : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_getss (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_getss (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_getss");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getss (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_getss");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getsz : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_getsz (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_getsz (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_getsz");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getsz (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_getsz");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_rereadpt : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_rereadpt (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_rereadpt (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_rereadpt");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_rereadpt (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_rereadpt");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setbsz : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_setbsz (value gv, value devicev, value blocksizev);

value
guestfs_int_ocaml_blockdev_setbsz (value gv, value devicev, value blocksizev)
{
  CAMLparam3 (gv, devicev, blocksizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_setbsz");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int blocksize = Int_val (blocksizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setbsz (g, device, blocksize);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_setbsz");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setra : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_setra (value gv, value devicev, value sectorsv);

value
guestfs_int_ocaml_blockdev_setra (value gv, value devicev, value sectorsv)
{
  CAMLparam3 (gv, devicev, sectorsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_setra");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int sectors = Int_val (sectorsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setra (g, device, sectors);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_setra");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setro : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_setro (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_setro (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_setro");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setro (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_setro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setrw : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_blockdev_setrw (value gv, value devicev);

value
guestfs_int_ocaml_blockdev_setrw (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("blockdev_setrw");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setrw (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "blockdev_setrw");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_balance_cancel : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_balance_cancel (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_balance_cancel (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_balance_cancel");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_balance_cancel (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_balance_cancel");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_balance_pause : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_balance_pause (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_balance_pause (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_balance_pause");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_balance_pause (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_balance_pause");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_balance_resume : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_balance_resume (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_balance_resume (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_balance_resume");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_balance_resume (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_balance_resume");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_balance_status : t -> string -> btrfsbalance
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_balance_status (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_balance_status (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_balance_status");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfsbalance *r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_balance_status (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_balance_status");

  rv = copy_btrfsbalance (r);
  guestfs_free_btrfsbalance (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_device_add : t -> string array -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_device_add (value gv, value devicesv, value fsv);

value
guestfs_int_ocaml_btrfs_device_add (value gv, value devicesv, value fsv)
{
  CAMLparam3 (gv, devicesv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_device_add");

  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_device_add (g, devices, fs);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (devices);
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_device_add");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_device_delete : t -> string array -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_device_delete (value gv, value devicesv, value fsv);

value
guestfs_int_ocaml_btrfs_device_delete (value gv, value devicesv, value fsv)
{
  CAMLparam3 (gv, devicesv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_device_delete");

  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_device_delete (g, devices, fs);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (devices);
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_device_delete");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_balance : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_filesystem_balance (value gv, value fsv);

value
guestfs_int_ocaml_btrfs_filesystem_balance (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_filesystem_balance");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_balance (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_filesystem_balance");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_defragment : t -> ?flush:bool -> ?compress:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_filesystem_defragment (value gv, value flushv, value compressv, value pathv);

value
guestfs_int_ocaml_btrfs_filesystem_defragment (value gv, value flushv, value compressv, value pathv)
{
  CAMLparam4 (gv, flushv, compressv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_filesystem_defragment");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  if (flushv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
    optargs_s.flush = Bool_val (Field (flushv, 0));
  }
  if (compressv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
    optargs_s.compress = strdup (String_val (Field (compressv, 0)));
    if (optargs_s.compress == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (compressv != Val_int (0))
    free ((char *) optargs_s.compress);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_filesystem_defragment");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_resize : t -> ?size:int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_filesystem_resize (value gv, value sizev, value mountpointv);

value
guestfs_int_ocaml_btrfs_filesystem_resize (value gv, value sizev, value mountpointv)
{
  CAMLparam3 (gv, sizev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_filesystem_resize");

  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  caml_leave_blocking_section ();
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_filesystem_resize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_show : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_filesystem_show (value gv, value devicev);

value
guestfs_int_ocaml_btrfs_filesystem_show (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_filesystem_show");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_show (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_filesystem_show");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_sync : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_filesystem_sync (value gv, value fsv);

value
guestfs_int_ocaml_btrfs_filesystem_sync (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_filesystem_sync");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_sync (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_filesystem_sync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_fsck : t -> ?superblock:int64 -> ?repair:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_fsck (value gv, value superblockv, value repairv, value devicev);

value
guestfs_int_ocaml_btrfs_fsck (value gv, value superblockv, value repairv, value devicev)
{
  CAMLparam4 (gv, superblockv, repairv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_fsck");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  if (superblockv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
    optargs_s.superblock = Int64_val (Field (superblockv, 0));
  }
  if (repairv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
    optargs_s.repair = Bool_val (Field (repairv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_fsck");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_image : t -> ?compresslevel:int -> string array -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_image (value gv, value compresslevelv, value sourcev, value imagev);

value
guestfs_int_ocaml_btrfs_image (value gv, value compresslevelv, value sourcev, value imagev)
{
  CAMLparam4 (gv, compresslevelv, sourcev, imagev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_image");

  char **source = guestfs_int_ocaml_strings_val (g, sourcev);
  char *image;
  image = strdup (String_val (imagev));
  if (image == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_image_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  if (compresslevelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
    optargs_s.compresslevel = Int_val (Field (compresslevelv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_image_argv (g, source, image, optargs);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (source);
  free (image);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_image");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_assign : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_assign (value gv, value srcv, value dstv, value pathv);

value
guestfs_int_ocaml_btrfs_qgroup_assign (value gv, value srcv, value dstv, value pathv)
{
  CAMLparam4 (gv, srcv, dstv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_assign");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dst;
  dst = strdup (String_val (dstv));
  if (dst == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);
  caml_leave_blocking_section ();
  free (src);
  free (dst);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_assign");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_create : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_create (value gv, value qgroupidv, value subvolumev);

value
guestfs_int_ocaml_btrfs_qgroup_create (value gv, value qgroupidv, value subvolumev)
{
  CAMLparam3 (gv, qgroupidv, subvolumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_create");

  char *qgroupid;
  qgroupid = strdup (String_val (qgroupidv));
  if (qgroupid == NULL) caml_raise_out_of_memory ();
  char *subvolume;
  subvolume = strdup (String_val (subvolumev));
  if (subvolume == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);
  caml_leave_blocking_section ();
  free (qgroupid);
  free (subvolume);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_destroy : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_destroy (value gv, value qgroupidv, value subvolumev);

value
guestfs_int_ocaml_btrfs_qgroup_destroy (value gv, value qgroupidv, value subvolumev)
{
  CAMLparam3 (gv, qgroupidv, subvolumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_destroy");

  char *qgroupid;
  qgroupid = strdup (String_val (qgroupidv));
  if (qgroupid == NULL) caml_raise_out_of_memory ();
  char *subvolume;
  subvolume = strdup (String_val (subvolumev));
  if (subvolume == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);
  caml_leave_blocking_section ();
  free (qgroupid);
  free (subvolume);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_destroy");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_limit : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_limit (value gv, value subvolumev, value sizev);

value
guestfs_int_ocaml_btrfs_qgroup_limit (value gv, value subvolumev, value sizev)
{
  CAMLparam3 (gv, subvolumev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_limit");

  char *subvolume;
  subvolume = strdup (String_val (subvolumev));
  if (subvolume == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);
  caml_leave_blocking_section ();
  free (subvolume);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_limit");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_remove : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_remove (value gv, value srcv, value dstv, value pathv);

value
guestfs_int_ocaml_btrfs_qgroup_remove (value gv, value srcv, value dstv, value pathv)
{
  CAMLparam4 (gv, srcv, dstv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_remove");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dst;
  dst = strdup (String_val (dstv));
  if (dst == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);
  caml_leave_blocking_section ();
  free (src);
  free (dst);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_remove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_qgroup_show : t -> string -> btrfsqgroup array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_qgroup_show (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_qgroup_show (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_qgroup_show");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfsqgroup_list *r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_qgroup_show (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_qgroup_show");

  rv = copy_btrfsqgroup_list (r);
  guestfs_free_btrfsqgroup_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_quota_enable : t -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_quota_enable (value gv, value fsv, value enablev);

value
guestfs_int_ocaml_btrfs_quota_enable (value gv, value fsv, value enablev)
{
  CAMLparam3 (gv, fsv, enablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_quota_enable");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int enable = Bool_val (enablev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_quota_enable (g, fs, enable);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_quota_enable");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_quota_rescan : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_quota_rescan (value gv, value fsv);

value
guestfs_int_ocaml_btrfs_quota_rescan (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_quota_rescan");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_quota_rescan (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_quota_rescan");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_replace : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_replace (value gv, value srcdevv, value targetdevv, value mntpointv);

value
guestfs_int_ocaml_btrfs_replace (value gv, value srcdevv, value targetdevv, value mntpointv)
{
  CAMLparam4 (gv, srcdevv, targetdevv, mntpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_replace");

  char *srcdev;
  srcdev = strdup (String_val (srcdevv));
  if (srcdev == NULL) caml_raise_out_of_memory ();
  char *targetdev;
  targetdev = strdup (String_val (targetdevv));
  if (targetdev == NULL) caml_raise_out_of_memory ();
  char *mntpoint;
  mntpoint = strdup (String_val (mntpointv));
  if (mntpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);
  caml_leave_blocking_section ();
  free (srcdev);
  free (targetdev);
  free (mntpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_replace");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_rescue_chunk_recover : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_rescue_chunk_recover (value gv, value devicev);

value
guestfs_int_ocaml_btrfs_rescue_chunk_recover (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_rescue_chunk_recover");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_rescue_chunk_recover (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_rescue_chunk_recover");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_rescue_super_recover : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_rescue_super_recover (value gv, value devicev);

value
guestfs_int_ocaml_btrfs_rescue_super_recover (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_rescue_super_recover");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_rescue_super_recover (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_rescue_super_recover");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_scrub_cancel : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_scrub_cancel (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_scrub_cancel (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_scrub_cancel");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_scrub_cancel (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_scrub_cancel");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_scrub_resume : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_scrub_resume (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_scrub_resume (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_scrub_resume");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_scrub_resume (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_scrub_resume");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_scrub_start : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_scrub_start (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_scrub_start (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_scrub_start");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_scrub_start (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_scrub_start");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_scrub_status : t -> string -> btrfsscrub
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_scrub_status (value gv, value pathv);

value
guestfs_int_ocaml_btrfs_scrub_status (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_scrub_status");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfsscrub *r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_scrub_status (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_scrub_status");

  rv = copy_btrfsscrub (r);
  guestfs_free_btrfsscrub (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_set_seeding : t -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_set_seeding (value gv, value devicev, value seedingv);

value
guestfs_int_ocaml_btrfs_set_seeding (value gv, value devicev, value seedingv)
{
  CAMLparam3 (gv, devicev, seedingv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_set_seeding");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int seeding = Bool_val (seedingv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_set_seeding (g, device, seeding);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_set_seeding");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_create : t -> ?qgroupid:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_create (value gv, value qgroupidv, value destv);

value
guestfs_int_ocaml_btrfs_subvolume_create (value gv, value qgroupidv, value destv)
{
  CAMLparam3 (gv, qgroupidv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_create");

  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;
  if (qgroupidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK;
    optargs_s.qgroupid = strdup (String_val (Field (qgroupidv, 0)));
    if (optargs_s.qgroupid == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);
  caml_leave_blocking_section ();
  free (dest);
  if (qgroupidv != Val_int (0))
    free ((char *) optargs_s.qgroupid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_delete : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_delete (value gv, value subvolumev);

value
guestfs_int_ocaml_btrfs_subvolume_delete (value gv, value subvolumev)
{
  CAMLparam2 (gv, subvolumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_delete");

  char *subvolume;
  subvolume = strdup (String_val (subvolumev));
  if (subvolume == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  caml_leave_blocking_section ();
  free (subvolume);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_delete");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_get_default : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_get_default (value gv, value fsv);

value
guestfs_int_ocaml_btrfs_subvolume_get_default (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_get_default");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_get_default (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_get_default");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_list : t -> string -> btrfssubvolume array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_list (value gv, value fsv);

value
guestfs_int_ocaml_btrfs_subvolume_list (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_list");

  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfssubvolume_list *r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_list (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_list");

  rv = copy_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_set_default : t -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_set_default (value gv, value idv, value fsv);

value
guestfs_int_ocaml_btrfs_subvolume_set_default (value gv, value idv, value fsv)
{
  CAMLparam3 (gv, idv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_set_default");

  int64_t id = Int64_val (idv);
  char *fs;
  fs = strdup (String_val (fsv));
  if (fs == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_set_default");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_show : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_show (value gv, value subvolumev);

value
guestfs_int_ocaml_btrfs_subvolume_show (value gv, value subvolumev)
{
  CAMLparam2 (gv, subvolumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_show");

  char *subvolume;
  subvolume = strdup (String_val (subvolumev));
  if (subvolume == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_show (g, subvolume);
  caml_leave_blocking_section ();
  free (subvolume);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_show");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_snapshot : t -> ?ro:bool -> ?qgroupid:string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfs_subvolume_snapshot (value gv, value rov, value qgroupidv, value sourcev, value destv);

value
guestfs_int_ocaml_btrfs_subvolume_snapshot (value gv, value rov, value qgroupidv, value sourcev, value destv)
{
  CAMLparam5 (gv, rov, qgroupidv, sourcev, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfs_subvolume_snapshot");

  char *source;
  source = strdup (String_val (sourcev));
  if (source == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;
  if (rov != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK;
    optargs_s.ro = Bool_val (Field (rov, 0));
  }
  if (qgroupidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK;
    optargs_s.qgroupid = strdup (String_val (Field (qgroupidv, 0)));
    if (optargs_s.qgroupid == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);
  caml_leave_blocking_section ();
  free (source);
  free (dest);
  if (qgroupidv != Val_int (0))
    free ((char *) optargs_s.qgroupid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfs_subvolume_snapshot");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfstune_enable_extended_inode_refs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfstune_enable_extended_inode_refs (value gv, value devicev);

value
guestfs_int_ocaml_btrfstune_enable_extended_inode_refs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfstune_enable_extended_inode_refs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfstune_enable_extended_inode_refs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfstune_enable_extended_inode_refs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfstune_enable_skinny_metadata_extent_refs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfstune_enable_skinny_metadata_extent_refs (value gv, value devicev);

value
guestfs_int_ocaml_btrfstune_enable_skinny_metadata_extent_refs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfstune_enable_skinny_metadata_extent_refs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfstune_enable_skinny_metadata_extent_refs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfstune_seeding : t -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_btrfstune_seeding (value gv, value devicev, value seedingv);

value
guestfs_int_ocaml_btrfstune_seeding (value gv, value devicev, value seedingv)
{
  CAMLparam3 (gv, devicev, seedingv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("btrfstune_seeding");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int seeding = Bool_val (seedingv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfstune_seeding (g, device, seeding);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "btrfstune_seeding");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val c_pointer : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_c_pointer (value gv);

value
guestfs_int_ocaml_c_pointer (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("c_pointer");

  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_c_pointer (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "c_pointer");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val canonical_device_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_canonical_device_name (value gv, value devicev);

value
guestfs_int_ocaml_canonical_device_name (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("canonical_device_name");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_canonical_device_name (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "canonical_device_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cap_get_file : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cap_get_file (value gv, value pathv);

value
guestfs_int_ocaml_cap_get_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cap_get_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_cap_get_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "cap_get_file");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cap_set_file : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cap_set_file (value gv, value pathv, value capv);

value
guestfs_int_ocaml_cap_set_file (value gv, value pathv, value capv)
{
  CAMLparam3 (gv, pathv, capv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cap_set_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *cap;
  cap = strdup (String_val (capv));
  if (cap == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cap_set_file (g, path, cap);
  caml_leave_blocking_section ();
  free (path);
  free (cap);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "cap_set_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val case_sensitive_path : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_case_sensitive_path (value gv, value pathv);

value
guestfs_int_ocaml_case_sensitive_path (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("case_sensitive_path");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_case_sensitive_path (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "case_sensitive_path");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cat : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cat (value gv, value pathv);

value
guestfs_int_ocaml_cat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cat");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_cat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "cat");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksum : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_checksum (value gv, value csumtypev, value pathv);

value
guestfs_int_ocaml_checksum (value gv, value csumtypev, value pathv)
{
  CAMLparam3 (gv, csumtypev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("checksum");

  char *csumtype;
  csumtype = strdup (String_val (csumtypev));
  if (csumtype == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_checksum (g, csumtype, path);
  caml_leave_blocking_section ();
  free (csumtype);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "checksum");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksum_device : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_checksum_device (value gv, value csumtypev, value devicev);

value
guestfs_int_ocaml_checksum_device (value gv, value csumtypev, value devicev)
{
  CAMLparam3 (gv, csumtypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("checksum_device");

  char *csumtype;
  csumtype = strdup (String_val (csumtypev));
  if (csumtype == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_checksum_device (g, csumtype, device);
  caml_leave_blocking_section ();
  free (csumtype);
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "checksum_device");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksums_out : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_checksums_out (value gv, value csumtypev, value directoryv, value sumsfilev);

value
guestfs_int_ocaml_checksums_out (value gv, value csumtypev, value directoryv, value sumsfilev)
{
  CAMLparam4 (gv, csumtypev, directoryv, sumsfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("checksums_out");

  char *csumtype;
  csumtype = strdup (String_val (csumtypev));
  if (csumtype == NULL) caml_raise_out_of_memory ();
  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *sumsfile;
  sumsfile = strdup (String_val (sumsfilev));
  if (sumsfile == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  caml_leave_blocking_section ();
  free (csumtype);
  free (directory);
  free (sumsfile);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "checksums_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val chmod : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_chmod (value gv, value modev, value pathv);

value
guestfs_int_ocaml_chmod (value gv, value modev, value pathv)
{
  CAMLparam3 (gv, modev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("chmod");

  int mode = Int_val (modev);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_chmod (g, mode, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "chmod");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val chown : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_chown (value gv, value ownerv, value groupv, value pathv);

value
guestfs_int_ocaml_chown (value gv, value ownerv, value groupv, value pathv)
{
  CAMLparam4 (gv, ownerv, groupv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("chown");

  int owner = Int_val (ownerv);
  int group = Int_val (groupv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_chown (g, owner, group, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "chown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val clear_backend_setting : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_clear_backend_setting (value gv, value namev);

value
guestfs_int_ocaml_clear_backend_setting (value gv, value namev)
{
  CAMLparam2 (gv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("clear_backend_setting");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_clear_backend_setting (g, name);
  free (name);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "clear_backend_setting");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val command : t -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_command (value gv, value argumentsv);

value
guestfs_int_ocaml_command (value gv, value argumentsv)
{
  CAMLparam2 (gv, argumentsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("command");

  char **arguments = guestfs_int_ocaml_strings_val (g, argumentsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_command (g, arguments);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (arguments);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "command");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val command_lines : t -> string array -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_command_lines (value gv, value argumentsv);

value
guestfs_int_ocaml_command_lines (value gv, value argumentsv)
{
  CAMLparam2 (gv, argumentsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("command_lines");

  char **arguments = guestfs_int_ocaml_strings_val (g, argumentsv);
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_command_lines (g, arguments);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (arguments);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "command_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val compress_device_out : t -> ?level:int -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_compress_device_out (value gv, value levelv, value ctypev, value devicev, value zdevicev);

value
guestfs_int_ocaml_compress_device_out (value gv, value levelv, value ctypev, value devicev, value zdevicev)
{
  CAMLparam5 (gv, levelv, ctypev, devicev, zdevicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("compress_device_out");

  char *ctype;
  ctype = strdup (String_val (ctypev));
  if (ctype == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *zdevice;
  zdevice = strdup (String_val (zdevicev));
  if (zdevice == NULL) caml_raise_out_of_memory ();
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  if (levelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
    optargs_s.level = Int_val (Field (levelv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  caml_leave_blocking_section ();
  free (ctype);
  free (device);
  free (zdevice);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "compress_device_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val compress_out : t -> ?level:int -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_compress_out (value gv, value levelv, value ctypev, value filev, value zfilev);

value
guestfs_int_ocaml_compress_out (value gv, value levelv, value ctypev, value filev, value zfilev)
{
  CAMLparam5 (gv, levelv, ctypev, filev, zfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("compress_out");

  char *ctype;
  ctype = strdup (String_val (ctypev));
  if (ctype == NULL) caml_raise_out_of_memory ();
  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  char *zfile;
  zfile = strdup (String_val (zfilev));
  if (zfile == NULL) caml_raise_out_of_memory ();
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  if (levelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
    optargs_s.level = Int_val (Field (levelv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  caml_leave_blocking_section ();
  free (ctype);
  free (file);
  free (zfile);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "compress_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val config : t -> string -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_config (value gv, value hvparamv, value hvvaluev);

value
guestfs_int_ocaml_config (value gv, value hvparamv, value hvvaluev)
{
  CAMLparam3 (gv, hvparamv, hvvaluev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("config");

  char *hvparam;
  hvparam = strdup (String_val (hvparamv));
  if (hvparam == NULL) caml_raise_out_of_memory ();
  char *hvvalue;
  if (hvvaluev == Val_int (0))
    hvvalue = NULL;
  else {
    hvvalue = strdup (String_val (Field (hvvaluev, 0)));
    if (hvvalue == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_config (g, hvparam, hvvalue);
  free (hvparam);
  free (hvvalue);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "config");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val copy_attributes : t -> ?all:bool -> ?mode:bool -> ?xattributes:bool -> ?ownership:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_attributes (value gv, value allv, value modev, value xattributesv, value ownershipv, value srcv, value destv);

value
guestfs_int_ocaml_copy_attributes (value gv, value allv, value modev, value xattributesv, value ownershipv, value srcv, value destv)
{
  CAMLparam5 (gv, allv, modev, xattributesv, ownershipv);
  CAMLxparam2 (srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_attributes");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  if (allv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
    optargs_s.all = Bool_val (Field (allv, 0));
  }
  if (modev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
    optargs_s.mode = Bool_val (Field (modev, 0));
  }
  if (xattributesv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
    optargs_s.xattributes = Bool_val (Field (xattributesv, 0));
  }
  if (ownershipv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
    optargs_s.ownership = Bool_val (Field (ownershipv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_attributes_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_attributes");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_attributes_byte (value *argv, int argn);

value
guestfs_int_ocaml_copy_attributes_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_copy_attributes (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val copy_device_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_device_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv);

value
guestfs_int_ocaml_copy_device_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, sparsev);
  CAMLxparam3 (appendv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_device_to_device");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  if (srcoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = Int64_val (Field (srcoffsetv, 0));
  }
  if (destoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = Int64_val (Field (destoffsetv, 0));
  }
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  if (sparsev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = Bool_val (Field (sparsev, 0));
  }
  if (appendv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
    optargs_s.append = Bool_val (Field (appendv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_device_to_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_device_to_device_byte (value *argv, int argn);

value
guestfs_int_ocaml_copy_device_to_device_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_copy_device_to_device (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val copy_device_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_device_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv);

value
guestfs_int_ocaml_copy_device_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, sparsev);
  CAMLxparam3 (appendv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_device_to_file");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  if (srcoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = Int64_val (Field (srcoffsetv, 0));
  }
  if (destoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = Int64_val (Field (destoffsetv, 0));
  }
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  if (sparsev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = Bool_val (Field (sparsev, 0));
  }
  if (appendv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
    optargs_s.append = Bool_val (Field (appendv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_device_to_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_device_to_file_byte (value *argv, int argn);

value
guestfs_int_ocaml_copy_device_to_file_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_copy_device_to_file (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val copy_file_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_file_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv);

value
guestfs_int_ocaml_copy_file_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, sparsev);
  CAMLxparam3 (appendv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_file_to_device");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  if (srcoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = Int64_val (Field (srcoffsetv, 0));
  }
  if (destoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = Int64_val (Field (destoffsetv, 0));
  }
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  if (sparsev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = Bool_val (Field (sparsev, 0));
  }
  if (appendv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
    optargs_s.append = Bool_val (Field (appendv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_file_to_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_file_to_device_byte (value *argv, int argn);

value
guestfs_int_ocaml_copy_file_to_device_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_copy_file_to_device (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val copy_file_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_file_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv);

value
guestfs_int_ocaml_copy_file_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value sparsev, value appendv, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, sparsev);
  CAMLxparam3 (appendv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_file_to_file");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  if (srcoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = Int64_val (Field (srcoffsetv, 0));
  }
  if (destoffsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = Int64_val (Field (destoffsetv, 0));
  }
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  if (sparsev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = Bool_val (Field (sparsev, 0));
  }
  if (appendv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
    optargs_s.append = Bool_val (Field (appendv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_file_to_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_file_to_file_byte (value *argv, int argn);

value
guestfs_int_ocaml_copy_file_to_file_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_copy_file_to_file (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val copy_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_in (value gv, value localpathv, value remotedirv);

value
guestfs_int_ocaml_copy_in (value gv, value localpathv, value remotedirv)
{
  CAMLparam3 (gv, localpathv, remotedirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_in");

  char *localpath;
  localpath = strdup (String_val (localpathv));
  if (localpath == NULL) caml_raise_out_of_memory ();
  char *remotedir;
  remotedir = strdup (String_val (remotedirv));
  if (remotedir == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_in (g, localpath, remotedir);
  caml_leave_blocking_section ();
  free (localpath);
  free (remotedir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val copy_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_out (value gv, value remotepathv, value localdirv);

value
guestfs_int_ocaml_copy_out (value gv, value remotepathv, value localdirv)
{
  CAMLparam3 (gv, remotepathv, localdirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_out");

  char *remotepath;
  remotepath = strdup (String_val (remotepathv));
  if (remotepath == NULL) caml_raise_out_of_memory ();
  char *localdir;
  localdir = strdup (String_val (localdirv));
  if (localdir == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_out (g, remotepath, localdir);
  caml_leave_blocking_section ();
  free (remotepath);
  free (localdir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val copy_size : t -> string -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_copy_size (value gv, value srcv, value destv, value sizev);

value
guestfs_int_ocaml_copy_size (value gv, value srcv, value destv, value sizev)
{
  CAMLparam4 (gv, srcv, destv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("copy_size");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_size (g, src, dest, size);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "copy_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cp : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cp (value gv, value srcv, value destv);

value
guestfs_int_ocaml_cp (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cp");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cp (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "cp");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cp_a : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cp_a (value gv, value srcv, value destv);

value
guestfs_int_ocaml_cp_a (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cp_a");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cp_a (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "cp_a");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cp_r : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cp_r (value gv, value srcv, value destv);

value
guestfs_int_ocaml_cp_r (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cp_r");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cp_r (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "cp_r");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cpio_out : t -> ?format:string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_cpio_out (value gv, value formatv, value directoryv, value cpiofilev);

value
guestfs_int_ocaml_cpio_out (value gv, value formatv, value directoryv, value cpiofilev)
{
  CAMLparam4 (gv, formatv, directoryv, cpiofilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("cpio_out");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *cpiofile;
  cpiofile = strdup (String_val (cpiofilev));
  if (cpiofile == NULL) caml_raise_out_of_memory ();
  struct guestfs_cpio_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  if (formatv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_CPIO_OUT_FORMAT_BITMASK;
    optargs_s.format = strdup (String_val (Field (formatv, 0)));
    if (optargs_s.format == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);
  caml_leave_blocking_section ();
  free (directory);
  free (cpiofile);
  if (formatv != Val_int (0))
    free ((char *) optargs_s.format);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "cpio_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val dd : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_dd (value gv, value srcv, value destv);

value
guestfs_int_ocaml_dd (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("dd");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_dd (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "dd");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug : t -> string -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_debug (value gv, value subcmdv, value extraargsv);

value
guestfs_int_ocaml_debug (value gv, value subcmdv, value extraargsv)
{
  CAMLparam3 (gv, subcmdv, extraargsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("debug");

  char *subcmd;
  subcmd = strdup (String_val (subcmdv));
  if (subcmd == NULL) caml_raise_out_of_memory ();
  char **extraargs = guestfs_int_ocaml_strings_val (g, extraargsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_debug (g, subcmd, extraargs);
  caml_leave_blocking_section ();
  free (subcmd);
  guestfs_int_free_string_list (extraargs);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "debug");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug_drives : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_debug_drives (value gv);

value
guestfs_int_ocaml_debug_drives (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("debug_drives");

  size_t i;
  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "debug_drives");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug_upload : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_debug_upload (value gv, value filenamev, value tmpnamev, value modev);

value
guestfs_int_ocaml_debug_upload (value gv, value filenamev, value tmpnamev, value modev)
{
  CAMLparam4 (gv, filenamev, tmpnamev, modev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("debug_upload");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *tmpname;
  tmpname = strdup (String_val (tmpnamev));
  if (tmpname == NULL) caml_raise_out_of_memory ();
  int mode = Int_val (modev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_debug_upload (g, filename, tmpname, mode);
  caml_leave_blocking_section ();
  free (filename);
  free (tmpname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "debug_upload");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val device_index : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_device_index (value gv, value devicev);

value
guestfs_int_ocaml_device_index (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("device_index");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_device_index (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "device_index");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val df : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_df (value gv);

value
guestfs_int_ocaml_df (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("df");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_df (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "df");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val df_h : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_df_h (value gv);

value
guestfs_int_ocaml_df_h (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("df_h");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_df_h (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "df_h");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val disk_create : t -> ?backingfile:string -> ?backingformat:string -> ?preallocation:string -> ?compat:string -> ?clustersize:int -> string -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_disk_create (value gv, value backingfilev, value backingformatv, value preallocationv, value compatv, value clustersizev, value filenamev, value formatv, value sizev);

value
guestfs_int_ocaml_disk_create (value gv, value backingfilev, value backingformatv, value preallocationv, value compatv, value clustersizev, value filenamev, value formatv, value sizev)
{
  CAMLparam5 (gv, backingfilev, backingformatv, preallocationv, compatv);
  CAMLxparam4 (clustersizev, filenamev, formatv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("disk_create");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *format;
  format = strdup (String_val (formatv));
  if (format == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  if (backingfilev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
    optargs_s.backingfile = strdup (String_val (Field (backingfilev, 0)));
    if (optargs_s.backingfile == NULL) caml_raise_out_of_memory ();
  }
  if (backingformatv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
    optargs_s.backingformat = strdup (String_val (Field (backingformatv, 0)));
    if (optargs_s.backingformat == NULL) caml_raise_out_of_memory ();
  }
  if (preallocationv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
    optargs_s.preallocation = strdup (String_val (Field (preallocationv, 0)));
    if (optargs_s.preallocation == NULL) caml_raise_out_of_memory ();
  }
  if (compatv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
    optargs_s.compat = strdup (String_val (Field (compatv, 0)));
    if (optargs_s.compat == NULL) caml_raise_out_of_memory ();
  }
  if (clustersizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
    optargs_s.clustersize = Int_val (Field (clustersizev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_disk_create_argv (g, filename, format, size, optargs);
  caml_leave_blocking_section ();
  free (filename);
  free (format);
  if (backingfilev != Val_int (0))
    free ((char *) optargs_s.backingfile);
  if (backingformatv != Val_int (0))
    free ((char *) optargs_s.backingformat);
  if (preallocationv != Val_int (0))
    free ((char *) optargs_s.preallocation);
  if (compatv != Val_int (0))
    free ((char *) optargs_s.compat);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "disk_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_disk_create_byte (value *argv, int argn);

value
guestfs_int_ocaml_disk_create_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_disk_create (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

/* Automatically generated wrapper for function
 * val disk_format : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_disk_format (value gv, value filenamev);

value
guestfs_int_ocaml_disk_format (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("disk_format");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_disk_format (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "disk_format");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val disk_has_backing_file : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_disk_has_backing_file (value gv, value filenamev);

value
guestfs_int_ocaml_disk_has_backing_file (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("disk_has_backing_file");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_disk_has_backing_file (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "disk_has_backing_file");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val disk_virtual_size : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_disk_virtual_size (value gv, value filenamev);

value
guestfs_int_ocaml_disk_virtual_size (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("disk_virtual_size");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_disk_virtual_size (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "disk_virtual_size");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val dmesg : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_dmesg (value gv);

value
guestfs_int_ocaml_dmesg (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("dmesg");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_dmesg (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "dmesg");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val download : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_download (value gv, value remotefilenamev, value filenamev);

value
guestfs_int_ocaml_download (value gv, value remotefilenamev, value filenamev)
{
  CAMLparam3 (gv, remotefilenamev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("download");

  char *remotefilename;
  remotefilename = strdup (String_val (remotefilenamev));
  if (remotefilename == NULL) caml_raise_out_of_memory ();
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download (g, remotefilename, filename);
  caml_leave_blocking_section ();
  free (remotefilename);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "download");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val download_blocks : t -> ?unallocated:bool -> string -> int64 -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_download_blocks (value gv, value unallocatedv, value devicev, value startv, value stopv, value filenamev);

value
guestfs_int_ocaml_download_blocks (value gv, value unallocatedv, value devicev, value startv, value stopv, value filenamev)
{
  CAMLparam5 (gv, unallocatedv, devicev, startv, stopv);
  CAMLxparam1 (filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("download_blocks");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t start = Int64_val (startv);
  int64_t stop = Int64_val (stopv);
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  struct guestfs_download_blocks_argv optargs_s = { .bitmask = 0 };
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  if (unallocatedv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK;
    optargs_s.unallocated = Bool_val (Field (unallocatedv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);
  caml_leave_blocking_section ();
  free (device);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "download_blocks");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_download_blocks_byte (value *argv, int argn);

value
guestfs_int_ocaml_download_blocks_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_download_blocks (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val download_inode : t -> string -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_download_inode (value gv, value devicev, value inodev, value filenamev);

value
guestfs_int_ocaml_download_inode (value gv, value devicev, value inodev, value filenamev)
{
  CAMLparam4 (gv, devicev, inodev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("download_inode");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t inode = Int64_val (inodev);
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download_inode (g, device, inode, filename);
  caml_leave_blocking_section ();
  free (device);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "download_inode");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val download_offset : t -> string -> string -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_download_offset (value gv, value remotefilenamev, value filenamev, value offsetv, value sizev);

value
guestfs_int_ocaml_download_offset (value gv, value remotefilenamev, value filenamev, value offsetv, value sizev)
{
  CAMLparam5 (gv, remotefilenamev, filenamev, offsetv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("download_offset");

  char *remotefilename;
  remotefilename = strdup (String_val (remotefilenamev));
  if (remotefilename == NULL) caml_raise_out_of_memory ();
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int64_t offset = Int64_val (offsetv);
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  caml_leave_blocking_section ();
  free (remotefilename);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "download_offset");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val drop_caches : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_drop_caches (value gv, value whattodropv);

value
guestfs_int_ocaml_drop_caches (value gv, value whattodropv)
{
  CAMLparam2 (gv, whattodropv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("drop_caches");

  int whattodrop = Int_val (whattodropv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_drop_caches (g, whattodrop);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "drop_caches");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val du : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_du (value gv, value pathv);

value
guestfs_int_ocaml_du (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("du");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_du (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "du");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val e2fsck : t -> ?correct:bool -> ?forceall:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_e2fsck (value gv, value correctv, value forceallv, value devicev);

value
guestfs_int_ocaml_e2fsck (value gv, value correctv, value forceallv, value devicev)
{
  CAMLparam4 (gv, correctv, forceallv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("e2fsck");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  if (correctv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
    optargs_s.correct = Bool_val (Field (correctv, 0));
  }
  if (forceallv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
    optargs_s.forceall = Bool_val (Field (forceallv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_e2fsck_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "e2fsck");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val e2fsck_f : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_e2fsck_f (value gv, value devicev);

value
guestfs_int_ocaml_e2fsck_f (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("e2fsck_f");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_e2fsck_f (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "e2fsck_f");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val echo_daemon : t -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_echo_daemon (value gv, value wordsv);

value
guestfs_int_ocaml_echo_daemon (value gv, value wordsv)
{
  CAMLparam2 (gv, wordsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("echo_daemon");

  char **words = guestfs_int_ocaml_strings_val (g, wordsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_echo_daemon (g, words);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (words);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "echo_daemon");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val egrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_egrep (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_egrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("egrep");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_egrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "egrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val egrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_egrepi (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_egrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("egrepi");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_egrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "egrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val equal : t -> string -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_equal (value gv, value file1v, value file2v);

value
guestfs_int_ocaml_equal (value gv, value file1v, value file2v)
{
  CAMLparam3 (gv, file1v, file2v);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("equal");

  char *file1;
  file1 = strdup (String_val (file1v));
  if (file1 == NULL) caml_raise_out_of_memory ();
  char *file2;
  file2 = strdup (String_val (file2v));
  if (file2 == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_equal (g, file1, file2);
  caml_leave_blocking_section ();
  free (file1);
  free (file2);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "equal");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val exists : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_exists (value gv, value pathv);

value
guestfs_int_ocaml_exists (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("exists");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_exists (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "exists");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val extlinux : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_extlinux (value gv, value directoryv);

value
guestfs_int_ocaml_extlinux (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("extlinux");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_extlinux (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "extlinux");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fallocate : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fallocate (value gv, value pathv, value lenv);

value
guestfs_int_ocaml_fallocate (value gv, value pathv, value lenv)
{
  CAMLparam3 (gv, pathv, lenv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fallocate");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int len = Int_val (lenv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fallocate (g, path, len);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fallocate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fallocate64 : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fallocate64 (value gv, value pathv, value lenv);

value
guestfs_int_ocaml_fallocate64 (value gv, value pathv, value lenv)
{
  CAMLparam3 (gv, pathv, lenv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fallocate64");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int64_t len = Int64_val (lenv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fallocate64 (g, path, len);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fallocate64");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val feature_available : t -> string array -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_feature_available (value gv, value groupsv);

value
guestfs_int_ocaml_feature_available (value gv, value groupsv)
{
  CAMLparam2 (gv, groupsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("feature_available");

  char **groups = guestfs_int_ocaml_strings_val (g, groupsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_feature_available (g, groups);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (groups);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "feature_available");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fgrep (value gv, value patternv, value pathv);

value
guestfs_int_ocaml_fgrep (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fgrep");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_fgrep (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "fgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fgrepi (value gv, value patternv, value pathv);

value
guestfs_int_ocaml_fgrepi (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fgrepi");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_fgrepi (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "fgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val file : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_file (value gv, value pathv);

value
guestfs_int_ocaml_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "file");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val file_architecture : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_file_architecture (value gv, value filenamev);

value
guestfs_int_ocaml_file_architecture (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("file_architecture");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_file_architecture (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "file_architecture");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val filesize : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_filesize (value gv, value filev);

value
guestfs_int_ocaml_filesize (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("filesize");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_filesize (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "filesize");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val filesystem_available : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_filesystem_available (value gv, value filesystemv);

value
guestfs_int_ocaml_filesystem_available (value gv, value filesystemv)
{
  CAMLparam2 (gv, filesystemv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("filesystem_available");

  char *filesystem;
  filesystem = strdup (String_val (filesystemv));
  if (filesystem == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_filesystem_available (g, filesystem);
  caml_leave_blocking_section ();
  free (filesystem);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "filesystem_available");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val filesystem_walk : t -> string -> tsk_dirent array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_filesystem_walk (value gv, value devicev);

value
guestfs_int_ocaml_filesystem_walk (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("filesystem_walk");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_tsk_dirent_list *r;

  caml_enter_blocking_section ();
  r = guestfs_filesystem_walk (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "filesystem_walk");

  rv = copy_tsk_dirent_list (r);
  guestfs_free_tsk_dirent_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fill : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fill (value gv, value cv, value lenv, value pathv);

value
guestfs_int_ocaml_fill (value gv, value cv, value lenv, value pathv)
{
  CAMLparam4 (gv, cv, lenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fill");

  int c = Int_val (cv);
  int len = Int_val (lenv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fill (g, c, len, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fill");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fill_dir : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fill_dir (value gv, value dirv, value nrv);

value
guestfs_int_ocaml_fill_dir (value gv, value dirv, value nrv)
{
  CAMLparam3 (gv, dirv, nrv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fill_dir");

  char *dir;
  dir = strdup (String_val (dirv));
  if (dir == NULL) caml_raise_out_of_memory ();
  int nr = Int_val (nrv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fill_dir (g, dir, nr);
  caml_leave_blocking_section ();
  free (dir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fill_dir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fill_pattern : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fill_pattern (value gv, value patternv, value lenv, value pathv);

value
guestfs_int_ocaml_fill_pattern (value gv, value patternv, value lenv, value pathv)
{
  CAMLparam4 (gv, patternv, lenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fill_pattern");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  int len = Int_val (lenv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fill_pattern (g, pattern, len, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fill_pattern");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val find : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_find (value gv, value directoryv);

value
guestfs_int_ocaml_find (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("find");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_find (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "find");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val find0 : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_find0 (value gv, value directoryv, value filesv);

value
guestfs_int_ocaml_find0 (value gv, value directoryv, value filesv)
{
  CAMLparam3 (gv, directoryv, filesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("find0");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *files;
  files = strdup (String_val (filesv));
  if (files == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_find0 (g, directory, files);
  caml_leave_blocking_section ();
  free (directory);
  free (files);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "find0");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val find_inode : t -> string -> int64 -> tsk_dirent array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_find_inode (value gv, value devicev, value inodev);

value
guestfs_int_ocaml_find_inode (value gv, value devicev, value inodev)
{
  CAMLparam3 (gv, devicev, inodev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("find_inode");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t inode = Int64_val (inodev);
  struct guestfs_tsk_dirent_list *r;

  caml_enter_blocking_section ();
  r = guestfs_find_inode (g, device, inode);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "find_inode");

  rv = copy_tsk_dirent_list (r);
  guestfs_free_tsk_dirent_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val findfs_label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_findfs_label (value gv, value labelv);

value
guestfs_int_ocaml_findfs_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("findfs_label");

  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_findfs_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "findfs_label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val findfs_uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_findfs_uuid (value gv, value uuidv);

value
guestfs_int_ocaml_findfs_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("findfs_uuid");

  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_findfs_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "findfs_uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fsck : t -> string -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fsck (value gv, value fstypev, value devicev);

value
guestfs_int_ocaml_fsck (value gv, value fstypev, value devicev)
{
  CAMLparam3 (gv, fstypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fsck");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fsck (g, fstype, device);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fsck");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fstrim : t -> ?offset:int64 -> ?length:int64 -> ?minimumfreeextent:int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_fstrim (value gv, value offsetv, value lengthv, value minimumfreeextentv, value mountpointv);

value
guestfs_int_ocaml_fstrim (value gv, value offsetv, value lengthv, value minimumfreeextentv, value mountpointv)
{
  CAMLparam5 (gv, offsetv, lengthv, minimumfreeextentv, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("fstrim");

  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  if (offsetv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
    optargs_s.offset = Int64_val (Field (offsetv, 0));
  }
  if (lengthv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
    optargs_s.length = Int64_val (Field (lengthv, 0));
  }
  if (minimumfreeextentv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
    optargs_s.minimumfreeextent = Int64_val (Field (minimumfreeextentv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fstrim_argv (g, mountpoint, optargs);
  caml_leave_blocking_section ();
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "fstrim");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_append : t -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_append (value gv);

value
guestfs_int_ocaml_get_append (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_append");

  const char *r;

  r = guestfs_get_append (g);

  if (r) { /* Some string */
    v = caml_alloc (1, 0);
    v2 = caml_copy_string (r);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_attach_method : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_attach_method (value gv);

value
guestfs_int_ocaml_get_attach_method (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_attach_method");

  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_attach_method");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_autosync : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_autosync (value gv);

value
guestfs_int_ocaml_get_autosync (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_autosync");

  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_autosync");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_backend : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_backend (value gv);

value
guestfs_int_ocaml_get_backend (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_backend");

  char *r;

  r = guestfs_get_backend (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_backend");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_backend_setting : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_backend_setting (value gv, value namev);

value
guestfs_int_ocaml_get_backend_setting (value gv, value namev)
{
  CAMLparam2 (gv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_backend_setting");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *r;

  r = guestfs_get_backend_setting (g, name);
  free (name);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_backend_setting");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_backend_settings : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_backend_settings (value gv);

value
guestfs_int_ocaml_get_backend_settings (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_backend_settings");

  size_t i;
  char **r;

  r = guestfs_get_backend_settings (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_backend_settings");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_cachedir : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_cachedir (value gv);

value
guestfs_int_ocaml_get_cachedir (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_cachedir");

  char *r;

  r = guestfs_get_cachedir (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_cachedir");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_direct : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_direct (value gv);

value
guestfs_int_ocaml_get_direct (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_direct");

  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_direct");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2attrs : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_e2attrs (value gv, value filev);

value
guestfs_int_ocaml_get_e2attrs (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_e2attrs");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2attrs (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_e2attrs");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2generation : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_e2generation (value gv, value filev);

value
guestfs_int_ocaml_get_e2generation (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_e2generation");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2generation (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_e2generation");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_e2label (value gv, value devicev);

value
guestfs_int_ocaml_get_e2label (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_e2label");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2label (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_e2label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_e2uuid (value gv, value devicev);

value
guestfs_int_ocaml_get_e2uuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_e2uuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2uuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_e2uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_hv : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_hv (value gv);

value
guestfs_int_ocaml_get_hv (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_hv");

  char *r;

  r = guestfs_get_hv (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_hv");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_identifier : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_identifier (value gv);

value
guestfs_int_ocaml_get_identifier (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_identifier");

  const char *r;

  r = guestfs_get_identifier (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_identifier");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_libvirt_requested_credential_challenge : t -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_libvirt_requested_credential_challenge (value gv, value indexv);

value
guestfs_int_ocaml_get_libvirt_requested_credential_challenge (value gv, value indexv)
{
  CAMLparam2 (gv, indexv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_libvirt_requested_credential_challenge");

  int index = Int_val (indexv);
  char *r;

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_libvirt_requested_credential_challenge");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_libvirt_requested_credential_defresult : t -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_libvirt_requested_credential_defresult (value gv, value indexv);

value
guestfs_int_ocaml_get_libvirt_requested_credential_defresult (value gv, value indexv)
{
  CAMLparam2 (gv, indexv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_libvirt_requested_credential_defresult");

  int index = Int_val (indexv);
  char *r;

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_libvirt_requested_credential_defresult");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_libvirt_requested_credential_prompt : t -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_libvirt_requested_credential_prompt (value gv, value indexv);

value
guestfs_int_ocaml_get_libvirt_requested_credential_prompt (value gv, value indexv)
{
  CAMLparam2 (gv, indexv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_libvirt_requested_credential_prompt");

  int index = Int_val (indexv);
  char *r;

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_libvirt_requested_credential_prompt");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_libvirt_requested_credentials : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_libvirt_requested_credentials (value gv);

value
guestfs_int_ocaml_get_libvirt_requested_credentials (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_libvirt_requested_credentials");

  size_t i;
  char **r;

  r = guestfs_get_libvirt_requested_credentials (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_libvirt_requested_credentials");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_memsize : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_memsize (value gv);

value
guestfs_int_ocaml_get_memsize (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_memsize");

  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_memsize");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_network : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_network (value gv);

value
guestfs_int_ocaml_get_network (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_network");

  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_network");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_path : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_path (value gv);

value
guestfs_int_ocaml_get_path (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_path");

  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_path");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_pgroup : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_pgroup (value gv);

value
guestfs_int_ocaml_get_pgroup (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_pgroup");

  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_pgroup");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_pid : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_pid (value gv);

value
guestfs_int_ocaml_get_pid (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_pid");

  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_pid");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_program : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_program (value gv);

value
guestfs_int_ocaml_get_program (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_program");

  const char *r;

  r = guestfs_get_program (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_program");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_qemu : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_qemu (value gv);

value
guestfs_int_ocaml_get_qemu (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_qemu");

  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_qemu");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_recovery_proc : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_recovery_proc (value gv);

value
guestfs_int_ocaml_get_recovery_proc (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_recovery_proc");

  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_recovery_proc");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_selinux : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_selinux (value gv);

value
guestfs_int_ocaml_get_selinux (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_selinux");

  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_selinux");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_smp : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_smp (value gv);

value
guestfs_int_ocaml_get_smp (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_smp");

  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_smp");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_sockdir : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_sockdir (value gv);

value
guestfs_int_ocaml_get_sockdir (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_sockdir");

  char *r;

  r = guestfs_get_sockdir (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_sockdir");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_state : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_state (value gv);

value
guestfs_int_ocaml_get_state (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_state");

  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_state");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_tmpdir : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_tmpdir (value gv);

value
guestfs_int_ocaml_get_tmpdir (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_tmpdir");

  char *r;

  r = guestfs_get_tmpdir (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "get_tmpdir");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_trace : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_trace (value gv);

value
guestfs_int_ocaml_get_trace (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_trace");

  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_trace");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_umask : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_umask (value gv);

value
guestfs_int_ocaml_get_umask (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_umask");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_umask (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_umask");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_verbose : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_get_verbose (value gv);

value
guestfs_int_ocaml_get_verbose (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("get_verbose");

  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "get_verbose");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getcon : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_getcon (value gv);

value
guestfs_int_ocaml_getcon (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("getcon");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_getcon (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "getcon");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getxattr : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_getxattr (value gv, value pathv, value namev);

value
guestfs_int_ocaml_getxattr (value gv, value pathv, value namev)
{
  CAMLparam3 (gv, pathv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("getxattr");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_getxattr (g, path, name, &size);
  caml_leave_blocking_section ();
  free (path);
  free (name);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "getxattr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getxattrs : t -> string -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_getxattrs (value gv, value pathv);

value
guestfs_int_ocaml_getxattrs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("getxattrs");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_getxattrs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "getxattrs");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val glob_expand : t -> ?directoryslash:bool -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_glob_expand (value gv, value directoryslashv, value patternv);

value
guestfs_int_ocaml_glob_expand (value gv, value directoryslashv, value patternv)
{
  CAMLparam3 (gv, directoryslashv, patternv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("glob_expand");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  struct guestfs_glob_expand_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  if (directoryslashv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK;
    optargs_s.directoryslash = Bool_val (Field (directoryslashv, 0));
  }
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);
  caml_leave_blocking_section ();
  free (pattern);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "glob_expand");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val grep : t -> ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_grep (value gv, value extendedv, value fixedv, value insensitivev, value compressedv, value regexv, value pathv);

value
guestfs_int_ocaml_grep (value gv, value extendedv, value fixedv, value insensitivev, value compressedv, value regexv, value pathv)
{
  CAMLparam5 (gv, extendedv, fixedv, insensitivev, compressedv);
  CAMLxparam2 (regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("grep");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  if (extendedv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
    optargs_s.extended = Bool_val (Field (extendedv, 0));
  }
  if (fixedv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
    optargs_s.fixed = Bool_val (Field (fixedv, 0));
  }
  if (insensitivev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
    optargs_s.insensitive = Bool_val (Field (insensitivev, 0));
  }
  if (compressedv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
    optargs_s.compressed = Bool_val (Field (compressedv, 0));
  }
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_grep_opts_argv (g, regex, path, optargs);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "grep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_grep_byte (value *argv, int argn);

value
guestfs_int_ocaml_grep_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_grep (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val grepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_grepi (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_grepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("grepi");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_grepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "grepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val grub_install : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_grub_install (value gv, value rootv, value devicev);

value
guestfs_int_ocaml_grub_install (value gv, value rootv, value devicev)
{
  CAMLparam3 (gv, rootv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("grub_install");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_grub_install (g, root, device);
  caml_leave_blocking_section ();
  free (root);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "grub_install");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val head : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_head (value gv, value pathv);

value
guestfs_int_ocaml_head (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("head");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_head (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "head");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val head_n : t -> int -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_head_n (value gv, value nrlinesv, value pathv);

value
guestfs_int_ocaml_head_n (value gv, value nrlinesv, value pathv)
{
  CAMLparam3 (gv, nrlinesv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("head_n");

  int nrlines = Int_val (nrlinesv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_head_n (g, nrlines, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "head_n");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hexdump : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hexdump (value gv, value pathv);

value
guestfs_int_ocaml_hexdump (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hexdump");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_hexdump (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hexdump");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_close (value gv);

value
guestfs_int_ocaml_hivex_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_commit : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_commit (value gv, value filenamev);

value
guestfs_int_ocaml_hivex_commit (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_commit");

  char *filename;
  if (filenamev == Val_int (0))
    filename = NULL;
  else {
    filename = strdup (String_val (Field (filenamev, 0)));
    if (filename == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_commit (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_commit");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_add_child : t -> int64 -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_add_child (value gv, value parentv, value namev);

value
guestfs_int_ocaml_hivex_node_add_child (value gv, value parentv, value namev)
{
  CAMLparam3 (gv, parentv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_add_child");

  int64_t parent = Int64_val (parentv);
  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_add_child (g, parent, name);
  caml_leave_blocking_section ();
  free (name);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_add_child");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_children : t -> int64 -> hivex_node array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_children (value gv, value nodehv);

value
guestfs_int_ocaml_hivex_node_children (value gv, value nodehv)
{
  CAMLparam2 (gv, nodehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_children");

  int64_t nodeh = Int64_val (nodehv);
  struct guestfs_hivex_node_list *r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_children (g, nodeh);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_node_children");

  rv = copy_hivex_node_list (r);
  guestfs_free_hivex_node_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_delete_child : t -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_delete_child (value gv, value nodehv);

value
guestfs_int_ocaml_hivex_node_delete_child (value gv, value nodehv)
{
  CAMLparam2 (gv, nodehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_delete_child");

  int64_t nodeh = Int64_val (nodehv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_delete_child (g, nodeh);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_delete_child");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_get_child : t -> int64 -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_get_child (value gv, value nodehv, value namev);

value
guestfs_int_ocaml_hivex_node_get_child (value gv, value nodehv, value namev)
{
  CAMLparam3 (gv, nodehv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_get_child");

  int64_t nodeh = Int64_val (nodehv);
  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_get_child (g, nodeh, name);
  caml_leave_blocking_section ();
  free (name);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_get_child");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_get_value : t -> int64 -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_get_value (value gv, value nodehv, value keyv);

value
guestfs_int_ocaml_hivex_node_get_value (value gv, value nodehv, value keyv)
{
  CAMLparam3 (gv, nodehv, keyv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_get_value");

  int64_t nodeh = Int64_val (nodehv);
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_get_value (g, nodeh, key);
  caml_leave_blocking_section ();
  free (key);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_get_value");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_name : t -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_name (value gv, value nodehv);

value
guestfs_int_ocaml_hivex_node_name (value gv, value nodehv)
{
  CAMLparam2 (gv, nodehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_name");

  int64_t nodeh = Int64_val (nodehv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_name (g, nodeh);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_node_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_parent : t -> int64 -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_parent (value gv, value nodehv);

value
guestfs_int_ocaml_hivex_node_parent (value gv, value nodehv)
{
  CAMLparam2 (gv, nodehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_parent");

  int64_t nodeh = Int64_val (nodehv);
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_parent (g, nodeh);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_parent");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_set_value : t -> int64 -> string -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_set_value (value gv, value nodehv, value keyv, value tv, value valv);

value
guestfs_int_ocaml_hivex_node_set_value (value gv, value nodehv, value keyv, value tv, value valv)
{
  CAMLparam5 (gv, nodehv, keyv, tv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_set_value");

  int64_t nodeh = Int64_val (nodehv);
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  int64_t t = Int64_val (tv);
  size_t val_size = caml_string_length (valv);
  char *val;
  val = malloc (val_size);
  if (val == NULL) caml_raise_out_of_memory ();
  memcpy (val, String_val (valv), val_size);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
  caml_leave_blocking_section ();
  free (key);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_node_set_value");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_node_values : t -> int64 -> hivex_value array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_node_values (value gv, value nodehv);

value
guestfs_int_ocaml_hivex_node_values (value gv, value nodehv)
{
  CAMLparam2 (gv, nodehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_node_values");

  int64_t nodeh = Int64_val (nodehv);
  struct guestfs_hivex_value_list *r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_node_values (g, nodeh);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_node_values");

  rv = copy_hivex_value_list (r);
  guestfs_free_hivex_value_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_open : t -> ?verbose:bool -> ?debug:bool -> ?write:bool -> ?unsafe:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_open (value gv, value verbosev, value debugv, value writev, value unsafev, value filenamev);

value
guestfs_int_ocaml_hivex_open (value gv, value verbosev, value debugv, value writev, value unsafev, value filenamev)
{
  CAMLparam5 (gv, verbosev, debugv, writev, unsafev);
  CAMLxparam1 (filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_open");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  if (verbosev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
    optargs_s.verbose = Bool_val (Field (verbosev, 0));
  }
  if (debugv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
    optargs_s.debug = Bool_val (Field (debugv, 0));
  }
  if (writev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
    optargs_s.write = Bool_val (Field (writev, 0));
  }
  if (unsafev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK;
    optargs_s.unsafe = Bool_val (Field (unsafev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_open_argv (g, filename, optargs);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_open");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_open_byte (value *argv, int argn);

value
guestfs_int_ocaml_hivex_open_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_hivex_open (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val hivex_root : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_root (value gv);

value
guestfs_int_ocaml_hivex_root (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_root");

  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_root (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_root");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_value_key : t -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_value_key (value gv, value valuehv);

value
guestfs_int_ocaml_hivex_value_key (value gv, value valuehv)
{
  CAMLparam2 (gv, valuehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_value_key");

  int64_t valueh = Int64_val (valuehv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_value_key (g, valueh);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_value_key");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_value_type : t -> int64 -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_value_type (value gv, value valuehv);

value
guestfs_int_ocaml_hivex_value_type (value gv, value valuehv)
{
  CAMLparam2 (gv, valuehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_value_type");

  int64_t valueh = Int64_val (valuehv);
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_value_type (g, valueh);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "hivex_value_type");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_value_utf8 : t -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_value_utf8 (value gv, value valuehv);

value
guestfs_int_ocaml_hivex_value_utf8 (value gv, value valuehv)
{
  CAMLparam2 (gv, valuehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_value_utf8");

  int64_t valueh = Int64_val (valuehv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_hivex_value_utf8 (g, valueh);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_value_utf8");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hivex_value_value : t -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_hivex_value_value (value gv, value valuehv);

value
guestfs_int_ocaml_hivex_value_value (value gv, value valuehv)
{
  CAMLparam2 (gv, valuehv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("hivex_value_value");

  int64_t valueh = Int64_val (valuehv);
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_hivex_value_value (g, valueh, &size);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "hivex_value_value");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val initrd_cat : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_initrd_cat (value gv, value initrdpathv, value filenamev);

value
guestfs_int_ocaml_initrd_cat (value gv, value initrdpathv, value filenamev)
{
  CAMLparam3 (gv, initrdpathv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("initrd_cat");

  char *initrdpath;
  initrdpath = strdup (String_val (initrdpathv));
  if (initrdpath == NULL) caml_raise_out_of_memory ();
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  caml_leave_blocking_section ();
  free (initrdpath);
  free (filename);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "initrd_cat");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val initrd_list : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_initrd_list (value gv, value pathv);

value
guestfs_int_ocaml_initrd_list (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("initrd_list");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_initrd_list (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "initrd_list");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_add_watch : t -> string -> int -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_add_watch (value gv, value pathv, value maskv);

value
guestfs_int_ocaml_inotify_add_watch (value gv, value pathv, value maskv)
{
  CAMLparam3 (gv, pathv, maskv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_add_watch");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int mask = Int_val (maskv);
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_add_watch (g, path, mask);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inotify_add_watch");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_close (value gv);

value
guestfs_int_ocaml_inotify_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inotify_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_files : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_files (value gv);

value
guestfs_int_ocaml_inotify_files (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_files");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_files (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inotify_files");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_init : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_init (value gv, value maxeventsv);

value
guestfs_int_ocaml_inotify_init (value gv, value maxeventsv)
{
  CAMLparam2 (gv, maxeventsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_init");

  int maxevents = Int_val (maxeventsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_init (g, maxevents);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inotify_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_read : t -> inotify_event array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_read (value gv);

value
guestfs_int_ocaml_inotify_read (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_read");

  struct guestfs_inotify_event_list *r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_read (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inotify_read");

  rv = copy_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_rm_watch : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inotify_rm_watch (value gv, value wdv);

value
guestfs_int_ocaml_inotify_rm_watch (value gv, value wdv)
{
  CAMLparam2 (gv, wdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inotify_rm_watch");

  int wd = Int_val (wdv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_rm_watch (g, wd);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inotify_rm_watch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_arch : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_arch (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_arch (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_arch");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_arch (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_arch");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_distro : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_distro (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_distro (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_distro");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_distro (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_distro");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_drive_mappings : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_drive_mappings (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_drive_mappings (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_drive_mappings");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_drive_mappings (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_drive_mappings");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_filesystems : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_filesystems (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_filesystems (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_filesystems");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_filesystems (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_filesystems");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_format : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_format (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_format (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_format");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_format (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_format");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_hostname : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_hostname (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_hostname (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_hostname");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_hostname (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_hostname");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_icon : t -> ?favicon:bool -> ?highquality:bool -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_icon (value gv, value faviconv, value highqualityv, value rootv);

value
guestfs_int_ocaml_inspect_get_icon (value gv, value faviconv, value highqualityv, value rootv)
{
  CAMLparam4 (gv, faviconv, highqualityv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_icon");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  if (faviconv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
    optargs_s.favicon = Bool_val (Field (faviconv, 0));
  }
  if (highqualityv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
    optargs_s.highquality = Bool_val (Field (highqualityv, 0));
  }
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_icon");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_major_version : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_major_version (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_major_version (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_major_version");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_major_version (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inspect_get_major_version");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_minor_version : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_minor_version (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_minor_version (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_minor_version");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_minor_version (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inspect_get_minor_version");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_mountpoints : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_mountpoints (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_mountpoints (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_mountpoints");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_mountpoints (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_mountpoints");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_package_format : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_package_format (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_package_format (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_package_format");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_package_format (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_package_format");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_package_management : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_package_management (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_package_management (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_package_management");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_package_management (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_package_management");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_product_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_product_name (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_product_name (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_product_name");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_product_name (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_product_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_product_variant : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_product_variant (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_product_variant (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_product_variant");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_product_variant (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_product_variant");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_roots : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_roots (value gv);

value
guestfs_int_ocaml_inspect_get_roots (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_roots");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_roots (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_roots");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_type : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_type (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_type (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_type");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_type (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_current_control_set : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_windows_current_control_set (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_windows_current_control_set (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_windows_current_control_set");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_current_control_set (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_windows_current_control_set");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_software_hive : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_windows_software_hive (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_windows_software_hive (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_windows_software_hive");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_software_hive (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_windows_software_hive");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_system_hive : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_windows_system_hive (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_windows_system_hive (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_windows_system_hive");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_system_hive (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_windows_system_hive");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_systemroot : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_get_windows_systemroot (value gv, value rootv);

value
guestfs_int_ocaml_inspect_get_windows_systemroot (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_get_windows_systemroot");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_systemroot (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_get_windows_systemroot");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_live : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_is_live (value gv, value rootv);

value
guestfs_int_ocaml_inspect_is_live (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_is_live");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_live (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inspect_is_live");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_multipart : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_is_multipart (value gv, value rootv);

value
guestfs_int_ocaml_inspect_is_multipart (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_is_multipart");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_multipart (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inspect_is_multipart");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_netinst : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_is_netinst (value gv, value rootv);

value
guestfs_int_ocaml_inspect_is_netinst (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_is_netinst");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_netinst (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "inspect_is_netinst");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_list_applications : t -> string -> application array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_list_applications (value gv, value rootv);

value
guestfs_int_ocaml_inspect_list_applications (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_list_applications");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  struct guestfs_application_list *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_list_applications (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_list_applications");

  rv = copy_application_list (r);
  guestfs_free_application_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_list_applications2 : t -> string -> application2 array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_list_applications2 (value gv, value rootv);

value
guestfs_int_ocaml_inspect_list_applications2 (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_list_applications2");

  char *root;
  root = strdup (String_val (rootv));
  if (root == NULL) caml_raise_out_of_memory ();
  struct guestfs_application2_list *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_list_applications2 (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_list_applications2");

  rv = copy_application2_list (r);
  guestfs_free_application2_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_os : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_inspect_os (value gv);

value
guestfs_int_ocaml_inspect_os (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("inspect_os");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_os (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "inspect_os");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_exit : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_exit (value gv);

value
guestfs_int_ocaml_internal_exit (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_exit");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_internal_exit (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_exit");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test : t -> ?obool:bool -> ?oint:int -> ?oint64:int64 -> ?ostring:string -> ?ostringlist:string array -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test (value gv, value oboolv, value ointv, value oint64v, value ostringv, value ostringlistv, value strv, value optstrv, value strlistv, value bv, value integerv, value integer64v, value fileinv, value fileoutv, value bufferinv);

value
guestfs_int_ocaml_internal_test (value gv, value oboolv, value ointv, value oint64v, value ostringv, value ostringlistv, value strv, value optstrv, value strlistv, value bv, value integerv, value integer64v, value fileinv, value fileoutv, value bufferinv)
{
  CAMLparam5 (gv, oboolv, ointv, oint64v, ostringv);
  CAMLxparam5 (ostringlistv, strv, optstrv, strlistv, bv);
  CAMLxparam5 (integerv, integer64v, fileinv, fileoutv, bufferinv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test");

  char *str;
  str = strdup (String_val (strv));
  if (str == NULL) caml_raise_out_of_memory ();
  char *optstr;
  if (optstrv == Val_int (0))
    optstr = NULL;
  else {
    optstr = strdup (String_val (Field (optstrv, 0)));
    if (optstr == NULL) caml_raise_out_of_memory ();
  }
  char **strlist = guestfs_int_ocaml_strings_val (g, strlistv);
  int b = Bool_val (bv);
  int integer = Int_val (integerv);
  int64_t integer64 = Int64_val (integer64v);
  char *filein;
  filein = strdup (String_val (fileinv));
  if (filein == NULL) caml_raise_out_of_memory ();
  char *fileout;
  fileout = strdup (String_val (fileoutv));
  if (fileout == NULL) caml_raise_out_of_memory ();
  size_t bufferin_size = caml_string_length (bufferinv);
  char *bufferin;
  bufferin = malloc (bufferin_size);
  if (bufferin == NULL) caml_raise_out_of_memory ();
  memcpy (bufferin, String_val (bufferinv), bufferin_size);
  struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  if (oboolv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
    optargs_s.obool = Bool_val (Field (oboolv, 0));
  }
  if (ointv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
    optargs_s.oint = Int_val (Field (ointv, 0));
  }
  if (oint64v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
    optargs_s.oint64 = Int64_val (Field (oint64v, 0));
  }
  if (ostringv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
    optargs_s.ostring = strdup (String_val (Field (ostringv, 0)));
    if (optargs_s.ostring == NULL) caml_raise_out_of_memory ();
  }
  if (ostringlistv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
    optargs_s.ostringlist = guestfs_int_ocaml_strings_val (g, Field (ostringlistv, 0));
  }
  int r;

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  free (str);
  free (optstr);
  guestfs_int_free_string_list (strlist);
  free (filein);
  free (fileout);
  free (bufferin);
  if (ostringv != Val_int (0))
    free ((char *) optargs_s.ostring);
  if (ostringlistv != Val_int (0))
    guestfs_int_free_string_list ((char **) optargs_s.ostringlist);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_byte (value *argv, int argn);

value
guestfs_int_ocaml_internal_test_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_internal_test (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14]);
}

/* Automatically generated wrapper for function
 * val internal_test_63_optargs : t -> ?opt1:int -> ?opt2:int -> ?opt3:int -> ?opt4:int -> ?opt5:int -> ?opt6:int -> ?opt7:int -> ?opt8:int -> ?opt9:int -> ?opt10:int -> ?opt11:int -> ?opt12:int -> ?opt13:int -> ?opt14:int -> ?opt15:int -> ?opt16:int -> ?opt17:int -> ?opt18:int -> ?opt19:int -> ?opt20:int -> ?opt21:int -> ?opt22:int -> ?opt23:int -> ?opt24:int -> ?opt25:int -> ?opt26:int -> ?opt27:int -> ?opt28:int -> ?opt29:int -> ?opt30:int -> ?opt31:int -> ?opt32:int -> ?opt33:int -> ?opt34:int -> ?opt35:int -> ?opt36:int -> ?opt37:int -> ?opt38:int -> ?opt39:int -> ?opt40:int -> ?opt41:int -> ?opt42:int -> ?opt43:int -> ?opt44:int -> ?opt45:int -> ?opt46:int -> ?opt47:int -> ?opt48:int -> ?opt49:int -> ?opt50:int -> ?opt51:int -> ?opt52:int -> ?opt53:int -> ?opt54:int -> ?opt55:int -> ?opt56:int -> ?opt57:int -> ?opt58:int -> ?opt59:int -> ?opt60:int -> ?opt61:int -> ?opt62:int -> ?opt63:int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_63_optargs (value gv, value opt1v, value opt2v, value opt3v, value opt4v, value opt5v, value opt6v, value opt7v, value opt8v, value opt9v, value opt10v, value opt11v, value opt12v, value opt13v, value opt14v, value opt15v, value opt16v, value opt17v, value opt18v, value opt19v, value opt20v, value opt21v, value opt22v, value opt23v, value opt24v, value opt25v, value opt26v, value opt27v, value opt28v, value opt29v, value opt30v, value opt31v, value opt32v, value opt33v, value opt34v, value opt35v, value opt36v, value opt37v, value opt38v, value opt39v, value opt40v, value opt41v, value opt42v, value opt43v, value opt44v, value opt45v, value opt46v, value opt47v, value opt48v, value opt49v, value opt50v, value opt51v, value opt52v, value opt53v, value opt54v, value opt55v, value opt56v, value opt57v, value opt58v, value opt59v, value opt60v, value opt61v, value opt62v, value opt63v);

value
guestfs_int_ocaml_internal_test_63_optargs (value gv, value opt1v, value opt2v, value opt3v, value opt4v, value opt5v, value opt6v, value opt7v, value opt8v, value opt9v, value opt10v, value opt11v, value opt12v, value opt13v, value opt14v, value opt15v, value opt16v, value opt17v, value opt18v, value opt19v, value opt20v, value opt21v, value opt22v, value opt23v, value opt24v, value opt25v, value opt26v, value opt27v, value opt28v, value opt29v, value opt30v, value opt31v, value opt32v, value opt33v, value opt34v, value opt35v, value opt36v, value opt37v, value opt38v, value opt39v, value opt40v, value opt41v, value opt42v, value opt43v, value opt44v, value opt45v, value opt46v, value opt47v, value opt48v, value opt49v, value opt50v, value opt51v, value opt52v, value opt53v, value opt54v, value opt55v, value opt56v, value opt57v, value opt58v, value opt59v, value opt60v, value opt61v, value opt62v, value opt63v)
{
  CAMLparam5 (gv, opt1v, opt2v, opt3v, opt4v);
  CAMLxparam5 (opt5v, opt6v, opt7v, opt8v, opt9v);
  CAMLxparam5 (opt10v, opt11v, opt12v, opt13v, opt14v);
  CAMLxparam5 (opt15v, opt16v, opt17v, opt18v, opt19v);
  CAMLxparam5 (opt20v, opt21v, opt22v, opt23v, opt24v);
  CAMLxparam5 (opt25v, opt26v, opt27v, opt28v, opt29v);
  CAMLxparam5 (opt30v, opt31v, opt32v, opt33v, opt34v);
  CAMLxparam5 (opt35v, opt36v, opt37v, opt38v, opt39v);
  CAMLxparam5 (opt40v, opt41v, opt42v, opt43v, opt44v);
  CAMLxparam5 (opt45v, opt46v, opt47v, opt48v, opt49v);
  CAMLxparam5 (opt50v, opt51v, opt52v, opt53v, opt54v);
  CAMLxparam5 (opt55v, opt56v, opt57v, opt58v, opt59v);
  CAMLxparam4 (opt60v, opt61v, opt62v, opt63v);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_63_optargs");

  struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  if (opt1v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
    optargs_s.opt1 = Int_val (Field (opt1v, 0));
  }
  if (opt2v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
    optargs_s.opt2 = Int_val (Field (opt2v, 0));
  }
  if (opt3v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
    optargs_s.opt3 = Int_val (Field (opt3v, 0));
  }
  if (opt4v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
    optargs_s.opt4 = Int_val (Field (opt4v, 0));
  }
  if (opt5v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
    optargs_s.opt5 = Int_val (Field (opt5v, 0));
  }
  if (opt6v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
    optargs_s.opt6 = Int_val (Field (opt6v, 0));
  }
  if (opt7v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
    optargs_s.opt7 = Int_val (Field (opt7v, 0));
  }
  if (opt8v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
    optargs_s.opt8 = Int_val (Field (opt8v, 0));
  }
  if (opt9v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
    optargs_s.opt9 = Int_val (Field (opt9v, 0));
  }
  if (opt10v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
    optargs_s.opt10 = Int_val (Field (opt10v, 0));
  }
  if (opt11v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
    optargs_s.opt11 = Int_val (Field (opt11v, 0));
  }
  if (opt12v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
    optargs_s.opt12 = Int_val (Field (opt12v, 0));
  }
  if (opt13v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
    optargs_s.opt13 = Int_val (Field (opt13v, 0));
  }
  if (opt14v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
    optargs_s.opt14 = Int_val (Field (opt14v, 0));
  }
  if (opt15v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
    optargs_s.opt15 = Int_val (Field (opt15v, 0));
  }
  if (opt16v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
    optargs_s.opt16 = Int_val (Field (opt16v, 0));
  }
  if (opt17v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
    optargs_s.opt17 = Int_val (Field (opt17v, 0));
  }
  if (opt18v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
    optargs_s.opt18 = Int_val (Field (opt18v, 0));
  }
  if (opt19v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
    optargs_s.opt19 = Int_val (Field (opt19v, 0));
  }
  if (opt20v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
    optargs_s.opt20 = Int_val (Field (opt20v, 0));
  }
  if (opt21v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
    optargs_s.opt21 = Int_val (Field (opt21v, 0));
  }
  if (opt22v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
    optargs_s.opt22 = Int_val (Field (opt22v, 0));
  }
  if (opt23v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
    optargs_s.opt23 = Int_val (Field (opt23v, 0));
  }
  if (opt24v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
    optargs_s.opt24 = Int_val (Field (opt24v, 0));
  }
  if (opt25v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
    optargs_s.opt25 = Int_val (Field (opt25v, 0));
  }
  if (opt26v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
    optargs_s.opt26 = Int_val (Field (opt26v, 0));
  }
  if (opt27v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
    optargs_s.opt27 = Int_val (Field (opt27v, 0));
  }
  if (opt28v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
    optargs_s.opt28 = Int_val (Field (opt28v, 0));
  }
  if (opt29v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
    optargs_s.opt29 = Int_val (Field (opt29v, 0));
  }
  if (opt30v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
    optargs_s.opt30 = Int_val (Field (opt30v, 0));
  }
  if (opt31v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
    optargs_s.opt31 = Int_val (Field (opt31v, 0));
  }
  if (opt32v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
    optargs_s.opt32 = Int_val (Field (opt32v, 0));
  }
  if (opt33v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
    optargs_s.opt33 = Int_val (Field (opt33v, 0));
  }
  if (opt34v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
    optargs_s.opt34 = Int_val (Field (opt34v, 0));
  }
  if (opt35v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
    optargs_s.opt35 = Int_val (Field (opt35v, 0));
  }
  if (opt36v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
    optargs_s.opt36 = Int_val (Field (opt36v, 0));
  }
  if (opt37v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
    optargs_s.opt37 = Int_val (Field (opt37v, 0));
  }
  if (opt38v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
    optargs_s.opt38 = Int_val (Field (opt38v, 0));
  }
  if (opt39v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
    optargs_s.opt39 = Int_val (Field (opt39v, 0));
  }
  if (opt40v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
    optargs_s.opt40 = Int_val (Field (opt40v, 0));
  }
  if (opt41v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
    optargs_s.opt41 = Int_val (Field (opt41v, 0));
  }
  if (opt42v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
    optargs_s.opt42 = Int_val (Field (opt42v, 0));
  }
  if (opt43v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
    optargs_s.opt43 = Int_val (Field (opt43v, 0));
  }
  if (opt44v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
    optargs_s.opt44 = Int_val (Field (opt44v, 0));
  }
  if (opt45v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
    optargs_s.opt45 = Int_val (Field (opt45v, 0));
  }
  if (opt46v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
    optargs_s.opt46 = Int_val (Field (opt46v, 0));
  }
  if (opt47v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
    optargs_s.opt47 = Int_val (Field (opt47v, 0));
  }
  if (opt48v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
    optargs_s.opt48 = Int_val (Field (opt48v, 0));
  }
  if (opt49v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
    optargs_s.opt49 = Int_val (Field (opt49v, 0));
  }
  if (opt50v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
    optargs_s.opt50 = Int_val (Field (opt50v, 0));
  }
  if (opt51v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
    optargs_s.opt51 = Int_val (Field (opt51v, 0));
  }
  if (opt52v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
    optargs_s.opt52 = Int_val (Field (opt52v, 0));
  }
  if (opt53v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
    optargs_s.opt53 = Int_val (Field (opt53v, 0));
  }
  if (opt54v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
    optargs_s.opt54 = Int_val (Field (opt54v, 0));
  }
  if (opt55v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
    optargs_s.opt55 = Int_val (Field (opt55v, 0));
  }
  if (opt56v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
    optargs_s.opt56 = Int_val (Field (opt56v, 0));
  }
  if (opt57v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
    optargs_s.opt57 = Int_val (Field (opt57v, 0));
  }
  if (opt58v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
    optargs_s.opt58 = Int_val (Field (opt58v, 0));
  }
  if (opt59v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
    optargs_s.opt59 = Int_val (Field (opt59v, 0));
  }
  if (opt60v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
    optargs_s.opt60 = Int_val (Field (opt60v, 0));
  }
  if (opt61v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
    optargs_s.opt61 = Int_val (Field (opt61v, 0));
  }
  if (opt62v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
    optargs_s.opt62 = Int_val (Field (opt62v, 0));
  }
  if (opt63v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
    optargs_s.opt63 = Int_val (Field (opt63v, 0));
  }
  int r;

  r = guestfs_internal_test_63_optargs_argv (g, optargs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_63_optargs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_63_optargs_byte (value *argv, int argn);

value
guestfs_int_ocaml_internal_test_63_optargs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_internal_test_63_optargs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14], argv[15], argv[16], argv[17], argv[18], argv[19], argv[20], argv[21], argv[22], argv[23], argv[24], argv[25], argv[26], argv[27], argv[28], argv[29], argv[30], argv[31], argv[32], argv[33], argv[34], argv[35], argv[36], argv[37], argv[38], argv[39], argv[40], argv[41], argv[42], argv[43], argv[44], argv[45], argv[46], argv[47], argv[48], argv[49], argv[50], argv[51], argv[52], argv[53], argv[54], argv[55], argv[56], argv[57], argv[58], argv[59], argv[60], argv[61], argv[62], argv[63]);
}

/* Automatically generated wrapper for function
 * val internal_test_close_output : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_close_output (value gv);

value
guestfs_int_ocaml_internal_test_close_output (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_close_output");

  int r;

  r = guestfs_internal_test_close_output (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_close_output");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_only_optargs : t -> ?test:int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_only_optargs (value gv, value testv);

value
guestfs_int_ocaml_internal_test_only_optargs (value gv, value testv)
{
  CAMLparam2 (gv, testv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_only_optargs");

  struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  if (testv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
    optargs_s.test = Int_val (Field (testv, 0));
  }
  int r;

  r = guestfs_internal_test_only_optargs_argv (g, optargs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_only_optargs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rbool : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rbool (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rbool (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rbool");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_internal_test_rbool (g, val);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rbool");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rboolerr : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rboolerr (value gv);

value
guestfs_int_ocaml_internal_test_rboolerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rboolerr");

  int r;

  r = guestfs_internal_test_rboolerr (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rboolerr");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rbufferout : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rbufferout (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rbufferout (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rbufferout");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferout (g, val, &size);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rbufferout");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rbufferouterr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rbufferouterr (value gv);

value
guestfs_int_ocaml_internal_test_rbufferouterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rbufferouterr");

  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferouterr (g, &size);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rbufferouterr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rconstoptstring : t -> string -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rconstoptstring (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rconstoptstring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rconstoptstring");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  const char *r;

  r = guestfs_internal_test_rconstoptstring (g, val);
  free (val);

  if (r) { /* Some string */
    v = caml_alloc (1, 0);
    v2 = caml_copy_string (r);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rconstoptstringerr : t -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rconstoptstringerr (value gv);

value
guestfs_int_ocaml_internal_test_rconstoptstringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rconstoptstringerr");

  const char *r;

  r = guestfs_internal_test_rconstoptstringerr (g);

  if (r) { /* Some string */
    v = caml_alloc (1, 0);
    v2 = caml_copy_string (r);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rconststring : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rconststring (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rconststring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rconststring");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  const char *r;

  r = guestfs_internal_test_rconststring (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rconststring");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rconststringerr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rconststringerr (value gv);

value
guestfs_int_ocaml_internal_test_rconststringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rconststringerr");

  const char *r;

  r = guestfs_internal_test_rconststringerr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rconststringerr");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rhashtable : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rhashtable (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rhashtable (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rhashtable");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  r = guestfs_internal_test_rhashtable (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rhashtable");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rhashtableerr : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rhashtableerr (value gv);

value
guestfs_int_ocaml_internal_test_rhashtableerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rhashtableerr");

  size_t i;
  char **r;

  r = guestfs_internal_test_rhashtableerr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rhashtableerr");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rint : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rint (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rint (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rint");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_internal_test_rint (g, val);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rint");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rint64 : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rint64 (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rint64 (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rint64");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int64_t r;

  r = guestfs_internal_test_rint64 (g, val);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rint64");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rint64err : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rint64err (value gv);

value
guestfs_int_ocaml_internal_test_rint64err (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rint64err");

  int64_t r;

  r = guestfs_internal_test_rint64err (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rint64err");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rinterr : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rinterr (value gv);

value
guestfs_int_ocaml_internal_test_rinterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rinterr");

  int r;

  r = guestfs_internal_test_rinterr (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_rinterr");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstring : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstring (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rstring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstring");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  char *r;

  r = guestfs_internal_test_rstring (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstring");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstringerr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstringerr (value gv);

value
guestfs_int_ocaml_internal_test_rstringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstringerr");

  char *r;

  r = guestfs_internal_test_rstringerr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstringerr");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstringlist : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstringlist (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rstringlist (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstringlist");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  r = guestfs_internal_test_rstringlist (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstringlist");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstringlisterr : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstringlisterr (value gv);

value
guestfs_int_ocaml_internal_test_rstringlisterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstringlisterr");

  size_t i;
  char **r;

  r = guestfs_internal_test_rstringlisterr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstringlisterr");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstruct : t -> string -> lvm_pv
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstruct (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rstruct (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstruct");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstruct (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstruct");

  rv = copy_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstructerr : t -> lvm_pv
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstructerr (value gv);

value
guestfs_int_ocaml_internal_test_rstructerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstructerr");

  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstructerr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstructerr");

  rv = copy_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstructlist : t -> string -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstructlist (value gv, value valv);

value
guestfs_int_ocaml_internal_test_rstructlist (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstructlist");

  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlist (g, val);
  free (val);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstructlist");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_rstructlisterr : t -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_rstructlisterr (value gv);

value
guestfs_int_ocaml_internal_test_rstructlisterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_rstructlisterr");

  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlisterr (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "internal_test_rstructlisterr");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_test_set_output : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_internal_test_set_output (value gv, value filenamev);

value
guestfs_int_ocaml_internal_test_set_output (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("internal_test_set_output");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_internal_test_set_output (g, filename);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "internal_test_set_output");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_blockdev : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_blockdev (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_blockdev (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_blockdev");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_blockdev_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_blockdev");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_busy : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_busy (value gv);

value
guestfs_int_ocaml_is_busy (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_busy");

  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_busy");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_chardev : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_chardev (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_chardev (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_chardev");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_chardev_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_chardev");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_config : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_config (value gv);

value
guestfs_int_ocaml_is_config (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_config");

  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_config");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_dir : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_dir (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_dir (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_dir");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_dir_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_dir");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_fifo : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_fifo (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_fifo (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_fifo");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_fifo_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_fifo");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_file : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_file (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_file (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_file_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_file");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_launching : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_launching (value gv);

value
guestfs_int_ocaml_is_launching (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_launching");

  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_launching");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_lv : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_lv (value gv, value mountablev);

value
guestfs_int_ocaml_is_lv (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_lv");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_lv (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_lv");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_ready : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_ready (value gv);

value
guestfs_int_ocaml_is_ready (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_ready");

  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_ready");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_socket : t -> ?followsymlinks:bool -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_socket (value gv, value followsymlinksv, value pathv);

value
guestfs_int_ocaml_is_socket (value gv, value followsymlinksv, value pathv)
{
  CAMLparam3 (gv, followsymlinksv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_socket");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  if (followsymlinksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = Bool_val (Field (followsymlinksv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_socket_opts_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_socket");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_symlink : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_symlink (value gv, value pathv);

value
guestfs_int_ocaml_is_symlink (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_symlink");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_symlink (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_symlink");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_whole_device : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_whole_device (value gv, value devicev);

value
guestfs_int_ocaml_is_whole_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_whole_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_whole_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_whole_device");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_zero : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_zero (value gv, value pathv);

value
guestfs_int_ocaml_is_zero (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_zero");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_zero (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_zero");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_zero_device : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_is_zero_device (value gv, value devicev);

value
guestfs_int_ocaml_is_zero_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("is_zero_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_zero_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "is_zero_device");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val isoinfo : t -> string -> isoinfo
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_isoinfo (value gv, value isofilev);

value
guestfs_int_ocaml_isoinfo (value gv, value isofilev)
{
  CAMLparam2 (gv, isofilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("isoinfo");

  char *isofile;
  isofile = strdup (String_val (isofilev));
  if (isofile == NULL) caml_raise_out_of_memory ();
  struct guestfs_isoinfo *r;

  caml_enter_blocking_section ();
  r = guestfs_isoinfo (g, isofile);
  caml_leave_blocking_section ();
  free (isofile);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "isoinfo");

  rv = copy_isoinfo (r);
  guestfs_free_isoinfo (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val isoinfo_device : t -> string -> isoinfo
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_isoinfo_device (value gv, value devicev);

value
guestfs_int_ocaml_isoinfo_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("isoinfo_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_isoinfo *r;

  caml_enter_blocking_section ();
  r = guestfs_isoinfo_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "isoinfo_device");

  rv = copy_isoinfo (r);
  guestfs_free_isoinfo (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_close (value gv);

value
guestfs_int_ocaml_journal_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_journal_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_get : t -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_get (value gv);

value
guestfs_int_ocaml_journal_get (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_get");

  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_journal_get (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "journal_get");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_get_data_threshold : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_get_data_threshold (value gv);

value
guestfs_int_ocaml_journal_get_data_threshold (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_get_data_threshold");

  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_journal_get_data_threshold (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_get_data_threshold");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_get_realtime_usec : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_get_realtime_usec (value gv);

value
guestfs_int_ocaml_journal_get_realtime_usec (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_get_realtime_usec");

  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_journal_get_realtime_usec (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_get_realtime_usec");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_next : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_next (value gv);

value
guestfs_int_ocaml_journal_next (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_next");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_journal_next (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_next");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_open : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_open (value gv, value directoryv);

value
guestfs_int_ocaml_journal_open (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_open");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_journal_open (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_open");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_set_data_threshold : t -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_set_data_threshold (value gv, value thresholdv);

value
guestfs_int_ocaml_journal_set_data_threshold (value gv, value thresholdv)
{
  CAMLparam2 (gv, thresholdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_set_data_threshold");

  int64_t threshold = Int64_val (thresholdv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_journal_set_data_threshold (g, threshold);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_set_data_threshold");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val journal_skip : t -> int64 -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_journal_skip (value gv, value skipv);

value
guestfs_int_ocaml_journal_skip (value gv, value skipv)
{
  CAMLparam2 (gv, skipv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("journal_skip");

  int64_t skip = Int64_val (skipv);
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_journal_skip (g, skip);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "journal_skip");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val kill_subprocess : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_kill_subprocess (value gv);

value
guestfs_int_ocaml_kill_subprocess (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("kill_subprocess");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_kill_subprocess (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "kill_subprocess");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val launch : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_launch (value gv);

value
guestfs_int_ocaml_launch (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("launch");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_launch (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "launch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lchown : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lchown (value gv, value ownerv, value groupv, value pathv);

value
guestfs_int_ocaml_lchown (value gv, value ownerv, value groupv, value pathv)
{
  CAMLparam4 (gv, ownerv, groupv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lchown");

  int owner = Int_val (ownerv);
  int group = Int_val (groupv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lchown (g, owner, group, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lchown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_create_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_create_all (value gv);

value
guestfs_int_ocaml_ldmtool_create_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_create_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_create_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ldmtool_create_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_diskgroup_disks : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_diskgroup_disks (value gv, value diskgroupv);

value
guestfs_int_ocaml_ldmtool_diskgroup_disks (value gv, value diskgroupv)
{
  CAMLparam2 (gv, diskgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_diskgroup_disks");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  caml_leave_blocking_section ();
  free (diskgroup);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_diskgroup_disks");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_diskgroup_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_diskgroup_name (value gv, value diskgroupv);

value
guestfs_int_ocaml_ldmtool_diskgroup_name (value gv, value diskgroupv)
{
  CAMLparam2 (gv, diskgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_diskgroup_name");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  caml_leave_blocking_section ();
  free (diskgroup);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_diskgroup_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_diskgroup_volumes : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_diskgroup_volumes (value gv, value diskgroupv);

value
guestfs_int_ocaml_ldmtool_diskgroup_volumes (value gv, value diskgroupv)
{
  CAMLparam2 (gv, diskgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_diskgroup_volumes");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
  caml_leave_blocking_section ();
  free (diskgroup);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_diskgroup_volumes");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_remove_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_remove_all (value gv);

value
guestfs_int_ocaml_ldmtool_remove_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_remove_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_remove_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ldmtool_remove_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_scan : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_scan (value gv);

value
guestfs_int_ocaml_ldmtool_scan (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_scan");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_scan (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_scan");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_scan_devices : t -> string array -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_scan_devices (value gv, value devicesv);

value
guestfs_int_ocaml_ldmtool_scan_devices (value gv, value devicesv)
{
  CAMLparam2 (gv, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_scan_devices");

  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_scan_devices (g, devices);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (devices);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_scan_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_volume_hint : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_volume_hint (value gv, value diskgroupv, value volumev);

value
guestfs_int_ocaml_ldmtool_volume_hint (value gv, value diskgroupv, value volumev)
{
  CAMLparam3 (gv, diskgroupv, volumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_volume_hint");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  char *volume;
  volume = strdup (String_val (volumev));
  if (volume == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  caml_leave_blocking_section ();
  free (diskgroup);
  free (volume);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_volume_hint");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_volume_partitions : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_volume_partitions (value gv, value diskgroupv, value volumev);

value
guestfs_int_ocaml_ldmtool_volume_partitions (value gv, value diskgroupv, value volumev)
{
  CAMLparam3 (gv, diskgroupv, volumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_volume_partitions");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  char *volume;
  volume = strdup (String_val (volumev));
  if (volume == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  caml_leave_blocking_section ();
  free (diskgroup);
  free (volume);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_volume_partitions");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ldmtool_volume_type : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ldmtool_volume_type (value gv, value diskgroupv, value volumev);

value
guestfs_int_ocaml_ldmtool_volume_type (value gv, value diskgroupv, value volumev)
{
  CAMLparam3 (gv, diskgroupv, volumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ldmtool_volume_type");

  char *diskgroup;
  diskgroup = strdup (String_val (diskgroupv));
  if (diskgroup == NULL) caml_raise_out_of_memory ();
  char *volume;
  volume = strdup (String_val (volumev));
  if (volume == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  caml_leave_blocking_section ();
  free (diskgroup);
  free (volume);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ldmtool_volume_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lgetxattr : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lgetxattr (value gv, value pathv, value namev);

value
guestfs_int_ocaml_lgetxattr (value gv, value pathv, value namev)
{
  CAMLparam3 (gv, pathv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lgetxattr");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_lgetxattr (g, path, name, &size);
  caml_leave_blocking_section ();
  free (path);
  free (name);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lgetxattr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lgetxattrs : t -> string -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lgetxattrs (value gv, value pathv);

value
guestfs_int_ocaml_lgetxattrs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lgetxattrs");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lgetxattrs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lgetxattrs");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_9p : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_9p (value gv);

value
guestfs_int_ocaml_list_9p (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_9p");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_9p (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_9p");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_devices (value gv);

value
guestfs_int_ocaml_list_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_disk_labels : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_disk_labels (value gv);

value
guestfs_int_ocaml_list_disk_labels (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_disk_labels");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_disk_labels (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_disk_labels");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_dm_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_dm_devices (value gv);

value
guestfs_int_ocaml_list_dm_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_dm_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_dm_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_dm_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_filesystems : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_filesystems (value gv);

value
guestfs_int_ocaml_list_filesystems (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_filesystems");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_filesystems (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_filesystems");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_ldm_partitions : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_ldm_partitions (value gv);

value
guestfs_int_ocaml_list_ldm_partitions (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_ldm_partitions");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_ldm_partitions (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_ldm_partitions");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_ldm_volumes : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_ldm_volumes (value gv);

value
guestfs_int_ocaml_list_ldm_volumes (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_ldm_volumes");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_ldm_volumes (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_ldm_volumes");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_md_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_md_devices (value gv);

value
guestfs_int_ocaml_list_md_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_md_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_md_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_md_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_partitions : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_list_partitions (value gv);

value
guestfs_int_ocaml_list_partitions (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("list_partitions");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_partitions (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "list_partitions");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ll : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ll (value gv, value directoryv);

value
guestfs_int_ocaml_ll (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ll");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_ll (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ll");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val llz : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_llz (value gv, value directoryv);

value
guestfs_int_ocaml_llz (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("llz");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_llz (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "llz");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ln (value gv, value targetv, value linknamev);

value
guestfs_int_ocaml_ln (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ln");

  char *target;
  target = strdup (String_val (targetv));
  if (target == NULL) caml_raise_out_of_memory ();
  char *linkname;
  linkname = strdup (String_val (linknamev));
  if (linkname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ln");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_f : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ln_f (value gv, value targetv, value linknamev);

value
guestfs_int_ocaml_ln_f (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ln_f");

  char *target;
  target = strdup (String_val (targetv));
  if (target == NULL) caml_raise_out_of_memory ();
  char *linkname;
  linkname = strdup (String_val (linknamev));
  if (linkname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_f (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ln_f");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_s : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ln_s (value gv, value targetv, value linknamev);

value
guestfs_int_ocaml_ln_s (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ln_s");

  char *target;
  target = strdup (String_val (targetv));
  if (target == NULL) caml_raise_out_of_memory ();
  char *linkname;
  linkname = strdup (String_val (linknamev));
  if (linkname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_s (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ln_s");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_sf : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ln_sf (value gv, value targetv, value linknamev);

value
guestfs_int_ocaml_ln_sf (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ln_sf");

  char *target;
  target = strdup (String_val (targetv));
  if (target == NULL) caml_raise_out_of_memory ();
  char *linkname;
  linkname = strdup (String_val (linknamev));
  if (linkname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_sf (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ln_sf");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lremovexattr : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lremovexattr (value gv, value xattrv, value pathv);

value
guestfs_int_ocaml_lremovexattr (value gv, value xattrv, value pathv)
{
  CAMLparam3 (gv, xattrv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lremovexattr");

  char *xattr;
  xattr = strdup (String_val (xattrv));
  if (xattr == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lremovexattr (g, xattr, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lremovexattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ls : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ls (value gv, value directoryv);

value
guestfs_int_ocaml_ls (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ls");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ls (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "ls");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ls0 : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ls0 (value gv, value dirv, value filenamesv);

value
guestfs_int_ocaml_ls0 (value gv, value dirv, value filenamesv)
{
  CAMLparam3 (gv, dirv, filenamesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ls0");

  char *dir;
  dir = strdup (String_val (dirv));
  if (dir == NULL) caml_raise_out_of_memory ();
  char *filenames;
  filenames = strdup (String_val (filenamesv));
  if (filenames == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ls0 (g, dir, filenames);
  caml_leave_blocking_section ();
  free (dir);
  free (filenames);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ls0");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lsetxattr : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lsetxattr (value gv, value xattrv, value valv, value vallenv, value pathv);

value
guestfs_int_ocaml_lsetxattr (value gv, value xattrv, value valv, value vallenv, value pathv)
{
  CAMLparam5 (gv, xattrv, valv, vallenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lsetxattr");

  char *xattr;
  xattr = strdup (String_val (xattrv));
  if (xattr == NULL) caml_raise_out_of_memory ();
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int vallen = Int_val (vallenv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lsetxattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstat : t -> string -> stat
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lstat (value gv, value pathv);

value
guestfs_int_ocaml_lstat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lstat");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_stat *r;

  caml_enter_blocking_section ();
  r = guestfs_lstat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lstat");

  rv = copy_stat (r);
  guestfs_free_stat (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstatlist : t -> string -> string array -> stat array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lstatlist (value gv, value pathv, value namesv);

value
guestfs_int_ocaml_lstatlist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lstatlist");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char **names = guestfs_int_ocaml_strings_val (g, namesv);
  struct guestfs_stat_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lstatlist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  guestfs_int_free_string_list (names);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lstatlist");

  rv = copy_stat_list (r);
  guestfs_free_stat_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstatns : t -> string -> statns
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lstatns (value gv, value pathv);

value
guestfs_int_ocaml_lstatns (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lstatns");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_statns *r;

  caml_enter_blocking_section ();
  r = guestfs_lstatns (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lstatns");

  rv = copy_statns (r);
  guestfs_free_statns (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstatnslist : t -> string -> string array -> statns array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lstatnslist (value gv, value pathv, value namesv);

value
guestfs_int_ocaml_lstatnslist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lstatnslist");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char **names = guestfs_int_ocaml_strings_val (g, namesv);
  struct guestfs_statns_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lstatnslist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  guestfs_int_free_string_list (names);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lstatnslist");

  rv = copy_statns_list (r);
  guestfs_free_statns_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_add_key : t -> string -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_add_key (value gv, value devicev, value keyv, value newkeyv, value keyslotv);

value
guestfs_int_ocaml_luks_add_key (value gv, value devicev, value keyv, value newkeyv, value keyslotv)
{
  CAMLparam5 (gv, devicev, keyv, newkeyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_add_key");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  char *newkey;
  newkey = strdup (String_val (newkeyv));
  if (newkey == NULL) caml_raise_out_of_memory ();
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (newkey);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_add_key");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_close : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_close (value gv, value devicev);

value
guestfs_int_ocaml_luks_close (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_close");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_close (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_format : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_format (value gv, value devicev, value keyv, value keyslotv);

value
guestfs_int_ocaml_luks_format (value gv, value devicev, value keyv, value keyslotv)
{
  CAMLparam4 (gv, devicev, keyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_format");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_format (g, device, key, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_format");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_format_cipher : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_format_cipher (value gv, value devicev, value keyv, value keyslotv, value cipherv);

value
guestfs_int_ocaml_luks_format_cipher (value gv, value devicev, value keyv, value keyslotv, value cipherv)
{
  CAMLparam5 (gv, devicev, keyv, keyslotv, cipherv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_format_cipher");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  int keyslot = Int_val (keyslotv);
  char *cipher;
  cipher = strdup (String_val (cipherv));
  if (cipher == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (cipher);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_format_cipher");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_kill_slot : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_kill_slot (value gv, value devicev, value keyv, value keyslotv);

value
guestfs_int_ocaml_luks_kill_slot (value gv, value devicev, value keyv, value keyslotv)
{
  CAMLparam4 (gv, devicev, keyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_kill_slot");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_kill_slot");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_open : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_open (value gv, value devicev, value keyv, value mapnamev);

value
guestfs_int_ocaml_luks_open (value gv, value devicev, value keyv, value mapnamev)
{
  CAMLparam4 (gv, devicev, keyv, mapnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_open");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  char *mapname;
  mapname = strdup (String_val (mapnamev));
  if (mapname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_open (g, device, key, mapname);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_open");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_open_ro : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_luks_open_ro (value gv, value devicev, value keyv, value mapnamev);

value
guestfs_int_ocaml_luks_open_ro (value gv, value devicev, value keyv, value mapnamev)
{
  CAMLparam4 (gv, devicev, keyv, mapnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("luks_open_ro");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *key;
  key = strdup (String_val (keyv));
  if (key == NULL) caml_raise_out_of_memory ();
  char *mapname;
  mapname = strdup (String_val (mapnamev));
  if (mapname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_open_ro (g, device, key, mapname);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "luks_open_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvcreate : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvcreate (value gv, value logvolv, value volgroupv, value mbytesv);

value
guestfs_int_ocaml_lvcreate (value gv, value logvolv, value volgroupv, value mbytesv)
{
  CAMLparam4 (gv, logvolv, volgroupv, mbytesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvcreate");

  char *logvol;
  logvol = strdup (String_val (logvolv));
  if (logvol == NULL) caml_raise_out_of_memory ();
  char *volgroup;
  volgroup = strdup (String_val (volgroupv));
  if (volgroup == NULL) caml_raise_out_of_memory ();
  int mbytes = Int_val (mbytesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  caml_leave_blocking_section ();
  free (logvol);
  free (volgroup);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvcreate_free : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvcreate_free (value gv, value logvolv, value volgroupv, value percentv);

value
guestfs_int_ocaml_lvcreate_free (value gv, value logvolv, value volgroupv, value percentv)
{
  CAMLparam4 (gv, logvolv, volgroupv, percentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvcreate_free");

  char *logvol;
  logvol = strdup (String_val (logvolv));
  if (logvol == NULL) caml_raise_out_of_memory ();
  char *volgroup;
  volgroup = strdup (String_val (volgroupv));
  if (volgroup == NULL) caml_raise_out_of_memory ();
  int percent = Int_val (percentv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  caml_leave_blocking_section ();
  free (logvol);
  free (volgroup);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvcreate_free");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_canonical_lv_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvm_canonical_lv_name (value gv, value lvnamev);

value
guestfs_int_ocaml_lvm_canonical_lv_name (value gv, value lvnamev)
{
  CAMLparam2 (gv, lvnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvm_canonical_lv_name");

  char *lvname;
  lvname = strdup (String_val (lvnamev));
  if (lvname == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_canonical_lv_name (g, lvname);
  caml_leave_blocking_section ();
  free (lvname);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lvm_canonical_lv_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_clear_filter : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvm_clear_filter (value gv);

value
guestfs_int_ocaml_lvm_clear_filter (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvm_clear_filter");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_clear_filter (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvm_clear_filter");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_remove_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvm_remove_all (value gv);

value
guestfs_int_ocaml_lvm_remove_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvm_remove_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_remove_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvm_remove_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_set_filter : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvm_set_filter (value gv, value devicesv);

value
guestfs_int_ocaml_lvm_set_filter (value gv, value devicesv)
{
  CAMLparam2 (gv, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvm_set_filter");

  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_set_filter (g, devices);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (devices);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvm_set_filter");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvremove (value gv, value devicev);

value
guestfs_int_ocaml_lvremove (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvremove");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvremove (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvrename : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvrename (value gv, value logvolv, value newlogvolv);

value
guestfs_int_ocaml_lvrename (value gv, value logvolv, value newlogvolv)
{
  CAMLparam3 (gv, logvolv, newlogvolv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvrename");

  char *logvol;
  logvol = strdup (String_val (logvolv));
  if (logvol == NULL) caml_raise_out_of_memory ();
  char *newlogvol;
  newlogvol = strdup (String_val (newlogvolv));
  if (newlogvol == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvrename (g, logvol, newlogvol);
  caml_leave_blocking_section ();
  free (logvol);
  free (newlogvol);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvrename");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvresize : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvresize (value gv, value devicev, value mbytesv);

value
guestfs_int_ocaml_lvresize (value gv, value devicev, value mbytesv)
{
  CAMLparam3 (gv, devicev, mbytesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvresize");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int mbytes = Int_val (mbytesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvresize (g, device, mbytes);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvresize_free : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvresize_free (value gv, value lvv, value percentv);

value
guestfs_int_ocaml_lvresize_free (value gv, value lvv, value percentv)
{
  CAMLparam3 (gv, lvv, percentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvresize_free");

  char *lv;
  lv = strdup (String_val (lvv));
  if (lv == NULL) caml_raise_out_of_memory ();
  int percent = Int_val (percentv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvresize_free (g, lv, percent);
  caml_leave_blocking_section ();
  free (lv);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "lvresize_free");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvs (value gv);

value
guestfs_int_ocaml_lvs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_lvs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lvs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvs_full : t -> lvm_lv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvs_full (value gv);

value
guestfs_int_ocaml_lvs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvs_full");

  struct guestfs_lvm_lv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lvs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lvs_full");

  rv = copy_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvuuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lvuuid (value gv, value devicev);

value
guestfs_int_ocaml_lvuuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lvuuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_lvuuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lvuuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lxattrlist : t -> string -> string array -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_lxattrlist (value gv, value pathv, value namesv);

value
guestfs_int_ocaml_lxattrlist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("lxattrlist");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char **names = guestfs_int_ocaml_strings_val (g, namesv);
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lxattrlist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  guestfs_int_free_string_list (names);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "lxattrlist");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val max_disks : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_max_disks (value gv);

value
guestfs_int_ocaml_max_disks (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("max_disks");

  int r;

  r = guestfs_max_disks (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "max_disks");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_create : t -> ?missingbitmap:int64 -> ?nrdevices:int -> ?spare:int -> ?chunk:int64 -> ?level:string -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_md_create (value gv, value missingbitmapv, value nrdevicesv, value sparev, value chunkv, value levelv, value namev, value devicesv);

value
guestfs_int_ocaml_md_create (value gv, value missingbitmapv, value nrdevicesv, value sparev, value chunkv, value levelv, value namev, value devicesv)
{
  CAMLparam5 (gv, missingbitmapv, nrdevicesv, sparev, chunkv);
  CAMLxparam3 (levelv, namev, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("md_create");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  if (missingbitmapv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
    optargs_s.missingbitmap = Int64_val (Field (missingbitmapv, 0));
  }
  if (nrdevicesv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
    optargs_s.nrdevices = Int_val (Field (nrdevicesv, 0));
  }
  if (sparev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
    optargs_s.spare = Int_val (Field (sparev, 0));
  }
  if (chunkv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
    optargs_s.chunk = Int64_val (Field (chunkv, 0));
  }
  if (levelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
    optargs_s.level = strdup (String_val (Field (levelv, 0)));
    if (optargs_s.level == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_md_create_argv (g, name, devices, optargs);
  caml_leave_blocking_section ();
  free (name);
  guestfs_int_free_string_list (devices);
  if (levelv != Val_int (0))
    free ((char *) optargs_s.level);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "md_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_md_create_byte (value *argv, int argn);

value
guestfs_int_ocaml_md_create_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_md_create (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val md_detail : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_md_detail (value gv, value mdv);

value
guestfs_int_ocaml_md_detail (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("md_detail");

  char *md;
  md = strdup (String_val (mdv));
  if (md == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_md_detail (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "md_detail");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_stat : t -> string -> mdstat array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_md_stat (value gv, value mdv);

value
guestfs_int_ocaml_md_stat (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("md_stat");

  char *md;
  md = strdup (String_val (mdv));
  if (md == NULL) caml_raise_out_of_memory ();
  struct guestfs_mdstat_list *r;

  caml_enter_blocking_section ();
  r = guestfs_md_stat (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "md_stat");

  rv = copy_mdstat_list (r);
  guestfs_free_mdstat_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_stop : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_md_stop (value gv, value mdv);

value
guestfs_int_ocaml_md_stop (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("md_stop");

  char *md;
  md = strdup (String_val (mdv));
  if (md == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_md_stop (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "md_stop");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkdir (value gv, value pathv);

value
guestfs_int_ocaml_mkdir (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkdir");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkdir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir_mode : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkdir_mode (value gv, value pathv, value modev);

value
guestfs_int_ocaml_mkdir_mode (value gv, value pathv, value modev)
{
  CAMLparam3 (gv, pathv, modev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkdir_mode");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int mode = Int_val (modev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir_mode (g, path, mode);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkdir_mode");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir_p : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkdir_p (value gv, value pathv);

value
guestfs_int_ocaml_mkdir_p (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkdir_p");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir_p (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkdir_p");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdtemp : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkdtemp (value gv, value tmplv);

value
guestfs_int_ocaml_mkdtemp (value gv, value tmplv)
{
  CAMLparam2 (gv, tmplv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkdtemp");

  char *tmpl;
  tmpl = strdup (String_val (tmplv));
  if (tmpl == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_mkdtemp (g, tmpl);
  caml_leave_blocking_section ();
  free (tmpl);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mkdtemp");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs : t -> ?blockscount:int64 -> ?blocksize:int64 -> ?fragsize:int64 -> ?blockspergroup:int64 -> ?numberofgroups:int64 -> ?bytesperinode:int64 -> ?inodesize:int64 -> ?journalsize:int64 -> ?numberofinodes:int64 -> ?stridesize:int64 -> ?stripewidth:int64 -> ?maxonlineresize:int64 -> ?reservedblockspercentage:int -> ?mmpupdateinterval:int -> ?journaldevice:string -> ?label:string -> ?lastmounteddir:string -> ?creatoros:string -> ?fstype:string -> ?usagetype:string -> ?uuid:string -> ?forcecreate:bool -> ?writesbandgrouponly:bool -> ?lazyitableinit:bool -> ?lazyjournalinit:bool -> ?testfs:bool -> ?discard:bool -> ?quotatype:bool -> ?extent:bool -> ?filetype:bool -> ?flexbg:bool -> ?hasjournal:bool -> ?journaldev:bool -> ?largefile:bool -> ?quota:bool -> ?resizeinode:bool -> ?sparsesuper:bool -> ?uninitbg:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2fs (value gv, value blockscountv, value blocksizev, value fragsizev, value blockspergroupv, value numberofgroupsv, value bytesperinodev, value inodesizev, value journalsizev, value numberofinodesv, value stridesizev, value stripewidthv, value maxonlineresizev, value reservedblockspercentagev, value mmpupdateintervalv, value journaldevicev, value labelv, value lastmounteddirv, value creatorosv, value fstypev, value usagetypev, value uuidv, value forcecreatev, value writesbandgrouponlyv, value lazyitableinitv, value lazyjournalinitv, value testfsv, value discardv, value quotatypev, value extentv, value filetypev, value flexbgv, value hasjournalv, value journaldevv, value largefilev, value quotav, value resizeinodev, value sparsesuperv, value uninitbgv, value devicev);

value
guestfs_int_ocaml_mke2fs (value gv, value blockscountv, value blocksizev, value fragsizev, value blockspergroupv, value numberofgroupsv, value bytesperinodev, value inodesizev, value journalsizev, value numberofinodesv, value stridesizev, value stripewidthv, value maxonlineresizev, value reservedblockspercentagev, value mmpupdateintervalv, value journaldevicev, value labelv, value lastmounteddirv, value creatorosv, value fstypev, value usagetypev, value uuidv, value forcecreatev, value writesbandgrouponlyv, value lazyitableinitv, value lazyjournalinitv, value testfsv, value discardv, value quotatypev, value extentv, value filetypev, value flexbgv, value hasjournalv, value journaldevv, value largefilev, value quotav, value resizeinodev, value sparsesuperv, value uninitbgv, value devicev)
{
  CAMLparam5 (gv, blockscountv, blocksizev, fragsizev, blockspergroupv);
  CAMLxparam5 (numberofgroupsv, bytesperinodev, inodesizev, journalsizev, numberofinodesv);
  CAMLxparam5 (stridesizev, stripewidthv, maxonlineresizev, reservedblockspercentagev, mmpupdateintervalv);
  CAMLxparam5 (journaldevicev, labelv, lastmounteddirv, creatorosv, fstypev);
  CAMLxparam5 (usagetypev, uuidv, forcecreatev, writesbandgrouponlyv, lazyitableinitv);
  CAMLxparam5 (lazyjournalinitv, testfsv, discardv, quotatypev, extentv);
  CAMLxparam5 (filetypev, flexbgv, hasjournalv, journaldevv, largefilev);
  CAMLxparam5 (quotav, resizeinodev, sparsesuperv, uninitbgv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2fs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  if (blockscountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
    optargs_s.blockscount = Int64_val (Field (blockscountv, 0));
  }
  if (blocksizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = Int64_val (Field (blocksizev, 0));
  }
  if (fragsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
    optargs_s.fragsize = Int64_val (Field (fragsizev, 0));
  }
  if (blockspergroupv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
    optargs_s.blockspergroup = Int64_val (Field (blockspergroupv, 0));
  }
  if (numberofgroupsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
    optargs_s.numberofgroups = Int64_val (Field (numberofgroupsv, 0));
  }
  if (bytesperinodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
    optargs_s.bytesperinode = Int64_val (Field (bytesperinodev, 0));
  }
  if (inodesizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
    optargs_s.inodesize = Int64_val (Field (inodesizev, 0));
  }
  if (journalsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
    optargs_s.journalsize = Int64_val (Field (journalsizev, 0));
  }
  if (numberofinodesv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
    optargs_s.numberofinodes = Int64_val (Field (numberofinodesv, 0));
  }
  if (stridesizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
    optargs_s.stridesize = Int64_val (Field (stridesizev, 0));
  }
  if (stripewidthv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
    optargs_s.stripewidth = Int64_val (Field (stripewidthv, 0));
  }
  if (maxonlineresizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
    optargs_s.maxonlineresize = Int64_val (Field (maxonlineresizev, 0));
  }
  if (reservedblockspercentagev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = Int_val (Field (reservedblockspercentagev, 0));
  }
  if (mmpupdateintervalv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
    optargs_s.mmpupdateinterval = Int_val (Field (mmpupdateintervalv, 0));
  }
  if (journaldevicev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
    optargs_s.journaldevice = strdup (String_val (Field (journaldevicev, 0)));
    if (optargs_s.journaldevice == NULL) caml_raise_out_of_memory ();
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  if (lastmounteddirv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
    optargs_s.lastmounteddir = strdup (String_val (Field (lastmounteddirv, 0)));
    if (optargs_s.lastmounteddir == NULL) caml_raise_out_of_memory ();
  }
  if (creatorosv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
    optargs_s.creatoros = strdup (String_val (Field (creatorosv, 0)));
    if (optargs_s.creatoros == NULL) caml_raise_out_of_memory ();
  }
  if (fstypev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
    optargs_s.fstype = strdup (String_val (Field (fstypev, 0)));
    if (optargs_s.fstype == NULL) caml_raise_out_of_memory ();
  }
  if (usagetypev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
    optargs_s.usagetype = strdup (String_val (Field (usagetypev, 0)));
    if (optargs_s.usagetype == NULL) caml_raise_out_of_memory ();
  }
  if (uuidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
    optargs_s.uuid = strdup (String_val (Field (uuidv, 0)));
    if (optargs_s.uuid == NULL) caml_raise_out_of_memory ();
  }
  if (forcecreatev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
    optargs_s.forcecreate = Bool_val (Field (forcecreatev, 0));
  }
  if (writesbandgrouponlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
    optargs_s.writesbandgrouponly = Bool_val (Field (writesbandgrouponlyv, 0));
  }
  if (lazyitableinitv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
    optargs_s.lazyitableinit = Bool_val (Field (lazyitableinitv, 0));
  }
  if (lazyjournalinitv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
    optargs_s.lazyjournalinit = Bool_val (Field (lazyjournalinitv, 0));
  }
  if (testfsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
    optargs_s.testfs = Bool_val (Field (testfsv, 0));
  }
  if (discardv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
    optargs_s.discard = Bool_val (Field (discardv, 0));
  }
  if (quotatypev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
    optargs_s.quotatype = Bool_val (Field (quotatypev, 0));
  }
  if (extentv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
    optargs_s.extent = Bool_val (Field (extentv, 0));
  }
  if (filetypev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
    optargs_s.filetype = Bool_val (Field (filetypev, 0));
  }
  if (flexbgv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
    optargs_s.flexbg = Bool_val (Field (flexbgv, 0));
  }
  if (hasjournalv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
    optargs_s.hasjournal = Bool_val (Field (hasjournalv, 0));
  }
  if (journaldevv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
    optargs_s.journaldev = Bool_val (Field (journaldevv, 0));
  }
  if (largefilev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
    optargs_s.largefile = Bool_val (Field (largefilev, 0));
  }
  if (quotav != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
    optargs_s.quota = Bool_val (Field (quotav, 0));
  }
  if (resizeinodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
    optargs_s.resizeinode = Bool_val (Field (resizeinodev, 0));
  }
  if (sparsesuperv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
    optargs_s.sparsesuper = Bool_val (Field (sparsesuperv, 0));
  }
  if (uninitbgv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
    optargs_s.uninitbg = Bool_val (Field (uninitbgv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (journaldevicev != Val_int (0))
    free ((char *) optargs_s.journaldevice);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (lastmounteddirv != Val_int (0))
    free ((char *) optargs_s.lastmounteddir);
  if (creatorosv != Val_int (0))
    free ((char *) optargs_s.creatoros);
  if (fstypev != Val_int (0))
    free ((char *) optargs_s.fstype);
  if (usagetypev != Val_int (0))
    free ((char *) optargs_s.usagetype);
  if (uuidv != Val_int (0))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2fs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2fs_byte (value *argv, int argn);

value
guestfs_int_ocaml_mke2fs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_mke2fs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14], argv[15], argv[16], argv[17], argv[18], argv[19], argv[20], argv[21], argv[22], argv[23], argv[24], argv[25], argv[26], argv[27], argv[28], argv[29], argv[30], argv[31], argv[32], argv[33], argv[34], argv[35], argv[36], argv[37], argv[38], argv[39]);
}

/* Automatically generated wrapper for function
 * val mke2fs_J : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2fs_J (value gv, value fstypev, value blocksizev, value devicev, value journalv);

value
guestfs_int_ocaml_mke2fs_J (value gv, value fstypev, value blocksizev, value devicev, value journalv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, journalv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2fs_J");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  int blocksize = Int_val (blocksizev);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *journal;
  journal = strdup (String_val (journalv));
  if (journal == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (journal);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2fs_J");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs_JL : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2fs_JL (value gv, value fstypev, value blocksizev, value devicev, value labelv);

value
guestfs_int_ocaml_mke2fs_JL (value gv, value fstypev, value blocksizev, value devicev, value labelv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2fs_JL");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  int blocksize = Int_val (blocksizev);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2fs_JL");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs_JU : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2fs_JU (value gv, value fstypev, value blocksizev, value devicev, value uuidv);

value
guestfs_int_ocaml_mke2fs_JU (value gv, value fstypev, value blocksizev, value devicev, value uuidv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2fs_JU");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  int blocksize = Int_val (blocksizev);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2fs_JU");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2journal (value gv, value blocksizev, value devicev);

value
guestfs_int_ocaml_mke2journal (value gv, value blocksizev, value devicev)
{
  CAMLparam3 (gv, blocksizev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2journal");

  int blocksize = Int_val (blocksizev);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal (g, blocksize, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2journal");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal_L : t -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2journal_L (value gv, value blocksizev, value labelv, value devicev);

value
guestfs_int_ocaml_mke2journal_L (value gv, value blocksizev, value labelv, value devicev)
{
  CAMLparam4 (gv, blocksizev, labelv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2journal_L");

  int blocksize = Int_val (blocksizev);
  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal_L (g, blocksize, label, device);
  caml_leave_blocking_section ();
  free (label);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2journal_L");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal_U : t -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mke2journal_U (value gv, value blocksizev, value uuidv, value devicev);

value
guestfs_int_ocaml_mke2journal_U (value gv, value blocksizev, value uuidv, value devicev)
{
  CAMLparam4 (gv, blocksizev, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mke2journal_U");

  int blocksize = Int_val (blocksizev);
  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  caml_leave_blocking_section ();
  free (uuid);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mke2journal_U");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfifo : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfifo (value gv, value modev, value pathv);

value
guestfs_int_ocaml_mkfifo (value gv, value modev, value pathv)
{
  CAMLparam3 (gv, modev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkfifo");

  int mode = Int_val (modev);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfifo (g, mode, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkfifo");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfs : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> ?label:string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfs (value gv, value blocksizev, value featuresv, value inodev, value sectorsizev, value labelv, value fstypev, value devicev);

value
guestfs_int_ocaml_mkfs (value gv, value blocksizev, value featuresv, value inodev, value sectorsizev, value labelv, value fstypev, value devicev)
{
  CAMLparam5 (gv, blocksizev, featuresv, inodev, sectorsizev);
  CAMLxparam3 (labelv, fstypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkfs");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  if (blocksizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = Int_val (Field (blocksizev, 0));
  }
  if (featuresv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
    optargs_s.features = strdup (String_val (Field (featuresv, 0)));
    if (optargs_s.features == NULL) caml_raise_out_of_memory ();
  }
  if (inodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
    optargs_s.inode = Int_val (Field (inodev, 0));
  }
  if (sectorsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = Int_val (Field (sectorsizev, 0));
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (featuresv != Val_int (0))
    free ((char *) optargs_s.features);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfs_byte (value *argv, int argn);

value
guestfs_int_ocaml_mkfs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_mkfs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val mkfs_b : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfs_b (value gv, value fstypev, value blocksizev, value devicev);

value
guestfs_int_ocaml_mkfs_b (value gv, value fstypev, value blocksizev, value devicev)
{
  CAMLparam4 (gv, fstypev, blocksizev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkfs_b");

  char *fstype;
  fstype = strdup (String_val (fstypev));
  if (fstype == NULL) caml_raise_out_of_memory ();
  int blocksize = Int_val (blocksizev);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkfs_b");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfs_btrfs : t -> ?allocstart:int64 -> ?bytecount:int64 -> ?datatype:string -> ?leafsize:int -> ?label:string -> ?metadata:string -> ?nodesize:int -> ?sectorsize:int -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfs_btrfs (value gv, value allocstartv, value bytecountv, value datatypev, value leafsizev, value labelv, value metadatav, value nodesizev, value sectorsizev, value devicesv);

value
guestfs_int_ocaml_mkfs_btrfs (value gv, value allocstartv, value bytecountv, value datatypev, value leafsizev, value labelv, value metadatav, value nodesizev, value sectorsizev, value devicesv)
{
  CAMLparam5 (gv, allocstartv, bytecountv, datatypev, leafsizev);
  CAMLxparam5 (labelv, metadatav, nodesizev, sectorsizev, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkfs_btrfs");

  char **devices = guestfs_int_ocaml_strings_val (g, devicesv);
  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  if (allocstartv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
    optargs_s.allocstart = Int64_val (Field (allocstartv, 0));
  }
  if (bytecountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
    optargs_s.bytecount = Int64_val (Field (bytecountv, 0));
  }
  if (datatypev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
    optargs_s.datatype = strdup (String_val (Field (datatypev, 0)));
    if (optargs_s.datatype == NULL) caml_raise_out_of_memory ();
  }
  if (leafsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
    optargs_s.leafsize = Int_val (Field (leafsizev, 0));
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  if (metadatav != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
    optargs_s.metadata = strdup (String_val (Field (metadatav, 0)));
    if (optargs_s.metadata == NULL) caml_raise_out_of_memory ();
  }
  if (nodesizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
    optargs_s.nodesize = Int_val (Field (nodesizev, 0));
  }
  if (sectorsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = Int_val (Field (sectorsizev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (devices);
  if (datatypev != Val_int (0))
    free ((char *) optargs_s.datatype);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (metadatav != Val_int (0))
    free ((char *) optargs_s.metadata);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkfs_btrfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkfs_btrfs_byte (value *argv, int argn);

value
guestfs_int_ocaml_mkfs_btrfs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_mkfs_btrfs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

/* Automatically generated wrapper for function
 * val mklost_and_found : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mklost_and_found (value gv, value mountpointv);

value
guestfs_int_ocaml_mklost_and_found (value gv, value mountpointv)
{
  CAMLparam2 (gv, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mklost_and_found");

  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mklost_and_found (g, mountpoint);
  caml_leave_blocking_section ();
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mklost_and_found");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkmountpoint : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkmountpoint (value gv, value exemptpathv);

value
guestfs_int_ocaml_mkmountpoint (value gv, value exemptpathv)
{
  CAMLparam2 (gv, exemptpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkmountpoint");

  char *exemptpath;
  exemptpath = strdup (String_val (exemptpathv));
  if (exemptpath == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkmountpoint (g, exemptpath);
  caml_leave_blocking_section ();
  free (exemptpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkmountpoint");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mknod (value gv, value modev, value devmajorv, value devminorv, value pathv);

value
guestfs_int_ocaml_mknod (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mknod");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mknod");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod_b : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mknod_b (value gv, value modev, value devmajorv, value devminorv, value pathv);

value
guestfs_int_ocaml_mknod_b (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mknod_b");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mknod_b");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod_c : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mknod_c (value gv, value modev, value devmajorv, value devminorv, value pathv);

value
guestfs_int_ocaml_mknod_c (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mknod_c");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mknod_c");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mksquashfs : t -> ?compress:string -> ?excludes:string array -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mksquashfs (value gv, value compressv, value excludesv, value pathv, value filenamev);

value
guestfs_int_ocaml_mksquashfs (value gv, value compressv, value excludesv, value pathv, value filenamev)
{
  CAMLparam5 (gv, compressv, excludesv, pathv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mksquashfs");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  struct guestfs_mksquashfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  if (compressv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKSQUASHFS_COMPRESS_BITMASK;
    optargs_s.compress = strdup (String_val (Field (compressv, 0)));
    if (optargs_s.compress == NULL) caml_raise_out_of_memory ();
  }
  if (excludesv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK;
    optargs_s.excludes = guestfs_int_ocaml_strings_val (g, Field (excludesv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mksquashfs_argv (g, path, filename, optargs);
  caml_leave_blocking_section ();
  free (path);
  free (filename);
  if (compressv != Val_int (0))
    free ((char *) optargs_s.compress);
  if (excludesv != Val_int (0))
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mksquashfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap : t -> ?label:string -> ?uuid:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkswap (value gv, value labelv, value uuidv, value devicev);

value
guestfs_int_ocaml_mkswap (value gv, value labelv, value uuidv, value devicev)
{
  CAMLparam4 (gv, labelv, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkswap");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  if (uuidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
    optargs_s.uuid = strdup (String_val (Field (uuidv, 0)));
    if (optargs_s.uuid == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_opts_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (uuidv != Val_int (0))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkswap");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_L : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkswap_L (value gv, value labelv, value devicev);

value
guestfs_int_ocaml_mkswap_L (value gv, value labelv, value devicev)
{
  CAMLparam3 (gv, labelv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkswap_L");

  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_L (g, label, device);
  caml_leave_blocking_section ();
  free (label);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkswap_L");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_U : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkswap_U (value gv, value uuidv, value devicev);

value
guestfs_int_ocaml_mkswap_U (value gv, value uuidv, value devicev)
{
  CAMLparam3 (gv, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkswap_U");

  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_U (g, uuid, device);
  caml_leave_blocking_section ();
  free (uuid);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkswap_U");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mkswap_file (value gv, value pathv);

value
guestfs_int_ocaml_mkswap_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mkswap_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mkswap_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mktemp : t -> ?suffix:string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mktemp (value gv, value suffixv, value tmplv);

value
guestfs_int_ocaml_mktemp (value gv, value suffixv, value tmplv)
{
  CAMLparam3 (gv, suffixv, tmplv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mktemp");

  char *tmpl;
  tmpl = strdup (String_val (tmplv));
  if (tmpl == NULL) caml_raise_out_of_memory ();
  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  if (suffixv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
    optargs_s.suffix = strdup (String_val (Field (suffixv, 0)));
    if (optargs_s.suffix == NULL) caml_raise_out_of_memory ();
  }
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_mktemp_argv (g, tmpl, optargs);
  caml_leave_blocking_section ();
  free (tmpl);
  if (suffixv != Val_int (0))
    free ((char *) optargs_s.suffix);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mktemp");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val modprobe : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_modprobe (value gv, value modulenamev);

value
guestfs_int_ocaml_modprobe (value gv, value modulenamev)
{
  CAMLparam2 (gv, modulenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("modprobe");

  char *modulename;
  modulename = strdup (String_val (modulenamev));
  if (modulename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_modprobe (g, modulename);
  caml_leave_blocking_section ();
  free (modulename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "modprobe");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount (value gv, value mountablev, value mountpointv);

value
guestfs_int_ocaml_mount (value gv, value mountablev, value mountpointv)
{
  CAMLparam3 (gv, mountablev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount (g, mountable, mountpoint);
  caml_leave_blocking_section ();
  free (mountable);
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_9p : t -> ?options:string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_9p (value gv, value optionsv, value mounttagv, value mountpointv);

value
guestfs_int_ocaml_mount_9p (value gv, value optionsv, value mounttagv, value mountpointv)
{
  CAMLparam4 (gv, optionsv, mounttagv, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_9p");

  char *mounttag;
  mounttag = strdup (String_val (mounttagv));
  if (mounttag == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  if (optionsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
    optargs_s.options = strdup (String_val (Field (optionsv, 0)));
    if (optargs_s.options == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  caml_leave_blocking_section ();
  free (mounttag);
  free (mountpoint);
  if (optionsv != Val_int (0))
    free ((char *) optargs_s.options);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_9p");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_local : t -> ?readonly:bool -> ?options:string -> ?cachetimeout:int -> ?debugcalls:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_local (value gv, value readonlyv, value optionsv, value cachetimeoutv, value debugcallsv, value localmountpointv);

value
guestfs_int_ocaml_mount_local (value gv, value readonlyv, value optionsv, value cachetimeoutv, value debugcallsv, value localmountpointv)
{
  CAMLparam5 (gv, readonlyv, optionsv, cachetimeoutv, debugcallsv);
  CAMLxparam1 (localmountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_local");

  char *localmountpoint;
  localmountpoint = strdup (String_val (localmountpointv));
  if (localmountpoint == NULL) caml_raise_out_of_memory ();
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (optionsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
    optargs_s.options = strdup (String_val (Field (optionsv, 0)));
    if (optargs_s.options == NULL) caml_raise_out_of_memory ();
  }
  if (cachetimeoutv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
    optargs_s.cachetimeout = Int_val (Field (cachetimeoutv, 0));
  }
  if (debugcallsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
    optargs_s.debugcalls = Bool_val (Field (debugcallsv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  caml_leave_blocking_section ();
  free (localmountpoint);
  if (optionsv != Val_int (0))
    free ((char *) optargs_s.options);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_local");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_local_byte (value *argv, int argn);

value
guestfs_int_ocaml_mount_local_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_mount_local (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val mount_local_run : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_local_run (value gv);

value
guestfs_int_ocaml_mount_local_run (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_local_run");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_local_run (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_local_run");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_loop : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_loop (value gv, value filev, value mountpointv);

value
guestfs_int_ocaml_mount_loop (value gv, value filev, value mountpointv)
{
  CAMLparam3 (gv, filev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_loop");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_loop (g, file, mountpoint);
  caml_leave_blocking_section ();
  free (file);
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_loop");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_options : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_options (value gv, value optionsv, value mountablev, value mountpointv);

value
guestfs_int_ocaml_mount_options (value gv, value optionsv, value mountablev, value mountpointv)
{
  CAMLparam4 (gv, optionsv, mountablev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_options");

  char *options;
  options = strdup (String_val (optionsv));
  if (options == NULL) caml_raise_out_of_memory ();
  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_options (g, options, mountable, mountpoint);
  caml_leave_blocking_section ();
  free (options);
  free (mountable);
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_options");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_ro : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_ro (value gv, value mountablev, value mountpointv);

value
guestfs_int_ocaml_mount_ro (value gv, value mountablev, value mountpointv)
{
  CAMLparam3 (gv, mountablev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_ro");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_ro (g, mountable, mountpoint);
  caml_leave_blocking_section ();
  free (mountable);
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_vfs : t -> string -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mount_vfs (value gv, value optionsv, value vfstypev, value mountablev, value mountpointv);

value
guestfs_int_ocaml_mount_vfs (value gv, value optionsv, value vfstypev, value mountablev, value mountpointv)
{
  CAMLparam5 (gv, optionsv, vfstypev, mountablev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mount_vfs");

  char *options;
  options = strdup (String_val (optionsv));
  if (options == NULL) caml_raise_out_of_memory ();
  char *vfstype;
  vfstype = strdup (String_val (vfstypev));
  if (vfstype == NULL) caml_raise_out_of_memory ();
  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  caml_leave_blocking_section ();
  free (options);
  free (vfstype);
  free (mountable);
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mount_vfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mountable_device : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mountable_device (value gv, value mountablev);

value
guestfs_int_ocaml_mountable_device (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mountable_device");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_mountable_device (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mountable_device");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mountable_subvolume : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mountable_subvolume (value gv, value mountablev);

value
guestfs_int_ocaml_mountable_subvolume (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mountable_subvolume");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_mountable_subvolume (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mountable_subvolume");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mountpoints : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mountpoints (value gv);

value
guestfs_int_ocaml_mountpoints (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mountpoints");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_mountpoints (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mountpoints");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mounts : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mounts (value gv);

value
guestfs_int_ocaml_mounts (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mounts");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_mounts (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "mounts");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mv : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_mv (value gv, value srcv, value destv);

value
guestfs_int_ocaml_mv (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("mv");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mv (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "mv");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val nr_devices : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_nr_devices (value gv);

value
guestfs_int_ocaml_nr_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("nr_devices");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_nr_devices (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "nr_devices");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfs_3g_probe : t -> bool -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfs_3g_probe (value gv, value rwv, value devicev);

value
guestfs_int_ocaml_ntfs_3g_probe (value gv, value rwv, value devicev)
{
  CAMLparam3 (gv, rwv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfs_3g_probe");

  int rw = Bool_val (rwv);
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfs_3g_probe (g, rw, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfs_3g_probe");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfscat_i : t -> string -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfscat_i (value gv, value devicev, value inodev, value filenamev);

value
guestfs_int_ocaml_ntfscat_i (value gv, value devicev, value inodev, value filenamev)
{
  CAMLparam4 (gv, devicev, inodev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfscat_i");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t inode = Int64_val (inodev);
  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfscat_i (g, device, inode, filename);
  caml_leave_blocking_section ();
  free (device);
  free (filename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfscat_i");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsclone_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsclone_in (value gv, value backupfilev, value devicev);

value
guestfs_int_ocaml_ntfsclone_in (value gv, value backupfilev, value devicev)
{
  CAMLparam3 (gv, backupfilev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfsclone_in");

  char *backupfile;
  backupfile = strdup (String_val (backupfilev));
  if (backupfile == NULL) caml_raise_out_of_memory ();
  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsclone_in (g, backupfile, device);
  caml_leave_blocking_section ();
  free (backupfile);
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfsclone_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsclone_out : t -> ?metadataonly:bool -> ?rescue:bool -> ?ignorefscheck:bool -> ?preservetimestamps:bool -> ?force:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsclone_out (value gv, value metadataonlyv, value rescuev, value ignorefscheckv, value preservetimestampsv, value forcev, value devicev, value backupfilev);

value
guestfs_int_ocaml_ntfsclone_out (value gv, value metadataonlyv, value rescuev, value ignorefscheckv, value preservetimestampsv, value forcev, value devicev, value backupfilev)
{
  CAMLparam5 (gv, metadataonlyv, rescuev, ignorefscheckv, preservetimestampsv);
  CAMLxparam3 (forcev, devicev, backupfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfsclone_out");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *backupfile;
  backupfile = strdup (String_val (backupfilev));
  if (backupfile == NULL) caml_raise_out_of_memory ();
  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  if (metadataonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
    optargs_s.metadataonly = Bool_val (Field (metadataonlyv, 0));
  }
  if (rescuev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
    optargs_s.rescue = Bool_val (Field (rescuev, 0));
  }
  if (ignorefscheckv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
    optargs_s.ignorefscheck = Bool_val (Field (ignorefscheckv, 0));
  }
  if (preservetimestampsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
    optargs_s.preservetimestamps = Bool_val (Field (preservetimestampsv, 0));
  }
  if (forcev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
    optargs_s.force = Bool_val (Field (forcev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  caml_leave_blocking_section ();
  free (device);
  free (backupfile);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfsclone_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsclone_out_byte (value *argv, int argn);

value
guestfs_int_ocaml_ntfsclone_out_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_ntfsclone_out (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val ntfsfix : t -> ?clearbadsectors:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsfix (value gv, value clearbadsectorsv, value devicev);

value
guestfs_int_ocaml_ntfsfix (value gv, value clearbadsectorsv, value devicev)
{
  CAMLparam3 (gv, clearbadsectorsv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfsfix");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  if (clearbadsectorsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
    optargs_s.clearbadsectors = Bool_val (Field (clearbadsectorsv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsfix_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfsfix");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsresize : t -> ?size:int64 -> ?force:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsresize (value gv, value sizev, value forcev, value devicev);

value
guestfs_int_ocaml_ntfsresize (value gv, value sizev, value forcev, value devicev)
{
  CAMLparam4 (gv, sizev, forcev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfsresize");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  if (sizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
    optargs_s.size = Int64_val (Field (sizev, 0));
  }
  if (forcev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
    optargs_s.force = Bool_val (Field (forcev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfsresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsresize_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ntfsresize_size (value gv, value devicev, value sizev);

value
guestfs_int_ocaml_ntfsresize_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ntfsresize_size");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsresize_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ntfsresize_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val parse_environment : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_parse_environment (value gv);

value
guestfs_int_ocaml_parse_environment (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("parse_environment");

  int r;

  r = guestfs_parse_environment (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "parse_environment");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val parse_environment_list : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_parse_environment_list (value gv, value environmentv);

value
guestfs_int_ocaml_parse_environment_list (value gv, value environmentv)
{
  CAMLparam2 (gv, environmentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("parse_environment_list");

  char **environment = guestfs_int_ocaml_strings_val (g, environmentv);
  int r;

  r = guestfs_parse_environment_list (g, environment);
  guestfs_int_free_string_list (environment);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "parse_environment_list");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_add : t -> string -> string -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_add (value gv, value devicev, value prlogexv, value startsectv, value endsectv);

value
guestfs_int_ocaml_part_add (value gv, value devicev, value prlogexv, value startsectv, value endsectv)
{
  CAMLparam5 (gv, devicev, prlogexv, startsectv, endsectv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_add");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *prlogex;
  prlogex = strdup (String_val (prlogexv));
  if (prlogex == NULL) caml_raise_out_of_memory ();
  int64_t startsect = Int64_val (startsectv);
  int64_t endsect = Int64_val (endsectv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  caml_leave_blocking_section ();
  free (device);
  free (prlogex);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_add");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_del : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_del (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_del (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_del");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_del (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_del");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_disk : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_disk (value gv, value devicev, value parttypev);

value
guestfs_int_ocaml_part_disk (value gv, value devicev, value parttypev)
{
  CAMLparam3 (gv, devicev, parttypev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_disk");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *parttype;
  parttype = strdup (String_val (parttypev));
  if (parttype == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_disk (g, device, parttype);
  caml_leave_blocking_section ();
  free (device);
  free (parttype);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_disk");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_expand_gpt : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_expand_gpt (value gv, value devicev);

value
guestfs_int_ocaml_part_expand_gpt (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_expand_gpt");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_expand_gpt (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_expand_gpt");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_bootable : t -> string -> int -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_bootable (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_bootable (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_bootable");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_bootable (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_get_bootable");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_disk_guid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_disk_guid (value gv, value devicev);

value
guestfs_int_ocaml_part_get_disk_guid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_disk_guid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_disk_guid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_disk_guid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_gpt_guid : t -> string -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_gpt_guid (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_gpt_guid (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_gpt_guid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_gpt_guid (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_gpt_guid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_gpt_type : t -> string -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_gpt_type (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_gpt_type (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_gpt_type");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_gpt_type (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_gpt_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_mbr_id : t -> string -> int -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_mbr_id (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_mbr_id (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_mbr_id");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_mbr_id (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_get_mbr_id");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_mbr_part_type : t -> string -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_mbr_part_type (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_mbr_part_type (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_mbr_part_type");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_mbr_part_type (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_mbr_part_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_name : t -> string -> int -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_name (value gv, value devicev, value partnumv);

value
guestfs_int_ocaml_part_get_name (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_name");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_name (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_parttype : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_get_parttype (value gv, value devicev);

value
guestfs_int_ocaml_part_get_parttype (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_get_parttype");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_parttype (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_get_parttype");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_init : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_init (value gv, value devicev, value parttypev);

value
guestfs_int_ocaml_part_init (value gv, value devicev, value parttypev)
{
  CAMLparam3 (gv, devicev, parttypev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_init");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *parttype;
  parttype = strdup (String_val (parttypev));
  if (parttype == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_init (g, device, parttype);
  caml_leave_blocking_section ();
  free (device);
  free (parttype);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_list : t -> string -> partition array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_list (value gv, value devicev);

value
guestfs_int_ocaml_part_list (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_list");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_partition_list *r;

  caml_enter_blocking_section ();
  r = guestfs_part_list (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_list");

  rv = copy_partition_list (r);
  guestfs_free_partition_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_bootable : t -> string -> int -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_bootable (value gv, value devicev, value partnumv, value bootablev);

value
guestfs_int_ocaml_part_set_bootable (value gv, value devicev, value partnumv, value bootablev)
{
  CAMLparam4 (gv, devicev, partnumv, bootablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_bootable");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int bootable = Bool_val (bootablev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_bootable");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_disk_guid : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_disk_guid (value gv, value devicev, value guidv);

value
guestfs_int_ocaml_part_set_disk_guid (value gv, value devicev, value guidv)
{
  CAMLparam3 (gv, devicev, guidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_disk_guid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *guid;
  guid = strdup (String_val (guidv));
  if (guid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_disk_guid (g, device, guid);
  caml_leave_blocking_section ();
  free (device);
  free (guid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_disk_guid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_disk_guid_random : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_disk_guid_random (value gv, value devicev);

value
guestfs_int_ocaml_part_set_disk_guid_random (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_disk_guid_random");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_disk_guid_random (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_disk_guid_random");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_gpt_guid : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_gpt_guid (value gv, value devicev, value partnumv, value guidv);

value
guestfs_int_ocaml_part_set_gpt_guid (value gv, value devicev, value partnumv, value guidv)
{
  CAMLparam4 (gv, devicev, partnumv, guidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_gpt_guid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *guid;
  guid = strdup (String_val (guidv));
  if (guid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);
  caml_leave_blocking_section ();
  free (device);
  free (guid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_gpt_guid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_gpt_type : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_gpt_type (value gv, value devicev, value partnumv, value guidv);

value
guestfs_int_ocaml_part_set_gpt_type (value gv, value devicev, value partnumv, value guidv)
{
  CAMLparam4 (gv, devicev, partnumv, guidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_gpt_type");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *guid;
  guid = strdup (String_val (guidv));
  if (guid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  caml_leave_blocking_section ();
  free (device);
  free (guid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_gpt_type");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_mbr_id : t -> string -> int -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_mbr_id (value gv, value devicev, value partnumv, value idbytev);

value
guestfs_int_ocaml_part_set_mbr_id (value gv, value devicev, value partnumv, value idbytev)
{
  CAMLparam4 (gv, devicev, partnumv, idbytev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_mbr_id");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int idbyte = Int_val (idbytev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_mbr_id");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_name : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_set_name (value gv, value devicev, value partnumv, value namev);

value
guestfs_int_ocaml_part_set_name (value gv, value devicev, value partnumv, value namev)
{
  CAMLparam4 (gv, devicev, partnumv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_set_name");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_name (g, device, partnum, name);
  caml_leave_blocking_section ();
  free (device);
  free (name);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_set_name");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_to_dev : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_to_dev (value gv, value partitionv);

value
guestfs_int_ocaml_part_to_dev (value gv, value partitionv)
{
  CAMLparam2 (gv, partitionv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_to_dev");

  char *partition;
  partition = strdup (String_val (partitionv));
  if (partition == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_to_dev (g, partition);
  caml_leave_blocking_section ();
  free (partition);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "part_to_dev");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_to_partnum : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_part_to_partnum (value gv, value partitionv);

value
guestfs_int_ocaml_part_to_partnum (value gv, value partitionv)
{
  CAMLparam2 (gv, partitionv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("part_to_partnum");

  char *partition;
  partition = strdup (String_val (partitionv));
  if (partition == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_to_partnum (g, partition);
  caml_leave_blocking_section ();
  free (partition);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "part_to_partnum");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ping_daemon : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_ping_daemon (value gv);

value
guestfs_int_ocaml_ping_daemon (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("ping_daemon");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_ping_daemon (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "ping_daemon");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pread : t -> string -> int -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pread (value gv, value pathv, value countv, value offsetv);

value
guestfs_int_ocaml_pread (value gv, value pathv, value countv, value offsetv)
{
  CAMLparam4 (gv, pathv, countv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pread");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int count = Int_val (countv);
  int64_t offset = Int64_val (offsetv);
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_pread (g, path, count, offset, &size);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "pread");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pread_device : t -> string -> int -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pread_device (value gv, value devicev, value countv, value offsetv);

value
guestfs_int_ocaml_pread_device (value gv, value devicev, value countv, value offsetv)
{
  CAMLparam4 (gv, devicev, countv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pread_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int count = Int_val (countv);
  int64_t offset = Int64_val (offsetv);
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_pread_device (g, device, count, offset, &size);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "pread_device");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvchange_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvchange_uuid (value gv, value devicev);

value
guestfs_int_ocaml_pvchange_uuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvchange_uuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvchange_uuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvchange_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvchange_uuid_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvchange_uuid_all (value gv);

value
guestfs_int_ocaml_pvchange_uuid_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvchange_uuid_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvchange_uuid_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvchange_uuid_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvcreate : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvcreate (value gv, value devicev);

value
guestfs_int_ocaml_pvcreate (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvcreate");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvcreate (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvremove (value gv, value devicev);

value
guestfs_int_ocaml_pvremove (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvremove");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvremove (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvresize : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvresize (value gv, value devicev);

value
guestfs_int_ocaml_pvresize (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvresize");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvresize (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvresize_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvresize_size (value gv, value devicev, value sizev);

value
guestfs_int_ocaml_pvresize_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvresize_size");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvresize_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pvresize_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvs (value gv);

value
guestfs_int_ocaml_pvs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_pvs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "pvs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvs_full : t -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvs_full (value gv);

value
guestfs_int_ocaml_pvs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvs_full");

  struct guestfs_lvm_pv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_pvs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "pvs_full");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvuuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pvuuid (value gv, value devicev);

value
guestfs_int_ocaml_pvuuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pvuuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_pvuuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "pvuuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pwrite : t -> string -> string -> int64 -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pwrite (value gv, value pathv, value contentv, value offsetv);

value
guestfs_int_ocaml_pwrite (value gv, value pathv, value contentv, value offsetv)
{
  CAMLparam4 (gv, pathv, contentv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pwrite");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t content_size = caml_string_length (contentv);
  char *content;
  content = malloc (content_size);
  if (content == NULL) caml_raise_out_of_memory ();
  memcpy (content, String_val (contentv), content_size);
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pwrite (g, path, content, content_size, offset);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pwrite");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pwrite_device : t -> string -> string -> int64 -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_pwrite_device (value gv, value devicev, value contentv, value offsetv);

value
guestfs_int_ocaml_pwrite_device (value gv, value devicev, value contentv, value offsetv)
{
  CAMLparam4 (gv, devicev, contentv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("pwrite_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  size_t content_size = caml_string_length (contentv);
  char *content;
  content = malloc (content_size);
  if (content == NULL) caml_raise_out_of_memory ();
  memcpy (content, String_val (contentv), content_size);
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  caml_leave_blocking_section ();
  free (device);
  free (content);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "pwrite_device");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val read_file : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_read_file (value gv, value pathv);

value
guestfs_int_ocaml_read_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("read_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_read_file (g, path, &size);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "read_file");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val read_lines : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_read_lines (value gv, value pathv);

value
guestfs_int_ocaml_read_lines (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("read_lines");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_read_lines (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "read_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readdir : t -> string -> dirent array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_readdir (value gv, value dirv);

value
guestfs_int_ocaml_readdir (value gv, value dirv)
{
  CAMLparam2 (gv, dirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("readdir");

  char *dir;
  dir = strdup (String_val (dirv));
  if (dir == NULL) caml_raise_out_of_memory ();
  struct guestfs_dirent_list *r;

  caml_enter_blocking_section ();
  r = guestfs_readdir (g, dir);
  caml_leave_blocking_section ();
  free (dir);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "readdir");

  rv = copy_dirent_list (r);
  guestfs_free_dirent_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readlink : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_readlink (value gv, value pathv);

value
guestfs_int_ocaml_readlink (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("readlink");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_readlink (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "readlink");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readlinklist : t -> string -> string array -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_readlinklist (value gv, value pathv, value namesv);

value
guestfs_int_ocaml_readlinklist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("readlinklist");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char **names = guestfs_int_ocaml_strings_val (g, namesv);
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_readlinklist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  guestfs_int_free_string_list (names);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "readlinklist");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val realpath : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_realpath (value gv, value pathv);

value
guestfs_int_ocaml_realpath (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("realpath");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_realpath (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "realpath");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val remount : t -> ?rw:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_remount (value gv, value rwv, value mountpointv);

value
guestfs_int_ocaml_remount (value gv, value rwv, value mountpointv)
{
  CAMLparam3 (gv, rwv, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("remount");

  char *mountpoint;
  mountpoint = strdup (String_val (mountpointv));
  if (mountpoint == NULL) caml_raise_out_of_memory ();
  struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
  struct guestfs_remount_argv *optargs = &optargs_s;
  if (rwv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
    optargs_s.rw = Bool_val (Field (rwv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_remount_argv (g, mountpoint, optargs);
  caml_leave_blocking_section ();
  free (mountpoint);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "remount");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val remove_drive : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_remove_drive (value gv, value labelv);

value
guestfs_int_ocaml_remove_drive (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("remove_drive");

  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_remove_drive (g, label);
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "remove_drive");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val removexattr : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_removexattr (value gv, value xattrv, value pathv);

value
guestfs_int_ocaml_removexattr (value gv, value xattrv, value pathv)
{
  CAMLparam3 (gv, xattrv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("removexattr");

  char *xattr;
  xattr = strdup (String_val (xattrv));
  if (xattr == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_removexattr (g, xattr, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "removexattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rename : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rename (value gv, value oldpathv, value newpathv);

value
guestfs_int_ocaml_rename (value gv, value oldpathv, value newpathv)
{
  CAMLparam3 (gv, oldpathv, newpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rename");

  char *oldpath;
  oldpath = strdup (String_val (oldpathv));
  if (oldpath == NULL) caml_raise_out_of_memory ();
  char *newpath;
  newpath = strdup (String_val (newpathv));
  if (newpath == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rename (g, oldpath, newpath);
  caml_leave_blocking_section ();
  free (oldpath);
  free (newpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rename");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_resize2fs (value gv, value devicev);

value
guestfs_int_ocaml_resize2fs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("resize2fs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "resize2fs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs_M : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_resize2fs_M (value gv, value devicev);

value
guestfs_int_ocaml_resize2fs_M (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("resize2fs_M");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs_M (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "resize2fs_M");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_resize2fs_size (value gv, value devicev, value sizev);

value
guestfs_int_ocaml_resize2fs_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("resize2fs_size");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "resize2fs_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rm : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rm (value gv, value pathv);

value
guestfs_int_ocaml_rm (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rm");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rm (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rm");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rm_f : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rm_f (value gv, value pathv);

value
guestfs_int_ocaml_rm_f (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rm_f");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rm_f (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rm_f");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rm_rf : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rm_rf (value gv, value pathv);

value
guestfs_int_ocaml_rm_rf (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rm_rf");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rm_rf (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rm_rf");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rmdir : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rmdir (value gv, value pathv);

value
guestfs_int_ocaml_rmdir (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rmdir");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rmdir (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rmdir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rmmountpoint : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rmmountpoint (value gv, value exemptpathv);

value
guestfs_int_ocaml_rmmountpoint (value gv, value exemptpathv)
{
  CAMLparam2 (gv, exemptpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rmmountpoint");

  char *exemptpath;
  exemptpath = strdup (String_val (exemptpathv));
  if (exemptpath == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rmmountpoint (g, exemptpath);
  caml_leave_blocking_section ();
  free (exemptpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rmmountpoint");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rsync : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rsync (value gv, value archivev, value deletedestv, value srcv, value destv);

value
guestfs_int_ocaml_rsync (value gv, value archivev, value deletedestv, value srcv, value destv)
{
  CAMLparam5 (gv, archivev, deletedestv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rsync");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;
  if (archivev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
    optargs_s.archive = Bool_val (Field (archivev, 0));
  }
  if (deletedestv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
    optargs_s.deletedest = Bool_val (Field (deletedestv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rsync_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rsync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rsync_in : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rsync_in (value gv, value archivev, value deletedestv, value remotev, value destv);

value
guestfs_int_ocaml_rsync_in (value gv, value archivev, value deletedestv, value remotev, value destv)
{
  CAMLparam5 (gv, archivev, deletedestv, remotev, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rsync_in");

  char *remote;
  remote = strdup (String_val (remotev));
  if (remote == NULL) caml_raise_out_of_memory ();
  char *dest;
  dest = strdup (String_val (destv));
  if (dest == NULL) caml_raise_out_of_memory ();
  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  if (archivev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
    optargs_s.archive = Bool_val (Field (archivev, 0));
  }
  if (deletedestv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
    optargs_s.deletedest = Bool_val (Field (deletedestv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  caml_leave_blocking_section ();
  free (remote);
  free (dest);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rsync_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rsync_out : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_rsync_out (value gv, value archivev, value deletedestv, value srcv, value remotev);

value
guestfs_int_ocaml_rsync_out (value gv, value archivev, value deletedestv, value srcv, value remotev)
{
  CAMLparam5 (gv, archivev, deletedestv, srcv, remotev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("rsync_out");

  char *src;
  src = strdup (String_val (srcv));
  if (src == NULL) caml_raise_out_of_memory ();
  char *remote;
  remote = strdup (String_val (remotev));
  if (remote == NULL) caml_raise_out_of_memory ();
  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  if (archivev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
    optargs_s.archive = Bool_val (Field (archivev, 0));
  }
  if (deletedestv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
    optargs_s.deletedest = Bool_val (Field (deletedestv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (remote);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "rsync_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_scrub_device (value gv, value devicev);

value
guestfs_int_ocaml_scrub_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("scrub_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "scrub_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_scrub_file (value gv, value filev);

value
guestfs_int_ocaml_scrub_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("scrub_file");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "scrub_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_freespace : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_scrub_freespace (value gv, value dirv);

value
guestfs_int_ocaml_scrub_freespace (value gv, value dirv)
{
  CAMLparam2 (gv, dirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("scrub_freespace");

  char *dir;
  dir = strdup (String_val (dirv));
  if (dir == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_freespace (g, dir);
  caml_leave_blocking_section ();
  free (dir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "scrub_freespace");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val selinux_relabel : t -> ?force:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_selinux_relabel (value gv, value forcev, value specfilev, value pathv);

value
guestfs_int_ocaml_selinux_relabel (value gv, value forcev, value specfilev, value pathv)
{
  CAMLparam4 (gv, forcev, specfilev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("selinux_relabel");

  char *specfile;
  specfile = strdup (String_val (specfilev));
  if (specfile == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_selinux_relabel_argv optargs_s = { .bitmask = 0 };
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  if (forcev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_SELINUX_RELABEL_FORCE_BITMASK;
    optargs_s.force = Bool_val (Field (forcev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);
  caml_leave_blocking_section ();
  free (specfile);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "selinux_relabel");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_append : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_append (value gv, value appendv);

value
guestfs_int_ocaml_set_append (value gv, value appendv)
{
  CAMLparam2 (gv, appendv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_append");

  char *append;
  if (appendv == Val_int (0))
    append = NULL;
  else {
    append = strdup (String_val (Field (appendv, 0)));
    if (append == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_set_append (g, append);
  free (append);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_append");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_attach_method : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_attach_method (value gv, value backendv);

value
guestfs_int_ocaml_set_attach_method (value gv, value backendv)
{
  CAMLparam2 (gv, backendv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_attach_method");

  char *backend;
  backend = strdup (String_val (backendv));
  if (backend == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_attach_method (g, backend);
  free (backend);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_attach_method");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_autosync : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_autosync (value gv, value autosyncv);

value
guestfs_int_ocaml_set_autosync (value gv, value autosyncv)
{
  CAMLparam2 (gv, autosyncv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_autosync");

  int autosync = Bool_val (autosyncv);
  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_autosync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_backend : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_backend (value gv, value backendv);

value
guestfs_int_ocaml_set_backend (value gv, value backendv)
{
  CAMLparam2 (gv, backendv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_backend");

  char *backend;
  backend = strdup (String_val (backendv));
  if (backend == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_backend (g, backend);
  free (backend);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_backend");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_backend_setting : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_backend_setting (value gv, value namev, value valv);

value
guestfs_int_ocaml_set_backend_setting (value gv, value namev, value valv)
{
  CAMLparam3 (gv, namev, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_backend_setting");

  char *name;
  name = strdup (String_val (namev));
  if (name == NULL) caml_raise_out_of_memory ();
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_backend_setting (g, name, val);
  free (name);
  free (val);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_backend_setting");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_backend_settings : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_backend_settings (value gv, value settingsv);

value
guestfs_int_ocaml_set_backend_settings (value gv, value settingsv)
{
  CAMLparam2 (gv, settingsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_backend_settings");

  char **settings = guestfs_int_ocaml_strings_val (g, settingsv);
  int r;

  r = guestfs_set_backend_settings (g, settings);
  guestfs_int_free_string_list (settings);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_backend_settings");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_cachedir : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_cachedir (value gv, value cachedirv);

value
guestfs_int_ocaml_set_cachedir (value gv, value cachedirv)
{
  CAMLparam2 (gv, cachedirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_cachedir");

  char *cachedir;
  if (cachedirv == Val_int (0))
    cachedir = NULL;
  else {
    cachedir = strdup (String_val (Field (cachedirv, 0)));
    if (cachedir == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_set_cachedir (g, cachedir);
  free (cachedir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_cachedir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_direct : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_direct (value gv, value directv);

value
guestfs_int_ocaml_set_direct (value gv, value directv)
{
  CAMLparam2 (gv, directv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_direct");

  int direct = Bool_val (directv);
  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_direct");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2attrs : t -> ?clear:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_e2attrs (value gv, value clearv, value filev, value attrsv);

value
guestfs_int_ocaml_set_e2attrs (value gv, value clearv, value filev, value attrsv)
{
  CAMLparam4 (gv, clearv, filev, attrsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_e2attrs");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  char *attrs;
  attrs = strdup (String_val (attrsv));
  if (attrs == NULL) caml_raise_out_of_memory ();
  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  if (clearv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
    optargs_s.clear = Bool_val (Field (clearv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
  caml_leave_blocking_section ();
  free (file);
  free (attrs);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_e2attrs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2generation : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_e2generation (value gv, value filev, value generationv);

value
guestfs_int_ocaml_set_e2generation (value gv, value filev, value generationv)
{
  CAMLparam3 (gv, filev, generationv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_e2generation");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int64_t generation = Int64_val (generationv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2generation (g, file, generation);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_e2generation");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2label : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_e2label (value gv, value devicev, value labelv);

value
guestfs_int_ocaml_set_e2label (value gv, value devicev, value labelv)
{
  CAMLparam3 (gv, devicev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_e2label");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2label (g, device, label);
  caml_leave_blocking_section ();
  free (device);
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_e2label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2uuid : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_e2uuid (value gv, value devicev, value uuidv);

value
guestfs_int_ocaml_set_e2uuid (value gv, value devicev, value uuidv)
{
  CAMLparam3 (gv, devicev, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_e2uuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2uuid (g, device, uuid);
  caml_leave_blocking_section ();
  free (device);
  free (uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_e2uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_hv : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_hv (value gv, value hvv);

value
guestfs_int_ocaml_set_hv (value gv, value hvv)
{
  CAMLparam2 (gv, hvv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_hv");

  char *hv;
  hv = strdup (String_val (hvv));
  if (hv == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_hv (g, hv);
  free (hv);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_hv");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_identifier : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_identifier (value gv, value identifierv);

value
guestfs_int_ocaml_set_identifier (value gv, value identifierv)
{
  CAMLparam2 (gv, identifierv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_identifier");

  char *identifier;
  identifier = strdup (String_val (identifierv));
  if (identifier == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_identifier (g, identifier);
  free (identifier);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_identifier");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_label : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_label (value gv, value mountablev, value labelv);

value
guestfs_int_ocaml_set_label (value gv, value mountablev, value labelv)
{
  CAMLparam3 (gv, mountablev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_label");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_label (g, mountable, label);
  caml_leave_blocking_section ();
  free (mountable);
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_libvirt_requested_credential : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_libvirt_requested_credential (value gv, value indexv, value credv);

value
guestfs_int_ocaml_set_libvirt_requested_credential (value gv, value indexv, value credv)
{
  CAMLparam3 (gv, indexv, credv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_libvirt_requested_credential");

  int index = Int_val (indexv);
  size_t cred_size = caml_string_length (credv);
  char *cred;
  cred = malloc (cred_size);
  if (cred == NULL) caml_raise_out_of_memory ();
  memcpy (cred, String_val (credv), cred_size);
  int r;

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  free (cred);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_libvirt_requested_credential");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_libvirt_supported_credentials : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_libvirt_supported_credentials (value gv, value credsv);

value
guestfs_int_ocaml_set_libvirt_supported_credentials (value gv, value credsv)
{
  CAMLparam2 (gv, credsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_libvirt_supported_credentials");

  char **creds = guestfs_int_ocaml_strings_val (g, credsv);
  int r;

  r = guestfs_set_libvirt_supported_credentials (g, creds);
  guestfs_int_free_string_list (creds);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_libvirt_supported_credentials");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_memsize : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_memsize (value gv, value memsizev);

value
guestfs_int_ocaml_set_memsize (value gv, value memsizev)
{
  CAMLparam2 (gv, memsizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_memsize");

  int memsize = Int_val (memsizev);
  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_memsize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_network : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_network (value gv, value networkv);

value
guestfs_int_ocaml_set_network (value gv, value networkv)
{
  CAMLparam2 (gv, networkv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_network");

  int network = Bool_val (networkv);
  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_network");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_path : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_path (value gv, value searchpathv);

value
guestfs_int_ocaml_set_path (value gv, value searchpathv)
{
  CAMLparam2 (gv, searchpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_path");

  char *searchpath;
  if (searchpathv == Val_int (0))
    searchpath = NULL;
  else {
    searchpath = strdup (String_val (Field (searchpathv, 0)));
    if (searchpath == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_set_path (g, searchpath);
  free (searchpath);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_path");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_pgroup : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_pgroup (value gv, value pgroupv);

value
guestfs_int_ocaml_set_pgroup (value gv, value pgroupv)
{
  CAMLparam2 (gv, pgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_pgroup");

  int pgroup = Bool_val (pgroupv);
  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_pgroup");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_program : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_program (value gv, value programv);

value
guestfs_int_ocaml_set_program (value gv, value programv)
{
  CAMLparam2 (gv, programv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_program");

  char *program;
  program = strdup (String_val (programv));
  if (program == NULL) caml_raise_out_of_memory ();
  int r;

  r = guestfs_set_program (g, program);
  free (program);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_program");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_qemu : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_qemu (value gv, value hvv);

value
guestfs_int_ocaml_set_qemu (value gv, value hvv)
{
  CAMLparam2 (gv, hvv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_qemu");

  char *hv;
  if (hvv == Val_int (0))
    hv = NULL;
  else {
    hv = strdup (String_val (Field (hvv, 0)));
    if (hv == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_set_qemu (g, hv);
  free (hv);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_qemu");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_recovery_proc : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_recovery_proc (value gv, value recoveryprocv);

value
guestfs_int_ocaml_set_recovery_proc (value gv, value recoveryprocv)
{
  CAMLparam2 (gv, recoveryprocv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_recovery_proc");

  int recoveryproc = Bool_val (recoveryprocv);
  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_recovery_proc");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_selinux : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_selinux (value gv, value selinuxv);

value
guestfs_int_ocaml_set_selinux (value gv, value selinuxv)
{
  CAMLparam2 (gv, selinuxv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_selinux");

  int selinux = Bool_val (selinuxv);
  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_selinux");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_smp : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_smp (value gv, value smpv);

value
guestfs_int_ocaml_set_smp (value gv, value smpv)
{
  CAMLparam2 (gv, smpv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_smp");

  int smp = Int_val (smpv);
  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_smp");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_tmpdir : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_tmpdir (value gv, value tmpdirv);

value
guestfs_int_ocaml_set_tmpdir (value gv, value tmpdirv)
{
  CAMLparam2 (gv, tmpdirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_tmpdir");

  char *tmpdir;
  if (tmpdirv == Val_int (0))
    tmpdir = NULL;
  else {
    tmpdir = strdup (String_val (Field (tmpdirv, 0)));
    if (tmpdir == NULL) caml_raise_out_of_memory ();
  }
  int r;

  r = guestfs_set_tmpdir (g, tmpdir);
  free (tmpdir);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_tmpdir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_trace : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_trace (value gv, value tracev);

value
guestfs_int_ocaml_set_trace (value gv, value tracev)
{
  CAMLparam2 (gv, tracev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_trace");

  int trace = Bool_val (tracev);
  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_trace");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_uuid : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_uuid (value gv, value devicev, value uuidv);

value
guestfs_int_ocaml_set_uuid (value gv, value devicev, value uuidv)
{
  CAMLparam3 (gv, devicev, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_uuid");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_uuid (g, device, uuid);
  caml_leave_blocking_section ();
  free (device);
  free (uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_uuid_random : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_uuid_random (value gv, value devicev);

value
guestfs_int_ocaml_set_uuid_random (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_uuid_random");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_uuid_random (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_uuid_random");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_verbose : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_set_verbose (value gv, value verbosev);

value
guestfs_int_ocaml_set_verbose (value gv, value verbosev)
{
  CAMLparam2 (gv, verbosev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("set_verbose");

  int verbose = Bool_val (verbosev);
  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "set_verbose");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val setcon : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_setcon (value gv, value contextv);

value
guestfs_int_ocaml_setcon (value gv, value contextv)
{
  CAMLparam2 (gv, contextv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("setcon");

  char *context;
  context = strdup (String_val (contextv));
  if (context == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_setcon (g, context);
  caml_leave_blocking_section ();
  free (context);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "setcon");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val setxattr : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_setxattr (value gv, value xattrv, value valv, value vallenv, value pathv);

value
guestfs_int_ocaml_setxattr (value gv, value xattrv, value valv, value vallenv, value pathv)
{
  CAMLparam5 (gv, xattrv, valv, vallenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("setxattr");

  char *xattr;
  xattr = strdup (String_val (xattrv));
  if (xattr == NULL) caml_raise_out_of_memory ();
  char *val;
  val = strdup (String_val (valv));
  if (val == NULL) caml_raise_out_of_memory ();
  int vallen = Int_val (vallenv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_setxattr (g, xattr, val, vallen, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "setxattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk : t -> string -> int -> int -> int -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk (value gv, value devicev, value cylsv, value headsv, value sectorsv, value linesv);

value
guestfs_int_ocaml_sfdisk (value gv, value devicev, value cylsv, value headsv, value sectorsv, value linesv)
{
  CAMLparam5 (gv, devicev, cylsv, headsv, sectorsv);
  CAMLxparam1 (linesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdisk");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int cyls = Int_val (cylsv);
  int heads = Int_val (headsv);
  int sectors = Int_val (sectorsv);
  char **lines = guestfs_int_ocaml_strings_val (g, linesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  caml_leave_blocking_section ();
  free (device);
  guestfs_int_free_string_list (lines);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "sfdisk");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_byte (value *argv, int argn);

value
guestfs_int_ocaml_sfdisk_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_sfdisk (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val sfdiskM : t -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdiskM (value gv, value devicev, value linesv);

value
guestfs_int_ocaml_sfdiskM (value gv, value devicev, value linesv)
{
  CAMLparam3 (gv, devicev, linesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdiskM");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char **lines = guestfs_int_ocaml_strings_val (g, linesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdiskM (g, device, lines);
  caml_leave_blocking_section ();
  free (device);
  guestfs_int_free_string_list (lines);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "sfdiskM");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_N (value gv, value devicev, value partnumv, value cylsv, value headsv, value sectorsv, value linev);

value
guestfs_int_ocaml_sfdisk_N (value gv, value devicev, value partnumv, value cylsv, value headsv, value sectorsv, value linev)
{
  CAMLparam5 (gv, devicev, partnumv, cylsv, headsv);
  CAMLxparam2 (sectorsv, linev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdisk_N");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int partnum = Int_val (partnumv);
  int cyls = Int_val (cylsv);
  int heads = Int_val (headsv);
  int sectors = Int_val (sectorsv);
  char *line;
  line = strdup (String_val (linev));
  if (line == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  caml_leave_blocking_section ();
  free (device);
  free (line);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "sfdisk_N");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_N_byte (value *argv, int argn);

value
guestfs_int_ocaml_sfdisk_N_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_sfdisk_N (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val sfdisk_disk_geometry : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_disk_geometry (value gv, value devicev);

value
guestfs_int_ocaml_sfdisk_disk_geometry (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdisk_disk_geometry");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_disk_geometry (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "sfdisk_disk_geometry");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_kernel_geometry : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_kernel_geometry (value gv, value devicev);

value
guestfs_int_ocaml_sfdisk_kernel_geometry (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdisk_kernel_geometry");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_kernel_geometry (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "sfdisk_kernel_geometry");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_l : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sfdisk_l (value gv, value devicev);

value
guestfs_int_ocaml_sfdisk_l (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sfdisk_l");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_l (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "sfdisk_l");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sh : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sh (value gv, value commandv);

value
guestfs_int_ocaml_sh (value gv, value commandv)
{
  CAMLparam2 (gv, commandv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sh");

  char *command;
  command = strdup (String_val (commandv));
  if (command == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sh (g, command);
  caml_leave_blocking_section ();
  free (command);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "sh");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sh_lines : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sh_lines (value gv, value commandv);

value
guestfs_int_ocaml_sh_lines (value gv, value commandv)
{
  CAMLparam2 (gv, commandv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sh_lines");

  char *command;
  command = strdup (String_val (commandv));
  if (command == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_sh_lines (g, command);
  caml_leave_blocking_section ();
  free (command);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "sh_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val shutdown : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_shutdown (value gv);

value
guestfs_int_ocaml_shutdown (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("shutdown");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_shutdown (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "shutdown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sleep : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sleep (value gv, value secsv);

value
guestfs_int_ocaml_sleep (value gv, value secsv)
{
  CAMLparam2 (gv, secsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sleep");

  int secs = Int_val (secsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sleep (g, secs);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "sleep");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val stat : t -> string -> stat
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_stat (value gv, value pathv);

value
guestfs_int_ocaml_stat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("stat");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_stat *r;

  caml_enter_blocking_section ();
  r = guestfs_stat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "stat");

  rv = copy_stat (r);
  guestfs_free_stat (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val statns : t -> string -> statns
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_statns (value gv, value pathv);

value
guestfs_int_ocaml_statns (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("statns");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_statns *r;

  caml_enter_blocking_section ();
  r = guestfs_statns (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "statns");

  rv = copy_statns (r);
  guestfs_free_statns (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val statvfs : t -> string -> statvfs
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_statvfs (value gv, value pathv);

value
guestfs_int_ocaml_statvfs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("statvfs");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_statvfs *r;

  caml_enter_blocking_section ();
  r = guestfs_statvfs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "statvfs");

  rv = copy_statvfs (r);
  guestfs_free_statvfs (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val strings : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_strings (value gv, value pathv);

value
guestfs_int_ocaml_strings (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("strings");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_strings (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "strings");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val strings_e : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_strings_e (value gv, value encodingv, value pathv);

value
guestfs_int_ocaml_strings_e (value gv, value encodingv, value pathv)
{
  CAMLparam3 (gv, encodingv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("strings_e");

  char *encoding;
  encoding = strdup (String_val (encodingv));
  if (encoding == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_strings_e (g, encoding, path);
  caml_leave_blocking_section ();
  free (encoding);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "strings_e");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapoff_device (value gv, value devicev);

value
guestfs_int_ocaml_swapoff_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapoff_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapoff_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapoff_file (value gv, value filev);

value
guestfs_int_ocaml_swapoff_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapoff_file");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapoff_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_label : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapoff_label (value gv, value labelv);

value
guestfs_int_ocaml_swapoff_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapoff_label");

  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapoff_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapoff_uuid (value gv, value uuidv);

value
guestfs_int_ocaml_swapoff_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapoff_uuid");

  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapoff_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapon_device (value gv, value devicev);

value
guestfs_int_ocaml_swapon_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapon_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapon_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapon_file (value gv, value filev);

value
guestfs_int_ocaml_swapon_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapon_file");

  char *file;
  file = strdup (String_val (filev));
  if (file == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapon_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_label : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapon_label (value gv, value labelv);

value
guestfs_int_ocaml_swapon_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapon_label");

  char *label;
  label = strdup (String_val (labelv));
  if (label == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapon_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_swapon_uuid (value gv, value uuidv);

value
guestfs_int_ocaml_swapon_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("swapon_uuid");

  char *uuid;
  uuid = strdup (String_val (uuidv));
  if (uuid == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "swapon_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sync : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_sync (value gv);

value
guestfs_int_ocaml_sync (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("sync");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_sync (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "sync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val syslinux : t -> ?directory:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_syslinux (value gv, value directoryv, value devicev);

value
guestfs_int_ocaml_syslinux (value gv, value directoryv, value devicev)
{
  CAMLparam3 (gv, directoryv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("syslinux");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  if (directoryv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
    optargs_s.directory = strdup (String_val (Field (directoryv, 0)));
    if (optargs_s.directory == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_syslinux_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (directoryv != Val_int (0))
    free ((char *) optargs_s.directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "syslinux");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tail : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tail (value gv, value pathv);

value
guestfs_int_ocaml_tail (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tail");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tail (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "tail");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tail_n : t -> int -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tail_n (value gv, value nrlinesv, value pathv);

value
guestfs_int_ocaml_tail_n (value gv, value nrlinesv, value pathv)
{
  CAMLparam3 (gv, nrlinesv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tail_n");

  int nrlines = Int_val (nrlinesv);
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tail_n (g, nrlines, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "tail_n");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tar_in : t -> ?compress:string -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tar_in (value gv, value compressv, value xattrsv, value selinuxv, value aclsv, value tarfilev, value directoryv);

value
guestfs_int_ocaml_tar_in (value gv, value compressv, value xattrsv, value selinuxv, value aclsv, value tarfilev, value directoryv)
{
  CAMLparam5 (gv, compressv, xattrsv, selinuxv, aclsv);
  CAMLxparam2 (tarfilev, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tar_in");

  char *tarfile;
  tarfile = strdup (String_val (tarfilev));
  if (tarfile == NULL) caml_raise_out_of_memory ();
  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  if (compressv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
    optargs_s.compress = strdup (String_val (Field (compressv, 0)));
    if (optargs_s.compress == NULL) caml_raise_out_of_memory ();
  }
  if (xattrsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK;
    optargs_s.xattrs = Bool_val (Field (xattrsv, 0));
  }
  if (selinuxv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK;
    optargs_s.selinux = Bool_val (Field (selinuxv, 0));
  }
  if (aclsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_ACLS_BITMASK;
    optargs_s.acls = Bool_val (Field (aclsv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  caml_leave_blocking_section ();
  free (tarfile);
  free (directory);
  if (compressv != Val_int (0))
    free ((char *) optargs_s.compress);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "tar_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tar_in_byte (value *argv, int argn);

value
guestfs_int_ocaml_tar_in_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_tar_in (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val tar_out : t -> ?compress:string -> ?numericowner:bool -> ?excludes:string array -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tar_out (value gv, value compressv, value numericownerv, value excludesv, value xattrsv, value selinuxv, value aclsv, value directoryv, value tarfilev);

value
guestfs_int_ocaml_tar_out (value gv, value compressv, value numericownerv, value excludesv, value xattrsv, value selinuxv, value aclsv, value directoryv, value tarfilev)
{
  CAMLparam5 (gv, compressv, numericownerv, excludesv, xattrsv);
  CAMLxparam4 (selinuxv, aclsv, directoryv, tarfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tar_out");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *tarfile;
  tarfile = strdup (String_val (tarfilev));
  if (tarfile == NULL) caml_raise_out_of_memory ();
  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  if (compressv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
    optargs_s.compress = strdup (String_val (Field (compressv, 0)));
    if (optargs_s.compress == NULL) caml_raise_out_of_memory ();
  }
  if (numericownerv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
    optargs_s.numericowner = Bool_val (Field (numericownerv, 0));
  }
  if (excludesv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
    optargs_s.excludes = guestfs_int_ocaml_strings_val (g, Field (excludesv, 0));
  }
  if (xattrsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK;
    optargs_s.xattrs = Bool_val (Field (xattrsv, 0));
  }
  if (selinuxv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK;
    optargs_s.selinux = Bool_val (Field (selinuxv, 0));
  }
  if (aclsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK;
    optargs_s.acls = Bool_val (Field (aclsv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  caml_leave_blocking_section ();
  free (directory);
  free (tarfile);
  if (compressv != Val_int (0))
    free ((char *) optargs_s.compress);
  if (excludesv != Val_int (0))
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "tar_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tar_out_byte (value *argv, int argn);

value
guestfs_int_ocaml_tar_out_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_tar_out (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

/* Automatically generated wrapper for function
 * val tgz_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tgz_in (value gv, value tarballv, value directoryv);

value
guestfs_int_ocaml_tgz_in (value gv, value tarballv, value directoryv)
{
  CAMLparam3 (gv, tarballv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tgz_in");

  char *tarball;
  tarball = strdup (String_val (tarballv));
  if (tarball == NULL) caml_raise_out_of_memory ();
  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tgz_in (g, tarball, directory);
  caml_leave_blocking_section ();
  free (tarball);
  free (directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "tgz_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tgz_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tgz_out (value gv, value directoryv, value tarballv);

value
guestfs_int_ocaml_tgz_out (value gv, value directoryv, value tarballv)
{
  CAMLparam3 (gv, directoryv, tarballv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tgz_out");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *tarball;
  tarball = strdup (String_val (tarballv));
  if (tarball == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tgz_out (g, directory, tarball);
  caml_leave_blocking_section ();
  free (directory);
  free (tarball);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "tgz_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val touch : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_touch (value gv, value pathv);

value
guestfs_int_ocaml_touch (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("touch");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_touch (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "touch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val truncate : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_truncate (value gv, value pathv);

value
guestfs_int_ocaml_truncate (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("truncate");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_truncate (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "truncate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val truncate_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_truncate_size (value gv, value pathv, value sizev);

value
guestfs_int_ocaml_truncate_size (value gv, value pathv, value sizev)
{
  CAMLparam3 (gv, pathv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("truncate_size");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_truncate_size (g, path, size);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "truncate_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tune2fs : t -> ?force:bool -> ?maxmountcount:int -> ?mountcount:int -> ?errorbehavior:string -> ?group:int64 -> ?intervalbetweenchecks:int -> ?reservedblockspercentage:int -> ?lastmounteddirectory:string -> ?reservedblockscount:int64 -> ?user:int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tune2fs (value gv, value forcev, value maxmountcountv, value mountcountv, value errorbehaviorv, value groupv, value intervalbetweenchecksv, value reservedblockspercentagev, value lastmounteddirectoryv, value reservedblockscountv, value userv, value devicev);

value
guestfs_int_ocaml_tune2fs (value gv, value forcev, value maxmountcountv, value mountcountv, value errorbehaviorv, value groupv, value intervalbetweenchecksv, value reservedblockspercentagev, value lastmounteddirectoryv, value reservedblockscountv, value userv, value devicev)
{
  CAMLparam5 (gv, forcev, maxmountcountv, mountcountv, errorbehaviorv);
  CAMLxparam5 (groupv, intervalbetweenchecksv, reservedblockspercentagev, lastmounteddirectoryv, reservedblockscountv);
  CAMLxparam2 (userv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tune2fs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  if (forcev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
    optargs_s.force = Bool_val (Field (forcev, 0));
  }
  if (maxmountcountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
    optargs_s.maxmountcount = Int_val (Field (maxmountcountv, 0));
  }
  if (mountcountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
    optargs_s.mountcount = Int_val (Field (mountcountv, 0));
  }
  if (errorbehaviorv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
    optargs_s.errorbehavior = strdup (String_val (Field (errorbehaviorv, 0)));
    if (optargs_s.errorbehavior == NULL) caml_raise_out_of_memory ();
  }
  if (groupv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
    optargs_s.group = Int64_val (Field (groupv, 0));
  }
  if (intervalbetweenchecksv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
    optargs_s.intervalbetweenchecks = Int_val (Field (intervalbetweenchecksv, 0));
  }
  if (reservedblockspercentagev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = Int_val (Field (reservedblockspercentagev, 0));
  }
  if (lastmounteddirectoryv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
    optargs_s.lastmounteddirectory = strdup (String_val (Field (lastmounteddirectoryv, 0)));
    if (optargs_s.lastmounteddirectory == NULL) caml_raise_out_of_memory ();
  }
  if (reservedblockscountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
    optargs_s.reservedblockscount = Int64_val (Field (reservedblockscountv, 0));
  }
  if (userv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
    optargs_s.user = Int64_val (Field (userv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tune2fs_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (errorbehaviorv != Val_int (0))
    free ((char *) optargs_s.errorbehavior);
  if (lastmounteddirectoryv != Val_int (0))
    free ((char *) optargs_s.lastmounteddirectory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "tune2fs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tune2fs_byte (value *argv, int argn);

value
guestfs_int_ocaml_tune2fs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_tune2fs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}

/* Automatically generated wrapper for function
 * val tune2fs_l : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_tune2fs_l (value gv, value devicev);

value
guestfs_int_ocaml_tune2fs_l (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("tune2fs_l");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tune2fs_l (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "tune2fs_l");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val txz_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_txz_in (value gv, value tarballv, value directoryv);

value
guestfs_int_ocaml_txz_in (value gv, value tarballv, value directoryv)
{
  CAMLparam3 (gv, tarballv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("txz_in");

  char *tarball;
  tarball = strdup (String_val (tarballv));
  if (tarball == NULL) caml_raise_out_of_memory ();
  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_txz_in (g, tarball, directory);
  caml_leave_blocking_section ();
  free (tarball);
  free (directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "txz_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val txz_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_txz_out (value gv, value directoryv, value tarballv);

value
guestfs_int_ocaml_txz_out (value gv, value directoryv, value tarballv)
{
  CAMLparam3 (gv, directoryv, tarballv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("txz_out");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  char *tarball;
  tarball = strdup (String_val (tarballv));
  if (tarball == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_txz_out (g, directory, tarball);
  caml_leave_blocking_section ();
  free (directory);
  free (tarball);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "txz_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umask : t -> int -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_umask (value gv, value maskv);

value
guestfs_int_ocaml_umask (value gv, value maskv)
{
  CAMLparam2 (gv, maskv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("umask");

  int mask = Int_val (maskv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_umask (g, mask);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "umask");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount : t -> ?force:bool -> ?lazyunmount:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_umount (value gv, value forcev, value lazyunmountv, value pathordevicev);

value
guestfs_int_ocaml_umount (value gv, value forcev, value lazyunmountv, value pathordevicev)
{
  CAMLparam4 (gv, forcev, lazyunmountv, pathordevicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("umount");

  char *pathordevice;
  pathordevice = strdup (String_val (pathordevicev));
  if (pathordevice == NULL) caml_raise_out_of_memory ();
  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  if (forcev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
    optargs_s.force = Bool_val (Field (forcev, 0));
  }
  if (lazyunmountv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
    optargs_s.lazyunmount = Bool_val (Field (lazyunmountv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  caml_leave_blocking_section ();
  free (pathordevice);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "umount");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_umount_all (value gv);

value
guestfs_int_ocaml_umount_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("umount_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_umount_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "umount_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount_local : t -> ?retry:bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_umount_local (value gv, value retryv);

value
guestfs_int_ocaml_umount_local (value gv, value retryv)
{
  CAMLparam2 (gv, retryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("umount_local");

  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  if (retryv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
    optargs_s.retry = Bool_val (Field (retryv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_umount_local_argv (g, optargs);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "umount_local");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val upload : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_upload (value gv, value filenamev, value remotefilenamev);

value
guestfs_int_ocaml_upload (value gv, value filenamev, value remotefilenamev)
{
  CAMLparam3 (gv, filenamev, remotefilenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("upload");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *remotefilename;
  remotefilename = strdup (String_val (remotefilenamev));
  if (remotefilename == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_upload (g, filename, remotefilename);
  caml_leave_blocking_section ();
  free (filename);
  free (remotefilename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "upload");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val upload_offset : t -> string -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_upload_offset (value gv, value filenamev, value remotefilenamev, value offsetv);

value
guestfs_int_ocaml_upload_offset (value gv, value filenamev, value remotefilenamev, value offsetv)
{
  CAMLparam4 (gv, filenamev, remotefilenamev, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("upload_offset");

  char *filename;
  filename = strdup (String_val (filenamev));
  if (filename == NULL) caml_raise_out_of_memory ();
  char *remotefilename;
  remotefilename = strdup (String_val (remotefilenamev));
  if (remotefilename == NULL) caml_raise_out_of_memory ();
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  caml_leave_blocking_section ();
  free (filename);
  free (remotefilename);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "upload_offset");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val user_cancel : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_user_cancel (value gv);

value
guestfs_int_ocaml_user_cancel (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("user_cancel");

  int r;

  r = guestfs_user_cancel (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "user_cancel");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_utimens (value gv, value pathv, value atsecsv, value atnsecsv, value mtsecsv, value mtnsecsv);

value
guestfs_int_ocaml_utimens (value gv, value pathv, value atsecsv, value atnsecsv, value mtsecsv, value mtnsecsv)
{
  CAMLparam5 (gv, pathv, atsecsv, atnsecsv, mtsecsv);
  CAMLxparam1 (mtnsecsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("utimens");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int64_t atsecs = Int64_val (atsecsv);
  int64_t atnsecs = Int64_val (atnsecsv);
  int64_t mtsecs = Int64_val (mtsecsv);
  int64_t mtnsecs = Int64_val (mtnsecsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "utimens");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_utimens_byte (value *argv, int argn);

value
guestfs_int_ocaml_utimens_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_utimens (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val utsname : t -> utsname
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_utsname (value gv);

value
guestfs_int_ocaml_utsname (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("utsname");

  struct guestfs_utsname *r;

  caml_enter_blocking_section ();
  r = guestfs_utsname (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "utsname");

  rv = copy_utsname (r);
  guestfs_free_utsname (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val version : t -> version
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_version (value gv);

value
guestfs_int_ocaml_version (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("version");

  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "version");

  rv = copy_version (r);
  guestfs_free_version (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vfs_label (value gv, value mountablev);

value
guestfs_int_ocaml_vfs_label (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vfs_label");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_label (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vfs_label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_minimum_size : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vfs_minimum_size (value gv, value mountablev);

value
guestfs_int_ocaml_vfs_minimum_size (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vfs_minimum_size");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_minimum_size (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vfs_minimum_size");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_type : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vfs_type (value gv, value mountablev);

value
guestfs_int_ocaml_vfs_type (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vfs_type");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_type (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vfs_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vfs_uuid (value gv, value mountablev);

value
guestfs_int_ocaml_vfs_uuid (value gv, value mountablev)
{
  CAMLparam2 (gv, mountablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vfs_uuid");

  char *mountable;
  mountable = strdup (String_val (mountablev));
  if (mountable == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_uuid (g, mountable);
  caml_leave_blocking_section ();
  free (mountable);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vfs_uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vg_activate : t -> bool -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vg_activate (value gv, value activatev, value volgroupsv);

value
guestfs_int_ocaml_vg_activate (value gv, value activatev, value volgroupsv)
{
  CAMLparam3 (gv, activatev, volgroupsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vg_activate");

  int activate = Bool_val (activatev);
  char **volgroups = guestfs_int_ocaml_strings_val (g, volgroupsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vg_activate (g, activate, volgroups);
  caml_leave_blocking_section ();
  guestfs_int_free_string_list (volgroups);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vg_activate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vg_activate_all : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vg_activate_all (value gv, value activatev);

value
guestfs_int_ocaml_vg_activate_all (value gv, value activatev)
{
  CAMLparam2 (gv, activatev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vg_activate_all");

  int activate = Bool_val (activatev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vg_activate_all (g, activate);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vg_activate_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgchange_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgchange_uuid (value gv, value vgv);

value
guestfs_int_ocaml_vgchange_uuid (value gv, value vgv)
{
  CAMLparam2 (gv, vgv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgchange_uuid");

  char *vg;
  vg = strdup (String_val (vgv));
  if (vg == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgchange_uuid (g, vg);
  caml_leave_blocking_section ();
  free (vg);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgchange_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgchange_uuid_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgchange_uuid_all (value gv);

value
guestfs_int_ocaml_vgchange_uuid_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgchange_uuid_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgchange_uuid_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgchange_uuid_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgcreate : t -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgcreate (value gv, value volgroupv, value physvolsv);

value
guestfs_int_ocaml_vgcreate (value gv, value volgroupv, value physvolsv)
{
  CAMLparam3 (gv, volgroupv, physvolsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgcreate");

  char *volgroup;
  volgroup = strdup (String_val (volgroupv));
  if (volgroup == NULL) caml_raise_out_of_memory ();
  char **physvols = guestfs_int_ocaml_strings_val (g, physvolsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgcreate (g, volgroup, physvols);
  caml_leave_blocking_section ();
  free (volgroup);
  guestfs_int_free_string_list (physvols);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vglvuuids : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vglvuuids (value gv, value vgnamev);

value
guestfs_int_ocaml_vglvuuids (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vglvuuids");

  char *vgname;
  vgname = strdup (String_val (vgnamev));
  if (vgname == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vglvuuids (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vglvuuids");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgmeta : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgmeta (value gv, value vgnamev);

value
guestfs_int_ocaml_vgmeta (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgmeta");

  char *vgname;
  vgname = strdup (String_val (vgnamev));
  if (vgname == NULL) caml_raise_out_of_memory ();
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_vgmeta (g, vgname, &size);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vgmeta");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgpvuuids : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgpvuuids (value gv, value vgnamev);

value
guestfs_int_ocaml_vgpvuuids (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgpvuuids");

  char *vgname;
  vgname = strdup (String_val (vgnamev));
  if (vgname == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vgpvuuids (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vgpvuuids");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgremove (value gv, value vgnamev);

value
guestfs_int_ocaml_vgremove (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgremove");

  char *vgname;
  vgname = strdup (String_val (vgnamev));
  if (vgname == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgremove (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgrename : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgrename (value gv, value volgroupv, value newvolgroupv);

value
guestfs_int_ocaml_vgrename (value gv, value volgroupv, value newvolgroupv)
{
  CAMLparam3 (gv, volgroupv, newvolgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgrename");

  char *volgroup;
  volgroup = strdup (String_val (volgroupv));
  if (volgroup == NULL) caml_raise_out_of_memory ();
  char *newvolgroup;
  newvolgroup = strdup (String_val (newvolgroupv));
  if (newvolgroup == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgrename (g, volgroup, newvolgroup);
  caml_leave_blocking_section ();
  free (volgroup);
  free (newvolgroup);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgrename");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgs (value gv);

value
guestfs_int_ocaml_vgs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vgs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vgs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgs_full : t -> lvm_vg array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgs_full (value gv);

value
guestfs_int_ocaml_vgs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgs_full");

  struct guestfs_lvm_vg_list *r;

  caml_enter_blocking_section ();
  r = guestfs_vgs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vgs_full");

  rv = copy_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgscan : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vgscan (value gv);

value
guestfs_int_ocaml_vgscan (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vgscan");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgscan (g);
  caml_leave_blocking_section ();
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "vgscan");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vguuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_vguuid (value gv, value vgnamev);

value
guestfs_int_ocaml_vguuid (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("vguuid");

  char *vgname;
  vgname = strdup (String_val (vgnamev));
  if (vgname == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vguuid (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "vguuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wait_ready : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_wait_ready (value gv);

value
guestfs_int_ocaml_wait_ready (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("wait_ready");

  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "wait_ready");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_c : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_wc_c (value gv, value pathv);

value
guestfs_int_ocaml_wc_c (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("wc_c");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_c (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "wc_c");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_l : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_wc_l (value gv, value pathv);

value
guestfs_int_ocaml_wc_l (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("wc_l");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_l (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "wc_l");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_w : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_wc_w (value gv, value pathv);

value
guestfs_int_ocaml_wc_w (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("wc_w");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_w (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "wc_w");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wipefs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_wipefs (value gv, value devicev);

value
guestfs_int_ocaml_wipefs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("wipefs");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wipefs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "wipefs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_write (value gv, value pathv, value contentv);

value
guestfs_int_ocaml_write (value gv, value pathv, value contentv)
{
  CAMLparam3 (gv, pathv, contentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("write");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t content_size = caml_string_length (contentv);
  char *content;
  content = malloc (content_size);
  if (content == NULL) caml_raise_out_of_memory ();
  memcpy (content, String_val (contentv), content_size);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write (g, path, content, content_size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "write");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write_append : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_write_append (value gv, value pathv, value contentv);

value
guestfs_int_ocaml_write_append (value gv, value pathv, value contentv)
{
  CAMLparam3 (gv, pathv, contentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("write_append");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t content_size = caml_string_length (contentv);
  char *content;
  content = malloc (content_size);
  if (content == NULL) caml_raise_out_of_memory ();
  memcpy (content, String_val (contentv), content_size);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write_append (g, path, content, content_size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "write_append");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write_file : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_write_file (value gv, value pathv, value contentv, value sizev);

value
guestfs_int_ocaml_write_file (value gv, value pathv, value contentv, value sizev)
{
  CAMLparam4 (gv, pathv, contentv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("write_file");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *content;
  content = strdup (String_val (contentv));
  if (content == NULL) caml_raise_out_of_memory ();
  int size = Int_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write_file (g, path, content, size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "write_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val xfs_admin : t -> ?extunwritten:bool -> ?imgfile:bool -> ?v2log:bool -> ?projid32bit:bool -> ?lazycounter:bool -> ?label:string -> ?uuid:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_admin (value gv, value extunwrittenv, value imgfilev, value v2logv, value projid32bitv, value lazycounterv, value labelv, value uuidv, value devicev);

value
guestfs_int_ocaml_xfs_admin (value gv, value extunwrittenv, value imgfilev, value v2logv, value projid32bitv, value lazycounterv, value labelv, value uuidv, value devicev)
{
  CAMLparam5 (gv, extunwrittenv, imgfilev, v2logv, projid32bitv);
  CAMLxparam4 (lazycounterv, labelv, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("xfs_admin");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  if (extunwrittenv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
    optargs_s.extunwritten = Bool_val (Field (extunwrittenv, 0));
  }
  if (imgfilev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
    optargs_s.imgfile = Bool_val (Field (imgfilev, 0));
  }
  if (v2logv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
    optargs_s.v2log = Bool_val (Field (v2logv, 0));
  }
  if (projid32bitv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
    optargs_s.projid32bit = Bool_val (Field (projid32bitv, 0));
  }
  if (lazycounterv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
    optargs_s.lazycounter = Bool_val (Field (lazycounterv, 0));
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
    optargs_s.label = strdup (String_val (Field (labelv, 0)));
    if (optargs_s.label == NULL) caml_raise_out_of_memory ();
  }
  if (uuidv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
    optargs_s.uuid = strdup (String_val (Field (uuidv, 0)));
    if (optargs_s.uuid == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_xfs_admin_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (uuidv != Val_int (0))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "xfs_admin");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_admin_byte (value *argv, int argn);

value
guestfs_int_ocaml_xfs_admin_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_xfs_admin (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

/* Automatically generated wrapper for function
 * val xfs_growfs : t -> ?datasec:bool -> ?logsec:bool -> ?rtsec:bool -> ?datasize:int64 -> ?logsize:int64 -> ?rtsize:int64 -> ?rtextsize:int64 -> ?maxpct:int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_growfs (value gv, value datasecv, value logsecv, value rtsecv, value datasizev, value logsizev, value rtsizev, value rtextsizev, value maxpctv, value pathv);

value
guestfs_int_ocaml_xfs_growfs (value gv, value datasecv, value logsecv, value rtsecv, value datasizev, value logsizev, value rtsizev, value rtextsizev, value maxpctv, value pathv)
{
  CAMLparam5 (gv, datasecv, logsecv, rtsecv, datasizev);
  CAMLxparam5 (logsizev, rtsizev, rtextsizev, maxpctv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("xfs_growfs");

  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  if (datasecv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
    optargs_s.datasec = Bool_val (Field (datasecv, 0));
  }
  if (logsecv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
    optargs_s.logsec = Bool_val (Field (logsecv, 0));
  }
  if (rtsecv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
    optargs_s.rtsec = Bool_val (Field (rtsecv, 0));
  }
  if (datasizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
    optargs_s.datasize = Int64_val (Field (datasizev, 0));
  }
  if (logsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
    optargs_s.logsize = Int64_val (Field (logsizev, 0));
  }
  if (rtsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
    optargs_s.rtsize = Int64_val (Field (rtsizev, 0));
  }
  if (rtextsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
    optargs_s.rtextsize = Int64_val (Field (rtextsizev, 0));
  }
  if (maxpctv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
    optargs_s.maxpct = Int_val (Field (maxpctv, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_xfs_growfs_argv (g, path, optargs);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "xfs_growfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_growfs_byte (value *argv, int argn);

value
guestfs_int_ocaml_xfs_growfs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_xfs_growfs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

/* Automatically generated wrapper for function
 * val xfs_info : t -> string -> xfsinfo
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_info (value gv, value pathordevicev);

value
guestfs_int_ocaml_xfs_info (value gv, value pathordevicev)
{
  CAMLparam2 (gv, pathordevicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("xfs_info");

  char *pathordevice;
  pathordevice = strdup (String_val (pathordevicev));
  if (pathordevice == NULL) caml_raise_out_of_memory ();
  struct guestfs_xfsinfo *r;

  caml_enter_blocking_section ();
  r = guestfs_xfs_info (g, pathordevice);
  caml_leave_blocking_section ();
  free (pathordevice);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "xfs_info");

  rv = copy_xfsinfo (r);
  guestfs_free_xfsinfo (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val xfs_repair : t -> ?forcelogzero:bool -> ?nomodify:bool -> ?noprefetch:bool -> ?forcegeometry:bool -> ?maxmem:int64 -> ?ihashsize:int64 -> ?bhashsize:int64 -> ?agstride:int64 -> ?logdev:string -> ?rtdev:string -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_repair (value gv, value forcelogzerov, value nomodifyv, value noprefetchv, value forcegeometryv, value maxmemv, value ihashsizev, value bhashsizev, value agstridev, value logdevv, value rtdevv, value devicev);

value
guestfs_int_ocaml_xfs_repair (value gv, value forcelogzerov, value nomodifyv, value noprefetchv, value forcegeometryv, value maxmemv, value ihashsizev, value bhashsizev, value agstridev, value logdevv, value rtdevv, value devicev)
{
  CAMLparam5 (gv, forcelogzerov, nomodifyv, noprefetchv, forcegeometryv);
  CAMLxparam5 (maxmemv, ihashsizev, bhashsizev, agstridev, logdevv);
  CAMLxparam2 (rtdevv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("xfs_repair");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  if (forcelogzerov != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
    optargs_s.forcelogzero = Bool_val (Field (forcelogzerov, 0));
  }
  if (nomodifyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
    optargs_s.nomodify = Bool_val (Field (nomodifyv, 0));
  }
  if (noprefetchv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
    optargs_s.noprefetch = Bool_val (Field (noprefetchv, 0));
  }
  if (forcegeometryv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
    optargs_s.forcegeometry = Bool_val (Field (forcegeometryv, 0));
  }
  if (maxmemv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
    optargs_s.maxmem = Int64_val (Field (maxmemv, 0));
  }
  if (ihashsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
    optargs_s.ihashsize = Int64_val (Field (ihashsizev, 0));
  }
  if (bhashsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
    optargs_s.bhashsize = Int64_val (Field (bhashsizev, 0));
  }
  if (agstridev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
    optargs_s.agstride = Int64_val (Field (agstridev, 0));
  }
  if (logdevv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
    optargs_s.logdev = strdup (String_val (Field (logdevv, 0)));
    if (optargs_s.logdev == NULL) caml_raise_out_of_memory ();
  }
  if (rtdevv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
    optargs_s.rtdev = strdup (String_val (Field (rtdevv, 0)));
    if (optargs_s.rtdev == NULL) caml_raise_out_of_memory ();
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_xfs_repair_argv (g, device, optargs);
  caml_leave_blocking_section ();
  free (device);
  if (logdevv != Val_int (0))
    free ((char *) optargs_s.logdev);
  if (rtdevv != Val_int (0))
    free ((char *) optargs_s.rtdev);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "xfs_repair");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_xfs_repair_byte (value *argv, int argn);

value
guestfs_int_ocaml_xfs_repair_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return guestfs_int_ocaml_xfs_repair (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}

/* Automatically generated wrapper for function
 * val zegrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zegrep (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_zegrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zegrep");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zegrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zegrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zegrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zegrepi (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_zegrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zegrepi");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zegrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zegrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zero (value gv, value devicev);

value
guestfs_int_ocaml_zero (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zero");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "zero");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zero_device (value gv, value devicev);

value
guestfs_int_ocaml_zero_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zero_device");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "zero_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero_free_space : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zero_free_space (value gv, value directoryv);

value
guestfs_int_ocaml_zero_free_space (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zero_free_space");

  char *directory;
  directory = strdup (String_val (directoryv));
  if (directory == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero_free_space (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "zero_free_space");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zerofree : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zerofree (value gv, value devicev);

value
guestfs_int_ocaml_zerofree (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zerofree");

  char *device;
  device = strdup (String_val (devicev));
  if (device == NULL) caml_raise_out_of_memory ();
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zerofree (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    guestfs_int_ocaml_raise_error (g, "zerofree");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zfgrep (value gv, value patternv, value pathv);

value
guestfs_int_ocaml_zfgrep (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zfgrep");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zfgrep (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zfgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zfgrepi (value gv, value patternv, value pathv);

value
guestfs_int_ocaml_zfgrepi (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zfgrepi");

  char *pattern;
  pattern = strdup (String_val (patternv));
  if (pattern == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zfgrepi (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zfgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfile : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zfile (value gv, value methv, value pathv);

value
guestfs_int_ocaml_zfile (value gv, value methv, value pathv)
{
  CAMLparam3 (gv, methv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zfile");

  char *meth;
  meth = strdup (String_val (methv));
  if (meth == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_zfile (g, meth, path);
  caml_leave_blocking_section ();
  free (meth);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zfile");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zgrep (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_zgrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zgrep");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zgrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
value guestfs_int_ocaml_zgrepi (value gv, value regexv, value pathv);

value
guestfs_int_ocaml_zgrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    guestfs_int_ocaml_raise_closed ("zgrepi");

  char *regex;
  regex = strdup (String_val (regexv));
  if (regex == NULL) caml_raise_out_of_memory ();
  char *path;
  path = strdup (String_val (pathv));
  if (path == NULL) caml_raise_out_of_memory ();
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zgrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    guestfs_int_ocaml_raise_error (g, "zgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

