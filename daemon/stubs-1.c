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
aug_clear_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_clear_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_clear_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_clear (augpath);
  if (r == -1)
    /* do_aug_clear has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_clear_args, (char *) &args);
done_no_free:
  return;
}

void
aug_defvar_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_defvar_args args;
  const char *name;
  const char *expr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defvar_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
  expr = args.expr ? *args.expr : NULL;

  r = do_aug_defvar (name, expr);
  if (r == -1)
    /* do_aug_defvar has already called reply_with_error */
    goto done;

  struct guestfs_aug_defvar_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_defvar_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
done_no_free:
  return;
}

void
base64_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_base64_in_args args;
  const char *filename;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_base64_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_base64_in (filename);
  if (r == -1)
    /* do_base64_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_base64_in_args, (char *) &args);
done_no_free:
  return;
}

void
base64_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_base64_out_args args;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_base64_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, , goto done);

  NEED_ROOT (, goto done);
  r = do_base64_out (filename);
  if (r == -1)
    /* do_base64_out has already called reply_with_error */
    goto done;

  /* do_base64_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_base64_out_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_balance_resume_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_resume_args args;
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

  if (!xdr_guestfs_btrfs_balance_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_resume (path);
  if (r == -1)
    /* do_btrfs_balance_resume has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_resume_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_fsck_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t superblock;
  int repair;

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

  if (!xdr_guestfs_btrfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  superblock = args.superblock;
  repair = args.repair;

  r = do_btrfs_fsck (device, superblock, repair);
  if (r == -1)
    /* do_btrfs_fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_fsck_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_show_stub (XDR *xdr_in)
{
  guestfs_int_btrfsqgroup_list *r;
  struct guestfs_btrfs_qgroup_show_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_show (path);
  if (r == NULL)
    /* do_btrfs_qgroup_show has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_qgroup_show_ret ret;
  ret.qgroups = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_rescue_chunk_recover_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_rescue_chunk_recover_args args;
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

  if (!xdr_guestfs_btrfs_rescue_chunk_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfs_rescue_chunk_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_chunk_recover has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_chunk_recover_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_scrub_resume_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_scrub_resume_args args;
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

  if (!xdr_guestfs_btrfs_scrub_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_resume (path);
  if (r == -1)
    /* do_btrfs_scrub_resume has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_resume_args, (char *) &args);
done_no_free:
  return;
}

void
checksum_device_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_checksum_device_args args;
  const char *csumtype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksum_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_checksum_device (csumtype, device);
  if (r == NULL)
    /* do_checksum_device has already called reply_with_error */
    goto done;

  struct guestfs_checksum_device_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_device_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_device_args, (char *) &args);
done_no_free:
  return;
}

void
copy_attributes_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_attributes_args args;
  const char *src;
  const char *dest;
  int all;
  int mode;
  int xattributes;
  int ownership;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_attributes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  all = args.all;
  mode = args.mode;
  xattributes = args.xattributes;
  ownership = args.ownership;

  NEED_ROOT (, goto done);
  r = do_copy_attributes (src, dest, all, mode, xattributes, ownership);
  if (r == -1)
    /* do_copy_attributes has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_attributes_args, (char *) &args);
done_no_free:
  return;
}

void
copy_device_to_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_device_to_device_args args;
  CLEANUP_FREE char *src = NULL;
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

  if (!xdr_guestfs_copy_device_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.src, src, , goto done);
  RESOLVE_DEVICE (args.dest, dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  r = do_copy_device_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) &args);
done_no_free:
  return;
}

void
dd_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_dd_args args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_dd_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.src, src, , goto done);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.dest, dest, , goto done);

  r = do_dd (src, dest);
  if (r == -1)
    /* do_dd has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
done_no_free:
  return;
}

void
device_index_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_device_index_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_device_index_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_device_index (device);
  if (r == -1)
    /* do_device_index has already called reply_with_error */
    goto done;

  struct guestfs_device_index_ret ret;
  ret.index = r;
  reply ((xdrproc_t) &xdr_guestfs_device_index_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_device_index_args, (char *) &args);
done_no_free:
  return;
}

void
download_inode_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_inode_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  /* The caller should have checked before calling this. */
  if (! optgroup_sleuthkit_available ()) {
    reply_with_unavailable_feature ("sleuthkit");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_inode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.device, device, , goto done);
  inode = args.inode;

  r = do_download_inode (&device, inode);
  if (r == -1)
    /* do_download_inode has already called reply_with_error */
    goto done;

  /* do_download_inode has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_inode_args, (char *) &args);
done_no_free:
  return;
}

void
exists_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_exists_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_exists_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_exists (path);
  if (r == -1)
    /* do_exists has already called reply_with_error */
    goto done;

  struct guestfs_exists_ret ret;
  ret.existsflag = r;
  reply ((xdrproc_t) &xdr_guestfs_exists_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
done_no_free:
  return;
}

void
fill_dir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_dir_args args;
  const char *dir;
  int nr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);
  nr = args.nr;

  NEED_ROOT (, goto done);
  r = do_fill_dir (dir, nr);
  if (r == -1)
    /* do_fill_dir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_dir_args, (char *) &args);
done_no_free:
  return;
}

void
findfs_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_findfs_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_findfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_findfs_label (label);
  if (r == NULL)
    /* do_findfs_label has already called reply_with_error */
    goto done;

  struct guestfs_findfs_label_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_findfs_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_findfs_label_args, (char *) &args);
done_no_free:
  return;
}

void
get_umask_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_get_umask ();
  if (r == -1)
    /* do_get_umask has already called reply_with_error */
    goto done;

  struct guestfs_get_umask_ret ret;
  ret.mask = r;
  reply ((xdrproc_t) &xdr_guestfs_get_umask_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
getxattrs_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_getxattrs_args args;
  const char *path;

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

  if (!xdr_guestfs_getxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_getxattrs (path);
  if (r == NULL)
    /* do_getxattrs has already called reply_with_error */
    goto done;

  struct guestfs_getxattrs_ret ret;
  ret.xattrs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
done_no_free:
  return;
}

void
grep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_grep_args args;
  const char *regex;
  const char *path;
  int extended;
  int fixed;
  int insensitive;
  int compressed;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);
  extended = args.extended;
  fixed = args.fixed;
  insensitive = args.insensitive;
  compressed = args.compressed;

  NEED_ROOT (, goto done);
  r = do_grep (regex, path, extended, fixed, insensitive, compressed);
  if (r == NULL)
    /* do_grep has already called reply_with_error */
    goto done;

  struct guestfs_grep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_parent_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_parent_args args;
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

  if (!xdr_guestfs_hivex_node_parent_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_parent (nodeh);
  if (r == -1)
    /* do_hivex_node_parent has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_parent_ret ret;
  ret.parent = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_parent_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_parent_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_root_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_root ();
  if (r == -1)
    /* do_hivex_root has already called reply_with_error */
    goto done;

  struct guestfs_hivex_root_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_root_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
hivex_value_value_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_hivex_value_value_args args;
  int64_t valueh;

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

  if (!xdr_guestfs_hivex_value_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_value (valueh, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_hivex_value_value has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_value_ret ret;
  ret.databuf.databuf_val = r;
  ret.databuf.databuf_len = size;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_value_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_value_args, (char *) &args);
done_no_free:
  return;
}

void
initrd_list_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_initrd_list_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_initrd_list (path);
  if (r == NULL)
    /* do_initrd_list has already called reply_with_error */
    goto done;

  struct guestfs_initrd_list_ret ret;
  ret.filenames.filenames_len = count_strings (r);
  ret.filenames.filenames_val = r;
  reply ((xdrproc_t) &xdr_guestfs_initrd_list_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
done_no_free:
  return;
}

void
inotify_files_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_files ();
  if (r == NULL)
    /* do_inotify_files has already called reply_with_error */
    goto done;

  struct guestfs_inotify_files_ret ret;
  ret.paths.paths_len = count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_files_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
inotify_rm_watch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_rm_watch_args args;
  int wd;

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

  if (!xdr_guestfs_inotify_rm_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  wd = args.wd;

  r = do_inotify_rm_watch (wd);
  if (r == -1)
    /* do_inotify_rm_watch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
done_no_free:
  return;
}

void
is_symlink_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_symlink_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_symlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_symlink (path);
  if (r == -1)
    /* do_is_symlink has already called reply_with_error */
    goto done;

  struct guestfs_is_symlink_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_symlink_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_symlink_args, (char *) &args);
done_no_free:
  return;
}

void
is_zero_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_zero_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_zero (path);
  if (r == -1)
    /* do_is_zero has already called reply_with_error */
    goto done;

  struct guestfs_is_zero_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_args, (char *) &args);
done_no_free:
  return;
}

void
lchown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lchown_args args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lchown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lchown (owner, group, path);
  if (r == -1)
    /* do_lchown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_create_all_stub (XDR *xdr_in)
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

  r = do_ldmtool_create_all ();
  if (r == -1)
    /* do_ldmtool_create_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
ldmtool_diskgroup_disks_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_disks_args args;
  const char *diskgroup;

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

  if (!xdr_guestfs_ldmtool_diskgroup_disks_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_disks (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_disks has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_disks_ret ret;
  ret.disks.disks_len = count_strings (r);
  ret.disks.disks_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_disks_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_args, (char *) &args);
done_no_free:
  return;
}

void
list_partitions_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_partitions ();
  if (r == NULL)
    /* do_list_partitions has already called reply_with_error */
    goto done;

  struct guestfs_list_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_partitions_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
llz_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_llz_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_llz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_llz (directory);
  if (r == NULL)
    /* do_llz has already called reply_with_error */
    goto done;

  struct guestfs_llz_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_llz_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_llz_args, (char *) &args);
done_no_free:
  return;
}

void
luks_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_open_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

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

  if (!xdr_guestfs_luks_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open (device, key, mapname);
  if (r == -1)
    /* do_luks_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_args, (char *) &args);
done_no_free:
  return;
}

void
luks_open_ro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_open_ro_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

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

  if (!xdr_guestfs_luks_open_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open_ro (device, key, mapname);
  if (r == -1)
    /* do_luks_open_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) &args);
done_no_free:
  return;
}

void
lvm_remove_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_remove_all ();
  if (r == -1)
    /* do_lvm_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
lvresize_free_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvresize_free_args args;
  CLEANUP_FREE char *lv = NULL;
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

  if (!xdr_guestfs_lvresize_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.lv, lv, , goto done);
  percent = args.percent;

  r = do_lvresize_free (lv, percent);
  if (r == -1)
    /* do_lvresize_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) &args);
done_no_free:
  return;
}

void
md_create_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_md_create_args args;
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
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
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
  missingbitmap = args.missingbitmap;
  nrdevices = args.nrdevices;
  spare = args.spare;
  chunk = args.chunk;
  level = args.level;

  r = do_md_create (name, devices, missingbitmap, nrdevices, spare, chunk, level);
  if (r == -1)
    /* do_md_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_create_args, (char *) &args);
done_no_free:
  return;
}

void
mkdtemp_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_mkdtemp_args args;
  const char *tmpl;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdtemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdtemp (tmpl);
  if (r == NULL)
    /* do_mkdtemp has already called reply_with_error */
    goto done;

  struct guestfs_mkdtemp_ret ret;
  ret.dir = r;
  reply ((xdrproc_t) &xdr_guestfs_mkdtemp_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
done_no_free:
  return;
}

void
mknod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_args args;
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

  if (!xdr_guestfs_mknod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
done_no_free:
  return;
}

void
mount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount (&mountable, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
done_no_free:
  return;
}

void
mount_ro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_ro_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount_ro (&mountable, mountpoint);
  if (r == -1)
    /* do_mount_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
done_no_free:
  return;
}

void
mounts_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mounts ();
  if (r == NULL)
    /* do_mounts has already called reply_with_error */
    goto done;

  struct guestfs_mounts_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mounts_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
ntfs_3g_probe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfs_3g_probe_args args;
  int rw;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfs_3g_probe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  rw = args.rw;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_ntfs_3g_probe (rw, device);
  if (r == -1)
    /* do_ntfs_3g_probe has already called reply_with_error */
    goto done;

  struct guestfs_ntfs_3g_probe_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
done_no_free:
  return;
}

void
ntfsclone_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsclone_out_args args;
  CLEANUP_FREE char *device = NULL;
  int metadataonly;
  int rescue;
  int ignorefscheck;
  int preservetimestamps;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsclone_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  metadataonly = args.metadataonly;
  rescue = args.rescue;
  ignorefscheck = args.ignorefscheck;
  preservetimestamps = args.preservetimestamps;
  force = args.force;

  r = do_ntfsclone_out (device, metadataonly, rescue, ignorefscheck, preservetimestamps, force);
  if (r == -1)
    /* do_ntfsclone_out has already called reply_with_error */
    goto done;

  /* do_ntfsclone_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_out_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_disk_guid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_disk_guid_args args;
  CLEANUP_FREE char *device = NULL;
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

  if (!xdr_guestfs_part_set_disk_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  guid = args.guid;

  r = do_part_set_disk_guid (device, guid);
  if (r == -1)
    /* do_part_set_disk_guid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_disk_guid_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_disk_guid_random_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_disk_guid_random_args args;
  CLEANUP_FREE char *device = NULL;

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

  if (!xdr_guestfs_part_set_disk_guid_random_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_set_disk_guid_random (device);
  if (r == -1)
    /* do_part_set_disk_guid_random has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_disk_guid_random_args, (char *) &args);
done_no_free:
  return;
}

void
pread_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_args args;
  const char *path;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pread_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  count = args.count;
  offset = args.offset;

  NEED_ROOT (, goto done);
  r = do_pread (path, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread has already called reply_with_error */
    goto done;

  struct guestfs_pread_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
done_no_free:
  return;
}

void
realpath_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_realpath_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_realpath_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_realpath (path);
  if (r == NULL)
    /* do_realpath has already called reply_with_error */
    goto done;

  struct guestfs_realpath_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_realpath_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
done_no_free:
  return;
}

void
selinux_relabel_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_selinux_relabel_args args;
  const char *specfile;
  const char *path;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinuxrelabel_available ()) {
    reply_with_unavailable_feature ("selinuxrelabel");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_selinux_relabel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  specfile = args.specfile;
  path = args.path;
  ABS_PATH (path, , goto done);
  force = args.force;

  NEED_ROOT (, goto done);
  r = do_selinux_relabel (specfile, path, force);
  if (r == -1)
    /* do_selinux_relabel has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_selinux_relabel_args, (char *) &args);
done_no_free:
  return;
}

void
swapoff_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_file_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_swapoff_file (file);
  if (r == -1)
    /* do_swapoff_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
done_no_free:
  return;
}

void
syslinux_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_syslinux_args args;
  CLEANUP_FREE char *device = NULL;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_syslinux_available ()) {
    reply_with_unavailable_feature ("syslinux");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_syslinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  directory = args.directory;

  r = do_syslinux (device, directory);
  if (r == -1)
    /* do_syslinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_syslinux_args, (char *) &args);
done_no_free:
  return;
}

void
tail_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail (path);
  if (r == NULL)
    /* do_tail has already called reply_with_error */
    goto done;

  struct guestfs_tail_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
done_no_free:
  return;
}

void
touch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_touch_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_touch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
done_no_free:
  return;
}

void
tune2fs_l_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tune2fs_l_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tune2fs_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_tune2fs_l (device);
  if (r == NULL)
    /* do_tune2fs_l has already called reply_with_error */
    goto done;

  struct guestfs_tune2fs_l_ret ret;
  ret.superblock.superblock_len = count_strings (r);
  ret.superblock.superblock_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tune2fs_l_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
done_no_free:
  return;
}

void
umount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_umount_args args;
  CLEANUP_FREE char *pathordevice = NULL;
  int force;
  int lazyunmount;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_umount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, , goto done);
  force = args.force;
  lazyunmount = args.lazyunmount;

  r = do_umount (pathordevice, force, lazyunmount);
  if (r == -1)
    /* do_umount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
done_no_free:
  return;
}

void
vg_activate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_args args;
  int activate;
  char **volgroups;

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

  if (!xdr_guestfs_vg_activate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args.activate;
  /* Ugly, but safe and avoids copying the strings. */
  volgroups = realloc (args.volgroups.volgroups_val,
                sizeof (char *) * (args.volgroups.volgroups_len+1));
  if (volgroups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  volgroups[args.volgroups.volgroups_len] = NULL;
  args.volgroups.volgroups_val = volgroups;

  r = do_vg_activate (activate, volgroups);
  if (r == -1)
    /* do_vg_activate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
done_no_free:
  return;
}

void
vgs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_vg_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs_full ();
  if (r == NULL)
    /* do_vgs_full has already called reply_with_error */
    goto done;

  struct guestfs_vgs_full_ret ret;
  ret.volgroups = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
vgscan_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgscan ();
  if (r == -1)
    /* do_vgscan has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
xfs_admin_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_admin_args args;
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
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff80)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_admin_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
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
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_admin_args, (char *) &args);
done_no_free:
  return;
}

void
zegrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrepi (regex, path);
  if (r == NULL)
    /* do_zegrepi has already called reply_with_error */
    goto done;

  struct guestfs_zegrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
done_no_free:
  return;
}

void
zfgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrep_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrep (pattern, path);
  if (r == NULL)
    /* do_zfgrep has already called reply_with_error */
    goto done;

  struct guestfs_zfgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
done_no_free:
  return;
}

void
zfile_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_zfile_args args;
  const char *meth;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfile_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  meth = args.meth;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfile (meth, path);
  if (r == NULL)
    /* do_zfile has already called reply_with_error */
    goto done;

  struct guestfs_zfile_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_zfile_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
done_no_free:
  return;
}

