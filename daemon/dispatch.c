/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
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
dispatch_incoming_message (XDR *xdr_in)
{
  switch (proc_nr) {
    case GUESTFS_PROC_ACL_DELETE_DEF_FILE:
      acl_delete_def_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_ACL_GET_FILE:
      acl_get_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_ACL_SET_FILE:
      acl_set_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_CLEAR:
      aug_clear_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_CLOSE:
      aug_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFNODE:
      aug_defnode_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFVAR:
      aug_defvar_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_GET:
      aug_get_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INIT:
      aug_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INSERT:
      aug_insert_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LABEL:
      aug_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LOAD:
      aug_load_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LS:
      aug_ls_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MATCH:
      aug_match_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MV:
      aug_mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_RM:
      aug_rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SAVE:
      aug_save_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SET:
      aug_set_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SETM:
      aug_setm_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_TRANSFORM:
      aug_transform_stub (xdr_in);
      break;
    case GUESTFS_PROC_AVAILABLE_ALL_GROUPS:
      available_all_groups_stub (xdr_in);
      break;
    case GUESTFS_PROC_BASE64_IN:
      base64_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_BASE64_OUT:
      base64_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKDISCARD:
      blkdiscard_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKDISCARDZEROES:
      blkdiscardzeroes_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKID:
      blkid_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_FLUSHBUFS:
      blockdev_flushbufs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETBSZ:
      blockdev_getbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETRO:
      blockdev_getro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSIZE64:
      blockdev_getsize64_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSS:
      blockdev_getss_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSZ:
      blockdev_getsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_REREADPT:
      blockdev_rereadpt_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETBSZ:
      blockdev_setbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRA:
      blockdev_setra_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRO:
      blockdev_setro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRW:
      blockdev_setrw_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_CANCEL:
      btrfs_balance_cancel_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_PAUSE:
      btrfs_balance_pause_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_RESUME:
      btrfs_balance_resume_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_STATUS:
      btrfs_balance_status_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_ADD:
      btrfs_device_add_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_DELETE:
      btrfs_device_delete_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE:
      btrfs_filesystem_balance_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_DEFRAGMENT:
      btrfs_filesystem_defragment_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE:
      btrfs_filesystem_resize_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_SHOW:
      btrfs_filesystem_show_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC:
      btrfs_filesystem_sync_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FSCK:
      btrfs_fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_IMAGE:
      btrfs_image_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_ASSIGN:
      btrfs_qgroup_assign_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_CREATE:
      btrfs_qgroup_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_DESTROY:
      btrfs_qgroup_destroy_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_LIMIT:
      btrfs_qgroup_limit_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_REMOVE:
      btrfs_qgroup_remove_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_SHOW:
      btrfs_qgroup_show_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QUOTA_ENABLE:
      btrfs_quota_enable_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QUOTA_RESCAN:
      btrfs_quota_rescan_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_REPLACE:
      btrfs_replace_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_RESCUE_CHUNK_RECOVER:
      btrfs_rescue_chunk_recover_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_RESCUE_SUPER_RECOVER:
      btrfs_rescue_super_recover_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_CANCEL:
      btrfs_scrub_cancel_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_RESUME:
      btrfs_scrub_resume_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_START:
      btrfs_scrub_start_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_STATUS:
      btrfs_scrub_status_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SET_SEEDING:
      btrfs_set_seeding_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE:
      btrfs_subvolume_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE:
      btrfs_subvolume_delete_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_GET_DEFAULT:
      btrfs_subvolume_get_default_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_LIST:
      btrfs_subvolume_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT:
      btrfs_subvolume_set_default_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SHOW:
      btrfs_subvolume_show_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT:
      btrfs_subvolume_snapshot_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS:
      btrfstune_enable_extended_inode_refs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS:
      btrfstune_enable_skinny_metadata_extent_refs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_SEEDING:
      btrfstune_seeding_stub (xdr_in);
      break;
    case GUESTFS_PROC_CAP_GET_FILE:
      cap_get_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_CAP_SET_FILE:
      cap_set_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_CASE_SENSITIVE_PATH:
      case_sensitive_path_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUM:
      checksum_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUM_DEVICE:
      checksum_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUMS_OUT:
      checksums_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHMOD:
      chmod_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHOWN:
      chown_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND:
      command_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND_LINES:
      command_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMPRESS_DEVICE_OUT:
      compress_device_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMPRESS_OUT:
      compress_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_ATTRIBUTES:
      copy_attributes_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_DEVICE:
      copy_device_to_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_FILE:
      copy_device_to_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_DEVICE:
      copy_file_to_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_FILE:
      copy_file_to_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_SIZE:
      copy_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP:
      cp_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP_A:
      cp_a_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP_R:
      cp_r_stub (xdr_in);
      break;
    case GUESTFS_PROC_CPIO_OUT:
      cpio_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_DD:
      dd_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEBUG:
      debug_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEBUG_UPLOAD:
      debug_upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEVICE_INDEX:
      device_index_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF:
      df_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF_H:
      df_h_stub (xdr_in);
      break;
    case GUESTFS_PROC_DMESG:
      dmesg_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD:
      download_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD_BLOCKS:
      download_blocks_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD_INODE:
      download_inode_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD_OFFSET:
      download_offset_stub (xdr_in);
      break;
    case GUESTFS_PROC_DROP_CACHES:
      drop_caches_stub (xdr_in);
      break;
    case GUESTFS_PROC_DU:
      du_stub (xdr_in);
      break;
    case GUESTFS_PROC_E2FSCK:
      e2fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_E2FSCK_F:
      e2fsck_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_ECHO_DAEMON:
      echo_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREP:
      egrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREPI:
      egrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_EQUAL:
      equal_stub (xdr_in);
      break;
    case GUESTFS_PROC_EXISTS:
      exists_stub (xdr_in);
      break;
    case GUESTFS_PROC_EXTLINUX:
      extlinux_stub (xdr_in);
      break;
    case GUESTFS_PROC_F2FS_EXPAND:
      f2fs_expand_stub (xdr_in);
      break;
    case GUESTFS_PROC_FALLOCATE:
      fallocate_stub (xdr_in);
      break;
    case GUESTFS_PROC_FALLOCATE64:
      fallocate64_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREP:
      fgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREPI:
      fgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILE:
      file_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILE_ARCHITECTURE:
      file_architecture_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILESIZE:
      filesize_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILESYSTEM_AVAILABLE:
      filesystem_available_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL:
      fill_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL_DIR:
      fill_dir_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL_PATTERN:
      fill_pattern_stub (xdr_in);
      break;
    case GUESTFS_PROC_FIND0:
      find0_stub (xdr_in);
      break;
    case GUESTFS_PROC_FINDFS_LABEL:
      findfs_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_FINDFS_UUID:
      findfs_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_FSCK:
      fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_FSTRIM:
      fstrim_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2ATTRS:
      get_e2attrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2GENERATION:
      get_e2generation_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2LABEL:
      get_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2UUID:
      get_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_UMASK:
      get_umask_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETCON:
      getcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETXATTR:
      getxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETXATTRS:
      getxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_GLOB_EXPAND:
      glob_expand_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREP:
      grep_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREPI:
      grepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_GRUB_INSTALL:
      grub_install_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD:
      head_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD_N:
      head_n_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEXDUMP:
      hexdump_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_CLOSE:
      hivex_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_COMMIT:
      hivex_commit_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_ADD_CHILD:
      hivex_node_add_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_CHILDREN:
      hivex_node_children_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD:
      hivex_node_delete_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_CHILD:
      hivex_node_get_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_VALUE:
      hivex_node_get_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_NAME:
      hivex_node_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_PARENT:
      hivex_node_parent_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_SET_VALUE:
      hivex_node_set_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_VALUES:
      hivex_node_values_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_OPEN:
      hivex_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_ROOT:
      hivex_root_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_KEY:
      hivex_value_key_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_STRING:
      hivex_value_string_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_TYPE:
      hivex_value_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_UTF8:
      hivex_value_utf8_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_VALUE:
      hivex_value_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_CAT:
      initrd_cat_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_LIST:
      initrd_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_ADD_WATCH:
      inotify_add_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_CLOSE:
      inotify_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_FILES:
      inotify_files_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_INIT:
      inotify_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_READ:
      inotify_read_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_RM_WATCH:
      inotify_rm_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_ARCH:
      inspect_get_arch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_DISTRO:
      inspect_get_distro_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_DRIVE_MAPPINGS:
      inspect_get_drive_mappings_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_FILESYSTEMS:
      inspect_get_filesystems_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_FORMAT:
      inspect_get_format_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_HOSTNAME:
      inspect_get_hostname_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_MAJOR_VERSION:
      inspect_get_major_version_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_MINOR_VERSION:
      inspect_get_minor_version_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_MOUNTPOINTS:
      inspect_get_mountpoints_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_PACKAGE_FORMAT:
      inspect_get_package_format_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_PACKAGE_MANAGEMENT:
      inspect_get_package_management_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_PRODUCT_NAME:
      inspect_get_product_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_PRODUCT_VARIANT:
      inspect_get_product_variant_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_ROOTS:
      inspect_get_roots_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_TYPE:
      inspect_get_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET:
      inspect_get_windows_current_control_set_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_WINDOWS_SOFTWARE_HIVE:
      inspect_get_windows_software_hive_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_WINDOWS_SYSTEM_HIVE:
      inspect_get_windows_system_hive_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_GET_WINDOWS_SYSTEMROOT:
      inspect_get_windows_systemroot_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_IS_LIVE:
      inspect_is_live_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_IS_MULTIPART:
      inspect_is_multipart_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_IS_NETINST:
      inspect_is_netinst_stub (xdr_in);
      break;
    case GUESTFS_PROC_INSPECT_OS:
      inspect_os_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_AUTOSYNC:
      internal_autosync_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_EXIT:
      internal_exit_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_FEATURE_AVAILABLE:
      internal_feature_available_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_FILESYSTEM_WALK:
      internal_filesystem_walk_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_FIND_INODE:
      internal_find_inode_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE:
      internal_hot_add_drive_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE:
      internal_hot_remove_drive_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK:
      internal_hot_remove_drive_precheck_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_JOURNAL_GET:
      internal_journal_get_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_LSTATNSLIST:
      internal_lstatnslist_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_LXATTRLIST:
      internal_lxattrlist_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE:
      internal_parse_mountable_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_READLINKLIST:
      internal_readlinklist_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_RHBZ914931:
      internal_rhbz914931_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_UPLOAD:
      internal_upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE:
      internal_write_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE_APPEND:
      internal_write_append_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_YARA_SCAN:
      internal_yara_scan_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_BLOCKDEV:
      is_blockdev_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_CHARDEV:
      is_chardev_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_DIR:
      is_dir_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_FIFO:
      is_fifo_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_FILE:
      is_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_LV:
      is_lv_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_SOCKET:
      is_socket_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_SYMLINK:
      is_symlink_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_WHOLE_DEVICE:
      is_whole_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_ZERO:
      is_zero_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_ZERO_DEVICE:
      is_zero_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_ISOINFO:
      isoinfo_stub (xdr_in);
      break;
    case GUESTFS_PROC_ISOINFO_DEVICE:
      isoinfo_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_CLOSE:
      journal_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_GET_DATA_THRESHOLD:
      journal_get_data_threshold_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC:
      journal_get_realtime_usec_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_NEXT:
      journal_next_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_OPEN:
      journal_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD:
      journal_set_data_threshold_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_SKIP:
      journal_skip_stub (xdr_in);
      break;
    case GUESTFS_PROC_LCHOWN:
      lchown_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_CREATE_ALL:
      ldmtool_create_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS:
      ldmtool_diskgroup_disks_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME:
      ldmtool_diskgroup_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES:
      ldmtool_diskgroup_volumes_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_REMOVE_ALL:
      ldmtool_remove_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN:
      ldmtool_scan_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN_DEVICES:
      ldmtool_scan_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_HINT:
      ldmtool_volume_hint_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS:
      ldmtool_volume_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_TYPE:
      ldmtool_volume_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_LGETXATTR:
      lgetxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LGETXATTRS:
      lgetxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_9P:
      list_9p_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DEVICES:
      list_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DISK_LABELS:
      list_disk_labels_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DM_DEVICES:
      list_dm_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_FILESYSTEMS:
      list_filesystems_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_LDM_PARTITIONS:
      list_ldm_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_LDM_VOLUMES:
      list_ldm_volumes_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_MD_DEVICES:
      list_md_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_PARTITIONS:
      list_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_LL:
      ll_stub (xdr_in);
      break;
    case GUESTFS_PROC_LLZ:
      llz_stub (xdr_in);
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
    case GUESTFS_PROC_LREMOVEXATTR:
      lremovexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LS0:
      ls0_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSETXATTR:
      lsetxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSTATNS:
      lstatns_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_ADD_KEY:
      luks_add_key_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_CLOSE:
      luks_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_FORMAT:
      luks_format_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_FORMAT_CIPHER:
      luks_format_cipher_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_KILL_SLOT:
      luks_kill_slot_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_OPEN:
      luks_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_OPEN_RO:
      luks_open_ro_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVCREATE:
      lvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVCREATE_FREE:
      lvcreate_free_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_CANONICAL_LV_NAME:
      lvm_canonical_lv_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_CLEAR_FILTER:
      lvm_clear_filter_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_REMOVE_ALL:
      lvm_remove_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_SCAN:
      lvm_scan_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_SET_FILTER:
      lvm_set_filter_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVREMOVE:
      lvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRENAME:
      lvrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRESIZE:
      lvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRESIZE_FREE:
      lvresize_free_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS:
      lvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS_FULL:
      lvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVUUID:
      lvuuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_CREATE:
      md_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_DETAIL:
      md_detail_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_STAT:
      md_stat_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_STOP:
      md_stop_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR:
      mkdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_MODE:
      mkdir_mode_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_P:
      mkdir_p_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDTEMP:
      mkdtemp_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS:
      mke2fs_stub (xdr_in);
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
    case GUESTFS_PROC_MKE2JOURNAL:
      mke2journal_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_L:
      mke2journal_L_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_U:
      mke2journal_U_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFIFO:
      mkfifo_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS:
      mkfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS_B:
      mkfs_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS_BTRFS:
      mkfs_btrfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKLOST_AND_FOUND:
      mklost_and_found_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKMOUNTPOINT:
      mkmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD:
      mknod_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_B:
      mknod_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_C:
      mknod_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSQUASHFS:
      mksquashfs_stub (xdr_in);
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
    case GUESTFS_PROC_MKSWAP_FILE:
      mkswap_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKTEMP:
      mktemp_stub (xdr_in);
      break;
    case GUESTFS_PROC_MODPROBE:
      modprobe_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT:
      mount_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_9P:
      mount_9p_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_LOOP:
      mount_loop_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_OPTIONS:
      mount_options_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_RO:
      mount_ro_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_VFS:
      mount_vfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTPOINTS:
      mountpoints_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTS:
      mounts_stub (xdr_in);
      break;
    case GUESTFS_PROC_MV:
      mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_NR_DEVICES:
      nr_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFS_3G_PROBE:
      ntfs_3g_probe_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSCAT_I:
      ntfscat_i_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSCLONE_IN:
      ntfsclone_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSCLONE_OUT:
      ntfsclone_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSFIX:
      ntfsfix_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSRESIZE:
      ntfsresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSRESIZE_SIZE:
      ntfsresize_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_ADD:
      part_add_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_DEL:
      part_del_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_DISK:
      part_disk_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_EXPAND_GPT:
      part_expand_gpt_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_BOOTABLE:
      part_get_bootable_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_DISK_GUID:
      part_get_disk_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_GPT_ATTRIBUTES:
      part_get_gpt_attributes_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_GPT_GUID:
      part_get_gpt_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_GPT_TYPE:
      part_get_gpt_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_MBR_ID:
      part_get_mbr_id_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_MBR_PART_TYPE:
      part_get_mbr_part_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_NAME:
      part_get_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_PARTTYPE:
      part_get_parttype_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_INIT:
      part_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_LIST:
      part_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_RESIZE:
      part_resize_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_BOOTABLE:
      part_set_bootable_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_DISK_GUID:
      part_set_disk_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_DISK_GUID_RANDOM:
      part_set_disk_guid_random_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_GPT_ATTRIBUTES:
      part_set_gpt_attributes_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_GPT_GUID:
      part_set_gpt_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_GPT_TYPE:
      part_set_gpt_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_MBR_ID:
      part_set_mbr_id_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_NAME:
      part_set_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_TO_DEV:
      part_to_dev_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_TO_PARTNUM:
      part_to_partnum_stub (xdr_in);
      break;
    case GUESTFS_PROC_PING_DAEMON:
      ping_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_PREAD:
      pread_stub (xdr_in);
      break;
    case GUESTFS_PROC_PREAD_DEVICE:
      pread_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID:
      pvchange_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID_ALL:
      pvchange_uuid_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCREATE:
      pvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVREMOVE:
      pvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVRESIZE:
      pvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVRESIZE_SIZE:
      pvresize_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS:
      pvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS_FULL:
      pvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVUUID:
      pvuuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PWRITE:
      pwrite_stub (xdr_in);
      break;
    case GUESTFS_PROC_PWRITE_DEVICE:
      pwrite_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_READDIR:
      readdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_READLINK:
      readlink_stub (xdr_in);
      break;
    case GUESTFS_PROC_REALPATH:
      realpath_stub (xdr_in);
      break;
    case GUESTFS_PROC_REMOUNT:
      remount_stub (xdr_in);
      break;
    case GUESTFS_PROC_REMOVEXATTR:
      removexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_RENAME:
      rename_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS:
      resize2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS_M:
      resize2fs_M_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS_SIZE:
      resize2fs_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM:
      rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM_F:
      rm_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM_RF:
      rm_rf_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMDIR:
      rmdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMMOUNTPOINT:
      rmmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC:
      rsync_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC_IN:
      rsync_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC_OUT:
      rsync_out_stub (xdr_in);
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
    case GUESTFS_PROC_SELINUX_RELABEL:
      selinux_relabel_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2ATTRS:
      set_e2attrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2GENERATION:
      set_e2generation_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2LABEL:
      set_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2UUID:
      set_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_LABEL:
      set_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_UUID:
      set_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_UUID_RANDOM:
      set_uuid_random_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETCON:
      setcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETXATTR:
      setxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK:
      sfdisk_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISKM:
      sfdiskM_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_N:
      sfdisk_N_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_DISK_GEOMETRY:
      sfdisk_disk_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY:
      sfdisk_kernel_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_L:
      sfdisk_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH:
      sh_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH_LINES:
      sh_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_SLEEP:
      sleep_stub (xdr_in);
      break;
    case GUESTFS_PROC_STATNS:
      statns_stub (xdr_in);
      break;
    case GUESTFS_PROC_STATVFS:
      statvfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS:
      strings_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS_E:
      strings_e_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_DEVICE:
      swapoff_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_FILE:
      swapoff_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_LABEL:
      swapoff_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_UUID:
      swapoff_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_DEVICE:
      swapon_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_FILE:
      swapon_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_LABEL:
      swapon_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_UUID:
      swapon_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SYNC:
      sync_stub (xdr_in);
      break;
    case GUESTFS_PROC_SYSLINUX:
      syslinux_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL:
      tail_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL_N:
      tail_n_stub (xdr_in);
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
    case GUESTFS_PROC_TOUCH:
      touch_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE:
      truncate_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE_SIZE:
      truncate_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_TUNE2FS:
      tune2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_TUNE2FS_L:
      tune2fs_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_TXZ_IN:
      txz_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TXZ_OUT:
      txz_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMASK:
      umask_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT:
      umount_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT_ALL:
      umount_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_UPLOAD:
      upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_UPLOAD_OFFSET:
      upload_offset_stub (xdr_in);
      break;
    case GUESTFS_PROC_UTIMENS:
      utimens_stub (xdr_in);
      break;
    case GUESTFS_PROC_UTSNAME:
      utsname_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_LABEL:
      vfs_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_MINIMUM_SIZE:
      vfs_minimum_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_TYPE:
      vfs_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_UUID:
      vfs_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE:
      vg_activate_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE_ALL:
      vg_activate_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID:
      vgchange_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID_ALL:
      vgchange_uuid_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCREATE:
      vgcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGLVUUIDS:
      vglvuuids_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGMETA:
      vgmeta_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGPVUUIDS:
      vgpvuuids_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGREMOVE:
      vgremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGRENAME:
      vgrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS:
      vgs_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS_FULL:
      vgs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGSCAN:
      vgscan_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGUUID:
      vguuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_C:
      wc_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_L:
      wc_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_W:
      wc_w_stub (xdr_in);
      break;
    case GUESTFS_PROC_WIPEFS:
      wipefs_stub (xdr_in);
      break;
    case GUESTFS_PROC_WRITE_FILE:
      write_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_ADMIN:
      xfs_admin_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_GROWFS:
      xfs_growfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_INFO:
      xfs_info_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_REPAIR:
      xfs_repair_stub (xdr_in);
      break;
    case GUESTFS_PROC_YARA_DESTROY:
      yara_destroy_stub (xdr_in);
      break;
    case GUESTFS_PROC_YARA_LOAD:
      yara_load_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREP:
      zegrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREPI:
      zegrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO:
      zero_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO_DEVICE:
      zero_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO_FREE_SPACE:
      zero_free_space_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEROFREE:
      zerofree_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREP:
      zfgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREPI:
      zfgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFILE:
      zfile_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREP:
      zgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREPI:
      zgrepi_stub (xdr_in);
      break;
    default:
      reply_with_error ("dispatch_incoming_message: unknown procedure number %d, set LIBGUESTFS_PATH to point to the matching libguestfs appliance directory", proc_nr);
  }
}

