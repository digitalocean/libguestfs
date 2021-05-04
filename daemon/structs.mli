(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ocaml.ml
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
 *)

type application = {
  app_name : string;
  app_display_name : string;
  app_epoch : int32;
  app_version : string;
  app_release : string;
  app_install_path : string;
  app_trans_path : string;
  app_publisher : string;
  app_url : string;
  app_source_package : string;
  app_summary : string;
  app_description : string;
}

type application2 = {
  app2_name : string;
  app2_display_name : string;
  app2_epoch : int32;
  app2_version : string;
  app2_release : string;
  app2_arch : string;
  app2_install_path : string;
  app2_trans_path : string;
  app2_publisher : string;
  app2_url : string;
  app2_source_package : string;
  app2_summary : string;
  app2_description : string;
  app2_spare1 : string;
  app2_spare2 : string;
  app2_spare3 : string;
  app2_spare4 : string;
}

type btrfsbalance = {
  btrfsbalance_status : string;
  btrfsbalance_total : int64;
  btrfsbalance_balanced : int64;
  btrfsbalance_considered : int64;
  btrfsbalance_left : int64;
}

type btrfsqgroup = {
  btrfsqgroup_id : string;
  btrfsqgroup_rfer : int64;
  btrfsqgroup_excl : int64;
}

type btrfsscrub = {
  btrfsscrub_data_extents_scrubbed : int64;
  btrfsscrub_tree_extents_scrubbed : int64;
  btrfsscrub_data_bytes_scrubbed : int64;
  btrfsscrub_tree_bytes_scrubbed : int64;
  btrfsscrub_read_errors : int64;
  btrfsscrub_csum_errors : int64;
  btrfsscrub_verify_errors : int64;
  btrfsscrub_no_csum : int64;
  btrfsscrub_csum_discards : int64;
  btrfsscrub_super_errors : int64;
  btrfsscrub_malloc_errors : int64;
  btrfsscrub_uncorrectable_errors : int64;
  btrfsscrub_unverified_errors : int64;
  btrfsscrub_corrected_errors : int64;
  btrfsscrub_last_physical : int64;
}

type btrfssubvolume = {
  btrfssubvolume_id : int64;
  btrfssubvolume_top_level_id : int64;
  btrfssubvolume_path : string;
}

type dirent = {
  ino : int64;
  ftyp : char;
  name : string;
}

type hivex_node = {
  hivex_node_h : int64;
}

type hivex_value = {
  hivex_value_h : int64;
}

type inotify_event = {
  in_wd : int64;
  in_mask : int32;
  in_cookie : int32;
  in_name : string;
}

type int_bool = {
  i : int32;
  b : int32;
}

type isoinfo = {
  iso_system_id : string;
  iso_volume_id : string;
  iso_volume_space_size : int32;
  iso_volume_set_size : int32;
  iso_volume_sequence_number : int32;
  iso_logical_block_size : int32;
  iso_volume_set_id : string;
  iso_publisher_id : string;
  iso_data_preparer_id : string;
  iso_application_id : string;
  iso_copyright_file_id : string;
  iso_abstract_file_id : string;
  iso_bibliographic_file_id : string;
  iso_volume_creation_t : int64;
  iso_volume_modification_t : int64;
  iso_volume_expiration_t : int64;
  iso_volume_effective_t : int64;
}

type lvm_lv = {
  lv_name : string;
  lv_uuid : string;
  lv_attr : string;
  lv_major : int64;
  lv_minor : int64;
  lv_kernel_major : int64;
  lv_kernel_minor : int64;
  lv_size : int64;
  seg_count : int64;
  origin : string;
  snap_percent : float option;
  copy_percent : float option;
  move_pv : string;
  lv_tags : string;
  mirror_log : string;
  modules : string;
}

type lvm_pv = {
  pv_name : string;
  pv_uuid : string;
  pv_fmt : string;
  pv_size : int64;
  dev_size : int64;
  pv_free : int64;
  pv_used : int64;
  pv_attr : string;
  pv_pe_count : int64;
  pv_pe_alloc_count : int64;
  pv_tags : string;
  pe_start : int64;
  pv_mda_count : int64;
  pv_mda_free : int64;
}

type lvm_vg = {
  vg_name : string;
  vg_uuid : string;
  vg_fmt : string;
  vg_attr : string;
  vg_size : int64;
  vg_free : int64;
  vg_sysid : string;
  vg_extent_size : int64;
  vg_extent_count : int64;
  vg_free_count : int64;
  max_lv : int64;
  max_pv : int64;
  pv_count : int64;
  lv_count : int64;
  snap_count : int64;
  vg_seqno : int64;
  vg_tags : string;
  vg_mda_count : int64;
  vg_mda_free : int64;
}

type mdstat = {
  mdstat_device : string;
  mdstat_index : int32;
  mdstat_flags : string;
}

type partition = {
  part_num : int32;
  part_start : int64;
  part_end : int64;
  part_size : int64;
}

type stat = {
  dev : int64;
  ino : int64;
  mode : int64;
  nlink : int64;
  uid : int64;
  gid : int64;
  rdev : int64;
  size : int64;
  blksize : int64;
  blocks : int64;
  atime : int64;
  mtime : int64;
  ctime : int64;
}

type statns = {
  st_dev : int64;
  st_ino : int64;
  st_mode : int64;
  st_nlink : int64;
  st_uid : int64;
  st_gid : int64;
  st_rdev : int64;
  st_size : int64;
  st_blksize : int64;
  st_blocks : int64;
  st_atime_sec : int64;
  st_atime_nsec : int64;
  st_mtime_sec : int64;
  st_mtime_nsec : int64;
  st_ctime_sec : int64;
  st_ctime_nsec : int64;
  st_spare1 : int64;
  st_spare2 : int64;
  st_spare3 : int64;
  st_spare4 : int64;
  st_spare5 : int64;
  st_spare6 : int64;
}

type statvfs = {
  bsize : int64;
  frsize : int64;
  blocks : int64;
  bfree : int64;
  bavail : int64;
  files : int64;
  ffree : int64;
  favail : int64;
  fsid : int64;
  flag : int64;
  namemax : int64;
}

type tsk_dirent = {
  tsk_inode : int64;
  tsk_type : char;
  tsk_size : int64;
  tsk_name : string;
  tsk_flags : int32;
  tsk_atime_sec : int64;
  tsk_atime_nsec : int64;
  tsk_mtime_sec : int64;
  tsk_mtime_nsec : int64;
  tsk_ctime_sec : int64;
  tsk_ctime_nsec : int64;
  tsk_crtime_sec : int64;
  tsk_crtime_nsec : int64;
  tsk_nlink : int64;
  tsk_link : string;
  tsk_spare1 : int64;
}

type utsname = {
  uts_sysname : string;
  uts_release : string;
  uts_version : string;
  uts_machine : string;
}

type version = {
  major : int64;
  minor : int64;
  release : int64;
  extra : string;
}

type xattr = {
  attrname : string;
  attrval : string;
}

type xfsinfo = {
  xfs_mntpoint : string;
  xfs_inodesize : int32;
  xfs_agcount : int32;
  xfs_agsize : int32;
  xfs_sectsize : int32;
  xfs_attr : int32;
  xfs_blocksize : int32;
  xfs_datablocks : int64;
  xfs_imaxpct : int32;
  xfs_sunit : int32;
  xfs_swidth : int32;
  xfs_dirversion : int32;
  xfs_dirblocksize : int32;
  xfs_cimode : int32;
  xfs_logname : string;
  xfs_logblocksize : int32;
  xfs_logblocks : int32;
  xfs_logversion : int32;
  xfs_logsectsize : int32;
  xfs_logsunit : int32;
  xfs_lazycount : int32;
  xfs_rtname : string;
  xfs_rtextsize : int32;
  xfs_rtblocks : int64;
  xfs_rtextents : int64;
}

type yara_detection = {
  yara_name : string;
  yara_rule : string;
}

