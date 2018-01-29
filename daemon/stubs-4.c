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
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <rpc/types.h>
#include <rpc/xdr.h>

#include "daemon.h"
#include "c-ctype.h"
#include "guestfs_protocol.h"
#include "actions.h"
#include "optgroups.h"
#include "stubs.h"
#include "stubs-macros.h"

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_INIT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_init_args)))

static void
cleanup_xdr_free_aug_init_args (struct guestfs_aug_init_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_init_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_INIT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_init_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_INIT_ARGS struct guestfs_aug_init_args args;
  memset (&args, 0, sizeof args);
  const char *root;
  int flags;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  root = args.root;
  ABS_PATH (root, false, return);
  flags = args.flags;

  NEED_ROOT (false, return);
  r = do_aug_init (root, flags);
  if (r == -1)
    /* do_aug_init has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_INSERT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_insert_args)))

static void
cleanup_xdr_free_aug_insert_args (struct guestfs_aug_insert_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_insert_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_INSERT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_insert_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_INSERT_ARGS struct guestfs_aug_insert_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;
  const char *label;
  int before;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_insert_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;
  label = args.label;
  before = args.before;

  r = do_aug_insert (augpath, label, before);
  if (r == -1)
    /* do_aug_insert has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
aug_load_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_aug_load ();
  if (r == -1)
    /* do_aug_load has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_RM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_rm_args)))

static void
cleanup_xdr_free_aug_rm_args (struct guestfs_aug_rm_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_rm_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_RM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_rm_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_RM_ARGS struct guestfs_aug_rm_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_rm (augpath);
  if (r == -1)
    /* do_aug_rm has already called reply_with_error */
    return;

  struct guestfs_aug_rm_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_rm_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_SET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_set_args)))

static void
cleanup_xdr_free_aug_set_args (struct guestfs_aug_set_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_set_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_SET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_set_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_SET_ARGS struct guestfs_aug_set_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_set_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;
  val = args.val;

  r = do_aug_set (augpath, val);
  if (r == -1)
    /* do_aug_set has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLKID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blkid_args)))

static void
cleanup_xdr_free_blkid_args (struct guestfs_blkid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blkid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLKID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blkid_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_BLKID_ARGS struct guestfs_blkid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blkid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blkid (device);
  if (r == NULL)
    /* do_blkid has already called reply_with_error */
    return;

  struct guestfs_blkid_ret ret;
  ret.info.info_len = count_strings (r);
  ret.info.info_val = r;
  reply ((xdrproc_t) &xdr_guestfs_blkid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_SETRA_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_setra_args)))

static void
cleanup_xdr_free_blockdev_setra_args (struct guestfs_blockdev_setra_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setra_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_SETRA_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_setra_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_SETRA_ARGS struct guestfs_blockdev_setra_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int sectors;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_setra_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  sectors = args.sectors;

  r = do_blockdev_setra (device, sectors);
  if (r == -1)
    /* do_blockdev_setra has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SCRUB_START_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_scrub_start_args)))

static void
cleanup_xdr_free_btrfs_scrub_start_args (struct guestfs_btrfs_scrub_start_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_start_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SCRUB_START_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_scrub_start_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SCRUB_START_ARGS struct guestfs_btrfs_scrub_start_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_scrub_start_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_scrub_start (path);
  if (r == -1)
    /* do_btrfs_scrub_start has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SCRUB_STATUS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_scrub_status_args)))

static void
cleanup_xdr_free_btrfs_scrub_status_args (struct guestfs_btrfs_scrub_status_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SCRUB_STATUS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_scrub_status_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_btrfsscrub *r = NULL;
  CLEANUP_XDR_FREE_BTRFS_SCRUB_STATUS_ARGS struct guestfs_btrfs_scrub_status_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_scrub_status_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_scrub_status (path);
  if (r == NULL)
    /* do_btrfs_scrub_status has already called reply_with_error */
    return;

  struct guestfs_btrfs_scrub_status_ret ret;
  ret.status = *r;
  reply ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_CREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_create_args)))

static void
cleanup_xdr_free_btrfs_subvolume_create_args (struct guestfs_btrfs_subvolume_create_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_create_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_CREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_create_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_CREATE_ARGS struct guestfs_btrfs_subvolume_create_args args;
  memset (&args, 0, sizeof args);
  const char *dest;
  const char *qgroupid;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_subvolume_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dest = args.dest;
  ABS_PATH (dest, false, return);
  qgroupid = args.qgroupid;

  NEED_ROOT (false, return);
  r = do_btrfs_subvolume_create (dest, qgroupid);
  if (r == -1)
    /* do_btrfs_subvolume_create has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SET_DEFAULT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_set_default_args)))

static void
cleanup_xdr_free_btrfs_subvolume_set_default_args (struct guestfs_btrfs_subvolume_set_default_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_set_default_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SET_DEFAULT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_set_default_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SET_DEFAULT_ARGS struct guestfs_btrfs_subvolume_set_default_args args;
  memset (&args, 0, sizeof args);
  int64_t id;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_subvolume_set_default_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  id = args.id;
  fs = args.fs;
  ABS_PATH (fs, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_subvolume_set_default (id, fs);
  if (r == -1)
    /* do_btrfs_subvolume_set_default has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SNAPSHOT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_snapshot_args)))

static void
cleanup_xdr_free_btrfs_subvolume_snapshot_args (struct guestfs_btrfs_subvolume_snapshot_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_snapshot_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SNAPSHOT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_snapshot_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SNAPSHOT_ARGS struct guestfs_btrfs_subvolume_snapshot_args args;
  memset (&args, 0, sizeof args);
  const char *source;
  const char *dest;
  int ro;
  const char *qgroupid;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_subvolume_snapshot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  source = args.source;
  ABS_PATH (source, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);
  ro = args.ro;
  qgroupid = args.qgroupid;

  NEED_ROOT (false, return);
  r = do_btrfs_subvolume_snapshot (source, dest, ro, qgroupid);
  if (r == -1)
    /* do_btrfs_subvolume_snapshot has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CASE_SENSITIVE_PATH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_case_sensitive_path_args)))

static void
cleanup_xdr_free_case_sensitive_path_args (struct guestfs_case_sensitive_path_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_case_sensitive_path_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CASE_SENSITIVE_PATH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
case_sensitive_path_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_CASE_SENSITIVE_PATH_ARGS struct guestfs_case_sensitive_path_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_case_sensitive_path_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_case_sensitive_path (path);
  if (r == NULL)
    /* do_case_sensitive_path has already called reply_with_error */
    return;

  struct guestfs_case_sensitive_path_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_case_sensitive_path_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_size_args)))

static void
cleanup_xdr_free_copy_size_args (struct guestfs_copy_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_size_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_SIZE_ARGS struct guestfs_copy_size_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_copy_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.src, src, false);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.dest, dest, false);
  size = args.size;

  r = do_copy_size (src, dest, size);
  if (r == -1)
    /* do_copy_size has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DEBUG_UPLOAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_debug_upload_args)))

static void
cleanup_xdr_free_debug_upload_args (struct guestfs_debug_upload_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_debug_upload_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DEBUG_UPLOAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
debug_upload_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DEBUG_UPLOAD_ARGS struct guestfs_debug_upload_args args;
  memset (&args, 0, sizeof args);
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_debug_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  tmpname = args.tmpname;
  mode = args.mode;

  r = do_debug_upload (tmpname, mode);
  if (r == -1)
    /* do_debug_upload has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DOWNLOAD_OFFSET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_download_offset_args)))

static void
cleanup_xdr_free_download_offset_args (struct guestfs_download_offset_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_download_offset_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DOWNLOAD_OFFSET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
download_offset_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DOWNLOAD_OFFSET_ARGS struct guestfs_download_offset_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_download_offset_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, false);
  offset = args.offset;
  size = args.size;

  r = do_download_offset (remotefilename, offset, size);
  if (r == -1)
    /* do_download_offset has already called reply_with_error */
    return;

  /* do_download_offset has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FINDFS_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_findfs_uuid_args)))

static void
cleanup_xdr_free_findfs_uuid_args (struct guestfs_findfs_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_findfs_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FINDFS_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
findfs_uuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_FINDFS_UUID_ARGS struct guestfs_findfs_uuid_args args;
  memset (&args, 0, sizeof args);
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_findfs_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  uuid = args.uuid;

  r = do_findfs_uuid (uuid);
  if (r == NULL)
    /* do_findfs_uuid has already called reply_with_error */
    return;

  struct guestfs_findfs_uuid_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_findfs_uuid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FSTRIM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fstrim_args)))

static void
cleanup_xdr_free_fstrim_args (struct guestfs_fstrim_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fstrim_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FSTRIM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fstrim_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FSTRIM_ARGS struct guestfs_fstrim_args args;
  memset (&args, 0, sizeof args);
  const char *mountpoint;
  int64_t offset;
  int64_t length;
  int64_t minimumfreeextent;

  /* The caller should have checked before calling this. */
  if (! optgroup_fstrim_available ()) {
    reply_with_unavailable_feature ("fstrim");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_fstrim_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, false, return);
  offset = args.offset;
  length = args.length;
  minimumfreeextent = args.minimumfreeextent;

  NEED_ROOT (false, return);
  r = do_fstrim (mountpoint, offset, length, minimumfreeextent);
  if (r == -1)
    /* do_fstrim has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GET_E2UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_get_e2uuid_args)))

static void
cleanup_xdr_free_get_e2uuid_args (struct guestfs_get_e2uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GET_E2UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
get_e2uuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_GET_E2UUID_ARGS struct guestfs_get_e2uuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_get_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_get_e2uuid (device);
  if (r == NULL)
    /* do_get_e2uuid has already called reply_with_error */
    return;

  struct guestfs_get_e2uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2uuid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_grepi_args)))

static void
cleanup_xdr_free_grepi_args (struct guestfs_grepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_grepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
grepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_GREPI_ARGS struct guestfs_grepi_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_grepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_grepi (regex, path);
  if (r == NULL)
    /* do_grepi has already called reply_with_error */
    return;

  struct guestfs_grepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grepi_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HEXDUMP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hexdump_args)))

static void
cleanup_xdr_free_hexdump_args (struct guestfs_hexdump_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hexdump_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HEXDUMP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hexdump_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_HEXDUMP_ARGS struct guestfs_hexdump_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hexdump_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_hexdump (path);
  if (r == NULL)
    /* do_hexdump has already called reply_with_error */
    return;

  struct guestfs_hexdump_ret ret;
  ret.dump = r;
  reply ((xdrproc_t) &xdr_guestfs_hexdump_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_CHILDREN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_children_args)))

static void
cleanup_xdr_free_hivex_node_children_args (struct guestfs_hivex_node_children_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_children_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_CHILDREN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_children_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_hivex_node_list *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_NODE_CHILDREN_ARGS struct guestfs_hivex_node_children_args args;
  memset (&args, 0, sizeof args);
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_node_children_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_children (nodeh);
  if (r == NULL)
    /* do_hivex_node_children has already called reply_with_error */
    return;

  struct guestfs_hivex_node_children_ret ret;
  ret.nodehs = *r;
  reply ((xdrproc_t) xdr_guestfs_hivex_node_children_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_children_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_hot_remove_drive_args)))

static void
cleanup_xdr_free_internal_hot_remove_drive_args (struct guestfs_internal_hot_remove_drive_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_remove_drive_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_hot_remove_drive_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_ARGS struct guestfs_internal_hot_remove_drive_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_hot_remove_drive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_internal_hot_remove_drive (label);
  if (r == -1)
    /* do_internal_hot_remove_drive has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_LSTATNSLIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_lstatnslist_args)))

static void
cleanup_xdr_free_internal_lstatnslist_args (struct guestfs_internal_lstatnslist_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lstatnslist_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_LSTATNSLIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_lstatnslist_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_statns_list *r = NULL;
  CLEANUP_XDR_FREE_INTERNAL_LSTATNSLIST_ARGS struct guestfs_internal_lstatnslist_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_lstatnslist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  {
    size_t i;
    for (i = 0; i < args.names.names_len; ++i) {
      if (strchr (args.names.names_val[i], '/') != NULL) {
        reply_with_error ("%s: '%s' is not a file name", __func__, args.names.names_val[i]);
        return;
      }
    }
  }
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (false, return);
  r = do_internal_lstatnslist (path, names);
  if (r == NULL)
    /* do_internal_lstatnslist has already called reply_with_error */
    return;

  struct guestfs_internal_lstatnslist_ret ret;
  ret.statbufs = *r;
  reply ((xdrproc_t) xdr_guestfs_internal_lstatnslist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lstatnslist_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_LXATTRLIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_lxattrlist_args)))

static void
cleanup_xdr_free_internal_lxattrlist_args (struct guestfs_internal_lxattrlist_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lxattrlist_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_LXATTRLIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_lxattrlist_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_xattr_list *r = NULL;
  CLEANUP_XDR_FREE_INTERNAL_LXATTRLIST_ARGS struct guestfs_internal_lxattrlist_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  char **names;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_lxattrlist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  {
    size_t i;
    for (i = 0; i < args.names.names_len; ++i) {
      if (strchr (args.names.names_val[i], '/') != NULL) {
        reply_with_error ("%s: '%s' is not a file name", __func__, args.names.names_val[i]);
        return;
      }
    }
  }
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (false, return);
  r = do_internal_lxattrlist (path, names);
  if (r == NULL)
    /* do_internal_lxattrlist has already called reply_with_error */
    return;

  struct guestfs_internal_lxattrlist_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_internal_lxattrlist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lxattrlist_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_RHBZ914931_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_rhbz914931_args)))

static void
cleanup_xdr_free_internal_rhbz914931_args (struct guestfs_internal_rhbz914931_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_rhbz914931_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_RHBZ914931_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_rhbz914931_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_RHBZ914931_ARGS struct guestfs_internal_rhbz914931_args args;
  memset (&args, 0, sizeof args);
  int count;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_rhbz914931_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  count = args.count;

  r = do_internal_rhbz914931 (count);
  if (r == -1)
    /* do_internal_rhbz914931 has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
ldmtool_scan_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_ldmtool_scan ();
  if (r == NULL)
    /* do_ldmtool_scan has already called reply_with_error */
    return;

  struct guestfs_ldmtool_scan_ret ret;
  ret.guids.guids_len = count_strings (r);
  ret.guids.guids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_scan_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LGETXATTRS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lgetxattrs_args)))

static void
cleanup_xdr_free_lgetxattrs_args (struct guestfs_lgetxattrs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LGETXATTRS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lgetxattrs_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_xattr_list *r = NULL;
  CLEANUP_XDR_FREE_LGETXATTRS_ARGS struct guestfs_lgetxattrs_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lgetxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_lgetxattrs (path);
  if (r == NULL)
    /* do_lgetxattrs has already called reply_with_error */
    return;

  struct guestfs_lgetxattrs_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
}

void
list_dm_devices_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_dm_devices ();
  if (r == NULL)
    /* do_list_dm_devices has already called reply_with_error */
    return;

  struct guestfs_list_dm_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_dm_devices_ret, (char *) &ret);
}

void
list_ldm_volumes_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_ldm_volumes ();
  if (r == NULL)
    /* do_list_ldm_volumes has already called reply_with_error */
    return;

  struct guestfs_list_ldm_volumes_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_ldm_volumes_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_FORMAT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_format_args)))

static void
cleanup_xdr_free_luks_format_args (struct guestfs_luks_format_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_format_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_FORMAT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_format_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_FORMAT_ARGS struct guestfs_luks_format_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_luks_format_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  keyslot = args.keyslot;

  r = do_luks_format (device, key, keyslot);
  if (r == -1)
    /* do_luks_format has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVM_CANONICAL_LV_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvm_canonical_lv_name_args)))

static void
cleanup_xdr_free_lvm_canonical_lv_name_args (struct guestfs_lvm_canonical_lv_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvm_canonical_lv_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVM_CANONICAL_LV_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvm_canonical_lv_name_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LVM_CANONICAL_LV_NAME_ARGS struct guestfs_lvm_canonical_lv_name_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *lvname = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvm_canonical_lv_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.lvname, lvname, false);

  r = do_lvm_canonical_lv_name (lvname);
  if (r == NULL)
    /* do_lvm_canonical_lv_name has already called reply_with_error */
    return;

  struct guestfs_lvm_canonical_lv_name_ret ret;
  ret.lv = r;
  reply ((xdrproc_t) &xdr_guestfs_lvm_canonical_lv_name_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVRENAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvrename_args)))

static void
cleanup_xdr_free_lvrename_args (struct guestfs_lvrename_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvrename_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVRENAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvrename_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVRENAME_ARGS struct guestfs_lvrename_args args;
  memset (&args, 0, sizeof args);
  const char *logvol;
  const char *newlogvol;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  logvol = args.logvol;
  newlogvol = args.newlogvol;

  r = do_lvrename (logvol, newlogvol);
  if (r == -1)
    /* do_lvrename has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVRESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvresize_args)))

static void
cleanup_xdr_free_lvresize_args (struct guestfs_lvresize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVRESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvresize_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVRESIZE_ARGS struct guestfs_lvresize_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  mbytes = args.mbytes;

  r = do_lvresize (device, mbytes);
  if (r == -1)
    /* do_lvresize has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVUUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvuuid_args)))

static void
cleanup_xdr_free_lvuuid_args (struct guestfs_lvuuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvuuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVUUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvuuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LVUUID_ARGS struct guestfs_lvuuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvuuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_lvuuid (device);
  if (r == NULL)
    /* do_lvuuid has already called reply_with_error */
    return;

  struct guestfs_lvuuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_lvuuid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2FS_J_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2fs_J_args)))

static void
cleanup_xdr_free_mke2fs_J_args (struct guestfs_mke2fs_J_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_J_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2FS_J_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2fs_J_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2FS_J_ARGS struct guestfs_mke2fs_J_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  CLEANUP_FREE char *journal = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2fs_J_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, false);
  RESOLVE_DEVICE (args.journal, journal, false);

  r = do_mke2fs_J (fstype, blocksize, device, journal);
  if (r == -1)
    /* do_mke2fs_J has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2JOURNAL_U_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2journal_U_args)))

static void
cleanup_xdr_free_mke2journal_U_args (struct guestfs_mke2journal_U_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_U_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2JOURNAL_U_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2journal_U_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2JOURNAL_U_ARGS struct guestfs_mke2journal_U_args args;
  memset (&args, 0, sizeof args);
  int blocksize;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2journal_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  uuid = args.uuid;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mke2journal_U (blocksize, uuid, device);
  if (r == -1)
    /* do_mke2journal_U has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKNOD_C_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mknod_c_args)))

static void
cleanup_xdr_free_mknod_c_args (struct guestfs_mknod_c_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_c_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKNOD_C_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mknod_c_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKNOD_C_ARGS struct guestfs_mknod_c_args args;
  memset (&args, 0, sizeof args);
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mknod_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mknod_c (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_c has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_OPTIONS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_options_args)))

static void
cleanup_xdr_free_mount_options_args (struct guestfs_mount_options_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_options_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_OPTIONS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_options_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_OPTIONS_ARGS struct guestfs_mount_options_args args;
  memset (&args, 0, sizeof args);
  const char *options;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mount_options_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  options = args.options;
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);
  mountpoint = args.mountpoint;

  r = do_mount_options (options, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_options has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSFIX_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfsfix_args)))

static void
cleanup_xdr_free_ntfsfix_args (struct guestfs_ntfsfix_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsfix_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSFIX_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfsfix_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSFIX_ARGS struct guestfs_ntfsfix_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int clearbadsectors;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_ntfsfix_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  clearbadsectors = args.clearbadsectors;

  r = do_ntfsfix (device, clearbadsectors);
  if (r == -1)
    /* do_ntfsfix has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_ADD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_add_args)))

static void
cleanup_xdr_free_part_add_args (struct guestfs_part_add_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_add_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_ADD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_add_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_ADD_ARGS struct guestfs_part_add_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_add_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  prlogex = args.prlogex;
  startsect = args.startsect;
  endsect = args.endsect;

  r = do_part_add (device, prlogex, startsect, endsect);
  if (r == -1)
    /* do_part_add has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_GPT_GUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_gpt_guid_args)))

static void
cleanup_xdr_free_part_get_gpt_guid_args (struct guestfs_part_get_gpt_guid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_gpt_guid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_GPT_GUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_gpt_guid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_GPT_GUID_ARGS struct guestfs_part_get_gpt_guid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_gpt_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_gpt_guid (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_guid has already called reply_with_error */
    return;

  struct guestfs_part_get_gpt_guid_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_gpt_guid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_MBR_ID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_mbr_id_args)))

static void
cleanup_xdr_free_part_get_mbr_id_args (struct guestfs_part_get_mbr_id_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_mbr_id_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_MBR_ID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_mbr_id_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_GET_MBR_ID_ARGS struct guestfs_part_get_mbr_id_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_mbr_id_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_mbr_id (device, partnum);
  if (r == -1)
    /* do_part_get_mbr_id has already called reply_with_error */
    return;

  struct guestfs_part_get_mbr_id_ret ret;
  ret.idbyte = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_mbr_id_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_MBR_PART_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_mbr_part_type_args)))

static void
cleanup_xdr_free_part_get_mbr_part_type_args (struct guestfs_part_get_mbr_part_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_mbr_part_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_MBR_PART_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_mbr_part_type_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_MBR_PART_TYPE_ARGS struct guestfs_part_get_mbr_part_type_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_mbr_part_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_mbr_part_type (device, partnum);
  if (r == NULL)
    /* do_part_get_mbr_part_type has already called reply_with_error */
    return;

  struct guestfs_part_get_mbr_part_type_ret ret;
  ret.partitiontype = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_mbr_part_type_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_name_args)))

static void
cleanup_xdr_free_part_get_name_args (struct guestfs_part_get_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_name_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_NAME_ARGS struct guestfs_part_get_name_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_name (device, partnum);
  if (r == NULL)
    /* do_part_get_name has already called reply_with_error */
    return;

  struct guestfs_part_get_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_name_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_INIT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_init_args)))

static void
cleanup_xdr_free_part_init_args (struct guestfs_part_init_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_init_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_INIT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_init_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_INIT_ARGS struct guestfs_part_init_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  parttype = args.parttype;

  r = do_part_init (device, parttype);
  if (r == -1)
    /* do_part_init has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_TO_PARTNUM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_to_partnum_args)))

static void
cleanup_xdr_free_part_to_partnum_args (struct guestfs_part_to_partnum_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_to_partnum_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_TO_PARTNUM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_to_partnum_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_TO_PARTNUM_ARGS struct guestfs_part_to_partnum_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_to_partnum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.partition, partition, false);

  r = do_part_to_partnum (partition);
  if (r == -1)
    /* do_part_to_partnum has already called reply_with_error */
    return;

  struct guestfs_part_to_partnum_ret ret;
  ret.partnum = r;
  reply ((xdrproc_t) &xdr_guestfs_part_to_partnum_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVUUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvuuid_args)))

static void
cleanup_xdr_free_pvuuid_args (struct guestfs_pvuuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvuuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVUUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvuuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PVUUID_ARGS struct guestfs_pvuuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pvuuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_pvuuid (device);
  if (r == NULL)
    /* do_pvuuid has already called reply_with_error */
    return;

  struct guestfs_pvuuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_pvuuid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RMMOUNTPOINT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rmmountpoint_args)))

static void
cleanup_xdr_free_rmmountpoint_args (struct guestfs_rmmountpoint_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rmmountpoint_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RMMOUNTPOINT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rmmountpoint_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RMMOUNTPOINT_ARGS struct guestfs_rmmountpoint_args args;
  memset (&args, 0, sizeof args);
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rmmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  exemptpath = args.exemptpath;

  r = do_rmmountpoint (exemptpath);
  if (r == -1)
    /* do_rmmountpoint has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SCRUB_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_scrub_device_args)))

static void
cleanup_xdr_free_scrub_device_args (struct guestfs_scrub_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SCRUB_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
scrub_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SCRUB_DEVICE_ARGS struct guestfs_scrub_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_scrub_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_scrub_device (device);
  if (r == -1)
    /* do_scrub_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_E2ATTRS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_e2attrs_args)))

static void
cleanup_xdr_free_set_e2attrs_args (struct guestfs_set_e2attrs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2attrs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_E2ATTRS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_e2attrs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_E2ATTRS_ARGS struct guestfs_set_e2attrs_args args;
  memset (&args, 0, sizeof args);
  const char *file;
  const char *attrs;
  int clear;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_set_e2attrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);
  attrs = args.attrs;
  clear = args.clear;

  NEED_ROOT (false, return);
  r = do_set_e2attrs (file, attrs, clear);
  if (r == -1)
    /* do_set_e2attrs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_E2LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_e2label_args)))

static void
cleanup_xdr_free_set_e2label_args (struct guestfs_set_e2label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_E2LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_e2label_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_E2LABEL_ARGS struct guestfs_set_e2label_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  label = args.label;

  r = do_set_e2label (device, label);
  if (r == -1)
    /* do_set_e2label has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SH_LINES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sh_lines_args)))

static void
cleanup_xdr_free_sh_lines_args (struct guestfs_sh_lines_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sh_lines_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SH_LINES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sh_lines_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_SH_LINES_ARGS struct guestfs_sh_lines_args args;
  memset (&args, 0, sizeof args);
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sh_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  command = args.command;

  r = do_sh_lines (command);
  if (r == NULL)
    /* do_sh_lines has already called reply_with_error */
    return;

  struct guestfs_sh_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_lines_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPON_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapon_file_args)))

static void
cleanup_xdr_free_swapon_file_args (struct guestfs_swapon_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPON_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapon_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPON_FILE_ARGS struct guestfs_swapon_file_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapon_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_swapon_file (file);
  if (r == -1)
    /* do_swapon_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TGZ_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tgz_out_args)))

static void
cleanup_xdr_free_tgz_out_args (struct guestfs_tgz_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TGZ_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tgz_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TGZ_OUT_ARGS struct guestfs_tgz_out_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_tgz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_tgz_out (directory);
  if (r == -1)
    /* do_tgz_out has already called reply_with_error */
    return;

  /* do_tgz_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_UMASK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_umask_args)))

static void
cleanup_xdr_free_umask_args (struct guestfs_umask_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_umask_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_UMASK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
umask_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_UMASK_ARGS struct guestfs_umask_args args;
  memset (&args, 0, sizeof args);
  int mask;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_umask_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mask = args.mask;

  r = do_umask (mask);
  if (r == -1)
    /* do_umask has already called reply_with_error */
    return;

  struct guestfs_umask_ret ret;
  ret.oldmask = r;
  reply ((xdrproc_t) &xdr_guestfs_umask_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_WIPEFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_wipefs_args)))

static void
cleanup_xdr_free_wipefs_args (struct guestfs_wipefs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_wipefs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_WIPEFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
wipefs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_WIPEFS_ARGS struct guestfs_wipefs_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_wipefs_available ()) {
    reply_with_unavailable_feature ("wipefs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_wipefs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_wipefs (device);
  if (r == -1)
    /* do_wipefs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

