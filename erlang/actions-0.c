/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
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
run_acl_delete_def_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_acl_delete_def_file (g, dir);
  if (r == -1)
    return make_error ("acl_delete_def_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_add_domain (ETERM *args_tuple)
{
  CLEANUP_FREE char *dom = erl_iolist_to_string (ARG (0));

  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "libvirturi")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      optargs_s.libvirturi = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "live")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      optargs_s.live = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "allowuuid")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      optargs_s.allowuuid = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonlydisk")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      optargs_s.readonlydisk = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachemode")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK;
      optargs_s.cachemode = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "discard")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_DISCARD_BITMASK;
      optargs_s.discard = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "copyonread")) {
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK;
      optargs_s.copyonread = get_bool (hd_value);
    }
    else
      return unknown_optarg ("add_domain", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_domain_argv (g, dom, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK))
    free ((char *) optargs_s.libvirturi);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK))
    free ((char *) optargs_s.readonlydisk);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK))
    free ((char *) optargs_s.cachemode);
  if ((optargs_s.bitmask & GUESTFS_ADD_DOMAIN_DISCARD_BITMASK))
    free ((char *) optargs_s.discard);
  if (r == -1)
    return make_error ("add_domain");

  return erl_mk_int (r);
}

ETERM *
run_add_drive_ro (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    return make_error ("add_drive_ro");

  return erl_mk_atom ("ok");
}

ETERM *
run_add_drive_ro_with_if (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    return make_error ("add_drive_ro_with_if");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_ls (ETERM *args_tuple)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_ls (g, augpath);
  if (r == NULL)
    return make_error ("aug_ls");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_aug_match (ETERM *args_tuple)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_aug_match (g, augpath);
  if (r == NULL)
    return make_error ("aug_match");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_aug_transform (ETERM *args_tuple)
{
  CLEANUP_FREE char *lens = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (1));

  struct guestfs_aug_transform_argv optargs_s = { .bitmask = 0 };
  struct guestfs_aug_transform_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "remove")) {
      optargs_s.bitmask |= GUESTFS_AUG_TRANSFORM_REMOVE_BITMASK;
      optargs_s.remove = get_bool (hd_value);
    }
    else
      return unknown_optarg ("aug_transform", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_aug_transform_argv (g, lens, file, optargs);
  if (r == -1)
    return make_error ("aug_transform");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_qgroup_create (ETERM *args_tuple)
{
  CLEANUP_FREE char *qgroupid = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);
  if (r == -1)
    return make_error ("btrfs_qgroup_create");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_rescue_super_recover (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_rescue_super_recover (g, device);
  if (r == -1)
    return make_error ("btrfs_rescue_super_recover");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfstune_enable_extended_inode_refs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfstune_enable_extended_inode_refs (g, device);
  if (r == -1)
    return make_error ("btrfstune_enable_extended_inode_refs");

  return erl_mk_atom ("ok");
}

ETERM *
run_command_lines (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **arguments = get_string_list (ARG (0));
  char **r;

  r = guestfs_command_lines (g, arguments);
  if (r == NULL)
    return make_error ("command_lines");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_compress_device_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *ctype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *zdevice = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      optargs_s.level = get_int (hd_value);
    }
    else
      return unknown_optarg ("compress_device_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1)
    return make_error ("compress_device_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_compress_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *ctype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *zfile = erl_iolist_to_string (ARG (2));

  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "level")) {
      optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      optargs_s.level = get_int (hd_value);
    }
    else
      return unknown_optarg ("compress_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1)
    return make_error ("compress_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *localpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remotedir = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_copy_in (g, localpath, remotedir);
  if (r == -1)
    return make_error ("copy_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_cp (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    return make_error ("cp");

  return erl_mk_atom ("ok");
}

ETERM *
run_df_h (ETERM *args_tuple)
{
  char *r;

  r = guestfs_df_h (g);
  if (r == NULL)
    return make_error ("df_h");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_disk_has_backing_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_disk_has_backing_file (g, filename);
  if (r == -1)
    return make_error ("disk_has_backing_file");

  return make_bool (r);
}

ETERM *
run_e2fsck (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "correct")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      optargs_s.correct = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "forceall")) {
      optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      optargs_s.forceall = get_bool (hd_value);
    }
    else
      return unknown_optarg ("e2fsck", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_e2fsck_argv (g, device, optargs);
  if (r == -1)
    return make_error ("e2fsck");

  return erl_mk_atom ("ok");
}

ETERM *
run_extlinux (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_extlinux (g, directory);
  if (r == -1)
    return make_error ("extlinux");

  return erl_mk_atom ("ok");
}

ETERM *
run_fsck (ETERM *args_tuple)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    return make_error ("fsck");

  return erl_mk_int (r);
}

ETERM *
run_get_attach_method (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    return make_error ("get_attach_method");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_cachedir (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_cachedir (g);
  if (r == NULL)
    return make_error ("get_cachedir");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_libvirt_requested_credential_defresult (ETERM *args_tuple)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_defresult");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_path (ETERM *args_tuple)
{
  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    return make_error ("get_path");

  return erl_mk_string (r);
}

ETERM *
run_get_pgroup (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    return make_error ("get_pgroup");

  return make_bool (r);
}

ETERM *
run_get_smp (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    return make_error ("get_smp");

  return erl_mk_int (r);
}

ETERM *
run_get_sockdir (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_sockdir (g);
  if (r == NULL)
    return make_error ("get_sockdir");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_trace (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    return make_error ("get_trace");

  return make_bool (r);
}

ETERM *
run_hivex_node_get_child (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_get_child (g, nodeh, name);
  if (r == -1)
    return make_error ("hivex_node_get_child");

  return erl_mk_longlong (r);
}

ETERM *
run_hivex_node_set_value (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int64_t t = get_int64 (ARG (2));
  ETERM *val_bin = erl_iolist_to_binary (ARG (3));
  const void *val = ERL_BIN_PTR (val_bin);
  size_t val_size = ERL_BIN_SIZE (val_bin);
  int r;

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
  if (r == -1)
    return make_error ("hivex_node_set_value");

  return erl_mk_atom ("ok");
}

ETERM *
run_hivex_value_key (ETERM *args_tuple)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_value_key (g, valueh);
  if (r == NULL)
    return make_error ("hivex_value_key");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_hivex_value_type (ETERM *args_tuple)
{
  int64_t valueh = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_hivex_value_type (g, valueh);
  if (r == -1)
    return make_error ("hivex_value_type");

  return erl_mk_longlong (r);
}

ETERM *
run_inspect_get_distro (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL)
    return make_error ("inspect_get_distro");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_filesystems (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_filesystems (g, root);
  if (r == NULL)
    return make_error ("inspect_get_filesystems");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_inspect_get_minor_version (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1)
    return make_error ("inspect_get_minor_version");

  return erl_mk_int (r);
}

ETERM *
run_inspect_get_package_format (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL)
    return make_error ("inspect_get_package_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_product_variant (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL)
    return make_error ("inspect_get_product_variant");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_windows_software_hive (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_software_hive (g, root);
  if (r == NULL)
    return make_error ("inspect_get_windows_software_hive");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_list_applications (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  struct guestfs_application_list *r;

  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL)
    return make_error ("inspect_list_applications");

  ETERM *rt = make_application_list (r);
  guestfs_free_application_list (r);
  return rt;
}

ETERM *
run_inspect_os (ETERM *args_tuple)
{
  char **r;

  r = guestfs_inspect_os (g);
  if (r == NULL)
    return make_error ("inspect_os");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_internal_test_rboolerr (ETERM *args_tuple)
{
  int r;

  r = guestfs_internal_test_rboolerr (g);
  if (r == -1)
    return make_error ("internal_test_rboolerr");

  return make_bool (r);
}

ETERM *
run_internal_test_rstring (ETERM *args_tuple)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_internal_test_rstring (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstring");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_internal_test_rstructerr (ETERM *args_tuple)
{
  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstructerr (g);
  if (r == NULL)
    return make_error ("internal_test_rstructerr");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

ETERM *
run_journal_get (ETERM *args_tuple)
{
  struct guestfs_xattr_list *r;

  r = guestfs_journal_get (g);
  if (r == NULL)
    return make_error ("journal_get");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

ETERM *
run_journal_get_data_threshold (ETERM *args_tuple)
{
  int64_t r;

  r = guestfs_journal_get_data_threshold (g);
  if (r == -1)
    return make_error ("journal_get_data_threshold");

  return erl_mk_longlong (r);
}

ETERM *
run_ldmtool_diskgroup_name (ETERM *args_tuple)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_ldmtool_diskgroup_volumes (ETERM *args_tuple)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
  if (r == NULL)
    return make_error ("ldmtool_diskgroup_volumes");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_ll (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_ll (g, directory);
  if (r == NULL)
    return make_error ("ll");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_ln_f (ETERM *args_tuple)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    return make_error ("ln_f");

  return erl_mk_atom ("ok");
}

ETERM *
run_ln_s (ETERM *args_tuple)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    return make_error ("ln_s");

  return erl_mk_atom ("ok");
}

ETERM *
run_lremovexattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    return make_error ("lremovexattr");

  return erl_mk_atom ("ok");
}

ETERM *
run_lstatnslist (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  struct guestfs_statns_list *r;

  r = guestfs_lstatnslist (g, path, names);
  if (r == NULL)
    return make_error ("lstatnslist");

  ETERM *rt = make_statns_list (r);
  guestfs_free_statns_list (r);
  return rt;
}

ETERM *
run_luks_close (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_luks_close (g, device);
  if (r == -1)
    return make_error ("luks_close");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvremove (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_lvremove (g, device);
  if (r == -1)
    return make_error ("lvremove");

  return erl_mk_atom ("ok");
}

ETERM *
run_md_stop (ETERM *args_tuple)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_md_stop (g, md);
  if (r == -1)
    return make_error ("md_stop");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkfs_btrfs (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));

  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "allocstart")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
      optargs_s.allocstart = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bytecount")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
      optargs_s.bytecount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "datatype")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
      optargs_s.datatype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "leafsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
      optargs_s.leafsize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "metadata")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
      optargs_s.metadata = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "nodesize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
      optargs_s.nodesize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "sectorsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = get_int (hd_value);
    }
    else
      return unknown_optarg ("mkfs_btrfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK))
    free ((char *) optargs_s.datatype);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK))
    free ((char *) optargs_s.metadata);
  if (r == -1)
    return make_error ("mkfs_btrfs");

  return erl_mk_atom ("ok");
}

ETERM *
run_mklost_and_found (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mklost_and_found (g, mountpoint);
  if (r == -1)
    return make_error ("mklost_and_found");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkmountpoint (ETERM *args_tuple)
{
  CLEANUP_FREE char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    return make_error ("mkmountpoint");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkswap_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    return make_error ("mkswap_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_9p (ETERM *args_tuple)
{
  CLEANUP_FREE char *mounttag = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));

  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "options")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      optargs_s.options = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mount_9p", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if ((optargs_s.bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK))
    free ((char *) optargs_s.options);
  if (r == -1)
    return make_error ("mount_9p");

  return erl_mk_atom ("ok");
}

ETERM *
run_mountable_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_mountable_device (g, mountable);
  if (r == NULL)
    return make_error ("mountable_device");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_mv (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    return make_error ("mv");

  return erl_mk_atom ("ok");
}

ETERM *
run_ntfsresize (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsresize", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1)
    return make_error ("ntfsresize");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_disk (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    return make_error ("part_disk");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_expand_gpt (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_part_expand_gpt (g, device);
  if (r == -1)
    return make_error ("part_expand_gpt");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_get_parttype (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    return make_error ("part_get_parttype");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_pvcreate (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    return make_error ("pvcreate");

  return erl_mk_atom ("ok");
}

ETERM *
run_pvs (ETERM *args_tuple)
{
  char **r;

  r = guestfs_pvs (g);
  if (r == NULL)
    return make_error ("pvs");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_pwrite (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1)
    return make_error ("pwrite");

  return erl_mk_int (r);
}

ETERM *
run_read_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    return make_error ("read_file");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_rename (ETERM *args_tuple)
{
  CLEANUP_FREE char *oldpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newpath = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_rename (g, oldpath, newpath);
  if (r == -1)
    return make_error ("rename");

  return erl_mk_atom ("ok");
}

ETERM *
run_resize2fs_M (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs_M (g, device);
  if (r == -1)
    return make_error ("resize2fs_M");

  return erl_mk_atom ("ok");
}

ETERM *
run_rm_rf (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    return make_error ("rm_rf");

  return erl_mk_atom ("ok");
}

ETERM *
run_scrub_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    return make_error ("scrub_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_append (ETERM *args_tuple)
{
  CLEANUP_FREE char *append;
  if (atom_equals (ARG (0), "undefined"))
    append = NULL;
  else
    append = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_append (g, append);
  if (r == -1)
    return make_error ("set_append");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_backend (ETERM *args_tuple)
{
  CLEANUP_FREE char *backend = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_backend (g, backend);
  if (r == -1)
    return make_error ("set_backend");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_direct (ETERM *args_tuple)
{
  int direct = get_bool (ARG (0));
  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    return make_error ("set_direct");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_memsize (ETERM *args_tuple)
{
  int memsize = get_int (ARG (0));
  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    return make_error ("set_memsize");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_program (ETERM *args_tuple)
{
  CLEANUP_FREE char *program = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_program (g, program);
  if (r == -1)
    return make_error ("set_program");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_selinux (ETERM *args_tuple)
{
  int selinux = get_bool (ARG (0));
  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    return make_error ("set_selinux");

  return erl_mk_atom ("ok");
}

ETERM *
run_setxattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int vallen = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return make_error ("setxattr");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdisk_l (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    return make_error ("sfdisk_l");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_umount_local (ETERM *args_tuple)
{

  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "retry")) {
      optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
      optargs_s.retry = get_bool (hd_value);
    }
    else
      return unknown_optarg ("umount_local", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_umount_local_argv (g, optargs);
  if (r == -1)
    return make_error ("umount_local");

  return erl_mk_atom ("ok");
}

ETERM *
run_vfs_label (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_label (g, mountable);
  if (r == NULL)
    return make_error ("vfs_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_vg_activate_all (ETERM *args_tuple)
{
  int activate = get_bool (ARG (0));
  int r;

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    return make_error ("vg_activate_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_vgchange_uuid_all (ETERM *args_tuple)
{
  int r;

  r = guestfs_vgchange_uuid_all (g);
  if (r == -1)
    return make_error ("vgchange_uuid_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_vgmeta (ETERM *args_tuple)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_vgmeta (g, vgname, &size);
  if (r == NULL)
    return make_error ("vgmeta");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_vgrename (ETERM *args_tuple)
{
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newvolgroup = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    return make_error ("vgrename");

  return erl_mk_atom ("ok");
}

ETERM *
run_vguuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vguuid (g, vgname);
  if (r == NULL)
    return make_error ("vguuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_wc_w (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_w (g, path);
  if (r == -1)
    return make_error ("wc_w");

  return erl_mk_int (r);
}

ETERM *
run_write (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int r;

  r = guestfs_write (g, path, content, content_size);
  if (r == -1)
    return make_error ("write");

  return erl_mk_atom ("ok");
}

ETERM *
run_zfgrepi (ETERM *args_tuple)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL)
    return make_error ("zfgrepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}
