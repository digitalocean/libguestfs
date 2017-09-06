/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

struct command_entry aug_mv_cmd_entry = {
  .name = "aug-mv",
  .help = "NAME\n"
          "    aug-mv - move Augeas node\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-mv src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    Move the node \"src\" to \"dest\". \"src\" must match exactly one node. \"dest\"\n"
          "    is overwritten if it exists.\n"
          "\n"
          "",
  .synopsis = "aug-mv src dest",
  .run = run_aug_mv
};

struct command_entry available_all_groups_cmd_entry = {
  .name = "available-all-groups",
  .help = "NAME\n"
          "    available-all-groups - return a list of all optional groups\n"
          "\n"
          "SYNOPSIS\n"
          "     available-all-groups\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns a list of all optional groups that this daemon\n"
          "    knows about. Note this returns both supported and unsupported groups. To\n"
          "    find out which ones the daemon can actually support you have to call\n"
          "    \"available\" / \"feature_available\" on each member of the returned list.\n"
          "\n"
          "    See also \"available\", \"feature_available\" and \"AVAILABILITY\" in\n"
          "    guestfs(3).\n"
          "\n"
          "",
  .synopsis = "available-all-groups",
  .run = run_available_all_groups
};

struct command_entry blockdev_getbsz_cmd_entry = {
  .name = "blockdev-getbsz",
  .help = "NAME\n"
          "    blockdev-getbsz - get blocksize of block device\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-getbsz device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the block size of a device.\n"
          "\n"
          "    Note: this is different from both *size in blocks* and *filesystem block\n"
          "    size*. Also this setting is not really used by anything. You should\n"
          "    probably not use it for anything. Filesystems have their own idea about\n"
          "    what block size to choose.\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-getbsz device",
  .run = run_blockdev_getbsz
};

struct command_entry blockdev_getro_cmd_entry = {
  .name = "blockdev-getro",
  .help = "NAME\n"
          "    blockdev-getro - is block device set to read-only\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-getro device\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns a boolean indicating if the block device is read-only (true if\n"
          "    read-only, false if not).\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-getro device",
  .run = run_blockdev_getro
};

struct command_entry blockdev_setbsz_cmd_entry = {
  .name = "blockdev-setbsz",
  .help = "NAME\n"
          "    blockdev-setbsz - set blocksize of block device\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-setbsz device blocksize\n"
          "\n"
          "DESCRIPTION\n"
          "    This call does nothing and has never done anything because of a bug in\n"
          "    blockdev. Do not use it.\n"
          "\n"
          "    If you need to set the filesystem block size, use the \"blocksize\" option\n"
          "    of \"mkfs\".\n"
          "\n"
          "    *This function is deprecated.* There is no replacement. Consult the API\n"
          "    documentation in guestfs(3) for further information.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "blockdev-setbsz device blocksize",
  .run = run_blockdev_setbsz
};

struct command_entry btrfs_qgroup_remove_cmd_entry = {
  .name = "btrfs-qgroup-remove",
  .help = "NAME\n"
          "    btrfs-qgroup-remove - remove a qgroup from its parent qgroup\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-remove src dst path\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove qgroup \"src\" from the parent qgroup \"dst\".\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-remove src dst path",
  .run = run_btrfs_qgroup_remove
};

struct command_entry btrfs_quota_enable_cmd_entry = {
  .name = "btrfs-quota-enable",
  .help = "NAME\n"
          "    btrfs-quota-enable - enable or disable subvolume quota support\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-quota-enable fs enable\n"
          "\n"
          "DESCRIPTION\n"
          "    Enable or disable subvolume quota support for filesystem which contains\n"
          "    \"path\".\n"
          "\n"
          "",
  .synopsis = "btrfs-quota-enable fs enable",
  .run = run_btrfs_quota_enable
};

struct command_entry checksums_out_cmd_entry = {
  .name = "checksums-out",
  .help = "NAME\n"
          "    checksums-out - compute MD5, SHAx or CRC checksum of files in a\n"
          "    directory\n"
          "\n"
          "SYNOPSIS\n"
          "     checksums-out csumtype directory sumsfile\n"
          "\n"
          "DESCRIPTION\n"
          "    This command computes the checksums of all regular files in directory\n"
          "    and then emits a list of those checksums to the local output file\n"
          "    \"sumsfile\".\n"
          "\n"
          "    This can be used for verifying the integrity of a virtual machine.\n"
          "    However to be properly secure you should pay attention to the output of\n"
          "    the checksum command (it uses the ones from GNU coreutils). In\n"
          "    particular when the filename is not printable, coreutils uses a special\n"
          "    backslash syntax. For more information, see the GNU coreutils info file.\n"
          "\n"
          "",
  .synopsis = "checksums-out csumtype directory sumsfile",
  .run = run_checksums_out
};

struct command_entry cp_a_cmd_entry = {
  .name = "cp-a",
  .help = "NAME\n"
          "    cp-a - copy a file or directory recursively\n"
          "\n"
          "SYNOPSIS\n"
          "     cp-a src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    This copies a file or directory from \"src\" to \"dest\" recursively using\n"
          "    the \"cp -a\" command.\n"
          "\n"
          "",
  .synopsis = "cp-a src dest",
  .run = run_cp_a
};

struct command_entry df_cmd_entry = {
  .name = "df",
  .help = "NAME\n"
          "    df - report file system disk space usage\n"
          "\n"
          "SYNOPSIS\n"
          "     df\n"
          "\n"
          "DESCRIPTION\n"
          "    This command runs the \"df\" command to report disk space used.\n"
          "\n"
          "    This command is mostly useful for interactive sessions. It is *not*\n"
          "    intended that you try to parse the output string. Use \"statvfs\" from\n"
          "    programs.\n"
          "\n"
          "",
  .synopsis = "df",
  .run = run_df
};

struct command_entry disk_format_cmd_entry = {
  .name = "disk-format",
  .help = "NAME\n"
          "    disk-format - detect the disk format of a disk image\n"
          "\n"
          "SYNOPSIS\n"
          "     disk-format filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Detect and return the format of the disk image called filename. filename\n"
          "    can also be a host device, etc. If the format of the image could not be\n"
          "    detected, then \"unknown\" is returned.\n"
          "\n"
          "    Note that detecting the disk format can be insecure under some\n"
          "    circumstances. See \"CVE-2010-3851\" in guestfs(3).\n"
          "\n"
          "    See also: \"DISK IMAGE FORMATS\" in guestfs(3)\n"
          "\n"
          "",
  .synopsis = "disk-format filename",
  .run = run_disk_format
};

struct command_entry egrepi_cmd_entry = {
  .name = "egrepi",
  .help = "NAME\n"
          "    egrepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     egrepi regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"egrep -i\" program and returns the matching\n"
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
  .synopsis = "egrepi regex path",
  .run = run_egrepi
};

struct command_entry fallocate_cmd_entry = {
  .name = "fallocate",
  .help = "NAME\n"
          "    fallocate - preallocate a file in the guest filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     fallocate path len\n"
          "\n"
          "DESCRIPTION\n"
          "    This command preallocates a file (containing zero bytes) named \"path\" of\n"
          "    size \"len\" bytes. If the file exists already, it is overwritten.\n"
          "\n"
          "    Do not confuse this with the guestfish-specific \"alloc\" command which\n"
          "    allocates a file in the host and attaches it as a device.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"fallocate64\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "fallocate path len",
  .run = run_fallocate
};

struct command_entry fallocate64_cmd_entry = {
  .name = "fallocate64",
  .help = "NAME\n"
          "    fallocate64 - preallocate a file in the guest filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     fallocate64 path len\n"
          "\n"
          "DESCRIPTION\n"
          "    This command preallocates a file (containing zero bytes) named \"path\" of\n"
          "    size \"len\" bytes. If the file exists already, it is overwritten.\n"
          "\n"
          "    Note that this call allocates disk blocks for the file. To create a\n"
          "    sparse file use \"truncate_size\" instead.\n"
          "\n"
          "    The deprecated call \"fallocate\" does the same, but owing to an oversight\n"
          "    it only allowed 30 bit lengths to be specified, effectively limiting the\n"
          "    maximum size of files created through that call to 1GB.\n"
          "\n"
          "    Do not confuse this with the guestfish-specific \"alloc\" and \"sparse\"\n"
          "    commands which create a file in the host and attach it as a device.\n"
          "\n"
          "",
  .synopsis = "fallocate64 path len",
  .run = run_fallocate64
};

struct command_entry fgrep_cmd_entry = {
  .name = "fgrep",
  .help = "NAME\n"
          "    fgrep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     fgrep pattern path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"fgrep\" program and returns the matching lines.\n"
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
  .synopsis = "fgrep pattern path",
  .run = run_fgrep
};

struct command_entry file_cmd_entry = {
  .name = "file",
  .help = "NAME\n"
          "    file - determine file type\n"
          "\n"
          "SYNOPSIS\n"
          "     file path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call uses the standard file(1) command to determine the type or\n"
          "    contents of the file.\n"
          "\n"
          "    This call will also transparently look inside various types of\n"
          "    compressed file.\n"
          "\n"
          "    The exact command which runs is \"file -zb path\". Note in particular that\n"
          "    the filename is not prepended to the output (the *-b* option).\n"
          "\n"
          "    The output depends on the output of the underlying file(1) command and\n"
          "    it can change in future in ways beyond our control. In other words, the\n"
          "    output is not guaranteed by the ABI.\n"
          "\n"
          "    See also: file(1), \"vfs_type\", \"lstat\", \"is_file\", \"is_blockdev\" (etc),\n"
          "    \"is_zero\".\n"
          "\n"
          "",
  .synopsis = "file path",
  .run = run_file
};

struct command_entry filesize_cmd_entry = {
  .name = "filesize",
  .help = "NAME\n"
          "    filesize - return the size of the file in bytes\n"
          "\n"
          "SYNOPSIS\n"
          "     filesize file\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns the size of file in bytes.\n"
          "\n"
          "    To get other stats about a file, use \"stat\", \"lstat\", \"is_dir\",\n"
          "    \"is_file\" etc. To get the size of block devices, use\n"
          "    \"blockdev_getsize64\".\n"
          "\n"
          "",
  .synopsis = "filesize file",
  .run = run_filesize
};

struct command_entry filesystem_available_cmd_entry = {
  .name = "filesystem-available",
  .help = "NAME\n"
          "    filesystem-available - check if filesystem is available\n"
          "\n"
          "SYNOPSIS\n"
          "     filesystem-available filesystem\n"
          "\n"
          "DESCRIPTION\n"
          "    Check whether libguestfs supports the named filesystem. The argument\n"
          "    \"filesystem\" is a filesystem name, such as \"ext3\".\n"
          "\n"
          "    You must call \"launch\" before using this command.\n"
          "\n"
          "    This is mainly useful as a negative test. If this returns true, it\n"
          "    doesn't mean that a particular filesystem can be created or mounted,\n"
          "    since filesystems can fail for other reasons such as it being a later\n"
          "    version of the filesystem, or having incompatible features, or lacking\n"
          "    the right mkfs.<*fs*> tool.\n"
          "\n"
          "    See also \"available\", \"feature_available\", \"AVAILABILITY\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "filesystem-available filesystem",
  .run = run_filesystem_available
};

struct command_entry fill_cmd_entry = {
  .name = "fill",
  .help = "NAME\n"
          "    fill - fill a file with octets\n"
          "\n"
          "SYNOPSIS\n"
          "     fill c len path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a new file called \"path\". The initial content of\n"
          "    the file is \"len\" octets of \"c\", where \"c\" must be a number in the range\n"
          "    \"[0..255]\".\n"
          "\n"
          "    To fill a file with zero bytes (sparsely), it is much more efficient to\n"
          "    use \"truncate_size\". To create a file with a pattern of repeating bytes\n"
          "    use \"fill_pattern\".\n"
          "\n"
          "",
  .synopsis = "fill c len path",
  .run = run_fill
};

struct command_entry find_cmd_entry = {
  .name = "find",
  .help = "NAME\n"
          "    find - find all files and directories\n"
          "\n"
          "SYNOPSIS\n"
          "     find directory\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lists out all files and directories, recursively, starting\n"
          "    at directory. It is essentially equivalent to running the shell command\n"
          "    \"find directory -print\" but some post-processing happens on the output,\n"
          "    described below.\n"
          "\n"
          "    This returns a list of strings *without any prefix*. Thus if the\n"
          "    directory structure was:\n"
          "\n"
          "     /tmp/a\n"
          "     /tmp/b\n"
          "     /tmp/c/d\n"
          "\n"
          "    then the returned list from \"find\" /tmp would be 4 elements:\n"
          "\n"
          "     a\n"
          "     b\n"
          "     c\n"
          "     c/d\n"
          "\n"
          "    If directory is not a directory, then this command returns an error.\n"
          "\n"
          "    The returned list is sorted.\n"
          "\n"
          "",
  .synopsis = "find directory",
  .run = run_find
};

struct command_entry get_direct_cmd_entry = {
  .name = "get-direct",
  .help = "NAME\n"
          "    get-direct - get direct appliance mode flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-direct\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the direct appliance mode flag.\n"
          "\n"
          "",
  .synopsis = "get-direct",
  .run = run_get_direct
};

struct command_entry get_hv_cmd_entry = {
  .name = "get-hv",
  .help = "NAME\n"
          "    get-hv - get the hypervisor binary\n"
          "\n"
          "SYNOPSIS\n"
          "     get-hv\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current hypervisor binary.\n"
          "\n"
          "    This is always non-NULL. If it wasn't set already, then this will return\n"
          "    the default qemu binary name.\n"
          "\n"
          "",
  .synopsis = "get-hv",
  .run = run_get_hv
};

struct command_entry get_libvirt_requested_credentials_cmd_entry = {
  .name = "get-libvirt-requested-credentials",
  .help = "NAME\n"
          "    get-libvirt-requested-credentials - get list of credentials requested by\n"
          "    libvirt\n"
          "\n"
          "SYNOPSIS\n"
          "     get-libvirt-requested-credentials\n"
          "\n"
          "DESCRIPTION\n"
          "    This should only be called during the event callback for events of type\n"
          "    \"GUESTFS_EVENT_LIBVIRT_AUTH\".\n"
          "\n"
          "    Return the list of credentials requested by libvirt. Possible values are\n"
          "    a subset of the strings provided when you called\n"
          "    \"set_libvirt_supported_credentials\".\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "get-libvirt-requested-credentials",
  .run = run_get_libvirt_requested_credentials
};

struct command_entry head_cmd_entry = {
  .name = "head",
  .help = "NAME\n"
          "    head - return first 10 lines of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     head path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns up to the first 10 lines of a file as a list of\n"
          "    strings.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "head path",
  .run = run_head
};

struct command_entry hivex_node_name_cmd_entry = {
  .name = "hivex-node-name",
  .help = "NAME\n"
          "    hivex-node-name - return the name of the node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-name nodeh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the name of \"nodeh\".\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-name nodeh",
  .run = run_hivex_node_name
};

struct command_entry hivex_node_values_cmd_entry = {
  .name = "hivex-node-values",
  .help = "NAME\n"
          "    hivex-node-values - return list of values attached to node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-values nodeh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the array of (key, datatype, data) tuples attached to \"nodeh\".\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-values nodeh",
  .run = run_hivex_node_values
};

struct command_entry inotify_read_cmd_entry = {
  .name = "inotify-read",
  .help = "NAME\n"
          "    inotify-read - return list of inotify events\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-read\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the complete queue of events that have happened since the\n"
          "    previous read call.\n"
          "\n"
          "    If no events have happened, this returns an empty list.\n"
          "\n"
          "    *Note*: In order to make sure that all events have been read, you must\n"
          "    call this function repeatedly until it returns an empty list. The reason\n"
          "    is that the call will read events up to the maximum appliance-to-host\n"
          "    message size and leave remaining events in the queue.\n"
          "\n"
          "",
  .synopsis = "inotify-read",
  .run = run_inotify_read
};

struct command_entry inspect_get_mountpoints_cmd_entry = {
  .name = "inspect-get-mountpoints",
  .help = "NAME\n"
          "    inspect-get-mountpoints - get mountpoints of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-mountpoints root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns a hash of where we think the filesystems associated with\n"
          "    this operating system should be mounted. Callers should note that this\n"
          "    is at best an educated guess made by reading configuration files such as\n"
          "    /etc/fstab. *In particular note* that this may return filesystems which\n"
          "    are non-existent or not mountable and callers should be prepared to\n"
          "    handle or ignore failures if they try to mount them.\n"
          "\n"
          "    Each element in the returned hashtable has a key which is the path of\n"
          "    the mountpoint (eg. /boot) and a value which is the filesystem that\n"
          "    would be mounted there (eg. /dev/sda1).\n"
          "\n"
          "    Non-mounted devices such as swap devices are *not* returned in this\n"
          "    list.\n"
          "\n"
          "    For operating systems like Windows which still use drive letters, this\n"
          "    call will only return an entry for the first drive \"mounted on\" /. For\n"
          "    information about the mapping of drive letters to partitions, see\n"
          "    \"inspect_get_drive_mappings\".\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n"
          "    \"inspect_get_filesystems\".\n"
          "\n"
          "",
  .synopsis = "inspect-get-mountpoints root",
  .run = run_inspect_get_mountpoints
};

struct command_entry inspect_get_package_management_cmd_entry = {
  .name = "inspect-get-package-management",
  .help = "NAME\n"
          "    inspect-get-package-management - get package management tool used by the\n"
          "    operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-package-management root\n"
          "\n"
          "DESCRIPTION\n"
          "    \"inspect_get_package_format\" and this function return the package format\n"
          "    and package management tool used by the inspected operating system. For\n"
          "    example for Fedora these functions would return \"rpm\" (package format),\n"
          "    and \"yum\" or \"dnf\" (package management).\n"
          "\n"
          "    This returns the string \"unknown\" if we could not determine the package\n"
          "    management tool *or* if the operating system does not have a real\n"
          "    packaging system (eg. Windows).\n"
          "\n"
          "    Possible strings include: \"yum\", \"dnf\", \"up2date\", \"apt\" (for all Debian\n"
          "    derivatives), \"portage\", \"pisi\", \"pacman\", \"urpmi\", \"zypper\", \"apk\",\n"
          "    \"xbps\". Future versions of libguestfs may return other strings.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-package-management root",
  .run = run_inspect_get_package_management
};

struct command_entry inspect_get_product_name_cmd_entry = {
  .name = "inspect-get-product-name",
  .help = "NAME\n"
          "    inspect-get-product-name - get product name of inspected operating\n"
          "    system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-product-name root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the product name of the inspected operating system. The\n"
          "    product name is generally some freeform string which can be displayed to\n"
          "    the user, but should not be parsed by programs.\n"
          "\n"
          "    If the product name could not be determined, then the string \"unknown\"\n"
          "    is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-product-name root",
  .run = run_inspect_get_product_name
};

struct command_entry isoinfo_cmd_entry = {
  .name = "isoinfo",
  .help = "NAME\n"
          "    isoinfo - get ISO information from primary volume descriptor of ISO file\n"
          "\n"
          "SYNOPSIS\n"
          "     isoinfo isofile\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"isoinfo_device\" except that it works for an ISO\n"
          "    file located inside some other mounted filesystem. Note that in the\n"
          "    common case where you have added an ISO file as a libguestfs device, you\n"
          "    would *not* call this. Instead you would call \"isoinfo_device\".\n"
          "\n"
          "",
  .synopsis = "isoinfo isofile",
  .run = run_isoinfo
};

struct command_entry journal_close_cmd_entry = {
  .name = "journal-close",
  .help = "NAME\n"
          "    journal-close - close the systemd journal\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-close\n"
          "\n"
          "DESCRIPTION\n"
          "    Close the journal handle.\n"
          "\n"
          "",
  .synopsis = "journal-close",
  .run = run_journal_close
};

struct command_entry lgetxattr_cmd_entry = {
  .name = "lgetxattr",
  .help = "NAME\n"
          "    lgetxattr - get a single extended attribute\n"
          "\n"
          "SYNOPSIS\n"
          "     lgetxattr path name\n"
          "\n"
          "DESCRIPTION\n"
          "    Get a single extended attribute from file \"path\" named \"name\". If \"path\"\n"
          "    is a symlink, then this call returns an extended attribute from the\n"
          "    symlink.\n"
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
          "    See also: \"lgetxattrs\", \"getxattr\", attr(5).\n"
          "\n"
          "",
  .synopsis = "lgetxattr path name",
  .run = run_lgetxattr
};

struct command_entry list_9p_cmd_entry = {
  .name = "list-9p",
  .help = "NAME\n"
          "    list-9p - list 9p filesystems\n"
          "\n"
          "SYNOPSIS\n"
          "     list-9p\n"
          "\n"
          "DESCRIPTION\n"
          "    List all 9p filesystems attached to the guest. A list of mount tags is\n"
          "    returned.\n"
          "\n"
          "",
  .synopsis = "list-9p",
  .run = run_list_9p
};

struct command_entry list_ldm_partitions_cmd_entry = {
  .name = "list-ldm-partitions",
  .help = "NAME\n"
          "    list-ldm-partitions - list all Windows dynamic disk partitions\n"
          "\n"
          "SYNOPSIS\n"
          "     list-ldm-partitions\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns all Windows dynamic disk partitions that were\n"
          "    found at launch time. It returns a list of device names.\n"
          "\n"
          "",
  .synopsis = "list-ldm-partitions",
  .run = run_list_ldm_partitions
};

struct command_entry luks_format_cipher_cmd_entry = {
  .name = "luks-format-cipher",
  .help = "NAME\n"
          "    luks-format-cipher - format a block device as a LUKS encrypted device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-format-cipher device keyslot cipher\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is the same as \"luks_format\" but it also allows you to set\n"
          "    the \"cipher\" used.\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-format-cipher device keyslot cipher",
  .run = run_luks_format_cipher
};

struct command_entry lvm_clear_filter_cmd_entry = {
  .name = "lvm-clear-filter",
  .help = "NAME\n"
          "    lvm-clear-filter - clear LVM device filter\n"
          "\n"
          "SYNOPSIS\n"
          "     lvm-clear-filter\n"
          "\n"
          "DESCRIPTION\n"
          "    This undoes the effect of \"lvm_set_filter\". LVM will be able to see\n"
          "    every block device.\n"
          "\n"
          "    This command also clears the LVM cache and performs a volume group scan.\n"
          "\n"
          "",
  .synopsis = "lvm-clear-filter",
  .run = run_lvm_clear_filter
};

struct command_entry lvs_cmd_entry = {
  .name = "lvs",
  .help = "NAME\n"
          "    lvs - list the LVM logical volumes (LVs)\n"
          "\n"
          "SYNOPSIS\n"
          "     lvs\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the logical volumes detected. This is the equivalent of the\n"
          "    lvs(8) command.\n"
          "\n"
          "    This returns a list of the logical volume device names (eg.\n"
          "    /dev/VolGroup00/LogVol00).\n"
          "\n"
          "    See also \"lvs_full\", \"list_filesystems\".\n"
          "\n"
          "",
  .synopsis = "lvs",
  .run = run_lvs
};

struct command_entry max_disks_cmd_entry = {
  .name = "max-disks",
  .help = "NAME\n"
          "    max-disks - maximum number of disks that may be added\n"
          "\n"
          "SYNOPSIS\n"
          "     max-disks\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the maximum number of disks that may be added to a handle (eg. by\n"
          "    \"add_drive_opts\" and similar calls).\n"
          "\n"
          "    This function was added in libguestfs 1.19.7. In previous versions of\n"
          "    libguestfs the limit was 25.\n"
          "\n"
          "    See \"MAXIMUM NUMBER OF DISKS\" in guestfs(3) for additional information\n"
          "    on this topic.\n"
          "\n"
          "",
  .synopsis = "max-disks",
  .run = run_max_disks
};

struct command_entry md_detail_cmd_entry = {
  .name = "md-detail",
  .help = "NAME\n"
          "    md-detail - obtain metadata for an MD device\n"
          "\n"
          "SYNOPSIS\n"
          "     md-detail md\n"
          "\n"
          "DESCRIPTION\n"
          "    This command exposes the output of 'mdadm -DY <md>'. The following\n"
          "    fields are usually present in the returned hash. Other fields may also\n"
          "    be present.\n"
          "\n"
          "    \"level\"\n"
          "        The raid level of the MD device.\n"
          "\n"
          "    \"devices\"\n"
          "        The number of underlying devices in the MD device.\n"
          "\n"
          "    \"metadata\"\n"
          "        The metadata version used.\n"
          "\n"
          "    \"uuid\"\n"
          "        The UUID of the MD device.\n"
          "\n"
          "    \"name\"\n"
          "        The name of the MD device.\n"
          "\n"
          "",
  .synopsis = "md-detail md",
  .run = run_md_detail
};

struct command_entry mke2journal_L_cmd_entry = {
  .name = "mke2journal-L",
  .help = "NAME\n"
          "    mke2journal-L - make ext2/3/4 external journal with label\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2journal-L blocksize label device\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2 external journal on \"device\" with label \"label\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2journal-L blocksize label device",
  .run = run_mke2journal_L
};

struct command_entry mkswap_cmd_entry = {
  .name = "mkswap",
  .help = "NAME\n"
          "    mkswap - create a swap partition\n"
          "\n"
          "SYNOPSIS\n"
          "     mkswap device [label:..] [uuid:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a Linux swap partition on \"device\".\n"
          "\n"
          "    The option arguments \"label\" and \"uuid\" allow you to set the label\n"
          "    and/or UUID of the new swap partition.\n"
          "\n"
          "    You can use 'mkswap-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "mkswap device [label:..] [uuid:..]",
  .run = run_mkswap
};

struct command_entry mkswap_L_cmd_entry = {
  .name = "mkswap-L",
  .help = "NAME\n"
          "    mkswap-L - create a swap partition with a label\n"
          "\n"
          "SYNOPSIS\n"
          "     mkswap-L label device\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a swap partition on \"device\" with label \"label\".\n"
          "\n"
          "    Note that you cannot attach a swap label to a block device (eg.\n"
          "    /dev/sda), just to a partition. This appears to be a limitation of the\n"
          "    kernel or swap tools.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mkswap\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mkswap-L label device",
  .run = run_mkswap_L
};

struct command_entry mktemp_cmd_entry = {
  .name = "mktemp",
  .help = "NAME\n"
          "    mktemp - create a temporary file\n"
          "\n"
          "SYNOPSIS\n"
          "     mktemp tmpl [suffix:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a temporary file. The \"tmpl\" parameter should be a\n"
          "    full pathname for the temporary directory name with the final six\n"
          "    characters being \"XXXXXX\".\n"
          "\n"
          "    For example: \"/tmp/myprogXXXXXX\" or \"/Temp/myprogXXXXXX\", the second one\n"
          "    being suitable for Windows filesystems.\n"
          "\n"
          "    The name of the temporary file that was created is returned.\n"
          "\n"
          "    The temporary file is created with mode 0600 and is owned by root.\n"
          "\n"
          "    The caller is responsible for deleting the temporary file after use.\n"
          "\n"
          "    If the optional \"suffix\" parameter is given, then the suffix (eg.\n"
          "    \".txt\") is appended to the temporary name.\n"
          "\n"
          "    See also: \"mkdtemp\".\n"
          "\n"
          "",
  .synopsis = "mktemp tmpl [suffix:..]",
  .run = run_mktemp
};

struct command_entry mount_loop_cmd_entry = {
  .name = "mount-loop",
  .help = "NAME\n"
          "    mount-loop - mount a file using the loop device\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-loop file mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lets you mount file (a filesystem image in a file) on a\n"
          "    mount point. It is entirely equivalent to the command \"mount -o loop\n"
          "    file mountpoint\".\n"
          "\n"
          "",
  .synopsis = "mount-loop file mountpoint",
  .run = run_mount_loop
};

struct command_entry mount_vfs_cmd_entry = {
  .name = "mount-vfs",
  .help = "NAME\n"
          "    mount-vfs - mount a guest disk with mount options and vfstype\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-vfs options vfstype mountable mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as the \"mount\" command, but it allows you to set both\n"
          "    the mount options and the vfstype as for the mount(8) *-o* and *-t*\n"
          "    flags.\n"
          "\n"
          "",
  .synopsis = "mount-vfs options vfstype mountable mountpoint",
  .run = run_mount_vfs
};

struct command_entry part_set_mbr_id_cmd_entry = {
  .name = "part-set-mbr-id",
  .help = "NAME\n"
          "    part-set-mbr-id - set the MBR type byte (ID byte) of a partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-mbr-id device partnum idbyte\n"
          "\n"
          "DESCRIPTION\n"
          "    Sets the MBR type byte (also known as the ID byte) of the numbered\n"
          "    partition \"partnum\" to \"idbyte\". Note that the type bytes quoted in most\n"
          "    documentation are in fact hexadecimal numbers, but usually documented\n"
          "    without any leading \"0x\" which might be confusing.\n"
          "\n"
          "    Note that only MBR (old DOS-style) partitions have type bytes. You will\n"
          "    get undefined results for other partition table types (see\n"
          "    \"part_get_parttype\").\n"
          "\n"
          "",
  .synopsis = "part-set-mbr-id device partnum idbyte",
  .run = run_part_set_mbr_id
};

struct command_entry pread_device_cmd_entry = {
  .name = "pread-device",
  .help = "NAME\n"
          "    pread-device - read part of a device\n"
          "\n"
          "SYNOPSIS\n"
          "     pread-device device count offset\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lets you read part of a block device. It reads \"count\"\n"
          "    bytes of \"device\", starting at \"offset\".\n"
          "\n"
          "    This may read fewer bytes than requested. For further details see the\n"
          "    pread(2) system call.\n"
          "\n"
          "    See also \"pread\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "pread-device device count offset",
  .run = run_pread_device
};

struct command_entry pvchange_uuid_cmd_entry = {
  .name = "pvchange-uuid",
  .help = "NAME\n"
          "    pvchange-uuid - generate a new random UUID for a physical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     pvchange-uuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    Generate a new random UUID for the physical volume \"device\".\n"
          "\n"
          "",
  .synopsis = "pvchange-uuid device",
  .run = run_pvchange_uuid
};

struct command_entry pvchange_uuid_all_cmd_entry = {
  .name = "pvchange-uuid-all",
  .help = "NAME\n"
          "    pvchange-uuid-all - generate new random UUIDs for all physical volumes\n"
          "\n"
          "SYNOPSIS\n"
          "     pvchange-uuid-all\n"
          "\n"
          "DESCRIPTION\n"
          "    Generate new random UUIDs for all physical volumes.\n"
          "\n"
          "",
  .synopsis = "pvchange-uuid-all",
  .run = run_pvchange_uuid_all
};

struct command_entry pvresize_size_cmd_entry = {
  .name = "pvresize-size",
  .help = "NAME\n"
          "    pvresize-size - resize an LVM physical volume (with size)\n"
          "\n"
          "SYNOPSIS\n"
          "     pvresize-size device size\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is the same as \"pvresize\" except that it allows you to\n"
          "    specify the new size (in bytes) explicitly.\n"
          "\n"
          "",
  .synopsis = "pvresize-size device size",
  .run = run_pvresize_size
};

struct command_entry read_lines_cmd_entry = {
  .name = "read-lines",
  .help = "NAME\n"
          "    read-lines - read file as lines\n"
          "\n"
          "SYNOPSIS\n"
          "     read-lines path\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the contents of the file named \"path\".\n"
          "\n"
          "    The file contents are returned as a list of lines. Trailing \"LF\" and\n"
          "    \"CRLF\" character sequences are *not* returned.\n"
          "\n"
          "    Note that this function cannot correctly handle binary files\n"
          "    (specifically, files containing \"\\0\" character which is treated as end\n"
          "    of string). For those you need to use the \"read_file\" function and split\n"
          "    the buffer into lines yourself.\n"
          "\n"
          "",
  .synopsis = "read-lines path",
  .run = run_read_lines
};

struct command_entry remount_cmd_entry = {
  .name = "remount",
  .help = "NAME\n"
          "    remount - remount a filesystem with different options\n"
          "\n"
          "SYNOPSIS\n"
          "     remount mountpoint [rw:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to change the \"rw\" (readonly/read-write) flag on an\n"
          "    already mounted filesystem at \"mountpoint\", converting a readonly\n"
          "    filesystem to be read-write, or vice-versa.\n"
          "\n"
          "    Note that at the moment you must supply the \"optional\" \"rw\" parameter.\n"
          "    In future we may allow other flags to be adjusted.\n"
          "\n"
          "",
  .synopsis = "remount mountpoint [rw:true|false]",
  .run = run_remount
};

struct command_entry removexattr_cmd_entry = {
  .name = "removexattr",
  .help = "NAME\n"
          "    removexattr - remove extended attribute of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     removexattr xattr path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call removes the extended attribute named \"xattr\" of the file\n"
          "    \"path\".\n"
          "\n"
          "    See also: \"lremovexattr\", attr(5).\n"
          "\n"
          "",
  .synopsis = "removexattr xattr path",
  .run = run_removexattr
};

struct command_entry resize2fs_size_cmd_entry = {
  .name = "resize2fs-size",
  .help = "NAME\n"
          "    resize2fs-size - resize an ext2, ext3 or ext4 filesystem (with size)\n"
          "\n"
          "SYNOPSIS\n"
          "     resize2fs-size device size\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is the same as \"resize2fs\" except that it allows you to\n"
          "    specify the new size (in bytes) explicitly.\n"
          "\n"
          "    See also \"RESIZE2FS ERRORS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "resize2fs-size device size",
  .run = run_resize2fs_size
};

struct command_entry rm_f_cmd_entry = {
  .name = "rm-f",
  .help = "NAME\n"
          "    rm-f - remove a file ignoring errors\n"
          "\n"
          "SYNOPSIS\n"
          "     rm-f path\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove the file \"path\".\n"
          "\n"
          "    If the file doesn't exist, that error is ignored. (Other errors, eg. I/O\n"
          "    errors or bad paths, are not ignored)\n"
          "\n"
          "    This call cannot remove directories. Use \"rmdir\" to remove an empty\n"
          "    directory, or \"rm_rf\" to remove directories recursively.\n"
          "\n"
          "",
  .synopsis = "rm-f path",
  .run = run_rm_f
};

struct command_entry rsync_out_cmd_entry = {
  .name = "rsync-out",
  .help = "NAME\n"
          "    rsync-out - synchronize filesystem with host or remote filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     rsync-out src remote [archive:true|false] [deletedest:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call may be used to copy or synchronize the filesystem within\n"
          "    libguestfs with a filesystem on the host or on a remote computer. This\n"
          "    uses the rsync(1) program which uses a fast algorithm that avoids\n"
          "    copying files unnecessarily.\n"
          "\n"
          "    This call only works if the network is enabled. See \"set_network\" or the\n"
          "    *--network* option to various tools like guestfish(1).\n"
          "\n"
          "    Files are copied from the source directory \"src\" to the remote server\n"
          "    and directory specified by \"remote\".\n"
          "\n"
          "    The format of the remote server string is defined by rsync(1). Note that\n"
          "    there is no way to supply a password or passphrase so the target must be\n"
          "    set up not to require one.\n"
          "\n"
          "    The optional arguments are the same as those of \"rsync\".\n"
          "\n"
          "    Globbing does not happen on the \"src\" parameter. In programs which use\n"
          "    the API directly you have to expand wildcards yourself (see\n"
          "    \"glob_expand\"). In guestfish you can use the \"glob\" command (see \"glob\"\n"
          "    in guestfish(1)), for example:\n"
          "\n"
          "     ><fs> glob rsync-out /* rsync://remote/\n"
          "\n"
          "",
  .synopsis = "rsync-out src remote [archive:true|false] [deletedest:true|false]",
  .run = run_rsync_out
};

struct command_entry set_e2generation_cmd_entry = {
  .name = "set-e2generation",
  .help = "NAME\n"
          "    set-e2generation - set ext2 file generation of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     set-e2generation file generation\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the ext2 file generation of a file.\n"
          "\n"
          "    See \"get_e2generation\".\n"
          "\n"
          "",
  .synopsis = "set-e2generation file generation",
  .run = run_set_e2generation
};

struct command_entry set_label_cmd_entry = {
  .name = "set-label",
  .help = "NAME\n"
          "    set-label - set filesystem label\n"
          "\n"
          "SYNOPSIS\n"
          "     set-label mountable label\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the filesystem label on \"mountable\" to \"label\".\n"
          "\n"
          "    Only some filesystem types support labels, and libguestfs supports\n"
          "    setting labels on only a subset of these.\n"
          "\n"
          "    ext2, ext3, ext4\n"
          "        Labels are limited to 16 bytes.\n"
          "\n"
          "    NTFS\n"
          "        Labels are limited to 128 unicode characters.\n"
          "\n"
          "    XFS The label is limited to 12 bytes. The filesystem must not be mounted\n"
          "        when trying to set the label.\n"
          "\n"
          "    btrfs\n"
          "        The label is limited to 255 bytes and some characters are not\n"
          "        allowed. Setting the label on a btrfs subvolume will set the label\n"
          "        on its parent filesystem. The filesystem must not be mounted when\n"
          "        trying to set the label.\n"
          "\n"
          "    fat The label is limited to 11 bytes.\n"
          "\n"
          "    swap\n"
          "        The label is limited to 16 bytes.\n"
          "\n"
          "    If there is no support for changing the label for the type of the\n"
          "    specified filesystem, set_label will fail and set errno as ENOTSUP.\n"
          "\n"
          "    To read the label on a filesystem, call \"vfs_label\".\n"
          "\n"
          "",
  .synopsis = "set-label mountable label",
  .run = run_set_label
};

struct command_entry sfdisk_kernel_geometry_cmd_entry = {
  .name = "sfdisk-kernel-geometry",
  .help = "NAME\n"
          "    sfdisk-kernel-geometry - display the kernel geometry\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdisk-kernel-geometry device\n"
          "\n"
          "DESCRIPTION\n"
          "    This displays the kernel's idea of the geometry of \"device\".\n"
          "\n"
          "    The result is in human-readable format, and not designed to be parsed.\n"
          "\n"
          "",
  .synopsis = "sfdisk-kernel-geometry device",
  .run = run_sfdisk_kernel_geometry
};

struct command_entry sleep_cmd_entry = {
  .name = "sleep",
  .help = "NAME\n"
          "    sleep - sleep for some seconds\n"
          "\n"
          "SYNOPSIS\n"
          "     sleep secs\n"
          "\n"
          "DESCRIPTION\n"
          "    Sleep for \"secs\" seconds.\n"
          "\n"
          "",
  .synopsis = "sleep secs",
  .run = run_sleep
};

struct command_entry strings_e_cmd_entry = {
  .name = "strings-e",
  .help = "NAME\n"
          "    strings-e - print the printable strings in a file\n"
          "\n"
          "SYNOPSIS\n"
          "     strings-e encoding path\n"
          "\n"
          "DESCRIPTION\n"
          "    This is like the \"strings\" command, but allows you to specify the\n"
          "    encoding of strings that are looked for in the source file \"path\".\n"
          "\n"
          "    Allowed encodings are:\n"
          "\n"
          "    s   Single 7-bit-byte characters like ASCII and the ASCII-compatible\n"
          "        parts of ISO-8859-X (this is what \"strings\" uses).\n"
          "\n"
          "    S   Single 8-bit-byte characters.\n"
          "\n"
          "    b   16-bit big endian strings such as those encoded in UTF-16BE or\n"
          "        UCS-2BE.\n"
          "\n"
          "    l (lower case letter L)\n"
          "        16-bit little endian such as UTF-16LE and UCS-2LE. This is useful\n"
          "        for examining binaries in Windows guests.\n"
          "\n"
          "    B   32-bit big endian such as UCS-4BE.\n"
          "\n"
          "    L   32-bit little endian such as UCS-4LE.\n"
          "\n"
          "    The returned strings are transcoded to UTF-8.\n"
          "\n"
          "    The \"strings\" command has, in the past, had problems with parsing\n"
          "    untrusted files. These are mitigated in the current version of\n"
          "    libguestfs, but see \"CVE-2014-8484\" in guestfs(3).\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "strings-e encoding path",
  .run = run_strings_e
};

struct command_entry sync_cmd_entry = {
  .name = "sync",
  .help = "NAME\n"
          "    sync - sync disks, writes are flushed through to the disk image\n"
          "\n"
          "SYNOPSIS\n"
          "     sync\n"
          "\n"
          "DESCRIPTION\n"
          "    This syncs the disk, so that any writes are flushed through to the\n"
          "    underlying disk image.\n"
          "\n"
          "    You should always call this if you have modified a disk image, before\n"
          "    closing the handle.\n"
          "\n"
          "",
  .synopsis = "sync",
  .run = run_sync
};

struct command_entry tail_n_cmd_entry = {
  .name = "tail-n",
  .help = "NAME\n"
          "    tail-n - return last N lines of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     tail-n nrlines path\n"
          "\n"
          "DESCRIPTION\n"
          "    If the parameter \"nrlines\" is a positive number, this returns the last\n"
          "    \"nrlines\" lines of the file \"path\".\n"
          "\n"
          "    If the parameter \"nrlines\" is a negative number, this returns lines from\n"
          "    the file \"path\", starting with the \"-nrlines\"th line.\n"
          "\n"
          "    If the parameter \"nrlines\" is zero, this returns an empty list.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "tail-n nrlines path",
  .run = run_tail_n
};

struct command_entry tar_out_cmd_entry = {
  .name = "tar-out",
  .help = "NAME\n"
          "    tar-out - pack directory into tarfile\n"
          "\n"
          "SYNOPSIS\n"
          "     tar-out directory tarfile [compress:..] [numericowner:true|false] [excludes:..] [xattrs:true|false] [selinux:true|false] [acls:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command packs the contents of directory and downloads it to local\n"
          "    file \"tarfile\".\n"
          "\n"
          "    The optional \"compress\" flag controls compression. If not given, then\n"
          "    the output will be an uncompressed tar file. Otherwise one of the\n"
          "    following strings may be given to select the compression type of the\n"
          "    output file: \"compress\", \"gzip\", \"bzip2\", \"xz\", \"lzop\". (Note that not\n"
          "    all builds of libguestfs will support all of these compression types).\n"
          "\n"
          "    The other optional arguments are:\n"
          "\n"
          "    \"excludes\"\n"
          "        A list of wildcards. Files are excluded if they match any of the\n"
          "        wildcards.\n"
          "\n"
          "    \"numericowner\"\n"
          "        If set to true, the output tar file will contain UID/GID numbers\n"
          "        instead of user/group names.\n"
          "\n"
          "    \"xattrs\"\n"
          "        If set to true, extended attributes are saved in the output tar.\n"
          "\n"
          "    \"selinux\"\n"
          "        If set to true, SELinux contexts are saved in the output tar.\n"
          "\n"
          "    \"acls\"\n"
          "        If set to true, POSIX ACLs are saved in the output tar.\n"
          "\n"
          "    You can use 'tar-out-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "tar-out directory tarfile [compress:..] [numericowner:true|false] [excludes:..] [xattrs:true|false] [selinux:true|false] [acls:true|false]",
  .run = run_tar_out
};

struct command_entry vfs_type_cmd_entry = {
  .name = "vfs-type",
  .help = "NAME\n"
          "    vfs-type - get the Linux VFS type corresponding to a mounted device\n"
          "\n"
          "SYNOPSIS\n"
          "     vfs-type mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    This command gets the filesystem type corresponding to the filesystem on\n"
          "    \"mountable\".\n"
          "\n"
          "    For most filesystems, the result is the name of the Linux VFS module\n"
          "    which would be used to mount this filesystem if you mounted it without\n"
          "    specifying the filesystem type. For example a string such as \"ext3\" or\n"
          "    \"ntfs\".\n"
          "\n"
          "",
  .synopsis = "vfs-type mountable",
  .run = run_vfs_type
};

struct command_entry vgcreate_cmd_entry = {
  .name = "vgcreate",
  .help = "NAME\n"
          "    vgcreate - create an LVM volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vgcreate volgroup physvols\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an LVM volume group called \"volgroup\" from the non-empty\n"
          "    list of physical volumes \"physvols\".\n"
          "\n"
          "",
  .synopsis = "vgcreate volgroup physvols",
  .run = run_vgcreate
};

struct command_entry wc_c_cmd_entry = {
  .name = "wc-c",
  .help = "NAME\n"
          "    wc-c - count characters in a file\n"
          "\n"
          "SYNOPSIS\n"
          "     wc-c path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command counts the characters in a file, using the \"wc -c\" external\n"
          "    command.\n"
          "\n"
          "",
  .synopsis = "wc-c path",
  .run = run_wc_c
};

struct command_entry zegrep_cmd_entry = {
  .name = "zegrep",
  .help = "NAME\n"
          "    zegrep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zegrep regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zegrep\" program and returns the matching lines.\n"
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
  .synopsis = "zegrep regex path",
  .run = run_zegrep
};

