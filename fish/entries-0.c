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

struct command_entry acl_delete_def_file_cmd_entry = {
  .name = "acl-delete-def-file",
  .help = "NAME\n"
          "    acl-delete-def-file - delete the default POSIX ACL of a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     acl-delete-def-file dir\n"
          "\n"
          "DESCRIPTION\n"
          "    This function deletes the default POSIX Access Control List (ACL)\n"
          "    attached to directory \"dir\".\n"
          "\n"
          "",
  .synopsis = "acl-delete-def-file dir",
  .run = run_acl_delete_def_file
};

struct command_entry add_domain_cmd_entry = {
  .name = "add-domain",
  .help = "NAME\n"
          "    add-domain - add the disk(s) from a named libvirt domain\n"
          "\n"
          "SYNOPSIS\n"
          "     add-domain dom [libvirturi:..] [readonly:true|false] [iface:..] [live:true|false] [allowuuid:true|false] [readonlydisk:..] [cachemode:..] [discard:..] [copyonread:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This function adds the disk(s) attached to the named libvirt domain\n"
          "    \"dom\". It works by connecting to libvirt, requesting the domain and\n"
          "    domain XML from libvirt, parsing it for disks, and calling\n"
          "    \"add_drive_opts\" on each one.\n"
          "\n"
          "    The number of disks added is returned. This operation is atomic: if an\n"
          "    error is returned, then no disks are added.\n"
          "\n"
          "    This function does some minimal checks to make sure the libvirt domain\n"
          "    is not running (unless \"readonly\" is true). In a future version we will\n"
          "    try to acquire the libvirt lock on each disk.\n"
          "\n"
          "    Disks must be accessible locally. This often means that adding disks\n"
          "    from a remote libvirt connection (see <http://libvirt.org/remote.html>)\n"
          "    will fail unless those disks are accessible via the same device path\n"
          "    locally too.\n"
          "\n"
          "    The optional \"libvirturi\" parameter sets the libvirt URI (see\n"
          "    <http://libvirt.org/uri.html>). If this is not set then we connect to\n"
          "    the default libvirt URI (or one set through an environment variable, see\n"
          "    the libvirt documentation for full details).\n"
          "\n"
          "    The optional \"live\" flag controls whether this call will try to connect\n"
          "    to a running virtual machine \"guestfsd\" process if it sees a suitable\n"
          "    <channel> element in the libvirt XML definition. The default (if the\n"
          "    flag is omitted) is never to try. See \"ATTACHING TO RUNNING DAEMONS\" in\n"
          "    guestfs(3) for more information.\n"
          "\n"
          "    If the \"allowuuid\" flag is true (default is false) then a UUID *may* be\n"
          "    passed instead of the domain name. The \"dom\" string is treated as a UUID\n"
          "    first and looked up, and if that lookup fails then we treat \"dom\" as a\n"
          "    name as usual.\n"
          "\n"
          "    The optional \"readonlydisk\" parameter controls what we do for disks\n"
          "    which are marked <readonly/> in the libvirt XML. Possible values are:\n"
          "\n"
          "    readonlydisk = \"error\"\n"
          "        If \"readonly\" is false:\n"
          "\n"
          "        The whole call is aborted with an error if any disk with the\n"
          "        <readonly/> flag is found.\n"
          "\n"
          "        If \"readonly\" is true:\n"
          "\n"
          "        Disks with the <readonly/> flag are added read-only.\n"
          "\n"
          "    readonlydisk = \"read\"\n"
          "        If \"readonly\" is false:\n"
          "\n"
          "        Disks with the <readonly/> flag are added read-only. Other disks are\n"
          "        added read/write.\n"
          "\n"
          "        If \"readonly\" is true:\n"
          "\n"
          "        Disks with the <readonly/> flag are added read-only.\n"
          "\n"
          "    readonlydisk = \"write\" (default)\n"
          "        If \"readonly\" is false:\n"
          "\n"
          "        Disks with the <readonly/> flag are added read/write.\n"
          "\n"
          "        If \"readonly\" is true:\n"
          "\n"
          "        Disks with the <readonly/> flag are added read-only.\n"
          "\n"
          "    readonlydisk = \"ignore\"\n"
          "        If \"readonly\" is true or false:\n"
          "\n"
          "        Disks with the <readonly/> flag are skipped.\n"
          "\n"
          "    The other optional parameters are passed directly through to\n"
          "    \"add_drive_opts\".\n"
          "\n"
          "    You can use 'domain' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "add-domain dom [libvirturi:..] [readonly:true|false] [iface:..] [live:true|false] [allowuuid:true|false] [readonlydisk:..] [cachemode:..] [discard:..] [copyonread:true|false]",
  .run = run_add_domain
};

struct command_entry add_drive_ro_cmd_entry = {
  .name = "add-drive-ro",
  .help = "NAME\n"
          "    add-drive-ro - add a drive in snapshot mode (read-only)\n"
          "\n"
          "SYNOPSIS\n"
          "     add-drive-ro filename\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is the equivalent of calling \"add_drive_opts\" with the\n"
          "    optional parameter \"GUESTFS_ADD_DRIVE_OPTS_READONLY\" set to 1, so the\n"
          "    disk is added read-only, with the format being detected automatically.\n"
          "\n"
          "    You can use 'add-ro' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "add-drive-ro filename",
  .run = run_add_drive_ro
};

struct command_entry add_drive_ro_with_if_cmd_entry = {
  .name = "add-drive-ro-with-if",
  .help = "NAME\n"
          "    add-drive-ro-with-if - add a drive read-only specifying the QEMU block\n"
          "    emulation to use\n"
          "\n"
          "SYNOPSIS\n"
          "     add-drive-ro-with-if filename iface\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"add_drive_ro\" but it allows you to specify the QEMU\n"
          "    interface emulation to use at run time.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"add-drive\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "add-drive-ro-with-if filename iface",
  .run = run_add_drive_ro_with_if
};

struct command_entry aug_ls_cmd_entry = {
  .name = "aug-ls",
  .help = "NAME\n"
          "    aug-ls - list Augeas nodes under augpath\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-ls augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    This is just a shortcut for listing \"aug_match\" \"path/*\" and sorting the\n"
          "    resulting nodes into alphabetical order.\n"
          "\n"
          "",
  .synopsis = "aug-ls augpath",
  .run = run_aug_ls
};

struct command_entry aug_match_cmd_entry = {
  .name = "aug-match",
  .help = "NAME\n"
          "    aug-match - return Augeas nodes which match augpath\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-match augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns a list of paths which match the path expression \"path\". The\n"
          "    returned paths are sufficiently qualified so that they match exactly one\n"
          "    node in the current tree.\n"
          "\n"
          "",
  .synopsis = "aug-match augpath",
  .run = run_aug_match
};

struct command_entry aug_transform_cmd_entry = {
  .name = "aug-transform",
  .help = "NAME\n"
          "    aug-transform - add/remove an Augeas lens transformation\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-transform lens file [remove:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    Add an Augeas transformation for the specified \"lens\" so it can handle\n"
          "    \"file\".\n"
          "\n"
          "    If \"remove\" is true (\"false\" by default), then the transformation is\n"
          "    removed.\n"
          "\n"
          "",
  .synopsis = "aug-transform lens file [remove:true|false]",
  .run = run_aug_transform
};

struct command_entry btrfs_qgroup_create_cmd_entry = {
  .name = "btrfs-qgroup-create",
  .help = "NAME\n"
          "    btrfs-qgroup-create - create a subvolume quota group\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-create qgroupid subvolume\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a quota group (qgroup) for subvolume at \"subvolume\".\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-create qgroupid subvolume",
  .run = run_btrfs_qgroup_create
};

struct command_entry btrfs_rescue_super_recover_cmd_entry = {
  .name = "btrfs-rescue-super-recover",
  .help = "NAME\n"
          "    btrfs-rescue-super-recover - recover bad superblocks from good copies\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-rescue-super-recover device\n"
          "\n"
          "DESCRIPTION\n"
          "    Recover bad superblocks from good copies.\n"
          "\n"
          "",
  .synopsis = "btrfs-rescue-super-recover device",
  .run = run_btrfs_rescue_super_recover
};

struct command_entry btrfstune_enable_extended_inode_refs_cmd_entry = {
  .name = "btrfstune-enable-extended-inode-refs",
  .help = "NAME\n"
          "    btrfstune-enable-extended-inode-refs - enable extended inode refs\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfstune-enable-extended-inode-refs device\n"
          "\n"
          "DESCRIPTION\n"
          "    This will Enable extended inode refs.\n"
          "\n"
          "",
  .synopsis = "btrfstune-enable-extended-inode-refs device",
  .run = run_btrfstune_enable_extended_inode_refs
};

struct command_entry command_lines_cmd_entry = {
  .name = "command-lines",
  .help = "NAME\n"
          "    command-lines - run a command, returning lines\n"
          "\n"
          "SYNOPSIS\n"
          "     command-lines arguments\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"command\", but splits the result into a list of\n"
          "    lines.\n"
          "\n"
          "    See also: \"sh_lines\"\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "command-lines arguments",
  .run = run_command_lines
};

struct command_entry compress_device_out_cmd_entry = {
  .name = "compress-device-out",
  .help = "NAME\n"
          "    compress-device-out - output compressed device\n"
          "\n"
          "SYNOPSIS\n"
          "     compress-device-out ctype device zdevice [level:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command compresses \"device\" and writes it out to the local file\n"
          "    \"zdevice\".\n"
          "\n"
          "    The \"ctype\" and optional \"level\" parameters have the same meaning as in\n"
          "    \"compress_out\".\n"
          "\n"
          "",
  .synopsis = "compress-device-out ctype device zdevice [level:N]",
  .run = run_compress_device_out
};

struct command_entry compress_out_cmd_entry = {
  .name = "compress-out",
  .help = "NAME\n"
          "    compress-out - output compressed file\n"
          "\n"
          "SYNOPSIS\n"
          "     compress-out ctype file zfile [level:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command compresses file and writes it out to the local file zfile.\n"
          "\n"
          "    The compression program used is controlled by the \"ctype\" parameter.\n"
          "    Currently this includes: \"compress\", \"gzip\", \"bzip2\", \"xz\" or \"lzop\".\n"
          "    Some compression types may not be supported by particular builds of\n"
          "    libguestfs, in which case you will get an error containing the substring\n"
          "    \"not supported\".\n"
          "\n"
          "    The optional \"level\" parameter controls compression level. The meaning\n"
          "    and default for this parameter depends on the compression program being\n"
          "    used.\n"
          "\n"
          "",
  .synopsis = "compress-out ctype file zfile [level:N]",
  .run = run_compress_out
};

struct command_entry cp_cmd_entry = {
  .name = "cp",
  .help = "NAME\n"
          "    cp - copy a file\n"
          "\n"
          "SYNOPSIS\n"
          "     cp src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    This copies a file from \"src\" to \"dest\" where \"dest\" is either a\n"
          "    destination filename or destination directory.\n"
          "\n"
          "",
  .synopsis = "cp src dest",
  .run = run_cp
};

struct command_entry df_h_cmd_entry = {
  .name = "df-h",
  .help = "NAME\n"
          "    df-h - report file system disk space usage (human readable)\n"
          "\n"
          "SYNOPSIS\n"
          "     df-h\n"
          "\n"
          "DESCRIPTION\n"
          "    This command runs the \"df -h\" command to report disk space used in\n"
          "    human-readable format.\n"
          "\n"
          "    This command is mostly useful for interactive sessions. It is *not*\n"
          "    intended that you try to parse the output string. Use \"statvfs\" from\n"
          "    programs.\n"
          "\n"
          "",
  .synopsis = "df-h",
  .run = run_df_h
};

struct command_entry disk_has_backing_file_cmd_entry = {
  .name = "disk-has-backing-file",
  .help = "NAME\n"
          "    disk-has-backing-file - return whether disk has a backing file\n"
          "\n"
          "SYNOPSIS\n"
          "     disk-has-backing-file filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Detect and return whether the disk image filename has a backing file.\n"
          "\n"
          "    Note that detecting disk features can be insecure under some\n"
          "    circumstances. See \"CVE-2010-3851\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "disk-has-backing-file filename",
  .run = run_disk_has_backing_file
};

struct command_entry e2fsck_cmd_entry = {
  .name = "e2fsck",
  .help = "NAME\n"
          "    e2fsck - check an ext2/ext3 filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     e2fsck device [correct:true|false] [forceall:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs the ext2/ext3 filesystem checker on \"device\". It can take the\n"
          "    following optional arguments:\n"
          "\n"
          "    \"correct\"\n"
          "        Automatically repair the file system. This option will cause e2fsck\n"
          "        to automatically fix any filesystem problems that can be safely\n"
          "        fixed without human intervention.\n"
          "\n"
          "        This option may not be specified at the same time as the \"forceall\"\n"
          "        option.\n"
          "\n"
          "    \"forceall\"\n"
          "        Assume an answer of 'yes' to all questions; allows e2fsck to be used\n"
          "        non-interactively.\n"
          "\n"
          "        This option may not be specified at the same time as the \"correct\"\n"
          "        option.\n"
          "\n"
          "",
  .synopsis = "e2fsck device [correct:true|false] [forceall:true|false]",
  .run = run_e2fsck
};

struct command_entry extlinux_cmd_entry = {
  .name = "extlinux",
  .help = "NAME\n"
          "    extlinux - install the SYSLINUX bootloader on an ext2/3/4 or btrfs\n"
          "    filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     extlinux directory\n"
          "\n"
          "DESCRIPTION\n"
          "    Install the SYSLINUX bootloader on the device mounted at directory.\n"
          "    Unlike \"syslinux\" which requires a FAT filesystem, this can be used on\n"
          "    an ext2/3/4 or btrfs filesystem.\n"
          "\n"
          "    The directory parameter can be either a mountpoint, or a directory\n"
          "    within the mountpoint.\n"
          "\n"
          "    You also have to mark the partition as \"active\" (\"part_set_bootable\")\n"
          "    and a Master Boot Record must be installed (eg. using \"pwrite_device\")\n"
          "    on the first sector of the whole disk. The SYSLINUX package comes with\n"
          "    some suitable Master Boot Records. See the extlinux(1) man page for\n"
          "    further information.\n"
          "\n"
          "    Additional configuration can be supplied to SYSLINUX by placing a file\n"
          "    called extlinux.conf on the filesystem under directory. For further\n"
          "    information about the contents of this file, see extlinux(1).\n"
          "\n"
          "    See also \"syslinux\".\n"
          "\n"
          "",
  .synopsis = "extlinux directory",
  .run = run_extlinux
};

struct command_entry fsck_cmd_entry = {
  .name = "fsck",
  .help = "NAME\n"
          "    fsck - run the filesystem checker\n"
          "\n"
          "SYNOPSIS\n"
          "     fsck fstype device\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs the filesystem checker (fsck) on \"device\" which should have\n"
          "    filesystem type \"fstype\".\n"
          "\n"
          "    The returned integer is the status. See fsck(8) for the list of status\n"
          "    codes from \"fsck\".\n"
          "\n"
          "    Notes:\n"
          "\n"
          "    *   Multiple status codes can be summed together.\n"
          "\n"
          "    *   A non-zero return code can mean \"success\", for example if errors\n"
          "        have been corrected on the filesystem.\n"
          "\n"
          "    *   Checking or repairing NTFS volumes is not supported (by linux-ntfs).\n"
          "\n"
          "    This command is entirely equivalent to running \"fsck -a -t fstype\n"
          "    device\".\n"
          "\n"
          "",
  .synopsis = "fsck fstype device",
  .run = run_fsck
};

struct command_entry get_attach_method_cmd_entry = {
  .name = "get-attach-method",
  .help = "NAME\n"
          "    get-attach-method - get the backend\n"
          "\n"
          "SYNOPSIS\n"
          "     get-attach-method\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current backend.\n"
          "\n"
          "    See \"set_backend\" and \"BACKEND\" in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"get-backend\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "get-attach-method",
  .run = run_get_attach_method
};

struct command_entry get_cachedir_cmd_entry = {
  .name = "get-cachedir",
  .help = "NAME\n"
          "    get-cachedir - get the appliance cache directory\n"
          "\n"
          "SYNOPSIS\n"
          "     get-cachedir\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the directory used by the handle to store the appliance cache.\n"
          "\n"
          "",
  .synopsis = "get-cachedir",
  .run = run_get_cachedir
};

struct command_entry get_libvirt_requested_credential_defresult_cmd_entry = {
  .name = "get-libvirt-requested-credential-defresult",
  .help = "NAME\n"
          "    get-libvirt-requested-credential-defresult - default result of i'th\n"
          "    requested credential\n"
          "\n"
          "SYNOPSIS\n"
          "     get-libvirt-requested-credential-defresult index\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the default result (provided by libvirt) for the \"index\"'th\n"
          "    requested credential. If libvirt did not provide a default result, this\n"
          "    returns the empty string \"\".\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "get-libvirt-requested-credential-defresult index",
  .run = run_get_libvirt_requested_credential_defresult
};

struct command_entry get_path_cmd_entry = {
  .name = "get-path",
  .help = "NAME\n"
          "    get-path - get the search path\n"
          "\n"
          "SYNOPSIS\n"
          "     get-path\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current search path.\n"
          "\n"
          "    This is always non-NULL. If it wasn't set already, then this will return\n"
          "    the default path.\n"
          "\n"
          "",
  .synopsis = "get-path",
  .run = run_get_path
};

struct command_entry get_pgroup_cmd_entry = {
  .name = "get-pgroup",
  .help = "NAME\n"
          "    get-pgroup - get process group flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-pgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the process group flag.\n"
          "\n"
          "",
  .synopsis = "get-pgroup",
  .run = run_get_pgroup
};

struct command_entry get_smp_cmd_entry = {
  .name = "get-smp",
  .help = "NAME\n"
          "    get-smp - get number of virtual CPUs in appliance\n"
          "\n"
          "SYNOPSIS\n"
          "     get-smp\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the number of virtual CPUs assigned to the appliance.\n"
          "\n"
          "",
  .synopsis = "get-smp",
  .run = run_get_smp
};

struct command_entry get_sockdir_cmd_entry = {
  .name = "get-sockdir",
  .help = "NAME\n"
          "    get-sockdir - get the temporary directory for sockets\n"
          "\n"
          "SYNOPSIS\n"
          "     get-sockdir\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the directory used by the handle to store temporary socket files.\n"
          "\n"
          "    This is different from \"tmpdir\", as we need shorter paths for sockets\n"
          "    (due to the limited buffers of filenames for UNIX sockets), and \"tmpdir\"\n"
          "    may be too long for them.\n"
          "\n"
          "    The environment variable \"XDG_RUNTIME_DIR\" controls the default value:\n"
          "    If \"XDG_RUNTIME_DIR\" is set, then that is the default. Else /tmp is the\n"
          "    default.\n"
          "\n"
          "",
  .synopsis = "get-sockdir",
  .run = run_get_sockdir
};

struct command_entry get_trace_cmd_entry = {
  .name = "get-trace",
  .help = "NAME\n"
          "    get-trace - get command trace enabled flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-trace\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the command trace flag.\n"
          "\n"
          "",
  .synopsis = "get-trace",
  .run = run_get_trace
};

struct command_entry hivex_node_get_child_cmd_entry = {
  .name = "hivex-node-get-child",
  .help = "NAME\n"
          "    hivex-node-get-child - return the named child of node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-get-child nodeh name\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the child of \"nodeh\" with the name \"name\", if it exists. This can\n"
          "    return 0 meaning the name was not found.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-get-child nodeh name",
  .run = run_hivex_node_get_child
};

struct command_entry hivex_node_set_value_cmd_entry = {
  .name = "hivex-node-set-value",
  .help = "NAME\n"
          "    hivex-node-set-value - set or replace a single value in a node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-set-value nodeh key t val\n"
          "\n"
          "DESCRIPTION\n"
          "    Set or replace a single value under the node \"nodeh\". The \"key\" is the\n"
          "    name, \"t\" is the type, and \"val\" is the data.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-set-value nodeh key t val",
  .run = run_hivex_node_set_value
};

struct command_entry hivex_value_key_cmd_entry = {
  .name = "hivex-value-key",
  .help = "NAME\n"
          "    hivex-value-key - return the key field from the (key, datatype, data)\n"
          "    tuple\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-value-key valueh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the key (name) field of a (key, datatype, data) tuple.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-value-key valueh",
  .run = run_hivex_value_key
};

struct command_entry hivex_value_type_cmd_entry = {
  .name = "hivex-value-type",
  .help = "NAME\n"
          "    hivex-value-type - return the data type from the (key, datatype, data)\n"
          "    tuple\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-value-type valueh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the data type field from a (key, datatype, data) tuple.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-value-type valueh",
  .run = run_hivex_value_type
};

struct command_entry inspect_get_distro_cmd_entry = {
  .name = "inspect-get-distro",
  .help = "NAME\n"
          "    inspect-get-distro - get distro of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-distro root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the distro (distribution) of the inspected operating\n"
          "    system.\n"
          "\n"
          "    Currently defined distros are:\n"
          "\n"
          "    \"alpinelinux\"\n"
          "        Alpine Linux.\n"
          "\n"
          "    \"altlinux\"\n"
          "        ALT Linux.\n"
          "\n"
          "    \"archlinux\"\n"
          "        Arch Linux.\n"
          "\n"
          "    \"buildroot\"\n"
          "        Buildroot-derived distro, but not one we specifically recognize.\n"
          "\n"
          "    \"centos\"\n"
          "        CentOS.\n"
          "\n"
          "    \"cirros\"\n"
          "        Cirros.\n"
          "\n"
          "    \"coreos\"\n"
          "        CoreOS.\n"
          "\n"
          "    \"debian\"\n"
          "        Debian.\n"
          "\n"
          "    \"fedora\"\n"
          "        Fedora.\n"
          "\n"
          "    \"freebsd\"\n"
          "        FreeBSD.\n"
          "\n"
          "    \"freedos\"\n"
          "        FreeDOS.\n"
          "\n"
          "    \"frugalware\"\n"
          "        Frugalware.\n"
          "\n"
          "    \"gentoo\"\n"
          "        Gentoo.\n"
          "\n"
          "    \"linuxmint\"\n"
          "        Linux Mint.\n"
          "\n"
          "    \"mageia\"\n"
          "        Mageia.\n"
          "\n"
          "    \"mandriva\"\n"
          "        Mandriva.\n"
          "\n"
          "    \"meego\"\n"
          "        MeeGo.\n"
          "\n"
          "    \"netbsd\"\n"
          "        NetBSD.\n"
          "\n"
          "    \"openbsd\"\n"
          "        OpenBSD.\n"
          "\n"
          "    \"opensuse\"\n"
          "        OpenSUSE.\n"
          "\n"
          "    \"oraclelinux\"\n"
          "        Oracle Linux.\n"
          "\n"
          "    \"pardus\"\n"
          "        Pardus.\n"
          "\n"
          "    \"pldlinux\"\n"
          "        PLD Linux.\n"
          "\n"
          "    \"redhat-based\"\n"
          "        Some Red Hat-derived distro.\n"
          "\n"
          "    \"rhel\"\n"
          "        Red Hat Enterprise Linux.\n"
          "\n"
          "    \"scientificlinux\"\n"
          "        Scientific Linux.\n"
          "\n"
          "    \"slackware\"\n"
          "        Slackware.\n"
          "\n"
          "    \"sles\"\n"
          "        SuSE Linux Enterprise Server or Desktop.\n"
          "\n"
          "    \"suse-based\"\n"
          "        Some openSuSE-derived distro.\n"
          "\n"
          "    \"ttylinux\"\n"
          "        ttylinux.\n"
          "\n"
          "    \"ubuntu\"\n"
          "        Ubuntu.\n"
          "\n"
          "    \"unknown\"\n"
          "        The distro could not be determined.\n"
          "\n"
          "    \"voidlinux\"\n"
          "        Void Linux.\n"
          "\n"
          "    \"windows\"\n"
          "        Windows does not have distributions. This string is returned if the\n"
          "        OS type is Windows.\n"
          "\n"
          "    Future versions of libguestfs may return other strings here. The caller\n"
          "    should be prepared to handle any string.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-distro root",
  .run = run_inspect_get_distro
};

struct command_entry inspect_get_filesystems_cmd_entry = {
  .name = "inspect-get-filesystems",
  .help = "NAME\n"
          "    inspect-get-filesystems - get filesystems associated with inspected\n"
          "    operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-filesystems root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns a list of all the filesystems that we think are associated\n"
          "    with this operating system. This includes the root filesystem, other\n"
          "    ordinary filesystems, and non-mounted devices like swap partitions.\n"
          "\n"
          "    In the case of a multi-boot virtual machine, it is possible for a\n"
          "    filesystem to be shared between operating systems.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n"
          "    \"inspect_get_mountpoints\".\n"
          "\n"
          "",
  .synopsis = "inspect-get-filesystems root",
  .run = run_inspect_get_filesystems
};

struct command_entry inspect_get_minor_version_cmd_entry = {
  .name = "inspect-get-minor-version",
  .help = "NAME\n"
          "    inspect-get-minor-version - get minor version of inspected operating\n"
          "    system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-minor-version root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the minor version number of the inspected operating system.\n"
          "\n"
          "    If the version could not be determined, then 0 is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n"
          "    \"inspect_get_major_version\".\n"
          "\n"
          "",
  .synopsis = "inspect-get-minor-version root",
  .run = run_inspect_get_minor_version
};

struct command_entry inspect_get_package_format_cmd_entry = {
  .name = "inspect-get-package-format",
  .help = "NAME\n"
          "    inspect-get-package-format - get package format used by the operating\n"
          "    system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-package-format root\n"
          "\n"
          "DESCRIPTION\n"
          "    This function and \"inspect_get_package_management\" return the package\n"
          "    format and package management tool used by the inspected operating\n"
          "    system. For example for Fedora these functions would return \"rpm\"\n"
          "    (package format), and \"yum\" or \"dnf\" (package management).\n"
          "\n"
          "    This returns the string \"unknown\" if we could not determine the package\n"
          "    format *or* if the operating system does not have a real packaging\n"
          "    system (eg. Windows).\n"
          "\n"
          "    Possible strings include: \"rpm\", \"deb\", \"ebuild\", \"pisi\", \"pacman\",\n"
          "    \"pkgsrc\", \"apk\", \"xbps\". Future versions of libguestfs may return other\n"
          "    strings.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-package-format root",
  .run = run_inspect_get_package_format
};

struct command_entry inspect_get_product_variant_cmd_entry = {
  .name = "inspect-get-product-variant",
  .help = "NAME\n"
          "    inspect-get-product-variant - get product variant of inspected operating\n"
          "    system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-product-variant root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the product variant of the inspected operating system.\n"
          "\n"
          "    For Windows guests, this returns the contents of the Registry key\n"
          "    \"HKLM\\Software\\Microsoft\\Windows NT\\CurrentVersion\" \"InstallationType\"\n"
          "    which is usually a string such as \"Client\" or \"Server\" (other values are\n"
          "    possible). This can be used to distinguish consumer and enterprise\n"
          "    versions of Windows that have the same version number (for example,\n"
          "    Windows 7 and Windows 2008 Server are both version 6.1, but the former\n"
          "    is \"Client\" and the latter is \"Server\").\n"
          "\n"
          "    For enterprise Linux guests, in future we intend this to return the\n"
          "    product variant such as \"Desktop\", \"Server\" and so on. But this is not\n"
          "    implemented at present.\n"
          "\n"
          "    If the product variant could not be determined, then the string\n"
          "    \"unknown\" is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n"
          "    \"inspect_get_product_name\", \"inspect_get_major_version\".\n"
          "\n"
          "",
  .synopsis = "inspect-get-product-variant root",
  .run = run_inspect_get_product_variant
};

struct command_entry inspect_get_windows_software_hive_cmd_entry = {
  .name = "inspect-get-windows-software-hive",
  .help = "NAME\n"
          "    inspect-get-windows-software-hive - get the path of the Windows software\n"
          "    hive\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-windows-software-hive root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the path to the hive (binary Windows Registry file)\n"
          "    corresponding to HKLM\\SOFTWARE.\n"
          "\n"
          "    This call assumes that the guest is Windows and that the guest has a\n"
          "    software hive file with the right name. If this is not the case then an\n"
          "    error is returned. This call does not check that the hive is a valid\n"
          "    Windows Registry hive.\n"
          "\n"
          "    You can use \"hivex_open\" to read or write to the hive.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-windows-software-hive root",
  .run = run_inspect_get_windows_software_hive
};

struct command_entry inspect_list_applications_cmd_entry = {
  .name = "inspect-list-applications",
  .help = "NAME\n"
          "    inspect-list-applications - get list of applications installed in the\n"
          "    operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-list-applications root\n"
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
          "    \"app_name\"\n"
          "        The name of the application. For Red Hat-derived and Debian-derived\n"
          "        Linux guests, this is the package name.\n"
          "\n"
          "    \"app_display_name\"\n"
          "        The display name of the application, sometimes localized to the\n"
          "        install language of the guest operating system.\n"
          "\n"
          "        If unavailable this is returned as an empty string \"\". Callers\n"
          "        needing to display something can use \"app_name\" instead.\n"
          "\n"
          "    \"app_epoch\"\n"
          "        For package managers which use epochs, this contains the epoch of\n"
          "        the package (an integer). If unavailable, this is returned as 0.\n"
          "\n"
          "    \"app_version\"\n"
          "        The version string of the application or package. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    \"app_release\"\n"
          "        The release string of the application or package, for package\n"
          "        managers that use this. If unavailable this is returned as an empty\n"
          "        string \"\".\n"
          "\n"
          "    \"app_install_path\"\n"
          "        The installation path of the application (on operating systems such\n"
          "        as Windows which use installation paths). This path is in the format\n"
          "        used by the guest operating system, it is not a libguestfs path.\n"
          "\n"
          "        If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app_trans_path\"\n"
          "        The install path translated into a libguestfs path. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    \"app_publisher\"\n"
          "        The name of the publisher of the application, for package managers\n"
          "        that use this. If unavailable this is returned as an empty string\n"
          "        \"\".\n"
          "\n"
          "    \"app_url\"\n"
          "        The URL (eg. upstream URL) of the application. If unavailable this\n"
          "        is returned as an empty string \"\".\n"
          "\n"
          "    \"app_source_package\"\n"
          "        For packaging systems which support this, the name of the source\n"
          "        package. If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app_summary\"\n"
          "        A short (usually one line) description of the application or\n"
          "        package. If unavailable this is returned as an empty string \"\".\n"
          "\n"
          "    \"app_description\"\n"
          "        A longer description of the application or package. If unavailable\n"
          "        this is returned as an empty string \"\".\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the\n"
          "    \"inspect-list-applications2\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "inspect-list-applications root",
  .run = run_inspect_list_applications
};

struct command_entry inspect_os_cmd_entry = {
  .name = "inspect-os",
  .help = "NAME\n"
          "    inspect-os - inspect disk and return list of operating systems found\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-os\n"
          "\n"
          "DESCRIPTION\n"
          "    This function uses other libguestfs functions and certain heuristics to\n"
          "    inspect the disk(s) (usually disks belonging to a virtual machine),\n"
          "    looking for operating systems.\n"
          "\n"
          "    The list returned is empty if no operating systems were found.\n"
          "\n"
          "    If one operating system was found, then this returns a list with a\n"
          "    single element, which is the name of the root filesystem of this\n"
          "    operating system. It is also possible for this function to return a list\n"
          "    containing more than one element, indicating a dual-boot or multi-boot\n"
          "    virtual machine, with each element being the root filesystem of one of\n"
          "    the operating systems.\n"
          "\n"
          "    You can pass the root string(s) returned to other \"inspect_get_*\"\n"
          "    functions in order to query further information about each operating\n"
          "    system, such as the name and version.\n"
          "\n"
          "    This function uses other libguestfs features such as \"mount_ro\" and\n"
          "    \"umount_all\" in order to mount and unmount filesystems and look at the\n"
          "    contents. This should be called with no disks currently mounted. The\n"
          "    function may also use Augeas, so any existing Augeas handle will be\n"
          "    closed.\n"
          "\n"
          "    This function cannot decrypt encrypted disks. The caller must do that\n"
          "    first (supplying the necessary keys) if the disk is encrypted.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "    See also \"list_filesystems\".\n"
          "\n"
          "",
  .synopsis = "inspect-os",
  .run = run_inspect_os
};

struct command_entry journal_get_cmd_entry = {
  .name = "journal-get",
  .help = "NAME\n"
          "    journal-get - read the current journal entry\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-get\n"
          "\n"
          "DESCRIPTION\n"
          "    Read the current journal entry. This returns all the fields in the\n"
          "    journal as a set of \"(attrname, attrval)\" pairs. The \"attrname\" is the\n"
          "    field name (a string).\n"
          "\n"
          "    The \"attrval\" is the field value (a binary blob, often but not always a\n"
          "    string). Please note that \"attrval\" is a byte array, *not* a\n"
          "    \\0-terminated C string.\n"
          "\n"
          "    The length of data may be truncated to the data threshold (see:\n"
          "    \"journal_set_data_threshold\", \"journal_get_data_threshold\").\n"
          "\n"
          "    If you set the data threshold to unlimited (0) then this call can read a\n"
          "    journal entry of any size, ie. it is not limited by the libguestfs\n"
          "    protocol.\n"
          "\n"
          "",
  .synopsis = "journal-get",
  .run = run_journal_get
};

struct command_entry journal_get_data_threshold_cmd_entry = {
  .name = "journal-get-data-threshold",
  .help = "NAME\n"
          "    journal-get-data-threshold - get the data threshold for reading journal\n"
          "    entries\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-get-data-threshold\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the current data threshold for reading journal entries. This is a\n"
          "    hint to the journal that it may truncate data fields to this size when\n"
          "    reading them (note also that it may not truncate them). If this returns\n"
          "    0, then the threshold is unlimited.\n"
          "\n"
          "    See also \"journal_set_data_threshold\".\n"
          "\n"
          "",
  .synopsis = "journal-get-data-threshold",
  .run = run_journal_get_data_threshold
};

struct command_entry ldmtool_diskgroup_name_cmd_entry = {
  .name = "ldmtool-diskgroup-name",
  .help = "NAME\n"
          "    ldmtool-diskgroup-name - return the name of a Windows dynamic disk group\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-diskgroup-name diskgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the name of a Windows dynamic disk group. The \"diskgroup\"\n"
          "    parameter should be the GUID of a disk group, one element from the list\n"
          "    returned by \"ldmtool_scan\".\n"
          "\n"
          "",
  .synopsis = "ldmtool-diskgroup-name diskgroup",
  .run = run_ldmtool_diskgroup_name
};

struct command_entry ldmtool_diskgroup_volumes_cmd_entry = {
  .name = "ldmtool-diskgroup-volumes",
  .help = "NAME\n"
          "    ldmtool-diskgroup-volumes - return the volumes in a Windows dynamic disk\n"
          "    group\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-diskgroup-volumes diskgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the volumes in a Windows dynamic disk group. The \"diskgroup\"\n"
          "    parameter should be the GUID of a disk group, one element from the list\n"
          "    returned by \"ldmtool_scan\".\n"
          "\n"
          "",
  .synopsis = "ldmtool-diskgroup-volumes diskgroup",
  .run = run_ldmtool_diskgroup_volumes
};

struct command_entry ll_cmd_entry = {
  .name = "ll",
  .help = "NAME\n"
          "    ll - list the files in a directory (long format)\n"
          "\n"
          "SYNOPSIS\n"
          "     ll directory\n"
          "\n"
          "DESCRIPTION\n"
          "    List the files in directory (relative to the root directory, there is no\n"
          "    cwd) in the format of 'ls -la'.\n"
          "\n"
          "    This command is mostly useful for interactive sessions. It is *not*\n"
          "    intended that you try to parse the output string.\n"
          "\n"
          "",
  .synopsis = "ll directory",
  .run = run_ll
};

struct command_entry ln_f_cmd_entry = {
  .name = "ln-f",
  .help = "NAME\n"
          "    ln-f - create a hard link\n"
          "\n"
          "SYNOPSIS\n"
          "     ln-f target linkname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a hard link using the \"ln -f\" command. The *-f*\n"
          "    option removes the link (\"linkname\") if it exists already.\n"
          "\n"
          "",
  .synopsis = "ln-f target linkname",
  .run = run_ln_f
};

struct command_entry ln_s_cmd_entry = {
  .name = "ln-s",
  .help = "NAME\n"
          "    ln-s - create a symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     ln-s target linkname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a symbolic link using the \"ln -s\" command.\n"
          "\n"
          "",
  .synopsis = "ln-s target linkname",
  .run = run_ln_s
};

struct command_entry lremovexattr_cmd_entry = {
  .name = "lremovexattr",
  .help = "NAME\n"
          "    lremovexattr - remove extended attribute of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     lremovexattr xattr path\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"removexattr\", but if \"path\" is a symbolic link,\n"
          "    then it removes an extended attribute of the link itself.\n"
          "\n"
          "",
  .synopsis = "lremovexattr xattr path",
  .run = run_lremovexattr
};

struct command_entry lstatnslist_cmd_entry = {
  .name = "lstatnslist",
  .help = "NAME\n"
          "    lstatnslist - lstat on multiple files\n"
          "\n"
          "SYNOPSIS\n"
          "     lstatnslist path names\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to perform the \"lstatns\" operation on multiple\n"
          "    files, where all files are in the directory \"path\". \"names\" is the list\n"
          "    of files from this directory.\n"
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
          "",
  .synopsis = "lstatnslist path names",
  .run = run_lstatnslist
};

struct command_entry luks_close_cmd_entry = {
  .name = "luks-close",
  .help = "NAME\n"
          "    luks-close - close a LUKS device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-close device\n"
          "\n"
          "DESCRIPTION\n"
          "    This closes a LUKS device that was created earlier by \"luks_open\" or\n"
          "    \"luks_open_ro\". The \"device\" parameter must be the name of the LUKS\n"
          "    mapping device (ie. /dev/mapper/mapname) and *not* the name of the\n"
          "    underlying block device.\n"
          "\n"
          "",
  .synopsis = "luks-close device",
  .run = run_luks_close
};

struct command_entry lvremove_cmd_entry = {
  .name = "lvremove",
  .help = "NAME\n"
          "    lvremove - remove an LVM logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     lvremove device\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove an LVM logical volume \"device\", where \"device\" is the path to the\n"
          "    LV, such as /dev/VG/LV.\n"
          "\n"
          "    You can also remove all LVs in a volume group by specifying the VG name,\n"
          "    /dev/VG.\n"
          "\n"
          "",
  .synopsis = "lvremove device",
  .run = run_lvremove
};

struct command_entry md_stop_cmd_entry = {
  .name = "md-stop",
  .help = "NAME\n"
          "    md-stop - stop a Linux md (RAID) device\n"
          "\n"
          "SYNOPSIS\n"
          "     md-stop md\n"
          "\n"
          "DESCRIPTION\n"
          "    This command deactivates the MD array named \"md\". The device is stopped,\n"
          "    but it is not destroyed or zeroed.\n"
          "\n"
          "",
  .synopsis = "md-stop md",
  .run = run_md_stop
};

struct command_entry mkfs_btrfs_cmd_entry = {
  .name = "mkfs-btrfs",
  .help = "NAME\n"
          "    mkfs-btrfs - create a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mkfs-btrfs devices [allocstart:N] [bytecount:N] [datatype:..] [leafsize:N] [label:..] [metadata:..] [nodesize:N] [sectorsize:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a btrfs filesystem, allowing all configurables to be set. For\n"
          "    more information on the optional arguments, see mkfs.btrfs(8).\n"
          "\n"
          "    Since btrfs filesystems can span multiple devices, this takes a\n"
          "    non-empty list of devices.\n"
          "\n"
          "    To create general filesystems, use \"mkfs\".\n"
          "\n"
          "",
  .synopsis = "mkfs-btrfs devices [allocstart:N] [bytecount:N] [datatype:..] [leafsize:N] [label:..] [metadata:..] [nodesize:N] [sectorsize:N]",
  .run = run_mkfs_btrfs
};

struct command_entry mklost_and_found_cmd_entry = {
  .name = "mklost-and-found",
  .help = "NAME\n"
          "    mklost-and-found - make lost+found directory on an ext2/3/4 filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mklost-and-found mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    Make the \"lost+found\" directory, normally in the root directory of an\n"
          "    ext2/3/4 filesystem. \"mountpoint\" is the directory under which we try to\n"
          "    create the \"lost+found\" directory.\n"
          "\n"
          "",
  .synopsis = "mklost-and-found mountpoint",
  .run = run_mklost_and_found
};

struct command_entry mkmountpoint_cmd_entry = {
  .name = "mkmountpoint",
  .help = "NAME\n"
          "    mkmountpoint - create a mountpoint\n"
          "\n"
          "SYNOPSIS\n"
          "     mkmountpoint exemptpath\n"
          "\n"
          "DESCRIPTION\n"
          "    \"mkmountpoint\" and \"rmmountpoint\" are specialized calls that can be used\n"
          "    to create extra mountpoints before mounting the first filesystem.\n"
          "\n"
          "    These calls are *only* necessary in some very limited circumstances,\n"
          "    mainly the case where you want to mount a mix of unrelated and/or\n"
          "    read-only filesystems together.\n"
          "\n"
          "    For example, live CDs often contain a \"Russian doll\" nest of\n"
          "    filesystems, an ISO outer layer, with a squashfs image inside, with an\n"
          "    ext2/3 image inside that. You can unpack this as follows in guestfish:\n"
          "\n"
          "     add-ro Fedora-11-i686-Live.iso\n"
          "     run\n"
          "     mkmountpoint /cd\n"
          "     mkmountpoint /sqsh\n"
          "     mkmountpoint /ext3fs\n"
          "     mount /dev/sda /cd\n"
          "     mount-loop /cd/LiveOS/squashfs.img /sqsh\n"
          "     mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs\n"
          "\n"
          "    The inner filesystem is now unpacked under the /ext3fs mountpoint.\n"
          "\n"
          "    \"mkmountpoint\" is not compatible with \"umount_all\". You may get\n"
          "    unexpected errors if you try to mix these calls. It is safest to\n"
          "    manually unmount filesystems and remove mountpoints after use.\n"
          "\n"
          "    \"umount_all\" unmounts filesystems by sorting the paths longest first, so\n"
          "    for this to work for manual mountpoints, you must ensure that the\n"
          "    innermost mountpoints have the longest pathnames, as in the example code\n"
          "    above.\n"
          "\n"
          "    For more details see\n"
          "    <https://bugzilla.redhat.com/show_bug.cgi?id=599503>\n"
          "\n"
          "    Autosync [see \"set_autosync\", this is set by default on handles] can\n"
          "    cause \"umount_all\" to be called when the handle is closed which can also\n"
          "    trigger these issues.\n"
          "\n"
          "",
  .synopsis = "mkmountpoint exemptpath",
  .run = run_mkmountpoint
};

struct command_entry mkswap_file_cmd_entry = {
  .name = "mkswap-file",
  .help = "NAME\n"
          "    mkswap-file - create a swap file\n"
          "\n"
          "SYNOPSIS\n"
          "     mkswap-file path\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a swap file.\n"
          "\n"
          "    This command just writes a swap file signature to an existing file. To\n"
          "    create the file itself, use something like \"fallocate\".\n"
          "\n"
          "",
  .synopsis = "mkswap-file path",
  .run = run_mkswap_file
};

struct command_entry mount_9p_cmd_entry = {
  .name = "mount-9p",
  .help = "NAME\n"
          "    mount-9p - mount 9p filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-9p mounttag mountpoint [options:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Mount the virtio-9p filesystem with the tag \"mounttag\" on the directory\n"
          "    \"mountpoint\".\n"
          "\n"
          "    If required, \"trans=virtio\" will be automatically added to the options.\n"
          "    Any other options required can be passed in the optional \"options\"\n"
          "    parameter.\n"
          "\n"
          "",
  .synopsis = "mount-9p mounttag mountpoint [options:..]",
  .run = run_mount_9p
};

struct command_entry mountable_device_cmd_entry = {
  .name = "mountable-device",
  .help = "NAME\n"
          "    mountable-device - extract the device part of a mountable\n"
          "\n"
          "SYNOPSIS\n"
          "     mountable-device mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns the device name of a mountable. In quite a lot of cases, the\n"
          "    mountable is the device name.\n"
          "\n"
          "    However this doesn't apply for btrfs subvolumes, where the mountable is\n"
          "    a combination of both the device name and the subvolume path (see also\n"
          "    \"mountable_subvolume\" to extract the subvolume path of the mountable if\n"
          "    any).\n"
          "\n"
          "",
  .synopsis = "mountable-device mountable",
  .run = run_mountable_device
};

struct command_entry mv_cmd_entry = {
  .name = "mv",
  .help = "NAME\n"
          "    mv - move a file\n"
          "\n"
          "SYNOPSIS\n"
          "     mv src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    This moves a file from \"src\" to \"dest\" where \"dest\" is either a\n"
          "    destination filename or destination directory.\n"
          "\n"
          "    See also: \"rename\".\n"
          "\n"
          "",
  .synopsis = "mv src dest",
  .run = run_mv
};

struct command_entry ntfsresize_cmd_entry = {
  .name = "ntfsresize",
  .help = "NAME\n"
          "    ntfsresize - resize an NTFS filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfsresize device [size:N] [force:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command resizes an NTFS filesystem, expanding or shrinking it to\n"
          "    the size of the underlying device.\n"
          "\n"
          "    The optional parameters are:\n"
          "\n"
          "    \"size\"\n"
          "        The new size (in bytes) of the filesystem. If omitted, the\n"
          "        filesystem is resized to fit the container (eg. partition).\n"
          "\n"
          "    \"force\"\n"
          "        If this option is true, then force the resize of the filesystem even\n"
          "        if the filesystem is marked as requiring a consistency check.\n"
          "\n"
          "        After the resize operation, the filesystem is always marked as\n"
          "        requiring a consistency check (for safety). You have to boot into\n"
          "        Windows to perform this check and clear this condition. If you\n"
          "        *don't* set the \"force\" option then it is not possible to call\n"
          "        \"ntfsresize\" multiple times on a single filesystem without booting\n"
          "        into Windows between each resize.\n"
          "\n"
          "    See also ntfsresize(8).\n"
          "\n"
          "    You can use 'ntfsresize-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "ntfsresize device [size:N] [force:true|false]",
  .run = run_ntfsresize
};

struct command_entry part_disk_cmd_entry = {
  .name = "part-disk",
  .help = "NAME\n"
          "    part-disk - partition whole disk with a single primary partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-disk device parttype\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is simply a combination of \"part_init\" followed by\n"
          "    \"part_add\" to create a single primary partition covering the whole disk.\n"
          "\n"
          "    \"parttype\" is the partition table type, usually \"mbr\" or \"gpt\", but\n"
          "    other possible values are described in \"part_init\".\n"
          "\n"
          "",
  .synopsis = "part-disk device parttype",
  .run = run_part_disk
};

struct command_entry part_expand_gpt_cmd_entry = {
  .name = "part-expand-gpt",
  .help = "NAME\n"
          "    part-expand-gpt - move backup GPT header to the end of the disk\n"
          "\n"
          "SYNOPSIS\n"
          "     part-expand-gpt device\n"
          "\n"
          "DESCRIPTION\n"
          "    Move backup GPT data structures to the end of the disk. This is useful\n"
          "    in case of in-place image expand since disk space after backup GPT\n"
          "    header is not usable. This is equivalent to \"sgdisk -e\".\n"
          "\n"
          "    See also sgdisk(8).\n"
          "\n"
          "",
  .synopsis = "part-expand-gpt device",
  .run = run_part_expand_gpt
};

struct command_entry part_get_parttype_cmd_entry = {
  .name = "part-get-parttype",
  .help = "NAME\n"
          "    part-get-parttype - get the partition table type\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-parttype device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command examines the partition table on \"device\" and returns the\n"
          "    partition table type (format) being used.\n"
          "\n"
          "    Common return values include: \"msdos\" (a DOS/Windows style MBR partition\n"
          "    table), \"gpt\" (a GPT/EFI-style partition table). Other values are\n"
          "    possible, although unusual. See \"part_init\" for a full list.\n"
          "\n"
          "",
  .synopsis = "part-get-parttype device",
  .run = run_part_get_parttype
};

struct command_entry pvcreate_cmd_entry = {
  .name = "pvcreate",
  .help = "NAME\n"
          "    pvcreate - create an LVM physical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     pvcreate device\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an LVM physical volume on the named \"device\", where\n"
          "    \"device\" should usually be a partition name such as /dev/sda1.\n"
          "\n"
          "",
  .synopsis = "pvcreate device",
  .run = run_pvcreate
};

struct command_entry pvs_cmd_entry = {
  .name = "pvs",
  .help = "NAME\n"
          "    pvs - list the LVM physical volumes (PVs)\n"
          "\n"
          "SYNOPSIS\n"
          "     pvs\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the physical volumes detected. This is the equivalent of the\n"
          "    pvs(8) command.\n"
          "\n"
          "    This returns a list of just the device names that contain PVs (eg.\n"
          "    /dev/sda2).\n"
          "\n"
          "    See also \"pvs_full\".\n"
          "\n"
          "",
  .synopsis = "pvs",
  .run = run_pvs
};

struct command_entry pwrite_cmd_entry = {
  .name = "pwrite",
  .help = "NAME\n"
          "    pwrite - write to part of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     pwrite path content offset\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes to part of a file. It writes the data buffer\n"
          "    \"content\" to the file \"path\" starting at offset \"offset\".\n"
          "\n"
          "    This command implements the pwrite(2) system call, and like that system\n"
          "    call it may not write the full data requested. The return value is the\n"
          "    number of bytes that were actually written to the file. This could even\n"
          "    be 0, although short writes are unlikely for regular files in ordinary\n"
          "    circumstances.\n"
          "\n"
          "    See also \"pread\", \"pwrite_device\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "pwrite path content offset",
  .run = run_pwrite
};

struct command_entry read_file_cmd_entry = {
  .name = "read-file",
  .help = "NAME\n"
          "    read-file - read a file\n"
          "\n"
          "SYNOPSIS\n"
          "     read-file path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls returns the contents of the file \"path\" as a buffer.\n"
          "\n"
          "    Unlike \"cat\", this function can correctly handle files that contain\n"
          "    embedded ASCII NUL characters.\n"
          "\n"
          "",
  .synopsis = "read-file path",
  .run = run_read_file
};

struct command_entry rename_cmd_entry = {
  .name = "rename",
  .help = "NAME\n"
          "    rename - rename a file on the same filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     rename oldpath newpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Rename a file to a new place on the same filesystem. This is the same as\n"
          "    the Linux rename(2) system call. In most cases you are better to use\n"
          "    \"mv\" instead.\n"
          "\n"
          "",
  .synopsis = "rename oldpath newpath",
  .run = run_rename
};

struct command_entry resize2fs_M_cmd_entry = {
  .name = "resize2fs-M",
  .help = "NAME\n"
          "    resize2fs-M - resize an ext2, ext3 or ext4 filesystem to the minimum\n"
          "    size\n"
          "\n"
          "SYNOPSIS\n"
          "     resize2fs-M device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command is the same as \"resize2fs\", but the filesystem is resized\n"
          "    to its minimum size. This works like the *-M* option to the \"resize2fs\"\n"
          "    command.\n"
          "\n"
          "    To get the resulting size of the filesystem you should call \"tune2fs_l\"\n"
          "    and read the \"Block size\" and \"Block count\" values. These two numbers,\n"
          "    multiplied together, give the resulting size of the minimal filesystem\n"
          "    in bytes.\n"
          "\n"
          "    See also \"RESIZE2FS ERRORS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "resize2fs-M device",
  .run = run_resize2fs_M
};

struct command_entry rm_rf_cmd_entry = {
  .name = "rm-rf",
  .help = "NAME\n"
          "    rm-rf - remove a file or directory recursively\n"
          "\n"
          "SYNOPSIS\n"
          "     rm-rf path\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove the file or directory \"path\", recursively removing the contents\n"
          "    if its a directory. This is like the \"rm -rf\" shell command.\n"
          "\n"
          "",
  .synopsis = "rm-rf path",
  .run = run_rm_rf
};

struct command_entry scrub_file_cmd_entry = {
  .name = "scrub-file",
  .help = "NAME\n"
          "    scrub-file - scrub (securely wipe) a file\n"
          "\n"
          "SYNOPSIS\n"
          "     scrub-file file\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes patterns over a file to make data retrieval more\n"
          "    difficult.\n"
          "\n"
          "    The file is *removed* after scrubbing.\n"
          "\n"
          "    It is an interface to the scrub(1) program. See that manual page for\n"
          "    more details.\n"
          "\n"
          "",
  .synopsis = "scrub-file file",
  .run = run_scrub_file
};

struct command_entry set_append_cmd_entry = {
  .name = "set-append",
  .help = "NAME\n"
          "    set-append - add options to kernel command line\n"
          "\n"
          "SYNOPSIS\n"
          "     set-append append\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is used to add additional options to the libguestfs\n"
          "    appliance kernel command line.\n"
          "\n"
          "    The default is \"NULL\" unless overridden by setting \"LIBGUESTFS_APPEND\"\n"
          "    environment variable.\n"
          "\n"
          "    Setting \"append\" to \"NULL\" means *no* additional options are passed\n"
          "    (libguestfs always adds a few of its own).\n"
          "\n"
          "    You can use 'append' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-append append",
  .run = run_set_append
};

struct command_entry set_backend_cmd_entry = {
  .name = "set-backend",
  .help = "NAME\n"
          "    set-backend - set the backend\n"
          "\n"
          "SYNOPSIS\n"
          "     set-backend backend\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the method that libguestfs uses to connect to the backend guestfsd\n"
          "    daemon.\n"
          "\n"
          "    This handle property was previously called the \"attach method\".\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3).\n"
          "\n"
          "    You can use 'backend' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-backend backend",
  .run = run_set_backend
};

struct command_entry set_direct_cmd_entry = {
  .name = "set-direct",
  .help = "NAME\n"
          "    set-direct - enable or disable direct appliance mode\n"
          "\n"
          "SYNOPSIS\n"
          "     set-direct direct\n"
          "\n"
          "DESCRIPTION\n"
          "    If the direct appliance mode flag is enabled, then stdin and stdout are\n"
          "    passed directly through to the appliance once it is launched.\n"
          "\n"
          "    One consequence of this is that log messages aren't caught by the\n"
          "    library and handled by \"set_log_message_callback\", but go straight to\n"
          "    stdout.\n"
          "\n"
          "    You probably don't want to use this unless you know what you are doing.\n"
          "\n"
          "    The default is disabled.\n"
          "\n"
          "    You can use 'direct' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-direct direct",
  .run = run_set_direct
};

struct command_entry set_memsize_cmd_entry = {
  .name = "set-memsize",
  .help = "NAME\n"
          "    set-memsize - set memory allocated to the hypervisor\n"
          "\n"
          "SYNOPSIS\n"
          "     set-memsize memsize\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the memory size in megabytes allocated to the hypervisor. This\n"
          "    only has any effect if called before \"launch\".\n"
          "\n"
          "    You can also change this by setting the environment variable\n"
          "    \"LIBGUESTFS_MEMSIZE\" before the handle is created.\n"
          "\n"
          "    For more information on the architecture of libguestfs, see guestfs(3).\n"
          "\n"
          "    You can use 'memsize' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-memsize memsize",
  .run = run_set_memsize
};

struct command_entry set_program_cmd_entry = {
  .name = "set-program",
  .help = "NAME\n"
          "    set-program - set the program name\n"
          "\n"
          "SYNOPSIS\n"
          "     set-program program\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the program name. This is an informative string which the main\n"
          "    program may optionally set in the handle.\n"
          "\n"
          "    When the handle is created, the program name in the handle is set to the\n"
          "    basename from \"argv[0]\". The program name can never be \"NULL\".\n"
          "\n"
          "    You can use 'program' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-program program",
  .run = run_set_program
};

struct command_entry set_selinux_cmd_entry = {
  .name = "set-selinux",
  .help = "NAME\n"
          "    set-selinux - set SELinux enabled or disabled at appliance boot\n"
          "\n"
          "SYNOPSIS\n"
          "     set-selinux selinux\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the selinux flag that is passed to the appliance at boot time.\n"
          "    The default is \"selinux=0\" (disabled).\n"
          "\n"
          "    Note that if SELinux is enabled, it is always in Permissive mode\n"
          "    (\"enforcing=0\").\n"
          "\n"
          "    For more information on the architecture of libguestfs, see guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"selinux-relabel\"\n"
          "    call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "    You can use 'selinux' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-selinux selinux",
  .run = run_set_selinux
};

struct command_entry setxattr_cmd_entry = {
  .name = "setxattr",
  .help = "NAME\n"
          "    setxattr - set extended attribute of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     setxattr xattr val vallen path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call sets the extended attribute named \"xattr\" of the file \"path\"\n"
          "    to the value \"val\" (of length \"vallen\"). The value is arbitrary 8 bit\n"
          "    data.\n"
          "\n"
          "    See also: \"lsetxattr\", attr(5).\n"
          "\n"
          "",
  .synopsis = "setxattr xattr val vallen path",
  .run = run_setxattr
};

struct command_entry sfdisk_l_cmd_entry = {
  .name = "sfdisk-l",
  .help = "NAME\n"
          "    sfdisk-l - display the partition table\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdisk-l device\n"
          "\n"
          "DESCRIPTION\n"
          "    This displays the partition table on \"device\", in the human-readable\n"
          "    output of the sfdisk(8) command. It is not intended to be parsed.\n"
          "\n"
          "    See also: \"part_list\"\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"part-list\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "sfdisk-l device",
  .run = run_sfdisk_l
};

struct command_entry umount_local_cmd_entry = {
  .name = "umount-local",
  .help = "NAME\n"
          "    umount-local - unmount a locally mounted filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     umount-local\n"
          "\n"
          "DESCRIPTION\n"
          "    If libguestfs is exporting the filesystem on a local mountpoint, then\n"
          "    this unmounts it.\n"
          "\n"
          "    See \"MOUNT LOCAL\" in guestfs(3) for full documentation.\n"
          "\n"
          "",
  .synopsis = "umount-local",
  .run = run_umount_local
};

struct command_entry vfs_label_cmd_entry = {
  .name = "vfs-label",
  .help = "NAME\n"
          "    vfs-label - get the filesystem label\n"
          "\n"
          "SYNOPSIS\n"
          "     vfs-label mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the label of the filesystem on \"mountable\".\n"
          "\n"
          "    If the filesystem is unlabeled, this returns the empty string.\n"
          "\n"
          "    To find a filesystem from the label, use \"findfs_label\".\n"
          "\n"
          "",
  .synopsis = "vfs-label mountable",
  .run = run_vfs_label
};

struct command_entry vg_activate_all_cmd_entry = {
  .name = "vg-activate-all",
  .help = "NAME\n"
          "    vg-activate-all - activate or deactivate all volume groups\n"
          "\n"
          "SYNOPSIS\n"
          "     vg-activate-all activate\n"
          "\n"
          "DESCRIPTION\n"
          "    This command activates or (if \"activate\" is false) deactivates all\n"
          "    logical volumes in all volume groups.\n"
          "\n"
          "    This command is the same as running \"vgchange -a y|n\"\n"
          "\n"
          "",
  .synopsis = "vg-activate-all activate",
  .run = run_vg_activate_all
};

struct command_entry vgchange_uuid_all_cmd_entry = {
  .name = "vgchange-uuid-all",
  .help = "NAME\n"
          "    vgchange-uuid-all - generate new random UUIDs for all volume groups\n"
          "\n"
          "SYNOPSIS\n"
          "     vgchange-uuid-all\n"
          "\n"
          "DESCRIPTION\n"
          "    Generate new random UUIDs for all volume groups.\n"
          "\n"
          "",
  .synopsis = "vgchange-uuid-all",
  .run = run_vgchange_uuid_all
};

struct command_entry vgmeta_cmd_entry = {
  .name = "vgmeta",
  .help = "NAME\n"
          "    vgmeta - get volume group metadata\n"
          "\n"
          "SYNOPSIS\n"
          "     vgmeta vgname\n"
          "\n"
          "DESCRIPTION\n"
          "    \"vgname\" is an LVM volume group. This command examines the volume group\n"
          "    and returns its metadata.\n"
          "\n"
          "    Note that the metadata is an internal structure used by LVM, subject to\n"
          "    change at any time, and is provided for information only.\n"
          "\n"
          "",
  .synopsis = "vgmeta vgname",
  .run = run_vgmeta
};

struct command_entry vgrename_cmd_entry = {
  .name = "vgrename",
  .help = "NAME\n"
          "    vgrename - rename an LVM volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vgrename volgroup newvolgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    Rename a volume group \"volgroup\" with the new name \"newvolgroup\".\n"
          "\n"
          "",
  .synopsis = "vgrename volgroup newvolgroup",
  .run = run_vgrename
};

struct command_entry vguuid_cmd_entry = {
  .name = "vguuid",
  .help = "NAME\n"
          "    vguuid - get the UUID of a volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vguuid vgname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns the UUID of the LVM VG named \"vgname\".\n"
          "\n"
          "",
  .synopsis = "vguuid vgname",
  .run = run_vguuid
};

struct command_entry wc_w_cmd_entry = {
  .name = "wc-w",
  .help = "NAME\n"
          "    wc-w - count words in a file\n"
          "\n"
          "SYNOPSIS\n"
          "     wc-w path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command counts the words in a file, using the \"wc -w\" external\n"
          "    command.\n"
          "\n"
          "",
  .synopsis = "wc-w path",
  .run = run_wc_w
};

struct command_entry write_cmd_entry = {
  .name = "write",
  .help = "NAME\n"
          "    write - create a new file\n"
          "\n"
          "SYNOPSIS\n"
          "     write path content\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates a file called \"path\". The content of the file is the\n"
          "    string \"content\" (which can contain any 8 bit data).\n"
          "\n"
          "    See also \"write_append\".\n"
          "\n"
          "",
  .synopsis = "write path content",
  .run = run_write
};

struct command_entry zfgrepi_cmd_entry = {
  .name = "zfgrepi",
  .help = "NAME\n"
          "    zfgrepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zfgrepi pattern path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zfgrep -i\" program and returns the matching\n"
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
  .synopsis = "zfgrepi pattern path",
  .run = run_zfgrepi
};

