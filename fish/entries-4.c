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

struct command_entry add_cdrom_cmd_entry = {
  .name = "add-cdrom",
  .help = "NAME\n"
          "    add-cdrom - add a CD-ROM disk image to examine\n"
          "\n"
          "SYNOPSIS\n"
          "     add-cdrom filename\n"
          "\n"
          "DESCRIPTION\n"
          "    This function adds a virtual CD-ROM disk image to the guest.\n"
          "\n"
          "    The image is added as read-only drive, so this function is equivalent of\n"
          "    \"add_drive_ro\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"add-drive-ro\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "add-cdrom filename",
  .run = run_add_cdrom
};

struct command_entry aug_init_cmd_entry = {
  .name = "aug-init",
  .help = "NAME\n"
          "    aug-init - create a new Augeas handle\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-init root flags\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a new Augeas handle for editing configuration files. If there was\n"
          "    any previous Augeas handle associated with this guestfs session, then it\n"
          "    is closed.\n"
          "\n"
          "    You must call this before using any other \"aug_*\" commands.\n"
          "\n"
          "    \"root\" is the filesystem root. \"root\" must not be NULL, use / instead.\n"
          "\n"
          "    The flags are the same as the flags defined in <augeas.h>, the logical\n"
          "    *or* of the following integers:\n"
          "\n"
          "    \"AUG_SAVE_BACKUP\" = 1\n"
          "        Keep the original file with a \".augsave\" extension.\n"
          "\n"
          "    \"AUG_SAVE_NEWFILE\" = 2\n"
          "        Save changes into a file with extension \".augnew\", and do not\n"
          "        overwrite original. Overrides \"AUG_SAVE_BACKUP\".\n"
          "\n"
          "    \"AUG_TYPE_CHECK\" = 4\n"
          "        Typecheck lenses.\n"
          "\n"
          "        This option is only useful when debugging Augeas lenses. Use of this\n"
          "        option may require additional memory for the libguestfs appliance.\n"
          "        You may need to set the \"LIBGUESTFS_MEMSIZE\" environment variable or\n"
          "        call \"set_memsize\".\n"
          "\n"
          "    \"AUG_NO_STDINC\" = 8\n"
          "        Do not use standard load path for modules.\n"
          "\n"
          "    \"AUG_SAVE_NOOP\" = 16\n"
          "        Make save a no-op, just record what would have been changed.\n"
          "\n"
          "    \"AUG_NO_LOAD\" = 32\n"
          "        Do not load the tree in \"aug_init\".\n"
          "\n"
          "    To close the handle, you can call \"aug_close\".\n"
          "\n"
          "    To find out more about Augeas, see <http://augeas.net/>.\n"
          "\n"
          "",
  .synopsis = "aug-init root flags",
  .run = run_aug_init
};

struct command_entry aug_insert_cmd_entry = {
  .name = "aug-insert",
  .help = "NAME\n"
          "    aug-insert - insert a sibling Augeas node\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-insert augpath label before\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a new sibling \"label\" for \"path\", inserting it into the tree\n"
          "    before or after \"path\" (depending on the boolean flag \"before\").\n"
          "\n"
          "    \"path\" must match exactly one existing node in the tree, and \"label\"\n"
          "    must be a label, ie. not contain /, \"*\" or end with a bracketed index\n"
          "    \"[N]\".\n"
          "\n"
          "",
  .synopsis = "aug-insert augpath label before",
  .run = run_aug_insert
};

struct command_entry aug_load_cmd_entry = {
  .name = "aug-load",
  .help = "NAME\n"
          "    aug-load - load files into the tree\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-load\n"
          "\n"
          "DESCRIPTION\n"
          "    Load files into the tree.\n"
          "\n"
          "    See \"aug_load\" in the Augeas documentation for the full gory details.\n"
          "\n"
          "",
  .synopsis = "aug-load",
  .run = run_aug_load
};

struct command_entry aug_rm_cmd_entry = {
  .name = "aug-rm",
  .help = "NAME\n"
          "    aug-rm - remove an Augeas path\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-rm augpath\n"
          "\n"
          "DESCRIPTION\n"
          "    Remove \"path\" and all of its children.\n"
          "\n"
          "    On success this returns the number of entries which were removed.\n"
          "\n"
          "",
  .synopsis = "aug-rm augpath",
  .run = run_aug_rm
};

struct command_entry aug_set_cmd_entry = {
  .name = "aug-set",
  .help = "NAME\n"
          "    aug-set - set Augeas path to value\n"
          "\n"
          "SYNOPSIS\n"
          "     aug-set augpath val\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the value associated with \"path\" to \"val\".\n"
          "\n"
          "    In the Augeas API, it is possible to clear a node by setting the value\n"
          "    to NULL. Due to an oversight in the libguestfs API you cannot do that\n"
          "    with this call. Instead you must use the \"aug_clear\" call.\n"
          "\n"
          "",
  .synopsis = "aug-set augpath val",
  .run = run_aug_set
};

struct command_entry blkid_cmd_entry = {
  .name = "blkid",
  .help = "NAME\n"
          "    blkid - print block device attributes\n"
          "\n"
          "SYNOPSIS\n"
          "     blkid device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns block device attributes for \"device\". The following\n"
          "    fields are usually present in the returned hash. Other fields may also\n"
          "    be present.\n"
          "\n"
          "    \"UUID\"\n"
          "        The uuid of this device.\n"
          "\n"
          "    \"LABEL\"\n"
          "        The label of this device.\n"
          "\n"
          "    \"VERSION\"\n"
          "        The version of blkid command.\n"
          "\n"
          "    \"TYPE\"\n"
          "        The filesystem type or RAID of this device.\n"
          "\n"
          "    \"USAGE\"\n"
          "        The usage of this device, for example \"filesystem\" or \"raid\".\n"
          "\n"
          "",
  .synopsis = "blkid device",
  .run = run_blkid
};

struct command_entry blockdev_setra_cmd_entry = {
  .name = "blockdev-setra",
  .help = "NAME\n"
          "    blockdev-setra - set readahead\n"
          "\n"
          "SYNOPSIS\n"
          "     blockdev-setra device sectors\n"
          "\n"
          "DESCRIPTION\n"
          "    Set readahead (in 512-byte sectors) for the device.\n"
          "\n"
          "    This uses the blockdev(8) command.\n"
          "\n"
          "",
  .synopsis = "blockdev-setra device sectors",
  .run = run_blockdev_setra
};

struct command_entry btrfs_scrub_start_cmd_entry = {
  .name = "btrfs-scrub-start",
  .help = "NAME\n"
          "    btrfs-scrub-start - read all data from all disks and verify checksums\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-scrub-start path\n"
          "\n"
          "DESCRIPTION\n"
          "    Reads all the data and metadata on the filesystem, and uses checksums\n"
          "    and the duplicate copies from RAID storage to identify and repair any\n"
          "    corrupt data.\n"
          "\n"
          "",
  .synopsis = "btrfs-scrub-start path",
  .run = run_btrfs_scrub_start
};

struct command_entry btrfs_scrub_status_cmd_entry = {
  .name = "btrfs-scrub-status",
  .help = "NAME\n"
          "    btrfs-scrub-status - show status of running or finished scrub\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-scrub-status path\n"
          "\n"
          "DESCRIPTION\n"
          "    Show status of running or finished scrub on a btrfs filesystem.\n"
          "\n"
          "",
  .synopsis = "btrfs-scrub-status path",
  .run = run_btrfs_scrub_status
};

struct command_entry btrfs_subvolume_create_cmd_entry = {
  .name = "btrfs-subvolume-create",
  .help = "NAME\n"
          "    btrfs-subvolume-create - create a btrfs subvolume\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-create dest [qgroupid:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a btrfs subvolume. The \"dest\" argument is the destination\n"
          "    directory and the name of the subvolume, in the form /path/to/dest/name.\n"
          "    The optional parameter \"qgroupid\" represents the qgroup which the newly\n"
          "    created subvolume will be added to.\n"
          "\n"
          "    You can use 'btrfs-subvolume-create-opts' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-create dest [qgroupid:..]",
  .run = run_btrfs_subvolume_create
};

struct command_entry btrfs_subvolume_set_default_cmd_entry = {
  .name = "btrfs-subvolume-set-default",
  .help = "NAME\n"
          "    btrfs-subvolume-set-default - set default btrfs subvolume\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-set-default id fs\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the subvolume of the btrfs filesystem \"fs\" which will be mounted by\n"
          "    default. See \"btrfs_subvolume_list\" to get a list of subvolumes.\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-set-default id fs",
  .run = run_btrfs_subvolume_set_default
};

struct command_entry btrfs_subvolume_snapshot_cmd_entry = {
  .name = "btrfs-subvolume-snapshot",
  .help = "NAME\n"
          "    btrfs-subvolume-snapshot - create a btrfs snapshot\n"
          "\n"
          "SYNOPSIS\n"
          "     btrfs-subvolume-snapshot source dest [ro:true|false] [qgroupid:..]\n"
          "\n"
          "DESCRIPTION\n"
          "    Create a snapshot of the btrfs subvolume \"source\". The \"dest\" argument\n"
          "    is the destination directory and the name of the snapshot, in the form\n"
          "    /path/to/dest/name. By default the newly created snapshot is writable,\n"
          "    if the value of optional parameter \"ro\" is true, then a readonly\n"
          "    snapshot is created. The optional parameter \"qgroupid\" represents the\n"
          "    qgroup which the newly created snapshot will be added to.\n"
          "\n"
          "    You can use 'btrfs-subvolume-snapshot-opts' as an alias for this\n"
          "    command.\n"
          "\n"
          "",
  .synopsis = "btrfs-subvolume-snapshot source dest [ro:true|false] [qgroupid:..]",
  .run = run_btrfs_subvolume_snapshot
};

struct command_entry canonical_device_name_cmd_entry = {
  .name = "canonical-device-name",
  .help = "NAME\n"
          "    canonical-device-name - return canonical device name\n"
          "\n"
          "SYNOPSIS\n"
          "     canonical-device-name device\n"
          "\n"
          "DESCRIPTION\n"
          "    This utility function is useful when displaying device names to the\n"
          "    user. It takes a number of irregular device names and returns them in a\n"
          "    consistent format:\n"
          "\n"
          "    /dev/hdX\n"
          "    /dev/vdX\n"
          "        These are returned as /dev/sdX. Note this works for device names and\n"
          "        partition names. This is approximately the reverse of the algorithm\n"
          "        described in \"BLOCK DEVICE NAMING\" in guestfs(3).\n"
          "\n"
          "    /dev/mapper/VG-LV\n"
          "    /dev/dm-N\n"
          "        Converted to /dev/VG/LV form using \"lvm_canonical_lv_name\".\n"
          "\n"
          "    Other strings are returned unmodified.\n"
          "\n"
          "",
  .synopsis = "canonical-device-name device",
  .run = run_canonical_device_name
};

struct command_entry case_sensitive_path_cmd_entry = {
  .name = "case-sensitive-path",
  .help = "NAME\n"
          "    case-sensitive-path - return true path on case-insensitive filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     case-sensitive-path path\n"
          "\n"
          "DESCRIPTION\n"
          "    This can be used to resolve case insensitive paths on a filesystem which\n"
          "    is case sensitive. The use case is to resolve paths which you have read\n"
          "    from Windows configuration files or the Windows Registry, to the true\n"
          "    path.\n"
          "\n"
          "    The command handles a peculiarity of the Linux ntfs-3g filesystem driver\n"
          "    (and probably others), which is that although the underlying filesystem\n"
          "    is case-insensitive, the driver exports the filesystem to Linux as\n"
          "    case-sensitive.\n"
          "\n"
          "    One consequence of this is that special directories such as C:\\windows\n"
          "    may appear as /WINDOWS or /windows (or other things) depending on the\n"
          "    precise details of how they were created. In Windows itself this would\n"
          "    not be a problem.\n"
          "\n"
          "    Bug or feature? You decide:\n"
          "    <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1>\n"
          "\n"
          "    \"case_sensitive_path\" attempts to resolve the true case of each element\n"
          "    in the path. It will return a resolved path if either the full path or\n"
          "    its parent directory exists. If the parent directory exists but the full\n"
          "    path does not, the case of the parent directory will be correctly\n"
          "    resolved, and the remainder appended unmodified. For example, if the\n"
          "    file \"/Windows/System32/netkvm.sys\" exists:\n"
          "\n"
          "    \"case_sensitive_path\" (\"/windows/system32/netkvm.sys\")\n"
          "        \"Windows/System32/netkvm.sys\"\n"
          "\n"
          "    \"case_sensitive_path\" (\"/windows/system32/NoSuchFile\")\n"
          "        \"Windows/System32/NoSuchFile\"\n"
          "\n"
          "    \"case_sensitive_path\" (\"/windows/system33/netkvm.sys\")\n"
          "        *ERROR*\n"
          "\n"
          "    *Note*: Because of the above behaviour, \"case_sensitive_path\" cannot be\n"
          "    used to check for the existence of a file.\n"
          "\n"
          "    *Note*: This function does not handle drive names, backslashes etc.\n"
          "\n"
          "    See also \"realpath\".\n"
          "\n"
          "",
  .synopsis = "case-sensitive-path path",
  .run = run_case_sensitive_path
};

struct command_entry copy_size_cmd_entry = {
  .name = "copy-size",
  .help = "NAME\n"
          "    copy-size - copy size bytes from source to destination using dd\n"
          "\n"
          "SYNOPSIS\n"
          "     copy-size src dest size\n"
          "\n"
          "DESCRIPTION\n"
          "    This command copies exactly \"size\" bytes from one source device or file\n"
          "    \"src\" to another destination device or file \"dest\".\n"
          "\n"
          "    Note this will fail if the source is too short or if the destination is\n"
          "    not large enough.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the\n"
          "    \"copy-device-to-device\" call instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "copy-size src dest size",
  .run = run_copy_size
};

struct command_entry debug_upload_cmd_entry = {
  .name = "debug-upload",
  .help = "NAME\n"
          "    debug-upload - upload a file to the appliance (internal use only)\n"
          "\n"
          "SYNOPSIS\n"
          "     debug-upload filename tmpname mode\n"
          "\n"
          "DESCRIPTION\n"
          "    The \"debug_upload\" command uploads a file to the libguestfs appliance.\n"
          "\n"
          "    There is no comprehensive help for this command. You have to look at the\n"
          "    file daemon/debug.c in the libguestfs source to find out what it is for.\n"
          "\n"
          "",
  .synopsis = "debug-upload filename tmpname mode",
  .run = run_debug_upload
};

struct command_entry download_offset_cmd_entry = {
  .name = "download-offset",
  .help = "NAME\n"
          "    download-offset - download a file to the local machine with offset and\n"
          "    size\n"
          "\n"
          "SYNOPSIS\n"
          "     download-offset remotefilename filename offset size\n"
          "\n"
          "DESCRIPTION\n"
          "    Download file remotefilename and save it as filename on the local\n"
          "    machine.\n"
          "\n"
          "    remotefilename is read for \"size\" bytes starting at \"offset\" (this\n"
          "    region must be within the file or device).\n"
          "\n"
          "    Note that there is no limit on the amount of data that can be downloaded\n"
          "    with this call, unlike with \"pread\", and this call always reads the full\n"
          "    amount unless an error occurs.\n"
          "\n"
          "    See also \"download\", \"pread\".\n"
          "\n"
          "",
  .synopsis = "download-offset remotefilename filename offset size",
  .run = run_download_offset
};

struct command_entry findfs_uuid_cmd_entry = {
  .name = "findfs-uuid",
  .help = "NAME\n"
          "    findfs-uuid - find a filesystem by UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     findfs-uuid uuid\n"
          "\n"
          "DESCRIPTION\n"
          "    This command searches the filesystems and returns the one which has the\n"
          "    given UUID. An error is returned if no such filesystem can be found.\n"
          "\n"
          "    To find the UUID of a filesystem, use \"vfs_uuid\".\n"
          "\n"
          "",
  .synopsis = "findfs-uuid uuid",
  .run = run_findfs_uuid
};

struct command_entry fstrim_cmd_entry = {
  .name = "fstrim",
  .help = "NAME\n"
          "    fstrim - trim free space in a filesystem\n"
          "\n"
          "SYNOPSIS\n"
          "     fstrim mountpoint [offset:N] [length:N] [minimumfreeextent:N]\n"
          "\n"
          "DESCRIPTION\n"
          "    Trim the free space in the filesystem mounted on \"mountpoint\". The\n"
          "    filesystem must be mounted read-write.\n"
          "\n"
          "    The filesystem contents are not affected, but any free space in the\n"
          "    filesystem is \"trimmed\", that is, given back to the host device, thus\n"
          "    making disk images more sparse, allowing unused space in qcow2 files to\n"
          "    be reused, etc.\n"
          "\n"
          "    This operation requires support in libguestfs, the mounted filesystem,\n"
          "    the host filesystem, qemu and the host kernel. If this support isn't\n"
          "    present it may give an error or even appear to run but do nothing.\n"
          "\n"
          "    In the case where the kernel vfs driver does not support trimming, this\n"
          "    call will fail with errno set to \"ENOTSUP\". Currently this happens when\n"
          "    trying to trim FAT filesystems.\n"
          "\n"
          "    See also \"zero_free_space\". That is a slightly different operation that\n"
          "    turns free space in the filesystem into zeroes. It is valid to call\n"
          "    \"fstrim\" either instead of, or after calling \"zero_free_space\".\n"
          "\n"
          "",
  .synopsis = "fstrim mountpoint [offset:N] [length:N] [minimumfreeextent:N]",
  .run = run_fstrim
};

struct command_entry get_autosync_cmd_entry = {
  .name = "get-autosync",
  .help = "NAME\n"
          "    get-autosync - get autosync mode\n"
          "\n"
          "SYNOPSIS\n"
          "     get-autosync\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the autosync flag.\n"
          "\n"
          "",
  .synopsis = "get-autosync",
  .run = run_get_autosync
};

struct command_entry get_e2uuid_cmd_entry = {
  .name = "get-e2uuid",
  .help = "NAME\n"
          "    get-e2uuid - get the ext2/3/4 filesystem UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     get-e2uuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the ext2/3/4 filesystem UUID of the filesystem on \"device\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"vfs-uuid\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "get-e2uuid device",
  .run = run_get_e2uuid
};

struct command_entry get_libvirt_requested_credential_challenge_cmd_entry = {
  .name = "get-libvirt-requested-credential-challenge",
  .help = "NAME\n"
          "    get-libvirt-requested-credential-challenge - challenge of i'th requested\n"
          "    credential\n"
          "\n"
          "SYNOPSIS\n"
          "     get-libvirt-requested-credential-challenge index\n"
          "\n"
          "DESCRIPTION\n"
          "    Get the challenge (provided by libvirt) for the \"index\"'th requested\n"
          "    credential. If libvirt did not provide a challenge, this returns the\n"
          "    empty string \"\".\n"
          "\n"
          "    See \"LIBVIRT AUTHENTICATION\" in guestfs(3) for documentation and example\n"
          "    code.\n"
          "\n"
          "",
  .synopsis = "get-libvirt-requested-credential-challenge index",
  .run = run_get_libvirt_requested_credential_challenge
};

struct command_entry get_pid_cmd_entry = {
  .name = "get-pid",
  .help = "NAME\n"
          "    get-pid - get PID of hypervisor\n"
          "\n"
          "SYNOPSIS\n"
          "     get-pid\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the process ID of the hypervisor. If there is no hypervisor\n"
          "    running, then this will return an error.\n"
          "\n"
          "    This is an internal call used for debugging and testing.\n"
          "\n"
          "    You can use 'pid' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "get-pid",
  .run = run_get_pid
};

struct command_entry get_selinux_cmd_entry = {
  .name = "get-selinux",
  .help = "NAME\n"
          "    get-selinux - get SELinux enabled flag\n"
          "\n"
          "SYNOPSIS\n"
          "     get-selinux\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the current setting of the selinux flag which is passed to\n"
          "    the appliance at boot time. See \"set_selinux\".\n"
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
          "",
  .synopsis = "get-selinux",
  .run = run_get_selinux
};

struct command_entry grepi_cmd_entry = {
  .name = "grepi",
  .help = "NAME\n"
          "    grepi - return lines matching a pattern\n"
          "\n"
          "SYNOPSIS\n"
          "     grepi regex path\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls the external \"grep -i\" program and returns the matching\n"
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
  .synopsis = "grepi regex path",
  .run = run_grepi
};

struct command_entry hexdump_cmd_entry = {
  .name = "hexdump",
  .help = "NAME\n"
          "    hexdump - dump a file in hexadecimal\n"
          "\n"
          "SYNOPSIS\n"
          "     hexdump path\n"
          "\n"
          "DESCRIPTION\n"
          "    This runs \"hexdump -C\" on the given \"path\". The result is the\n"
          "    human-readable, canonical hex dump of the file.\n"
          "\n"
          "    Because of the message protocol, there is a transfer limit of somewhere\n"
          "    between 2MB and 4MB. See \"PROTOCOL LIMITS\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = "hexdump path",
  .run = run_hexdump
};

struct command_entry hivex_node_children_cmd_entry = {
  .name = "hivex-node-children",
  .help = "NAME\n"
          "    hivex-node-children - return list of nodes which are subkeys of node\n"
          "\n"
          "SYNOPSIS\n"
          "     hivex-node-children nodeh\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the list of nodes which are subkeys of \"nodeh\".\n"
          "\n"
          "    This is a wrapper around the hivex(3) call of the same name.\n"
          "\n"
          "",
  .synopsis = "hivex-node-children nodeh",
  .run = run_hivex_node_children
};

struct command_entry inspect_get_format_cmd_entry = {
  .name = "inspect-get-format",
  .help = "NAME\n"
          "    inspect-get-format - get format of inspected operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-format root\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the format of the inspected operating system. You can use\n"
          "    it to detect install images, live CDs and similar.\n"
          "\n"
          "    Currently defined formats are:\n"
          "\n"
          "    \"installed\"\n"
          "        This is an installed operating system.\n"
          "\n"
          "    \"installer\"\n"
          "        The disk image being inspected is not an installed operating system,\n"
          "        but a *bootable* install disk, live CD, or similar.\n"
          "\n"
          "    \"unknown\"\n"
          "        The format of this disk image is not known.\n"
          "\n"
          "    Future versions of libguestfs may return other strings here. The caller\n"
          "    should be prepared to handle any string.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-format root",
  .run = run_inspect_get_format
};

struct command_entry inspect_get_hostname_cmd_entry = {
  .name = "inspect-get-hostname",
  .help = "NAME\n"
          "    inspect-get-hostname - get hostname of the operating system\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-get-hostname root\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns the hostname of the operating system as found by\n"
          "    inspection of the guest's configuration files.\n"
          "\n"
          "    If the hostname could not be determined, then the string \"unknown\" is\n"
          "    returned.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-get-hostname root",
  .run = run_inspect_get_hostname
};

struct command_entry inspect_is_multipart_cmd_entry = {
  .name = "inspect-is-multipart",
  .help = "NAME\n"
          "    inspect-is-multipart - get multipart flag for install disk\n"
          "\n"
          "SYNOPSIS\n"
          "     inspect-is-multipart root\n"
          "\n"
          "DESCRIPTION\n"
          "    If \"inspect_get_format\" returns \"installer\" (this is an install disk),\n"
          "    then this returns true if the disk is part of a set.\n"
          "\n"
          "    Please read \"INSPECTION\" in guestfs(3) for more details.\n"
          "\n"
          "",
  .synopsis = "inspect-is-multipart root",
  .run = run_inspect_is_multipart
};

struct command_entry ldmtool_scan_cmd_entry = {
  .name = "ldmtool-scan",
  .help = "NAME\n"
          "    ldmtool-scan - scan for Windows dynamic disks\n"
          "\n"
          "SYNOPSIS\n"
          "     ldmtool-scan\n"
          "\n"
          "DESCRIPTION\n"
          "    This function scans for Windows dynamic disks. It returns a list of\n"
          "    identifiers (GUIDs) for all disk groups that were found. These\n"
          "    identifiers can be passed to other \"ldmtool_*\" functions.\n"
          "\n"
          "    This function scans all block devices. To scan a subset of block\n"
          "    devices, call \"ldmtool_scan_devices\" instead.\n"
          "\n"
          "",
  .synopsis = "ldmtool-scan",
  .run = run_ldmtool_scan
};

struct command_entry lgetxattrs_cmd_entry = {
  .name = "lgetxattrs",
  .help = "NAME\n"
          "    lgetxattrs - list extended attributes of a file or directory\n"
          "\n"
          "SYNOPSIS\n"
          "     lgetxattrs path\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"getxattrs\", but if \"path\" is a symbolic link, then\n"
          "    it returns the extended attributes of the link itself.\n"
          "\n"
          "",
  .synopsis = "lgetxattrs path",
  .run = run_lgetxattrs
};

struct command_entry list_dm_devices_cmd_entry = {
  .name = "list-dm-devices",
  .help = "NAME\n"
          "    list-dm-devices - list device mapper devices\n"
          "\n"
          "SYNOPSIS\n"
          "     list-dm-devices\n"
          "\n"
          "DESCRIPTION\n"
          "    List all device mapper devices.\n"
          "\n"
          "    The returned list contains /dev/mapper/* devices, eg. ones created by a\n"
          "    previous call to \"luks_open\".\n"
          "\n"
          "    Device mapper devices which correspond to logical volumes are *not*\n"
          "    returned in this list. Call \"lvs\" if you want to list logical volumes.\n"
          "\n"
          "",
  .synopsis = "list-dm-devices",
  .run = run_list_dm_devices
};

struct command_entry list_ldm_volumes_cmd_entry = {
  .name = "list-ldm-volumes",
  .help = "NAME\n"
          "    list-ldm-volumes - list all Windows dynamic disk volumes\n"
          "\n"
          "SYNOPSIS\n"
          "     list-ldm-volumes\n"
          "\n"
          "DESCRIPTION\n"
          "    This function returns all Windows dynamic disk volumes that were found\n"
          "    at launch time. It returns a list of device names.\n"
          "\n"
          "",
  .synopsis = "list-ldm-volumes",
  .run = run_list_ldm_volumes
};

struct command_entry luks_format_cmd_entry = {
  .name = "luks-format",
  .help = "NAME\n"
          "    luks-format - format a block device as a LUKS encrypted device\n"
          "\n"
          "SYNOPSIS\n"
          "     luks-format device keyslot\n"
          "\n"
          "DESCRIPTION\n"
          "    This command erases existing data on \"device\" and formats the device as\n"
          "    a LUKS encrypted device. \"key\" is the initial key, which is added to key\n"
          "    slot \"slot\". (LUKS supports 8 key slots, numbered 0-7).\n"
          "\n"
          "    This command has one or more key or passphrase parameters. Guestfish\n"
          "    will prompt for these separately.\n"
          "\n"
          "",
  .synopsis = "luks-format device keyslot",
  .run = run_luks_format
};

struct command_entry lvm_canonical_lv_name_cmd_entry = {
  .name = "lvm-canonical-lv-name",
  .help = "NAME\n"
          "    lvm-canonical-lv-name - get canonical name of an LV\n"
          "\n"
          "SYNOPSIS\n"
          "     lvm-canonical-lv-name lvname\n"
          "\n"
          "DESCRIPTION\n"
          "    This converts alternative naming schemes for LVs that you might find to\n"
          "    the canonical name. For example, /dev/mapper/VG-LV is converted to\n"
          "    /dev/VG/LV.\n"
          "\n"
          "    This command returns an error if the \"lvname\" parameter does not refer\n"
          "    to a logical volume.\n"
          "\n"
          "    See also \"is_lv\", \"canonical_device_name\".\n"
          "\n"
          "",
  .synopsis = "lvm-canonical-lv-name lvname",
  .run = run_lvm_canonical_lv_name
};

struct command_entry lvrename_cmd_entry = {
  .name = "lvrename",
  .help = "NAME\n"
          "    lvrename - rename an LVM logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     lvrename logvol newlogvol\n"
          "\n"
          "DESCRIPTION\n"
          "    Rename a logical volume \"logvol\" with the new name \"newlogvol\".\n"
          "\n"
          "",
  .synopsis = "lvrename logvol newlogvol",
  .run = run_lvrename
};

struct command_entry lvresize_cmd_entry = {
  .name = "lvresize",
  .help = "NAME\n"
          "    lvresize - resize an LVM logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     lvresize device mbytes\n"
          "\n"
          "DESCRIPTION\n"
          "    This resizes (expands or shrinks) an existing LVM logical volume to\n"
          "    \"mbytes\". When reducing, data in the reduced part is lost.\n"
          "\n"
          "",
  .synopsis = "lvresize device mbytes",
  .run = run_lvresize
};

struct command_entry lvuuid_cmd_entry = {
  .name = "lvuuid",
  .help = "NAME\n"
          "    lvuuid - get the UUID of a logical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     lvuuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns the UUID of the LVM LV \"device\".\n"
          "\n"
          "",
  .synopsis = "lvuuid device",
  .run = run_lvuuid
};

struct command_entry mke2fs_J_cmd_entry = {
  .name = "mke2fs-J",
  .help = "NAME\n"
          "    mke2fs-J - make ext2/3/4 filesystem with external journal\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2fs-J fstype blocksize device journal\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2/3/4 filesystem on \"device\" with an external journal\n"
          "    on \"journal\". It is equivalent to the command:\n"
          "\n"
          "     mke2fs -t fstype -b blocksize -J device=<journal> <device>\n"
          "\n"
          "    See also \"mke2journal\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2fs-J fstype blocksize device journal",
  .run = run_mke2fs_J
};

struct command_entry mke2journal_U_cmd_entry = {
  .name = "mke2journal-U",
  .help = "NAME\n"
          "    mke2journal-U - make ext2/3/4 external journal with UUID\n"
          "\n"
          "SYNOPSIS\n"
          "     mke2journal-U blocksize uuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an ext2 external journal on \"device\" with UUID \"uuid\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"mke2fs\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "mke2journal-U blocksize uuid device",
  .run = run_mke2journal_U
};

struct command_entry mknod_c_cmd_entry = {
  .name = "mknod-c",
  .help = "NAME\n"
          "    mknod-c - make char device node\n"
          "\n"
          "SYNOPSIS\n"
          "     mknod-c mode devmajor devminor path\n"
          "\n"
          "DESCRIPTION\n"
          "    This call creates a char device node called \"path\" with mode \"mode\" and\n"
          "    device major/minor \"devmajor\" and \"devminor\". It is just a convenient\n"
          "    wrapper around \"mknod\".\n"
          "\n"
          "    Unlike with \"mknod\", \"mode\" must contain only permissions bits.\n"
          "\n"
          "    The mode actually set is affected by the umask.\n"
          "\n"
          "",
  .synopsis = "mknod-c mode devmajor devminor path",
  .run = run_mknod_c
};

struct command_entry mount_options_cmd_entry = {
  .name = "mount-options",
  .help = "NAME\n"
          "    mount-options - mount a guest disk with mount options\n"
          "\n"
          "SYNOPSIS\n"
          "     mount-options options mountable mountpoint\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as the \"mount\" command, but it allows you to set the\n"
          "    mount options as for the mount(8) *-o* flag.\n"
          "\n"
          "    If the \"options\" parameter is an empty string, then no options are\n"
          "    passed (all options default to whatever the filesystem uses).\n"
          "\n"
          "",
  .synopsis = "mount-options options mountable mountpoint",
  .run = run_mount_options
};

struct command_entry ntfsfix_cmd_entry = {
  .name = "ntfsfix",
  .help = "NAME\n"
          "    ntfsfix - fix common errors and force Windows to check NTFS\n"
          "\n"
          "SYNOPSIS\n"
          "     ntfsfix device [clearbadsectors:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This command repairs some fundamental NTFS inconsistencies, resets the\n"
          "    NTFS journal file, and schedules an NTFS consistency check for the first\n"
          "    boot into Windows.\n"
          "\n"
          "    This is *not* an equivalent of Windows \"chkdsk\". It does *not* scan the\n"
          "    filesystem for inconsistencies.\n"
          "\n"
          "    The optional \"clearbadsectors\" flag clears the list of bad sectors. This\n"
          "    is useful after cloning a disk with bad sectors to a new disk.\n"
          "\n"
          "",
  .synopsis = "ntfsfix device [clearbadsectors:true|false]",
  .run = run_ntfsfix
};

struct command_entry part_add_cmd_entry = {
  .name = "part-add",
  .help = "NAME\n"
          "    part-add - add a partition to the device\n"
          "\n"
          "SYNOPSIS\n"
          "     part-add device prlogex startsect endsect\n"
          "\n"
          "DESCRIPTION\n"
          "    This command adds a partition to \"device\". If there is no partition\n"
          "    table on the device, call \"part_init\" first.\n"
          "\n"
          "    The \"prlogex\" parameter is the type of partition. Normally you should\n"
          "    pass \"p\" or \"primary\" here, but MBR partition tables also support \"l\"\n"
          "    (or \"logical\") and \"e\" (or \"extended\") partition types.\n"
          "\n"
          "    \"startsect\" and \"endsect\" are the start and end of the partition in\n"
          "    *sectors*. \"endsect\" may be negative, which means it counts backwards\n"
          "    from the end of the disk (-1 is the last sector).\n"
          "\n"
          "    Creating a partition which covers the whole disk is not so easy. Use\n"
          "    \"part_disk\" to do that.\n"
          "\n"
          "",
  .synopsis = "part-add device prlogex startsect endsect",
  .run = run_part_add
};

struct command_entry part_get_gpt_guid_cmd_entry = {
  .name = "part-get-gpt-guid",
  .help = "NAME\n"
          "    part-get-gpt-guid - get the GUID of a GPT partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-gpt-guid device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    Return the GUID of numbered GPT partition \"partnum\".\n"
          "\n"
          "",
  .synopsis = "part-get-gpt-guid device partnum",
  .run = run_part_get_gpt_guid
};

struct command_entry part_get_mbr_id_cmd_entry = {
  .name = "part-get-mbr-id",
  .help = "NAME\n"
          "    part-get-mbr-id - get the MBR type byte (ID byte) from a partition\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-mbr-id device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    Returns the MBR type byte (also known as the ID byte) from the numbered\n"
          "    partition \"partnum\".\n"
          "\n"
          "    Note that only MBR (old DOS-style) partitions have type bytes. You will\n"
          "    get undefined results for other partition table types (see\n"
          "    \"part_get_parttype\").\n"
          "\n"
          "",
  .synopsis = "part-get-mbr-id device partnum",
  .run = run_part_get_mbr_id
};

struct command_entry part_get_mbr_part_type_cmd_entry = {
  .name = "part-get-mbr-part-type",
  .help = "NAME\n"
          "    part-get-mbr-part-type - get the MBR partition type\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-mbr-part-type device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    This returns the partition type of an MBR partition numbered \"partnum\"\n"
          "    on device \"device\".\n"
          "\n"
          "    It returns \"primary\", \"logical\", or \"extended\".\n"
          "\n"
          "",
  .synopsis = "part-get-mbr-part-type device partnum",
  .run = run_part_get_mbr_part_type
};

struct command_entry part_get_name_cmd_entry = {
  .name = "part-get-name",
  .help = "NAME\n"
          "    part-get-name - get partition name\n"
          "\n"
          "SYNOPSIS\n"
          "     part-get-name device partnum\n"
          "\n"
          "DESCRIPTION\n"
          "    This gets the partition name on partition numbered \"partnum\" on device\n"
          "    \"device\". Note that partitions are numbered from 1.\n"
          "\n"
          "    The partition name can only be read on certain types of partition table.\n"
          "    This works on \"gpt\" but not on \"mbr\" partitions.\n"
          "\n"
          "",
  .synopsis = "part-get-name device partnum",
  .run = run_part_get_name
};

struct command_entry part_init_cmd_entry = {
  .name = "part-init",
  .help = "NAME\n"
          "    part-init - create an empty partition table\n"
          "\n"
          "SYNOPSIS\n"
          "     part-init device parttype\n"
          "\n"
          "DESCRIPTION\n"
          "    This creates an empty partition table on \"device\" of one of the\n"
          "    partition types listed below. Usually \"parttype\" should be either\n"
          "    \"msdos\" or \"gpt\" (for large disks).\n"
          "\n"
          "    Initially there are no partitions. Following this, you should call\n"
          "    \"part_add\" for each partition required.\n"
          "\n"
          "    Possible values for \"parttype\" are:\n"
          "\n"
          "    efi\n"
          "    gpt Intel EFI / GPT partition table.\n"
          "\n"
          "        This is recommended for >= 2 TB partitions that will be accessed\n"
          "        from Linux and Intel-based Mac OS X. It also has limited backwards\n"
          "        compatibility with the \"mbr\" format.\n"
          "\n"
          "    mbr\n"
          "    msdos\n"
          "        The standard PC \"Master Boot Record\" (MBR) format used by MS-DOS and\n"
          "        Windows. This partition type will only work for device sizes up to 2\n"
          "        TB. For large disks we recommend using \"gpt\".\n"
          "\n"
          "    Other partition table types that may work but are not supported include:\n"
          "\n"
          "    aix AIX disk labels.\n"
          "\n"
          "    amiga\n"
          "    rdb Amiga \"Rigid Disk Block\" format.\n"
          "\n"
          "    bsd BSD disk labels.\n"
          "\n"
          "    dasd\n"
          "        DASD, used on IBM mainframes.\n"
          "\n"
          "    dvh MIPS/SGI volumes.\n"
          "\n"
          "    mac Old Mac partition format. Modern Macs use \"gpt\".\n"
          "\n"
          "    pc98\n"
          "        NEC PC-98 format, common in Japan apparently.\n"
          "\n"
          "    sun Sun disk labels.\n"
          "\n"
          "",
  .synopsis = "part-init device parttype",
  .run = run_part_init
};

struct command_entry part_to_partnum_cmd_entry = {
  .name = "part-to-partnum",
  .help = "NAME\n"
          "    part-to-partnum - convert partition name to partition number\n"
          "\n"
          "SYNOPSIS\n"
          "     part-to-partnum partition\n"
          "\n"
          "DESCRIPTION\n"
          "    This function takes a partition name (eg. \"/dev/sdb1\") and returns the\n"
          "    partition number (eg. 1).\n"
          "\n"
          "    The named partition must exist, for example as a string returned from\n"
          "    \"list_partitions\".\n"
          "\n"
          "    See also \"part_to_dev\".\n"
          "\n"
          "",
  .synopsis = "part-to-partnum partition",
  .run = run_part_to_partnum
};

struct command_entry pvuuid_cmd_entry = {
  .name = "pvuuid",
  .help = "NAME\n"
          "    pvuuid - get the UUID of a physical volume\n"
          "\n"
          "SYNOPSIS\n"
          "     pvuuid device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command returns the UUID of the LVM PV \"device\".\n"
          "\n"
          "",
  .synopsis = "pvuuid device",
  .run = run_pvuuid
};

struct command_entry readlinklist_cmd_entry = {
  .name = "readlinklist",
  .help = "NAME\n"
          "    readlinklist - readlink on multiple files\n"
          "\n"
          "SYNOPSIS\n"
          "     readlinklist path names\n"
          "\n"
          "DESCRIPTION\n"
          "    This call allows you to do a \"readlink\" operation on multiple files,\n"
          "    where all files are in the directory \"path\". \"names\" is the list of\n"
          "    files from this directory.\n"
          "\n"
          "    On return you get a list of strings, with a one-to-one correspondence to\n"
          "    the \"names\" list. Each string is the value of the symbolic link.\n"
          "\n"
          "    If the readlink(2) operation fails on any name, then the corresponding\n"
          "    result string is the empty string \"\". However the whole operation is\n"
          "    completed even if there were readlink(2) errors, and so you can call\n"
          "    this function with names where you don't know if they are symbolic links\n"
          "    already (albeit slightly less efficient).\n"
          "\n"
          "    This call is intended for programs that want to efficiently list a\n"
          "    directory contents without making many round-trips.\n"
          "\n"
          "",
  .synopsis = "readlinklist path names",
  .run = run_readlinklist
};

struct command_entry rmmountpoint_cmd_entry = {
  .name = "rmmountpoint",
  .help = "NAME\n"
          "    rmmountpoint - remove a mountpoint\n"
          "\n"
          "SYNOPSIS\n"
          "     rmmountpoint exemptpath\n"
          "\n"
          "DESCRIPTION\n"
          "    This calls removes a mountpoint that was previously created with\n"
          "    \"mkmountpoint\". See \"mkmountpoint\" for full details.\n"
          "\n"
          "",
  .synopsis = "rmmountpoint exemptpath",
  .run = run_rmmountpoint
};

struct command_entry scrub_device_cmd_entry = {
  .name = "scrub-device",
  .help = "NAME\n"
          "    scrub-device - scrub (securely wipe) a device\n"
          "\n"
          "SYNOPSIS\n"
          "     scrub-device device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command writes patterns over \"device\" to make data retrieval more\n"
          "    difficult.\n"
          "\n"
          "    It is an interface to the scrub(1) program. See that manual page for\n"
          "    more details.\n"
          "\n"
          "",
  .synopsis = "scrub-device device",
  .run = run_scrub_device
};

struct command_entry set_cachedir_cmd_entry = {
  .name = "set-cachedir",
  .help = "NAME\n"
          "    set-cachedir - set the appliance cache directory\n"
          "\n"
          "SYNOPSIS\n"
          "     set-cachedir cachedir\n"
          "\n"
          "DESCRIPTION\n"
          "    Set the directory used by the handle to store the appliance cache, when\n"
          "    using a supermin appliance. The appliance is cached and shared between\n"
          "    all handles which have the same effective user ID.\n"
          "\n"
          "    The environment variables \"LIBGUESTFS_CACHEDIR\" and \"TMPDIR\" control the\n"
          "    default value: If \"LIBGUESTFS_CACHEDIR\" is set, then that is the\n"
          "    default. Else if \"TMPDIR\" is set, then that is the default. Else\n"
          "    /var/tmp is the default.\n"
          "\n"
          "    You can use 'cachedir' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = "set-cachedir cachedir",
  .run = run_set_cachedir
};

struct command_entry set_e2attrs_cmd_entry = {
  .name = "set-e2attrs",
  .help = "NAME\n"
          "    set-e2attrs - set ext2 file attributes of a file\n"
          "\n"
          "SYNOPSIS\n"
          "     set-e2attrs file attrs [clear:true|false]\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets or clears the file attributes \"attrs\" associated with the\n"
          "    inode file.\n"
          "\n"
          "    \"attrs\" is a string of characters representing file attributes. See\n"
          "    \"get_e2attrs\" for a list of possible attributes. Not all attributes can\n"
          "    be changed.\n"
          "\n"
          "    If optional boolean \"clear\" is not present or false, then the \"attrs\"\n"
          "    listed are set in the inode.\n"
          "\n"
          "    If \"clear\" is true, then the \"attrs\" listed are cleared in the inode.\n"
          "\n"
          "    In both cases, other attributes not present in the \"attrs\" string are\n"
          "    left unchanged.\n"
          "\n"
          "    These attributes are only present when the file is located on an\n"
          "    ext2/3/4 filesystem. Using this call on other filesystem types will\n"
          "    result in an error.\n"
          "\n"
          "",
  .synopsis = "set-e2attrs file attrs [clear:true|false]",
  .run = run_set_e2attrs
};

struct command_entry set_e2label_cmd_entry = {
  .name = "set-e2label",
  .help = "NAME\n"
          "    set-e2label - set the ext2/3/4 filesystem label\n"
          "\n"
          "SYNOPSIS\n"
          "     set-e2label device label\n"
          "\n"
          "DESCRIPTION\n"
          "    This sets the ext2/3/4 filesystem label of the filesystem on \"device\" to\n"
          "    \"label\". Filesystem labels are limited to 16 characters.\n"
          "\n"
          "    You can use either \"tune2fs_l\" or \"get_e2label\" to return the existing\n"
          "    label on a filesystem.\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"set-label\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "set-e2label device label",
  .run = run_set_e2label
};

struct command_entry sh_lines_cmd_entry = {
  .name = "sh-lines",
  .help = "NAME\n"
          "    sh-lines - run a command via the shell returning lines\n"
          "\n"
          "SYNOPSIS\n"
          "     sh-lines command\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the same as \"sh\", but splits the result into a list of lines.\n"
          "\n"
          "    See also: \"command_lines\"\n"
          "\n"
          "",
  .synopsis = "sh-lines command",
  .run = run_sh_lines
};

struct command_entry shutdown_cmd_entry = {
  .name = "shutdown",
  .help = "NAME\n"
          "    shutdown - shutdown the hypervisor\n"
          "\n"
          "SYNOPSIS\n"
          "     shutdown\n"
          "\n"
          "DESCRIPTION\n"
          "    This is the opposite of \"launch\". It performs an orderly shutdown of the\n"
          "    backend process(es). If the autosync flag is set (which is the default)\n"
          "    then the disk image is synchronized.\n"
          "\n"
          "    If the subprocess exits with an error then this function will return an\n"
          "    error, which should *not* be ignored (it may indicate that the disk\n"
          "    image could not be written out properly).\n"
          "\n"
          "    It is safe to call this multiple times. Extra calls are ignored.\n"
          "\n"
          "    This call does *not* close or free up the handle. You still need to call\n"
          "    \"close\" afterwards.\n"
          "\n"
          "    \"close\" will call this if you don't do it explicitly, but note that any\n"
          "    errors are ignored in that case.\n"
          "\n"
          "",
  .synopsis = "shutdown",
  .run = run_shutdown
};

struct command_entry swapon_file_cmd_entry = {
  .name = "swapon-file",
  .help = "NAME\n"
          "    swapon-file - enable swap on file\n"
          "\n"
          "SYNOPSIS\n"
          "     swapon-file file\n"
          "\n"
          "DESCRIPTION\n"
          "    This command enables swap to a file. See \"swapon_device\" for other\n"
          "    notes.\n"
          "\n"
          "",
  .synopsis = "swapon-file file",
  .run = run_swapon_file
};

struct command_entry tgz_out_cmd_entry = {
  .name = "tgz-out",
  .help = "NAME\n"
          "    tgz-out - pack directory into compressed tarball\n"
          "\n"
          "SYNOPSIS\n"
          "     tgz-out directory tarball\n"
          "\n"
          "DESCRIPTION\n"
          "    This command packs the contents of directory and downloads it to local\n"
          "    file \"tarball\".\n"
          "\n"
          "    *This function is deprecated.* In new code, use the \"tar-out\" call\n"
          "    instead.\n"
          "\n"
          "    Deprecated functions will not be removed from the API, but the fact that\n"
          "    they are deprecated indicates that there are problems with correct use\n"
          "    of these functions.\n"
          "\n"
          "",
  .synopsis = "tgz-out directory tarball",
  .run = run_tgz_out
};

struct command_entry umask_cmd_entry = {
  .name = "umask",
  .help = "NAME\n"
          "    umask - set file mode creation mask (umask)\n"
          "\n"
          "SYNOPSIS\n"
          "     umask mask\n"
          "\n"
          "DESCRIPTION\n"
          "    This function sets the mask used for creating new files and device nodes\n"
          "    to \"mask & 0777\".\n"
          "\n"
          "    Typical umask values would be 022 which creates new files with\n"
          "    permissions like \"-rw-r--r--\" or \"-rwxr-xr-x\", and 002 which creates new\n"
          "    files with permissions like \"-rw-rw-r--\" or \"-rwxrwxr-x\".\n"
          "\n"
          "    The default umask is 022. This is important because it means that\n"
          "    directories and device nodes will be created with 0644 or 0755 mode even\n"
          "    if you specify 0777.\n"
          "\n"
          "    See also \"get_umask\", umask(2), \"mknod\", \"mkdir\".\n"
          "\n"
          "    This call returns the previous umask.\n"
          "\n"
          "",
  .synopsis = "umask mask",
  .run = run_umask
};

struct command_entry wipefs_cmd_entry = {
  .name = "wipefs",
  .help = "NAME\n"
          "    wipefs - wipe a filesystem signature from a device\n"
          "\n"
          "SYNOPSIS\n"
          "     wipefs device\n"
          "\n"
          "DESCRIPTION\n"
          "    This command erases filesystem or RAID signatures from the specified\n"
          "    \"device\" to make the filesystem invisible to libblkid.\n"
          "\n"
          "    This does not erase the filesystem itself nor any other data from the\n"
          "    \"device\".\n"
          "\n"
          "    Compare with \"zero\" which zeroes the first few blocks of a device.\n"
          "\n"
          "",
  .synopsis = "wipefs device",
  .run = run_wipefs
};

