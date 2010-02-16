/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

#include "../src/guestfs_protocol.h"

extern int do_mount (const char *device, const char *mountpoint);
extern int do_sync (void);
extern int do_touch (const char *path);
extern char *do_cat (const char *path);
extern char *do_ll (const char *directory);
extern char **do_ls (const char *directory);
extern char **do_list_devices (void);
extern char **do_list_partitions (void);
extern char **do_pvs (void);
extern char **do_vgs (void);
extern char **do_lvs (void);
extern guestfs_int_lvm_pv_list *do_pvs_full (void);
extern guestfs_int_lvm_vg_list *do_vgs_full (void);
extern guestfs_int_lvm_lv_list *do_lvs_full (void);
extern char **do_read_lines (const char *path);
extern int do_aug_init (const char *root, int flags);
extern int do_aug_close (void);
extern int do_aug_defvar (const char *name, const char *expr);
extern guestfs_int_int_bool *do_aug_defnode (const char *name, const char *expr, const char *val);
extern char *do_aug_get (const char *augpath);
extern int do_aug_set (const char *augpath, const char *val);
extern int do_aug_insert (const char *augpath, const char *label, int before);
extern int do_aug_rm (const char *augpath);
extern int do_aug_mv (const char *src, const char *dest);
extern char **do_aug_match (const char *augpath);
extern int do_aug_save (void);
extern int do_aug_load (void);
extern char **do_aug_ls (const char *augpath);
extern int do_rm (const char *path);
extern int do_rmdir (const char *path);
extern int do_rm_rf (const char *path);
extern int do_mkdir (const char *path);
extern int do_mkdir_p (const char *path);
extern int do_chmod (int mode, const char *path);
extern int do_chown (int owner, int group, const char *path);
extern int do_exists (const char *path);
extern int do_is_file (const char *path);
extern int do_is_dir (const char *path);
extern int do_pvcreate (const char *device);
extern int do_vgcreate (const char *volgroup, char *const *physvols);
extern int do_lvcreate (const char *logvol, const char *volgroup, int mbytes);
extern int do_mkfs (const char *fstype, const char *device);
extern int do_sfdisk (const char *device, int cyls, int heads, int sectors, char *const *lines);
extern int do_write_file (const char *path, const char *content, int size);
extern int do_umount (const char *pathordevice);
extern char **do_mounts (void);
extern int do_umount_all (void);
extern int do_lvm_remove_all (void);
extern char *do_file (const char *path);
extern char *do_command (char *const *arguments);
extern char **do_command_lines (char *const *arguments);
extern guestfs_int_stat *do_stat (const char *path);
extern guestfs_int_stat *do_lstat (const char *path);
extern guestfs_int_statvfs *do_statvfs (const char *path);
extern char **do_tune2fs_l (const char *device);
extern int do_blockdev_setro (const char *device);
extern int do_blockdev_setrw (const char *device);
extern int do_blockdev_getro (const char *device);
extern int do_blockdev_getss (const char *device);
extern int do_blockdev_getbsz (const char *device);
extern int do_blockdev_setbsz (const char *device, int blocksize);
extern int64_t do_blockdev_getsz (const char *device);
extern int64_t do_blockdev_getsize64 (const char *device);
extern int do_blockdev_flushbufs (const char *device);
extern int do_blockdev_rereadpt (const char *device);
extern int do_upload (const char *remotefilename);
extern int do_download (const char *remotefilename);
extern char *do_checksum (const char *csumtype, const char *path);
extern int do_tar_in (const char *directory);
extern int do_tar_out (const char *directory);
extern int do_tgz_in (const char *directory);
extern int do_tgz_out (const char *directory);
extern int do_mount_ro (const char *device, const char *mountpoint);
extern int do_mount_options (const char *options, const char *device, const char *mountpoint);
extern int do_mount_vfs (const char *options, const char *vfstype, const char *device, const char *mountpoint);
extern char *do_debug (const char *subcmd, char *const *extraargs);
extern int do_lvremove (const char *device);
extern int do_vgremove (const char *vgname);
extern int do_pvremove (const char *device);
extern int do_set_e2label (const char *device, const char *label);
extern char *do_get_e2label (const char *device);
extern int do_set_e2uuid (const char *device, const char *uuid);
extern char *do_get_e2uuid (const char *device);
extern int do_fsck (const char *fstype, const char *device);
extern int do_zero (const char *device);
extern int do_grub_install (const char *root, const char *device);
extern int do_cp (const char *src, const char *dest);
extern int do_cp_a (const char *src, const char *dest);
extern int do_mv (const char *src, const char *dest);
extern int do_drop_caches (int whattodrop);
extern char *do_dmesg (void);
extern int do_ping_daemon (void);
extern int do_equal (const char *file1, const char *file2);
extern char **do_strings (const char *path);
extern char **do_strings_e (const char *encoding, const char *path);
extern char *do_hexdump (const char *path);
extern int do_zerofree (const char *device);
extern int do_pvresize (const char *device);
extern int do_sfdisk_N (const char *device, int partnum, int cyls, int heads, int sectors, const char *line);
extern char *do_sfdisk_l (const char *device);
extern char *do_sfdisk_kernel_geometry (const char *device);
extern char *do_sfdisk_disk_geometry (const char *device);
extern int do_vg_activate_all (int activate);
extern int do_vg_activate (int activate, char *const *volgroups);
extern int do_lvresize (const char *device, int mbytes);
extern int do_resize2fs (const char *device);
extern char **do_find (const char *directory);
extern int do_e2fsck_f (const char *device);
extern int do_sleep (int secs);
extern int do_ntfs_3g_probe (int rw, const char *device);
extern char *do_sh (const char *command);
extern char **do_sh_lines (const char *command);
extern char **do_glob_expand (const char *pattern);
extern int do_scrub_device (const char *device);
extern int do_scrub_file (const char *file);
extern int do_scrub_freespace (const char *dir);
extern char *do_mkdtemp (const char *template);
extern int do_wc_l (const char *path);
extern int do_wc_w (const char *path);
extern int do_wc_c (const char *path);
extern char **do_head (const char *path);
extern char **do_head_n (int nrlines, const char *path);
extern char **do_tail (const char *path);
extern char **do_tail_n (int nrlines, const char *path);
extern char *do_df (void);
extern char *do_df_h (void);
extern int64_t do_du (const char *path);
extern char **do_initrd_list (const char *path);
extern int do_mount_loop (const char *file, const char *mountpoint);
extern int do_mkswap (const char *device);
extern int do_mkswap_L (const char *label, const char *device);
extern int do_mkswap_U (const char *uuid, const char *device);
extern int do_mknod (int mode, int devmajor, int devminor, const char *path);
extern int do_mkfifo (int mode, const char *path);
extern int do_mknod_b (int mode, int devmajor, int devminor, const char *path);
extern int do_mknod_c (int mode, int devmajor, int devminor, const char *path);
extern int do_umask (int mask);
extern guestfs_int_dirent_list *do_readdir (const char *dir);
extern int do_sfdiskM (const char *device, char *const *lines);
extern char *do_zfile (const char *meth, const char *path);
extern guestfs_int_xattr_list *do_getxattrs (const char *path);
extern guestfs_int_xattr_list *do_lgetxattrs (const char *path);
extern int do_setxattr (const char *xattr, const char *val, int vallen, const char *path);
extern int do_lsetxattr (const char *xattr, const char *val, int vallen, const char *path);
extern int do_removexattr (const char *xattr, const char *path);
extern int do_lremovexattr (const char *xattr, const char *path);
extern char **do_mountpoints (void);
extern int do_mkmountpoint (const char *exemptpath);
extern int do_rmmountpoint (const char *exemptpath);
extern char *do_read_file (const char *path, size_t *size_r);
extern char **do_grep (const char *regex, const char *path);
extern char **do_egrep (const char *regex, const char *path);
extern char **do_fgrep (const char *pattern, const char *path);
extern char **do_grepi (const char *regex, const char *path);
extern char **do_egrepi (const char *regex, const char *path);
extern char **do_fgrepi (const char *pattern, const char *path);
extern char **do_zgrep (const char *regex, const char *path);
extern char **do_zegrep (const char *regex, const char *path);
extern char **do_zfgrep (const char *pattern, const char *path);
extern char **do_zgrepi (const char *regex, const char *path);
extern char **do_zegrepi (const char *regex, const char *path);
extern char **do_zfgrepi (const char *pattern, const char *path);
extern char *do_realpath (const char *path);
extern int do_ln (const char *target, const char *linkname);
extern int do_ln_f (const char *target, const char *linkname);
extern int do_ln_s (const char *target, const char *linkname);
extern int do_ln_sf (const char *target, const char *linkname);
extern char *do_readlink (const char *path);
extern int do_fallocate (const char *path, int len);
extern int do_swapon_device (const char *device);
extern int do_swapoff_device (const char *device);
extern int do_swapon_file (const char *file);
extern int do_swapoff_file (const char *file);
extern int do_swapon_label (const char *label);
extern int do_swapoff_label (const char *label);
extern int do_swapon_uuid (const char *uuid);
extern int do_swapoff_uuid (const char *uuid);
extern int do_mkswap_file (const char *path);
extern int do_inotify_init (int maxevents);
extern int64_t do_inotify_add_watch (const char *path, int mask);
extern int do_inotify_rm_watch (int wd);
extern guestfs_int_inotify_event_list *do_inotify_read (void);
extern char **do_inotify_files (void);
extern int do_inotify_close (void);
extern int do_setcon (const char *context);
extern char *do_getcon (void);
extern int do_mkfs_b (const char *fstype, int blocksize, const char *device);
extern int do_mke2journal (int blocksize, const char *device);
extern int do_mke2journal_L (int blocksize, const char *label, const char *device);
extern int do_mke2journal_U (int blocksize, const char *uuid, const char *device);
extern int do_mke2fs_J (const char *fstype, int blocksize, const char *device, const char *journal);
extern int do_mke2fs_JL (const char *fstype, int blocksize, const char *device, const char *label);
extern int do_mke2fs_JU (const char *fstype, int blocksize, const char *device, const char *uuid);
extern int do_modprobe (const char *modulename);
extern char *do_echo_daemon (char *const *words);
extern int do_find0 (const char *directory);
extern char *do_case_sensitive_path (const char *path);
extern char *do_vfs_type (const char *device);
extern int do_truncate (const char *path);
extern int do_truncate_size (const char *path, int64_t size);
extern int do_utimens (const char *path, int64_t atsecs, int64_t atnsecs, int64_t mtsecs, int64_t mtnsecs);
extern int do_mkdir_mode (const char *path, int mode);
extern int do_lchown (int owner, int group, const char *path);
extern guestfs_int_stat_list *do_lstatlist (const char *path, char *const *names);
extern guestfs_int_xattr_list *do_lxattrlist (const char *path, char *const *names);
extern char **do_readlinklist (const char *path, char *const *names);
extern char *do_pread (const char *path, int count, int64_t offset, size_t *size_r);
extern int do_part_init (const char *device, const char *parttype);
extern int do_part_add (const char *device, const char *prlogex, int64_t startsect, int64_t endsect);
extern int do_part_disk (const char *device, const char *parttype);
extern int do_part_set_bootable (const char *device, int partnum, int bootable);
extern int do_part_set_name (const char *device, int partnum, const char *name);
extern guestfs_int_partition_list *do_part_list (const char *device);
extern char *do_part_get_parttype (const char *device);
extern int do_fill (int c, int len, const char *path);
extern int do_available (char *const *groups);
extern int do_dd (const char *src, const char *dest);
extern int64_t do_filesize (const char *file);
extern int do_lvrename (const char *logvol, const char *newlogvol);
extern int do_vgrename (const char *volgroup, const char *newvolgroup);
extern char *do_initrd_cat (const char *initrdpath, const char *filename, size_t *size_r);
