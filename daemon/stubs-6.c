/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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

#define CLEANUP_XDR_FREE_AUG_MV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_mv_args)))

static void
cleanup_xdr_free_aug_mv_args (struct guestfs_aug_mv_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_mv_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_MV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_mv_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_MV_ARGS struct guestfs_aug_mv_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  dest = args.dest;

  r = do_aug_mv (src, dest);
  if (r == -1)
    /* do_aug_mv has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
available_all_groups_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_available_all_groups ();
  if (r == NULL)
    /* do_available_all_groups has already called reply_with_error */
    return;

  struct guestfs_available_all_groups_ret ret;
  ret.groups.groups_len = guestfs_int_count_strings (r);
  ret.groups.groups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_available_all_groups_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_GETBSZ_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_getbsz_args)))

static void
cleanup_xdr_free_blockdev_getbsz_args (struct guestfs_blockdev_getbsz_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_GETBSZ_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_getbsz_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_GETBSZ_ARGS struct guestfs_blockdev_getbsz_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_getbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_getbsz (device);
  if (r == -1)
    /* do_blockdev_getbsz has already called reply_with_error */
    return;

  struct guestfs_blockdev_getbsz_ret ret;
  ret.blocksize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_GETRO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_getro_args)))

static void
cleanup_xdr_free_blockdev_getro_args (struct guestfs_blockdev_getro_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_GETRO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_getro_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_GETRO_ARGS struct guestfs_blockdev_getro_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_getro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_getro (device);
  if (r == -1)
    /* do_blockdev_getro has already called reply_with_error */
    return;

  struct guestfs_blockdev_getro_ret ret;
  ret.ro = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getro_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_SETBSZ_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_setbsz_args)))

static void
cleanup_xdr_free_blockdev_setbsz_args (struct guestfs_blockdev_setbsz_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_SETBSZ_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_setbsz_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_SETBSZ_ARGS struct guestfs_blockdev_setbsz_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int blocksize;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_setbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  blocksize = args.blocksize;

  r = do_blockdev_setbsz (device, blocksize);
  if (r == -1)
    /* do_blockdev_setbsz has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_REMOVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_remove_args)))

static void
cleanup_xdr_free_btrfs_qgroup_remove_args (struct guestfs_btrfs_qgroup_remove_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_remove_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_REMOVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_remove_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_REMOVE_ARGS struct guestfs_btrfs_qgroup_remove_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dst;
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

  if (!xdr_guestfs_btrfs_qgroup_remove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_remove (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_remove has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QUOTA_ENABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_quota_enable_args)))

static void
cleanup_xdr_free_btrfs_quota_enable_args (struct guestfs_btrfs_quota_enable_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_enable_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QUOTA_ENABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_quota_enable_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QUOTA_ENABLE_ARGS struct guestfs_btrfs_quota_enable_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };
  int enable;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_quota_enable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, false);
  enable = args.enable;

  r = do_btrfs_quota_enable (&fs, enable);
  if (r == -1)
    /* do_btrfs_quota_enable has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CHECKSUMS_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_checksums_out_args)))

static void
cleanup_xdr_free_checksums_out_args (struct guestfs_checksums_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_checksums_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CHECKSUMS_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
checksums_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CHECKSUMS_OUT_ARGS struct guestfs_checksums_out_args args;
  memset (&args, 0, sizeof args);
  const char *csumtype;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_checksums_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  csumtype = args.csumtype;
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_checksums_out (csumtype, directory);
  if (r == -1)
    /* do_checksums_out has already called reply_with_error */
    return;

  /* do_checksums_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CP_A_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cp_a_args)))

static void
cleanup_xdr_free_cp_a_args (struct guestfs_cp_a_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cp_a_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CP_A_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cp_a_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CP_A_ARGS struct guestfs_cp_a_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_cp_a_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);

  NEED_ROOT (false, return);
  r = do_cp_a (src, dest);
  if (r == -1)
    /* do_cp_a has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
df_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_df ();
  if (r == NULL)
    /* do_df has already called reply_with_error */
    return;

  struct guestfs_df_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_EGREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_egrepi_args)))

static void
cleanup_xdr_free_egrepi_args (struct guestfs_egrepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_egrepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_EGREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
egrepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_EGREPI_ARGS struct guestfs_egrepi_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_egrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_egrepi (regex, path);
  if (r == NULL)
    /* do_egrepi has already called reply_with_error */
    return;

  struct guestfs_egrepi_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrepi_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FALLOCATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fallocate_args)))

static void
cleanup_xdr_free_fallocate_args (struct guestfs_fallocate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FALLOCATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fallocate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FALLOCATE_ARGS struct guestfs_fallocate_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fallocate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  len = args.len;

  NEED_ROOT (false, return);
  r = do_fallocate (path, len);
  if (r == -1)
    /* do_fallocate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FALLOCATE64_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fallocate64_args)))

static void
cleanup_xdr_free_fallocate64_args (struct guestfs_fallocate64_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate64_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FALLOCATE64_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fallocate64_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FALLOCATE64_ARGS struct guestfs_fallocate64_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int64_t len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fallocate64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  len = args.len;

  NEED_ROOT (false, return);
  r = do_fallocate64 (path, len);
  if (r == -1)
    /* do_fallocate64 has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FGREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fgrep_args)))

static void
cleanup_xdr_free_fgrep_args (struct guestfs_fgrep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fgrep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FGREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fgrep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_FGREP_ARGS struct guestfs_fgrep_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_fgrep (pattern, path);
  if (r == NULL)
    /* do_fgrep has already called reply_with_error */
    return;

  struct guestfs_fgrep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrep_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_file_args)))

static void
cleanup_xdr_free_file_args (struct guestfs_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
file_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_FILE_ARGS struct guestfs_file_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *path = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.path, path, false);

  r = do_file (path);
  if (r == NULL)
    /* do_file has already called reply_with_error */
    return;

  struct guestfs_file_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_file_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_filesize_args)))

static void
cleanup_xdr_free_filesize_args (struct guestfs_filesize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_filesize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
filesize_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_FILESIZE_ARGS struct guestfs_filesize_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_filesize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_filesize (file);
  if (r == -1)
    /* do_filesize has already called reply_with_error */
    return;

  struct guestfs_filesize_ret ret;
  ret.size = r;
  reply ((xdrproc_t) &xdr_guestfs_filesize_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILESYSTEM_AVAILABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_filesystem_available_args)))

static void
cleanup_xdr_free_filesystem_available_args (struct guestfs_filesystem_available_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_filesystem_available_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILESYSTEM_AVAILABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
filesystem_available_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FILESYSTEM_AVAILABLE_ARGS struct guestfs_filesystem_available_args args;
  memset (&args, 0, sizeof args);
  const char *filesystem;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_filesystem_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filesystem = args.filesystem;

  r = do_filesystem_available (filesystem);
  if (r == -1)
    /* do_filesystem_available has already called reply_with_error */
    return;

  struct guestfs_filesystem_available_ret ret;
  ret.fsavail = r;
  reply ((xdrproc_t) &xdr_guestfs_filesystem_available_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fill_args)))

static void
cleanup_xdr_free_fill_args (struct guestfs_fill_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fill_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fill_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FILL_ARGS struct guestfs_fill_args args;
  memset (&args, 0, sizeof args);
  int c;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fill_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  c = args.c;
  len = args.len;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_fill (c, len, path);
  if (r == -1)
    /* do_fill has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HEAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_head_args)))

static void
cleanup_xdr_free_head_args (struct guestfs_head_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_head_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HEAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
head_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_HEAD_ARGS struct guestfs_head_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_head_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_head (path);
  if (r == NULL)
    /* do_head has already called reply_with_error */
    return;

  struct guestfs_head_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_name_args)))

static void
cleanup_xdr_free_hivex_node_name_args (struct guestfs_hivex_node_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_name_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_NODE_NAME_ARGS struct guestfs_hivex_node_name_args args;
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

  if (!xdr_guestfs_hivex_node_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_name (nodeh);
  if (r == NULL)
    /* do_hivex_node_name has already called reply_with_error */
    return;

  struct guestfs_hivex_node_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_name_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_VALUES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_values_args)))

static void
cleanup_xdr_free_hivex_node_values_args (struct guestfs_hivex_node_values_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_VALUES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_values_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_hivex_value_list *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_NODE_VALUES_ARGS struct guestfs_hivex_node_values_args args;
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

  if (!xdr_guestfs_hivex_node_values_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_values (nodeh);
  if (r == NULL)
    /* do_hivex_node_values has already called reply_with_error */
    return;

  struct guestfs_hivex_node_values_ret ret;
  ret.valuehs = *r;
  reply ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
}

void
inotify_read_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_inotify_event_list *r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_inotify_read ();
  if (r == NULL)
    /* do_inotify_read has already called reply_with_error */
    return;

  struct guestfs_inotify_read_ret ret;
  ret.events = *r;
  reply ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_MOUNTPOINTS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_mountpoints_args)))

static void
cleanup_xdr_free_inspect_get_mountpoints_args (struct guestfs_inspect_get_mountpoints_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_mountpoints_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_MOUNTPOINTS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_mountpoints_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_MOUNTPOINTS_ARGS struct guestfs_inspect_get_mountpoints_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_mountpoints_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_mountpoints (&root);
  if (r == NULL)
    /* do_inspect_get_mountpoints has already called reply_with_error */
    return;

  struct guestfs_inspect_get_mountpoints_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; i += 2) {
    char *rr = reverse_device_name_translation (r[i+1]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i+1]);
    r[i+1] = rr;
  }
  ret.mountpoints.mountpoints_len = guestfs_int_count_strings (r);
  ret.mountpoints.mountpoints_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_mountpoints_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_PACKAGE_MANAGEMENT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_package_management_args)))

static void
cleanup_xdr_free_inspect_get_package_management_args (struct guestfs_inspect_get_package_management_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_package_management_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_PACKAGE_MANAGEMENT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_package_management_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_PACKAGE_MANAGEMENT_ARGS struct guestfs_inspect_get_package_management_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_package_management_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_package_management (&root);
  if (r == NULL)
    /* do_inspect_get_package_management has already called reply_with_error */
    return;

  struct guestfs_inspect_get_package_management_ret ret;
  ret.packagemanagement = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_package_management_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_PRODUCT_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_product_name_args)))

static void
cleanup_xdr_free_inspect_get_product_name_args (struct guestfs_inspect_get_product_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_product_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_PRODUCT_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_product_name_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_PRODUCT_NAME_ARGS struct guestfs_inspect_get_product_name_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_product_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_product_name (&root);
  if (r == NULL)
    /* do_inspect_get_product_name has already called reply_with_error */
    return;

  struct guestfs_inspect_get_product_name_ret ret;
  ret.product = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_product_name_ret, (char *) &ret);
}

void
internal_autosync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_internal_autosync ();
  if (r == -1)
    /* do_internal_autosync has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_FEATURE_AVAILABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_feature_available_args)))

static void
cleanup_xdr_free_internal_feature_available_args (struct guestfs_internal_feature_available_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_feature_available_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_FEATURE_AVAILABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_feature_available_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_FEATURE_AVAILABLE_ARGS struct guestfs_internal_feature_available_args args;
  memset (&args, 0, sizeof args);
  const char *group;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_feature_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  group = args.group;

  r = do_internal_feature_available (group);
  if (r == -1)
    /* do_internal_feature_available has already called reply_with_error */
    return;

  struct guestfs_internal_feature_available_ret ret;
  ret.result = r;
  reply ((xdrproc_t) &xdr_guestfs_internal_feature_available_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_PARSE_MOUNTABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_parse_mountable_args)))

static void
cleanup_xdr_free_internal_parse_mountable_args (struct guestfs_internal_parse_mountable_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_PARSE_MOUNTABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_parse_mountable_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_internal_mountable *r = NULL;
  CLEANUP_XDR_FREE_INTERNAL_PARSE_MOUNTABLE_ARGS struct guestfs_internal_parse_mountable_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_parse_mountable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_internal_parse_mountable (&mountable);
  if (r == NULL)
    /* do_internal_parse_mountable has already called reply_with_error */
    return;

  struct guestfs_internal_parse_mountable_ret ret;
  ret.mountable = *r;
  reply ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_READLINKLIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_readlinklist_args)))

static void
cleanup_xdr_free_internal_readlinklist_args (struct guestfs_internal_readlinklist_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_readlinklist_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_READLINKLIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_readlinklist_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_INTERNAL_READLINKLIST_ARGS struct guestfs_internal_readlinklist_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_readlinklist_args (xdr_in, &args)) {
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
  r = do_internal_readlinklist (path, names);
  if (r == NULL)
    /* do_internal_readlinklist has already called reply_with_error */
    return;

  struct guestfs_internal_readlinklist_ret ret;
  ret.links.links_len = guestfs_int_count_strings (r);
  ret.links.links_val = r;
  reply ((xdrproc_t) &xdr_guestfs_internal_readlinklist_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ISOINFO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_isoinfo_args)))

static void
cleanup_xdr_free_isoinfo_args (struct guestfs_isoinfo_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ISOINFO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
isoinfo_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_isoinfo *r = NULL;
  CLEANUP_XDR_FREE_ISOINFO_ARGS struct guestfs_isoinfo_args args;
  memset (&args, 0, sizeof args);
  const char *isofile;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_isoinfo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  isofile = args.isofile;
  ABS_PATH (isofile, false, return);

  NEED_ROOT (false, return);
  r = do_isoinfo (isofile);
  if (r == NULL)
    /* do_isoinfo has already called reply_with_error */
    return;

  struct guestfs_isoinfo_ret ret;
  ret.isodata = *r;
  reply ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
}

void
journal_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_journal_close ();
  if (r == -1)
    /* do_journal_close has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LGETXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lgetxattr_args)))

static void
cleanup_xdr_free_lgetxattr_args (struct guestfs_lgetxattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LGETXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lgetxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LGETXATTR_ARGS struct guestfs_lgetxattr_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lgetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  name = args.name;

  NEED_ROOT (false, return);
  r = do_lgetxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_lgetxattr has already called reply_with_error */
    return;

  struct guestfs_lgetxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_lgetxattr_ret, (char *) &ret);
}

void
list_9p_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_9p ();
  if (r == NULL)
    /* do_list_9p has already called reply_with_error */
    return;

  struct guestfs_list_9p_ret ret;
  ret.mounttags.mounttags_len = guestfs_int_count_strings (r);
  ret.mounttags.mounttags_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_9p_ret, (char *) &ret);
}

void
list_ldm_partitions_stub (XDR *xdr_in)
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

  r = do_list_ldm_partitions ();
  if (r == NULL)
    /* do_list_ldm_partitions has already called reply_with_error */
    return;

  struct guestfs_list_ldm_partitions_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; ++i) {
    char *rr = reverse_device_name_translation (r[i]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i]);
    r[i] = rr;
  }
  ret.devices.devices_len = guestfs_int_count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_ldm_partitions_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_FORMAT_CIPHER_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_format_cipher_args)))

static void
cleanup_xdr_free_luks_format_cipher_args (struct guestfs_luks_format_cipher_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_format_cipher_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_FORMAT_CIPHER_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_format_cipher_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_FORMAT_CIPHER_ARGS struct guestfs_luks_format_cipher_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;
  const char *cipher;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_luks_format_cipher_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  keyslot = args.keyslot;
  cipher = args.cipher;

  r = do_luks_format_cipher (device, key, keyslot, cipher);
  if (r == -1)
    /* do_luks_format_cipher has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
lvm_clear_filter_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_lvm_clear_filter ();
  if (r == -1)
    /* do_lvm_clear_filter has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
lvs_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_lvs ();
  if (r == NULL)
    /* do_lvs has already called reply_with_error */
    return;

  struct guestfs_lvs_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; ++i) {
    char *rr = reverse_device_name_translation (r[i]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i]);
    r[i] = rr;
  }
  ret.logvols.logvols_len = guestfs_int_count_strings (r);
  ret.logvols.logvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_lvs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MD_DETAIL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_md_detail_args)))

static void
cleanup_xdr_free_md_detail_args (struct guestfs_md_detail_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_md_detail_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MD_DETAIL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
md_detail_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_MD_DETAIL_ARGS struct guestfs_md_detail_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_md_detail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.md, md, false);

  r = do_md_detail (md);
  if (r == NULL)
    /* do_md_detail has already called reply_with_error */
    return;

  struct guestfs_md_detail_ret ret;
  ret.info.info_len = guestfs_int_count_strings (r);
  ret.info.info_val = r;
  reply ((xdrproc_t) &xdr_guestfs_md_detail_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2JOURNAL_L_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2journal_L_args)))

static void
cleanup_xdr_free_mke2journal_L_args (struct guestfs_mke2journal_L_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2JOURNAL_L_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2journal_L_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2JOURNAL_L_ARGS struct guestfs_mke2journal_L_args args;
  memset (&args, 0, sizeof args);
  int blocksize;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2journal_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  label = args.label;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mke2journal_L (blocksize, label, device);
  if (r == -1)
    /* do_mke2journal_L has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKSWAP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkswap_args)))

static void
cleanup_xdr_free_mkswap_args (struct guestfs_mkswap_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKSWAP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkswap_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKSWAP_ARGS struct guestfs_mkswap_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *label;
  const char *uuid;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mkswap_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  label = args.label;
  uuid = args.uuid;

  r = do_mkswap (device, label, uuid);
  if (r == -1)
    /* do_mkswap has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKSWAP_L_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkswap_L_args)))

static void
cleanup_xdr_free_mkswap_L_args (struct guestfs_mkswap_L_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKSWAP_L_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkswap_L_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKSWAP_L_ARGS struct guestfs_mkswap_L_args args;
  memset (&args, 0, sizeof args);
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkswap_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mkswap_L (label, device);
  if (r == -1)
    /* do_mkswap_L has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKTEMP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mktemp_args)))

static void
cleanup_xdr_free_mktemp_args (struct guestfs_mktemp_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mktemp_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKTEMP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mktemp_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_MKTEMP_ARGS struct guestfs_mktemp_args args;
  memset (&args, 0, sizeof args);
  const char *tmpl;
  const char *suffix;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mktemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, false, return);
  suffix = args.suffix;

  NEED_ROOT (false, return);
  r = do_mktemp (tmpl, suffix);
  if (r == NULL)
    /* do_mktemp has already called reply_with_error */
    return;

  struct guestfs_mktemp_ret ret;
  ret.path = r;
  reply ((xdrproc_t) &xdr_guestfs_mktemp_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_LOOP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_loop_args)))

static void
cleanup_xdr_free_mount_loop_args (struct guestfs_mount_loop_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_loop_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_LOOP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_loop_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_LOOP_ARGS struct guestfs_mount_loop_args args;
  memset (&args, 0, sizeof args);
  const char *file;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mount_loop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, false, return);

  NEED_ROOT (false, return);
  r = do_mount_loop (file, mountpoint);
  if (r == -1)
    /* do_mount_loop has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_VFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_vfs_args)))

static void
cleanup_xdr_free_mount_vfs_args (struct guestfs_mount_vfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_VFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_vfs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_VFS_ARGS struct guestfs_mount_vfs_args args;
  memset (&args, 0, sizeof args);
  const char *options;
  const char *vfstype;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mount_vfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  options = args.options;
  vfstype = args.vfstype;
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);
  mountpoint = args.mountpoint;

  r = do_mount_vfs (options, vfstype, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_vfs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_MBR_ID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_mbr_id_args)))

static void
cleanup_xdr_free_part_set_mbr_id_args (struct guestfs_part_set_mbr_id_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_mbr_id_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_MBR_ID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_mbr_id_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_MBR_ID_ARGS struct guestfs_part_set_mbr_id_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int idbyte;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_set_mbr_id_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  idbyte = args.idbyte;

  r = do_part_set_mbr_id (device, partnum, idbyte);
  if (r == -1)
    /* do_part_set_mbr_id has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PREAD_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pread_device_args)))

static void
cleanup_xdr_free_pread_device_args (struct guestfs_pread_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pread_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PREAD_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pread_device_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PREAD_DEVICE_ARGS struct guestfs_pread_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pread_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  count = args.count;
  offset = args.offset;

  r = do_pread_device (device, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread_device has already called reply_with_error */
    return;

  struct guestfs_pread_device_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_device_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVCHANGE_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvchange_uuid_args)))

static void
cleanup_xdr_free_pvchange_uuid_args (struct guestfs_pvchange_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvchange_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVCHANGE_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvchange_uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PVCHANGE_UUID_ARGS struct guestfs_pvchange_uuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pvchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_pvchange_uuid (device);
  if (r == -1)
    /* do_pvchange_uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
pvchange_uuid_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_pvchange_uuid_all ();
  if (r == -1)
    /* do_pvchange_uuid_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVRESIZE_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvresize_size_args)))

static void
cleanup_xdr_free_pvresize_size_args (struct guestfs_pvresize_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVRESIZE_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvresize_size_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PVRESIZE_SIZE_ARGS struct guestfs_pvresize_size_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pvresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  size = args.size;

  r = do_pvresize_size (device, size);
  if (r == -1)
    /* do_pvresize_size has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_REMOUNT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_remount_args)))

static void
cleanup_xdr_free_remount_args (struct guestfs_remount_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_remount_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_REMOUNT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
remount_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_REMOUNT_ARGS struct guestfs_remount_args args;
  memset (&args, 0, sizeof args);
  const char *mountpoint;
  int rw;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_remount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, false, return);
  rw = args.rw;

  NEED_ROOT (false, return);
  r = do_remount (mountpoint, rw);
  if (r == -1)
    /* do_remount has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_REMOVEXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_removexattr_args)))

static void
cleanup_xdr_free_removexattr_args (struct guestfs_removexattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_removexattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_REMOVEXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
removexattr_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_REMOVEXATTR_ARGS struct guestfs_removexattr_args args;
  memset (&args, 0, sizeof args);
  const char *xattr;
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

  if (!xdr_guestfs_removexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_removexattr (xattr, path);
  if (r == -1)
    /* do_removexattr has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RESIZE2FS_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_resize2fs_size_args)))

static void
cleanup_xdr_free_resize2fs_size_args (struct guestfs_resize2fs_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RESIZE2FS_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
resize2fs_size_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RESIZE2FS_SIZE_ARGS struct guestfs_resize2fs_size_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_resize2fs_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  size = args.size;

  r = do_resize2fs_size (device, size);
  if (r == -1)
    /* do_resize2fs_size has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RM_F_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rm_f_args)))

static void
cleanup_xdr_free_rm_f_args (struct guestfs_rm_f_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rm_f_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RM_F_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rm_f_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RM_F_ARGS struct guestfs_rm_f_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rm_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_rm_f (path);
  if (r == -1)
    /* do_rm_f has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RSYNC_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rsync_out_args)))

static void
cleanup_xdr_free_rsync_out_args (struct guestfs_rsync_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RSYNC_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rsync_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RSYNC_OUT_ARGS struct guestfs_rsync_out_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *remote;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_rsync_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  remote = args.remote;
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (false, return);
  r = do_rsync_out (src, remote, archive, deletedest);
  if (r == -1)
    /* do_rsync_out has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_E2GENERATION_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_e2generation_args)))

static void
cleanup_xdr_free_set_e2generation_args (struct guestfs_set_e2generation_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2generation_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_E2GENERATION_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_e2generation_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_E2GENERATION_ARGS struct guestfs_set_e2generation_args args;
  memset (&args, 0, sizeof args);
  const char *file;
  int64_t generation;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);
  generation = args.generation;

  NEED_ROOT (false, return);
  r = do_set_e2generation (file, generation);
  if (r == -1)
    /* do_set_e2generation has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_label_args)))

static void
cleanup_xdr_free_set_label_args (struct guestfs_set_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_label_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_LABEL_ARGS struct guestfs_set_label_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);
  label = args.label;

  r = do_set_label (&mountable, label);
  if (r == -1)
    /* do_set_label has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISK_KERNEL_GEOMETRY_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdisk_kernel_geometry_args)))

static void
cleanup_xdr_free_sfdisk_kernel_geometry_args (struct guestfs_sfdisk_kernel_geometry_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISK_KERNEL_GEOMETRY_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdisk_kernel_geometry_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_SFDISK_KERNEL_GEOMETRY_ARGS struct guestfs_sfdisk_kernel_geometry_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdisk_kernel_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_sfdisk_kernel_geometry (device);
  if (r == NULL)
    /* do_sfdisk_kernel_geometry has already called reply_with_error */
    return;

  struct guestfs_sfdisk_kernel_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_kernel_geometry_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SLEEP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sleep_args)))

static void
cleanup_xdr_free_sleep_args (struct guestfs_sleep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sleep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SLEEP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sleep_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SLEEP_ARGS struct guestfs_sleep_args args;
  memset (&args, 0, sizeof args);
  int secs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sleep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  secs = args.secs;

  r = do_sleep (secs);
  if (r == -1)
    /* do_sleep has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_STRINGS_E_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_strings_e_args)))

static void
cleanup_xdr_free_strings_e_args (struct guestfs_strings_e_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_strings_e_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_STRINGS_E_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
strings_e_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_STRINGS_E_ARGS struct guestfs_strings_e_args args;
  memset (&args, 0, sizeof args);
  const char *encoding;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_strings_e_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  encoding = args.encoding;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_strings_e (encoding, path);
  if (r == NULL)
    /* do_strings_e has already called reply_with_error */
    return;

  struct guestfs_strings_e_ret ret;
  ret.stringsout.stringsout_len = guestfs_int_count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_e_ret, (char *) &ret);
}

void
sync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TAIL_N_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tail_n_args)))

static void
cleanup_xdr_free_tail_n_args (struct guestfs_tail_n_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tail_n_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TAIL_N_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tail_n_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_TAIL_N_ARGS struct guestfs_tail_n_args args;
  memset (&args, 0, sizeof args);
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_tail_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_tail_n (nrlines, path);
  if (r == NULL)
    /* do_tail_n has already called reply_with_error */
    return;

  struct guestfs_tail_n_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_n_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TAR_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tar_out_args)))

static void
cleanup_xdr_free_tar_out_args (struct guestfs_tar_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tar_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TAR_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tar_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TAR_OUT_ARGS struct guestfs_tar_out_args args;
  memset (&args, 0, sizeof args);
  const char *directory;
  const char *compress;
  int numericowner;
  char **excludes;
  int xattrs;
  int selinux;
  int acls;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffc0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_tar_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  compress = args.compress;
  numericowner = args.numericowner;
  /* Ugly, but safe and avoids copying the strings. */
  excludes = realloc (args.excludes.excludes_val,
                sizeof (char *) * (args.excludes.excludes_len+1));
  if (excludes == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  excludes[args.excludes.excludes_len] = NULL;
  args.excludes.excludes_val = excludes;
  xattrs = args.xattrs;
  selinux = args.selinux;
  acls = args.acls;

  r = do_tar_out (directory, compress, numericowner, excludes, xattrs, selinux, acls);
  if (r == -1)
    /* do_tar_out has already called reply_with_error */
    return;

  /* do_tar_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VFS_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vfs_type_args)))

static void
cleanup_xdr_free_vfs_type_args (struct guestfs_vfs_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VFS_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vfs_type_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_VFS_TYPE_ARGS struct guestfs_vfs_type_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vfs_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_vfs_type (&mountable);
  if (r == NULL)
    /* do_vfs_type has already called reply_with_error */
    return;

  struct guestfs_vfs_type_ret ret;
  ret.fstype = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_type_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGCREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgcreate_args)))

static void
cleanup_xdr_free_vgcreate_args (struct guestfs_vgcreate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgcreate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGCREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgcreate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VGCREATE_ARGS struct guestfs_vgcreate_args args;
  memset (&args, 0, sizeof args);
  const char *volgroup;
  CLEANUP_FREE_STRING_LIST char **physvols = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vgcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  volgroup = args.volgroup;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  physvols = calloc (args.physvols.physvols_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.physvols.physvols_len; ++i)
      RESOLVE_DEVICE (args.physvols.physvols_val[i], physvols[i], false);
    physvols[i] = NULL;
  }

  r = do_vgcreate (volgroup, physvols);
  if (r == -1)
    /* do_vgcreate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_WC_C_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_wc_c_args)))

static void
cleanup_xdr_free_wc_c_args (struct guestfs_wc_c_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_wc_c_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_WC_C_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
wc_c_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_WC_C_ARGS struct guestfs_wc_c_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_wc_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_wc_c (path);
  if (r == -1)
    /* do_wc_c has already called reply_with_error */
    return;

  struct guestfs_wc_c_ret ret;
  ret.chars = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_c_ret, (char *) &ret);
}

void
yara_load_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_libyara_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("libyara");
    return;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_yara_load ();
  if (r == -1)
    /* do_yara_load has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZEGREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zegrep_args)))

static void
cleanup_xdr_free_zegrep_args (struct guestfs_zegrep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zegrep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZEGREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zegrep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZEGREP_ARGS struct guestfs_zegrep_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zegrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zegrep (regex, path);
  if (r == NULL)
    /* do_zegrep has already called reply_with_error */
    return;

  struct guestfs_zegrep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrep_ret, (char *) &ret);
}

