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

struct command_entry acl_set_file_cmd_entry = {
  .name = "acl-set-file",
  .help = "NAME\n"
          "    acl-set-file - set the POSIX ACL attached to a file\n"
          "\n"
          "SYNOPSIS\n"
          "     acl-set-file path acltype acl\n"
          "\n"
          "DESCRIPTION\n"
          "    This function sets the POSIX Access Control List (ACL) attached to\n"
          "    \"path\".\n"
          "\n"
          "    The \"acltype\" parameter may be:\n"
          "\n"
          "    \"access\"\n"
          "        Set the ordinary (access) ACL for any file, directory or other\n"
          "        filesystem object.\n"
          "\n"
          "    \"default\"\n"
          "        Set the default ACL. Normally this only makes sense if \"path\" is a\n"
          "        directory.\n"
          "\n"
          "    The \"acl\" parameter is the new ACL in either \"long text form\" or \"short\n"
          "    text form\" (see acl(5)). The new ACL completely replaces any previous\n"
          "    ACL on the file. The ACL must contain the full Unix permissions (eg.\n"
          "    \"u::rwx,g::rx,o::rx\").\n"
          "\n"
          "    If you are specifying individual users or groups, then the mask field is\n"
          "    also required (eg. \"m::rwx\"), followed by the \"u:*ID*:...\" and/or\n"
          "    \"g:*ID*:...\" field(s). A full ACL string might therefore look like this:\n"
          "\n"
          "     u::rwx,g::rwx,o::rwx,m::rwx,u:500:rwx,g:500:rwx\n"
          "     \\ Unix permissions / \\mask/ \\      ACL        /\n"
          "\n"
          "    You should use numeric UIDs and GIDs. To map usernames and groupnames to\n"
          "    the correct numeric ID in the context of the guest, use the Augeas\n"
          "    functions (see \"aug_init\").\n"
          "\n"
          "",
  .synopsis = "acl-set-file path acltype acl",
  .run = run_acl_set_file
};

struct command_entry add_drive_with_if_cmd_entry = {
  .name = "add-drive-with-if",
  .help = "NAME\n"
          "    add-drive-with-if - add a drive specifying the QEMU block emulation to\n"
          "    use\n"
          "\n"
          "SYNOPSIS\n"
          "     add-drive-with-if filename iface\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"add_drive\" but it allows you to specify the QEMU\n"
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
  .synopsis = "add-drive-with-if filename iface",
  .run = run_add_drive_with_if
};

struct command_entry blockdev_flushbufs_cmd_entry = {
  .name = "blockdev-flushbufs",
  .help = "NAME\n"
          "    blockdev-flushbufs - flush device buffers\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-flushbufs device\n"
          "\n"
          "DESCRIPTION\n"
          "    This tells the kernel to flush internal buffers associated with\n"
          "    \"device\".\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-flushbufs device",
  .run = run_blockdev_flushbufs
};

struct command_entry blockdev_setrw_cmd_entry = {
  .name = "blockdev-setrw",
  .help = "NAME\n"
          "    blockdev-setrw - set block device to read-write\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-setrw device\n"
          "\n"
          "DESCRIPTION\n"
          "    Sets the block device named \"device\" to read-write.\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-setrw device",
  .run = run_blockdev_setrw
};

struct command_entry btrfs_balance_pause_cmd_entry = {
  .name = "btrfs-balance-pause",
  .help = "NAME\n"
          "    btrfs-balance-pause - pause a running balance\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-balance-pause path\n"
          "\n"
          "DESCRIPTION\n"
          "    Pause a running balance on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-balance-pause path",
  .run = run_btrfs_balance_pause
};

struct command_entry btrfs_device_add_cmd_entry = {
  .name = "btrfs-device-add",
  .help = "NAME\n"
          "    btrfs-device-add - add devices to a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-device-add devices fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Add the list of device(s) in \"devices\" to the btrfs filesystem mounted\n"
          "    at \"fs\". If \"devices\" is an empty list, this does nothing.\n"
          "\n"
          "",
  .synopsis = "btrfs-device-add devices fs",
  .run = run_btrfs_device_add
};

struct command_entry btrfs_filesystem_balance_cmd_entry = {
  .name = "btrfs-filesystem-balance",
  .help = "NAME\n"
          "    btrfs-filesystem-balance - balance a btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-filesystem-balance fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Balance the chunks in the btrfs filesystem mounted at \"fs\" across the\n"
          "    underlying devices.\n"
          "\n"
          "    You can use 'btrfs-balance' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "btrfs-filesystem-balance fs",
  .run = run_btrfs_filesystem_balance
};

struct command_entry btrfs_filesystem_show_cmd_entry = {
  .name = "btrfs-filesystem-show",
  .help = "NAME\n"
          "    btrfs-filesystem-show - list devices for btrfs filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-filesystem-show device\n"
          "\n"
          "DESCRIPTION\n"
          "    Show all the devices where the filesystems in \"device\" is spanned over.\n"
          "\n"
          "    If not all the devices for the filesystems are present, then this\n"
          "    function fails and the \"errno\" is set to \"ENODEV\".\n"
          "\n"
          "",
  .synopsis = "btrfs-filesystem-show device",
  .run = run_btrfs_filesystem_show
};

struct command_entry btrfs_qgroup_assign_cmd_entry = {
  .name = "btrfs-qgroup-assign",
  .help = "NAME\n"
          "    btrfs-qgroup-assign - add a qgroup to a parent qgroup\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-qgroup-assign src dst path\n"
          "\n"
          "DESCRIPTION\n"
          "    Add qgroup \"src\" to parent qgroup \"dst\". This command can group several\n"
          "    qgroups into a parent qgroup to share common limit.\n"
          "\n"
          "",
  .synopsis = "btrfs-qgroup-assign src dst path",
  .run = run_btrfs_qgroup_assign
};

struct command_entry btrfs_replace_cmd_entry = {
  .name = "btrfs-replace",
  .help = "NAME\n"
          "    btrfs-replace - replace a btrfs managed device with another device\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-replace srcdev targetdev mntpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    Replace device of a btrfs filesystem. On a live filesystem, duplicate\n"
          "    the data to the target device which is currently stored on the source\n"
          "    device. After completion of the operation, the source device is wiped\n"
          "    out and removed from the filesystem.\n"
          "\n"
          "    The \"targetdev\" needs to be same size or larger than the \"srcdev\".\n"
          "    Devices which are currently mounted are never allowed to be used as the\n"
          "    \"targetdev\".\n"
          "\n"
          "",
  .synopsis = "btrfs-replace srcdev targetdev mntpoint",
  .run = run_btrfs_replace
};

struct command_entry btrfs_scrub_cancel_cmd_entry = {
  .name = "btrfs-scrub-cancel",
  .help = "NAME\n"
          "    btrfs-scrub-cancel - cancel a running scrub\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-scrub-cancel path\n"
          "\n"
          "DESCRIPTION\n"
          "    Cancel a running scrub on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-scrub-cancel path",
  .run = run_btrfs_scrub_cancel
};

struct command_entry btrfs_subvolume_get_default_cmd_entry = {
  .name = "btrfs-subvolume-get-default",
  .help = "NAME\n"
          "    btrfs-subvolume-get-default - get the default subvolume or snapshot of a\n"
          "    filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-get-default fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the default subvolume or snapshot of a filesystem mounted at\n"
          "    \"mountpoint\".\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-get-default fs",
  .run = run_btrfs_subvolume_get_default
};

struct command_entry btrfstune_seeding_cmd_entry = {
  .name = "btrfstune-seeding",
  .help = "NAME\n"
          "    btrfstune-seeding - enable or disable seeding of a btrfs device\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfstune-seeding device seeding\n"
          "\n"
          "DESCRIPTION\n"
          "    Enable seeding of a btrfs device, this will force a fs readonly so that\n"
          "    you can use it to build other filesystems.\n"
          "\n"
          "",
  .synopsis = "btrfstune-seeding device seeding",
  .run = run_btrfstune_seeding
};

struct command_entry c_pointer_cmd_entry = {
  .name = "c-pointer",
  .help = "NAME\n"
          "    c-pointer - return the C pointer to the guestfs_h handle\n"
          "\n"
          "SYNOPSIS\n"
          "     c-pointer\n"
          "\n"
          "DESCRIPTION\n"
          "    In non-C language bindings, this allows you to retrieve the underlying C\n"
          "    pointer to the handle (ie. \"h *\"). The purpose of this is to allow other\n"
          "    libraries to interwork with libguestfs.\n"
          "\n"
          "",
  .synopsis = "c-pointer",
  .run = run_c_pointer
};

struct command_entry cap_set_file_cmd_entry = {
  .name = "cap-set-file",
  .help = "NAME\n"
          "    cap-set-file - set the Linux capabilities attached to a file\n"
          "\n"
          "SYNOPSIS\n"
          "     cap-set-file path cap\n"
          "\n"
          "DESCRIPTION\n"
          "    This function sets the Linux capabilities attached to \"path\". The\n"
          "    capabilities set \"cap\" should be passed in text form (see\n"
          "    cap_from_text(3)).\n"
          "\n"
          "",
  .synopsis = "cap-set-file path cap",
  .run = run_cap_set_file
};

struct command_entry copy_file_to_device_cmd_entry = {
  .name = "copy-file-to-device",
  .help = "NAME\n"
          "    copy-file-to-device - copy from source file to destination device\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-file-to-device src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    See \"copy_device_to_device\" for a general overview of this call.\n"
          "\n"
          "",
  .synopsis = "copy-file-to-device src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]",
  .run = run_copy_file_to_device
};

struct command_entry copy_file_to_file_cmd_entry = {
  .name = "copy-file-to-file",
  .help = "NAME\n"
          "    copy-file-to-file - copy from source file to destination file\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-file-to-file src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    See \"copy_device_to_device\" for a general overview of this call.\n"
          "\n"
          "    This is not the function you want for copying files. This is for copying\n"
          "    blocks within existing files. See \"cp\", \"cp_a\" and \"mv\" for general file\n"
          "    copying and moving functions.\n"
          "\n"
          "",
  .synopsis = "copy-file-to-file src dest [srcoffset:N] [destoffset:N] [size:N] [sparse:true|false] [append:true|false]",
  .run = run_copy_file_to_file
};

struct command_entry cpio_out_cmd_entry = {
  .name = "cpio-out",
  .help = "NAME\n"
          "    cpio-out - pack directory into cpio file\n"
          "\n"
          "SYNOPSIS\n"
          "     cpio-out directory cpiofile [format:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command packs the contents of directory and downloads it to local\n"
          "    file \"cpiofile\".\n"
          "\n"
          "    The optional \"format\" parameter can be used to select the format. Only\n"
          "    the following formats are currently permitted:\n"
          "\n"
          "    \"newc\"\n"
          "        New (SVR4) portable format. This format happens to be compatible\n"
          "        with the cpio-like format used by the Linux kernel for initramfs.\n"
          "\n"
          "        This is the default format.\n"
          "\n"
          "    \"crc\"\n"
          "        New (SVR4) portable format with a checksum.\n"
          "\n"
          "",
  .synopsis = "cpio-out directory cpiofile [format:..]",
  .run = run_cpio_out
};

struct command_entry disk_virtual_size_cmd_entry = {
  .name = "disk-virtual-size",
  .help = "NAME\n"
          "    disk-virtual-size - return virtual size of a disk\n"
          "\n"
          "SYNOPSIS\n"
          "     disk-virtual-size filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Detect and return the virtual size in bytes of the disk image called\n"
          "    filename.\n"
          "\n"
          "    Note that detecting disk features can be insecure under some\n"
          "    circumstances. See \"CVE-2010-3851\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "disk-virtual-size filename",
  .run = run_disk_virtual_size
};

struct command_entry download_cmd_entry = {
  .name = "download",
  .help = "NAME\n"
          "    download - download a file to the local machine\n"
          "\n"
          "SYNOPSIS\n"
          "     download remotefilename filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Download file remotefilename and save it as filename on the local\n"
          "    machine.\n"
          "\n"
          "    filename can also be a named pipe.\n"
          "\n"
          "    See also \"upload\", \"cat\".\n"
          "\n"
          "",
  .synopsis = "download remotefilename filename",
  .run = run_download
};

struct command_entry feature_available_cmd_entry = {
  .name = "feature-available",
  .help = "NAME\n"
          "    feature-available - test availability of some parts of the API\n"
          "\n"
          "SYNOPSIS\n"
          "     feature-available groups\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"available\", but unlike that call it returns a\n"
          "    simple true/false boolean result, instead of throwing an exception if a\n"
          "    feature is not found. For other documentation see \"available\".\n"
          "\n"
          "",
  .synopsis = "feature-available groups",
  .run = run_feature_available
};

struct command_entry fill_pattern_cmd_entry = {
  .name = "fill-pattern",
  .help = "NAME\n"
          "    fill-pattern - fill a file with a repeating pattern of bytes\n"
          "\n"
          "SYNOPSIS\n"
          "     fill-pattern pattern len path\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is like \"fill\" except that it creates a new file of length\n"
          "    \"len\" containing the repeating pattern of bytes in \"pattern\". The\n"
          "    pattern is truncated if necessary to ensure the length of the file is\n"
          "    exactly \"len\" bytes.\n"
          "\n"
          "",
  .synopsis = "fill-pattern pattern len path",
  .run = run_fill_pattern
};

struct command_entry find0_cmd_entry = {
  .name = "find0",
  .help = "NAME\n"
          "    find0 - find all files and directories, returning NUL-separated list\n"
          "\n"
          "SYNOPSIS\n"
          "     find0 directory files\n"
          "\n"
          "DESCRIPTION\n"
          "    This command lists out all files and directories, recursively, starting\n"
          "    at directory, placing the resulting list in the external file called\n"
          "    files.\n"
          "\n"
          "    This command works the same way as \"find\" with the following exceptions:\n"
          "\n"
          "    *   The resulting list is written to an external file.\n"
          "\n"
          "    *   Items (filenames) in the result are separated by \"\\0\" characters.\n"
          "        See find(1) option *-print0*.\n"
          "\n"
          "    *   The result list is not sorted.\n"
          "\n"
          "",
  .synopsis = "find0 directory files",
  .run = run_find0
};

struct command_entry get_append_cmd_entry = {
  .name = "get-append",
  .help = "NAME\n"
          "    get-append - get the additional kernel options\n"
          "\n"
          "SYNOPSIS\n"
          "     get-append\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the additional kernel options which are added to the libguestfs\n"
          "    appliance kernel command line.\n"
          "\n"
          "    If \"NULL\" then no options are added.\n"
          "\n"
          "",
  .synopsis = "get-append",
  .run = run_get_append
};

struct command_entry get_memsize_cmd_entry = {
  .name = "get-memsize",
  .help = "NAME\n"
          "    get-memsize - get memory allocated to the hypervisor\n"
          "\n"
          "SYNOPSIS\n"
          "     get-memsize\n"
          "\n"
          "DESCRIPTION\n"
          "    This gets the memory size in megabytes allocated to the hypervisor.\n"
          "\n"
          "    If \"set_memsize\" was not called on this handle, and if\n"
          "    \"LIBGUESTFS_MEMSIZE\" was not set, then this returns the compiled-in\n"
          "    default value for memsize.\n"
          "\n"
          "    For more information on the architecture of libguestfs, see guestfs(3).\n"
          "\n"
          "",
  .synopsis = "get-memsize",
  .run = run_get_memsize
};

struct command_entry get_program_cmd_entry = {
  .name = "get-program",
  .help = "NAME\n"
          "    get-program - get the program name\n"
          "\n"
          "SYNOPSIS\n"
          "     get-program\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the program name. See \"set_program\".\n"
          "\n"
          "",
  .synopsis = "get-program",
  .run = run_get_program
};

struct command_entry head_n_cmd_entry = {
  .name = "head-n",
  .help = "NAME\n"
          "    head-n - return first N lines of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     head-n nrlines path\n"
          "\n"
          "DESCRIPTION\n"
          "    If the parameter \"nrlines\" is a positive number, this returns the first\n"
          "    \"nrlines\" lines of the file \"path\".\n"
          "\n"
          "    If the parameter \"nrlines\" is a negative number, this returns lines from\n"
          "    the file \"path\", excluding the last \"nrlines\" lines.\n"
          "\n"
          "    If the parameter \"nrlines\" is zero, this returns an empty list.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "head-n nrlines path",
  .run = run_head_n
};

struct command_entry hivex_commit_cmd_entry = {
  .name = "hivex-commit",
  .help = "NAME\n"
          "    hivex-commit - commit (write) changes back to the hive\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-commit filename\n"
          "\n"
          "DESCRIPTION\n"
          "    Commit (write) changes to the hive.\n"
          "\n"
          "    If the optional filename parameter is null, then the changes are written\n"
          "    back to the same hive that was opened. If this is not null then they are\n"
          "    written to the alternate filename given and the original hive is left\n"
          "    untouched.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-commit filename",
  .run = run_hivex_commit
};

struct command_entry hivex_node_delete_child_cmd_entry = {
  .name = "hivex-node-delete-child",
  .help = "NAME\n"
          "    hivex-node-delete-child - delete a node (recursively)\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-delete-child nodeh\n"
          "\n"
          "DESCRIPTION\n"
          "    Delete \"nodeh\", recursively if necessary.\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-delete-child nodeh",
  .run = run_hivex_node_delete_child
};

struct command_entry initrd_cat_cmd_entry = {
  .name = "initrd-cat",
  .help = "NAME\n"
          "    initrd-cat - list the contents of a single file in an initrd\n"
          "\n"
          "SYNOPSIS\n"
          "     initrd-cat initrdpath filename\n"
          "\n"
          "DESCRIPTION\n"
          "    This command unpacks the file filename from the initrd file called\n"
          "    initrdpath. The filename must be given *without* the initial /\n"
          "    character.\n"
          "\n"
          "    For example, in guestfish you could use the following command to examine\n"
          "    the boot script (usually called /init) contained in a Linux initrd or\n"
          "    initramfs image:\n"
          "\n"
          "     initrd-cat /boot/initrd-<version>.img init\n"
          "\n"
          "    See also \"initrd_list\".\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "initrd-cat initrdpath filename",
  .run = run_initrd_cat
};

struct command_entry inotify_close_cmd_entry = {
  .name = "inotify-close",
  .help = "NAME\n"
          "    inotify-close - close the inotify handle\n"
          "\n"
          "SYNOPSIS\n"
          "     inotify-close\n"
          "\n"
          "DESCRIPTION\n"
          "    This closes the inotify handle which was previously opened by\n"
          "    inotify_init. It removes all watches, throws away any pending events,\n"
          "    and deallocates all resources.\n"
          "\n"
          "",
  .synopsis = "inotify-close",
  .run = run_inotify_close
};

struct command_entry inspect_get_major_version_cmd_entry = {
  .name = "inspect-get-major-version",
  .help = "NAME\n"
          "    inspect-get-major-version - get major version of inspected operating\n"
          "    system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-major-version root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the major version number of the inspected operating system.\n"
          "\n"
          "    Windows uses a consistent versioning scheme which is *not* reflected in\n"
          "    the popular public names used by the operating system. Notably the\n"
          "    operating system known as \"Windows 7\" is really version 6.1 (ie. major =\n"
          "    6, minor = 1). You can find out the real versions corresponding to\n"
          "    releases of Windows by consulting Wikipedia or MSDN.\n"
          "\n"
          "    If the version could not be determined, then 0 is returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-major-version root",
  .run = run_inspect_get_major_version
};

struct command_entry inspect_get_roots_cmd_entry = {
  .name = "inspect-get-roots",
  .help = "NAME\n"
          "    inspect-get-roots - return list of operating systems found by last\n"
          "    inspection\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-roots\n"
          "\n"
          "DESCRIPTION\n"
          "    This function is a convenient way to get the list of root devices, as\n"
          "    returned from a previous call to \"inspect_os\", but without redoing the\n"
          "    whole inspection process.\n"
          "\n"
          "    This returns an empty list if either no root devices were found or the\n"
          "    caller has not called \"inspect_os\".\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-roots",
  .run = run_inspect_get_roots
};

struct command_entry is_blockdev_cmd_entry = {
  .name = "is-blockdev",
  .help = "NAME\n"
          "    is-blockdev - test if block device\n"
          "\n"
          "SYNOPSIS\n"
          "     is-blockdev path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a block device with the\n"
          "    given \"path\" name.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a block device also causes the function to\n"
          "    return true.\n"
          "\n"
          "    This call only looks at files within the guest filesystem. Libguestfs\n"
          "    partitions and block devices (eg. /dev/sda) cannot be used as the \"path\"\n"
          "    parameter of this call.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-blockdev-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-blockdev path [followsymlinks:true|false]",
  .run = run_is_blockdev
};

struct command_entry is_config_cmd_entry = {
  .name = "is-config",
  .help = "NAME\n"
          "    is-config - is in configuration state\n"
          "\n"
          "SYNOPSIS\n"
          "     is-config\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns true iff this handle is being configured (in the \"CONFIG\"\n"
          "    state).\n"
          "\n"
          "    For more information on states, see guestfs(3).\n"
          "\n"
          "",
  .synopsis = "is-config",
  .run = run_is_config
};

struct command_entry is_fifo_cmd_entry = {
  .name = "is-fifo",
  .help = "NAME\n"
          "    is-fifo - test if FIFO (named pipe)\n"
          "\n"
          "SYNOPSIS\n"
          "     is-fifo path [followsymlinks:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns \"true\" if and only if there is a FIFO (named pipe) with the\n"
          "    given \"path\" name.\n"
          "\n"
          "    If the optional flag \"followsymlinks\" is true, then a symlink (or chain\n"
          "    of symlinks) that ends with a FIFO also causes the function to return\n"
          "    true.\n"
          "\n"
          "    See also \"stat\".\n"
          "\n"
          "    You can use 'is-fifo-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "is-fifo path [followsymlinks:true|false]",
  .run = run_is_fifo
};

struct command_entry isoinfo_device_cmd_entry = {
  .name = "isoinfo-device",
  .help = "NAME\n"
          "    isoinfo-device - get ISO information from primary volume descriptor of\n"
          "    device\n"
          "\n"
          "SYNOPSIS\n"
          "     isoinfo-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    \"device\" is an ISO device. This returns a struct of information read\n"
          "    from the primary volume descriptor (the ISO equivalent of the\n"
          "    superblock) of the device.\n"
          "\n"
          "    Usually it is more efficient to use the isoinfo(1) command with the *-d*\n"
          "    option on the host to analyze ISO files, instead of going through\n"
          "    libguestfs.\n"
          "\n"
          "    For information on the primary volume descriptor fields, see\n"
          "    <http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descriptor>\n"
          "\n"
          "",
  .synopsis = "isoinfo-device device",
  .run = run_isoinfo_device
};

struct command_entry journal_next_cmd_entry = {
  .name = "journal-next",
  .help = "NAME\n"
          "    journal-next - move to the next journal entry\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-next\n"
          "\n"
          "DESCRIPTION\n"
          "    Move to the next journal entry. You have to call this at least once\n"
          "    after opening the handle before you are able to read data.\n"
          "\n"
          "    The returned boolean tells you if there are any more journal records to\n"
          "    read. \"true\" means you can read the next record (eg. using\n"
          "    \"journal_get\"), and \"false\" means you have reached the end of the\n"
          "    journal.\n"
          "\n"
          "",
  .synopsis = "journal-next",
  .run = run_journal_next
};

struct command_entry journal_skip_cmd_entry = {
  .name = "journal-skip",
  .help = "NAME\n"
          "    journal-skip - skip forwards or backwards in the journal\n"
          "\n"
          "SYNOPSIS\n"
          "     journal-skip skip\n"
          "\n"
          "DESCRIPTION\n"
          "    Skip forwards (\"skip ≥ 0\") or backwards (\"skip < 0\") in the journal.\n"
          "\n"
          "    The number of entries actually skipped is returned (note \"rskip ≥ 0\").\n"
          "    If this is not the same as the absolute value of the skip parameter\n"
          "    (\"|skip|\") you passed in then it means you have reached the end or the\n"
          "    start of the journal.\n"
          "\n"
          "",
  .synopsis = "journal-skip skip",
  .run = run_journal_skip
};

struct command_entry ldmtool_volume_partitions_cmd_entry = {
  .name = "ldmtool-volume-partitions",
  .help = "NAME\n"
          "    ldmtool-volume-partitions - return the partitions in a Windows dynamic\n"
          "    disk volume\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-volume-partitions diskgroup volume\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the list of partitions in the volume named \"volume\" in the disk\n"
          "    group with GUID \"diskgroup\".\n"
          "\n"
          "",
  .synopsis = "ldmtool-volume-partitions diskgroup volume",
  .run = run_ldmtool_volume_partitions
};

struct command_entry list_disk_labels_cmd_entry = {
  .name = "list-disk-labels",
  .help = "NAME\n"
          "    list-disk-labels - mapping of disk labels to devices\n"
          "\n"
          "SYNOPSIS\n"
          "     list-disk-labels\n"
          "\n"
          "DESCRIPTION\n"
          "    If you add drives using the optional \"label\" parameter of\n"
          "    \"add_drive_opts\", you can use this call to map between disk labels, and\n"
          "    raw block device and partition names (like /dev/sda and /dev/sda1).\n"
          "\n"
          "    This returns a hashtable, where keys are the disk labels (*without* the\n"
          "    /dev/disk/guestfs prefix), and the values are the full raw block device\n"
          "    and partition names (eg. /dev/sda and /dev/sda1).\n"
          "\n"
          "",
  .synopsis = "list-disk-labels",
  .run = run_list_disk_labels
};

struct command_entry list_md_devices_cmd_entry = {
  .name = "list-md-devices",
  .help = "NAME\n"
          "    list-md-devices - list Linux md (RAID) devices\n"
          "\n"
          "SYNOPSIS\n"
          "     list-md-devices\n"
          "\n"
          "DESCRIPTION\n"
          "    List all Linux md devices.\n"
          "\n"
          "",
  .synopsis = "list-md-devices",
  .run = run_list_md_devices
};

struct command_entry ln_cmd_entry = {
  .name = "ln",
  .help = "NAME\n"
          "    ln - create a hard link\n"
          "\n"
          "SYNOPSIS\n"
          "     ln target linkname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a hard link using the \"ln\" command.\n"
          "\n"
          "",
  .synopsis = "ln target linkname",
  .run = run_ln
};

struct command_entry ln_sf_cmd_entry = {
  .name = "ln-sf",
  .help = "NAME\n"
          "    ln-sf - create a symbolic link\n"
          "\n"
          "SYNOPSIS\n"
          "     ln-sf target linkname\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates a symbolic link using the \"ln -sf\" command, The\n"
          "    *-f* option removes the link (\"linkname\") if it exists already.\n"
          "\n"
          "",
  .synopsis = "ln-sf target linkname",
  .run = run_ln_sf
};

struct command_entry luks_add_key_cmd_entry = {
  .name = "luks-add-key",
  .help = "NAME\n"
          "    luks-add-key - add a key on a LUKS encrypted device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-add-key device keyslot\n"
          "\n"
          "DESCRIPTION\n"
          "    This command adds a new key on LUKS device \"device\". \"key\" is any\n"
          "    existing key, and is used to access the device. \"newkey\" is the new key\n"
          "    to add. \"keyslot\" is the key slot that will be replaced.\n"
          "\n"
          "    Note that if \"keyslot\" already contains a key, then this command will\n"
          "    fail. You have to use \"luks_kill_slot\" first to remove that key.\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-add-key device keyslot",
  .run = run_luks_add_key
};

struct command_entry lvcreate_cmd_entry = {
  .name = "lvcreate",
  .help = "NAME\n"
          "    lvcreate - create an LVM logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     lvcreate logvol volgroup mbytes\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an LVM logical volume called \"logvol\" on the volume group\n"
          "    \"volgroup\", with \"size\" megabytes.\n"
          "\n"
          "",
  .synopsis = "lvcreate logvol volgroup mbytes",
  .run = run_lvcreate
};

struct command_entry lvcreate_free_cmd_entry = {
  .name = "lvcreate-free",
  .help = "NAME\n"
          "    lvcreate-free - create an LVM logical volume in % remaining free space\n"
          "\n"
          "SYNOPSIS\n"
          "     lvcreate-free logvol volgroup percent\n"
          "\n"
          "DESCRIPTION\n"
          "    Create an LVM logical volume called /dev/volgroup/logvol, using\n"
          "    approximately \"percent\" % of the free space remaining in the volume\n"
          "    group. Most usefully, when \"percent\" is 100 this will create the largest\n"
          "    possible LV.\n"
          "\n"
          "",
  .synopsis = "lvcreate-free logvol volgroup percent",
  .run = run_lvcreate_free
};

struct command_entry lvm_set_filter_cmd_entry = {
  .name = "lvm-set-filter",
  .help = "NAME\n"
          "    lvm-set-filter - set LVM device filter\n"
          "\n"
          "SYNOPSIS\n"
          "     lvm-set-filter devices\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the LVM device filter so that LVM will only be able to \"see\"\n"
          "    the block devices in the list \"devices\", and will ignore all other\n"
          "    attached block devices.\n"
          "\n"
          "    Where disk image(s) contain duplicate PVs or VGs, this command is useful\n"
          "    to get LVM to ignore the duplicates, otherwise LVM can get confused.\n"
          "    Note also there are two types of duplication possible: either cloned\n"
          "    PVs/VGs which have identical UUIDs; or VGs that are not cloned but just\n"
          "    happen to have the same name. In normal operation you cannot create this\n"
          "    situation, but you can do it outside LVM, eg. by cloning disk images or\n"
          "    by bit twiddling inside the LVM metadata.\n"
          "\n"
          "    This command also clears the LVM cache and performs a volume group scan.\n"
          "\n"
          "    You can filter whole block devices or individual partitions.\n"
          "\n"
          "    You cannot use this if any VG is currently in use (eg. contains a\n"
          "    mounted filesystem), even if you are not filtering out that VG.\n"
          "\n"
          "",
  .synopsis = "lvm-set-filter devices",
  .run = run_lvm_set_filter
};

struct command_entry lvs_full_cmd_entry = {
  .name = "lvs-full",
  .help = "NAME\n"
          "    lvs-full - list the LVM logical volumes (LVs)\n"
          "\n"
          "SYNOPSIS\n"
          "     lvs-full\n"
          "\n"
          "DESCRIPTION\n"
          "    List all the logical volumes detected. This is the equivalent of the\n"
          "    lvs(8) command. The \"full\" version includes all fields.\n"
          "\n"
          "",
  .synopsis = "lvs-full",
  .run = run_lvs_full
};

struct command_entry md_stat_cmd_entry = {
  .name = "md-stat",
  .help = "NAME\n"
          "    md-stat - get underlying devices from an MD device\n"
          "\n"
          "SYNOPSIS\n"
          "     md-stat md\n"
          "\n"
          "DESCRIPTION\n"
          "    This call returns a list of the underlying devices which make up the\n"
          "    single software RAID array device \"md\".\n"
          "\n"
          "    To get a list of software RAID devices, call \"list_md_devices\".\n"
          "\n"
          "    Each structure returned corresponds to one device along with additional\n"
          "    status information:\n"
          "\n"
          "    \"mdstat_device\"\n"
          "        The name of the underlying device.\n"
          "\n"
          "    \"mdstat_index\"\n"
          "        The index of this device within the array.\n"
          "\n"
          "    \"mdstat_flags\"\n"
          "        Flags associated with this device. This is a string containing (in\n"
          "        no specific order) zero or more of the following flags:\n"
          "\n"
          "        \"W\" write-mostly\n"
          "\n"
          "        \"F\" device is faulty\n"
          "\n"
          "        \"S\" device is a RAID spare\n"
          "\n"
          "        \"R\" replacement\n"
          "\n"
          "",
  .synopsis = "md-stat md",
  .run = run_md_stat
};

struct command_entry mkfs_cmd_entry = {
  .name = "mkfs",
  .help = "NAME\n"
          "    mkfs - make a filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     mkfs fstype device [blocksize:N] [features:..] [inode:N] [sectorsize:N] [label:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    This function creates a filesystem on \"device\". The filesystem type is\n"
          "    \"fstype\", for example \"ext3\".\n"
          "\n"
          "    The optional arguments are:\n"
          "\n"
          "    \"blocksize\"\n"
          "        The filesystem block size. Supported block sizes depend on the\n"
          "        filesystem type, but typically they are 1024, 2048 or 4096 for Linux\n"
          "        ext2/3 filesystems.\n"
          "\n"
          "        For VFAT and NTFS the \"blocksize\" parameter is treated as the\n"
          "        requested cluster size.\n"
          "\n"
          "        For UFS block sizes, please see mkfs.ufs(8).\n"
          "\n"
          "    \"features\"\n"
          "        This passes the *-O* parameter to the external mkfs program.\n"
          "\n"
          "        For certain filesystem types, this allows extra filesystem features\n"
          "        to be selected. See mke2fs(8) and mkfs.ufs(8) for more details.\n"
          "\n"
          "        You cannot use this optional parameter with the \"gfs\" or \"gfs2\"\n"
          "        filesystem type.\n"
          "\n"
          "    \"inode\"\n"
          "        This passes the *-I* parameter to the external mke2fs(8) program\n"
          "        which sets the inode size (only for ext2/3/4 filesystems at\n"
          "        present).\n"
          "\n"
          "    \"sectorsize\"\n"
          "        This passes the *-S* parameter to external mkfs.ufs(8) program,\n"
          "        which sets sector size for ufs filesystem.\n"
          "\n"
          "    You can use 'mkfs-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "mkfs fstype device [blocksize:N] [features:..] [inode:N] [sectorsize:N] [label:..]",
  .run = run_mkfs
};

struct command_entry mkfs_b_cmd_entry = {
  .name = "mkfs-b",
  .help = "NAME\n"
          "    mkfs-b - make a filesystem with block size\n"
          "\n"
          "SYNOPSIS\n"
          "     mkfs-b fstype blocksize device\n"
          "\n"
          "DESCRIPTION\n"
          "    This call is similar to \"mkfs\", but it allows you to control the block\n"
          "    size of the resulting filesystem. Supported block sizes depend on the\n"
          "    filesystem type, but typically they are 1024, 2048 or 4096 only.\n"
          "\n"
          "    For VFAT and NTFS the \"blocksize\" parameter is treated as the requested\n"
          "    cluster size.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mkfs\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mkfs-b fstype blocksize device",
  .run = run_mkfs_b
};

struct command_entry mkswap_U_cmd_entry = {
  .name = "mkswap-U",
  .help = "NAME\n"
          "    mkswap-U - create a swap partition with an explicit UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     mkswap-U uuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a swap partition on \"device\" with UUID \"uuid\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mkswap\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mkswap-U uuid device",
  .run = run_mkswap_U
};

struct command_entry mountpoints_cmd_entry = {
  .name = "mountpoints",
  .help = "NAME\n"
          "    mountpoints - show mountpoints\n"
          "\n"
          "SYNOPSIS\n"
          "     mountpoints\n"
          "\n"
          "DESCRIPTION\n"
          "    This call is similar to \"mounts\". That call returns a list of devices.\n"
          "    This one returns a hash table (map) of device name to directory where\n"
          "    the device is mounted.\n"
          "\n"
          "",
  .synopsis = "mountpoints",
  .run = run_mountpoints
};

struct command_entry nr_devices_cmd_entry = {
  .name = "nr-devices",
  .help = "NAME\n"
          "    nr-devices - return number of whole block devices (disks) added\n"
          "\n"
          "SYNOPSIS\n"
          "     nr-devices\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the number of whole block devices that were added. This is\n"
          "    the same as the number of devices that would be returned if you called\n"
          "    \"list_devices\".\n"
          "\n"
          "    To find out the maximum number of devices that could be added, call\n"
          "    \"max_disks\".\n"
          "\n"
          "",
  .synopsis = "nr-devices",
  .run = run_nr_devices
};

struct command_entry ntfsclone_in_cmd_entry = {
  .name = "ntfsclone-in",
  .help = "NAME\n"
          "    ntfsclone-in - restore NTFS from backup file\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfsclone-in backupfile device\n"
          "\n"
          "DESCRIPTION\n"
          "    Restore the \"backupfile\" (from a previous call to \"ntfsclone_out\") to\n"
          "    \"device\", overwriting any existing contents of this device.\n"
          "\n"
          "",
  .synopsis = "ntfsclone-in backupfile device",
  .run = run_ntfsclone_in
};

struct command_entry parse_environment_list_cmd_entry = {
  .name = "parse-environment-list",
  .help = "NAME\n"
          "    parse-environment-list - parse the environment and set handle flags\n"
          "    accordingly\n"
          "\n"
          "SYNOPSIS\n"
          "     parse-environment-list environment\n"
          "\n"
          "DESCRIPTION\n"
          "    Parse the list of strings in the argument \"environment\" and set flags in\n"
          "    the handle accordingly. For example if \"LIBGUESTFS_DEBUG=1\" is a string\n"
          "    in the list, then the 'verbose' flag is set in the handle.\n"
          "\n"
          "    This is the same as \"parse_environment\" except that it parses an\n"
          "    explicit list of strings instead of the program's environment.\n"
          "\n"
          "",
  .synopsis = "parse-environment-list environment",
  .run = run_parse_environment_list
};

struct command_entry part_get_bootable_cmd_entry = {
  .name = "part-get-bootable",
  .help = "NAME\n"
          "    part-get-bootable - return true if a partition is bootable\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-bootable device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns true if the partition \"partnum\" on \"device\" has the\n"
          "    bootable flag set.\n"
          "\n"
          "    See also \"part_set_bootable\".\n"
          "\n"
          "",
  .synopsis = "part-get-bootable device partnum",
  .run = run_part_get_bootable
};

struct command_entry part_set_gpt_type_cmd_entry = {
  .name = "part-set-gpt-type",
  .help = "NAME\n"
          "    part-set-gpt-type - set the type GUID of a GPT partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-gpt-type device partnum guid\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the type GUID of numbered GPT partition \"partnum\" to \"guid\". Return\n"
          "    an error if the partition table of \"device\" isn't GPT, or if \"guid\" is\n"
          "    not a valid GUID.\n"
          "\n"
          "    See\n"
          "    <http://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs>\n"
          "    for a useful list of type GUIDs.\n"
          "\n"
          "",
  .synopsis = "part-set-gpt-type device partnum guid",
  .run = run_part_set_gpt_type
};

struct command_entry part_set_name_cmd_entry = {
  .name = "part-set-name",
  .help = "NAME\n"
          "    part-set-name - set partition name\n"
          "\n"
          "SYNOPSIS\n"
          "     part-set-name device partnum name\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the partition name on partition numbered \"partnum\" on device\n"
          "    \"device\". Note that partitions are numbered from 1.\n"
          "\n"
          "    The partition name can only be set on certain types of partition table.\n"
          "    This works on \"gpt\" but not on \"mbr\" partitions.\n"
          "\n"
          "",
  .synopsis = "part-set-name device partnum name",
  .run = run_part_set_name
};

struct command_entry pvremove_cmd_entry = {
  .name = "pvremove",
  .help = "NAME\n"
          "    pvremove - remove an LVM physical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     pvremove device\n"
          "\n"
          "DESCRIPTION\n"
          "    This wipes a physical volume \"device\" so that LVM will no longer\n"
          "    recognise it.\n"
          "\n"
          "    The implementation uses the \"pvremove\" command which refuses to wipe\n"
          "    physical volumes that contain any volume groups, so you have to remove\n"
          "    those first.\n"
          "\n"
          "",
  .synopsis = "pvremove device",
  .run = run_pvremove
};

struct command_entry scrub_freespace_cmd_entry = {
  .name = "scrub-freespace",
  .help = "NAME\n"
          "    scrub-freespace - scrub (securely wipe) free space\n"
          "\n"
          "SYNOPSIS\n"
          "     scrub-freespace dir\n"
          "\n"
          "DESCRIPTION\n"
          "    This command creates the directory \"dir\" and then fills it with files\n"
          "    until the filesystem is full, and scrubs the files as for \"scrub_file\",\n"
          "    and deletes them. The intention is to scrub any free space on the\n"
          "    partition containing \"dir\".\n"
          "\n"
          "    It is an interface to the scrub(1) program. See that manual page for\n"
          "    more details.\n"
          "\n"
          "",
  .synopsis = "scrub-freespace dir",
  .run = run_scrub_freespace
};

struct command_entry set_attach_method_cmd_entry = {
  .name = "set-attach-method",
  .help = "NAME\n"
          "    set-attach-method - set the backend\n"
          "\n"
          "SYNOPSIS\n"
          "     set-attach-method backend\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the method that libguestfs uses to connect to the backend guestfsd\n"
          "    daemon.\n"
          "\n"
          "    See \"BACKEND\" in guestfs(3).\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"set-backend\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "    You can use 'attach-method' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-attach-method backend",
  .run = run_set_attach_method
};

struct command_entry set_network_cmd_entry = {
  .name = "set-network",
  .help = "NAME\n"
          "    set-network - set enable network flag\n"
          "\n"
          "SYNOPSIS\n"
          "     set-network network\n"
          "\n"
          "DESCRIPTION\n"
          "    If \"network\" is true, then the network is enabled in the libguestfs\n"
          "    appliance. The default is false.\n"
          "\n"
          "    This affects whether commands are able to access the network (see\n"
          "    \"RUNNING COMMANDS\" in guestfs(3)).\n"
          "\n"
          "    You must call this before calling \"launch\", otherwise it has no effect.\n"
          "\n"
          "    You can use 'network' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-network network",
  .run = run_set_network
};

struct command_entry set_smp_cmd_entry = {
  .name = "set-smp",
  .help = "NAME\n"
          "    set-smp - set number of virtual CPUs in appliance\n"
          "\n"
          "SYNOPSIS\n"
          "     set-smp smp\n"
          "\n"
          "DESCRIPTION\n"
          "    Change the number of virtual CPUs assigned to the appliance. The default\n"
          "    is 1. Increasing this may improve performance, though often it has no\n"
          "    effect.\n"
          "\n"
          "    This function must be called before \"launch\".\n"
          "\n"
          "    You can use 'smp' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-smp smp",
  .run = run_set_smp
};

struct command_entry set_tmpdir_cmd_entry = {
  .name = "set-tmpdir",
  .help = "NAME\n"
          "    set-tmpdir - set the temporary directory\n"
          "\n"
          "SYNOPSIS\n"
          "     set-tmpdir tmpdir\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the directory used by the handle to store temporary files.\n"
          "\n"
          "    The environment variables \"LIBGUESTFS_TMPDIR\" and \"TMPDIR\" control the\n"
          "    default value: If \"LIBGUESTFS_TMPDIR\" is set, then that is the default.\n"
          "    Else if \"TMPDIR\" is set, then that is the default. Else /tmp is the\n"
          "    default.\n"
          "\n"
          "    You can use 'tmpdir' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-tmpdir tmpdir",
  .run = run_set_tmpdir
};

struct command_entry set_trace_cmd_entry = {
  .name = "set-trace",
  .help = "NAME\n"
          "    set-trace - enable or disable command traces\n"
          "\n"
          "SYNOPSIS\n"
          "     set-trace trace\n"
          "\n"
          "DESCRIPTION\n"
          "    If the command trace flag is set to 1, then libguestfs calls, parameters\n"
          "    and return values are traced.\n"
          "\n"
          "    If you want to trace C API calls into libguestfs (and other libraries)\n"
          "    then possibly a better way is to use the external ltrace(1) command.\n"
          "\n"
          "    Command traces are disabled unless the environment variable\n"
          "    \"LIBGUESTFS_TRACE\" is defined and set to 1.\n"
          "\n"
          "    Trace messages are normally sent to \"stderr\", unless you register a\n"
          "    callback to send them somewhere else (see \"set_event_callback\").\n"
          "\n"
          "    You can use 'trace' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-trace trace",
  .run = run_set_trace
};

struct command_entry set_uuid_random_cmd_entry = {
  .name = "set-uuid-random",
  .help = "NAME\n"
          "    set-uuid-random - set a random UUID for the filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     set-uuid-random device\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the filesystem UUID on \"device\" to a random UUID. If this fails and\n"
          "    the errno is ENOTSUP, means that there is no support for changing the\n"
          "    UUID for the type of the specified filesystem.\n"
          "\n"
          "    Only some filesystem types support setting UUIDs.\n"
          "\n"
          "    To read the UUID on a filesystem, call \"vfs_uuid\".\n"
          "\n"
          "",
  .synopsis = "set-uuid-random device",
  .run = run_set_uuid_random
};

struct command_entry sfdisk_cmd_entry = {
  .name = "sfdisk",
  .help = "NAME\n"
          "    sfdisk - create partitions on a block device\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdisk device cyls heads sectors lines\n"
          "\n"
          "DESCRIPTION\n"
          "    This is a direct interface to the sfdisk(8) program for creating\n"
          "    partitions on block devices.\n"
          "\n"
          "    \"device\" should be a block device, for example /dev/sda.\n"
          "\n"
          "    \"cyls\", \"heads\" and \"sectors\" are the number of cylinders, heads and\n"
          "    sectors on the device, which are passed directly to sfdisk as the *-C*,\n"
          "    *-H* and *-S* parameters. If you pass 0 for any of these, then the\n"
          "    corresponding parameter is omitted. Usually for 'large' disks, you can\n"
          "    just pass 0 for these, but for small (floppy-sized) disks, sfdisk (or\n"
          "    rather, the kernel) cannot work out the right geometry and you will need\n"
          "    to tell it.\n"
          "\n"
          "    \"lines\" is a list of lines that we feed to \"sfdisk\". For more\n"
          "    information refer to the sfdisk(8) manpage.\n"
          "\n"
          "    To create a single partition occupying the whole disk, you would pass\n"
          "    \"lines\" as a single element list, when the single element being the\n"
          "    string \",\" (comma).\n"
          "\n"
          "    See also: \"sfdisk_l\", \"sfdisk_N\", \"part_init\"\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"part-add\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "sfdisk device cyls heads sectors lines",
  .run = run_sfdisk
};

struct command_entry sfdiskM_cmd_entry = {
  .name = "sfdiskM",
  .help = "NAME\n"
          "    sfdiskM - create partitions on a block device\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdiskM device lines\n"
          "\n"
          "DESCRIPTION\n"
          "    This is a simplified interface to the \"sfdisk\" command, where partition\n"
          "    sizes are specified in megabytes only (rounded to the nearest cylinder)\n"
          "    and you don't need to specify the cyls, heads and sectors parameters\n"
          "    which were rarely if ever used anyway.\n"
          "\n"
          "    See also: \"sfdisk\", the sfdisk(8) manpage and \"part_disk\"\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"part-add\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "sfdiskM device lines",
  .run = run_sfdiskM
};

struct command_entry sfdisk_N_cmd_entry = {
  .name = "sfdisk-N",
  .help = "NAME\n"
          "    sfdisk-N - modify a single partition on a block device\n"
          "\n"
          "SYNOPSIS\n"
          "     sfdisk-N device partnum cyls heads sectors line\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs sfdisk(8) option to modify just the single partition \"n\"\n"
          "    (note: \"n\" counts from 1).\n"
          "\n"
          "    For other parameters, see \"sfdisk\". You should usually pass 0 for the\n"
          "    cyls/heads/sectors parameters.\n"
          "\n"
          "    See also: \"part_add\"\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"part-add\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "sfdisk-N device partnum cyls heads sectors line",
  .run = run_sfdisk_N
};

struct command_entry stat_cmd_entry = {
  .name = "stat",
  .help = "NAME\n"
          "    stat - get file information\n"
          "\n"
          "SYNOPSIS\n"
          "     stat path\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns file information for the given \"path\".\n"
          "\n"
          "    This is the same as the stat(2) system call.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"statns\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "stat path",
  .run = run_stat
};

struct command_entry swapoff_device_cmd_entry = {
  .name = "swapoff-device",
  .help = "NAME\n"
          "    swapoff-device - disable swap on device\n"
          "\n"
          "SYNOPSIS\n"
          "     swapoff-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command disables the libguestfs appliance swap device or partition\n"
          "    named \"device\". See \"swapon_device\".\n"
          "\n"
          "",
  .synopsis = "swapoff-device device",
  .run = run_swapoff_device
};

struct command_entry swapon_device_cmd_entry = {
  .name = "swapon-device",
  .help = "NAME\n"
          "    swapon-device - enable swap on device\n"
          "\n"
          "SYNOPSIS\n"
          "     swapon-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command enables the libguestfs appliance to use the swap device or\n"
          "    partition named \"device\". The increased memory is made available for all\n"
          "    commands, for example those run using \"command\" or \"sh\".\n"
          "\n"
          "    Note that you should not swap to existing guest swap partitions unless\n"
          "    you know what you are doing. They may contain hibernation information,\n"
          "    or other information that the guest doesn't want you to trash. You also\n"
          "    risk leaking information about the host to the guest this way. Instead,\n"
          "    attach a new host device to the guest and swap on that.\n"
          "\n"
          "",
  .synopsis = "swapon-device device",
  .run = run_swapon_device
};

struct command_entry swapon_uuid_cmd_entry = {
  .name = "swapon-uuid",
  .help = "NAME\n"
          "    swapon-uuid - enable swap on swap partition by UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     swapon-uuid uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    This command enables swap to a swap partition with the given UUID. See\n"
          "    \"swapon_device\" for other notes.\n"
          "\n"
          "",
  .synopsis = "swapon-uuid uuid",
  .run = run_swapon_uuid
};

struct command_entry tgz_in_cmd_entry = {
  .name = "tgz-in",
  .help = "NAME\n"
          "    tgz-in - unpack compressed tarball to directory\n"
          "\n"
          "SYNOPSIS\n"
          "     tgz-in tarball directory\n"
          "\n"
          "DESCRIPTION\n"
          "    This command uploads and unpacks local file \"tarball\" (a *gzip\n"
          "    compressed* tar file) into directory.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"tar-in\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "tgz-in tarball directory",
  .run = run_tgz_in
};

struct command_entry truncate_size_cmd_entry = {
  .name = "truncate-size",
  .help = "NAME\n"
          "    truncate-size - truncate a file to a particular size\n"
          "\n"
          "SYNOPSIS\n"
          "     truncate-size path size\n"
          "\n"
          "DESCRIPTION\n"
          "    This command truncates \"path\" to size \"size\" bytes. The file must exist\n"
          "    already.\n"
          "\n"
          "    If the current file size is less than \"size\" then the file is extended\n"
          "    to the required size with zero bytes. This creates a sparse file (ie.\n"
          "    disk blocks are not allocated for the file until you write to it). To\n"
          "    create a non-sparse file of zeroes, use \"fallocate64\" instead.\n"
          "\n"
          "",
  .synopsis = "truncate-size path size",
  .run = run_truncate_size
};

struct command_entry txz_in_cmd_entry = {
  .name = "txz-in",
  .help = "NAME\n"
          "    txz-in - unpack compressed tarball to directory\n"
          "\n"
          "SYNOPSIS\n"
          "     txz-in tarball directory\n"
          "\n"
          "DESCRIPTION\n"
          "    This command uploads and unpacks local file \"tarball\" (an *xz\n"
          "    compressed* tar file) into directory.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"tar-in\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "txz-in tarball directory",
  .run = run_txz_in
};

struct command_entry user_cancel_cmd_entry = {
  .name = "user-cancel",
  .help = "NAME\n"
          "    user-cancel - cancel the current upload or download operation\n"
          "\n"
          "SYNOPSIS\n"
          "     user-cancel\n"
          "\n"
          "DESCRIPTION\n"
          "    This function cancels the current upload or download operation.\n"
          "\n"
          "    Unlike most other libguestfs calls, this function is signal safe and\n"
          "    thread safe. You can call it from a signal handler or from another\n"
          "    thread, without needing to do any locking.\n"
          "\n"
          "    The transfer that was in progress (if there is one) will stop shortly\n"
          "    afterwards, and will return an error. The errno (see\n"
          "    \"guestfs_last_errno\") is set to \"EINTR\", so you can test for this to\n"
          "    find out if the operation was cancelled or failed because of another\n"
          "    error.\n"
          "\n"
          "    No cleanup is performed: for example, if a file was being uploaded then\n"
          "    after cancellation there may be a partially uploaded file. It is the\n"
          "    caller's responsibility to clean up if necessary.\n"
          "\n"
          "    There are two common places that you might call \"user_cancel\":\n"
          "\n"
          "    In an interactive text-based program, you might call it from a \"SIGINT\"\n"
          "    signal handler so that pressing \"^C\" cancels the current operation. (You\n"
          "    also need to call \"guestfs_set_pgroup\" so that child processes don't\n"
          "    receive the \"^C\" signal).\n"
          "\n"
          "    In a graphical program, when the main thread is displaying a progress\n"
          "    bar with a cancel button, wire up the cancel button to call this\n"
          "    function.\n"
          "\n"
          "",
  .synopsis = "user-cancel",
  .run = run_user_cancel
};

struct command_entry vgchange_uuid_cmd_entry = {
  .name = "vgchange-uuid",
  .help = "NAME\n"
          "    vgchange-uuid - generate a new random UUID for a volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vgchange-uuid vg\n"
          "\n"
          "DESCRIPTION\n"
          "    Generate a new random UUID for the volume group \"vg\".\n"
          "\n"
          "",
  .synopsis = "vgchange-uuid vg",
  .run = run_vgchange_uuid
};

struct command_entry vglvuuids_cmd_entry = {
  .name = "vglvuuids",
  .help = "NAME\n"
          "    vglvuuids - get the LV UUIDs of all LVs in the volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vglvuuids vgname\n"
          "\n"
          "DESCRIPTION\n"
          "    Given a VG called \"vgname\", this returns the UUIDs of all the logical\n"
          "    volumes created in this volume group.\n"
          "\n"
          "    You can use this along with \"lvs\" and \"lvuuid\" calls to associate\n"
          "    logical volumes and volume groups.\n"
          "\n"
          "    See also \"vgpvuuids\".\n"
          "\n"
          "",
  .synopsis = "vglvuuids vgname",
  .run = run_vglvuuids
};

struct command_entry vgremove_cmd_entry = {
  .name = "vgremove",
  .help = "NAME\n"
          "    vgremove - remove an LVM volume group\n"
          "\n"
          "SYNOPSIS\n"
          "     vgremove vgname\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove an LVM volume group \"vgname\", (for example \"VG\").\n"
          "\n"
          "    This also forcibly removes all logical volumes in the volume group (if\n"
          "    any).\n"
          "\n"
          "",
  .synopsis = "vgremove vgname",
  .run = run_vgremove
};

struct command_entry wc_l_cmd_entry = {
  .name = "wc-l",
  .help = "NAME\n"
          "    wc-l - count lines in a file\n"
          "\n"
          "SYNOPSIS\n"
          "     wc-l path\n"
          "\n"
          "DESCRIPTION\n"
          "    This command counts the lines in a file, using the \"wc -l\" external\n"
          "    command.\n"
          "\n"
          "",
  .synopsis = "wc-l path",
  .run = run_wc_l
};

struct command_entry xfs_growfs_cmd_entry = {
  .name = "xfs-growfs",
  .help = "NAME\n"
          "    xfs-growfs - expand an existing XFS filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     xfs-growfs path [datasec:true|false] [logsec:true|false] [rtsec:true|false] [datasize:N] [logsize:N] [rtsize:N] [rtextsize:N] [maxpct:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    Grow the XFS filesystem mounted at \"path\".\n"
          "\n"
          "    The returned struct contains geometry information. Missing fields are\n"
          "    returned as -1 (for numeric fields) or empty string.\n"
          "\n"
          "",
  .synopsis = "xfs-growfs path [datasec:true|false] [logsec:true|false] [rtsec:true|false] [datasize:N] [logsize:N] [rtsize:N] [rtextsize:N] [maxpct:N]",
  .run = run_xfs_growfs
};

struct command_entry xfs_info_cmd_entry = {
  .name = "xfs-info",
  .help = "NAME\n"
          "    xfs-info - get geometry of XFS filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     xfs-info pathordevice\n"
          "\n"
          "DESCRIPTION\n"
          "    \"pathordevice\" is a mounted XFS filesystem or a device containing an XFS\n"
          "    filesystem. This command returns the geometry of the filesystem.\n"
          "\n"
          "    The returned struct contains geometry information. Missing fields are\n"
          "    returned as -1 (for numeric fields) or empty string.\n"
          "\n"
          "",
  .synopsis = "xfs-info pathordevice",
  .run = run_xfs_info
};

struct command_entry xfs_repair_cmd_entry = {
  .name = "xfs-repair",
  .help = "NAME\n"
          "    xfs-repair - repair an XFS filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     xfs-repair device [forcelogzero:true|false] [nomodify:true|false] [noprefetch:true|false] [forcegeometry:true|false] [maxmem:N] [ihashsize:N] [bhashsize:N] [agstride:N] [logdev:..] [rtdev:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Repair corrupt or damaged XFS filesystem on \"device\".\n"
          "\n"
          "    The filesystem is specified using the \"device\" argument which should be\n"
          "    the device name of the disk partition or volume containing the\n"
          "    filesystem. If given the name of a block device, \"xfs_repair\" will\n"
          "    attempt to find the raw device associated with the specified block\n"
          "    device and will use the raw device instead.\n"
          "\n"
          "    Regardless, the filesystem to be repaired must be unmounted, otherwise,\n"
          "    the resulting filesystem may be inconsistent or corrupt.\n"
          "\n"
          "    The returned status indicates whether filesystem corruption was detected\n"
          "    (returns 1) or was not detected (returns 0).\n"
          "\n"
          "",
  .synopsis = "xfs-repair device [forcelogzero:true|false] [nomodify:true|false] [noprefetch:true|false] [forcegeometry:true|false] [maxmem:N] [ihashsize:N] [bhashsize:N] [agstride:N] [logdev:..] [rtdev:..]",
  .run = run_xfs_repair
};

struct command_entry zero_device_cmd_entry = {
  .name = "zero-device",
  .help = "NAME\n"
          "    zero-device - write zeroes to an entire device\n"
          "\n"
          "SYNOPSIS\n"
          "     zero-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes zeroes over the entire \"device\". Compare with \"zero\"\n"
          "    which just zeroes the first few blocks of a device.\n"
          "\n"
          "    If blocks are already zero, then this command avoids writing zeroes.\n"
          "    This prevents the underlying device from becoming non-sparse or growing\n"
          "    unnecessarily.\n"
          "\n"
          "",
  .synopsis = "zero-device device",
  .run = run_zero_device
};

struct command_entry zero_free_space_cmd_entry = {
  .name = "zero-free-space",
  .help = "NAME\n"
          "    zero-free-space - zero free space in a filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     zero-free-space directory\n"
          "\n"
          "DESCRIPTION\n"
          "    Zero the free space in the filesystem mounted on directory. The\n"
          "    filesystem must be mounted read-write.\n"
          "\n"
          "    The filesystem contents are not affected, but any free space in the\n"
          "    filesystem is freed.\n"
          "\n"
          "    Free space is not \"trimmed\". You may want to call \"fstrim\" either as an\n"
          "    alternative to this, or after calling this, depending on your\n"
          "    requirements.\n"
          "\n"
          "",
  .synopsis = "zero-free-space directory",
  .run = run_zero_free_space
};

