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
#include "guestfs-utils.h"

#include "actions.h"

ETERM *
run_add_drive (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));

  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "format")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      optargs_s.format = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "name")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      optargs_s.name = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "protocol")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      optargs_s.protocol = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "server")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
      optargs_s.server = get_string_list (hd_value);
    }
    else
    if (atom_equals (hd_name, "username")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
      optargs_s.username = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "secret")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
      optargs_s.secret = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachemode")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
      optargs_s.cachemode = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "discard")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
      optargs_s.discard = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "copyonread")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
      optargs_s.copyonread = get_bool (hd_value);
    }
    else
      return unknown_optarg ("add_drive", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK))
    free ((char *) optargs_s.format);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK))
    free ((char *) optargs_s.name);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK))
    free ((char *) optargs_s.protocol);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK))
    guestfs_int_free_string_list ((char **) optargs_s.server);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK))
    free ((char *) optargs_s.username);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK))
    free ((char *) optargs_s.secret);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK))
    free ((char *) optargs_s.cachemode);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK))
    free ((char *) optargs_s.discard);
  if (r == -1)
    return make_error ("add_drive");

  return erl_mk_atom ("ok");
}

ETERM *
run_add_drive_scratch (ETERM *args_tuple)
{
  int64_t size = get_int64 (ARG (0));

  struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "name")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
      optargs_s.name = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("add_drive_scratch", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_drive_scratch_argv (g, size, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK))
    free ((char *) optargs_s.name);
  if ((optargs_s.bitmask & GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if (r == -1)
    return make_error ("add_drive_scratch");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_label (ETERM *args_tuple)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_aug_label (g, augpath);
  if (r == NULL)
    return make_error ("aug_label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_blkdiscardzeroes (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blkdiscardzeroes (g, device);
  if (r == -1)
    return make_error ("blkdiscardzeroes");

  return make_bool (r);
}

ETERM *
run_blockdev_getsize64 (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    return make_error ("blockdev_getsize64");

  return erl_mk_longlong (r);
}

ETERM *
run_blockdev_getss (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    return make_error ("blockdev_getss");

  return erl_mk_int (r);
}

ETERM *
run_blockdev_rereadpt (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    return make_error ("blockdev_rereadpt");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_balance_cancel (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_balance_cancel (g, path);
  if (r == -1)
    return make_error ("btrfs_balance_cancel");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_qgroup_limit (ETERM *args_tuple)
{
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);
  if (r == -1)
    return make_error ("btrfs_qgroup_limit");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_quota_rescan (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_quota_rescan (g, fs);
  if (r == -1)
    return make_error ("btrfs_quota_rescan");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_set_seeding (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int seeding = get_bool (ARG (1));
  int r;

  r = guestfs_btrfs_set_seeding (g, device, seeding);
  if (r == -1)
    return make_error ("btrfs_set_seeding");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_show (ETERM *args_tuple)
{
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_btrfs_subvolume_show (g, subvolume);
  if (r == NULL)
    return make_error ("btrfs_subvolume_show");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_chown (ETERM *args_tuple)
{
  int owner = get_int (ARG (0));
  int group = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    return make_error ("chown");

  return erl_mk_atom ("ok");
}

ETERM *
run_command (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **arguments = get_string_list (ARG (0));
  char *r;

  r = guestfs_command (g, arguments);
  if (r == NULL)
    return make_error ("command");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_copy_device_to_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "append")) {
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
      optargs_s.append = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_device_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_device_to_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_cp_r (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp_r (g, src, dest);
  if (r == -1)
    return make_error ("cp_r");

  return erl_mk_atom ("ok");
}

ETERM *
run_debug (ETERM *args_tuple)
{
  CLEANUP_FREE char *subcmd = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **extraargs = get_string_list (ARG (1));
  char *r;

  r = guestfs_debug (g, subcmd, extraargs);
  if (r == NULL)
    return make_error ("debug");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_drop_caches (ETERM *args_tuple)
{
  int whattodrop = get_int (ARG (0));
  int r;

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    return make_error ("drop_caches");

  return erl_mk_atom ("ok");
}

ETERM *
run_egrep (ETERM *args_tuple)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrep (g, regex, path);
  if (r == NULL)
    return make_error ("egrep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_file_architecture (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file_architecture (g, filename);
  if (r == NULL)
    return make_error ("file_architecture");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_backend (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_backend (g);
  if (r == NULL)
    return make_error ("get_backend");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_e2attrs (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2attrs (g, file);
  if (r == NULL)
    return make_error ("get_e2attrs");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_e2generation (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_get_e2generation (g, file);
  if (r == -1)
    return make_error ("get_e2generation");

  return erl_mk_longlong (r);
}

ETERM *
run_glob_expand (ETERM *args_tuple)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));

  struct guestfs_glob_expand_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "directoryslash")) {
      optargs_s.bitmask |= GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK;
      optargs_s.directoryslash = get_bool (hd_value);
    }
    else
      return unknown_optarg ("glob_expand", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char **r;

  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);
  if (r == NULL)
    return make_error ("glob_expand");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_grub_install (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    return make_error ("grub_install");

  return erl_mk_atom ("ok");
}

ETERM *
run_hivex_node_add_child (ETERM *args_tuple)
{
  int64_t parent = get_int64 (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_add_child (g, parent, name);
  if (r == -1)
    return make_error ("hivex_node_add_child");

  return erl_mk_longlong (r);
}

ETERM *
run_hivex_node_get_value (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int64_t r;

  r = guestfs_hivex_node_get_value (g, nodeh, key);
  if (r == -1)
    return make_error ("hivex_node_get_value");

  return erl_mk_longlong (r);
}

ETERM *
run_inspect_get_arch (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL)
    return make_error ("inspect_get_arch");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_drive_mappings (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL)
    return make_error ("inspect_get_drive_mappings");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_inspect_get_windows_current_control_set (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL)
    return make_error ("inspect_get_windows_current_control_set");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_windows_systemroot (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL)
    return make_error ("inspect_get_windows_systemroot");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_internal_test_close_output (ETERM *args_tuple)
{
  int r;

  r = guestfs_internal_test_close_output (g);
  if (r == -1)
    return make_error ("internal_test_close_output");

  return erl_mk_atom ("ok");
}

ETERM *
run_internal_test_rbufferout (ETERM *args_tuple)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferout (g, val, &size);
  if (r == NULL)
    return make_error ("internal_test_rbufferout");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_internal_test_rconstoptstringerr (ETERM *args_tuple)
{
  const char *r;

  r = guestfs_internal_test_rconstoptstringerr (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

ETERM *
run_internal_test_rinterr (ETERM *args_tuple)
{
  int r;

  r = guestfs_internal_test_rinterr (g);
  if (r == -1)
    return make_error ("internal_test_rinterr");

  return erl_mk_int (r);
}

ETERM *
run_internal_test_set_output (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_set_output (g, filename);
  if (r == -1)
    return make_error ("internal_test_set_output");

  return erl_mk_atom ("ok");
}

ETERM *
run_is_chardev (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_chardev", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_chardev_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_chardev");

  return make_bool (r);
}

ETERM *
run_is_launching (ETERM *args_tuple)
{
  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    return make_error ("is_launching");

  return make_bool (r);
}

ETERM *
run_is_lv (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_lv (g, mountable);
  if (r == -1)
    return make_error ("is_lv");

  return make_bool (r);
}

ETERM *
run_is_socket (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_socket", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_socket_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_socket");

  return make_bool (r);
}

ETERM *
run_journal_open (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_journal_open (g, directory);
  if (r == -1)
    return make_error ("journal_open");

  return erl_mk_atom ("ok");
}

ETERM *
run_kill_subprocess (ETERM *args_tuple)
{
  int r;

  r = guestfs_kill_subprocess (g);
  if (r == -1)
    return make_error ("kill_subprocess");

  return erl_mk_atom ("ok");
}

ETERM *
run_ldmtool_scan_devices (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  char **r;

  r = guestfs_ldmtool_scan_devices (g, devices);
  if (r == NULL)
    return make_error ("ldmtool_scan_devices");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_lsetxattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int vallen = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return make_error ("lsetxattr");

  return erl_mk_atom ("ok");
}

ETERM *
run_luks_kill_slot (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  int r;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1)
    return make_error ("luks_kill_slot");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkdir (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir (g, path);
  if (r == -1)
    return make_error ("mkdir");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkfifo (ETERM *args_tuple)
{
  int mode = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    return make_error ("mkfifo");

  return erl_mk_atom ("ok");
}

ETERM *
run_mksquashfs (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));

  struct guestfs_mksquashfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_MKSQUASHFS_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "excludes")) {
      optargs_s.bitmask |= GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK;
      optargs_s.excludes = get_string_list (hd_value);
    }
    else
      return unknown_optarg ("mksquashfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mksquashfs_argv (g, path, filename, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKSQUASHFS_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if ((optargs_s.bitmask & GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK))
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  if (r == -1)
    return make_error ("mksquashfs");

  return erl_mk_atom ("ok");
}

ETERM *
run_modprobe (ETERM *args_tuple)
{
  CLEANUP_FREE char *modulename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    return make_error ("modprobe");

  return erl_mk_atom ("ok");
}

ETERM *
run_ntfscat_i (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t inode = get_int64 (ARG (1));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_ntfscat_i (g, device, inode, filename);
  if (r == -1)
    return make_error ("ntfscat_i");

  return erl_mk_atom ("ok");
}

ETERM *
run_parse_environment (ETERM *args_tuple)
{
  int r;

  r = guestfs_parse_environment (g);
  if (r == -1)
    return make_error ("parse_environment");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_get_disk_guid (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_get_disk_guid (g, device);
  if (r == NULL)
    return make_error ("part_get_disk_guid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_part_list (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  if (r == NULL)
    return make_error ("part_list");

  ETERM *rt = make_partition_list (r);
  guestfs_free_partition_list (r);
  return rt;
}

ETERM *
run_part_set_bootable (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int bootable = get_bool (ARG (2));
  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    return make_error ("part_set_bootable");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_gpt_attributes (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int64_t attributes = get_int64 (ARG (2));
  int r;

  r = guestfs_part_set_gpt_attributes (g, device, partnum, attributes);
  if (r == -1)
    return make_error ("part_set_gpt_attributes");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_gpt_guid (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  CLEANUP_FREE char *guid = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);
  if (r == -1)
    return make_error ("part_set_gpt_guid");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_to_dev (ETERM *args_tuple)
{
  CLEANUP_FREE char *partition = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_part_to_dev (g, partition);
  if (r == NULL)
    return make_error ("part_to_dev");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_pvresize (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvresize (g, device);
  if (r == -1)
    return make_error ("pvresize");

  return erl_mk_atom ("ok");
}

ETERM *
run_pvs_full (ETERM *args_tuple)
{
  struct guestfs_lvm_pv_list *r;

  r = guestfs_pvs_full (g);
  if (r == NULL)
    return make_error ("pvs_full");

  ETERM *rt = make_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  return rt;
}

ETERM *
run_pwrite_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1)
    return make_error ("pwrite_device");

  return erl_mk_int (r);
}

ETERM *
run_readdir (ETERM *args_tuple)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    return make_error ("readdir");

  ETERM *rt = make_dirent_list (r);
  guestfs_free_dirent_list (r);
  return rt;
}

ETERM *
run_readlink (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_readlink (g, path);
  if (r == NULL)
    return make_error ("readlink");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_resize2fs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    return make_error ("resize2fs");

  return erl_mk_atom ("ok");
}

ETERM *
run_rsync_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *remote = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync_in", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  if (r == -1)
    return make_error ("rsync_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_e2uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    return make_error ("set_e2uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_libvirt_requested_credential (ETERM *args_tuple)
{
  int index = get_int (ARG (0));
  ETERM *cred_bin = erl_iolist_to_binary (ARG (1));
  const void *cred = ERL_BIN_PTR (cred_bin);
  size_t cred_size = ERL_BIN_SIZE (cred_bin);
  int r;

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  if (r == -1)
    return make_error ("set_libvirt_requested_credential");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_libvirt_supported_credentials (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **creds = get_string_list (ARG (0));
  int r;

  r = guestfs_set_libvirt_supported_credentials (g, creds);
  if (r == -1)
    return make_error ("set_libvirt_supported_credentials");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_path (ETERM *args_tuple)
{
  CLEANUP_FREE char *searchpath;
  if (atom_equals (ARG (0), "undefined"))
    searchpath = NULL;
  else
    searchpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    return make_error ("set_path");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_pgroup (ETERM *args_tuple)
{
  int pgroup = get_bool (ARG (0));
  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    return make_error ("set_pgroup");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdisk_disk_geometry (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    return make_error ("sfdisk_disk_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_sh (ETERM *args_tuple)
{
  CLEANUP_FREE char *command = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sh (g, command);
  if (r == NULL)
    return make_error ("sh");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_statns (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_statns *r;

  r = guestfs_statns (g, path);
  if (r == NULL)
    return make_error ("statns");

  ETERM *rt = make_statns (r);
  guestfs_free_statns (r);
  return rt;
}

ETERM *
run_swapon_label (ETERM *args_tuple)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    return make_error ("swapon_label");

  return erl_mk_atom ("ok");
}

ETERM *
run_txz_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1)
    return make_error ("txz_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_umount_all (ETERM *args_tuple)
{
  int r;

  r = guestfs_umount_all (g);
  if (r == -1)
    return make_error ("umount_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_upload_offset (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  int r;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1)
    return make_error ("upload_offset");

  return erl_mk_atom ("ok");
}

ETERM *
run_utsname (ETERM *args_tuple)
{
  struct guestfs_utsname *r;

  r = guestfs_utsname (g);
  if (r == NULL)
    return make_error ("utsname");

  ETERM *rt = make_utsname (r);
  guestfs_free_utsname (r);
  return rt;
}

ETERM *
run_vgpvuuids (ETERM *args_tuple)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL)
    return make_error ("vgpvuuids");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_write_append (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  ETERM *content_bin = erl_iolist_to_binary (ARG (1));
  const void *content = ERL_BIN_PTR (content_bin);
  size_t content_size = ERL_BIN_SIZE (content_bin);
  int r;

  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1)
    return make_error ("write_append");

  return erl_mk_atom ("ok");
}

ETERM *
run_yara_scan (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_yara_detection_list *r;

  r = guestfs_yara_scan (g, path);
  if (r == NULL)
    return make_error ("yara_scan");

  ETERM *rt = make_yara_detection_list (r);
  guestfs_free_yara_detection_list (r);
  return rt;
}

ETERM *
run_zgrep (ETERM *args_tuple)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrep (g, regex, path);
  if (r == NULL)
    return make_error ("zgrep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}
