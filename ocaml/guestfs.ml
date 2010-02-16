(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

external create : unit -> t = "ocaml_guestfs_create"
external close : t -> unit = "ocaml_guestfs_close"

(* Give the exceptions names, so they can be raised from the C code. *)
let () =
  Callback.register_exception "ocaml_guestfs_error" (Error "");
  Callback.register_exception "ocaml_guestfs_closed" (Handle_closed "")

type int_bool = {
  i : int32;
  b : int32;
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

type dirent = {
  ino : int64;
  ftyp : char;
  name : string;
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

type inotify_event = {
  in_wd : int64;
  in_mask : int32;
  in_cookie : int32;
  in_name : string;
}

type partition = {
  part_num : int32;
  part_start : int64;
  part_end : int64;
  part_size : int64;
}

external add_cdrom : t -> string -> unit = "ocaml_guestfs_add_cdrom"
external add_drive : t -> string -> unit = "ocaml_guestfs_add_drive"
external add_drive_ro : t -> string -> unit = "ocaml_guestfs_add_drive_ro"
external add_drive_ro_with_if : t -> string -> string -> unit = "ocaml_guestfs_add_drive_ro_with_if"
external add_drive_with_if : t -> string -> string -> unit = "ocaml_guestfs_add_drive_with_if"
external aug_close : t -> unit = "ocaml_guestfs_aug_close"
external aug_defnode : t -> string -> string -> string -> int_bool = "ocaml_guestfs_aug_defnode"
external aug_defvar : t -> string -> string option -> int = "ocaml_guestfs_aug_defvar"
external aug_get : t -> string -> string = "ocaml_guestfs_aug_get"
external aug_init : t -> string -> int -> unit = "ocaml_guestfs_aug_init"
external aug_insert : t -> string -> string -> bool -> unit = "ocaml_guestfs_aug_insert"
external aug_load : t -> unit = "ocaml_guestfs_aug_load"
external aug_ls : t -> string -> string array = "ocaml_guestfs_aug_ls"
external aug_match : t -> string -> string array = "ocaml_guestfs_aug_match"
external aug_mv : t -> string -> string -> unit = "ocaml_guestfs_aug_mv"
external aug_rm : t -> string -> int = "ocaml_guestfs_aug_rm"
external aug_save : t -> unit = "ocaml_guestfs_aug_save"
external aug_set : t -> string -> string -> unit = "ocaml_guestfs_aug_set"
external available : t -> string array -> unit = "ocaml_guestfs_available"
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
external case_sensitive_path : t -> string -> string = "ocaml_guestfs_case_sensitive_path"
external cat : t -> string -> string = "ocaml_guestfs_cat"
external checksum : t -> string -> string -> string = "ocaml_guestfs_checksum"
external chmod : t -> int -> string -> unit = "ocaml_guestfs_chmod"
external chown : t -> int -> int -> string -> unit = "ocaml_guestfs_chown"
external command : t -> string array -> string = "ocaml_guestfs_command"
external command_lines : t -> string array -> string array = "ocaml_guestfs_command_lines"
external config : t -> string -> string option -> unit = "ocaml_guestfs_config"
external cp : t -> string -> string -> unit = "ocaml_guestfs_cp"
external cp_a : t -> string -> string -> unit = "ocaml_guestfs_cp_a"
external dd : t -> string -> string -> unit = "ocaml_guestfs_dd"
external debug : t -> string -> string array -> string = "ocaml_guestfs_debug"
external df : t -> string = "ocaml_guestfs_df"
external df_h : t -> string = "ocaml_guestfs_df_h"
external dmesg : t -> string = "ocaml_guestfs_dmesg"
external download : t -> string -> string -> unit = "ocaml_guestfs_download"
external drop_caches : t -> int -> unit = "ocaml_guestfs_drop_caches"
external du : t -> string -> int64 = "ocaml_guestfs_du"
external e2fsck_f : t -> string -> unit = "ocaml_guestfs_e2fsck_f"
external echo_daemon : t -> string array -> string = "ocaml_guestfs_echo_daemon"
external egrep : t -> string -> string -> string array = "ocaml_guestfs_egrep"
external egrepi : t -> string -> string -> string array = "ocaml_guestfs_egrepi"
external equal : t -> string -> string -> bool = "ocaml_guestfs_equal"
external exists : t -> string -> bool = "ocaml_guestfs_exists"
external fallocate : t -> string -> int -> unit = "ocaml_guestfs_fallocate"
external fgrep : t -> string -> string -> string array = "ocaml_guestfs_fgrep"
external fgrepi : t -> string -> string -> string array = "ocaml_guestfs_fgrepi"
external file : t -> string -> string = "ocaml_guestfs_file"
external filesize : t -> string -> int64 = "ocaml_guestfs_filesize"
external fill : t -> int -> int -> string -> unit = "ocaml_guestfs_fill"
external find : t -> string -> string array = "ocaml_guestfs_find"
external find0 : t -> string -> string -> unit = "ocaml_guestfs_find0"
external fsck : t -> string -> string -> int = "ocaml_guestfs_fsck"
external get_append : t -> string option = "ocaml_guestfs_get_append"
external get_autosync : t -> bool = "ocaml_guestfs_get_autosync"
external get_direct : t -> bool = "ocaml_guestfs_get_direct"
external get_e2label : t -> string -> string = "ocaml_guestfs_get_e2label"
external get_e2uuid : t -> string -> string = "ocaml_guestfs_get_e2uuid"
external get_memsize : t -> int = "ocaml_guestfs_get_memsize"
external get_path : t -> string = "ocaml_guestfs_get_path"
external get_pid : t -> int = "ocaml_guestfs_get_pid"
external get_qemu : t -> string = "ocaml_guestfs_get_qemu"
external get_recovery_proc : t -> bool = "ocaml_guestfs_get_recovery_proc"
external get_selinux : t -> bool = "ocaml_guestfs_get_selinux"
external get_state : t -> int = "ocaml_guestfs_get_state"
external get_trace : t -> bool = "ocaml_guestfs_get_trace"
external get_verbose : t -> bool = "ocaml_guestfs_get_verbose"
external getcon : t -> string = "ocaml_guestfs_getcon"
external getxattrs : t -> string -> xattr array = "ocaml_guestfs_getxattrs"
external glob_expand : t -> string -> string array = "ocaml_guestfs_glob_expand"
external grep : t -> string -> string -> string array = "ocaml_guestfs_grep"
external grepi : t -> string -> string -> string array = "ocaml_guestfs_grepi"
external grub_install : t -> string -> string -> unit = "ocaml_guestfs_grub_install"
external head : t -> string -> string array = "ocaml_guestfs_head"
external head_n : t -> int -> string -> string array = "ocaml_guestfs_head_n"
external hexdump : t -> string -> string = "ocaml_guestfs_hexdump"
external initrd_cat : t -> string -> string -> string = "ocaml_guestfs_initrd_cat"
external initrd_list : t -> string -> string array = "ocaml_guestfs_initrd_list"
external inotify_add_watch : t -> string -> int -> int64 = "ocaml_guestfs_inotify_add_watch"
external inotify_close : t -> unit = "ocaml_guestfs_inotify_close"
external inotify_files : t -> string array = "ocaml_guestfs_inotify_files"
external inotify_init : t -> int -> unit = "ocaml_guestfs_inotify_init"
external inotify_read : t -> inotify_event array = "ocaml_guestfs_inotify_read"
external inotify_rm_watch : t -> int -> unit = "ocaml_guestfs_inotify_rm_watch"
external is_busy : t -> bool = "ocaml_guestfs_is_busy"
external is_config : t -> bool = "ocaml_guestfs_is_config"
external is_dir : t -> string -> bool = "ocaml_guestfs_is_dir"
external is_file : t -> string -> bool = "ocaml_guestfs_is_file"
external is_launching : t -> bool = "ocaml_guestfs_is_launching"
external is_ready : t -> bool = "ocaml_guestfs_is_ready"
external kill_subprocess : t -> unit = "ocaml_guestfs_kill_subprocess"
external launch : t -> unit = "ocaml_guestfs_launch"
external lchown : t -> int -> int -> string -> unit = "ocaml_guestfs_lchown"
external lgetxattrs : t -> string -> xattr array = "ocaml_guestfs_lgetxattrs"
external list_devices : t -> string array = "ocaml_guestfs_list_devices"
external list_partitions : t -> string array = "ocaml_guestfs_list_partitions"
external ll : t -> string -> string = "ocaml_guestfs_ll"
external ln : t -> string -> string -> unit = "ocaml_guestfs_ln"
external ln_f : t -> string -> string -> unit = "ocaml_guestfs_ln_f"
external ln_s : t -> string -> string -> unit = "ocaml_guestfs_ln_s"
external ln_sf : t -> string -> string -> unit = "ocaml_guestfs_ln_sf"
external lremovexattr : t -> string -> string -> unit = "ocaml_guestfs_lremovexattr"
external ls : t -> string -> string array = "ocaml_guestfs_ls"
external lsetxattr : t -> string -> string -> int -> string -> unit = "ocaml_guestfs_lsetxattr"
external lstat : t -> string -> stat = "ocaml_guestfs_lstat"
external lstatlist : t -> string -> string array -> stat array = "ocaml_guestfs_lstatlist"
external lvcreate : t -> string -> string -> int -> unit = "ocaml_guestfs_lvcreate"
external lvm_remove_all : t -> unit = "ocaml_guestfs_lvm_remove_all"
external lvremove : t -> string -> unit = "ocaml_guestfs_lvremove"
external lvrename : t -> string -> string -> unit = "ocaml_guestfs_lvrename"
external lvresize : t -> string -> int -> unit = "ocaml_guestfs_lvresize"
external lvs : t -> string array = "ocaml_guestfs_lvs"
external lvs_full : t -> lvm_lv array = "ocaml_guestfs_lvs_full"
external lxattrlist : t -> string -> string array -> xattr array = "ocaml_guestfs_lxattrlist"
external mkdir : t -> string -> unit = "ocaml_guestfs_mkdir"
external mkdir_mode : t -> string -> int -> unit = "ocaml_guestfs_mkdir_mode"
external mkdir_p : t -> string -> unit = "ocaml_guestfs_mkdir_p"
external mkdtemp : t -> string -> string = "ocaml_guestfs_mkdtemp"
external mke2fs_J : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_J"
external mke2fs_JL : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_JL"
external mke2fs_JU : t -> string -> int -> string -> string -> unit = "ocaml_guestfs_mke2fs_JU"
external mke2journal : t -> int -> string -> unit = "ocaml_guestfs_mke2journal"
external mke2journal_L : t -> int -> string -> string -> unit = "ocaml_guestfs_mke2journal_L"
external mke2journal_U : t -> int -> string -> string -> unit = "ocaml_guestfs_mke2journal_U"
external mkfifo : t -> int -> string -> unit = "ocaml_guestfs_mkfifo"
external mkfs : t -> string -> string -> unit = "ocaml_guestfs_mkfs"
external mkfs_b : t -> string -> int -> string -> unit = "ocaml_guestfs_mkfs_b"
external mkmountpoint : t -> string -> unit = "ocaml_guestfs_mkmountpoint"
external mknod : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod"
external mknod_b : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod_b"
external mknod_c : t -> int -> int -> int -> string -> unit = "ocaml_guestfs_mknod_c"
external mkswap : t -> string -> unit = "ocaml_guestfs_mkswap"
external mkswap_L : t -> string -> string -> unit = "ocaml_guestfs_mkswap_L"
external mkswap_U : t -> string -> string -> unit = "ocaml_guestfs_mkswap_U"
external mkswap_file : t -> string -> unit = "ocaml_guestfs_mkswap_file"
external modprobe : t -> string -> unit = "ocaml_guestfs_modprobe"
external mount : t -> string -> string -> unit = "ocaml_guestfs_mount"
external mount_loop : t -> string -> string -> unit = "ocaml_guestfs_mount_loop"
external mount_options : t -> string -> string -> string -> unit = "ocaml_guestfs_mount_options"
external mount_ro : t -> string -> string -> unit = "ocaml_guestfs_mount_ro"
external mount_vfs : t -> string -> string -> string -> string -> unit = "ocaml_guestfs_mount_vfs"
external mountpoints : t -> (string * string) list = "ocaml_guestfs_mountpoints"
external mounts : t -> string array = "ocaml_guestfs_mounts"
external mv : t -> string -> string -> unit = "ocaml_guestfs_mv"
external ntfs_3g_probe : t -> bool -> string -> int = "ocaml_guestfs_ntfs_3g_probe"
external part_add : t -> string -> string -> int64 -> int64 -> unit = "ocaml_guestfs_part_add"
external part_disk : t -> string -> string -> unit = "ocaml_guestfs_part_disk"
external part_get_parttype : t -> string -> string = "ocaml_guestfs_part_get_parttype"
external part_init : t -> string -> string -> unit = "ocaml_guestfs_part_init"
external part_list : t -> string -> partition array = "ocaml_guestfs_part_list"
external part_set_bootable : t -> string -> int -> bool -> unit = "ocaml_guestfs_part_set_bootable"
external part_set_name : t -> string -> int -> string -> unit = "ocaml_guestfs_part_set_name"
external ping_daemon : t -> unit = "ocaml_guestfs_ping_daemon"
external pread : t -> string -> int -> int64 -> string = "ocaml_guestfs_pread"
external pvcreate : t -> string -> unit = "ocaml_guestfs_pvcreate"
external pvremove : t -> string -> unit = "ocaml_guestfs_pvremove"
external pvresize : t -> string -> unit = "ocaml_guestfs_pvresize"
external pvs : t -> string array = "ocaml_guestfs_pvs"
external pvs_full : t -> lvm_pv array = "ocaml_guestfs_pvs_full"
external read_file : t -> string -> string = "ocaml_guestfs_read_file"
external read_lines : t -> string -> string array = "ocaml_guestfs_read_lines"
external readdir : t -> string -> dirent array = "ocaml_guestfs_readdir"
external readlink : t -> string -> string = "ocaml_guestfs_readlink"
external readlinklist : t -> string -> string array -> string array = "ocaml_guestfs_readlinklist"
external realpath : t -> string -> string = "ocaml_guestfs_realpath"
external removexattr : t -> string -> string -> unit = "ocaml_guestfs_removexattr"
external resize2fs : t -> string -> unit = "ocaml_guestfs_resize2fs"
external rm : t -> string -> unit = "ocaml_guestfs_rm"
external rm_rf : t -> string -> unit = "ocaml_guestfs_rm_rf"
external rmdir : t -> string -> unit = "ocaml_guestfs_rmdir"
external rmmountpoint : t -> string -> unit = "ocaml_guestfs_rmmountpoint"
external scrub_device : t -> string -> unit = "ocaml_guestfs_scrub_device"
external scrub_file : t -> string -> unit = "ocaml_guestfs_scrub_file"
external scrub_freespace : t -> string -> unit = "ocaml_guestfs_scrub_freespace"
external set_append : t -> string option -> unit = "ocaml_guestfs_set_append"
external set_autosync : t -> bool -> unit = "ocaml_guestfs_set_autosync"
external set_direct : t -> bool -> unit = "ocaml_guestfs_set_direct"
external set_e2label : t -> string -> string -> unit = "ocaml_guestfs_set_e2label"
external set_e2uuid : t -> string -> string -> unit = "ocaml_guestfs_set_e2uuid"
external set_memsize : t -> int -> unit = "ocaml_guestfs_set_memsize"
external set_path : t -> string -> unit = "ocaml_guestfs_set_path"
external set_qemu : t -> string -> unit = "ocaml_guestfs_set_qemu"
external set_recovery_proc : t -> bool -> unit = "ocaml_guestfs_set_recovery_proc"
external set_selinux : t -> bool -> unit = "ocaml_guestfs_set_selinux"
external set_trace : t -> bool -> unit = "ocaml_guestfs_set_trace"
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
external sleep : t -> int -> unit = "ocaml_guestfs_sleep"
external stat : t -> string -> stat = "ocaml_guestfs_stat"
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
external tail : t -> string -> string array = "ocaml_guestfs_tail"
external tail_n : t -> int -> string -> string array = "ocaml_guestfs_tail_n"
external tar_in : t -> string -> string -> unit = "ocaml_guestfs_tar_in"
external tar_out : t -> string -> string -> unit = "ocaml_guestfs_tar_out"
external test0 : t -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> unit = "ocaml_guestfs_test0_byte" "ocaml_guestfs_test0"
external test0rbool : t -> string -> bool = "ocaml_guestfs_test0rbool"
external test0rboolerr : t -> bool = "ocaml_guestfs_test0rboolerr"
external test0rconstoptstring : t -> string -> string option = "ocaml_guestfs_test0rconstoptstring"
external test0rconstoptstringerr : t -> string option = "ocaml_guestfs_test0rconstoptstringerr"
external test0rconststring : t -> string -> string = "ocaml_guestfs_test0rconststring"
external test0rconststringerr : t -> string = "ocaml_guestfs_test0rconststringerr"
external test0rhashtable : t -> string -> (string * string) list = "ocaml_guestfs_test0rhashtable"
external test0rhashtableerr : t -> (string * string) list = "ocaml_guestfs_test0rhashtableerr"
external test0rint : t -> string -> int = "ocaml_guestfs_test0rint"
external test0rint64 : t -> string -> int64 = "ocaml_guestfs_test0rint64"
external test0rint64err : t -> int64 = "ocaml_guestfs_test0rint64err"
external test0rinterr : t -> int = "ocaml_guestfs_test0rinterr"
external test0rstring : t -> string -> string = "ocaml_guestfs_test0rstring"
external test0rstringerr : t -> string = "ocaml_guestfs_test0rstringerr"
external test0rstringlist : t -> string -> string array = "ocaml_guestfs_test0rstringlist"
external test0rstringlisterr : t -> string array = "ocaml_guestfs_test0rstringlisterr"
external test0rstruct : t -> string -> lvm_pv = "ocaml_guestfs_test0rstruct"
external test0rstructerr : t -> lvm_pv = "ocaml_guestfs_test0rstructerr"
external test0rstructlist : t -> string -> lvm_pv array = "ocaml_guestfs_test0rstructlist"
external test0rstructlisterr : t -> lvm_pv array = "ocaml_guestfs_test0rstructlisterr"
external tgz_in : t -> string -> string -> unit = "ocaml_guestfs_tgz_in"
external tgz_out : t -> string -> string -> unit = "ocaml_guestfs_tgz_out"
external touch : t -> string -> unit = "ocaml_guestfs_touch"
external truncate : t -> string -> unit = "ocaml_guestfs_truncate"
external truncate_size : t -> string -> int64 -> unit = "ocaml_guestfs_truncate_size"
external tune2fs_l : t -> string -> (string * string) list = "ocaml_guestfs_tune2fs_l"
external umask : t -> int -> int = "ocaml_guestfs_umask"
external umount : t -> string -> unit = "ocaml_guestfs_umount"
external umount_all : t -> unit = "ocaml_guestfs_umount_all"
external upload : t -> string -> string -> unit = "ocaml_guestfs_upload"
external utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit = "ocaml_guestfs_utimens_byte" "ocaml_guestfs_utimens"
external version : t -> version = "ocaml_guestfs_version"
external vfs_type : t -> string -> string = "ocaml_guestfs_vfs_type"
external vg_activate : t -> bool -> string array -> unit = "ocaml_guestfs_vg_activate"
external vg_activate_all : t -> bool -> unit = "ocaml_guestfs_vg_activate_all"
external vgcreate : t -> string -> string array -> unit = "ocaml_guestfs_vgcreate"
external vgremove : t -> string -> unit = "ocaml_guestfs_vgremove"
external vgrename : t -> string -> string -> unit = "ocaml_guestfs_vgrename"
external vgs : t -> string array = "ocaml_guestfs_vgs"
external vgs_full : t -> lvm_vg array = "ocaml_guestfs_vgs_full"
external wait_ready : t -> unit = "ocaml_guestfs_wait_ready"
external wc_c : t -> string -> int = "ocaml_guestfs_wc_c"
external wc_l : t -> string -> int = "ocaml_guestfs_wc_l"
external wc_w : t -> string -> int = "ocaml_guestfs_wc_w"
external write_file : t -> string -> string -> int -> unit = "ocaml_guestfs_write_file"
external zegrep : t -> string -> string -> string array = "ocaml_guestfs_zegrep"
external zegrepi : t -> string -> string -> string array = "ocaml_guestfs_zegrepi"
external zero : t -> string -> unit = "ocaml_guestfs_zero"
external zerofree : t -> string -> unit = "ocaml_guestfs_zerofree"
external zfgrep : t -> string -> string -> string array = "ocaml_guestfs_zfgrep"
external zfgrepi : t -> string -> string -> string array = "ocaml_guestfs_zfgrepi"
external zfile : t -> string -> string -> string = "ocaml_guestfs_zfile"
external zgrep : t -> string -> string -> string array = "ocaml_guestfs_zgrep"
external zgrepi : t -> string -> string -> string array = "ocaml_guestfs_zgrepi"
