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
dispatch (ETERM *args_tuple)
{
  ETERM *fun;

  fun = ERL_TUPLE_ELEMENT (args_tuple, 0);

  /* XXX We should use gperf here. */
  if (atom_equals (fun, "acl_delete_def_file"))
    return run_acl_delete_def_file (args_tuple);
  else if (atom_equals (fun, "acl_get_file"))
    return run_acl_get_file (args_tuple);
  else if (atom_equals (fun, "acl_set_file"))
    return run_acl_set_file (args_tuple);
  else if (atom_equals (fun, "add_cdrom"))
    return run_add_cdrom (args_tuple);
  else if (atom_equals (fun, "add_domain"))
    return run_add_domain (args_tuple);
  else if (atom_equals (fun, "add_drive"))
    return run_add_drive (args_tuple);
  else if (atom_equals (fun, "add_drive_ro"))
    return run_add_drive_ro (args_tuple);
  else if (atom_equals (fun, "add_drive_ro_with_if"))
    return run_add_drive_ro_with_if (args_tuple);
  else if (atom_equals (fun, "add_drive_scratch"))
    return run_add_drive_scratch (args_tuple);
  else if (atom_equals (fun, "add_drive_with_if"))
    return run_add_drive_with_if (args_tuple);
  else if (atom_equals (fun, "add_libvirt_dom"))
    return run_add_libvirt_dom (args_tuple);
  else if (atom_equals (fun, "aug_clear"))
    return run_aug_clear (args_tuple);
  else if (atom_equals (fun, "aug_close"))
    return run_aug_close (args_tuple);
  else if (atom_equals (fun, "aug_defnode"))
    return run_aug_defnode (args_tuple);
  else if (atom_equals (fun, "aug_defvar"))
    return run_aug_defvar (args_tuple);
  else if (atom_equals (fun, "aug_get"))
    return run_aug_get (args_tuple);
  else if (atom_equals (fun, "aug_init"))
    return run_aug_init (args_tuple);
  else if (atom_equals (fun, "aug_insert"))
    return run_aug_insert (args_tuple);
  else if (atom_equals (fun, "aug_label"))
    return run_aug_label (args_tuple);
  else if (atom_equals (fun, "aug_load"))
    return run_aug_load (args_tuple);
  else if (atom_equals (fun, "aug_ls"))
    return run_aug_ls (args_tuple);
  else if (atom_equals (fun, "aug_match"))
    return run_aug_match (args_tuple);
  else if (atom_equals (fun, "aug_mv"))
    return run_aug_mv (args_tuple);
  else if (atom_equals (fun, "aug_rm"))
    return run_aug_rm (args_tuple);
  else if (atom_equals (fun, "aug_save"))
    return run_aug_save (args_tuple);
  else if (atom_equals (fun, "aug_set"))
    return run_aug_set (args_tuple);
  else if (atom_equals (fun, "aug_setm"))
    return run_aug_setm (args_tuple);
  else if (atom_equals (fun, "available"))
    return run_available (args_tuple);
  else if (atom_equals (fun, "available_all_groups"))
    return run_available_all_groups (args_tuple);
  else if (atom_equals (fun, "base64_in"))
    return run_base64_in (args_tuple);
  else if (atom_equals (fun, "base64_out"))
    return run_base64_out (args_tuple);
  else if (atom_equals (fun, "blkdiscard"))
    return run_blkdiscard (args_tuple);
  else if (atom_equals (fun, "blkdiscardzeroes"))
    return run_blkdiscardzeroes (args_tuple);
  else if (atom_equals (fun, "blkid"))
    return run_blkid (args_tuple);
  else if (atom_equals (fun, "blockdev_flushbufs"))
    return run_blockdev_flushbufs (args_tuple);
  else if (atom_equals (fun, "blockdev_getbsz"))
    return run_blockdev_getbsz (args_tuple);
  else if (atom_equals (fun, "blockdev_getro"))
    return run_blockdev_getro (args_tuple);
  else if (atom_equals (fun, "blockdev_getsize64"))
    return run_blockdev_getsize64 (args_tuple);
  else if (atom_equals (fun, "blockdev_getss"))
    return run_blockdev_getss (args_tuple);
  else if (atom_equals (fun, "blockdev_getsz"))
    return run_blockdev_getsz (args_tuple);
  else if (atom_equals (fun, "blockdev_rereadpt"))
    return run_blockdev_rereadpt (args_tuple);
  else if (atom_equals (fun, "blockdev_setbsz"))
    return run_blockdev_setbsz (args_tuple);
  else if (atom_equals (fun, "blockdev_setra"))
    return run_blockdev_setra (args_tuple);
  else if (atom_equals (fun, "blockdev_setro"))
    return run_blockdev_setro (args_tuple);
  else if (atom_equals (fun, "blockdev_setrw"))
    return run_blockdev_setrw (args_tuple);
  else if (atom_equals (fun, "btrfs_balance_cancel"))
    return run_btrfs_balance_cancel (args_tuple);
  else if (atom_equals (fun, "btrfs_balance_pause"))
    return run_btrfs_balance_pause (args_tuple);
  else if (atom_equals (fun, "btrfs_balance_resume"))
    return run_btrfs_balance_resume (args_tuple);
  else if (atom_equals (fun, "btrfs_balance_status"))
    return run_btrfs_balance_status (args_tuple);
  else if (atom_equals (fun, "btrfs_device_add"))
    return run_btrfs_device_add (args_tuple);
  else if (atom_equals (fun, "btrfs_device_delete"))
    return run_btrfs_device_delete (args_tuple);
  else if (atom_equals (fun, "btrfs_filesystem_balance"))
    return run_btrfs_filesystem_balance (args_tuple);
  else if (atom_equals (fun, "btrfs_filesystem_defragment"))
    return run_btrfs_filesystem_defragment (args_tuple);
  else if (atom_equals (fun, "btrfs_filesystem_resize"))
    return run_btrfs_filesystem_resize (args_tuple);
  else if (atom_equals (fun, "btrfs_filesystem_show"))
    return run_btrfs_filesystem_show (args_tuple);
  else if (atom_equals (fun, "btrfs_filesystem_sync"))
    return run_btrfs_filesystem_sync (args_tuple);
  else if (atom_equals (fun, "btrfs_fsck"))
    return run_btrfs_fsck (args_tuple);
  else if (atom_equals (fun, "btrfs_image"))
    return run_btrfs_image (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_assign"))
    return run_btrfs_qgroup_assign (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_create"))
    return run_btrfs_qgroup_create (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_destroy"))
    return run_btrfs_qgroup_destroy (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_limit"))
    return run_btrfs_qgroup_limit (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_remove"))
    return run_btrfs_qgroup_remove (args_tuple);
  else if (atom_equals (fun, "btrfs_qgroup_show"))
    return run_btrfs_qgroup_show (args_tuple);
  else if (atom_equals (fun, "btrfs_quota_enable"))
    return run_btrfs_quota_enable (args_tuple);
  else if (atom_equals (fun, "btrfs_quota_rescan"))
    return run_btrfs_quota_rescan (args_tuple);
  else if (atom_equals (fun, "btrfs_replace"))
    return run_btrfs_replace (args_tuple);
  else if (atom_equals (fun, "btrfs_rescue_chunk_recover"))
    return run_btrfs_rescue_chunk_recover (args_tuple);
  else if (atom_equals (fun, "btrfs_rescue_super_recover"))
    return run_btrfs_rescue_super_recover (args_tuple);
  else if (atom_equals (fun, "btrfs_scrub_cancel"))
    return run_btrfs_scrub_cancel (args_tuple);
  else if (atom_equals (fun, "btrfs_scrub_resume"))
    return run_btrfs_scrub_resume (args_tuple);
  else if (atom_equals (fun, "btrfs_scrub_start"))
    return run_btrfs_scrub_start (args_tuple);
  else if (atom_equals (fun, "btrfs_scrub_status"))
    return run_btrfs_scrub_status (args_tuple);
  else if (atom_equals (fun, "btrfs_set_seeding"))
    return run_btrfs_set_seeding (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_create"))
    return run_btrfs_subvolume_create (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_delete"))
    return run_btrfs_subvolume_delete (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_get_default"))
    return run_btrfs_subvolume_get_default (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_list"))
    return run_btrfs_subvolume_list (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_set_default"))
    return run_btrfs_subvolume_set_default (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_show"))
    return run_btrfs_subvolume_show (args_tuple);
  else if (atom_equals (fun, "btrfs_subvolume_snapshot"))
    return run_btrfs_subvolume_snapshot (args_tuple);
  else if (atom_equals (fun, "btrfstune_enable_extended_inode_refs"))
    return run_btrfstune_enable_extended_inode_refs (args_tuple);
  else if (atom_equals (fun, "btrfstune_enable_skinny_metadata_extent_refs"))
    return run_btrfstune_enable_skinny_metadata_extent_refs (args_tuple);
  else if (atom_equals (fun, "btrfstune_seeding"))
    return run_btrfstune_seeding (args_tuple);
  else if (atom_equals (fun, "c_pointer"))
    return run_c_pointer (args_tuple);
  else if (atom_equals (fun, "canonical_device_name"))
    return run_canonical_device_name (args_tuple);
  else if (atom_equals (fun, "cap_get_file"))
    return run_cap_get_file (args_tuple);
  else if (atom_equals (fun, "cap_set_file"))
    return run_cap_set_file (args_tuple);
  else if (atom_equals (fun, "case_sensitive_path"))
    return run_case_sensitive_path (args_tuple);
  else if (atom_equals (fun, "cat"))
    return run_cat (args_tuple);
  else if (atom_equals (fun, "checksum"))
    return run_checksum (args_tuple);
  else if (atom_equals (fun, "checksum_device"))
    return run_checksum_device (args_tuple);
  else if (atom_equals (fun, "checksums_out"))
    return run_checksums_out (args_tuple);
  else if (atom_equals (fun, "chmod"))
    return run_chmod (args_tuple);
  else if (atom_equals (fun, "chown"))
    return run_chown (args_tuple);
  else if (atom_equals (fun, "clear_backend_setting"))
    return run_clear_backend_setting (args_tuple);
  else if (atom_equals (fun, "command"))
    return run_command (args_tuple);
  else if (atom_equals (fun, "command_lines"))
    return run_command_lines (args_tuple);
  else if (atom_equals (fun, "compress_device_out"))
    return run_compress_device_out (args_tuple);
  else if (atom_equals (fun, "compress_out"))
    return run_compress_out (args_tuple);
  else if (atom_equals (fun, "config"))
    return run_config (args_tuple);
  else if (atom_equals (fun, "copy_attributes"))
    return run_copy_attributes (args_tuple);
  else if (atom_equals (fun, "copy_device_to_device"))
    return run_copy_device_to_device (args_tuple);
  else if (atom_equals (fun, "copy_device_to_file"))
    return run_copy_device_to_file (args_tuple);
  else if (atom_equals (fun, "copy_file_to_device"))
    return run_copy_file_to_device (args_tuple);
  else if (atom_equals (fun, "copy_file_to_file"))
    return run_copy_file_to_file (args_tuple);
  else if (atom_equals (fun, "copy_in"))
    return run_copy_in (args_tuple);
  else if (atom_equals (fun, "copy_out"))
    return run_copy_out (args_tuple);
  else if (atom_equals (fun, "copy_size"))
    return run_copy_size (args_tuple);
  else if (atom_equals (fun, "cp"))
    return run_cp (args_tuple);
  else if (atom_equals (fun, "cp_a"))
    return run_cp_a (args_tuple);
  else if (atom_equals (fun, "cp_r"))
    return run_cp_r (args_tuple);
  else if (atom_equals (fun, "cpio_out"))
    return run_cpio_out (args_tuple);
  else if (atom_equals (fun, "dd"))
    return run_dd (args_tuple);
  else if (atom_equals (fun, "debug"))
    return run_debug (args_tuple);
  else if (atom_equals (fun, "debug_drives"))
    return run_debug_drives (args_tuple);
  else if (atom_equals (fun, "debug_upload"))
    return run_debug_upload (args_tuple);
  else if (atom_equals (fun, "device_index"))
    return run_device_index (args_tuple);
  else if (atom_equals (fun, "df"))
    return run_df (args_tuple);
  else if (atom_equals (fun, "df_h"))
    return run_df_h (args_tuple);
  else if (atom_equals (fun, "disk_create"))
    return run_disk_create (args_tuple);
  else if (atom_equals (fun, "disk_format"))
    return run_disk_format (args_tuple);
  else if (atom_equals (fun, "disk_has_backing_file"))
    return run_disk_has_backing_file (args_tuple);
  else if (atom_equals (fun, "disk_virtual_size"))
    return run_disk_virtual_size (args_tuple);
  else if (atom_equals (fun, "dmesg"))
    return run_dmesg (args_tuple);
  else if (atom_equals (fun, "download"))
    return run_download (args_tuple);
  else if (atom_equals (fun, "download_blocks"))
    return run_download_blocks (args_tuple);
  else if (atom_equals (fun, "download_inode"))
    return run_download_inode (args_tuple);
  else if (atom_equals (fun, "download_offset"))
    return run_download_offset (args_tuple);
  else if (atom_equals (fun, "drop_caches"))
    return run_drop_caches (args_tuple);
  else if (atom_equals (fun, "du"))
    return run_du (args_tuple);
  else if (atom_equals (fun, "e2fsck"))
    return run_e2fsck (args_tuple);
  else if (atom_equals (fun, "e2fsck_f"))
    return run_e2fsck_f (args_tuple);
  else if (atom_equals (fun, "echo_daemon"))
    return run_echo_daemon (args_tuple);
  else if (atom_equals (fun, "egrep"))
    return run_egrep (args_tuple);
  else if (atom_equals (fun, "egrepi"))
    return run_egrepi (args_tuple);
  else if (atom_equals (fun, "equal"))
    return run_equal (args_tuple);
  else if (atom_equals (fun, "exists"))
    return run_exists (args_tuple);
  else if (atom_equals (fun, "extlinux"))
    return run_extlinux (args_tuple);
  else if (atom_equals (fun, "fallocate"))
    return run_fallocate (args_tuple);
  else if (atom_equals (fun, "fallocate64"))
    return run_fallocate64 (args_tuple);
  else if (atom_equals (fun, "feature_available"))
    return run_feature_available (args_tuple);
  else if (atom_equals (fun, "fgrep"))
    return run_fgrep (args_tuple);
  else if (atom_equals (fun, "fgrepi"))
    return run_fgrepi (args_tuple);
  else if (atom_equals (fun, "file"))
    return run_file (args_tuple);
  else if (atom_equals (fun, "file_architecture"))
    return run_file_architecture (args_tuple);
  else if (atom_equals (fun, "filesize"))
    return run_filesize (args_tuple);
  else if (atom_equals (fun, "filesystem_available"))
    return run_filesystem_available (args_tuple);
  else if (atom_equals (fun, "filesystem_walk"))
    return run_filesystem_walk (args_tuple);
  else if (atom_equals (fun, "fill"))
    return run_fill (args_tuple);
  else if (atom_equals (fun, "fill_dir"))
    return run_fill_dir (args_tuple);
  else if (atom_equals (fun, "fill_pattern"))
    return run_fill_pattern (args_tuple);
  else if (atom_equals (fun, "find"))
    return run_find (args_tuple);
  else if (atom_equals (fun, "find0"))
    return run_find0 (args_tuple);
  else if (atom_equals (fun, "findfs_label"))
    return run_findfs_label (args_tuple);
  else if (atom_equals (fun, "findfs_uuid"))
    return run_findfs_uuid (args_tuple);
  else if (atom_equals (fun, "fsck"))
    return run_fsck (args_tuple);
  else if (atom_equals (fun, "fstrim"))
    return run_fstrim (args_tuple);
  else if (atom_equals (fun, "get_append"))
    return run_get_append (args_tuple);
  else if (atom_equals (fun, "get_attach_method"))
    return run_get_attach_method (args_tuple);
  else if (atom_equals (fun, "get_autosync"))
    return run_get_autosync (args_tuple);
  else if (atom_equals (fun, "get_backend"))
    return run_get_backend (args_tuple);
  else if (atom_equals (fun, "get_backend_setting"))
    return run_get_backend_setting (args_tuple);
  else if (atom_equals (fun, "get_backend_settings"))
    return run_get_backend_settings (args_tuple);
  else if (atom_equals (fun, "get_cachedir"))
    return run_get_cachedir (args_tuple);
  else if (atom_equals (fun, "get_direct"))
    return run_get_direct (args_tuple);
  else if (atom_equals (fun, "get_e2attrs"))
    return run_get_e2attrs (args_tuple);
  else if (atom_equals (fun, "get_e2generation"))
    return run_get_e2generation (args_tuple);
  else if (atom_equals (fun, "get_e2label"))
    return run_get_e2label (args_tuple);
  else if (atom_equals (fun, "get_e2uuid"))
    return run_get_e2uuid (args_tuple);
  else if (atom_equals (fun, "get_hv"))
    return run_get_hv (args_tuple);
  else if (atom_equals (fun, "get_identifier"))
    return run_get_identifier (args_tuple);
  else if (atom_equals (fun, "get_libvirt_requested_credential_challenge"))
    return run_get_libvirt_requested_credential_challenge (args_tuple);
  else if (atom_equals (fun, "get_libvirt_requested_credential_defresult"))
    return run_get_libvirt_requested_credential_defresult (args_tuple);
  else if (atom_equals (fun, "get_libvirt_requested_credential_prompt"))
    return run_get_libvirt_requested_credential_prompt (args_tuple);
  else if (atom_equals (fun, "get_libvirt_requested_credentials"))
    return run_get_libvirt_requested_credentials (args_tuple);
  else if (atom_equals (fun, "get_memsize"))
    return run_get_memsize (args_tuple);
  else if (atom_equals (fun, "get_network"))
    return run_get_network (args_tuple);
  else if (atom_equals (fun, "get_path"))
    return run_get_path (args_tuple);
  else if (atom_equals (fun, "get_pgroup"))
    return run_get_pgroup (args_tuple);
  else if (atom_equals (fun, "get_pid"))
    return run_get_pid (args_tuple);
  else if (atom_equals (fun, "get_program"))
    return run_get_program (args_tuple);
  else if (atom_equals (fun, "get_qemu"))
    return run_get_qemu (args_tuple);
  else if (atom_equals (fun, "get_recovery_proc"))
    return run_get_recovery_proc (args_tuple);
  else if (atom_equals (fun, "get_selinux"))
    return run_get_selinux (args_tuple);
  else if (atom_equals (fun, "get_smp"))
    return run_get_smp (args_tuple);
  else if (atom_equals (fun, "get_sockdir"))
    return run_get_sockdir (args_tuple);
  else if (atom_equals (fun, "get_state"))
    return run_get_state (args_tuple);
  else if (atom_equals (fun, "get_tmpdir"))
    return run_get_tmpdir (args_tuple);
  else if (atom_equals (fun, "get_trace"))
    return run_get_trace (args_tuple);
  else if (atom_equals (fun, "get_umask"))
    return run_get_umask (args_tuple);
  else if (atom_equals (fun, "get_verbose"))
    return run_get_verbose (args_tuple);
  else if (atom_equals (fun, "getcon"))
    return run_getcon (args_tuple);
  else if (atom_equals (fun, "getxattr"))
    return run_getxattr (args_tuple);
  else if (atom_equals (fun, "getxattrs"))
    return run_getxattrs (args_tuple);
  else if (atom_equals (fun, "glob_expand"))
    return run_glob_expand (args_tuple);
  else if (atom_equals (fun, "grep"))
    return run_grep (args_tuple);
  else if (atom_equals (fun, "grepi"))
    return run_grepi (args_tuple);
  else if (atom_equals (fun, "grub_install"))
    return run_grub_install (args_tuple);
  else if (atom_equals (fun, "head"))
    return run_head (args_tuple);
  else if (atom_equals (fun, "head_n"))
    return run_head_n (args_tuple);
  else if (atom_equals (fun, "hexdump"))
    return run_hexdump (args_tuple);
  else if (atom_equals (fun, "hivex_close"))
    return run_hivex_close (args_tuple);
  else if (atom_equals (fun, "hivex_commit"))
    return run_hivex_commit (args_tuple);
  else if (atom_equals (fun, "hivex_node_add_child"))
    return run_hivex_node_add_child (args_tuple);
  else if (atom_equals (fun, "hivex_node_children"))
    return run_hivex_node_children (args_tuple);
  else if (atom_equals (fun, "hivex_node_delete_child"))
    return run_hivex_node_delete_child (args_tuple);
  else if (atom_equals (fun, "hivex_node_get_child"))
    return run_hivex_node_get_child (args_tuple);
  else if (atom_equals (fun, "hivex_node_get_value"))
    return run_hivex_node_get_value (args_tuple);
  else if (atom_equals (fun, "hivex_node_name"))
    return run_hivex_node_name (args_tuple);
  else if (atom_equals (fun, "hivex_node_parent"))
    return run_hivex_node_parent (args_tuple);
  else if (atom_equals (fun, "hivex_node_set_value"))
    return run_hivex_node_set_value (args_tuple);
  else if (atom_equals (fun, "hivex_node_values"))
    return run_hivex_node_values (args_tuple);
  else if (atom_equals (fun, "hivex_open"))
    return run_hivex_open (args_tuple);
  else if (atom_equals (fun, "hivex_root"))
    return run_hivex_root (args_tuple);
  else if (atom_equals (fun, "hivex_value_key"))
    return run_hivex_value_key (args_tuple);
  else if (atom_equals (fun, "hivex_value_type"))
    return run_hivex_value_type (args_tuple);
  else if (atom_equals (fun, "hivex_value_utf8"))
    return run_hivex_value_utf8 (args_tuple);
  else if (atom_equals (fun, "hivex_value_value"))
    return run_hivex_value_value (args_tuple);
  else if (atom_equals (fun, "initrd_cat"))
    return run_initrd_cat (args_tuple);
  else if (atom_equals (fun, "initrd_list"))
    return run_initrd_list (args_tuple);
  else if (atom_equals (fun, "inotify_add_watch"))
    return run_inotify_add_watch (args_tuple);
  else if (atom_equals (fun, "inotify_close"))
    return run_inotify_close (args_tuple);
  else if (atom_equals (fun, "inotify_files"))
    return run_inotify_files (args_tuple);
  else if (atom_equals (fun, "inotify_init"))
    return run_inotify_init (args_tuple);
  else if (atom_equals (fun, "inotify_read"))
    return run_inotify_read (args_tuple);
  else if (atom_equals (fun, "inotify_rm_watch"))
    return run_inotify_rm_watch (args_tuple);
  else if (atom_equals (fun, "inspect_get_arch"))
    return run_inspect_get_arch (args_tuple);
  else if (atom_equals (fun, "inspect_get_distro"))
    return run_inspect_get_distro (args_tuple);
  else if (atom_equals (fun, "inspect_get_drive_mappings"))
    return run_inspect_get_drive_mappings (args_tuple);
  else if (atom_equals (fun, "inspect_get_filesystems"))
    return run_inspect_get_filesystems (args_tuple);
  else if (atom_equals (fun, "inspect_get_format"))
    return run_inspect_get_format (args_tuple);
  else if (atom_equals (fun, "inspect_get_hostname"))
    return run_inspect_get_hostname (args_tuple);
  else if (atom_equals (fun, "inspect_get_icon"))
    return run_inspect_get_icon (args_tuple);
  else if (atom_equals (fun, "inspect_get_major_version"))
    return run_inspect_get_major_version (args_tuple);
  else if (atom_equals (fun, "inspect_get_minor_version"))
    return run_inspect_get_minor_version (args_tuple);
  else if (atom_equals (fun, "inspect_get_mountpoints"))
    return run_inspect_get_mountpoints (args_tuple);
  else if (atom_equals (fun, "inspect_get_package_format"))
    return run_inspect_get_package_format (args_tuple);
  else if (atom_equals (fun, "inspect_get_package_management"))
    return run_inspect_get_package_management (args_tuple);
  else if (atom_equals (fun, "inspect_get_product_name"))
    return run_inspect_get_product_name (args_tuple);
  else if (atom_equals (fun, "inspect_get_product_variant"))
    return run_inspect_get_product_variant (args_tuple);
  else if (atom_equals (fun, "inspect_get_roots"))
    return run_inspect_get_roots (args_tuple);
  else if (atom_equals (fun, "inspect_get_type"))
    return run_inspect_get_type (args_tuple);
  else if (atom_equals (fun, "inspect_get_windows_current_control_set"))
    return run_inspect_get_windows_current_control_set (args_tuple);
  else if (atom_equals (fun, "inspect_get_windows_systemroot"))
    return run_inspect_get_windows_systemroot (args_tuple);
  else if (atom_equals (fun, "inspect_is_live"))
    return run_inspect_is_live (args_tuple);
  else if (atom_equals (fun, "inspect_is_multipart"))
    return run_inspect_is_multipart (args_tuple);
  else if (atom_equals (fun, "inspect_is_netinst"))
    return run_inspect_is_netinst (args_tuple);
  else if (atom_equals (fun, "inspect_list_applications"))
    return run_inspect_list_applications (args_tuple);
  else if (atom_equals (fun, "inspect_list_applications2"))
    return run_inspect_list_applications2 (args_tuple);
  else if (atom_equals (fun, "inspect_os"))
    return run_inspect_os (args_tuple);
  else if (atom_equals (fun, "internal_exit"))
    return run_internal_exit (args_tuple);
  else if (atom_equals (fun, "internal_test"))
    return run_internal_test (args_tuple);
  else if (atom_equals (fun, "internal_test_63_optargs"))
    return run_internal_test_63_optargs (args_tuple);
  else if (atom_equals (fun, "internal_test_close_output"))
    return run_internal_test_close_output (args_tuple);
  else if (atom_equals (fun, "internal_test_only_optargs"))
    return run_internal_test_only_optargs (args_tuple);
  else if (atom_equals (fun, "internal_test_rbool"))
    return run_internal_test_rbool (args_tuple);
  else if (atom_equals (fun, "internal_test_rboolerr"))
    return run_internal_test_rboolerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rbufferout"))
    return run_internal_test_rbufferout (args_tuple);
  else if (atom_equals (fun, "internal_test_rbufferouterr"))
    return run_internal_test_rbufferouterr (args_tuple);
  else if (atom_equals (fun, "internal_test_rconstoptstring"))
    return run_internal_test_rconstoptstring (args_tuple);
  else if (atom_equals (fun, "internal_test_rconstoptstringerr"))
    return run_internal_test_rconstoptstringerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rconststring"))
    return run_internal_test_rconststring (args_tuple);
  else if (atom_equals (fun, "internal_test_rconststringerr"))
    return run_internal_test_rconststringerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rhashtable"))
    return run_internal_test_rhashtable (args_tuple);
  else if (atom_equals (fun, "internal_test_rhashtableerr"))
    return run_internal_test_rhashtableerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rint"))
    return run_internal_test_rint (args_tuple);
  else if (atom_equals (fun, "internal_test_rint64"))
    return run_internal_test_rint64 (args_tuple);
  else if (atom_equals (fun, "internal_test_rint64err"))
    return run_internal_test_rint64err (args_tuple);
  else if (atom_equals (fun, "internal_test_rinterr"))
    return run_internal_test_rinterr (args_tuple);
  else if (atom_equals (fun, "internal_test_rstring"))
    return run_internal_test_rstring (args_tuple);
  else if (atom_equals (fun, "internal_test_rstringerr"))
    return run_internal_test_rstringerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rstringlist"))
    return run_internal_test_rstringlist (args_tuple);
  else if (atom_equals (fun, "internal_test_rstringlisterr"))
    return run_internal_test_rstringlisterr (args_tuple);
  else if (atom_equals (fun, "internal_test_rstruct"))
    return run_internal_test_rstruct (args_tuple);
  else if (atom_equals (fun, "internal_test_rstructerr"))
    return run_internal_test_rstructerr (args_tuple);
  else if (atom_equals (fun, "internal_test_rstructlist"))
    return run_internal_test_rstructlist (args_tuple);
  else if (atom_equals (fun, "internal_test_rstructlisterr"))
    return run_internal_test_rstructlisterr (args_tuple);
  else if (atom_equals (fun, "internal_test_set_output"))
    return run_internal_test_set_output (args_tuple);
  else if (atom_equals (fun, "is_blockdev"))
    return run_is_blockdev (args_tuple);
  else if (atom_equals (fun, "is_busy"))
    return run_is_busy (args_tuple);
  else if (atom_equals (fun, "is_chardev"))
    return run_is_chardev (args_tuple);
  else if (atom_equals (fun, "is_config"))
    return run_is_config (args_tuple);
  else if (atom_equals (fun, "is_dir"))
    return run_is_dir (args_tuple);
  else if (atom_equals (fun, "is_fifo"))
    return run_is_fifo (args_tuple);
  else if (atom_equals (fun, "is_file"))
    return run_is_file (args_tuple);
  else if (atom_equals (fun, "is_launching"))
    return run_is_launching (args_tuple);
  else if (atom_equals (fun, "is_lv"))
    return run_is_lv (args_tuple);
  else if (atom_equals (fun, "is_ready"))
    return run_is_ready (args_tuple);
  else if (atom_equals (fun, "is_socket"))
    return run_is_socket (args_tuple);
  else if (atom_equals (fun, "is_symlink"))
    return run_is_symlink (args_tuple);
  else if (atom_equals (fun, "is_whole_device"))
    return run_is_whole_device (args_tuple);
  else if (atom_equals (fun, "is_zero"))
    return run_is_zero (args_tuple);
  else if (atom_equals (fun, "is_zero_device"))
    return run_is_zero_device (args_tuple);
  else if (atom_equals (fun, "isoinfo"))
    return run_isoinfo (args_tuple);
  else if (atom_equals (fun, "isoinfo_device"))
    return run_isoinfo_device (args_tuple);
  else if (atom_equals (fun, "journal_close"))
    return run_journal_close (args_tuple);
  else if (atom_equals (fun, "journal_get"))
    return run_journal_get (args_tuple);
  else if (atom_equals (fun, "journal_get_data_threshold"))
    return run_journal_get_data_threshold (args_tuple);
  else if (atom_equals (fun, "journal_get_realtime_usec"))
    return run_journal_get_realtime_usec (args_tuple);
  else if (atom_equals (fun, "journal_next"))
    return run_journal_next (args_tuple);
  else if (atom_equals (fun, "journal_open"))
    return run_journal_open (args_tuple);
  else if (atom_equals (fun, "journal_set_data_threshold"))
    return run_journal_set_data_threshold (args_tuple);
  else if (atom_equals (fun, "journal_skip"))
    return run_journal_skip (args_tuple);
  else if (atom_equals (fun, "kill_subprocess"))
    return run_kill_subprocess (args_tuple);
  else if (atom_equals (fun, "launch"))
    return run_launch (args_tuple);
  else if (atom_equals (fun, "lchown"))
    return run_lchown (args_tuple);
  else if (atom_equals (fun, "ldmtool_create_all"))
    return run_ldmtool_create_all (args_tuple);
  else if (atom_equals (fun, "ldmtool_diskgroup_disks"))
    return run_ldmtool_diskgroup_disks (args_tuple);
  else if (atom_equals (fun, "ldmtool_diskgroup_name"))
    return run_ldmtool_diskgroup_name (args_tuple);
  else if (atom_equals (fun, "ldmtool_diskgroup_volumes"))
    return run_ldmtool_diskgroup_volumes (args_tuple);
  else if (atom_equals (fun, "ldmtool_remove_all"))
    return run_ldmtool_remove_all (args_tuple);
  else if (atom_equals (fun, "ldmtool_scan"))
    return run_ldmtool_scan (args_tuple);
  else if (atom_equals (fun, "ldmtool_scan_devices"))
    return run_ldmtool_scan_devices (args_tuple);
  else if (atom_equals (fun, "ldmtool_volume_hint"))
    return run_ldmtool_volume_hint (args_tuple);
  else if (atom_equals (fun, "ldmtool_volume_partitions"))
    return run_ldmtool_volume_partitions (args_tuple);
  else if (atom_equals (fun, "ldmtool_volume_type"))
    return run_ldmtool_volume_type (args_tuple);
  else if (atom_equals (fun, "lgetxattr"))
    return run_lgetxattr (args_tuple);
  else if (atom_equals (fun, "lgetxattrs"))
    return run_lgetxattrs (args_tuple);
  else if (atom_equals (fun, "list_9p"))
    return run_list_9p (args_tuple);
  else if (atom_equals (fun, "list_devices"))
    return run_list_devices (args_tuple);
  else if (atom_equals (fun, "list_disk_labels"))
    return run_list_disk_labels (args_tuple);
  else if (atom_equals (fun, "list_dm_devices"))
    return run_list_dm_devices (args_tuple);
  else if (atom_equals (fun, "list_filesystems"))
    return run_list_filesystems (args_tuple);
  else if (atom_equals (fun, "list_ldm_partitions"))
    return run_list_ldm_partitions (args_tuple);
  else if (atom_equals (fun, "list_ldm_volumes"))
    return run_list_ldm_volumes (args_tuple);
  else if (atom_equals (fun, "list_md_devices"))
    return run_list_md_devices (args_tuple);
  else if (atom_equals (fun, "list_partitions"))
    return run_list_partitions (args_tuple);
  else if (atom_equals (fun, "ll"))
    return run_ll (args_tuple);
  else if (atom_equals (fun, "llz"))
    return run_llz (args_tuple);
  else if (atom_equals (fun, "ln"))
    return run_ln (args_tuple);
  else if (atom_equals (fun, "ln_f"))
    return run_ln_f (args_tuple);
  else if (atom_equals (fun, "ln_s"))
    return run_ln_s (args_tuple);
  else if (atom_equals (fun, "ln_sf"))
    return run_ln_sf (args_tuple);
  else if (atom_equals (fun, "lremovexattr"))
    return run_lremovexattr (args_tuple);
  else if (atom_equals (fun, "ls"))
    return run_ls (args_tuple);
  else if (atom_equals (fun, "ls0"))
    return run_ls0 (args_tuple);
  else if (atom_equals (fun, "lsetxattr"))
    return run_lsetxattr (args_tuple);
  else if (atom_equals (fun, "lstat"))
    return run_lstat (args_tuple);
  else if (atom_equals (fun, "lstatlist"))
    return run_lstatlist (args_tuple);
  else if (atom_equals (fun, "lstatns"))
    return run_lstatns (args_tuple);
  else if (atom_equals (fun, "lstatnslist"))
    return run_lstatnslist (args_tuple);
  else if (atom_equals (fun, "luks_add_key"))
    return run_luks_add_key (args_tuple);
  else if (atom_equals (fun, "luks_close"))
    return run_luks_close (args_tuple);
  else if (atom_equals (fun, "luks_format"))
    return run_luks_format (args_tuple);
  else if (atom_equals (fun, "luks_format_cipher"))
    return run_luks_format_cipher (args_tuple);
  else if (atom_equals (fun, "luks_kill_slot"))
    return run_luks_kill_slot (args_tuple);
  else if (atom_equals (fun, "luks_open"))
    return run_luks_open (args_tuple);
  else if (atom_equals (fun, "luks_open_ro"))
    return run_luks_open_ro (args_tuple);
  else if (atom_equals (fun, "lvcreate"))
    return run_lvcreate (args_tuple);
  else if (atom_equals (fun, "lvcreate_free"))
    return run_lvcreate_free (args_tuple);
  else if (atom_equals (fun, "lvm_canonical_lv_name"))
    return run_lvm_canonical_lv_name (args_tuple);
  else if (atom_equals (fun, "lvm_clear_filter"))
    return run_lvm_clear_filter (args_tuple);
  else if (atom_equals (fun, "lvm_remove_all"))
    return run_lvm_remove_all (args_tuple);
  else if (atom_equals (fun, "lvm_set_filter"))
    return run_lvm_set_filter (args_tuple);
  else if (atom_equals (fun, "lvremove"))
    return run_lvremove (args_tuple);
  else if (atom_equals (fun, "lvrename"))
    return run_lvrename (args_tuple);
  else if (atom_equals (fun, "lvresize"))
    return run_lvresize (args_tuple);
  else if (atom_equals (fun, "lvresize_free"))
    return run_lvresize_free (args_tuple);
  else if (atom_equals (fun, "lvs"))
    return run_lvs (args_tuple);
  else if (atom_equals (fun, "lvs_full"))
    return run_lvs_full (args_tuple);
  else if (atom_equals (fun, "lvuuid"))
    return run_lvuuid (args_tuple);
  else if (atom_equals (fun, "lxattrlist"))
    return run_lxattrlist (args_tuple);
  else if (atom_equals (fun, "max_disks"))
    return run_max_disks (args_tuple);
  else if (atom_equals (fun, "md_create"))
    return run_md_create (args_tuple);
  else if (atom_equals (fun, "md_detail"))
    return run_md_detail (args_tuple);
  else if (atom_equals (fun, "md_stat"))
    return run_md_stat (args_tuple);
  else if (atom_equals (fun, "md_stop"))
    return run_md_stop (args_tuple);
  else if (atom_equals (fun, "mkdir"))
    return run_mkdir (args_tuple);
  else if (atom_equals (fun, "mkdir_mode"))
    return run_mkdir_mode (args_tuple);
  else if (atom_equals (fun, "mkdir_p"))
    return run_mkdir_p (args_tuple);
  else if (atom_equals (fun, "mkdtemp"))
    return run_mkdtemp (args_tuple);
  else if (atom_equals (fun, "mke2fs"))
    return run_mke2fs (args_tuple);
  else if (atom_equals (fun, "mke2fs_J"))
    return run_mke2fs_J (args_tuple);
  else if (atom_equals (fun, "mke2fs_JL"))
    return run_mke2fs_JL (args_tuple);
  else if (atom_equals (fun, "mke2fs_JU"))
    return run_mke2fs_JU (args_tuple);
  else if (atom_equals (fun, "mke2journal"))
    return run_mke2journal (args_tuple);
  else if (atom_equals (fun, "mke2journal_L"))
    return run_mke2journal_L (args_tuple);
  else if (atom_equals (fun, "mke2journal_U"))
    return run_mke2journal_U (args_tuple);
  else if (atom_equals (fun, "mkfifo"))
    return run_mkfifo (args_tuple);
  else if (atom_equals (fun, "mkfs"))
    return run_mkfs (args_tuple);
  else if (atom_equals (fun, "mkfs_b"))
    return run_mkfs_b (args_tuple);
  else if (atom_equals (fun, "mkfs_btrfs"))
    return run_mkfs_btrfs (args_tuple);
  else if (atom_equals (fun, "mklost_and_found"))
    return run_mklost_and_found (args_tuple);
  else if (atom_equals (fun, "mkmountpoint"))
    return run_mkmountpoint (args_tuple);
  else if (atom_equals (fun, "mknod"))
    return run_mknod (args_tuple);
  else if (atom_equals (fun, "mknod_b"))
    return run_mknod_b (args_tuple);
  else if (atom_equals (fun, "mknod_c"))
    return run_mknod_c (args_tuple);
  else if (atom_equals (fun, "mkswap"))
    return run_mkswap (args_tuple);
  else if (atom_equals (fun, "mkswap_L"))
    return run_mkswap_L (args_tuple);
  else if (atom_equals (fun, "mkswap_U"))
    return run_mkswap_U (args_tuple);
  else if (atom_equals (fun, "mkswap_file"))
    return run_mkswap_file (args_tuple);
  else if (atom_equals (fun, "mktemp"))
    return run_mktemp (args_tuple);
  else if (atom_equals (fun, "modprobe"))
    return run_modprobe (args_tuple);
  else if (atom_equals (fun, "mount"))
    return run_mount (args_tuple);
  else if (atom_equals (fun, "mount_9p"))
    return run_mount_9p (args_tuple);
  else if (atom_equals (fun, "mount_local"))
    return run_mount_local (args_tuple);
  else if (atom_equals (fun, "mount_local_run"))
    return run_mount_local_run (args_tuple);
  else if (atom_equals (fun, "mount_loop"))
    return run_mount_loop (args_tuple);
  else if (atom_equals (fun, "mount_options"))
    return run_mount_options (args_tuple);
  else if (atom_equals (fun, "mount_ro"))
    return run_mount_ro (args_tuple);
  else if (atom_equals (fun, "mount_vfs"))
    return run_mount_vfs (args_tuple);
  else if (atom_equals (fun, "mountable_device"))
    return run_mountable_device (args_tuple);
  else if (atom_equals (fun, "mountable_subvolume"))
    return run_mountable_subvolume (args_tuple);
  else if (atom_equals (fun, "mountpoints"))
    return run_mountpoints (args_tuple);
  else if (atom_equals (fun, "mounts"))
    return run_mounts (args_tuple);
  else if (atom_equals (fun, "mv"))
    return run_mv (args_tuple);
  else if (atom_equals (fun, "nr_devices"))
    return run_nr_devices (args_tuple);
  else if (atom_equals (fun, "ntfs_3g_probe"))
    return run_ntfs_3g_probe (args_tuple);
  else if (atom_equals (fun, "ntfscat_i"))
    return run_ntfscat_i (args_tuple);
  else if (atom_equals (fun, "ntfsclone_in"))
    return run_ntfsclone_in (args_tuple);
  else if (atom_equals (fun, "ntfsclone_out"))
    return run_ntfsclone_out (args_tuple);
  else if (atom_equals (fun, "ntfsfix"))
    return run_ntfsfix (args_tuple);
  else if (atom_equals (fun, "ntfsresize"))
    return run_ntfsresize (args_tuple);
  else if (atom_equals (fun, "ntfsresize_size"))
    return run_ntfsresize_size (args_tuple);
  else if (atom_equals (fun, "parse_environment"))
    return run_parse_environment (args_tuple);
  else if (atom_equals (fun, "parse_environment_list"))
    return run_parse_environment_list (args_tuple);
  else if (atom_equals (fun, "part_add"))
    return run_part_add (args_tuple);
  else if (atom_equals (fun, "part_del"))
    return run_part_del (args_tuple);
  else if (atom_equals (fun, "part_disk"))
    return run_part_disk (args_tuple);
  else if (atom_equals (fun, "part_expand_gpt"))
    return run_part_expand_gpt (args_tuple);
  else if (atom_equals (fun, "part_get_bootable"))
    return run_part_get_bootable (args_tuple);
  else if (atom_equals (fun, "part_get_disk_guid"))
    return run_part_get_disk_guid (args_tuple);
  else if (atom_equals (fun, "part_get_gpt_guid"))
    return run_part_get_gpt_guid (args_tuple);
  else if (atom_equals (fun, "part_get_gpt_type"))
    return run_part_get_gpt_type (args_tuple);
  else if (atom_equals (fun, "part_get_mbr_id"))
    return run_part_get_mbr_id (args_tuple);
  else if (atom_equals (fun, "part_get_mbr_part_type"))
    return run_part_get_mbr_part_type (args_tuple);
  else if (atom_equals (fun, "part_get_name"))
    return run_part_get_name (args_tuple);
  else if (atom_equals (fun, "part_get_parttype"))
    return run_part_get_parttype (args_tuple);
  else if (atom_equals (fun, "part_init"))
    return run_part_init (args_tuple);
  else if (atom_equals (fun, "part_list"))
    return run_part_list (args_tuple);
  else if (atom_equals (fun, "part_set_bootable"))
    return run_part_set_bootable (args_tuple);
  else if (atom_equals (fun, "part_set_disk_guid"))
    return run_part_set_disk_guid (args_tuple);
  else if (atom_equals (fun, "part_set_disk_guid_random"))
    return run_part_set_disk_guid_random (args_tuple);
  else if (atom_equals (fun, "part_set_gpt_guid"))
    return run_part_set_gpt_guid (args_tuple);
  else if (atom_equals (fun, "part_set_gpt_type"))
    return run_part_set_gpt_type (args_tuple);
  else if (atom_equals (fun, "part_set_mbr_id"))
    return run_part_set_mbr_id (args_tuple);
  else if (atom_equals (fun, "part_set_name"))
    return run_part_set_name (args_tuple);
  else if (atom_equals (fun, "part_to_dev"))
    return run_part_to_dev (args_tuple);
  else if (atom_equals (fun, "part_to_partnum"))
    return run_part_to_partnum (args_tuple);
  else if (atom_equals (fun, "ping_daemon"))
    return run_ping_daemon (args_tuple);
  else if (atom_equals (fun, "pread"))
    return run_pread (args_tuple);
  else if (atom_equals (fun, "pread_device"))
    return run_pread_device (args_tuple);
  else if (atom_equals (fun, "pvchange_uuid"))
    return run_pvchange_uuid (args_tuple);
  else if (atom_equals (fun, "pvchange_uuid_all"))
    return run_pvchange_uuid_all (args_tuple);
  else if (atom_equals (fun, "pvcreate"))
    return run_pvcreate (args_tuple);
  else if (atom_equals (fun, "pvremove"))
    return run_pvremove (args_tuple);
  else if (atom_equals (fun, "pvresize"))
    return run_pvresize (args_tuple);
  else if (atom_equals (fun, "pvresize_size"))
    return run_pvresize_size (args_tuple);
  else if (atom_equals (fun, "pvs"))
    return run_pvs (args_tuple);
  else if (atom_equals (fun, "pvs_full"))
    return run_pvs_full (args_tuple);
  else if (atom_equals (fun, "pvuuid"))
    return run_pvuuid (args_tuple);
  else if (atom_equals (fun, "pwrite"))
    return run_pwrite (args_tuple);
  else if (atom_equals (fun, "pwrite_device"))
    return run_pwrite_device (args_tuple);
  else if (atom_equals (fun, "read_file"))
    return run_read_file (args_tuple);
  else if (atom_equals (fun, "read_lines"))
    return run_read_lines (args_tuple);
  else if (atom_equals (fun, "readdir"))
    return run_readdir (args_tuple);
  else if (atom_equals (fun, "readlink"))
    return run_readlink (args_tuple);
  else if (atom_equals (fun, "readlinklist"))
    return run_readlinklist (args_tuple);
  else if (atom_equals (fun, "realpath"))
    return run_realpath (args_tuple);
  else if (atom_equals (fun, "remount"))
    return run_remount (args_tuple);
  else if (atom_equals (fun, "remove_drive"))
    return run_remove_drive (args_tuple);
  else if (atom_equals (fun, "removexattr"))
    return run_removexattr (args_tuple);
  else if (atom_equals (fun, "rename"))
    return run_rename (args_tuple);
  else if (atom_equals (fun, "resize2fs"))
    return run_resize2fs (args_tuple);
  else if (atom_equals (fun, "resize2fs_M"))
    return run_resize2fs_M (args_tuple);
  else if (atom_equals (fun, "resize2fs_size"))
    return run_resize2fs_size (args_tuple);
  else if (atom_equals (fun, "rm"))
    return run_rm (args_tuple);
  else if (atom_equals (fun, "rm_f"))
    return run_rm_f (args_tuple);
  else if (atom_equals (fun, "rm_rf"))
    return run_rm_rf (args_tuple);
  else if (atom_equals (fun, "rmdir"))
    return run_rmdir (args_tuple);
  else if (atom_equals (fun, "rmmountpoint"))
    return run_rmmountpoint (args_tuple);
  else if (atom_equals (fun, "rsync"))
    return run_rsync (args_tuple);
  else if (atom_equals (fun, "rsync_in"))
    return run_rsync_in (args_tuple);
  else if (atom_equals (fun, "rsync_out"))
    return run_rsync_out (args_tuple);
  else if (atom_equals (fun, "scrub_device"))
    return run_scrub_device (args_tuple);
  else if (atom_equals (fun, "scrub_file"))
    return run_scrub_file (args_tuple);
  else if (atom_equals (fun, "scrub_freespace"))
    return run_scrub_freespace (args_tuple);
  else if (atom_equals (fun, "selinux_relabel"))
    return run_selinux_relabel (args_tuple);
  else if (atom_equals (fun, "set_append"))
    return run_set_append (args_tuple);
  else if (atom_equals (fun, "set_attach_method"))
    return run_set_attach_method (args_tuple);
  else if (atom_equals (fun, "set_autosync"))
    return run_set_autosync (args_tuple);
  else if (atom_equals (fun, "set_backend"))
    return run_set_backend (args_tuple);
  else if (atom_equals (fun, "set_backend_setting"))
    return run_set_backend_setting (args_tuple);
  else if (atom_equals (fun, "set_backend_settings"))
    return run_set_backend_settings (args_tuple);
  else if (atom_equals (fun, "set_cachedir"))
    return run_set_cachedir (args_tuple);
  else if (atom_equals (fun, "set_direct"))
    return run_set_direct (args_tuple);
  else if (atom_equals (fun, "set_e2attrs"))
    return run_set_e2attrs (args_tuple);
  else if (atom_equals (fun, "set_e2generation"))
    return run_set_e2generation (args_tuple);
  else if (atom_equals (fun, "set_e2label"))
    return run_set_e2label (args_tuple);
  else if (atom_equals (fun, "set_e2uuid"))
    return run_set_e2uuid (args_tuple);
  else if (atom_equals (fun, "set_hv"))
    return run_set_hv (args_tuple);
  else if (atom_equals (fun, "set_identifier"))
    return run_set_identifier (args_tuple);
  else if (atom_equals (fun, "set_label"))
    return run_set_label (args_tuple);
  else if (atom_equals (fun, "set_libvirt_requested_credential"))
    return run_set_libvirt_requested_credential (args_tuple);
  else if (atom_equals (fun, "set_libvirt_supported_credentials"))
    return run_set_libvirt_supported_credentials (args_tuple);
  else if (atom_equals (fun, "set_memsize"))
    return run_set_memsize (args_tuple);
  else if (atom_equals (fun, "set_network"))
    return run_set_network (args_tuple);
  else if (atom_equals (fun, "set_path"))
    return run_set_path (args_tuple);
  else if (atom_equals (fun, "set_pgroup"))
    return run_set_pgroup (args_tuple);
  else if (atom_equals (fun, "set_program"))
    return run_set_program (args_tuple);
  else if (atom_equals (fun, "set_qemu"))
    return run_set_qemu (args_tuple);
  else if (atom_equals (fun, "set_recovery_proc"))
    return run_set_recovery_proc (args_tuple);
  else if (atom_equals (fun, "set_selinux"))
    return run_set_selinux (args_tuple);
  else if (atom_equals (fun, "set_smp"))
    return run_set_smp (args_tuple);
  else if (atom_equals (fun, "set_tmpdir"))
    return run_set_tmpdir (args_tuple);
  else if (atom_equals (fun, "set_trace"))
    return run_set_trace (args_tuple);
  else if (atom_equals (fun, "set_uuid"))
    return run_set_uuid (args_tuple);
  else if (atom_equals (fun, "set_uuid_random"))
    return run_set_uuid_random (args_tuple);
  else if (atom_equals (fun, "set_verbose"))
    return run_set_verbose (args_tuple);
  else if (atom_equals (fun, "setcon"))
    return run_setcon (args_tuple);
  else if (atom_equals (fun, "setxattr"))
    return run_setxattr (args_tuple);
  else if (atom_equals (fun, "sfdisk"))
    return run_sfdisk (args_tuple);
  else if (atom_equals (fun, "sfdiskM"))
    return run_sfdiskM (args_tuple);
  else if (atom_equals (fun, "sfdisk_N"))
    return run_sfdisk_N (args_tuple);
  else if (atom_equals (fun, "sfdisk_disk_geometry"))
    return run_sfdisk_disk_geometry (args_tuple);
  else if (atom_equals (fun, "sfdisk_kernel_geometry"))
    return run_sfdisk_kernel_geometry (args_tuple);
  else if (atom_equals (fun, "sfdisk_l"))
    return run_sfdisk_l (args_tuple);
  else if (atom_equals (fun, "sh"))
    return run_sh (args_tuple);
  else if (atom_equals (fun, "sh_lines"))
    return run_sh_lines (args_tuple);
  else if (atom_equals (fun, "shutdown"))
    return run_shutdown (args_tuple);
  else if (atom_equals (fun, "sleep"))
    return run_sleep (args_tuple);
  else if (atom_equals (fun, "stat"))
    return run_stat (args_tuple);
  else if (atom_equals (fun, "statns"))
    return run_statns (args_tuple);
  else if (atom_equals (fun, "statvfs"))
    return run_statvfs (args_tuple);
  else if (atom_equals (fun, "strings"))
    return run_strings (args_tuple);
  else if (atom_equals (fun, "strings_e"))
    return run_strings_e (args_tuple);
  else if (atom_equals (fun, "swapoff_device"))
    return run_swapoff_device (args_tuple);
  else if (atom_equals (fun, "swapoff_file"))
    return run_swapoff_file (args_tuple);
  else if (atom_equals (fun, "swapoff_label"))
    return run_swapoff_label (args_tuple);
  else if (atom_equals (fun, "swapoff_uuid"))
    return run_swapoff_uuid (args_tuple);
  else if (atom_equals (fun, "swapon_device"))
    return run_swapon_device (args_tuple);
  else if (atom_equals (fun, "swapon_file"))
    return run_swapon_file (args_tuple);
  else if (atom_equals (fun, "swapon_label"))
    return run_swapon_label (args_tuple);
  else if (atom_equals (fun, "swapon_uuid"))
    return run_swapon_uuid (args_tuple);
  else if (atom_equals (fun, "sync"))
    return run_sync (args_tuple);
  else if (atom_equals (fun, "syslinux"))
    return run_syslinux (args_tuple);
  else if (atom_equals (fun, "tail"))
    return run_tail (args_tuple);
  else if (atom_equals (fun, "tail_n"))
    return run_tail_n (args_tuple);
  else if (atom_equals (fun, "tar_in"))
    return run_tar_in (args_tuple);
  else if (atom_equals (fun, "tar_out"))
    return run_tar_out (args_tuple);
  else if (atom_equals (fun, "tgz_in"))
    return run_tgz_in (args_tuple);
  else if (atom_equals (fun, "tgz_out"))
    return run_tgz_out (args_tuple);
  else if (atom_equals (fun, "touch"))
    return run_touch (args_tuple);
  else if (atom_equals (fun, "truncate"))
    return run_truncate (args_tuple);
  else if (atom_equals (fun, "truncate_size"))
    return run_truncate_size (args_tuple);
  else if (atom_equals (fun, "tune2fs"))
    return run_tune2fs (args_tuple);
  else if (atom_equals (fun, "tune2fs_l"))
    return run_tune2fs_l (args_tuple);
  else if (atom_equals (fun, "txz_in"))
    return run_txz_in (args_tuple);
  else if (atom_equals (fun, "txz_out"))
    return run_txz_out (args_tuple);
  else if (atom_equals (fun, "umask"))
    return run_umask (args_tuple);
  else if (atom_equals (fun, "umount"))
    return run_umount (args_tuple);
  else if (atom_equals (fun, "umount_all"))
    return run_umount_all (args_tuple);
  else if (atom_equals (fun, "umount_local"))
    return run_umount_local (args_tuple);
  else if (atom_equals (fun, "upload"))
    return run_upload (args_tuple);
  else if (atom_equals (fun, "upload_offset"))
    return run_upload_offset (args_tuple);
  else if (atom_equals (fun, "user_cancel"))
    return run_user_cancel (args_tuple);
  else if (atom_equals (fun, "utimens"))
    return run_utimens (args_tuple);
  else if (atom_equals (fun, "utsname"))
    return run_utsname (args_tuple);
  else if (atom_equals (fun, "version"))
    return run_version (args_tuple);
  else if (atom_equals (fun, "vfs_label"))
    return run_vfs_label (args_tuple);
  else if (atom_equals (fun, "vfs_minimum_size"))
    return run_vfs_minimum_size (args_tuple);
  else if (atom_equals (fun, "vfs_type"))
    return run_vfs_type (args_tuple);
  else if (atom_equals (fun, "vfs_uuid"))
    return run_vfs_uuid (args_tuple);
  else if (atom_equals (fun, "vg_activate"))
    return run_vg_activate (args_tuple);
  else if (atom_equals (fun, "vg_activate_all"))
    return run_vg_activate_all (args_tuple);
  else if (atom_equals (fun, "vgchange_uuid"))
    return run_vgchange_uuid (args_tuple);
  else if (atom_equals (fun, "vgchange_uuid_all"))
    return run_vgchange_uuid_all (args_tuple);
  else if (atom_equals (fun, "vgcreate"))
    return run_vgcreate (args_tuple);
  else if (atom_equals (fun, "vglvuuids"))
    return run_vglvuuids (args_tuple);
  else if (atom_equals (fun, "vgmeta"))
    return run_vgmeta (args_tuple);
  else if (atom_equals (fun, "vgpvuuids"))
    return run_vgpvuuids (args_tuple);
  else if (atom_equals (fun, "vgremove"))
    return run_vgremove (args_tuple);
  else if (atom_equals (fun, "vgrename"))
    return run_vgrename (args_tuple);
  else if (atom_equals (fun, "vgs"))
    return run_vgs (args_tuple);
  else if (atom_equals (fun, "vgs_full"))
    return run_vgs_full (args_tuple);
  else if (atom_equals (fun, "vgscan"))
    return run_vgscan (args_tuple);
  else if (atom_equals (fun, "vguuid"))
    return run_vguuid (args_tuple);
  else if (atom_equals (fun, "wait_ready"))
    return run_wait_ready (args_tuple);
  else if (atom_equals (fun, "wc_c"))
    return run_wc_c (args_tuple);
  else if (atom_equals (fun, "wc_l"))
    return run_wc_l (args_tuple);
  else if (atom_equals (fun, "wc_w"))
    return run_wc_w (args_tuple);
  else if (atom_equals (fun, "wipefs"))
    return run_wipefs (args_tuple);
  else if (atom_equals (fun, "write"))
    return run_write (args_tuple);
  else if (atom_equals (fun, "write_append"))
    return run_write_append (args_tuple);
  else if (atom_equals (fun, "write_file"))
    return run_write_file (args_tuple);
  else if (atom_equals (fun, "xfs_admin"))
    return run_xfs_admin (args_tuple);
  else if (atom_equals (fun, "xfs_growfs"))
    return run_xfs_growfs (args_tuple);
  else if (atom_equals (fun, "xfs_info"))
    return run_xfs_info (args_tuple);
  else if (atom_equals (fun, "xfs_repair"))
    return run_xfs_repair (args_tuple);
  else if (atom_equals (fun, "zegrep"))
    return run_zegrep (args_tuple);
  else if (atom_equals (fun, "zegrepi"))
    return run_zegrepi (args_tuple);
  else if (atom_equals (fun, "zero"))
    return run_zero (args_tuple);
  else if (atom_equals (fun, "zero_device"))
    return run_zero_device (args_tuple);
  else if (atom_equals (fun, "zero_free_space"))
    return run_zero_free_space (args_tuple);
  else if (atom_equals (fun, "zerofree"))
    return run_zerofree (args_tuple);
  else if (atom_equals (fun, "zfgrep"))
    return run_zfgrep (args_tuple);
  else if (atom_equals (fun, "zfgrepi"))
    return run_zfgrepi (args_tuple);
  else if (atom_equals (fun, "zfile"))
    return run_zfile (args_tuple);
  else if (atom_equals (fun, "zgrep"))
    return run_zgrep (args_tuple);
  else if (atom_equals (fun, "zgrepi"))
    return run_zgrepi (args_tuple);
  else return unknown_function (fun);
}
