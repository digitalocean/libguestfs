/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

#define CLEANUP_XDR_FREE_ACL_GET_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_acl_get_file_args)))

static void
cleanup_xdr_free_acl_get_file_args (struct guestfs_acl_get_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_acl_get_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ACL_GET_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
acl_get_file_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_ACL_GET_FILE_ARGS struct guestfs_acl_get_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *acltype;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_acl_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  acltype = args.acltype;

  NEED_ROOT (false, return);
  r = do_acl_get_file (path, acltype);
  if (r == NULL)
    /* do_acl_get_file has already called reply_with_error */
    return;

  struct guestfs_acl_get_file_ret ret;
  ret.acl = r;
  reply ((xdrproc_t) &xdr_guestfs_acl_get_file_ret, (char *) &ret);
}

void
aug_close_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_aug_close ();
  if (r == -1)
    /* do_aug_close has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_DEFNODE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_defnode_args)))

static void
cleanup_xdr_free_aug_defnode_args (struct guestfs_aug_defnode_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_DEFNODE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_defnode_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_int_bool *r = NULL;
  CLEANUP_XDR_FREE_AUG_DEFNODE_ARGS struct guestfs_aug_defnode_args args;
  memset (&args, 0, sizeof args);
  const char *name;
  const char *expr;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_defnode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  name = args.name;
  expr = args.expr;
  val = args.val;

  r = do_aug_defnode (name, expr, val);
  if (r == NULL)
    /* do_aug_defnode has already called reply_with_error */
    return;

  struct guestfs_aug_defnode_ret ret;
  ret.nrnodescreated = *r;
  reply ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_GET_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_get_args)))

static void
cleanup_xdr_free_aug_get_args (struct guestfs_aug_get_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_get_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_GET_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_get_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_AUG_GET_ARGS struct guestfs_aug_get_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_get_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_get (augpath);
  if (r == NULL)
    /* do_aug_get has already called reply_with_error */
    return;

  struct guestfs_aug_get_ret ret;
  ret.val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_get_ret, (char *) &ret);
}

void
aug_save_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_aug_save ();
  if (r == -1)
    /* do_aug_save has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_SETM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_setm_args)))

static void
cleanup_xdr_free_aug_setm_args (struct guestfs_aug_setm_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_setm_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_SETM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_setm_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_SETM_ARGS struct guestfs_aug_setm_args args;
  memset (&args, 0, sizeof args);
  const char *base;
  const char *sub;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_setm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  base = args.base;
  sub = args.sub ? *args.sub : NULL;
  val = args.val;

  r = do_aug_setm (base, sub, val);
  if (r == -1)
    /* do_aug_setm has already called reply_with_error */
    return;

  struct guestfs_aug_setm_ret ret;
  ret.nodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_setm_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLKDISCARD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blkdiscard_args)))

static void
cleanup_xdr_free_blkdiscard_args (struct guestfs_blkdiscard_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscard_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLKDISCARD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blkdiscard_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLKDISCARD_ARGS struct guestfs_blkdiscard_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscard_available ()) {
    reply_with_unavailable_feature ("blkdiscard");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blkdiscard_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blkdiscard (device);
  if (r == -1)
    /* do_blkdiscard has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_GETSZ_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_getsz_args)))

static void
cleanup_xdr_free_blockdev_getsz_args (struct guestfs_blockdev_getsz_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_GETSZ_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_getsz_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_BLOCKDEV_GETSZ_ARGS struct guestfs_blockdev_getsz_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_getsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_getsz (device);
  if (r == -1)
    /* do_blockdev_getsz has already called reply_with_error */
    return;

  struct guestfs_blockdev_getsz_ret ret;
  ret.sizeinsectors = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_SETRO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_setro_args)))

static void
cleanup_xdr_free_blockdev_setro_args (struct guestfs_blockdev_setro_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_SETRO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_setro_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_SETRO_ARGS struct guestfs_blockdev_setro_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_setro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_setro (device);
  if (r == -1)
    /* do_blockdev_setro has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_BALANCE_STATUS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_balance_status_args)))

static void
cleanup_xdr_free_btrfs_balance_status_args (struct guestfs_btrfs_balance_status_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_BALANCE_STATUS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_balance_status_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_btrfsbalance *r = NULL;
  CLEANUP_XDR_FREE_BTRFS_BALANCE_STATUS_ARGS struct guestfs_btrfs_balance_status_args args;
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

  if (!xdr_guestfs_btrfs_balance_status_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_balance_status (path);
  if (r == NULL)
    /* do_btrfs_balance_status has already called reply_with_error */
    return;

  struct guestfs_btrfs_balance_status_ret ret;
  ret.status = *r;
  reply ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_DEVICE_DELETE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_device_delete_args)))

static void
cleanup_xdr_free_btrfs_device_delete_args (struct guestfs_btrfs_device_delete_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_delete_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_DEVICE_DELETE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_device_delete_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_DEVICE_DELETE_ARGS struct guestfs_btrfs_device_delete_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
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

  if (!xdr_guestfs_btrfs_device_delete_args (xdr_in, &args)) {
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
  fs = args.fs;
  ABS_PATH (fs, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_device_delete (devices, fs);
  if (r == -1)
    /* do_btrfs_device_delete has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_DEFRAGMENT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_filesystem_defragment_args)))

static void
cleanup_xdr_free_btrfs_filesystem_defragment_args (struct guestfs_btrfs_filesystem_defragment_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_defragment_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_DEFRAGMENT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_filesystem_defragment_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_DEFRAGMENT_ARGS struct guestfs_btrfs_filesystem_defragment_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int flush;
  const char *compress;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_filesystem_defragment_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  flush = args.flush;
  compress = args.compress;

  NEED_ROOT (false, return);
  r = do_btrfs_filesystem_defragment (path, flush, compress);
  if (r == -1)
    /* do_btrfs_filesystem_defragment has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_RESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_filesystem_resize_args)))

static void
cleanup_xdr_free_btrfs_filesystem_resize_args (struct guestfs_btrfs_filesystem_resize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_resize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_RESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_filesystem_resize_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_RESIZE_ARGS struct guestfs_btrfs_filesystem_resize_args args;
  memset (&args, 0, sizeof args);
  const char *mountpoint;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_filesystem_resize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, false, return);
  size = args.size;

  NEED_ROOT (false, return);
  r = do_btrfs_filesystem_resize (mountpoint, size);
  if (r == -1)
    /* do_btrfs_filesystem_resize has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SYNC_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_filesystem_sync_args)))

static void
cleanup_xdr_free_btrfs_filesystem_sync_args (struct guestfs_btrfs_filesystem_sync_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_sync_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SYNC_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_filesystem_sync_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SYNC_ARGS struct guestfs_btrfs_filesystem_sync_args args;
  memset (&args, 0, sizeof args);
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

  if (!xdr_guestfs_btrfs_filesystem_sync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fs = args.fs;
  ABS_PATH (fs, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_filesystem_sync (fs);
  if (r == -1)
    /* do_btrfs_filesystem_sync has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_IMAGE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_image_args)))

static void
cleanup_xdr_free_btrfs_image_args (struct guestfs_btrfs_image_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_image_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_IMAGE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_image_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_IMAGE_ARGS struct guestfs_btrfs_image_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_STRING_LIST char **source = NULL;
  const char *image;
  int compresslevel;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_btrfs_image_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  source = calloc (args.source.source_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.source.source_len; ++i)
      RESOLVE_DEVICE (args.source.source_val[i], source[i], false);
    source[i] = NULL;
  }
  image = args.image;
  ABS_PATH (image, false, return);
  compresslevel = args.compresslevel;

  NEED_ROOT (false, return);
  r = do_btrfs_image (source, image, compresslevel);
  if (r == -1)
    /* do_btrfs_image has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_DESTROY_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_destroy_args)))

static void
cleanup_xdr_free_btrfs_qgroup_destroy_args (struct guestfs_btrfs_qgroup_destroy_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_destroy_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_DESTROY_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_destroy_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_DESTROY_ARGS struct guestfs_btrfs_qgroup_destroy_args args;
  memset (&args, 0, sizeof args);
  const char *qgroupid;
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

  if (!xdr_guestfs_btrfs_qgroup_destroy_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_destroy (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_destroy has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_DELETE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_delete_args)))

static void
cleanup_xdr_free_btrfs_subvolume_delete_args (struct guestfs_btrfs_subvolume_delete_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_delete_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_DELETE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_delete_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_DELETE_ARGS struct guestfs_btrfs_subvolume_delete_args args;
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

  if (!xdr_guestfs_btrfs_subvolume_delete_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_subvolume_delete (subvolume);
  if (r == -1)
    /* do_btrfs_subvolume_delete has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_LIST_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_list_args)))

static void
cleanup_xdr_free_btrfs_subvolume_list_args (struct guestfs_btrfs_subvolume_list_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_LIST_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_list_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_btrfssubvolume_list *r = NULL;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_LIST_ARGS struct guestfs_btrfs_subvolume_list_args args;
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

  if (!xdr_guestfs_btrfs_subvolume_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, false);

  r = do_btrfs_subvolume_list (&fs);
  if (r == NULL)
    /* do_btrfs_subvolume_list has already called reply_with_error */
    return;

  struct guestfs_btrfs_subvolume_list_ret ret;
  ret.subvolumes = *r;
  reply ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfstune_enable_skinny_metadata_extent_refs_args)))

static void
cleanup_xdr_free_btrfstune_enable_skinny_metadata_extent_refs_args (struct guestfs_btrfstune_enable_skinny_metadata_extent_refs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfstune_enable_skinny_metadata_extent_refs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS_ARGS struct guestfs_btrfstune_enable_skinny_metadata_extent_refs_args args;
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

  if (!xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_btrfstune_enable_skinny_metadata_extent_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_skinny_metadata_extent_refs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CAP_GET_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cap_get_file_args)))

static void
cleanup_xdr_free_cap_get_file_args (struct guestfs_cap_get_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cap_get_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CAP_GET_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cap_get_file_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_CAP_GET_FILE_ARGS struct guestfs_cap_get_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_cap_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_cap_get_file (path);
  if (r == NULL)
    /* do_cap_get_file has already called reply_with_error */
    return;

  struct guestfs_cap_get_file_ret ret;
  ret.cap = r;
  reply ((xdrproc_t) &xdr_guestfs_cap_get_file_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CHECKSUM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_checksum_args)))

static void
cleanup_xdr_free_checksum_args (struct guestfs_checksum_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CHECKSUM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
checksum_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_CHECKSUM_ARGS struct guestfs_checksum_args args;
  memset (&args, 0, sizeof args);
  const char *csumtype;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_checksum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  csumtype = args.csumtype;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_checksum (csumtype, path);
  if (r == NULL)
    /* do_checksum has already called reply_with_error */
    return;

  struct guestfs_checksum_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CHMOD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_chmod_args)))

static void
cleanup_xdr_free_chmod_args (struct guestfs_chmod_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_chmod_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CHMOD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
chmod_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CHMOD_ARGS struct guestfs_chmod_args args;
  memset (&args, 0, sizeof args);
  int mode;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_chmod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_chmod (mode, path);
  if (r == -1)
    /* do_chmod has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
dmesg_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_dmesg ();
  if (r == NULL)
    /* do_dmesg has already called reply_with_error */
    return;

  struct guestfs_dmesg_ret ret;
  ret.kmsgs = r;
  reply ((xdrproc_t) &xdr_guestfs_dmesg_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DOWNLOAD_BLOCKS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_download_blocks_args)))

static void
cleanup_xdr_free_download_blocks_args (struct guestfs_download_blocks_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_download_blocks_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DOWNLOAD_BLOCKS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
download_blocks_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DOWNLOAD_BLOCKS_ARGS struct guestfs_download_blocks_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t start;
  int64_t stop;
  int unallocated;

  /* The caller should have checked before calling this. */
  if (! optgroup_sleuthkit_available ()) {
    reply_with_unavailable_feature ("sleuthkit");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_download_blocks_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.device, device, false);
  start = args.start;
  stop = args.stop;
  unallocated = args.unallocated;

  r = do_download_blocks (&device, start, stop, unallocated);
  if (r == -1)
    /* do_download_blocks has already called reply_with_error */
    return;

  /* do_download_blocks has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DU_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_du_args)))

static void
cleanup_xdr_free_du_args (struct guestfs_du_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_du_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DU_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
du_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_DU_ARGS struct guestfs_du_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_du_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_du (path);
  if (r == -1)
    /* do_du has already called reply_with_error */
    return;

  struct guestfs_du_ret ret;
  ret.sizekb = r;
  reply ((xdrproc_t) &xdr_guestfs_du_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_E2FSCK_F_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_e2fsck_f_args)))

static void
cleanup_xdr_free_e2fsck_f_args (struct guestfs_e2fsck_f_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_E2FSCK_F_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
e2fsck_f_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_E2FSCK_F_ARGS struct guestfs_e2fsck_f_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_e2fsck_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_e2fsck_f (device);
  if (r == -1)
    /* do_e2fsck_f has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ECHO_DAEMON_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_echo_daemon_args)))

static void
cleanup_xdr_free_echo_daemon_args (struct guestfs_echo_daemon_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_echo_daemon_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ECHO_DAEMON_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
echo_daemon_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_ECHO_DAEMON_ARGS struct guestfs_echo_daemon_args args;
  memset (&args, 0, sizeof args);
  char **words;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_echo_daemon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  /* Ugly, but safe and avoids copying the strings. */
  words = realloc (args.words.words_val,
                sizeof (char *) * (args.words.words_len+1));
  if (words == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  words[args.words.words_len] = NULL;
  args.words.words_val = words;

  r = do_echo_daemon (words);
  if (r == NULL)
    /* do_echo_daemon has already called reply_with_error */
    return;

  struct guestfs_echo_daemon_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_echo_daemon_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_EQUAL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_equal_args)))

static void
cleanup_xdr_free_equal_args (struct guestfs_equal_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_equal_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_EQUAL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
equal_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_EQUAL_ARGS struct guestfs_equal_args args;
  memset (&args, 0, sizeof args);
  const char *file1;
  const char *file2;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_equal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file1 = args.file1;
  ABS_PATH (file1, false, return);
  file2 = args.file2;
  ABS_PATH (file2, false, return);

  NEED_ROOT (false, return);
  r = do_equal (file1, file2);
  if (r == -1)
    /* do_equal has already called reply_with_error */
    return;

  struct guestfs_equal_ret ret;
  ret.equality = r;
  reply ((xdrproc_t) &xdr_guestfs_equal_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FGREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fgrepi_args)))

static void
cleanup_xdr_free_fgrepi_args (struct guestfs_fgrepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fgrepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FGREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fgrepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_FGREPI_ARGS struct guestfs_fgrepi_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_fgrepi (pattern, path);
  if (r == NULL)
    /* do_fgrepi has already called reply_with_error */
    return;

  struct guestfs_fgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrepi_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GET_E2LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_get_e2label_args)))

static void
cleanup_xdr_free_get_e2label_args (struct guestfs_get_e2label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GET_E2LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
get_e2label_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_GET_E2LABEL_ARGS struct guestfs_get_e2label_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_get_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_get_e2label (device);
  if (r == NULL)
    /* do_get_e2label has already called reply_with_error */
    return;

  struct guestfs_get_e2label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2label_ret, (char *) &ret);
}

void
getcon_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_getcon ();
  if (r == NULL)
    /* do_getcon has already called reply_with_error */
    return;

  struct guestfs_getcon_ret ret;
  ret.context = r;
  reply ((xdrproc_t) &xdr_guestfs_getcon_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_GETXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_getxattr_args)))

static void
cleanup_xdr_free_getxattr_args (struct guestfs_getxattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_getxattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_GETXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
getxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_GETXATTR_ARGS struct guestfs_getxattr_args args;
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

  if (!xdr_guestfs_getxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  name = args.name;

  NEED_ROOT (false, return);
  r = do_getxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_getxattr has already called reply_with_error */
    return;

  struct guestfs_getxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_getxattr_ret, (char *) &ret);
}

void
hivex_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_hivex_close ();
  if (r == -1)
    /* do_hivex_close has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_OPEN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_open_args)))

static void
cleanup_xdr_free_hivex_open_args (struct guestfs_hivex_open_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_open_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_OPEN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_open_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_HIVEX_OPEN_ARGS struct guestfs_hivex_open_args args;
  memset (&args, 0, sizeof args);
  const char *filename;
  int verbose;
  int debug;
  int write;
  int unsafe;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_hivex_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filename = args.filename;
  ABS_PATH (filename, false, return);
  verbose = args.verbose;
  debug = args.debug;
  write = args.write;
  unsafe = args.unsafe;

  NEED_ROOT (false, return);
  r = do_hivex_open (filename, verbose, debug, write, unsafe);
  if (r == -1)
    /* do_hivex_open has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INOTIFY_ADD_WATCH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inotify_add_watch_args)))

static void
cleanup_xdr_free_inotify_add_watch_args (struct guestfs_inotify_add_watch_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INOTIFY_ADD_WATCH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inotify_add_watch_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_INOTIFY_ADD_WATCH_ARGS struct guestfs_inotify_add_watch_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int mask;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inotify_add_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  mask = args.mask;

  NEED_ROOT (false, return);
  r = do_inotify_add_watch (path, mask);
  if (r == -1)
    /* do_inotify_add_watch has already called reply_with_error */
    return;

  struct guestfs_inotify_add_watch_ret ret;
  ret.wd = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INOTIFY_INIT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_inotify_init_args)))

static void
cleanup_xdr_free_inotify_init_args (struct guestfs_inotify_init_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_init_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INOTIFY_INIT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
inotify_init_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INOTIFY_INIT_ARGS struct guestfs_inotify_init_args args;
  memset (&args, 0, sizeof args);
  int maxevents;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_inotify_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  maxevents = args.maxevents;

  r = do_inotify_init (maxevents);
  if (r == -1)
    /* do_inotify_init has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
internal_exit_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_internal_exit ();
  if (r == -1)
    /* do_internal_exit has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_DIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_dir_args)))

static void
cleanup_xdr_free_is_dir_args (struct guestfs_is_dir_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_dir_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_DIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_dir_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_DIR_ARGS struct guestfs_is_dir_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_dir (path, followsymlinks);
  if (r == -1)
    /* do_is_dir has already called reply_with_error */
    return;

  struct guestfs_is_dir_ret ret;
  ret.dirflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_dir_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_file_args)))

static void
cleanup_xdr_free_is_file_args (struct guestfs_is_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_FILE_ARGS struct guestfs_is_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_file (path, followsymlinks);
  if (r == -1)
    /* do_is_file has already called reply_with_error */
    return;

  struct guestfs_is_file_ret ret;
  ret.fileflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_file_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_WHOLE_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_whole_device_args)))

static void
cleanup_xdr_free_is_whole_device_args (struct guestfs_is_whole_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_whole_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_WHOLE_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_whole_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_WHOLE_DEVICE_ARGS struct guestfs_is_whole_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_is_whole_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_is_whole_device (device);
  if (r == -1)
    /* do_is_whole_device has already called reply_with_error */
    return;

  struct guestfs_is_whole_device_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_whole_device_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_ZERO_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_zero_device_args)))

static void
cleanup_xdr_free_is_zero_device_args (struct guestfs_is_zero_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_ZERO_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_zero_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_ZERO_DEVICE_ARGS struct guestfs_is_zero_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_is_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_is_zero_device (device);
  if (r == -1)
    /* do_is_zero_device has already called reply_with_error */
    return;

  struct guestfs_is_zero_device_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_device_ret, (char *) &ret);
}

void
journal_get_realtime_usec_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_journal_get_realtime_usec ();
  if (r == -1)
    /* do_journal_get_realtime_usec has already called reply_with_error */
    return;

  struct guestfs_journal_get_realtime_usec_ret ret;
  ret.usec = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_realtime_usec_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_JOURNAL_SET_DATA_THRESHOLD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_journal_set_data_threshold_args)))

static void
cleanup_xdr_free_journal_set_data_threshold_args (struct guestfs_journal_set_data_threshold_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_journal_set_data_threshold_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_JOURNAL_SET_DATA_THRESHOLD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
journal_set_data_threshold_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_JOURNAL_SET_DATA_THRESHOLD_ARGS struct guestfs_journal_set_data_threshold_args args;
  memset (&args, 0, sizeof args);
  int64_t threshold;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_journal_set_data_threshold_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  threshold = args.threshold;

  r = do_journal_set_data_threshold (threshold);
  if (r == -1)
    /* do_journal_set_data_threshold has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
ldmtool_remove_all_stub (XDR *xdr_in)
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

  r = do_ldmtool_remove_all ();
  if (r == -1)
    /* do_ldmtool_remove_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_HINT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_volume_hint_args)))

static void
cleanup_xdr_free_ldmtool_volume_hint_args (struct guestfs_ldmtool_volume_hint_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_hint_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_HINT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_volume_hint_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_VOLUME_HINT_ARGS struct guestfs_ldmtool_volume_hint_args args;
  memset (&args, 0, sizeof args);
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ldmtool_volume_hint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_hint (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_hint has already called reply_with_error */
    return;

  struct guestfs_ldmtool_volume_hint_ret ret;
  ret.hint = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_hint_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_volume_type_args)))

static void
cleanup_xdr_free_ldmtool_volume_type_args (struct guestfs_ldmtool_volume_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_volume_type_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_VOLUME_TYPE_ARGS struct guestfs_ldmtool_volume_type_args args;
  memset (&args, 0, sizeof args);
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ldmtool_volume_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_type (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_type has already called reply_with_error */
    return;

  struct guestfs_ldmtool_volume_type_ret ret;
  ret.voltype = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_type_ret, (char *) &ret);
}

void
list_devices_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_devices ();
  if (r == NULL)
    /* do_list_devices has already called reply_with_error */
    return;

  struct guestfs_list_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_devices_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LS0_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ls0_args)))

static void
cleanup_xdr_free_ls0_args (struct guestfs_ls0_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ls0_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LS0_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ls0_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LS0_ARGS struct guestfs_ls0_args args;
  memset (&args, 0, sizeof args);
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ls0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dir = args.dir;
  ABS_PATH (dir, false, return);

  NEED_ROOT (false, return);
  r = do_ls0 (dir);
  if (r == -1)
    /* do_ls0 has already called reply_with_error */
    return;

  /* do_ls0 has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LSTATNS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lstatns_args)))

static void
cleanup_xdr_free_lstatns_args (struct guestfs_lstatns_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LSTATNS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lstatns_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_statns *r = NULL;
  CLEANUP_XDR_FREE_LSTATNS_ARGS struct guestfs_lstatns_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lstatns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_lstatns (path);
  if (r == NULL)
    /* do_lstatns has already called reply_with_error */
    return;

  struct guestfs_lstatns_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKDIR_MODE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkdir_mode_args)))

static void
cleanup_xdr_free_mkdir_mode_args (struct guestfs_mkdir_mode_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKDIR_MODE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkdir_mode_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKDIR_MODE_ARGS struct guestfs_mkdir_mode_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int mode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkdir_mode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  mode = args.mode;

  NEED_ROOT (false, return);
  r = do_mkdir_mode (path, mode);
  if (r == -1)
    /* do_mkdir_mode has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKDIR_P_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkdir_p_args)))

static void
cleanup_xdr_free_mkdir_p_args (struct guestfs_mkdir_p_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKDIR_P_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkdir_p_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKDIR_P_ARGS struct guestfs_mkdir_p_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkdir_p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mkdir_p (path);
  if (r == -1)
    /* do_mkdir_p has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2FS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2fs_args)))

static void
cleanup_xdr_free_mke2fs_args (struct guestfs_mke2fs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2FS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2fs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2FS_ARGS struct guestfs_mke2fs_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t blockscount;
  int64_t blocksize;
  int64_t fragsize;
  int64_t blockspergroup;
  int64_t numberofgroups;
  int64_t bytesperinode;
  int64_t inodesize;
  int64_t journalsize;
  int64_t numberofinodes;
  int64_t stridesize;
  int64_t stripewidth;
  int64_t maxonlineresize;
  int reservedblockspercentage;
  int mmpupdateinterval;
  const char *journaldevice;
  const char *label;
  const char *lastmounteddir;
  const char *creatoros;
  const char *fstype;
  const char *usagetype;
  const char *uuid;
  int forcecreate;
  int writesbandgrouponly;
  int lazyitableinit;
  int lazyjournalinit;
  int testfs;
  int discard;
  int quotatype;
  int extent;
  int filetype;
  int flexbg;
  int hasjournal;
  int journaldev;
  int largefile;
  int quota;
  int resizeinode;
  int sparsesuper;
  int uninitbg;

  if (optargs_bitmask & UINT64_C(0xffffffc000000000)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mke2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  blockscount = args.blockscount;
  blocksize = args.blocksize;
  fragsize = args.fragsize;
  blockspergroup = args.blockspergroup;
  numberofgroups = args.numberofgroups;
  bytesperinode = args.bytesperinode;
  inodesize = args.inodesize;
  journalsize = args.journalsize;
  numberofinodes = args.numberofinodes;
  stridesize = args.stridesize;
  stripewidth = args.stripewidth;
  maxonlineresize = args.maxonlineresize;
  reservedblockspercentage = args.reservedblockspercentage;
  mmpupdateinterval = args.mmpupdateinterval;
  journaldevice = args.journaldevice;
  label = args.label;
  lastmounteddir = args.lastmounteddir;
  creatoros = args.creatoros;
  fstype = args.fstype;
  usagetype = args.usagetype;
  uuid = args.uuid;
  forcecreate = args.forcecreate;
  writesbandgrouponly = args.writesbandgrouponly;
  lazyitableinit = args.lazyitableinit;
  lazyjournalinit = args.lazyjournalinit;
  testfs = args.testfs;
  discard = args.discard;
  quotatype = args.quotatype;
  extent = args.extent;
  filetype = args.filetype;
  flexbg = args.flexbg;
  hasjournal = args.hasjournal;
  journaldev = args.journaldev;
  largefile = args.largefile;
  quota = args.quota;
  resizeinode = args.resizeinode;
  sparsesuper = args.sparsesuper;
  uninitbg = args.uninitbg;

  r = do_mke2fs (device, blockscount, blocksize, fragsize, blockspergroup, numberofgroups, bytesperinode, inodesize, journalsize, numberofinodes, stridesize, stripewidth, maxonlineresize, reservedblockspercentage, mmpupdateinterval, journaldevice, label, lastmounteddir, creatoros, fstype, usagetype, uuid, forcecreate, writesbandgrouponly, lazyitableinit, lazyjournalinit, testfs, discard, quotatype, extent, filetype, flexbg, hasjournal, journaldev, largefile, quota, resizeinode, sparsesuper, uninitbg);
  if (r == -1)
    /* do_mke2fs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2FS_JL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2fs_JL_args)))

static void
cleanup_xdr_free_mke2fs_JL_args (struct guestfs_mke2fs_JL_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2FS_JL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2fs_JL_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2FS_JL_ARGS struct guestfs_mke2fs_JL_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2fs_JL_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, false);
  label = args.label;

  r = do_mke2fs_JL (fstype, blocksize, device, label);
  if (r == -1)
    /* do_mke2fs_JL has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2FS_JU_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2fs_JU_args)))

static void
cleanup_xdr_free_mke2fs_JU_args (struct guestfs_mke2fs_JU_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2FS_JU_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2fs_JU_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2FS_JU_ARGS struct guestfs_mke2fs_JU_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2fs_JU_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, false);
  uuid = args.uuid;

  r = do_mke2fs_JU (fstype, blocksize, device, uuid);
  if (r == -1)
    /* do_mke2fs_JU has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKE2JOURNAL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mke2journal_args)))

static void
cleanup_xdr_free_mke2journal_args (struct guestfs_mke2journal_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKE2JOURNAL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mke2journal_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKE2JOURNAL_ARGS struct guestfs_mke2journal_args args;
  memset (&args, 0, sizeof args);
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mke2journal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mke2journal (blocksize, device);
  if (r == -1)
    /* do_mke2journal has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKNOD_B_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mknod_b_args)))

static void
cleanup_xdr_free_mknod_b_args (struct guestfs_mknod_b_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_b_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKNOD_B_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mknod_b_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKNOD_B_ARGS struct guestfs_mknod_b_args args;
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

  if (!xdr_guestfs_mknod_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mknod_b (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_b has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSRESIZE_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfsresize_size_args)))

static void
cleanup_xdr_free_ntfsresize_size_args (struct guestfs_ntfsresize_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSRESIZE_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfsresize_size_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSRESIZE_SIZE_ARGS struct guestfs_ntfsresize_size_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ntfsresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  size = args.size;

  r = do_ntfsresize_size (device, size);
  if (r == -1)
    /* do_ntfsresize_size has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_DEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_del_args)))

static void
cleanup_xdr_free_part_del_args (struct guestfs_part_del_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_del_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_DEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_del_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_DEL_ARGS struct guestfs_part_del_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_del_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_del (device, partnum);
  if (r == -1)
    /* do_part_del has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_GPT_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_gpt_type_args)))

static void
cleanup_xdr_free_part_get_gpt_type_args (struct guestfs_part_get_gpt_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_gpt_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_GPT_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_gpt_type_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_GPT_TYPE_ARGS struct guestfs_part_get_gpt_type_args args;
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

  if (!xdr_guestfs_part_get_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_gpt_type (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_type has already called reply_with_error */
    return;

  struct guestfs_part_get_gpt_type_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_gpt_type_ret, (char *) &ret);
}

void
ping_daemon_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_ping_daemon ();
  if (r == -1)
    /* do_ping_daemon has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rm_args)))

static void
cleanup_xdr_free_rm_args (struct guestfs_rm_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rm_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rm_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RM_ARGS struct guestfs_rm_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_rm (path);
  if (r == -1)
    /* do_rm has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RMDIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rmdir_args)))

static void
cleanup_xdr_free_rmdir_args (struct guestfs_rmdir_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rmdir_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RMDIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rmdir_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RMDIR_ARGS struct guestfs_rmdir_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rmdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_rmdir (path);
  if (r == -1)
    /* do_rmdir has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RSYNC_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rsync_args)))

static void
cleanup_xdr_free_rsync_args (struct guestfs_rsync_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RSYNC_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rsync_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RSYNC_ARGS struct guestfs_rsync_args args;
  memset (&args, 0, sizeof args);
  const char *src;
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

  if (!xdr_guestfs_rsync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (false, return);
  r = do_rsync (src, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_uuid_args)))

static void
cleanup_xdr_free_set_uuid_args (struct guestfs_set_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_UUID_ARGS struct guestfs_set_uuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  uuid = args.uuid;

  r = do_set_uuid (device, uuid);
  if (r == -1)
    /* do_set_uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SETCON_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_setcon_args)))

static void
cleanup_xdr_free_setcon_args (struct guestfs_setcon_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_setcon_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SETCON_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
setcon_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SETCON_ARGS struct guestfs_setcon_args args;
  memset (&args, 0, sizeof args);
  const char *context;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_setcon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  context = args.context;

  r = do_setcon (context);
  if (r == -1)
    /* do_setcon has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_STATVFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_statvfs_args)))

static void
cleanup_xdr_free_statvfs_args (struct guestfs_statvfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_STATVFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
statvfs_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_statvfs *r = NULL;
  CLEANUP_XDR_FREE_STATVFS_ARGS struct guestfs_statvfs_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_statvfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_statvfs (path);
  if (r == NULL)
    /* do_statvfs has already called reply_with_error */
    return;

  struct guestfs_statvfs_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_STRINGS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_strings_args)))

static void
cleanup_xdr_free_strings_args (struct guestfs_strings_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_strings_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_STRINGS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
strings_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_STRINGS_ARGS struct guestfs_strings_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_strings_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_strings (path);
  if (r == NULL)
    /* do_strings has already called reply_with_error */
    return;

  struct guestfs_strings_ret ret;
  ret.stringsout.stringsout_len = count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPOFF_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapoff_label_args)))

static void
cleanup_xdr_free_swapoff_label_args (struct guestfs_swapoff_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPOFF_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapoff_label_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPOFF_LABEL_ARGS struct guestfs_swapoff_label_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapoff_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_swapoff_label (label);
  if (r == -1)
    /* do_swapoff_label has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPOFF_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapoff_uuid_args)))

static void
cleanup_xdr_free_swapoff_uuid_args (struct guestfs_swapoff_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPOFF_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapoff_uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPOFF_UUID_ARGS struct guestfs_swapoff_uuid_args args;
  memset (&args, 0, sizeof args);
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapoff_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  uuid = args.uuid;

  r = do_swapoff_uuid (uuid);
  if (r == -1)
    /* do_swapoff_uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TAR_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tar_in_args)))

static void
cleanup_xdr_free_tar_in_args (struct guestfs_tar_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tar_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TAR_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tar_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TAR_IN_ARGS struct guestfs_tar_in_args args;
  memset (&args, 0, sizeof args);
  const char *directory;
  const char *compress;
  int xattrs;
  int selinux;
  int acls;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    cancel_receive ();
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_tar_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, true, return);
  compress = args.compress;
  xattrs = args.xattrs;
  selinux = args.selinux;
  acls = args.acls;

  NEED_ROOT (true, return);
  r = do_tar_in (directory, compress, xattrs, selinux, acls);
  if (r == -1)
    /* do_tar_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TRUNCATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_truncate_args)))

static void
cleanup_xdr_free_truncate_args (struct guestfs_truncate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TRUNCATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
truncate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TRUNCATE_ARGS struct guestfs_truncate_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_truncate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_truncate (path);
  if (r == -1)
    /* do_truncate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TUNE2FS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tune2fs_args)))

static void
cleanup_xdr_free_tune2fs_args (struct guestfs_tune2fs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TUNE2FS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tune2fs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TUNE2FS_ARGS struct guestfs_tune2fs_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int force;
  int maxmountcount;
  int mountcount;
  const char *errorbehavior;
  int64_t group;
  int intervalbetweenchecks;
  int reservedblockspercentage;
  const char *lastmounteddirectory;
  int64_t reservedblockscount;
  int64_t user;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_tune2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  force = args.force;
  maxmountcount = args.maxmountcount;
  mountcount = args.mountcount;
  errorbehavior = args.errorbehavior;
  group = args.group;
  intervalbetweenchecks = args.intervalbetweenchecks;
  reservedblockspercentage = args.reservedblockspercentage;
  lastmounteddirectory = args.lastmounteddirectory;
  reservedblockscount = args.reservedblockscount;
  user = args.user;

  r = do_tune2fs (device, force, maxmountcount, mountcount, errorbehavior, group, intervalbetweenchecks, reservedblockspercentage, lastmounteddirectory, reservedblockscount, user);
  if (r == -1)
    /* do_tune2fs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_UPLOAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_upload_args)))

static void
cleanup_xdr_free_upload_args (struct guestfs_upload_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_upload_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_UPLOAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
upload_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_UPLOAD_ARGS struct guestfs_upload_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, true);

  r = do_upload (remotefilename);
  if (r == -1)
    /* do_upload has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_UTIMENS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_utimens_args)))

static void
cleanup_xdr_free_utimens_args (struct guestfs_utimens_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_utimens_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_UTIMENS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
utimens_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_UTIMENS_ARGS struct guestfs_utimens_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_utimens_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  atsecs = args.atsecs;
  atnsecs = args.atnsecs;
  mtsecs = args.mtsecs;
  mtnsecs = args.mtnsecs;

  NEED_ROOT (false, return);
  r = do_utimens (path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    /* do_utimens has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VFS_MINIMUM_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vfs_minimum_size_args)))

static void
cleanup_xdr_free_vfs_minimum_size_args (struct guestfs_vfs_minimum_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_minimum_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VFS_MINIMUM_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vfs_minimum_size_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_VFS_MINIMUM_SIZE_ARGS struct guestfs_vfs_minimum_size_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vfs_minimum_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_vfs_minimum_size (&mountable);
  if (r == -1)
    /* do_vfs_minimum_size has already called reply_with_error */
    return;

  struct guestfs_vfs_minimum_size_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_minimum_size_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VFS_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vfs_uuid_args)))

static void
cleanup_xdr_free_vfs_uuid_args (struct guestfs_vfs_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VFS_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vfs_uuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_VFS_UUID_ARGS struct guestfs_vfs_uuid_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vfs_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_vfs_uuid (&mountable);
  if (r == NULL)
    /* do_vfs_uuid has already called reply_with_error */
    return;

  struct guestfs_vfs_uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_uuid_ret, (char *) &ret);
}

void
vgs_stub (XDR *xdr_in)
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

  r = do_vgs ();
  if (r == NULL)
    /* do_vgs has already called reply_with_error */
    return;

  struct guestfs_vgs_ret ret;
  ret.volgroups.volgroups_len = count_strings (r);
  ret.volgroups.volgroups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_WRITE_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_write_file_args)))

static void
cleanup_xdr_free_write_file_args (struct guestfs_write_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_write_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_WRITE_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
write_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_WRITE_FILE_ARGS struct guestfs_write_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *content;
  int size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_write_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  content = args.content;
  size = args.size;

  NEED_ROOT (false, return);
  r = do_write_file (path, content, size);
  if (r == -1)
    /* do_write_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZERO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zero_args)))

static void
cleanup_xdr_free_zero_args (struct guestfs_zero_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zero_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZERO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zero_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ZERO_ARGS struct guestfs_zero_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_zero (device);
  if (r == -1)
    /* do_zero has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZEROFREE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zerofree_args)))

static void
cleanup_xdr_free_zerofree_args (struct guestfs_zerofree_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zerofree_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZEROFREE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zerofree_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ZEROFREE_ARGS struct guestfs_zerofree_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_zerofree_available ()) {
    reply_with_unavailable_feature ("zerofree");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zerofree_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_zerofree (device);
  if (r == -1)
    /* do_zerofree has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZGREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zgrepi_args)))

static void
cleanup_xdr_free_zgrepi_args (struct guestfs_zgrepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zgrepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZGREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zgrepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZGREPI_ARGS struct guestfs_zgrepi_args args;
  memset (&args, 0, sizeof args);
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zgrepi (regex, path);
  if (r == NULL)
    /* do_zgrepi has already called reply_with_error */
    return;

  struct guestfs_zgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrepi_ret, (char *) &ret);
}

