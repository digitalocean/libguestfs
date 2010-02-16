/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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
#include <rpc/types.h>
#include <rpc/xdr.h>

#include "daemon.h"
#include "c-ctype.h"
#include "../src/guestfs_protocol.h"
#include "actions.h"

static void mount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *mountpoint = args.mountpoint;

  r = do_mount (device, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
}

static void sync_stub (XDR *xdr_in)
{
  int r;

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void touch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_touch_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_touch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
}

static void cat_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_cat_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_cat (path);
  if (r == NULL)
    /* do_cat has already called reply_with_error */
    goto done;

  struct guestfs_cat_ret ret;
  ret.content = r;
  reply ((xdrproc_t) &xdr_guestfs_cat_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cat_args, (char *) &args);
}

static void ll_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ll_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ll_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;
  ABS_PATH (directory, goto done);

  NEED_ROOT (goto done);
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
}

static void ls_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ls_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ls_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;
  ABS_PATH (directory, goto done);

  NEED_ROOT (goto done);
  r = do_ls (directory);
  if (r == NULL)
    /* do_ls has already called reply_with_error */
    goto done;

  struct guestfs_ls_ret ret;
  ret.listing.listing_len = count_strings (r);
  ret.listing.listing_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ls_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ls_args, (char *) &args);
}

static void list_devices_stub (XDR *xdr_in)
{
  char **r;

  r = do_list_devices ();
  if (r == NULL)
    /* do_list_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_devices_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void list_partitions_stub (XDR *xdr_in)
{
  char **r;

  r = do_list_partitions ();
  if (r == NULL)
    /* do_list_partitions has already called reply_with_error */
    goto done;

  struct guestfs_list_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_partitions_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void pvs_stub (XDR *xdr_in)
{
  char **r;

  r = do_pvs ();
  if (r == NULL)
    /* do_pvs has already called reply_with_error */
    goto done;

  struct guestfs_pvs_ret ret;
  ret.physvols.physvols_len = count_strings (r);
  ret.physvols.physvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_pvs_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void vgs_stub (XDR *xdr_in)
{
  char **r;

  r = do_vgs ();
  if (r == NULL)
    /* do_vgs has already called reply_with_error */
    goto done;

  struct guestfs_vgs_ret ret;
  ret.volgroups.volgroups_len = count_strings (r);
  ret.volgroups.volgroups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgs_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void lvs_stub (XDR *xdr_in)
{
  char **r;

  r = do_lvs ();
  if (r == NULL)
    /* do_lvs has already called reply_with_error */
    goto done;

  struct guestfs_lvs_ret ret;
  ret.logvols.logvols_len = count_strings (r);
  ret.logvols.logvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_lvs_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void pvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_pv_list *r;

  r = do_pvs_full ();
  if (r == NULL)
    /* do_pvs_full has already called reply_with_error */
    goto done;

  struct guestfs_pvs_full_ret ret;
  ret.physvols = *r;
  reply ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
done: ;
}

static void vgs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_vg_list *r;

  r = do_vgs_full ();
  if (r == NULL)
    /* do_vgs_full has already called reply_with_error */
    goto done;

  struct guestfs_vgs_full_ret ret;
  ret.volgroups = *r;
  reply ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
done: ;
}

static void lvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_lv_list *r;

  r = do_lvs_full ();
  if (r == NULL)
    /* do_lvs_full has already called reply_with_error */
    goto done;

  struct guestfs_lvs_full_ret ret;
  ret.logvols = *r;
  reply ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
done: ;
}

static void read_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_read_lines_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_read_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_read_lines (path);
  if (r == NULL)
    /* do_read_lines has already called reply_with_error */
    goto done;

  struct guestfs_read_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_read_lines_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_read_lines_args, (char *) &args);
}

static void aug_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_init_args args;
  int flags;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *root = args.root;
  ABS_PATH (root, goto done);
  flags = args.flags;

  NEED_ROOT (goto done);
  r = do_aug_init (root, flags);
  if (r == -1)
    /* do_aug_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_init_args, (char *) &args);
}

static void aug_close_stub (XDR *xdr_in)
{
  int r;

  r = do_aug_close ();
  if (r == -1)
    /* do_aug_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void aug_defvar_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_defvar_args args;
  char *expr;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defvar_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *name = args.name;
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
}

static void aug_defnode_stub (XDR *xdr_in)
{
  guestfs_int_int_bool *r;
  struct guestfs_aug_defnode_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defnode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *name = args.name;
  char *expr = args.expr;
  char *val = args.val;

  r = do_aug_defnode (name, expr, val);
  if (r == NULL)
    /* do_aug_defnode has already called reply_with_error */
    goto done;

  struct guestfs_aug_defnode_ret ret;
  ret.nrnodescreated = *r;
  reply ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) &args);
}

static void aug_get_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_aug_get_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_get_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;

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
}

static void aug_set_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_set_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_set_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;
  char *val = args.val;

  r = do_aug_set (augpath, val);
  if (r == -1)
    /* do_aug_set has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_set_args, (char *) &args);
}

static void aug_insert_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_insert_args args;
  int before;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_insert_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;
  char *label = args.label;
  before = args.before;

  r = do_aug_insert (augpath, label, before);
  if (r == -1)
    /* do_aug_insert has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_insert_args, (char *) &args);
}

static void aug_rm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_rm_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;

  r = do_aug_rm (augpath);
  if (r == -1)
    /* do_aug_rm has already called reply_with_error */
    goto done;

  struct guestfs_aug_rm_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_rm_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_rm_args, (char *) &args);
}

static void aug_mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_mv_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *src = args.src;
  char *dest = args.dest;

  r = do_aug_mv (src, dest);
  if (r == -1)
    /* do_aug_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_mv_args, (char *) &args);
}

static void aug_match_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_match_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_match_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;

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
}

static void aug_save_stub (XDR *xdr_in)
{
  int r;

  r = do_aug_save ();
  if (r == -1)
    /* do_aug_save has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void aug_load_stub (XDR *xdr_in)
{
  int r;

  r = do_aug_load ();
  if (r == -1)
    /* do_aug_load has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void aug_ls_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_ls_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_ls_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *augpath = args.augpath;

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
}

static void rm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_rm (path);
  if (r == -1)
    /* do_rm has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_args, (char *) &args);
}

static void rmdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rmdir_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rmdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_rmdir (path);
  if (r == -1)
    /* do_rmdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rmdir_args, (char *) &args);
}

static void rm_rf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_rf_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_rf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_rm_rf (path);
  if (r == -1)
    /* do_rm_rf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
}

static void mkdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mkdir (path);
  if (r == -1)
    /* do_mkdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_args, (char *) &args);
}

static void mkdir_p_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_p_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mkdir_p (path);
  if (r == -1)
    /* do_mkdir_p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) &args);
}

static void chmod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chmod_args args;
  int mode;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chmod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_chmod (mode, path);
  if (r == -1)
    /* do_chmod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chmod_args, (char *) &args);
}

static void chown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chown_args args;
  int owner;
  int group;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  owner = args.owner;
  group = args.group;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_chown (owner, group, path);
  if (r == -1)
    /* do_chown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chown_args, (char *) &args);
}

static void exists_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_exists_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_exists_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_exists (path);
  if (r == -1)
    /* do_exists has already called reply_with_error */
    goto done;

  struct guestfs_exists_ret ret;
  ret.existsflag = r;
  reply ((xdrproc_t) &xdr_guestfs_exists_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
}

static void is_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_is_file (path);
  if (r == -1)
    /* do_is_file has already called reply_with_error */
    goto done;

  struct guestfs_is_file_ret ret;
  ret.fileflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_file_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_file_args, (char *) &args);
}

static void is_dir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_dir_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_is_dir (path);
  if (r == -1)
    /* do_is_dir has already called reply_with_error */
    goto done;

  struct guestfs_is_dir_ret ret;
  ret.dirflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_dir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_dir_args, (char *) &args);
}

static void pvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvcreate_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_pvcreate (device);
  if (r == -1)
    /* do_pvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
}

static void vgcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgcreate_args args;
  char **physvols;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *volgroup = args.volgroup;
  physvols = realloc (args.physvols.physvols_val,
                sizeof (char *) * (args.physvols.physvols_len+1));
  if (physvols == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  physvols[args.physvols.physvols_len] = NULL;
  args.physvols.physvols_val = physvols;
  /* Ensure that each is a device,
   * and perform device name translation. */
  { int pvi; for (pvi = 0; physvols[pvi] != NULL; ++pvi)
    RESOLVE_DEVICE (physvols[pvi], goto done);
  }

  r = do_vgcreate (volgroup, physvols);
  if (r == -1)
    /* do_vgcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgcreate_args, (char *) &args);
}

static void lvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvcreate_args args;
  int mbytes;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *logvol = args.logvol;
  char *volgroup = args.volgroup;
  mbytes = args.mbytes;

  r = do_lvcreate (logvol, volgroup, mbytes);
  if (r == -1)
    /* do_lvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
}

static void mkfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mkfs (fstype, device);
  if (r == -1)
    /* do_mkfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
}

static void sfdisk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_args args;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
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
}

static void write_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_write_file_args args;
  int size;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_write_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  char *content = args.content;
  size = args.size;

  NEED_ROOT (goto done);
  r = do_write_file (path, content, size);
  if (r == -1)
    /* do_write_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_write_file_args, (char *) &args);
}

static void umount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_umount_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_umount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pathordevice = args.pathordevice;

  r = do_umount (pathordevice);
  if (r == -1)
    /* do_umount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
}

static void mounts_stub (XDR *xdr_in)
{
  char **r;

  r = do_mounts ();
  if (r == NULL)
    /* do_mounts has already called reply_with_error */
    goto done;

  struct guestfs_mounts_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mounts_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void umount_all_stub (XDR *xdr_in)
{
  int r;

  r = do_umount_all ();
  if (r == -1)
    /* do_umount_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void lvm_remove_all_stub (XDR *xdr_in)
{
  int r;

  r = do_lvm_remove_all ();
  if (r == -1)
    /* do_lvm_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (path, goto done);

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
}

static void command_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_command_args args;
  char **arguments;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
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
}

static void command_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_command_lines_args args;
  char **arguments;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
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
}

static void stat_stub (XDR *xdr_in)
{
  guestfs_int_stat *r;
  struct guestfs_stat_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_stat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_stat (path);
  if (r == NULL)
    /* do_stat has already called reply_with_error */
    goto done;

  struct guestfs_stat_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_stat_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_stat_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_stat_args, (char *) &args);
}

static void lstat_stub (XDR *xdr_in)
{
  guestfs_int_stat *r;
  struct guestfs_lstat_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lstat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_lstat (path);
  if (r == NULL)
    /* do_lstat has already called reply_with_error */
    goto done;

  struct guestfs_lstat_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_lstat_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lstat_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lstat_args, (char *) &args);
}

static void statvfs_stub (XDR *xdr_in)
{
  guestfs_int_statvfs *r;
  struct guestfs_statvfs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_statvfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_statvfs (path);
  if (r == NULL)
    /* do_statvfs has already called reply_with_error */
    goto done;

  struct guestfs_statvfs_ret ret;
  ret.statbuf = *r;
  reply ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_args, (char *) &args);
}

static void tune2fs_l_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tune2fs_l_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tune2fs_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void blockdev_setro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setro_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_setro (device);
  if (r == -1)
    /* do_blockdev_setro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) &args);
}

static void blockdev_setrw_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setrw_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setrw_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_setrw (device);
  if (r == -1)
    /* do_blockdev_setrw has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
}

static void blockdev_getro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getro_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_getro (device);
  if (r == -1)
    /* do_blockdev_getro has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getro_ret ret;
  ret.ro = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getro_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) &args);
}

static void blockdev_getss_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getss_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getss_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_getss (device);
  if (r == -1)
    /* do_blockdev_getss has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getss_ret ret;
  ret.sectorsize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getss_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) &args);
}

static void blockdev_getbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getbsz_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_getbsz (device);
  if (r == -1)
    /* do_blockdev_getbsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getbsz_ret ret;
  ret.blocksize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) &args);
}

static void blockdev_setbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setbsz_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  blocksize = args.blocksize;

  r = do_blockdev_setbsz (device, blocksize);
  if (r == -1)
    /* do_blockdev_setbsz has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) &args);
}

static void blockdev_getsz_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsz_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_getsz (device);
  if (r == -1)
    /* do_blockdev_getsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsz_ret ret;
  ret.sizeinsectors = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) &args);
}

static void blockdev_getsize64_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsize64_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsize64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_getsize64 (device);
  if (r == -1)
    /* do_blockdev_getsize64 has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsize64_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) &args);
}

static void blockdev_flushbufs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_flushbufs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_flushbufs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_flushbufs (device);
  if (r == -1)
    /* do_blockdev_flushbufs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
}

static void blockdev_rereadpt_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_rereadpt_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_rereadpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_blockdev_rereadpt (device);
  if (r == -1)
    /* do_blockdev_rereadpt has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) &args);
}

static void upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_upload_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_upload_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *remotefilename = args.remotefilename;
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (remotefilename, goto done);

  r = do_upload (remotefilename);
  if (r == -1)
    /* do_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_upload_args, (char *) &args);
}

static void download_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *remotefilename = args.remotefilename;
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (remotefilename, goto done);

  r = do_download (remotefilename);
  if (r == -1)
    /* do_download has already called reply_with_error */
    goto done;

  /* do_download has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_args, (char *) &args);
}

static void checksum_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_checksum_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *csumtype = args.csumtype;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void tar_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_in_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_in_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;

  r = do_tar_in (directory);
  if (r == -1)
    /* do_tar_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_in_args, (char *) &args);
}

static void tar_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_out_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;

  r = do_tar_out (directory);
  if (r == -1)
    /* do_tar_out has already called reply_with_error */
    goto done;

  /* do_tar_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_out_args, (char *) &args);
}

static void tgz_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tgz_in_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tgz_in_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;

  r = do_tgz_in (directory);
  if (r == -1)
    /* do_tgz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
}

static void tgz_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tgz_out_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tgz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;
  ABS_PATH (directory, goto done);

  NEED_ROOT (goto done);
  r = do_tgz_out (directory);
  if (r == -1)
    /* do_tgz_out has already called reply_with_error */
    goto done;

  /* do_tgz_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_out_args, (char *) &args);
}

static void mount_ro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_ro_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *mountpoint = args.mountpoint;

  r = do_mount_ro (device, mountpoint);
  if (r == -1)
    /* do_mount_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
}

static void mount_options_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_options_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_options_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *options = args.options;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *mountpoint = args.mountpoint;

  r = do_mount_options (options, device, mountpoint);
  if (r == -1)
    /* do_mount_options has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_options_args, (char *) &args);
}

static void mount_vfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_vfs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_vfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *options = args.options;
  char *vfstype = args.vfstype;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *mountpoint = args.mountpoint;

  r = do_mount_vfs (options, vfstype, device, mountpoint);
  if (r == -1)
    /* do_mount_vfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) &args);
}

static void debug_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_debug_args args;
  char **extraargs;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_debug_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *subcmd = args.subcmd;
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
}

static void lvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvremove_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_lvremove (device);
  if (r == -1)
    /* do_lvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
}

static void vgremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgremove_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *vgname = args.vgname;

  r = do_vgremove (vgname);
  if (r == -1)
    /* do_vgremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
}

static void pvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvremove_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_pvremove (device);
  if (r == -1)
    /* do_pvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
}

static void set_e2label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2label_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *label = args.label;

  r = do_set_e2label (device, label);
  if (r == -1)
    /* do_set_e2label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2label_args, (char *) &args);
}

static void get_e2label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2label_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void set_e2uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2uuid_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *uuid = args.uuid;

  r = do_set_e2uuid (device, uuid);
  if (r == -1)
    /* do_set_e2uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) &args);
}

static void get_e2uuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2uuid_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_get_e2uuid (device);
  if (r == NULL)
    /* do_get_e2uuid has already called reply_with_error */
    goto done;

  struct guestfs_get_e2uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2uuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2uuid_args, (char *) &args);
}

static void fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fsck_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_fsck (fstype, device);
  if (r == -1)
    /* do_fsck has already called reply_with_error */
    goto done;

  struct guestfs_fsck_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_fsck_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
}

static void zero_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_zero (device);
  if (r == -1)
    /* do_zero has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_args, (char *) &args);
}

static void grub_install_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_grub_install_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grub_install_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *root = args.root;
  ABS_PATH (root, goto done);
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  NEED_ROOT (goto done);
  r = do_grub_install (root, device);
  if (r == -1)
    /* do_grub_install has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grub_install_args, (char *) &args);
}

static void cp_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *src = args.src;
  ABS_PATH (src, goto done);
  char *dest = args.dest;
  ABS_PATH (dest, goto done);

  NEED_ROOT (goto done);
  r = do_cp (src, dest);
  if (r == -1)
    /* do_cp has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
}

static void cp_a_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_a_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_a_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *src = args.src;
  ABS_PATH (src, goto done);
  char *dest = args.dest;
  ABS_PATH (dest, goto done);

  NEED_ROOT (goto done);
  r = do_cp_a (src, dest);
  if (r == -1)
    /* do_cp_a has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_a_args, (char *) &args);
}

static void mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mv_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *src = args.src;
  ABS_PATH (src, goto done);
  char *dest = args.dest;
  ABS_PATH (dest, goto done);

  NEED_ROOT (goto done);
  r = do_mv (src, dest);
  if (r == -1)
    /* do_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
}

static void drop_caches_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_drop_caches_args args;
  int whattodrop;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_drop_caches_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  whattodrop = args.whattodrop;

  r = do_drop_caches (whattodrop);
  if (r == -1)
    /* do_drop_caches has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_drop_caches_args, (char *) &args);
}

static void dmesg_stub (XDR *xdr_in)
{
  char *r;

  r = do_dmesg ();
  if (r == NULL)
    /* do_dmesg has already called reply_with_error */
    goto done;

  struct guestfs_dmesg_ret ret;
  ret.kmsgs = r;
  reply ((xdrproc_t) &xdr_guestfs_dmesg_ret, (char *) &ret);
  free (r);
done: ;
}

static void ping_daemon_stub (XDR *xdr_in)
{
  int r;

  r = do_ping_daemon ();
  if (r == -1)
    /* do_ping_daemon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void equal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_equal_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_equal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file1 = args.file1;
  ABS_PATH (file1, goto done);
  char *file2 = args.file2;
  ABS_PATH (file2, goto done);

  NEED_ROOT (goto done);
  r = do_equal (file1, file2);
  if (r == -1)
    /* do_equal has already called reply_with_error */
    goto done;

  struct guestfs_equal_ret ret;
  ret.equality = r;
  reply ((xdrproc_t) &xdr_guestfs_equal_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_equal_args, (char *) &args);
}

static void strings_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void strings_e_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_e_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_e_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *encoding = args.encoding;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void hexdump_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hexdump_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hexdump_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_hexdump (path);
  if (r == NULL)
    /* do_hexdump has already called reply_with_error */
    goto done;

  struct guestfs_hexdump_ret ret;
  ret.dump = r;
  reply ((xdrproc_t) &xdr_guestfs_hexdump_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hexdump_args, (char *) &args);
}

static void zerofree_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zerofree_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zerofree_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_zerofree (device);
  if (r == -1)
    /* do_zerofree has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zerofree_args, (char *) &args);
}

static void pvresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvresize_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_pvresize (device);
  if (r == -1)
    /* do_pvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_args, (char *) &args);
}

static void sfdisk_N_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_N_args args;
  int partnum;
  int cyls;
  int heads;
  int sectors;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_N_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  partnum = args.partnum;
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  char *line = args.line;

  r = do_sfdisk_N (device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    /* do_sfdisk_N has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
}

static void sfdisk_l_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_l_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void sfdisk_kernel_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_kernel_geometry_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_kernel_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void sfdisk_disk_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_disk_geometry_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_disk_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void vg_activate_all_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_all_args args;
  int activate;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vg_activate_all_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  activate = args.activate;

  r = do_vg_activate_all (activate);
  if (r == -1)
    /* do_vg_activate_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
}

static void vg_activate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_args args;
  int activate;
  char **volgroups;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vg_activate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  activate = args.activate;
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
}

static void lvresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvresize_args args;
  int mbytes;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  mbytes = args.mbytes;

  r = do_lvresize (device, mbytes);
  if (r == -1)
    /* do_lvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_args, (char *) &args);
}

static void resize2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_resize2fs (device);
  if (r == -1)
    /* do_resize2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_args, (char *) &args);
}

static void find_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_find_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_find_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;
  ABS_PATH (directory, goto done);

  NEED_ROOT (goto done);
  r = do_find (directory);
  if (r == NULL)
    /* do_find has already called reply_with_error */
    goto done;

  struct guestfs_find_ret ret;
  ret.names.names_len = count_strings (r);
  ret.names.names_val = r;
  reply ((xdrproc_t) &xdr_guestfs_find_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_find_args, (char *) &args);
}

static void e2fsck_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_e2fsck_f_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_e2fsck_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_e2fsck_f (device);
  if (r == -1)
    /* do_e2fsck_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) &args);
}

static void sleep_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sleep_args args;
  int secs;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sleep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  secs = args.secs;

  r = do_sleep (secs);
  if (r == -1)
    /* do_sleep has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sleep_args, (char *) &args);
}

static void ntfs_3g_probe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfs_3g_probe_args args;
  int rw;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfs_3g_probe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  rw = args.rw;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_ntfs_3g_probe (rw, device);
  if (r == -1)
    /* do_ntfs_3g_probe has already called reply_with_error */
    goto done;

  struct guestfs_ntfs_3g_probe_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
}

static void sh_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sh_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sh_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *command = args.command;

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
}

static void sh_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_sh_lines_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sh_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *command = args.command;

  r = do_sh_lines (command);
  if (r == NULL)
    /* do_sh_lines has already called reply_with_error */
    goto done;

  struct guestfs_sh_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_lines_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sh_lines_args, (char *) &args);
}

static void glob_expand_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_glob_expand_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_glob_expand_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pattern = args.pattern;
  ABS_PATH (pattern, goto done);

  NEED_ROOT (goto done);
  r = do_glob_expand (pattern);
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
}

static void scrub_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_device_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_scrub_device (device);
  if (r == -1)
    /* do_scrub_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_device_args, (char *) &args);
}

static void scrub_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file = args.file;
  ABS_PATH (file, goto done);

  NEED_ROOT (goto done);
  r = do_scrub_file (file);
  if (r == -1)
    /* do_scrub_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
}

static void scrub_freespace_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_freespace_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_freespace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *dir = args.dir;
  ABS_PATH (dir, goto done);

  NEED_ROOT (goto done);
  r = do_scrub_freespace (dir);
  if (r == -1)
    /* do_scrub_freespace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
}

static void mkdtemp_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_mkdtemp_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdtemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *template = args.template;
  ABS_PATH (template, goto done);

  NEED_ROOT (goto done);
  r = do_mkdtemp (template);
  if (r == NULL)
    /* do_mkdtemp has already called reply_with_error */
    goto done;

  struct guestfs_mkdtemp_ret ret;
  ret.dir = r;
  reply ((xdrproc_t) &xdr_guestfs_mkdtemp_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
}

static void wc_l_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_l_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_wc_l (path);
  if (r == -1)
    /* do_wc_l has already called reply_with_error */
    goto done;

  struct guestfs_wc_l_ret ret;
  ret.lines = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_l_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
}

static void wc_w_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_w_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_w_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_wc_w (path);
  if (r == -1)
    /* do_wc_w has already called reply_with_error */
    goto done;

  struct guestfs_wc_w_ret ret;
  ret.words = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_w_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
}

static void wc_c_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_c_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_wc_c (path);
  if (r == -1)
    /* do_wc_c has already called reply_with_error */
    goto done;

  struct guestfs_wc_c_ret ret;
  ret.chars = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_c_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_c_args, (char *) &args);
}

static void head_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void head_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_n_args args;
  int nrlines;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nrlines = args.nrlines;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void tail_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void tail_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_n_args args;
  int nrlines;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  nrlines = args.nrlines;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void df_stub (XDR *xdr_in)
{
  char *r;

  r = do_df ();
  if (r == NULL)
    /* do_df has already called reply_with_error */
    goto done;

  struct guestfs_df_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_ret, (char *) &ret);
  free (r);
done: ;
}

static void df_h_stub (XDR *xdr_in)
{
  char *r;

  r = do_df_h ();
  if (r == NULL)
    /* do_df_h has already called reply_with_error */
    goto done;

  struct guestfs_df_h_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_h_ret, (char *) &ret);
  free (r);
done: ;
}

static void du_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_du_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_du_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_du (path);
  if (r == -1)
    /* do_du has already called reply_with_error */
    goto done;

  struct guestfs_du_ret ret;
  ret.sizekb = r;
  reply ((xdrproc_t) &xdr_guestfs_du_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_du_args, (char *) &args);
}

static void initrd_list_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_initrd_list_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void mount_loop_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_loop_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_loop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file = args.file;
  ABS_PATH (file, goto done);
  char *mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, goto done);

  NEED_ROOT (goto done);
  r = do_mount_loop (file, mountpoint);
  if (r == -1)
    /* do_mount_loop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_loop_args, (char *) &args);
}

static void mkswap_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mkswap (device);
  if (r == -1)
    /* do_mkswap has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_args, (char *) &args);
}

static void mkswap_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_L_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *label = args.label;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mkswap_L (label, device);
  if (r == -1)
    /* do_mkswap_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) &args);
}

static void mkswap_U_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_U_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *uuid = args.uuid;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mkswap_U (uuid, device);
  if (r == -1)
    /* do_mkswap_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
}

static void mknod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_args args;
  int mode;
  int devmajor;
  int devminor;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mknod (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
}

static void mkfifo_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfifo_args args;
  int mode;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mkfifo (mode, path);
  if (r == -1)
    /* do_mkfifo has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfifo_args, (char *) &args);
}

static void mknod_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_b_args args;
  int mode;
  int devmajor;
  int devminor;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mknod_b (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_b_args, (char *) &args);
}

static void mknod_c_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_c_args args;
  int mode;
  int devmajor;
  int devminor;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mknod_c (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_c has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_c_args, (char *) &args);
}

static void umask_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_umask_args args;
  int mask;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_umask_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  mask = args.mask;

  r = do_umask (mask);
  if (r == -1)
    /* do_umask has already called reply_with_error */
    goto done;

  struct guestfs_umask_ret ret;
  ret.oldmask = r;
  reply ((xdrproc_t) &xdr_guestfs_umask_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_umask_args, (char *) &args);
}

static void readdir_stub (XDR *xdr_in)
{
  guestfs_int_dirent_list *r;
  struct guestfs_readdir_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *dir = args.dir;
  ABS_PATH (dir, goto done);

  NEED_ROOT (goto done);
  r = do_readdir (dir);
  if (r == NULL)
    /* do_readdir has already called reply_with_error */
    goto done;

  struct guestfs_readdir_ret ret;
  ret.entries = *r;
  reply ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_args, (char *) &args);
}

static void sfdiskM_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdiskM_args args;
  char **lines;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdiskM_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
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
}

static void zfile_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_zfile_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfile_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *meth = args.meth;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void getxattrs_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_getxattrs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_getxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_getxattrs (path);
  if (r == NULL)
    /* do_getxattrs has already called reply_with_error */
    goto done;

  struct guestfs_getxattrs_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
}

static void lgetxattrs_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_lgetxattrs_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lgetxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_lgetxattrs (path);
  if (r == NULL)
    /* do_lgetxattrs has already called reply_with_error */
    goto done;

  struct guestfs_lgetxattrs_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_args, (char *) &args);
}

static void setxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setxattr_args args;
  int vallen;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_setxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *xattr = args.xattr;
  char *val = args.val;
  vallen = args.vallen;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_setxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_setxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
}

static void lsetxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lsetxattr_args args;
  int vallen;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lsetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *xattr = args.xattr;
  char *val = args.val;
  vallen = args.vallen;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_lsetxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_lsetxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) &args);
}

static void removexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_removexattr_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_removexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *xattr = args.xattr;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_removexattr (xattr, path);
  if (r == -1)
    /* do_removexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_removexattr_args, (char *) &args);
}

static void lremovexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lremovexattr_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lremovexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *xattr = args.xattr;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_lremovexattr (xattr, path);
  if (r == -1)
    /* do_lremovexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
}

static void mountpoints_stub (XDR *xdr_in)
{
  char **r;

  r = do_mountpoints ();
  if (r == NULL)
    /* do_mountpoints has already called reply_with_error */
    goto done;

  struct guestfs_mountpoints_ret ret;
  ret.mps.mps_len = count_strings (r);
  ret.mps.mps_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mountpoints_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void mkmountpoint_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkmountpoint_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *exemptpath = args.exemptpath;

  r = do_mkmountpoint (exemptpath);
  if (r == -1)
    /* do_mkmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
}

static void rmmountpoint_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rmmountpoint_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rmmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *exemptpath = args.exemptpath;

  r = do_rmmountpoint (exemptpath);
  if (r == -1)
    /* do_rmmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rmmountpoint_args, (char *) &args);
}

static void read_file_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_read_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_read_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_read_file (path, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_read_file has already called reply_with_error */
    goto done;

  struct guestfs_read_file_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_read_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_read_file_args, (char *) &args);
}

static void grep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_grep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_grep (regex, path);
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
}

static void egrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void fgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pattern = args.pattern;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void grepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_grepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_grepi (regex, path);
  if (r == NULL)
    /* do_grepi has already called reply_with_error */
    goto done;

  struct guestfs_grepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grepi_args, (char *) &args);
}

static void egrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void fgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pattern = args.pattern;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zegrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zfgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrep_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pattern = args.pattern;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zegrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *regex = args.regex;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void zfgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrepi_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *pattern = args.pattern;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void realpath_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_realpath_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_realpath_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void ln_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *target = args.target;
  char *linkname = args.linkname;
  ABS_PATH (linkname, goto done);

  NEED_ROOT (goto done);
  r = do_ln (target, linkname);
  if (r == -1)
    /* do_ln has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
}

static void ln_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_f_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *target = args.target;
  char *linkname = args.linkname;
  ABS_PATH (linkname, goto done);

  NEED_ROOT (goto done);
  r = do_ln_f (target, linkname);
  if (r == -1)
    /* do_ln_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
}

static void ln_s_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_s_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_s_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *target = args.target;
  char *linkname = args.linkname;
  ABS_PATH (linkname, goto done);

  NEED_ROOT (goto done);
  r = do_ln_s (target, linkname);
  if (r == -1)
    /* do_ln_s has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
}

static void ln_sf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_sf_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_sf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *target = args.target;
  char *linkname = args.linkname;
  ABS_PATH (linkname, goto done);

  NEED_ROOT (goto done);
  r = do_ln_sf (target, linkname);
  if (r == -1)
    /* do_ln_sf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
}

static void readlink_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_readlink_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
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
}

static void fallocate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fallocate_args args;
  int len;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fallocate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  len = args.len;

  NEED_ROOT (goto done);
  r = do_fallocate (path, len);
  if (r == -1)
    /* do_fallocate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate_args, (char *) &args);
}

static void swapon_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_device_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_swapon_device (device);
  if (r == -1)
    /* do_swapon_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
}

static void swapoff_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_device_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_swapoff_device (device);
  if (r == -1)
    /* do_swapoff_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
}

static void swapon_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file = args.file;
  ABS_PATH (file, goto done);

  NEED_ROOT (goto done);
  r = do_swapon_file (file);
  if (r == -1)
    /* do_swapon_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_file_args, (char *) &args);
}

static void swapoff_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file = args.file;
  ABS_PATH (file, goto done);

  NEED_ROOT (goto done);
  r = do_swapoff_file (file);
  if (r == -1)
    /* do_swapoff_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
}

static void swapon_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_label_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *label = args.label;

  r = do_swapon_label (label);
  if (r == -1)
    /* do_swapon_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_label_args, (char *) &args);
}

static void swapoff_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_label_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *label = args.label;

  r = do_swapoff_label (label);
  if (r == -1)
    /* do_swapoff_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) &args);
}

static void swapon_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_uuid_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *uuid = args.uuid;

  r = do_swapon_uuid (uuid);
  if (r == -1)
    /* do_swapon_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
}

static void swapoff_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_uuid_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *uuid = args.uuid;

  r = do_swapoff_uuid (uuid);
  if (r == -1)
    /* do_swapoff_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) &args);
}

static void mkswap_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_file_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_mkswap_file (path);
  if (r == -1)
    /* do_mkswap_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
}

static void inotify_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_init_args args;
  int maxevents;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  maxevents = args.maxevents;

  r = do_inotify_init (maxevents);
  if (r == -1)
    /* do_inotify_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_init_args, (char *) &args);
}

static void inotify_add_watch_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_inotify_add_watch_args args;
  int mask;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_add_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  mask = args.mask;

  NEED_ROOT (goto done);
  r = do_inotify_add_watch (path, mask);
  if (r == -1)
    /* do_inotify_add_watch has already called reply_with_error */
    goto done;

  struct guestfs_inotify_add_watch_ret ret;
  ret.wd = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) &args);
}

static void inotify_rm_watch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_rm_watch_args args;
  int wd;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_rm_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  wd = args.wd;

  r = do_inotify_rm_watch (wd);
  if (r == -1)
    /* do_inotify_rm_watch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
}

static void inotify_read_stub (XDR *xdr_in)
{
  guestfs_int_inotify_event_list *r;

  r = do_inotify_read ();
  if (r == NULL)
    /* do_inotify_read has already called reply_with_error */
    goto done;

  struct guestfs_inotify_read_ret ret;
  ret.events = *r;
  reply ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
done: ;
}

static void inotify_files_stub (XDR *xdr_in)
{
  char **r;

  r = do_inotify_files ();
  if (r == NULL)
    /* do_inotify_files has already called reply_with_error */
    goto done;

  struct guestfs_inotify_files_ret ret;
  ret.paths.paths_len = count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_files_ret, (char *) &ret);
  free_strings (r);
done: ;
}

static void inotify_close_stub (XDR *xdr_in)
{
  int r;

  r = do_inotify_close ();
  if (r == -1)
    /* do_inotify_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done: ;
}

static void setcon_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setcon_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_setcon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *context = args.context;

  r = do_setcon (context);
  if (r == -1)
    /* do_setcon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setcon_args, (char *) &args);
}

static void getcon_stub (XDR *xdr_in)
{
  char *r;

  r = do_getcon ();
  if (r == NULL)
    /* do_getcon has already called reply_with_error */
    goto done;

  struct guestfs_getcon_ret ret;
  ret.context = r;
  reply ((xdrproc_t) &xdr_guestfs_getcon_ret, (char *) &ret);
  free (r);
done: ;
}

static void mkfs_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_b_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  blocksize = args.blocksize;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mkfs_b (fstype, blocksize, device);
  if (r == -1)
    /* do_mkfs_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
}

static void mke2journal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mke2journal (blocksize, device);
  if (r == -1)
    /* do_mke2journal has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_args, (char *) &args);
}

static void mke2journal_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_L_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  char *label = args.label;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mke2journal_L (blocksize, label, device);
  if (r == -1)
    /* do_mke2journal_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) &args);
}

static void mke2journal_U_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_U_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  blocksize = args.blocksize;
  char *uuid = args.uuid;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_mke2journal_U (blocksize, uuid, device);
  if (r == -1)
    /* do_mke2journal_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_U_args, (char *) &args);
}

static void mke2fs_J_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_J_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_J_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  blocksize = args.blocksize;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *journal = args.journal;
  RESOLVE_DEVICE (journal, goto done);

  r = do_mke2fs_J (fstype, blocksize, device, journal);
  if (r == -1)
    /* do_mke2fs_J has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_J_args, (char *) &args);
}

static void mke2fs_JL_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JL_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_JL_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  blocksize = args.blocksize;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *label = args.label;

  r = do_mke2fs_JL (fstype, blocksize, device, label);
  if (r == -1)
    /* do_mke2fs_JL has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) &args);
}

static void mke2fs_JU_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JU_args args;
  int blocksize;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_JU_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *fstype = args.fstype;
  blocksize = args.blocksize;
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *uuid = args.uuid;

  r = do_mke2fs_JU (fstype, blocksize, device, uuid);
  if (r == -1)
    /* do_mke2fs_JU has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) &args);
}

static void modprobe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_modprobe_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_modprobe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *modulename = args.modulename;

  r = do_modprobe (modulename);
  if (r == -1)
    /* do_modprobe has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_modprobe_args, (char *) &args);
}

static void echo_daemon_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_echo_daemon_args args;
  char **words;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_echo_daemon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
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
}

static void find0_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_find0_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_find0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *directory = args.directory;
  ABS_PATH (directory, goto done);

  NEED_ROOT (goto done);
  r = do_find0 (directory);
  if (r == -1)
    /* do_find0 has already called reply_with_error */
    goto done;

  /* do_find0 has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
}

static void case_sensitive_path_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_case_sensitive_path_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_case_sensitive_path_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_case_sensitive_path (path);
  if (r == NULL)
    /* do_case_sensitive_path has already called reply_with_error */
    goto done;

  struct guestfs_case_sensitive_path_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_case_sensitive_path_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_case_sensitive_path_args, (char *) &args);
}

static void vfs_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_type_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_vfs_type (device);
  if (r == NULL)
    /* do_vfs_type has already called reply_with_error */
    goto done;

  struct guestfs_vfs_type_ret ret;
  ret.fstype = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_type_args, (char *) &args);
}

static void truncate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_truncate (path);
  if (r == -1)
    /* do_truncate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_args, (char *) &args);
}

static void truncate_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_size_args args;
  int64_t size;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  size = args.size;

  NEED_ROOT (goto done);
  r = do_truncate_size (path, size);
  if (r == -1)
    /* do_truncate_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
}

static void utimens_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_utimens_args args;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_utimens_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  atsecs = args.atsecs;
  atnsecs = args.atnsecs;
  mtsecs = args.mtsecs;
  mtnsecs = args.mtnsecs;

  NEED_ROOT (goto done);
  r = do_utimens (path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    /* do_utimens has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_utimens_args, (char *) &args);
}

static void mkdir_mode_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_mode_args args;
  int mode;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_mode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  mode = args.mode;

  NEED_ROOT (goto done);
  r = do_mkdir_mode (path, mode);
  if (r == -1)
    /* do_mkdir_mode has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) &args);
}

static void lchown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lchown_args args;
  int owner;
  int group;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lchown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  owner = args.owner;
  group = args.group;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_lchown (owner, group, path);
  if (r == -1)
    /* do_lchown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
}

static void lstatlist_stub (XDR *xdr_in)
{
  guestfs_int_stat_list *r;
  struct guestfs_lstatlist_args args;
  char **names;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lstatlist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (goto done);
  r = do_lstatlist (path, names);
  if (r == NULL)
    /* do_lstatlist has already called reply_with_error */
    goto done;

  struct guestfs_lstatlist_ret ret;
  ret.statbufs = *r;
  reply ((xdrproc_t) xdr_guestfs_lstatlist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lstatlist_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lstatlist_args, (char *) &args);
}

static void lxattrlist_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_lxattrlist_args args;
  char **names;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lxattrlist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (goto done);
  r = do_lxattrlist (path, names);
  if (r == NULL)
    /* do_lxattrlist has already called reply_with_error */
    goto done;

  struct guestfs_lxattrlist_ret ret;
  ret.xattrs = *r;
  reply ((xdrproc_t) xdr_guestfs_lxattrlist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lxattrlist_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lxattrlist_args, (char *) &args);
}

static void readlinklist_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_readlinklist_args args;
  char **names;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readlinklist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (goto done);
  r = do_readlinklist (path, names);
  if (r == NULL)
    /* do_readlinklist has already called reply_with_error */
    goto done;

  struct guestfs_readlinklist_ret ret;
  ret.links.links_len = count_strings (r);
  ret.links.links_val = r;
  reply ((xdrproc_t) &xdr_guestfs_readlinklist_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readlinklist_args, (char *) &args);
}

static void pread_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_args args;
  int count;
  int64_t offset;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pread_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *path = args.path;
  ABS_PATH (path, goto done);
  count = args.count;
  offset = args.offset;

  NEED_ROOT (goto done);
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
}

static void part_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_init_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *parttype = args.parttype;

  r = do_part_init (device, parttype);
  if (r == -1)
    /* do_part_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_init_args, (char *) &args);
}

static void part_add_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_add_args args;
  int64_t startsect;
  int64_t endsect;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_add_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *prlogex = args.prlogex;
  startsect = args.startsect;
  endsect = args.endsect;

  r = do_part_add (device, prlogex, startsect, endsect);
  if (r == -1)
    /* do_part_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_add_args, (char *) &args);
}

static void part_disk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_disk_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_disk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  char *parttype = args.parttype;

  r = do_part_disk (device, parttype);
  if (r == -1)
    /* do_part_disk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
}

static void part_set_bootable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_bootable_args args;
  int partnum;
  int bootable;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  partnum = args.partnum;
  bootable = args.bootable;

  r = do_part_set_bootable (device, partnum, bootable);
  if (r == -1)
    /* do_part_set_bootable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) &args);
}

static void part_set_name_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_name_args args;
  int partnum;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);
  partnum = args.partnum;
  char *name = args.name;

  r = do_part_set_name (device, partnum, name);
  if (r == -1)
    /* do_part_set_name has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
}

static void part_list_stub (XDR *xdr_in)
{
  guestfs_int_partition_list *r;
  struct guestfs_part_list_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

  r = do_part_list (device);
  if (r == NULL)
    /* do_part_list has already called reply_with_error */
    goto done;

  struct guestfs_part_list_ret ret;
  ret.partitions = *r;
  reply ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_args, (char *) &args);
}

static void part_get_parttype_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_parttype_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_parttype_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *device = args.device;
  RESOLVE_DEVICE (device, goto done);

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
}

static void fill_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_args args;
  int c;
  int len;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  c = args.c;
  len = args.len;
  char *path = args.path;
  ABS_PATH (path, goto done);

  NEED_ROOT (goto done);
  r = do_fill (c, len, path);
  if (r == -1)
    /* do_fill has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_args, (char *) &args);
}

static void available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_available_args args;
  char **groups;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  groups = realloc (args.groups.groups_val,
                sizeof (char *) * (args.groups.groups_len+1));
  if (groups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  groups[args.groups.groups_len] = NULL;
  args.groups.groups_val = groups;

  r = do_available (groups);
  if (r == -1)
    /* do_available has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_available_args, (char *) &args);
}

static void dd_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_dd_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_dd_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *src = args.src;
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (src, goto done);
  char *dest = args.dest;
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (dest, goto done);

  r = do_dd (src, dest);
  if (r == -1)
    /* do_dd has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
}

static void filesize_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_filesize_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_filesize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *file = args.file;
  ABS_PATH (file, goto done);

  NEED_ROOT (goto done);
  r = do_filesize (file);
  if (r == -1)
    /* do_filesize has already called reply_with_error */
    goto done;

  struct guestfs_filesize_ret ret;
  ret.size = r;
  reply ((xdrproc_t) &xdr_guestfs_filesize_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_filesize_args, (char *) &args);
}

static void lvrename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvrename_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *logvol = args.logvol;
  char *newlogvol = args.newlogvol;

  r = do_lvrename (logvol, newlogvol);
  if (r == -1)
    /* do_lvrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvrename_args, (char *) &args);
}

static void vgrename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgrename_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *volgroup = args.volgroup;
  char *newvolgroup = args.newvolgroup;

  r = do_vgrename (volgroup, newvolgroup);
  if (r == -1)
    /* do_vgrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
}

static void initrd_cat_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_initrd_cat_args args;

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_cat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    return;
  }
  char *initrdpath = args.initrdpath;
  ABS_PATH (initrdpath, goto done);
  char *filename = args.filename;

  NEED_ROOT (goto done);
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
}

void dispatch_incoming_message (XDR *xdr_in)
{
  switch (proc_nr) {
    case GUESTFS_PROC_MOUNT:
      mount_stub (xdr_in);
      break;
    case GUESTFS_PROC_SYNC:
      sync_stub (xdr_in);
      break;
    case GUESTFS_PROC_TOUCH:
      touch_stub (xdr_in);
      break;
    case GUESTFS_PROC_CAT:
      cat_stub (xdr_in);
      break;
    case GUESTFS_PROC_LL:
      ll_stub (xdr_in);
      break;
    case GUESTFS_PROC_LS:
      ls_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DEVICES:
      list_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_PARTITIONS:
      list_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS:
      pvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS:
      vgs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS:
      lvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS_FULL:
      pvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS_FULL:
      vgs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS_FULL:
      lvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_READ_LINES:
      read_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INIT:
      aug_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_CLOSE:
      aug_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFVAR:
      aug_defvar_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFNODE:
      aug_defnode_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_GET:
      aug_get_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SET:
      aug_set_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INSERT:
      aug_insert_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_RM:
      aug_rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MV:
      aug_mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MATCH:
      aug_match_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SAVE:
      aug_save_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LOAD:
      aug_load_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LS:
      aug_ls_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM:
      rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMDIR:
      rmdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM_RF:
      rm_rf_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR:
      mkdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_P:
      mkdir_p_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHMOD:
      chmod_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHOWN:
      chown_stub (xdr_in);
      break;
    case GUESTFS_PROC_EXISTS:
      exists_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_FILE:
      is_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_DIR:
      is_dir_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCREATE:
      pvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCREATE:
      vgcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVCREATE:
      lvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS:
      mkfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK:
      sfdisk_stub (xdr_in);
      break;
    case GUESTFS_PROC_WRITE_FILE:
      write_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT:
      umount_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTS:
      mounts_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT_ALL:
      umount_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_REMOVE_ALL:
      lvm_remove_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILE:
      file_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND:
      command_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND_LINES:
      command_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_STAT:
      stat_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSTAT:
      lstat_stub (xdr_in);
      break;
    case GUESTFS_PROC_STATVFS:
      statvfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_TUNE2FS_L:
      tune2fs_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRO:
      blockdev_setro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRW:
      blockdev_setrw_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETRO:
      blockdev_getro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSS:
      blockdev_getss_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETBSZ:
      blockdev_getbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETBSZ:
      blockdev_setbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSZ:
      blockdev_getsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSIZE64:
      blockdev_getsize64_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_FLUSHBUFS:
      blockdev_flushbufs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_REREADPT:
      blockdev_rereadpt_stub (xdr_in);
      break;
    case GUESTFS_PROC_UPLOAD:
      upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD:
      download_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUM:
      checksum_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAR_IN:
      tar_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAR_OUT:
      tar_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_TGZ_IN:
      tgz_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TGZ_OUT:
      tgz_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_RO:
      mount_ro_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_OPTIONS:
      mount_options_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_VFS:
      mount_vfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEBUG:
      debug_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVREMOVE:
      lvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGREMOVE:
      vgremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVREMOVE:
      pvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2LABEL:
      set_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2LABEL:
      get_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2UUID:
      set_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2UUID:
      get_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_FSCK:
      fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO:
      zero_stub (xdr_in);
      break;
    case GUESTFS_PROC_GRUB_INSTALL:
      grub_install_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP:
      cp_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP_A:
      cp_a_stub (xdr_in);
      break;
    case GUESTFS_PROC_MV:
      mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_DROP_CACHES:
      drop_caches_stub (xdr_in);
      break;
    case GUESTFS_PROC_DMESG:
      dmesg_stub (xdr_in);
      break;
    case GUESTFS_PROC_PING_DAEMON:
      ping_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_EQUAL:
      equal_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS:
      strings_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS_E:
      strings_e_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEXDUMP:
      hexdump_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEROFREE:
      zerofree_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVRESIZE:
      pvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_N:
      sfdisk_N_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_L:
      sfdisk_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY:
      sfdisk_kernel_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_DISK_GEOMETRY:
      sfdisk_disk_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE_ALL:
      vg_activate_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE:
      vg_activate_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRESIZE:
      lvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS:
      resize2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_FIND:
      find_stub (xdr_in);
      break;
    case GUESTFS_PROC_E2FSCK_F:
      e2fsck_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_SLEEP:
      sleep_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFS_3G_PROBE:
      ntfs_3g_probe_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH:
      sh_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH_LINES:
      sh_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_GLOB_EXPAND:
      glob_expand_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_DEVICE:
      scrub_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_FILE:
      scrub_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_FREESPACE:
      scrub_freespace_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDTEMP:
      mkdtemp_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_L:
      wc_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_W:
      wc_w_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_C:
      wc_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD:
      head_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD_N:
      head_n_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL:
      tail_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL_N:
      tail_n_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF:
      df_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF_H:
      df_h_stub (xdr_in);
      break;
    case GUESTFS_PROC_DU:
      du_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_LIST:
      initrd_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_LOOP:
      mount_loop_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP:
      mkswap_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_L:
      mkswap_L_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_U:
      mkswap_U_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD:
      mknod_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFIFO:
      mkfifo_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_B:
      mknod_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_C:
      mknod_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMASK:
      umask_stub (xdr_in);
      break;
    case GUESTFS_PROC_READDIR:
      readdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISKM:
      sfdiskM_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFILE:
      zfile_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETXATTRS:
      getxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LGETXATTRS:
      lgetxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETXATTR:
      setxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSETXATTR:
      lsetxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_REMOVEXATTR:
      removexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LREMOVEXATTR:
      lremovexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTPOINTS:
      mountpoints_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKMOUNTPOINT:
      mkmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMMOUNTPOINT:
      rmmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_READ_FILE:
      read_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREP:
      grep_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREP:
      egrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREP:
      fgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREPI:
      grepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREPI:
      egrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREPI:
      fgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREP:
      zgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREP:
      zegrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREP:
      zfgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREPI:
      zgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREPI:
      zegrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREPI:
      zfgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_REALPATH:
      realpath_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN:
      ln_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_F:
      ln_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_S:
      ln_s_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_SF:
      ln_sf_stub (xdr_in);
      break;
    case GUESTFS_PROC_READLINK:
      readlink_stub (xdr_in);
      break;
    case GUESTFS_PROC_FALLOCATE:
      fallocate_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_DEVICE:
      swapon_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_DEVICE:
      swapoff_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_FILE:
      swapon_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_FILE:
      swapoff_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_LABEL:
      swapon_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_LABEL:
      swapoff_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_UUID:
      swapon_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_UUID:
      swapoff_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_FILE:
      mkswap_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_INIT:
      inotify_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_ADD_WATCH:
      inotify_add_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_RM_WATCH:
      inotify_rm_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_READ:
      inotify_read_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_FILES:
      inotify_files_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_CLOSE:
      inotify_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETCON:
      setcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETCON:
      getcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS_B:
      mkfs_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL:
      mke2journal_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_L:
      mke2journal_L_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_U:
      mke2journal_U_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_J:
      mke2fs_J_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_JL:
      mke2fs_JL_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_JU:
      mke2fs_JU_stub (xdr_in);
      break;
    case GUESTFS_PROC_MODPROBE:
      modprobe_stub (xdr_in);
      break;
    case GUESTFS_PROC_ECHO_DAEMON:
      echo_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_FIND0:
      find0_stub (xdr_in);
      break;
    case GUESTFS_PROC_CASE_SENSITIVE_PATH:
      case_sensitive_path_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_TYPE:
      vfs_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE:
      truncate_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE_SIZE:
      truncate_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_UTIMENS:
      utimens_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_MODE:
      mkdir_mode_stub (xdr_in);
      break;
    case GUESTFS_PROC_LCHOWN:
      lchown_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSTATLIST:
      lstatlist_stub (xdr_in);
      break;
    case GUESTFS_PROC_LXATTRLIST:
      lxattrlist_stub (xdr_in);
      break;
    case GUESTFS_PROC_READLINKLIST:
      readlinklist_stub (xdr_in);
      break;
    case GUESTFS_PROC_PREAD:
      pread_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_INIT:
      part_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_ADD:
      part_add_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_DISK:
      part_disk_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_BOOTABLE:
      part_set_bootable_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_NAME:
      part_set_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_LIST:
      part_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_PARTTYPE:
      part_get_parttype_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL:
      fill_stub (xdr_in);
      break;
    case GUESTFS_PROC_AVAILABLE:
      available_stub (xdr_in);
      break;
    case GUESTFS_PROC_DD:
      dd_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILESIZE:
      filesize_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRENAME:
      lvrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGRENAME:
      vgrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_CAT:
      initrd_cat_stub (xdr_in);
      break;
    default:
      reply_with_error ("dispatch_incoming_message: unknown procedure number %d, set LIBGUESTFS_PATH to point to the matching libguestfs appliance directory", proc_nr);
  }
}

static const char *lvm_pv_cols = "pv_name,pv_uuid,pv_fmt,pv_size,dev_size,pv_free,pv_used,pv_attr,pv_pe_count,pv_pe_alloc_count,pv_tags,pe_start,pv_mda_count,pv_mda_free";

static int lvm_tokenize_pv (char *str, guestfs_int_lvm_pv *r)
{
  char *tok, *p, *next;
  int i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_name = strdup (tok);
  if (r->pv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->pv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_fmt");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_fmt = strdup (tok);
  if (r->pv_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "dev_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->dev_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "dev_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_used");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_used) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_used");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_attr = strdup (tok);
  if (r->pv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_pe_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_alloc_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_pe_alloc_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_alloc_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_tags = strdup (tok);
  if (r->pv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pe_start");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pe_start) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pe_start");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->pv_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_pv_list *
parse_command_line_pvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_pv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_pv_list_len = 0;
  ret->guestfs_int_lvm_pv_list_val = NULL;

  r = command (&out, &err,
	       "/sbin/lvm", "pvs",
	       "-o", lvm_pv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_pv_list_val,
		    sizeof (guestfs_int_lvm_pv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_pv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_pv (p, &ret->guestfs_int_lvm_pv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'pvs' command");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_pv_list_len = i;

  free (out);
  return ret;
}
static const char *lvm_vg_cols = "vg_name,vg_uuid,vg_fmt,vg_attr,vg_size,vg_free,vg_sysid,vg_extent_size,vg_extent_count,vg_free_count,max_lv,max_pv,pv_count,lv_count,snap_count,vg_seqno,vg_tags,vg_mda_count,vg_mda_free";

static int lvm_tokenize_vg (char *str, guestfs_int_lvm_vg *r)
{
  char *tok, *p, *next;
  int i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_name = strdup (tok);
  if (r->vg_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->vg_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_fmt");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_fmt = strdup (tok);
  if (r->vg_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_attr = strdup (tok);
  if (r->vg_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_sysid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_sysid = strdup (tok);
  if (r->vg_sysid == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_extent_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_extent_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_extent_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_extent_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_free_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_free_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_lv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->max_lv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_lv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_pv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->max_pv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_pv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->pv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->snap_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "snap_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_seqno");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_seqno) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_seqno");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_tags = strdup (tok);
  if (r->vg_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->vg_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_free");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->vg_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_vg_list *
parse_command_line_vgs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_vg_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_vg_list_len = 0;
  ret->guestfs_int_lvm_vg_list_val = NULL;

  r = command (&out, &err,
	       "/sbin/lvm", "vgs",
	       "-o", lvm_vg_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_vg_list_val,
		    sizeof (guestfs_int_lvm_vg) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_vg_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_vg (p, &ret->guestfs_int_lvm_vg_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'vgs' command");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_vg_list_len = i;

  free (out);
  return ret;
}
static const char *lvm_lv_cols = "lv_name,lv_uuid,lv_attr,lv_major,lv_minor,lv_kernel_major,lv_kernel_minor,lv_size,seg_count,origin,snap_percent,copy_percent,move_pv,lv_tags,mirror_log,modules";

static int lvm_tokenize_lv (char *str, guestfs_int_lvm_lv *r)
{
  char *tok, *p, *next;
  int i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_name");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_name = strdup (tok);
  if (r->lv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_uuid");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->lv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_attr");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_attr = strdup (tok);
  if (r->lv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_major");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_minor");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_major");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_kernel_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_minor");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->lv_kernel_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_size");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNu64, &r->lv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "lv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "seg_count");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%"SCNi64, &r->seg_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "seg_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "origin");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->origin = strdup (tok);
  if (r->origin == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_percent");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->snap_percent = -1;
  else if (sscanf (tok, "%f", &r->snap_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "snap_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "copy_percent");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->copy_percent = -1;
  else if (sscanf (tok, "%f", &r->copy_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "copy_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "move_pv");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->move_pv = strdup (tok);
  if (r->move_pv == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_tags");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_tags = strdup (tok);
  if (r->lv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "mirror_log");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->mirror_log = strdup (tok);
  if (r->mirror_log == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "modules");
    return -1;
  }
  p = strchrnul (tok, ',');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->modules = strdup (tok);
  if (r->modules == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_lv_list *
parse_command_line_lvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_lv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_lv_list_len = 0;
  ret->guestfs_int_lvm_lv_list_val = NULL;

  r = command (&out, &err,
	       "/sbin/lvm", "lvs",
	       "-o", lvm_lv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ",", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_lv_list_val,
		    sizeof (guestfs_int_lvm_lv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_lv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_lv (p, &ret->guestfs_int_lvm_lv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'lvs' command");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_lv_list_len = i;

  free (out);
  return ret;
}
