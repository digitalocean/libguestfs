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
list_devices_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_devices ();
  if (r == NULL)
    /* do_list_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_devices_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
vgs_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs ();
  if (r == NULL)
    /* do_vgs has already called reply_with_error */
    goto done;

  struct guestfs_vgs_ret ret;
  ret.volgroups.volgroups_len = count_strings (r);
  ret.volgroups.volgroups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
aug_close_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_close ();
  if (r == -1)
    /* do_aug_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
aug_defnode_stub (XDR *xdr_in)
{
  guestfs_int_int_bool *r;
  struct guestfs_aug_defnode_args args;
  const char *name;
  const char *expr;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defnode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
  expr = args.expr;
  val = args.val;

  r = do_aug_defnode (name, expr, val);
  if (r == NULL)
    /* do_aug_defnode has already called reply_with_error */
    goto done;

  struct guestfs_aug_defnode_ret ret;
  ret.nrnodescreated = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) &args);
done_no_free:
  return;
}

void
aug_get_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_aug_get_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_get_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_get (augpath);
  if (r == NULL)
    /* do_aug_get has already called reply_with_error */
    goto done;

  struct guestfs_aug_get_ret ret;
  ret.val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_get_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_get_args, (char *) &args);
done_no_free:
  return;
}

void
aug_save_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_save ();
  if (r == -1)
    /* do_aug_save has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
rm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm (path);
  if (r == -1)
    /* do_rm has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_args, (char *) &args);
done_no_free:
  return;
}

void
rmdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rmdir_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rmdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rmdir (path);
  if (r == -1)
    /* do_rmdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rmdir_args, (char *) &args);
done_no_free:
  return;
}

void
mkdir_p_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_p_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir_p (path);
  if (r == -1)
    /* do_mkdir_p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) &args);
done_no_free:
  return;
}

void
chmod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chmod_args args;
  int mode;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chmod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chmod (mode, path);
  if (r == -1)
    /* do_chmod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chmod_args, (char *) &args);
done_no_free:
  return;
}

void
is_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_file_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_file (path, followsymlinks);
  if (r == -1)
    /* do_is_file has already called reply_with_error */
    goto done;

  struct guestfs_is_file_ret ret;
  ret.fileflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_file_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_file_args, (char *) &args);
done_no_free:
  return;
}

void
is_dir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_dir_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_dir (path, followsymlinks);
  if (r == -1)
    /* do_is_dir has already called reply_with_error */
    goto done;

  struct guestfs_is_dir_ret ret;
  ret.dirflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_dir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_dir_args, (char *) &args);
done_no_free:
  return;
}

void
write_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_write_file_args args;
  const char *path;
  const char *content;
  int size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_write_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content;
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_write_file (path, content, size);
  if (r == -1)
    /* do_write_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_write_file_args, (char *) &args);
done_no_free:
  return;
}

void
statvfs_stub (XDR *xdr_in)
{
  guestfs_int_statvfs *r;
  struct guestfs_statvfs_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_statvfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statvfs (path);
  if (r == NULL)
    /* do_statvfs has already called reply_with_error */
    goto done;

  struct guestfs_statvfs_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_setro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setro_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_setro (device);
  if (r == -1)
    /* do_blockdev_setro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_getsz_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsz_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getsz (device);
  if (r == -1)
    /* do_blockdev_getsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsz_ret ret;
  ret.sizeinsectors = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) &args);
done_no_free:
  return;
}

void
upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_upload_args args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, cancel_receive (), goto done);

  r = do_upload (remotefilename);
  if (r == -1)
    /* do_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_upload_args, (char *) &args);
done_no_free:
  return;
}

void
checksum_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_checksum_args args;
  const char *csumtype;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksum (csumtype, path);
  if (r == NULL)
    /* do_checksum has already called reply_with_error */
    goto done;

  struct guestfs_checksum_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_args, (char *) &args);
done_no_free:
  return;
}

void
tar_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_in_args args;
  const char *directory;
  const char *compress;
  int xattrs;
  int selinux;
  int acls;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    cancel_receive ();
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);
  compress = args.compress;
  xattrs = args.xattrs;
  selinux = args.selinux;
  acls = args.acls;

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tar_in (directory, compress, xattrs, selinux, acls);
  if (r == -1)
    /* do_tar_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_in_args, (char *) &args);
done_no_free:
  return;
}

void
get_e2label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2label_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_get_e2label (device);
  if (r == NULL)
    /* do_get_e2label has already called reply_with_error */
    goto done;

  struct guestfs_get_e2label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2label_args, (char *) &args);
done_no_free:
  return;
}

void
zero_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zero (device);
  if (r == -1)
    /* do_zero has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_args, (char *) &args);
done_no_free:
  return;
}

void
dmesg_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_dmesg ();
  if (r == NULL)
    /* do_dmesg has already called reply_with_error */
    goto done;

  struct guestfs_dmesg_ret ret;
  ret.kmsgs = r;
  reply ((xdrproc_t) &xdr_guestfs_dmesg_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

void
ping_daemon_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ping_daemon ();
  if (r == -1)
    /* do_ping_daemon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
equal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_equal_args args;
  const char *file1;
  const char *file2;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_equal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file1 = args.file1;
  ABS_PATH (file1, , goto done);
  file2 = args.file2;
  ABS_PATH (file2, , goto done);

  NEED_ROOT (, goto done);
  r = do_equal (file1, file2);
  if (r == -1)
    /* do_equal has already called reply_with_error */
    goto done;

  struct guestfs_equal_ret ret;
  ret.equality = r;
  reply ((xdrproc_t) &xdr_guestfs_equal_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_equal_args, (char *) &args);
done_no_free:
  return;
}

void
strings_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings (path);
  if (r == NULL)
    /* do_strings has already called reply_with_error */
    goto done;

  struct guestfs_strings_ret ret;
  ret.stringsout.stringsout_len = count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_strings_args, (char *) &args);
done_no_free:
  return;
}

void
zerofree_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zerofree_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_zerofree_available ()) {
    reply_with_unavailable_feature ("zerofree");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zerofree_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zerofree (device);
  if (r == -1)
    /* do_zerofree has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zerofree_args, (char *) &args);
done_no_free:
  return;
}

void
e2fsck_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_e2fsck_f_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_e2fsck_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_e2fsck_f (device);
  if (r == -1)
    /* do_e2fsck_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) &args);
done_no_free:
  return;
}

void
du_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_du_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_du_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_du (path);
  if (r == -1)
    /* do_du has already called reply_with_error */
    goto done;

  struct guestfs_du_ret ret;
  ret.sizekb = r;
  reply ((xdrproc_t) &xdr_guestfs_du_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_du_args, (char *) &args);
done_no_free:
  return;
}

void
mknod_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_b_args args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod_b (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_b_args, (char *) &args);
done_no_free:
  return;
}

void
fgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrepi_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrepi (pattern, path);
  if (r == NULL)
    /* do_fgrepi has already called reply_with_error */
    goto done;

  struct guestfs_fgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fgrepi_args, (char *) &args);
done_no_free:
  return;
}

void
zgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrepi (regex, path);
  if (r == NULL)
    /* do_zgrepi has already called reply_with_error */
    goto done;

  struct guestfs_zgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zgrepi_args, (char *) &args);
done_no_free:
  return;
}

void
swapoff_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_swapoff_label (label);
  if (r == -1)
    /* do_swapoff_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) &args);
done_no_free:
  return;
}

void
swapoff_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_uuid_args args;
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

  if (!xdr_guestfs_swapoff_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;

  r = do_swapoff_uuid (uuid);
  if (r == -1)
    /* do_swapoff_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
inotify_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_init_args args;
  int maxevents;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  maxevents = args.maxevents;

  r = do_inotify_init (maxevents);
  if (r == -1)
    /* do_inotify_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_init_args, (char *) &args);
done_no_free:
  return;
}

void
inotify_add_watch_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_inotify_add_watch_args args;
  const char *path;
  int mask;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_add_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  mask = args.mask;

  NEED_ROOT (, goto done);
  r = do_inotify_add_watch (path, mask);
  if (r == -1)
    /* do_inotify_add_watch has already called reply_with_error */
    goto done;

  struct guestfs_inotify_add_watch_ret ret;
  ret.wd = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) &args);
done_no_free:
  return;
}

void
setcon_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setcon_args args;
  const char *context;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_setcon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  context = args.context;

  r = do_setcon (context);
  if (r == -1)
    /* do_setcon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setcon_args, (char *) &args);
done_no_free:
  return;
}

void
getcon_stub (XDR *xdr_in)
{
  char *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_getcon ();
  if (r == NULL)
    /* do_getcon has already called reply_with_error */
    goto done;

  struct guestfs_getcon_ret ret;
  ret.context = r;
  reply ((xdrproc_t) &xdr_guestfs_getcon_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

void
mke2journal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_args args;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mke2journal (blocksize, device);
  if (r == -1)
    /* do_mke2journal has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_args, (char *) &args);
done_no_free:
  return;
}

void
mke2fs_JL_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JL_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_JL_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);
  label = args.label;

  r = do_mke2fs_JL (fstype, blocksize, device, label);
  if (r == -1)
    /* do_mke2fs_JL has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) &args);
done_no_free:
  return;
}

void
mke2fs_JU_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JU_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
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

  if (!xdr_guestfs_mke2fs_JU_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_mke2fs_JU (fstype, blocksize, device, uuid);
  if (r == -1)
    /* do_mke2fs_JU has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) &args);
done_no_free:
  return;
}

void
echo_daemon_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_echo_daemon_args args;
  char **words;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_echo_daemon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  words = realloc (args.words.words_val,
                sizeof (char *) * (args.words.words_len+1));
  if (words == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  words[args.words.words_len] = NULL;
  args.words.words_val = words;

  r = do_echo_daemon (words);
  if (r == NULL)
    /* do_echo_daemon has already called reply_with_error */
    goto done;

  struct guestfs_echo_daemon_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_echo_daemon_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_echo_daemon_args, (char *) &args);
done_no_free:
  return;
}

void
truncate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_truncate (path);
  if (r == -1)
    /* do_truncate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_args, (char *) &args);
done_no_free:
  return;
}

void
utimens_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_utimens_args args;
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_utimens_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  atsecs = args.atsecs;
  atnsecs = args.atnsecs;
  mtsecs = args.mtsecs;
  mtnsecs = args.mtnsecs;

  NEED_ROOT (, goto done);
  r = do_utimens (path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    /* do_utimens has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_utimens_args, (char *) &args);
done_no_free:
  return;
}

void
mkdir_mode_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_mode_args args;
  const char *path;
  int mode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_mode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  mode = args.mode;

  NEED_ROOT (, goto done);
  r = do_mkdir_mode (path, mode);
  if (r == -1)
    /* do_mkdir_mode has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) &args);
done_no_free:
  return;
}

void
part_del_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_del_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_del_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_del (device, partnum);
  if (r == -1)
    /* do_part_del has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_del_args, (char *) &args);
done_no_free:
  return;
}

void
ntfsresize_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsresize_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_ntfsresize_size (device, size);
  if (r == -1)
    /* do_ntfsresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_size_args, (char *) &args);
done_no_free:
  return;
}

void
vfs_uuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_uuid_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_uuid (&mountable);
  if (r == NULL)
    /* do_vfs_uuid has already called reply_with_error */
    goto done;

  struct guestfs_vfs_uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_uuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
getxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_getxattr_args args;
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_getxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  name = args.name;

  NEED_ROOT (, goto done);
  r = do_getxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_getxattr has already called reply_with_error */
    goto done;

  struct guestfs_getxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_getxattr_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_getxattr_args, (char *) &args);
done_no_free:
  return;
}

void
is_zero_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_zero_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_is_zero_device (device);
  if (r == -1)
    /* do_is_zero_device has already called reply_with_error */
    goto done;

  struct guestfs_is_zero_device_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_device_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_filesystem_resize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_resize_args args;
  const char *mountpoint;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_resize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_resize (mountpoint, size);
  if (r == -1)
    /* do_btrfs_filesystem_resize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_resize_args, (char *) &args);
done_no_free:
  return;
}

void
tune2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tune2fs_args args;
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
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tune2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
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
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_subvolume_delete_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_subvolume_delete_args args;
  const char *subvolume;

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

  if (!xdr_guestfs_btrfs_subvolume_delete_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_delete (subvolume);
  if (r == -1)
    /* do_btrfs_subvolume_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_delete_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_subvolume_list_stub (XDR *xdr_in)
{
  guestfs_int_btrfssubvolume_list *r;
  struct guestfs_btrfs_subvolume_list_args args;
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

  if (!xdr_guestfs_btrfs_subvolume_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_subvolume_list (&fs);
  if (r == NULL)
    /* do_btrfs_subvolume_list has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_list_ret ret;
  ret.subvolumes = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_filesystem_sync_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_sync_args args;
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

  if (!xdr_guestfs_btrfs_filesystem_sync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_sync (fs);
  if (r == -1)
    /* do_btrfs_filesystem_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_sync_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_device_delete_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_device_delete_args args;
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

  if (!xdr_guestfs_btrfs_device_delete_args (xdr_in, &args)) {
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
  r = do_btrfs_device_delete (devices, fs);
  if (r == -1)
    /* do_btrfs_device_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_delete_args, (char *) &args);
done_no_free:
  return;
}

void
rsync_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_args args;
  const char *src;
  const char *dest;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rsync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync (src, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_args, (char *) &args);
done_no_free:
  return;
}

void
ls0_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ls0_args args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ls0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_ls0 (dir);
  if (r == -1)
    /* do_ls0 has already called reply_with_error */
    goto done;

  /* do_ls0 has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ls0_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_open_args args;
  const char *filename;
  int verbose;
  int debug;
  int write;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, , goto done);
  verbose = args.verbose;
  debug = args.debug;
  write = args.write;

  NEED_ROOT (, goto done);
  r = do_hivex_open (filename, verbose, debug, write);
  if (r == -1)
    /* do_hivex_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_open_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_close ();
  if (r == -1)
    /* do_hivex_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
mke2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_args args;
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
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
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
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_args, (char *) &args);
done_no_free:
  return;
}

void
acl_get_file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_acl_get_file_args args;
  const char *path;
  const char *acltype;

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

  if (!xdr_guestfs_acl_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  acltype = args.acltype;

  NEED_ROOT (, goto done);
  r = do_acl_get_file (path, acltype);
  if (r == NULL)
    /* do_acl_get_file has already called reply_with_error */
    goto done;

  struct guestfs_acl_get_file_ret ret;
  ret.acl = r;
  reply ((xdrproc_t) &xdr_guestfs_acl_get_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_get_file_args, (char *) &args);
done_no_free:
  return;
}

void
cap_get_file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_cap_get_file_args args;
  const char *path;

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

  if (!xdr_guestfs_cap_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_cap_get_file (path);
  if (r == NULL)
    /* do_cap_get_file has already called reply_with_error */
    goto done;

  struct guestfs_cap_get_file_ret ret;
  ret.cap = r;
  reply ((xdrproc_t) &xdr_guestfs_cap_get_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cap_get_file_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_remove_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_remove_all ();
  if (r == -1)
    /* do_ldmtool_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
ldmtool_volume_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_volume_type_args args;
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

  if (!xdr_guestfs_ldmtool_volume_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_type (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_type has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_type_ret ret;
  ret.voltype = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_type_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_volume_hint_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_volume_hint_args args;
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

  if (!xdr_guestfs_ldmtool_volume_hint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_hint (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_hint has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_hint_ret ret;
  ret.hint = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_hint_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_hint_args, (char *) &args);
done_no_free:
  return;
}

void
part_get_gpt_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_gpt_type_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

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

  if (!xdr_guestfs_part_get_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_gpt_type (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_type has already called reply_with_error */
    goto done;

  struct guestfs_part_get_gpt_type_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_gpt_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_gpt_type_args, (char *) &args);
done_no_free:
  return;
}

void
is_whole_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_whole_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_whole_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_is_whole_device (device);
  if (r == -1)
    /* do_is_whole_device has already called reply_with_error */
    goto done;

  struct guestfs_is_whole_device_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_whole_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_whole_device_args, (char *) &args);
done_no_free:
  return;
}

void
set_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_uuid_args args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_set_uuid (device, uuid);
  if (r == -1)
    /* do_set_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
journal_set_data_threshold_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_journal_set_data_threshold_args args;
  int64_t threshold;

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

  if (!xdr_guestfs_journal_set_data_threshold_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  threshold = args.threshold;

  r = do_journal_set_data_threshold (threshold);
  if (r == -1)
    /* do_journal_set_data_threshold has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_set_data_threshold_args, (char *) &args);
done_no_free:
  return;
}

void
aug_setm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_setm_args args;
  const char *base;
  const char *sub;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_setm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  base = args.base;
  sub = args.sub ? *args.sub : NULL;
  val = args.val;

  r = do_aug_setm (base, sub, val);
  if (r == -1)
    /* do_aug_setm has already called reply_with_error */
    goto done;

  struct guestfs_aug_setm_ret ret;
  ret.nodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_setm_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_setm_args, (char *) &args);
done_no_free:
  return;
}

void
internal_exit_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_exit ();
  if (r == -1)
    /* do_internal_exit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
blkdiscard_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blkdiscard_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscard_available ()) {
    reply_with_unavailable_feature ("blkdiscard");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blkdiscard_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blkdiscard (device);
  if (r == -1)
    /* do_blkdiscard has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscard_args, (char *) &args);
done_no_free:
  return;
}

void
journal_get_realtime_usec_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_get_realtime_usec ();
  if (r == -1)
    /* do_journal_get_realtime_usec has already called reply_with_error */
    goto done;

  struct guestfs_journal_get_realtime_usec_ret ret;
  ret.usec = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_realtime_usec_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
lstatns_stub (XDR *xdr_in)
{
  guestfs_int_statns *r;
  struct guestfs_lstatns_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lstatns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lstatns (path);
  if (r == NULL)
    /* do_lstatns has already called reply_with_error */
    goto done;

  struct guestfs_lstatns_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_destroy_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_destroy_args args;
  const char *qgroupid;
  const char *subvolume;

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

  if (!xdr_guestfs_btrfs_qgroup_destroy_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_destroy (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_destroy has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_destroy_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_filesystem_defragment_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_defragment_args args;
  const char *path;
  int flush;
  const char *compress;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_defragment_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  flush = args.flush;
  compress = args.compress;

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_defragment (path, flush, compress);
  if (r == -1)
    /* do_btrfs_filesystem_defragment has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_defragment_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_balance_status_stub (XDR *xdr_in)
{
  guestfs_int_btrfsbalance *r;
  struct guestfs_btrfs_balance_status_args args;
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

  if (!xdr_guestfs_btrfs_balance_status_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_status (path);
  if (r == NULL)
    /* do_btrfs_balance_status has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_balance_status_ret ret;
  ret.status = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_args, (char *) &args);
done_no_free:
  return;
}

void
btrfstune_enable_skinny_metadata_extent_refs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_enable_skinny_metadata_extent_refs_args args;
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

  if (!xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfstune_enable_skinny_metadata_extent_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_skinny_metadata_extent_refs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_image_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_image_args args;
  CLEANUP_FREE_STRING_LIST char **source = NULL;
  const char *image;
  int compresslevel;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_image_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  source = calloc (args.source.source_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.source.source_len; ++i)
      RESOLVE_DEVICE (args.source.source_val[i], source[i],
                      , goto done);
    source[i] = NULL;
  }
  image = args.image;
  ABS_PATH (image, , goto done);
  compresslevel = args.compresslevel;

  NEED_ROOT (, goto done);
  r = do_btrfs_image (source, image, compresslevel);
  if (r == -1)
    /* do_btrfs_image has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_image_args, (char *) &args);
done_no_free:
  return;
}

void
vfs_minimum_size_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_vfs_minimum_size_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_minimum_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_minimum_size (&mountable);
  if (r == -1)
    /* do_vfs_minimum_size has already called reply_with_error */
    goto done;

  struct guestfs_vfs_minimum_size_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_minimum_size_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_minimum_size_args, (char *) &args);
done_no_free:
  return;
}

void
download_blocks_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_blocks_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t start;
  int64_t stop;
  int unallocated;

  /* The caller should have checked before calling this. */
  if (! optgroup_sleuthkit_available ()) {
    reply_with_unavailable_feature ("sleuthkit");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_blocks_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.device, device, , goto done);
  start = args.start;
  stop = args.stop;
  unallocated = args.unallocated;

  r = do_download_blocks (&device, start, stop, unallocated);
  if (r == -1)
    /* do_download_blocks has already called reply_with_error */
    goto done;

  /* do_download_blocks has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_blocks_args, (char *) &args);
done_no_free:
  return;
}

