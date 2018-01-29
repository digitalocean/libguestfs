/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ruby.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "actions.h"

VALUE m_guestfs;                  /* guestfs module */
VALUE c_guestfs;                  /* guestfs_h handle */
VALUE e_Error;                    /* used for all errors */

extern void Init__guestfs (void); /* keep GCC warnings happy */

/* Initialize the module. */
void
Init__guestfs (void)
{
  m_guestfs = rb_define_module ("Guestfs");
  c_guestfs = rb_define_class_under (m_guestfs, "Guestfs", rb_cObject);
  e_Error = rb_define_class_under (m_guestfs, "Error", rb_eStandardError);

#ifdef HAVE_RB_DEFINE_ALLOC_FUNC
#ifndef HAVE_TYPE_RB_ALLOC_FUNC_T
#define rb_alloc_func_t void*
#endif
  rb_define_alloc_func (c_guestfs, (rb_alloc_func_t) guestfs_int_ruby_alloc_handle);
#endif

  rb_define_method (c_guestfs, "initialize",
                    guestfs_int_ruby_initialize_handle, -1);
  rb_define_method (c_guestfs, "close",
                    guestfs_int_ruby_close_handle, 0);
  rb_define_method (c_guestfs, "set_event_callback",
                    guestfs_int_ruby_set_event_callback, 2);
  rb_define_method (c_guestfs, "delete_event_callback",
                    guestfs_int_ruby_delete_event_callback, 1);
  rb_define_module_function (m_guestfs, "event_to_string",
                             guestfs_int_ruby_event_to_string, 1);

  /* For backwards compatibility with older code, define a ::create
   * module function.
   */
  rb_define_module_function (m_guestfs, "create",
                             guestfs_int_ruby_compat_create_handle, -1);

  rb_define_const (m_guestfs, "EVENT_CLOSE",
                   ULL2NUM (UINT64_C (0x1)));
  rb_define_const (m_guestfs, "EVENT_SUBPROCESS_QUIT",
                   ULL2NUM (UINT64_C (0x2)));
  rb_define_const (m_guestfs, "EVENT_LAUNCH_DONE",
                   ULL2NUM (UINT64_C (0x4)));
  rb_define_const (m_guestfs, "EVENT_PROGRESS",
                   ULL2NUM (UINT64_C (0x8)));
  rb_define_const (m_guestfs, "EVENT_APPLIANCE",
                   ULL2NUM (UINT64_C (0x10)));
  rb_define_const (m_guestfs, "EVENT_LIBRARY",
                   ULL2NUM (UINT64_C (0x20)));
  rb_define_const (m_guestfs, "EVENT_TRACE",
                   ULL2NUM (UINT64_C (0x40)));
  rb_define_const (m_guestfs, "EVENT_ENTER",
                   ULL2NUM (UINT64_C (0x80)));
  rb_define_const (m_guestfs, "EVENT_LIBVIRT_AUTH",
                   ULL2NUM (UINT64_C (0x100)));
  rb_define_const (m_guestfs, "EVENT_WARNING",
                   ULL2NUM (UINT64_C (0x200)));
  rb_define_const (m_guestfs, "EVENT_ALL",
                   ULL2NUM (UINT64_C (0x3ff)));

  rb_define_method (c_guestfs, "acl_delete_def_file",
                    guestfs_int_ruby_acl_delete_def_file, 1);
  rb_define_method (c_guestfs, "acl_get_file",
                    guestfs_int_ruby_acl_get_file, 2);
  rb_define_method (c_guestfs, "acl_set_file",
                    guestfs_int_ruby_acl_set_file, 3);
  rb_define_method (c_guestfs, "add_cdrom",
                    guestfs_int_ruby_add_cdrom, 1);
  rb_define_method (c_guestfs, "add_domain",
                    guestfs_int_ruby_add_domain, -1);
  rb_define_method (c_guestfs, "add_drive",
                    guestfs_int_ruby_add_drive, -1);
  rb_define_method (c_guestfs, "add_drive_opts",
                    guestfs_int_ruby_add_drive, -1);
  rb_define_method (c_guestfs, "add_drive_ro",
                    guestfs_int_ruby_add_drive_ro, 1);
  rb_define_method (c_guestfs, "add_drive_ro_with_if",
                    guestfs_int_ruby_add_drive_ro_with_if, 2);
  rb_define_method (c_guestfs, "add_drive_scratch",
                    guestfs_int_ruby_add_drive_scratch, -1);
  rb_define_method (c_guestfs, "add_drive_with_if",
                    guestfs_int_ruby_add_drive_with_if, 2);
  rb_define_method (c_guestfs, "add_libvirt_dom",
                    guestfs_int_ruby_add_libvirt_dom, -1);
  rb_define_method (c_guestfs, "aug_clear",
                    guestfs_int_ruby_aug_clear, 1);
  rb_define_method (c_guestfs, "aug_close",
                    guestfs_int_ruby_aug_close, 0);
  rb_define_method (c_guestfs, "aug_defnode",
                    guestfs_int_ruby_aug_defnode, 3);
  rb_define_method (c_guestfs, "aug_defvar",
                    guestfs_int_ruby_aug_defvar, 2);
  rb_define_method (c_guestfs, "aug_get",
                    guestfs_int_ruby_aug_get, 1);
  rb_define_method (c_guestfs, "aug_init",
                    guestfs_int_ruby_aug_init, 2);
  rb_define_method (c_guestfs, "aug_insert",
                    guestfs_int_ruby_aug_insert, 3);
  rb_define_method (c_guestfs, "aug_label",
                    guestfs_int_ruby_aug_label, 1);
  rb_define_method (c_guestfs, "aug_load",
                    guestfs_int_ruby_aug_load, 0);
  rb_define_method (c_guestfs, "aug_ls",
                    guestfs_int_ruby_aug_ls, 1);
  rb_define_method (c_guestfs, "aug_match",
                    guestfs_int_ruby_aug_match, 1);
  rb_define_method (c_guestfs, "aug_mv",
                    guestfs_int_ruby_aug_mv, 2);
  rb_define_method (c_guestfs, "aug_rm",
                    guestfs_int_ruby_aug_rm, 1);
  rb_define_method (c_guestfs, "aug_save",
                    guestfs_int_ruby_aug_save, 0);
  rb_define_method (c_guestfs, "aug_set",
                    guestfs_int_ruby_aug_set, 2);
  rb_define_method (c_guestfs, "aug_setm",
                    guestfs_int_ruby_aug_setm, 3);
  rb_define_method (c_guestfs, "aug_transform",
                    guestfs_int_ruby_aug_transform, -1);
  rb_define_method (c_guestfs, "available",
                    guestfs_int_ruby_available, 1);
  rb_define_method (c_guestfs, "available_all_groups",
                    guestfs_int_ruby_available_all_groups, 0);
  rb_define_method (c_guestfs, "base64_in",
                    guestfs_int_ruby_base64_in, 2);
  rb_define_method (c_guestfs, "base64_out",
                    guestfs_int_ruby_base64_out, 2);
  rb_define_method (c_guestfs, "blkdiscard",
                    guestfs_int_ruby_blkdiscard, 1);
  rb_define_method (c_guestfs, "blkdiscardzeroes",
                    guestfs_int_ruby_blkdiscardzeroes, 1);
  rb_define_method (c_guestfs, "blkid",
                    guestfs_int_ruby_blkid, 1);
  rb_define_method (c_guestfs, "blockdev_flushbufs",
                    guestfs_int_ruby_blockdev_flushbufs, 1);
  rb_define_method (c_guestfs, "blockdev_getbsz",
                    guestfs_int_ruby_blockdev_getbsz, 1);
  rb_define_method (c_guestfs, "blockdev_getro",
                    guestfs_int_ruby_blockdev_getro, 1);
  rb_define_method (c_guestfs, "blockdev_getsize64",
                    guestfs_int_ruby_blockdev_getsize64, 1);
  rb_define_method (c_guestfs, "blockdev_getss",
                    guestfs_int_ruby_blockdev_getss, 1);
  rb_define_method (c_guestfs, "blockdev_getsz",
                    guestfs_int_ruby_blockdev_getsz, 1);
  rb_define_method (c_guestfs, "blockdev_rereadpt",
                    guestfs_int_ruby_blockdev_rereadpt, 1);
  rb_define_method (c_guestfs, "blockdev_setbsz",
                    guestfs_int_ruby_blockdev_setbsz, 2);
  rb_define_method (c_guestfs, "blockdev_setra",
                    guestfs_int_ruby_blockdev_setra, 2);
  rb_define_method (c_guestfs, "blockdev_setro",
                    guestfs_int_ruby_blockdev_setro, 1);
  rb_define_method (c_guestfs, "blockdev_setrw",
                    guestfs_int_ruby_blockdev_setrw, 1);
  rb_define_method (c_guestfs, "btrfs_balance_cancel",
                    guestfs_int_ruby_btrfs_balance_cancel, 1);
  rb_define_method (c_guestfs, "btrfs_balance_pause",
                    guestfs_int_ruby_btrfs_balance_pause, 1);
  rb_define_method (c_guestfs, "btrfs_balance_resume",
                    guestfs_int_ruby_btrfs_balance_resume, 1);
  rb_define_method (c_guestfs, "btrfs_balance_status",
                    guestfs_int_ruby_btrfs_balance_status, 1);
  rb_define_method (c_guestfs, "btrfs_device_add",
                    guestfs_int_ruby_btrfs_device_add, 2);
  rb_define_method (c_guestfs, "btrfs_device_delete",
                    guestfs_int_ruby_btrfs_device_delete, 2);
  rb_define_method (c_guestfs, "btrfs_filesystem_balance",
                    guestfs_int_ruby_btrfs_filesystem_balance, 1);
  rb_define_method (c_guestfs, "btrfs_filesystem_defragment",
                    guestfs_int_ruby_btrfs_filesystem_defragment, -1);
  rb_define_method (c_guestfs, "btrfs_filesystem_resize",
                    guestfs_int_ruby_btrfs_filesystem_resize, -1);
  rb_define_method (c_guestfs, "btrfs_filesystem_show",
                    guestfs_int_ruby_btrfs_filesystem_show, 1);
  rb_define_method (c_guestfs, "btrfs_filesystem_sync",
                    guestfs_int_ruby_btrfs_filesystem_sync, 1);
  rb_define_method (c_guestfs, "btrfs_fsck",
                    guestfs_int_ruby_btrfs_fsck, -1);
  rb_define_method (c_guestfs, "btrfs_image",
                    guestfs_int_ruby_btrfs_image, -1);
  rb_define_method (c_guestfs, "btrfs_qgroup_assign",
                    guestfs_int_ruby_btrfs_qgroup_assign, 3);
  rb_define_method (c_guestfs, "btrfs_qgroup_create",
                    guestfs_int_ruby_btrfs_qgroup_create, 2);
  rb_define_method (c_guestfs, "btrfs_qgroup_destroy",
                    guestfs_int_ruby_btrfs_qgroup_destroy, 2);
  rb_define_method (c_guestfs, "btrfs_qgroup_limit",
                    guestfs_int_ruby_btrfs_qgroup_limit, 2);
  rb_define_method (c_guestfs, "btrfs_qgroup_remove",
                    guestfs_int_ruby_btrfs_qgroup_remove, 3);
  rb_define_method (c_guestfs, "btrfs_qgroup_show",
                    guestfs_int_ruby_btrfs_qgroup_show, 1);
  rb_define_method (c_guestfs, "btrfs_quota_enable",
                    guestfs_int_ruby_btrfs_quota_enable, 2);
  rb_define_method (c_guestfs, "btrfs_quota_rescan",
                    guestfs_int_ruby_btrfs_quota_rescan, 1);
  rb_define_method (c_guestfs, "btrfs_replace",
                    guestfs_int_ruby_btrfs_replace, 3);
  rb_define_method (c_guestfs, "btrfs_rescue_chunk_recover",
                    guestfs_int_ruby_btrfs_rescue_chunk_recover, 1);
  rb_define_method (c_guestfs, "btrfs_rescue_super_recover",
                    guestfs_int_ruby_btrfs_rescue_super_recover, 1);
  rb_define_method (c_guestfs, "btrfs_scrub_cancel",
                    guestfs_int_ruby_btrfs_scrub_cancel, 1);
  rb_define_method (c_guestfs, "btrfs_scrub_resume",
                    guestfs_int_ruby_btrfs_scrub_resume, 1);
  rb_define_method (c_guestfs, "btrfs_scrub_start",
                    guestfs_int_ruby_btrfs_scrub_start, 1);
  rb_define_method (c_guestfs, "btrfs_scrub_status",
                    guestfs_int_ruby_btrfs_scrub_status, 1);
  rb_define_method (c_guestfs, "btrfs_set_seeding",
                    guestfs_int_ruby_btrfs_set_seeding, 2);
  rb_define_method (c_guestfs, "btrfs_subvolume_create",
                    guestfs_int_ruby_btrfs_subvolume_create, -1);
  rb_define_method (c_guestfs, "btrfs_subvolume_create_opts",
                    guestfs_int_ruby_btrfs_subvolume_create, -1);
  rb_define_method (c_guestfs, "btrfs_subvolume_delete",
                    guestfs_int_ruby_btrfs_subvolume_delete, 1);
  rb_define_method (c_guestfs, "btrfs_subvolume_get_default",
                    guestfs_int_ruby_btrfs_subvolume_get_default, 1);
  rb_define_method (c_guestfs, "btrfs_subvolume_list",
                    guestfs_int_ruby_btrfs_subvolume_list, 1);
  rb_define_method (c_guestfs, "btrfs_subvolume_set_default",
                    guestfs_int_ruby_btrfs_subvolume_set_default, 2);
  rb_define_method (c_guestfs, "btrfs_subvolume_show",
                    guestfs_int_ruby_btrfs_subvolume_show, 1);
  rb_define_method (c_guestfs, "btrfs_subvolume_snapshot",
                    guestfs_int_ruby_btrfs_subvolume_snapshot, -1);
  rb_define_method (c_guestfs, "btrfs_subvolume_snapshot_opts",
                    guestfs_int_ruby_btrfs_subvolume_snapshot, -1);
  rb_define_method (c_guestfs, "btrfstune_enable_extended_inode_refs",
                    guestfs_int_ruby_btrfstune_enable_extended_inode_refs, 1);
  rb_define_method (c_guestfs, "btrfstune_enable_skinny_metadata_extent_refs",
                    guestfs_int_ruby_btrfstune_enable_skinny_metadata_extent_refs, 1);
  rb_define_method (c_guestfs, "btrfstune_seeding",
                    guestfs_int_ruby_btrfstune_seeding, 2);
  rb_define_method (c_guestfs, "c_pointer",
                    guestfs_int_ruby_c_pointer, 0);
  rb_define_method (c_guestfs, "canonical_device_name",
                    guestfs_int_ruby_canonical_device_name, 1);
  rb_define_method (c_guestfs, "cap_get_file",
                    guestfs_int_ruby_cap_get_file, 1);
  rb_define_method (c_guestfs, "cap_set_file",
                    guestfs_int_ruby_cap_set_file, 2);
  rb_define_method (c_guestfs, "case_sensitive_path",
                    guestfs_int_ruby_case_sensitive_path, 1);
  rb_define_method (c_guestfs, "cat",
                    guestfs_int_ruby_cat, 1);
  rb_define_method (c_guestfs, "checksum",
                    guestfs_int_ruby_checksum, 2);
  rb_define_method (c_guestfs, "checksum_device",
                    guestfs_int_ruby_checksum_device, 2);
  rb_define_method (c_guestfs, "checksums_out",
                    guestfs_int_ruby_checksums_out, 3);
  rb_define_method (c_guestfs, "chmod",
                    guestfs_int_ruby_chmod, 2);
  rb_define_method (c_guestfs, "chown",
                    guestfs_int_ruby_chown, 3);
  rb_define_method (c_guestfs, "clear_backend_setting",
                    guestfs_int_ruby_clear_backend_setting, 1);
  rb_define_method (c_guestfs, "command",
                    guestfs_int_ruby_command, 1);
  rb_define_method (c_guestfs, "command_lines",
                    guestfs_int_ruby_command_lines, 1);
  rb_define_method (c_guestfs, "compress_device_out",
                    guestfs_int_ruby_compress_device_out, -1);
  rb_define_method (c_guestfs, "compress_out",
                    guestfs_int_ruby_compress_out, -1);
  rb_define_method (c_guestfs, "config",
                    guestfs_int_ruby_config, 2);
  rb_define_method (c_guestfs, "copy_attributes",
                    guestfs_int_ruby_copy_attributes, -1);
  rb_define_method (c_guestfs, "copy_device_to_device",
                    guestfs_int_ruby_copy_device_to_device, -1);
  rb_define_method (c_guestfs, "copy_device_to_file",
                    guestfs_int_ruby_copy_device_to_file, -1);
  rb_define_method (c_guestfs, "copy_file_to_device",
                    guestfs_int_ruby_copy_file_to_device, -1);
  rb_define_method (c_guestfs, "copy_file_to_file",
                    guestfs_int_ruby_copy_file_to_file, -1);
  rb_define_method (c_guestfs, "copy_in",
                    guestfs_int_ruby_copy_in, 2);
  rb_define_method (c_guestfs, "copy_out",
                    guestfs_int_ruby_copy_out, 2);
  rb_define_method (c_guestfs, "copy_size",
                    guestfs_int_ruby_copy_size, 3);
  rb_define_method (c_guestfs, "cp",
                    guestfs_int_ruby_cp, 2);
  rb_define_method (c_guestfs, "cp_a",
                    guestfs_int_ruby_cp_a, 2);
  rb_define_method (c_guestfs, "cp_r",
                    guestfs_int_ruby_cp_r, 2);
  rb_define_method (c_guestfs, "cpio_out",
                    guestfs_int_ruby_cpio_out, -1);
  rb_define_method (c_guestfs, "dd",
                    guestfs_int_ruby_dd, 2);
  rb_define_method (c_guestfs, "debug",
                    guestfs_int_ruby_debug, 2);
  rb_define_method (c_guestfs, "debug_drives",
                    guestfs_int_ruby_debug_drives, 0);
  rb_define_method (c_guestfs, "debug_upload",
                    guestfs_int_ruby_debug_upload, 3);
  rb_define_method (c_guestfs, "device_index",
                    guestfs_int_ruby_device_index, 1);
  rb_define_method (c_guestfs, "df",
                    guestfs_int_ruby_df, 0);
  rb_define_method (c_guestfs, "df_h",
                    guestfs_int_ruby_df_h, 0);
  rb_define_method (c_guestfs, "disk_create",
                    guestfs_int_ruby_disk_create, -1);
  rb_define_method (c_guestfs, "disk_format",
                    guestfs_int_ruby_disk_format, 1);
  rb_define_method (c_guestfs, "disk_has_backing_file",
                    guestfs_int_ruby_disk_has_backing_file, 1);
  rb_define_method (c_guestfs, "disk_virtual_size",
                    guestfs_int_ruby_disk_virtual_size, 1);
  rb_define_method (c_guestfs, "dmesg",
                    guestfs_int_ruby_dmesg, 0);
  rb_define_method (c_guestfs, "download",
                    guestfs_int_ruby_download, 2);
  rb_define_method (c_guestfs, "download_blocks",
                    guestfs_int_ruby_download_blocks, -1);
  rb_define_method (c_guestfs, "download_inode",
                    guestfs_int_ruby_download_inode, 3);
  rb_define_method (c_guestfs, "download_offset",
                    guestfs_int_ruby_download_offset, 4);
  rb_define_method (c_guestfs, "drop_caches",
                    guestfs_int_ruby_drop_caches, 1);
  rb_define_method (c_guestfs, "du",
                    guestfs_int_ruby_du, 1);
  rb_define_method (c_guestfs, "e2fsck",
                    guestfs_int_ruby_e2fsck, -1);
  rb_define_method (c_guestfs, "e2fsck_f",
                    guestfs_int_ruby_e2fsck_f, 1);
  rb_define_method (c_guestfs, "echo_daemon",
                    guestfs_int_ruby_echo_daemon, 1);
  rb_define_method (c_guestfs, "egrep",
                    guestfs_int_ruby_egrep, 2);
  rb_define_method (c_guestfs, "egrepi",
                    guestfs_int_ruby_egrepi, 2);
  rb_define_method (c_guestfs, "equal",
                    guestfs_int_ruby_equal, 2);
  rb_define_method (c_guestfs, "exists",
                    guestfs_int_ruby_exists, 1);
  rb_define_method (c_guestfs, "extlinux",
                    guestfs_int_ruby_extlinux, 1);
  rb_define_method (c_guestfs, "fallocate",
                    guestfs_int_ruby_fallocate, 2);
  rb_define_method (c_guestfs, "fallocate64",
                    guestfs_int_ruby_fallocate64, 2);
  rb_define_method (c_guestfs, "feature_available",
                    guestfs_int_ruby_feature_available, 1);
  rb_define_method (c_guestfs, "fgrep",
                    guestfs_int_ruby_fgrep, 2);
  rb_define_method (c_guestfs, "fgrepi",
                    guestfs_int_ruby_fgrepi, 2);
  rb_define_method (c_guestfs, "file",
                    guestfs_int_ruby_file, 1);
  rb_define_method (c_guestfs, "file_architecture",
                    guestfs_int_ruby_file_architecture, 1);
  rb_define_method (c_guestfs, "filesize",
                    guestfs_int_ruby_filesize, 1);
  rb_define_method (c_guestfs, "filesystem_available",
                    guestfs_int_ruby_filesystem_available, 1);
  rb_define_method (c_guestfs, "filesystem_walk",
                    guestfs_int_ruby_filesystem_walk, 1);
  rb_define_method (c_guestfs, "fill",
                    guestfs_int_ruby_fill, 3);
  rb_define_method (c_guestfs, "fill_dir",
                    guestfs_int_ruby_fill_dir, 2);
  rb_define_method (c_guestfs, "fill_pattern",
                    guestfs_int_ruby_fill_pattern, 3);
  rb_define_method (c_guestfs, "find",
                    guestfs_int_ruby_find, 1);
  rb_define_method (c_guestfs, "find0",
                    guestfs_int_ruby_find0, 2);
  rb_define_method (c_guestfs, "find_inode",
                    guestfs_int_ruby_find_inode, 2);
  rb_define_method (c_guestfs, "findfs_label",
                    guestfs_int_ruby_findfs_label, 1);
  rb_define_method (c_guestfs, "findfs_uuid",
                    guestfs_int_ruby_findfs_uuid, 1);
  rb_define_method (c_guestfs, "fsck",
                    guestfs_int_ruby_fsck, 2);
  rb_define_method (c_guestfs, "fstrim",
                    guestfs_int_ruby_fstrim, -1);
  rb_define_method (c_guestfs, "get_append",
                    guestfs_int_ruby_get_append, 0);
  rb_define_method (c_guestfs, "get_attach_method",
                    guestfs_int_ruby_get_attach_method, 0);
  rb_define_method (c_guestfs, "get_autosync",
                    guestfs_int_ruby_get_autosync, 0);
  rb_define_method (c_guestfs, "get_backend",
                    guestfs_int_ruby_get_backend, 0);
  rb_define_method (c_guestfs, "get_backend_setting",
                    guestfs_int_ruby_get_backend_setting, 1);
  rb_define_method (c_guestfs, "get_backend_settings",
                    guestfs_int_ruby_get_backend_settings, 0);
  rb_define_method (c_guestfs, "get_cachedir",
                    guestfs_int_ruby_get_cachedir, 0);
  rb_define_method (c_guestfs, "get_direct",
                    guestfs_int_ruby_get_direct, 0);
  rb_define_method (c_guestfs, "get_e2attrs",
                    guestfs_int_ruby_get_e2attrs, 1);
  rb_define_method (c_guestfs, "get_e2generation",
                    guestfs_int_ruby_get_e2generation, 1);
  rb_define_method (c_guestfs, "get_e2label",
                    guestfs_int_ruby_get_e2label, 1);
  rb_define_method (c_guestfs, "get_e2uuid",
                    guestfs_int_ruby_get_e2uuid, 1);
  rb_define_method (c_guestfs, "get_hv",
                    guestfs_int_ruby_get_hv, 0);
  rb_define_method (c_guestfs, "get_identifier",
                    guestfs_int_ruby_get_identifier, 0);
  rb_define_method (c_guestfs, "get_libvirt_requested_credential_challenge",
                    guestfs_int_ruby_get_libvirt_requested_credential_challenge, 1);
  rb_define_method (c_guestfs, "get_libvirt_requested_credential_defresult",
                    guestfs_int_ruby_get_libvirt_requested_credential_defresult, 1);
  rb_define_method (c_guestfs, "get_libvirt_requested_credential_prompt",
                    guestfs_int_ruby_get_libvirt_requested_credential_prompt, 1);
  rb_define_method (c_guestfs, "get_libvirt_requested_credentials",
                    guestfs_int_ruby_get_libvirt_requested_credentials, 0);
  rb_define_method (c_guestfs, "get_memsize",
                    guestfs_int_ruby_get_memsize, 0);
  rb_define_method (c_guestfs, "get_network",
                    guestfs_int_ruby_get_network, 0);
  rb_define_method (c_guestfs, "get_path",
                    guestfs_int_ruby_get_path, 0);
  rb_define_method (c_guestfs, "get_pgroup",
                    guestfs_int_ruby_get_pgroup, 0);
  rb_define_method (c_guestfs, "get_pid",
                    guestfs_int_ruby_get_pid, 0);
  rb_define_method (c_guestfs, "get_program",
                    guestfs_int_ruby_get_program, 0);
  rb_define_method (c_guestfs, "get_qemu",
                    guestfs_int_ruby_get_qemu, 0);
  rb_define_method (c_guestfs, "get_recovery_proc",
                    guestfs_int_ruby_get_recovery_proc, 0);
  rb_define_method (c_guestfs, "get_selinux",
                    guestfs_int_ruby_get_selinux, 0);
  rb_define_method (c_guestfs, "get_smp",
                    guestfs_int_ruby_get_smp, 0);
  rb_define_method (c_guestfs, "get_sockdir",
                    guestfs_int_ruby_get_sockdir, 0);
  rb_define_method (c_guestfs, "get_state",
                    guestfs_int_ruby_get_state, 0);
  rb_define_method (c_guestfs, "get_tmpdir",
                    guestfs_int_ruby_get_tmpdir, 0);
  rb_define_method (c_guestfs, "get_trace",
                    guestfs_int_ruby_get_trace, 0);
  rb_define_method (c_guestfs, "get_umask",
                    guestfs_int_ruby_get_umask, 0);
  rb_define_method (c_guestfs, "get_verbose",
                    guestfs_int_ruby_get_verbose, 0);
  rb_define_method (c_guestfs, "getcon",
                    guestfs_int_ruby_getcon, 0);
  rb_define_method (c_guestfs, "getxattr",
                    guestfs_int_ruby_getxattr, 2);
  rb_define_method (c_guestfs, "getxattrs",
                    guestfs_int_ruby_getxattrs, 1);
  rb_define_method (c_guestfs, "glob_expand",
                    guestfs_int_ruby_glob_expand, -1);
  rb_define_method (c_guestfs, "glob_expand_opts",
                    guestfs_int_ruby_glob_expand, -1);
  rb_define_method (c_guestfs, "grep",
                    guestfs_int_ruby_grep, -1);
  rb_define_method (c_guestfs, "grep_opts",
                    guestfs_int_ruby_grep, -1);
  rb_define_method (c_guestfs, "grepi",
                    guestfs_int_ruby_grepi, 2);
  rb_define_method (c_guestfs, "grub_install",
                    guestfs_int_ruby_grub_install, 2);
  rb_define_method (c_guestfs, "head",
                    guestfs_int_ruby_head, 1);
  rb_define_method (c_guestfs, "head_n",
                    guestfs_int_ruby_head_n, 2);
  rb_define_method (c_guestfs, "hexdump",
                    guestfs_int_ruby_hexdump, 1);
  rb_define_method (c_guestfs, "hivex_close",
                    guestfs_int_ruby_hivex_close, 0);
  rb_define_method (c_guestfs, "hivex_commit",
                    guestfs_int_ruby_hivex_commit, 1);
  rb_define_method (c_guestfs, "hivex_node_add_child",
                    guestfs_int_ruby_hivex_node_add_child, 2);
  rb_define_method (c_guestfs, "hivex_node_children",
                    guestfs_int_ruby_hivex_node_children, 1);
  rb_define_method (c_guestfs, "hivex_node_delete_child",
                    guestfs_int_ruby_hivex_node_delete_child, 1);
  rb_define_method (c_guestfs, "hivex_node_get_child",
                    guestfs_int_ruby_hivex_node_get_child, 2);
  rb_define_method (c_guestfs, "hivex_node_get_value",
                    guestfs_int_ruby_hivex_node_get_value, 2);
  rb_define_method (c_guestfs, "hivex_node_name",
                    guestfs_int_ruby_hivex_node_name, 1);
  rb_define_method (c_guestfs, "hivex_node_parent",
                    guestfs_int_ruby_hivex_node_parent, 1);
  rb_define_method (c_guestfs, "hivex_node_set_value",
                    guestfs_int_ruby_hivex_node_set_value, 4);
  rb_define_method (c_guestfs, "hivex_node_values",
                    guestfs_int_ruby_hivex_node_values, 1);
  rb_define_method (c_guestfs, "hivex_open",
                    guestfs_int_ruby_hivex_open, -1);
  rb_define_method (c_guestfs, "hivex_root",
                    guestfs_int_ruby_hivex_root, 0);
  rb_define_method (c_guestfs, "hivex_value_key",
                    guestfs_int_ruby_hivex_value_key, 1);
  rb_define_method (c_guestfs, "hivex_value_type",
                    guestfs_int_ruby_hivex_value_type, 1);
  rb_define_method (c_guestfs, "hivex_value_utf8",
                    guestfs_int_ruby_hivex_value_utf8, 1);
  rb_define_method (c_guestfs, "hivex_value_value",
                    guestfs_int_ruby_hivex_value_value, 1);
  rb_define_method (c_guestfs, "initrd_cat",
                    guestfs_int_ruby_initrd_cat, 2);
  rb_define_method (c_guestfs, "initrd_list",
                    guestfs_int_ruby_initrd_list, 1);
  rb_define_method (c_guestfs, "inotify_add_watch",
                    guestfs_int_ruby_inotify_add_watch, 2);
  rb_define_method (c_guestfs, "inotify_close",
                    guestfs_int_ruby_inotify_close, 0);
  rb_define_method (c_guestfs, "inotify_files",
                    guestfs_int_ruby_inotify_files, 0);
  rb_define_method (c_guestfs, "inotify_init",
                    guestfs_int_ruby_inotify_init, 1);
  rb_define_method (c_guestfs, "inotify_read",
                    guestfs_int_ruby_inotify_read, 0);
  rb_define_method (c_guestfs, "inotify_rm_watch",
                    guestfs_int_ruby_inotify_rm_watch, 1);
  rb_define_method (c_guestfs, "inspect_get_arch",
                    guestfs_int_ruby_inspect_get_arch, 1);
  rb_define_method (c_guestfs, "inspect_get_distro",
                    guestfs_int_ruby_inspect_get_distro, 1);
  rb_define_method (c_guestfs, "inspect_get_drive_mappings",
                    guestfs_int_ruby_inspect_get_drive_mappings, 1);
  rb_define_method (c_guestfs, "inspect_get_filesystems",
                    guestfs_int_ruby_inspect_get_filesystems, 1);
  rb_define_method (c_guestfs, "inspect_get_format",
                    guestfs_int_ruby_inspect_get_format, 1);
  rb_define_method (c_guestfs, "inspect_get_hostname",
                    guestfs_int_ruby_inspect_get_hostname, 1);
  rb_define_method (c_guestfs, "inspect_get_icon",
                    guestfs_int_ruby_inspect_get_icon, -1);
  rb_define_method (c_guestfs, "inspect_get_major_version",
                    guestfs_int_ruby_inspect_get_major_version, 1);
  rb_define_method (c_guestfs, "inspect_get_minor_version",
                    guestfs_int_ruby_inspect_get_minor_version, 1);
  rb_define_method (c_guestfs, "inspect_get_mountpoints",
                    guestfs_int_ruby_inspect_get_mountpoints, 1);
  rb_define_method (c_guestfs, "inspect_get_package_format",
                    guestfs_int_ruby_inspect_get_package_format, 1);
  rb_define_method (c_guestfs, "inspect_get_package_management",
                    guestfs_int_ruby_inspect_get_package_management, 1);
  rb_define_method (c_guestfs, "inspect_get_product_name",
                    guestfs_int_ruby_inspect_get_product_name, 1);
  rb_define_method (c_guestfs, "inspect_get_product_variant",
                    guestfs_int_ruby_inspect_get_product_variant, 1);
  rb_define_method (c_guestfs, "inspect_get_roots",
                    guestfs_int_ruby_inspect_get_roots, 0);
  rb_define_method (c_guestfs, "inspect_get_type",
                    guestfs_int_ruby_inspect_get_type, 1);
  rb_define_method (c_guestfs, "inspect_get_windows_current_control_set",
                    guestfs_int_ruby_inspect_get_windows_current_control_set, 1);
  rb_define_method (c_guestfs, "inspect_get_windows_software_hive",
                    guestfs_int_ruby_inspect_get_windows_software_hive, 1);
  rb_define_method (c_guestfs, "inspect_get_windows_system_hive",
                    guestfs_int_ruby_inspect_get_windows_system_hive, 1);
  rb_define_method (c_guestfs, "inspect_get_windows_systemroot",
                    guestfs_int_ruby_inspect_get_windows_systemroot, 1);
  rb_define_method (c_guestfs, "inspect_is_live",
                    guestfs_int_ruby_inspect_is_live, 1);
  rb_define_method (c_guestfs, "inspect_is_multipart",
                    guestfs_int_ruby_inspect_is_multipart, 1);
  rb_define_method (c_guestfs, "inspect_is_netinst",
                    guestfs_int_ruby_inspect_is_netinst, 1);
  rb_define_method (c_guestfs, "inspect_list_applications",
                    guestfs_int_ruby_inspect_list_applications, 1);
  rb_define_method (c_guestfs, "inspect_list_applications2",
                    guestfs_int_ruby_inspect_list_applications2, 1);
  rb_define_method (c_guestfs, "inspect_os",
                    guestfs_int_ruby_inspect_os, 0);
  rb_define_method (c_guestfs, "internal_exit",
                    guestfs_int_ruby_internal_exit, 0);
  rb_define_method (c_guestfs, "internal_test",
                    guestfs_int_ruby_internal_test, -1);
  rb_define_method (c_guestfs, "internal_test_63_optargs",
                    guestfs_int_ruby_internal_test_63_optargs, -1);
  rb_define_method (c_guestfs, "internal_test_close_output",
                    guestfs_int_ruby_internal_test_close_output, 0);
  rb_define_method (c_guestfs, "internal_test_only_optargs",
                    guestfs_int_ruby_internal_test_only_optargs, -1);
  rb_define_method (c_guestfs, "internal_test_rbool",
                    guestfs_int_ruby_internal_test_rbool, 1);
  rb_define_method (c_guestfs, "internal_test_rboolerr",
                    guestfs_int_ruby_internal_test_rboolerr, 0);
  rb_define_method (c_guestfs, "internal_test_rbufferout",
                    guestfs_int_ruby_internal_test_rbufferout, 1);
  rb_define_method (c_guestfs, "internal_test_rbufferouterr",
                    guestfs_int_ruby_internal_test_rbufferouterr, 0);
  rb_define_method (c_guestfs, "internal_test_rconstoptstring",
                    guestfs_int_ruby_internal_test_rconstoptstring, 1);
  rb_define_method (c_guestfs, "internal_test_rconstoptstringerr",
                    guestfs_int_ruby_internal_test_rconstoptstringerr, 0);
  rb_define_method (c_guestfs, "internal_test_rconststring",
                    guestfs_int_ruby_internal_test_rconststring, 1);
  rb_define_method (c_guestfs, "internal_test_rconststringerr",
                    guestfs_int_ruby_internal_test_rconststringerr, 0);
  rb_define_method (c_guestfs, "internal_test_rhashtable",
                    guestfs_int_ruby_internal_test_rhashtable, 1);
  rb_define_method (c_guestfs, "internal_test_rhashtableerr",
                    guestfs_int_ruby_internal_test_rhashtableerr, 0);
  rb_define_method (c_guestfs, "internal_test_rint",
                    guestfs_int_ruby_internal_test_rint, 1);
  rb_define_method (c_guestfs, "internal_test_rint64",
                    guestfs_int_ruby_internal_test_rint64, 1);
  rb_define_method (c_guestfs, "internal_test_rint64err",
                    guestfs_int_ruby_internal_test_rint64err, 0);
  rb_define_method (c_guestfs, "internal_test_rinterr",
                    guestfs_int_ruby_internal_test_rinterr, 0);
  rb_define_method (c_guestfs, "internal_test_rstring",
                    guestfs_int_ruby_internal_test_rstring, 1);
  rb_define_method (c_guestfs, "internal_test_rstringerr",
                    guestfs_int_ruby_internal_test_rstringerr, 0);
  rb_define_method (c_guestfs, "internal_test_rstringlist",
                    guestfs_int_ruby_internal_test_rstringlist, 1);
  rb_define_method (c_guestfs, "internal_test_rstringlisterr",
                    guestfs_int_ruby_internal_test_rstringlisterr, 0);
  rb_define_method (c_guestfs, "internal_test_rstruct",
                    guestfs_int_ruby_internal_test_rstruct, 1);
  rb_define_method (c_guestfs, "internal_test_rstructerr",
                    guestfs_int_ruby_internal_test_rstructerr, 0);
  rb_define_method (c_guestfs, "internal_test_rstructlist",
                    guestfs_int_ruby_internal_test_rstructlist, 1);
  rb_define_method (c_guestfs, "internal_test_rstructlisterr",
                    guestfs_int_ruby_internal_test_rstructlisterr, 0);
  rb_define_method (c_guestfs, "internal_test_set_output",
                    guestfs_int_ruby_internal_test_set_output, 1);
  rb_define_method (c_guestfs, "is_blockdev",
                    guestfs_int_ruby_is_blockdev, -1);
  rb_define_method (c_guestfs, "is_blockdev_opts",
                    guestfs_int_ruby_is_blockdev, -1);
  rb_define_method (c_guestfs, "is_busy",
                    guestfs_int_ruby_is_busy, 0);
  rb_define_method (c_guestfs, "is_chardev",
                    guestfs_int_ruby_is_chardev, -1);
  rb_define_method (c_guestfs, "is_chardev_opts",
                    guestfs_int_ruby_is_chardev, -1);
  rb_define_method (c_guestfs, "is_config",
                    guestfs_int_ruby_is_config, 0);
  rb_define_method (c_guestfs, "is_dir",
                    guestfs_int_ruby_is_dir, -1);
  rb_define_method (c_guestfs, "is_dir_opts",
                    guestfs_int_ruby_is_dir, -1);
  rb_define_method (c_guestfs, "is_fifo",
                    guestfs_int_ruby_is_fifo, -1);
  rb_define_method (c_guestfs, "is_fifo_opts",
                    guestfs_int_ruby_is_fifo, -1);
  rb_define_method (c_guestfs, "is_file",
                    guestfs_int_ruby_is_file, -1);
  rb_define_method (c_guestfs, "is_file_opts",
                    guestfs_int_ruby_is_file, -1);
  rb_define_method (c_guestfs, "is_launching",
                    guestfs_int_ruby_is_launching, 0);
  rb_define_method (c_guestfs, "is_lv",
                    guestfs_int_ruby_is_lv, 1);
  rb_define_method (c_guestfs, "is_ready",
                    guestfs_int_ruby_is_ready, 0);
  rb_define_method (c_guestfs, "is_socket",
                    guestfs_int_ruby_is_socket, -1);
  rb_define_method (c_guestfs, "is_socket_opts",
                    guestfs_int_ruby_is_socket, -1);
  rb_define_method (c_guestfs, "is_symlink",
                    guestfs_int_ruby_is_symlink, 1);
  rb_define_method (c_guestfs, "is_whole_device",
                    guestfs_int_ruby_is_whole_device, 1);
  rb_define_method (c_guestfs, "is_zero",
                    guestfs_int_ruby_is_zero, 1);
  rb_define_method (c_guestfs, "is_zero_device",
                    guestfs_int_ruby_is_zero_device, 1);
  rb_define_method (c_guestfs, "isoinfo",
                    guestfs_int_ruby_isoinfo, 1);
  rb_define_method (c_guestfs, "isoinfo_device",
                    guestfs_int_ruby_isoinfo_device, 1);
  rb_define_method (c_guestfs, "journal_close",
                    guestfs_int_ruby_journal_close, 0);
  rb_define_method (c_guestfs, "journal_get",
                    guestfs_int_ruby_journal_get, 0);
  rb_define_method (c_guestfs, "journal_get_data_threshold",
                    guestfs_int_ruby_journal_get_data_threshold, 0);
  rb_define_method (c_guestfs, "journal_get_realtime_usec",
                    guestfs_int_ruby_journal_get_realtime_usec, 0);
  rb_define_method (c_guestfs, "journal_next",
                    guestfs_int_ruby_journal_next, 0);
  rb_define_method (c_guestfs, "journal_open",
                    guestfs_int_ruby_journal_open, 1);
  rb_define_method (c_guestfs, "journal_set_data_threshold",
                    guestfs_int_ruby_journal_set_data_threshold, 1);
  rb_define_method (c_guestfs, "journal_skip",
                    guestfs_int_ruby_journal_skip, 1);
  rb_define_method (c_guestfs, "kill_subprocess",
                    guestfs_int_ruby_kill_subprocess, 0);
  rb_define_method (c_guestfs, "launch",
                    guestfs_int_ruby_launch, 0);
  rb_define_method (c_guestfs, "lchown",
                    guestfs_int_ruby_lchown, 3);
  rb_define_method (c_guestfs, "ldmtool_create_all",
                    guestfs_int_ruby_ldmtool_create_all, 0);
  rb_define_method (c_guestfs, "ldmtool_diskgroup_disks",
                    guestfs_int_ruby_ldmtool_diskgroup_disks, 1);
  rb_define_method (c_guestfs, "ldmtool_diskgroup_name",
                    guestfs_int_ruby_ldmtool_diskgroup_name, 1);
  rb_define_method (c_guestfs, "ldmtool_diskgroup_volumes",
                    guestfs_int_ruby_ldmtool_diskgroup_volumes, 1);
  rb_define_method (c_guestfs, "ldmtool_remove_all",
                    guestfs_int_ruby_ldmtool_remove_all, 0);
  rb_define_method (c_guestfs, "ldmtool_scan",
                    guestfs_int_ruby_ldmtool_scan, 0);
  rb_define_method (c_guestfs, "ldmtool_scan_devices",
                    guestfs_int_ruby_ldmtool_scan_devices, 1);
  rb_define_method (c_guestfs, "ldmtool_volume_hint",
                    guestfs_int_ruby_ldmtool_volume_hint, 2);
  rb_define_method (c_guestfs, "ldmtool_volume_partitions",
                    guestfs_int_ruby_ldmtool_volume_partitions, 2);
  rb_define_method (c_guestfs, "ldmtool_volume_type",
                    guestfs_int_ruby_ldmtool_volume_type, 2);
  rb_define_method (c_guestfs, "lgetxattr",
                    guestfs_int_ruby_lgetxattr, 2);
  rb_define_method (c_guestfs, "lgetxattrs",
                    guestfs_int_ruby_lgetxattrs, 1);
  rb_define_method (c_guestfs, "list_9p",
                    guestfs_int_ruby_list_9p, 0);
  rb_define_method (c_guestfs, "list_devices",
                    guestfs_int_ruby_list_devices, 0);
  rb_define_method (c_guestfs, "list_disk_labels",
                    guestfs_int_ruby_list_disk_labels, 0);
  rb_define_method (c_guestfs, "list_dm_devices",
                    guestfs_int_ruby_list_dm_devices, 0);
  rb_define_method (c_guestfs, "list_filesystems",
                    guestfs_int_ruby_list_filesystems, 0);
  rb_define_method (c_guestfs, "list_ldm_partitions",
                    guestfs_int_ruby_list_ldm_partitions, 0);
  rb_define_method (c_guestfs, "list_ldm_volumes",
                    guestfs_int_ruby_list_ldm_volumes, 0);
  rb_define_method (c_guestfs, "list_md_devices",
                    guestfs_int_ruby_list_md_devices, 0);
  rb_define_method (c_guestfs, "list_partitions",
                    guestfs_int_ruby_list_partitions, 0);
  rb_define_method (c_guestfs, "ll",
                    guestfs_int_ruby_ll, 1);
  rb_define_method (c_guestfs, "llz",
                    guestfs_int_ruby_llz, 1);
  rb_define_method (c_guestfs, "ln",
                    guestfs_int_ruby_ln, 2);
  rb_define_method (c_guestfs, "ln_f",
                    guestfs_int_ruby_ln_f, 2);
  rb_define_method (c_guestfs, "ln_s",
                    guestfs_int_ruby_ln_s, 2);
  rb_define_method (c_guestfs, "ln_sf",
                    guestfs_int_ruby_ln_sf, 2);
  rb_define_method (c_guestfs, "lremovexattr",
                    guestfs_int_ruby_lremovexattr, 2);
  rb_define_method (c_guestfs, "ls",
                    guestfs_int_ruby_ls, 1);
  rb_define_method (c_guestfs, "ls0",
                    guestfs_int_ruby_ls0, 2);
  rb_define_method (c_guestfs, "lsetxattr",
                    guestfs_int_ruby_lsetxattr, 4);
  rb_define_method (c_guestfs, "lstat",
                    guestfs_int_ruby_lstat, 1);
  rb_define_method (c_guestfs, "lstatlist",
                    guestfs_int_ruby_lstatlist, 2);
  rb_define_method (c_guestfs, "lstatns",
                    guestfs_int_ruby_lstatns, 1);
  rb_define_method (c_guestfs, "lstatnslist",
                    guestfs_int_ruby_lstatnslist, 2);
  rb_define_method (c_guestfs, "luks_add_key",
                    guestfs_int_ruby_luks_add_key, 4);
  rb_define_method (c_guestfs, "luks_close",
                    guestfs_int_ruby_luks_close, 1);
  rb_define_method (c_guestfs, "luks_format",
                    guestfs_int_ruby_luks_format, 3);
  rb_define_method (c_guestfs, "luks_format_cipher",
                    guestfs_int_ruby_luks_format_cipher, 4);
  rb_define_method (c_guestfs, "luks_kill_slot",
                    guestfs_int_ruby_luks_kill_slot, 3);
  rb_define_method (c_guestfs, "luks_open",
                    guestfs_int_ruby_luks_open, 3);
  rb_define_method (c_guestfs, "luks_open_ro",
                    guestfs_int_ruby_luks_open_ro, 3);
  rb_define_method (c_guestfs, "lvcreate",
                    guestfs_int_ruby_lvcreate, 3);
  rb_define_method (c_guestfs, "lvcreate_free",
                    guestfs_int_ruby_lvcreate_free, 3);
  rb_define_method (c_guestfs, "lvm_canonical_lv_name",
                    guestfs_int_ruby_lvm_canonical_lv_name, 1);
  rb_define_method (c_guestfs, "lvm_clear_filter",
                    guestfs_int_ruby_lvm_clear_filter, 0);
  rb_define_method (c_guestfs, "lvm_remove_all",
                    guestfs_int_ruby_lvm_remove_all, 0);
  rb_define_method (c_guestfs, "lvm_set_filter",
                    guestfs_int_ruby_lvm_set_filter, 1);
  rb_define_method (c_guestfs, "lvremove",
                    guestfs_int_ruby_lvremove, 1);
  rb_define_method (c_guestfs, "lvrename",
                    guestfs_int_ruby_lvrename, 2);
  rb_define_method (c_guestfs, "lvresize",
                    guestfs_int_ruby_lvresize, 2);
  rb_define_method (c_guestfs, "lvresize_free",
                    guestfs_int_ruby_lvresize_free, 2);
  rb_define_method (c_guestfs, "lvs",
                    guestfs_int_ruby_lvs, 0);
  rb_define_method (c_guestfs, "lvs_full",
                    guestfs_int_ruby_lvs_full, 0);
  rb_define_method (c_guestfs, "lvuuid",
                    guestfs_int_ruby_lvuuid, 1);
  rb_define_method (c_guestfs, "lxattrlist",
                    guestfs_int_ruby_lxattrlist, 2);
  rb_define_method (c_guestfs, "max_disks",
                    guestfs_int_ruby_max_disks, 0);
  rb_define_method (c_guestfs, "md_create",
                    guestfs_int_ruby_md_create, -1);
  rb_define_method (c_guestfs, "md_detail",
                    guestfs_int_ruby_md_detail, 1);
  rb_define_method (c_guestfs, "md_stat",
                    guestfs_int_ruby_md_stat, 1);
  rb_define_method (c_guestfs, "md_stop",
                    guestfs_int_ruby_md_stop, 1);
  rb_define_method (c_guestfs, "mkdir",
                    guestfs_int_ruby_mkdir, 1);
  rb_define_method (c_guestfs, "mkdir_mode",
                    guestfs_int_ruby_mkdir_mode, 2);
  rb_define_method (c_guestfs, "mkdir_p",
                    guestfs_int_ruby_mkdir_p, 1);
  rb_define_method (c_guestfs, "mkdtemp",
                    guestfs_int_ruby_mkdtemp, 1);
  rb_define_method (c_guestfs, "mke2fs",
                    guestfs_int_ruby_mke2fs, -1);
  rb_define_method (c_guestfs, "mke2fs_J",
                    guestfs_int_ruby_mke2fs_J, 4);
  rb_define_method (c_guestfs, "mke2fs_JL",
                    guestfs_int_ruby_mke2fs_JL, 4);
  rb_define_method (c_guestfs, "mke2fs_JU",
                    guestfs_int_ruby_mke2fs_JU, 4);
  rb_define_method (c_guestfs, "mke2journal",
                    guestfs_int_ruby_mke2journal, 2);
  rb_define_method (c_guestfs, "mke2journal_L",
                    guestfs_int_ruby_mke2journal_L, 3);
  rb_define_method (c_guestfs, "mke2journal_U",
                    guestfs_int_ruby_mke2journal_U, 3);
  rb_define_method (c_guestfs, "mkfifo",
                    guestfs_int_ruby_mkfifo, 2);
  rb_define_method (c_guestfs, "mkfs",
                    guestfs_int_ruby_mkfs, -1);
  rb_define_method (c_guestfs, "mkfs_opts",
                    guestfs_int_ruby_mkfs, -1);
  rb_define_method (c_guestfs, "mkfs_b",
                    guestfs_int_ruby_mkfs_b, 3);
  rb_define_method (c_guestfs, "mkfs_btrfs",
                    guestfs_int_ruby_mkfs_btrfs, -1);
  rb_define_method (c_guestfs, "mklost_and_found",
                    guestfs_int_ruby_mklost_and_found, 1);
  rb_define_method (c_guestfs, "mkmountpoint",
                    guestfs_int_ruby_mkmountpoint, 1);
  rb_define_method (c_guestfs, "mknod",
                    guestfs_int_ruby_mknod, 4);
  rb_define_method (c_guestfs, "mknod_b",
                    guestfs_int_ruby_mknod_b, 4);
  rb_define_method (c_guestfs, "mknod_c",
                    guestfs_int_ruby_mknod_c, 4);
  rb_define_method (c_guestfs, "mksquashfs",
                    guestfs_int_ruby_mksquashfs, -1);
  rb_define_method (c_guestfs, "mkswap",
                    guestfs_int_ruby_mkswap, -1);
  rb_define_method (c_guestfs, "mkswap_opts",
                    guestfs_int_ruby_mkswap, -1);
  rb_define_method (c_guestfs, "mkswap_L",
                    guestfs_int_ruby_mkswap_L, 2);
  rb_define_method (c_guestfs, "mkswap_U",
                    guestfs_int_ruby_mkswap_U, 2);
  rb_define_method (c_guestfs, "mkswap_file",
                    guestfs_int_ruby_mkswap_file, 1);
  rb_define_method (c_guestfs, "mktemp",
                    guestfs_int_ruby_mktemp, -1);
  rb_define_method (c_guestfs, "modprobe",
                    guestfs_int_ruby_modprobe, 1);
  rb_define_method (c_guestfs, "mount",
                    guestfs_int_ruby_mount, 2);
  rb_define_method (c_guestfs, "mount_9p",
                    guestfs_int_ruby_mount_9p, -1);
  rb_define_method (c_guestfs, "mount_local",
                    guestfs_int_ruby_mount_local, -1);
  rb_define_method (c_guestfs, "mount_local_run",
                    guestfs_int_ruby_mount_local_run, 0);
  rb_define_method (c_guestfs, "mount_loop",
                    guestfs_int_ruby_mount_loop, 2);
  rb_define_method (c_guestfs, "mount_options",
                    guestfs_int_ruby_mount_options, 3);
  rb_define_method (c_guestfs, "mount_ro",
                    guestfs_int_ruby_mount_ro, 2);
  rb_define_method (c_guestfs, "mount_vfs",
                    guestfs_int_ruby_mount_vfs, 4);
  rb_define_method (c_guestfs, "mountable_device",
                    guestfs_int_ruby_mountable_device, 1);
  rb_define_method (c_guestfs, "mountable_subvolume",
                    guestfs_int_ruby_mountable_subvolume, 1);
  rb_define_method (c_guestfs, "mountpoints",
                    guestfs_int_ruby_mountpoints, 0);
  rb_define_method (c_guestfs, "mounts",
                    guestfs_int_ruby_mounts, 0);
  rb_define_method (c_guestfs, "mv",
                    guestfs_int_ruby_mv, 2);
  rb_define_method (c_guestfs, "nr_devices",
                    guestfs_int_ruby_nr_devices, 0);
  rb_define_method (c_guestfs, "ntfs_3g_probe",
                    guestfs_int_ruby_ntfs_3g_probe, 2);
  rb_define_method (c_guestfs, "ntfscat_i",
                    guestfs_int_ruby_ntfscat_i, 3);
  rb_define_method (c_guestfs, "ntfsclone_in",
                    guestfs_int_ruby_ntfsclone_in, 2);
  rb_define_method (c_guestfs, "ntfsclone_out",
                    guestfs_int_ruby_ntfsclone_out, -1);
  rb_define_method (c_guestfs, "ntfsfix",
                    guestfs_int_ruby_ntfsfix, -1);
  rb_define_method (c_guestfs, "ntfsresize",
                    guestfs_int_ruby_ntfsresize, -1);
  rb_define_method (c_guestfs, "ntfsresize_opts",
                    guestfs_int_ruby_ntfsresize, -1);
  rb_define_method (c_guestfs, "ntfsresize_size",
                    guestfs_int_ruby_ntfsresize_size, 2);
  rb_define_method (c_guestfs, "parse_environment",
                    guestfs_int_ruby_parse_environment, 0);
  rb_define_method (c_guestfs, "parse_environment_list",
                    guestfs_int_ruby_parse_environment_list, 1);
  rb_define_method (c_guestfs, "part_add",
                    guestfs_int_ruby_part_add, 4);
  rb_define_method (c_guestfs, "part_del",
                    guestfs_int_ruby_part_del, 2);
  rb_define_method (c_guestfs, "part_disk",
                    guestfs_int_ruby_part_disk, 2);
  rb_define_method (c_guestfs, "part_expand_gpt",
                    guestfs_int_ruby_part_expand_gpt, 1);
  rb_define_method (c_guestfs, "part_get_bootable",
                    guestfs_int_ruby_part_get_bootable, 2);
  rb_define_method (c_guestfs, "part_get_disk_guid",
                    guestfs_int_ruby_part_get_disk_guid, 1);
  rb_define_method (c_guestfs, "part_get_gpt_guid",
                    guestfs_int_ruby_part_get_gpt_guid, 2);
  rb_define_method (c_guestfs, "part_get_gpt_type",
                    guestfs_int_ruby_part_get_gpt_type, 2);
  rb_define_method (c_guestfs, "part_get_mbr_id",
                    guestfs_int_ruby_part_get_mbr_id, 2);
  rb_define_method (c_guestfs, "part_get_mbr_part_type",
                    guestfs_int_ruby_part_get_mbr_part_type, 2);
  rb_define_method (c_guestfs, "part_get_name",
                    guestfs_int_ruby_part_get_name, 2);
  rb_define_method (c_guestfs, "part_get_parttype",
                    guestfs_int_ruby_part_get_parttype, 1);
  rb_define_method (c_guestfs, "part_init",
                    guestfs_int_ruby_part_init, 2);
  rb_define_method (c_guestfs, "part_list",
                    guestfs_int_ruby_part_list, 1);
  rb_define_method (c_guestfs, "part_set_bootable",
                    guestfs_int_ruby_part_set_bootable, 3);
  rb_define_method (c_guestfs, "part_set_disk_guid",
                    guestfs_int_ruby_part_set_disk_guid, 2);
  rb_define_method (c_guestfs, "part_set_disk_guid_random",
                    guestfs_int_ruby_part_set_disk_guid_random, 1);
  rb_define_method (c_guestfs, "part_set_gpt_guid",
                    guestfs_int_ruby_part_set_gpt_guid, 3);
  rb_define_method (c_guestfs, "part_set_gpt_type",
                    guestfs_int_ruby_part_set_gpt_type, 3);
  rb_define_method (c_guestfs, "part_set_mbr_id",
                    guestfs_int_ruby_part_set_mbr_id, 3);
  rb_define_method (c_guestfs, "part_set_name",
                    guestfs_int_ruby_part_set_name, 3);
  rb_define_method (c_guestfs, "part_to_dev",
                    guestfs_int_ruby_part_to_dev, 1);
  rb_define_method (c_guestfs, "part_to_partnum",
                    guestfs_int_ruby_part_to_partnum, 1);
  rb_define_method (c_guestfs, "ping_daemon",
                    guestfs_int_ruby_ping_daemon, 0);
  rb_define_method (c_guestfs, "pread",
                    guestfs_int_ruby_pread, 3);
  rb_define_method (c_guestfs, "pread_device",
                    guestfs_int_ruby_pread_device, 3);
  rb_define_method (c_guestfs, "pvchange_uuid",
                    guestfs_int_ruby_pvchange_uuid, 1);
  rb_define_method (c_guestfs, "pvchange_uuid_all",
                    guestfs_int_ruby_pvchange_uuid_all, 0);
  rb_define_method (c_guestfs, "pvcreate",
                    guestfs_int_ruby_pvcreate, 1);
  rb_define_method (c_guestfs, "pvremove",
                    guestfs_int_ruby_pvremove, 1);
  rb_define_method (c_guestfs, "pvresize",
                    guestfs_int_ruby_pvresize, 1);
  rb_define_method (c_guestfs, "pvresize_size",
                    guestfs_int_ruby_pvresize_size, 2);
  rb_define_method (c_guestfs, "pvs",
                    guestfs_int_ruby_pvs, 0);
  rb_define_method (c_guestfs, "pvs_full",
                    guestfs_int_ruby_pvs_full, 0);
  rb_define_method (c_guestfs, "pvuuid",
                    guestfs_int_ruby_pvuuid, 1);
  rb_define_method (c_guestfs, "pwrite",
                    guestfs_int_ruby_pwrite, 3);
  rb_define_method (c_guestfs, "pwrite_device",
                    guestfs_int_ruby_pwrite_device, 3);
  rb_define_method (c_guestfs, "read_file",
                    guestfs_int_ruby_read_file, 1);
  rb_define_method (c_guestfs, "read_lines",
                    guestfs_int_ruby_read_lines, 1);
  rb_define_method (c_guestfs, "readdir",
                    guestfs_int_ruby_readdir, 1);
  rb_define_method (c_guestfs, "readlink",
                    guestfs_int_ruby_readlink, 1);
  rb_define_method (c_guestfs, "readlinklist",
                    guestfs_int_ruby_readlinklist, 2);
  rb_define_method (c_guestfs, "realpath",
                    guestfs_int_ruby_realpath, 1);
  rb_define_method (c_guestfs, "remount",
                    guestfs_int_ruby_remount, -1);
  rb_define_method (c_guestfs, "remove_drive",
                    guestfs_int_ruby_remove_drive, 1);
  rb_define_method (c_guestfs, "removexattr",
                    guestfs_int_ruby_removexattr, 2);
  rb_define_method (c_guestfs, "rename",
                    guestfs_int_ruby_rename, 2);
  rb_define_method (c_guestfs, "resize2fs",
                    guestfs_int_ruby_resize2fs, 1);
  rb_define_method (c_guestfs, "resize2fs_M",
                    guestfs_int_ruby_resize2fs_M, 1);
  rb_define_method (c_guestfs, "resize2fs_size",
                    guestfs_int_ruby_resize2fs_size, 2);
  rb_define_method (c_guestfs, "rm",
                    guestfs_int_ruby_rm, 1);
  rb_define_method (c_guestfs, "rm_f",
                    guestfs_int_ruby_rm_f, 1);
  rb_define_method (c_guestfs, "rm_rf",
                    guestfs_int_ruby_rm_rf, 1);
  rb_define_method (c_guestfs, "rmdir",
                    guestfs_int_ruby_rmdir, 1);
  rb_define_method (c_guestfs, "rmmountpoint",
                    guestfs_int_ruby_rmmountpoint, 1);
  rb_define_method (c_guestfs, "rsync",
                    guestfs_int_ruby_rsync, -1);
  rb_define_method (c_guestfs, "rsync_in",
                    guestfs_int_ruby_rsync_in, -1);
  rb_define_method (c_guestfs, "rsync_out",
                    guestfs_int_ruby_rsync_out, -1);
  rb_define_method (c_guestfs, "scrub_device",
                    guestfs_int_ruby_scrub_device, 1);
  rb_define_method (c_guestfs, "scrub_file",
                    guestfs_int_ruby_scrub_file, 1);
  rb_define_method (c_guestfs, "scrub_freespace",
                    guestfs_int_ruby_scrub_freespace, 1);
  rb_define_method (c_guestfs, "selinux_relabel",
                    guestfs_int_ruby_selinux_relabel, -1);
  rb_define_method (c_guestfs, "set_append",
                    guestfs_int_ruby_set_append, 1);
  rb_define_method (c_guestfs, "set_attach_method",
                    guestfs_int_ruby_set_attach_method, 1);
  rb_define_method (c_guestfs, "set_autosync",
                    guestfs_int_ruby_set_autosync, 1);
  rb_define_method (c_guestfs, "set_backend",
                    guestfs_int_ruby_set_backend, 1);
  rb_define_method (c_guestfs, "set_backend_setting",
                    guestfs_int_ruby_set_backend_setting, 2);
  rb_define_method (c_guestfs, "set_backend_settings",
                    guestfs_int_ruby_set_backend_settings, 1);
  rb_define_method (c_guestfs, "set_cachedir",
                    guestfs_int_ruby_set_cachedir, 1);
  rb_define_method (c_guestfs, "set_direct",
                    guestfs_int_ruby_set_direct, 1);
  rb_define_method (c_guestfs, "set_e2attrs",
                    guestfs_int_ruby_set_e2attrs, -1);
  rb_define_method (c_guestfs, "set_e2generation",
                    guestfs_int_ruby_set_e2generation, 2);
  rb_define_method (c_guestfs, "set_e2label",
                    guestfs_int_ruby_set_e2label, 2);
  rb_define_method (c_guestfs, "set_e2uuid",
                    guestfs_int_ruby_set_e2uuid, 2);
  rb_define_method (c_guestfs, "set_hv",
                    guestfs_int_ruby_set_hv, 1);
  rb_define_method (c_guestfs, "set_identifier",
                    guestfs_int_ruby_set_identifier, 1);
  rb_define_method (c_guestfs, "set_label",
                    guestfs_int_ruby_set_label, 2);
  rb_define_method (c_guestfs, "set_libvirt_requested_credential",
                    guestfs_int_ruby_set_libvirt_requested_credential, 2);
  rb_define_method (c_guestfs, "set_libvirt_supported_credentials",
                    guestfs_int_ruby_set_libvirt_supported_credentials, 1);
  rb_define_method (c_guestfs, "set_memsize",
                    guestfs_int_ruby_set_memsize, 1);
  rb_define_method (c_guestfs, "set_network",
                    guestfs_int_ruby_set_network, 1);
  rb_define_method (c_guestfs, "set_path",
                    guestfs_int_ruby_set_path, 1);
  rb_define_method (c_guestfs, "set_pgroup",
                    guestfs_int_ruby_set_pgroup, 1);
  rb_define_method (c_guestfs, "set_program",
                    guestfs_int_ruby_set_program, 1);
  rb_define_method (c_guestfs, "set_qemu",
                    guestfs_int_ruby_set_qemu, 1);
  rb_define_method (c_guestfs, "set_recovery_proc",
                    guestfs_int_ruby_set_recovery_proc, 1);
  rb_define_method (c_guestfs, "set_selinux",
                    guestfs_int_ruby_set_selinux, 1);
  rb_define_method (c_guestfs, "set_smp",
                    guestfs_int_ruby_set_smp, 1);
  rb_define_method (c_guestfs, "set_tmpdir",
                    guestfs_int_ruby_set_tmpdir, 1);
  rb_define_method (c_guestfs, "set_trace",
                    guestfs_int_ruby_set_trace, 1);
  rb_define_method (c_guestfs, "set_uuid",
                    guestfs_int_ruby_set_uuid, 2);
  rb_define_method (c_guestfs, "set_uuid_random",
                    guestfs_int_ruby_set_uuid_random, 1);
  rb_define_method (c_guestfs, "set_verbose",
                    guestfs_int_ruby_set_verbose, 1);
  rb_define_method (c_guestfs, "setcon",
                    guestfs_int_ruby_setcon, 1);
  rb_define_method (c_guestfs, "setxattr",
                    guestfs_int_ruby_setxattr, 4);
  rb_define_method (c_guestfs, "sfdisk",
                    guestfs_int_ruby_sfdisk, 5);
  rb_define_method (c_guestfs, "sfdiskM",
                    guestfs_int_ruby_sfdiskM, 2);
  rb_define_method (c_guestfs, "sfdisk_N",
                    guestfs_int_ruby_sfdisk_N, 6);
  rb_define_method (c_guestfs, "sfdisk_disk_geometry",
                    guestfs_int_ruby_sfdisk_disk_geometry, 1);
  rb_define_method (c_guestfs, "sfdisk_kernel_geometry",
                    guestfs_int_ruby_sfdisk_kernel_geometry, 1);
  rb_define_method (c_guestfs, "sfdisk_l",
                    guestfs_int_ruby_sfdisk_l, 1);
  rb_define_method (c_guestfs, "sh",
                    guestfs_int_ruby_sh, 1);
  rb_define_method (c_guestfs, "sh_lines",
                    guestfs_int_ruby_sh_lines, 1);
  rb_define_method (c_guestfs, "shutdown",
                    guestfs_int_ruby_shutdown, 0);
  rb_define_method (c_guestfs, "sleep",
                    guestfs_int_ruby_sleep, 1);
  rb_define_method (c_guestfs, "stat",
                    guestfs_int_ruby_stat, 1);
  rb_define_method (c_guestfs, "statns",
                    guestfs_int_ruby_statns, 1);
  rb_define_method (c_guestfs, "statvfs",
                    guestfs_int_ruby_statvfs, 1);
  rb_define_method (c_guestfs, "strings",
                    guestfs_int_ruby_strings, 1);
  rb_define_method (c_guestfs, "strings_e",
                    guestfs_int_ruby_strings_e, 2);
  rb_define_method (c_guestfs, "swapoff_device",
                    guestfs_int_ruby_swapoff_device, 1);
  rb_define_method (c_guestfs, "swapoff_file",
                    guestfs_int_ruby_swapoff_file, 1);
  rb_define_method (c_guestfs, "swapoff_label",
                    guestfs_int_ruby_swapoff_label, 1);
  rb_define_method (c_guestfs, "swapoff_uuid",
                    guestfs_int_ruby_swapoff_uuid, 1);
  rb_define_method (c_guestfs, "swapon_device",
                    guestfs_int_ruby_swapon_device, 1);
  rb_define_method (c_guestfs, "swapon_file",
                    guestfs_int_ruby_swapon_file, 1);
  rb_define_method (c_guestfs, "swapon_label",
                    guestfs_int_ruby_swapon_label, 1);
  rb_define_method (c_guestfs, "swapon_uuid",
                    guestfs_int_ruby_swapon_uuid, 1);
  rb_define_method (c_guestfs, "sync",
                    guestfs_int_ruby_sync, 0);
  rb_define_method (c_guestfs, "syslinux",
                    guestfs_int_ruby_syslinux, -1);
  rb_define_method (c_guestfs, "tail",
                    guestfs_int_ruby_tail, 1);
  rb_define_method (c_guestfs, "tail_n",
                    guestfs_int_ruby_tail_n, 2);
  rb_define_method (c_guestfs, "tar_in",
                    guestfs_int_ruby_tar_in, -1);
  rb_define_method (c_guestfs, "tar_in_opts",
                    guestfs_int_ruby_tar_in, -1);
  rb_define_method (c_guestfs, "tar_out",
                    guestfs_int_ruby_tar_out, -1);
  rb_define_method (c_guestfs, "tar_out_opts",
                    guestfs_int_ruby_tar_out, -1);
  rb_define_method (c_guestfs, "tgz_in",
                    guestfs_int_ruby_tgz_in, 2);
  rb_define_method (c_guestfs, "tgz_out",
                    guestfs_int_ruby_tgz_out, 2);
  rb_define_method (c_guestfs, "touch",
                    guestfs_int_ruby_touch, 1);
  rb_define_method (c_guestfs, "truncate",
                    guestfs_int_ruby_truncate, 1);
  rb_define_method (c_guestfs, "truncate_size",
                    guestfs_int_ruby_truncate_size, 2);
  rb_define_method (c_guestfs, "tune2fs",
                    guestfs_int_ruby_tune2fs, -1);
  rb_define_method (c_guestfs, "tune2fs_l",
                    guestfs_int_ruby_tune2fs_l, 1);
  rb_define_method (c_guestfs, "txz_in",
                    guestfs_int_ruby_txz_in, 2);
  rb_define_method (c_guestfs, "txz_out",
                    guestfs_int_ruby_txz_out, 2);
  rb_define_method (c_guestfs, "umask",
                    guestfs_int_ruby_umask, 1);
  rb_define_method (c_guestfs, "umount",
                    guestfs_int_ruby_umount, -1);
  rb_define_method (c_guestfs, "umount_opts",
                    guestfs_int_ruby_umount, -1);
  rb_define_method (c_guestfs, "umount_all",
                    guestfs_int_ruby_umount_all, 0);
  rb_define_method (c_guestfs, "umount_local",
                    guestfs_int_ruby_umount_local, -1);
  rb_define_method (c_guestfs, "upload",
                    guestfs_int_ruby_upload, 2);
  rb_define_method (c_guestfs, "upload_offset",
                    guestfs_int_ruby_upload_offset, 3);
  rb_define_method (c_guestfs, "user_cancel",
                    guestfs_int_ruby_user_cancel, 0);
  rb_define_method (c_guestfs, "utimens",
                    guestfs_int_ruby_utimens, 5);
  rb_define_method (c_guestfs, "utsname",
                    guestfs_int_ruby_utsname, 0);
  rb_define_method (c_guestfs, "version",
                    guestfs_int_ruby_version, 0);
  rb_define_method (c_guestfs, "vfs_label",
                    guestfs_int_ruby_vfs_label, 1);
  rb_define_method (c_guestfs, "vfs_minimum_size",
                    guestfs_int_ruby_vfs_minimum_size, 1);
  rb_define_method (c_guestfs, "vfs_type",
                    guestfs_int_ruby_vfs_type, 1);
  rb_define_method (c_guestfs, "vfs_uuid",
                    guestfs_int_ruby_vfs_uuid, 1);
  rb_define_method (c_guestfs, "vg_activate",
                    guestfs_int_ruby_vg_activate, 2);
  rb_define_method (c_guestfs, "vg_activate_all",
                    guestfs_int_ruby_vg_activate_all, 1);
  rb_define_method (c_guestfs, "vgchange_uuid",
                    guestfs_int_ruby_vgchange_uuid, 1);
  rb_define_method (c_guestfs, "vgchange_uuid_all",
                    guestfs_int_ruby_vgchange_uuid_all, 0);
  rb_define_method (c_guestfs, "vgcreate",
                    guestfs_int_ruby_vgcreate, 2);
  rb_define_method (c_guestfs, "vglvuuids",
                    guestfs_int_ruby_vglvuuids, 1);
  rb_define_method (c_guestfs, "vgmeta",
                    guestfs_int_ruby_vgmeta, 1);
  rb_define_method (c_guestfs, "vgpvuuids",
                    guestfs_int_ruby_vgpvuuids, 1);
  rb_define_method (c_guestfs, "vgremove",
                    guestfs_int_ruby_vgremove, 1);
  rb_define_method (c_guestfs, "vgrename",
                    guestfs_int_ruby_vgrename, 2);
  rb_define_method (c_guestfs, "vgs",
                    guestfs_int_ruby_vgs, 0);
  rb_define_method (c_guestfs, "vgs_full",
                    guestfs_int_ruby_vgs_full, 0);
  rb_define_method (c_guestfs, "vgscan",
                    guestfs_int_ruby_vgscan, 0);
  rb_define_method (c_guestfs, "vguuid",
                    guestfs_int_ruby_vguuid, 1);
  rb_define_method (c_guestfs, "wait_ready",
                    guestfs_int_ruby_wait_ready, 0);
  rb_define_method (c_guestfs, "wc_c",
                    guestfs_int_ruby_wc_c, 1);
  rb_define_method (c_guestfs, "wc_l",
                    guestfs_int_ruby_wc_l, 1);
  rb_define_method (c_guestfs, "wc_w",
                    guestfs_int_ruby_wc_w, 1);
  rb_define_method (c_guestfs, "wipefs",
                    guestfs_int_ruby_wipefs, 1);
  rb_define_method (c_guestfs, "write",
                    guestfs_int_ruby_write, 2);
  rb_define_method (c_guestfs, "write_append",
                    guestfs_int_ruby_write_append, 2);
  rb_define_method (c_guestfs, "write_file",
                    guestfs_int_ruby_write_file, 3);
  rb_define_method (c_guestfs, "xfs_admin",
                    guestfs_int_ruby_xfs_admin, -1);
  rb_define_method (c_guestfs, "xfs_growfs",
                    guestfs_int_ruby_xfs_growfs, -1);
  rb_define_method (c_guestfs, "xfs_info",
                    guestfs_int_ruby_xfs_info, 1);
  rb_define_method (c_guestfs, "xfs_repair",
                    guestfs_int_ruby_xfs_repair, -1);
  rb_define_method (c_guestfs, "zegrep",
                    guestfs_int_ruby_zegrep, 2);
  rb_define_method (c_guestfs, "zegrepi",
                    guestfs_int_ruby_zegrepi, 2);
  rb_define_method (c_guestfs, "zero",
                    guestfs_int_ruby_zero, 1);
  rb_define_method (c_guestfs, "zero_device",
                    guestfs_int_ruby_zero_device, 1);
  rb_define_method (c_guestfs, "zero_free_space",
                    guestfs_int_ruby_zero_free_space, 1);
  rb_define_method (c_guestfs, "zerofree",
                    guestfs_int_ruby_zerofree, 1);
  rb_define_method (c_guestfs, "zfgrep",
                    guestfs_int_ruby_zfgrep, 2);
  rb_define_method (c_guestfs, "zfgrepi",
                    guestfs_int_ruby_zfgrepi, 2);
  rb_define_method (c_guestfs, "zfile",
                    guestfs_int_ruby_zfile, 2);
  rb_define_method (c_guestfs, "zgrep",
                    guestfs_int_ruby_zgrep, 2);
  rb_define_method (c_guestfs, "zgrepi",
                    guestfs_int_ruby_zgrepi, 2);
}
