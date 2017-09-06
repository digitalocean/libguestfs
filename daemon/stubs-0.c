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
acl_delete_def_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_acl_delete_def_file_args args;
  const char *dir;

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

  if (!xdr_guestfs_acl_delete_def_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_acl_delete_def_file (dir);
  if (r == -1)
    /* do_acl_delete_def_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_delete_def_file_args, (char *) &args);
done_no_free:
  return;
}

void
aug_ls_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_ls_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_ls_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_ls (augpath);
  if (r == NULL)
    /* do_aug_ls has already called reply_with_error */
    goto done;

  struct guestfs_aug_ls_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_ls_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_ls_args, (char *) &args);
done_no_free:
  return;
}

void
aug_match_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_match_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_match_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_match (augpath);
  if (r == NULL)
    /* do_aug_match has already called reply_with_error */
    goto done;

  struct guestfs_aug_match_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_match_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_match_args, (char *) &args);
done_no_free:
  return;
}

void
aug_transform_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_transform_args args;
  const char *lens;
  const char *file;
  int remove;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_transform_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  lens = args.lens;
  file = args.file;
  remove = args.remove;

  r = do_aug_transform (lens, file, remove);
  if (r == -1)
    /* do_aug_transform has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_transform_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_create_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_create_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_create (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_create_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_rescue_super_recover_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_rescue_super_recover_args args;
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

  if (!xdr_guestfs_btrfs_rescue_super_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfs_rescue_super_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_super_recover has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_super_recover_args, (char *) &args);
done_no_free:
  return;
}

void
btrfstune_enable_extended_inode_refs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_enable_extended_inode_refs_args args;
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

  if (!xdr_guestfs_btrfstune_enable_extended_inode_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfstune_enable_extended_inode_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_extended_inode_refs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_extended_inode_refs_args, (char *) &args);
done_no_free:
  return;
}

void
command_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_command_lines_args args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args.arguments.arguments_val,
                sizeof (char *) * (args.arguments.arguments_len+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  arguments[args.arguments.arguments_len] = NULL;
  args.arguments.arguments_val = arguments;

  r = do_command_lines (arguments);
  if (r == NULL)
    /* do_command_lines has already called reply_with_error */
    goto done;

  struct guestfs_command_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_command_lines_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_command_lines_args, (char *) &args);
done_no_free:
  return;
}

void
compress_device_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_compress_device_out_args args;
  const char *ctype;
  CLEANUP_FREE char *device = NULL;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_compress_device_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args.ctype;
  RESOLVE_DEVICE (args.device, device, , goto done);
  level = args.level;

  r = do_compress_device_out (ctype, device, level);
  if (r == -1)
    /* do_compress_device_out has already called reply_with_error */
    goto done;

  /* do_compress_device_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_compress_device_out_args, (char *) &args);
done_no_free:
  return;
}

void
compress_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_compress_out_args args;
  const char *ctype;
  const char *file;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_compress_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args.ctype;
  file = args.file;
  ABS_PATH (file, , goto done);
  level = args.level;

  NEED_ROOT (, goto done);
  r = do_compress_out (ctype, file, level);
  if (r == -1)
    /* do_compress_out has already called reply_with_error */
    goto done;

  /* do_compress_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_compress_out_args, (char *) &args);
done_no_free:
  return;
}

void
cp_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp (src, dest);
  if (r == -1)
    /* do_cp has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
done_no_free:
  return;
}

void
df_h_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df_h ();
  if (r == NULL)
    /* do_df_h has already called reply_with_error */
    goto done;

  struct guestfs_df_h_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_h_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

void
e2fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_e2fsck_args args;
  CLEANUP_FREE char *device = NULL;
  int correct;
  int forceall;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_e2fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  correct = args.correct;
  forceall = args.forceall;

  r = do_e2fsck (device, correct, forceall);
  if (r == -1)
    /* do_e2fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_args, (char *) &args);
done_no_free:
  return;
}

void
extlinux_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_extlinux_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_extlinux_available ()) {
    reply_with_unavailable_feature ("extlinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_extlinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_extlinux (directory);
  if (r == -1)
    /* do_extlinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_extlinux_args, (char *) &args);
done_no_free:
  return;
}

void
fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fsck_args args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_fsck (fstype, device);
  if (r == -1)
    /* do_fsck has already called reply_with_error */
    goto done;

  struct guestfs_fsck_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_fsck_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_get_child_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_get_child_args args;
  int64_t nodeh;
  const char *name;

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

  if (!xdr_guestfs_hivex_node_get_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  name = args.name;

  r = do_hivex_node_get_child (nodeh, name);
  if (r == -1)
    /* do_hivex_node_get_child has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_get_child_ret ret;
  ret.child = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_child_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_child_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_set_value_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_node_set_value_args args;
  int64_t nodeh;
  const char *key;
  int64_t t;
  const char *val;
  size_t val_size;

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

  if (!xdr_guestfs_hivex_node_set_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  key = args.key;
  t = args.t;
  val = args.val.val_val;
  val_size = args.val.val_len;

  r = do_hivex_node_set_value (nodeh, key, t, val, val_size);
  if (r == -1)
    /* do_hivex_node_set_value has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_set_value_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_value_key_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hivex_value_key_args args;
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

  if (!xdr_guestfs_hivex_value_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_key (valueh);
  if (r == NULL)
    /* do_hivex_value_key has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_key_ret ret;
  ret.key = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_key_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_key_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_value_type_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_value_type_args args;
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

  if (!xdr_guestfs_hivex_value_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_type (valueh);
  if (r == -1)
    /* do_hivex_value_type has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_type_ret ret;
  ret.datatype = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_type_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_type_args, (char *) &args);
done_no_free:
  return;
}

void
internal_filesystem_walk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_filesystem_walk_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_libtsk_available ()) {
    reply_with_unavailable_feature ("libtsk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_filesystem_walk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.device, device, , goto done);

  r = do_internal_filesystem_walk (&device);
  if (r == -1)
    /* do_internal_filesystem_walk has already called reply_with_error */
    goto done;

  /* do_internal_filesystem_walk has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_filesystem_walk_args, (char *) &args);
done_no_free:
  return;
}

void
internal_find_inode_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_find_inode_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  /* The caller should have checked before calling this. */
  if (! optgroup_libtsk_available ()) {
    reply_with_unavailable_feature ("libtsk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_find_inode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.device, device, , goto done);
  inode = args.inode;

  r = do_internal_find_inode (&device, inode);
  if (r == -1)
    /* do_internal_find_inode has already called reply_with_error */
    goto done;

  /* do_internal_find_inode has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_find_inode_args, (char *) &args);
done_no_free:
  return;
}

void
internal_hot_add_drive_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_hot_add_drive_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_hot_add_drive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_internal_hot_add_drive (label);
  if (r == -1)
    /* do_internal_hot_add_drive has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_add_drive_args, (char *) &args);
done_no_free:
  return;
}

void
internal_hot_remove_drive_precheck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_hot_remove_drive_precheck_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_hot_remove_drive_precheck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_internal_hot_remove_drive_precheck (label);
  if (r == -1)
    /* do_internal_hot_remove_drive_precheck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_remove_drive_precheck_args, (char *) &args);
done_no_free:
  return;
}

void
internal_journal_get_stub (XDR *xdr_in)
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

  r = do_internal_journal_get ();
  if (r == -1)
    /* do_internal_journal_get has already called reply_with_error */
    goto done;

  /* do_internal_journal_get has already sent a reply */
done:
done_no_free:
  return;
}

void
journal_get_data_threshold_stub (XDR *xdr_in)
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

  r = do_journal_get_data_threshold ();
  if (r == -1)
    /* do_journal_get_data_threshold has already called reply_with_error */
    goto done;

  struct guestfs_journal_get_data_threshold_ret ret;
  ret.threshold = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_data_threshold_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
ldmtool_diskgroup_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_diskgroup_name_args args;
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

  if (!xdr_guestfs_ldmtool_diskgroup_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_name (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_name has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_name_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_diskgroup_volumes_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_volumes_args args;
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

  if (!xdr_guestfs_ldmtool_diskgroup_volumes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_volumes (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_volumes has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_volumes_ret ret;
  ret.volumes.volumes_len = count_strings (r);
  ret.volumes.volumes_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_volumes_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_volumes_args, (char *) &args);
done_no_free:
  return;
}

void
ll_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ll_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ll_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_ll (directory);
  if (r == NULL)
    /* do_ll has already called reply_with_error */
    goto done;

  struct guestfs_ll_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_ll_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ll_args, (char *) &args);
done_no_free:
  return;
}

void
ln_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_f_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_f (target, linkname);
  if (r == -1)
    /* do_ln_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
done_no_free:
  return;
}

void
ln_s_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_s_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_s_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_s (target, linkname);
  if (r == -1)
    /* do_ln_s has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
done_no_free:
  return;
}

void
lremovexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lremovexattr_args args;
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

  if (!xdr_guestfs_lremovexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lremovexattr (xattr, path);
  if (r == -1)
    /* do_lremovexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
done_no_free:
  return;
}

void
luks_close_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_close_args args;
  CLEANUP_FREE char *device = NULL;

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

  if (!xdr_guestfs_luks_close_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_luks_close (device);
  if (r == -1)
    /* do_luks_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_close_args, (char *) &args);
done_no_free:
  return;
}

void
lvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvremove_args args;
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

  if (!xdr_guestfs_lvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_lvremove (device);
  if (r == -1)
    /* do_lvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
done_no_free:
  return;
}

void
md_stop_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_md_stop_args args;
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

  if (!xdr_guestfs_md_stop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_stop (md);
  if (r == -1)
    /* do_md_stop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_stop_args, (char *) &args);
done_no_free:
  return;
}

void
mkfs_btrfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_btrfs_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t allocstart;
  int64_t bytecount;
  const char *datatype;
  int leafsize;
  const char *label;
  const char *metadata;
  int nodesize;
  int sectorsize;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_btrfs_args (xdr_in, &args)) {
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
  allocstart = args.allocstart;
  bytecount = args.bytecount;
  datatype = args.datatype;
  leafsize = args.leafsize;
  label = args.label;
  metadata = args.metadata;
  nodesize = args.nodesize;
  sectorsize = args.sectorsize;

  r = do_mkfs_btrfs (devices, allocstart, bytecount, datatype, leafsize, label, metadata, nodesize, sectorsize);
  if (r == -1)
    /* do_mkfs_btrfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_btrfs_args, (char *) &args);
done_no_free:
  return;
}

void
mklost_and_found_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mklost_and_found_args args;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mklost_and_found_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mklost_and_found (mountpoint);
  if (r == -1)
    /* do_mklost_and_found has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mklost_and_found_args, (char *) &args);
done_no_free:
  return;
}

void
mkmountpoint_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkmountpoint_args args;
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  exemptpath = args.exemptpath;

  r = do_mkmountpoint (exemptpath);
  if (r == -1)
    /* do_mkmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
done_no_free:
  return;
}

void
mkswap_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_file_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkswap_file (path);
  if (r == -1)
    /* do_mkswap_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
done_no_free:
  return;
}

void
mount_9p_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_9p_args args;
  const char *mounttag;
  const char *mountpoint;
  const char *options;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_9p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mounttag = args.mounttag;
  mountpoint = args.mountpoint;
  options = args.options;

  r = do_mount_9p (mounttag, mountpoint, options);
  if (r == -1)
    /* do_mount_9p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_9p_args, (char *) &args);
done_no_free:
  return;
}

void
mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mv_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_mv (src, dest);
  if (r == -1)
    /* do_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
done_no_free:
  return;
}

void
ntfsresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsresize_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;
  force = args.force;

  r = do_ntfsresize (device, size, force);
  if (r == -1)
    /* do_ntfsresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_args, (char *) &args);
done_no_free:
  return;
}

void
part_disk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_disk_args args;
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_disk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  parttype = args.parttype;

  r = do_part_disk (device, parttype);
  if (r == -1)
    /* do_part_disk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
done_no_free:
  return;
}

void
part_expand_gpt_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_expand_gpt_args args;
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

  if (!xdr_guestfs_part_expand_gpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_expand_gpt (device);
  if (r == -1)
    /* do_part_expand_gpt has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_expand_gpt_args, (char *) &args);
done_no_free:
  return;
}

void
part_get_parttype_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_parttype_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_parttype_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_get_parttype (device);
  if (r == NULL)
    /* do_part_get_parttype has already called reply_with_error */
    goto done;

  struct guestfs_part_get_parttype_ret ret;
  ret.parttype = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_parttype_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) &args);
done_no_free:
  return;
}

void
pvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvcreate_args args;
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

  if (!xdr_guestfs_pvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvcreate (device);
  if (r == -1)
    /* do_pvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
done_no_free:
  return;
}

void
pvs_stub (XDR *xdr_in)
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

  r = do_pvs ();
  if (r == NULL)
    /* do_pvs has already called reply_with_error */
    goto done;

  struct guestfs_pvs_ret ret;
  ret.physvols.physvols_len = count_strings (r);
  ret.physvols.physvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_pvs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

void
pwrite_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pwrite_args args;
  const char *path;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pwrite_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  NEED_ROOT (, goto done);
  r = do_pwrite (path, content, content_size, offset);
  if (r == -1)
    /* do_pwrite has already called reply_with_error */
    goto done;

  struct guestfs_pwrite_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_args, (char *) &args);
done_no_free:
  return;
}

void
rename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rename_args args;
  const char *oldpath;
  const char *newpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  oldpath = args.oldpath;
  ABS_PATH (oldpath, , goto done);
  newpath = args.newpath;
  ABS_PATH (newpath, , goto done);

  NEED_ROOT (, goto done);
  r = do_rename (oldpath, newpath);
  if (r == -1)
    /* do_rename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rename_args, (char *) &args);
done_no_free:
  return;
}

void
resize2fs_M_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_M_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_M_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_resize2fs_M (device);
  if (r == -1)
    /* do_resize2fs_M has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_M_args, (char *) &args);
done_no_free:
  return;
}

void
rm_rf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_rf_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_rf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_rf (path);
  if (r == -1)
    /* do_rm_rf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
done_no_free:
  return;
}

void
scrub_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_file_args args;
  const char *file;

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

  if (!xdr_guestfs_scrub_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_file (file);
  if (r == -1)
    /* do_scrub_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
done_no_free:
  return;
}

void
setxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setxattr_args args;
  const char *xattr;
  const char *val;
  int vallen;
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

  if (!xdr_guestfs_setxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_setxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_setxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
done_no_free:
  return;
}

void
sfdisk_l_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_l_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_l (device);
  if (r == NULL)
    /* do_sfdisk_l has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_l_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_l_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) &args);
done_no_free:
  return;
}

void
vfs_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_label_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_label (&mountable);
  if (r == NULL)
    /* do_vfs_label has already called reply_with_error */
    goto done;

  struct guestfs_vfs_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_label_args, (char *) &args);
done_no_free:
  return;
}

void
vg_activate_all_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_all_args args;
  int activate;

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

  if (!xdr_guestfs_vg_activate_all_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args.activate;

  r = do_vg_activate_all (activate);
  if (r == -1)
    /* do_vg_activate_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
done_no_free:
  return;
}

void
vgchange_uuid_all_stub (XDR *xdr_in)
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

  r = do_vgchange_uuid_all ();
  if (r == -1)
    /* do_vgchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
vgmeta_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_vgmeta_args args;
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

  if (!xdr_guestfs_vgmeta_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgmeta (vgname, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_vgmeta has already called reply_with_error */
    goto done;

  struct guestfs_vgmeta_ret ret;
  ret.metadata.metadata_val = r;
  ret.metadata.metadata_len = size;
  reply ((xdrproc_t) &xdr_guestfs_vgmeta_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgmeta_args, (char *) &args);
done_no_free:
  return;
}

void
vgrename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgrename_args args;
  const char *volgroup;
  const char *newvolgroup;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args.volgroup;
  newvolgroup = args.newvolgroup;

  r = do_vgrename (volgroup, newvolgroup);
  if (r == -1)
    /* do_vgrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
done_no_free:
  return;
}

void
vguuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vguuid_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vguuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vguuid (vgname);
  if (r == NULL)
    /* do_vguuid has already called reply_with_error */
    goto done;

  struct guestfs_vguuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vguuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vguuid_args, (char *) &args);
done_no_free:
  return;
}

void
wc_w_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_w_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_w_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_w (path);
  if (r == -1)
    /* do_wc_w has already called reply_with_error */
    goto done;

  struct guestfs_wc_w_ret ret;
  ret.words = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_w_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
done_no_free:
  return;
}

void
zfgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrepi_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrepi (pattern, path);
  if (r == NULL)
    /* do_zfgrepi has already called reply_with_error */
    goto done;

  struct guestfs_zfgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) &args);
done_no_free:
  return;
}

