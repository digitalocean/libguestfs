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

#define CLEANUP_XDR_FREE_ACL_DELETE_DEF_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_acl_delete_def_file_args)))

static void
cleanup_xdr_free_acl_delete_def_file_args (struct guestfs_acl_delete_def_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_acl_delete_def_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ACL_DELETE_DEF_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
acl_delete_def_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_ACL_DELETE_DEF_FILE_ARGS struct guestfs_acl_delete_def_file_args args;
  memset (&args, 0, sizeof args);
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_acl_delete_def_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  dir = args.dir;
  ABS_PATH (dir, false, return);

  NEED_ROOT (false, return);
  r = do_acl_delete_def_file (dir);
  if (r == -1)
    /* do_acl_delete_def_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_LS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_ls_args)))

static void
cleanup_xdr_free_aug_ls_args (struct guestfs_aug_ls_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_ls_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_LS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_ls_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_AUG_LS_ARGS struct guestfs_aug_ls_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_ls_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_ls (augpath);
  if (r == NULL)
    /* do_aug_ls has already called reply_with_error */
    return;

  struct guestfs_aug_ls_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_ls_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_MATCH_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_match_args)))

static void
cleanup_xdr_free_aug_match_args (struct guestfs_aug_match_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_match_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_MATCH_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_match_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_AUG_MATCH_ARGS struct guestfs_aug_match_args args;
  memset (&args, 0, sizeof args);
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_aug_match_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  augpath = args.augpath;

  r = do_aug_match (augpath);
  if (r == NULL)
    /* do_aug_match has already called reply_with_error */
    return;

  struct guestfs_aug_match_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_match_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_AUG_TRANSFORM_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_aug_transform_args)))

static void
cleanup_xdr_free_aug_transform_args (struct guestfs_aug_transform_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_aug_transform_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_AUG_TRANSFORM_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
aug_transform_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_AUG_TRANSFORM_ARGS struct guestfs_aug_transform_args args;
  memset (&args, 0, sizeof args);
  const char *lens;
  const char *file;
  int remove;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_aug_transform_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  lens = args.lens;
  file = args.file;
  remove = args.remove;

  r = do_aug_transform (lens, file, remove);
  if (r == -1)
    /* do_aug_transform has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_QGROUP_CREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_qgroup_create_args)))

static void
cleanup_xdr_free_btrfs_qgroup_create_args (struct guestfs_btrfs_qgroup_create_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_create_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_QGROUP_CREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_qgroup_create_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_QGROUP_CREATE_ARGS struct guestfs_btrfs_qgroup_create_args args;
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

  if (!xdr_guestfs_btrfs_qgroup_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, false, return);

  NEED_ROOT (false, return);
  r = do_btrfs_qgroup_create (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_create has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFS_RESCUE_SUPER_RECOVER_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfs_rescue_super_recover_args)))

static void
cleanup_xdr_free_btrfs_rescue_super_recover_args (struct guestfs_btrfs_rescue_super_recover_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_super_recover_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFS_RESCUE_SUPER_RECOVER_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfs_rescue_super_recover_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFS_RESCUE_SUPER_RECOVER_ARGS struct guestfs_btrfs_rescue_super_recover_args args;
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

  if (!xdr_guestfs_btrfs_rescue_super_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_btrfs_rescue_super_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_super_recover has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_btrfstune_enable_extended_inode_refs_args)))

static void
cleanup_xdr_free_btrfstune_enable_extended_inode_refs_args (struct guestfs_btrfstune_enable_extended_inode_refs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_extended_inode_refs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
btrfstune_enable_extended_inode_refs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS_ARGS struct guestfs_btrfstune_enable_extended_inode_refs_args args;
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

  if (!xdr_guestfs_btrfstune_enable_extended_inode_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_btrfstune_enable_extended_inode_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_extended_inode_refs has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COMMAND_LINES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_command_lines_args)))

static void
cleanup_xdr_free_command_lines_args (struct guestfs_command_lines_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_command_lines_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COMMAND_LINES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
command_lines_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_COMMAND_LINES_ARGS struct guestfs_command_lines_args args;
  memset (&args, 0, sizeof args);
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_command_lines_args (xdr_in, &args)) {
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

  r = do_command_lines (arguments);
  if (r == NULL)
    /* do_command_lines has already called reply_with_error */
    return;

  struct guestfs_command_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_command_lines_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COMPRESS_DEVICE_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_compress_device_out_args)))

static void
cleanup_xdr_free_compress_device_out_args (struct guestfs_compress_device_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_compress_device_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COMPRESS_DEVICE_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
compress_device_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COMPRESS_DEVICE_OUT_ARGS struct guestfs_compress_device_out_args args;
  memset (&args, 0, sizeof args);
  const char *ctype;
  CLEANUP_FREE char *device = NULL;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_compress_device_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  ctype = args.ctype;
  RESOLVE_DEVICE (args.device, device, false);
  level = args.level;

  r = do_compress_device_out (ctype, device, level);
  if (r == -1)
    /* do_compress_device_out has already called reply_with_error */
    return;

  /* do_compress_device_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_COMPRESS_OUT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_compress_out_args)))

static void
cleanup_xdr_free_compress_out_args (struct guestfs_compress_out_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_compress_out_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_COMPRESS_OUT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
compress_out_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_COMPRESS_OUT_ARGS struct guestfs_compress_out_args args;
  memset (&args, 0, sizeof args);
  const char *ctype;
  const char *file;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_compress_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  ctype = args.ctype;
  file = args.file;
  ABS_PATH (file, false, return);
  level = args.level;

  NEED_ROOT (false, return);
  r = do_compress_out (ctype, file, level);
  if (r == -1)
    /* do_compress_out has already called reply_with_error */
    return;

  /* do_compress_out has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_CP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_cp_args)))

static void
cleanup_xdr_free_cp_args (struct guestfs_cp_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_cp_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_CP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
cp_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_CP_ARGS struct guestfs_cp_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_cp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);

  NEED_ROOT (false, return);
  r = do_cp (src, dest);
  if (r == -1)
    /* do_cp has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
df_h_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  r = do_df_h ();
  if (r == NULL)
    /* do_df_h has already called reply_with_error */
    return;

  struct guestfs_df_h_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_h_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_E2FSCK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_e2fsck_args)))

static void
cleanup_xdr_free_e2fsck_args (struct guestfs_e2fsck_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_E2FSCK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
e2fsck_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_E2FSCK_ARGS struct guestfs_e2fsck_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int correct;
  int forceall;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_e2fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  correct = args.correct;
  forceall = args.forceall;

  r = do_e2fsck (device, correct, forceall);
  if (r == -1)
    /* do_e2fsck has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_EXTLINUX_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_extlinux_args)))

static void
cleanup_xdr_free_extlinux_args (struct guestfs_extlinux_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_extlinux_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_EXTLINUX_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
extlinux_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_EXTLINUX_ARGS struct guestfs_extlinux_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_extlinux_available ()) {
    reply_with_unavailable_feature ("extlinux");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_extlinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_extlinux (directory);
  if (r == -1)
    /* do_extlinux has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_FSCK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_fsck_args)))

static void
cleanup_xdr_free_fsck_args (struct guestfs_fsck_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_fsck_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_FSCK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
fsck_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_FSCK_ARGS struct guestfs_fsck_args args;
  memset (&args, 0, sizeof args);
  const char *fstype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, false);

  r = do_fsck (fstype, device);
  if (r == -1)
    /* do_fsck has already called reply_with_error */
    return;

  struct guestfs_fsck_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_fsck_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_GET_CHILD_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_get_child_args)))

static void
cleanup_xdr_free_hivex_node_get_child_args (struct guestfs_hivex_node_get_child_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_child_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_GET_CHILD_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_get_child_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_HIVEX_NODE_GET_CHILD_ARGS struct guestfs_hivex_node_get_child_args args;
  memset (&args, 0, sizeof args);
  int64_t nodeh;
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

  if (!xdr_guestfs_hivex_node_get_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;
  name = args.name;

  r = do_hivex_node_get_child (nodeh, name);
  if (r == -1)
    /* do_hivex_node_get_child has already called reply_with_error */
    return;

  struct guestfs_hivex_node_get_child_ret ret;
  ret.child = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_child_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_NODE_SET_VALUE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_node_set_value_args)))

static void
cleanup_xdr_free_hivex_node_set_value_args (struct guestfs_hivex_node_set_value_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_set_value_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_NODE_SET_VALUE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_node_set_value_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_HIVEX_NODE_SET_VALUE_ARGS struct guestfs_hivex_node_set_value_args args;
  memset (&args, 0, sizeof args);
  int64_t nodeh;
  const char *key;
  int64_t t;
  const char *val;
  size_t val_size;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_hivex_node_set_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nodeh = args.nodeh;
  key = args.key;
  t = args.t;
  val = args.val.val_val;
  val_size = args.val.val_len;

  r = do_hivex_node_set_value (nodeh, key, t, val, val_size);
  if (r == -1)
    /* do_hivex_node_set_value has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_VALUE_KEY_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_value_key_args)))

static void
cleanup_xdr_free_hivex_value_key_args (struct guestfs_hivex_value_key_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_key_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_VALUE_KEY_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_value_key_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_HIVEX_VALUE_KEY_ARGS struct guestfs_hivex_value_key_args args;
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

  if (!xdr_guestfs_hivex_value_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  valueh = args.valueh;

  r = do_hivex_value_key (valueh);
  if (r == NULL)
    /* do_hivex_value_key has already called reply_with_error */
    return;

  struct guestfs_hivex_value_key_ret ret;
  ret.key = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_key_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_HIVEX_VALUE_TYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_hivex_value_type_args)))

static void
cleanup_xdr_free_hivex_value_type_args (struct guestfs_hivex_value_type_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_type_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_HIVEX_VALUE_TYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
hivex_value_type_stub (XDR *xdr_in)
{
  int64_t r;
  CLEANUP_XDR_FREE_HIVEX_VALUE_TYPE_ARGS struct guestfs_hivex_value_type_args args;
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

  if (!xdr_guestfs_hivex_value_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  valueh = args.valueh;

  r = do_hivex_value_type (valueh);
  if (r == -1)
    /* do_hivex_value_type has already called reply_with_error */
    return;

  struct guestfs_hivex_value_type_ret ret;
  ret.datatype = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_type_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_FILESYSTEM_WALK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_filesystem_walk_args)))

static void
cleanup_xdr_free_internal_filesystem_walk_args (struct guestfs_internal_filesystem_walk_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_filesystem_walk_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_FILESYSTEM_WALK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_filesystem_walk_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_FILESYSTEM_WALK_ARGS struct guestfs_internal_filesystem_walk_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_libtsk_available ()) {
    reply_with_unavailable_feature ("libtsk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_filesystem_walk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.device, device, false);

  r = do_internal_filesystem_walk (&device);
  if (r == -1)
    /* do_internal_filesystem_walk has already called reply_with_error */
    return;

  /* do_internal_filesystem_walk has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_FIND_INODE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_find_inode_args)))

static void
cleanup_xdr_free_internal_find_inode_args (struct guestfs_internal_find_inode_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_find_inode_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_FIND_INODE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_find_inode_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_FIND_INODE_ARGS struct guestfs_internal_find_inode_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  /* The caller should have checked before calling this. */
  if (! optgroup_libtsk_available ()) {
    reply_with_unavailable_feature ("libtsk");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_find_inode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.device, device, false);
  inode = args.inode;

  r = do_internal_find_inode (&device, inode);
  if (r == -1)
    /* do_internal_find_inode has already called reply_with_error */
    return;

  /* do_internal_find_inode has already sent a reply */
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_HOT_ADD_DRIVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_hot_add_drive_args)))

static void
cleanup_xdr_free_internal_hot_add_drive_args (struct guestfs_internal_hot_add_drive_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_add_drive_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_HOT_ADD_DRIVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_hot_add_drive_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_HOT_ADD_DRIVE_ARGS struct guestfs_internal_hot_add_drive_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_hot_add_drive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_internal_hot_add_drive (label);
  if (r == -1)
    /* do_internal_hot_add_drive has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_internal_hot_remove_drive_precheck_args)))

static void
cleanup_xdr_free_internal_hot_remove_drive_precheck_args (struct guestfs_internal_hot_remove_drive_precheck_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_remove_drive_precheck_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
internal_hot_remove_drive_precheck_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK_ARGS struct guestfs_internal_hot_remove_drive_precheck_args args;
  memset (&args, 0, sizeof args);
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_internal_hot_remove_drive_precheck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  label = args.label;

  r = do_internal_hot_remove_drive_precheck (label);
  if (r == -1)
    /* do_internal_hot_remove_drive_precheck has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
internal_journal_get_stub (XDR *xdr_in)
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

  r = do_internal_journal_get ();
  if (r == -1)
    /* do_internal_journal_get has already called reply_with_error */
    return;

  /* do_internal_journal_get has already sent a reply */
}

void
journal_get_data_threshold_stub (XDR *xdr_in)
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

  r = do_journal_get_data_threshold ();
  if (r == -1)
    /* do_journal_get_data_threshold has already called reply_with_error */
    return;

  struct guestfs_journal_get_data_threshold_ret ret;
  ret.threshold = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_data_threshold_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_NAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_diskgroup_name_args)))

static void
cleanup_xdr_free_ldmtool_diskgroup_name_args (struct guestfs_ldmtool_diskgroup_name_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_name_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_NAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_diskgroup_name_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_NAME_ARGS struct guestfs_ldmtool_diskgroup_name_args args;
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

  if (!xdr_guestfs_ldmtool_diskgroup_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_name (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_name has already called reply_with_error */
    return;

  struct guestfs_ldmtool_diskgroup_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_name_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_VOLUMES_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ldmtool_diskgroup_volumes_args)))

static void
cleanup_xdr_free_ldmtool_diskgroup_volumes_args (struct guestfs_ldmtool_diskgroup_volumes_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_volumes_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_VOLUMES_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ldmtool_diskgroup_volumes_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_LDMTOOL_DISKGROUP_VOLUMES_ARGS struct guestfs_ldmtool_diskgroup_volumes_args args;
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

  if (!xdr_guestfs_ldmtool_diskgroup_volumes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_volumes (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_volumes has already called reply_with_error */
    return;

  struct guestfs_ldmtool_diskgroup_volumes_ret ret;
  ret.volumes.volumes_len = count_strings (r);
  ret.volumes.volumes_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_volumes_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ll_args)))

static void
cleanup_xdr_free_ll_args (struct guestfs_ll_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ll_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ll_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_LL_ARGS struct guestfs_ll_args args;
  memset (&args, 0, sizeof args);
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ll_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  directory = args.directory;
  ABS_PATH (directory, false, return);

  NEED_ROOT (false, return);
  r = do_ll (directory);
  if (r == NULL)
    /* do_ll has already called reply_with_error */
    return;

  struct guestfs_ll_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_ll_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LN_F_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ln_f_args)))

static void
cleanup_xdr_free_ln_f_args (struct guestfs_ln_f_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ln_f_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LN_F_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ln_f_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LN_F_ARGS struct guestfs_ln_f_args args;
  memset (&args, 0, sizeof args);
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ln_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, false, return);

  NEED_ROOT (false, return);
  r = do_ln_f (target, linkname);
  if (r == -1)
    /* do_ln_f has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LN_S_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ln_s_args)))

static void
cleanup_xdr_free_ln_s_args (struct guestfs_ln_s_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ln_s_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LN_S_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ln_s_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LN_S_ARGS struct guestfs_ln_s_args args;
  memset (&args, 0, sizeof args);
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_ln_s_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, false, return);

  NEED_ROOT (false, return);
  r = do_ln_s (target, linkname);
  if (r == -1)
    /* do_ln_s has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LREMOVEXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lremovexattr_args)))

static void
cleanup_xdr_free_lremovexattr_args (struct guestfs_lremovexattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LREMOVEXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lremovexattr_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LREMOVEXATTR_ARGS struct guestfs_lremovexattr_args args;
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

  if (!xdr_guestfs_lremovexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_lremovexattr (xattr, path);
  if (r == -1)
    /* do_lremovexattr has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LUKS_CLOSE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_luks_close_args)))

static void
cleanup_xdr_free_luks_close_args (struct guestfs_luks_close_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_luks_close_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LUKS_CLOSE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
luks_close_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LUKS_CLOSE_ARGS struct guestfs_luks_close_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_luks_close_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_luks_close (device);
  if (r == -1)
    /* do_luks_close has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_LVREMOVE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_lvremove_args)))

static void
cleanup_xdr_free_lvremove_args (struct guestfs_lvremove_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_lvremove_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_LVREMOVE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
lvremove_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_LVREMOVE_ARGS struct guestfs_lvremove_args args;
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

  if (!xdr_guestfs_lvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_lvremove (device);
  if (r == -1)
    /* do_lvremove has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MD_STOP_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_md_stop_args)))

static void
cleanup_xdr_free_md_stop_args (struct guestfs_md_stop_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_md_stop_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MD_STOP_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
md_stop_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MD_STOP_ARGS struct guestfs_md_stop_args args;
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

  if (!xdr_guestfs_md_stop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.md, md, false);

  r = do_md_stop (md);
  if (r == -1)
    /* do_md_stop has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKFS_BTRFS_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkfs_btrfs_args)))

static void
cleanup_xdr_free_mkfs_btrfs_args (struct guestfs_mkfs_btrfs_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_btrfs_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKFS_BTRFS_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkfs_btrfs_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKFS_BTRFS_ARGS struct guestfs_mkfs_btrfs_args args;
  memset (&args, 0, sizeof args);
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
    return;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mkfs_btrfs_args (xdr_in, &args)) {
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
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKLOST_AND_FOUND_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mklost_and_found_args)))

static void
cleanup_xdr_free_mklost_and_found_args (struct guestfs_mklost_and_found_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mklost_and_found_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKLOST_AND_FOUND_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mklost_and_found_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKLOST_AND_FOUND_ARGS struct guestfs_mklost_and_found_args args;
  memset (&args, 0, sizeof args);
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mklost_and_found_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, false, return);

  NEED_ROOT (false, return);
  r = do_mklost_and_found (mountpoint);
  if (r == -1)
    /* do_mklost_and_found has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKMOUNTPOINT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkmountpoint_args)))

static void
cleanup_xdr_free_mkmountpoint_args (struct guestfs_mkmountpoint_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKMOUNTPOINT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkmountpoint_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKMOUNTPOINT_ARGS struct guestfs_mkmountpoint_args args;
  memset (&args, 0, sizeof args);
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  exemptpath = args.exemptpath;

  r = do_mkmountpoint (exemptpath);
  if (r == -1)
    /* do_mkmountpoint has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MKSWAP_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mkswap_file_args)))

static void
cleanup_xdr_free_mkswap_file_args (struct guestfs_mkswap_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MKSWAP_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mkswap_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MKSWAP_FILE_ARGS struct guestfs_mkswap_file_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mkswap_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_mkswap_file (path);
  if (r == -1)
    /* do_mkswap_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MOUNT_9P_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mount_9p_args)))

static void
cleanup_xdr_free_mount_9p_args (struct guestfs_mount_9p_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mount_9p_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MOUNT_9P_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mount_9p_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MOUNT_9P_ARGS struct guestfs_mount_9p_args args;
  memset (&args, 0, sizeof args);
  const char *mounttag;
  const char *mountpoint;
  const char *options;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_mount_9p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mounttag = args.mounttag;
  mountpoint = args.mountpoint;
  options = args.options;

  r = do_mount_9p (mounttag, mountpoint, options);
  if (r == -1)
    /* do_mount_9p has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_MV_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_mv_args)))

static void
cleanup_xdr_free_mv_args (struct guestfs_mv_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_mv_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_MV_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
mv_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_MV_ARGS struct guestfs_mv_args args;
  memset (&args, 0, sizeof args);
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  src = args.src;
  ABS_PATH (src, false, return);
  dest = args.dest;
  ABS_PATH (dest, false, return);

  NEED_ROOT (false, return);
  r = do_mv (src, dest);
  if (r == -1)
    /* do_mv has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_NTFSRESIZE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_ntfsresize_args)))

static void
cleanup_xdr_free_ntfsresize_args (struct guestfs_ntfsresize_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_NTFSRESIZE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
ntfsresize_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_NTFSRESIZE_ARGS struct guestfs_ntfsresize_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  int64_t size;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    return;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    return;
  }

  if (!xdr_guestfs_ntfsresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  size = args.size;
  force = args.force;

  r = do_ntfsresize (device, size, force);
  if (r == -1)
    /* do_ntfsresize has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_DISK_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_disk_args)))

static void
cleanup_xdr_free_part_disk_args (struct guestfs_part_disk_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_disk_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_DISK_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_disk_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_DISK_ARGS struct guestfs_part_disk_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_disk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);
  parttype = args.parttype;

  r = do_part_disk (device, parttype);
  if (r == -1)
    /* do_part_disk has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_EXPAND_GPT_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_expand_gpt_args)))

static void
cleanup_xdr_free_part_expand_gpt_args (struct guestfs_part_expand_gpt_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_expand_gpt_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_EXPAND_GPT_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_expand_gpt_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PART_EXPAND_GPT_ARGS struct guestfs_part_expand_gpt_args args;
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

  if (!xdr_guestfs_part_expand_gpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_part_expand_gpt (device);
  if (r == -1)
    /* do_part_expand_gpt has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PART_GET_PARTTYPE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_part_get_parttype_args)))

static void
cleanup_xdr_free_part_get_parttype_args (struct guestfs_part_get_parttype_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PART_GET_PARTTYPE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
part_get_parttype_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_PART_GET_PARTTYPE_ARGS struct guestfs_part_get_parttype_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_part_get_parttype_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_part_get_parttype (device);
  if (r == NULL)
    /* do_part_get_parttype has already called reply_with_error */
    return;

  struct guestfs_part_get_parttype_ret ret;
  ret.parttype = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_parttype_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PVCREATE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pvcreate_args)))

static void
cleanup_xdr_free_pvcreate_args (struct guestfs_pvcreate_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pvcreate_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PVCREATE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pvcreate_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PVCREATE_ARGS struct guestfs_pvcreate_args args;
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

  if (!xdr_guestfs_pvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_pvcreate (device);
  if (r == -1)
    /* do_pvcreate has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
pvs_stub (XDR *xdr_in)
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

  r = do_pvs ();
  if (r == NULL)
    /* do_pvs has already called reply_with_error */
    return;

  struct guestfs_pvs_ret ret;
  ret.physvols.physvols_len = count_strings (r);
  ret.physvols.physvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_pvs_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_PWRITE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_pwrite_args)))

static void
cleanup_xdr_free_pwrite_args (struct guestfs_pwrite_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_PWRITE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
pwrite_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_PWRITE_ARGS struct guestfs_pwrite_args args;
  memset (&args, 0, sizeof args);
  const char *path;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_pwrite_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  NEED_ROOT (false, return);
  r = do_pwrite (path, content, content_size, offset);
  if (r == -1)
    /* do_pwrite has already called reply_with_error */
    return;

  struct guestfs_pwrite_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RENAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rename_args)))

static void
cleanup_xdr_free_rename_args (struct guestfs_rename_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rename_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RENAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rename_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RENAME_ARGS struct guestfs_rename_args args;
  memset (&args, 0, sizeof args);
  const char *oldpath;
  const char *newpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  oldpath = args.oldpath;
  ABS_PATH (oldpath, false, return);
  newpath = args.newpath;
  ABS_PATH (newpath, false, return);

  NEED_ROOT (false, return);
  r = do_rename (oldpath, newpath);
  if (r == -1)
    /* do_rename has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RESIZE2FS_M_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_resize2fs_M_args)))

static void
cleanup_xdr_free_resize2fs_M_args (struct guestfs_resize2fs_M_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_M_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RESIZE2FS_M_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
resize2fs_M_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RESIZE2FS_M_ARGS struct guestfs_resize2fs_M_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_resize2fs_M_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_resize2fs_M (device);
  if (r == -1)
    /* do_resize2fs_M has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_RM_RF_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_rm_rf_args)))

static void
cleanup_xdr_free_rm_rf_args (struct guestfs_rm_rf_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_rm_rf_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_RM_RF_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
rm_rf_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_RM_RF_ARGS struct guestfs_rm_rf_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_rm_rf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_rm_rf (path);
  if (r == -1)
    /* do_rm_rf has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SCRUB_FILE_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_scrub_file_args)))

static void
cleanup_xdr_free_scrub_file_args (struct guestfs_scrub_file_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_file_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SCRUB_FILE_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
scrub_file_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SCRUB_FILE_ARGS struct guestfs_scrub_file_args args;
  memset (&args, 0, sizeof args);
  const char *file;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_scrub_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  file = args.file;
  ABS_PATH (file, false, return);

  NEED_ROOT (false, return);
  r = do_scrub_file (file);
  if (r == -1)
    /* do_scrub_file has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SETXATTR_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_setxattr_args)))

static void
cleanup_xdr_free_setxattr_args (struct guestfs_setxattr_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_setxattr_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SETXATTR_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
setxattr_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_SETXATTR_ARGS struct guestfs_setxattr_args args;
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

  if (!xdr_guestfs_setxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_setxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_setxattr has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_SFDISK_L_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_sfdisk_l_args)))

static void
cleanup_xdr_free_sfdisk_l_args (struct guestfs_sfdisk_l_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_SFDISK_L_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
sfdisk_l_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_SFDISK_L_ARGS struct guestfs_sfdisk_l_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_sfdisk_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_DEVICE (args.device, device, false);

  r = do_sfdisk_l (device);
  if (r == NULL)
    /* do_sfdisk_l has already called reply_with_error */
    return;

  struct guestfs_sfdisk_l_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_l_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VFS_LABEL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vfs_label_args)))

static void
cleanup_xdr_free_vfs_label_args (struct guestfs_vfs_label_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_label_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VFS_LABEL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vfs_label_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_VFS_LABEL_ARGS struct guestfs_vfs_label_args args;
  memset (&args, 0, sizeof args);
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, false);

  r = do_vfs_label (&mountable);
  if (r == NULL)
    /* do_vfs_label has already called reply_with_error */
    return;

  struct guestfs_vfs_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_label_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VG_ACTIVATE_ALL_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vg_activate_all_args)))

static void
cleanup_xdr_free_vg_activate_all_args (struct guestfs_vg_activate_all_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VG_ACTIVATE_ALL_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vg_activate_all_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VG_ACTIVATE_ALL_ARGS struct guestfs_vg_activate_all_args args;
  memset (&args, 0, sizeof args);
  int activate;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    return;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vg_activate_all_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  activate = args.activate;

  r = do_vg_activate_all (activate);
  if (r == -1)
    /* do_vg_activate_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

void
vgchange_uuid_all_stub (XDR *xdr_in)
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

  r = do_vgchange_uuid_all ();
  if (r == -1)
    /* do_vgchange_uuid_all has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGMETA_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgmeta_args)))

static void
cleanup_xdr_free_vgmeta_args (struct guestfs_vgmeta_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgmeta_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGMETA_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgmeta_stub (XDR *xdr_in)
{
  size_t size = 1;
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_VGMETA_ARGS struct guestfs_vgmeta_args args;
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

  if (!xdr_guestfs_vgmeta_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vgname = args.vgname;

  r = do_vgmeta (vgname, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_vgmeta has already called reply_with_error */
    return;

  struct guestfs_vgmeta_ret ret;
  ret.metadata.metadata_val = r;
  ret.metadata.metadata_len = size;
  reply ((xdrproc_t) &xdr_guestfs_vgmeta_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGRENAME_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vgrename_args)))

static void
cleanup_xdr_free_vgrename_args (struct guestfs_vgrename_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vgrename_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGRENAME_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vgrename_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_VGRENAME_ARGS struct guestfs_vgrename_args args;
  memset (&args, 0, sizeof args);
  const char *volgroup;
  const char *newvolgroup;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vgrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  volgroup = args.volgroup;
  newvolgroup = args.newvolgroup;

  r = do_vgrename (volgroup, newvolgroup);
  if (r == -1)
    /* do_vgrename has already called reply_with_error */
    return;

  reply (NULL, NULL);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_VGUUID_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_vguuid_args)))

static void
cleanup_xdr_free_vguuid_args (struct guestfs_vguuid_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_vguuid_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_VGUUID_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
vguuid_stub (XDR *xdr_in)
{
  CLEANUP_FREE char *r = NULL;
  CLEANUP_XDR_FREE_VGUUID_ARGS struct guestfs_vguuid_args args;
  memset (&args, 0, sizeof args);
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_vguuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  vgname = args.vgname;

  r = do_vguuid (vgname);
  if (r == NULL)
    /* do_vguuid has already called reply_with_error */
    return;

  struct guestfs_vguuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vguuid_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_WC_W_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_wc_w_args)))

static void
cleanup_xdr_free_wc_w_args (struct guestfs_wc_w_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_wc_w_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_WC_W_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
wc_w_stub (XDR *xdr_in)
{
  int r;
  CLEANUP_XDR_FREE_WC_W_ARGS struct guestfs_wc_w_args args;
  memset (&args, 0, sizeof args);
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_wc_w_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_wc_w (path);
  if (r == -1)
    /* do_wc_w has already called reply_with_error */
    return;

  struct guestfs_wc_w_ret ret;
  ret.words = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_w_ret, (char *) &ret);
}

#ifdef HAVE_ATTRIBUTE_CLEANUP

#define CLEANUP_XDR_FREE_ZFGREPI_ARGS \
    __attribute__((cleanup(cleanup_xdr_free_zfgrepi_args)))

static void
cleanup_xdr_free_zfgrepi_args (struct guestfs_zfgrepi_args *argsp)
{
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) argsp);
}

#else /* !HAVE_ATTRIBUTE_CLEANUP */
#define CLEANUP_XDR_FREE_ZFGREPI_ARGS
#endif /* !HAVE_ATTRIBUTE_CLEANUP */

void
zfgrepi_stub (XDR *xdr_in)
{
  CLEANUP_FREE_STRING_LIST char **r = NULL;
  CLEANUP_XDR_FREE_ZFGREPI_ARGS struct guestfs_zfgrepi_args args;
  memset (&args, 0, sizeof args);
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    return;
  }

  if (!xdr_guestfs_zfgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, false, return);

  NEED_ROOT (false, return);
  r = do_zfgrepi (pattern, path);
  if (r == NULL)
    /* do_zfgrepi has already called reply_with_error */
    return;

  struct guestfs_zfgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrepi_ret, (char *) &ret);
}

