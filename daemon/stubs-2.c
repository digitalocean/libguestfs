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
pvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_pv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvs_full ();
  if (r == NULL)
    /* do_pvs_full has already called reply_with_error */
    goto done;

  struct guestfs_pvs_full_ret ret;
  ret.physvols = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
mkdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir (path);
  if (r == -1)
    /* do_mkdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_args, (char *) &args);
done_no_free:
  return;
}

void
chown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chown_args args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chown (owner, group, path);
  if (r == -1)
    /* do_chown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chown_args, (char *) &args);
done_no_free:
  return;
}

void
umount_all_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_umount_all ();
  if (r == -1)
    /* do_umount_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

void
command_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_command_args args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_args (xdr_in, &args)) {
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

  r = do_command (arguments);
  if (r == NULL)
    /* do_command has already called reply_with_error */
    goto done;

  struct guestfs_command_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_command_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_command_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_getss_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getss_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getss_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getss (device);
  if (r == -1)
    /* do_blockdev_getss has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getss_ret ret;
  ret.sectorsize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getss_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_getsize64_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsize64_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsize64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getsize64 (device);
  if (r == -1)
    /* do_blockdev_getsize64 has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsize64_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) &args);
done_no_free:
  return;
}

void
blockdev_rereadpt_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_rereadpt_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_rereadpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_rereadpt (device);
  if (r == -1)
    /* do_blockdev_rereadpt has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) &args);
done_no_free:
  return;
}

void
debug_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_debug_args args;
  const char *subcmd;
  char **extraargs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_debug_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subcmd = args.subcmd;
  /* Ugly, but safe and avoids copying the strings. */
  extraargs = realloc (args.extraargs.extraargs_val,
                sizeof (char *) * (args.extraargs.extraargs_len+1));
  if (extraargs == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  extraargs[args.extraargs.extraargs_len] = NULL;
  args.extraargs.extraargs_val = extraargs;

  r = do_debug (subcmd, extraargs);
  if (r == NULL)
    /* do_debug has already called reply_with_error */
    goto done;

  struct guestfs_debug_ret ret;
  ret.result = r;
  reply ((xdrproc_t) &xdr_guestfs_debug_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_debug_args, (char *) &args);
done_no_free:
  return;
}

void
set_e2uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2uuid_args args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_set_e2uuid (device, uuid);
  if (r == -1)
    /* do_set_e2uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) &args);
done_no_free:
  return;
}

void
grub_install_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_grub_install_args args;
  const char *root;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_grub_available ()) {
    reply_with_unavailable_feature ("grub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grub_install_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  root = args.root;
  ABS_PATH (root, , goto done);
  RESOLVE_DEVICE (args.device, device, , goto done);

  NEED_ROOT (, goto done);
  r = do_grub_install (root, device);
  if (r == -1)
    /* do_grub_install has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grub_install_args, (char *) &args);
done_no_free:
  return;
}

void
drop_caches_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_drop_caches_args args;
  int whattodrop;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_drop_caches_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  whattodrop = args.whattodrop;

  r = do_drop_caches (whattodrop);
  if (r == -1)
    /* do_drop_caches has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_drop_caches_args, (char *) &args);
done_no_free:
  return;
}

void
pvresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvresize_args args;
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

  if (!xdr_guestfs_pvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvresize (device);
  if (r == -1)
    /* do_pvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_args, (char *) &args);
done_no_free:
  return;
}

void
sfdisk_disk_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_disk_geometry_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_disk_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_disk_geometry (device);
  if (r == NULL)
    /* do_sfdisk_disk_geometry has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_disk_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_disk_geometry_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_args, (char *) &args);
done_no_free:
  return;
}

void
resize2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_resize2fs (device);
  if (r == -1)
    /* do_resize2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_args, (char *) &args);
done_no_free:
  return;
}

void
sh_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sh_args args;
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sh_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  command = args.command;

  r = do_sh (command);
  if (r == NULL)
    /* do_sh has already called reply_with_error */
    goto done;

  struct guestfs_sh_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sh_args, (char *) &args);
done_no_free:
  return;
}

void
glob_expand_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_glob_expand_args args;
  const char *pattern;
  int directoryslash;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_glob_expand_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  ABS_PATH (pattern, , goto done);
  directoryslash = args.directoryslash;

  NEED_ROOT (, goto done);
  r = do_glob_expand (pattern, directoryslash);
  if (r == NULL)
    /* do_glob_expand has already called reply_with_error */
    goto done;

  struct guestfs_glob_expand_ret ret;
  ret.paths.paths_len = count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_glob_expand_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_glob_expand_args, (char *) &args);
done_no_free:
  return;
}

void
mkfifo_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfifo_args args;
  int mode;
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

  if (!xdr_guestfs_mkfifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkfifo (mode, path);
  if (r == -1)
    /* do_mkfifo has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfifo_args, (char *) &args);
done_no_free:
  return;
}

void
readdir_stub (XDR *xdr_in)
{
  guestfs_int_dirent_list *r;
  struct guestfs_readdir_args args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_readdir (dir);
  if (r == NULL)
    /* do_readdir has already called reply_with_error */
    goto done;

  struct guestfs_readdir_ret ret;
  ret.entries = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_args, (char *) &args);
done_no_free:
  return;
}

void
lsetxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lsetxattr_args args;
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

  if (!xdr_guestfs_lsetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lsetxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_lsetxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) &args);
done_no_free:
  return;
}

void
egrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrep (regex, path);
  if (r == NULL)
    /* do_egrep has already called reply_with_error */
    goto done;

  struct guestfs_egrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_egrep_args, (char *) &args);
done_no_free:
  return;
}

void
zgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrep (regex, path);
  if (r == NULL)
    /* do_zgrep has already called reply_with_error */
    goto done;

  struct guestfs_zgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zgrep_args, (char *) &args);
done_no_free:
  return;
}

void
readlink_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_readlink_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_readlink (path);
  if (r == NULL)
    /* do_readlink has already called reply_with_error */
    goto done;

  struct guestfs_readlink_ret ret;
  ret.link = r;
  reply ((xdrproc_t) &xdr_guestfs_readlink_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readlink_args, (char *) &args);
done_no_free:
  return;
}

void
swapon_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_swapon_label (label);
  if (r == -1)
    /* do_swapon_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_label_args, (char *) &args);
done_no_free:
  return;
}

void
modprobe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_modprobe_args args;
  const char *modulename;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxmodules_available ()) {
    reply_with_unavailable_feature ("linuxmodules");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_modprobe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  modulename = args.modulename;

  r = do_modprobe (modulename);
  if (r == -1)
    /* do_modprobe has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_modprobe_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_bootable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_bootable_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int bootable;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  bootable = args.bootable;

  r = do_part_set_bootable (device, partnum, bootable);
  if (r == -1)
    /* do_part_set_bootable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) &args);
done_no_free:
  return;
}

void
part_list_stub (XDR *xdr_in)
{
  guestfs_int_partition_list *r;
  struct guestfs_part_list_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_list (device);
  if (r == NULL)
    /* do_part_list has already called reply_with_error */
    goto done;

  struct guestfs_part_list_ret ret;
  ret.partitions = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_args, (char *) &args);
done_no_free:
  return;
}

void
vgpvuuids_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_vgpvuuids_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgpvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgpvuuids (vgname);
  if (r == NULL)
    /* do_vgpvuuids has already called reply_with_error */
    goto done;

  struct guestfs_vgpvuuids_ret ret;
  ret.uuids.uuids_len = count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgpvuuids_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgpvuuids_args, (char *) &args);
done_no_free:
  return;
}

void
txz_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_txz_out_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_txz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_txz_out (directory);
  if (r == -1)
    /* do_txz_out has already called reply_with_error */
    goto done;

  /* do_txz_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_txz_out_args, (char *) &args);
done_no_free:
  return;
}

void
luks_kill_slot_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_kill_slot_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
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

  if (!xdr_guestfs_luks_kill_slot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  keyslot = args.keyslot;

  r = do_luks_kill_slot (device, key, keyslot);
  if (r == -1)
    /* do_luks_kill_slot has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_kill_slot_args, (char *) &args);
done_no_free:
  return;
}

void
is_lv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_lv_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_lv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_is_lv (&mountable);
  if (r == -1)
    /* do_is_lv has already called reply_with_error */
    goto done;

  struct guestfs_is_lv_ret ret;
  ret.lvflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_lv_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_lv_args, (char *) &args);
done_no_free:
  return;
}

void
is_chardev_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_chardev_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_chardev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_chardev (path, followsymlinks);
  if (r == -1)
    /* do_is_chardev has already called reply_with_error */
    goto done;

  struct guestfs_is_chardev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_chardev_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_chardev_args, (char *) &args);
done_no_free:
  return;
}

void
is_socket_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_socket_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_socket_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_socket (path, followsymlinks);
  if (r == -1)
    /* do_is_socket has already called reply_with_error */
    goto done;

  struct guestfs_is_socket_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_socket_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_socket_args, (char *) &args);
done_no_free:
  return;
}

void
part_to_dev_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_to_dev_args args;
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_to_dev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.partition, partition, , goto done);

  r = do_part_to_dev (partition);
  if (r == NULL)
    /* do_part_to_dev has already called reply_with_error */
    goto done;

  struct guestfs_part_to_dev_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_part_to_dev_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_to_dev_args, (char *) &args);
done_no_free:
  return;
}

void
upload_offset_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_upload_offset_args args;
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_upload_offset_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, cancel_receive (), goto done);
  offset = args.offset;

  r = do_upload_offset (remotefilename, offset);
  if (r == -1)
    /* do_upload_offset has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_upload_offset_args, (char *) &args);
done_no_free:
  return;
}

void
pwrite_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pwrite_device_args args;
  CLEANUP_FREE char *device = NULL;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pwrite_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  r = do_pwrite_device (device, content, content_size, offset);
  if (r == -1)
    /* do_pwrite_device has already called reply_with_error */
    goto done;

  struct guestfs_pwrite_device_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_device_args, (char *) &args);
done_no_free:
  return;
}

void
copy_device_to_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_device_to_file_args args;
  CLEANUP_FREE char *src = NULL;
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

  if (!xdr_guestfs_copy_device_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.src, src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_device_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_file_args, (char *) &args);
done_no_free:
  return;
}

void
get_e2attrs_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2attrs_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2attrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2attrs (file);
  if (r == NULL)
    /* do_get_e2attrs has already called reply_with_error */
    goto done;

  struct guestfs_get_e2attrs_ret ret;
  ret.attrs = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2attrs_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2attrs_args, (char *) &args);
done_no_free:
  return;
}

void
get_e2generation_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_get_e2generation_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2generation (file);
  if (r == -1)
    /* do_get_e2generation has already called reply_with_error */
    goto done;

  struct guestfs_get_e2generation_ret ret;
  ret.generation = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2generation_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2generation_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_set_seeding_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_set_seeding_args args;
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

  if (!xdr_guestfs_btrfs_set_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  seeding = args.seeding;

  r = do_btrfs_set_seeding (device, seeding);
  if (r == -1)
    /* do_btrfs_set_seeding has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_set_seeding_args, (char *) &args);
done_no_free:
  return;
}

void
utsname_stub (XDR *xdr_in)
{
  guestfs_int_utsname *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_utsname ();
  if (r == NULL)
    /* do_utsname has already called reply_with_error */
    goto done;

  struct guestfs_utsname_ret ret;
  ret.uts = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
done:
done_no_free:
  return;
}

void
rsync_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_in_args args;
  const char *remote;
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

  if (!xdr_guestfs_rsync_in_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  remote = args.remote;
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_in (remote, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_in_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_get_value_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_get_value_args args;
  int64_t nodeh;
  const char *key;

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

  if (!xdr_guestfs_hivex_node_get_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  key = args.key;

  r = do_hivex_node_get_value (nodeh, key);
  if (r == -1)
    /* do_hivex_node_get_value has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_get_value_ret ret;
  ret.valueh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_value_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_value_args, (char *) &args);
done_no_free:
  return;
}

void
hivex_node_add_child_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_add_child_args args;
  int64_t parent;
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

  if (!xdr_guestfs_hivex_node_add_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  parent = args.parent;
  name = args.name;

  r = do_hivex_node_add_child (parent, name);
  if (r == -1)
    /* do_hivex_node_add_child has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_add_child_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_add_child_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_add_child_args, (char *) &args);
done_no_free:
  return;
}

void
ldmtool_scan_devices_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_scan_devices_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

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

  if (!xdr_guestfs_ldmtool_scan_devices_args (xdr_in, &args)) {
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

  r = do_ldmtool_scan_devices (devices);
  if (r == NULL)
    /* do_ldmtool_scan_devices has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_scan_devices_ret ret;
  ret.guids.guids_len = count_strings (r);
  ret.guids.guids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_scan_devices_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_scan_devices_args, (char *) &args);
done_no_free:
  return;
}

void
cp_r_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_r_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_r_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_r (src, dest);
  if (r == -1)
    /* do_cp_r has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_r_args, (char *) &args);
done_no_free:
  return;
}

void
journal_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_journal_open_args args;
  const char *directory;

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

  if (!xdr_guestfs_journal_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_journal_open (directory);
  if (r == -1)
    /* do_journal_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_open_args, (char *) &args);
done_no_free:
  return;
}

void
aug_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_aug_label_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_label (augpath);
  if (r == NULL)
    /* do_aug_label has already called reply_with_error */
    goto done;

  struct guestfs_aug_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_label_args, (char *) &args);
done_no_free:
  return;
}

void
blkdiscardzeroes_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blkdiscardzeroes_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscardzeroes_available ()) {
    reply_with_unavailable_feature ("blkdiscardzeroes");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blkdiscardzeroes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blkdiscardzeroes (device);
  if (r == -1)
    /* do_blkdiscardzeroes has already called reply_with_error */
    goto done;

  struct guestfs_blkdiscardzeroes_ret ret;
  ret.zeroes = r;
  reply ((xdrproc_t) &xdr_guestfs_blkdiscardzeroes_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscardzeroes_args, (char *) &args);
done_no_free:
  return;
}

void
statns_stub (XDR *xdr_in)
{
  guestfs_int_statns *r;
  struct guestfs_statns_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_statns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statns (path);
  if (r == NULL)
    /* do_statns has already called reply_with_error */
    goto done;

  struct guestfs_statns_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_statns_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_subvolume_show_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_btrfs_subvolume_show_args args;
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

  if (!xdr_guestfs_btrfs_subvolume_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_show (subvolume);
  if (r == NULL)
    /* do_btrfs_subvolume_show has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_show_ret ret;
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_len = count_strings (r);
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_val = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_show_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_show_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_quota_rescan_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_quota_rescan_args args;
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

  if (!xdr_guestfs_btrfs_quota_rescan_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_quota_rescan (&fs);
  if (r == -1)
    /* do_btrfs_quota_rescan has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_rescan_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_qgroup_limit_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_limit_args args;
  const char *subvolume;
  int64_t size;

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

  if (!xdr_guestfs_btrfs_qgroup_limit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_limit (subvolume, size);
  if (r == -1)
    /* do_btrfs_qgroup_limit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_limit_args, (char *) &args);
done_no_free:
  return;
}

void
btrfs_balance_cancel_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_cancel_args args;
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

  if (!xdr_guestfs_btrfs_balance_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_cancel (path);
  if (r == -1)
    /* do_btrfs_balance_cancel has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_cancel_args, (char *) &args);
done_no_free:
  return;
}

void
part_set_gpt_guid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_gpt_guid_args args;
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

  if (!xdr_guestfs_part_set_gpt_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_guid (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_guid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_guid_args, (char *) &args);
done_no_free:
  return;
}

void
part_get_disk_guid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_disk_guid_args args;
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

  if (!xdr_guestfs_part_get_disk_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_get_disk_guid (device);
  if (r == NULL)
    /* do_part_get_disk_guid has already called reply_with_error */
    goto done;

  struct guestfs_part_get_disk_guid_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_disk_guid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_disk_guid_args, (char *) &args);
done_no_free:
  return;
}

void
ntfscat_i_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfscat_i_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t device
      = { .device = NULL, .volume = NULL };
  int64_t inode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfscat_i_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.device, device, , goto done);
  inode = args.inode;

  r = do_ntfscat_i (&device, inode);
  if (r == -1)
    /* do_ntfscat_i has already called reply_with_error */
    goto done;

  /* do_ntfscat_i has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfscat_i_args, (char *) &args);
done_no_free:
  return;
}

