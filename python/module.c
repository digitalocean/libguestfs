/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/python.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

/* This has to be included first, else definitions conflict with
 * glibc header files.  Python is broken.
 */
#define PY_SSIZE_T_CLEAN 1
#include <Python.h>

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "actions.h"

static PyMethodDef methods[] = {
  { (char *) "create", guestfs_int_py_create, METH_VARARGS, NULL },
  { (char *) "close", guestfs_int_py_close, METH_VARARGS, NULL },
  { (char *) "set_event_callback",
    guestfs_int_py_set_event_callback, METH_VARARGS, NULL },
  { (char *) "delete_event_callback",
    guestfs_int_py_delete_event_callback, METH_VARARGS, NULL },
  { (char *) "event_to_string",
    guestfs_int_py_event_to_string, METH_VARARGS, NULL },
#ifdef GUESTFS_HAVE_ACL_DELETE_DEF_FILE
  { (char *) "acl_delete_def_file", guestfs_int_py_acl_delete_def_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ACL_GET_FILE
  { (char *) "acl_get_file", guestfs_int_py_acl_get_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ACL_SET_FILE
  { (char *) "acl_set_file", guestfs_int_py_acl_set_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_CDROM
  { (char *) "add_cdrom", guestfs_int_py_add_cdrom, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DOMAIN
  { (char *) "add_domain", guestfs_int_py_add_domain, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_OPTS
  { (char *) "add_drive", guestfs_int_py_add_drive, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO
  { (char *) "add_drive_ro", guestfs_int_py_add_drive_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF
  { (char *) "add_drive_ro_with_if", guestfs_int_py_add_drive_ro_with_if, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_SCRATCH
  { (char *) "add_drive_scratch", guestfs_int_py_add_drive_scratch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_WITH_IF
  { (char *) "add_drive_with_if", guestfs_int_py_add_drive_with_if, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_LIBVIRT_DOM
  { (char *) "add_libvirt_dom", guestfs_int_py_add_libvirt_dom, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_CLEAR
  { (char *) "aug_clear", guestfs_int_py_aug_clear, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_CLOSE
  { (char *) "aug_close", guestfs_int_py_aug_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_DEFNODE
  { (char *) "aug_defnode", guestfs_int_py_aug_defnode, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_DEFVAR
  { (char *) "aug_defvar", guestfs_int_py_aug_defvar, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_GET
  { (char *) "aug_get", guestfs_int_py_aug_get, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_INIT
  { (char *) "aug_init", guestfs_int_py_aug_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_INSERT
  { (char *) "aug_insert", guestfs_int_py_aug_insert, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LABEL
  { (char *) "aug_label", guestfs_int_py_aug_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LOAD
  { (char *) "aug_load", guestfs_int_py_aug_load, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LS
  { (char *) "aug_ls", guestfs_int_py_aug_ls, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_MATCH
  { (char *) "aug_match", guestfs_int_py_aug_match, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_MV
  { (char *) "aug_mv", guestfs_int_py_aug_mv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_RM
  { (char *) "aug_rm", guestfs_int_py_aug_rm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SAVE
  { (char *) "aug_save", guestfs_int_py_aug_save, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SET
  { (char *) "aug_set", guestfs_int_py_aug_set, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SETM
  { (char *) "aug_setm", guestfs_int_py_aug_setm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AVAILABLE
  { (char *) "available", guestfs_int_py_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AVAILABLE_ALL_GROUPS
  { (char *) "available_all_groups", guestfs_int_py_available_all_groups, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BASE64_IN
  { (char *) "base64_in", guestfs_int_py_base64_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BASE64_OUT
  { (char *) "base64_out", guestfs_int_py_base64_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKDISCARD
  { (char *) "blkdiscard", guestfs_int_py_blkdiscard, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKDISCARDZEROES
  { (char *) "blkdiscardzeroes", guestfs_int_py_blkdiscardzeroes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKID
  { (char *) "blkid", guestfs_int_py_blkid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS
  { (char *) "blockdev_flushbufs", guestfs_int_py_blockdev_flushbufs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETBSZ
  { (char *) "blockdev_getbsz", guestfs_int_py_blockdev_getbsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETRO
  { (char *) "blockdev_getro", guestfs_int_py_blockdev_getro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSIZE64
  { (char *) "blockdev_getsize64", guestfs_int_py_blockdev_getsize64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSS
  { (char *) "blockdev_getss", guestfs_int_py_blockdev_getss, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSZ
  { (char *) "blockdev_getsz", guestfs_int_py_blockdev_getsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_REREADPT
  { (char *) "blockdev_rereadpt", guestfs_int_py_blockdev_rereadpt, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETBSZ
  { (char *) "blockdev_setbsz", guestfs_int_py_blockdev_setbsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRA
  { (char *) "blockdev_setra", guestfs_int_py_blockdev_setra, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRO
  { (char *) "blockdev_setro", guestfs_int_py_blockdev_setro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRW
  { (char *) "blockdev_setrw", guestfs_int_py_blockdev_setrw, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_CANCEL
  { (char *) "btrfs_balance_cancel", guestfs_int_py_btrfs_balance_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_PAUSE
  { (char *) "btrfs_balance_pause", guestfs_int_py_btrfs_balance_pause, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_RESUME
  { (char *) "btrfs_balance_resume", guestfs_int_py_btrfs_balance_resume, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_STATUS
  { (char *) "btrfs_balance_status", guestfs_int_py_btrfs_balance_status, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_ADD
  { (char *) "btrfs_device_add", guestfs_int_py_btrfs_device_add, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_DELETE
  { (char *) "btrfs_device_delete", guestfs_int_py_btrfs_device_delete, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE
  { (char *) "btrfs_filesystem_balance", guestfs_int_py_btrfs_filesystem_balance, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT
  { (char *) "btrfs_filesystem_defragment", guestfs_int_py_btrfs_filesystem_defragment, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE
  { (char *) "btrfs_filesystem_resize", guestfs_int_py_btrfs_filesystem_resize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SHOW
  { (char *) "btrfs_filesystem_show", guestfs_int_py_btrfs_filesystem_show, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC
  { (char *) "btrfs_filesystem_sync", guestfs_int_py_btrfs_filesystem_sync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FSCK
  { (char *) "btrfs_fsck", guestfs_int_py_btrfs_fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_IMAGE
  { (char *) "btrfs_image", guestfs_int_py_btrfs_image, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN
  { (char *) "btrfs_qgroup_assign", guestfs_int_py_btrfs_qgroup_assign, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_CREATE
  { (char *) "btrfs_qgroup_create", guestfs_int_py_btrfs_qgroup_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_DESTROY
  { (char *) "btrfs_qgroup_destroy", guestfs_int_py_btrfs_qgroup_destroy, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_LIMIT
  { (char *) "btrfs_qgroup_limit", guestfs_int_py_btrfs_qgroup_limit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_REMOVE
  { (char *) "btrfs_qgroup_remove", guestfs_int_py_btrfs_qgroup_remove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_SHOW
  { (char *) "btrfs_qgroup_show", guestfs_int_py_btrfs_qgroup_show, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_ENABLE
  { (char *) "btrfs_quota_enable", guestfs_int_py_btrfs_quota_enable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_RESCAN
  { (char *) "btrfs_quota_rescan", guestfs_int_py_btrfs_quota_rescan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_REPLACE
  { (char *) "btrfs_replace", guestfs_int_py_btrfs_replace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER
  { (char *) "btrfs_rescue_chunk_recover", guestfs_int_py_btrfs_rescue_chunk_recover, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER
  { (char *) "btrfs_rescue_super_recover", guestfs_int_py_btrfs_rescue_super_recover, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_CANCEL
  { (char *) "btrfs_scrub_cancel", guestfs_int_py_btrfs_scrub_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_RESUME
  { (char *) "btrfs_scrub_resume", guestfs_int_py_btrfs_scrub_resume, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_START
  { (char *) "btrfs_scrub_start", guestfs_int_py_btrfs_scrub_start, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_STATUS
  { (char *) "btrfs_scrub_status", guestfs_int_py_btrfs_scrub_status, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SET_SEEDING
  { (char *) "btrfs_set_seeding", guestfs_int_py_btrfs_set_seeding, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS
  { (char *) "btrfs_subvolume_create", guestfs_int_py_btrfs_subvolume_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE
  { (char *) "btrfs_subvolume_delete", guestfs_int_py_btrfs_subvolume_delete, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT
  { (char *) "btrfs_subvolume_get_default", guestfs_int_py_btrfs_subvolume_get_default, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST
  { (char *) "btrfs_subvolume_list", guestfs_int_py_btrfs_subvolume_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT
  { (char *) "btrfs_subvolume_set_default", guestfs_int_py_btrfs_subvolume_set_default, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW
  { (char *) "btrfs_subvolume_show", guestfs_int_py_btrfs_subvolume_show, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS
  { (char *) "btrfs_subvolume_snapshot", guestfs_int_py_btrfs_subvolume_snapshot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS
  { (char *) "btrfstune_enable_extended_inode_refs", guestfs_int_py_btrfstune_enable_extended_inode_refs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS
  { (char *) "btrfstune_enable_skinny_metadata_extent_refs", guestfs_int_py_btrfstune_enable_skinny_metadata_extent_refs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_SEEDING
  { (char *) "btrfstune_seeding", guestfs_int_py_btrfstune_seeding, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_C_POINTER
  { (char *) "c_pointer", guestfs_int_py_c_pointer, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CANONICAL_DEVICE_NAME
  { (char *) "canonical_device_name", guestfs_int_py_canonical_device_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAP_GET_FILE
  { (char *) "cap_get_file", guestfs_int_py_cap_get_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAP_SET_FILE
  { (char *) "cap_set_file", guestfs_int_py_cap_set_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CASE_SENSITIVE_PATH
  { (char *) "case_sensitive_path", guestfs_int_py_case_sensitive_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAT
  { (char *) "cat", guestfs_int_py_cat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUM
  { (char *) "checksum", guestfs_int_py_checksum, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUM_DEVICE
  { (char *) "checksum_device", guestfs_int_py_checksum_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUMS_OUT
  { (char *) "checksums_out", guestfs_int_py_checksums_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHMOD
  { (char *) "chmod", guestfs_int_py_chmod, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHOWN
  { (char *) "chown", guestfs_int_py_chown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CLEAR_BACKEND_SETTING
  { (char *) "clear_backend_setting", guestfs_int_py_clear_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMMAND
  { (char *) "command", guestfs_int_py_command, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMMAND_LINES
  { (char *) "command_lines", guestfs_int_py_command_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMPRESS_DEVICE_OUT
  { (char *) "compress_device_out", guestfs_int_py_compress_device_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMPRESS_OUT
  { (char *) "compress_out", guestfs_int_py_compress_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CONFIG
  { (char *) "config", guestfs_int_py_config, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_ATTRIBUTES
  { (char *) "copy_attributes", guestfs_int_py_copy_attributes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_DEVICE
  { (char *) "copy_device_to_device", guestfs_int_py_copy_device_to_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_FILE
  { (char *) "copy_device_to_file", guestfs_int_py_copy_device_to_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_DEVICE
  { (char *) "copy_file_to_device", guestfs_int_py_copy_file_to_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_FILE
  { (char *) "copy_file_to_file", guestfs_int_py_copy_file_to_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_IN
  { (char *) "copy_in", guestfs_int_py_copy_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_OUT
  { (char *) "copy_out", guestfs_int_py_copy_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_SIZE
  { (char *) "copy_size", guestfs_int_py_copy_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP
  { (char *) "cp", guestfs_int_py_cp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP_A
  { (char *) "cp_a", guestfs_int_py_cp_a, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP_R
  { (char *) "cp_r", guestfs_int_py_cp_r, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CPIO_OUT
  { (char *) "cpio_out", guestfs_int_py_cpio_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DD
  { (char *) "dd", guestfs_int_py_dd, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG
  { (char *) "debug", guestfs_int_py_debug, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG_DRIVES
  { (char *) "debug_drives", guestfs_int_py_debug_drives, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG_UPLOAD
  { (char *) "debug_upload", guestfs_int_py_debug_upload, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEVICE_INDEX
  { (char *) "device_index", guestfs_int_py_device_index, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DF
  { (char *) "df", guestfs_int_py_df, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DF_H
  { (char *) "df_h", guestfs_int_py_df_h, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_CREATE
  { (char *) "disk_create", guestfs_int_py_disk_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_FORMAT
  { (char *) "disk_format", guestfs_int_py_disk_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_HAS_BACKING_FILE
  { (char *) "disk_has_backing_file", guestfs_int_py_disk_has_backing_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_VIRTUAL_SIZE
  { (char *) "disk_virtual_size", guestfs_int_py_disk_virtual_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DMESG
  { (char *) "dmesg", guestfs_int_py_dmesg, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD
  { (char *) "download", guestfs_int_py_download, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_BLOCKS
  { (char *) "download_blocks", guestfs_int_py_download_blocks, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_INODE
  { (char *) "download_inode", guestfs_int_py_download_inode, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_OFFSET
  { (char *) "download_offset", guestfs_int_py_download_offset, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DROP_CACHES
  { (char *) "drop_caches", guestfs_int_py_drop_caches, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DU
  { (char *) "du", guestfs_int_py_du, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_E2FSCK
  { (char *) "e2fsck", guestfs_int_py_e2fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_E2FSCK_F
  { (char *) "e2fsck_f", guestfs_int_py_e2fsck_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ECHO_DAEMON
  { (char *) "echo_daemon", guestfs_int_py_echo_daemon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EGREP
  { (char *) "egrep", guestfs_int_py_egrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EGREPI
  { (char *) "egrepi", guestfs_int_py_egrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EQUAL
  { (char *) "equal", guestfs_int_py_equal, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EXISTS
  { (char *) "exists", guestfs_int_py_exists, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EXTLINUX
  { (char *) "extlinux", guestfs_int_py_extlinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FALLOCATE
  { (char *) "fallocate", guestfs_int_py_fallocate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FALLOCATE64
  { (char *) "fallocate64", guestfs_int_py_fallocate64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FEATURE_AVAILABLE
  { (char *) "feature_available", guestfs_int_py_feature_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FGREP
  { (char *) "fgrep", guestfs_int_py_fgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FGREPI
  { (char *) "fgrepi", guestfs_int_py_fgrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILE
  { (char *) "file", guestfs_int_py_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILE_ARCHITECTURE
  { (char *) "file_architecture", guestfs_int_py_file_architecture, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILESIZE
  { (char *) "filesize", guestfs_int_py_filesize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILESYSTEM_AVAILABLE
  { (char *) "filesystem_available", guestfs_int_py_filesystem_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILESYSTEM_WALK
  { (char *) "filesystem_walk", guestfs_int_py_filesystem_walk, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL
  { (char *) "fill", guestfs_int_py_fill, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL_DIR
  { (char *) "fill_dir", guestfs_int_py_fill_dir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL_PATTERN
  { (char *) "fill_pattern", guestfs_int_py_fill_pattern, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FIND
  { (char *) "find", guestfs_int_py_find, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FIND0
  { (char *) "find0", guestfs_int_py_find0, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FINDFS_LABEL
  { (char *) "findfs_label", guestfs_int_py_findfs_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FINDFS_UUID
  { (char *) "findfs_uuid", guestfs_int_py_findfs_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FSCK
  { (char *) "fsck", guestfs_int_py_fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FSTRIM
  { (char *) "fstrim", guestfs_int_py_fstrim, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_APPEND
  { (char *) "get_append", guestfs_int_py_get_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_ATTACH_METHOD
  { (char *) "get_attach_method", guestfs_int_py_get_attach_method, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_AUTOSYNC
  { (char *) "get_autosync", guestfs_int_py_get_autosync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND
  { (char *) "get_backend", guestfs_int_py_get_backend, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTING
  { (char *) "get_backend_setting", guestfs_int_py_get_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTINGS
  { (char *) "get_backend_settings", guestfs_int_py_get_backend_settings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_CACHEDIR
  { (char *) "get_cachedir", guestfs_int_py_get_cachedir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_DIRECT
  { (char *) "get_direct", guestfs_int_py_get_direct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2ATTRS
  { (char *) "get_e2attrs", guestfs_int_py_get_e2attrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2GENERATION
  { (char *) "get_e2generation", guestfs_int_py_get_e2generation, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2LABEL
  { (char *) "get_e2label", guestfs_int_py_get_e2label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2UUID
  { (char *) "get_e2uuid", guestfs_int_py_get_e2uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_HV
  { (char *) "get_hv", guestfs_int_py_get_hv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_IDENTIFIER
  { (char *) "get_identifier", guestfs_int_py_get_identifier, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE
  { (char *) "get_libvirt_requested_credential_challenge", guestfs_int_py_get_libvirt_requested_credential_challenge, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT
  { (char *) "get_libvirt_requested_credential_defresult", guestfs_int_py_get_libvirt_requested_credential_defresult, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT
  { (char *) "get_libvirt_requested_credential_prompt", guestfs_int_py_get_libvirt_requested_credential_prompt, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS
  { (char *) "get_libvirt_requested_credentials", guestfs_int_py_get_libvirt_requested_credentials, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_MEMSIZE
  { (char *) "get_memsize", guestfs_int_py_get_memsize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_NETWORK
  { (char *) "get_network", guestfs_int_py_get_network, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PATH
  { (char *) "get_path", guestfs_int_py_get_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PGROUP
  { (char *) "get_pgroup", guestfs_int_py_get_pgroup, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PID
  { (char *) "get_pid", guestfs_int_py_get_pid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PROGRAM
  { (char *) "get_program", guestfs_int_py_get_program, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_QEMU
  { (char *) "get_qemu", guestfs_int_py_get_qemu, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_RECOVERY_PROC
  { (char *) "get_recovery_proc", guestfs_int_py_get_recovery_proc, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_SELINUX
  { (char *) "get_selinux", guestfs_int_py_get_selinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_SMP
  { (char *) "get_smp", guestfs_int_py_get_smp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_SOCKDIR
  { (char *) "get_sockdir", guestfs_int_py_get_sockdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_STATE
  { (char *) "get_state", guestfs_int_py_get_state, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_TMPDIR
  { (char *) "get_tmpdir", guestfs_int_py_get_tmpdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_TRACE
  { (char *) "get_trace", guestfs_int_py_get_trace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_UMASK
  { (char *) "get_umask", guestfs_int_py_get_umask, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_VERBOSE
  { (char *) "get_verbose", guestfs_int_py_get_verbose, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETCON
  { (char *) "getcon", guestfs_int_py_getcon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETXATTR
  { (char *) "getxattr", guestfs_int_py_getxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETXATTRS
  { (char *) "getxattrs", guestfs_int_py_getxattrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GLOB_EXPAND_OPTS
  { (char *) "glob_expand", guestfs_int_py_glob_expand, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GREP_OPTS
  { (char *) "grep", guestfs_int_py_grep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GREPI
  { (char *) "grepi", guestfs_int_py_grepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GRUB_INSTALL
  { (char *) "grub_install", guestfs_int_py_grub_install, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEAD
  { (char *) "head", guestfs_int_py_head, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEAD_N
  { (char *) "head_n", guestfs_int_py_head_n, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEXDUMP
  { (char *) "hexdump", guestfs_int_py_hexdump, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_CLOSE
  { (char *) "hivex_close", guestfs_int_py_hivex_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_COMMIT
  { (char *) "hivex_commit", guestfs_int_py_hivex_commit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD
  { (char *) "hivex_node_add_child", guestfs_int_py_hivex_node_add_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_CHILDREN
  { (char *) "hivex_node_children", guestfs_int_py_hivex_node_children, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD
  { (char *) "hivex_node_delete_child", guestfs_int_py_hivex_node_delete_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_CHILD
  { (char *) "hivex_node_get_child", guestfs_int_py_hivex_node_get_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_VALUE
  { (char *) "hivex_node_get_value", guestfs_int_py_hivex_node_get_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_NAME
  { (char *) "hivex_node_name", guestfs_int_py_hivex_node_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_PARENT
  { (char *) "hivex_node_parent", guestfs_int_py_hivex_node_parent, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_SET_VALUE
  { (char *) "hivex_node_set_value", guestfs_int_py_hivex_node_set_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_VALUES
  { (char *) "hivex_node_values", guestfs_int_py_hivex_node_values, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_OPEN
  { (char *) "hivex_open", guestfs_int_py_hivex_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_ROOT
  { (char *) "hivex_root", guestfs_int_py_hivex_root, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_KEY
  { (char *) "hivex_value_key", guestfs_int_py_hivex_value_key, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_TYPE
  { (char *) "hivex_value_type", guestfs_int_py_hivex_value_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_UTF8
  { (char *) "hivex_value_utf8", guestfs_int_py_hivex_value_utf8, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_VALUE
  { (char *) "hivex_value_value", guestfs_int_py_hivex_value_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INITRD_CAT
  { (char *) "initrd_cat", guestfs_int_py_initrd_cat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INITRD_LIST
  { (char *) "initrd_list", guestfs_int_py_initrd_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_ADD_WATCH
  { (char *) "inotify_add_watch", guestfs_int_py_inotify_add_watch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_CLOSE
  { (char *) "inotify_close", guestfs_int_py_inotify_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_FILES
  { (char *) "inotify_files", guestfs_int_py_inotify_files, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_INIT
  { (char *) "inotify_init", guestfs_int_py_inotify_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_READ
  { (char *) "inotify_read", guestfs_int_py_inotify_read, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_RM_WATCH
  { (char *) "inotify_rm_watch", guestfs_int_py_inotify_rm_watch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ARCH
  { (char *) "inspect_get_arch", guestfs_int_py_inspect_get_arch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DISTRO
  { (char *) "inspect_get_distro", guestfs_int_py_inspect_get_distro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS
  { (char *) "inspect_get_drive_mappings", guestfs_int_py_inspect_get_drive_mappings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS
  { (char *) "inspect_get_filesystems", guestfs_int_py_inspect_get_filesystems, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FORMAT
  { (char *) "inspect_get_format", guestfs_int_py_inspect_get_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_HOSTNAME
  { (char *) "inspect_get_hostname", guestfs_int_py_inspect_get_hostname, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ICON
  { (char *) "inspect_get_icon", guestfs_int_py_inspect_get_icon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION
  { (char *) "inspect_get_major_version", guestfs_int_py_inspect_get_major_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION
  { (char *) "inspect_get_minor_version", guestfs_int_py_inspect_get_minor_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS
  { (char *) "inspect_get_mountpoints", guestfs_int_py_inspect_get_mountpoints, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT
  { (char *) "inspect_get_package_format", guestfs_int_py_inspect_get_package_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT
  { (char *) "inspect_get_package_management", guestfs_int_py_inspect_get_package_management, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME
  { (char *) "inspect_get_product_name", guestfs_int_py_inspect_get_product_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT
  { (char *) "inspect_get_product_variant", guestfs_int_py_inspect_get_product_variant, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ROOTS
  { (char *) "inspect_get_roots", guestfs_int_py_inspect_get_roots, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_TYPE
  { (char *) "inspect_get_type", guestfs_int_py_inspect_get_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET
  { (char *) "inspect_get_windows_current_control_set", guestfs_int_py_inspect_get_windows_current_control_set, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT
  { (char *) "inspect_get_windows_systemroot", guestfs_int_py_inspect_get_windows_systemroot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_LIVE
  { (char *) "inspect_is_live", guestfs_int_py_inspect_is_live, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_MULTIPART
  { (char *) "inspect_is_multipart", guestfs_int_py_inspect_is_multipart, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_NETINST
  { (char *) "inspect_is_netinst", guestfs_int_py_inspect_is_netinst, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS
  { (char *) "inspect_list_applications", guestfs_int_py_inspect_list_applications, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2
  { (char *) "inspect_list_applications2", guestfs_int_py_inspect_list_applications2, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_OS
  { (char *) "inspect_os", guestfs_int_py_inspect_os, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_EXIT
  { (char *) "internal_exit", guestfs_int_py_internal_exit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST
  { (char *) "internal_test", guestfs_int_py_internal_test, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_63_OPTARGS
  { (char *) "internal_test_63_optargs", guestfs_int_py_internal_test_63_optargs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT
  { (char *) "internal_test_close_output", guestfs_int_py_internal_test_close_output, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS
  { (char *) "internal_test_only_optargs", guestfs_int_py_internal_test_only_optargs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOL
  { (char *) "internal_test_rbool", guestfs_int_py_internal_test_rbool, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR
  { (char *) "internal_test_rboolerr", guestfs_int_py_internal_test_rboolerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT
  { (char *) "internal_test_rbufferout", guestfs_int_py_internal_test_rbufferout, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR
  { (char *) "internal_test_rbufferouterr", guestfs_int_py_internal_test_rbufferouterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING
  { (char *) "internal_test_rconstoptstring", guestfs_int_py_internal_test_rconstoptstring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR
  { (char *) "internal_test_rconstoptstringerr", guestfs_int_py_internal_test_rconstoptstringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRING
  { (char *) "internal_test_rconststring", guestfs_int_py_internal_test_rconststring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR
  { (char *) "internal_test_rconststringerr", guestfs_int_py_internal_test_rconststringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE
  { (char *) "internal_test_rhashtable", guestfs_int_py_internal_test_rhashtable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR
  { (char *) "internal_test_rhashtableerr", guestfs_int_py_internal_test_rhashtableerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT
  { (char *) "internal_test_rint", guestfs_int_py_internal_test_rint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64
  { (char *) "internal_test_rint64", guestfs_int_py_internal_test_rint64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64ERR
  { (char *) "internal_test_rint64err", guestfs_int_py_internal_test_rint64err, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINTERR
  { (char *) "internal_test_rinterr", guestfs_int_py_internal_test_rinterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRING
  { (char *) "internal_test_rstring", guestfs_int_py_internal_test_rstring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR
  { (char *) "internal_test_rstringerr", guestfs_int_py_internal_test_rstringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST
  { (char *) "internal_test_rstringlist", guestfs_int_py_internal_test_rstringlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR
  { (char *) "internal_test_rstringlisterr", guestfs_int_py_internal_test_rstringlisterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCT
  { (char *) "internal_test_rstruct", guestfs_int_py_internal_test_rstruct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR
  { (char *) "internal_test_rstructerr", guestfs_int_py_internal_test_rstructerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST
  { (char *) "internal_test_rstructlist", guestfs_int_py_internal_test_rstructlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR
  { (char *) "internal_test_rstructlisterr", guestfs_int_py_internal_test_rstructlisterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT
  { (char *) "internal_test_set_output", guestfs_int_py_internal_test_set_output, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_BLOCKDEV_OPTS
  { (char *) "is_blockdev", guestfs_int_py_is_blockdev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_BUSY
  { (char *) "is_busy", guestfs_int_py_is_busy, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_CHARDEV_OPTS
  { (char *) "is_chardev", guestfs_int_py_is_chardev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_CONFIG
  { (char *) "is_config", guestfs_int_py_is_config, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_DIR_OPTS
  { (char *) "is_dir", guestfs_int_py_is_dir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_FIFO_OPTS
  { (char *) "is_fifo", guestfs_int_py_is_fifo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_FILE_OPTS
  { (char *) "is_file", guestfs_int_py_is_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_LAUNCHING
  { (char *) "is_launching", guestfs_int_py_is_launching, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_LV
  { (char *) "is_lv", guestfs_int_py_is_lv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_READY
  { (char *) "is_ready", guestfs_int_py_is_ready, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_SOCKET_OPTS
  { (char *) "is_socket", guestfs_int_py_is_socket, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_SYMLINK
  { (char *) "is_symlink", guestfs_int_py_is_symlink, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_WHOLE_DEVICE
  { (char *) "is_whole_device", guestfs_int_py_is_whole_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_ZERO
  { (char *) "is_zero", guestfs_int_py_is_zero, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_ZERO_DEVICE
  { (char *) "is_zero_device", guestfs_int_py_is_zero_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ISOINFO
  { (char *) "isoinfo", guestfs_int_py_isoinfo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ISOINFO_DEVICE
  { (char *) "isoinfo_device", guestfs_int_py_isoinfo_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_CLOSE
  { (char *) "journal_close", guestfs_int_py_journal_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET
  { (char *) "journal_get", guestfs_int_py_journal_get, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD
  { (char *) "journal_get_data_threshold", guestfs_int_py_journal_get_data_threshold, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC
  { (char *) "journal_get_realtime_usec", guestfs_int_py_journal_get_realtime_usec, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_NEXT
  { (char *) "journal_next", guestfs_int_py_journal_next, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_OPEN
  { (char *) "journal_open", guestfs_int_py_journal_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD
  { (char *) "journal_set_data_threshold", guestfs_int_py_journal_set_data_threshold, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SKIP
  { (char *) "journal_skip", guestfs_int_py_journal_skip, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_KILL_SUBPROCESS
  { (char *) "kill_subprocess", guestfs_int_py_kill_subprocess, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LAUNCH
  { (char *) "launch", guestfs_int_py_launch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LCHOWN
  { (char *) "lchown", guestfs_int_py_lchown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_CREATE_ALL
  { (char *) "ldmtool_create_all", guestfs_int_py_ldmtool_create_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS
  { (char *) "ldmtool_diskgroup_disks", guestfs_int_py_ldmtool_diskgroup_disks, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME
  { (char *) "ldmtool_diskgroup_name", guestfs_int_py_ldmtool_diskgroup_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES
  { (char *) "ldmtool_diskgroup_volumes", guestfs_int_py_ldmtool_diskgroup_volumes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_REMOVE_ALL
  { (char *) "ldmtool_remove_all", guestfs_int_py_ldmtool_remove_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN
  { (char *) "ldmtool_scan", guestfs_int_py_ldmtool_scan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES
  { (char *) "ldmtool_scan_devices", guestfs_int_py_ldmtool_scan_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_HINT
  { (char *) "ldmtool_volume_hint", guestfs_int_py_ldmtool_volume_hint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS
  { (char *) "ldmtool_volume_partitions", guestfs_int_py_ldmtool_volume_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE
  { (char *) "ldmtool_volume_type", guestfs_int_py_ldmtool_volume_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LGETXATTR
  { (char *) "lgetxattr", guestfs_int_py_lgetxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LGETXATTRS
  { (char *) "lgetxattrs", guestfs_int_py_lgetxattrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_9P
  { (char *) "list_9p", guestfs_int_py_list_9p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DEVICES
  { (char *) "list_devices", guestfs_int_py_list_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DISK_LABELS
  { (char *) "list_disk_labels", guestfs_int_py_list_disk_labels, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DM_DEVICES
  { (char *) "list_dm_devices", guestfs_int_py_list_dm_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_FILESYSTEMS
  { (char *) "list_filesystems", guestfs_int_py_list_filesystems, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_PARTITIONS
  { (char *) "list_ldm_partitions", guestfs_int_py_list_ldm_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_VOLUMES
  { (char *) "list_ldm_volumes", guestfs_int_py_list_ldm_volumes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_MD_DEVICES
  { (char *) "list_md_devices", guestfs_int_py_list_md_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_PARTITIONS
  { (char *) "list_partitions", guestfs_int_py_list_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LL
  { (char *) "ll", guestfs_int_py_ll, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LLZ
  { (char *) "llz", guestfs_int_py_llz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN
  { (char *) "ln", guestfs_int_py_ln, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_F
  { (char *) "ln_f", guestfs_int_py_ln_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_S
  { (char *) "ln_s", guestfs_int_py_ln_s, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_SF
  { (char *) "ln_sf", guestfs_int_py_ln_sf, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LREMOVEXATTR
  { (char *) "lremovexattr", guestfs_int_py_lremovexattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LS
  { (char *) "ls", guestfs_int_py_ls, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LS0
  { (char *) "ls0", guestfs_int_py_ls0, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSETXATTR
  { (char *) "lsetxattr", guestfs_int_py_lsetxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTAT
  { (char *) "lstat", guestfs_int_py_lstat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATLIST
  { (char *) "lstatlist", guestfs_int_py_lstatlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATNS
  { (char *) "lstatns", guestfs_int_py_lstatns, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATNSLIST
  { (char *) "lstatnslist", guestfs_int_py_lstatnslist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_ADD_KEY
  { (char *) "luks_add_key", guestfs_int_py_luks_add_key, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_CLOSE
  { (char *) "luks_close", guestfs_int_py_luks_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT
  { (char *) "luks_format", guestfs_int_py_luks_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT_CIPHER
  { (char *) "luks_format_cipher", guestfs_int_py_luks_format_cipher, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_KILL_SLOT
  { (char *) "luks_kill_slot", guestfs_int_py_luks_kill_slot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN
  { (char *) "luks_open", guestfs_int_py_luks_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN_RO
  { (char *) "luks_open_ro", guestfs_int_py_luks_open_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVCREATE
  { (char *) "lvcreate", guestfs_int_py_lvcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVCREATE_FREE
  { (char *) "lvcreate_free", guestfs_int_py_lvcreate_free, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_CANONICAL_LV_NAME
  { (char *) "lvm_canonical_lv_name", guestfs_int_py_lvm_canonical_lv_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_CLEAR_FILTER
  { (char *) "lvm_clear_filter", guestfs_int_py_lvm_clear_filter, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_REMOVE_ALL
  { (char *) "lvm_remove_all", guestfs_int_py_lvm_remove_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_SET_FILTER
  { (char *) "lvm_set_filter", guestfs_int_py_lvm_set_filter, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVREMOVE
  { (char *) "lvremove", guestfs_int_py_lvremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRENAME
  { (char *) "lvrename", guestfs_int_py_lvrename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRESIZE
  { (char *) "lvresize", guestfs_int_py_lvresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRESIZE_FREE
  { (char *) "lvresize_free", guestfs_int_py_lvresize_free, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVS
  { (char *) "lvs", guestfs_int_py_lvs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVS_FULL
  { (char *) "lvs_full", guestfs_int_py_lvs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVUUID
  { (char *) "lvuuid", guestfs_int_py_lvuuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LXATTRLIST
  { (char *) "lxattrlist", guestfs_int_py_lxattrlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MAX_DISKS
  { (char *) "max_disks", guestfs_int_py_max_disks, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_CREATE
  { (char *) "md_create", guestfs_int_py_md_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_DETAIL
  { (char *) "md_detail", guestfs_int_py_md_detail, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_STAT
  { (char *) "md_stat", guestfs_int_py_md_stat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_STOP
  { (char *) "md_stop", guestfs_int_py_md_stop, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR
  { (char *) "mkdir", guestfs_int_py_mkdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR_MODE
  { (char *) "mkdir_mode", guestfs_int_py_mkdir_mode, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR_P
  { (char *) "mkdir_p", guestfs_int_py_mkdir_p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDTEMP
  { (char *) "mkdtemp", guestfs_int_py_mkdtemp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS
  { (char *) "mke2fs", guestfs_int_py_mke2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_J
  { (char *) "mke2fs_J", guestfs_int_py_mke2fs_J, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JL
  { (char *) "mke2fs_JL", guestfs_int_py_mke2fs_JL, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JU
  { (char *) "mke2fs_JU", guestfs_int_py_mke2fs_JU, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL
  { (char *) "mke2journal", guestfs_int_py_mke2journal, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_L
  { (char *) "mke2journal_L", guestfs_int_py_mke2journal_L, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_U
  { (char *) "mke2journal_U", guestfs_int_py_mke2journal_U, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFIFO
  { (char *) "mkfifo", guestfs_int_py_mkfifo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_OPTS
  { (char *) "mkfs", guestfs_int_py_mkfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_B
  { (char *) "mkfs_b", guestfs_int_py_mkfs_b, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_BTRFS
  { (char *) "mkfs_btrfs", guestfs_int_py_mkfs_btrfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKLOST_AND_FOUND
  { (char *) "mklost_and_found", guestfs_int_py_mklost_and_found, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKMOUNTPOINT
  { (char *) "mkmountpoint", guestfs_int_py_mkmountpoint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD
  { (char *) "mknod", guestfs_int_py_mknod, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD_B
  { (char *) "mknod_b", guestfs_int_py_mknod_b, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD_C
  { (char *) "mknod_c", guestfs_int_py_mknod_c, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_OPTS
  { (char *) "mkswap", guestfs_int_py_mkswap, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_L
  { (char *) "mkswap_L", guestfs_int_py_mkswap_L, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_U
  { (char *) "mkswap_U", guestfs_int_py_mkswap_U, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_FILE
  { (char *) "mkswap_file", guestfs_int_py_mkswap_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKTEMP
  { (char *) "mktemp", guestfs_int_py_mktemp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MODPROBE
  { (char *) "modprobe", guestfs_int_py_modprobe, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT
  { (char *) "mount", guestfs_int_py_mount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_9P
  { (char *) "mount_9p", guestfs_int_py_mount_9p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL
  { (char *) "mount_local", guestfs_int_py_mount_local, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL_RUN
  { (char *) "mount_local_run", guestfs_int_py_mount_local_run, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOOP
  { (char *) "mount_loop", guestfs_int_py_mount_loop, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_OPTIONS
  { (char *) "mount_options", guestfs_int_py_mount_options, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_RO
  { (char *) "mount_ro", guestfs_int_py_mount_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_VFS
  { (char *) "mount_vfs", guestfs_int_py_mount_vfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTABLE_DEVICE
  { (char *) "mountable_device", guestfs_int_py_mountable_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTABLE_SUBVOLUME
  { (char *) "mountable_subvolume", guestfs_int_py_mountable_subvolume, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTPOINTS
  { (char *) "mountpoints", guestfs_int_py_mountpoints, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTS
  { (char *) "mounts", guestfs_int_py_mounts, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MV
  { (char *) "mv", guestfs_int_py_mv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NR_DEVICES
  { (char *) "nr_devices", guestfs_int_py_nr_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFS_3G_PROBE
  { (char *) "ntfs_3g_probe", guestfs_int_py_ntfs_3g_probe, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSCAT_I
  { (char *) "ntfscat_i", guestfs_int_py_ntfscat_i, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_IN
  { (char *) "ntfsclone_in", guestfs_int_py_ntfsclone_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_OUT
  { (char *) "ntfsclone_out", guestfs_int_py_ntfsclone_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSFIX
  { (char *) "ntfsfix", guestfs_int_py_ntfsfix, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_OPTS
  { (char *) "ntfsresize", guestfs_int_py_ntfsresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_SIZE
  { (char *) "ntfsresize_size", guestfs_int_py_ntfsresize_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT
  { (char *) "parse_environment", guestfs_int_py_parse_environment, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST
  { (char *) "parse_environment_list", guestfs_int_py_parse_environment_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_ADD
  { (char *) "part_add", guestfs_int_py_part_add, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_DEL
  { (char *) "part_del", guestfs_int_py_part_del, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_DISK
  { (char *) "part_disk", guestfs_int_py_part_disk, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_EXPAND_GPT
  { (char *) "part_expand_gpt", guestfs_int_py_part_expand_gpt, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_BOOTABLE
  { (char *) "part_get_bootable", guestfs_int_py_part_get_bootable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_DISK_GUID
  { (char *) "part_get_disk_guid", guestfs_int_py_part_get_disk_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_GUID
  { (char *) "part_get_gpt_guid", guestfs_int_py_part_get_gpt_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_TYPE
  { (char *) "part_get_gpt_type", guestfs_int_py_part_get_gpt_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_ID
  { (char *) "part_get_mbr_id", guestfs_int_py_part_get_mbr_id, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_PART_TYPE
  { (char *) "part_get_mbr_part_type", guestfs_int_py_part_get_mbr_part_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_NAME
  { (char *) "part_get_name", guestfs_int_py_part_get_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_PARTTYPE
  { (char *) "part_get_parttype", guestfs_int_py_part_get_parttype, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_INIT
  { (char *) "part_init", guestfs_int_py_part_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_LIST
  { (char *) "part_list", guestfs_int_py_part_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_BOOTABLE
  { (char *) "part_set_bootable", guestfs_int_py_part_set_bootable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID
  { (char *) "part_set_disk_guid", guestfs_int_py_part_set_disk_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID_RANDOM
  { (char *) "part_set_disk_guid_random", guestfs_int_py_part_set_disk_guid_random, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_GUID
  { (char *) "part_set_gpt_guid", guestfs_int_py_part_set_gpt_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_TYPE
  { (char *) "part_set_gpt_type", guestfs_int_py_part_set_gpt_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_MBR_ID
  { (char *) "part_set_mbr_id", guestfs_int_py_part_set_mbr_id, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_NAME
  { (char *) "part_set_name", guestfs_int_py_part_set_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_TO_DEV
  { (char *) "part_to_dev", guestfs_int_py_part_to_dev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_TO_PARTNUM
  { (char *) "part_to_partnum", guestfs_int_py_part_to_partnum, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PING_DAEMON
  { (char *) "ping_daemon", guestfs_int_py_ping_daemon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PREAD
  { (char *) "pread", guestfs_int_py_pread, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PREAD_DEVICE
  { (char *) "pread_device", guestfs_int_py_pread_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID
  { (char *) "pvchange_uuid", guestfs_int_py_pvchange_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID_ALL
  { (char *) "pvchange_uuid_all", guestfs_int_py_pvchange_uuid_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCREATE
  { (char *) "pvcreate", guestfs_int_py_pvcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVREMOVE
  { (char *) "pvremove", guestfs_int_py_pvremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVRESIZE
  { (char *) "pvresize", guestfs_int_py_pvresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVRESIZE_SIZE
  { (char *) "pvresize_size", guestfs_int_py_pvresize_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVS
  { (char *) "pvs", guestfs_int_py_pvs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVS_FULL
  { (char *) "pvs_full", guestfs_int_py_pvs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVUUID
  { (char *) "pvuuid", guestfs_int_py_pvuuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PWRITE
  { (char *) "pwrite", guestfs_int_py_pwrite, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PWRITE_DEVICE
  { (char *) "pwrite_device", guestfs_int_py_pwrite_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READ_FILE
  { (char *) "read_file", guestfs_int_py_read_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READ_LINES
  { (char *) "read_lines", guestfs_int_py_read_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READDIR
  { (char *) "readdir", guestfs_int_py_readdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READLINK
  { (char *) "readlink", guestfs_int_py_readlink, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READLINKLIST
  { (char *) "readlinklist", guestfs_int_py_readlinklist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REALPATH
  { (char *) "realpath", guestfs_int_py_realpath, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOUNT
  { (char *) "remount", guestfs_int_py_remount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOVE_DRIVE
  { (char *) "remove_drive", guestfs_int_py_remove_drive, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOVEXATTR
  { (char *) "removexattr", guestfs_int_py_removexattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RENAME
  { (char *) "rename", guestfs_int_py_rename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS
  { (char *) "resize2fs", guestfs_int_py_resize2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_M
  { (char *) "resize2fs_M", guestfs_int_py_resize2fs_M, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_SIZE
  { (char *) "resize2fs_size", guestfs_int_py_resize2fs_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM
  { (char *) "rm", guestfs_int_py_rm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM_F
  { (char *) "rm_f", guestfs_int_py_rm_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM_RF
  { (char *) "rm_rf", guestfs_int_py_rm_rf, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RMDIR
  { (char *) "rmdir", guestfs_int_py_rmdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RMMOUNTPOINT
  { (char *) "rmmountpoint", guestfs_int_py_rmmountpoint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC
  { (char *) "rsync", guestfs_int_py_rsync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC_IN
  { (char *) "rsync_in", guestfs_int_py_rsync_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC_OUT
  { (char *) "rsync_out", guestfs_int_py_rsync_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_DEVICE
  { (char *) "scrub_device", guestfs_int_py_scrub_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_FILE
  { (char *) "scrub_file", guestfs_int_py_scrub_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_FREESPACE
  { (char *) "scrub_freespace", guestfs_int_py_scrub_freespace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SELINUX_RELABEL
  { (char *) "selinux_relabel", guestfs_int_py_selinux_relabel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_APPEND
  { (char *) "set_append", guestfs_int_py_set_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_ATTACH_METHOD
  { (char *) "set_attach_method", guestfs_int_py_set_attach_method, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_AUTOSYNC
  { (char *) "set_autosync", guestfs_int_py_set_autosync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND
  { (char *) "set_backend", guestfs_int_py_set_backend, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTING
  { (char *) "set_backend_setting", guestfs_int_py_set_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTINGS
  { (char *) "set_backend_settings", guestfs_int_py_set_backend_settings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_CACHEDIR
  { (char *) "set_cachedir", guestfs_int_py_set_cachedir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_DIRECT
  { (char *) "set_direct", guestfs_int_py_set_direct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2ATTRS
  { (char *) "set_e2attrs", guestfs_int_py_set_e2attrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2GENERATION
  { (char *) "set_e2generation", guestfs_int_py_set_e2generation, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2LABEL
  { (char *) "set_e2label", guestfs_int_py_set_e2label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2UUID
  { (char *) "set_e2uuid", guestfs_int_py_set_e2uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_HV
  { (char *) "set_hv", guestfs_int_py_set_hv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_IDENTIFIER
  { (char *) "set_identifier", guestfs_int_py_set_identifier, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LABEL
  { (char *) "set_label", guestfs_int_py_set_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL
  { (char *) "set_libvirt_requested_credential", guestfs_int_py_set_libvirt_requested_credential, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS
  { (char *) "set_libvirt_supported_credentials", guestfs_int_py_set_libvirt_supported_credentials, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_MEMSIZE
  { (char *) "set_memsize", guestfs_int_py_set_memsize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_NETWORK
  { (char *) "set_network", guestfs_int_py_set_network, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PATH
  { (char *) "set_path", guestfs_int_py_set_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PGROUP
  { (char *) "set_pgroup", guestfs_int_py_set_pgroup, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PROGRAM
  { (char *) "set_program", guestfs_int_py_set_program, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_QEMU
  { (char *) "set_qemu", guestfs_int_py_set_qemu, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_RECOVERY_PROC
  { (char *) "set_recovery_proc", guestfs_int_py_set_recovery_proc, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_SELINUX
  { (char *) "set_selinux", guestfs_int_py_set_selinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_SMP
  { (char *) "set_smp", guestfs_int_py_set_smp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_TMPDIR
  { (char *) "set_tmpdir", guestfs_int_py_set_tmpdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_TRACE
  { (char *) "set_trace", guestfs_int_py_set_trace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_UUID
  { (char *) "set_uuid", guestfs_int_py_set_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_UUID_RANDOM
  { (char *) "set_uuid_random", guestfs_int_py_set_uuid_random, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_VERBOSE
  { (char *) "set_verbose", guestfs_int_py_set_verbose, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SETCON
  { (char *) "setcon", guestfs_int_py_setcon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SETXATTR
  { (char *) "setxattr", guestfs_int_py_setxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK
  { (char *) "sfdisk", guestfs_int_py_sfdisk, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISKM
  { (char *) "sfdiskM", guestfs_int_py_sfdiskM, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_N
  { (char *) "sfdisk_N", guestfs_int_py_sfdisk_N, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_DISK_GEOMETRY
  { (char *) "sfdisk_disk_geometry", guestfs_int_py_sfdisk_disk_geometry, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY
  { (char *) "sfdisk_kernel_geometry", guestfs_int_py_sfdisk_kernel_geometry, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_L
  { (char *) "sfdisk_l", guestfs_int_py_sfdisk_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SH
  { (char *) "sh", guestfs_int_py_sh, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SH_LINES
  { (char *) "sh_lines", guestfs_int_py_sh_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SHUTDOWN
  { (char *) "shutdown", guestfs_int_py_shutdown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SLEEP
  { (char *) "sleep", guestfs_int_py_sleep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STAT
  { (char *) "stat", guestfs_int_py_stat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STATNS
  { (char *) "statns", guestfs_int_py_statns, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STATVFS
  { (char *) "statvfs", guestfs_int_py_statvfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STRINGS
  { (char *) "strings", guestfs_int_py_strings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STRINGS_E
  { (char *) "strings_e", guestfs_int_py_strings_e, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_DEVICE
  { (char *) "swapoff_device", guestfs_int_py_swapoff_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_FILE
  { (char *) "swapoff_file", guestfs_int_py_swapoff_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_LABEL
  { (char *) "swapoff_label", guestfs_int_py_swapoff_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_UUID
  { (char *) "swapoff_uuid", guestfs_int_py_swapoff_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_DEVICE
  { (char *) "swapon_device", guestfs_int_py_swapon_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_FILE
  { (char *) "swapon_file", guestfs_int_py_swapon_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_LABEL
  { (char *) "swapon_label", guestfs_int_py_swapon_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_UUID
  { (char *) "swapon_uuid", guestfs_int_py_swapon_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SYNC
  { (char *) "sync", guestfs_int_py_sync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SYSLINUX
  { (char *) "syslinux", guestfs_int_py_syslinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAIL
  { (char *) "tail", guestfs_int_py_tail, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAIL_N
  { (char *) "tail_n", guestfs_int_py_tail_n, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAR_IN_OPTS
  { (char *) "tar_in", guestfs_int_py_tar_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAR_OUT_OPTS
  { (char *) "tar_out", guestfs_int_py_tar_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TGZ_IN
  { (char *) "tgz_in", guestfs_int_py_tgz_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TGZ_OUT
  { (char *) "tgz_out", guestfs_int_py_tgz_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TOUCH
  { (char *) "touch", guestfs_int_py_touch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TRUNCATE
  { (char *) "truncate", guestfs_int_py_truncate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TRUNCATE_SIZE
  { (char *) "truncate_size", guestfs_int_py_truncate_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TUNE2FS
  { (char *) "tune2fs", guestfs_int_py_tune2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TUNE2FS_L
  { (char *) "tune2fs_l", guestfs_int_py_tune2fs_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TXZ_IN
  { (char *) "txz_in", guestfs_int_py_txz_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TXZ_OUT
  { (char *) "txz_out", guestfs_int_py_txz_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMASK
  { (char *) "umask", guestfs_int_py_umask, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_OPTS
  { (char *) "umount", guestfs_int_py_umount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_ALL
  { (char *) "umount_all", guestfs_int_py_umount_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_LOCAL
  { (char *) "umount_local", guestfs_int_py_umount_local, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UPLOAD
  { (char *) "upload", guestfs_int_py_upload, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UPLOAD_OFFSET
  { (char *) "upload_offset", guestfs_int_py_upload_offset, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_USER_CANCEL
  { (char *) "user_cancel", guestfs_int_py_user_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UTIMENS
  { (char *) "utimens", guestfs_int_py_utimens, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UTSNAME
  { (char *) "utsname", guestfs_int_py_utsname, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VERSION
  { (char *) "version", guestfs_int_py_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_LABEL
  { (char *) "vfs_label", guestfs_int_py_vfs_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_MINIMUM_SIZE
  { (char *) "vfs_minimum_size", guestfs_int_py_vfs_minimum_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_TYPE
  { (char *) "vfs_type", guestfs_int_py_vfs_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_UUID
  { (char *) "vfs_uuid", guestfs_int_py_vfs_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE
  { (char *) "vg_activate", guestfs_int_py_vg_activate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE_ALL
  { (char *) "vg_activate_all", guestfs_int_py_vg_activate_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID
  { (char *) "vgchange_uuid", guestfs_int_py_vgchange_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID_ALL
  { (char *) "vgchange_uuid_all", guestfs_int_py_vgchange_uuid_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCREATE
  { (char *) "vgcreate", guestfs_int_py_vgcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGLVUUIDS
  { (char *) "vglvuuids", guestfs_int_py_vglvuuids, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGMETA
  { (char *) "vgmeta", guestfs_int_py_vgmeta, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGPVUUIDS
  { (char *) "vgpvuuids", guestfs_int_py_vgpvuuids, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGREMOVE
  { (char *) "vgremove", guestfs_int_py_vgremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGRENAME
  { (char *) "vgrename", guestfs_int_py_vgrename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGS
  { (char *) "vgs", guestfs_int_py_vgs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGS_FULL
  { (char *) "vgs_full", guestfs_int_py_vgs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGSCAN
  { (char *) "vgscan", guestfs_int_py_vgscan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGUUID
  { (char *) "vguuid", guestfs_int_py_vguuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WAIT_READY
  { (char *) "wait_ready", guestfs_int_py_wait_ready, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_C
  { (char *) "wc_c", guestfs_int_py_wc_c, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_L
  { (char *) "wc_l", guestfs_int_py_wc_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_W
  { (char *) "wc_w", guestfs_int_py_wc_w, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WIPEFS
  { (char *) "wipefs", guestfs_int_py_wipefs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE
  { (char *) "write", guestfs_int_py_write, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE_APPEND
  { (char *) "write_append", guestfs_int_py_write_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE_FILE
  { (char *) "write_file", guestfs_int_py_write_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_ADMIN
  { (char *) "xfs_admin", guestfs_int_py_xfs_admin, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_GROWFS
  { (char *) "xfs_growfs", guestfs_int_py_xfs_growfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_INFO
  { (char *) "xfs_info", guestfs_int_py_xfs_info, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_REPAIR
  { (char *) "xfs_repair", guestfs_int_py_xfs_repair, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEGREP
  { (char *) "zegrep", guestfs_int_py_zegrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEGREPI
  { (char *) "zegrepi", guestfs_int_py_zegrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO
  { (char *) "zero", guestfs_int_py_zero, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO_DEVICE
  { (char *) "zero_device", guestfs_int_py_zero_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO_FREE_SPACE
  { (char *) "zero_free_space", guestfs_int_py_zero_free_space, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEROFREE
  { (char *) "zerofree", guestfs_int_py_zerofree, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFGREP
  { (char *) "zfgrep", guestfs_int_py_zfgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFGREPI
  { (char *) "zfgrepi", guestfs_int_py_zfgrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFILE
  { (char *) "zfile", guestfs_int_py_zfile, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZGREP
  { (char *) "zgrep", guestfs_int_py_zgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZGREPI
  { (char *) "zgrepi", guestfs_int_py_zgrepi, METH_VARARGS, NULL },
#endif
  { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "libguestfsmod",     /* m_name */
  "libguestfs module",   /* m_doc */
  -1,                    /* m_size */
  methods,               /* m_methods */
  NULL,                  /* m_reload */
  NULL,                  /* m_traverse */
  NULL,                  /* m_clear */
  NULL,                  /* m_free */
};
#endif

static PyObject *
moduleinit (void)
{
  PyObject *m;

#if PY_MAJOR_VERSION >= 3
  m = PyModule_Create (&moduledef);
#else
  m = Py_InitModule ((char *) "libguestfsmod", methods);
#endif

  if (m != NULL)
    guestfs_int_py_extend_module (m);

  return m; /* m might be NULL if module init failed */
}

#if PY_MAJOR_VERSION >= 3
extern PyMODINIT_FUNC PyInit_libguestfsmod (void);

PyMODINIT_FUNC
PyInit_libguestfsmod (void)
{
  return moduleinit ();
}
#else
extern void initlibguestfsmod (void);

void
initlibguestfsmod (void)
{
  (void) moduleinit ();
}
#endif
