/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
#include "guestfs-internal-frontend.h"

extern guestfs_h *g;

extern ETERM *dispatch (ETERM *message);
extern int atom_equals (ETERM *atom, const char *name);
extern ETERM *make_error (const char *funname);
extern ETERM *unknown_optarg (const char *funname, ETERM *optargname);
extern ETERM *unknown_function (ETERM *fun);
extern ETERM *make_string_list (char **r);
extern ETERM *make_table (char **r);
extern ETERM *make_bool (int r);
extern char **get_string_list (ETERM *term);
extern int get_bool (ETERM *term);
extern int get_int (ETERM *term);
extern int64_t get_int64 (ETERM *term);

#define ARG(i) (ERL_TUPLE_ELEMENT(message,(i)+1))

static ETERM *
make_int_bool (const struct guestfs_int_bool *int_bool)
{
  ETERM *t[2];

  t[0] = erl_mk_int (int_bool->i);
  t[1] = erl_mk_int (int_bool->b);

  return erl_mk_list (t, 2);
}

static ETERM *
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

static ETERM *
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

static ETERM *
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

static ETERM *
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

static ETERM *
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

static ETERM *
make_dirent (const struct guestfs_dirent *dirent)
{
  ETERM *t[3];

  t[0] = erl_mk_longlong (dirent->ino);
  t[1] = erl_mk_int (dirent->ftyp);
  t[2] = erl_mk_string (dirent->name);

  return erl_mk_list (t, 3);
}

static ETERM *
make_version (const struct guestfs_version *version)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (version->major);
  t[1] = erl_mk_longlong (version->minor);
  t[2] = erl_mk_longlong (version->release);
  t[3] = erl_mk_string (version->extra);

  return erl_mk_list (t, 4);
}

static ETERM *
make_xattr (const struct guestfs_xattr *xattr)
{
  ETERM *t[2];

  t[0] = erl_mk_string (xattr->attrname);
  t[1] = erl_mk_estring (xattr->attrval, xattr->attrval_len);

  return erl_mk_list (t, 2);
}

static ETERM *
make_inotify_event (const struct guestfs_inotify_event *inotify_event)
{
  ETERM *t[4];

  t[0] = erl_mk_longlong (inotify_event->in_wd);
  t[1] = erl_mk_int (inotify_event->in_mask);
  t[2] = erl_mk_int (inotify_event->in_cookie);
  t[3] = erl_mk_string (inotify_event->in_name);

  return erl_mk_list (t, 4);
}

static ETERM *
make_partition (const struct guestfs_partition *partition)
{
  ETERM *t[4];

  t[0] = erl_mk_int (partition->part_num);
  t[1] = erl_mk_longlong (partition->part_start);
  t[2] = erl_mk_longlong (partition->part_end);
  t[3] = erl_mk_longlong (partition->part_size);

  return erl_mk_list (t, 4);
}

static ETERM *
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

static ETERM *
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

static ETERM *
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

static ETERM *
make_mdstat (const struct guestfs_mdstat *mdstat)
{
  ETERM *t[3];

  t[0] = erl_mk_string (mdstat->mdstat_device);
  t[1] = erl_mk_int (mdstat->mdstat_index);
  t[2] = erl_mk_string (mdstat->mdstat_flags);

  return erl_mk_list (t, 3);
}

static ETERM *
make_btrfssubvolume (const struct guestfs_btrfssubvolume *btrfssubvolume)
{
  ETERM *t[3];

  t[0] = erl_mk_longlong (btrfssubvolume->btrfssubvolume_id);
  t[1] = erl_mk_longlong (btrfssubvolume->btrfssubvolume_top_level_id);
  t[2] = erl_mk_string (btrfssubvolume->btrfssubvolume_path);

  return erl_mk_list (t, 3);
}

static ETERM *
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

static ETERM *
make_utsname (const struct guestfs_utsname *utsname)
{
  ETERM *t[4];

  t[0] = erl_mk_string (utsname->uts_sysname);
  t[1] = erl_mk_string (utsname->uts_release);
  t[2] = erl_mk_string (utsname->uts_version);
  t[3] = erl_mk_string (utsname->uts_machine);

  return erl_mk_list (t, 4);
}

static ETERM *
make_hivex_node (const struct guestfs_hivex_node *hivex_node)
{
  ETERM *t[1];

  t[0] = erl_mk_longlong (hivex_node->hivex_node_h);

  return erl_mk_list (t, 1);
}

static ETERM *
make_hivex_value (const struct guestfs_hivex_value *hivex_value)
{
  ETERM *t[1];

  t[0] = erl_mk_longlong (hivex_value->hivex_value_h);

  return erl_mk_list (t, 1);
}

static ETERM *
make_lvm_lv_list (const struct guestfs_lvm_lv_list *lvm_lvs)
{
  ETERM *t[lvm_lvs->len];
  size_t i;

  for (i = 0; i < lvm_lvs->len; ++i)
    t[i] = make_lvm_lv (&lvm_lvs->val[i]);

  return erl_mk_list (t, lvm_lvs->len);
}

static ETERM *
make_dirent_list (const struct guestfs_dirent_list *dirents)
{
  ETERM *t[dirents->len];
  size_t i;

  for (i = 0; i < dirents->len; ++i)
    t[i] = make_dirent (&dirents->val[i]);

  return erl_mk_list (t, dirents->len);
}

static ETERM *
make_partition_list (const struct guestfs_partition_list *partitions)
{
  ETERM *t[partitions->len];
  size_t i;

  for (i = 0; i < partitions->len; ++i)
    t[i] = make_partition (&partitions->val[i]);

  return erl_mk_list (t, partitions->len);
}

static ETERM *
make_application2_list (const struct guestfs_application2_list *application2s)
{
  ETERM *t[application2s->len];
  size_t i;

  for (i = 0; i < application2s->len; ++i)
    t[i] = make_application2 (&application2s->val[i]);

  return erl_mk_list (t, application2s->len);
}

static ETERM *
make_inotify_event_list (const struct guestfs_inotify_event_list *inotify_events)
{
  ETERM *t[inotify_events->len];
  size_t i;

  for (i = 0; i < inotify_events->len; ++i)
    t[i] = make_inotify_event (&inotify_events->val[i]);

  return erl_mk_list (t, inotify_events->len);
}

static ETERM *
make_application_list (const struct guestfs_application_list *applications)
{
  ETERM *t[applications->len];
  size_t i;

  for (i = 0; i < applications->len; ++i)
    t[i] = make_application (&applications->val[i]);

  return erl_mk_list (t, applications->len);
}

static ETERM *
make_hivex_value_list (const struct guestfs_hivex_value_list *hivex_values)
{
  ETERM *t[hivex_values->len];
  size_t i;

  for (i = 0; i < hivex_values->len; ++i)
    t[i] = make_hivex_value (&hivex_values->val[i]);

  return erl_mk_list (t, hivex_values->len);
}

static ETERM *
make_xattr_list (const struct guestfs_xattr_list *xattrs)
{
  ETERM *t[xattrs->len];
  size_t i;

  for (i = 0; i < xattrs->len; ++i)
    t[i] = make_xattr (&xattrs->val[i]);

  return erl_mk_list (t, xattrs->len);
}

static ETERM *
make_lvm_pv_list (const struct guestfs_lvm_pv_list *lvm_pvs)
{
  ETERM *t[lvm_pvs->len];
  size_t i;

  for (i = 0; i < lvm_pvs->len; ++i)
    t[i] = make_lvm_pv (&lvm_pvs->val[i]);

  return erl_mk_list (t, lvm_pvs->len);
}

static ETERM *
make_lvm_vg_list (const struct guestfs_lvm_vg_list *lvm_vgs)
{
  ETERM *t[lvm_vgs->len];
  size_t i;

  for (i = 0; i < lvm_vgs->len; ++i)
    t[i] = make_lvm_vg (&lvm_vgs->val[i]);

  return erl_mk_list (t, lvm_vgs->len);
}

static ETERM *
make_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  ETERM *t[btrfssubvolumes->len];
  size_t i;

  for (i = 0; i < btrfssubvolumes->len; ++i)
    t[i] = make_btrfssubvolume (&btrfssubvolumes->val[i]);

  return erl_mk_list (t, btrfssubvolumes->len);
}

static ETERM *
make_mdstat_list (const struct guestfs_mdstat_list *mdstats)
{
  ETERM *t[mdstats->len];
  size_t i;

  for (i = 0; i < mdstats->len; ++i)
    t[i] = make_mdstat (&mdstats->val[i]);

  return erl_mk_list (t, mdstats->len);
}

static ETERM *
make_hivex_node_list (const struct guestfs_hivex_node_list *hivex_nodes)
{
  ETERM *t[hivex_nodes->len];
  size_t i;

  for (i = 0; i < hivex_nodes->len; ++i)
    t[i] = make_hivex_node (&hivex_nodes->val[i]);

  return erl_mk_list (t, hivex_nodes->len);
}

static ETERM *
make_stat_list (const struct guestfs_stat_list *stats)
{
  ETERM *t[stats->len];
  size_t i;

  for (i = 0; i < stats->len; ++i)
    t[i] = make_stat (&stats->val[i]);

  return erl_mk_list (t, stats->len);
}

static ETERM *
run_acl_delete_def_file (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_acl_delete_def_file (g, dir);
  if (r == -1)
    return make_error ("acl_delete_def_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_acl_get_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *acltype = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_acl_get_file (g, path, acltype);
  if (r == NULL)
    return make_error ("acl_get_file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_acl_set_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *acltype = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *acl = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_acl_set_file (g, path, acltype, acl);
  if (r == -1)
    return make_error ("acl_set_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_cdrom (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    return make_error ("add_cdrom");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_domain (ETERM *message)
{
  CLEANUP_FREE char *dom = erl_iolist_to_string (ARG (0));

  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "libvirturi")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      optargs_s.libvirturi = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "live")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      optargs_s.live = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "allowuuid")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      optargs_s.allowuuid = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonlydisk")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      optargs_s.readonlydisk = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_domain", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_domain_argv (g, dom, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK))
    free ((char *) optargs_s.libvirturi);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK))
    free ((char *) optargs_s.readonlydisk);
  if (r == -1)
    return make_error ("add_domain");

  return erl_mk_int (r);
}

static ETERM *
run_add_drive (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));

  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "format")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      optargs_s.format = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "name")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      optargs_s.name = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "protocol")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      optargs_s.protocol = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "server")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
      optargs_s.server = get_string_list (hd_value);
    }
    else
    if (atom_equals (hd_name, "username")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
      optargs_s.username = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "secret")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
      optargs_s.secret = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachemode")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
      optargs_s.cachemode = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_drive", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK))
    free ((char *) optargs_s.format);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK))
    free ((char *) optargs_s.name);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK))
    free ((char *) optargs_s.protocol);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK))
    guestfs___free_string_list ((char **) optargs_s.server);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK))
    free ((char *) optargs_s.username);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK))
    free ((char *) optargs_s.secret);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK))
    free ((char *) optargs_s.cachemode);
  if (r == -1)
    return make_error ("add_drive");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_ro (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    return make_error ("add_drive_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_ro_with_if (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    return make_error ("add_drive_ro_with_if");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_scratch (ETERM *message)
{
  int64_t size = get_int64 (ARG (0));

  struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "name")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
      optargs_s.name = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_drive_scratch", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_drive_scratch_argv (g, size, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK))
    free ((char *) optargs_s.name);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if (r == -1)
    return make_error ("add_drive_scratch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_add_drive_with_if (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    return make_error ("add_drive_with_if");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_clear (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_clear (g, augpath);
  if (r == -1)
    return make_error ("aug_clear");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_close (ETERM *message)
{
  int r;

  r = guestfs_aug_close (g);
  if (r == -1)
    return make_error ("aug_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_defnode (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *expr = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (2));
  struct guestfs_int_bool *r;

  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL)
    return make_error ("aug_defnode");

  ETERM *rt = make_int_bool (r);
  guestfs_free_int_bool (r);
  return rt;
}

static ETERM *
run_aug_defvar (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *expr;
  if (atom_equals (ARG (1), "undefined"))
    expr = NULL;
  else
    expr = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    return make_error ("aug_defvar");

  return erl_mk_int (r);
}

static ETERM *
run_aug_get (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    return make_error ("aug_get");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_aug_init (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int flags = get_int (ARG (1));
  int r;

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    return make_error ("aug_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_insert (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int before = get_bool (ARG (2));
  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    return make_error ("aug_insert");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_label (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_aug_label (g, augpath);
  if (r == NULL)
    return make_error ("aug_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_aug_load (ETERM *message)
{
  int r;

  r = guestfs_aug_load (g);
  if (r == -1)
    return make_error ("aug_load");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_ls (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_ls (g, augpath);
  if (r == NULL)
    return make_error ("aug_ls");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_aug_match (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_match (g, augpath);
  if (r == NULL)
    return make_error ("aug_match");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_aug_mv (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    return make_error ("aug_mv");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_rm (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    return make_error ("aug_rm");

  return erl_mk_int (r);
}

static ETERM *
run_aug_save (ETERM *message)
{
  int r;

  r = guestfs_aug_save (g);
  if (r == -1)
    return make_error ("aug_save");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_set (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    return make_error ("aug_set");

  return erl_mk_atom ("ok");
}

static ETERM *
run_aug_setm (ETERM *message)
{
  CLEANUP_FREE char *base = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *sub;
  if (atom_equals (ARG (1), "undefined"))
    sub = NULL;
  else
    sub = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_aug_setm (g, base, sub, val);
  if (r == -1)
    return make_error ("aug_setm");

  return erl_mk_int (r);
}

static ETERM *
run_available (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **groups = get_string_list (ARG (0));
  int r;

  r = guestfs_available (g, groups);
  if (r == -1)
    return make_error ("available");

  return erl_mk_atom ("ok");
}

static ETERM *
run_available_all_groups (ETERM *message)
{
  char **r;

  r = guestfs_available_all_groups (g);
  if (r == NULL)
    return make_error ("available_all_groups");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_base64_in (ETERM *message)
{
  CLEANUP_FREE char *base64file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1)
    return make_error ("base64_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_base64_out (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *base64file = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1)
    return make_error ("base64_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blkid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_blkid (g, device);
  if (r == NULL)
    return make_error ("blkid");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_blockdev_flushbufs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    return make_error ("blockdev_flushbufs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_getbsz (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    return make_error ("blockdev_getbsz");

  return erl_mk_int (r);
}

static ETERM *
run_blockdev_getro (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    return make_error ("blockdev_getro");

  return make_bool (r);
}

static ETERM *
run_blockdev_getsize64 (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    return make_error ("blockdev_getsize64");

  return erl_mk_longlong (r);
}

static ETERM *
run_blockdev_getss (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    return make_error ("blockdev_getss");

  return erl_mk_int (r);
}

static ETERM *
run_blockdev_getsz (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    return make_error ("blockdev_getsz");

  return erl_mk_longlong (r);
}

static ETERM *
run_blockdev_rereadpt (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    return make_error ("blockdev_rereadpt");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setbsz (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    return make_error ("blockdev_setbsz");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setro (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    return make_error ("blockdev_setro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_blockdev_setrw (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    return make_error ("blockdev_setrw");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_device_add (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_device_add (g, devices, fs);
  if (r == -1)
    return make_error ("btrfs_device_add");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_device_delete (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_device_delete (g, devices, fs);
  if (r == -1)
    return make_error ("btrfs_device_delete");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_filesystem_balance (ETERM *message)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_filesystem_balance (g, fs);
  if (r == -1)
    return make_error ("btrfs_filesystem_balance");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_filesystem_resize (ETERM *message)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("btrfs_filesystem_resize", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("btrfs_filesystem_resize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_filesystem_sync (ETERM *message)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_filesystem_sync (g, fs);
  if (r == -1)
    return make_error ("btrfs_filesystem_sync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_fsck (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "superblock")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      optargs_s.superblock = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "repair")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      optargs_s.repair = get_bool (hd_value);
    }
    else
      return unknown_optarg ("btrfs_fsck", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  if (r == -1)
    return make_error ("btrfs_fsck");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_set_seeding (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int seeding = get_bool (ARG (1));
  int r;

  r = guestfs_btrfs_set_seeding (g, device, seeding);
  if (r == -1)
    return make_error ("btrfs_set_seeding");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_subvolume_create (ETERM *message)
{
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_subvolume_create (g, dest);
  if (r == -1)
    return make_error ("btrfs_subvolume_create");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_subvolume_delete (ETERM *message)
{
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (r == -1)
    return make_error ("btrfs_subvolume_delete");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_subvolume_list (ETERM *message)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  struct guestfs_btrfssubvolume_list *r;

  r = guestfs_btrfs_subvolume_list (g, fs);
  if (r == NULL)
    return make_error ("btrfs_subvolume_list");

  ETERM *rt = make_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);
  return rt;
}

static ETERM *
run_btrfs_subvolume_set_default (ETERM *message)
{
  int64_t id = get_int64 (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  if (r == -1)
    return make_error ("btrfs_subvolume_set_default");

  return erl_mk_atom ("ok");
}

static ETERM *
run_btrfs_subvolume_snapshot (ETERM *message)
{
  CLEANUP_FREE char *source = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);
  if (r == -1)
    return make_error ("btrfs_subvolume_snapshot");

  return erl_mk_atom ("ok");
}

static ETERM *
run_canonical_device_name (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_canonical_device_name (g, device);
  if (r == NULL)
    return make_error ("canonical_device_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_cap_get_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_cap_get_file (g, path);
  if (r == NULL)
    return make_error ("cap_get_file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_cap_set_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *cap = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cap_set_file (g, path, cap);
  if (r == -1)
    return make_error ("cap_set_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_case_sensitive_path (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    return make_error ("case_sensitive_path");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_cat (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_cat (g, path);
  if (r == NULL)
    return make_error ("cat");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksum (ETERM *message)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    return make_error ("checksum");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksum_device (ETERM *message)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL)
    return make_error ("checksum_device");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_checksums_out (ETERM *message)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *sumsfile = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1)
    return make_error ("checksums_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_chmod (ETERM *message)
{
  int mode = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    return make_error ("chmod");

  return erl_mk_atom ("ok");
}

static ETERM *
run_chown (ETERM *message)
{
  int owner = get_int (ARG (0));
  int group = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    return make_error ("chown");

  return erl_mk_atom ("ok");
}

static ETERM *
run_command (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **arguments = get_string_list (ARG (0));
  char *r;

  r = guestfs_command (g, arguments);
  if (r == NULL)
    return make_error ("command");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_command_lines (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **arguments = get_string_list (ARG (0));
  char **r;

  r = guestfs_command_lines (g, arguments);
  if (r == NULL)
    return make_error ("command_lines");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_compress_device_out (ETERM *message)
{
  CLEANUP_FREE char *ctype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *zdevice = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      optargs_s.level = get_int (hd_value);
    }
    else
      return unknown_optarg ("compress_device_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1)
    return make_error ("compress_device_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_compress_out (ETERM *message)
{
  CLEANUP_FREE char *ctype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *zfile = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      optargs_s.level = get_int (hd_value);
    }
    else
      return unknown_optarg ("compress_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1)
    return make_error ("compress_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_config (ETERM *message)
{
  CLEANUP_FREE char *hvparam = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *hvvalue;
  if (atom_equals (ARG (1), "undefined"))
    hvvalue = NULL;
  else
    hvvalue = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_config (g, hvparam, hvvalue);
  if (r == -1)
    return make_error ("config");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_attributes (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "all")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
      optargs_s.all = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "mode")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
      optargs_s.mode = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "xattributes")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
      optargs_s.xattributes = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "ownership")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
      optargs_s.ownership = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_attributes", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_attributes");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_device_to_device (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_device_to_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_device_to_file (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_device_to_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_file_to_device (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_file_to_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_file_to_file (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_file_to_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_copy_size (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int64_t size = get_int64 (ARG (2));
  int r;

  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1)
    return make_error ("copy_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_cp (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    return make_error ("cp");

  return erl_mk_atom ("ok");
}

static ETERM *
run_cp_a (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    return make_error ("cp_a");

  return erl_mk_atom ("ok");
}

static ETERM *
run_cp_r (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp_r (g, src, dest);
  if (r == -1)
    return make_error ("cp_r");

  return erl_mk_atom ("ok");
}

static ETERM *
run_dd (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    return make_error ("dd");

  return erl_mk_atom ("ok");
}

static ETERM *
run_debug (ETERM *message)
{
  CLEANUP_FREE char *subcmd = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **extraargs = get_string_list (ARG (1));
  char *r;

  r = guestfs_debug (g, subcmd, extraargs);
  if (r == NULL)
    return make_error ("debug");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_debug_drives (ETERM *message)
{
  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    return make_error ("debug_drives");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_debug_upload (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tmpname = erl_iolist_to_string (ARG (1));
  int mode = get_int (ARG (2));
  int r;

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1)
    return make_error ("debug_upload");

  return erl_mk_atom ("ok");
}

static ETERM *
run_device_index (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_device_index (g, device);
  if (r == -1)
    return make_error ("device_index");

  return erl_mk_int (r);
}

static ETERM *
run_df (ETERM *message)
{
  char *r;

  r = guestfs_df (g);
  if (r == NULL)
    return make_error ("df");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_df_h (ETERM *message)
{
  char *r;

  r = guestfs_df_h (g);
  if (r == NULL)
    return make_error ("df_h");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_disk_create (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *format = erl_iolist_to_string (ARG (1));
  int64_t size = get_int64 (ARG (2));

  struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "backingfile")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
      optargs_s.backingfile = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "backingformat")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
      optargs_s.backingformat = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "preallocation")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
      optargs_s.preallocation = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "compat")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
      optargs_s.compat = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "clustersize")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
      optargs_s.clustersize = get_int (hd_value);
    }
    else
      return unknown_optarg ("disk_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK))
    free ((char *) optargs_s.backingfile);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK))
    free ((char *) optargs_s.backingformat);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK))
    free ((char *) optargs_s.preallocation);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_COMPAT_BITMASK))
    free ((char *) optargs_s.compat);
  if (r == -1)
    return make_error ("disk_create");

  return erl_mk_atom ("ok");
}

static ETERM *
run_disk_format (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_disk_format (g, filename);
  if (r == NULL)
    return make_error ("disk_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_disk_has_backing_file (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_disk_has_backing_file (g, filename);
  if (r == -1)
    return make_error ("disk_has_backing_file");

  return make_bool (r);
}

static ETERM *
run_disk_virtual_size (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_disk_virtual_size (g, filename);
  if (r == -1)
    return make_error ("disk_virtual_size");

  return erl_mk_longlong (r);
}

static ETERM *
run_dmesg (ETERM *message)
{
  char *r;

  r = guestfs_dmesg (g);
  if (r == NULL)
    return make_error ("dmesg");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_download (ETERM *message)
{
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    return make_error ("download");

  return erl_mk_atom ("ok");
}

static ETERM *
run_download_offset (ETERM *message)
{
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  int64_t size = get_int64 (ARG (3));
  int r;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1)
    return make_error ("download_offset");

  return erl_mk_atom ("ok");
}

static ETERM *
run_drop_caches (ETERM *message)
{
  int whattodrop = get_int (ARG (0));
  int r;

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    return make_error ("drop_caches");

  return erl_mk_atom ("ok");
}

static ETERM *
run_du (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_du (g, path);
  if (r == -1)
    return make_error ("du");

  return erl_mk_longlong (r);
}

static ETERM *
run_e2fsck (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "correct")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      optargs_s.correct = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "forceall")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      optargs_s.forceall = get_bool (hd_value);
    }
    else
      return unknown_optarg ("e2fsck", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_e2fsck_argv (g, device, optargs);
  if (r == -1)
    return make_error ("e2fsck");

  return erl_mk_atom ("ok");
}

static ETERM *
run_e2fsck_f (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    return make_error ("e2fsck_f");

  return erl_mk_atom ("ok");
}

static ETERM *
run_echo_daemon (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **words = get_string_list (ARG (0));
  char *r;

  r = guestfs_echo_daemon (g, words);
  if (r == NULL)
    return make_error ("echo_daemon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_egrep (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrep (g, regex, path);
  if (r == NULL)
    return make_error ("egrep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_egrepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrepi (g, regex, path);
  if (r == NULL)
    return make_error ("egrepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_equal (ETERM *message)
{
  CLEANUP_FREE char *file1 = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *file2 = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    return make_error ("equal");

  return make_bool (r);
}

static ETERM *
run_exists (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_exists (g, path);
  if (r == -1)
    return make_error ("exists");

  return make_bool (r);
}

static ETERM *
run_extlinux (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_extlinux (g, directory);
  if (r == -1)
    return make_error ("extlinux");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fallocate (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int len = get_int (ARG (1));
  int r;

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    return make_error ("fallocate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fallocate64 (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t len = get_int64 (ARG (1));
  int r;

  r = guestfs_fallocate64 (g, path, len);
  if (r == -1)
    return make_error ("fallocate64");

  return erl_mk_atom ("ok");
}

static ETERM *
run_feature_available (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **groups = get_string_list (ARG (0));
  int r;

  r = guestfs_feature_available (g, groups);
  if (r == -1)
    return make_error ("feature_available");

  return make_bool (r);
}

static ETERM *
run_fgrep (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL)
    return make_error ("fgrep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_fgrepi (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL)
    return make_error ("fgrepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file (g, path);
  if (r == NULL)
    return make_error ("file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_file_architecture (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file_architecture (g, filename);
  if (r == NULL)
    return make_error ("file_architecture");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_filesize (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_filesize (g, file);
  if (r == -1)
    return make_error ("filesize");

  return erl_mk_longlong (r);
}

static ETERM *
run_filesystem_available (ETERM *message)
{
  CLEANUP_FREE char *filesystem = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_filesystem_available (g, filesystem);
  if (r == -1)
    return make_error ("filesystem_available");

  return make_bool (r);
}

static ETERM *
run_fill (ETERM *message)
{
  int c = get_int (ARG (0));
  int len = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    return make_error ("fill");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fill_dir (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int nr = get_int (ARG (1));
  int r;

  r = guestfs_fill_dir (g, dir, nr);
  if (r == -1)
    return make_error ("fill_dir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_fill_pattern (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  int len = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1)
    return make_error ("fill_pattern");

  return erl_mk_atom ("ok");
}

static ETERM *
run_find (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_find (g, directory);
  if (r == NULL)
    return make_error ("find");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_find0 (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *files = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    return make_error ("find0");

  return erl_mk_atom ("ok");
}

static ETERM *
run_findfs_label (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_label (g, label);
  if (r == NULL)
    return make_error ("findfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_findfs_uuid (ETERM *message)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL)
    return make_error ("findfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_fsck (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    return make_error ("fsck");

  return erl_mk_int (r);
}

static ETERM *
run_fstrim (ETERM *message)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "offset")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
      optargs_s.offset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "length")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
      optargs_s.length = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "minimumfreeextent")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
      optargs_s.minimumfreeextent = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("fstrim", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_fstrim_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("fstrim");

  return erl_mk_atom ("ok");
}

static ETERM *
run_get_append (ETERM *message)
{
  const char *r;

  r = guestfs_get_append (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_get_attach_method (ETERM *message)
{
  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    return make_error ("get_attach_method");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_autosync (ETERM *message)
{
  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    return make_error ("get_autosync");

  return make_bool (r);
}

static ETERM *
run_get_backend (ETERM *message)
{
  char *r;

  r = guestfs_get_backend (g);
  if (r == NULL)
    return make_error ("get_backend");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_backend_settings (ETERM *message)
{
  char **r;

  r = guestfs_get_backend_settings (g);
  if (r == NULL)
    return make_error ("get_backend_settings");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_get_cachedir (ETERM *message)
{
  char *r;

  r = guestfs_get_cachedir (g);
  if (r == NULL)
    return make_error ("get_cachedir");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_direct (ETERM *message)
{
  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    return make_error ("get_direct");

  return make_bool (r);
}

static ETERM *
run_get_e2attrs (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2attrs (g, file);
  if (r == NULL)
    return make_error ("get_e2attrs");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_e2generation (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_get_e2generation (g, file);
  if (r == -1)
    return make_error ("get_e2generation");

  return erl_mk_longlong (r);
}

static ETERM *
run_get_e2label (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    return make_error ("get_e2label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_e2uuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    return make_error ("get_e2uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_hv (ETERM *message)
{
  char *r;

  r = guestfs_get_hv (g);
  if (r == NULL)
    return make_error ("get_hv");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_libvirt_requested_credential_challenge (ETERM *message)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_challenge");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_libvirt_requested_credential_defresult (ETERM *message)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_defresult");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_libvirt_requested_credential_prompt (ETERM *message)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_prompt");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_libvirt_requested_credentials (ETERM *message)
{
  char **r;

  r = guestfs_get_libvirt_requested_credentials (g);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credentials");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_get_memsize (ETERM *message)
{
  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    return make_error ("get_memsize");

  return erl_mk_int (r);
}

static ETERM *
run_get_network (ETERM *message)
{
  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    return make_error ("get_network");

  return make_bool (r);
}

static ETERM *
run_get_path (ETERM *message)
{
  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    return make_error ("get_path");

  return erl_mk_string (r);
}

static ETERM *
run_get_pgroup (ETERM *message)
{
  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    return make_error ("get_pgroup");

  return make_bool (r);
}

static ETERM *
run_get_pid (ETERM *message)
{
  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    return make_error ("get_pid");

  return erl_mk_int (r);
}

static ETERM *
run_get_program (ETERM *message)
{
  const char *r;

  r = guestfs_get_program (g);
  if (r == NULL)
    return make_error ("get_program");

  return erl_mk_string (r);
}

static ETERM *
run_get_qemu (ETERM *message)
{
  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    return make_error ("get_qemu");

  return erl_mk_string (r);
}

static ETERM *
run_get_recovery_proc (ETERM *message)
{
  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    return make_error ("get_recovery_proc");

  return make_bool (r);
}

static ETERM *
run_get_selinux (ETERM *message)
{
  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    return make_error ("get_selinux");

  return make_bool (r);
}

static ETERM *
run_get_smp (ETERM *message)
{
  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    return make_error ("get_smp");

  return erl_mk_int (r);
}

static ETERM *
run_get_state (ETERM *message)
{
  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    return make_error ("get_state");

  return erl_mk_int (r);
}

static ETERM *
run_get_tmpdir (ETERM *message)
{
  char *r;

  r = guestfs_get_tmpdir (g);
  if (r == NULL)
    return make_error ("get_tmpdir");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_get_trace (ETERM *message)
{
  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    return make_error ("get_trace");

  return make_bool (r);
}

static ETERM *
run_get_umask (ETERM *message)
{
  int r;

  r = guestfs_get_umask (g);
  if (r == -1)
    return make_error ("get_umask");

  return erl_mk_int (r);
}

static ETERM *
run_get_verbose (ETERM *message)
{
  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    return make_error ("get_verbose");

  return make_bool (r);
}

static ETERM *
run_getcon (ETERM *message)
{
  char *r;

  r = guestfs_getcon (g);
  if (r == NULL)
    return make_error ("getcon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_getxattr (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL)
    return make_error ("getxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_getxattrs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    return make_error ("getxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_glob_expand (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_glob_expand (g, pattern);
  if (r == NULL)
    return make_error ("glob_expand");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_grep (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));

  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "extended")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
      optargs_s.extended = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "fixed")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
      optargs_s.fixed = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "insensitive")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
      optargs_s.insensitive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "compressed")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
      optargs_s.compressed = get_bool (hd_value);
    }
    else
      return unknown_optarg ("grep", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char **r;

  r = guestfs_grep_opts_argv (g, regex, path, optargs);
  if (r == NULL)
    return make_error ("grep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_grepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_grepi (g, regex, path);
  if (r == NULL)
    return make_error ("grepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_grub_install (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    return make_error ("grub_install");

  return erl_mk_atom ("ok");
}

static ETERM *
run_head (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_head (g, path);
  if (r == NULL)
    return make_error ("head");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_head_n (ETERM *message)
{
  int nrlines = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL)
    return make_error ("head_n");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_hexdump (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    return make_error ("hexdump");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_hivex_close (ETERM *message)
{
  int r;

  r = guestfs_hivex_close (g);
  if (r == -1)
    return make_error ("hivex_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_hivex_commit (ETERM *message)
{
  CLEANUP_FREE char *filename;
  if (atom_equals (ARG (0), "undefined"))
    filename = NULL;
  else
    filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_hivex_commit (g, filename);
  if (r == -1)
    return make_error ("hivex_commit");

  return erl_mk_atom ("ok");
}

static ETERM *
run_hivex_node_add_child (ETERM *message)
{
  int64_t parent = get_int64 (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_add_child (g, parent, name);
  if (r == -1)
    return make_error ("hivex_node_add_child");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_node_children (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  struct guestfs_hivex_node_list *r;

  r = guestfs_hivex_node_children (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_children");

  ETERM *rt = make_hivex_node_list (r);
  guestfs_free_hivex_node_list (r);
  return rt;
}

static ETERM *
run_hivex_node_delete_child (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  int r;

  r = guestfs_hivex_node_delete_child (g, nodeh);
  if (r == -1)
    return make_error ("hivex_node_delete_child");

  return erl_mk_atom ("ok");
}

static ETERM *
run_hivex_node_get_child (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_get_child (g, nodeh, name);
  if (r == -1)
    return make_error ("hivex_node_get_child");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_node_get_value (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_get_value (g, nodeh, key);
  if (r == -1)
    return make_error ("hivex_node_get_value");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_node_name (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_node_name (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_hivex_node_parent (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_hivex_node_parent (g, nodeh);
  if (r == -1)
    return make_error ("hivex_node_parent");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_node_set_value (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int64_t t = get_int64 (ARG (2));
  ETERM *val_bin = erl_iolist_to_binary (ARG (3));
  const void *val = ERL_BIN_PTR (val_bin);
  size_t val_size = ERL_BIN_SIZE (val_bin);
  int r;

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
  if (r == -1)
    return make_error ("hivex_node_set_value");

  return erl_mk_atom ("ok");
}

static ETERM *
run_hivex_node_values (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  struct guestfs_hivex_value_list *r;

  r = guestfs_hivex_node_values (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_values");

  ETERM *rt = make_hivex_value_list (r);
  guestfs_free_hivex_value_list (r);
  return rt;
}

static ETERM *
run_hivex_open (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));

  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "verbose")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
      optargs_s.verbose = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "debug")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
      optargs_s.debug = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "write")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
      optargs_s.write = get_bool (hd_value);
    }
    else
      return unknown_optarg ("hivex_open", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_hivex_open_argv (g, filename, optargs);
  if (r == -1)
    return make_error ("hivex_open");

  return erl_mk_atom ("ok");
}

static ETERM *
run_hivex_root (ETERM *message)
{
  int64_t r;

  r = guestfs_hivex_root (g);
  if (r == -1)
    return make_error ("hivex_root");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_value_key (ETERM *message)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_value_key (g, valueh);
  if (r == NULL)
    return make_error ("hivex_value_key");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_hivex_value_type (ETERM *message)
{
  int64_t valueh = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_hivex_value_type (g, valueh);
  if (r == -1)
    return make_error ("hivex_value_type");

  return erl_mk_longlong (r);
}

static ETERM *
run_hivex_value_utf8 (ETERM *message)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_value_utf8 (g, valueh);
  if (r == NULL)
    return make_error ("hivex_value_utf8");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_hivex_value_value (ETERM *message)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;
  size_t size;

  r = guestfs_hivex_value_value (g, valueh, &size);
  if (r == NULL)
    return make_error ("hivex_value_value");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_initrd_cat (ETERM *message)
{
  CLEANUP_FREE char *initrdpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    return make_error ("initrd_cat");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_initrd_list (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    return make_error ("initrd_list");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_inotify_add_watch (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int mask = get_int (ARG (1));
  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    return make_error ("inotify_add_watch");

  return erl_mk_longlong (r);
}

static ETERM *
run_inotify_close (ETERM *message)
{
  int r;

  r = guestfs_inotify_close (g);
  if (r == -1)
    return make_error ("inotify_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inotify_files (ETERM *message)
{
  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    return make_error ("inotify_files");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_inotify_init (ETERM *message)
{
  int maxevents = get_int (ARG (0));
  int r;

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    return make_error ("inotify_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inotify_read (ETERM *message)
{
  struct guestfs_inotify_event_list *r;

  r = guestfs_inotify_read (g);
  if (r == NULL)
    return make_error ("inotify_read");

  ETERM *rt = make_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
  return rt;
}

static ETERM *
run_inotify_rm_watch (ETERM *message)
{
  int wd = get_int (ARG (0));
  int r;

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    return make_error ("inotify_rm_watch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_inspect_get_arch (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL)
    return make_error ("inspect_get_arch");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_distro (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL)
    return make_error ("inspect_get_distro");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_drive_mappings (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL)
    return make_error ("inspect_get_drive_mappings");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_inspect_get_filesystems (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_filesystems (g, root);
  if (r == NULL)
    return make_error ("inspect_get_filesystems");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_inspect_get_format (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_format (g, root);
  if (r == NULL)
    return make_error ("inspect_get_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_hostname (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL)
    return make_error ("inspect_get_hostname");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_icon (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));

  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "favicon")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      optargs_s.favicon = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "highquality")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      optargs_s.highquality = get_bool (hd_value);
    }
    else
      return unknown_optarg ("inspect_get_icon", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char *r;
  size_t size;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL)
    return make_error ("inspect_get_icon");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_major_version (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1)
    return make_error ("inspect_get_major_version");

  return erl_mk_int (r);
}

static ETERM *
run_inspect_get_minor_version (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1)
    return make_error ("inspect_get_minor_version");

  return erl_mk_int (r);
}

static ETERM *
run_inspect_get_mountpoints (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL)
    return make_error ("inspect_get_mountpoints");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_inspect_get_package_format (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL)
    return make_error ("inspect_get_package_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_package_management (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL)
    return make_error ("inspect_get_package_management");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_product_name (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL)
    return make_error ("inspect_get_product_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_product_variant (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL)
    return make_error ("inspect_get_product_variant");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_roots (ETERM *message)
{
  char **r;

  r = guestfs_inspect_get_roots (g);
  if (r == NULL)
    return make_error ("inspect_get_roots");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_inspect_get_type (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_type (g, root);
  if (r == NULL)
    return make_error ("inspect_get_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_windows_current_control_set (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL)
    return make_error ("inspect_get_windows_current_control_set");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_get_windows_systemroot (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL)
    return make_error ("inspect_get_windows_systemroot");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_inspect_is_live (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_live (g, root);
  if (r == -1)
    return make_error ("inspect_is_live");

  return make_bool (r);
}

static ETERM *
run_inspect_is_multipart (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1)
    return make_error ("inspect_is_multipart");

  return make_bool (r);
}

static ETERM *
run_inspect_is_netinst (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1)
    return make_error ("inspect_is_netinst");

  return make_bool (r);
}

static ETERM *
run_inspect_list_applications (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  struct guestfs_application_list *r;

  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL)
    return make_error ("inspect_list_applications");

  ETERM *rt = make_application_list (r);
  guestfs_free_application_list (r);
  return rt;
}

static ETERM *
run_inspect_list_applications2 (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  struct guestfs_application2_list *r;

  r = guestfs_inspect_list_applications2 (g, root);
  if (r == NULL)
    return make_error ("inspect_list_applications2");

  ETERM *rt = make_application2_list (r);
  guestfs_free_application2_list (r);
  return rt;
}

static ETERM *
run_inspect_os (ETERM *message)
{
  char **r;

  r = guestfs_inspect_os (g);
  if (r == NULL)
    return make_error ("inspect_os");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_internal_test (ETERM *message)
{
  CLEANUP_FREE char *str = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *optstr;
  if (atom_equals (ARG (1), "undefined"))
    optstr = NULL;
  else
    optstr = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE_STRING_LIST char **strlist = get_string_list (ARG (2));
  int b = get_bool (ARG (3));
  int integer = get_int (ARG (4));
  int64_t integer64 = get_int64 (ARG (5));
  CLEANUP_FREE char *filein = erl_iolist_to_string (ARG (6));
  CLEANUP_FREE char *fileout = erl_iolist_to_string (ARG (7));
  ETERM *bufferin_bin = erl_iolist_to_binary (ARG (8));
  const void *bufferin = ERL_BIN_PTR (bufferin_bin);
  size_t bufferin_size = ERL_BIN_SIZE (bufferin_bin);

  struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (9);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "obool")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
      optargs_s.obool = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
      optargs_s.oint = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint64")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
      optargs_s.oint64 = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "ostring")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
      optargs_s.ostring = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "ostringlist")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
      optargs_s.ostringlist = get_string_list (hd_value);
    }
    else
      return unknown_optarg ("internal_test", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  if ((optargs_s.bitmask & GUESTFS_INTERNAL_TEST_OSTRING_BITMASK))
    free ((char *) optargs_s.ostring);
  if ((optargs_s.bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK))
    guestfs___free_string_list ((char **) optargs_s.ostringlist);
  if (r == -1)
    return make_error ("internal_test");

  return erl_mk_atom ("ok");
}

static ETERM *
run_internal_test_63_optargs (ETERM *message)
{

  struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "opt1")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
      optargs_s.opt1 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt2")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
      optargs_s.opt2 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt3")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
      optargs_s.opt3 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt4")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
      optargs_s.opt4 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt5")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
      optargs_s.opt5 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt6")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
      optargs_s.opt6 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt7")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
      optargs_s.opt7 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt8")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
      optargs_s.opt8 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt9")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
      optargs_s.opt9 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt10")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
      optargs_s.opt10 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt11")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
      optargs_s.opt11 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt12")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
      optargs_s.opt12 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt13")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
      optargs_s.opt13 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt14")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
      optargs_s.opt14 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt15")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
      optargs_s.opt15 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt16")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
      optargs_s.opt16 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt17")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
      optargs_s.opt17 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt18")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
      optargs_s.opt18 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt19")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
      optargs_s.opt19 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt20")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
      optargs_s.opt20 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt21")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
      optargs_s.opt21 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt22")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
      optargs_s.opt22 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt23")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
      optargs_s.opt23 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt24")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
      optargs_s.opt24 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt25")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
      optargs_s.opt25 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt26")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
      optargs_s.opt26 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt27")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
      optargs_s.opt27 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt28")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
      optargs_s.opt28 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt29")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
      optargs_s.opt29 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt30")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
      optargs_s.opt30 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt31")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
      optargs_s.opt31 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt32")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
      optargs_s.opt32 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt33")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
      optargs_s.opt33 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt34")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
      optargs_s.opt34 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt35")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
      optargs_s.opt35 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt36")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
      optargs_s.opt36 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt37")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
      optargs_s.opt37 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt38")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
      optargs_s.opt38 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt39")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
      optargs_s.opt39 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt40")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
      optargs_s.opt40 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt41")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
      optargs_s.opt41 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt42")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
      optargs_s.opt42 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt43")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
      optargs_s.opt43 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt44")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
      optargs_s.opt44 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt45")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
      optargs_s.opt45 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt46")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
      optargs_s.opt46 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt47")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
      optargs_s.opt47 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt48")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
      optargs_s.opt48 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt49")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
      optargs_s.opt49 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt50")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
      optargs_s.opt50 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt51")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
      optargs_s.opt51 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt52")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
      optargs_s.opt52 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt53")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
      optargs_s.opt53 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt54")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
      optargs_s.opt54 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt55")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
      optargs_s.opt55 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt56")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
      optargs_s.opt56 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt57")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
      optargs_s.opt57 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt58")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
      optargs_s.opt58 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt59")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
      optargs_s.opt59 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt60")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
      optargs_s.opt60 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt61")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
      optargs_s.opt61 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt62")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
      optargs_s.opt62 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt63")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
      optargs_s.opt63 = get_int (hd_value);
    }
    else
      return unknown_optarg ("internal_test_63_optargs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_63_optargs_argv (g, optargs);
  if (r == -1)
    return make_error ("internal_test_63_optargs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_internal_test_close_output (ETERM *message)
{
  int r;

  r = guestfs_internal_test_close_output (g);
  if (r == -1)
    return make_error ("internal_test_close_output");

  return erl_mk_atom ("ok");
}

static ETERM *
run_internal_test_only_optargs (ETERM *message)
{

  struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "test")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
      optargs_s.test = get_int (hd_value);
    }
    else
      return unknown_optarg ("internal_test_only_optargs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_only_optargs_argv (g, optargs);
  if (r == -1)
    return make_error ("internal_test_only_optargs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_internal_test_rbool (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_rbool (g, val);
  if (r == -1)
    return make_error ("internal_test_rbool");

  return make_bool (r);
}

static ETERM *
run_internal_test_rboolerr (ETERM *message)
{
  int r;

  r = guestfs_internal_test_rboolerr (g);
  if (r == -1)
    return make_error ("internal_test_rboolerr");

  return make_bool (r);
}

static ETERM *
run_internal_test_rbufferout (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferout (g, val, &size);
  if (r == NULL)
    return make_error ("internal_test_rbufferout");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_internal_test_rbufferouterr (ETERM *message)
{
  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferouterr (g, &size);
  if (r == NULL)
    return make_error ("internal_test_rbufferouterr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_internal_test_rconstoptstring (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_internal_test_rconstoptstring (g, val);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_internal_test_rconstoptstringerr (ETERM *message)
{
  const char *r;

  r = guestfs_internal_test_rconstoptstringerr (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

static ETERM *
run_internal_test_rconststring (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_internal_test_rconststring (g, val);
  if (r == NULL)
    return make_error ("internal_test_rconststring");

  return erl_mk_string (r);
}

static ETERM *
run_internal_test_rconststringerr (ETERM *message)
{
  const char *r;

  r = guestfs_internal_test_rconststringerr (g);
  if (r == NULL)
    return make_error ("internal_test_rconststringerr");

  return erl_mk_string (r);
}

static ETERM *
run_internal_test_rhashtable (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_internal_test_rhashtable (g, val);
  if (r == NULL)
    return make_error ("internal_test_rhashtable");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_internal_test_rhashtableerr (ETERM *message)
{
  char **r;

  r = guestfs_internal_test_rhashtableerr (g);
  if (r == NULL)
    return make_error ("internal_test_rhashtableerr");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_internal_test_rint (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_rint (g, val);
  if (r == -1)
    return make_error ("internal_test_rint");

  return erl_mk_int (r);
}

static ETERM *
run_internal_test_rint64 (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_internal_test_rint64 (g, val);
  if (r == -1)
    return make_error ("internal_test_rint64");

  return erl_mk_longlong (r);
}

static ETERM *
run_internal_test_rint64err (ETERM *message)
{
  int64_t r;

  r = guestfs_internal_test_rint64err (g);
  if (r == -1)
    return make_error ("internal_test_rint64err");

  return erl_mk_longlong (r);
}

static ETERM *
run_internal_test_rinterr (ETERM *message)
{
  int r;

  r = guestfs_internal_test_rinterr (g);
  if (r == -1)
    return make_error ("internal_test_rinterr");

  return erl_mk_int (r);
}

static ETERM *
run_internal_test_rstring (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_internal_test_rstring (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstring");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_internal_test_rstringerr (ETERM *message)
{
  char *r;

  r = guestfs_internal_test_rstringerr (g);
  if (r == NULL)
    return make_error ("internal_test_rstringerr");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_internal_test_rstringlist (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_internal_test_rstringlist (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstringlist");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_internal_test_rstringlisterr (ETERM *message)
{
  char **r;

  r = guestfs_internal_test_rstringlisterr (g);
  if (r == NULL)
    return make_error ("internal_test_rstringlisterr");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_internal_test_rstruct (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstruct (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstruct");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

static ETERM *
run_internal_test_rstructerr (ETERM *message)
{
  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstructerr (g);
  if (r == NULL)
    return make_error ("internal_test_rstructerr");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

static ETERM *
run_internal_test_rstructlist (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlist (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstructlist");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_internal_test_rstructlisterr (ETERM *message)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlisterr (g);
  if (r == NULL)
    return make_error ("internal_test_rstructlisterr");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_internal_test_set_output (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_set_output (g, filename);
  if (r == -1)
    return make_error ("internal_test_set_output");

  return erl_mk_atom ("ok");
}

static ETERM *
run_is_blockdev (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_blockdev", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_blockdev");

  return make_bool (r);
}

static ETERM *
run_is_busy (ETERM *message)
{
  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    return make_error ("is_busy");

  return make_bool (r);
}

static ETERM *
run_is_chardev (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_chardev", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_chardev_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_chardev");

  return make_bool (r);
}

static ETERM *
run_is_config (ETERM *message)
{
  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    return make_error ("is_config");

  return make_bool (r);
}

static ETERM *
run_is_dir (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_dir", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_dir_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_dir");

  return make_bool (r);
}

static ETERM *
run_is_fifo (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_fifo", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_fifo_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_fifo");

  return make_bool (r);
}

static ETERM *
run_is_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_file_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_file");

  return make_bool (r);
}

static ETERM *
run_is_launching (ETERM *message)
{
  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    return make_error ("is_launching");

  return make_bool (r);
}

static ETERM *
run_is_lv (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_lv (g, device);
  if (r == -1)
    return make_error ("is_lv");

  return make_bool (r);
}

static ETERM *
run_is_ready (ETERM *message)
{
  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    return make_error ("is_ready");

  return make_bool (r);
}

static ETERM *
run_is_socket (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_socket", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_socket_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_socket");

  return make_bool (r);
}

static ETERM *
run_is_symlink (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_symlink (g, path);
  if (r == -1)
    return make_error ("is_symlink");

  return make_bool (r);
}

static ETERM *
run_is_whole_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_whole_device (g, device);
  if (r == -1)
    return make_error ("is_whole_device");

  return make_bool (r);
}

static ETERM *
run_is_zero (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero (g, path);
  if (r == -1)
    return make_error ("is_zero");

  return make_bool (r);
}

static ETERM *
run_is_zero_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero_device (g, device);
  if (r == -1)
    return make_error ("is_zero_device");

  return make_bool (r);
}

static ETERM *
run_isoinfo (ETERM *message)
{
  CLEANUP_FREE char *isofile = erl_iolist_to_string (ARG (0));
  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo (g, isofile);
  if (r == NULL)
    return make_error ("isoinfo");

  ETERM *rt = make_isoinfo (r);
  guestfs_free_isoinfo (r);
  return rt;
}

static ETERM *
run_isoinfo_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo_device (g, device);
  if (r == NULL)
    return make_error ("isoinfo_device");

  ETERM *rt = make_isoinfo (r);
  guestfs_free_isoinfo (r);
  return rt;
}

static ETERM *
run_journal_close (ETERM *message)
{
  int r;

  r = guestfs_journal_close (g);
  if (r == -1)
    return make_error ("journal_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_journal_get (ETERM *message)
{
  struct guestfs_xattr_list *r;

  r = guestfs_journal_get (g);
  if (r == NULL)
    return make_error ("journal_get");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_journal_get_data_threshold (ETERM *message)
{
  int64_t r;

  r = guestfs_journal_get_data_threshold (g);
  if (r == -1)
    return make_error ("journal_get_data_threshold");

  return erl_mk_longlong (r);
}

static ETERM *
run_journal_next (ETERM *message)
{
  int r;

  r = guestfs_journal_next (g);
  if (r == -1)
    return make_error ("journal_next");

  return make_bool (r);
}

static ETERM *
run_journal_open (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_journal_open (g, directory);
  if (r == -1)
    return make_error ("journal_open");

  return erl_mk_atom ("ok");
}

static ETERM *
run_journal_set_data_threshold (ETERM *message)
{
  int64_t threshold = get_int64 (ARG (0));
  int r;

  r = guestfs_journal_set_data_threshold (g, threshold);
  if (r == -1)
    return make_error ("journal_set_data_threshold");

  return erl_mk_atom ("ok");
}

static ETERM *
run_journal_skip (ETERM *message)
{
  int64_t skip = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_journal_skip (g, skip);
  if (r == -1)
    return make_error ("journal_skip");

  return erl_mk_longlong (r);
}

static ETERM *
run_kill_subprocess (ETERM *message)
{
  int r;

  r = guestfs_kill_subprocess (g);
  if (r == -1)
    return make_error ("kill_subprocess");

  return erl_mk_atom ("ok");
}

static ETERM *
run_launch (ETERM *message)
{
  int r;

  r = guestfs_launch (g);
  if (r == -1)
    return make_error ("launch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lchown (ETERM *message)
{
  int owner = get_int (ARG (0));
  int group = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    return make_error ("lchown");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ldmtool_create_all (ETERM *message)
{
  int r;

  r = guestfs_ldmtool_create_all (g);
  if (r == -1)
    return make_error ("ldmtool_create_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ldmtool_diskgroup_disks (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_disks");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ldmtool_diskgroup_name (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_ldmtool_diskgroup_volumes (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_volumes");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ldmtool_remove_all (ETERM *message)
{
  int r;

  r = guestfs_ldmtool_remove_all (g);
  if (r == -1)
    return make_error ("ldmtool_remove_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ldmtool_scan (ETERM *message)
{
  char **r;

  r = guestfs_ldmtool_scan (g);
  if (r == NULL)
    return make_error ("ldmtool_scan");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ldmtool_scan_devices (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  char **r;

  r = guestfs_ldmtool_scan_devices (g, devices);
  if (r == NULL)
    return make_error ("ldmtool_scan_devices");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ldmtool_volume_hint (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_hint");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_ldmtool_volume_partitions (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_partitions");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ldmtool_volume_type (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_lgetxattr (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL)
    return make_error ("lgetxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_lgetxattrs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
  if (r == NULL)
    return make_error ("lgetxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_list_9p (ETERM *message)
{
  char **r;

  r = guestfs_list_9p (g);
  if (r == NULL)
    return make_error ("list_9p");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_devices (g);
  if (r == NULL)
    return make_error ("list_devices");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_disk_labels (ETERM *message)
{
  char **r;

  r = guestfs_list_disk_labels (g);
  if (r == NULL)
    return make_error ("list_disk_labels");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_list_dm_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_dm_devices (g);
  if (r == NULL)
    return make_error ("list_dm_devices");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_filesystems (ETERM *message)
{
  char **r;

  r = guestfs_list_filesystems (g);
  if (r == NULL)
    return make_error ("list_filesystems");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_list_ldm_partitions (ETERM *message)
{
  char **r;

  r = guestfs_list_ldm_partitions (g);
  if (r == NULL)
    return make_error ("list_ldm_partitions");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_ldm_volumes (ETERM *message)
{
  char **r;

  r = guestfs_list_ldm_volumes (g);
  if (r == NULL)
    return make_error ("list_ldm_volumes");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_md_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_md_devices (g);
  if (r == NULL)
    return make_error ("list_md_devices");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_list_partitions (ETERM *message)
{
  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    return make_error ("list_partitions");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ll (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_ll (g, directory);
  if (r == NULL)
    return make_error ("ll");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_llz (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_llz (g, directory);
  if (r == NULL)
    return make_error ("llz");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_ln (ETERM *message)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    return make_error ("ln");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_f (ETERM *message)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    return make_error ("ln_f");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_s (ETERM *message)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    return make_error ("ln_s");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ln_sf (ETERM *message)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    return make_error ("ln_sf");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lremovexattr (ETERM *message)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    return make_error ("lremovexattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ls (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ls (g, directory);
  if (r == NULL)
    return make_error ("ls");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_ls0 (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filenames = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ls0 (g, dir, filenames);
  if (r == -1)
    return make_error ("ls0");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lsetxattr (ETERM *message)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int vallen = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return make_error ("lsetxattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lstat (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_lstat (g, path);
  if (r == NULL)
    return make_error ("lstat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

static ETERM *
run_lstatlist (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  struct guestfs_stat_list *r;

  r = guestfs_lstatlist (g, path, names);
  if (r == NULL)
    return make_error ("lstatlist");

  ETERM *rt = make_stat_list (r);
  guestfs_free_stat_list (r);
  return rt;
}

static ETERM *
run_luks_add_key (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *newkey = erl_iolist_to_string (ARG (2));
  int keyslot = get_int (ARG (3));
  int r;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1)
    return make_error ("luks_add_key");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_close (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_luks_close (g, device);
  if (r == -1)
    return make_error ("luks_close");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_format (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  int r;

  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1)
    return make_error ("luks_format");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_format_cipher (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  CLEANUP_FREE char *cipher = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1)
    return make_error ("luks_format_cipher");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_kill_slot (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  int r;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1)
    return make_error ("luks_kill_slot");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_open (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1)
    return make_error ("luks_open");

  return erl_mk_atom ("ok");
}

static ETERM *
run_luks_open_ro (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1)
    return make_error ("luks_open_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvcreate (ETERM *message)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (1));
  int mbytes = get_int (ARG (2));
  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    return make_error ("lvcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvcreate_free (ETERM *message)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (1));
  int percent = get_int (ARG (2));
  int r;

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (r == -1)
    return make_error ("lvcreate_free");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_canonical_lv_name (ETERM *message)
{
  CLEANUP_FREE char *lvname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL)
    return make_error ("lvm_canonical_lv_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_lvm_clear_filter (ETERM *message)
{
  int r;

  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    return make_error ("lvm_clear_filter");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_remove_all (ETERM *message)
{
  int r;

  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    return make_error ("lvm_remove_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvm_set_filter (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  int r;

  r = guestfs_lvm_set_filter (g, devices);
  if (r == -1)
    return make_error ("lvm_set_filter");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvremove (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_lvremove (g, device);
  if (r == -1)
    return make_error ("lvremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvrename (ETERM *message)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newlogvol = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    return make_error ("lvrename");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvresize (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int mbytes = get_int (ARG (1));
  int r;

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    return make_error ("lvresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvresize_free (ETERM *message)
{
  CLEANUP_FREE char *lv = erl_iolist_to_string (ARG (0));
  int percent = get_int (ARG (1));
  int r;

  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1)
    return make_error ("lvresize_free");

  return erl_mk_atom ("ok");
}

static ETERM *
run_lvs (ETERM *message)
{
  char **r;

  r = guestfs_lvs (g);
  if (r == NULL)
    return make_error ("lvs");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_lvs_full (ETERM *message)
{
  struct guestfs_lvm_lv_list *r;

  r = guestfs_lvs_full (g);
  if (r == NULL)
    return make_error ("lvs_full");

  ETERM *rt = make_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
  return rt;
}

static ETERM *
run_lvuuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvuuid (g, device);
  if (r == NULL)
    return make_error ("lvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_lxattrlist (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  struct guestfs_xattr_list *r;

  r = guestfs_lxattrlist (g, path, names);
  if (r == NULL)
    return make_error ("lxattrlist");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

static ETERM *
run_max_disks (ETERM *message)
{
  int r;

  r = guestfs_max_disks (g);
  if (r == -1)
    return make_error ("max_disks");

  return erl_mk_int (r);
}

static ETERM *
run_md_create (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (1));

  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "missingbitmap")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      optargs_s.missingbitmap = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "nrdevices")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      optargs_s.nrdevices = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "spare")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      optargs_s.spare = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "chunk")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      optargs_s.chunk = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      optargs_s.level = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("md_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_md_create_argv (g, name, devices, optargs);
  if ((optargs_s.bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK))
    free ((char *) optargs_s.level);
  if (r == -1)
    return make_error ("md_create");

  return erl_mk_atom ("ok");
}

static ETERM *
run_md_detail (ETERM *message)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_md_detail (g, md);
  if (r == NULL)
    return make_error ("md_detail");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_md_stat (ETERM *message)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  struct guestfs_mdstat_list *r;

  r = guestfs_md_stat (g, md);
  if (r == NULL)
    return make_error ("md_stat");

  ETERM *rt = make_mdstat_list (r);
  guestfs_free_mdstat_list (r);
  return rt;
}

static ETERM *
run_md_stop (ETERM *message)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_md_stop (g, md);
  if (r == -1)
    return make_error ("md_stop");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir (g, path);
  if (r == -1)
    return make_error ("mkdir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir_mode (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int mode = get_int (ARG (1));
  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    return make_error ("mkdir_mode");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdir_p (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    return make_error ("mkdir_p");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkdtemp (ETERM *message)
{
  CLEANUP_FREE char *tmpl = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_mkdtemp (g, tmpl);
  if (r == NULL)
    return make_error ("mkdtemp");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_mke2fs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "blockscount")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
      optargs_s.blockscount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "blocksize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "fragsize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
      optargs_s.fragsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "blockspergroup")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
      optargs_s.blockspergroup = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "numberofgroups")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
      optargs_s.numberofgroups = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bytesperinode")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
      optargs_s.bytesperinode = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "inodesize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
      optargs_s.inodesize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "journalsize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
      optargs_s.journalsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "numberofinodes")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
      optargs_s.numberofinodes = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "stridesize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
      optargs_s.stridesize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "stripewidth")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
      optargs_s.stripewidth = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxonlineresize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
      optargs_s.maxonlineresize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockspercentage")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "mmpupdateinterval")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
      optargs_s.mmpupdateinterval = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "journaldevice")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
      optargs_s.journaldevice = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "lastmounteddir")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
      optargs_s.lastmounteddir = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "creatoros")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
      optargs_s.creatoros = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "fstype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
      optargs_s.fstype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "usagetype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
      optargs_s.usagetype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "forcecreate")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
      optargs_s.forcecreate = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "writesbandgrouponly")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
      optargs_s.writesbandgrouponly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyitableinit")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
      optargs_s.lazyitableinit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyjournalinit")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
      optargs_s.lazyjournalinit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "testfs")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
      optargs_s.testfs = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "discard")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
      optargs_s.discard = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "quotatype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
      optargs_s.quotatype = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "extent")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
      optargs_s.extent = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "filetype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
      optargs_s.filetype = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "flexbg")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
      optargs_s.flexbg = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "hasjournal")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
      optargs_s.hasjournal = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "journaldev")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
      optargs_s.journaldev = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "largefile")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
      optargs_s.largefile = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "quota")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
      optargs_s.quota = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "resizeinode")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
      optargs_s.resizeinode = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparsesuper")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
      optargs_s.sparsesuper = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "uninitbg")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
      optargs_s.uninitbg = get_bool (hd_value);
    }
    else
      return unknown_optarg ("mke2fs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mke2fs_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK))
    free ((char *) optargs_s.journaldevice);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK))
    free ((char *) optargs_s.lastmounteddir);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_CREATOROS_BITMASK))
    free ((char *) optargs_s.creatoros);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_FSTYPE_BITMASK))
    free ((char *) optargs_s.fstype);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_USAGETYPE_BITMASK))
    free ((char *) optargs_s.usagetype);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("mke2fs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2fs_J (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *journal = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    return make_error ("mke2fs_J");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2fs_JL (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    return make_error ("mke2fs_JL");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2fs_JU (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    return make_error ("mke2fs_JU");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal (ETERM *message)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    return make_error ("mke2journal");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal_L (ETERM *message)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    return make_error ("mke2journal_L");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mke2journal_U (ETERM *message)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    return make_error ("mke2journal_U");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfifo (ETERM *message)
{
  int mode = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    return make_error ("mkfifo");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));

  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "blocksize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "features")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      optargs_s.features = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "inode")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      optargs_s.inode = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "sectorsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = get_int (hd_value);
    }
    else
      return unknown_optarg ("mkfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK))
    free ((char *) optargs_s.features);
  if (r == -1)
    return make_error ("mkfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs_b (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    return make_error ("mkfs_b");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkfs_btrfs (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));

  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "allocstart")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
      optargs_s.allocstart = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bytecount")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
      optargs_s.bytecount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "datatype")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
      optargs_s.datatype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "leafsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
      optargs_s.leafsize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "metadata")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
      optargs_s.metadata = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "nodesize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
      optargs_s.nodesize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "sectorsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = get_int (hd_value);
    }
    else
      return unknown_optarg ("mkfs_btrfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK))
    free ((char *) optargs_s.datatype);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK))
    free ((char *) optargs_s.metadata);
  if (r == -1)
    return make_error ("mkfs_btrfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mklost_and_found (ETERM *message)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mklost_and_found (g, mountpoint);
  if (r == -1)
    return make_error ("mklost_and_found");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkmountpoint (ETERM *message)
{
  CLEANUP_FREE char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    return make_error ("mkmountpoint");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod (ETERM *message)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod_b (ETERM *message)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod_b");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mknod_c (ETERM *message)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod_c");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mkswap", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkswap_opts_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKSWAP_OPTS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKSWAP_OPTS_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("mkswap");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_L (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    return make_error ("mkswap_L");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_U (ETERM *message)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    return make_error ("mkswap_U");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mkswap_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    return make_error ("mkswap_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mktemp (ETERM *message)
{
  CLEANUP_FREE char *tmpl = erl_iolist_to_string (ARG (0));

  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "suffix")) {
      optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
      optargs_s.suffix = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mktemp", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char *r;

  r = guestfs_mktemp_argv (g, tmpl, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKTEMP_SUFFIX_BITMASK))
    free ((char *) optargs_s.suffix);
  if (r == NULL)
    return make_error ("mktemp");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_modprobe (ETERM *message)
{
  CLEANUP_FREE char *modulename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    return make_error ("modprobe");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount (g, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_9p (ETERM *message)
{
  CLEANUP_FREE char *mounttag = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));

  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "options")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      optargs_s.options = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mount_9p", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if ((optargs_s.bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK))
    free ((char *) optargs_s.options);
  if (r == -1)
    return make_error ("mount_9p");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_local (ETERM *message)
{
  CLEANUP_FREE char *localmountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "options")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      optargs_s.options = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachetimeout")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      optargs_s.cachetimeout = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "debugcalls")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      optargs_s.debugcalls = get_bool (hd_value);
    }
    else
      return unknown_optarg ("mount_local", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  if ((optargs_s.bitmask & GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK))
    free ((char *) optargs_s.options);
  if (r == -1)
    return make_error ("mount_local");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_local_run (ETERM *message)
{
  int r;

  r = guestfs_mount_local_run (g);
  if (r == -1)
    return make_error ("mount_local_run");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_loop (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    return make_error ("mount_loop");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_options (ETERM *message)
{
  CLEANUP_FREE char *options = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mount_options (g, options, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_options");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_ro (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_ro (g, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_ro");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mount_vfs (ETERM *message)
{
  CLEANUP_FREE char *options = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *vfstype = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_vfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_mountpoints (ETERM *message)
{
  char **r;

  r = guestfs_mountpoints (g);
  if (r == NULL)
    return make_error ("mountpoints");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_mounts (ETERM *message)
{
  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    return make_error ("mounts");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_mv (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    return make_error ("mv");

  return erl_mk_atom ("ok");
}

static ETERM *
run_nr_devices (ETERM *message)
{
  int r;

  r = guestfs_nr_devices (g);
  if (r == -1)
    return make_error ("nr_devices");

  return erl_mk_int (r);
}

static ETERM *
run_ntfs_3g_probe (ETERM *message)
{
  int rw = get_bool (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    return make_error ("ntfs_3g_probe");

  return erl_mk_int (r);
}

static ETERM *
run_ntfsclone_in (ETERM *message)
{
  CLEANUP_FREE char *backupfile = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ntfsclone_in (g, backupfile, device);
  if (r == -1)
    return make_error ("ntfsclone_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsclone_out (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *backupfile = erl_iolist_to_string (ARG (1));

  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "metadataonly")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      optargs_s.metadataonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "rescue")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      optargs_s.rescue = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "ignorefscheck")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      optargs_s.ignorefscheck = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "preservetimestamps")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      optargs_s.preservetimestamps = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsclone_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  if (r == -1)
    return make_error ("ntfsclone_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsfix (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "clearbadsectors")) {
      optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
      optargs_s.clearbadsectors = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsfix", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsfix_argv (g, device, optargs);
  if (r == -1)
    return make_error ("ntfsfix");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsresize (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsresize", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1)
    return make_error ("ntfsresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_ntfsresize_size (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1)
    return make_error ("ntfsresize_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_parse_environment (ETERM *message)
{
  int r;

  r = guestfs_parse_environment (g);
  if (r == -1)
    return make_error ("parse_environment");

  return erl_mk_atom ("ok");
}

static ETERM *
run_parse_environment_list (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **environment = get_string_list (ARG (0));
  int r;

  r = guestfs_parse_environment_list (g, environment);
  if (r == -1)
    return make_error ("parse_environment_list");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_add (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *prlogex = erl_iolist_to_string (ARG (1));
  int64_t startsect = get_int64 (ARG (2));
  int64_t endsect = get_int64 (ARG (3));
  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    return make_error ("part_add");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_del (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_del (g, device, partnum);
  if (r == -1)
    return make_error ("part_del");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_disk (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    return make_error ("part_disk");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_get_bootable (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1)
    return make_error ("part_get_bootable");

  return make_bool (r);
}

static ETERM *
run_part_get_gpt_type (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_gpt_type (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_gpt_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_get_mbr_id (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1)
    return make_error ("part_get_mbr_id");

  return erl_mk_int (r);
}

static ETERM *
run_part_get_name (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_name (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_get_parttype (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    return make_error ("part_get_parttype");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_init (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    return make_error ("part_init");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_list (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  if (r == NULL)
    return make_error ("part_list");

  ETERM *rt = make_partition_list (r);
  guestfs_free_partition_list (r);
  return rt;
}

static ETERM *
run_part_set_bootable (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int bootable = get_bool (ARG (2));
  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    return make_error ("part_set_bootable");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_set_gpt_type (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  CLEANUP_FREE char *guid = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (r == -1)
    return make_error ("part_set_gpt_type");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_set_mbr_id (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int idbyte = get_int (ARG (2));
  int r;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1)
    return make_error ("part_set_mbr_id");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_set_name (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    return make_error ("part_set_name");

  return erl_mk_atom ("ok");
}

static ETERM *
run_part_to_dev (ETERM *message)
{
  CLEANUP_FREE char *partition = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_to_dev (g, partition);
  if (r == NULL)
    return make_error ("part_to_dev");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_part_to_partnum (ETERM *message)
{
  CLEANUP_FREE char *partition = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_part_to_partnum (g, partition);
  if (r == -1)
    return make_error ("part_to_partnum");

  return erl_mk_int (r);
}

static ETERM *
run_ping_daemon (ETERM *message)
{
  int r;

  r = guestfs_ping_daemon (g);
  if (r == -1)
    return make_error ("ping_daemon");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pread (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int count = get_int (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL)
    return make_error ("pread");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_pread_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int count = get_int (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL)
    return make_error ("pread_device");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_pvchange_uuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvchange_uuid (g, device);
  if (r == -1)
    return make_error ("pvchange_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvchange_uuid_all (ETERM *message)
{
  int r;

  r = guestfs_pvchange_uuid_all (g);
  if (r == -1)
    return make_error ("pvchange_uuid_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvcreate (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    return make_error ("pvcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvremove (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvremove (g, device);
  if (r == -1)
    return make_error ("pvremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvresize (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvresize (g, device);
  if (r == -1)
    return make_error ("pvresize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvresize_size (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_pvresize_size (g, device, size);
  if (r == -1)
    return make_error ("pvresize_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_pvs (ETERM *message)
{
  char **r;

  r = guestfs_pvs (g);
  if (r == NULL)
    return make_error ("pvs");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_pvs_full (ETERM *message)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_pvs_full (g);
  if (r == NULL)
    return make_error ("pvs_full");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

static ETERM *
run_pvuuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_pvuuid (g, device);
  if (r == NULL)
    return make_error ("pvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_pwrite (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1)
    return make_error ("pwrite");

  return erl_mk_int (r);
}

static ETERM *
run_pwrite_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1)
    return make_error ("pwrite_device");

  return erl_mk_int (r);
}

static ETERM *
run_read_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    return make_error ("read_file");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_read_lines (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_read_lines (g, path);
  if (r == NULL)
    return make_error ("read_lines");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_readdir (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    return make_error ("readdir");

  ETERM *rt = make_dirent_list (r);
  guestfs_free_dirent_list (r);
  return rt;
}

static ETERM *
run_readlink (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_readlink (g, path);
  if (r == NULL)
    return make_error ("readlink");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_readlinklist (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  char **r;

  r = guestfs_readlinklist (g, path, names);
  if (r == NULL)
    return make_error ("readlinklist");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_realpath (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_realpath (g, path);
  if (r == NULL)
    return make_error ("realpath");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_remount (ETERM *message)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
  struct guestfs_remount_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "rw")) {
      optargs_s.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
      optargs_s.rw = get_bool (hd_value);
    }
    else
      return unknown_optarg ("remount", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_remount_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("remount");

  return erl_mk_atom ("ok");
}

static ETERM *
run_remove_drive (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_remove_drive (g, label);
  if (r == -1)
    return make_error ("remove_drive");

  return erl_mk_atom ("ok");
}

static ETERM *
run_removexattr (ETERM *message)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    return make_error ("removexattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rename (ETERM *message)
{
  CLEANUP_FREE char *oldpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newpath = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_rename (g, oldpath, newpath);
  if (r == -1)
    return make_error ("rename");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    return make_error ("resize2fs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs_M (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs_M (g, device);
  if (r == -1)
    return make_error ("resize2fs_M");

  return erl_mk_atom ("ok");
}

static ETERM *
run_resize2fs_size (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1)
    return make_error ("resize2fs_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rm (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm (g, path);
  if (r == -1)
    return make_error ("rm");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rm_f (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm_f (g, path);
  if (r == -1)
    return make_error ("rm_f");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rm_rf (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    return make_error ("rm_rf");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rmdir (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmdir (g, path);
  if (r == -1)
    return make_error ("rmdir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rmmountpoint (ETERM *message)
{
  CLEANUP_FREE char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    return make_error ("rmmountpoint");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rsync (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("rsync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rsync_in (ETERM *message)
{
  CLEANUP_FREE char *remote = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync_in", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  if (r == -1)
    return make_error ("rsync_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_rsync_out (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remote = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  if (r == -1)
    return make_error ("rsync_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    return make_error ("scrub_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_file (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    return make_error ("scrub_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_scrub_freespace (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    return make_error ("scrub_freespace");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_append (ETERM *message)
{
  CLEANUP_FREE char *append;
  if (atom_equals (ARG (0), "undefined"))
    append = NULL;
  else
    append = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_append (g, append);
  if (r == -1)
    return make_error ("set_append");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_attach_method (ETERM *message)
{
  CLEANUP_FREE char *backend = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_attach_method (g, backend);
  if (r == -1)
    return make_error ("set_attach_method");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_autosync (ETERM *message)
{
  int autosync = get_bool (ARG (0));
  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    return make_error ("set_autosync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_backend (ETERM *message)
{
  CLEANUP_FREE char *backend = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_backend (g, backend);
  if (r == -1)
    return make_error ("set_backend");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_backend_settings (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **settings = get_string_list (ARG (0));
  int r;

  r = guestfs_set_backend_settings (g, settings);
  if (r == -1)
    return make_error ("set_backend_settings");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_cachedir (ETERM *message)
{
  CLEANUP_FREE char *cachedir;
  if (atom_equals (ARG (0), "undefined"))
    cachedir = NULL;
  else
    cachedir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_cachedir (g, cachedir);
  if (r == -1)
    return make_error ("set_cachedir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_direct (ETERM *message)
{
  int direct = get_bool (ARG (0));
  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    return make_error ("set_direct");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2attrs (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *attrs = erl_iolist_to_string (ARG (1));

  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "clear")) {
      optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
      optargs_s.clear = get_bool (hd_value);
    }
    else
      return unknown_optarg ("set_e2attrs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
  if (r == -1)
    return make_error ("set_e2attrs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2generation (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t generation = get_int64 (ARG (1));
  int r;

  r = guestfs_set_e2generation (g, file, generation);
  if (r == -1)
    return make_error ("set_e2generation");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2label (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    return make_error ("set_e2label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_e2uuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    return make_error ("set_e2uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_hv (ETERM *message)
{
  CLEANUP_FREE char *hv = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_hv (g, hv);
  if (r == -1)
    return make_error ("set_hv");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_label (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_label (g, mountable, label);
  if (r == -1)
    return make_error ("set_label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_libvirt_requested_credential (ETERM *message)
{
  int index = get_int (ARG (0));
  ETERM *cred_bin = erl_iolist_to_binary (ARG (1));
  const void *cred = ERL_BIN_PTR (cred_bin);
  size_t cred_size = ERL_BIN_SIZE (cred_bin);
  int r;

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  if (r == -1)
    return make_error ("set_libvirt_requested_credential");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_libvirt_supported_credentials (ETERM *message)
{
  CLEANUP_FREE_STRING_LIST char **creds = get_string_list (ARG (0));
  int r;

  r = guestfs_set_libvirt_supported_credentials (g, creds);
  if (r == -1)
    return make_error ("set_libvirt_supported_credentials");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_memsize (ETERM *message)
{
  int memsize = get_int (ARG (0));
  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    return make_error ("set_memsize");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_network (ETERM *message)
{
  int network = get_bool (ARG (0));
  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    return make_error ("set_network");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_path (ETERM *message)
{
  CLEANUP_FREE char *searchpath;
  if (atom_equals (ARG (0), "undefined"))
    searchpath = NULL;
  else
    searchpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    return make_error ("set_path");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_pgroup (ETERM *message)
{
  int pgroup = get_bool (ARG (0));
  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    return make_error ("set_pgroup");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_program (ETERM *message)
{
  CLEANUP_FREE char *program = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_program (g, program);
  if (r == -1)
    return make_error ("set_program");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_qemu (ETERM *message)
{
  CLEANUP_FREE char *hv;
  if (atom_equals (ARG (0), "undefined"))
    hv = NULL;
  else
    hv = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_qemu (g, hv);
  if (r == -1)
    return make_error ("set_qemu");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_recovery_proc (ETERM *message)
{
  int recoveryproc = get_bool (ARG (0));
  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    return make_error ("set_recovery_proc");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_selinux (ETERM *message)
{
  int selinux = get_bool (ARG (0));
  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    return make_error ("set_selinux");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_smp (ETERM *message)
{
  int smp = get_int (ARG (0));
  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    return make_error ("set_smp");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_tmpdir (ETERM *message)
{
  CLEANUP_FREE char *tmpdir;
  if (atom_equals (ARG (0), "undefined"))
    tmpdir = NULL;
  else
    tmpdir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_tmpdir (g, tmpdir);
  if (r == -1)
    return make_error ("set_tmpdir");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_trace (ETERM *message)
{
  int trace = get_bool (ARG (0));
  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    return make_error ("set_trace");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_uuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_uuid (g, device, uuid);
  if (r == -1)
    return make_error ("set_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_set_verbose (ETERM *message)
{
  int verbose = get_bool (ARG (0));
  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    return make_error ("set_verbose");

  return erl_mk_atom ("ok");
}

static ETERM *
run_setcon (ETERM *message)
{
  CLEANUP_FREE char *context = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_setcon (g, context);
  if (r == -1)
    return make_error ("setcon");

  return erl_mk_atom ("ok");
}

static ETERM *
run_setxattr (ETERM *message)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int vallen = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return make_error ("setxattr");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int cyls = get_int (ARG (1));
  int heads = get_int (ARG (2));
  int sectors = get_int (ARG (3));
  CLEANUP_FREE_STRING_LIST char **lines = get_string_list (ARG (4));
  int r;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  if (r == -1)
    return make_error ("sfdisk");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdiskM (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **lines = get_string_list (ARG (1));
  int r;

  r = guestfs_sfdiskM (g, device, lines);
  if (r == -1)
    return make_error ("sfdiskM");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk_N (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int cyls = get_int (ARG (2));
  int heads = get_int (ARG (3));
  int sectors = get_int (ARG (4));
  CLEANUP_FREE char *line = erl_iolist_to_string (ARG (5));
  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    return make_error ("sfdisk_N");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sfdisk_disk_geometry (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    return make_error ("sfdisk_disk_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sfdisk_kernel_geometry (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    return make_error ("sfdisk_kernel_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sfdisk_l (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    return make_error ("sfdisk_l");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sh (ETERM *message)
{
  CLEANUP_FREE char *command = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sh (g, command);
  if (r == NULL)
    return make_error ("sh");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_sh_lines (ETERM *message)
{
  CLEANUP_FREE char *command = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_sh_lines (g, command);
  if (r == NULL)
    return make_error ("sh_lines");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_shutdown (ETERM *message)
{
  int r;

  r = guestfs_shutdown (g);
  if (r == -1)
    return make_error ("shutdown");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sleep (ETERM *message)
{
  int secs = get_int (ARG (0));
  int r;

  r = guestfs_sleep (g, secs);
  if (r == -1)
    return make_error ("sleep");

  return erl_mk_atom ("ok");
}

static ETERM *
run_stat (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_stat (g, path);
  if (r == NULL)
    return make_error ("stat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

static ETERM *
run_statvfs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_statvfs *r;

  r = guestfs_statvfs (g, path);
  if (r == NULL)
    return make_error ("statvfs");

  ETERM *rt = make_statvfs (r);
  guestfs_free_statvfs (r);
  return rt;
}

static ETERM *
run_strings (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_strings (g, path);
  if (r == NULL)
    return make_error ("strings");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_strings_e (ETERM *message)
{
  CLEANUP_FREE char *encoding = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL)
    return make_error ("strings_e");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_swapoff_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    return make_error ("swapoff_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_file (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    return make_error ("swapoff_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_label (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    return make_error ("swapoff_label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapoff_uuid (ETERM *message)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    return make_error ("swapoff_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    return make_error ("swapon_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_file (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    return make_error ("swapon_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_label (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    return make_error ("swapon_label");

  return erl_mk_atom ("ok");
}

static ETERM *
run_swapon_uuid (ETERM *message)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    return make_error ("swapon_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_sync (ETERM *message)
{
  int r;

  r = guestfs_sync (g);
  if (r == -1)
    return make_error ("sync");

  return erl_mk_atom ("ok");
}

static ETERM *
run_syslinux (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "directory")) {
      optargs_s.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
      optargs_s.directory = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("syslinux", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_syslinux_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_SYSLINUX_DIRECTORY_BITMASK))
    free ((char *) optargs_s.directory);
  if (r == -1)
    return make_error ("syslinux");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tail (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tail (g, path);
  if (r == NULL)
    return make_error ("tail");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_tail_n (ETERM *message)
{
  int nrlines = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL)
    return make_error ("tail_n");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_tar_in (ETERM *message)
{
  CLEANUP_FREE char *tarfile = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));

  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("tar_in", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  if ((optargs_s.bitmask & GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if (r == -1)
    return make_error ("tar_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tar_out (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarfile = erl_iolist_to_string (ARG (1));

  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "numericowner")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
      optargs_s.numericowner = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "excludes")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
      optargs_s.excludes = get_string_list (hd_value);
    }
    else
      return unknown_optarg ("tar_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  if ((optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if ((optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK))
    guestfs___free_string_list ((char **) optargs_s.excludes);
  if (r == -1)
    return make_error ("tar_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tgz_in (ETERM *message)
{
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    return make_error ("tgz_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tgz_out (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    return make_error ("tgz_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_touch (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_touch (g, path);
  if (r == -1)
    return make_error ("touch");

  return erl_mk_atom ("ok");
}

static ETERM *
run_truncate (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_truncate (g, path);
  if (r == -1)
    return make_error ("truncate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_truncate_size (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    return make_error ("truncate_size");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tune2fs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxmountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      optargs_s.maxmountcount = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "mountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      optargs_s.mountcount = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "errorbehavior")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      optargs_s.errorbehavior = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "group")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      optargs_s.group = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "intervalbetweenchecks")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      optargs_s.intervalbetweenchecks = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockspercentage")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "lastmounteddirectory")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      optargs_s.lastmounteddirectory = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockscount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      optargs_s.reservedblockscount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "user")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      optargs_s.user = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("tune2fs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tune2fs_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK))
    free ((char *) optargs_s.errorbehavior);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK))
    free ((char *) optargs_s.lastmounteddirectory);
  if (r == -1)
    return make_error ("tune2fs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_tune2fs_l (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    return make_error ("tune2fs_l");

  ETERM *rt = make_table (r);
  guestfs___free_string_list (r);
  return rt;
}

static ETERM *
run_txz_in (ETERM *message)
{
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1)
    return make_error ("txz_in");

  return erl_mk_atom ("ok");
}

static ETERM *
run_txz_out (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1)
    return make_error ("txz_out");

  return erl_mk_atom ("ok");
}

static ETERM *
run_umask (ETERM *message)
{
  int mask = get_int (ARG (0));
  int r;

  r = guestfs_umask (g, mask);
  if (r == -1)
    return make_error ("umask");

  return erl_mk_int (r);
}

static ETERM *
run_umount (ETERM *message)
{
  CLEANUP_FREE char *pathordevice = erl_iolist_to_string (ARG (0));

  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyunmount")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
      optargs_s.lazyunmount = get_bool (hd_value);
    }
    else
      return unknown_optarg ("umount", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  if (r == -1)
    return make_error ("umount");

  return erl_mk_atom ("ok");
}

static ETERM *
run_umount_all (ETERM *message)
{
  int r;

  r = guestfs_umount_all (g);
  if (r == -1)
    return make_error ("umount_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_umount_local (ETERM *message)
{

  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "retry")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
      optargs_s.retry = get_bool (hd_value);
    }
    else
      return unknown_optarg ("umount_local", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_umount_local_argv (g, optargs);
  if (r == -1)
    return make_error ("umount_local");

  return erl_mk_atom ("ok");
}

static ETERM *
run_upload (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    return make_error ("upload");

  return erl_mk_atom ("ok");
}

static ETERM *
run_upload_offset (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1)
    return make_error ("upload_offset");

  return erl_mk_atom ("ok");
}

static ETERM *
run_user_cancel (ETERM *message)
{
  int r;

  r = guestfs_user_cancel (g);
  if (r == -1)
    return make_error ("user_cancel");

  return erl_mk_atom ("ok");
}

static ETERM *
run_utimens (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t atsecs = get_int64 (ARG (1));
  int64_t atnsecs = get_int64 (ARG (2));
  int64_t mtsecs = get_int64 (ARG (3));
  int64_t mtnsecs = get_int64 (ARG (4));
  int r;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    return make_error ("utimens");

  return erl_mk_atom ("ok");
}

static ETERM *
run_utsname (ETERM *message)
{
  struct guestfs_utsname *r;

  r = guestfs_utsname (g);
  if (r == NULL)
    return make_error ("utsname");

  ETERM *rt = make_utsname (r);
  guestfs_free_utsname (r);
  return rt;
}

static ETERM *
run_version (ETERM *message)
{
  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    return make_error ("version");

  ETERM *rt = make_version (r);
  guestfs_free_version (r);
  return rt;
}

static ETERM *
run_vfs_label (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_label (g, mountable);
  if (r == NULL)
    return make_error ("vfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vfs_type (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_type (g, mountable);
  if (r == NULL)
    return make_error ("vfs_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vfs_uuid (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_uuid (g, mountable);
  if (r == NULL)
    return make_error ("vfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_vg_activate (ETERM *message)
{
  int activate = get_bool (ARG (0));
  CLEANUP_FREE_STRING_LIST char **volgroups = get_string_list (ARG (1));
  int r;

  r = guestfs_vg_activate (g, activate, volgroups);
  if (r == -1)
    return make_error ("vg_activate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vg_activate_all (ETERM *message)
{
  int activate = get_bool (ARG (0));
  int r;

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    return make_error ("vg_activate_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgchange_uuid (ETERM *message)
{
  CLEANUP_FREE char *vg = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_vgchange_uuid (g, vg);
  if (r == -1)
    return make_error ("vgchange_uuid");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgchange_uuid_all (ETERM *message)
{
  int r;

  r = guestfs_vgchange_uuid_all (g);
  if (r == -1)
    return make_error ("vgchange_uuid_all");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgcreate (ETERM *message)
{
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **physvols = get_string_list (ARG (1));
  int r;

  r = guestfs_vgcreate (g, volgroup, physvols);
  if (r == -1)
    return make_error ("vgcreate");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vglvuuids (ETERM *message)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL)
    return make_error ("vglvuuids");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_vgmeta (ETERM *message)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_vgmeta (g, vgname, &size);
  if (r == NULL)
    return make_error ("vgmeta");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

static ETERM *
run_vgpvuuids (ETERM *message)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL)
    return make_error ("vgpvuuids");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_vgremove (ETERM *message)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    return make_error ("vgremove");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgrename (ETERM *message)
{
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newvolgroup = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    return make_error ("vgrename");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vgs (ETERM *message)
{
  char **r;

  r = guestfs_vgs (g);
  if (r == NULL)
    return make_error ("vgs");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_vgs_full (ETERM *message)
{
  struct guestfs_lvm_vg_list *r;

  r = guestfs_vgs_full (g);
  if (r == NULL)
    return make_error ("vgs_full");

  ETERM *rt = make_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  return rt;
}

static ETERM *
run_vgscan (ETERM *message)
{
  int r;

  r = guestfs_vgscan (g);
  if (r == -1)
    return make_error ("vgscan");

  return erl_mk_atom ("ok");
}

static ETERM *
run_vguuid (ETERM *message)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vguuid (g, vgname);
  if (r == NULL)
    return make_error ("vguuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_wait_ready (ETERM *message)
{
  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    return make_error ("wait_ready");

  return erl_mk_atom ("ok");
}

static ETERM *
run_wc_c (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_c (g, path);
  if (r == -1)
    return make_error ("wc_c");

  return erl_mk_int (r);
}

static ETERM *
run_wc_l (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_l (g, path);
  if (r == -1)
    return make_error ("wc_l");

  return erl_mk_int (r);
}

static ETERM *
run_wc_w (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_w (g, path);
  if (r == -1)
    return make_error ("wc_w");

  return erl_mk_int (r);
}

static ETERM *
run_wipefs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wipefs (g, device);
  if (r == -1)
    return make_error ("wipefs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_write (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int r;

  r = guestfs_write (g, path, content, content_size);
  if (r == -1)
    return make_error ("write");

  return erl_mk_atom ("ok");
}

static ETERM *
run_write_append (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int r;

  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1)
    return make_error ("write_append");

  return erl_mk_atom ("ok");
}

static ETERM *
run_write_file (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *content = erl_iolist_to_string (ARG (1));
  int size = get_int (ARG (2));
  int r;

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    return make_error ("write_file");

  return erl_mk_atom ("ok");
}

static ETERM *
run_xfs_admin (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "extunwritten")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
      optargs_s.extunwritten = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "imgfile")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
      optargs_s.imgfile = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "v2log")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
      optargs_s.v2log = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "projid32bit")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
      optargs_s.projid32bit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazycounter")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
      optargs_s.lazycounter = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("xfs_admin", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_admin_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("xfs_admin");

  return erl_mk_atom ("ok");
}

static ETERM *
run_xfs_growfs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "datasec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
      optargs_s.datasec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "logsec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
      optargs_s.logsec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtsec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
      optargs_s.rtsec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "datasize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
      optargs_s.datasize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "logsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
      optargs_s.logsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
      optargs_s.rtsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtextsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
      optargs_s.rtextsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxpct")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
      optargs_s.maxpct = get_int (hd_value);
    }
    else
      return unknown_optarg ("xfs_growfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_growfs_argv (g, path, optargs);
  if (r == -1)
    return make_error ("xfs_growfs");

  return erl_mk_atom ("ok");
}

static ETERM *
run_xfs_info (ETERM *message)
{
  CLEANUP_FREE char *pathordevice = erl_iolist_to_string (ARG (0));
  struct guestfs_xfsinfo *r;

  r = guestfs_xfs_info (g, pathordevice);
  if (r == NULL)
    return make_error ("xfs_info");

  ETERM *rt = make_xfsinfo (r);
  guestfs_free_xfsinfo (r);
  return rt;
}

static ETERM *
run_xfs_repair (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "forcelogzero")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
      optargs_s.forcelogzero = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "nomodify")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
      optargs_s.nomodify = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "noprefetch")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
      optargs_s.noprefetch = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "forcegeometry")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
      optargs_s.forcegeometry = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxmem")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
      optargs_s.maxmem = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "ihashsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
      optargs_s.ihashsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bhashsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
      optargs_s.bhashsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "agstride")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
      optargs_s.agstride = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "logdev")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
      optargs_s.logdev = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtdev")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
      optargs_s.rtdev = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("xfs_repair", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_repair_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_XFS_REPAIR_LOGDEV_BITMASK))
    free ((char *) optargs_s.logdev);
  if ((optargs_s.bitmask & GUESTFS_XFS_REPAIR_RTDEV_BITMASK))
    free ((char *) optargs_s.rtdev);
  if (r == -1)
    return make_error ("xfs_repair");

  return erl_mk_int (r);
}

static ETERM *
run_zegrep (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrep (g, regex, path);
  if (r == NULL)
    return make_error ("zegrep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_zegrepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    return make_error ("zegrepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_zero (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero (g, device);
  if (r == -1)
    return make_error ("zero");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zero_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero_device (g, device);
  if (r == -1)
    return make_error ("zero_device");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zero_free_space (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero_free_space (g, directory);
  if (r == -1)
    return make_error ("zero_free_space");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zerofree (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zerofree (g, device);
  if (r == -1)
    return make_error ("zerofree");

  return erl_mk_atom ("ok");
}

static ETERM *
run_zfgrep (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    return make_error ("zfgrep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_zfgrepi (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL)
    return make_error ("zfgrepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_zfile (ETERM *message)
{
  CLEANUP_FREE char *meth = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    return make_error ("zfile");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

static ETERM *
run_zgrep (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrep (g, regex, path);
  if (r == NULL)
    return make_error ("zgrep");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}

static ETERM *
run_zgrepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL)
    return make_error ("zgrepi");

  ETERM *rt = make_string_list (r);
  guestfs___free_string_list (r);

  return rt;
}


ETERM *
dispatch (ETERM *message)
{
  ETERM *fun;

  fun = ERL_TUPLE_ELEMENT (message, 0);

  /* XXX We should use gperf here. */
  if (atom_equals (fun, "acl_delete_def_file"))
    return run_acl_delete_def_file (message);
  else if (atom_equals (fun, "acl_get_file"))
    return run_acl_get_file (message);
  else if (atom_equals (fun, "acl_set_file"))
    return run_acl_set_file (message);
  else if (atom_equals (fun, "add_cdrom"))
    return run_add_cdrom (message);
  else if (atom_equals (fun, "add_domain"))
    return run_add_domain (message);
  else if (atom_equals (fun, "add_drive"))
    return run_add_drive (message);
  else if (atom_equals (fun, "add_drive_ro"))
    return run_add_drive_ro (message);
  else if (atom_equals (fun, "add_drive_ro_with_if"))
    return run_add_drive_ro_with_if (message);
  else if (atom_equals (fun, "add_drive_scratch"))
    return run_add_drive_scratch (message);
  else if (atom_equals (fun, "add_drive_with_if"))
    return run_add_drive_with_if (message);
  else if (atom_equals (fun, "aug_clear"))
    return run_aug_clear (message);
  else if (atom_equals (fun, "aug_close"))
    return run_aug_close (message);
  else if (atom_equals (fun, "aug_defnode"))
    return run_aug_defnode (message);
  else if (atom_equals (fun, "aug_defvar"))
    return run_aug_defvar (message);
  else if (atom_equals (fun, "aug_get"))
    return run_aug_get (message);
  else if (atom_equals (fun, "aug_init"))
    return run_aug_init (message);
  else if (atom_equals (fun, "aug_insert"))
    return run_aug_insert (message);
  else if (atom_equals (fun, "aug_label"))
    return run_aug_label (message);
  else if (atom_equals (fun, "aug_load"))
    return run_aug_load (message);
  else if (atom_equals (fun, "aug_ls"))
    return run_aug_ls (message);
  else if (atom_equals (fun, "aug_match"))
    return run_aug_match (message);
  else if (atom_equals (fun, "aug_mv"))
    return run_aug_mv (message);
  else if (atom_equals (fun, "aug_rm"))
    return run_aug_rm (message);
  else if (atom_equals (fun, "aug_save"))
    return run_aug_save (message);
  else if (atom_equals (fun, "aug_set"))
    return run_aug_set (message);
  else if (atom_equals (fun, "aug_setm"))
    return run_aug_setm (message);
  else if (atom_equals (fun, "available"))
    return run_available (message);
  else if (atom_equals (fun, "available_all_groups"))
    return run_available_all_groups (message);
  else if (atom_equals (fun, "base64_in"))
    return run_base64_in (message);
  else if (atom_equals (fun, "base64_out"))
    return run_base64_out (message);
  else if (atom_equals (fun, "blkid"))
    return run_blkid (message);
  else if (atom_equals (fun, "blockdev_flushbufs"))
    return run_blockdev_flushbufs (message);
  else if (atom_equals (fun, "blockdev_getbsz"))
    return run_blockdev_getbsz (message);
  else if (atom_equals (fun, "blockdev_getro"))
    return run_blockdev_getro (message);
  else if (atom_equals (fun, "blockdev_getsize64"))
    return run_blockdev_getsize64 (message);
  else if (atom_equals (fun, "blockdev_getss"))
    return run_blockdev_getss (message);
  else if (atom_equals (fun, "blockdev_getsz"))
    return run_blockdev_getsz (message);
  else if (atom_equals (fun, "blockdev_rereadpt"))
    return run_blockdev_rereadpt (message);
  else if (atom_equals (fun, "blockdev_setbsz"))
    return run_blockdev_setbsz (message);
  else if (atom_equals (fun, "blockdev_setro"))
    return run_blockdev_setro (message);
  else if (atom_equals (fun, "blockdev_setrw"))
    return run_blockdev_setrw (message);
  else if (atom_equals (fun, "btrfs_device_add"))
    return run_btrfs_device_add (message);
  else if (atom_equals (fun, "btrfs_device_delete"))
    return run_btrfs_device_delete (message);
  else if (atom_equals (fun, "btrfs_filesystem_balance"))
    return run_btrfs_filesystem_balance (message);
  else if (atom_equals (fun, "btrfs_filesystem_resize"))
    return run_btrfs_filesystem_resize (message);
  else if (atom_equals (fun, "btrfs_filesystem_sync"))
    return run_btrfs_filesystem_sync (message);
  else if (atom_equals (fun, "btrfs_fsck"))
    return run_btrfs_fsck (message);
  else if (atom_equals (fun, "btrfs_set_seeding"))
    return run_btrfs_set_seeding (message);
  else if (atom_equals (fun, "btrfs_subvolume_create"))
    return run_btrfs_subvolume_create (message);
  else if (atom_equals (fun, "btrfs_subvolume_delete"))
    return run_btrfs_subvolume_delete (message);
  else if (atom_equals (fun, "btrfs_subvolume_list"))
    return run_btrfs_subvolume_list (message);
  else if (atom_equals (fun, "btrfs_subvolume_set_default"))
    return run_btrfs_subvolume_set_default (message);
  else if (atom_equals (fun, "btrfs_subvolume_snapshot"))
    return run_btrfs_subvolume_snapshot (message);
  else if (atom_equals (fun, "canonical_device_name"))
    return run_canonical_device_name (message);
  else if (atom_equals (fun, "cap_get_file"))
    return run_cap_get_file (message);
  else if (atom_equals (fun, "cap_set_file"))
    return run_cap_set_file (message);
  else if (atom_equals (fun, "case_sensitive_path"))
    return run_case_sensitive_path (message);
  else if (atom_equals (fun, "cat"))
    return run_cat (message);
  else if (atom_equals (fun, "checksum"))
    return run_checksum (message);
  else if (atom_equals (fun, "checksum_device"))
    return run_checksum_device (message);
  else if (atom_equals (fun, "checksums_out"))
    return run_checksums_out (message);
  else if (atom_equals (fun, "chmod"))
    return run_chmod (message);
  else if (atom_equals (fun, "chown"))
    return run_chown (message);
  else if (atom_equals (fun, "command"))
    return run_command (message);
  else if (atom_equals (fun, "command_lines"))
    return run_command_lines (message);
  else if (atom_equals (fun, "compress_device_out"))
    return run_compress_device_out (message);
  else if (atom_equals (fun, "compress_out"))
    return run_compress_out (message);
  else if (atom_equals (fun, "config"))
    return run_config (message);
  else if (atom_equals (fun, "copy_attributes"))
    return run_copy_attributes (message);
  else if (atom_equals (fun, "copy_device_to_device"))
    return run_copy_device_to_device (message);
  else if (atom_equals (fun, "copy_device_to_file"))
    return run_copy_device_to_file (message);
  else if (atom_equals (fun, "copy_file_to_device"))
    return run_copy_file_to_device (message);
  else if (atom_equals (fun, "copy_file_to_file"))
    return run_copy_file_to_file (message);
  else if (atom_equals (fun, "copy_size"))
    return run_copy_size (message);
  else if (atom_equals (fun, "cp"))
    return run_cp (message);
  else if (atom_equals (fun, "cp_a"))
    return run_cp_a (message);
  else if (atom_equals (fun, "cp_r"))
    return run_cp_r (message);
  else if (atom_equals (fun, "dd"))
    return run_dd (message);
  else if (atom_equals (fun, "debug"))
    return run_debug (message);
  else if (atom_equals (fun, "debug_drives"))
    return run_debug_drives (message);
  else if (atom_equals (fun, "debug_upload"))
    return run_debug_upload (message);
  else if (atom_equals (fun, "device_index"))
    return run_device_index (message);
  else if (atom_equals (fun, "df"))
    return run_df (message);
  else if (atom_equals (fun, "df_h"))
    return run_df_h (message);
  else if (atom_equals (fun, "disk_create"))
    return run_disk_create (message);
  else if (atom_equals (fun, "disk_format"))
    return run_disk_format (message);
  else if (atom_equals (fun, "disk_has_backing_file"))
    return run_disk_has_backing_file (message);
  else if (atom_equals (fun, "disk_virtual_size"))
    return run_disk_virtual_size (message);
  else if (atom_equals (fun, "dmesg"))
    return run_dmesg (message);
  else if (atom_equals (fun, "download"))
    return run_download (message);
  else if (atom_equals (fun, "download_offset"))
    return run_download_offset (message);
  else if (atom_equals (fun, "drop_caches"))
    return run_drop_caches (message);
  else if (atom_equals (fun, "du"))
    return run_du (message);
  else if (atom_equals (fun, "e2fsck"))
    return run_e2fsck (message);
  else if (atom_equals (fun, "e2fsck_f"))
    return run_e2fsck_f (message);
  else if (atom_equals (fun, "echo_daemon"))
    return run_echo_daemon (message);
  else if (atom_equals (fun, "egrep"))
    return run_egrep (message);
  else if (atom_equals (fun, "egrepi"))
    return run_egrepi (message);
  else if (atom_equals (fun, "equal"))
    return run_equal (message);
  else if (atom_equals (fun, "exists"))
    return run_exists (message);
  else if (atom_equals (fun, "extlinux"))
    return run_extlinux (message);
  else if (atom_equals (fun, "fallocate"))
    return run_fallocate (message);
  else if (atom_equals (fun, "fallocate64"))
    return run_fallocate64 (message);
  else if (atom_equals (fun, "feature_available"))
    return run_feature_available (message);
  else if (atom_equals (fun, "fgrep"))
    return run_fgrep (message);
  else if (atom_equals (fun, "fgrepi"))
    return run_fgrepi (message);
  else if (atom_equals (fun, "file"))
    return run_file (message);
  else if (atom_equals (fun, "file_architecture"))
    return run_file_architecture (message);
  else if (atom_equals (fun, "filesize"))
    return run_filesize (message);
  else if (atom_equals (fun, "filesystem_available"))
    return run_filesystem_available (message);
  else if (atom_equals (fun, "fill"))
    return run_fill (message);
  else if (atom_equals (fun, "fill_dir"))
    return run_fill_dir (message);
  else if (atom_equals (fun, "fill_pattern"))
    return run_fill_pattern (message);
  else if (atom_equals (fun, "find"))
    return run_find (message);
  else if (atom_equals (fun, "find0"))
    return run_find0 (message);
  else if (atom_equals (fun, "findfs_label"))
    return run_findfs_label (message);
  else if (atom_equals (fun, "findfs_uuid"))
    return run_findfs_uuid (message);
  else if (atom_equals (fun, "fsck"))
    return run_fsck (message);
  else if (atom_equals (fun, "fstrim"))
    return run_fstrim (message);
  else if (atom_equals (fun, "get_append"))
    return run_get_append (message);
  else if (atom_equals (fun, "get_attach_method"))
    return run_get_attach_method (message);
  else if (atom_equals (fun, "get_autosync"))
    return run_get_autosync (message);
  else if (atom_equals (fun, "get_backend"))
    return run_get_backend (message);
  else if (atom_equals (fun, "get_backend_settings"))
    return run_get_backend_settings (message);
  else if (atom_equals (fun, "get_cachedir"))
    return run_get_cachedir (message);
  else if (atom_equals (fun, "get_direct"))
    return run_get_direct (message);
  else if (atom_equals (fun, "get_e2attrs"))
    return run_get_e2attrs (message);
  else if (atom_equals (fun, "get_e2generation"))
    return run_get_e2generation (message);
  else if (atom_equals (fun, "get_e2label"))
    return run_get_e2label (message);
  else if (atom_equals (fun, "get_e2uuid"))
    return run_get_e2uuid (message);
  else if (atom_equals (fun, "get_hv"))
    return run_get_hv (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_challenge"))
    return run_get_libvirt_requested_credential_challenge (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_defresult"))
    return run_get_libvirt_requested_credential_defresult (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_prompt"))
    return run_get_libvirt_requested_credential_prompt (message);
  else if (atom_equals (fun, "get_libvirt_requested_credentials"))
    return run_get_libvirt_requested_credentials (message);
  else if (atom_equals (fun, "get_memsize"))
    return run_get_memsize (message);
  else if (atom_equals (fun, "get_network"))
    return run_get_network (message);
  else if (atom_equals (fun, "get_path"))
    return run_get_path (message);
  else if (atom_equals (fun, "get_pgroup"))
    return run_get_pgroup (message);
  else if (atom_equals (fun, "get_pid"))
    return run_get_pid (message);
  else if (atom_equals (fun, "get_program"))
    return run_get_program (message);
  else if (atom_equals (fun, "get_qemu"))
    return run_get_qemu (message);
  else if (atom_equals (fun, "get_recovery_proc"))
    return run_get_recovery_proc (message);
  else if (atom_equals (fun, "get_selinux"))
    return run_get_selinux (message);
  else if (atom_equals (fun, "get_smp"))
    return run_get_smp (message);
  else if (atom_equals (fun, "get_state"))
    return run_get_state (message);
  else if (atom_equals (fun, "get_tmpdir"))
    return run_get_tmpdir (message);
  else if (atom_equals (fun, "get_trace"))
    return run_get_trace (message);
  else if (atom_equals (fun, "get_umask"))
    return run_get_umask (message);
  else if (atom_equals (fun, "get_verbose"))
    return run_get_verbose (message);
  else if (atom_equals (fun, "getcon"))
    return run_getcon (message);
  else if (atom_equals (fun, "getxattr"))
    return run_getxattr (message);
  else if (atom_equals (fun, "getxattrs"))
    return run_getxattrs (message);
  else if (atom_equals (fun, "glob_expand"))
    return run_glob_expand (message);
  else if (atom_equals (fun, "grep"))
    return run_grep (message);
  else if (atom_equals (fun, "grepi"))
    return run_grepi (message);
  else if (atom_equals (fun, "grub_install"))
    return run_grub_install (message);
  else if (atom_equals (fun, "head"))
    return run_head (message);
  else if (atom_equals (fun, "head_n"))
    return run_head_n (message);
  else if (atom_equals (fun, "hexdump"))
    return run_hexdump (message);
  else if (atom_equals (fun, "hivex_close"))
    return run_hivex_close (message);
  else if (atom_equals (fun, "hivex_commit"))
    return run_hivex_commit (message);
  else if (atom_equals (fun, "hivex_node_add_child"))
    return run_hivex_node_add_child (message);
  else if (atom_equals (fun, "hivex_node_children"))
    return run_hivex_node_children (message);
  else if (atom_equals (fun, "hivex_node_delete_child"))
    return run_hivex_node_delete_child (message);
  else if (atom_equals (fun, "hivex_node_get_child"))
    return run_hivex_node_get_child (message);
  else if (atom_equals (fun, "hivex_node_get_value"))
    return run_hivex_node_get_value (message);
  else if (atom_equals (fun, "hivex_node_name"))
    return run_hivex_node_name (message);
  else if (atom_equals (fun, "hivex_node_parent"))
    return run_hivex_node_parent (message);
  else if (atom_equals (fun, "hivex_node_set_value"))
    return run_hivex_node_set_value (message);
  else if (atom_equals (fun, "hivex_node_values"))
    return run_hivex_node_values (message);
  else if (atom_equals (fun, "hivex_open"))
    return run_hivex_open (message);
  else if (atom_equals (fun, "hivex_root"))
    return run_hivex_root (message);
  else if (atom_equals (fun, "hivex_value_key"))
    return run_hivex_value_key (message);
  else if (atom_equals (fun, "hivex_value_type"))
    return run_hivex_value_type (message);
  else if (atom_equals (fun, "hivex_value_utf8"))
    return run_hivex_value_utf8 (message);
  else if (atom_equals (fun, "hivex_value_value"))
    return run_hivex_value_value (message);
  else if (atom_equals (fun, "initrd_cat"))
    return run_initrd_cat (message);
  else if (atom_equals (fun, "initrd_list"))
    return run_initrd_list (message);
  else if (atom_equals (fun, "inotify_add_watch"))
    return run_inotify_add_watch (message);
  else if (atom_equals (fun, "inotify_close"))
    return run_inotify_close (message);
  else if (atom_equals (fun, "inotify_files"))
    return run_inotify_files (message);
  else if (atom_equals (fun, "inotify_init"))
    return run_inotify_init (message);
  else if (atom_equals (fun, "inotify_read"))
    return run_inotify_read (message);
  else if (atom_equals (fun, "inotify_rm_watch"))
    return run_inotify_rm_watch (message);
  else if (atom_equals (fun, "inspect_get_arch"))
    return run_inspect_get_arch (message);
  else if (atom_equals (fun, "inspect_get_distro"))
    return run_inspect_get_distro (message);
  else if (atom_equals (fun, "inspect_get_drive_mappings"))
    return run_inspect_get_drive_mappings (message);
  else if (atom_equals (fun, "inspect_get_filesystems"))
    return run_inspect_get_filesystems (message);
  else if (atom_equals (fun, "inspect_get_format"))
    return run_inspect_get_format (message);
  else if (atom_equals (fun, "inspect_get_hostname"))
    return run_inspect_get_hostname (message);
  else if (atom_equals (fun, "inspect_get_icon"))
    return run_inspect_get_icon (message);
  else if (atom_equals (fun, "inspect_get_major_version"))
    return run_inspect_get_major_version (message);
  else if (atom_equals (fun, "inspect_get_minor_version"))
    return run_inspect_get_minor_version (message);
  else if (atom_equals (fun, "inspect_get_mountpoints"))
    return run_inspect_get_mountpoints (message);
  else if (atom_equals (fun, "inspect_get_package_format"))
    return run_inspect_get_package_format (message);
  else if (atom_equals (fun, "inspect_get_package_management"))
    return run_inspect_get_package_management (message);
  else if (atom_equals (fun, "inspect_get_product_name"))
    return run_inspect_get_product_name (message);
  else if (atom_equals (fun, "inspect_get_product_variant"))
    return run_inspect_get_product_variant (message);
  else if (atom_equals (fun, "inspect_get_roots"))
    return run_inspect_get_roots (message);
  else if (atom_equals (fun, "inspect_get_type"))
    return run_inspect_get_type (message);
  else if (atom_equals (fun, "inspect_get_windows_current_control_set"))
    return run_inspect_get_windows_current_control_set (message);
  else if (atom_equals (fun, "inspect_get_windows_systemroot"))
    return run_inspect_get_windows_systemroot (message);
  else if (atom_equals (fun, "inspect_is_live"))
    return run_inspect_is_live (message);
  else if (atom_equals (fun, "inspect_is_multipart"))
    return run_inspect_is_multipart (message);
  else if (atom_equals (fun, "inspect_is_netinst"))
    return run_inspect_is_netinst (message);
  else if (atom_equals (fun, "inspect_list_applications"))
    return run_inspect_list_applications (message);
  else if (atom_equals (fun, "inspect_list_applications2"))
    return run_inspect_list_applications2 (message);
  else if (atom_equals (fun, "inspect_os"))
    return run_inspect_os (message);
  else if (atom_equals (fun, "internal_test"))
    return run_internal_test (message);
  else if (atom_equals (fun, "internal_test_63_optargs"))
    return run_internal_test_63_optargs (message);
  else if (atom_equals (fun, "internal_test_close_output"))
    return run_internal_test_close_output (message);
  else if (atom_equals (fun, "internal_test_only_optargs"))
    return run_internal_test_only_optargs (message);
  else if (atom_equals (fun, "internal_test_rbool"))
    return run_internal_test_rbool (message);
  else if (atom_equals (fun, "internal_test_rboolerr"))
    return run_internal_test_rboolerr (message);
  else if (atom_equals (fun, "internal_test_rbufferout"))
    return run_internal_test_rbufferout (message);
  else if (atom_equals (fun, "internal_test_rbufferouterr"))
    return run_internal_test_rbufferouterr (message);
  else if (atom_equals (fun, "internal_test_rconstoptstring"))
    return run_internal_test_rconstoptstring (message);
  else if (atom_equals (fun, "internal_test_rconstoptstringerr"))
    return run_internal_test_rconstoptstringerr (message);
  else if (atom_equals (fun, "internal_test_rconststring"))
    return run_internal_test_rconststring (message);
  else if (atom_equals (fun, "internal_test_rconststringerr"))
    return run_internal_test_rconststringerr (message);
  else if (atom_equals (fun, "internal_test_rhashtable"))
    return run_internal_test_rhashtable (message);
  else if (atom_equals (fun, "internal_test_rhashtableerr"))
    return run_internal_test_rhashtableerr (message);
  else if (atom_equals (fun, "internal_test_rint"))
    return run_internal_test_rint (message);
  else if (atom_equals (fun, "internal_test_rint64"))
    return run_internal_test_rint64 (message);
  else if (atom_equals (fun, "internal_test_rint64err"))
    return run_internal_test_rint64err (message);
  else if (atom_equals (fun, "internal_test_rinterr"))
    return run_internal_test_rinterr (message);
  else if (atom_equals (fun, "internal_test_rstring"))
    return run_internal_test_rstring (message);
  else if (atom_equals (fun, "internal_test_rstringerr"))
    return run_internal_test_rstringerr (message);
  else if (atom_equals (fun, "internal_test_rstringlist"))
    return run_internal_test_rstringlist (message);
  else if (atom_equals (fun, "internal_test_rstringlisterr"))
    return run_internal_test_rstringlisterr (message);
  else if (atom_equals (fun, "internal_test_rstruct"))
    return run_internal_test_rstruct (message);
  else if (atom_equals (fun, "internal_test_rstructerr"))
    return run_internal_test_rstructerr (message);
  else if (atom_equals (fun, "internal_test_rstructlist"))
    return run_internal_test_rstructlist (message);
  else if (atom_equals (fun, "internal_test_rstructlisterr"))
    return run_internal_test_rstructlisterr (message);
  else if (atom_equals (fun, "internal_test_set_output"))
    return run_internal_test_set_output (message);
  else if (atom_equals (fun, "is_blockdev"))
    return run_is_blockdev (message);
  else if (atom_equals (fun, "is_busy"))
    return run_is_busy (message);
  else if (atom_equals (fun, "is_chardev"))
    return run_is_chardev (message);
  else if (atom_equals (fun, "is_config"))
    return run_is_config (message);
  else if (atom_equals (fun, "is_dir"))
    return run_is_dir (message);
  else if (atom_equals (fun, "is_fifo"))
    return run_is_fifo (message);
  else if (atom_equals (fun, "is_file"))
    return run_is_file (message);
  else if (atom_equals (fun, "is_launching"))
    return run_is_launching (message);
  else if (atom_equals (fun, "is_lv"))
    return run_is_lv (message);
  else if (atom_equals (fun, "is_ready"))
    return run_is_ready (message);
  else if (atom_equals (fun, "is_socket"))
    return run_is_socket (message);
  else if (atom_equals (fun, "is_symlink"))
    return run_is_symlink (message);
  else if (atom_equals (fun, "is_whole_device"))
    return run_is_whole_device (message);
  else if (atom_equals (fun, "is_zero"))
    return run_is_zero (message);
  else if (atom_equals (fun, "is_zero_device"))
    return run_is_zero_device (message);
  else if (atom_equals (fun, "isoinfo"))
    return run_isoinfo (message);
  else if (atom_equals (fun, "isoinfo_device"))
    return run_isoinfo_device (message);
  else if (atom_equals (fun, "journal_close"))
    return run_journal_close (message);
  else if (atom_equals (fun, "journal_get"))
    return run_journal_get (message);
  else if (atom_equals (fun, "journal_get_data_threshold"))
    return run_journal_get_data_threshold (message);
  else if (atom_equals (fun, "journal_next"))
    return run_journal_next (message);
  else if (atom_equals (fun, "journal_open"))
    return run_journal_open (message);
  else if (atom_equals (fun, "journal_set_data_threshold"))
    return run_journal_set_data_threshold (message);
  else if (atom_equals (fun, "journal_skip"))
    return run_journal_skip (message);
  else if (atom_equals (fun, "kill_subprocess"))
    return run_kill_subprocess (message);
  else if (atom_equals (fun, "launch"))
    return run_launch (message);
  else if (atom_equals (fun, "lchown"))
    return run_lchown (message);
  else if (atom_equals (fun, "ldmtool_create_all"))
    return run_ldmtool_create_all (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_disks"))
    return run_ldmtool_diskgroup_disks (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_name"))
    return run_ldmtool_diskgroup_name (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_volumes"))
    return run_ldmtool_diskgroup_volumes (message);
  else if (atom_equals (fun, "ldmtool_remove_all"))
    return run_ldmtool_remove_all (message);
  else if (atom_equals (fun, "ldmtool_scan"))
    return run_ldmtool_scan (message);
  else if (atom_equals (fun, "ldmtool_scan_devices"))
    return run_ldmtool_scan_devices (message);
  else if (atom_equals (fun, "ldmtool_volume_hint"))
    return run_ldmtool_volume_hint (message);
  else if (atom_equals (fun, "ldmtool_volume_partitions"))
    return run_ldmtool_volume_partitions (message);
  else if (atom_equals (fun, "ldmtool_volume_type"))
    return run_ldmtool_volume_type (message);
  else if (atom_equals (fun, "lgetxattr"))
    return run_lgetxattr (message);
  else if (atom_equals (fun, "lgetxattrs"))
    return run_lgetxattrs (message);
  else if (atom_equals (fun, "list_9p"))
    return run_list_9p (message);
  else if (atom_equals (fun, "list_devices"))
    return run_list_devices (message);
  else if (atom_equals (fun, "list_disk_labels"))
    return run_list_disk_labels (message);
  else if (atom_equals (fun, "list_dm_devices"))
    return run_list_dm_devices (message);
  else if (atom_equals (fun, "list_filesystems"))
    return run_list_filesystems (message);
  else if (atom_equals (fun, "list_ldm_partitions"))
    return run_list_ldm_partitions (message);
  else if (atom_equals (fun, "list_ldm_volumes"))
    return run_list_ldm_volumes (message);
  else if (atom_equals (fun, "list_md_devices"))
    return run_list_md_devices (message);
  else if (atom_equals (fun, "list_partitions"))
    return run_list_partitions (message);
  else if (atom_equals (fun, "ll"))
    return run_ll (message);
  else if (atom_equals (fun, "llz"))
    return run_llz (message);
  else if (atom_equals (fun, "ln"))
    return run_ln (message);
  else if (atom_equals (fun, "ln_f"))
    return run_ln_f (message);
  else if (atom_equals (fun, "ln_s"))
    return run_ln_s (message);
  else if (atom_equals (fun, "ln_sf"))
    return run_ln_sf (message);
  else if (atom_equals (fun, "lremovexattr"))
    return run_lremovexattr (message);
  else if (atom_equals (fun, "ls"))
    return run_ls (message);
  else if (atom_equals (fun, "ls0"))
    return run_ls0 (message);
  else if (atom_equals (fun, "lsetxattr"))
    return run_lsetxattr (message);
  else if (atom_equals (fun, "lstat"))
    return run_lstat (message);
  else if (atom_equals (fun, "lstatlist"))
    return run_lstatlist (message);
  else if (atom_equals (fun, "luks_add_key"))
    return run_luks_add_key (message);
  else if (atom_equals (fun, "luks_close"))
    return run_luks_close (message);
  else if (atom_equals (fun, "luks_format"))
    return run_luks_format (message);
  else if (atom_equals (fun, "luks_format_cipher"))
    return run_luks_format_cipher (message);
  else if (atom_equals (fun, "luks_kill_slot"))
    return run_luks_kill_slot (message);
  else if (atom_equals (fun, "luks_open"))
    return run_luks_open (message);
  else if (atom_equals (fun, "luks_open_ro"))
    return run_luks_open_ro (message);
  else if (atom_equals (fun, "lvcreate"))
    return run_lvcreate (message);
  else if (atom_equals (fun, "lvcreate_free"))
    return run_lvcreate_free (message);
  else if (atom_equals (fun, "lvm_canonical_lv_name"))
    return run_lvm_canonical_lv_name (message);
  else if (atom_equals (fun, "lvm_clear_filter"))
    return run_lvm_clear_filter (message);
  else if (atom_equals (fun, "lvm_remove_all"))
    return run_lvm_remove_all (message);
  else if (atom_equals (fun, "lvm_set_filter"))
    return run_lvm_set_filter (message);
  else if (atom_equals (fun, "lvremove"))
    return run_lvremove (message);
  else if (atom_equals (fun, "lvrename"))
    return run_lvrename (message);
  else if (atom_equals (fun, "lvresize"))
    return run_lvresize (message);
  else if (atom_equals (fun, "lvresize_free"))
    return run_lvresize_free (message);
  else if (atom_equals (fun, "lvs"))
    return run_lvs (message);
  else if (atom_equals (fun, "lvs_full"))
    return run_lvs_full (message);
  else if (atom_equals (fun, "lvuuid"))
    return run_lvuuid (message);
  else if (atom_equals (fun, "lxattrlist"))
    return run_lxattrlist (message);
  else if (atom_equals (fun, "max_disks"))
    return run_max_disks (message);
  else if (atom_equals (fun, "md_create"))
    return run_md_create (message);
  else if (atom_equals (fun, "md_detail"))
    return run_md_detail (message);
  else if (atom_equals (fun, "md_stat"))
    return run_md_stat (message);
  else if (atom_equals (fun, "md_stop"))
    return run_md_stop (message);
  else if (atom_equals (fun, "mkdir"))
    return run_mkdir (message);
  else if (atom_equals (fun, "mkdir_mode"))
    return run_mkdir_mode (message);
  else if (atom_equals (fun, "mkdir_p"))
    return run_mkdir_p (message);
  else if (atom_equals (fun, "mkdtemp"))
    return run_mkdtemp (message);
  else if (atom_equals (fun, "mke2fs"))
    return run_mke2fs (message);
  else if (atom_equals (fun, "mke2fs_J"))
    return run_mke2fs_J (message);
  else if (atom_equals (fun, "mke2fs_JL"))
    return run_mke2fs_JL (message);
  else if (atom_equals (fun, "mke2fs_JU"))
    return run_mke2fs_JU (message);
  else if (atom_equals (fun, "mke2journal"))
    return run_mke2journal (message);
  else if (atom_equals (fun, "mke2journal_L"))
    return run_mke2journal_L (message);
  else if (atom_equals (fun, "mke2journal_U"))
    return run_mke2journal_U (message);
  else if (atom_equals (fun, "mkfifo"))
    return run_mkfifo (message);
  else if (atom_equals (fun, "mkfs"))
    return run_mkfs (message);
  else if (atom_equals (fun, "mkfs_b"))
    return run_mkfs_b (message);
  else if (atom_equals (fun, "mkfs_btrfs"))
    return run_mkfs_btrfs (message);
  else if (atom_equals (fun, "mklost_and_found"))
    return run_mklost_and_found (message);
  else if (atom_equals (fun, "mkmountpoint"))
    return run_mkmountpoint (message);
  else if (atom_equals (fun, "mknod"))
    return run_mknod (message);
  else if (atom_equals (fun, "mknod_b"))
    return run_mknod_b (message);
  else if (atom_equals (fun, "mknod_c"))
    return run_mknod_c (message);
  else if (atom_equals (fun, "mkswap"))
    return run_mkswap (message);
  else if (atom_equals (fun, "mkswap_L"))
    return run_mkswap_L (message);
  else if (atom_equals (fun, "mkswap_U"))
    return run_mkswap_U (message);
  else if (atom_equals (fun, "mkswap_file"))
    return run_mkswap_file (message);
  else if (atom_equals (fun, "mktemp"))
    return run_mktemp (message);
  else if (atom_equals (fun, "modprobe"))
    return run_modprobe (message);
  else if (atom_equals (fun, "mount"))
    return run_mount (message);
  else if (atom_equals (fun, "mount_9p"))
    return run_mount_9p (message);
  else if (atom_equals (fun, "mount_local"))
    return run_mount_local (message);
  else if (atom_equals (fun, "mount_local_run"))
    return run_mount_local_run (message);
  else if (atom_equals (fun, "mount_loop"))
    return run_mount_loop (message);
  else if (atom_equals (fun, "mount_options"))
    return run_mount_options (message);
  else if (atom_equals (fun, "mount_ro"))
    return run_mount_ro (message);
  else if (atom_equals (fun, "mount_vfs"))
    return run_mount_vfs (message);
  else if (atom_equals (fun, "mountpoints"))
    return run_mountpoints (message);
  else if (atom_equals (fun, "mounts"))
    return run_mounts (message);
  else if (atom_equals (fun, "mv"))
    return run_mv (message);
  else if (atom_equals (fun, "nr_devices"))
    return run_nr_devices (message);
  else if (atom_equals (fun, "ntfs_3g_probe"))
    return run_ntfs_3g_probe (message);
  else if (atom_equals (fun, "ntfsclone_in"))
    return run_ntfsclone_in (message);
  else if (atom_equals (fun, "ntfsclone_out"))
    return run_ntfsclone_out (message);
  else if (atom_equals (fun, "ntfsfix"))
    return run_ntfsfix (message);
  else if (atom_equals (fun, "ntfsresize"))
    return run_ntfsresize (message);
  else if (atom_equals (fun, "ntfsresize_size"))
    return run_ntfsresize_size (message);
  else if (atom_equals (fun, "parse_environment"))
    return run_parse_environment (message);
  else if (atom_equals (fun, "parse_environment_list"))
    return run_parse_environment_list (message);
  else if (atom_equals (fun, "part_add"))
    return run_part_add (message);
  else if (atom_equals (fun, "part_del"))
    return run_part_del (message);
  else if (atom_equals (fun, "part_disk"))
    return run_part_disk (message);
  else if (atom_equals (fun, "part_get_bootable"))
    return run_part_get_bootable (message);
  else if (atom_equals (fun, "part_get_gpt_type"))
    return run_part_get_gpt_type (message);
  else if (atom_equals (fun, "part_get_mbr_id"))
    return run_part_get_mbr_id (message);
  else if (atom_equals (fun, "part_get_name"))
    return run_part_get_name (message);
  else if (atom_equals (fun, "part_get_parttype"))
    return run_part_get_parttype (message);
  else if (atom_equals (fun, "part_init"))
    return run_part_init (message);
  else if (atom_equals (fun, "part_list"))
    return run_part_list (message);
  else if (atom_equals (fun, "part_set_bootable"))
    return run_part_set_bootable (message);
  else if (atom_equals (fun, "part_set_gpt_type"))
    return run_part_set_gpt_type (message);
  else if (atom_equals (fun, "part_set_mbr_id"))
    return run_part_set_mbr_id (message);
  else if (atom_equals (fun, "part_set_name"))
    return run_part_set_name (message);
  else if (atom_equals (fun, "part_to_dev"))
    return run_part_to_dev (message);
  else if (atom_equals (fun, "part_to_partnum"))
    return run_part_to_partnum (message);
  else if (atom_equals (fun, "ping_daemon"))
    return run_ping_daemon (message);
  else if (atom_equals (fun, "pread"))
    return run_pread (message);
  else if (atom_equals (fun, "pread_device"))
    return run_pread_device (message);
  else if (atom_equals (fun, "pvchange_uuid"))
    return run_pvchange_uuid (message);
  else if (atom_equals (fun, "pvchange_uuid_all"))
    return run_pvchange_uuid_all (message);
  else if (atom_equals (fun, "pvcreate"))
    return run_pvcreate (message);
  else if (atom_equals (fun, "pvremove"))
    return run_pvremove (message);
  else if (atom_equals (fun, "pvresize"))
    return run_pvresize (message);
  else if (atom_equals (fun, "pvresize_size"))
    return run_pvresize_size (message);
  else if (atom_equals (fun, "pvs"))
    return run_pvs (message);
  else if (atom_equals (fun, "pvs_full"))
    return run_pvs_full (message);
  else if (atom_equals (fun, "pvuuid"))
    return run_pvuuid (message);
  else if (atom_equals (fun, "pwrite"))
    return run_pwrite (message);
  else if (atom_equals (fun, "pwrite_device"))
    return run_pwrite_device (message);
  else if (atom_equals (fun, "read_file"))
    return run_read_file (message);
  else if (atom_equals (fun, "read_lines"))
    return run_read_lines (message);
  else if (atom_equals (fun, "readdir"))
    return run_readdir (message);
  else if (atom_equals (fun, "readlink"))
    return run_readlink (message);
  else if (atom_equals (fun, "readlinklist"))
    return run_readlinklist (message);
  else if (atom_equals (fun, "realpath"))
    return run_realpath (message);
  else if (atom_equals (fun, "remount"))
    return run_remount (message);
  else if (atom_equals (fun, "remove_drive"))
    return run_remove_drive (message);
  else if (atom_equals (fun, "removexattr"))
    return run_removexattr (message);
  else if (atom_equals (fun, "rename"))
    return run_rename (message);
  else if (atom_equals (fun, "resize2fs"))
    return run_resize2fs (message);
  else if (atom_equals (fun, "resize2fs_M"))
    return run_resize2fs_M (message);
  else if (atom_equals (fun, "resize2fs_size"))
    return run_resize2fs_size (message);
  else if (atom_equals (fun, "rm"))
    return run_rm (message);
  else if (atom_equals (fun, "rm_f"))
    return run_rm_f (message);
  else if (atom_equals (fun, "rm_rf"))
    return run_rm_rf (message);
  else if (atom_equals (fun, "rmdir"))
    return run_rmdir (message);
  else if (atom_equals (fun, "rmmountpoint"))
    return run_rmmountpoint (message);
  else if (atom_equals (fun, "rsync"))
    return run_rsync (message);
  else if (atom_equals (fun, "rsync_in"))
    return run_rsync_in (message);
  else if (atom_equals (fun, "rsync_out"))
    return run_rsync_out (message);
  else if (atom_equals (fun, "scrub_device"))
    return run_scrub_device (message);
  else if (atom_equals (fun, "scrub_file"))
    return run_scrub_file (message);
  else if (atom_equals (fun, "scrub_freespace"))
    return run_scrub_freespace (message);
  else if (atom_equals (fun, "set_append"))
    return run_set_append (message);
  else if (atom_equals (fun, "set_attach_method"))
    return run_set_attach_method (message);
  else if (atom_equals (fun, "set_autosync"))
    return run_set_autosync (message);
  else if (atom_equals (fun, "set_backend"))
    return run_set_backend (message);
  else if (atom_equals (fun, "set_backend_settings"))
    return run_set_backend_settings (message);
  else if (atom_equals (fun, "set_cachedir"))
    return run_set_cachedir (message);
  else if (atom_equals (fun, "set_direct"))
    return run_set_direct (message);
  else if (atom_equals (fun, "set_e2attrs"))
    return run_set_e2attrs (message);
  else if (atom_equals (fun, "set_e2generation"))
    return run_set_e2generation (message);
  else if (atom_equals (fun, "set_e2label"))
    return run_set_e2label (message);
  else if (atom_equals (fun, "set_e2uuid"))
    return run_set_e2uuid (message);
  else if (atom_equals (fun, "set_hv"))
    return run_set_hv (message);
  else if (atom_equals (fun, "set_label"))
    return run_set_label (message);
  else if (atom_equals (fun, "set_libvirt_requested_credential"))
    return run_set_libvirt_requested_credential (message);
  else if (atom_equals (fun, "set_libvirt_supported_credentials"))
    return run_set_libvirt_supported_credentials (message);
  else if (atom_equals (fun, "set_memsize"))
    return run_set_memsize (message);
  else if (atom_equals (fun, "set_network"))
    return run_set_network (message);
  else if (atom_equals (fun, "set_path"))
    return run_set_path (message);
  else if (atom_equals (fun, "set_pgroup"))
    return run_set_pgroup (message);
  else if (atom_equals (fun, "set_program"))
    return run_set_program (message);
  else if (atom_equals (fun, "set_qemu"))
    return run_set_qemu (message);
  else if (atom_equals (fun, "set_recovery_proc"))
    return run_set_recovery_proc (message);
  else if (atom_equals (fun, "set_selinux"))
    return run_set_selinux (message);
  else if (atom_equals (fun, "set_smp"))
    return run_set_smp (message);
  else if (atom_equals (fun, "set_tmpdir"))
    return run_set_tmpdir (message);
  else if (atom_equals (fun, "set_trace"))
    return run_set_trace (message);
  else if (atom_equals (fun, "set_uuid"))
    return run_set_uuid (message);
  else if (atom_equals (fun, "set_verbose"))
    return run_set_verbose (message);
  else if (atom_equals (fun, "setcon"))
    return run_setcon (message);
  else if (atom_equals (fun, "setxattr"))
    return run_setxattr (message);
  else if (atom_equals (fun, "sfdisk"))
    return run_sfdisk (message);
  else if (atom_equals (fun, "sfdiskM"))
    return run_sfdiskM (message);
  else if (atom_equals (fun, "sfdisk_N"))
    return run_sfdisk_N (message);
  else if (atom_equals (fun, "sfdisk_disk_geometry"))
    return run_sfdisk_disk_geometry (message);
  else if (atom_equals (fun, "sfdisk_kernel_geometry"))
    return run_sfdisk_kernel_geometry (message);
  else if (atom_equals (fun, "sfdisk_l"))
    return run_sfdisk_l (message);
  else if (atom_equals (fun, "sh"))
    return run_sh (message);
  else if (atom_equals (fun, "sh_lines"))
    return run_sh_lines (message);
  else if (atom_equals (fun, "shutdown"))
    return run_shutdown (message);
  else if (atom_equals (fun, "sleep"))
    return run_sleep (message);
  else if (atom_equals (fun, "stat"))
    return run_stat (message);
  else if (atom_equals (fun, "statvfs"))
    return run_statvfs (message);
  else if (atom_equals (fun, "strings"))
    return run_strings (message);
  else if (atom_equals (fun, "strings_e"))
    return run_strings_e (message);
  else if (atom_equals (fun, "swapoff_device"))
    return run_swapoff_device (message);
  else if (atom_equals (fun, "swapoff_file"))
    return run_swapoff_file (message);
  else if (atom_equals (fun, "swapoff_label"))
    return run_swapoff_label (message);
  else if (atom_equals (fun, "swapoff_uuid"))
    return run_swapoff_uuid (message);
  else if (atom_equals (fun, "swapon_device"))
    return run_swapon_device (message);
  else if (atom_equals (fun, "swapon_file"))
    return run_swapon_file (message);
  else if (atom_equals (fun, "swapon_label"))
    return run_swapon_label (message);
  else if (atom_equals (fun, "swapon_uuid"))
    return run_swapon_uuid (message);
  else if (atom_equals (fun, "sync"))
    return run_sync (message);
  else if (atom_equals (fun, "syslinux"))
    return run_syslinux (message);
  else if (atom_equals (fun, "tail"))
    return run_tail (message);
  else if (atom_equals (fun, "tail_n"))
    return run_tail_n (message);
  else if (atom_equals (fun, "tar_in"))
    return run_tar_in (message);
  else if (atom_equals (fun, "tar_out"))
    return run_tar_out (message);
  else if (atom_equals (fun, "tgz_in"))
    return run_tgz_in (message);
  else if (atom_equals (fun, "tgz_out"))
    return run_tgz_out (message);
  else if (atom_equals (fun, "touch"))
    return run_touch (message);
  else if (atom_equals (fun, "truncate"))
    return run_truncate (message);
  else if (atom_equals (fun, "truncate_size"))
    return run_truncate_size (message);
  else if (atom_equals (fun, "tune2fs"))
    return run_tune2fs (message);
  else if (atom_equals (fun, "tune2fs_l"))
    return run_tune2fs_l (message);
  else if (atom_equals (fun, "txz_in"))
    return run_txz_in (message);
  else if (atom_equals (fun, "txz_out"))
    return run_txz_out (message);
  else if (atom_equals (fun, "umask"))
    return run_umask (message);
  else if (atom_equals (fun, "umount"))
    return run_umount (message);
  else if (atom_equals (fun, "umount_all"))
    return run_umount_all (message);
  else if (atom_equals (fun, "umount_local"))
    return run_umount_local (message);
  else if (atom_equals (fun, "upload"))
    return run_upload (message);
  else if (atom_equals (fun, "upload_offset"))
    return run_upload_offset (message);
  else if (atom_equals (fun, "user_cancel"))
    return run_user_cancel (message);
  else if (atom_equals (fun, "utimens"))
    return run_utimens (message);
  else if (atom_equals (fun, "utsname"))
    return run_utsname (message);
  else if (atom_equals (fun, "version"))
    return run_version (message);
  else if (atom_equals (fun, "vfs_label"))
    return run_vfs_label (message);
  else if (atom_equals (fun, "vfs_type"))
    return run_vfs_type (message);
  else if (atom_equals (fun, "vfs_uuid"))
    return run_vfs_uuid (message);
  else if (atom_equals (fun, "vg_activate"))
    return run_vg_activate (message);
  else if (atom_equals (fun, "vg_activate_all"))
    return run_vg_activate_all (message);
  else if (atom_equals (fun, "vgchange_uuid"))
    return run_vgchange_uuid (message);
  else if (atom_equals (fun, "vgchange_uuid_all"))
    return run_vgchange_uuid_all (message);
  else if (atom_equals (fun, "vgcreate"))
    return run_vgcreate (message);
  else if (atom_equals (fun, "vglvuuids"))
    return run_vglvuuids (message);
  else if (atom_equals (fun, "vgmeta"))
    return run_vgmeta (message);
  else if (atom_equals (fun, "vgpvuuids"))
    return run_vgpvuuids (message);
  else if (atom_equals (fun, "vgremove"))
    return run_vgremove (message);
  else if (atom_equals (fun, "vgrename"))
    return run_vgrename (message);
  else if (atom_equals (fun, "vgs"))
    return run_vgs (message);
  else if (atom_equals (fun, "vgs_full"))
    return run_vgs_full (message);
  else if (atom_equals (fun, "vgscan"))
    return run_vgscan (message);
  else if (atom_equals (fun, "vguuid"))
    return run_vguuid (message);
  else if (atom_equals (fun, "wait_ready"))
    return run_wait_ready (message);
  else if (atom_equals (fun, "wc_c"))
    return run_wc_c (message);
  else if (atom_equals (fun, "wc_l"))
    return run_wc_l (message);
  else if (atom_equals (fun, "wc_w"))
    return run_wc_w (message);
  else if (atom_equals (fun, "wipefs"))
    return run_wipefs (message);
  else if (atom_equals (fun, "write"))
    return run_write (message);
  else if (atom_equals (fun, "write_append"))
    return run_write_append (message);
  else if (atom_equals (fun, "write_file"))
    return run_write_file (message);
  else if (atom_equals (fun, "xfs_admin"))
    return run_xfs_admin (message);
  else if (atom_equals (fun, "xfs_growfs"))
    return run_xfs_growfs (message);
  else if (atom_equals (fun, "xfs_info"))
    return run_xfs_info (message);
  else if (atom_equals (fun, "xfs_repair"))
    return run_xfs_repair (message);
  else if (atom_equals (fun, "zegrep"))
    return run_zegrep (message);
  else if (atom_equals (fun, "zegrepi"))
    return run_zegrepi (message);
  else if (atom_equals (fun, "zero"))
    return run_zero (message);
  else if (atom_equals (fun, "zero_device"))
    return run_zero_device (message);
  else if (atom_equals (fun, "zero_free_space"))
    return run_zero_free_space (message);
  else if (atom_equals (fun, "zerofree"))
    return run_zerofree (message);
  else if (atom_equals (fun, "zfgrep"))
    return run_zfgrep (message);
  else if (atom_equals (fun, "zfgrepi"))
    return run_zfgrepi (message);
  else if (atom_equals (fun, "zfile"))
    return run_zfile (message);
  else if (atom_equals (fun, "zgrep"))
    return run_zgrep (message);
  else if (atom_equals (fun, "zgrepi"))
    return run_zgrepi (message);
  else return unknown_function (fun);
}
