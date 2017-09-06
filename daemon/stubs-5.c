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

void
acl_set_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_acl_set_file_args args;
  const char *path;
  const char *acltype;
  const char *acl;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_acl_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  acltype = args.acltype;
  acl = args.acl;

  NEED_ROOT (, goto done);
  r = do_acl_set_file (path, acltype, acl);
  if (r == -1)
    /* do_acl_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_set_file_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_flushbufs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_flushbufs_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_flushbufs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_flushbufs (device);
  if (r == -1)
    /* do_blockdev_flushbufs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_setrw_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setrw_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setrw_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_setrw (device);
  if (r == -1)
    /* do_blockdev_setrw has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_balance_pause_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_pause_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_balance_pause_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_pause (path);
  if (r == -1)
    /* do_btrfs_balance_pause has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_pause_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_device_add_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_device_add_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_device_add_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_device_add (devices, fs);
  if (r == -1)
    /* do_btrfs_device_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_add_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_filesystem_balance_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_balance_args args;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_balance_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_balance (fs);
  if (r == -1)
    /* do_btrfs_filesystem_balance has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_balance_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_filesystem_show_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_btrfs_filesystem_show_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfs_filesystem_show (device);
  if (r == NULL)
    /* do_btrfs_filesystem_show has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_filesystem_show_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_filesystem_show_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_show_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_assign_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_assign_args args;
  const char *src;
  const char *dst;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_assign_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_assign (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_assign has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_assign_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_replace_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_replace_args args;
  CLEANUP_FREE char *srcdev = NULL;
  CLEANUP_FREE char *targetdev = NULL;
  const char *mntpoint;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_replace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.srcdev, srcdev, , goto done);
  RESOLVE_DEVICE (args.targetdev, targetdev, , goto done);
  mntpoint = args.mntpoint;
  ABS_PATH (mntpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_replace (srcdev, targetdev, mntpoint);
  if (r == -1)
    /* do_btrfs_replace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_replace_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_scrub_cancel_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_scrub_cancel_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_scrub_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_cancel (path);
  if (r == -1)
    /* do_btrfs_scrub_cancel has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_cancel_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_subvolume_get_default_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_btrfs_subvolume_get_default_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_get_default_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_subvolume_get_default (&fs);
  if (r == -1)
    /* do_btrfs_subvolume_get_default has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_get_default_ret ret;
  ret.id = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_get_default_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_get_default_args, (char *) &args);
done_no_free:
  return;
}

void
btrfstune_seeding_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_seeding_args args;
  CLEANUP_FREE char *device = NULL;
  int seeding;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfstune_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  seeding = args.seeding;

  r = do_btrfstune_seeding (device, seeding);
  if (r == -1)
    /* do_btrfstune_seeding has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_seeding_args, (char *) &args);
done_no_free:
  return;
}

void
cap_set_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cap_set_file_args args;
  const char *path;
  const char *cap;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cap_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  cap = args.cap;

  NEED_ROOT (, goto done);
  r = do_cap_set_file (path, cap);
  if (r == -1)
    /* do_cap_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cap_set_file_args, (char *) &args);
done_no_free:
  return;
}

void
copy_file_to_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_file_to_device_args args;
  const char *src;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_file_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  RESOLVE_DEVICE (args.dest, dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_device_args, (char *) &args);
done_no_free:
  return;
}

void
copy_file_to_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_file_to_file_args args;
  const char *src;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_file_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_file_args, (char *) &args);
done_no_free:
  return;
}

void
cpio_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cpio_out_args args;
  const char *directory;
  const char *format;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cpio_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  format = args.format;

  r = do_cpio_out (directory, format);
  if (r == -1)
    /* do_cpio_out has already called reply_with_error */
    goto done;

  /* do_cpio_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cpio_out_args, (char *) &args);
done_no_free:
  return;
}

void
download_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_args args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, , goto done);

  r = do_download (remotefilename);
  if (r == -1)
    /* do_download has already called reply_with_error */
    goto done;

  /* do_download has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_args, (char *) &args);
done_no_free:
  return;
}

void
fill_pattern_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_pattern_args args;
  const char *pattern;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_pattern_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  len = args.len;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill_pattern (pattern, len, path);
  if (r == -1)
    /* do_fill_pattern has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_pattern_args, (char *) &args);
done_no_free:
  return;
}

void
find0_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_find0_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_find0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_find0 (directory);
  if (r == -1)
    /* do_find0 has already called reply_with_error */
    goto done;

  /* do_find0 has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
done_no_free:
  return;
}

void
head_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_n_args args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head_n (nrlines, path);
  if (r == NULL)
    /* do_head_n has already called reply_with_error */
    goto done;

  struct guestfs_head_n_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_n_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_head_n_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_commit_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_commit_args args;
  const char *filename;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_commit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename ? *args.filename : NULL;

  r = do_hivex_commit (filename);
  if (r == -1)
    /* do_hivex_commit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_commit_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_delete_child_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_node_delete_child_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_delete_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_delete_child (nodeh);
  if (r == -1)
    /* do_hivex_node_delete_child has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_delete_child_args, (char *) &args);
done_no_free:
  return;
}

void
initrd_cat_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_initrd_cat_args args;
  const char *initrdpath;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_cat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  initrdpath = args.initrdpath;
  ABS_PATH (initrdpath, , goto done);
  filename = args.filename;

  NEED_ROOT (, goto done);
  r = do_initrd_cat (initrdpath, filename, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_initrd_cat has already called reply_with_error */
    goto done;

  struct guestfs_initrd_cat_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_initrd_cat_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) &args);
done_no_free:
  return;
}

void
inotify_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_close ();
  if (r == -1)
    /* do_inotify_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
internal_upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_upload_args args;
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpname = args.tmpname;
  mode = args.mode;

  r = do_internal_upload (tmpname, mode);
  if (r == -1)
    /* do_internal_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_upload_args, (char *) &args);
done_no_free:
  return;
}

void
internal_write_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_write_args args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_write_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (, goto done);
  r = do_internal_write (path, content, content_size);
  if (r == -1)
    /* do_internal_write has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_args, (char *) &args);
done_no_free:
  return;
}

void
internal_write_append_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_write_append_args args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_write_append_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (, goto done);
  r = do_internal_write_append (path, content, content_size);
  if (r == -1)
    /* do_internal_write_append has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_append_args, (char *) &args);
done_no_free:
  return;
}

void
is_blockdev_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_blockdev_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_blockdev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_blockdev (path, followsymlinks);
  if (r == -1)
    /* do_is_blockdev has already called reply_with_error */
    goto done;

  struct guestfs_is_blockdev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_blockdev_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_blockdev_args, (char *) &args);
done_no_free:
  return;
}

void
is_fifo_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_fifo_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_fifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_fifo (path, followsymlinks);
  if (r == -1)
    /* do_is_fifo has already called reply_with_error */
    goto done;

  struct guestfs_is_fifo_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_fifo_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_fifo_args, (char *) &args);
done_no_free:
  return;
}

void
isoinfo_device_stub (XDR *xdr_in)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_isoinfo_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_isoinfo_device (device);
  if (r == NULL)
    /* do_isoinfo_device has already called reply_with_error */
    goto done;

  struct guestfs_isoinfo_device_ret ret;
  ret.isodata = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_args, (char *) &args);
done_no_free:
  return;
}

void
journal_next_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_next ();
  if (r == -1)
    /* do_journal_next has already called reply_with_error */
    goto done;

  struct guestfs_journal_next_ret ret;
  ret.more = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_next_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
journal_skip_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_journal_skip_args args;
  int64_t skip;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_journal_skip_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  skip = args.skip;

  r = do_journal_skip (skip);
  if (r == -1)
    /* do_journal_skip has already called reply_with_error */
    goto done;

  struct guestfs_journal_skip_ret ret;
  ret.rskip = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_skip_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_skip_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_volume_partitions_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_volume_partitions_args args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_volume_partitions_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_partitions (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_partitions has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_partitions_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_partitions_args, (char *) &args);
done_no_free:
  return;
}

void
list_disk_labels_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_disk_labels ();
  if (r == NULL)
    /* do_list_disk_labels has already called reply_with_error */
    goto done;

  struct guestfs_list_disk_labels_ret ret;
  ret.labels.labels_len = count_strings (r);
  ret.labels.labels_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_disk_labels_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
list_md_devices_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_md_devices ();
  if (r == NULL)
    /* do_list_md_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_md_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_md_devices_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
ln_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln (target, linkname);
  if (r == -1)
    /* do_ln has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
done_no_free:
  return;
}

void
ln_sf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_sf_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_sf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_sf (target, linkname);
  if (r == -1)
    /* do_ln_sf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
done_no_free:
  return;
}

void
luks_add_key_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_add_key_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *newkey;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_add_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  newkey = args.newkey;
  keyslot = args.keyslot;

  r = do_luks_add_key (device, key, newkey, keyslot);
  if (r == -1)
    /* do_luks_add_key has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_add_key_args, (char *) &args);
done_no_free:
  return;
}

void
lvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvcreate_args args;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  mbytes = args.mbytes;

  r = do_lvcreate (logvol, volgroup, mbytes);
  if (r == -1)
    /* do_lvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
done_no_free:
  return;
}

void
lvcreate_free_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvcreate_free_args args;
  const char *logvol;
  const char *volgroup;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvcreate_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  percent = args.percent;

  r = do_lvcreate_free (logvol, volgroup, percent);
  if (r == -1)
    /* do_lvcreate_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_free_args, (char *) &args);
done_no_free:
  return;
}

void
lvm_set_filter_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvm_set_filter_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvm_set_filter_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }

  r = do_lvm_set_filter (devices);
  if (r == -1)
    /* do_lvm_set_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvm_set_filter_args, (char *) &args);
done_no_free:
  return;
}

void
lvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_lv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvs_full ();
  if (r == NULL)
    /* do_lvs_full has already called reply_with_error */
    goto done;

  struct guestfs_lvs_full_ret ret;
  ret.logvols = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
md_stat_stub (XDR *xdr_in)
{
  guestfs_int_mdstat_list *r;
  struct guestfs_md_stat_args args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_stat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_stat (md);
  if (r == NULL)
    /* do_md_stat has already called reply_with_error */
    goto done;

  struct guestfs_md_stat_ret ret;
  ret.devices = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_args, (char *) &args);
done_no_free:
  return;
}

void
mkfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_args args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;
  int blocksize;
  const char *features;
  int inode;
  int sectorsize;
  const char *label;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, , goto done);
  blocksize = args.blocksize;
  features = args.features;
  inode = args.inode;
  sectorsize = args.sectorsize;
  label = args.label;

  r = do_mkfs (fstype, device, blocksize, features, inode, sectorsize, label);
  if (r == -1)
    /* do_mkfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
done_no_free:
  return;
}

void
mkfs_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_b_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkfs_b (fstype, blocksize, device);
  if (r == -1)
    /* do_mkfs_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
done_no_free:
  return;
}

void
mkswap_U_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_U_args args;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkswap_U (uuid, device);
  if (r == -1)
    /* do_mkswap_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
done_no_free:
  return;
}

void
mountpoints_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mountpoints ();
  if (r == NULL)
    /* do_mountpoints has already called reply_with_error */
    goto done;

  struct guestfs_mountpoints_ret ret;
  ret.mps.mps_len = count_strings (r);
  ret.mps.mps_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mountpoints_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
nr_devices_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_nr_devices ();
  if (r == -1)
    /* do_nr_devices has already called reply_with_error */
    goto done;

  struct guestfs_nr_devices_ret ret;
  ret.nrdisks = r;
  reply ((xdrproc_t) &xdr_guestfs_nr_devices_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
ntfsclone_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsclone_in_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsclone_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, cancel_receive (), goto done);

  r = do_ntfsclone_in (device);
  if (r == -1)
    /* do_ntfsclone_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_in_args, (char *) &args);
done_no_free:
  return;
}

void
part_get_bootable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_get_bootable_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_bootable (device, partnum);
  if (r == -1)
    /* do_part_get_bootable has already called reply_with_error */
    goto done;

  struct guestfs_part_get_bootable_ret ret;
  ret.bootable = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_bootable_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_bootable_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_gpt_type_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_gpt_type_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *guid;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_type (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_type has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_type_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_name_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_name_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *name;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  name = args.name;

  r = do_part_set_name (device, partnum, name);
  if (r == -1)
    /* do_part_set_name has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
done_no_free:
  return;
}

void
pvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvremove_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvremove (device);
  if (r == -1)
    /* do_pvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
done_no_free:
  return;
}

void
scrub_freespace_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_freespace_args args;
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_freespace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_freespace (dir);
  if (r == -1)
    /* do_scrub_freespace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
done_no_free:
  return;
}

void
set_uuid_random_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_uuid_random_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_uuid_random_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_set_uuid_random (device);
  if (r == -1)
    /* do_set_uuid_random has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_random_args, (char *) &args);
done_no_free:
  return;
}

void
sfdisk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_args args;
  CLEANUP_FREE char *device = NULL;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdisk (device, cyls, heads, sectors, lines);
  if (r == -1)
    /* do_sfdisk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_args, (char *) &args);
done_no_free:
  return;
}

void
sfdiskM_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdiskM_args args;
  CLEANUP_FREE char *device = NULL;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdiskM_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdiskM (device, lines);
  if (r == -1)
    /* do_sfdiskM has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) &args);
done_no_free:
  return;
}

void
sfdisk_N_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_N_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_N_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  line = args.line;

  r = do_sfdisk_N (device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    /* do_sfdisk_N has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
done_no_free:
  return;
}

void
swapoff_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_swapoff_device (device);
  if (r == -1)
    /* do_swapoff_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
done_no_free:
  return;
}

void
swapon_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_swapon_device (device);
  if (r == -1)
    /* do_swapon_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
done_no_free:
  return;
}

void
swapon_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_uuid_args args;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;

  r = do_swapon_uuid (uuid);
  if (r == -1)
    /* do_swapon_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
tgz_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tgz_in_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tgz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tgz_in (directory);
  if (r == -1)
    /* do_tgz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
done_no_free:
  return;
}

void
truncate_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_size_args args;
  const char *path;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_truncate_size (path, size);
  if (r == -1)
    /* do_truncate_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
done_no_free:
  return;
}

void
txz_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_txz_in_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_txz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_txz_in (directory);
  if (r == -1)
    /* do_txz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_txz_in_args, (char *) &args);
done_no_free:
  return;
}

void
vgchange_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgchange_uuid_args args;
  const char *vg;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vg = args.vg;

  r = do_vgchange_uuid (vg);
  if (r == -1)
    /* do_vgchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgchange_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
vglvuuids_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_vglvuuids_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vglvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vglvuuids (vgname);
  if (r == NULL)
    /* do_vglvuuids has already called reply_with_error */
    goto done;

  struct guestfs_vglvuuids_ret ret;
  ret.uuids.uuids_len = count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vglvuuids_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vglvuuids_args, (char *) &args);
done_no_free:
  return;
}

void
vgremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgremove_args args;
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgremove (vgname);
  if (r == -1)
    /* do_vgremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
done_no_free:
  return;
}

void
wc_l_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_l_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_l (path);
  if (r == -1)
    /* do_wc_l has already called reply_with_error */
    goto done;

  struct guestfs_wc_l_ret ret;
  ret.lines = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_l_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
done_no_free:
  return;
}

void
xfs_growfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_growfs_args args;
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
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_growfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  datasec = args.datasec;
  logsec = args.logsec;
  rtsec = args.rtsec;
  datasize = args.datasize;
  logsize = args.logsize;
  rtsize = args.rtsize;
  rtextsize = args.rtextsize;
  maxpct = args.maxpct;

  NEED_ROOT (, goto done);
  r = do_xfs_growfs (path, datasec, logsec, rtsec, datasize, logsize, rtsize, rtextsize, maxpct);
  if (r == -1)
    /* do_xfs_growfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_growfs_args, (char *) &args);
done_no_free:
  return;
}

void
xfs_info_stub (XDR *xdr_in)
{
  guestfs_int_xfsinfo *r;
  struct guestfs_xfs_info_args args;
  CLEANUP_FREE char *pathordevice = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_info_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, , goto done);

  r = do_xfs_info (pathordevice);
  if (r == NULL)
    /* do_xfs_info has already called reply_with_error */
    goto done;

  struct guestfs_xfs_info_ret ret;
  ret.info = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_args, (char *) &args);
done_no_free:
  return;
}

void
xfs_repair_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_repair_args args;
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
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_repair_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.device, device, , goto done);
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
    goto done;

  struct guestfs_xfs_repair_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_xfs_repair_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_repair_args, (char *) &args);
done_no_free:
  return;
}

void
zero_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zero_device (device);
  if (r == -1)
    /* do_zero_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_device_args, (char *) &args);
done_no_free:
  return;
}

void
zero_free_space_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_free_space_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_free_space_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_zero_free_space (directory);
  if (r == -1)
    /* do_zero_free_space has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_free_space_args, (char *) &args);
done_no_free:
  return;
}

