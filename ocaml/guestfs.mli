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

(** For API documentation you should refer to the C API
    in the guestfs(3) manual page.  The OCaml API uses almost
    exactly the same calls. *)

type t
(** A [guestfs_h] handle. *)

exception Error of string
(** This exception is raised when there is an error. *)

exception Handle_closed of string
(** This exception is raised if you use a {!Guestfs.t} handle
    after calling {!close} on it.  The string is the name of
    the function. *)

val create : unit -> t
(** Create a {!Guestfs.t} handle. *)

val close : t -> unit
(** Close the {!Guestfs.t} handle and free up all resources used
    by it immediately.

    Handles are closed by the garbage collector when they become
    unreferenced, but callers can call this in order to provide
    predictable cleanup. *)

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

val add_cdrom : t -> string -> unit
(** add a CD-ROM disk image to examine *)

val add_drive : t -> string -> unit
(** add an image to examine or modify *)

val add_drive_ro : t -> string -> unit
(** add a drive in snapshot mode (read-only) *)

val add_drive_ro_with_if : t -> string -> string -> unit
(** add a drive read-only specifying the QEMU block emulation to use *)

val add_drive_with_if : t -> string -> string -> unit
(** add a drive specifying the QEMU block emulation to use *)

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

val case_sensitive_path : t -> string -> string
(** return true path on case-insensitive filesystem *)

val cat : t -> string -> string
(** list the contents of a file *)

val checksum : t -> string -> string -> string
(** compute MD5, SHAx or CRC checksum of file *)

val chmod : t -> int -> string -> unit
(** change file mode *)

val chown : t -> int -> int -> string -> unit
(** change file owner and group *)

val command : t -> string array -> string
(** run a command from the guest filesystem *)

val command_lines : t -> string array -> string array
(** run a command, returning lines *)

val config : t -> string -> string option -> unit
(** add qemu parameters *)

val cp : t -> string -> string -> unit
(** copy a file *)

val cp_a : t -> string -> string -> unit
(** copy a file or directory recursively *)

val dd : t -> string -> string -> unit
(** copy from source to destination using dd *)

val debug : t -> string -> string array -> string
(** debugging and internals *)

val df : t -> string
(** report file system disk space usage *)

val df_h : t -> string
(** report file system disk space usage (human readable) *)

val dmesg : t -> string
(** return kernel messages *)

val download : t -> string -> string -> unit
(** download a file to the local machine *)

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
(** preallocate a file in the guest filesystem *)

val fgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val fgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val file : t -> string -> string
(** determine file type *)

val filesize : t -> string -> int64
(** return the size of the file in bytes *)

val fill : t -> int -> int -> string -> unit
(** fill a file with octets *)

val find : t -> string -> string array
(** find all files and directories *)

val find0 : t -> string -> string -> unit
(** find all files and directories, returning NUL-separated list *)

val fsck : t -> string -> string -> int
(** run the filesystem checker *)

val get_append : t -> string option
(** get the additional kernel options *)

val get_autosync : t -> bool
(** get autosync mode *)

val get_direct : t -> bool
(** get direct appliance mode flag *)

val get_e2label : t -> string -> string
(** get the ext2/3/4 filesystem label *)

val get_e2uuid : t -> string -> string
(** get the ext2/3/4 filesystem UUID *)

val get_memsize : t -> int
(** get memory allocated to the qemu subprocess *)

val get_path : t -> string
(** get the search path *)

val get_pid : t -> int
(** get PID of qemu subprocess *)

val get_qemu : t -> string
(** get the qemu binary *)

val get_recovery_proc : t -> bool
(** get recovery process enabled flag *)

val get_selinux : t -> bool
(** get SELinux enabled flag *)

val get_state : t -> int
(** get the current state *)

val get_trace : t -> bool
(** get command trace enabled flag *)

val get_verbose : t -> bool
(** get verbose mode *)

val getcon : t -> string
(** get SELinux security context *)

val getxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory *)

val glob_expand : t -> string -> string array
(** expand a wildcard path *)

val grep : t -> string -> string -> string array
(** return lines matching a pattern *)

val grepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val grub_install : t -> string -> string -> unit
(** install GRUB *)

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

val is_busy : t -> bool
(** is busy processing a command *)

val is_config : t -> bool
(** is in configuration state *)

val is_dir : t -> string -> bool
(** test if file exists *)

val is_file : t -> string -> bool
(** test if file exists *)

val is_launching : t -> bool
(** is launching subprocess *)

val is_ready : t -> bool
(** is ready to accept commands *)

val kill_subprocess : t -> unit
(** kill the qemu subprocess *)

val launch : t -> unit
(** launch the qemu subprocess *)

val lchown : t -> int -> int -> string -> unit
(** change file owner and group *)

val lgetxattrs : t -> string -> xattr array
(** list extended attributes of a file or directory *)

val list_devices : t -> string array
(** list the block devices *)

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

val lvcreate : t -> string -> string -> int -> unit
(** create an LVM volume group *)

val lvm_remove_all : t -> unit
(** remove all LVM LVs, VGs and PVs *)

val lvremove : t -> string -> unit
(** remove an LVM logical volume *)

val lvrename : t -> string -> string -> unit
(** rename an LVM logical volume *)

val lvresize : t -> string -> int -> unit
(** resize an LVM logical volume *)

val lvs : t -> string array
(** list the LVM logical volumes (LVs) *)

val lvs_full : t -> lvm_lv array
(** list the LVM logical volumes (LVs) *)

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
(** make a filesystem with block size *)

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

val part_add : t -> string -> string -> int64 -> int64 -> unit
(** add a partition to the device *)

val part_disk : t -> string -> string -> unit
(** partition whole disk with a single primary partition *)

val part_get_parttype : t -> string -> string
(** get the partition table type *)

val part_init : t -> string -> string -> unit
(** create an empty partition table *)

val part_list : t -> string -> partition array
(** list partitions on a device *)

val part_set_bootable : t -> string -> int -> bool -> unit
(** make a partition bootable *)

val part_set_name : t -> string -> int -> string -> unit
(** set partition name *)

val ping_daemon : t -> unit
(** ping the guest daemon *)

val pread : t -> string -> int -> int64 -> string
(** read part of a file *)

val pvcreate : t -> string -> unit
(** create an LVM physical volume *)

val pvremove : t -> string -> unit
(** remove an LVM physical volume *)

val pvresize : t -> string -> unit
(** resize an LVM physical volume *)

val pvs : t -> string array
(** list the LVM physical volumes (PVs) *)

val pvs_full : t -> lvm_pv array
(** list the LVM physical volumes (PVs) *)

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
(** resize an ext2/ext3 filesystem *)

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

val set_path : t -> string -> unit
(** set the search path *)

val set_qemu : t -> string -> unit
(** set the qemu binary *)

val set_recovery_proc : t -> bool -> unit
(** enable or disable the recovery process *)

val set_selinux : t -> bool -> unit
(** set SELinux enabled or disabled at appliance boot *)

val set_trace : t -> bool -> unit
(** enable or disable command traces *)

val set_verbose : t -> bool -> unit
(** set verbose mode *)

val setcon : t -> string -> unit
(** set SELinux security context *)

val setxattr : t -> string -> string -> int -> string -> unit
(** set extended attribute of a file or directory *)

val sfdisk : t -> string -> int -> int -> int -> string array -> unit
(** create partitions on a block device *)

val sfdiskM : t -> string -> string array -> unit
(** create partitions on a block device *)

val sfdisk_N : t -> string -> int -> int -> int -> int -> string -> unit
(** modify a single partition on a block device *)

val sfdisk_disk_geometry : t -> string -> string
(** display the disk geometry from the partition table *)

val sfdisk_kernel_geometry : t -> string -> string
(** display the kernel geometry *)

val sfdisk_l : t -> string -> string
(** display the partition table *)

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

val test0 : t -> string -> string option -> string array -> bool -> int -> int64 -> string -> string -> unit
(** internal test function - do not use *)

val test0rbool : t -> string -> bool
(** internal test function - do not use *)

val test0rboolerr : t -> bool
(** internal test function - do not use *)

val test0rconstoptstring : t -> string -> string option
(** internal test function - do not use *)

val test0rconstoptstringerr : t -> string option
(** internal test function - do not use *)

val test0rconststring : t -> string -> string
(** internal test function - do not use *)

val test0rconststringerr : t -> string
(** internal test function - do not use *)

val test0rhashtable : t -> string -> (string * string) list
(** internal test function - do not use *)

val test0rhashtableerr : t -> (string * string) list
(** internal test function - do not use *)

val test0rint : t -> string -> int
(** internal test function - do not use *)

val test0rint64 : t -> string -> int64
(** internal test function - do not use *)

val test0rint64err : t -> int64
(** internal test function - do not use *)

val test0rinterr : t -> int
(** internal test function - do not use *)

val test0rstring : t -> string -> string
(** internal test function - do not use *)

val test0rstringerr : t -> string
(** internal test function - do not use *)

val test0rstringlist : t -> string -> string array
(** internal test function - do not use *)

val test0rstringlisterr : t -> string array
(** internal test function - do not use *)

val test0rstruct : t -> string -> lvm_pv
(** internal test function - do not use *)

val test0rstructerr : t -> lvm_pv
(** internal test function - do not use *)

val test0rstructlist : t -> string -> lvm_pv array
(** internal test function - do not use *)

val test0rstructlisterr : t -> lvm_pv array
(** internal test function - do not use *)

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

val umask : t -> int -> int
(** set file mode creation mask (umask) *)

val umount : t -> string -> unit
(** unmount a filesystem *)

val umount_all : t -> unit
(** unmount all filesystems *)

val upload : t -> string -> string -> unit
(** upload a file from the local machine *)

val utimens : t -> string -> int64 -> int64 -> int64 -> int64 -> unit
(** set timestamp of a file with nanosecond precision *)

val version : t -> version
(** get the library version number *)

val vfs_type : t -> string -> string
(** get the Linux VFS type corresponding to a mounted device *)

val vg_activate : t -> bool -> string array -> unit
(** activate or deactivate some volume groups *)

val vg_activate_all : t -> bool -> unit
(** activate or deactivate all volume groups *)

val vgcreate : t -> string -> string array -> unit
(** create an LVM volume group *)

val vgremove : t -> string -> unit
(** remove an LVM volume group *)

val vgrename : t -> string -> string -> unit
(** rename an LVM volume group *)

val vgs : t -> string array
(** list the LVM volume groups (VGs) *)

val vgs_full : t -> lvm_vg array
(** list the LVM volume groups (VGs) *)

val wait_ready : t -> unit
(** wait until the qemu subprocess launches (no op) *)

val wc_c : t -> string -> int
(** count characters in a file *)

val wc_l : t -> string -> int
(** count lines in a file *)

val wc_w : t -> string -> int
(** count words in a file *)

val write_file : t -> string -> string -> int -> unit
(** create a file *)

val zegrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zegrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val zero : t -> string -> unit
(** write zeroes to the device *)

val zerofree : t -> string -> unit
(** zero unused inodes and disk blocks on ext2/3 filesystem *)

val zfgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zfgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

val zfile : t -> string -> string -> string
(** determine file type inside a compressed file *)

val zgrep : t -> string -> string -> string array
(** return lines matching a pattern *)

val zgrepi : t -> string -> string -> string array
(** return lines matching a pattern *)

