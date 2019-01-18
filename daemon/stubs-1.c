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

#define CLEANUP_XDR_FREE_AUG_CLEAR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_clear_args)))

static void
cleanup_xdr_free_aug_clear_args (struct guestfs_aug_clear_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_clear_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_CLEAR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_clear_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_CLEAR_ARGS struct guestfs_aug_clear_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_clear_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_clear (augpath);
  if (r == -1)
    /* do_aug_clear has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_DEFVAR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_defvar_args)))

static void
cleanup_xdr_free_aug_defvar_args (struct guestfs_aug_defvar_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_DEFVAR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_defvar_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_DEFVAR_ARGS struct guestfs_aug_defvar_args args;
  memset (&args, 0, sizeof args);
  const char *name;
  const char *expr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_defvar_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  name = args.name;
  expr = args.expr ? *args.expr : NULL;

  r = do_aug_defvar (name, expr);
  if (r == -1)
    /* do_aug_defvar has already called reply_with_error */
    return;

  struct guestfs_aug_defvar_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_defvar_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BASE64_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_base64_in_args)))

static void
cleanup_xdr_free_base64_in_args (struct guestfs_base64_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_base64_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BASE64_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
base64_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BASE64_IN_ARGS struct guestfs_base64_in_args args;
  memset (&args, 0, sizeof args);
  const char *filename;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_base64_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filename = args.filename;
  ABS_PATH (filename, true, return);

  NEED_ROOT (true, return);
  r = do_base64_in (filename);
  if (r == -1)
    /* do_base64_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BASE64_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_base64_out_args)))

static void
cleanup_xdr_free_base64_out_args (struct guestfs_base64_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_base64_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BASE64_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
base64_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BASE64_OUT_ARGS struct guestfs_base64_out_args args;
  memset (&args, 0, sizeof args);
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_base64_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filename = args.filename;
  ABS_PATH (filename, false, return);

  NEED_ROOT (false, return);
  r = do_base64_out (filename);
  if (r == -1)
    /* do_base64_out has already called reply_with_error */
    return;

  /* do_base64_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_BALANCE_RESUME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_balance_resume_args)))

static void
cleanup_xdr_free_btrfs_balance_resume_args (struct guestfs_btrfs_balance_resume_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_resume_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_BALANCE_RESUME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_balance_resume_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_BALANCE_RESUME_ARGS struct guestfs_btrfs_balance_resume_args args;
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

  if (!xdr_guestfs_btrfs_balance_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_balance_resume (path);
  if (r == -1)
    /* do_btrfs_balance_resume has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FSCK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_fsck_args)))

static void
cleanup_xdr_free_btrfs_fsck_args (struct guestfs_btrfs_fsck_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_fsck_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FSCK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_fsck_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_FSCK_ARGS struct guestfs_btrfs_fsck_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t superblock;
  int repair;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  superblock = args.superblock;
  repair = args.repair;

  r = do_btrfs_fsck (device, superblock, repair);
  if (r == -1)
    /* do_btrfs_fsck has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_SHOW_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_show_args)))

static void
cleanup_xdr_free_btrfs_qgroup_show_args (struct guestfs_btrfs_qgroup_show_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_SHOW_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_show_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_btrfsqgroup_list *r = NULL;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_SHOW_ARGS struct guestfs_btrfs_qgroup_show_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_show (path);
  if (r == NULL)
    /* do_btrfs_qgroup_show has already called reply_with_error */
    return;

  struct guestfs_btrfs_qgroup_show_ret ret;
  ret.qgroups = *r;
  reply ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_RESCUE_CHUNK_RECOVER_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_rescue_chunk_recover_args)))

static void
cleanup_xdr_free_btrfs_rescue_chunk_recover_args (struct guestfs_btrfs_rescue_chunk_recover_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_chunk_recover_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_RESCUE_CHUNK_RECOVER_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_rescue_chunk_recover_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_RESCUE_CHUNK_RECOVER_ARGS struct guestfs_btrfs_rescue_chunk_recover_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_rescue_chunk_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_btrfs_rescue_chunk_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_chunk_recover has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SCRUB_RESUME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_scrub_resume_args)))

static void
cleanup_xdr_free_btrfs_scrub_resume_args (struct guestfs_btrfs_scrub_resume_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_resume_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SCRUB_RESUME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_scrub_resume_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SCRUB_RESUME_ARGS struct guestfs_btrfs_scrub_resume_args args;
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

  if (!xdr_guestfs_btrfs_scrub_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_scrub_resume (path);
  if (r == -1)
    /* do_btrfs_scrub_resume has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CHECKSUM_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_checksum_device_args)))

static void
cleanup_xdr_free_checksum_device_args (struct guestfs_checksum_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CHECKSUM_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
checksum_device_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_CHECKSUM_DEVICE_ARGS struct guestfs_checksum_device_args args;
  memset (&args, 0, sizeof args);
  const char *csumtype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_checksum_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  csumtype = args.csumtype;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_checksum_device (csumtype, device);
  if (r == NULL)
    /* do_checksum_device has already called reply_with_error */
    return;

  struct guestfs_checksum_device_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_device_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_ATTRIBUTES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_attributes_args)))

static void
cleanup_xdr_free_copy_attributes_args (struct guestfs_copy_attributes_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_attributes_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_ATTRIBUTES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_attributes_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_ATTRIBUTES_ARGS struct guestfs_copy_attributes_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;
  int all;
  int mode;
  int xattributes;
  int ownership;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_copy_attributes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);
  all = args.all;
  mode = args.mode;
  xattributes = args.xattributes;
  ownership = args.ownership;

  NEED_ROOT (false, return);
  r = do_copy_attributes (src, dest, all, mode, xattributes, ownership);
  if (r == -1)
    /* do_copy_attributes has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_DEVICE_TO_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_device_to_device_args)))

static void
cleanup_xdr_free_copy_device_to_device_args (struct guestfs_copy_device_to_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_DEVICE_TO_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_device_to_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_DEVICE_TO_DEVICE_ARGS struct guestfs_copy_device_to_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_copy_device_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.src, src, false);
  RESOLVE_DEVICE (args.dest, dest, false);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  r = do_copy_device_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_dd_args)))

static void
cleanup_xdr_free_dd_args (struct guestfs_dd_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_dd_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
dd_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DD_ARGS struct guestfs_dd_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_dd_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.src, src, false);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.dest, dest, false);

  r = do_dd (src, dest);
  if (r == -1)
    /* do_dd has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DEVICE_INDEX_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_device_index_args)))

static void
cleanup_xdr_free_device_index_args (struct guestfs_device_index_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_device_index_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DEVICE_INDEX_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
device_index_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DEVICE_INDEX_ARGS struct guestfs_device_index_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_device_index_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_device_index (device);
  if (r == -1)
    /* do_device_index has already called reply_with_error */
    return;

  struct guestfs_device_index_ret ret;
  ret.index = r;
  reply ((xdrproc_t) &xdr_guestfs_device_index_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DOWNLOAD_INODE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_download_inode_args)))

static void
cleanup_xdr_free_download_inode_args (struct guestfs_download_inode_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_download_inode_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DOWNLOAD_INODE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
download_inode_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DOWNLOAD_INODE_ARGS struct guestfs_download_inode_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  /* The caller should have checked before calling this. */
  if (! optgroup_sleuthkit_available ()) {
    reply_with_unavailable_feature ("sleuthkit");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_download_inode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.device, device, false);
  inode = args.inode;

  r = do_download_inode (&device, inode);
  if (r == -1)
    /* do_download_inode has already called reply_with_error */
    return;

  /* do_download_inode has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_EXISTS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_exists_args)))

static void
cleanup_xdr_free_exists_args (struct guestfs_exists_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_exists_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_EXISTS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
exists_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_EXISTS_ARGS struct guestfs_exists_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_exists_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_exists (path);
  if (r == -1)
    /* do_exists has already called reply_with_error */
    return;

  struct guestfs_exists_ret ret;
  ret.existsflag = r;
  reply ((xdrproc_t) &xdr_guestfs_exists_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_F2FS_EXPAND_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_f2fs_expand_args)))

static void
cleanup_xdr_free_f2fs_expand_args (struct guestfs_f2fs_expand_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_f2fs_expand_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_F2FS_EXPAND_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
f2fs_expand_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_F2FS_EXPAND_ARGS struct guestfs_f2fs_expand_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_f2fs_available ()) {
    reply_with_unavailable_feature ("f2fs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_f2fs_expand_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_f2fs_expand (device);
  if (r == -1)
    /* do_f2fs_expand has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILL_DIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fill_dir_args)))

static void
cleanup_xdr_free_fill_dir_args (struct guestfs_fill_dir_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fill_dir_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILL_DIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fill_dir_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FILL_DIR_ARGS struct guestfs_fill_dir_args args;
  memset (&args, 0, sizeof args);
  const char *dir;
  int nr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fill_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dir = args.dir;
  ABS_PATH (dir, false, return);
  nr = args.nr;

  NEED_ROOT (false, return);
  r = do_fill_dir (dir, nr);
  if (r == -1)
    /* do_fill_dir has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FINDFS_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_findfs_label_args)))

static void
cleanup_xdr_free_findfs_label_args (struct guestfs_findfs_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_findfs_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FINDFS_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
findfs_label_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_FINDFS_LABEL_ARGS struct guestfs_findfs_label_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_findfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_findfs_label (label);
  if (r == NULL)
    /* do_findfs_label has already called reply_with_error */
    return;

  struct guestfs_findfs_label_ret ret;
  CLEANUP_FREE char *rr = reverse_device_name_translation (r);
  if (rr == NULL)
    /* reverse_device_name_translation has already called reply_with_error */
    return;
  ret.device = rr;
  reply ((xdrproc_t) &xdr_guestfs_findfs_label_ret, (char *) &ret);
}

void
get_umask_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_get_umask ();
  if (r == -1)
    /* do_get_umask has already called reply_with_error */
    return;

  struct guestfs_get_umask_ret ret;
  ret.mask = r;
  reply ((xdrproc_t) &xdr_guestfs_get_umask_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GETXATTRS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_getxattrs_args)))

static void
cleanup_xdr_free_getxattrs_args (struct guestfs_getxattrs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GETXATTRS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
getxattrs_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_xattr_list *r = NULL;
  CLEANUP_XDR_FREE_GETXATTRS_ARGS struct guestfs_getxattrs_args args;
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

  if (!xdr_guestfs_getxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_getxattrs (path);
  if (r == NULL)
    /* do_getxattrs has already called reply_with_error */
    return;

  struct guestfs_getxattrs_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_grep_args)))

static void
cleanup_xdr_free_grep_args (struct guestfs_grep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_grep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
grep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_GREP_ARGS struct guestfs_grep_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;
  int extended;
  int fixed;
  int insensitive;
  int compressed;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_grep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);
  extended = args.extended;
  fixed = args.fixed;
  insensitive = args.insensitive;
  compressed = args.compressed;

  NEED_ROOT (false, return);
  r = do_grep (regex, path, extended, fixed, insensitive, compressed);
  if (r == NULL)
    /* do_grep has already called reply_with_error */
    return;

  struct guestfs_grep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grep_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_PARENT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_parent_args)))

static void
cleanup_xdr_free_hivex_node_parent_args (struct guestfs_hivex_node_parent_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_parent_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_PARENT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_parent_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_HIVEX_NODE_PARENT_ARGS struct guestfs_hivex_node_parent_args args;
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

  if (!xdr_guestfs_hivex_node_parent_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_parent (nodeh);
  if (r == -1)
    /* do_hivex_node_parent has already called reply_with_error */
    return;

  struct guestfs_hivex_node_parent_ret ret;
  ret.parent = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_parent_ret, (char *) &ret);
}

void
hivex_root_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_hivex_root ();
  if (r == -1)
    /* do_hivex_root has already called reply_with_error */
    return;

  struct guestfs_hivex_root_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_root_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_VALUE_STRING_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_value_string_args)))

static void
cleanup_xdr_free_hivex_value_string_args (struct guestfs_hivex_value_string_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_string_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_VALUE_STRING_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_value_string_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_VALUE_STRING_ARGS struct guestfs_hivex_value_string_args args;
  memset (&args, 0, sizeof args);
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_value_string_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  valueh = args.valueh;

  r = do_hivex_value_string (valueh);
  if (r == NULL)
    /* do_hivex_value_string has already called reply_with_error */
    return;

  struct guestfs_hivex_value_string_ret ret;
  ret.databuf = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_string_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_VALUE_VALUE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_value_value_args)))

static void
cleanup_xdr_free_hivex_value_value_args (struct guestfs_hivex_value_value_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_value_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_VALUE_VALUE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_value_value_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_VALUE_VALUE_ARGS struct guestfs_hivex_value_value_args args;
  memset (&args, 0, sizeof args);
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_value_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  valueh = args.valueh;

  r = do_hivex_value_value (valueh, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_hivex_value_value has already called reply_with_error */
    return;

  struct guestfs_hivex_value_value_ret ret;
  ret.databuf.databuf_val = r;
  ret.databuf.databuf_len = size;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_value_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INITRD_LIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_initrd_list_args)))

static void
cleanup_xdr_free_initrd_list_args (struct guestfs_initrd_list_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_list_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INITRD_LIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
initrd_list_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_INITRD_LIST_ARGS struct guestfs_initrd_list_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_initrd_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_initrd_list (path);
  if (r == NULL)
    /* do_initrd_list has already called reply_with_error */
    return;

  struct guestfs_initrd_list_ret ret;
  ret.filenames.filenames_len = guestfs_int_count_strings (r);
  ret.filenames.filenames_val = r;
  reply ((xdrproc_t) &xdr_guestfs_initrd_list_ret, (char *) &ret);
}

void
inotify_files_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_inotify_files ();
  if (r == NULL)
    /* do_inotify_files has already called reply_with_error */
    return;

  struct guestfs_inotify_files_ret ret;
  ret.paths.paths_len = guestfs_int_count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_files_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INOTIFY_RM_WATCH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inotify_rm_watch_args)))

static void
cleanup_xdr_free_inotify_rm_watch_args (struct guestfs_inotify_rm_watch_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INOTIFY_RM_WATCH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inotify_rm_watch_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INOTIFY_RM_WATCH_ARGS struct guestfs_inotify_rm_watch_args args;
  memset (&args, 0, sizeof args);
  int wd;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inotify_rm_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  wd = args.wd;

  r = do_inotify_rm_watch (wd);
  if (r == -1)
    /* do_inotify_rm_watch has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEM_HIVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_get_windows_system_hive_args)))

static void
cleanup_xdr_free_inspect_get_windows_system_hive_args (struct guestfs_inspect_get_windows_system_hive_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_get_windows_system_hive_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEM_HIVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_get_windows_system_hive_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INSPECT_GET_WINDOWS_SYSTEM_HIVE_ARGS struct guestfs_inspect_get_windows_system_hive_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_get_windows_system_hive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_get_windows_system_hive (&root);
  if (r == NULL)
    /* do_inspect_get_windows_system_hive has already called reply_with_error */
    return;

  struct guestfs_inspect_get_windows_system_hive_ret ret;
  ret.path = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_get_windows_system_hive_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INSPECT_IS_NETINST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inspect_is_netinst_args)))

static void
cleanup_xdr_free_inspect_is_netinst_args (struct guestfs_inspect_is_netinst_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inspect_is_netinst_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INSPECT_IS_NETINST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inspect_is_netinst_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INSPECT_IS_NETINST_ARGS struct guestfs_inspect_is_netinst_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t root
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inspect_is_netinst_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.root, root, false);

  r = do_inspect_is_netinst (&root);
  if (r == -1)
    /* do_inspect_is_netinst has already called reply_with_error */
    return;

  struct guestfs_inspect_is_netinst_ret ret;
  ret.netinst = r;
  reply ((xdrproc_t) &xdr_guestfs_inspect_is_netinst_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_SYMLINK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_symlink_args)))

static void
cleanup_xdr_free_is_symlink_args (struct guestfs_is_symlink_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_symlink_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_SYMLINK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_symlink_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_SYMLINK_ARGS struct guestfs_is_symlink_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_is_symlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_is_symlink (path);
  if (r == -1)
    /* do_is_symlink has already called reply_with_error */
    return;

  struct guestfs_is_symlink_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_symlink_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_ZERO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_zero_args)))

static void
cleanup_xdr_free_is_zero_args (struct guestfs_is_zero_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_ZERO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_zero_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_ZERO_ARGS struct guestfs_is_zero_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_is_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_is_zero (path);
  if (r == -1)
    /* do_is_zero has already called reply_with_error */
    return;

  struct guestfs_is_zero_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LCHOWN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lchown_args)))

static void
cleanup_xdr_free_lchown_args (struct guestfs_lchown_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lchown_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LCHOWN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lchown_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LCHOWN_ARGS struct guestfs_lchown_args args;
  memset (&args, 0, sizeof args);
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lchown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_lchown (owner, group, path);
  if (r == -1)
    /* do_lchown has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
ldmtool_create_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_ldmtool_create_all ();
  if (r == -1)
    /* do_ldmtool_create_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_DISKS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_diskgroup_disks_args)))

static void
cleanup_xdr_free_ldmtool_diskgroup_disks_args (struct guestfs_ldmtool_diskgroup_disks_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_DISKS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_diskgroup_disks_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_DISKS_ARGS struct guestfs_ldmtool_diskgroup_disks_args args;
  memset (&args, 0, sizeof args);
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ldmtool_diskgroup_disks_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_disks (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_disks has already called reply_with_error */
    return;

  struct guestfs_ldmtool_diskgroup_disks_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; ++i) {
    char *rr = reverse_device_name_translation (r[i]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i]);
    r[i] = rr;
  }
  ret.disks.disks_len = guestfs_int_count_strings (r);
  ret.disks.disks_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_disks_ret, (char *) &ret);
}

void
list_partitions_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_partitions ();
  if (r == NULL)
    /* do_list_partitions has already called reply_with_error */
    return;

  struct guestfs_list_partitions_ret ret;
  size_t i;
  for (i = 0; r[i] != NULL; ++i) {
    char *rr = reverse_device_name_translation (r[i]);
    if (rr == NULL)
      /* reverse_device_name_translation has already called reply_with_error */
      return;
    free (r[i]);
    r[i] = rr;
  }
  ret.partitions.partitions_len = guestfs_int_count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_partitions_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LLZ_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_llz_args)))

static void
cleanup_xdr_free_llz_args (struct guestfs_llz_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_llz_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LLZ_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
llz_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LLZ_ARGS struct guestfs_llz_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_llz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_llz (directory);
  if (r == NULL)
    /* do_llz has already called reply_with_error */
    return;

  struct guestfs_llz_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_llz_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_OPEN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_open_args)))

static void
cleanup_xdr_free_luks_open_args (struct guestfs_luks_open_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_OPEN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_open_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_OPEN_ARGS struct guestfs_luks_open_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_luks_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open (device, key, mapname);
  if (r == -1)
    /* do_luks_open has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_OPEN_RO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_open_ro_args)))

static void
cleanup_xdr_free_luks_open_ro_args (struct guestfs_luks_open_ro_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_OPEN_RO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_open_ro_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_OPEN_RO_ARGS struct guestfs_luks_open_ro_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_luks_open_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open_ro (device, key, mapname);
  if (r == -1)
    /* do_luks_open_ro has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
lvm_remove_all_stub (XDR *xdr_in)
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

  r = do_lvm_remove_all ();
  if (r == -1)
    /* do_lvm_remove_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVRESIZE_FREE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvresize_free_args)))

static void
cleanup_xdr_free_lvresize_free_args (struct guestfs_lvresize_free_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVRESIZE_FREE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvresize_free_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVRESIZE_FREE_ARGS struct guestfs_lvresize_free_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *lv = NULL;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvresize_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.lv, lv, false);
  percent = args.percent;

  r = do_lvresize_free (lv, percent);
  if (r == -1)
    /* do_lvresize_free has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MD_CREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_md_create_args)))

static void
cleanup_xdr_free_md_create_args (struct guestfs_md_create_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_md_create_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MD_CREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
md_create_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MD_CREATE_ARGS struct guestfs_md_create_args args;
  memset (&args, 0, sizeof args);
  const char *name;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t missingbitmap;
  int nrdevices;
  int spare;
  int64_t chunk;
  const char *level;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_md_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  name = args.name;
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
  missingbitmap = args.missingbitmap;
  nrdevices = args.nrdevices;
  spare = args.spare;
  chunk = args.chunk;
  level = args.level;

  r = do_md_create (name, devices, missingbitmap, nrdevices, spare, chunk, level);
  if (r == -1)
    /* do_md_create has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKDTEMP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkdtemp_args)))

static void
cleanup_xdr_free_mkdtemp_args (struct guestfs_mkdtemp_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKDTEMP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkdtemp_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_MKDTEMP_ARGS struct guestfs_mkdtemp_args args;
  memset (&args, 0, sizeof args);
  const char *tmpl;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkdtemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, false, return);

  NEED_ROOT (false, return);
  r = do_mkdtemp (tmpl);
  if (r == NULL)
    /* do_mkdtemp has already called reply_with_error */
    return;

  struct guestfs_mkdtemp_ret ret;
  ret.dir = r;
  reply ((xdrproc_t) &xdr_guestfs_mkdtemp_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKNOD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mknod_args)))

static void
cleanup_xdr_free_mknod_args (struct guestfs_mknod_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKNOD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mknod_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKNOD_ARGS struct guestfs_mknod_args args;
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

  if (!xdr_guestfs_mknod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mknod (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_args)))

static void
cleanup_xdr_free_mount_args (struct guestfs_mount_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_ARGS struct guestfs_mount_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);
  mountpoint = args.mountpoint;

  r = do_mount (&mountable, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_RO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_ro_args)))

static void
cleanup_xdr_free_mount_ro_args (struct guestfs_mount_ro_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_ro_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_RO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_ro_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_RO_ARGS struct guestfs_mount_ro_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mount_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);
  mountpoint = args.mountpoint;

  r = do_mount_ro (&mountable, mountpoint);
  if (r == -1)
    /* do_mount_ro has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
mounts_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_mounts ();
  if (r == NULL)
    /* do_mounts has already called reply_with_error */
    return;

  struct guestfs_mounts_ret ret;
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
  reply ((xdrproc_t) &xdr_guestfs_mounts_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFS_3G_PROBE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfs_3g_probe_args)))

static void
cleanup_xdr_free_ntfs_3g_probe_args (struct guestfs_ntfs_3g_probe_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFS_3G_PROBE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfs_3g_probe_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFS_3G_PROBE_ARGS struct guestfs_ntfs_3g_probe_args args;
  memset (&args, 0, sizeof args);
  int rw;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ntfs_3g_probe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  rw = args.rw;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_ntfs_3g_probe (rw, device);
  if (r == -1)
    /* do_ntfs_3g_probe has already called reply_with_error */
    return;

  struct guestfs_ntfs_3g_probe_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSCLONE_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfsclone_out_args)))

static void
cleanup_xdr_free_ntfsclone_out_args (struct guestfs_ntfsclone_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSCLONE_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfsclone_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSCLONE_OUT_ARGS struct guestfs_ntfsclone_out_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int metadataonly;
  int rescue;
  int ignorefscheck;
  int preservetimestamps;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_ntfsclone_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  metadataonly = args.metadataonly;
  rescue = args.rescue;
  ignorefscheck = args.ignorefscheck;
  preservetimestamps = args.preservetimestamps;
  force = args.force;

  r = do_ntfsclone_out (device, metadataonly, rescue, ignorefscheck, preservetimestamps, force);
  if (r == -1)
    /* do_ntfsclone_out has already called reply_with_error */
    return;

  /* do_ntfsclone_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_RESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_resize_args)))

static void
cleanup_xdr_free_part_resize_args (struct guestfs_part_resize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_resize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_RESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_resize_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_RESIZE_ARGS struct guestfs_part_resize_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int64_t endsect;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_resize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  endsect = args.endsect;

  r = do_part_resize (device, partnum, endsect);
  if (r == -1)
    /* do_part_resize has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_DISK_GUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_disk_guid_args)))

static void
cleanup_xdr_free_part_set_disk_guid_args (struct guestfs_part_set_disk_guid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_disk_guid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_DISK_GUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_disk_guid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_DISK_GUID_ARGS struct guestfs_part_set_disk_guid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
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

  if (!xdr_guestfs_part_set_disk_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  guid = args.guid;

  r = do_part_set_disk_guid (device, guid);
  if (r == -1)
    /* do_part_set_disk_guid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_DISK_GUID_RANDOM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_disk_guid_random_args)))

static void
cleanup_xdr_free_part_set_disk_guid_random_args (struct guestfs_part_set_disk_guid_random_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_disk_guid_random_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_DISK_GUID_RANDOM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_disk_guid_random_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_DISK_GUID_RANDOM_ARGS struct guestfs_part_set_disk_guid_random_args args;
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

  if (!xdr_guestfs_part_set_disk_guid_random_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_part_set_disk_guid_random (device);
  if (r == -1)
    /* do_part_set_disk_guid_random has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PREAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pread_args)))

static void
cleanup_xdr_free_pread_args (struct guestfs_pread_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pread_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PREAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pread_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PREAD_ARGS struct guestfs_pread_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pread_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  count = args.count;
  offset = args.offset;

  NEED_ROOT (false, return);
  r = do_pread (path, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread has already called reply_with_error */
    return;

  struct guestfs_pread_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_REALPATH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_realpath_args)))

static void
cleanup_xdr_free_realpath_args (struct guestfs_realpath_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_realpath_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_REALPATH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
realpath_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_REALPATH_ARGS struct guestfs_realpath_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_realpath_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_realpath (path);
  if (r == NULL)
    /* do_realpath has already called reply_with_error */
    return;

  struct guestfs_realpath_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_realpath_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SELINUX_RELABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_selinux_relabel_args)))

static void
cleanup_xdr_free_selinux_relabel_args (struct guestfs_selinux_relabel_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_selinux_relabel_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SELINUX_RELABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
selinux_relabel_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SELINUX_RELABEL_ARGS struct guestfs_selinux_relabel_args args;
  memset (&args, 0, sizeof args);
  const char *specfile;
  const char *path;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinuxrelabel_available ()) {
    reply_with_unavailable_feature ("selinuxrelabel");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_selinux_relabel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  specfile = args.specfile;
  path = args.path;
  ABS_PATH (path, false, return);
  force = args.force;

  NEED_ROOT (false, return);
  r = do_selinux_relabel (specfile, path, force);
  if (r == -1)
    /* do_selinux_relabel has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPOFF_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapoff_file_args)))

static void
cleanup_xdr_free_swapoff_file_args (struct guestfs_swapoff_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPOFF_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapoff_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPOFF_FILE_ARGS struct guestfs_swapoff_file_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapoff_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_swapoff_file (file);
  if (r == -1)
    /* do_swapoff_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SYSLINUX_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_syslinux_args)))

static void
cleanup_xdr_free_syslinux_args (struct guestfs_syslinux_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_syslinux_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SYSLINUX_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
syslinux_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SYSLINUX_ARGS struct guestfs_syslinux_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_syslinux_available ()) {
    reply_with_unavailable_feature ("syslinux");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_syslinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  directory = args.directory;

  r = do_syslinux (device, directory);
  if (r == -1)
    /* do_syslinux has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TAIL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tail_args)))

static void
cleanup_xdr_free_tail_args (struct guestfs_tail_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tail_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TAIL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tail_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_TAIL_ARGS struct guestfs_tail_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_tail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_tail (path);
  if (r == NULL)
    /* do_tail has already called reply_with_error */
    return;

  struct guestfs_tail_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TOUCH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_touch_args)))

static void
cleanup_xdr_free_touch_args (struct guestfs_touch_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_touch_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TOUCH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
touch_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TOUCH_ARGS struct guestfs_touch_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_touch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TUNE2FS_L_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tune2fs_l_args)))

static void
cleanup_xdr_free_tune2fs_l_args (struct guestfs_tune2fs_l_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TUNE2FS_L_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tune2fs_l_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_TUNE2FS_L_ARGS struct guestfs_tune2fs_l_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_tune2fs_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_tune2fs_l (device);
  if (r == NULL)
    /* do_tune2fs_l has already called reply_with_error */
    return;

  struct guestfs_tune2fs_l_ret ret;
  ret.superblock.superblock_len = guestfs_int_count_strings (r);
  ret.superblock.superblock_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tune2fs_l_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_UMOUNT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_umount_args)))

static void
cleanup_xdr_free_umount_args (struct guestfs_umount_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_umount_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_UMOUNT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
umount_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_UMOUNT_ARGS struct guestfs_umount_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *pathordevice = NULL;
  int force;
  int lazyunmount;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_umount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, false);
  force = args.force;
  lazyunmount = args.lazyunmount;

  r = do_umount (pathordevice, force, lazyunmount);
  if (r == -1)
    /* do_umount has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VG_ACTIVATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vg_activate_args)))

static void
cleanup_xdr_free_vg_activate_args (struct guestfs_vg_activate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VG_ACTIVATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vg_activate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VG_ACTIVATE_ARGS struct guestfs_vg_activate_args args;
  memset (&args, 0, sizeof args);
  int activate;
  char **volgroups;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vg_activate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  activate = args.activate;
  /* Ugly, but safe and avoids copying the strings. */
  volgroups = realloc (args.volgroups.volgroups_val,
                sizeof (char *) * (args.volgroups.volgroups_len+1));
  if (volgroups == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  volgroups[args.volgroups.volgroups_len] = NULL;
  args.volgroups.volgroups_val = volgroups;

  r = do_vg_activate (activate, volgroups);
  if (r == -1)
    /* do_vg_activate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
vgs_full_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_lvm_vg_list *r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_vgs_full ();
  if (r == NULL)
    /* do_vgs_full has already called reply_with_error */
    return;

  struct guestfs_vgs_full_ret ret;
  ret.volgroups = *r;
  reply ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
}

void
vgscan_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_vgscan ();
  if (r == -1)
    /* do_vgscan has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_XFS_ADMIN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_xfs_admin_args)))

static void
cleanup_xdr_free_xfs_admin_args (struct guestfs_xfs_admin_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_admin_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_XFS_ADMIN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
xfs_admin_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_XFS_ADMIN_ARGS struct guestfs_xfs_admin_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int extunwritten;
  int imgfile;
  int v2log;
  int projid32bit;
  int lazycounter;
  const char *label;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff80)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_xfs_admin_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  extunwritten = args.extunwritten;
  imgfile = args.imgfile;
  v2log = args.v2log;
  projid32bit = args.projid32bit;
  lazycounter = args.lazycounter;
  label = args.label;
  uuid = args.uuid;

  r = do_xfs_admin (device, extunwritten, imgfile, v2log, projid32bit, lazycounter, label, uuid);
  if (r == -1)
    /* do_xfs_admin has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
yara_destroy_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_libyara_available ()) {
    reply_with_unavailable_feature ("libyara");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_yara_destroy ();
  if (r == -1)
    /* do_yara_destroy has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZEGREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zegrepi_args)))

static void
cleanup_xdr_free_zegrepi_args (struct guestfs_zegrepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zegrepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZEGREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zegrepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZEGREPI_ARGS struct guestfs_zegrepi_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zegrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zegrepi (regex, path);
  if (r == NULL)
    /* do_zegrepi has already called reply_with_error */
    return;

  struct guestfs_zegrepi_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrepi_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZFGREP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zfgrep_args)))

static void
cleanup_xdr_free_zfgrep_args (struct guestfs_zfgrep_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrep_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZFGREP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zfgrep_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZFGREP_ARGS struct guestfs_zfgrep_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zfgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zfgrep (pattern, path);
  if (r == NULL)
    /* do_zfgrep has already called reply_with_error */
    return;

  struct guestfs_zfgrep_ret ret;
  ret.lines.lines_len = guestfs_int_count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrep_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZFILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zfile_args)))

static void
cleanup_xdr_free_zfile_args (struct guestfs_zfile_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zfile_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZFILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zfile_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_ZFILE_ARGS struct guestfs_zfile_args args;
  memset (&args, 0, sizeof args);
  const char *meth;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zfile_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  meth = args.meth;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zfile (meth, path);
  if (r == NULL)
    /* do_zfile has already called reply_with_error */
    return;

  struct guestfs_zfile_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_zfile_ret, (char *) &ret);
}

