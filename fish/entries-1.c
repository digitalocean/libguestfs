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

struct command_entry aug_clear_cmd_entry = {
  .name = "aug-clear",
  .help = "NAME\n"
          "    aug-clear - clear Augeas path\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-clear augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the value associated with \"path\" to \"NULL\". This is the same as the\n"
          "    augtool(1) \"clear\" command.\n"
          "\n"
          "",
  .synopsis = "aug-clear augpath",
  .run = run_aug_clear
};

struct command_entry aug_defvar_cmd_entry = {
  .name = "aug-defvar",
  .help = "NAME\n"
          "    aug-defvar - define an Augeas variable\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-defvar name expr\n"
          "\n"
          "DESCRIPTION\n"
          "    Defines an Augeas variable \"name\" whose value is the result of\n"
          "    evaluating \"expr\". If \"expr\" is NULL, then \"name\" is undefined.\n"
          "\n"
          "    On success this returns the number of nodes in \"expr\", or 0 if \"expr\"\n"
          "    evaluates to something which is not a nodeset.\n"
          "\n"
          "",
  .synopsis = "aug-defvar name expr",
  .run = run_aug_defvar
};

struct command_entry base64_in_cmd_entry = {
  .name = "base64-in",
  .help = "NAME\n"
          "    base64-in - upload base64-encoded data to file\n"
          "\n"
          "SYNOPSIS\n"
          "     base64-in base64file filename\n"
          "\n"
          "DESCRIPTION\n"
          "    This command uploads base64-encoded data from \"base64file\" to filename.\n"
          "\n"
          "",
  .synopsis = "base64-in base64file filename",
  .run = run_base64_in
};

struct command_entry base64_out_cmd_entry = {
  .name = "base64-out",
  .help = "NAME\n"
          "    base64-out - download file and encode as base64\n"
          "\n"
          "SYNOPSIS\n"
          "     base64-out filename base64file\n"
          "\n"
          "DESCRIPTION\n"
          "    This command downloads the contents of filename, writing it out to local\n"
          "    file \"base64file\" encoded as base64.\n"
          "\n"
          "",
  .synopsis = "base64-out filename base64file",
  .run = run_base64_out
};

struct command_entry btrfs_balance_resume_cmd_entry = {
  .name = "btrfs-balance-resume",
  .help = "NAME\n"
          "    btrfs-balance-resume - resume a paused balance\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-balance-resume path\n"
          "\n"
          "DESCRIPTION\n"
          "    Resume a paused balance on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-balance-resume path",
  .run = run_btrfs_balance_resume
};

struct command_entry btrfs_fsck_cmd_entry = {
  .name = "btrfs-fsck",
  .help = "NAME\n"
          "    btrfs-fsck - check a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-fsck device [superblock:N] [repair:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Used to check a btrfs filesystem, \"device\" is the device file where the\n"
          "    filesystem is stored.\n"
          "\n"
          "",
  .synopsis = "btrfs-fsck device [superblock:N] [repair:true|false]",
  .run = run_btrfs_fsck
};

struct command_entry btrfs_qgroup_show_cmd_entry = {
  .name = "btrfs-qgroup-show",
  .help = "NAME\n"
          "    btrfs-qgroup-show - show subvolume quota groups\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-show path\n"
          "\n"
          "DESCRIPTION\n"
          "    Show all subvolume quota groups in a btrfs filesystem, including their\n"
          "    usages.\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-show path",
  .run = run_btrfs_qgroup_show
};

struct command_entry btrfs_rescue_chunk_recover_cmd_entry = {
  .name = "btrfs-rescue-chunk-recover",
  .help = "NAME\n"
          "    btrfs-rescue-chunk-recover - recover the chunk tree of btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-rescue-chunk-recover device\n"
          "\n"
          "DESCRIPTION\n"
          "    Recover the chunk tree of btrfs filesystem by scanning the devices one\n"
          "    by one.\n"
          "\n"
          "",
  .synopsis = "btrfs-rescue-chunk-recover device",
  .run = run_btrfs_rescue_chunk_recover
};

struct command_entry btrfs_scrub_resume_cmd_entry = {
  .name = "btrfs-scrub-resume",
  .help = "NAME\n"
          "    btrfs-scrub-resume - resume a previously canceled or interrupted scrub\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-scrub-resume path\n"
          "\n"
          "DESCRIPTION\n"
          "    Resume a previously canceled or interrupted scrub on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-scrub-resume path",
  .run = run_btrfs_scrub_resume
};

struct command_entry cat_cmd_entry = {
  .name = "cat",
  .help = "NAME\n"
          "    cat - list the contents of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     cat path\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the contents of the file named \"path\".\n"
          "\n"
          "    Because, in C, this function returns a \"char *\", there is no way to\n"
          "    differentiate between a \"\\0\" character in a file and end of string. To\n"
          "    handle binary files, use the \"read_file\" or \"download\" functions.\n"
          "\n"
          "",
  .synopsis = "cat path",
  .run = run_cat
};

struct command_entry checksum_device_cmd_entry = {
  .name = "checksum-device",
  .help = "NAME\n"
          "    checksum-device - compute MD5, SHAx or CRC checksum of the contents of a\n"
          "    device\n"
          "\n"
          "SYNOPSIS\n"
          "     checksum-device csumtype device\n"
          "\n"
          "DESCRIPTION\n"
          "    This call computes the MD5, SHAx or CRC checksum of the contents of the\n"
          "    device named \"device\". For the types of checksums supported see the\n"
          "    \"checksum\" command.\n"
          "\n"
          "",
  .synopsis = "checksum-device csumtype device",
  .run = run_checksum_device
};

struct command_entry clear_backend_setting_cmd_entry = {
  .name = "clear-backend-setting",
  .help = "NAME\n"
          "    clear-backend-setting - remove a single per-backend settings string\n"
          "\n"
          "SYNOPSIS\n"
          "     clear-backend-setting name\n"
          "\n"
          "DESCRIPTION\n"
          "    If there is a backend setting string matching \"name\" or beginning with\n"
          "    \"name=\", then that string is removed from the backend settings.\n"
          "\n"
          "    This call returns the number of strings which were removed (which may be\n"
          "    0, 1 or greater than 1).\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3), \"BACKEND SETTINGS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "clear-backend-setting name",
  .run = run_clear_backend_setting
};

struct command_entry config_cmd_entry = {
  .name = "config",
  .help = "NAME\n"
          "    config - add hypervisor parameters\n"
          "\n"
          "SYNOPSIS\n"
          "     config hvparam hvvalue\n"
          "\n"
          "DESCRIPTION\n"
          "    This can be used to add arbitrary hypervisor parameters of the form\n"
          "    *-param value*. Actually it’s not quite arbitrary - we prevent you from\n"
          "    setting some parameters which would interfere with parameters that we\n"
          "    use.\n"
          "\n"
          "    The first character of \"hvparam\" string must be a \"-\" (dash).\n"
          "\n"
          "    \"hvvalue\" can be NULL.\n"
          "\n"
          "",
  .synopsis = "config hvparam hvvalue",
  .run = run_config
};

struct command_entry copy_attributes_cmd_entry = {
  .name = "copy-attributes",
  .help = "NAME\n"
          "    copy-attributes - copy the attributes of a path (file/directory) to\n"
          "    another\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-attributes src dest [all:true|false] [mode:true|false] [xattributes:true|false] [ownership:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Copy the attributes of a path (which can be a file or a directory) to\n"
          "    another path.\n"
          "\n"
          "    By default \"no\" attribute is copied, so make sure to specify any (or\n"
          "    \"all\" to copy everything).\n"
          "\n"
          "    The optional arguments specify which attributes can be copied:\n"
          "\n"
          "    \"mode\"\n"
          "        Copy part of the file mode from \"source\" to \"destination\". Only the\n"
          "        UNIX permissions and the sticky/setuid/setgid bits can be copied.\n"
          "\n"
          "    \"xattributes\"\n"
          "        Copy the Linux extended attributes (xattrs) from \"source\" to\n"
          "        \"destination\". This flag does nothing if the *linuxxattrs* feature\n"
          "        is not available (see \"feature_available\").\n"
          "\n"
          "    \"ownership\"\n"
          "        Copy the owner uid and the group gid of \"source\" to \"destination\".\n"
          "\n"
          "    \"all\"\n"
          "        Copy all the attributes from \"source\" to \"destination\". Enabling it\n"
          "        enables all the other flags, if they are not specified already.\n"
          "\n"
          "",
  .synopsis = "copy-attributes src dest [all:true|false] [mode:true|false] [xattributes:true|false] [ownership:true|false]",
  .run = run_copy_attributes
};

struct command_entry copy_device_to_device_cmd_entry = {
  .name = "copy-device-to-device",
  .help = "NAME\n"
          "    copy-device-to-device - copy from source device to destination device\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-device-to-device src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    The four calls \"copy_device_to_device\", \"copy_device_to_file\",\n"
          "    \"copy_file_to_device\", and \"copy_file_to_file\" let you copy from a\n"
          "    source (device|file) to a destination (device|file).\n"
          "\n"
          "    Partial copies can be made since you can specify optionally the source\n"
          "    offset, destination offset and size to copy. These values are all\n"
          "    specified in bytes. If not given, the offsets both default to zero, and\n"
          "    the size defaults to copying as much as possible until we hit the end of\n"
          "    the source.\n"
          "\n"
          "    The source and destination may be the same object. However overlapping\n"
          "    regions may not be copied correctly.\n"
          "\n"
          "    If the destination is a file, it is created if required. If the\n"
          "    destination file is not large enough, it is extended.\n"
          "\n"
          "    If the destination is a file and the \"append\" flag is not set, then the\n"
          "    destination file is truncated. If the \"append\" flag is set, then the\n"
          "    copy appends to the destination file. The \"append\" flag currently cannot\n"
          "    be set for devices.\n"
          "\n"
          "    If the \"sparse\" flag is true then the call avoids writing blocks that\n"
          "    contain only zeroes, which can help in some situations where the backing\n"
          "    disk is thin-provisioned. Note that unless the target is already zeroed,\n"
          "    using this option will result in incorrect copying.\n"
          "\n"
          "",
  .synopsis = "copy-device-to-device src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]",
  .run = run_copy_device_to_device
};

struct command_entry dd_cmd_entry = {
  .name = "dd",
  .help = "NAME\n"
          "    dd - copy from source to destination using dd\n"
          "\n"
          "SYNOPSIS\n"
          "     dd src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    This command copies from one source device or file \"src\" to another\n"
          "    destination device or file \"dest\". Normally you would use this to copy\n"
          "    to or from a device or partition, for example to duplicate a filesystem.\n"
          "\n"
          "    If the destination is a device, it must be as large or larger than the\n"
          "    source file or device, otherwise the copy will fail. This command cannot\n"
          "    do partial copies (see \"copy_device_to_device\").\n"
          "\n"
          "    *This function is deprecated.* In new code, use the\n"
          "    \"copy-device-to-device\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "dd src dest",
  .run = run_dd
};

struct command_entry debug_drives_cmd_entry = {
  .name = "debug-drives",
  .help = "NAME\n"
          "    debug-drives - debug the drives (internal use only)\n"
          "\n"
          "SYNOPSIS\n"
          "     debug-drives\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the internal list of drives. ‘debug’ commands are not part\n"
          "    of the formal API and can be removed or changed at any time.\n"
          "\n"
          "",
  .synopsis = "debug-drives",
  .run = run_debug_drives
};

struct command_entry device_index_cmd_entry = {
  .name = "device-index",
  .help = "NAME\n"
          "    device-index - convert device to index\n"
          "\n"
          "SYNOPSIS\n"
          "     device-index device\n"
          "\n"
          "DESCRIPTION\n"
          "    This function takes a device name (eg. \"/dev/sdb\") and returns the index\n"
          "    of the device in the list of devices.\n"
          "\n"
          "    Index numbers start from 0. The named device must exist, for example as\n"
          "    a string returned from \"list_devices\".\n"
          "\n"
          "    See also \"list_devices\", \"part_to_dev\".\n"
          "\n"
          "",
  .synopsis = "device-index device",
  .run = run_device_index
};

struct command_entry download_inode_cmd_entry = {
  .name = "download-inode",
  .help = "NAME\n"
          "    download-inode - download a file to the local machine given its inode\n"
          "\n"
          "SYNOPSIS\n"
          "     download-inode device inode filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Download a file given its inode from the disk partition (eg. /dev/sda1)\n"
          "    and save it as filename on the local machine.\n"
          "\n"
          "    It is not required to mount the disk to run this command.\n"
          "\n"
          "    The command is capable of downloading deleted or inaccessible files.\n"
          "\n"
          "",
  .synopsis = "download-inode device inode filename",
  .run = run_download_inode
};

struct command_entry exists_cmd_entry = {
  .name = "exists",
  .help = "NAME\n"
          "    exists - test if file or directory exists\n"
          "\n"
          "SYNOPSIS\n"
          "     exists path\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a file, directory (or\n"
          "    anything) with the given \"path\" name.\n"
          "\n"
          "    See also \"is_file\", \"is_dir\", \"stat\".\n"
          "\n"
          "",
  .synopsis = "exists path",
  .run = run_exists
};

struct command_entry filesystem_walk_cmd_entry = {
  .name = "filesystem-walk",
  .help = "NAME\n"
          "    filesystem-walk - walk through the filesystem content\n"
          "\n"
          "SYNOPSIS\n"
          "     filesystem-walk device\n"
          "\n"
          "DESCRIPTION\n"
          "    Walk through the internal structures of a disk partition (eg. /dev/sda1)\n"
          "    in order to return a list of all the files and directories stored\n"
          "    within.\n"
          "\n"
          "    It is not necessary to mount the disk partition to run this command.\n"
          "\n"
          "    All entries in the filesystem are returned. This function can list\n"
          "    deleted or unaccessible files. The entries are *not* sorted.\n"
          "\n"
          "    The \"tsk_dirent\" structure contains the following fields.\n"
          "\n"
          "    \"tsk_inode\"\n"
          "        Filesystem reference number of the node. It might be 0 if the node\n"
          "        has been deleted.\n"
          "\n"
          "    \"tsk_type\"\n"
          "        Basic file type information. See below for a detailed list of\n"
          "        values.\n"
          "\n"
          "    \"tsk_size\"\n"
          "        File size in bytes. It might be -1 if the node has been deleted.\n"
          "\n"
          "    \"tsk_name\"\n"
          "        The file path relative to its directory.\n"
          "\n"
          "    \"tsk_flags\"\n"
          "        Bitfield containing extra information regarding the entry. It\n"
          "        contains the logical OR of the following values:\n"
          "\n"
          "        0x0001\n"
          "            If set to 1, the file is allocated and visible within the\n"
          "            filesystem. Otherwise, the file has been deleted. Under certain\n"
          "            circumstances, the function \"download_inode\" can be used to\n"
          "            recover deleted files.\n"
          "\n"
          "        0x0002\n"
          "            Filesystem such as NTFS and Ext2 or greater, separate the file\n"
          "            name from the metadata structure. The bit is set to 1 when the\n"
          "            file name is in an unallocated state and the metadata structure\n"
          "            is in an allocated one. This generally implies the metadata has\n"
          "            been reallocated to a new file. Therefore, information such as\n"
          "            file type, file size, timestamps, number of links and symlink\n"
          "            target might not correspond with the ones of the original\n"
          "            deleted entry.\n"
          "\n"
          "        0x0004\n"
          "            The bit is set to 1 when the file is compressed using filesystem\n"
          "            native compression support (NTFS). The API is not able to detect\n"
          "            application level compression.\n"
          "\n"
          "    \"tsk_atime_sec\"\n"
          "    \"tsk_atime_nsec\"\n"
          "    \"tsk_mtime_sec\"\n"
          "    \"tsk_mtime_nsec\"\n"
          "    \"tsk_ctime_sec\"\n"
          "    \"tsk_ctime_nsec\"\n"
          "    \"tsk_crtime_sec\"\n"
          "    \"tsk_crtime_nsec\"\n"
          "        Respectively, access, modification, last status change and creation\n"
          "        time in Unix format in seconds and nanoseconds.\n"
          "\n"
          "    \"tsk_nlink\"\n"
          "        Number of file names pointing to this entry.\n"
          "\n"
          "    \"tsk_link\"\n"
          "        If the entry is a symbolic link, this field will contain the path to\n"
          "        the target file.\n"
          "\n"
          "    The \"tsk_type\" field will contain one of the following characters:\n"
          "\n"
          "    'b' Block special\n"
          "\n"
          "    'c' Char special\n"
          "\n"
          "    'd' Directory\n"
          "\n"
          "    'f' FIFO (named pipe)\n"
          "\n"
          "    'l' Symbolic link\n"
          "\n"
          "    'r' Regular file\n"
          "\n"
          "    's' Socket\n"
          "\n"
          "    'h' Shadow inode (Solaris)\n"
          "\n"
          "    'w' Whiteout inode (BSD)\n"
          "\n"
          "    'u' Unknown file type\n"
          "\n"
          "",
  .synopsis = "filesystem-walk device",
  .run = run_filesystem_walk
};

struct command_entry fill_dir_cmd_entry = {
  .name = "fill-dir",
  .help = "NAME\n"
          "    fill-dir - fill a directory with empty files\n"
          "\n"
          "SYNOPSIS\n"
          "     fill-dir dir nr\n"
          "\n"
          "DESCRIPTION\n"
          "    This function, useful for testing filesystems, creates \"nr\" empty files\n"
          "    in the directory \"dir\" with names 00000000 through \"nr-1\" (ie. each file\n"
          "    name is 8 digits long padded with zeroes).\n"
          "\n"
          "",
  .synopsis = "fill-dir dir nr",
  .run = run_fill_dir
};

struct command_entry findfs_label_cmd_entry = {
  .name = "findfs-label",
  .help = "NAME\n"
          "    findfs-label - find a filesystem by label\n"
          "\n"
          "SYNOPSIS\n"
          "     findfs-label label\n"
          "\n"
          "DESCRIPTION\n"
          "    This command searches the filesystems and returns the one which has the\n"
          "    given label. An error is returned if no such filesystem can be found.\n"
          "\n"
          "    To find the label of a filesystem, use \"vfs_label\".\n"
          "\n"
          "",
  .synopsis = "findfs-label label",
  .run = run_findfs_label
};

struct command_entry get_identifier_cmd_entry = {
  .name = "get-identifier",
  .help = "NAME\n"
          "    get-identifier - get the handle identifier\n"
          "\n"
          "SYNOPSIS\n"
          "     get-identifier\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the handle identifier. See \"set_identifier\".\n"
          "\n"
          "",
  .synopsis = "get-identifier",
  .run = run_get_identifier
};

struct command_entry get_libvirt_requested_credential_prompt_cmd_entry = {
  .name = "get-libvirt-requested-credential-prompt",
  .help = "NAME\n"
          "    get-libvirt-requested-credential-prompt - prompt of i'th requested\n"
          "    credential\n"
          "\n"
          "SYNOPSIS\n"
          "     get-libvirt-requested-credential-prompt index\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the prompt (provided by libvirt) for the \"index\"'th requested\n"
          "    credential. If libvirt did not provide a prompt, this returns the empty\n"
          "    string \"\".\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "get-libvirt-requested-credential-prompt index",
  .run = run_get_libvirt_requested_credential_prompt
};

struct command_entry get_network_cmd_entry = {
  .name = "get-network",
  .help = "NAME\n"
          "    get-network - get enable network flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-network\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the enable network flag.\n"
          "\n"
          "",
  .synopsis = "get-network",
  .run = run_get_network
};

struct command_entry get_qemu_cmd_entry = {
  .name = "get-qemu",
  .help = "NAME\n"
          "    get-qemu - get the hypervisor binary (usually qemu)\n"
          "\n"
          "SYNOPSIS\n"
          "     get-qemu\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current hypervisor binary (usually qemu).\n"
          "\n"
          "    This is always non-NULL. If it wasn't set already, then this will return\n"
          "    the default qemu binary name.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"get-hv\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "get-qemu",
  .run = run_get_qemu
};

struct command_entry get_umask_cmd_entry = {
  .name = "get-umask",
  .help = "NAME\n"
          "    get-umask - get the current umask\n"
          "\n"
          "SYNOPSIS\n"
          "     get-umask\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current umask. By default the umask is 022 unless it has been\n"
          "    set by calling \"umask\".\n"
          "\n"
          "",
  .synopsis = "get-umask",
  .run = run_get_umask
};

struct command_entry get_verbose_cmd_entry = {
  .name = "get-verbose",
  .help = "NAME\n"
          "    get-verbose - get verbose mode\n"
          "\n"
          "SYNOPSIS\n"
          "     get-verbose\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the verbose messages flag.\n"
          "\n"
          "",
  .synopsis = "get-verbose",
  .run = run_get_verbose
};

struct command_entry getxattrs_cmd_entry = {
  .name = "getxattrs",
  .help = "NAME\n"
          "    getxattrs - list extended attributes of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     getxattrs path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call lists the extended attributes of the file or directory \"path\".\n"
          "\n"
          "    At the system call level, this is a combination of the listxattr(2) and\n"
          "    getxattr(2) calls.\n"
          "\n"
          "    See also: \"lgetxattrs\", attr(5).\n"
          "\n"
          "",
  .synopsis = "getxattrs path",
  .run = run_getxattrs
};

struct command_entry grep_cmd_entry = {
  .name = "grep",
  .help = "NAME\n"
          "    grep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     grep regex path [extended:true|false] [fixed:true|false] [insensitive:true|false] [compressed:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"grep\" program and returns the matching lines.\n"
          "\n"
          "    The optional flags are:\n"
          "\n"
          "    \"extended\"\n"
          "        Use extended regular expressions. This is the same as using the *-E*\n"
          "        flag.\n"
          "\n"
          "    \"fixed\"\n"
          "        Match fixed (don't use regular expressions). This is the same as\n"
          "        using the *-F* flag.\n"
          "\n"
          "    \"insensitive\"\n"
          "        Match case-insensitive. This is the same as using the *-i* flag.\n"
          "\n"
          "    \"compressed\"\n"
          "        Use \"zgrep\" instead of \"grep\". This allows the input to be compress-\n"
          "        or gzip-compressed.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "    You can use 'grep-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "grep regex path [extended:true|false] [fixed:true|false] [insensitive:true|false] [compressed:true|false]",
  .run = run_grep
};

struct command_entry hivex_node_parent_cmd_entry = {
  .name = "hivex-node-parent",
  .help = "NAME\n"
          "    hivex-node-parent - return the parent of node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-parent nodeh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the parent node of \"nodeh\".\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-parent nodeh",
  .run = run_hivex_node_parent
};

struct command_entry hivex_root_cmd_entry = {
  .name = "hivex-root",
  .help = "NAME\n"
          "    hivex-root - return the root node of the hive\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-root\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the root node of the hive.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-root",
  .run = run_hivex_root
};

struct command_entry hivex_value_string_cmd_entry = {
  .name = "hivex-value-string",
  .help = "NAME\n"
          "    hivex-value-string - return the data field as a UTF-8 string\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-value-string valueh\n"
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
          "",
  .synopsis = "hivex-value-string valueh",
  .run = run_hivex_value_string
};

struct command_entry hivex_value_value_cmd_entry = {
  .name = "hivex-value-value",
  .help = "NAME\n"
          "    hivex-value-value - return the data field from the (key, datatype, data)\n"
          "    tuple\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-value-value valueh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the data field of a (key, datatype, data) tuple.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "    See also: \"hivex_value_utf8\".\n"
          "\n"
          "",
  .synopsis = "hivex-value-value valueh",
  .run = run_hivex_value_value
};

struct command_entry initrd_list_cmd_entry = {
  .name = "initrd-list",
  .help = "NAME\n"
          "    initrd-list - list files in an initrd\n"
          "\n"
          "SYNOPSIS\n"
          "     initrd-list path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lists out files contained in an initrd.\n"
          "\n"
          "    The files are listed without any initial / character. The files are\n"
          "    listed in the order they appear (not necessarily alphabetical).\n"
          "    Directory names are listed as separate items.\n"
          "\n"
          "    Old Linux kernels (2.4 and earlier) used a compressed ext2 filesystem as\n"
          "    initrd. We *only* support the newer initramfs format (compressed cpio\n"
          "    files).\n"
          "\n"
          "",
  .synopsis = "initrd-list path",
  .run = run_initrd_list
};

struct command_entry inotify_files_cmd_entry = {
  .name = "inotify-files",
  .help = "NAME\n"
          "    inotify-files - return list of watched files that had events\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-files\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is a helpful wrapper around \"inotify_read\" which just\n"
          "    returns a list of pathnames of objects that were touched. The returned\n"
          "    pathnames are sorted and deduplicated.\n"
          "\n"
          "",
  .synopsis = "inotify-files",
  .run = run_inotify_files
};

struct command_entry inotify_rm_watch_cmd_entry = {
  .name = "inotify-rm-watch",
  .help = "NAME\n"
          "    inotify-rm-watch - remove an inotify watch\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-rm-watch wd\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove a previously defined inotify watch. See \"inotify_add_watch\".\n"
          "\n"
          "",
  .synopsis = "inotify-rm-watch wd",
  .run = run_inotify_rm_watch
};

struct command_entry inspect_get_icon_cmd_entry = {
  .name = "inspect-get-icon",
  .help = "NAME\n"
          "    inspect-get-icon - get the icon corresponding to this operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-icon root [favicon:true|false] [highquality:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns an icon corresponding to the inspected operating\n"
          "    system. The icon is returned as a buffer containing a PNG image\n"
          "    (re-encoded to PNG if necessary).\n"
          "\n"
          "    If it was not possible to get an icon this function returns a\n"
          "    zero-length (non-NULL) buffer. *Callers must check for this case*.\n"
          "\n"
          "    Libguestfs will start by looking for a file called /etc/favicon.png or\n"
          "    C:\\etc\\favicon.png and if it has the correct format, the contents of\n"
          "    this file will be returned. You can disable favicons by passing the\n"
          "    optional \"favicon\" boolean as false (default is true).\n"
          "\n"
          "    If finding the favicon fails, then we look in other places in the guest\n"
          "    for a suitable icon.\n"
          "\n"
          "    If the optional \"highquality\" boolean is true then only high quality\n"
          "    icons are returned, which means only icons of high resolution with an\n"
          "    alpha channel. The default (false) is to return any icon we can, even if\n"
          "    it is of substandard quality.\n"
          "\n"
          "    Notes:\n"
          "\n"
          "    *   Unlike most other inspection API calls, the guest’s disks must be\n"
          "        mounted up before you call this, since it needs to read information\n"
          "        from the guest filesystem during the call.\n"
          "\n"
          "    *   Security: The icon data comes from the untrusted guest, and should\n"
          "        be treated with caution. PNG files have been known to contain\n"
          "        exploits. Ensure that libpng (or other relevant libraries) are fully\n"
          "        up to date before trying to process or display the icon.\n"
          "\n"
          "    *   The PNG image returned can be any size. It might not be square.\n"
          "        Libguestfs tries to return the largest, highest quality icon\n"
          "        available. The application must scale the icon to the required size.\n"
          "\n"
          "    *   Extracting icons from Windows guests requires the external\n"
          "        \"wrestool\" program from the \"icoutils\" package, and several programs\n"
          "        (\"bmptopnm\", \"pnmtopng\", \"pamcut\") from the \"netpbm\" package. These\n"
          "        must be installed separately.\n"
          "\n"
          "    *   Operating system icons are usually trademarks. Seek legal advice\n"
          "        before using trademarks in applications.\n"
          "\n"
          "",
  .synopsis = "inspect-get-icon root [favicon:true|false] [highquality:true|false]",
  .run = run_inspect_get_icon
};

struct command_entry inspect_get_windows_system_hive_cmd_entry = {
  .name = "inspect-get-windows-system-hive",
  .help = "NAME\n"
          "    inspect-get-windows-system-hive - get the path of the Windows system\n"
          "    hive\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-windows-system-hive root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the path to the hive (binary Windows Registry file)\n"
          "    corresponding to HKLM\\SYSTEM.\n"
          "\n"
          "    This call assumes that the guest is Windows and that the guest has a\n"
          "    system hive file with the right name. If this is not the case then an\n"
          "    error is returned. This call does not check that the hive is a valid\n"
          "    Windows Registry hive.\n"
          "\n"
          "    You can use \"hivex_open\" to read or write to the hive.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-windows-system-hive root",
  .run = run_inspect_get_windows_system_hive
};

struct command_entry inspect_is_netinst_cmd_entry = {
  .name = "inspect-is-netinst",
  .help = "NAME\n"
          "    inspect-is-netinst - get netinst (network installer) flag for install\n"
          "    disk\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-is-netinst root\n"
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
  .synopsis = "inspect-is-netinst root",
  .run = run_inspect_is_netinst
};

struct command_entry inspect_list_applications2_cmd_entry = {
  .name = "inspect-list-applications2",
  .help = "NAME\n"
          "    inspect-list-applications2 - get list of applications installed in the\n"
          "    operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-list-applications2 root\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the list of applications installed in the operating system.\n"
          "\n"
          "    *Note:* This call works differently from other parts of the inspection\n"
          "    API. You have to call \"inspect_os\", then \"inspect_get_mountpoints\", then\n"
          "    mount up the disks, before calling this. Listing applications is a\n"
          "    significantly more difficult operation which requires access to the full\n"
          "    filesystem. Also note that unlike the other \"inspect_get_*\" calls which\n"
          "    are just returning data cached in the libguestfs handle, this call\n"
          "    actually reads parts of the mounted filesystems during the call.\n"
          "\n"
          "    This returns an empty list if the inspection code was not able to\n"
          "    determine the list of applications.\n"
          "\n"
          "    The application structure contains the following fields:\n"
          "\n"
          "    \"app2_name\"\n"
          "        The name of the application. For Red Hat-derived and Debian-derived\n"
          "        Linux guests, this is the package name.\n"
          "\n"
          "    \"app2_display_name\"\n"
          "        The display name of the application, sometimes localized to the\n"
          "        install language of the guest operating system.\n"
          "\n"
          "        If unavailable this is returned as an empty string \"\". Callers\n"
          "        needing to display something can use \"app2_name\" instead.\n"
          "\n"
          "    \"app2_epoch\"\n"
          "        For package managers which use epochs, this contains the epoch of\n"
          "        the package (an integer). If unavailable, this is returned as 0.\n"
          "\n"
          "    \"app2_version\"\n"
          "        The version string of the application or package. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_release\"\n"
          "        The release string of the application or package, for package\n"
          "        managers that use this. If unavailable this is returned as an empty\n"
          "        string \"\".\n"
          "\n"
          "    \"app2_arch\"\n"
          "        The architecture string of the application or package, for package\n"
          "        managers that use this. If unavailable this is returned as an empty\n"
          "        string \"\".\n"
          "\n"
          "    \"app2_install_path\"\n"
          "        The installation path of the application (on operating systems such\n"
          "        as Windows which use installation paths). This path is in the format\n"
          "        used by the guest operating system, it is not a libguestfs path.\n"
          "\n"
          "        If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_trans_path\"\n"
          "        The install path translated into a libguestfs path. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_publisher\"\n"
          "        The name of the publisher of the application, for package managers\n"
          "        that use this. If unavailable this is returned as an empty string\n"
          "        \"\".\n"
          "\n"
          "    \"app2_url\"\n"
          "        The URL (eg. upstream URL) of the application. If unavailable this\n"
          "        is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_source_package\"\n"
          "        For packaging systems which support this, the name of the source\n"
          "        package. If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_summary\"\n"
          "        A short (usually one line) description of the application or\n"
          "        package. If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app2_description\"\n"
          "        A longer description of the application or package. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-list-applications2 root",
  .run = run_inspect_list_applications2
};

struct command_entry is_symlink_cmd_entry = {
  .name = "is-symlink",
  .help = "NAME\n"
          "    is-symlink - test if symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     is-symlink path\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a symbolic link with the\n"
          "    given \"path\" name.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "",
  .synopsis = "is-symlink path",
  .run = run_is_symlink
};

struct command_entry is_zero_cmd_entry = {
  .name = "is-zero",
  .help = "NAME\n"
          "    is-zero - test if a file contains all zero bytes\n"
          "\n"
          "SYNOPSIS\n"
          "     is-zero path\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns true iff the file exists and the file is empty or it\n"
          "    contains all zero bytes.\n"
          "\n"
          "",
  .synopsis = "is-zero path",
  .run = run_is_zero
};

struct command_entry lchown_cmd_entry = {
  .name = "lchown",
  .help = "NAME\n"
          "    lchown - change file owner and group\n"
          "\n"
          "SYNOPSIS\n"
          "     lchown owner group path\n"
          "\n"
          "DESCRIPTION\n"
          "    Change the file owner to \"owner\" and group to \"group\". This is like\n"
          "    \"chown\" but if \"path\" is a symlink then the link itself is changed, not\n"
          "    the target.\n"
          "\n"
          "    Only numeric uid and gid are supported. If you want to use names, you\n"
          "    will need to locate and parse the password file yourself (Augeas support\n"
          "    makes this relatively easy).\n"
          "\n"
          "",
  .synopsis = "lchown owner group path",
  .run = run_lchown
};

struct command_entry ldmtool_create_all_cmd_entry = {
  .name = "ldmtool-create-all",
  .help = "NAME\n"
          "    ldmtool-create-all - scan and create Windows dynamic disk volumes\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-create-all\n"
          "\n"
          "DESCRIPTION\n"
          "    This function scans all block devices looking for Windows dynamic disk\n"
          "    volumes and partitions, and creates devices for any that were found.\n"
          "\n"
          "    Call \"list_ldm_volumes\" and \"list_ldm_partitions\" to return all devices.\n"
          "\n"
          "    Note that you don't normally need to call this explicitly, since it is\n"
          "    done automatically at \"launch\" time. However you might want to call this\n"
          "    function if you have hotplugged disks or have just created a Windows\n"
          "    dynamic disk.\n"
          "\n"
          "",
  .synopsis = "ldmtool-create-all",
  .run = run_ldmtool_create_all
};

struct command_entry ldmtool_diskgroup_disks_cmd_entry = {
  .name = "ldmtool-diskgroup-disks",
  .help = "NAME\n"
          "    ldmtool-diskgroup-disks - return the disks in a Windows dynamic disk\n"
          "    group\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-diskgroup-disks diskgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the disks in a Windows dynamic disk group. The \"diskgroup\"\n"
          "    parameter should be the GUID of a disk group, one element from the list\n"
          "    returned by \"ldmtool_scan\".\n"
          "\n"
          "",
  .synopsis = "ldmtool-diskgroup-disks diskgroup",
  .run = run_ldmtool_diskgroup_disks
};

struct command_entry list_partitions_cmd_entry = {
  .name = "list-partitions",
  .help = "NAME\n"
          "    list-partitions - list the partitions\n"
          "\n"
          "SYNOPSIS\n"
          "     list-partitions\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the partitions detected on all block devices.\n"
          "\n"
          "    The full partition device names are returned, eg. /dev/sda1\n"
          "\n"
          "    This does not return logical volumes. For that you will need to call\n"
          "    \"lvs\".\n"
          "\n"
          "    See also \"list_filesystems\".\n"
          "\n"
          "",
  .synopsis = "list-partitions",
  .run = run_list_partitions
};

struct command_entry llz_cmd_entry = {
  .name = "llz",
  .help = "NAME\n"
          "    llz - list the files in a directory (long format with SELinux contexts)\n"
          "\n"
          "SYNOPSIS\n"
          "     llz directory\n"
          "\n"
          "DESCRIPTION\n"
          "    List the files in directory in the format of 'ls -laZ'.\n"
          "\n"
          "    This command is mostly useful for interactive sessions. It is *not*\n"
          "    intended that you try to parse the output string.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"lgetxattrs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "llz directory",
  .run = run_llz
};

struct command_entry lstat_cmd_entry = {
  .name = "lstat",
  .help = "NAME\n"
          "    lstat - get file information for a symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     lstat path\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns file information for the given \"path\".\n"
          "\n"
          "    This is the same as \"stat\" except that if \"path\" is a symbolic link,\n"
          "    then the link is stat-ed, not the file it refers to.\n"
          "\n"
          "    This is the same as the lstat(2) system call.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"lstatns\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "lstat path",
  .run = run_lstat
};

struct command_entry lstatlist_cmd_entry = {
  .name = "lstatlist",
  .help = "NAME\n"
          "    lstatlist - lstat on multiple files\n"
          "\n"
          "SYNOPSIS\n"
          "     lstatlist path names\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to perform the \"lstat\" operation on multiple files,\n"
          "    where all files are in the directory \"path\". \"names\" is the list of\n"
          "    files from this directory.\n"
          "\n"
          "    On return you get a list of stat structs, with a one-to-one\n"
          "    correspondence to the \"names\" list. If any name did not exist or could\n"
          "    not be lstat'd, then the \"st_ino\" field of that structure is set to -1.\n"
          "\n"
          "    This call is intended for programs that want to efficiently list a\n"
          "    directory contents without making many round-trips. See also\n"
          "    \"lxattrlist\" for a similarly efficient call for getting extended\n"
          "    attributes.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"lstatnslist\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "lstatlist path names",
  .run = run_lstatlist
};

struct command_entry luks_open_cmd_entry = {
  .name = "luks-open",
  .help = "NAME\n"
          "    luks-open - open a LUKS-encrypted block device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-open device mapname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command opens a block device which has been encrypted according to\n"
          "    the Linux Unified Key Setup (LUKS) standard.\n"
          "\n"
          "    \"device\" is the encrypted block device or partition.\n"
          "\n"
          "    The caller must supply one of the keys associated with the LUKS block\n"
          "    device, in the \"key\" parameter.\n"
          "\n"
          "    This creates a new block device called /dev/mapper/mapname. Reads and\n"
          "    writes to this block device are decrypted from and encrypted to the\n"
          "    underlying \"device\" respectively.\n"
          "\n"
          "    If this block device contains LVM volume groups, then calling \"vgscan\"\n"
          "    followed by \"vg_activate_all\" will make them visible.\n"
          "\n"
          "    Use \"list_dm_devices\" to list all device mapper devices.\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-open device mapname",
  .run = run_luks_open
};

struct command_entry luks_open_ro_cmd_entry = {
  .name = "luks-open-ro",
  .help = "NAME\n"
          "    luks-open-ro - open a LUKS-encrypted block device read-only\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-open-ro device mapname\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"luks_open\" except that a read-only mapping is\n"
          "    created.\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-open-ro device mapname",
  .run = run_luks_open_ro
};

struct command_entry lvm_remove_all_cmd_entry = {
  .name = "lvm-remove-all",
  .help = "NAME\n"
          "    lvm-remove-all - remove all LVM LVs, VGs and PVs\n"
          "\n"
          "SYNOPSIS\n"
          "     lvm-remove-all\n"
          "\n"
          "DESCRIPTION\n"
          "    This command removes all LVM logical volumes, volume groups and physical\n"
          "    volumes.\n"
          "\n"
          "",
  .synopsis = "lvm-remove-all",
  .run = run_lvm_remove_all
};

struct command_entry lvresize_free_cmd_entry = {
  .name = "lvresize-free",
  .help = "NAME\n"
          "    lvresize-free - expand an LV to fill free space\n"
          "\n"
          "SYNOPSIS\n"
          "     lvresize-free lv percent\n"
          "\n"
          "DESCRIPTION\n"
          "    This expands an existing logical volume \"lv\" so that it fills \"pc\"% of\n"
          "    the remaining free space in the volume group. Commonly you would call\n"
          "    this with pc = 100 which expands the logical volume as much as possible,\n"
          "    using all remaining free space in the volume group.\n"
          "\n"
          "",
  .synopsis = "lvresize-free lv percent",
  .run = run_lvresize_free
};

struct command_entry md_create_cmd_entry = {
  .name = "md-create",
  .help = "NAME\n"
          "    md-create - create a Linux md (RAID) device\n"
          "\n"
          "SYNOPSIS\n"
          "     md-create name devices [missingbitmap:N] [nrdevices:N] [spare:N] [chunk:N] [level:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a Linux md (RAID) device named \"name\" on the devices in the list\n"
          "    \"devices\".\n"
          "\n"
          "    The optional parameters are:\n"
          "\n"
          "    \"missingbitmap\"\n"
          "        A bitmap of missing devices. If a bit is set it means that a missing\n"
          "        device is added to the array. The least significant bit corresponds\n"
          "        to the first device in the array.\n"
          "\n"
          "        As examples:\n"
          "\n"
          "        If \"devices = [\"/dev/sda\"]\" and \"missingbitmap = 0x1\" then the\n"
          "        resulting array would be \"[<missing>, \"/dev/sda\"]\".\n"
          "\n"
          "        If \"devices = [\"/dev/sda\"]\" and \"missingbitmap = 0x2\" then the\n"
          "        resulting array would be \"[\"/dev/sda\", <missing>]\".\n"
          "\n"
          "        This defaults to 0 (no missing devices).\n"
          "\n"
          "        The length of \"devices\" + the number of bits set in \"missingbitmap\"\n"
          "        must equal \"nrdevices\" + \"spare\".\n"
          "\n"
          "    \"nrdevices\"\n"
          "        The number of active RAID devices.\n"
          "\n"
          "        If not set, this defaults to the length of \"devices\" plus the number\n"
          "        of bits set in \"missingbitmap\".\n"
          "\n"
          "    \"spare\"\n"
          "        The number of spare devices.\n"
          "\n"
          "        If not set, this defaults to 0.\n"
          "\n"
          "    \"chunk\"\n"
          "        The chunk size in bytes.\n"
          "\n"
          "    \"level\"\n"
          "        The RAID level, which can be one of: *linear*, *raid0*, *0*,\n"
          "        *stripe*, *raid1*, *1*, *mirror*, *raid4*, *4*, *raid5*, *5*,\n"
          "        *raid6*, *6*, *raid10*, *10*. Some of these are synonymous, and more\n"
          "        levels may be added in future.\n"
          "\n"
          "        If not set, this defaults to \"raid1\".\n"
          "\n"
          "",
  .synopsis = "md-create name devices [missingbitmap:N] [nrdevices:N] [spare:N] [chunk:N] [level:..]",
  .run = run_md_create
};

struct command_entry mkdtemp_cmd_entry = {
  .name = "mkdtemp",
  .help = "NAME\n"
          "    mkdtemp - create a temporary directory\n"
          "\n"
          "SYNOPSIS\n"
          "     mkdtemp tmpl\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a temporary directory. The \"tmpl\" parameter should\n"
          "    be a full pathname for the temporary directory name with the final six\n"
          "    characters being \"XXXXXX\".\n"
          "\n"
          "    For example: \"/tmp/myprogXXXXXX\" or \"/Temp/myprogXXXXXX\", the second one\n"
          "    being suitable for Windows filesystems.\n"
          "\n"
          "    The name of the temporary directory that was created is returned.\n"
          "\n"
          "    The temporary directory is created with mode 0700 and is owned by root.\n"
          "\n"
          "    The caller is responsible for deleting the temporary directory and its\n"
          "    contents after use.\n"
          "\n"
          "    See also: mkdtemp(3)\n"
          "\n"
          "",
  .synopsis = "mkdtemp tmpl",
  .run = run_mkdtemp
};

struct command_entry mknod_cmd_entry = {
  .name = "mknod",
  .help = "NAME\n"
          "    mknod - make block, character or FIFO devices\n"
          "\n"
          "SYNOPSIS\n"
          "     mknod mode devmajor devminor path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates block or character special devices, or named pipes\n"
          "    (FIFOs).\n"
          "\n"
          "    The \"mode\" parameter should be the mode, using the standard constants.\n"
          "    \"devmajor\" and \"devminor\" are the device major and minor numbers, only\n"
          "    used when creating block and character special devices.\n"
          "\n"
          "    Note that, just like mknod(2), the mode must be bitwise OR'd with\n"
          "    S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK (otherwise this call just creates\n"
          "    a regular file). These constants are available in the standard Linux\n"
          "    header files, or you can use \"mknod_b\", \"mknod_c\" or \"mkfifo\" which are\n"
          "    wrappers around this command which bitwise OR in the appropriate\n"
          "    constant for you.\n"
          "\n"
          "    The mode actually set is affected by the umask.\n"
          "\n"
          "",
  .synopsis = "mknod mode devmajor devminor path",
  .run = run_mknod
};

struct command_entry mount_cmd_entry = {
  .name = "mount",
  .help = "NAME\n"
          "    mount - mount a guest disk at a position in the filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mount mountable mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    Mount a guest disk at a position in the filesystem. Block devices are\n"
          "    named /dev/sda, /dev/sdb and so on, as they were added to the guest. If\n"
          "    those block devices contain partitions, they will have the usual names\n"
          "    (eg. /dev/sda1). Also LVM /dev/VG/LV-style names can be used, or\n"
          "    ‘mountable’ strings returned by \"list_filesystems\" or\n"
          "    \"inspect_get_mountpoints\".\n"
          "\n"
          "    The rules are the same as for mount(2): A filesystem must first be\n"
          "    mounted on / before others can be mounted. Other filesystems can only be\n"
          "    mounted on directories which already exist.\n"
          "\n"
          "    The mounted filesystem is writable, if we have sufficient permissions on\n"
          "    the underlying device.\n"
          "\n"
          "    Before libguestfs 1.13.16, this call implicitly added the options \"sync\"\n"
          "    and \"noatime\". The \"sync\" option greatly slowed writes and caused many\n"
          "    problems for users. If your program might need to work with older\n"
          "    versions of libguestfs, use \"mount_options\" instead (using an empty\n"
          "    string for the first parameter if you don't want any options).\n"
          "\n"
          "",
  .synopsis = "mount mountable mountpoint",
  .run = run_mount
};

struct command_entry mount_local_run_cmd_entry = {
  .name = "mount-local-run",
  .help = "NAME\n"
          "    mount-local-run - run main loop of mount on the local filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-local-run\n"
          "\n"
          "DESCRIPTION\n"
          "    Run the main loop which translates kernel calls to libguestfs calls.\n"
          "\n"
          "    This should only be called after \"mount_local\" returns successfully. The\n"
          "    call will not return until the filesystem is unmounted.\n"
          "\n"
          "    Note you must *not* make concurrent libguestfs calls on the same handle\n"
          "    from another thread.\n"
          "\n"
          "    You may call this from a different thread than the one which called\n"
          "    \"mount_local\", subject to the usual rules for threads and libguestfs\n"
          "    (see \"MULTIPLE HANDLES AND MULTIPLE THREADS\" in guestfs(3)).\n"
          "\n"
          "    See \"MOUNT LOCAL\" in guestfs(3) for full documentation.\n"
          "\n"
          "",
  .synopsis = "mount-local-run",
  .run = run_mount_local_run
};

struct command_entry mount_ro_cmd_entry = {
  .name = "mount-ro",
  .help = "NAME\n"
          "    mount-ro - mount a guest disk, read-only\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-ro mountable mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as the \"mount\" command, but it mounts the filesystem\n"
          "    with the read-only (*-o ro*) flag.\n"
          "\n"
          "",
  .synopsis = "mount-ro mountable mountpoint",
  .run = run_mount_ro
};

struct command_entry mountable_subvolume_cmd_entry = {
  .name = "mountable-subvolume",
  .help = "NAME\n"
          "    mountable-subvolume - extract the subvolume part of a mountable\n"
          "\n"
          "SYNOPSIS\n"
          "     mountable-subvolume mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns the subvolume path of a mountable. Btrfs subvolumes mountables\n"
          "    are a combination of both the device name and the subvolume path (see\n"
          "    also \"mountable_device\" to extract the device of the mountable).\n"
          "\n"
          "    If the mountable does not represent a btrfs subvolume, then this\n"
          "    function fails and the \"errno\" is set to \"EINVAL\".\n"
          "\n"
          "",
  .synopsis = "mountable-subvolume mountable",
  .run = run_mountable_subvolume
};

struct command_entry mounts_cmd_entry = {
  .name = "mounts",
  .help = "NAME\n"
          "    mounts - show mounted filesystems\n"
          "\n"
          "SYNOPSIS\n"
          "     mounts\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the list of currently mounted filesystems. It returns the\n"
          "    list of devices (eg. /dev/sda1, /dev/VG/LV).\n"
          "\n"
          "    Some internal mounts are not shown.\n"
          "\n"
          "    See also: \"mountpoints\"\n"
          "\n"
          "",
  .synopsis = "mounts",
  .run = run_mounts
};

struct command_entry ntfs_3g_probe_cmd_entry = {
  .name = "ntfs-3g-probe",
  .help = "NAME\n"
          "    ntfs-3g-probe - probe NTFS volume\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfs-3g-probe rw device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command runs the ntfs-3g.probe(8) command which probes an NTFS\n"
          "    \"device\" for mountability. (Not all NTFS volumes can be mounted\n"
          "    read-write, and some cannot be mounted at all).\n"
          "\n"
          "    \"rw\" is a boolean flag. Set it to true if you want to test if the volume\n"
          "    can be mounted read-write. Set it to false if you want to test if the\n"
          "    volume can be mounted read-only.\n"
          "\n"
          "    The return value is an integer which 0 if the operation would succeed,\n"
          "    or some non-zero value documented in the ntfs-3g.probe(8) manual page.\n"
          "\n"
          "",
  .synopsis = "ntfs-3g-probe rw device",
  .run = run_ntfs_3g_probe
};

struct command_entry ntfsclone_out_cmd_entry = {
  .name = "ntfsclone-out",
  .help = "NAME\n"
          "    ntfsclone-out - save NTFS to backup file\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfsclone-out device backupfile [metadataonly:true|false] [rescue:true|false] [ignorefscheck:true|false] [preservetimestamps:true|false] [force:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Stream the NTFS filesystem \"device\" to the local file \"backupfile\". The\n"
          "    format used for the backup file is a special format used by the\n"
          "    ntfsclone(8) tool.\n"
          "\n"
          "    If the optional \"metadataonly\" flag is true, then *only* the metadata is\n"
          "    saved, losing all the user data (this is useful for diagnosing some\n"
          "    filesystem problems).\n"
          "\n"
          "    The optional \"rescue\", \"ignorefscheck\", \"preservetimestamps\" and \"force\"\n"
          "    flags have precise meanings detailed in the ntfsclone(8) man page.\n"
          "\n"
          "    Use \"ntfsclone_in\" to restore the file back to a libguestfs device.\n"
          "\n"
          "",
  .synopsis = "ntfsclone-out device backupfile [metadataonly:true|false] [rescue:true|false] [ignorefscheck:true|false] [preservetimestamps:true|false] [force:true|false]",
  .run = run_ntfsclone_out
};

struct command_entry part_resize_cmd_entry = {
  .name = "part-resize",
  .help = "NAME\n"
          "    part-resize - resize a partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-resize device partnum endsect\n"
          "\n"
          "DESCRIPTION\n"
          "    This command resizes the partition numbered \"partnum\" on \"device\" by\n"
          "    moving the end position.\n"
          "\n"
          "    Note that this does not modify any filesystem present in the partition.\n"
          "    If you wish to do this, you will need to use filesystem resizing\n"
          "    commands like \"resize2fs\".\n"
          "\n"
          "    When growing a partition you will want to grow the filesystem\n"
          "    afterwards, but when shrinking, you need to shrink the filesystem before\n"
          "    the partition.\n"
          "\n"
          "",
  .synopsis = "part-resize device partnum endsect",
  .run = run_part_resize
};

struct command_entry part_set_disk_guid_cmd_entry = {
  .name = "part-set-disk-guid",
  .help = "NAME\n"
          "    part-set-disk-guid - set the GUID of a GPT-partitioned disk\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-disk-guid device guid\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the disk identifier (GUID) of a GPT-partitioned \"device\" to \"guid\".\n"
          "    Return an error if the partition table of \"device\" isn't GPT, or if\n"
          "    \"guid\" is not a valid GUID.\n"
          "\n"
          "",
  .synopsis = "part-set-disk-guid device guid",
  .run = run_part_set_disk_guid
};

struct command_entry part_set_disk_guid_random_cmd_entry = {
  .name = "part-set-disk-guid-random",
  .help = "NAME\n"
          "    part-set-disk-guid-random - set the GUID of a GPT-partitioned disk to\n"
          "    random value\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-disk-guid-random device\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the disk identifier (GUID) of a GPT-partitioned \"device\" to a\n"
          "    randomly generated value. Return an error if the partition table of\n"
          "    \"device\" isn't GPT.\n"
          "\n"
          "",
  .synopsis = "part-set-disk-guid-random device",
  .run = run_part_set_disk_guid_random
};

struct command_entry pread_cmd_entry = {
  .name = "pread",
  .help = "NAME\n"
          "    pread - read part of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     pread path count offset\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lets you read part of a file. It reads \"count\" bytes of the\n"
          "    file, starting at \"offset\", from file \"path\".\n"
          "\n"
          "    This may read fewer bytes than requested. For further details see the\n"
          "    pread(2) system call.\n"
          "\n"
          "    See also \"pwrite\", \"pread_device\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "pread path count offset",
  .run = run_pread
};

struct command_entry realpath_cmd_entry = {
  .name = "realpath",
  .help = "NAME\n"
          "    realpath - canonicalized absolute pathname\n"
          "\n"
          "SYNOPSIS\n"
          "     realpath path\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the canonicalized absolute pathname of \"path\". The returned path\n"
          "    has no \".\", \"..\" or symbolic link path elements.\n"
          "\n"
          "",
  .synopsis = "realpath path",
  .run = run_realpath
};

struct command_entry selinux_relabel_cmd_entry = {
  .name = "selinux-relabel",
  .help = "NAME\n"
          "    selinux-relabel - relabel parts of the filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     selinux-relabel specfile path [force:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    SELinux relabel parts of the filesystem.\n"
          "\n"
          "    The \"specfile\" parameter controls the policy spec file used. You have to\n"
          "    parse \"/etc/selinux/config\" to find the correct SELinux policy and then\n"
          "    pass the spec file, usually: \"/etc/selinux/\" + *selinuxtype* +\n"
          "    \"/contexts/files/file_contexts\".\n"
          "\n"
          "    The required \"path\" parameter is the top level directory where\n"
          "    relabelling starts. Normally you should pass \"path\" as \"/\" to relabel\n"
          "    the whole guest filesystem.\n"
          "\n"
          "    The optional \"force\" boolean controls whether the context is reset for\n"
          "    customizable files, and also whether the user, role and range parts of\n"
          "    the file context is changed.\n"
          "\n"
          "",
  .synopsis = "selinux-relabel specfile path [force:true|false]",
  .run = run_selinux_relabel
};

struct command_entry set_autosync_cmd_entry = {
  .name = "set-autosync",
  .help = "NAME\n"
          "    set-autosync - set autosync mode\n"
          "\n"
          "SYNOPSIS\n"
          "     set-autosync autosync\n"
          "\n"
          "DESCRIPTION\n"
          "    If \"autosync\" is true, this enables autosync. Libguestfs will make a\n"
          "    best effort attempt to make filesystems consistent and synchronized when\n"
          "    the handle is closed (also if the program exits without closing\n"
          "    handles).\n"
          "\n"
          "    This is enabled by default (since libguestfs 1.5.24, previously it was\n"
          "    disabled by default).\n"
          "\n"
          "    You can use 'autosync' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-autosync autosync",
  .run = run_set_autosync
};

struct command_entry set_backend_setting_cmd_entry = {
  .name = "set-backend-setting",
  .help = "NAME\n"
          "    set-backend-setting - set a single per-backend settings string\n"
          "\n"
          "SYNOPSIS\n"
          "     set-backend-setting name val\n"
          "\n"
          "DESCRIPTION\n"
          "    Append \"name=value\" to the backend settings string list. However if a\n"
          "    string already exists matching \"name\" or beginning with \"name=\", then\n"
          "    that setting is replaced.\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3), \"BACKEND SETTINGS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "set-backend-setting name val",
  .run = run_set_backend_setting
};

struct command_entry set_identifier_cmd_entry = {
  .name = "set-identifier",
  .help = "NAME\n"
          "    set-identifier - set the handle identifier\n"
          "\n"
          "SYNOPSIS\n"
          "     set-identifier identifier\n"
          "\n"
          "DESCRIPTION\n"
          "    This is an informative string which the caller may optionally set in the\n"
          "    handle. It is printed in various places, allowing the current handle to\n"
          "    be identified in debugging output.\n"
          "\n"
          "    One important place is when tracing is enabled. If the identifier string\n"
          "    is not an empty string, then trace messages change from this:\n"
          "\n"
          "     libguestfs: trace: get_tmpdir\n"
          "     libguestfs: trace: get_tmpdir = \"/tmp\"\n"
          "\n"
          "    to this:\n"
          "\n"
          "     libguestfs: trace: ID: get_tmpdir\n"
          "     libguestfs: trace: ID: get_tmpdir = \"/tmp\"\n"
          "\n"
          "    where \"ID\" is the identifier string set by this call.\n"
          "\n"
          "    The identifier must only contain alphanumeric ASCII characters,\n"
          "    underscore and minus sign. The default is the empty string.\n"
          "\n"
          "    See also \"set_program\", \"set_trace\", \"get_identifier\".\n"
          "\n"
          "    You can use 'identifier' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-identifier identifier",
  .run = run_set_identifier
};

struct command_entry set_verbose_cmd_entry = {
  .name = "set-verbose",
  .help = "NAME\n"
          "    set-verbose - set verbose mode\n"
          "\n"
          "SYNOPSIS\n"
          "     set-verbose verbose\n"
          "\n"
          "DESCRIPTION\n"
          "    If \"verbose\" is true, this turns on verbose messages.\n"
          "\n"
          "    Verbose messages are disabled unless the environment variable\n"
          "    \"LIBGUESTFS_DEBUG\" is defined and set to 1.\n"
          "\n"
          "    Verbose messages are normally sent to \"stderr\", unless you register a\n"
          "    callback to send them somewhere else (see \"set_event_callback\").\n"
          "\n"
          "    You can use 'verbose' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-verbose verbose",
  .run = run_set_verbose
};

struct command_entry swapoff_file_cmd_entry = {
  .name = "swapoff-file",
  .help = "NAME\n"
          "    swapoff-file - disable swap on file\n"
          "\n"
          "SYNOPSIS\n"
          "     swapoff-file file\n"
          "\n"
          "DESCRIPTION\n"
          "    This command disables the libguestfs appliance swap on file.\n"
          "\n"
          "",
  .synopsis = "swapoff-file file",
  .run = run_swapoff_file
};

struct command_entry syslinux_cmd_entry = {
  .name = "syslinux",
  .help = "NAME\n"
          "    syslinux - install the SYSLINUX bootloader\n"
          "\n"
          "SYNOPSIS\n"
          "     syslinux device [directory:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Install the SYSLINUX bootloader on \"device\".\n"
          "\n"
          "    The device parameter must be either a whole disk formatted as a FAT\n"
          "    filesystem, or a partition formatted as a FAT filesystem. In the latter\n"
          "    case, the partition should be marked as \"active\" (\"part_set_bootable\")\n"
          "    and a Master Boot Record must be installed (eg. using \"pwrite_device\")\n"
          "    on the first sector of the whole disk. The SYSLINUX package comes with\n"
          "    some suitable Master Boot Records. See the syslinux(1) man page for\n"
          "    further information.\n"
          "\n"
          "    The optional arguments are:\n"
          "\n"
          "    directory\n"
          "        Install SYSLINUX in the named subdirectory, instead of in the root\n"
          "        directory of the FAT filesystem.\n"
          "\n"
          "    Additional configuration can be supplied to SYSLINUX by placing a file\n"
          "    called syslinux.cfg on the FAT filesystem, either in the root directory,\n"
          "    or under directory if that optional argument is being used. For further\n"
          "    information about the contents of this file, see syslinux(1).\n"
          "\n"
          "    See also \"extlinux\".\n"
          "\n"
          "",
  .synopsis = "syslinux device [directory:..]",
  .run = run_syslinux
};

struct command_entry tail_cmd_entry = {
  .name = "tail",
  .help = "NAME\n"
          "    tail - return last 10 lines of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     tail path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns up to the last 10 lines of a file as a list of\n"
          "    strings.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "tail path",
  .run = run_tail
};

struct command_entry touch_cmd_entry = {
  .name = "touch",
  .help = "NAME\n"
          "    touch - update file timestamps or create a new file\n"
          "\n"
          "SYNOPSIS\n"
          "     touch path\n"
          "\n"
          "DESCRIPTION\n"
          "    Touch acts like the touch(1) command. It can be used to update the\n"
          "    timestamps on a file, or, if the file does not exist, to create a new\n"
          "    zero-length file.\n"
          "\n"
          "    This command only works on regular files, and will fail on other file\n"
          "    types such as directories, symbolic links, block special etc.\n"
          "\n"
          "",
  .synopsis = "touch path",
  .run = run_touch
};

struct command_entry tune2fs_l_cmd_entry = {
  .name = "tune2fs-l",
  .help = "NAME\n"
          "    tune2fs-l - get ext2/ext3/ext4 superblock details\n"
          "\n"
          "SYNOPSIS\n"
          "     tune2fs-l device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the contents of the ext2, ext3 or ext4 filesystem\n"
          "    superblock on \"device\".\n"
          "\n"
          "    It is the same as running \"tune2fs -l device\". See tune2fs(8) manpage\n"
          "    for more details. The list of fields returned isn't clearly defined, and\n"
          "    depends on both the version of \"tune2fs\" that libguestfs was built\n"
          "    against, and the filesystem itself.\n"
          "\n"
          "",
  .synopsis = "tune2fs-l device",
  .run = run_tune2fs_l
};

struct command_entry umount_cmd_entry = {
  .name = "umount",
  .help = "NAME\n"
          "    umount - unmount a filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     umount pathordevice [force:true|false] [lazyunmount:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This unmounts the given filesystem. The filesystem may be specified\n"
          "    either by its mountpoint (path) or the device which contains the\n"
          "    filesystem.\n"
          "\n"
          "    You can use 'unmount' or 'umount-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "umount pathordevice [force:true|false] [lazyunmount:true|false]",
  .run = run_umount
};

struct command_entry vg_activate_cmd_entry = {
  .name = "vg-activate",
  .help = "NAME\n"
          "    vg-activate - activate or deactivate some volume groups\n"
          "\n"
          "SYNOPSIS\n"
          "     vg-activate activate volgroups\n"
          "\n"
          "DESCRIPTION\n"
          "    This command activates or (if \"activate\" is false) deactivates all\n"
          "    logical volumes in the listed volume groups \"volgroups\".\n"
          "\n"
          "    This command is the same as running \"vgchange -a y|n volgroups...\"\n"
          "\n"
          "    Note that if \"volgroups\" is an empty list then all volume groups are\n"
          "    activated or deactivated.\n"
          "\n"
          "",
  .synopsis = "vg-activate activate volgroups",
  .run = run_vg_activate
};

struct command_entry vgs_full_cmd_entry = {
  .name = "vgs-full",
  .help = "NAME\n"
          "    vgs-full - list the LVM volume groups (VGs)\n"
          "\n"
          "SYNOPSIS\n"
          "     vgs-full\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the volumes groups detected. This is the equivalent of the\n"
          "    vgs(8) command. The \"full\" version includes all fields.\n"
          "\n"
          "",
  .synopsis = "vgs-full",
  .run = run_vgs_full
};

struct command_entry vgscan_cmd_entry = {
  .name = "vgscan",
  .help = "NAME\n"
          "    vgscan - rescan for LVM physical volumes, volume groups and logical\n"
          "    volumes\n"
          "\n"
          "SYNOPSIS\n"
          "     vgscan\n"
          "\n"
          "DESCRIPTION\n"
          "    This rescans all block devices and rebuilds the list of LVM physical\n"
          "    volumes, volume groups and logical volumes.\n"
          "\n"
          "",
  .synopsis = "vgscan",
  .run = run_vgscan
};

struct command_entry xfs_admin_cmd_entry = {
  .name = "xfs-admin",
  .help = "NAME\n"
          "    xfs-admin - change parameters of an XFS filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     xfs-admin device [extunwritten:true|false] [imgfile:true|false] [v2log:true|false] [projid32bit:true|false] [lazycounter:true|false] [label:..] [uuid:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Change the parameters of the XFS filesystem on \"device\".\n"
          "\n"
          "    Devices that are mounted cannot be modified. Administrators must unmount\n"
          "    filesystems before this call can modify parameters.\n"
          "\n"
          "    Some of the parameters of a mounted filesystem can be examined and\n"
          "    modified using the \"xfs_info\" and \"xfs_growfs\" calls.\n"
          "\n"
          "",
  .synopsis = "xfs-admin device [extunwritten:true|false] [imgfile:true|false] [v2log:true|false] [projid32bit:true|false] [lazycounter:true|false] [label:..] [uuid:..]",
  .run = run_xfs_admin
};

struct command_entry yara_destroy_cmd_entry = {
  .name = "yara-destroy",
  .help = "NAME\n"
          "    yara-destroy - destroy previously loaded yara rules\n"
          "\n"
          "SYNOPSIS\n"
          "     yara-destroy\n"
          "\n"
          "DESCRIPTION\n"
          "    Destroy previously loaded Yara rules in order to free libguestfs\n"
          "    resources.\n"
          "\n"
          "",
  .synopsis = "yara-destroy",
  .run = run_yara_destroy
};

struct command_entry zegrepi_cmd_entry = {
  .name = "zegrepi",
  .help = "NAME\n"
          "    zegrepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zegrepi regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zegrep -i\" program and returns the matching\n"
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
  .synopsis = "zegrepi regex path",
  .run = run_zegrepi
};

struct command_entry zfgrep_cmd_entry = {
  .name = "zfgrep",
  .help = "NAME\n"
          "    zfgrep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zfgrep pattern path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zfgrep\" program and returns the matching lines.\n"
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
  .synopsis = "zfgrep pattern path",
  .run = run_zfgrep
};

struct command_entry zfile_cmd_entry = {
  .name = "zfile",
  .help = "NAME\n"
          "    zfile - determine file type inside a compressed file\n"
          "\n"
          "SYNOPSIS\n"
          "     zfile meth path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command runs file after first decompressing \"path\" using \"method\".\n"
          "\n"
          "    \"method\" must be one of \"gzip\", \"compress\" or \"bzip2\".\n"
          "\n"
          "    Since 1.0.63, use \"file\" instead which can now process compressed files.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"file\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "zfile meth path",
  .run = run_zfile
};

