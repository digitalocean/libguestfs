/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
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
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <erl_interface.h>
/* We should switch over to using
  #include <ei.h>
instead of erl_interface.
*/

#include "guestfs.h"
#include "guestfs-utils.h"

#include "actions.h"

ETERM *
make_application (const struct guestfs_application *application)
{
  ETERM *t[12];

  t[0] = erl_mk_string (application->app_name);
  t[1] = erl_mk_string (application->app_display_name);
  t[2] = erl_mk_int (application->app_epoch);
  t[3] = erl_mk_string (application->app_version);
  t[4] = erl_mk_string (application->app_release);
  t[5] = erl_mk_string (application->app_install_path);
  t[6] = erl_mk_string (application->app_trans_path);
  t[7] = erl_mk_string (application->app_publisher);
  t[8] = erl_mk_string (application->app_url);
  t[9] = erl_mk_string (application->app_source_package);
  t[10] = erl_mk_string (application->app_summary);
  t[11] = erl_mk_string (application->app_description);

  return erl_mk_list (t, 12);
}

ETERM *
make_application2 (const struct guestfs_application2 *application2)
{
  ETERM *t[17];

  t[0] = erl_mk_string (application2->app2_name);
  t[1] = erl_mk_string (application2->app2_display_name);
  t[2] = erl_mk_int (application2->app2_epoch);
  t[3] = erl_mk_string (application2->app2_version);
  t[4] = erl_mk_string (application2->app2_release);
  t[5] = erl_mk_string (application2->app2_arch);
  t[6] = erl_mk_string (application2->app2_install_path);
  t[7] = erl_mk_string (application2->app2_trans_path);
  t[8] = erl_mk_string (application2->app2_publisher);
  t[9] = erl_mk_string (application2->app2_url);
  t[10] = erl_mk_string (application2->app2_source_package);
  t[11] = erl_mk_string (application2->app2_summary);
  t[12] = erl_mk_string (application2->app2_description);
  t[13] = erl_mk_string (application2->app2_spare1);
  t[14] = erl_mk_string (application2->app2_spare2);
  t[15] = erl_mk_string (application2->app2_spare3);
  t[16] = erl_mk_string (application2->app2_spare4);

  return erl_mk_list (t, 17);
}

ETERM *
make_btrfsbalance (const struct guestfs_btrfsbalance *btrfsbalance)
{
  ETERM *t[5];

  t[0] = erl_mk_string (btrfsbalance->btrfsbalance_status);
  t[1] = erl_mk_longlong (btrfsbalance->btrfsbalance_total);
  t[2] = erl_mk_longlong (btrfsbalance->btrfsbalance_balanced);
  t[3] = erl_mk_longlong (btrfsbalance->btrfsbalance_considered);
  t[4] = erl_mk_longlong (btrfsbalance->btrfsbalance_left);

  return erl_mk_list (t, 5);
}

ETERM *
make_btrfsqgroup (const struct guestfs_btrfsqgroup *btrfsqgroup)
{
  ETERM *t[3];

  t[0] = erl_mk_string (btrfsqgroup->btrfsqgroup_id);
  t[1] = erl_mk_longlong (btrfsqgroup->btrfsqgroup_rfer);
  t[2] = erl_mk_longlong (btrfsqgroup->btrfsqgroup_excl);

  return erl_mk_list (t, 3);
}

ETERM *
make_btrfsscrub (const struct guestfs_btrfsscrub *btrfsscrub)
{
  ETERM *t[15];

  t[0] = erl_mk_longlong (btrfsscrub->btrfsscrub_data_extents_scrubbed);
  t[1] = erl_mk_longlong (btrfsscrub->btrfsscrub_tree_extents_scrubbed);
  t[2] = erl_mk_longlong (btrfsscrub->btrfsscrub_data_bytes_scrubbed);
  t[3] = erl_mk_longlong (btrfsscrub->btrfsscrub_tree_bytes_scrubbed);
  t[4] = erl_mk_longlong (btrfsscrub->btrfsscrub_read_errors);
  t[5] = erl_mk_longlong (btrfsscrub->btrfsscrub_csum_errors);
  t[6] = erl_mk_longlong (btrfsscrub->btrfsscrub_verify_errors);
  t[7] = erl_mk_longlong (btrfsscrub->btrfsscrub_no_csum);
  t[8] = erl_mk_longlong (btrfsscrub->btrfsscrub_csum_discards);
  t[9] = erl_mk_longlong (btrfsscrub->btrfsscrub_super_errors);
  t[10] = erl_mk_longlong (btrfsscrub->btrfsscrub_malloc_errors);
  t[11] = erl_mk_longlong (btrfsscrub->btrfsscrub_uncorrectable_errors);
  t[12] = erl_mk_longlong (btrfsscrub->btrfsscrub_unverified_errors);
  t[13] = erl_mk_longlong (btrfsscrub->btrfsscrub_corrected_errors);
  t[14] = erl_mk_longlong (btrfsscrub->btrfsscrub_last_physical);

  return erl_mk_list (t, 15);
}

ETERM *
make_btrfssubvolume (const struct guestfs_btrfssubvolume *btrfssubvolume)
{
  ETERM *t[3];

  t[0] = erl_mk_longlong (btrfssubvolume->btrfssubvolume_id);
  t[1] = erl_mk_longlong (btrfssubvolume->btrfssubvolume_top_level_id);
  t[2] = erl_mk_string (btrfssubvolume->btrfssubvolume_path);

  return erl_mk_list (t, 3);
}

ETERM *
make_dirent (const struct guestfs_dirent *dirent)
{
  ETERM *t[3];

  t[0] = erl_mk_longlong (dirent->ino);
  t[1] = erl_mk_int (dirent->ftyp);
  t[2] = erl_mk_string (dirent->name);

  return erl_mk_list (t, 3);
}

ETERM *
make_hivex_node (const struct guestfs_hivex_node *hivex_node)
{
  ETERM *t[1];

  t[0] = erl_mk_longlong (hivex_node->hivex_node_h);

  return erl_mk_list (t, 1);
}

ETERM *
make_hivex_value (const struct guestfs_hivex_value *hivex_value)
{
  ETERM *t[1];

  t[0] = erl_mk_longlong (hivex_value->hivex_value_h);

  return erl_mk_list (t, 1);
}

ETERM *
make_inotify_event (const struct guestfs_inotify_event *inotify_event)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (inotify_event->in_wd);
  t[1] = erl_mk_int (inotify_event->in_mask);
  t[2] = erl_mk_int (inotify_event->in_cookie);
  t[3] = erl_mk_string (inotify_event->in_name);

  return erl_mk_list (t, 4);
}

ETERM *
make_int_bool (const struct guestfs_int_bool *int_bool)
{
  ETERM *t[2];

  t[0] = erl_mk_int (int_bool->i);
  t[1] = erl_mk_int (int_bool->b);

  return erl_mk_list (t, 2);
}

ETERM *
make_isoinfo (const struct guestfs_isoinfo *isoinfo)
{
  ETERM *t[17];

  t[0] = erl_mk_string (isoinfo->iso_system_id);
  t[1] = erl_mk_string (isoinfo->iso_volume_id);
  t[2] = erl_mk_int (isoinfo->iso_volume_space_size);
  t[3] = erl_mk_int (isoinfo->iso_volume_set_size);
  t[4] = erl_mk_int (isoinfo->iso_volume_sequence_number);
  t[5] = erl_mk_int (isoinfo->iso_logical_block_size);
  t[6] = erl_mk_string (isoinfo->iso_volume_set_id);
  t[7] = erl_mk_string (isoinfo->iso_publisher_id);
  t[8] = erl_mk_string (isoinfo->iso_data_preparer_id);
  t[9] = erl_mk_string (isoinfo->iso_application_id);
  t[10] = erl_mk_string (isoinfo->iso_copyright_file_id);
  t[11] = erl_mk_string (isoinfo->iso_abstract_file_id);
  t[12] = erl_mk_string (isoinfo->iso_bibliographic_file_id);
  t[13] = erl_mk_longlong (isoinfo->iso_volume_creation_t);
  t[14] = erl_mk_longlong (isoinfo->iso_volume_modification_t);
  t[15] = erl_mk_longlong (isoinfo->iso_volume_expiration_t);
  t[16] = erl_mk_longlong (isoinfo->iso_volume_effective_t);

  return erl_mk_list (t, 17);
}

ETERM *
make_lvm_lv (const struct guestfs_lvm_lv *lvm_lv)
{
  ETERM *t[16];

  t[0] = erl_mk_string (lvm_lv->lv_name);
  t[1] = erl_mk_estring (lvm_lv->lv_uuid, 32);
  t[2] = erl_mk_string (lvm_lv->lv_attr);
  t[3] = erl_mk_longlong (lvm_lv->lv_major);
  t[4] = erl_mk_longlong (lvm_lv->lv_minor);
  t[5] = erl_mk_longlong (lvm_lv->lv_kernel_major);
  t[6] = erl_mk_longlong (lvm_lv->lv_kernel_minor);
  t[7] = erl_mk_longlong (lvm_lv->lv_size);
  t[8] = erl_mk_longlong (lvm_lv->seg_count);
  t[9] = erl_mk_string (lvm_lv->origin);
  if (lvm_lv->snap_percent >= 0)
    t[10] = erl_mk_float (lvm_lv->snap_percent);
  else
    t[10] = erl_mk_atom ("undefined");
  if (lvm_lv->copy_percent >= 0)
    t[11] = erl_mk_float (lvm_lv->copy_percent);
  else
    t[11] = erl_mk_atom ("undefined");
  t[12] = erl_mk_string (lvm_lv->move_pv);
  t[13] = erl_mk_string (lvm_lv->lv_tags);
  t[14] = erl_mk_string (lvm_lv->mirror_log);
  t[15] = erl_mk_string (lvm_lv->modules);

  return erl_mk_list (t, 16);
}

ETERM *
make_lvm_pv (const struct guestfs_lvm_pv *lvm_pv)
{
  ETERM *t[14];

  t[0] = erl_mk_string (lvm_pv->pv_name);
  t[1] = erl_mk_estring (lvm_pv->pv_uuid, 32);
  t[2] = erl_mk_string (lvm_pv->pv_fmt);
  t[3] = erl_mk_longlong (lvm_pv->pv_size);
  t[4] = erl_mk_longlong (lvm_pv->dev_size);
  t[5] = erl_mk_longlong (lvm_pv->pv_free);
  t[6] = erl_mk_longlong (lvm_pv->pv_used);
  t[7] = erl_mk_string (lvm_pv->pv_attr);
  t[8] = erl_mk_longlong (lvm_pv->pv_pe_count);
  t[9] = erl_mk_longlong (lvm_pv->pv_pe_alloc_count);
  t[10] = erl_mk_string (lvm_pv->pv_tags);
  t[11] = erl_mk_longlong (lvm_pv->pe_start);
  t[12] = erl_mk_longlong (lvm_pv->pv_mda_count);
  t[13] = erl_mk_longlong (lvm_pv->pv_mda_free);

  return erl_mk_list (t, 14);
}

ETERM *
make_lvm_vg (const struct guestfs_lvm_vg *lvm_vg)
{
  ETERM *t[19];

  t[0] = erl_mk_string (lvm_vg->vg_name);
  t[1] = erl_mk_estring (lvm_vg->vg_uuid, 32);
  t[2] = erl_mk_string (lvm_vg->vg_fmt);
  t[3] = erl_mk_string (lvm_vg->vg_attr);
  t[4] = erl_mk_longlong (lvm_vg->vg_size);
  t[5] = erl_mk_longlong (lvm_vg->vg_free);
  t[6] = erl_mk_string (lvm_vg->vg_sysid);
  t[7] = erl_mk_longlong (lvm_vg->vg_extent_size);
  t[8] = erl_mk_longlong (lvm_vg->vg_extent_count);
  t[9] = erl_mk_longlong (lvm_vg->vg_free_count);
  t[10] = erl_mk_longlong (lvm_vg->max_lv);
  t[11] = erl_mk_longlong (lvm_vg->max_pv);
  t[12] = erl_mk_longlong (lvm_vg->pv_count);
  t[13] = erl_mk_longlong (lvm_vg->lv_count);
  t[14] = erl_mk_longlong (lvm_vg->snap_count);
  t[15] = erl_mk_longlong (lvm_vg->vg_seqno);
  t[16] = erl_mk_string (lvm_vg->vg_tags);
  t[17] = erl_mk_longlong (lvm_vg->vg_mda_count);
  t[18] = erl_mk_longlong (lvm_vg->vg_mda_free);

  return erl_mk_list (t, 19);
}

ETERM *
make_mdstat (const struct guestfs_mdstat *mdstat)
{
  ETERM *t[3];

  t[0] = erl_mk_string (mdstat->mdstat_device);
  t[1] = erl_mk_int (mdstat->mdstat_index);
  t[2] = erl_mk_string (mdstat->mdstat_flags);

  return erl_mk_list (t, 3);
}

ETERM *
make_partition (const struct guestfs_partition *partition)
{
  ETERM *t[4];

  t[0] = erl_mk_int (partition->part_num);
  t[1] = erl_mk_longlong (partition->part_start);
  t[2] = erl_mk_longlong (partition->part_end);
  t[3] = erl_mk_longlong (partition->part_size);

  return erl_mk_list (t, 4);
}

ETERM *
make_stat (const struct guestfs_stat *stat)
{
  ETERM *t[13];

  t[0] = erl_mk_longlong (stat->dev);
  t[1] = erl_mk_longlong (stat->ino);
  t[2] = erl_mk_longlong (stat->mode);
  t[3] = erl_mk_longlong (stat->nlink);
  t[4] = erl_mk_longlong (stat->uid);
  t[5] = erl_mk_longlong (stat->gid);
  t[6] = erl_mk_longlong (stat->rdev);
  t[7] = erl_mk_longlong (stat->size);
  t[8] = erl_mk_longlong (stat->blksize);
  t[9] = erl_mk_longlong (stat->blocks);
  t[10] = erl_mk_longlong (stat->atime);
  t[11] = erl_mk_longlong (stat->mtime);
  t[12] = erl_mk_longlong (stat->ctime);

  return erl_mk_list (t, 13);
}

ETERM *
make_statns (const struct guestfs_statns *statns)
{
  ETERM *t[22];

  t[0] = erl_mk_longlong (statns->st_dev);
  t[1] = erl_mk_longlong (statns->st_ino);
  t[2] = erl_mk_longlong (statns->st_mode);
  t[3] = erl_mk_longlong (statns->st_nlink);
  t[4] = erl_mk_longlong (statns->st_uid);
  t[5] = erl_mk_longlong (statns->st_gid);
  t[6] = erl_mk_longlong (statns->st_rdev);
  t[7] = erl_mk_longlong (statns->st_size);
  t[8] = erl_mk_longlong (statns->st_blksize);
  t[9] = erl_mk_longlong (statns->st_blocks);
  t[10] = erl_mk_longlong (statns->st_atime_sec);
  t[11] = erl_mk_longlong (statns->st_atime_nsec);
  t[12] = erl_mk_longlong (statns->st_mtime_sec);
  t[13] = erl_mk_longlong (statns->st_mtime_nsec);
  t[14] = erl_mk_longlong (statns->st_ctime_sec);
  t[15] = erl_mk_longlong (statns->st_ctime_nsec);
  t[16] = erl_mk_longlong (statns->st_spare1);
  t[17] = erl_mk_longlong (statns->st_spare2);
  t[18] = erl_mk_longlong (statns->st_spare3);
  t[19] = erl_mk_longlong (statns->st_spare4);
  t[20] = erl_mk_longlong (statns->st_spare5);
  t[21] = erl_mk_longlong (statns->st_spare6);

  return erl_mk_list (t, 22);
}

ETERM *
make_statvfs (const struct guestfs_statvfs *statvfs)
{
  ETERM *t[11];

  t[0] = erl_mk_longlong (statvfs->bsize);
  t[1] = erl_mk_longlong (statvfs->frsize);
  t[2] = erl_mk_longlong (statvfs->blocks);
  t[3] = erl_mk_longlong (statvfs->bfree);
  t[4] = erl_mk_longlong (statvfs->bavail);
  t[5] = erl_mk_longlong (statvfs->files);
  t[6] = erl_mk_longlong (statvfs->ffree);
  t[7] = erl_mk_longlong (statvfs->favail);
  t[8] = erl_mk_longlong (statvfs->fsid);
  t[9] = erl_mk_longlong (statvfs->flag);
  t[10] = erl_mk_longlong (statvfs->namemax);

  return erl_mk_list (t, 11);
}

ETERM *
make_tsk_dirent (const struct guestfs_tsk_dirent *tsk_dirent)
{
  ETERM *t[16];

  t[0] = erl_mk_longlong (tsk_dirent->tsk_inode);
  t[1] = erl_mk_int (tsk_dirent->tsk_type);
  t[2] = erl_mk_longlong (tsk_dirent->tsk_size);
  t[3] = erl_mk_string (tsk_dirent->tsk_name);
  t[4] = erl_mk_int (tsk_dirent->tsk_flags);
  t[5] = erl_mk_longlong (tsk_dirent->tsk_atime_sec);
  t[6] = erl_mk_longlong (tsk_dirent->tsk_atime_nsec);
  t[7] = erl_mk_longlong (tsk_dirent->tsk_mtime_sec);
  t[8] = erl_mk_longlong (tsk_dirent->tsk_mtime_nsec);
  t[9] = erl_mk_longlong (tsk_dirent->tsk_ctime_sec);
  t[10] = erl_mk_longlong (tsk_dirent->tsk_ctime_nsec);
  t[11] = erl_mk_longlong (tsk_dirent->tsk_crtime_sec);
  t[12] = erl_mk_longlong (tsk_dirent->tsk_crtime_nsec);
  t[13] = erl_mk_longlong (tsk_dirent->tsk_nlink);
  t[14] = erl_mk_string (tsk_dirent->tsk_link);
  t[15] = erl_mk_longlong (tsk_dirent->tsk_spare1);

  return erl_mk_list (t, 16);
}

ETERM *
make_utsname (const struct guestfs_utsname *utsname)
{
  ETERM *t[4];

  t[0] = erl_mk_string (utsname->uts_sysname);
  t[1] = erl_mk_string (utsname->uts_release);
  t[2] = erl_mk_string (utsname->uts_version);
  t[3] = erl_mk_string (utsname->uts_machine);

  return erl_mk_list (t, 4);
}

ETERM *
make_version (const struct guestfs_version *version)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (version->major);
  t[1] = erl_mk_longlong (version->minor);
  t[2] = erl_mk_longlong (version->release);
  t[3] = erl_mk_string (version->extra);

  return erl_mk_list (t, 4);
}

ETERM *
make_xattr (const struct guestfs_xattr *xattr)
{
  ETERM *t[2];

  t[0] = erl_mk_string (xattr->attrname);
  t[1] = erl_mk_estring (xattr->attrval, xattr->attrval_len);

  return erl_mk_list (t, 2);
}

ETERM *
make_xfsinfo (const struct guestfs_xfsinfo *xfsinfo)
{
  ETERM *t[25];

  t[0] = erl_mk_string (xfsinfo->xfs_mntpoint);
  t[1] = erl_mk_int (xfsinfo->xfs_inodesize);
  t[2] = erl_mk_int (xfsinfo->xfs_agcount);
  t[3] = erl_mk_int (xfsinfo->xfs_agsize);
  t[4] = erl_mk_int (xfsinfo->xfs_sectsize);
  t[5] = erl_mk_int (xfsinfo->xfs_attr);
  t[6] = erl_mk_int (xfsinfo->xfs_blocksize);
  t[7] = erl_mk_longlong (xfsinfo->xfs_datablocks);
  t[8] = erl_mk_int (xfsinfo->xfs_imaxpct);
  t[9] = erl_mk_int (xfsinfo->xfs_sunit);
  t[10] = erl_mk_int (xfsinfo->xfs_swidth);
  t[11] = erl_mk_int (xfsinfo->xfs_dirversion);
  t[12] = erl_mk_int (xfsinfo->xfs_dirblocksize);
  t[13] = erl_mk_int (xfsinfo->xfs_cimode);
  t[14] = erl_mk_string (xfsinfo->xfs_logname);
  t[15] = erl_mk_int (xfsinfo->xfs_logblocksize);
  t[16] = erl_mk_int (xfsinfo->xfs_logblocks);
  t[17] = erl_mk_int (xfsinfo->xfs_logversion);
  t[18] = erl_mk_int (xfsinfo->xfs_logsectsize);
  t[19] = erl_mk_int (xfsinfo->xfs_logsunit);
  t[20] = erl_mk_int (xfsinfo->xfs_lazycount);
  t[21] = erl_mk_string (xfsinfo->xfs_rtname);
  t[22] = erl_mk_int (xfsinfo->xfs_rtextsize);
  t[23] = erl_mk_longlong (xfsinfo->xfs_rtblocks);
  t[24] = erl_mk_longlong (xfsinfo->xfs_rtextents);

  return erl_mk_list (t, 25);
}

ETERM *
make_yara_detection (const struct guestfs_yara_detection *yara_detection)
{
  ETERM *t[2];

  t[0] = erl_mk_string (yara_detection->yara_name);
  t[1] = erl_mk_string (yara_detection->yara_rule);

  return erl_mk_list (t, 2);
}

ETERM *
make_lvm_lv_list (const struct guestfs_lvm_lv_list *lvm_lvs)
{
  size_t len = lvm_lvs->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_lvm_lv_list");

  for (i = 0; i < len; ++i)
    t[i] = make_lvm_lv (&lvm_lvs->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_dirent_list (const struct guestfs_dirent_list *dirents)
{
  size_t len = dirents->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_dirent_list");

  for (i = 0; i < len; ++i)
    t[i] = make_dirent (&dirents->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *btrfsqgroups)
{
  size_t len = btrfsqgroups->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_btrfsqgroup_list");

  for (i = 0; i < len; ++i)
    t[i] = make_btrfsqgroup (&btrfsqgroups->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_tsk_dirent_list (const struct guestfs_tsk_dirent_list *tsk_dirents)
{
  size_t len = tsk_dirents->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_tsk_dirent_list");

  for (i = 0; i < len; ++i)
    t[i] = make_tsk_dirent (&tsk_dirents->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_partition_list (const struct guestfs_partition_list *partitions)
{
  size_t len = partitions->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_partition_list");

  for (i = 0; i < len; ++i)
    t[i] = make_partition (&partitions->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_statns_list (const struct guestfs_statns_list *statnss)
{
  size_t len = statnss->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_statns_list");

  for (i = 0; i < len; ++i)
    t[i] = make_statns (&statnss->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_application2_list (const struct guestfs_application2_list *application2s)
{
  size_t len = application2s->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_application2_list");

  for (i = 0; i < len; ++i)
    t[i] = make_application2 (&application2s->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_inotify_event_list (const struct guestfs_inotify_event_list *inotify_events)
{
  size_t len = inotify_events->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_inotify_event_list");

  for (i = 0; i < len; ++i)
    t[i] = make_inotify_event (&inotify_events->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_application_list (const struct guestfs_application_list *applications)
{
  size_t len = applications->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_application_list");

  for (i = 0; i < len; ++i)
    t[i] = make_application (&applications->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_hivex_value_list (const struct guestfs_hivex_value_list *hivex_values)
{
  size_t len = hivex_values->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_hivex_value_list");

  for (i = 0; i < len; ++i)
    t[i] = make_hivex_value (&hivex_values->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_xattr_list (const struct guestfs_xattr_list *xattrs)
{
  size_t len = xattrs->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_xattr_list");

  for (i = 0; i < len; ++i)
    t[i] = make_xattr (&xattrs->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_lvm_pv_list (const struct guestfs_lvm_pv_list *lvm_pvs)
{
  size_t len = lvm_pvs->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_lvm_pv_list");

  for (i = 0; i < len; ++i)
    t[i] = make_lvm_pv (&lvm_pvs->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_yara_detection_list (const struct guestfs_yara_detection_list *yara_detections)
{
  size_t len = yara_detections->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_yara_detection_list");

  for (i = 0; i < len; ++i)
    t[i] = make_yara_detection (&yara_detections->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_lvm_vg_list (const struct guestfs_lvm_vg_list *lvm_vgs)
{
  size_t len = lvm_vgs->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_lvm_vg_list");

  for (i = 0; i < len; ++i)
    t[i] = make_lvm_vg (&lvm_vgs->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  size_t len = btrfssubvolumes->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_btrfssubvolume_list");

  for (i = 0; i < len; ++i)
    t[i] = make_btrfssubvolume (&btrfssubvolumes->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_mdstat_list (const struct guestfs_mdstat_list *mdstats)
{
  size_t len = mdstats->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_mdstat_list");

  for (i = 0; i < len; ++i)
    t[i] = make_mdstat (&mdstats->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_hivex_node_list (const struct guestfs_hivex_node_list *hivex_nodes)
{
  size_t len = hivex_nodes->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_hivex_node_list");

  for (i = 0; i < len; ++i)
    t[i] = make_hivex_node (&hivex_nodes->val[i]);

  return erl_mk_list (t, len);
}

ETERM *
make_stat_list (const struct guestfs_stat_list *stats)
{
  size_t len = stats->len;
  size_t i;
  CLEANUP_FREE ETERM **t;

  t = malloc (sizeof (ETERM *) * len);
  if (t == NULL)
    return make_error ("make_stat_list");

  for (i = 0; i < len; ++i)
    t[i] = make_stat (&stats->val[i]);

  return erl_mk_list (t, len);
}
