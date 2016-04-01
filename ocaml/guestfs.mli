(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ocaml.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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

(** libguestfs bindings for OCaml.

    For API documentation, the canonical reference is the
    {{:http://libguestfs.org/guestfs.3.html}guestfs(3)} man page.
    The OCaml API uses almost exactly the same calls.

    For examples written in OCaml see the
    {{:http://libguestfs.org/guestfs-ocaml.3.html}guestfs-ocaml(3)} man page.
    *)

(** {2 Module style API}

    This is the module-style API.  There is also an object-oriented API
    (see the end of this file and {!guestfs})
    which is functionally completely equivalent, but is more compact. *)

(** {3 Handles} *)

type t
(** A [guestfs_h] handle. *)

exception Error of string
(** This exception is raised when there is an error. *)

exception Handle_closed of string
(** This exception is raised if you use a {!t} handle
    after calling {!close} on it.  The string is the name of
    the function that was called incorrectly. *)

val create : ?environment:bool -> ?close_on_exit:bool -> unit -> t
(** Create a {!t} handle.

    [?environment] defaults to [true].  If set to false, it sets
    the [GUESTFS_CREATE_NO_ENVIRONMENT] flag.

    [?close_on_exit] defaults to [true].  If set to false, it sets
    the [GUESTFS_CREATE_NO_CLOSE_ON_EXIT] flag. *)

val close : t -> unit
(** Close the {!t} handle and free up all resources used
    by it immediately.

    Handles are closed by the garbage collector when they become
    unreferenced, but callers can call this in order to provide
    predictable cleanup. *)

(** {3 Events} *)

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

val event_all : event list
(** A list containing all event types. *)

type event_handle
(** The opaque event handle which can be used to delete event callbacks. *)

type event_callback = event -> event_handle -> string -> int64 array -> unit
(** The event callback. *)

val set_event_callback : t -> event_callback -> event list -> event_handle
(** [set_event_callback g f es] sets [f] as the event callback function
    for all events in the set [es].

    Note that if the closure captures a reference to the handle,
    this reference will prevent the handle from being
    automatically closed by the garbage collector. *)

val delete_event_callback : t -> event_handle -> unit
(** [delete_event_callback g eh] removes a previously registered
    event callback.  See {!set_event_callback}. *)

val event_to_string : event list -> string
(** [event_to_string events] returns the event(s) as a printable string
    for debugging etc. *)

(** {3 Errors} *)

val last_errno : t -> int
(** [last_errno g] returns the last errno that happened on the handle [g]
    (or [0] if there was no errno).  Note that the returned integer is the
    raw errno number, and it is {i not} related to the {!Unix.error} type.

    Some raw errno numbers are exposed by the {!Guestfs.Errno} submodule,
    and we can add more as required.

    [last_errno] can be overwritten by subsequent operations on a handle,
    so if you want to capture the errno correctly, you must call this
    in the {!Error} exception handler, before any other operation on [g]. *)

(** The [Guestfs.Errno] submodule exposes some raw errno numbers,
    which you can use to test the return value of {!Guestfs.last_errno}. *)

module Errno : sig
  val errno_EINVAL : int
  (** Integer value of errno [EINVAL].  See {!Guestfs.last_errno}. *)
  val errno_ENOTSUP : int
  (** Integer value of errno [ENOTSUP].  See {!Guestfs.last_errno}. *)
  val errno_EPERM : int
  (** Integer value of errno [EPERM].  See {!Guestfs.last_errno}. *)
  val errno_ESRCH : int
  (** Integer value of errno [ESRCH].  See {!Guestfs.last_errno}. *)
  val errno_ENOENT : int
  (** Integer value of errno [ENOENT].  See {!Guestfs.last_errno}. *)
end

(** {3 Structs} *)

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


(** {3 Actions} *)

val acl_delete_def_file : t -> string -> unit
(** delete the default POSIX ACL of a directory

    @since 1.19.63
 *)

val acl_get_file : t -> string -> string -> string
(** get the POSIX ACL attached to a file

    @since 1.19.63
 *)

val acl_set_file : t -> string -> string -> string -> unit
(** set the POSIX ACL attached to a file

    @since 1.19.63
 *)

val add_cdrom : t -> string -> unit
(** add a CD-ROM disk image to examine

    @deprecated Use {!add_drive_ro} instead

    @since 0.3
 *)

val add_domain : t -> ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> int
(** add the disk(s) from a named libvirt domain

    @since 1.7.4
 *)

val add_drive : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit
(** add an image to examine or modify

    @since 0.3
 *)

val add_drive_opts : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit
(** alias for {!add_drive}

    @since 0.3
 *)

val add_drive_ro : t -> string -> unit
(** add a drive in snapshot mode (read-only)

    @since 1.0.38
 *)

val add_drive_ro_with_if : t -> string -> string -> unit
(** add a drive read-only specifying the QEMU block emulation to use

    @deprecated Use {!add_drive} instead

    @since 1.0.84
 *)

val add_drive_scratch : t -> ?name:string -> ?label:string -> int64 -> unit
(** add a temporary scratch drive

    @since 1.23.10
 *)

val add_drive_with_if : t -> string -> string -> unit
(** add a drive specifying the QEMU block emulation to use

    @deprecated Use {!add_drive} instead

    @since 1.0.84
 *)

val add_libvirt_dom : t -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> int64 -> int
(** add the disk(s) from a libvirt domain

    @since 1.29.14
 *)

val aug_clear : t -> string -> unit
(** clear Augeas path

    @since 1.3.4
 *)

val aug_close : t -> unit
(** close the current Augeas handle

    @since 0.7
 *)

val aug_defnode : t -> string -> string -> string -> int_bool
(** define an Augeas node

    @since 0.7
 *)

val aug_defvar : t -> string -> string option -> int
(** define an Augeas variable

    @since 0.7
 *)

val aug_get : t -> string -> string
(** look up the value of an Augeas path

    @since 0.7
 *)

val aug_init : t -> string -> int -> unit
(** create a new Augeas handle

    @since 0.7
 *)

val aug_insert : t -> string -> string -> bool -> unit
(** insert a sibling Augeas node

    @since 0.7
 *)

val aug_label : t -> string -> string
(** return the label from an Augeas path expression

    @since 1.23.14
 *)

val aug_load : t -> unit
(** load files into the tree

    @since 0.7
 *)

val aug_ls : t -> string -> string array
(** list Augeas nodes under augpath

    @since 0.8
 *)

val aug_match : t -> string -> string array
(** return Augeas nodes which match augpath

    @since 0.7
 *)

val aug_mv : t -> string -> string -> unit
(** move Augeas node

    @since 0.7
 *)

val aug_rm : t -> string -> int
(** remove an Augeas path

    @since 0.7
 *)

val aug_save : t -> unit
(** write all pending Augeas changes to disk

    @since 0.7
 *)

val aug_set : t -> string -> string -> unit
(** set Augeas path to value

    @since 0.7
 *)

val aug_setm : t -> string -> string option -> string -> int
(** set multiple Augeas nodes

    @since 1.23.14
 *)

val available : t -> string array -> unit
(** test availability of some parts of the API

    @since 1.0.80
 *)

val available_all_groups : t -> string array
(** return a list of all optional groups

    @since 1.3.15
 *)

val base64_in : t -> string -> string -> unit
(** upload base64-encoded data to file

    @since 1.3.5
 *)

val base64_out : t -> string -> string -> unit
(** download file and encode as base64

    @since 1.3.5
 *)

val blkdiscard : t -> string -> unit
(** discard all blocks on a device

    @since 1.25.44
 *)

val blkdiscardzeroes : t -> string -> bool
(** return true if discarded blocks are read as zeroes

    @since 1.25.44
 *)

val blkid : t -> string -> (string * string) list
(** print block device attributes

    @since 1.15.9
 *)

val blockdev_flushbufs : t -> string -> unit
(** flush device buffers

    @since 1.9.3
 *)

val blockdev_getbsz : t -> string -> int
(** get blocksize of block device

    @since 1.9.3
 *)

val blockdev_getro : t -> string -> bool
(** is block device set to read-only

    @since 1.9.3
 *)

val blockdev_getsize64 : t -> string -> int64
(** get total size of device in bytes

    @since 1.9.3
 *)

val blockdev_getss : t -> string -> int
(** get sectorsize of block device

    @since 1.9.3
 *)

val blockdev_getsz : t -> string -> int64
(** get total size of device in 512-byte sectors

    @since 1.9.3
 *)

val blockdev_rereadpt : t -> string -> unit
(** reread partition table

    @since 1.9.3
 *)

val blockdev_setbsz : t -> string -> int -> unit
(** set blocksize of block device

    @deprecated Use {!mkfs} instead

    @since 1.9.3
 *)

val blockdev_setra : t -> string -> int -> unit
(** set readahead

    @since 1.29.10
 *)

val blockdev_setro : t -> string -> unit
(** set block device to read-only

    @since 1.9.3
 *)

val blockdev_setrw : t -> string -> unit
(** set block device to read-write

    @since 1.9.3
 *)

val btrfs_balance_cancel : t -> string -> unit
(** cancel a running or paused balance

    @since 1.29.22
 *)

val btrfs_balance_pause : t -> string -> unit
(** pause a running balance

    @since 1.29.22
 *)

val btrfs_balance_resume : t -> string -> unit
(** resume a paused balance

    @since 1.29.22
 *)

val btrfs_balance_status : t -> string -> btrfsbalance
(** show the status of a running or paused balance

    @since 1.29.26
 *)

val btrfs_device_add : t -> string array -> string -> unit
(** add devices to a btrfs filesystem

    @since 1.17.35
 *)

val btrfs_device_delete : t -> string array -> string -> unit
(** remove devices from a btrfs filesystem

    @since 1.17.35
 *)

val btrfs_filesystem_balance : t -> string -> unit
(** balance a btrfs filesystem

    @since 1.17.35
 *)

val btrfs_filesystem_defragment : t -> ?flush:bool -> ?compress:string -> string -> unit
(** defragment a file or directory

    @since 1.29.22
 *)

val btrfs_filesystem_resize : t -> ?size:int64 -> string -> unit
(** resize a btrfs filesystem

    @since 1.11.17
 *)

val btrfs_filesystem_sync : t -> string -> unit
(** sync a btrfs filesystem

    @since 1.17.35
 *)

val btrfs_fsck : t -> ?superblock:int64 -> ?repair:bool -> string -> unit
(** check a btrfs filesystem

    @since 1.17.43
 *)

val btrfs_image : t -> ?compresslevel:int -> string array -> string -> unit
(** create an image of a btrfs filesystem

    @since 1.29.32
 *)

val btrfs_qgroup_assign : t -> string -> string -> string -> unit
(** add a qgroup to a parent qgroup

    @since 1.29.17
 *)

val btrfs_qgroup_create : t -> string -> string -> unit
(** create a subvolume quota group

    @since 1.29.17
 *)

val btrfs_qgroup_destroy : t -> string -> string -> unit
(** destroy a subvolume quota group

    @since 1.29.17
 *)

val btrfs_qgroup_limit : t -> string -> int64 -> unit
(** limit the size of a subvolume

    @since 1.29.17
 *)

val btrfs_qgroup_remove : t -> string -> string -> string -> unit
(** remove a qgroup from its parent qgroup

    @since 1.29.17
 *)

val btrfs_qgroup_show : t -> string -> btrfsqgroup array
(** show subvolume quota groups

    @since 1.29.17
 *)

val btrfs_quota_enable : t -> string -> bool -> unit
(** enable or disable subvolume quota support

    @since 1.29.17
 *)

val btrfs_quota_rescan : t -> string -> unit
(** trash all qgroup numbers and scan the metadata again with the current config

    @since 1.29.17
 *)

val btrfs_replace : t -> string -> string -> string -> unit
(** replace a btrfs managed device with another device

    @since 1.29.48
 *)

val btrfs_rescue_chunk_recover : t -> string -> unit
(** recover the chunk tree of btrfs filesystem

    @since 1.29.22
 *)

val btrfs_rescue_super_recover : t -> string -> unit
(** recover bad superblocks from good copies

    @since 1.29.22
 *)

val btrfs_scrub_cancel : t -> string -> unit
(** cancel a running scrub

    @since 1.29.22
 *)

val btrfs_scrub_resume : t -> string -> unit
(** resume a previously canceled or interrupted scrub

    @since 1.29.22
 *)

val btrfs_scrub_start : t -> string -> unit
(** read all data from all disks and verify checksums

    @since 1.29.22
 *)

val btrfs_scrub_status : t -> string -> btrfsscrub
(** show status of running or finished scrub

    @since 1.29.26
 *)

val btrfs_set_seeding : t -> string -> bool -> unit
(** enable or disable the seeding feature of device

    @since 1.17.43
 *)

val btrfs_subvolume_create : t -> ?qgroupid:string -> string -> unit
(** create a btrfs subvolume

    @since 1.17.35
 *)

val btrfs_subvolume_create_opts : t -> ?qgroupid:string -> string -> unit
(** alias for {!btrfs_subvolume_create}

    @since 1.17.35
 *)

val btrfs_subvolume_delete : t -> string -> unit
(** delete a btrfs subvolume or snapshot

    @since 1.17.35
 *)

val btrfs_subvolume_get_default : t -> string -> int64
(** get the default subvolume or snapshot of a filesystem

    @since 1.29.17
 *)

val btrfs_subvolume_list : t -> string -> btrfssubvolume array
(** list btrfs snapshots and subvolumes

    @since 1.17.35
 *)

val btrfs_subvolume_set_default : t -> int64 -> string -> unit
(** set default btrfs subvolume

    @since 1.17.35
 *)

val btrfs_subvolume_show : t -> string -> (string * string) list
(** return detailed information of the subvolume

    @since 1.29.17
 *)

val btrfs_subvolume_snapshot : t -> ?ro:bool -> ?qgroupid:string -> string -> string -> unit
(** create a btrfs snapshot

    @since 1.17.35
 *)

val btrfs_subvolume_snapshot_opts : t -> ?ro:bool -> ?qgroupid:string -> string -> string -> unit
(** alias for {!btrfs_subvolume_snapshot}

    @since 1.17.35
 *)

val btrfstune_enable_extended_inode_refs : t -> string -> unit
(** enable extended inode refs

    @since 1.29.29
 *)

val btrfstune_enable_skinny_metadata_extent_refs : t -> string -> unit
(** enable skinny metadata extent refs

    @since 1.29.29
 *)

val btrfstune_seeding : t -> string -> bool -> unit
(** enable or disable seeding of a btrfs device

    @since 1.29.29
 *)

val c_pointer : t -> int64
(** return the C pointer to the guestfs_h handle

    @since 1.29.17
 *)

val canonical_device_name : t -> string -> string
(** return canonical device name

    @since 1.19.7
 *)

val cap_get_file : t -> string -> string
(** get the Linux capabilities attached to a file

    @since 1.19.63
 *)

val cap_set_file : t -> string -> string -> unit
(** set the Linux capabilities attached to a file

    @since 1.19.63
 *)

val case_sensitive_path : t -> string -> string
(** return true path on case-insensitive filesystem

    @since 1.0.75
 *)

val cat : t -> string -> string
(** list the contents of a file

    @since 0.4
 *)

val checksum : t -> string -> string -> string
(** compute MD5, SHAx or CRC checksum of file

    @since 1.0.2
 *)

val checksum_device : t -> string -> string -> string
(** compute MD5, SHAx or CRC checksum of the contents of a device

    @since 1.3.2
 *)

val checksums_out : t -> string -> string -> string -> unit
(** compute MD5, SHAx or CRC checksum of files in a directory

    @since 1.3.7
 *)

val chmod : t -> int -> string -> unit
(** change file mode

    @since 0.8
 *)

val chown : t -> int -> int -> string -> unit
(** change file owner and group

    @since 0.8
 *)

val clear_backend_setting : t -> string -> int
(** remove a single per-backend settings string

    @since 1.27.2
 *)

val command : t -> string array -> string
(** run a command from the guest filesystem

    @since 1.9.1
 *)

val command_lines : t -> string array -> string array
(** run a command, returning lines

    @since 1.9.1
 *)

val compress_device_out : t -> ?level:int -> string -> string -> string -> unit
(** output compressed device

    @since 1.13.15
 *)

val compress_out : t -> ?level:int -> string -> string -> string -> unit
(** output compressed file

    @since 1.13.15
 *)

val config : t -> string -> string option -> unit
(** add hypervisor parameters

    @since 0.3
 *)

val copy_attributes : t -> ?all:bool -> ?mode:bool -> ?xattributes:bool -> ?ownership:bool -> string -> string -> unit
(** copy the attributes of a path (file/directory) to another

    @since 1.25.21
 *)

val copy_device_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
(** copy from source device to destination device

    @since 1.13.25
 *)

val copy_device_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
(** copy from source device to destination file

    @since 1.13.25
 *)

val copy_file_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
(** copy from source file to destination device

    @since 1.13.25
 *)

val copy_file_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
(** copy from source file to destination file

    @since 1.13.25
 *)

val copy_in : t -> string -> string -> unit
(** copy local files or directories into an image

    @since 1.29.24
 *)

val copy_out : t -> string -> string -> unit
(** copy remote files or directories out of an image

    @since 1.29.24
 *)

val copy_size : t -> string -> string -> int64 -> unit
(** copy size bytes from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead

    @since 1.0.87
 *)

val cp : t -> string -> string -> unit
(** copy a file

    @since 1.0.18
 *)

val cp_a : t -> string -> string -> unit
(** copy a file or directory recursively

    @since 1.0.18
 *)

val cp_r : t -> string -> string -> unit
(** copy a file or directory recursively

    @since 1.21.38
 *)

val cpio_out : t -> ?format:string -> string -> string -> unit
(** pack directory into cpio file

    @since 1.27.9
 *)

val dd : t -> string -> string -> unit
(** copy from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead

    @since 1.0.80
 *)

(**/**)
val debug : t -> string -> string array -> string
(**/**)

(**/**)
val debug_drives : t -> string array
(**/**)

(**/**)
val debug_upload : t -> string -> string -> int -> unit
(**/**)

val device_index : t -> string -> int
(** convert device to index

    @since 1.19.7
 *)

val df : t -> string
(** report file system disk space usage

    @since 1.0.54
 *)

val df_h : t -> string
(** report file system disk space usage (human readable)

    @since 1.0.54
 *)

val disk_create : t -> ?backingfile:string -> ?backingformat:string -> ?preallocation:string -> ?compat:string -> ?clustersize:int -> string -> string -> int64 -> unit
(** create a blank disk image

    @since 1.25.31
 *)

val disk_format : t -> string -> string
(** detect the disk format of a disk image

    @since 1.19.38
 *)

val disk_has_backing_file : t -> string -> bool
(** return whether disk has a backing file

    @since 1.19.39
 *)

val disk_virtual_size : t -> string -> int64
(** return virtual size of a disk

    @since 1.19.39
 *)

val dmesg : t -> string
(** return kernel messages

    @since 1.0.18
 *)

val download : t -> string -> string -> unit
(** download a file to the local machine

    @since 1.0.2
 *)

val download_offset : t -> string -> string -> int64 -> int64 -> unit
(** download a file to the local machine with offset and size

    @since 1.5.17
 *)

val drop_caches : t -> int -> unit
(** drop kernel page cache, dentries and inodes

    @since 1.0.18
 *)

val du : t -> string -> int64
(** estimate file space usage

    @since 1.0.54
 *)

val e2fsck : t -> ?correct:bool -> ?forceall:bool -> string -> unit
(** check an ext2/ext3 filesystem

    @since 1.15.17
 *)

val e2fsck_f : t -> string -> unit
(** check an ext2/ext3 filesystem

    @deprecated Use {!e2fsck} instead

    @since 1.0.29
 *)

val echo_daemon : t -> string array -> string
(** echo arguments back to the client

    @since 1.0.69
 *)

val egrep : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val egrepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val equal : t -> string -> string -> bool
(** test if two files have equal contents

    @since 1.0.18
 *)

val exists : t -> string -> bool
(** test if file or directory exists

    @since 0.8
 *)

val extlinux : t -> string -> unit
(** install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem

    @since 1.21.27
 *)

val fallocate : t -> string -> int -> unit
(** preallocate a file in the guest filesystem

    @deprecated Use {!fallocate64} instead

    @since 1.0.66
 *)

val fallocate64 : t -> string -> int64 -> unit
(** preallocate a file in the guest filesystem

    @since 1.3.17
 *)

val feature_available : t -> string array -> bool
(** test availability of some parts of the API

    @since 1.21.26
 *)

val fgrep : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val fgrepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val file : t -> string -> string
(** determine file type

    @since 1.9.1
 *)

val file_architecture : t -> string -> string
(** detect the architecture of a binary file

    @since 1.5.3
 *)

val filesize : t -> string -> int64
(** return the size of the file in bytes

    @since 1.0.82
 *)

val filesystem_available : t -> string -> bool
(** check if filesystem is available

    @since 1.19.5
 *)

val fill : t -> int -> int -> string -> unit
(** fill a file with octets

    @since 1.0.79
 *)

val fill_dir : t -> string -> int -> unit
(** fill a directory with empty files

    @since 1.19.32
 *)

val fill_pattern : t -> string -> int -> string -> unit
(** fill a file with a repeating pattern of bytes

    @since 1.3.12
 *)

val find : t -> string -> string array
(** find all files and directories

    @since 1.0.27
 *)

val find0 : t -> string -> string -> unit
(** find all files and directories, returning NUL-separated list

    @since 1.0.74
 *)

val findfs_label : t -> string -> string
(** find a filesystem by label

    @since 1.5.3
 *)

val findfs_uuid : t -> string -> string
(** find a filesystem by UUID

    @since 1.5.3
 *)

val fsck : t -> string -> string -> int
(** run the filesystem checker

    @since 1.0.16
 *)

val fstrim : t -> ?offset:int64 -> ?length:int64 -> ?minimumfreeextent:int64 -> string -> unit
(** trim free space in a filesystem

    @since 1.19.6
 *)

val get_append : t -> string option
(** get the additional kernel options

    @since 1.0.26
 *)

val get_attach_method : t -> string
(** get the backend

    @deprecated Use {!get_backend} instead

    @since 1.9.8
 *)

val get_autosync : t -> bool
(** get autosync mode

    @since 0.3
 *)

val get_backend : t -> string
(** get the backend

    @since 1.21.26
 *)

val get_backend_setting : t -> string -> string
(** get a single per-backend settings string

    @since 1.27.2
 *)

val get_backend_settings : t -> string array
(** get per-backend settings

    @since 1.25.24
 *)

val get_cachedir : t -> string
(** get the appliance cache directory

    @since 1.19.58
 *)

val get_direct : t -> bool
(** get direct appliance mode flag

    @since 1.0.72
 *)

val get_e2attrs : t -> string -> string
(** get ext2 file attributes of a file

    @since 1.17.31
 *)

val get_e2generation : t -> string -> int64
(** get ext2 file generation of a file

    @since 1.17.31
 *)

val get_e2label : t -> string -> string
(** get the ext2/3/4 filesystem label

    @deprecated Use {!vfs_label} instead

    @since 1.0.15
 *)

val get_e2uuid : t -> string -> string
(** get the ext2/3/4 filesystem UUID

    @deprecated Use {!vfs_uuid} instead

    @since 1.0.15
 *)

val get_hv : t -> string
(** get the hypervisor binary

    @since 1.23.17
 *)

val get_identifier : t -> string
(** get the handle identifier

    @since 1.31.14
 *)

val get_libvirt_requested_credential_challenge : t -> int -> string
(** challenge of i'th requested credential

    @since 1.19.52
 *)

val get_libvirt_requested_credential_defresult : t -> int -> string
(** default result of i'th requested credential

    @since 1.19.52
 *)

val get_libvirt_requested_credential_prompt : t -> int -> string
(** prompt of i'th requested credential

    @since 1.19.52
 *)

val get_libvirt_requested_credentials : t -> string array
(** get list of credentials requested by libvirt

    @since 1.19.52
 *)

val get_memsize : t -> int
(** get memory allocated to the hypervisor

    @since 1.0.55
 *)

val get_network : t -> bool
(** get enable network flag

    @since 1.5.4
 *)

val get_path : t -> string
(** get the search path

    @since 0.3
 *)

val get_pgroup : t -> bool
(** get process group flag

    @since 1.11.18
 *)

val get_pid : t -> int
(** get PID of hypervisor

    @since 1.0.56
 *)

val get_program : t -> string
(** get the program name

    @since 1.21.29
 *)

val get_qemu : t -> string
(** get the hypervisor binary (usually qemu)

    @deprecated Use {!get_hv} instead

    @since 1.0.6
 *)

val get_recovery_proc : t -> bool
(** get recovery process enabled flag

    @since 1.0.77
 *)

val get_selinux : t -> bool
(** get SELinux enabled flag

    @since 1.0.67
 *)

val get_smp : t -> int
(** get number of virtual CPUs in appliance

    @since 1.13.15
 *)

val get_state : t -> int
(** get the current state

    @since 1.0.2
 *)

val get_tmpdir : t -> string
(** get the temporary directory

    @since 1.19.58
 *)

val get_trace : t -> bool
(** get command trace enabled flag

    @since 1.0.69
 *)

val get_umask : t -> int
(** get the current umask

    @since 1.3.4
 *)

val get_verbose : t -> bool
(** get verbose mode

    @since 0.3
 *)

val getcon : t -> string
(** get SELinux security context

    @since 1.0.67
 *)

val getxattr : t -> string -> string -> string
(** get a single extended attribute

    @since 1.7.24
 *)

val getxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory

    @since 1.0.59
 *)

val glob_expand : t -> string -> string array
(** expand a wildcard path

    @since 1.0.50
 *)

val grep : t -> ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array
(** return lines matching a pattern

    @since 1.0.66
 *)

val grep_opts : t -> ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array
(** alias for {!grep}

    @since 1.0.66
 *)

val grepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val grub_install : t -> string -> string -> unit
(** install GRUB 1

    @since 1.0.17
 *)

val head : t -> string -> string array
(** return first 10 lines of a file

    @since 1.0.54
 *)

val head_n : t -> int -> string -> string array
(** return first N lines of a file

    @since 1.0.54
 *)

val hexdump : t -> string -> string
(** dump a file in hexadecimal

    @since 1.0.22
 *)

val hivex_close : t -> unit
(** close the current hivex handle

    @since 1.19.35
 *)

val hivex_commit : t -> string option -> unit
(** commit (write) changes back to the hive

    @since 1.19.35
 *)

val hivex_node_add_child : t -> int64 -> string -> int64
(** add a child node

    @since 1.19.35
 *)

val hivex_node_children : t -> int64 -> hivex_node array
(** return list of nodes which are subkeys of node

    @since 1.19.35
 *)

val hivex_node_delete_child : t -> int64 -> unit
(** delete a node (recursively)

    @since 1.19.35
 *)

val hivex_node_get_child : t -> int64 -> string -> int64
(** return the named child of node

    @since 1.19.35
 *)

val hivex_node_get_value : t -> int64 -> string -> int64
(** return the named value

    @since 1.19.35
 *)

val hivex_node_name : t -> int64 -> string
(** return the name of the node

    @since 1.19.35
 *)

val hivex_node_parent : t -> int64 -> int64
(** return the parent of node

    @since 1.19.35
 *)

val hivex_node_set_value : t -> int64 -> string -> int64 -> string -> unit
(** set or replace a single value in a node

    @since 1.19.35
 *)

val hivex_node_values : t -> int64 -> hivex_value array
(** return list of values attached to node

    @since 1.19.35
 *)

val hivex_open : t -> ?verbose:bool -> ?debug:bool -> ?write:bool -> string -> unit
(** open a Windows Registry hive file

    @since 1.19.35
 *)

val hivex_root : t -> int64
(** return the root node of the hive

    @since 1.19.35
 *)

val hivex_value_key : t -> int64 -> string
(** return the key field from the (key, datatype, data) tuple

    @since 1.19.35
 *)

val hivex_value_type : t -> int64 -> int64
(** return the data type from the (key, datatype, data) tuple

    @since 1.19.35
 *)

val hivex_value_utf8 : t -> int64 -> string
(** return the data field from the (key, datatype, data) tuple

    @since 1.19.35
 *)

val hivex_value_value : t -> int64 -> string
(** return the data field from the (key, datatype, data) tuple

    @since 1.19.35
 *)

val initrd_cat : t -> string -> string -> string
(** list the contents of a single file in an initrd

    @since 1.0.84
 *)

val initrd_list : t -> string -> string array
(** list files in an initrd

    @since 1.0.54
 *)

val inotify_add_watch : t -> string -> int -> int64
(** add an inotify watch

    @since 1.0.66
 *)

val inotify_close : t -> unit
(** close the inotify handle

    @since 1.0.66
 *)

val inotify_files : t -> string array
(** return list of watched files that had events

    @since 1.0.66
 *)

val inotify_init : t -> int -> unit
(** create an inotify handle

    @since 1.0.66
 *)

val inotify_read : t -> inotify_event array
(** return list of inotify events

    @since 1.0.66
 *)

val inotify_rm_watch : t -> int -> unit
(** remove an inotify watch

    @since 1.0.66
 *)

val inspect_get_arch : t -> string -> string
(** get architecture of inspected operating system

    @since 1.5.3
 *)

val inspect_get_distro : t -> string -> string
(** get distro of inspected operating system

    @since 1.5.3
 *)

val inspect_get_drive_mappings : t -> string -> (string * string) list
(** get drive letter mappings

    @since 1.9.17
 *)

val inspect_get_filesystems : t -> string -> string array
(** get filesystems associated with inspected operating system

    @since 1.5.3
 *)

val inspect_get_format : t -> string -> string
(** get format of inspected operating system

    @since 1.9.4
 *)

val inspect_get_hostname : t -> string -> string
(** get hostname of the operating system

    @since 1.7.9
 *)

val inspect_get_icon : t -> ?favicon:bool -> ?highquality:bool -> string -> string
(** get the icon corresponding to this operating system

    @since 1.11.12
 *)

val inspect_get_major_version : t -> string -> int
(** get major version of inspected operating system

    @since 1.5.3
 *)

val inspect_get_minor_version : t -> string -> int
(** get minor version of inspected operating system

    @since 1.5.3
 *)

val inspect_get_mountpoints : t -> string -> (string * string) list
(** get mountpoints of inspected operating system

    @since 1.5.3
 *)

val inspect_get_package_format : t -> string -> string
(** get package format used by the operating system

    @since 1.7.5
 *)

val inspect_get_package_management : t -> string -> string
(** get package management tool used by the operating system

    @since 1.7.5
 *)

val inspect_get_product_name : t -> string -> string
(** get product name of inspected operating system

    @since 1.5.3
 *)

val inspect_get_product_variant : t -> string -> string
(** get product variant of inspected operating system

    @since 1.9.13
 *)

val inspect_get_roots : t -> string array
(** return list of operating systems found by last inspection

    @since 1.7.3
 *)

val inspect_get_type : t -> string -> string
(** get type of inspected operating system

    @since 1.5.3
 *)

val inspect_get_windows_current_control_set : t -> string -> string
(** get Windows CurrentControlSet of inspected operating system

    @since 1.9.17
 *)

val inspect_get_windows_systemroot : t -> string -> string
(** get Windows systemroot of inspected operating system

    @since 1.5.25
 *)

val inspect_is_live : t -> string -> bool
(** get live flag for install disk

    @since 1.9.4
 *)

val inspect_is_multipart : t -> string -> bool
(** get multipart flag for install disk

    @since 1.9.4
 *)

val inspect_is_netinst : t -> string -> bool
(** get netinst (network installer) flag for install disk

    @since 1.9.4
 *)

val inspect_list_applications : t -> string -> application array
(** get list of applications installed in the operating system

    @deprecated Use {!inspect_list_applications2} instead

    @since 1.7.8
 *)

val inspect_list_applications2 : t -> string -> application2 array
(** get list of applications installed in the operating system

    @since 1.19.56
 *)

val inspect_os : t -> string array
(** inspect disk and return list of operating systems found

    @since 1.5.3
 *)

(**/**)
val internal_exit : t -> unit
(**/**)

(**/**)
val internal_test : t -> ?obool:bool -> ?oint:int -> ?oint64:int64 -> ?ostring:string -> ?ostringlist:string array -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit
(**/**)

(**/**)
val internal_test_63_optargs : t -> ?opt1:int -> ?opt2:int -> ?opt3:int -> ?opt4:int -> ?opt5:int -> ?opt6:int -> ?opt7:int -> ?opt8:int -> ?opt9:int -> ?opt10:int -> ?opt11:int -> ?opt12:int -> ?opt13:int -> ?opt14:int -> ?opt15:int -> ?opt16:int -> ?opt17:int -> ?opt18:int -> ?opt19:int -> ?opt20:int -> ?opt21:int -> ?opt22:int -> ?opt23:int -> ?opt24:int -> ?opt25:int -> ?opt26:int -> ?opt27:int -> ?opt28:int -> ?opt29:int -> ?opt30:int -> ?opt31:int -> ?opt32:int -> ?opt33:int -> ?opt34:int -> ?opt35:int -> ?opt36:int -> ?opt37:int -> ?opt38:int -> ?opt39:int -> ?opt40:int -> ?opt41:int -> ?opt42:int -> ?opt43:int -> ?opt44:int -> ?opt45:int -> ?opt46:int -> ?opt47:int -> ?opt48:int -> ?opt49:int -> ?opt50:int -> ?opt51:int -> ?opt52:int -> ?opt53:int -> ?opt54:int -> ?opt55:int -> ?opt56:int -> ?opt57:int -> ?opt58:int -> ?opt59:int -> ?opt60:int -> ?opt61:int -> ?opt62:int -> ?opt63:int -> unit
(**/**)

(**/**)
val internal_test_close_output : t -> unit
(**/**)

(**/**)
val internal_test_only_optargs : t -> ?test:int -> unit
(**/**)

(**/**)
val internal_test_rbool : t -> string -> bool
(**/**)

(**/**)
val internal_test_rboolerr : t -> bool
(**/**)

(**/**)
val internal_test_rbufferout : t -> string -> string
(**/**)

(**/**)
val internal_test_rbufferouterr : t -> string
(**/**)

(**/**)
val internal_test_rconstoptstring : t -> string -> string option
(**/**)

(**/**)
val internal_test_rconstoptstringerr : t -> string option
(**/**)

(**/**)
val internal_test_rconststring : t -> string -> string
(**/**)

(**/**)
val internal_test_rconststringerr : t -> string
(**/**)

(**/**)
val internal_test_rhashtable : t -> string -> (string * string) list
(**/**)

(**/**)
val internal_test_rhashtableerr : t -> (string * string) list
(**/**)

(**/**)
val internal_test_rint : t -> string -> int
(**/**)

(**/**)
val internal_test_rint64 : t -> string -> int64
(**/**)

(**/**)
val internal_test_rint64err : t -> int64
(**/**)

(**/**)
val internal_test_rinterr : t -> int
(**/**)

(**/**)
val internal_test_rstring : t -> string -> string
(**/**)

(**/**)
val internal_test_rstringerr : t -> string
(**/**)

(**/**)
val internal_test_rstringlist : t -> string -> string array
(**/**)

(**/**)
val internal_test_rstringlisterr : t -> string array
(**/**)

(**/**)
val internal_test_rstruct : t -> string -> lvm_pv
(**/**)

(**/**)
val internal_test_rstructerr : t -> lvm_pv
(**/**)

(**/**)
val internal_test_rstructlist : t -> string -> lvm_pv array
(**/**)

(**/**)
val internal_test_rstructlisterr : t -> lvm_pv array
(**/**)

(**/**)
val internal_test_set_output : t -> string -> unit
(**/**)

val is_blockdev : t -> ?followsymlinks:bool -> string -> bool
(** test if block device

    @since 1.5.10
 *)

val is_blockdev_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_blockdev}

    @since 1.5.10
 *)

val is_busy : t -> bool
(** is busy processing a command

    @since 1.0.2
 *)

val is_chardev : t -> ?followsymlinks:bool -> string -> bool
(** test if character device

    @since 1.5.10
 *)

val is_chardev_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_chardev}

    @since 1.5.10
 *)

val is_config : t -> bool
(** is in configuration state

    @since 1.0.2
 *)

val is_dir : t -> ?followsymlinks:bool -> string -> bool
(** test if a directory

    @since 0.8
 *)

val is_dir_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_dir}

    @since 0.8
 *)

val is_fifo : t -> ?followsymlinks:bool -> string -> bool
(** test if FIFO (named pipe)

    @since 1.5.10
 *)

val is_fifo_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_fifo}

    @since 1.5.10
 *)

val is_file : t -> ?followsymlinks:bool -> string -> bool
(** test if a regular file

    @since 0.8
 *)

val is_file_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_file}

    @since 0.8
 *)

val is_launching : t -> bool
(** is launching subprocess

    @since 1.0.2
 *)

val is_lv : t -> string -> bool
(** test if device is a logical volume

    @since 1.5.3
 *)

val is_ready : t -> bool
(** is ready to accept commands

    @since 1.0.2
 *)

val is_socket : t -> ?followsymlinks:bool -> string -> bool
(** test if socket

    @since 1.5.10
 *)

val is_socket_opts : t -> ?followsymlinks:bool -> string -> bool
(** alias for {!is_socket}

    @since 1.5.10
 *)

val is_symlink : t -> string -> bool
(** test if symbolic link

    @since 1.5.10
 *)

val is_whole_device : t -> string -> bool
(** test if a device is a whole device

    @since 1.21.9
 *)

val is_zero : t -> string -> bool
(** test if a file contains all zero bytes

    @since 1.11.8
 *)

val is_zero_device : t -> string -> bool
(** test if a device contains all zero bytes

    @since 1.11.8
 *)

val isoinfo : t -> string -> isoinfo
(** get ISO information from primary volume descriptor of ISO file

    @since 1.17.19
 *)

val isoinfo_device : t -> string -> isoinfo
(** get ISO information from primary volume descriptor of device

    @since 1.17.19
 *)

val journal_close : t -> unit
(** close the systemd journal

    @since 1.23.11
 *)

val journal_get : t -> xattr array
(** read the current journal entry

    @since 1.23.11
 *)

val journal_get_data_threshold : t -> int64
(** get the data threshold for reading journal entries

    @since 1.23.11
 *)

val journal_get_realtime_usec : t -> int64
(** get the timestamp of the current journal entry

    @since 1.27.18
 *)

val journal_next : t -> bool
(** move to the next journal entry

    @since 1.23.11
 *)

val journal_open : t -> string -> unit
(** open the systemd journal

    @since 1.23.11
 *)

val journal_set_data_threshold : t -> int64 -> unit
(** set the data threshold for reading journal entries

    @since 1.23.11
 *)

val journal_skip : t -> int64 -> int64
(** skip forwards or backwards in the journal

    @since 1.23.11
 *)

val kill_subprocess : t -> unit
(** kill the hypervisor

    @deprecated Use {!shutdown} instead

    @since 0.3
 *)

val launch : t -> unit
(** launch the backend

    @since 0.3
 *)

val lchown : t -> int -> int -> string -> unit
(** change file owner and group

    @since 1.0.77
 *)

val ldmtool_create_all : t -> unit
(** scan and create Windows dynamic disk volumes

    @since 1.20.0
 *)

val ldmtool_diskgroup_disks : t -> string -> string array
(** return the disks in a Windows dynamic disk group

    @since 1.20.0
 *)

val ldmtool_diskgroup_name : t -> string -> string
(** return the name of a Windows dynamic disk group

    @since 1.20.0
 *)

val ldmtool_diskgroup_volumes : t -> string -> string array
(** return the volumes in a Windows dynamic disk group

    @since 1.20.0
 *)

val ldmtool_remove_all : t -> unit
(** remove all Windows dynamic disk volumes

    @since 1.20.0
 *)

val ldmtool_scan : t -> string array
(** scan for Windows dynamic disks

    @since 1.20.0
 *)

val ldmtool_scan_devices : t -> string array -> string array
(** scan for Windows dynamic disks

    @since 1.20.0
 *)

val ldmtool_volume_hint : t -> string -> string -> string
(** return the hint field of a Windows dynamic disk volume

    @since 1.20.0
 *)

val ldmtool_volume_partitions : t -> string -> string -> string array
(** return the partitions in a Windows dynamic disk volume

    @since 1.20.0
 *)

val ldmtool_volume_type : t -> string -> string -> string
(** return the type of a Windows dynamic disk volume

    @since 1.20.0
 *)

val lgetxattr : t -> string -> string -> string
(** get a single extended attribute

    @since 1.7.24
 *)

val lgetxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory

    @since 1.0.59
 *)

val list_9p : t -> string array
(** list 9p filesystems

    @since 1.11.12
 *)

val list_devices : t -> string array
(** list the block devices

    @since 0.4
 *)

val list_disk_labels : t -> (string * string) list
(** mapping of disk labels to devices

    @since 1.19.49
 *)

val list_dm_devices : t -> string array
(** list device mapper devices

    @since 1.11.15
 *)

val list_filesystems : t -> (string * string) list
(** list filesystems

    @since 1.5.15
 *)

val list_ldm_partitions : t -> string array
(** list all Windows dynamic disk partitions

    @since 1.20.0
 *)

val list_ldm_volumes : t -> string array
(** list all Windows dynamic disk volumes

    @since 1.20.0
 *)

val list_md_devices : t -> string array
(** list Linux md (RAID) devices

    @since 1.15.4
 *)

val list_partitions : t -> string array
(** list the partitions

    @since 0.4
 *)

val ll : t -> string -> string
(** list the files in a directory (long format)

    @since 0.4
 *)

val llz : t -> string -> string
(** list the files in a directory (long format with SELinux contexts)

    @since 1.17.6
 *)

val ln : t -> string -> string -> unit
(** create a hard link

    @since 1.0.66
 *)

val ln_f : t -> string -> string -> unit
(** create a hard link

    @since 1.0.66
 *)

val ln_s : t -> string -> string -> unit
(** create a symbolic link

    @since 1.0.66
 *)

val ln_sf : t -> string -> string -> unit
(** create a symbolic link

    @since 1.0.66
 *)

val lremovexattr : t -> string -> string -> unit
(** remove extended attribute of a file or directory

    @since 1.0.59
 *)

val ls : t -> string -> string array
(** list the files in a directory

    @since 0.4
 *)

val ls0 : t -> string -> string -> unit
(** get list of files in a directory

    @since 1.19.32
 *)

val lsetxattr : t -> string -> string -> int -> string -> unit
(** set extended attribute of a file or directory

    @since 1.0.59
 *)

val lstat : t -> string -> stat
(** get file information for a symbolic link

    @deprecated Use {!lstatns} instead

    @since 1.9.2
 *)

val lstatlist : t -> string -> string array -> stat array
(** lstat on multiple files

    @deprecated Use {!lstatnslist} instead

    @since 1.0.77
 *)

val lstatns : t -> string -> statns
(** get file information for a symbolic link

    @since 1.27.53
 *)

val lstatnslist : t -> string -> string array -> statns array
(** lstat on multiple files

    @since 1.27.53
 *)

val luks_add_key : t -> string -> string -> string -> int -> unit
(** add a key on a LUKS encrypted device

    @since 1.5.2
 *)

val luks_close : t -> string -> unit
(** close a LUKS device

    @since 1.5.1
 *)

val luks_format : t -> string -> string -> int -> unit
(** format a block device as a LUKS encrypted device

    @since 1.5.2
 *)

val luks_format_cipher : t -> string -> string -> int -> string -> unit
(** format a block device as a LUKS encrypted device

    @since 1.5.2
 *)

val luks_kill_slot : t -> string -> string -> int -> unit
(** remove a key from a LUKS encrypted device

    @since 1.5.2
 *)

val luks_open : t -> string -> string -> string -> unit
(** open a LUKS-encrypted block device

    @since 1.5.1
 *)

val luks_open_ro : t -> string -> string -> string -> unit
(** open a LUKS-encrypted block device read-only

    @since 1.5.1
 *)

val lvcreate : t -> string -> string -> int -> unit
(** create an LVM logical volume

    @since 0.8
 *)

val lvcreate_free : t -> string -> string -> int -> unit
(** create an LVM logical volume in % remaining free space

    @since 1.17.18
 *)

val lvm_canonical_lv_name : t -> string -> string
(** get canonical name of an LV

    @since 1.5.24
 *)

val lvm_clear_filter : t -> unit
(** clear LVM device filter

    @since 1.5.1
 *)

val lvm_remove_all : t -> unit
(** remove all LVM LVs, VGs and PVs

    @since 0.8
 *)

val lvm_set_filter : t -> string array -> unit
(** set LVM device filter

    @since 1.5.1
 *)

val lvremove : t -> string -> unit
(** remove an LVM logical volume

    @since 1.0.13
 *)

val lvrename : t -> string -> string -> unit
(** rename an LVM logical volume

    @since 1.0.83
 *)

val lvresize : t -> string -> int -> unit
(** resize an LVM logical volume

    @since 1.0.27
 *)

val lvresize_free : t -> string -> int -> unit
(** expand an LV to fill free space

    @since 1.3.3
 *)

val lvs : t -> string array
(** list the LVM logical volumes (LVs)

    @since 0.4
 *)

val lvs_full : t -> lvm_lv array
(** list the LVM logical volumes (LVs)

    @since 0.4
 *)

val lvuuid : t -> string -> string
(** get the UUID of a logical volume

    @since 1.0.87
 *)

val lxattrlist : t -> string -> string array -> xattr array
(** lgetxattr on multiple files

    @since 1.0.77
 *)

val max_disks : t -> int
(** maximum number of disks that may be added

    @since 1.19.7
 *)

val md_create : t -> ?missingbitmap:int64 -> ?nrdevices:int -> ?spare:int -> ?chunk:int64 -> ?level:string -> string -> string array -> unit
(** create a Linux md (RAID) device

    @since 1.15.6
 *)

val md_detail : t -> string -> (string * string) list
(** obtain metadata for an MD device

    @since 1.15.6
 *)

val md_stat : t -> string -> mdstat array
(** get underlying devices from an MD device

    @since 1.17.21
 *)

val md_stop : t -> string -> unit
(** stop a Linux md (RAID) device

    @since 1.15.6
 *)

val mkdir : t -> string -> unit
(** create a directory

    @since 0.8
 *)

val mkdir_mode : t -> string -> int -> unit
(** create a directory with a particular mode

    @since 1.0.77
 *)

val mkdir_p : t -> string -> unit
(** create a directory and parents

    @since 0.8
 *)

val mkdtemp : t -> string -> string
(** create a temporary directory

    @since 1.0.54
 *)

val mke2fs : t -> ?blockscount:int64 -> ?blocksize:int64 -> ?fragsize:int64 -> ?blockspergroup:int64 -> ?numberofgroups:int64 -> ?bytesperinode:int64 -> ?inodesize:int64 -> ?journalsize:int64 -> ?numberofinodes:int64 -> ?stridesize:int64 -> ?stripewidth:int64 -> ?maxonlineresize:int64 -> ?reservedblockspercentage:int -> ?mmpupdateinterval:int -> ?journaldevice:string -> ?label:string -> ?lastmounteddir:string -> ?creatoros:string -> ?fstype:string -> ?usagetype:string -> ?uuid:string -> ?forcecreate:bool -> ?writesbandgrouponly:bool -> ?lazyitableinit:bool -> ?lazyjournalinit:bool -> ?testfs:bool -> ?discard:bool -> ?quotatype:bool -> ?extent:bool -> ?filetype:bool -> ?flexbg:bool -> ?hasjournal:bool -> ?journaldev:bool -> ?largefile:bool -> ?quota:bool -> ?resizeinode:bool -> ?sparsesuper:bool -> ?uninitbg:bool -> string -> unit
(** create an ext2/ext3/ext4 filesystem on device

    @since 1.19.44
 *)

val mke2fs_J : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mke2fs_JL : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mke2fs_JU : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mke2journal : t -> int -> string -> unit
(** make ext2/3/4 external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mke2journal_L : t -> int -> string -> string -> unit
(** make ext2/3/4 external journal with label

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mke2journal_U : t -> int -> string -> string -> unit
(** make ext2/3/4 external journal with UUID

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
 *)

val mkfifo : t -> int -> string -> unit
(** make FIFO (named pipe)

    @since 1.0.55
 *)

val mkfs : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> ?label:string -> string -> string -> unit
(** make a filesystem

    @since 0.8
 *)

val mkfs_opts : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> ?label:string -> string -> string -> unit
(** alias for {!mkfs}

    @since 0.8
 *)

val mkfs_b : t -> string -> int -> string -> unit
(** make a filesystem with block size

    @deprecated Use {!mkfs} instead

    @since 1.0.68
 *)

val mkfs_btrfs : t -> ?allocstart:int64 -> ?bytecount:int64 -> ?datatype:string -> ?leafsize:int -> ?label:string -> ?metadata:string -> ?nodesize:int -> ?sectorsize:int -> string array -> unit
(** create a btrfs filesystem

    @since 1.17.25
 *)

val mklost_and_found : t -> string -> unit
(** make lost+found directory on an ext2/3/4 filesystem

    @since 1.19.56
 *)

val mkmountpoint : t -> string -> unit
(** create a mountpoint

    @since 1.0.62
 *)

val mknod : t -> int -> int -> int -> string -> unit
(** make block, character or FIFO devices

    @since 1.0.55
 *)

val mknod_b : t -> int -> int -> int -> string -> unit
(** make block device node

    @since 1.0.55
 *)

val mknod_c : t -> int -> int -> int -> string -> unit
(** make char device node

    @since 1.0.55
 *)

val mkswap : t -> ?label:string -> ?uuid:string -> string -> unit
(** create a swap partition

    @since 1.0.55
 *)

val mkswap_opts : t -> ?label:string -> ?uuid:string -> string -> unit
(** alias for {!mkswap}

    @since 1.0.55
 *)

val mkswap_L : t -> string -> string -> unit
(** create a swap partition with a label

    @deprecated Use {!mkswap} instead

    @since 1.0.55
 *)

val mkswap_U : t -> string -> string -> unit
(** create a swap partition with an explicit UUID

    @deprecated Use {!mkswap} instead

    @since 1.0.55
 *)

val mkswap_file : t -> string -> unit
(** create a swap file

    @since 1.0.66
 *)

val mktemp : t -> ?suffix:string -> string -> string
(** create a temporary file

    @since 1.19.53
 *)

val modprobe : t -> string -> unit
(** load a kernel module

    @since 1.0.68
 *)

val mount : t -> string -> string -> unit
(** mount a guest disk at a position in the filesystem

    @since 0.3
 *)

val mount_9p : t -> ?options:string -> string -> string -> unit
(** mount 9p filesystem

    @since 1.11.12
 *)

val mount_local : t -> ?readonly:bool -> ?options:string -> ?cachetimeout:int -> ?debugcalls:bool -> string -> unit
(** mount on the local filesystem

    @since 1.17.22
 *)

val mount_local_run : t -> unit
(** run main loop of mount on the local filesystem

    @since 1.17.22
 *)

val mount_loop : t -> string -> string -> unit
(** mount a file using the loop device

    @since 1.0.54
 *)

val mount_options : t -> string -> string -> string -> unit
(** mount a guest disk with mount options

    @since 1.0.10
 *)

val mount_ro : t -> string -> string -> unit
(** mount a guest disk, read-only

    @since 1.0.10
 *)

val mount_vfs : t -> string -> string -> string -> string -> unit
(** mount a guest disk with mount options and vfstype

    @since 1.0.10
 *)

val mountpoints : t -> (string * string) list
(** show mountpoints

    @since 1.0.62
 *)

val mounts : t -> string array
(** show mounted filesystems

    @since 0.8
 *)

val mv : t -> string -> string -> unit
(** move a file

    @since 1.0.18
 *)

val nr_devices : t -> int
(** return number of whole block devices (disks) added

    @since 1.19.15
 *)

val ntfs_3g_probe : t -> bool -> string -> int
(** probe NTFS volume

    @since 1.0.43
 *)

val ntfsclone_in : t -> string -> string -> unit
(** restore NTFS from backup file

    @since 1.17.9
 *)

val ntfsclone_out : t -> ?metadataonly:bool -> ?rescue:bool -> ?ignorefscheck:bool -> ?preservetimestamps:bool -> ?force:bool -> string -> string -> unit
(** save NTFS to backup file

    @since 1.17.9
 *)

val ntfsfix : t -> ?clearbadsectors:bool -> string -> unit
(** fix common errors and force Windows to check NTFS

    @since 1.17.9
 *)

val ntfsresize : t -> ?size:int64 -> ?force:bool -> string -> unit
(** resize an NTFS filesystem

    @since 1.3.2
 *)

val ntfsresize_opts : t -> ?size:int64 -> ?force:bool -> string -> unit
(** alias for {!ntfsresize}

    @since 1.3.2
 *)

val ntfsresize_size : t -> string -> int64 -> unit
(** resize an NTFS filesystem (with size)

    @deprecated Use {!ntfsresize} instead

    @since 1.3.14
 *)

val parse_environment : t -> unit
(** parse the environment and set handle flags accordingly

    @since 1.19.53
 *)

val parse_environment_list : t -> string array -> unit
(** parse the environment and set handle flags accordingly

    @since 1.19.53
 *)

val part_add : t -> string -> string -> int64 -> int64 -> unit
(** add a partition to the device

    @since 1.0.78
 *)

val part_del : t -> string -> int -> unit
(** delete a partition

    @since 1.3.2
 *)

val part_disk : t -> string -> string -> unit
(** partition whole disk with a single primary partition

    @since 1.0.78
 *)

val part_get_bootable : t -> string -> int -> bool
(** return true if a partition is bootable

    @since 1.3.2
 *)

val part_get_gpt_guid : t -> string -> int -> string
(** get the GUID of a GPT partition

    @since 1.29.25
 *)

val part_get_gpt_type : t -> string -> int -> string
(** get the type GUID of a GPT partition

    @since 1.21.1
 *)

val part_get_mbr_id : t -> string -> int -> int
(** get the MBR type byte (ID byte) from a partition

    @since 1.3.2
 *)

val part_get_mbr_part_type : t -> string -> int -> string
(** get the MBR partition type

    @since 1.29.32
 *)

val part_get_name : t -> string -> int -> string
(** get partition name

    @since 1.25.33
 *)

val part_get_parttype : t -> string -> string
(** get the partition table type

    @since 1.0.78
 *)

val part_init : t -> string -> string -> unit
(** create an empty partition table

    @since 1.0.78
 *)

val part_list : t -> string -> partition array
(** list partitions on a device

    @since 1.0.78
 *)

val part_set_bootable : t -> string -> int -> bool -> unit
(** make a partition bootable

    @since 1.0.78
 *)

val part_set_gpt_guid : t -> string -> int -> string -> unit
(** set the GUID of a GPT partition

    @since 1.29.25
 *)

val part_set_gpt_type : t -> string -> int -> string -> unit
(** set the type GUID of a GPT partition

    @since 1.21.1
 *)

val part_set_mbr_id : t -> string -> int -> int -> unit
(** set the MBR type byte (ID byte) of a partition

    @since 1.3.2
 *)

val part_set_name : t -> string -> int -> string -> unit
(** set partition name

    @since 1.0.78
 *)

val part_to_dev : t -> string -> string
(** convert partition name to device name

    @since 1.5.15
 *)

val part_to_partnum : t -> string -> int
(** convert partition name to partition number

    @since 1.13.25
 *)

val ping_daemon : t -> unit
(** ping the guest daemon

    @since 1.0.18
 *)

val pread : t -> string -> int -> int64 -> string
(** read part of a file

    @since 1.0.77
 *)

val pread_device : t -> string -> int -> int64 -> string
(** read part of a device

    @since 1.5.21
 *)

val pvchange_uuid : t -> string -> unit
(** generate a new random UUID for a physical volume

    @since 1.19.26
 *)

val pvchange_uuid_all : t -> unit
(** generate new random UUIDs for all physical volumes

    @since 1.19.26
 *)

val pvcreate : t -> string -> unit
(** create an LVM physical volume

    @since 0.8
 *)

val pvremove : t -> string -> unit
(** remove an LVM physical volume

    @since 1.0.13
 *)

val pvresize : t -> string -> unit
(** resize an LVM physical volume

    @since 1.0.26
 *)

val pvresize_size : t -> string -> int64 -> unit
(** resize an LVM physical volume (with size)

    @since 1.3.14
 *)

val pvs : t -> string array
(** list the LVM physical volumes (PVs)

    @since 0.4
 *)

val pvs_full : t -> lvm_pv array
(** list the LVM physical volumes (PVs)

    @since 0.4
 *)

val pvuuid : t -> string -> string
(** get the UUID of a physical volume

    @since 1.0.87
 *)

val pwrite : t -> string -> string -> int64 -> int
(** write to part of a file

    @since 1.3.14
 *)

val pwrite_device : t -> string -> string -> int64 -> int
(** write to part of a device

    @since 1.5.20
 *)

val read_file : t -> string -> string
(** read a file

    @since 1.0.63
 *)

val read_lines : t -> string -> string array
(** read file as lines

    @since 0.7
 *)

val readdir : t -> string -> dirent array
(** read directories entries

    @since 1.0.55
 *)

val readlink : t -> string -> string
(** read the target of a symbolic link

    @since 1.0.66
 *)

val readlinklist : t -> string -> string array -> string array
(** readlink on multiple files

    @since 1.0.77
 *)

val realpath : t -> string -> string
(** canonicalized absolute pathname

    @since 1.0.66
 *)

val remount : t -> ?rw:bool -> string -> unit
(** remount a filesystem with different options

    @since 1.23.2
 *)

val remove_drive : t -> string -> unit
(** remove a disk image

    @since 1.19.49
 *)

val removexattr : t -> string -> string -> unit
(** remove extended attribute of a file or directory

    @since 1.0.59
 *)

val rename : t -> string -> string -> unit
(** rename a file on the same filesystem

    @since 1.21.5
 *)

val resize2fs : t -> string -> unit
(** resize an ext2, ext3 or ext4 filesystem

    @since 1.0.27
 *)

val resize2fs_M : t -> string -> unit
(** resize an ext2, ext3 or ext4 filesystem to the minimum size

    @since 1.9.4
 *)

val resize2fs_size : t -> string -> int64 -> unit
(** resize an ext2, ext3 or ext4 filesystem (with size)

    @since 1.3.14
 *)

val rm : t -> string -> unit
(** remove a file

    @since 0.8
 *)

val rm_f : t -> string -> unit
(** remove a file ignoring errors

    @since 1.19.42
 *)

val rm_rf : t -> string -> unit
(** remove a file or directory recursively

    @since 0.8
 *)

val rmdir : t -> string -> unit
(** remove a directory

    @since 0.8
 *)

val rmmountpoint : t -> string -> unit
(** remove a mountpoint

    @since 1.0.62
 *)

val rsync : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
(** synchronize the contents of two directories

    @since 1.19.29
 *)

val rsync_in : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
(** synchronize host or remote filesystem with filesystem

    @since 1.19.29
 *)

val rsync_out : t -> ?archive:bool -> ?deletedest:bool -> string -> string -> unit
(** synchronize filesystem with host or remote filesystem

    @since 1.19.29
 *)

val scrub_device : t -> string -> unit
(** scrub (securely wipe) a device

    @since 1.0.52
 *)

val scrub_file : t -> string -> unit
(** scrub (securely wipe) a file

    @since 1.0.52
 *)

val scrub_freespace : t -> string -> unit
(** scrub (securely wipe) free space

    @since 1.0.52
 *)

val set_append : t -> string option -> unit
(** add options to kernel command line

    @since 1.0.26
 *)

val set_attach_method : t -> string -> unit
(** set the backend

    @deprecated Use {!set_backend} instead

    @since 1.9.8
 *)

val set_autosync : t -> bool -> unit
(** set autosync mode

    @since 0.3
 *)

val set_backend : t -> string -> unit
(** set the backend

    @since 1.21.26
 *)

val set_backend_setting : t -> string -> string -> unit
(** set a single per-backend settings string

    @since 1.27.2
 *)

val set_backend_settings : t -> string array -> unit
(** replace per-backend settings strings

    @since 1.25.24
 *)

val set_cachedir : t -> string option -> unit
(** set the appliance cache directory

    @since 1.19.58
 *)

val set_direct : t -> bool -> unit
(** enable or disable direct appliance mode

    @since 1.0.72
 *)

val set_e2attrs : t -> ?clear:bool -> string -> string -> unit
(** set ext2 file attributes of a file

    @since 1.17.31
 *)

val set_e2generation : t -> string -> int64 -> unit
(** set ext2 file generation of a file

    @since 1.17.31
 *)

val set_e2label : t -> string -> string -> unit
(** set the ext2/3/4 filesystem label

    @deprecated Use {!set_label} instead

    @since 1.0.15
 *)

val set_e2uuid : t -> string -> string -> unit
(** set the ext2/3/4 filesystem UUID

    @deprecated Use {!set_uuid} instead

    @since 1.0.15
 *)

val set_hv : t -> string -> unit
(** set the hypervisor binary

    @since 1.23.17
 *)

val set_identifier : t -> string -> unit
(** set the handle identifier

    @since 1.31.14
 *)

val set_label : t -> string -> string -> unit
(** set filesystem label

    @since 1.17.9
 *)

val set_libvirt_requested_credential : t -> int -> string -> unit
(** pass requested credential back to libvirt

    @since 1.19.52
 *)

val set_libvirt_supported_credentials : t -> string array -> unit
(** set libvirt credentials supported by calling program

    @since 1.19.52
 *)

val set_memsize : t -> int -> unit
(** set memory allocated to the hypervisor

    @since 1.0.55
 *)

val set_network : t -> bool -> unit
(** set enable network flag

    @since 1.5.4
 *)

val set_path : t -> string option -> unit
(** set the search path

    @since 0.3
 *)

val set_pgroup : t -> bool -> unit
(** set process group flag

    @since 1.11.18
 *)

val set_program : t -> string -> unit
(** set the program name

    @since 1.21.29
 *)

val set_qemu : t -> string option -> unit
(** set the hypervisor binary (usually qemu)

    @deprecated Use {!set_hv} instead

    @since 1.0.6
 *)

val set_recovery_proc : t -> bool -> unit
(** enable or disable the recovery process

    @since 1.0.77
 *)

val set_selinux : t -> bool -> unit
(** set SELinux enabled or disabled at appliance boot

    @since 1.0.67
 *)

val set_smp : t -> int -> unit
(** set number of virtual CPUs in appliance

    @since 1.13.15
 *)

val set_tmpdir : t -> string option -> unit
(** set the temporary directory

    @since 1.19.58
 *)

val set_trace : t -> bool -> unit
(** enable or disable command traces

    @since 1.0.69
 *)

val set_uuid : t -> string -> string -> unit
(** set the filesystem UUID

    @since 1.23.10
 *)

val set_uuid_random : t -> string -> unit
(** set a random UUID for the filesystem

    @since 1.29.50
 *)

val set_verbose : t -> bool -> unit
(** set verbose mode

    @since 0.3
 *)

val setcon : t -> string -> unit
(** set SELinux security context

    @since 1.0.67
 *)

val setxattr : t -> string -> string -> int -> string -> unit
(** set extended attribute of a file or directory

    @since 1.0.59
 *)

val sfdisk : t -> string -> int -> int -> int -> string array -> unit
(** create partitions on a block device

    @deprecated Use {!part_add} instead

    @since 0.8
 *)

val sfdiskM : t -> string -> string array -> unit
(** create partitions on a block device

    @deprecated Use {!part_add} instead

    @since 1.0.55
 *)

val sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit
(** modify a single partition on a block device

    @deprecated Use {!part_add} instead

    @since 1.0.26
 *)

val sfdisk_disk_geometry : t -> string -> string
(** display the disk geometry from the partition table

    @since 1.0.26
 *)

val sfdisk_kernel_geometry : t -> string -> string
(** display the kernel geometry

    @since 1.0.26
 *)

val sfdisk_l : t -> string -> string
(** display the partition table

    @deprecated Use {!part_list} instead

    @since 1.0.26
 *)

val sh : t -> string -> string
(** run a command via the shell

    @since 1.0.50
 *)

val sh_lines : t -> string -> string array
(** run a command via the shell returning lines

    @since 1.0.50
 *)

val shutdown : t -> unit
(** shutdown the hypervisor

    @since 1.19.16
 *)

val sleep : t -> int -> unit
(** sleep for some seconds

    @since 1.0.41
 *)

val stat : t -> string -> stat
(** get file information

    @deprecated Use {!statns} instead

    @since 1.9.2
 *)

val statns : t -> string -> statns
(** get file information

    @since 1.27.53
 *)

val statvfs : t -> string -> statvfs
(** get file system statistics

    @since 1.9.2
 *)

val strings : t -> string -> string array
(** print the printable strings in a file

    @since 1.0.22
 *)

val strings_e : t -> string -> string -> string array
(** print the printable strings in a file

    @since 1.0.22
 *)

val swapoff_device : t -> string -> unit
(** disable swap on device

    @since 1.0.66
 *)

val swapoff_file : t -> string -> unit
(** disable swap on file

    @since 1.0.66
 *)

val swapoff_label : t -> string -> unit
(** disable swap on labeled swap partition

    @since 1.0.66
 *)

val swapoff_uuid : t -> string -> unit
(** disable swap on swap partition by UUID

    @since 1.0.66
 *)

val swapon_device : t -> string -> unit
(** enable swap on device

    @since 1.0.66
 *)

val swapon_file : t -> string -> unit
(** enable swap on file

    @since 1.0.66
 *)

val swapon_label : t -> string -> unit
(** enable swap on labeled swap partition

    @since 1.0.66
 *)

val swapon_uuid : t -> string -> unit
(** enable swap on swap partition by UUID

    @since 1.0.66
 *)

val sync : t -> unit
(** sync disks, writes are flushed through to the disk image

    @since 0.3
 *)

val syslinux : t -> ?directory:string -> string -> unit
(** install the SYSLINUX bootloader

    @since 1.21.27
 *)

val tail : t -> string -> string array
(** return last 10 lines of a file

    @since 1.0.54
 *)

val tail_n : t -> int -> string -> string array
(** return last N lines of a file

    @since 1.0.54
 *)

val tar_in : t -> ?compress:string -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
(** unpack tarfile to directory

    @since 1.0.3
 *)

val tar_in_opts : t -> ?compress:string -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
(** alias for {!tar_in}

    @since 1.0.3
 *)

val tar_out : t -> ?compress:string -> ?numericowner:bool -> ?excludes:string array -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
(** pack directory into tarfile

    @since 1.0.3
 *)

val tar_out_opts : t -> ?compress:string -> ?numericowner:bool -> ?excludes:string array -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
(** alias for {!tar_out}

    @since 1.0.3
 *)

val tgz_in : t -> string -> string -> unit
(** unpack compressed tarball to directory

    @deprecated Use {!tar_in} instead

    @since 1.0.3
 *)

val tgz_out : t -> string -> string -> unit
(** pack directory into compressed tarball

    @deprecated Use {!tar_out} instead

    @since 1.0.3
 *)

val touch : t -> string -> unit
(** update file timestamps or create a new file

    @since 0.3
 *)

val truncate : t -> string -> unit
(** truncate a file to zero size

    @since 1.0.77
 *)

val truncate_size : t -> string -> int64 -> unit
(** truncate a file to a particular size

    @since 1.0.77
 *)

val tune2fs : t -> ?force:bool -> ?maxmountcount:int -> ?mountcount:int -> ?errorbehavior:string -> ?group:int64 -> ?intervalbetweenchecks:int -> ?reservedblockspercentage:int -> ?lastmounteddirectory:string -> ?reservedblockscount:int64 -> ?user:int64 -> string -> unit
(** adjust ext2/ext3/ext4 filesystem parameters

    @since 1.15.4
 *)

val tune2fs_l : t -> string -> (string * string) list
(** get ext2/ext3/ext4 superblock details

    @since 1.9.2
 *)

val txz_in : t -> string -> string -> unit
(** unpack compressed tarball to directory

    @deprecated Use {!tar_in} instead

    @since 1.3.2
 *)

val txz_out : t -> string -> string -> unit
(** pack directory into compressed tarball

    @deprecated Use {!tar_out} instead

    @since 1.3.2
 *)

val umask : t -> int -> int
(** set file mode creation mask (umask)

    @since 1.0.55
 *)

val umount : t -> ?force:bool -> ?lazyunmount:bool -> string -> unit
(** unmount a filesystem

    @since 0.8
 *)

val umount_opts : t -> ?force:bool -> ?lazyunmount:bool -> string -> unit
(** alias for {!umount}

    @since 0.8
 *)

val umount_all : t -> unit
(** unmount all filesystems

    @since 0.8
 *)

val umount_local : t -> ?retry:bool -> unit
(** unmount a locally mounted filesystem

    @since 1.17.22
 *)

val upload : t -> string -> string -> unit
(** upload a file from the local machine

    @since 1.0.2
 *)

val upload_offset : t -> string -> string -> int64 -> unit
(** upload a file from the local machine with offset

    @since 1.5.17
 *)

val user_cancel : t -> unit
(** cancel the current upload or download operation

    @since 1.11.18
 *)

val utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit
(** set timestamp of a file with nanosecond precision

    @since 1.0.77
 *)

val utsname : t -> utsname
(** appliance kernel version

    @since 1.19.27
 *)

val version : t -> version
(** get the library version number

    @since 1.0.58
 *)

val vfs_label : t -> string -> string
(** get the filesystem label

    @since 1.3.18
 *)

val vfs_minimum_size : t -> string -> int64
(** get minimum filesystem size

    @since 1.31.18
 *)

val vfs_type : t -> string -> string
(** get the Linux VFS type corresponding to a mounted device

    @since 1.0.75
 *)

val vfs_uuid : t -> string -> string
(** get the filesystem UUID

    @since 1.3.18
 *)

val vg_activate : t -> bool -> string array -> unit
(** activate or deactivate some volume groups

    @since 1.0.26
 *)

val vg_activate_all : t -> bool -> unit
(** activate or deactivate all volume groups

    @since 1.0.26
 *)

val vgchange_uuid : t -> string -> unit
(** generate a new random UUID for a volume group

    @since 1.19.26
 *)

val vgchange_uuid_all : t -> unit
(** generate new random UUIDs for all volume groups

    @since 1.19.26
 *)

val vgcreate : t -> string -> string array -> unit
(** create an LVM volume group

    @since 0.8
 *)

val vglvuuids : t -> string -> string array
(** get the LV UUIDs of all LVs in the volume group

    @since 1.0.87
 *)

val vgmeta : t -> string -> string
(** get volume group metadata

    @since 1.17.20
 *)

val vgpvuuids : t -> string -> string array
(** get the PV UUIDs containing the volume group

    @since 1.0.87
 *)

val vgremove : t -> string -> unit
(** remove an LVM volume group

    @since 1.0.13
 *)

val vgrename : t -> string -> string -> unit
(** rename an LVM volume group

    @since 1.0.83
 *)

val vgs : t -> string array
(** list the LVM volume groups (VGs)

    @since 0.4
 *)

val vgs_full : t -> lvm_vg array
(** list the LVM volume groups (VGs)

    @since 0.4
 *)

val vgscan : t -> unit
(** rescan for LVM physical volumes, volume groups and logical volumes

    @since 1.3.2
 *)

val vguuid : t -> string -> string
(** get the UUID of a volume group

    @since 1.0.87
 *)

val wait_ready : t -> unit
(** wait until the hypervisor launches (no op)

    @deprecated Use {!launch} instead

    @since 0.3
 *)

val wc_c : t -> string -> int
(** count characters in a file

    @since 1.0.54
 *)

val wc_l : t -> string -> int
(** count lines in a file

    @since 1.0.54
 *)

val wc_w : t -> string -> int
(** count words in a file

    @since 1.0.54
 *)

val wipefs : t -> string -> unit
(** wipe a filesystem signature from a device

    @since 1.17.6
 *)

val write : t -> string -> string -> unit
(** create a new file

    @since 1.3.14
 *)

val write_append : t -> string -> string -> unit
(** append content to end of file

    @since 1.11.18
 *)

val write_file : t -> string -> string -> int -> unit
(** create a file

    @deprecated Use {!write} instead

    @since 0.8
 *)

val xfs_admin : t -> ?extunwritten:bool -> ?imgfile:bool -> ?v2log:bool -> ?projid32bit:bool -> ?lazycounter:bool -> ?label:string -> ?uuid:string -> string -> unit
(** change parameters of an XFS filesystem

    @since 1.19.33
 *)

val xfs_growfs : t -> ?datasec:bool -> ?logsec:bool -> ?rtsec:bool -> ?datasize:int64 -> ?logsize:int64 -> ?rtsize:int64 -> ?rtextsize:int64 -> ?maxpct:int -> string -> unit
(** expand an existing XFS filesystem

    @since 1.19.28
 *)

val xfs_info : t -> string -> xfsinfo
(** get geometry of XFS filesystem

    @since 1.19.21
 *)

val xfs_repair : t -> ?forcelogzero:bool -> ?nomodify:bool -> ?noprefetch:bool -> ?forcegeometry:bool -> ?maxmem:int64 -> ?ihashsize:int64 -> ?bhashsize:int64 -> ?agstride:int64 -> ?logdev:string -> ?rtdev:string -> string -> int
(** repair an XFS filesystem

    @since 1.19.36
 *)

val zegrep : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val zegrepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val zero : t -> string -> unit
(** write zeroes to the device

    @since 1.0.16
 *)

val zero_device : t -> string -> unit
(** write zeroes to an entire device

    @since 1.3.1
 *)

val zero_free_space : t -> string -> unit
(** zero free space in a filesystem

    @since 1.17.18
 *)

val zerofree : t -> string -> unit
(** zero unused inodes and disk blocks on ext2/3 filesystem

    @since 1.0.26
 *)

val zfgrep : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val zfgrepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val zfile : t -> string -> string -> string
(** determine file type inside a compressed file

    @deprecated Use {!file} instead

    @since 1.0.59
 *)

val zgrep : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

val zgrepi : t -> string -> string -> string array
(** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
 *)

(** {2 Object-oriented API}

    This is an alternate way of calling the API using an object-oriented
    style, so you can use
    [g#]{{!guestfs.add_drive_opts}add_drive_opts} [filename]
    instead of [Guestfs.add_drive_opts g filename].
    Apart from the different style, it offers exactly the same functionality.

    Calling [new guestfs ()] creates both the object and the handle.
    The object and handle are closed either implicitly when the
    object is garbage collected, or explicitly by calling the
    [g#]{{!guestfs.close}close} [()] method.

    You can get the {!t} handle by calling
    [g#]{{!guestfs.ocaml_handle}ocaml_handle}.

    Note that methods that take no required parameters
    (except the implicit handle) get an extra unit [()] parameter.
    This is so you can create a closure from the method easily.
    For example [g#]{{!guestfs.get_verbose}get_verbose} [()]
    calls the method, whereas [g#get_verbose] is a function. *)

class guestfs : ?environment:bool -> ?close_on_exit:bool -> unit -> object
  method close : unit -> unit
  (** See {!Guestfs.close} *)
  method set_event_callback : event_callback -> event list -> event_handle
  (** See {!Guestfs.set_event_callback} *)
  method delete_event_callback : event_handle -> unit
  (** See {!Guestfs.delete_event_callback} *)
  method last_errno : unit -> int
  (** See {!Guestfs.last_errno} *)
  method ocaml_handle : t
  (** Return the {!Guestfs.t} handle *)
  method acl_delete_def_file : string -> unit
  (** delete the default POSIX ACL of a directory

    @since 1.19.63
   *)
  method acl_get_file : string -> string -> string
  (** get the POSIX ACL attached to a file

    @since 1.19.63
   *)
  method acl_set_file : string -> string -> string -> unit
  (** set the POSIX ACL attached to a file

    @since 1.19.63
   *)
  method add_cdrom : string -> unit
  (** add a CD-ROM disk image to examine

    @deprecated Use {!add_drive_ro} instead

    @since 0.3
   *)
  method add_domain : ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> int
  (** add the disk(s) from a named libvirt domain

    @since 1.7.4
   *)
  method add_drive : ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit
  (** add an image to examine or modify

    @since 0.3
   *)
  method add_drive_opts : ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> ?label:string -> ?protocol:string -> ?server:string array -> ?username:string -> ?secret:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> string -> unit
  (** alias for {!add_drive}

    @since 0.3
   *)
  method add_drive_ro : string -> unit
  (** add a drive in snapshot mode (read-only)

    @since 1.0.38
   *)
  method add_drive_ro_with_if : string -> string -> unit
  (** add a drive read-only specifying the QEMU block emulation to use

    @deprecated Use {!add_drive} instead

    @since 1.0.84
   *)
  method add_drive_scratch : ?name:string -> ?label:string -> int64 -> unit
  (** add a temporary scratch drive

    @since 1.23.10
   *)
  method add_drive_with_if : string -> string -> unit
  (** add a drive specifying the QEMU block emulation to use

    @deprecated Use {!add_drive} instead

    @since 1.0.84
   *)
  method add_libvirt_dom : ?readonly:bool -> ?iface:string -> ?live:bool -> ?readonlydisk:string -> ?cachemode:string -> ?discard:string -> ?copyonread:bool -> int64 -> int
  (** add the disk(s) from a libvirt domain

    @since 1.29.14
   *)
  method aug_clear : string -> unit
  (** clear Augeas path

    @since 1.3.4
   *)
  method aug_close : unit -> unit
  (** close the current Augeas handle

    @since 0.7
   *)
  method aug_defnode : string -> string -> string -> int_bool
  (** define an Augeas node

    @since 0.7
   *)
  method aug_defvar : string -> string option -> int
  (** define an Augeas variable

    @since 0.7
   *)
  method aug_get : string -> string
  (** look up the value of an Augeas path

    @since 0.7
   *)
  method aug_init : string -> int -> unit
  (** create a new Augeas handle

    @since 0.7
   *)
  method aug_insert : string -> string -> bool -> unit
  (** insert a sibling Augeas node

    @since 0.7
   *)
  method aug_label : string -> string
  (** return the label from an Augeas path expression

    @since 1.23.14
   *)
  method aug_load : unit -> unit
  (** load files into the tree

    @since 0.7
   *)
  method aug_ls : string -> string array
  (** list Augeas nodes under augpath

    @since 0.8
   *)
  method aug_match : string -> string array
  (** return Augeas nodes which match augpath

    @since 0.7
   *)
  method aug_mv : string -> string -> unit
  (** move Augeas node

    @since 0.7
   *)
  method aug_rm : string -> int
  (** remove an Augeas path

    @since 0.7
   *)
  method aug_save : unit -> unit
  (** write all pending Augeas changes to disk

    @since 0.7
   *)
  method aug_set : string -> string -> unit
  (** set Augeas path to value

    @since 0.7
   *)
  method aug_setm : string -> string option -> string -> int
  (** set multiple Augeas nodes

    @since 1.23.14
   *)
  method available : string array -> unit
  (** test availability of some parts of the API

    @since 1.0.80
   *)
  method available_all_groups : unit -> string array
  (** return a list of all optional groups

    @since 1.3.15
   *)
  method base64_in : string -> string -> unit
  (** upload base64-encoded data to file

    @since 1.3.5
   *)
  method base64_out : string -> string -> unit
  (** download file and encode as base64

    @since 1.3.5
   *)
  method blkdiscard : string -> unit
  (** discard all blocks on a device

    @since 1.25.44
   *)
  method blkdiscardzeroes : string -> bool
  (** return true if discarded blocks are read as zeroes

    @since 1.25.44
   *)
  method blkid : string -> (string * string) list
  (** print block device attributes

    @since 1.15.9
   *)
  method blockdev_flushbufs : string -> unit
  (** flush device buffers

    @since 1.9.3
   *)
  method blockdev_getbsz : string -> int
  (** get blocksize of block device

    @since 1.9.3
   *)
  method blockdev_getro : string -> bool
  (** is block device set to read-only

    @since 1.9.3
   *)
  method blockdev_getsize64 : string -> int64
  (** get total size of device in bytes

    @since 1.9.3
   *)
  method blockdev_getss : string -> int
  (** get sectorsize of block device

    @since 1.9.3
   *)
  method blockdev_getsz : string -> int64
  (** get total size of device in 512-byte sectors

    @since 1.9.3
   *)
  method blockdev_rereadpt : string -> unit
  (** reread partition table

    @since 1.9.3
   *)
  method blockdev_setbsz : string -> int -> unit
  (** set blocksize of block device

    @deprecated Use {!mkfs} instead

    @since 1.9.3
   *)
  method blockdev_setra : string -> int -> unit
  (** set readahead

    @since 1.29.10
   *)
  method blockdev_setro : string -> unit
  (** set block device to read-only

    @since 1.9.3
   *)
  method blockdev_setrw : string -> unit
  (** set block device to read-write

    @since 1.9.3
   *)
  method btrfs_balance_cancel : string -> unit
  (** cancel a running or paused balance

    @since 1.29.22
   *)
  method btrfs_balance_pause : string -> unit
  (** pause a running balance

    @since 1.29.22
   *)
  method btrfs_balance_resume : string -> unit
  (** resume a paused balance

    @since 1.29.22
   *)
  method btrfs_balance_status : string -> btrfsbalance
  (** show the status of a running or paused balance

    @since 1.29.26
   *)
  method btrfs_device_add : string array -> string -> unit
  (** add devices to a btrfs filesystem

    @since 1.17.35
   *)
  method btrfs_device_delete : string array -> string -> unit
  (** remove devices from a btrfs filesystem

    @since 1.17.35
   *)
  method btrfs_filesystem_balance : string -> unit
  (** balance a btrfs filesystem

    @since 1.17.35
   *)
  method btrfs_filesystem_defragment : ?flush:bool -> ?compress:string -> string -> unit
  (** defragment a file or directory

    @since 1.29.22
   *)
  method btrfs_filesystem_resize : ?size:int64 -> string -> unit
  (** resize a btrfs filesystem

    @since 1.11.17
   *)
  method btrfs_filesystem_sync : string -> unit
  (** sync a btrfs filesystem

    @since 1.17.35
   *)
  method btrfs_fsck : ?superblock:int64 -> ?repair:bool -> string -> unit
  (** check a btrfs filesystem

    @since 1.17.43
   *)
  method btrfs_image : ?compresslevel:int -> string array -> string -> unit
  (** create an image of a btrfs filesystem

    @since 1.29.32
   *)
  method btrfs_qgroup_assign : string -> string -> string -> unit
  (** add a qgroup to a parent qgroup

    @since 1.29.17
   *)
  method btrfs_qgroup_create : string -> string -> unit
  (** create a subvolume quota group

    @since 1.29.17
   *)
  method btrfs_qgroup_destroy : string -> string -> unit
  (** destroy a subvolume quota group

    @since 1.29.17
   *)
  method btrfs_qgroup_limit : string -> int64 -> unit
  (** limit the size of a subvolume

    @since 1.29.17
   *)
  method btrfs_qgroup_remove : string -> string -> string -> unit
  (** remove a qgroup from its parent qgroup

    @since 1.29.17
   *)
  method btrfs_qgroup_show : string -> btrfsqgroup array
  (** show subvolume quota groups

    @since 1.29.17
   *)
  method btrfs_quota_enable : string -> bool -> unit
  (** enable or disable subvolume quota support

    @since 1.29.17
   *)
  method btrfs_quota_rescan : string -> unit
  (** trash all qgroup numbers and scan the metadata again with the current config

    @since 1.29.17
   *)
  method btrfs_replace : string -> string -> string -> unit
  (** replace a btrfs managed device with another device

    @since 1.29.48
   *)
  method btrfs_rescue_chunk_recover : string -> unit
  (** recover the chunk tree of btrfs filesystem

    @since 1.29.22
   *)
  method btrfs_rescue_super_recover : string -> unit
  (** recover bad superblocks from good copies

    @since 1.29.22
   *)
  method btrfs_scrub_cancel : string -> unit
  (** cancel a running scrub

    @since 1.29.22
   *)
  method btrfs_scrub_resume : string -> unit
  (** resume a previously canceled or interrupted scrub

    @since 1.29.22
   *)
  method btrfs_scrub_start : string -> unit
  (** read all data from all disks and verify checksums

    @since 1.29.22
   *)
  method btrfs_scrub_status : string -> btrfsscrub
  (** show status of running or finished scrub

    @since 1.29.26
   *)
  method btrfs_set_seeding : string -> bool -> unit
  (** enable or disable the seeding feature of device

    @since 1.17.43
   *)
  method btrfs_subvolume_create : ?qgroupid:string -> string -> unit
  (** create a btrfs subvolume

    @since 1.17.35
   *)
  method btrfs_subvolume_create_opts : ?qgroupid:string -> string -> unit
  (** alias for {!btrfs_subvolume_create}

    @since 1.17.35
   *)
  method btrfs_subvolume_delete : string -> unit
  (** delete a btrfs subvolume or snapshot

    @since 1.17.35
   *)
  method btrfs_subvolume_get_default : string -> int64
  (** get the default subvolume or snapshot of a filesystem

    @since 1.29.17
   *)
  method btrfs_subvolume_list : string -> btrfssubvolume array
  (** list btrfs snapshots and subvolumes

    @since 1.17.35
   *)
  method btrfs_subvolume_set_default : int64 -> string -> unit
  (** set default btrfs subvolume

    @since 1.17.35
   *)
  method btrfs_subvolume_show : string -> (string * string) list
  (** return detailed information of the subvolume

    @since 1.29.17
   *)
  method btrfs_subvolume_snapshot : ?ro:bool -> ?qgroupid:string -> string -> string -> unit
  (** create a btrfs snapshot

    @since 1.17.35
   *)
  method btrfs_subvolume_snapshot_opts : ?ro:bool -> ?qgroupid:string -> string -> string -> unit
  (** alias for {!btrfs_subvolume_snapshot}

    @since 1.17.35
   *)
  method btrfstune_enable_extended_inode_refs : string -> unit
  (** enable extended inode refs

    @since 1.29.29
   *)
  method btrfstune_enable_skinny_metadata_extent_refs : string -> unit
  (** enable skinny metadata extent refs

    @since 1.29.29
   *)
  method btrfstune_seeding : string -> bool -> unit
  (** enable or disable seeding of a btrfs device

    @since 1.29.29
   *)
  method c_pointer : unit -> int64
  (** return the C pointer to the guestfs_h handle

    @since 1.29.17
   *)
  method canonical_device_name : string -> string
  (** return canonical device name

    @since 1.19.7
   *)
  method cap_get_file : string -> string
  (** get the Linux capabilities attached to a file

    @since 1.19.63
   *)
  method cap_set_file : string -> string -> unit
  (** set the Linux capabilities attached to a file

    @since 1.19.63
   *)
  method case_sensitive_path : string -> string
  (** return true path on case-insensitive filesystem

    @since 1.0.75
   *)
  method cat : string -> string
  (** list the contents of a file

    @since 0.4
   *)
  method checksum : string -> string -> string
  (** compute MD5, SHAx or CRC checksum of file

    @since 1.0.2
   *)
  method checksum_device : string -> string -> string
  (** compute MD5, SHAx or CRC checksum of the contents of a device

    @since 1.3.2
   *)
  method checksums_out : string -> string -> string -> unit
  (** compute MD5, SHAx or CRC checksum of files in a directory

    @since 1.3.7
   *)
  method chmod : int -> string -> unit
  (** change file mode

    @since 0.8
   *)
  method chown : int -> int -> string -> unit
  (** change file owner and group

    @since 0.8
   *)
  method clear_backend_setting : string -> int
  (** remove a single per-backend settings string

    @since 1.27.2
   *)
  method command : string array -> string
  (** run a command from the guest filesystem

    @since 1.9.1
   *)
  method command_lines : string array -> string array
  (** run a command, returning lines

    @since 1.9.1
   *)
  method compress_device_out : ?level:int -> string -> string -> string -> unit
  (** output compressed device

    @since 1.13.15
   *)
  method compress_out : ?level:int -> string -> string -> string -> unit
  (** output compressed file

    @since 1.13.15
   *)
  method config : string -> string option -> unit
  (** add hypervisor parameters

    @since 0.3
   *)
  method copy_attributes : ?all:bool -> ?mode:bool -> ?xattributes:bool -> ?ownership:bool -> string -> string -> unit
  (** copy the attributes of a path (file/directory) to another

    @since 1.25.21
   *)
  method copy_device_to_device : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
  (** copy from source device to destination device

    @since 1.13.25
   *)
  method copy_device_to_file : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
  (** copy from source device to destination file

    @since 1.13.25
   *)
  method copy_file_to_device : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
  (** copy from source file to destination device

    @since 1.13.25
   *)
  method copy_file_to_file : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> ?sparse:bool -> ?append:bool -> string -> string -> unit
  (** copy from source file to destination file

    @since 1.13.25
   *)
  method copy_in : string -> string -> unit
  (** copy local files or directories into an image

    @since 1.29.24
   *)
  method copy_out : string -> string -> unit
  (** copy remote files or directories out of an image

    @since 1.29.24
   *)
  method copy_size : string -> string -> int64 -> unit
  (** copy size bytes from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead

    @since 1.0.87
   *)
  method cp : string -> string -> unit
  (** copy a file

    @since 1.0.18
   *)
  method cp_a : string -> string -> unit
  (** copy a file or directory recursively

    @since 1.0.18
   *)
  method cp_r : string -> string -> unit
  (** copy a file or directory recursively

    @since 1.21.38
   *)
  method cpio_out : ?format:string -> string -> string -> unit
  (** pack directory into cpio file

    @since 1.27.9
   *)
  method dd : string -> string -> unit
  (** copy from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead

    @since 1.0.80
   *)
  (**/**)
  method debug : string -> string array -> string
  (**/**)
  (**/**)
  method debug_drives : unit -> string array
  (**/**)
  (**/**)
  method debug_upload : string -> string -> int -> unit
  (**/**)
  method device_index : string -> int
  (** convert device to index

    @since 1.19.7
   *)
  method df : unit -> string
  (** report file system disk space usage

    @since 1.0.54
   *)
  method df_h : unit -> string
  (** report file system disk space usage (human readable)

    @since 1.0.54
   *)
  method disk_create : ?backingfile:string -> ?backingformat:string -> ?preallocation:string -> ?compat:string -> ?clustersize:int -> string -> string -> int64 -> unit
  (** create a blank disk image

    @since 1.25.31
   *)
  method disk_format : string -> string
  (** detect the disk format of a disk image

    @since 1.19.38
   *)
  method disk_has_backing_file : string -> bool
  (** return whether disk has a backing file

    @since 1.19.39
   *)
  method disk_virtual_size : string -> int64
  (** return virtual size of a disk

    @since 1.19.39
   *)
  method dmesg : unit -> string
  (** return kernel messages

    @since 1.0.18
   *)
  method download : string -> string -> unit
  (** download a file to the local machine

    @since 1.0.2
   *)
  method download_offset : string -> string -> int64 -> int64 -> unit
  (** download a file to the local machine with offset and size

    @since 1.5.17
   *)
  method drop_caches : int -> unit
  (** drop kernel page cache, dentries and inodes

    @since 1.0.18
   *)
  method du : string -> int64
  (** estimate file space usage

    @since 1.0.54
   *)
  method e2fsck : ?correct:bool -> ?forceall:bool -> string -> unit
  (** check an ext2/ext3 filesystem

    @since 1.15.17
   *)
  method e2fsck_f : string -> unit
  (** check an ext2/ext3 filesystem

    @deprecated Use {!e2fsck} instead

    @since 1.0.29
   *)
  method echo_daemon : string array -> string
  (** echo arguments back to the client

    @since 1.0.69
   *)
  method egrep : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method egrepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method equal : string -> string -> bool
  (** test if two files have equal contents

    @since 1.0.18
   *)
  method exists : string -> bool
  (** test if file or directory exists

    @since 0.8
   *)
  method extlinux : string -> unit
  (** install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem

    @since 1.21.27
   *)
  method fallocate : string -> int -> unit
  (** preallocate a file in the guest filesystem

    @deprecated Use {!fallocate64} instead

    @since 1.0.66
   *)
  method fallocate64 : string -> int64 -> unit
  (** preallocate a file in the guest filesystem

    @since 1.3.17
   *)
  method feature_available : string array -> bool
  (** test availability of some parts of the API

    @since 1.21.26
   *)
  method fgrep : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method fgrepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method file : string -> string
  (** determine file type

    @since 1.9.1
   *)
  method file_architecture : string -> string
  (** detect the architecture of a binary file

    @since 1.5.3
   *)
  method filesize : string -> int64
  (** return the size of the file in bytes

    @since 1.0.82
   *)
  method filesystem_available : string -> bool
  (** check if filesystem is available

    @since 1.19.5
   *)
  method fill : int -> int -> string -> unit
  (** fill a file with octets

    @since 1.0.79
   *)
  method fill_dir : string -> int -> unit
  (** fill a directory with empty files

    @since 1.19.32
   *)
  method fill_pattern : string -> int -> string -> unit
  (** fill a file with a repeating pattern of bytes

    @since 1.3.12
   *)
  method find : string -> string array
  (** find all files and directories

    @since 1.0.27
   *)
  method find0 : string -> string -> unit
  (** find all files and directories, returning NUL-separated list

    @since 1.0.74
   *)
  method findfs_label : string -> string
  (** find a filesystem by label

    @since 1.5.3
   *)
  method findfs_uuid : string -> string
  (** find a filesystem by UUID

    @since 1.5.3
   *)
  method fsck : string -> string -> int
  (** run the filesystem checker

    @since 1.0.16
   *)
  method fstrim : ?offset:int64 -> ?length:int64 -> ?minimumfreeextent:int64 -> string -> unit
  (** trim free space in a filesystem

    @since 1.19.6
   *)
  method get_append : unit -> string option
  (** get the additional kernel options

    @since 1.0.26
   *)
  method get_attach_method : unit -> string
  (** get the backend

    @deprecated Use {!get_backend} instead

    @since 1.9.8
   *)
  method get_autosync : unit -> bool
  (** get autosync mode

    @since 0.3
   *)
  method get_backend : unit -> string
  (** get the backend

    @since 1.21.26
   *)
  method get_backend_setting : string -> string
  (** get a single per-backend settings string

    @since 1.27.2
   *)
  method get_backend_settings : unit -> string array
  (** get per-backend settings

    @since 1.25.24
   *)
  method get_cachedir : unit -> string
  (** get the appliance cache directory

    @since 1.19.58
   *)
  method get_direct : unit -> bool
  (** get direct appliance mode flag

    @since 1.0.72
   *)
  method get_e2attrs : string -> string
  (** get ext2 file attributes of a file

    @since 1.17.31
   *)
  method get_e2generation : string -> int64
  (** get ext2 file generation of a file

    @since 1.17.31
   *)
  method get_e2label : string -> string
  (** get the ext2/3/4 filesystem label

    @deprecated Use {!vfs_label} instead

    @since 1.0.15
   *)
  method get_e2uuid : string -> string
  (** get the ext2/3/4 filesystem UUID

    @deprecated Use {!vfs_uuid} instead

    @since 1.0.15
   *)
  method get_hv : unit -> string
  (** get the hypervisor binary

    @since 1.23.17
   *)
  method get_identifier : unit -> string
  (** get the handle identifier

    @since 1.31.14
   *)
  method get_libvirt_requested_credential_challenge : int -> string
  (** challenge of i'th requested credential

    @since 1.19.52
   *)
  method get_libvirt_requested_credential_defresult : int -> string
  (** default result of i'th requested credential

    @since 1.19.52
   *)
  method get_libvirt_requested_credential_prompt : int -> string
  (** prompt of i'th requested credential

    @since 1.19.52
   *)
  method get_libvirt_requested_credentials : unit -> string array
  (** get list of credentials requested by libvirt

    @since 1.19.52
   *)
  method get_memsize : unit -> int
  (** get memory allocated to the hypervisor

    @since 1.0.55
   *)
  method get_network : unit -> bool
  (** get enable network flag

    @since 1.5.4
   *)
  method get_path : unit -> string
  (** get the search path

    @since 0.3
   *)
  method get_pgroup : unit -> bool
  (** get process group flag

    @since 1.11.18
   *)
  method get_pid : unit -> int
  (** get PID of hypervisor

    @since 1.0.56
   *)
  method get_program : unit -> string
  (** get the program name

    @since 1.21.29
   *)
  method get_qemu : unit -> string
  (** get the hypervisor binary (usually qemu)

    @deprecated Use {!get_hv} instead

    @since 1.0.6
   *)
  method get_recovery_proc : unit -> bool
  (** get recovery process enabled flag

    @since 1.0.77
   *)
  method get_selinux : unit -> bool
  (** get SELinux enabled flag

    @since 1.0.67
   *)
  method get_smp : unit -> int
  (** get number of virtual CPUs in appliance

    @since 1.13.15
   *)
  method get_state : unit -> int
  (** get the current state

    @since 1.0.2
   *)
  method get_tmpdir : unit -> string
  (** get the temporary directory

    @since 1.19.58
   *)
  method get_trace : unit -> bool
  (** get command trace enabled flag

    @since 1.0.69
   *)
  method get_umask : unit -> int
  (** get the current umask

    @since 1.3.4
   *)
  method get_verbose : unit -> bool
  (** get verbose mode

    @since 0.3
   *)
  method getcon : unit -> string
  (** get SELinux security context

    @since 1.0.67
   *)
  method getxattr : string -> string -> string
  (** get a single extended attribute

    @since 1.7.24
   *)
  method getxattrs : string -> xattr array
  (** list extended attributes of a file or directory

    @since 1.0.59
   *)
  method glob_expand : string -> string array
  (** expand a wildcard path

    @since 1.0.50
   *)
  method grep : ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array
  (** return lines matching a pattern

    @since 1.0.66
   *)
  method grep_opts : ?extended:bool -> ?fixed:bool -> ?insensitive:bool -> ?compressed:bool -> string -> string -> string array
  (** alias for {!grep}

    @since 1.0.66
   *)
  method grepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method grub_install : string -> string -> unit
  (** install GRUB 1

    @since 1.0.17
   *)
  method head : string -> string array
  (** return first 10 lines of a file

    @since 1.0.54
   *)
  method head_n : int -> string -> string array
  (** return first N lines of a file

    @since 1.0.54
   *)
  method hexdump : string -> string
  (** dump a file in hexadecimal

    @since 1.0.22
   *)
  method hivex_close : unit -> unit
  (** close the current hivex handle

    @since 1.19.35
   *)
  method hivex_commit : string option -> unit
  (** commit (write) changes back to the hive

    @since 1.19.35
   *)
  method hivex_node_add_child : int64 -> string -> int64
  (** add a child node

    @since 1.19.35
   *)
  method hivex_node_children : int64 -> hivex_node array
  (** return list of nodes which are subkeys of node

    @since 1.19.35
   *)
  method hivex_node_delete_child : int64 -> unit
  (** delete a node (recursively)

    @since 1.19.35
   *)
  method hivex_node_get_child : int64 -> string -> int64
  (** return the named child of node

    @since 1.19.35
   *)
  method hivex_node_get_value : int64 -> string -> int64
  (** return the named value

    @since 1.19.35
   *)
  method hivex_node_name : int64 -> string
  (** return the name of the node

    @since 1.19.35
   *)
  method hivex_node_parent : int64 -> int64
  (** return the parent of node

    @since 1.19.35
   *)
  method hivex_node_set_value : int64 -> string -> int64 -> string -> unit
  (** set or replace a single value in a node

    @since 1.19.35
   *)
  method hivex_node_values : int64 -> hivex_value array
  (** return list of values attached to node

    @since 1.19.35
   *)
  method hivex_open : ?verbose:bool -> ?debug:bool -> ?write:bool -> string -> unit
  (** open a Windows Registry hive file

    @since 1.19.35
   *)
  method hivex_root : unit -> int64
  (** return the root node of the hive

    @since 1.19.35
   *)
  method hivex_value_key : int64 -> string
  (** return the key field from the (key, datatype, data) tuple

    @since 1.19.35
   *)
  method hivex_value_type : int64 -> int64
  (** return the data type from the (key, datatype, data) tuple

    @since 1.19.35
   *)
  method hivex_value_utf8 : int64 -> string
  (** return the data field from the (key, datatype, data) tuple

    @since 1.19.35
   *)
  method hivex_value_value : int64 -> string
  (** return the data field from the (key, datatype, data) tuple

    @since 1.19.35
   *)
  method initrd_cat : string -> string -> string
  (** list the contents of a single file in an initrd

    @since 1.0.84
   *)
  method initrd_list : string -> string array
  (** list files in an initrd

    @since 1.0.54
   *)
  method inotify_add_watch : string -> int -> int64
  (** add an inotify watch

    @since 1.0.66
   *)
  method inotify_close : unit -> unit
  (** close the inotify handle

    @since 1.0.66
   *)
  method inotify_files : unit -> string array
  (** return list of watched files that had events

    @since 1.0.66
   *)
  method inotify_init : int -> unit
  (** create an inotify handle

    @since 1.0.66
   *)
  method inotify_read : unit -> inotify_event array
  (** return list of inotify events

    @since 1.0.66
   *)
  method inotify_rm_watch : int -> unit
  (** remove an inotify watch

    @since 1.0.66
   *)
  method inspect_get_arch : string -> string
  (** get architecture of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_distro : string -> string
  (** get distro of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_drive_mappings : string -> (string * string) list
  (** get drive letter mappings

    @since 1.9.17
   *)
  method inspect_get_filesystems : string -> string array
  (** get filesystems associated with inspected operating system

    @since 1.5.3
   *)
  method inspect_get_format : string -> string
  (** get format of inspected operating system

    @since 1.9.4
   *)
  method inspect_get_hostname : string -> string
  (** get hostname of the operating system

    @since 1.7.9
   *)
  method inspect_get_icon : ?favicon:bool -> ?highquality:bool -> string -> string
  (** get the icon corresponding to this operating system

    @since 1.11.12
   *)
  method inspect_get_major_version : string -> int
  (** get major version of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_minor_version : string -> int
  (** get minor version of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_mountpoints : string -> (string * string) list
  (** get mountpoints of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_package_format : string -> string
  (** get package format used by the operating system

    @since 1.7.5
   *)
  method inspect_get_package_management : string -> string
  (** get package management tool used by the operating system

    @since 1.7.5
   *)
  method inspect_get_product_name : string -> string
  (** get product name of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_product_variant : string -> string
  (** get product variant of inspected operating system

    @since 1.9.13
   *)
  method inspect_get_roots : unit -> string array
  (** return list of operating systems found by last inspection

    @since 1.7.3
   *)
  method inspect_get_type : string -> string
  (** get type of inspected operating system

    @since 1.5.3
   *)
  method inspect_get_windows_current_control_set : string -> string
  (** get Windows CurrentControlSet of inspected operating system

    @since 1.9.17
   *)
  method inspect_get_windows_systemroot : string -> string
  (** get Windows systemroot of inspected operating system

    @since 1.5.25
   *)
  method inspect_is_live : string -> bool
  (** get live flag for install disk

    @since 1.9.4
   *)
  method inspect_is_multipart : string -> bool
  (** get multipart flag for install disk

    @since 1.9.4
   *)
  method inspect_is_netinst : string -> bool
  (** get netinst (network installer) flag for install disk

    @since 1.9.4
   *)
  method inspect_list_applications : string -> application array
  (** get list of applications installed in the operating system

    @deprecated Use {!inspect_list_applications2} instead

    @since 1.7.8
   *)
  method inspect_list_applications2 : string -> application2 array
  (** get list of applications installed in the operating system

    @since 1.19.56
   *)
  method inspect_os : unit -> string array
  (** inspect disk and return list of operating systems found

    @since 1.5.3
   *)
  (**/**)
  method internal_exit : unit -> unit
  (**/**)
  (**/**)
  method internal_test : ?obool:bool -> ?oint:int -> ?oint64:int64 -> ?ostring:string -> ?ostringlist:string array -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit
  (**/**)
  (**/**)
  method internal_test_63_optargs : ?opt1:int -> ?opt2:int -> ?opt3:int -> ?opt4:int -> ?opt5:int -> ?opt6:int -> ?opt7:int -> ?opt8:int -> ?opt9:int -> ?opt10:int -> ?opt11:int -> ?opt12:int -> ?opt13:int -> ?opt14:int -> ?opt15:int -> ?opt16:int -> ?opt17:int -> ?opt18:int -> ?opt19:int -> ?opt20:int -> ?opt21:int -> ?opt22:int -> ?opt23:int -> ?opt24:int -> ?opt25:int -> ?opt26:int -> ?opt27:int -> ?opt28:int -> ?opt29:int -> ?opt30:int -> ?opt31:int -> ?opt32:int -> ?opt33:int -> ?opt34:int -> ?opt35:int -> ?opt36:int -> ?opt37:int -> ?opt38:int -> ?opt39:int -> ?opt40:int -> ?opt41:int -> ?opt42:int -> ?opt43:int -> ?opt44:int -> ?opt45:int -> ?opt46:int -> ?opt47:int -> ?opt48:int -> ?opt49:int -> ?opt50:int -> ?opt51:int -> ?opt52:int -> ?opt53:int -> ?opt54:int -> ?opt55:int -> ?opt56:int -> ?opt57:int -> ?opt58:int -> ?opt59:int -> ?opt60:int -> ?opt61:int -> ?opt62:int -> ?opt63:int -> unit -> unit
  (**/**)
  (**/**)
  method internal_test_close_output : unit -> unit
  (**/**)
  (**/**)
  method internal_test_only_optargs : ?test:int -> unit -> unit
  (**/**)
  (**/**)
  method internal_test_rbool : string -> bool
  (**/**)
  (**/**)
  method internal_test_rboolerr : unit -> bool
  (**/**)
  (**/**)
  method internal_test_rbufferout : string -> string
  (**/**)
  (**/**)
  method internal_test_rbufferouterr : unit -> string
  (**/**)
  (**/**)
  method internal_test_rconstoptstring : string -> string option
  (**/**)
  (**/**)
  method internal_test_rconstoptstringerr : unit -> string option
  (**/**)
  (**/**)
  method internal_test_rconststring : string -> string
  (**/**)
  (**/**)
  method internal_test_rconststringerr : unit -> string
  (**/**)
  (**/**)
  method internal_test_rhashtable : string -> (string * string) list
  (**/**)
  (**/**)
  method internal_test_rhashtableerr : unit -> (string * string) list
  (**/**)
  (**/**)
  method internal_test_rint : string -> int
  (**/**)
  (**/**)
  method internal_test_rint64 : string -> int64
  (**/**)
  (**/**)
  method internal_test_rint64err : unit -> int64
  (**/**)
  (**/**)
  method internal_test_rinterr : unit -> int
  (**/**)
  (**/**)
  method internal_test_rstring : string -> string
  (**/**)
  (**/**)
  method internal_test_rstringerr : unit -> string
  (**/**)
  (**/**)
  method internal_test_rstringlist : string -> string array
  (**/**)
  (**/**)
  method internal_test_rstringlisterr : unit -> string array
  (**/**)
  (**/**)
  method internal_test_rstruct : string -> lvm_pv
  (**/**)
  (**/**)
  method internal_test_rstructerr : unit -> lvm_pv
  (**/**)
  (**/**)
  method internal_test_rstructlist : string -> lvm_pv array
  (**/**)
  (**/**)
  method internal_test_rstructlisterr : unit -> lvm_pv array
  (**/**)
  (**/**)
  method internal_test_set_output : string -> unit
  (**/**)
  method is_blockdev : ?followsymlinks:bool -> string -> bool
  (** test if block device

    @since 1.5.10
   *)
  method is_blockdev_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_blockdev}

    @since 1.5.10
   *)
  method is_busy : unit -> bool
  (** is busy processing a command

    @since 1.0.2
   *)
  method is_chardev : ?followsymlinks:bool -> string -> bool
  (** test if character device

    @since 1.5.10
   *)
  method is_chardev_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_chardev}

    @since 1.5.10
   *)
  method is_config : unit -> bool
  (** is in configuration state

    @since 1.0.2
   *)
  method is_dir : ?followsymlinks:bool -> string -> bool
  (** test if a directory

    @since 0.8
   *)
  method is_dir_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_dir}

    @since 0.8
   *)
  method is_fifo : ?followsymlinks:bool -> string -> bool
  (** test if FIFO (named pipe)

    @since 1.5.10
   *)
  method is_fifo_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_fifo}

    @since 1.5.10
   *)
  method is_file : ?followsymlinks:bool -> string -> bool
  (** test if a regular file

    @since 0.8
   *)
  method is_file_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_file}

    @since 0.8
   *)
  method is_launching : unit -> bool
  (** is launching subprocess

    @since 1.0.2
   *)
  method is_lv : string -> bool
  (** test if device is a logical volume

    @since 1.5.3
   *)
  method is_ready : unit -> bool
  (** is ready to accept commands

    @since 1.0.2
   *)
  method is_socket : ?followsymlinks:bool -> string -> bool
  (** test if socket

    @since 1.5.10
   *)
  method is_socket_opts : ?followsymlinks:bool -> string -> bool
  (** alias for {!is_socket}

    @since 1.5.10
   *)
  method is_symlink : string -> bool
  (** test if symbolic link

    @since 1.5.10
   *)
  method is_whole_device : string -> bool
  (** test if a device is a whole device

    @since 1.21.9
   *)
  method is_zero : string -> bool
  (** test if a file contains all zero bytes

    @since 1.11.8
   *)
  method is_zero_device : string -> bool
  (** test if a device contains all zero bytes

    @since 1.11.8
   *)
  method isoinfo : string -> isoinfo
  (** get ISO information from primary volume descriptor of ISO file

    @since 1.17.19
   *)
  method isoinfo_device : string -> isoinfo
  (** get ISO information from primary volume descriptor of device

    @since 1.17.19
   *)
  method journal_close : unit -> unit
  (** close the systemd journal

    @since 1.23.11
   *)
  method journal_get : unit -> xattr array
  (** read the current journal entry

    @since 1.23.11
   *)
  method journal_get_data_threshold : unit -> int64
  (** get the data threshold for reading journal entries

    @since 1.23.11
   *)
  method journal_get_realtime_usec : unit -> int64
  (** get the timestamp of the current journal entry

    @since 1.27.18
   *)
  method journal_next : unit -> bool
  (** move to the next journal entry

    @since 1.23.11
   *)
  method journal_open : string -> unit
  (** open the systemd journal

    @since 1.23.11
   *)
  method journal_set_data_threshold : int64 -> unit
  (** set the data threshold for reading journal entries

    @since 1.23.11
   *)
  method journal_skip : int64 -> int64
  (** skip forwards or backwards in the journal

    @since 1.23.11
   *)
  method kill_subprocess : unit -> unit
  (** kill the hypervisor

    @deprecated Use {!shutdown} instead

    @since 0.3
   *)
  method launch : unit -> unit
  (** launch the backend

    @since 0.3
   *)
  method lchown : int -> int -> string -> unit
  (** change file owner and group

    @since 1.0.77
   *)
  method ldmtool_create_all : unit -> unit
  (** scan and create Windows dynamic disk volumes

    @since 1.20.0
   *)
  method ldmtool_diskgroup_disks : string -> string array
  (** return the disks in a Windows dynamic disk group

    @since 1.20.0
   *)
  method ldmtool_diskgroup_name : string -> string
  (** return the name of a Windows dynamic disk group

    @since 1.20.0
   *)
  method ldmtool_diskgroup_volumes : string -> string array
  (** return the volumes in a Windows dynamic disk group

    @since 1.20.0
   *)
  method ldmtool_remove_all : unit -> unit
  (** remove all Windows dynamic disk volumes

    @since 1.20.0
   *)
  method ldmtool_scan : unit -> string array
  (** scan for Windows dynamic disks

    @since 1.20.0
   *)
  method ldmtool_scan_devices : string array -> string array
  (** scan for Windows dynamic disks

    @since 1.20.0
   *)
  method ldmtool_volume_hint : string -> string -> string
  (** return the hint field of a Windows dynamic disk volume

    @since 1.20.0
   *)
  method ldmtool_volume_partitions : string -> string -> string array
  (** return the partitions in a Windows dynamic disk volume

    @since 1.20.0
   *)
  method ldmtool_volume_type : string -> string -> string
  (** return the type of a Windows dynamic disk volume

    @since 1.20.0
   *)
  method lgetxattr : string -> string -> string
  (** get a single extended attribute

    @since 1.7.24
   *)
  method lgetxattrs : string -> xattr array
  (** list extended attributes of a file or directory

    @since 1.0.59
   *)
  method list_9p : unit -> string array
  (** list 9p filesystems

    @since 1.11.12
   *)
  method list_devices : unit -> string array
  (** list the block devices

    @since 0.4
   *)
  method list_disk_labels : unit -> (string * string) list
  (** mapping of disk labels to devices

    @since 1.19.49
   *)
  method list_dm_devices : unit -> string array
  (** list device mapper devices

    @since 1.11.15
   *)
  method list_filesystems : unit -> (string * string) list
  (** list filesystems

    @since 1.5.15
   *)
  method list_ldm_partitions : unit -> string array
  (** list all Windows dynamic disk partitions

    @since 1.20.0
   *)
  method list_ldm_volumes : unit -> string array
  (** list all Windows dynamic disk volumes

    @since 1.20.0
   *)
  method list_md_devices : unit -> string array
  (** list Linux md (RAID) devices

    @since 1.15.4
   *)
  method list_partitions : unit -> string array
  (** list the partitions

    @since 0.4
   *)
  method ll : string -> string
  (** list the files in a directory (long format)

    @since 0.4
   *)
  method llz : string -> string
  (** list the files in a directory (long format with SELinux contexts)

    @since 1.17.6
   *)
  method ln : string -> string -> unit
  (** create a hard link

    @since 1.0.66
   *)
  method ln_f : string -> string -> unit
  (** create a hard link

    @since 1.0.66
   *)
  method ln_s : string -> string -> unit
  (** create a symbolic link

    @since 1.0.66
   *)
  method ln_sf : string -> string -> unit
  (** create a symbolic link

    @since 1.0.66
   *)
  method lremovexattr : string -> string -> unit
  (** remove extended attribute of a file or directory

    @since 1.0.59
   *)
  method ls : string -> string array
  (** list the files in a directory

    @since 0.4
   *)
  method ls0 : string -> string -> unit
  (** get list of files in a directory

    @since 1.19.32
   *)
  method lsetxattr : string -> string -> int -> string -> unit
  (** set extended attribute of a file or directory

    @since 1.0.59
   *)
  method lstat : string -> stat
  (** get file information for a symbolic link

    @deprecated Use {!lstatns} instead

    @since 1.9.2
   *)
  method lstatlist : string -> string array -> stat array
  (** lstat on multiple files

    @deprecated Use {!lstatnslist} instead

    @since 1.0.77
   *)
  method lstatns : string -> statns
  (** get file information for a symbolic link

    @since 1.27.53
   *)
  method lstatnslist : string -> string array -> statns array
  (** lstat on multiple files

    @since 1.27.53
   *)
  method luks_add_key : string -> string -> string -> int -> unit
  (** add a key on a LUKS encrypted device

    @since 1.5.2
   *)
  method luks_close : string -> unit
  (** close a LUKS device

    @since 1.5.1
   *)
  method luks_format : string -> string -> int -> unit
  (** format a block device as a LUKS encrypted device

    @since 1.5.2
   *)
  method luks_format_cipher : string -> string -> int -> string -> unit
  (** format a block device as a LUKS encrypted device

    @since 1.5.2
   *)
  method luks_kill_slot : string -> string -> int -> unit
  (** remove a key from a LUKS encrypted device

    @since 1.5.2
   *)
  method luks_open : string -> string -> string -> unit
  (** open a LUKS-encrypted block device

    @since 1.5.1
   *)
  method luks_open_ro : string -> string -> string -> unit
  (** open a LUKS-encrypted block device read-only

    @since 1.5.1
   *)
  method lvcreate : string -> string -> int -> unit
  (** create an LVM logical volume

    @since 0.8
   *)
  method lvcreate_free : string -> string -> int -> unit
  (** create an LVM logical volume in % remaining free space

    @since 1.17.18
   *)
  method lvm_canonical_lv_name : string -> string
  (** get canonical name of an LV

    @since 1.5.24
   *)
  method lvm_clear_filter : unit -> unit
  (** clear LVM device filter

    @since 1.5.1
   *)
  method lvm_remove_all : unit -> unit
  (** remove all LVM LVs, VGs and PVs

    @since 0.8
   *)
  method lvm_set_filter : string array -> unit
  (** set LVM device filter

    @since 1.5.1
   *)
  method lvremove : string -> unit
  (** remove an LVM logical volume

    @since 1.0.13
   *)
  method lvrename : string -> string -> unit
  (** rename an LVM logical volume

    @since 1.0.83
   *)
  method lvresize : string -> int -> unit
  (** resize an LVM logical volume

    @since 1.0.27
   *)
  method lvresize_free : string -> int -> unit
  (** expand an LV to fill free space

    @since 1.3.3
   *)
  method lvs : unit -> string array
  (** list the LVM logical volumes (LVs)

    @since 0.4
   *)
  method lvs_full : unit -> lvm_lv array
  (** list the LVM logical volumes (LVs)

    @since 0.4
   *)
  method lvuuid : string -> string
  (** get the UUID of a logical volume

    @since 1.0.87
   *)
  method lxattrlist : string -> string array -> xattr array
  (** lgetxattr on multiple files

    @since 1.0.77
   *)
  method max_disks : unit -> int
  (** maximum number of disks that may be added

    @since 1.19.7
   *)
  method md_create : ?missingbitmap:int64 -> ?nrdevices:int -> ?spare:int -> ?chunk:int64 -> ?level:string -> string -> string array -> unit
  (** create a Linux md (RAID) device

    @since 1.15.6
   *)
  method md_detail : string -> (string * string) list
  (** obtain metadata for an MD device

    @since 1.15.6
   *)
  method md_stat : string -> mdstat array
  (** get underlying devices from an MD device

    @since 1.17.21
   *)
  method md_stop : string -> unit
  (** stop a Linux md (RAID) device

    @since 1.15.6
   *)
  method mkdir : string -> unit
  (** create a directory

    @since 0.8
   *)
  method mkdir_mode : string -> int -> unit
  (** create a directory with a particular mode

    @since 1.0.77
   *)
  method mkdir_p : string -> unit
  (** create a directory and parents

    @since 0.8
   *)
  method mkdtemp : string -> string
  (** create a temporary directory

    @since 1.0.54
   *)
  method mke2fs : ?blockscount:int64 -> ?blocksize:int64 -> ?fragsize:int64 -> ?blockspergroup:int64 -> ?numberofgroups:int64 -> ?bytesperinode:int64 -> ?inodesize:int64 -> ?journalsize:int64 -> ?numberofinodes:int64 -> ?stridesize:int64 -> ?stripewidth:int64 -> ?maxonlineresize:int64 -> ?reservedblockspercentage:int -> ?mmpupdateinterval:int -> ?journaldevice:string -> ?label:string -> ?lastmounteddir:string -> ?creatoros:string -> ?fstype:string -> ?usagetype:string -> ?uuid:string -> ?forcecreate:bool -> ?writesbandgrouponly:bool -> ?lazyitableinit:bool -> ?lazyjournalinit:bool -> ?testfs:bool -> ?discard:bool -> ?quotatype:bool -> ?extent:bool -> ?filetype:bool -> ?flexbg:bool -> ?hasjournal:bool -> ?journaldev:bool -> ?largefile:bool -> ?quota:bool -> ?resizeinode:bool -> ?sparsesuper:bool -> ?uninitbg:bool -> string -> unit
  (** create an ext2/ext3/ext4 filesystem on device

    @since 1.19.44
   *)
  method mke2fs_J : string -> int -> string -> string -> unit
  (** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mke2fs_JL : string -> int -> string -> string -> unit
  (** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mke2fs_JU : string -> int -> string -> string -> unit
  (** make ext2/3/4 filesystem with external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mke2journal : int -> string -> unit
  (** make ext2/3/4 external journal

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mke2journal_L : int -> string -> string -> unit
  (** make ext2/3/4 external journal with label

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mke2journal_U : int -> string -> string -> unit
  (** make ext2/3/4 external journal with UUID

    @deprecated Use {!mke2fs} instead

    @since 1.0.68
   *)
  method mkfifo : int -> string -> unit
  (** make FIFO (named pipe)

    @since 1.0.55
   *)
  method mkfs : ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> ?label:string -> string -> string -> unit
  (** make a filesystem

    @since 0.8
   *)
  method mkfs_opts : ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> ?label:string -> string -> string -> unit
  (** alias for {!mkfs}

    @since 0.8
   *)
  method mkfs_b : string -> int -> string -> unit
  (** make a filesystem with block size

    @deprecated Use {!mkfs} instead

    @since 1.0.68
   *)
  method mkfs_btrfs : ?allocstart:int64 -> ?bytecount:int64 -> ?datatype:string -> ?leafsize:int -> ?label:string -> ?metadata:string -> ?nodesize:int -> ?sectorsize:int -> string array -> unit
  (** create a btrfs filesystem

    @since 1.17.25
   *)
  method mklost_and_found : string -> unit
  (** make lost+found directory on an ext2/3/4 filesystem

    @since 1.19.56
   *)
  method mkmountpoint : string -> unit
  (** create a mountpoint

    @since 1.0.62
   *)
  method mknod : int -> int -> int -> string -> unit
  (** make block, character or FIFO devices

    @since 1.0.55
   *)
  method mknod_b : int -> int -> int -> string -> unit
  (** make block device node

    @since 1.0.55
   *)
  method mknod_c : int -> int -> int -> string -> unit
  (** make char device node

    @since 1.0.55
   *)
  method mkswap : ?label:string -> ?uuid:string -> string -> unit
  (** create a swap partition

    @since 1.0.55
   *)
  method mkswap_opts : ?label:string -> ?uuid:string -> string -> unit
  (** alias for {!mkswap}

    @since 1.0.55
   *)
  method mkswap_L : string -> string -> unit
  (** create a swap partition with a label

    @deprecated Use {!mkswap} instead

    @since 1.0.55
   *)
  method mkswap_U : string -> string -> unit
  (** create a swap partition with an explicit UUID

    @deprecated Use {!mkswap} instead

    @since 1.0.55
   *)
  method mkswap_file : string -> unit
  (** create a swap file

    @since 1.0.66
   *)
  method mktemp : ?suffix:string -> string -> string
  (** create a temporary file

    @since 1.19.53
   *)
  method modprobe : string -> unit
  (** load a kernel module

    @since 1.0.68
   *)
  method mount : string -> string -> unit
  (** mount a guest disk at a position in the filesystem

    @since 0.3
   *)
  method mount_9p : ?options:string -> string -> string -> unit
  (** mount 9p filesystem

    @since 1.11.12
   *)
  method mount_local : ?readonly:bool -> ?options:string -> ?cachetimeout:int -> ?debugcalls:bool -> string -> unit
  (** mount on the local filesystem

    @since 1.17.22
   *)
  method mount_local_run : unit -> unit
  (** run main loop of mount on the local filesystem

    @since 1.17.22
   *)
  method mount_loop : string -> string -> unit
  (** mount a file using the loop device

    @since 1.0.54
   *)
  method mount_options : string -> string -> string -> unit
  (** mount a guest disk with mount options

    @since 1.0.10
   *)
  method mount_ro : string -> string -> unit
  (** mount a guest disk, read-only

    @since 1.0.10
   *)
  method mount_vfs : string -> string -> string -> string -> unit
  (** mount a guest disk with mount options and vfstype

    @since 1.0.10
   *)
  method mountpoints : unit -> (string * string) list
  (** show mountpoints

    @since 1.0.62
   *)
  method mounts : unit -> string array
  (** show mounted filesystems

    @since 0.8
   *)
  method mv : string -> string -> unit
  (** move a file

    @since 1.0.18
   *)
  method nr_devices : unit -> int
  (** return number of whole block devices (disks) added

    @since 1.19.15
   *)
  method ntfs_3g_probe : bool -> string -> int
  (** probe NTFS volume

    @since 1.0.43
   *)
  method ntfsclone_in : string -> string -> unit
  (** restore NTFS from backup file

    @since 1.17.9
   *)
  method ntfsclone_out : ?metadataonly:bool -> ?rescue:bool -> ?ignorefscheck:bool -> ?preservetimestamps:bool -> ?force:bool -> string -> string -> unit
  (** save NTFS to backup file

    @since 1.17.9
   *)
  method ntfsfix : ?clearbadsectors:bool -> string -> unit
  (** fix common errors and force Windows to check NTFS

    @since 1.17.9
   *)
  method ntfsresize : ?size:int64 -> ?force:bool -> string -> unit
  (** resize an NTFS filesystem

    @since 1.3.2
   *)
  method ntfsresize_opts : ?size:int64 -> ?force:bool -> string -> unit
  (** alias for {!ntfsresize}

    @since 1.3.2
   *)
  method ntfsresize_size : string -> int64 -> unit
  (** resize an NTFS filesystem (with size)

    @deprecated Use {!ntfsresize} instead

    @since 1.3.14
   *)
  method parse_environment : unit -> unit
  (** parse the environment and set handle flags accordingly

    @since 1.19.53
   *)
  method parse_environment_list : string array -> unit
  (** parse the environment and set handle flags accordingly

    @since 1.19.53
   *)
  method part_add : string -> string -> int64 -> int64 -> unit
  (** add a partition to the device

    @since 1.0.78
   *)
  method part_del : string -> int -> unit
  (** delete a partition

    @since 1.3.2
   *)
  method part_disk : string -> string -> unit
  (** partition whole disk with a single primary partition

    @since 1.0.78
   *)
  method part_get_bootable : string -> int -> bool
  (** return true if a partition is bootable

    @since 1.3.2
   *)
  method part_get_gpt_guid : string -> int -> string
  (** get the GUID of a GPT partition

    @since 1.29.25
   *)
  method part_get_gpt_type : string -> int -> string
  (** get the type GUID of a GPT partition

    @since 1.21.1
   *)
  method part_get_mbr_id : string -> int -> int
  (** get the MBR type byte (ID byte) from a partition

    @since 1.3.2
   *)
  method part_get_mbr_part_type : string -> int -> string
  (** get the MBR partition type

    @since 1.29.32
   *)
  method part_get_name : string -> int -> string
  (** get partition name

    @since 1.25.33
   *)
  method part_get_parttype : string -> string
  (** get the partition table type

    @since 1.0.78
   *)
  method part_init : string -> string -> unit
  (** create an empty partition table

    @since 1.0.78
   *)
  method part_list : string -> partition array
  (** list partitions on a device

    @since 1.0.78
   *)
  method part_set_bootable : string -> int -> bool -> unit
  (** make a partition bootable

    @since 1.0.78
   *)
  method part_set_gpt_guid : string -> int -> string -> unit
  (** set the GUID of a GPT partition

    @since 1.29.25
   *)
  method part_set_gpt_type : string -> int -> string -> unit
  (** set the type GUID of a GPT partition

    @since 1.21.1
   *)
  method part_set_mbr_id : string -> int -> int -> unit
  (** set the MBR type byte (ID byte) of a partition

    @since 1.3.2
   *)
  method part_set_name : string -> int -> string -> unit
  (** set partition name

    @since 1.0.78
   *)
  method part_to_dev : string -> string
  (** convert partition name to device name

    @since 1.5.15
   *)
  method part_to_partnum : string -> int
  (** convert partition name to partition number

    @since 1.13.25
   *)
  method ping_daemon : unit -> unit
  (** ping the guest daemon

    @since 1.0.18
   *)
  method pread : string -> int -> int64 -> string
  (** read part of a file

    @since 1.0.77
   *)
  method pread_device : string -> int -> int64 -> string
  (** read part of a device

    @since 1.5.21
   *)
  method pvchange_uuid : string -> unit
  (** generate a new random UUID for a physical volume

    @since 1.19.26
   *)
  method pvchange_uuid_all : unit -> unit
  (** generate new random UUIDs for all physical volumes

    @since 1.19.26
   *)
  method pvcreate : string -> unit
  (** create an LVM physical volume

    @since 0.8
   *)
  method pvremove : string -> unit
  (** remove an LVM physical volume

    @since 1.0.13
   *)
  method pvresize : string -> unit
  (** resize an LVM physical volume

    @since 1.0.26
   *)
  method pvresize_size : string -> int64 -> unit
  (** resize an LVM physical volume (with size)

    @since 1.3.14
   *)
  method pvs : unit -> string array
  (** list the LVM physical volumes (PVs)

    @since 0.4
   *)
  method pvs_full : unit -> lvm_pv array
  (** list the LVM physical volumes (PVs)

    @since 0.4
   *)
  method pvuuid : string -> string
  (** get the UUID of a physical volume

    @since 1.0.87
   *)
  method pwrite : string -> string -> int64 -> int
  (** write to part of a file

    @since 1.3.14
   *)
  method pwrite_device : string -> string -> int64 -> int
  (** write to part of a device

    @since 1.5.20
   *)
  method read_file : string -> string
  (** read a file

    @since 1.0.63
   *)
  method read_lines : string -> string array
  (** read file as lines

    @since 0.7
   *)
  method readdir : string -> dirent array
  (** read directories entries

    @since 1.0.55
   *)
  method readlink : string -> string
  (** read the target of a symbolic link

    @since 1.0.66
   *)
  method readlinklist : string -> string array -> string array
  (** readlink on multiple files

    @since 1.0.77
   *)
  method realpath : string -> string
  (** canonicalized absolute pathname

    @since 1.0.66
   *)
  method remount : ?rw:bool -> string -> unit
  (** remount a filesystem with different options

    @since 1.23.2
   *)
  method remove_drive : string -> unit
  (** remove a disk image

    @since 1.19.49
   *)
  method removexattr : string -> string -> unit
  (** remove extended attribute of a file or directory

    @since 1.0.59
   *)
  method rename : string -> string -> unit
  (** rename a file on the same filesystem

    @since 1.21.5
   *)
  method resize2fs : string -> unit
  (** resize an ext2, ext3 or ext4 filesystem

    @since 1.0.27
   *)
  method resize2fs_M : string -> unit
  (** resize an ext2, ext3 or ext4 filesystem to the minimum size

    @since 1.9.4
   *)
  method resize2fs_size : string -> int64 -> unit
  (** resize an ext2, ext3 or ext4 filesystem (with size)

    @since 1.3.14
   *)
  method rm : string -> unit
  (** remove a file

    @since 0.8
   *)
  method rm_f : string -> unit
  (** remove a file ignoring errors

    @since 1.19.42
   *)
  method rm_rf : string -> unit
  (** remove a file or directory recursively

    @since 0.8
   *)
  method rmdir : string -> unit
  (** remove a directory

    @since 0.8
   *)
  method rmmountpoint : string -> unit
  (** remove a mountpoint

    @since 1.0.62
   *)
  method rsync : ?archive:bool -> ?deletedest:bool -> string -> string -> unit
  (** synchronize the contents of two directories

    @since 1.19.29
   *)
  method rsync_in : ?archive:bool -> ?deletedest:bool -> string -> string -> unit
  (** synchronize host or remote filesystem with filesystem

    @since 1.19.29
   *)
  method rsync_out : ?archive:bool -> ?deletedest:bool -> string -> string -> unit
  (** synchronize filesystem with host or remote filesystem

    @since 1.19.29
   *)
  method scrub_device : string -> unit
  (** scrub (securely wipe) a device

    @since 1.0.52
   *)
  method scrub_file : string -> unit
  (** scrub (securely wipe) a file

    @since 1.0.52
   *)
  method scrub_freespace : string -> unit
  (** scrub (securely wipe) free space

    @since 1.0.52
   *)
  method set_append : string option -> unit
  (** add options to kernel command line

    @since 1.0.26
   *)
  method set_attach_method : string -> unit
  (** set the backend

    @deprecated Use {!set_backend} instead

    @since 1.9.8
   *)
  method set_autosync : bool -> unit
  (** set autosync mode

    @since 0.3
   *)
  method set_backend : string -> unit
  (** set the backend

    @since 1.21.26
   *)
  method set_backend_setting : string -> string -> unit
  (** set a single per-backend settings string

    @since 1.27.2
   *)
  method set_backend_settings : string array -> unit
  (** replace per-backend settings strings

    @since 1.25.24
   *)
  method set_cachedir : string option -> unit
  (** set the appliance cache directory

    @since 1.19.58
   *)
  method set_direct : bool -> unit
  (** enable or disable direct appliance mode

    @since 1.0.72
   *)
  method set_e2attrs : ?clear:bool -> string -> string -> unit
  (** set ext2 file attributes of a file

    @since 1.17.31
   *)
  method set_e2generation : string -> int64 -> unit
  (** set ext2 file generation of a file

    @since 1.17.31
   *)
  method set_e2label : string -> string -> unit
  (** set the ext2/3/4 filesystem label

    @deprecated Use {!set_label} instead

    @since 1.0.15
   *)
  method set_e2uuid : string -> string -> unit
  (** set the ext2/3/4 filesystem UUID

    @deprecated Use {!set_uuid} instead

    @since 1.0.15
   *)
  method set_hv : string -> unit
  (** set the hypervisor binary

    @since 1.23.17
   *)
  method set_identifier : string -> unit
  (** set the handle identifier

    @since 1.31.14
   *)
  method set_label : string -> string -> unit
  (** set filesystem label

    @since 1.17.9
   *)
  method set_libvirt_requested_credential : int -> string -> unit
  (** pass requested credential back to libvirt

    @since 1.19.52
   *)
  method set_libvirt_supported_credentials : string array -> unit
  (** set libvirt credentials supported by calling program

    @since 1.19.52
   *)
  method set_memsize : int -> unit
  (** set memory allocated to the hypervisor

    @since 1.0.55
   *)
  method set_network : bool -> unit
  (** set enable network flag

    @since 1.5.4
   *)
  method set_path : string option -> unit
  (** set the search path

    @since 0.3
   *)
  method set_pgroup : bool -> unit
  (** set process group flag

    @since 1.11.18
   *)
  method set_program : string -> unit
  (** set the program name

    @since 1.21.29
   *)
  method set_qemu : string option -> unit
  (** set the hypervisor binary (usually qemu)

    @deprecated Use {!set_hv} instead

    @since 1.0.6
   *)
  method set_recovery_proc : bool -> unit
  (** enable or disable the recovery process

    @since 1.0.77
   *)
  method set_selinux : bool -> unit
  (** set SELinux enabled or disabled at appliance boot

    @since 1.0.67
   *)
  method set_smp : int -> unit
  (** set number of virtual CPUs in appliance

    @since 1.13.15
   *)
  method set_tmpdir : string option -> unit
  (** set the temporary directory

    @since 1.19.58
   *)
  method set_trace : bool -> unit
  (** enable or disable command traces

    @since 1.0.69
   *)
  method set_uuid : string -> string -> unit
  (** set the filesystem UUID

    @since 1.23.10
   *)
  method set_uuid_random : string -> unit
  (** set a random UUID for the filesystem

    @since 1.29.50
   *)
  method set_verbose : bool -> unit
  (** set verbose mode

    @since 0.3
   *)
  method setcon : string -> unit
  (** set SELinux security context

    @since 1.0.67
   *)
  method setxattr : string -> string -> int -> string -> unit
  (** set extended attribute of a file or directory

    @since 1.0.59
   *)
  method sfdisk : string -> int -> int -> int -> string array -> unit
  (** create partitions on a block device

    @deprecated Use {!part_add} instead

    @since 0.8
   *)
  method sfdiskM : string -> string array -> unit
  (** create partitions on a block device

    @deprecated Use {!part_add} instead

    @since 1.0.55
   *)
  method sfdisk_N : string -> int -> int -> int -> int -> string -> unit
  (** modify a single partition on a block device

    @deprecated Use {!part_add} instead

    @since 1.0.26
   *)
  method sfdisk_disk_geometry : string -> string
  (** display the disk geometry from the partition table

    @since 1.0.26
   *)
  method sfdisk_kernel_geometry : string -> string
  (** display the kernel geometry

    @since 1.0.26
   *)
  method sfdisk_l : string -> string
  (** display the partition table

    @deprecated Use {!part_list} instead

    @since 1.0.26
   *)
  method sh : string -> string
  (** run a command via the shell

    @since 1.0.50
   *)
  method sh_lines : string -> string array
  (** run a command via the shell returning lines

    @since 1.0.50
   *)
  method shutdown : unit -> unit
  (** shutdown the hypervisor

    @since 1.19.16
   *)
  method sleep : int -> unit
  (** sleep for some seconds

    @since 1.0.41
   *)
  method stat : string -> stat
  (** get file information

    @deprecated Use {!statns} instead

    @since 1.9.2
   *)
  method statns : string -> statns
  (** get file information

    @since 1.27.53
   *)
  method statvfs : string -> statvfs
  (** get file system statistics

    @since 1.9.2
   *)
  method strings : string -> string array
  (** print the printable strings in a file

    @since 1.0.22
   *)
  method strings_e : string -> string -> string array
  (** print the printable strings in a file

    @since 1.0.22
   *)
  method swapoff_device : string -> unit
  (** disable swap on device

    @since 1.0.66
   *)
  method swapoff_file : string -> unit
  (** disable swap on file

    @since 1.0.66
   *)
  method swapoff_label : string -> unit
  (** disable swap on labeled swap partition

    @since 1.0.66
   *)
  method swapoff_uuid : string -> unit
  (** disable swap on swap partition by UUID

    @since 1.0.66
   *)
  method swapon_device : string -> unit
  (** enable swap on device

    @since 1.0.66
   *)
  method swapon_file : string -> unit
  (** enable swap on file

    @since 1.0.66
   *)
  method swapon_label : string -> unit
  (** enable swap on labeled swap partition

    @since 1.0.66
   *)
  method swapon_uuid : string -> unit
  (** enable swap on swap partition by UUID

    @since 1.0.66
   *)
  method sync : unit -> unit
  (** sync disks, writes are flushed through to the disk image

    @since 0.3
   *)
  method syslinux : ?directory:string -> string -> unit
  (** install the SYSLINUX bootloader

    @since 1.21.27
   *)
  method tail : string -> string array
  (** return last 10 lines of a file

    @since 1.0.54
   *)
  method tail_n : int -> string -> string array
  (** return last N lines of a file

    @since 1.0.54
   *)
  method tar_in : ?compress:string -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
  (** unpack tarfile to directory

    @since 1.0.3
   *)
  method tar_in_opts : ?compress:string -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
  (** alias for {!tar_in}

    @since 1.0.3
   *)
  method tar_out : ?compress:string -> ?numericowner:bool -> ?excludes:string array -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
  (** pack directory into tarfile

    @since 1.0.3
   *)
  method tar_out_opts : ?compress:string -> ?numericowner:bool -> ?excludes:string array -> ?xattrs:bool -> ?selinux:bool -> ?acls:bool -> string -> string -> unit
  (** alias for {!tar_out}

    @since 1.0.3
   *)
  method tgz_in : string -> string -> unit
  (** unpack compressed tarball to directory

    @deprecated Use {!tar_in} instead

    @since 1.0.3
   *)
  method tgz_out : string -> string -> unit
  (** pack directory into compressed tarball

    @deprecated Use {!tar_out} instead

    @since 1.0.3
   *)
  method touch : string -> unit
  (** update file timestamps or create a new file

    @since 0.3
   *)
  method truncate : string -> unit
  (** truncate a file to zero size

    @since 1.0.77
   *)
  method truncate_size : string -> int64 -> unit
  (** truncate a file to a particular size

    @since 1.0.77
   *)
  method tune2fs : ?force:bool -> ?maxmountcount:int -> ?mountcount:int -> ?errorbehavior:string -> ?group:int64 -> ?intervalbetweenchecks:int -> ?reservedblockspercentage:int -> ?lastmounteddirectory:string -> ?reservedblockscount:int64 -> ?user:int64 -> string -> unit
  (** adjust ext2/ext3/ext4 filesystem parameters

    @since 1.15.4
   *)
  method tune2fs_l : string -> (string * string) list
  (** get ext2/ext3/ext4 superblock details

    @since 1.9.2
   *)
  method txz_in : string -> string -> unit
  (** unpack compressed tarball to directory

    @deprecated Use {!tar_in} instead

    @since 1.3.2
   *)
  method txz_out : string -> string -> unit
  (** pack directory into compressed tarball

    @deprecated Use {!tar_out} instead

    @since 1.3.2
   *)
  method umask : int -> int
  (** set file mode creation mask (umask)

    @since 1.0.55
   *)
  method umount : ?force:bool -> ?lazyunmount:bool -> string -> unit
  (** unmount a filesystem

    @since 0.8
   *)
  method umount_opts : ?force:bool -> ?lazyunmount:bool -> string -> unit
  (** alias for {!umount}

    @since 0.8
   *)
  method umount_all : unit -> unit
  (** unmount all filesystems

    @since 0.8
   *)
  method umount_local : ?retry:bool -> unit -> unit
  (** unmount a locally mounted filesystem

    @since 1.17.22
   *)
  method upload : string -> string -> unit
  (** upload a file from the local machine

    @since 1.0.2
   *)
  method upload_offset : string -> string -> int64 -> unit
  (** upload a file from the local machine with offset

    @since 1.5.17
   *)
  method user_cancel : unit -> unit
  (** cancel the current upload or download operation

    @since 1.11.18
   *)
  method utimens : string -> int64 -> int64 -> int64 -> int64 -> unit
  (** set timestamp of a file with nanosecond precision

    @since 1.0.77
   *)
  method utsname : unit -> utsname
  (** appliance kernel version

    @since 1.19.27
   *)
  method version : unit -> version
  (** get the library version number

    @since 1.0.58
   *)
  method vfs_label : string -> string
  (** get the filesystem label

    @since 1.3.18
   *)
  method vfs_minimum_size : string -> int64
  (** get minimum filesystem size

    @since 1.31.18
   *)
  method vfs_type : string -> string
  (** get the Linux VFS type corresponding to a mounted device

    @since 1.0.75
   *)
  method vfs_uuid : string -> string
  (** get the filesystem UUID

    @since 1.3.18
   *)
  method vg_activate : bool -> string array -> unit
  (** activate or deactivate some volume groups

    @since 1.0.26
   *)
  method vg_activate_all : bool -> unit
  (** activate or deactivate all volume groups

    @since 1.0.26
   *)
  method vgchange_uuid : string -> unit
  (** generate a new random UUID for a volume group

    @since 1.19.26
   *)
  method vgchange_uuid_all : unit -> unit
  (** generate new random UUIDs for all volume groups

    @since 1.19.26
   *)
  method vgcreate : string -> string array -> unit
  (** create an LVM volume group

    @since 0.8
   *)
  method vglvuuids : string -> string array
  (** get the LV UUIDs of all LVs in the volume group

    @since 1.0.87
   *)
  method vgmeta : string -> string
  (** get volume group metadata

    @since 1.17.20
   *)
  method vgpvuuids : string -> string array
  (** get the PV UUIDs containing the volume group

    @since 1.0.87
   *)
  method vgremove : string -> unit
  (** remove an LVM volume group

    @since 1.0.13
   *)
  method vgrename : string -> string -> unit
  (** rename an LVM volume group

    @since 1.0.83
   *)
  method vgs : unit -> string array
  (** list the LVM volume groups (VGs)

    @since 0.4
   *)
  method vgs_full : unit -> lvm_vg array
  (** list the LVM volume groups (VGs)

    @since 0.4
   *)
  method vgscan : unit -> unit
  (** rescan for LVM physical volumes, volume groups and logical volumes

    @since 1.3.2
   *)
  method vguuid : string -> string
  (** get the UUID of a volume group

    @since 1.0.87
   *)
  method wait_ready : unit -> unit
  (** wait until the hypervisor launches (no op)

    @deprecated Use {!launch} instead

    @since 0.3
   *)
  method wc_c : string -> int
  (** count characters in a file

    @since 1.0.54
   *)
  method wc_l : string -> int
  (** count lines in a file

    @since 1.0.54
   *)
  method wc_w : string -> int
  (** count words in a file

    @since 1.0.54
   *)
  method wipefs : string -> unit
  (** wipe a filesystem signature from a device

    @since 1.17.6
   *)
  method write : string -> string -> unit
  (** create a new file

    @since 1.3.14
   *)
  method write_append : string -> string -> unit
  (** append content to end of file

    @since 1.11.18
   *)
  method write_file : string -> string -> int -> unit
  (** create a file

    @deprecated Use {!write} instead

    @since 0.8
   *)
  method xfs_admin : ?extunwritten:bool -> ?imgfile:bool -> ?v2log:bool -> ?projid32bit:bool -> ?lazycounter:bool -> ?label:string -> ?uuid:string -> string -> unit
  (** change parameters of an XFS filesystem

    @since 1.19.33
   *)
  method xfs_growfs : ?datasec:bool -> ?logsec:bool -> ?rtsec:bool -> ?datasize:int64 -> ?logsize:int64 -> ?rtsize:int64 -> ?rtextsize:int64 -> ?maxpct:int -> string -> unit
  (** expand an existing XFS filesystem

    @since 1.19.28
   *)
  method xfs_info : string -> xfsinfo
  (** get geometry of XFS filesystem

    @since 1.19.21
   *)
  method xfs_repair : ?forcelogzero:bool -> ?nomodify:bool -> ?noprefetch:bool -> ?forcegeometry:bool -> ?maxmem:int64 -> ?ihashsize:int64 -> ?bhashsize:int64 -> ?agstride:int64 -> ?logdev:string -> ?rtdev:string -> string -> int
  (** repair an XFS filesystem

    @since 1.19.36
   *)
  method zegrep : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method zegrepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method zero : string -> unit
  (** write zeroes to the device

    @since 1.0.16
   *)
  method zero_device : string -> unit
  (** write zeroes to an entire device

    @since 1.3.1
   *)
  method zero_free_space : string -> unit
  (** zero free space in a filesystem

    @since 1.17.18
   *)
  method zerofree : string -> unit
  (** zero unused inodes and disk blocks on ext2/3 filesystem

    @since 1.0.26
   *)
  method zfgrep : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method zfgrepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method zfile : string -> string -> string
  (** determine file type inside a compressed file

    @deprecated Use {!file} instead

    @since 1.0.59
   *)
  method zgrep : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
  method zgrepi : string -> string -> string array
  (** return lines matching a pattern

    @deprecated Use {!grep} instead

    @since 1.0.66
   *)
end
