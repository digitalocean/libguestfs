/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

/* It is safe to call deprecated functions from this file. */
#undef GUESTFS_WARN_DEPRECATED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "c-ctype.h"
#include "full-write.h"
#include "xstrtol.h"

#include <guestfs.h>
#include "fish.h"
#include "fish-cmds.h"
#include "options.h"
#include "cmds_gperf.h"

/* Valid suffixes allowed for numbers.  See Gnulib xstrtol function. */
static const char *xstrtol_suffixes = "0kKMGTPEZY";

static int run_launch (const char *cmd, size_t argc, char *argv[]);
static int run_kill_subprocess (const char *cmd, size_t argc, char *argv[]);
static int run_add_drive (const char *cmd, size_t argc, char *argv[]);
static int run_add_cdrom (const char *cmd, size_t argc, char *argv[]);
static int run_add_drive_ro (const char *cmd, size_t argc, char *argv[]);
static int run_config (const char *cmd, size_t argc, char *argv[]);
static int run_set_qemu (const char *cmd, size_t argc, char *argv[]);
static int run_get_qemu (const char *cmd, size_t argc, char *argv[]);
static int run_set_path (const char *cmd, size_t argc, char *argv[]);
static int run_get_path (const char *cmd, size_t argc, char *argv[]);
static int run_set_append (const char *cmd, size_t argc, char *argv[]);
static int run_get_append (const char *cmd, size_t argc, char *argv[]);
static int run_set_autosync (const char *cmd, size_t argc, char *argv[]);
static int run_get_autosync (const char *cmd, size_t argc, char *argv[]);
static int run_set_verbose (const char *cmd, size_t argc, char *argv[]);
static int run_get_verbose (const char *cmd, size_t argc, char *argv[]);
static int run_is_ready (const char *cmd, size_t argc, char *argv[]);
static int run_is_config (const char *cmd, size_t argc, char *argv[]);
static int run_is_launching (const char *cmd, size_t argc, char *argv[]);
static int run_is_busy (const char *cmd, size_t argc, char *argv[]);
static int run_get_state (const char *cmd, size_t argc, char *argv[]);
static int run_set_memsize (const char *cmd, size_t argc, char *argv[]);
static int run_get_memsize (const char *cmd, size_t argc, char *argv[]);
static int run_get_pid (const char *cmd, size_t argc, char *argv[]);
static int run_version (const char *cmd, size_t argc, char *argv[]);
static int run_set_selinux (const char *cmd, size_t argc, char *argv[]);
static int run_get_selinux (const char *cmd, size_t argc, char *argv[]);
static int run_set_trace (const char *cmd, size_t argc, char *argv[]);
static int run_get_trace (const char *cmd, size_t argc, char *argv[]);
static int run_set_direct (const char *cmd, size_t argc, char *argv[]);
static int run_get_direct (const char *cmd, size_t argc, char *argv[]);
static int run_set_recovery_proc (const char *cmd, size_t argc, char *argv[]);
static int run_get_recovery_proc (const char *cmd, size_t argc, char *argv[]);
static int run_add_drive_with_if (const char *cmd, size_t argc, char *argv[]);
static int run_add_drive_ro_with_if (const char *cmd, size_t argc, char *argv[]);
static int run_file_architecture (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_os (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_type (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_arch (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_distro (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_major_version (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_minor_version (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_product_name (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_mountpoints (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_filesystems (const char *cmd, size_t argc, char *argv[]);
static int run_set_network (const char *cmd, size_t argc, char *argv[]);
static int run_get_network (const char *cmd, size_t argc, char *argv[]);
static int run_list_filesystems (const char *cmd, size_t argc, char *argv[]);
static int run_add_drive_opts (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_windows_systemroot (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_roots (const char *cmd, size_t argc, char *argv[]);
static int run_debug_cmdline (const char *cmd, size_t argc, char *argv[]);
static int run_debug_drives (const char *cmd, size_t argc, char *argv[]);
static int run_add_domain (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_package_format (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_package_management (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_list_applications (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_hostname (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_format (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_is_live (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_is_netinst (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_is_multipart (const char *cmd, size_t argc, char *argv[]);
static int run_set_attach_method (const char *cmd, size_t argc, char *argv[]);
static int run_get_attach_method (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_product_variant (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_windows_current_control_set (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_drive_mappings (const char *cmd, size_t argc, char *argv[]);
static int run_inspect_get_icon (const char *cmd, size_t argc, char *argv[]);
static int run_set_pgroup (const char *cmd, size_t argc, char *argv[]);
static int run_get_pgroup (const char *cmd, size_t argc, char *argv[]);
static int run_set_smp (const char *cmd, size_t argc, char *argv[]);
static int run_get_smp (const char *cmd, size_t argc, char *argv[]);
static int run_mount (const char *cmd, size_t argc, char *argv[]);
static int run_sync (const char *cmd, size_t argc, char *argv[]);
static int run_touch (const char *cmd, size_t argc, char *argv[]);
static int run_cat (const char *cmd, size_t argc, char *argv[]);
static int run_ll (const char *cmd, size_t argc, char *argv[]);
static int run_ls (const char *cmd, size_t argc, char *argv[]);
static int run_list_devices (const char *cmd, size_t argc, char *argv[]);
static int run_list_partitions (const char *cmd, size_t argc, char *argv[]);
static int run_pvs (const char *cmd, size_t argc, char *argv[]);
static int run_vgs (const char *cmd, size_t argc, char *argv[]);
static int run_lvs (const char *cmd, size_t argc, char *argv[]);
static int run_pvs_full (const char *cmd, size_t argc, char *argv[]);
static int run_vgs_full (const char *cmd, size_t argc, char *argv[]);
static int run_lvs_full (const char *cmd, size_t argc, char *argv[]);
static int run_read_lines (const char *cmd, size_t argc, char *argv[]);
static int run_aug_init (const char *cmd, size_t argc, char *argv[]);
static int run_aug_close (const char *cmd, size_t argc, char *argv[]);
static int run_aug_defvar (const char *cmd, size_t argc, char *argv[]);
static int run_aug_defnode (const char *cmd, size_t argc, char *argv[]);
static int run_aug_get (const char *cmd, size_t argc, char *argv[]);
static int run_aug_set (const char *cmd, size_t argc, char *argv[]);
static int run_aug_insert (const char *cmd, size_t argc, char *argv[]);
static int run_aug_rm (const char *cmd, size_t argc, char *argv[]);
static int run_aug_mv (const char *cmd, size_t argc, char *argv[]);
static int run_aug_match (const char *cmd, size_t argc, char *argv[]);
static int run_aug_save (const char *cmd, size_t argc, char *argv[]);
static int run_aug_load (const char *cmd, size_t argc, char *argv[]);
static int run_aug_ls (const char *cmd, size_t argc, char *argv[]);
static int run_rm (const char *cmd, size_t argc, char *argv[]);
static int run_rmdir (const char *cmd, size_t argc, char *argv[]);
static int run_rm_rf (const char *cmd, size_t argc, char *argv[]);
static int run_mkdir (const char *cmd, size_t argc, char *argv[]);
static int run_mkdir_p (const char *cmd, size_t argc, char *argv[]);
static int run_chmod (const char *cmd, size_t argc, char *argv[]);
static int run_chown (const char *cmd, size_t argc, char *argv[]);
static int run_exists (const char *cmd, size_t argc, char *argv[]);
static int run_is_file (const char *cmd, size_t argc, char *argv[]);
static int run_is_dir (const char *cmd, size_t argc, char *argv[]);
static int run_pvcreate (const char *cmd, size_t argc, char *argv[]);
static int run_vgcreate (const char *cmd, size_t argc, char *argv[]);
static int run_lvcreate (const char *cmd, size_t argc, char *argv[]);
static int run_mkfs (const char *cmd, size_t argc, char *argv[]);
static int run_sfdisk (const char *cmd, size_t argc, char *argv[]);
static int run_write_file (const char *cmd, size_t argc, char *argv[]);
static int run_umount (const char *cmd, size_t argc, char *argv[]);
static int run_mounts (const char *cmd, size_t argc, char *argv[]);
static int run_umount_all (const char *cmd, size_t argc, char *argv[]);
static int run_lvm_remove_all (const char *cmd, size_t argc, char *argv[]);
static int run_file (const char *cmd, size_t argc, char *argv[]);
static int run_command (const char *cmd, size_t argc, char *argv[]);
static int run_command_lines (const char *cmd, size_t argc, char *argv[]);
static int run_stat (const char *cmd, size_t argc, char *argv[]);
static int run_lstat (const char *cmd, size_t argc, char *argv[]);
static int run_statvfs (const char *cmd, size_t argc, char *argv[]);
static int run_tune2fs_l (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_setro (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_setrw (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_getro (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_getss (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_getbsz (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_setbsz (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_getsz (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_getsize64 (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_flushbufs (const char *cmd, size_t argc, char *argv[]);
static int run_blockdev_rereadpt (const char *cmd, size_t argc, char *argv[]);
static int run_upload (const char *cmd, size_t argc, char *argv[]);
static int run_download (const char *cmd, size_t argc, char *argv[]);
static int run_checksum (const char *cmd, size_t argc, char *argv[]);
static int run_tar_in (const char *cmd, size_t argc, char *argv[]);
static int run_tar_out (const char *cmd, size_t argc, char *argv[]);
static int run_tgz_in (const char *cmd, size_t argc, char *argv[]);
static int run_tgz_out (const char *cmd, size_t argc, char *argv[]);
static int run_mount_ro (const char *cmd, size_t argc, char *argv[]);
static int run_mount_options (const char *cmd, size_t argc, char *argv[]);
static int run_mount_vfs (const char *cmd, size_t argc, char *argv[]);
static int run_debug (const char *cmd, size_t argc, char *argv[]);
static int run_lvremove (const char *cmd, size_t argc, char *argv[]);
static int run_vgremove (const char *cmd, size_t argc, char *argv[]);
static int run_pvremove (const char *cmd, size_t argc, char *argv[]);
static int run_set_e2label (const char *cmd, size_t argc, char *argv[]);
static int run_get_e2label (const char *cmd, size_t argc, char *argv[]);
static int run_set_e2uuid (const char *cmd, size_t argc, char *argv[]);
static int run_get_e2uuid (const char *cmd, size_t argc, char *argv[]);
static int run_fsck (const char *cmd, size_t argc, char *argv[]);
static int run_zero (const char *cmd, size_t argc, char *argv[]);
static int run_grub_install (const char *cmd, size_t argc, char *argv[]);
static int run_cp (const char *cmd, size_t argc, char *argv[]);
static int run_cp_a (const char *cmd, size_t argc, char *argv[]);
static int run_mv (const char *cmd, size_t argc, char *argv[]);
static int run_drop_caches (const char *cmd, size_t argc, char *argv[]);
static int run_dmesg (const char *cmd, size_t argc, char *argv[]);
static int run_ping_daemon (const char *cmd, size_t argc, char *argv[]);
static int run_equal (const char *cmd, size_t argc, char *argv[]);
static int run_strings (const char *cmd, size_t argc, char *argv[]);
static int run_strings_e (const char *cmd, size_t argc, char *argv[]);
static int run_hexdump (const char *cmd, size_t argc, char *argv[]);
static int run_zerofree (const char *cmd, size_t argc, char *argv[]);
static int run_pvresize (const char *cmd, size_t argc, char *argv[]);
static int run_sfdisk_N (const char *cmd, size_t argc, char *argv[]);
static int run_sfdisk_l (const char *cmd, size_t argc, char *argv[]);
static int run_sfdisk_kernel_geometry (const char *cmd, size_t argc, char *argv[]);
static int run_sfdisk_disk_geometry (const char *cmd, size_t argc, char *argv[]);
static int run_vg_activate_all (const char *cmd, size_t argc, char *argv[]);
static int run_vg_activate (const char *cmd, size_t argc, char *argv[]);
static int run_lvresize (const char *cmd, size_t argc, char *argv[]);
static int run_resize2fs (const char *cmd, size_t argc, char *argv[]);
static int run_find (const char *cmd, size_t argc, char *argv[]);
static int run_e2fsck_f (const char *cmd, size_t argc, char *argv[]);
static int run_sleep (const char *cmd, size_t argc, char *argv[]);
static int run_ntfs_3g_probe (const char *cmd, size_t argc, char *argv[]);
static int run_sh (const char *cmd, size_t argc, char *argv[]);
static int run_sh_lines (const char *cmd, size_t argc, char *argv[]);
static int run_glob_expand (const char *cmd, size_t argc, char *argv[]);
static int run_scrub_device (const char *cmd, size_t argc, char *argv[]);
static int run_scrub_file (const char *cmd, size_t argc, char *argv[]);
static int run_scrub_freespace (const char *cmd, size_t argc, char *argv[]);
static int run_mkdtemp (const char *cmd, size_t argc, char *argv[]);
static int run_wc_l (const char *cmd, size_t argc, char *argv[]);
static int run_wc_w (const char *cmd, size_t argc, char *argv[]);
static int run_wc_c (const char *cmd, size_t argc, char *argv[]);
static int run_head (const char *cmd, size_t argc, char *argv[]);
static int run_head_n (const char *cmd, size_t argc, char *argv[]);
static int run_tail (const char *cmd, size_t argc, char *argv[]);
static int run_tail_n (const char *cmd, size_t argc, char *argv[]);
static int run_df (const char *cmd, size_t argc, char *argv[]);
static int run_df_h (const char *cmd, size_t argc, char *argv[]);
static int run_du (const char *cmd, size_t argc, char *argv[]);
static int run_initrd_list (const char *cmd, size_t argc, char *argv[]);
static int run_mount_loop (const char *cmd, size_t argc, char *argv[]);
static int run_mkswap (const char *cmd, size_t argc, char *argv[]);
static int run_mkswap_L (const char *cmd, size_t argc, char *argv[]);
static int run_mkswap_U (const char *cmd, size_t argc, char *argv[]);
static int run_mknod (const char *cmd, size_t argc, char *argv[]);
static int run_mkfifo (const char *cmd, size_t argc, char *argv[]);
static int run_mknod_b (const char *cmd, size_t argc, char *argv[]);
static int run_mknod_c (const char *cmd, size_t argc, char *argv[]);
static int run_umask (const char *cmd, size_t argc, char *argv[]);
static int run_readdir (const char *cmd, size_t argc, char *argv[]);
static int run_sfdiskM (const char *cmd, size_t argc, char *argv[]);
static int run_zfile (const char *cmd, size_t argc, char *argv[]);
static int run_getxattrs (const char *cmd, size_t argc, char *argv[]);
static int run_lgetxattrs (const char *cmd, size_t argc, char *argv[]);
static int run_setxattr (const char *cmd, size_t argc, char *argv[]);
static int run_lsetxattr (const char *cmd, size_t argc, char *argv[]);
static int run_removexattr (const char *cmd, size_t argc, char *argv[]);
static int run_lremovexattr (const char *cmd, size_t argc, char *argv[]);
static int run_mountpoints (const char *cmd, size_t argc, char *argv[]);
static int run_mkmountpoint (const char *cmd, size_t argc, char *argv[]);
static int run_rmmountpoint (const char *cmd, size_t argc, char *argv[]);
static int run_read_file (const char *cmd, size_t argc, char *argv[]);
static int run_grep (const char *cmd, size_t argc, char *argv[]);
static int run_egrep (const char *cmd, size_t argc, char *argv[]);
static int run_fgrep (const char *cmd, size_t argc, char *argv[]);
static int run_grepi (const char *cmd, size_t argc, char *argv[]);
static int run_egrepi (const char *cmd, size_t argc, char *argv[]);
static int run_fgrepi (const char *cmd, size_t argc, char *argv[]);
static int run_zgrep (const char *cmd, size_t argc, char *argv[]);
static int run_zegrep (const char *cmd, size_t argc, char *argv[]);
static int run_zfgrep (const char *cmd, size_t argc, char *argv[]);
static int run_zgrepi (const char *cmd, size_t argc, char *argv[]);
static int run_zegrepi (const char *cmd, size_t argc, char *argv[]);
static int run_zfgrepi (const char *cmd, size_t argc, char *argv[]);
static int run_realpath (const char *cmd, size_t argc, char *argv[]);
static int run_ln (const char *cmd, size_t argc, char *argv[]);
static int run_ln_f (const char *cmd, size_t argc, char *argv[]);
static int run_ln_s (const char *cmd, size_t argc, char *argv[]);
static int run_ln_sf (const char *cmd, size_t argc, char *argv[]);
static int run_readlink (const char *cmd, size_t argc, char *argv[]);
static int run_fallocate (const char *cmd, size_t argc, char *argv[]);
static int run_swapon_device (const char *cmd, size_t argc, char *argv[]);
static int run_swapoff_device (const char *cmd, size_t argc, char *argv[]);
static int run_swapon_file (const char *cmd, size_t argc, char *argv[]);
static int run_swapoff_file (const char *cmd, size_t argc, char *argv[]);
static int run_swapon_label (const char *cmd, size_t argc, char *argv[]);
static int run_swapoff_label (const char *cmd, size_t argc, char *argv[]);
static int run_swapon_uuid (const char *cmd, size_t argc, char *argv[]);
static int run_swapoff_uuid (const char *cmd, size_t argc, char *argv[]);
static int run_mkswap_file (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_init (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_add_watch (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_rm_watch (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_read (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_files (const char *cmd, size_t argc, char *argv[]);
static int run_inotify_close (const char *cmd, size_t argc, char *argv[]);
static int run_setcon (const char *cmd, size_t argc, char *argv[]);
static int run_getcon (const char *cmd, size_t argc, char *argv[]);
static int run_mkfs_b (const char *cmd, size_t argc, char *argv[]);
static int run_mke2journal (const char *cmd, size_t argc, char *argv[]);
static int run_mke2journal_L (const char *cmd, size_t argc, char *argv[]);
static int run_mke2journal_U (const char *cmd, size_t argc, char *argv[]);
static int run_mke2fs_J (const char *cmd, size_t argc, char *argv[]);
static int run_mke2fs_JL (const char *cmd, size_t argc, char *argv[]);
static int run_mke2fs_JU (const char *cmd, size_t argc, char *argv[]);
static int run_modprobe (const char *cmd, size_t argc, char *argv[]);
static int run_echo_daemon (const char *cmd, size_t argc, char *argv[]);
static int run_find0 (const char *cmd, size_t argc, char *argv[]);
static int run_case_sensitive_path (const char *cmd, size_t argc, char *argv[]);
static int run_vfs_type (const char *cmd, size_t argc, char *argv[]);
static int run_truncate (const char *cmd, size_t argc, char *argv[]);
static int run_truncate_size (const char *cmd, size_t argc, char *argv[]);
static int run_utimens (const char *cmd, size_t argc, char *argv[]);
static int run_mkdir_mode (const char *cmd, size_t argc, char *argv[]);
static int run_lchown (const char *cmd, size_t argc, char *argv[]);
static int run_lstatlist (const char *cmd, size_t argc, char *argv[]);
static int run_lxattrlist (const char *cmd, size_t argc, char *argv[]);
static int run_readlinklist (const char *cmd, size_t argc, char *argv[]);
static int run_pread (const char *cmd, size_t argc, char *argv[]);
static int run_part_init (const char *cmd, size_t argc, char *argv[]);
static int run_part_add (const char *cmd, size_t argc, char *argv[]);
static int run_part_disk (const char *cmd, size_t argc, char *argv[]);
static int run_part_set_bootable (const char *cmd, size_t argc, char *argv[]);
static int run_part_set_name (const char *cmd, size_t argc, char *argv[]);
static int run_part_list (const char *cmd, size_t argc, char *argv[]);
static int run_part_get_parttype (const char *cmd, size_t argc, char *argv[]);
static int run_fill (const char *cmd, size_t argc, char *argv[]);
static int run_available (const char *cmd, size_t argc, char *argv[]);
static int run_dd (const char *cmd, size_t argc, char *argv[]);
static int run_filesize (const char *cmd, size_t argc, char *argv[]);
static int run_lvrename (const char *cmd, size_t argc, char *argv[]);
static int run_vgrename (const char *cmd, size_t argc, char *argv[]);
static int run_initrd_cat (const char *cmd, size_t argc, char *argv[]);
static int run_pvuuid (const char *cmd, size_t argc, char *argv[]);
static int run_vguuid (const char *cmd, size_t argc, char *argv[]);
static int run_lvuuid (const char *cmd, size_t argc, char *argv[]);
static int run_vgpvuuids (const char *cmd, size_t argc, char *argv[]);
static int run_vglvuuids (const char *cmd, size_t argc, char *argv[]);
static int run_copy_size (const char *cmd, size_t argc, char *argv[]);
static int run_zero_device (const char *cmd, size_t argc, char *argv[]);
static int run_txz_in (const char *cmd, size_t argc, char *argv[]);
static int run_txz_out (const char *cmd, size_t argc, char *argv[]);
static int run_ntfsresize (const char *cmd, size_t argc, char *argv[]);
static int run_vgscan (const char *cmd, size_t argc, char *argv[]);
static int run_part_del (const char *cmd, size_t argc, char *argv[]);
static int run_part_get_bootable (const char *cmd, size_t argc, char *argv[]);
static int run_part_get_mbr_id (const char *cmd, size_t argc, char *argv[]);
static int run_part_set_mbr_id (const char *cmd, size_t argc, char *argv[]);
static int run_checksum_device (const char *cmd, size_t argc, char *argv[]);
static int run_lvresize_free (const char *cmd, size_t argc, char *argv[]);
static int run_aug_clear (const char *cmd, size_t argc, char *argv[]);
static int run_get_umask (const char *cmd, size_t argc, char *argv[]);
static int run_debug_upload (const char *cmd, size_t argc, char *argv[]);
static int run_base64_in (const char *cmd, size_t argc, char *argv[]);
static int run_base64_out (const char *cmd, size_t argc, char *argv[]);
static int run_checksums_out (const char *cmd, size_t argc, char *argv[]);
static int run_fill_pattern (const char *cmd, size_t argc, char *argv[]);
static int run_write (const char *cmd, size_t argc, char *argv[]);
static int run_pwrite (const char *cmd, size_t argc, char *argv[]);
static int run_resize2fs_size (const char *cmd, size_t argc, char *argv[]);
static int run_pvresize_size (const char *cmd, size_t argc, char *argv[]);
static int run_ntfsresize_size (const char *cmd, size_t argc, char *argv[]);
static int run_available_all_groups (const char *cmd, size_t argc, char *argv[]);
static int run_fallocate64 (const char *cmd, size_t argc, char *argv[]);
static int run_vfs_label (const char *cmd, size_t argc, char *argv[]);
static int run_vfs_uuid (const char *cmd, size_t argc, char *argv[]);
static int run_lvm_set_filter (const char *cmd, size_t argc, char *argv[]);
static int run_lvm_clear_filter (const char *cmd, size_t argc, char *argv[]);
static int run_luks_open (const char *cmd, size_t argc, char *argv[]);
static int run_luks_open_ro (const char *cmd, size_t argc, char *argv[]);
static int run_luks_close (const char *cmd, size_t argc, char *argv[]);
static int run_luks_format (const char *cmd, size_t argc, char *argv[]);
static int run_luks_format_cipher (const char *cmd, size_t argc, char *argv[]);
static int run_luks_add_key (const char *cmd, size_t argc, char *argv[]);
static int run_luks_kill_slot (const char *cmd, size_t argc, char *argv[]);
static int run_is_lv (const char *cmd, size_t argc, char *argv[]);
static int run_findfs_uuid (const char *cmd, size_t argc, char *argv[]);
static int run_findfs_label (const char *cmd, size_t argc, char *argv[]);
static int run_is_chardev (const char *cmd, size_t argc, char *argv[]);
static int run_is_blockdev (const char *cmd, size_t argc, char *argv[]);
static int run_is_fifo (const char *cmd, size_t argc, char *argv[]);
static int run_is_symlink (const char *cmd, size_t argc, char *argv[]);
static int run_is_socket (const char *cmd, size_t argc, char *argv[]);
static int run_part_to_dev (const char *cmd, size_t argc, char *argv[]);
static int run_upload_offset (const char *cmd, size_t argc, char *argv[]);
static int run_download_offset (const char *cmd, size_t argc, char *argv[]);
static int run_pwrite_device (const char *cmd, size_t argc, char *argv[]);
static int run_pread_device (const char *cmd, size_t argc, char *argv[]);
static int run_lvm_canonical_lv_name (const char *cmd, size_t argc, char *argv[]);
static int run_mkfs_opts (const char *cmd, size_t argc, char *argv[]);
static int run_getxattr (const char *cmd, size_t argc, char *argv[]);
static int run_lgetxattr (const char *cmd, size_t argc, char *argv[]);
static int run_resize2fs_M (const char *cmd, size_t argc, char *argv[]);
static int run_is_zero (const char *cmd, size_t argc, char *argv[]);
static int run_is_zero_device (const char *cmd, size_t argc, char *argv[]);
static int run_list_9p (const char *cmd, size_t argc, char *argv[]);
static int run_mount_9p (const char *cmd, size_t argc, char *argv[]);
static int run_list_dm_devices (const char *cmd, size_t argc, char *argv[]);
static int run_ntfsresize_opts (const char *cmd, size_t argc, char *argv[]);
static int run_btrfs_filesystem_resize (const char *cmd, size_t argc, char *argv[]);
static int run_write_append (const char *cmd, size_t argc, char *argv[]);
static int run_compress_out (const char *cmd, size_t argc, char *argv[]);
static int run_compress_device_out (const char *cmd, size_t argc, char *argv[]);
static int run_part_to_partnum (const char *cmd, size_t argc, char *argv[]);
static int run_copy_device_to_device (const char *cmd, size_t argc, char *argv[]);
static int run_copy_device_to_file (const char *cmd, size_t argc, char *argv[]);
static int run_copy_file_to_device (const char *cmd, size_t argc, char *argv[]);
static int run_copy_file_to_file (const char *cmd, size_t argc, char *argv[]);
static int run_tune2fs (const char *cmd, size_t argc, char *argv[]);
static int run_md_create (const char *cmd, size_t argc, char *argv[]);
static int run_list_md_devices (const char *cmd, size_t argc, char *argv[]);
static int run_md_detail (const char *cmd, size_t argc, char *argv[]);
static int run_md_stop (const char *cmd, size_t argc, char *argv[]);
static int run_blkid (const char *cmd, size_t argc, char *argv[]);
static int run_e2fsck (const char *cmd, size_t argc, char *argv[]);

struct command_entry alloc_cmd_entry = {
  .name = "alloc",
  .help = "NAME\n    alloc - allocate and add a disk file\n\nDESCRIPTION\n     alloc filename size\n\n    This creates an empty (zeroed) file of the given size, and then adds so\n    it can be further examined.\n\n    For more advanced image creation, see qemu-img(1) utility.\n\n    Size can be specified using standard suffixes, eg. \"1M\".\n\n    To create a sparse file, use \"sparse\" instead. To create a prepared disk\n    image, see \"PREPARED DISK IMAGES\".\n\n    You can use 'allocate' as an alias for this command.\n\n",
  .run = run_alloc
};

struct command_entry copy_in_cmd_entry = {
  .name = "copy-in",
  .help = "NAME\n    copy-in - copy local files or directories into an image\n\nDESCRIPTION\n     copy-in local [local ...] /remotedir\n\n    \"copy-in\" copies local files or directories recursively into the disk\n    image, placing them in the directory called \"/remotedir\" (which must\n    exist). This guestfish meta-command turns into a sequence of \"tar-in\"\n    and other commands as necessary.\n\n    Multiple local files and directories can be specified, but the last\n    parameter must always be a remote directory. Wildcards cannot be used.\n\n",
  .run = run_copy_in
};

struct command_entry copy_out_cmd_entry = {
  .name = "copy-out",
  .help = "NAME\n    copy-out - copy remote files or directories out of an image\n\nDESCRIPTION\n     copy-out remote [remote ...] localdir\n\n    \"copy-out\" copies remote files or directories recursively out of the\n    disk image, placing them on the host disk in a local directory called\n    \"localdir\" (which must exist). This guestfish meta-command turns into a\n    sequence of \"download\", \"tar-out\" and other commands as necessary.\n\n    Multiple remote files and directories can be specified, but the last\n    parameter must always be a local directory. To download to the current\n    directory, use \".\" as in:\n\n     copy-out /home .\n\n    Wildcards cannot be used in the ordinary command, but you can use them\n    with the help of \"glob\" like this:\n\n     glob copy-out /home/* .\n\n",
  .run = run_copy_out
};

struct command_entry delete_event_cmd_entry = {
  .name = "delete-event",
  .help = "NAME\n    delete-event - delete a previously registered event handler\n\nDESCRIPTION\n     delete-event name\n\n    Delete the event handler which was previously registered as \"name\". If\n    multiple event handlers were registered with the same name, they are all\n    deleted.\n\n    See also the guestfish commands \"event\" and \"list-events\".\n\n",
  .run = run_delete_event
};

struct command_entry display_cmd_entry = {
  .name = "display",
  .help = "NAME\n    display - display an image\n\nDESCRIPTION\n     display filename\n\n    Use \"display\" (a graphical display program) to display an image file. It\n    downloads the file, and runs \"display\" on it.\n\n    To use an alternative program, set the \"GUESTFISH_DISPLAY_IMAGE\"\n    environment variable. For example to use the GNOME display program:\n\n     export GUESTFISH_DISPLAY_IMAGE=eog\n\n    See also display(1).\n\n",
  .run = run_display
};

struct command_entry echo_cmd_entry = {
  .name = "echo",
  .help = "NAME\n    echo - display a line of text\n\nDESCRIPTION\n     echo [params ...]\n\n    This echos the parameters to the terminal.\n\n",
  .run = run_echo
};

struct command_entry edit_cmd_entry = {
  .name = "edit",
  .help = "NAME\n    edit - edit a file\n\nDESCRIPTION\n     edit filename\n\n    This is used to edit a file. It downloads the file, edits it locally\n    using your editor, then uploads the result.\n\n    The editor is $EDITOR. However if you use the alternate commands \"vi\" or\n    \"emacs\" you will get those corresponding editors.\n\n    You can use 'vi' or 'emacs' as an alias for this command.\n\n",
  .run = run_edit
};

struct command_entry event_cmd_entry = {
  .name = "event",
  .help = "NAME\n    event - register a handler for an event or events\n\nDESCRIPTION\n     event name eventset \"shell script ...\"\n\n    Register a shell script fragment which is executed when an event is\n    raised. See \"guestfs_set_event_callback\" in guestfs(3) for a discussion\n    of the event API in libguestfs.\n\n    The \"name\" parameter is a name that you give to this event handler. It\n    can be any string (even the empty string) and is simply there so you can\n    delete the handler using the guestfish \"delete-event\" command.\n\n    The \"eventset\" parameter is a comma-separated list of one or more\n    events, for example \"close\" or \"close,trace\". The special value \"*\"\n    means all events.\n\n    The third and final parameter is the shell script fragment (or any\n    external command) that is executed when any of the events in the\n    eventset occurs. It is executed using \"$SHELL -c\", or if $SHELL is not\n    set then \"/bin/sh -c\".\n\n    The shell script fragment receives callback parameters as arguments $1,\n    $2 etc. The actual event that was called is available in the environment\n    variable $EVENT.\n\n     event \"\" close \"echo closed\"\n     event messages appliance,library,trace \"echo $@\"\n     event \"\" progress \"echo progress: $3/$4\"\n     event \"\" * \"echo $EVENT $@\"\n\n    See also the guestfish commands \"delete-event\" and \"list-events\".\n\n",
  .run = run_event
};

struct command_entry glob_cmd_entry = {
  .name = "glob",
  .help = "NAME\n    glob - expand wildcards in command\n\nDESCRIPTION\n     glob command args...\n\n    Expand wildcards in any paths in the args list, and run \"command\"\n    repeatedly on each matching path.\n\n    See \"WILDCARDS AND GLOBBING\".\n\n",
  .run = run_glob
};

struct command_entry hexedit_cmd_entry = {
  .name = "hexedit",
  .help = "NAME\n    hexedit - edit with a hex editor\n\nDESCRIPTION\n     hexedit <filename|device>\n     hexedit <filename|device> <max>\n     hexedit <filename|device> <start> <max>\n\n    Use hexedit (a hex editor) to edit all or part of a binary file or block\n    device.\n\n    This command works by downloading potentially the whole file or device,\n    editing it locally, then uploading it. If the file or device is large,\n    you have to specify which part you wish to edit by using \"max\" and/or\n    \"start\" \"max\" parameters. \"start\" and \"max\" are specified in bytes, with\n    the usual modifiers allowed such as \"1M\" (1 megabyte).\n\n    For example to edit the first few sectors of a disk you might do:\n\n     hexedit /dev/sda 1M\n\n    which would allow you to edit anywhere within the first megabyte of the\n    disk.\n\n    To edit the superblock of an ext2 filesystem on \"/dev/sda1\", do:\n\n     hexedit /dev/sda1 0x400 0x400\n\n    (assuming the superblock is in the standard location).\n\n    This command requires the external hexedit(1) program. You can specify\n    another program to use by setting the \"HEXEDITOR\" environment variable.\n\n    See also \"hexdump\".\n\n",
  .run = run_hexedit
};

struct command_entry lcd_cmd_entry = {
  .name = "lcd",
  .help = "NAME\n    lcd - change working directory\n\nDESCRIPTION\n     lcd directory\n\n    Change the local directory, ie. the current directory of guestfish\n    itself.\n\n    Note that \"!cd\" won't do what you might expect.\n\n",
  .run = run_lcd
};

struct command_entry list_events_cmd_entry = {
  .name = "list-events",
  .help = "NAME\n    list-events - list event handlers\n\nDESCRIPTION\n     list-events\n\n    List the event handlers registered using the guestfish \"event\" command.\n\n",
  .run = run_list_events
};

struct command_entry man_cmd_entry = {
  .name = "man",
  .help = "NAME\n    man - open the manual\n\nDESCRIPTION\n      man\n\n    Opens the manual page for guestfish.\n\n    You can use 'manual' as an alias for this command.\n\n",
  .run = run_man
};

struct command_entry more_cmd_entry = {
  .name = "more",
  .help = "NAME\n    more - view a file\n\nDESCRIPTION\n     more filename\n\n     less filename\n\n    This is used to view a file.\n\n    The default viewer is $PAGER. However if you use the alternate command\n    \"less\" you will get the \"less\" command specifically.\n\n    You can use 'less' as an alias for this command.\n\n",
  .run = run_more
};

struct command_entry reopen_cmd_entry = {
  .name = "reopen",
  .help = "NAME\n    reopen - close and reopen libguestfs handle\n\nDESCRIPTION\n      reopen\n\n    Close and reopen the libguestfs handle. It is not necessary to use this\n    normally, because the handle is closed properly when guestfish exits.\n    However this is occasionally useful for testing.\n\n",
  .run = run_reopen
};

struct command_entry setenv_cmd_entry = {
  .name = "setenv",
  .help = "NAME\n    setenv - set an environment variable\n\nDESCRIPTION\n      setenv VAR value\n\n    Set the environment variable \"VAR\" to the string \"value\".\n\n    To print the value of an environment variable use a shell command such\n    as:\n\n     !echo $VAR\n\n",
  .run = run_setenv
};

struct command_entry sparse_cmd_entry = {
  .name = "sparse",
  .help = "NAME\n    sparse - create a sparse disk image and add\n\nDESCRIPTION\n     sparse filename size\n\n    This creates an empty sparse file of the given size, and then adds so it\n    can be further examined.\n\n    In all respects it works the same as the \"alloc\" command, except that\n    the image file is allocated sparsely, which means that disk blocks are\n    not assigned to the file until they are needed. Sparse disk files only\n    use space when written to, but they are slower and there is a danger you\n    could run out of real disk space during a write operation.\n\n    For more advanced image creation, see qemu-img(1) utility.\n\n    Size can be specified using standard suffixes, eg. \"1M\".\n\n",
  .run = run_sparse
};

struct command_entry supported_cmd_entry = {
  .name = "supported",
  .help = "NAME\n    supported - list supported groups of commands\n\nDESCRIPTION\n     supported\n\n    This command returns a list of the optional groups known to the daemon,\n    and indicates which ones are supported by this build of the libguestfs\n    appliance.\n\n    See also \"AVAILABILITY\" in guestfs(3).\n\n",
  .run = run_supported
};

struct command_entry time_cmd_entry = {
  .name = "time",
  .help = "NAME\n    time - print elapsed time taken to run a command\n\nDESCRIPTION\n     time command args...\n\n    Run the command as usual, but print the elapsed time afterwards. This\n    can be useful for benchmarking operations.\n\n",
  .run = run_time
};

struct command_entry unsetenv_cmd_entry = {
  .name = "unsetenv",
  .help = "NAME\n    unsetenv - unset an environment variable\n\nDESCRIPTION\n      unsetenv VAR\n\n    Remove \"VAR\" from the environment.\n\n",
  .run = run_unsetenv
};

struct command_entry launch_cmd_entry = {
  .name = "launch",
  .help = "NAME\n    launch - launch the qemu subprocess\n\nSYNOPSIS\n     launch\n\nDESCRIPTION\n    Internally libguestfs is implemented by running a virtual machine using\n    qemu(1).\n\n    You should call this after configuring the handle (eg. adding drives)\n    but before performing any actions.\n\n    You can use 'run' as an alias for this command.\n\n",
  .run = run_launch
};

struct command_entry kill_subprocess_cmd_entry = {
  .name = "kill-subprocess",
  .help = "NAME\n    kill-subprocess - kill the qemu subprocess\n\nSYNOPSIS\n     kill-subprocess\n\nDESCRIPTION\n    This kills the qemu subprocess. You should never need to call this.\n\n",
  .run = run_kill_subprocess
};

struct command_entry add_drive_cmd_entry = {
  .name = "add-drive",
  .help = "NAME\n    add-drive - add an image to examine or modify\n\nSYNOPSIS\n     add-drive filename\n\nDESCRIPTION\n    This function is the equivalent of calling \"add_drive_opts\" with no\n    optional parameters, so the disk is added writable, with the format\n    being detected automatically.\n\n    Automatic detection of the format opens you up to a potential security\n    hole when dealing with untrusted raw-format images. See CVE-2010-3851\n    and RHBZ#642934. Specifying the format closes this security hole.\n    Therefore you should think about replacing calls to this function with\n    calls to \"add_drive_opts\", and specifying the format.\n\n",
  .run = run_add_drive
};

struct command_entry add_cdrom_cmd_entry = {
  .name = "add-cdrom",
  .help = "NAME\n    add-cdrom - add a CD-ROM disk image to examine\n\nSYNOPSIS\n     add-cdrom filename\n\nDESCRIPTION\n    This function adds a virtual CD-ROM disk image to the guest.\n\n    This is equivalent to the qemu parameter *-cdrom filename*.\n\n    Notes:\n\n    *   This call checks for the existence of \"filename\". This stops you\n        from specifying other types of drive which are supported by qemu\n        such as \"nbd:\" and \"http:\" URLs. To specify those, use the general\n        \"config\" call instead.\n\n    *   If you just want to add an ISO file (often you use this as an\n        efficient way to transfer large files into the guest), then you\n        should probably use \"add_drive_ro\" instead.\n\n    *This function is deprecated.* In new code, use the \"add_drive_opts\"\n    call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_add_cdrom
};

struct command_entry add_drive_ro_cmd_entry = {
  .name = "add-drive-ro",
  .help = "NAME\n    add-drive-ro - add a drive in snapshot mode (read-only)\n\nSYNOPSIS\n     add-drive-ro filename\n\nDESCRIPTION\n    This function is the equivalent of calling \"add_drive_opts\" with the\n    optional parameter \"GUESTFS_ADD_DRIVE_OPTS_READONLY\" set to 1, so the\n    disk is added read-only, with the format being detected automatically.\n\n    You can use 'add-ro' as an alias for this command.\n\n",
  .run = run_add_drive_ro
};

struct command_entry config_cmd_entry = {
  .name = "config",
  .help = "NAME\n    config - add qemu parameters\n\nSYNOPSIS\n     config qemuparam qemuvalue\n\nDESCRIPTION\n    This can be used to add arbitrary qemu command line parameters of the\n    form *-param value*. Actually it's not quite arbitrary - we prevent you\n    from setting some parameters which would interfere with parameters that\n    we use.\n\n    The first character of \"param\" string must be a \"-\" (dash).\n\n    \"value\" can be NULL.\n\n",
  .run = run_config
};

struct command_entry set_qemu_cmd_entry = {
  .name = "set-qemu",
  .help = "NAME\n    set-qemu - set the qemu binary\n\nSYNOPSIS\n     set-qemu qemu\n\nDESCRIPTION\n    Set the qemu binary that we will use.\n\n    The default is chosen when the library was compiled by the configure\n    script.\n\n    You can also override this by setting the \"LIBGUESTFS_QEMU\" environment\n    variable.\n\n    Setting \"qemu\" to \"NULL\" restores the default qemu binary.\n\n    Note that you should call this function as early as possible after\n    creating the handle. This is because some pre-launch operations depend\n    on testing qemu features (by running \"qemu -help\"). If the qemu binary\n    changes, we don't retest features, and so you might see inconsistent\n    results. Using the environment variable \"LIBGUESTFS_QEMU\" is safest of\n    all since that picks the qemu binary at the same time as the handle is\n    created.\n\n    You can use 'qemu' as an alias for this command.\n\n",
  .run = run_set_qemu
};

struct command_entry get_qemu_cmd_entry = {
  .name = "get-qemu",
  .help = "NAME\n    get-qemu - get the qemu binary\n\nSYNOPSIS\n     get-qemu\n\nDESCRIPTION\n    Return the current qemu binary.\n\n    This is always non-NULL. If it wasn't set already, then this will return\n    the default qemu binary name.\n\n",
  .run = run_get_qemu
};

struct command_entry set_path_cmd_entry = {
  .name = "set-path",
  .help = "NAME\n    set-path - set the search path\n\nSYNOPSIS\n     set-path searchpath\n\nDESCRIPTION\n    Set the path that libguestfs searches for kernel and initrd.img.\n\n    The default is \"$libdir/guestfs\" unless overridden by setting\n    \"LIBGUESTFS_PATH\" environment variable.\n\n    Setting \"path\" to \"NULL\" restores the default path.\n\n    You can use 'path' as an alias for this command.\n\n",
  .run = run_set_path
};

struct command_entry get_path_cmd_entry = {
  .name = "get-path",
  .help = "NAME\n    get-path - get the search path\n\nSYNOPSIS\n     get-path\n\nDESCRIPTION\n    Return the current search path.\n\n    This is always non-NULL. If it wasn't set already, then this will return\n    the default path.\n\n",
  .run = run_get_path
};

struct command_entry set_append_cmd_entry = {
  .name = "set-append",
  .help = "NAME\n    set-append - add options to kernel command line\n\nSYNOPSIS\n     set-append append\n\nDESCRIPTION\n    This function is used to add additional options to the guest kernel\n    command line.\n\n    The default is \"NULL\" unless overridden by setting \"LIBGUESTFS_APPEND\"\n    environment variable.\n\n    Setting \"append\" to \"NULL\" means *no* additional options are passed\n    (libguestfs always adds a few of its own).\n\n    You can use 'append' as an alias for this command.\n\n",
  .run = run_set_append
};

struct command_entry get_append_cmd_entry = {
  .name = "get-append",
  .help = "NAME\n    get-append - get the additional kernel options\n\nSYNOPSIS\n     get-append\n\nDESCRIPTION\n    Return the additional kernel options which are added to the guest kernel\n    command line.\n\n    If \"NULL\" then no options are added.\n\n",
  .run = run_get_append
};

struct command_entry set_autosync_cmd_entry = {
  .name = "set-autosync",
  .help = "NAME\n    set-autosync - set autosync mode\n\nSYNOPSIS\n     set-autosync autosync\n\nDESCRIPTION\n    If \"autosync\" is true, this enables autosync. Libguestfs will make a\n    best effort attempt to make filesystems consistent and synchronized when\n    the handle is closed (also if the program exits without closing\n    handles).\n\n    This is enabled by default (since libguestfs 1.5.24, previously it was\n    disabled by default).\n\n    You can use 'autosync' as an alias for this command.\n\n",
  .run = run_set_autosync
};

struct command_entry get_autosync_cmd_entry = {
  .name = "get-autosync",
  .help = "NAME\n    get-autosync - get autosync mode\n\nSYNOPSIS\n     get-autosync\n\nDESCRIPTION\n    Get the autosync flag.\n\n",
  .run = run_get_autosync
};

struct command_entry set_verbose_cmd_entry = {
  .name = "set-verbose",
  .help = "NAME\n    set-verbose - set verbose mode\n\nSYNOPSIS\n     set-verbose verbose\n\nDESCRIPTION\n    If \"verbose\" is true, this turns on verbose messages.\n\n    Verbose messages are disabled unless the environment variable\n    \"LIBGUESTFS_DEBUG\" is defined and set to 1.\n\n    Verbose messages are normally sent to \"stderr\", unless you register a\n    callback to send them somewhere else (see \"set_event_callback\").\n\n    You can use 'verbose' as an alias for this command.\n\n",
  .run = run_set_verbose
};

struct command_entry get_verbose_cmd_entry = {
  .name = "get-verbose",
  .help = "NAME\n    get-verbose - get verbose mode\n\nSYNOPSIS\n     get-verbose\n\nDESCRIPTION\n    This returns the verbose messages flag.\n\n",
  .run = run_get_verbose
};

struct command_entry is_ready_cmd_entry = {
  .name = "is-ready",
  .help = "NAME\n    is-ready - is ready to accept commands\n\nSYNOPSIS\n     is-ready\n\nDESCRIPTION\n    This returns true iff this handle is ready to accept commands (in the\n    \"READY\" state).\n\n    For more information on states, see guestfs(3).\n\n",
  .run = run_is_ready
};

struct command_entry is_config_cmd_entry = {
  .name = "is-config",
  .help = "NAME\n    is-config - is in configuration state\n\nSYNOPSIS\n     is-config\n\nDESCRIPTION\n    This returns true iff this handle is being configured (in the \"CONFIG\"\n    state).\n\n    For more information on states, see guestfs(3).\n\n",
  .run = run_is_config
};

struct command_entry is_launching_cmd_entry = {
  .name = "is-launching",
  .help = "NAME\n    is-launching - is launching subprocess\n\nSYNOPSIS\n     is-launching\n\nDESCRIPTION\n    This returns true iff this handle is launching the subprocess (in the\n    \"LAUNCHING\" state).\n\n    For more information on states, see guestfs(3).\n\n",
  .run = run_is_launching
};

struct command_entry is_busy_cmd_entry = {
  .name = "is-busy",
  .help = "NAME\n    is-busy - is busy processing a command\n\nSYNOPSIS\n     is-busy\n\nDESCRIPTION\n    This returns true iff this handle is busy processing a command (in the\n    \"BUSY\" state).\n\n    For more information on states, see guestfs(3).\n\n",
  .run = run_is_busy
};

struct command_entry get_state_cmd_entry = {
  .name = "get-state",
  .help = "NAME\n    get-state - get the current state\n\nSYNOPSIS\n     get-state\n\nDESCRIPTION\n    This returns the current state as an opaque integer. This is only useful\n    for printing debug and internal error messages.\n\n    For more information on states, see guestfs(3).\n\n",
  .run = run_get_state
};

struct command_entry set_memsize_cmd_entry = {
  .name = "set-memsize",
  .help = "NAME\n    set-memsize - set memory allocated to the qemu subprocess\n\nSYNOPSIS\n     set-memsize memsize\n\nDESCRIPTION\n    This sets the memory size in megabytes allocated to the qemu subprocess.\n    This only has any effect if called before \"launch\".\n\n    You can also change this by setting the environment variable\n    \"LIBGUESTFS_MEMSIZE\" before the handle is created.\n\n    For more information on the architecture of libguestfs, see guestfs(3).\n\n    You can use 'memsize' as an alias for this command.\n\n",
  .run = run_set_memsize
};

struct command_entry get_memsize_cmd_entry = {
  .name = "get-memsize",
  .help = "NAME\n    get-memsize - get memory allocated to the qemu subprocess\n\nSYNOPSIS\n     get-memsize\n\nDESCRIPTION\n    This gets the memory size in megabytes allocated to the qemu subprocess.\n\n    If \"set_memsize\" was not called on this handle, and if\n    \"LIBGUESTFS_MEMSIZE\" was not set, then this returns the compiled-in\n    default value for memsize.\n\n    For more information on the architecture of libguestfs, see guestfs(3).\n\n",
  .run = run_get_memsize
};

struct command_entry get_pid_cmd_entry = {
  .name = "get-pid",
  .help = "NAME\n    get-pid - get PID of qemu subprocess\n\nSYNOPSIS\n     get-pid\n\nDESCRIPTION\n    Return the process ID of the qemu subprocess. If there is no qemu\n    subprocess, then this will return an error.\n\n    This is an internal call used for debugging and testing.\n\n    You can use 'pid' as an alias for this command.\n\n",
  .run = run_get_pid
};

struct command_entry version_cmd_entry = {
  .name = "version",
  .help = "NAME\n    version - get the library version number\n\nSYNOPSIS\n     version\n\nDESCRIPTION\n    Return the libguestfs version number that the program is linked against.\n\n    Note that because of dynamic linking this is not necessarily the version\n    of libguestfs that you compiled against. You can compile the program,\n    and then at runtime dynamically link against a completely different\n    \"libguestfs.so\" library.\n\n    This call was added in version 1.0.58. In previous versions of\n    libguestfs there was no way to get the version number. From C code you\n    can use dynamic linker functions to find out if this symbol exists (if\n    it doesn't, then it's an earlier version).\n\n    The call returns a structure with four elements. The first three\n    (\"major\", \"minor\" and \"release\") are numbers and correspond to the usual\n    version triplet. The fourth element (\"extra\") is a string and is\n    normally empty, but may be used for distro-specific information.\n\n    To construct the original version string: \"$major.$minor.$release$extra\"\n\n    See also: \"LIBGUESTFS VERSION NUMBERS\" in guestfs(3).\n\n    *Note:* Don't use this call to test for availability of features. In\n    enterprise distributions we backport features from later versions into\n    earlier versions, making this an unreliable way to test for features.\n    Use \"available\" instead.\n\n",
  .run = run_version
};

struct command_entry set_selinux_cmd_entry = {
  .name = "set-selinux",
  .help = "NAME\n    set-selinux - set SELinux enabled or disabled at appliance boot\n\nSYNOPSIS\n     set-selinux selinux\n\nDESCRIPTION\n    This sets the selinux flag that is passed to the appliance at boot time.\n    The default is \"selinux=0\" (disabled).\n\n    Note that if SELinux is enabled, it is always in Permissive mode\n    (\"enforcing=0\").\n\n    For more information on the architecture of libguestfs, see guestfs(3).\n\n    You can use 'selinux' as an alias for this command.\n\n",
  .run = run_set_selinux
};

struct command_entry get_selinux_cmd_entry = {
  .name = "get-selinux",
  .help = "NAME\n    get-selinux - get SELinux enabled flag\n\nSYNOPSIS\n     get-selinux\n\nDESCRIPTION\n    This returns the current setting of the selinux flag which is passed to\n    the appliance at boot time. See \"set_selinux\".\n\n    For more information on the architecture of libguestfs, see guestfs(3).\n\n",
  .run = run_get_selinux
};

struct command_entry set_trace_cmd_entry = {
  .name = "set-trace",
  .help = "NAME\n    set-trace - enable or disable command traces\n\nSYNOPSIS\n     set-trace trace\n\nDESCRIPTION\n    If the command trace flag is set to 1, then libguestfs calls, parameters\n    and return values are traced.\n\n    If you want to trace C API calls into libguestfs (and other libraries)\n    then possibly a better way is to use the external ltrace(1) command.\n\n    Command traces are disabled unless the environment variable\n    \"LIBGUESTFS_TRACE\" is defined and set to 1.\n\n    Trace messages are normally sent to \"stderr\", unless you register a\n    callback to send them somewhere else (see \"set_event_callback\").\n\n    You can use 'trace' as an alias for this command.\n\n",
  .run = run_set_trace
};

struct command_entry get_trace_cmd_entry = {
  .name = "get-trace",
  .help = "NAME\n    get-trace - get command trace enabled flag\n\nSYNOPSIS\n     get-trace\n\nDESCRIPTION\n    Return the command trace flag.\n\n",
  .run = run_get_trace
};

struct command_entry set_direct_cmd_entry = {
  .name = "set-direct",
  .help = "NAME\n    set-direct - enable or disable direct appliance mode\n\nSYNOPSIS\n     set-direct direct\n\nDESCRIPTION\n    If the direct appliance mode flag is enabled, then stdin and stdout are\n    passed directly through to the appliance once it is launched.\n\n    One consequence of this is that log messages aren't caught by the\n    library and handled by \"set_log_message_callback\", but go straight to\n    stdout.\n\n    You probably don't want to use this unless you know what you are doing.\n\n    The default is disabled.\n\n    You can use 'direct' as an alias for this command.\n\n",
  .run = run_set_direct
};

struct command_entry get_direct_cmd_entry = {
  .name = "get-direct",
  .help = "NAME\n    get-direct - get direct appliance mode flag\n\nSYNOPSIS\n     get-direct\n\nDESCRIPTION\n    Return the direct appliance mode flag.\n\n",
  .run = run_get_direct
};

struct command_entry set_recovery_proc_cmd_entry = {
  .name = "set-recovery-proc",
  .help = "NAME\n    set-recovery-proc - enable or disable the recovery process\n\nSYNOPSIS\n     set-recovery-proc recoveryproc\n\nDESCRIPTION\n    If this is called with the parameter \"false\" then \"launch\" does not\n    create a recovery process. The purpose of the recovery process is to\n    stop runaway qemu processes in the case where the main program aborts\n    abruptly.\n\n    This only has any effect if called before \"launch\", and the default is\n    true.\n\n    About the only time when you would want to disable this is if the main\n    process will fork itself into the background (\"daemonize\" itself). In\n    this case the recovery process thinks that the main program has\n    disappeared and so kills qemu, which is not very helpful.\n\n    You can use 'recovery-proc' as an alias for this command.\n\n",
  .run = run_set_recovery_proc
};

struct command_entry get_recovery_proc_cmd_entry = {
  .name = "get-recovery-proc",
  .help = "NAME\n    get-recovery-proc - get recovery process enabled flag\n\nSYNOPSIS\n     get-recovery-proc\n\nDESCRIPTION\n    Return the recovery process enabled flag.\n\n",
  .run = run_get_recovery_proc
};

struct command_entry add_drive_with_if_cmd_entry = {
  .name = "add-drive-with-if",
  .help = "NAME\n    add-drive-with-if - add a drive specifying the QEMU block emulation to\n    use\n\nSYNOPSIS\n     add-drive-with-if filename iface\n\nDESCRIPTION\n    This is the same as \"add_drive\" but it allows you to specify the QEMU\n    interface emulation to use at run time.\n\n    *This function is deprecated.* In new code, use the \"add_drive_opts\"\n    call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_add_drive_with_if
};

struct command_entry add_drive_ro_with_if_cmd_entry = {
  .name = "add-drive-ro-with-if",
  .help = "NAME\n    add-drive-ro-with-if - add a drive read-only specifying the QEMU block\n    emulation to use\n\nSYNOPSIS\n     add-drive-ro-with-if filename iface\n\nDESCRIPTION\n    This is the same as \"add_drive_ro\" but it allows you to specify the QEMU\n    interface emulation to use at run time.\n\n    *This function is deprecated.* In new code, use the \"add_drive_opts\"\n    call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_add_drive_ro_with_if
};

struct command_entry file_architecture_cmd_entry = {
  .name = "file-architecture",
  .help = "NAME\n    file-architecture - detect the architecture of a binary file\n\nSYNOPSIS\n     file-architecture filename\n\nDESCRIPTION\n    This detects the architecture of the binary \"filename\", and returns it\n    if known.\n\n    Currently defined architectures are:\n\n    \"i386\"\n        This string is returned for all 32 bit i386, i486, i586, i686\n        binaries irrespective of the precise processor requirements of the\n        binary.\n\n    \"x86_64\"\n        64 bit x86-64.\n\n    \"sparc\"\n        32 bit SPARC.\n\n    \"sparc64\"\n        64 bit SPARC V9 and above.\n\n    \"ia64\"\n        Intel Itanium.\n\n    \"ppc\"\n        32 bit Power PC.\n\n    \"ppc64\"\n        64 bit Power PC.\n\n    Libguestfs may return other architecture strings in future.\n\n    The function works on at least the following types of files:\n\n    *   many types of Un*x and Linux binary\n\n    *   many types of Un*x and Linux shared library\n\n    *   Windows Win32 and Win64 binaries\n\n    *   Windows Win32 and Win64 DLLs\n\n        Win32 binaries and DLLs return \"i386\".\n\n        Win64 binaries and DLLs return \"x86_64\".\n\n    *   Linux kernel modules\n\n    *   Linux new-style initrd images\n\n    *   some non-x86 Linux vmlinuz kernels\n\n    What it can't do currently:\n\n    *   static libraries (libfoo.a)\n\n    *   Linux old-style initrd as compressed ext2 filesystem (RHEL 3)\n\n    *   x86 Linux vmlinuz kernels\n\n        x86 vmlinuz images (bzImage format) consist of a mix of 16-, 32- and\n        compressed code, and are horribly hard to unpack. If you want to\n        find the architecture of a kernel, use the architecture of the\n        associated initrd or kernel module(s) instead.\n\n",
  .run = run_file_architecture
};

struct command_entry inspect_os_cmd_entry = {
  .name = "inspect-os",
  .help = "NAME\n    inspect-os - inspect disk and return list of operating systems found\n\nSYNOPSIS\n     inspect-os\n\nDESCRIPTION\n    This function uses other libguestfs functions and certain heuristics to\n    inspect the disk(s) (usually disks belonging to a virtual machine),\n    looking for operating systems.\n\n    The list returned is empty if no operating systems were found.\n\n    If one operating system was found, then this returns a list with a\n    single element, which is the name of the root filesystem of this\n    operating system. It is also possible for this function to return a list\n    containing more than one element, indicating a dual-boot or multi-boot\n    virtual machine, with each element being the root filesystem of one of\n    the operating systems.\n\n    You can pass the root string(s) returned to other \"inspect_get_*\"\n    functions in order to query further information about each operating\n    system, such as the name and version.\n\n    This function uses other libguestfs features such as \"mount_ro\" and\n    \"umount_all\" in order to mount and unmount filesystems and look at the\n    contents. This should be called with no disks currently mounted. The\n    function may also use Augeas, so any existing Augeas handle will be\n    closed.\n\n    This function cannot decrypt encrypted disks. The caller must do that\n    first (supplying the necessary keys) if the disk is encrypted.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n    See also \"list_filesystems\".\n\n",
  .run = run_inspect_os
};

struct command_entry inspect_get_type_cmd_entry = {
  .name = "inspect-get-type",
  .help = "NAME\n    inspect-get-type - get type of inspected operating system\n\nSYNOPSIS\n     inspect-get-type root\n\nDESCRIPTION\n    This returns the type of the inspected operating system. Currently\n    defined types are:\n\n    \"linux\"\n        Any Linux-based operating system.\n\n    \"windows\"\n        Any Microsoft Windows operating system.\n\n    \"freebsd\"\n        FreeBSD.\n\n    \"netbsd\"\n        NetBSD.\n\n    \"hurd\"\n        GNU/Hurd.\n\n    \"unknown\"\n        The operating system type could not be determined.\n\n    Future versions of libguestfs may return other strings here. The caller\n    should be prepared to handle any string.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_type
};

struct command_entry inspect_get_arch_cmd_entry = {
  .name = "inspect-get-arch",
  .help = "NAME\n    inspect-get-arch - get architecture of inspected operating system\n\nSYNOPSIS\n     inspect-get-arch root\n\nDESCRIPTION\n    This returns the architecture of the inspected operating system. The\n    possible return values are listed under \"file_architecture\".\n\n    If the architecture could not be determined, then the string \"unknown\"\n    is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_arch
};

struct command_entry inspect_get_distro_cmd_entry = {
  .name = "inspect-get-distro",
  .help = "NAME\n    inspect-get-distro - get distro of inspected operating system\n\nSYNOPSIS\n     inspect-get-distro root\n\nDESCRIPTION\n    This returns the distro (distribution) of the inspected operating\n    system.\n\n    Currently defined distros are:\n\n    \"archlinux\"\n        Arch Linux.\n\n    \"centos\"\n        CentOS.\n\n    \"debian\"\n        Debian.\n\n    \"fedora\"\n        Fedora.\n\n    \"gentoo\"\n        Gentoo.\n\n    \"linuxmint\"\n        Linux Mint.\n\n    \"mageia\"\n        Mageia.\n\n    \"mandriva\"\n        Mandriva.\n\n    \"meego\"\n        MeeGo.\n\n    \"opensuse\"\n        OpenSUSE.\n\n    \"pardus\"\n        Pardus.\n\n    \"redhat-based\"\n        Some Red Hat-derived distro.\n\n    \"rhel\"\n        Red Hat Enterprise Linux.\n\n    \"scientificlinux\"\n        Scientific Linux.\n\n    \"slackware\"\n        Slackware.\n\n    \"ttylinux\"\n        ttylinux.\n\n    \"ubuntu\"\n        Ubuntu.\n\n    \"unknown\"\n        The distro could not be determined.\n\n    \"windows\"\n        Windows does not have distributions. This string is returned if the\n        OS type is Windows.\n\n    Future versions of libguestfs may return other strings here. The caller\n    should be prepared to handle any string.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_distro
};

struct command_entry inspect_get_major_version_cmd_entry = {
  .name = "inspect-get-major-version",
  .help = "NAME\n    inspect-get-major-version - get major version of inspected operating\n    system\n\nSYNOPSIS\n     inspect-get-major-version root\n\nDESCRIPTION\n    This returns the major version number of the inspected operating system.\n\n    Windows uses a consistent versioning scheme which is *not* reflected in\n    the popular public names used by the operating system. Notably the\n    operating system known as \"Windows 7\" is really version 6.1 (ie. major =\n    6, minor = 1). You can find out the real versions corresponding to\n    releases of Windows by consulting Wikipedia or MSDN.\n\n    If the version could not be determined, then 0 is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_major_version
};

struct command_entry inspect_get_minor_version_cmd_entry = {
  .name = "inspect-get-minor-version",
  .help = "NAME\n    inspect-get-minor-version - get minor version of inspected operating\n    system\n\nSYNOPSIS\n     inspect-get-minor-version root\n\nDESCRIPTION\n    This returns the minor version number of the inspected operating system.\n\n    If the version could not be determined, then 0 is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n    \"inspect_get_major_version\".\n\n",
  .run = run_inspect_get_minor_version
};

struct command_entry inspect_get_product_name_cmd_entry = {
  .name = "inspect-get-product-name",
  .help = "NAME\n    inspect-get-product-name - get product name of inspected operating\n    system\n\nSYNOPSIS\n     inspect-get-product-name root\n\nDESCRIPTION\n    This returns the product name of the inspected operating system. The\n    product name is generally some freeform string which can be displayed to\n    the user, but should not be parsed by programs.\n\n    If the product name could not be determined, then the string \"unknown\"\n    is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_product_name
};

struct command_entry inspect_get_mountpoints_cmd_entry = {
  .name = "inspect-get-mountpoints",
  .help = "NAME\n    inspect-get-mountpoints - get mountpoints of inspected operating system\n\nSYNOPSIS\n     inspect-get-mountpoints root\n\nDESCRIPTION\n    This returns a hash of where we think the filesystems associated with\n    this operating system should be mounted. Callers should note that this\n    is at best an educated guess made by reading configuration files such as\n    \"/etc/fstab\". *In particular note* that this may return filesystems\n    which are non-existent or not mountable and callers should be prepared\n    to handle or ignore failures if they try to mount them.\n\n    Each element in the returned hashtable has a key which is the path of\n    the mountpoint (eg. \"/boot\") and a value which is the filesystem that\n    would be mounted there (eg. \"/dev/sda1\").\n\n    Non-mounted devices such as swap devices are *not* returned in this\n    list.\n\n    For operating systems like Windows which still use drive letters, this\n    call will only return an entry for the first drive \"mounted on\" \"/\". For\n    information about the mapping of drive letters to partitions, see\n    \"inspect_get_drive_mappings\".\n\n    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n    \"inspect_get_filesystems\".\n\n",
  .run = run_inspect_get_mountpoints
};

struct command_entry inspect_get_filesystems_cmd_entry = {
  .name = "inspect-get-filesystems",
  .help = "NAME\n    inspect-get-filesystems - get filesystems associated with inspected\n    operating system\n\nSYNOPSIS\n     inspect-get-filesystems root\n\nDESCRIPTION\n    This returns a list of all the filesystems that we think are associated\n    with this operating system. This includes the root filesystem, other\n    ordinary filesystems, and non-mounted devices like swap partitions.\n\n    In the case of a multi-boot virtual machine, it is possible for a\n    filesystem to be shared between operating systems.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n    \"inspect_get_mountpoints\".\n\n",
  .run = run_inspect_get_filesystems
};

struct command_entry set_network_cmd_entry = {
  .name = "set-network",
  .help = "NAME\n    set-network - set enable network flag\n\nSYNOPSIS\n     set-network network\n\nDESCRIPTION\n    If \"network\" is true, then the network is enabled in the libguestfs\n    appliance. The default is false.\n\n    This affects whether commands are able to access the network (see\n    \"RUNNING COMMANDS\" in guestfs(3)).\n\n    You must call this before calling \"launch\", otherwise it has no effect.\n\n    You can use 'network' as an alias for this command.\n\n",
  .run = run_set_network
};

struct command_entry get_network_cmd_entry = {
  .name = "get-network",
  .help = "NAME\n    get-network - get enable network flag\n\nSYNOPSIS\n     get-network\n\nDESCRIPTION\n    This returns the enable network flag.\n\n",
  .run = run_get_network
};

struct command_entry list_filesystems_cmd_entry = {
  .name = "list-filesystems",
  .help = "NAME\n    list-filesystems - list filesystems\n\nSYNOPSIS\n     list-filesystems\n\nDESCRIPTION\n    This inspection command looks for filesystems on partitions, block\n    devices and logical volumes, returning a list of devices containing\n    filesystems and their type.\n\n    The return value is a hash, where the keys are the devices containing\n    filesystems, and the values are the filesystem types. For example:\n\n     \"/dev/sda1\" => \"ntfs\"\n     \"/dev/sda2\" => \"ext2\"\n     \"/dev/vg_guest/lv_root\" => \"ext4\"\n     \"/dev/vg_guest/lv_swap\" => \"swap\"\n\n    The value can have the special value \"unknown\", meaning the content of\n    the device is undetermined or empty. \"swap\" means a Linux swap\n    partition.\n\n    This command runs other libguestfs commands, which might include \"mount\"\n    and \"umount\", and therefore you should use this soon after launch and\n    only when nothing is mounted.\n\n    Not all of the filesystems returned will be mountable. In particular,\n    swap partitions are returned in the list. Also this command does not\n    check that each filesystem found is valid and mountable, and some\n    filesystems might be mountable but require special options. Filesystems\n    may not all belong to a single logical operating system (use\n    \"inspect_os\" to look for OSes).\n\n",
  .run = run_list_filesystems
};

struct command_entry add_drive_opts_cmd_entry = {
  .name = "add-drive-opts",
  .help = "NAME\n    add-drive-opts - add an image to examine or modify\n\nSYNOPSIS\n     add-drive-opts filename [readonly:true|false] [format:..] [iface:..] [name:..]\n\nDESCRIPTION\n    This function adds a virtual machine disk image \"filename\" to\n    libguestfs. The first time you call this function, the disk appears as\n    \"/dev/sda\", the second time as \"/dev/sdb\", and so on.\n\n    You don't necessarily need to be root when using libguestfs. However you\n    obviously do need sufficient permissions to access the filename for\n    whatever operations you want to perform (ie. read access if you just\n    want to read the image or write access if you want to modify the image).\n\n    This call checks that \"filename\" exists.\n\n    The optional arguments are:\n\n    \"readonly\"\n        If true then the image is treated as read-only. Writes are still\n        allowed, but they are stored in a temporary snapshot overlay which\n        is discarded at the end. The disk that you add is not modified.\n\n    \"format\"\n        This forces the image format. If you omit this (or use \"add_drive\"\n        or \"add_drive_ro\") then the format is automatically detected.\n        Possible formats include \"raw\" and \"qcow2\".\n\n        Automatic detection of the format opens you up to a potential\n        security hole when dealing with untrusted raw-format images. See\n        CVE-2010-3851 and RHBZ#642934. Specifying the format closes this\n        security hole.\n\n    \"iface\"\n        This rarely-used option lets you emulate the behaviour of the\n        deprecated \"add_drive_with_if\" call (q.v.)\n\n    \"name\"\n        The name the drive had in the original guest, e.g. /dev/sdb. This is\n        used as a hint to the guest inspection process if it is available.\n\n    You can use 'add' as an alias for this command.\n\n",
  .run = run_add_drive_opts
};

struct command_entry inspect_get_windows_systemroot_cmd_entry = {
  .name = "inspect-get-windows-systemroot",
  .help = "NAME\n    inspect-get-windows-systemroot - get Windows systemroot of inspected\n    operating system\n\nSYNOPSIS\n     inspect-get-windows-systemroot root\n\nDESCRIPTION\n    This returns the Windows systemroot of the inspected guest. The\n    systemroot is a directory path such as \"/WINDOWS\".\n\n    This call assumes that the guest is Windows and that the systemroot\n    could be determined by inspection. If this is not the case then an error\n    is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_windows_systemroot
};

struct command_entry inspect_get_roots_cmd_entry = {
  .name = "inspect-get-roots",
  .help = "NAME\n    inspect-get-roots - return list of operating systems found by last\n    inspection\n\nSYNOPSIS\n     inspect-get-roots\n\nDESCRIPTION\n    This function is a convenient way to get the list of root devices, as\n    returned from a previous call to \"inspect_os\", but without redoing the\n    whole inspection process.\n\n    This returns an empty list if either no root devices were found or the\n    caller has not called \"inspect_os\".\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_roots
};

struct command_entry debug_cmdline_cmd_entry = {
  .name = "debug-cmdline",
  .help = "NAME\n    debug-cmdline - debug the QEMU command line (internal use only)\n\nSYNOPSIS\n     debug-cmdline\n\nDESCRIPTION\n    This returns the internal QEMU command line. 'debug' commands are not\n    part of the formal API and can be removed or changed at any time.\n\n",
  .run = run_debug_cmdline
};

struct command_entry debug_drives_cmd_entry = {
  .name = "debug-drives",
  .help = "NAME\n    debug-drives - debug the drives (internal use only)\n\nSYNOPSIS\n     debug-drives\n\nDESCRIPTION\n    This returns the internal list of drives. 'debug' commands are not part\n    of the formal API and can be removed or changed at any time.\n\n",
  .run = run_debug_drives
};

struct command_entry add_domain_cmd_entry = {
  .name = "add-domain",
  .help = "NAME\n    add-domain - add the disk(s) from a named libvirt domain\n\nSYNOPSIS\n     add-domain dom [libvirturi:..] [readonly:true|false] [iface:..] [live:true|false] [allowuuid:true|false] [readonlydisk:..]\n\nDESCRIPTION\n    This function adds the disk(s) attached to the named libvirt domain\n    \"dom\". It works by connecting to libvirt, requesting the domain and\n    domain XML from libvirt, parsing it for disks, and calling\n    \"add_drive_opts\" on each one.\n\n    The number of disks added is returned. This operation is atomic: if an\n    error is returned, then no disks are added.\n\n    This function does some minimal checks to make sure the libvirt domain\n    is not running (unless \"readonly\" is true). In a future version we will\n    try to acquire the libvirt lock on each disk.\n\n    Disks must be accessible locally. This often means that adding disks\n    from a remote libvirt connection (see <http://libvirt.org/remote.html>)\n    will fail unless those disks are accessible via the same device path\n    locally too.\n\n    The optional \"libvirturi\" parameter sets the libvirt URI (see\n    <http://libvirt.org/uri.html>). If this is not set then we connect to\n    the default libvirt URI (or one set through an environment variable, see\n    the libvirt documentation for full details).\n\n    The optional \"live\" flag controls whether this call will try to connect\n    to a running virtual machine \"guestfsd\" process if it sees a suitable\n    <channel> element in the libvirt XML definition. The default (if the\n    flag is omitted) is never to try. See \"ATTACHING TO RUNNING DAEMONS\" in\n    guestfs(3) for more information.\n\n    If the \"allowuuid\" flag is true (default is false) then a UUID *may* be\n    passed instead of the domain name. The \"dom\" string is treated as a UUID\n    first and looked up, and if that lookup fails then we treat \"dom\" as a\n    name as usual.\n\n    The optional \"readonlydisk\" parameter controls what we do for disks\n    which are marked <readonly/> in the libvirt XML. Possible values are:\n\n    readonlydisk = \"error\"\n        If \"readonly\" is false:\n\n        The whole call is aborted with an error if any disk with the\n        <readonly/> flag is found.\n\n        If \"readonly\" is true:\n\n        Disks with the <readonly/> flag are added read-only.\n\n    readonlydisk = \"read\"\n        If \"readonly\" is false:\n\n        Disks with the <readonly/> flag are added read-only. Other disks are\n        added read/write.\n\n        If \"readonly\" is true:\n\n        Disks with the <readonly/> flag are added read-only.\n\n    readonlydisk = \"write\" (default)\n        If \"readonly\" is false:\n\n        Disks with the <readonly/> flag are added read/write.\n\n        If \"readonly\" is true:\n\n        Disks with the <readonly/> flag are added read-only.\n\n    readonlydisk = \"ignore\"\n        If \"readonly\" is true or false:\n\n        Disks with the <readonly/> flag are skipped.\n\n    The other optional parameters are passed directly through to\n    \"add_drive_opts\".\n\n    You can use 'domain' as an alias for this command.\n\n",
  .run = run_add_domain
};

struct command_entry inspect_get_package_format_cmd_entry = {
  .name = "inspect-get-package-format",
  .help = "NAME\n    inspect-get-package-format - get package format used by the operating\n    system\n\nSYNOPSIS\n     inspect-get-package-format root\n\nDESCRIPTION\n    This function and \"inspect_get_package_management\" return the package\n    format and package management tool used by the inspected operating\n    system. For example for Fedora these functions would return \"rpm\"\n    (package format) and \"yum\" (package management).\n\n    This returns the string \"unknown\" if we could not determine the package\n    format *or* if the operating system does not have a real packaging\n    system (eg. Windows).\n\n    Possible strings include: \"rpm\", \"deb\", \"ebuild\", \"pisi\", \"pacman\",\n    \"pkgsrc\". Future versions of libguestfs may return other strings.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_package_format
};

struct command_entry inspect_get_package_management_cmd_entry = {
  .name = "inspect-get-package-management",
  .help = "NAME\n    inspect-get-package-management - get package management tool used by the\n    operating system\n\nSYNOPSIS\n     inspect-get-package-management root\n\nDESCRIPTION\n    \"inspect_get_package_format\" and this function return the package format\n    and package management tool used by the inspected operating system. For\n    example for Fedora these functions would return \"rpm\" (package format)\n    and \"yum\" (package management).\n\n    This returns the string \"unknown\" if we could not determine the package\n    management tool *or* if the operating system does not have a real\n    packaging system (eg. Windows).\n\n    Possible strings include: \"yum\", \"up2date\", \"apt\" (for all Debian\n    derivatives), \"portage\", \"pisi\", \"pacman\", \"urpmi\", \"zypper\". Future\n    versions of libguestfs may return other strings.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_package_management
};

struct command_entry inspect_list_applications_cmd_entry = {
  .name = "inspect-list-applications",
  .help = "NAME\n    inspect-list-applications - get list of applications installed in the\n    operating system\n\nSYNOPSIS\n     inspect-list-applications root\n\nDESCRIPTION\n    Return the list of applications installed in the operating system.\n\n    *Note:* This call works differently from other parts of the inspection\n    API. You have to call \"inspect_os\", then \"inspect_get_mountpoints\", then\n    mount up the disks, before calling this. Listing applications is a\n    significantly more difficult operation which requires access to the full\n    filesystem. Also note that unlike the other \"inspect_get_*\" calls which\n    are just returning data cached in the libguestfs handle, this call\n    actually reads parts of the mounted filesystems during the call.\n\n    This returns an empty list if the inspection code was not able to\n    determine the list of applications.\n\n    The application structure contains the following fields:\n\n    \"app_name\"\n        The name of the application. For Red Hat-derived and Debian-derived\n        Linux guests, this is the package name.\n\n    \"app_display_name\"\n        The display name of the application, sometimes localized to the\n        install language of the guest operating system.\n\n        If unavailable this is returned as an empty string \"\". Callers\n        needing to display something can use \"app_name\" instead.\n\n    \"app_epoch\"\n        For package managers which use epochs, this contains the epoch of\n        the package (an integer). If unavailable, this is returned as 0.\n\n    \"app_version\"\n        The version string of the application or package. If unavailable\n        this is returned as an empty string \"\".\n\n    \"app_release\"\n        The release string of the application or package, for package\n        managers that use this. If unavailable this is returned as an empty\n        string \"\".\n\n    \"app_install_path\"\n        The installation path of the application (on operating systems such\n        as Windows which use installation paths). This path is in the format\n        used by the guest operating system, it is not a libguestfs path.\n\n        If unavailable this is returned as an empty string \"\".\n\n    \"app_trans_path\"\n        The install path translated into a libguestfs path. If unavailable\n        this is returned as an empty string \"\".\n\n    \"app_publisher\"\n        The name of the publisher of the application, for package managers\n        that use this. If unavailable this is returned as an empty string\n        \"\".\n\n    \"app_url\"\n        The URL (eg. upstream URL) of the application. If unavailable this\n        is returned as an empty string \"\".\n\n    \"app_source_package\"\n        For packaging systems which support this, the name of the source\n        package. If unavailable this is returned as an empty string \"\".\n\n    \"app_summary\"\n        A short (usually one line) description of the application or\n        package. If unavailable this is returned as an empty string \"\".\n\n    \"app_description\"\n        A longer description of the application or package. If unavailable\n        this is returned as an empty string \"\".\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_list_applications
};

struct command_entry inspect_get_hostname_cmd_entry = {
  .name = "inspect-get-hostname",
  .help = "NAME\n    inspect-get-hostname - get hostname of the operating system\n\nSYNOPSIS\n     inspect-get-hostname root\n\nDESCRIPTION\n    This function returns the hostname of the operating system as found by\n    inspection of the guest's configuration files.\n\n    If the hostname could not be determined, then the string \"unknown\" is\n    returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_hostname
};

struct command_entry inspect_get_format_cmd_entry = {
  .name = "inspect-get-format",
  .help = "NAME\n    inspect-get-format - get format of inspected operating system\n\nSYNOPSIS\n     inspect-get-format root\n\nDESCRIPTION\n    This returns the format of the inspected operating system. You can use\n    it to detect install images, live CDs and similar.\n\n    Currently defined formats are:\n\n    \"installed\"\n        This is an installed operating system.\n\n    \"installer\"\n        The disk image being inspected is not an installed operating system,\n        but a *bootable* install disk, live CD, or similar.\n\n    \"unknown\"\n        The format of this disk image is not known.\n\n    Future versions of libguestfs may return other strings here. The caller\n    should be prepared to handle any string.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_format
};

struct command_entry inspect_is_live_cmd_entry = {
  .name = "inspect-is-live",
  .help = "NAME\n    inspect-is-live - get live flag for install disk\n\nSYNOPSIS\n     inspect-is-live root\n\nDESCRIPTION\n    If \"inspect_get_format\" returns \"installer\" (this is an install disk),\n    then this returns true if a live image was detected on the disk.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_is_live
};

struct command_entry inspect_is_netinst_cmd_entry = {
  .name = "inspect-is-netinst",
  .help = "NAME\n    inspect-is-netinst - get netinst (network installer) flag for install\n    disk\n\nSYNOPSIS\n     inspect-is-netinst root\n\nDESCRIPTION\n    If \"inspect_get_format\" returns \"installer\" (this is an install disk),\n    then this returns true if the disk is a network installer, ie. not a\n    self-contained install CD but one which is likely to require network\n    access to complete the install.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_is_netinst
};

struct command_entry inspect_is_multipart_cmd_entry = {
  .name = "inspect-is-multipart",
  .help = "NAME\n    inspect-is-multipart - get multipart flag for install disk\n\nSYNOPSIS\n     inspect-is-multipart root\n\nDESCRIPTION\n    If \"inspect_get_format\" returns \"installer\" (this is an install disk),\n    then this returns true if the disk is part of a set.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_is_multipart
};

struct command_entry set_attach_method_cmd_entry = {
  .name = "set-attach-method",
  .help = "NAME\n    set-attach-method - set the attach method\n\nSYNOPSIS\n     set-attach-method attachmethod\n\nDESCRIPTION\n    Set the method that libguestfs uses to connect to the back end guestfsd\n    daemon. Possible methods are:\n\n    \"appliance\"\n        Launch an appliance and connect to it. This is the ordinary method\n        and the default.\n\n    \"unix:*path*\"\n        Connect to the Unix domain socket *path*.\n\n        This method lets you connect to an existing daemon or (using\n        virtio-serial) to a live guest. For more information, see \"ATTACHING\n        TO RUNNING DAEMONS\" in guestfs(3).\n\n    You can use 'attach-method' as an alias for this command.\n\n",
  .run = run_set_attach_method
};

struct command_entry get_attach_method_cmd_entry = {
  .name = "get-attach-method",
  .help = "NAME\n    get-attach-method - get the attach method\n\nSYNOPSIS\n     get-attach-method\n\nDESCRIPTION\n    Return the current attach method. See \"set_attach_method\".\n\n",
  .run = run_get_attach_method
};

struct command_entry inspect_get_product_variant_cmd_entry = {
  .name = "inspect-get-product-variant",
  .help = "NAME\n    inspect-get-product-variant - get product variant of inspected operating\n    system\n\nSYNOPSIS\n     inspect-get-product-variant root\n\nDESCRIPTION\n    This returns the product variant of the inspected operating system.\n\n    For Windows guests, this returns the contents of the Registry key\n    \"HKLM\\Software\\Microsoft\\Windows NT\\CurrentVersion\" \"InstallationType\"\n    which is usually a string such as \"Client\" or \"Server\" (other values are\n    possible). This can be used to distinguish consumer and enterprise\n    versions of Windows that have the same version number (for example,\n    Windows 7 and Windows 2008 Server are both version 6.1, but the former\n    is \"Client\" and the latter is \"Server\").\n\n    For enterprise Linux guests, in future we intend this to return the\n    product variant such as \"Desktop\", \"Server\" and so on. But this is not\n    implemented at present.\n\n    If the product variant could not be determined, then the string\n    \"unknown\" is returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n    \"inspect_get_product_name\", \"inspect_get_major_version\".\n\n",
  .run = run_inspect_get_product_variant
};

struct command_entry inspect_get_windows_current_control_set_cmd_entry = {
  .name = "inspect-get-windows-current-control-set",
  .help = "NAME\n    inspect-get-windows-current-control-set - get Windows CurrentControlSet\n    of inspected operating system\n\nSYNOPSIS\n     inspect-get-windows-current-control-set root\n\nDESCRIPTION\n    This returns the Windows CurrentControlSet of the inspected guest. The\n    CurrentControlSet is a registry key name such as \"ControlSet001\".\n\n    This call assumes that the guest is Windows and that the Registry could\n    be examined by inspection. If this is not the case then an error is\n    returned.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details.\n\n",
  .run = run_inspect_get_windows_current_control_set
};

struct command_entry inspect_get_drive_mappings_cmd_entry = {
  .name = "inspect-get-drive-mappings",
  .help = "NAME\n    inspect-get-drive-mappings - get drive letter mappings\n\nSYNOPSIS\n     inspect-get-drive-mappings root\n\nDESCRIPTION\n    This call is useful for Windows which uses a primitive system of\n    assigning drive letters (like \"C:\") to partitions. This inspection API\n    examines the Windows Registry to find out how disks/partitions are\n    mapped to drive letters, and returns a hash table as in the example\n    below:\n\n     C      =>     /dev/vda2\n     E      =>     /dev/vdb1\n     F      =>     /dev/vdc1\n\n    Note that keys are drive letters. For Windows, the key is case\n    insensitive and just contains the drive letter, without the customary\n    colon separator character.\n\n    In future we may support other operating systems that also used drive\n    letters, but the keys for those might not be case insensitive and might\n    be longer than 1 character. For example in OS-9, hard drives were named\n    \"h0\", \"h1\" etc.\n\n    For Windows guests, currently only hard drive mappings are returned.\n    Removable disks (eg. DVD-ROMs) are ignored.\n\n    For guests that do not use drive mappings, or if the drive mappings\n    could not be determined, this returns an empty hash table.\n\n    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n    \"inspect_get_mountpoints\", \"inspect_get_filesystems\".\n\n",
  .run = run_inspect_get_drive_mappings
};

struct command_entry inspect_get_icon_cmd_entry = {
  .name = "inspect-get-icon",
  .help = "NAME\n    inspect-get-icon - get the icon corresponding to this operating system\n\nSYNOPSIS\n     inspect-get-icon root [favicon:true|false] [highquality:true|false]\n\nDESCRIPTION\n    This function returns an icon corresponding to the inspected operating\n    system. The icon is returned as a buffer containing a PNG image\n    (re-encoded to PNG if necessary).\n\n    If it was not possible to get an icon this function returns a\n    zero-length (non-NULL) buffer. *Callers must check for this case*.\n\n    Libguestfs will start by looking for a file called \"/etc/favicon.png\" or\n    \"C:\\etc\\favicon.png\" and if it has the correct format, the contents of\n    this file will be returned. You can disable favicons by passing the\n    optional \"favicon\" boolean as false (default is true).\n\n    If finding the favicon fails, then we look in other places in the guest\n    for a suitable icon.\n\n    If the optional \"highquality\" boolean is true then only high quality\n    icons are returned, which means only icons of high resolution with an\n    alpha channel. The default (false) is to return any icon we can, even if\n    it is of substandard quality.\n\n    Notes:\n\n    *   Unlike most other inspection API calls, the guest's disks must be\n        mounted up before you call this, since it needs to read information\n        from the guest filesystem during the call.\n\n    *   Security: The icon data comes from the untrusted guest, and should\n        be treated with caution. PNG files have been known to contain\n        exploits. Ensure that libpng (or other relevant libraries) are fully\n        up to date before trying to process or display the icon.\n\n    *   The PNG image returned can be any size. It might not be square.\n        Libguestfs tries to return the largest, highest quality icon\n        available. The application must scale the icon to the required size.\n\n    *   Extracting icons from Windows guests requires the external\n        \"wrestool\" program from the \"icoutils\" package, and several programs\n        (\"bmptopnm\", \"pnmtopng\", \"pamcut\") from the \"netpbm\" package. These\n        must be installed separately.\n\n    *   Operating system icons are usually trademarks. Seek legal advice\n        before using trademarks in applications.\n\n",
  .run = run_inspect_get_icon
};

struct command_entry set_pgroup_cmd_entry = {
  .name = "set-pgroup",
  .help = "NAME\n    set-pgroup - set process group flag\n\nSYNOPSIS\n     set-pgroup pgroup\n\nDESCRIPTION\n    If \"pgroup\" is true, child processes are placed into their own process\n    group.\n\n    The practical upshot of this is that signals like \"SIGINT\" (from users\n    pressing \"^C\") won't be received by the child process.\n\n    The default for this flag is false, because usually you want \"^C\" to\n    kill the subprocess. Guestfish sets this flag to true when used\n    interactively, so that \"^C\" can cancel long-running commands gracefully\n    (see \"user_cancel\").\n\n    You can use 'pgroup' as an alias for this command.\n\n",
  .run = run_set_pgroup
};

struct command_entry get_pgroup_cmd_entry = {
  .name = "get-pgroup",
  .help = "NAME\n    get-pgroup - get process group flag\n\nSYNOPSIS\n     get-pgroup\n\nDESCRIPTION\n    This returns the process group flag.\n\n",
  .run = run_get_pgroup
};

struct command_entry set_smp_cmd_entry = {
  .name = "set-smp",
  .help = "NAME\n    set-smp - set number of virtual CPUs in appliance\n\nSYNOPSIS\n     set-smp smp\n\nDESCRIPTION\n    Change the number of virtual CPUs assigned to the appliance. The default\n    is 1. Increasing this may improve performance, though often it has no\n    effect.\n\n    This function must be called before \"launch\".\n\n    You can use 'smp' as an alias for this command.\n\n",
  .run = run_set_smp
};

struct command_entry get_smp_cmd_entry = {
  .name = "get-smp",
  .help = "NAME\n    get-smp - get number of virtual CPUs in appliance\n\nSYNOPSIS\n     get-smp\n\nDESCRIPTION\n    This returns the number of virtual CPUs assigned to the appliance.\n\n",
  .run = run_get_smp
};

struct command_entry mount_cmd_entry = {
  .name = "mount",
  .help = "NAME\n    mount - mount a guest disk at a position in the filesystem\n\nSYNOPSIS\n     mount device mountpoint\n\nDESCRIPTION\n    Mount a guest disk at a position in the filesystem. Block devices are\n    named \"/dev/sda\", \"/dev/sdb\" and so on, as they were added to the guest.\n    If those block devices contain partitions, they will have the usual\n    names (eg. \"/dev/sda1\"). Also LVM \"/dev/VG/LV\"-style names can be used.\n\n    The rules are the same as for mount(2): A filesystem must first be\n    mounted on \"/\" before others can be mounted. Other filesystems can only\n    be mounted on directories which already exist.\n\n    The mounted filesystem is writable, if we have sufficient permissions on\n    the underlying device.\n\n    Before libguestfs 1.13.16, this call implicitly added the options \"sync\"\n    and \"noatime\". The \"sync\" option greatly slowed writes and caused many\n    problems for users. If your program might need to work with older\n    versions of libguestfs, use \"mount_options\" instead (using an empty\n    string for the first parameter if you don't want any options).\n\n",
  .run = run_mount
};

struct command_entry sync_cmd_entry = {
  .name = "sync",
  .help = "NAME\n    sync - sync disks, writes are flushed through to the disk image\n\nSYNOPSIS\n     sync\n\nDESCRIPTION\n    This syncs the disk, so that any writes are flushed through to the\n    underlying disk image.\n\n    You should always call this if you have modified a disk image, before\n    closing the handle.\n\n",
  .run = run_sync
};

struct command_entry touch_cmd_entry = {
  .name = "touch",
  .help = "NAME\n    touch - update file timestamps or create a new file\n\nSYNOPSIS\n     touch path\n\nDESCRIPTION\n    Touch acts like the touch(1) command. It can be used to update the\n    timestamps on a file, or, if the file does not exist, to create a new\n    zero-length file.\n\n    This command only works on regular files, and will fail on other file\n    types such as directories, symbolic links, block special etc.\n\n",
  .run = run_touch
};

struct command_entry cat_cmd_entry = {
  .name = "cat",
  .help = "NAME\n    cat - list the contents of a file\n\nSYNOPSIS\n     cat path\n\nDESCRIPTION\n    Return the contents of the file named \"path\".\n\n    Note that this function cannot correctly handle binary files\n    (specifically, files containing \"\\0\" character which is treated as end\n    of string). For those you need to use the \"read_file\" or \"download\"\n    functions which have a more complex interface.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_cat
};

struct command_entry ll_cmd_entry = {
  .name = "ll",
  .help = "NAME\n    ll - list the files in a directory (long format)\n\nSYNOPSIS\n     ll directory\n\nDESCRIPTION\n    List the files in \"directory\" (relative to the root directory, there is\n    no cwd) in the format of 'ls -la'.\n\n    This command is mostly useful for interactive sessions. It is *not*\n    intended that you try to parse the output string.\n\n",
  .run = run_ll
};

struct command_entry ls_cmd_entry = {
  .name = "ls",
  .help = "NAME\n    ls - list the files in a directory\n\nSYNOPSIS\n     ls directory\n\nDESCRIPTION\n    List the files in \"directory\" (relative to the root directory, there is\n    no cwd). The '.' and '..' entries are not returned, but hidden files are\n    shown.\n\n    This command is mostly useful for interactive sessions. Programs should\n    probably use \"readdir\" instead.\n\n",
  .run = run_ls
};

struct command_entry list_devices_cmd_entry = {
  .name = "list-devices",
  .help = "NAME\n    list-devices - list the block devices\n\nSYNOPSIS\n     list-devices\n\nDESCRIPTION\n    List all the block devices.\n\n    The full block device names are returned, eg. \"/dev/sda\".\n\n    See also \"list_filesystems\".\n\n",
  .run = run_list_devices
};

struct command_entry list_partitions_cmd_entry = {
  .name = "list-partitions",
  .help = "NAME\n    list-partitions - list the partitions\n\nSYNOPSIS\n     list-partitions\n\nDESCRIPTION\n    List all the partitions detected on all block devices.\n\n    The full partition device names are returned, eg. \"/dev/sda1\"\n\n    This does not return logical volumes. For that you will need to call\n    \"lvs\".\n\n    See also \"list_filesystems\".\n\n",
  .run = run_list_partitions
};

struct command_entry pvs_cmd_entry = {
  .name = "pvs",
  .help = "NAME\n    pvs - list the LVM physical volumes (PVs)\n\nSYNOPSIS\n     pvs\n\nDESCRIPTION\n    List all the physical volumes detected. This is the equivalent of the\n    pvs(8) command.\n\n    This returns a list of just the device names that contain PVs (eg.\n    \"/dev/sda2\").\n\n    See also \"pvs_full\".\n\n",
  .run = run_pvs
};

struct command_entry vgs_cmd_entry = {
  .name = "vgs",
  .help = "NAME\n    vgs - list the LVM volume groups (VGs)\n\nSYNOPSIS\n     vgs\n\nDESCRIPTION\n    List all the volumes groups detected. This is the equivalent of the\n    vgs(8) command.\n\n    This returns a list of just the volume group names that were detected\n    (eg. \"VolGroup00\").\n\n    See also \"vgs_full\".\n\n",
  .run = run_vgs
};

struct command_entry lvs_cmd_entry = {
  .name = "lvs",
  .help = "NAME\n    lvs - list the LVM logical volumes (LVs)\n\nSYNOPSIS\n     lvs\n\nDESCRIPTION\n    List all the logical volumes detected. This is the equivalent of the\n    lvs(8) command.\n\n    This returns a list of the logical volume device names (eg.\n    \"/dev/VolGroup00/LogVol00\").\n\n    See also \"lvs_full\", \"list_filesystems\".\n\n",
  .run = run_lvs
};

struct command_entry pvs_full_cmd_entry = {
  .name = "pvs-full",
  .help = "NAME\n    pvs-full - list the LVM physical volumes (PVs)\n\nSYNOPSIS\n     pvs-full\n\nDESCRIPTION\n    List all the physical volumes detected. This is the equivalent of the\n    pvs(8) command. The \"full\" version includes all fields.\n\n",
  .run = run_pvs_full
};

struct command_entry vgs_full_cmd_entry = {
  .name = "vgs-full",
  .help = "NAME\n    vgs-full - list the LVM volume groups (VGs)\n\nSYNOPSIS\n     vgs-full\n\nDESCRIPTION\n    List all the volumes groups detected. This is the equivalent of the\n    vgs(8) command. The \"full\" version includes all fields.\n\n",
  .run = run_vgs_full
};

struct command_entry lvs_full_cmd_entry = {
  .name = "lvs-full",
  .help = "NAME\n    lvs-full - list the LVM logical volumes (LVs)\n\nSYNOPSIS\n     lvs-full\n\nDESCRIPTION\n    List all the logical volumes detected. This is the equivalent of the\n    lvs(8) command. The \"full\" version includes all fields.\n\n",
  .run = run_lvs_full
};

struct command_entry read_lines_cmd_entry = {
  .name = "read-lines",
  .help = "NAME\n    read-lines - read file as lines\n\nSYNOPSIS\n     read-lines path\n\nDESCRIPTION\n    Return the contents of the file named \"path\".\n\n    The file contents are returned as a list of lines. Trailing \"LF\" and\n    \"CRLF\" character sequences are *not* returned.\n\n    Note that this function cannot correctly handle binary files\n    (specifically, files containing \"\\0\" character which is treated as end\n    of line). For those you need to use the \"read_file\" function which has a\n    more complex interface.\n\n",
  .run = run_read_lines
};

struct command_entry aug_init_cmd_entry = {
  .name = "aug-init",
  .help = "NAME\n    aug-init - create a new Augeas handle\n\nSYNOPSIS\n     aug-init root flags\n\nDESCRIPTION\n    Create a new Augeas handle for editing configuration files. If there was\n    any previous Augeas handle associated with this guestfs session, then it\n    is closed.\n\n    You must call this before using any other \"aug_*\" commands.\n\n    \"root\" is the filesystem root. \"root\" must not be NULL, use \"/\" instead.\n\n    The flags are the same as the flags defined in <augeas.h>, the logical\n    *or* of the following integers:\n\n    \"AUG_SAVE_BACKUP\" = 1\n        Keep the original file with a \".augsave\" extension.\n\n    \"AUG_SAVE_NEWFILE\" = 2\n        Save changes into a file with extension \".augnew\", and do not\n        overwrite original. Overrides \"AUG_SAVE_BACKUP\".\n\n    \"AUG_TYPE_CHECK\" = 4\n        Typecheck lenses.\n\n        This option is only useful when debugging Augeas lenses. Use of this\n        option may require additional memory for the libguestfs appliance.\n        You may need to set the \"LIBGUESTFS_MEMSIZE\" environment variable or\n        call \"set_memsize\".\n\n    \"AUG_NO_STDINC\" = 8\n        Do not use standard load path for modules.\n\n    \"AUG_SAVE_NOOP\" = 16\n        Make save a no-op, just record what would have been changed.\n\n    \"AUG_NO_LOAD\" = 32\n        Do not load the tree in \"aug_init\".\n\n    To close the handle, you can call \"aug_close\".\n\n    To find out more about Augeas, see <http://augeas.net/>.\n\n",
  .run = run_aug_init
};

struct command_entry aug_close_cmd_entry = {
  .name = "aug-close",
  .help = "NAME\n    aug-close - close the current Augeas handle\n\nSYNOPSIS\n     aug-close\n\nDESCRIPTION\n    Close the current Augeas handle and free up any resources used by it.\n    After calling this, you have to call \"aug_init\" again before you can use\n    any other Augeas functions.\n\n",
  .run = run_aug_close
};

struct command_entry aug_defvar_cmd_entry = {
  .name = "aug-defvar",
  .help = "NAME\n    aug-defvar - define an Augeas variable\n\nSYNOPSIS\n     aug-defvar name expr\n\nDESCRIPTION\n    Defines an Augeas variable \"name\" whose value is the result of\n    evaluating \"expr\". If \"expr\" is NULL, then \"name\" is undefined.\n\n    On success this returns the number of nodes in \"expr\", or 0 if \"expr\"\n    evaluates to something which is not a nodeset.\n\n",
  .run = run_aug_defvar
};

struct command_entry aug_defnode_cmd_entry = {
  .name = "aug-defnode",
  .help = "NAME\n    aug-defnode - define an Augeas node\n\nSYNOPSIS\n     aug-defnode name expr val\n\nDESCRIPTION\n    Defines a variable \"name\" whose value is the result of evaluating\n    \"expr\".\n\n    If \"expr\" evaluates to an empty nodeset, a node is created, equivalent\n    to calling \"aug_set\" \"expr\", \"value\". \"name\" will be the nodeset\n    containing that single node.\n\n    On success this returns a pair containing the number of nodes in the\n    nodeset, and a boolean flag if a node was created.\n\n",
  .run = run_aug_defnode
};

struct command_entry aug_get_cmd_entry = {
  .name = "aug-get",
  .help = "NAME\n    aug-get - look up the value of an Augeas path\n\nSYNOPSIS\n     aug-get augpath\n\nDESCRIPTION\n    Look up the value associated with \"path\". If \"path\" matches exactly one\n    node, the \"value\" is returned.\n\n",
  .run = run_aug_get
};

struct command_entry aug_set_cmd_entry = {
  .name = "aug-set",
  .help = "NAME\n    aug-set - set Augeas path to value\n\nSYNOPSIS\n     aug-set augpath val\n\nDESCRIPTION\n    Set the value associated with \"path\" to \"val\".\n\n    In the Augeas API, it is possible to clear a node by setting the value\n    to NULL. Due to an oversight in the libguestfs API you cannot do that\n    with this call. Instead you must use the \"aug_clear\" call.\n\n",
  .run = run_aug_set
};

struct command_entry aug_insert_cmd_entry = {
  .name = "aug-insert",
  .help = "NAME\n    aug-insert - insert a sibling Augeas node\n\nSYNOPSIS\n     aug-insert augpath label before\n\nDESCRIPTION\n    Create a new sibling \"label\" for \"path\", inserting it into the tree\n    before or after \"path\" (depending on the boolean flag \"before\").\n\n    \"path\" must match exactly one existing node in the tree, and \"label\"\n    must be a label, ie. not contain \"/\", \"*\" or end with a bracketed index\n    \"[N]\".\n\n",
  .run = run_aug_insert
};

struct command_entry aug_rm_cmd_entry = {
  .name = "aug-rm",
  .help = "NAME\n    aug-rm - remove an Augeas path\n\nSYNOPSIS\n     aug-rm augpath\n\nDESCRIPTION\n    Remove \"path\" and all of its children.\n\n    On success this returns the number of entries which were removed.\n\n",
  .run = run_aug_rm
};

struct command_entry aug_mv_cmd_entry = {
  .name = "aug-mv",
  .help = "NAME\n    aug-mv - move Augeas node\n\nSYNOPSIS\n     aug-mv src dest\n\nDESCRIPTION\n    Move the node \"src\" to \"dest\". \"src\" must match exactly one node. \"dest\"\n    is overwritten if it exists.\n\n",
  .run = run_aug_mv
};

struct command_entry aug_match_cmd_entry = {
  .name = "aug-match",
  .help = "NAME\n    aug-match - return Augeas nodes which match augpath\n\nSYNOPSIS\n     aug-match augpath\n\nDESCRIPTION\n    Returns a list of paths which match the path expression \"path\". The\n    returned paths are sufficiently qualified so that they match exactly one\n    node in the current tree.\n\n",
  .run = run_aug_match
};

struct command_entry aug_save_cmd_entry = {
  .name = "aug-save",
  .help = "NAME\n    aug-save - write all pending Augeas changes to disk\n\nSYNOPSIS\n     aug-save\n\nDESCRIPTION\n    This writes all pending changes to disk.\n\n    The flags which were passed to \"aug_init\" affect exactly how files are\n    saved.\n\n",
  .run = run_aug_save
};

struct command_entry aug_load_cmd_entry = {
  .name = "aug-load",
  .help = "NAME\n    aug-load - load files into the tree\n\nSYNOPSIS\n     aug-load\n\nDESCRIPTION\n    Load files into the tree.\n\n    See \"aug_load\" in the Augeas documentation for the full gory details.\n\n",
  .run = run_aug_load
};

struct command_entry aug_ls_cmd_entry = {
  .name = "aug-ls",
  .help = "NAME\n    aug-ls - list Augeas nodes under augpath\n\nSYNOPSIS\n     aug-ls augpath\n\nDESCRIPTION\n    This is just a shortcut for listing \"aug_match\" \"path/*\" and sorting the\n    resulting nodes into alphabetical order.\n\n",
  .run = run_aug_ls
};

struct command_entry rm_cmd_entry = {
  .name = "rm",
  .help = "NAME\n    rm - remove a file\n\nSYNOPSIS\n     rm path\n\nDESCRIPTION\n    Remove the single file \"path\".\n\n",
  .run = run_rm
};

struct command_entry rmdir_cmd_entry = {
  .name = "rmdir",
  .help = "NAME\n    rmdir - remove a directory\n\nSYNOPSIS\n     rmdir path\n\nDESCRIPTION\n    Remove the single directory \"path\".\n\n",
  .run = run_rmdir
};

struct command_entry rm_rf_cmd_entry = {
  .name = "rm-rf",
  .help = "NAME\n    rm-rf - remove a file or directory recursively\n\nSYNOPSIS\n     rm-rf path\n\nDESCRIPTION\n    Remove the file or directory \"path\", recursively removing the contents\n    if its a directory. This is like the \"rm -rf\" shell command.\n\n",
  .run = run_rm_rf
};

struct command_entry mkdir_cmd_entry = {
  .name = "mkdir",
  .help = "NAME\n    mkdir - create a directory\n\nSYNOPSIS\n     mkdir path\n\nDESCRIPTION\n    Create a directory named \"path\".\n\n",
  .run = run_mkdir
};

struct command_entry mkdir_p_cmd_entry = {
  .name = "mkdir-p",
  .help = "NAME\n    mkdir-p - create a directory and parents\n\nSYNOPSIS\n     mkdir-p path\n\nDESCRIPTION\n    Create a directory named \"path\", creating any parent directories as\n    necessary. This is like the \"mkdir -p\" shell command.\n\n",
  .run = run_mkdir_p
};

struct command_entry chmod_cmd_entry = {
  .name = "chmod",
  .help = "NAME\n    chmod - change file mode\n\nSYNOPSIS\n     chmod mode path\n\nDESCRIPTION\n    Change the mode (permissions) of \"path\" to \"mode\". Only numeric modes\n    are supported.\n\n    *Note*: When using this command from guestfish, \"mode\" by default would\n    be decimal, unless you prefix it with 0 to get octal, ie. use 0700 not\n    700.\n\n    The mode actually set is affected by the umask.\n\n",
  .run = run_chmod
};

struct command_entry chown_cmd_entry = {
  .name = "chown",
  .help = "NAME\n    chown - change file owner and group\n\nSYNOPSIS\n     chown owner group path\n\nDESCRIPTION\n    Change the file owner to \"owner\" and group to \"group\".\n\n    Only numeric uid and gid are supported. If you want to use names, you\n    will need to locate and parse the password file yourself (Augeas support\n    makes this relatively easy).\n\n",
  .run = run_chown
};

struct command_entry exists_cmd_entry = {
  .name = "exists",
  .help = "NAME\n    exists - test if file or directory exists\n\nSYNOPSIS\n     exists path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a file, directory (or\n    anything) with the given \"path\" name.\n\n    See also \"is_file\", \"is_dir\", \"stat\".\n\n",
  .run = run_exists
};

struct command_entry is_file_cmd_entry = {
  .name = "is-file",
  .help = "NAME\n    is-file - test if a regular file\n\nSYNOPSIS\n     is-file path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a regular file with the\n    given \"path\" name. Note that it returns false for other objects like\n    directories.\n\n    See also \"stat\".\n\n",
  .run = run_is_file
};

struct command_entry is_dir_cmd_entry = {
  .name = "is-dir",
  .help = "NAME\n    is-dir - test if a directory\n\nSYNOPSIS\n     is-dir path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a directory with the given\n    \"path\" name. Note that it returns false for other objects like files.\n\n    See also \"stat\".\n\n",
  .run = run_is_dir
};

struct command_entry pvcreate_cmd_entry = {
  .name = "pvcreate",
  .help = "NAME\n    pvcreate - create an LVM physical volume\n\nSYNOPSIS\n     pvcreate device\n\nDESCRIPTION\n    This creates an LVM physical volume on the named \"device\", where\n    \"device\" should usually be a partition name such as \"/dev/sda1\".\n\n",
  .run = run_pvcreate
};

struct command_entry vgcreate_cmd_entry = {
  .name = "vgcreate",
  .help = "NAME\n    vgcreate - create an LVM volume group\n\nSYNOPSIS\n     vgcreate volgroup physvols\n\nDESCRIPTION\n    This creates an LVM volume group called \"volgroup\" from the non-empty\n    list of physical volumes \"physvols\".\n\n",
  .run = run_vgcreate
};

struct command_entry lvcreate_cmd_entry = {
  .name = "lvcreate",
  .help = "NAME\n    lvcreate - create an LVM logical volume\n\nSYNOPSIS\n     lvcreate logvol volgroup mbytes\n\nDESCRIPTION\n    This creates an LVM logical volume called \"logvol\" on the volume group\n    \"volgroup\", with \"size\" megabytes.\n\n",
  .run = run_lvcreate
};

struct command_entry mkfs_cmd_entry = {
  .name = "mkfs",
  .help = "NAME\n    mkfs - make a filesystem\n\nSYNOPSIS\n     mkfs fstype device\n\nDESCRIPTION\n    This creates a filesystem on \"device\" (usually a partition or LVM\n    logical volume). The filesystem type is \"fstype\", for example \"ext3\".\n\n",
  .run = run_mkfs
};

struct command_entry sfdisk_cmd_entry = {
  .name = "sfdisk",
  .help = "NAME\n    sfdisk - create partitions on a block device\n\nSYNOPSIS\n     sfdisk device cyls heads sectors lines\n\nDESCRIPTION\n    This is a direct interface to the sfdisk(8) program for creating\n    partitions on block devices.\n\n    \"device\" should be a block device, for example \"/dev/sda\".\n\n    \"cyls\", \"heads\" and \"sectors\" are the number of cylinders, heads and\n    sectors on the device, which are passed directly to sfdisk as the *-C*,\n    *-H* and *-S* parameters. If you pass 0 for any of these, then the\n    corresponding parameter is omitted. Usually for 'large' disks, you can\n    just pass 0 for these, but for small (floppy-sized) disks, sfdisk (or\n    rather, the kernel) cannot work out the right geometry and you will need\n    to tell it.\n\n    \"lines\" is a list of lines that we feed to \"sfdisk\". For more\n    information refer to the sfdisk(8) manpage.\n\n    To create a single partition occupying the whole disk, you would pass\n    \"lines\" as a single element list, when the single element being the\n    string \",\" (comma).\n\n    See also: \"sfdisk_l\", \"sfdisk_N\", \"part_init\"\n\n    *This function is deprecated.* In new code, use the \"part_add\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_sfdisk
};

struct command_entry write_file_cmd_entry = {
  .name = "write-file",
  .help = "NAME\n    write-file - create a file\n\nSYNOPSIS\n     write-file path content size\n\nDESCRIPTION\n    This call creates a file called \"path\". The contents of the file is the\n    string \"content\" (which can contain any 8 bit data), with length \"size\".\n\n    As a special case, if \"size\" is 0 then the length is calculated using\n    \"strlen\" (so in this case the content cannot contain embedded ASCII\n    NULs).\n\n    *NB.* Owing to a bug, writing content containing ASCII NUL characters\n    does *not* work, even if the length is specified.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n    *This function is deprecated.* In new code, use the \"write\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_write_file
};

struct command_entry umount_cmd_entry = {
  .name = "umount",
  .help = "NAME\n    umount - unmount a filesystem\n\nSYNOPSIS\n     umount pathordevice\n\nDESCRIPTION\n    This unmounts the given filesystem. The filesystem may be specified\n    either by its mountpoint (path) or the device which contains the\n    filesystem.\n\n    You can use 'unmount' as an alias for this command.\n\n",
  .run = run_umount
};

struct command_entry mounts_cmd_entry = {
  .name = "mounts",
  .help = "NAME\n    mounts - show mounted filesystems\n\nSYNOPSIS\n     mounts\n\nDESCRIPTION\n    This returns the list of currently mounted filesystems. It returns the\n    list of devices (eg. \"/dev/sda1\", \"/dev/VG/LV\").\n\n    Some internal mounts are not shown.\n\n    See also: \"mountpoints\"\n\n",
  .run = run_mounts
};

struct command_entry umount_all_cmd_entry = {
  .name = "umount-all",
  .help = "NAME\n    umount-all - unmount all filesystems\n\nSYNOPSIS\n     umount-all\n\nDESCRIPTION\n    This unmounts all mounted filesystems.\n\n    Some internal mounts are not unmounted by this call.\n\n    You can use 'unmount-all' as an alias for this command.\n\n",
  .run = run_umount_all
};

struct command_entry lvm_remove_all_cmd_entry = {
  .name = "lvm-remove-all",
  .help = "NAME\n    lvm-remove-all - remove all LVM LVs, VGs and PVs\n\nSYNOPSIS\n     lvm-remove-all\n\nDESCRIPTION\n    This command removes all LVM logical volumes, volume groups and physical\n    volumes.\n\n",
  .run = run_lvm_remove_all
};

struct command_entry file_cmd_entry = {
  .name = "file",
  .help = "NAME\n    file - determine file type\n\nSYNOPSIS\n     file path\n\nDESCRIPTION\n    This call uses the standard file(1) command to determine the type or\n    contents of the file.\n\n    This call will also transparently look inside various types of\n    compressed file.\n\n    The exact command which runs is \"file -zb path\". Note in particular that\n    the filename is not prepended to the output (the *-b* option).\n\n    The output depends on the output of the underlying file(1) command and\n    it can change in future in ways beyond our control. In other words, the\n    output is not guaranteed by the ABI.\n\n    See also: file(1), \"vfs_type\", \"lstat\", \"is_file\", \"is_blockdev\" (etc),\n    \"is_zero\".\n\n",
  .run = run_file
};

struct command_entry command_cmd_entry = {
  .name = "command",
  .help = "NAME\n    command - run a command from the guest filesystem\n\nSYNOPSIS\n     command arguments\n\nDESCRIPTION\n    This call runs a command from the guest filesystem. The filesystem must\n    be mounted, and must contain a compatible operating system (ie.\n    something Linux, with the same or compatible processor architecture).\n\n    The single parameter is an argv-style list of arguments. The first\n    element is the name of the program to run. Subsequent elements are\n    parameters. The list must be non-empty (ie. must contain a program\n    name). Note that the command runs directly, and is *not* invoked via the\n    shell (see \"sh\").\n\n    The return value is anything printed to *stdout* by the command.\n\n    If the command returns a non-zero exit status, then this function\n    returns an error message. The error message string is the content of\n    *stderr* from the command.\n\n    The $PATH environment variable will contain at least \"/usr/bin\" and\n    \"/bin\". If you require a program from another location, you should\n    provide the full path in the first parameter.\n\n    Shared libraries and data files required by the program must be\n    available on filesystems which are mounted in the correct places. It is\n    the caller's responsibility to ensure all filesystems that are needed\n    are mounted at the right locations.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_command
};

struct command_entry command_lines_cmd_entry = {
  .name = "command-lines",
  .help = "NAME\n    command-lines - run a command, returning lines\n\nSYNOPSIS\n     command-lines arguments\n\nDESCRIPTION\n    This is the same as \"command\", but splits the result into a list of\n    lines.\n\n    See also: \"sh_lines\"\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_command_lines
};

struct command_entry stat_cmd_entry = {
  .name = "stat",
  .help = "NAME\n    stat - get file information\n\nSYNOPSIS\n     stat path\n\nDESCRIPTION\n    Returns file information for the given \"path\".\n\n    This is the same as the stat(2) system call.\n\n",
  .run = run_stat
};

struct command_entry lstat_cmd_entry = {
  .name = "lstat",
  .help = "NAME\n    lstat - get file information for a symbolic link\n\nSYNOPSIS\n     lstat path\n\nDESCRIPTION\n    Returns file information for the given \"path\".\n\n    This is the same as \"stat\" except that if \"path\" is a symbolic link,\n    then the link is stat-ed, not the file it refers to.\n\n    This is the same as the lstat(2) system call.\n\n",
  .run = run_lstat
};

struct command_entry statvfs_cmd_entry = {
  .name = "statvfs",
  .help = "NAME\n    statvfs - get file system statistics\n\nSYNOPSIS\n     statvfs path\n\nDESCRIPTION\n    Returns file system statistics for any mounted file system. \"path\"\n    should be a file or directory in the mounted file system (typically it\n    is the mount point itself, but it doesn't need to be).\n\n    This is the same as the statvfs(2) system call.\n\n",
  .run = run_statvfs
};

struct command_entry tune2fs_l_cmd_entry = {
  .name = "tune2fs-l",
  .help = "NAME\n    tune2fs-l - get ext2/ext3/ext4 superblock details\n\nSYNOPSIS\n     tune2fs-l device\n\nDESCRIPTION\n    This returns the contents of the ext2, ext3 or ext4 filesystem\n    superblock on \"device\".\n\n    It is the same as running \"tune2fs -l device\". See tune2fs(8) manpage\n    for more details. The list of fields returned isn't clearly defined, and\n    depends on both the version of \"tune2fs\" that libguestfs was built\n    against, and the filesystem itself.\n\n",
  .run = run_tune2fs_l
};

struct command_entry blockdev_setro_cmd_entry = {
  .name = "blockdev-setro",
  .help = "NAME\n    blockdev-setro - set block device to read-only\n\nSYNOPSIS\n     blockdev-setro device\n\nDESCRIPTION\n    Sets the block device named \"device\" to read-only.\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_setro
};

struct command_entry blockdev_setrw_cmd_entry = {
  .name = "blockdev-setrw",
  .help = "NAME\n    blockdev-setrw - set block device to read-write\n\nSYNOPSIS\n     blockdev-setrw device\n\nDESCRIPTION\n    Sets the block device named \"device\" to read-write.\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_setrw
};

struct command_entry blockdev_getro_cmd_entry = {
  .name = "blockdev-getro",
  .help = "NAME\n    blockdev-getro - is block device set to read-only\n\nSYNOPSIS\n     blockdev-getro device\n\nDESCRIPTION\n    Returns a boolean indicating if the block device is read-only (true if\n    read-only, false if not).\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_getro
};

struct command_entry blockdev_getss_cmd_entry = {
  .name = "blockdev-getss",
  .help = "NAME\n    blockdev-getss - get sectorsize of block device\n\nSYNOPSIS\n     blockdev-getss device\n\nDESCRIPTION\n    This returns the size of sectors on a block device. Usually 512, but can\n    be larger for modern devices.\n\n    (Note, this is not the size in sectors, use \"blockdev_getsz\" for that).\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_getss
};

struct command_entry blockdev_getbsz_cmd_entry = {
  .name = "blockdev-getbsz",
  .help = "NAME\n    blockdev-getbsz - get blocksize of block device\n\nSYNOPSIS\n     blockdev-getbsz device\n\nDESCRIPTION\n    This returns the block size of a device.\n\n    (Note this is different from both *size in blocks* and *filesystem block\n    size*).\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_getbsz
};

struct command_entry blockdev_setbsz_cmd_entry = {
  .name = "blockdev-setbsz",
  .help = "NAME\n    blockdev-setbsz - set blocksize of block device\n\nSYNOPSIS\n     blockdev-setbsz device blocksize\n\nDESCRIPTION\n    This sets the block size of a device.\n\n    (Note this is different from both *size in blocks* and *filesystem block\n    size*).\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_setbsz
};

struct command_entry blockdev_getsz_cmd_entry = {
  .name = "blockdev-getsz",
  .help = "NAME\n    blockdev-getsz - get total size of device in 512-byte sectors\n\nSYNOPSIS\n     blockdev-getsz device\n\nDESCRIPTION\n    This returns the size of the device in units of 512-byte sectors (even\n    if the sectorsize isn't 512 bytes ... weird).\n\n    See also \"blockdev_getss\" for the real sector size of the device, and\n    \"blockdev_getsize64\" for the more useful *size in bytes*.\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_getsz
};

struct command_entry blockdev_getsize64_cmd_entry = {
  .name = "blockdev-getsize64",
  .help = "NAME\n    blockdev-getsize64 - get total size of device in bytes\n\nSYNOPSIS\n     blockdev-getsize64 device\n\nDESCRIPTION\n    This returns the size of the device in bytes.\n\n    See also \"blockdev_getsz\".\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_getsize64
};

struct command_entry blockdev_flushbufs_cmd_entry = {
  .name = "blockdev-flushbufs",
  .help = "NAME\n    blockdev-flushbufs - flush device buffers\n\nSYNOPSIS\n     blockdev-flushbufs device\n\nDESCRIPTION\n    This tells the kernel to flush internal buffers associated with\n    \"device\".\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_flushbufs
};

struct command_entry blockdev_rereadpt_cmd_entry = {
  .name = "blockdev-rereadpt",
  .help = "NAME\n    blockdev-rereadpt - reread partition table\n\nSYNOPSIS\n     blockdev-rereadpt device\n\nDESCRIPTION\n    Reread the partition table on \"device\".\n\n    This uses the blockdev(8) command.\n\n",
  .run = run_blockdev_rereadpt
};

struct command_entry upload_cmd_entry = {
  .name = "upload",
  .help = "NAME\n    upload - upload a file from the local machine\n\nSYNOPSIS\n     upload filename remotefilename\n\nDESCRIPTION\n    Upload local file \"filename\" to \"remotefilename\" on the filesystem.\n\n    \"filename\" can also be a named pipe.\n\n    See also \"download\".\n\n",
  .run = run_upload
};

struct command_entry download_cmd_entry = {
  .name = "download",
  .help = "NAME\n    download - download a file to the local machine\n\nSYNOPSIS\n     download remotefilename filename\n\nDESCRIPTION\n    Download file \"remotefilename\" and save it as \"filename\" on the local\n    machine.\n\n    \"filename\" can also be a named pipe.\n\n    See also \"upload\", \"cat\".\n\n",
  .run = run_download
};

struct command_entry checksum_cmd_entry = {
  .name = "checksum",
  .help = "NAME\n    checksum - compute MD5, SHAx or CRC checksum of file\n\nSYNOPSIS\n     checksum csumtype path\n\nDESCRIPTION\n    This call computes the MD5, SHAx or CRC checksum of the file named\n    \"path\".\n\n    The type of checksum to compute is given by the \"csumtype\" parameter\n    which must have one of the following values:\n\n    \"crc\"\n        Compute the cyclic redundancy check (CRC) specified by POSIX for the\n        \"cksum\" command.\n\n    \"md5\"\n        Compute the MD5 hash (using the \"md5sum\" program).\n\n    \"sha1\"\n        Compute the SHA1 hash (using the \"sha1sum\" program).\n\n    \"sha224\"\n        Compute the SHA224 hash (using the \"sha224sum\" program).\n\n    \"sha256\"\n        Compute the SHA256 hash (using the \"sha256sum\" program).\n\n    \"sha384\"\n        Compute the SHA384 hash (using the \"sha384sum\" program).\n\n    \"sha512\"\n        Compute the SHA512 hash (using the \"sha512sum\" program).\n\n    The checksum is returned as a printable string.\n\n    To get the checksum for a device, use \"checksum_device\".\n\n    To get the checksums for many files, use \"checksums_out\".\n\n",
  .run = run_checksum
};

struct command_entry tar_in_cmd_entry = {
  .name = "tar-in",
  .help = "NAME\n    tar-in - unpack tarfile to directory\n\nSYNOPSIS\n     tar-in tarfile directory\n\nDESCRIPTION\n    This command uploads and unpacks local file \"tarfile\" (an *uncompressed*\n    tar file) into \"directory\".\n\n    To upload a compressed tarball, use \"tgz_in\" or \"txz_in\".\n\n",
  .run = run_tar_in
};

struct command_entry tar_out_cmd_entry = {
  .name = "tar-out",
  .help = "NAME\n    tar-out - pack directory into tarfile\n\nSYNOPSIS\n     tar-out directory tarfile\n\nDESCRIPTION\n    This command packs the contents of \"directory\" and downloads it to local\n    file \"tarfile\".\n\n    To download a compressed tarball, use \"tgz_out\" or \"txz_out\".\n\n",
  .run = run_tar_out
};

struct command_entry tgz_in_cmd_entry = {
  .name = "tgz-in",
  .help = "NAME\n    tgz-in - unpack compressed tarball to directory\n\nSYNOPSIS\n     tgz-in tarball directory\n\nDESCRIPTION\n    This command uploads and unpacks local file \"tarball\" (a *gzip\n    compressed* tar file) into \"directory\".\n\n    To upload an uncompressed tarball, use \"tar_in\".\n\n",
  .run = run_tgz_in
};

struct command_entry tgz_out_cmd_entry = {
  .name = "tgz-out",
  .help = "NAME\n    tgz-out - pack directory into compressed tarball\n\nSYNOPSIS\n     tgz-out directory tarball\n\nDESCRIPTION\n    This command packs the contents of \"directory\" and downloads it to local\n    file \"tarball\".\n\n    To download an uncompressed tarball, use \"tar_out\".\n\n",
  .run = run_tgz_out
};

struct command_entry mount_ro_cmd_entry = {
  .name = "mount-ro",
  .help = "NAME\n    mount-ro - mount a guest disk, read-only\n\nSYNOPSIS\n     mount-ro device mountpoint\n\nDESCRIPTION\n    This is the same as the \"mount\" command, but it mounts the filesystem\n    with the read-only (*-o ro*) flag.\n\n",
  .run = run_mount_ro
};

struct command_entry mount_options_cmd_entry = {
  .name = "mount-options",
  .help = "NAME\n    mount-options - mount a guest disk with mount options\n\nSYNOPSIS\n     mount-options options device mountpoint\n\nDESCRIPTION\n    This is the same as the \"mount\" command, but it allows you to set the\n    mount options as for the mount(8) *-o* flag.\n\n    If the \"options\" parameter is an empty string, then no options are\n    passed (all options default to whatever the filesystem uses).\n\n",
  .run = run_mount_options
};

struct command_entry mount_vfs_cmd_entry = {
  .name = "mount-vfs",
  .help = "NAME\n    mount-vfs - mount a guest disk with mount options and vfstype\n\nSYNOPSIS\n     mount-vfs options vfstype device mountpoint\n\nDESCRIPTION\n    This is the same as the \"mount\" command, but it allows you to set both\n    the mount options and the vfstype as for the mount(8) *-o* and *-t*\n    flags.\n\n",
  .run = run_mount_vfs
};

struct command_entry debug_cmd_entry = {
  .name = "debug",
  .help = "NAME\n    debug - debugging and internals\n\nSYNOPSIS\n     debug subcmd extraargs\n\nDESCRIPTION\n    The \"debug\" command exposes some internals of \"guestfsd\" (the guestfs\n    daemon) that runs inside the qemu subprocess.\n\n    There is no comprehensive help for this command. You have to look at the\n    file \"daemon/debug.c\" in the libguestfs source to find out what you can\n    do.\n\n",
  .run = run_debug
};

struct command_entry lvremove_cmd_entry = {
  .name = "lvremove",
  .help = "NAME\n    lvremove - remove an LVM logical volume\n\nSYNOPSIS\n     lvremove device\n\nDESCRIPTION\n    Remove an LVM logical volume \"device\", where \"device\" is the path to the\n    LV, such as \"/dev/VG/LV\".\n\n    You can also remove all LVs in a volume group by specifying the VG name,\n    \"/dev/VG\".\n\n",
  .run = run_lvremove
};

struct command_entry vgremove_cmd_entry = {
  .name = "vgremove",
  .help = "NAME\n    vgremove - remove an LVM volume group\n\nSYNOPSIS\n     vgremove vgname\n\nDESCRIPTION\n    Remove an LVM volume group \"vgname\", (for example \"VG\").\n\n    This also forcibly removes all logical volumes in the volume group (if\n    any).\n\n",
  .run = run_vgremove
};

struct command_entry pvremove_cmd_entry = {
  .name = "pvremove",
  .help = "NAME\n    pvremove - remove an LVM physical volume\n\nSYNOPSIS\n     pvremove device\n\nDESCRIPTION\n    This wipes a physical volume \"device\" so that LVM will no longer\n    recognise it.\n\n    The implementation uses the \"pvremove\" command which refuses to wipe\n    physical volumes that contain any volume groups, so you have to remove\n    those first.\n\n",
  .run = run_pvremove
};

struct command_entry set_e2label_cmd_entry = {
  .name = "set-e2label",
  .help = "NAME\n    set-e2label - set the ext2/3/4 filesystem label\n\nSYNOPSIS\n     set-e2label device label\n\nDESCRIPTION\n    This sets the ext2/3/4 filesystem label of the filesystem on \"device\" to\n    \"label\". Filesystem labels are limited to 16 characters.\n\n    You can use either \"tune2fs_l\" or \"get_e2label\" to return the existing\n    label on a filesystem.\n\n",
  .run = run_set_e2label
};

struct command_entry get_e2label_cmd_entry = {
  .name = "get-e2label",
  .help = "NAME\n    get-e2label - get the ext2/3/4 filesystem label\n\nSYNOPSIS\n     get-e2label device\n\nDESCRIPTION\n    This returns the ext2/3/4 filesystem label of the filesystem on\n    \"device\".\n\n    *This function is deprecated.* In new code, use the \"vfs_label\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_get_e2label
};

struct command_entry set_e2uuid_cmd_entry = {
  .name = "set-e2uuid",
  .help = "NAME\n    set-e2uuid - set the ext2/3/4 filesystem UUID\n\nSYNOPSIS\n     set-e2uuid device uuid\n\nDESCRIPTION\n    This sets the ext2/3/4 filesystem UUID of the filesystem on \"device\" to\n    \"uuid\". The format of the UUID and alternatives such as \"clear\",\n    \"random\" and \"time\" are described in the tune2fs(8) manpage.\n\n    You can use either \"tune2fs_l\" or \"get_e2uuid\" to return the existing\n    UUID of a filesystem.\n\n",
  .run = run_set_e2uuid
};

struct command_entry get_e2uuid_cmd_entry = {
  .name = "get-e2uuid",
  .help = "NAME\n    get-e2uuid - get the ext2/3/4 filesystem UUID\n\nSYNOPSIS\n     get-e2uuid device\n\nDESCRIPTION\n    This returns the ext2/3/4 filesystem UUID of the filesystem on \"device\".\n\n    *This function is deprecated.* In new code, use the \"vfs_uuid\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_get_e2uuid
};

struct command_entry fsck_cmd_entry = {
  .name = "fsck",
  .help = "NAME\n    fsck - run the filesystem checker\n\nSYNOPSIS\n     fsck fstype device\n\nDESCRIPTION\n    This runs the filesystem checker (fsck) on \"device\" which should have\n    filesystem type \"fstype\".\n\n    The returned integer is the status. See fsck(8) for the list of status\n    codes from \"fsck\".\n\n    Notes:\n\n    *   Multiple status codes can be summed together.\n\n    *   A non-zero return code can mean \"success\", for example if errors\n        have been corrected on the filesystem.\n\n    *   Checking or repairing NTFS volumes is not supported (by linux-ntfs).\n\n    This command is entirely equivalent to running \"fsck -a -t fstype\n    device\".\n\n",
  .run = run_fsck
};

struct command_entry zero_cmd_entry = {
  .name = "zero",
  .help = "NAME\n    zero - write zeroes to the device\n\nSYNOPSIS\n     zero device\n\nDESCRIPTION\n    This command writes zeroes over the first few blocks of \"device\".\n\n    How many blocks are zeroed isn't specified (but it's *not* enough to\n    securely wipe the device). It should be sufficient to remove any\n    partition tables, filesystem superblocks and so on.\n\n    If blocks are already zero, then this command avoids writing zeroes.\n    This prevents the underlying device from becoming non-sparse or growing\n    unnecessarily.\n\n    See also: \"zero_device\", \"scrub_device\", \"is_zero_device\"\n\n",
  .run = run_zero
};

struct command_entry grub_install_cmd_entry = {
  .name = "grub-install",
  .help = "NAME\n    grub-install - install GRUB 1\n\nSYNOPSIS\n     grub-install root device\n\nDESCRIPTION\n    This command installs GRUB 1 (the Grand Unified Bootloader) on \"device\",\n    with the root directory being \"root\".\n\n    Notes:\n\n    *   There is currently no way in the API to install grub2, which is used\n        by most modern Linux guests. It is possible to run the grub2 command\n        from the guest, although see the caveats in \"RUNNING COMMANDS\" in\n        guestfs(3).\n\n    *   This uses \"grub-install\" from the host. Unfortunately grub is not\n        always compatible with itself, so this only works in rather narrow\n        circumstances. Careful testing with each guest version is advisable.\n\n    *   If grub-install reports the error \"No suitable drive was found in\n        the generated device map.\" it may be that you need to create a\n        \"/boot/grub/device.map\" file first that contains the mapping between\n        grub device names and Linux device names. It is usually sufficient\n        to create a file containing:\n\n         (hd0) /dev/vda\n\n        replacing \"/dev/vda\" with the name of the installation device.\n\n",
  .run = run_grub_install
};

struct command_entry cp_cmd_entry = {
  .name = "cp",
  .help = "NAME\n    cp - copy a file\n\nSYNOPSIS\n     cp src dest\n\nDESCRIPTION\n    This copies a file from \"src\" to \"dest\" where \"dest\" is either a\n    destination filename or destination directory.\n\n",
  .run = run_cp
};

struct command_entry cp_a_cmd_entry = {
  .name = "cp-a",
  .help = "NAME\n    cp-a - copy a file or directory recursively\n\nSYNOPSIS\n     cp-a src dest\n\nDESCRIPTION\n    This copies a file or directory from \"src\" to \"dest\" recursively using\n    the \"cp -a\" command.\n\n",
  .run = run_cp_a
};

struct command_entry mv_cmd_entry = {
  .name = "mv",
  .help = "NAME\n    mv - move a file\n\nSYNOPSIS\n     mv src dest\n\nDESCRIPTION\n    This moves a file from \"src\" to \"dest\" where \"dest\" is either a\n    destination filename or destination directory.\n\n",
  .run = run_mv
};

struct command_entry drop_caches_cmd_entry = {
  .name = "drop-caches",
  .help = "NAME\n    drop-caches - drop kernel page cache, dentries and inodes\n\nSYNOPSIS\n     drop-caches whattodrop\n\nDESCRIPTION\n    This instructs the guest kernel to drop its page cache, and/or dentries\n    and inode caches. The parameter \"whattodrop\" tells the kernel what\n    precisely to drop, see <http://linux-mm.org/Drop_Caches>\n\n    Setting \"whattodrop\" to 3 should drop everything.\n\n    This automatically calls sync(2) before the operation, so that the\n    maximum guest memory is freed.\n\n",
  .run = run_drop_caches
};

struct command_entry dmesg_cmd_entry = {
  .name = "dmesg",
  .help = "NAME\n    dmesg - return kernel messages\n\nSYNOPSIS\n     dmesg\n\nDESCRIPTION\n    This returns the kernel messages (\"dmesg\" output) from the guest kernel.\n    This is sometimes useful for extended debugging of problems.\n\n    Another way to get the same information is to enable verbose messages\n    with \"set_verbose\" or by setting the environment variable\n    \"LIBGUESTFS_DEBUG=1\" before running the program.\n\n",
  .run = run_dmesg
};

struct command_entry ping_daemon_cmd_entry = {
  .name = "ping-daemon",
  .help = "NAME\n    ping-daemon - ping the guest daemon\n\nSYNOPSIS\n     ping-daemon\n\nDESCRIPTION\n    This is a test probe into the guestfs daemon running inside the qemu\n    subprocess. Calling this function checks that the daemon responds to the\n    ping message, without affecting the daemon or attached block device(s)\n    in any other way.\n\n",
  .run = run_ping_daemon
};

struct command_entry equal_cmd_entry = {
  .name = "equal",
  .help = "NAME\n    equal - test if two files have equal contents\n\nSYNOPSIS\n     equal file1 file2\n\nDESCRIPTION\n    This compares the two files \"file1\" and \"file2\" and returns true if\n    their content is exactly equal, or false otherwise.\n\n    The external cmp(1) program is used for the comparison.\n\n",
  .run = run_equal
};

struct command_entry strings_cmd_entry = {
  .name = "strings",
  .help = "NAME\n    strings - print the printable strings in a file\n\nSYNOPSIS\n     strings path\n\nDESCRIPTION\n    This runs the strings(1) command on a file and returns the list of\n    printable strings found.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_strings
};

struct command_entry strings_e_cmd_entry = {
  .name = "strings-e",
  .help = "NAME\n    strings-e - print the printable strings in a file\n\nSYNOPSIS\n     strings-e encoding path\n\nDESCRIPTION\n    This is like the \"strings\" command, but allows you to specify the\n    encoding of strings that are looked for in the source file \"path\".\n\n    Allowed encodings are:\n\n    s   Single 7-bit-byte characters like ASCII and the ASCII-compatible\n        parts of ISO-8859-X (this is what \"strings\" uses).\n\n    S   Single 8-bit-byte characters.\n\n    b   16-bit big endian strings such as those encoded in UTF-16BE or\n        UCS-2BE.\n\n    l (lower case letter L)\n        16-bit little endian such as UTF-16LE and UCS-2LE. This is useful\n        for examining binaries in Windows guests.\n\n    B   32-bit big endian such as UCS-4BE.\n\n    L   32-bit little endian such as UCS-4LE.\n\n    The returned strings are transcoded to UTF-8.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_strings_e
};

struct command_entry hexdump_cmd_entry = {
  .name = "hexdump",
  .help = "NAME\n    hexdump - dump a file in hexadecimal\n\nSYNOPSIS\n     hexdump path\n\nDESCRIPTION\n    This runs \"hexdump -C\" on the given \"path\". The result is the\n    human-readable, canonical hex dump of the file.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_hexdump
};

struct command_entry zerofree_cmd_entry = {
  .name = "zerofree",
  .help = "NAME\n    zerofree - zero unused inodes and disk blocks on ext2/3 filesystem\n\nSYNOPSIS\n     zerofree device\n\nDESCRIPTION\n    This runs the *zerofree* program on \"device\". This program claims to\n    zero unused inodes and disk blocks on an ext2/3 filesystem, thus making\n    it possible to compress the filesystem more effectively.\n\n    You should not run this program if the filesystem is mounted.\n\n    It is possible that using this program can damage the filesystem or data\n    on the filesystem.\n\n",
  .run = run_zerofree
};

struct command_entry pvresize_cmd_entry = {
  .name = "pvresize",
  .help = "NAME\n    pvresize - resize an LVM physical volume\n\nSYNOPSIS\n     pvresize device\n\nDESCRIPTION\n    This resizes (expands or shrinks) an existing LVM physical volume to\n    match the new size of the underlying device.\n\n",
  .run = run_pvresize
};

struct command_entry sfdisk_N_cmd_entry = {
  .name = "sfdisk-N",
  .help = "NAME\n    sfdisk-N - modify a single partition on a block device\n\nSYNOPSIS\n     sfdisk-N device partnum cyls heads sectors line\n\nDESCRIPTION\n    This runs sfdisk(8) option to modify just the single partition \"n\"\n    (note: \"n\" counts from 1).\n\n    For other parameters, see \"sfdisk\". You should usually pass 0 for the\n    cyls/heads/sectors parameters.\n\n    See also: \"part_add\"\n\n    *This function is deprecated.* In new code, use the \"part_add\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_sfdisk_N
};

struct command_entry sfdisk_l_cmd_entry = {
  .name = "sfdisk-l",
  .help = "NAME\n    sfdisk-l - display the partition table\n\nSYNOPSIS\n     sfdisk-l device\n\nDESCRIPTION\n    This displays the partition table on \"device\", in the human-readable\n    output of the sfdisk(8) command. It is not intended to be parsed.\n\n    See also: \"part_list\"\n\n    *This function is deprecated.* In new code, use the \"part_list\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_sfdisk_l
};

struct command_entry sfdisk_kernel_geometry_cmd_entry = {
  .name = "sfdisk-kernel-geometry",
  .help = "NAME\n    sfdisk-kernel-geometry - display the kernel geometry\n\nSYNOPSIS\n     sfdisk-kernel-geometry device\n\nDESCRIPTION\n    This displays the kernel's idea of the geometry of \"device\".\n\n    The result is in human-readable format, and not designed to be parsed.\n\n",
  .run = run_sfdisk_kernel_geometry
};

struct command_entry sfdisk_disk_geometry_cmd_entry = {
  .name = "sfdisk-disk-geometry",
  .help = "NAME\n    sfdisk-disk-geometry - display the disk geometry from the partition\n    table\n\nSYNOPSIS\n     sfdisk-disk-geometry device\n\nDESCRIPTION\n    This displays the disk geometry of \"device\" read from the partition\n    table. Especially in the case where the underlying block device has been\n    resized, this can be different from the kernel's idea of the geometry\n    (see \"sfdisk_kernel_geometry\").\n\n    The result is in human-readable format, and not designed to be parsed.\n\n",
  .run = run_sfdisk_disk_geometry
};

struct command_entry vg_activate_all_cmd_entry = {
  .name = "vg-activate-all",
  .help = "NAME\n    vg-activate-all - activate or deactivate all volume groups\n\nSYNOPSIS\n     vg-activate-all activate\n\nDESCRIPTION\n    This command activates or (if \"activate\" is false) deactivates all\n    logical volumes in all volume groups.\n\n    This command is the same as running \"vgchange -a y|n\"\n\n",
  .run = run_vg_activate_all
};

struct command_entry vg_activate_cmd_entry = {
  .name = "vg-activate",
  .help = "NAME\n    vg-activate - activate or deactivate some volume groups\n\nSYNOPSIS\n     vg-activate activate volgroups\n\nDESCRIPTION\n    This command activates or (if \"activate\" is false) deactivates all\n    logical volumes in the listed volume groups \"volgroups\".\n\n    This command is the same as running \"vgchange -a y|n volgroups...\"\n\n    Note that if \"volgroups\" is an empty list then all volume groups are\n    activated or deactivated.\n\n",
  .run = run_vg_activate
};

struct command_entry lvresize_cmd_entry = {
  .name = "lvresize",
  .help = "NAME\n    lvresize - resize an LVM logical volume\n\nSYNOPSIS\n     lvresize device mbytes\n\nDESCRIPTION\n    This resizes (expands or shrinks) an existing LVM logical volume to\n    \"mbytes\". When reducing, data in the reduced part is lost.\n\n",
  .run = run_lvresize
};

struct command_entry resize2fs_cmd_entry = {
  .name = "resize2fs",
  .help = "NAME\n    resize2fs - resize an ext2, ext3 or ext4 filesystem\n\nSYNOPSIS\n     resize2fs device\n\nDESCRIPTION\n    This resizes an ext2, ext3 or ext4 filesystem to match the size of the\n    underlying device.\n\n    *Note:* It is sometimes required that you run \"e2fsck_f\" on the \"device\"\n    before calling this command. For unknown reasons \"resize2fs\" sometimes\n    gives an error about this and sometimes not. In any case, it is always\n    safe to call \"e2fsck_f\" before calling this function.\n\n",
  .run = run_resize2fs
};

struct command_entry find_cmd_entry = {
  .name = "find",
  .help = "NAME\n    find - find all files and directories\n\nSYNOPSIS\n     find directory\n\nDESCRIPTION\n    This command lists out all files and directories, recursively, starting\n    at \"directory\". It is essentially equivalent to running the shell\n    command \"find directory -print\" but some post-processing happens on the\n    output, described below.\n\n    This returns a list of strings *without any prefix*. Thus if the\n    directory structure was:\n\n     /tmp/a\n     /tmp/b\n     /tmp/c/d\n\n    then the returned list from \"find\" \"/tmp\" would be 4 elements:\n\n     a\n     b\n     c\n     c/d\n\n    If \"directory\" is not a directory, then this command returns an error.\n\n    The returned list is sorted.\n\n    See also \"find0\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_find
};

struct command_entry e2fsck_f_cmd_entry = {
  .name = "e2fsck-f",
  .help = "NAME\n    e2fsck-f - check an ext2/ext3 filesystem\n\nSYNOPSIS\n     e2fsck-f device\n\nDESCRIPTION\n    This runs \"e2fsck -p -f device\", ie. runs the ext2/ext3 filesystem\n    checker on \"device\", noninteractively (*-p*), even if the filesystem\n    appears to be clean (*-f*).\n\n    This command is only needed because of \"resize2fs\" (q.v.). Normally you\n    should use \"fsck\".\n\n",
  .run = run_e2fsck_f
};

struct command_entry sleep_cmd_entry = {
  .name = "sleep",
  .help = "NAME\n    sleep - sleep for some seconds\n\nSYNOPSIS\n     sleep secs\n\nDESCRIPTION\n    Sleep for \"secs\" seconds.\n\n",
  .run = run_sleep
};

struct command_entry ntfs_3g_probe_cmd_entry = {
  .name = "ntfs-3g-probe",
  .help = "NAME\n    ntfs-3g-probe - probe NTFS volume\n\nSYNOPSIS\n     ntfs-3g-probe rw device\n\nDESCRIPTION\n    This command runs the ntfs-3g.probe(8) command which probes an NTFS\n    \"device\" for mountability. (Not all NTFS volumes can be mounted\n    read-write, and some cannot be mounted at all).\n\n    \"rw\" is a boolean flag. Set it to true if you want to test if the volume\n    can be mounted read-write. Set it to false if you want to test if the\n    volume can be mounted read-only.\n\n    The return value is an integer which 0 if the operation would succeed,\n    or some non-zero value documented in the ntfs-3g.probe(8) manual page.\n\n",
  .run = run_ntfs_3g_probe
};

struct command_entry sh_cmd_entry = {
  .name = "sh",
  .help = "NAME\n    sh - run a command via the shell\n\nSYNOPSIS\n     sh command\n\nDESCRIPTION\n    This call runs a command from the guest filesystem via the guest's\n    \"/bin/sh\".\n\n    This is like \"command\", but passes the command to:\n\n     /bin/sh -c \"command\"\n\n    Depending on the guest's shell, this usually results in wildcards being\n    expanded, shell expressions being interpolated and so on.\n\n    All the provisos about \"command\" apply to this call.\n\n",
  .run = run_sh
};

struct command_entry sh_lines_cmd_entry = {
  .name = "sh-lines",
  .help = "NAME\n    sh-lines - run a command via the shell returning lines\n\nSYNOPSIS\n     sh-lines command\n\nDESCRIPTION\n    This is the same as \"sh\", but splits the result into a list of lines.\n\n    See also: \"command_lines\"\n\n",
  .run = run_sh_lines
};

struct command_entry glob_expand_cmd_entry = {
  .name = "glob-expand",
  .help = "NAME\n    glob-expand - expand a wildcard path\n\nSYNOPSIS\n     glob-expand pattern\n\nDESCRIPTION\n    This command searches for all the pathnames matching \"pattern\" according\n    to the wildcard expansion rules used by the shell.\n\n    If no paths match, then this returns an empty list (note: not an error).\n\n    It is just a wrapper around the C glob(3) function with flags\n    \"GLOB_MARK|GLOB_BRACE\". See that manual page for more details.\n\n",
  .run = run_glob_expand
};

struct command_entry scrub_device_cmd_entry = {
  .name = "scrub-device",
  .help = "NAME\n    scrub-device - scrub (securely wipe) a device\n\nSYNOPSIS\n     scrub-device device\n\nDESCRIPTION\n    This command writes patterns over \"device\" to make data retrieval more\n    difficult.\n\n    It is an interface to the scrub(1) program. See that manual page for\n    more details.\n\n",
  .run = run_scrub_device
};

struct command_entry scrub_file_cmd_entry = {
  .name = "scrub-file",
  .help = "NAME\n    scrub-file - scrub (securely wipe) a file\n\nSYNOPSIS\n     scrub-file file\n\nDESCRIPTION\n    This command writes patterns over a file to make data retrieval more\n    difficult.\n\n    The file is *removed* after scrubbing.\n\n    It is an interface to the scrub(1) program. See that manual page for\n    more details.\n\n",
  .run = run_scrub_file
};

struct command_entry scrub_freespace_cmd_entry = {
  .name = "scrub-freespace",
  .help = "NAME\n    scrub-freespace - scrub (securely wipe) free space\n\nSYNOPSIS\n     scrub-freespace dir\n\nDESCRIPTION\n    This command creates the directory \"dir\" and then fills it with files\n    until the filesystem is full, and scrubs the files as for \"scrub_file\",\n    and deletes them. The intention is to scrub any free space on the\n    partition containing \"dir\".\n\n    It is an interface to the scrub(1) program. See that manual page for\n    more details.\n\n",
  .run = run_scrub_freespace
};

struct command_entry mkdtemp_cmd_entry = {
  .name = "mkdtemp",
  .help = "NAME\n    mkdtemp - create a temporary directory\n\nSYNOPSIS\n     mkdtemp tmpl\n\nDESCRIPTION\n    This command creates a temporary directory. The \"tmpl\" parameter should\n    be a full pathname for the temporary directory name with the final six\n    characters being \"XXXXXX\".\n\n    For example: \"/tmp/myprogXXXXXX\" or \"/Temp/myprogXXXXXX\", the second one\n    being suitable for Windows filesystems.\n\n    The name of the temporary directory that was created is returned.\n\n    The temporary directory is created with mode 0700 and is owned by root.\n\n    The caller is responsible for deleting the temporary directory and its\n    contents after use.\n\n    See also: mkdtemp(3)\n\n",
  .run = run_mkdtemp
};

struct command_entry wc_l_cmd_entry = {
  .name = "wc-l",
  .help = "NAME\n    wc-l - count lines in a file\n\nSYNOPSIS\n     wc-l path\n\nDESCRIPTION\n    This command counts the lines in a file, using the \"wc -l\" external\n    command.\n\n",
  .run = run_wc_l
};

struct command_entry wc_w_cmd_entry = {
  .name = "wc-w",
  .help = "NAME\n    wc-w - count words in a file\n\nSYNOPSIS\n     wc-w path\n\nDESCRIPTION\n    This command counts the words in a file, using the \"wc -w\" external\n    command.\n\n",
  .run = run_wc_w
};

struct command_entry wc_c_cmd_entry = {
  .name = "wc-c",
  .help = "NAME\n    wc-c - count characters in a file\n\nSYNOPSIS\n     wc-c path\n\nDESCRIPTION\n    This command counts the characters in a file, using the \"wc -c\" external\n    command.\n\n",
  .run = run_wc_c
};

struct command_entry head_cmd_entry = {
  .name = "head",
  .help = "NAME\n    head - return first 10 lines of a file\n\nSYNOPSIS\n     head path\n\nDESCRIPTION\n    This command returns up to the first 10 lines of a file as a list of\n    strings.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_head
};

struct command_entry head_n_cmd_entry = {
  .name = "head-n",
  .help = "NAME\n    head-n - return first N lines of a file\n\nSYNOPSIS\n     head-n nrlines path\n\nDESCRIPTION\n    If the parameter \"nrlines\" is a positive number, this returns the first\n    \"nrlines\" lines of the file \"path\".\n\n    If the parameter \"nrlines\" is a negative number, this returns lines from\n    the file \"path\", excluding the last \"nrlines\" lines.\n\n    If the parameter \"nrlines\" is zero, this returns an empty list.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_head_n
};

struct command_entry tail_cmd_entry = {
  .name = "tail",
  .help = "NAME\n    tail - return last 10 lines of a file\n\nSYNOPSIS\n     tail path\n\nDESCRIPTION\n    This command returns up to the last 10 lines of a file as a list of\n    strings.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_tail
};

struct command_entry tail_n_cmd_entry = {
  .name = "tail-n",
  .help = "NAME\n    tail-n - return last N lines of a file\n\nSYNOPSIS\n     tail-n nrlines path\n\nDESCRIPTION\n    If the parameter \"nrlines\" is a positive number, this returns the last\n    \"nrlines\" lines of the file \"path\".\n\n    If the parameter \"nrlines\" is a negative number, this returns lines from\n    the file \"path\", starting with the \"-nrlines\"th line.\n\n    If the parameter \"nrlines\" is zero, this returns an empty list.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_tail_n
};

struct command_entry df_cmd_entry = {
  .name = "df",
  .help = "NAME\n    df - report file system disk space usage\n\nSYNOPSIS\n     df\n\nDESCRIPTION\n    This command runs the \"df\" command to report disk space used.\n\n    This command is mostly useful for interactive sessions. It is *not*\n    intended that you try to parse the output string. Use \"statvfs\" from\n    programs.\n\n",
  .run = run_df
};

struct command_entry df_h_cmd_entry = {
  .name = "df-h",
  .help = "NAME\n    df-h - report file system disk space usage (human readable)\n\nSYNOPSIS\n     df-h\n\nDESCRIPTION\n    This command runs the \"df -h\" command to report disk space used in\n    human-readable format.\n\n    This command is mostly useful for interactive sessions. It is *not*\n    intended that you try to parse the output string. Use \"statvfs\" from\n    programs.\n\n",
  .run = run_df_h
};

struct command_entry du_cmd_entry = {
  .name = "du",
  .help = "NAME\n    du - estimate file space usage\n\nSYNOPSIS\n     du path\n\nDESCRIPTION\n    This command runs the \"du -s\" command to estimate file space usage for\n    \"path\".\n\n    \"path\" can be a file or a directory. If \"path\" is a directory then the\n    estimate includes the contents of the directory and all subdirectories\n    (recursively).\n\n    The result is the estimated size in *kilobytes* (ie. units of 1024\n    bytes).\n\n",
  .run = run_du
};

struct command_entry initrd_list_cmd_entry = {
  .name = "initrd-list",
  .help = "NAME\n    initrd-list - list files in an initrd\n\nSYNOPSIS\n     initrd-list path\n\nDESCRIPTION\n    This command lists out files contained in an initrd.\n\n    The files are listed without any initial \"/\" character. The files are\n    listed in the order they appear (not necessarily alphabetical).\n    Directory names are listed as separate items.\n\n    Old Linux kernels (2.4 and earlier) used a compressed ext2 filesystem as\n    initrd. We *only* support the newer initramfs format (compressed cpio\n    files).\n\n",
  .run = run_initrd_list
};

struct command_entry mount_loop_cmd_entry = {
  .name = "mount-loop",
  .help = "NAME\n    mount-loop - mount a file using the loop device\n\nSYNOPSIS\n     mount-loop file mountpoint\n\nDESCRIPTION\n    This command lets you mount \"file\" (a filesystem image in a file) on a\n    mount point. It is entirely equivalent to the command \"mount -o loop\n    file mountpoint\".\n\n",
  .run = run_mount_loop
};

struct command_entry mkswap_cmd_entry = {
  .name = "mkswap",
  .help = "NAME\n    mkswap - create a swap partition\n\nSYNOPSIS\n     mkswap device\n\nDESCRIPTION\n    Create a swap partition on \"device\".\n\n",
  .run = run_mkswap
};

struct command_entry mkswap_L_cmd_entry = {
  .name = "mkswap-L",
  .help = "NAME\n    mkswap-L - create a swap partition with a label\n\nSYNOPSIS\n     mkswap-L label device\n\nDESCRIPTION\n    Create a swap partition on \"device\" with label \"label\".\n\n    Note that you cannot attach a swap label to a block device (eg.\n    \"/dev/sda\"), just to a partition. This appears to be a limitation of the\n    kernel or swap tools.\n\n",
  .run = run_mkswap_L
};

struct command_entry mkswap_U_cmd_entry = {
  .name = "mkswap-U",
  .help = "NAME\n    mkswap-U - create a swap partition with an explicit UUID\n\nSYNOPSIS\n     mkswap-U uuid device\n\nDESCRIPTION\n    Create a swap partition on \"device\" with UUID \"uuid\".\n\n",
  .run = run_mkswap_U
};

struct command_entry mknod_cmd_entry = {
  .name = "mknod",
  .help = "NAME\n    mknod - make block, character or FIFO devices\n\nSYNOPSIS\n     mknod mode devmajor devminor path\n\nDESCRIPTION\n    This call creates block or character special devices, or named pipes\n    (FIFOs).\n\n    The \"mode\" parameter should be the mode, using the standard constants.\n    \"devmajor\" and \"devminor\" are the device major and minor numbers, only\n    used when creating block and character special devices.\n\n    Note that, just like mknod(2), the mode must be bitwise OR'd with\n    S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK (otherwise this call just creates\n    a regular file). These constants are available in the standard Linux\n    header files, or you can use \"mknod_b\", \"mknod_c\" or \"mkfifo\" which are\n    wrappers around this command which bitwise OR in the appropriate\n    constant for you.\n\n    The mode actually set is affected by the umask.\n\n",
  .run = run_mknod
};

struct command_entry mkfifo_cmd_entry = {
  .name = "mkfifo",
  .help = "NAME\n    mkfifo - make FIFO (named pipe)\n\nSYNOPSIS\n     mkfifo mode path\n\nDESCRIPTION\n    This call creates a FIFO (named pipe) called \"path\" with mode \"mode\". It\n    is just a convenient wrapper around \"mknod\".\n\n    The mode actually set is affected by the umask.\n\n",
  .run = run_mkfifo
};

struct command_entry mknod_b_cmd_entry = {
  .name = "mknod-b",
  .help = "NAME\n    mknod-b - make block device node\n\nSYNOPSIS\n     mknod-b mode devmajor devminor path\n\nDESCRIPTION\n    This call creates a block device node called \"path\" with mode \"mode\" and\n    device major/minor \"devmajor\" and \"devminor\". It is just a convenient\n    wrapper around \"mknod\".\n\n    The mode actually set is affected by the umask.\n\n",
  .run = run_mknod_b
};

struct command_entry mknod_c_cmd_entry = {
  .name = "mknod-c",
  .help = "NAME\n    mknod-c - make char device node\n\nSYNOPSIS\n     mknod-c mode devmajor devminor path\n\nDESCRIPTION\n    This call creates a char device node called \"path\" with mode \"mode\" and\n    device major/minor \"devmajor\" and \"devminor\". It is just a convenient\n    wrapper around \"mknod\".\n\n    The mode actually set is affected by the umask.\n\n",
  .run = run_mknod_c
};

struct command_entry umask_cmd_entry = {
  .name = "umask",
  .help = "NAME\n    umask - set file mode creation mask (umask)\n\nSYNOPSIS\n     umask mask\n\nDESCRIPTION\n    This function sets the mask used for creating new files and device nodes\n    to \"mask & 0777\".\n\n    Typical umask values would be 022 which creates new files with\n    permissions like \"-rw-r--r--\" or \"-rwxr-xr-x\", and 002 which creates new\n    files with permissions like \"-rw-rw-r--\" or \"-rwxrwxr-x\".\n\n    The default umask is 022. This is important because it means that\n    directories and device nodes will be created with 0644 or 0755 mode even\n    if you specify 0777.\n\n    See also \"get_umask\", umask(2), \"mknod\", \"mkdir\".\n\n    This call returns the previous umask.\n\n",
  .run = run_umask
};

struct command_entry readdir_cmd_entry = {
  .name = "readdir",
  .help = "NAME\n    readdir - read directories entries\n\nSYNOPSIS\n     readdir dir\n\nDESCRIPTION\n    This returns the list of directory entries in directory \"dir\".\n\n    All entries in the directory are returned, including \".\" and \"..\". The\n    entries are *not* sorted, but returned in the same order as the\n    underlying filesystem.\n\n    Also this call returns basic file type information about each file. The\n    \"ftyp\" field will contain one of the following characters:\n\n    'b' Block special\n\n    'c' Char special\n\n    'd' Directory\n\n    'f' FIFO (named pipe)\n\n    'l' Symbolic link\n\n    'r' Regular file\n\n    's' Socket\n\n    'u' Unknown file type\n\n    '?' The readdir(3) call returned a \"d_type\" field with an unexpected\n        value\n\n    This function is primarily intended for use by programs. To get a simple\n    list of names, use \"ls\". To get a printable directory for human\n    consumption, use \"ll\".\n\n",
  .run = run_readdir
};

struct command_entry sfdiskM_cmd_entry = {
  .name = "sfdiskM",
  .help = "NAME\n    sfdiskM - create partitions on a block device\n\nSYNOPSIS\n     sfdiskM device lines\n\nDESCRIPTION\n    This is a simplified interface to the \"sfdisk\" command, where partition\n    sizes are specified in megabytes only (rounded to the nearest cylinder)\n    and you don't need to specify the cyls, heads and sectors parameters\n    which were rarely if ever used anyway.\n\n    See also: \"sfdisk\", the sfdisk(8) manpage and \"part_disk\"\n\n    *This function is deprecated.* In new code, use the \"part_add\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_sfdiskM
};

struct command_entry zfile_cmd_entry = {
  .name = "zfile",
  .help = "NAME\n    zfile - determine file type inside a compressed file\n\nSYNOPSIS\n     zfile meth path\n\nDESCRIPTION\n    This command runs \"file\" after first decompressing \"path\" using\n    \"method\".\n\n    \"method\" must be one of \"gzip\", \"compress\" or \"bzip2\".\n\n    Since 1.0.63, use \"file\" instead which can now process compressed files.\n\n    *This function is deprecated.* In new code, use the \"file\" call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_zfile
};

struct command_entry getxattrs_cmd_entry = {
  .name = "getxattrs",
  .help = "NAME\n    getxattrs - list extended attributes of a file or directory\n\nSYNOPSIS\n     getxattrs path\n\nDESCRIPTION\n    This call lists the extended attributes of the file or directory \"path\".\n\n    At the system call level, this is a combination of the listxattr(2) and\n    getxattr(2) calls.\n\n    See also: \"lgetxattrs\", attr(5).\n\n",
  .run = run_getxattrs
};

struct command_entry lgetxattrs_cmd_entry = {
  .name = "lgetxattrs",
  .help = "NAME\n    lgetxattrs - list extended attributes of a file or directory\n\nSYNOPSIS\n     lgetxattrs path\n\nDESCRIPTION\n    This is the same as \"getxattrs\", but if \"path\" is a symbolic link, then\n    it returns the extended attributes of the link itself.\n\n",
  .run = run_lgetxattrs
};

struct command_entry setxattr_cmd_entry = {
  .name = "setxattr",
  .help = "NAME\n    setxattr - set extended attribute of a file or directory\n\nSYNOPSIS\n     setxattr xattr val vallen path\n\nDESCRIPTION\n    This call sets the extended attribute named \"xattr\" of the file \"path\"\n    to the value \"val\" (of length \"vallen\"). The value is arbitrary 8 bit\n    data.\n\n    See also: \"lsetxattr\", attr(5).\n\n",
  .run = run_setxattr
};

struct command_entry lsetxattr_cmd_entry = {
  .name = "lsetxattr",
  .help = "NAME\n    lsetxattr - set extended attribute of a file or directory\n\nSYNOPSIS\n     lsetxattr xattr val vallen path\n\nDESCRIPTION\n    This is the same as \"setxattr\", but if \"path\" is a symbolic link, then\n    it sets an extended attribute of the link itself.\n\n",
  .run = run_lsetxattr
};

struct command_entry removexattr_cmd_entry = {
  .name = "removexattr",
  .help = "NAME\n    removexattr - remove extended attribute of a file or directory\n\nSYNOPSIS\n     removexattr xattr path\n\nDESCRIPTION\n    This call removes the extended attribute named \"xattr\" of the file\n    \"path\".\n\n    See also: \"lremovexattr\", attr(5).\n\n",
  .run = run_removexattr
};

struct command_entry lremovexattr_cmd_entry = {
  .name = "lremovexattr",
  .help = "NAME\n    lremovexattr - remove extended attribute of a file or directory\n\nSYNOPSIS\n     lremovexattr xattr path\n\nDESCRIPTION\n    This is the same as \"removexattr\", but if \"path\" is a symbolic link,\n    then it removes an extended attribute of the link itself.\n\n",
  .run = run_lremovexattr
};

struct command_entry mountpoints_cmd_entry = {
  .name = "mountpoints",
  .help = "NAME\n    mountpoints - show mountpoints\n\nSYNOPSIS\n     mountpoints\n\nDESCRIPTION\n    This call is similar to \"mounts\". That call returns a list of devices.\n    This one returns a hash table (map) of device name to directory where\n    the device is mounted.\n\n",
  .run = run_mountpoints
};

struct command_entry mkmountpoint_cmd_entry = {
  .name = "mkmountpoint",
  .help = "NAME\n    mkmountpoint - create a mountpoint\n\nSYNOPSIS\n     mkmountpoint exemptpath\n\nDESCRIPTION\n    \"mkmountpoint\" and \"rmmountpoint\" are specialized calls that can be used\n    to create extra mountpoints before mounting the first filesystem.\n\n    These calls are *only* necessary in some very limited circumstances,\n    mainly the case where you want to mount a mix of unrelated and/or\n    read-only filesystems together.\n\n    For example, live CDs often contain a \"Russian doll\" nest of\n    filesystems, an ISO outer layer, with a squashfs image inside, with an\n    ext2/3 image inside that. You can unpack this as follows in guestfish:\n\n     add-ro Fedora-11-i686-Live.iso\n     run\n     mkmountpoint /cd\n     mkmountpoint /sqsh\n     mkmountpoint /ext3fs\n     mount /dev/sda /cd\n     mount-loop /cd/LiveOS/squashfs.img /sqsh\n     mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs\n\n    The inner filesystem is now unpacked under the /ext3fs mountpoint.\n\n    \"mkmountpoint\" is not compatible with \"umount_all\". You may get\n    unexpected errors if you try to mix these calls. It is safest to\n    manually unmount filesystems and remove mountpoints after use.\n\n    \"umount_all\" unmounts filesystems by sorting the paths longest first, so\n    for this to work for manual mountpoints, you must ensure that the\n    innermost mountpoints have the longest pathnames, as in the example code\n    above.\n\n    For more details see\n    <https://bugzilla.redhat.com/show_bug.cgi?id=599503>\n\n    Autosync [see \"set_autosync\", this is set by default on handles] can\n    cause \"umount_all\" to be called when the handle is closed which can also\n    trigger these issues.\n\n",
  .run = run_mkmountpoint
};

struct command_entry rmmountpoint_cmd_entry = {
  .name = "rmmountpoint",
  .help = "NAME\n    rmmountpoint - remove a mountpoint\n\nSYNOPSIS\n     rmmountpoint exemptpath\n\nDESCRIPTION\n    This calls removes a mountpoint that was previously created with\n    \"mkmountpoint\". See \"mkmountpoint\" for full details.\n\n",
  .run = run_rmmountpoint
};

struct command_entry read_file_cmd_entry = {
  .name = "read-file",
  .help = "NAME\n    read-file - read a file\n\nSYNOPSIS\n     read-file path\n\nDESCRIPTION\n    This calls returns the contents of the file \"path\" as a buffer.\n\n    Unlike \"cat\", this function can correctly handle files that contain\n    embedded ASCII NUL characters. However unlike \"download\", this function\n    is limited in the total size of file that can be handled.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_read_file
};

struct command_entry grep_cmd_entry = {
  .name = "grep",
  .help = "NAME\n    grep - return lines matching a pattern\n\nSYNOPSIS\n     grep regex path\n\nDESCRIPTION\n    This calls the external \"grep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_grep
};

struct command_entry egrep_cmd_entry = {
  .name = "egrep",
  .help = "NAME\n    egrep - return lines matching a pattern\n\nSYNOPSIS\n     egrep regex path\n\nDESCRIPTION\n    This calls the external \"egrep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_egrep
};

struct command_entry fgrep_cmd_entry = {
  .name = "fgrep",
  .help = "NAME\n    fgrep - return lines matching a pattern\n\nSYNOPSIS\n     fgrep pattern path\n\nDESCRIPTION\n    This calls the external \"fgrep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_fgrep
};

struct command_entry grepi_cmd_entry = {
  .name = "grepi",
  .help = "NAME\n    grepi - return lines matching a pattern\n\nSYNOPSIS\n     grepi regex path\n\nDESCRIPTION\n    This calls the external \"grep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_grepi
};

struct command_entry egrepi_cmd_entry = {
  .name = "egrepi",
  .help = "NAME\n    egrepi - return lines matching a pattern\n\nSYNOPSIS\n     egrepi regex path\n\nDESCRIPTION\n    This calls the external \"egrep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_egrepi
};

struct command_entry fgrepi_cmd_entry = {
  .name = "fgrepi",
  .help = "NAME\n    fgrepi - return lines matching a pattern\n\nSYNOPSIS\n     fgrepi pattern path\n\nDESCRIPTION\n    This calls the external \"fgrep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_fgrepi
};

struct command_entry zgrep_cmd_entry = {
  .name = "zgrep",
  .help = "NAME\n    zgrep - return lines matching a pattern\n\nSYNOPSIS\n     zgrep regex path\n\nDESCRIPTION\n    This calls the external \"zgrep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zgrep
};

struct command_entry zegrep_cmd_entry = {
  .name = "zegrep",
  .help = "NAME\n    zegrep - return lines matching a pattern\n\nSYNOPSIS\n     zegrep regex path\n\nDESCRIPTION\n    This calls the external \"zegrep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zegrep
};

struct command_entry zfgrep_cmd_entry = {
  .name = "zfgrep",
  .help = "NAME\n    zfgrep - return lines matching a pattern\n\nSYNOPSIS\n     zfgrep pattern path\n\nDESCRIPTION\n    This calls the external \"zfgrep\" program and returns the matching lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zfgrep
};

struct command_entry zgrepi_cmd_entry = {
  .name = "zgrepi",
  .help = "NAME\n    zgrepi - return lines matching a pattern\n\nSYNOPSIS\n     zgrepi regex path\n\nDESCRIPTION\n    This calls the external \"zgrep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zgrepi
};

struct command_entry zegrepi_cmd_entry = {
  .name = "zegrepi",
  .help = "NAME\n    zegrepi - return lines matching a pattern\n\nSYNOPSIS\n     zegrepi regex path\n\nDESCRIPTION\n    This calls the external \"zegrep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zegrepi
};

struct command_entry zfgrepi_cmd_entry = {
  .name = "zfgrepi",
  .help = "NAME\n    zfgrepi - return lines matching a pattern\n\nSYNOPSIS\n     zfgrepi pattern path\n\nDESCRIPTION\n    This calls the external \"zfgrep -i\" program and returns the matching\n    lines.\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_zfgrepi
};

struct command_entry realpath_cmd_entry = {
  .name = "realpath",
  .help = "NAME\n    realpath - canonicalized absolute pathname\n\nSYNOPSIS\n     realpath path\n\nDESCRIPTION\n    Return the canonicalized absolute pathname of \"path\". The returned path\n    has no \".\", \"..\" or symbolic link path elements.\n\n",
  .run = run_realpath
};

struct command_entry ln_cmd_entry = {
  .name = "ln",
  .help = "NAME\n    ln - create a hard link\n\nSYNOPSIS\n     ln target linkname\n\nDESCRIPTION\n    This command creates a hard link using the \"ln\" command.\n\n",
  .run = run_ln
};

struct command_entry ln_f_cmd_entry = {
  .name = "ln-f",
  .help = "NAME\n    ln-f - create a hard link\n\nSYNOPSIS\n     ln-f target linkname\n\nDESCRIPTION\n    This command creates a hard link using the \"ln -f\" command. The *-f*\n    option removes the link (\"linkname\") if it exists already.\n\n",
  .run = run_ln_f
};

struct command_entry ln_s_cmd_entry = {
  .name = "ln-s",
  .help = "NAME\n    ln-s - create a symbolic link\n\nSYNOPSIS\n     ln-s target linkname\n\nDESCRIPTION\n    This command creates a symbolic link using the \"ln -s\" command.\n\n",
  .run = run_ln_s
};

struct command_entry ln_sf_cmd_entry = {
  .name = "ln-sf",
  .help = "NAME\n    ln-sf - create a symbolic link\n\nSYNOPSIS\n     ln-sf target linkname\n\nDESCRIPTION\n    This command creates a symbolic link using the \"ln -sf\" command, The\n    *-f* option removes the link (\"linkname\") if it exists already.\n\n",
  .run = run_ln_sf
};

struct command_entry readlink_cmd_entry = {
  .name = "readlink",
  .help = "NAME\n    readlink - read the target of a symbolic link\n\nSYNOPSIS\n     readlink path\n\nDESCRIPTION\n    This command reads the target of a symbolic link.\n\n",
  .run = run_readlink
};

struct command_entry fallocate_cmd_entry = {
  .name = "fallocate",
  .help = "NAME\n    fallocate - preallocate a file in the guest filesystem\n\nSYNOPSIS\n     fallocate path len\n\nDESCRIPTION\n    This command preallocates a file (containing zero bytes) named \"path\" of\n    size \"len\" bytes. If the file exists already, it is overwritten.\n\n    Do not confuse this with the guestfish-specific \"alloc\" command which\n    allocates a file in the host and attaches it as a device.\n\n    *This function is deprecated.* In new code, use the \"fallocate64\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_fallocate
};

struct command_entry swapon_device_cmd_entry = {
  .name = "swapon-device",
  .help = "NAME\n    swapon-device - enable swap on device\n\nSYNOPSIS\n     swapon-device device\n\nDESCRIPTION\n    This command enables the libguestfs appliance to use the swap device or\n    partition named \"device\". The increased memory is made available for all\n    commands, for example those run using \"command\" or \"sh\".\n\n    Note that you should not swap to existing guest swap partitions unless\n    you know what you are doing. They may contain hibernation information,\n    or other information that the guest doesn't want you to trash. You also\n    risk leaking information about the host to the guest this way. Instead,\n    attach a new host device to the guest and swap on that.\n\n",
  .run = run_swapon_device
};

struct command_entry swapoff_device_cmd_entry = {
  .name = "swapoff-device",
  .help = "NAME\n    swapoff-device - disable swap on device\n\nSYNOPSIS\n     swapoff-device device\n\nDESCRIPTION\n    This command disables the libguestfs appliance swap device or partition\n    named \"device\". See \"swapon_device\".\n\n",
  .run = run_swapoff_device
};

struct command_entry swapon_file_cmd_entry = {
  .name = "swapon-file",
  .help = "NAME\n    swapon-file - enable swap on file\n\nSYNOPSIS\n     swapon-file file\n\nDESCRIPTION\n    This command enables swap to a file. See \"swapon_device\" for other\n    notes.\n\n",
  .run = run_swapon_file
};

struct command_entry swapoff_file_cmd_entry = {
  .name = "swapoff-file",
  .help = "NAME\n    swapoff-file - disable swap on file\n\nSYNOPSIS\n     swapoff-file file\n\nDESCRIPTION\n    This command disables the libguestfs appliance swap on file.\n\n",
  .run = run_swapoff_file
};

struct command_entry swapon_label_cmd_entry = {
  .name = "swapon-label",
  .help = "NAME\n    swapon-label - enable swap on labeled swap partition\n\nSYNOPSIS\n     swapon-label label\n\nDESCRIPTION\n    This command enables swap to a labeled swap partition. See\n    \"swapon_device\" for other notes.\n\n",
  .run = run_swapon_label
};

struct command_entry swapoff_label_cmd_entry = {
  .name = "swapoff-label",
  .help = "NAME\n    swapoff-label - disable swap on labeled swap partition\n\nSYNOPSIS\n     swapoff-label label\n\nDESCRIPTION\n    This command disables the libguestfs appliance swap on labeled swap\n    partition.\n\n",
  .run = run_swapoff_label
};

struct command_entry swapon_uuid_cmd_entry = {
  .name = "swapon-uuid",
  .help = "NAME\n    swapon-uuid - enable swap on swap partition by UUID\n\nSYNOPSIS\n     swapon-uuid uuid\n\nDESCRIPTION\n    This command enables swap to a swap partition with the given UUID. See\n    \"swapon_device\" for other notes.\n\n",
  .run = run_swapon_uuid
};

struct command_entry swapoff_uuid_cmd_entry = {
  .name = "swapoff-uuid",
  .help = "NAME\n    swapoff-uuid - disable swap on swap partition by UUID\n\nSYNOPSIS\n     swapoff-uuid uuid\n\nDESCRIPTION\n    This command disables the libguestfs appliance swap partition with the\n    given UUID.\n\n",
  .run = run_swapoff_uuid
};

struct command_entry mkswap_file_cmd_entry = {
  .name = "mkswap-file",
  .help = "NAME\n    mkswap-file - create a swap file\n\nSYNOPSIS\n     mkswap-file path\n\nDESCRIPTION\n    Create a swap file.\n\n    This command just writes a swap file signature to an existing file. To\n    create the file itself, use something like \"fallocate\".\n\n",
  .run = run_mkswap_file
};

struct command_entry inotify_init_cmd_entry = {
  .name = "inotify-init",
  .help = "NAME\n    inotify-init - create an inotify handle\n\nSYNOPSIS\n     inotify-init maxevents\n\nDESCRIPTION\n    This command creates a new inotify handle. The inotify subsystem can be\n    used to notify events which happen to objects in the guest filesystem.\n\n    \"maxevents\" is the maximum number of events which will be queued up\n    between calls to \"inotify_read\" or \"inotify_files\". If this is passed as\n    0, then the kernel (or previously set) default is used. For Linux 2.6.29\n    the default was 16384 events. Beyond this limit, the kernel throws away\n    events, but records the fact that it threw them away by setting a flag\n    \"IN_Q_OVERFLOW\" in the returned structure list (see \"inotify_read\").\n\n    Before any events are generated, you have to add some watches to the\n    internal watch list. See: \"inotify_add_watch\" and \"inotify_rm_watch\".\n\n    Queued up events should be read periodically by calling \"inotify_read\"\n    (or \"inotify_files\" which is just a helpful wrapper around\n    \"inotify_read\"). If you don't read the events out often enough then you\n    risk the internal queue overflowing.\n\n    The handle should be closed after use by calling \"inotify_close\". This\n    also removes any watches automatically.\n\n    See also inotify(7) for an overview of the inotify interface as exposed\n    by the Linux kernel, which is roughly what we expose via libguestfs.\n    Note that there is one global inotify handle per libguestfs instance.\n\n",
  .run = run_inotify_init
};

struct command_entry inotify_add_watch_cmd_entry = {
  .name = "inotify-add-watch",
  .help = "NAME\n    inotify-add-watch - add an inotify watch\n\nSYNOPSIS\n     inotify-add-watch path mask\n\nDESCRIPTION\n    Watch \"path\" for the events listed in \"mask\".\n\n    Note that if \"path\" is a directory then events within that directory are\n    watched, but this does *not* happen recursively (in subdirectories).\n\n    Note for non-C or non-Linux callers: the inotify events are defined by\n    the Linux kernel ABI and are listed in \"/usr/include/sys/inotify.h\".\n\n",
  .run = run_inotify_add_watch
};

struct command_entry inotify_rm_watch_cmd_entry = {
  .name = "inotify-rm-watch",
  .help = "NAME\n    inotify-rm-watch - remove an inotify watch\n\nSYNOPSIS\n     inotify-rm-watch wd\n\nDESCRIPTION\n    Remove a previously defined inotify watch. See \"inotify_add_watch\".\n\n",
  .run = run_inotify_rm_watch
};

struct command_entry inotify_read_cmd_entry = {
  .name = "inotify-read",
  .help = "NAME\n    inotify-read - return list of inotify events\n\nSYNOPSIS\n     inotify-read\n\nDESCRIPTION\n    Return the complete queue of events that have happened since the\n    previous read call.\n\n    If no events have happened, this returns an empty list.\n\n    *Note*: In order to make sure that all events have been read, you must\n    call this function repeatedly until it returns an empty list. The reason\n    is that the call will read events up to the maximum appliance-to-host\n    message size and leave remaining events in the queue.\n\n",
  .run = run_inotify_read
};

struct command_entry inotify_files_cmd_entry = {
  .name = "inotify-files",
  .help = "NAME\n    inotify-files - return list of watched files that had events\n\nSYNOPSIS\n     inotify-files\n\nDESCRIPTION\n    This function is a helpful wrapper around \"inotify_read\" which just\n    returns a list of pathnames of objects that were touched. The returned\n    pathnames are sorted and deduplicated.\n\n",
  .run = run_inotify_files
};

struct command_entry inotify_close_cmd_entry = {
  .name = "inotify-close",
  .help = "NAME\n    inotify-close - close the inotify handle\n\nSYNOPSIS\n     inotify-close\n\nDESCRIPTION\n    This closes the inotify handle which was previously opened by\n    inotify_init. It removes all watches, throws away any pending events,\n    and deallocates all resources.\n\n",
  .run = run_inotify_close
};

struct command_entry setcon_cmd_entry = {
  .name = "setcon",
  .help = "NAME\n    setcon - set SELinux security context\n\nSYNOPSIS\n     setcon context\n\nDESCRIPTION\n    This sets the SELinux security context of the daemon to the string\n    \"context\".\n\n    See the documentation about SELINUX in guestfs(3).\n\n",
  .run = run_setcon
};

struct command_entry getcon_cmd_entry = {
  .name = "getcon",
  .help = "NAME\n    getcon - get SELinux security context\n\nSYNOPSIS\n     getcon\n\nDESCRIPTION\n    This gets the SELinux security context of the daemon.\n\n    See the documentation about SELINUX in guestfs(3), and \"setcon\"\n\n",
  .run = run_getcon
};

struct command_entry mkfs_b_cmd_entry = {
  .name = "mkfs-b",
  .help = "NAME\n    mkfs-b - make a filesystem with block size\n\nSYNOPSIS\n     mkfs-b fstype blocksize device\n\nDESCRIPTION\n    This call is similar to \"mkfs\", but it allows you to control the block\n    size of the resulting filesystem. Supported block sizes depend on the\n    filesystem type, but typically they are 1024, 2048 or 4096 only.\n\n    For VFAT and NTFS the \"blocksize\" parameter is treated as the requested\n    cluster size.\n\n    *This function is deprecated.* In new code, use the \"mkfs_opts\" call\n    instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_mkfs_b
};

struct command_entry mke2journal_cmd_entry = {
  .name = "mke2journal",
  .help = "NAME\n    mke2journal - make ext2/3/4 external journal\n\nSYNOPSIS\n     mke2journal blocksize device\n\nDESCRIPTION\n    This creates an ext2 external journal on \"device\". It is equivalent to\n    the command:\n\n     mke2fs -O journal_dev -b blocksize device\n\n",
  .run = run_mke2journal
};

struct command_entry mke2journal_L_cmd_entry = {
  .name = "mke2journal-L",
  .help = "NAME\n    mke2journal-L - make ext2/3/4 external journal with label\n\nSYNOPSIS\n     mke2journal-L blocksize label device\n\nDESCRIPTION\n    This creates an ext2 external journal on \"device\" with label \"label\".\n\n",
  .run = run_mke2journal_L
};

struct command_entry mke2journal_U_cmd_entry = {
  .name = "mke2journal-U",
  .help = "NAME\n    mke2journal-U - make ext2/3/4 external journal with UUID\n\nSYNOPSIS\n     mke2journal-U blocksize uuid device\n\nDESCRIPTION\n    This creates an ext2 external journal on \"device\" with UUID \"uuid\".\n\n",
  .run = run_mke2journal_U
};

struct command_entry mke2fs_J_cmd_entry = {
  .name = "mke2fs-J",
  .help = "NAME\n    mke2fs-J - make ext2/3/4 filesystem with external journal\n\nSYNOPSIS\n     mke2fs-J fstype blocksize device journal\n\nDESCRIPTION\n    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n    on \"journal\". It is equivalent to the command:\n\n     mke2fs -t fstype -b blocksize -J device=<journal> <device>\n\n    See also \"mke2journal\".\n\n",
  .run = run_mke2fs_J
};

struct command_entry mke2fs_JL_cmd_entry = {
  .name = "mke2fs-JL",
  .help = "NAME\n    mke2fs-JL - make ext2/3/4 filesystem with external journal\n\nSYNOPSIS\n     mke2fs-JL fstype blocksize device label\n\nDESCRIPTION\n    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n    on the journal labeled \"label\".\n\n    See also \"mke2journal_L\".\n\n",
  .run = run_mke2fs_JL
};

struct command_entry mke2fs_JU_cmd_entry = {
  .name = "mke2fs-JU",
  .help = "NAME\n    mke2fs-JU - make ext2/3/4 filesystem with external journal\n\nSYNOPSIS\n     mke2fs-JU fstype blocksize device uuid\n\nDESCRIPTION\n    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n    on the journal with UUID \"uuid\".\n\n    See also \"mke2journal_U\".\n\n",
  .run = run_mke2fs_JU
};

struct command_entry modprobe_cmd_entry = {
  .name = "modprobe",
  .help = "NAME\n    modprobe - load a kernel module\n\nSYNOPSIS\n     modprobe modulename\n\nDESCRIPTION\n    This loads a kernel module in the appliance.\n\n    The kernel module must have been whitelisted when libguestfs was built\n    (see \"appliance/kmod.whitelist.in\" in the source).\n\n",
  .run = run_modprobe
};

struct command_entry echo_daemon_cmd_entry = {
  .name = "echo-daemon",
  .help = "NAME\n    echo-daemon - echo arguments back to the client\n\nSYNOPSIS\n     echo-daemon words\n\nDESCRIPTION\n    This command concatenates the list of \"words\" passed with single spaces\n    between them and returns the resulting string.\n\n    You can use this command to test the connection through to the daemon.\n\n    See also \"ping_daemon\".\n\n",
  .run = run_echo_daemon
};

struct command_entry find0_cmd_entry = {
  .name = "find0",
  .help = "NAME\n    find0 - find all files and directories, returning NUL-separated list\n\nSYNOPSIS\n     find0 directory files\n\nDESCRIPTION\n    This command lists out all files and directories, recursively, starting\n    at \"directory\", placing the resulting list in the external file called\n    \"files\".\n\n    This command works the same way as \"find\" with the following exceptions:\n\n    *   The resulting list is written to an external file.\n\n    *   Items (filenames) in the result are separated by \"\\0\" characters.\n        See find(1) option *-print0*.\n\n    *   This command is not limited in the number of names that it can\n        return.\n\n    *   The result list is not sorted.\n\n",
  .run = run_find0
};

struct command_entry case_sensitive_path_cmd_entry = {
  .name = "case-sensitive-path",
  .help = "NAME\n    case-sensitive-path - return true path on case-insensitive filesystem\n\nSYNOPSIS\n     case-sensitive-path path\n\nDESCRIPTION\n    This can be used to resolve case insensitive paths on a filesystem which\n    is case sensitive. The use case is to resolve paths which you have read\n    from Windows configuration files or the Windows Registry, to the true\n    path.\n\n    The command handles a peculiarity of the Linux ntfs-3g filesystem driver\n    (and probably others), which is that although the underlying filesystem\n    is case-insensitive, the driver exports the filesystem to Linux as\n    case-sensitive.\n\n    One consequence of this is that special directories such as \"c:\\windows\"\n    may appear as \"/WINDOWS\" or \"/windows\" (or other things) depending on\n    the precise details of how they were created. In Windows itself this\n    would not be a problem.\n\n    Bug or feature? You decide:\n    <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1>\n\n    This function resolves the true case of each element in the path and\n    returns the case-sensitive path.\n\n    Thus \"case_sensitive_path\" (\"/Windows/System32\") might return\n    \"/WINDOWS/system32\" (the exact return value would depend on details of\n    how the directories were originally created under Windows).\n\n    *Note*: This function does not handle drive names, backslashes etc.\n\n    See also \"realpath\".\n\n",
  .run = run_case_sensitive_path
};

struct command_entry vfs_type_cmd_entry = {
  .name = "vfs-type",
  .help = "NAME\n    vfs-type - get the Linux VFS type corresponding to a mounted device\n\nSYNOPSIS\n     vfs-type device\n\nDESCRIPTION\n    This command gets the filesystem type corresponding to the filesystem on\n    \"device\".\n\n    For most filesystems, the result is the name of the Linux VFS module\n    which would be used to mount this filesystem if you mounted it without\n    specifying the filesystem type. For example a string such as \"ext3\" or\n    \"ntfs\".\n\n",
  .run = run_vfs_type
};

struct command_entry truncate_cmd_entry = {
  .name = "truncate",
  .help = "NAME\n    truncate - truncate a file to zero size\n\nSYNOPSIS\n     truncate path\n\nDESCRIPTION\n    This command truncates \"path\" to a zero-length file. The file must exist\n    already.\n\n",
  .run = run_truncate
};

struct command_entry truncate_size_cmd_entry = {
  .name = "truncate-size",
  .help = "NAME\n    truncate-size - truncate a file to a particular size\n\nSYNOPSIS\n     truncate-size path size\n\nDESCRIPTION\n    This command truncates \"path\" to size \"size\" bytes. The file must exist\n    already.\n\n    If the current file size is less than \"size\" then the file is extended\n    to the required size with zero bytes. This creates a sparse file (ie.\n    disk blocks are not allocated for the file until you write to it). To\n    create a non-sparse file of zeroes, use \"fallocate64\" instead.\n\n",
  .run = run_truncate_size
};

struct command_entry utimens_cmd_entry = {
  .name = "utimens",
  .help = "NAME\n    utimens - set timestamp of a file with nanosecond precision\n\nSYNOPSIS\n     utimens path atsecs atnsecs mtsecs mtnsecs\n\nDESCRIPTION\n    This command sets the timestamps of a file with nanosecond precision.\n\n    \"atsecs, atnsecs\" are the last access time (atime) in secs and\n    nanoseconds from the epoch.\n\n    \"mtsecs, mtnsecs\" are the last modification time (mtime) in secs and\n    nanoseconds from the epoch.\n\n    If the *nsecs field contains the special value -1 then the corresponding\n    timestamp is set to the current time. (The *secs field is ignored in\n    this case).\n\n    If the *nsecs field contains the special value -2 then the corresponding\n    timestamp is left unchanged. (The *secs field is ignored in this case).\n\n",
  .run = run_utimens
};

struct command_entry mkdir_mode_cmd_entry = {
  .name = "mkdir-mode",
  .help = "NAME\n    mkdir-mode - create a directory with a particular mode\n\nSYNOPSIS\n     mkdir-mode path mode\n\nDESCRIPTION\n    This command creates a directory, setting the initial permissions of the\n    directory to \"mode\".\n\n    For common Linux filesystems, the actual mode which is set will be \"mode\n    & ~umask & 01777\". Non-native-Linux filesystems may interpret the mode\n    in other ways.\n\n    See also \"mkdir\", \"umask\"\n\n",
  .run = run_mkdir_mode
};

struct command_entry lchown_cmd_entry = {
  .name = "lchown",
  .help = "NAME\n    lchown - change file owner and group\n\nSYNOPSIS\n     lchown owner group path\n\nDESCRIPTION\n    Change the file owner to \"owner\" and group to \"group\". This is like\n    \"chown\" but if \"path\" is a symlink then the link itself is changed, not\n    the target.\n\n    Only numeric uid and gid are supported. If you want to use names, you\n    will need to locate and parse the password file yourself (Augeas support\n    makes this relatively easy).\n\n",
  .run = run_lchown
};

struct command_entry lstatlist_cmd_entry = {
  .name = "lstatlist",
  .help = "NAME\n    lstatlist - lstat on multiple files\n\nSYNOPSIS\n     lstatlist path names\n\nDESCRIPTION\n    This call allows you to perform the \"lstat\" operation on multiple files,\n    where all files are in the directory \"path\". \"names\" is the list of\n    files from this directory.\n\n    On return you get a list of stat structs, with a one-to-one\n    correspondence to the \"names\" list. If any name did not exist or could\n    not be lstat'd, then the \"ino\" field of that structure is set to -1.\n\n    This call is intended for programs that want to efficiently list a\n    directory contents without making many round-trips. See also\n    \"lxattrlist\" for a similarly efficient call for getting extended\n    attributes. Very long directory listings might cause the protocol\n    message size to be exceeded, causing this call to fail. The caller must\n    split up such requests into smaller groups of names.\n\n",
  .run = run_lstatlist
};

struct command_entry lxattrlist_cmd_entry = {
  .name = "lxattrlist",
  .help = "NAME\n    lxattrlist - lgetxattr on multiple files\n\nSYNOPSIS\n     lxattrlist path names\n\nDESCRIPTION\n    This call allows you to get the extended attributes of multiple files,\n    where all files are in the directory \"path\". \"names\" is the list of\n    files from this directory.\n\n    On return you get a flat list of xattr structs which must be interpreted\n    sequentially. The first xattr struct always has a zero-length\n    \"attrname\". \"attrval\" in this struct is zero-length to indicate there\n    was an error doing \"lgetxattr\" for this file, *or* is a C string which\n    is a decimal number (the number of following attributes for this file,\n    which could be \"0\"). Then after the first xattr struct are the zero or\n    more attributes for the first named file. This repeats for the second\n    and subsequent files.\n\n    This call is intended for programs that want to efficiently list a\n    directory contents without making many round-trips. See also \"lstatlist\"\n    for a similarly efficient call for getting standard stats. Very long\n    directory listings might cause the protocol message size to be exceeded,\n    causing this call to fail. The caller must split up such requests into\n    smaller groups of names.\n\n",
  .run = run_lxattrlist
};

struct command_entry readlinklist_cmd_entry = {
  .name = "readlinklist",
  .help = "NAME\n    readlinklist - readlink on multiple files\n\nSYNOPSIS\n     readlinklist path names\n\nDESCRIPTION\n    This call allows you to do a \"readlink\" operation on multiple files,\n    where all files are in the directory \"path\". \"names\" is the list of\n    files from this directory.\n\n    On return you get a list of strings, with a one-to-one correspondence to\n    the \"names\" list. Each string is the value of the symbolic link.\n\n    If the readlink(2) operation fails on any name, then the corresponding\n    result string is the empty string \"\". However the whole operation is\n    completed even if there were readlink(2) errors, and so you can call\n    this function with names where you don't know if they are symbolic links\n    already (albeit slightly less efficient).\n\n    This call is intended for programs that want to efficiently list a\n    directory contents without making many round-trips. Very long directory\n    listings might cause the protocol message size to be exceeded, causing\n    this call to fail. The caller must split up such requests into smaller\n    groups of names.\n\n",
  .run = run_readlinklist
};

struct command_entry pread_cmd_entry = {
  .name = "pread",
  .help = "NAME\n    pread - read part of a file\n\nSYNOPSIS\n     pread path count offset\n\nDESCRIPTION\n    This command lets you read part of a file. It reads \"count\" bytes of the\n    file, starting at \"offset\", from file \"path\".\n\n    This may read fewer bytes than requested. For further details see the\n    pread(2) system call.\n\n    See also \"pwrite\", \"pread_device\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_pread
};

struct command_entry part_init_cmd_entry = {
  .name = "part-init",
  .help = "NAME\n    part-init - create an empty partition table\n\nSYNOPSIS\n     part-init device parttype\n\nDESCRIPTION\n    This creates an empty partition table on \"device\" of one of the\n    partition types listed below. Usually \"parttype\" should be either\n    \"msdos\" or \"gpt\" (for large disks).\n\n    Initially there are no partitions. Following this, you should call\n    \"part_add\" for each partition required.\n\n    Possible values for \"parttype\" are:\n\n    efi\n    gpt Intel EFI / GPT partition table.\n\n        This is recommended for >= 2 TB partitions that will be accessed\n        from Linux and Intel-based Mac OS X. It also has limited backwards\n        compatibility with the \"mbr\" format.\n\n    mbr\n    msdos\n        The standard PC \"Master Boot Record\" (MBR) format used by MS-DOS and\n        Windows. This partition type will only work for device sizes up to 2\n        TB. For large disks we recommend using \"gpt\".\n\n    Other partition table types that may work but are not supported include:\n\n    aix AIX disk labels.\n\n    amiga\n    rdb Amiga \"Rigid Disk Block\" format.\n\n    bsd BSD disk labels.\n\n    dasd\n        DASD, used on IBM mainframes.\n\n    dvh MIPS/SGI volumes.\n\n    mac Old Mac partition format. Modern Macs use \"gpt\".\n\n    pc98\n        NEC PC-98 format, common in Japan apparently.\n\n    sun Sun disk labels.\n\n",
  .run = run_part_init
};

struct command_entry part_add_cmd_entry = {
  .name = "part-add",
  .help = "NAME\n    part-add - add a partition to the device\n\nSYNOPSIS\n     part-add device prlogex startsect endsect\n\nDESCRIPTION\n    This command adds a partition to \"device\". If there is no partition\n    table on the device, call \"part_init\" first.\n\n    The \"prlogex\" parameter is the type of partition. Normally you should\n    pass \"p\" or \"primary\" here, but MBR partition tables also support \"l\"\n    (or \"logical\") and \"e\" (or \"extended\") partition types.\n\n    \"startsect\" and \"endsect\" are the start and end of the partition in\n    *sectors*. \"endsect\" may be negative, which means it counts backwards\n    from the end of the disk (-1 is the last sector).\n\n    Creating a partition which covers the whole disk is not so easy. Use\n    \"part_disk\" to do that.\n\n",
  .run = run_part_add
};

struct command_entry part_disk_cmd_entry = {
  .name = "part-disk",
  .help = "NAME\n    part-disk - partition whole disk with a single primary partition\n\nSYNOPSIS\n     part-disk device parttype\n\nDESCRIPTION\n    This command is simply a combination of \"part_init\" followed by\n    \"part_add\" to create a single primary partition covering the whole disk.\n\n    \"parttype\" is the partition table type, usually \"mbr\" or \"gpt\", but\n    other possible values are described in \"part_init\".\n\n",
  .run = run_part_disk
};

struct command_entry part_set_bootable_cmd_entry = {
  .name = "part-set-bootable",
  .help = "NAME\n    part-set-bootable - make a partition bootable\n\nSYNOPSIS\n     part-set-bootable device partnum bootable\n\nDESCRIPTION\n    This sets the bootable flag on partition numbered \"partnum\" on device\n    \"device\". Note that partitions are numbered from 1.\n\n    The bootable flag is used by some operating systems (notably Windows) to\n    determine which partition to boot from. It is by no means universally\n    recognized.\n\n",
  .run = run_part_set_bootable
};

struct command_entry part_set_name_cmd_entry = {
  .name = "part-set-name",
  .help = "NAME\n    part-set-name - set partition name\n\nSYNOPSIS\n     part-set-name device partnum name\n\nDESCRIPTION\n    This sets the partition name on partition numbered \"partnum\" on device\n    \"device\". Note that partitions are numbered from 1.\n\n    The partition name can only be set on certain types of partition table.\n    This works on \"gpt\" but not on \"mbr\" partitions.\n\n",
  .run = run_part_set_name
};

struct command_entry part_list_cmd_entry = {
  .name = "part-list",
  .help = "NAME\n    part-list - list partitions on a device\n\nSYNOPSIS\n     part-list device\n\nDESCRIPTION\n    This command parses the partition table on \"device\" and returns the list\n    of partitions found.\n\n    The fields in the returned structure are:\n\n    part_num\n        Partition number, counting from 1.\n\n    part_start\n        Start of the partition *in bytes*. To get sectors you have to divide\n        by the device's sector size, see \"blockdev_getss\".\n\n    part_end\n        End of the partition in bytes.\n\n    part_size\n        Size of the partition in bytes.\n\n",
  .run = run_part_list
};

struct command_entry part_get_parttype_cmd_entry = {
  .name = "part-get-parttype",
  .help = "NAME\n    part-get-parttype - get the partition table type\n\nSYNOPSIS\n     part-get-parttype device\n\nDESCRIPTION\n    This command examines the partition table on \"device\" and returns the\n    partition table type (format) being used.\n\n    Common return values include: \"msdos\" (a DOS/Windows style MBR partition\n    table), \"gpt\" (a GPT/EFI-style partition table). Other values are\n    possible, although unusual. See \"part_init\" for a full list.\n\n",
  .run = run_part_get_parttype
};

struct command_entry fill_cmd_entry = {
  .name = "fill",
  .help = "NAME\n    fill - fill a file with octets\n\nSYNOPSIS\n     fill c len path\n\nDESCRIPTION\n    This command creates a new file called \"path\". The initial content of\n    the file is \"len\" octets of \"c\", where \"c\" must be a number in the range\n    \"[0..255]\".\n\n    To fill a file with zero bytes (sparsely), it is much more efficient to\n    use \"truncate_size\". To create a file with a pattern of repeating bytes\n    use \"fill_pattern\".\n\n",
  .run = run_fill
};

struct command_entry available_cmd_entry = {
  .name = "available",
  .help = "NAME\n    available - test availability of some parts of the API\n\nSYNOPSIS\n     available groups\n\nDESCRIPTION\n    This command is used to check the availability of some groups of\n    functionality in the appliance, which not all builds of the libguestfs\n    appliance will be able to provide.\n\n    The libguestfs groups, and the functions that those groups correspond\n    to, are listed in \"AVAILABILITY\" in guestfs(3). You can also fetch this\n    list at runtime by calling \"available_all_groups\".\n\n    The argument \"groups\" is a list of group names, eg: \"[\"inotify\",\n    \"augeas\"]\" would check for the availability of the Linux inotify\n    functions and Augeas (configuration file editing) functions.\n\n    The command returns no error if *all* requested groups are available.\n\n    It fails with an error if one or more of the requested groups is\n    unavailable in the appliance.\n\n    If an unknown group name is included in the list of groups then an error\n    is always returned.\n\n    *Notes:*\n\n    *   You must call \"launch\" before calling this function.\n\n        The reason is because we don't know what groups are supported by the\n        appliance/daemon until it is running and can be queried.\n\n    *   If a group of functions is available, this does not necessarily mean\n        that they will work. You still have to check for errors when calling\n        individual API functions even if they are available.\n\n    *   It is usually the job of distro packagers to build complete\n        functionality into the libguestfs appliance. Upstream libguestfs, if\n        built from source with all requirements satisfied, will support\n        everything.\n\n    *   This call was added in version 1.0.80. In previous versions of\n        libguestfs all you could do would be to speculatively execute a\n        command to find out if the daemon implemented it. See also\n        \"version\".\n\n",
  .run = run_available
};

struct command_entry dd_cmd_entry = {
  .name = "dd",
  .help = "NAME\n    dd - copy from source to destination using dd\n\nSYNOPSIS\n     dd src dest\n\nDESCRIPTION\n    This command copies from one source device or file \"src\" to another\n    destination device or file \"dest\". Normally you would use this to copy\n    to or from a device or partition, for example to duplicate a filesystem.\n\n    If the destination is a device, it must be as large or larger than the\n    source file or device, otherwise the copy will fail. This command cannot\n    do partial copies (see \"copy_device_to_device\").\n\n    *This function is deprecated.* In new code, use the\n    \"copy_device_to_device\" call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_dd
};

struct command_entry filesize_cmd_entry = {
  .name = "filesize",
  .help = "NAME\n    filesize - return the size of the file in bytes\n\nSYNOPSIS\n     filesize file\n\nDESCRIPTION\n    This command returns the size of \"file\" in bytes.\n\n    To get other stats about a file, use \"stat\", \"lstat\", \"is_dir\",\n    \"is_file\" etc. To get the size of block devices, use\n    \"blockdev_getsize64\".\n\n",
  .run = run_filesize
};

struct command_entry lvrename_cmd_entry = {
  .name = "lvrename",
  .help = "NAME\n    lvrename - rename an LVM logical volume\n\nSYNOPSIS\n     lvrename logvol newlogvol\n\nDESCRIPTION\n    Rename a logical volume \"logvol\" with the new name \"newlogvol\".\n\n",
  .run = run_lvrename
};

struct command_entry vgrename_cmd_entry = {
  .name = "vgrename",
  .help = "NAME\n    vgrename - rename an LVM volume group\n\nSYNOPSIS\n     vgrename volgroup newvolgroup\n\nDESCRIPTION\n    Rename a volume group \"volgroup\" with the new name \"newvolgroup\".\n\n",
  .run = run_vgrename
};

struct command_entry initrd_cat_cmd_entry = {
  .name = "initrd-cat",
  .help = "NAME\n    initrd-cat - list the contents of a single file in an initrd\n\nSYNOPSIS\n     initrd-cat initrdpath filename\n\nDESCRIPTION\n    This command unpacks the file \"filename\" from the initrd file called\n    \"initrdpath\". The filename must be given *without* the initial \"/\"\n    character.\n\n    For example, in guestfish you could use the following command to examine\n    the boot script (usually called \"/init\") contained in a Linux initrd or\n    initramfs image:\n\n     initrd-cat /boot/initrd-<version>.img init\n\n    See also \"initrd_list\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_initrd_cat
};

struct command_entry pvuuid_cmd_entry = {
  .name = "pvuuid",
  .help = "NAME\n    pvuuid - get the UUID of a physical volume\n\nSYNOPSIS\n     pvuuid device\n\nDESCRIPTION\n    This command returns the UUID of the LVM PV \"device\".\n\n",
  .run = run_pvuuid
};

struct command_entry vguuid_cmd_entry = {
  .name = "vguuid",
  .help = "NAME\n    vguuid - get the UUID of a volume group\n\nSYNOPSIS\n     vguuid vgname\n\nDESCRIPTION\n    This command returns the UUID of the LVM VG named \"vgname\".\n\n",
  .run = run_vguuid
};

struct command_entry lvuuid_cmd_entry = {
  .name = "lvuuid",
  .help = "NAME\n    lvuuid - get the UUID of a logical volume\n\nSYNOPSIS\n     lvuuid device\n\nDESCRIPTION\n    This command returns the UUID of the LVM LV \"device\".\n\n",
  .run = run_lvuuid
};

struct command_entry vgpvuuids_cmd_entry = {
  .name = "vgpvuuids",
  .help = "NAME\n    vgpvuuids - get the PV UUIDs containing the volume group\n\nSYNOPSIS\n     vgpvuuids vgname\n\nDESCRIPTION\n    Given a VG called \"vgname\", this returns the UUIDs of all the physical\n    volumes that this volume group resides on.\n\n    You can use this along with \"pvs\" and \"pvuuid\" calls to associate\n    physical volumes and volume groups.\n\n    See also \"vglvuuids\".\n\n",
  .run = run_vgpvuuids
};

struct command_entry vglvuuids_cmd_entry = {
  .name = "vglvuuids",
  .help = "NAME\n    vglvuuids - get the LV UUIDs of all LVs in the volume group\n\nSYNOPSIS\n     vglvuuids vgname\n\nDESCRIPTION\n    Given a VG called \"vgname\", this returns the UUIDs of all the logical\n    volumes created in this volume group.\n\n    You can use this along with \"lvs\" and \"lvuuid\" calls to associate\n    logical volumes and volume groups.\n\n    See also \"vgpvuuids\".\n\n",
  .run = run_vglvuuids
};

struct command_entry copy_size_cmd_entry = {
  .name = "copy-size",
  .help = "NAME\n    copy-size - copy size bytes from source to destination using dd\n\nSYNOPSIS\n     copy-size src dest size\n\nDESCRIPTION\n    This command copies exactly \"size\" bytes from one source device or file\n    \"src\" to another destination device or file \"dest\".\n\n    Note this will fail if the source is too short or if the destination is\n    not large enough.\n\n    *This function is deprecated.* In new code, use the\n    \"copy_device_to_device\" call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_copy_size
};

struct command_entry zero_device_cmd_entry = {
  .name = "zero-device",
  .help = "NAME\n    zero-device - write zeroes to an entire device\n\nSYNOPSIS\n     zero-device device\n\nDESCRIPTION\n    This command writes zeroes over the entire \"device\". Compare with \"zero\"\n    which just zeroes the first few blocks of a device.\n\n    If blocks are already zero, then this command avoids writing zeroes.\n    This prevents the underlying device from becoming non-sparse or growing\n    unnecessarily.\n\n",
  .run = run_zero_device
};

struct command_entry txz_in_cmd_entry = {
  .name = "txz-in",
  .help = "NAME\n    txz-in - unpack compressed tarball to directory\n\nSYNOPSIS\n     txz-in tarball directory\n\nDESCRIPTION\n    This command uploads and unpacks local file \"tarball\" (an *xz\n    compressed* tar file) into \"directory\".\n\n",
  .run = run_txz_in
};

struct command_entry txz_out_cmd_entry = {
  .name = "txz-out",
  .help = "NAME\n    txz-out - pack directory into compressed tarball\n\nSYNOPSIS\n     txz-out directory tarball\n\nDESCRIPTION\n    This command packs the contents of \"directory\" and downloads it to local\n    file \"tarball\" (as an xz compressed tar archive).\n\n",
  .run = run_txz_out
};

struct command_entry ntfsresize_cmd_entry = {
  .name = "ntfsresize",
  .help = "NAME\n    ntfsresize - resize an NTFS filesystem\n\nSYNOPSIS\n     ntfsresize device\n\nDESCRIPTION\n    This command resizes an NTFS filesystem, expanding or shrinking it to\n    the size of the underlying device.\n\n    *Note:* After the resize operation, the filesystem is marked as\n    requiring a consistency check (for safety). You have to boot into\n    Windows to perform this check and clear this condition. Furthermore,\n    ntfsresize refuses to resize filesystems which have been marked in this\n    way. So in effect it is not possible to call ntfsresize multiple times\n    on a single filesystem without booting into Windows between each resize.\n\n    See also ntfsresize(8).\n\n    *This function is deprecated.* In new code, use the \"ntfsresize_opts\"\n    call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_ntfsresize
};

struct command_entry vgscan_cmd_entry = {
  .name = "vgscan",
  .help = "NAME\n    vgscan - rescan for LVM physical volumes, volume groups and logical\n    volumes\n\nSYNOPSIS\n     vgscan\n\nDESCRIPTION\n    This rescans all block devices and rebuilds the list of LVM physical\n    volumes, volume groups and logical volumes.\n\n",
  .run = run_vgscan
};

struct command_entry part_del_cmd_entry = {
  .name = "part-del",
  .help = "NAME\n    part-del - delete a partition\n\nSYNOPSIS\n     part-del device partnum\n\nDESCRIPTION\n    This command deletes the partition numbered \"partnum\" on \"device\".\n\n    Note that in the case of MBR partitioning, deleting an extended\n    partition also deletes any logical partitions it contains.\n\n",
  .run = run_part_del
};

struct command_entry part_get_bootable_cmd_entry = {
  .name = "part-get-bootable",
  .help = "NAME\n    part-get-bootable - return true if a partition is bootable\n\nSYNOPSIS\n     part-get-bootable device partnum\n\nDESCRIPTION\n    This command returns true if the partition \"partnum\" on \"device\" has the\n    bootable flag set.\n\n    See also \"part_set_bootable\".\n\n",
  .run = run_part_get_bootable
};

struct command_entry part_get_mbr_id_cmd_entry = {
  .name = "part-get-mbr-id",
  .help = "NAME\n    part-get-mbr-id - get the MBR type byte (ID byte) from a partition\n\nSYNOPSIS\n     part-get-mbr-id device partnum\n\nDESCRIPTION\n    Returns the MBR type byte (also known as the ID byte) from the numbered\n    partition \"partnum\".\n\n    Note that only MBR (old DOS-style) partitions have type bytes. You will\n    get undefined results for other partition table types (see\n    \"part_get_parttype\").\n\n",
  .run = run_part_get_mbr_id
};

struct command_entry part_set_mbr_id_cmd_entry = {
  .name = "part-set-mbr-id",
  .help = "NAME\n    part-set-mbr-id - set the MBR type byte (ID byte) of a partition\n\nSYNOPSIS\n     part-set-mbr-id device partnum idbyte\n\nDESCRIPTION\n    Sets the MBR type byte (also known as the ID byte) of the numbered\n    partition \"partnum\" to \"idbyte\". Note that the type bytes quoted in most\n    documentation are in fact hexadecimal numbers, but usually documented\n    without any leading \"0x\" which might be confusing.\n\n    Note that only MBR (old DOS-style) partitions have type bytes. You will\n    get undefined results for other partition table types (see\n    \"part_get_parttype\").\n\n",
  .run = run_part_set_mbr_id
};

struct command_entry checksum_device_cmd_entry = {
  .name = "checksum-device",
  .help = "NAME\n    checksum-device - compute MD5, SHAx or CRC checksum of the contents of a\n    device\n\nSYNOPSIS\n     checksum-device csumtype device\n\nDESCRIPTION\n    This call computes the MD5, SHAx or CRC checksum of the contents of the\n    device named \"device\". For the types of checksums supported see the\n    \"checksum\" command.\n\n",
  .run = run_checksum_device
};

struct command_entry lvresize_free_cmd_entry = {
  .name = "lvresize-free",
  .help = "NAME\n    lvresize-free - expand an LV to fill free space\n\nSYNOPSIS\n     lvresize-free lv percent\n\nDESCRIPTION\n    This expands an existing logical volume \"lv\" so that it fills \"pc\"% of\n    the remaining free space in the volume group. Commonly you would call\n    this with pc = 100 which expands the logical volume as much as possible,\n    using all remaining free space in the volume group.\n\n",
  .run = run_lvresize_free
};

struct command_entry aug_clear_cmd_entry = {
  .name = "aug-clear",
  .help = "NAME\n    aug-clear - clear Augeas path\n\nSYNOPSIS\n     aug-clear augpath\n\nDESCRIPTION\n    Set the value associated with \"path\" to \"NULL\". This is the same as the\n    augtool(1) \"clear\" command.\n\n",
  .run = run_aug_clear
};

struct command_entry get_umask_cmd_entry = {
  .name = "get-umask",
  .help = "NAME\n    get-umask - get the current umask\n\nSYNOPSIS\n     get-umask\n\nDESCRIPTION\n    Return the current umask. By default the umask is 022 unless it has been\n    set by calling \"umask\".\n\n",
  .run = run_get_umask
};

struct command_entry debug_upload_cmd_entry = {
  .name = "debug-upload",
  .help = "NAME\n    debug-upload - upload a file to the appliance (internal use only)\n\nSYNOPSIS\n     debug-upload filename tmpname mode\n\nDESCRIPTION\n    The \"debug_upload\" command uploads a file to the libguestfs appliance.\n\n    There is no comprehensive help for this command. You have to look at the\n    file \"daemon/debug.c\" in the libguestfs source to find out what it is\n    for.\n\n",
  .run = run_debug_upload
};

struct command_entry base64_in_cmd_entry = {
  .name = "base64-in",
  .help = "NAME\n    base64-in - upload base64-encoded data to file\n\nSYNOPSIS\n     base64-in base64file filename\n\nDESCRIPTION\n    This command uploads base64-encoded data from \"base64file\" to\n    \"filename\".\n\n",
  .run = run_base64_in
};

struct command_entry base64_out_cmd_entry = {
  .name = "base64-out",
  .help = "NAME\n    base64-out - download file and encode as base64\n\nSYNOPSIS\n     base64-out filename base64file\n\nDESCRIPTION\n    This command downloads the contents of \"filename\", writing it out to\n    local file \"base64file\" encoded as base64.\n\n",
  .run = run_base64_out
};

struct command_entry checksums_out_cmd_entry = {
  .name = "checksums-out",
  .help = "NAME\n    checksums-out - compute MD5, SHAx or CRC checksum of files in a\n    directory\n\nSYNOPSIS\n     checksums-out csumtype directory sumsfile\n\nDESCRIPTION\n    This command computes the checksums of all regular files in \"directory\"\n    and then emits a list of those checksums to the local output file\n    \"sumsfile\".\n\n    This can be used for verifying the integrity of a virtual machine.\n    However to be properly secure you should pay attention to the output of\n    the checksum command (it uses the ones from GNU coreutils). In\n    particular when the filename is not printable, coreutils uses a special\n    backslash syntax. For more information, see the GNU coreutils info file.\n\n",
  .run = run_checksums_out
};

struct command_entry fill_pattern_cmd_entry = {
  .name = "fill-pattern",
  .help = "NAME\n    fill-pattern - fill a file with a repeating pattern of bytes\n\nSYNOPSIS\n     fill-pattern pattern len path\n\nDESCRIPTION\n    This function is like \"fill\" except that it creates a new file of length\n    \"len\" containing the repeating pattern of bytes in \"pattern\". The\n    pattern is truncated if necessary to ensure the length of the file is\n    exactly \"len\" bytes.\n\n",
  .run = run_fill_pattern
};

struct command_entry write_cmd_entry = {
  .name = "write",
  .help = "NAME\n    write - create a new file\n\nSYNOPSIS\n     write path content\n\nDESCRIPTION\n    This call creates a file called \"path\". The content of the file is the\n    string \"content\" (which can contain any 8 bit data).\n\n    See also \"write_append\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_write
};

struct command_entry pwrite_cmd_entry = {
  .name = "pwrite",
  .help = "NAME\n    pwrite - write to part of a file\n\nSYNOPSIS\n     pwrite path content offset\n\nDESCRIPTION\n    This command writes to part of a file. It writes the data buffer\n    \"content\" to the file \"path\" starting at offset \"offset\".\n\n    This command implements the pwrite(2) system call, and like that system\n    call it may not write the full data requested. The return value is the\n    number of bytes that were actually written to the file. This could even\n    be 0, although short writes are unlikely for regular files in ordinary\n    circumstances.\n\n    See also \"pread\", \"pwrite_device\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_pwrite
};

struct command_entry resize2fs_size_cmd_entry = {
  .name = "resize2fs-size",
  .help = "NAME\n    resize2fs-size - resize an ext2, ext3 or ext4 filesystem (with size)\n\nSYNOPSIS\n     resize2fs-size device size\n\nDESCRIPTION\n    This command is the same as \"resize2fs\" except that it allows you to\n    specify the new size (in bytes) explicitly.\n\n",
  .run = run_resize2fs_size
};

struct command_entry pvresize_size_cmd_entry = {
  .name = "pvresize-size",
  .help = "NAME\n    pvresize-size - resize an LVM physical volume (with size)\n\nSYNOPSIS\n     pvresize-size device size\n\nDESCRIPTION\n    This command is the same as \"pvresize\" except that it allows you to\n    specify the new size (in bytes) explicitly.\n\n",
  .run = run_pvresize_size
};

struct command_entry ntfsresize_size_cmd_entry = {
  .name = "ntfsresize-size",
  .help = "NAME\n    ntfsresize-size - resize an NTFS filesystem (with size)\n\nSYNOPSIS\n     ntfsresize-size device size\n\nDESCRIPTION\n    This command is the same as \"ntfsresize\" except that it allows you to\n    specify the new size (in bytes) explicitly.\n\n    *This function is deprecated.* In new code, use the \"ntfsresize_opts\"\n    call instead.\n\n    Deprecated functions will not be removed from the API, but the fact that\n    they are deprecated indicates that there are problems with correct use\n    of these functions.\n\n",
  .run = run_ntfsresize_size
};

struct command_entry available_all_groups_cmd_entry = {
  .name = "available-all-groups",
  .help = "NAME\n    available-all-groups - return a list of all optional groups\n\nSYNOPSIS\n     available-all-groups\n\nDESCRIPTION\n    This command returns a list of all optional groups that this daemon\n    knows about. Note this returns both supported and unsupported groups. To\n    find out which ones the daemon can actually support you have to call\n    \"available\" on each member of the returned list.\n\n    See also \"available\" and \"AVAILABILITY\" in guestfs(3).\n\n",
  .run = run_available_all_groups
};

struct command_entry fallocate64_cmd_entry = {
  .name = "fallocate64",
  .help = "NAME\n    fallocate64 - preallocate a file in the guest filesystem\n\nSYNOPSIS\n     fallocate64 path len\n\nDESCRIPTION\n    This command preallocates a file (containing zero bytes) named \"path\" of\n    size \"len\" bytes. If the file exists already, it is overwritten.\n\n    Note that this call allocates disk blocks for the file. To create a\n    sparse file use \"truncate_size\" instead.\n\n    The deprecated call \"fallocate\" does the same, but owing to an oversight\n    it only allowed 30 bit lengths to be specified, effectively limiting the\n    maximum size of files created through that call to 1GB.\n\n    Do not confuse this with the guestfish-specific \"alloc\" and \"sparse\"\n    commands which create a file in the host and attach it as a device.\n\n",
  .run = run_fallocate64
};

struct command_entry vfs_label_cmd_entry = {
  .name = "vfs-label",
  .help = "NAME\n    vfs-label - get the filesystem label\n\nSYNOPSIS\n     vfs-label device\n\nDESCRIPTION\n    This returns the filesystem label of the filesystem on \"device\".\n\n    If the filesystem is unlabeled, this returns the empty string.\n\n    To find a filesystem from the label, use \"findfs_label\".\n\n",
  .run = run_vfs_label
};

struct command_entry vfs_uuid_cmd_entry = {
  .name = "vfs-uuid",
  .help = "NAME\n    vfs-uuid - get the filesystem UUID\n\nSYNOPSIS\n     vfs-uuid device\n\nDESCRIPTION\n    This returns the filesystem UUID of the filesystem on \"device\".\n\n    If the filesystem does not have a UUID, this returns the empty string.\n\n    To find a filesystem from the UUID, use \"findfs_uuid\".\n\n",
  .run = run_vfs_uuid
};

struct command_entry lvm_set_filter_cmd_entry = {
  .name = "lvm-set-filter",
  .help = "NAME\n    lvm-set-filter - set LVM device filter\n\nSYNOPSIS\n     lvm-set-filter devices\n\nDESCRIPTION\n    This sets the LVM device filter so that LVM will only be able to \"see\"\n    the block devices in the list \"devices\", and will ignore all other\n    attached block devices.\n\n    Where disk image(s) contain duplicate PVs or VGs, this command is useful\n    to get LVM to ignore the duplicates, otherwise LVM can get confused.\n    Note also there are two types of duplication possible: either cloned\n    PVs/VGs which have identical UUIDs; or VGs that are not cloned but just\n    happen to have the same name. In normal operation you cannot create this\n    situation, but you can do it outside LVM, eg. by cloning disk images or\n    by bit twiddling inside the LVM metadata.\n\n    This command also clears the LVM cache and performs a volume group scan.\n\n    You can filter whole block devices or individual partitions.\n\n    You cannot use this if any VG is currently in use (eg. contains a\n    mounted filesystem), even if you are not filtering out that VG.\n\n",
  .run = run_lvm_set_filter
};

struct command_entry lvm_clear_filter_cmd_entry = {
  .name = "lvm-clear-filter",
  .help = "NAME\n    lvm-clear-filter - clear LVM device filter\n\nSYNOPSIS\n     lvm-clear-filter\n\nDESCRIPTION\n    This undoes the effect of \"lvm_set_filter\". LVM will be able to see\n    every block device.\n\n    This command also clears the LVM cache and performs a volume group scan.\n\n",
  .run = run_lvm_clear_filter
};

struct command_entry luks_open_cmd_entry = {
  .name = "luks-open",
  .help = "NAME\n    luks-open - open a LUKS-encrypted block device\n\nSYNOPSIS\n     luks-open device mapname\n\nDESCRIPTION\n    This command opens a block device which has been encrypted according to\n    the Linux Unified Key Setup (LUKS) standard.\n\n    \"device\" is the encrypted block device or partition.\n\n    The caller must supply one of the keys associated with the LUKS block\n    device, in the \"key\" parameter.\n\n    This creates a new block device called \"/dev/mapper/mapname\". Reads and\n    writes to this block device are decrypted from and encrypted to the\n    underlying \"device\" respectively.\n\n    If this block device contains LVM volume groups, then calling \"vgscan\"\n    followed by \"vg_activate_all\" will make them visible.\n\n    Use \"list_dm_devices\" to list all device mapper devices.\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_open
};

struct command_entry luks_open_ro_cmd_entry = {
  .name = "luks-open-ro",
  .help = "NAME\n    luks-open-ro - open a LUKS-encrypted block device read-only\n\nSYNOPSIS\n     luks-open-ro device mapname\n\nDESCRIPTION\n    This is the same as \"luks_open\" except that a read-only mapping is\n    created.\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_open_ro
};

struct command_entry luks_close_cmd_entry = {
  .name = "luks-close",
  .help = "NAME\n    luks-close - close a LUKS device\n\nSYNOPSIS\n     luks-close device\n\nDESCRIPTION\n    This closes a LUKS device that was created earlier by \"luks_open\" or\n    \"luks_open_ro\". The \"device\" parameter must be the name of the LUKS\n    mapping device (ie. \"/dev/mapper/mapname\") and *not* the name of the\n    underlying block device.\n\n",
  .run = run_luks_close
};

struct command_entry luks_format_cmd_entry = {
  .name = "luks-format",
  .help = "NAME\n    luks-format - format a block device as a LUKS encrypted device\n\nSYNOPSIS\n     luks-format device keyslot\n\nDESCRIPTION\n    This command erases existing data on \"device\" and formats the device as\n    a LUKS encrypted device. \"key\" is the initial key, which is added to key\n    slot \"slot\". (LUKS supports 8 key slots, numbered 0-7).\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_format
};

struct command_entry luks_format_cipher_cmd_entry = {
  .name = "luks-format-cipher",
  .help = "NAME\n    luks-format-cipher - format a block device as a LUKS encrypted device\n\nSYNOPSIS\n     luks-format-cipher device keyslot cipher\n\nDESCRIPTION\n    This command is the same as \"luks_format\" but it also allows you to set\n    the \"cipher\" used.\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_format_cipher
};

struct command_entry luks_add_key_cmd_entry = {
  .name = "luks-add-key",
  .help = "NAME\n    luks-add-key - add a key on a LUKS encrypted device\n\nSYNOPSIS\n     luks-add-key device keyslot\n\nDESCRIPTION\n    This command adds a new key on LUKS device \"device\". \"key\" is any\n    existing key, and is used to access the device. \"newkey\" is the new key\n    to add. \"keyslot\" is the key slot that will be replaced.\n\n    Note that if \"keyslot\" already contains a key, then this command will\n    fail. You have to use \"luks_kill_slot\" first to remove that key.\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_add_key
};

struct command_entry luks_kill_slot_cmd_entry = {
  .name = "luks-kill-slot",
  .help = "NAME\n    luks-kill-slot - remove a key from a LUKS encrypted device\n\nSYNOPSIS\n     luks-kill-slot device keyslot\n\nDESCRIPTION\n    This command deletes the key in key slot \"keyslot\" from the encrypted\n    LUKS device \"device\". \"key\" must be one of the *other* keys.\n\n    This command has one or more key or passphrase parameters. Guestfish\n    will prompt for these separately.\n\n",
  .run = run_luks_kill_slot
};

struct command_entry is_lv_cmd_entry = {
  .name = "is-lv",
  .help = "NAME\n    is-lv - test if device is a logical volume\n\nSYNOPSIS\n     is-lv device\n\nDESCRIPTION\n    This command tests whether \"device\" is a logical volume, and returns\n    true iff this is the case.\n\n",
  .run = run_is_lv
};

struct command_entry findfs_uuid_cmd_entry = {
  .name = "findfs-uuid",
  .help = "NAME\n    findfs-uuid - find a filesystem by UUID\n\nSYNOPSIS\n     findfs-uuid uuid\n\nDESCRIPTION\n    This command searches the filesystems and returns the one which has the\n    given UUID. An error is returned if no such filesystem can be found.\n\n    To find the UUID of a filesystem, use \"vfs_uuid\".\n\n",
  .run = run_findfs_uuid
};

struct command_entry findfs_label_cmd_entry = {
  .name = "findfs-label",
  .help = "NAME\n    findfs-label - find a filesystem by label\n\nSYNOPSIS\n     findfs-label label\n\nDESCRIPTION\n    This command searches the filesystems and returns the one which has the\n    given label. An error is returned if no such filesystem can be found.\n\n    To find the label of a filesystem, use \"vfs_label\".\n\n",
  .run = run_findfs_label
};

struct command_entry is_chardev_cmd_entry = {
  .name = "is-chardev",
  .help = "NAME\n    is-chardev - test if character device\n\nSYNOPSIS\n     is-chardev path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a character device with the\n    given \"path\" name.\n\n    See also \"stat\".\n\n",
  .run = run_is_chardev
};

struct command_entry is_blockdev_cmd_entry = {
  .name = "is-blockdev",
  .help = "NAME\n    is-blockdev - test if block device\n\nSYNOPSIS\n     is-blockdev path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a block device with the\n    given \"path\" name.\n\n    See also \"stat\".\n\n",
  .run = run_is_blockdev
};

struct command_entry is_fifo_cmd_entry = {
  .name = "is-fifo",
  .help = "NAME\n    is-fifo - test if FIFO (named pipe)\n\nSYNOPSIS\n     is-fifo path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a FIFO (named pipe) with the\n    given \"path\" name.\n\n    See also \"stat\".\n\n",
  .run = run_is_fifo
};

struct command_entry is_symlink_cmd_entry = {
  .name = "is-symlink",
  .help = "NAME\n    is-symlink - test if symbolic link\n\nSYNOPSIS\n     is-symlink path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a symbolic link with the\n    given \"path\" name.\n\n    See also \"stat\".\n\n",
  .run = run_is_symlink
};

struct command_entry is_socket_cmd_entry = {
  .name = "is-socket",
  .help = "NAME\n    is-socket - test if socket\n\nSYNOPSIS\n     is-socket path\n\nDESCRIPTION\n    This returns \"true\" if and only if there is a Unix domain socket with\n    the given \"path\" name.\n\n    See also \"stat\".\n\n",
  .run = run_is_socket
};

struct command_entry part_to_dev_cmd_entry = {
  .name = "part-to-dev",
  .help = "NAME\n    part-to-dev - convert partition name to device name\n\nSYNOPSIS\n     part-to-dev partition\n\nDESCRIPTION\n    This function takes a partition name (eg. \"/dev/sdb1\") and removes the\n    partition number, returning the device name (eg. \"/dev/sdb\").\n\n    The named partition must exist, for example as a string returned from\n    \"list_partitions\".\n\n    See also \"part_to_partnum\".\n\n",
  .run = run_part_to_dev
};

struct command_entry upload_offset_cmd_entry = {
  .name = "upload-offset",
  .help = "NAME\n    upload-offset - upload a file from the local machine with offset\n\nSYNOPSIS\n     upload-offset filename remotefilename offset\n\nDESCRIPTION\n    Upload local file \"filename\" to \"remotefilename\" on the filesystem.\n\n    \"remotefilename\" is overwritten starting at the byte \"offset\" specified.\n    The intention is to overwrite parts of existing files or devices,\n    although if a non-existant file is specified then it is created with a\n    \"hole\" before \"offset\". The size of the data written is implicit in the\n    size of the source \"filename\".\n\n    Note that there is no limit on the amount of data that can be uploaded\n    with this call, unlike with \"pwrite\", and this call always writes the\n    full amount unless an error occurs.\n\n    See also \"upload\", \"pwrite\".\n\n",
  .run = run_upload_offset
};

struct command_entry download_offset_cmd_entry = {
  .name = "download-offset",
  .help = "NAME\n    download-offset - download a file to the local machine with offset and\n    size\n\nSYNOPSIS\n     download-offset remotefilename filename offset size\n\nDESCRIPTION\n    Download file \"remotefilename\" and save it as \"filename\" on the local\n    machine.\n\n    \"remotefilename\" is read for \"size\" bytes starting at \"offset\" (this\n    region must be within the file or device).\n\n    Note that there is no limit on the amount of data that can be downloaded\n    with this call, unlike with \"pread\", and this call always reads the full\n    amount unless an error occurs.\n\n    See also \"download\", \"pread\".\n\n",
  .run = run_download_offset
};

struct command_entry pwrite_device_cmd_entry = {
  .name = "pwrite-device",
  .help = "NAME\n    pwrite-device - write to part of a device\n\nSYNOPSIS\n     pwrite-device device content offset\n\nDESCRIPTION\n    This command writes to part of a device. It writes the data buffer\n    \"content\" to \"device\" starting at offset \"offset\".\n\n    This command implements the pwrite(2) system call, and like that system\n    call it may not write the full data requested (although short writes to\n    disk devices and partitions are probably impossible with standard Linux\n    kernels).\n\n    See also \"pwrite\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_pwrite_device
};

struct command_entry pread_device_cmd_entry = {
  .name = "pread-device",
  .help = "NAME\n    pread-device - read part of a device\n\nSYNOPSIS\n     pread-device device count offset\n\nDESCRIPTION\n    This command lets you read part of a file. It reads \"count\" bytes of\n    \"device\", starting at \"offset\".\n\n    This may read fewer bytes than requested. For further details see the\n    pread(2) system call.\n\n    See also \"pread\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_pread_device
};

struct command_entry lvm_canonical_lv_name_cmd_entry = {
  .name = "lvm-canonical-lv-name",
  .help = "NAME\n    lvm-canonical-lv-name - get canonical name of an LV\n\nSYNOPSIS\n     lvm-canonical-lv-name lvname\n\nDESCRIPTION\n    This converts alternative naming schemes for LVs that you might find to\n    the canonical name. For example, \"/dev/mapper/VG-LV\" is converted to\n    \"/dev/VG/LV\".\n\n    This command returns an error if the \"lvname\" parameter does not refer\n    to a logical volume.\n\n    See also \"is_lv\".\n\n",
  .run = run_lvm_canonical_lv_name
};

struct command_entry mkfs_opts_cmd_entry = {
  .name = "mkfs-opts",
  .help = "NAME\n    mkfs-opts - make a filesystem\n\nSYNOPSIS\n     mkfs-opts fstype device [blocksize:N] [features:..] [inode:N] [sectorsize:N]\n\nDESCRIPTION\n    This function creates a filesystem on \"device\". The filesystem type is\n    \"fstype\", for example \"ext3\".\n\n    The optional arguments are:\n\n    \"blocksize\"\n        The filesystem block size. Supported block sizes depend on the\n        filesystem type, but typically they are 1024, 2048 or 4096 for Linux\n        ext2/3 filesystems.\n\n        For VFAT and NTFS the \"blocksize\" parameter is treated as the\n        requested cluster size.\n\n        For UFS block sizes, please see mkfs.ufs(8).\n\n    \"features\"\n        This passes the *-O* parameter to the external mkfs program.\n\n        For certain filesystem types, this allows extra filesystem features\n        to be selected. See mke2fs(8) and mkfs.ufs(8) for more details.\n\n        You cannot use this optional parameter with the \"gfs\" or \"gfs2\"\n        filesystem type.\n\n    \"inode\"\n        This passes the *-I* parameter to the external mke2fs(8) program\n        which sets the inode size (only for ext2/3/4 filesystems at\n        present).\n\n    \"sectorsize\"\n        This passes the *-S* parameter to external mkfs.ufs(8) program,\n        which sets sector size for ufs filesystem.\n\n",
  .run = run_mkfs_opts
};

struct command_entry getxattr_cmd_entry = {
  .name = "getxattr",
  .help = "NAME\n    getxattr - get a single extended attribute\n\nSYNOPSIS\n     getxattr path name\n\nDESCRIPTION\n    Get a single extended attribute from file \"path\" named \"name\". This call\n    follows symlinks. If you want to lookup an extended attribute for the\n    symlink itself, use \"lgetxattr\".\n\n    Normally it is better to get all extended attributes from a file in one\n    go by calling \"getxattrs\". However some Linux filesystem implementations\n    are buggy and do not provide a way to list out attributes. For these\n    filesystems (notably ntfs-3g) you have to know the names of the extended\n    attributes you want in advance and call this function.\n\n    Extended attribute values are blobs of binary data. If there is no\n    extended attribute named \"name\", this returns an error.\n\n    See also: \"getxattrs\", \"lgetxattr\", attr(5).\n\n",
  .run = run_getxattr
};

struct command_entry lgetxattr_cmd_entry = {
  .name = "lgetxattr",
  .help = "NAME\n    lgetxattr - get a single extended attribute\n\nSYNOPSIS\n     lgetxattr path name\n\nDESCRIPTION\n    Get a single extended attribute from file \"path\" named \"name\". If \"path\"\n    is a symlink, then this call returns an extended attribute from the\n    symlink.\n\n    Normally it is better to get all extended attributes from a file in one\n    go by calling \"getxattrs\". However some Linux filesystem implementations\n    are buggy and do not provide a way to list out attributes. For these\n    filesystems (notably ntfs-3g) you have to know the names of the extended\n    attributes you want in advance and call this function.\n\n    Extended attribute values are blobs of binary data. If there is no\n    extended attribute named \"name\", this returns an error.\n\n    See also: \"lgetxattrs\", \"getxattr\", attr(5).\n\n",
  .run = run_lgetxattr
};

struct command_entry resize2fs_M_cmd_entry = {
  .name = "resize2fs-M",
  .help = "NAME\n    resize2fs-M - resize an ext2, ext3 or ext4 filesystem to the minimum\n    size\n\nSYNOPSIS\n     resize2fs-M device\n\nDESCRIPTION\n    This command is the same as \"resize2fs\", but the filesystem is resized\n    to its minimum size. This works like the *-M* option to the \"resize2fs\"\n    command.\n\n    To get the resulting size of the filesystem you should call \"tune2fs_l\"\n    and read the \"Block size\" and \"Block count\" values. These two numbers,\n    multiplied together, give the resulting size of the minimal filesystem\n    in bytes.\n\n",
  .run = run_resize2fs_M
};

struct command_entry is_zero_cmd_entry = {
  .name = "is-zero",
  .help = "NAME\n    is-zero - test if a file contains all zero bytes\n\nSYNOPSIS\n     is-zero path\n\nDESCRIPTION\n    This returns true iff the file exists and the file is empty or it\n    contains all zero bytes.\n\n",
  .run = run_is_zero
};

struct command_entry is_zero_device_cmd_entry = {
  .name = "is-zero-device",
  .help = "NAME\n    is-zero-device - test if a device contains all zero bytes\n\nSYNOPSIS\n     is-zero-device device\n\nDESCRIPTION\n    This returns true iff the device exists and contains all zero bytes.\n\n    Note that for large devices this can take a long time to run.\n\n",
  .run = run_is_zero_device
};

struct command_entry list_9p_cmd_entry = {
  .name = "list-9p",
  .help = "NAME\n    list-9p - list 9p filesystems\n\nSYNOPSIS\n     list-9p\n\nDESCRIPTION\n    List all 9p filesystems attached to the guest. A list of mount tags is\n    returned.\n\n",
  .run = run_list_9p
};

struct command_entry mount_9p_cmd_entry = {
  .name = "mount-9p",
  .help = "NAME\n    mount-9p - mount 9p filesystem\n\nSYNOPSIS\n     mount-9p mounttag mountpoint [options:..]\n\nDESCRIPTION\n    Mount the virtio-9p filesystem with the tag \"mounttag\" on the directory\n    \"mountpoint\".\n\n    If required, \"trans=virtio\" will be automatically added to the options.\n    Any other options required can be passed in the optional \"options\"\n    parameter.\n\n",
  .run = run_mount_9p
};

struct command_entry list_dm_devices_cmd_entry = {
  .name = "list-dm-devices",
  .help = "NAME\n    list-dm-devices - list device mapper devices\n\nSYNOPSIS\n     list-dm-devices\n\nDESCRIPTION\n    List all device mapper devices.\n\n    The returned list contains \"/dev/mapper/*\" devices, eg. ones created by\n    a previous call to \"luks_open\".\n\n    Device mapper devices which correspond to logical volumes are *not*\n    returned in this list. Call \"lvs\" if you want to list logical volumes.\n\n",
  .run = run_list_dm_devices
};

struct command_entry ntfsresize_opts_cmd_entry = {
  .name = "ntfsresize-opts",
  .help = "NAME\n    ntfsresize-opts - resize an NTFS filesystem\n\nSYNOPSIS\n     ntfsresize-opts device [size:N] [force:true|false]\n\nDESCRIPTION\n    This command resizes an NTFS filesystem, expanding or shrinking it to\n    the size of the underlying device.\n\n    The optional parameters are:\n\n    \"size\"\n        The new size (in bytes) of the filesystem. If omitted, the\n        filesystem is resized to fit the container (eg. partition).\n\n    \"force\"\n        If this option is true, then force the resize of the filesystem even\n        if the filesystem is marked as requiring a consistency check.\n\n        After the resize operation, the filesystem is always marked as\n        requiring a consistency check (for safety). You have to boot into\n        Windows to perform this check and clear this condition. If you\n        *don't* set the \"force\" option then it is not possible to call\n        \"ntfsresize_opts\" multiple times on a single filesystem without\n        booting into Windows between each resize.\n\n    See also ntfsresize(8).\n\n",
  .run = run_ntfsresize_opts
};

struct command_entry btrfs_filesystem_resize_cmd_entry = {
  .name = "btrfs-filesystem-resize",
  .help = "NAME\n    btrfs-filesystem-resize - resize a btrfs filesystem\n\nSYNOPSIS\n     btrfs-filesystem-resize mountpoint [size:N]\n\nDESCRIPTION\n    This command resizes a btrfs filesystem.\n\n    Note that unlike other resize calls, the filesystem has to be mounted\n    and the parameter is the mountpoint not the device (this is a\n    requirement of btrfs itself).\n\n    The optional parameters are:\n\n    \"size\"\n        The new size (in bytes) of the filesystem. If omitted, the\n        filesystem is resized to the maximum size.\n\n    See also btrfs(8).\n\n",
  .run = run_btrfs_filesystem_resize
};

struct command_entry write_append_cmd_entry = {
  .name = "write-append",
  .help = "NAME\n    write-append - append content to end of file\n\nSYNOPSIS\n     write-append path content\n\nDESCRIPTION\n    This call appends \"content\" to the end of file \"path\". If \"path\" does\n    not exist, then a new file is created.\n\n    See also \"write\".\n\n    Because of the message protocol, there is a transfer limit of somewhere\n    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n\n",
  .run = run_write_append
};

struct command_entry compress_out_cmd_entry = {
  .name = "compress-out",
  .help = "NAME\n    compress-out - output compressed file\n\nSYNOPSIS\n     compress-out ctype file zfile [level:N]\n\nDESCRIPTION\n    This command compresses \"file\" and writes it out to the local file\n    \"zfile\".\n\n    The compression program used is controlled by the \"ctype\" parameter.\n    Currently this includes: \"compress\", \"gzip\", \"bzip2\", \"xz\" or \"lzop\".\n    Some compression types may not be supported by particular builds of\n    libguestfs, in which case you will get an error containing the substring\n    \"not supported\".\n\n    The optional \"level\" parameter controls compression level. The meaning\n    and default for this parameter depends on the compression program being\n    used.\n\n",
  .run = run_compress_out
};

struct command_entry compress_device_out_cmd_entry = {
  .name = "compress-device-out",
  .help = "NAME\n    compress-device-out - output compressed device\n\nSYNOPSIS\n     compress-device-out ctype device zdevice [level:N]\n\nDESCRIPTION\n    This command compresses \"device\" and writes it out to the local file\n    \"zdevice\".\n\n    The \"ctype\" and optional \"level\" parameters have the same meaning as in\n    \"compress_out\".\n\n",
  .run = run_compress_device_out
};

struct command_entry part_to_partnum_cmd_entry = {
  .name = "part-to-partnum",
  .help = "NAME\n    part-to-partnum - convert partition name to partition number\n\nSYNOPSIS\n     part-to-partnum partition\n\nDESCRIPTION\n    This function takes a partition name (eg. \"/dev/sdb1\") and returns the\n    partition number (eg. 1).\n\n    The named partition must exist, for example as a string returned from\n    \"list_partitions\".\n\n    See also \"part_to_dev\".\n\n",
  .run = run_part_to_partnum
};

struct command_entry copy_device_to_device_cmd_entry = {
  .name = "copy-device-to-device",
  .help = "NAME\n    copy-device-to-device - copy from source device to destination device\n\nSYNOPSIS\n     copy-device-to-device src dest [srcoffset:N] [destoffset:N] [size:N]\n\nDESCRIPTION\n    The four calls \"copy_device_to_device\", \"copy_device_to_file\",\n    \"copy_file_to_device\", and \"copy_file_to_file\" let you copy from a\n    source (device|file) to a destination (device|file).\n\n    Partial copies can be made since you can specify optionally the source\n    offset, destination offset and size to copy. These values are all\n    specified in bytes. If not given, the offsets both default to zero, and\n    the size defaults to copying as much as possible until we hit the end of\n    the source.\n\n    The source and destination may be the same object. However overlapping\n    regions may not be copied correctly.\n\n    If the destination is a file, it is created if required. If the\n    destination file is not large enough, it is extended.\n\n",
  .run = run_copy_device_to_device
};

struct command_entry copy_device_to_file_cmd_entry = {
  .name = "copy-device-to-file",
  .help = "NAME\n    copy-device-to-file - copy from source device to destination file\n\nSYNOPSIS\n     copy-device-to-file src dest [srcoffset:N] [destoffset:N] [size:N]\n\nDESCRIPTION\n    See \"copy_device_to_device\" for a general overview of this call.\n\n",
  .run = run_copy_device_to_file
};

struct command_entry copy_file_to_device_cmd_entry = {
  .name = "copy-file-to-device",
  .help = "NAME\n    copy-file-to-device - copy from source file to destination device\n\nSYNOPSIS\n     copy-file-to-device src dest [srcoffset:N] [destoffset:N] [size:N]\n\nDESCRIPTION\n    See \"copy_device_to_device\" for a general overview of this call.\n\n",
  .run = run_copy_file_to_device
};

struct command_entry copy_file_to_file_cmd_entry = {
  .name = "copy-file-to-file",
  .help = "NAME\n    copy-file-to-file - copy from source file to destination file\n\nSYNOPSIS\n     copy-file-to-file src dest [srcoffset:N] [destoffset:N] [size:N]\n\nDESCRIPTION\n    See \"copy_device_to_device\" for a general overview of this call.\n\n    This is not the function you want for copying files. This is for copying\n    blocks within existing files. See \"cp\", \"cp_a\" and \"mv\" for general file\n    copying and moving functions.\n\n",
  .run = run_copy_file_to_file
};

struct command_entry tune2fs_cmd_entry = {
  .name = "tune2fs",
  .help = "NAME\n    tune2fs - adjust ext2/ext3/ext4 filesystem parameters\n\nSYNOPSIS\n     tune2fs device [force:true|false] [maxmountcount:N] [mountcount:N] [errorbehavior:..] [group:N] [intervalbetweenchecks:N] [reservedblockspercentage:N] [lastmounteddirectory:..] [reservedblockscount:N] [user:N]\n\nDESCRIPTION\n    This call allows you to adjust various filesystem parameters of an\n    ext2/ext3/ext4 filesystem called \"device\".\n\n    The optional parameters are:\n\n    \"force\"\n        Force tune2fs to complete the operation even in the face of errors.\n        This is the same as the tune2fs \"-f\" option.\n\n    \"maxmountcount\"\n        Set the number of mounts after which the filesystem is checked by\n        e2fsck(8). If this is 0 then the number of mounts is disregarded.\n        This is the same as the tune2fs \"-c\" option.\n\n    \"mountcount\"\n        Set the number of times the filesystem has been mounted. This is the\n        same as the tune2fs \"-C\" option.\n\n    \"errorbehavior\"\n        Change the behavior of the kernel code when errors are detected.\n        Possible values currently are: \"continue\", \"remount-ro\", \"panic\". In\n        practice these options don't really make any difference,\n        particularly for write errors.\n\n        This is the same as the tune2fs \"-e\" option.\n\n    \"group\"\n        Set the group which can use reserved filesystem blocks. This is the\n        same as the tune2fs \"-g\" option except that it can only be specified\n        as a number.\n\n    \"intervalbetweenchecks\"\n        Adjust the maximal time between two filesystem checks (in seconds).\n        If the option is passed as 0 then time-dependent checking is\n        disabled.\n\n        This is the same as the tune2fs \"-i\" option.\n\n    \"reservedblockspercentage\"\n        Set the percentage of the filesystem which may only be allocated by\n        privileged processes. This is the same as the tune2fs \"-m\" option.\n\n    \"lastmounteddirectory\"\n        Set the last mounted directory. This is the same as the tune2fs \"-M\"\n        option.\n\n    \"reservedblockscount\" Set the number of reserved filesystem blocks. This\n    is the same as the tune2fs \"-r\" option.\n    \"user\"\n        Set the user who can use the reserved filesystem blocks. This is the\n        same as the tune2fs \"-u\" option except that it can only be specified\n        as a number.\n\n    To get the current values of filesystem parameters, see \"tune2fs_l\". For\n    precise details of how tune2fs works, see the tune2fs(8) man page.\n\n",
  .run = run_tune2fs
};

struct command_entry md_create_cmd_entry = {
  .name = "md-create",
  .help = "NAME\n    md-create - create a Linux md (RAID) device\n\nSYNOPSIS\n     md-create name devices [missingbitmap:N] [nrdevices:N] [spare:N] [chunk:N] [level:..]\n\nDESCRIPTION\n    Create a Linux md (RAID) device named \"name\" on the devices in the list\n    \"devices\".\n\n    The optional parameters are:\n\n    \"missingbitmap\"\n        A bitmap of missing devices. If a bit is set it means that a missing\n        device is added to the array. The least significant bit corresponds\n        to the first device in the array.\n\n        As examples:\n\n        If \"devices = [\"/dev/sda\"]\" and \"missingbitmap = 0x1\" then the\n        resulting array would be \"[<missing>, \"/dev/sda\"]\".\n\n        If \"devices = [\"/dev/sda\"]\" and \"missingbitmap = 0x2\" then the\n        resulting array would be \"[\"/dev/sda\", <missing>]\".\n\n        This defaults to 0 (no missing devices).\n\n        The length of \"devices\" + the number of bits set in \"missingbitmap\"\n        must equal \"nrdevices\" + \"spare\".\n\n    \"nrdevices\"\n        The number of active RAID devices.\n\n        If not set, this defaults to the length of \"devices\" plus the number\n        of bits set in \"missingbitmap\".\n\n    \"spare\"\n        The number of spare devices.\n\n        If not set, this defaults to 0.\n\n    \"chunk\"\n        The chunk size in bytes.\n\n    \"level\"\n        The RAID level, which can be one of: *linear*, *raid0*, *0*,\n        *stripe*, *raid1*, *1*, *mirror*, *raid4*, *4*, *raid5*, *5*,\n        *raid6*, *6*, *raid10*, *10*. Some of these are synonymous, and more\n        levels may be added in future.\n\n        If not set, this defaults to \"raid1\".\n\n",
  .run = run_md_create
};

struct command_entry list_md_devices_cmd_entry = {
  .name = "list-md-devices",
  .help = "NAME\n    list-md-devices - list Linux md (RAID) devices\n\nSYNOPSIS\n     list-md-devices\n\nDESCRIPTION\n    List all Linux md devices.\n\n",
  .run = run_list_md_devices
};

struct command_entry md_detail_cmd_entry = {
  .name = "md-detail",
  .help = "NAME\n    md-detail - obtain metadata for an MD device\n\nSYNOPSIS\n     md-detail md\n\nDESCRIPTION\n    This command exposes the output of 'mdadm -DY <md>'. The following\n    fields are usually present in the returned hash. Other fields may also\n    be present.\n\n    \"level\"\n        The raid level of the MD device.\n\n    \"devices\"\n        The number of underlying devices in the MD device.\n\n    \"metadata\"\n        The metadata version used.\n\n    \"uuid\"\n        The UUID of the MD device.\n\n    \"name\"\n        The name of the MD device.\n\n",
  .run = run_md_detail
};

struct command_entry md_stop_cmd_entry = {
  .name = "md-stop",
  .help = "NAME\n    md-stop - stop a Linux md (RAID) device\n\nSYNOPSIS\n     md-stop md\n\nDESCRIPTION\n    This command deactivates the MD array named \"md\". The device is stopped,\n    but it is not destroyed or zeroed.\n\n",
  .run = run_md_stop
};

struct command_entry blkid_cmd_entry = {
  .name = "blkid",
  .help = "NAME\n    blkid - print block device attributes\n\nSYNOPSIS\n     blkid device\n\nDESCRIPTION\n    This command returns block device attributes for \"device\". The following\n    fields are usually present in the returned hash. Other fields may also\n    be present.\n\n    \"UUID\"\n        The uuid of this device.\n\n    \"LABEL\"\n        The label of this device.\n\n    \"VERSION\"\n        The version of blkid command.\n\n    \"TYPE\"\n        The filesystem type or RAID of this device.\n\n    \"USAGE\"\n        The usage of this device, for example \"filesystem\" or \"raid\".\n\n",
  .run = run_blkid
};

struct command_entry e2fsck_cmd_entry = {
  .name = "e2fsck",
  .help = "NAME\n    e2fsck - check an ext2/ext3 filesystem\n\nSYNOPSIS\n     e2fsck device [correct:true|false] [forceall:true|false]\n\nDESCRIPTION\n    This runs the ext2/ext3 filesystem checker on \"device\". It can take the\n    following optional arguments:\n\n    \"correct\"\n        Automatically repair the file system. This option will cause e2fsck\n        to automatically fix any filesystem problems that can be safely\n        fixed without human intervention.\n\n        This option may not be specified at the same time as the \"forceall\"\n        option.\n\n    \"forceall\"\n        Assume an answer of 'yes' to all questions; allows e2fsck to be used\n        non-interactively.\n\n        This option may not be specified at the same time as the \"correct\"\n        option.\n\n",
  .run = run_e2fsck
};

void
list_commands (void)
{
  printf ("    %-16s     %s\n", _("Command"), _("Description"));
  list_builtin_commands ();
  printf ("%-20s %s\n", "add-cdrom", _("add a CD-ROM disk image to examine"));
  printf ("%-20s %s\n", "add-domain", _("add the disk(s) from a named libvirt domain"));
  printf ("%-20s %s\n", "add-drive", _("add an image to examine or modify"));
  printf ("%-20s %s\n", "add-drive-opts", _("add an image to examine or modify"));
  printf ("%-20s %s\n", "add-drive-ro", _("add a drive in snapshot mode (read-only)"));
  printf ("%-20s %s\n", "add-drive-ro-with-if", _("add a drive read-only specifying the QEMU block emulation to use"));
  printf ("%-20s %s\n", "add-drive-with-if", _("add a drive specifying the QEMU block emulation to use"));
  printf ("%-20s %s\n", "alloc", _("allocate and add a disk file"));
  printf ("%-20s %s\n", "aug-clear", _("clear Augeas path"));
  printf ("%-20s %s\n", "aug-close", _("close the current Augeas handle"));
  printf ("%-20s %s\n", "aug-defnode", _("define an Augeas node"));
  printf ("%-20s %s\n", "aug-defvar", _("define an Augeas variable"));
  printf ("%-20s %s\n", "aug-get", _("look up the value of an Augeas path"));
  printf ("%-20s %s\n", "aug-init", _("create a new Augeas handle"));
  printf ("%-20s %s\n", "aug-insert", _("insert a sibling Augeas node"));
  printf ("%-20s %s\n", "aug-load", _("load files into the tree"));
  printf ("%-20s %s\n", "aug-ls", _("list Augeas nodes under augpath"));
  printf ("%-20s %s\n", "aug-match", _("return Augeas nodes which match augpath"));
  printf ("%-20s %s\n", "aug-mv", _("move Augeas node"));
  printf ("%-20s %s\n", "aug-rm", _("remove an Augeas path"));
  printf ("%-20s %s\n", "aug-save", _("write all pending Augeas changes to disk"));
  printf ("%-20s %s\n", "aug-set", _("set Augeas path to value"));
  printf ("%-20s %s\n", "available", _("test availability of some parts of the API"));
  printf ("%-20s %s\n", "available-all-groups", _("return a list of all optional groups"));
  printf ("%-20s %s\n", "base64-in", _("upload base64-encoded data to file"));
  printf ("%-20s %s\n", "base64-out", _("download file and encode as base64"));
  printf ("%-20s %s\n", "blkid", _("print block device attributes"));
  printf ("%-20s %s\n", "blockdev-flushbufs", _("flush device buffers"));
  printf ("%-20s %s\n", "blockdev-getbsz", _("get blocksize of block device"));
  printf ("%-20s %s\n", "blockdev-getro", _("is block device set to read-only"));
  printf ("%-20s %s\n", "blockdev-getsize64", _("get total size of device in bytes"));
  printf ("%-20s %s\n", "blockdev-getss", _("get sectorsize of block device"));
  printf ("%-20s %s\n", "blockdev-getsz", _("get total size of device in 512-byte sectors"));
  printf ("%-20s %s\n", "blockdev-rereadpt", _("reread partition table"));
  printf ("%-20s %s\n", "blockdev-setbsz", _("set blocksize of block device"));
  printf ("%-20s %s\n", "blockdev-setro", _("set block device to read-only"));
  printf ("%-20s %s\n", "blockdev-setrw", _("set block device to read-write"));
  printf ("%-20s %s\n", "btrfs-filesystem-resize", _("resize a btrfs filesystem"));
  printf ("%-20s %s\n", "case-sensitive-path", _("return true path on case-insensitive filesystem"));
  printf ("%-20s %s\n", "cat", _("list the contents of a file"));
  printf ("%-20s %s\n", "checksum", _("compute MD5, SHAx or CRC checksum of file"));
  printf ("%-20s %s\n", "checksum-device", _("compute MD5, SHAx or CRC checksum of the contents of a device"));
  printf ("%-20s %s\n", "checksums-out", _("compute MD5, SHAx or CRC checksum of files in a directory"));
  printf ("%-20s %s\n", "chmod", _("change file mode"));
  printf ("%-20s %s\n", "chown", _("change file owner and group"));
  printf ("%-20s %s\n", "command", _("run a command from the guest filesystem"));
  printf ("%-20s %s\n", "command-lines", _("run a command, returning lines"));
  printf ("%-20s %s\n", "compress-device-out", _("output compressed device"));
  printf ("%-20s %s\n", "compress-out", _("output compressed file"));
  printf ("%-20s %s\n", "config", _("add qemu parameters"));
  printf ("%-20s %s\n", "copy-device-to-device", _("copy from source device to destination device"));
  printf ("%-20s %s\n", "copy-device-to-file", _("copy from source device to destination file"));
  printf ("%-20s %s\n", "copy-file-to-device", _("copy from source file to destination device"));
  printf ("%-20s %s\n", "copy-file-to-file", _("copy from source file to destination file"));
  printf ("%-20s %s\n", "copy-in", _("copy local files or directories into an image"));
  printf ("%-20s %s\n", "copy-out", _("copy remote files or directories out of an image"));
  printf ("%-20s %s\n", "copy-size", _("copy size bytes from source to destination using dd"));
  printf ("%-20s %s\n", "cp", _("copy a file"));
  printf ("%-20s %s\n", "cp-a", _("copy a file or directory recursively"));
  printf ("%-20s %s\n", "dd", _("copy from source to destination using dd"));
  printf ("%-20s %s\n", "debug", _("debugging and internals"));
  printf ("%-20s %s\n", "debug-cmdline", _("debug the QEMU command line (internal use only)"));
  printf ("%-20s %s\n", "debug-drives", _("debug the drives (internal use only)"));
  printf ("%-20s %s\n", "debug-upload", _("upload a file to the appliance (internal use only)"));
  printf ("%-20s %s\n", "delete-event", _("delete a previously registered event handler"));
  printf ("%-20s %s\n", "df", _("report file system disk space usage"));
  printf ("%-20s %s\n", "df-h", _("report file system disk space usage (human readable)"));
  printf ("%-20s %s\n", "display", _("display an image"));
  printf ("%-20s %s\n", "dmesg", _("return kernel messages"));
  printf ("%-20s %s\n", "download", _("download a file to the local machine"));
  printf ("%-20s %s\n", "download-offset", _("download a file to the local machine with offset and size"));
  printf ("%-20s %s\n", "drop-caches", _("drop kernel page cache, dentries and inodes"));
  printf ("%-20s %s\n", "du", _("estimate file space usage"));
  printf ("%-20s %s\n", "e2fsck", _("check an ext2/ext3 filesystem"));
  printf ("%-20s %s\n", "e2fsck-f", _("check an ext2/ext3 filesystem"));
  printf ("%-20s %s\n", "echo", _("display a line of text"));
  printf ("%-20s %s\n", "echo-daemon", _("echo arguments back to the client"));
  printf ("%-20s %s\n", "edit", _("edit a file"));
  printf ("%-20s %s\n", "egrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "egrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "equal", _("test if two files have equal contents"));
  printf ("%-20s %s\n", "event", _("register a handler for an event or events"));
  printf ("%-20s %s\n", "exists", _("test if file or directory exists"));
  printf ("%-20s %s\n", "fallocate", _("preallocate a file in the guest filesystem"));
  printf ("%-20s %s\n", "fallocate64", _("preallocate a file in the guest filesystem"));
  printf ("%-20s %s\n", "fgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "fgrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "file", _("determine file type"));
  printf ("%-20s %s\n", "file-architecture", _("detect the architecture of a binary file"));
  printf ("%-20s %s\n", "filesize", _("return the size of the file in bytes"));
  printf ("%-20s %s\n", "fill", _("fill a file with octets"));
  printf ("%-20s %s\n", "fill-pattern", _("fill a file with a repeating pattern of bytes"));
  printf ("%-20s %s\n", "find", _("find all files and directories"));
  printf ("%-20s %s\n", "find0", _("find all files and directories, returning NUL-separated list"));
  printf ("%-20s %s\n", "findfs-label", _("find a filesystem by label"));
  printf ("%-20s %s\n", "findfs-uuid", _("find a filesystem by UUID"));
  printf ("%-20s %s\n", "fsck", _("run the filesystem checker"));
  printf ("%-20s %s\n", "get-append", _("get the additional kernel options"));
  printf ("%-20s %s\n", "get-attach-method", _("get the attach method"));
  printf ("%-20s %s\n", "get-autosync", _("get autosync mode"));
  printf ("%-20s %s\n", "get-direct", _("get direct appliance mode flag"));
  printf ("%-20s %s\n", "get-e2label", _("get the ext2/3/4 filesystem label"));
  printf ("%-20s %s\n", "get-e2uuid", _("get the ext2/3/4 filesystem UUID"));
  printf ("%-20s %s\n", "get-memsize", _("get memory allocated to the qemu subprocess"));
  printf ("%-20s %s\n", "get-network", _("get enable network flag"));
  printf ("%-20s %s\n", "get-path", _("get the search path"));
  printf ("%-20s %s\n", "get-pgroup", _("get process group flag"));
  printf ("%-20s %s\n", "get-pid", _("get PID of qemu subprocess"));
  printf ("%-20s %s\n", "get-qemu", _("get the qemu binary"));
  printf ("%-20s %s\n", "get-recovery-proc", _("get recovery process enabled flag"));
  printf ("%-20s %s\n", "get-selinux", _("get SELinux enabled flag"));
  printf ("%-20s %s\n", "get-smp", _("get number of virtual CPUs in appliance"));
  printf ("%-20s %s\n", "get-state", _("get the current state"));
  printf ("%-20s %s\n", "get-trace", _("get command trace enabled flag"));
  printf ("%-20s %s\n", "get-umask", _("get the current umask"));
  printf ("%-20s %s\n", "get-verbose", _("get verbose mode"));
  printf ("%-20s %s\n", "getcon", _("get SELinux security context"));
  printf ("%-20s %s\n", "getxattr", _("get a single extended attribute"));
  printf ("%-20s %s\n", "getxattrs", _("list extended attributes of a file or directory"));
  printf ("%-20s %s\n", "glob", _("expand wildcards in command"));
  printf ("%-20s %s\n", "glob-expand", _("expand a wildcard path"));
  printf ("%-20s %s\n", "grep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "grepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "grub-install", _("install GRUB 1"));
  printf ("%-20s %s\n", "head", _("return first 10 lines of a file"));
  printf ("%-20s %s\n", "head-n", _("return first N lines of a file"));
  printf ("%-20s %s\n", "hexdump", _("dump a file in hexadecimal"));
  printf ("%-20s %s\n", "hexedit", _("edit with a hex editor"));
  printf ("%-20s %s\n", "initrd-cat", _("list the contents of a single file in an initrd"));
  printf ("%-20s %s\n", "initrd-list", _("list files in an initrd"));
  printf ("%-20s %s\n", "inotify-add-watch", _("add an inotify watch"));
  printf ("%-20s %s\n", "inotify-close", _("close the inotify handle"));
  printf ("%-20s %s\n", "inotify-files", _("return list of watched files that had events"));
  printf ("%-20s %s\n", "inotify-init", _("create an inotify handle"));
  printf ("%-20s %s\n", "inotify-read", _("return list of inotify events"));
  printf ("%-20s %s\n", "inotify-rm-watch", _("remove an inotify watch"));
  printf ("%-20s %s\n", "inspect-get-arch", _("get architecture of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-distro", _("get distro of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-drive-mappings", _("get drive letter mappings"));
  printf ("%-20s %s\n", "inspect-get-filesystems", _("get filesystems associated with inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-format", _("get format of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-hostname", _("get hostname of the operating system"));
  printf ("%-20s %s\n", "inspect-get-icon", _("get the icon corresponding to this operating system"));
  printf ("%-20s %s\n", "inspect-get-major-version", _("get major version of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-minor-version", _("get minor version of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-mountpoints", _("get mountpoints of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-package-format", _("get package format used by the operating system"));
  printf ("%-20s %s\n", "inspect-get-package-management", _("get package management tool used by the operating system"));
  printf ("%-20s %s\n", "inspect-get-product-name", _("get product name of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-product-variant", _("get product variant of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-roots", _("return list of operating systems found by last inspection"));
  printf ("%-20s %s\n", "inspect-get-type", _("get type of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-windows-current-control-set", _("get Windows CurrentControlSet of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-windows-systemroot", _("get Windows systemroot of inspected operating system"));
  printf ("%-20s %s\n", "inspect-is-live", _("get live flag for install disk"));
  printf ("%-20s %s\n", "inspect-is-multipart", _("get multipart flag for install disk"));
  printf ("%-20s %s\n", "inspect-is-netinst", _("get netinst (network installer) flag for install disk"));
  printf ("%-20s %s\n", "inspect-list-applications", _("get list of applications installed in the operating system"));
  printf ("%-20s %s\n", "inspect-os", _("inspect disk and return list of operating systems found"));
  printf ("%-20s %s\n", "is-blockdev", _("test if block device"));
  printf ("%-20s %s\n", "is-busy", _("is busy processing a command"));
  printf ("%-20s %s\n", "is-chardev", _("test if character device"));
  printf ("%-20s %s\n", "is-config", _("is in configuration state"));
  printf ("%-20s %s\n", "is-dir", _("test if a directory"));
  printf ("%-20s %s\n", "is-fifo", _("test if FIFO (named pipe)"));
  printf ("%-20s %s\n", "is-file", _("test if a regular file"));
  printf ("%-20s %s\n", "is-launching", _("is launching subprocess"));
  printf ("%-20s %s\n", "is-lv", _("test if device is a logical volume"));
  printf ("%-20s %s\n", "is-ready", _("is ready to accept commands"));
  printf ("%-20s %s\n", "is-socket", _("test if socket"));
  printf ("%-20s %s\n", "is-symlink", _("test if symbolic link"));
  printf ("%-20s %s\n", "is-zero", _("test if a file contains all zero bytes"));
  printf ("%-20s %s\n", "is-zero-device", _("test if a device contains all zero bytes"));
  printf ("%-20s %s\n", "kill-subprocess", _("kill the qemu subprocess"));
  printf ("%-20s %s\n", "launch", _("launch the qemu subprocess"));
  printf ("%-20s %s\n", "lcd", _("change working directory"));
  printf ("%-20s %s\n", "lchown", _("change file owner and group"));
  printf ("%-20s %s\n", "lgetxattr", _("get a single extended attribute"));
  printf ("%-20s %s\n", "lgetxattrs", _("list extended attributes of a file or directory"));
  printf ("%-20s %s\n", "list-9p", _("list 9p filesystems"));
  printf ("%-20s %s\n", "list-devices", _("list the block devices"));
  printf ("%-20s %s\n", "list-dm-devices", _("list device mapper devices"));
  printf ("%-20s %s\n", "list-events", _("list event handlers"));
  printf ("%-20s %s\n", "list-filesystems", _("list filesystems"));
  printf ("%-20s %s\n", "list-md-devices", _("list Linux md (RAID) devices"));
  printf ("%-20s %s\n", "list-partitions", _("list the partitions"));
  printf ("%-20s %s\n", "ll", _("list the files in a directory (long format)"));
  printf ("%-20s %s\n", "ln", _("create a hard link"));
  printf ("%-20s %s\n", "ln-f", _("create a hard link"));
  printf ("%-20s %s\n", "ln-s", _("create a symbolic link"));
  printf ("%-20s %s\n", "ln-sf", _("create a symbolic link"));
  printf ("%-20s %s\n", "lremovexattr", _("remove extended attribute of a file or directory"));
  printf ("%-20s %s\n", "ls", _("list the files in a directory"));
  printf ("%-20s %s\n", "lsetxattr", _("set extended attribute of a file or directory"));
  printf ("%-20s %s\n", "lstat", _("get file information for a symbolic link"));
  printf ("%-20s %s\n", "lstatlist", _("lstat on multiple files"));
  printf ("%-20s %s\n", "luks-add-key", _("add a key on a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-close", _("close a LUKS device"));
  printf ("%-20s %s\n", "luks-format", _("format a block device as a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-format-cipher", _("format a block device as a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-kill-slot", _("remove a key from a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-open", _("open a LUKS-encrypted block device"));
  printf ("%-20s %s\n", "luks-open-ro", _("open a LUKS-encrypted block device read-only"));
  printf ("%-20s %s\n", "lvcreate", _("create an LVM logical volume"));
  printf ("%-20s %s\n", "lvm-canonical-lv-name", _("get canonical name of an LV"));
  printf ("%-20s %s\n", "lvm-clear-filter", _("clear LVM device filter"));
  printf ("%-20s %s\n", "lvm-remove-all", _("remove all LVM LVs, VGs and PVs"));
  printf ("%-20s %s\n", "lvm-set-filter", _("set LVM device filter"));
  printf ("%-20s %s\n", "lvremove", _("remove an LVM logical volume"));
  printf ("%-20s %s\n", "lvrename", _("rename an LVM logical volume"));
  printf ("%-20s %s\n", "lvresize", _("resize an LVM logical volume"));
  printf ("%-20s %s\n", "lvresize-free", _("expand an LV to fill free space"));
  printf ("%-20s %s\n", "lvs", _("list the LVM logical volumes (LVs)"));
  printf ("%-20s %s\n", "lvs-full", _("list the LVM logical volumes (LVs)"));
  printf ("%-20s %s\n", "lvuuid", _("get the UUID of a logical volume"));
  printf ("%-20s %s\n", "lxattrlist", _("lgetxattr on multiple files"));
  printf ("%-20s %s\n", "man", _("open the manual"));
  printf ("%-20s %s\n", "md-create", _("create a Linux md (RAID) device"));
  printf ("%-20s %s\n", "md-detail", _("obtain metadata for an MD device"));
  printf ("%-20s %s\n", "md-stop", _("stop a Linux md (RAID) device"));
  printf ("%-20s %s\n", "mkdir", _("create a directory"));
  printf ("%-20s %s\n", "mkdir-mode", _("create a directory with a particular mode"));
  printf ("%-20s %s\n", "mkdir-p", _("create a directory and parents"));
  printf ("%-20s %s\n", "mkdtemp", _("create a temporary directory"));
  printf ("%-20s %s\n", "mke2fs-J", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2fs-JL", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2fs-JU", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2journal", _("make ext2/3/4 external journal"));
  printf ("%-20s %s\n", "mke2journal-L", _("make ext2/3/4 external journal with label"));
  printf ("%-20s %s\n", "mke2journal-U", _("make ext2/3/4 external journal with UUID"));
  printf ("%-20s %s\n", "mkfifo", _("make FIFO (named pipe)"));
  printf ("%-20s %s\n", "mkfs", _("make a filesystem"));
  printf ("%-20s %s\n", "mkfs-b", _("make a filesystem with block size"));
  printf ("%-20s %s\n", "mkfs-opts", _("make a filesystem"));
  printf ("%-20s %s\n", "mkmountpoint", _("create a mountpoint"));
  printf ("%-20s %s\n", "mknod", _("make block, character or FIFO devices"));
  printf ("%-20s %s\n", "mknod-b", _("make block device node"));
  printf ("%-20s %s\n", "mknod-c", _("make char device node"));
  printf ("%-20s %s\n", "mkswap", _("create a swap partition"));
  printf ("%-20s %s\n", "mkswap-L", _("create a swap partition with a label"));
  printf ("%-20s %s\n", "mkswap-U", _("create a swap partition with an explicit UUID"));
  printf ("%-20s %s\n", "mkswap-file", _("create a swap file"));
  printf ("%-20s %s\n", "modprobe", _("load a kernel module"));
  printf ("%-20s %s\n", "more", _("view a file"));
  printf ("%-20s %s\n", "mount", _("mount a guest disk at a position in the filesystem"));
  printf ("%-20s %s\n", "mount-9p", _("mount 9p filesystem"));
  printf ("%-20s %s\n", "mount-loop", _("mount a file using the loop device"));
  printf ("%-20s %s\n", "mount-options", _("mount a guest disk with mount options"));
  printf ("%-20s %s\n", "mount-ro", _("mount a guest disk, read-only"));
  printf ("%-20s %s\n", "mount-vfs", _("mount a guest disk with mount options and vfstype"));
  printf ("%-20s %s\n", "mountpoints", _("show mountpoints"));
  printf ("%-20s %s\n", "mounts", _("show mounted filesystems"));
  printf ("%-20s %s\n", "mv", _("move a file"));
  printf ("%-20s %s\n", "ntfs-3g-probe", _("probe NTFS volume"));
  printf ("%-20s %s\n", "ntfsresize", _("resize an NTFS filesystem"));
  printf ("%-20s %s\n", "ntfsresize-opts", _("resize an NTFS filesystem"));
  printf ("%-20s %s\n", "ntfsresize-size", _("resize an NTFS filesystem (with size)"));
  printf ("%-20s %s\n", "part-add", _("add a partition to the device"));
  printf ("%-20s %s\n", "part-del", _("delete a partition"));
  printf ("%-20s %s\n", "part-disk", _("partition whole disk with a single primary partition"));
  printf ("%-20s %s\n", "part-get-bootable", _("return true if a partition is bootable"));
  printf ("%-20s %s\n", "part-get-mbr-id", _("get the MBR type byte (ID byte) from a partition"));
  printf ("%-20s %s\n", "part-get-parttype", _("get the partition table type"));
  printf ("%-20s %s\n", "part-init", _("create an empty partition table"));
  printf ("%-20s %s\n", "part-list", _("list partitions on a device"));
  printf ("%-20s %s\n", "part-set-bootable", _("make a partition bootable"));
  printf ("%-20s %s\n", "part-set-mbr-id", _("set the MBR type byte (ID byte) of a partition"));
  printf ("%-20s %s\n", "part-set-name", _("set partition name"));
  printf ("%-20s %s\n", "part-to-dev", _("convert partition name to device name"));
  printf ("%-20s %s\n", "part-to-partnum", _("convert partition name to partition number"));
  printf ("%-20s %s\n", "ping-daemon", _("ping the guest daemon"));
  printf ("%-20s %s\n", "pread", _("read part of a file"));
  printf ("%-20s %s\n", "pread-device", _("read part of a device"));
  printf ("%-20s %s\n", "pvcreate", _("create an LVM physical volume"));
  printf ("%-20s %s\n", "pvremove", _("remove an LVM physical volume"));
  printf ("%-20s %s\n", "pvresize", _("resize an LVM physical volume"));
  printf ("%-20s %s\n", "pvresize-size", _("resize an LVM physical volume (with size)"));
  printf ("%-20s %s\n", "pvs", _("list the LVM physical volumes (PVs)"));
  printf ("%-20s %s\n", "pvs-full", _("list the LVM physical volumes (PVs)"));
  printf ("%-20s %s\n", "pvuuid", _("get the UUID of a physical volume"));
  printf ("%-20s %s\n", "pwrite", _("write to part of a file"));
  printf ("%-20s %s\n", "pwrite-device", _("write to part of a device"));
  printf ("%-20s %s\n", "read-file", _("read a file"));
  printf ("%-20s %s\n", "read-lines", _("read file as lines"));
  printf ("%-20s %s\n", "readdir", _("read directories entries"));
  printf ("%-20s %s\n", "readlink", _("read the target of a symbolic link"));
  printf ("%-20s %s\n", "readlinklist", _("readlink on multiple files"));
  printf ("%-20s %s\n", "realpath", _("canonicalized absolute pathname"));
  printf ("%-20s %s\n", "removexattr", _("remove extended attribute of a file or directory"));
  printf ("%-20s %s\n", "reopen", _("close and reopen libguestfs handle"));
  printf ("%-20s %s\n", "resize2fs", _("resize an ext2, ext3 or ext4 filesystem"));
  printf ("%-20s %s\n", "resize2fs-M", _("resize an ext2, ext3 or ext4 filesystem to the minimum size"));
  printf ("%-20s %s\n", "resize2fs-size", _("resize an ext2, ext3 or ext4 filesystem (with size)"));
  printf ("%-20s %s\n", "rm", _("remove a file"));
  printf ("%-20s %s\n", "rm-rf", _("remove a file or directory recursively"));
  printf ("%-20s %s\n", "rmdir", _("remove a directory"));
  printf ("%-20s %s\n", "rmmountpoint", _("remove a mountpoint"));
  printf ("%-20s %s\n", "scrub-device", _("scrub (securely wipe) a device"));
  printf ("%-20s %s\n", "scrub-file", _("scrub (securely wipe) a file"));
  printf ("%-20s %s\n", "scrub-freespace", _("scrub (securely wipe) free space"));
  printf ("%-20s %s\n", "set-append", _("add options to kernel command line"));
  printf ("%-20s %s\n", "set-attach-method", _("set the attach method"));
  printf ("%-20s %s\n", "set-autosync", _("set autosync mode"));
  printf ("%-20s %s\n", "set-direct", _("enable or disable direct appliance mode"));
  printf ("%-20s %s\n", "set-e2label", _("set the ext2/3/4 filesystem label"));
  printf ("%-20s %s\n", "set-e2uuid", _("set the ext2/3/4 filesystem UUID"));
  printf ("%-20s %s\n", "set-memsize", _("set memory allocated to the qemu subprocess"));
  printf ("%-20s %s\n", "set-network", _("set enable network flag"));
  printf ("%-20s %s\n", "set-path", _("set the search path"));
  printf ("%-20s %s\n", "set-pgroup", _("set process group flag"));
  printf ("%-20s %s\n", "set-qemu", _("set the qemu binary"));
  printf ("%-20s %s\n", "set-recovery-proc", _("enable or disable the recovery process"));
  printf ("%-20s %s\n", "set-selinux", _("set SELinux enabled or disabled at appliance boot"));
  printf ("%-20s %s\n", "set-smp", _("set number of virtual CPUs in appliance"));
  printf ("%-20s %s\n", "set-trace", _("enable or disable command traces"));
  printf ("%-20s %s\n", "set-verbose", _("set verbose mode"));
  printf ("%-20s %s\n", "setcon", _("set SELinux security context"));
  printf ("%-20s %s\n", "setenv", _("set an environment variable"));
  printf ("%-20s %s\n", "setxattr", _("set extended attribute of a file or directory"));
  printf ("%-20s %s\n", "sfdisk", _("create partitions on a block device"));
  printf ("%-20s %s\n", "sfdiskM", _("create partitions on a block device"));
  printf ("%-20s %s\n", "sfdisk-N", _("modify a single partition on a block device"));
  printf ("%-20s %s\n", "sfdisk-disk-geometry", _("display the disk geometry from the partition table"));
  printf ("%-20s %s\n", "sfdisk-kernel-geometry", _("display the kernel geometry"));
  printf ("%-20s %s\n", "sfdisk-l", _("display the partition table"));
  printf ("%-20s %s\n", "sh", _("run a command via the shell"));
  printf ("%-20s %s\n", "sh-lines", _("run a command via the shell returning lines"));
  printf ("%-20s %s\n", "sleep", _("sleep for some seconds"));
  printf ("%-20s %s\n", "sparse", _("create a sparse disk image and add"));
  printf ("%-20s %s\n", "stat", _("get file information"));
  printf ("%-20s %s\n", "statvfs", _("get file system statistics"));
  printf ("%-20s %s\n", "strings", _("print the printable strings in a file"));
  printf ("%-20s %s\n", "strings-e", _("print the printable strings in a file"));
  printf ("%-20s %s\n", "supported", _("list supported groups of commands"));
  printf ("%-20s %s\n", "swapoff-device", _("disable swap on device"));
  printf ("%-20s %s\n", "swapoff-file", _("disable swap on file"));
  printf ("%-20s %s\n", "swapoff-label", _("disable swap on labeled swap partition"));
  printf ("%-20s %s\n", "swapoff-uuid", _("disable swap on swap partition by UUID"));
  printf ("%-20s %s\n", "swapon-device", _("enable swap on device"));
  printf ("%-20s %s\n", "swapon-file", _("enable swap on file"));
  printf ("%-20s %s\n", "swapon-label", _("enable swap on labeled swap partition"));
  printf ("%-20s %s\n", "swapon-uuid", _("enable swap on swap partition by UUID"));
  printf ("%-20s %s\n", "sync", _("sync disks, writes are flushed through to the disk image"));
  printf ("%-20s %s\n", "tail", _("return last 10 lines of a file"));
  printf ("%-20s %s\n", "tail-n", _("return last N lines of a file"));
  printf ("%-20s %s\n", "tar-in", _("unpack tarfile to directory"));
  printf ("%-20s %s\n", "tar-out", _("pack directory into tarfile"));
  printf ("%-20s %s\n", "tgz-in", _("unpack compressed tarball to directory"));
  printf ("%-20s %s\n", "tgz-out", _("pack directory into compressed tarball"));
  printf ("%-20s %s\n", "time", _("print elapsed time taken to run a command"));
  printf ("%-20s %s\n", "touch", _("update file timestamps or create a new file"));
  printf ("%-20s %s\n", "truncate", _("truncate a file to zero size"));
  printf ("%-20s %s\n", "truncate-size", _("truncate a file to a particular size"));
  printf ("%-20s %s\n", "tune2fs", _("adjust ext2/ext3/ext4 filesystem parameters"));
  printf ("%-20s %s\n", "tune2fs-l", _("get ext2/ext3/ext4 superblock details"));
  printf ("%-20s %s\n", "txz-in", _("unpack compressed tarball to directory"));
  printf ("%-20s %s\n", "txz-out", _("pack directory into compressed tarball"));
  printf ("%-20s %s\n", "umask", _("set file mode creation mask (umask)"));
  printf ("%-20s %s\n", "umount", _("unmount a filesystem"));
  printf ("%-20s %s\n", "umount-all", _("unmount all filesystems"));
  printf ("%-20s %s\n", "unsetenv", _("unset an environment variable"));
  printf ("%-20s %s\n", "upload", _("upload a file from the local machine"));
  printf ("%-20s %s\n", "upload-offset", _("upload a file from the local machine with offset"));
  printf ("%-20s %s\n", "utimens", _("set timestamp of a file with nanosecond precision"));
  printf ("%-20s %s\n", "version", _("get the library version number"));
  printf ("%-20s %s\n", "vfs-label", _("get the filesystem label"));
  printf ("%-20s %s\n", "vfs-type", _("get the Linux VFS type corresponding to a mounted device"));
  printf ("%-20s %s\n", "vfs-uuid", _("get the filesystem UUID"));
  printf ("%-20s %s\n", "vg-activate", _("activate or deactivate some volume groups"));
  printf ("%-20s %s\n", "vg-activate-all", _("activate or deactivate all volume groups"));
  printf ("%-20s %s\n", "vgcreate", _("create an LVM volume group"));
  printf ("%-20s %s\n", "vglvuuids", _("get the LV UUIDs of all LVs in the volume group"));
  printf ("%-20s %s\n", "vgpvuuids", _("get the PV UUIDs containing the volume group"));
  printf ("%-20s %s\n", "vgremove", _("remove an LVM volume group"));
  printf ("%-20s %s\n", "vgrename", _("rename an LVM volume group"));
  printf ("%-20s %s\n", "vgs", _("list the LVM volume groups (VGs)"));
  printf ("%-20s %s\n", "vgs-full", _("list the LVM volume groups (VGs)"));
  printf ("%-20s %s\n", "vgscan", _("rescan for LVM physical volumes, volume groups and logical volumes"));
  printf ("%-20s %s\n", "vguuid", _("get the UUID of a volume group"));
  printf ("%-20s %s\n", "wc-c", _("count characters in a file"));
  printf ("%-20s %s\n", "wc-l", _("count lines in a file"));
  printf ("%-20s %s\n", "wc-w", _("count words in a file"));
  printf ("%-20s %s\n", "write", _("create a new file"));
  printf ("%-20s %s\n", "write-append", _("append content to end of file"));
  printf ("%-20s %s\n", "write-file", _("create a file"));
  printf ("%-20s %s\n", "zegrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zegrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zero", _("write zeroes to the device"));
  printf ("%-20s %s\n", "zero-device", _("write zeroes to an entire device"));
  printf ("%-20s %s\n", "zerofree", _("zero unused inodes and disk blocks on ext2/3 filesystem"));
  printf ("%-20s %s\n", "zfgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zfgrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zfile", _("determine file type inside a compressed file"));
  printf ("%-20s %s\n", "zgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zgrepi", _("return lines matching a pattern"));
  printf ("    %s\n",          _("Use -h <cmd> / help <cmd> to show detailed help for a command."));
}

int
display_command (const char *cmd)
{
  const struct command_table *ct;

  ct = lookup_fish_command (cmd, strlen (cmd));
  if (ct) {
    fputs (ct->entry->help, stdout);
    return 0;
  }
  else
    return display_builtin_command (cmd);
}

static void
print_int_bool_indent (struct guestfs_int_bool *int_bool, const char *indent)
{
  printf ("%si: %" PRIi32 "\n", indent, int_bool->i);
  printf ("%sb: %" PRIi32 "\n", indent, int_bool->b);
}

static void
print_lvm_pv_indent (struct guestfs_lvm_pv *lvm_pv, const char *indent)
{
  unsigned int i;

  printf ("%spv_name: %s\n", indent, lvm_pv->pv_name);
  printf ("%spv_uuid: ", indent);
  for (i = 0; i < 32; ++i)
    printf ("%c", lvm_pv->pv_uuid[i]);
  printf ("\n");
  printf ("%spv_fmt: %s\n", indent, lvm_pv->pv_fmt);
  printf ("%spv_size: %" PRIu64 "\n", indent, lvm_pv->pv_size);
  printf ("%sdev_size: %" PRIu64 "\n", indent, lvm_pv->dev_size);
  printf ("%spv_free: %" PRIu64 "\n", indent, lvm_pv->pv_free);
  printf ("%spv_used: %" PRIu64 "\n", indent, lvm_pv->pv_used);
  printf ("%spv_attr: %s\n", indent, lvm_pv->pv_attr);
  printf ("%spv_pe_count: %" PRIi64 "\n", indent, lvm_pv->pv_pe_count);
  printf ("%spv_pe_alloc_count: %" PRIi64 "\n", indent, lvm_pv->pv_pe_alloc_count);
  printf ("%spv_tags: %s\n", indent, lvm_pv->pv_tags);
  printf ("%spe_start: %" PRIu64 "\n", indent, lvm_pv->pe_start);
  printf ("%spv_mda_count: %" PRIi64 "\n", indent, lvm_pv->pv_mda_count);
  printf ("%spv_mda_free: %" PRIu64 "\n", indent, lvm_pv->pv_mda_free);
}

static void
print_lvm_vg_indent (struct guestfs_lvm_vg *lvm_vg, const char *indent)
{
  unsigned int i;

  printf ("%svg_name: %s\n", indent, lvm_vg->vg_name);
  printf ("%svg_uuid: ", indent);
  for (i = 0; i < 32; ++i)
    printf ("%c", lvm_vg->vg_uuid[i]);
  printf ("\n");
  printf ("%svg_fmt: %s\n", indent, lvm_vg->vg_fmt);
  printf ("%svg_attr: %s\n", indent, lvm_vg->vg_attr);
  printf ("%svg_size: %" PRIu64 "\n", indent, lvm_vg->vg_size);
  printf ("%svg_free: %" PRIu64 "\n", indent, lvm_vg->vg_free);
  printf ("%svg_sysid: %s\n", indent, lvm_vg->vg_sysid);
  printf ("%svg_extent_size: %" PRIu64 "\n", indent, lvm_vg->vg_extent_size);
  printf ("%svg_extent_count: %" PRIi64 "\n", indent, lvm_vg->vg_extent_count);
  printf ("%svg_free_count: %" PRIi64 "\n", indent, lvm_vg->vg_free_count);
  printf ("%smax_lv: %" PRIi64 "\n", indent, lvm_vg->max_lv);
  printf ("%smax_pv: %" PRIi64 "\n", indent, lvm_vg->max_pv);
  printf ("%spv_count: %" PRIi64 "\n", indent, lvm_vg->pv_count);
  printf ("%slv_count: %" PRIi64 "\n", indent, lvm_vg->lv_count);
  printf ("%ssnap_count: %" PRIi64 "\n", indent, lvm_vg->snap_count);
  printf ("%svg_seqno: %" PRIi64 "\n", indent, lvm_vg->vg_seqno);
  printf ("%svg_tags: %s\n", indent, lvm_vg->vg_tags);
  printf ("%svg_mda_count: %" PRIi64 "\n", indent, lvm_vg->vg_mda_count);
  printf ("%svg_mda_free: %" PRIu64 "\n", indent, lvm_vg->vg_mda_free);
}

static void
print_lvm_lv_indent (struct guestfs_lvm_lv *lvm_lv, const char *indent)
{
  unsigned int i;

  printf ("%slv_name: %s\n", indent, lvm_lv->lv_name);
  printf ("%slv_uuid: ", indent);
  for (i = 0; i < 32; ++i)
    printf ("%c", lvm_lv->lv_uuid[i]);
  printf ("\n");
  printf ("%slv_attr: %s\n", indent, lvm_lv->lv_attr);
  printf ("%slv_major: %" PRIi64 "\n", indent, lvm_lv->lv_major);
  printf ("%slv_minor: %" PRIi64 "\n", indent, lvm_lv->lv_minor);
  printf ("%slv_kernel_major: %" PRIi64 "\n", indent, lvm_lv->lv_kernel_major);
  printf ("%slv_kernel_minor: %" PRIi64 "\n", indent, lvm_lv->lv_kernel_minor);
  printf ("%slv_size: %" PRIu64 "\n", indent, lvm_lv->lv_size);
  printf ("%sseg_count: %" PRIi64 "\n", indent, lvm_lv->seg_count);
  printf ("%sorigin: %s\n", indent, lvm_lv->origin);
  if (lvm_lv->snap_percent >= 0)
    printf ("%ssnap_percent: %g %%\n", indent, (double) lvm_lv->snap_percent);
  else
    printf ("%ssnap_percent: \n", indent);
  if (lvm_lv->copy_percent >= 0)
    printf ("%scopy_percent: %g %%\n", indent, (double) lvm_lv->copy_percent);
  else
    printf ("%scopy_percent: \n", indent);
  printf ("%smove_pv: %s\n", indent, lvm_lv->move_pv);
  printf ("%slv_tags: %s\n", indent, lvm_lv->lv_tags);
  printf ("%smirror_log: %s\n", indent, lvm_lv->mirror_log);
  printf ("%smodules: %s\n", indent, lvm_lv->modules);
}

static void
print_stat_indent (struct guestfs_stat *stat, const char *indent)
{
  printf ("%sdev: %" PRIi64 "\n", indent, stat->dev);
  printf ("%sino: %" PRIi64 "\n", indent, stat->ino);
  printf ("%smode: %" PRIi64 "\n", indent, stat->mode);
  printf ("%snlink: %" PRIi64 "\n", indent, stat->nlink);
  printf ("%suid: %" PRIi64 "\n", indent, stat->uid);
  printf ("%sgid: %" PRIi64 "\n", indent, stat->gid);
  printf ("%srdev: %" PRIi64 "\n", indent, stat->rdev);
  printf ("%ssize: %" PRIi64 "\n", indent, stat->size);
  printf ("%sblksize: %" PRIi64 "\n", indent, stat->blksize);
  printf ("%sblocks: %" PRIi64 "\n", indent, stat->blocks);
  printf ("%satime: %" PRIi64 "\n", indent, stat->atime);
  printf ("%smtime: %" PRIi64 "\n", indent, stat->mtime);
  printf ("%sctime: %" PRIi64 "\n", indent, stat->ctime);
}

static void
print_statvfs_indent (struct guestfs_statvfs *statvfs, const char *indent)
{
  printf ("%sbsize: %" PRIi64 "\n", indent, statvfs->bsize);
  printf ("%sfrsize: %" PRIi64 "\n", indent, statvfs->frsize);
  printf ("%sblocks: %" PRIi64 "\n", indent, statvfs->blocks);
  printf ("%sbfree: %" PRIi64 "\n", indent, statvfs->bfree);
  printf ("%sbavail: %" PRIi64 "\n", indent, statvfs->bavail);
  printf ("%sfiles: %" PRIi64 "\n", indent, statvfs->files);
  printf ("%sffree: %" PRIi64 "\n", indent, statvfs->ffree);
  printf ("%sfavail: %" PRIi64 "\n", indent, statvfs->favail);
  printf ("%sfsid: %" PRIi64 "\n", indent, statvfs->fsid);
  printf ("%sflag: %" PRIi64 "\n", indent, statvfs->flag);
  printf ("%snamemax: %" PRIi64 "\n", indent, statvfs->namemax);
}

static void
print_dirent_indent (struct guestfs_dirent *dirent, const char *indent)
{
  printf ("%sino: %" PRIi64 "\n", indent, dirent->ino);
  printf ("%sftyp: %c\n", indent, dirent->ftyp);
  printf ("%sname: %s\n", indent, dirent->name);
}

static void
print_version_indent (struct guestfs_version *version, const char *indent)
{
  printf ("%smajor: %" PRIi64 "\n", indent, version->major);
  printf ("%sminor: %" PRIi64 "\n", indent, version->minor);
  printf ("%srelease: %" PRIi64 "\n", indent, version->release);
  printf ("%sextra: %s\n", indent, version->extra);
}

static void
print_xattr_indent (struct guestfs_xattr *xattr, const char *indent)
{
  unsigned int i;

  printf ("%sattrname: %s\n", indent, xattr->attrname);
  printf ("%sattrval: ", indent);
  for (i = 0; i < xattr->attrval_len; ++i)
    if (c_isprint (xattr->attrval[i]))
      printf ("%c", xattr->attrval[i]);
    else
      printf ("\\x%02x", xattr->attrval[i]);
  printf ("\n");
}

static void
print_inotify_event_indent (struct guestfs_inotify_event *inotify_event, const char *indent)
{
  printf ("%sin_wd: %" PRIi64 "\n", indent, inotify_event->in_wd);
  printf ("%sin_mask: %" PRIu32 "\n", indent, inotify_event->in_mask);
  printf ("%sin_cookie: %" PRIu32 "\n", indent, inotify_event->in_cookie);
  printf ("%sin_name: %s\n", indent, inotify_event->in_name);
}

static void
print_partition_indent (struct guestfs_partition *partition, const char *indent)
{
  printf ("%spart_num: %" PRIi32 "\n", indent, partition->part_num);
  printf ("%spart_start: %" PRIu64 "\n", indent, partition->part_start);
  printf ("%spart_end: %" PRIu64 "\n", indent, partition->part_end);
  printf ("%spart_size: %" PRIu64 "\n", indent, partition->part_size);
}

static void
print_application_indent (struct guestfs_application *application, const char *indent)
{
  printf ("%sapp_name: %s\n", indent, application->app_name);
  printf ("%sapp_display_name: %s\n", indent, application->app_display_name);
  printf ("%sapp_epoch: %" PRIi32 "\n", indent, application->app_epoch);
  printf ("%sapp_version: %s\n", indent, application->app_version);
  printf ("%sapp_release: %s\n", indent, application->app_release);
  printf ("%sapp_install_path: %s\n", indent, application->app_install_path);
  printf ("%sapp_trans_path: %s\n", indent, application->app_trans_path);
  printf ("%sapp_publisher: %s\n", indent, application->app_publisher);
  printf ("%sapp_url: %s\n", indent, application->app_url);
  printf ("%sapp_source_package: %s\n", indent, application->app_source_package);
  printf ("%sapp_summary: %s\n", indent, application->app_summary);
  printf ("%sapp_description: %s\n", indent, application->app_description);
}

static void
print_lvm_vg_list (struct guestfs_lvm_vg_list *lvm_vgs)
{
  unsigned int i;

  for (i = 0; i < lvm_vgs->len; ++i) {
    printf ("[%d] = {\n", i);
    print_lvm_vg_indent (&lvm_vgs->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_stat_list (struct guestfs_stat_list *stats)
{
  unsigned int i;

  for (i = 0; i < stats->len; ++i) {
    printf ("[%d] = {\n", i);
    print_stat_indent (&stats->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_dirent_list (struct guestfs_dirent_list *dirents)
{
  unsigned int i;

  for (i = 0; i < dirents->len; ++i) {
    printf ("[%d] = {\n", i);
    print_dirent_indent (&dirents->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_partition_list (struct guestfs_partition_list *partitions)
{
  unsigned int i;

  for (i = 0; i < partitions->len; ++i) {
    printf ("[%d] = {\n", i);
    print_partition_indent (&partitions->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_lvm_lv_list (struct guestfs_lvm_lv_list *lvm_lvs)
{
  unsigned int i;

  for (i = 0; i < lvm_lvs->len; ++i) {
    printf ("[%d] = {\n", i);
    print_lvm_lv_indent (&lvm_lvs->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_xattr_list (struct guestfs_xattr_list *xattrs)
{
  unsigned int i;

  for (i = 0; i < xattrs->len; ++i) {
    printf ("[%d] = {\n", i);
    print_xattr_indent (&xattrs->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_lvm_pv_list (struct guestfs_lvm_pv_list *lvm_pvs)
{
  unsigned int i;

  for (i = 0; i < lvm_pvs->len; ++i) {
    printf ("[%d] = {\n", i);
    print_lvm_pv_indent (&lvm_pvs->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_application_list (struct guestfs_application_list *applications)
{
  unsigned int i;

  for (i = 0; i < applications->len; ++i) {
    printf ("[%d] = {\n", i);
    print_application_indent (&applications->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_inotify_event_list (struct guestfs_inotify_event_list *inotify_events)
{
  unsigned int i;

  for (i = 0; i < inotify_events->len; ++i) {
    printf ("[%d] = {\n", i);
    print_inotify_event_indent (&inotify_events->val[i], "  ");
    printf ("}\n");
  }
}

static void
print_stat (struct guestfs_stat *stat)
{
  print_stat_indent (stat, "");
}

static void
print_statvfs (struct guestfs_statvfs *statvfs)
{
  print_statvfs_indent (statvfs, "");
}

static void
print_version (struct guestfs_version *version)
{
  print_version_indent (version, "");
}

static void
print_int_bool (struct guestfs_int_bool *int_bool)
{
  print_int_bool_indent (int_bool, "");
}

static int
run_launch (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_launch (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_kill_subprocess (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_kill_subprocess (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_add_drive (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];
  r = guestfs_add_drive (g, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_add_cdrom (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];
  r = guestfs_add_cdrom (g, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_add_drive_ro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];
  r = guestfs_add_drive_ro (g, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_config (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *qemuparam;
  const char *qemuvalue;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  qemuparam = argv[i++];
  qemuvalue = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_config (g, qemuparam, qemuvalue);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_set_qemu (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *qemu;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  qemu = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_qemu (g, qemu);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_qemu (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  const char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_qemu (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_path (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *searchpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  searchpath = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_path (g, searchpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_path (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  const char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_path (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_append (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *append;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  append = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_set_append (g, append);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_append (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  const char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_append (g);
  ret = 0;
  printf ("%s\n", r ? : "(null)");
 out_noargs:
  return ret;
}

static int
run_set_autosync (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int autosync;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  autosync = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_autosync (g, autosync);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_autosync (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_autosync (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_verbose (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int verbose;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  verbose = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_verbose (g, verbose);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_verbose (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_verbose (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_is_ready (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_is_ready (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_is_config (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_is_config (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_is_launching (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_is_launching (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_is_busy (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_is_busy (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_get_state (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_state (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_memsize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int memsize;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "memsize", "xstrtoll", xerr);
      goto out_memsize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "memsize");
      goto out_memsize;
    }
    /* The check above should ensure this assignment does not overflow. */
    memsize = r;
  }
  r = guestfs_set_memsize (g, memsize);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_memsize:
 out_noargs:
  return ret;
}

static int
run_get_memsize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_memsize (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_get_pid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_pid (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_version (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_version *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_version (g);
  if (r == NULL) goto out;
  ret = 0;
  print_version (r);
  guestfs_free_version (r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_selinux (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int selinux;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  selinux = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_selinux (g, selinux);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_selinux (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_selinux (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_trace (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int trace;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  trace = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_trace (g, trace);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_trace (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_trace (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_direct (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int direct;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  direct = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_direct (g, direct);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_direct (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_direct (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_recovery_proc (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int recoveryproc;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  recoveryproc = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_recovery_proc (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_recovery_proc (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_add_drive_with_if (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  const char *iface;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];
  iface = argv[i++];
  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_add_drive_ro_with_if (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  const char *iface;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];
  iface = argv[i++];
  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_file_architecture (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *filename;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  r = guestfs_file_architecture (g, filename);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (filename);
 out_filename:
 out_noargs:
  return ret;
}

static int
run_inspect_os (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_inspect_os (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_type (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_arch (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_distro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_major_version (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_minor_version (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_product_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_mountpoints (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_filesystems (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_filesystems (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_network (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int network;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  network = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_network (g, network);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_network (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_network (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_list_filesystems (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_filesystems (g);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_add_drive_opts (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *filename;
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 5) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "readonly:")) {
      optargs_s.readonly = is_true (&argv[i][9]) ? 1 : 0;
      this_mask = GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      this_arg = "readonly";
    }
    else if (STRPREFIX (argv[i], "format:")) {
      optargs_s.format = &argv[i][7];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      this_arg = "format";
    }
    else if (STRPREFIX (argv[i], "iface:")) {
      optargs_s.iface = &argv[i][6];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      this_arg = "iface";
    }
    else if (STRPREFIX (argv[i], "name:")) {
      optargs_s.name = &argv[i][5];
      this_mask = GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      this_arg = "name";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_windows_systemroot (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_roots (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_inspect_get_roots (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_debug_cmdline (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_debug_cmdline (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_debug_drives (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_debug_drives (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_add_domain (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *dom;
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 7) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 7);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  dom = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "libvirturi:")) {
      optargs_s.libvirturi = &argv[i][11];
      this_mask = GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      this_arg = "libvirturi";
    }
    else if (STRPREFIX (argv[i], "readonly:")) {
      optargs_s.readonly = is_true (&argv[i][9]) ? 1 : 0;
      this_mask = GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      this_arg = "readonly";
    }
    else if (STRPREFIX (argv[i], "iface:")) {
      optargs_s.iface = &argv[i][6];
      this_mask = GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      this_arg = "iface";
    }
    else if (STRPREFIX (argv[i], "live:")) {
      optargs_s.live = is_true (&argv[i][5]) ? 1 : 0;
      this_mask = GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      this_arg = "live";
    }
    else if (STRPREFIX (argv[i], "allowuuid:")) {
      optargs_s.allowuuid = is_true (&argv[i][10]) ? 1 : 0;
      this_mask = GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      this_arg = "allowuuid";
    }
    else if (STRPREFIX (argv[i], "readonlydisk:")) {
      optargs_s.readonlydisk = &argv[i][13];
      this_mask = GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      this_arg = "readonlydisk";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_add_domain_argv (g, dom, optargs);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_package_format (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_package_management (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_list_applications (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_application_list *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_application_list (r);
  guestfs_free_application_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_hostname (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_format (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_format (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_is_live (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_is_live (g, root);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_is_netinst (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_is_multipart (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_attach_method (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *attachmethod;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  attachmethod = argv[i++];
  r = guestfs_set_attach_method (g, attachmethod);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_attach_method (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_attach_method (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_product_variant (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_windows_current_control_set (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_drive_mappings (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *root;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];
  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inspect_get_icon (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  const char *root;
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "favicon:")) {
      optargs_s.favicon = is_true (&argv[i][8]) ? 1 : 0;
      this_mask = GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      this_arg = "favicon";
    }
    else if (STRPREFIX (argv[i], "highquality:")) {
      optargs_s.highquality = is_true (&argv[i][12]) ? 1 : 0;
      this_mask = GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      this_arg = "highquality";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_pgroup (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int pgroup;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pgroup = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_pgroup (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_pgroup (g);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_set_smp (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int smp;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "smp", "xstrtoll", xerr);
      goto out_smp;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "smp");
      goto out_smp;
    }
    /* The check above should ensure this assignment does not overflow. */
    smp = r;
  }
  r = guestfs_set_smp (g, smp);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_smp:
 out_noargs:
  return ret;
}

static int
run_get_smp (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_smp (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_mount (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount (g, device, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_sync (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_sync (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_touch (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_touch (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_cat (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_cat (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_ll (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_ll (g, directory);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_ls (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_ls (g, directory);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_list_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_devices (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_list_partitions (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_partitions (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_pvs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_pvs (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vgs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_vgs (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_lvs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_lvs (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_pvs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_lvm_pv_list *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_pvs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vgs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_lvm_vg_list *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_vgs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_lvs_full (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_lvm_lv_list *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_lvs_full (g);
  if (r == NULL) goto out;
  ret = 0;
  print_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_read_lines (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_read_lines (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_aug_init (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *root;
  int flags;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = win_prefix (argv[i++]); /* process "win:" prefix */
  if (root == NULL) goto out_root;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "flags", "xstrtoll", xerr);
      goto out_flags;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "flags");
      goto out_flags;
    }
    /* The check above should ensure this assignment does not overflow. */
    flags = r;
  }
  r = guestfs_aug_init (g, root, flags);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_flags:
  free (root);
 out_root:
 out_noargs:
  return ret;
}

static int
run_aug_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_aug_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_defvar (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *name;
  const char *expr;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  name = argv[i++];
  expr = STRNEQ (argv[i], "") ? argv[i] : NULL;
  i++;
  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_aug_defnode (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_int_bool *r;
  const char *name;
  const char *expr;
  const char *val;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  name = argv[i++];
  expr = argv[i++];
  val = argv[i++];
  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL) goto out;
  ret = 0;
  print_int_bool (r);
  guestfs_free_int_bool (r);
 out:
 out_noargs:
  return ret;
}

static int
run_aug_get (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_get (g, augpath);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_aug_set (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *augpath;
  const char *val;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  val = argv[i++];
  r = guestfs_aug_set (g, augpath, val);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_insert (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *augpath;
  const char *label;
  int before;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  label = argv[i++];
  before = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_rm (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_rm (g, augpath);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_aug_mv (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *src;
  const char *dest;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = argv[i++];
  dest = argv[i++];
  r = guestfs_aug_mv (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_match (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_match (g, augpath);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_aug_save (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_aug_save (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_load (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_aug_load (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_aug_ls (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_ls (g, augpath);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_rm (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_rm (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_rmdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_rmdir (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_rm_rf (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_rm_rf (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_mkdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mkdir (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_mkdir_p (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mkdir_p (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_chmod (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mode;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_chmod (g, mode, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_mode:
 out_noargs:
  return ret;
}

static int
run_chown (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int owner;
  int group;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "owner", "xstrtoll", xerr);
      goto out_owner;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "owner");
      goto out_owner;
    }
    /* The check above should ensure this assignment does not overflow. */
    owner = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "group", "xstrtoll", xerr);
      goto out_group;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "group");
      goto out_group;
    }
    /* The check above should ensure this assignment does not overflow. */
    group = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_chown (g, owner, group, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_group:
 out_owner:
 out_noargs:
  return ret;
}

static int
run_exists (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_exists (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_file (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_dir (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_dir (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_pvcreate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_pvcreate (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_vgcreate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *volgroup;
  char **physvols;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  volgroup = argv[i++];
  physvols = parse_string_list (argv[i++]);
  if (physvols == NULL) goto out_physvols;
  r = guestfs_vgcreate (g, volgroup, physvols);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (physvols);
 out_physvols:
 out_noargs:
  return ret;
}

static int
run_lvcreate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *logvol;
  const char *volgroup;
  int mbytes;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  logvol = argv[i++];
  volgroup = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mbytes", "xstrtoll", xerr);
      goto out_mbytes;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mbytes");
      goto out_mbytes;
    }
    /* The check above should ensure this assignment does not overflow. */
    mbytes = r;
  }
  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mbytes:
 out_noargs:
  return ret;
}

static int
run_mkfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  device = argv[i++];
  r = guestfs_mkfs (g, fstype, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_sfdisk (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  char **lines;
  size_t i = 0;

  if (argc != 5) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "cyls", "xstrtoll", xerr);
      goto out_cyls;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "cyls");
      goto out_cyls;
    }
    /* The check above should ensure this assignment does not overflow. */
    cyls = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "heads", "xstrtoll", xerr);
      goto out_heads;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "heads");
      goto out_heads;
    }
    /* The check above should ensure this assignment does not overflow. */
    heads = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "sectors", "xstrtoll", xerr);
      goto out_sectors;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "sectors");
      goto out_sectors;
    }
    /* The check above should ensure this assignment does not overflow. */
    sectors = r;
  }
  lines = parse_string_list (argv[i++]);
  if (lines == NULL) goto out_lines;
  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (lines);
 out_lines:
 out_sectors:
 out_heads:
 out_cyls:
 out_noargs:
  return ret;
}

static int
run_write_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  const char *content;
  int size;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "size");
      goto out_size;
    }
    /* The check above should ensure this assignment does not overflow. */
    size = r;
  }
  r = guestfs_write_file (g, path, content, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_umount (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *pathordevice;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pathordevice = argv[i++];
  r = guestfs_umount (g, pathordevice);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mounts (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_mounts (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_umount_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_umount_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_lvm_remove_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_lvm_remove_all (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_file (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_command (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char **arguments;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  arguments = parse_string_list (argv[i++]);
  if (arguments == NULL) goto out_arguments;
  r = guestfs_command (g, arguments);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free_strings (arguments);
 out_arguments:
 out_noargs:
  return ret;
}

static int
run_command_lines (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char **arguments;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  arguments = parse_string_list (argv[i++]);
  if (arguments == NULL) goto out_arguments;
  r = guestfs_command_lines (g, arguments);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free_strings (arguments);
 out_arguments:
 out_noargs:
  return ret;
}

static int
run_stat (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_stat *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_stat (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_stat (r);
  guestfs_free_stat (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lstat (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_stat *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lstat (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_stat (r);
  guestfs_free_stat (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_statvfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_statvfs *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_statvfs (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_statvfs (r);
  guestfs_free_statvfs (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_tune2fs_l (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_tune2fs_l (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_setro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_setro (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_setrw (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_setrw (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_getro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getro (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_getss (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getss (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_getbsz (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_setbsz (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int blocksize;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_blockdev_getsz (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int64_t r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getsz (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_getsize64 (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int64_t r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_flushbufs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_blockdev_rereadpt (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_upload (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *filename;
  char *remotefilename;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = file_in (argv[i++]);
  if (filename == NULL) goto out_filename;
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (remotefilename);
 out_remotefilename:
  free_file_in (filename);
 out_filename:
 out_noargs:
  return ret;
}

static int
run_download (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *remotefilename;
  char *filename;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;
  r = guestfs_download (g, remotefilename, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
  free (remotefilename);
 out_remotefilename:
 out_noargs:
  return ret;
}

static int
run_checksum (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *csumtype;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  csumtype = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_tar_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *tarfile;
  char *directory;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  tarfile = file_in (argv[i++]);
  if (tarfile == NULL) goto out_tarfile;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_tar_in (g, tarfile, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarfile);
 out_tarfile:
 out_noargs:
  return ret;
}

static int
run_tar_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *directory;
  char *tarfile;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = argv[i++];
  tarfile = file_out (argv[i++]);
  if (tarfile == NULL) goto out_tarfile;
  r = guestfs_tar_out (g, directory, tarfile);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (tarfile);
 out_tarfile:
 out_noargs:
  return ret;
}

static int
run_tgz_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *tarball;
  char *directory;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  tarball = file_in (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarball);
 out_tarball:
 out_noargs:
  return ret;
}

static int
run_tgz_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *directory;
  char *tarball;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  tarball = file_out (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (tarball);
 out_tarball:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_mount_ro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount_ro (g, device, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mount_options (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *options;
  const char *device;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  options = argv[i++];
  device = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount_options (g, options, device, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mount_vfs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *options;
  const char *vfstype;
  const char *device;
  const char *mountpoint;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  options = argv[i++];
  vfstype = argv[i++];
  device = argv[i++];
  mountpoint = argv[i++];
  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_debug (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *subcmd;
  char **extraargs;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  subcmd = argv[i++];
  extraargs = parse_string_list (argv[i++]);
  if (extraargs == NULL) goto out_extraargs;
  r = guestfs_debug (g, subcmd, extraargs);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free_strings (extraargs);
 out_extraargs:
 out_noargs:
  return ret;
}

static int
run_lvremove (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_lvremove (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_vgremove (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vgremove (g, vgname);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_pvremove (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_pvremove (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_set_e2label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *label;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  label = argv[i++];
  r = guestfs_set_e2label (g, device, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_e2label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_get_e2label (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_set_e2uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *uuid;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  uuid = argv[i++];
  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_e2uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_get_e2uuid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_fsck (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  device = argv[i++];
  r = guestfs_fsck (g, fstype, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%x\n", r != 0 ? "0x" : "", r);
 out:
 out_noargs:
  return ret;
}

static int
run_zero (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_zero (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_grub_install (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *root;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  root = win_prefix (argv[i++]); /* process "win:" prefix */
  if (root == NULL) goto out_root;
  device = argv[i++];
  r = guestfs_grub_install (g, root, device);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (root);
 out_root:
 out_noargs:
  return ret;
}

static int
run_cp (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  r = guestfs_cp (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_cp_a (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  r = guestfs_cp_a (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_mv (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  r = guestfs_mv (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_drop_caches (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int whattodrop;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "whattodrop", "xstrtoll", xerr);
      goto out_whattodrop;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "whattodrop");
      goto out_whattodrop;
    }
    /* The check above should ensure this assignment does not overflow. */
    whattodrop = r;
  }
  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_whattodrop:
 out_noargs:
  return ret;
}

static int
run_dmesg (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_dmesg (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_ping_daemon (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_ping_daemon (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_equal (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *file1;
  char *file2;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file1 = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file1 == NULL) goto out_file1;
  file2 = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file2 == NULL) goto out_file2;
  r = guestfs_equal (g, file1, file2);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (file2);
 out_file2:
  free (file1);
 out_file1:
 out_noargs:
  return ret;
}

static int
run_strings (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_strings (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_strings_e (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *encoding;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  encoding = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_hexdump (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_hexdump (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zerofree (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_zerofree (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_pvresize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_pvresize (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_sfdisk_N (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;
  size_t i = 0;

  if (argc != 6) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 6);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "cyls", "xstrtoll", xerr);
      goto out_cyls;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "cyls");
      goto out_cyls;
    }
    /* The check above should ensure this assignment does not overflow. */
    cyls = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "heads", "xstrtoll", xerr);
      goto out_heads;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "heads");
      goto out_heads;
    }
    /* The check above should ensure this assignment does not overflow. */
    heads = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "sectors", "xstrtoll", xerr);
      goto out_sectors;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "sectors");
      goto out_sectors;
    }
    /* The check above should ensure this assignment does not overflow. */
    sectors = r;
  }
  line = argv[i++];
  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_sectors:
 out_heads:
 out_cyls:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_sfdisk_l (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_sfdisk_l (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_sfdisk_kernel_geometry (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_sfdisk_disk_geometry (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vg_activate_all (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int activate;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  activate = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_vg_activate_all (g, activate);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_vg_activate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int activate;
  char **volgroups;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  activate = is_true (argv[i++]) ? 1 : 0;
  volgroups = parse_string_list (argv[i++]);
  if (volgroups == NULL) goto out_volgroups;
  r = guestfs_vg_activate (g, activate, volgroups);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (volgroups);
 out_volgroups:
 out_noargs:
  return ret;
}

static int
run_lvresize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int mbytes;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mbytes", "xstrtoll", xerr);
      goto out_mbytes;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mbytes");
      goto out_mbytes;
    }
    /* The check above should ensure this assignment does not overflow. */
    mbytes = r;
  }
  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mbytes:
 out_noargs:
  return ret;
}

static int
run_resize2fs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_resize2fs (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_find (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *directory;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_find (g, directory);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_e2fsck_f (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_e2fsck_f (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_sleep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int secs;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "secs", "xstrtoll", xerr);
      goto out_secs;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "secs");
      goto out_secs;
    }
    /* The check above should ensure this assignment does not overflow. */
    secs = r;
  }
  r = guestfs_sleep (g, secs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_secs:
 out_noargs:
  return ret;
}

static int
run_ntfs_3g_probe (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int rw;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  rw = is_true (argv[i++]) ? 1 : 0;
  device = argv[i++];
  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_sh (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *command;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  command = argv[i++];
  r = guestfs_sh (g, command);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_sh_lines (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *command;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  command = argv[i++];
  r = guestfs_sh_lines (g, command);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_glob_expand (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *pattern;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = win_prefix (argv[i++]); /* process "win:" prefix */
  if (pattern == NULL) goto out_pattern;
  r = guestfs_glob_expand (g, pattern);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (pattern);
 out_pattern:
 out_noargs:
  return ret;
}

static int
run_scrub_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_scrub_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_scrub_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_scrub_file (g, file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_scrub_freespace (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *dir;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  r = guestfs_scrub_freespace (g, dir);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

static int
run_mkdtemp (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *tmpl;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  tmpl = win_prefix (argv[i++]); /* process "win:" prefix */
  if (tmpl == NULL) goto out_tmpl;
  r = guestfs_mkdtemp (g, tmpl);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (tmpl);
 out_tmpl:
 out_noargs:
  return ret;
}

static int
run_wc_l (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_wc_l (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_wc_w (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_wc_w (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_wc_c (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_wc_c (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_head (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_head (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_head_n (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  int nrlines;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "nrlines", "xstrtoll", xerr);
      goto out_nrlines;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "nrlines");
      goto out_nrlines;
    }
    /* The check above should ensure this assignment does not overflow. */
    nrlines = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_nrlines:
 out_noargs:
  return ret;
}

static int
run_tail (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_tail (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_tail_n (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  int nrlines;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "nrlines", "xstrtoll", xerr);
      goto out_nrlines;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "nrlines");
      goto out_nrlines;
    }
    /* The check above should ensure this assignment does not overflow. */
    nrlines = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_nrlines:
 out_noargs:
  return ret;
}

static int
run_df (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_df (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_df_h (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_df_h (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_du (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int64_t r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_du (g, path);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_initrd_list (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_initrd_list (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_mount_loop (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *file;
  char *mountpoint;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  mountpoint = win_prefix (argv[i++]); /* process "win:" prefix */
  if (mountpoint == NULL) goto out_mountpoint;
  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mountpoint);
 out_mountpoint:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_mkswap (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_mkswap (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mkswap_L (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *label;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  label = argv[i++];
  device = argv[i++];
  r = guestfs_mkswap_L (g, label, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mkswap_U (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *uuid;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  uuid = argv[i++];
  device = argv[i++];
  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mknod (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mode;
  int devmajor;
  int devminor;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devmajor", "xstrtoll", xerr);
      goto out_devmajor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devmajor");
      goto out_devmajor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devmajor = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devminor", "xstrtoll", xerr);
      goto out_devminor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devminor");
      goto out_devminor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devminor = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_devminor:
 out_devmajor:
 out_mode:
 out_noargs:
  return ret;
}

static int
run_mkfifo (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mode;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mkfifo (g, mode, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_mode:
 out_noargs:
  return ret;
}

static int
run_mknod_b (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mode;
  int devmajor;
  int devminor;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devmajor", "xstrtoll", xerr);
      goto out_devmajor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devmajor");
      goto out_devmajor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devmajor = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devminor", "xstrtoll", xerr);
      goto out_devminor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devminor");
      goto out_devminor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devminor = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_devminor:
 out_devmajor:
 out_mode:
 out_noargs:
  return ret;
}

static int
run_mknod_c (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mode;
  int devmajor;
  int devminor;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devmajor", "xstrtoll", xerr);
      goto out_devmajor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devmajor");
      goto out_devmajor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devmajor = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "devminor", "xstrtoll", xerr);
      goto out_devminor;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "devminor");
      goto out_devminor;
    }
    /* The check above should ensure this assignment does not overflow. */
    devminor = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_devminor:
 out_devmajor:
 out_mode:
 out_noargs:
  return ret;
}

static int
run_umask (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int mask;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mask", "xstrtoll", xerr);
      goto out_mask;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mask");
      goto out_mask;
    }
    /* The check above should ensure this assignment does not overflow. */
    mask = r;
  }
  r = guestfs_umask (g, mask);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%o\n", r != 0 ? "0" : "", r);
 out:
 out_mask:
 out_noargs:
  return ret;
}

static int
run_readdir (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_dirent_list *r;
  char *dir;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  dir = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dir == NULL) goto out_dir;
  r = guestfs_readdir (g, dir);
  if (r == NULL) goto out;
  ret = 0;
  print_dirent_list (r);
  guestfs_free_dirent_list (r);
 out:
  free (dir);
 out_dir:
 out_noargs:
  return ret;
}

static int
run_sfdiskM (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char **lines;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  lines = parse_string_list (argv[i++]);
  if (lines == NULL) goto out_lines;
  r = guestfs_sfdiskM (g, device, lines);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (lines);
 out_lines:
 out_noargs:
  return ret;
}

static int
run_zfile (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *meth;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  meth = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zfile (g, meth, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_getxattrs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_xattr_list *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_getxattrs (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_xattr_list (r);
  guestfs_free_xattr_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lgetxattrs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_xattr_list *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lgetxattrs (g, path);
  if (r == NULL) goto out;
  ret = 0;
  print_xattr_list (r);
  guestfs_free_xattr_list (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_setxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  xattr = argv[i++];
  val = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "vallen", "xstrtoll", xerr);
      goto out_vallen;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "vallen");
      goto out_vallen;
    }
    /* The check above should ensure this assignment does not overflow. */
    vallen = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_vallen:
 out_noargs:
  return ret;
}

static int
run_lsetxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  char *path;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  xattr = argv[i++];
  val = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "vallen", "xstrtoll", xerr);
      goto out_vallen;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "vallen");
      goto out_vallen;
    }
    /* The check above should ensure this assignment does not overflow. */
    vallen = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_vallen:
 out_noargs:
  return ret;
}

static int
run_removexattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *xattr;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  xattr = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_removexattr (g, xattr, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lremovexattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *xattr;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  xattr = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_mountpoints (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_mountpoints (g);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_mkmountpoint (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *exemptpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  exemptpath = argv[i++];
  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_rmmountpoint (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *exemptpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  exemptpath = argv[i++];
  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_read_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_read_file (g, path, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_grep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_grep (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_egrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_egrep (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_fgrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *pattern;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_grepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_grepi (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_egrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_egrepi (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_fgrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *pattern;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zgrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zgrep (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zegrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zegrep (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zfgrep (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *pattern;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zgrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zegrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *regex;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  regex = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_zfgrepi (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *pattern;
  char *path;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = argv[i++];
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_realpath (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_realpath (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_ln (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

static int
run_ln_f (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln_f (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

static int
run_ln_s (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln_s (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

static int
run_ln_sf (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *target;
  char *linkname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  target = argv[i++];
  linkname = win_prefix (argv[i++]); /* process "win:" prefix */
  if (linkname == NULL) goto out_linkname;
  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (linkname);
 out_linkname:
 out_noargs:
  return ret;
}

static int
run_readlink (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_readlink (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_fallocate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  int len;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "len");
      goto out_len;
    }
    /* The check above should ensure this assignment does not overflow. */
    len = r;
  }
  r = guestfs_fallocate (g, path, len);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_len:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_swapon_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_swapon_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_swapoff_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_swapoff_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_swapon_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_swapon_file (g, file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_swapoff_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_swapoff_file (g, file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_swapon_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *label;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  label = argv[i++];
  r = guestfs_swapon_label (g, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_swapoff_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *label;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  label = argv[i++];
  r = guestfs_swapoff_label (g, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_swapon_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *uuid;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  uuid = argv[i++];
  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_swapoff_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *uuid;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  uuid = argv[i++];
  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_mkswap_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_mkswap_file (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_inotify_init (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int maxevents;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "maxevents", "xstrtoll", xerr);
      goto out_maxevents;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "maxevents");
      goto out_maxevents;
    }
    /* The check above should ensure this assignment does not overflow. */
    maxevents = r;
  }
  r = guestfs_inotify_init (g, maxevents);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_maxevents:
 out_noargs:
  return ret;
}

static int
run_inotify_add_watch (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int64_t r;
  char *path;
  int mask;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mask", "xstrtoll", xerr);
      goto out_mask;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mask");
      goto out_mask;
    }
    /* The check above should ensure this assignment does not overflow. */
    mask = r;
  }
  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
 out_mask:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_inotify_rm_watch (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int wd;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "wd", "xstrtoll", xerr);
      goto out_wd;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "wd");
      goto out_wd;
    }
    /* The check above should ensure this assignment does not overflow. */
    wd = r;
  }
  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_wd:
 out_noargs:
  return ret;
}

static int
run_inotify_read (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_inotify_event_list *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_inotify_read (g);
  if (r == NULL) goto out;
  ret = 0;
  print_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inotify_files (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_inotify_files (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_inotify_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_inotify_close (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_setcon (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *context;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  context = argv[i++];
  r = guestfs_setcon (g, context);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_getcon (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_getcon (g);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_mkfs_b (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  device = argv[i++];
  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2journal (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int blocksize;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  device = argv[i++];
  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2journal_L (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int blocksize;
  const char *label;
  const char *device;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  label = argv[i++];
  device = argv[i++];
  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2journal_U (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int blocksize;
  const char *uuid;
  const char *device;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  uuid = argv[i++];
  device = argv[i++];
  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2fs_J (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *journal;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  device = argv[i++];
  journal = argv[i++];
  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2fs_JL (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *label;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  device = argv[i++];
  label = argv[i++];
  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_mke2fs_JU (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *uuid;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "blocksize", "xstrtoll", xerr);
      goto out_blocksize;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "blocksize");
      goto out_blocksize;
    }
    /* The check above should ensure this assignment does not overflow. */
    blocksize = r;
  }
  device = argv[i++];
  uuid = argv[i++];
  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_blocksize:
 out_noargs:
  return ret;
}

static int
run_modprobe (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *modulename;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  modulename = argv[i++];
  r = guestfs_modprobe (g, modulename);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_echo_daemon (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char **words;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  words = parse_string_list (argv[i++]);
  if (words == NULL) goto out_words;
  r = guestfs_echo_daemon (g, words);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free_strings (words);
 out_words:
 out_noargs:
  return ret;
}

static int
run_find0 (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *directory;
  char *files;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  files = file_out (argv[i++]);
  if (files == NULL) goto out_files;
  r = guestfs_find0 (g, directory, files);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (files);
 out_files:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_case_sensitive_path (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_vfs_type (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_vfs_type (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_truncate (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_truncate (g, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_truncate_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_truncate_size (g, path, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_utimens (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;
  size_t i = 0;

  if (argc != 5) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "atsecs", "xstrtoll", xerr);
      goto out_atsecs;
    }
    atsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "atnsecs", "xstrtoll", xerr);
      goto out_atnsecs;
    }
    atnsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mtsecs", "xstrtoll", xerr);
      goto out_mtsecs;
    }
    mtsecs = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mtnsecs", "xstrtoll", xerr);
      goto out_mtnsecs;
    }
    mtnsecs = r;
  }
  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mtnsecs:
 out_mtsecs:
 out_atnsecs:
 out_atsecs:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_mkdir_mode (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  int mode;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mode:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lchown (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int owner;
  int group;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "owner", "xstrtoll", xerr);
      goto out_owner;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "owner");
      goto out_owner;
    }
    /* The check above should ensure this assignment does not overflow. */
    owner = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "group", "xstrtoll", xerr);
      goto out_group;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "group");
      goto out_group;
    }
    /* The check above should ensure this assignment does not overflow. */
    group = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_lchown (g, owner, group, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_group:
 out_owner:
 out_noargs:
  return ret;
}

static int
run_lstatlist (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_stat_list *r;
  char *path;
  char **names;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  names = parse_string_list (argv[i++]);
  if (names == NULL) goto out_names;
  r = guestfs_lstatlist (g, path, names);
  if (r == NULL) goto out;
  ret = 0;
  print_stat_list (r);
  guestfs_free_stat_list (r);
 out:
  free_strings (names);
 out_names:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lxattrlist (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_xattr_list *r;
  char *path;
  char **names;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  names = parse_string_list (argv[i++]);
  if (names == NULL) goto out_names;
  r = guestfs_lxattrlist (g, path, names);
  if (r == NULL) goto out;
  ret = 0;
  print_xattr_list (r);
  guestfs_free_xattr_list (r);
 out:
  free_strings (names);
 out_names:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_readlinklist (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  char *path;
  char **names;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  names = parse_string_list (argv[i++]);
  if (names == NULL) goto out_names;
  r = guestfs_readlinklist (g, path, names);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
  free_strings (names);
 out_names:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_pread (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  char *path;
  int count;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "count", "xstrtoll", xerr);
      goto out_count;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "count");
      goto out_count;
    }
    /* The check above should ensure this assignment does not overflow. */
    count = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_offset:
 out_count:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_part_init (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *parttype;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  parttype = argv[i++];
  r = guestfs_part_init (g, device, parttype);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_part_add (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  prlogex = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "startsect", "xstrtoll", xerr);
      goto out_startsect;
    }
    startsect = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "endsect", "xstrtoll", xerr);
      goto out_endsect;
    }
    endsect = r;
  }
  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_endsect:
 out_startsect:
 out_noargs:
  return ret;
}

static int
run_part_disk (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *parttype;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  parttype = argv[i++];
  r = guestfs_part_disk (g, device, parttype);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_part_set_bootable (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  int bootable;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  bootable = is_true (argv[i++]) ? 1 : 0;
  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_part_set_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  const char *name;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  name = argv[i++];
  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_part_list (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  struct guestfs_partition_list *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_part_list (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_partition_list (r);
  guestfs_free_partition_list (r);
 out:
 out_noargs:
  return ret;
}

static int
run_part_get_parttype (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_part_get_parttype (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_fill (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  int c;
  int len;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "c", "xstrtoll", xerr);
      goto out_c;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "c");
      goto out_c;
    }
    /* The check above should ensure this assignment does not overflow. */
    c = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "len");
      goto out_len;
    }
    /* The check above should ensure this assignment does not overflow. */
    len = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fill (g, c, len, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_len:
 out_c:
 out_noargs:
  return ret;
}

static int
run_available (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char **groups;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  groups = parse_string_list (argv[i++]);
  if (groups == NULL) goto out_groups;
  r = guestfs_available (g, groups);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (groups);
 out_groups:
 out_noargs:
  return ret;
}

static int
run_dd (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  r = guestfs_dd (g, src, dest);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_filesize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int64_t r;
  char *file;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  r = guestfs_filesize (g, file);
  if (r == -1) goto out;
  ret = 0;
  printf ("%" PRIi64 "\n", r);
 out:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_lvrename (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *logvol;
  const char *newlogvol;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  logvol = argv[i++];
  newlogvol = argv[i++];
  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_vgrename (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *volgroup;
  const char *newvolgroup;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  volgroup = argv[i++];
  newvolgroup = argv[i++];
  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_initrd_cat (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  char *initrdpath;
  const char *filename;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  initrdpath = win_prefix (argv[i++]); /* process "win:" prefix */
  if (initrdpath == NULL) goto out_initrdpath;
  filename = argv[i++];
  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (initrdpath);
 out_initrdpath:
 out_noargs:
  return ret;
}

static int
run_pvuuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_pvuuid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vguuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vguuid (g, vgname);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_lvuuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_lvuuid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vgpvuuids (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vglvuuids (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *vgname;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  vgname = argv[i++];
  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_copy_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  int64_t size;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_zero_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_zero_device (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_txz_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *tarball;
  char *directory;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  tarball = file_in (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (directory);
 out_directory:
  free_file_in (tarball);
 out_tarball:
 out_noargs:
  return ret;
}

static int
run_txz_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *directory;
  char *tarball;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  tarball = file_out (argv[i++]);
  if (tarball == NULL) goto out_tarball;
  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (tarball);
 out_tarball:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_ntfsresize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_ntfsresize (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_vgscan (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_vgscan (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_part_del (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  r = guestfs_part_del (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_part_get_bootable (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_part_get_mbr_id (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%x\n", r != 0 ? "0x" : "", r);
 out:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_part_set_mbr_id (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int partnum;
  int idbyte;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "partnum", "xstrtoll", xerr);
      goto out_partnum;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "partnum");
      goto out_partnum;
    }
    /* The check above should ensure this assignment does not overflow. */
    partnum = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "idbyte", "xstrtoll", xerr);
      goto out_idbyte;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "idbyte");
      goto out_idbyte;
    }
    /* The check above should ensure this assignment does not overflow. */
    idbyte = r;
  }
  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_idbyte:
 out_partnum:
 out_noargs:
  return ret;
}

static int
run_checksum_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *csumtype;
  const char *device;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  csumtype = argv[i++];
  device = argv[i++];
  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_lvresize_free (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *lv;
  int percent;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  lv = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "percent", "xstrtoll", xerr);
      goto out_percent;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "percent");
      goto out_percent;
    }
    /* The check above should ensure this assignment does not overflow. */
    percent = r;
  }
  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_percent:
 out_noargs:
  return ret;
}

static int
run_aug_clear (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *augpath;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  augpath = argv[i++];
  r = guestfs_aug_clear (g, augpath);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_get_umask (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_get_umask (g);
  if (r == -1) goto out;
  ret = 0;
  printf ("%s%o\n", r != 0 ? "0" : "", r);
 out:
 out_noargs:
  return ret;
}

static int
run_debug_upload (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *filename;
  const char *tmpname;
  int mode;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = file_in (argv[i++]);
  if (filename == NULL) goto out_filename;
  tmpname = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "mode", "xstrtoll", xerr);
      goto out_mode;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "mode");
      goto out_mode;
    }
    /* The check above should ensure this assignment does not overflow. */
    mode = r;
  }
  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_mode:
  free_file_in (filename);
 out_filename:
 out_noargs:
  return ret;
}

static int
run_base64_in (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *base64file;
  char *filename;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  base64file = file_in (argv[i++]);
  if (base64file == NULL) goto out_base64file;
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (filename);
 out_filename:
  free_file_in (base64file);
 out_base64file:
 out_noargs:
  return ret;
}

static int
run_base64_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *filename;
  char *base64file;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (filename == NULL) goto out_filename;
  base64file = file_out (argv[i++]);
  if (base64file == NULL) goto out_base64file;
  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (base64file);
 out_base64file:
  free (filename);
 out_filename:
 out_noargs:
  return ret;
}

static int
run_checksums_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *csumtype;
  char *directory;
  char *sumsfile;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  csumtype = argv[i++];
  directory = win_prefix (argv[i++]); /* process "win:" prefix */
  if (directory == NULL) goto out_directory;
  sumsfile = file_out (argv[i++]);
  if (sumsfile == NULL) goto out_sumsfile;
  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (sumsfile);
 out_sumsfile:
  free (directory);
 out_directory:
 out_noargs:
  return ret;
}

static int
run_fill_pattern (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *pattern;
  int len;
  char *path;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  pattern = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "len");
      goto out_len;
    }
    /* The check above should ensure this assignment does not overflow. */
    len = r;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_len:
 out_noargs:
  return ret;
}

static int
run_write (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  const char *content;
  size_t content_size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
  r = guestfs_write (g, path, content, content_size);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_pwrite (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  const char *content;
  size_t content_size;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_offset:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_resize2fs_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

static int
run_pvresize_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_pvresize_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

static int
run_ntfsresize_size (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  int64_t size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_noargs:
  return ret;
}

static int
run_available_all_groups (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_available_all_groups (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_fallocate64 (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  int64_t len;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "len", "xstrtoll", xerr);
      goto out_len;
    }
    len = r;
  }
  r = guestfs_fallocate64 (g, path, len);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_len:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_vfs_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_vfs_label (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_vfs_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_vfs_uuid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_lvm_set_filter (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char **devices;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;
  r = guestfs_lvm_set_filter (g, devices);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (devices);
 out_devices:
 out_noargs:
  return ret;
}

static int
run_lvm_clear_filter (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_lvm_clear_filter (g);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_luks_open (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  const char *mapname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  mapname = argv[i++];
  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_luks_open_ro (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  const char *mapname;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  mapname = argv[i++];
  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_luks_close (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_luks_close (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_luks_format (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  int keyslot;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "keyslot", "xstrtoll", xerr);
      goto out_keyslot;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "keyslot");
      goto out_keyslot;
    }
    /* The check above should ensure this assignment does not overflow. */
    keyslot = r;
  }
  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_luks_format_cipher (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  int keyslot;
  const char *cipher;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "keyslot", "xstrtoll", xerr);
      goto out_keyslot;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "keyslot");
      goto out_keyslot;
    }
    /* The check above should ensure this assignment does not overflow. */
    keyslot = r;
  }
  cipher = argv[i++];
  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_luks_add_key (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  char *newkey;
  int keyslot;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  newkey = read_key ("newkey");
  if (keys_from_stdin)
    input_lineno++;
  if (newkey == NULL) goto out_newkey;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "keyslot", "xstrtoll", xerr);
      goto out_keyslot;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "keyslot");
      goto out_keyslot;
    }
    /* The check above should ensure this assignment does not overflow. */
    keyslot = r;
  }
  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (newkey);
 out_newkey:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_luks_kill_slot (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  char *key;
  int keyslot;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  key = read_key ("key");
  if (keys_from_stdin)
    input_lineno++;
  if (key == NULL) goto out_key;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "keyslot", "xstrtoll", xerr);
      goto out_keyslot;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "keyslot");
      goto out_keyslot;
    }
    /* The check above should ensure this assignment does not overflow. */
    keyslot = r;
  }
  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_keyslot:
  free (key);
 out_key:
 out_noargs:
  return ret;
}

static int
run_is_lv (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_is_lv (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_findfs_uuid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *uuid;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  uuid = argv[i++];
  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_findfs_label (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *label;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  label = argv[i++];
  r = guestfs_findfs_label (g, label);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_is_chardev (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_chardev (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_blockdev (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_blockdev (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_fifo (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_fifo (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_symlink (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_symlink (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_socket (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_socket (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_part_to_dev (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *partition;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  partition = argv[i++];
  r = guestfs_part_to_dev (g, partition);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_upload_offset (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *filename;
  char *remotefilename;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  filename = file_in (argv[i++]);
  if (filename == NULL) goto out_filename;
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_offset:
  free (remotefilename);
 out_remotefilename:
  free_file_in (filename);
 out_filename:
 out_noargs:
  return ret;
}

static int
run_download_offset (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *remotefilename;
  char *filename;
  int64_t offset;
  int64_t size;
  size_t i = 0;

  if (argc != 4) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  remotefilename = win_prefix (argv[i++]); /* process "win:" prefix */
  if (remotefilename == NULL) goto out_remotefilename;
  filename = file_out (argv[i++]);
  if (filename == NULL) goto out_filename;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "size", "xstrtoll", xerr);
      goto out_size;
    }
    size = r;
  }
  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_size:
 out_offset:
  free (filename);
 out_filename:
  free (remotefilename);
 out_remotefilename:
 out_noargs:
  return ret;
}

static int
run_pwrite_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  const char *content;
  size_t content_size;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_offset:
 out_noargs:
  return ret;
}

static int
run_pread_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  const char *device;
  int count;
  int64_t offset;
  size_t i = 0;

  if (argc != 3) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "count", "xstrtoll", xerr);
      goto out_count;
    }
    /* The Int type in the generator is a signed 31 bit int. */
    if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
      fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "count");
      goto out_count;
    }
    /* The check above should ensure this assignment does not overflow. */
    count = r;
  }
  {
    strtol_error xerr;
    long long r;

    xerr = xstrtoll (argv[i++], NULL, 0, &r, xstrtol_suffixes);
    if (xerr != LONGINT_OK) {
      fprintf (stderr,
               _("%s: %s: invalid integer parameter (%s returned %d)\n"),
               cmd, "offset", "xstrtoll", xerr);
      goto out_offset;
    }
    offset = r;
  }
  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
 out_offset:
 out_count:
 out_noargs:
  return ret;
}

static int
run_lvm_canonical_lv_name (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  const char *lvname;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  lvname = argv[i++];
  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL) goto out;
  ret = 0;
  printf ("%s\n", r);
  free (r);
 out:
 out_noargs:
  return ret;
}

static int
run_mkfs_opts (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *fstype;
  const char *device;
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 6) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 6);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  fstype = argv[i++];
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "blocksize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.blocksize", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.blocksize");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.blocksize = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      this_arg = "blocksize";
    }
    else if (STRPREFIX (argv[i], "features:")) {
      optargs_s.features = &argv[i][9];
      this_mask = GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      this_arg = "features";
    }
    else if (STRPREFIX (argv[i], "inode:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.inode", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.inode");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.inode = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_INODE_BITMASK;
      this_arg = "inode";
    }
    else if (STRPREFIX (argv[i], "sectorsize:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.sectorsize", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.sectorsize");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.sectorsize = r;
      }
      this_mask = GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      this_arg = "sectorsize";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_getxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  char *path;
  const char *name;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  name = argv[i++];
  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_lgetxattr (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char *r;
  size_t size;
  char *path;
  const char *name;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  name = argv[i++];
  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL) goto out;
  if (full_write (1, r, size) != size) {
    perror ("write");
    free (r);
    goto out;
  }
  ret = 0;
  free (r);
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_resize2fs_M (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_resize2fs_M (g, device);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_is_zero (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  r = guestfs_is_zero (g, path);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_is_zero_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_is_zero_device (g, device);
  if (r == -1) goto out;
  ret = 0;
  if (r) printf ("true\n"); else printf ("false\n");
 out:
 out_noargs:
  return ret;
}

static int
run_list_9p (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_9p (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_mount_9p (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *mounttag;
  const char *mountpoint;
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 3) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  mounttag = argv[i++];
  mountpoint = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "options:")) {
      optargs_s.options = &argv[i][8];
      this_mask = GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      this_arg = "options";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_list_dm_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_dm_devices (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_ntfsresize_opts (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      this_arg = "size";
    }
    else if (STRPREFIX (argv[i], "force:")) {
      optargs_s.force = is_true (&argv[i][6]) ? 1 : 0;
      this_mask = GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      this_arg = "force";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_btrfs_filesystem_resize (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *mountpoint;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 2) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  mountpoint = win_prefix (argv[i++]); /* process "win:" prefix */
  if (mountpoint == NULL) goto out_mountpoint;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      this_arg = "size";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (mountpoint);
 out_mountpoint:
 out_noargs:
  return ret;
}

static int
run_write_append (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *path;
  const char *content;
  size_t content_size;
  size_t i = 0;

  if (argc != 2) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 2);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  path = win_prefix (argv[i++]); /* process "win:" prefix */
  if (path == NULL) goto out_path;
  content = argv[i];
  content_size = strlen (argv[i]);
  i++;
  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (path);
 out_path:
 out_noargs:
  return ret;
}

static int
run_compress_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *ctype;
  char *file;
  char *zfile;
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 3 || argc > 4) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 3, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  ctype = argv[i++];
  file = win_prefix (argv[i++]); /* process "win:" prefix */
  if (file == NULL) goto out_file;
  zfile = file_out (argv[i++]);
  if (zfile == NULL) goto out_zfile;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "level:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.level", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.level");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.level = r;
      }
      this_mask = GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      this_arg = "level";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (zfile);
 out_zfile:
  free (file);
 out_file:
 out_noargs:
  return ret;
}

static int
run_compress_device_out (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *ctype;
  const char *device;
  char *zdevice;
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 3 || argc > 4) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 3, 4);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  ctype = argv[i++];
  device = argv[i++];
  zdevice = file_out (argv[i++]);
  if (zdevice == NULL) goto out_zdevice;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "level:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.level", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.level");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.level = r;
      }
      this_mask = GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      this_arg = "level";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (zdevice);
 out_zdevice:
 out_noargs:
  return ret;
}

static int
run_part_to_partnum (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *partition;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  partition = argv[i++];
  r = guestfs_part_to_partnum (g, partition);
  if (r == -1) goto out;
  ret = 0;
  printf ("%d\n", r);
 out:
 out_noargs:
  return ret;
}

static int
run_copy_device_to_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 5) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = argv[i++];
  dest = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      this_arg = "size";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_copy_device_to_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *src;
  char *dest;
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 5) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = argv[i++];
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      this_arg = "size";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
 out_noargs:
  return ret;
}

static int
run_copy_file_to_device (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  const char *dest;
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 5) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      this_arg = "size";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_copy_file_to_file (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  char *src;
  char *dest;
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 5) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 5);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  src = win_prefix (argv[i++]); /* process "win:" prefix */
  if (src == NULL) goto out_src;
  dest = win_prefix (argv[i++]); /* process "win:" prefix */
  if (dest == NULL) goto out_dest;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "srcoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.srcoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.srcoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      this_arg = "srcoffset";
    }
    else if (STRPREFIX (argv[i], "destoffset:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.destoffset", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.destoffset = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      this_arg = "destoffset";
    }
    else if (STRPREFIX (argv[i], "size:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.size", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.size = r;
      }
      this_mask = GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      this_arg = "size";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free (dest);
 out_dest:
  free (src);
 out_src:
 out_noargs:
  return ret;
}

static int
run_tune2fs (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 11) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 11);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "force:")) {
      optargs_s.force = is_true (&argv[i][6]) ? 1 : 0;
      this_mask = GUESTFS_TUNE2FS_FORCE_BITMASK;
      this_arg = "force";
    }
    else if (STRPREFIX (argv[i], "maxmountcount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.maxmountcount", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.maxmountcount");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.maxmountcount = r;
      }
      this_mask = GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      this_arg = "maxmountcount";
    }
    else if (STRPREFIX (argv[i], "mountcount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][11], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.mountcount", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.mountcount");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.mountcount = r;
      }
      this_mask = GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      this_arg = "mountcount";
    }
    else if (STRPREFIX (argv[i], "errorbehavior:")) {
      optargs_s.errorbehavior = &argv[i][14];
      this_mask = GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      this_arg = "errorbehavior";
    }
    else if (STRPREFIX (argv[i], "group:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.group", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.group = r;
      }
      this_mask = GUESTFS_TUNE2FS_GROUP_BITMASK;
      this_arg = "group";
    }
    else if (STRPREFIX (argv[i], "intervalbetweenchecks:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][22], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.intervalbetweenchecks", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.intervalbetweenchecks");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.intervalbetweenchecks = r;
      }
      this_mask = GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      this_arg = "intervalbetweenchecks";
    }
    else if (STRPREFIX (argv[i], "reservedblockspercentage:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][25], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.reservedblockspercentage", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.reservedblockspercentage");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.reservedblockspercentage = r;
      }
      this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      this_arg = "reservedblockspercentage";
    }
    else if (STRPREFIX (argv[i], "lastmounteddirectory:")) {
      optargs_s.lastmounteddirectory = &argv[i][21];
      this_mask = GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      this_arg = "lastmounteddirectory";
    }
    else if (STRPREFIX (argv[i], "reservedblockscount:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][20], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.reservedblockscount", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.reservedblockscount = r;
      }
      this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      this_arg = "reservedblockscount";
    }
    else if (STRPREFIX (argv[i], "user:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][5], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.user", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.user = r;
      }
      this_mask = GUESTFS_TUNE2FS_USER_BITMASK;
      this_arg = "user";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_tune2fs_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_md_create (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *name;
  char **devices;
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 2 || argc > 7) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 2, 7);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  name = argv[i++];
  devices = parse_string_list (argv[i++]);
  if (devices == NULL) goto out_devices;

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "missingbitmap:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][14], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.missingbitmap", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.missingbitmap = r;
      }
      this_mask = GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      this_arg = "missingbitmap";
    }
    else if (STRPREFIX (argv[i], "nrdevices:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][10], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.nrdevices", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.nrdevices");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.nrdevices = r;
      }
      this_mask = GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      this_arg = "nrdevices";
    }
    else if (STRPREFIX (argv[i], "spare:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.spare", "xstrtoll", xerr);
          goto out;
        }
        /* The Int type in the generator is a signed 31 bit int. */
        if (r < (-(2LL<<30)) || r > ((2LL<<30)-1)) {
          fprintf (stderr, _("%s: %s: integer out of range\n"), cmd, "optargs_s.spare");
          goto out;
        }
        /* The check above should ensure this assignment does not overflow. */
        optargs_s.spare = r;
      }
      this_mask = GUESTFS_MD_CREATE_SPARE_BITMASK;
      this_arg = "spare";
    }
    else if (STRPREFIX (argv[i], "chunk:")) {
      {
        strtol_error xerr;
        long long r;

        xerr = xstrtoll (&argv[i][6], NULL, 0, &r, xstrtol_suffixes);
        if (xerr != LONGINT_OK) {
          fprintf (stderr,
                   _("%s: %s: invalid integer parameter (%s returned %d)\n"),
                   cmd, "optargs_s.chunk", "xstrtoll", xerr);
          goto out;
        }
        optargs_s.chunk = r;
      }
      this_mask = GUESTFS_MD_CREATE_CHUNK_BITMASK;
      this_arg = "chunk";
    }
    else if (STRPREFIX (argv[i], "level:")) {
      optargs_s.level = &argv[i][6];
      this_mask = GUESTFS_MD_CREATE_LEVEL_BITMASK;
      this_arg = "level";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_md_create_argv (g, name, devices, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
  free_strings (devices);
 out_devices:
 out_noargs:
  return ret;
}

static int
run_list_md_devices (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;

  if (argc != 0) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 0);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  r = guestfs_list_md_devices (g);
  if (r == NULL) goto out;
  ret = 0;
  print_strings (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_md_detail (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *md;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  md = argv[i++];
  r = guestfs_md_detail (g, md);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_md_stop (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *md;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  md = argv[i++];
  r = guestfs_md_stop (g, md);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

static int
run_blkid (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  char **r;
  const char *device;
  size_t i = 0;

  if (argc != 1) {
    fprintf (stderr, _("%s should have %d parameter(s)\n"), cmd, 1);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];
  r = guestfs_blkid (g, device);
  if (r == NULL) goto out;
  ret = 0;
  print_table (r);
  free_strings (r);
 out:
 out_noargs:
  return ret;
}

static int
run_e2fsck (const char *cmd, size_t argc, char *argv[])
{
  int ret = -1;
  int r;
  const char *device;
  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  size_t i = 0;

  if (argc < 1 || argc > 3) {
    fprintf (stderr, _("%s should have %d-%d parameter(s)\n"), cmd, 1, 3);
    fprintf (stderr, _("type 'help %s' for help on %s\n"), cmd, cmd);
    goto out_noargs;
  }
  device = argv[i++];

  for (; i < argc; ++i) {
    uint64_t this_mask;
    const char *this_arg;

    if (STRPREFIX (argv[i], "correct:")) {
      optargs_s.correct = is_true (&argv[i][8]) ? 1 : 0;
      this_mask = GUESTFS_E2FSCK_CORRECT_BITMASK;
      this_arg = "correct";
    }
    else if (STRPREFIX (argv[i], "forceall:")) {
      optargs_s.forceall = is_true (&argv[i][9]) ? 1 : 0;
      this_mask = GUESTFS_E2FSCK_FORCEALL_BITMASK;
      this_arg = "forceall";
    }
    else {
      fprintf (stderr, _("%s: unknown optional argument \"%s\"\n"),
               cmd, argv[i]);
      goto out;
    }

    if (optargs_s.bitmask & this_mask) {
      fprintf (stderr, _("%s: optional argument \"%s\" given twice\n"),
               cmd, this_arg);
      goto out;
    }
    optargs_s.bitmask |= this_mask;
  }

  r = guestfs_e2fsck_argv (g, device, optargs);
  if (r == -1) goto out;
  ret = 0;
 out:
 out_noargs:
  return ret;
}

int
run_action (const char *cmd, size_t argc, char *argv[])
{
  const struct command_table *ct;

  ct = lookup_fish_command (cmd, strlen (cmd));
  if (ct)
    return ct->entry->run (cmd, argc, argv);
  else {
    fprintf (stderr, _("%s: unknown command\n"), cmd);
    if (command_num == 1)
      extended_help_message ();
    return -1;
  }
}
