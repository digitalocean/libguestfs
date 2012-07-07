/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

/* NOTE: Be very careful with all macros in PHP header files.  The
 * morons who wrote them aren't good at making them safe for inclusion
 * in arbitrary places in C code, eg. not using 'do ... while(0)'
 * or parenthesizing any of the arguments.
 */

/* NOTE (2): Some parts of the API can't be used on 32 bit platforms.
 * Any 64 bit numbers will be truncated.  There's no easy way around
 * this in PHP.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>

#include <php.h>
#include <php_guestfs_php.h>

#include "guestfs.h"

static int res_guestfs_h;

static void
guestfs_php_handle_dtor (zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
  guestfs_h *g = (guestfs_h *) rsrc->ptr;
  if (g != NULL)
    guestfs_close (g);
}

PHP_MINIT_FUNCTION (guestfs_php)
{
  res_guestfs_h =
    zend_register_list_destructors_ex (guestfs_php_handle_dtor,
    NULL, PHP_GUESTFS_HANDLE_RES_NAME, module_number);
}

static zend_function_entry guestfs_php_functions[] = {
  PHP_FE (guestfs_create, NULL)
  PHP_FE (guestfs_last_error, NULL)
  PHP_FE (guestfs_add_cdrom, NULL)
  PHP_FE (guestfs_add_domain, NULL)
  PHP_FE (guestfs_add_drive, NULL)
  PHP_FE (guestfs_add_drive_opts, NULL)
  PHP_FE (guestfs_add_drive_ro, NULL)
  PHP_FE (guestfs_add_drive_ro_with_if, NULL)
  PHP_FE (guestfs_add_drive_with_if, NULL)
  PHP_FE (guestfs_aug_clear, NULL)
  PHP_FE (guestfs_aug_close, NULL)
  PHP_FE (guestfs_aug_defnode, NULL)
  PHP_FE (guestfs_aug_defvar, NULL)
  PHP_FE (guestfs_aug_get, NULL)
  PHP_FE (guestfs_aug_init, NULL)
  PHP_FE (guestfs_aug_insert, NULL)
  PHP_FE (guestfs_aug_load, NULL)
  PHP_FE (guestfs_aug_ls, NULL)
  PHP_FE (guestfs_aug_match, NULL)
  PHP_FE (guestfs_aug_mv, NULL)
  PHP_FE (guestfs_aug_rm, NULL)
  PHP_FE (guestfs_aug_save, NULL)
  PHP_FE (guestfs_aug_set, NULL)
  PHP_FE (guestfs_available, NULL)
  PHP_FE (guestfs_available_all_groups, NULL)
  PHP_FE (guestfs_base64_in, NULL)
  PHP_FE (guestfs_base64_out, NULL)
  PHP_FE (guestfs_blkid, NULL)
  PHP_FE (guestfs_blockdev_flushbufs, NULL)
  PHP_FE (guestfs_blockdev_getbsz, NULL)
  PHP_FE (guestfs_blockdev_getro, NULL)
  PHP_FE (guestfs_blockdev_getsize64, NULL)
  PHP_FE (guestfs_blockdev_getss, NULL)
  PHP_FE (guestfs_blockdev_getsz, NULL)
  PHP_FE (guestfs_blockdev_rereadpt, NULL)
  PHP_FE (guestfs_blockdev_setbsz, NULL)
  PHP_FE (guestfs_blockdev_setro, NULL)
  PHP_FE (guestfs_blockdev_setrw, NULL)
  PHP_FE (guestfs_btrfs_device_add, NULL)
  PHP_FE (guestfs_btrfs_device_delete, NULL)
  PHP_FE (guestfs_btrfs_filesystem_balance, NULL)
  PHP_FE (guestfs_btrfs_filesystem_resize, NULL)
  PHP_FE (guestfs_btrfs_filesystem_sync, NULL)
  PHP_FE (guestfs_btrfs_fsck, NULL)
  PHP_FE (guestfs_btrfs_set_seeding, NULL)
  PHP_FE (guestfs_btrfs_subvolume_create, NULL)
  PHP_FE (guestfs_btrfs_subvolume_delete, NULL)
  PHP_FE (guestfs_btrfs_subvolume_list, NULL)
  PHP_FE (guestfs_btrfs_subvolume_set_default, NULL)
  PHP_FE (guestfs_btrfs_subvolume_snapshot, NULL)
  PHP_FE (guestfs_case_sensitive_path, NULL)
  PHP_FE (guestfs_cat, NULL)
  PHP_FE (guestfs_checksum, NULL)
  PHP_FE (guestfs_checksum_device, NULL)
  PHP_FE (guestfs_checksums_out, NULL)
  PHP_FE (guestfs_chmod, NULL)
  PHP_FE (guestfs_chown, NULL)
  PHP_FE (guestfs_command, NULL)
  PHP_FE (guestfs_command_lines, NULL)
  PHP_FE (guestfs_compress_device_out, NULL)
  PHP_FE (guestfs_compress_out, NULL)
  PHP_FE (guestfs_config, NULL)
  PHP_FE (guestfs_copy_device_to_device, NULL)
  PHP_FE (guestfs_copy_device_to_file, NULL)
  PHP_FE (guestfs_copy_file_to_device, NULL)
  PHP_FE (guestfs_copy_file_to_file, NULL)
  PHP_FE (guestfs_copy_size, NULL)
  PHP_FE (guestfs_cp, NULL)
  PHP_FE (guestfs_cp_a, NULL)
  PHP_FE (guestfs_dd, NULL)
  PHP_FE (guestfs_debug, NULL)
  PHP_FE (guestfs_debug_cmdline, NULL)
  PHP_FE (guestfs_debug_drives, NULL)
  PHP_FE (guestfs_debug_upload, NULL)
  PHP_FE (guestfs_device_index, NULL)
  PHP_FE (guestfs_df, NULL)
  PHP_FE (guestfs_df_h, NULL)
  PHP_FE (guestfs_dmesg, NULL)
  PHP_FE (guestfs_download, NULL)
  PHP_FE (guestfs_download_offset, NULL)
  PHP_FE (guestfs_drop_caches, NULL)
  PHP_FE (guestfs_du, NULL)
  PHP_FE (guestfs_e2fsck, NULL)
  PHP_FE (guestfs_e2fsck_f, NULL)
  PHP_FE (guestfs_echo_daemon, NULL)
  PHP_FE (guestfs_egrep, NULL)
  PHP_FE (guestfs_egrepi, NULL)
  PHP_FE (guestfs_equal, NULL)
  PHP_FE (guestfs_exists, NULL)
  PHP_FE (guestfs_fallocate, NULL)
  PHP_FE (guestfs_fallocate64, NULL)
  PHP_FE (guestfs_fgrep, NULL)
  PHP_FE (guestfs_fgrepi, NULL)
  PHP_FE (guestfs_file, NULL)
  PHP_FE (guestfs_file_architecture, NULL)
  PHP_FE (guestfs_filesize, NULL)
  PHP_FE (guestfs_fill, NULL)
  PHP_FE (guestfs_fill_pattern, NULL)
  PHP_FE (guestfs_find, NULL)
  PHP_FE (guestfs_find0, NULL)
  PHP_FE (guestfs_findfs_label, NULL)
  PHP_FE (guestfs_findfs_uuid, NULL)
  PHP_FE (guestfs_fsck, NULL)
  PHP_FE (guestfs_get_append, NULL)
  PHP_FE (guestfs_get_attach_method, NULL)
  PHP_FE (guestfs_get_autosync, NULL)
  PHP_FE (guestfs_get_direct, NULL)
  PHP_FE (guestfs_get_e2attrs, NULL)
  PHP_FE (guestfs_get_e2generation, NULL)
  PHP_FE (guestfs_get_e2label, NULL)
  PHP_FE (guestfs_get_e2uuid, NULL)
  PHP_FE (guestfs_get_memsize, NULL)
  PHP_FE (guestfs_get_network, NULL)
  PHP_FE (guestfs_get_path, NULL)
  PHP_FE (guestfs_get_pgroup, NULL)
  PHP_FE (guestfs_get_pid, NULL)
  PHP_FE (guestfs_get_qemu, NULL)
  PHP_FE (guestfs_get_recovery_proc, NULL)
  PHP_FE (guestfs_get_selinux, NULL)
  PHP_FE (guestfs_get_smp, NULL)
  PHP_FE (guestfs_get_state, NULL)
  PHP_FE (guestfs_get_trace, NULL)
  PHP_FE (guestfs_get_umask, NULL)
  PHP_FE (guestfs_get_verbose, NULL)
  PHP_FE (guestfs_getcon, NULL)
  PHP_FE (guestfs_getxattr, NULL)
  PHP_FE (guestfs_getxattrs, NULL)
  PHP_FE (guestfs_glob_expand, NULL)
  PHP_FE (guestfs_grep, NULL)
  PHP_FE (guestfs_grepi, NULL)
  PHP_FE (guestfs_grub_install, NULL)
  PHP_FE (guestfs_head, NULL)
  PHP_FE (guestfs_head_n, NULL)
  PHP_FE (guestfs_hexdump, NULL)
  PHP_FE (guestfs_initrd_cat, NULL)
  PHP_FE (guestfs_initrd_list, NULL)
  PHP_FE (guestfs_inotify_add_watch, NULL)
  PHP_FE (guestfs_inotify_close, NULL)
  PHP_FE (guestfs_inotify_files, NULL)
  PHP_FE (guestfs_inotify_init, NULL)
  PHP_FE (guestfs_inotify_read, NULL)
  PHP_FE (guestfs_inotify_rm_watch, NULL)
  PHP_FE (guestfs_inspect_get_arch, NULL)
  PHP_FE (guestfs_inspect_get_distro, NULL)
  PHP_FE (guestfs_inspect_get_drive_mappings, NULL)
  PHP_FE (guestfs_inspect_get_filesystems, NULL)
  PHP_FE (guestfs_inspect_get_format, NULL)
  PHP_FE (guestfs_inspect_get_hostname, NULL)
  PHP_FE (guestfs_inspect_get_icon, NULL)
  PHP_FE (guestfs_inspect_get_major_version, NULL)
  PHP_FE (guestfs_inspect_get_minor_version, NULL)
  PHP_FE (guestfs_inspect_get_mountpoints, NULL)
  PHP_FE (guestfs_inspect_get_package_format, NULL)
  PHP_FE (guestfs_inspect_get_package_management, NULL)
  PHP_FE (guestfs_inspect_get_product_name, NULL)
  PHP_FE (guestfs_inspect_get_product_variant, NULL)
  PHP_FE (guestfs_inspect_get_roots, NULL)
  PHP_FE (guestfs_inspect_get_type, NULL)
  PHP_FE (guestfs_inspect_get_windows_current_control_set, NULL)
  PHP_FE (guestfs_inspect_get_windows_systemroot, NULL)
  PHP_FE (guestfs_inspect_is_live, NULL)
  PHP_FE (guestfs_inspect_is_multipart, NULL)
  PHP_FE (guestfs_inspect_is_netinst, NULL)
  PHP_FE (guestfs_inspect_list_applications, NULL)
  PHP_FE (guestfs_inspect_os, NULL)
  PHP_FE (guestfs_internal_autosync, NULL)
  PHP_FE (guestfs_is_blockdev, NULL)
  PHP_FE (guestfs_is_busy, NULL)
  PHP_FE (guestfs_is_chardev, NULL)
  PHP_FE (guestfs_is_config, NULL)
  PHP_FE (guestfs_is_dir, NULL)
  PHP_FE (guestfs_is_fifo, NULL)
  PHP_FE (guestfs_is_file, NULL)
  PHP_FE (guestfs_is_launching, NULL)
  PHP_FE (guestfs_is_lv, NULL)
  PHP_FE (guestfs_is_ready, NULL)
  PHP_FE (guestfs_is_socket, NULL)
  PHP_FE (guestfs_is_symlink, NULL)
  PHP_FE (guestfs_is_zero, NULL)
  PHP_FE (guestfs_is_zero_device, NULL)
  PHP_FE (guestfs_isoinfo, NULL)
  PHP_FE (guestfs_isoinfo_device, NULL)
  PHP_FE (guestfs_kill_subprocess, NULL)
  PHP_FE (guestfs_launch, NULL)
  PHP_FE (guestfs_lchown, NULL)
  PHP_FE (guestfs_lgetxattr, NULL)
  PHP_FE (guestfs_lgetxattrs, NULL)
  PHP_FE (guestfs_list_9p, NULL)
  PHP_FE (guestfs_list_devices, NULL)
  PHP_FE (guestfs_list_dm_devices, NULL)
  PHP_FE (guestfs_list_filesystems, NULL)
  PHP_FE (guestfs_list_md_devices, NULL)
  PHP_FE (guestfs_list_partitions, NULL)
  PHP_FE (guestfs_ll, NULL)
  PHP_FE (guestfs_llz, NULL)
  PHP_FE (guestfs_ln, NULL)
  PHP_FE (guestfs_ln_f, NULL)
  PHP_FE (guestfs_ln_s, NULL)
  PHP_FE (guestfs_ln_sf, NULL)
  PHP_FE (guestfs_lremovexattr, NULL)
  PHP_FE (guestfs_ls, NULL)
  PHP_FE (guestfs_lsetxattr, NULL)
  PHP_FE (guestfs_lstat, NULL)
  PHP_FE (guestfs_lstatlist, NULL)
  PHP_FE (guestfs_luks_add_key, NULL)
  PHP_FE (guestfs_luks_close, NULL)
  PHP_FE (guestfs_luks_format, NULL)
  PHP_FE (guestfs_luks_format_cipher, NULL)
  PHP_FE (guestfs_luks_kill_slot, NULL)
  PHP_FE (guestfs_luks_open, NULL)
  PHP_FE (guestfs_luks_open_ro, NULL)
  PHP_FE (guestfs_lvcreate, NULL)
  PHP_FE (guestfs_lvcreate_free, NULL)
  PHP_FE (guestfs_lvm_canonical_lv_name, NULL)
  PHP_FE (guestfs_lvm_clear_filter, NULL)
  PHP_FE (guestfs_lvm_remove_all, NULL)
  PHP_FE (guestfs_lvm_set_filter, NULL)
  PHP_FE (guestfs_lvremove, NULL)
  PHP_FE (guestfs_lvrename, NULL)
  PHP_FE (guestfs_lvresize, NULL)
  PHP_FE (guestfs_lvresize_free, NULL)
  PHP_FE (guestfs_lvs, NULL)
  PHP_FE (guestfs_lvs_full, NULL)
  PHP_FE (guestfs_lvuuid, NULL)
  PHP_FE (guestfs_lxattrlist, NULL)
  PHP_FE (guestfs_md_create, NULL)
  PHP_FE (guestfs_md_detail, NULL)
  PHP_FE (guestfs_md_stat, NULL)
  PHP_FE (guestfs_md_stop, NULL)
  PHP_FE (guestfs_mkdir, NULL)
  PHP_FE (guestfs_mkdir_mode, NULL)
  PHP_FE (guestfs_mkdir_p, NULL)
  PHP_FE (guestfs_mkdtemp, NULL)
  PHP_FE (guestfs_mke2fs_J, NULL)
  PHP_FE (guestfs_mke2fs_JL, NULL)
  PHP_FE (guestfs_mke2fs_JU, NULL)
  PHP_FE (guestfs_mke2journal, NULL)
  PHP_FE (guestfs_mke2journal_L, NULL)
  PHP_FE (guestfs_mke2journal_U, NULL)
  PHP_FE (guestfs_mkfifo, NULL)
  PHP_FE (guestfs_mkfs, NULL)
  PHP_FE (guestfs_mkfs_b, NULL)
  PHP_FE (guestfs_mkfs_btrfs, NULL)
  PHP_FE (guestfs_mkfs_opts, NULL)
  PHP_FE (guestfs_mkmountpoint, NULL)
  PHP_FE (guestfs_mknod, NULL)
  PHP_FE (guestfs_mknod_b, NULL)
  PHP_FE (guestfs_mknod_c, NULL)
  PHP_FE (guestfs_mkswap, NULL)
  PHP_FE (guestfs_mkswap_L, NULL)
  PHP_FE (guestfs_mkswap_U, NULL)
  PHP_FE (guestfs_mkswap_file, NULL)
  PHP_FE (guestfs_modprobe, NULL)
  PHP_FE (guestfs_mount, NULL)
  PHP_FE (guestfs_mount_9p, NULL)
  PHP_FE (guestfs_mount_local, NULL)
  PHP_FE (guestfs_mount_local_run, NULL)
  PHP_FE (guestfs_mount_loop, NULL)
  PHP_FE (guestfs_mount_options, NULL)
  PHP_FE (guestfs_mount_ro, NULL)
  PHP_FE (guestfs_mount_vfs, NULL)
  PHP_FE (guestfs_mountpoints, NULL)
  PHP_FE (guestfs_mounts, NULL)
  PHP_FE (guestfs_mv, NULL)
  PHP_FE (guestfs_nr_devices, NULL)
  PHP_FE (guestfs_ntfs_3g_probe, NULL)
  PHP_FE (guestfs_ntfsclone_in, NULL)
  PHP_FE (guestfs_ntfsclone_out, NULL)
  PHP_FE (guestfs_ntfsfix, NULL)
  PHP_FE (guestfs_ntfsresize, NULL)
  PHP_FE (guestfs_ntfsresize_opts, NULL)
  PHP_FE (guestfs_ntfsresize_size, NULL)
  PHP_FE (guestfs_part_add, NULL)
  PHP_FE (guestfs_part_del, NULL)
  PHP_FE (guestfs_part_disk, NULL)
  PHP_FE (guestfs_part_get_bootable, NULL)
  PHP_FE (guestfs_part_get_mbr_id, NULL)
  PHP_FE (guestfs_part_get_parttype, NULL)
  PHP_FE (guestfs_part_init, NULL)
  PHP_FE (guestfs_part_list, NULL)
  PHP_FE (guestfs_part_set_bootable, NULL)
  PHP_FE (guestfs_part_set_mbr_id, NULL)
  PHP_FE (guestfs_part_set_name, NULL)
  PHP_FE (guestfs_part_to_dev, NULL)
  PHP_FE (guestfs_part_to_partnum, NULL)
  PHP_FE (guestfs_ping_daemon, NULL)
  PHP_FE (guestfs_pread, NULL)
  PHP_FE (guestfs_pread_device, NULL)
  PHP_FE (guestfs_pvcreate, NULL)
  PHP_FE (guestfs_pvremove, NULL)
  PHP_FE (guestfs_pvresize, NULL)
  PHP_FE (guestfs_pvresize_size, NULL)
  PHP_FE (guestfs_pvs, NULL)
  PHP_FE (guestfs_pvs_full, NULL)
  PHP_FE (guestfs_pvuuid, NULL)
  PHP_FE (guestfs_pwrite, NULL)
  PHP_FE (guestfs_pwrite_device, NULL)
  PHP_FE (guestfs_read_file, NULL)
  PHP_FE (guestfs_read_lines, NULL)
  PHP_FE (guestfs_readdir, NULL)
  PHP_FE (guestfs_readlink, NULL)
  PHP_FE (guestfs_readlinklist, NULL)
  PHP_FE (guestfs_realpath, NULL)
  PHP_FE (guestfs_removexattr, NULL)
  PHP_FE (guestfs_resize2fs, NULL)
  PHP_FE (guestfs_resize2fs_M, NULL)
  PHP_FE (guestfs_resize2fs_size, NULL)
  PHP_FE (guestfs_rm, NULL)
  PHP_FE (guestfs_rm_rf, NULL)
  PHP_FE (guestfs_rmdir, NULL)
  PHP_FE (guestfs_rmmountpoint, NULL)
  PHP_FE (guestfs_scrub_device, NULL)
  PHP_FE (guestfs_scrub_file, NULL)
  PHP_FE (guestfs_scrub_freespace, NULL)
  PHP_FE (guestfs_set_append, NULL)
  PHP_FE (guestfs_set_attach_method, NULL)
  PHP_FE (guestfs_set_autosync, NULL)
  PHP_FE (guestfs_set_direct, NULL)
  PHP_FE (guestfs_set_e2attrs, NULL)
  PHP_FE (guestfs_set_e2generation, NULL)
  PHP_FE (guestfs_set_e2label, NULL)
  PHP_FE (guestfs_set_e2uuid, NULL)
  PHP_FE (guestfs_set_label, NULL)
  PHP_FE (guestfs_set_memsize, NULL)
  PHP_FE (guestfs_set_network, NULL)
  PHP_FE (guestfs_set_path, NULL)
  PHP_FE (guestfs_set_pgroup, NULL)
  PHP_FE (guestfs_set_qemu, NULL)
  PHP_FE (guestfs_set_recovery_proc, NULL)
  PHP_FE (guestfs_set_selinux, NULL)
  PHP_FE (guestfs_set_smp, NULL)
  PHP_FE (guestfs_set_trace, NULL)
  PHP_FE (guestfs_set_verbose, NULL)
  PHP_FE (guestfs_setcon, NULL)
  PHP_FE (guestfs_setxattr, NULL)
  PHP_FE (guestfs_sfdisk, NULL)
  PHP_FE (guestfs_sfdiskM, NULL)
  PHP_FE (guestfs_sfdisk_N, NULL)
  PHP_FE (guestfs_sfdisk_disk_geometry, NULL)
  PHP_FE (guestfs_sfdisk_kernel_geometry, NULL)
  PHP_FE (guestfs_sfdisk_l, NULL)
  PHP_FE (guestfs_sh, NULL)
  PHP_FE (guestfs_sh_lines, NULL)
  PHP_FE (guestfs_shutdown, NULL)
  PHP_FE (guestfs_sleep, NULL)
  PHP_FE (guestfs_stat, NULL)
  PHP_FE (guestfs_statvfs, NULL)
  PHP_FE (guestfs_strings, NULL)
  PHP_FE (guestfs_strings_e, NULL)
  PHP_FE (guestfs_swapoff_device, NULL)
  PHP_FE (guestfs_swapoff_file, NULL)
  PHP_FE (guestfs_swapoff_label, NULL)
  PHP_FE (guestfs_swapoff_uuid, NULL)
  PHP_FE (guestfs_swapon_device, NULL)
  PHP_FE (guestfs_swapon_file, NULL)
  PHP_FE (guestfs_swapon_label, NULL)
  PHP_FE (guestfs_swapon_uuid, NULL)
  PHP_FE (guestfs_sync, NULL)
  PHP_FE (guestfs_tail, NULL)
  PHP_FE (guestfs_tail_n, NULL)
  PHP_FE (guestfs_tar_in, NULL)
  PHP_FE (guestfs_tar_out, NULL)
  PHP_FE (guestfs_test0, NULL)
  PHP_FE (guestfs_test0rbool, NULL)
  PHP_FE (guestfs_test0rboolerr, NULL)
  PHP_FE (guestfs_test0rbufferout, NULL)
  PHP_FE (guestfs_test0rbufferouterr, NULL)
  PHP_FE (guestfs_test0rconstoptstring, NULL)
  PHP_FE (guestfs_test0rconstoptstringerr, NULL)
  PHP_FE (guestfs_test0rconststring, NULL)
  PHP_FE (guestfs_test0rconststringerr, NULL)
  PHP_FE (guestfs_test0rhashtable, NULL)
  PHP_FE (guestfs_test0rhashtableerr, NULL)
  PHP_FE (guestfs_test0rint, NULL)
  PHP_FE (guestfs_test0rint64, NULL)
  PHP_FE (guestfs_test0rint64err, NULL)
  PHP_FE (guestfs_test0rinterr, NULL)
  PHP_FE (guestfs_test0rstring, NULL)
  PHP_FE (guestfs_test0rstringerr, NULL)
  PHP_FE (guestfs_test0rstringlist, NULL)
  PHP_FE (guestfs_test0rstringlisterr, NULL)
  PHP_FE (guestfs_test0rstruct, NULL)
  PHP_FE (guestfs_test0rstructerr, NULL)
  PHP_FE (guestfs_test0rstructlist, NULL)
  PHP_FE (guestfs_test0rstructlisterr, NULL)
  PHP_FE (guestfs_tgz_in, NULL)
  PHP_FE (guestfs_tgz_out, NULL)
  PHP_FE (guestfs_touch, NULL)
  PHP_FE (guestfs_truncate, NULL)
  PHP_FE (guestfs_truncate_size, NULL)
  PHP_FE (guestfs_tune2fs, NULL)
  PHP_FE (guestfs_tune2fs_l, NULL)
  PHP_FE (guestfs_txz_in, NULL)
  PHP_FE (guestfs_txz_out, NULL)
  PHP_FE (guestfs_umask, NULL)
  PHP_FE (guestfs_umount, NULL)
  PHP_FE (guestfs_umount_all, NULL)
  PHP_FE (guestfs_umount_local, NULL)
  PHP_FE (guestfs_upload, NULL)
  PHP_FE (guestfs_upload_offset, NULL)
  PHP_FE (guestfs_utimens, NULL)
  PHP_FE (guestfs_version, NULL)
  PHP_FE (guestfs_vfs_label, NULL)
  PHP_FE (guestfs_vfs_type, NULL)
  PHP_FE (guestfs_vfs_uuid, NULL)
  PHP_FE (guestfs_vg_activate, NULL)
  PHP_FE (guestfs_vg_activate_all, NULL)
  PHP_FE (guestfs_vgcreate, NULL)
  PHP_FE (guestfs_vglvuuids, NULL)
  PHP_FE (guestfs_vgmeta, NULL)
  PHP_FE (guestfs_vgpvuuids, NULL)
  PHP_FE (guestfs_vgremove, NULL)
  PHP_FE (guestfs_vgrename, NULL)
  PHP_FE (guestfs_vgs, NULL)
  PHP_FE (guestfs_vgs_full, NULL)
  PHP_FE (guestfs_vgscan, NULL)
  PHP_FE (guestfs_vguuid, NULL)
  PHP_FE (guestfs_wait_ready, NULL)
  PHP_FE (guestfs_wc_c, NULL)
  PHP_FE (guestfs_wc_l, NULL)
  PHP_FE (guestfs_wc_w, NULL)
  PHP_FE (guestfs_wipefs, NULL)
  PHP_FE (guestfs_write, NULL)
  PHP_FE (guestfs_write_append, NULL)
  PHP_FE (guestfs_write_file, NULL)
  PHP_FE (guestfs_zegrep, NULL)
  PHP_FE (guestfs_zegrepi, NULL)
  PHP_FE (guestfs_zero, NULL)
  PHP_FE (guestfs_zero_device, NULL)
  PHP_FE (guestfs_zero_free_space, NULL)
  PHP_FE (guestfs_zerofree, NULL)
  PHP_FE (guestfs_zfgrep, NULL)
  PHP_FE (guestfs_zfgrepi, NULL)
  PHP_FE (guestfs_zfile, NULL)
  PHP_FE (guestfs_zgrep, NULL)
  PHP_FE (guestfs_zgrepi, NULL)
  { NULL, NULL, NULL }
};

zend_module_entry guestfs_php_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
  STANDARD_MODULE_HEADER,
#endif
  PHP_GUESTFS_PHP_EXTNAME,
  guestfs_php_functions,
  PHP_MINIT (guestfs_php),
  NULL,
  NULL,
  NULL,
  NULL,
#if ZEND_MODULE_API_NO >= 20010901
  PHP_GUESTFS_PHP_VERSION,
#endif
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_GUESTFS_PHP
ZEND_GET_MODULE (guestfs_php)
#endif

PHP_FUNCTION (guestfs_create)
{
  guestfs_h *g = guestfs_create ();
  if (g == NULL) {
    RETURN_FALSE;
  }

  guestfs_set_error_handler (g, NULL, NULL);

  ZEND_REGISTER_RESOURCE (return_value, g, res_guestfs_h);
}

PHP_FUNCTION (guestfs_last_error)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
                             &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *err = guestfs_last_error (g);
  if (err) {
    RETURN_STRING (err, 1);
  } else {
    RETURN_NULL ();
  }
}

PHP_FUNCTION (guestfs_add_cdrom)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_cdrom: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_add_cdrom (g, filename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_add_domain)
{
  zval *z_g;
  guestfs_h *g;
  char *dom;
  int dom_size;
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  char *optargs_t_libvirturi = NULL;
  int optargs_t_libvirturi_size = -1;
  zend_bool optargs_t_readonly = -1;
  char *optargs_t_iface = NULL;
  int optargs_t_iface_size = -1;
  zend_bool optargs_t_live = -1;
  zend_bool optargs_t_allowuuid = -1;
  char *optargs_t_readonlydisk = NULL;
  int optargs_t_readonlydisk_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|sbsbbs",
        &z_g, &dom, &dom_size, &optargs_t_libvirturi, &optargs_t_libvirturi_size, &optargs_t_readonly, &optargs_t_iface, &optargs_t_iface_size, &optargs_t_live, &optargs_t_allowuuid, &optargs_t_readonlydisk, &optargs_t_readonlydisk_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (dom) != dom_size) {
    fprintf (stderr, "libguestfs: add_domain: parameter 'dom' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_libvirturi != NULL) {
    optargs_s.libvirturi = optargs_t_libvirturi;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
  }
  if (optargs_t_readonly != ((zend_bool)-1)) {
    optargs_s.readonly = optargs_t_readonly;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
  }
  if (optargs_t_iface != NULL) {
    optargs_s.iface = optargs_t_iface;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
  }
  if (optargs_t_live != ((zend_bool)-1)) {
    optargs_s.live = optargs_t_live;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
  }
  if (optargs_t_allowuuid != ((zend_bool)-1)) {
    optargs_s.allowuuid = optargs_t_allowuuid;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
  }
  if (optargs_t_readonlydisk != NULL) {
    optargs_s.readonlydisk = optargs_t_readonlydisk;
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
  }

  int r;
  r = guestfs_add_domain_argv (g, dom, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_add_drive)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_drive: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_add_drive (g, filename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_add_drive_opts)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  zend_bool optargs_t_readonly = -1;
  char *optargs_t_format = NULL;
  int optargs_t_format_size = -1;
  char *optargs_t_iface = NULL;
  int optargs_t_iface_size = -1;
  char *optargs_t_name = NULL;
  int optargs_t_name_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|bsss",
        &z_g, &filename, &filename_size, &optargs_t_readonly, &optargs_t_format, &optargs_t_format_size, &optargs_t_iface, &optargs_t_iface_size, &optargs_t_name, &optargs_t_name_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_drive_opts: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_readonly != ((zend_bool)-1)) {
    optargs_s.readonly = optargs_t_readonly;
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
  }
  if (optargs_t_format != NULL) {
    optargs_s.format = optargs_t_format;
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
  }
  if (optargs_t_iface != NULL) {
    optargs_s.iface = optargs_t_iface;
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
  }
  if (optargs_t_name != NULL) {
    optargs_s.name = optargs_t_name;
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
  }

  int r;
  r = guestfs_add_drive_opts_argv (g, filename, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_add_drive_ro)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_drive_ro: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_add_drive_ro (g, filename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_add_drive_ro_with_if)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *iface;
  int iface_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &filename, &filename_size, &iface, &iface_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_drive_ro_with_if: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (iface) != iface_size) {
    fprintf (stderr, "libguestfs: add_drive_ro_with_if: parameter 'iface' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_add_drive_ro_with_if (g, filename, iface);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_add_drive_with_if)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *iface;
  int iface_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &filename, &filename_size, &iface, &iface_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: add_drive_with_if: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (iface) != iface_size) {
    fprintf (stderr, "libguestfs: add_drive_with_if: parameter 'iface' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_add_drive_with_if (g, filename, iface);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_clear)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &augpath, &augpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_clear: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_clear (g, augpath);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_close)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_close (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_defnode)
{
  zval *z_g;
  guestfs_h *g;
  char *name;
  int name_size;
  char *expr;
  int expr_size;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss",
        &z_g, &name, &name_size, &expr, &expr_size, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: aug_defnode: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (expr) != expr_size) {
    fprintf (stderr, "libguestfs: aug_defnode: parameter 'expr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: aug_defnode: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_int_bool *r;
  r = guestfs_aug_defnode (g, name, expr, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_long (return_value, "i", r->i);
  add_assoc_long (return_value, "b", r->b);
  guestfs_free_int_bool (r);
}

PHP_FUNCTION (guestfs_aug_defvar)
{
  zval *z_g;
  guestfs_h *g;
  char *name;
  int name_size;
  char *expr;
  int expr_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss!",
        &z_g, &name, &name_size, &expr, &expr_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: aug_defvar: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (expr) != expr_size) {
    fprintf (stderr, "libguestfs: aug_defvar: parameter 'expr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_defvar (g, name, expr);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_aug_get)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &augpath, &augpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_get: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_aug_get (g, augpath);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_aug_init)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;
  long flags;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &root, &root_size, &flags) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: aug_init: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_init (g, root, flags);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_insert)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;
  char *label;
  int label_size;
  zend_bool before;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssb",
        &z_g, &augpath, &augpath_size, &label, &label_size, &before) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_insert: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: aug_insert: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_insert (g, augpath, label, before);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_load)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_load (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_ls)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &augpath, &augpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_ls: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_aug_ls (g, augpath);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_aug_match)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &augpath, &augpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_match: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_aug_match (g, augpath);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_aug_mv)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &src, &src_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: aug_mv: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: aug_mv: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_mv (g, src, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_rm)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &augpath, &augpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_rm: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_rm (g, augpath);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_aug_save)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_save (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_aug_set)
{
  zval *z_g;
  guestfs_h *g;
  char *augpath;
  int augpath_size;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &augpath, &augpath_size, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (augpath) != augpath_size) {
    fprintf (stderr, "libguestfs: aug_set: parameter 'augpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: aug_set: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_aug_set (g, augpath, val);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_available)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_groups;
  char **groups;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra",
        &z_g, &z_groups) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_groups);
    n = zend_hash_num_elements (a);
    groups = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      groups[c] = Z_STRVAL (t);
      c++;
    }
    groups[c] = NULL;
  }

  int r;
  r = guestfs_available (g, groups);

  {
    size_t c = 0;

    for (c = 0; groups[c] != NULL; ++c)
      efree (groups[c]);
    efree (groups);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_available_all_groups)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_available_all_groups (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_base64_in)
{
  zval *z_g;
  guestfs_h *g;
  char *base64file;
  int base64file_size;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &base64file, &base64file_size, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (base64file) != base64file_size) {
    fprintf (stderr, "libguestfs: base64_in: parameter 'base64file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: base64_in: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_base64_in (g, base64file, filename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_base64_out)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *base64file;
  int base64file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &filename, &filename_size, &base64file, &base64file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: base64_out: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (base64file) != base64file_size) {
    fprintf (stderr, "libguestfs: base64_out: parameter 'base64file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_base64_out (g, filename, base64file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_blkid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blkid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_blkid (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_blockdev_flushbufs)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_flushbufs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_flushbufs (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_blockdev_getbsz)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_getbsz: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_getbsz (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_blockdev_getro)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_getro: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_getro (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_blockdev_getsize64)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_getsize64: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_blockdev_getsize64 (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_blockdev_getss)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_getss: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_getss (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_blockdev_getsz)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_getsz: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_blockdev_getsz (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_blockdev_rereadpt)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_rereadpt: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_rereadpt (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_blockdev_setbsz)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long blocksize;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &blocksize) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_setbsz: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_setbsz (g, device, blocksize);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_blockdev_setro)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_setro: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_setro (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_blockdev_setrw)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: blockdev_setrw: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_blockdev_setrw (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_device_add)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_devices;
  char **devices;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ras",
        &z_g, &z_devices, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_devices);
    n = zend_hash_num_elements (a);
    devices = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      devices[c] = Z_STRVAL (t);
      c++;
    }
    devices[c] = NULL;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_device_add: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_device_add (g, devices, fs);

  {
    size_t c = 0;

    for (c = 0; devices[c] != NULL; ++c)
      efree (devices[c]);
    efree (devices);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_device_delete)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_devices;
  char **devices;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ras",
        &z_g, &z_devices, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_devices);
    n = zend_hash_num_elements (a);
    devices = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      devices[c] = Z_STRVAL (t);
      c++;
    }
    devices[c] = NULL;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_device_delete: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_device_delete (g, devices, fs);

  {
    size_t c = 0;

    for (c = 0; devices[c] != NULL; ++c)
      efree (devices[c]);
    efree (devices);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_filesystem_balance)
{
  zval *z_g;
  guestfs_h *g;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_filesystem_balance: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_filesystem_balance (g, fs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_filesystem_resize)
{
  zval *z_g;
  guestfs_h *g;
  char *mountpoint;
  int mountpoint_size;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  long optargs_t_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|l",
        &z_g, &mountpoint, &mountpoint_size, &optargs_t_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: btrfs_filesystem_resize: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
  }

  int r;
  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_filesystem_sync)
{
  zval *z_g;
  guestfs_h *g;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_filesystem_sync: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_filesystem_sync (g, fs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_fsck)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  long optargs_t_superblock = -1;
  zend_bool optargs_t_repair = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|lb",
        &z_g, &device, &device_size, &optargs_t_superblock, &optargs_t_repair) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: btrfs_fsck: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_superblock != -1) {
    optargs_s.superblock = optargs_t_superblock;
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
  }
  if (optargs_t_repair != ((zend_bool)-1)) {
    optargs_s.repair = optargs_t_repair;
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
  }

  int r;
  r = guestfs_btrfs_fsck_argv (g, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_set_seeding)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  zend_bool seeding;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsb",
        &z_g, &device, &device_size, &seeding) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: btrfs_set_seeding: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_set_seeding (g, device, seeding);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_subvolume_create)
{
  zval *z_g;
  guestfs_h *g;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_create: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_subvolume_create (g, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_subvolume_delete)
{
  zval *z_g;
  guestfs_h *g;
  char *subvolume;
  int subvolume_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &subvolume, &subvolume_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (subvolume) != subvolume_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_delete: parameter 'subvolume' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_subvolume_delete (g, subvolume);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_subvolume_list)
{
  zval *z_g;
  guestfs_h *g;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_list: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_btrfssubvolume_list *r;
  r = guestfs_btrfs_subvolume_list (g, fs);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_long (z_elem, "btrfssubvolume_id", r->val[c].btrfssubvolume_id);
    add_assoc_long (z_elem, "btrfssubvolume_top_level_id", r->val[c].btrfssubvolume_top_level_id);
    add_assoc_string (z_elem, "btrfssubvolume_path", r->val[c].btrfssubvolume_path, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_btrfssubvolume_list (r);
}

PHP_FUNCTION (guestfs_btrfs_subvolume_set_default)
{
  zval *z_g;
  guestfs_h *g;
  long id;
  char *fs;
  int fs_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &id, &fs, &fs_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fs) != fs_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_set_default: parameter 'fs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_subvolume_set_default (g, id, fs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_btrfs_subvolume_snapshot)
{
  zval *z_g;
  guestfs_h *g;
  char *source;
  int source_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &source, &source_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (source) != source_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_snapshot: parameter 'source' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: btrfs_subvolume_snapshot: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_case_sensitive_path)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: case_sensitive_path: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_case_sensitive_path (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_cat)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: cat: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_cat (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_checksum)
{
  zval *z_g;
  guestfs_h *g;
  char *csumtype;
  int csumtype_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &csumtype, &csumtype_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (csumtype) != csumtype_size) {
    fprintf (stderr, "libguestfs: checksum: parameter 'csumtype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: checksum: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_checksum (g, csumtype, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_checksum_device)
{
  zval *z_g;
  guestfs_h *g;
  char *csumtype;
  int csumtype_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &csumtype, &csumtype_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (csumtype) != csumtype_size) {
    fprintf (stderr, "libguestfs: checksum_device: parameter 'csumtype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: checksum_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_checksum_device (g, csumtype, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_checksums_out)
{
  zval *z_g;
  guestfs_h *g;
  char *csumtype;
  int csumtype_size;
  char *directory;
  int directory_size;
  char *sumsfile;
  int sumsfile_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss",
        &z_g, &csumtype, &csumtype_size, &directory, &directory_size, &sumsfile, &sumsfile_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (csumtype) != csumtype_size) {
    fprintf (stderr, "libguestfs: checksums_out: parameter 'csumtype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: checksums_out: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (sumsfile) != sumsfile_size) {
    fprintf (stderr, "libguestfs: checksums_out: parameter 'sumsfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_chmod)
{
  zval *z_g;
  guestfs_h *g;
  long mode;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &mode, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: chmod: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_chmod (g, mode, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_chown)
{
  zval *z_g;
  guestfs_h *g;
  long owner;
  long group;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rlls",
        &z_g, &owner, &group, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: chown: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_chown (g, owner, group, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_command)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_arguments;
  char **arguments;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra",
        &z_g, &z_arguments) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_arguments);
    n = zend_hash_num_elements (a);
    arguments = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      arguments[c] = Z_STRVAL (t);
      c++;
    }
    arguments[c] = NULL;
  }

  char *r;
  r = guestfs_command (g, arguments);

  {
    size_t c = 0;

    for (c = 0; arguments[c] != NULL; ++c)
      efree (arguments[c]);
    efree (arguments);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_command_lines)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_arguments;
  char **arguments;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra",
        &z_g, &z_arguments) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_arguments);
    n = zend_hash_num_elements (a);
    arguments = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      arguments[c] = Z_STRVAL (t);
      c++;
    }
    arguments[c] = NULL;
  }

  char **r;
  r = guestfs_command_lines (g, arguments);

  {
    size_t c = 0;

    for (c = 0; arguments[c] != NULL; ++c)
      efree (arguments[c]);
    efree (arguments);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_compress_device_out)
{
  zval *z_g;
  guestfs_h *g;
  char *ctype;
  int ctype_size;
  char *device;
  int device_size;
  char *zdevice;
  int zdevice_size;
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  long optargs_t_level = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss|l",
        &z_g, &ctype, &ctype_size, &device, &device_size, &zdevice, &zdevice_size, &optargs_t_level) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (ctype) != ctype_size) {
    fprintf (stderr, "libguestfs: compress_device_out: parameter 'ctype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: compress_device_out: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (zdevice) != zdevice_size) {
    fprintf (stderr, "libguestfs: compress_device_out: parameter 'zdevice' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_level != -1) {
    optargs_s.level = optargs_t_level;
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
  }

  int r;
  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_compress_out)
{
  zval *z_g;
  guestfs_h *g;
  char *ctype;
  int ctype_size;
  char *file;
  int file_size;
  char *zfile;
  int zfile_size;
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  long optargs_t_level = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss|l",
        &z_g, &ctype, &ctype_size, &file, &file_size, &zfile, &zfile_size, &optargs_t_level) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (ctype) != ctype_size) {
    fprintf (stderr, "libguestfs: compress_out: parameter 'ctype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: compress_out: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (zfile) != zfile_size) {
    fprintf (stderr, "libguestfs: compress_out: parameter 'zfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_level != -1) {
    optargs_s.level = optargs_t_level;
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
  }

  int r;
  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_config)
{
  zval *z_g;
  guestfs_h *g;
  char *qemuparam;
  int qemuparam_size;
  char *qemuvalue;
  int qemuvalue_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss!",
        &z_g, &qemuparam, &qemuparam_size, &qemuvalue, &qemuvalue_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (qemuparam) != qemuparam_size) {
    fprintf (stderr, "libguestfs: config: parameter 'qemuparam' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (qemuvalue) != qemuvalue_size) {
    fprintf (stderr, "libguestfs: config: parameter 'qemuvalue' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_config (g, qemuparam, qemuvalue);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_copy_device_to_device)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  long optargs_t_srcoffset = -1;
  long optargs_t_destoffset = -1;
  long optargs_t_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|lll",
        &z_g, &src, &src_size, &dest, &dest_size, &optargs_t_srcoffset, &optargs_t_destoffset, &optargs_t_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: copy_device_to_device: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: copy_device_to_device: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_srcoffset != -1) {
    optargs_s.srcoffset = optargs_t_srcoffset;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  if (optargs_t_destoffset != -1) {
    optargs_s.destoffset = optargs_t_destoffset;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
  }

  int r;
  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_copy_device_to_file)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  long optargs_t_srcoffset = -1;
  long optargs_t_destoffset = -1;
  long optargs_t_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|lll",
        &z_g, &src, &src_size, &dest, &dest_size, &optargs_t_srcoffset, &optargs_t_destoffset, &optargs_t_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: copy_device_to_file: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: copy_device_to_file: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_srcoffset != -1) {
    optargs_s.srcoffset = optargs_t_srcoffset;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
  }
  if (optargs_t_destoffset != -1) {
    optargs_s.destoffset = optargs_t_destoffset;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
  }
  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
  }

  int r;
  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_copy_file_to_device)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  long optargs_t_srcoffset = -1;
  long optargs_t_destoffset = -1;
  long optargs_t_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|lll",
        &z_g, &src, &src_size, &dest, &dest_size, &optargs_t_srcoffset, &optargs_t_destoffset, &optargs_t_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: copy_file_to_device: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: copy_file_to_device: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_srcoffset != -1) {
    optargs_s.srcoffset = optargs_t_srcoffset;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  if (optargs_t_destoffset != -1) {
    optargs_s.destoffset = optargs_t_destoffset;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
  }

  int r;
  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_copy_file_to_file)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  long optargs_t_srcoffset = -1;
  long optargs_t_destoffset = -1;
  long optargs_t_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|lll",
        &z_g, &src, &src_size, &dest, &dest_size, &optargs_t_srcoffset, &optargs_t_destoffset, &optargs_t_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: copy_file_to_file: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: copy_file_to_file: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_srcoffset != -1) {
    optargs_s.srcoffset = optargs_t_srcoffset;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
  }
  if (optargs_t_destoffset != -1) {
    optargs_s.destoffset = optargs_t_destoffset;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
  }
  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
  }

  int r;
  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_copy_size)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &src, &src_size, &dest, &dest_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: copy_size: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: copy_size: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_copy_size (g, src, dest, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_cp)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &src, &src_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: cp: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: cp: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_cp (g, src, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_cp_a)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &src, &src_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: cp_a: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: cp_a: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_cp_a (g, src, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_dd)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &src, &src_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: dd: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: dd: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_dd (g, src, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_debug)
{
  zval *z_g;
  guestfs_h *g;
  char *subcmd;
  int subcmd_size;
  zval *z_extraargs;
  char **extraargs;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &subcmd, &subcmd_size, &z_extraargs) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (subcmd) != subcmd_size) {
    fprintf (stderr, "libguestfs: debug: parameter 'subcmd' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_extraargs);
    n = zend_hash_num_elements (a);
    extraargs = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      extraargs[c] = Z_STRVAL (t);
      c++;
    }
    extraargs[c] = NULL;
  }

  char *r;
  r = guestfs_debug (g, subcmd, extraargs);

  {
    size_t c = 0;

    for (c = 0; extraargs[c] != NULL; ++c)
      efree (extraargs[c]);
    efree (extraargs);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_debug_cmdline)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_debug_cmdline (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_debug_drives)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_debug_drives (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_debug_upload)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *tmpname;
  int tmpname_size;
  long mode;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &filename, &filename_size, &tmpname, &tmpname_size, &mode) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: debug_upload: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (tmpname) != tmpname_size) {
    fprintf (stderr, "libguestfs: debug_upload: parameter 'tmpname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_debug_upload (g, filename, tmpname, mode);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_device_index)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: device_index: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_device_index (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_df)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_df (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_df_h)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_df_h (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_dmesg)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_dmesg (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_download)
{
  zval *z_g;
  guestfs_h *g;
  char *remotefilename;
  int remotefilename_size;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &remotefilename, &remotefilename_size, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (remotefilename) != remotefilename_size) {
    fprintf (stderr, "libguestfs: download: parameter 'remotefilename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: download: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_download (g, remotefilename, filename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_download_offset)
{
  zval *z_g;
  guestfs_h *g;
  char *remotefilename;
  int remotefilename_size;
  char *filename;
  int filename_size;
  long offset;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssll",
        &z_g, &remotefilename, &remotefilename_size, &filename, &filename_size, &offset, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (remotefilename) != remotefilename_size) {
    fprintf (stderr, "libguestfs: download_offset: parameter 'remotefilename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: download_offset: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_download_offset (g, remotefilename, filename, offset, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_drop_caches)
{
  zval *z_g;
  guestfs_h *g;
  long whattodrop;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &whattodrop) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_drop_caches (g, whattodrop);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_du)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: du: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_du (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_e2fsck)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  zend_bool optargs_t_correct = -1;
  zend_bool optargs_t_forceall = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|bb",
        &z_g, &device, &device_size, &optargs_t_correct, &optargs_t_forceall) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: e2fsck: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_correct != ((zend_bool)-1)) {
    optargs_s.correct = optargs_t_correct;
    optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
  }
  if (optargs_t_forceall != ((zend_bool)-1)) {
    optargs_s.forceall = optargs_t_forceall;
    optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
  }

  int r;
  r = guestfs_e2fsck_argv (g, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_e2fsck_f)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: e2fsck_f: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_e2fsck_f (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_echo_daemon)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_words;
  char **words;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra",
        &z_g, &z_words) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_words);
    n = zend_hash_num_elements (a);
    words = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      words[c] = Z_STRVAL (t);
      c++;
    }
    words[c] = NULL;
  }

  char *r;
  r = guestfs_echo_daemon (g, words);

  {
    size_t c = 0;

    for (c = 0; words[c] != NULL; ++c)
      efree (words[c]);
    efree (words);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_egrep)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: egrep: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: egrep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_egrep (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_egrepi)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: egrepi: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: egrepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_egrepi (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_equal)
{
  zval *z_g;
  guestfs_h *g;
  char *file1;
  int file1_size;
  char *file2;
  int file2_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &file1, &file1_size, &file2, &file2_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file1) != file1_size) {
    fprintf (stderr, "libguestfs: equal: parameter 'file1' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (file2) != file2_size) {
    fprintf (stderr, "libguestfs: equal: parameter 'file2' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_equal (g, file1, file2);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_exists)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: exists: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_exists (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_fallocate)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long len;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &path, &path_size, &len) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fallocate: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_fallocate (g, path, len);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_fallocate64)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long len;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &path, &path_size, &len) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fallocate64: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_fallocate64 (g, path, len);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_fgrep)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &pattern, &pattern_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: fgrep: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fgrep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_fgrep (g, pattern, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_fgrepi)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &pattern, &pattern_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: fgrepi: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fgrepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_fgrepi (g, pattern, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_file)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: file: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_file (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_file_architecture)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: file_architecture: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_file_architecture (g, filename);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_filesize)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: filesize: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_filesize (g, file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_fill)
{
  zval *z_g;
  guestfs_h *g;
  long c;
  long len;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rlls",
        &z_g, &c, &len, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fill: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_fill (g, c, len, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_fill_pattern)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;
  long len;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsls",
        &z_g, &pattern, &pattern_size, &len, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: fill_pattern: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: fill_pattern: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_fill_pattern (g, pattern, len, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_find)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: find: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_find (g, directory);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_find0)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;
  char *files;
  int files_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &directory, &directory_size, &files, &files_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: find0: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (files) != files_size) {
    fprintf (stderr, "libguestfs: find0: parameter 'files' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_find0 (g, directory, files);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_findfs_label)
{
  zval *z_g;
  guestfs_h *g;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: findfs_label: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_findfs_label (g, label);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_findfs_uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *uuid;
  int uuid_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &uuid, &uuid_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: findfs_uuid: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_findfs_uuid (g, uuid);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_fsck)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &fstype, &fstype_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: fsck: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: fsck: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_fsck (g, fstype, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_append)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_get_append (g);


  if (r) { RETURN_STRING (r, 1); }
  else { RETURN_NULL (); }
}

PHP_FUNCTION (guestfs_get_attach_method)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_get_attach_method (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_get_autosync)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_autosync (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_direct)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_direct (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_e2attrs)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: get_e2attrs: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_get_e2attrs (g, file);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_get_e2generation)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: get_e2generation: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_get_e2generation (g, file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_e2label)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: get_e2label: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_get_e2label (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_get_e2uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: get_e2uuid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_get_e2uuid (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_get_memsize)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_memsize (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_network)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_network (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_path)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_get_path (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  RETURN_STRING (r, 1);
}

PHP_FUNCTION (guestfs_get_pgroup)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_pgroup (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_pid)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_pid (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_qemu)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_get_qemu (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  RETURN_STRING (r, 1);
}

PHP_FUNCTION (guestfs_get_recovery_proc)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_recovery_proc (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_selinux)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_selinux (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_smp)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_smp (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_state)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_state (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_trace)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_trace (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_get_umask)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_umask (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_get_verbose)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_get_verbose (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_getcon)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_getcon (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_getxattr)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *name;
  int name_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &path, &path_size, &name, &name_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: getxattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: getxattr: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_getxattr (g, path, name, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_getxattrs)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: getxattrs: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_xattr_list *r;
  r = guestfs_getxattrs (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "attrname", r->val[c].attrname, 1);
    add_assoc_stringl (z_elem, "attrval", r->val[c].attrval, r->val[c].attrval_len, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_xattr_list (r);
}

PHP_FUNCTION (guestfs_glob_expand)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &pattern, &pattern_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: glob_expand: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_glob_expand (g, pattern);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_grep)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: grep: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: grep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_grep (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_grepi)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: grepi: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: grepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_grepi (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_grub_install)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &root, &root_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: grub_install: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: grub_install: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_grub_install (g, root, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_head)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: head: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_head (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_head_n)
{
  zval *z_g;
  guestfs_h *g;
  long nrlines;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &nrlines, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: head_n: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_head_n (g, nrlines, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_hexdump)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: hexdump: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_hexdump (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_initrd_cat)
{
  zval *z_g;
  guestfs_h *g;
  char *initrdpath;
  int initrdpath_size;
  char *filename;
  int filename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &initrdpath, &initrdpath_size, &filename, &filename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (initrdpath) != initrdpath_size) {
    fprintf (stderr, "libguestfs: initrd_cat: parameter 'initrdpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: initrd_cat: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_initrd_cat (g, initrdpath, filename, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_initrd_list)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: initrd_list: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_initrd_list (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inotify_add_watch)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long mask;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &path, &path_size, &mask) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: inotify_add_watch: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_inotify_add_watch (g, path, mask);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_inotify_close)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inotify_close (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_inotify_files)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inotify_files (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inotify_init)
{
  zval *z_g;
  guestfs_h *g;
  long maxevents;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &maxevents) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inotify_init (g, maxevents);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_inotify_read)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_inotify_event_list *r;
  r = guestfs_inotify_read (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_long (z_elem, "in_wd", r->val[c].in_wd);
    add_assoc_long (z_elem, "in_mask", r->val[c].in_mask);
    add_assoc_long (z_elem, "in_cookie", r->val[c].in_cookie);
    add_assoc_string (z_elem, "in_name", r->val[c].in_name, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_inotify_event_list (r);
}

PHP_FUNCTION (guestfs_inotify_rm_watch)
{
  zval *z_g;
  guestfs_h *g;
  long wd;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &wd) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inotify_rm_watch (g, wd);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_inspect_get_arch)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_arch: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_arch (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_distro)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_distro: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_distro (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_drive_mappings)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_drive_mappings: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inspect_get_drive_mappings (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inspect_get_filesystems)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_filesystems: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inspect_get_filesystems (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inspect_get_format)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_format: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_format (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_hostname)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_hostname: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_hostname (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_icon)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  zend_bool optargs_t_favicon = -1;
  zend_bool optargs_t_highquality = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|bb",
        &z_g, &root, &root_size, &optargs_t_favicon, &optargs_t_highquality) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_icon: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_favicon != ((zend_bool)-1)) {
    optargs_s.favicon = optargs_t_favicon;
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
  }
  if (optargs_t_highquality != ((zend_bool)-1)) {
    optargs_s.highquality = optargs_t_highquality;
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
  }

  char *r;
  size_t size;
  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_major_version)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_major_version: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inspect_get_major_version (g, root);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_inspect_get_minor_version)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_minor_version: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inspect_get_minor_version (g, root);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_inspect_get_mountpoints)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_mountpoints: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inspect_get_mountpoints (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inspect_get_package_format)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_package_format: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_package_format (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_package_management)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_package_management: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_package_management (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_product_name)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_product_name: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_product_name (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_product_variant)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_product_variant: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_product_variant (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_roots)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inspect_get_roots (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_inspect_get_type)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_type: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_type (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_windows_current_control_set)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_windows_current_control_set: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_windows_current_control_set (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_get_windows_systemroot)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_get_windows_systemroot: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_inspect_get_windows_systemroot (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_inspect_is_live)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_is_live: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inspect_is_live (g, root);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_inspect_is_multipart)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_is_multipart: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inspect_is_multipart (g, root);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_inspect_is_netinst)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_is_netinst: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_inspect_is_netinst (g, root);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_inspect_list_applications)
{
  zval *z_g;
  guestfs_h *g;
  char *root;
  int root_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &root, &root_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (root) != root_size) {
    fprintf (stderr, "libguestfs: inspect_list_applications: parameter 'root' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_application_list *r;
  r = guestfs_inspect_list_applications (g, root);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "app_name", r->val[c].app_name, 1);
    add_assoc_string (z_elem, "app_display_name", r->val[c].app_display_name, 1);
    add_assoc_long (z_elem, "app_epoch", r->val[c].app_epoch);
    add_assoc_string (z_elem, "app_version", r->val[c].app_version, 1);
    add_assoc_string (z_elem, "app_release", r->val[c].app_release, 1);
    add_assoc_string (z_elem, "app_install_path", r->val[c].app_install_path, 1);
    add_assoc_string (z_elem, "app_trans_path", r->val[c].app_trans_path, 1);
    add_assoc_string (z_elem, "app_publisher", r->val[c].app_publisher, 1);
    add_assoc_string (z_elem, "app_url", r->val[c].app_url, 1);
    add_assoc_string (z_elem, "app_source_package", r->val[c].app_source_package, 1);
    add_assoc_string (z_elem, "app_summary", r->val[c].app_summary, 1);
    add_assoc_string (z_elem, "app_description", r->val[c].app_description, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_application_list (r);
}

PHP_FUNCTION (guestfs_inspect_os)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_inspect_os (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_internal_autosync)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_internal_autosync (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_is_blockdev)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_blockdev: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_blockdev (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_busy)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_busy (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_chardev)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_chardev: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_chardev (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_config)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_config (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_dir)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_dir: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_dir (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_fifo)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_fifo: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_fifo (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_file)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_file: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_file (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_launching)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_launching (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_lv)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: is_lv: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_lv (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_ready)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_ready (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_socket)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_socket: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_socket (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_symlink)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_symlink: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_symlink (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_zero)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: is_zero: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_zero (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_is_zero_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: is_zero_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_is_zero_device (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_isoinfo)
{
  zval *z_g;
  guestfs_h *g;
  char *isofile;
  int isofile_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &isofile, &isofile_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (isofile) != isofile_size) {
    fprintf (stderr, "libguestfs: isoinfo: parameter 'isofile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_isoinfo *r;
  r = guestfs_isoinfo (g, isofile);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_string (return_value, "iso_system_id", r->iso_system_id, 1);
  add_assoc_string (return_value, "iso_volume_id", r->iso_volume_id, 1);
  add_assoc_long (return_value, "iso_volume_space_size", r->iso_volume_space_size);
  add_assoc_long (return_value, "iso_volume_set_size", r->iso_volume_set_size);
  add_assoc_long (return_value, "iso_volume_sequence_number", r->iso_volume_sequence_number);
  add_assoc_long (return_value, "iso_logical_block_size", r->iso_logical_block_size);
  add_assoc_string (return_value, "iso_volume_set_id", r->iso_volume_set_id, 1);
  add_assoc_string (return_value, "iso_publisher_id", r->iso_publisher_id, 1);
  add_assoc_string (return_value, "iso_data_preparer_id", r->iso_data_preparer_id, 1);
  add_assoc_string (return_value, "iso_application_id", r->iso_application_id, 1);
  add_assoc_string (return_value, "iso_copyright_file_id", r->iso_copyright_file_id, 1);
  add_assoc_string (return_value, "iso_abstract_file_id", r->iso_abstract_file_id, 1);
  add_assoc_string (return_value, "iso_bibliographic_file_id", r->iso_bibliographic_file_id, 1);
  add_assoc_long (return_value, "iso_volume_creation_t", r->iso_volume_creation_t);
  add_assoc_long (return_value, "iso_volume_modification_t", r->iso_volume_modification_t);
  add_assoc_long (return_value, "iso_volume_expiration_t", r->iso_volume_expiration_t);
  add_assoc_long (return_value, "iso_volume_effective_t", r->iso_volume_effective_t);
  guestfs_free_isoinfo (r);
}

PHP_FUNCTION (guestfs_isoinfo_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: isoinfo_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_isoinfo *r;
  r = guestfs_isoinfo_device (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_string (return_value, "iso_system_id", r->iso_system_id, 1);
  add_assoc_string (return_value, "iso_volume_id", r->iso_volume_id, 1);
  add_assoc_long (return_value, "iso_volume_space_size", r->iso_volume_space_size);
  add_assoc_long (return_value, "iso_volume_set_size", r->iso_volume_set_size);
  add_assoc_long (return_value, "iso_volume_sequence_number", r->iso_volume_sequence_number);
  add_assoc_long (return_value, "iso_logical_block_size", r->iso_logical_block_size);
  add_assoc_string (return_value, "iso_volume_set_id", r->iso_volume_set_id, 1);
  add_assoc_string (return_value, "iso_publisher_id", r->iso_publisher_id, 1);
  add_assoc_string (return_value, "iso_data_preparer_id", r->iso_data_preparer_id, 1);
  add_assoc_string (return_value, "iso_application_id", r->iso_application_id, 1);
  add_assoc_string (return_value, "iso_copyright_file_id", r->iso_copyright_file_id, 1);
  add_assoc_string (return_value, "iso_abstract_file_id", r->iso_abstract_file_id, 1);
  add_assoc_string (return_value, "iso_bibliographic_file_id", r->iso_bibliographic_file_id, 1);
  add_assoc_long (return_value, "iso_volume_creation_t", r->iso_volume_creation_t);
  add_assoc_long (return_value, "iso_volume_modification_t", r->iso_volume_modification_t);
  add_assoc_long (return_value, "iso_volume_expiration_t", r->iso_volume_expiration_t);
  add_assoc_long (return_value, "iso_volume_effective_t", r->iso_volume_effective_t);
  guestfs_free_isoinfo (r);
}

PHP_FUNCTION (guestfs_kill_subprocess)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_kill_subprocess (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_launch)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_launch (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lchown)
{
  zval *z_g;
  guestfs_h *g;
  long owner;
  long group;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rlls",
        &z_g, &owner, &group, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lchown: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lchown (g, owner, group, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lgetxattr)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *name;
  int name_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &path, &path_size, &name, &name_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lgetxattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: lgetxattr: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_lgetxattr (g, path, name, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_lgetxattrs)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lgetxattrs: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_xattr_list *r;
  r = guestfs_lgetxattrs (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "attrname", r->val[c].attrname, 1);
    add_assoc_stringl (z_elem, "attrval", r->val[c].attrval, r->val[c].attrval_len, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_xattr_list (r);
}

PHP_FUNCTION (guestfs_list_9p)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_9p (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_list_devices)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_devices (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_list_dm_devices)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_dm_devices (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_list_filesystems)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_filesystems (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_list_md_devices)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_md_devices (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_list_partitions)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_list_partitions (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_ll)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: ll: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_ll (g, directory);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_llz)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: llz: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_llz (g, directory);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_ln)
{
  zval *z_g;
  guestfs_h *g;
  char *target;
  int target_size;
  char *linkname;
  int linkname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &target, &target_size, &linkname, &linkname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (target) != target_size) {
    fprintf (stderr, "libguestfs: ln: parameter 'target' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (linkname) != linkname_size) {
    fprintf (stderr, "libguestfs: ln: parameter 'linkname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ln (g, target, linkname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ln_f)
{
  zval *z_g;
  guestfs_h *g;
  char *target;
  int target_size;
  char *linkname;
  int linkname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &target, &target_size, &linkname, &linkname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (target) != target_size) {
    fprintf (stderr, "libguestfs: ln_f: parameter 'target' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (linkname) != linkname_size) {
    fprintf (stderr, "libguestfs: ln_f: parameter 'linkname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ln_f (g, target, linkname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ln_s)
{
  zval *z_g;
  guestfs_h *g;
  char *target;
  int target_size;
  char *linkname;
  int linkname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &target, &target_size, &linkname, &linkname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (target) != target_size) {
    fprintf (stderr, "libguestfs: ln_s: parameter 'target' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (linkname) != linkname_size) {
    fprintf (stderr, "libguestfs: ln_s: parameter 'linkname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ln_s (g, target, linkname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ln_sf)
{
  zval *z_g;
  guestfs_h *g;
  char *target;
  int target_size;
  char *linkname;
  int linkname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &target, &target_size, &linkname, &linkname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (target) != target_size) {
    fprintf (stderr, "libguestfs: ln_sf: parameter 'target' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (linkname) != linkname_size) {
    fprintf (stderr, "libguestfs: ln_sf: parameter 'linkname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ln_sf (g, target, linkname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lremovexattr)
{
  zval *z_g;
  guestfs_h *g;
  char *xattr;
  int xattr_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &xattr, &xattr_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (xattr) != xattr_size) {
    fprintf (stderr, "libguestfs: lremovexattr: parameter 'xattr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lremovexattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lremovexattr (g, xattr, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ls)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: ls: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_ls (g, directory);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_lsetxattr)
{
  zval *z_g;
  guestfs_h *g;
  char *xattr;
  int xattr_size;
  char *val;
  int val_size;
  long vallen;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssls",
        &z_g, &xattr, &xattr_size, &val, &val_size, &vallen, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (xattr) != xattr_size) {
    fprintf (stderr, "libguestfs: lsetxattr: parameter 'xattr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: lsetxattr: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lsetxattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lsetxattr (g, xattr, val, vallen, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lstat)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lstat: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_stat *r;
  r = guestfs_lstat (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_long (return_value, "dev", r->dev);
  add_assoc_long (return_value, "ino", r->ino);
  add_assoc_long (return_value, "mode", r->mode);
  add_assoc_long (return_value, "nlink", r->nlink);
  add_assoc_long (return_value, "uid", r->uid);
  add_assoc_long (return_value, "gid", r->gid);
  add_assoc_long (return_value, "rdev", r->rdev);
  add_assoc_long (return_value, "size", r->size);
  add_assoc_long (return_value, "blksize", r->blksize);
  add_assoc_long (return_value, "blocks", r->blocks);
  add_assoc_long (return_value, "atime", r->atime);
  add_assoc_long (return_value, "mtime", r->mtime);
  add_assoc_long (return_value, "ctime", r->ctime);
  guestfs_free_stat (r);
}

PHP_FUNCTION (guestfs_lstatlist)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  zval *z_names;
  char **names;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &path, &path_size, &z_names) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lstatlist: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_names);
    n = zend_hash_num_elements (a);
    names = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      names[c] = Z_STRVAL (t);
      c++;
    }
    names[c] = NULL;
  }

  struct guestfs_stat_list *r;
  r = guestfs_lstatlist (g, path, names);

  {
    size_t c = 0;

    for (c = 0; names[c] != NULL; ++c)
      efree (names[c]);
    efree (names);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_long (z_elem, "dev", r->val[c].dev);
    add_assoc_long (z_elem, "ino", r->val[c].ino);
    add_assoc_long (z_elem, "mode", r->val[c].mode);
    add_assoc_long (z_elem, "nlink", r->val[c].nlink);
    add_assoc_long (z_elem, "uid", r->val[c].uid);
    add_assoc_long (z_elem, "gid", r->val[c].gid);
    add_assoc_long (z_elem, "rdev", r->val[c].rdev);
    add_assoc_long (z_elem, "size", r->val[c].size);
    add_assoc_long (z_elem, "blksize", r->val[c].blksize);
    add_assoc_long (z_elem, "blocks", r->val[c].blocks);
    add_assoc_long (z_elem, "atime", r->val[c].atime);
    add_assoc_long (z_elem, "mtime", r->val[c].mtime);
    add_assoc_long (z_elem, "ctime", r->val[c].ctime);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_stat_list (r);
}

PHP_FUNCTION (guestfs_luks_add_key)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  char *newkey;
  int newkey_size;
  long keyslot;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsssl",
        &z_g, &device, &device_size, &key, &key_size, &newkey, &newkey_size, &keyslot) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_add_key: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_add_key: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (newkey) != newkey_size) {
    fprintf (stderr, "libguestfs: luks_add_key: parameter 'newkey' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_close)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_close: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_close (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_format)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  long keyslot;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &device, &device_size, &key, &key_size, &keyslot) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_format: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_format: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_format (g, device, key, keyslot);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_format_cipher)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  long keyslot;
  char *cipher;
  int cipher_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssls",
        &z_g, &device, &device_size, &key, &key_size, &keyslot, &cipher, &cipher_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_format_cipher: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_format_cipher: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (cipher) != cipher_size) {
    fprintf (stderr, "libguestfs: luks_format_cipher: parameter 'cipher' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_kill_slot)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  long keyslot;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &device, &device_size, &key, &key_size, &keyslot) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_kill_slot: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_kill_slot: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_kill_slot (g, device, key, keyslot);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_open)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  char *mapname;
  int mapname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss",
        &z_g, &device, &device_size, &key, &key_size, &mapname, &mapname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_open: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_open: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mapname) != mapname_size) {
    fprintf (stderr, "libguestfs: luks_open: parameter 'mapname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_open (g, device, key, mapname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_luks_open_ro)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *key;
  int key_size;
  char *mapname;
  int mapname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss",
        &z_g, &device, &device_size, &key, &key_size, &mapname, &mapname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: luks_open_ro: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (key) != key_size) {
    fprintf (stderr, "libguestfs: luks_open_ro: parameter 'key' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mapname) != mapname_size) {
    fprintf (stderr, "libguestfs: luks_open_ro: parameter 'mapname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_luks_open_ro (g, device, key, mapname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvcreate)
{
  zval *z_g;
  guestfs_h *g;
  char *logvol;
  int logvol_size;
  char *volgroup;
  int volgroup_size;
  long mbytes;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &logvol, &logvol_size, &volgroup, &volgroup_size, &mbytes) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (logvol) != logvol_size) {
    fprintf (stderr, "libguestfs: lvcreate: parameter 'logvol' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (volgroup) != volgroup_size) {
    fprintf (stderr, "libguestfs: lvcreate: parameter 'volgroup' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvcreate_free)
{
  zval *z_g;
  guestfs_h *g;
  char *logvol;
  int logvol_size;
  char *volgroup;
  int volgroup_size;
  long percent;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &logvol, &logvol_size, &volgroup, &volgroup_size, &percent) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (logvol) != logvol_size) {
    fprintf (stderr, "libguestfs: lvcreate_free: parameter 'logvol' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (volgroup) != volgroup_size) {
    fprintf (stderr, "libguestfs: lvcreate_free: parameter 'volgroup' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvm_canonical_lv_name)
{
  zval *z_g;
  guestfs_h *g;
  char *lvname;
  int lvname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &lvname, &lvname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (lvname) != lvname_size) {
    fprintf (stderr, "libguestfs: lvm_canonical_lv_name: parameter 'lvname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_lvm_canonical_lv_name (g, lvname);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_lvm_clear_filter)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvm_clear_filter (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvm_remove_all)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvm_remove_all (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvm_set_filter)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_devices;
  char **devices;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra",
        &z_g, &z_devices) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_devices);
    n = zend_hash_num_elements (a);
    devices = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      devices[c] = Z_STRVAL (t);
      c++;
    }
    devices[c] = NULL;
  }

  int r;
  r = guestfs_lvm_set_filter (g, devices);

  {
    size_t c = 0;

    for (c = 0; devices[c] != NULL; ++c)
      efree (devices[c]);
    efree (devices);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvremove)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: lvremove: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvremove (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvrename)
{
  zval *z_g;
  guestfs_h *g;
  char *logvol;
  int logvol_size;
  char *newlogvol;
  int newlogvol_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &logvol, &logvol_size, &newlogvol, &newlogvol_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (logvol) != logvol_size) {
    fprintf (stderr, "libguestfs: lvrename: parameter 'logvol' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (newlogvol) != newlogvol_size) {
    fprintf (stderr, "libguestfs: lvrename: parameter 'newlogvol' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvrename (g, logvol, newlogvol);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvresize)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long mbytes;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &mbytes) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: lvresize: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvresize (g, device, mbytes);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvresize_free)
{
  zval *z_g;
  guestfs_h *g;
  char *lv;
  int lv_size;
  long percent;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &lv, &lv_size, &percent) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (lv) != lv_size) {
    fprintf (stderr, "libguestfs: lvresize_free: parameter 'lv' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_lvresize_free (g, lv, percent);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_lvs)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_lvs (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_lvs_full)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_lvm_lv_list *r;
  r = guestfs_lvs_full (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "lv_name", r->val[c].lv_name, 1);
    add_assoc_stringl (z_elem, "lv_uuid", r->val[c].lv_uuid, 32, 1);
    add_assoc_string (z_elem, "lv_attr", r->val[c].lv_attr, 1);
    add_assoc_long (z_elem, "lv_major", r->val[c].lv_major);
    add_assoc_long (z_elem, "lv_minor", r->val[c].lv_minor);
    add_assoc_long (z_elem, "lv_kernel_major", r->val[c].lv_kernel_major);
    add_assoc_long (z_elem, "lv_kernel_minor", r->val[c].lv_kernel_minor);
    add_assoc_long (z_elem, "lv_size", r->val[c].lv_size);
    add_assoc_long (z_elem, "seg_count", r->val[c].seg_count);
    add_assoc_string (z_elem, "origin", r->val[c].origin, 1);
    add_assoc_double (z_elem, "snap_percent", r->val[c].snap_percent);
    add_assoc_double (z_elem, "copy_percent", r->val[c].copy_percent);
    add_assoc_string (z_elem, "move_pv", r->val[c].move_pv, 1);
    add_assoc_string (z_elem, "lv_tags", r->val[c].lv_tags, 1);
    add_assoc_string (z_elem, "mirror_log", r->val[c].mirror_log, 1);
    add_assoc_string (z_elem, "modules", r->val[c].modules, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_lvm_lv_list (r);
}

PHP_FUNCTION (guestfs_lvuuid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: lvuuid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_lvuuid (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_lxattrlist)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  zval *z_names;
  char **names;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &path, &path_size, &z_names) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: lxattrlist: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_names);
    n = zend_hash_num_elements (a);
    names = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      names[c] = Z_STRVAL (t);
      c++;
    }
    names[c] = NULL;
  }

  struct guestfs_xattr_list *r;
  r = guestfs_lxattrlist (g, path, names);

  {
    size_t c = 0;

    for (c = 0; names[c] != NULL; ++c)
      efree (names[c]);
    efree (names);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "attrname", r->val[c].attrname, 1);
    add_assoc_stringl (z_elem, "attrval", r->val[c].attrval, r->val[c].attrval_len, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_xattr_list (r);
}

PHP_FUNCTION (guestfs_md_create)
{
  zval *z_g;
  guestfs_h *g;
  char *name;
  int name_size;
  zval *z_devices;
  char **devices;
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  long optargs_t_missingbitmap = -1;
  long optargs_t_nrdevices = -1;
  long optargs_t_spare = -1;
  long optargs_t_chunk = -1;
  char *optargs_t_level = NULL;
  int optargs_t_level_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa|lllls",
        &z_g, &name, &name_size, &z_devices, &optargs_t_missingbitmap, &optargs_t_nrdevices, &optargs_t_spare, &optargs_t_chunk, &optargs_t_level, &optargs_t_level_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: md_create: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_devices);
    n = zend_hash_num_elements (a);
    devices = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      devices[c] = Z_STRVAL (t);
      c++;
    }
    devices[c] = NULL;
  }

  if (optargs_t_missingbitmap != -1) {
    optargs_s.missingbitmap = optargs_t_missingbitmap;
    optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
  }
  if (optargs_t_nrdevices != -1) {
    optargs_s.nrdevices = optargs_t_nrdevices;
    optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
  }
  if (optargs_t_spare != -1) {
    optargs_s.spare = optargs_t_spare;
    optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
  }
  if (optargs_t_chunk != -1) {
    optargs_s.chunk = optargs_t_chunk;
    optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
  }
  if (optargs_t_level != NULL) {
    optargs_s.level = optargs_t_level;
    optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
  }

  int r;
  r = guestfs_md_create_argv (g, name, devices, optargs);

  {
    size_t c = 0;

    for (c = 0; devices[c] != NULL; ++c)
      efree (devices[c]);
    efree (devices);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_md_detail)
{
  zval *z_g;
  guestfs_h *g;
  char *md;
  int md_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &md, &md_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (md) != md_size) {
    fprintf (stderr, "libguestfs: md_detail: parameter 'md' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_md_detail (g, md);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_md_stat)
{
  zval *z_g;
  guestfs_h *g;
  char *md;
  int md_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &md, &md_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (md) != md_size) {
    fprintf (stderr, "libguestfs: md_stat: parameter 'md' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_mdstat_list *r;
  r = guestfs_md_stat (g, md);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "mdstat_device", r->val[c].mdstat_device, 1);
    add_assoc_long (z_elem, "mdstat_index", r->val[c].mdstat_index);
    add_assoc_string (z_elem, "mdstat_flags", r->val[c].mdstat_flags, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_mdstat_list (r);
}

PHP_FUNCTION (guestfs_md_stop)
{
  zval *z_g;
  guestfs_h *g;
  char *md;
  int md_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &md, &md_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (md) != md_size) {
    fprintf (stderr, "libguestfs: md_stop: parameter 'md' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_md_stop (g, md);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkdir)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mkdir: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkdir (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkdir_mode)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long mode;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &path, &path_size, &mode) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mkdir_mode: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkdir_mode (g, path, mode);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkdir_p)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mkdir_p: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkdir_p (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkdtemp)
{
  zval *z_g;
  guestfs_h *g;
  char *tmpl;
  int tmpl_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &tmpl, &tmpl_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (tmpl) != tmpl_size) {
    fprintf (stderr, "libguestfs: mkdtemp: parameter 'tmpl' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_mkdtemp (g, tmpl);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_mke2fs_J)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  long blocksize;
  char *device;
  int device_size;
  char *journal;
  int journal_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rslss",
        &z_g, &fstype, &fstype_size, &blocksize, &device, &device_size, &journal, &journal_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mke2fs_J: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2fs_J: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (journal) != journal_size) {
    fprintf (stderr, "libguestfs: mke2fs_J: parameter 'journal' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mke2fs_JL)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  long blocksize;
  char *device;
  int device_size;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rslss",
        &z_g, &fstype, &fstype_size, &blocksize, &device, &device_size, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mke2fs_JL: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2fs_JL: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: mke2fs_JL: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mke2fs_JU)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  long blocksize;
  char *device;
  int device_size;
  char *uuid;
  int uuid_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rslss",
        &z_g, &fstype, &fstype_size, &blocksize, &device, &device_size, &uuid, &uuid_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mke2fs_JU: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2fs_JU: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: mke2fs_JU: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mke2journal)
{
  zval *z_g;
  guestfs_h *g;
  long blocksize;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &blocksize, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2journal: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2journal (g, blocksize, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mke2journal_L)
{
  zval *z_g;
  guestfs_h *g;
  long blocksize;
  char *label;
  int label_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rlss",
        &z_g, &blocksize, &label, &label_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: mke2journal_L: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2journal_L: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2journal_L (g, blocksize, label, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mke2journal_U)
{
  zval *z_g;
  guestfs_h *g;
  long blocksize;
  char *uuid;
  int uuid_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rlss",
        &z_g, &blocksize, &uuid, &uuid_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: mke2journal_U: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mke2journal_U: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mke2journal_U (g, blocksize, uuid, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkfifo)
{
  zval *z_g;
  guestfs_h *g;
  long mode;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &mode, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mkfifo: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkfifo (g, mode, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkfs)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &fstype, &fstype_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mkfs: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkfs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkfs (g, fstype, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkfs_b)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  long blocksize;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsls",
        &z_g, &fstype, &fstype_size, &blocksize, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mkfs_b: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkfs_b: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkfs_b (g, fstype, blocksize, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkfs_btrfs)
{
  zval *z_g;
  guestfs_h *g;
  zval *z_devices;
  char **devices;
  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  long optargs_t_allocstart = -1;
  long optargs_t_bytecount = -1;
  char *optargs_t_datatype = NULL;
  int optargs_t_datatype_size = -1;
  long optargs_t_leafsize = -1;
  char *optargs_t_label = NULL;
  int optargs_t_label_size = -1;
  char *optargs_t_metadata = NULL;
  int optargs_t_metadata_size = -1;
  long optargs_t_nodesize = -1;
  long optargs_t_sectorsize = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "ra|llslssll",
        &z_g, &z_devices, &optargs_t_allocstart, &optargs_t_bytecount, &optargs_t_datatype, &optargs_t_datatype_size, &optargs_t_leafsize, &optargs_t_label, &optargs_t_label_size, &optargs_t_metadata, &optargs_t_metadata_size, &optargs_t_nodesize, &optargs_t_sectorsize) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_devices);
    n = zend_hash_num_elements (a);
    devices = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      devices[c] = Z_STRVAL (t);
      c++;
    }
    devices[c] = NULL;
  }

  if (optargs_t_allocstart != -1) {
    optargs_s.allocstart = optargs_t_allocstart;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
  }
  if (optargs_t_bytecount != -1) {
    optargs_s.bytecount = optargs_t_bytecount;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
  }
  if (optargs_t_datatype != NULL) {
    optargs_s.datatype = optargs_t_datatype;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
  }
  if (optargs_t_leafsize != -1) {
    optargs_s.leafsize = optargs_t_leafsize;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
  }
  if (optargs_t_label != NULL) {
    optargs_s.label = optargs_t_label;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
  }
  if (optargs_t_metadata != NULL) {
    optargs_s.metadata = optargs_t_metadata;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
  }
  if (optargs_t_nodesize != -1) {
    optargs_s.nodesize = optargs_t_nodesize;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
  }
  if (optargs_t_sectorsize != -1) {
    optargs_s.sectorsize = optargs_t_sectorsize;
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
  }

  int r;
  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);

  {
    size_t c = 0;

    for (c = 0; devices[c] != NULL; ++c)
      efree (devices[c]);
    efree (devices);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkfs_opts)
{
  zval *z_g;
  guestfs_h *g;
  char *fstype;
  int fstype_size;
  char *device;
  int device_size;
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  long optargs_t_blocksize = -1;
  char *optargs_t_features = NULL;
  int optargs_t_features_size = -1;
  long optargs_t_inode = -1;
  long optargs_t_sectorsize = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|lsll",
        &z_g, &fstype, &fstype_size, &device, &device_size, &optargs_t_blocksize, &optargs_t_features, &optargs_t_features_size, &optargs_t_inode, &optargs_t_sectorsize) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (fstype) != fstype_size) {
    fprintf (stderr, "libguestfs: mkfs_opts: parameter 'fstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkfs_opts: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_blocksize != -1) {
    optargs_s.blocksize = optargs_t_blocksize;
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
  }
  if (optargs_t_features != NULL) {
    optargs_s.features = optargs_t_features;
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
  }
  if (optargs_t_inode != -1) {
    optargs_s.inode = optargs_t_inode;
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
  }
  if (optargs_t_sectorsize != -1) {
    optargs_s.sectorsize = optargs_t_sectorsize;
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
  }

  int r;
  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkmountpoint)
{
  zval *z_g;
  guestfs_h *g;
  char *exemptpath;
  int exemptpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &exemptpath, &exemptpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (exemptpath) != exemptpath_size) {
    fprintf (stderr, "libguestfs: mkmountpoint: parameter 'exemptpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkmountpoint (g, exemptpath);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mknod)
{
  zval *z_g;
  guestfs_h *g;
  long mode;
  long devmajor;
  long devminor;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rllls",
        &z_g, &mode, &devmajor, &devminor, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mknod: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mknod (g, mode, devmajor, devminor, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mknod_b)
{
  zval *z_g;
  guestfs_h *g;
  long mode;
  long devmajor;
  long devminor;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rllls",
        &z_g, &mode, &devmajor, &devminor, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mknod_b: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mknod_c)
{
  zval *z_g;
  guestfs_h *g;
  long mode;
  long devmajor;
  long devminor;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rllls",
        &z_g, &mode, &devmajor, &devminor, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mknod_c: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkswap)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkswap: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkswap (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkswap_L)
{
  zval *z_g;
  guestfs_h *g;
  char *label;
  int label_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &label, &label_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: mkswap_L: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkswap_L: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkswap_L (g, label, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkswap_U)
{
  zval *z_g;
  guestfs_h *g;
  char *uuid;
  int uuid_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &uuid, &uuid_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: mkswap_U: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mkswap_U: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkswap_U (g, uuid, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mkswap_file)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: mkswap_file: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mkswap_file (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_modprobe)
{
  zval *z_g;
  guestfs_h *g;
  char *modulename;
  int modulename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &modulename, &modulename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (modulename) != modulename_size) {
    fprintf (stderr, "libguestfs: modprobe: parameter 'modulename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_modprobe (g, modulename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *mountpoint;
  int mountpoint_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &mountpoint, &mountpoint_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mount: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount (g, device, mountpoint);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_9p)
{
  zval *z_g;
  guestfs_h *g;
  char *mounttag;
  int mounttag_size;
  char *mountpoint;
  int mountpoint_size;
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  char *optargs_t_options = NULL;
  int optargs_t_options_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|s",
        &z_g, &mounttag, &mounttag_size, &mountpoint, &mountpoint_size, &optargs_t_options, &optargs_t_options_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (mounttag) != mounttag_size) {
    fprintf (stderr, "libguestfs: mount_9p: parameter 'mounttag' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount_9p: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_options != NULL) {
    optargs_s.options = optargs_t_options;
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
  }

  int r;
  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_local)
{
  zval *z_g;
  guestfs_h *g;
  char *localmountpoint;
  int localmountpoint_size;
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  zend_bool optargs_t_readonly = -1;
  char *optargs_t_options = NULL;
  int optargs_t_options_size = -1;
  long optargs_t_cachetimeout = -1;
  zend_bool optargs_t_debugcalls = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|bslb",
        &z_g, &localmountpoint, &localmountpoint_size, &optargs_t_readonly, &optargs_t_options, &optargs_t_options_size, &optargs_t_cachetimeout, &optargs_t_debugcalls) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (localmountpoint) != localmountpoint_size) {
    fprintf (stderr, "libguestfs: mount_local: parameter 'localmountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_readonly != ((zend_bool)-1)) {
    optargs_s.readonly = optargs_t_readonly;
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
  }
  if (optargs_t_options != NULL) {
    optargs_s.options = optargs_t_options;
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
  }
  if (optargs_t_cachetimeout != -1) {
    optargs_s.cachetimeout = optargs_t_cachetimeout;
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
  }
  if (optargs_t_debugcalls != ((zend_bool)-1)) {
    optargs_s.debugcalls = optargs_t_debugcalls;
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
  }

  int r;
  r = guestfs_mount_local_argv (g, localmountpoint, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_local_run)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount_local_run (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_loop)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;
  char *mountpoint;
  int mountpoint_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &file, &file_size, &mountpoint, &mountpoint_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: mount_loop: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount_loop: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount_loop (g, file, mountpoint);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_options)
{
  zval *z_g;
  guestfs_h *g;
  char *options;
  int options_size;
  char *device;
  int device_size;
  char *mountpoint;
  int mountpoint_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsss",
        &z_g, &options, &options_size, &device, &device_size, &mountpoint, &mountpoint_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (options) != options_size) {
    fprintf (stderr, "libguestfs: mount_options: parameter 'options' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mount_options: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount_options: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount_options (g, options, device, mountpoint);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_ro)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *mountpoint;
  int mountpoint_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &mountpoint, &mountpoint_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mount_ro: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount_ro: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount_ro (g, device, mountpoint);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mount_vfs)
{
  zval *z_g;
  guestfs_h *g;
  char *options;
  int options_size;
  char *vfstype;
  int vfstype_size;
  char *device;
  int device_size;
  char *mountpoint;
  int mountpoint_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssss",
        &z_g, &options, &options_size, &vfstype, &vfstype_size, &device, &device_size, &mountpoint, &mountpoint_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (options) != options_size) {
    fprintf (stderr, "libguestfs: mount_vfs: parameter 'options' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (vfstype) != vfstype_size) {
    fprintf (stderr, "libguestfs: mount_vfs: parameter 'vfstype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: mount_vfs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (mountpoint) != mountpoint_size) {
    fprintf (stderr, "libguestfs: mount_vfs: parameter 'mountpoint' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_mountpoints)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_mountpoints (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_mounts)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_mounts (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_mv)
{
  zval *z_g;
  guestfs_h *g;
  char *src;
  int src_size;
  char *dest;
  int dest_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &src, &src_size, &dest, &dest_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (src) != src_size) {
    fprintf (stderr, "libguestfs: mv: parameter 'src' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (dest) != dest_size) {
    fprintf (stderr, "libguestfs: mv: parameter 'dest' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_mv (g, src, dest);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_nr_devices)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_nr_devices (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_ntfs_3g_probe)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool rw;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rbs",
        &z_g, &rw, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfs_3g_probe: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ntfs_3g_probe (g, rw, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_ntfsclone_in)
{
  zval *z_g;
  guestfs_h *g;
  char *backupfile;
  int backupfile_size;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &backupfile, &backupfile_size, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (backupfile) != backupfile_size) {
    fprintf (stderr, "libguestfs: ntfsclone_in: parameter 'backupfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsclone_in: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ntfsclone_in (g, backupfile, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ntfsclone_out)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *backupfile;
  int backupfile_size;
  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  zend_bool optargs_t_metadataonly = -1;
  zend_bool optargs_t_rescue = -1;
  zend_bool optargs_t_ignorefscheck = -1;
  zend_bool optargs_t_preservetimestamps = -1;
  zend_bool optargs_t_force = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|bbbbb",
        &z_g, &device, &device_size, &backupfile, &backupfile_size, &optargs_t_metadataonly, &optargs_t_rescue, &optargs_t_ignorefscheck, &optargs_t_preservetimestamps, &optargs_t_force) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsclone_out: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (backupfile) != backupfile_size) {
    fprintf (stderr, "libguestfs: ntfsclone_out: parameter 'backupfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_metadataonly != ((zend_bool)-1)) {
    optargs_s.metadataonly = optargs_t_metadataonly;
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
  }
  if (optargs_t_rescue != ((zend_bool)-1)) {
    optargs_s.rescue = optargs_t_rescue;
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
  }
  if (optargs_t_ignorefscheck != ((zend_bool)-1)) {
    optargs_s.ignorefscheck = optargs_t_ignorefscheck;
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
  }
  if (optargs_t_preservetimestamps != ((zend_bool)-1)) {
    optargs_s.preservetimestamps = optargs_t_preservetimestamps;
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
  }
  if (optargs_t_force != ((zend_bool)-1)) {
    optargs_s.force = optargs_t_force;
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
  }

  int r;
  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ntfsfix)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  zend_bool optargs_t_clearbadsectors = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|b",
        &z_g, &device, &device_size, &optargs_t_clearbadsectors) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsfix: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_clearbadsectors != ((zend_bool)-1)) {
    optargs_s.clearbadsectors = optargs_t_clearbadsectors;
    optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
  }

  int r;
  r = guestfs_ntfsfix_argv (g, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ntfsresize)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsresize: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ntfsresize (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ntfsresize_opts)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  long optargs_t_size = -1;
  zend_bool optargs_t_force = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|lb",
        &z_g, &device, &device_size, &optargs_t_size, &optargs_t_force) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsresize_opts: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_size != -1) {
    optargs_s.size = optargs_t_size;
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
  }
  if (optargs_t_force != ((zend_bool)-1)) {
    optargs_s.force = optargs_t_force;
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
  }

  int r;
  r = guestfs_ntfsresize_opts_argv (g, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_ntfsresize_size)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: ntfsresize_size: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ntfsresize_size (g, device, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_add)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *prlogex;
  int prlogex_size;
  long startsect;
  long endsect;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssll",
        &z_g, &device, &device_size, &prlogex, &prlogex_size, &startsect, &endsect) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_add: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (prlogex) != prlogex_size) {
    fprintf (stderr, "libguestfs: part_add: parameter 'prlogex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_add (g, device, prlogex, startsect, endsect);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_del)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &partnum) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_del: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_del (g, device, partnum);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_disk)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *parttype;
  int parttype_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &parttype, &parttype_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_disk: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (parttype) != parttype_size) {
    fprintf (stderr, "libguestfs: part_disk: parameter 'parttype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_disk (g, device, parttype);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_get_bootable)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &partnum) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_get_bootable: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_get_bootable (g, device, partnum);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_part_get_mbr_id)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &partnum) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_get_mbr_id: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_get_mbr_id (g, device, partnum);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_part_get_parttype)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_get_parttype: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_part_get_parttype (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_part_init)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *parttype;
  int parttype_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &parttype, &parttype_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_init: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (parttype) != parttype_size) {
    fprintf (stderr, "libguestfs: part_init: parameter 'parttype' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_init (g, device, parttype);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_list)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_list: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_partition_list *r;
  r = guestfs_part_list (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_long (z_elem, "part_num", r->val[c].part_num);
    add_assoc_long (z_elem, "part_start", r->val[c].part_start);
    add_assoc_long (z_elem, "part_end", r->val[c].part_end);
    add_assoc_long (z_elem, "part_size", r->val[c].part_size);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_partition_list (r);
}

PHP_FUNCTION (guestfs_part_set_bootable)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;
  zend_bool bootable;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rslb",
        &z_g, &device, &device_size, &partnum, &bootable) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_set_bootable: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_set_bootable (g, device, partnum, bootable);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_set_mbr_id)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;
  long idbyte;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsll",
        &z_g, &device, &device_size, &partnum, &idbyte) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_set_mbr_id: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_set_name)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;
  char *name;
  int name_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsls",
        &z_g, &device, &device_size, &partnum, &name, &name_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: part_set_name: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (name) != name_size) {
    fprintf (stderr, "libguestfs: part_set_name: parameter 'name' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_set_name (g, device, partnum, name);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_part_to_dev)
{
  zval *z_g;
  guestfs_h *g;
  char *partition;
  int partition_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &partition, &partition_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (partition) != partition_size) {
    fprintf (stderr, "libguestfs: part_to_dev: parameter 'partition' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_part_to_dev (g, partition);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_part_to_partnum)
{
  zval *z_g;
  guestfs_h *g;
  char *partition;
  int partition_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &partition, &partition_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (partition) != partition_size) {
    fprintf (stderr, "libguestfs: part_to_partnum: parameter 'partition' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_part_to_partnum (g, partition);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_ping_daemon)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_ping_daemon (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_pread)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long count;
  long offset;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsll",
        &z_g, &path, &path_size, &count, &offset) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: pread: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_pread (g, path, count, offset, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_pread_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long count;
  long offset;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsll",
        &z_g, &device, &device_size, &count, &offset) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pread_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_pread_device (g, device, count, offset, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_pvcreate)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pvcreate: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pvcreate (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_pvremove)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pvremove: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pvremove (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_pvresize)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pvresize: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pvresize (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_pvresize_size)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pvresize_size: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pvresize_size (g, device, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_pvs)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_pvs (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_pvs_full)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_lvm_pv_list *r;
  r = guestfs_pvs_full (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "pv_name", r->val[c].pv_name, 1);
    add_assoc_stringl (z_elem, "pv_uuid", r->val[c].pv_uuid, 32, 1);
    add_assoc_string (z_elem, "pv_fmt", r->val[c].pv_fmt, 1);
    add_assoc_long (z_elem, "pv_size", r->val[c].pv_size);
    add_assoc_long (z_elem, "dev_size", r->val[c].dev_size);
    add_assoc_long (z_elem, "pv_free", r->val[c].pv_free);
    add_assoc_long (z_elem, "pv_used", r->val[c].pv_used);
    add_assoc_string (z_elem, "pv_attr", r->val[c].pv_attr, 1);
    add_assoc_long (z_elem, "pv_pe_count", r->val[c].pv_pe_count);
    add_assoc_long (z_elem, "pv_pe_alloc_count", r->val[c].pv_pe_alloc_count);
    add_assoc_string (z_elem, "pv_tags", r->val[c].pv_tags, 1);
    add_assoc_long (z_elem, "pe_start", r->val[c].pe_start);
    add_assoc_long (z_elem, "pv_mda_count", r->val[c].pv_mda_count);
    add_assoc_long (z_elem, "pv_mda_free", r->val[c].pv_mda_free);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_lvm_pv_list (r);
}

PHP_FUNCTION (guestfs_pvuuid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pvuuid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_pvuuid (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_pwrite)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *content;
  int content_size;
  long offset;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &path, &path_size, &content, &content_size, &offset) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: pwrite: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pwrite (g, path, content, content_size, offset);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_pwrite_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *content;
  int content_size;
  long offset;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &device, &device_size, &content, &content_size, &offset) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: pwrite_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_pwrite_device (g, device, content, content_size, offset);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_read_file)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: read_file: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_read_file (g, path, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_read_lines)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: read_lines: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_read_lines (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_readdir)
{
  zval *z_g;
  guestfs_h *g;
  char *dir;
  int dir_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &dir, &dir_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (dir) != dir_size) {
    fprintf (stderr, "libguestfs: readdir: parameter 'dir' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_dirent_list *r;
  r = guestfs_readdir (g, dir);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_long (z_elem, "ino", r->val[c].ino);
    add_assoc_stringl (z_elem, "ftyp", &r->val[c].ftyp, 1, 1);
    add_assoc_string (z_elem, "name", r->val[c].name, 1);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_dirent_list (r);
}

PHP_FUNCTION (guestfs_readlink)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: readlink: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_readlink (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_readlinklist)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  zval *z_names;
  char **names;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &path, &path_size, &z_names) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: readlinklist: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_names);
    n = zend_hash_num_elements (a);
    names = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      names[c] = Z_STRVAL (t);
      c++;
    }
    names[c] = NULL;
  }

  char **r;
  r = guestfs_readlinklist (g, path, names);

  {
    size_t c = 0;

    for (c = 0; names[c] != NULL; ++c)
      efree (names[c]);
    efree (names);
  }

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_realpath)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: realpath: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_realpath (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_removexattr)
{
  zval *z_g;
  guestfs_h *g;
  char *xattr;
  int xattr_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &xattr, &xattr_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (xattr) != xattr_size) {
    fprintf (stderr, "libguestfs: removexattr: parameter 'xattr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: removexattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_removexattr (g, xattr, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_resize2fs)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: resize2fs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_resize2fs (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_resize2fs_M)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: resize2fs_M: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_resize2fs_M (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_resize2fs_size)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &device, &device_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: resize2fs_size: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_resize2fs_size (g, device, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_rm)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: rm: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_rm (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_rm_rf)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: rm_rf: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_rm_rf (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_rmdir)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: rmdir: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_rmdir (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_rmmountpoint)
{
  zval *z_g;
  guestfs_h *g;
  char *exemptpath;
  int exemptpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &exemptpath, &exemptpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (exemptpath) != exemptpath_size) {
    fprintf (stderr, "libguestfs: rmmountpoint: parameter 'exemptpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_rmmountpoint (g, exemptpath);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_scrub_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: scrub_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_scrub_device (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_scrub_file)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: scrub_file: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_scrub_file (g, file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_scrub_freespace)
{
  zval *z_g;
  guestfs_h *g;
  char *dir;
  int dir_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &dir, &dir_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (dir) != dir_size) {
    fprintf (stderr, "libguestfs: scrub_freespace: parameter 'dir' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_scrub_freespace (g, dir);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_append)
{
  zval *z_g;
  guestfs_h *g;
  char *append;
  int append_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs!",
        &z_g, &append, &append_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (append) != append_size) {
    fprintf (stderr, "libguestfs: set_append: parameter 'append' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_append (g, append);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_attach_method)
{
  zval *z_g;
  guestfs_h *g;
  char *attachmethod;
  int attachmethod_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &attachmethod, &attachmethod_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (attachmethod) != attachmethod_size) {
    fprintf (stderr, "libguestfs: set_attach_method: parameter 'attachmethod' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_attach_method (g, attachmethod);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_autosync)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool autosync;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &autosync) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_autosync (g, autosync);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_direct)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool direct;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &direct) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_direct (g, direct);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_e2attrs)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;
  char *attrs;
  int attrs_size;
  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  zend_bool optargs_t_clear = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss|b",
        &z_g, &file, &file_size, &attrs, &attrs_size, &optargs_t_clear) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: set_e2attrs: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (attrs) != attrs_size) {
    fprintf (stderr, "libguestfs: set_e2attrs: parameter 'attrs' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_clear != ((zend_bool)-1)) {
    optargs_s.clear = optargs_t_clear;
    optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
  }

  int r;
  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_e2generation)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;
  long generation;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &file, &file_size, &generation) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: set_e2generation: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_e2generation (g, file, generation);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_e2label)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: set_e2label: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: set_e2label: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_e2label (g, device, label);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_e2uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *uuid;
  int uuid_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &uuid, &uuid_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: set_e2uuid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: set_e2uuid: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_e2uuid (g, device, uuid);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_label)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &device, &device_size, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: set_label: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: set_label: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_label (g, device, label);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_memsize)
{
  zval *z_g;
  guestfs_h *g;
  long memsize;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &memsize) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_memsize (g, memsize);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_network)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool network;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &network) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_network (g, network);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_path)
{
  zval *z_g;
  guestfs_h *g;
  char *searchpath;
  int searchpath_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs!",
        &z_g, &searchpath, &searchpath_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (searchpath) != searchpath_size) {
    fprintf (stderr, "libguestfs: set_path: parameter 'searchpath' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_path (g, searchpath);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_pgroup)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool pgroup;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &pgroup) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_pgroup (g, pgroup);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_qemu)
{
  zval *z_g;
  guestfs_h *g;
  char *qemu;
  int qemu_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs!",
        &z_g, &qemu, &qemu_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (qemu) != qemu_size) {
    fprintf (stderr, "libguestfs: set_qemu: parameter 'qemu' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_qemu (g, qemu);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_recovery_proc)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool recoveryproc;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &recoveryproc) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_recovery_proc (g, recoveryproc);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_selinux)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool selinux;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &selinux) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_selinux (g, selinux);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_smp)
{
  zval *z_g;
  guestfs_h *g;
  long smp;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &smp) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_smp (g, smp);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_trace)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool trace;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &trace) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_trace (g, trace);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_set_verbose)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool verbose;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &verbose) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_set_verbose (g, verbose);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_setcon)
{
  zval *z_g;
  guestfs_h *g;
  char *context;
  int context_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &context, &context_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (context) != context_size) {
    fprintf (stderr, "libguestfs: setcon: parameter 'context' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_setcon (g, context);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_setxattr)
{
  zval *z_g;
  guestfs_h *g;
  char *xattr;
  int xattr_size;
  char *val;
  int val_size;
  long vallen;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssls",
        &z_g, &xattr, &xattr_size, &val, &val_size, &vallen, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (xattr) != xattr_size) {
    fprintf (stderr, "libguestfs: setxattr: parameter 'xattr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: setxattr: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: setxattr: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_setxattr (g, xattr, val, vallen, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sfdisk)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long cyls;
  long heads;
  long sectors;
  zval *z_lines;
  char **lines;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsllla",
        &z_g, &device, &device_size, &cyls, &heads, &sectors, &z_lines) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdisk: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_lines);
    n = zend_hash_num_elements (a);
    lines = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      lines[c] = Z_STRVAL (t);
      c++;
    }
    lines[c] = NULL;
  }

  int r;
  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);

  {
    size_t c = 0;

    for (c = 0; lines[c] != NULL; ++c)
      efree (lines[c]);
    efree (lines);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sfdiskM)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  zval *z_lines;
  char **lines;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &device, &device_size, &z_lines) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdiskM: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_lines);
    n = zend_hash_num_elements (a);
    lines = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      lines[c] = Z_STRVAL (t);
      c++;
    }
    lines[c] = NULL;
  }

  int r;
  r = guestfs_sfdiskM (g, device, lines);

  {
    size_t c = 0;

    for (c = 0; lines[c] != NULL; ++c)
      efree (lines[c]);
    efree (lines);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sfdisk_N)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  long partnum;
  long cyls;
  long heads;
  long sectors;
  char *line;
  int line_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rslllls",
        &z_g, &device, &device_size, &partnum, &cyls, &heads, &sectors, &line, &line_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdisk_N: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (line) != line_size) {
    fprintf (stderr, "libguestfs: sfdisk_N: parameter 'line' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sfdisk_disk_geometry)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdisk_disk_geometry: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_sfdisk_disk_geometry (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_sfdisk_kernel_geometry)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdisk_kernel_geometry: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_sfdisk_kernel_geometry (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_sfdisk_l)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: sfdisk_l: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_sfdisk_l (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_sh)
{
  zval *z_g;
  guestfs_h *g;
  char *command;
  int command_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &command, &command_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (command) != command_size) {
    fprintf (stderr, "libguestfs: sh: parameter 'command' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_sh (g, command);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_sh_lines)
{
  zval *z_g;
  guestfs_h *g;
  char *command;
  int command_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &command, &command_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (command) != command_size) {
    fprintf (stderr, "libguestfs: sh_lines: parameter 'command' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_sh_lines (g, command);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_shutdown)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_shutdown (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sleep)
{
  zval *z_g;
  guestfs_h *g;
  long secs;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &secs) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_sleep (g, secs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_stat)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: stat: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_stat *r;
  r = guestfs_stat (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_long (return_value, "dev", r->dev);
  add_assoc_long (return_value, "ino", r->ino);
  add_assoc_long (return_value, "mode", r->mode);
  add_assoc_long (return_value, "nlink", r->nlink);
  add_assoc_long (return_value, "uid", r->uid);
  add_assoc_long (return_value, "gid", r->gid);
  add_assoc_long (return_value, "rdev", r->rdev);
  add_assoc_long (return_value, "size", r->size);
  add_assoc_long (return_value, "blksize", r->blksize);
  add_assoc_long (return_value, "blocks", r->blocks);
  add_assoc_long (return_value, "atime", r->atime);
  add_assoc_long (return_value, "mtime", r->mtime);
  add_assoc_long (return_value, "ctime", r->ctime);
  guestfs_free_stat (r);
}

PHP_FUNCTION (guestfs_statvfs)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: statvfs: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_statvfs *r;
  r = guestfs_statvfs (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_long (return_value, "bsize", r->bsize);
  add_assoc_long (return_value, "frsize", r->frsize);
  add_assoc_long (return_value, "blocks", r->blocks);
  add_assoc_long (return_value, "bfree", r->bfree);
  add_assoc_long (return_value, "bavail", r->bavail);
  add_assoc_long (return_value, "files", r->files);
  add_assoc_long (return_value, "ffree", r->ffree);
  add_assoc_long (return_value, "favail", r->favail);
  add_assoc_long (return_value, "fsid", r->fsid);
  add_assoc_long (return_value, "flag", r->flag);
  add_assoc_long (return_value, "namemax", r->namemax);
  guestfs_free_statvfs (r);
}

PHP_FUNCTION (guestfs_strings)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: strings: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_strings (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_strings_e)
{
  zval *z_g;
  guestfs_h *g;
  char *encoding;
  int encoding_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &encoding, &encoding_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (encoding) != encoding_size) {
    fprintf (stderr, "libguestfs: strings_e: parameter 'encoding' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: strings_e: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_strings_e (g, encoding, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_swapoff_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: swapoff_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapoff_device (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapoff_file)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: swapoff_file: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapoff_file (g, file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapoff_label)
{
  zval *z_g;
  guestfs_h *g;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: swapoff_label: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapoff_label (g, label);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapoff_uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *uuid;
  int uuid_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &uuid, &uuid_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: swapoff_uuid: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapoff_uuid (g, uuid);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapon_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: swapon_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapon_device (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapon_file)
{
  zval *z_g;
  guestfs_h *g;
  char *file;
  int file_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &file, &file_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (file) != file_size) {
    fprintf (stderr, "libguestfs: swapon_file: parameter 'file' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapon_file (g, file);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapon_label)
{
  zval *z_g;
  guestfs_h *g;
  char *label;
  int label_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &label, &label_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (label) != label_size) {
    fprintf (stderr, "libguestfs: swapon_label: parameter 'label' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapon_label (g, label);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_swapon_uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *uuid;
  int uuid_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &uuid, &uuid_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (uuid) != uuid_size) {
    fprintf (stderr, "libguestfs: swapon_uuid: parameter 'uuid' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_swapon_uuid (g, uuid);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_sync)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_sync (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_tail)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: tail: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_tail (g, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_tail_n)
{
  zval *z_g;
  guestfs_h *g;
  long nrlines;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rls",
        &z_g, &nrlines, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: tail_n: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_tail_n (g, nrlines, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_tar_in)
{
  zval *z_g;
  guestfs_h *g;
  char *tarfile;
  int tarfile_size;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &tarfile, &tarfile_size, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (tarfile) != tarfile_size) {
    fprintf (stderr, "libguestfs: tar_in: parameter 'tarfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: tar_in: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_tar_in (g, tarfile, directory);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_tar_out)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;
  char *tarfile;
  int tarfile_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &directory, &directory_size, &tarfile, &tarfile_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: tar_out: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (tarfile) != tarfile_size) {
    fprintf (stderr, "libguestfs: tar_out: parameter 'tarfile' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_tar_out (g, directory, tarfile);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_test0)
{
  zval *z_g;
  guestfs_h *g;
  char *str;
  int str_size;
  char *optstr;
  int optstr_size;
  zval *z_strlist;
  char **strlist;
  zend_bool b;
  long integer;
  long integer64;
  char *filein;
  int filein_size;
  char *fileout;
  int fileout_size;
  char *bufferin;
  int bufferin_size;
  struct guestfs_test0_argv optargs_s = { .bitmask = 0 };
  struct guestfs_test0_argv *optargs = &optargs_s;
  zend_bool optargs_t_obool = -1;
  long optargs_t_oint = -1;
  long optargs_t_oint64 = -1;
  char *optargs_t_ostring = NULL;
  int optargs_t_ostring_size = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss!abllsss|blls",
        &z_g, &str, &str_size, &optstr, &optstr_size, &z_strlist, &b, &integer, &integer64, &filein, &filein_size, &fileout, &fileout_size, &bufferin, &bufferin_size, &optargs_t_obool, &optargs_t_oint, &optargs_t_oint64, &optargs_t_ostring, &optargs_t_ostring_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (str) != str_size) {
    fprintf (stderr, "libguestfs: test0: parameter 'str' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (optstr) != optstr_size) {
    fprintf (stderr, "libguestfs: test0: parameter 'optstr' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_strlist);
    n = zend_hash_num_elements (a);
    strlist = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      strlist[c] = Z_STRVAL (t);
      c++;
    }
    strlist[c] = NULL;
  }

  if (strlen (filein) != filein_size) {
    fprintf (stderr, "libguestfs: test0: parameter 'filein' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (fileout) != fileout_size) {
    fprintf (stderr, "libguestfs: test0: parameter 'fileout' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_obool != ((zend_bool)-1)) {
    optargs_s.obool = optargs_t_obool;
    optargs_s.bitmask |= GUESTFS_TEST0_OBOOL_BITMASK;
  }
  if (optargs_t_oint != -1) {
    optargs_s.oint = optargs_t_oint;
    optargs_s.bitmask |= GUESTFS_TEST0_OINT_BITMASK;
  }
  if (optargs_t_oint64 != -1) {
    optargs_s.oint64 = optargs_t_oint64;
    optargs_s.bitmask |= GUESTFS_TEST0_OINT64_BITMASK;
  }
  if (optargs_t_ostring != NULL) {
    optargs_s.ostring = optargs_t_ostring;
    optargs_s.bitmask |= GUESTFS_TEST0_OSTRING_BITMASK;
  }

  int r;
  r = guestfs_test0_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);

  {
    size_t c = 0;

    for (c = 0; strlist[c] != NULL; ++c)
      efree (strlist[c]);
    efree (strlist);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_test0rbool)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rbool: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_test0rbool (g, val);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_test0rboolerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_test0rboolerr (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_BOOL (r);
}

PHP_FUNCTION (guestfs_test0rbufferout)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rbufferout: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_test0rbufferout (g, val, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_test0rbufferouterr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_test0rbufferouterr (g, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_test0rconstoptstring)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rconstoptstring: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_test0rconstoptstring (g, val);


  if (r) { RETURN_STRING (r, 1); }
  else { RETURN_NULL (); }
}

PHP_FUNCTION (guestfs_test0rconstoptstringerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_test0rconstoptstringerr (g);


  if (r) { RETURN_STRING (r, 1); }
  else { RETURN_NULL (); }
}

PHP_FUNCTION (guestfs_test0rconststring)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rconststring: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_test0rconststring (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  RETURN_STRING (r, 1);
}

PHP_FUNCTION (guestfs_test0rconststringerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  const char *r;
  r = guestfs_test0rconststringerr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  RETURN_STRING (r, 1);
}

PHP_FUNCTION (guestfs_test0rhashtable)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rhashtable: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_test0rhashtable (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_test0rhashtableerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_test0rhashtableerr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_test0rint)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rint: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_test0rint (g, val);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_test0rint64)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rint64: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_test0rint64 (g, val);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_test0rint64err)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int64_t r;
  r = guestfs_test0rint64err (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_test0rinterr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_test0rinterr (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_test0rstring)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rstring: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_test0rstring (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_test0rstringerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_test0rstringerr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_test0rstringlist)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rstringlist: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_test0rstringlist (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_test0rstringlisterr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_test0rstringlisterr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_test0rstruct)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rstruct: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_lvm_pv *r;
  r = guestfs_test0rstruct (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_string (return_value, "pv_name", r->pv_name, 1);
  add_assoc_stringl (return_value, "pv_uuid", r->pv_uuid, 32, 1);
  add_assoc_string (return_value, "pv_fmt", r->pv_fmt, 1);
  add_assoc_long (return_value, "pv_size", r->pv_size);
  add_assoc_long (return_value, "dev_size", r->dev_size);
  add_assoc_long (return_value, "pv_free", r->pv_free);
  add_assoc_long (return_value, "pv_used", r->pv_used);
  add_assoc_string (return_value, "pv_attr", r->pv_attr, 1);
  add_assoc_long (return_value, "pv_pe_count", r->pv_pe_count);
  add_assoc_long (return_value, "pv_pe_alloc_count", r->pv_pe_alloc_count);
  add_assoc_string (return_value, "pv_tags", r->pv_tags, 1);
  add_assoc_long (return_value, "pe_start", r->pe_start);
  add_assoc_long (return_value, "pv_mda_count", r->pv_mda_count);
  add_assoc_long (return_value, "pv_mda_free", r->pv_mda_free);
  guestfs_free_lvm_pv (r);
}

PHP_FUNCTION (guestfs_test0rstructerr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_lvm_pv *r;
  r = guestfs_test0rstructerr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_string (return_value, "pv_name", r->pv_name, 1);
  add_assoc_stringl (return_value, "pv_uuid", r->pv_uuid, 32, 1);
  add_assoc_string (return_value, "pv_fmt", r->pv_fmt, 1);
  add_assoc_long (return_value, "pv_size", r->pv_size);
  add_assoc_long (return_value, "dev_size", r->dev_size);
  add_assoc_long (return_value, "pv_free", r->pv_free);
  add_assoc_long (return_value, "pv_used", r->pv_used);
  add_assoc_string (return_value, "pv_attr", r->pv_attr, 1);
  add_assoc_long (return_value, "pv_pe_count", r->pv_pe_count);
  add_assoc_long (return_value, "pv_pe_alloc_count", r->pv_pe_alloc_count);
  add_assoc_string (return_value, "pv_tags", r->pv_tags, 1);
  add_assoc_long (return_value, "pe_start", r->pe_start);
  add_assoc_long (return_value, "pv_mda_count", r->pv_mda_count);
  add_assoc_long (return_value, "pv_mda_free", r->pv_mda_free);
  guestfs_free_lvm_pv (r);
}

PHP_FUNCTION (guestfs_test0rstructlist)
{
  zval *z_g;
  guestfs_h *g;
  char *val;
  int val_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &val, &val_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (val) != val_size) {
    fprintf (stderr, "libguestfs: test0rstructlist: parameter 'val' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  struct guestfs_lvm_pv_list *r;
  r = guestfs_test0rstructlist (g, val);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "pv_name", r->val[c].pv_name, 1);
    add_assoc_stringl (z_elem, "pv_uuid", r->val[c].pv_uuid, 32, 1);
    add_assoc_string (z_elem, "pv_fmt", r->val[c].pv_fmt, 1);
    add_assoc_long (z_elem, "pv_size", r->val[c].pv_size);
    add_assoc_long (z_elem, "dev_size", r->val[c].dev_size);
    add_assoc_long (z_elem, "pv_free", r->val[c].pv_free);
    add_assoc_long (z_elem, "pv_used", r->val[c].pv_used);
    add_assoc_string (z_elem, "pv_attr", r->val[c].pv_attr, 1);
    add_assoc_long (z_elem, "pv_pe_count", r->val[c].pv_pe_count);
    add_assoc_long (z_elem, "pv_pe_alloc_count", r->val[c].pv_pe_alloc_count);
    add_assoc_string (z_elem, "pv_tags", r->val[c].pv_tags, 1);
    add_assoc_long (z_elem, "pe_start", r->val[c].pe_start);
    add_assoc_long (z_elem, "pv_mda_count", r->val[c].pv_mda_count);
    add_assoc_long (z_elem, "pv_mda_free", r->val[c].pv_mda_free);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_lvm_pv_list (r);
}

PHP_FUNCTION (guestfs_test0rstructlisterr)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_lvm_pv_list *r;
  r = guestfs_test0rstructlisterr (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "pv_name", r->val[c].pv_name, 1);
    add_assoc_stringl (z_elem, "pv_uuid", r->val[c].pv_uuid, 32, 1);
    add_assoc_string (z_elem, "pv_fmt", r->val[c].pv_fmt, 1);
    add_assoc_long (z_elem, "pv_size", r->val[c].pv_size);
    add_assoc_long (z_elem, "dev_size", r->val[c].dev_size);
    add_assoc_long (z_elem, "pv_free", r->val[c].pv_free);
    add_assoc_long (z_elem, "pv_used", r->val[c].pv_used);
    add_assoc_string (z_elem, "pv_attr", r->val[c].pv_attr, 1);
    add_assoc_long (z_elem, "pv_pe_count", r->val[c].pv_pe_count);
    add_assoc_long (z_elem, "pv_pe_alloc_count", r->val[c].pv_pe_alloc_count);
    add_assoc_string (z_elem, "pv_tags", r->val[c].pv_tags, 1);
    add_assoc_long (z_elem, "pe_start", r->val[c].pe_start);
    add_assoc_long (z_elem, "pv_mda_count", r->val[c].pv_mda_count);
    add_assoc_long (z_elem, "pv_mda_free", r->val[c].pv_mda_free);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_lvm_pv_list (r);
}

PHP_FUNCTION (guestfs_tgz_in)
{
  zval *z_g;
  guestfs_h *g;
  char *tarball;
  int tarball_size;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &tarball, &tarball_size, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (tarball) != tarball_size) {
    fprintf (stderr, "libguestfs: tgz_in: parameter 'tarball' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: tgz_in: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_tgz_in (g, tarball, directory);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_tgz_out)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;
  char *tarball;
  int tarball_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &directory, &directory_size, &tarball, &tarball_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: tgz_out: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (tarball) != tarball_size) {
    fprintf (stderr, "libguestfs: tgz_out: parameter 'tarball' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_tgz_out (g, directory, tarball);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_touch)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: touch: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_touch (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_truncate)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: truncate: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_truncate (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_truncate_size)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsl",
        &z_g, &path, &path_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: truncate_size: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_truncate_size (g, path, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_tune2fs)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  zend_bool optargs_t_force = -1;
  long optargs_t_maxmountcount = -1;
  long optargs_t_mountcount = -1;
  char *optargs_t_errorbehavior = NULL;
  int optargs_t_errorbehavior_size = -1;
  long optargs_t_group = -1;
  long optargs_t_intervalbetweenchecks = -1;
  long optargs_t_reservedblockspercentage = -1;
  char *optargs_t_lastmounteddirectory = NULL;
  int optargs_t_lastmounteddirectory_size = -1;
  long optargs_t_reservedblockscount = -1;
  long optargs_t_user = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs|bllslllsll",
        &z_g, &device, &device_size, &optargs_t_force, &optargs_t_maxmountcount, &optargs_t_mountcount, &optargs_t_errorbehavior, &optargs_t_errorbehavior_size, &optargs_t_group, &optargs_t_intervalbetweenchecks, &optargs_t_reservedblockspercentage, &optargs_t_lastmounteddirectory, &optargs_t_lastmounteddirectory_size, &optargs_t_reservedblockscount, &optargs_t_user) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: tune2fs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (optargs_t_force != ((zend_bool)-1)) {
    optargs_s.force = optargs_t_force;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
  }
  if (optargs_t_maxmountcount != -1) {
    optargs_s.maxmountcount = optargs_t_maxmountcount;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
  }
  if (optargs_t_mountcount != -1) {
    optargs_s.mountcount = optargs_t_mountcount;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
  }
  if (optargs_t_errorbehavior != NULL) {
    optargs_s.errorbehavior = optargs_t_errorbehavior;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
  }
  if (optargs_t_group != -1) {
    optargs_s.group = optargs_t_group;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
  }
  if (optargs_t_intervalbetweenchecks != -1) {
    optargs_s.intervalbetweenchecks = optargs_t_intervalbetweenchecks;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
  }
  if (optargs_t_reservedblockspercentage != -1) {
    optargs_s.reservedblockspercentage = optargs_t_reservedblockspercentage;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
  }
  if (optargs_t_lastmounteddirectory != NULL) {
    optargs_s.lastmounteddirectory = optargs_t_lastmounteddirectory;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
  }
  if (optargs_t_reservedblockscount != -1) {
    optargs_s.reservedblockscount = optargs_t_reservedblockscount;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
  }
  if (optargs_t_user != -1) {
    optargs_s.user = optargs_t_user;
    optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
  }

  int r;
  r = guestfs_tune2fs_argv (g, device, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_tune2fs_l)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: tune2fs_l: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_tune2fs_l (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; c += 2) {
    add_assoc_string (return_value, r[c], r[c+1], 1);
    free (r[c]);
    free (r[c+1]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_txz_in)
{
  zval *z_g;
  guestfs_h *g;
  char *tarball;
  int tarball_size;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &tarball, &tarball_size, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (tarball) != tarball_size) {
    fprintf (stderr, "libguestfs: txz_in: parameter 'tarball' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: txz_in: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_txz_in (g, tarball, directory);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_txz_out)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;
  char *tarball;
  int tarball_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &directory, &directory_size, &tarball, &tarball_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: txz_out: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (tarball) != tarball_size) {
    fprintf (stderr, "libguestfs: txz_out: parameter 'tarball' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_txz_out (g, directory, tarball);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_umask)
{
  zval *z_g;
  guestfs_h *g;
  long mask;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rl",
        &z_g, &mask) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_umask (g, mask);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_umount)
{
  zval *z_g;
  guestfs_h *g;
  char *pathordevice;
  int pathordevice_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &pathordevice, &pathordevice_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pathordevice) != pathordevice_size) {
    fprintf (stderr, "libguestfs: umount: parameter 'pathordevice' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_umount (g, pathordevice);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_umount_all)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_umount_all (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_umount_local)
{
  zval *z_g;
  guestfs_h *g;
  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  zend_bool optargs_t_retry = -1;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r|b",
        &z_g, &optargs_t_retry) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (optargs_t_retry != ((zend_bool)-1)) {
    optargs_s.retry = optargs_t_retry;
    optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
  }

  int r;
  r = guestfs_umount_local_argv (g, optargs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_upload)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *remotefilename;
  int remotefilename_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &filename, &filename_size, &remotefilename, &remotefilename_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: upload: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (remotefilename) != remotefilename_size) {
    fprintf (stderr, "libguestfs: upload: parameter 'remotefilename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_upload (g, filename, remotefilename);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_upload_offset)
{
  zval *z_g;
  guestfs_h *g;
  char *filename;
  int filename_size;
  char *remotefilename;
  int remotefilename_size;
  long offset;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &filename, &filename_size, &remotefilename, &remotefilename_size, &offset) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (filename) != filename_size) {
    fprintf (stderr, "libguestfs: upload_offset: parameter 'filename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (remotefilename) != remotefilename_size) {
    fprintf (stderr, "libguestfs: upload_offset: parameter 'remotefilename' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_upload_offset (g, filename, remotefilename, offset);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_utimens)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  long atsecs;
  long atnsecs;
  long mtsecs;
  long mtnsecs;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsllll",
        &z_g, &path, &path_size, &atsecs, &atnsecs, &mtsecs, &mtnsecs) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: utimens: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_version)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_version *r;
  r = guestfs_version (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  add_assoc_long (return_value, "major", r->major);
  add_assoc_long (return_value, "minor", r->minor);
  add_assoc_long (return_value, "release", r->release);
  add_assoc_string (return_value, "extra", r->extra, 1);
  guestfs_free_version (r);
}

PHP_FUNCTION (guestfs_vfs_label)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: vfs_label: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_vfs_label (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_vfs_type)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: vfs_type: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_vfs_type (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_vfs_uuid)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: vfs_uuid: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_vfs_uuid (g, device);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_vg_activate)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool activate;
  zval *z_volgroups;
  char **volgroups;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rba",
        &z_g, &activate, &z_volgroups) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_volgroups);
    n = zend_hash_num_elements (a);
    volgroups = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      volgroups[c] = Z_STRVAL (t);
      c++;
    }
    volgroups[c] = NULL;
  }

  int r;
  r = guestfs_vg_activate (g, activate, volgroups);

  {
    size_t c = 0;

    for (c = 0; volgroups[c] != NULL; ++c)
      efree (volgroups[c]);
    efree (volgroups);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vg_activate_all)
{
  zval *z_g;
  guestfs_h *g;
  zend_bool activate;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rb",
        &z_g, &activate) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_vg_activate_all (g, activate);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vgcreate)
{
  zval *z_g;
  guestfs_h *g;
  char *volgroup;
  int volgroup_size;
  zval *z_physvols;
  char **physvols;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rsa",
        &z_g, &volgroup, &volgroup_size, &z_physvols) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (volgroup) != volgroup_size) {
    fprintf (stderr, "libguestfs: vgcreate: parameter 'volgroup' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  {
    HashTable *a;
    int n;
    HashPosition p;
    zval **d;
    size_t c = 0;

    a = Z_ARRVAL_P (z_physvols);
    n = zend_hash_num_elements (a);
    physvols = safe_emalloc (n + 1, sizeof (char *), 0);
    for (zend_hash_internal_pointer_reset_ex (a, &p);
         zend_hash_get_current_data_ex (a, (void **) &d, &p) == SUCCESS;
         zend_hash_move_forward_ex (a, &p)) {
      zval t = **d;
      zval_copy_ctor (&t);
      convert_to_string (&t);
      physvols[c] = Z_STRVAL (t);
      c++;
    }
    physvols[c] = NULL;
  }

  int r;
  r = guestfs_vgcreate (g, volgroup, physvols);

  {
    size_t c = 0;

    for (c = 0; physvols[c] != NULL; ++c)
      efree (physvols[c]);
    efree (physvols);
  }

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vglvuuids)
{
  zval *z_g;
  guestfs_h *g;
  char *vgname;
  int vgname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &vgname, &vgname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (vgname) != vgname_size) {
    fprintf (stderr, "libguestfs: vglvuuids: parameter 'vgname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_vglvuuids (g, vgname);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_vgmeta)
{
  zval *z_g;
  guestfs_h *g;
  char *vgname;
  int vgname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &vgname, &vgname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (vgname) != vgname_size) {
    fprintf (stderr, "libguestfs: vgmeta: parameter 'vgname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  size_t size;
  r = guestfs_vgmeta (g, vgname, &size);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrndup (r, size);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_vgpvuuids)
{
  zval *z_g;
  guestfs_h *g;
  char *vgname;
  int vgname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &vgname, &vgname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (vgname) != vgname_size) {
    fprintf (stderr, "libguestfs: vgpvuuids: parameter 'vgname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_vgpvuuids (g, vgname);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_vgremove)
{
  zval *z_g;
  guestfs_h *g;
  char *vgname;
  int vgname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &vgname, &vgname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (vgname) != vgname_size) {
    fprintf (stderr, "libguestfs: vgremove: parameter 'vgname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_vgremove (g, vgname);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vgrename)
{
  zval *z_g;
  guestfs_h *g;
  char *volgroup;
  int volgroup_size;
  char *newvolgroup;
  int newvolgroup_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &volgroup, &volgroup_size, &newvolgroup, &newvolgroup_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (volgroup) != volgroup_size) {
    fprintf (stderr, "libguestfs: vgrename: parameter 'volgroup' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (newvolgroup) != newvolgroup_size) {
    fprintf (stderr, "libguestfs: vgrename: parameter 'newvolgroup' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_vgrename (g, volgroup, newvolgroup);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vgs)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_vgs (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_vgs_full)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  struct guestfs_lvm_vg_list *r;
  r = guestfs_vgs_full (g);

  if (r == NULL) {
    RETURN_FALSE;
  }

  array_init (return_value);
  size_t c = 0;
  for (c = 0; c < r->len; ++c) {
    zval *z_elem;
    ALLOC_INIT_ZVAL (z_elem);
    array_init (z_elem);
    add_assoc_string (z_elem, "vg_name", r->val[c].vg_name, 1);
    add_assoc_stringl (z_elem, "vg_uuid", r->val[c].vg_uuid, 32, 1);
    add_assoc_string (z_elem, "vg_fmt", r->val[c].vg_fmt, 1);
    add_assoc_string (z_elem, "vg_attr", r->val[c].vg_attr, 1);
    add_assoc_long (z_elem, "vg_size", r->val[c].vg_size);
    add_assoc_long (z_elem, "vg_free", r->val[c].vg_free);
    add_assoc_string (z_elem, "vg_sysid", r->val[c].vg_sysid, 1);
    add_assoc_long (z_elem, "vg_extent_size", r->val[c].vg_extent_size);
    add_assoc_long (z_elem, "vg_extent_count", r->val[c].vg_extent_count);
    add_assoc_long (z_elem, "vg_free_count", r->val[c].vg_free_count);
    add_assoc_long (z_elem, "max_lv", r->val[c].max_lv);
    add_assoc_long (z_elem, "max_pv", r->val[c].max_pv);
    add_assoc_long (z_elem, "pv_count", r->val[c].pv_count);
    add_assoc_long (z_elem, "lv_count", r->val[c].lv_count);
    add_assoc_long (z_elem, "snap_count", r->val[c].snap_count);
    add_assoc_long (z_elem, "vg_seqno", r->val[c].vg_seqno);
    add_assoc_string (z_elem, "vg_tags", r->val[c].vg_tags, 1);
    add_assoc_long (z_elem, "vg_mda_count", r->val[c].vg_mda_count);
    add_assoc_long (z_elem, "vg_mda_free", r->val[c].vg_mda_free);
    add_next_index_zval (return_value, z_elem);
  }
  guestfs_free_lvm_vg_list (r);
}

PHP_FUNCTION (guestfs_vgscan)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_vgscan (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_vguuid)
{
  zval *z_g;
  guestfs_h *g;
  char *vgname;
  int vgname_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &vgname, &vgname_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (vgname) != vgname_size) {
    fprintf (stderr, "libguestfs: vguuid: parameter 'vgname' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_vguuid (g, vgname);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_wait_ready)
{
  zval *z_g;
  guestfs_h *g;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "r",
        &z_g) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  int r;
  r = guestfs_wait_ready (g);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_wc_c)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: wc_c: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_wc_c (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_wc_l)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: wc_l: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_wc_l (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_wc_w)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: wc_w: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_wc_w (g, path);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_LONG (r);
}

PHP_FUNCTION (guestfs_wipefs)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: wipefs: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_wipefs (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_write)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *content;
  int content_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &path, &path_size, &content, &content_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: write: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_write (g, path, content, content_size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_write_append)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *content;
  int content_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &path, &path_size, &content, &content_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: write_append: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_write_append (g, path, content, content_size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_write_file)
{
  zval *z_g;
  guestfs_h *g;
  char *path;
  int path_size;
  char *content;
  int content_size;
  long size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rssl",
        &z_g, &path, &path_size, &content, &content_size, &size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: write_file: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (content) != content_size) {
    fprintf (stderr, "libguestfs: write_file: parameter 'content' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_write_file (g, path, content, size);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_zegrep)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: zegrep: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zegrep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zegrep (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_zegrepi)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: zegrepi: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zegrepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zegrepi (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_zero)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: zero: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_zero (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_zero_device)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: zero_device: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_zero_device (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_zero_free_space)
{
  zval *z_g;
  guestfs_h *g;
  char *directory;
  int directory_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &directory, &directory_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (directory) != directory_size) {
    fprintf (stderr, "libguestfs: zero_free_space: parameter 'directory' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_zero_free_space (g, directory);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_zerofree)
{
  zval *z_g;
  guestfs_h *g;
  char *device;
  int device_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rs",
        &z_g, &device, &device_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (device) != device_size) {
    fprintf (stderr, "libguestfs: zerofree: parameter 'device' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  int r;
  r = guestfs_zerofree (g, device);

  if (r == -1) {
    RETURN_FALSE;
  }

  RETURN_TRUE;
}

PHP_FUNCTION (guestfs_zfgrep)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &pattern, &pattern_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: zfgrep: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zfgrep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zfgrep (g, pattern, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_zfgrepi)
{
  zval *z_g;
  guestfs_h *g;
  char *pattern;
  int pattern_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &pattern, &pattern_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (pattern) != pattern_size) {
    fprintf (stderr, "libguestfs: zfgrepi: parameter 'pattern' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zfgrepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zfgrepi (g, pattern, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_zfile)
{
  zval *z_g;
  guestfs_h *g;
  char *meth;
  int meth_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &meth, &meth_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (meth) != meth_size) {
    fprintf (stderr, "libguestfs: zfile: parameter 'meth' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zfile: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char *r;
  r = guestfs_zfile (g, meth, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  char *r_copy = estrdup (r);
  free (r);
  RETURN_STRING (r_copy, 0);
}

PHP_FUNCTION (guestfs_zgrep)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: zgrep: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zgrep: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zgrep (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

PHP_FUNCTION (guestfs_zgrepi)
{
  zval *z_g;
  guestfs_h *g;
  char *regex;
  int regex_size;
  char *path;
  int path_size;

  if (zend_parse_parameters (ZEND_NUM_ARGS() TSRMLS_CC, "rss",
        &z_g, &regex, &regex_size, &path, &path_size) == FAILURE) {
    RETURN_FALSE;
  }

  ZEND_FETCH_RESOURCE (g, guestfs_h *, &z_g, -1, PHP_GUESTFS_HANDLE_RES_NAME,
                       res_guestfs_h);
  if (g == NULL) {
    RETURN_FALSE;
  }

  if (strlen (regex) != regex_size) {
    fprintf (stderr, "libguestfs: zgrepi: parameter 'regex' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  if (strlen (path) != path_size) {
    fprintf (stderr, "libguestfs: zgrepi: parameter 'path' contains embedded ASCII NUL.\n");
    RETURN_FALSE;
  }

  char **r;
  r = guestfs_zgrepi (g, regex, path);

  if (r == NULL) {
    RETURN_FALSE;
  }

  size_t c = 0;
  array_init (return_value);
  for (c = 0; r[c] != NULL; ++c) {
    add_next_index_string (return_value, r[c], 1);
    free (r[c]);
  }
  free (r);
}

