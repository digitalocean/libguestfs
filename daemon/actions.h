/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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

#ifndef GUESTFSD_ACTIONS_H
#define GUESTFSD_ACTIONS_H

#include "guestfs_protocol.h"
#include "daemon.h"

#define GUESTFS_IS_FILE_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_IS_DIR_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_UMOUNT_FORCE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_UMOUNT_LAZYUNMOUNT_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_TAR_IN_COMPRESS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_TAR_OUT_COMPRESS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_TAR_OUT_NUMERICOWNER_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_TAR_OUT_EXCLUDES_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MKSWAP_LABEL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKSWAP_UUID_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_GREP_EXTENDED_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_GREP_FIXED_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_GREP_INSENSITIVE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_GREP_COMPRESSED_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_IS_CHARDEV_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_IS_BLOCKDEV_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_IS_FIFO_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_IS_SOCKET_FOLLOWSYMLINKS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKFS_BLOCKSIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKFS_FEATURES_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_MKFS_INODE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MKFS_SECTORSIZE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_MKFS_LABEL_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_MOUNT_9P_OPTIONS_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSRESIZE_SIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_NTFSRESIZE_FORCE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COMPRESS_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK (UINT64_C(1)<<4)
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
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_RO_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_QGROUPID_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_BTRFS_SUBVOLUME_CREATE_QGROUPID_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FSCK_REPAIR_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_FSTRIM_OFFSET_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_FSTRIM_LENGTH_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_XFS_GROWFS_DATASEC_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_XFS_GROWFS_LOGSEC_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_XFS_GROWFS_RTSEC_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_XFS_GROWFS_DATASIZE_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_XFS_GROWFS_RTSIZE_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_XFS_GROWFS_MAXPCT_BITMASK (UINT64_C(1)<<7)
#define GUESTFS_RSYNC_ARCHIVE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_RSYNC_DELETEDEST_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_RSYNC_IN_ARCHIVE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_RSYNC_IN_DELETEDEST_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_XFS_ADMIN_IMGFILE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_XFS_ADMIN_V2LOG_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_XFS_ADMIN_LABEL_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_XFS_ADMIN_UUID_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_HIVEX_OPEN_DEBUG_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_HIVEX_OPEN_WRITE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_XFS_REPAIR_MAXMEM_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK (UINT64_C(1)<<7)
#define GUESTFS_XFS_REPAIR_LOGDEV_BITMASK (UINT64_C(1)<<8)
#define GUESTFS_XFS_REPAIR_RTDEV_BITMASK (UINT64_C(1)<<9)
#define GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_MKE2FS_BLOCKSIZE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_MKE2FS_FRAGSIZE_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK (UINT64_C(1)<<4)
#define GUESTFS_MKE2FS_BYTESPERINODE_BITMASK (UINT64_C(1)<<5)
#define GUESTFS_MKE2FS_INODESIZE_BITMASK (UINT64_C(1)<<6)
#define GUESTFS_MKE2FS_JOURNALSIZE_BITMASK (UINT64_C(1)<<7)
#define GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK (UINT64_C(1)<<8)
#define GUESTFS_MKE2FS_STRIDESIZE_BITMASK (UINT64_C(1)<<9)
#define GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK (UINT64_C(1)<<10)
#define GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK (UINT64_C(1)<<11)
#define GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK (UINT64_C(1)<<12)
#define GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK (UINT64_C(1)<<13)
#define GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK (UINT64_C(1)<<14)
#define GUESTFS_MKE2FS_LABEL_BITMASK (UINT64_C(1)<<15)
#define GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK (UINT64_C(1)<<16)
#define GUESTFS_MKE2FS_CREATOROS_BITMASK (UINT64_C(1)<<17)
#define GUESTFS_MKE2FS_FSTYPE_BITMASK (UINT64_C(1)<<18)
#define GUESTFS_MKE2FS_USAGETYPE_BITMASK (UINT64_C(1)<<19)
#define GUESTFS_MKE2FS_UUID_BITMASK (UINT64_C(1)<<20)
#define GUESTFS_MKE2FS_FORCECREATE_BITMASK (UINT64_C(1)<<21)
#define GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK (UINT64_C(1)<<22)
#define GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK (UINT64_C(1)<<23)
#define GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK (UINT64_C(1)<<24)
#define GUESTFS_MKE2FS_TESTFS_BITMASK (UINT64_C(1)<<25)
#define GUESTFS_MKE2FS_DISCARD_BITMASK (UINT64_C(1)<<26)
#define GUESTFS_MKE2FS_QUOTATYPE_BITMASK (UINT64_C(1)<<27)
#define GUESTFS_MKE2FS_EXTENT_BITMASK (UINT64_C(1)<<28)
#define GUESTFS_MKE2FS_FILETYPE_BITMASK (UINT64_C(1)<<29)
#define GUESTFS_MKE2FS_FLEXBG_BITMASK (UINT64_C(1)<<30)
#define GUESTFS_MKE2FS_HASJOURNAL_BITMASK (UINT64_C(1)<<31)
#define GUESTFS_MKE2FS_JOURNALDEV_BITMASK (UINT64_C(1)<<32)
#define GUESTFS_MKE2FS_LARGEFILE_BITMASK (UINT64_C(1)<<33)
#define GUESTFS_MKE2FS_QUOTA_BITMASK (UINT64_C(1)<<34)
#define GUESTFS_MKE2FS_RESIZEINODE_BITMASK (UINT64_C(1)<<35)
#define GUESTFS_MKE2FS_SPARSESUPER_BITMASK (UINT64_C(1)<<36)
#define GUESTFS_MKE2FS_UNINITBG_BITMASK (UINT64_C(1)<<37)
#define GUESTFS_MKTEMP_SUFFIX_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_SYSLINUX_DIRECTORY_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_REMOUNT_RW_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK (UINT64_C(1)<<2)
#define GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK (UINT64_C(1)<<3)
#define GUESTFS_CPIO_OUT_FORMAT_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK (UINT64_C(1)<<0)
#define GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK (UINT64_C(1)<<1)
#define GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK (UINT64_C(1)<<0)
extern int do_mount (const mountable_t *mountable, const char *mountpoint);
extern int do_sync (void);
extern int do_touch (const char *path);
extern char *do_ll (const char *directory);
extern char **do_list_devices (void);
extern char **do_list_partitions (void);
extern char **do_pvs (void);
extern char **do_vgs (void);
extern char **do_lvs (void);
extern guestfs_int_lvm_pv_list *do_pvs_full (void);
extern guestfs_int_lvm_vg_list *do_vgs_full (void);
extern guestfs_int_lvm_lv_list *do_lvs_full (void);
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
extern int do_is_file (const char *path, int followsymlinks);
extern int do_is_dir (const char *path, int followsymlinks);
extern int do_pvcreate (const char *device);
extern int do_vgcreate (const char *volgroup, char *const *physvols);
extern int do_lvcreate (const char *logvol, const char *volgroup, int mbytes);
extern int do_sfdisk (const char *device, int cyls, int heads, int sectors, char *const *lines);
extern int do_write_file (const char *path, const char *content, int size);
extern int do_umount (const char *pathordevice, int force, int lazyunmount);
extern char **do_mounts (void);
extern int do_umount_all (void);
extern int do_lvm_remove_all (void);
extern char *do_file (const char *path);
extern char *do_command (char *const *arguments);
extern char **do_command_lines (char *const *arguments);
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
extern int do_tar_in (const char *directory, const char *compress);
extern int do_tar_out (const char *directory, const char *compress, int numericowner, char *const *excludes);
extern int do_tgz_in (const char *directory);
extern int do_tgz_out (const char *directory);
extern int do_mount_ro (const mountable_t *mountable, const char *mountpoint);
extern int do_mount_options (const char *options, const mountable_t *mountable, const char *mountpoint);
extern int do_mount_vfs (const char *options, const char *vfstype, const mountable_t *mountable, const char *mountpoint);
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
extern int do_mkswap (const char *device, const char *label, const char *uuid);
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
extern char **do_grep (const char *regex, const char *path, int extended, int fixed, int insensitive, int compressed);
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
extern char *do_vfs_type (const mountable_t *mountable);
extern int do_truncate (const char *path);
extern int do_truncate_size (const char *path, int64_t size);
extern int do_utimens (const char *path, int64_t atsecs, int64_t atnsecs, int64_t mtsecs, int64_t mtnsecs);
extern int do_mkdir_mode (const char *path, int mode);
extern int do_lchown (int owner, int group, const char *path);
extern guestfs_int_xattr_list *do_internal_lxattrlist (const char *path, char *const *names);
extern char **do_internal_readlinklist (const char *path, char *const *names);
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
extern int do_internal_write (const char *path, const char *content, size_t content_size);
extern int do_pwrite (const char *path, const char *content, size_t content_size, int64_t offset);
extern int do_resize2fs_size (const char *device, int64_t size);
extern int do_pvresize_size (const char *device, int64_t size);
extern int do_ntfsresize_size (const char *device, int64_t size);
extern char **do_available_all_groups (void);
extern int do_fallocate64 (const char *path, int64_t len);
extern char *do_vfs_label (const mountable_t *mountable);
extern char *do_vfs_uuid (const mountable_t *mountable);
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
extern int do_is_chardev (const char *path, int followsymlinks);
extern int do_is_blockdev (const char *path, int followsymlinks);
extern int do_is_fifo (const char *path, int followsymlinks);
extern int do_is_symlink (const char *path);
extern int do_is_socket (const char *path, int followsymlinks);
extern char *do_part_to_dev (const char *partition);
extern int do_upload_offset (const char *remotefilename, int64_t offset);
extern int do_download_offset (const char *remotefilename, int64_t offset, int64_t size);
extern int do_pwrite_device (const char *device, const char *content, size_t content_size, int64_t offset);
extern char *do_pread_device (const char *device, int count, int64_t offset, size_t *size_r);
extern char *do_lvm_canonical_lv_name (const char *lvname);
extern int do_mkfs (const char *fstype, const char *device, int blocksize, const char *features, int inode, int sectorsize, const char *label);
extern char *do_getxattr (const char *path, const char *name, size_t *size_r);
extern char *do_lgetxattr (const char *path, const char *name, size_t *size_r);
extern int do_resize2fs_M (const char *device);
extern int do_internal_autosync (void);
extern int do_is_zero (const char *path);
extern int do_is_zero_device (const char *device);
extern char **do_list_9p (void);
extern int do_mount_9p (const char *mounttag, const char *mountpoint, const char *options);
extern char **do_list_dm_devices (void);
extern int do_ntfsresize (const char *device, int64_t size, int force);
extern int do_btrfs_filesystem_resize (const char *mountpoint, int64_t size);
extern int do_internal_write_append (const char *path, const char *content, size_t content_size);
extern int do_compress_out (const char *ctype, const char *file, int level);
extern int do_compress_device_out (const char *ctype, const char *device, int level);
extern int do_part_to_partnum (const char *partition);
extern int do_copy_device_to_device (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size, int sparse, int append);
extern int do_copy_device_to_file (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size, int sparse, int append);
extern int do_copy_file_to_device (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size, int sparse, int append);
extern int do_copy_file_to_file (const char *src, const char *dest, int64_t srcoffset, int64_t destoffset, int64_t size, int sparse, int append);
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
extern int do_set_label (const mountable_t *mountable, const char *label);
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
extern int do_btrfs_subvolume_snapshot (const char *source, const char *dest, int ro, const char *qgroupid);
extern int do_btrfs_subvolume_delete (const char *subvolume);
extern int do_btrfs_subvolume_create (const char *dest, const char *qgroupid);
extern guestfs_int_btrfssubvolume_list *do_btrfs_subvolume_list (const mountable_t *fs);
extern int do_btrfs_subvolume_set_default (int64_t id, const char *fs);
extern int do_btrfs_filesystem_sync (const char *fs);
extern int do_btrfs_filesystem_balance (const char *fs);
extern int do_btrfs_device_add (char *const *devices, const char *fs);
extern int do_btrfs_device_delete (char *const *devices, const char *fs);
extern int do_btrfs_set_seeding (const char *device, int seeding);
extern int do_btrfs_fsck (const char *device, int64_t superblock, int repair);
extern int do_filesystem_available (const char *filesystem);
extern int do_fstrim (const char *mountpoint, int64_t offset, int64_t length, int64_t minimumfreeextent);
extern int do_device_index (const char *device);
extern int do_nr_devices (void);
extern guestfs_int_xfsinfo *do_xfs_info (const char *pathordevice);
extern int do_pvchange_uuid (const char *device);
extern int do_pvchange_uuid_all (void);
extern int do_vgchange_uuid (const char *vg);
extern int do_vgchange_uuid_all (void);
extern guestfs_int_utsname *do_utsname (void);
extern int do_xfs_growfs (const char *path, int datasec, int logsec, int rtsec, int64_t datasize, int64_t logsize, int64_t rtsize, int64_t rtextsize, int maxpct);
extern int do_rsync (const char *src, const char *dest, int archive, int deletedest);
extern int do_rsync_in (const char *remote, const char *dest, int archive, int deletedest);
extern int do_rsync_out (const char *src, const char *remote, int archive, int deletedest);
extern int do_ls0 (const char *dir);
extern int do_fill_dir (const char *dir, int nr);
extern int do_xfs_admin (const char *device, int extunwritten, int imgfile, int v2log, int projid32bit, int lazycounter, const char *label, const char *uuid);
extern int do_hivex_open (const char *filename, int verbose, int debug, int write);
extern int do_hivex_close (void);
extern int64_t do_hivex_root (void);
extern char *do_hivex_node_name (int64_t nodeh);
extern guestfs_int_hivex_node_list *do_hivex_node_children (int64_t nodeh);
extern int64_t do_hivex_node_get_child (int64_t nodeh, const char *name);
extern int64_t do_hivex_node_parent (int64_t nodeh);
extern guestfs_int_hivex_value_list *do_hivex_node_values (int64_t nodeh);
extern int64_t do_hivex_node_get_value (int64_t nodeh, const char *key);
extern char *do_hivex_value_key (int64_t valueh);
extern int64_t do_hivex_value_type (int64_t valueh);
extern char *do_hivex_value_value (int64_t valueh, size_t *size_r);
extern int do_hivex_commit (const char *filename);
extern int64_t do_hivex_node_add_child (int64_t parent, const char *name);
extern int do_hivex_node_delete_child (int64_t nodeh);
extern int do_hivex_node_set_value (int64_t nodeh, const char *key, int64_t t, const char *val, size_t val_size);
extern int do_xfs_repair (const char *device, int forcelogzero, int nomodify, int noprefetch, int forcegeometry, int64_t maxmem, int64_t ihashsize, int64_t bhashsize, int64_t agstride, const char *logdev, const char *rtdev);
extern int do_rm_f (const char *path);
extern int do_mke2fs (const char *device, int64_t blockscount, int64_t blocksize, int64_t fragsize, int64_t blockspergroup, int64_t numberofgroups, int64_t bytesperinode, int64_t inodesize, int64_t journalsize, int64_t numberofinodes, int64_t stridesize, int64_t stripewidth, int64_t maxonlineresize, int reservedblockspercentage, int mmpupdateinterval, const char *journaldevice, const char *label, const char *lastmounteddir, const char *creatoros, const char *fstype, const char *usagetype, const char *uuid, int forcecreate, int writesbandgrouponly, int lazyitableinit, int lazyjournalinit, int testfs, int discard, int quotatype, int extent, int filetype, int flexbg, int hasjournal, int journaldev, int largefile, int quota, int resizeinode, int sparsesuper, int uninitbg);
extern char **do_list_disk_labels (void);
extern int do_internal_hot_add_drive (const char *label);
extern int do_internal_hot_remove_drive_precheck (const char *label);
extern int do_internal_hot_remove_drive (const char *label);
extern char *do_mktemp (const char *tmpl, const char *suffix);
extern int do_mklost_and_found (const char *mountpoint);
extern char *do_acl_get_file (const char *path, const char *acltype);
extern int do_acl_set_file (const char *path, const char *acltype, const char *acl);
extern int do_acl_delete_def_file (const char *dir);
extern char *do_cap_get_file (const char *path);
extern int do_cap_set_file (const char *path, const char *cap);
extern char **do_list_ldm_volumes (void);
extern char **do_list_ldm_partitions (void);
extern int do_ldmtool_create_all (void);
extern int do_ldmtool_remove_all (void);
extern char **do_ldmtool_scan (void);
extern char **do_ldmtool_scan_devices (char *const *devices);
extern char *do_ldmtool_diskgroup_name (const char *diskgroup);
extern char **do_ldmtool_diskgroup_volumes (const char *diskgroup);
extern char **do_ldmtool_diskgroup_disks (const char *diskgroup);
extern char *do_ldmtool_volume_type (const char *diskgroup, const char *volume);
extern char *do_ldmtool_volume_hint (const char *diskgroup, const char *volume);
extern char **do_ldmtool_volume_partitions (const char *diskgroup, const char *volume);
extern int do_part_set_gpt_type (const char *device, int partnum, const char *guid);
extern char *do_part_get_gpt_type (const char *device, int partnum);
extern int do_rename (const char *oldpath, const char *newpath);
extern int do_is_whole_device (const char *device);
extern guestfs_int_internal_mountable *do_internal_parse_mountable (const mountable_t *mountable);
extern int do_internal_rhbz914931 (int count);
extern int do_feature_available (char *const *groups);
extern int do_syslinux (const char *device, const char *directory);
extern int do_extlinux (const char *directory);
extern int do_cp_r (const char *src, const char *dest);
extern int do_remount (const char *mountpoint, int rw);
extern int do_set_uuid (const char *device, const char *uuid);
extern int do_journal_open (const char *directory);
extern int do_journal_close (void);
extern int do_journal_next (void);
extern int64_t do_journal_skip (int64_t skip);
extern int do_internal_journal_get (void);
extern int64_t do_journal_get_data_threshold (void);
extern int do_journal_set_data_threshold (int64_t threshold);
extern int do_aug_setm (const char *base, const char *sub, const char *val);
extern char *do_aug_label (const char *augpath);
extern int do_internal_upload (const char *tmpname, int mode);
extern int do_internal_exit (void);
extern int do_copy_attributes (const char *src, const char *dest, int all, int mode, int xattributes, int ownership);
extern char *do_part_get_name (const char *device, int partnum);
extern int do_blkdiscard (const char *device);
extern int do_blkdiscardzeroes (const char *device);
extern int do_cpio_out (const char *directory, const char *format);
extern int64_t do_journal_get_realtime_usec (void);
extern guestfs_int_statns *do_statns (const char *path);
extern guestfs_int_statns *do_lstatns (const char *path);
extern guestfs_int_statns_list *do_internal_lstatnslist (const char *path, char *const *names);
extern int do_blockdev_setra (const char *device, int sectors);
extern int64_t do_btrfs_subvolume_get_default (const mountable_t *fs);
extern char **do_btrfs_subvolume_show (const char *subvolume);
extern int do_btrfs_quota_enable (const mountable_t *fs, int enable);
extern int do_btrfs_quota_rescan (const mountable_t *fs);
extern int do_btrfs_qgroup_limit (const char *subvolume, int64_t size);
extern int do_btrfs_qgroup_create (const char *qgroupid, const char *subvolume);
extern int do_btrfs_qgroup_destroy (const char *qgroupid, const char *subvolume);
extern guestfs_int_btrfsqgroup_list *do_btrfs_qgroup_show (const char *path);
extern int do_btrfs_qgroup_assign (const char *src, const char *dst, const char *path);
extern int do_btrfs_qgroup_remove (const char *src, const char *dst, const char *path);
extern int do_btrfs_scrub_start (const char *path);
extern int do_btrfs_scrub_cancel (const char *path);
extern int do_btrfs_scrub_resume (const char *path);
extern int do_btrfs_balance_pause (const char *path);
extern int do_btrfs_balance_cancel (const char *path);
extern int do_btrfs_balance_resume (const char *path);
extern int do_btrfs_filesystem_defragment (const char *path, int flush, const char *compress);
extern int do_btrfs_rescue_chunk_recover (const char *device);
extern int do_btrfs_rescue_super_recover (const char *device);
extern int do_part_set_gpt_guid (const char *device, int partnum, const char *guid);
extern char *do_part_get_gpt_guid (const char *device, int partnum);
extern guestfs_int_btrfsbalance *do_btrfs_balance_status (const char *path);
extern guestfs_int_btrfsscrub *do_btrfs_scrub_status (const char *path);
extern int do_btrfstune_seeding (const char *device, int seeding);
extern int do_btrfstune_enable_extended_inode_refs (const char *device);
extern int do_btrfstune_enable_skinny_metadata_extent_refs (const char *device);
extern int do_btrfs_image (char *const *source, const char *image, int compresslevel);
extern char *do_part_get_mbr_part_type (const char *device, int partnum);
extern int do_btrfs_replace (const char *srcdev, const char *targetdev, const char *mntpoint);
extern int do_set_uuid_random (const char *device);

#endif /* GUESTFSD_ACTIONS_H */
