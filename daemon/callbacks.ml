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

let init_callbacks () =
  (* Initialize callbacks to OCaml code. *)
  Callback.register "Btrfs.btrfs_subvolume_get_default" Btrfs.btrfs_subvolume_get_default;
  Callback.register "Btrfs.btrfs_subvolume_list" Btrfs.btrfs_subvolume_list;
  Callback.register "Realpath.case_sensitive_path" Realpath.case_sensitive_path;
  Callback.register "Devsparts.device_index" Devsparts.device_index;
  Callback.register "File.file" File.file;
  Callback.register "Filearch.file_architecture" Filearch.file_architecture;
  Callback.register "Findfs.findfs_label" Findfs.findfs_label;
  Callback.register "Findfs.findfs_uuid" Findfs.findfs_uuid;
  Callback.register "Inspect.inspect_get_arch" Inspect.inspect_get_arch;
  Callback.register "Inspect.inspect_get_distro" Inspect.inspect_get_distro;
  Callback.register "Inspect.inspect_get_drive_mappings" Inspect.inspect_get_drive_mappings;
  Callback.register "Inspect.inspect_get_filesystems" Inspect.inspect_get_filesystems;
  Callback.register "Inspect.inspect_get_format" Inspect.inspect_get_format;
  Callback.register "Inspect.inspect_get_hostname" Inspect.inspect_get_hostname;
  Callback.register "Inspect.inspect_get_major_version" Inspect.inspect_get_major_version;
  Callback.register "Inspect.inspect_get_minor_version" Inspect.inspect_get_minor_version;
  Callback.register "Inspect.inspect_get_mountpoints" Inspect.inspect_get_mountpoints;
  Callback.register "Inspect.inspect_get_package_format" Inspect.inspect_get_package_format;
  Callback.register "Inspect.inspect_get_package_management" Inspect.inspect_get_package_management;
  Callback.register "Inspect.inspect_get_product_name" Inspect.inspect_get_product_name;
  Callback.register "Inspect.inspect_get_product_variant" Inspect.inspect_get_product_variant;
  Callback.register "Inspect.inspect_get_roots" Inspect.inspect_get_roots;
  Callback.register "Inspect.inspect_get_type" Inspect.inspect_get_type;
  Callback.register "Inspect.inspect_get_windows_current_control_set" Inspect.inspect_get_windows_current_control_set;
  Callback.register "Inspect.inspect_get_windows_software_hive" Inspect.inspect_get_windows_software_hive;
  Callback.register "Inspect.inspect_get_windows_system_hive" Inspect.inspect_get_windows_system_hive;
  Callback.register "Inspect.inspect_get_windows_systemroot" Inspect.inspect_get_windows_systemroot;
  Callback.register "Inspect.inspect_is_live" Inspect.inspect_is_live;
  Callback.register "Inspect.inspect_is_multipart" Inspect.inspect_is_multipart;
  Callback.register "Inspect.inspect_is_netinst" Inspect.inspect_is_netinst;
  Callback.register "Inspect.inspect_os" Inspect.inspect_os;
  Callback.register "Is.is_dir" Is.is_dir;
  Callback.register "Is.is_file" Is.is_file;
  Callback.register "Is.is_symlink" Is.is_symlink;
  Callback.register "Devsparts.is_whole_device" Devsparts.is_whole_device;
  Callback.register "Devsparts.list_devices" Devsparts.list_devices;
  Callback.register "Listfs.list_filesystems" Listfs.list_filesystems;
  Callback.register "Ldm.list_ldm_partitions" Ldm.list_ldm_partitions;
  Callback.register "Ldm.list_ldm_volumes" Ldm.list_ldm_volumes;
  Callback.register "Md.list_md_devices" Md.list_md_devices;
  Callback.register "Devsparts.list_partitions" Devsparts.list_partitions;
  Callback.register "Lvm.lvs" Lvm.lvs;
  Callback.register "Md.md_detail" Md.md_detail;
  Callback.register "Mount.mount" Mount.mount;
  Callback.register "Mount.mount_options" Mount.mount_options;
  Callback.register "Mount.mount_ro" Mount.mount_ro;
  Callback.register "Mount.mount_vfs" Mount.mount_vfs;
  Callback.register "Devsparts.nr_devices" Devsparts.nr_devices;
  Callback.register "Parted.part_get_gpt_attributes" Parted.part_get_gpt_attributes;
  Callback.register "Parted.part_get_gpt_guid" Parted.part_get_gpt_guid;
  Callback.register "Parted.part_get_gpt_type" Parted.part_get_gpt_type;
  Callback.register "Parted.part_get_mbr_id" Parted.part_get_mbr_id;
  Callback.register "Parted.part_get_mbr_part_type" Parted.part_get_mbr_part_type;
  Callback.register "Parted.part_get_parttype" Parted.part_get_parttype;
  Callback.register "Parted.part_list" Parted.part_list;
  Callback.register "Parted.part_set_gpt_attributes" Parted.part_set_gpt_attributes;
  Callback.register "Devsparts.part_to_dev" Devsparts.part_to_dev;
  Callback.register "Devsparts.part_to_partnum" Devsparts.part_to_partnum;
  Callback.register "Link.readlink" Link.readlink;
  Callback.register "Realpath.realpath" Realpath.realpath;
  Callback.register "Statvfs.statvfs" Statvfs.statvfs;
  Callback.register "Blkid.vfs_type" Blkid.vfs_type;
