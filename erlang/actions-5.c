/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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
run_acl_set_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *acltype = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *acl = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_acl_set_file (g, path, acltype, acl);
  if (r == -1)
    return make_error ("acl_set_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_add_drive_with_if (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *iface = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    return make_error ("add_drive_with_if");

  return erl_mk_atom ("ok");
}

ETERM *
run_blockdev_flushbufs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    return make_error ("blockdev_flushbufs");

  return erl_mk_atom ("ok");
}

ETERM *
run_blockdev_setrw (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    return make_error ("blockdev_setrw");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_balance_pause (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_balance_pause (g, path);
  if (r == -1)
    return make_error ("btrfs_balance_pause");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_device_add (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_device_add (g, devices, fs);
  if (r == -1)
    return make_error ("btrfs_device_add");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_filesystem_balance (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_filesystem_balance (g, fs);
  if (r == -1)
    return make_error ("btrfs_filesystem_balance");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_filesystem_show (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_btrfs_filesystem_show (g, device);
  if (r == NULL)
    return make_error ("btrfs_filesystem_show");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_btrfs_qgroup_assign (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dst = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);
  if (r == -1)
    return make_error ("btrfs_qgroup_assign");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_replace (ETERM *args_tuple)
{
  CLEANUP_FREE char *srcdev = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *targetdev = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mntpoint = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);
  if (r == -1)
    return make_error ("btrfs_replace");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_scrub_cancel (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_scrub_cancel (g, path);
  if (r == -1)
    return make_error ("btrfs_scrub_cancel");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_get_default (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_btrfs_subvolume_get_default (g, fs);
  if (r == -1)
    return make_error ("btrfs_subvolume_get_default");

  return erl_mk_longlong (r);
}

ETERM *
run_btrfstune_seeding (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int seeding = get_bool (ARG (1));
  int r;

  r = guestfs_btrfstune_seeding (g, device, seeding);
  if (r == -1)
    return make_error ("btrfstune_seeding");

  return erl_mk_atom ("ok");
}

ETERM *
run_c_pointer (ETERM *args_tuple)
{
  int64_t r;

  r = guestfs_c_pointer (g);
  if (r == -1)
    return make_error ("c_pointer");

  return erl_mk_longlong (r);
}

ETERM *
run_cap_set_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *cap = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cap_set_file (g, path, cap);
  if (r == -1)
    return make_error ("cap_set_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_file_to_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "append")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
      optargs_s.append = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_device", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_file_to_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_file_to_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "srcoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "destoffset")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparse")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
      optargs_s.sparse = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "append")) {
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
      optargs_s.append = get_bool (hd_value);
    }
    else
      return unknown_optarg ("copy_file_to_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("copy_file_to_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_cpio_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *cpiofile = erl_iolist_to_string (ARG (1));

  struct guestfs_cpio_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "format")) {
      optargs_s.bitmask |= GUESTFS_CPIO_OUT_FORMAT_BITMASK;
      optargs_s.format = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("cpio_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);
  if ((optargs_s.bitmask & GUESTFS_CPIO_OUT_FORMAT_BITMASK))
    free ((char *) optargs_s.format);
  if (r == -1)
    return make_error ("cpio_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_disk_virtual_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_disk_virtual_size (g, filename);
  if (r == -1)
    return make_error ("disk_virtual_size");

  return erl_mk_longlong (r);
}

ETERM *
run_download (ETERM *args_tuple)
{
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    return make_error ("download");

  return erl_mk_atom ("ok");
}

ETERM *
run_feature_available (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **groups = get_string_list (ARG (0));
  int r;

  r = guestfs_feature_available (g, groups);
  if (r == -1)
    return make_error ("feature_available");

  return make_bool (r);
}

ETERM *
run_fill_pattern (ETERM *args_tuple)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  int len = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1)
    return make_error ("fill_pattern");

  return erl_mk_atom ("ok");
}

ETERM *
run_find0 (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *files = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    return make_error ("find0");

  return erl_mk_atom ("ok");
}

ETERM *
run_get_append (ETERM *args_tuple)
{
  const char *r;

  r = guestfs_get_append (g);

  ETERM *rt;
  if (r)
    rt = erl_mk_string (r);
  else
    rt = erl_mk_atom ("undefined");
  return rt;
}

ETERM *
run_get_memsize (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    return make_error ("get_memsize");

  return erl_mk_int (r);
}

ETERM *
run_get_program (ETERM *args_tuple)
{
  const char *r;

  r = guestfs_get_program (g);
  if (r == NULL)
    return make_error ("get_program");

  return erl_mk_string (r);
}

ETERM *
run_head_n (ETERM *args_tuple)
{
  int nrlines = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL)
    return make_error ("head_n");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_hivex_commit (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename;
  if (atom_equals (ARG (0), "undefined"))
    filename = NULL;
  else
    filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_hivex_commit (g, filename);
  if (r == -1)
    return make_error ("hivex_commit");

  return erl_mk_atom ("ok");
}

ETERM *
run_hivex_node_delete_child (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  int r;

  r = guestfs_hivex_node_delete_child (g, nodeh);
  if (r == -1)
    return make_error ("hivex_node_delete_child");

  return erl_mk_atom ("ok");
}

ETERM *
run_initrd_cat (ETERM *args_tuple)
{
  CLEANUP_FREE char *initrdpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    return make_error ("initrd_cat");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_inotify_close (ETERM *args_tuple)
{
  int r;

  r = guestfs_inotify_close (g);
  if (r == -1)
    return make_error ("inotify_close");

  return erl_mk_atom ("ok");
}

ETERM *
run_inspect_get_major_version (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1)
    return make_error ("inspect_get_major_version");

  return erl_mk_int (r);
}

ETERM *
run_inspect_get_osinfo (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_osinfo (g, root);
  if (r == NULL)
    return make_error ("inspect_get_osinfo");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_roots (ETERM *args_tuple)
{
  char **r;

  r = guestfs_inspect_get_roots (g);
  if (r == NULL)
    return make_error ("inspect_get_roots");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_internal_test (ETERM *args_tuple)
{
  CLEANUP_FREE char *str = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *optstr;
  if (atom_equals (ARG (1), "undefined"))
    optstr = NULL;
  else
    optstr = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE_STRING_LIST char **strlist = get_string_list (ARG (2));
  int b = get_bool (ARG (3));
  int integer = get_int (ARG (4));
  int64_t integer64 = get_int64 (ARG (5));
  CLEANUP_FREE char *filein = erl_iolist_to_string (ARG (6));
  CLEANUP_FREE char *fileout = erl_iolist_to_string (ARG (7));
  ETERM *bufferin_bin = erl_iolist_to_binary (ARG (8));
  const void *bufferin = ERL_BIN_PTR (bufferin_bin);
  size_t bufferin_size = ERL_BIN_SIZE (bufferin_bin);

  struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (9);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "obool")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
      optargs_s.obool = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
      optargs_s.oint = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "oint64")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
      optargs_s.oint64 = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "ostring")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
      optargs_s.ostring = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "ostringlist")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
      optargs_s.ostringlist = get_string_list (hd_value);
    }
    else
      return unknown_optarg ("internal_test", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  if ((optargs_s.bitmask & GUESTFS_INTERNAL_TEST_OSTRING_BITMASK))
    free ((char *) optargs_s.ostring);
  if ((optargs_s.bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK))
    guestfs_int_free_string_list ((char **) optargs_s.ostringlist);
  if (r == -1)
    return make_error ("internal_test");

  return erl_mk_atom ("ok");
}

ETERM *
run_internal_test_63_optargs (ETERM *args_tuple)
{

  struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "opt1")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
      optargs_s.opt1 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt2")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
      optargs_s.opt2 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt3")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
      optargs_s.opt3 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt4")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
      optargs_s.opt4 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt5")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
      optargs_s.opt5 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt6")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
      optargs_s.opt6 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt7")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
      optargs_s.opt7 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt8")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
      optargs_s.opt8 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt9")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
      optargs_s.opt9 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt10")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
      optargs_s.opt10 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt11")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
      optargs_s.opt11 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt12")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
      optargs_s.opt12 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt13")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
      optargs_s.opt13 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt14")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
      optargs_s.opt14 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt15")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
      optargs_s.opt15 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt16")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
      optargs_s.opt16 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt17")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
      optargs_s.opt17 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt18")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
      optargs_s.opt18 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt19")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
      optargs_s.opt19 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt20")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
      optargs_s.opt20 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt21")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
      optargs_s.opt21 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt22")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
      optargs_s.opt22 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt23")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
      optargs_s.opt23 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt24")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
      optargs_s.opt24 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt25")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
      optargs_s.opt25 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt26")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
      optargs_s.opt26 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt27")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
      optargs_s.opt27 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt28")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
      optargs_s.opt28 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt29")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
      optargs_s.opt29 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt30")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
      optargs_s.opt30 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt31")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
      optargs_s.opt31 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt32")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
      optargs_s.opt32 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt33")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
      optargs_s.opt33 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt34")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
      optargs_s.opt34 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt35")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
      optargs_s.opt35 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt36")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
      optargs_s.opt36 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt37")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
      optargs_s.opt37 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt38")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
      optargs_s.opt38 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt39")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
      optargs_s.opt39 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt40")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
      optargs_s.opt40 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt41")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
      optargs_s.opt41 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt42")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
      optargs_s.opt42 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt43")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
      optargs_s.opt43 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt44")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
      optargs_s.opt44 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt45")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
      optargs_s.opt45 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt46")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
      optargs_s.opt46 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt47")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
      optargs_s.opt47 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt48")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
      optargs_s.opt48 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt49")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
      optargs_s.opt49 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt50")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
      optargs_s.opt50 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt51")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
      optargs_s.opt51 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt52")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
      optargs_s.opt52 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt53")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
      optargs_s.opt53 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt54")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
      optargs_s.opt54 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt55")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
      optargs_s.opt55 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt56")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
      optargs_s.opt56 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt57")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
      optargs_s.opt57 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt58")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
      optargs_s.opt58 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt59")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
      optargs_s.opt59 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt60")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
      optargs_s.opt60 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt61")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
      optargs_s.opt61 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt62")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
      optargs_s.opt62 = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "opt63")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
      optargs_s.opt63 = get_int (hd_value);
    }
    else
      return unknown_optarg ("internal_test_63_optargs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_63_optargs_argv (g, optargs);
  if (r == -1)
    return make_error ("internal_test_63_optargs");

  return erl_mk_atom ("ok");
}

ETERM *
run_internal_test_rhashtableerr (ETERM *args_tuple)
{
  char **r;

  r = guestfs_internal_test_rhashtableerr (g);
  if (r == NULL)
    return make_error ("internal_test_rhashtableerr");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_is_blockdev (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_blockdev", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_blockdev");

  return make_bool (r);
}

ETERM *
run_is_config (ETERM *args_tuple)
{
  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    return make_error ("is_config");

  return make_bool (r);
}

ETERM *
run_is_fifo (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_fifo", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_fifo_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_fifo");

  return make_bool (r);
}

ETERM *
run_isoinfo_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo_device (g, device);
  if (r == NULL)
    return make_error ("isoinfo_device");

  ETERM *rt = make_isoinfo (r);
  guestfs_free_isoinfo (r);
  return rt;
}

ETERM *
run_journal_next (ETERM *args_tuple)
{
  int r;

  r = guestfs_journal_next (g);
  if (r == -1)
    return make_error ("journal_next");

  return make_bool (r);
}

ETERM *
run_journal_skip (ETERM *args_tuple)
{
  int64_t skip = get_int64 (ARG (0));
  int64_t r;

  r = guestfs_journal_skip (g, skip);
  if (r == -1)
    return make_error ("journal_skip");

  return erl_mk_longlong (r);
}

ETERM *
run_ldmtool_volume_partitions (ETERM *args_tuple)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_partitions");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_list_disk_labels (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_disk_labels (g);
  if (r == NULL)
    return make_error ("list_disk_labels");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_list_md_devices (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_md_devices (g);
  if (r == NULL)
    return make_error ("list_md_devices");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_ln (ETERM *args_tuple)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    return make_error ("ln");

  return erl_mk_atom ("ok");
}

ETERM *
run_ln_sf (ETERM *args_tuple)
{
  CLEANUP_FREE char *target = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *linkname = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    return make_error ("ln_sf");

  return erl_mk_atom ("ok");
}

ETERM *
run_luks_add_key (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *newkey = erl_iolist_to_string (ARG (2));
  int keyslot = get_int (ARG (3));
  int r;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1)
    return make_error ("luks_add_key");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvcreate (ETERM *args_tuple)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (1));
  int mbytes = get_int (ARG (2));
  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    return make_error ("lvcreate");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvcreate_free (ETERM *args_tuple)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (1));
  int percent = get_int (ARG (2));
  int r;

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (r == -1)
    return make_error ("lvcreate_free");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvm_set_filter (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  int r;

  r = guestfs_lvm_set_filter (g, devices);
  if (r == -1)
    return make_error ("lvm_set_filter");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvs_full (ETERM *args_tuple)
{
  struct guestfs_lvm_lv_list *r;

  r = guestfs_lvs_full (g);
  if (r == NULL)
    return make_error ("lvs_full");

  ETERM *rt = make_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
  return rt;
}

ETERM *
run_md_stat (ETERM *args_tuple)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  struct guestfs_mdstat_list *r;

  r = guestfs_md_stat (g, md);
  if (r == NULL)
    return make_error ("md_stat");

  ETERM *rt = make_mdstat_list (r);
  guestfs_free_mdstat_list (r);
  return rt;
}

ETERM *
run_mkfs (ETERM *args_tuple)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));

  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "blocksize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "features")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      optargs_s.features = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "inode")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      optargs_s.inode = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "sectorsize")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mkfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK))
    free ((char *) optargs_s.features);
  if ((optargs_s.bitmask & GUESTFS_MKFS_OPTS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if (r == -1)
    return make_error ("mkfs");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkfs_b (ETERM *args_tuple)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    return make_error ("mkfs_b");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkswap_U (ETERM *args_tuple)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    return make_error ("mkswap_U");

  return erl_mk_atom ("ok");
}

ETERM *
run_mountpoints (ETERM *args_tuple)
{
  char **r;

  r = guestfs_mountpoints (g);
  if (r == NULL)
    return make_error ("mountpoints");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_nr_devices (ETERM *args_tuple)
{
  int r;

  r = guestfs_nr_devices (g);
  if (r == -1)
    return make_error ("nr_devices");

  return erl_mk_int (r);
}

ETERM *
run_ntfsclone_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *backupfile = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ntfsclone_in (g, backupfile, device);
  if (r == -1)
    return make_error ("ntfsclone_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_parse_environment_list (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **environment = get_string_list (ARG (0));
  int r;

  r = guestfs_parse_environment_list (g, environment);
  if (r == -1)
    return make_error ("parse_environment_list");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_get_bootable (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1)
    return make_error ("part_get_bootable");

  return make_bool (r);
}

ETERM *
run_part_get_gpt_attributes (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int64_t r;

  r = guestfs_part_get_gpt_attributes (g, device, partnum);
  if (r == -1)
    return make_error ("part_get_gpt_attributes");

  return erl_mk_longlong (r);
}

ETERM *
run_part_set_gpt_type (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  CLEANUP_FREE char *guid = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (r == -1)
    return make_error ("part_set_gpt_type");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_name (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    return make_error ("part_set_name");

  return erl_mk_atom ("ok");
}

ETERM *
run_pvremove (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvremove (g, device);
  if (r == -1)
    return make_error ("pvremove");

  return erl_mk_atom ("ok");
}

ETERM *
run_scrub_freespace (ETERM *args_tuple)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    return make_error ("scrub_freespace");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_attach_method (ETERM *args_tuple)
{
  CLEANUP_FREE char *backend = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_attach_method (g, backend);
  if (r == -1)
    return make_error ("set_attach_method");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_network (ETERM *args_tuple)
{
  int network = get_bool (ARG (0));
  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    return make_error ("set_network");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_smp (ETERM *args_tuple)
{
  int smp = get_int (ARG (0));
  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    return make_error ("set_smp");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_tmpdir (ETERM *args_tuple)
{
  CLEANUP_FREE char *tmpdir;
  if (atom_equals (ARG (0), "undefined"))
    tmpdir = NULL;
  else
    tmpdir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_tmpdir (g, tmpdir);
  if (r == -1)
    return make_error ("set_tmpdir");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_trace (ETERM *args_tuple)
{
  int trace = get_bool (ARG (0));
  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    return make_error ("set_trace");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_uuid_random (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_uuid_random (g, device);
  if (r == -1)
    return make_error ("set_uuid_random");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdisk (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int cyls = get_int (ARG (1));
  int heads = get_int (ARG (2));
  int sectors = get_int (ARG (3));
  CLEANUP_FREE_STRING_LIST char **lines = get_string_list (ARG (4));
  int r;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  if (r == -1)
    return make_error ("sfdisk");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdiskM (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **lines = get_string_list (ARG (1));
  int r;

  r = guestfs_sfdiskM (g, device, lines);
  if (r == -1)
    return make_error ("sfdiskM");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdisk_N (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int cyls = get_int (ARG (2));
  int heads = get_int (ARG (3));
  int sectors = get_int (ARG (4));
  CLEANUP_FREE char *line = erl_iolist_to_string (ARG (5));
  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    return make_error ("sfdisk_N");

  return erl_mk_atom ("ok");
}

ETERM *
run_stat (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_stat *r;

  r = guestfs_stat (g, path);
  if (r == NULL)
    return make_error ("stat");

  ETERM *rt = make_stat (r);
  guestfs_free_stat (r);
  return rt;
}

ETERM *
run_swapoff_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    return make_error ("swapoff_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_swapon_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    return make_error ("swapon_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_swapon_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    return make_error ("swapon_uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_tgz_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    return make_error ("tgz_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_truncate_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    return make_error ("truncate_size");

  return erl_mk_atom ("ok");
}

ETERM *
run_txz_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1)
    return make_error ("txz_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_user_cancel (ETERM *args_tuple)
{
  int r;

  r = guestfs_user_cancel (g);
  if (r == -1)
    return make_error ("user_cancel");

  return erl_mk_atom ("ok");
}

ETERM *
run_vgchange_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *vg = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_vgchange_uuid (g, vg);
  if (r == -1)
    return make_error ("vgchange_uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_vglvuuids (ETERM *args_tuple)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL)
    return make_error ("vglvuuids");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_vgremove (ETERM *args_tuple)
{
  CLEANUP_FREE char *vgname = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    return make_error ("vgremove");

  return erl_mk_atom ("ok");
}

ETERM *
run_wc_l (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_l (g, path);
  if (r == -1)
    return make_error ("wc_l");

  return erl_mk_int (r);
}

ETERM *
run_xfs_growfs (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "datasec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
      optargs_s.datasec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "logsec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
      optargs_s.logsec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtsec")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
      optargs_s.rtsec = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "datasize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
      optargs_s.datasize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "logsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
      optargs_s.logsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
      optargs_s.rtsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtextsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
      optargs_s.rtextsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxpct")) {
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
      optargs_s.maxpct = get_int (hd_value);
    }
    else
      return unknown_optarg ("xfs_growfs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_growfs_argv (g, path, optargs);
  if (r == -1)
    return make_error ("xfs_growfs");

  return erl_mk_atom ("ok");
}

ETERM *
run_xfs_info (ETERM *args_tuple)
{
  CLEANUP_FREE char *pathordevice = erl_iolist_to_string (ARG (0));
  struct guestfs_xfsinfo *r;

  r = guestfs_xfs_info (g, pathordevice);
  if (r == NULL)
    return make_error ("xfs_info");

  ETERM *rt = make_xfsinfo (r);
  guestfs_free_xfsinfo (r);
  return rt;
}

ETERM *
run_xfs_repair (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "forcelogzero")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
      optargs_s.forcelogzero = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "nomodify")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
      optargs_s.nomodify = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "noprefetch")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
      optargs_s.noprefetch = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "forcegeometry")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
      optargs_s.forcegeometry = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxmem")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
      optargs_s.maxmem = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "ihashsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
      optargs_s.ihashsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bhashsize")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
      optargs_s.bhashsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "agstride")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
      optargs_s.agstride = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "logdev")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
      optargs_s.logdev = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "rtdev")) {
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
      optargs_s.rtdev = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("xfs_repair", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_xfs_repair_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_XFS_REPAIR_LOGDEV_BITMASK))
    free ((char *) optargs_s.logdev);
  if ((optargs_s.bitmask & GUESTFS_XFS_REPAIR_RTDEV_BITMASK))
    free ((char *) optargs_s.rtdev);
  if (r == -1)
    return make_error ("xfs_repair");

  return erl_mk_int (r);
}

ETERM *
run_zero_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero_device (g, device);
  if (r == -1)
    return make_error ("zero_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_zero_free_space (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero_free_space (g, directory);
  if (r == -1)
    return make_error ("zero_free_space");

  return erl_mk_atom ("ok");
}
