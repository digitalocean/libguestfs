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
aug_mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_mv_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dest = args.dest;

  r = do_aug_mv (src, dest);
  if (r == -1)
    /* do_aug_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_mv_args, (char *) &args);
done_no_free:
  return;
}

void
available_all_groups_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_available_all_groups ();
  if (r == NULL)
    /* do_available_all_groups has already called reply_with_error */
    goto done;

  struct guestfs_available_all_groups_ret ret;
  ret.groups.groups_len = count_strings (r);
  ret.groups.groups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_available_all_groups_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
blockdev_getbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getbsz_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getbsz (device);
  if (r == -1)
    /* do_blockdev_getbsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getbsz_ret ret;
  ret.blocksize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_getro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getro_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getro (device);
  if (r == -1)
    /* do_blockdev_getro has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getro_ret ret;
  ret.ro = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getro_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_setbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setbsz_args args;
  CLEANUP_FREE char *device = NULL;
  int blocksize;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  blocksize = args.blocksize;

  r = do_blockdev_setbsz (device, blocksize);
  if (r == -1)
    /* do_blockdev_setbsz has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_remove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_remove_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_remove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_remove (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_remove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_remove_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_quota_enable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_quota_enable_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };
  int enable;

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

  if (!xdr_guestfs_btrfs_quota_enable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);
  enable = args.enable;

  r = do_btrfs_quota_enable (&fs, enable);
  if (r == -1)
    /* do_btrfs_quota_enable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_enable_args, (char *) &args);
done_no_free:
  return;
}

void
checksums_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_checksums_out_args args;
  const char *csumtype;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksums_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksums_out (csumtype, directory);
  if (r == -1)
    /* do_checksums_out has already called reply_with_error */
    goto done;

  /* do_checksums_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksums_out_args, (char *) &args);
done_no_free:
  return;
}

void
cp_a_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_a_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_a_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_a (src, dest);
  if (r == -1)
    /* do_cp_a has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_a_args, (char *) &args);
done_no_free:
  return;
}

void
df_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df ();
  if (r == NULL)
    /* do_df has already called reply_with_error */
    goto done;

  struct guestfs_df_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

void
egrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrepi (regex, path);
  if (r == NULL)
    /* do_egrepi has already called reply_with_error */
    goto done;

  struct guestfs_egrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_egrepi_args, (char *) &args);
done_no_free:
  return;
}

void
fallocate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fallocate_args args;
  const char *path;
  int len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fallocate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  len = args.len;

  NEED_ROOT (, goto done);
  r = do_fallocate (path, len);
  if (r == -1)
    /* do_fallocate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate_args, (char *) &args);
done_no_free:
  return;
}

void
fallocate64_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fallocate64_args args;
  const char *path;
  int64_t len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fallocate64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  len = args.len;

  NEED_ROOT (, goto done);
  r = do_fallocate64 (path, len);
  if (r == -1)
    /* do_fallocate64 has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate64_args, (char *) &args);
done_no_free:
  return;
}

void
fgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrep_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrep (pattern, path);
  if (r == NULL)
    /* do_fgrep has already called reply_with_error */
    goto done;

  struct guestfs_fgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fgrep_args, (char *) &args);
done_no_free:
  return;
}

void
file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_file_args args;
  CLEANUP_FREE char *path = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.path, path, , goto done);

  r = do_file (path);
  if (r == NULL)
    /* do_file has already called reply_with_error */
    goto done;

  struct guestfs_file_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_file_args, (char *) &args);
done_no_free:
  return;
}

void
filesize_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_filesize_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_filesize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_filesize (file);
  if (r == -1)
    /* do_filesize has already called reply_with_error */
    goto done;

  struct guestfs_filesize_ret ret;
  ret.size = r;
  reply ((xdrproc_t) &xdr_guestfs_filesize_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_filesize_args, (char *) &args);
done_no_free:
  return;
}

void
filesystem_available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_filesystem_available_args args;
  const char *filesystem;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_filesystem_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filesystem = args.filesystem;

  r = do_filesystem_available (filesystem);
  if (r == -1)
    /* do_filesystem_available has already called reply_with_error */
    goto done;

  struct guestfs_filesystem_available_ret ret;
  ret.fsavail = r;
  reply ((xdrproc_t) &xdr_guestfs_filesystem_available_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_filesystem_available_args, (char *) &args);
done_no_free:
  return;
}

void
fill_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_args args;
  int c;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  c = args.c;
  len = args.len;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill (c, len, path);
  if (r == -1)
    /* do_fill has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_args, (char *) &args);
done_no_free:
  return;
}

void
head_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head (path);
  if (r == NULL)
    /* do_head has already called reply_with_error */
    goto done;

  struct guestfs_head_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_head_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hivex_node_name_args args;
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

  if (!xdr_guestfs_hivex_node_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_name (nodeh);
  if (r == NULL)
    /* do_hivex_node_name has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_name_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_values_stub (XDR *xdr_in)
{
  guestfs_int_hivex_value_list *r;
  struct guestfs_hivex_node_values_args args;
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

  if (!xdr_guestfs_hivex_node_values_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_values (nodeh);
  if (r == NULL)
    /* do_hivex_node_values has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_values_ret ret;
  ret.valuehs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_args, (char *) &args);
done_no_free:
  return;
}

void
inotify_read_stub (XDR *xdr_in)
{
  guestfs_int_inotify_event_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_read ();
  if (r == NULL)
    /* do_inotify_read has already called reply_with_error */
    goto done;

  struct guestfs_inotify_read_ret ret;
  ret.events = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
internal_autosync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_autosync ();
  if (r == -1)
    /* do_internal_autosync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
internal_feature_available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_feature_available_args args;
  const char *group;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_feature_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  group = args.group;

  r = do_internal_feature_available (group);
  if (r == -1)
    /* do_internal_feature_available has already called reply_with_error */
    goto done;

  struct guestfs_internal_feature_available_ret ret;
  ret.result = r;
  reply ((xdrproc_t) &xdr_guestfs_internal_feature_available_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_feature_available_args, (char *) &args);
done_no_free:
  return;
}

void
internal_parse_mountable_stub (XDR *xdr_in)
{
  guestfs_int_internal_mountable *r;
  struct guestfs_internal_parse_mountable_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_parse_mountable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_internal_parse_mountable (&mountable);
  if (r == NULL)
    /* do_internal_parse_mountable has already called reply_with_error */
    goto done;

  struct guestfs_internal_parse_mountable_ret ret;
  ret.mountable = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_args, (char *) &args);
done_no_free:
  return;
}

void
internal_readlinklist_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_internal_readlinklist_args args;
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_readlinklist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  {
    size_t i;
    for (i = 0; i < args.names.names_len; ++i) {
      if (strchr (args.names.names_val[i], '/') != NULL) {
        reply_with_error ("%s: '%s' is not a file name", __func__, args.names.names_val[i]);
        goto done;
      }
    }
  }
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (, goto done);
  r = do_internal_readlinklist (path, names);
  if (r == NULL)
    /* do_internal_readlinklist has already called reply_with_error */
    goto done;

  struct guestfs_internal_readlinklist_ret ret;
  ret.links.links_len = count_strings (r);
  ret.links.links_val = r;
  reply ((xdrproc_t) &xdr_guestfs_internal_readlinklist_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_readlinklist_args, (char *) &args);
done_no_free:
  return;
}

void
isoinfo_stub (XDR *xdr_in)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_args args;
  const char *isofile;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_isoinfo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  isofile = args.isofile;
  ABS_PATH (isofile, , goto done);

  NEED_ROOT (, goto done);
  r = do_isoinfo (isofile);
  if (r == NULL)
    /* do_isoinfo has already called reply_with_error */
    goto done;

  struct guestfs_isoinfo_ret ret;
  ret.isodata = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_args, (char *) &args);
done_no_free:
  return;
}

void
journal_close_stub (XDR *xdr_in)
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

  r = do_journal_close ();
  if (r == -1)
    /* do_journal_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
lgetxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_lgetxattr_args args;
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

  if (!xdr_guestfs_lgetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  name = args.name;

  NEED_ROOT (, goto done);
  r = do_lgetxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_lgetxattr has already called reply_with_error */
    goto done;

  struct guestfs_lgetxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_lgetxattr_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattr_args, (char *) &args);
done_no_free:
  return;
}

void
list_9p_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_9p ();
  if (r == NULL)
    /* do_list_9p has already called reply_with_error */
    goto done;

  struct guestfs_list_9p_ret ret;
  ret.mounttags.mounttags_len = count_strings (r);
  ret.mounttags.mounttags_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_9p_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
list_ldm_partitions_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_ldm_partitions ();
  if (r == NULL)
    /* do_list_ldm_partitions has already called reply_with_error */
    goto done;

  struct guestfs_list_ldm_partitions_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_ldm_partitions_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
luks_format_cipher_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_format_cipher_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;
  const char *cipher;

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

  if (!xdr_guestfs_luks_format_cipher_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  keyslot = args.keyslot;
  cipher = args.cipher;

  r = do_luks_format_cipher (device, key, keyslot, cipher);
  if (r == -1)
    /* do_luks_format_cipher has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_format_cipher_args, (char *) &args);
done_no_free:
  return;
}

void
lvm_clear_filter_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_clear_filter ();
  if (r == -1)
    /* do_lvm_clear_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
lvs_stub (XDR *xdr_in)
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

  r = do_lvs ();
  if (r == NULL)
    /* do_lvs has already called reply_with_error */
    goto done;

  struct guestfs_lvs_ret ret;
  ret.logvols.logvols_len = count_strings (r);
  ret.logvols.logvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_lvs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
md_detail_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_md_detail_args args;
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

  if (!xdr_guestfs_md_detail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_detail (md);
  if (r == NULL)
    /* do_md_detail has already called reply_with_error */
    goto done;

  struct guestfs_md_detail_ret ret;
  ret.info.info_len = count_strings (r);
  ret.info.info_val = r;
  reply ((xdrproc_t) &xdr_guestfs_md_detail_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_detail_args, (char *) &args);
done_no_free:
  return;
}

void
mke2journal_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_L_args args;
  int blocksize;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args.blocksize;
  label = args.label;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mke2journal_L (blocksize, label, device);
  if (r == -1)
    /* do_mke2journal_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) &args);
done_no_free:
  return;
}

void
mkswap_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_args args;
  CLEANUP_FREE char *device = NULL;
  const char *label;
  const char *uuid;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  label = args.label;
  uuid = args.uuid;

  r = do_mkswap (device, label, uuid);
  if (r == -1)
    /* do_mkswap has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_args, (char *) &args);
done_no_free:
  return;
}

void
mkswap_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_L_args args;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkswap_L (label, device);
  if (r == -1)
    /* do_mkswap_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) &args);
done_no_free:
  return;
}

void
mktemp_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_mktemp_args args;
  const char *tmpl;
  const char *suffix;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mktemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, , goto done);
  suffix = args.suffix;

  NEED_ROOT (, goto done);
  r = do_mktemp (tmpl, suffix);
  if (r == NULL)
    /* do_mktemp has already called reply_with_error */
    goto done;

  struct guestfs_mktemp_ret ret;
  ret.path = r;
  reply ((xdrproc_t) &xdr_guestfs_mktemp_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mktemp_args, (char *) &args);
done_no_free:
  return;
}

void
mount_loop_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_loop_args args;
  const char *file;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_loop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mount_loop (file, mountpoint);
  if (r == -1)
    /* do_mount_loop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_loop_args, (char *) &args);
done_no_free:
  return;
}

void
mount_vfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_vfs_args args;
  const char *options;
  const char *vfstype;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_vfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  options = args.options;
  vfstype = args.vfstype;
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount_vfs (options, vfstype, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_vfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_mbr_id_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_mbr_id_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int idbyte;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_mbr_id_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  idbyte = args.idbyte;

  r = do_part_set_mbr_id (device, partnum, idbyte);
  if (r == -1)
    /* do_part_set_mbr_id has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_mbr_id_args, (char *) &args);
done_no_free:
  return;
}

void
pread_device_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_device_args args;
  CLEANUP_FREE char *device = NULL;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pread_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  count = args.count;
  offset = args.offset;

  r = do_pread_device (device, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread_device has already called reply_with_error */
    goto done;

  struct guestfs_pread_device_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_device_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pread_device_args, (char *) &args);
done_no_free:
  return;
}

void
pvchange_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvchange_uuid_args args;
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

  if (!xdr_guestfs_pvchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvchange_uuid (device);
  if (r == -1)
    /* do_pvchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvchange_uuid_args, (char *) &args);
done_no_free:
  return;
}

void
pvchange_uuid_all_stub (XDR *xdr_in)
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

  r = do_pvchange_uuid_all ();
  if (r == -1)
    /* do_pvchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
pvresize_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvresize_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

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

  if (!xdr_guestfs_pvresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_pvresize_size (device, size);
  if (r == -1)
    /* do_pvresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_size_args, (char *) &args);
done_no_free:
  return;
}

void
remount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_remount_args args;
  const char *mountpoint;
  int rw;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_remount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);
  rw = args.rw;

  NEED_ROOT (, goto done);
  r = do_remount (mountpoint, rw);
  if (r == -1)
    /* do_remount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_remount_args, (char *) &args);
done_no_free:
  return;
}

void
removexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_removexattr_args args;
  const char *xattr;
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

  if (!xdr_guestfs_removexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_removexattr (xattr, path);
  if (r == -1)
    /* do_removexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_removexattr_args, (char *) &args);
done_no_free:
  return;
}

void
resize2fs_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_resize2fs_size (device, size);
  if (r == -1)
    /* do_resize2fs_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_size_args, (char *) &args);
done_no_free:
  return;
}

void
rm_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_f_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_f (path);
  if (r == -1)
    /* do_rm_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_f_args, (char *) &args);
done_no_free:
  return;
}

void
rsync_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_out_args args;
  const char *src;
  const char *remote;
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

  if (!xdr_guestfs_rsync_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  remote = args.remote;
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_out (src, remote, archive, deletedest);
  if (r == -1)
    /* do_rsync_out has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_out_args, (char *) &args);
done_no_free:
  return;
}

void
set_e2generation_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2generation_args args;
  const char *file;
  int64_t generation;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);
  generation = args.generation;

  NEED_ROOT (, goto done);
  r = do_set_e2generation (file, generation);
  if (r == -1)
    /* do_set_e2generation has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2generation_args, (char *) &args);
done_no_free:
  return;
}

void
set_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_label_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  label = args.label;

  r = do_set_label (&mountable, label);
  if (r == -1)
    /* do_set_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_label_args, (char *) &args);
done_no_free:
  return;
}

void
sfdisk_kernel_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_kernel_geometry_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_kernel_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_kernel_geometry (device);
  if (r == NULL)
    /* do_sfdisk_kernel_geometry has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_kernel_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_kernel_geometry_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_args, (char *) &args);
done_no_free:
  return;
}

void
sleep_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sleep_args args;
  int secs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sleep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  secs = args.secs;

  r = do_sleep (secs);
  if (r == -1)
    /* do_sleep has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sleep_args, (char *) &args);
done_no_free:
  return;
}

void
strings_e_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_e_args args;
  const char *encoding;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_e_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  encoding = args.encoding;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings_e (encoding, path);
  if (r == NULL)
    /* do_strings_e has already called reply_with_error */
    goto done;

  struct guestfs_strings_e_ret ret;
  ret.stringsout.stringsout_len = count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_e_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_strings_e_args, (char *) &args);
done_no_free:
  return;
}

void
sync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
tail_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_n_args args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail_n (nrlines, path);
  if (r == NULL)
    /* do_tail_n has already called reply_with_error */
    goto done;

  struct guestfs_tail_n_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_n_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tail_n_args, (char *) &args);
done_no_free:
  return;
}

void
tar_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_out_args args;
  const char *directory;
  const char *compress;
  int numericowner;
  char **excludes;
  int xattrs;
  int selinux;
  int acls;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffc0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  compress = args.compress;
  numericowner = args.numericowner;
  /* Ugly, but safe and avoids copying the strings. */
  excludes = realloc (args.excludes.excludes_val,
                sizeof (char *) * (args.excludes.excludes_len+1));
  if (excludes == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  excludes[args.excludes.excludes_len] = NULL;
  args.excludes.excludes_val = excludes;
  xattrs = args.xattrs;
  selinux = args.selinux;
  acls = args.acls;

  r = do_tar_out (directory, compress, numericowner, excludes, xattrs, selinux, acls);
  if (r == -1)
    /* do_tar_out has already called reply_with_error */
    goto done;

  /* do_tar_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_out_args, (char *) &args);
done_no_free:
  return;
}

void
vfs_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_type_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_type (&mountable);
  if (r == NULL)
    /* do_vfs_type has already called reply_with_error */
    goto done;

  struct guestfs_vfs_type_ret ret;
  ret.fstype = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_type_args, (char *) &args);
done_no_free:
  return;
}

void
vgcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgcreate_args args;
  const char *volgroup;
  CLEANUP_FREE_STRING_LIST char **physvols = NULL;

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

  if (!xdr_guestfs_vgcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args.volgroup;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  physvols = calloc (args.physvols.physvols_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.physvols.physvols_len; ++i)
      RESOLVE_DEVICE (args.physvols.physvols_val[i], physvols[i],
                      , goto done);
    physvols[i] = NULL;
  }

  r = do_vgcreate (volgroup, physvols);
  if (r == -1)
    /* do_vgcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgcreate_args, (char *) &args);
done_no_free:
  return;
}

void
wc_c_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_c_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_c (path);
  if (r == -1)
    /* do_wc_c has already called reply_with_error */
    goto done;

  struct guestfs_wc_c_ret ret;
  ret.chars = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_c_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_c_args, (char *) &args);
done_no_free:
  return;
}

void
zegrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrep (regex, path);
  if (r == NULL)
    /* do_zegrep has already called reply_with_error */
    goto done;

  struct guestfs_zegrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zegrep_args, (char *) &args);
done_no_free:
  return;
}

