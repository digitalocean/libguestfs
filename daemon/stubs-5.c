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

#define CLEANUP_XDR_FREE_ACL_SET_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_acl_set_file_args)))

static void
cleanup_xdr_free_acl_set_file_args (struct guestfs_acl_set_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_acl_set_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ACL_SET_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
acl_set_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ACL_SET_FILE_ARGS struct guestfs_acl_set_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *acltype;
  const char *acl;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_acl_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  acltype = args.acltype;
  acl = args.acl;

  NEED_ROOT (false, return);
  r = do_acl_set_file (path, acltype, acl);
  if (r == -1)
    /* do_acl_set_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_FLUSHBUFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_flushbufs_args)))

static void
cleanup_xdr_free_blockdev_flushbufs_args (struct guestfs_blockdev_flushbufs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_FLUSHBUFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_flushbufs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_FLUSHBUFS_ARGS struct guestfs_blockdev_flushbufs_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_flushbufs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_flushbufs (device);
  if (r == -1)
    /* do_blockdev_flushbufs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BLOCKDEV_SETRW_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_blockdev_setrw_args)))

static void
cleanup_xdr_free_blockdev_setrw_args (struct guestfs_blockdev_setrw_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BLOCKDEV_SETRW_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
blockdev_setrw_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BLOCKDEV_SETRW_ARGS struct guestfs_blockdev_setrw_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_blockdev_setrw_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_blockdev_setrw (device);
  if (r == -1)
    /* do_blockdev_setrw has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_BALANCE_PAUSE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_balance_pause_args)))

static void
cleanup_xdr_free_btrfs_balance_pause_args (struct guestfs_btrfs_balance_pause_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_pause_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_BALANCE_PAUSE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_balance_pause_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_BALANCE_PAUSE_ARGS struct guestfs_btrfs_balance_pause_args args;
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

  if (!xdr_guestfs_btrfs_balance_pause_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_balance_pause (path);
  if (r == -1)
    /* do_btrfs_balance_pause has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_DEVICE_ADD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_device_add_args)))

static void
cleanup_xdr_free_btrfs_device_add_args (struct guestfs_btrfs_device_add_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_add_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_DEVICE_ADD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_device_add_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_DEVICE_ADD_ARGS struct guestfs_btrfs_device_add_args args;
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

  if (!xdr_guestfs_btrfs_device_add_args (xdr_in, &args)) {
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
  r = do_btrfs_device_add (devices, fs);
  if (r == -1)
    /* do_btrfs_device_add has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_BALANCE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_filesystem_balance_args)))

static void
cleanup_xdr_free_btrfs_filesystem_balance_args (struct guestfs_btrfs_filesystem_balance_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_balance_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_BALANCE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_filesystem_balance_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_BALANCE_ARGS struct guestfs_btrfs_filesystem_balance_args args;
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

  if (!xdr_guestfs_btrfs_filesystem_balance_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fs = args.fs;
  ABS_PATH (fs, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_filesystem_balance (fs);
  if (r == -1)
    /* do_btrfs_filesystem_balance has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SHOW_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_filesystem_show_args)))

static void
cleanup_xdr_free_btrfs_filesystem_show_args (struct guestfs_btrfs_filesystem_show_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_show_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SHOW_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_filesystem_show_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_BTRFS_FILESYSTEM_SHOW_ARGS struct guestfs_btrfs_filesystem_show_args args;
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

  if (!xdr_guestfs_btrfs_filesystem_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_btrfs_filesystem_show (device);
  if (r == NULL)
    /* do_btrfs_filesystem_show has already called reply_with_error */
    return;

  struct guestfs_btrfs_filesystem_show_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_filesystem_show_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_ASSIGN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_assign_args)))

static void
cleanup_xdr_free_btrfs_qgroup_assign_args (struct guestfs_btrfs_qgroup_assign_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_assign_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_ASSIGN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_assign_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_ASSIGN_ARGS struct guestfs_btrfs_qgroup_assign_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_assign_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_assign (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_assign has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_REPLACE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_replace_args)))

static void
cleanup_xdr_free_btrfs_replace_args (struct guestfs_btrfs_replace_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_replace_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_REPLACE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_replace_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_REPLACE_ARGS struct guestfs_btrfs_replace_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *srcdev = NULL;
  CLEANUP_FREE char *targetdev = NULL;
  const char *mntpoint;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_btrfs_replace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.srcdev, srcdev, false);
  RESOLVE_DEVICE (args.targetdev, targetdev, false);
  mntpoint = args.mntpoint;
  ABS_PATH (mntpoint, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_replace (srcdev, targetdev, mntpoint);
  if (r == -1)
    /* do_btrfs_replace has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SCRUB_CANCEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_scrub_cancel_args)))

static void
cleanup_xdr_free_btrfs_scrub_cancel_args (struct guestfs_btrfs_scrub_cancel_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_cancel_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SCRUB_CANCEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_scrub_cancel_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_SCRUB_CANCEL_ARGS struct guestfs_btrfs_scrub_cancel_args args;
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

  if (!xdr_guestfs_btrfs_scrub_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_scrub_cancel (path);
  if (r == -1)
    /* do_btrfs_scrub_cancel has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_GET_DEFAULT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_subvolume_get_default_args)))

static void
cleanup_xdr_free_btrfs_subvolume_get_default_args (struct guestfs_btrfs_subvolume_get_default_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_get_default_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_GET_DEFAULT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_subvolume_get_default_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_BTRFS_SUBVOLUME_GET_DEFAULT_ARGS struct guestfs_btrfs_subvolume_get_default_args args;
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

  if (!xdr_guestfs_btrfs_subvolume_get_default_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, false);

  r = do_btrfs_subvolume_get_default (&fs);
  if (r == -1)
    /* do_btrfs_subvolume_get_default has already called reply_with_error */
    return;

  struct guestfs_btrfs_subvolume_get_default_ret ret;
  ret.id = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_get_default_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFSTUNE_SEEDING_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfstune_seeding_args)))

static void
cleanup_xdr_free_btrfstune_seeding_args (struct guestfs_btrfstune_seeding_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_seeding_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFSTUNE_SEEDING_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfstune_seeding_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFSTUNE_SEEDING_ARGS struct guestfs_btrfstune_seeding_args args;
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

  if (!xdr_guestfs_btrfstune_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  seeding = args.seeding;

  r = do_btrfstune_seeding (device, seeding);
  if (r == -1)
    /* do_btrfstune_seeding has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CAP_SET_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cap_set_file_args)))

static void
cleanup_xdr_free_cap_set_file_args (struct guestfs_cap_set_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cap_set_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CAP_SET_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cap_set_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CAP_SET_FILE_ARGS struct guestfs_cap_set_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *cap;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_cap_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  cap = args.cap;

  NEED_ROOT (false, return);
  r = do_cap_set_file (path, cap);
  if (r == -1)
    /* do_cap_set_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_FILE_TO_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_file_to_device_args)))

static void
cleanup_xdr_free_copy_file_to_device_args (struct guestfs_copy_file_to_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_FILE_TO_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_file_to_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_FILE_TO_DEVICE_ARGS struct guestfs_copy_file_to_device_args args;
  memset (&args, 0, sizeof args);
  const char *src;
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

  if (!xdr_guestfs_copy_file_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  RESOLVE_DEVICE (args.dest, dest, false);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (false, return);
  r = do_copy_file_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COPY_FILE_TO_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_copy_file_to_file_args)))

static void
cleanup_xdr_free_copy_file_to_file_args (struct guestfs_copy_file_to_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COPY_FILE_TO_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
copy_file_to_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COPY_FILE_TO_FILE_ARGS struct guestfs_copy_file_to_file_args args;
  memset (&args, 0, sizeof args);
  const char *src;
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

  if (!xdr_guestfs_copy_file_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (false, return);
  r = do_copy_file_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CPIO_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cpio_out_args)))

static void
cleanup_xdr_free_cpio_out_args (struct guestfs_cpio_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cpio_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CPIO_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cpio_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CPIO_OUT_ARGS struct guestfs_cpio_out_args args;
  memset (&args, 0, sizeof args);
  const char *directory;
  const char *format;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_cpio_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  format = args.format;

  r = do_cpio_out (directory, format);
  if (r == -1)
    /* do_cpio_out has already called reply_with_error */
    return;

  /* do_cpio_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_DOWNLOAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_download_args)))

static void
cleanup_xdr_free_download_args (struct guestfs_download_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_download_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_DOWNLOAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
download_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_DOWNLOAD_ARGS struct guestfs_download_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_download_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, false);

  r = do_download (remotefilename);
  if (r == -1)
    /* do_download has already called reply_with_error */
    return;

  /* do_download has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FILL_PATTERN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fill_pattern_args)))

static void
cleanup_xdr_free_fill_pattern_args (struct guestfs_fill_pattern_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fill_pattern_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FILL_PATTERN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fill_pattern_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FILL_PATTERN_ARGS struct guestfs_fill_pattern_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fill_pattern_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  len = args.len;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_fill_pattern (pattern, len, path);
  if (r == -1)
    /* do_fill_pattern has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FIND0_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_find0_args)))

static void
cleanup_xdr_free_find0_args (struct guestfs_find0_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_find0_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FIND0_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
find0_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FIND0_ARGS struct guestfs_find0_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_find0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_find0 (directory);
  if (r == -1)
    /* do_find0 has already called reply_with_error */
    return;

  /* do_find0 has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HEAD_N_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_head_n_args)))

static void
cleanup_xdr_free_head_n_args (struct guestfs_head_n_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_head_n_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HEAD_N_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
head_n_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_HEAD_N_ARGS struct guestfs_head_n_args args;
  memset (&args, 0, sizeof args);
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_head_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_head_n (nrlines, path);
  if (r == NULL)
    /* do_head_n has already called reply_with_error */
    return;

  struct guestfs_head_n_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_n_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_COMMIT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_commit_args)))

static void
cleanup_xdr_free_hivex_commit_args (struct guestfs_hivex_commit_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_commit_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_COMMIT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_commit_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_HIVEX_COMMIT_ARGS struct guestfs_hivex_commit_args args;
  memset (&args, 0, sizeof args);
  const char *filename;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_commit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  filename = args.filename ? *args.filename : NULL;

  r = do_hivex_commit (filename);
  if (r == -1)
    /* do_hivex_commit has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_DELETE_CHILD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_delete_child_args)))

static void
cleanup_xdr_free_hivex_node_delete_child_args (struct guestfs_hivex_node_delete_child_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_delete_child_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_DELETE_CHILD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_delete_child_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_HIVEX_NODE_DELETE_CHILD_ARGS struct guestfs_hivex_node_delete_child_args args;
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

  if (!xdr_guestfs_hivex_node_delete_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_delete_child (nodeh);
  if (r == -1)
    /* do_hivex_node_delete_child has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INITRD_CAT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_initrd_cat_args)))

static void
cleanup_xdr_free_initrd_cat_args (struct guestfs_initrd_cat_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INITRD_CAT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
initrd_cat_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_INITRD_CAT_ARGS struct guestfs_initrd_cat_args args;
  memset (&args, 0, sizeof args);
  const char *initrdpath;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_initrd_cat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  initrdpath = args.initrdpath;
  ABS_PATH (initrdpath, false, return);
  filename = args.filename;

  NEED_ROOT (false, return);
  r = do_initrd_cat (initrdpath, filename, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_initrd_cat has already called reply_with_error */
    return;

  struct guestfs_initrd_cat_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_initrd_cat_ret, (char *) &ret);
}

void
inotify_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_inotify_close ();
  if (r == -1)
    /* do_inotify_close has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_UPLOAD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_upload_args)))

static void
cleanup_xdr_free_internal_upload_args (struct guestfs_internal_upload_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_upload_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_UPLOAD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_upload_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_UPLOAD_ARGS struct guestfs_internal_upload_args args;
  memset (&args, 0, sizeof args);
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  tmpname = args.tmpname;
  mode = args.mode;

  r = do_internal_upload (tmpname, mode);
  if (r == -1)
    /* do_internal_upload has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_WRITE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_write_args)))

static void
cleanup_xdr_free_internal_write_args (struct guestfs_internal_write_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_WRITE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_write_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_WRITE_ARGS struct guestfs_internal_write_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_write_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (false, return);
  r = do_internal_write (path, content, content_size);
  if (r == -1)
    /* do_internal_write has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_WRITE_APPEND_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_write_append_args)))

static void
cleanup_xdr_free_internal_write_append_args (struct guestfs_internal_write_append_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_append_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_WRITE_APPEND_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_write_append_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_WRITE_APPEND_ARGS struct guestfs_internal_write_append_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_write_append_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (false, return);
  r = do_internal_write_append (path, content, content_size);
  if (r == -1)
    /* do_internal_write_append has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_BLOCKDEV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_blockdev_args)))

static void
cleanup_xdr_free_is_blockdev_args (struct guestfs_is_blockdev_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_blockdev_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_BLOCKDEV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_blockdev_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_BLOCKDEV_ARGS struct guestfs_is_blockdev_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_blockdev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_blockdev (path, followsymlinks);
  if (r == -1)
    /* do_is_blockdev has already called reply_with_error */
    return;

  struct guestfs_is_blockdev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_blockdev_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_IS_FIFO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_is_fifo_args)))

static void
cleanup_xdr_free_is_fifo_args (struct guestfs_is_fifo_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_is_fifo_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_IS_FIFO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
is_fifo_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_IS_FIFO_ARGS struct guestfs_is_fifo_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_is_fifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (false, return);
  r = do_is_fifo (path, followsymlinks);
  if (r == -1)
    /* do_is_fifo has already called reply_with_error */
    return;

  struct guestfs_is_fifo_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_fifo_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ISOINFO_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_isoinfo_device_args)))

static void
cleanup_xdr_free_isoinfo_device_args (struct guestfs_isoinfo_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ISOINFO_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
isoinfo_device_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_isoinfo *r = NULL;
  CLEANUP_XDR_FREE_ISOINFO_DEVICE_ARGS struct guestfs_isoinfo_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_isoinfo_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_isoinfo_device (device);
  if (r == NULL)
    /* do_isoinfo_device has already called reply_with_error */
    return;

  struct guestfs_isoinfo_device_ret ret;
  ret.isodata = *r;
  reply ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
}

void
journal_next_stub (XDR *xdr_in)
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

  r = do_journal_next ();
  if (r == -1)
    /* do_journal_next has already called reply_with_error */
    return;

  struct guestfs_journal_next_ret ret;
  ret.more = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_next_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_JOURNAL_SKIP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_journal_skip_args)))

static void
cleanup_xdr_free_journal_skip_args (struct guestfs_journal_skip_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_journal_skip_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_JOURNAL_SKIP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
journal_skip_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_JOURNAL_SKIP_ARGS struct guestfs_journal_skip_args args;
  memset (&args, 0, sizeof args);
  int64_t skip;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_journal_skip_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  skip = args.skip;

  r = do_journal_skip (skip);
  if (r == -1)
    /* do_journal_skip has already called reply_with_error */
    return;

  struct guestfs_journal_skip_ret ret;
  ret.rskip = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_skip_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_PARTITIONS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_volume_partitions_args)))

static void
cleanup_xdr_free_ldmtool_volume_partitions_args (struct guestfs_ldmtool_volume_partitions_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_partitions_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_VOLUME_PARTITIONS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_volume_partitions_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_VOLUME_PARTITIONS_ARGS struct guestfs_ldmtool_volume_partitions_args args;
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

  if (!xdr_guestfs_ldmtool_volume_partitions_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_partitions (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_partitions has already called reply_with_error */
    return;

  struct guestfs_ldmtool_volume_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_partitions_ret, (char *) &ret);
}

void
list_disk_labels_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_disk_labels ();
  if (r == NULL)
    /* do_list_disk_labels has already called reply_with_error */
    return;

  struct guestfs_list_disk_labels_ret ret;
  ret.labels.labels_len = count_strings (r);
  ret.labels.labels_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_disk_labels_ret, (char *) &ret);
}

void
list_md_devices_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_list_md_devices ();
  if (r == NULL)
    /* do_list_md_devices has already called reply_with_error */
    return;

  struct guestfs_list_md_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_md_devices_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ln_args)))

static void
cleanup_xdr_free_ln_args (struct guestfs_ln_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ln_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ln_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LN_ARGS struct guestfs_ln_args args;
  memset (&args, 0, sizeof args);
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ln_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, false, return);

  NEED_ROOT (false, return);
  r = do_ln (target, linkname);
  if (r == -1)
    /* do_ln has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LN_SF_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ln_sf_args)))

static void
cleanup_xdr_free_ln_sf_args (struct guestfs_ln_sf_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ln_sf_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LN_SF_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ln_sf_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LN_SF_ARGS struct guestfs_ln_sf_args args;
  memset (&args, 0, sizeof args);
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ln_sf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, false, return);

  NEED_ROOT (false, return);
  r = do_ln_sf (target, linkname);
  if (r == -1)
    /* do_ln_sf has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_ADD_KEY_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_add_key_args)))

static void
cleanup_xdr_free_luks_add_key_args (struct guestfs_luks_add_key_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_add_key_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_ADD_KEY_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_add_key_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_ADD_KEY_ARGS struct guestfs_luks_add_key_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *newkey;
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

  if (!xdr_guestfs_luks_add_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  key = args.key;
  newkey = args.newkey;
  keyslot = args.keyslot;

  r = do_luks_add_key (device, key, newkey, keyslot);
  if (r == -1)
    /* do_luks_add_key has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVCREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvcreate_args)))

static void
cleanup_xdr_free_lvcreate_args (struct guestfs_lvcreate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVCREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvcreate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVCREATE_ARGS struct guestfs_lvcreate_args args;
  memset (&args, 0, sizeof args);
  const char *logvol;
  const char *volgroup;
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

  if (!xdr_guestfs_lvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  mbytes = args.mbytes;

  r = do_lvcreate (logvol, volgroup, mbytes);
  if (r == -1)
    /* do_lvcreate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVCREATE_FREE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvcreate_free_args)))

static void
cleanup_xdr_free_lvcreate_free_args (struct guestfs_lvcreate_free_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_free_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVCREATE_FREE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvcreate_free_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVCREATE_FREE_ARGS struct guestfs_lvcreate_free_args args;
  memset (&args, 0, sizeof args);
  const char *logvol;
  const char *volgroup;
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

  if (!xdr_guestfs_lvcreate_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  percent = args.percent;

  r = do_lvcreate_free (logvol, volgroup, percent);
  if (r == -1)
    /* do_lvcreate_free has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVM_SET_FILTER_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvm_set_filter_args)))

static void
cleanup_xdr_free_lvm_set_filter_args (struct guestfs_lvm_set_filter_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvm_set_filter_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVM_SET_FILTER_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvm_set_filter_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVM_SET_FILTER_ARGS struct guestfs_lvm_set_filter_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_lvm_set_filter_args (xdr_in, &args)) {
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

  r = do_lvm_set_filter (devices);
  if (r == -1)
    /* do_lvm_set_filter has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
lvs_full_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_lvm_lv_list *r = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_lvs_full ();
  if (r == NULL)
    /* do_lvs_full has already called reply_with_error */
    return;

  struct guestfs_lvs_full_ret ret;
  ret.logvols = *r;
  reply ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MD_STAT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_md_stat_args)))

static void
cleanup_xdr_free_md_stat_args (struct guestfs_md_stat_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MD_STAT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
md_stat_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_mdstat_list *r = NULL;
  CLEANUP_XDR_FREE_MD_STAT_ARGS struct guestfs_md_stat_args args;
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

  if (!xdr_guestfs_md_stat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.md, md, false);

  r = do_md_stat (md);
  if (r == NULL)
    /* do_md_stat has already called reply_with_error */
    return;

  struct guestfs_md_stat_ret ret;
  ret.devices = *r;
  reply ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkfs_args)))

static void
cleanup_xdr_free_mkfs_args (struct guestfs_mkfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkfs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKFS_ARGS struct guestfs_mkfs_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  CLEANUP_FREE char *device = NULL;
  int blocksize;
  const char *features;
  int inode;
  int sectorsize;
  const char *label;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mkfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, false);
  blocksize = args.blocksize;
  features = args.features;
  inode = args.inode;
  sectorsize = args.sectorsize;
  label = args.label;

  r = do_mkfs (fstype, device, blocksize, features, inode, sectorsize, label);
  if (r == -1)
    /* do_mkfs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKFS_B_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkfs_b_args)))

static void
cleanup_xdr_free_mkfs_b_args (struct guestfs_mkfs_b_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKFS_B_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkfs_b_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKFS_B_ARGS struct guestfs_mkfs_b_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkfs_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mkfs_b (fstype, blocksize, device);
  if (r == -1)
    /* do_mkfs_b has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKSWAP_U_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkswap_U_args)))

static void
cleanup_xdr_free_mkswap_U_args (struct guestfs_mkswap_U_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKSWAP_U_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkswap_U_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKSWAP_U_ARGS struct guestfs_mkswap_U_args args;
  memset (&args, 0, sizeof args);
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

  if (!xdr_guestfs_mkswap_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  uuid = args.uuid;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_mkswap_U (uuid, device);
  if (r == -1)
    /* do_mkswap_U has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
mountpoints_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_mountpoints ();
  if (r == NULL)
    /* do_mountpoints has already called reply_with_error */
    return;

  struct guestfs_mountpoints_ret ret;
  ret.mps.mps_len = count_strings (r);
  ret.mps.mps_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mountpoints_ret, (char *) &ret);
}

void
nr_devices_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_nr_devices ();
  if (r == -1)
    /* do_nr_devices has already called reply_with_error */
    return;

  struct guestfs_nr_devices_ret ret;
  ret.nrdisks = r;
  reply ((xdrproc_t) &xdr_guestfs_nr_devices_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSCLONE_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfsclone_in_args)))

static void
cleanup_xdr_free_ntfsclone_in_args (struct guestfs_ntfsclone_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSCLONE_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfsclone_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSCLONE_IN_ARGS struct guestfs_ntfsclone_in_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("ntfs3g");
    return;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ntfsclone_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, true);

  r = do_ntfsclone_in (device);
  if (r == -1)
    /* do_ntfsclone_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_BOOTABLE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_bootable_args)))

static void
cleanup_xdr_free_part_get_bootable_args (struct guestfs_part_get_bootable_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_bootable_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_BOOTABLE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_bootable_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_GET_BOOTABLE_ARGS struct guestfs_part_get_bootable_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;

  r = do_part_get_bootable (device, partnum);
  if (r == -1)
    /* do_part_get_bootable has already called reply_with_error */
    return;

  struct guestfs_part_get_bootable_ret ret;
  ret.bootable = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_bootable_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_GPT_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_gpt_type_args)))

static void
cleanup_xdr_free_part_set_gpt_type_args (struct guestfs_part_set_gpt_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_GPT_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_gpt_type_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_GPT_TYPE_ARGS struct guestfs_part_set_gpt_type_args args;
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

  if (!xdr_guestfs_part_set_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_type (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_type has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_SET_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_set_name_args)))

static void
cleanup_xdr_free_part_set_name_args (struct guestfs_part_set_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_SET_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_set_name_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_SET_NAME_ARGS struct guestfs_part_set_name_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *name;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_set_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  name = args.name;

  r = do_part_set_name (device, partnum, name);
  if (r == -1)
    /* do_part_set_name has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVREMOVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvremove_args)))

static void
cleanup_xdr_free_pvremove_args (struct guestfs_pvremove_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvremove_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVREMOVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvremove_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PVREMOVE_ARGS struct guestfs_pvremove_args args;
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

  if (!xdr_guestfs_pvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_pvremove (device);
  if (r == -1)
    /* do_pvremove has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SCRUB_FREESPACE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_scrub_freespace_args)))

static void
cleanup_xdr_free_scrub_freespace_args (struct guestfs_scrub_freespace_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SCRUB_FREESPACE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
scrub_freespace_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SCRUB_FREESPACE_ARGS struct guestfs_scrub_freespace_args args;
  memset (&args, 0, sizeof args);
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_scrub_freespace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dir = args.dir;
  ABS_PATH (dir, false, return);

  NEED_ROOT (false, return);
  r = do_scrub_freespace (dir);
  if (r == -1)
    /* do_scrub_freespace has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SET_UUID_RANDOM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_set_uuid_random_args)))

static void
cleanup_xdr_free_set_uuid_random_args (struct guestfs_set_uuid_random_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_random_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SET_UUID_RANDOM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
set_uuid_random_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SET_UUID_RANDOM_ARGS struct guestfs_set_uuid_random_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_set_uuid_random_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_set_uuid_random (device);
  if (r == -1)
    /* do_set_uuid_random has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdisk_args)))

static void
cleanup_xdr_free_sfdisk_args (struct guestfs_sfdisk_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdisk_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SFDISK_ARGS struct guestfs_sfdisk_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdisk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdisk (device, cyls, heads, sectors, lines);
  if (r == -1)
    /* do_sfdisk has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISKM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdiskM_args)))

static void
cleanup_xdr_free_sfdiskM_args (struct guestfs_sfdiskM_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISKM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdiskM_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SFDISKM_ARGS struct guestfs_sfdiskM_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdiskM_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    return;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdiskM (device, lines);
  if (r == -1)
    /* do_sfdiskM has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISK_N_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdisk_N_args)))

static void
cleanup_xdr_free_sfdisk_N_args (struct guestfs_sfdisk_N_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISK_N_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdisk_N_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SFDISK_N_ARGS struct guestfs_sfdisk_N_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdisk_N_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  partnum = args.partnum;
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  line = args.line;

  r = do_sfdisk_N (device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    /* do_sfdisk_N has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPOFF_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapoff_device_args)))

static void
cleanup_xdr_free_swapoff_device_args (struct guestfs_swapoff_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPOFF_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapoff_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPOFF_DEVICE_ARGS struct guestfs_swapoff_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapoff_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_swapoff_device (device);
  if (r == -1)
    /* do_swapoff_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPON_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapon_device_args)))

static void
cleanup_xdr_free_swapon_device_args (struct guestfs_swapon_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPON_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapon_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPON_DEVICE_ARGS struct guestfs_swapon_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_swapon_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_swapon_device (device);
  if (r == -1)
    /* do_swapon_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SWAPON_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_swapon_uuid_args)))

static void
cleanup_xdr_free_swapon_uuid_args (struct guestfs_swapon_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SWAPON_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
swapon_uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SWAPON_UUID_ARGS struct guestfs_swapon_uuid_args args;
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

  if (!xdr_guestfs_swapon_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  uuid = args.uuid;

  r = do_swapon_uuid (uuid);
  if (r == -1)
    /* do_swapon_uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TGZ_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_tgz_in_args)))

static void
cleanup_xdr_free_tgz_in_args (struct guestfs_tgz_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TGZ_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
tgz_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TGZ_IN_ARGS struct guestfs_tgz_in_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_tgz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, true, return);

  NEED_ROOT (true, return);
  r = do_tgz_in (directory);
  if (r == -1)
    /* do_tgz_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TRUNCATE_SIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_truncate_size_args)))

static void
cleanup_xdr_free_truncate_size_args (struct guestfs_truncate_size_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_size_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TRUNCATE_SIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
truncate_size_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TRUNCATE_SIZE_ARGS struct guestfs_truncate_size_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_truncate_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  size = args.size;

  NEED_ROOT (false, return);
  r = do_truncate_size (path, size);
  if (r == -1)
    /* do_truncate_size has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_TXZ_IN_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_txz_in_args)))

static void
cleanup_xdr_free_txz_in_args (struct guestfs_txz_in_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_txz_in_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_TXZ_IN_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
txz_in_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_TXZ_IN_ARGS struct guestfs_txz_in_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("xz");
    return;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_txz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, true, return);

  NEED_ROOT (true, return);
  r = do_txz_in (directory);
  if (r == -1)
    /* do_txz_in has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGCHANGE_UUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgchange_uuid_args)))

static void
cleanup_xdr_free_vgchange_uuid_args (struct guestfs_vgchange_uuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgchange_uuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGCHANGE_UUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgchange_uuid_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VGCHANGE_UUID_ARGS struct guestfs_vgchange_uuid_args args;
  memset (&args, 0, sizeof args);
  const char *vg;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vgchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vg = args.vg;

  r = do_vgchange_uuid (vg);
  if (r == -1)
    /* do_vgchange_uuid has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGLVUUIDS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vglvuuids_args)))

static void
cleanup_xdr_free_vglvuuids_args (struct guestfs_vglvuuids_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vglvuuids_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGLVUUIDS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vglvuuids_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_VGLVUUIDS_ARGS struct guestfs_vglvuuids_args args;
  memset (&args, 0, sizeof args);
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vglvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vgname = args.vgname;

  r = do_vglvuuids (vgname);
  if (r == NULL)
    /* do_vglvuuids has already called reply_with_error */
    return;

  struct guestfs_vglvuuids_ret ret;
  ret.uuids.uuids_len = count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vglvuuids_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGREMOVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgremove_args)))

static void
cleanup_xdr_free_vgremove_args (struct guestfs_vgremove_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgremove_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGREMOVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgremove_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VGREMOVE_ARGS struct guestfs_vgremove_args args;
  memset (&args, 0, sizeof args);
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vgremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vgname = args.vgname;

  r = do_vgremove (vgname);
  if (r == -1)
    /* do_vgremove has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_WC_L_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_wc_l_args)))

static void
cleanup_xdr_free_wc_l_args (struct guestfs_wc_l_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_wc_l_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_WC_L_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
wc_l_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_WC_L_ARGS struct guestfs_wc_l_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_wc_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_wc_l (path);
  if (r == -1)
    /* do_wc_l has already called reply_with_error */
    return;

  struct guestfs_wc_l_ret ret;
  ret.lines = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_l_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_XFS_GROWFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_xfs_growfs_args)))

static void
cleanup_xdr_free_xfs_growfs_args (struct guestfs_xfs_growfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_growfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_XFS_GROWFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
xfs_growfs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_XFS_GROWFS_ARGS struct guestfs_xfs_growfs_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  int datasec;
  int logsec;
  int rtsec;
  int64_t datasize;
  int64_t logsize;
  int64_t rtsize;
  int64_t rtextsize;
  int maxpct;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_xfs_growfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  datasec = args.datasec;
  logsec = args.logsec;
  rtsec = args.rtsec;
  datasize = args.datasize;
  logsize = args.logsize;
  rtsize = args.rtsize;
  rtextsize = args.rtextsize;
  maxpct = args.maxpct;

  NEED_ROOT (false, return);
  r = do_xfs_growfs (path, datasec, logsec, rtsec, datasize, logsize, rtsize, rtextsize, maxpct);
  if (r == -1)
    /* do_xfs_growfs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_XFS_INFO_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_xfs_info_args)))

static void
cleanup_xdr_free_xfs_info_args (struct guestfs_xfs_info_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_XFS_INFO_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
xfs_info_stub (XDR *xdr_in)
{
  CLEANUP_FREE guestfs_int_xfsinfo *r = NULL;
  CLEANUP_XDR_FREE_XFS_INFO_ARGS struct guestfs_xfs_info_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *pathordevice = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_xfs_info_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, false);

  r = do_xfs_info (pathordevice);
  if (r == NULL)
    /* do_xfs_info has already called reply_with_error */
    return;

  struct guestfs_xfs_info_ret ret;
  ret.info = *r;
  reply ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_XFS_REPAIR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_xfs_repair_args)))

static void
cleanup_xdr_free_xfs_repair_args (struct guestfs_xfs_repair_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_repair_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_XFS_REPAIR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
xfs_repair_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_XFS_REPAIR_ARGS struct guestfs_xfs_repair_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int forcelogzero;
  int nomodify;
  int noprefetch;
  int forcegeometry;
  int64_t maxmem;
  int64_t ihashsize;
  int64_t bhashsize;
  int64_t agstride;
  const char *logdev;
  const char *rtdev;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_xfs_repair_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.device, device, false);
  forcelogzero = args.forcelogzero;
  nomodify = args.nomodify;
  noprefetch = args.noprefetch;
  forcegeometry = args.forcegeometry;
  maxmem = args.maxmem;
  ihashsize = args.ihashsize;
  bhashsize = args.bhashsize;
  agstride = args.agstride;
  logdev = args.logdev;
  rtdev = args.rtdev;

  r = do_xfs_repair (device, forcelogzero, nomodify, noprefetch, forcegeometry, maxmem, ihashsize, bhashsize, agstride, logdev, rtdev);
  if (r == -1)
    /* do_xfs_repair has already called reply_with_error */
    return;

  struct guestfs_xfs_repair_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_xfs_repair_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZERO_DEVICE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zero_device_args)))

static void
cleanup_xdr_free_zero_device_args (struct guestfs_zero_device_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zero_device_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZERO_DEVICE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zero_device_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ZERO_DEVICE_ARGS struct guestfs_zero_device_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_zero_device (device);
  if (r == -1)
    /* do_zero_device has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZERO_FREE_SPACE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zero_free_space_args)))

static void
cleanup_xdr_free_zero_free_space_args (struct guestfs_zero_free_space_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zero_free_space_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZERO_FREE_SPACE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zero_free_space_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ZERO_FREE_SPACE_ARGS struct guestfs_zero_free_space_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zero_free_space_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_zero_free_space (directory);
  if (r == -1)
    /* do_zero_free_space has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

