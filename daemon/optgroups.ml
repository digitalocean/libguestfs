(* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
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

external acl_available : unit -> bool =
  "guestfs_int_daemon_optgroup_acl_available" "noalloc"
external blkdiscard_available : unit -> bool =
  "guestfs_int_daemon_optgroup_blkdiscard_available" "noalloc"
external blkdiscardzeroes_available : unit -> bool =
  "guestfs_int_daemon_optgroup_blkdiscardzeroes_available" "noalloc"
external btrfs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_btrfs_available" "noalloc"
external extlinux_available : unit -> bool =
  "guestfs_int_daemon_optgroup_extlinux_available" "noalloc"
external f2fs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_f2fs_available" "noalloc"
external fstrim_available : unit -> bool =
  "guestfs_int_daemon_optgroup_fstrim_available" "noalloc"
external gdisk_available : unit -> bool =
  "guestfs_int_daemon_optgroup_gdisk_available" "noalloc"
external grub_available : unit -> bool =
  "guestfs_int_daemon_optgroup_grub_available" "noalloc"
external hivex_available : unit -> bool =
  "guestfs_int_daemon_optgroup_hivex_available" "noalloc"
external inotify_available : unit -> bool =
  "guestfs_int_daemon_optgroup_inotify_available" "noalloc"
external journal_available : unit -> bool =
  "guestfs_int_daemon_optgroup_journal_available" "noalloc"
external ldm_available : unit -> bool =
  "guestfs_int_daemon_optgroup_ldm_available" "noalloc"
external libtsk_available : unit -> bool =
  "guestfs_int_daemon_optgroup_libtsk_available" "noalloc"
external libyara_available : unit -> bool =
  "guestfs_int_daemon_optgroup_libyara_available" "noalloc"
external linuxcaps_available : unit -> bool =
  "guestfs_int_daemon_optgroup_linuxcaps_available" "noalloc"
external linuxfsuuid_available : unit -> bool =
  "guestfs_int_daemon_optgroup_linuxfsuuid_available" "noalloc"
external linuxmodules_available : unit -> bool =
  "guestfs_int_daemon_optgroup_linuxmodules_available" "noalloc"
external linuxxattrs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_linuxxattrs_available" "noalloc"
external luks_available : unit -> bool =
  "guestfs_int_daemon_optgroup_luks_available" "noalloc"
external lvm2_available : unit -> bool =
  "guestfs_int_daemon_optgroup_lvm2_available" "noalloc"
external mdadm_available : unit -> bool =
  "guestfs_int_daemon_optgroup_mdadm_available" "noalloc"
external mknod_available : unit -> bool =
  "guestfs_int_daemon_optgroup_mknod_available" "noalloc"
external ntfs3g_available : unit -> bool =
  "guestfs_int_daemon_optgroup_ntfs3g_available" "noalloc"
external ntfsprogs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_ntfsprogs_available" "noalloc"
external rsync_available : unit -> bool =
  "guestfs_int_daemon_optgroup_rsync_available" "noalloc"
external scrub_available : unit -> bool =
  "guestfs_int_daemon_optgroup_scrub_available" "noalloc"
external selinux_available : unit -> bool =
  "guestfs_int_daemon_optgroup_selinux_available" "noalloc"
external selinuxrelabel_available : unit -> bool =
  "guestfs_int_daemon_optgroup_selinuxrelabel_available" "noalloc"
external sleuthkit_available : unit -> bool =
  "guestfs_int_daemon_optgroup_sleuthkit_available" "noalloc"
external squashfs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_squashfs_available" "noalloc"
external syslinux_available : unit -> bool =
  "guestfs_int_daemon_optgroup_syslinux_available" "noalloc"
external wipefs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_wipefs_available" "noalloc"
external xfs_available : unit -> bool =
  "guestfs_int_daemon_optgroup_xfs_available" "noalloc"
external xz_available : unit -> bool =
  "guestfs_int_daemon_optgroup_xz_available" "noalloc"
external zerofree_available : unit -> bool =
  "guestfs_int_daemon_optgroup_zerofree_available" "noalloc"
