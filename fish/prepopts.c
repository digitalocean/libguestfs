/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

#include <config.h>

#include <stdio.h>

#include "fish.h"
#include "prepopts.h"

static struct prep_param disk_args[] = {
  { "size", "100M", "the size of the disk image" },
};

static struct prep_param part_args[] = {
  { "size", "100M", "the size of the disk image" },
  { "partition", "mbr", "partition table type" },
};

static struct prep_param fs_args[] = {
  { "filesystem", "ext2", "the type of filesystem to use" },
  { "size", "100M", "the size of the disk image" },
  { "partition", "mbr", "partition table type" },
};

static struct prep_param lv_args[] = {
  { "name", "/dev/VG/LV", "the name of the VG and LV to use" },
  { "size", "100M", "the size of the disk image" },
  { "partition", "mbr", "partition table type" },
};

static struct prep_param lvfs_args[] = {
  { "name", "/dev/VG/LV", "the name of the VG and LV to use" },
  { "filesystem", "ext2", "the type of filesystem to use" },
  { "size", "100M", "the size of the disk image" },
  { "partition", "mbr", "partition table type" },
};

static struct prep_param bootroot_args[] = {
  { "bootfs", "ext2", "the type of filesystem to use for boot" },
  { "rootfs", "ext2", "the type of filesystem to use for root" },
  { "size", "100M", "the size of the disk image" },
  { "bootsize", "32M", "the size of the boot filesystem" },
  { "partition", "mbr", "partition table type" },
};

static struct prep_param bootrootlv_args[] = {
  { "name", "/dev/VG/LV", "the name of the VG and LV for root" },
  { "bootfs", "ext2", "the type of filesystem to use for boot" },
  { "rootfs", "ext2", "the type of filesystem to use for root" },
  { "size", "100M", "the size of the disk image" },
  { "bootsize", "32M", "the size of the boot filesystem" },
  { "partition", "mbr", "partition table type" },
};

const struct prep preps[] = {
  { "disk", 1, disk_args,
    "create a blank disk",
    "  Create a blank disk, size 100MB (by default).\n\n  The default size can be changed by supplying an optional parameter.",
    prep_prelaunch_disk, prep_postlaunch_disk },
  { "part", 2, part_args,
    "create a partitioned disk",
    "  Create a disk with a single partition.  By default the size of the disk\n  is 100MB (the available space in the partition will be a tiny bit smaller)\n  and the partition table will be MBR (old DOS-style).\n\n  These defaults can be changed by supplying optional parameters.",
    prep_prelaunch_part, prep_postlaunch_part },
  { "fs", 3, fs_args,
    "create a filesystem",
    "  Create a disk with a single partition, with the partition containing\n  an empty filesystem.  This defaults to creating a 100MB disk (the available\n  space in the filesystem will be a tiny bit smaller) with an MBR (old\n  DOS-style) partition table and an ext2 filesystem.\n\n  These defaults can be changed by supplying optional parameters.",
    prep_prelaunch_fs, prep_postlaunch_fs },
  { "lv", 3, lv_args,
    "create a disk with logical volume",
    "  Create a disk with a single partition, set up the partition as an\n  LVM2 physical volume, and place a volume group and logical volume\n  on there.  This defaults to creating a 100MB disk with the VG and\n  LV called /dev/VG/LV.  You can change the name of the VG and LV\n  by supplying an alternate name as the first optional parameter.\n\n  Note this does not create a filesystem.  Use 'lvfs' to do that.",
    prep_prelaunch_lv, prep_postlaunch_lv },
  { "lvfs", 4, lvfs_args,
    "create a disk with logical volume and filesystem",
    "  Create a disk with a single partition, set up the partition as an\n  LVM2 physical volume, and place a volume group and logical volume\n  on there.  Then format the LV with a filesystem.  This defaults to\n  creating a 100MB disk with the VG and LV called /dev/VG/LV, with an\n  ext2 filesystem.",
    prep_prelaunch_lvfs, prep_postlaunch_lvfs },
  { "bootroot", 5, bootroot_args,
    "create a boot and root filesystem",
    "  Create a disk with two partitions, for boot and root filesystem.\n  Format the two filesystems independently.  There are several optional\n  parameters which control the exact layout and filesystem types.",
    prep_prelaunch_bootroot, prep_postlaunch_bootroot },
  { "bootrootlv", 6, bootrootlv_args,
    "create a boot and root filesystem using LVM",
    "  This is the same as 'bootroot' but the root filesystem (only) is\n  placed on a logical volume, named by default '/dev/VG/LV'.  There are\n  several optional parameters which control the exact layout.",
    prep_prelaunch_bootrootlv, prep_postlaunch_bootrootlv },
};
