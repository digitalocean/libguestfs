/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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
dispatch (ETERM *message)
{
  ETERM *fun;

  fun = ERL_TUPLE_ELEMENT (message, 0);

  /* XXX We should use gperf here. */
  if (atom_equals (fun, "acl_delete_def_file"))
    return run_acl_delete_def_file (message);
  else if (atom_equals (fun, "acl_get_file"))
    return run_acl_get_file (message);
  else if (atom_equals (fun, "acl_set_file"))
    return run_acl_set_file (message);
  else if (atom_equals (fun, "add_cdrom"))
    return run_add_cdrom (message);
  else if (atom_equals (fun, "add_domain"))
    return run_add_domain (message);
  else if (atom_equals (fun, "add_drive"))
    return run_add_drive (message);
  else if (atom_equals (fun, "add_drive_ro"))
    return run_add_drive_ro (message);
  else if (atom_equals (fun, "add_drive_ro_with_if"))
    return run_add_drive_ro_with_if (message);
  else if (atom_equals (fun, "add_drive_scratch"))
    return run_add_drive_scratch (message);
  else if (atom_equals (fun, "add_drive_with_if"))
    return run_add_drive_with_if (message);
  else if (atom_equals (fun, "add_libvirt_dom"))
    return run_add_libvirt_dom (message);
  else if (atom_equals (fun, "aug_clear"))
    return run_aug_clear (message);
  else if (atom_equals (fun, "aug_close"))
    return run_aug_close (message);
  else if (atom_equals (fun, "aug_defnode"))
    return run_aug_defnode (message);
  else if (atom_equals (fun, "aug_defvar"))
    return run_aug_defvar (message);
  else if (atom_equals (fun, "aug_get"))
    return run_aug_get (message);
  else if (atom_equals (fun, "aug_init"))
    return run_aug_init (message);
  else if (atom_equals (fun, "aug_insert"))
    return run_aug_insert (message);
  else if (atom_equals (fun, "aug_label"))
    return run_aug_label (message);
  else if (atom_equals (fun, "aug_load"))
    return run_aug_load (message);
  else if (atom_equals (fun, "aug_ls"))
    return run_aug_ls (message);
  else if (atom_equals (fun, "aug_match"))
    return run_aug_match (message);
  else if (atom_equals (fun, "aug_mv"))
    return run_aug_mv (message);
  else if (atom_equals (fun, "aug_rm"))
    return run_aug_rm (message);
  else if (atom_equals (fun, "aug_save"))
    return run_aug_save (message);
  else if (atom_equals (fun, "aug_set"))
    return run_aug_set (message);
  else if (atom_equals (fun, "aug_setm"))
    return run_aug_setm (message);
  else if (atom_equals (fun, "aug_transform"))
    return run_aug_transform (message);
  else if (atom_equals (fun, "available"))
    return run_available (message);
  else if (atom_equals (fun, "available_all_groups"))
    return run_available_all_groups (message);
  else if (atom_equals (fun, "base64_in"))
    return run_base64_in (message);
  else if (atom_equals (fun, "base64_out"))
    return run_base64_out (message);
  else if (atom_equals (fun, "blkdiscard"))
    return run_blkdiscard (message);
  else if (atom_equals (fun, "blkdiscardzeroes"))
    return run_blkdiscardzeroes (message);
  else if (atom_equals (fun, "blkid"))
    return run_blkid (message);
  else if (atom_equals (fun, "blockdev_flushbufs"))
    return run_blockdev_flushbufs (message);
  else if (atom_equals (fun, "blockdev_getbsz"))
    return run_blockdev_getbsz (message);
  else if (atom_equals (fun, "blockdev_getro"))
    return run_blockdev_getro (message);
  else if (atom_equals (fun, "blockdev_getsize64"))
    return run_blockdev_getsize64 (message);
  else if (atom_equals (fun, "blockdev_getss"))
    return run_blockdev_getss (message);
  else if (atom_equals (fun, "blockdev_getsz"))
    return run_blockdev_getsz (message);
  else if (atom_equals (fun, "blockdev_rereadpt"))
    return run_blockdev_rereadpt (message);
  else if (atom_equals (fun, "blockdev_setbsz"))
    return run_blockdev_setbsz (message);
  else if (atom_equals (fun, "blockdev_setra"))
    return run_blockdev_setra (message);
  else if (atom_equals (fun, "blockdev_setro"))
    return run_blockdev_setro (message);
  else if (atom_equals (fun, "blockdev_setrw"))
    return run_blockdev_setrw (message);
  else if (atom_equals (fun, "btrfs_balance_cancel"))
    return run_btrfs_balance_cancel (message);
  else if (atom_equals (fun, "btrfs_balance_pause"))
    return run_btrfs_balance_pause (message);
  else if (atom_equals (fun, "btrfs_balance_resume"))
    return run_btrfs_balance_resume (message);
  else if (atom_equals (fun, "btrfs_balance_status"))
    return run_btrfs_balance_status (message);
  else if (atom_equals (fun, "btrfs_device_add"))
    return run_btrfs_device_add (message);
  else if (atom_equals (fun, "btrfs_device_delete"))
    return run_btrfs_device_delete (message);
  else if (atom_equals (fun, "btrfs_filesystem_balance"))
    return run_btrfs_filesystem_balance (message);
  else if (atom_equals (fun, "btrfs_filesystem_defragment"))
    return run_btrfs_filesystem_defragment (message);
  else if (atom_equals (fun, "btrfs_filesystem_resize"))
    return run_btrfs_filesystem_resize (message);
  else if (atom_equals (fun, "btrfs_filesystem_show"))
    return run_btrfs_filesystem_show (message);
  else if (atom_equals (fun, "btrfs_filesystem_sync"))
    return run_btrfs_filesystem_sync (message);
  else if (atom_equals (fun, "btrfs_fsck"))
    return run_btrfs_fsck (message);
  else if (atom_equals (fun, "btrfs_image"))
    return run_btrfs_image (message);
  else if (atom_equals (fun, "btrfs_qgroup_assign"))
    return run_btrfs_qgroup_assign (message);
  else if (atom_equals (fun, "btrfs_qgroup_create"))
    return run_btrfs_qgroup_create (message);
  else if (atom_equals (fun, "btrfs_qgroup_destroy"))
    return run_btrfs_qgroup_destroy (message);
  else if (atom_equals (fun, "btrfs_qgroup_limit"))
    return run_btrfs_qgroup_limit (message);
  else if (atom_equals (fun, "btrfs_qgroup_remove"))
    return run_btrfs_qgroup_remove (message);
  else if (atom_equals (fun, "btrfs_qgroup_show"))
    return run_btrfs_qgroup_show (message);
  else if (atom_equals (fun, "btrfs_quota_enable"))
    return run_btrfs_quota_enable (message);
  else if (atom_equals (fun, "btrfs_quota_rescan"))
    return run_btrfs_quota_rescan (message);
  else if (atom_equals (fun, "btrfs_replace"))
    return run_btrfs_replace (message);
  else if (atom_equals (fun, "btrfs_rescue_chunk_recover"))
    return run_btrfs_rescue_chunk_recover (message);
  else if (atom_equals (fun, "btrfs_rescue_super_recover"))
    return run_btrfs_rescue_super_recover (message);
  else if (atom_equals (fun, "btrfs_scrub_cancel"))
    return run_btrfs_scrub_cancel (message);
  else if (atom_equals (fun, "btrfs_scrub_resume"))
    return run_btrfs_scrub_resume (message);
  else if (atom_equals (fun, "btrfs_scrub_start"))
    return run_btrfs_scrub_start (message);
  else if (atom_equals (fun, "btrfs_scrub_status"))
    return run_btrfs_scrub_status (message);
  else if (atom_equals (fun, "btrfs_set_seeding"))
    return run_btrfs_set_seeding (message);
  else if (atom_equals (fun, "btrfs_subvolume_create"))
    return run_btrfs_subvolume_create (message);
  else if (atom_equals (fun, "btrfs_subvolume_delete"))
    return run_btrfs_subvolume_delete (message);
  else if (atom_equals (fun, "btrfs_subvolume_get_default"))
    return run_btrfs_subvolume_get_default (message);
  else if (atom_equals (fun, "btrfs_subvolume_list"))
    return run_btrfs_subvolume_list (message);
  else if (atom_equals (fun, "btrfs_subvolume_set_default"))
    return run_btrfs_subvolume_set_default (message);
  else if (atom_equals (fun, "btrfs_subvolume_show"))
    return run_btrfs_subvolume_show (message);
  else if (atom_equals (fun, "btrfs_subvolume_snapshot"))
    return run_btrfs_subvolume_snapshot (message);
  else if (atom_equals (fun, "btrfstune_enable_extended_inode_refs"))
    return run_btrfstune_enable_extended_inode_refs (message);
  else if (atom_equals (fun, "btrfstune_enable_skinny_metadata_extent_refs"))
    return run_btrfstune_enable_skinny_metadata_extent_refs (message);
  else if (atom_equals (fun, "btrfstune_seeding"))
    return run_btrfstune_seeding (message);
  else if (atom_equals (fun, "c_pointer"))
    return run_c_pointer (message);
  else if (atom_equals (fun, "canonical_device_name"))
    return run_canonical_device_name (message);
  else if (atom_equals (fun, "cap_get_file"))
    return run_cap_get_file (message);
  else if (atom_equals (fun, "cap_set_file"))
    return run_cap_set_file (message);
  else if (atom_equals (fun, "case_sensitive_path"))
    return run_case_sensitive_path (message);
  else if (atom_equals (fun, "cat"))
    return run_cat (message);
  else if (atom_equals (fun, "checksum"))
    return run_checksum (message);
  else if (atom_equals (fun, "checksum_device"))
    return run_checksum_device (message);
  else if (atom_equals (fun, "checksums_out"))
    return run_checksums_out (message);
  else if (atom_equals (fun, "chmod"))
    return run_chmod (message);
  else if (atom_equals (fun, "chown"))
    return run_chown (message);
  else if (atom_equals (fun, "clear_backend_setting"))
    return run_clear_backend_setting (message);
  else if (atom_equals (fun, "command"))
    return run_command (message);
  else if (atom_equals (fun, "command_lines"))
    return run_command_lines (message);
  else if (atom_equals (fun, "compress_device_out"))
    return run_compress_device_out (message);
  else if (atom_equals (fun, "compress_out"))
    return run_compress_out (message);
  else if (atom_equals (fun, "config"))
    return run_config (message);
  else if (atom_equals (fun, "copy_attributes"))
    return run_copy_attributes (message);
  else if (atom_equals (fun, "copy_device_to_device"))
    return run_copy_device_to_device (message);
  else if (atom_equals (fun, "copy_device_to_file"))
    return run_copy_device_to_file (message);
  else if (atom_equals (fun, "copy_file_to_device"))
    return run_copy_file_to_device (message);
  else if (atom_equals (fun, "copy_file_to_file"))
    return run_copy_file_to_file (message);
  else if (atom_equals (fun, "copy_in"))
    return run_copy_in (message);
  else if (atom_equals (fun, "copy_out"))
    return run_copy_out (message);
  else if (atom_equals (fun, "copy_size"))
    return run_copy_size (message);
  else if (atom_equals (fun, "cp"))
    return run_cp (message);
  else if (atom_equals (fun, "cp_a"))
    return run_cp_a (message);
  else if (atom_equals (fun, "cp_r"))
    return run_cp_r (message);
  else if (atom_equals (fun, "cpio_out"))
    return run_cpio_out (message);
  else if (atom_equals (fun, "dd"))
    return run_dd (message);
  else if (atom_equals (fun, "debug"))
    return run_debug (message);
  else if (atom_equals (fun, "debug_drives"))
    return run_debug_drives (message);
  else if (atom_equals (fun, "debug_upload"))
    return run_debug_upload (message);
  else if (atom_equals (fun, "device_index"))
    return run_device_index (message);
  else if (atom_equals (fun, "df"))
    return run_df (message);
  else if (atom_equals (fun, "df_h"))
    return run_df_h (message);
  else if (atom_equals (fun, "disk_create"))
    return run_disk_create (message);
  else if (atom_equals (fun, "disk_format"))
    return run_disk_format (message);
  else if (atom_equals (fun, "disk_has_backing_file"))
    return run_disk_has_backing_file (message);
  else if (atom_equals (fun, "disk_virtual_size"))
    return run_disk_virtual_size (message);
  else if (atom_equals (fun, "dmesg"))
    return run_dmesg (message);
  else if (atom_equals (fun, "download"))
    return run_download (message);
  else if (atom_equals (fun, "download_blocks"))
    return run_download_blocks (message);
  else if (atom_equals (fun, "download_inode"))
    return run_download_inode (message);
  else if (atom_equals (fun, "download_offset"))
    return run_download_offset (message);
  else if (atom_equals (fun, "drop_caches"))
    return run_drop_caches (message);
  else if (atom_equals (fun, "du"))
    return run_du (message);
  else if (atom_equals (fun, "e2fsck"))
    return run_e2fsck (message);
  else if (atom_equals (fun, "e2fsck_f"))
    return run_e2fsck_f (message);
  else if (atom_equals (fun, "echo_daemon"))
    return run_echo_daemon (message);
  else if (atom_equals (fun, "egrep"))
    return run_egrep (message);
  else if (atom_equals (fun, "egrepi"))
    return run_egrepi (message);
  else if (atom_equals (fun, "equal"))
    return run_equal (message);
  else if (atom_equals (fun, "exists"))
    return run_exists (message);
  else if (atom_equals (fun, "extlinux"))
    return run_extlinux (message);
  else if (atom_equals (fun, "fallocate"))
    return run_fallocate (message);
  else if (atom_equals (fun, "fallocate64"))
    return run_fallocate64 (message);
  else if (atom_equals (fun, "feature_available"))
    return run_feature_available (message);
  else if (atom_equals (fun, "fgrep"))
    return run_fgrep (message);
  else if (atom_equals (fun, "fgrepi"))
    return run_fgrepi (message);
  else if (atom_equals (fun, "file"))
    return run_file (message);
  else if (atom_equals (fun, "file_architecture"))
    return run_file_architecture (message);
  else if (atom_equals (fun, "filesize"))
    return run_filesize (message);
  else if (atom_equals (fun, "filesystem_available"))
    return run_filesystem_available (message);
  else if (atom_equals (fun, "filesystem_walk"))
    return run_filesystem_walk (message);
  else if (atom_equals (fun, "fill"))
    return run_fill (message);
  else if (atom_equals (fun, "fill_dir"))
    return run_fill_dir (message);
  else if (atom_equals (fun, "fill_pattern"))
    return run_fill_pattern (message);
  else if (atom_equals (fun, "find"))
    return run_find (message);
  else if (atom_equals (fun, "find0"))
    return run_find0 (message);
  else if (atom_equals (fun, "find_inode"))
    return run_find_inode (message);
  else if (atom_equals (fun, "findfs_label"))
    return run_findfs_label (message);
  else if (atom_equals (fun, "findfs_uuid"))
    return run_findfs_uuid (message);
  else if (atom_equals (fun, "fsck"))
    return run_fsck (message);
  else if (atom_equals (fun, "fstrim"))
    return run_fstrim (message);
  else if (atom_equals (fun, "get_append"))
    return run_get_append (message);
  else if (atom_equals (fun, "get_attach_method"))
    return run_get_attach_method (message);
  else if (atom_equals (fun, "get_autosync"))
    return run_get_autosync (message);
  else if (atom_equals (fun, "get_backend"))
    return run_get_backend (message);
  else if (atom_equals (fun, "get_backend_setting"))
    return run_get_backend_setting (message);
  else if (atom_equals (fun, "get_backend_settings"))
    return run_get_backend_settings (message);
  else if (atom_equals (fun, "get_cachedir"))
    return run_get_cachedir (message);
  else if (atom_equals (fun, "get_direct"))
    return run_get_direct (message);
  else if (atom_equals (fun, "get_e2attrs"))
    return run_get_e2attrs (message);
  else if (atom_equals (fun, "get_e2generation"))
    return run_get_e2generation (message);
  else if (atom_equals (fun, "get_e2label"))
    return run_get_e2label (message);
  else if (atom_equals (fun, "get_e2uuid"))
    return run_get_e2uuid (message);
  else if (atom_equals (fun, "get_hv"))
    return run_get_hv (message);
  else if (atom_equals (fun, "get_identifier"))
    return run_get_identifier (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_challenge"))
    return run_get_libvirt_requested_credential_challenge (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_defresult"))
    return run_get_libvirt_requested_credential_defresult (message);
  else if (atom_equals (fun, "get_libvirt_requested_credential_prompt"))
    return run_get_libvirt_requested_credential_prompt (message);
  else if (atom_equals (fun, "get_libvirt_requested_credentials"))
    return run_get_libvirt_requested_credentials (message);
  else if (atom_equals (fun, "get_memsize"))
    return run_get_memsize (message);
  else if (atom_equals (fun, "get_network"))
    return run_get_network (message);
  else if (atom_equals (fun, "get_path"))
    return run_get_path (message);
  else if (atom_equals (fun, "get_pgroup"))
    return run_get_pgroup (message);
  else if (atom_equals (fun, "get_pid"))
    return run_get_pid (message);
  else if (atom_equals (fun, "get_program"))
    return run_get_program (message);
  else if (atom_equals (fun, "get_qemu"))
    return run_get_qemu (message);
  else if (atom_equals (fun, "get_recovery_proc"))
    return run_get_recovery_proc (message);
  else if (atom_equals (fun, "get_selinux"))
    return run_get_selinux (message);
  else if (atom_equals (fun, "get_smp"))
    return run_get_smp (message);
  else if (atom_equals (fun, "get_sockdir"))
    return run_get_sockdir (message);
  else if (atom_equals (fun, "get_state"))
    return run_get_state (message);
  else if (atom_equals (fun, "get_tmpdir"))
    return run_get_tmpdir (message);
  else if (atom_equals (fun, "get_trace"))
    return run_get_trace (message);
  else if (atom_equals (fun, "get_umask"))
    return run_get_umask (message);
  else if (atom_equals (fun, "get_verbose"))
    return run_get_verbose (message);
  else if (atom_equals (fun, "getcon"))
    return run_getcon (message);
  else if (atom_equals (fun, "getxattr"))
    return run_getxattr (message);
  else if (atom_equals (fun, "getxattrs"))
    return run_getxattrs (message);
  else if (atom_equals (fun, "glob_expand"))
    return run_glob_expand (message);
  else if (atom_equals (fun, "grep"))
    return run_grep (message);
  else if (atom_equals (fun, "grepi"))
    return run_grepi (message);
  else if (atom_equals (fun, "grub_install"))
    return run_grub_install (message);
  else if (atom_equals (fun, "head"))
    return run_head (message);
  else if (atom_equals (fun, "head_n"))
    return run_head_n (message);
  else if (atom_equals (fun, "hexdump"))
    return run_hexdump (message);
  else if (atom_equals (fun, "hivex_close"))
    return run_hivex_close (message);
  else if (atom_equals (fun, "hivex_commit"))
    return run_hivex_commit (message);
  else if (atom_equals (fun, "hivex_node_add_child"))
    return run_hivex_node_add_child (message);
  else if (atom_equals (fun, "hivex_node_children"))
    return run_hivex_node_children (message);
  else if (atom_equals (fun, "hivex_node_delete_child"))
    return run_hivex_node_delete_child (message);
  else if (atom_equals (fun, "hivex_node_get_child"))
    return run_hivex_node_get_child (message);
  else if (atom_equals (fun, "hivex_node_get_value"))
    return run_hivex_node_get_value (message);
  else if (atom_equals (fun, "hivex_node_name"))
    return run_hivex_node_name (message);
  else if (atom_equals (fun, "hivex_node_parent"))
    return run_hivex_node_parent (message);
  else if (atom_equals (fun, "hivex_node_set_value"))
    return run_hivex_node_set_value (message);
  else if (atom_equals (fun, "hivex_node_values"))
    return run_hivex_node_values (message);
  else if (atom_equals (fun, "hivex_open"))
    return run_hivex_open (message);
  else if (atom_equals (fun, "hivex_root"))
    return run_hivex_root (message);
  else if (atom_equals (fun, "hivex_value_key"))
    return run_hivex_value_key (message);
  else if (atom_equals (fun, "hivex_value_type"))
    return run_hivex_value_type (message);
  else if (atom_equals (fun, "hivex_value_utf8"))
    return run_hivex_value_utf8 (message);
  else if (atom_equals (fun, "hivex_value_value"))
    return run_hivex_value_value (message);
  else if (atom_equals (fun, "initrd_cat"))
    return run_initrd_cat (message);
  else if (atom_equals (fun, "initrd_list"))
    return run_initrd_list (message);
  else if (atom_equals (fun, "inotify_add_watch"))
    return run_inotify_add_watch (message);
  else if (atom_equals (fun, "inotify_close"))
    return run_inotify_close (message);
  else if (atom_equals (fun, "inotify_files"))
    return run_inotify_files (message);
  else if (atom_equals (fun, "inotify_init"))
    return run_inotify_init (message);
  else if (atom_equals (fun, "inotify_read"))
    return run_inotify_read (message);
  else if (atom_equals (fun, "inotify_rm_watch"))
    return run_inotify_rm_watch (message);
  else if (atom_equals (fun, "inspect_get_arch"))
    return run_inspect_get_arch (message);
  else if (atom_equals (fun, "inspect_get_distro"))
    return run_inspect_get_distro (message);
  else if (atom_equals (fun, "inspect_get_drive_mappings"))
    return run_inspect_get_drive_mappings (message);
  else if (atom_equals (fun, "inspect_get_filesystems"))
    return run_inspect_get_filesystems (message);
  else if (atom_equals (fun, "inspect_get_format"))
    return run_inspect_get_format (message);
  else if (atom_equals (fun, "inspect_get_hostname"))
    return run_inspect_get_hostname (message);
  else if (atom_equals (fun, "inspect_get_icon"))
    return run_inspect_get_icon (message);
  else if (atom_equals (fun, "inspect_get_major_version"))
    return run_inspect_get_major_version (message);
  else if (atom_equals (fun, "inspect_get_minor_version"))
    return run_inspect_get_minor_version (message);
  else if (atom_equals (fun, "inspect_get_mountpoints"))
    return run_inspect_get_mountpoints (message);
  else if (atom_equals (fun, "inspect_get_package_format"))
    return run_inspect_get_package_format (message);
  else if (atom_equals (fun, "inspect_get_package_management"))
    return run_inspect_get_package_management (message);
  else if (atom_equals (fun, "inspect_get_product_name"))
    return run_inspect_get_product_name (message);
  else if (atom_equals (fun, "inspect_get_product_variant"))
    return run_inspect_get_product_variant (message);
  else if (atom_equals (fun, "inspect_get_roots"))
    return run_inspect_get_roots (message);
  else if (atom_equals (fun, "inspect_get_type"))
    return run_inspect_get_type (message);
  else if (atom_equals (fun, "inspect_get_windows_current_control_set"))
    return run_inspect_get_windows_current_control_set (message);
  else if (atom_equals (fun, "inspect_get_windows_software_hive"))
    return run_inspect_get_windows_software_hive (message);
  else if (atom_equals (fun, "inspect_get_windows_system_hive"))
    return run_inspect_get_windows_system_hive (message);
  else if (atom_equals (fun, "inspect_get_windows_systemroot"))
    return run_inspect_get_windows_systemroot (message);
  else if (atom_equals (fun, "inspect_is_live"))
    return run_inspect_is_live (message);
  else if (atom_equals (fun, "inspect_is_multipart"))
    return run_inspect_is_multipart (message);
  else if (atom_equals (fun, "inspect_is_netinst"))
    return run_inspect_is_netinst (message);
  else if (atom_equals (fun, "inspect_list_applications"))
    return run_inspect_list_applications (message);
  else if (atom_equals (fun, "inspect_list_applications2"))
    return run_inspect_list_applications2 (message);
  else if (atom_equals (fun, "inspect_os"))
    return run_inspect_os (message);
  else if (atom_equals (fun, "internal_exit"))
    return run_internal_exit (message);
  else if (atom_equals (fun, "internal_test"))
    return run_internal_test (message);
  else if (atom_equals (fun, "internal_test_63_optargs"))
    return run_internal_test_63_optargs (message);
  else if (atom_equals (fun, "internal_test_close_output"))
    return run_internal_test_close_output (message);
  else if (atom_equals (fun, "internal_test_only_optargs"))
    return run_internal_test_only_optargs (message);
  else if (atom_equals (fun, "internal_test_rbool"))
    return run_internal_test_rbool (message);
  else if (atom_equals (fun, "internal_test_rboolerr"))
    return run_internal_test_rboolerr (message);
  else if (atom_equals (fun, "internal_test_rbufferout"))
    return run_internal_test_rbufferout (message);
  else if (atom_equals (fun, "internal_test_rbufferouterr"))
    return run_internal_test_rbufferouterr (message);
  else if (atom_equals (fun, "internal_test_rconstoptstring"))
    return run_internal_test_rconstoptstring (message);
  else if (atom_equals (fun, "internal_test_rconstoptstringerr"))
    return run_internal_test_rconstoptstringerr (message);
  else if (atom_equals (fun, "internal_test_rconststring"))
    return run_internal_test_rconststring (message);
  else if (atom_equals (fun, "internal_test_rconststringerr"))
    return run_internal_test_rconststringerr (message);
  else if (atom_equals (fun, "internal_test_rhashtable"))
    return run_internal_test_rhashtable (message);
  else if (atom_equals (fun, "internal_test_rhashtableerr"))
    return run_internal_test_rhashtableerr (message);
  else if (atom_equals (fun, "internal_test_rint"))
    return run_internal_test_rint (message);
  else if (atom_equals (fun, "internal_test_rint64"))
    return run_internal_test_rint64 (message);
  else if (atom_equals (fun, "internal_test_rint64err"))
    return run_internal_test_rint64err (message);
  else if (atom_equals (fun, "internal_test_rinterr"))
    return run_internal_test_rinterr (message);
  else if (atom_equals (fun, "internal_test_rstring"))
    return run_internal_test_rstring (message);
  else if (atom_equals (fun, "internal_test_rstringerr"))
    return run_internal_test_rstringerr (message);
  else if (atom_equals (fun, "internal_test_rstringlist"))
    return run_internal_test_rstringlist (message);
  else if (atom_equals (fun, "internal_test_rstringlisterr"))
    return run_internal_test_rstringlisterr (message);
  else if (atom_equals (fun, "internal_test_rstruct"))
    return run_internal_test_rstruct (message);
  else if (atom_equals (fun, "internal_test_rstructerr"))
    return run_internal_test_rstructerr (message);
  else if (atom_equals (fun, "internal_test_rstructlist"))
    return run_internal_test_rstructlist (message);
  else if (atom_equals (fun, "internal_test_rstructlisterr"))
    return run_internal_test_rstructlisterr (message);
  else if (atom_equals (fun, "internal_test_set_output"))
    return run_internal_test_set_output (message);
  else if (atom_equals (fun, "is_blockdev"))
    return run_is_blockdev (message);
  else if (atom_equals (fun, "is_busy"))
    return run_is_busy (message);
  else if (atom_equals (fun, "is_chardev"))
    return run_is_chardev (message);
  else if (atom_equals (fun, "is_config"))
    return run_is_config (message);
  else if (atom_equals (fun, "is_dir"))
    return run_is_dir (message);
  else if (atom_equals (fun, "is_fifo"))
    return run_is_fifo (message);
  else if (atom_equals (fun, "is_file"))
    return run_is_file (message);
  else if (atom_equals (fun, "is_launching"))
    return run_is_launching (message);
  else if (atom_equals (fun, "is_lv"))
    return run_is_lv (message);
  else if (atom_equals (fun, "is_ready"))
    return run_is_ready (message);
  else if (atom_equals (fun, "is_socket"))
    return run_is_socket (message);
  else if (atom_equals (fun, "is_symlink"))
    return run_is_symlink (message);
  else if (atom_equals (fun, "is_whole_device"))
    return run_is_whole_device (message);
  else if (atom_equals (fun, "is_zero"))
    return run_is_zero (message);
  else if (atom_equals (fun, "is_zero_device"))
    return run_is_zero_device (message);
  else if (atom_equals (fun, "isoinfo"))
    return run_isoinfo (message);
  else if (atom_equals (fun, "isoinfo_device"))
    return run_isoinfo_device (message);
  else if (atom_equals (fun, "journal_close"))
    return run_journal_close (message);
  else if (atom_equals (fun, "journal_get"))
    return run_journal_get (message);
  else if (atom_equals (fun, "journal_get_data_threshold"))
    return run_journal_get_data_threshold (message);
  else if (atom_equals (fun, "journal_get_realtime_usec"))
    return run_journal_get_realtime_usec (message);
  else if (atom_equals (fun, "journal_next"))
    return run_journal_next (message);
  else if (atom_equals (fun, "journal_open"))
    return run_journal_open (message);
  else if (atom_equals (fun, "journal_set_data_threshold"))
    return run_journal_set_data_threshold (message);
  else if (atom_equals (fun, "journal_skip"))
    return run_journal_skip (message);
  else if (atom_equals (fun, "kill_subprocess"))
    return run_kill_subprocess (message);
  else if (atom_equals (fun, "launch"))
    return run_launch (message);
  else if (atom_equals (fun, "lchown"))
    return run_lchown (message);
  else if (atom_equals (fun, "ldmtool_create_all"))
    return run_ldmtool_create_all (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_disks"))
    return run_ldmtool_diskgroup_disks (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_name"))
    return run_ldmtool_diskgroup_name (message);
  else if (atom_equals (fun, "ldmtool_diskgroup_volumes"))
    return run_ldmtool_diskgroup_volumes (message);
  else if (atom_equals (fun, "ldmtool_remove_all"))
    return run_ldmtool_remove_all (message);
  else if (atom_equals (fun, "ldmtool_scan"))
    return run_ldmtool_scan (message);
  else if (atom_equals (fun, "ldmtool_scan_devices"))
    return run_ldmtool_scan_devices (message);
  else if (atom_equals (fun, "ldmtool_volume_hint"))
    return run_ldmtool_volume_hint (message);
  else if (atom_equals (fun, "ldmtool_volume_partitions"))
    return run_ldmtool_volume_partitions (message);
  else if (atom_equals (fun, "ldmtool_volume_type"))
    return run_ldmtool_volume_type (message);
  else if (atom_equals (fun, "lgetxattr"))
    return run_lgetxattr (message);
  else if (atom_equals (fun, "lgetxattrs"))
    return run_lgetxattrs (message);
  else if (atom_equals (fun, "list_9p"))
    return run_list_9p (message);
  else if (atom_equals (fun, "list_devices"))
    return run_list_devices (message);
  else if (atom_equals (fun, "list_disk_labels"))
    return run_list_disk_labels (message);
  else if (atom_equals (fun, "list_dm_devices"))
    return run_list_dm_devices (message);
  else if (atom_equals (fun, "list_filesystems"))
    return run_list_filesystems (message);
  else if (atom_equals (fun, "list_ldm_partitions"))
    return run_list_ldm_partitions (message);
  else if (atom_equals (fun, "list_ldm_volumes"))
    return run_list_ldm_volumes (message);
  else if (atom_equals (fun, "list_md_devices"))
    return run_list_md_devices (message);
  else if (atom_equals (fun, "list_partitions"))
    return run_list_partitions (message);
  else if (atom_equals (fun, "ll"))
    return run_ll (message);
  else if (atom_equals (fun, "llz"))
    return run_llz (message);
  else if (atom_equals (fun, "ln"))
    return run_ln (message);
  else if (atom_equals (fun, "ln_f"))
    return run_ln_f (message);
  else if (atom_equals (fun, "ln_s"))
    return run_ln_s (message);
  else if (atom_equals (fun, "ln_sf"))
    return run_ln_sf (message);
  else if (atom_equals (fun, "lremovexattr"))
    return run_lremovexattr (message);
  else if (atom_equals (fun, "ls"))
    return run_ls (message);
  else if (atom_equals (fun, "ls0"))
    return run_ls0 (message);
  else if (atom_equals (fun, "lsetxattr"))
    return run_lsetxattr (message);
  else if (atom_equals (fun, "lstat"))
    return run_lstat (message);
  else if (atom_equals (fun, "lstatlist"))
    return run_lstatlist (message);
  else if (atom_equals (fun, "lstatns"))
    return run_lstatns (message);
  else if (atom_equals (fun, "lstatnslist"))
    return run_lstatnslist (message);
  else if (atom_equals (fun, "luks_add_key"))
    return run_luks_add_key (message);
  else if (atom_equals (fun, "luks_close"))
    return run_luks_close (message);
  else if (atom_equals (fun, "luks_format"))
    return run_luks_format (message);
  else if (atom_equals (fun, "luks_format_cipher"))
    return run_luks_format_cipher (message);
  else if (atom_equals (fun, "luks_kill_slot"))
    return run_luks_kill_slot (message);
  else if (atom_equals (fun, "luks_open"))
    return run_luks_open (message);
  else if (atom_equals (fun, "luks_open_ro"))
    return run_luks_open_ro (message);
  else if (atom_equals (fun, "lvcreate"))
    return run_lvcreate (message);
  else if (atom_equals (fun, "lvcreate_free"))
    return run_lvcreate_free (message);
  else if (atom_equals (fun, "lvm_canonical_lv_name"))
    return run_lvm_canonical_lv_name (message);
  else if (atom_equals (fun, "lvm_clear_filter"))
    return run_lvm_clear_filter (message);
  else if (atom_equals (fun, "lvm_remove_all"))
    return run_lvm_remove_all (message);
  else if (atom_equals (fun, "lvm_set_filter"))
    return run_lvm_set_filter (message);
  else if (atom_equals (fun, "lvremove"))
    return run_lvremove (message);
  else if (atom_equals (fun, "lvrename"))
    return run_lvrename (message);
  else if (atom_equals (fun, "lvresize"))
    return run_lvresize (message);
  else if (atom_equals (fun, "lvresize_free"))
    return run_lvresize_free (message);
  else if (atom_equals (fun, "lvs"))
    return run_lvs (message);
  else if (atom_equals (fun, "lvs_full"))
    return run_lvs_full (message);
  else if (atom_equals (fun, "lvuuid"))
    return run_lvuuid (message);
  else if (atom_equals (fun, "lxattrlist"))
    return run_lxattrlist (message);
  else if (atom_equals (fun, "max_disks"))
    return run_max_disks (message);
  else if (atom_equals (fun, "md_create"))
    return run_md_create (message);
  else if (atom_equals (fun, "md_detail"))
    return run_md_detail (message);
  else if (atom_equals (fun, "md_stat"))
    return run_md_stat (message);
  else if (atom_equals (fun, "md_stop"))
    return run_md_stop (message);
  else if (atom_equals (fun, "mkdir"))
    return run_mkdir (message);
  else if (atom_equals (fun, "mkdir_mode"))
    return run_mkdir_mode (message);
  else if (atom_equals (fun, "mkdir_p"))
    return run_mkdir_p (message);
  else if (atom_equals (fun, "mkdtemp"))
    return run_mkdtemp (message);
  else if (atom_equals (fun, "mke2fs"))
    return run_mke2fs (message);
  else if (atom_equals (fun, "mke2fs_J"))
    return run_mke2fs_J (message);
  else if (atom_equals (fun, "mke2fs_JL"))
    return run_mke2fs_JL (message);
  else if (atom_equals (fun, "mke2fs_JU"))
    return run_mke2fs_JU (message);
  else if (atom_equals (fun, "mke2journal"))
    return run_mke2journal (message);
  else if (atom_equals (fun, "mke2journal_L"))
    return run_mke2journal_L (message);
  else if (atom_equals (fun, "mke2journal_U"))
    return run_mke2journal_U (message);
  else if (atom_equals (fun, "mkfifo"))
    return run_mkfifo (message);
  else if (atom_equals (fun, "mkfs"))
    return run_mkfs (message);
  else if (atom_equals (fun, "mkfs_b"))
    return run_mkfs_b (message);
  else if (atom_equals (fun, "mkfs_btrfs"))
    return run_mkfs_btrfs (message);
  else if (atom_equals (fun, "mklost_and_found"))
    return run_mklost_and_found (message);
  else if (atom_equals (fun, "mkmountpoint"))
    return run_mkmountpoint (message);
  else if (atom_equals (fun, "mknod"))
    return run_mknod (message);
  else if (atom_equals (fun, "mknod_b"))
    return run_mknod_b (message);
  else if (atom_equals (fun, "mknod_c"))
    return run_mknod_c (message);
  else if (atom_equals (fun, "mksquashfs"))
    return run_mksquashfs (message);
  else if (atom_equals (fun, "mkswap"))
    return run_mkswap (message);
  else if (atom_equals (fun, "mkswap_L"))
    return run_mkswap_L (message);
  else if (atom_equals (fun, "mkswap_U"))
    return run_mkswap_U (message);
  else if (atom_equals (fun, "mkswap_file"))
    return run_mkswap_file (message);
  else if (atom_equals (fun, "mktemp"))
    return run_mktemp (message);
  else if (atom_equals (fun, "modprobe"))
    return run_modprobe (message);
  else if (atom_equals (fun, "mount"))
    return run_mount (message);
  else if (atom_equals (fun, "mount_9p"))
    return run_mount_9p (message);
  else if (atom_equals (fun, "mount_local"))
    return run_mount_local (message);
  else if (atom_equals (fun, "mount_local_run"))
    return run_mount_local_run (message);
  else if (atom_equals (fun, "mount_loop"))
    return run_mount_loop (message);
  else if (atom_equals (fun, "mount_options"))
    return run_mount_options (message);
  else if (atom_equals (fun, "mount_ro"))
    return run_mount_ro (message);
  else if (atom_equals (fun, "mount_vfs"))
    return run_mount_vfs (message);
  else if (atom_equals (fun, "mountable_device"))
    return run_mountable_device (message);
  else if (atom_equals (fun, "mountable_subvolume"))
    return run_mountable_subvolume (message);
  else if (atom_equals (fun, "mountpoints"))
    return run_mountpoints (message);
  else if (atom_equals (fun, "mounts"))
    return run_mounts (message);
  else if (atom_equals (fun, "mv"))
    return run_mv (message);
  else if (atom_equals (fun, "nr_devices"))
    return run_nr_devices (message);
  else if (atom_equals (fun, "ntfs_3g_probe"))
    return run_ntfs_3g_probe (message);
  else if (atom_equals (fun, "ntfscat_i"))
    return run_ntfscat_i (message);
  else if (atom_equals (fun, "ntfsclone_in"))
    return run_ntfsclone_in (message);
  else if (atom_equals (fun, "ntfsclone_out"))
    return run_ntfsclone_out (message);
  else if (atom_equals (fun, "ntfsfix"))
    return run_ntfsfix (message);
  else if (atom_equals (fun, "ntfsresize"))
    return run_ntfsresize (message);
  else if (atom_equals (fun, "ntfsresize_size"))
    return run_ntfsresize_size (message);
  else if (atom_equals (fun, "parse_environment"))
    return run_parse_environment (message);
  else if (atom_equals (fun, "parse_environment_list"))
    return run_parse_environment_list (message);
  else if (atom_equals (fun, "part_add"))
    return run_part_add (message);
  else if (atom_equals (fun, "part_del"))
    return run_part_del (message);
  else if (atom_equals (fun, "part_disk"))
    return run_part_disk (message);
  else if (atom_equals (fun, "part_expand_gpt"))
    return run_part_expand_gpt (message);
  else if (atom_equals (fun, "part_get_bootable"))
    return run_part_get_bootable (message);
  else if (atom_equals (fun, "part_get_disk_guid"))
    return run_part_get_disk_guid (message);
  else if (atom_equals (fun, "part_get_gpt_guid"))
    return run_part_get_gpt_guid (message);
  else if (atom_equals (fun, "part_get_gpt_type"))
    return run_part_get_gpt_type (message);
  else if (atom_equals (fun, "part_get_mbr_id"))
    return run_part_get_mbr_id (message);
  else if (atom_equals (fun, "part_get_mbr_part_type"))
    return run_part_get_mbr_part_type (message);
  else if (atom_equals (fun, "part_get_name"))
    return run_part_get_name (message);
  else if (atom_equals (fun, "part_get_parttype"))
    return run_part_get_parttype (message);
  else if (atom_equals (fun, "part_init"))
    return run_part_init (message);
  else if (atom_equals (fun, "part_list"))
    return run_part_list (message);
  else if (atom_equals (fun, "part_set_bootable"))
    return run_part_set_bootable (message);
  else if (atom_equals (fun, "part_set_disk_guid"))
    return run_part_set_disk_guid (message);
  else if (atom_equals (fun, "part_set_disk_guid_random"))
    return run_part_set_disk_guid_random (message);
  else if (atom_equals (fun, "part_set_gpt_guid"))
    return run_part_set_gpt_guid (message);
  else if (atom_equals (fun, "part_set_gpt_type"))
    return run_part_set_gpt_type (message);
  else if (atom_equals (fun, "part_set_mbr_id"))
    return run_part_set_mbr_id (message);
  else if (atom_equals (fun, "part_set_name"))
    return run_part_set_name (message);
  else if (atom_equals (fun, "part_to_dev"))
    return run_part_to_dev (message);
  else if (atom_equals (fun, "part_to_partnum"))
    return run_part_to_partnum (message);
  else if (atom_equals (fun, "ping_daemon"))
    return run_ping_daemon (message);
  else if (atom_equals (fun, "pread"))
    return run_pread (message);
  else if (atom_equals (fun, "pread_device"))
    return run_pread_device (message);
  else if (atom_equals (fun, "pvchange_uuid"))
    return run_pvchange_uuid (message);
  else if (atom_equals (fun, "pvchange_uuid_all"))
    return run_pvchange_uuid_all (message);
  else if (atom_equals (fun, "pvcreate"))
    return run_pvcreate (message);
  else if (atom_equals (fun, "pvremove"))
    return run_pvremove (message);
  else if (atom_equals (fun, "pvresize"))
    return run_pvresize (message);
  else if (atom_equals (fun, "pvresize_size"))
    return run_pvresize_size (message);
  else if (atom_equals (fun, "pvs"))
    return run_pvs (message);
  else if (atom_equals (fun, "pvs_full"))
    return run_pvs_full (message);
  else if (atom_equals (fun, "pvuuid"))
    return run_pvuuid (message);
  else if (atom_equals (fun, "pwrite"))
    return run_pwrite (message);
  else if (atom_equals (fun, "pwrite_device"))
    return run_pwrite_device (message);
  else if (atom_equals (fun, "read_file"))
    return run_read_file (message);
  else if (atom_equals (fun, "read_lines"))
    return run_read_lines (message);
  else if (atom_equals (fun, "readdir"))
    return run_readdir (message);
  else if (atom_equals (fun, "readlink"))
    return run_readlink (message);
  else if (atom_equals (fun, "readlinklist"))
    return run_readlinklist (message);
  else if (atom_equals (fun, "realpath"))
    return run_realpath (message);
  else if (atom_equals (fun, "remount"))
    return run_remount (message);
  else if (atom_equals (fun, "remove_drive"))
    return run_remove_drive (message);
  else if (atom_equals (fun, "removexattr"))
    return run_removexattr (message);
  else if (atom_equals (fun, "rename"))
    return run_rename (message);
  else if (atom_equals (fun, "resize2fs"))
    return run_resize2fs (message);
  else if (atom_equals (fun, "resize2fs_M"))
    return run_resize2fs_M (message);
  else if (atom_equals (fun, "resize2fs_size"))
    return run_resize2fs_size (message);
  else if (atom_equals (fun, "rm"))
    return run_rm (message);
  else if (atom_equals (fun, "rm_f"))
    return run_rm_f (message);
  else if (atom_equals (fun, "rm_rf"))
    return run_rm_rf (message);
  else if (atom_equals (fun, "rmdir"))
    return run_rmdir (message);
  else if (atom_equals (fun, "rmmountpoint"))
    return run_rmmountpoint (message);
  else if (atom_equals (fun, "rsync"))
    return run_rsync (message);
  else if (atom_equals (fun, "rsync_in"))
    return run_rsync_in (message);
  else if (atom_equals (fun, "rsync_out"))
    return run_rsync_out (message);
  else if (atom_equals (fun, "scrub_device"))
    return run_scrub_device (message);
  else if (atom_equals (fun, "scrub_file"))
    return run_scrub_file (message);
  else if (atom_equals (fun, "scrub_freespace"))
    return run_scrub_freespace (message);
  else if (atom_equals (fun, "selinux_relabel"))
    return run_selinux_relabel (message);
  else if (atom_equals (fun, "set_append"))
    return run_set_append (message);
  else if (atom_equals (fun, "set_attach_method"))
    return run_set_attach_method (message);
  else if (atom_equals (fun, "set_autosync"))
    return run_set_autosync (message);
  else if (atom_equals (fun, "set_backend"))
    return run_set_backend (message);
  else if (atom_equals (fun, "set_backend_setting"))
    return run_set_backend_setting (message);
  else if (atom_equals (fun, "set_backend_settings"))
    return run_set_backend_settings (message);
  else if (atom_equals (fun, "set_cachedir"))
    return run_set_cachedir (message);
  else if (atom_equals (fun, "set_direct"))
    return run_set_direct (message);
  else if (atom_equals (fun, "set_e2attrs"))
    return run_set_e2attrs (message);
  else if (atom_equals (fun, "set_e2generation"))
    return run_set_e2generation (message);
  else if (atom_equals (fun, "set_e2label"))
    return run_set_e2label (message);
  else if (atom_equals (fun, "set_e2uuid"))
    return run_set_e2uuid (message);
  else if (atom_equals (fun, "set_hv"))
    return run_set_hv (message);
  else if (atom_equals (fun, "set_identifier"))
    return run_set_identifier (message);
  else if (atom_equals (fun, "set_label"))
    return run_set_label (message);
  else if (atom_equals (fun, "set_libvirt_requested_credential"))
    return run_set_libvirt_requested_credential (message);
  else if (atom_equals (fun, "set_libvirt_supported_credentials"))
    return run_set_libvirt_supported_credentials (message);
  else if (atom_equals (fun, "set_memsize"))
    return run_set_memsize (message);
  else if (atom_equals (fun, "set_network"))
    return run_set_network (message);
  else if (atom_equals (fun, "set_path"))
    return run_set_path (message);
  else if (atom_equals (fun, "set_pgroup"))
    return run_set_pgroup (message);
  else if (atom_equals (fun, "set_program"))
    return run_set_program (message);
  else if (atom_equals (fun, "set_qemu"))
    return run_set_qemu (message);
  else if (atom_equals (fun, "set_recovery_proc"))
    return run_set_recovery_proc (message);
  else if (atom_equals (fun, "set_selinux"))
    return run_set_selinux (message);
  else if (atom_equals (fun, "set_smp"))
    return run_set_smp (message);
  else if (atom_equals (fun, "set_tmpdir"))
    return run_set_tmpdir (message);
  else if (atom_equals (fun, "set_trace"))
    return run_set_trace (message);
  else if (atom_equals (fun, "set_uuid"))
    return run_set_uuid (message);
  else if (atom_equals (fun, "set_uuid_random"))
    return run_set_uuid_random (message);
  else if (atom_equals (fun, "set_verbose"))
    return run_set_verbose (message);
  else if (atom_equals (fun, "setcon"))
    return run_setcon (message);
  else if (atom_equals (fun, "setxattr"))
    return run_setxattr (message);
  else if (atom_equals (fun, "sfdisk"))
    return run_sfdisk (message);
  else if (atom_equals (fun, "sfdiskM"))
    return run_sfdiskM (message);
  else if (atom_equals (fun, "sfdisk_N"))
    return run_sfdisk_N (message);
  else if (atom_equals (fun, "sfdisk_disk_geometry"))
    return run_sfdisk_disk_geometry (message);
  else if (atom_equals (fun, "sfdisk_kernel_geometry"))
    return run_sfdisk_kernel_geometry (message);
  else if (atom_equals (fun, "sfdisk_l"))
    return run_sfdisk_l (message);
  else if (atom_equals (fun, "sh"))
    return run_sh (message);
  else if (atom_equals (fun, "sh_lines"))
    return run_sh_lines (message);
  else if (atom_equals (fun, "shutdown"))
    return run_shutdown (message);
  else if (atom_equals (fun, "sleep"))
    return run_sleep (message);
  else if (atom_equals (fun, "stat"))
    return run_stat (message);
  else if (atom_equals (fun, "statns"))
    return run_statns (message);
  else if (atom_equals (fun, "statvfs"))
    return run_statvfs (message);
  else if (atom_equals (fun, "strings"))
    return run_strings (message);
  else if (atom_equals (fun, "strings_e"))
    return run_strings_e (message);
  else if (atom_equals (fun, "swapoff_device"))
    return run_swapoff_device (message);
  else if (atom_equals (fun, "swapoff_file"))
    return run_swapoff_file (message);
  else if (atom_equals (fun, "swapoff_label"))
    return run_swapoff_label (message);
  else if (atom_equals (fun, "swapoff_uuid"))
    return run_swapoff_uuid (message);
  else if (atom_equals (fun, "swapon_device"))
    return run_swapon_device (message);
  else if (atom_equals (fun, "swapon_file"))
    return run_swapon_file (message);
  else if (atom_equals (fun, "swapon_label"))
    return run_swapon_label (message);
  else if (atom_equals (fun, "swapon_uuid"))
    return run_swapon_uuid (message);
  else if (atom_equals (fun, "sync"))
    return run_sync (message);
  else if (atom_equals (fun, "syslinux"))
    return run_syslinux (message);
  else if (atom_equals (fun, "tail"))
    return run_tail (message);
  else if (atom_equals (fun, "tail_n"))
    return run_tail_n (message);
  else if (atom_equals (fun, "tar_in"))
    return run_tar_in (message);
  else if (atom_equals (fun, "tar_out"))
    return run_tar_out (message);
  else if (atom_equals (fun, "tgz_in"))
    return run_tgz_in (message);
  else if (atom_equals (fun, "tgz_out"))
    return run_tgz_out (message);
  else if (atom_equals (fun, "touch"))
    return run_touch (message);
  else if (atom_equals (fun, "truncate"))
    return run_truncate (message);
  else if (atom_equals (fun, "truncate_size"))
    return run_truncate_size (message);
  else if (atom_equals (fun, "tune2fs"))
    return run_tune2fs (message);
  else if (atom_equals (fun, "tune2fs_l"))
    return run_tune2fs_l (message);
  else if (atom_equals (fun, "txz_in"))
    return run_txz_in (message);
  else if (atom_equals (fun, "txz_out"))
    return run_txz_out (message);
  else if (atom_equals (fun, "umask"))
    return run_umask (message);
  else if (atom_equals (fun, "umount"))
    return run_umount (message);
  else if (atom_equals (fun, "umount_all"))
    return run_umount_all (message);
  else if (atom_equals (fun, "umount_local"))
    return run_umount_local (message);
  else if (atom_equals (fun, "upload"))
    return run_upload (message);
  else if (atom_equals (fun, "upload_offset"))
    return run_upload_offset (message);
  else if (atom_equals (fun, "user_cancel"))
    return run_user_cancel (message);
  else if (atom_equals (fun, "utimens"))
    return run_utimens (message);
  else if (atom_equals (fun, "utsname"))
    return run_utsname (message);
  else if (atom_equals (fun, "version"))
    return run_version (message);
  else if (atom_equals (fun, "vfs_label"))
    return run_vfs_label (message);
  else if (atom_equals (fun, "vfs_minimum_size"))
    return run_vfs_minimum_size (message);
  else if (atom_equals (fun, "vfs_type"))
    return run_vfs_type (message);
  else if (atom_equals (fun, "vfs_uuid"))
    return run_vfs_uuid (message);
  else if (atom_equals (fun, "vg_activate"))
    return run_vg_activate (message);
  else if (atom_equals (fun, "vg_activate_all"))
    return run_vg_activate_all (message);
  else if (atom_equals (fun, "vgchange_uuid"))
    return run_vgchange_uuid (message);
  else if (atom_equals (fun, "vgchange_uuid_all"))
    return run_vgchange_uuid_all (message);
  else if (atom_equals (fun, "vgcreate"))
    return run_vgcreate (message);
  else if (atom_equals (fun, "vglvuuids"))
    return run_vglvuuids (message);
  else if (atom_equals (fun, "vgmeta"))
    return run_vgmeta (message);
  else if (atom_equals (fun, "vgpvuuids"))
    return run_vgpvuuids (message);
  else if (atom_equals (fun, "vgremove"))
    return run_vgremove (message);
  else if (atom_equals (fun, "vgrename"))
    return run_vgrename (message);
  else if (atom_equals (fun, "vgs"))
    return run_vgs (message);
  else if (atom_equals (fun, "vgs_full"))
    return run_vgs_full (message);
  else if (atom_equals (fun, "vgscan"))
    return run_vgscan (message);
  else if (atom_equals (fun, "vguuid"))
    return run_vguuid (message);
  else if (atom_equals (fun, "wait_ready"))
    return run_wait_ready (message);
  else if (atom_equals (fun, "wc_c"))
    return run_wc_c (message);
  else if (atom_equals (fun, "wc_l"))
    return run_wc_l (message);
  else if (atom_equals (fun, "wc_w"))
    return run_wc_w (message);
  else if (atom_equals (fun, "wipefs"))
    return run_wipefs (message);
  else if (atom_equals (fun, "write"))
    return run_write (message);
  else if (atom_equals (fun, "write_append"))
    return run_write_append (message);
  else if (atom_equals (fun, "write_file"))
    return run_write_file (message);
  else if (atom_equals (fun, "xfs_admin"))
    return run_xfs_admin (message);
  else if (atom_equals (fun, "xfs_growfs"))
    return run_xfs_growfs (message);
  else if (atom_equals (fun, "xfs_info"))
    return run_xfs_info (message);
  else if (atom_equals (fun, "xfs_repair"))
    return run_xfs_repair (message);
  else if (atom_equals (fun, "zegrep"))
    return run_zegrep (message);
  else if (atom_equals (fun, "zegrepi"))
    return run_zegrepi (message);
  else if (atom_equals (fun, "zero"))
    return run_zero (message);
  else if (atom_equals (fun, "zero_device"))
    return run_zero_device (message);
  else if (atom_equals (fun, "zero_free_space"))
    return run_zero_free_space (message);
  else if (atom_equals (fun, "zerofree"))
    return run_zerofree (message);
  else if (atom_equals (fun, "zfgrep"))
    return run_zfgrep (message);
  else if (atom_equals (fun, "zfgrepi"))
    return run_zfgrepi (message);
  else if (atom_equals (fun, "zfile"))
    return run_zfile (message);
  else if (atom_equals (fun, "zgrep"))
    return run_zgrep (message);
  else if (atom_equals (fun, "zgrepi"))
    return run_zgrepi (message);
  else return unknown_function (fun);
}
