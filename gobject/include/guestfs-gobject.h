/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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

#include <guestfs-gobject/session.h>
#include <guestfs-gobject/tristate.h>
#include <guestfs-gobject/struct-application.h>
#include <guestfs-gobject/struct-application2.h>
#include <guestfs-gobject/struct-btrfsbalance.h>
#include <guestfs-gobject/struct-btrfsqgroup.h>
#include <guestfs-gobject/struct-btrfsscrub.h>
#include <guestfs-gobject/struct-btrfssubvolume.h>
#include <guestfs-gobject/struct-dirent.h>
#include <guestfs-gobject/struct-hivex_node.h>
#include <guestfs-gobject/struct-hivex_value.h>
#include <guestfs-gobject/struct-inotify_event.h>
#include <guestfs-gobject/struct-int_bool.h>
#include <guestfs-gobject/struct-isoinfo.h>
#include <guestfs-gobject/struct-lvm_lv.h>
#include <guestfs-gobject/struct-lvm_pv.h>
#include <guestfs-gobject/struct-lvm_vg.h>
#include <guestfs-gobject/struct-mdstat.h>
#include <guestfs-gobject/struct-partition.h>
#include <guestfs-gobject/struct-stat.h>
#include <guestfs-gobject/struct-statns.h>
#include <guestfs-gobject/struct-statvfs.h>
#include <guestfs-gobject/struct-utsname.h>
#include <guestfs-gobject/struct-version.h>
#include <guestfs-gobject/struct-xattr.h>
#include <guestfs-gobject/struct-xfsinfo.h>
#include <guestfs-gobject/optargs-add_domain.h>
#include <guestfs-gobject/optargs-add_drive.h>
#include <guestfs-gobject/optargs-add_drive_scratch.h>
#include <guestfs-gobject/optargs-add_libvirt_dom.h>
#include <guestfs-gobject/optargs-btrfs_filesystem_defragment.h>
#include <guestfs-gobject/optargs-btrfs_filesystem_resize.h>
#include <guestfs-gobject/optargs-btrfs_fsck.h>
#include <guestfs-gobject/optargs-btrfs_image.h>
#include <guestfs-gobject/optargs-btrfs_subvolume_create.h>
#include <guestfs-gobject/optargs-btrfs_subvolume_snapshot.h>
#include <guestfs-gobject/optargs-compress_device_out.h>
#include <guestfs-gobject/optargs-compress_out.h>
#include <guestfs-gobject/optargs-copy_attributes.h>
#include <guestfs-gobject/optargs-copy_device_to_device.h>
#include <guestfs-gobject/optargs-copy_device_to_file.h>
#include <guestfs-gobject/optargs-copy_file_to_device.h>
#include <guestfs-gobject/optargs-copy_file_to_file.h>
#include <guestfs-gobject/optargs-cpio_out.h>
#include <guestfs-gobject/optargs-disk_create.h>
#include <guestfs-gobject/optargs-e2fsck.h>
#include <guestfs-gobject/optargs-fstrim.h>
#include <guestfs-gobject/optargs-grep.h>
#include <guestfs-gobject/optargs-hivex_open.h>
#include <guestfs-gobject/optargs-inspect_get_icon.h>
#include <guestfs-gobject/optargs-internal_test.h>
#include <guestfs-gobject/optargs-internal_test_63_optargs.h>
#include <guestfs-gobject/optargs-internal_test_only_optargs.h>
#include <guestfs-gobject/optargs-is_blockdev.h>
#include <guestfs-gobject/optargs-is_chardev.h>
#include <guestfs-gobject/optargs-is_dir.h>
#include <guestfs-gobject/optargs-is_fifo.h>
#include <guestfs-gobject/optargs-is_file.h>
#include <guestfs-gobject/optargs-is_socket.h>
#include <guestfs-gobject/optargs-md_create.h>
#include <guestfs-gobject/optargs-mke2fs.h>
#include <guestfs-gobject/optargs-mkfs.h>
#include <guestfs-gobject/optargs-mkfs_btrfs.h>
#include <guestfs-gobject/optargs-mkswap.h>
#include <guestfs-gobject/optargs-mktemp.h>
#include <guestfs-gobject/optargs-mount_9p.h>
#include <guestfs-gobject/optargs-mount_local.h>
#include <guestfs-gobject/optargs-ntfsclone_out.h>
#include <guestfs-gobject/optargs-ntfsfix.h>
#include <guestfs-gobject/optargs-ntfsresize.h>
#include <guestfs-gobject/optargs-remount.h>
#include <guestfs-gobject/optargs-rsync.h>
#include <guestfs-gobject/optargs-rsync_in.h>
#include <guestfs-gobject/optargs-rsync_out.h>
#include <guestfs-gobject/optargs-set_e2attrs.h>
#include <guestfs-gobject/optargs-syslinux.h>
#include <guestfs-gobject/optargs-tar_in.h>
#include <guestfs-gobject/optargs-tar_out.h>
#include <guestfs-gobject/optargs-tune2fs.h>
#include <guestfs-gobject/optargs-umount.h>
#include <guestfs-gobject/optargs-umount_local.h>
#include <guestfs-gobject/optargs-xfs_admin.h>
#include <guestfs-gobject/optargs-xfs_growfs.h>
#include <guestfs-gobject/optargs-xfs_repair.h>
