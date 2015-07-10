/* libguestfs generated file -*- c -*-
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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

/* This file defines the protocol used between the library and
 * the appliance/daemon.  For more information see the COMMUNICATION
 * PROTOCOL section in guestfs(3).  Note this protocol is internal
 * to libguestfs and may change at any time.
 */

%#include <config.h>

/* This has to be defined to get around a limitation in Mac OS X's rpcgen. */
#if HAVE_XDR_U_INT64_T
#define uint64_t u_int64_t
%#if HAVE_XDR_UINT64_T
%#define xdr_u_int64_t xdr_uint64_t
%#define u_int64_t uint64_t
%#endif
#else
%#if HAVE_XDR_U_INT64_T
%#define xdr_uint64_t xdr_u_int64_t
%#define uint64_t u_int64_t
%#endif
#endif

/* This has to be defined to get around a limitation in Sun's rpcgen. */
typedef string guestfs_str<>;

/* Internal structures. */

struct guestfs_int_int_bool {
  int i;
  int b;
};

typedef struct guestfs_int_int_bool guestfs_int_int_bool_list<>;

struct guestfs_int_lvm_pv {
  string pv_name<>;
  opaque pv_uuid[32];
  string pv_fmt<>;
  int64_t pv_size;
  int64_t dev_size;
  int64_t pv_free;
  int64_t pv_used;
  string pv_attr<>;
  int64_t pv_pe_count;
  int64_t pv_pe_alloc_count;
  string pv_tags<>;
  int64_t pe_start;
  int64_t pv_mda_count;
  int64_t pv_mda_free;
};

typedef struct guestfs_int_lvm_pv guestfs_int_lvm_pv_list<>;

struct guestfs_int_lvm_vg {
  string vg_name<>;
  opaque vg_uuid[32];
  string vg_fmt<>;
  string vg_attr<>;
  int64_t vg_size;
  int64_t vg_free;
  string vg_sysid<>;
  int64_t vg_extent_size;
  int64_t vg_extent_count;
  int64_t vg_free_count;
  int64_t max_lv;
  int64_t max_pv;
  int64_t pv_count;
  int64_t lv_count;
  int64_t snap_count;
  int64_t vg_seqno;
  string vg_tags<>;
  int64_t vg_mda_count;
  int64_t vg_mda_free;
};

typedef struct guestfs_int_lvm_vg guestfs_int_lvm_vg_list<>;

struct guestfs_int_lvm_lv {
  string lv_name<>;
  opaque lv_uuid[32];
  string lv_attr<>;
  int64_t lv_major;
  int64_t lv_minor;
  int64_t lv_kernel_major;
  int64_t lv_kernel_minor;
  int64_t lv_size;
  int64_t seg_count;
  string origin<>;
  float snap_percent;
  float copy_percent;
  string move_pv<>;
  string lv_tags<>;
  string mirror_log<>;
  string modules<>;
};

typedef struct guestfs_int_lvm_lv guestfs_int_lvm_lv_list<>;

struct guestfs_int_stat {
  int64_t dev;
  int64_t ino;
  int64_t mode;
  int64_t nlink;
  int64_t uid;
  int64_t gid;
  int64_t rdev;
  int64_t size;
  int64_t blksize;
  int64_t blocks;
  int64_t atime;
  int64_t mtime;
  int64_t ctime;
};

typedef struct guestfs_int_stat guestfs_int_stat_list<>;

struct guestfs_int_statns {
  int64_t st_dev;
  int64_t st_ino;
  int64_t st_mode;
  int64_t st_nlink;
  int64_t st_uid;
  int64_t st_gid;
  int64_t st_rdev;
  int64_t st_size;
  int64_t st_blksize;
  int64_t st_blocks;
  int64_t st_atime_sec;
  int64_t st_atime_nsec;
  int64_t st_mtime_sec;
  int64_t st_mtime_nsec;
  int64_t st_ctime_sec;
  int64_t st_ctime_nsec;
  int64_t st_spare1;
  int64_t st_spare2;
  int64_t st_spare3;
  int64_t st_spare4;
  int64_t st_spare5;
  int64_t st_spare6;
};

typedef struct guestfs_int_statns guestfs_int_statns_list<>;

struct guestfs_int_statvfs {
  int64_t bsize;
  int64_t frsize;
  int64_t blocks;
  int64_t bfree;
  int64_t bavail;
  int64_t files;
  int64_t ffree;
  int64_t favail;
  int64_t fsid;
  int64_t flag;
  int64_t namemax;
};

typedef struct guestfs_int_statvfs guestfs_int_statvfs_list<>;

struct guestfs_int_dirent {
  int64_t ino;
  char ftyp;
  string name<>;
};

typedef struct guestfs_int_dirent guestfs_int_dirent_list<>;

struct guestfs_int_version {
  int64_t major;
  int64_t minor;
  int64_t release;
  string extra<>;
};

typedef struct guestfs_int_version guestfs_int_version_list<>;

struct guestfs_int_xattr {
  string attrname<>;
  opaque attrval<>;
};

typedef struct guestfs_int_xattr guestfs_int_xattr_list<>;

struct guestfs_int_inotify_event {
  int64_t in_wd;
  unsigned int in_mask;
  unsigned int in_cookie;
  string in_name<>;
};

typedef struct guestfs_int_inotify_event guestfs_int_inotify_event_list<>;

struct guestfs_int_partition {
  int part_num;
  int64_t part_start;
  int64_t part_end;
  int64_t part_size;
};

typedef struct guestfs_int_partition guestfs_int_partition_list<>;

struct guestfs_int_application {
  string app_name<>;
  string app_display_name<>;
  int app_epoch;
  string app_version<>;
  string app_release<>;
  string app_install_path<>;
  string app_trans_path<>;
  string app_publisher<>;
  string app_url<>;
  string app_source_package<>;
  string app_summary<>;
  string app_description<>;
};

typedef struct guestfs_int_application guestfs_int_application_list<>;

struct guestfs_int_application2 {
  string app2_name<>;
  string app2_display_name<>;
  int app2_epoch;
  string app2_version<>;
  string app2_release<>;
  string app2_arch<>;
  string app2_install_path<>;
  string app2_trans_path<>;
  string app2_publisher<>;
  string app2_url<>;
  string app2_source_package<>;
  string app2_summary<>;
  string app2_description<>;
  string app2_spare1<>;
  string app2_spare2<>;
  string app2_spare3<>;
  string app2_spare4<>;
};

typedef struct guestfs_int_application2 guestfs_int_application2_list<>;

struct guestfs_int_isoinfo {
  string iso_system_id<>;
  string iso_volume_id<>;
  unsigned int iso_volume_space_size;
  unsigned int iso_volume_set_size;
  unsigned int iso_volume_sequence_number;
  unsigned int iso_logical_block_size;
  string iso_volume_set_id<>;
  string iso_publisher_id<>;
  string iso_data_preparer_id<>;
  string iso_application_id<>;
  string iso_copyright_file_id<>;
  string iso_abstract_file_id<>;
  string iso_bibliographic_file_id<>;
  int64_t iso_volume_creation_t;
  int64_t iso_volume_modification_t;
  int64_t iso_volume_expiration_t;
  int64_t iso_volume_effective_t;
};

typedef struct guestfs_int_isoinfo guestfs_int_isoinfo_list<>;

struct guestfs_int_mdstat {
  string mdstat_device<>;
  int mdstat_index;
  string mdstat_flags<>;
};

typedef struct guestfs_int_mdstat guestfs_int_mdstat_list<>;

struct guestfs_int_btrfssubvolume {
  uint64_t btrfssubvolume_id;
  uint64_t btrfssubvolume_top_level_id;
  string btrfssubvolume_path<>;
};

typedef struct guestfs_int_btrfssubvolume guestfs_int_btrfssubvolume_list<>;

struct guestfs_int_btrfsqgroup {
  string btrfsqgroup_id<>;
  uint64_t btrfsqgroup_rfer;
  uint64_t btrfsqgroup_excl;
};

typedef struct guestfs_int_btrfsqgroup guestfs_int_btrfsqgroup_list<>;

struct guestfs_int_btrfsbalance {
  string btrfsbalance_status<>;
  uint64_t btrfsbalance_total;
  uint64_t btrfsbalance_balanced;
  uint64_t btrfsbalance_considered;
  uint64_t btrfsbalance_left;
};

typedef struct guestfs_int_btrfsbalance guestfs_int_btrfsbalance_list<>;

struct guestfs_int_btrfsscrub {
  uint64_t btrfsscrub_data_extents_scrubbed;
  uint64_t btrfsscrub_tree_extents_scrubbed;
  uint64_t btrfsscrub_data_bytes_scrubbed;
  uint64_t btrfsscrub_tree_bytes_scrubbed;
  uint64_t btrfsscrub_read_errors;
  uint64_t btrfsscrub_csum_errors;
  uint64_t btrfsscrub_verify_errors;
  uint64_t btrfsscrub_no_csum;
  uint64_t btrfsscrub_csum_discards;
  uint64_t btrfsscrub_super_errors;
  uint64_t btrfsscrub_malloc_errors;
  uint64_t btrfsscrub_uncorrectable_errors;
  uint64_t btrfsscrub_unverified_errors;
  uint64_t btrfsscrub_corrected_errors;
  uint64_t btrfsscrub_last_physical;
};

typedef struct guestfs_int_btrfsscrub guestfs_int_btrfsscrub_list<>;

struct guestfs_int_xfsinfo {
  string xfs_mntpoint<>;
  unsigned int xfs_inodesize;
  unsigned int xfs_agcount;
  unsigned int xfs_agsize;
  unsigned int xfs_sectsize;
  unsigned int xfs_attr;
  unsigned int xfs_blocksize;
  uint64_t xfs_datablocks;
  unsigned int xfs_imaxpct;
  unsigned int xfs_sunit;
  unsigned int xfs_swidth;
  unsigned int xfs_dirversion;
  unsigned int xfs_dirblocksize;
  unsigned int xfs_cimode;
  string xfs_logname<>;
  unsigned int xfs_logblocksize;
  unsigned int xfs_logblocks;
  unsigned int xfs_logversion;
  unsigned int xfs_logsectsize;
  unsigned int xfs_logsunit;
  unsigned int xfs_lazycount;
  string xfs_rtname<>;
  unsigned int xfs_rtextsize;
  uint64_t xfs_rtblocks;
  uint64_t xfs_rtextents;
};

typedef struct guestfs_int_xfsinfo guestfs_int_xfsinfo_list<>;

struct guestfs_int_utsname {
  string uts_sysname<>;
  string uts_release<>;
  string uts_version<>;
  string uts_machine<>;
};

typedef struct guestfs_int_utsname guestfs_int_utsname_list<>;

struct guestfs_int_hivex_node {
  int64_t hivex_node_h;
};

typedef struct guestfs_int_hivex_node guestfs_int_hivex_node_list<>;

struct guestfs_int_hivex_value {
  int64_t hivex_value_h;
};

typedef struct guestfs_int_hivex_value guestfs_int_hivex_value_list<>;

struct guestfs_int_internal_mountable {
  int im_type;
  string im_device<>;
  string im_volume<>;
};

typedef struct guestfs_int_internal_mountable guestfs_int_internal_mountable_list<>;

/* Function arguments and return values. */

struct guestfs_mount_args {
  string mountable<>;
  string mountpoint<>;
};

struct guestfs_touch_args {
  string path<>;
};

struct guestfs_ll_args {
  string directory<>;
};

struct guestfs_ll_ret {
  string listing<>;
};

struct guestfs_list_devices_ret {
  guestfs_str devices<>;
};

struct guestfs_list_partitions_ret {
  guestfs_str partitions<>;
};

struct guestfs_pvs_ret {
  guestfs_str physvols<>;
};

struct guestfs_vgs_ret {
  guestfs_str volgroups<>;
};

struct guestfs_lvs_ret {
  guestfs_str logvols<>;
};

struct guestfs_pvs_full_ret {
  guestfs_int_lvm_pv_list physvols;
};

struct guestfs_vgs_full_ret {
  guestfs_int_lvm_vg_list volgroups;
};

struct guestfs_lvs_full_ret {
  guestfs_int_lvm_lv_list logvols;
};

struct guestfs_aug_init_args {
  string root<>;
  int flags;
};

struct guestfs_aug_defvar_args {
  string name<>;
  guestfs_str *expr;
};

struct guestfs_aug_defvar_ret {
  int nrnodes;
};

struct guestfs_aug_defnode_args {
  string name<>;
  string expr<>;
  string val<>;
};

struct guestfs_aug_defnode_ret {
  guestfs_int_int_bool nrnodescreated;
};

struct guestfs_aug_get_args {
  string augpath<>;
};

struct guestfs_aug_get_ret {
  string val<>;
};

struct guestfs_aug_set_args {
  string augpath<>;
  string val<>;
};

struct guestfs_aug_insert_args {
  string augpath<>;
  string label<>;
  bool before;
};

struct guestfs_aug_rm_args {
  string augpath<>;
};

struct guestfs_aug_rm_ret {
  int nrnodes;
};

struct guestfs_aug_mv_args {
  string src<>;
  string dest<>;
};

struct guestfs_aug_match_args {
  string augpath<>;
};

struct guestfs_aug_match_ret {
  guestfs_str matches<>;
};

struct guestfs_aug_ls_args {
  string augpath<>;
};

struct guestfs_aug_ls_ret {
  guestfs_str matches<>;
};

struct guestfs_rm_args {
  string path<>;
};

struct guestfs_rmdir_args {
  string path<>;
};

struct guestfs_rm_rf_args {
  string path<>;
};

struct guestfs_mkdir_args {
  string path<>;
};

struct guestfs_mkdir_p_args {
  string path<>;
};

struct guestfs_chmod_args {
  int mode;
  string path<>;
};

struct guestfs_chown_args {
  int owner;
  int group;
  string path<>;
};

struct guestfs_exists_args {
  string path<>;
};

struct guestfs_exists_ret {
  bool existsflag;
};

struct guestfs_is_file_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_file_ret {
  bool fileflag;
};

struct guestfs_is_dir_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_dir_ret {
  bool dirflag;
};

struct guestfs_pvcreate_args {
  string device<>;
};

struct guestfs_vgcreate_args {
  string volgroup<>;
  guestfs_str physvols<>;
};

struct guestfs_lvcreate_args {
  string logvol<>;
  string volgroup<>;
  int mbytes;
};

struct guestfs_sfdisk_args {
  string device<>;
  int cyls;
  int heads;
  int sectors;
  guestfs_str lines<>;
};

struct guestfs_write_file_args {
  string path<>;
  string content<>;
  int size;
};

struct guestfs_umount_args {
  string pathordevice<>;
  bool force;
  bool lazyunmount;
};

struct guestfs_mounts_ret {
  guestfs_str devices<>;
};

struct guestfs_file_args {
  string path<>;
};

struct guestfs_file_ret {
  string description<>;
};

struct guestfs_command_args {
  guestfs_str arguments<>;
};

struct guestfs_command_ret {
  string output<>;
};

struct guestfs_command_lines_args {
  guestfs_str arguments<>;
};

struct guestfs_command_lines_ret {
  guestfs_str lines<>;
};

struct guestfs_statvfs_args {
  string path<>;
};

struct guestfs_statvfs_ret {
  guestfs_int_statvfs statbuf;
};

struct guestfs_tune2fs_l_args {
  string device<>;
};

struct guestfs_tune2fs_l_ret {
  guestfs_str superblock<>;
};

struct guestfs_blockdev_setro_args {
  string device<>;
};

struct guestfs_blockdev_setrw_args {
  string device<>;
};

struct guestfs_blockdev_getro_args {
  string device<>;
};

struct guestfs_blockdev_getro_ret {
  bool ro;
};

struct guestfs_blockdev_getss_args {
  string device<>;
};

struct guestfs_blockdev_getss_ret {
  int sectorsize;
};

struct guestfs_blockdev_getbsz_args {
  string device<>;
};

struct guestfs_blockdev_getbsz_ret {
  int blocksize;
};

struct guestfs_blockdev_setbsz_args {
  string device<>;
  int blocksize;
};

struct guestfs_blockdev_getsz_args {
  string device<>;
};

struct guestfs_blockdev_getsz_ret {
  int64_t sizeinsectors;
};

struct guestfs_blockdev_getsize64_args {
  string device<>;
};

struct guestfs_blockdev_getsize64_ret {
  int64_t sizeinbytes;
};

struct guestfs_blockdev_flushbufs_args {
  string device<>;
};

struct guestfs_blockdev_rereadpt_args {
  string device<>;
};

struct guestfs_upload_args {
  string remotefilename<>;
};

struct guestfs_download_args {
  string remotefilename<>;
};

struct guestfs_checksum_args {
  string csumtype<>;
  string path<>;
};

struct guestfs_checksum_ret {
  string checksum<>;
};

struct guestfs_tar_in_args {
  string directory<>;
  string compress<>;
};

struct guestfs_tar_out_args {
  string directory<>;
  string compress<>;
  bool numericowner;
  guestfs_str excludes<>;
};

struct guestfs_tgz_in_args {
  string directory<>;
};

struct guestfs_tgz_out_args {
  string directory<>;
};

struct guestfs_mount_ro_args {
  string mountable<>;
  string mountpoint<>;
};

struct guestfs_mount_options_args {
  string options<>;
  string mountable<>;
  string mountpoint<>;
};

struct guestfs_mount_vfs_args {
  string options<>;
  string vfstype<>;
  string mountable<>;
  string mountpoint<>;
};

struct guestfs_debug_args {
  string subcmd<>;
  guestfs_str extraargs<>;
};

struct guestfs_debug_ret {
  string result<>;
};

struct guestfs_lvremove_args {
  string device<>;
};

struct guestfs_vgremove_args {
  string vgname<>;
};

struct guestfs_pvremove_args {
  string device<>;
};

struct guestfs_set_e2label_args {
  string device<>;
  string label<>;
};

struct guestfs_get_e2label_args {
  string device<>;
};

struct guestfs_get_e2label_ret {
  string label<>;
};

struct guestfs_set_e2uuid_args {
  string device<>;
  string uuid<>;
};

struct guestfs_get_e2uuid_args {
  string device<>;
};

struct guestfs_get_e2uuid_ret {
  string uuid<>;
};

struct guestfs_fsck_args {
  string fstype<>;
  string device<>;
};

struct guestfs_fsck_ret {
  int status;
};

struct guestfs_zero_args {
  string device<>;
};

struct guestfs_grub_install_args {
  string root<>;
  string device<>;
};

struct guestfs_cp_args {
  string src<>;
  string dest<>;
};

struct guestfs_cp_a_args {
  string src<>;
  string dest<>;
};

struct guestfs_mv_args {
  string src<>;
  string dest<>;
};

struct guestfs_drop_caches_args {
  int whattodrop;
};

struct guestfs_dmesg_ret {
  string kmsgs<>;
};

struct guestfs_equal_args {
  string file1<>;
  string file2<>;
};

struct guestfs_equal_ret {
  bool equality;
};

struct guestfs_strings_args {
  string path<>;
};

struct guestfs_strings_ret {
  guestfs_str stringsout<>;
};

struct guestfs_strings_e_args {
  string encoding<>;
  string path<>;
};

struct guestfs_strings_e_ret {
  guestfs_str stringsout<>;
};

struct guestfs_hexdump_args {
  string path<>;
};

struct guestfs_hexdump_ret {
  string dump<>;
};

struct guestfs_zerofree_args {
  string device<>;
};

struct guestfs_pvresize_args {
  string device<>;
};

struct guestfs_sfdisk_N_args {
  string device<>;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  string line<>;
};

struct guestfs_sfdisk_l_args {
  string device<>;
};

struct guestfs_sfdisk_l_ret {
  string partitions<>;
};

struct guestfs_sfdisk_kernel_geometry_args {
  string device<>;
};

struct guestfs_sfdisk_kernel_geometry_ret {
  string partitions<>;
};

struct guestfs_sfdisk_disk_geometry_args {
  string device<>;
};

struct guestfs_sfdisk_disk_geometry_ret {
  string partitions<>;
};

struct guestfs_vg_activate_all_args {
  bool activate;
};

struct guestfs_vg_activate_args {
  bool activate;
  guestfs_str volgroups<>;
};

struct guestfs_lvresize_args {
  string device<>;
  int mbytes;
};

struct guestfs_resize2fs_args {
  string device<>;
};

struct guestfs_e2fsck_f_args {
  string device<>;
};

struct guestfs_sleep_args {
  int secs;
};

struct guestfs_ntfs_3g_probe_args {
  bool rw;
  string device<>;
};

struct guestfs_ntfs_3g_probe_ret {
  int status;
};

struct guestfs_sh_args {
  string command<>;
};

struct guestfs_sh_ret {
  string output<>;
};

struct guestfs_sh_lines_args {
  string command<>;
};

struct guestfs_sh_lines_ret {
  guestfs_str lines<>;
};

struct guestfs_glob_expand_args {
  string pattern<>;
};

struct guestfs_glob_expand_ret {
  guestfs_str paths<>;
};

struct guestfs_scrub_device_args {
  string device<>;
};

struct guestfs_scrub_file_args {
  string file<>;
};

struct guestfs_scrub_freespace_args {
  string dir<>;
};

struct guestfs_mkdtemp_args {
  string tmpl<>;
};

struct guestfs_mkdtemp_ret {
  string dir<>;
};

struct guestfs_wc_l_args {
  string path<>;
};

struct guestfs_wc_l_ret {
  int lines;
};

struct guestfs_wc_w_args {
  string path<>;
};

struct guestfs_wc_w_ret {
  int words;
};

struct guestfs_wc_c_args {
  string path<>;
};

struct guestfs_wc_c_ret {
  int chars;
};

struct guestfs_head_args {
  string path<>;
};

struct guestfs_head_ret {
  guestfs_str lines<>;
};

struct guestfs_head_n_args {
  int nrlines;
  string path<>;
};

struct guestfs_head_n_ret {
  guestfs_str lines<>;
};

struct guestfs_tail_args {
  string path<>;
};

struct guestfs_tail_ret {
  guestfs_str lines<>;
};

struct guestfs_tail_n_args {
  int nrlines;
  string path<>;
};

struct guestfs_tail_n_ret {
  guestfs_str lines<>;
};

struct guestfs_df_ret {
  string output<>;
};

struct guestfs_df_h_ret {
  string output<>;
};

struct guestfs_du_args {
  string path<>;
};

struct guestfs_du_ret {
  int64_t sizekb;
};

struct guestfs_initrd_list_args {
  string path<>;
};

struct guestfs_initrd_list_ret {
  guestfs_str filenames<>;
};

struct guestfs_mount_loop_args {
  string file<>;
  string mountpoint<>;
};

struct guestfs_mkswap_args {
  string device<>;
  string label<>;
  string uuid<>;
};

struct guestfs_mkswap_L_args {
  string label<>;
  string device<>;
};

struct guestfs_mkswap_U_args {
  string uuid<>;
  string device<>;
};

struct guestfs_mknod_args {
  int mode;
  int devmajor;
  int devminor;
  string path<>;
};

struct guestfs_mkfifo_args {
  int mode;
  string path<>;
};

struct guestfs_mknod_b_args {
  int mode;
  int devmajor;
  int devminor;
  string path<>;
};

struct guestfs_mknod_c_args {
  int mode;
  int devmajor;
  int devminor;
  string path<>;
};

struct guestfs_umask_args {
  int mask;
};

struct guestfs_umask_ret {
  int oldmask;
};

struct guestfs_readdir_args {
  string dir<>;
};

struct guestfs_readdir_ret {
  guestfs_int_dirent_list entries;
};

struct guestfs_sfdiskM_args {
  string device<>;
  guestfs_str lines<>;
};

struct guestfs_zfile_args {
  string meth<>;
  string path<>;
};

struct guestfs_zfile_ret {
  string description<>;
};

struct guestfs_getxattrs_args {
  string path<>;
};

struct guestfs_getxattrs_ret {
  guestfs_int_xattr_list xattrs;
};

struct guestfs_lgetxattrs_args {
  string path<>;
};

struct guestfs_lgetxattrs_ret {
  guestfs_int_xattr_list xattrs;
};

struct guestfs_setxattr_args {
  string xattr<>;
  string val<>;
  int vallen;
  string path<>;
};

struct guestfs_lsetxattr_args {
  string xattr<>;
  string val<>;
  int vallen;
  string path<>;
};

struct guestfs_removexattr_args {
  string xattr<>;
  string path<>;
};

struct guestfs_lremovexattr_args {
  string xattr<>;
  string path<>;
};

struct guestfs_mountpoints_ret {
  guestfs_str mps<>;
};

struct guestfs_mkmountpoint_args {
  string exemptpath<>;
};

struct guestfs_rmmountpoint_args {
  string exemptpath<>;
};

struct guestfs_grep_args {
  string regex<>;
  string path<>;
  bool extended;
  bool fixed;
  bool insensitive;
  bool compressed;
};

struct guestfs_grep_ret {
  guestfs_str lines<>;
};

struct guestfs_egrep_args {
  string regex<>;
  string path<>;
};

struct guestfs_egrep_ret {
  guestfs_str lines<>;
};

struct guestfs_fgrep_args {
  string pattern<>;
  string path<>;
};

struct guestfs_fgrep_ret {
  guestfs_str lines<>;
};

struct guestfs_grepi_args {
  string regex<>;
  string path<>;
};

struct guestfs_grepi_ret {
  guestfs_str lines<>;
};

struct guestfs_egrepi_args {
  string regex<>;
  string path<>;
};

struct guestfs_egrepi_ret {
  guestfs_str lines<>;
};

struct guestfs_fgrepi_args {
  string pattern<>;
  string path<>;
};

struct guestfs_fgrepi_ret {
  guestfs_str lines<>;
};

struct guestfs_zgrep_args {
  string regex<>;
  string path<>;
};

struct guestfs_zgrep_ret {
  guestfs_str lines<>;
};

struct guestfs_zegrep_args {
  string regex<>;
  string path<>;
};

struct guestfs_zegrep_ret {
  guestfs_str lines<>;
};

struct guestfs_zfgrep_args {
  string pattern<>;
  string path<>;
};

struct guestfs_zfgrep_ret {
  guestfs_str lines<>;
};

struct guestfs_zgrepi_args {
  string regex<>;
  string path<>;
};

struct guestfs_zgrepi_ret {
  guestfs_str lines<>;
};

struct guestfs_zegrepi_args {
  string regex<>;
  string path<>;
};

struct guestfs_zegrepi_ret {
  guestfs_str lines<>;
};

struct guestfs_zfgrepi_args {
  string pattern<>;
  string path<>;
};

struct guestfs_zfgrepi_ret {
  guestfs_str lines<>;
};

struct guestfs_realpath_args {
  string path<>;
};

struct guestfs_realpath_ret {
  string rpath<>;
};

struct guestfs_ln_args {
  string target<>;
  string linkname<>;
};

struct guestfs_ln_f_args {
  string target<>;
  string linkname<>;
};

struct guestfs_ln_s_args {
  string target<>;
  string linkname<>;
};

struct guestfs_ln_sf_args {
  string target<>;
  string linkname<>;
};

struct guestfs_readlink_args {
  string path<>;
};

struct guestfs_readlink_ret {
  string link<>;
};

struct guestfs_fallocate_args {
  string path<>;
  int len;
};

struct guestfs_swapon_device_args {
  string device<>;
};

struct guestfs_swapoff_device_args {
  string device<>;
};

struct guestfs_swapon_file_args {
  string file<>;
};

struct guestfs_swapoff_file_args {
  string file<>;
};

struct guestfs_swapon_label_args {
  string label<>;
};

struct guestfs_swapoff_label_args {
  string label<>;
};

struct guestfs_swapon_uuid_args {
  string uuid<>;
};

struct guestfs_swapoff_uuid_args {
  string uuid<>;
};

struct guestfs_mkswap_file_args {
  string path<>;
};

struct guestfs_inotify_init_args {
  int maxevents;
};

struct guestfs_inotify_add_watch_args {
  string path<>;
  int mask;
};

struct guestfs_inotify_add_watch_ret {
  int64_t wd;
};

struct guestfs_inotify_rm_watch_args {
  int wd;
};

struct guestfs_inotify_read_ret {
  guestfs_int_inotify_event_list events;
};

struct guestfs_inotify_files_ret {
  guestfs_str paths<>;
};

struct guestfs_setcon_args {
  string context<>;
};

struct guestfs_getcon_ret {
  string context<>;
};

struct guestfs_mkfs_b_args {
  string fstype<>;
  int blocksize;
  string device<>;
};

struct guestfs_mke2journal_args {
  int blocksize;
  string device<>;
};

struct guestfs_mke2journal_L_args {
  int blocksize;
  string label<>;
  string device<>;
};

struct guestfs_mke2journal_U_args {
  int blocksize;
  string uuid<>;
  string device<>;
};

struct guestfs_mke2fs_J_args {
  string fstype<>;
  int blocksize;
  string device<>;
  string journal<>;
};

struct guestfs_mke2fs_JL_args {
  string fstype<>;
  int blocksize;
  string device<>;
  string label<>;
};

struct guestfs_mke2fs_JU_args {
  string fstype<>;
  int blocksize;
  string device<>;
  string uuid<>;
};

struct guestfs_modprobe_args {
  string modulename<>;
};

struct guestfs_echo_daemon_args {
  guestfs_str words<>;
};

struct guestfs_echo_daemon_ret {
  string output<>;
};

struct guestfs_find0_args {
  string directory<>;
};

struct guestfs_case_sensitive_path_args {
  string path<>;
};

struct guestfs_case_sensitive_path_ret {
  string rpath<>;
};

struct guestfs_vfs_type_args {
  string mountable<>;
};

struct guestfs_vfs_type_ret {
  string fstype<>;
};

struct guestfs_truncate_args {
  string path<>;
};

struct guestfs_truncate_size_args {
  string path<>;
  int64_t size;
};

struct guestfs_utimens_args {
  string path<>;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;
};

struct guestfs_mkdir_mode_args {
  string path<>;
  int mode;
};

struct guestfs_lchown_args {
  int owner;
  int group;
  string path<>;
};

struct guestfs_internal_lxattrlist_args {
  string path<>;
  guestfs_str names<>;
};

struct guestfs_internal_lxattrlist_ret {
  guestfs_int_xattr_list xattrs;
};

struct guestfs_internal_readlinklist_args {
  string path<>;
  guestfs_str names<>;
};

struct guestfs_internal_readlinklist_ret {
  guestfs_str links<>;
};

struct guestfs_pread_args {
  string path<>;
  int count;
  int64_t offset;
};

struct guestfs_pread_ret {
  opaque content<>;
};

struct guestfs_part_init_args {
  string device<>;
  string parttype<>;
};

struct guestfs_part_add_args {
  string device<>;
  string prlogex<>;
  int64_t startsect;
  int64_t endsect;
};

struct guestfs_part_disk_args {
  string device<>;
  string parttype<>;
};

struct guestfs_part_set_bootable_args {
  string device<>;
  int partnum;
  bool bootable;
};

struct guestfs_part_set_name_args {
  string device<>;
  int partnum;
  string name<>;
};

struct guestfs_part_list_args {
  string device<>;
};

struct guestfs_part_list_ret {
  guestfs_int_partition_list partitions;
};

struct guestfs_part_get_parttype_args {
  string device<>;
};

struct guestfs_part_get_parttype_ret {
  string parttype<>;
};

struct guestfs_fill_args {
  int c;
  int len;
  string path<>;
};

struct guestfs_available_args {
  guestfs_str groups<>;
};

struct guestfs_dd_args {
  string src<>;
  string dest<>;
};

struct guestfs_filesize_args {
  string file<>;
};

struct guestfs_filesize_ret {
  int64_t size;
};

struct guestfs_lvrename_args {
  string logvol<>;
  string newlogvol<>;
};

struct guestfs_vgrename_args {
  string volgroup<>;
  string newvolgroup<>;
};

struct guestfs_initrd_cat_args {
  string initrdpath<>;
  string filename<>;
};

struct guestfs_initrd_cat_ret {
  opaque content<>;
};

struct guestfs_pvuuid_args {
  string device<>;
};

struct guestfs_pvuuid_ret {
  string uuid<>;
};

struct guestfs_vguuid_args {
  string vgname<>;
};

struct guestfs_vguuid_ret {
  string uuid<>;
};

struct guestfs_lvuuid_args {
  string device<>;
};

struct guestfs_lvuuid_ret {
  string uuid<>;
};

struct guestfs_vgpvuuids_args {
  string vgname<>;
};

struct guestfs_vgpvuuids_ret {
  guestfs_str uuids<>;
};

struct guestfs_vglvuuids_args {
  string vgname<>;
};

struct guestfs_vglvuuids_ret {
  guestfs_str uuids<>;
};

struct guestfs_copy_size_args {
  string src<>;
  string dest<>;
  int64_t size;
};

struct guestfs_zero_device_args {
  string device<>;
};

struct guestfs_txz_in_args {
  string directory<>;
};

struct guestfs_txz_out_args {
  string directory<>;
};

struct guestfs_part_del_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_bootable_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_bootable_ret {
  bool bootable;
};

struct guestfs_part_get_mbr_id_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_mbr_id_ret {
  int idbyte;
};

struct guestfs_part_set_mbr_id_args {
  string device<>;
  int partnum;
  int idbyte;
};

struct guestfs_checksum_device_args {
  string csumtype<>;
  string device<>;
};

struct guestfs_checksum_device_ret {
  string checksum<>;
};

struct guestfs_lvresize_free_args {
  string lv<>;
  int percent;
};

struct guestfs_aug_clear_args {
  string augpath<>;
};

struct guestfs_get_umask_ret {
  int mask;
};

struct guestfs_debug_upload_args {
  string tmpname<>;
  int mode;
};

struct guestfs_base64_in_args {
  string filename<>;
};

struct guestfs_base64_out_args {
  string filename<>;
};

struct guestfs_checksums_out_args {
  string csumtype<>;
  string directory<>;
};

struct guestfs_fill_pattern_args {
  string pattern<>;
  int len;
  string path<>;
};

struct guestfs_internal_write_args {
  string path<>;
  opaque content<>;
};

struct guestfs_pwrite_args {
  string path<>;
  opaque content<>;
  int64_t offset;
};

struct guestfs_pwrite_ret {
  int nbytes;
};

struct guestfs_resize2fs_size_args {
  string device<>;
  int64_t size;
};

struct guestfs_pvresize_size_args {
  string device<>;
  int64_t size;
};

struct guestfs_ntfsresize_size_args {
  string device<>;
  int64_t size;
};

struct guestfs_available_all_groups_ret {
  guestfs_str groups<>;
};

struct guestfs_fallocate64_args {
  string path<>;
  int64_t len;
};

struct guestfs_vfs_label_args {
  string mountable<>;
};

struct guestfs_vfs_label_ret {
  string label<>;
};

struct guestfs_vfs_uuid_args {
  string mountable<>;
};

struct guestfs_vfs_uuid_ret {
  string uuid<>;
};

struct guestfs_lvm_set_filter_args {
  guestfs_str devices<>;
};

struct guestfs_luks_open_args {
  string device<>;
  string key<>;
  string mapname<>;
};

struct guestfs_luks_open_ro_args {
  string device<>;
  string key<>;
  string mapname<>;
};

struct guestfs_luks_close_args {
  string device<>;
};

struct guestfs_luks_format_args {
  string device<>;
  string key<>;
  int keyslot;
};

struct guestfs_luks_format_cipher_args {
  string device<>;
  string key<>;
  int keyslot;
  string cipher<>;
};

struct guestfs_luks_add_key_args {
  string device<>;
  string key<>;
  string newkey<>;
  int keyslot;
};

struct guestfs_luks_kill_slot_args {
  string device<>;
  string key<>;
  int keyslot;
};

struct guestfs_is_lv_args {
  string device<>;
};

struct guestfs_is_lv_ret {
  bool lvflag;
};

struct guestfs_findfs_uuid_args {
  string uuid<>;
};

struct guestfs_findfs_uuid_ret {
  string device<>;
};

struct guestfs_findfs_label_args {
  string label<>;
};

struct guestfs_findfs_label_ret {
  string device<>;
};

struct guestfs_is_chardev_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_chardev_ret {
  bool flag;
};

struct guestfs_is_blockdev_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_blockdev_ret {
  bool flag;
};

struct guestfs_is_fifo_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_fifo_ret {
  bool flag;
};

struct guestfs_is_symlink_args {
  string path<>;
};

struct guestfs_is_symlink_ret {
  bool flag;
};

struct guestfs_is_socket_args {
  string path<>;
  bool followsymlinks;
};

struct guestfs_is_socket_ret {
  bool flag;
};

struct guestfs_part_to_dev_args {
  string partition<>;
};

struct guestfs_part_to_dev_ret {
  string device<>;
};

struct guestfs_upload_offset_args {
  string remotefilename<>;
  int64_t offset;
};

struct guestfs_download_offset_args {
  string remotefilename<>;
  int64_t offset;
  int64_t size;
};

struct guestfs_pwrite_device_args {
  string device<>;
  opaque content<>;
  int64_t offset;
};

struct guestfs_pwrite_device_ret {
  int nbytes;
};

struct guestfs_pread_device_args {
  string device<>;
  int count;
  int64_t offset;
};

struct guestfs_pread_device_ret {
  opaque content<>;
};

struct guestfs_lvm_canonical_lv_name_args {
  string lvname<>;
};

struct guestfs_lvm_canonical_lv_name_ret {
  string lv<>;
};

struct guestfs_mkfs_args {
  string fstype<>;
  string device<>;
  int blocksize;
  string features<>;
  int inode;
  int sectorsize;
  string label<>;
};

struct guestfs_getxattr_args {
  string path<>;
  string name<>;
};

struct guestfs_getxattr_ret {
  opaque xattr<>;
};

struct guestfs_lgetxattr_args {
  string path<>;
  string name<>;
};

struct guestfs_lgetxattr_ret {
  opaque xattr<>;
};

struct guestfs_resize2fs_M_args {
  string device<>;
};

struct guestfs_is_zero_args {
  string path<>;
};

struct guestfs_is_zero_ret {
  bool zeroflag;
};

struct guestfs_is_zero_device_args {
  string device<>;
};

struct guestfs_is_zero_device_ret {
  bool zeroflag;
};

struct guestfs_list_9p_ret {
  guestfs_str mounttags<>;
};

struct guestfs_mount_9p_args {
  string mounttag<>;
  string mountpoint<>;
  string options<>;
};

struct guestfs_list_dm_devices_ret {
  guestfs_str devices<>;
};

struct guestfs_ntfsresize_args {
  string device<>;
  int64_t size;
  bool force;
};

struct guestfs_btrfs_filesystem_resize_args {
  string mountpoint<>;
  int64_t size;
};

struct guestfs_internal_write_append_args {
  string path<>;
  opaque content<>;
};

struct guestfs_compress_out_args {
  string ctype<>;
  string file<>;
  int level;
};

struct guestfs_compress_device_out_args {
  string ctype<>;
  string device<>;
  int level;
};

struct guestfs_part_to_partnum_args {
  string partition<>;
};

struct guestfs_part_to_partnum_ret {
  int partnum;
};

struct guestfs_copy_device_to_device_args {
  string src<>;
  string dest<>;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  bool sparse;
  bool append;
};

struct guestfs_copy_device_to_file_args {
  string src<>;
  string dest<>;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  bool sparse;
  bool append;
};

struct guestfs_copy_file_to_device_args {
  string src<>;
  string dest<>;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  bool sparse;
  bool append;
};

struct guestfs_copy_file_to_file_args {
  string src<>;
  string dest<>;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  bool sparse;
  bool append;
};

struct guestfs_tune2fs_args {
  string device<>;
  bool force;
  int maxmountcount;
  int mountcount;
  string errorbehavior<>;
  int64_t group;
  int intervalbetweenchecks;
  int reservedblockspercentage;
  string lastmounteddirectory<>;
  int64_t reservedblockscount;
  int64_t user;
};

struct guestfs_md_create_args {
  string name<>;
  guestfs_str devices<>;
  int64_t missingbitmap;
  int nrdevices;
  int spare;
  int64_t chunk;
  string level<>;
};

struct guestfs_list_md_devices_ret {
  guestfs_str devices<>;
};

struct guestfs_md_detail_args {
  string md<>;
};

struct guestfs_md_detail_ret {
  guestfs_str info<>;
};

struct guestfs_md_stop_args {
  string md<>;
};

struct guestfs_blkid_args {
  string device<>;
};

struct guestfs_blkid_ret {
  guestfs_str info<>;
};

struct guestfs_e2fsck_args {
  string device<>;
  bool correct;
  bool forceall;
};

struct guestfs_llz_args {
  string directory<>;
};

struct guestfs_llz_ret {
  string listing<>;
};

struct guestfs_wipefs_args {
  string device<>;
};

struct guestfs_ntfsfix_args {
  string device<>;
  bool clearbadsectors;
};

struct guestfs_ntfsclone_out_args {
  string device<>;
  bool metadataonly;
  bool rescue;
  bool ignorefscheck;
  bool preservetimestamps;
  bool force;
};

struct guestfs_ntfsclone_in_args {
  string device<>;
};

struct guestfs_set_label_args {
  string mountable<>;
  string label<>;
};

struct guestfs_zero_free_space_args {
  string directory<>;
};

struct guestfs_lvcreate_free_args {
  string logvol<>;
  string volgroup<>;
  int percent;
};

struct guestfs_isoinfo_device_args {
  string device<>;
};

struct guestfs_isoinfo_device_ret {
  guestfs_int_isoinfo isodata;
};

struct guestfs_isoinfo_args {
  string isofile<>;
};

struct guestfs_isoinfo_ret {
  guestfs_int_isoinfo isodata;
};

struct guestfs_vgmeta_args {
  string vgname<>;
};

struct guestfs_vgmeta_ret {
  opaque metadata<>;
};

struct guestfs_md_stat_args {
  string md<>;
};

struct guestfs_md_stat_ret {
  guestfs_int_mdstat_list devices;
};

struct guestfs_mkfs_btrfs_args {
  guestfs_str devices<>;
  int64_t allocstart;
  int64_t bytecount;
  string datatype<>;
  int leafsize;
  string label<>;
  string metadata<>;
  int nodesize;
  int sectorsize;
};

struct guestfs_get_e2attrs_args {
  string file<>;
};

struct guestfs_get_e2attrs_ret {
  string attrs<>;
};

struct guestfs_set_e2attrs_args {
  string file<>;
  string attrs<>;
  bool clear;
};

struct guestfs_get_e2generation_args {
  string file<>;
};

struct guestfs_get_e2generation_ret {
  int64_t generation;
};

struct guestfs_set_e2generation_args {
  string file<>;
  int64_t generation;
};

struct guestfs_btrfs_subvolume_snapshot_args {
  string source<>;
  string dest<>;
  bool ro;
  string qgroupid<>;
};

struct guestfs_btrfs_subvolume_delete_args {
  string subvolume<>;
};

struct guestfs_btrfs_subvolume_create_args {
  string dest<>;
  string qgroupid<>;
};

struct guestfs_btrfs_subvolume_list_args {
  string fs<>;
};

struct guestfs_btrfs_subvolume_list_ret {
  guestfs_int_btrfssubvolume_list subvolumes;
};

struct guestfs_btrfs_subvolume_set_default_args {
  int64_t id;
  string fs<>;
};

struct guestfs_btrfs_filesystem_sync_args {
  string fs<>;
};

struct guestfs_btrfs_filesystem_balance_args {
  string fs<>;
};

struct guestfs_btrfs_device_add_args {
  guestfs_str devices<>;
  string fs<>;
};

struct guestfs_btrfs_device_delete_args {
  guestfs_str devices<>;
  string fs<>;
};

struct guestfs_btrfs_set_seeding_args {
  string device<>;
  bool seeding;
};

struct guestfs_btrfs_fsck_args {
  string device<>;
  int64_t superblock;
  bool repair;
};

struct guestfs_filesystem_available_args {
  string filesystem<>;
};

struct guestfs_filesystem_available_ret {
  bool fsavail;
};

struct guestfs_fstrim_args {
  string mountpoint<>;
  int64_t offset;
  int64_t length;
  int64_t minimumfreeextent;
};

struct guestfs_device_index_args {
  string device<>;
};

struct guestfs_device_index_ret {
  int index;
};

struct guestfs_nr_devices_ret {
  int nrdisks;
};

struct guestfs_xfs_info_args {
  string pathordevice<>;
};

struct guestfs_xfs_info_ret {
  guestfs_int_xfsinfo info;
};

struct guestfs_pvchange_uuid_args {
  string device<>;
};

struct guestfs_vgchange_uuid_args {
  string vg<>;
};

struct guestfs_utsname_ret {
  guestfs_int_utsname uts;
};

struct guestfs_xfs_growfs_args {
  string path<>;
  bool datasec;
  bool logsec;
  bool rtsec;
  int64_t datasize;
  int64_t logsize;
  int64_t rtsize;
  int64_t rtextsize;
  int maxpct;
};

struct guestfs_rsync_args {
  string src<>;
  string dest<>;
  bool archive;
  bool deletedest;
};

struct guestfs_rsync_in_args {
  string remote<>;
  string dest<>;
  bool archive;
  bool deletedest;
};

struct guestfs_rsync_out_args {
  string src<>;
  string remote<>;
  bool archive;
  bool deletedest;
};

struct guestfs_ls0_args {
  string dir<>;
};

struct guestfs_fill_dir_args {
  string dir<>;
  int nr;
};

struct guestfs_xfs_admin_args {
  string device<>;
  bool extunwritten;
  bool imgfile;
  bool v2log;
  bool projid32bit;
  bool lazycounter;
  string label<>;
  string uuid<>;
};

struct guestfs_hivex_open_args {
  string filename<>;
  bool verbose;
  bool debug;
  bool write;
};

struct guestfs_hivex_root_ret {
  int64_t nodeh;
};

struct guestfs_hivex_node_name_args {
  int64_t nodeh;
};

struct guestfs_hivex_node_name_ret {
  string name<>;
};

struct guestfs_hivex_node_children_args {
  int64_t nodeh;
};

struct guestfs_hivex_node_children_ret {
  guestfs_int_hivex_node_list nodehs;
};

struct guestfs_hivex_node_get_child_args {
  int64_t nodeh;
  string name<>;
};

struct guestfs_hivex_node_get_child_ret {
  int64_t child;
};

struct guestfs_hivex_node_parent_args {
  int64_t nodeh;
};

struct guestfs_hivex_node_parent_ret {
  int64_t parent;
};

struct guestfs_hivex_node_values_args {
  int64_t nodeh;
};

struct guestfs_hivex_node_values_ret {
  guestfs_int_hivex_value_list valuehs;
};

struct guestfs_hivex_node_get_value_args {
  int64_t nodeh;
  string key<>;
};

struct guestfs_hivex_node_get_value_ret {
  int64_t valueh;
};

struct guestfs_hivex_value_key_args {
  int64_t valueh;
};

struct guestfs_hivex_value_key_ret {
  string key<>;
};

struct guestfs_hivex_value_type_args {
  int64_t valueh;
};

struct guestfs_hivex_value_type_ret {
  int64_t datatype;
};

struct guestfs_hivex_value_value_args {
  int64_t valueh;
};

struct guestfs_hivex_value_value_ret {
  opaque databuf<>;
};

struct guestfs_hivex_commit_args {
  guestfs_str *filename;
};

struct guestfs_hivex_node_add_child_args {
  int64_t parent;
  string name<>;
};

struct guestfs_hivex_node_add_child_ret {
  int64_t nodeh;
};

struct guestfs_hivex_node_delete_child_args {
  int64_t nodeh;
};

struct guestfs_hivex_node_set_value_args {
  int64_t nodeh;
  string key<>;
  int64_t t;
  opaque val<>;
};

struct guestfs_xfs_repair_args {
  string device<>;
  bool forcelogzero;
  bool nomodify;
  bool noprefetch;
  bool forcegeometry;
  int64_t maxmem;
  int64_t ihashsize;
  int64_t bhashsize;
  int64_t agstride;
  string logdev<>;
  string rtdev<>;
};

struct guestfs_xfs_repair_ret {
  int status;
};

struct guestfs_rm_f_args {
  string path<>;
};

struct guestfs_mke2fs_args {
  string device<>;
  int64_t blockscount;
  int64_t blocksize;
  int64_t fragsize;
  int64_t blockspergroup;
  int64_t numberofgroups;
  int64_t bytesperinode;
  int64_t inodesize;
  int64_t journalsize;
  int64_t numberofinodes;
  int64_t stridesize;
  int64_t stripewidth;
  int64_t maxonlineresize;
  int reservedblockspercentage;
  int mmpupdateinterval;
  string journaldevice<>;
  string label<>;
  string lastmounteddir<>;
  string creatoros<>;
  string fstype<>;
  string usagetype<>;
  string uuid<>;
  bool forcecreate;
  bool writesbandgrouponly;
  bool lazyitableinit;
  bool lazyjournalinit;
  bool testfs;
  bool discard;
  bool quotatype;
  bool extent;
  bool filetype;
  bool flexbg;
  bool hasjournal;
  bool journaldev;
  bool largefile;
  bool quota;
  bool resizeinode;
  bool sparsesuper;
  bool uninitbg;
};

struct guestfs_list_disk_labels_ret {
  guestfs_str labels<>;
};

struct guestfs_internal_hot_add_drive_args {
  string label<>;
};

struct guestfs_internal_hot_remove_drive_precheck_args {
  string label<>;
};

struct guestfs_internal_hot_remove_drive_args {
  string label<>;
};

struct guestfs_mktemp_args {
  string tmpl<>;
  string suffix<>;
};

struct guestfs_mktemp_ret {
  string path<>;
};

struct guestfs_mklost_and_found_args {
  string mountpoint<>;
};

struct guestfs_acl_get_file_args {
  string path<>;
  string acltype<>;
};

struct guestfs_acl_get_file_ret {
  string acl<>;
};

struct guestfs_acl_set_file_args {
  string path<>;
  string acltype<>;
  string acl<>;
};

struct guestfs_acl_delete_def_file_args {
  string dir<>;
};

struct guestfs_cap_get_file_args {
  string path<>;
};

struct guestfs_cap_get_file_ret {
  string cap<>;
};

struct guestfs_cap_set_file_args {
  string path<>;
  string cap<>;
};

struct guestfs_list_ldm_volumes_ret {
  guestfs_str devices<>;
};

struct guestfs_list_ldm_partitions_ret {
  guestfs_str devices<>;
};

struct guestfs_ldmtool_scan_ret {
  guestfs_str guids<>;
};

struct guestfs_ldmtool_scan_devices_args {
  guestfs_str devices<>;
};

struct guestfs_ldmtool_scan_devices_ret {
  guestfs_str guids<>;
};

struct guestfs_ldmtool_diskgroup_name_args {
  string diskgroup<>;
};

struct guestfs_ldmtool_diskgroup_name_ret {
  string name<>;
};

struct guestfs_ldmtool_diskgroup_volumes_args {
  string diskgroup<>;
};

struct guestfs_ldmtool_diskgroup_volumes_ret {
  guestfs_str volumes<>;
};

struct guestfs_ldmtool_diskgroup_disks_args {
  string diskgroup<>;
};

struct guestfs_ldmtool_diskgroup_disks_ret {
  guestfs_str disks<>;
};

struct guestfs_ldmtool_volume_type_args {
  string diskgroup<>;
  string volume<>;
};

struct guestfs_ldmtool_volume_type_ret {
  string voltype<>;
};

struct guestfs_ldmtool_volume_hint_args {
  string diskgroup<>;
  string volume<>;
};

struct guestfs_ldmtool_volume_hint_ret {
  string hint<>;
};

struct guestfs_ldmtool_volume_partitions_args {
  string diskgroup<>;
  string volume<>;
};

struct guestfs_ldmtool_volume_partitions_ret {
  guestfs_str partitions<>;
};

struct guestfs_part_set_gpt_type_args {
  string device<>;
  int partnum;
  string guid<>;
};

struct guestfs_part_get_gpt_type_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_gpt_type_ret {
  string guid<>;
};

struct guestfs_rename_args {
  string oldpath<>;
  string newpath<>;
};

struct guestfs_is_whole_device_args {
  string device<>;
};

struct guestfs_is_whole_device_ret {
  bool flag;
};

struct guestfs_internal_parse_mountable_args {
  string mountable<>;
};

struct guestfs_internal_parse_mountable_ret {
  guestfs_int_internal_mountable mountable;
};

struct guestfs_internal_rhbz914931_args {
  int count;
};

struct guestfs_feature_available_args {
  guestfs_str groups<>;
};

struct guestfs_feature_available_ret {
  bool isavailable;
};

struct guestfs_syslinux_args {
  string device<>;
  string directory<>;
};

struct guestfs_extlinux_args {
  string directory<>;
};

struct guestfs_cp_r_args {
  string src<>;
  string dest<>;
};

struct guestfs_remount_args {
  string mountpoint<>;
  bool rw;
};

struct guestfs_set_uuid_args {
  string device<>;
  string uuid<>;
};

struct guestfs_journal_open_args {
  string directory<>;
};

struct guestfs_journal_next_ret {
  bool more;
};

struct guestfs_journal_skip_args {
  int64_t skip;
};

struct guestfs_journal_skip_ret {
  int64_t rskip;
};

struct guestfs_journal_get_data_threshold_ret {
  int64_t threshold;
};

struct guestfs_journal_set_data_threshold_args {
  int64_t threshold;
};

struct guestfs_aug_setm_args {
  string base<>;
  guestfs_str *sub;
  string val<>;
};

struct guestfs_aug_setm_ret {
  int nodes;
};

struct guestfs_aug_label_args {
  string augpath<>;
};

struct guestfs_aug_label_ret {
  string label<>;
};

struct guestfs_internal_upload_args {
  string tmpname<>;
  int mode;
};

struct guestfs_copy_attributes_args {
  string src<>;
  string dest<>;
  bool all;
  bool mode;
  bool xattributes;
  bool ownership;
};

struct guestfs_part_get_name_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_name_ret {
  string name<>;
};

struct guestfs_blkdiscard_args {
  string device<>;
};

struct guestfs_blkdiscardzeroes_args {
  string device<>;
};

struct guestfs_blkdiscardzeroes_ret {
  bool zeroes;
};

struct guestfs_cpio_out_args {
  string directory<>;
  string format<>;
};

struct guestfs_journal_get_realtime_usec_ret {
  int64_t usec;
};

struct guestfs_statns_args {
  string path<>;
};

struct guestfs_statns_ret {
  guestfs_int_statns statbuf;
};

struct guestfs_lstatns_args {
  string path<>;
};

struct guestfs_lstatns_ret {
  guestfs_int_statns statbuf;
};

struct guestfs_internal_lstatnslist_args {
  string path<>;
  guestfs_str names<>;
};

struct guestfs_internal_lstatnslist_ret {
  guestfs_int_statns_list statbufs;
};

struct guestfs_blockdev_setra_args {
  string device<>;
  int sectors;
};

struct guestfs_btrfs_subvolume_get_default_args {
  string fs<>;
};

struct guestfs_btrfs_subvolume_get_default_ret {
  int64_t id;
};

struct guestfs_btrfs_subvolume_show_args {
  string subvolume<>;
};

struct guestfs_btrfs_subvolume_show_ret {
  guestfs_str btrfssubvolumeinfo<>;
};

struct guestfs_btrfs_quota_enable_args {
  string fs<>;
  bool enable;
};

struct guestfs_btrfs_quota_rescan_args {
  string fs<>;
};

struct guestfs_btrfs_qgroup_limit_args {
  string subvolume<>;
  int64_t size;
};

struct guestfs_btrfs_qgroup_create_args {
  string qgroupid<>;
  string subvolume<>;
};

struct guestfs_btrfs_qgroup_destroy_args {
  string qgroupid<>;
  string subvolume<>;
};

struct guestfs_btrfs_qgroup_show_args {
  string path<>;
};

struct guestfs_btrfs_qgroup_show_ret {
  guestfs_int_btrfsqgroup_list qgroups;
};

struct guestfs_btrfs_qgroup_assign_args {
  string src<>;
  string dst<>;
  string path<>;
};

struct guestfs_btrfs_qgroup_remove_args {
  string src<>;
  string dst<>;
  string path<>;
};

struct guestfs_btrfs_scrub_start_args {
  string path<>;
};

struct guestfs_btrfs_scrub_cancel_args {
  string path<>;
};

struct guestfs_btrfs_scrub_resume_args {
  string path<>;
};

struct guestfs_btrfs_balance_pause_args {
  string path<>;
};

struct guestfs_btrfs_balance_cancel_args {
  string path<>;
};

struct guestfs_btrfs_balance_resume_args {
  string path<>;
};

struct guestfs_btrfs_filesystem_defragment_args {
  string path<>;
  bool flush;
  string compress<>;
};

struct guestfs_btrfs_rescue_chunk_recover_args {
  string device<>;
};

struct guestfs_btrfs_rescue_super_recover_args {
  string device<>;
};

struct guestfs_part_set_gpt_guid_args {
  string device<>;
  int partnum;
  string guid<>;
};

struct guestfs_part_get_gpt_guid_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_gpt_guid_ret {
  string guid<>;
};

struct guestfs_btrfs_balance_status_args {
  string path<>;
};

struct guestfs_btrfs_balance_status_ret {
  guestfs_int_btrfsbalance status;
};

struct guestfs_btrfs_scrub_status_args {
  string path<>;
};

struct guestfs_btrfs_scrub_status_ret {
  guestfs_int_btrfsscrub status;
};

struct guestfs_btrfstune_seeding_args {
  string device<>;
  bool seeding;
};

struct guestfs_btrfstune_enable_extended_inode_refs_args {
  string device<>;
};

struct guestfs_btrfstune_enable_skinny_metadata_extent_refs_args {
  string device<>;
};

struct guestfs_btrfs_image_args {
  guestfs_str source<>;
  string image<>;
  int compresslevel;
};

struct guestfs_part_get_mbr_part_type_args {
  string device<>;
  int partnum;
};

struct guestfs_part_get_mbr_part_type_ret {
  string partitiontype<>;
};

struct guestfs_btrfs_replace_args {
  string srcdev<>;
  string targetdev<>;
  string mntpoint<>;
};

struct guestfs_set_uuid_random_args {
  string device<>;
};

/* Table of procedure numbers. */
enum guestfs_procedure {
  GUESTFS_PROC_MOUNT = 1,
  GUESTFS_PROC_SYNC = 2,
  GUESTFS_PROC_TOUCH = 3,
  GUESTFS_PROC_LL = 5,
  GUESTFS_PROC_LIST_DEVICES = 7,
  GUESTFS_PROC_LIST_PARTITIONS = 8,
  GUESTFS_PROC_PVS = 9,
  GUESTFS_PROC_VGS = 10,
  GUESTFS_PROC_LVS = 11,
  GUESTFS_PROC_PVS_FULL = 12,
  GUESTFS_PROC_VGS_FULL = 13,
  GUESTFS_PROC_LVS_FULL = 14,
  GUESTFS_PROC_AUG_INIT = 16,
  GUESTFS_PROC_AUG_CLOSE = 26,
  GUESTFS_PROC_AUG_DEFVAR = 17,
  GUESTFS_PROC_AUG_DEFNODE = 18,
  GUESTFS_PROC_AUG_GET = 19,
  GUESTFS_PROC_AUG_SET = 20,
  GUESTFS_PROC_AUG_INSERT = 21,
  GUESTFS_PROC_AUG_RM = 22,
  GUESTFS_PROC_AUG_MV = 23,
  GUESTFS_PROC_AUG_MATCH = 24,
  GUESTFS_PROC_AUG_SAVE = 25,
  GUESTFS_PROC_AUG_LOAD = 27,
  GUESTFS_PROC_AUG_LS = 28,
  GUESTFS_PROC_RM = 29,
  GUESTFS_PROC_RMDIR = 30,
  GUESTFS_PROC_RM_RF = 31,
  GUESTFS_PROC_MKDIR = 32,
  GUESTFS_PROC_MKDIR_P = 33,
  GUESTFS_PROC_CHMOD = 34,
  GUESTFS_PROC_CHOWN = 35,
  GUESTFS_PROC_EXISTS = 36,
  GUESTFS_PROC_IS_FILE = 37,
  GUESTFS_PROC_IS_DIR = 38,
  GUESTFS_PROC_PVCREATE = 39,
  GUESTFS_PROC_VGCREATE = 40,
  GUESTFS_PROC_LVCREATE = 41,
  GUESTFS_PROC_SFDISK = 43,
  GUESTFS_PROC_WRITE_FILE = 44,
  GUESTFS_PROC_UMOUNT = 45,
  GUESTFS_PROC_MOUNTS = 46,
  GUESTFS_PROC_UMOUNT_ALL = 47,
  GUESTFS_PROC_LVM_REMOVE_ALL = 48,
  GUESTFS_PROC_FILE = 49,
  GUESTFS_PROC_COMMAND = 50,
  GUESTFS_PROC_COMMAND_LINES = 51,
  GUESTFS_PROC_STATVFS = 54,
  GUESTFS_PROC_TUNE2FS_L = 55,
  GUESTFS_PROC_BLOCKDEV_SETRO = 56,
  GUESTFS_PROC_BLOCKDEV_SETRW = 57,
  GUESTFS_PROC_BLOCKDEV_GETRO = 58,
  GUESTFS_PROC_BLOCKDEV_GETSS = 59,
  GUESTFS_PROC_BLOCKDEV_GETBSZ = 60,
  GUESTFS_PROC_BLOCKDEV_SETBSZ = 61,
  GUESTFS_PROC_BLOCKDEV_GETSZ = 62,
  GUESTFS_PROC_BLOCKDEV_GETSIZE64 = 63,
  GUESTFS_PROC_BLOCKDEV_FLUSHBUFS = 64,
  GUESTFS_PROC_BLOCKDEV_REREADPT = 65,
  GUESTFS_PROC_UPLOAD = 66,
  GUESTFS_PROC_DOWNLOAD = 67,
  GUESTFS_PROC_CHECKSUM = 68,
  GUESTFS_PROC_TAR_IN = 69,
  GUESTFS_PROC_TAR_OUT = 70,
  GUESTFS_PROC_TGZ_IN = 71,
  GUESTFS_PROC_TGZ_OUT = 72,
  GUESTFS_PROC_MOUNT_RO = 73,
  GUESTFS_PROC_MOUNT_OPTIONS = 74,
  GUESTFS_PROC_MOUNT_VFS = 75,
  GUESTFS_PROC_DEBUG = 76,
  GUESTFS_PROC_LVREMOVE = 77,
  GUESTFS_PROC_VGREMOVE = 78,
  GUESTFS_PROC_PVREMOVE = 79,
  GUESTFS_PROC_SET_E2LABEL = 80,
  GUESTFS_PROC_GET_E2LABEL = 81,
  GUESTFS_PROC_SET_E2UUID = 82,
  GUESTFS_PROC_GET_E2UUID = 83,
  GUESTFS_PROC_FSCK = 84,
  GUESTFS_PROC_ZERO = 85,
  GUESTFS_PROC_GRUB_INSTALL = 86,
  GUESTFS_PROC_CP = 87,
  GUESTFS_PROC_CP_A = 88,
  GUESTFS_PROC_MV = 89,
  GUESTFS_PROC_DROP_CACHES = 90,
  GUESTFS_PROC_DMESG = 91,
  GUESTFS_PROC_PING_DAEMON = 92,
  GUESTFS_PROC_EQUAL = 93,
  GUESTFS_PROC_STRINGS = 94,
  GUESTFS_PROC_STRINGS_E = 95,
  GUESTFS_PROC_HEXDUMP = 96,
  GUESTFS_PROC_ZEROFREE = 97,
  GUESTFS_PROC_PVRESIZE = 98,
  GUESTFS_PROC_SFDISK_N = 99,
  GUESTFS_PROC_SFDISK_L = 100,
  GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY = 101,
  GUESTFS_PROC_SFDISK_DISK_GEOMETRY = 102,
  GUESTFS_PROC_VG_ACTIVATE_ALL = 103,
  GUESTFS_PROC_VG_ACTIVATE = 104,
  GUESTFS_PROC_LVRESIZE = 105,
  GUESTFS_PROC_RESIZE2FS = 106,
  GUESTFS_PROC_E2FSCK_F = 108,
  GUESTFS_PROC_SLEEP = 109,
  GUESTFS_PROC_NTFS_3G_PROBE = 110,
  GUESTFS_PROC_SH = 111,
  GUESTFS_PROC_SH_LINES = 112,
  GUESTFS_PROC_GLOB_EXPAND = 113,
  GUESTFS_PROC_SCRUB_DEVICE = 114,
  GUESTFS_PROC_SCRUB_FILE = 115,
  GUESTFS_PROC_SCRUB_FREESPACE = 116,
  GUESTFS_PROC_MKDTEMP = 117,
  GUESTFS_PROC_WC_L = 118,
  GUESTFS_PROC_WC_W = 119,
  GUESTFS_PROC_WC_C = 120,
  GUESTFS_PROC_HEAD = 121,
  GUESTFS_PROC_HEAD_N = 122,
  GUESTFS_PROC_TAIL = 123,
  GUESTFS_PROC_TAIL_N = 124,
  GUESTFS_PROC_DF = 125,
  GUESTFS_PROC_DF_H = 126,
  GUESTFS_PROC_DU = 127,
  GUESTFS_PROC_INITRD_LIST = 128,
  GUESTFS_PROC_MOUNT_LOOP = 129,
  GUESTFS_PROC_MKSWAP = 130,
  GUESTFS_PROC_MKSWAP_L = 131,
  GUESTFS_PROC_MKSWAP_U = 132,
  GUESTFS_PROC_MKNOD = 133,
  GUESTFS_PROC_MKFIFO = 134,
  GUESTFS_PROC_MKNOD_B = 135,
  GUESTFS_PROC_MKNOD_C = 136,
  GUESTFS_PROC_UMASK = 137,
  GUESTFS_PROC_READDIR = 138,
  GUESTFS_PROC_SFDISKM = 139,
  GUESTFS_PROC_ZFILE = 140,
  GUESTFS_PROC_GETXATTRS = 141,
  GUESTFS_PROC_LGETXATTRS = 142,
  GUESTFS_PROC_SETXATTR = 143,
  GUESTFS_PROC_LSETXATTR = 144,
  GUESTFS_PROC_REMOVEXATTR = 145,
  GUESTFS_PROC_LREMOVEXATTR = 146,
  GUESTFS_PROC_MOUNTPOINTS = 147,
  GUESTFS_PROC_MKMOUNTPOINT = 148,
  GUESTFS_PROC_RMMOUNTPOINT = 149,
  GUESTFS_PROC_GREP = 151,
  GUESTFS_PROC_EGREP = 152,
  GUESTFS_PROC_FGREP = 153,
  GUESTFS_PROC_GREPI = 154,
  GUESTFS_PROC_EGREPI = 155,
  GUESTFS_PROC_FGREPI = 156,
  GUESTFS_PROC_ZGREP = 157,
  GUESTFS_PROC_ZEGREP = 158,
  GUESTFS_PROC_ZFGREP = 159,
  GUESTFS_PROC_ZGREPI = 160,
  GUESTFS_PROC_ZEGREPI = 161,
  GUESTFS_PROC_ZFGREPI = 162,
  GUESTFS_PROC_REALPATH = 163,
  GUESTFS_PROC_LN = 164,
  GUESTFS_PROC_LN_F = 165,
  GUESTFS_PROC_LN_S = 166,
  GUESTFS_PROC_LN_SF = 167,
  GUESTFS_PROC_READLINK = 168,
  GUESTFS_PROC_FALLOCATE = 169,
  GUESTFS_PROC_SWAPON_DEVICE = 170,
  GUESTFS_PROC_SWAPOFF_DEVICE = 171,
  GUESTFS_PROC_SWAPON_FILE = 172,
  GUESTFS_PROC_SWAPOFF_FILE = 173,
  GUESTFS_PROC_SWAPON_LABEL = 174,
  GUESTFS_PROC_SWAPOFF_LABEL = 175,
  GUESTFS_PROC_SWAPON_UUID = 176,
  GUESTFS_PROC_SWAPOFF_UUID = 177,
  GUESTFS_PROC_MKSWAP_FILE = 178,
  GUESTFS_PROC_INOTIFY_INIT = 179,
  GUESTFS_PROC_INOTIFY_ADD_WATCH = 180,
  GUESTFS_PROC_INOTIFY_RM_WATCH = 181,
  GUESTFS_PROC_INOTIFY_READ = 182,
  GUESTFS_PROC_INOTIFY_FILES = 183,
  GUESTFS_PROC_INOTIFY_CLOSE = 184,
  GUESTFS_PROC_SETCON = 185,
  GUESTFS_PROC_GETCON = 186,
  GUESTFS_PROC_MKFS_B = 187,
  GUESTFS_PROC_MKE2JOURNAL = 188,
  GUESTFS_PROC_MKE2JOURNAL_L = 189,
  GUESTFS_PROC_MKE2JOURNAL_U = 190,
  GUESTFS_PROC_MKE2FS_J = 191,
  GUESTFS_PROC_MKE2FS_JL = 192,
  GUESTFS_PROC_MKE2FS_JU = 193,
  GUESTFS_PROC_MODPROBE = 194,
  GUESTFS_PROC_ECHO_DAEMON = 195,
  GUESTFS_PROC_FIND0 = 196,
  GUESTFS_PROC_CASE_SENSITIVE_PATH = 197,
  GUESTFS_PROC_VFS_TYPE = 198,
  GUESTFS_PROC_TRUNCATE = 199,
  GUESTFS_PROC_TRUNCATE_SIZE = 200,
  GUESTFS_PROC_UTIMENS = 201,
  GUESTFS_PROC_MKDIR_MODE = 202,
  GUESTFS_PROC_LCHOWN = 203,
  GUESTFS_PROC_INTERNAL_LXATTRLIST = 205,
  GUESTFS_PROC_INTERNAL_READLINKLIST = 206,
  GUESTFS_PROC_PREAD = 207,
  GUESTFS_PROC_PART_INIT = 208,
  GUESTFS_PROC_PART_ADD = 209,
  GUESTFS_PROC_PART_DISK = 210,
  GUESTFS_PROC_PART_SET_BOOTABLE = 211,
  GUESTFS_PROC_PART_SET_NAME = 212,
  GUESTFS_PROC_PART_LIST = 213,
  GUESTFS_PROC_PART_GET_PARTTYPE = 214,
  GUESTFS_PROC_FILL = 215,
  GUESTFS_PROC_AVAILABLE = 216,
  GUESTFS_PROC_DD = 217,
  GUESTFS_PROC_FILESIZE = 218,
  GUESTFS_PROC_LVRENAME = 219,
  GUESTFS_PROC_VGRENAME = 220,
  GUESTFS_PROC_INITRD_CAT = 221,
  GUESTFS_PROC_PVUUID = 222,
  GUESTFS_PROC_VGUUID = 223,
  GUESTFS_PROC_LVUUID = 224,
  GUESTFS_PROC_VGPVUUIDS = 225,
  GUESTFS_PROC_VGLVUUIDS = 226,
  GUESTFS_PROC_COPY_SIZE = 227,
  GUESTFS_PROC_ZERO_DEVICE = 228,
  GUESTFS_PROC_TXZ_IN = 229,
  GUESTFS_PROC_TXZ_OUT = 230,
  GUESTFS_PROC_VGSCAN = 232,
  GUESTFS_PROC_PART_DEL = 233,
  GUESTFS_PROC_PART_GET_BOOTABLE = 234,
  GUESTFS_PROC_PART_GET_MBR_ID = 235,
  GUESTFS_PROC_PART_SET_MBR_ID = 236,
  GUESTFS_PROC_CHECKSUM_DEVICE = 237,
  GUESTFS_PROC_LVRESIZE_FREE = 238,
  GUESTFS_PROC_AUG_CLEAR = 239,
  GUESTFS_PROC_GET_UMASK = 240,
  GUESTFS_PROC_DEBUG_UPLOAD = 241,
  GUESTFS_PROC_BASE64_IN = 242,
  GUESTFS_PROC_BASE64_OUT = 243,
  GUESTFS_PROC_CHECKSUMS_OUT = 244,
  GUESTFS_PROC_FILL_PATTERN = 245,
  GUESTFS_PROC_INTERNAL_WRITE = 246,
  GUESTFS_PROC_PWRITE = 247,
  GUESTFS_PROC_RESIZE2FS_SIZE = 248,
  GUESTFS_PROC_PVRESIZE_SIZE = 249,
  GUESTFS_PROC_NTFSRESIZE_SIZE = 250,
  GUESTFS_PROC_AVAILABLE_ALL_GROUPS = 251,
  GUESTFS_PROC_FALLOCATE64 = 252,
  GUESTFS_PROC_VFS_LABEL = 253,
  GUESTFS_PROC_VFS_UUID = 254,
  GUESTFS_PROC_LVM_SET_FILTER = 255,
  GUESTFS_PROC_LVM_CLEAR_FILTER = 256,
  GUESTFS_PROC_LUKS_OPEN = 257,
  GUESTFS_PROC_LUKS_OPEN_RO = 258,
  GUESTFS_PROC_LUKS_CLOSE = 259,
  GUESTFS_PROC_LUKS_FORMAT = 260,
  GUESTFS_PROC_LUKS_FORMAT_CIPHER = 261,
  GUESTFS_PROC_LUKS_ADD_KEY = 262,
  GUESTFS_PROC_LUKS_KILL_SLOT = 263,
  GUESTFS_PROC_IS_LV = 264,
  GUESTFS_PROC_FINDFS_UUID = 265,
  GUESTFS_PROC_FINDFS_LABEL = 266,
  GUESTFS_PROC_IS_CHARDEV = 267,
  GUESTFS_PROC_IS_BLOCKDEV = 268,
  GUESTFS_PROC_IS_FIFO = 269,
  GUESTFS_PROC_IS_SYMLINK = 270,
  GUESTFS_PROC_IS_SOCKET = 271,
  GUESTFS_PROC_PART_TO_DEV = 272,
  GUESTFS_PROC_UPLOAD_OFFSET = 273,
  GUESTFS_PROC_DOWNLOAD_OFFSET = 274,
  GUESTFS_PROC_PWRITE_DEVICE = 275,
  GUESTFS_PROC_PREAD_DEVICE = 276,
  GUESTFS_PROC_LVM_CANONICAL_LV_NAME = 277,
  GUESTFS_PROC_MKFS = 278,
  GUESTFS_PROC_GETXATTR = 279,
  GUESTFS_PROC_LGETXATTR = 280,
  GUESTFS_PROC_RESIZE2FS_M = 281,
  GUESTFS_PROC_INTERNAL_AUTOSYNC = 282,
  GUESTFS_PROC_IS_ZERO = 283,
  GUESTFS_PROC_IS_ZERO_DEVICE = 284,
  GUESTFS_PROC_LIST_9P = 285,
  GUESTFS_PROC_MOUNT_9P = 286,
  GUESTFS_PROC_LIST_DM_DEVICES = 287,
  GUESTFS_PROC_NTFSRESIZE = 288,
  GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE = 289,
  GUESTFS_PROC_INTERNAL_WRITE_APPEND = 290,
  GUESTFS_PROC_COMPRESS_OUT = 291,
  GUESTFS_PROC_COMPRESS_DEVICE_OUT = 292,
  GUESTFS_PROC_PART_TO_PARTNUM = 293,
  GUESTFS_PROC_COPY_DEVICE_TO_DEVICE = 294,
  GUESTFS_PROC_COPY_DEVICE_TO_FILE = 295,
  GUESTFS_PROC_COPY_FILE_TO_DEVICE = 296,
  GUESTFS_PROC_COPY_FILE_TO_FILE = 297,
  GUESTFS_PROC_TUNE2FS = 298,
  GUESTFS_PROC_MD_CREATE = 299,
  GUESTFS_PROC_LIST_MD_DEVICES = 300,
  GUESTFS_PROC_MD_DETAIL = 301,
  GUESTFS_PROC_MD_STOP = 302,
  GUESTFS_PROC_BLKID = 303,
  GUESTFS_PROC_E2FSCK = 304,
  GUESTFS_PROC_LLZ = 305,
  GUESTFS_PROC_WIPEFS = 306,
  GUESTFS_PROC_NTFSFIX = 307,
  GUESTFS_PROC_NTFSCLONE_OUT = 308,
  GUESTFS_PROC_NTFSCLONE_IN = 309,
  GUESTFS_PROC_SET_LABEL = 310,
  GUESTFS_PROC_ZERO_FREE_SPACE = 311,
  GUESTFS_PROC_LVCREATE_FREE = 312,
  GUESTFS_PROC_ISOINFO_DEVICE = 313,
  GUESTFS_PROC_ISOINFO = 314,
  GUESTFS_PROC_VGMETA = 315,
  GUESTFS_PROC_MD_STAT = 316,
  GUESTFS_PROC_MKFS_BTRFS = 317,
  GUESTFS_PROC_GET_E2ATTRS = 318,
  GUESTFS_PROC_SET_E2ATTRS = 319,
  GUESTFS_PROC_GET_E2GENERATION = 320,
  GUESTFS_PROC_SET_E2GENERATION = 321,
  GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT = 322,
  GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE = 323,
  GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE = 324,
  GUESTFS_PROC_BTRFS_SUBVOLUME_LIST = 325,
  GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT = 326,
  GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC = 327,
  GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE = 328,
  GUESTFS_PROC_BTRFS_DEVICE_ADD = 329,
  GUESTFS_PROC_BTRFS_DEVICE_DELETE = 330,
  GUESTFS_PROC_BTRFS_SET_SEEDING = 331,
  GUESTFS_PROC_BTRFS_FSCK = 332,
  GUESTFS_PROC_FILESYSTEM_AVAILABLE = 333,
  GUESTFS_PROC_FSTRIM = 334,
  GUESTFS_PROC_DEVICE_INDEX = 335,
  GUESTFS_PROC_NR_DEVICES = 336,
  GUESTFS_PROC_XFS_INFO = 337,
  GUESTFS_PROC_PVCHANGE_UUID = 338,
  GUESTFS_PROC_PVCHANGE_UUID_ALL = 339,
  GUESTFS_PROC_VGCHANGE_UUID = 340,
  GUESTFS_PROC_VGCHANGE_UUID_ALL = 341,
  GUESTFS_PROC_UTSNAME = 342,
  GUESTFS_PROC_XFS_GROWFS = 343,
  GUESTFS_PROC_RSYNC = 344,
  GUESTFS_PROC_RSYNC_IN = 345,
  GUESTFS_PROC_RSYNC_OUT = 346,
  GUESTFS_PROC_LS0 = 347,
  GUESTFS_PROC_FILL_DIR = 348,
  GUESTFS_PROC_XFS_ADMIN = 349,
  GUESTFS_PROC_HIVEX_OPEN = 350,
  GUESTFS_PROC_HIVEX_CLOSE = 351,
  GUESTFS_PROC_HIVEX_ROOT = 352,
  GUESTFS_PROC_HIVEX_NODE_NAME = 353,
  GUESTFS_PROC_HIVEX_NODE_CHILDREN = 354,
  GUESTFS_PROC_HIVEX_NODE_GET_CHILD = 355,
  GUESTFS_PROC_HIVEX_NODE_PARENT = 356,
  GUESTFS_PROC_HIVEX_NODE_VALUES = 357,
  GUESTFS_PROC_HIVEX_NODE_GET_VALUE = 358,
  GUESTFS_PROC_HIVEX_VALUE_KEY = 359,
  GUESTFS_PROC_HIVEX_VALUE_TYPE = 360,
  GUESTFS_PROC_HIVEX_VALUE_VALUE = 361,
  GUESTFS_PROC_HIVEX_COMMIT = 362,
  GUESTFS_PROC_HIVEX_NODE_ADD_CHILD = 363,
  GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD = 364,
  GUESTFS_PROC_HIVEX_NODE_SET_VALUE = 365,
  GUESTFS_PROC_XFS_REPAIR = 366,
  GUESTFS_PROC_RM_F = 367,
  GUESTFS_PROC_MKE2FS = 368,
  GUESTFS_PROC_LIST_DISK_LABELS = 369,
  GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE = 370,
  GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK = 371,
  GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE = 372,
  GUESTFS_PROC_MKTEMP = 373,
  GUESTFS_PROC_MKLOST_AND_FOUND = 374,
  GUESTFS_PROC_ACL_GET_FILE = 375,
  GUESTFS_PROC_ACL_SET_FILE = 376,
  GUESTFS_PROC_ACL_DELETE_DEF_FILE = 377,
  GUESTFS_PROC_CAP_GET_FILE = 378,
  GUESTFS_PROC_CAP_SET_FILE = 379,
  GUESTFS_PROC_LIST_LDM_VOLUMES = 380,
  GUESTFS_PROC_LIST_LDM_PARTITIONS = 381,
  GUESTFS_PROC_LDMTOOL_CREATE_ALL = 382,
  GUESTFS_PROC_LDMTOOL_REMOVE_ALL = 383,
  GUESTFS_PROC_LDMTOOL_SCAN = 384,
  GUESTFS_PROC_LDMTOOL_SCAN_DEVICES = 385,
  GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME = 386,
  GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES = 387,
  GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS = 388,
  GUESTFS_PROC_LDMTOOL_VOLUME_TYPE = 389,
  GUESTFS_PROC_LDMTOOL_VOLUME_HINT = 390,
  GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS = 391,
  GUESTFS_PROC_PART_SET_GPT_TYPE = 392,
  GUESTFS_PROC_PART_GET_GPT_TYPE = 393,
  GUESTFS_PROC_RENAME = 394,
  GUESTFS_PROC_IS_WHOLE_DEVICE = 395,
  GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE = 396,
  GUESTFS_PROC_INTERNAL_RHBZ914931 = 397,
  GUESTFS_PROC_FEATURE_AVAILABLE = 398,
  GUESTFS_PROC_SYSLINUX = 399,
  GUESTFS_PROC_EXTLINUX = 400,
  GUESTFS_PROC_CP_R = 401,
  GUESTFS_PROC_REMOUNT = 402,
  GUESTFS_PROC_SET_UUID = 403,
  GUESTFS_PROC_JOURNAL_OPEN = 404,
  GUESTFS_PROC_JOURNAL_CLOSE = 405,
  GUESTFS_PROC_JOURNAL_NEXT = 406,
  GUESTFS_PROC_JOURNAL_SKIP = 407,
  GUESTFS_PROC_INTERNAL_JOURNAL_GET = 408,
  GUESTFS_PROC_JOURNAL_GET_DATA_THRESHOLD = 409,
  GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD = 410,
  GUESTFS_PROC_AUG_SETM = 411,
  GUESTFS_PROC_AUG_LABEL = 412,
  GUESTFS_PROC_INTERNAL_UPLOAD = 413,
  GUESTFS_PROC_INTERNAL_EXIT = 414,
  GUESTFS_PROC_COPY_ATTRIBUTES = 415,
  GUESTFS_PROC_PART_GET_NAME = 416,
  GUESTFS_PROC_BLKDISCARD = 417,
  GUESTFS_PROC_BLKDISCARDZEROES = 418,
  GUESTFS_PROC_CPIO_OUT = 419,
  GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC = 420,
  GUESTFS_PROC_STATNS = 421,
  GUESTFS_PROC_LSTATNS = 422,
  GUESTFS_PROC_INTERNAL_LSTATNSLIST = 423,
  GUESTFS_PROC_BLOCKDEV_SETRA = 424,
  GUESTFS_PROC_BTRFS_SUBVOLUME_GET_DEFAULT = 425,
  GUESTFS_PROC_BTRFS_SUBVOLUME_SHOW = 426,
  GUESTFS_PROC_BTRFS_QUOTA_ENABLE = 427,
  GUESTFS_PROC_BTRFS_QUOTA_RESCAN = 428,
  GUESTFS_PROC_BTRFS_QGROUP_LIMIT = 429,
  GUESTFS_PROC_BTRFS_QGROUP_CREATE = 430,
  GUESTFS_PROC_BTRFS_QGROUP_DESTROY = 431,
  GUESTFS_PROC_BTRFS_QGROUP_SHOW = 432,
  GUESTFS_PROC_BTRFS_QGROUP_ASSIGN = 433,
  GUESTFS_PROC_BTRFS_QGROUP_REMOVE = 434,
  GUESTFS_PROC_BTRFS_SCRUB_START = 435,
  GUESTFS_PROC_BTRFS_SCRUB_CANCEL = 436,
  GUESTFS_PROC_BTRFS_SCRUB_RESUME = 437,
  GUESTFS_PROC_BTRFS_BALANCE_PAUSE = 438,
  GUESTFS_PROC_BTRFS_BALANCE_CANCEL = 439,
  GUESTFS_PROC_BTRFS_BALANCE_RESUME = 440,
  GUESTFS_PROC_BTRFS_FILESYSTEM_DEFRAGMENT = 443,
  GUESTFS_PROC_BTRFS_RESCUE_CHUNK_RECOVER = 444,
  GUESTFS_PROC_BTRFS_RESCUE_SUPER_RECOVER = 445,
  GUESTFS_PROC_PART_SET_GPT_GUID = 446,
  GUESTFS_PROC_PART_GET_GPT_GUID = 447,
  GUESTFS_PROC_BTRFS_BALANCE_STATUS = 448,
  GUESTFS_PROC_BTRFS_SCRUB_STATUS = 449,
  GUESTFS_PROC_BTRFSTUNE_SEEDING = 450,
  GUESTFS_PROC_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS = 451,
  GUESTFS_PROC_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS = 452,
  GUESTFS_PROC_BTRFS_IMAGE = 453,
  GUESTFS_PROC_PART_GET_MBR_PART_TYPE = 454,
  GUESTFS_PROC_BTRFS_REPLACE = 455,
  GUESTFS_PROC_SET_UUID_RANDOM = 456
};

const GUESTFS_MAX_PROC_NR = 456;

/* The remote procedure call protocol. */

const GUESTFS_MESSAGE_MAX = 4194304;

const GUESTFS_PROGRAM = 0x2000F5F5;
const GUESTFS_PROTOCOL_VERSION = 4;

/* These constants must be larger than any possible message length. */
const GUESTFS_LAUNCH_FLAG = 0xf5f55ff5;
const GUESTFS_CANCEL_FLAG = 0xffffeeee;
const GUESTFS_PROGRESS_FLAG = 0xffff5555;

enum guestfs_message_direction {
  GUESTFS_DIRECTION_CALL = 0,        /* client -> daemon */
  GUESTFS_DIRECTION_REPLY = 1        /* daemon -> client */
};

enum guestfs_message_status {
  GUESTFS_STATUS_OK = 0,
  GUESTFS_STATUS_ERROR = 1
};

const GUESTFS_ERROR_LEN = 65536;

struct guestfs_message_error {
  string errno_string<32>;           /* errno eg. "EINVAL", empty string
                                        if errno not available */
  string error_message<GUESTFS_ERROR_LEN>;
};

struct guestfs_message_header {
  unsigned prog;                     /* GUESTFS_PROGRAM */
  unsigned vers;                     /* GUESTFS_PROTOCOL_VERSION */
  guestfs_procedure proc;            /* GUESTFS_PROC_x */
  guestfs_message_direction direction;
  unsigned serial;                   /* message serial number */
  uint64_t progress_hint;            /* upload hint for progress bar */
  uint64_t optargs_bitmask;          /* bitmask for optional args */
  guestfs_message_status status;
};

const GUESTFS_MAX_CHUNK_SIZE = 8192;

struct guestfs_chunk {
  int cancel;			     /* if non-zero, transfer is cancelled */
  /* data size is 0 bytes if the transfer has finished successfully */
  opaque data<GUESTFS_MAX_CHUNK_SIZE>;
};

/* Progress notifications.  Daemon self-limits these messages to
 * at most one per second.  The daemon can send these messages
 * at any time, and the caller should discard unexpected messages.
 * 'position' and 'total' have undefined units; however they may
 * have meaning for some calls.
 *
 * Notes:
 *
 * (1) guestfs_int_recv_from_daemon assumes the XDR-encoded
 * structure is 24 bytes long.
 *
 * (2) daemon/proto.c:async_safe_send_pulse assumes the progress
 * message is laid out precisely in this way.  So if you change
 * this then you'd better change that function as well.
 */
struct guestfs_progress {
  guestfs_procedure proc;            /* @0:  GUESTFS_PROC_x */
  unsigned serial;                   /* @4:  message serial number */
  uint64_t position;                 /* @8:  0 <= position <= total */
  uint64_t total;                    /* @16: total size of operation */
                                     /* @24: size of structure */
};
