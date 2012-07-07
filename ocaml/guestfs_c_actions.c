/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#include "guestfs.h"

#include "guestfs_c.h"

/* Copy a hashtable of string pairs into an assoc-list.  We return
 * the list in reverse order, but hashtables aren't supposed to be
 * ordered anyway.
 */
static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

static CAMLprim value
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
      caml_modify (&Field (rv, i), v);
    }
    CAMLreturn (rv);
  }
}

/* Automatically generated wrapper for function
 * val add_cdrom : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_cdrom (value gv, value filenamev);

CAMLprim value
ocaml_guestfs_add_cdrom (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_cdrom");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_cdrom (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_cdrom");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_domain : t -> ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_domain (value gv, value libvirturiv, value readonlyv, value ifacev, value livev, value allowuuidv, value readonlydiskv, value domv);

CAMLprim value
ocaml_guestfs_add_domain (value gv, value libvirturiv, value readonlyv, value ifacev, value livev, value allowuuidv, value readonlydiskv, value domv)
{
  CAMLparam5 (gv, libvirturiv, readonlyv, ifacev, livev);
  CAMLxparam3 (allowuuidv, readonlydiskv, domv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_domain");

  char *dom = guestfs_safe_strdup (g, String_val (domv));
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  if (libvirturiv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
    optargs_s.libvirturi = guestfs_safe_strdup (g, String_val (Field (libvirturiv, 0)));
  }
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (ifacev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
    optargs_s.iface = guestfs_safe_strdup (g, String_val (Field (ifacev, 0)));
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
    optargs_s.readonlydisk = guestfs_safe_strdup (g, String_val (Field (readonlydiskv, 0)));
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
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_domain");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_domain_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_add_domain_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_add_domain (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val add_drive : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive (value gv, value filenamev);

CAMLprim value
ocaml_guestfs_add_drive (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_drive");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_drive (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_drive");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_opts : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive_opts (value gv, value readonlyv, value formatv, value ifacev, value namev, value filenamev);

CAMLprim value
ocaml_guestfs_add_drive_opts (value gv, value readonlyv, value formatv, value ifacev, value namev, value filenamev)
{
  CAMLparam5 (gv, readonlyv, formatv, ifacev, namev);
  CAMLxparam1 (filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_drive_opts");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (formatv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
    optargs_s.format = guestfs_safe_strdup (g, String_val (Field (formatv, 0)));
  }
  if (ifacev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
    optargs_s.iface = guestfs_safe_strdup (g, String_val (Field (ifacev, 0)));
  }
  if (namev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
    optargs_s.name = guestfs_safe_strdup (g, String_val (Field (namev, 0)));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  caml_leave_blocking_section ();
  free (filename);
  if (formatv != Val_int (0))
    free ((char *) optargs_s.format);
  if (ifacev != Val_int (0))
    free ((char *) optargs_s.iface);
  if (namev != Val_int (0))
    free ((char *) optargs_s.name);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_drive_opts");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive_opts_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_add_drive_opts_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_add_drive_opts (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val add_drive_ro : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive_ro (value gv, value filenamev);

CAMLprim value
ocaml_guestfs_add_drive_ro (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_drive_ro");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_drive_ro (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_drive_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_ro_with_if : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive_ro_with_if (value gv, value filenamev, value ifacev);

CAMLprim value
ocaml_guestfs_add_drive_ro_with_if (value gv, value filenamev, value ifacev)
{
  CAMLparam3 (gv, filenamev, ifacev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_drive_ro_with_if");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *iface = guestfs_safe_strdup (g, String_val (ifacev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  caml_leave_blocking_section ();
  free (filename);
  free (iface);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_drive_ro_with_if");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val add_drive_with_if : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_add_drive_with_if (value gv, value filenamev, value ifacev);

CAMLprim value
ocaml_guestfs_add_drive_with_if (value gv, value filenamev, value ifacev)
{
  CAMLparam3 (gv, filenamev, ifacev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("add_drive_with_if");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *iface = guestfs_safe_strdup (g, String_val (ifacev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_add_drive_with_if (g, filename, iface);
  caml_leave_blocking_section ();
  free (filename);
  free (iface);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "add_drive_with_if");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_clear : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_clear (value gv, value augpathv);

CAMLprim value
ocaml_guestfs_aug_clear (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_clear");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_clear (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_clear");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_close (value gv);

CAMLprim value
ocaml_guestfs_aug_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_defnode : t -> string -> string -> string -> int_bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_defnode (value gv, value namev, value exprv, value valv);

CAMLprim value
ocaml_guestfs_aug_defnode (value gv, value namev, value exprv, value valv)
{
  CAMLparam4 (gv, namev, exprv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_defnode");

  char *name = guestfs_safe_strdup (g, String_val (namev));
  char *expr = guestfs_safe_strdup (g, String_val (exprv));
  char *val = guestfs_safe_strdup (g, String_val (valv));
  struct guestfs_int_bool *r;

  caml_enter_blocking_section ();
  r = guestfs_aug_defnode (g, name, expr, val);
  caml_leave_blocking_section ();
  free (name);
  free (expr);
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "aug_defnode");

  rv = copy_int_bool (r);
  guestfs_free_int_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_defvar : t -> string -> string option -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_defvar (value gv, value namev, value exprv);

CAMLprim value
ocaml_guestfs_aug_defvar (value gv, value namev, value exprv)
{
  CAMLparam3 (gv, namev, exprv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_defvar");

  char *name = guestfs_safe_strdup (g, String_val (namev));
  char *expr =
    exprv != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (exprv, 0))) : NULL;
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_defvar (g, name, expr);
  caml_leave_blocking_section ();
  free (name);
  free (expr);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_defvar");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_get : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_get (value gv, value augpathv);

CAMLprim value
ocaml_guestfs_aug_get (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_get");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_aug_get (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "aug_get");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_init : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_init (value gv, value rootv, value flagsv);

CAMLprim value
ocaml_guestfs_aug_init (value gv, value rootv, value flagsv)
{
  CAMLparam3 (gv, rootv, flagsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_init");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int flags = Int_val (flagsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_init (g, root, flags);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_insert : t -> string -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_insert (value gv, value augpathv, value labelv, value beforev);

CAMLprim value
ocaml_guestfs_aug_insert (value gv, value augpathv, value labelv, value beforev)
{
  CAMLparam4 (gv, augpathv, labelv, beforev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_insert");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int before = Bool_val (beforev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_insert (g, augpath, label, before);
  caml_leave_blocking_section ();
  free (augpath);
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_insert");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_load : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_load (value gv);

CAMLprim value
ocaml_guestfs_aug_load (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_load");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_load (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_load");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_ls : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_ls (value gv, value augpathv);

CAMLprim value
ocaml_guestfs_aug_ls (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_ls");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_aug_ls (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "aug_ls");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_match : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_match (value gv, value augpathv);

CAMLprim value
ocaml_guestfs_aug_match (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_match");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_aug_match (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "aug_match");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_mv : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_mv (value gv, value srcv, value destv);

CAMLprim value
ocaml_guestfs_aug_mv (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_mv");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_mv (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_mv");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_rm : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_rm (value gv, value augpathv);

CAMLprim value
ocaml_guestfs_aug_rm (value gv, value augpathv)
{
  CAMLparam2 (gv, augpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_rm");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_rm (g, augpath);
  caml_leave_blocking_section ();
  free (augpath);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_rm");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_save : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_save (value gv);

CAMLprim value
ocaml_guestfs_aug_save (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_save");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_save (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_save");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val aug_set : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_aug_set (value gv, value augpathv, value valv);

CAMLprim value
ocaml_guestfs_aug_set (value gv, value augpathv, value valv)
{
  CAMLparam3 (gv, augpathv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("aug_set");

  char *augpath = guestfs_safe_strdup (g, String_val (augpathv));
  char *val = guestfs_safe_strdup (g, String_val (valv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_aug_set (g, augpath, val);
  caml_leave_blocking_section ();
  free (augpath);
  free (val);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "aug_set");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val available : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_available (value gv, value groupsv);

CAMLprim value
ocaml_guestfs_available (value gv, value groupsv)
{
  CAMLparam2 (gv, groupsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("available");

  char **groups = ocaml_guestfs_strings_val (g, groupsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_available (g, groups);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (groups);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "available");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val available_all_groups : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_available_all_groups (value gv);

CAMLprim value
ocaml_guestfs_available_all_groups (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("available_all_groups");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_available_all_groups (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "available_all_groups");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val base64_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_base64_in (value gv, value base64filev, value filenamev);

CAMLprim value
ocaml_guestfs_base64_in (value gv, value base64filev, value filenamev)
{
  CAMLparam3 (gv, base64filev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("base64_in");

  char *base64file = guestfs_safe_strdup (g, String_val (base64filev));
  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_base64_in (g, base64file, filename);
  caml_leave_blocking_section ();
  free (base64file);
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "base64_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val base64_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_base64_out (value gv, value filenamev, value base64filev);

CAMLprim value
ocaml_guestfs_base64_out (value gv, value filenamev, value base64filev)
{
  CAMLparam3 (gv, filenamev, base64filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("base64_out");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *base64file = guestfs_safe_strdup (g, String_val (base64filev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_base64_out (g, filename, base64file);
  caml_leave_blocking_section ();
  free (filename);
  free (base64file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "base64_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blkid : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blkid (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blkid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blkid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_blkid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "blkid");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_flushbufs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_flushbufs (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_flushbufs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_flushbufs");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_flushbufs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_flushbufs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getbsz : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_getbsz (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_getbsz (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_getbsz");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getbsz (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_getbsz");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getro : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_getro (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_getro (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_getro");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getro (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_getro");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getsize64 : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_getsize64 (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_getsize64 (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_getsize64");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getsize64 (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_getsize64");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getss : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_getss (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_getss (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_getss");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getss (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_getss");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_getsz : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_getsz (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_getsz (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_getsz");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_getsz (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_getsz");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_rereadpt : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_rereadpt (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_rereadpt (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_rereadpt");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_rereadpt (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_rereadpt");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setbsz : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_setbsz (value gv, value devicev, value blocksizev);

CAMLprim value
ocaml_guestfs_blockdev_setbsz (value gv, value devicev, value blocksizev)
{
  CAMLparam3 (gv, devicev, blocksizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_setbsz");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int blocksize = Int_val (blocksizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setbsz (g, device, blocksize);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_setbsz");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setro : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_setro (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_setro (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_setro");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setro (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_setro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val blockdev_setrw : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_blockdev_setrw (value gv, value devicev);

CAMLprim value
ocaml_guestfs_blockdev_setrw (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("blockdev_setrw");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_blockdev_setrw (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "blockdev_setrw");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_device_add : t -> string array -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_device_add (value gv, value devicesv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_device_add (value gv, value devicesv, value fsv)
{
  CAMLparam3 (gv, devicesv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_device_add");

  char **devices = ocaml_guestfs_strings_val (g, devicesv);
  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_device_add (g, devices, fs);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (devices);
  free (fs);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_device_add");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_device_delete : t -> string array -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_device_delete (value gv, value devicesv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_device_delete (value gv, value devicesv, value fsv)
{
  CAMLparam3 (gv, devicesv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_device_delete");

  char **devices = ocaml_guestfs_strings_val (g, devicesv);
  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_device_delete (g, devices, fs);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (devices);
  free (fs);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_device_delete");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_balance : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_filesystem_balance (value gv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_filesystem_balance (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_filesystem_balance");

  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_balance (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_filesystem_balance");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_resize : t -> ?size:int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_filesystem_resize (value gv, value sizev, value mountpointv);

CAMLprim value
ocaml_guestfs_btrfs_filesystem_resize (value gv, value sizev, value mountpointv)
{
  CAMLparam3 (gv, sizev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_filesystem_resize");

  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
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
    ocaml_guestfs_raise_error (g, "btrfs_filesystem_resize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_filesystem_sync : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_filesystem_sync (value gv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_filesystem_sync (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_filesystem_sync");

  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_filesystem_sync (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_filesystem_sync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_fsck : t -> ?superblock:int64 -> ?repair:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_fsck (value gv, value superblockv, value repairv, value devicev);

CAMLprim value
ocaml_guestfs_btrfs_fsck (value gv, value superblockv, value repairv, value devicev)
{
  CAMLparam4 (gv, superblockv, repairv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_fsck");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
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
    ocaml_guestfs_raise_error (g, "btrfs_fsck");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_set_seeding : t -> string -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_set_seeding (value gv, value devicev, value seedingv);

CAMLprim value
ocaml_guestfs_btrfs_set_seeding (value gv, value devicev, value seedingv)
{
  CAMLparam3 (gv, devicev, seedingv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_set_seeding");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int seeding = Bool_val (seedingv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_set_seeding (g, device, seeding);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_set_seeding");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_create : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_subvolume_create (value gv, value destv);

CAMLprim value
ocaml_guestfs_btrfs_subvolume_create (value gv, value destv)
{
  CAMLparam2 (gv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_subvolume_create");

  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_create (g, dest);
  caml_leave_blocking_section ();
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_subvolume_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_delete : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_subvolume_delete (value gv, value subvolumev);

CAMLprim value
ocaml_guestfs_btrfs_subvolume_delete (value gv, value subvolumev)
{
  CAMLparam2 (gv, subvolumev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_subvolume_delete");

  char *subvolume = guestfs_safe_strdup (g, String_val (subvolumev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  caml_leave_blocking_section ();
  free (subvolume);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_subvolume_delete");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_list : t -> string -> btrfssubvolume array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_subvolume_list (value gv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_subvolume_list (value gv, value fsv)
{
  CAMLparam2 (gv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_subvolume_list");

  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  struct guestfs_btrfssubvolume_list *r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_list (g, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "btrfs_subvolume_list");

  rv = copy_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_set_default : t -> int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_subvolume_set_default (value gv, value idv, value fsv);

CAMLprim value
ocaml_guestfs_btrfs_subvolume_set_default (value gv, value idv, value fsv)
{
  CAMLparam3 (gv, idv, fsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_subvolume_set_default");

  int64_t id = Int64_val (idv);
  char *fs = guestfs_safe_strdup (g, String_val (fsv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  caml_leave_blocking_section ();
  free (fs);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_subvolume_set_default");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val btrfs_subvolume_snapshot : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_btrfs_subvolume_snapshot (value gv, value sourcev, value destv);

CAMLprim value
ocaml_guestfs_btrfs_subvolume_snapshot (value gv, value sourcev, value destv)
{
  CAMLparam3 (gv, sourcev, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("btrfs_subvolume_snapshot");

  char *source = guestfs_safe_strdup (g, String_val (sourcev));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);
  caml_leave_blocking_section ();
  free (source);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "btrfs_subvolume_snapshot");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val case_sensitive_path : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_case_sensitive_path (value gv, value pathv);

CAMLprim value
ocaml_guestfs_case_sensitive_path (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("case_sensitive_path");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_case_sensitive_path (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "case_sensitive_path");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cat : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_cat (value gv, value pathv);

CAMLprim value
ocaml_guestfs_cat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("cat");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_cat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "cat");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksum : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_checksum (value gv, value csumtypev, value pathv);

CAMLprim value
ocaml_guestfs_checksum (value gv, value csumtypev, value pathv)
{
  CAMLparam3 (gv, csumtypev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("checksum");

  char *csumtype = guestfs_safe_strdup (g, String_val (csumtypev));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_checksum (g, csumtype, path);
  caml_leave_blocking_section ();
  free (csumtype);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "checksum");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksum_device : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_checksum_device (value gv, value csumtypev, value devicev);

CAMLprim value
ocaml_guestfs_checksum_device (value gv, value csumtypev, value devicev)
{
  CAMLparam3 (gv, csumtypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("checksum_device");

  char *csumtype = guestfs_safe_strdup (g, String_val (csumtypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_checksum_device (g, csumtype, device);
  caml_leave_blocking_section ();
  free (csumtype);
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "checksum_device");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val checksums_out : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_checksums_out (value gv, value csumtypev, value directoryv, value sumsfilev);

CAMLprim value
ocaml_guestfs_checksums_out (value gv, value csumtypev, value directoryv, value sumsfilev)
{
  CAMLparam4 (gv, csumtypev, directoryv, sumsfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("checksums_out");

  char *csumtype = guestfs_safe_strdup (g, String_val (csumtypev));
  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *sumsfile = guestfs_safe_strdup (g, String_val (sumsfilev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  caml_leave_blocking_section ();
  free (csumtype);
  free (directory);
  free (sumsfile);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "checksums_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val chmod : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_chmod (value gv, value modev, value pathv);

CAMLprim value
ocaml_guestfs_chmod (value gv, value modev, value pathv)
{
  CAMLparam3 (gv, modev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("chmod");

  int mode = Int_val (modev);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_chmod (g, mode, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "chmod");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val chown : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_chown (value gv, value ownerv, value groupv, value pathv);

CAMLprim value
ocaml_guestfs_chown (value gv, value ownerv, value groupv, value pathv)
{
  CAMLparam4 (gv, ownerv, groupv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("chown");

  int owner = Int_val (ownerv);
  int group = Int_val (groupv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_chown (g, owner, group, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "chown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val command : t -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_command (value gv, value argumentsv);

CAMLprim value
ocaml_guestfs_command (value gv, value argumentsv)
{
  CAMLparam2 (gv, argumentsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("command");

  char **arguments = ocaml_guestfs_strings_val (g, argumentsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_command (g, arguments);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (arguments);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "command");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val command_lines : t -> string array -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_command_lines (value gv, value argumentsv);

CAMLprim value
ocaml_guestfs_command_lines (value gv, value argumentsv)
{
  CAMLparam2 (gv, argumentsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("command_lines");

  char **arguments = ocaml_guestfs_strings_val (g, argumentsv);
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_command_lines (g, arguments);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (arguments);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "command_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val compress_device_out : t -> ?level:int -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_compress_device_out (value gv, value levelv, value ctypev, value devicev, value zdevicev);

CAMLprim value
ocaml_guestfs_compress_device_out (value gv, value levelv, value ctypev, value devicev, value zdevicev)
{
  CAMLparam5 (gv, levelv, ctypev, devicev, zdevicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("compress_device_out");

  char *ctype = guestfs_safe_strdup (g, String_val (ctypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *zdevice = guestfs_safe_strdup (g, String_val (zdevicev));
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
    ocaml_guestfs_raise_error (g, "compress_device_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val compress_out : t -> ?level:int -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_compress_out (value gv, value levelv, value ctypev, value filev, value zfilev);

CAMLprim value
ocaml_guestfs_compress_out (value gv, value levelv, value ctypev, value filev, value zfilev)
{
  CAMLparam5 (gv, levelv, ctypev, filev, zfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("compress_out");

  char *ctype = guestfs_safe_strdup (g, String_val (ctypev));
  char *file = guestfs_safe_strdup (g, String_val (filev));
  char *zfile = guestfs_safe_strdup (g, String_val (zfilev));
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
    ocaml_guestfs_raise_error (g, "compress_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val config : t -> string -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_config (value gv, value qemuparamv, value qemuvaluev);

CAMLprim value
ocaml_guestfs_config (value gv, value qemuparamv, value qemuvaluev)
{
  CAMLparam3 (gv, qemuparamv, qemuvaluev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("config");

  char *qemuparam = guestfs_safe_strdup (g, String_val (qemuparamv));
  char *qemuvalue =
    qemuvaluev != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (qemuvaluev, 0))) : NULL;
  int r;

  caml_enter_blocking_section ();
  r = guestfs_config (g, qemuparam, qemuvalue);
  caml_leave_blocking_section ();
  free (qemuparam);
  free (qemuvalue);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "config");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val copy_device_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_device_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv);

CAMLprim value
ocaml_guestfs_copy_device_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, srcv);
  CAMLxparam1 (destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("copy_device_to_device");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
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
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "copy_device_to_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_device_to_device_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_copy_device_to_device_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_copy_device_to_device (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val copy_device_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_device_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv);

CAMLprim value
ocaml_guestfs_copy_device_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, srcv);
  CAMLxparam1 (destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("copy_device_to_file");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
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
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "copy_device_to_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_device_to_file_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_copy_device_to_file_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_copy_device_to_file (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val copy_file_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_file_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv);

CAMLprim value
ocaml_guestfs_copy_file_to_device (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, srcv);
  CAMLxparam1 (destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("copy_file_to_device");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
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
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "copy_file_to_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_file_to_device_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_copy_file_to_device_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_copy_file_to_device (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val copy_file_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_file_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv);

CAMLprim value
ocaml_guestfs_copy_file_to_file (value gv, value srcoffsetv, value destoffsetv, value sizev, value srcv, value destv)
{
  CAMLparam5 (gv, srcoffsetv, destoffsetv, sizev, srcv);
  CAMLxparam1 (destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("copy_file_to_file");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
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
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "copy_file_to_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_file_to_file_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_copy_file_to_file_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_copy_file_to_file (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val copy_size : t -> string -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_copy_size (value gv, value srcv, value destv, value sizev);

CAMLprim value
ocaml_guestfs_copy_size (value gv, value srcv, value destv, value sizev)
{
  CAMLparam4 (gv, srcv, destv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("copy_size");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_copy_size (g, src, dest, size);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "copy_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cp : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_cp (value gv, value srcv, value destv);

CAMLprim value
ocaml_guestfs_cp (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("cp");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cp (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "cp");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val cp_a : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_cp_a (value gv, value srcv, value destv);

CAMLprim value
ocaml_guestfs_cp_a (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("cp_a");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_cp_a (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "cp_a");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val dd : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_dd (value gv, value srcv, value destv);

CAMLprim value
ocaml_guestfs_dd (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("dd");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_dd (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "dd");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug : t -> string -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_debug (value gv, value subcmdv, value extraargsv);

CAMLprim value
ocaml_guestfs_debug (value gv, value subcmdv, value extraargsv)
{
  CAMLparam3 (gv, subcmdv, extraargsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("debug");

  char *subcmd = guestfs_safe_strdup (g, String_val (subcmdv));
  char **extraargs = ocaml_guestfs_strings_val (g, extraargsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_debug (g, subcmd, extraargs);
  caml_leave_blocking_section ();
  free (subcmd);
  ocaml_guestfs_free_strings (extraargs);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "debug");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug_cmdline : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_debug_cmdline (value gv);

CAMLprim value
ocaml_guestfs_debug_cmdline (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("debug_cmdline");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_debug_cmdline (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "debug_cmdline");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug_drives : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_debug_drives (value gv);

CAMLprim value
ocaml_guestfs_debug_drives (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("debug_drives");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_debug_drives (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "debug_drives");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val debug_upload : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_debug_upload (value gv, value filenamev, value tmpnamev, value modev);

CAMLprim value
ocaml_guestfs_debug_upload (value gv, value filenamev, value tmpnamev, value modev)
{
  CAMLparam4 (gv, filenamev, tmpnamev, modev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("debug_upload");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *tmpname = guestfs_safe_strdup (g, String_val (tmpnamev));
  int mode = Int_val (modev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_debug_upload (g, filename, tmpname, mode);
  caml_leave_blocking_section ();
  free (filename);
  free (tmpname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "debug_upload");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val device_index : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_device_index (value gv, value devicev);

CAMLprim value
ocaml_guestfs_device_index (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("device_index");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_device_index (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "device_index");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val df : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_df (value gv);

CAMLprim value
ocaml_guestfs_df (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("df");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_df (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "df");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val df_h : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_df_h (value gv);

CAMLprim value
ocaml_guestfs_df_h (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("df_h");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_df_h (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "df_h");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val dmesg : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_dmesg (value gv);

CAMLprim value
ocaml_guestfs_dmesg (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("dmesg");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_dmesg (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "dmesg");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val download : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_download (value gv, value remotefilenamev, value filenamev);

CAMLprim value
ocaml_guestfs_download (value gv, value remotefilenamev, value filenamev)
{
  CAMLparam3 (gv, remotefilenamev, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("download");

  char *remotefilename = guestfs_safe_strdup (g, String_val (remotefilenamev));
  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download (g, remotefilename, filename);
  caml_leave_blocking_section ();
  free (remotefilename);
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "download");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val download_offset : t -> string -> string -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_download_offset (value gv, value remotefilenamev, value filenamev, value offsetv, value sizev);

CAMLprim value
ocaml_guestfs_download_offset (value gv, value remotefilenamev, value filenamev, value offsetv, value sizev)
{
  CAMLparam5 (gv, remotefilenamev, filenamev, offsetv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("download_offset");

  char *remotefilename = guestfs_safe_strdup (g, String_val (remotefilenamev));
  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  int64_t offset = Int64_val (offsetv);
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  caml_leave_blocking_section ();
  free (remotefilename);
  free (filename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "download_offset");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val drop_caches : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_drop_caches (value gv, value whattodropv);

CAMLprim value
ocaml_guestfs_drop_caches (value gv, value whattodropv)
{
  CAMLparam2 (gv, whattodropv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("drop_caches");

  int whattodrop = Int_val (whattodropv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_drop_caches (g, whattodrop);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "drop_caches");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val du : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_du (value gv, value pathv);

CAMLprim value
ocaml_guestfs_du (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("du");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_du (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "du");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val e2fsck : t -> ?correct:bool -> ?forceall:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_e2fsck (value gv, value correctv, value forceallv, value devicev);

CAMLprim value
ocaml_guestfs_e2fsck (value gv, value correctv, value forceallv, value devicev)
{
  CAMLparam4 (gv, correctv, forceallv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("e2fsck");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
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
    ocaml_guestfs_raise_error (g, "e2fsck");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val e2fsck_f : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_e2fsck_f (value gv, value devicev);

CAMLprim value
ocaml_guestfs_e2fsck_f (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("e2fsck_f");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_e2fsck_f (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "e2fsck_f");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val echo_daemon : t -> string array -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_echo_daemon (value gv, value wordsv);

CAMLprim value
ocaml_guestfs_echo_daemon (value gv, value wordsv)
{
  CAMLparam2 (gv, wordsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("echo_daemon");

  char **words = ocaml_guestfs_strings_val (g, wordsv);
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_echo_daemon (g, words);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (words);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "echo_daemon");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val egrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_egrep (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_egrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("egrep");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_egrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "egrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val egrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_egrepi (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_egrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("egrepi");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_egrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "egrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val equal : t -> string -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_equal (value gv, value file1v, value file2v);

CAMLprim value
ocaml_guestfs_equal (value gv, value file1v, value file2v)
{
  CAMLparam3 (gv, file1v, file2v);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("equal");

  char *file1 = guestfs_safe_strdup (g, String_val (file1v));
  char *file2 = guestfs_safe_strdup (g, String_val (file2v));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_equal (g, file1, file2);
  caml_leave_blocking_section ();
  free (file1);
  free (file2);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "equal");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val exists : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_exists (value gv, value pathv);

CAMLprim value
ocaml_guestfs_exists (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("exists");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_exists (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "exists");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fallocate : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fallocate (value gv, value pathv, value lenv);

CAMLprim value
ocaml_guestfs_fallocate (value gv, value pathv, value lenv)
{
  CAMLparam3 (gv, pathv, lenv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fallocate");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int len = Int_val (lenv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fallocate (g, path, len);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "fallocate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fallocate64 : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fallocate64 (value gv, value pathv, value lenv);

CAMLprim value
ocaml_guestfs_fallocate64 (value gv, value pathv, value lenv)
{
  CAMLparam3 (gv, pathv, lenv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fallocate64");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int64_t len = Int64_val (lenv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fallocate64 (g, path, len);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "fallocate64");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fgrep (value gv, value patternv, value pathv);

CAMLprim value
ocaml_guestfs_fgrep (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fgrep");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_fgrep (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "fgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fgrepi (value gv, value patternv, value pathv);

CAMLprim value
ocaml_guestfs_fgrepi (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fgrepi");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_fgrepi (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "fgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val file : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_file (value gv, value pathv);

CAMLprim value
ocaml_guestfs_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("file");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "file");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val file_architecture : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_file_architecture (value gv, value filenamev);

CAMLprim value
ocaml_guestfs_file_architecture (value gv, value filenamev)
{
  CAMLparam2 (gv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("file_architecture");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_file_architecture (g, filename);
  caml_leave_blocking_section ();
  free (filename);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "file_architecture");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val filesize : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_filesize (value gv, value filev);

CAMLprim value
ocaml_guestfs_filesize (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("filesize");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_filesize (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "filesize");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fill : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fill (value gv, value cv, value lenv, value pathv);

CAMLprim value
ocaml_guestfs_fill (value gv, value cv, value lenv, value pathv)
{
  CAMLparam4 (gv, cv, lenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fill");

  int c = Int_val (cv);
  int len = Int_val (lenv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fill (g, c, len, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "fill");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fill_pattern : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fill_pattern (value gv, value patternv, value lenv, value pathv);

CAMLprim value
ocaml_guestfs_fill_pattern (value gv, value patternv, value lenv, value pathv)
{
  CAMLparam4 (gv, patternv, lenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fill_pattern");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  int len = Int_val (lenv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fill_pattern (g, pattern, len, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "fill_pattern");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val find : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_find (value gv, value directoryv);

CAMLprim value
ocaml_guestfs_find (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("find");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_find (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "find");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val find0 : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_find0 (value gv, value directoryv, value filesv);

CAMLprim value
ocaml_guestfs_find0 (value gv, value directoryv, value filesv)
{
  CAMLparam3 (gv, directoryv, filesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("find0");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *files = guestfs_safe_strdup (g, String_val (filesv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_find0 (g, directory, files);
  caml_leave_blocking_section ();
  free (directory);
  free (files);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "find0");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val findfs_label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_findfs_label (value gv, value labelv);

CAMLprim value
ocaml_guestfs_findfs_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("findfs_label");

  char *label = guestfs_safe_strdup (g, String_val (labelv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_findfs_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "findfs_label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val findfs_uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_findfs_uuid (value gv, value uuidv);

CAMLprim value
ocaml_guestfs_findfs_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("findfs_uuid");

  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_findfs_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "findfs_uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val fsck : t -> string -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_fsck (value gv, value fstypev, value devicev);

CAMLprim value
ocaml_guestfs_fsck (value gv, value fstypev, value devicev)
{
  CAMLparam3 (gv, fstypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("fsck");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_fsck (g, fstype, device);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "fsck");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_append : t -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_append (value gv);

CAMLprim value
ocaml_guestfs_get_append (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_append");

  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_append (g);
  caml_leave_blocking_section ();

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
CAMLprim value ocaml_guestfs_get_attach_method (value gv);

CAMLprim value
ocaml_guestfs_get_attach_method (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_attach_method");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_attach_method (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_attach_method");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_autosync : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_autosync (value gv);

CAMLprim value
ocaml_guestfs_get_autosync (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_autosync");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_autosync (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_autosync");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_direct : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_direct (value gv);

CAMLprim value
ocaml_guestfs_get_direct (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_direct");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_direct (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_direct");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2attrs : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_e2attrs (value gv, value filev);

CAMLprim value
ocaml_guestfs_get_e2attrs (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_e2attrs");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2attrs (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_e2attrs");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2generation : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_e2generation (value gv, value filev);

CAMLprim value
ocaml_guestfs_get_e2generation (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_e2generation");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2generation (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_e2generation");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_e2label (value gv, value devicev);

CAMLprim value
ocaml_guestfs_get_e2label (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_e2label");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2label (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_e2label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_e2uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_e2uuid (value gv, value devicev);

CAMLprim value
ocaml_guestfs_get_e2uuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_e2uuid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_e2uuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_e2uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_memsize : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_memsize (value gv);

CAMLprim value
ocaml_guestfs_get_memsize (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_memsize");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_memsize (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_memsize");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_network : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_network (value gv);

CAMLprim value
ocaml_guestfs_get_network (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_network");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_network (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_network");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_path : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_path (value gv);

CAMLprim value
ocaml_guestfs_get_path (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_path");

  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_path (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_path");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_pgroup : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_pgroup (value gv);

CAMLprim value
ocaml_guestfs_get_pgroup (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_pgroup");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_pgroup (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_pgroup");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_pid : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_pid (value gv);

CAMLprim value
ocaml_guestfs_get_pid (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_pid");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_pid (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_pid");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_qemu : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_qemu (value gv);

CAMLprim value
ocaml_guestfs_get_qemu (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_qemu");

  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_get_qemu (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "get_qemu");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_recovery_proc : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_recovery_proc (value gv);

CAMLprim value
ocaml_guestfs_get_recovery_proc (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_recovery_proc");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_recovery_proc (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_recovery_proc");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_selinux : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_selinux (value gv);

CAMLprim value
ocaml_guestfs_get_selinux (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_selinux");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_selinux (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_selinux");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_smp : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_smp (value gv);

CAMLprim value
ocaml_guestfs_get_smp (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_smp");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_smp (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_smp");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_state : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_state (value gv);

CAMLprim value
ocaml_guestfs_get_state (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_state");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_state (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_state");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_trace : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_trace (value gv);

CAMLprim value
ocaml_guestfs_get_trace (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_trace");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_trace (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_trace");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_umask : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_umask (value gv);

CAMLprim value
ocaml_guestfs_get_umask (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_umask");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_umask (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_umask");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val get_verbose : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_get_verbose (value gv);

CAMLprim value
ocaml_guestfs_get_verbose (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("get_verbose");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_get_verbose (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "get_verbose");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getcon : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_getcon (value gv);

CAMLprim value
ocaml_guestfs_getcon (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("getcon");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_getcon (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "getcon");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getxattr : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_getxattr (value gv, value pathv, value namev);

CAMLprim value
ocaml_guestfs_getxattr (value gv, value pathv, value namev)
{
  CAMLparam3 (gv, pathv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("getxattr");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *name = guestfs_safe_strdup (g, String_val (namev));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_getxattr (g, path, name, &size);
  caml_leave_blocking_section ();
  free (path);
  free (name);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "getxattr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val getxattrs : t -> string -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_getxattrs (value gv, value pathv);

CAMLprim value
ocaml_guestfs_getxattrs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("getxattrs");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_getxattrs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "getxattrs");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val glob_expand : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_glob_expand (value gv, value patternv);

CAMLprim value
ocaml_guestfs_glob_expand (value gv, value patternv)
{
  CAMLparam2 (gv, patternv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("glob_expand");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_glob_expand (g, pattern);
  caml_leave_blocking_section ();
  free (pattern);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "glob_expand");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val grep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_grep (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_grep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("grep");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_grep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "grep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val grepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_grepi (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_grepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("grepi");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_grepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "grepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val grub_install : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_grub_install (value gv, value rootv, value devicev);

CAMLprim value
ocaml_guestfs_grub_install (value gv, value rootv, value devicev)
{
  CAMLparam3 (gv, rootv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("grub_install");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_grub_install (g, root, device);
  caml_leave_blocking_section ();
  free (root);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "grub_install");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val head : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_head (value gv, value pathv);

CAMLprim value
ocaml_guestfs_head (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("head");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_head (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "head");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val head_n : t -> int -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_head_n (value gv, value nrlinesv, value pathv);

CAMLprim value
ocaml_guestfs_head_n (value gv, value nrlinesv, value pathv)
{
  CAMLparam3 (gv, nrlinesv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("head_n");

  int nrlines = Int_val (nrlinesv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_head_n (g, nrlines, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "head_n");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val hexdump : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_hexdump (value gv, value pathv);

CAMLprim value
ocaml_guestfs_hexdump (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("hexdump");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_hexdump (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "hexdump");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val initrd_cat : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_initrd_cat (value gv, value initrdpathv, value filenamev);

CAMLprim value
ocaml_guestfs_initrd_cat (value gv, value initrdpathv, value filenamev)
{
  CAMLparam3 (gv, initrdpathv, filenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("initrd_cat");

  char *initrdpath = guestfs_safe_strdup (g, String_val (initrdpathv));
  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  caml_leave_blocking_section ();
  free (initrdpath);
  free (filename);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "initrd_cat");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val initrd_list : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_initrd_list (value gv, value pathv);

CAMLprim value
ocaml_guestfs_initrd_list (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("initrd_list");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_initrd_list (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "initrd_list");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_add_watch : t -> string -> int -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_add_watch (value gv, value pathv, value maskv);

CAMLprim value
ocaml_guestfs_inotify_add_watch (value gv, value pathv, value maskv)
{
  CAMLparam3 (gv, pathv, maskv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_add_watch");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int mask = Int_val (maskv);
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_add_watch (g, path, mask);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inotify_add_watch");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_close : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_close (value gv);

CAMLprim value
ocaml_guestfs_inotify_close (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_close");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_close (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inotify_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_files : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_files (value gv);

CAMLprim value
ocaml_guestfs_inotify_files (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_files");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_files (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inotify_files");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_init : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_init (value gv, value maxeventsv);

CAMLprim value
ocaml_guestfs_inotify_init (value gv, value maxeventsv)
{
  CAMLparam2 (gv, maxeventsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_init");

  int maxevents = Int_val (maxeventsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_init (g, maxevents);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inotify_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_read : t -> inotify_event array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_read (value gv);

CAMLprim value
ocaml_guestfs_inotify_read (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_read");

  struct guestfs_inotify_event_list *r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_read (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inotify_read");

  rv = copy_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inotify_rm_watch : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inotify_rm_watch (value gv, value wdv);

CAMLprim value
ocaml_guestfs_inotify_rm_watch (value gv, value wdv)
{
  CAMLparam2 (gv, wdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inotify_rm_watch");

  int wd = Int_val (wdv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inotify_rm_watch (g, wd);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inotify_rm_watch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_arch : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_arch (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_arch (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_arch");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_arch (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_arch");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_distro : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_distro (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_distro (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_distro");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_distro (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_distro");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_drive_mappings : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_drive_mappings (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_drive_mappings (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_drive_mappings");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_drive_mappings (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_drive_mappings");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_filesystems : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_filesystems (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_filesystems (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_filesystems");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_filesystems (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_filesystems");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_format : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_format (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_format (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_format");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_format (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_format");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_hostname : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_hostname (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_hostname (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_hostname");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_hostname (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_hostname");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_icon : t -> ?favicon:bool -> ?highquality:bool -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_icon (value gv, value faviconv, value highqualityv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_icon (value gv, value faviconv, value highqualityv, value rootv)
{
  CAMLparam4 (gv, faviconv, highqualityv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_icon");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
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
    ocaml_guestfs_raise_error (g, "inspect_get_icon");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_major_version : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_major_version (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_major_version (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_major_version");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_major_version (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inspect_get_major_version");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_minor_version : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_minor_version (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_minor_version (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_minor_version");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_minor_version (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inspect_get_minor_version");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_mountpoints : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_mountpoints (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_mountpoints (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_mountpoints");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_mountpoints (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_mountpoints");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_package_format : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_package_format (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_package_format (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_package_format");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_package_format (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_package_format");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_package_management : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_package_management (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_package_management (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_package_management");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_package_management (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_package_management");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_product_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_product_name (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_product_name (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_product_name");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_product_name (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_product_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_product_variant : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_product_variant (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_product_variant (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_product_variant");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_product_variant (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_product_variant");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_roots : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_roots (value gv);

CAMLprim value
ocaml_guestfs_inspect_get_roots (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_roots");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_roots (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_roots");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_type : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_type (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_type (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_type");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_type (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_current_control_set : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_windows_current_control_set (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_windows_current_control_set (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_windows_current_control_set");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_current_control_set (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_windows_current_control_set");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_get_windows_systemroot : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_get_windows_systemroot (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_get_windows_systemroot (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_get_windows_systemroot");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_get_windows_systemroot (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_get_windows_systemroot");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_live : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_is_live (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_is_live (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_is_live");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_live (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inspect_is_live");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_multipart : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_is_multipart (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_is_multipart (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_is_multipart");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_multipart (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inspect_is_multipart");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_is_netinst : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_is_netinst (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_is_netinst (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_is_netinst");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_is_netinst (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "inspect_is_netinst");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_list_applications : t -> string -> application array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_list_applications (value gv, value rootv);

CAMLprim value
ocaml_guestfs_inspect_list_applications (value gv, value rootv)
{
  CAMLparam2 (gv, rootv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_list_applications");

  char *root = guestfs_safe_strdup (g, String_val (rootv));
  struct guestfs_application_list *r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_list_applications (g, root);
  caml_leave_blocking_section ();
  free (root);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_list_applications");

  rv = copy_application_list (r);
  guestfs_free_application_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val inspect_os : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_inspect_os (value gv);

CAMLprim value
ocaml_guestfs_inspect_os (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("inspect_os");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_inspect_os (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "inspect_os");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val internal_autosync : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_internal_autosync (value gv);

CAMLprim value
ocaml_guestfs_internal_autosync (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("internal_autosync");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_internal_autosync (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "internal_autosync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_blockdev : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_blockdev (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_blockdev (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_blockdev");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_blockdev (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_blockdev");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_busy : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_busy (value gv);

CAMLprim value
ocaml_guestfs_is_busy (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_busy");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_busy (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_busy");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_chardev : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_chardev (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_chardev (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_chardev");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_chardev (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_chardev");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_config : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_config (value gv);

CAMLprim value
ocaml_guestfs_is_config (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_config");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_config (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_config");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_dir : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_dir (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_dir (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_dir");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_dir (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_dir");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_fifo : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_fifo (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_fifo (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_fifo");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_fifo (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_fifo");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_file : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_file (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_file");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_file");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_launching : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_launching (value gv);

CAMLprim value
ocaml_guestfs_is_launching (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_launching");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_launching (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_launching");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_lv : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_lv (value gv, value devicev);

CAMLprim value
ocaml_guestfs_is_lv (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_lv");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_lv (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_lv");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_ready : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_ready (value gv);

CAMLprim value
ocaml_guestfs_is_ready (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_ready");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_ready (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_ready");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_socket : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_socket (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_socket (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_socket");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_socket (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_socket");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_symlink : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_symlink (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_symlink (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_symlink");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_symlink (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_symlink");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_zero : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_zero (value gv, value pathv);

CAMLprim value
ocaml_guestfs_is_zero (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_zero");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_zero (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_zero");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val is_zero_device : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_is_zero_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_is_zero_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("is_zero_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_is_zero_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "is_zero_device");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val isoinfo : t -> string -> isoinfo
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_isoinfo (value gv, value isofilev);

CAMLprim value
ocaml_guestfs_isoinfo (value gv, value isofilev)
{
  CAMLparam2 (gv, isofilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("isoinfo");

  char *isofile = guestfs_safe_strdup (g, String_val (isofilev));
  struct guestfs_isoinfo *r;

  caml_enter_blocking_section ();
  r = guestfs_isoinfo (g, isofile);
  caml_leave_blocking_section ();
  free (isofile);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "isoinfo");

  rv = copy_isoinfo (r);
  guestfs_free_isoinfo (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val isoinfo_device : t -> string -> isoinfo
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_isoinfo_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_isoinfo_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("isoinfo_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  struct guestfs_isoinfo *r;

  caml_enter_blocking_section ();
  r = guestfs_isoinfo_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "isoinfo_device");

  rv = copy_isoinfo (r);
  guestfs_free_isoinfo (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val kill_subprocess : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_kill_subprocess (value gv);

CAMLprim value
ocaml_guestfs_kill_subprocess (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("kill_subprocess");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_kill_subprocess (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "kill_subprocess");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val launch : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_launch (value gv);

CAMLprim value
ocaml_guestfs_launch (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("launch");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_launch (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "launch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lchown : t -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lchown (value gv, value ownerv, value groupv, value pathv);

CAMLprim value
ocaml_guestfs_lchown (value gv, value ownerv, value groupv, value pathv)
{
  CAMLparam4 (gv, ownerv, groupv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lchown");

  int owner = Int_val (ownerv);
  int group = Int_val (groupv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lchown (g, owner, group, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lchown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lgetxattr : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lgetxattr (value gv, value pathv, value namev);

CAMLprim value
ocaml_guestfs_lgetxattr (value gv, value pathv, value namev)
{
  CAMLparam3 (gv, pathv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lgetxattr");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *name = guestfs_safe_strdup (g, String_val (namev));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_lgetxattr (g, path, name, &size);
  caml_leave_blocking_section ();
  free (path);
  free (name);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lgetxattr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lgetxattrs : t -> string -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lgetxattrs (value gv, value pathv);

CAMLprim value
ocaml_guestfs_lgetxattrs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lgetxattrs");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lgetxattrs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lgetxattrs");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_9p : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_9p (value gv);

CAMLprim value
ocaml_guestfs_list_9p (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_9p");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_9p (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_9p");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_devices (value gv);

CAMLprim value
ocaml_guestfs_list_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_dm_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_dm_devices (value gv);

CAMLprim value
ocaml_guestfs_list_dm_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_dm_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_dm_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_dm_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_filesystems : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_filesystems (value gv);

CAMLprim value
ocaml_guestfs_list_filesystems (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_filesystems");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_filesystems (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_filesystems");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_md_devices : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_md_devices (value gv);

CAMLprim value
ocaml_guestfs_list_md_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_md_devices");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_md_devices (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_md_devices");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val list_partitions : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_list_partitions (value gv);

CAMLprim value
ocaml_guestfs_list_partitions (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("list_partitions");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_list_partitions (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "list_partitions");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ll : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ll (value gv, value directoryv);

CAMLprim value
ocaml_guestfs_ll (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ll");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_ll (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "ll");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val llz : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_llz (value gv, value directoryv);

CAMLprim value
ocaml_guestfs_llz (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("llz");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_llz (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "llz");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ln (value gv, value targetv, value linknamev);

CAMLprim value
ocaml_guestfs_ln (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ln");

  char *target = guestfs_safe_strdup (g, String_val (targetv));
  char *linkname = guestfs_safe_strdup (g, String_val (linknamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ln");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_f : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ln_f (value gv, value targetv, value linknamev);

CAMLprim value
ocaml_guestfs_ln_f (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ln_f");

  char *target = guestfs_safe_strdup (g, String_val (targetv));
  char *linkname = guestfs_safe_strdup (g, String_val (linknamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_f (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ln_f");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_s : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ln_s (value gv, value targetv, value linknamev);

CAMLprim value
ocaml_guestfs_ln_s (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ln_s");

  char *target = guestfs_safe_strdup (g, String_val (targetv));
  char *linkname = guestfs_safe_strdup (g, String_val (linknamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_s (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ln_s");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ln_sf : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ln_sf (value gv, value targetv, value linknamev);

CAMLprim value
ocaml_guestfs_ln_sf (value gv, value targetv, value linknamev)
{
  CAMLparam3 (gv, targetv, linknamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ln_sf");

  char *target = guestfs_safe_strdup (g, String_val (targetv));
  char *linkname = guestfs_safe_strdup (g, String_val (linknamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ln_sf (g, target, linkname);
  caml_leave_blocking_section ();
  free (target);
  free (linkname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ln_sf");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lremovexattr : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lremovexattr (value gv, value xattrv, value pathv);

CAMLprim value
ocaml_guestfs_lremovexattr (value gv, value xattrv, value pathv)
{
  CAMLparam3 (gv, xattrv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lremovexattr");

  char *xattr = guestfs_safe_strdup (g, String_val (xattrv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lremovexattr (g, xattr, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lremovexattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ls : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ls (value gv, value directoryv);

CAMLprim value
ocaml_guestfs_ls (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ls");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_ls (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "ls");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lsetxattr : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lsetxattr (value gv, value xattrv, value valv, value vallenv, value pathv);

CAMLprim value
ocaml_guestfs_lsetxattr (value gv, value xattrv, value valv, value vallenv, value pathv)
{
  CAMLparam5 (gv, xattrv, valv, vallenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lsetxattr");

  char *xattr = guestfs_safe_strdup (g, String_val (xattrv));
  char *val = guestfs_safe_strdup (g, String_val (valv));
  int vallen = Int_val (vallenv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lsetxattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstat : t -> string -> stat
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lstat (value gv, value pathv);

CAMLprim value
ocaml_guestfs_lstat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lstat");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  struct guestfs_stat *r;

  caml_enter_blocking_section ();
  r = guestfs_lstat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lstat");

  rv = copy_stat (r);
  guestfs_free_stat (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lstatlist : t -> string -> string array -> stat array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lstatlist (value gv, value pathv, value namesv);

CAMLprim value
ocaml_guestfs_lstatlist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lstatlist");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char **names = ocaml_guestfs_strings_val (g, namesv);
  struct guestfs_stat_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lstatlist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  ocaml_guestfs_free_strings (names);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lstatlist");

  rv = copy_stat_list (r);
  guestfs_free_stat_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_add_key : t -> string -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_add_key (value gv, value devicev, value keyv, value newkeyv, value keyslotv);

CAMLprim value
ocaml_guestfs_luks_add_key (value gv, value devicev, value keyv, value newkeyv, value keyslotv)
{
  CAMLparam5 (gv, devicev, keyv, newkeyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_add_key");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  char *newkey = guestfs_safe_strdup (g, String_val (newkeyv));
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (newkey);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_add_key");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_close : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_close (value gv, value devicev);

CAMLprim value
ocaml_guestfs_luks_close (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_close");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_close (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_close");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_format : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_format (value gv, value devicev, value keyv, value keyslotv);

CAMLprim value
ocaml_guestfs_luks_format (value gv, value devicev, value keyv, value keyslotv)
{
  CAMLparam4 (gv, devicev, keyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_format");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_format (g, device, key, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_format");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_format_cipher : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_format_cipher (value gv, value devicev, value keyv, value keyslotv, value cipherv);

CAMLprim value
ocaml_guestfs_luks_format_cipher (value gv, value devicev, value keyv, value keyslotv, value cipherv)
{
  CAMLparam5 (gv, devicev, keyv, keyslotv, cipherv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_format_cipher");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  int keyslot = Int_val (keyslotv);
  char *cipher = guestfs_safe_strdup (g, String_val (cipherv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (cipher);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_format_cipher");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_kill_slot : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_kill_slot (value gv, value devicev, value keyv, value keyslotv);

CAMLprim value
ocaml_guestfs_luks_kill_slot (value gv, value devicev, value keyv, value keyslotv)
{
  CAMLparam4 (gv, devicev, keyv, keyslotv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_kill_slot");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  int keyslot = Int_val (keyslotv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_kill_slot");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_open : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_open (value gv, value devicev, value keyv, value mapnamev);

CAMLprim value
ocaml_guestfs_luks_open (value gv, value devicev, value keyv, value mapnamev)
{
  CAMLparam4 (gv, devicev, keyv, mapnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_open");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  char *mapname = guestfs_safe_strdup (g, String_val (mapnamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_open (g, device, key, mapname);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_open");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val luks_open_ro : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_luks_open_ro (value gv, value devicev, value keyv, value mapnamev);

CAMLprim value
ocaml_guestfs_luks_open_ro (value gv, value devicev, value keyv, value mapnamev)
{
  CAMLparam4 (gv, devicev, keyv, mapnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("luks_open_ro");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *key = guestfs_safe_strdup (g, String_val (keyv));
  char *mapname = guestfs_safe_strdup (g, String_val (mapnamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_luks_open_ro (g, device, key, mapname);
  caml_leave_blocking_section ();
  free (device);
  free (key);
  free (mapname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "luks_open_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvcreate : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvcreate (value gv, value logvolv, value volgroupv, value mbytesv);

CAMLprim value
ocaml_guestfs_lvcreate (value gv, value logvolv, value volgroupv, value mbytesv)
{
  CAMLparam4 (gv, logvolv, volgroupv, mbytesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvcreate");

  char *logvol = guestfs_safe_strdup (g, String_val (logvolv));
  char *volgroup = guestfs_safe_strdup (g, String_val (volgroupv));
  int mbytes = Int_val (mbytesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  caml_leave_blocking_section ();
  free (logvol);
  free (volgroup);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvcreate_free : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvcreate_free (value gv, value logvolv, value volgroupv, value percentv);

CAMLprim value
ocaml_guestfs_lvcreate_free (value gv, value logvolv, value volgroupv, value percentv)
{
  CAMLparam4 (gv, logvolv, volgroupv, percentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvcreate_free");

  char *logvol = guestfs_safe_strdup (g, String_val (logvolv));
  char *volgroup = guestfs_safe_strdup (g, String_val (volgroupv));
  int percent = Int_val (percentv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  caml_leave_blocking_section ();
  free (logvol);
  free (volgroup);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvcreate_free");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_canonical_lv_name : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvm_canonical_lv_name (value gv, value lvnamev);

CAMLprim value
ocaml_guestfs_lvm_canonical_lv_name (value gv, value lvnamev)
{
  CAMLparam2 (gv, lvnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvm_canonical_lv_name");

  char *lvname = guestfs_safe_strdup (g, String_val (lvnamev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_canonical_lv_name (g, lvname);
  caml_leave_blocking_section ();
  free (lvname);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lvm_canonical_lv_name");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_clear_filter : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvm_clear_filter (value gv);

CAMLprim value
ocaml_guestfs_lvm_clear_filter (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvm_clear_filter");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_clear_filter (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvm_clear_filter");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_remove_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvm_remove_all (value gv);

CAMLprim value
ocaml_guestfs_lvm_remove_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvm_remove_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_remove_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvm_remove_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvm_set_filter : t -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvm_set_filter (value gv, value devicesv);

CAMLprim value
ocaml_guestfs_lvm_set_filter (value gv, value devicesv)
{
  CAMLparam2 (gv, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvm_set_filter");

  char **devices = ocaml_guestfs_strings_val (g, devicesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvm_set_filter (g, devices);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (devices);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvm_set_filter");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvremove (value gv, value devicev);

CAMLprim value
ocaml_guestfs_lvremove (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvremove");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvremove (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvrename : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvrename (value gv, value logvolv, value newlogvolv);

CAMLprim value
ocaml_guestfs_lvrename (value gv, value logvolv, value newlogvolv)
{
  CAMLparam3 (gv, logvolv, newlogvolv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvrename");

  char *logvol = guestfs_safe_strdup (g, String_val (logvolv));
  char *newlogvol = guestfs_safe_strdup (g, String_val (newlogvolv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvrename (g, logvol, newlogvol);
  caml_leave_blocking_section ();
  free (logvol);
  free (newlogvol);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvrename");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvresize : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvresize (value gv, value devicev, value mbytesv);

CAMLprim value
ocaml_guestfs_lvresize (value gv, value devicev, value mbytesv)
{
  CAMLparam3 (gv, devicev, mbytesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvresize");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int mbytes = Int_val (mbytesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvresize (g, device, mbytes);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvresize_free : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvresize_free (value gv, value lvv, value percentv);

CAMLprim value
ocaml_guestfs_lvresize_free (value gv, value lvv, value percentv)
{
  CAMLparam3 (gv, lvv, percentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvresize_free");

  char *lv = guestfs_safe_strdup (g, String_val (lvv));
  int percent = Int_val (percentv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_lvresize_free (g, lv, percent);
  caml_leave_blocking_section ();
  free (lv);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "lvresize_free");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvs (value gv);

CAMLprim value
ocaml_guestfs_lvs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_lvs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lvs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvs_full : t -> lvm_lv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvs_full (value gv);

CAMLprim value
ocaml_guestfs_lvs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvs_full");

  struct guestfs_lvm_lv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lvs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lvs_full");

  rv = copy_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lvuuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lvuuid (value gv, value devicev);

CAMLprim value
ocaml_guestfs_lvuuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lvuuid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_lvuuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lvuuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val lxattrlist : t -> string -> string array -> xattr array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_lxattrlist (value gv, value pathv, value namesv);

CAMLprim value
ocaml_guestfs_lxattrlist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("lxattrlist");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char **names = ocaml_guestfs_strings_val (g, namesv);
  struct guestfs_xattr_list *r;

  caml_enter_blocking_section ();
  r = guestfs_lxattrlist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  ocaml_guestfs_free_strings (names);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "lxattrlist");

  rv = copy_xattr_list (r);
  guestfs_free_xattr_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_create : t -> ?missingbitmap:int64 -> ?nrdevices:int -> ?spare:int -> ?chunk:int64 -> ?level:string -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_md_create (value gv, value missingbitmapv, value nrdevicesv, value sparev, value chunkv, value levelv, value namev, value devicesv);

CAMLprim value
ocaml_guestfs_md_create (value gv, value missingbitmapv, value nrdevicesv, value sparev, value chunkv, value levelv, value namev, value devicesv)
{
  CAMLparam5 (gv, missingbitmapv, nrdevicesv, sparev, chunkv);
  CAMLxparam3 (levelv, namev, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("md_create");

  char *name = guestfs_safe_strdup (g, String_val (namev));
  char **devices = ocaml_guestfs_strings_val (g, devicesv);
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
    optargs_s.level = guestfs_safe_strdup (g, String_val (Field (levelv, 0)));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_md_create_argv (g, name, devices, optargs);
  caml_leave_blocking_section ();
  free (name);
  ocaml_guestfs_free_strings (devices);
  if (levelv != Val_int (0))
    free ((char *) optargs_s.level);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "md_create");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_md_create_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_md_create_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_md_create (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val md_detail : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_md_detail (value gv, value mdv);

CAMLprim value
ocaml_guestfs_md_detail (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("md_detail");

  char *md = guestfs_safe_strdup (g, String_val (mdv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_md_detail (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "md_detail");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_stat : t -> string -> mdstat array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_md_stat (value gv, value mdv);

CAMLprim value
ocaml_guestfs_md_stat (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("md_stat");

  char *md = guestfs_safe_strdup (g, String_val (mdv));
  struct guestfs_mdstat_list *r;

  caml_enter_blocking_section ();
  r = guestfs_md_stat (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "md_stat");

  rv = copy_mdstat_list (r);
  guestfs_free_mdstat_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val md_stop : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_md_stop (value gv, value mdv);

CAMLprim value
ocaml_guestfs_md_stop (value gv, value mdv)
{
  CAMLparam2 (gv, mdv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("md_stop");

  char *md = guestfs_safe_strdup (g, String_val (mdv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_md_stop (g, md);
  caml_leave_blocking_section ();
  free (md);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "md_stop");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkdir (value gv, value pathv);

CAMLprim value
ocaml_guestfs_mkdir (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkdir");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkdir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir_mode : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkdir_mode (value gv, value pathv, value modev);

CAMLprim value
ocaml_guestfs_mkdir_mode (value gv, value pathv, value modev)
{
  CAMLparam3 (gv, pathv, modev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkdir_mode");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int mode = Int_val (modev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir_mode (g, path, mode);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkdir_mode");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdir_p : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkdir_p (value gv, value pathv);

CAMLprim value
ocaml_guestfs_mkdir_p (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkdir_p");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkdir_p (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkdir_p");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkdtemp : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkdtemp (value gv, value tmplv);

CAMLprim value
ocaml_guestfs_mkdtemp (value gv, value tmplv)
{
  CAMLparam2 (gv, tmplv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkdtemp");

  char *tmpl = guestfs_safe_strdup (g, String_val (tmplv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_mkdtemp (g, tmpl);
  caml_leave_blocking_section ();
  free (tmpl);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "mkdtemp");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs_J : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2fs_J (value gv, value fstypev, value blocksizev, value devicev, value journalv);

CAMLprim value
ocaml_guestfs_mke2fs_J (value gv, value fstypev, value blocksizev, value devicev, value journalv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, journalv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2fs_J");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  int blocksize = Int_val (blocksizev);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *journal = guestfs_safe_strdup (g, String_val (journalv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (journal);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2fs_J");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs_JL : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2fs_JL (value gv, value fstypev, value blocksizev, value devicev, value labelv);

CAMLprim value
ocaml_guestfs_mke2fs_JL (value gv, value fstypev, value blocksizev, value devicev, value labelv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2fs_JL");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  int blocksize = Int_val (blocksizev);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2fs_JL");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2fs_JU : t -> string -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2fs_JU (value gv, value fstypev, value blocksizev, value devicev, value uuidv);

CAMLprim value
ocaml_guestfs_mke2fs_JU (value gv, value fstypev, value blocksizev, value devicev, value uuidv)
{
  CAMLparam5 (gv, fstypev, blocksizev, devicev, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2fs_JU");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  int blocksize = Int_val (blocksizev);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  free (uuid);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2fs_JU");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2journal (value gv, value blocksizev, value devicev);

CAMLprim value
ocaml_guestfs_mke2journal (value gv, value blocksizev, value devicev)
{
  CAMLparam3 (gv, blocksizev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2journal");

  int blocksize = Int_val (blocksizev);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal (g, blocksize, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2journal");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal_L : t -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2journal_L (value gv, value blocksizev, value labelv, value devicev);

CAMLprim value
ocaml_guestfs_mke2journal_L (value gv, value blocksizev, value labelv, value devicev)
{
  CAMLparam4 (gv, blocksizev, labelv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2journal_L");

  int blocksize = Int_val (blocksizev);
  char *label = guestfs_safe_strdup (g, String_val (labelv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal_L (g, blocksize, label, device);
  caml_leave_blocking_section ();
  free (label);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2journal_L");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mke2journal_U : t -> int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mke2journal_U (value gv, value blocksizev, value uuidv, value devicev);

CAMLprim value
ocaml_guestfs_mke2journal_U (value gv, value blocksizev, value uuidv, value devicev)
{
  CAMLparam4 (gv, blocksizev, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mke2journal_U");

  int blocksize = Int_val (blocksizev);
  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  caml_leave_blocking_section ();
  free (uuid);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mke2journal_U");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfifo : t -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfifo (value gv, value modev, value pathv);

CAMLprim value
ocaml_guestfs_mkfifo (value gv, value modev, value pathv)
{
  CAMLparam3 (gv, modev, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkfifo");

  int mode = Int_val (modev);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfifo (g, mode, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkfifo");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfs : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs (value gv, value fstypev, value devicev);

CAMLprim value
ocaml_guestfs_mkfs (value gv, value fstypev, value devicev)
{
  CAMLparam3 (gv, fstypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkfs");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs (g, fstype, device);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfs_b : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs_b (value gv, value fstypev, value blocksizev, value devicev);

CAMLprim value
ocaml_guestfs_mkfs_b (value gv, value fstypev, value blocksizev, value devicev)
{
  CAMLparam4 (gv, fstypev, blocksizev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkfs_b");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  int blocksize = Int_val (blocksizev);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkfs_b");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkfs_btrfs : t -> ?allocstart:int64 -> ?bytecount:int64 -> ?datatype:string -> ?leafsize:int -> ?label:string -> ?metadata:string -> ?nodesize:int -> ?sectorsize:int -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs_btrfs (value gv, value allocstartv, value bytecountv, value datatypev, value leafsizev, value labelv, value metadatav, value nodesizev, value sectorsizev, value devicesv);

CAMLprim value
ocaml_guestfs_mkfs_btrfs (value gv, value allocstartv, value bytecountv, value datatypev, value leafsizev, value labelv, value metadatav, value nodesizev, value sectorsizev, value devicesv)
{
  CAMLparam5 (gv, allocstartv, bytecountv, datatypev, leafsizev);
  CAMLxparam5 (labelv, metadatav, nodesizev, sectorsizev, devicesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkfs_btrfs");

  char **devices = ocaml_guestfs_strings_val (g, devicesv);
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
    optargs_s.datatype = guestfs_safe_strdup (g, String_val (Field (datatypev, 0)));
  }
  if (leafsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
    optargs_s.leafsize = Int_val (Field (leafsizev, 0));
  }
  if (labelv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
    optargs_s.label = guestfs_safe_strdup (g, String_val (Field (labelv, 0)));
  }
  if (metadatav != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
    optargs_s.metadata = guestfs_safe_strdup (g, String_val (Field (metadatav, 0)));
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
  ocaml_guestfs_free_strings (devices);
  if (datatypev != Val_int (0))
    free ((char *) optargs_s.datatype);
  if (labelv != Val_int (0))
    free ((char *) optargs_s.label);
  if (metadatav != Val_int (0))
    free ((char *) optargs_s.metadata);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkfs_btrfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs_btrfs_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_mkfs_btrfs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_mkfs_btrfs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

/* Automatically generated wrapper for function
 * val mkfs_opts : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs_opts (value gv, value blocksizev, value featuresv, value inodev, value sectorsizev, value fstypev, value devicev);

CAMLprim value
ocaml_guestfs_mkfs_opts (value gv, value blocksizev, value featuresv, value inodev, value sectorsizev, value fstypev, value devicev)
{
  CAMLparam5 (gv, blocksizev, featuresv, inodev, sectorsizev);
  CAMLxparam2 (fstypev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkfs_opts");

  char *fstype = guestfs_safe_strdup (g, String_val (fstypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  if (blocksizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = Int_val (Field (blocksizev, 0));
  }
  if (featuresv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
    optargs_s.features = guestfs_safe_strdup (g, String_val (Field (featuresv, 0)));
  }
  if (inodev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
    optargs_s.inode = Int_val (Field (inodev, 0));
  }
  if (sectorsizev != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = Int_val (Field (sectorsizev, 0));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  caml_leave_blocking_section ();
  free (fstype);
  free (device);
  if (featuresv != Val_int (0))
    free ((char *) optargs_s.features);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkfs_opts");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkfs_opts_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_mkfs_opts_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_mkfs_opts (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val mkmountpoint : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkmountpoint (value gv, value exemptpathv);

CAMLprim value
ocaml_guestfs_mkmountpoint (value gv, value exemptpathv)
{
  CAMLparam2 (gv, exemptpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkmountpoint");

  char *exemptpath = guestfs_safe_strdup (g, String_val (exemptpathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkmountpoint (g, exemptpath);
  caml_leave_blocking_section ();
  free (exemptpath);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkmountpoint");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mknod (value gv, value modev, value devmajorv, value devminorv, value pathv);

CAMLprim value
ocaml_guestfs_mknod (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mknod");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mknod");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod_b : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mknod_b (value gv, value modev, value devmajorv, value devminorv, value pathv);

CAMLprim value
ocaml_guestfs_mknod_b (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mknod_b");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mknod_b");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mknod_c : t -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mknod_c (value gv, value modev, value devmajorv, value devminorv, value pathv);

CAMLprim value
ocaml_guestfs_mknod_c (value gv, value modev, value devmajorv, value devminorv, value pathv)
{
  CAMLparam5 (gv, modev, devmajorv, devminorv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mknod_c");

  int mode = Int_val (modev);
  int devmajor = Int_val (devmajorv);
  int devminor = Int_val (devminorv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mknod_c");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkswap (value gv, value devicev);

CAMLprim value
ocaml_guestfs_mkswap (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkswap");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkswap");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_L : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkswap_L (value gv, value labelv, value devicev);

CAMLprim value
ocaml_guestfs_mkswap_L (value gv, value labelv, value devicev)
{
  CAMLparam3 (gv, labelv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkswap_L");

  char *label = guestfs_safe_strdup (g, String_val (labelv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_L (g, label, device);
  caml_leave_blocking_section ();
  free (label);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkswap_L");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_U : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkswap_U (value gv, value uuidv, value devicev);

CAMLprim value
ocaml_guestfs_mkswap_U (value gv, value uuidv, value devicev)
{
  CAMLparam3 (gv, uuidv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkswap_U");

  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_U (g, uuid, device);
  caml_leave_blocking_section ();
  free (uuid);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkswap_U");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mkswap_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mkswap_file (value gv, value pathv);

CAMLprim value
ocaml_guestfs_mkswap_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mkswap_file");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mkswap_file (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mkswap_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val modprobe : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_modprobe (value gv, value modulenamev);

CAMLprim value
ocaml_guestfs_modprobe (value gv, value modulenamev)
{
  CAMLparam2 (gv, modulenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("modprobe");

  char *modulename = guestfs_safe_strdup (g, String_val (modulenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_modprobe (g, modulename);
  caml_leave_blocking_section ();
  free (modulename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "modprobe");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount (value gv, value devicev, value mountpointv);

CAMLprim value
ocaml_guestfs_mount (value gv, value devicev, value mountpointv)
{
  CAMLparam3 (gv, devicev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount (g, device, mountpoint);
  caml_leave_blocking_section ();
  free (device);
  free (mountpoint);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_9p : t -> ?options:string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_9p (value gv, value optionsv, value mounttagv, value mountpointv);

CAMLprim value
ocaml_guestfs_mount_9p (value gv, value optionsv, value mounttagv, value mountpointv)
{
  CAMLparam4 (gv, optionsv, mounttagv, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_9p");

  char *mounttag = guestfs_safe_strdup (g, String_val (mounttagv));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  if (optionsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
    optargs_s.options = guestfs_safe_strdup (g, String_val (Field (optionsv, 0)));
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
    ocaml_guestfs_raise_error (g, "mount_9p");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_local : t -> ?readonly:bool -> ?options:string -> ?cachetimeout:int -> ?debugcalls:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_local (value gv, value readonlyv, value optionsv, value cachetimeoutv, value debugcallsv, value localmountpointv);

CAMLprim value
ocaml_guestfs_mount_local (value gv, value readonlyv, value optionsv, value cachetimeoutv, value debugcallsv, value localmountpointv)
{
  CAMLparam5 (gv, readonlyv, optionsv, cachetimeoutv, debugcallsv);
  CAMLxparam1 (localmountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_local");

  char *localmountpoint = guestfs_safe_strdup (g, String_val (localmountpointv));
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  if (readonlyv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
    optargs_s.readonly = Bool_val (Field (readonlyv, 0));
  }
  if (optionsv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
    optargs_s.options = guestfs_safe_strdup (g, String_val (Field (optionsv, 0)));
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
    ocaml_guestfs_raise_error (g, "mount_local");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_local_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_mount_local_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_mount_local (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val mount_local_run : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_local_run (value gv);

CAMLprim value
ocaml_guestfs_mount_local_run (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_local_run");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_local_run (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount_local_run");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_loop : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_loop (value gv, value filev, value mountpointv);

CAMLprim value
ocaml_guestfs_mount_loop (value gv, value filev, value mountpointv)
{
  CAMLparam3 (gv, filev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_loop");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_loop (g, file, mountpoint);
  caml_leave_blocking_section ();
  free (file);
  free (mountpoint);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount_loop");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_options : t -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_options (value gv, value optionsv, value devicev, value mountpointv);

CAMLprim value
ocaml_guestfs_mount_options (value gv, value optionsv, value devicev, value mountpointv)
{
  CAMLparam4 (gv, optionsv, devicev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_options");

  char *options = guestfs_safe_strdup (g, String_val (optionsv));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_options (g, options, device, mountpoint);
  caml_leave_blocking_section ();
  free (options);
  free (device);
  free (mountpoint);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount_options");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_ro : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_ro (value gv, value devicev, value mountpointv);

CAMLprim value
ocaml_guestfs_mount_ro (value gv, value devicev, value mountpointv)
{
  CAMLparam3 (gv, devicev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_ro");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_ro (g, device, mountpoint);
  caml_leave_blocking_section ();
  free (device);
  free (mountpoint);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount_ro");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mount_vfs : t -> string -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mount_vfs (value gv, value optionsv, value vfstypev, value devicev, value mountpointv);

CAMLprim value
ocaml_guestfs_mount_vfs (value gv, value optionsv, value vfstypev, value devicev, value mountpointv)
{
  CAMLparam5 (gv, optionsv, vfstypev, devicev, mountpointv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mount_vfs");

  char *options = guestfs_safe_strdup (g, String_val (optionsv));
  char *vfstype = guestfs_safe_strdup (g, String_val (vfstypev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *mountpoint = guestfs_safe_strdup (g, String_val (mountpointv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
  caml_leave_blocking_section ();
  free (options);
  free (vfstype);
  free (device);
  free (mountpoint);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mount_vfs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mountpoints : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mountpoints (value gv);

CAMLprim value
ocaml_guestfs_mountpoints (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mountpoints");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_mountpoints (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "mountpoints");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mounts : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mounts (value gv);

CAMLprim value
ocaml_guestfs_mounts (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mounts");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_mounts (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "mounts");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val mv : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_mv (value gv, value srcv, value destv);

CAMLprim value
ocaml_guestfs_mv (value gv, value srcv, value destv)
{
  CAMLparam3 (gv, srcv, destv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("mv");

  char *src = guestfs_safe_strdup (g, String_val (srcv));
  char *dest = guestfs_safe_strdup (g, String_val (destv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_mv (g, src, dest);
  caml_leave_blocking_section ();
  free (src);
  free (dest);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "mv");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val nr_devices : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_nr_devices (value gv);

CAMLprim value
ocaml_guestfs_nr_devices (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("nr_devices");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_nr_devices (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "nr_devices");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfs_3g_probe : t -> bool -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfs_3g_probe (value gv, value rwv, value devicev);

CAMLprim value
ocaml_guestfs_ntfs_3g_probe (value gv, value rwv, value devicev)
{
  CAMLparam3 (gv, rwv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfs_3g_probe");

  int rw = Bool_val (rwv);
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfs_3g_probe (g, rw, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ntfs_3g_probe");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsclone_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsclone_in (value gv, value backupfilev, value devicev);

CAMLprim value
ocaml_guestfs_ntfsclone_in (value gv, value backupfilev, value devicev)
{
  CAMLparam3 (gv, backupfilev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsclone_in");

  char *backupfile = guestfs_safe_strdup (g, String_val (backupfilev));
  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsclone_in (g, backupfile, device);
  caml_leave_blocking_section ();
  free (backupfile);
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ntfsclone_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsclone_out : t -> ?metadataonly:bool -> ?rescue:bool -> ?ignorefscheck:bool -> ?preservetimestamps:bool -> ?force:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsclone_out (value gv, value metadataonlyv, value rescuev, value ignorefscheckv, value preservetimestampsv, value forcev, value devicev, value backupfilev);

CAMLprim value
ocaml_guestfs_ntfsclone_out (value gv, value metadataonlyv, value rescuev, value ignorefscheckv, value preservetimestampsv, value forcev, value devicev, value backupfilev)
{
  CAMLparam5 (gv, metadataonlyv, rescuev, ignorefscheckv, preservetimestampsv);
  CAMLxparam3 (forcev, devicev, backupfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsclone_out");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *backupfile = guestfs_safe_strdup (g, String_val (backupfilev));
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
    ocaml_guestfs_raise_error (g, "ntfsclone_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsclone_out_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_ntfsclone_out_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_ntfsclone_out (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

/* Automatically generated wrapper for function
 * val ntfsfix : t -> ?clearbadsectors:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsfix (value gv, value clearbadsectorsv, value devicev);

CAMLprim value
ocaml_guestfs_ntfsfix (value gv, value clearbadsectorsv, value devicev)
{
  CAMLparam3 (gv, clearbadsectorsv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsfix");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
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
    ocaml_guestfs_raise_error (g, "ntfsfix");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsresize : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsresize (value gv, value devicev);

CAMLprim value
ocaml_guestfs_ntfsresize (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsresize");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsresize (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ntfsresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsresize_opts : t -> ?size:int64 -> ?force:bool -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsresize_opts (value gv, value sizev, value forcev, value devicev);

CAMLprim value
ocaml_guestfs_ntfsresize_opts (value gv, value sizev, value forcev, value devicev)
{
  CAMLparam4 (gv, sizev, forcev, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsresize_opts");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
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
    ocaml_guestfs_raise_error (g, "ntfsresize_opts");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ntfsresize_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ntfsresize_size (value gv, value devicev, value sizev);

CAMLprim value
ocaml_guestfs_ntfsresize_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ntfsresize_size");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_ntfsresize_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ntfsresize_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_add : t -> string -> string -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_add (value gv, value devicev, value prlogexv, value startsectv, value endsectv);

CAMLprim value
ocaml_guestfs_part_add (value gv, value devicev, value prlogexv, value startsectv, value endsectv)
{
  CAMLparam5 (gv, devicev, prlogexv, startsectv, endsectv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_add");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *prlogex = guestfs_safe_strdup (g, String_val (prlogexv));
  int64_t startsect = Int64_val (startsectv);
  int64_t endsect = Int64_val (endsectv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  caml_leave_blocking_section ();
  free (device);
  free (prlogex);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_add");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_del : t -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_del (value gv, value devicev, value partnumv);

CAMLprim value
ocaml_guestfs_part_del (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_del");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_del (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_del");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_disk : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_disk (value gv, value devicev, value parttypev);

CAMLprim value
ocaml_guestfs_part_disk (value gv, value devicev, value parttypev)
{
  CAMLparam3 (gv, devicev, parttypev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_disk");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *parttype = guestfs_safe_strdup (g, String_val (parttypev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_disk (g, device, parttype);
  caml_leave_blocking_section ();
  free (device);
  free (parttype);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_disk");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_bootable : t -> string -> int -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_get_bootable (value gv, value devicev, value partnumv);

CAMLprim value
ocaml_guestfs_part_get_bootable (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_get_bootable");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_bootable (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_get_bootable");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_mbr_id : t -> string -> int -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_get_mbr_id (value gv, value devicev, value partnumv);

CAMLprim value
ocaml_guestfs_part_get_mbr_id (value gv, value devicev, value partnumv)
{
  CAMLparam3 (gv, devicev, partnumv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_get_mbr_id");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_mbr_id (g, device, partnum);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_get_mbr_id");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_get_parttype : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_get_parttype (value gv, value devicev);

CAMLprim value
ocaml_guestfs_part_get_parttype (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_get_parttype");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_get_parttype (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "part_get_parttype");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_init : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_init (value gv, value devicev, value parttypev);

CAMLprim value
ocaml_guestfs_part_init (value gv, value devicev, value parttypev)
{
  CAMLparam3 (gv, devicev, parttypev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_init");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *parttype = guestfs_safe_strdup (g, String_val (parttypev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_init (g, device, parttype);
  caml_leave_blocking_section ();
  free (device);
  free (parttype);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_init");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_list : t -> string -> partition array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_list (value gv, value devicev);

CAMLprim value
ocaml_guestfs_part_list (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_list");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  struct guestfs_partition_list *r;

  caml_enter_blocking_section ();
  r = guestfs_part_list (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "part_list");

  rv = copy_partition_list (r);
  guestfs_free_partition_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_bootable : t -> string -> int -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_set_bootable (value gv, value devicev, value partnumv, value bootablev);

CAMLprim value
ocaml_guestfs_part_set_bootable (value gv, value devicev, value partnumv, value bootablev)
{
  CAMLparam4 (gv, devicev, partnumv, bootablev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_set_bootable");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int bootable = Bool_val (bootablev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_set_bootable");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_mbr_id : t -> string -> int -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_set_mbr_id (value gv, value devicev, value partnumv, value idbytev);

CAMLprim value
ocaml_guestfs_part_set_mbr_id (value gv, value devicev, value partnumv, value idbytev)
{
  CAMLparam4 (gv, devicev, partnumv, idbytev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_set_mbr_id");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int idbyte = Int_val (idbytev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_set_mbr_id");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_set_name : t -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_set_name (value gv, value devicev, value partnumv, value namev);

CAMLprim value
ocaml_guestfs_part_set_name (value gv, value devicev, value partnumv, value namev)
{
  CAMLparam4 (gv, devicev, partnumv, namev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_set_name");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  char *name = guestfs_safe_strdup (g, String_val (namev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_set_name (g, device, partnum, name);
  caml_leave_blocking_section ();
  free (device);
  free (name);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_set_name");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_to_dev : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_to_dev (value gv, value partitionv);

CAMLprim value
ocaml_guestfs_part_to_dev (value gv, value partitionv)
{
  CAMLparam2 (gv, partitionv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_to_dev");

  char *partition = guestfs_safe_strdup (g, String_val (partitionv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_part_to_dev (g, partition);
  caml_leave_blocking_section ();
  free (partition);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "part_to_dev");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val part_to_partnum : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_part_to_partnum (value gv, value partitionv);

CAMLprim value
ocaml_guestfs_part_to_partnum (value gv, value partitionv)
{
  CAMLparam2 (gv, partitionv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("part_to_partnum");

  char *partition = guestfs_safe_strdup (g, String_val (partitionv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_part_to_partnum (g, partition);
  caml_leave_blocking_section ();
  free (partition);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "part_to_partnum");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val ping_daemon : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_ping_daemon (value gv);

CAMLprim value
ocaml_guestfs_ping_daemon (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("ping_daemon");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_ping_daemon (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "ping_daemon");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pread : t -> string -> int -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pread (value gv, value pathv, value countv, value offsetv);

CAMLprim value
ocaml_guestfs_pread (value gv, value pathv, value countv, value offsetv)
{
  CAMLparam4 (gv, pathv, countv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pread");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int count = Int_val (countv);
  int64_t offset = Int64_val (offsetv);
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_pread (g, path, count, offset, &size);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "pread");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pread_device : t -> string -> int -> int64 -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pread_device (value gv, value devicev, value countv, value offsetv);

CAMLprim value
ocaml_guestfs_pread_device (value gv, value devicev, value countv, value offsetv)
{
  CAMLparam4 (gv, devicev, countv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pread_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int count = Int_val (countv);
  int64_t offset = Int64_val (offsetv);
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_pread_device (g, device, count, offset, &size);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "pread_device");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvcreate : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvcreate (value gv, value devicev);

CAMLprim value
ocaml_guestfs_pvcreate (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvcreate");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvcreate (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pvcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvremove (value gv, value devicev);

CAMLprim value
ocaml_guestfs_pvremove (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvremove");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvremove (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pvremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvresize : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvresize (value gv, value devicev);

CAMLprim value
ocaml_guestfs_pvresize (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvresize");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvresize (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pvresize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvresize_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvresize_size (value gv, value devicev, value sizev);

CAMLprim value
ocaml_guestfs_pvresize_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvresize_size");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pvresize_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pvresize_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvs (value gv);

CAMLprim value
ocaml_guestfs_pvs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_pvs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "pvs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvs_full : t -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvs_full (value gv);

CAMLprim value
ocaml_guestfs_pvs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvs_full");

  struct guestfs_lvm_pv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_pvs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "pvs_full");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pvuuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pvuuid (value gv, value devicev);

CAMLprim value
ocaml_guestfs_pvuuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pvuuid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_pvuuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "pvuuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pwrite : t -> string -> string -> int64 -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pwrite (value gv, value pathv, value contentv, value offsetv);

CAMLprim value
ocaml_guestfs_pwrite (value gv, value pathv, value contentv, value offsetv)
{
  CAMLparam4 (gv, pathv, contentv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pwrite");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t content_size = caml_string_length (contentv);
  char *content = guestfs_safe_memdup (g, String_val (contentv), content_size);
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pwrite (g, path, content, content_size, offset);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pwrite");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val pwrite_device : t -> string -> string -> int64 -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_pwrite_device (value gv, value devicev, value contentv, value offsetv);

CAMLprim value
ocaml_guestfs_pwrite_device (value gv, value devicev, value contentv, value offsetv)
{
  CAMLparam4 (gv, devicev, contentv, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("pwrite_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  size_t content_size = caml_string_length (contentv);
  char *content = guestfs_safe_memdup (g, String_val (contentv), content_size);
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  caml_leave_blocking_section ();
  free (device);
  free (content);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "pwrite_device");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val read_file : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_read_file (value gv, value pathv);

CAMLprim value
ocaml_guestfs_read_file (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("read_file");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_read_file (g, path, &size);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "read_file");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val read_lines : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_read_lines (value gv, value pathv);

CAMLprim value
ocaml_guestfs_read_lines (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("read_lines");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_read_lines (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "read_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readdir : t -> string -> dirent array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_readdir (value gv, value dirv);

CAMLprim value
ocaml_guestfs_readdir (value gv, value dirv)
{
  CAMLparam2 (gv, dirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("readdir");

  char *dir = guestfs_safe_strdup (g, String_val (dirv));
  struct guestfs_dirent_list *r;

  caml_enter_blocking_section ();
  r = guestfs_readdir (g, dir);
  caml_leave_blocking_section ();
  free (dir);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "readdir");

  rv = copy_dirent_list (r);
  guestfs_free_dirent_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readlink : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_readlink (value gv, value pathv);

CAMLprim value
ocaml_guestfs_readlink (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("readlink");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_readlink (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "readlink");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val readlinklist : t -> string -> string array -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_readlinklist (value gv, value pathv, value namesv);

CAMLprim value
ocaml_guestfs_readlinklist (value gv, value pathv, value namesv)
{
  CAMLparam3 (gv, pathv, namesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("readlinklist");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char **names = ocaml_guestfs_strings_val (g, namesv);
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_readlinklist (g, path, names);
  caml_leave_blocking_section ();
  free (path);
  ocaml_guestfs_free_strings (names);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "readlinklist");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val realpath : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_realpath (value gv, value pathv);

CAMLprim value
ocaml_guestfs_realpath (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("realpath");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_realpath (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "realpath");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val removexattr : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_removexattr (value gv, value xattrv, value pathv);

CAMLprim value
ocaml_guestfs_removexattr (value gv, value xattrv, value pathv)
{
  CAMLparam3 (gv, xattrv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("removexattr");

  char *xattr = guestfs_safe_strdup (g, String_val (xattrv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_removexattr (g, xattr, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "removexattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_resize2fs (value gv, value devicev);

CAMLprim value
ocaml_guestfs_resize2fs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("resize2fs");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "resize2fs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs_M : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_resize2fs_M (value gv, value devicev);

CAMLprim value
ocaml_guestfs_resize2fs_M (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("resize2fs_M");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs_M (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "resize2fs_M");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val resize2fs_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_resize2fs_size (value gv, value devicev, value sizev);

CAMLprim value
ocaml_guestfs_resize2fs_size (value gv, value devicev, value sizev)
{
  CAMLparam3 (gv, devicev, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("resize2fs_size");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_resize2fs_size (g, device, size);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "resize2fs_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rm : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_rm (value gv, value pathv);

CAMLprim value
ocaml_guestfs_rm (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("rm");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rm (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "rm");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rm_rf : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_rm_rf (value gv, value pathv);

CAMLprim value
ocaml_guestfs_rm_rf (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("rm_rf");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rm_rf (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "rm_rf");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rmdir : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_rmdir (value gv, value pathv);

CAMLprim value
ocaml_guestfs_rmdir (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("rmdir");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rmdir (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "rmdir");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val rmmountpoint : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_rmmountpoint (value gv, value exemptpathv);

CAMLprim value
ocaml_guestfs_rmmountpoint (value gv, value exemptpathv)
{
  CAMLparam2 (gv, exemptpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("rmmountpoint");

  char *exemptpath = guestfs_safe_strdup (g, String_val (exemptpathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_rmmountpoint (g, exemptpath);
  caml_leave_blocking_section ();
  free (exemptpath);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "rmmountpoint");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_scrub_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_scrub_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("scrub_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "scrub_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_scrub_file (value gv, value filev);

CAMLprim value
ocaml_guestfs_scrub_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("scrub_file");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "scrub_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val scrub_freespace : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_scrub_freespace (value gv, value dirv);

CAMLprim value
ocaml_guestfs_scrub_freespace (value gv, value dirv)
{
  CAMLparam2 (gv, dirv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("scrub_freespace");

  char *dir = guestfs_safe_strdup (g, String_val (dirv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_scrub_freespace (g, dir);
  caml_leave_blocking_section ();
  free (dir);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "scrub_freespace");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_append : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_append (value gv, value appendv);

CAMLprim value
ocaml_guestfs_set_append (value gv, value appendv)
{
  CAMLparam2 (gv, appendv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_append");

  char *append =
    appendv != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (appendv, 0))) : NULL;
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_append (g, append);
  caml_leave_blocking_section ();
  free (append);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_append");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_attach_method : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_attach_method (value gv, value attachmethodv);

CAMLprim value
ocaml_guestfs_set_attach_method (value gv, value attachmethodv)
{
  CAMLparam2 (gv, attachmethodv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_attach_method");

  char *attachmethod = guestfs_safe_strdup (g, String_val (attachmethodv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_attach_method (g, attachmethod);
  caml_leave_blocking_section ();
  free (attachmethod);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_attach_method");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_autosync : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_autosync (value gv, value autosyncv);

CAMLprim value
ocaml_guestfs_set_autosync (value gv, value autosyncv)
{
  CAMLparam2 (gv, autosyncv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_autosync");

  int autosync = Bool_val (autosyncv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_autosync (g, autosync);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_autosync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_direct : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_direct (value gv, value directv);

CAMLprim value
ocaml_guestfs_set_direct (value gv, value directv)
{
  CAMLparam2 (gv, directv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_direct");

  int direct = Bool_val (directv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_direct (g, direct);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_direct");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2attrs : t -> ?clear:bool -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_e2attrs (value gv, value clearv, value filev, value attrsv);

CAMLprim value
ocaml_guestfs_set_e2attrs (value gv, value clearv, value filev, value attrsv)
{
  CAMLparam4 (gv, clearv, filev, attrsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_e2attrs");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  char *attrs = guestfs_safe_strdup (g, String_val (attrsv));
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
    ocaml_guestfs_raise_error (g, "set_e2attrs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2generation : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_e2generation (value gv, value filev, value generationv);

CAMLprim value
ocaml_guestfs_set_e2generation (value gv, value filev, value generationv)
{
  CAMLparam3 (gv, filev, generationv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_e2generation");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int64_t generation = Int64_val (generationv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2generation (g, file, generation);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_e2generation");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2label : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_e2label (value gv, value devicev, value labelv);

CAMLprim value
ocaml_guestfs_set_e2label (value gv, value devicev, value labelv)
{
  CAMLparam3 (gv, devicev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_e2label");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2label (g, device, label);
  caml_leave_blocking_section ();
  free (device);
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_e2label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_e2uuid : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_e2uuid (value gv, value devicev, value uuidv);

CAMLprim value
ocaml_guestfs_set_e2uuid (value gv, value devicev, value uuidv)
{
  CAMLparam3 (gv, devicev, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_e2uuid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_e2uuid (g, device, uuid);
  caml_leave_blocking_section ();
  free (device);
  free (uuid);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_e2uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_label : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_label (value gv, value devicev, value labelv);

CAMLprim value
ocaml_guestfs_set_label (value gv, value devicev, value labelv)
{
  CAMLparam3 (gv, devicev, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_label");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_label (g, device, label);
  caml_leave_blocking_section ();
  free (device);
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_memsize : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_memsize (value gv, value memsizev);

CAMLprim value
ocaml_guestfs_set_memsize (value gv, value memsizev)
{
  CAMLparam2 (gv, memsizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_memsize");

  int memsize = Int_val (memsizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_memsize (g, memsize);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_memsize");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_network : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_network (value gv, value networkv);

CAMLprim value
ocaml_guestfs_set_network (value gv, value networkv)
{
  CAMLparam2 (gv, networkv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_network");

  int network = Bool_val (networkv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_network (g, network);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_network");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_path : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_path (value gv, value searchpathv);

CAMLprim value
ocaml_guestfs_set_path (value gv, value searchpathv)
{
  CAMLparam2 (gv, searchpathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_path");

  char *searchpath =
    searchpathv != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (searchpathv, 0))) : NULL;
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_path (g, searchpath);
  caml_leave_blocking_section ();
  free (searchpath);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_path");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_pgroup : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_pgroup (value gv, value pgroupv);

CAMLprim value
ocaml_guestfs_set_pgroup (value gv, value pgroupv)
{
  CAMLparam2 (gv, pgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_pgroup");

  int pgroup = Bool_val (pgroupv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_pgroup (g, pgroup);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_pgroup");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_qemu : t -> string option -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_qemu (value gv, value qemuv);

CAMLprim value
ocaml_guestfs_set_qemu (value gv, value qemuv)
{
  CAMLparam2 (gv, qemuv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_qemu");

  char *qemu =
    qemuv != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (qemuv, 0))) : NULL;
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_qemu (g, qemu);
  caml_leave_blocking_section ();
  free (qemu);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_qemu");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_recovery_proc : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_recovery_proc (value gv, value recoveryprocv);

CAMLprim value
ocaml_guestfs_set_recovery_proc (value gv, value recoveryprocv)
{
  CAMLparam2 (gv, recoveryprocv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_recovery_proc");

  int recoveryproc = Bool_val (recoveryprocv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_recovery_proc (g, recoveryproc);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_recovery_proc");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_selinux : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_selinux (value gv, value selinuxv);

CAMLprim value
ocaml_guestfs_set_selinux (value gv, value selinuxv)
{
  CAMLparam2 (gv, selinuxv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_selinux");

  int selinux = Bool_val (selinuxv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_selinux (g, selinux);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_selinux");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_smp : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_smp (value gv, value smpv);

CAMLprim value
ocaml_guestfs_set_smp (value gv, value smpv)
{
  CAMLparam2 (gv, smpv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_smp");

  int smp = Int_val (smpv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_smp (g, smp);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_smp");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_trace : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_trace (value gv, value tracev);

CAMLprim value
ocaml_guestfs_set_trace (value gv, value tracev)
{
  CAMLparam2 (gv, tracev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_trace");

  int trace = Bool_val (tracev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_trace (g, trace);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_trace");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val set_verbose : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_set_verbose (value gv, value verbosev);

CAMLprim value
ocaml_guestfs_set_verbose (value gv, value verbosev)
{
  CAMLparam2 (gv, verbosev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("set_verbose");

  int verbose = Bool_val (verbosev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_set_verbose (g, verbose);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "set_verbose");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val setcon : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_setcon (value gv, value contextv);

CAMLprim value
ocaml_guestfs_setcon (value gv, value contextv)
{
  CAMLparam2 (gv, contextv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("setcon");

  char *context = guestfs_safe_strdup (g, String_val (contextv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_setcon (g, context);
  caml_leave_blocking_section ();
  free (context);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "setcon");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val setxattr : t -> string -> string -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_setxattr (value gv, value xattrv, value valv, value vallenv, value pathv);

CAMLprim value
ocaml_guestfs_setxattr (value gv, value xattrv, value valv, value vallenv, value pathv)
{
  CAMLparam5 (gv, xattrv, valv, vallenv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("setxattr");

  char *xattr = guestfs_safe_strdup (g, String_val (xattrv));
  char *val = guestfs_safe_strdup (g, String_val (valv));
  int vallen = Int_val (vallenv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_setxattr (g, xattr, val, vallen, path);
  caml_leave_blocking_section ();
  free (xattr);
  free (val);
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "setxattr");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk : t -> string -> int -> int -> int -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk (value gv, value devicev, value cylsv, value headsv, value sectorsv, value linesv);

CAMLprim value
ocaml_guestfs_sfdisk (value gv, value devicev, value cylsv, value headsv, value sectorsv, value linesv)
{
  CAMLparam5 (gv, devicev, cylsv, headsv, sectorsv);
  CAMLxparam1 (linesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdisk");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int cyls = Int_val (cylsv);
  int heads = Int_val (headsv);
  int sectors = Int_val (sectorsv);
  char **lines = ocaml_guestfs_strings_val (g, linesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  caml_leave_blocking_section ();
  free (device);
  ocaml_guestfs_free_strings (lines);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "sfdisk");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_sfdisk_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_sfdisk (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val sfdiskM : t -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdiskM (value gv, value devicev, value linesv);

CAMLprim value
ocaml_guestfs_sfdiskM (value gv, value devicev, value linesv)
{
  CAMLparam3 (gv, devicev, linesv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdiskM");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char **lines = ocaml_guestfs_strings_val (g, linesv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdiskM (g, device, lines);
  caml_leave_blocking_section ();
  free (device);
  ocaml_guestfs_free_strings (lines);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "sfdiskM");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_N (value gv, value devicev, value partnumv, value cylsv, value headsv, value sectorsv, value linev);

CAMLprim value
ocaml_guestfs_sfdisk_N (value gv, value devicev, value partnumv, value cylsv, value headsv, value sectorsv, value linev)
{
  CAMLparam5 (gv, devicev, partnumv, cylsv, headsv);
  CAMLxparam2 (sectorsv, linev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdisk_N");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int partnum = Int_val (partnumv);
  int cyls = Int_val (cylsv);
  int heads = Int_val (headsv);
  int sectors = Int_val (sectorsv);
  char *line = guestfs_safe_strdup (g, String_val (linev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  caml_leave_blocking_section ();
  free (device);
  free (line);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "sfdisk_N");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_N_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_sfdisk_N_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_sfdisk_N (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

/* Automatically generated wrapper for function
 * val sfdisk_disk_geometry : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_disk_geometry (value gv, value devicev);

CAMLprim value
ocaml_guestfs_sfdisk_disk_geometry (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdisk_disk_geometry");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_disk_geometry (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "sfdisk_disk_geometry");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_kernel_geometry : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_kernel_geometry (value gv, value devicev);

CAMLprim value
ocaml_guestfs_sfdisk_kernel_geometry (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdisk_kernel_geometry");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_kernel_geometry (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "sfdisk_kernel_geometry");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sfdisk_l : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sfdisk_l (value gv, value devicev);

CAMLprim value
ocaml_guestfs_sfdisk_l (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sfdisk_l");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sfdisk_l (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "sfdisk_l");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sh : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sh (value gv, value commandv);

CAMLprim value
ocaml_guestfs_sh (value gv, value commandv)
{
  CAMLparam2 (gv, commandv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sh");

  char *command = guestfs_safe_strdup (g, String_val (commandv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_sh (g, command);
  caml_leave_blocking_section ();
  free (command);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "sh");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sh_lines : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sh_lines (value gv, value commandv);

CAMLprim value
ocaml_guestfs_sh_lines (value gv, value commandv)
{
  CAMLparam2 (gv, commandv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sh_lines");

  char *command = guestfs_safe_strdup (g, String_val (commandv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_sh_lines (g, command);
  caml_leave_blocking_section ();
  free (command);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "sh_lines");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val shutdown : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_shutdown (value gv);

CAMLprim value
ocaml_guestfs_shutdown (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("shutdown");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_shutdown (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "shutdown");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sleep : t -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sleep (value gv, value secsv);

CAMLprim value
ocaml_guestfs_sleep (value gv, value secsv)
{
  CAMLparam2 (gv, secsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sleep");

  int secs = Int_val (secsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_sleep (g, secs);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "sleep");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val stat : t -> string -> stat
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_stat (value gv, value pathv);

CAMLprim value
ocaml_guestfs_stat (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("stat");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  struct guestfs_stat *r;

  caml_enter_blocking_section ();
  r = guestfs_stat (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "stat");

  rv = copy_stat (r);
  guestfs_free_stat (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val statvfs : t -> string -> statvfs
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_statvfs (value gv, value pathv);

CAMLprim value
ocaml_guestfs_statvfs (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("statvfs");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  struct guestfs_statvfs *r;

  caml_enter_blocking_section ();
  r = guestfs_statvfs (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "statvfs");

  rv = copy_statvfs (r);
  guestfs_free_statvfs (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val strings : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_strings (value gv, value pathv);

CAMLprim value
ocaml_guestfs_strings (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("strings");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_strings (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "strings");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val strings_e : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_strings_e (value gv, value encodingv, value pathv);

CAMLprim value
ocaml_guestfs_strings_e (value gv, value encodingv, value pathv)
{
  CAMLparam3 (gv, encodingv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("strings_e");

  char *encoding = guestfs_safe_strdup (g, String_val (encodingv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_strings_e (g, encoding, path);
  caml_leave_blocking_section ();
  free (encoding);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "strings_e");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapoff_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_swapoff_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapoff_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapoff_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapoff_file (value gv, value filev);

CAMLprim value
ocaml_guestfs_swapoff_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapoff_file");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapoff_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_label : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapoff_label (value gv, value labelv);

CAMLprim value
ocaml_guestfs_swapoff_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapoff_label");

  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapoff_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapoff_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapoff_uuid (value gv, value uuidv);

CAMLprim value
ocaml_guestfs_swapoff_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapoff_uuid");

  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapoff_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapoff_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapon_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_swapon_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapon_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapon_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_file : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapon_file (value gv, value filev);

CAMLprim value
ocaml_guestfs_swapon_file (value gv, value filev)
{
  CAMLparam2 (gv, filev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapon_file");

  char *file = guestfs_safe_strdup (g, String_val (filev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_file (g, file);
  caml_leave_blocking_section ();
  free (file);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapon_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_label : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapon_label (value gv, value labelv);

CAMLprim value
ocaml_guestfs_swapon_label (value gv, value labelv)
{
  CAMLparam2 (gv, labelv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapon_label");

  char *label = guestfs_safe_strdup (g, String_val (labelv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_label (g, label);
  caml_leave_blocking_section ();
  free (label);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapon_label");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val swapon_uuid : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_swapon_uuid (value gv, value uuidv);

CAMLprim value
ocaml_guestfs_swapon_uuid (value gv, value uuidv)
{
  CAMLparam2 (gv, uuidv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("swapon_uuid");

  char *uuid = guestfs_safe_strdup (g, String_val (uuidv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_swapon_uuid (g, uuid);
  caml_leave_blocking_section ();
  free (uuid);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "swapon_uuid");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val sync : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_sync (value gv);

CAMLprim value
ocaml_guestfs_sync (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("sync");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_sync (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "sync");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tail : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tail (value gv, value pathv);

CAMLprim value
ocaml_guestfs_tail (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tail");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tail (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "tail");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tail_n : t -> int -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tail_n (value gv, value nrlinesv, value pathv);

CAMLprim value
ocaml_guestfs_tail_n (value gv, value nrlinesv, value pathv)
{
  CAMLparam3 (gv, nrlinesv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tail_n");

  int nrlines = Int_val (nrlinesv);
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tail_n (g, nrlines, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "tail_n");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tar_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tar_in (value gv, value tarfilev, value directoryv);

CAMLprim value
ocaml_guestfs_tar_in (value gv, value tarfilev, value directoryv)
{
  CAMLparam3 (gv, tarfilev, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tar_in");

  char *tarfile = guestfs_safe_strdup (g, String_val (tarfilev));
  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tar_in (g, tarfile, directory);
  caml_leave_blocking_section ();
  free (tarfile);
  free (directory);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "tar_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tar_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tar_out (value gv, value directoryv, value tarfilev);

CAMLprim value
ocaml_guestfs_tar_out (value gv, value directoryv, value tarfilev)
{
  CAMLparam3 (gv, directoryv, tarfilev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tar_out");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *tarfile = guestfs_safe_strdup (g, String_val (tarfilev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tar_out (g, directory, tarfile);
  caml_leave_blocking_section ();
  free (directory);
  free (tarfile);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "tar_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0 : t -> ?obool:bool -> ?oint:int -> ?oint64:int64 -> ?ostring:string -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0 (value gv, value oboolv, value ointv, value oint64v, value ostringv, value strv, value optstrv, value strlistv, value bv, value integerv, value integer64v, value fileinv, value fileoutv, value bufferinv);

CAMLprim value
ocaml_guestfs_test0 (value gv, value oboolv, value ointv, value oint64v, value ostringv, value strv, value optstrv, value strlistv, value bv, value integerv, value integer64v, value fileinv, value fileoutv, value bufferinv)
{
  CAMLparam5 (gv, oboolv, ointv, oint64v, ostringv);
  CAMLxparam5 (strv, optstrv, strlistv, bv, integerv);
  CAMLxparam4 (integer64v, fileinv, fileoutv, bufferinv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0");

  char *str = guestfs_safe_strdup (g, String_val (strv));
  char *optstr =
    optstrv != Val_int (0) ?
      guestfs_safe_strdup (g, String_val (Field (optstrv, 0))) : NULL;
  char **strlist = ocaml_guestfs_strings_val (g, strlistv);
  int b = Bool_val (bv);
  int integer = Int_val (integerv);
  int64_t integer64 = Int64_val (integer64v);
  char *filein = guestfs_safe_strdup (g, String_val (fileinv));
  char *fileout = guestfs_safe_strdup (g, String_val (fileoutv));
  size_t bufferin_size = caml_string_length (bufferinv);
  char *bufferin = guestfs_safe_memdup (g, String_val (bufferinv), bufferin_size);
  struct guestfs_test0_argv optargs_s = { .bitmask = 0 };
  struct guestfs_test0_argv *optargs = &optargs_s;
  if (oboolv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TEST0_OBOOL_BITMASK;
    optargs_s.obool = Bool_val (Field (oboolv, 0));
  }
  if (ointv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TEST0_OINT_BITMASK;
    optargs_s.oint = Int_val (Field (ointv, 0));
  }
  if (oint64v != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TEST0_OINT64_BITMASK;
    optargs_s.oint64 = Int64_val (Field (oint64v, 0));
  }
  if (ostringv != Val_int (0)) {
    optargs_s.bitmask |= GUESTFS_TEST0_OSTRING_BITMASK;
    optargs_s.ostring = guestfs_safe_strdup (g, String_val (Field (ostringv, 0)));
  }
  int r;

  caml_enter_blocking_section ();
  r = guestfs_test0_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  caml_leave_blocking_section ();
  free (str);
  free (optstr);
  ocaml_guestfs_free_strings (strlist);
  free (filein);
  free (fileout);
  free (bufferin);
  if (ostringv != Val_int (0))
    free ((char *) optargs_s.ostring);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_test0_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_test0 (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]);
}

/* Automatically generated wrapper for function
 * val test0rbool : t -> string -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rbool (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rbool (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rbool");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_test0rbool (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rbool");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rboolerr : t -> bool
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rboolerr (value gv);

CAMLprim value
ocaml_guestfs_test0rboolerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rboolerr");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_test0rboolerr (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rboolerr");

  rv = Val_bool (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rbufferout : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rbufferout (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rbufferout (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rbufferout");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_test0rbufferout (g, val, &size);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rbufferout");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rbufferouterr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rbufferouterr (value gv);

CAMLprim value
ocaml_guestfs_test0rbufferouterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rbufferouterr");

  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_test0rbufferouterr (g, &size);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rbufferouterr");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rconstoptstring : t -> string -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rconstoptstring (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rconstoptstring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rconstoptstring");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rconstoptstring (g, val);
  caml_leave_blocking_section ();
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
 * val test0rconstoptstringerr : t -> string option
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rconstoptstringerr (value gv);

CAMLprim value
ocaml_guestfs_test0rconstoptstringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal3 (rv, v, v2);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rconstoptstringerr");

  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rconstoptstringerr (g);
  caml_leave_blocking_section ();

  if (r) { /* Some string */
    v = caml_alloc (1, 0);
    v2 = caml_copy_string (r);
    Store_field (v, 0, v2);
  } else /* None */
    v = Val_int (0);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rconststring : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rconststring (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rconststring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rconststring");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rconststring (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rconststring");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rconststringerr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rconststringerr (value gv);

CAMLprim value
ocaml_guestfs_test0rconststringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rconststringerr");

  const char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rconststringerr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rconststringerr");

  rv = caml_copy_string (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rhashtable : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rhashtable (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rhashtable (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rhashtable");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_test0rhashtable (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rhashtable");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rhashtableerr : t -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rhashtableerr (value gv);

CAMLprim value
ocaml_guestfs_test0rhashtableerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rhashtableerr");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_test0rhashtableerr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rhashtableerr");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rint : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rint (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rint (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rint");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_test0rint (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rint");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rint64 : t -> string -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rint64 (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rint64 (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rint64");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_test0rint64 (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rint64");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rint64err : t -> int64
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rint64err (value gv);

CAMLprim value
ocaml_guestfs_test0rint64err (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rint64err");

  int64_t r;

  caml_enter_blocking_section ();
  r = guestfs_test0rint64err (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rint64err");

  rv = caml_copy_int64 (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rinterr : t -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rinterr (value gv);

CAMLprim value
ocaml_guestfs_test0rinterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rinterr");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_test0rinterr (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "test0rinterr");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstring : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstring (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rstring (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstring");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstring (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstring");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstringerr : t -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstringerr (value gv);

CAMLprim value
ocaml_guestfs_test0rstringerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstringerr");

  char *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstringerr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstringerr");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstringlist : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstringlist (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rstringlist (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstringlist");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstringlist (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstringlist");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstringlisterr : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstringlisterr (value gv);

CAMLprim value
ocaml_guestfs_test0rstringlisterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstringlisterr");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstringlisterr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstringlisterr");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstruct : t -> string -> lvm_pv
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstruct (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rstruct (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstruct");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  struct guestfs_lvm_pv *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstruct (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstruct");

  rv = copy_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstructerr : t -> lvm_pv
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstructerr (value gv);

CAMLprim value
ocaml_guestfs_test0rstructerr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstructerr");

  struct guestfs_lvm_pv *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstructerr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstructerr");

  rv = copy_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstructlist : t -> string -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstructlist (value gv, value valv);

CAMLprim value
ocaml_guestfs_test0rstructlist (value gv, value valv)
{
  CAMLparam2 (gv, valv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstructlist");

  char *val = guestfs_safe_strdup (g, String_val (valv));
  struct guestfs_lvm_pv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstructlist (g, val);
  caml_leave_blocking_section ();
  free (val);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstructlist");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val test0rstructlisterr : t -> lvm_pv array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_test0rstructlisterr (value gv);

CAMLprim value
ocaml_guestfs_test0rstructlisterr (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("test0rstructlisterr");

  struct guestfs_lvm_pv_list *r;

  caml_enter_blocking_section ();
  r = guestfs_test0rstructlisterr (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "test0rstructlisterr");

  rv = copy_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tgz_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tgz_in (value gv, value tarballv, value directoryv);

CAMLprim value
ocaml_guestfs_tgz_in (value gv, value tarballv, value directoryv)
{
  CAMLparam3 (gv, tarballv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tgz_in");

  char *tarball = guestfs_safe_strdup (g, String_val (tarballv));
  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tgz_in (g, tarball, directory);
  caml_leave_blocking_section ();
  free (tarball);
  free (directory);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "tgz_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tgz_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tgz_out (value gv, value directoryv, value tarballv);

CAMLprim value
ocaml_guestfs_tgz_out (value gv, value directoryv, value tarballv)
{
  CAMLparam3 (gv, directoryv, tarballv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tgz_out");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *tarball = guestfs_safe_strdup (g, String_val (tarballv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_tgz_out (g, directory, tarball);
  caml_leave_blocking_section ();
  free (directory);
  free (tarball);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "tgz_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val touch : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_touch (value gv, value pathv);

CAMLprim value
ocaml_guestfs_touch (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("touch");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_touch (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "touch");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val truncate : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_truncate (value gv, value pathv);

CAMLprim value
ocaml_guestfs_truncate (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("truncate");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_truncate (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "truncate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val truncate_size : t -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_truncate_size (value gv, value pathv, value sizev);

CAMLprim value
ocaml_guestfs_truncate_size (value gv, value pathv, value sizev)
{
  CAMLparam3 (gv, pathv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("truncate_size");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int64_t size = Int64_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_truncate_size (g, path, size);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "truncate_size");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val tune2fs : t -> ?force:bool -> ?maxmountcount:int -> ?mountcount:int -> ?errorbehavior:string -> ?group:int64 -> ?intervalbetweenchecks:int -> ?reservedblockspercentage:int -> ?lastmounteddirectory:string -> ?reservedblockscount:int64 -> ?user:int64 -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tune2fs (value gv, value forcev, value maxmountcountv, value mountcountv, value errorbehaviorv, value groupv, value intervalbetweenchecksv, value reservedblockspercentagev, value lastmounteddirectoryv, value reservedblockscountv, value userv, value devicev);

CAMLprim value
ocaml_guestfs_tune2fs (value gv, value forcev, value maxmountcountv, value mountcountv, value errorbehaviorv, value groupv, value intervalbetweenchecksv, value reservedblockspercentagev, value lastmounteddirectoryv, value reservedblockscountv, value userv, value devicev)
{
  CAMLparam5 (gv, forcev, maxmountcountv, mountcountv, errorbehaviorv);
  CAMLxparam5 (groupv, intervalbetweenchecksv, reservedblockspercentagev, lastmounteddirectoryv, reservedblockscountv);
  CAMLxparam2 (userv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tune2fs");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
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
    optargs_s.errorbehavior = guestfs_safe_strdup (g, String_val (Field (errorbehaviorv, 0)));
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
    optargs_s.lastmounteddirectory = guestfs_safe_strdup (g, String_val (Field (lastmounteddirectoryv, 0)));
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
    ocaml_guestfs_raise_error (g, "tune2fs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tune2fs_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_tune2fs_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_tune2fs (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}

/* Automatically generated wrapper for function
 * val tune2fs_l : t -> string -> (string * string) list
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_tune2fs_l (value gv, value devicev);

CAMLprim value
ocaml_guestfs_tune2fs_l (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("tune2fs_l");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_tune2fs_l (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "tune2fs_l");

  rv = copy_table (r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val txz_in : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_txz_in (value gv, value tarballv, value directoryv);

CAMLprim value
ocaml_guestfs_txz_in (value gv, value tarballv, value directoryv)
{
  CAMLparam3 (gv, tarballv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("txz_in");

  char *tarball = guestfs_safe_strdup (g, String_val (tarballv));
  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_txz_in (g, tarball, directory);
  caml_leave_blocking_section ();
  free (tarball);
  free (directory);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "txz_in");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val txz_out : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_txz_out (value gv, value directoryv, value tarballv);

CAMLprim value
ocaml_guestfs_txz_out (value gv, value directoryv, value tarballv)
{
  CAMLparam3 (gv, directoryv, tarballv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("txz_out");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  char *tarball = guestfs_safe_strdup (g, String_val (tarballv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_txz_out (g, directory, tarball);
  caml_leave_blocking_section ();
  free (directory);
  free (tarball);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "txz_out");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umask : t -> int -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_umask (value gv, value maskv);

CAMLprim value
ocaml_guestfs_umask (value gv, value maskv)
{
  CAMLparam2 (gv, maskv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("umask");

  int mask = Int_val (maskv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_umask (g, mask);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "umask");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_umount (value gv, value pathordevicev);

CAMLprim value
ocaml_guestfs_umount (value gv, value pathordevicev)
{
  CAMLparam2 (gv, pathordevicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("umount");

  char *pathordevice = guestfs_safe_strdup (g, String_val (pathordevicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_umount (g, pathordevice);
  caml_leave_blocking_section ();
  free (pathordevice);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "umount");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount_all : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_umount_all (value gv);

CAMLprim value
ocaml_guestfs_umount_all (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("umount_all");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_umount_all (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "umount_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val umount_local : t -> ?retry:bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_umount_local (value gv, value retryv);

CAMLprim value
ocaml_guestfs_umount_local (value gv, value retryv)
{
  CAMLparam2 (gv, retryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("umount_local");

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
    ocaml_guestfs_raise_error (g, "umount_local");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val upload : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_upload (value gv, value filenamev, value remotefilenamev);

CAMLprim value
ocaml_guestfs_upload (value gv, value filenamev, value remotefilenamev)
{
  CAMLparam3 (gv, filenamev, remotefilenamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("upload");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *remotefilename = guestfs_safe_strdup (g, String_val (remotefilenamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_upload (g, filename, remotefilename);
  caml_leave_blocking_section ();
  free (filename);
  free (remotefilename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "upload");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val upload_offset : t -> string -> string -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_upload_offset (value gv, value filenamev, value remotefilenamev, value offsetv);

CAMLprim value
ocaml_guestfs_upload_offset (value gv, value filenamev, value remotefilenamev, value offsetv)
{
  CAMLparam4 (gv, filenamev, remotefilenamev, offsetv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("upload_offset");

  char *filename = guestfs_safe_strdup (g, String_val (filenamev));
  char *remotefilename = guestfs_safe_strdup (g, String_val (remotefilenamev));
  int64_t offset = Int64_val (offsetv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  caml_leave_blocking_section ();
  free (filename);
  free (remotefilename);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "upload_offset");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_utimens (value gv, value pathv, value atsecsv, value atnsecsv, value mtsecsv, value mtnsecsv);

CAMLprim value
ocaml_guestfs_utimens (value gv, value pathv, value atsecsv, value atnsecsv, value mtsecsv, value mtnsecsv)
{
  CAMLparam5 (gv, pathv, atsecsv, atnsecsv, mtsecsv);
  CAMLxparam1 (mtnsecsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("utimens");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
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
    ocaml_guestfs_raise_error (g, "utimens");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_utimens_byte (value *argv, int argn);
CAMLprim value
ocaml_guestfs_utimens_byte (value *argv, int argn ATTRIBUTE_UNUSED)
{
  return ocaml_guestfs_utimens (argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* Automatically generated wrapper for function
 * val version : t -> version
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_version (value gv);

CAMLprim value
ocaml_guestfs_version (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("version");

  struct guestfs_version *r;

  caml_enter_blocking_section ();
  r = guestfs_version (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "version");

  rv = copy_version (r);
  guestfs_free_version (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_label : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vfs_label (value gv, value devicev);

CAMLprim value
ocaml_guestfs_vfs_label (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vfs_label");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_label (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vfs_label");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_type : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vfs_type (value gv, value devicev);

CAMLprim value
ocaml_guestfs_vfs_type (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vfs_type");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_type (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vfs_type");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vfs_uuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vfs_uuid (value gv, value devicev);

CAMLprim value
ocaml_guestfs_vfs_uuid (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vfs_uuid");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vfs_uuid (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vfs_uuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vg_activate : t -> bool -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vg_activate (value gv, value activatev, value volgroupsv);

CAMLprim value
ocaml_guestfs_vg_activate (value gv, value activatev, value volgroupsv)
{
  CAMLparam3 (gv, activatev, volgroupsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vg_activate");

  int activate = Bool_val (activatev);
  char **volgroups = ocaml_guestfs_strings_val (g, volgroupsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vg_activate (g, activate, volgroups);
  caml_leave_blocking_section ();
  ocaml_guestfs_free_strings (volgroups);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vg_activate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vg_activate_all : t -> bool -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vg_activate_all (value gv, value activatev);

CAMLprim value
ocaml_guestfs_vg_activate_all (value gv, value activatev)
{
  CAMLparam2 (gv, activatev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vg_activate_all");

  int activate = Bool_val (activatev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vg_activate_all (g, activate);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vg_activate_all");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgcreate : t -> string -> string array -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgcreate (value gv, value volgroupv, value physvolsv);

CAMLprim value
ocaml_guestfs_vgcreate (value gv, value volgroupv, value physvolsv)
{
  CAMLparam3 (gv, volgroupv, physvolsv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgcreate");

  char *volgroup = guestfs_safe_strdup (g, String_val (volgroupv));
  char **physvols = ocaml_guestfs_strings_val (g, physvolsv);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgcreate (g, volgroup, physvols);
  caml_leave_blocking_section ();
  free (volgroup);
  ocaml_guestfs_free_strings (physvols);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vgcreate");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vglvuuids : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vglvuuids (value gv, value vgnamev);

CAMLprim value
ocaml_guestfs_vglvuuids (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vglvuuids");

  char *vgname = guestfs_safe_strdup (g, String_val (vgnamev));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vglvuuids (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vglvuuids");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgmeta : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgmeta (value gv, value vgnamev);

CAMLprim value
ocaml_guestfs_vgmeta (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgmeta");

  char *vgname = guestfs_safe_strdup (g, String_val (vgnamev));
  char *r;
  size_t size;

  caml_enter_blocking_section ();
  r = guestfs_vgmeta (g, vgname, &size);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vgmeta");

  rv = caml_alloc_string (size);
  memcpy (String_val (rv), r, size);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgpvuuids : t -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgpvuuids (value gv, value vgnamev);

CAMLprim value
ocaml_guestfs_vgpvuuids (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgpvuuids");

  char *vgname = guestfs_safe_strdup (g, String_val (vgnamev));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vgpvuuids (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vgpvuuids");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgremove : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgremove (value gv, value vgnamev);

CAMLprim value
ocaml_guestfs_vgremove (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgremove");

  char *vgname = guestfs_safe_strdup (g, String_val (vgnamev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgremove (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vgremove");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgrename : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgrename (value gv, value volgroupv, value newvolgroupv);

CAMLprim value
ocaml_guestfs_vgrename (value gv, value volgroupv, value newvolgroupv)
{
  CAMLparam3 (gv, volgroupv, newvolgroupv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgrename");

  char *volgroup = guestfs_safe_strdup (g, String_val (volgroupv));
  char *newvolgroup = guestfs_safe_strdup (g, String_val (newvolgroupv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgrename (g, volgroup, newvolgroup);
  caml_leave_blocking_section ();
  free (volgroup);
  free (newvolgroup);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vgrename");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgs : t -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgs (value gv);

CAMLprim value
ocaml_guestfs_vgs (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgs");

  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_vgs (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vgs");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgs_full : t -> lvm_vg array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgs_full (value gv);

CAMLprim value
ocaml_guestfs_vgs_full (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgs_full");

  struct guestfs_lvm_vg_list *r;

  caml_enter_blocking_section ();
  r = guestfs_vgs_full (g);
  caml_leave_blocking_section ();
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vgs_full");

  rv = copy_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vgscan : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vgscan (value gv);

CAMLprim value
ocaml_guestfs_vgscan (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vgscan");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_vgscan (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "vgscan");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val vguuid : t -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_vguuid (value gv, value vgnamev);

CAMLprim value
ocaml_guestfs_vguuid (value gv, value vgnamev)
{
  CAMLparam2 (gv, vgnamev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("vguuid");

  char *vgname = guestfs_safe_strdup (g, String_val (vgnamev));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_vguuid (g, vgname);
  caml_leave_blocking_section ();
  free (vgname);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "vguuid");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wait_ready : t -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_wait_ready (value gv);

CAMLprim value
ocaml_guestfs_wait_ready (value gv)
{
  CAMLparam1 (gv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("wait_ready");

  int r;

  caml_enter_blocking_section ();
  r = guestfs_wait_ready (g);
  caml_leave_blocking_section ();
  if (r == -1)
    ocaml_guestfs_raise_error (g, "wait_ready");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_c : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_wc_c (value gv, value pathv);

CAMLprim value
ocaml_guestfs_wc_c (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("wc_c");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_c (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "wc_c");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_l : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_wc_l (value gv, value pathv);

CAMLprim value
ocaml_guestfs_wc_l (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("wc_l");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_l (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "wc_l");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wc_w : t -> string -> int
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_wc_w (value gv, value pathv);

CAMLprim value
ocaml_guestfs_wc_w (value gv, value pathv)
{
  CAMLparam2 (gv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("wc_w");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wc_w (g, path);
  caml_leave_blocking_section ();
  free (path);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "wc_w");

  rv = Val_int (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val wipefs : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_wipefs (value gv, value devicev);

CAMLprim value
ocaml_guestfs_wipefs (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("wipefs");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_wipefs (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "wipefs");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_write (value gv, value pathv, value contentv);

CAMLprim value
ocaml_guestfs_write (value gv, value pathv, value contentv)
{
  CAMLparam3 (gv, pathv, contentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("write");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t content_size = caml_string_length (contentv);
  char *content = guestfs_safe_memdup (g, String_val (contentv), content_size);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write (g, path, content, content_size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "write");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write_append : t -> string -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_write_append (value gv, value pathv, value contentv);

CAMLprim value
ocaml_guestfs_write_append (value gv, value pathv, value contentv)
{
  CAMLparam3 (gv, pathv, contentv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("write_append");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t content_size = caml_string_length (contentv);
  char *content = guestfs_safe_memdup (g, String_val (contentv), content_size);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write_append (g, path, content, content_size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "write_append");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val write_file : t -> string -> string -> int -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_write_file (value gv, value pathv, value contentv, value sizev);

CAMLprim value
ocaml_guestfs_write_file (value gv, value pathv, value contentv, value sizev)
{
  CAMLparam4 (gv, pathv, contentv, sizev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("write_file");

  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *content = guestfs_safe_strdup (g, String_val (contentv));
  int size = Int_val (sizev);
  int r;

  caml_enter_blocking_section ();
  r = guestfs_write_file (g, path, content, size);
  caml_leave_blocking_section ();
  free (path);
  free (content);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "write_file");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zegrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zegrep (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_zegrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zegrep");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zegrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zegrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zegrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zegrepi (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_zegrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zegrepi");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zegrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zegrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zero (value gv, value devicev);

CAMLprim value
ocaml_guestfs_zero (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zero");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "zero");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero_device : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zero_device (value gv, value devicev);

CAMLprim value
ocaml_guestfs_zero_device (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zero_device");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero_device (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "zero_device");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zero_free_space : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zero_free_space (value gv, value directoryv);

CAMLprim value
ocaml_guestfs_zero_free_space (value gv, value directoryv)
{
  CAMLparam2 (gv, directoryv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zero_free_space");

  char *directory = guestfs_safe_strdup (g, String_val (directoryv));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zero_free_space (g, directory);
  caml_leave_blocking_section ();
  free (directory);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "zero_free_space");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zerofree : t -> string -> unit
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zerofree (value gv, value devicev);

CAMLprim value
ocaml_guestfs_zerofree (value gv, value devicev)
{
  CAMLparam2 (gv, devicev);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zerofree");

  char *device = guestfs_safe_strdup (g, String_val (devicev));
  int r;

  caml_enter_blocking_section ();
  r = guestfs_zerofree (g, device);
  caml_leave_blocking_section ();
  free (device);
  if (r == -1)
    ocaml_guestfs_raise_error (g, "zerofree");

  rv = Val_unit;
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zfgrep (value gv, value patternv, value pathv);

CAMLprim value
ocaml_guestfs_zfgrep (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zfgrep");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zfgrep (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zfgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zfgrepi (value gv, value patternv, value pathv);

CAMLprim value
ocaml_guestfs_zfgrepi (value gv, value patternv, value pathv)
{
  CAMLparam3 (gv, patternv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zfgrepi");

  char *pattern = guestfs_safe_strdup (g, String_val (patternv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zfgrepi (g, pattern, path);
  caml_leave_blocking_section ();
  free (pattern);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zfgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zfile : t -> string -> string -> string
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zfile (value gv, value methv, value pathv);

CAMLprim value
ocaml_guestfs_zfile (value gv, value methv, value pathv)
{
  CAMLparam3 (gv, methv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zfile");

  char *meth = guestfs_safe_strdup (g, String_val (methv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  char *r;

  caml_enter_blocking_section ();
  r = guestfs_zfile (g, meth, path);
  caml_leave_blocking_section ();
  free (meth);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zfile");

  rv = caml_copy_string (r);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zgrep : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zgrep (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_zgrep (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zgrep");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zgrep (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zgrep");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

/* Automatically generated wrapper for function
 * val zgrepi : t -> string -> string -> string array
 */

/* Emit prototype to appease gcc's -Wmissing-prototypes. */
CAMLprim value ocaml_guestfs_zgrepi (value gv, value regexv, value pathv);

CAMLprim value
ocaml_guestfs_zgrepi (value gv, value regexv, value pathv)
{
  CAMLparam3 (gv, regexv, pathv);
  CAMLlocal1 (rv);

  guestfs_h *g = Guestfs_val (gv);
  if (g == NULL)
    ocaml_guestfs_raise_closed ("zgrepi");

  char *regex = guestfs_safe_strdup (g, String_val (regexv));
  char *path = guestfs_safe_strdup (g, String_val (pathv));
  size_t i;
  char **r;

  caml_enter_blocking_section ();
  r = guestfs_zgrepi (g, regex, path);
  caml_leave_blocking_section ();
  free (regex);
  free (path);
  if (r == NULL)
    ocaml_guestfs_raise_error (g, "zgrepi");

  rv = caml_copy_string_array ((const char **) r);
  for (i = 0; r[i] != NULL; ++i) free (r[i]);
  free (r);
  CAMLreturn (rv);
}

