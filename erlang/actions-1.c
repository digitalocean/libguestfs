/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <erl_interface.h>
/* We should switch over to using
  #include <ei.h>
instead of erl_interface.
*/

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

#include "actions.h"

ETERM *
run_aug_clear (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_clear (g, augpath);
  if (r == -1)
    return make_error ("aug_clear");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_defvar (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *expr;
  if (atom_equals (ARG (1), "undefined"))
    expr = NULL;
  else
    expr = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    return make_error ("aug_defvar");

  return erl_mk_int (r);
}

ETERM *
run_base64_in (ETERM *message)
{
  CLEANUP_FREE char *base64file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1)
    return make_error ("base64_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_base64_out (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *base64file = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1)
    return make_error ("base64_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_balance_resume (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_balance_resume (g, path);
  if (r == -1)
    return make_error ("btrfs_balance_resume");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_fsck (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "superblock")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      optargs_s.superblock = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "repair")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      optargs_s.repair = get_bool (hd_value);
    }
    else
      return unknown_optarg ("btrfs_fsck", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  if (r == -1)
    return make_error ("btrfs_fsck");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_qgroup_show (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_btrfsqgroup_list *r;

  r = guestfs_btrfs_qgroup_show (g, path);
  if (r == NULL)
    return make_error ("btrfs_qgroup_show");

  ETERM *rt = make_btrfsqgroup_list (r);
  guestfs_free_btrfsqgroup_list (r);
  return rt;
}

ETERM *
run_btrfs_rescue_chunk_recover (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_rescue_chunk_recover (g, device);
  if (r == -1)
    return make_error ("btrfs_rescue_chunk_recover");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_scrub_resume (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_scrub_resume (g, path);
  if (r == -1)
    return make_error ("btrfs_scrub_resume");

  return erl_mk_atom ("ok");
}

ETERM *
run_cat (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_cat (g, path);
  if (r == NULL)
    return make_error ("cat");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_checksum_device (ETERM *message)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL)
    return make_error ("checksum_device");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_clear_backend_setting (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_clear_backend_setting (g, name);
  if (r == -1)
    return make_error ("clear_backend_setting");

  return erl_mk_int (r);
}

ETERM *
run_config (ETERM *message)
{
  CLEANUP_FREE char *hvparam = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *hvvalue;
  if (atom_equals (ARG (1), "undefined"))
    hvvalue = NULL;
  else
    hvvalue = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_config (g, hvparam, hvvalue);
  if (r == -1)
    return make_error ("config");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_attributes (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "all")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
      optargs_s.all = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "mode")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
      optargs_s.mode = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "xattributes")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
      optargs_s.xattributes = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "ownership")) {
      optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
      optargs_s.ownership = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_attributes", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_attributes");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_device_to_device (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "append")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
      optargs_s.append = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_device_to_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_dd (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    return make_error ("dd");

  return erl_mk_atom ("ok");
}

ETERM *
run_debug_drives (ETERM *message)
{
  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    return make_error ("debug_drives");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_device_index (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_device_index (g, device);
  if (r == -1)
    return make_error ("device_index");

  return erl_mk_int (r);
}

ETERM *
run_download_inode (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t inode = get_int64 (ARG (1));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_download_inode (g, device, inode, filename);
  if (r == -1)
    return make_error ("download_inode");

  return erl_mk_atom ("ok");
}

ETERM *
run_exists (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_exists (g, path);
  if (r == -1)
    return make_error ("exists");

  return make_bool (r);
}

ETERM *
run_filesystem_walk (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_tsk_dirent_list *r;

  r = guestfs_filesystem_walk (g, device);
  if (r == NULL)
    return make_error ("filesystem_walk");

  ETERM *rt = make_tsk_dirent_list (r);
  guestfs_free_tsk_dirent_list (r);
  return rt;
}

ETERM *
run_fill_dir (ETERM *message)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int nr = get_int (ARG (1));
  int r;

  r = guestfs_fill_dir (g, dir, nr);
  if (r == -1)
    return make_error ("fill_dir");

  return erl_mk_atom ("ok");
}

ETERM *
run_findfs_label (ETERM *message)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_label (g, label);
  if (r == NULL)
    return make_error ("findfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_identifier (ETERM *message)
{
  const char *r;

  r = guestfs_get_identifier (g);
  if (r == NULL)
    return make_error ("get_identifier");

  return erl_mk_string (r);
}

ETERM *
run_get_libvirt_requested_credential_prompt (ETERM *message)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_prompt");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_network (ETERM *message)
{
  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    return make_error ("get_network");

  return make_bool (r);
}

ETERM *
run_get_qemu (ETERM *message)
{
  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    return make_error ("get_qemu");

  return erl_mk_string (r);
}

ETERM *
run_get_state (ETERM *message)
{
  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    return make_error ("get_state");

  return erl_mk_int (r);
}

ETERM *
run_get_umask (ETERM *message)
{
  int r;

  r = guestfs_get_umask (g);
  if (r == -1)
    return make_error ("get_umask");

  return erl_mk_int (r);
}

ETERM *
run_get_verbose (ETERM *message)
{
  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    return make_error ("get_verbose");

  return make_bool (r);
}

ETERM *
run_getxattrs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    return make_error ("getxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

ETERM *
run_grep (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));

  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "extended")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
      optargs_s.extended = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "fixed")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
      optargs_s.fixed = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "insensitive")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
      optargs_s.insensitive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "compressed")) {
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
      optargs_s.compressed = get_bool (hd_value);
    }
    else
      return unknown_optarg ("grep", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char **r;

  r = guestfs_grep_opts_argv (g, regex, path, optargs);
  if (r == NULL)
    return make_error ("grep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_hivex_node_parent (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_hivex_node_parent (g, nodeh);
  if (r == -1)
    return make_error ("hivex_node_parent");

  return erl_mk_longlong (r);
}

ETERM *
run_hivex_root (ETERM *message)
{
  int64_t r;

  r = guestfs_hivex_root (g);
  if (r == -1)
    return make_error ("hivex_root");

  return erl_mk_longlong (r);
}

ETERM *
run_hivex_value_value (ETERM *message)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;
  size_t size;

  r = guestfs_hivex_value_value (g, valueh, &size);
  if (r == NULL)
    return make_error ("hivex_value_value");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_initrd_list (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    return make_error ("initrd_list");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_inotify_files (ETERM *message)
{
  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    return make_error ("inotify_files");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_inotify_rm_watch (ETERM *message)
{
  int wd = get_int (ARG (0));
  int r;

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    return make_error ("inotify_rm_watch");

  return erl_mk_atom ("ok");
}

ETERM *
run_inspect_get_icon (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));

  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "favicon")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      optargs_s.favicon = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "highquality")) {
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      optargs_s.highquality = get_bool (hd_value);
    }
    else
      return unknown_optarg ("inspect_get_icon", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char *r;
  size_t size;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL)
    return make_error ("inspect_get_icon");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_inspect_is_netinst (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1)
    return make_error ("inspect_is_netinst");

  return make_bool (r);
}

ETERM *
run_inspect_list_applications2 (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  struct guestfs_application2_list *r;

  r = guestfs_inspect_list_applications2 (g, root);
  if (r == NULL)
    return make_error ("inspect_list_applications2");

  ETERM *rt = make_application2_list (r);
  guestfs_free_application2_list (r);
  return rt;
}

ETERM *
run_internal_test_rbufferouterr (ETERM *message)
{
  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferouterr (g, &size);
  if (r == NULL)
    return make_error ("internal_test_rbufferouterr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_internal_test_rconstoptstring (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_internal_test_rconstoptstring (g, val);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

ETERM *
run_internal_test_rint64 (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_internal_test_rint64 (g, val);
  if (r == -1)
    return make_error ("internal_test_rint64");

  return erl_mk_longlong (r);
}

ETERM *
run_internal_test_rstringerr (ETERM *message)
{
  char *r;

  r = guestfs_internal_test_rstringerr (g);
  if (r == NULL)
    return make_error ("internal_test_rstringerr");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_internal_test_rstructlist (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlist (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstructlist");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

ETERM *
run_internal_test_rstructlisterr (ETERM *message)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlisterr (g);
  if (r == NULL)
    return make_error ("internal_test_rstructlisterr");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

ETERM *
run_is_symlink (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_symlink (g, path);
  if (r == -1)
    return make_error ("is_symlink");

  return make_bool (r);
}

ETERM *
run_is_zero (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero (g, path);
  if (r == -1)
    return make_error ("is_zero");

  return make_bool (r);
}

ETERM *
run_lchown (ETERM *message)
{
  int owner = get_int (ARG (0));
  int group = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    return make_error ("lchown");

  return erl_mk_atom ("ok");
}

ETERM *
run_ldmtool_create_all (ETERM *message)
{
  int r;

  r = guestfs_ldmtool_create_all (g);
  if (r == -1)
    return make_error ("ldmtool_create_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_ldmtool_diskgroup_disks (ETERM *message)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_disks");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_list_partitions (ETERM *message)
{
  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    return make_error ("list_partitions");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_llz (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_llz (g, directory);
  if (r == NULL)
    return make_error ("llz");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_lstat (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_lstat (g, path);
  if (r == NULL)
    return make_error ("lstat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

ETERM *
run_lstatlist (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  struct guestfs_stat_list *r;

  r = guestfs_lstatlist (g, path, names);
  if (r == NULL)
    return make_error ("lstatlist");

  ETERM *rt = make_stat_list (r);
  guestfs_free_stat_list (r);
  return rt;
}

ETERM *
run_luks_open (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1)
    return make_error ("luks_open");

  return erl_mk_atom ("ok");
}

ETERM *
run_luks_open_ro (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mapname = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1)
    return make_error ("luks_open_ro");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvm_remove_all (ETERM *message)
{
  int r;

  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    return make_error ("lvm_remove_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvresize_free (ETERM *message)
{
  CLEANUP_FREE char *lv = erl_iolist_to_string (ARG (0));
  int percent = get_int (ARG (1));
  int r;

  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1)
    return make_error ("lvresize_free");

  return erl_mk_atom ("ok");
}

ETERM *
run_md_create (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (1));

  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "missingbitmap")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      optargs_s.missingbitmap = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "nrdevices")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      optargs_s.nrdevices = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "spare")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      optargs_s.spare = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "chunk")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      optargs_s.chunk = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      optargs_s.level = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("md_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_md_create_argv (g, name, devices, optargs);
  if ((optargs_s.bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK))
    free ((char *) optargs_s.level);
  if (r == -1)
    return make_error ("md_create");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkdtemp (ETERM *message)
{
  CLEANUP_FREE char *tmpl = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_mkdtemp (g, tmpl);
  if (r == NULL)
    return make_error ("mkdtemp");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_mknod (ETERM *message)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount (g, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_local_run (ETERM *message)
{
  int r;

  r = guestfs_mount_local_run (g);
  if (r == -1)
    return make_error ("mount_local_run");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_ro (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_ro (g, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_ro");

  return erl_mk_atom ("ok");
}

ETERM *
run_mountable_subvolume (ETERM *message)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_mountable_subvolume (g, mountable);
  if (r == NULL)
    return make_error ("mountable_subvolume");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_mounts (ETERM *message)
{
  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    return make_error ("mounts");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_ntfs_3g_probe (ETERM *message)
{
  int rw = get_bool (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    return make_error ("ntfs_3g_probe");

  return erl_mk_int (r);
}

ETERM *
run_ntfsclone_out (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *backupfile = erl_iolist_to_string (ARG (1));

  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "metadataonly")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      optargs_s.metadataonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "rescue")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      optargs_s.rescue = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "ignorefscheck")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      optargs_s.ignorefscheck = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "preservetimestamps")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      optargs_s.preservetimestamps = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsclone_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  if (r == -1)
    return make_error ("ntfsclone_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_disk_guid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *guid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_set_disk_guid (g, device, guid);
  if (r == -1)
    return make_error ("part_set_disk_guid");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_disk_guid_random (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_part_set_disk_guid_random (g, device);
  if (r == -1)
    return make_error ("part_set_disk_guid_random");

  return erl_mk_atom ("ok");
}

ETERM *
run_pread (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int count = get_int (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL)
    return make_error ("pread");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_realpath (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_realpath (g, path);
  if (r == NULL)
    return make_error ("realpath");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_selinux_relabel (ETERM *message)
{
  CLEANUP_FREE char *specfile = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));

  struct guestfs_selinux_relabel_argv optargs_s = { .bitmask = 0 };
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_SELINUX_RELABEL_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("selinux_relabel", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);
  if (r == -1)
    return make_error ("selinux_relabel");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_autosync (ETERM *message)
{
  int autosync = get_bool (ARG (0));
  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    return make_error ("set_autosync");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_backend_setting (ETERM *message)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_backend_setting (g, name, val);
  if (r == -1)
    return make_error ("set_backend_setting");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_identifier (ETERM *message)
{
  CLEANUP_FREE char *identifier = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_identifier (g, identifier);
  if (r == -1)
    return make_error ("set_identifier");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_verbose (ETERM *message)
{
  int verbose = get_bool (ARG (0));
  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    return make_error ("set_verbose");

  return erl_mk_atom ("ok");
}

ETERM *
run_swapoff_file (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    return make_error ("swapoff_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_syslinux (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "directory")) {
      optargs_s.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
      optargs_s.directory = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("syslinux", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_syslinux_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_SYSLINUX_DIRECTORY_BITMASK))
    free ((char *) optargs_s.directory);
  if (r == -1)
    return make_error ("syslinux");

  return erl_mk_atom ("ok");
}

ETERM *
run_tail (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tail (g, path);
  if (r == NULL)
    return make_error ("tail");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_touch (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_touch (g, path);
  if (r == -1)
    return make_error ("touch");

  return erl_mk_atom ("ok");
}

ETERM *
run_tune2fs_l (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    return make_error ("tune2fs_l");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_umount (ETERM *message)
{
  CLEANUP_FREE char *pathordevice = erl_iolist_to_string (ARG (0));

  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyunmount")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
      optargs_s.lazyunmount = get_bool (hd_value);
    }
    else
      return unknown_optarg ("umount", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  if (r == -1)
    return make_error ("umount");

  return erl_mk_atom ("ok");
}

ETERM *
run_vg_activate (ETERM *message)
{
  int activate = get_bool (ARG (0));
  CLEANUP_FREE_STRING_LIST char **volgroups = get_string_list (ARG (1));
  int r;

  r = guestfs_vg_activate (g, activate, volgroups);
  if (r == -1)
    return make_error ("vg_activate");

  return erl_mk_atom ("ok");
}

ETERM *
run_vgs_full (ETERM *message)
{
  struct guestfs_lvm_vg_list *r;

  r = guestfs_vgs_full (g);
  if (r == NULL)
    return make_error ("vgs_full");

  ETERM *rt = make_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  return rt;
}

ETERM *
run_vgscan (ETERM *message)
{
  int r;

  r = guestfs_vgscan (g);
  if (r == -1)
    return make_error ("vgscan");

  return erl_mk_atom ("ok");
}

ETERM *
run_xfs_admin (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "extunwritten")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
      optargs_s.extunwritten = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "imgfile")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
      optargs_s.imgfile = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "v2log")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
      optargs_s.v2log = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "projid32bit")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
      optargs_s.projid32bit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazycounter")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
      optargs_s.lazycounter = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("xfs_admin", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_admin_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("xfs_admin");

  return erl_mk_atom ("ok");
}

ETERM *
run_zegrepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    return make_error ("zegrepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_zfgrep (ETERM *message)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    return make_error ("zfgrep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_zfile (ETERM *message)
{
  CLEANUP_FREE char *meth = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    return make_error ("zfile");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}
