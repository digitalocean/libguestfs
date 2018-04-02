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

struct command_entry add_drive_cmd_entry = {
  .name = "add-drive",
  .help = "NAME\n"
          "    add-drive - add an image to examine or modify\n"
          "\n"
          "SYNOPSIS\n"
          "     add-drive filename [readonly:true|false] [format:..] [iface:..] [name:..] [label:..] [protocol:..] [server:..] [username:..] [secret:..] [cachemode:..] [discard:..] [copyonread:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This function adds a disk image called filename to the handle. filename\n"
          "    may be a regular host file or a host device.\n"
          "\n"
          "    When this function is called before \"launch\" (the usual case) then the\n"
          "    first time you call this function, the disk appears in the API as\n"
          "    /dev/sda, the second time as /dev/sdb, and so on.\n"
          "\n"
          "    In libguestfs ≥ 1.20 you can also call this function after launch (with\n"
          "    some restrictions). This is called \"hotplugging\". When hotplugging, you\n"
          "    must specify a \"label\" so that the new disk gets a predictable name. For\n"
          "    more information see \"HOTPLUGGING\" in guestfs(3).\n"
          "\n"
          "    You don't necessarily need to be root when using libguestfs. However you\n"
          "    obviously do need sufficient permissions to access the filename for\n"
          "    whatever operations you want to perform (ie. read access if you just\n"
          "    want to read the image or write access if you want to modify the image).\n"
          "\n"
          "    This call checks that filename exists.\n"
          "\n"
          "    filename may be the special string \"/dev/null\". See \"NULL DISKS\" in\n"
          "    guestfs(3).\n"
          "\n"
          "    The optional arguments are:\n"
          "\n"
          "    \"readonly\"\n"
          "        If true then the image is treated as read-only. Writes are still\n"
          "        allowed, but they are stored in a temporary snapshot overlay which\n"
          "        is discarded at the end. The disk that you add is not modified.\n"
          "\n"
          "    \"format\"\n"
          "        This forces the image format. If you omit this (or use \"add_drive\"\n"
          "        or \"add_drive_ro\") then the format is automatically detected.\n"
          "        Possible formats include \"raw\" and \"qcow2\".\n"
          "\n"
          "        Automatic detection of the format opens you up to a potential\n"
          "        security hole when dealing with untrusted raw-format images. See\n"
          "        CVE-2010-3851 and RHBZ#642934. Specifying the format closes this\n"
          "        security hole.\n"
          "\n"
          "    \"iface\"\n"
          "        This rarely-used option lets you emulate the behaviour of the\n"
          "        deprecated \"add_drive_with_if\" call (q.v.)\n"
          "\n"
          "    \"name\"\n"
          "        The name the drive had in the original guest, e.g. /dev/sdb. This is\n"
          "        used as a hint to the guest inspection process if it is available.\n"
          "\n"
          "    \"label\"\n"
          "        Give the disk a label. The label should be a unique, short string\n"
          "        using *only* ASCII characters \"[a-zA-Z]\". As well as its usual name\n"
          "        in the API (such as /dev/sda), the drive will also be named\n"
          "        /dev/disk/guestfs/*label*.\n"
          "\n"
          "        See \"DISK LABELS\" in guestfs(3).\n"
          "\n"
          "    \"protocol\"\n"
          "        The optional protocol argument can be used to select an alternate\n"
          "        source protocol.\n"
          "\n"
          "        See also: \"REMOTE STORAGE\" in guestfs(3).\n"
          "\n"
          "        \"protocol = \"file\"\"\n"
          "            filename is interpreted as a local file or device. This is the\n"
          "            default if the optional protocol parameter is omitted.\n"
          "\n"
          "        \"protocol = \"ftp\"|\"ftps\"|\"http\"|\"https\"|\"tftp\"\"\n"
          "            Connect to a remote FTP, HTTP or TFTP server. The \"server\"\n"
          "            parameter must also be supplied - see below.\n"
          "\n"
          "            See also: \"FTP, HTTP AND TFTP\" in guestfs(3)\n"
          "\n"
          "        \"protocol = \"gluster\"\"\n"
          "            Connect to the GlusterFS server. The \"server\" parameter must\n"
          "            also be supplied - see below.\n"
          "\n"
          "            See also: \"GLUSTER\" in guestfs(3)\n"
          "\n"
          "        \"protocol = \"iscsi\"\"\n"
          "            Connect to the iSCSI server. The \"server\" parameter must also be\n"
          "            supplied - see below. The \"username\" parameter may be supplied.\n"
          "            See below. The \"secret\" parameter may be supplied. See below.\n"
          "\n"
          "            See also: \"ISCSI\" in guestfs(3).\n"
          "\n"
          "        \"protocol = \"nbd\"\"\n"
          "            Connect to the Network Block Device server. The \"server\"\n"
          "            parameter must also be supplied - see below.\n"
          "\n"
          "            See also: \"NETWORK BLOCK DEVICE\" in guestfs(3).\n"
          "\n"
          "        \"protocol = \"rbd\"\"\n"
          "            Connect to the Ceph (librbd/RBD) server. The \"server\" parameter\n"
          "            must also be supplied - see below. The \"username\" parameter may\n"
          "            be supplied. See below. The \"secret\" parameter may be supplied.\n"
          "            See below.\n"
          "\n"
          "            See also: \"CEPH\" in guestfs(3).\n"
          "\n"
          "        \"protocol = \"sheepdog\"\"\n"
          "            Connect to the Sheepdog server. The \"server\" parameter may also\n"
          "            be supplied - see below.\n"
          "\n"
          "            See also: \"SHEEPDOG\" in guestfs(3).\n"
          "\n"
          "        \"protocol = \"ssh\"\"\n"
          "            Connect to the Secure Shell (ssh) server.\n"
          "\n"
          "            The \"server\" parameter must be supplied. The \"username\"\n"
          "            parameter may be supplied. See below.\n"
          "\n"
          "            See also: \"SSH\" in guestfs(3).\n"
          "\n"
          "    \"server\"\n"
          "        For protocols which require access to a remote server, this is a\n"
          "        list of server(s).\n"
          "\n"
          "         Protocol       Number of servers required\n"
          "         --------       --------------------------\n"
          "         file           List must be empty or param not used at all\n"
          "         ftp|ftps|http|https|tftp  Exactly one\n"
          "         gluster        Exactly one\n"
          "         iscsi          Exactly one\n"
          "         nbd            Exactly one\n"
          "         rbd            Zero or more\n"
          "         sheepdog       Zero or more\n"
          "         ssh            Exactly one\n"
          "\n"
          "        Each list element is a string specifying a server. The string must\n"
          "        be in one of the following formats:\n"
          "\n"
          "         hostname\n"
          "         hostname:port\n"
          "         tcp:hostname\n"
          "         tcp:hostname:port\n"
          "         unix:/path/to/socket\n"
          "\n"
          "        If the port number is omitted, then the standard port number for the\n"
          "        protocol is used (see /etc/services).\n"
          "\n"
          "    \"username\"\n"
          "        For the \"ftp\", \"ftps\", \"http\", \"https\", \"iscsi\", \"rbd\", \"ssh\" and\n"
          "        \"tftp\" protocols, this specifies the remote username.\n"
          "\n"
          "        If not given, then the local username is used for \"ssh\", and no\n"
          "        authentication is attempted for ceph. But note this sometimes may\n"
          "        give unexpected results, for example if using the libvirt backend\n"
          "        and if the libvirt backend is configured to start the qemu appliance\n"
          "        as a special user such as \"qemu.qemu\". If in doubt, specify the\n"
          "        remote username you want.\n"
          "\n"
          "    \"secret\"\n"
          "        For the \"rbd\" protocol only, this specifies the ‘secret’ to use when\n"
          "        connecting to the remote device. It must be base64 encoded.\n"
          "\n"
          "        If not given, then a secret matching the given username will be\n"
          "        looked up in the default keychain locations, or if no username is\n"
          "        given, then no authentication will be used.\n"
          "\n"
          "    \"cachemode\"\n"
          "        Choose whether or not libguestfs will obey sync operations (safe but\n"
          "        slow) or not (unsafe but fast). The possible values for this string\n"
          "        are:\n"
          "\n"
          "        \"cachemode = \"writeback\"\"\n"
          "            This is the default.\n"
          "\n"
          "            Write operations in the API do not return until a write(2) call\n"
          "            has completed in the host [but note this does not imply that\n"
          "            anything gets written to disk].\n"
          "\n"
          "            Sync operations in the API, including implicit syncs caused by\n"
          "            filesystem journalling, will not return until an fdatasync(2)\n"
          "            call has completed in the host, indicating that data has been\n"
          "            committed to disk.\n"
          "\n"
          "        \"cachemode = \"unsafe\"\"\n"
          "            In this mode, there are no guarantees. Libguestfs may cache\n"
          "            anything and ignore sync requests. This is suitable only for\n"
          "            scratch or temporary disks.\n"
          "\n"
          "    \"discard\"\n"
          "        Enable or disable discard (a.k.a. trim or unmap) support on this\n"
          "        drive. If enabled, operations such as \"fstrim\" will be able to\n"
          "        discard / make thin / punch holes in the underlying host file or\n"
          "        device.\n"
          "\n"
          "        Possible discard settings are:\n"
          "\n"
          "        \"discard = \"disable\"\"\n"
          "            Disable discard support. This is the default.\n"
          "\n"
          "        \"discard = \"enable\"\"\n"
          "            Enable discard support. Fail if discard is not possible.\n"
          "\n"
          "        \"discard = \"besteffort\"\"\n"
          "            Enable discard support if possible, but don't fail if it is not\n"
          "            supported.\n"
          "\n"
          "            Since not all backends and not all underlying systems support\n"
          "            discard, this is a good choice if you want to use discard if\n"
          "            possible, but don't mind if it doesn't work.\n"
          "\n"
          "    \"copyonread\"\n"
          "        The boolean parameter \"copyonread\" enables copy-on-read support.\n"
          "        This only affects disk formats which have backing files, and causes\n"
          "        reads to be stored in the overlay layer, speeding up multiple reads\n"
          "        of the same area of disk.\n"
          "\n"
          "        The default is false.\n"
          "\n"
          "    You can use 'add' or 'add-drive-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "add-drive filename [readonly:true|false] [format:..] [iface:..] [name:..] [label:..] [protocol:..] [server:..] [username:..] [secret:..] [cachemode:..] [discard:..] [copyonread:true|false]",
  .run = run_add_drive
};

struct command_entry add_drive_scratch_cmd_entry = {
  .name = "add-drive-scratch",
  .help = "NAME\n"
          "    add-drive-scratch - add a temporary scratch drive\n"
          "\n"
          "SYNOPSIS\n"
          "     add-drive-scratch size [name:..] [label:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command adds a temporary scratch drive to the handle. The \"size\"\n"
          "    parameter is the virtual size (in bytes). The scratch drive is blank\n"
          "    initially (all reads return zeroes until you start writing to it). The\n"
          "    drive is deleted when the handle is closed.\n"
          "\n"
          "    The optional arguments \"name\" and \"label\" are passed through to\n"
          "    \"add_drive\".\n"
          "\n"
          "    You can use 'scratch' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "add-drive-scratch size [name:..] [label:..]",
  .run = run_add_drive_scratch
};

struct command_entry aug_label_cmd_entry = {
  .name = "aug-label",
  .help = "NAME\n"
          "    aug-label - return the label from an Augeas path expression\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-label augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    The label (name of the last element) of the Augeas path expression\n"
          "    \"augpath\" is returned. \"augpath\" must match exactly one node, else this\n"
          "    function returns an error.\n"
          "\n"
          "",
  .synopsis = "aug-label augpath",
  .run = run_aug_label
};

struct command_entry blkdiscardzeroes_cmd_entry = {
  .name = "blkdiscardzeroes",
  .help = "NAME\n"
          "    blkdiscardzeroes - return true if discarded blocks are read as zeroes\n"
          "\n"
          "SYNOPSIS\n"
          "     blkdiscardzeroes device\n"
          "\n"
          "DESCRIPTION\n"
          "    This call returns true if blocks on \"device\" that have been discarded by\n"
          "    a call to \"blkdiscard\" are returned as blocks of zero bytes when read\n"
          "    the next time.\n"
          "\n"
          "    If it returns false, then it may be that discarded blocks are read as\n"
          "    stale or random data.\n"
          "\n"
          "",
  .synopsis = "blkdiscardzeroes device",
  .run = run_blkdiscardzeroes
};

struct command_entry blockdev_getsize64_cmd_entry = {
  .name = "blockdev-getsize64",
  .help = "NAME\n"
          "    blockdev-getsize64 - get total size of device in bytes\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-getsize64 device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the size of the device in bytes.\n"
          "\n"
          "    See also \"blockdev_getsz\".\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-getsize64 device",
  .run = run_blockdev_getsize64
};

struct command_entry blockdev_getss_cmd_entry = {
  .name = "blockdev-getss",
  .help = "NAME\n"
          "    blockdev-getss - get sectorsize of block device\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-getss device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the size of sectors on a block device. Usually 512, but can\n"
          "    be larger for modern devices.\n"
          "\n"
          "    (Note, this is not the size in sectors, use \"blockdev_getsz\" for that).\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-getss device",
  .run = run_blockdev_getss
};

struct command_entry blockdev_rereadpt_cmd_entry = {
  .name = "blockdev-rereadpt",
  .help = "NAME\n"
          "    blockdev-rereadpt - reread partition table\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-rereadpt device\n"
          "\n"
          "DESCRIPTION\n"
          "    Reread the partition table on \"device\".\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-rereadpt device",
  .run = run_blockdev_rereadpt
};

struct command_entry btrfs_balance_cancel_cmd_entry = {
  .name = "btrfs-balance-cancel",
  .help = "NAME\n"
          "    btrfs-balance-cancel - cancel a running or paused balance\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-balance-cancel path\n"
          "\n"
          "DESCRIPTION\n"
          "    Cancel a running balance on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-balance-cancel path",
  .run = run_btrfs_balance_cancel
};

struct command_entry btrfs_qgroup_limit_cmd_entry = {
  .name = "btrfs-qgroup-limit",
  .help = "NAME\n"
          "    btrfs-qgroup-limit - limit the size of a subvolume\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-limit subvolume size\n"
          "\n"
          "DESCRIPTION\n"
          "    Limit the size of the subvolume with path \"subvolume\".\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-limit subvolume size",
  .run = run_btrfs_qgroup_limit
};

struct command_entry btrfs_quota_rescan_cmd_entry = {
  .name = "btrfs-quota-rescan",
  .help = "NAME\n"
          "    btrfs-quota-rescan - trash all qgroup numbers and scan the metadata\n"
          "    again with the current config\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-quota-rescan fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Trash all qgroup numbers and scan the metadata again with the current\n"
          "    config.\n"
          "\n"
          "",
  .synopsis = "btrfs-quota-rescan fs",
  .run = run_btrfs_quota_rescan
};

struct command_entry btrfs_set_seeding_cmd_entry = {
  .name = "btrfs-set-seeding",
  .help = "NAME\n"
          "    btrfs-set-seeding - enable or disable the seeding feature of device\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-set-seeding device seeding\n"
          "\n"
          "DESCRIPTION\n"
          "    Enable or disable the seeding feature of a device that contains a btrfs\n"
          "    filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-set-seeding device seeding",
  .run = run_btrfs_set_seeding
};

struct command_entry btrfs_subvolume_show_cmd_entry = {
  .name = "btrfs-subvolume-show",
  .help = "NAME\n"
          "    btrfs-subvolume-show - return detailed information of the subvolume\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-show subvolume\n"
          "\n"
          "DESCRIPTION\n"
          "    Return detailed information of the subvolume.\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-show subvolume",
  .run = run_btrfs_subvolume_show
};

struct command_entry chown_cmd_entry = {
  .name = "chown",
  .help = "NAME\n"
          "    chown - change file owner and group\n"
          "\n"
          "SYNOPSIS\n"
          "     chown owner group path\n"
          "\n"
          "DESCRIPTION\n"
          "    Change the file owner to \"owner\" and group to \"group\".\n"
          "\n"
          "    Only numeric uid and gid are supported. If you want to use names, you\n"
          "    will need to locate and parse the password file yourself (Augeas support\n"
          "    makes this relatively easy).\n"
          "\n"
          "",
  .synopsis = "chown owner group path",
  .run = run_chown
};

struct command_entry command_cmd_entry = {
  .name = "command",
  .help = "NAME\n"
          "    command - run a command from the guest filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     command arguments\n"
          "\n"
          "DESCRIPTION\n"
          "    This call runs a command from the guest filesystem. The filesystem must\n"
          "    be mounted, and must contain a compatible operating system (ie.\n"
          "    something Linux, with the same or compatible processor architecture).\n"
          "\n"
          "    The single parameter is an argv-style list of arguments. The first\n"
          "    element is the name of the program to run. Subsequent elements are\n"
          "    parameters. The list must be non-empty (ie. must contain a program\n"
          "    name). Note that the command runs directly, and is *not* invoked via the\n"
          "    shell (see \"sh\").\n"
          "\n"
          "    The return value is anything printed to *stdout* by the command.\n"
          "\n"
          "    If the command returns a non-zero exit status, then this function\n"
          "    returns an error message. The error message string is the content of\n"
          "    *stderr* from the command.\n"
          "\n"
          "    The $PATH environment variable will contain at least /usr/bin and /bin.\n"
          "    If you require a program from another location, you should provide the\n"
          "    full path in the first parameter.\n"
          "\n"
          "    Shared libraries and data files required by the program must be\n"
          "    available on filesystems which are mounted in the correct places. It is\n"
          "    the caller’s responsibility to ensure all filesystems that are needed\n"
          "    are mounted at the right locations.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "command arguments",
  .run = run_command
};

struct command_entry copy_device_to_file_cmd_entry = {
  .name = "copy-device-to-file",
  .help = "NAME\n"
          "    copy-device-to-file - copy from source device to destination file\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-device-to-file src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    See \"copy_device_to_device\" for a general overview of this call.\n"
          "\n"
          "",
  .synopsis = "copy-device-to-file src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]",
  .run = run_copy_device_to_file
};

struct command_entry cp_r_cmd_entry = {
  .name = "cp-r",
  .help = "NAME\n"
          "    cp-r - copy a file or directory recursively\n"
          "\n"
          "SYNOPSIS\n"
          "     cp-r src dest\n"
          "\n"
          "DESCRIPTION\n"
          "    This copies a file or directory from \"src\" to \"dest\" recursively using\n"
          "    the \"cp -rP\" command.\n"
          "\n"
          "    Most users should use \"cp_a\" instead. This command is useful when you\n"
          "    don't want to preserve permissions, because the target filesystem does\n"
          "    not support it (primarily when writing to DOS FAT filesystems).\n"
          "\n"
          "",
  .synopsis = "cp-r src dest",
  .run = run_cp_r
};

struct command_entry debug_cmd_entry = {
  .name = "debug",
  .help = "NAME\n"
          "    debug - debugging and internals\n"
          "\n"
          "SYNOPSIS\n"
          "     debug subcmd extraargs\n"
          "\n"
          "DESCRIPTION\n"
          "    The \"debug\" command exposes some internals of \"guestfsd\" (the guestfs\n"
          "    daemon) that runs inside the hypervisor.\n"
          "\n"
          "    There is no comprehensive help for this command. You have to look at the\n"
          "    file daemon/debug.c in the libguestfs source to find out what you can\n"
          "    do.\n"
          "\n"
          "",
  .synopsis = "debug subcmd extraargs",
  .run = run_debug
};

struct command_entry drop_caches_cmd_entry = {
  .name = "drop-caches",
  .help = "NAME\n"
          "    drop-caches - drop kernel page cache, dentries and inodes\n"
          "\n"
          "SYNOPSIS\n"
          "     drop-caches whattodrop\n"
          "\n"
          "DESCRIPTION\n"
          "    This instructs the guest kernel to drop its page cache, and/or dentries\n"
          "    and inode caches. The parameter \"whattodrop\" tells the kernel what\n"
          "    precisely to drop, see <http://linux-mm.org/Drop_Caches>\n"
          "\n"
          "    Setting \"whattodrop\" to 3 should drop everything.\n"
          "\n"
          "    This automatically calls sync(2) before the operation, so that the\n"
          "    maximum guest memory is freed.\n"
          "\n"
          "",
  .synopsis = "drop-caches whattodrop",
  .run = run_drop_caches
};

struct command_entry egrep_cmd_entry = {
  .name = "egrep",
  .help = "NAME\n"
          "    egrep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     egrep regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"egrep\" program and returns the matching lines.\n"
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
  .synopsis = "egrep regex path",
  .run = run_egrep
};

struct command_entry file_architecture_cmd_entry = {
  .name = "file-architecture",
  .help = "NAME\n"
          "    file-architecture - detect the architecture of a binary file\n"
          "\n"
          "SYNOPSIS\n"
          "     file-architecture filename\n"
          "\n"
          "DESCRIPTION\n"
          "    This detects the architecture of the binary filename, and returns it if\n"
          "    known.\n"
          "\n"
          "    Currently defined architectures are:\n"
          "\n"
          "    \"aarch64\"\n"
          "        64 bit ARM.\n"
          "\n"
          "    \"arm\"\n"
          "        32 bit ARM.\n"
          "\n"
          "    \"i386\"\n"
          "        This string is returned for all 32 bit i386, i486, i586, i686\n"
          "        binaries irrespective of the precise processor requirements of the\n"
          "        binary.\n"
          "\n"
          "    \"ia64\"\n"
          "        Intel Itanium.\n"
          "\n"
          "    \"ppc\"\n"
          "        32 bit Power PC.\n"
          "\n"
          "    \"ppc64\"\n"
          "        64 bit Power PC (big endian).\n"
          "\n"
          "    \"ppc64le\"\n"
          "        64 bit Power PC (little endian).\n"
          "\n"
          "    \"riscv32\"\n"
          "    \"riscv64\"\n"
          "    \"riscv128\"\n"
          "        RISC-V 32-, 64- or 128-bit variants.\n"
          "\n"
          "    \"s390\"\n"
          "        31 bit IBM S/390.\n"
          "\n"
          "    \"s390x\"\n"
          "        64 bit IBM S/390.\n"
          "\n"
          "    \"sparc\"\n"
          "        32 bit SPARC.\n"
          "\n"
          "    \"sparc64\"\n"
          "        64 bit SPARC V9 and above.\n"
          "\n"
          "    \"x86_64\"\n"
          "        64 bit x86-64.\n"
          "\n"
          "    Libguestfs may return other architecture strings in future.\n"
          "\n"
          "    The function works on at least the following types of files:\n"
          "\n"
          "    *   many types of Un*x and Linux binary\n"
          "\n"
          "    *   many types of Un*x and Linux shared library\n"
          "\n"
          "    *   Windows Win32 and Win64 binaries\n"
          "\n"
          "    *   Windows Win32 and Win64 DLLs\n"
          "\n"
          "        Win32 binaries and DLLs return \"i386\".\n"
          "\n"
          "        Win64 binaries and DLLs return \"x86_64\".\n"
          "\n"
          "    *   Linux kernel modules\n"
          "\n"
          "    *   Linux new-style initrd images\n"
          "\n"
          "    *   some non-x86 Linux vmlinuz kernels\n"
          "\n"
          "    What it can't do currently:\n"
          "\n"
          "    *   static libraries (libfoo.a)\n"
          "\n"
          "    *   Linux old-style initrd as compressed ext2 filesystem (RHEL 3)\n"
          "\n"
          "    *   x86 Linux vmlinuz kernels\n"
          "\n"
          "        x86 vmlinuz images (bzImage format) consist of a mix of 16-, 32- and\n"
          "        compressed code, and are horribly hard to unpack. If you want to\n"
          "        find the architecture of a kernel, use the architecture of the\n"
          "        associated initrd or kernel module(s) instead.\n"
          "\n"
          "",
  .synopsis = "file-architecture filename",
  .run = run_file_architecture
};

struct command_entry get_backend_cmd_entry = {
  .name = "get-backend",
  .help = "NAME\n"
          "    get-backend - get the backend\n"
          "\n"
          "SYNOPSIS\n"
          "     get-backend\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the current backend.\n"
          "\n"
          "    This handle property was previously called the \"attach method\".\n"
          "\n"
          "    See \"set_backend\" and \"BACKEND\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "get-backend",
  .run = run_get_backend
};

struct command_entry get_e2attrs_cmd_entry = {
  .name = "get-e2attrs",
  .help = "NAME\n"
          "    get-e2attrs - get ext2 file attributes of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     get-e2attrs file\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the file attributes associated with file.\n"
          "\n"
          "    The attributes are a set of bits associated with each inode which affect\n"
          "    the behaviour of the file. The attributes are returned as a string of\n"
          "    letters (described below). The string may be empty, indicating that no\n"
          "    file attributes are set for this file.\n"
          "\n"
          "    These attributes are only present when the file is located on an\n"
          "    ext2/3/4 filesystem. Using this call on other filesystem types will\n"
          "    result in an error.\n"
          "\n"
          "    The characters (file attributes) in the returned string are currently:\n"
          "\n"
          "    'A' When the file is accessed, its atime is not modified.\n"
          "\n"
          "    'a' The file is append-only.\n"
          "\n"
          "    'c' The file is compressed on-disk.\n"
          "\n"
          "    'D' (Directories only.) Changes to this directory are written\n"
          "        synchronously to disk.\n"
          "\n"
          "    'd' The file is not a candidate for backup (see dump(8)).\n"
          "\n"
          "    'E' The file has compression errors.\n"
          "\n"
          "    'e' The file is using extents.\n"
          "\n"
          "    'h' The file is storing its blocks in units of the filesystem blocksize\n"
          "        instead of sectors.\n"
          "\n"
          "    'I' (Directories only.) The directory is using hashed trees.\n"
          "\n"
          "    'i' The file is immutable. It cannot be modified, deleted or renamed. No\n"
          "        link can be created to this file.\n"
          "\n"
          "    'j' The file is data-journaled.\n"
          "\n"
          "    's' When the file is deleted, all its blocks will be zeroed.\n"
          "\n"
          "    'S' Changes to this file are written synchronously to disk.\n"
          "\n"
          "    'T' (Directories only.) This is a hint to the block allocator that\n"
          "        subdirectories contained in this directory should be spread across\n"
          "        blocks. If not present, the block allocator will try to group\n"
          "        subdirectories together.\n"
          "\n"
          "    't' For a file, this disables tail-merging. (Not used by upstream\n"
          "        implementations of ext2.)\n"
          "\n"
          "    'u' When the file is deleted, its blocks will be saved, allowing the\n"
          "        file to be undeleted.\n"
          "\n"
          "    'X' The raw contents of the compressed file may be accessed.\n"
          "\n"
          "    'Z' The compressed file is dirty.\n"
          "\n"
          "    More file attributes may be added to this list later. Not all file\n"
          "    attributes may be set for all kinds of files. For detailed information,\n"
          "    consult the chattr(1) man page.\n"
          "\n"
          "    See also \"set_e2attrs\".\n"
          "\n"
          "    Don't confuse these attributes with extended attributes (see\n"
          "    \"getxattr\").\n"
          "\n"
          "",
  .synopsis = "get-e2attrs file",
  .run = run_get_e2attrs
};

struct command_entry get_e2generation_cmd_entry = {
  .name = "get-e2generation",
  .help = "NAME\n"
          "    get-e2generation - get ext2 file generation of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     get-e2generation file\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the ext2 file generation of a file. The generation (which\n"
          "    used to be called the \"version\") is a number associated with an inode.\n"
          "    This is most commonly used by NFS servers.\n"
          "\n"
          "    The generation is only present when the file is located on an ext2/3/4\n"
          "    filesystem. Using this call on other filesystem types will result in an\n"
          "    error.\n"
          "\n"
          "    See \"set_e2generation\".\n"
          "\n"
          "",
  .synopsis = "get-e2generation file",
  .run = run_get_e2generation
};

struct command_entry glob_expand_cmd_entry = {
  .name = "glob-expand",
  .help = "NAME\n"
          "    glob-expand - expand a wildcard path\n"
          "\n"
          "SYNOPSIS\n"
          "     glob-expand pattern [directoryslash:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command searches for all the pathnames matching \"pattern\" according\n"
          "    to the wildcard expansion rules used by the shell.\n"
          "\n"
          "    If no paths match, then this returns an empty list (note: not an error).\n"
          "\n"
          "    It is just a wrapper around the C glob(3) function with flags\n"
          "    \"GLOB_MARK|GLOB_BRACE\". See that manual page for more details.\n"
          "\n"
          "    \"directoryslash\" controls whether use the \"GLOB_MARK\" flag for glob(3),\n"
          "    and it defaults to true. It can be explicitly set as off to return no\n"
          "    trailing slashes in filenames of directories.\n"
          "\n"
          "    Notice that there is no equivalent command for expanding a device name\n"
          "    (eg. /dev/sd*). Use \"list_devices\", \"list_partitions\" etc functions\n"
          "    instead.\n"
          "\n"
          "    You can use 'glob-expand-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "glob-expand pattern [directoryslash:true|false]",
  .run = run_glob_expand
};

struct command_entry grub_install_cmd_entry = {
  .name = "grub-install",
  .help = "NAME\n"
          "    grub-install - install GRUB 1\n"
          "\n"
          "SYNOPSIS\n"
          "     grub-install root device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command installs GRUB 1 (the Grand Unified Bootloader) on \"device\",\n"
          "    with the root directory being \"root\".\n"
          "\n"
          "    Notes:\n"
          "\n"
          "    *   There is currently no way in the API to install grub2, which is used\n"
          "        by most modern Linux guests. It is possible to run the grub2 command\n"
          "        from the guest, although see the caveats in \"RUNNING COMMANDS\" in\n"
          "        guestfs(3).\n"
          "\n"
          "    *   This uses \"grub-install\" from the host. Unfortunately grub is not\n"
          "        always compatible with itself, so this only works in rather narrow\n"
          "        circumstances. Careful testing with each guest version is advisable.\n"
          "\n"
          "    *   If grub-install reports the error \"No suitable drive was found in\n"
          "        the generated device map.\" it may be that you need to create a\n"
          "        /boot/grub/device.map file first that contains the mapping between\n"
          "        grub device names and Linux device names. It is usually sufficient\n"
          "        to create a file containing:\n"
          "\n"
          "         (hd0) /dev/vda\n"
          "\n"
          "        replacing /dev/vda with the name of the installation device.\n"
          "\n"
          "",
  .synopsis = "grub-install root device",
  .run = run_grub_install
};

struct command_entry hivex_node_add_child_cmd_entry = {
  .name = "hivex-node-add-child",
  .help = "NAME\n"
          "    hivex-node-add-child - add a child node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-add-child parent name\n"
          "\n"
          "DESCRIPTION\n"
          "    Add a child node to \"parent\" named \"name\".\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-add-child parent name",
  .run = run_hivex_node_add_child
};

struct command_entry hivex_node_get_value_cmd_entry = {
  .name = "hivex-node-get-value",
  .help = "NAME\n"
          "    hivex-node-get-value - return the named value\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-get-value nodeh key\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the value attached to \"nodeh\" which has the name \"key\", if it\n"
          "    exists. This can return 0 meaning the key was not found.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-get-value nodeh key",
  .run = run_hivex_node_get_value
};

struct command_entry inspect_get_arch_cmd_entry = {
  .name = "inspect-get-arch",
  .help = "NAME\n"
          "    inspect-get-arch - get architecture of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-arch root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the architecture of the inspected operating system. The\n"
          "    possible return values are listed under \"file_architecture\".\n"
          "\n"
          "    If the architecture could not be determined, then the string \"unknown\"\n"
          "    is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-arch root",
  .run = run_inspect_get_arch
};

struct command_entry inspect_get_drive_mappings_cmd_entry = {
  .name = "inspect-get-drive-mappings",
  .help = "NAME\n"
          "    inspect-get-drive-mappings - get drive letter mappings\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-drive-mappings root\n"
          "\n"
          "DESCRIPTION\n"
          "    This call is useful for Windows which uses a primitive system of\n"
          "    assigning drive letters (like C:\\) to partitions. This inspection API\n"
          "    examines the Windows Registry to find out how disks/partitions are\n"
          "    mapped to drive letters, and returns a hash table as in the example\n"
          "    below:\n"
          "\n"
          "     C      =>     /dev/vda2\n"
          "     E      =>     /dev/vdb1\n"
          "     F      =>     /dev/vdc1\n"
          "\n"
          "    Note that keys are drive letters. For Windows, the key is case\n"
          "    insensitive and just contains the drive letter, without the customary\n"
          "    colon separator character.\n"
          "\n"
          "    In future we may support other operating systems that also used drive\n"
          "    letters, but the keys for those might not be case insensitive and might\n"
          "    be longer than 1 character. For example in OS-9, hard drives were named\n"
          "    \"h0\", \"h1\" etc.\n"
          "\n"
          "    For Windows guests, currently only hard drive mappings are returned.\n"
          "    Removable disks (eg. DVD-ROMs) are ignored.\n"
          "\n"
          "    For guests that do not use drive mappings, or if the drive mappings\n"
          "    could not be determined, this returns an empty hash table.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details. See also\n"
          "    \"inspect_get_mountpoints\", \"inspect_get_filesystems\".\n"
          "\n"
          "",
  .synopsis = "inspect-get-drive-mappings root",
  .run = run_inspect_get_drive_mappings
};

struct command_entry inspect_get_windows_current_control_set_cmd_entry = {
  .name = "inspect-get-windows-current-control-set",
  .help = "NAME\n"
          "    inspect-get-windows-current-control-set - get Windows CurrentControlSet\n"
          "    of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-windows-current-control-set root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the Windows CurrentControlSet of the inspected guest. The\n"
          "    CurrentControlSet is a registry key name such as \"ControlSet001\".\n"
          "\n"
          "    This call assumes that the guest is Windows and that the Registry could\n"
          "    be examined by inspection. If this is not the case then an error is\n"
          "    returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-windows-current-control-set root",
  .run = run_inspect_get_windows_current_control_set
};

struct command_entry inspect_get_windows_systemroot_cmd_entry = {
  .name = "inspect-get-windows-systemroot",
  .help = "NAME\n"
          "    inspect-get-windows-systemroot - get Windows systemroot of inspected\n"
          "    operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-windows-systemroot root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the Windows systemroot of the inspected guest. The\n"
          "    systemroot is a directory path such as /WINDOWS.\n"
          "\n"
          "    This call assumes that the guest is Windows and that the systemroot\n"
          "    could be determined by inspection. If this is not the case then an error\n"
          "    is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-windows-systemroot root",
  .run = run_inspect_get_windows_systemroot
};

struct command_entry is_chardev_cmd_entry = {
  .name = "is-chardev",
  .help = "NAME\n"
          "    is-chardev - test if character device\n"
          "\n"
          "SYNOPSIS\n"
          "     is-chardev path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a character device with the\n"
          "    given \"path\" name.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a chardev also causes the function to return\n"
          "    true.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-chardev-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-chardev path [followsymlinks:true|false]",
  .run = run_is_chardev
};

struct command_entry is_lv_cmd_entry = {
  .name = "is-lv",
  .help = "NAME\n"
          "    is-lv - test if mountable is a logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     is-lv mountable\n"
          "\n"
          "DESCRIPTION\n"
          "    This command tests whether \"mountable\" is a logical volume, and returns\n"
          "    true iff this is the case.\n"
          "\n"
          "",
  .synopsis = "is-lv mountable",
  .run = run_is_lv
};

struct command_entry is_socket_cmd_entry = {
  .name = "is-socket",
  .help = "NAME\n"
          "    is-socket - test if socket\n"
          "\n"
          "SYNOPSIS\n"
          "     is-socket path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a Unix domain socket with\n"
          "    the given \"path\" name.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a socket also causes the function to return\n"
          "    true.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-socket-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-socket path [followsymlinks:true|false]",
  .run = run_is_socket
};

struct command_entry journal_open_cmd_entry = {
  .name = "journal-open",
  .help = "NAME\n"
          "    journal-open - open the systemd journal\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-open directory\n"
          "\n"
          "DESCRIPTION\n"
          "    Open the systemd journal located in directory. Any previously opened\n"
          "    journal handle is closed.\n"
          "\n"
          "    The contents of the journal can be read using \"journal_next\" and\n"
          "    \"journal_get\".\n"
          "\n"
          "    After you have finished using the journal, you should close the handle\n"
          "    by calling \"journal_close\".\n"
          "\n"
          "",
  .synopsis = "journal-open directory",
  .run = run_journal_open
};

struct command_entry kill_subprocess_cmd_entry = {
  .name = "kill-subprocess",
  .help = "NAME\n"
          "    kill-subprocess - kill the hypervisor\n"
          "\n"
          "SYNOPSIS\n"
          "     kill-subprocess\n"
          "\n"
          "DESCRIPTION\n"
          "    This kills the hypervisor.\n"
          "\n"
          "    Do not call this. See: \"shutdown\" instead.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"shutdown\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "kill-subprocess",
  .run = run_kill_subprocess
};

struct command_entry ldmtool_scan_devices_cmd_entry = {
  .name = "ldmtool-scan-devices",
  .help = "NAME\n"
          "    ldmtool-scan-devices - scan for Windows dynamic disks\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-scan-devices devices\n"
          "\n"
          "DESCRIPTION\n"
          "    This function scans for Windows dynamic disks. It returns a list of\n"
          "    identifiers (GUIDs) for all disk groups that were found. These\n"
          "    identifiers can be passed to other \"ldmtool_*\" functions.\n"
          "\n"
          "    The parameter \"devices\" is a list of block devices which are scanned. If\n"
          "    this list is empty, all block devices are scanned.\n"
          "\n"
          "",
  .synopsis = "ldmtool-scan-devices devices",
  .run = run_ldmtool_scan_devices
};

struct command_entry lsetxattr_cmd_entry = {
  .name = "lsetxattr",
  .help = "NAME\n"
          "    lsetxattr - set extended attribute of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     lsetxattr xattr val vallen path\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"setxattr\", but if \"path\" is a symbolic link, then\n"
          "    it sets an extended attribute of the link itself.\n"
          "\n"
          "",
  .synopsis = "lsetxattr xattr val vallen path",
  .run = run_lsetxattr
};

struct command_entry luks_kill_slot_cmd_entry = {
  .name = "luks-kill-slot",
  .help = "NAME\n"
          "    luks-kill-slot - remove a key from a LUKS encrypted device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-kill-slot device keyslot\n"
          "\n"
          "DESCRIPTION\n"
          "    This command deletes the key in key slot \"keyslot\" from the encrypted\n"
          "    LUKS device \"device\". \"key\" must be one of the *other* keys.\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-kill-slot device keyslot",
  .run = run_luks_kill_slot
};

struct command_entry mkdir_cmd_entry = {
  .name = "mkdir",
  .help = "NAME\n"
          "    mkdir - create a directory\n"
          "\n"
          "SYNOPSIS\n"
          "     mkdir path\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a directory named \"path\".\n"
          "\n"
          "",
  .synopsis = "mkdir path",
  .run = run_mkdir
};

struct command_entry mkfifo_cmd_entry = {
  .name = "mkfifo",
  .help = "NAME\n"
          "    mkfifo - make FIFO (named pipe)\n"
          "\n"
          "SYNOPSIS\n"
          "     mkfifo mode path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates a FIFO (named pipe) called \"path\" with mode \"mode\". It\n"
          "    is just a convenient wrapper around \"mknod\".\n"
          "\n"
          "    Unlike with \"mknod\", \"mode\" must contain only permissions bits.\n"
          "\n"
          "    The mode actually set is affected by the umask.\n"
          "\n"
          "",
  .synopsis = "mkfifo mode path",
  .run = run_mkfifo
};

struct command_entry mksquashfs_cmd_entry = {
  .name = "mksquashfs",
  .help = "NAME\n"
          "    mksquashfs - create a squashfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mksquashfs path filename [compress:..] [excludes:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a squashfs filesystem for the specified \"path\".\n"
          "\n"
          "    The optional \"compress\" flag controls compression. If not given, then\n"
          "    the output compressed using \"gzip\". Otherwise one of the following\n"
          "    strings may be given to select the compression type of the squashfs:\n"
          "    \"gzip\", \"lzma\", \"lzo\", \"lz4\", \"xz\".\n"
          "\n"
          "    The other optional arguments are:\n"
          "\n"
          "    \"excludes\"\n"
          "        A list of wildcards. Files are excluded if they match any of the\n"
          "        wildcards.\n"
          "\n"
          "    Please note that this API may fail when used to compress directories\n"
          "    with large files, such as the resulting squashfs will be over 3GB big.\n"
          "\n"
          "",
  .synopsis = "mksquashfs path filename [compress:..] [excludes:..]",
  .run = run_mksquashfs
};

struct command_entry modprobe_cmd_entry = {
  .name = "modprobe",
  .help = "NAME\n"
          "    modprobe - load a kernel module\n"
          "\n"
          "SYNOPSIS\n"
          "     modprobe modulename\n"
          "\n"
          "DESCRIPTION\n"
          "    This loads a kernel module in the appliance.\n"
          "\n"
          "",
  .synopsis = "modprobe modulename",
  .run = run_modprobe
};

struct command_entry ntfscat_i_cmd_entry = {
  .name = "ntfscat-i",
  .help = "NAME\n"
          "    ntfscat-i - download a file to the local machine given its inode\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfscat-i device inode filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Download a file given its inode from a NTFS filesystem and save it as\n"
          "    filename on the local machine.\n"
          "\n"
          "    This allows to download some otherwise inaccessible files such as the\n"
          "    ones within the $Extend folder.\n"
          "\n"
          "    The filesystem from which to extract the file must be unmounted,\n"
          "    otherwise the call will fail.\n"
          "\n"
          "",
  .synopsis = "ntfscat-i device inode filename",
  .run = run_ntfscat_i
};

struct command_entry parse_environment_cmd_entry = {
  .name = "parse-environment",
  .help = "NAME\n"
          "    parse-environment - parse the environment and set handle flags\n"
          "    accordingly\n"
          "\n"
          "SYNOPSIS\n"
          "     parse-environment\n"
          "\n"
          "DESCRIPTION\n"
          "    Parse the program’s environment and set flags in the handle accordingly.\n"
          "    For example if \"LIBGUESTFS_DEBUG=1\" then the ‘verbose’ flag is set in\n"
          "    the handle.\n"
          "\n"
          "    *Most programs do not need to call this*. It is done implicitly when you\n"
          "    call \"create\".\n"
          "\n"
          "    See \"ENVIRONMENT VARIABLES\" in guestfs(3) for a list of environment\n"
          "    variables that can affect libguestfs handles. See also\n"
          "    \"guestfs_create_flags\" in guestfs(3), and \"parse_environment_list\".\n"
          "\n"
          "",
  .synopsis = "parse-environment",
  .run = run_parse_environment
};

struct command_entry part_get_disk_guid_cmd_entry = {
  .name = "part-get-disk-guid",
  .help = "NAME\n"
          "    part-get-disk-guid - get the GUID of a GPT-partitioned disk\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-disk-guid device\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the disk identifier (GUID) of a GPT-partitioned \"device\".\n"
          "    Behaviour is undefined for other partition types.\n"
          "\n"
          "",
  .synopsis = "part-get-disk-guid device",
  .run = run_part_get_disk_guid
};

struct command_entry part_list_cmd_entry = {
  .name = "part-list",
  .help = "NAME\n"
          "    part-list - list partitions on a device\n"
          "\n"
          "SYNOPSIS\n"
          "     part-list device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command parses the partition table on \"device\" and returns the list\n"
          "    of partitions found.\n"
          "\n"
          "    The fields in the returned structure are:\n"
          "\n"
          "    part_num\n"
          "        Partition number, counting from 1.\n"
          "\n"
          "    part_start\n"
          "        Start of the partition *in bytes*. To get sectors you have to divide\n"
          "        by the device’s sector size, see \"blockdev_getss\".\n"
          "\n"
          "    part_end\n"
          "        End of the partition in bytes.\n"
          "\n"
          "    part_size\n"
          "        Size of the partition in bytes.\n"
          "\n"
          "",
  .synopsis = "part-list device",
  .run = run_part_list
};

struct command_entry part_set_bootable_cmd_entry = {
  .name = "part-set-bootable",
  .help = "NAME\n"
          "    part-set-bootable - make a partition bootable\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-bootable device partnum bootable\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the bootable flag on partition numbered \"partnum\" on device\n"
          "    \"device\". Note that partitions are numbered from 1.\n"
          "\n"
          "    The bootable flag is used by some operating systems (notably Windows) to\n"
          "    determine which partition to boot from. It is by no means universally\n"
          "    recognized.\n"
          "\n"
          "",
  .synopsis = "part-set-bootable device partnum bootable",
  .run = run_part_set_bootable
};

struct command_entry part_set_gpt_attributes_cmd_entry = {
  .name = "part-set-gpt-attributes",
  .help = "NAME\n"
          "    part-set-gpt-attributes - set the attribute flags of a GPT partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-gpt-attributes device partnum attributes\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the attribute flags of numbered GPT partition \"partnum\" to\n"
          "    \"attributes\". Return an error if the partition table of \"device\" isn't\n"
          "    GPT.\n"
          "\n"
          "    See\n"
          "    <https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_entries>\n"
          "    for a useful list of partition attributes.\n"
          "\n"
          "",
  .synopsis = "part-set-gpt-attributes device partnum attributes",
  .run = run_part_set_gpt_attributes
};

struct command_entry part_set_gpt_guid_cmd_entry = {
  .name = "part-set-gpt-guid",
  .help = "NAME\n"
          "    part-set-gpt-guid - set the GUID of a GPT partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-gpt-guid device partnum guid\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the GUID of numbered GPT partition \"partnum\" to \"guid\". Return an\n"
          "    error if the partition table of \"device\" isn't GPT, or if \"guid\" is not\n"
          "    a valid GUID.\n"
          "\n"
          "",
  .synopsis = "part-set-gpt-guid device partnum guid",
  .run = run_part_set_gpt_guid
};

struct command_entry part_to_dev_cmd_entry = {
  .name = "part-to-dev",
  .help = "NAME\n"
          "    part-to-dev - convert partition name to device name\n"
          "\n"
          "SYNOPSIS\n"
          "     part-to-dev partition\n"
          "\n"
          "DESCRIPTION\n"
          "    This function takes a partition name (eg. \"/dev/sdb1\") and removes the\n"
          "    partition number, returning the device name (eg. \"/dev/sdb\").\n"
          "\n"
          "    The named partition must exist, for example as a string returned from\n"
          "    \"list_partitions\".\n"
          "\n"
          "    See also \"part_to_partnum\", \"device_index\".\n"
          "\n"
          "",
  .synopsis = "part-to-dev partition",
  .run = run_part_to_dev
};

struct command_entry pvresize_cmd_entry = {
  .name = "pvresize",
  .help = "NAME\n"
          "    pvresize - resize an LVM physical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     pvresize device\n"
          "\n"
          "DESCRIPTION\n"
          "    This resizes (expands or shrinks) an existing LVM physical volume to\n"
          "    match the new size of the underlying device.\n"
          "\n"
          "",
  .synopsis = "pvresize device",
  .run = run_pvresize
};

struct command_entry pvs_full_cmd_entry = {
  .name = "pvs-full",
  .help = "NAME\n"
          "    pvs-full - list the LVM physical volumes (PVs)\n"
          "\n"
          "SYNOPSIS\n"
          "     pvs-full\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the physical volumes detected. This is the equivalent of the\n"
          "    pvs(8) command. The \"full\" version includes all fields.\n"
          "\n"
          "",
  .synopsis = "pvs-full",
  .run = run_pvs_full
};

struct command_entry pwrite_device_cmd_entry = {
  .name = "pwrite-device",
  .help = "NAME\n"
          "    pwrite-device - write to part of a device\n"
          "\n"
          "SYNOPSIS\n"
          "     pwrite-device device content offset\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes to part of a device. It writes the data buffer\n"
          "    \"content\" to \"device\" starting at offset \"offset\".\n"
          "\n"
          "    This command implements the pwrite(2) system call, and like that system\n"
          "    call it may not write the full data requested (although short writes to\n"
          "    disk devices and partitions are probably impossible with standard Linux\n"
          "    kernels).\n"
          "\n"
          "    See also \"pwrite\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "pwrite-device device content offset",
  .run = run_pwrite_device
};

struct command_entry readdir_cmd_entry = {
  .name = "readdir",
  .help = "NAME\n"
          "    readdir - read directories entries\n"
          "\n"
          "SYNOPSIS\n"
          "     readdir dir\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the list of directory entries in directory \"dir\".\n"
          "\n"
          "    All entries in the directory are returned, including \".\" and \"..\". The\n"
          "    entries are *not* sorted, but returned in the same order as the\n"
          "    underlying filesystem.\n"
          "\n"
          "    Also this call returns basic file type information about each file. The\n"
          "    \"ftyp\" field will contain one of the following characters:\n"
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
          "    'u' Unknown file type\n"
          "\n"
          "    '?' The readdir(3) call returned a \"d_type\" field with an unexpected\n"
          "        value\n"
          "\n"
          "    This function is primarily intended for use by programs. To get a simple\n"
          "    list of names, use \"ls\". To get a printable directory for human\n"
          "    consumption, use \"ll\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "readdir dir",
  .run = run_readdir
};

struct command_entry readlink_cmd_entry = {
  .name = "readlink",
  .help = "NAME\n"
          "    readlink - read the target of a symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     readlink path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command reads the target of a symbolic link.\n"
          "\n"
          "",
  .synopsis = "readlink path",
  .run = run_readlink
};

struct command_entry resize2fs_cmd_entry = {
  .name = "resize2fs",
  .help = "NAME\n"
          "    resize2fs - resize an ext2, ext3 or ext4 filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     resize2fs device\n"
          "\n"
          "DESCRIPTION\n"
          "    This resizes an ext2, ext3 or ext4 filesystem to match the size of the\n"
          "    underlying device.\n"
          "\n"
          "    See also \"RESIZE2FS ERRORS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "resize2fs device",
  .run = run_resize2fs
};

struct command_entry rsync_in_cmd_entry = {
  .name = "rsync-in",
  .help = "NAME\n"
          "    rsync-in - synchronize host or remote filesystem with filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     rsync-in remote dest [archive:true|false] [deletedest:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This call may be used to copy or synchronize the filesystem on the host\n"
          "    or on a remote computer with the filesystem within libguestfs. This uses\n"
          "    the rsync(1) program which uses a fast algorithm that avoids copying\n"
          "    files unnecessarily.\n"
          "\n"
          "    This call only works if the network is enabled. See \"set_network\" or the\n"
          "    *--network* option to various tools like guestfish(1).\n"
          "\n"
          "    Files are copied from the remote server and directory specified by\n"
          "    \"remote\" to the destination directory \"dest\".\n"
          "\n"
          "    The format of the remote server string is defined by rsync(1). Note that\n"
          "    there is no way to supply a password or passphrase so the target must be\n"
          "    set up not to require one.\n"
          "\n"
          "    The optional arguments are the same as those of \"rsync\".\n"
          "\n"
          "",
  .synopsis = "rsync-in remote dest [archive:true|false] [deletedest:true|false]",
  .run = run_rsync_in
};

struct command_entry set_e2uuid_cmd_entry = {
  .name = "set-e2uuid",
  .help = "NAME\n"
          "    set-e2uuid - set the ext2/3/4 filesystem UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     set-e2uuid device uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the ext2/3/4 filesystem UUID of the filesystem on \"device\" to\n"
          "    \"uuid\". The format of the UUID and alternatives such as \"clear\",\n"
          "    \"random\" and \"time\" are described in the tune2fs(8) manpage.\n"
          "\n"
          "    You can use \"vfs_uuid\" to return the existing UUID of a filesystem.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"set-uuid\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "set-e2uuid device uuid",
  .run = run_set_e2uuid
};

struct command_entry set_libvirt_requested_credential_cmd_entry = {
  .name = "set-libvirt-requested-credential",
  .help = "NAME\n"
          "    set-libvirt-requested-credential - pass requested credential back to\n"
          "    libvirt\n"
          "\n"
          "SYNOPSIS\n"
          "     set-libvirt-requested-credential index cred\n"
          "\n"
          "DESCRIPTION\n"
          "    After requesting the \"index\"'th credential from the user, call this\n"
          "    function to pass the answer back to libvirt.\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "set-libvirt-requested-credential index cred",
  .run = run_set_libvirt_requested_credential
};

struct command_entry set_libvirt_supported_credentials_cmd_entry = {
  .name = "set-libvirt-supported-credentials",
  .help = "NAME\n"
          "    set-libvirt-supported-credentials - set libvirt credentials supported by\n"
          "    calling program\n"
          "\n"
          "SYNOPSIS\n"
          "     set-libvirt-supported-credentials creds\n"
          "\n"
          "DESCRIPTION\n"
          "    Call this function before setting an event handler for\n"
          "    \"GUESTFS_EVENT_LIBVIRT_AUTH\", to supply the list of credential types\n"
          "    that the program knows how to process.\n"
          "\n"
          "    The \"creds\" list must be a non-empty list of strings. Possible strings\n"
          "    are:\n"
          "\n"
          "    \"username\"\n"
          "    \"authname\"\n"
          "    \"language\"\n"
          "    \"cnonce\"\n"
          "    \"passphrase\"\n"
          "    \"echoprompt\"\n"
          "    \"noechoprompt\"\n"
          "    \"realm\"\n"
          "    \"external\"\n"
          "\n"
          "    See libvirt documentation for the meaning of these credential types.\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "set-libvirt-supported-credentials creds",
  .run = run_set_libvirt_supported_credentials
};

struct command_entry set_path_cmd_entry = {
  .name = "set-path",
  .help = "NAME\n"
          "    set-path - set the search path\n"
          "\n"
          "SYNOPSIS\n"
          "     set-path searchpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the path that libguestfs searches for kernel and initrd.img.\n"
          "\n"
          "    The default is \"$libdir/guestfs\" unless overridden by setting\n"
          "    \"LIBGUESTFS_PATH\" environment variable.\n"
          "\n"
          "    Setting \"path\" to \"NULL\" restores the default path.\n"
          "\n"
          "    You can use 'path' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-path searchpath",
  .run = run_set_path
};

struct command_entry set_pgroup_cmd_entry = {
  .name = "set-pgroup",
  .help = "NAME\n"
          "    set-pgroup - set process group flag\n"
          "\n"
          "SYNOPSIS\n"
          "     set-pgroup pgroup\n"
          "\n"
          "DESCRIPTION\n"
          "    If \"pgroup\" is true, child processes are placed into their own process\n"
          "    group.\n"
          "\n"
          "    The practical upshot of this is that signals like \"SIGINT\" (from users\n"
          "    pressing \"^C\") won't be received by the child process.\n"
          "\n"
          "    The default for this flag is false, because usually you want \"^C\" to\n"
          "    kill the subprocess. Guestfish sets this flag to true when used\n"
          "    interactively, so that \"^C\" can cancel long-running commands gracefully\n"
          "    (see \"user_cancel\").\n"
          "\n"
          "    You can use 'pgroup' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-pgroup pgroup",
  .run = run_set_pgroup
};

struct command_entry sfdisk_disk_geometry_cmd_entry = {
  .name = "sfdisk-disk-geometry",
  .help = "NAME\n"
          "    sfdisk-disk-geometry - display the disk geometry from the partition\n"
          "    table\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdisk-disk-geometry device\n"
          "\n"
          "DESCRIPTION\n"
          "    This displays the disk geometry of \"device\" read from the partition\n"
          "    table. Especially in the case where the underlying block device has been\n"
          "    resized, this can be different from the kernel’s idea of the geometry\n"
          "    (see \"sfdisk_kernel_geometry\").\n"
          "\n"
          "    The result is in human-readable format, and not designed to be parsed.\n"
          "\n"
          "",
  .synopsis = "sfdisk-disk-geometry device",
  .run = run_sfdisk_disk_geometry
};

struct command_entry sh_cmd_entry = {
  .name = "sh",
  .help = "NAME\n"
          "    sh - run a command via the shell\n"
          "\n"
          "SYNOPSIS\n"
          "     sh command\n"
          "\n"
          "DESCRIPTION\n"
          "    This call runs a command from the guest filesystem via the guest’s\n"
          "    /bin/sh.\n"
          "\n"
          "    This is like \"command\", but passes the command to:\n"
          "\n"
          "     /bin/sh -c \"command\"\n"
          "\n"
          "    Depending on the guest’s shell, this usually results in wildcards being\n"
          "    expanded, shell expressions being interpolated and so on.\n"
          "\n"
          "    All the provisos about \"command\" apply to this call.\n"
          "\n"
          "",
  .synopsis = "sh command",
  .run = run_sh
};

struct command_entry statns_cmd_entry = {
  .name = "statns",
  .help = "NAME\n"
          "    statns - get file information\n"
          "\n"
          "SYNOPSIS\n"
          "     statns path\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns file information for the given \"path\".\n"
          "\n"
          "    This is the same as the stat(2) system call.\n"
          "\n"
          "",
  .synopsis = "statns path",
  .run = run_statns
};

struct command_entry swapon_label_cmd_entry = {
  .name = "swapon-label",
  .help = "NAME\n"
          "    swapon-label - enable swap on labeled swap partition\n"
          "\n"
          "SYNOPSIS\n"
          "     swapon-label label\n"
          "\n"
          "DESCRIPTION\n"
          "    This command enables swap to a labeled swap partition. See\n"
          "    \"swapon_device\" for other notes.\n"
          "\n"
          "",
  .synopsis = "swapon-label label",
  .run = run_swapon_label
};

struct command_entry txz_out_cmd_entry = {
  .name = "txz-out",
  .help = "NAME\n"
          "    txz-out - pack directory into compressed tarball\n"
          "\n"
          "SYNOPSIS\n"
          "     txz-out directory tarball\n"
          "\n"
          "DESCRIPTION\n"
          "    This command packs the contents of directory and downloads it to local\n"
          "    file \"tarball\" (as an xz compressed tar archive).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"tar-out\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "txz-out directory tarball",
  .run = run_txz_out
};

struct command_entry umount_all_cmd_entry = {
  .name = "umount-all",
  .help = "NAME\n"
          "    umount-all - unmount all filesystems\n"
          "\n"
          "SYNOPSIS\n"
          "     umount-all\n"
          "\n"
          "DESCRIPTION\n"
          "    This unmounts all mounted filesystems.\n"
          "\n"
          "    Some internal mounts are not unmounted by this call.\n"
          "\n"
          "    You can use 'unmount-all' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "umount-all",
  .run = run_umount_all
};

struct command_entry upload_offset_cmd_entry = {
  .name = "upload-offset",
  .help = "NAME\n"
          "    upload-offset - upload a file from the local machine with offset\n"
          "\n"
          "SYNOPSIS\n"
          "     upload-offset filename remotefilename offset\n"
          "\n"
          "DESCRIPTION\n"
          "    Upload local file filename to remotefilename on the filesystem.\n"
          "\n"
          "    remotefilename is overwritten starting at the byte \"offset\" specified.\n"
          "    The intention is to overwrite parts of existing files or devices,\n"
          "    although if a non-existent file is specified then it is created with a\n"
          "    \"hole\" before \"offset\". The size of the data written is implicit in the\n"
          "    size of the source filename.\n"
          "\n"
          "    Note that there is no limit on the amount of data that can be uploaded\n"
          "    with this call, unlike with \"pwrite\", and this call always writes the\n"
          "    full amount unless an error occurs.\n"
          "\n"
          "    See also \"upload\", \"pwrite\".\n"
          "\n"
          "",
  .synopsis = "upload-offset filename remotefilename offset",
  .run = run_upload_offset
};

struct command_entry utsname_cmd_entry = {
  .name = "utsname",
  .help = "NAME\n"
          "    utsname - appliance kernel version\n"
          "\n"
          "SYNOPSIS\n"
          "     utsname\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the kernel version of the appliance, where this is\n"
          "    available. This information is only useful for debugging. Nothing in the\n"
          "    returned structure is defined by the API.\n"
          "\n"
          "",
  .synopsis = "utsname",
  .run = run_utsname
};

struct command_entry vgpvuuids_cmd_entry = {
  .name = "vgpvuuids",
  .help = "NAME\n"
          "    vgpvuuids - get the PV UUIDs containing the volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vgpvuuids vgname\n"
          "\n"
          "DESCRIPTION\n"
          "    Given a VG called \"vgname\", this returns the UUIDs of all the physical\n"
          "    volumes that this volume group resides on.\n"
          "\n"
          "    You can use this along with \"pvs\" and \"pvuuid\" calls to associate\n"
          "    physical volumes and volume groups.\n"
          "\n"
          "    See also \"vglvuuids\".\n"
          "\n"
          "",
  .synopsis = "vgpvuuids vgname",
  .run = run_vgpvuuids
};

struct command_entry write_append_cmd_entry = {
  .name = "write-append",
  .help = "NAME\n"
          "    write-append - append content to end of file\n"
          "\n"
          "SYNOPSIS\n"
          "     write-append path content\n"
          "\n"
          "DESCRIPTION\n"
          "    This call appends \"content\" to the end of file \"path\". If \"path\" does\n"
          "    not exist, then a new file is created.\n"
          "\n"
          "    See also \"write\".\n"
          "\n"
          "",
  .synopsis = "write-append path content",
  .run = run_write_append
};

struct command_entry yara_scan_cmd_entry = {
  .name = "yara-scan",
  .help = "NAME\n"
          "    yara-scan - scan a file with the loaded yara rules\n"
          "\n"
          "SYNOPSIS\n"
          "     yara-scan path\n"
          "\n"
          "DESCRIPTION\n"
          "    Scan a file with the previously loaded Yara rules.\n"
          "\n"
          "    For each matching rule, a \"yara_detection\" structure is returned.\n"
          "\n"
          "    The \"yara_detection\" structure contains the following fields.\n"
          "\n"
          "    \"yara_name\"\n"
          "        Path of the file matching a Yara rule.\n"
          "\n"
          "    \"yara_rule\"\n"
          "        Identifier of the Yara rule which matched against the given file.\n"
          "\n"
          "",
  .synopsis = "yara-scan path",
  .run = run_yara_scan
};

struct command_entry zgrep_cmd_entry = {
  .name = "zgrep",
  .help = "NAME\n"
          "    zgrep - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     zgrep regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"zgrep\" program and returns the matching lines.\n"
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
  .synopsis = "zgrep regex path",
  .run = run_zgrep
};

