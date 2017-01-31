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

/* Structure-copying functions. */

static void
copy_int_bool (const struct guestfs_int_bool *inp, struct guestfs_int_bool *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_int_bool *
guestfs_copy_int_bool (const struct guestfs_int_bool *inp)
{
  struct guestfs_int_bool *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_int_bool (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_int_bool_list *
guestfs_copy_int_bool_list (const struct guestfs_int_bool_list *inp)
{
  int err;
  struct guestfs_int_bool_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_int_bool) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_int_bool (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_lvm_pv (struct guestfs_lvm_pv *s)
{
  free (s->pv_name);
  free (s->pv_fmt);
  free (s->pv_attr);
  free (s->pv_tags);
}

static int
copy_lvm_pv (const struct guestfs_lvm_pv *inp, struct guestfs_lvm_pv *out)
{
  int err;

  out->pv_name = NULL;
  out->pv_fmt = NULL;
  out->pv_attr = NULL;
  out->pv_tags = NULL;
  out->pv_name = strdup (inp->pv_name);
  if (out->pv_name == NULL) goto error;
  memcpy (out->pv_uuid, inp->pv_uuid, 32 * sizeof (char));
  out->pv_fmt = strdup (inp->pv_fmt);
  if (out->pv_fmt == NULL) goto error;
  out->pv_size = inp->pv_size;
  out->dev_size = inp->dev_size;
  out->pv_free = inp->pv_free;
  out->pv_used = inp->pv_used;
  out->pv_attr = strdup (inp->pv_attr);
  if (out->pv_attr == NULL) goto error;
  out->pv_pe_count = inp->pv_pe_count;
  out->pv_pe_alloc_count = inp->pv_pe_alloc_count;
  out->pv_tags = strdup (inp->pv_tags);
  if (out->pv_tags == NULL) goto error;
  out->pe_start = inp->pe_start;
  out->pv_mda_count = inp->pv_mda_count;
  out->pv_mda_free = inp->pv_mda_free;
  return 0;

error: ;
  err = errno;
  free_lvm_pv (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *
guestfs_copy_lvm_pv (const struct guestfs_lvm_pv *inp)
{
  struct guestfs_lvm_pv *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_lvm_pv (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_copy_lvm_pv_list (const struct guestfs_lvm_pv_list *inp)
{
  int err;
  struct guestfs_lvm_pv_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_lvm_pv) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_lvm_pv (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_lvm_pv (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_lvm_vg (struct guestfs_lvm_vg *s)
{
  free (s->vg_name);
  free (s->vg_fmt);
  free (s->vg_attr);
  free (s->vg_sysid);
  free (s->vg_tags);
}

static int
copy_lvm_vg (const struct guestfs_lvm_vg *inp, struct guestfs_lvm_vg *out)
{
  int err;

  out->vg_name = NULL;
  out->vg_fmt = NULL;
  out->vg_attr = NULL;
  out->vg_sysid = NULL;
  out->vg_tags = NULL;
  out->vg_name = strdup (inp->vg_name);
  if (out->vg_name == NULL) goto error;
  memcpy (out->vg_uuid, inp->vg_uuid, 32 * sizeof (char));
  out->vg_fmt = strdup (inp->vg_fmt);
  if (out->vg_fmt == NULL) goto error;
  out->vg_attr = strdup (inp->vg_attr);
  if (out->vg_attr == NULL) goto error;
  out->vg_size = inp->vg_size;
  out->vg_free = inp->vg_free;
  out->vg_sysid = strdup (inp->vg_sysid);
  if (out->vg_sysid == NULL) goto error;
  out->vg_extent_size = inp->vg_extent_size;
  out->vg_extent_count = inp->vg_extent_count;
  out->vg_free_count = inp->vg_free_count;
  out->max_lv = inp->max_lv;
  out->max_pv = inp->max_pv;
  out->pv_count = inp->pv_count;
  out->lv_count = inp->lv_count;
  out->snap_count = inp->snap_count;
  out->vg_seqno = inp->vg_seqno;
  out->vg_tags = strdup (inp->vg_tags);
  if (out->vg_tags == NULL) goto error;
  out->vg_mda_count = inp->vg_mda_count;
  out->vg_mda_free = inp->vg_mda_free;
  return 0;

error: ;
  err = errno;
  free_lvm_vg (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg *
guestfs_copy_lvm_vg (const struct guestfs_lvm_vg *inp)
{
  struct guestfs_lvm_vg *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_lvm_vg (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg_list *
guestfs_copy_lvm_vg_list (const struct guestfs_lvm_vg_list *inp)
{
  int err;
  struct guestfs_lvm_vg_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_lvm_vg) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_lvm_vg (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_lvm_vg (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_lvm_lv (struct guestfs_lvm_lv *s)
{
  free (s->lv_name);
  free (s->lv_attr);
  free (s->origin);
  free (s->move_pv);
  free (s->lv_tags);
  free (s->mirror_log);
  free (s->modules);
}

static int
copy_lvm_lv (const struct guestfs_lvm_lv *inp, struct guestfs_lvm_lv *out)
{
  int err;

  out->lv_name = NULL;
  out->lv_attr = NULL;
  out->origin = NULL;
  out->move_pv = NULL;
  out->lv_tags = NULL;
  out->mirror_log = NULL;
  out->modules = NULL;
  out->lv_name = strdup (inp->lv_name);
  if (out->lv_name == NULL) goto error;
  memcpy (out->lv_uuid, inp->lv_uuid, 32 * sizeof (char));
  out->lv_attr = strdup (inp->lv_attr);
  if (out->lv_attr == NULL) goto error;
  out->lv_major = inp->lv_major;
  out->lv_minor = inp->lv_minor;
  out->lv_kernel_major = inp->lv_kernel_major;
  out->lv_kernel_minor = inp->lv_kernel_minor;
  out->lv_size = inp->lv_size;
  out->seg_count = inp->seg_count;
  out->origin = strdup (inp->origin);
  if (out->origin == NULL) goto error;
  out->snap_percent = inp->snap_percent;
  out->copy_percent = inp->copy_percent;
  out->move_pv = strdup (inp->move_pv);
  if (out->move_pv == NULL) goto error;
  out->lv_tags = strdup (inp->lv_tags);
  if (out->lv_tags == NULL) goto error;
  out->mirror_log = strdup (inp->mirror_log);
  if (out->mirror_log == NULL) goto error;
  out->modules = strdup (inp->modules);
  if (out->modules == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_lvm_lv (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv *
guestfs_copy_lvm_lv (const struct guestfs_lvm_lv *inp)
{
  struct guestfs_lvm_lv *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_lvm_lv (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv_list *
guestfs_copy_lvm_lv_list (const struct guestfs_lvm_lv_list *inp)
{
  int err;
  struct guestfs_lvm_lv_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_lvm_lv) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_lvm_lv (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_lvm_lv (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_stat (const struct guestfs_stat *inp, struct guestfs_stat *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_stat *
guestfs_copy_stat (const struct guestfs_stat *inp)
{
  struct guestfs_stat *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_stat (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat_list *
guestfs_copy_stat_list (const struct guestfs_stat_list *inp)
{
  int err;
  struct guestfs_stat_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_stat) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_stat (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_statns (const struct guestfs_statns *inp, struct guestfs_statns *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_statns *
guestfs_copy_statns (const struct guestfs_statns *inp)
{
  struct guestfs_statns *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_statns (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_statns_list *
guestfs_copy_statns_list (const struct guestfs_statns_list *inp)
{
  int err;
  struct guestfs_statns_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_statns) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_statns (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_statvfs (const struct guestfs_statvfs *inp, struct guestfs_statvfs *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_statvfs *
guestfs_copy_statvfs (const struct guestfs_statvfs *inp)
{
  struct guestfs_statvfs *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_statvfs (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_statvfs_list *
guestfs_copy_statvfs_list (const struct guestfs_statvfs_list *inp)
{
  int err;
  struct guestfs_statvfs_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_statvfs) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_statvfs (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_dirent (struct guestfs_dirent *s)
{
  free (s->name);
}

static int
copy_dirent (const struct guestfs_dirent *inp, struct guestfs_dirent *out)
{
  int err;

  out->name = NULL;
  out->ino = inp->ino;
  out->ftyp = inp->ftyp;
  out->name = strdup (inp->name);
  if (out->name == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_dirent (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_dirent *
guestfs_copy_dirent (const struct guestfs_dirent *inp)
{
  struct guestfs_dirent *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_dirent (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_dirent_list *
guestfs_copy_dirent_list (const struct guestfs_dirent_list *inp)
{
  int err;
  struct guestfs_dirent_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_dirent) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_dirent (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_dirent (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_version (struct guestfs_version *s)
{
  free (s->extra);
}

static int
copy_version (const struct guestfs_version *inp, struct guestfs_version *out)
{
  int err;

  out->extra = NULL;
  out->major = inp->major;
  out->minor = inp->minor;
  out->release = inp->release;
  out->extra = strdup (inp->extra);
  if (out->extra == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_version (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_version *
guestfs_copy_version (const struct guestfs_version *inp)
{
  struct guestfs_version *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_version (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_version_list *
guestfs_copy_version_list (const struct guestfs_version_list *inp)
{
  int err;
  struct guestfs_version_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_version) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_version (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_version (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_xattr (struct guestfs_xattr *s)
{
  free (s->attrname);
  free (s->attrval);
}

static int
copy_xattr (const struct guestfs_xattr *inp, struct guestfs_xattr *out)
{
  int err;

  out->attrname = NULL;
  out->attrval = NULL;
  out->attrname = strdup (inp->attrname);
  if (out->attrname == NULL) goto error;
  /* This adds NUL-termination, which is not strictly required
   * but avoids a common bug in calling code.  Note that callers
   * should NOT depend on this behaviour intentionally.
   */
  out->attrval_len = inp->attrval_len;
  out->attrval = malloc (out->attrval_len + 1);
  if (out->attrval == NULL) goto error;
  memcpy (out->attrval, inp->attrval, out->attrval_len);
  out->attrval[out->attrval_len] = '\0';
  return 0;

error: ;
  err = errno;
  free_xattr (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr *
guestfs_copy_xattr (const struct guestfs_xattr *inp)
{
  struct guestfs_xattr *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_xattr (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *
guestfs_copy_xattr_list (const struct guestfs_xattr_list *inp)
{
  int err;
  struct guestfs_xattr_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_xattr) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_xattr (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_xattr (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_inotify_event (struct guestfs_inotify_event *s)
{
  free (s->in_name);
}

static int
copy_inotify_event (const struct guestfs_inotify_event *inp, struct guestfs_inotify_event *out)
{
  int err;

  out->in_name = NULL;
  out->in_wd = inp->in_wd;
  out->in_mask = inp->in_mask;
  out->in_cookie = inp->in_cookie;
  out->in_name = strdup (inp->in_name);
  if (out->in_name == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_inotify_event (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_inotify_event *
guestfs_copy_inotify_event (const struct guestfs_inotify_event *inp)
{
  struct guestfs_inotify_event *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_inotify_event (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_inotify_event_list *
guestfs_copy_inotify_event_list (const struct guestfs_inotify_event_list *inp)
{
  int err;
  struct guestfs_inotify_event_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_inotify_event) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_inotify_event (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_inotify_event (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_partition (const struct guestfs_partition *inp, struct guestfs_partition *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_partition *
guestfs_copy_partition (const struct guestfs_partition *inp)
{
  struct guestfs_partition *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_partition (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_partition_list *
guestfs_copy_partition_list (const struct guestfs_partition_list *inp)
{
  int err;
  struct guestfs_partition_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_partition) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_partition (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_application (struct guestfs_application *s)
{
  free (s->app_name);
  free (s->app_display_name);
  free (s->app_version);
  free (s->app_release);
  free (s->app_install_path);
  free (s->app_trans_path);
  free (s->app_publisher);
  free (s->app_url);
  free (s->app_source_package);
  free (s->app_summary);
  free (s->app_description);
}

static int
copy_application (const struct guestfs_application *inp, struct guestfs_application *out)
{
  int err;

  out->app_name = NULL;
  out->app_display_name = NULL;
  out->app_version = NULL;
  out->app_release = NULL;
  out->app_install_path = NULL;
  out->app_trans_path = NULL;
  out->app_publisher = NULL;
  out->app_url = NULL;
  out->app_source_package = NULL;
  out->app_summary = NULL;
  out->app_description = NULL;
  out->app_name = strdup (inp->app_name);
  if (out->app_name == NULL) goto error;
  out->app_display_name = strdup (inp->app_display_name);
  if (out->app_display_name == NULL) goto error;
  out->app_epoch = inp->app_epoch;
  out->app_version = strdup (inp->app_version);
  if (out->app_version == NULL) goto error;
  out->app_release = strdup (inp->app_release);
  if (out->app_release == NULL) goto error;
  out->app_install_path = strdup (inp->app_install_path);
  if (out->app_install_path == NULL) goto error;
  out->app_trans_path = strdup (inp->app_trans_path);
  if (out->app_trans_path == NULL) goto error;
  out->app_publisher = strdup (inp->app_publisher);
  if (out->app_publisher == NULL) goto error;
  out->app_url = strdup (inp->app_url);
  if (out->app_url == NULL) goto error;
  out->app_source_package = strdup (inp->app_source_package);
  if (out->app_source_package == NULL) goto error;
  out->app_summary = strdup (inp->app_summary);
  if (out->app_summary == NULL) goto error;
  out->app_description = strdup (inp->app_description);
  if (out->app_description == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_application (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_application *
guestfs_copy_application (const struct guestfs_application *inp)
{
  struct guestfs_application *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_application (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_application_list *
guestfs_copy_application_list (const struct guestfs_application_list *inp)
{
  int err;
  struct guestfs_application_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_application) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_application (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_application (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_application2 (struct guestfs_application2 *s)
{
  free (s->app2_name);
  free (s->app2_display_name);
  free (s->app2_version);
  free (s->app2_release);
  free (s->app2_arch);
  free (s->app2_install_path);
  free (s->app2_trans_path);
  free (s->app2_publisher);
  free (s->app2_url);
  free (s->app2_source_package);
  free (s->app2_summary);
  free (s->app2_description);
  free (s->app2_spare1);
  free (s->app2_spare2);
  free (s->app2_spare3);
  free (s->app2_spare4);
}

static int
copy_application2 (const struct guestfs_application2 *inp, struct guestfs_application2 *out)
{
  int err;

  out->app2_name = NULL;
  out->app2_display_name = NULL;
  out->app2_version = NULL;
  out->app2_release = NULL;
  out->app2_arch = NULL;
  out->app2_install_path = NULL;
  out->app2_trans_path = NULL;
  out->app2_publisher = NULL;
  out->app2_url = NULL;
  out->app2_source_package = NULL;
  out->app2_summary = NULL;
  out->app2_description = NULL;
  out->app2_spare1 = NULL;
  out->app2_spare2 = NULL;
  out->app2_spare3 = NULL;
  out->app2_spare4 = NULL;
  out->app2_name = strdup (inp->app2_name);
  if (out->app2_name == NULL) goto error;
  out->app2_display_name = strdup (inp->app2_display_name);
  if (out->app2_display_name == NULL) goto error;
  out->app2_epoch = inp->app2_epoch;
  out->app2_version = strdup (inp->app2_version);
  if (out->app2_version == NULL) goto error;
  out->app2_release = strdup (inp->app2_release);
  if (out->app2_release == NULL) goto error;
  out->app2_arch = strdup (inp->app2_arch);
  if (out->app2_arch == NULL) goto error;
  out->app2_install_path = strdup (inp->app2_install_path);
  if (out->app2_install_path == NULL) goto error;
  out->app2_trans_path = strdup (inp->app2_trans_path);
  if (out->app2_trans_path == NULL) goto error;
  out->app2_publisher = strdup (inp->app2_publisher);
  if (out->app2_publisher == NULL) goto error;
  out->app2_url = strdup (inp->app2_url);
  if (out->app2_url == NULL) goto error;
  out->app2_source_package = strdup (inp->app2_source_package);
  if (out->app2_source_package == NULL) goto error;
  out->app2_summary = strdup (inp->app2_summary);
  if (out->app2_summary == NULL) goto error;
  out->app2_description = strdup (inp->app2_description);
  if (out->app2_description == NULL) goto error;
  out->app2_spare1 = strdup (inp->app2_spare1);
  if (out->app2_spare1 == NULL) goto error;
  out->app2_spare2 = strdup (inp->app2_spare2);
  if (out->app2_spare2 == NULL) goto error;
  out->app2_spare3 = strdup (inp->app2_spare3);
  if (out->app2_spare3 == NULL) goto error;
  out->app2_spare4 = strdup (inp->app2_spare4);
  if (out->app2_spare4 == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_application2 (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_application2 *
guestfs_copy_application2 (const struct guestfs_application2 *inp)
{
  struct guestfs_application2 *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_application2 (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_application2_list *
guestfs_copy_application2_list (const struct guestfs_application2_list *inp)
{
  int err;
  struct guestfs_application2_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_application2) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_application2 (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_application2 (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_isoinfo (struct guestfs_isoinfo *s)
{
  free (s->iso_system_id);
  free (s->iso_volume_id);
  free (s->iso_volume_set_id);
  free (s->iso_publisher_id);
  free (s->iso_data_preparer_id);
  free (s->iso_application_id);
  free (s->iso_copyright_file_id);
  free (s->iso_abstract_file_id);
  free (s->iso_bibliographic_file_id);
}

static int
copy_isoinfo (const struct guestfs_isoinfo *inp, struct guestfs_isoinfo *out)
{
  int err;

  out->iso_system_id = NULL;
  out->iso_volume_id = NULL;
  out->iso_volume_set_id = NULL;
  out->iso_publisher_id = NULL;
  out->iso_data_preparer_id = NULL;
  out->iso_application_id = NULL;
  out->iso_copyright_file_id = NULL;
  out->iso_abstract_file_id = NULL;
  out->iso_bibliographic_file_id = NULL;
  out->iso_system_id = strdup (inp->iso_system_id);
  if (out->iso_system_id == NULL) goto error;
  out->iso_volume_id = strdup (inp->iso_volume_id);
  if (out->iso_volume_id == NULL) goto error;
  out->iso_volume_space_size = inp->iso_volume_space_size;
  out->iso_volume_set_size = inp->iso_volume_set_size;
  out->iso_volume_sequence_number = inp->iso_volume_sequence_number;
  out->iso_logical_block_size = inp->iso_logical_block_size;
  out->iso_volume_set_id = strdup (inp->iso_volume_set_id);
  if (out->iso_volume_set_id == NULL) goto error;
  out->iso_publisher_id = strdup (inp->iso_publisher_id);
  if (out->iso_publisher_id == NULL) goto error;
  out->iso_data_preparer_id = strdup (inp->iso_data_preparer_id);
  if (out->iso_data_preparer_id == NULL) goto error;
  out->iso_application_id = strdup (inp->iso_application_id);
  if (out->iso_application_id == NULL) goto error;
  out->iso_copyright_file_id = strdup (inp->iso_copyright_file_id);
  if (out->iso_copyright_file_id == NULL) goto error;
  out->iso_abstract_file_id = strdup (inp->iso_abstract_file_id);
  if (out->iso_abstract_file_id == NULL) goto error;
  out->iso_bibliographic_file_id = strdup (inp->iso_bibliographic_file_id);
  if (out->iso_bibliographic_file_id == NULL) goto error;
  out->iso_volume_creation_t = inp->iso_volume_creation_t;
  out->iso_volume_modification_t = inp->iso_volume_modification_t;
  out->iso_volume_expiration_t = inp->iso_volume_expiration_t;
  out->iso_volume_effective_t = inp->iso_volume_effective_t;
  return 0;

error: ;
  err = errno;
  free_isoinfo (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *
guestfs_copy_isoinfo (const struct guestfs_isoinfo *inp)
{
  struct guestfs_isoinfo *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_isoinfo (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_isoinfo_list *
guestfs_copy_isoinfo_list (const struct guestfs_isoinfo_list *inp)
{
  int err;
  struct guestfs_isoinfo_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_isoinfo) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_isoinfo (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_isoinfo (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_mdstat (struct guestfs_mdstat *s)
{
  free (s->mdstat_device);
  free (s->mdstat_flags);
}

static int
copy_mdstat (const struct guestfs_mdstat *inp, struct guestfs_mdstat *out)
{
  int err;

  out->mdstat_device = NULL;
  out->mdstat_flags = NULL;
  out->mdstat_device = strdup (inp->mdstat_device);
  if (out->mdstat_device == NULL) goto error;
  out->mdstat_index = inp->mdstat_index;
  out->mdstat_flags = strdup (inp->mdstat_flags);
  if (out->mdstat_flags == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_mdstat (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_mdstat *
guestfs_copy_mdstat (const struct guestfs_mdstat *inp)
{
  struct guestfs_mdstat *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_mdstat (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_mdstat_list *
guestfs_copy_mdstat_list (const struct guestfs_mdstat_list *inp)
{
  int err;
  struct guestfs_mdstat_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_mdstat) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_mdstat (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_mdstat (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_btrfssubvolume (struct guestfs_btrfssubvolume *s)
{
  free (s->btrfssubvolume_path);
}

static int
copy_btrfssubvolume (const struct guestfs_btrfssubvolume *inp, struct guestfs_btrfssubvolume *out)
{
  int err;

  out->btrfssubvolume_path = NULL;
  out->btrfssubvolume_id = inp->btrfssubvolume_id;
  out->btrfssubvolume_top_level_id = inp->btrfssubvolume_top_level_id;
  out->btrfssubvolume_path = strdup (inp->btrfssubvolume_path);
  if (out->btrfssubvolume_path == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_btrfssubvolume (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume *
guestfs_copy_btrfssubvolume (const struct guestfs_btrfssubvolume *inp)
{
  struct guestfs_btrfssubvolume *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_btrfssubvolume (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfssubvolume_list *
guestfs_copy_btrfssubvolume_list (const struct guestfs_btrfssubvolume_list *inp)
{
  int err;
  struct guestfs_btrfssubvolume_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_btrfssubvolume) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_btrfssubvolume (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_btrfssubvolume (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_btrfsqgroup (struct guestfs_btrfsqgroup *s)
{
  free (s->btrfsqgroup_id);
}

static int
copy_btrfsqgroup (const struct guestfs_btrfsqgroup *inp, struct guestfs_btrfsqgroup *out)
{
  int err;

  out->btrfsqgroup_id = NULL;
  out->btrfsqgroup_id = strdup (inp->btrfsqgroup_id);
  if (out->btrfsqgroup_id == NULL) goto error;
  out->btrfsqgroup_rfer = inp->btrfsqgroup_rfer;
  out->btrfsqgroup_excl = inp->btrfsqgroup_excl;
  return 0;

error: ;
  err = errno;
  free_btrfsqgroup (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup *
guestfs_copy_btrfsqgroup (const struct guestfs_btrfsqgroup *inp)
{
  struct guestfs_btrfsqgroup *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_btrfsqgroup (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup_list *
guestfs_copy_btrfsqgroup_list (const struct guestfs_btrfsqgroup_list *inp)
{
  int err;
  struct guestfs_btrfsqgroup_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_btrfsqgroup) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_btrfsqgroup (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_btrfsqgroup (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_btrfsbalance (struct guestfs_btrfsbalance *s)
{
  free (s->btrfsbalance_status);
}

static int
copy_btrfsbalance (const struct guestfs_btrfsbalance *inp, struct guestfs_btrfsbalance *out)
{
  int err;

  out->btrfsbalance_status = NULL;
  out->btrfsbalance_status = strdup (inp->btrfsbalance_status);
  if (out->btrfsbalance_status == NULL) goto error;
  out->btrfsbalance_total = inp->btrfsbalance_total;
  out->btrfsbalance_balanced = inp->btrfsbalance_balanced;
  out->btrfsbalance_considered = inp->btrfsbalance_considered;
  out->btrfsbalance_left = inp->btrfsbalance_left;
  return 0;

error: ;
  err = errno;
  free_btrfsbalance (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsbalance *
guestfs_copy_btrfsbalance (const struct guestfs_btrfsbalance *inp)
{
  struct guestfs_btrfsbalance *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_btrfsbalance (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsbalance_list *
guestfs_copy_btrfsbalance_list (const struct guestfs_btrfsbalance_list *inp)
{
  int err;
  struct guestfs_btrfsbalance_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_btrfsbalance) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_btrfsbalance (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_btrfsbalance (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_btrfsscrub (const struct guestfs_btrfsscrub *inp, struct guestfs_btrfsscrub *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsscrub *
guestfs_copy_btrfsscrub (const struct guestfs_btrfsscrub *inp)
{
  struct guestfs_btrfsscrub *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_btrfsscrub (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsscrub_list *
guestfs_copy_btrfsscrub_list (const struct guestfs_btrfsscrub_list *inp)
{
  int err;
  struct guestfs_btrfsscrub_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_btrfsscrub) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_btrfsscrub (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_xfsinfo (struct guestfs_xfsinfo *s)
{
  free (s->xfs_mntpoint);
  free (s->xfs_logname);
  free (s->xfs_rtname);
}

static int
copy_xfsinfo (const struct guestfs_xfsinfo *inp, struct guestfs_xfsinfo *out)
{
  int err;

  out->xfs_mntpoint = NULL;
  out->xfs_logname = NULL;
  out->xfs_rtname = NULL;
  out->xfs_mntpoint = strdup (inp->xfs_mntpoint);
  if (out->xfs_mntpoint == NULL) goto error;
  out->xfs_inodesize = inp->xfs_inodesize;
  out->xfs_agcount = inp->xfs_agcount;
  out->xfs_agsize = inp->xfs_agsize;
  out->xfs_sectsize = inp->xfs_sectsize;
  out->xfs_attr = inp->xfs_attr;
  out->xfs_blocksize = inp->xfs_blocksize;
  out->xfs_datablocks = inp->xfs_datablocks;
  out->xfs_imaxpct = inp->xfs_imaxpct;
  out->xfs_sunit = inp->xfs_sunit;
  out->xfs_swidth = inp->xfs_swidth;
  out->xfs_dirversion = inp->xfs_dirversion;
  out->xfs_dirblocksize = inp->xfs_dirblocksize;
  out->xfs_cimode = inp->xfs_cimode;
  out->xfs_logname = strdup (inp->xfs_logname);
  if (out->xfs_logname == NULL) goto error;
  out->xfs_logblocksize = inp->xfs_logblocksize;
  out->xfs_logblocks = inp->xfs_logblocks;
  out->xfs_logversion = inp->xfs_logversion;
  out->xfs_logsectsize = inp->xfs_logsectsize;
  out->xfs_logsunit = inp->xfs_logsunit;
  out->xfs_lazycount = inp->xfs_lazycount;
  out->xfs_rtname = strdup (inp->xfs_rtname);
  if (out->xfs_rtname == NULL) goto error;
  out->xfs_rtextsize = inp->xfs_rtextsize;
  out->xfs_rtblocks = inp->xfs_rtblocks;
  out->xfs_rtextents = inp->xfs_rtextents;
  return 0;

error: ;
  err = errno;
  free_xfsinfo (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo *
guestfs_copy_xfsinfo (const struct guestfs_xfsinfo *inp)
{
  struct guestfs_xfsinfo *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_xfsinfo (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo_list *
guestfs_copy_xfsinfo_list (const struct guestfs_xfsinfo_list *inp)
{
  int err;
  struct guestfs_xfsinfo_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_xfsinfo) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_xfsinfo (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_xfsinfo (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_utsname (struct guestfs_utsname *s)
{
  free (s->uts_sysname);
  free (s->uts_release);
  free (s->uts_version);
  free (s->uts_machine);
}

static int
copy_utsname (const struct guestfs_utsname *inp, struct guestfs_utsname *out)
{
  int err;

  out->uts_sysname = NULL;
  out->uts_release = NULL;
  out->uts_version = NULL;
  out->uts_machine = NULL;
  out->uts_sysname = strdup (inp->uts_sysname);
  if (out->uts_sysname == NULL) goto error;
  out->uts_release = strdup (inp->uts_release);
  if (out->uts_release == NULL) goto error;
  out->uts_version = strdup (inp->uts_version);
  if (out->uts_version == NULL) goto error;
  out->uts_machine = strdup (inp->uts_machine);
  if (out->uts_machine == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_utsname (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_utsname *
guestfs_copy_utsname (const struct guestfs_utsname *inp)
{
  struct guestfs_utsname *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_utsname (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_utsname_list *
guestfs_copy_utsname_list (const struct guestfs_utsname_list *inp)
{
  int err;
  struct guestfs_utsname_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_utsname) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_utsname (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_utsname (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_hivex_node (const struct guestfs_hivex_node *inp, struct guestfs_hivex_node *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_node *
guestfs_copy_hivex_node (const struct guestfs_hivex_node *inp)
{
  struct guestfs_hivex_node *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_hivex_node (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_node_list *
guestfs_copy_hivex_node_list (const struct guestfs_hivex_node_list *inp)
{
  int err;
  struct guestfs_hivex_node_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_hivex_node) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_hivex_node (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
copy_hivex_value (const struct guestfs_hivex_value *inp, struct guestfs_hivex_value *out)
{
  memcpy (out, inp, sizeof *out);
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_value *
guestfs_copy_hivex_value (const struct guestfs_hivex_value *inp)
{
  struct guestfs_hivex_value *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  copy_hivex_value (inp, ret);

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_hivex_value_list *
guestfs_copy_hivex_value_list (const struct guestfs_hivex_value_list *inp)
{
  int err;
  struct guestfs_hivex_value_list *ret;
  size_t i = 0;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_hivex_value) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    copy_hivex_value (&inp->val[i], &ret->val[i]);
  }

  return ret;

error: ;
  err = errno;
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_internal_mountable (struct guestfs_internal_mountable *s)
{
  free (s->im_device);
  free (s->im_volume);
}

static int
copy_internal_mountable (const struct guestfs_internal_mountable *inp, struct guestfs_internal_mountable *out)
{
  int err;

  out->im_device = NULL;
  out->im_volume = NULL;
  out->im_type = inp->im_type;
  out->im_device = strdup (inp->im_device);
  if (out->im_device == NULL) goto error;
  out->im_volume = strdup (inp->im_volume);
  if (out->im_volume == NULL) goto error;
  return 0;

error: ;
  err = errno;
  free_internal_mountable (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable *
guestfs_copy_internal_mountable (const struct guestfs_internal_mountable *inp)
{
  struct guestfs_internal_mountable *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_internal_mountable (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_internal_mountable_list *
guestfs_copy_internal_mountable_list (const struct guestfs_internal_mountable_list *inp)
{
  int err;
  struct guestfs_internal_mountable_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_internal_mountable) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_internal_mountable (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_internal_mountable (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}

static void
free_tsk_dirent (struct guestfs_tsk_dirent *s)
{
  free (s->tsk_name);
  free (s->tsk_link);
}

static int
copy_tsk_dirent (const struct guestfs_tsk_dirent *inp, struct guestfs_tsk_dirent *out)
{
  int err;

  out->tsk_name = NULL;
  out->tsk_link = NULL;
  out->tsk_inode = inp->tsk_inode;
  out->tsk_type = inp->tsk_type;
  out->tsk_size = inp->tsk_size;
  out->tsk_name = strdup (inp->tsk_name);
  if (out->tsk_name == NULL) goto error;
  out->tsk_flags = inp->tsk_flags;
  out->tsk_atime_sec = inp->tsk_atime_sec;
  out->tsk_atime_nsec = inp->tsk_atime_nsec;
  out->tsk_mtime_sec = inp->tsk_mtime_sec;
  out->tsk_mtime_nsec = inp->tsk_mtime_nsec;
  out->tsk_ctime_sec = inp->tsk_ctime_sec;
  out->tsk_ctime_nsec = inp->tsk_ctime_nsec;
  out->tsk_crtime_sec = inp->tsk_crtime_sec;
  out->tsk_crtime_nsec = inp->tsk_crtime_nsec;
  out->tsk_nlink = inp->tsk_nlink;
  out->tsk_link = strdup (inp->tsk_link);
  if (out->tsk_link == NULL) goto error;
  out->tsk_spare1 = inp->tsk_spare1;
  return 0;

error: ;
  err = errno;
  free_tsk_dirent (out);
  errno = err;
  return -1;
}

GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent *
guestfs_copy_tsk_dirent (const struct guestfs_tsk_dirent *inp)
{
  struct guestfs_tsk_dirent *ret;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  if (copy_tsk_dirent (inp, ret) == -1) {
    int err;

    err = errno;
    free (ret);
    errno = err;
    return NULL;
  }

  return ret;
}

GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent_list *
guestfs_copy_tsk_dirent_list (const struct guestfs_tsk_dirent_list *inp)
{
  int err;
  struct guestfs_tsk_dirent_list *ret;
  size_t i = 0;
  size_t j;

  ret = malloc (sizeof *ret);
  if (ret == NULL)
    return NULL;

  ret->len = inp->len;
  ret->val = malloc (sizeof (struct guestfs_tsk_dirent) * ret->len);
  if (ret->val == NULL)
    goto error;

  for (i = 0; i < ret->len; ++i) {
    if (copy_tsk_dirent (&inp->val[i], &ret->val[i]) == -1)
      goto error;
  }

  return ret;

error: ;
  err = errno;
  for (j = 0; j < i; ++j)
    free_tsk_dirent (&ret->val[j]);
  free (ret->val);
  free (ret);
  errno = err;
  return NULL;
}
