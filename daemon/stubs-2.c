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

#define CLEANUP_XDR_FREE_AUG_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_label_args)))

static void
cleanup_xdr_free_aug_label_args (struct guestfs_aug_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_label_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_AUG_LABEL_ARGS struct guestfs_aug_label_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_label (augpath);
  if (r == NULL)
    /* do_aug_label has already called reply_with_error */
    return;

  struct guestfs_aug_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_label_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLKDISCARDZEROES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blkdiscardzeroes_args)))

static void
cleanup_xdr_free_blkdiscardzeroes_args (struct guestfs_blkdiscardzeroes_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscardzeroes_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLKDISCARDZEROES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blkdiscardzeroes_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLKDISCARDZEROES_ARGS struct guestfs_blkdiscardzeroes_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscardzeroes_available ()) {
    reply_with_unavailable_feature ("blkdiscardzeroes");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blkdiscardzeroes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blkdiscardzeroes (device);
  if (r == -1)
    /* do_blkdiscardzeroes has already called reply_with_error */
    return;

  struct guestfs_blkdiscardzeroes_ret ret;
  ret.zeroes = r;
  reply ((xdrproc_t) &xdr_guestfs_blkdiscardzeroes_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_GETSIZE64_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_getsize64_args)))

static void
cleanup_xdr_free_blockdev_getsize64_args (struct guestfs_blockdev_getsize64_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_GETSIZE64_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_getsize64_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_BLOCKDEV_GETSIZE64_ARGS struct guestfs_blockdev_getsize64_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_getsize64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_getsize64 (device);
  if (r == -1)
    /* do_blockdev_getsize64 has already called reply_with_error */
    return;

  struct guestfs_blockdev_getsize64_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_GETSS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_getss_args)))

static void
cleanup_xdr_free_blockdev_getss_args (struct guestfs_blockdev_getss_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_GETSS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_getss_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_GETSS_ARGS struct guestfs_blockdev_getss_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_getss_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_getss (device);
  if (r == -1)
    /* do_blockdev_getss has already called reply_with_error */
    return;

  struct guestfs_blockdev_getss_ret ret;
  ret.sectorsize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getss_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_REREADPT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_rereadpt_args)))

static void
cleanup_xdr_free_blockdev_rereadpt_args (struct guestfs_blockdev_rereadpt_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_REREADPT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_rereadpt_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_REREADPT_ARGS struct guestfs_blockdev_rereadpt_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_rereadpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_rereadpt (device);
  if (r == -1)
    /* do_blockdev_rereadpt has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_BALANCE_CANCEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_balance_cancel_args)))

static void
cleanup_xdr_free_btrfs_balance_cancel_args (struct guestfs_btrfs_balance_cancel_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_cancel_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_BALANCE_CANCEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_balance_cancel_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_BALANCE_CANCEL_ARGS struct guestfs_btrfs_balance_cancel_args args;
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

  if (!xdr_guestfs_btrfs_balance_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_balance_cancel (path);
  if (r == -1)
    /* do_btrfs_balance_cancel has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_LIMIT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_limit_args)))

static void
cleanup_xdr_free_btrfs_qgroup_limit_args (struct guestfs_btrfs_qgroup_limit_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_limit_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_LIMIT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_limit_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_LIMIT_ARGS struct guestfs_btrfs_qgroup_limit_args args;
  memset (&args, 0, sizeof args);
  const char *subvolume;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_qgroup_limit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, false, return);
  size = args.size;

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_limit (subvolume, size);
  if (r == -1)
    /* do_btrfs_qgroup_limit has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QUOTA_RESCAN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_quota_rescan_args)))

static void
cleanup_xdr_free_btrfs_quota_rescan_args (struct guestfs_btrfs_quota_rescan_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_rescan_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QUOTA_RESCAN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_quota_rescan_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QUOTA_RESCAN_ARGS struct guestfs_btrfs_quota_rescan_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_quota_rescan_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, false);

  r = do_btrfs_quota_rescan (&fs);
  if (r == -1)
    /* do_btrfs_quota_rescan has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SET_SEEDING_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_set_seeding_args)))

static void
cleanup_xdr_free_btrfs_set_seeding_args (struct guestfs_btrfs_set_seeding_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_set_seeding_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SET_SEEDING_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_set_seeding_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SET_SEEDING_ARGS struct guestfs_btrfs_set_seeding_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int seeding;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_set_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  seeding = args.seeding;

  r = do_btrfs_set_seeding (device, seeding);
  if (r == -1)
    /* do_btrfs_set_seeding has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SHOW_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_show_args)))

static void
cleanup_xdr_free_btrfs_subvolume_show_args (struct guestfs_btrfs_subvolume_show_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_show_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SHOW_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_show_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_SHOW_ARGS struct guestfs_btrfs_subvolume_show_args args;
  memset (&args, 0, sizeof args);
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_subvolume_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_subvolume_show (subvolume);
  if (r == NULL)
    /* do_btrfs_subvolume_show has already called reply_with_error */
    return;

  struct guestfs_btrfs_subvolume_show_ret ret;
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_len = guestfs_int_count_strings (r);
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_val = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_show_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CHOWN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_chown_args)))

static void
cleanup_xdr_free_chown_args (struct guestfs_chown_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_chown_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CHOWN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
chown_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CHOWN_ARGS struct guestfs_chown_args args;
  memset (&args, 0, sizeof args);
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_chown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_chown (owner, group, path);
  if (r == -1)
    /* do_chown has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COMMAND_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_command_args)))

static void
cleanup_xdr_free_command_args (struct guestfs_command_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_command_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COMMAND_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
command_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_COMMAND_ARGS struct guestfs_command_args args;
  memset (&args, 0, sizeof args);
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_command_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args.arguments.arguments_val,
                sizeof (char *) * (args.arguments.arguments_len+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  arguments[args.arguments.arguments_len] = NULL;
  args.arguments.arguments_val = arguments;

  r = do_command (arguments);
  if (r == NULL)
    /* do_command has already called reply_with_error */
    return;

  struct guestfs_command_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_command_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_DEVICE_TO_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_device_to_file_args)))

static void
cleanup_xdr_free_copy_device_to_file_args (struct guestfs_copy_device_to_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_DEVICE_TO_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_device_to_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_DEVICE_TO_FILE_ARGS struct guestfs_copy_device_to_file_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *src = NULL;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_copy_device_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.src, src, false);
  dest = args.dest;
  ABS_PATH (dest, false, return);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (false, return);
  r = do_copy_device_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CP_R_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cp_r_args)))

static void
cleanup_xdr_free_cp_r_args (struct guestfs_cp_r_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cp_r_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CP_R_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cp_r_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CP_R_ARGS struct guestfs_cp_r_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_cp_r_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);

  NEED_ROOT (false, return);
  r = do_cp_r (src, dest);
  if (r == -1)
    /* do_cp_r has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DEBUG_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_debug_args)))

static void
cleanup_xdr_free_debug_args (struct guestfs_debug_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_debug_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DEBUG_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
debug_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_DEBUG_ARGS struct guestfs_debug_args args;
  memset (&args, 0, sizeof args);
  const char *subcmd;
  char **extraargs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_debug_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  subcmd = args.subcmd;
  /* Ugly, but safe and avoids copying the strings. */
  extraargs = realloc (args.extraargs.extraargs_val,
                sizeof (char *) * (args.extraargs.extraargs_len+1));
  if (extraargs == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  extraargs[args.extraargs.extraargs_len] = NULL;
  args.extraargs.extraargs_val = extraargs;

  r = do_debug (subcmd, extraargs);
  if (r == NULL)
    /* do_debug has already called reply_with_error */
    return;

  struct guestfs_debug_ret ret;
  ret.result = r;
  reply ((xdrproc_t) &xdr_guestfs_debug_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DROP_CACHES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_drop_caches_args)))

static void
cleanup_xdr_free_drop_caches_args (struct guestfs_drop_caches_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_drop_caches_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DROP_CACHES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
drop_caches_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DROP_CACHES_ARGS struct guestfs_drop_caches_args args;
  memset (&args, 0, sizeof args);
  int whattodrop;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_drop_caches_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  whattodrop = args.whattodrop;

  r = do_drop_caches (whattodrop);
  if (r == -1)
    /* do_drop_caches has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_EGREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_egrep_args)))

static void
cleanup_xdr_free_egrep_args (struct guestfs_egrep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_egrep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_EGREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
egrep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_EGREP_ARGS struct guestfs_egrep_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_egrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_egrep (regex, path);
  if (r == NULL)
    /* do_egrep has already called reply_with_error */
    return;

  struct guestfs_egrep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrep_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILE_ARCHITECTURE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_file_architecture_args)))

static void
cleanup_xdr_free_file_architecture_args (struct guestfs_file_architecture_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_file_architecture_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILE_ARCHITECTURE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
file_architecture_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_FILE_ARCHITECTURE_ARGS struct guestfs_file_architecture_args args;
  memset (&args, 0, sizeof args);
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_file_architecture_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filename = args.filename;
  ABS_PATH (filename, false, return);

  NEED_ROOT (false, return);
  r = do_file_architecture (filename);
  if (r == NULL)
    /* do_file_architecture has already called reply_with_error */
    return;

  struct guestfs_file_architecture_ret ret;
  ret.arch = r;
  reply ((xdrproc_t) &xdr_guestfs_file_architecture_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GET_E2ATTRS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_get_e2attrs_args)))

static void
cleanup_xdr_free_get_e2attrs_args (struct guestfs_get_e2attrs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2attrs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GET_E2ATTRS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
get_e2attrs_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_GET_E2ATTRS_ARGS struct guestfs_get_e2attrs_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_get_e2attrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_get_e2attrs (file);
  if (r == NULL)
    /* do_get_e2attrs has already called reply_with_error */
    return;

  struct guestfs_get_e2attrs_ret ret;
  ret.attrs = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2attrs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GET_E2GENERATION_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_get_e2generation_args)))

static void
cleanup_xdr_free_get_e2generation_args (struct guestfs_get_e2generation_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2generation_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GET_E2GENERATION_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
get_e2generation_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_GET_E2GENERATION_ARGS struct guestfs_get_e2generation_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_get_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_get_e2generation (file);
  if (r == -1)
    /* do_get_e2generation has already called reply_with_error */
    return;

  struct guestfs_get_e2generation_ret ret;
  ret.generation = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2generation_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GLOB_EXPAND_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_glob_expand_args)))

static void
cleanup_xdr_free_glob_expand_args (struct guestfs_glob_expand_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_glob_expand_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GLOB_EXPAND_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
glob_expand_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_GLOB_EXPAND_ARGS struct guestfs_glob_expand_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  int directoryslash;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_glob_expand_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  ABS_PATH (pattern, false, return);
  directoryslash = args.directoryslash;

  NEED_ROOT (false, return);
  r = do_glob_expand (pattern, directoryslash);
  if (r == NULL)
    /* do_glob_expand has already called reply_with_error */
    return;

  struct guestfs_glob_expand_ret ret;
  ret.paths.paths_len = guestfs_int_count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_glob_expand_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GRUB_INSTALL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_grub_install_args)))

static void
cleanup_xdr_free_grub_install_args (struct guestfs_grub_install_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_grub_install_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GRUB_INSTALL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
grub_install_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_GRUB_INSTALL_ARGS struct guestfs_grub_install_args args;
  memset (&args, 0, sizeof args);
  const char *root;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_grub_available ()) {
    reply_with_unavailable_feature ("grub");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_grub_install_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  root = args.root;
  ABS_PATH (root, false, return);
  RESOLVE_DEVICE (args.device, device, false);

  NEED_ROOT (false, return);
  r = do_grub_install (root, device);
  if (r == -1)
    /* do_grub_install has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_ADD_CHILD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_add_child_args)))

static void
cleanup_xdr_free_hivex_node_add_child_args (struct guestfs_hivex_node_add_child_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_add_child_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_ADD_CHILD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_add_child_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_HIVEX_NODE_ADD_CHILD_ARGS struct guestfs_hivex_node_add_child_args args;
  memset (&args, 0, sizeof args);
  int64_t parent;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_node_add_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  parent = args.parent;
  name = args.name;

  r = do_hivex_node_add_child (parent, name);
  if (r == -1)
    /* do_hivex_node_add_child has already called reply_with_error */
    return;

  struct guestfs_hivex_node_add_child_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_add_child_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_GET_VALUE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_get_value_args)))

static void
cleanup_xdr_free_hivex_node_get_value_args (struct guestfs_hivex_node_get_value_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_value_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_GET_VALUE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_get_value_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_HIVEX_NODE_GET_VALUE_ARGS struct guestfs_hivex_node_get_value_args args;
  memset (&args, 0, sizeof args);
  int64_t nodeh;
  const char *key;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_node_get_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;
  key = args.key;

  r = do_hivex_node_get_value (nodeh, key);
  if (r == -1)
    /* do_hivex_node_get_value has already called reply_with_error */
    return;

  struct guestfs_hivex_node_get_value_ret ret;
  ret.valueh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_value_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_ARCH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_arch_args)))

static void
cleanup_xdr_free_inspect_get_arch_args (struct guestfs_inspect_get_arch_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_arch_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_ARCH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_arch_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_ARCH_ARGS struct guestfs_inspect_get_arch_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_arch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_arch (&root);
  if (r == NULL)
    /* do_inspect_get_arch has already called reply_with_error */
    return;

  struct guestfs_inspect_get_arch_ret ret;
  ret.arch = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_arch_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_DRIVE_MAPPINGS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_drive_mappings_args)))

static void
cleanup_xdr_free_inspect_get_drive_mappings_args (struct guestfs_inspect_get_drive_mappings_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_drive_mappings_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_DRIVE_MAPPINGS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_drive_mappings_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_DRIVE_MAPPINGS_ARGS struct guestfs_inspect_get_drive_mappings_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_drive_mappings_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_drive_mappings (&root);
  if (r == NULL)
    /* do_inspect_get_drive_mappings has already called reply_with_error */
    return;

  struct guestfs_inspect_get_drive_mappings_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; i += 2) {
    char *rr = reverse_device_name_translation (r[i+1]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i+1]);
    r[i+1] = rr;
  }
  ret.drives.drives_len = guestfs_int_count_strings (r);
  ret.drives.drives_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_drive_mappings_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_windows_current_control_set_args)))

static void
cleanup_xdr_free_inspect_get_windows_current_control_set_args (struct guestfs_inspect_get_windows_current_control_set_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_windows_current_control_set_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_windows_current_control_set_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET_ARGS struct guestfs_inspect_get_windows_current_control_set_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_windows_current_control_set_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_windows_current_control_set (&root);
  if (r == NULL)
    /* do_inspect_get_windows_current_control_set has already called reply_with_error */
    return;

  struct guestfs_inspect_get_windows_current_control_set_ret ret;
  ret.controlset = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_windows_current_control_set_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEMROOT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_windows_systemroot_args)))

static void
cleanup_xdr_free_inspect_get_windows_systemroot_args (struct guestfs_inspect_get_windows_systemroot_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_windows_systemroot_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEMROOT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_windows_systemroot_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEMROOT_ARGS struct guestfs_inspect_get_windows_systemroot_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_windows_systemroot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_windows_systemroot (&root);
  if (r == NULL)
    /* do_inspect_get_windows_systemroot has already called reply_with_error */
    return;

  struct guestfs_inspect_get_windows_systemroot_ret ret;
  ret.systemroot = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_windows_systemroot_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_CHARDEV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_chardev_args)))

static void
cleanup_xdr_free_is_chardev_args (struct guestfs_is_chardev_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_chardev_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_CHARDEV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_chardev_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_CHARDEV_ARGS struct guestfs_is_chardev_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_chardev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_chardev (path, followsymlinks);
  if (r == -1)
    /* do_is_chardev has already called reply_with_error */
    return;

  struct guestfs_is_chardev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_chardev_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_LV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_lv_args)))

static void
cleanup_xdr_free_is_lv_args (struct guestfs_is_lv_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_lv_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_LV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_lv_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_LV_ARGS struct guestfs_is_lv_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_is_lv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_is_lv (&mountable);
  if (r == -1)
    /* do_is_lv has already called reply_with_error */
    return;

  struct guestfs_is_lv_ret ret;
  ret.lvflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_lv_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_SOCKET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_socket_args)))

static void
cleanup_xdr_free_is_socket_args (struct guestfs_is_socket_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_socket_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_SOCKET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_socket_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_SOCKET_ARGS struct guestfs_is_socket_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_socket_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_socket (path, followsymlinks);
  if (r == -1)
    /* do_is_socket has already called reply_with_error */
    return;

  struct guestfs_is_socket_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_socket_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_JOURNAL_OPEN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_journal_open_args)))

static void
cleanup_xdr_free_journal_open_args (struct guestfs_journal_open_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_journal_open_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_JOURNAL_OPEN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
journal_open_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_JOURNAL_OPEN_ARGS struct guestfs_journal_open_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_journal_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_journal_open (directory);
  if (r == -1)
    /* do_journal_open has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_SCAN_DEVICES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_scan_devices_args)))

static void
cleanup_xdr_free_ldmtool_scan_devices_args (struct guestfs_ldmtool_scan_devices_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_scan_devices_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_SCAN_DEVICES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_scan_devices_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_SCAN_DEVICES_ARGS struct guestfs_ldmtool_scan_devices_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ldmtool_scan_devices_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i], false);
    devices[i] = NULL;
  }

  r = do_ldmtool_scan_devices (devices);
  if (r == NULL)
    /* do_ldmtool_scan_devices has already called reply_with_error */
    return;

  struct guestfs_ldmtool_scan_devices_ret ret;
  ret.guids.guids_len = guestfs_int_count_strings (r);
  ret.guids.guids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_scan_devices_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LSETXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lsetxattr_args)))

static void
cleanup_xdr_free_lsetxattr_args (struct guestfs_lsetxattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LSETXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lsetxattr_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LSETXATTR_ARGS struct guestfs_lsetxattr_args args;
  memset (&args, 0, sizeof args);
  const char *xattr;
  const char *val;
  int vallen;
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

  if (!xdr_guestfs_lsetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_lsetxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_lsetxattr has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_KILL_SLOT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_kill_slot_args)))

static void
cleanup_xdr_free_luks_kill_slot_args (struct guestfs_luks_kill_slot_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_kill_slot_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_KILL_SLOT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_kill_slot_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_KILL_SLOT_ARGS struct guestfs_luks_kill_slot_args args;
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

  if (!xdr_guestfs_luks_kill_slot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  keyslot = args.keyslot;

  r = do_luks_kill_slot (device, key, keyslot);
  if (r == -1)
    /* do_luks_kill_slot has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKDIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkdir_args)))

static void
cleanup_xdr_free_mkdir_args (struct guestfs_mkdir_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKDIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkdir_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKDIR_ARGS struct guestfs_mkdir_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mkdir (path);
  if (r == -1)
    /* do_mkdir has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKFIFO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkfifo_args)))

static void
cleanup_xdr_free_mkfifo_args (struct guestfs_mkfifo_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkfifo_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKFIFO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkfifo_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKFIFO_ARGS struct guestfs_mkfifo_args args;
  memset (&args, 0, sizeof args);
  int mode;
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

  if (!xdr_guestfs_mkfifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mkfifo (mode, path);
  if (r == -1)
    /* do_mkfifo has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKSQUASHFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mksquashfs_args)))

static void
cleanup_xdr_free_mksquashfs_args (struct guestfs_mksquashfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mksquashfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKSQUASHFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mksquashfs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKSQUASHFS_ARGS struct guestfs_mksquashfs_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *compress;
  char **excludes;

  /* The caller should have checked before calling this. */
  if (! optgroup_squashfs_available ()) {
    reply_with_unavailable_feature ("squashfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mksquashfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  compress = args.compress;
  /* Ugly, but safe and avoids copying the strings. */
  excludes = realloc (args.excludes.excludes_val,
                sizeof (char *) * (args.excludes.excludes_len+1));
  if (excludes == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  excludes[args.excludes.excludes_len] = NULL;
  args.excludes.excludes_val = excludes;

  NEED_ROOT (false, return);
  r = do_mksquashfs (path, compress, excludes);
  if (r == -1)
    /* do_mksquashfs has already called reply_with_error */
    return;

  /* do_mksquashfs has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MODPROBE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_modprobe_args)))

static void
cleanup_xdr_free_modprobe_args (struct guestfs_modprobe_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_modprobe_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MODPROBE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
modprobe_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MODPROBE_ARGS struct guestfs_modprobe_args args;
  memset (&args, 0, sizeof args);
  const char *modulename;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxmodules_available ()) {
    reply_with_unavailable_feature ("linuxmodules");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_modprobe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  modulename = args.modulename;

  r = do_modprobe (modulename);
  if (r == -1)
    /* do_modprobe has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSCAT_I_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfscat_i_args)))

static void
cleanup_xdr_free_ntfscat_i_args (struct guestfs_ntfscat_i_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfscat_i_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSCAT_I_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfscat_i_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSCAT_I_ARGS struct guestfs_ntfscat_i_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ntfscat_i_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.device, device, false);
  inode = args.inode;

  r = do_ntfscat_i (&device, inode);
  if (r == -1)
    /* do_ntfscat_i has already called reply_with_error */
    return;

  /* do_ntfscat_i has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_DISK_GUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_disk_guid_args)))

static void
cleanup_xdr_free_part_get_disk_guid_args (struct guestfs_part_get_disk_guid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_disk_guid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_DISK_GUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_disk_guid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_DISK_GUID_ARGS struct guestfs_part_get_disk_guid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_disk_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_part_get_disk_guid (device);
  if (r == NULL)
    /* do_part_get_disk_guid has already called reply_with_error */
    return;

  struct guestfs_part_get_disk_guid_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_disk_guid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_LIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_list_args)))

static void
cleanup_xdr_free_part_list_args (struct guestfs_part_list_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_LIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_list_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_partition_list *r = NULL;
  CLEANUP_XDR_FREE_PART_LIST_ARGS struct guestfs_part_list_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_part_list (device);
  if (r == NULL)
    /* do_part_list has already called reply_with_error */
    return;

  struct guestfs_part_list_ret ret;
  ret.partitions = *r;
  reply ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_BOOTABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_bootable_args)))

static void
cleanup_xdr_free_part_set_bootable_args (struct guestfs_part_set_bootable_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_BOOTABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_bootable_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_BOOTABLE_ARGS struct guestfs_part_set_bootable_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int bootable;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_set_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  bootable = args.bootable;

  r = do_part_set_bootable (device, partnum, bootable);
  if (r == -1)
    /* do_part_set_bootable has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_GPT_ATTRIBUTES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_gpt_attributes_args)))

static void
cleanup_xdr_free_part_set_gpt_attributes_args (struct guestfs_part_set_gpt_attributes_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_attributes_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_GPT_ATTRIBUTES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_gpt_attributes_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_GPT_ATTRIBUTES_ARGS struct guestfs_part_set_gpt_attributes_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int64_t attributes;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_set_gpt_attributes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  attributes = args.attributes;

  r = do_part_set_gpt_attributes (device, partnum, attributes);
  if (r == -1)
    /* do_part_set_gpt_attributes has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_GPT_GUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_gpt_guid_args)))

static void
cleanup_xdr_free_part_set_gpt_guid_args (struct guestfs_part_set_gpt_guid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_guid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_GPT_GUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_gpt_guid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_GPT_GUID_ARGS struct guestfs_part_set_gpt_guid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *guid;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_set_gpt_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_guid (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_guid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_TO_DEV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_to_dev_args)))

static void
cleanup_xdr_free_part_to_dev_args (struct guestfs_part_to_dev_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_to_dev_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_TO_DEV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_to_dev_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_TO_DEV_ARGS struct guestfs_part_to_dev_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_to_dev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.partition, partition, false);

  r = do_part_to_dev (partition);
  if (r == NULL)
    /* do_part_to_dev has already called reply_with_error */
    return;

  struct guestfs_part_to_dev_ret ret;
  CLEANUP_FREE char *rr = reverse_device_name_translation (r);
  if (rr == NULL)
    /* reverse_device_name_translation has already called reply_with_error */
    return;
  ret.device = rr;
  reply ((xdrproc_t) &xdr_guestfs_part_to_dev_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVRESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvresize_args)))

static void
cleanup_xdr_free_pvresize_args (struct guestfs_pvresize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVRESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvresize_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PVRESIZE_ARGS struct guestfs_pvresize_args args;
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

  if (!xdr_guestfs_pvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_pvresize (device);
  if (r == -1)
    /* do_pvresize has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
pvs_full_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_lvm_pv_list *r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_pvs_full ();
  if (r == NULL)
    /* do_pvs_full has already called reply_with_error */
    return;

  struct guestfs_pvs_full_ret ret;
  ret.physvols = *r;
  reply ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PWRITE_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pwrite_device_args)))

static void
cleanup_xdr_free_pwrite_device_args (struct guestfs_pwrite_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PWRITE_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pwrite_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PWRITE_DEVICE_ARGS struct guestfs_pwrite_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pwrite_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  r = do_pwrite_device (device, content, content_size, offset);
  if (r == -1)
    /* do_pwrite_device has already called reply_with_error */
    return;

  struct guestfs_pwrite_device_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_device_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_READDIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_readdir_args)))

static void
cleanup_xdr_free_readdir_args (struct guestfs_readdir_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_READDIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
readdir_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_dirent_list *r = NULL;
  CLEANUP_XDR_FREE_READDIR_ARGS struct guestfs_readdir_args args;
  memset (&args, 0, sizeof args);
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_readdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dir = args.dir;
  ABS_PATH (dir, false, return);

  NEED_ROOT (false, return);
  r = do_readdir (dir);
  if (r == NULL)
    /* do_readdir has already called reply_with_error */
    return;

  struct guestfs_readdir_ret ret;
  ret.entries = *r;
  reply ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_READLINK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_readlink_args)))

static void
cleanup_xdr_free_readlink_args (struct guestfs_readlink_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_readlink_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_READLINK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
readlink_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_READLINK_ARGS struct guestfs_readlink_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_readlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_readlink (path);
  if (r == NULL)
    /* do_readlink has already called reply_with_error */
    return;

  struct guestfs_readlink_ret ret;
  ret.link = r;
  reply ((xdrproc_t) &xdr_guestfs_readlink_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RESIZE2FS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_resize2fs_args)))

static void
cleanup_xdr_free_resize2fs_args (struct guestfs_resize2fs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RESIZE2FS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
resize2fs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RESIZE2FS_ARGS struct guestfs_resize2fs_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_resize2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_resize2fs (device);
  if (r == -1)
    /* do_resize2fs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RSYNC_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rsync_in_args)))

static void
cleanup_xdr_free_rsync_in_args (struct guestfs_rsync_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RSYNC_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rsync_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RSYNC_IN_ARGS struct guestfs_rsync_in_args args;
  memset (&args, 0, sizeof args);
  const char *remote;
  const char *dest;
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

  if (!xdr_guestfs_rsync_in_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  remote = args.remote;
  dest = args.dest;
  ABS_PATH (dest, false, return);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (false, return);
  r = do_rsync_in (remote, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_E2UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_e2uuid_args)))

static void
cleanup_xdr_free_set_e2uuid_args (struct guestfs_set_e2uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_E2UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_e2uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_E2UUID_ARGS struct guestfs_set_e2uuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  uuid = args.uuid;

  r = do_set_e2uuid (device, uuid);
  if (r == -1)
    /* do_set_e2uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISK_DISK_GEOMETRY_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdisk_disk_geometry_args)))

static void
cleanup_xdr_free_sfdisk_disk_geometry_args (struct guestfs_sfdisk_disk_geometry_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISK_DISK_GEOMETRY_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdisk_disk_geometry_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_SFDISK_DISK_GEOMETRY_ARGS struct guestfs_sfdisk_disk_geometry_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdisk_disk_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_sfdisk_disk_geometry (device);
  if (r == NULL)
    /* do_sfdisk_disk_geometry has already called reply_with_error */
    return;

  struct guestfs_sfdisk_disk_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_disk_geometry_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sh_args)))

static void
cleanup_xdr_free_sh_args (struct guestfs_sh_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sh_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sh_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_SH_ARGS struct guestfs_sh_args args;
  memset (&args, 0, sizeof args);
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sh_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  command = args.command;

  r = do_sh (command);
  if (r == NULL)
    /* do_sh has already called reply_with_error */
    return;

  struct guestfs_sh_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_STATNS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_statns_args)))

static void
cleanup_xdr_free_statns_args (struct guestfs_statns_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_statns_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_STATNS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
statns_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_statns *r = NULL;
  CLEANUP_XDR_FREE_STATNS_ARGS struct guestfs_statns_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_statns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_statns (path);
  if (r == NULL)
    /* do_statns has already called reply_with_error */
    return;

  struct guestfs_statns_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPON_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapon_label_args)))

static void
cleanup_xdr_free_swapon_label_args (struct guestfs_swapon_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPON_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapon_label_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPON_LABEL_ARGS struct guestfs_swapon_label_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapon_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_swapon_label (label);
  if (r == -1)
    /* do_swapon_label has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TXZ_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_txz_out_args)))

static void
cleanup_xdr_free_txz_out_args (struct guestfs_txz_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_txz_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TXZ_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
txz_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TXZ_OUT_ARGS struct guestfs_txz_out_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    reply_with_unavailable_feature ("xz");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_txz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_txz_out (directory);
  if (r == -1)
    /* do_txz_out has already called reply_with_error */
    return;

  /* do_txz_out has already sent a reply */
}

void
umount_all_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_umount_all ();
  if (r == -1)
    /* do_umount_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_UPLOAD_OFFSET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_upload_offset_args)))

static void
cleanup_xdr_free_upload_offset_args (struct guestfs_upload_offset_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_upload_offset_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_UPLOAD_OFFSET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
upload_offset_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_UPLOAD_OFFSET_ARGS struct guestfs_upload_offset_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_upload_offset_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, true);
  offset = args.offset;

  r = do_upload_offset (remotefilename, offset);
  if (r == -1)
    /* do_upload_offset has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
utsname_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_utsname *r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_utsname ();
  if (r == NULL)
    /* do_utsname has already called reply_with_error */
    return;

  struct guestfs_utsname_ret ret;
  ret.uts = *r;
  reply ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGPVUUIDS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgpvuuids_args)))

static void
cleanup_xdr_free_vgpvuuids_args (struct guestfs_vgpvuuids_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgpvuuids_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGPVUUIDS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgpvuuids_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_VGPVUUIDS_ARGS struct guestfs_vgpvuuids_args args;
  memset (&args, 0, sizeof args);
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vgpvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vgname = args.vgname;

  r = do_vgpvuuids (vgname);
  if (r == NULL)
    /* do_vgpvuuids has already called reply_with_error */
    return;

  struct guestfs_vgpvuuids_ret ret;
  ret.uuids.uuids_len = guestfs_int_count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgpvuuids_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZGREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zgrep_args)))

static void
cleanup_xdr_free_zgrep_args (struct guestfs_zgrep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zgrep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZGREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zgrep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZGREP_ARGS struct guestfs_zgrep_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zgrep (regex, path);
  if (r == NULL)
    /* do_zgrep has already called reply_with_error */
    return;

  struct guestfs_zgrep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrep_ret, (char *) &ret);
}

