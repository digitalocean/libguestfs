(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
 *)

type t

exception Error of string
exception Handle_closed of string

external create : ?environment:bool -> ?close_on_exit:bool -> unit -> t =
  "ocaml_guestfs_create"
external close : t -> unit = "ocaml_guestfs_close"

type event =
  | EVENT_CLOSE
  | EVENT_SUBPROCESS_QUIT
  | EVENT_LAUNCH_DONE
  | EVENT_PROGRESS
  | EVENT_APPLIANCE
  | EVENT_LIBRARY
  | EVENT_TRACE
  | EVENT_ENTER
  | EVENT_LIBVIRT_AUTH
  | EVENT_WARNING

let event_all = [
  EVENT_CLOSE;
  EVENT_SUBPROCESS_QUIT;
  EVENT_LAUNCH_DONE;
  EVENT_PROGRESS;
  EVENT_APPLIANCE;
  EVENT_LIBRARY;
  EVENT_TRACE;
  EVENT_ENTER;
  EVENT_LIBVIRT_AUTH;
  EVENT_WARNING;
]

type event_handle = int

type event_callback =
  t -> event -> event_handle -> string -> int64 array -> unit

external set_event_callback : t -> event_callback -> event list -> event_handle
  = "ocaml_guestfs_set_event_callback"
external delete_event_callback : t -> event_handle -> unit
  = "ocaml_guestfs_delete_event_callback"
external event_to_string : event list -> string
  = "ocaml_guestfs_event_to_string"

external last_errno : t -> int = "ocaml_guestfs_last_errno"

module Errno = struct
  external enotsup : unit -> int = "ocaml_guestfs_get_ENOTSUP" "noalloc"
  let errno_ENOTSUP = enotsup ()
  external esrch : unit -> int = "ocaml_guestfs_get_ESRCH" "noalloc"
  let errno_ESRCH = esrch ()
end

(* Give the exceptions names, so they can be raised from the C code. *)
let () =
  Callback.register_exception "ocaml_guestfs_error" (Error "");
  Callback.register_exception "ocaml_guestfs_closed" (Handle_closed "")

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

external acl_delete_def_file : t -> string -> unit = "ocaml_guestfs_acl_delete_def_file"
external acl_get_file : t -> string -> string -> string = "ocaml_guestfs_acl_get_file"
external acl_set_file : t -> string -> string -> string -> unit = "ocaml_guestfs_acl_set_file"
external add_cdrom : t -> string -> unit = "ocaml_guestfs_add_cdrom"
external add_domain : t -> ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> int = "ocaml_guestfs_add_domain_byte" "ocaml_guestfs_add_domain"
external add_drive : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit = "ocaml_guestfs_add_drive_byte" "ocaml_guestfs_add_drive"
let add_drive_opts = add_drive
external add_drive_ro : t -> string -> unit = "ocaml_guestfs_add_drive_ro"
external add_drive_ro_with_if : t -> string -> string -> unit = "ocaml_guestfs_add_drive_ro_with_if"
external add_drive_scratch : t -> ?name:string -> ?label:string -> int64 -> unit = "ocaml_guestfs_add_drive_scratch"
external add_drive_with_if : t -> string -> string -> unit = "ocaml_guestfs_add_drive_with_if"
external aug_clear : t -> string -> unit = "ocaml_guestfs_aug_clear"
external aug_close : t -> unit = "ocaml_guestfs_aug_close"
external aug_defnode : t -> string -> string -> string -> int_bool = "ocaml_guestfs_aug_defnode"
external aug_defvar : t -> string -> string option -> int = "ocaml_guestfs_aug_defvar"
external aug_get : t -> string -> string = "ocaml_guestfs_aug_get"
external aug_init : t -> string -> int -> unit = "ocaml_guestfs_aug_init"
external aug_insert : t -> string -> string -> bool -> unit = "ocaml_guestfs_aug_insert"
external aug_label : t -> string -> string = "ocaml_guestfs_aug_label"
external aug_load : t -> unit = "ocaml_guestfs_aug_load"
external aug_ls : t -> string -> string array = "ocaml_guestfs_aug_ls"
external aug_match : t -> string -> string array = "ocaml_guestfs_aug_match"
external aug_mv : t -> string -> string -> unit = "ocaml_guestfs_aug_mv"
external aug_rm : t -> string -> int = "ocaml_guestfs_aug_rm"
external aug_save : t -> unit = "ocaml_guestfs_aug_save"
external aug_set : t -> string -> string -> unit = "ocaml_guestfs_aug_set"
external aug_setm : t -> string -> string option -> string -> int = "ocaml_guestfs_aug_setm"
external available : t -> string array -> unit = "ocaml_guestfs_available"
external available_all_groups : t -> string array = "ocaml_guestfs_available_all_groups"
external base64_in : t -> string -> string -> unit = "ocaml_guestfs_base64_in"
external base64_out : t -> string -> string -> unit = "ocaml_guestfs_base64_out"
external blkdiscard : t -> string -> unit = "ocaml_guestfs_blkdiscard"
external blkdiscardzeroes : t -> string -> bool = "ocaml_guestfs_blkdiscardzeroes"
external blkid : t -> string -> (string * string) list = "ocaml_guestfs_blkid"
external blockdev_flushbufs : t -> string -> unit = "ocaml_guestfs_blockdev_flushbufs"
external blockdev_getbsz : t -> string -> int = "ocaml_guestfs_blockdev_getbsz"
external blockdev_getro : t -> string -> bool = "ocaml_guestfs_blockdev_getro"
external blockdev_getsize64 : t -> string -> int64 = "ocaml_guestfs_blockdev_getsize64"
external blockdev_getss : t -> string -> int = "ocaml_guestfs_blockdev_getss"
external blockdev_getsz : t -> string -> int64 = "ocaml_guestfs_blockdev_getsz"
external blockdev_rereadpt : t -> string -> unit = "ocaml_guestfs_blockdev_rereadpt"
external blockdev_setbsz : t -> string -> int -> unit = "ocaml_guestfs_blockdev_setbsz"
external blockdev_setro : t -> string -> unit = "ocaml_guestfs_blockdev_setro"
external blockdev_setrw : t -> string -> unit = "ocaml_guestfs_blockdev_setrw"
external btrfs_device_add : t -> string array -> string -> unit = "ocaml_guestfs_btrfs_device_add"
external btrfs_device_delete : t -> string array -> string -> unit = "ocaml_guestfs_btrfs_device_delete"
external btrfs_filesystem_balance : t -> string -> unit = "ocaml_guestfs_btrfs_filesystem_balance"
external btrfs_filesystem_resize : t -> ?size:int64 -> string -> unit = "ocaml_guestfs_btrfs_filesystem_resize"
external btrfs_filesystem_sync : t -> string -> unit = "ocaml_guestfs_btrfs_filesystem_sync"
external btrfs_fsck : t -> ?superblock:int64 -> ?repair:bool -> string -> unit = "ocaml_guestfs_btrfs_fsck"
external btrfs_set_seeding : t -> string -> bool -> unit = "ocaml_guestfs_btrfs_set_seeding"
external btrfs_subvolume_create : t -> string -> unit = "ocaml_guestfs_btrfs_subvolume_create"
external btrfs_subvolume_delete : t -> string -> unit = "ocaml_guestfs_btrfs_subvolume_delete"
external btrfs_subvolume_list : t -> string -> btrfssubvolume array = "ocaml_guestfs_btrfs_subvolume_list"
external btrfs_subvolume_set_default : t -> int64 -> string -> unit = "ocaml_guestfs_btrfs_subvolume_set_default"
external btrfs_subvolume_snapshot : t -> string -> string -> unit = "ocaml_guestfs_btrfs_subvolume_snapshot"
external canonical_device_name : t -> string -> string = "ocaml_guestfs_canonical_device_name"
external cap_get_file : t -> string -> string = "ocaml_guestfs_cap_get_file"
external cap_set_file : t -> string -> string -> unit = "ocaml_guestfs_cap_set_file"
external case_sensitive_path : t -> string -> string = "ocaml_guestfs_case_sensitive_path"
external cat : t -> string -> string = "ocaml_guestfs_cat"
external checksum : t -> string -> string -> string = "ocaml_guestfs_checksum"
external checksum_device : t -> string -> string -> string = "ocaml_guestfs_checksum_device"
external checksums_out : t -> string -> string -> string -> unit = "ocaml_guestfs_checksums_out"
external chmod : t -> int -> string -> unit = "ocaml_guestfs_chmod"
external chown : t -> int -> int -> string -> unit = "ocaml_guestfs_chown"
external clear_backend_setting : t -> string -> int = "ocaml_guestfs_clear_backend_setting"
external command : t -> string array -> string = "ocaml_guestfs_command"
external command_lines : t -> string array -> string array = "ocaml_guestfs_command_lines"
external compress_device_out : t -> ?level:int -> string -> string -> string -> unit = "ocaml_guestfs_compress_device_out"
external compress_out : t -> ?level:int -> string -> string -> string -> unit = "ocaml_guestfs_compress_out"
external config : t -> string -> string option -> unit = "ocaml_guestfs_config"
external copy_attributes : t -> ?all:bool -> ?mode:bool -> ?xattributes:bool -> ?ownership:bool -> string -> string -> unit = "ocaml_guestfs_copy_attributes_byte" "ocaml_guestfs_copy_attributes"
external copy_device_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> string -> string -> unit = "ocaml_guestfs_copy_device_to_device_byte" "ocaml_guestfs_copy_device_to_device"
external copy_device_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> string -> string -> unit = "ocaml_guestfs_copy_device_to_file_byte" "ocaml_guestfs_copy_device_to_file"
external copy_file_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> string -> string -> unit = "ocaml_guestfs_copy_file_to_device_byte" "ocaml_guestfs_copy_file_to_device"
external copy_file_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> string -> string -> unit = "ocaml_guestfs_copy_file_to_file_byte" "ocaml_guestfs_copy_file_to_file"
external copy_size : t -> string -> string -> int64 -> unit = "ocaml_guestfs_copy_size"
external cp : t -> string -> string -> unit = "ocaml_guestfs_cp"
external cp_a : t -> string -> string -> unit = "ocaml_guestfs_cp_a"
external cp_r : t -> string -> string -> unit = "ocaml_guestfs_cp_r"
external cpio_out : t -> ?format:string -> string -> string -> unit = "ocaml_guestfs_cpio_out"
external dd : t -> string -> string -> unit = "ocaml_guestfs_dd"
external debug : t -> string -> string array -> string = "ocaml_guestfs_debug"
external debug_drives : t -> string array = "ocaml_guestfs_debug_drives"
external debug_upload : t -> string -> string -> int -> unit = "ocaml_guestfs_debug_upload"
external device_index : t -> string -> int = "ocaml_guestfs_device_index"
external df : t -> string = "ocaml_guestfs_df"
external df_h : t -> string = "ocaml_guestfs_df_h"
external disk_create : t -> ?backingfile:string -> ?backingformat:string -> ?preallocation:string -> ?compat:string -> ?clustersize:int -> string -> string -> int64 -> unit = "ocaml_guestfs_disk_create_byte" "ocaml_guestfs_disk_create"
external disk_format : t -> string -> string = "ocaml_guestfs_disk_format"
external disk_has_backing_file : t -> string -> bool = "ocaml_guestfs_disk_has_backing_file"
external disk_virtual_size : t -> string -> int64 = "ocaml_guestfs_disk_virtual_size"
external dmesg : t -> string = "ocaml_guestfs_dmesg"
external download : t -> string -> string -> unit = "ocaml_guestfs_download"
external download_offset : t -> string -> string -> int64 -> int64 -> unit = "ocaml_guestfs_download_offset"
external drop_caches : t -> int -> unit = "ocaml_guestfs_drop_caches"
external du : t -> string -> int64 = "ocaml_guestfs_du"
external e2fsck : t -> ?correct:bool -> ?forceall:bool -> string -> unit = "ocaml_guestfs_e2fsck"
external e2fsck_f : t -> string -> unit = "ocaml_guestfs_e2fsck_f"
external echo_daemon : t -> string array -> string = "ocaml_guestfs_echo_daemon"
external egrep : t -> string -> string -> string array = "ocaml_guestfs_egrep"
external egrepi : t -> string -> string -> string array = "ocaml_guestfs_egrepi"
external equal : t -> string -> string -> bool = "ocaml_guestfs_equal"
external exists : t -> string -> bool = "ocaml_guestfs_exists"
external extlinux : t -> string -> unit = "ocaml_guestfs_extlinux"
external fallocate : t -> string -> int -> unit = "ocaml_guestfs_fallocate"
external fallocate64 : t -> string -> int64 -> unit = "ocaml_guestfs_fallocate64"
external feature_available : t -> string array -> bool = "ocaml_guestfs_feature_available"
external fgrep : t -> string -> string -> string array = "ocaml_guestfs_fgrep"
external fgrepi : t -> string -> string -> string array = "ocaml_guestfs_fgrepi"
external file : t -> string -> string = "ocaml_guestfs_file"
external file_architecture : t -> string -> string = "ocaml_guestfs_file_architecture"
external filesize : t -> string -> int64 = "ocaml_guestfs_filesize"
external filesystem_available : t -> string -> bool = "ocaml_guestfs_filesystem_available"
external fill : t -> int -> int -> string -> unit = "ocaml_guestfs_fill"
external fill_dir : t -> string -> int -> unit = "ocaml_guestfs_fill_dir"
external fill_pattern : t -> string -> int -> string -> unit = "ocaml_guestfs_fill_pattern"
external find : t -> string -> string array = "ocaml_guestfs_find"
external find0 : t -> string -> string -> unit = "ocaml_guestfs_find0"
external findfs_label : t -> string -> string = "ocaml_guestfs_findfs_label"
external findfs_uuid : t -> string -> string = "ocaml_guestfs_findfs_uuid"
external fsck : t -> string -> string -> int = "ocaml_guestfs_fsck"
external fstrim : t -> ?offset:int64 -> ?length:int64 -> ?minimumfreeextent:int64 -> string -> unit = "ocaml_guestfs_fstrim"
external get_append : t -> string option = "ocaml_guestfs_get_append"
external get_attach_method : t -> string = "ocaml_guestfs_get_attach_method"
external get_autosync : t -> bool = "ocaml_guestfs_get_autosync"
external get_backend : t -> string = "ocaml_guestfs_get_backend"
external get_backend_setting : t -> string -> string = "ocaml_guestfs_get_backend_setting"
external get_backend_settings : t -> string array = "ocaml_guestfs_get_backend_settings"
external get_cachedir : t -> string = "ocaml_guestfs_get_cachedir"
external get_direct : t -> bool = "ocaml_guestfs_get_direct"
external get_e2attrs : t -> string -> string = "ocaml_guestfs_get_e2attrs"
external get_e2generation : t -> string -> int64 = "ocaml_guestfs_get_e2generation"
external get_e2label : t -> string -> string = "ocaml_guestfs_get_e2label"
external get_e2uuid : t -> string -> string = "ocaml_guestfs_get_e2uuid"
external get_hv : t -> string = "ocaml_guestfs_get_hv"
external get_libvirt_requested_credential_challenge : t -> int -> string = "ocaml_guestfs_get_libvirt_requested_credential_challenge"
external get_libvirt_requested_credential_defresult : t -> int -> string = "ocaml_guestfs_get_libvirt_requested_credential_defresult"
external get_libvirt_requested_credential_prompt : t -> int -> string = "ocaml_guestfs_get_libvirt_requested_credential_prompt"
external get_libvirt_requested_credentials : t -> string array = "ocaml_guestfs_get_libvirt_requested_credentials"
external get_memsize : t -> int = "ocaml_guestfs_get_memsize"
external get_network : t -> bool = "ocaml_guestfs_get_network"
external get_path : t -> string = "ocaml_guestfs_get_path"
external get_pgroup : t -> bool = "ocaml_guestfs_get_pgroup"
external get_pid : t -> int = "ocaml_guestfs_get_pid"
external get_program : t -> string = "ocaml_guestfs_get_program"
external get_qemu : t -> string = "ocaml_guestfs_get_qemu"
external get_recovery_proc : t -> bool = "ocaml_guestfs_get_recovery_proc"
external get_selinux : t -> bool = "ocaml_guestfs_get_selinux"
external get_smp : t -> int = "ocaml_guestfs_get_smp"
external get_state : t -> int = "ocaml_guestfs_get_state"
external get_tmpdir : t -> string = "ocaml_guestfs_get_tmpdir"
external get_trace : t -> bool = "ocaml_guestfs_get_trace"
external get_umask : t -> int = "ocaml_guestfs_get_umask"
external get_verbose : t -> bool = "ocaml_guestfs_get_verbose"
external getcon : t -> string = "ocaml_guestfs_getcon"
external getxattr : t -> string -> string -> string = "ocaml_guestfs_getxattr"
external getxattrs : t -> string -> xattr array = "ocaml_guestfs_getxattrs"
external glob_expand : t -> string -> string array = "ocaml_guestfs_glob_expand"
external grep : t -> ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array = "ocaml_guestfs_grep_byte" "ocaml_guestfs_grep"
let grep_opts = grep
external grepi : t -> string -> string -> string array = "ocaml_guestfs_grepi"
external grub_install : t -> string -> string -> unit = "ocaml_guestfs_grub_install"
external head : t -> string -> string array = "ocaml_guestfs_head"
external head_n : t -> int -> string -> string array = "ocaml_guestfs_head_n"
external hexdump : t -> string -> string = "ocaml_guestfs_hexdump"
external hivex_close : t -> unit = "ocaml_guestfs_hivex_close"
external hivex_commit : t -> string option -> unit = "ocaml_guestfs_hivex_commit"
external hivex_node_add_child : t -> int64 -> string -> int64 = "ocaml_guestfs_hivex_node_add_child"
external hivex_node_children : t -> int64 -> hivex_node array = "ocaml_guestfs_hivex_node_children"
external hivex_node_delete_child : t -> int64 -> unit = "ocaml_guestfs_hivex_node_delete_child"
external hivex_node_get_child : t -> int64 -> string -> int64 = "ocaml_guestfs_hivex_node_get_child"
external hivex_node_get_value : t -> int64 -> string -> int64 = "ocaml_guestfs_hivex_node_get_value"
external hivex_node_name : t -> int64 -> string = "ocaml_guestfs_hivex_node_name"
external hivex_node_parent : t -> int64 -> int64 = "ocaml_guestfs_hivex_node_parent"
external hivex_node_set_value : t -> int64 -> string -> int64 -> string -> unit = "ocaml_guestfs_hivex_node_set_value"
external hivex_node_values : t -> int64 -> hivex_value array = "ocaml_guestfs_hivex_node_values"
external hivex_open : t -> ?verbose:bool -> ?debug:bool -> ?write:bool -> string -> unit = "ocaml_guestfs_hivex_open"
external hivex_root : t -> int64 = "ocaml_guestfs_hivex_root"
external hivex_value_key : t -> int64 -> string = "ocaml_guestfs_hivex_value_key"
external hivex_value_type : t -> int64 -> int64 = "ocaml_guestfs_hivex_value_type"
external hivex_value_utf8 : t -> int64 -> string = "ocaml_guestfs_hivex_value_utf8"
external hivex_value_value : t -> int64 -> string = "ocaml_guestfs_hivex_value_value"
external initrd_cat : t -> string -> string -> string = "ocaml_guestfs_initrd_cat"
external initrd_list : t -> string -> string array = "ocaml_guestfs_initrd_list"
external inotify_add_watch : t -> string -> int -> int64 = "ocaml_guestfs_inotify_add_watch"
external inotify_close : t -> unit = "ocaml_guestfs_inotify_close"
external inotify_files : t -> string array = "ocaml_guestfs_inotify_files"
external inotify_init : t -> int -> unit = "ocaml_guestfs_inotify_init"
external inotify_read : t -> inotify_event array = "ocaml_guestfs_inotify_read"
external inotify_rm_watch : t -> int -> unit = "ocaml_guestfs_inotify_rm_watch"
external inspect_get_arch : t -> string -> string = "ocaml_guestfs_inspect_get_arch"
external inspect_get_distro : t -> string -> string = "ocaml_guestfs_inspect_get_distro"
external inspect_get_drive_mappings : t -> string -> (string * string) list = "ocaml_guestfs_inspect_get_drive_mappings"
external inspect_get_filesystems : t -> string -> string array = "ocaml_guestfs_inspect_get_filesystems"
external inspect_get_format : t -> string -> string = "ocaml_guestfs_inspect_get_format"
external inspect_get_hostname : t -> string -> string = "ocaml_guestfs_inspect_get_hostname"
external inspect_get_icon : t -> ?favicon:bool -> ?highquality:bool -> string -> string = "ocaml_guestfs_inspect_get_icon"
external inspect_get_major_version : t -> string -> int = "ocaml_guestfs_inspect_get_major_version"
external inspect_get_minor_version : t -> string -> int = "ocaml_guestfs_inspect_get_minor_version"
external inspect_get_mountpoints : t -> string -> (string * string) list = "ocaml_guestfs_inspect_get_mountpoints"
external inspect_get_package_format : t -> string -> string = "ocaml_guestfs_inspect_get_package_format"
external inspect_get_package_management : t -> string -> string = "ocaml_guestfs_inspect_get_package_management"
external inspect_get_product_name : t -> string -> string = "ocaml_guestfs_inspect_get_product_name"
external inspect_get_product_variant : t -> string -> string = "ocaml_guestfs_inspect_get_product_variant"
external inspect_get_roots : t -> string array = "ocaml_guestfs_inspect_get_roots"
external inspect_get_type : t -> string -> string = "ocaml_guestfs_inspect_get_type"
external inspect_get_windows_current_control_set : t -> string -> string = "ocaml_guestfs_inspect_get_windows_current_control_set"
external inspect_get_windows_systemroot : t -> string -> string = "ocaml_guestfs_inspect_get_windows_systemroot"
external inspect_is_live : t -> string -> bool = "ocaml_guestfs_inspect_is_live"
external inspect_is_multipart : t -> string -> bool = "ocaml_guestfs_inspect_is_multipart"
external inspect_is_netinst : t -> string -> bool = "ocaml_guestfs_inspect_is_netinst"
external inspect_list_applications : t -> string -> application array = "ocaml_guestfs_inspect_list_applications"
external inspect_list_applications2 : t -> string -> application2 array = "ocaml_guestfs_inspect_list_applications2"
external inspect_os : t -> string array = "ocaml_guestfs_inspect_os"
external internal_test : t -> ?obool:bool -> ?oint:int -> ?oint64:int64 -> ?ostring:string -> ?ostringlist:string array -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit = "ocaml_guestfs_internal_test_byte" "ocaml_guestfs_internal_test"
external internal_test_63_optargs : t -> ?opt1:int -> ?opt2:int -> ?opt3:int -> ?opt4:int -> ?opt5:int -> ?opt6:int -> ?opt7:int -> ?opt8:int -> ?opt9:int -> ?opt10:int -> ?opt11:int -> ?opt12:int -> ?opt13:int -> ?opt14:int -> ?opt15:int -> ?opt16:int -> ?opt17:int -> ?opt18:int -> ?opt19:int -> ?opt20:int -> ?opt21:int -> ?opt22:int -> ?opt23:int -> ?opt24:int -> ?opt25:int -> ?opt26:int -> ?opt27:int -> ?opt28:int -> ?opt29:int -> ?opt30:int -> ?opt31:int -> ?opt32:int -> ?opt33:int -> ?opt34:int -> ?opt35:int -> ?opt36:int -> ?opt37:int -> ?opt38:int -> ?opt39:int -> ?opt40:int -> ?opt41:int -> ?opt42:int -> ?opt43:int -> ?opt44:int -> ?opt45:int -> ?opt46:int -> ?opt47:int -> ?opt48:int -> ?opt49:int -> ?opt50:int -> ?opt51:int -> ?opt52:int -> ?opt53:int -> ?opt54:int -> ?opt55:int -> ?opt56:int -> ?opt57:int -> ?opt58:int -> ?opt59:int -> ?opt60:int -> ?opt61:int -> ?opt62:int -> ?opt63:int -> unit = "ocaml_guestfs_internal_test_63_optargs_byte" "ocaml_guestfs_internal_test_63_optargs"
external internal_test_close_output : t -> unit = "ocaml_guestfs_internal_test_close_output"
external internal_test_only_optargs : t -> ?test:int -> unit = "ocaml_guestfs_internal_test_only_optargs"
external internal_test_rbool : t -> string -> bool = "ocaml_guestfs_internal_test_rbool"
external internal_test_rboolerr : t -> bool = "ocaml_guestfs_internal_test_rboolerr"
external internal_test_rbufferout : t -> string -> string = "ocaml_guestfs_internal_test_rbufferout"
external internal_test_rbufferouterr : t -> string = "ocaml_guestfs_internal_test_rbufferouterr"
external internal_test_rconstoptstring : t -> string -> string option = "ocaml_guestfs_internal_test_rconstoptstring"
external internal_test_rconstoptstringerr : t -> string option = "ocaml_guestfs_internal_test_rconstoptstringerr"
external internal_test_rconststring : t -> string -> string = "ocaml_guestfs_internal_test_rconststring"
external internal_test_rconststringerr : t -> string = "ocaml_guestfs_internal_test_rconststringerr"
external internal_test_rhashtable : t -> string -> (string * string) list = "ocaml_guestfs_internal_test_rhashtable"
external internal_test_rhashtableerr : t -> (string * string) list = "ocaml_guestfs_internal_test_rhashtableerr"
external internal_test_rint : t -> string -> int = "ocaml_guestfs_internal_test_rint"
external internal_test_rint64 : t -> string -> int64 = "ocaml_guestfs_internal_test_rint64"
external internal_test_rint64err : t -> int64 = "ocaml_guestfs_internal_test_rint64err"
external internal_test_rinterr : t -> int = "ocaml_guestfs_internal_test_rinterr"
external internal_test_rstring : t -> string -> string = "ocaml_guestfs_internal_test_rstring"
external internal_test_rstringerr : t -> string = "ocaml_guestfs_internal_test_rstringerr"
external internal_test_rstringlist : t -> string -> string array = "ocaml_guestfs_internal_test_rstringlist"
external internal_test_rstringlisterr : t -> string array = "ocaml_guestfs_internal_test_rstringlisterr"
external internal_test_rstruct : t -> string -> lvm_pv = "ocaml_guestfs_internal_test_rstruct"
external internal_test_rstructerr : t -> lvm_pv = "ocaml_guestfs_internal_test_rstructerr"
external internal_test_rstructlist : t -> string -> lvm_pv array = "ocaml_guestfs_internal_test_rstructlist"
external internal_test_rstructlisterr : t -> lvm_pv array = "ocaml_guestfs_internal_test_rstructlisterr"
external internal_test_set_output : t -> string -> unit = "ocaml_guestfs_internal_test_set_output"
external is_blockdev : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_blockdev"
let is_blockdev_opts = is_blockdev
external is_busy : t -> bool = "ocaml_guestfs_is_busy"
external is_chardev : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_chardev"
let is_chardev_opts = is_chardev
external is_config : t -> bool = "ocaml_guestfs_is_config"
external is_dir : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_dir"
let is_dir_opts = is_dir
external is_fifo : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_fifo"
let is_fifo_opts = is_fifo
external is_file : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_file"
let is_file_opts = is_file
external is_launching : t -> bool = "ocaml_guestfs_is_launching"
external is_lv : t -> string -> bool = "ocaml_guestfs_is_lv"
external is_ready : t -> bool = "ocaml_guestfs_is_ready"
external is_socket : t -> ?followsymlinks:bool -> string -> bool = "ocaml_guestfs_is_socket"
let is_socket_opts = is_socket
external is_symlink : t -> string -> bool = "ocaml_guestfs_is_symlink"
external is_whole_device : t -> string -> bool = "ocaml_guestfs_is_whole_device"
external is_zero : t -> string -> bool = "ocaml_guestfs_is_zero"
external is_zero_device : t -> string -> bool = "ocaml_guestfs_is_zero_device"
external isoinfo : t -> string -> isoinfo = "ocaml_guestfs_isoinfo"
external isoinfo_device : t -> string -> isoinfo = "ocaml_guestfs_isoinfo_device"
external journal_close : t -> unit = "ocaml_guestfs_journal_close"
external journal_get : t -> xattr array = "ocaml_guestfs_journal_get"
external journal_get_data_threshold : t -> int64 = "ocaml_guestfs_journal_get_data_threshold"
external journal_get_realtime_usec : t -> int64 = "ocaml_guestfs_journal_get_realtime_usec"
external journal_next : t -> bool = "ocaml_guestfs_journal_next"
external journal_open : t -> string -> unit = "ocaml_guestfs_journal_open"
external journal_set_data_threshold : t -> int64 -> unit = "ocaml_guestfs_journal_set_data_threshold"
external journal_skip : t -> int64 -> int64 = "ocaml_guestfs_journal_skip"
external kill_subprocess : t -> unit = "ocaml_guestfs_kill_subprocess"
external launch : t -> unit = "ocaml_guestfs_launch"
external lchown : t -> int -> int -> string -> unit = "ocaml_guestfs_lchown"
external ldmtool_create_all : t -> unit = "ocaml_guestfs_ldmtool_create_all"
external ldmtool_diskgroup_disks : t -> string -> string array = "ocaml_guestfs_ldmtool_diskgroup_disks"
external ldmtool_diskgroup_name : t -> string -> string = "ocaml_guestfs_ldmtool_diskgroup_name"
external ldmtool_diskgroup_volumes : t -> string -> string array = "ocaml_guestfs_ldmtool_diskgroup_volumes"
external ldmtool_remove_all : t -> unit = "ocaml_guestfs_ldmtool_remove_all"
external ldmtool_scan : t -> string array = "ocaml_guestfs_ldmtool_scan"
external ldmtool_scan_devices : t -> string array -> string array = "ocaml_guestfs_ldmtool_scan_devices"
external ldmtool_volume_hint : t -> string -> string -> string = "ocaml_guestfs_ldmtool_volume_hint"
external ldmtool_volume_partitions : t -> string -> string -> string array = "ocaml_guestfs_ldmtool_volume_partitions"
external ldmtool_volume_type : t -> string -> string -> string = "ocaml_guestfs_ldmtool_volume_type"
external lgetxattr : t -> string -> string -> string = "ocaml_guestfs_lgetxattr"
external lgetxattrs : t -> string -> xattr array = "ocaml_guestfs_lgetxattrs"
external list_9p : t -> string array = "ocaml_guestfs_list_9p"
external list_devices : t -> string array = "ocaml_guestfs_list_devices"
external list_disk_labels : t -> (string * string) list = "ocaml_guestfs_list_disk_labels"
external list_dm_devices : t -> string array = "ocaml_guestfs_list_dm_devices"
external list_filesystems : t -> (string * string) list = "ocaml_guestfs_list_filesystems"
external list_ldm_partitions : t -> string array = "ocaml_guestfs_list_ldm_partitions"
external list_ldm_volumes : t -> string array = "ocaml_guestfs_list_ldm_volumes"
external list_md_devices : t -> string array = "ocaml_guestfs_list_md_devices"
external list_partitions : t -> string array = "ocaml_guestfs_list_partitions"
external ll : t -> string -> string = "ocaml_guestfs_ll"
external llz : t -> string -> string = "ocaml_guestfs_llz"
external ln : t -> string -> string -> unit = "ocaml_guestfs_ln"
external ln_f : t -> string -> string -> unit = "ocaml_guestfs_ln_f"
external ln_s : t -> string -> string -> unit = "ocaml_guestfs_ln_s"
external ln_sf : t -> string -> string -> unit = "ocaml_guestfs_ln_sf"
external lremovexattr : t -> string -> string -> unit = "ocaml_guestfs_lremovexattr"
external ls : t -> string -> string array = "ocaml_guestfs_ls"
external ls0 : t -> string -> string -> unit = "ocaml_guestfs_ls0"
external lsetxattr : t -> string -> string -> int -> string -> unit = "ocaml_guestfs_lsetxattr"
external lstat : t -> string -> stat = "ocaml_guestfs_lstat"
external lstatlist : t -> string -> string array -> stat array = "ocaml_guestfs_lstatlist"
external lstatns : t -> string -> statns = "ocaml_guestfs_lstatns"
external lstatnslist : t -> string -> string array -> statns array = "ocaml_guestfs_lstatnslist"
external luks_add_key : t -> string -> string -> string -> int -> unit = "ocaml_guestfs_luks_add_key"
external luks_close : t -> string -> unit = "ocaml_guestfs_luks_close"
external luks_format : t -> string -> string -> int -> unit = "ocaml_guestfs_luks_format"
external luks_format_cipher : t -> string -> string -> int -> string -> unit = "ocaml_guestfs_luks_format_cipher"
external luks_kill_slot : t -> string -> string -> int -> unit = "ocaml_guestfs_luks_kill_slot"
external luks_open : t -> string -> string -> string -> unit = "ocaml_guestfs_luks_open"
external luks_open_ro : t -> string -> string -> string -> unit = "ocaml_guestfs_luks_open_ro"
external lvcreate : t -> string -> string -> int -> unit = "ocaml_guestfs_lvcreate"
external lvcreate_free : t -> string -> string -> int -> unit = "ocaml_guestfs_lvcreate_free"
external lvm_canonical_lv_name : t -> string -> string = "ocaml_guestfs_lvm_canonical_lv_name"
external lvm_clear_filter : t -> unit = "ocaml_guestfs_lvm_clear_filter"
external lvm_remove_all : t -> unit = "ocaml_guestfs_lvm_remove_all"
external lvm_set_filter : t -> string array -> unit = "ocaml_guestfs_lvm_set_filter"
external lvremove : t -> string -> unit = "ocaml_guestfs_lvremove"
external lvrename : t -> string -> string -> unit = "ocaml_guestfs_lvrename"
external lvresize : t -> string -> int -> unit = "ocaml_guestfs_lvresize"
external lvresize_free : t -> string -> int -> unit = "ocaml_guestfs_lvresize_free"
external lvs : t -> string array = "ocaml_guestfs_lvs"
external lvs_full : t -> lvm_lv array = "ocaml_guestfs_lvs_full"
external lvuuid : t -> string -> string = "ocaml_guestfs_lvuuid"
external lxattrlist : t -> string -> string array -> xattr array = "ocaml_guestfs_lxattrlist"
external max_disks : t -> int = "ocaml_guestfs_max_disks"
external md_create : t -> ?missingbitmap:int64 -> ?nrdevices:int -> ?spare:int -> ?chunk:int64 -> ?level:string -> string -> string array -> unit = "ocaml_guestfs_md_create_byte" "ocaml_guestfs_md_create"
external md_detail : t -> string -> (string * string) list = "ocaml_guestfs_md_detail"
external md_stat : t -> string -> mdstat array = "ocaml_guestfs_md_stat"
external md_stop : t -> string -> unit = "ocaml_guestfs_md_stop"
external mkdir : t -> string -> unit = "ocaml_guestfs_mkdir"
external mkdir_mode : t -> string -> int -> unit = "ocaml_guestfs_mkdir_mode"
external mkdir_p : t -> string -> unit = "ocaml_guestfs_mkdir_p"
external mkdtemp : t -> string -> string = "ocaml_guestfs_mkdtemp"
external mke2fs : t -> ?blockscount:int64 -> ?blocksize:int64 -> ?fragsize:int64 -> ?blockspergroup:int64 -> ?numberofgroups:int64 -> ?bytesperinode:int64 -> ?inodesize:int64 -> ?journalsize:int64 -> ?numberofinodes:int64 -> ?stridesize:int64 -> ?stripewidth:int64 -> ?maxonlineresize:int64 -> ?reservedblockspercentage:int -> ?mmpupdateinterval:int -> ?journaldevice:string -> ?label:string -> ?lastmounteddir:string -> ?creatoros:string -> ?fstype:string -> ?usagetype:string -> ?uuid:string -> ?forcecreate:bool -> ?writesbandgrouponly:bool -> ?lazyitableinit:bool -> ?lazyjournalinit:bool -> ?testfs:bool -> ?discard:bool -> ?quotatype:bool -> ?extent:bool -> ?filetype:bool -> ?flexbg:bool -> ?hasjournal:bool -> ?journaldev:bool -> ?largefile:bool -> ?quota:bool -> ?resizeinode:bool -> ?sparsesuper:bool -> ?uninitbg:bool -> string -> unit = "ocaml_guestfs_mke2fs_byte" "ocaml_guestfs_mke2fs"
external mke2fs_J : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_J"
external mke2fs_JL : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_JL"
external mke2fs_JU : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_JU"
external mke2journal : t -> int -> string -> unit = "ocaml_guestfs_mke2journal"
external mke2journal_L : t -> int -> string -> string -> unit = "ocaml_guestfs_mke2journal_L"
external mke2journal_U : t -> int -> string -> string -> unit = "ocaml_guestfs_mke2journal_U"
external mkfifo : t -> int -> string -> unit = "ocaml_guestfs_mkfifo"
external mkfs : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> string -> string -> unit = "ocaml_guestfs_mkfs_byte" "ocaml_guestfs_mkfs"
let mkfs_opts = mkfs
external mkfs_b : t -> string -> int -> string -> unit = "ocaml_guestfs_mkfs_b"
external mkfs_btrfs : t -> ?allocstart:int64 -> ?bytecount:int64 -> ?datatype:string -> ?leafsize:int -> ?label:string -> ?metadata:string -> ?nodesize:int -> ?sectorsize:int -> string array -> unit = "ocaml_guestfs_mkfs_btrfs_byte" "ocaml_guestfs_mkfs_btrfs"
external mklost_and_found : t -> string -> unit = "ocaml_guestfs_mklost_and_found"
external mkmountpoint : t -> string -> unit = "ocaml_guestfs_mkmountpoint"
external mknod : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod"
external mknod_b : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod_b"
external mknod_c : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod_c"
external mkswap : t -> ?label:string -> ?uuid:string -> string -> unit = "ocaml_guestfs_mkswap"
let mkswap_opts = mkswap
external mkswap_L : t -> string -> string -> unit = "ocaml_guestfs_mkswap_L"
external mkswap_U : t -> string -> string -> unit = "ocaml_guestfs_mkswap_U"
external mkswap_file : t -> string -> unit = "ocaml_guestfs_mkswap_file"
external mktemp : t -> ?suffix:string -> string -> string = "ocaml_guestfs_mktemp"
external modprobe : t -> string -> unit = "ocaml_guestfs_modprobe"
external mount : t -> string -> string -> unit = "ocaml_guestfs_mount"
external mount_9p : t -> ?options:string -> string -> string -> unit = "ocaml_guestfs_mount_9p"
external mount_local : t -> ?readonly:bool -> ?options:string -> ?cachetimeout:int -> ?debugcalls:bool -> string -> unit = "ocaml_guestfs_mount_local_byte" "ocaml_guestfs_mount_local"
external mount_local_run : t -> unit = "ocaml_guestfs_mount_local_run"
external mount_loop : t -> string -> string -> unit = "ocaml_guestfs_mount_loop"
external mount_options : t -> string -> string -> string -> unit = "ocaml_guestfs_mount_options"
external mount_ro : t -> string -> string -> unit = "ocaml_guestfs_mount_ro"
external mount_vfs : t -> string -> string -> string -> string -> unit = "ocaml_guestfs_mount_vfs"
external mountpoints : t -> (string * string) list = "ocaml_guestfs_mountpoints"
external mounts : t -> string array = "ocaml_guestfs_mounts"
external mv : t -> string -> string -> unit = "ocaml_guestfs_mv"
external nr_devices : t -> int = "ocaml_guestfs_nr_devices"
external ntfs_3g_probe : t -> bool -> string -> int = "ocaml_guestfs_ntfs_3g_probe"
external ntfsclone_in : t -> string -> string -> unit = "ocaml_guestfs_ntfsclone_in"
external ntfsclone_out : t -> ?metadataonly:bool -> ?rescue:bool -> ?ignorefscheck:bool -> ?preservetimestamps:bool -> ?force:bool -> string -> string -> unit = "ocaml_guestfs_ntfsclone_out_byte" "ocaml_guestfs_ntfsclone_out"
external ntfsfix : t -> ?clearbadsectors:bool -> string -> unit = "ocaml_guestfs_ntfsfix"
external ntfsresize : t -> ?size:int64 -> ?force:bool -> string -> unit = "ocaml_guestfs_ntfsresize"
let ntfsresize_opts = ntfsresize
external ntfsresize_size : t -> string -> int64 -> unit = "ocaml_guestfs_ntfsresize_size"
external parse_environment : t -> unit = "ocaml_guestfs_parse_environment"
external parse_environment_list : t -> string array -> unit = "ocaml_guestfs_parse_environment_list"
external part_add : t -> string -> string -> int64 -> int64 -> unit = "ocaml_guestfs_part_add"
external part_del : t -> string -> int -> unit = "ocaml_guestfs_part_del"
external part_disk : t -> string -> string -> unit = "ocaml_guestfs_part_disk"
external part_get_bootable : t -> string -> int -> bool = "ocaml_guestfs_part_get_bootable"
external part_get_gpt_type : t -> string -> int -> string = "ocaml_guestfs_part_get_gpt_type"
external part_get_mbr_id : t -> string -> int -> int = "ocaml_guestfs_part_get_mbr_id"
external part_get_name : t -> string -> int -> string = "ocaml_guestfs_part_get_name"
external part_get_parttype : t -> string -> string = "ocaml_guestfs_part_get_parttype"
external part_init : t -> string -> string -> unit = "ocaml_guestfs_part_init"
external part_list : t -> string -> partition array = "ocaml_guestfs_part_list"
external part_set_bootable : t -> string -> int -> bool -> unit = "ocaml_guestfs_part_set_bootable"
external part_set_gpt_type : t -> string -> int -> string -> unit = "ocaml_guestfs_part_set_gpt_type"
external part_set_mbr_id : t -> string -> int -> int -> unit = "ocaml_guestfs_part_set_mbr_id"
external part_set_name : t -> string -> int -> string -> unit = "ocaml_guestfs_part_set_name"
external part_to_dev : t -> string -> string = "ocaml_guestfs_part_to_dev"
external part_to_partnum : t -> string -> int = "ocaml_guestfs_part_to_partnum"
external ping_daemon : t -> unit = "ocaml_guestfs_ping_daemon"
external pread : t -> string -> int -> int64 -> string = "ocaml_guestfs_pread"
external pread_device : t -> string -> int -> int64 -> string = "ocaml_guestfs_pread_device"
external pvchange_uuid : t -> string -> unit = "ocaml_guestfs_pvchange_uuid"
external pvchange_uuid_all : t -> unit = "ocaml_guestfs_pvchange_uuid_all"
external pvcreate : t -> string -> unit = "ocaml_guestfs_pvcreate"
external pvremove : t -> string -> unit = "ocaml_guestfs_pvremove"
external pvresize : t -> string -> unit = "ocaml_guestfs_pvresize"
external pvresize_size : t -> string -> int64 -> unit = "ocaml_guestfs_pvresize_size"
external pvs : t -> string array = "ocaml_guestfs_pvs"
external pvs_full : t -> lvm_pv array = "ocaml_guestfs_pvs_full"
external pvuuid : t -> string -> string = "ocaml_guestfs_pvuuid"
external pwrite : t -> string -> string -> int64 -> int = "ocaml_guestfs_pwrite"
external pwrite_device : t -> string -> string -> int64 -> int = "ocaml_guestfs_pwrite_device"
external read_file : t -> string -> string = "ocaml_guestfs_read_file"
external read_lines : t -> string -> string array = "ocaml_guestfs_read_lines"
external readdir : t -> string -> dirent array = "ocaml_guestfs_readdir"
external readlink : t -> string -> string = "ocaml_guestfs_readlink"
external readlinklist : t -> string -> string array -> string array = "ocaml_guestfs_readlinklist"
external realpath : t -> string -> string = "ocaml_guestfs_realpath"
external remount : t -> ?rw:bool -> string -> unit = "ocaml_guestfs_remount"
external remove_drive : t -> string -> unit = "ocaml_guestfs_remove_drive"
external removexattr : t -> string -> string -> unit = "ocaml_guestfs_removexattr"
external rename : t -> string -> string -> unit = "ocaml_guestfs_rename"
external resize2fs : t -> string -> unit = "ocaml_guestfs_resize2fs"
external resize2fs_M : t -> string -> unit = "ocaml_guestfs_resize2fs_M"
external resize2fs_size : t -> string -> int64 -> unit = "ocaml_guestfs_resize2fs_size"
external rm : t -> string -> unit = "ocaml_guestfs_rm"
external rm_f : t -> string -> unit = "ocaml_guestfs_rm_f"
external rm_rf : t -> string -> unit = "ocaml_guestfs_rm_rf"
external rmdir : t -> string -> unit = "ocaml_guestfs_rmdir"
external rmmountpoint : t -> string -> unit = "ocaml_guestfs_rmmountpoint"
external rsync : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit = "ocaml_guestfs_rsync"
external rsync_in : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit = "ocaml_guestfs_rsync_in"
external rsync_out : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit = "ocaml_guestfs_rsync_out"
external scrub_device : t -> string -> unit = "ocaml_guestfs_scrub_device"
external scrub_file : t -> string -> unit = "ocaml_guestfs_scrub_file"
external scrub_freespace : t -> string -> unit = "ocaml_guestfs_scrub_freespace"
external set_append : t -> string option -> unit = "ocaml_guestfs_set_append"
external set_attach_method : t -> string -> unit = "ocaml_guestfs_set_attach_method"
external set_autosync : t -> bool -> unit = "ocaml_guestfs_set_autosync"
external set_backend : t -> string -> unit = "ocaml_guestfs_set_backend"
external set_backend_setting : t -> string -> string -> unit = "ocaml_guestfs_set_backend_setting"
external set_backend_settings : t -> string array -> unit = "ocaml_guestfs_set_backend_settings"
external set_cachedir : t -> string option -> unit = "ocaml_guestfs_set_cachedir"
external set_direct : t -> bool -> unit = "ocaml_guestfs_set_direct"
external set_e2attrs : t -> ?clear:bool -> string -> string -> unit = "ocaml_guestfs_set_e2attrs"
external set_e2generation : t -> string -> int64 -> unit = "ocaml_guestfs_set_e2generation"
external set_e2label : t -> string -> string -> unit = "ocaml_guestfs_set_e2label"
external set_e2uuid : t -> string -> string -> unit = "ocaml_guestfs_set_e2uuid"
external set_hv : t -> string -> unit = "ocaml_guestfs_set_hv"
external set_label : t -> string -> string -> unit = "ocaml_guestfs_set_label"
external set_libvirt_requested_credential : t -> int -> string -> unit = "ocaml_guestfs_set_libvirt_requested_credential"
external set_libvirt_supported_credentials : t -> string array -> unit = "ocaml_guestfs_set_libvirt_supported_credentials"
external set_memsize : t -> int -> unit = "ocaml_guestfs_set_memsize"
external set_network : t -> bool -> unit = "ocaml_guestfs_set_network"
external set_path : t -> string option -> unit = "ocaml_guestfs_set_path"
external set_pgroup : t -> bool -> unit = "ocaml_guestfs_set_pgroup"
external set_program : t -> string -> unit = "ocaml_guestfs_set_program"
external set_qemu : t -> string option -> unit = "ocaml_guestfs_set_qemu"
external set_recovery_proc : t -> bool -> unit = "ocaml_guestfs_set_recovery_proc"
external set_selinux : t -> bool -> unit = "ocaml_guestfs_set_selinux"
external set_smp : t -> int -> unit = "ocaml_guestfs_set_smp"
external set_tmpdir : t -> string option -> unit = "ocaml_guestfs_set_tmpdir"
external set_trace : t -> bool -> unit = "ocaml_guestfs_set_trace"
external set_uuid : t -> string -> string -> unit = "ocaml_guestfs_set_uuid"
external set_verbose : t -> bool -> unit = "ocaml_guestfs_set_verbose"
external setcon : t -> string -> unit = "ocaml_guestfs_setcon"
external setxattr : t -> string -> string -> int -> string -> unit = "ocaml_guestfs_setxattr"
external sfdisk : t -> string -> int -> int -> int -> string array -> unit = "ocaml_guestfs_sfdisk_byte" "ocaml_guestfs_sfdisk"
external sfdiskM : t -> string -> string array -> unit = "ocaml_guestfs_sfdiskM"
external sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit = "ocaml_guestfs_sfdisk_N_byte" "ocaml_guestfs_sfdisk_N"
external sfdisk_disk_geometry : t -> string -> string = "ocaml_guestfs_sfdisk_disk_geometry"
external sfdisk_kernel_geometry : t -> string -> string = "ocaml_guestfs_sfdisk_kernel_geometry"
external sfdisk_l : t -> string -> string = "ocaml_guestfs_sfdisk_l"
external sh : t -> string -> string = "ocaml_guestfs_sh"
external sh_lines : t -> string -> string array = "ocaml_guestfs_sh_lines"
external shutdown : t -> unit = "ocaml_guestfs_shutdown"
external sleep : t -> int -> unit = "ocaml_guestfs_sleep"
external stat : t -> string -> stat = "ocaml_guestfs_stat"
external statns : t -> string -> statns = "ocaml_guestfs_statns"
external statvfs : t -> string -> statvfs = "ocaml_guestfs_statvfs"
external strings : t -> string -> string array = "ocaml_guestfs_strings"
external strings_e : t -> string -> string -> string array = "ocaml_guestfs_strings_e"
external swapoff_device : t -> string -> unit = "ocaml_guestfs_swapoff_device"
external swapoff_file : t -> string -> unit = "ocaml_guestfs_swapoff_file"
external swapoff_label : t -> string -> unit = "ocaml_guestfs_swapoff_label"
external swapoff_uuid : t -> string -> unit = "ocaml_guestfs_swapoff_uuid"
external swapon_device : t -> string -> unit = "ocaml_guestfs_swapon_device"
external swapon_file : t -> string -> unit = "ocaml_guestfs_swapon_file"
external swapon_label : t -> string -> unit = "ocaml_guestfs_swapon_label"
external swapon_uuid : t -> string -> unit = "ocaml_guestfs_swapon_uuid"
external sync : t -> unit = "ocaml_guestfs_sync"
external syslinux : t -> ?directory:string -> string -> unit = "ocaml_guestfs_syslinux"
external tail : t -> string -> string array = "ocaml_guestfs_tail"
external tail_n : t -> int -> string -> string array = "ocaml_guestfs_tail_n"
external tar_in : t -> ?compress:string -> string -> string -> unit = "ocaml_guestfs_tar_in"
let tar_in_opts = tar_in
external tar_out : t -> ?compress:string -> ?numericowner:bool -> ?excludes:string array -> string -> string -> unit = "ocaml_guestfs_tar_out_byte" "ocaml_guestfs_tar_out"
let tar_out_opts = tar_out
external tgz_in : t -> string -> string -> unit = "ocaml_guestfs_tgz_in"
external tgz_out : t -> string -> string -> unit = "ocaml_guestfs_tgz_out"
external touch : t -> string -> unit = "ocaml_guestfs_touch"
external truncate : t -> string -> unit = "ocaml_guestfs_truncate"
external truncate_size : t -> string -> int64 -> unit = "ocaml_guestfs_truncate_size"
external tune2fs : t -> ?force:bool -> ?maxmountcount:int -> ?mountcount:int -> ?errorbehavior:string -> ?group:int64 -> ?intervalbetweenchecks:int -> ?reservedblockspercentage:int -> ?lastmounteddirectory:string -> ?reservedblockscount:int64 -> ?user:int64 -> string -> unit = "ocaml_guestfs_tune2fs_byte" "ocaml_guestfs_tune2fs"
external tune2fs_l : t -> string -> (string * string) list = "ocaml_guestfs_tune2fs_l"
external txz_in : t -> string -> string -> unit = "ocaml_guestfs_txz_in"
external txz_out : t -> string -> string -> unit = "ocaml_guestfs_txz_out"
external umask : t -> int -> int = "ocaml_guestfs_umask"
external umount : t -> ?force:bool -> ?lazyunmount:bool -> string -> unit = "ocaml_guestfs_umount"
let umount_opts = umount
external umount_all : t -> unit = "ocaml_guestfs_umount_all"
external umount_local : t -> ?retry:bool -> unit = "ocaml_guestfs_umount_local"
external upload : t -> string -> string -> unit = "ocaml_guestfs_upload"
external upload_offset : t -> string -> string -> int64 -> unit = "ocaml_guestfs_upload_offset"
external user_cancel : t -> unit = "ocaml_guestfs_user_cancel"
external utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit = "ocaml_guestfs_utimens_byte" "ocaml_guestfs_utimens"
external utsname : t -> utsname = "ocaml_guestfs_utsname"
external version : t -> version = "ocaml_guestfs_version"
external vfs_label : t -> string -> string = "ocaml_guestfs_vfs_label"
external vfs_type : t -> string -> string = "ocaml_guestfs_vfs_type"
external vfs_uuid : t -> string -> string = "ocaml_guestfs_vfs_uuid"
external vg_activate : t -> bool -> string array -> unit = "ocaml_guestfs_vg_activate"
external vg_activate_all : t -> bool -> unit = "ocaml_guestfs_vg_activate_all"
external vgchange_uuid : t -> string -> unit = "ocaml_guestfs_vgchange_uuid"
external vgchange_uuid_all : t -> unit = "ocaml_guestfs_vgchange_uuid_all"
external vgcreate : t -> string -> string array -> unit = "ocaml_guestfs_vgcreate"
external vglvuuids : t -> string -> string array = "ocaml_guestfs_vglvuuids"
external vgmeta : t -> string -> string = "ocaml_guestfs_vgmeta"
external vgpvuuids : t -> string -> string array = "ocaml_guestfs_vgpvuuids"
external vgremove : t -> string -> unit = "ocaml_guestfs_vgremove"
external vgrename : t -> string -> string -> unit = "ocaml_guestfs_vgrename"
external vgs : t -> string array = "ocaml_guestfs_vgs"
external vgs_full : t -> lvm_vg array = "ocaml_guestfs_vgs_full"
external vgscan : t -> unit = "ocaml_guestfs_vgscan"
external vguuid : t -> string -> string = "ocaml_guestfs_vguuid"
external wait_ready : t -> unit = "ocaml_guestfs_wait_ready"
external wc_c : t -> string -> int = "ocaml_guestfs_wc_c"
external wc_l : t -> string -> int = "ocaml_guestfs_wc_l"
external wc_w : t -> string -> int = "ocaml_guestfs_wc_w"
external wipefs : t -> string -> unit = "ocaml_guestfs_wipefs"
external write : t -> string -> string -> unit = "ocaml_guestfs_write"
external write_append : t -> string -> string -> unit = "ocaml_guestfs_write_append"
external write_file : t -> string -> string -> int -> unit = "ocaml_guestfs_write_file"
external xfs_admin : t -> ?extunwritten:bool -> ?imgfile:bool -> ?v2log:bool -> ?projid32bit:bool -> ?lazycounter:bool -> ?label:string -> ?uuid:string -> string -> unit = "ocaml_guestfs_xfs_admin_byte" "ocaml_guestfs_xfs_admin"
external xfs_growfs : t -> ?datasec:bool -> ?logsec:bool -> ?rtsec:bool -> ?datasize:int64 -> ?logsize:int64 -> ?rtsize:int64 -> ?rtextsize:int64 -> ?maxpct:int -> string -> unit = "ocaml_guestfs_xfs_growfs_byte" "ocaml_guestfs_xfs_growfs"
external xfs_info : t -> string -> xfsinfo = "ocaml_guestfs_xfs_info"
external xfs_repair : t -> ?forcelogzero:bool -> ?nomodify:bool -> ?noprefetch:bool -> ?forcegeometry:bool -> ?maxmem:int64 -> ?ihashsize:int64 -> ?bhashsize:int64 -> ?agstride:int64 -> ?logdev:string -> ?rtdev:string -> string -> int = "ocaml_guestfs_xfs_repair_byte" "ocaml_guestfs_xfs_repair"
external zegrep : t -> string -> string -> string array = "ocaml_guestfs_zegrep"
external zegrepi : t -> string -> string -> string array = "ocaml_guestfs_zegrepi"
external zero : t -> string -> unit = "ocaml_guestfs_zero"
external zero_device : t -> string -> unit = "ocaml_guestfs_zero_device"
external zero_free_space : t -> string -> unit = "ocaml_guestfs_zero_free_space"
external zerofree : t -> string -> unit = "ocaml_guestfs_zerofree"
external zfgrep : t -> string -> string -> string array = "ocaml_guestfs_zfgrep"
external zfgrepi : t -> string -> string -> string array = "ocaml_guestfs_zfgrepi"
external zfile : t -> string -> string -> string = "ocaml_guestfs_zfile"
external zgrep : t -> string -> string -> string array = "ocaml_guestfs_zgrep"
external zgrepi : t -> string -> string -> string array = "ocaml_guestfs_zgrepi"

class guestfs ?environment ?close_on_exit () =
  let g = create ?environment ?close_on_exit () in
  object (self)
    method close () = close g
    method set_event_callback = set_event_callback g
    method delete_event_callback = delete_event_callback g
    method last_errno () = last_errno g
    method ocaml_handle = g
    method acl_delete_def_file = acl_delete_def_file g
    method acl_get_file = acl_get_file g
    method acl_set_file = acl_set_file g
    method add_cdrom = add_cdrom g
    method add_domain = add_domain g
    method add_drive = add_drive g
    method add_drive_opts = self#add_drive
    method add_drive_ro = add_drive_ro g
    method add_drive_ro_with_if = add_drive_ro_with_if g
    method add_drive_scratch = add_drive_scratch g
    method add_drive_with_if = add_drive_with_if g
    method aug_clear = aug_clear g
    method aug_close () = aug_close g
    method aug_defnode = aug_defnode g
    method aug_defvar = aug_defvar g
    method aug_get = aug_get g
    method aug_init = aug_init g
    method aug_insert = aug_insert g
    method aug_label = aug_label g
    method aug_load () = aug_load g
    method aug_ls = aug_ls g
    method aug_match = aug_match g
    method aug_mv = aug_mv g
    method aug_rm = aug_rm g
    method aug_save () = aug_save g
    method aug_set = aug_set g
    method aug_setm = aug_setm g
    method available = available g
    method available_all_groups () = available_all_groups g
    method base64_in = base64_in g
    method base64_out = base64_out g
    method blkdiscard = blkdiscard g
    method blkdiscardzeroes = blkdiscardzeroes g
    method blkid = blkid g
    method blockdev_flushbufs = blockdev_flushbufs g
    method blockdev_getbsz = blockdev_getbsz g
    method blockdev_getro = blockdev_getro g
    method blockdev_getsize64 = blockdev_getsize64 g
    method blockdev_getss = blockdev_getss g
    method blockdev_getsz = blockdev_getsz g
    method blockdev_rereadpt = blockdev_rereadpt g
    method blockdev_setbsz = blockdev_setbsz g
    method blockdev_setro = blockdev_setro g
    method blockdev_setrw = blockdev_setrw g
    method btrfs_device_add = btrfs_device_add g
    method btrfs_device_delete = btrfs_device_delete g
    method btrfs_filesystem_balance = btrfs_filesystem_balance g
    method btrfs_filesystem_resize = btrfs_filesystem_resize g
    method btrfs_filesystem_sync = btrfs_filesystem_sync g
    method btrfs_fsck = btrfs_fsck g
    method btrfs_set_seeding = btrfs_set_seeding g
    method btrfs_subvolume_create = btrfs_subvolume_create g
    method btrfs_subvolume_delete = btrfs_subvolume_delete g
    method btrfs_subvolume_list = btrfs_subvolume_list g
    method btrfs_subvolume_set_default = btrfs_subvolume_set_default g
    method btrfs_subvolume_snapshot = btrfs_subvolume_snapshot g
    method canonical_device_name = canonical_device_name g
    method cap_get_file = cap_get_file g
    method cap_set_file = cap_set_file g
    method case_sensitive_path = case_sensitive_path g
    method cat = cat g
    method checksum = checksum g
    method checksum_device = checksum_device g
    method checksums_out = checksums_out g
    method chmod = chmod g
    method chown = chown g
    method clear_backend_setting = clear_backend_setting g
    method command = command g
    method command_lines = command_lines g
    method compress_device_out = compress_device_out g
    method compress_out = compress_out g
    method config = config g
    method copy_attributes = copy_attributes g
    method copy_device_to_device = copy_device_to_device g
    method copy_device_to_file = copy_device_to_file g
    method copy_file_to_device = copy_file_to_device g
    method copy_file_to_file = copy_file_to_file g
    method copy_size = copy_size g
    method cp = cp g
    method cp_a = cp_a g
    method cp_r = cp_r g
    method cpio_out = cpio_out g
    method dd = dd g
    method debug = debug g
    method debug_drives () = debug_drives g
    method debug_upload = debug_upload g
    method device_index = device_index g
    method df () = df g
    method df_h () = df_h g
    method disk_create = disk_create g
    method disk_format = disk_format g
    method disk_has_backing_file = disk_has_backing_file g
    method disk_virtual_size = disk_virtual_size g
    method dmesg () = dmesg g
    method download = download g
    method download_offset = download_offset g
    method drop_caches = drop_caches g
    method du = du g
    method e2fsck = e2fsck g
    method e2fsck_f = e2fsck_f g
    method echo_daemon = echo_daemon g
    method egrep = egrep g
    method egrepi = egrepi g
    method equal = equal g
    method exists = exists g
    method extlinux = extlinux g
    method fallocate = fallocate g
    method fallocate64 = fallocate64 g
    method feature_available = feature_available g
    method fgrep = fgrep g
    method fgrepi = fgrepi g
    method file = file g
    method file_architecture = file_architecture g
    method filesize = filesize g
    method filesystem_available = filesystem_available g
    method fill = fill g
    method fill_dir = fill_dir g
    method fill_pattern = fill_pattern g
    method find = find g
    method find0 = find0 g
    method findfs_label = findfs_label g
    method findfs_uuid = findfs_uuid g
    method fsck = fsck g
    method fstrim = fstrim g
    method get_append () = get_append g
    method get_attach_method () = get_attach_method g
    method get_autosync () = get_autosync g
    method get_backend () = get_backend g
    method get_backend_setting = get_backend_setting g
    method get_backend_settings () = get_backend_settings g
    method get_cachedir () = get_cachedir g
    method get_direct () = get_direct g
    method get_e2attrs = get_e2attrs g
    method get_e2generation = get_e2generation g
    method get_e2label = get_e2label g
    method get_e2uuid = get_e2uuid g
    method get_hv () = get_hv g
    method get_libvirt_requested_credential_challenge = get_libvirt_requested_credential_challenge g
    method get_libvirt_requested_credential_defresult = get_libvirt_requested_credential_defresult g
    method get_libvirt_requested_credential_prompt = get_libvirt_requested_credential_prompt g
    method get_libvirt_requested_credentials () = get_libvirt_requested_credentials g
    method get_memsize () = get_memsize g
    method get_network () = get_network g
    method get_path () = get_path g
    method get_pgroup () = get_pgroup g
    method get_pid () = get_pid g
    method get_program () = get_program g
    method get_qemu () = get_qemu g
    method get_recovery_proc () = get_recovery_proc g
    method get_selinux () = get_selinux g
    method get_smp () = get_smp g
    method get_state () = get_state g
    method get_tmpdir () = get_tmpdir g
    method get_trace () = get_trace g
    method get_umask () = get_umask g
    method get_verbose () = get_verbose g
    method getcon () = getcon g
    method getxattr = getxattr g
    method getxattrs = getxattrs g
    method glob_expand = glob_expand g
    method grep = grep g
    method grep_opts = self#grep
    method grepi = grepi g
    method grub_install = grub_install g
    method head = head g
    method head_n = head_n g
    method hexdump = hexdump g
    method hivex_close () = hivex_close g
    method hivex_commit = hivex_commit g
    method hivex_node_add_child = hivex_node_add_child g
    method hivex_node_children = hivex_node_children g
    method hivex_node_delete_child = hivex_node_delete_child g
    method hivex_node_get_child = hivex_node_get_child g
    method hivex_node_get_value = hivex_node_get_value g
    method hivex_node_name = hivex_node_name g
    method hivex_node_parent = hivex_node_parent g
    method hivex_node_set_value = hivex_node_set_value g
    method hivex_node_values = hivex_node_values g
    method hivex_open = hivex_open g
    method hivex_root () = hivex_root g
    method hivex_value_key = hivex_value_key g
    method hivex_value_type = hivex_value_type g
    method hivex_value_utf8 = hivex_value_utf8 g
    method hivex_value_value = hivex_value_value g
    method initrd_cat = initrd_cat g
    method initrd_list = initrd_list g
    method inotify_add_watch = inotify_add_watch g
    method inotify_close () = inotify_close g
    method inotify_files () = inotify_files g
    method inotify_init = inotify_init g
    method inotify_read () = inotify_read g
    method inotify_rm_watch = inotify_rm_watch g
    method inspect_get_arch = inspect_get_arch g
    method inspect_get_distro = inspect_get_distro g
    method inspect_get_drive_mappings = inspect_get_drive_mappings g
    method inspect_get_filesystems = inspect_get_filesystems g
    method inspect_get_format = inspect_get_format g
    method inspect_get_hostname = inspect_get_hostname g
    method inspect_get_icon = inspect_get_icon g
    method inspect_get_major_version = inspect_get_major_version g
    method inspect_get_minor_version = inspect_get_minor_version g
    method inspect_get_mountpoints = inspect_get_mountpoints g
    method inspect_get_package_format = inspect_get_package_format g
    method inspect_get_package_management = inspect_get_package_management g
    method inspect_get_product_name = inspect_get_product_name g
    method inspect_get_product_variant = inspect_get_product_variant g
    method inspect_get_roots () = inspect_get_roots g
    method inspect_get_type = inspect_get_type g
    method inspect_get_windows_current_control_set = inspect_get_windows_current_control_set g
    method inspect_get_windows_systemroot = inspect_get_windows_systemroot g
    method inspect_is_live = inspect_is_live g
    method inspect_is_multipart = inspect_is_multipart g
    method inspect_is_netinst = inspect_is_netinst g
    method inspect_list_applications = inspect_list_applications g
    method inspect_list_applications2 = inspect_list_applications2 g
    method inspect_os () = inspect_os g
    method internal_test = internal_test g
    method internal_test_63_optargs ?opt1 ?opt2 ?opt3 ?opt4 ?opt5 ?opt6 ?opt7 ?opt8 ?opt9 ?opt10 ?opt11 ?opt12 ?opt13 ?opt14 ?opt15 ?opt16 ?opt17 ?opt18 ?opt19 ?opt20 ?opt21 ?opt22 ?opt23 ?opt24 ?opt25 ?opt26 ?opt27 ?opt28 ?opt29 ?opt30 ?opt31 ?opt32 ?opt33 ?opt34 ?opt35 ?opt36 ?opt37 ?opt38 ?opt39 ?opt40 ?opt41 ?opt42 ?opt43 ?opt44 ?opt45 ?opt46 ?opt47 ?opt48 ?opt49 ?opt50 ?opt51 ?opt52 ?opt53 ?opt54 ?opt55 ?opt56 ?opt57 ?opt58 ?opt59 ?opt60 ?opt61 ?opt62 ?opt63 () = internal_test_63_optargs g ?opt1 ?opt2 ?opt3 ?opt4 ?opt5 ?opt6 ?opt7 ?opt8 ?opt9 ?opt10 ?opt11 ?opt12 ?opt13 ?opt14 ?opt15 ?opt16 ?opt17 ?opt18 ?opt19 ?opt20 ?opt21 ?opt22 ?opt23 ?opt24 ?opt25 ?opt26 ?opt27 ?opt28 ?opt29 ?opt30 ?opt31 ?opt32 ?opt33 ?opt34 ?opt35 ?opt36 ?opt37 ?opt38 ?opt39 ?opt40 ?opt41 ?opt42 ?opt43 ?opt44 ?opt45 ?opt46 ?opt47 ?opt48 ?opt49 ?opt50 ?opt51 ?opt52 ?opt53 ?opt54 ?opt55 ?opt56 ?opt57 ?opt58 ?opt59 ?opt60 ?opt61 ?opt62 ?opt63
    method internal_test_close_output () = internal_test_close_output g
    method internal_test_only_optargs ?test () = internal_test_only_optargs g ?test
    method internal_test_rbool = internal_test_rbool g
    method internal_test_rboolerr () = internal_test_rboolerr g
    method internal_test_rbufferout = internal_test_rbufferout g
    method internal_test_rbufferouterr () = internal_test_rbufferouterr g
    method internal_test_rconstoptstring = internal_test_rconstoptstring g
    method internal_test_rconstoptstringerr () = internal_test_rconstoptstringerr g
    method internal_test_rconststring = internal_test_rconststring g
    method internal_test_rconststringerr () = internal_test_rconststringerr g
    method internal_test_rhashtable = internal_test_rhashtable g
    method internal_test_rhashtableerr () = internal_test_rhashtableerr g
    method internal_test_rint = internal_test_rint g
    method internal_test_rint64 = internal_test_rint64 g
    method internal_test_rint64err () = internal_test_rint64err g
    method internal_test_rinterr () = internal_test_rinterr g
    method internal_test_rstring = internal_test_rstring g
    method internal_test_rstringerr () = internal_test_rstringerr g
    method internal_test_rstringlist = internal_test_rstringlist g
    method internal_test_rstringlisterr () = internal_test_rstringlisterr g
    method internal_test_rstruct = internal_test_rstruct g
    method internal_test_rstructerr () = internal_test_rstructerr g
    method internal_test_rstructlist = internal_test_rstructlist g
    method internal_test_rstructlisterr () = internal_test_rstructlisterr g
    method internal_test_set_output = internal_test_set_output g
    method is_blockdev = is_blockdev g
    method is_blockdev_opts = self#is_blockdev
    method is_busy () = is_busy g
    method is_chardev = is_chardev g
    method is_chardev_opts = self#is_chardev
    method is_config () = is_config g
    method is_dir = is_dir g
    method is_dir_opts = self#is_dir
    method is_fifo = is_fifo g
    method is_fifo_opts = self#is_fifo
    method is_file = is_file g
    method is_file_opts = self#is_file
    method is_launching () = is_launching g
    method is_lv = is_lv g
    method is_ready () = is_ready g
    method is_socket = is_socket g
    method is_socket_opts = self#is_socket
    method is_symlink = is_symlink g
    method is_whole_device = is_whole_device g
    method is_zero = is_zero g
    method is_zero_device = is_zero_device g
    method isoinfo = isoinfo g
    method isoinfo_device = isoinfo_device g
    method journal_close () = journal_close g
    method journal_get () = journal_get g
    method journal_get_data_threshold () = journal_get_data_threshold g
    method journal_get_realtime_usec () = journal_get_realtime_usec g
    method journal_next () = journal_next g
    method journal_open = journal_open g
    method journal_set_data_threshold = journal_set_data_threshold g
    method journal_skip = journal_skip g
    method kill_subprocess () = kill_subprocess g
    method launch () = launch g
    method lchown = lchown g
    method ldmtool_create_all () = ldmtool_create_all g
    method ldmtool_diskgroup_disks = ldmtool_diskgroup_disks g
    method ldmtool_diskgroup_name = ldmtool_diskgroup_name g
    method ldmtool_diskgroup_volumes = ldmtool_diskgroup_volumes g
    method ldmtool_remove_all () = ldmtool_remove_all g
    method ldmtool_scan () = ldmtool_scan g
    method ldmtool_scan_devices = ldmtool_scan_devices g
    method ldmtool_volume_hint = ldmtool_volume_hint g
    method ldmtool_volume_partitions = ldmtool_volume_partitions g
    method ldmtool_volume_type = ldmtool_volume_type g
    method lgetxattr = lgetxattr g
    method lgetxattrs = lgetxattrs g
    method list_9p () = list_9p g
    method list_devices () = list_devices g
    method list_disk_labels () = list_disk_labels g
    method list_dm_devices () = list_dm_devices g
    method list_filesystems () = list_filesystems g
    method list_ldm_partitions () = list_ldm_partitions g
    method list_ldm_volumes () = list_ldm_volumes g
    method list_md_devices () = list_md_devices g
    method list_partitions () = list_partitions g
    method ll = ll g
    method llz = llz g
    method ln = ln g
    method ln_f = ln_f g
    method ln_s = ln_s g
    method ln_sf = ln_sf g
    method lremovexattr = lremovexattr g
    method ls = ls g
    method ls0 = ls0 g
    method lsetxattr = lsetxattr g
    method lstat = lstat g
    method lstatlist = lstatlist g
    method lstatns = lstatns g
    method lstatnslist = lstatnslist g
    method luks_add_key = luks_add_key g
    method luks_close = luks_close g
    method luks_format = luks_format g
    method luks_format_cipher = luks_format_cipher g
    method luks_kill_slot = luks_kill_slot g
    method luks_open = luks_open g
    method luks_open_ro = luks_open_ro g
    method lvcreate = lvcreate g
    method lvcreate_free = lvcreate_free g
    method lvm_canonical_lv_name = lvm_canonical_lv_name g
    method lvm_clear_filter () = lvm_clear_filter g
    method lvm_remove_all () = lvm_remove_all g
    method lvm_set_filter = lvm_set_filter g
    method lvremove = lvremove g
    method lvrename = lvrename g
    method lvresize = lvresize g
    method lvresize_free = lvresize_free g
    method lvs () = lvs g
    method lvs_full () = lvs_full g
    method lvuuid = lvuuid g
    method lxattrlist = lxattrlist g
    method max_disks () = max_disks g
    method md_create = md_create g
    method md_detail = md_detail g
    method md_stat = md_stat g
    method md_stop = md_stop g
    method mkdir = mkdir g
    method mkdir_mode = mkdir_mode g
    method mkdir_p = mkdir_p g
    method mkdtemp = mkdtemp g
    method mke2fs = mke2fs g
    method mke2fs_J = mke2fs_J g
    method mke2fs_JL = mke2fs_JL g
    method mke2fs_JU = mke2fs_JU g
    method mke2journal = mke2journal g
    method mke2journal_L = mke2journal_L g
    method mke2journal_U = mke2journal_U g
    method mkfifo = mkfifo g
    method mkfs = mkfs g
    method mkfs_opts = self#mkfs
    method mkfs_b = mkfs_b g
    method mkfs_btrfs = mkfs_btrfs g
    method mklost_and_found = mklost_and_found g
    method mkmountpoint = mkmountpoint g
    method mknod = mknod g
    method mknod_b = mknod_b g
    method mknod_c = mknod_c g
    method mkswap = mkswap g
    method mkswap_opts = self#mkswap
    method mkswap_L = mkswap_L g
    method mkswap_U = mkswap_U g
    method mkswap_file = mkswap_file g
    method mktemp = mktemp g
    method modprobe = modprobe g
    method mount = mount g
    method mount_9p = mount_9p g
    method mount_local = mount_local g
    method mount_local_run () = mount_local_run g
    method mount_loop = mount_loop g
    method mount_options = mount_options g
    method mount_ro = mount_ro g
    method mount_vfs = mount_vfs g
    method mountpoints () = mountpoints g
    method mounts () = mounts g
    method mv = mv g
    method nr_devices () = nr_devices g
    method ntfs_3g_probe = ntfs_3g_probe g
    method ntfsclone_in = ntfsclone_in g
    method ntfsclone_out = ntfsclone_out g
    method ntfsfix = ntfsfix g
    method ntfsresize = ntfsresize g
    method ntfsresize_opts = self#ntfsresize
    method ntfsresize_size = ntfsresize_size g
    method parse_environment () = parse_environment g
    method parse_environment_list = parse_environment_list g
    method part_add = part_add g
    method part_del = part_del g
    method part_disk = part_disk g
    method part_get_bootable = part_get_bootable g
    method part_get_gpt_type = part_get_gpt_type g
    method part_get_mbr_id = part_get_mbr_id g
    method part_get_name = part_get_name g
    method part_get_parttype = part_get_parttype g
    method part_init = part_init g
    method part_list = part_list g
    method part_set_bootable = part_set_bootable g
    method part_set_gpt_type = part_set_gpt_type g
    method part_set_mbr_id = part_set_mbr_id g
    method part_set_name = part_set_name g
    method part_to_dev = part_to_dev g
    method part_to_partnum = part_to_partnum g
    method ping_daemon () = ping_daemon g
    method pread = pread g
    method pread_device = pread_device g
    method pvchange_uuid = pvchange_uuid g
    method pvchange_uuid_all () = pvchange_uuid_all g
    method pvcreate = pvcreate g
    method pvremove = pvremove g
    method pvresize = pvresize g
    method pvresize_size = pvresize_size g
    method pvs () = pvs g
    method pvs_full () = pvs_full g
    method pvuuid = pvuuid g
    method pwrite = pwrite g
    method pwrite_device = pwrite_device g
    method read_file = read_file g
    method read_lines = read_lines g
    method readdir = readdir g
    method readlink = readlink g
    method readlinklist = readlinklist g
    method realpath = realpath g
    method remount = remount g
    method remove_drive = remove_drive g
    method removexattr = removexattr g
    method rename = rename g
    method resize2fs = resize2fs g
    method resize2fs_M = resize2fs_M g
    method resize2fs_size = resize2fs_size g
    method rm = rm g
    method rm_f = rm_f g
    method rm_rf = rm_rf g
    method rmdir = rmdir g
    method rmmountpoint = rmmountpoint g
    method rsync = rsync g
    method rsync_in = rsync_in g
    method rsync_out = rsync_out g
    method scrub_device = scrub_device g
    method scrub_file = scrub_file g
    method scrub_freespace = scrub_freespace g
    method set_append = set_append g
    method set_attach_method = set_attach_method g
    method set_autosync = set_autosync g
    method set_backend = set_backend g
    method set_backend_setting = set_backend_setting g
    method set_backend_settings = set_backend_settings g
    method set_cachedir = set_cachedir g
    method set_direct = set_direct g
    method set_e2attrs = set_e2attrs g
    method set_e2generation = set_e2generation g
    method set_e2label = set_e2label g
    method set_e2uuid = set_e2uuid g
    method set_hv = set_hv g
    method set_label = set_label g
    method set_libvirt_requested_credential = set_libvirt_requested_credential g
    method set_libvirt_supported_credentials = set_libvirt_supported_credentials g
    method set_memsize = set_memsize g
    method set_network = set_network g
    method set_path = set_path g
    method set_pgroup = set_pgroup g
    method set_program = set_program g
    method set_qemu = set_qemu g
    method set_recovery_proc = set_recovery_proc g
    method set_selinux = set_selinux g
    method set_smp = set_smp g
    method set_tmpdir = set_tmpdir g
    method set_trace = set_trace g
    method set_uuid = set_uuid g
    method set_verbose = set_verbose g
    method setcon = setcon g
    method setxattr = setxattr g
    method sfdisk = sfdisk g
    method sfdiskM = sfdiskM g
    method sfdisk_N = sfdisk_N g
    method sfdisk_disk_geometry = sfdisk_disk_geometry g
    method sfdisk_kernel_geometry = sfdisk_kernel_geometry g
    method sfdisk_l = sfdisk_l g
    method sh = sh g
    method sh_lines = sh_lines g
    method shutdown () = shutdown g
    method sleep = sleep g
    method stat = stat g
    method statns = statns g
    method statvfs = statvfs g
    method strings = strings g
    method strings_e = strings_e g
    method swapoff_device = swapoff_device g
    method swapoff_file = swapoff_file g
    method swapoff_label = swapoff_label g
    method swapoff_uuid = swapoff_uuid g
    method swapon_device = swapon_device g
    method swapon_file = swapon_file g
    method swapon_label = swapon_label g
    method swapon_uuid = swapon_uuid g
    method sync () = sync g
    method syslinux = syslinux g
    method tail = tail g
    method tail_n = tail_n g
    method tar_in = tar_in g
    method tar_in_opts = self#tar_in
    method tar_out = tar_out g
    method tar_out_opts = self#tar_out
    method tgz_in = tgz_in g
    method tgz_out = tgz_out g
    method touch = touch g
    method truncate = truncate g
    method truncate_size = truncate_size g
    method tune2fs = tune2fs g
    method tune2fs_l = tune2fs_l g
    method txz_in = txz_in g
    method txz_out = txz_out g
    method umask = umask g
    method umount = umount g
    method umount_opts = self#umount
    method umount_all () = umount_all g
    method umount_local ?retry () = umount_local g ?retry
    method upload = upload g
    method upload_offset = upload_offset g
    method user_cancel () = user_cancel g
    method utimens = utimens g
    method utsname () = utsname g
    method version () = version g
    method vfs_label = vfs_label g
    method vfs_type = vfs_type g
    method vfs_uuid = vfs_uuid g
    method vg_activate = vg_activate g
    method vg_activate_all = vg_activate_all g
    method vgchange_uuid = vgchange_uuid g
    method vgchange_uuid_all () = vgchange_uuid_all g
    method vgcreate = vgcreate g
    method vglvuuids = vglvuuids g
    method vgmeta = vgmeta g
    method vgpvuuids = vgpvuuids g
    method vgremove = vgremove g
    method vgrename = vgrename g
    method vgs () = vgs g
    method vgs_full () = vgs_full g
    method vgscan () = vgscan g
    method vguuid = vguuid g
    method wait_ready () = wait_ready g
    method wc_c = wc_c g
    method wc_l = wc_l g
    method wc_w = wc_w g
    method wipefs = wipefs g
    method write = write g
    method write_append = write_append g
    method write_file = write_file g
    method xfs_admin = xfs_admin g
    method xfs_growfs = xfs_growfs g
    method xfs_info = xfs_info g
    method xfs_repair = xfs_repair g
    method zegrep = zegrep g
    method zegrepi = zegrepi g
    method zero = zero g
    method zero_device = zero_device g
    method zero_free_space = zero_free_space g
    method zerofree = zerofree g
    method zfgrep = zfgrep g
    method zfgrepi = zfgrepi g
    method zfile = zfile g
    method zgrep = zgrep g
    method zgrepi = zgrepi g
  end
