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
#include <string.h>
#include <errno.h>

#include "guestfs.h"
#include "guestfs-internal.h"

/* Structure-comparison functions. */

GUESTFS_DLL_PUBLIC int
guestfs_compare_int_bool (const struct guestfs_int_bool *s1, const struct guestfs_int_bool *s2)
{
  if (s1->i < s2->i) return -1;
  else if (s1->i > s2->i) return 1;
  if (s1->b < s2->b) return -1;
  else if (s1->b > s2->b) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_int_bool_list (const struct guestfs_int_bool_list *s1, const struct guestfs_int_bool_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_int_bool (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_pv (const struct guestfs_lvm_pv *s1, const struct guestfs_lvm_pv *s2)
{
  int r;

  r = strcmp (s1->pv_name, s2->pv_name);
  if (r != 0) return r;
  r = memcmp (s1->pv_uuid, s2->pv_uuid, 32 * sizeof (char));
  if (r != 0) return r;
  r = strcmp (s1->pv_fmt, s2->pv_fmt);
  if (r != 0) return r;
  if (s1->pv_size < s2->pv_size) return -1;
  else if (s1->pv_size > s2->pv_size) return 1;
  if (s1->dev_size < s2->dev_size) return -1;
  else if (s1->dev_size > s2->dev_size) return 1;
  if (s1->pv_free < s2->pv_free) return -1;
  else if (s1->pv_free > s2->pv_free) return 1;
  if (s1->pv_used < s2->pv_used) return -1;
  else if (s1->pv_used > s2->pv_used) return 1;
  r = strcmp (s1->pv_attr, s2->pv_attr);
  if (r != 0) return r;
  if (s1->pv_pe_count < s2->pv_pe_count) return -1;
  else if (s1->pv_pe_count > s2->pv_pe_count) return 1;
  if (s1->pv_pe_alloc_count < s2->pv_pe_alloc_count) return -1;
  else if (s1->pv_pe_alloc_count > s2->pv_pe_alloc_count) return 1;
  r = strcmp (s1->pv_tags, s2->pv_tags);
  if (r != 0) return r;
  if (s1->pe_start < s2->pe_start) return -1;
  else if (s1->pe_start > s2->pe_start) return 1;
  if (s1->pv_mda_count < s2->pv_mda_count) return -1;
  else if (s1->pv_mda_count > s2->pv_mda_count) return 1;
  if (s1->pv_mda_free < s2->pv_mda_free) return -1;
  else if (s1->pv_mda_free > s2->pv_mda_free) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_pv_list (const struct guestfs_lvm_pv_list *s1, const struct guestfs_lvm_pv_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_lvm_pv (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_vg (const struct guestfs_lvm_vg *s1, const struct guestfs_lvm_vg *s2)
{
  int r;

  r = strcmp (s1->vg_name, s2->vg_name);
  if (r != 0) return r;
  r = memcmp (s1->vg_uuid, s2->vg_uuid, 32 * sizeof (char));
  if (r != 0) return r;
  r = strcmp (s1->vg_fmt, s2->vg_fmt);
  if (r != 0) return r;
  r = strcmp (s1->vg_attr, s2->vg_attr);
  if (r != 0) return r;
  if (s1->vg_size < s2->vg_size) return -1;
  else if (s1->vg_size > s2->vg_size) return 1;
  if (s1->vg_free < s2->vg_free) return -1;
  else if (s1->vg_free > s2->vg_free) return 1;
  r = strcmp (s1->vg_sysid, s2->vg_sysid);
  if (r != 0) return r;
  if (s1->vg_extent_size < s2->vg_extent_size) return -1;
  else if (s1->vg_extent_size > s2->vg_extent_size) return 1;
  if (s1->vg_extent_count < s2->vg_extent_count) return -1;
  else if (s1->vg_extent_count > s2->vg_extent_count) return 1;
  if (s1->vg_free_count < s2->vg_free_count) return -1;
  else if (s1->vg_free_count > s2->vg_free_count) return 1;
  if (s1->max_lv < s2->max_lv) return -1;
  else if (s1->max_lv > s2->max_lv) return 1;
  if (s1->max_pv < s2->max_pv) return -1;
  else if (s1->max_pv > s2->max_pv) return 1;
  if (s1->pv_count < s2->pv_count) return -1;
  else if (s1->pv_count > s2->pv_count) return 1;
  if (s1->lv_count < s2->lv_count) return -1;
  else if (s1->lv_count > s2->lv_count) return 1;
  if (s1->snap_count < s2->snap_count) return -1;
  else if (s1->snap_count > s2->snap_count) return 1;
  if (s1->vg_seqno < s2->vg_seqno) return -1;
  else if (s1->vg_seqno > s2->vg_seqno) return 1;
  r = strcmp (s1->vg_tags, s2->vg_tags);
  if (r != 0) return r;
  if (s1->vg_mda_count < s2->vg_mda_count) return -1;
  else if (s1->vg_mda_count > s2->vg_mda_count) return 1;
  if (s1->vg_mda_free < s2->vg_mda_free) return -1;
  else if (s1->vg_mda_free > s2->vg_mda_free) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_vg_list (const struct guestfs_lvm_vg_list *s1, const struct guestfs_lvm_vg_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_lvm_vg (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_lv (const struct guestfs_lvm_lv *s1, const struct guestfs_lvm_lv *s2)
{
  int r;

  r = strcmp (s1->lv_name, s2->lv_name);
  if (r != 0) return r;
  r = memcmp (s1->lv_uuid, s2->lv_uuid, 32 * sizeof (char));
  if (r != 0) return r;
  r = strcmp (s1->lv_attr, s2->lv_attr);
  if (r != 0) return r;
  if (s1->lv_major < s2->lv_major) return -1;
  else if (s1->lv_major > s2->lv_major) return 1;
  if (s1->lv_minor < s2->lv_minor) return -1;
  else if (s1->lv_minor > s2->lv_minor) return 1;
  if (s1->lv_kernel_major < s2->lv_kernel_major) return -1;
  else if (s1->lv_kernel_major > s2->lv_kernel_major) return 1;
  if (s1->lv_kernel_minor < s2->lv_kernel_minor) return -1;
  else if (s1->lv_kernel_minor > s2->lv_kernel_minor) return 1;
  if (s1->lv_size < s2->lv_size) return -1;
  else if (s1->lv_size > s2->lv_size) return 1;
  if (s1->seg_count < s2->seg_count) return -1;
  else if (s1->seg_count > s2->seg_count) return 1;
  r = strcmp (s1->origin, s2->origin);
  if (r != 0) return r;
  if (s1->snap_percent < s2->snap_percent) return -1;
  else if (s1->snap_percent > s2->snap_percent) return 1;
  if (s1->copy_percent < s2->copy_percent) return -1;
  else if (s1->copy_percent > s2->copy_percent) return 1;
  r = strcmp (s1->move_pv, s2->move_pv);
  if (r != 0) return r;
  r = strcmp (s1->lv_tags, s2->lv_tags);
  if (r != 0) return r;
  r = strcmp (s1->mirror_log, s2->mirror_log);
  if (r != 0) return r;
  r = strcmp (s1->modules, s2->modules);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_lvm_lv_list (const struct guestfs_lvm_lv_list *s1, const struct guestfs_lvm_lv_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_lvm_lv (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_stat (const struct guestfs_stat *s1, const struct guestfs_stat *s2)
{
  if (s1->dev < s2->dev) return -1;
  else if (s1->dev > s2->dev) return 1;
  if (s1->ino < s2->ino) return -1;
  else if (s1->ino > s2->ino) return 1;
  if (s1->mode < s2->mode) return -1;
  else if (s1->mode > s2->mode) return 1;
  if (s1->nlink < s2->nlink) return -1;
  else if (s1->nlink > s2->nlink) return 1;
  if (s1->uid < s2->uid) return -1;
  else if (s1->uid > s2->uid) return 1;
  if (s1->gid < s2->gid) return -1;
  else if (s1->gid > s2->gid) return 1;
  if (s1->rdev < s2->rdev) return -1;
  else if (s1->rdev > s2->rdev) return 1;
  if (s1->size < s2->size) return -1;
  else if (s1->size > s2->size) return 1;
  if (s1->blksize < s2->blksize) return -1;
  else if (s1->blksize > s2->blksize) return 1;
  if (s1->blocks < s2->blocks) return -1;
  else if (s1->blocks > s2->blocks) return 1;
  if (s1->atime < s2->atime) return -1;
  else if (s1->atime > s2->atime) return 1;
  if (s1->mtime < s2->mtime) return -1;
  else if (s1->mtime > s2->mtime) return 1;
  if (s1->ctime < s2->ctime) return -1;
  else if (s1->ctime > s2->ctime) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_stat_list (const struct guestfs_stat_list *s1, const struct guestfs_stat_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_stat (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_statns (const struct guestfs_statns *s1, const struct guestfs_statns *s2)
{
  if (s1->st_dev < s2->st_dev) return -1;
  else if (s1->st_dev > s2->st_dev) return 1;
  if (s1->st_ino < s2->st_ino) return -1;
  else if (s1->st_ino > s2->st_ino) return 1;
  if (s1->st_mode < s2->st_mode) return -1;
  else if (s1->st_mode > s2->st_mode) return 1;
  if (s1->st_nlink < s2->st_nlink) return -1;
  else if (s1->st_nlink > s2->st_nlink) return 1;
  if (s1->st_uid < s2->st_uid) return -1;
  else if (s1->st_uid > s2->st_uid) return 1;
  if (s1->st_gid < s2->st_gid) return -1;
  else if (s1->st_gid > s2->st_gid) return 1;
  if (s1->st_rdev < s2->st_rdev) return -1;
  else if (s1->st_rdev > s2->st_rdev) return 1;
  if (s1->st_size < s2->st_size) return -1;
  else if (s1->st_size > s2->st_size) return 1;
  if (s1->st_blksize < s2->st_blksize) return -1;
  else if (s1->st_blksize > s2->st_blksize) return 1;
  if (s1->st_blocks < s2->st_blocks) return -1;
  else if (s1->st_blocks > s2->st_blocks) return 1;
  if (s1->st_atime_sec < s2->st_atime_sec) return -1;
  else if (s1->st_atime_sec > s2->st_atime_sec) return 1;
  if (s1->st_atime_nsec < s2->st_atime_nsec) return -1;
  else if (s1->st_atime_nsec > s2->st_atime_nsec) return 1;
  if (s1->st_mtime_sec < s2->st_mtime_sec) return -1;
  else if (s1->st_mtime_sec > s2->st_mtime_sec) return 1;
  if (s1->st_mtime_nsec < s2->st_mtime_nsec) return -1;
  else if (s1->st_mtime_nsec > s2->st_mtime_nsec) return 1;
  if (s1->st_ctime_sec < s2->st_ctime_sec) return -1;
  else if (s1->st_ctime_sec > s2->st_ctime_sec) return 1;
  if (s1->st_ctime_nsec < s2->st_ctime_nsec) return -1;
  else if (s1->st_ctime_nsec > s2->st_ctime_nsec) return 1;
  if (s1->st_spare1 < s2->st_spare1) return -1;
  else if (s1->st_spare1 > s2->st_spare1) return 1;
  if (s1->st_spare2 < s2->st_spare2) return -1;
  else if (s1->st_spare2 > s2->st_spare2) return 1;
  if (s1->st_spare3 < s2->st_spare3) return -1;
  else if (s1->st_spare3 > s2->st_spare3) return 1;
  if (s1->st_spare4 < s2->st_spare4) return -1;
  else if (s1->st_spare4 > s2->st_spare4) return 1;
  if (s1->st_spare5 < s2->st_spare5) return -1;
  else if (s1->st_spare5 > s2->st_spare5) return 1;
  if (s1->st_spare6 < s2->st_spare6) return -1;
  else if (s1->st_spare6 > s2->st_spare6) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_statns_list (const struct guestfs_statns_list *s1, const struct guestfs_statns_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_statns (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_statvfs (const struct guestfs_statvfs *s1, const struct guestfs_statvfs *s2)
{
  if (s1->bsize < s2->bsize) return -1;
  else if (s1->bsize > s2->bsize) return 1;
  if (s1->frsize < s2->frsize) return -1;
  else if (s1->frsize > s2->frsize) return 1;
  if (s1->blocks < s2->blocks) return -1;
  else if (s1->blocks > s2->blocks) return 1;
  if (s1->bfree < s2->bfree) return -1;
  else if (s1->bfree > s2->bfree) return 1;
  if (s1->bavail < s2->bavail) return -1;
  else if (s1->bavail > s2->bavail) return 1;
  if (s1->files < s2->files) return -1;
  else if (s1->files > s2->files) return 1;
  if (s1->ffree < s2->ffree) return -1;
  else if (s1->ffree > s2->ffree) return 1;
  if (s1->favail < s2->favail) return -1;
  else if (s1->favail > s2->favail) return 1;
  if (s1->fsid < s2->fsid) return -1;
  else if (s1->fsid > s2->fsid) return 1;
  if (s1->flag < s2->flag) return -1;
  else if (s1->flag > s2->flag) return 1;
  if (s1->namemax < s2->namemax) return -1;
  else if (s1->namemax > s2->namemax) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_statvfs_list (const struct guestfs_statvfs_list *s1, const struct guestfs_statvfs_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_statvfs (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_dirent (const struct guestfs_dirent *s1, const struct guestfs_dirent *s2)
{
  int r;

  if (s1->ino < s2->ino) return -1;
  else if (s1->ino > s2->ino) return 1;
  if (s1->ftyp < s2->ftyp) return -1;
  else if (s1->ftyp > s2->ftyp) return 1;
  r = strcmp (s1->name, s2->name);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_dirent_list (const struct guestfs_dirent_list *s1, const struct guestfs_dirent_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_dirent (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_version (const struct guestfs_version *s1, const struct guestfs_version *s2)
{
  int r;

  if (s1->major < s2->major) return -1;
  else if (s1->major > s2->major) return 1;
  if (s1->minor < s2->minor) return -1;
  else if (s1->minor > s2->minor) return 1;
  if (s1->release < s2->release) return -1;
  else if (s1->release > s2->release) return 1;
  r = strcmp (s1->extra, s2->extra);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_version_list (const struct guestfs_version_list *s1, const struct guestfs_version_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_version (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_xattr (const struct guestfs_xattr *s1, const struct guestfs_xattr *s2)
{
  int r;

  r = strcmp (s1->attrname, s2->attrname);
  if (r != 0) return r;
  if (s1->attrval_len < s2->attrval_len) return -1;
  else if (s1->attrval_len > s2->attrval_len) return 1;
  else {
    r = memcmp (s1->attrval, s2->attrval, s1->attrval_len);
    if (r != 0) return r;
  }
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_xattr_list (const struct guestfs_xattr_list *s1, const struct guestfs_xattr_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_xattr (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_inotify_event (const struct guestfs_inotify_event *s1, const struct guestfs_inotify_event *s2)
{
  int r;

  if (s1->in_wd < s2->in_wd) return -1;
  else if (s1->in_wd > s2->in_wd) return 1;
  if (s1->in_mask < s2->in_mask) return -1;
  else if (s1->in_mask > s2->in_mask) return 1;
  if (s1->in_cookie < s2->in_cookie) return -1;
  else if (s1->in_cookie > s2->in_cookie) return 1;
  r = strcmp (s1->in_name, s2->in_name);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_inotify_event_list (const struct guestfs_inotify_event_list *s1, const struct guestfs_inotify_event_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_inotify_event (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_partition (const struct guestfs_partition *s1, const struct guestfs_partition *s2)
{
  if (s1->part_num < s2->part_num) return -1;
  else if (s1->part_num > s2->part_num) return 1;
  if (s1->part_start < s2->part_start) return -1;
  else if (s1->part_start > s2->part_start) return 1;
  if (s1->part_end < s2->part_end) return -1;
  else if (s1->part_end > s2->part_end) return 1;
  if (s1->part_size < s2->part_size) return -1;
  else if (s1->part_size > s2->part_size) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_partition_list (const struct guestfs_partition_list *s1, const struct guestfs_partition_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_partition (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_application (const struct guestfs_application *s1, const struct guestfs_application *s2)
{
  int r;

  r = strcmp (s1->app_name, s2->app_name);
  if (r != 0) return r;
  r = strcmp (s1->app_display_name, s2->app_display_name);
  if (r != 0) return r;
  if (s1->app_epoch < s2->app_epoch) return -1;
  else if (s1->app_epoch > s2->app_epoch) return 1;
  r = strcmp (s1->app_version, s2->app_version);
  if (r != 0) return r;
  r = strcmp (s1->app_release, s2->app_release);
  if (r != 0) return r;
  r = strcmp (s1->app_install_path, s2->app_install_path);
  if (r != 0) return r;
  r = strcmp (s1->app_trans_path, s2->app_trans_path);
  if (r != 0) return r;
  r = strcmp (s1->app_publisher, s2->app_publisher);
  if (r != 0) return r;
  r = strcmp (s1->app_url, s2->app_url);
  if (r != 0) return r;
  r = strcmp (s1->app_source_package, s2->app_source_package);
  if (r != 0) return r;
  r = strcmp (s1->app_summary, s2->app_summary);
  if (r != 0) return r;
  r = strcmp (s1->app_description, s2->app_description);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_application_list (const struct guestfs_application_list *s1, const struct guestfs_application_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_application (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_application2 (const struct guestfs_application2 *s1, const struct guestfs_application2 *s2)
{
  int r;

  r = strcmp (s1->app2_name, s2->app2_name);
  if (r != 0) return r;
  r = strcmp (s1->app2_display_name, s2->app2_display_name);
  if (r != 0) return r;
  if (s1->app2_epoch < s2->app2_epoch) return -1;
  else if (s1->app2_epoch > s2->app2_epoch) return 1;
  r = strcmp (s1->app2_version, s2->app2_version);
  if (r != 0) return r;
  r = strcmp (s1->app2_release, s2->app2_release);
  if (r != 0) return r;
  r = strcmp (s1->app2_arch, s2->app2_arch);
  if (r != 0) return r;
  r = strcmp (s1->app2_install_path, s2->app2_install_path);
  if (r != 0) return r;
  r = strcmp (s1->app2_trans_path, s2->app2_trans_path);
  if (r != 0) return r;
  r = strcmp (s1->app2_publisher, s2->app2_publisher);
  if (r != 0) return r;
  r = strcmp (s1->app2_url, s2->app2_url);
  if (r != 0) return r;
  r = strcmp (s1->app2_source_package, s2->app2_source_package);
  if (r != 0) return r;
  r = strcmp (s1->app2_summary, s2->app2_summary);
  if (r != 0) return r;
  r = strcmp (s1->app2_description, s2->app2_description);
  if (r != 0) return r;
  r = strcmp (s1->app2_spare1, s2->app2_spare1);
  if (r != 0) return r;
  r = strcmp (s1->app2_spare2, s2->app2_spare2);
  if (r != 0) return r;
  r = strcmp (s1->app2_spare3, s2->app2_spare3);
  if (r != 0) return r;
  r = strcmp (s1->app2_spare4, s2->app2_spare4);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_application2_list (const struct guestfs_application2_list *s1, const struct guestfs_application2_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_application2 (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_isoinfo (const struct guestfs_isoinfo *s1, const struct guestfs_isoinfo *s2)
{
  int r;

  r = strcmp (s1->iso_system_id, s2->iso_system_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_volume_id, s2->iso_volume_id);
  if (r != 0) return r;
  if (s1->iso_volume_space_size < s2->iso_volume_space_size) return -1;
  else if (s1->iso_volume_space_size > s2->iso_volume_space_size) return 1;
  if (s1->iso_volume_set_size < s2->iso_volume_set_size) return -1;
  else if (s1->iso_volume_set_size > s2->iso_volume_set_size) return 1;
  if (s1->iso_volume_sequence_number < s2->iso_volume_sequence_number) return -1;
  else if (s1->iso_volume_sequence_number > s2->iso_volume_sequence_number) return 1;
  if (s1->iso_logical_block_size < s2->iso_logical_block_size) return -1;
  else if (s1->iso_logical_block_size > s2->iso_logical_block_size) return 1;
  r = strcmp (s1->iso_volume_set_id, s2->iso_volume_set_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_publisher_id, s2->iso_publisher_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_data_preparer_id, s2->iso_data_preparer_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_application_id, s2->iso_application_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_copyright_file_id, s2->iso_copyright_file_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_abstract_file_id, s2->iso_abstract_file_id);
  if (r != 0) return r;
  r = strcmp (s1->iso_bibliographic_file_id, s2->iso_bibliographic_file_id);
  if (r != 0) return r;
  if (s1->iso_volume_creation_t < s2->iso_volume_creation_t) return -1;
  else if (s1->iso_volume_creation_t > s2->iso_volume_creation_t) return 1;
  if (s1->iso_volume_modification_t < s2->iso_volume_modification_t) return -1;
  else if (s1->iso_volume_modification_t > s2->iso_volume_modification_t) return 1;
  if (s1->iso_volume_expiration_t < s2->iso_volume_expiration_t) return -1;
  else if (s1->iso_volume_expiration_t > s2->iso_volume_expiration_t) return 1;
  if (s1->iso_volume_effective_t < s2->iso_volume_effective_t) return -1;
  else if (s1->iso_volume_effective_t > s2->iso_volume_effective_t) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_isoinfo_list (const struct guestfs_isoinfo_list *s1, const struct guestfs_isoinfo_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_isoinfo (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_mdstat (const struct guestfs_mdstat *s1, const struct guestfs_mdstat *s2)
{
  int r;

  r = strcmp (s1->mdstat_device, s2->mdstat_device);
  if (r != 0) return r;
  if (s1->mdstat_index < s2->mdstat_index) return -1;
  else if (s1->mdstat_index > s2->mdstat_index) return 1;
  r = strcmp (s1->mdstat_flags, s2->mdstat_flags);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_mdstat_list (const struct guestfs_mdstat_list *s1, const struct guestfs_mdstat_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_mdstat (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfssubvolume (const struct guestfs_btrfssubvolume *s1, const struct guestfs_btrfssubvolume *s2)
{
  int r;

  if (s1->btrfssubvolume_id < s2->btrfssubvolume_id) return -1;
  else if (s1->btrfssubvolume_id > s2->btrfssubvolume_id) return 1;
  if (s1->btrfssubvolume_top_level_id < s2->btrfssubvolume_top_level_id) return -1;
  else if (s1->btrfssubvolume_top_level_id > s2->btrfssubvolume_top_level_id) return 1;
  r = strcmp (s1->btrfssubvolume_path, s2->btrfssubvolume_path);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *s1, const struct guestfs_btrfssubvolume_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_btrfssubvolume (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsqgroup (const struct guestfs_btrfsqgroup *s1, const struct guestfs_btrfsqgroup *s2)
{
  int r;

  r = strcmp (s1->btrfsqgroup_id, s2->btrfsqgroup_id);
  if (r != 0) return r;
  if (s1->btrfsqgroup_rfer < s2->btrfsqgroup_rfer) return -1;
  else if (s1->btrfsqgroup_rfer > s2->btrfsqgroup_rfer) return 1;
  if (s1->btrfsqgroup_excl < s2->btrfsqgroup_excl) return -1;
  else if (s1->btrfsqgroup_excl > s2->btrfsqgroup_excl) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *s1, const struct guestfs_btrfsqgroup_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_btrfsqgroup (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsbalance (const struct guestfs_btrfsbalance *s1, const struct guestfs_btrfsbalance *s2)
{
  int r;

  r = strcmp (s1->btrfsbalance_status, s2->btrfsbalance_status);
  if (r != 0) return r;
  if (s1->btrfsbalance_total < s2->btrfsbalance_total) return -1;
  else if (s1->btrfsbalance_total > s2->btrfsbalance_total) return 1;
  if (s1->btrfsbalance_balanced < s2->btrfsbalance_balanced) return -1;
  else if (s1->btrfsbalance_balanced > s2->btrfsbalance_balanced) return 1;
  if (s1->btrfsbalance_considered < s2->btrfsbalance_considered) return -1;
  else if (s1->btrfsbalance_considered > s2->btrfsbalance_considered) return 1;
  if (s1->btrfsbalance_left < s2->btrfsbalance_left) return -1;
  else if (s1->btrfsbalance_left > s2->btrfsbalance_left) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsbalance_list (const struct guestfs_btrfsbalance_list *s1, const struct guestfs_btrfsbalance_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_btrfsbalance (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsscrub (const struct guestfs_btrfsscrub *s1, const struct guestfs_btrfsscrub *s2)
{
  if (s1->btrfsscrub_data_extents_scrubbed < s2->btrfsscrub_data_extents_scrubbed) return -1;
  else if (s1->btrfsscrub_data_extents_scrubbed > s2->btrfsscrub_data_extents_scrubbed) return 1;
  if (s1->btrfsscrub_tree_extents_scrubbed < s2->btrfsscrub_tree_extents_scrubbed) return -1;
  else if (s1->btrfsscrub_tree_extents_scrubbed > s2->btrfsscrub_tree_extents_scrubbed) return 1;
  if (s1->btrfsscrub_data_bytes_scrubbed < s2->btrfsscrub_data_bytes_scrubbed) return -1;
  else if (s1->btrfsscrub_data_bytes_scrubbed > s2->btrfsscrub_data_bytes_scrubbed) return 1;
  if (s1->btrfsscrub_tree_bytes_scrubbed < s2->btrfsscrub_tree_bytes_scrubbed) return -1;
  else if (s1->btrfsscrub_tree_bytes_scrubbed > s2->btrfsscrub_tree_bytes_scrubbed) return 1;
  if (s1->btrfsscrub_read_errors < s2->btrfsscrub_read_errors) return -1;
  else if (s1->btrfsscrub_read_errors > s2->btrfsscrub_read_errors) return 1;
  if (s1->btrfsscrub_csum_errors < s2->btrfsscrub_csum_errors) return -1;
  else if (s1->btrfsscrub_csum_errors > s2->btrfsscrub_csum_errors) return 1;
  if (s1->btrfsscrub_verify_errors < s2->btrfsscrub_verify_errors) return -1;
  else if (s1->btrfsscrub_verify_errors > s2->btrfsscrub_verify_errors) return 1;
  if (s1->btrfsscrub_no_csum < s2->btrfsscrub_no_csum) return -1;
  else if (s1->btrfsscrub_no_csum > s2->btrfsscrub_no_csum) return 1;
  if (s1->btrfsscrub_csum_discards < s2->btrfsscrub_csum_discards) return -1;
  else if (s1->btrfsscrub_csum_discards > s2->btrfsscrub_csum_discards) return 1;
  if (s1->btrfsscrub_super_errors < s2->btrfsscrub_super_errors) return -1;
  else if (s1->btrfsscrub_super_errors > s2->btrfsscrub_super_errors) return 1;
  if (s1->btrfsscrub_malloc_errors < s2->btrfsscrub_malloc_errors) return -1;
  else if (s1->btrfsscrub_malloc_errors > s2->btrfsscrub_malloc_errors) return 1;
  if (s1->btrfsscrub_uncorrectable_errors < s2->btrfsscrub_uncorrectable_errors) return -1;
  else if (s1->btrfsscrub_uncorrectable_errors > s2->btrfsscrub_uncorrectable_errors) return 1;
  if (s1->btrfsscrub_unverified_errors < s2->btrfsscrub_unverified_errors) return -1;
  else if (s1->btrfsscrub_unverified_errors > s2->btrfsscrub_unverified_errors) return 1;
  if (s1->btrfsscrub_corrected_errors < s2->btrfsscrub_corrected_errors) return -1;
  else if (s1->btrfsscrub_corrected_errors > s2->btrfsscrub_corrected_errors) return 1;
  if (s1->btrfsscrub_last_physical < s2->btrfsscrub_last_physical) return -1;
  else if (s1->btrfsscrub_last_physical > s2->btrfsscrub_last_physical) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_btrfsscrub_list (const struct guestfs_btrfsscrub_list *s1, const struct guestfs_btrfsscrub_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_btrfsscrub (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_xfsinfo (const struct guestfs_xfsinfo *s1, const struct guestfs_xfsinfo *s2)
{
  int r;

  r = strcmp (s1->xfs_mntpoint, s2->xfs_mntpoint);
  if (r != 0) return r;
  if (s1->xfs_inodesize < s2->xfs_inodesize) return -1;
  else if (s1->xfs_inodesize > s2->xfs_inodesize) return 1;
  if (s1->xfs_agcount < s2->xfs_agcount) return -1;
  else if (s1->xfs_agcount > s2->xfs_agcount) return 1;
  if (s1->xfs_agsize < s2->xfs_agsize) return -1;
  else if (s1->xfs_agsize > s2->xfs_agsize) return 1;
  if (s1->xfs_sectsize < s2->xfs_sectsize) return -1;
  else if (s1->xfs_sectsize > s2->xfs_sectsize) return 1;
  if (s1->xfs_attr < s2->xfs_attr) return -1;
  else if (s1->xfs_attr > s2->xfs_attr) return 1;
  if (s1->xfs_blocksize < s2->xfs_blocksize) return -1;
  else if (s1->xfs_blocksize > s2->xfs_blocksize) return 1;
  if (s1->xfs_datablocks < s2->xfs_datablocks) return -1;
  else if (s1->xfs_datablocks > s2->xfs_datablocks) return 1;
  if (s1->xfs_imaxpct < s2->xfs_imaxpct) return -1;
  else if (s1->xfs_imaxpct > s2->xfs_imaxpct) return 1;
  if (s1->xfs_sunit < s2->xfs_sunit) return -1;
  else if (s1->xfs_sunit > s2->xfs_sunit) return 1;
  if (s1->xfs_swidth < s2->xfs_swidth) return -1;
  else if (s1->xfs_swidth > s2->xfs_swidth) return 1;
  if (s1->xfs_dirversion < s2->xfs_dirversion) return -1;
  else if (s1->xfs_dirversion > s2->xfs_dirversion) return 1;
  if (s1->xfs_dirblocksize < s2->xfs_dirblocksize) return -1;
  else if (s1->xfs_dirblocksize > s2->xfs_dirblocksize) return 1;
  if (s1->xfs_cimode < s2->xfs_cimode) return -1;
  else if (s1->xfs_cimode > s2->xfs_cimode) return 1;
  r = strcmp (s1->xfs_logname, s2->xfs_logname);
  if (r != 0) return r;
  if (s1->xfs_logblocksize < s2->xfs_logblocksize) return -1;
  else if (s1->xfs_logblocksize > s2->xfs_logblocksize) return 1;
  if (s1->xfs_logblocks < s2->xfs_logblocks) return -1;
  else if (s1->xfs_logblocks > s2->xfs_logblocks) return 1;
  if (s1->xfs_logversion < s2->xfs_logversion) return -1;
  else if (s1->xfs_logversion > s2->xfs_logversion) return 1;
  if (s1->xfs_logsectsize < s2->xfs_logsectsize) return -1;
  else if (s1->xfs_logsectsize > s2->xfs_logsectsize) return 1;
  if (s1->xfs_logsunit < s2->xfs_logsunit) return -1;
  else if (s1->xfs_logsunit > s2->xfs_logsunit) return 1;
  if (s1->xfs_lazycount < s2->xfs_lazycount) return -1;
  else if (s1->xfs_lazycount > s2->xfs_lazycount) return 1;
  r = strcmp (s1->xfs_rtname, s2->xfs_rtname);
  if (r != 0) return r;
  if (s1->xfs_rtextsize < s2->xfs_rtextsize) return -1;
  else if (s1->xfs_rtextsize > s2->xfs_rtextsize) return 1;
  if (s1->xfs_rtblocks < s2->xfs_rtblocks) return -1;
  else if (s1->xfs_rtblocks > s2->xfs_rtblocks) return 1;
  if (s1->xfs_rtextents < s2->xfs_rtextents) return -1;
  else if (s1->xfs_rtextents > s2->xfs_rtextents) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_xfsinfo_list (const struct guestfs_xfsinfo_list *s1, const struct guestfs_xfsinfo_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_xfsinfo (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_utsname (const struct guestfs_utsname *s1, const struct guestfs_utsname *s2)
{
  int r;

  r = strcmp (s1->uts_sysname, s2->uts_sysname);
  if (r != 0) return r;
  r = strcmp (s1->uts_release, s2->uts_release);
  if (r != 0) return r;
  r = strcmp (s1->uts_version, s2->uts_version);
  if (r != 0) return r;
  r = strcmp (s1->uts_machine, s2->uts_machine);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_utsname_list (const struct guestfs_utsname_list *s1, const struct guestfs_utsname_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_utsname (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_hivex_node (const struct guestfs_hivex_node *s1, const struct guestfs_hivex_node *s2)
{
  if (s1->hivex_node_h < s2->hivex_node_h) return -1;
  else if (s1->hivex_node_h > s2->hivex_node_h) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_hivex_node_list (const struct guestfs_hivex_node_list *s1, const struct guestfs_hivex_node_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_hivex_node (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_hivex_value (const struct guestfs_hivex_value *s1, const struct guestfs_hivex_value *s2)
{
  if (s1->hivex_value_h < s2->hivex_value_h) return -1;
  else if (s1->hivex_value_h > s2->hivex_value_h) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_hivex_value_list (const struct guestfs_hivex_value_list *s1, const struct guestfs_hivex_value_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_hivex_value (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_internal_mountable (const struct guestfs_internal_mountable *s1, const struct guestfs_internal_mountable *s2)
{
  int r;

  if (s1->im_type < s2->im_type) return -1;
  else if (s1->im_type > s2->im_type) return 1;
  r = strcmp (s1->im_device, s2->im_device);
  if (r != 0) return r;
  r = strcmp (s1->im_volume, s2->im_volume);
  if (r != 0) return r;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_internal_mountable_list (const struct guestfs_internal_mountable_list *s1, const struct guestfs_internal_mountable_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_internal_mountable (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_tsk_dirent (const struct guestfs_tsk_dirent *s1, const struct guestfs_tsk_dirent *s2)
{
  int r;

  if (s1->tsk_inode < s2->tsk_inode) return -1;
  else if (s1->tsk_inode > s2->tsk_inode) return 1;
  if (s1->tsk_type < s2->tsk_type) return -1;
  else if (s1->tsk_type > s2->tsk_type) return 1;
  if (s1->tsk_size < s2->tsk_size) return -1;
  else if (s1->tsk_size > s2->tsk_size) return 1;
  r = strcmp (s1->tsk_name, s2->tsk_name);
  if (r != 0) return r;
  if (s1->tsk_flags < s2->tsk_flags) return -1;
  else if (s1->tsk_flags > s2->tsk_flags) return 1;
  if (s1->tsk_atime_sec < s2->tsk_atime_sec) return -1;
  else if (s1->tsk_atime_sec > s2->tsk_atime_sec) return 1;
  if (s1->tsk_atime_nsec < s2->tsk_atime_nsec) return -1;
  else if (s1->tsk_atime_nsec > s2->tsk_atime_nsec) return 1;
  if (s1->tsk_mtime_sec < s2->tsk_mtime_sec) return -1;
  else if (s1->tsk_mtime_sec > s2->tsk_mtime_sec) return 1;
  if (s1->tsk_mtime_nsec < s2->tsk_mtime_nsec) return -1;
  else if (s1->tsk_mtime_nsec > s2->tsk_mtime_nsec) return 1;
  if (s1->tsk_ctime_sec < s2->tsk_ctime_sec) return -1;
  else if (s1->tsk_ctime_sec > s2->tsk_ctime_sec) return 1;
  if (s1->tsk_ctime_nsec < s2->tsk_ctime_nsec) return -1;
  else if (s1->tsk_ctime_nsec > s2->tsk_ctime_nsec) return 1;
  if (s1->tsk_crtime_sec < s2->tsk_crtime_sec) return -1;
  else if (s1->tsk_crtime_sec > s2->tsk_crtime_sec) return 1;
  if (s1->tsk_crtime_nsec < s2->tsk_crtime_nsec) return -1;
  else if (s1->tsk_crtime_nsec > s2->tsk_crtime_nsec) return 1;
  if (s1->tsk_nlink < s2->tsk_nlink) return -1;
  else if (s1->tsk_nlink > s2->tsk_nlink) return 1;
  r = strcmp (s1->tsk_link, s2->tsk_link);
  if (r != 0) return r;
  if (s1->tsk_spare1 < s2->tsk_spare1) return -1;
  else if (s1->tsk_spare1 > s2->tsk_spare1) return 1;
  return 0;
}

GUESTFS_DLL_PUBLIC int
guestfs_compare_tsk_dirent_list (const struct guestfs_tsk_dirent_list *s1, const struct guestfs_tsk_dirent_list *s2)
{
  if (s1->len < s2->len) return -1;
  else if (s1->len > s2->len) return 1;
  else {
    size_t i;
    int r;

    for (i = 0; i < s1->len; ++i) {
      r = guestfs_compare_tsk_dirent (&s1->val[i], &s2->val[i]);
      if (r != 0) return r;
    }
    return 0;
  }
}
