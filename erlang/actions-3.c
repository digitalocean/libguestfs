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
run_acl_get_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *acltype = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_acl_get_file (g, path, acltype);
  if (r == NULL)
    return make_error ("acl_get_file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_aug_close (ETERM *args_tuple)
{
  int r;

  r = guestfs_aug_close (g);
  if (r == -1)
    return make_error ("aug_close");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_defnode (ETERM *args_tuple)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *expr = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (2));
  struct guestfs_int_bool *r;

  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL)
    return make_error ("aug_defnode");

  ETERM *rt = make_int_bool (r);
  guestfs_free_int_bool (r);
  return rt;
}

ETERM *
run_aug_get (ETERM *args_tuple)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    return make_error ("aug_get");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_aug_save (ETERM *args_tuple)
{
  int r;

  r = guestfs_aug_save (g);
  if (r == -1)
    return make_error ("aug_save");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_setm (ETERM *args_tuple)
{
  CLEANUP_FREE char *base = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *sub;
  if (atom_equals (ARG (1), "undefined"))
    sub = NULL;
  else
    sub = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_aug_setm (g, base, sub, val);
  if (r == -1)
    return make_error ("aug_setm");

  return erl_mk_int (r);
}

ETERM *
run_available (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **groups = get_string_list (ARG (0));
  int r;

  r = guestfs_available (g, groups);
  if (r == -1)
    return make_error ("available");

  return erl_mk_atom ("ok");
}

ETERM *
run_blkdiscard (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blkdiscard (g, device);
  if (r == -1)
    return make_error ("blkdiscard");

  return erl_mk_atom ("ok");
}

ETERM *
run_blockdev_getsz (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    return make_error ("blockdev_getsz");

  return erl_mk_longlong (r);
}

ETERM *
run_blockdev_setro (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    return make_error ("blockdev_setro");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_balance_status (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_btrfsbalance *r;

  r = guestfs_btrfs_balance_status (g, path);
  if (r == NULL)
    return make_error ("btrfs_balance_status");

  ETERM *rt = make_btrfsbalance (r);
  guestfs_free_btrfsbalance (r);
  return rt;
}

ETERM *
run_btrfs_device_delete (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **devices = get_string_list (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_device_delete (g, devices, fs);
  if (r == -1)
    return make_error ("btrfs_device_delete");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_filesystem_defragment (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_filesystem_defragment_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "flush")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
      optargs_s.flush = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("btrfs_filesystem_defragment", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);
  if ((optargs_s.bitmask & GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if (r == -1)
    return make_error ("btrfs_filesystem_defragment");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_filesystem_resize (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "size")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      optargs_s.size = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("btrfs_filesystem_resize", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("btrfs_filesystem_resize");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_filesystem_sync (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_filesystem_sync (g, fs);
  if (r == -1)
    return make_error ("btrfs_filesystem_sync");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_image (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **source = get_string_list (ARG (0));
  CLEANUP_FREE char *image = erl_iolist_to_string (ARG (1));

  struct guestfs_btrfs_image_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compresslevel")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
      optargs_s.compresslevel = get_int (hd_value);
    }
    else
      return unknown_optarg ("btrfs_image", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_image_argv (g, source, image, optargs);
  if (r == -1)
    return make_error ("btrfs_image");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_qgroup_destroy (ETERM *args_tuple)
{
  CLEANUP_FREE char *qgroupid = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);
  if (r == -1)
    return make_error ("btrfs_qgroup_destroy");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_delete (ETERM *args_tuple)
{
  CLEANUP_FREE char *subvolume = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (r == -1)
    return make_error ("btrfs_subvolume_delete");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_list (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  struct guestfs_btrfssubvolume_list *r;

  r = guestfs_btrfs_subvolume_list (g, fs);
  if (r == NULL)
    return make_error ("btrfs_subvolume_list");

  ETERM *rt = make_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);
  return rt;
}

ETERM *
run_btrfstune_enable_skinny_metadata_extent_refs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);
  if (r == -1)
    return make_error ("btrfstune_enable_skinny_metadata_extent_refs");

  return erl_mk_atom ("ok");
}

ETERM *
run_cap_get_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_cap_get_file (g, path);
  if (r == NULL)
    return make_error ("cap_get_file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_checksum (ETERM *args_tuple)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    return make_error ("checksum");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_chmod (ETERM *args_tuple)
{
  int mode = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    return make_error ("chmod");

  return erl_mk_atom ("ok");
}

ETERM *
run_copy_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *remotepath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *localdir = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_copy_out (g, remotepath, localdir);
  if (r == -1)
    return make_error ("copy_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_disk_create (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *format = erl_iolist_to_string (ARG (1));
  int64_t size = get_int64 (ARG (2));

  struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (3);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "backingfile")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
      optargs_s.backingfile = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "backingformat")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
      optargs_s.backingformat = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "preallocation")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
      optargs_s.preallocation = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "compat")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
      optargs_s.compat = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "clustersize")) {
      optargs_s.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
      optargs_s.clustersize = get_int (hd_value);
    }
    else
      return unknown_optarg ("disk_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK))
    free ((char *) optargs_s.backingfile);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK))
    free ((char *) optargs_s.backingformat);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK))
    free ((char *) optargs_s.preallocation);
  if ((optargs_s.bitmask & GUESTFS_DISK_CREATE_COMPAT_BITMASK))
    free ((char *) optargs_s.compat);
  if (r == -1)
    return make_error ("disk_create");

  return erl_mk_atom ("ok");
}

ETERM *
run_dmesg (ETERM *args_tuple)
{
  char *r;

  r = guestfs_dmesg (g);
  if (r == NULL)
    return make_error ("dmesg");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_download_blocks (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t start = get_int64 (ARG (1));
  int64_t stop = get_int64 (ARG (2));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (3));

  struct guestfs_download_blocks_argv optargs_s = { .bitmask = 0 };
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (4);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "unallocated")) {
      optargs_s.bitmask |= GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK;
      optargs_s.unallocated = get_bool (hd_value);
    }
    else
      return unknown_optarg ("download_blocks", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);
  if (r == -1)
    return make_error ("download_blocks");

  return erl_mk_atom ("ok");
}

ETERM *
run_du (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_du (g, path);
  if (r == -1)
    return make_error ("du");

  return erl_mk_longlong (r);
}

ETERM *
run_e2fsck_f (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    return make_error ("e2fsck_f");

  return erl_mk_atom ("ok");
}

ETERM *
run_echo_daemon (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **words = get_string_list (ARG (0));
  char *r;

  r = guestfs_echo_daemon (g, words);
  if (r == NULL)
    return make_error ("echo_daemon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_equal (ETERM *args_tuple)
{
  CLEANUP_FREE char *file1 = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *file2 = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    return make_error ("equal");

  return make_bool (r);
}

ETERM *
run_fgrepi (ETERM *args_tuple)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL)
    return make_error ("fgrepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_get_backend_setting (ETERM *args_tuple)
{
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_backend_setting (g, name);
  if (r == NULL)
    return make_error ("get_backend_setting");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_backend_settings (ETERM *args_tuple)
{
  char **r;

  r = guestfs_get_backend_settings (g);
  if (r == NULL)
    return make_error ("get_backend_settings");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_get_e2label (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    return make_error ("get_e2label");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_recovery_proc (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    return make_error ("get_recovery_proc");

  return make_bool (r);
}

ETERM *
run_get_tmpdir (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_tmpdir (g);
  if (r == NULL)
    return make_error ("get_tmpdir");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_getcon (ETERM *args_tuple)
{
  char *r;

  r = guestfs_getcon (g);
  if (r == NULL)
    return make_error ("getcon");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_getxattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL)
    return make_error ("getxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_hivex_close (ETERM *args_tuple)
{
  int r;

  r = guestfs_hivex_close (g);
  if (r == -1)
    return make_error ("hivex_close");

  return erl_mk_atom ("ok");
}

ETERM *
run_hivex_open (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));

  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "verbose")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
      optargs_s.verbose = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "debug")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
      optargs_s.debug = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "write")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
      optargs_s.write = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "unsafe")) {
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK;
      optargs_s.unsafe = get_bool (hd_value);
    }
    else
      return unknown_optarg ("hivex_open", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_hivex_open_argv (g, filename, optargs);
  if (r == -1)
    return make_error ("hivex_open");

  return erl_mk_atom ("ok");
}

ETERM *
run_hivex_value_utf8 (ETERM *args_tuple)
{
  int64_t valueh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_value_utf8 (g, valueh);
  if (r == NULL)
    return make_error ("hivex_value_utf8");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inotify_add_watch (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int mask = get_int (ARG (1));
  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    return make_error ("inotify_add_watch");

  return erl_mk_longlong (r);
}

ETERM *
run_inotify_init (ETERM *args_tuple)
{
  int maxevents = get_int (ARG (0));
  int r;

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    return make_error ("inotify_init");

  return erl_mk_atom ("ok");
}

ETERM *
run_inspect_get_type (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_type (g, root);
  if (r == NULL)
    return make_error ("inspect_get_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_is_live (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_live (g, root);
  if (r == -1)
    return make_error ("inspect_is_live");

  return make_bool (r);
}

ETERM *
run_internal_exit (ETERM *args_tuple)
{
  int r;

  r = guestfs_internal_exit (g);
  if (r == -1)
    return make_error ("internal_exit");

  return erl_mk_atom ("ok");
}

ETERM *
run_internal_test_only_optargs (ETERM *args_tuple)
{

  struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (0);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "test")) {
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
      optargs_s.test = get_int (hd_value);
    }
    else
      return unknown_optarg ("internal_test_only_optargs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_internal_test_only_optargs_argv (g, optargs);
  if (r == -1)
    return make_error ("internal_test_only_optargs");

  return erl_mk_atom ("ok");
}

ETERM *
run_internal_test_rconststringerr (ETERM *args_tuple)
{
  const char *r;

  r = guestfs_internal_test_rconststringerr (g);
  if (r == NULL)
    return make_error ("internal_test_rconststringerr");

  return erl_mk_string (r);
}

ETERM *
run_is_dir (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_dir", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_dir_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_dir");

  return make_bool (r);
}

ETERM *
run_is_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));

  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "followsymlinks")) {
      optargs_s.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
      optargs_s.followsymlinks = get_bool (hd_value);
    }
    else
      return unknown_optarg ("is_file", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_is_file_opts_argv (g, path, optargs);
  if (r == -1)
    return make_error ("is_file");

  return make_bool (r);
}

ETERM *
run_is_whole_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_whole_device (g, device);
  if (r == -1)
    return make_error ("is_whole_device");

  return make_bool (r);
}

ETERM *
run_is_zero_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_is_zero_device (g, device);
  if (r == -1)
    return make_error ("is_zero_device");

  return make_bool (r);
}

ETERM *
run_journal_get_realtime_usec (ETERM *args_tuple)
{
  int64_t r;

  r = guestfs_journal_get_realtime_usec (g);
  if (r == -1)
    return make_error ("journal_get_realtime_usec");

  return erl_mk_longlong (r);
}

ETERM *
run_journal_set_data_threshold (ETERM *args_tuple)
{
  int64_t threshold = get_int64 (ARG (0));
  int r;

  r = guestfs_journal_set_data_threshold (g, threshold);
  if (r == -1)
    return make_error ("journal_set_data_threshold");

  return erl_mk_atom ("ok");
}

ETERM *
run_launch (ETERM *args_tuple)
{
  int r;

  r = guestfs_launch (g);
  if (r == -1)
    return make_error ("launch");

  return erl_mk_atom ("ok");
}

ETERM *
run_ldmtool_remove_all (ETERM *args_tuple)
{
  int r;

  r = guestfs_ldmtool_remove_all (g);
  if (r == -1)
    return make_error ("ldmtool_remove_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_ldmtool_volume_hint (ETERM *args_tuple)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_hint");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_ldmtool_volume_type (ETERM *args_tuple)
{
  CLEANUP_FREE char *diskgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *volume = erl_iolist_to_string (ARG (1));
  char *r;

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (r == NULL)
    return make_error ("ldmtool_volume_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_list_devices (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_devices (g);
  if (r == NULL)
    return make_error ("list_devices");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_list_filesystems (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_filesystems (g);
  if (r == NULL)
    return make_error ("list_filesystems");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_ls (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_ls (g, directory);
  if (r == NULL)
    return make_error ("ls");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_ls0 (ETERM *args_tuple)
{
  CLEANUP_FREE char *dir = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filenames = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_ls0 (g, dir, filenames);
  if (r == -1)
    return make_error ("ls0");

  return erl_mk_atom ("ok");
}

ETERM *
run_lstatns (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_statns *r;

  r = guestfs_lstatns (g, path);
  if (r == NULL)
    return make_error ("lstatns");

  ETERM *rt = make_statns (r);
  guestfs_free_statns (r);
  return rt;
}

ETERM *
run_lxattrlist (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  struct guestfs_xattr_list *r;

  r = guestfs_lxattrlist (g, path, names);
  if (r == NULL)
    return make_error ("lxattrlist");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

ETERM *
run_mkdir_mode (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int mode = get_int (ARG (1));
  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    return make_error ("mkdir_mode");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkdir_p (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    return make_error ("mkdir_p");

  return erl_mk_atom ("ok");
}

ETERM *
run_mke2fs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "blockscount")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
      optargs_s.blockscount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "blocksize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "fragsize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
      optargs_s.fragsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "blockspergroup")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
      optargs_s.blockspergroup = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "numberofgroups")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
      optargs_s.numberofgroups = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "bytesperinode")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
      optargs_s.bytesperinode = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "inodesize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
      optargs_s.inodesize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "journalsize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
      optargs_s.journalsize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "numberofinodes")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
      optargs_s.numberofinodes = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "stridesize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
      optargs_s.stridesize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "stripewidth")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
      optargs_s.stripewidth = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxonlineresize")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
      optargs_s.maxonlineresize = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockspercentage")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "mmpupdateinterval")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
      optargs_s.mmpupdateinterval = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "journaldevice")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
      optargs_s.journaldevice = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "lastmounteddir")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
      optargs_s.lastmounteddir = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "creatoros")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
      optargs_s.creatoros = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "fstype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
      optargs_s.fstype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "usagetype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
      optargs_s.usagetype = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "forcecreate")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
      optargs_s.forcecreate = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "writesbandgrouponly")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
      optargs_s.writesbandgrouponly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyitableinit")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
      optargs_s.lazyitableinit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "lazyjournalinit")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
      optargs_s.lazyjournalinit = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "testfs")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
      optargs_s.testfs = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "discard")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
      optargs_s.discard = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "quotatype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
      optargs_s.quotatype = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "extent")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
      optargs_s.extent = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "filetype")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
      optargs_s.filetype = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "flexbg")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
      optargs_s.flexbg = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "hasjournal")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
      optargs_s.hasjournal = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "journaldev")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
      optargs_s.journaldev = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "largefile")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
      optargs_s.largefile = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "quota")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
      optargs_s.quota = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "resizeinode")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
      optargs_s.resizeinode = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "sparsesuper")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
      optargs_s.sparsesuper = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "uninitbg")) {
      optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
      optargs_s.uninitbg = get_bool (hd_value);
    }
    else
      return unknown_optarg ("mke2fs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mke2fs_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK))
    free ((char *) optargs_s.journaldevice);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK))
    free ((char *) optargs_s.lastmounteddir);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_CREATOROS_BITMASK))
    free ((char *) optargs_s.creatoros);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_FSTYPE_BITMASK))
    free ((char *) optargs_s.fstype);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_USAGETYPE_BITMASK))
    free ((char *) optargs_s.usagetype);
  if ((optargs_s.bitmask & GUESTFS_MKE2FS_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("mke2fs");

  return erl_mk_atom ("ok");
}

ETERM *
run_mke2fs_JL (ETERM *args_tuple)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    return make_error ("mke2fs_JL");

  return erl_mk_atom ("ok");
}

ETERM *
run_mke2fs_JU (ETERM *args_tuple)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    return make_error ("mke2fs_JU");

  return erl_mk_atom ("ok");
}

ETERM *
run_mke2journal (ETERM *args_tuple)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    return make_error ("mke2journal");

  return erl_mk_atom ("ok");
}

ETERM *
run_mknod_b (ETERM *args_tuple)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod_b");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_local (ETERM *args_tuple)
{
  CLEANUP_FREE char *localmountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "options")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      optargs_s.options = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachetimeout")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      optargs_s.cachetimeout = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "debugcalls")) {
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      optargs_s.debugcalls = get_bool (hd_value);
    }
    else
      return unknown_optarg ("mount_local", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  if ((optargs_s.bitmask & GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK))
    free ((char *) optargs_s.options);
  if (r == -1)
    return make_error ("mount_local");

  return erl_mk_atom ("ok");
}

ETERM *
run_ntfsresize_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1)
    return make_error ("ntfsresize_size");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_del (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_del (g, device, partnum);
  if (r == -1)
    return make_error ("part_del");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_get_gpt_type (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_gpt_type (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_gpt_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_ping_daemon (ETERM *args_tuple)
{
  int r;

  r = guestfs_ping_daemon (g);
  if (r == -1)
    return make_error ("ping_daemon");

  return erl_mk_atom ("ok");
}

ETERM *
run_remove_drive (ETERM *args_tuple)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_remove_drive (g, label);
  if (r == -1)
    return make_error ("remove_drive");

  return erl_mk_atom ("ok");
}

ETERM *
run_rm (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm (g, path);
  if (r == -1)
    return make_error ("rm");

  return erl_mk_atom ("ok");
}

ETERM *
run_rmdir (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmdir (g, path);
  if (r == -1)
    return make_error ("rmdir");

  return erl_mk_atom ("ok");
}

ETERM *
run_rsync (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_argv (g, src, dest, optargs);
  if (r == -1)
    return make_error ("rsync");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_backend_settings (ETERM *args_tuple)
{
  CLEANUP_FREE_STRING_LIST char **settings = get_string_list (ARG (0));
  int r;

  r = guestfs_set_backend_settings (g, settings);
  if (r == -1)
    return make_error ("set_backend_settings");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_hv (ETERM *args_tuple)
{
  CLEANUP_FREE char *hv = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_hv (g, hv);
  if (r == -1)
    return make_error ("set_hv");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_qemu (ETERM *args_tuple)
{
  CLEANUP_FREE char *hv;
  if (atom_equals (ARG (0), "undefined"))
    hv = NULL;
  else
    hv = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_qemu (g, hv);
  if (r == -1)
    return make_error ("set_qemu");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_recovery_proc (ETERM *args_tuple)
{
  int recoveryproc = get_bool (ARG (0));
  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    return make_error ("set_recovery_proc");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_uuid (g, device, uuid);
  if (r == -1)
    return make_error ("set_uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_setcon (ETERM *args_tuple)
{
  CLEANUP_FREE char *context = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_setcon (g, context);
  if (r == -1)
    return make_error ("setcon");

  return erl_mk_atom ("ok");
}

ETERM *
run_statvfs (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_statvfs *r;

  r = guestfs_statvfs (g, path);
  if (r == NULL)
    return make_error ("statvfs");

  ETERM *rt = make_statvfs (r);
  guestfs_free_statvfs (r);
  return rt;
}

ETERM *
run_strings (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_strings (g, path);
  if (r == NULL)
    return make_error ("strings");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_swapoff_label (ETERM *args_tuple)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    return make_error ("swapoff_label");

  return erl_mk_atom ("ok");
}

ETERM *
run_swapoff_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    return make_error ("swapoff_uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_tar_in (ETERM *args_tuple)
{
  CLEANUP_FREE char *tarfile = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));

  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "xattrs")) {
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK;
      optargs_s.xattrs = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "selinux")) {
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK;
      optargs_s.selinux = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "acls")) {
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_ACLS_BITMASK;
      optargs_s.acls = get_bool (hd_value);
    }
    else
      return unknown_optarg ("tar_in", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  if ((optargs_s.bitmask & GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if (r == -1)
    return make_error ("tar_in");

  return erl_mk_atom ("ok");
}

ETERM *
run_truncate (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_truncate (g, path);
  if (r == -1)
    return make_error ("truncate");

  return erl_mk_atom ("ok");
}

ETERM *
run_tune2fs (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "force")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      optargs_s.force = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "maxmountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      optargs_s.maxmountcount = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "mountcount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      optargs_s.mountcount = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "errorbehavior")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      optargs_s.errorbehavior = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "group")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      optargs_s.group = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "intervalbetweenchecks")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      optargs_s.intervalbetweenchecks = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockspercentage")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = get_int (hd_value);
    }
    else
    if (atom_equals (hd_name, "lastmounteddirectory")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      optargs_s.lastmounteddirectory = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "reservedblockscount")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      optargs_s.reservedblockscount = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "user")) {
      optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      optargs_s.user = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("tune2fs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tune2fs_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK))
    free ((char *) optargs_s.errorbehavior);
  if ((optargs_s.bitmask & GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK))
    free ((char *) optargs_s.lastmounteddirectory);
  if (r == -1)
    return make_error ("tune2fs");

  return erl_mk_atom ("ok");
}

ETERM *
run_upload (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    return make_error ("upload");

  return erl_mk_atom ("ok");
}

ETERM *
run_utimens (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t atsecs = get_int64 (ARG (1));
  int64_t atnsecs = get_int64 (ARG (2));
  int64_t mtsecs = get_int64 (ARG (3));
  int64_t mtnsecs = get_int64 (ARG (4));
  int r;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    return make_error ("utimens");

  return erl_mk_atom ("ok");
}

ETERM *
run_version (ETERM *args_tuple)
{
  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    return make_error ("version");

  ETERM *rt = make_version (r);
  guestfs_free_version (r);
  return rt;
}

ETERM *
run_vfs_minimum_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_vfs_minimum_size (g, mountable);
  if (r == -1)
    return make_error ("vfs_minimum_size");

  return erl_mk_longlong (r);
}

ETERM *
run_vfs_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_uuid (g, mountable);
  if (r == NULL)
    return make_error ("vfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_vgs (ETERM *args_tuple)
{
  char **r;

  r = guestfs_vgs (g);
  if (r == NULL)
    return make_error ("vgs");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_write_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *content = erl_iolist_to_string (ARG (1));
  int size = get_int (ARG (2));
  int r;

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    return make_error ("write_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_zero (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zero (g, device);
  if (r == -1)
    return make_error ("zero");

  return erl_mk_atom ("ok");
}

ETERM *
run_zerofree (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_zerofree (g, device);
  if (r == -1)
    return make_error ("zerofree");

  return erl_mk_atom ("ok");
}

ETERM *
run_zgrepi (ETERM *args_tuple)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL)
    return make_error ("zgrepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}
