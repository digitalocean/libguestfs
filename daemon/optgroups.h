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

#ifndef GUESTFSD_OPTGROUPS_H
#define GUESTFSD_OPTGROUPS_H

extern int optgroup_acl_available (void);
extern int optgroup_blkdiscard_available (void);
extern int optgroup_blkdiscardzeroes_available (void);
extern int optgroup_btrfs_available (void);
extern int optgroup_extlinux_available (void);
extern int optgroup_fstrim_available (void);
extern int optgroup_gdisk_available (void);
extern int optgroup_grub_available (void);
extern int optgroup_hivex_available (void);
extern int optgroup_inotify_available (void);
extern int optgroup_journal_available (void);
extern int optgroup_ldm_available (void);
extern int optgroup_linuxcaps_available (void);
extern int optgroup_linuxfsuuid_available (void);
extern int optgroup_linuxmodules_available (void);
extern int optgroup_linuxxattrs_available (void);
extern int optgroup_luks_available (void);
extern int optgroup_lvm2_available (void);
extern int optgroup_mdadm_available (void);
extern int optgroup_mknod_available (void);
extern int optgroup_ntfs3g_available (void);
extern int optgroup_ntfsprogs_available (void);
extern int optgroup_rsync_available (void);
extern int optgroup_scrub_available (void);
extern int optgroup_selinux_available (void);
extern int optgroup_syslinux_available (void);
extern int optgroup_wipefs_available (void);
extern int optgroup_xfs_available (void);
extern int optgroup_xz_available (void);
extern int optgroup_zerofree_available (void);

/* These macros can be used to disable an entire group of functions.
 * The advantage of generating this code is that it avoids an
 * undetected error when a new function in a group is added, but
 * the appropriate abort function is not added to the daemon (because
 * the developers rarely test that the daemon builds when a library
 * is not present).
 */

#define OPTGROUP_ACL_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_acl_delete_def_file (const char *dir) { abort (); } \
  char *__attribute__((noreturn)) do_acl_get_file (const char *path, const char *acltype) { abort (); } \
  int __attribute__((noreturn)) do_acl_set_file (const char *path, const char *acltype, const char *acl) { abort (); } \
  int optgroup_acl_available (void) { return 0; }

#define OPTGROUP_BLKDISCARD_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_blkdiscard (const char *device) { abort (); } \
  int optgroup_blkdiscard_available (void) { return 0; }

#define OPTGROUP_BLKDISCARDZEROES_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_blkdiscardzeroes (const char *device) { abort (); } \
  int optgroup_blkdiscardzeroes_available (void) { return 0; }

#define OPTGROUP_BTRFS_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_btrfs_balance_cancel (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_balance_pause (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_balance_resume (const char *path) { abort (); } \
  guestfs_int_btrfsbalance *__attribute__((noreturn)) do_btrfs_balance_status (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_device_add (char *const *devices, const char *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_device_delete (char *const *devices, const char *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_filesystem_balance (const char *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_filesystem_defragment (const char *path, int flush, const char *compress) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_filesystem_resize (const char *mountpoint, int64_t size) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_filesystem_sync (const char *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_fsck (const char *device, int64_t superblock, int repair) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_qgroup_assign (const char *src, const char *dst, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_qgroup_create (const char *qgroupid, const char *subvolume) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_qgroup_destroy (const char *qgroupid, const char *subvolume) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_qgroup_limit (const char *subvolume, int64_t size) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_qgroup_remove (const char *src, const char *dst, const char *path) { abort (); } \
  guestfs_int_btrfsqgroup_list *__attribute__((noreturn)) do_btrfs_qgroup_show (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_quota_enable (const mountable_t *fs, int enable) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_quota_rescan (const mountable_t *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_rescue_chunk_recover (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_rescue_super_recover (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_scrub_cancel (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_scrub_resume (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_scrub_start (const char *path) { abort (); } \
  guestfs_int_btrfsscrub *__attribute__((noreturn)) do_btrfs_scrub_status (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_set_seeding (const char *device, int seeding) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_subvolume_create (const char *dest, const char *qgroupid) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_subvolume_delete (const char *subvolume) { abort (); } \
  int64_t __attribute__((noreturn)) do_btrfs_subvolume_get_default (const mountable_t *fs) { abort (); } \
  guestfs_int_btrfssubvolume_list *__attribute__((noreturn)) do_btrfs_subvolume_list (const mountable_t *fs) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_subvolume_set_default (int64_t id, const char *fs) { abort (); } \
  char **__attribute__((noreturn)) do_btrfs_subvolume_show (const char *subvolume) { abort (); } \
  int __attribute__((noreturn)) do_btrfs_subvolume_snapshot (const char *source, const char *dest, int ro, const char *qgroupid) { abort (); } \
  int __attribute__((noreturn)) do_btrfstune_enable_extended_inode_refs (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_btrfstune_enable_skinny_metadata_extent_refs (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_btrfstune_seeding (const char *device, int seeding) { abort (); } \
  int __attribute__((noreturn)) do_mkfs_btrfs (char *const *devices, int64_t allocstart, int64_t bytecount, const char *datatype, int leafsize, const char *label, const char *metadata, int nodesize, int sectorsize) { abort (); } \
  int optgroup_btrfs_available (void) { return 0; }

#define OPTGROUP_EXTLINUX_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_extlinux (const char *directory) { abort (); } \
  int optgroup_extlinux_available (void) { return 0; }

#define OPTGROUP_FSTRIM_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_fstrim (const char *mountpoint, int64_t offset, int64_t length, int64_t minimumfreeextent) { abort (); } \
  int optgroup_fstrim_available (void) { return 0; }

#define OPTGROUP_GDISK_NOT_AVAILABLE \
  char *__attribute__((noreturn)) do_part_get_gpt_guid (const char *device, int partnum) { abort (); } \
  char *__attribute__((noreturn)) do_part_get_gpt_type (const char *device, int partnum) { abort (); } \
  int __attribute__((noreturn)) do_part_set_gpt_guid (const char *device, int partnum, const char *guid) { abort (); } \
  int __attribute__((noreturn)) do_part_set_gpt_type (const char *device, int partnum, const char *guid) { abort (); } \
  int optgroup_gdisk_available (void) { return 0; }

#define OPTGROUP_GRUB_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_grub_install (const char *root, const char *device) { abort (); } \
  int optgroup_grub_available (void) { return 0; }

#define OPTGROUP_HIVEX_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_hivex_close (void) { abort (); } \
  int __attribute__((noreturn)) do_hivex_commit (const char *filename) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_node_add_child (int64_t parent, const char *name) { abort (); } \
  guestfs_int_hivex_node_list *__attribute__((noreturn)) do_hivex_node_children (int64_t nodeh) { abort (); } \
  int __attribute__((noreturn)) do_hivex_node_delete_child (int64_t nodeh) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_node_get_child (int64_t nodeh, const char *name) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_node_get_value (int64_t nodeh, const char *key) { abort (); } \
  char *__attribute__((noreturn)) do_hivex_node_name (int64_t nodeh) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_node_parent (int64_t nodeh) { abort (); } \
  int __attribute__((noreturn)) do_hivex_node_set_value (int64_t nodeh, const char *key, int64_t t, const char *val, size_t val_size) { abort (); } \
  guestfs_int_hivex_value_list *__attribute__((noreturn)) do_hivex_node_values (int64_t nodeh) { abort (); } \
  int __attribute__((noreturn)) do_hivex_open (const char *filename, int verbose, int debug, int write) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_root (void) { abort (); } \
  char *__attribute__((noreturn)) do_hivex_value_key (int64_t valueh) { abort (); } \
  int64_t __attribute__((noreturn)) do_hivex_value_type (int64_t valueh) { abort (); } \
  char *__attribute__((noreturn)) do_hivex_value_value (int64_t valueh, size_t *size_r) { abort (); } \
  int optgroup_hivex_available (void) { return 0; }

#define OPTGROUP_INOTIFY_NOT_AVAILABLE \
  int64_t __attribute__((noreturn)) do_inotify_add_watch (const char *path, int mask) { abort (); } \
  int __attribute__((noreturn)) do_inotify_close (void) { abort (); } \
  char **__attribute__((noreturn)) do_inotify_files (void) { abort (); } \
  int __attribute__((noreturn)) do_inotify_init (int maxevents) { abort (); } \
  guestfs_int_inotify_event_list *__attribute__((noreturn)) do_inotify_read (void) { abort (); } \
  int __attribute__((noreturn)) do_inotify_rm_watch (int wd) { abort (); } \
  int optgroup_inotify_available (void) { return 0; }

#define OPTGROUP_JOURNAL_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_internal_journal_get (void) { abort (); } \
  int __attribute__((noreturn)) do_journal_close (void) { abort (); } \
  int64_t __attribute__((noreturn)) do_journal_get_data_threshold (void) { abort (); } \
  int64_t __attribute__((noreturn)) do_journal_get_realtime_usec (void) { abort (); } \
  int __attribute__((noreturn)) do_journal_next (void) { abort (); } \
  int __attribute__((noreturn)) do_journal_open (const char *directory) { abort (); } \
  int __attribute__((noreturn)) do_journal_set_data_threshold (int64_t threshold) { abort (); } \
  int64_t __attribute__((noreturn)) do_journal_skip (int64_t skip) { abort (); } \
  int optgroup_journal_available (void) { return 0; }

#define OPTGROUP_LDM_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_ldmtool_create_all (void) { abort (); } \
  char **__attribute__((noreturn)) do_ldmtool_diskgroup_disks (const char *diskgroup) { abort (); } \
  char *__attribute__((noreturn)) do_ldmtool_diskgroup_name (const char *diskgroup) { abort (); } \
  char **__attribute__((noreturn)) do_ldmtool_diskgroup_volumes (const char *diskgroup) { abort (); } \
  int __attribute__((noreturn)) do_ldmtool_remove_all (void) { abort (); } \
  char **__attribute__((noreturn)) do_ldmtool_scan (void) { abort (); } \
  char **__attribute__((noreturn)) do_ldmtool_scan_devices (char *const *devices) { abort (); } \
  char *__attribute__((noreturn)) do_ldmtool_volume_hint (const char *diskgroup, const char *volume) { abort (); } \
  char **__attribute__((noreturn)) do_ldmtool_volume_partitions (const char *diskgroup, const char *volume) { abort (); } \
  char *__attribute__((noreturn)) do_ldmtool_volume_type (const char *diskgroup, const char *volume) { abort (); } \
  char **__attribute__((noreturn)) do_list_ldm_partitions (void) { abort (); } \
  char **__attribute__((noreturn)) do_list_ldm_volumes (void) { abort (); } \
  int optgroup_ldm_available (void) { return 0; }

#define OPTGROUP_LINUXCAPS_NOT_AVAILABLE \
  char *__attribute__((noreturn)) do_cap_get_file (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_cap_set_file (const char *path, const char *cap) { abort (); } \
  int optgroup_linuxcaps_available (void) { return 0; }

#define OPTGROUP_LINUXFSUUID_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_mke2fs_JU (const char *fstype, int blocksize, const char *device, const char *uuid) { abort (); } \
  int __attribute__((noreturn)) do_mke2journal_U (int blocksize, const char *uuid, const char *device) { abort (); } \
  int __attribute__((noreturn)) do_mkswap_U (const char *uuid, const char *device) { abort (); } \
  int __attribute__((noreturn)) do_swapoff_uuid (const char *uuid) { abort (); } \
  int __attribute__((noreturn)) do_swapon_uuid (const char *uuid) { abort (); } \
  int optgroup_linuxfsuuid_available (void) { return 0; }

#define OPTGROUP_LINUXMODULES_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_modprobe (const char *modulename) { abort (); } \
  int optgroup_linuxmodules_available (void) { return 0; }

#define OPTGROUP_LINUXXATTRS_NOT_AVAILABLE \
  char *__attribute__((noreturn)) do_getxattr (const char *path, const char *name, size_t *size_r) { abort (); } \
  guestfs_int_xattr_list *__attribute__((noreturn)) do_getxattrs (const char *path) { abort (); } \
  guestfs_int_xattr_list *__attribute__((noreturn)) do_internal_lxattrlist (const char *path, char *const *names) { abort (); } \
  char *__attribute__((noreturn)) do_lgetxattr (const char *path, const char *name, size_t *size_r) { abort (); } \
  guestfs_int_xattr_list *__attribute__((noreturn)) do_lgetxattrs (const char *path) { abort (); } \
  int __attribute__((noreturn)) do_lremovexattr (const char *xattr, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_lsetxattr (const char *xattr, const char *val, int vallen, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_removexattr (const char *xattr, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_setxattr (const char *xattr, const char *val, int vallen, const char *path) { abort (); } \
  int optgroup_linuxxattrs_available (void) { return 0; }

#define OPTGROUP_LUKS_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_luks_add_key (const char *device, const char *key, const char *newkey, int keyslot) { abort (); } \
  int __attribute__((noreturn)) do_luks_close (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_luks_format (const char *device, const char *key, int keyslot) { abort (); } \
  int __attribute__((noreturn)) do_luks_format_cipher (const char *device, const char *key, int keyslot, const char *cipher) { abort (); } \
  int __attribute__((noreturn)) do_luks_kill_slot (const char *device, const char *key, int keyslot) { abort (); } \
  int __attribute__((noreturn)) do_luks_open (const char *device, const char *key, const char *mapname) { abort (); } \
  int __attribute__((noreturn)) do_luks_open_ro (const char *device, const char *key, const char *mapname) { abort (); } \
  int optgroup_luks_available (void) { return 0; }

#define OPTGROUP_LVM2_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_lvcreate (const char *logvol, const char *volgroup, int mbytes) { abort (); } \
  int __attribute__((noreturn)) do_lvcreate_free (const char *logvol, const char *volgroup, int percent) { abort (); } \
  int __attribute__((noreturn)) do_lvm_remove_all (void) { abort (); } \
  int __attribute__((noreturn)) do_lvm_set_filter (char *const *devices) { abort (); } \
  int __attribute__((noreturn)) do_lvremove (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_lvresize (const char *device, int mbytes) { abort (); } \
  int __attribute__((noreturn)) do_lvresize_free (const char *lv, int percent) { abort (); } \
  char **__attribute__((noreturn)) do_lvs (void) { abort (); } \
  guestfs_int_lvm_lv_list *__attribute__((noreturn)) do_lvs_full (void) { abort (); } \
  int __attribute__((noreturn)) do_pvchange_uuid (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_pvchange_uuid_all (void) { abort (); } \
  int __attribute__((noreturn)) do_pvcreate (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_pvremove (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_pvresize (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_pvresize_size (const char *device, int64_t size) { abort (); } \
  char **__attribute__((noreturn)) do_pvs (void) { abort (); } \
  guestfs_int_lvm_pv_list *__attribute__((noreturn)) do_pvs_full (void) { abort (); } \
  int __attribute__((noreturn)) do_vg_activate (int activate, char *const *volgroups) { abort (); } \
  int __attribute__((noreturn)) do_vg_activate_all (int activate) { abort (); } \
  int __attribute__((noreturn)) do_vgchange_uuid (const char *vg) { abort (); } \
  int __attribute__((noreturn)) do_vgchange_uuid_all (void) { abort (); } \
  int __attribute__((noreturn)) do_vgcreate (const char *volgroup, char *const *physvols) { abort (); } \
  char *__attribute__((noreturn)) do_vgmeta (const char *vgname, size_t *size_r) { abort (); } \
  int __attribute__((noreturn)) do_vgremove (const char *vgname) { abort (); } \
  char **__attribute__((noreturn)) do_vgs (void) { abort (); } \
  guestfs_int_lvm_vg_list *__attribute__((noreturn)) do_vgs_full (void) { abort (); } \
  int optgroup_lvm2_available (void) { return 0; }

#define OPTGROUP_MDADM_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_md_create (const char *name, char *const *devices, int64_t missingbitmap, int nrdevices, int spare, int64_t chunk, const char *level) { abort (); } \
  char **__attribute__((noreturn)) do_md_detail (const char *md) { abort (); } \
  guestfs_int_mdstat_list *__attribute__((noreturn)) do_md_stat (const char *md) { abort (); } \
  int __attribute__((noreturn)) do_md_stop (const char *md) { abort (); } \
  int optgroup_mdadm_available (void) { return 0; }

#define OPTGROUP_MKNOD_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_mkfifo (int mode, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_mknod (int mode, int devmajor, int devminor, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_mknod_b (int mode, int devmajor, int devminor, const char *path) { abort (); } \
  int __attribute__((noreturn)) do_mknod_c (int mode, int devmajor, int devminor, const char *path) { abort (); } \
  int optgroup_mknod_available (void) { return 0; }

#define OPTGROUP_NTFS3G_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_ntfs_3g_probe (int rw, const char *device) { abort (); } \
  int __attribute__((noreturn)) do_ntfsclone_in (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_ntfsclone_out (const char *device, int metadataonly, int rescue, int ignorefscheck, int preservetimestamps, int force) { abort (); } \
  int __attribute__((noreturn)) do_ntfsfix (const char *device, int clearbadsectors) { abort (); } \
  int optgroup_ntfs3g_available (void) { return 0; }

#define OPTGROUP_NTFSPROGS_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_ntfsresize (const char *device, int64_t size, int force) { abort (); } \
  int __attribute__((noreturn)) do_ntfsresize_size (const char *device, int64_t size) { abort (); } \
  int optgroup_ntfsprogs_available (void) { return 0; }

#define OPTGROUP_RSYNC_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_rsync (const char *src, const char *dest, int archive, int deletedest) { abort (); } \
  int __attribute__((noreturn)) do_rsync_in (const char *remote, const char *dest, int archive, int deletedest) { abort (); } \
  int __attribute__((noreturn)) do_rsync_out (const char *src, const char *remote, int archive, int deletedest) { abort (); } \
  int optgroup_rsync_available (void) { return 0; }

#define OPTGROUP_SCRUB_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_scrub_device (const char *device) { abort (); } \
  int __attribute__((noreturn)) do_scrub_file (const char *file) { abort (); } \
  int __attribute__((noreturn)) do_scrub_freespace (const char *dir) { abort (); } \
  int optgroup_scrub_available (void) { return 0; }

#define OPTGROUP_SELINUX_NOT_AVAILABLE \
  char *__attribute__((noreturn)) do_getcon (void) { abort (); } \
  int __attribute__((noreturn)) do_setcon (const char *context) { abort (); } \
  int optgroup_selinux_available (void) { return 0; }

#define OPTGROUP_SYSLINUX_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_syslinux (const char *device, const char *directory) { abort (); } \
  int optgroup_syslinux_available (void) { return 0; }

#define OPTGROUP_WIPEFS_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_wipefs (const char *device) { abort (); } \
  int optgroup_wipefs_available (void) { return 0; }

#define OPTGROUP_XFS_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_xfs_admin (const char *device, int extunwritten, int imgfile, int v2log, int projid32bit, int lazycounter, const char *label, const char *uuid) { abort (); } \
  int __attribute__((noreturn)) do_xfs_growfs (const char *path, int datasec, int logsec, int rtsec, int64_t datasize, int64_t logsize, int64_t rtsize, int64_t rtextsize, int maxpct) { abort (); } \
  guestfs_int_xfsinfo *__attribute__((noreturn)) do_xfs_info (const char *pathordevice) { abort (); } \
  int __attribute__((noreturn)) do_xfs_repair (const char *device, int forcelogzero, int nomodify, int noprefetch, int forcegeometry, int64_t maxmem, int64_t ihashsize, int64_t bhashsize, int64_t agstride, const char *logdev, const char *rtdev) { abort (); } \
  int optgroup_xfs_available (void) { return 0; }

#define OPTGROUP_XZ_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_txz_in (const char *directory) { abort (); } \
  int __attribute__((noreturn)) do_txz_out (const char *directory) { abort (); } \
  int optgroup_xz_available (void) { return 0; }

#define OPTGROUP_ZEROFREE_NOT_AVAILABLE \
  int __attribute__((noreturn)) do_zerofree (const char *device) { abort (); } \
  int optgroup_zerofree_available (void) { return 0; }

#endif /* GUESTFSD_OPTGROUPS_H */
