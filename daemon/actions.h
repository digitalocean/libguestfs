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

#include "guestfs_protocol.h"

#define GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKFS_OPTS_FEATURES_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_MKFS_OPTS_INODE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_MOUNT_9P_OPTIONS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COMPRESS_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_TUNE2FS_FORCE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_TUNE2FS_GROUP_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK (UINT64_C(1)<<7)
#define GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK (UINT64_C(1)<<8)
#define GUESTFS_TUNE2FS_USER_BITMASK (UINT64_C(1)<<9)
#define GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MD_CREATE_NRDEVICES_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_MD_CREATE_SPARE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MD_CREATE_CHUNK_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_MD_CREATE_LEVEL_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_E2FSCK_CORRECT_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_E2FSCK_FORCEALL_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_MKFS_BTRFS_LABEL_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_MKFS_BTRFS_METADATA_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK (UINT64_C(1)<<7)
#define GUESTFS_SET_E2ATTRS_CLEAR_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FSCK_REPAIR_BITMASK (UINT64_C(1)<<1)
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
extern char *do_mkdtemp (const char *tmpl);
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
extern char *do_pvuuid (const char *device);
extern char *do_vguuid (const char *vgname);
extern char *do_lvuuid (const char *device);
extern char **do_vgpvuuids (const char *vgname);
extern char **do_vglvuuids (const char *vgname);
extern int do_copy_size (const char *src, const char *dest, int64_t size);
extern int do_zero_device (const char *device);
extern int do_txz_in (const char *directory);
extern int do_txz_out (const char *directory);
extern int do_ntfsresize (const char *device);
extern int do_vgscan (void);
extern int do_part_del (const char *device, int partnum);
extern int do_part_get_bootable (const char *device, int partnum);
extern int do_part_get_mbr_id (const char *device, int partnum);
extern int do_part_set_mbr_id (const char *device, int partnum, int idbyte);
extern char *do_checksum_device (const char *csumtype, const char *device);
extern int do_lvresize_free (const char *lv, int percent);
extern int do_aug_clear (const char *augpath);
extern int do_get_umask (void);
extern int do_debug_upload (const char *tmpname, int mode);
extern int do_base64_in (const char *filename);
extern int do_base64_out (const char *filename);
extern int do_checksums_out (const char *csumtype, const char *directory);
extern int do_fill_pattern (const char *pattern, int len, const char *path);
extern int do_write (const char *path, const char *content, size_t content_size);
extern int do_pwrite (const char *path, const char *content, size_t content_size, int64_t offset);
extern int do_resize2fs_size (const char *device, int64_t size);
extern int do_pvresize_size (const char *device, int64_t size);
extern int do_ntfsresize_size (const char *device, int64_t size);
extern char **do_available_all_groups (void);
extern int do_fallocate64 (const char *path, int64_t len);
extern char *do_vfs_label (const char *device);
extern char *do_vfs_uuid (const char *device);
extern int do_lvm_set_filter (char *const *devices);
extern int do_lvm_clear_filter (void);
extern int do_luks_open (const char *device, const char *key, const char *mapname);
extern int do_luks_open_ro (const char *device, const char *key, const char *mapname);
extern int do_luks_close (const char *device);
extern int do_luks_format (const char *device, const char *key, int keyslot);
extern int do_luks_format_cipher (const char *device, const char *key, int keyslot, const char *cipher);
extern int do_luks_add_key (const char *device, const char *key, const char *newkey, int keyslot);
extern int do_luks_kill_slot (const char *device, const char *key, int keyslot);
extern int do_is_lv (const char *device);
extern char *do_findfs_uuid (const char *uuid);
extern char *do_findfs_label (const char *label);
extern int do_is_chardev (const char *path);
extern int do_is_blockdev (const char *path);
extern int do_is_fifo (const char *path);
extern int do_is_symlink (const char *path);
extern int do_is_socket (const char *path);
extern char *do_part_to_dev (const char *partition);
extern int do_upload_offset (const char *remotefilename, int64_t offset);
extern int do_download_offset (const char *remotefilename, int64_t offset, int64_t size);
extern int do_pwrite_device (const char *device, const char *content, size_t content_size, int64_t offset);
extern char *do_pread_device (const char *device, int count, int64_t offset, size_t *size_r);
extern char *do_lvm_canonical_lv_name (const char *lvname);
extern int do_mkfs_opts (const char *fstype, const char *device, int blocksize, const char *features, int inode, int sectorsize);
extern char *do_getxattr (const char *path, const char *name, size_t *size_r);
extern char *do_lgetxattr (const char *path, const char *name, size_t *size_r);
extern int do_resize2fs_M (const char *device);
extern int do_internal_autosync (void);
extern int do_is_zero (const char *path);
extern int do_is_zero_device (const char *device);
extern char **do_list_9p (void);
extern int do_mount_9p (const char *mounttag, const char *mountpoint, const char *options);
extern char **do_list_dm_devices (void);
extern int do_ntfsresize_opts (const char *device, int64_t size, int force);
extern int do_btrfs_filesystem_resize (const char *mountpoint, int64_t size);
extern int do_write_append (const char *path, const char *content, size_t content_size);
extern int do_compress_out (const char *ctype, const char *file, int level);
extern int do_compress_device_out (const char *ctype, const char *device, int level);
extern int do_part_to_partnum (const char *partition);
extern int do_copy_device_to_device (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size);
extern int do_copy_device_to_file (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size);
extern int do_copy_file_to_device (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size);
extern int do_copy_file_to_file (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size);
extern int do_tune2fs (const char *device, int force, int maxmountcount, int mountcount, const char *errorbehavior, int64_t group, int intervalbetweenchecks, int reservedblockspercentage, const char *lastmounteddirectory, int64_t reservedblockscount, int64_t user);
extern int do_md_create (const char *name, char *const *devices, int64_t missingbitmap, int nrdevices, int spare, int64_t chunk, const char *level);
extern char **do_list_md_devices (void);
extern char **do_md_detail (const char *md);
extern int do_md_stop (const char *md);
extern char **do_blkid (const char *device);
extern int do_e2fsck (const char *device, int correct, int forceall);
extern char *do_llz (const char *directory);
extern int do_wipefs (const char *device);
extern int do_ntfsfix (const char *device, int clearbadsectors);
extern int do_ntfsclone_out (const char *device, int metadataonly, int rescue, int ignorefscheck, int preservetimestamps, int force);
extern int do_ntfsclone_in (const char *device);
extern int do_set_label (const char *device, const char *label);
extern int do_zero_free_space (const char *directory);
extern int do_lvcreate_free (const char *logvol, const char *volgroup, int percent);
extern guestfs_int_isoinfo *do_isoinfo_device (const char *device);
extern guestfs_int_isoinfo *do_isoinfo (const char *isofile);
extern char *do_vgmeta (const char *vgname, size_t *size_r);
extern guestfs_int_mdstat_list *do_md_stat (const char *md);
extern int do_mkfs_btrfs (char *const *devices, int64_t allocstart, int64_t bytecount, const char *datatype, int leafsize, const char *label, const char *metadata, int nodesize, int sectorsize);
extern char *do_get_e2attrs (const char *file);
extern int do_set_e2attrs (const char *file, const char *attrs, int clear);
extern int64_t do_get_e2generation (const char *file);
extern int do_set_e2generation (const char *file, int64_t generation);
extern int do_btrfs_subvolume_snapshot (const char *source, const char *dest);
extern int do_btrfs_subvolume_delete (const char *subvolume);
extern int do_btrfs_subvolume_create (const char *dest);
extern guestfs_int_btrfssubvolume_list *do_btrfs_subvolume_list (const char *fs);
extern int do_btrfs_subvolume_set_default (int64_t id, const char *fs);
extern int do_btrfs_filesystem_sync (const char *fs);
extern int do_btrfs_filesystem_balance (const char *fs);
extern int do_btrfs_device_add (char *const *devices, const char *fs);
extern int do_btrfs_device_delete (char *const *devices, const char *fs);
extern int do_btrfs_set_seeding (const char *device, int seeding);
extern int do_btrfs_fsck (const char *device, int64_t superblock, int repair);
