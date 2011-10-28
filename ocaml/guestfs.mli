(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2011 Red Hat Inc.
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

type t
(** A [guestfs_h] handle. *)

exception Error of string
(** This exception is raised when there is an error. *)

exception Handle_closed of string
(** This exception is raised if you use a {!t} handle
    after calling {!close} on it.  The string is the name of
    the function. *)

val create : unit -> t
(** Create a {!t} handle. *)

val close : t -> unit
(** Close the {!t} handle and free up all resources used
    by it immediately.

    Handles are closed by the garbage collector when they become
    unreferenced, but callers can call this in order to provide
    predictable cleanup. *)

type event =
  | EVENT_CLOSE
  | EVENT_SUBPROCESS_QUIT
  | EVENT_LAUNCH_DONE
  | EVENT_PROGRESS
  | EVENT_APPLIANCE
  | EVENT_LIBRARY
  | EVENT_TRACE
  | EVENT_ENTER

val event_all : event list
(** A list containing all event types. *)

type event_handle
(** The opaque event handle which can be used to delete event callbacks. *)

type event_callback =
  t -> event -> event_handle -> string -> int64 array -> unit
(** The event callback. *)

val set_event_callback : t -> event_callback -> event list -> event_handle
(** [set_event_callback g f es] sets [f] as the event callback function
    for all events in the set [es].

    Note that if the closure captures a reference to the handle,
    this reference will prevent the handle from being
    automatically closed by the garbage collector.  Since the
    handle is passed to the event callback, with careful programming
    it should be possible to avoid capturing the handle in the closure. *)

val delete_event_callback : t -> event_handle -> unit
(** [delete_event_callback g eh] removes a previously registered
    event callback.  See {!set_event_callback}. *)

val last_errno : t -> int
(** [last_errno g] returns the last errno that happened on the handle [g]
    (or [0] if there was no errno).  Note that the returned integer is the
    raw errno number, and it is {i not} related to the {!Unix.error} type.

    [last_errno] can be overwritten by subsequent operations on a handle,
    so if you want to capture the errno correctly, you must call this
    in the {!Error} exception handler, before any other operation on [g]. *)

val user_cancel : t -> unit
(** Cancel current transfer.  This is safe to call from OCaml signal
    handlers and threads. *)

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

val add_cdrom : t -> string -> unit
(** add a CD-ROM disk image to examine

    @deprecated Use {!add_drive_opts} instead
 *)

val add_domain : t -> ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> string -> int
(** add the disk(s) from a named libvirt domain *)

val add_drive : t -> string -> unit
(** add an image to examine or modify *)

val add_drive_opts : t -> ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> string -> unit
(** add an image to examine or modify *)

val add_drive_ro : t -> string -> unit
(** add a drive in snapshot mode (read-only) *)

val add_drive_ro_with_if : t -> string -> string -> unit
(** add a drive read-only specifying the QEMU block emulation to use

    @deprecated Use {!add_drive_opts} instead
 *)

val add_drive_with_if : t -> string -> string -> unit
(** add a drive specifying the QEMU block emulation to use

    @deprecated Use {!add_drive_opts} instead
 *)

val aug_clear : t -> string -> unit
(** clear Augeas path *)

val aug_close : t -> unit
(** close the current Augeas handle *)

val aug_defnode : t -> string -> string -> string -> int_bool
(** define an Augeas node *)

val aug_defvar : t -> string -> string option -> int
(** define an Augeas variable *)

val aug_get : t -> string -> string
(** look up the value of an Augeas path *)

val aug_init : t -> string -> int -> unit
(** create a new Augeas handle *)

val aug_insert : t -> string -> string -> bool -> unit
(** insert a sibling Augeas node *)

val aug_load : t -> unit
(** load files into the tree *)

val aug_ls : t -> string -> string array
(** list Augeas nodes under augpath *)

val aug_match : t -> string -> string array
(** return Augeas nodes which match augpath *)

val aug_mv : t -> string -> string -> unit
(** move Augeas node *)

val aug_rm : t -> string -> int
(** remove an Augeas path *)

val aug_save : t -> unit
(** write all pending Augeas changes to disk *)

val aug_set : t -> string -> string -> unit
(** set Augeas path to value *)

val available : t -> string array -> unit
(** test availability of some parts of the API *)

val available_all_groups : t -> string array
(** return a list of all optional groups *)

val base64_in : t -> string -> string -> unit
(** upload base64-encoded data to file *)

val base64_out : t -> string -> string -> unit
(** download file and encode as base64 *)

val blockdev_flushbufs : t -> string -> unit
(** flush device buffers *)

val blockdev_getbsz : t -> string -> int
(** get blocksize of block device *)

val blockdev_getro : t -> string -> bool
(** is block device set to read-only *)

val blockdev_getsize64 : t -> string -> int64
(** get total size of device in bytes *)

val blockdev_getss : t -> string -> int
(** get sectorsize of block device *)

val blockdev_getsz : t -> string -> int64
(** get total size of device in 512-byte sectors *)

val blockdev_rereadpt : t -> string -> unit
(** reread partition table *)

val blockdev_setbsz : t -> string -> int -> unit
(** set blocksize of block device *)

val blockdev_setro : t -> string -> unit
(** set block device to read-only *)

val blockdev_setrw : t -> string -> unit
(** set block device to read-write *)

val btrfs_filesystem_resize : t -> ?size:int64 -> string -> unit
(** resize a btrfs filesystem *)

val case_sensitive_path : t -> string -> string
(** return true path on case-insensitive filesystem *)

val cat : t -> string -> string
(** list the contents of a file *)

val checksum : t -> string -> string -> string
(** compute MD5, SHAx or CRC checksum of file *)

val checksum_device : t -> string -> string -> string
(** compute MD5, SHAx or CRC checksum of the contents of a device *)

val checksums_out : t -> string -> string -> string -> unit
(** compute MD5, SHAx or CRC checksum of files in a directory *)

val chmod : t -> int -> string -> unit
(** change file mode *)

val chown : t -> int -> int -> string -> unit
(** change file owner and group *)

val command : t -> string array -> string
(** run a command from the guest filesystem *)

val command_lines : t -> string array -> string array
(** run a command, returning lines *)

val compress_device_out : t -> ?level:int -> string -> string -> string -> unit
(** output compressed device *)

val compress_out : t -> ?level:int -> string -> string -> string -> unit
(** output compressed file *)

val config : t -> string -> string option -> unit
(** add qemu parameters *)

val copy_device_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
(** copy from source device to destination device *)

val copy_device_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
(** copy from source device to destination file *)

val copy_file_to_device : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
(** copy from source file to destination device *)

val copy_file_to_file : t -> ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
(** copy from source file to destination file *)

val copy_size : t -> string -> string -> int64 -> unit
(** copy size bytes from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead
 *)

val cp : t -> string -> string -> unit
(** copy a file *)

val cp_a : t -> string -> string -> unit
(** copy a file or directory recursively *)

val dd : t -> string -> string -> unit
(** copy from source to destination using dd

    @deprecated Use {!copy_device_to_device} instead
 *)

val debug : t -> string -> string array -> string

val debug_cmdline : t -> string array

val debug_drives : t -> string array

val debug_upload : t -> string -> string -> int -> unit

val df : t -> string
(** report file system disk space usage *)

val df_h : t -> string
(** report file system disk space usage (human readable) *)

val dmesg : t -> string
(** return kernel messages *)

val download : t -> string -> string -> unit
(** download a file to the local machine *)

val download_offset : t -> string -> string -> int64 -> int64 -> unit
(** download a file to the local machine with offset and size *)

val drop_caches : t -> int -> unit
(** drop kernel page cache, dentries and inodes *)

val du : t -> string -> int64
(** estimate file space usage *)

val e2fsck_f : t -> string -> unit
(** check an ext2/ext3 filesystem *)

val echo_daemon : t -> string array -> string
(** echo arguments back to the client *)

val egrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val egrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val equal : t -> string -> string -> bool
(** test if two files have equal contents *)

val exists : t -> string -> bool
(** test if file or directory exists *)

val fallocate : t -> string -> int -> unit
(** preallocate a file in the guest filesystem

    @deprecated Use {!fallocate64} instead
 *)

val fallocate64 : t -> string -> int64 -> unit
(** preallocate a file in the guest filesystem *)

val fgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val fgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val file : t -> string -> string
(** determine file type *)

val file_architecture : t -> string -> string
(** detect the architecture of a binary file *)

val filesize : t -> string -> int64
(** return the size of the file in bytes *)

val fill : t -> int -> int -> string -> unit
(** fill a file with octets *)

val fill_pattern : t -> string -> int -> string -> unit
(** fill a file with a repeating pattern of bytes *)

val find : t -> string -> string array
(** find all files and directories *)

val find0 : t -> string -> string -> unit
(** find all files and directories, returning NUL-separated list *)

val findfs_label : t -> string -> string
(** find a filesystem by label *)

val findfs_uuid : t -> string -> string
(** find a filesystem by UUID *)

val fsck : t -> string -> string -> int
(** run the filesystem checker *)

val get_append : t -> string option
(** get the additional kernel options *)

val get_attach_method : t -> string
(** get the attach method *)

val get_autosync : t -> bool
(** get autosync mode *)

val get_direct : t -> bool
(** get direct appliance mode flag *)

val get_e2label : t -> string -> string
(** get the ext2/3/4 filesystem label

    @deprecated Use {!vfs_label} instead
 *)

val get_e2uuid : t -> string -> string
(** get the ext2/3/4 filesystem UUID

    @deprecated Use {!vfs_uuid} instead
 *)

val get_memsize : t -> int
(** get memory allocated to the qemu subprocess *)

val get_network : t -> bool
(** get enable network flag *)

val get_path : t -> string
(** get the search path *)

val get_pgroup : t -> bool
(** get process group flag *)

val get_pid : t -> int
(** get PID of qemu subprocess *)

val get_qemu : t -> string
(** get the qemu binary *)

val get_recovery_proc : t -> bool
(** get recovery process enabled flag *)

val get_selinux : t -> bool
(** get SELinux enabled flag *)

val get_smp : t -> int
(** get number of virtual CPUs in appliance *)

val get_state : t -> int
(** get the current state *)

val get_trace : t -> bool
(** get command trace enabled flag *)

val get_umask : t -> int
(** get the current umask *)

val get_verbose : t -> bool
(** get verbose mode *)

val getcon : t -> string
(** get SELinux security context *)

val getxattr : t -> string -> string -> string
(** get a single extended attribute *)

val getxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory *)

val glob_expand : t -> string -> string array
(** expand a wildcard path *)

val grep : t -> string -> string -> string array
(** return lines matching a pattern *)

val grepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val grub_install : t -> string -> string -> unit
(** install GRUB 1 *)

val head : t -> string -> string array
(** return first 10 lines of a file *)

val head_n : t -> int -> string -> string array
(** return first N lines of a file *)

val hexdump : t -> string -> string
(** dump a file in hexadecimal *)

val initrd_cat : t -> string -> string -> string
(** list the contents of a single file in an initrd *)

val initrd_list : t -> string -> string array
(** list files in an initrd *)

val inotify_add_watch : t -> string -> int -> int64
(** add an inotify watch *)

val inotify_close : t -> unit
(** close the inotify handle *)

val inotify_files : t -> string array
(** return list of watched files that had events *)

val inotify_init : t -> int -> unit
(** create an inotify handle *)

val inotify_read : t -> inotify_event array
(** return list of inotify events *)

val inotify_rm_watch : t -> int -> unit
(** remove an inotify watch *)

val inspect_get_arch : t -> string -> string
(** get architecture of inspected operating system *)

val inspect_get_distro : t -> string -> string
(** get distro of inspected operating system *)

val inspect_get_drive_mappings : t -> string -> (string * string) list
(** get drive letter mappings *)

val inspect_get_filesystems : t -> string -> string array
(** get filesystems associated with inspected operating system *)

val inspect_get_format : t -> string -> string
(** get format of inspected operating system *)

val inspect_get_hostname : t -> string -> string
(** get hostname of the operating system *)

val inspect_get_icon : t -> ?favicon:bool -> ?highquality:bool -> string -> string
(** get the icon corresponding to this operating system *)

val inspect_get_major_version : t -> string -> int
(** get major version of inspected operating system *)

val inspect_get_minor_version : t -> string -> int
(** get minor version of inspected operating system *)

val inspect_get_mountpoints : t -> string -> (string * string) list
(** get mountpoints of inspected operating system *)

val inspect_get_package_format : t -> string -> string
(** get package format used by the operating system *)

val inspect_get_package_management : t -> string -> string
(** get package management tool used by the operating system *)

val inspect_get_product_name : t -> string -> string
(** get product name of inspected operating system *)

val inspect_get_product_variant : t -> string -> string
(** get product variant of inspected operating system *)

val inspect_get_roots : t -> string array
(** return list of operating systems found by last inspection *)

val inspect_get_type : t -> string -> string
(** get type of inspected operating system *)

val inspect_get_windows_current_control_set : t -> string -> string
(** get Windows CurrentControlSet of inspected operating system *)

val inspect_get_windows_systemroot : t -> string -> string
(** get Windows systemroot of inspected operating system *)

val inspect_is_live : t -> string -> bool
(** get live flag for install disk *)

val inspect_is_multipart : t -> string -> bool
(** get multipart flag for install disk *)

val inspect_is_netinst : t -> string -> bool
(** get netinst (network installer) flag for install disk *)

val inspect_list_applications : t -> string -> application array
(** get list of applications installed in the operating system *)

val inspect_os : t -> string array
(** inspect disk and return list of operating systems found *)

val internal_autosync : t -> unit

val is_blockdev : t -> string -> bool
(** test if block device *)

val is_busy : t -> bool
(** is busy processing a command *)

val is_chardev : t -> string -> bool
(** test if character device *)

val is_config : t -> bool
(** is in configuration state *)

val is_dir : t -> string -> bool
(** test if a directory *)

val is_fifo : t -> string -> bool
(** test if FIFO (named pipe) *)

val is_file : t -> string -> bool
(** test if a regular file *)

val is_launching : t -> bool
(** is launching subprocess *)

val is_lv : t -> string -> bool
(** test if device is a logical volume *)

val is_ready : t -> bool
(** is ready to accept commands *)

val is_socket : t -> string -> bool
(** test if socket *)

val is_symlink : t -> string -> bool
(** test if symbolic link *)

val is_zero : t -> string -> bool
(** test if a file contains all zero bytes *)

val is_zero_device : t -> string -> bool
(** test if a device contains all zero bytes *)

val kill_subprocess : t -> unit
(** kill the qemu subprocess *)

val launch : t -> unit
(** launch the qemu subprocess *)

val lchown : t -> int -> int -> string -> unit
(** change file owner and group *)

val lgetxattr : t -> string -> string -> string
(** get a single extended attribute *)

val lgetxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory *)

val list_9p : t -> string array
(** list 9p filesystems *)

val list_devices : t -> string array
(** list the block devices *)

val list_dm_devices : t -> string array
(** list device mapper devices *)

val list_filesystems : t -> (string * string) list
(** list filesystems *)

val list_partitions : t -> string array
(** list the partitions *)

val ll : t -> string -> string
(** list the files in a directory (long format) *)

val ln : t -> string -> string -> unit
(** create a hard link *)

val ln_f : t -> string -> string -> unit
(** create a hard link *)

val ln_s : t -> string -> string -> unit
(** create a symbolic link *)

val ln_sf : t -> string -> string -> unit
(** create a symbolic link *)

val lremovexattr : t -> string -> string -> unit
(** remove extended attribute of a file or directory *)

val ls : t -> string -> string array
(** list the files in a directory *)

val lsetxattr : t -> string -> string -> int -> string -> unit
(** set extended attribute of a file or directory *)

val lstat : t -> string -> stat
(** get file information for a symbolic link *)

val lstatlist : t -> string -> string array -> stat array
(** lstat on multiple files *)

val luks_add_key : t -> string -> string -> string -> int -> unit
(** add a key on a LUKS encrypted device *)

val luks_close : t -> string -> unit
(** close a LUKS device *)

val luks_format : t -> string -> string -> int -> unit
(** format a block device as a LUKS encrypted device *)

val luks_format_cipher : t -> string -> string -> int -> string -> unit
(** format a block device as a LUKS encrypted device *)

val luks_kill_slot : t -> string -> string -> int -> unit
(** remove a key from a LUKS encrypted device *)

val luks_open : t -> string -> string -> string -> unit
(** open a LUKS-encrypted block device *)

val luks_open_ro : t -> string -> string -> string -> unit
(** open a LUKS-encrypted block device read-only *)

val lvcreate : t -> string -> string -> int -> unit
(** create an LVM logical volume *)

val lvm_canonical_lv_name : t -> string -> string
(** get canonical name of an LV *)

val lvm_clear_filter : t -> unit
(** clear LVM device filter *)

val lvm_remove_all : t -> unit
(** remove all LVM LVs, VGs and PVs *)

val lvm_set_filter : t -> string array -> unit
(** set LVM device filter *)

val lvremove : t -> string -> unit
(** remove an LVM logical volume *)

val lvrename : t -> string -> string -> unit
(** rename an LVM logical volume *)

val lvresize : t -> string -> int -> unit
(** resize an LVM logical volume *)

val lvresize_free : t -> string -> int -> unit
(** expand an LV to fill free space *)

val lvs : t -> string array
(** list the LVM logical volumes (LVs) *)

val lvs_full : t -> lvm_lv array
(** list the LVM logical volumes (LVs) *)

val lvuuid : t -> string -> string
(** get the UUID of a logical volume *)

val lxattrlist : t -> string -> string array -> xattr array
(** lgetxattr on multiple files *)

val mkdir : t -> string -> unit
(** create a directory *)

val mkdir_mode : t -> string -> int -> unit
(** create a directory with a particular mode *)

val mkdir_p : t -> string -> unit
(** create a directory and parents *)

val mkdtemp : t -> string -> string
(** create a temporary directory *)

val mke2fs_J : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal *)

val mke2fs_JL : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal *)

val mke2fs_JU : t -> string -> int -> string -> string -> unit
(** make ext2/3/4 filesystem with external journal *)

val mke2journal : t -> int -> string -> unit
(** make ext2/3/4 external journal *)

val mke2journal_L : t -> int -> string -> string -> unit
(** make ext2/3/4 external journal with label *)

val mke2journal_U : t -> int -> string -> string -> unit
(** make ext2/3/4 external journal with UUID *)

val mkfifo : t -> int -> string -> unit
(** make FIFO (named pipe) *)

val mkfs : t -> string -> string -> unit
(** make a filesystem *)

val mkfs_b : t -> string -> int -> string -> unit
(** make a filesystem with block size

    @deprecated Use {!mkfs_opts} instead
 *)

val mkfs_opts : t -> ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> string -> string -> unit
(** make a filesystem *)

val mkmountpoint : t -> string -> unit
(** create a mountpoint *)

val mknod : t -> int -> int -> int -> string -> unit
(** make block, character or FIFO devices *)

val mknod_b : t -> int -> int -> int -> string -> unit
(** make block device node *)

val mknod_c : t -> int -> int -> int -> string -> unit
(** make char device node *)

val mkswap : t -> string -> unit
(** create a swap partition *)

val mkswap_L : t -> string -> string -> unit
(** create a swap partition with a label *)

val mkswap_U : t -> string -> string -> unit
(** create a swap partition with an explicit UUID *)

val mkswap_file : t -> string -> unit
(** create a swap file *)

val modprobe : t -> string -> unit
(** load a kernel module *)

val mount : t -> string -> string -> unit
(** mount a guest disk at a position in the filesystem *)

val mount_9p : t -> ?options:string -> string -> string -> unit
(** mount 9p filesystem *)

val mount_loop : t -> string -> string -> unit
(** mount a file using the loop device *)

val mount_options : t -> string -> string -> string -> unit
(** mount a guest disk with mount options *)

val mount_ro : t -> string -> string -> unit
(** mount a guest disk, read-only *)

val mount_vfs : t -> string -> string -> string -> string -> unit
(** mount a guest disk with mount options and vfstype *)

val mountpoints : t -> (string * string) list
(** show mountpoints *)

val mounts : t -> string array
(** show mounted filesystems *)

val mv : t -> string -> string -> unit
(** move a file *)

val ntfs_3g_probe : t -> bool -> string -> int
(** probe NTFS volume *)

val ntfsresize : t -> string -> unit
(** resize an NTFS filesystem

    @deprecated Use {!ntfsresize_opts} instead
 *)

val ntfsresize_opts : t -> ?size:int64 -> ?force:bool -> string -> unit
(** resize an NTFS filesystem *)

val ntfsresize_size : t -> string -> int64 -> unit
(** resize an NTFS filesystem (with size)

    @deprecated Use {!ntfsresize_opts} instead
 *)

val part_add : t -> string -> string -> int64 -> int64 -> unit
(** add a partition to the device *)

val part_del : t -> string -> int -> unit
(** delete a partition *)

val part_disk : t -> string -> string -> unit
(** partition whole disk with a single primary partition *)

val part_get_bootable : t -> string -> int -> bool
(** return true if a partition is bootable *)

val part_get_mbr_id : t -> string -> int -> int
(** get the MBR type byte (ID byte) from a partition *)

val part_get_parttype : t -> string -> string
(** get the partition table type *)

val part_init : t -> string -> string -> unit
(** create an empty partition table *)

val part_list : t -> string -> partition array
(** list partitions on a device *)

val part_set_bootable : t -> string -> int -> bool -> unit
(** make a partition bootable *)

val part_set_mbr_id : t -> string -> int -> int -> unit
(** set the MBR type byte (ID byte) of a partition *)

val part_set_name : t -> string -> int -> string -> unit
(** set partition name *)

val part_to_dev : t -> string -> string
(** convert partition name to device name *)

val part_to_partnum : t -> string -> int
(** convert partition name to partition number *)

val ping_daemon : t -> unit
(** ping the guest daemon *)

val pread : t -> string -> int -> int64 -> string
(** read part of a file *)

val pread_device : t -> string -> int -> int64 -> string
(** read part of a device *)

val pvcreate : t -> string -> unit
(** create an LVM physical volume *)

val pvremove : t -> string -> unit
(** remove an LVM physical volume *)

val pvresize : t -> string -> unit
(** resize an LVM physical volume *)

val pvresize_size : t -> string -> int64 -> unit
(** resize an LVM physical volume (with size) *)

val pvs : t -> string array
(** list the LVM physical volumes (PVs) *)

val pvs_full : t -> lvm_pv array
(** list the LVM physical volumes (PVs) *)

val pvuuid : t -> string -> string
(** get the UUID of a physical volume *)

val pwrite : t -> string -> string -> int64 -> int
(** write to part of a file *)

val pwrite_device : t -> string -> string -> int64 -> int
(** write to part of a device *)

val read_file : t -> string -> string
(** read a file *)

val read_lines : t -> string -> string array
(** read file as lines *)

val readdir : t -> string -> dirent array
(** read directories entries *)

val readlink : t -> string -> string
(** read the target of a symbolic link *)

val readlinklist : t -> string -> string array -> string array
(** readlink on multiple files *)

val realpath : t -> string -> string
(** canonicalized absolute pathname *)

val removexattr : t -> string -> string -> unit
(** remove extended attribute of a file or directory *)

val resize2fs : t -> string -> unit
(** resize an ext2, ext3 or ext4 filesystem *)

val resize2fs_M : t -> string -> unit
(** resize an ext2, ext3 or ext4 filesystem to the minimum size *)

val resize2fs_size : t -> string -> int64 -> unit
(** resize an ext2, ext3 or ext4 filesystem (with size) *)

val rm : t -> string -> unit
(** remove a file *)

val rm_rf : t -> string -> unit
(** remove a file or directory recursively *)

val rmdir : t -> string -> unit
(** remove a directory *)

val rmmountpoint : t -> string -> unit
(** remove a mountpoint *)

val scrub_device : t -> string -> unit
(** scrub (securely wipe) a device *)

val scrub_file : t -> string -> unit
(** scrub (securely wipe) a file *)

val scrub_freespace : t -> string -> unit
(** scrub (securely wipe) free space *)

val set_append : t -> string option -> unit
(** add options to kernel command line *)

val set_attach_method : t -> string -> unit
(** set the attach method *)

val set_autosync : t -> bool -> unit
(** set autosync mode *)

val set_direct : t -> bool -> unit
(** enable or disable direct appliance mode *)

val set_e2label : t -> string -> string -> unit
(** set the ext2/3/4 filesystem label *)

val set_e2uuid : t -> string -> string -> unit
(** set the ext2/3/4 filesystem UUID *)

val set_memsize : t -> int -> unit
(** set memory allocated to the qemu subprocess *)

val set_network : t -> bool -> unit
(** set enable network flag *)

val set_path : t -> string option -> unit
(** set the search path *)

val set_pgroup : t -> bool -> unit
(** set process group flag *)

val set_qemu : t -> string option -> unit
(** set the qemu binary *)

val set_recovery_proc : t -> bool -> unit
(** enable or disable the recovery process *)

val set_selinux : t -> bool -> unit
(** set SELinux enabled or disabled at appliance boot *)

val set_smp : t -> int -> unit
(** set number of virtual CPUs in appliance *)

val set_trace : t -> bool -> unit
(** enable or disable command traces *)

val set_verbose : t -> bool -> unit
(** set verbose mode *)

val setcon : t -> string -> unit
(** set SELinux security context *)

val setxattr : t -> string -> string -> int -> string -> unit
(** set extended attribute of a file or directory *)

val sfdisk : t -> string -> int -> int -> int -> string array -> unit
(** create partitions on a block device

    @deprecated Use {!part_add} instead
 *)

val sfdiskM : t -> string -> string array -> unit
(** create partitions on a block device

    @deprecated Use {!part_add} instead
 *)

val sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit
(** modify a single partition on a block device

    @deprecated Use {!part_add} instead
 *)

val sfdisk_disk_geometry : t -> string -> string
(** display the disk geometry from the partition table *)

val sfdisk_kernel_geometry : t -> string -> string
(** display the kernel geometry *)

val sfdisk_l : t -> string -> string
(** display the partition table

    @deprecated Use {!part_list} instead
 *)

val sh : t -> string -> string
(** run a command via the shell *)

val sh_lines : t -> string -> string array
(** run a command via the shell returning lines *)

val sleep : t -> int -> unit
(** sleep for some seconds *)

val stat : t -> string -> stat
(** get file information *)

val statvfs : t -> string -> statvfs
(** get file system statistics *)

val strings : t -> string -> string array
(** print the printable strings in a file *)

val strings_e : t -> string -> string -> string array
(** print the printable strings in a file *)

val swapoff_device : t -> string -> unit
(** disable swap on device *)

val swapoff_file : t -> string -> unit
(** disable swap on file *)

val swapoff_label : t -> string -> unit
(** disable swap on labeled swap partition *)

val swapoff_uuid : t -> string -> unit
(** disable swap on swap partition by UUID *)

val swapon_device : t -> string -> unit
(** enable swap on device *)

val swapon_file : t -> string -> unit
(** enable swap on file *)

val swapon_label : t -> string -> unit
(** enable swap on labeled swap partition *)

val swapon_uuid : t -> string -> unit
(** enable swap on swap partition by UUID *)

val sync : t -> unit
(** sync disks, writes are flushed through to the disk image *)

val tail : t -> string -> string array
(** return last 10 lines of a file *)

val tail_n : t -> int -> string -> string array
(** return last N lines of a file *)

val tar_in : t -> string -> string -> unit
(** unpack tarfile to directory *)

val tar_out : t -> string -> string -> unit
(** pack directory into tarfile *)

val test0 : t -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit

val test0rbool : t -> string -> bool

val test0rboolerr : t -> bool

val test0rconstoptstring : t -> string -> string option

val test0rconstoptstringerr : t -> string option

val test0rconststring : t -> string -> string

val test0rconststringerr : t -> string

val test0rhashtable : t -> string -> (string * string) list

val test0rhashtableerr : t -> (string * string) list

val test0rint : t -> string -> int

val test0rint64 : t -> string -> int64

val test0rint64err : t -> int64

val test0rinterr : t -> int

val test0rstring : t -> string -> string

val test0rstringerr : t -> string

val test0rstringlist : t -> string -> string array

val test0rstringlisterr : t -> string array

val test0rstruct : t -> string -> lvm_pv

val test0rstructerr : t -> lvm_pv

val test0rstructlist : t -> string -> lvm_pv array

val test0rstructlisterr : t -> lvm_pv array

val tgz_in : t -> string -> string -> unit
(** unpack compressed tarball to directory *)

val tgz_out : t -> string -> string -> unit
(** pack directory into compressed tarball *)

val touch : t -> string -> unit
(** update file timestamps or create a new file *)

val truncate : t -> string -> unit
(** truncate a file to zero size *)

val truncate_size : t -> string -> int64 -> unit
(** truncate a file to a particular size *)

val tune2fs_l : t -> string -> (string * string) list
(** get ext2/ext3/ext4 superblock details *)

val txz_in : t -> string -> string -> unit
(** unpack compressed tarball to directory *)

val txz_out : t -> string -> string -> unit
(** pack directory into compressed tarball *)

val umask : t -> int -> int
(** set file mode creation mask (umask) *)

val umount : t -> string -> unit
(** unmount a filesystem *)

val umount_all : t -> unit
(** unmount all filesystems *)

val upload : t -> string -> string -> unit
(** upload a file from the local machine *)

val upload_offset : t -> string -> string -> int64 -> unit
(** upload a file from the local machine with offset *)

val utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit
(** set timestamp of a file with nanosecond precision *)

val version : t -> version
(** get the library version number *)

val vfs_label : t -> string -> string
(** get the filesystem label *)

val vfs_type : t -> string -> string
(** get the Linux VFS type corresponding to a mounted device *)

val vfs_uuid : t -> string -> string
(** get the filesystem UUID *)

val vg_activate : t -> bool -> string array -> unit
(** activate or deactivate some volume groups *)

val vg_activate_all : t -> bool -> unit
(** activate or deactivate all volume groups *)

val vgcreate : t -> string -> string array -> unit
(** create an LVM volume group *)

val vglvuuids : t -> string -> string array
(** get the LV UUIDs of all LVs in the volume group *)

val vgpvuuids : t -> string -> string array
(** get the PV UUIDs containing the volume group *)

val vgremove : t -> string -> unit
(** remove an LVM volume group *)

val vgrename : t -> string -> string -> unit
(** rename an LVM volume group *)

val vgs : t -> string array
(** list the LVM volume groups (VGs) *)

val vgs_full : t -> lvm_vg array
(** list the LVM volume groups (VGs) *)

val vgscan : t -> unit
(** rescan for LVM physical volumes, volume groups and logical volumes *)

val vguuid : t -> string -> string
(** get the UUID of a volume group *)

val wait_ready : t -> unit
(** wait until the qemu subprocess launches (no op)

    @deprecated Use {!launch} instead
 *)

val wc_c : t -> string -> int
(** count characters in a file *)

val wc_l : t -> string -> int
(** count lines in a file *)

val wc_w : t -> string -> int
(** count words in a file *)

val write : t -> string -> string -> unit
(** create a new file *)

val write_append : t -> string -> string -> unit
(** append content to end of file *)

val write_file : t -> string -> string -> int -> unit
(** create a file

    @deprecated Use {!write} instead
 *)

val zegrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zegrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val zero : t -> string -> unit
(** write zeroes to the device *)

val zero_device : t -> string -> unit
(** write zeroes to an entire device *)

val zerofree : t -> string -> unit
(** zero unused inodes and disk blocks on ext2/3 filesystem *)

val zfgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zfgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val zfile : t -> string -> string -> string
(** determine file type inside a compressed file

    @deprecated Use {!file} instead
 *)

val zgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

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

    Note that methods that take no parameters (except the implicit handle)
    get an extra unit [()] parameter.  This is so you can create a
    closure from the method easily.  For example
    [g#]{{!guestfs.get_verbose}get_verbose} [()]
    calls the method, whereas [g#get_verbose] is a function. *)

class guestfs : unit -> object
  method close : unit -> unit
  method set_event_callback : event_callback -> event list -> event_handle
  method delete_event_callback : event_handle -> unit
  method last_errno : unit -> int
  method user_cancel : unit -> unit
  method ocaml_handle : t
  method add_cdrom : string -> unit
  method add_domain : ?libvirturi:string -> ?readonly:bool -> ?iface:string -> ?live:bool -> ?allowuuid:bool -> ?readonlydisk:string -> string -> int
  method add_drive : string -> unit
  method add_drive_opts : ?readonly:bool -> ?format:string -> ?iface:string -> ?name:string -> string -> unit
  method add_drive_ro : string -> unit
  method add_drive_ro_with_if : string -> string -> unit
  method add_drive_with_if : string -> string -> unit
  method aug_clear : string -> unit
  method aug_close : unit -> unit
  method aug_defnode : string -> string -> string -> int_bool
  method aug_defvar : string -> string option -> int
  method aug_get : string -> string
  method aug_init : string -> int -> unit
  method aug_insert : string -> string -> bool -> unit
  method aug_load : unit -> unit
  method aug_ls : string -> string array
  method aug_match : string -> string array
  method aug_mv : string -> string -> unit
  method aug_rm : string -> int
  method aug_save : unit -> unit
  method aug_set : string -> string -> unit
  method available : string array -> unit
  method available_all_groups : unit -> string array
  method base64_in : string -> string -> unit
  method base64_out : string -> string -> unit
  method blockdev_flushbufs : string -> unit
  method blockdev_getbsz : string -> int
  method blockdev_getro : string -> bool
  method blockdev_getsize64 : string -> int64
  method blockdev_getss : string -> int
  method blockdev_getsz : string -> int64
  method blockdev_rereadpt : string -> unit
  method blockdev_setbsz : string -> int -> unit
  method blockdev_setro : string -> unit
  method blockdev_setrw : string -> unit
  method btrfs_filesystem_resize : ?size:int64 -> string -> unit
  method case_sensitive_path : string -> string
  method cat : string -> string
  method checksum : string -> string -> string
  method checksum_device : string -> string -> string
  method checksums_out : string -> string -> string -> unit
  method chmod : int -> string -> unit
  method chown : int -> int -> string -> unit
  method command : string array -> string
  method command_lines : string array -> string array
  method compress_device_out : ?level:int -> string -> string -> string -> unit
  method compress_out : ?level:int -> string -> string -> string -> unit
  method config : string -> string option -> unit
  method copy_device_to_device : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
  method copy_device_to_file : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
  method copy_file_to_device : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
  method copy_file_to_file : ?srcoffset:int64 -> ?destoffset:int64 -> ?size:int64 -> string -> string -> unit
  method copy_size : string -> string -> int64 -> unit
  method cp : string -> string -> unit
  method cp_a : string -> string -> unit
  method dd : string -> string -> unit
  method debug : string -> string array -> string
  method debug_cmdline : unit -> string array
  method debug_drives : unit -> string array
  method debug_upload : string -> string -> int -> unit
  method df : unit -> string
  method df_h : unit -> string
  method dmesg : unit -> string
  method download : string -> string -> unit
  method download_offset : string -> string -> int64 -> int64 -> unit
  method drop_caches : int -> unit
  method du : string -> int64
  method e2fsck_f : string -> unit
  method echo_daemon : string array -> string
  method egrep : string -> string -> string array
  method egrepi : string -> string -> string array
  method equal : string -> string -> bool
  method exists : string -> bool
  method fallocate : string -> int -> unit
  method fallocate64 : string -> int64 -> unit
  method fgrep : string -> string -> string array
  method fgrepi : string -> string -> string array
  method file : string -> string
  method file_architecture : string -> string
  method filesize : string -> int64
  method fill : int -> int -> string -> unit
  method fill_pattern : string -> int -> string -> unit
  method find : string -> string array
  method find0 : string -> string -> unit
  method findfs_label : string -> string
  method findfs_uuid : string -> string
  method fsck : string -> string -> int
  method get_append : unit -> string option
  method get_attach_method : unit -> string
  method get_autosync : unit -> bool
  method get_direct : unit -> bool
  method get_e2label : string -> string
  method get_e2uuid : string -> string
  method get_memsize : unit -> int
  method get_network : unit -> bool
  method get_path : unit -> string
  method get_pgroup : unit -> bool
  method get_pid : unit -> int
  method get_qemu : unit -> string
  method get_recovery_proc : unit -> bool
  method get_selinux : unit -> bool
  method get_smp : unit -> int
  method get_state : unit -> int
  method get_trace : unit -> bool
  method get_umask : unit -> int
  method get_verbose : unit -> bool
  method getcon : unit -> string
  method getxattr : string -> string -> string
  method getxattrs : string -> xattr array
  method glob_expand : string -> string array
  method grep : string -> string -> string array
  method grepi : string -> string -> string array
  method grub_install : string -> string -> unit
  method head : string -> string array
  method head_n : int -> string -> string array
  method hexdump : string -> string
  method initrd_cat : string -> string -> string
  method initrd_list : string -> string array
  method inotify_add_watch : string -> int -> int64
  method inotify_close : unit -> unit
  method inotify_files : unit -> string array
  method inotify_init : int -> unit
  method inotify_read : unit -> inotify_event array
  method inotify_rm_watch : int -> unit
  method inspect_get_arch : string -> string
  method inspect_get_distro : string -> string
  method inspect_get_drive_mappings : string -> (string * string) list
  method inspect_get_filesystems : string -> string array
  method inspect_get_format : string -> string
  method inspect_get_hostname : string -> string
  method inspect_get_icon : ?favicon:bool -> ?highquality:bool -> string -> string
  method inspect_get_major_version : string -> int
  method inspect_get_minor_version : string -> int
  method inspect_get_mountpoints : string -> (string * string) list
  method inspect_get_package_format : string -> string
  method inspect_get_package_management : string -> string
  method inspect_get_product_name : string -> string
  method inspect_get_product_variant : string -> string
  method inspect_get_roots : unit -> string array
  method inspect_get_type : string -> string
  method inspect_get_windows_current_control_set : string -> string
  method inspect_get_windows_systemroot : string -> string
  method inspect_is_live : string -> bool
  method inspect_is_multipart : string -> bool
  method inspect_is_netinst : string -> bool
  method inspect_list_applications : string -> application array
  method inspect_os : unit -> string array
  method internal_autosync : unit -> unit
  method is_blockdev : string -> bool
  method is_busy : unit -> bool
  method is_chardev : string -> bool
  method is_config : unit -> bool
  method is_dir : string -> bool
  method is_fifo : string -> bool
  method is_file : string -> bool
  method is_launching : unit -> bool
  method is_lv : string -> bool
  method is_ready : unit -> bool
  method is_socket : string -> bool
  method is_symlink : string -> bool
  method is_zero : string -> bool
  method is_zero_device : string -> bool
  method kill_subprocess : unit -> unit
  method launch : unit -> unit
  method lchown : int -> int -> string -> unit
  method lgetxattr : string -> string -> string
  method lgetxattrs : string -> xattr array
  method list_9p : unit -> string array
  method list_devices : unit -> string array
  method list_dm_devices : unit -> string array
  method list_filesystems : unit -> (string * string) list
  method list_partitions : unit -> string array
  method ll : string -> string
  method ln : string -> string -> unit
  method ln_f : string -> string -> unit
  method ln_s : string -> string -> unit
  method ln_sf : string -> string -> unit
  method lremovexattr : string -> string -> unit
  method ls : string -> string array
  method lsetxattr : string -> string -> int -> string -> unit
  method lstat : string -> stat
  method lstatlist : string -> string array -> stat array
  method luks_add_key : string -> string -> string -> int -> unit
  method luks_close : string -> unit
  method luks_format : string -> string -> int -> unit
  method luks_format_cipher : string -> string -> int -> string -> unit
  method luks_kill_slot : string -> string -> int -> unit
  method luks_open : string -> string -> string -> unit
  method luks_open_ro : string -> string -> string -> unit
  method lvcreate : string -> string -> int -> unit
  method lvm_canonical_lv_name : string -> string
  method lvm_clear_filter : unit -> unit
  method lvm_remove_all : unit -> unit
  method lvm_set_filter : string array -> unit
  method lvremove : string -> unit
  method lvrename : string -> string -> unit
  method lvresize : string -> int -> unit
  method lvresize_free : string -> int -> unit
  method lvs : unit -> string array
  method lvs_full : unit -> lvm_lv array
  method lvuuid : string -> string
  method lxattrlist : string -> string array -> xattr array
  method mkdir : string -> unit
  method mkdir_mode : string -> int -> unit
  method mkdir_p : string -> unit
  method mkdtemp : string -> string
  method mke2fs_J : string -> int -> string -> string -> unit
  method mke2fs_JL : string -> int -> string -> string -> unit
  method mke2fs_JU : string -> int -> string -> string -> unit
  method mke2journal : int -> string -> unit
  method mke2journal_L : int -> string -> string -> unit
  method mke2journal_U : int -> string -> string -> unit
  method mkfifo : int -> string -> unit
  method mkfs : string -> string -> unit
  method mkfs_b : string -> int -> string -> unit
  method mkfs_opts : ?blocksize:int -> ?features:string -> ?inode:int -> ?sectorsize:int -> string -> string -> unit
  method mkmountpoint : string -> unit
  method mknod : int -> int -> int -> string -> unit
  method mknod_b : int -> int -> int -> string -> unit
  method mknod_c : int -> int -> int -> string -> unit
  method mkswap : string -> unit
  method mkswap_L : string -> string -> unit
  method mkswap_U : string -> string -> unit
  method mkswap_file : string -> unit
  method modprobe : string -> unit
  method mount : string -> string -> unit
  method mount_9p : ?options:string -> string -> string -> unit
  method mount_loop : string -> string -> unit
  method mount_options : string -> string -> string -> unit
  method mount_ro : string -> string -> unit
  method mount_vfs : string -> string -> string -> string -> unit
  method mountpoints : unit -> (string * string) list
  method mounts : unit -> string array
  method mv : string -> string -> unit
  method ntfs_3g_probe : bool -> string -> int
  method ntfsresize : string -> unit
  method ntfsresize_opts : ?size:int64 -> ?force:bool -> string -> unit
  method ntfsresize_size : string -> int64 -> unit
  method part_add : string -> string -> int64 -> int64 -> unit
  method part_del : string -> int -> unit
  method part_disk : string -> string -> unit
  method part_get_bootable : string -> int -> bool
  method part_get_mbr_id : string -> int -> int
  method part_get_parttype : string -> string
  method part_init : string -> string -> unit
  method part_list : string -> partition array
  method part_set_bootable : string -> int -> bool -> unit
  method part_set_mbr_id : string -> int -> int -> unit
  method part_set_name : string -> int -> string -> unit
  method part_to_dev : string -> string
  method part_to_partnum : string -> int
  method ping_daemon : unit -> unit
  method pread : string -> int -> int64 -> string
  method pread_device : string -> int -> int64 -> string
  method pvcreate : string -> unit
  method pvremove : string -> unit
  method pvresize : string -> unit
  method pvresize_size : string -> int64 -> unit
  method pvs : unit -> string array
  method pvs_full : unit -> lvm_pv array
  method pvuuid : string -> string
  method pwrite : string -> string -> int64 -> int
  method pwrite_device : string -> string -> int64 -> int
  method read_file : string -> string
  method read_lines : string -> string array
  method readdir : string -> dirent array
  method readlink : string -> string
  method readlinklist : string -> string array -> string array
  method realpath : string -> string
  method removexattr : string -> string -> unit
  method resize2fs : string -> unit
  method resize2fs_M : string -> unit
  method resize2fs_size : string -> int64 -> unit
  method rm : string -> unit
  method rm_rf : string -> unit
  method rmdir : string -> unit
  method rmmountpoint : string -> unit
  method scrub_device : string -> unit
  method scrub_file : string -> unit
  method scrub_freespace : string -> unit
  method set_append : string option -> unit
  method set_attach_method : string -> unit
  method set_autosync : bool -> unit
  method set_direct : bool -> unit
  method set_e2label : string -> string -> unit
  method set_e2uuid : string -> string -> unit
  method set_memsize : int -> unit
  method set_network : bool -> unit
  method set_path : string option -> unit
  method set_pgroup : bool -> unit
  method set_qemu : string option -> unit
  method set_recovery_proc : bool -> unit
  method set_selinux : bool -> unit
  method set_smp : int -> unit
  method set_trace : bool -> unit
  method set_verbose : bool -> unit
  method setcon : string -> unit
  method setxattr : string -> string -> int -> string -> unit
  method sfdisk : string -> int -> int -> int -> string array -> unit
  method sfdiskM : string -> string array -> unit
  method sfdisk_N : string -> int -> int -> int -> int -> string -> unit
  method sfdisk_disk_geometry : string -> string
  method sfdisk_kernel_geometry : string -> string
  method sfdisk_l : string -> string
  method sh : string -> string
  method sh_lines : string -> string array
  method sleep : int -> unit
  method stat : string -> stat
  method statvfs : string -> statvfs
  method strings : string -> string array
  method strings_e : string -> string -> string array
  method swapoff_device : string -> unit
  method swapoff_file : string -> unit
  method swapoff_label : string -> unit
  method swapoff_uuid : string -> unit
  method swapon_device : string -> unit
  method swapon_file : string -> unit
  method swapon_label : string -> unit
  method swapon_uuid : string -> unit
  method sync : unit -> unit
  method tail : string -> string array
  method tail_n : int -> string -> string array
  method tar_in : string -> string -> unit
  method tar_out : string -> string -> unit
  method test0 : string -> string option -> string array -> bool -> int -> int64 -> string -> string -> string -> unit
  method test0rbool : string -> bool
  method test0rboolerr : unit -> bool
  method test0rconstoptstring : string -> string option
  method test0rconstoptstringerr : unit -> string option
  method test0rconststring : string -> string
  method test0rconststringerr : unit -> string
  method test0rhashtable : string -> (string * string) list
  method test0rhashtableerr : unit -> (string * string) list
  method test0rint : string -> int
  method test0rint64 : string -> int64
  method test0rint64err : unit -> int64
  method test0rinterr : unit -> int
  method test0rstring : string -> string
  method test0rstringerr : unit -> string
  method test0rstringlist : string -> string array
  method test0rstringlisterr : unit -> string array
  method test0rstruct : string -> lvm_pv
  method test0rstructerr : unit -> lvm_pv
  method test0rstructlist : string -> lvm_pv array
  method test0rstructlisterr : unit -> lvm_pv array
  method tgz_in : string -> string -> unit
  method tgz_out : string -> string -> unit
  method touch : string -> unit
  method truncate : string -> unit
  method truncate_size : string -> int64 -> unit
  method tune2fs_l : string -> (string * string) list
  method txz_in : string -> string -> unit
  method txz_out : string -> string -> unit
  method umask : int -> int
  method umount : string -> unit
  method umount_all : unit -> unit
  method upload : string -> string -> unit
  method upload_offset : string -> string -> int64 -> unit
  method utimens : string -> int64 -> int64 -> int64 -> int64 -> unit
  method version : unit -> version
  method vfs_label : string -> string
  method vfs_type : string -> string
  method vfs_uuid : string -> string
  method vg_activate : bool -> string array -> unit
  method vg_activate_all : bool -> unit
  method vgcreate : string -> string array -> unit
  method vglvuuids : string -> string array
  method vgpvuuids : string -> string array
  method vgremove : string -> unit
  method vgrename : string -> string -> unit
  method vgs : unit -> string array
  method vgs_full : unit -> lvm_vg array
  method vgscan : unit -> unit
  method vguuid : string -> string
  method wait_ready : unit -> unit
  method wc_c : string -> int
  method wc_l : string -> int
  method wc_w : string -> int
  method write : string -> string -> unit
  method write_append : string -> string -> unit
  method write_file : string -> string -> int -> unit
  method zegrep : string -> string -> string array
  method zegrepi : string -> string -> string array
  method zero : string -> unit
  method zero_device : string -> unit
  method zerofree : string -> unit
  method zfgrep : string -> string -> string array
  method zfgrepi : string -> string -> string array
  method zfile : string -> string -> string
  method zgrep : string -> string -> string array
  method zgrepi : string -> string -> string array
end
