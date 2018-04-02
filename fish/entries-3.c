/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
#include <stdlib.h>

#include "cmds-gperf.h"
#include "run.h"

struct command_entry acl_get_file_cmd_entry = {
  .name = "acl-get-file",
  .help = "NAME\n"
          "    acl-get-file - get the POSIX ACL attached to a file\n"
          "\n"
          "SYNOPSIS\n"
          "     acl-get-file path acltype\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns the POSIX Access Control List (ACL) attached to\n"
          "    \"path\". The ACL is returned in \"long text form\" (see acl(5)).\n"
          "\n"
          "    The \"acltype\" parameter may be:\n"
          "\n"
          "    \"access\"\n"
          "        Return the ordinary (access) ACL for any file, directory or other\n"
          "        filesystem object.\n"
          "\n"
          "    \"default\"\n"
          "        Return the default ACL. Normally this only makes sense if \"path\" is\n"
          "        a directory.\n"
          "\n"
          "",
  .synopsis = "acl-get-file path acltype",
  .run = run_acl_get_file
};

struct command_entry aug_close_cmd_entry = {
  .name = "aug-close",
  .help = "NAME\n"
          "    aug-close - close the current Augeas handle\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-close\n"
          "\n"
          "DESCRIPTION\n"
          "    Close the current Augeas handle and free up any resources used by it.\n"
          "    After calling this, you have to call \"aug_init\" again before you can use\n"
          "    any other Augeas functions.\n"
          "\n"
          "",
  .synopsis = "aug-close",
  .run = run_aug_close
};

struct command_entry aug_defnode_cmd_entry = {
  .name = "aug-defnode",
  .help = "NAME\n"
          "    aug-defnode - define an Augeas node\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-defnode name expr val\n"
          "\n"
          "DESCRIPTION\n"
          "    Defines a variable \"name\" whose value is the result of evaluating\n"
          "    \"expr\".\n"
          "\n"
          "    If \"expr\" evaluates to an empty nodeset, a node is created, equivalent\n"
          "    to calling \"aug_set\" \"expr\", \"value\". \"name\" will be the nodeset\n"
          "    containing that single node.\n"
          "\n"
          "    On success this returns a pair containing the number of nodes in the\n"
          "    nodeset, and a boolean flag if a node was created.\n"
          "\n"
          "",
  .synopsis = "aug-defnode name expr val",
  .run = run_aug_defnode
};

struct command_entry aug_get_cmd_entry = {
  .name = "aug-get",
  .help = "NAME\n"
          "    aug-get - look up the value of an Augeas path\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-get augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Look up the value associated with \"path\". If \"path\" matches exactly one\n"
          "    node, the \"value\" is returned.\n"
          "\n"
          "",
  .synopsis = "aug-get augpath",
  .run = run_aug_get
};

struct command_entry aug_save_cmd_entry = {
  .name = "aug-save",
  .help = "NAME\n"
          "    aug-save - write all pending Augeas changes to disk\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-save\n"
          "\n"
          "DESCRIPTION\n"
          "    This writes all pending changes to disk.\n"
          "\n"
          "    The flags which were passed to \"aug_init\" affect exactly how files are\n"
          "    saved.\n"
          "\n"
          "",
  .synopsis = "aug-save",
  .run = run_aug_save
};

struct command_entry aug_setm_cmd_entry = {
  .name = "aug-setm",
  .help = "NAME\n"
          "    aug-setm - set multiple Augeas nodes\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-setm base sub val\n"
          "\n"
          "DESCRIPTION\n"
          "    Change multiple Augeas nodes in a single operation. \"base\" is an\n"
          "    expression matching multiple nodes. \"sub\" is a path expression relative\n"
          "    to \"base\". All nodes matching \"base\" are found, and then for each node,\n"
          "    \"sub\" is changed to \"val\". \"sub\" may also be \"NULL\" in which case the\n"
          "    \"base\" nodes are modified.\n"
          "\n"
          "    This returns the number of nodes modified.\n"
          "\n"
          "",
  .synopsis = "aug-setm base sub val",
  .run = run_aug_setm
};

struct command_entry available_cmd_entry = {
  .name = "available",
  .help = "NAME\n"
          "    available - test availability of some parts of the API\n"
          "\n"
          "SYNOPSIS\n"
          "     available groups\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is used to check the availability of some groups of\n"
          "    functionality in the appliance, which not all builds of the libguestfs\n"
          "    appliance will be able to provide.\n"
          "\n"
          "    The libguestfs groups, and the functions that those groups correspond\n"
          "    to, are listed in \"AVAILABILITY\" in guestfs(3). You can also fetch this\n"
          "    list at runtime by calling \"available_all_groups\".\n"
          "\n"
          "    The argument \"groups\" is a list of group names, eg: \"[\"inotify\",\n"
          "    \"augeas\"]\" would check for the availability of the Linux inotify\n"
          "    functions and Augeas (configuration file editing) functions.\n"
          "\n"
          "    The command returns no error if *all* requested groups are available.\n"
          "\n"
          "    It fails with an error if one or more of the requested groups is\n"
          "    unavailable in the appliance.\n"
          "\n"
          "    If an unknown group name is included in the list of groups then an error\n"
          "    is always returned.\n"
          "\n"
          "    *Notes:*\n"
          "\n"
          "    *   \"feature_available\" is the same as this call, but with a slightly\n"
          "        simpler to use API: that call returns a boolean true/false instead\n"
          "        of throwing an error.\n"
          "\n"
          "    *   You must call \"launch\" before calling this function.\n"
          "\n"
          "        The reason is because we don't know what groups are supported by the\n"
          "        appliance/daemon until it is running and can be queried.\n"
          "\n"
          "    *   If a group of functions is available, this does not necessarily mean\n"
          "        that they will work. You still have to check for errors when calling\n"
          "        individual API functions even if they are available.\n"
          "\n"
          "    *   It is usually the job of distro packagers to build complete\n"
          "        functionality into the libguestfs appliance. Upstream libguestfs, if\n"
          "        built from source with all requirements satisfied, will support\n"
          "        everything.\n"
          "\n"
          "    *   This call was added in version 1.0.80. In previous versions of\n"
          "        libguestfs all you could do would be to speculatively execute a\n"
          "        command to find out if the daemon implemented it. See also\n"
          "        \"version\".\n"
          "\n"
          "    See also \"filesystem_available\".\n"
          "\n"
          "",
  .synopsis = "available groups",
  .run = run_available
};

struct command_entry blkdiscard_cmd_entry = {
  .name = "blkdiscard",
  .help = "NAME\n"
          "    blkdiscard - discard all blocks on a device\n"
          "\n"
          "SYNOPSIS\n"
          "     blkdiscard device\n"
          "\n"
          "DESCRIPTION\n"
          "    This discards all blocks on the block device \"device\", giving the free\n"
          "    space back to the host.\n"
          "\n"
          "    This operation requires support in libguestfs, the host filesystem, qemu\n"
          "    and the host kernel. If this support isn't present it may give an error\n"
          "    or even appear to run but do nothing. You must also set the \"discard\"\n"
          "    attribute on the underlying drive (see \"add_drive_opts\").\n"
          "\n"
          "",
  .synopsis = "blkdiscard device",
  .run = run_blkdiscard
};

struct command_entry blockdev_getsz_cmd_entry = {
  .name = "blockdev-getsz",
  .help = "NAME\n"
          "    blockdev-getsz - get total size of device in 512-byte sectors\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-getsz device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the size of the device in units of 512-byte sectors (even\n"
          "    if the sectorsize isn't 512 bytes ... weird).\n"
          "\n"
          "    See also \"blockdev_getss\" for the real sector size of the device, and\n"
          "    \"blockdev_getsize64\" for the more useful *size in bytes*.\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-getsz device",
  .run = run_blockdev_getsz
};

struct command_entry blockdev_setro_cmd_entry = {
  .name = "blockdev-setro",
  .help = "NAME\n"
          "    blockdev-setro - set block device to read-only\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-setro device\n"
          "\n"
          "DESCRIPTION\n"
          "    Sets the block device named \"device\" to read-only.\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-setro device",
  .run = run_blockdev_setro
};

struct command_entry btrfs_balance_status_cmd_entry = {
  .name = "btrfs-balance-status",
  .help = "NAME\n"
          "    btrfs-balance-status - show the status of a running or paused balance\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-balance-status path\n"
          "\n"
          "DESCRIPTION\n"
          "    Show the status of a running or paused balance on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-balance-status path",
  .run = run_btrfs_balance_status
};

struct command_entry btrfs_device_delete_cmd_entry = {
  .name = "btrfs-device-delete",
  .help = "NAME\n"
          "    btrfs-device-delete - remove devices from a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-device-delete devices fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove the \"devices\" from the btrfs filesystem mounted at \"fs\". If\n"
          "    \"devices\" is an empty list, this does nothing.\n"
          "\n"
          "",
  .synopsis = "btrfs-device-delete devices fs",
  .run = run_btrfs_device_delete
};

struct command_entry btrfs_filesystem_defragment_cmd_entry = {
  .name = "btrfs-filesystem-defragment",
  .help = "NAME\n"
          "    btrfs-filesystem-defragment - defragment a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-filesystem-defragment path [flush:true|false] [compress:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Defragment a file or directory on a btrfs filesystem. compress is one of\n"
          "    zlib or lzo.\n"
          "\n"
          "",
  .synopsis = "btrfs-filesystem-defragment path [flush:true|false] [compress:..]",
  .run = run_btrfs_filesystem_defragment
};

struct command_entry btrfs_filesystem_resize_cmd_entry = {
  .name = "btrfs-filesystem-resize",
  .help = "NAME\n"
          "    btrfs-filesystem-resize - resize a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-filesystem-resize mountpoint [size:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command resizes a btrfs filesystem.\n"
          "\n"
          "    Note that unlike other resize calls, the filesystem has to be mounted\n"
          "    and the parameter is the mountpoint not the device (this is a\n"
          "    requirement of btrfs itself).\n"
          "\n"
          "    The optional parameters are:\n"
          "\n"
          "    \"size\"\n"
          "        The new size (in bytes) of the filesystem. If omitted, the\n"
          "        filesystem is resized to the maximum size.\n"
          "\n"
          "    See also btrfs(8).\n"
          "\n"
          "",
  .synopsis = "btrfs-filesystem-resize mountpoint [size:N]",
  .run = run_btrfs_filesystem_resize
};

struct command_entry btrfs_filesystem_sync_cmd_entry = {
  .name = "btrfs-filesystem-sync",
  .help = "NAME\n"
          "    btrfs-filesystem-sync - sync a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-filesystem-sync fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Force sync on the btrfs filesystem mounted at \"fs\".\n"
          "\n"
          "",
  .synopsis = "btrfs-filesystem-sync fs",
  .run = run_btrfs_filesystem_sync
};

struct command_entry btrfs_image_cmd_entry = {
  .name = "btrfs-image",
  .help = "NAME\n"
          "    btrfs-image - create an image of a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-image source image [compresslevel:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    This is used to create an image of a btrfs filesystem. All data will be\n"
          "    zeroed, but metadata and the like is preserved.\n"
          "\n"
          "",
  .synopsis = "btrfs-image source image [compresslevel:N]",
  .run = run_btrfs_image
};

struct command_entry btrfs_qgroup_destroy_cmd_entry = {
  .name = "btrfs-qgroup-destroy",
  .help = "NAME\n"
          "    btrfs-qgroup-destroy - destroy a subvolume quota group\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-destroy qgroupid subvolume\n"
          "\n"
          "DESCRIPTION\n"
          "    Destroy a quota group.\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-destroy qgroupid subvolume",
  .run = run_btrfs_qgroup_destroy
};

struct command_entry btrfs_subvolume_delete_cmd_entry = {
  .name = "btrfs-subvolume-delete",
  .help = "NAME\n"
          "    btrfs-subvolume-delete - delete a btrfs subvolume or snapshot\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-delete subvolume\n"
          "\n"
          "DESCRIPTION\n"
          "    Delete the named btrfs subvolume or snapshot.\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-delete subvolume",
  .run = run_btrfs_subvolume_delete
};

struct command_entry btrfs_subvolume_list_cmd_entry = {
  .name = "btrfs-subvolume-list",
  .help = "NAME\n"
          "    btrfs-subvolume-list - list btrfs snapshots and subvolumes\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-list fs\n"
          "\n"
          "DESCRIPTION\n"
          "    List the btrfs snapshots and subvolumes of the btrfs filesystem which is\n"
          "    mounted at \"fs\".\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-list fs",
  .run = run_btrfs_subvolume_list
};

struct command_entry btrfstune_enable_skinny_metadata_extent_refs_cmd_entry = {
  .name = "btrfstune-enable-skinny-metadata-extent-refs",
  .help = "NAME\n"
          "    btrfstune-enable-skinny-metadata-extent-refs - enable skinny metadata\n"
          "    extent refs\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfstune-enable-skinny-metadata-extent-refs device\n"
          "\n"
          "DESCRIPTION\n"
          "    This enable skinny metadata extent refs.\n"
          "\n"
          "",
  .synopsis = "btrfstune-enable-skinny-metadata-extent-refs device",
  .run = run_btrfstune_enable_skinny_metadata_extent_refs
};

struct command_entry cap_get_file_cmd_entry = {
  .name = "cap-get-file",
  .help = "NAME\n"
          "    cap-get-file - get the Linux capabilities attached to a file\n"
          "\n"
          "SYNOPSIS\n"
          "     cap-get-file path\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns the Linux capabilities attached to \"path\". The\n"
          "    capabilities set is returned in text form (see cap_to_text(3)).\n"
          "\n"
          "    If no capabilities are attached to a file, an empty string is returned.\n"
          "\n"
          "",
  .synopsis = "cap-get-file path",
  .run = run_cap_get_file
};

struct command_entry checksum_cmd_entry = {
  .name = "checksum",
  .help = "NAME\n"
          "    checksum - compute MD5, SHAx or CRC checksum of file\n"
          "\n"
          "SYNOPSIS\n"
          "     checksum csumtype path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call computes the MD5, SHAx or CRC checksum of the file named\n"
          "    \"path\".\n"
          "\n"
          "    The type of checksum to compute is given by the \"csumtype\" parameter\n"
          "    which must have one of the following values:\n"
          "\n"
          "    \"crc\"\n"
          "        Compute the cyclic redundancy check (CRC) specified by POSIX for the\n"
          "        \"cksum\" command.\n"
          "\n"
          "    \"md5\"\n"
          "        Compute the MD5 hash (using the \"md5sum\" program).\n"
          "\n"
          "    \"sha1\"\n"
          "        Compute the SHA1 hash (using the \"sha1sum\" program).\n"
          "\n"
          "    \"sha224\"\n"
          "        Compute the SHA224 hash (using the \"sha224sum\" program).\n"
          "\n"
          "    \"sha256\"\n"
          "        Compute the SHA256 hash (using the \"sha256sum\" program).\n"
          "\n"
          "    \"sha384\"\n"
          "        Compute the SHA384 hash (using the \"sha384sum\" program).\n"
          "\n"
          "    \"sha512\"\n"
          "        Compute the SHA512 hash (using the \"sha512sum\" program).\n"
          "\n"
          "    The checksum is returned as a printable string.\n"
          "\n"
          "    To get the checksum for a device, use \"checksum_device\".\n"
          "\n"
          "    To get the checksums for many files, use \"checksums_out\".\n"
          "\n"
          "",
  .synopsis = "checksum csumtype path",
  .run = run_checksum
};

struct command_entry chmod_cmd_entry = {
  .name = "chmod",
  .help = "NAME\n"
          "    chmod - change file mode\n"
          "\n"
          "SYNOPSIS\n"
          "     chmod mode path\n"
          "\n"
          "DESCRIPTION\n"
          "    Change the mode (permissions) of \"path\" to \"mode\". Only numeric modes\n"
          "    are supported.\n"
          "\n"
          "    *Note*: When using this command from guestfish, \"mode\" by default would\n"
          "    be decimal, unless you prefix it with 0 to get octal, ie. use 0700 not\n"
          "    700.\n"
          "\n"
          "    The mode actually set is affected by the umask.\n"
          "\n"
          "",
  .synopsis = "chmod mode path",
  .run = run_chmod
};

struct command_entry disk_create_cmd_entry = {
  .name = "disk-create",
  .help = "NAME\n"
          "    disk-create - create a blank disk image\n"
          "\n"
          "SYNOPSIS\n"
          "     disk-create filename format size [backingfile:..] [backingformat:..] [preallocation:..] [compat:..] [clustersize:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a blank disk image called filename (a host file) with format\n"
          "    \"format\" (usually \"raw\" or \"qcow2\"). The size is \"size\" bytes.\n"
          "\n"
          "    If used with the optional \"backingfile\" parameter, then a snapshot is\n"
          "    created on top of the backing file. In this case, \"size\" must be passed\n"
          "    as -1. The size of the snapshot is the same as the size of the backing\n"
          "    file, which is discovered automatically. You are encouraged to also pass\n"
          "    \"backingformat\" to describe the format of \"backingfile\".\n"
          "\n"
          "    If filename refers to a block device, then the device is formatted. The\n"
          "    \"size\" is ignored since block devices have an intrinsic size.\n"
          "\n"
          "    The other optional parameters are:\n"
          "\n"
          "    \"preallocation\"\n"
          "        If format is \"raw\", then this can be either \"off\" (or \"sparse\") or\n"
          "        \"full\" to create a sparse or fully allocated file respectively. The\n"
          "        default is \"off\".\n"
          "\n"
          "        If format is \"qcow2\", then this can be \"off\" (or \"sparse\"),\n"
          "        \"metadata\" or \"full\". Preallocating metadata can be faster when\n"
          "        doing lots of writes, but uses more space. The default is \"off\".\n"
          "\n"
          "    \"compat\"\n"
          "        \"qcow2\" only: Pass the string 1.1 to use the advanced qcow2 format\n"
          "        supported by qemu ≥ 1.1.\n"
          "\n"
          "    \"clustersize\"\n"
          "        \"qcow2\" only: Change the qcow2 cluster size. The default is 65536\n"
          "        (bytes) and this setting may be any power of two between 512 and\n"
          "        2097152.\n"
          "\n"
          "    Note that this call does not add the new disk to the handle. You may\n"
          "    need to call \"add_drive_opts\" separately.\n"
          "\n"
          "",
  .synopsis = "disk-create filename format size [backingfile:..] [backingformat:..] [preallocation:..] [compat:..] [clustersize:N]",
  .run = run_disk_create
};

struct command_entry dmesg_cmd_entry = {
  .name = "dmesg",
  .help = "NAME\n"
          "    dmesg - return kernel messages\n"
          "\n"
          "SYNOPSIS\n"
          "     dmesg\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the kernel messages (\"dmesg\" output) from the guest kernel.\n"
          "    This is sometimes useful for extended debugging of problems.\n"
          "\n"
          "    Another way to get the same information is to enable verbose messages\n"
          "    with \"set_verbose\" or by setting the environment variable\n"
          "    \"LIBGUESTFS_DEBUG=1\" before running the program.\n"
          "\n"
          "",
  .synopsis = "dmesg",
  .run = run_dmesg
};

struct command_entry download_blocks_cmd_entry = {
  .name = "download-blocks",
  .help = "NAME\n"
          "    download-blocks - download the given data units from the disk\n"
          "\n"
          "SYNOPSIS\n"
          "     download-blocks device start stop filename [unallocated:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Download the data units from start address to stop from the disk\n"
          "    partition (eg. /dev/sda1) and save them as filename on the local\n"
          "    machine.\n"
          "\n"
          "    The use of this API on sparse disk image formats such as QCOW, may\n"
          "    result in large zero-filled files downloaded on the host.\n"
          "\n"
          "    The size of a data unit varies across filesystem implementations. On\n"
          "    NTFS filesystems data units are referred as clusters while on ExtX ones\n"
          "    they are referred as fragments.\n"
          "\n"
          "    If the optional \"unallocated\" flag is true (default is false), only the\n"
          "    unallocated blocks will be extracted. This is useful to detect hidden\n"
          "    data or to retrieve deleted files which data units have not been\n"
          "    overwritten yet.\n"
          "\n"
          "",
  .synopsis = "download-blocks device start stop filename [unallocated:true|false]",
  .run = run_download_blocks
};

struct command_entry du_cmd_entry = {
  .name = "du",
  .help = "NAME\n"
          "    du - estimate file space usage\n"
          "\n"
          "SYNOPSIS\n"
          "     du path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command runs the \"du -s\" command to estimate file space usage for\n"
          "    \"path\".\n"
          "\n"
          "    \"path\" can be a file or a directory. If \"path\" is a directory then the\n"
          "    estimate includes the contents of the directory and all subdirectories\n"
          "    (recursively).\n"
          "\n"
          "    The result is the estimated size in *kilobytes* (ie. units of 1024\n"
          "    bytes).\n"
          "\n"
          "",
  .synopsis = "du path",
  .run = run_du
};

struct command_entry e2fsck_f_cmd_entry = {
  .name = "e2fsck-f",
  .help = "NAME\n"
          "    e2fsck-f - check an ext2/ext3 filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     e2fsck-f device\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs \"e2fsck -p -f device\", ie. runs the ext2/ext3 filesystem\n"
          "    checker on \"device\", noninteractively (*-p*), even if the filesystem\n"
          "    appears to be clean (*-f*).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"e2fsck\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "e2fsck-f device",
  .run = run_e2fsck_f
};

struct command_entry echo_daemon_cmd_entry = {
  .name = "echo-daemon",
  .help = "NAME\n"
          "    echo-daemon - echo arguments back to the client\n"
          "\n"
          "SYNOPSIS\n"
          "     echo-daemon words\n"
          "\n"
          "DESCRIPTION\n"
          "    This command concatenates the list of \"words\" passed with single spaces\n"
          "    between them and returns the resulting string.\n"
          "\n"
          "    You can use this command to test the connection through to the daemon.\n"
          "\n"
          "    See also \"ping_daemon\".\n"
          "\n"
          "",
  .synopsis = "echo-daemon words",
  .run = run_echo_daemon
};

struct command_entry equal_cmd_entry = {
  .name = "equal",
  .help = "NAME\n"
          "    equal - test if two files have equal contents\n"
          "\n"
          "SYNOPSIS\n"
          "     equal file1 file2\n"
          "\n"
          "DESCRIPTION\n"
          "    This compares the two files file1 and file2 and returns true if their\n"
          "    content is exactly equal, or false otherwise.\n"
          "\n"
          "    The external cmp(1) program is used for the comparison.\n"
          "\n"
          "",
  .synopsis = "equal file1 file2",
  .run = run_equal
};

struct command_entry fgrepi_cmd_entry = {
  .name = "fgrepi",
  .help = "NAME\n"
          "    fgrepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     fgrepi pattern path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"fgrep -i\" program and returns the matching\n"
          "    lines.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"grep\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "fgrepi pattern path",
  .run = run_fgrepi
};

struct command_entry get_backend_setting_cmd_entry = {
  .name = "get-backend-setting",
  .help = "NAME\n"
          "    get-backend-setting - get a single per-backend settings string\n"
          "\n"
          "SYNOPSIS\n"
          "     get-backend-setting name\n"
          "\n"
          "DESCRIPTION\n"
          "    Find a backend setting string which is either \"name\" or begins with\n"
          "    \"name=\". If \"name\", this returns the string \"1\". If \"name=\", this\n"
          "    returns the part after the equals sign (which may be an empty string).\n"
          "\n"
          "    If no such setting is found, this function throws an error. The errno\n"
          "    (see \"last_errno\") will be \"ESRCH\" in this case.\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3), \"BACKEND SETTINGS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "get-backend-setting name",
  .run = run_get_backend_setting
};

struct command_entry get_backend_settings_cmd_entry = {
  .name = "get-backend-settings",
  .help = "NAME\n"
          "    get-backend-settings - get per-backend settings\n"
          "\n"
          "SYNOPSIS\n"
          "     get-backend-settings\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current backend settings.\n"
          "\n"
          "    This call returns all backend settings strings. If you want to find a\n"
          "    single backend setting, see \"get_backend_setting\".\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3), \"BACKEND SETTINGS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "get-backend-settings",
  .run = run_get_backend_settings
};

struct command_entry get_e2label_cmd_entry = {
  .name = "get-e2label",
  .help = "NAME\n"
          "    get-e2label - get the ext2/3/4 filesystem label\n"
          "\n"
          "SYNOPSIS\n"
          "     get-e2label device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the ext2/3/4 filesystem label of the filesystem on\n"
          "    \"device\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"vfs-label\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "get-e2label device",
  .run = run_get_e2label
};

struct command_entry get_recovery_proc_cmd_entry = {
  .name = "get-recovery-proc",
  .help = "NAME\n"
          "    get-recovery-proc - get recovery process enabled flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-recovery-proc\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the recovery process enabled flag.\n"
          "\n"
          "",
  .synopsis = "get-recovery-proc",
  .run = run_get_recovery_proc
};

struct command_entry get_tmpdir_cmd_entry = {
  .name = "get-tmpdir",
  .help = "NAME\n"
          "    get-tmpdir - get the temporary directory\n"
          "\n"
          "SYNOPSIS\n"
          "     get-tmpdir\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the directory used by the handle to store temporary files.\n"
          "\n"
          "",
  .synopsis = "get-tmpdir",
  .run = run_get_tmpdir
};

struct command_entry getcon_cmd_entry = {
  .name = "getcon",
  .help = "NAME\n"
          "    getcon - get SELinux security context\n"
          "\n"
          "SYNOPSIS\n"
          "     getcon\n"
          "\n"
          "DESCRIPTION\n"
          "    This gets the SELinux security context of the daemon.\n"
          "\n"
          "    See the documentation about SELINUX in guestfs(3), and \"setcon\"\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"selinux-relabel\"\n"
          "    call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "getcon",
  .run = run_getcon
};

struct command_entry getxattr_cmd_entry = {
  .name = "getxattr",
  .help = "NAME\n"
          "    getxattr - get a single extended attribute\n"
          "\n"
          "SYNOPSIS\n"
          "     getxattr path name\n"
          "\n"
          "DESCRIPTION\n"
          "    Get a single extended attribute from file \"path\" named \"name\". This call\n"
          "    follows symlinks. If you want to lookup an extended attribute for the\n"
          "    symlink itself, use \"lgetxattr\".\n"
          "\n"
          "    Normally it is better to get all extended attributes from a file in one\n"
          "    go by calling \"getxattrs\". However some Linux filesystem implementations\n"
          "    are buggy and do not provide a way to list out attributes. For these\n"
          "    filesystems (notably ntfs-3g) you have to know the names of the extended\n"
          "    attributes you want in advance and call this function.\n"
          "\n"
          "    Extended attribute values are blobs of binary data. If there is no\n"
          "    extended attribute named \"name\", this returns an error.\n"
          "\n"
          "    See also: \"getxattrs\", \"lgetxattr\", attr(5).\n"
          "\n"
          "",
  .synopsis = "getxattr path name",
  .run = run_getxattr
};

struct command_entry hivex_close_cmd_entry = {
  .name = "hivex-close",
  .help = "NAME\n"
          "    hivex-close - close the current hivex handle\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-close\n"
          "\n"
          "DESCRIPTION\n"
          "    Close the current hivex handle.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-close",
  .run = run_hivex_close
};

struct command_entry hivex_open_cmd_entry = {
  .name = "hivex-open",
  .help = "NAME\n"
          "    hivex-open - open a Windows Registry hive file\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-open filename [verbose:true|false] [debug:true|false] [write:true|false] [unsafe:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Open the Windows Registry hive file named filename. If there was any\n"
          "    previous hivex handle associated with this guestfs session, then it is\n"
          "    closed.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-open filename [verbose:true|false] [debug:true|false] [write:true|false] [unsafe:true|false]",
  .run = run_hivex_open
};

struct command_entry hivex_value_utf8_cmd_entry = {
  .name = "hivex-value-utf8",
  .help = "NAME\n"
          "    hivex-value-utf8 - return the data field as a UTF-8 string\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-value-utf8 valueh\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls \"hivex_value_value\" (which returns the data field from a\n"
          "    hivex value tuple). It then assumes that the field is a UTF-16LE string\n"
          "    and converts the result to UTF-8 (or if this is not possible, it returns\n"
          "    an error).\n"
          "\n"
          "    This is useful for reading strings out of the Windows registry. However\n"
          "    it is not foolproof because the registry is not strongly-typed and\n"
          "    fields can contain arbitrary or unexpected data.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"hivex-value-string\"\n"
          "    call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "hivex-value-utf8 valueh",
  .run = run_hivex_value_utf8
};

struct command_entry inotify_add_watch_cmd_entry = {
  .name = "inotify-add-watch",
  .help = "NAME\n"
          "    inotify-add-watch - add an inotify watch\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-add-watch path mask\n"
          "\n"
          "DESCRIPTION\n"
          "    Watch \"path\" for the events listed in \"mask\".\n"
          "\n"
          "    Note that if \"path\" is a directory then events within that directory are\n"
          "    watched, but this does *not* happen recursively (in subdirectories).\n"
          "\n"
          "    Note for non-C or non-Linux callers: the inotify events are defined by\n"
          "    the Linux kernel ABI and are listed in /usr/include/sys/inotify.h.\n"
          "\n"
          "",
  .synopsis = "inotify-add-watch path mask",
  .run = run_inotify_add_watch
};

struct command_entry inotify_init_cmd_entry = {
  .name = "inotify-init",
  .help = "NAME\n"
          "    inotify-init - create an inotify handle\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-init maxevents\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a new inotify handle. The inotify subsystem can be\n"
          "    used to notify events which happen to objects in the guest filesystem.\n"
          "\n"
          "    \"maxevents\" is the maximum number of events which will be queued up\n"
          "    between calls to \"inotify_read\" or \"inotify_files\". If this is passed as\n"
          "    0, then the kernel (or previously set) default is used. For Linux 2.6.29\n"
          "    the default was 16384 events. Beyond this limit, the kernel throws away\n"
          "    events, but records the fact that it threw them away by setting a flag\n"
          "    \"IN_Q_OVERFLOW\" in the returned structure list (see \"inotify_read\").\n"
          "\n"
          "    Before any events are generated, you have to add some watches to the\n"
          "    internal watch list. See: \"inotify_add_watch\" and \"inotify_rm_watch\".\n"
          "\n"
          "    Queued up events should be read periodically by calling \"inotify_read\"\n"
          "    (or \"inotify_files\" which is just a helpful wrapper around\n"
          "    \"inotify_read\"). If you don't read the events out often enough then you\n"
          "    risk the internal queue overflowing.\n"
          "\n"
          "    The handle should be closed after use by calling \"inotify_close\". This\n"
          "    also removes any watches automatically.\n"
          "\n"
          "    See also inotify(7) for an overview of the inotify interface as exposed\n"
          "    by the Linux kernel, which is roughly what we expose via libguestfs.\n"
          "    Note that there is one global inotify handle per libguestfs instance.\n"
          "\n"
          "",
  .synopsis = "inotify-init maxevents",
  .run = run_inotify_init
};

struct command_entry inspect_get_type_cmd_entry = {
  .name = "inspect-get-type",
  .help = "NAME\n"
          "    inspect-get-type - get type of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-type root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the type of the inspected operating system. Currently\n"
          "    defined types are:\n"
          "\n"
          "    \"linux\"\n"
          "        Any Linux-based operating system.\n"
          "\n"
          "    \"windows\"\n"
          "        Any Microsoft Windows operating system.\n"
          "\n"
          "    \"freebsd\"\n"
          "        FreeBSD.\n"
          "\n"
          "    \"netbsd\"\n"
          "        NetBSD.\n"
          "\n"
          "    \"openbsd\"\n"
          "        OpenBSD.\n"
          "\n"
          "    \"hurd\"\n"
          "        GNU/Hurd.\n"
          "\n"
          "    \"dos\"\n"
          "        MS-DOS, FreeDOS and others.\n"
          "\n"
          "    \"minix\"\n"
          "        MINIX.\n"
          "\n"
          "    \"unknown\"\n"
          "        The operating system type could not be determined.\n"
          "\n"
          "    Future versions of libguestfs may return other strings here. The caller\n"
          "    should be prepared to handle any string.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-type root",
  .run = run_inspect_get_type
};

struct command_entry inspect_is_live_cmd_entry = {
  .name = "inspect-is-live",
  .help = "NAME\n"
          "    inspect-is-live - get live flag for install disk\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-is-live root\n"
          "\n"
          "DESCRIPTION\n"
          "    This is deprecated and always returns \"false\".\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "    *This function is deprecated.* There is no replacement. Consult the API\n"
          "    documentation in guestfs(3) for further information.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "inspect-is-live root",
  .run = run_inspect_is_live
};

struct command_entry internal_exit_cmd_entry = {
  .name = "internal-exit",
  .help = "NAME\n"
          "    internal-exit - cause the daemon to exit (internal use only)\n"
          "\n"
          "SYNOPSIS\n"
          "     internal-exit\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is used internally when testing the appliance.\n"
          "\n"
          "",
  .synopsis = "internal-exit",
  .run = run_internal_exit
};

struct command_entry is_dir_cmd_entry = {
  .name = "is-dir",
  .help = "NAME\n"
          "    is-dir - test if a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     is-dir path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a directory with the given\n"
          "    \"path\" name. Note that it returns false for other objects like files.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a directory also causes the function to\n"
          "    return true.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-dir-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-dir path [followsymlinks:true|false]",
  .run = run_is_dir
};

struct command_entry is_file_cmd_entry = {
  .name = "is-file",
  .help = "NAME\n"
          "    is-file - test if a regular file\n"
          "\n"
          "SYNOPSIS\n"
          "     is-file path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a regular file with the\n"
          "    given \"path\" name. Note that it returns false for other objects like\n"
          "    directories.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a file also causes the function to return\n"
          "    true.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-file-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-file path [followsymlinks:true|false]",
  .run = run_is_file
};

struct command_entry is_whole_device_cmd_entry = {
  .name = "is-whole-device",
  .help = "NAME\n"
          "    is-whole-device - test if a device is a whole device\n"
          "\n"
          "SYNOPSIS\n"
          "     is-whole-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if \"device\" refers to a whole block\n"
          "    device. That is, not a partition or a logical device.\n"
          "\n"
          "",
  .synopsis = "is-whole-device device",
  .run = run_is_whole_device
};

struct command_entry is_zero_device_cmd_entry = {
  .name = "is-zero-device",
  .help = "NAME\n"
          "    is-zero-device - test if a device contains all zero bytes\n"
          "\n"
          "SYNOPSIS\n"
          "     is-zero-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns true iff the device exists and contains all zero bytes.\n"
          "\n"
          "    Note that for large devices this can take a long time to run.\n"
          "\n"
          "",
  .synopsis = "is-zero-device device",
  .run = run_is_zero_device
};

struct command_entry journal_get_realtime_usec_cmd_entry = {
  .name = "journal-get-realtime-usec",
  .help = "NAME\n"
          "    journal-get-realtime-usec - get the timestamp of the current journal\n"
          "    entry\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-get-realtime-usec\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the realtime (wallclock) timestamp of the current journal entry.\n"
          "\n"
          "",
  .synopsis = "journal-get-realtime-usec",
  .run = run_journal_get_realtime_usec
};

struct command_entry journal_set_data_threshold_cmd_entry = {
  .name = "journal-set-data-threshold",
  .help = "NAME\n"
          "    journal-set-data-threshold - set the data threshold for reading journal\n"
          "    entries\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-set-data-threshold threshold\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the data threshold for reading journal entries. This is a hint to\n"
          "    the journal that it may truncate data fields to this size when reading\n"
          "    them (note also that it may not truncate them). If you set this to 0,\n"
          "    then the threshold is unlimited.\n"
          "\n"
          "    See also \"journal_get_data_threshold\".\n"
          "\n"
          "",
  .synopsis = "journal-set-data-threshold threshold",
  .run = run_journal_set_data_threshold
};

struct command_entry launch_cmd_entry = {
  .name = "launch",
  .help = "NAME\n"
          "    launch - launch the backend\n"
          "\n"
          "SYNOPSIS\n"
          "     launch\n"
          "\n"
          "DESCRIPTION\n"
          "    You should call this after configuring the handle (eg. adding drives)\n"
          "    but before performing any actions.\n"
          "\n"
          "    Do not call \"launch\" twice on the same handle. Although it will not give\n"
          "    an error (for historical reasons), the precise behaviour when you do\n"
          "    this is not well defined. Handles are very cheap to create, so create a\n"
          "    new one for each launch.\n"
          "\n"
          "    You can use 'run' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "launch",
  .run = run_launch
};

struct command_entry ldmtool_remove_all_cmd_entry = {
  .name = "ldmtool-remove-all",
  .help = "NAME\n"
          "    ldmtool-remove-all - remove all Windows dynamic disk volumes\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-remove-all\n"
          "\n"
          "DESCRIPTION\n"
          "    This is essentially the opposite of \"ldmtool_create_all\". It removes the\n"
          "    device mapper mappings for all Windows dynamic disk volumes\n"
          "\n"
          "",
  .synopsis = "ldmtool-remove-all",
  .run = run_ldmtool_remove_all
};

struct command_entry ldmtool_volume_hint_cmd_entry = {
  .name = "ldmtool-volume-hint",
  .help = "NAME\n"
          "    ldmtool-volume-hint - return the hint field of a Windows dynamic disk\n"
          "    volume\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-volume-hint diskgroup volume\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the hint field of the volume named \"volume\" in the disk group\n"
          "    with GUID \"diskgroup\". This may not be defined, in which case the empty\n"
          "    string is returned. The hint field is often, though not always, the name\n"
          "    of a Windows drive, eg. \"E:\".\n"
          "\n"
          "",
  .synopsis = "ldmtool-volume-hint diskgroup volume",
  .run = run_ldmtool_volume_hint
};

struct command_entry ldmtool_volume_type_cmd_entry = {
  .name = "ldmtool-volume-type",
  .help = "NAME\n"
          "    ldmtool-volume-type - return the type of a Windows dynamic disk volume\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-volume-type diskgroup volume\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the type of the volume named \"volume\" in the disk group with GUID\n"
          "    \"diskgroup\".\n"
          "\n"
          "    Possible volume types that can be returned here include: \"simple\",\n"
          "    \"spanned\", \"striped\", \"mirrored\", \"raid5\". Other types may also be\n"
          "    returned.\n"
          "\n"
          "",
  .synopsis = "ldmtool-volume-type diskgroup volume",
  .run = run_ldmtool_volume_type
};

struct command_entry list_devices_cmd_entry = {
  .name = "list-devices",
  .help = "NAME\n"
          "    list-devices - list the block devices\n"
          "\n"
          "SYNOPSIS\n"
          "     list-devices\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the block devices.\n"
          "\n"
          "    The full block device names are returned, eg. /dev/sda.\n"
          "\n"
          "    See also \"list_filesystems\".\n"
          "\n"
          "",
  .synopsis = "list-devices",
  .run = run_list_devices
};

struct command_entry list_filesystems_cmd_entry = {
  .name = "list-filesystems",
  .help = "NAME\n"
          "    list-filesystems - list filesystems\n"
          "\n"
          "SYNOPSIS\n"
          "     list-filesystems\n"
          "\n"
          "DESCRIPTION\n"
          "    This inspection command looks for filesystems on partitions, block\n"
          "    devices and logical volumes, returning a list of \"mountables\" containing\n"
          "    filesystems and their type.\n"
          "\n"
          "    The return value is a hash, where the keys are the devices containing\n"
          "    filesystems, and the values are the filesystem types. For example:\n"
          "\n"
          "     \"/dev/sda1\" => \"ntfs\"\n"
          "     \"/dev/sda2\" => \"ext2\"\n"
          "     \"/dev/vg_guest/lv_root\" => \"ext4\"\n"
          "     \"/dev/vg_guest/lv_swap\" => \"swap\"\n"
          "\n"
          "    The key is not necessarily a block device. It may also be an opaque\n"
          "    ‘mountable’ string which can be passed to \"mount\".\n"
          "\n"
          "    The value can have the special value \"unknown\", meaning the content of\n"
          "    the device is undetermined or empty. \"swap\" means a Linux swap\n"
          "    partition.\n"
          "\n"
          "    In libguestfs ≤ 1.36 this command ran other libguestfs commands, which\n"
          "    might have included \"mount\" and \"umount\", and therefore you had to use\n"
          "    this soon after launch and only when nothing else was mounted. This\n"
          "    restriction is removed in libguestfs ≥ 1.38.\n"
          "\n"
          "    Not all of the filesystems returned will be mountable. In particular,\n"
          "    swap partitions are returned in the list. Also this command does not\n"
          "    check that each filesystem found is valid and mountable, and some\n"
          "    filesystems might be mountable but require special options. Filesystems\n"
          "    may not all belong to a single logical operating system (use\n"
          "    \"inspect_os\" to look for OSes).\n"
          "\n"
          "",
  .synopsis = "list-filesystems",
  .run = run_list_filesystems
};

struct command_entry ls_cmd_entry = {
  .name = "ls",
  .help = "NAME\n"
          "    ls - list the files in a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     ls directory\n"
          "\n"
          "DESCRIPTION\n"
          "    List the files in directory (relative to the root directory, there is no\n"
          "    cwd). The '.' and '..' entries are not returned, but hidden files are\n"
          "    shown.\n"
          "\n"
          "",
  .synopsis = "ls directory",
  .run = run_ls
};

struct command_entry ls0_cmd_entry = {
  .name = "ls0",
  .help = "NAME\n"
          "    ls0 - get list of files in a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     ls0 dir filenames\n"
          "\n"
          "DESCRIPTION\n"
          "    This specialized command is used to get a listing of the filenames in\n"
          "    the directory \"dir\". The list of filenames is written to the local file\n"
          "    filenames (on the host).\n"
          "\n"
          "    In the output file, the filenames are separated by \"\\0\" characters.\n"
          "\n"
          "    \".\" and \"..\" are not returned. The filenames are not sorted.\n"
          "\n"
          "",
  .synopsis = "ls0 dir filenames",
  .run = run_ls0
};

struct command_entry lstatns_cmd_entry = {
  .name = "lstatns",
  .help = "NAME\n"
          "    lstatns - get file information for a symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     lstatns path\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns file information for the given \"path\".\n"
          "\n"
          "    This is the same as \"statns\" except that if \"path\" is a symbolic link,\n"
          "    then the link is stat-ed, not the file it refers to.\n"
          "\n"
          "    This is the same as the lstat(2) system call.\n"
          "\n"
          "",
  .synopsis = "lstatns path",
  .run = run_lstatns
};

struct command_entry lxattrlist_cmd_entry = {
  .name = "lxattrlist",
  .help = "NAME\n"
          "    lxattrlist - lgetxattr on multiple files\n"
          "\n"
          "SYNOPSIS\n"
          "     lxattrlist path names\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to get the extended attributes of multiple files,\n"
          "    where all files are in the directory \"path\". \"names\" is the list of\n"
          "    files from this directory.\n"
          "\n"
          "    On return you get a flat list of xattr structs which must be interpreted\n"
          "    sequentially. The first xattr struct always has a zero-length\n"
          "    \"attrname\". \"attrval\" in this struct is zero-length to indicate there\n"
          "    was an error doing \"lgetxattr\" for this file, *or* is a C string which\n"
          "    is a decimal number (the number of following attributes for this file,\n"
          "    which could be \"0\"). Then after the first xattr struct are the zero or\n"
          "    more attributes for the first named file. This repeats for the second\n"
          "    and subsequent files.\n"
          "\n"
          "    This call is intended for programs that want to efficiently list a\n"
          "    directory contents without making many round-trips. See also \"lstatlist\"\n"
          "    for a similarly efficient call for getting standard stats.\n"
          "\n"
          "",
  .synopsis = "lxattrlist path names",
  .run = run_lxattrlist
};

struct command_entry mkdir_mode_cmd_entry = {
  .name = "mkdir-mode",
  .help = "NAME\n"
          "    mkdir-mode - create a directory with a particular mode\n"
          "\n"
          "SYNOPSIS\n"
          "     mkdir-mode path mode\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a directory, setting the initial permissions of the\n"
          "    directory to \"mode\".\n"
          "\n"
          "    For common Linux filesystems, the actual mode which is set will be \"mode\n"
          "    & ~umask & 01777\". Non-native-Linux filesystems may interpret the mode\n"
          "    in other ways.\n"
          "\n"
          "    See also \"mkdir\", \"umask\"\n"
          "\n"
          "",
  .synopsis = "mkdir-mode path mode",
  .run = run_mkdir_mode
};

struct command_entry mkdir_p_cmd_entry = {
  .name = "mkdir-p",
  .help = "NAME\n"
          "    mkdir-p - create a directory and parents\n"
          "\n"
          "SYNOPSIS\n"
          "     mkdir-p path\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a directory named \"path\", creating any parent directories as\n"
          "    necessary. This is like the \"mkdir -p\" shell command.\n"
          "\n"
          "",
  .synopsis = "mkdir-p path",
  .run = run_mkdir_p
};

struct command_entry mke2fs_cmd_entry = {
  .name = "mke2fs",
  .help = "NAME\n"
          "    mke2fs - create an ext2/ext3/ext4 filesystem on device\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2fs device [blockscount:N] [blocksize:N] [fragsize:N] [blockspergroup:N] [numberofgroups:N] [bytesperinode:N] [inodesize:N] [journalsize:N] [numberofinodes:N] [stridesize:N] [stripewidth:N] [maxonlineresize:N] [reservedblockspercentage:N] [mmpupdateinterval:N] [journaldevice:..] [label:..] [lastmounteddir:..] [creatoros:..] [fstype:..] [usagetype:..] [uuid:..] [forcecreate:true|false] [writesbandgrouponly:true|false] [lazyitableinit:true|false] [lazyjournalinit:true|false] [testfs:true|false] [discard:true|false] [quotatype:true|false] [extent:true|false] [filetype:true|false] [flexbg:true|false] [hasjournal:true|false] [journaldev:true|false] [largefile:true|false] [quota:true|false] [resizeinode:true|false] [sparsesuper:true|false] [uninitbg:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    \"mke2fs\" is used to create an ext2, ext3, or ext4 filesystem on\n"
          "    \"device\".\n"
          "\n"
          "    The optional \"blockscount\" is the size of the filesystem in blocks. If\n"
          "    omitted it defaults to the size of \"device\". Note if the filesystem is\n"
          "    too small to contain a journal, \"mke2fs\" will silently create an ext2\n"
          "    filesystem instead.\n"
          "\n"
          "",
  .synopsis = "mke2fs device [blockscount:N] [blocksize:N] [fragsize:N] [blockspergroup:N] [numberofgroups:N] [bytesperinode:N] [inodesize:N] [journalsize:N] [numberofinodes:N] [stridesize:N] [stripewidth:N] [maxonlineresize:N] [reservedblockspercentage:N] [mmpupdateinterval:N] [journaldevice:..] [label:..] [lastmounteddir:..] [creatoros:..] [fstype:..] [usagetype:..] [uuid:..] [forcecreate:true|false] [writesbandgrouponly:true|false] [lazyitableinit:true|false] [lazyjournalinit:true|false] [testfs:true|false] [discard:true|false] [quotatype:true|false] [extent:true|false] [filetype:true|false] [flexbg:true|false] [hasjournal:true|false] [journaldev:true|false] [largefile:true|false] [quota:true|false] [resizeinode:true|false] [sparsesuper:true|false] [uninitbg:true|false]",
  .run = run_mke2fs
};

struct command_entry mke2fs_JL_cmd_entry = {
  .name = "mke2fs-JL",
  .help = "NAME\n"
          "    mke2fs-JL - make ext2/3/4 filesystem with external journal\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2fs-JL fstype blocksize device label\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n"
          "    on the journal labeled \"label\".\n"
          "\n"
          "    See also \"mke2journal_L\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2fs-JL fstype blocksize device label",
  .run = run_mke2fs_JL
};

struct command_entry mke2fs_JU_cmd_entry = {
  .name = "mke2fs-JU",
  .help = "NAME\n"
          "    mke2fs-JU - make ext2/3/4 filesystem with external journal\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2fs-JU fstype blocksize device uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n"
          "    on the journal with UUID \"uuid\".\n"
          "\n"
          "    See also \"mke2journal_U\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2fs-JU fstype blocksize device uuid",
  .run = run_mke2fs_JU
};

struct command_entry mke2journal_cmd_entry = {
  .name = "mke2journal",
  .help = "NAME\n"
          "    mke2journal - make ext2/3/4 external journal\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2journal blocksize device\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2 external journal on \"device\". It is equivalent to\n"
          "    the command:\n"
          "\n"
          "     mke2fs -O journal_dev -b blocksize device\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2journal blocksize device",
  .run = run_mke2journal
};

struct command_entry mknod_b_cmd_entry = {
  .name = "mknod-b",
  .help = "NAME\n"
          "    mknod-b - make block device node\n"
          "\n"
          "SYNOPSIS\n"
          "     mknod-b mode devmajor devminor path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates a block device node called \"path\" with mode \"mode\" and\n"
          "    device major/minor \"devmajor\" and \"devminor\". It is just a convenient\n"
          "    wrapper around \"mknod\".\n"
          "\n"
          "    Unlike with \"mknod\", \"mode\" must contain only permissions bits.\n"
          "\n"
          "    The mode actually set is affected by the umask.\n"
          "\n"
          "",
  .synopsis = "mknod-b mode devmajor devminor path",
  .run = run_mknod_b
};

struct command_entry mount_local_cmd_entry = {
  .name = "mount-local",
  .help = "NAME\n"
          "    mount-local - mount on the local filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-local localmountpoint [readonly:true|false] [options:..] [cachetimeout:N] [debugcalls:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call exports the libguestfs-accessible filesystem to a local\n"
          "    mountpoint (directory) called \"localmountpoint\". Ordinary reads and\n"
          "    writes to files and directories under \"localmountpoint\" are redirected\n"
          "    through libguestfs.\n"
          "\n"
          "    If the optional \"readonly\" flag is set to true, then writes to the\n"
          "    filesystem return error \"EROFS\".\n"
          "\n"
          "    \"options\" is a comma-separated list of mount options. See guestmount(1)\n"
          "    for some useful options.\n"
          "\n"
          "    \"cachetimeout\" sets the timeout (in seconds) for cached directory\n"
          "    entries. The default is 60 seconds. See guestmount(1) for further\n"
          "    information.\n"
          "\n"
          "    If \"debugcalls\" is set to true, then additional debugging information is\n"
          "    generated for every FUSE call.\n"
          "\n"
          "    When \"mount_local\" returns, the filesystem is ready, but is not\n"
          "    processing requests (access to it will block). You have to call\n"
          "    \"mount_local_run\" to run the main loop.\n"
          "\n"
          "    See \"MOUNT LOCAL\" in guestfs(3) for full documentation.\n"
          "\n"
          "",
  .synopsis = "mount-local localmountpoint [readonly:true|false] [options:..] [cachetimeout:N] [debugcalls:true|false]",
  .run = run_mount_local
};

struct command_entry ntfsresize_size_cmd_entry = {
  .name = "ntfsresize-size",
  .help = "NAME\n"
          "    ntfsresize-size - resize an NTFS filesystem (with size)\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfsresize-size device size\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is the same as \"ntfsresize\" except that it allows you to\n"
          "    specify the new size (in bytes) explicitly.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"ntfsresize\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "ntfsresize-size device size",
  .run = run_ntfsresize_size
};

struct command_entry part_del_cmd_entry = {
  .name = "part-del",
  .help = "NAME\n"
          "    part-del - delete a partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-del device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    This command deletes the partition numbered \"partnum\" on \"device\".\n"
          "\n"
          "    Note that in the case of MBR partitioning, deleting an extended\n"
          "    partition also deletes any logical partitions it contains.\n"
          "\n"
          "",
  .synopsis = "part-del device partnum",
  .run = run_part_del
};

struct command_entry part_get_gpt_type_cmd_entry = {
  .name = "part-get-gpt-type",
  .help = "NAME\n"
          "    part-get-gpt-type - get the type GUID of a GPT partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-gpt-type device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the type GUID of numbered GPT partition \"partnum\". For MBR\n"
          "    partitions, return an appropriate GUID corresponding to the MBR type.\n"
          "    Behaviour is undefined for other partition types.\n"
          "\n"
          "",
  .synopsis = "part-get-gpt-type device partnum",
  .run = run_part_get_gpt_type
};

struct command_entry ping_daemon_cmd_entry = {
  .name = "ping-daemon",
  .help = "NAME\n"
          "    ping-daemon - ping the guest daemon\n"
          "\n"
          "SYNOPSIS\n"
          "     ping-daemon\n"
          "\n"
          "DESCRIPTION\n"
          "    This is a test probe into the guestfs daemon running inside the\n"
          "    libguestfs appliance. Calling this function checks that the daemon\n"
          "    responds to the ping message, without affecting the daemon or attached\n"
          "    block device(s) in any other way.\n"
          "\n"
          "",
  .synopsis = "ping-daemon",
  .run = run_ping_daemon
};

struct command_entry remove_drive_cmd_entry = {
  .name = "remove-drive",
  .help = "NAME\n"
          "    remove-drive - remove a disk image\n"
          "\n"
          "SYNOPSIS\n"
          "     remove-drive label\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is conceptually the opposite of \"add_drive_opts\". It\n"
          "    removes the drive that was previously added with label \"label\".\n"
          "\n"
          "    Note that in order to remove drives, you have to add them with labels\n"
          "    (see the optional \"label\" argument to \"add_drive_opts\"). If you didn't\n"
          "    use a label, then they cannot be removed.\n"
          "\n"
          "    You can call this function before or after launching the handle. If\n"
          "    called after launch, if the backend supports it, we try to hot unplug\n"
          "    the drive: see \"HOTPLUGGING\" in guestfs(3). The disk must not be in use\n"
          "    (eg. mounted) when you do this. We try to detect if the disk is in use\n"
          "    and stop you from doing this.\n"
          "\n"
          "",
  .synopsis = "remove-drive label",
  .run = run_remove_drive
};

struct command_entry rm_cmd_entry = {
  .name = "rm",
  .help = "NAME\n"
          "    rm - remove a file\n"
          "\n"
          "SYNOPSIS\n"
          "     rm path\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove the single file \"path\".\n"
          "\n"
          "",
  .synopsis = "rm path",
  .run = run_rm
};

struct command_entry rmdir_cmd_entry = {
  .name = "rmdir",
  .help = "NAME\n"
          "    rmdir - remove a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     rmdir path\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove the single directory \"path\".\n"
          "\n"
          "",
  .synopsis = "rmdir path",
  .run = run_rmdir
};

struct command_entry rsync_cmd_entry = {
  .name = "rsync",
  .help = "NAME\n"
          "    rsync - synchronize the contents of two directories\n"
          "\n"
          "SYNOPSIS\n"
          "     rsync src dest [archive:true|false] [deletedest:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call may be used to copy or synchronize two directories under the\n"
          "    same libguestfs handle. This uses the rsync(1) program which uses a fast\n"
          "    algorithm that avoids copying files unnecessarily.\n"
          "\n"
          "    \"src\" and \"dest\" are the source and destination directories. Files are\n"
          "    copied from \"src\" to \"dest\".\n"
          "\n"
          "    The optional arguments are:\n"
          "\n"
          "    \"archive\"\n"
          "        Turns on archive mode. This is the same as passing the *--archive*\n"
          "        flag to \"rsync\".\n"
          "\n"
          "    \"deletedest\"\n"
          "        Delete files at the destination that do not exist at the source.\n"
          "\n"
          "",
  .synopsis = "rsync src dest [archive:true|false] [deletedest:true|false]",
  .run = run_rsync
};

struct command_entry set_backend_settings_cmd_entry = {
  .name = "set-backend-settings",
  .help = "NAME\n"
          "    set-backend-settings - replace per-backend settings strings\n"
          "\n"
          "SYNOPSIS\n"
          "     set-backend-settings settings\n"
          "\n"
          "DESCRIPTION\n"
          "    Set a list of zero or more settings which are passed through to the\n"
          "    current backend. Each setting is a string which is interpreted in a\n"
          "    backend-specific way, or ignored if not understood by the backend.\n"
          "\n"
          "    The default value is an empty list, unless the environment variable\n"
          "    \"LIBGUESTFS_BACKEND_SETTINGS\" was set when the handle was created. This\n"
          "    environment variable contains a colon-separated list of settings.\n"
          "\n"
          "    This call replaces all backend settings. If you want to replace a single\n"
          "    backend setting, see \"set_backend_setting\". If you want to clear a\n"
          "    single backend setting, see \"clear_backend_setting\".\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3), \"BACKEND SETTINGS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "set-backend-settings settings",
  .run = run_set_backend_settings
};

struct command_entry set_hv_cmd_entry = {
  .name = "set-hv",
  .help = "NAME\n"
          "    set-hv - set the hypervisor binary\n"
          "\n"
          "SYNOPSIS\n"
          "     set-hv hv\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the hypervisor binary that we will use. The hypervisor depends on\n"
          "    the backend, but is usually the location of the qemu/KVM hypervisor. For\n"
          "    the uml backend, it is the location of the \"linux\" or \"vmlinux\" binary.\n"
          "\n"
          "    The default is chosen when the library was compiled by the configure\n"
          "    script.\n"
          "\n"
          "    You can also override this by setting the \"LIBGUESTFS_HV\" environment\n"
          "    variable.\n"
          "\n"
          "    Note that you should call this function as early as possible after\n"
          "    creating the handle. This is because some pre-launch operations depend\n"
          "    on testing qemu features (by running \"qemu -help\"). If the qemu binary\n"
          "    changes, we don't retest features, and so you might see inconsistent\n"
          "    results. Using the environment variable \"LIBGUESTFS_HV\" is safest of all\n"
          "    since that picks the qemu binary at the same time as the handle is\n"
          "    created.\n"
          "\n"
          "    You can use 'hv' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-hv hv",
  .run = run_set_hv
};

struct command_entry set_qemu_cmd_entry = {
  .name = "set-qemu",
  .help = "NAME\n"
          "    set-qemu - set the hypervisor binary (usually qemu)\n"
          "\n"
          "SYNOPSIS\n"
          "     set-qemu hv\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the hypervisor binary (usually qemu) that we will use.\n"
          "\n"
          "    The default is chosen when the library was compiled by the configure\n"
          "    script.\n"
          "\n"
          "    You can also override this by setting the \"LIBGUESTFS_HV\" environment\n"
          "    variable.\n"
          "\n"
          "    Setting \"hv\" to \"NULL\" restores the default qemu binary.\n"
          "\n"
          "    Note that you should call this function as early as possible after\n"
          "    creating the handle. This is because some pre-launch operations depend\n"
          "    on testing qemu features (by running \"qemu -help\"). If the qemu binary\n"
          "    changes, we don't retest features, and so you might see inconsistent\n"
          "    results. Using the environment variable \"LIBGUESTFS_HV\" is safest of all\n"
          "    since that picks the qemu binary at the same time as the handle is\n"
          "    created.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"set-hv\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "    You can use 'qemu' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-qemu hv",
  .run = run_set_qemu
};

struct command_entry set_recovery_proc_cmd_entry = {
  .name = "set-recovery-proc",
  .help = "NAME\n"
          "    set-recovery-proc - enable or disable the recovery process\n"
          "\n"
          "SYNOPSIS\n"
          "     set-recovery-proc recoveryproc\n"
          "\n"
          "DESCRIPTION\n"
          "    If this is called with the parameter \"false\" then \"launch\" does not\n"
          "    create a recovery process. The purpose of the recovery process is to\n"
          "    stop runaway hypervisor processes in the case where the main program\n"
          "    aborts abruptly.\n"
          "\n"
          "    This only has any effect if called before \"launch\", and the default is\n"
          "    true.\n"
          "\n"
          "    About the only time when you would want to disable this is if the main\n"
          "    process will fork itself into the background (\"daemonize\" itself). In\n"
          "    this case the recovery process thinks that the main program has\n"
          "    disappeared and so kills the hypervisor, which is not very helpful.\n"
          "\n"
          "    You can use 'recovery-proc' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-recovery-proc recoveryproc",
  .run = run_set_recovery_proc
};

struct command_entry set_uuid_cmd_entry = {
  .name = "set-uuid",
  .help = "NAME\n"
          "    set-uuid - set the filesystem UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     set-uuid device uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the filesystem UUID on \"device\" to \"uuid\". If this fails and the\n"
          "    errno is ENOTSUP, means that there is no support for changing the UUID\n"
          "    for the type of the specified filesystem.\n"
          "\n"
          "    Only some filesystem types support setting UUIDs.\n"
          "\n"
          "    To read the UUID on a filesystem, call \"vfs_uuid\".\n"
          "\n"
          "",
  .synopsis = "set-uuid device uuid",
  .run = run_set_uuid
};

struct command_entry setcon_cmd_entry = {
  .name = "setcon",
  .help = "NAME\n"
          "    setcon - set SELinux security context\n"
          "\n"
          "SYNOPSIS\n"
          "     setcon context\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the SELinux security context of the daemon to the string\n"
          "    \"context\".\n"
          "\n"
          "    See the documentation about SELINUX in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"selinux-relabel\"\n"
          "    call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "setcon context",
  .run = run_setcon
};

struct command_entry statvfs_cmd_entry = {
  .name = "statvfs",
  .help = "NAME\n"
          "    statvfs - get file system statistics\n"
          "\n"
          "SYNOPSIS\n"
          "     statvfs path\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns file system statistics for any mounted file system. \"path\"\n"
          "    should be a file or directory in the mounted file system (typically it\n"
          "    is the mount point itself, but it doesn't need to be).\n"
          "\n"
          "    This is the same as the statvfs(2) system call.\n"
          "\n"
          "",
  .synopsis = "statvfs path",
  .run = run_statvfs
};

struct command_entry strings_cmd_entry = {
  .name = "strings",
  .help = "NAME\n"
          "    strings - print the printable strings in a file\n"
          "\n"
          "SYNOPSIS\n"
          "     strings path\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs the strings(1) command on a file and returns the list of\n"
          "    printable strings found.\n"
          "\n"
          "    The \"strings\" command has, in the past, had problems with parsing\n"
          "    untrusted files. These are mitigated in the current version of\n"
          "    libguestfs, but see \"CVE-2014-8484\" in guestfs(3).\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "strings path",
  .run = run_strings
};

struct command_entry swapoff_label_cmd_entry = {
  .name = "swapoff-label",
  .help = "NAME\n"
          "    swapoff-label - disable swap on labeled swap partition\n"
          "\n"
          "SYNOPSIS\n"
          "     swapoff-label label\n"
          "\n"
          "DESCRIPTION\n"
          "    This command disables the libguestfs appliance swap on labeled swap\n"
          "    partition.\n"
          "\n"
          "",
  .synopsis = "swapoff-label label",
  .run = run_swapoff_label
};

struct command_entry swapoff_uuid_cmd_entry = {
  .name = "swapoff-uuid",
  .help = "NAME\n"
          "    swapoff-uuid - disable swap on swap partition by UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     swapoff-uuid uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    This command disables the libguestfs appliance swap partition with the\n"
          "    given UUID.\n"
          "\n"
          "",
  .synopsis = "swapoff-uuid uuid",
  .run = run_swapoff_uuid
};

struct command_entry tar_in_cmd_entry = {
  .name = "tar-in",
  .help = "NAME\n"
          "    tar-in - unpack tarfile to directory\n"
          "\n"
          "SYNOPSIS\n"
          "     tar-in tarfile directory [compress:..] [xattrs:true|false] [selinux:true|false] [acls:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command uploads and unpacks local file \"tarfile\" into directory.\n"
          "\n"
          "    The optional \"compress\" flag controls compression. If not given, then\n"
          "    the input should be an uncompressed tar file. Otherwise one of the\n"
          "    following strings may be given to select the compression type of the\n"
          "    input file: \"compress\", \"gzip\", \"bzip2\", \"xz\", \"lzop\". (Note that not\n"
          "    all builds of libguestfs will support all of these compression types).\n"
          "\n"
          "    The other optional arguments are:\n"
          "\n"
          "    \"xattrs\"\n"
          "        If set to true, extended attributes are restored from the tar file.\n"
          "\n"
          "    \"selinux\"\n"
          "        If set to true, SELinux contexts are restored from the tar file.\n"
          "\n"
          "    \"acls\"\n"
          "        If set to true, POSIX ACLs are restored from the tar file.\n"
          "\n"
          "    You can use 'tar-in-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "tar-in tarfile directory [compress:..] [xattrs:true|false] [selinux:true|false] [acls:true|false]",
  .run = run_tar_in
};

struct command_entry truncate_cmd_entry = {
  .name = "truncate",
  .help = "NAME\n"
          "    truncate - truncate a file to zero size\n"
          "\n"
          "SYNOPSIS\n"
          "     truncate path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command truncates \"path\" to a zero-length file. The file must exist\n"
          "    already.\n"
          "\n"
          "",
  .synopsis = "truncate path",
  .run = run_truncate
};

struct command_entry tune2fs_cmd_entry = {
  .name = "tune2fs",
  .help = "NAME\n"
          "    tune2fs - adjust ext2/ext3/ext4 filesystem parameters\n"
          "\n"
          "SYNOPSIS\n"
          "     tune2fs device [force:true|false] [maxmountcount:N] [mountcount:N] [errorbehavior:..] [group:N] [intervalbetweenchecks:N] [reservedblockspercentage:N] [lastmounteddirectory:..] [reservedblockscount:N] [user:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to adjust various filesystem parameters of an\n"
          "    ext2/ext3/ext4 filesystem called \"device\".\n"
          "\n"
          "    The optional parameters are:\n"
          "\n"
          "    \"force\"\n"
          "        Force tune2fs to complete the operation even in the face of errors.\n"
          "        This is the same as the tune2fs \"-f\" option.\n"
          "\n"
          "    \"maxmountcount\"\n"
          "        Set the number of mounts after which the filesystem is checked by\n"
          "        e2fsck(8). If this is 0 then the number of mounts is disregarded.\n"
          "        This is the same as the tune2fs \"-c\" option.\n"
          "\n"
          "    \"mountcount\"\n"
          "        Set the number of times the filesystem has been mounted. This is the\n"
          "        same as the tune2fs \"-C\" option.\n"
          "\n"
          "    \"errorbehavior\"\n"
          "        Change the behavior of the kernel code when errors are detected.\n"
          "        Possible values currently are: \"continue\", \"remount-ro\", \"panic\". In\n"
          "        practice these options don't really make any difference,\n"
          "        particularly for write errors.\n"
          "\n"
          "        This is the same as the tune2fs \"-e\" option.\n"
          "\n"
          "    \"group\"\n"
          "        Set the group which can use reserved filesystem blocks. This is the\n"
          "        same as the tune2fs \"-g\" option except that it can only be specified\n"
          "        as a number.\n"
          "\n"
          "    \"intervalbetweenchecks\"\n"
          "        Adjust the maximal time between two filesystem checks (in seconds).\n"
          "        If the option is passed as 0 then time-dependent checking is\n"
          "        disabled.\n"
          "\n"
          "        This is the same as the tune2fs \"-i\" option.\n"
          "\n"
          "    \"reservedblockspercentage\"\n"
          "        Set the percentage of the filesystem which may only be allocated by\n"
          "        privileged processes. This is the same as the tune2fs \"-m\" option.\n"
          "\n"
          "    \"lastmounteddirectory\"\n"
          "        Set the last mounted directory. This is the same as the tune2fs \"-M\"\n"
          "        option.\n"
          "\n"
          "    \"reservedblockscount\" Set the number of reserved filesystem blocks. This\n"
          "    is the same as the tune2fs \"-r\" option.\n"
          "    \"user\"\n"
          "        Set the user who can use the reserved filesystem blocks. This is the\n"
          "        same as the tune2fs \"-u\" option except that it can only be specified\n"
          "        as a number.\n"
          "\n"
          "    To get the current values of filesystem parameters, see \"tune2fs_l\". For\n"
          "    precise details of how tune2fs works, see the tune2fs(8) man page.\n"
          "\n"
          "",
  .synopsis = "tune2fs device [force:true|false] [maxmountcount:N] [mountcount:N] [errorbehavior:..] [group:N] [intervalbetweenchecks:N] [reservedblockspercentage:N] [lastmounteddirectory:..] [reservedblockscount:N] [user:N]",
  .run = run_tune2fs
};

struct command_entry upload_cmd_entry = {
  .name = "upload",
  .help = "NAME\n"
          "    upload - upload a file from the local machine\n"
          "\n"
          "SYNOPSIS\n"
          "     upload filename remotefilename\n"
          "\n"
          "DESCRIPTION\n"
          "    Upload local file filename to remotefilename on the filesystem.\n"
          "\n"
          "    filename can also be a named pipe.\n"
          "\n"
          "    See also \"download\".\n"
          "\n"
          "",
  .synopsis = "upload filename remotefilename",
  .run = run_upload
};

struct command_entry utimens_cmd_entry = {
  .name = "utimens",
  .help = "NAME\n"
          "    utimens - set timestamp of a file with nanosecond precision\n"
          "\n"
          "SYNOPSIS\n"
          "     utimens path atsecs atnsecs mtsecs mtnsecs\n"
          "\n"
          "DESCRIPTION\n"
          "    This command sets the timestamps of a file with nanosecond precision.\n"
          "\n"
          "    \"atsecs, atnsecs\" are the last access time (atime) in secs and\n"
          "    nanoseconds from the epoch.\n"
          "\n"
          "    \"mtsecs, mtnsecs\" are the last modification time (mtime) in secs and\n"
          "    nanoseconds from the epoch.\n"
          "\n"
          "    If the *nsecs field contains the special value -1 then the corresponding\n"
          "    timestamp is set to the current time. (The *secs field is ignored in\n"
          "    this case).\n"
          "\n"
          "    If the *nsecs field contains the special value -2 then the corresponding\n"
          "    timestamp is left unchanged. (The *secs field is ignored in this case).\n"
          "\n"
          "",
  .synopsis = "utimens path atsecs atnsecs mtsecs mtnsecs",
  .run = run_utimens
};

struct command_entry version_cmd_entry = {
  .name = "version",
  .help = "NAME\n"
          "    version - get the library version number\n"
          "\n"
          "SYNOPSIS\n"
          "     version\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the libguestfs version number that the program is linked against.\n"
          "\n"
          "    Note that because of dynamic linking this is not necessarily the version\n"
          "    of libguestfs that you compiled against. You can compile the program,\n"
          "    and then at runtime dynamically link against a completely different\n"
          "    libguestfs.so library.\n"
          "\n"
          "    This call was added in version 1.0.58. In previous versions of\n"
          "    libguestfs there was no way to get the version number. From C code you\n"
          "    can use dynamic linker functions to find out if this symbol exists (if\n"
          "    it doesn't, then it’s an earlier version).\n"
          "\n"
          "    The call returns a structure with four elements. The first three\n"
          "    (\"major\", \"minor\" and \"release\") are numbers and correspond to the usual\n"
          "    version triplet. The fourth element (\"extra\") is a string and is\n"
          "    normally empty, but may be used for distro-specific information.\n"
          "\n"
          "    To construct the original version string: \"$major.$minor.$release$extra\"\n"
          "\n"
          "    See also: \"LIBGUESTFS VERSION NUMBERS\" in guestfs(3).\n"
          "\n"
          "    *Note:* Don't use this call to test for availability of features. In\n"
          "    enterprise distributions we backport features from later versions into\n"
          "    earlier versions, making this an unreliable way to test for features.\n"
          "    Use \"available\" or \"feature_available\" instead.\n"
          "\n"
          "",
  .synopsis = "version",
  .run = run_version
};

struct command_entry vfs_minimum_size_cmd_entry = {
  .name = "vfs-minimum-size",
  .help = "NAME\n"
          "    vfs-minimum-size - get minimum filesystem size\n"
          "\n"
          "SYNOPSIS\n"
          "     vfs-minimum-size mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the minimum size of filesystem in bytes. This is the minimum\n"
          "    possible size for filesystem shrinking.\n"
          "\n"
          "    If getting minimum size of specified filesystem is not supported, this\n"
          "    will fail and set errno as ENOTSUP.\n"
          "\n"
          "    See also ntfsresize(8), resize2fs(8), btrfs(8), xfs_info(8).\n"
          "\n"
          "",
  .synopsis = "vfs-minimum-size mountable",
  .run = run_vfs_minimum_size
};

struct command_entry vfs_uuid_cmd_entry = {
  .name = "vfs-uuid",
  .help = "NAME\n"
          "    vfs-uuid - get the filesystem UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     vfs-uuid mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the filesystem UUID of the filesystem on \"mountable\".\n"
          "\n"
          "    If the filesystem does not have a UUID, this returns the empty string.\n"
          "\n"
          "    To find a filesystem from the UUID, use \"findfs_uuid\".\n"
          "\n"
          "    You can use 'get-uuid' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "vfs-uuid mountable",
  .run = run_vfs_uuid
};

struct command_entry vgs_cmd_entry = {
  .name = "vgs",
  .help = "NAME\n"
          "    vgs - list the LVM volume groups (VGs)\n"
          "\n"
          "SYNOPSIS\n"
          "     vgs\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the volumes groups detected. This is the equivalent of the\n"
          "    vgs(8) command.\n"
          "\n"
          "    This returns a list of just the volume group names that were detected\n"
          "    (eg. \"VolGroup00\").\n"
          "\n"
          "    See also \"vgs_full\".\n"
          "\n"
          "",
  .synopsis = "vgs",
  .run = run_vgs
};

struct command_entry write_file_cmd_entry = {
  .name = "write-file",
  .help = "NAME\n"
          "    write-file - create a file\n"
          "\n"
          "SYNOPSIS\n"
          "     write-file path content size\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates a file called \"path\". The contents of the file is the\n"
          "    string \"content\" (which can contain any 8 bit data), with length \"size\".\n"
          "\n"
          "    As a special case, if \"size\" is 0 then the length is calculated using\n"
          "    \"strlen\" (so in this case the content cannot contain embedded ASCII\n"
          "    NULs).\n"
          "\n"
          "    *NB.* Owing to a bug, writing content containing ASCII NUL characters\n"
          "    does *not* work, even if the length is specified.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"write\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "write-file path content size",
  .run = run_write_file
};

struct command_entry zero_cmd_entry = {
  .name = "zero",
  .help = "NAME\n"
          "    zero - write zeroes to the device\n"
          "\n"
          "SYNOPSIS\n"
          "     zero device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes zeroes over the first few blocks of \"device\".\n"
          "\n"
          "    How many blocks are zeroed isn't specified (but it’s *not* enough to\n"
          "    securely wipe the device). It should be sufficient to remove any\n"
          "    partition tables, filesystem superblocks and so on.\n"
          "\n"
          "    If blocks are already zero, then this command avoids writing zeroes.\n"
          "    This prevents the underlying device from becoming non-sparse or growing\n"
          "    unnecessarily.\n"
          "\n"
          "    See also: \"zero_device\", \"scrub_device\", \"is_zero_device\"\n"
          "\n"
          "",
  .synopsis = "zero device",
  .run = run_zero
};

struct command_entry zerofree_cmd_entry = {
  .name = "zerofree",
  .help = "NAME\n"
          "    zerofree - zero unused inodes and disk blocks on ext2/3 filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     zerofree device\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs the *zerofree* program on \"device\". This program claims to\n"
          "    zero unused inodes and disk blocks on an ext2/3 filesystem, thus making\n"
          "    it possible to compress the filesystem more effectively.\n"
          "\n"
          "    You should not run this program if the filesystem is mounted.\n"
          "\n"
          "    It is possible that using this program can damage the filesystem or data\n"
          "    on the filesystem.\n"
          "\n"
          "",
  .synopsis = "zerofree device",
  .run = run_zerofree
};

struct command_entry zgrepi_cmd_entry = {
  .name = "zgrepi",
  .help = "NAME\n"
          "    zgrepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zgrepi regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zgrep -i\" program and returns the matching\n"
          "    lines.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"grep\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "zgrepi regex path",
  .run = run_zgrepi
};

