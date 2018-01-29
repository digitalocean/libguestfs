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
run_aug_mv (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    return make_error ("aug_mv");

  return erl_mk_atom ("ok");
}

ETERM *
run_available_all_groups (ETERM *args_tuple)
{
  char **r;

  r = guestfs_available_all_groups (g);
  if (r == NULL)
    return make_error ("available_all_groups");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_blockdev_getbsz (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    return make_error ("blockdev_getbsz");

  return erl_mk_int (r);
}

ETERM *
run_blockdev_getro (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    return make_error ("blockdev_getro");

  return make_bool (r);
}

ETERM *
run_blockdev_setbsz (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    return make_error ("blockdev_setbsz");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_qgroup_remove (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dst = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);
  if (r == -1)
    return make_error ("btrfs_qgroup_remove");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_quota_enable (ETERM *args_tuple)
{
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (0));
  int enable = get_bool (ARG (1));
  int r;

  r = guestfs_btrfs_quota_enable (g, fs, enable);
  if (r == -1)
    return make_error ("btrfs_quota_enable");

  return erl_mk_atom ("ok");
}

ETERM *
run_checksums_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *csumtype = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *sumsfile = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1)
    return make_error ("checksums_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_cp_a (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    return make_error ("cp_a");

  return erl_mk_atom ("ok");
}

ETERM *
run_df (ETERM *args_tuple)
{
  char *r;

  r = guestfs_df (g);
  if (r == NULL)
    return make_error ("df");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_disk_format (ETERM *args_tuple)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_disk_format (g, filename);
  if (r == NULL)
    return make_error ("disk_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_egrepi (ETERM *args_tuple)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_egrepi (g, regex, path);
  if (r == NULL)
    return make_error ("egrepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_fallocate (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int len = get_int (ARG (1));
  int r;

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    return make_error ("fallocate");

  return erl_mk_atom ("ok");
}

ETERM *
run_fallocate64 (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int64_t len = get_int64 (ARG (1));
  int r;

  r = guestfs_fallocate64 (g, path, len);
  if (r == -1)
    return make_error ("fallocate64");

  return erl_mk_atom ("ok");
}

ETERM *
run_fgrep (ETERM *args_tuple)
{
  CLEANUP_FREE char *pattern = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL)
    return make_error ("fgrep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_file (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_file (g, path);
  if (r == NULL)
    return make_error ("file");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_filesize (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t r;

  r = guestfs_filesize (g, file);
  if (r == -1)
    return make_error ("filesize");

  return erl_mk_longlong (r);
}

ETERM *
run_filesystem_available (ETERM *args_tuple)
{
  CLEANUP_FREE char *filesystem = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_filesystem_available (g, filesystem);
  if (r == -1)
    return make_error ("filesystem_available");

  return make_bool (r);
}

ETERM *
run_fill (ETERM *args_tuple)
{
  int c = get_int (ARG (0));
  int len = get_int (ARG (1));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    return make_error ("fill");

  return erl_mk_atom ("ok");
}

ETERM *
run_find (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_find (g, directory);
  if (r == NULL)
    return make_error ("find");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_get_direct (ETERM *args_tuple)
{
  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    return make_error ("get_direct");

  return make_bool (r);
}

ETERM *
run_get_hv (ETERM *args_tuple)
{
  char *r;

  r = guestfs_get_hv (g);
  if (r == NULL)
    return make_error ("get_hv");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_libvirt_requested_credentials (ETERM *args_tuple)
{
  char **r;

  r = guestfs_get_libvirt_requested_credentials (g);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credentials");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_head (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_head (g, path);
  if (r == NULL)
    return make_error ("head");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_hivex_node_name (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  char *r;

  r = guestfs_hivex_node_name (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_hivex_node_values (ETERM *args_tuple)
{
  int64_t nodeh = get_int64 (ARG (0));
  struct guestfs_hivex_value_list *r;

  r = guestfs_hivex_node_values (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_values");

  ETERM *rt = make_hivex_value_list (r);
  guestfs_free_hivex_value_list (r);
  return rt;
}

ETERM *
run_inotify_read (ETERM *args_tuple)
{
  struct guestfs_inotify_event_list *r;

  r = guestfs_inotify_read (g);
  if (r == NULL)
    return make_error ("inotify_read");

  ETERM *rt = make_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
  return rt;
}

ETERM *
run_inspect_get_mountpoints (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL)
    return make_error ("inspect_get_mountpoints");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_inspect_get_package_management (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL)
    return make_error ("inspect_get_package_management");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_product_name (ETERM *args_tuple)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL)
    return make_error ("inspect_get_product_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_internal_test_rconststring (ETERM *args_tuple)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  const char *r;

  r = guestfs_internal_test_rconststring (g, val);
  if (r == NULL)
    return make_error ("internal_test_rconststring");

  return erl_mk_string (r);
}

ETERM *
run_internal_test_rint (ETERM *args_tuple)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_rint (g, val);
  if (r == -1)
    return make_error ("internal_test_rint");

  return erl_mk_int (r);
}

ETERM *
run_internal_test_rint64err (ETERM *args_tuple)
{
  int64_t r;

  r = guestfs_internal_test_rint64err (g);
  if (r == -1)
    return make_error ("internal_test_rint64err");

  return erl_mk_longlong (r);
}

ETERM *
run_internal_test_rstruct (ETERM *args_tuple)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstruct (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstruct");

  ETERM *rt = make_lvm_pv (r);
  guestfs_free_lvm_pv (r);
  return rt;
}

ETERM *
run_isoinfo (ETERM *args_tuple)
{
  CLEANUP_FREE char *isofile = erl_iolist_to_string (ARG (0));
  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo (g, isofile);
  if (r == NULL)
    return make_error ("isoinfo");

  ETERM *rt = make_isoinfo (r);
  guestfs_free_isoinfo (r);
  return rt;
}

ETERM *
run_journal_close (ETERM *args_tuple)
{
  int r;

  r = guestfs_journal_close (g);
  if (r == -1)
    return make_error ("journal_close");

  return erl_mk_atom ("ok");
}

ETERM *
run_lgetxattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *name = erl_iolist_to_string (ARG (1));
  char *r;
  size_t size;

  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL)
    return make_error ("lgetxattr");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_list_9p (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_9p (g);
  if (r == NULL)
    return make_error ("list_9p");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_list_ldm_partitions (ETERM *args_tuple)
{
  char **r;

  r = guestfs_list_ldm_partitions (g);
  if (r == NULL)
    return make_error ("list_ldm_partitions");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_luks_format_cipher (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  CLEANUP_FREE char *cipher = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1)
    return make_error ("luks_format_cipher");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvm_clear_filter (ETERM *args_tuple)
{
  int r;

  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    return make_error ("lvm_clear_filter");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvs (ETERM *args_tuple)
{
  char **r;

  r = guestfs_lvs (g);
  if (r == NULL)
    return make_error ("lvs");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_max_disks (ETERM *args_tuple)
{
  int r;

  r = guestfs_max_disks (g);
  if (r == -1)
    return make_error ("max_disks");

  return erl_mk_int (r);
}

ETERM *
run_md_detail (ETERM *args_tuple)
{
  CLEANUP_FREE char *md = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_md_detail (g, md);
  if (r == NULL)
    return make_error ("md_detail");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_mke2journal_L (ETERM *args_tuple)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    return make_error ("mke2journal_L");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkswap (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "label")) {
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
      optargs_s.label = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "uuid")) {
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
      optargs_s.uuid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mkswap", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_mkswap_opts_argv (g, device, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKSWAP_OPTS_LABEL_BITMASK))
    free ((char *) optargs_s.label);
  if ((optargs_s.bitmask & GUESTFS_MKSWAP_OPTS_UUID_BITMASK))
    free ((char *) optargs_s.uuid);
  if (r == -1)
    return make_error ("mkswap");

  return erl_mk_atom ("ok");
}

ETERM *
run_mkswap_L (ETERM *args_tuple)
{
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    return make_error ("mkswap_L");

  return erl_mk_atom ("ok");
}

ETERM *
run_mktemp (ETERM *args_tuple)
{
  CLEANUP_FREE char *tmpl = erl_iolist_to_string (ARG (0));

  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "suffix")) {
      optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
      optargs_s.suffix = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("mktemp", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  char *r;

  r = guestfs_mktemp_argv (g, tmpl, optargs);
  if ((optargs_s.bitmask & GUESTFS_MKTEMP_SUFFIX_BITMASK))
    free ((char *) optargs_s.suffix);
  if (r == NULL)
    return make_error ("mktemp");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_mount_loop (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    return make_error ("mount_loop");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_vfs (ETERM *args_tuple)
{
  CLEANUP_FREE char *options = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *vfstype = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_vfs");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_set_mbr_id (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int idbyte = get_int (ARG (2));
  int r;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1)
    return make_error ("part_set_mbr_id");

  return erl_mk_atom ("ok");
}

ETERM *
run_pread_device (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int count = get_int (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  char *r;
  size_t size;

  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL)
    return make_error ("pread_device");

  ETERM *rt = erl_mk_estring (r, size);
  free (r);
  return rt;
}

ETERM *
run_pvchange_uuid (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_pvchange_uuid (g, device);
  if (r == -1)
    return make_error ("pvchange_uuid");

  return erl_mk_atom ("ok");
}

ETERM *
run_pvchange_uuid_all (ETERM *args_tuple)
{
  int r;

  r = guestfs_pvchange_uuid_all (g);
  if (r == -1)
    return make_error ("pvchange_uuid_all");

  return erl_mk_atom ("ok");
}

ETERM *
run_pvresize_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_pvresize_size (g, device, size);
  if (r == -1)
    return make_error ("pvresize_size");

  return erl_mk_atom ("ok");
}

ETERM *
run_read_lines (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_read_lines (g, path);
  if (r == NULL)
    return make_error ("read_lines");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_remount (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
  struct guestfs_remount_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "rw")) {
      optargs_s.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
      optargs_s.rw = get_bool (hd_value);
    }
    else
      return unknown_optarg ("remount", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_remount_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("remount");

  return erl_mk_atom ("ok");
}

ETERM *
run_removexattr (ETERM *args_tuple)
{
  CLEANUP_FREE char *xattr = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    return make_error ("removexattr");

  return erl_mk_atom ("ok");
}

ETERM *
run_resize2fs_size (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int64_t size = get_int64 (ARG (1));
  int r;

  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1)
    return make_error ("resize2fs_size");

  return erl_mk_atom ("ok");
}

ETERM *
run_rm_f (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rm_f (g, path);
  if (r == -1)
    return make_error ("rm_f");

  return erl_mk_atom ("ok");
}

ETERM *
run_rsync_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *remote = erl_iolist_to_string (ARG (1));

  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "archive")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
      optargs_s.archive = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "deletedest")) {
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
      optargs_s.deletedest = get_bool (hd_value);
    }
    else
      return unknown_optarg ("rsync_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  if (r == -1)
    return make_error ("rsync_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_e2generation (ETERM *args_tuple)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int64_t generation = get_int64 (ARG (1));
  int r;

  r = guestfs_set_e2generation (g, file, generation);
  if (r == -1)
    return make_error ("set_e2generation");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_label (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_label (g, mountable, label);
  if (r == -1)
    return make_error ("set_label");

  return erl_mk_atom ("ok");
}

ETERM *
run_sfdisk_kernel_geometry (ETERM *args_tuple)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    return make_error ("sfdisk_kernel_geometry");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_sleep (ETERM *args_tuple)
{
  int secs = get_int (ARG (0));
  int r;

  r = guestfs_sleep (g, secs);
  if (r == -1)
    return make_error ("sleep");

  return erl_mk_atom ("ok");
}

ETERM *
run_strings_e (ETERM *args_tuple)
{
  CLEANUP_FREE char *encoding = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL)
    return make_error ("strings_e");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_sync (ETERM *args_tuple)
{
  int r;

  r = guestfs_sync (g);
  if (r == -1)
    return make_error ("sync");

  return erl_mk_atom ("ok");
}

ETERM *
run_tail_n (ETERM *args_tuple)
{
  int nrlines = get_int (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL)
    return make_error ("tail_n");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_tar_out (ETERM *args_tuple)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarfile = erl_iolist_to_string (ARG (1));

  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "compress")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "numericowner")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
      optargs_s.numericowner = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "excludes")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
      optargs_s.excludes = get_string_list (hd_value);
    }
    else
    if (atom_equals (hd_name, "xattrs")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK;
      optargs_s.xattrs = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "selinux")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK;
      optargs_s.selinux = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "acls")) {
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK;
      optargs_s.acls = get_bool (hd_value);
    }
    else
      return unknown_optarg ("tar_out", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  if ((optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK))
    free ((char *) optargs_s.compress);
  if ((optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK))
    guestfs_int_free_string_list ((char **) optargs_s.excludes);
  if (r == -1)
    return make_error ("tar_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_vfs_type (ETERM *args_tuple)
{
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_vfs_type (g, mountable);
  if (r == NULL)
    return make_error ("vfs_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_vgcreate (ETERM *args_tuple)
{
  CLEANUP_FREE char *volgroup = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **physvols = get_string_list (ARG (1));
  int r;

  r = guestfs_vgcreate (g, volgroup, physvols);
  if (r == -1)
    return make_error ("vgcreate");

  return erl_mk_atom ("ok");
}

ETERM *
run_wait_ready (ETERM *args_tuple)
{
  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    return make_error ("wait_ready");

  return erl_mk_atom ("ok");
}

ETERM *
run_wc_c (ETERM *args_tuple)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wc_c (g, path);
  if (r == -1)
    return make_error ("wc_c");

  return erl_mk_int (r);
}

ETERM *
run_zegrep (ETERM *args_tuple)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_zegrep (g, regex, path);
  if (r == NULL)
    return make_error ("zegrep");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}
