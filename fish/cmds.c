/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/fish.ml
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
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <libintl.h>
#include <errno.h>

#include "guestfs.h"
#include "guestfs-utils.h"
#include "structs-print.h"

#include "fish.h"
#include "fish-cmds.h"
#include "options.h"
#include "cmds-gperf.h"
#include "run.h"

struct command_entry alloc_cmd_entry = {
  .name = "alloc",
  .help = "NAME\n"
          "    alloc - allocate and add a disk file\n"
          "\n"
          "DESCRIPTION\n"
          "     alloc filename size\n"
          "\n"
          "    This creates an empty (zeroed) file of the given size, and then adds so\n"
          "    it can be further examined.\n"
          "\n"
          "    For more advanced image creation, see \"disk-create\".\n"
          "\n"
          "    Size can be specified using standard suffixes, eg. \"1M\".\n"
          "\n"
          "    To create a sparse file, use \"sparse\" instead. To create a prepared disk\n"
          "    image, see \"PREPARED DISK IMAGES\".\n"
          "\n"
          "    You can use 'allocate' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_alloc
};

struct command_entry copy_in_cmd_entry = {
  .name = "copy-in",
  .help = "NAME\n"
          "    copy-in - copy local files or directories into an image\n"
          "\n"
          "DESCRIPTION\n"
          "     copy-in local [local ...] /remotedir\n"
          "\n"
          "    \"copy-in\" copies local files or directories recursively into the disk\n"
          "    image, placing them in the directory called /remotedir (which must\n"
          "    exist). This guestfish meta-command turns into a sequence of \"tar-in\"\n"
          "    and other commands as necessary.\n"
          "\n"
          "    Multiple local files and directories can be specified, but the last\n"
          "    parameter must always be a remote directory. Wildcards cannot be used.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_copy_in
};

struct command_entry copy_out_cmd_entry = {
  .name = "copy-out",
  .help = "NAME\n"
          "    copy-out - copy remote files or directories out of an image\n"
          "\n"
          "DESCRIPTION\n"
          "     copy-out remote [remote ...] localdir\n"
          "\n"
          "    \"copy-out\" copies remote files or directories recursively out of the\n"
          "    disk image, placing them on the host disk in a local directory called\n"
          "    \"localdir\" (which must exist). This guestfish meta-command turns into a\n"
          "    sequence of \"download\", \"tar-out\" and other commands as necessary.\n"
          "\n"
          "    Multiple remote files and directories can be specified, but the last\n"
          "    parameter must always be a local directory. To download to the current\n"
          "    directory, use \".\" as in:\n"
          "\n"
          "     copy-out /home .\n"
          "\n"
          "    Wildcards cannot be used in the ordinary command, but you can use them\n"
          "    with the help of \"glob\" like this:\n"
          "\n"
          "     glob copy-out /home/* .\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_copy_out
};

struct command_entry delete_event_cmd_entry = {
  .name = "delete-event",
  .help = "NAME\n"
          "    delete-event - delete a previously registered event handler\n"
          "\n"
          "DESCRIPTION\n"
          "     delete-event name\n"
          "\n"
          "    Delete the event handler which was previously registered as \"name\". If\n"
          "    multiple event handlers were registered with the same name, they are all\n"
          "    deleted.\n"
          "\n"
          "    See also the guestfish commands \"event\" and \"list-events\".\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_delete_event
};

struct command_entry display_cmd_entry = {
  .name = "display",
  .help = "NAME\n"
          "    display - display an image\n"
          "\n"
          "DESCRIPTION\n"
          "     display filename\n"
          "\n"
          "    Use \"display\" (a graphical display program) to display an image file. It\n"
          "    downloads the file, and runs \"display\" on it.\n"
          "\n"
          "    To use an alternative program, set the \"GUESTFISH_DISPLAY_IMAGE\"\n"
          "    environment variable. For example to use the GNOME display program:\n"
          "\n"
          "     export GUESTFISH_DISPLAY_IMAGE=eog\n"
          "\n"
          "    See also display(1).\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_display
};

struct command_entry echo_cmd_entry = {
  .name = "echo",
  .help = "NAME\n"
          "    echo - display a line of text\n"
          "\n"
          "DESCRIPTION\n"
          "     echo [params ...]\n"
          "\n"
          "    This echos the parameters to the terminal.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_echo
};

struct command_entry edit_cmd_entry = {
  .name = "edit",
  .help = "NAME\n"
          "    edit - edit a file\n"
          "\n"
          "DESCRIPTION\n"
          "     edit filename\n"
          "\n"
          "    This is used to edit a file. It downloads the file, edits it locally\n"
          "    using your editor, then uploads the result.\n"
          "\n"
          "    The editor is $EDITOR. However if you use the alternate commands \"vi\" or\n"
          "    \"emacs\" you will get those corresponding editors.\n"
          "\n"
          "    You can use 'vi' or 'emacs' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_edit
};

struct command_entry event_cmd_entry = {
  .name = "event",
  .help = "NAME\n"
          "    event - register a handler for an event or events\n"
          "\n"
          "DESCRIPTION\n"
          "     event name eventset \"shell script ...\"\n"
          "\n"
          "    Register a shell script fragment which is executed when an event is\n"
          "    raised. See \"guestfs_set_event_callback\" in guestfs(3) for a discussion\n"
          "    of the event API in libguestfs.\n"
          "\n"
          "    The \"name\" parameter is a name that you give to this event handler. It\n"
          "    can be any string (even the empty string) and is simply there so you can\n"
          "    delete the handler using the guestfish \"delete-event\" command.\n"
          "\n"
          "    The \"eventset\" parameter is a comma-separated list of one or more\n"
          "    events, for example \"close\" or \"close,trace\". The special value \"*\"\n"
          "    means all events.\n"
          "\n"
          "    The third and final parameter is the shell script fragment (or any\n"
          "    external command) that is executed when any of the events in the\n"
          "    eventset occurs. It is executed using \"$SHELL -c\", or if $SHELL is not\n"
          "    set then /bin/sh -c.\n"
          "\n"
          "    The shell script fragment receives callback parameters as arguments $1,\n"
          "    $2 etc. The actual event that was called is available in the environment\n"
          "    variable $EVENT.\n"
          "\n"
          "     event \"\" close \"echo closed\"\n"
          "     event messages appliance,library,trace \"echo $@\"\n"
          "     event \"\" progress \"echo progress: $3/$4\"\n"
          "     event \"\" * \"echo $EVENT $@\"\n"
          "\n"
          "    See also the guestfish commands \"delete-event\" and \"list-events\".\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_event
};

struct command_entry glob_cmd_entry = {
  .name = "glob",
  .help = "NAME\n"
          "    glob - expand wildcards in command\n"
          "\n"
          "DESCRIPTION\n"
          "     glob command args...\n"
          "\n"
          "    Expand wildcards in any paths in the args list, and run \"command\"\n"
          "    repeatedly on each matching path.\n"
          "\n"
          "    See \"WILDCARDS AND GLOBBING\".\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_glob
};

struct command_entry hexedit_cmd_entry = {
  .name = "hexedit",
  .help = "NAME\n"
          "    hexedit - edit with a hex editor\n"
          "\n"
          "DESCRIPTION\n"
          "     hexedit <filename|device>\n"
          "     hexedit <filename|device> <max>\n"
          "     hexedit <filename|device> <start> <max>\n"
          "\n"
          "    Use hexedit (a hex editor) to edit all or part of a binary file or block\n"
          "    device.\n"
          "\n"
          "    This command works by downloading potentially the whole file or device,\n"
          "    editing it locally, then uploading it. If the file or device is large,\n"
          "    you have to specify which part you wish to edit by using \"max\" and/or\n"
          "    \"start\" \"max\" parameters. \"start\" and \"max\" are specified in bytes, with\n"
          "    the usual modifiers allowed such as \"1M\" (1 megabyte).\n"
          "\n"
          "    For example to edit the first few sectors of a disk you might do:\n"
          "\n"
          "     hexedit /dev/sda 1M\n"
          "\n"
          "    which would allow you to edit anywhere within the first megabyte of the\n"
          "    disk.\n"
          "\n"
          "    To edit the superblock of an ext2 filesystem on /dev/sda1, do:\n"
          "\n"
          "     hexedit /dev/sda1 0x400 0x400\n"
          "\n"
          "    (assuming the superblock is in the standard location).\n"
          "\n"
          "    This command requires the external hexedit(1) program. You can specify\n"
          "    another program to use by setting the \"HEXEDITOR\" environment variable.\n"
          "\n"
          "    See also \"hexdump\".\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_hexedit
};

struct command_entry lcd_cmd_entry = {
  .name = "lcd",
  .help = "NAME\n"
          "    lcd - change working directory\n"
          "\n"
          "DESCRIPTION\n"
          "     lcd directory\n"
          "\n"
          "    Change the local directory, ie. the current directory of guestfish\n"
          "    itself.\n"
          "\n"
          "    Note that \"!cd\" won't do what you might expect.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_lcd
};

struct command_entry list_events_cmd_entry = {
  .name = "list-events",
  .help = "NAME\n"
          "    list-events - list event handlers\n"
          "\n"
          "DESCRIPTION\n"
          "     list-events\n"
          "\n"
          "    List the event handlers registered using the guestfish \"event\" command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_list_events
};

struct command_entry man_cmd_entry = {
  .name = "man",
  .help = "NAME\n"
          "    man - open the manual\n"
          "\n"
          "DESCRIPTION\n"
          "      man\n"
          "\n"
          "    Opens the manual page for guestfish.\n"
          "\n"
          "    You can use 'manual' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_man
};

struct command_entry more_cmd_entry = {
  .name = "more",
  .help = "NAME\n"
          "    more - view a file\n"
          "\n"
          "DESCRIPTION\n"
          "     more filename\n"
          "\n"
          "     less filename\n"
          "\n"
          "    This is used to view a file.\n"
          "\n"
          "    The default viewer is $PAGER. However if you use the alternate command\n"
          "    \"less\" you will get the \"less\" command specifically.\n"
          "\n"
          "    You can use 'less' as an alias for this command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_more
};

struct command_entry reopen_cmd_entry = {
  .name = "reopen",
  .help = "NAME\n"
          "    reopen - close and reopen libguestfs handle\n"
          "\n"
          "DESCRIPTION\n"
          "      reopen\n"
          "\n"
          "    Close and reopen the libguestfs handle. It is not necessary to use this\n"
          "    normally, because the handle is closed properly when guestfish exits.\n"
          "    However this is occasionally useful for testing.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_reopen
};

struct command_entry setenv_cmd_entry = {
  .name = "setenv",
  .help = "NAME\n"
          "    setenv - set an environment variable\n"
          "\n"
          "DESCRIPTION\n"
          "      setenv VAR value\n"
          "\n"
          "    Set the environment variable \"VAR\" to the string \"value\".\n"
          "\n"
          "    To print the value of an environment variable use a shell command such\n"
          "    as:\n"
          "\n"
          "     !echo $VAR\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_setenv
};

struct command_entry sparse_cmd_entry = {
  .name = "sparse",
  .help = "NAME\n"
          "    sparse - create a sparse disk image and add\n"
          "\n"
          "DESCRIPTION\n"
          "     sparse filename size\n"
          "\n"
          "    This creates an empty sparse file of the given size, and then adds so it\n"
          "    can be further examined.\n"
          "\n"
          "    In all respects it works the same as the \"alloc\" command, except that\n"
          "    the image file is allocated sparsely, which means that disk blocks are\n"
          "    not assigned to the file until they are needed. Sparse disk files only\n"
          "    use space when written to, but they are slower and there is a danger you\n"
          "    could run out of real disk space during a write operation.\n"
          "\n"
          "    For more advanced image creation, see \"disk-create\".\n"
          "\n"
          "    Size can be specified using standard suffixes, eg. \"1M\".\n"
          "\n"
          "    See also the guestfish \"scratch\" command.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_sparse
};

struct command_entry supported_cmd_entry = {
  .name = "supported",
  .help = "NAME\n"
          "    supported - list supported groups of commands\n"
          "\n"
          "DESCRIPTION\n"
          "     supported\n"
          "\n"
          "    This command returns a list of the optional groups known to the daemon,\n"
          "    and indicates which ones are supported by this build of the libguestfs\n"
          "    appliance.\n"
          "\n"
          "    See also \"AVAILABILITY\" in guestfs(3).\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_supported
};

struct command_entry time_cmd_entry = {
  .name = "time",
  .help = "NAME\n"
          "    time - print elapsed time taken to run a command\n"
          "\n"
          "DESCRIPTION\n"
          "     time command args...\n"
          "\n"
          "    Run the command as usual, but print the elapsed time afterwards. This\n"
          "    can be useful for benchmarking operations.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_time
};

struct command_entry unsetenv_cmd_entry = {
  .name = "unsetenv",
  .help = "NAME\n"
          "    unsetenv - unset an environment variable\n"
          "\n"
          "DESCRIPTION\n"
          "      unsetenv VAR\n"
          "\n"
          "    Remove \"VAR\" from the environment.\n"
          "\n"
          "",
  .synopsis = NULL,
  .run = run_unsetenv
};

void
list_commands (void)
{
  printf ("    %-16s     %s\n", _("Command"), _("Description"));
  list_builtin_commands ();
  printf ("%-20s %s\n", "acl-delete-def-file", _("delete the default POSIX ACL of a directory"));
  printf ("%-20s %s\n", "acl-get-file", _("get the POSIX ACL attached to a file"));
  printf ("%-20s %s\n", "acl-set-file", _("set the POSIX ACL attached to a file"));
  printf ("%-20s ", "add");
  printf (_("alias for '%s'"), "add-drive");
  putchar ('\n');
  printf ("%-20s ", "add-ro");
  printf (_("alias for '%s'"), "add-drive-ro");
  putchar ('\n');
  printf ("%-20s %s\n", "add-cdrom", _("add a CD-ROM disk image to examine"));
  printf ("%-20s %s\n", "add-domain", _("add the disk(s) from a named libvirt domain"));
  printf ("%-20s %s\n", "add-drive", _("add an image to examine or modify"));
  printf ("%-20s %s\n", "add-drive-ro", _("add a drive in snapshot mode (read-only)"));
  printf ("%-20s %s\n", "add-drive-ro-with-if", _("add a drive read-only specifying the QEMU block emulation to use"));
  printf ("%-20s %s\n", "add-drive-scratch", _("add a temporary scratch drive"));
  printf ("%-20s %s\n", "add-drive-with-if", _("add a drive specifying the QEMU block emulation to use"));
  printf ("%-20s %s\n", "alloc", _("allocate and add a disk file"));
  printf ("%-20s ", "allocate");
  printf (_("alias for '%s'"), "alloc");
  putchar ('\n');
  printf ("%-20s ", "append");
  printf (_("alias for '%s'"), "set-append");
  putchar ('\n');
  printf ("%-20s ", "attach-method");
  printf (_("alias for '%s'"), "set-attach-method");
  putchar ('\n');
  printf ("%-20s %s\n", "aug-clear", _("clear Augeas path"));
  printf ("%-20s %s\n", "aug-close", _("close the current Augeas handle"));
  printf ("%-20s %s\n", "aug-defnode", _("define an Augeas node"));
  printf ("%-20s %s\n", "aug-defvar", _("define an Augeas variable"));
  printf ("%-20s %s\n", "aug-get", _("look up the value of an Augeas path"));
  printf ("%-20s %s\n", "aug-init", _("create a new Augeas handle"));
  printf ("%-20s %s\n", "aug-insert", _("insert a sibling Augeas node"));
  printf ("%-20s %s\n", "aug-label", _("return the label from an Augeas path expression"));
  printf ("%-20s %s\n", "aug-load", _("load files into the tree"));
  printf ("%-20s %s\n", "aug-ls", _("list Augeas nodes under augpath"));
  printf ("%-20s %s\n", "aug-match", _("return Augeas nodes which match augpath"));
  printf ("%-20s %s\n", "aug-mv", _("move Augeas node"));
  printf ("%-20s %s\n", "aug-rm", _("remove an Augeas path"));
  printf ("%-20s %s\n", "aug-save", _("write all pending Augeas changes to disk"));
  printf ("%-20s %s\n", "aug-set", _("set Augeas path to value"));
  printf ("%-20s %s\n", "aug-setm", _("set multiple Augeas nodes"));
  printf ("%-20s %s\n", "aug-transform", _("add/remove an Augeas lens transformation"));
  printf ("%-20s ", "autosync");
  printf (_("alias for '%s'"), "set-autosync");
  putchar ('\n');
  printf ("%-20s %s\n", "available", _("test availability of some parts of the API"));
  printf ("%-20s %s\n", "available-all-groups", _("return a list of all optional groups"));
  printf ("%-20s ", "backend");
  printf (_("alias for '%s'"), "set-backend");
  putchar ('\n');
  printf ("%-20s %s\n", "base64-in", _("upload base64-encoded data to file"));
  printf ("%-20s %s\n", "base64-out", _("download file and encode as base64"));
  printf ("%-20s %s\n", "blkdiscard", _("discard all blocks on a device"));
  printf ("%-20s %s\n", "blkdiscardzeroes", _("return true if discarded blocks are read as zeroes"));
  printf ("%-20s %s\n", "blkid", _("print block device attributes"));
  printf ("%-20s %s\n", "blockdev-flushbufs", _("flush device buffers"));
  printf ("%-20s %s\n", "blockdev-getbsz", _("get blocksize of block device"));
  printf ("%-20s %s\n", "blockdev-getro", _("is block device set to read-only"));
  printf ("%-20s %s\n", "blockdev-getsize64", _("get total size of device in bytes"));
  printf ("%-20s %s\n", "blockdev-getss", _("get sectorsize of block device"));
  printf ("%-20s %s\n", "blockdev-getsz", _("get total size of device in 512-byte sectors"));
  printf ("%-20s %s\n", "blockdev-rereadpt", _("reread partition table"));
  printf ("%-20s %s\n", "blockdev-setbsz", _("set blocksize of block device"));
  printf ("%-20s %s\n", "blockdev-setra", _("set readahead"));
  printf ("%-20s %s\n", "blockdev-setro", _("set block device to read-only"));
  printf ("%-20s %s\n", "blockdev-setrw", _("set block device to read-write"));
  printf ("%-20s ", "btrfs-balance");
  printf (_("alias for '%s'"), "btrfs-filesystem-balance");
  putchar ('\n');
  printf ("%-20s %s\n", "btrfs-balance-cancel", _("cancel a running or paused balance"));
  printf ("%-20s %s\n", "btrfs-balance-pause", _("pause a running balance"));
  printf ("%-20s %s\n", "btrfs-balance-resume", _("resume a paused balance"));
  printf ("%-20s %s\n", "btrfs-balance-status", _("show the status of a running or paused balance"));
  printf ("%-20s %s\n", "btrfs-device-add", _("add devices to a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-device-delete", _("remove devices from a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-filesystem-balance", _("balance a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-filesystem-defragment", _("defragment a file or directory"));
  printf ("%-20s %s\n", "btrfs-filesystem-resize", _("resize a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-filesystem-show", _("list devices for btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-filesystem-sync", _("sync a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-fsck", _("check a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-image", _("create an image of a btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-qgroup-assign", _("add a qgroup to a parent qgroup"));
  printf ("%-20s %s\n", "btrfs-qgroup-create", _("create a subvolume quota group"));
  printf ("%-20s %s\n", "btrfs-qgroup-destroy", _("destroy a subvolume quota group"));
  printf ("%-20s %s\n", "btrfs-qgroup-limit", _("limit the size of a subvolume"));
  printf ("%-20s %s\n", "btrfs-qgroup-remove", _("remove a qgroup from its parent qgroup"));
  printf ("%-20s %s\n", "btrfs-qgroup-show", _("show subvolume quota groups"));
  printf ("%-20s %s\n", "btrfs-quota-enable", _("enable or disable subvolume quota support"));
  printf ("%-20s %s\n", "btrfs-quota-rescan", _("trash all qgroup numbers and scan the metadata again with the current config"));
  printf ("%-20s %s\n", "btrfs-replace", _("replace a btrfs managed device with another device"));
  printf ("%-20s %s\n", "btrfs-rescue-chunk-recover", _("recover the chunk tree of btrfs filesystem"));
  printf ("%-20s %s\n", "btrfs-rescue-super-recover", _("recover bad superblocks from good copies"));
  printf ("%-20s %s\n", "btrfs-scrub-cancel", _("cancel a running scrub"));
  printf ("%-20s %s\n", "btrfs-scrub-resume", _("resume a previously canceled or interrupted scrub"));
  printf ("%-20s %s\n", "btrfs-scrub-start", _("read all data from all disks and verify checksums"));
  printf ("%-20s %s\n", "btrfs-scrub-status", _("show status of running or finished scrub"));
  printf ("%-20s %s\n", "btrfs-set-seeding", _("enable or disable the seeding feature of device"));
  printf ("%-20s %s\n", "btrfs-subvolume-create", _("create a btrfs subvolume"));
  printf ("%-20s %s\n", "btrfs-subvolume-delete", _("delete a btrfs subvolume or snapshot"));
  printf ("%-20s %s\n", "btrfs-subvolume-get-default", _("get the default subvolume or snapshot of a filesystem"));
  printf ("%-20s %s\n", "btrfs-subvolume-list", _("list btrfs snapshots and subvolumes"));
  printf ("%-20s %s\n", "btrfs-subvolume-set-default", _("set default btrfs subvolume"));
  printf ("%-20s %s\n", "btrfs-subvolume-show", _("return detailed information of the subvolume"));
  printf ("%-20s %s\n", "btrfs-subvolume-snapshot", _("create a btrfs snapshot"));
  printf ("%-20s %s\n", "btrfstune-enable-extended-inode-refs", _("enable extended inode refs"));
  printf ("%-20s %s\n", "btrfstune-enable-skinny-metadata-extent-refs", _("enable skinny metadata extent refs"));
  printf ("%-20s %s\n", "btrfstune-seeding", _("enable or disable seeding of a btrfs device"));
  printf ("%-20s %s\n", "c-pointer", _("return the C pointer to the guestfs_h handle"));
  printf ("%-20s ", "cachedir");
  printf (_("alias for '%s'"), "set-cachedir");
  putchar ('\n');
  printf ("%-20s %s\n", "canonical-device-name", _("return canonical device name"));
  printf ("%-20s %s\n", "cap-get-file", _("get the Linux capabilities attached to a file"));
  printf ("%-20s %s\n", "cap-set-file", _("set the Linux capabilities attached to a file"));
  printf ("%-20s %s\n", "case-sensitive-path", _("return true path on case-insensitive filesystem"));
  printf ("%-20s %s\n", "cat", _("list the contents of a file"));
  printf ("%-20s %s\n", "checksum", _("compute MD5, SHAx or CRC checksum of file"));
  printf ("%-20s %s\n", "checksum-device", _("compute MD5, SHAx or CRC checksum of the contents of a device"));
  printf ("%-20s %s\n", "checksums-out", _("compute MD5, SHAx or CRC checksum of files in a directory"));
  printf ("%-20s %s\n", "chmod", _("change file mode"));
  printf ("%-20s %s\n", "chown", _("change file owner and group"));
  printf ("%-20s %s\n", "clear-backend-setting", _("remove a single per-backend settings string"));
  printf ("%-20s %s\n", "command", _("run a command from the guest filesystem"));
  printf ("%-20s %s\n", "command-lines", _("run a command, returning lines"));
  printf ("%-20s %s\n", "compress-device-out", _("output compressed device"));
  printf ("%-20s %s\n", "compress-out", _("output compressed file"));
  printf ("%-20s %s\n", "config", _("add hypervisor parameters"));
  printf ("%-20s %s\n", "copy-attributes", _("copy the attributes of a path (file/directory) to another"));
  printf ("%-20s %s\n", "copy-device-to-device", _("copy from source device to destination device"));
  printf ("%-20s %s\n", "copy-device-to-file", _("copy from source device to destination file"));
  printf ("%-20s %s\n", "copy-file-to-device", _("copy from source file to destination device"));
  printf ("%-20s %s\n", "copy-file-to-file", _("copy from source file to destination file"));
  printf ("%-20s %s\n", "copy-in", _("copy local files or directories into an image"));
  printf ("%-20s %s\n", "copy-out", _("copy remote files or directories out of an image"));
  printf ("%-20s %s\n", "copy-size", _("copy size bytes from source to destination using dd"));
  printf ("%-20s %s\n", "cp", _("copy a file"));
  printf ("%-20s %s\n", "cp-a", _("copy a file or directory recursively"));
  printf ("%-20s %s\n", "cp-r", _("copy a file or directory recursively"));
  printf ("%-20s %s\n", "cpio-out", _("pack directory into cpio file"));
  printf ("%-20s %s\n", "dd", _("copy from source to destination using dd"));
  printf ("%-20s %s\n", "debug", _("debugging and internals"));
  printf ("%-20s %s\n", "debug-drives", _("debug the drives (internal use only)"));
  printf ("%-20s %s\n", "debug-upload", _("upload a file to the appliance (internal use only)"));
  printf ("%-20s %s\n", "delete-event", _("delete a previously registered event handler"));
  printf ("%-20s %s\n", "device-index", _("convert device to index"));
  printf ("%-20s %s\n", "df", _("report file system disk space usage"));
  printf ("%-20s %s\n", "df-h", _("report file system disk space usage (human readable)"));
  printf ("%-20s ", "direct");
  printf (_("alias for '%s'"), "set-direct");
  putchar ('\n');
  printf ("%-20s %s\n", "disk-create", _("create a blank disk image"));
  printf ("%-20s %s\n", "disk-format", _("detect the disk format of a disk image"));
  printf ("%-20s %s\n", "disk-has-backing-file", _("return whether disk has a backing file"));
  printf ("%-20s %s\n", "disk-virtual-size", _("return virtual size of a disk"));
  printf ("%-20s %s\n", "display", _("display an image"));
  printf ("%-20s %s\n", "dmesg", _("return kernel messages"));
  printf ("%-20s ", "domain");
  printf (_("alias for '%s'"), "add-domain");
  putchar ('\n');
  printf ("%-20s %s\n", "download", _("download a file to the local machine"));
  printf ("%-20s %s\n", "download-blocks", _("download the given data units from the disk"));
  printf ("%-20s %s\n", "download-inode", _("download a file to the local machine given its inode"));
  printf ("%-20s %s\n", "download-offset", _("download a file to the local machine with offset and size"));
  printf ("%-20s %s\n", "drop-caches", _("drop kernel page cache, dentries and inodes"));
  printf ("%-20s %s\n", "du", _("estimate file space usage"));
  printf ("%-20s %s\n", "e2fsck", _("check an ext2/ext3 filesystem"));
  printf ("%-20s %s\n", "e2fsck-f", _("check an ext2/ext3 filesystem"));
  printf ("%-20s %s\n", "echo", _("display a line of text"));
  printf ("%-20s %s\n", "echo-daemon", _("echo arguments back to the client"));
  printf ("%-20s %s\n", "edit", _("edit a file"));
  printf ("%-20s %s\n", "egrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "egrepi", _("return lines matching a pattern"));
  printf ("%-20s ", "emacs");
  printf (_("alias for '%s'"), "edit");
  putchar ('\n');
  printf ("%-20s %s\n", "equal", _("test if two files have equal contents"));
  printf ("%-20s %s\n", "event", _("register a handler for an event or events"));
  printf ("%-20s %s\n", "exists", _("test if file or directory exists"));
  printf ("%-20s %s\n", "extlinux", _("install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem"));
  printf ("%-20s %s\n", "f2fs-expand", _("expand a f2fs filesystem"));
  printf ("%-20s %s\n", "fallocate", _("preallocate a file in the guest filesystem"));
  printf ("%-20s %s\n", "fallocate64", _("preallocate a file in the guest filesystem"));
  printf ("%-20s %s\n", "feature-available", _("test availability of some parts of the API"));
  printf ("%-20s %s\n", "fgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "fgrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "file", _("determine file type"));
  printf ("%-20s %s\n", "file-architecture", _("detect the architecture of a binary file"));
  printf ("%-20s %s\n", "filesize", _("return the size of the file in bytes"));
  printf ("%-20s %s\n", "filesystem-available", _("check if filesystem is available"));
  printf ("%-20s %s\n", "filesystem-walk", _("walk through the filesystem content"));
  printf ("%-20s %s\n", "fill", _("fill a file with octets"));
  printf ("%-20s %s\n", "fill-dir", _("fill a directory with empty files"));
  printf ("%-20s %s\n", "fill-pattern", _("fill a file with a repeating pattern of bytes"));
  printf ("%-20s %s\n", "find", _("find all files and directories"));
  printf ("%-20s %s\n", "find0", _("find all files and directories, returning NUL-separated list"));
  printf ("%-20s %s\n", "find-inode", _("search the entries associated to the given inode"));
  printf ("%-20s %s\n", "findfs-label", _("find a filesystem by label"));
  printf ("%-20s %s\n", "findfs-uuid", _("find a filesystem by UUID"));
  printf ("%-20s %s\n", "fsck", _("run the filesystem checker"));
  printf ("%-20s %s\n", "fstrim", _("trim free space in a filesystem"));
  printf ("%-20s ", "get-uuid");
  printf (_("alias for '%s'"), "vfs-uuid");
  putchar ('\n');
  printf ("%-20s %s\n", "get-append", _("get the additional kernel options"));
  printf ("%-20s %s\n", "get-attach-method", _("get the backend"));
  printf ("%-20s %s\n", "get-autosync", _("get autosync mode"));
  printf ("%-20s %s\n", "get-backend", _("get the backend"));
  printf ("%-20s %s\n", "get-backend-setting", _("get a single per-backend settings string"));
  printf ("%-20s %s\n", "get-backend-settings", _("get per-backend settings"));
  printf ("%-20s %s\n", "get-cachedir", _("get the appliance cache directory"));
  printf ("%-20s %s\n", "get-direct", _("get direct appliance mode flag"));
  printf ("%-20s %s\n", "get-e2attrs", _("get ext2 file attributes of a file"));
  printf ("%-20s %s\n", "get-e2generation", _("get ext2 file generation of a file"));
  printf ("%-20s %s\n", "get-e2label", _("get the ext2/3/4 filesystem label"));
  printf ("%-20s %s\n", "get-e2uuid", _("get the ext2/3/4 filesystem UUID"));
  printf ("%-20s %s\n", "get-hv", _("get the hypervisor binary"));
  printf ("%-20s %s\n", "get-identifier", _("get the handle identifier"));
  printf ("%-20s %s\n", "get-libvirt-requested-credential-challenge", _("challenge of i'th requested credential"));
  printf ("%-20s %s\n", "get-libvirt-requested-credential-defresult", _("default result of i'th requested credential"));
  printf ("%-20s %s\n", "get-libvirt-requested-credential-prompt", _("prompt of i'th requested credential"));
  printf ("%-20s %s\n", "get-libvirt-requested-credentials", _("get list of credentials requested by libvirt"));
  printf ("%-20s %s\n", "get-memsize", _("get memory allocated to the hypervisor"));
  printf ("%-20s %s\n", "get-network", _("get enable network flag"));
  printf ("%-20s %s\n", "get-path", _("get the search path"));
  printf ("%-20s %s\n", "get-pgroup", _("get process group flag"));
  printf ("%-20s %s\n", "get-pid", _("get PID of hypervisor"));
  printf ("%-20s %s\n", "get-program", _("get the program name"));
  printf ("%-20s %s\n", "get-qemu", _("get the hypervisor binary (usually qemu)"));
  printf ("%-20s %s\n", "get-recovery-proc", _("get recovery process enabled flag"));
  printf ("%-20s %s\n", "get-selinux", _("get SELinux enabled flag"));
  printf ("%-20s %s\n", "get-smp", _("get number of virtual CPUs in appliance"));
  printf ("%-20s %s\n", "get-sockdir", _("get the temporary directory for sockets"));
  printf ("%-20s %s\n", "get-tmpdir", _("get the temporary directory"));
  printf ("%-20s %s\n", "get-trace", _("get command trace enabled flag"));
  printf ("%-20s %s\n", "get-umask", _("get the current umask"));
  printf ("%-20s %s\n", "get-verbose", _("get verbose mode"));
  printf ("%-20s %s\n", "getcon", _("get SELinux security context"));
  printf ("%-20s %s\n", "getxattr", _("get a single extended attribute"));
  printf ("%-20s %s\n", "getxattrs", _("list extended attributes of a file or directory"));
  printf ("%-20s %s\n", "glob", _("expand wildcards in command"));
  printf ("%-20s %s\n", "glob-expand", _("expand a wildcard path"));
  printf ("%-20s %s\n", "grep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "grepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "grub-install", _("install GRUB 1"));
  printf ("%-20s %s\n", "head", _("return first 10 lines of a file"));
  printf ("%-20s %s\n", "head-n", _("return first N lines of a file"));
  printf ("%-20s %s\n", "hexdump", _("dump a file in hexadecimal"));
  printf ("%-20s %s\n", "hexedit", _("edit with a hex editor"));
  printf ("%-20s %s\n", "hivex-close", _("close the current hivex handle"));
  printf ("%-20s %s\n", "hivex-commit", _("commit (write) changes back to the hive"));
  printf ("%-20s %s\n", "hivex-node-add-child", _("add a child node"));
  printf ("%-20s %s\n", "hivex-node-children", _("return list of nodes which are subkeys of node"));
  printf ("%-20s %s\n", "hivex-node-delete-child", _("delete a node (recursively)"));
  printf ("%-20s %s\n", "hivex-node-get-child", _("return the named child of node"));
  printf ("%-20s %s\n", "hivex-node-get-value", _("return the named value"));
  printf ("%-20s %s\n", "hivex-node-name", _("return the name of the node"));
  printf ("%-20s %s\n", "hivex-node-parent", _("return the parent of node"));
  printf ("%-20s %s\n", "hivex-node-set-value", _("set or replace a single value in a node"));
  printf ("%-20s %s\n", "hivex-node-values", _("return list of values attached to node"));
  printf ("%-20s %s\n", "hivex-open", _("open a Windows Registry hive file"));
  printf ("%-20s %s\n", "hivex-root", _("return the root node of the hive"));
  printf ("%-20s %s\n", "hivex-value-key", _("return the key field from the (key, datatype, data) tuple"));
  printf ("%-20s %s\n", "hivex-value-string", _("return the data field as a UTF-8 string"));
  printf ("%-20s %s\n", "hivex-value-type", _("return the data type from the (key, datatype, data) tuple"));
  printf ("%-20s %s\n", "hivex-value-utf8", _("return the data field as a UTF-8 string"));
  printf ("%-20s %s\n", "hivex-value-value", _("return the data field from the (key, datatype, data) tuple"));
  printf ("%-20s ", "hv");
  printf (_("alias for '%s'"), "set-hv");
  putchar ('\n');
  printf ("%-20s ", "identifier");
  printf (_("alias for '%s'"), "set-identifier");
  putchar ('\n');
  printf ("%-20s %s\n", "initrd-cat", _("list the contents of a single file in an initrd"));
  printf ("%-20s %s\n", "initrd-list", _("list files in an initrd"));
  printf ("%-20s %s\n", "inotify-add-watch", _("add an inotify watch"));
  printf ("%-20s %s\n", "inotify-close", _("close the inotify handle"));
  printf ("%-20s %s\n", "inotify-files", _("return list of watched files that had events"));
  printf ("%-20s %s\n", "inotify-init", _("create an inotify handle"));
  printf ("%-20s %s\n", "inotify-read", _("return list of inotify events"));
  printf ("%-20s %s\n", "inotify-rm-watch", _("remove an inotify watch"));
  printf ("%-20s %s\n", "inspect-get-arch", _("get architecture of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-distro", _("get distro of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-drive-mappings", _("get drive letter mappings"));
  printf ("%-20s %s\n", "inspect-get-filesystems", _("get filesystems associated with inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-format", _("get format of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-hostname", _("get hostname of the operating system"));
  printf ("%-20s %s\n", "inspect-get-icon", _("get the icon corresponding to this operating system"));
  printf ("%-20s %s\n", "inspect-get-major-version", _("get major version of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-minor-version", _("get minor version of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-mountpoints", _("get mountpoints of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-osinfo", _("get a possible osinfo short ID corresponding to this operating system"));
  printf ("%-20s %s\n", "inspect-get-package-format", _("get package format used by the operating system"));
  printf ("%-20s %s\n", "inspect-get-package-management", _("get package management tool used by the operating system"));
  printf ("%-20s %s\n", "inspect-get-product-name", _("get product name of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-product-variant", _("get product variant of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-roots", _("return list of operating systems found by last inspection"));
  printf ("%-20s %s\n", "inspect-get-type", _("get type of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-windows-current-control-set", _("get Windows CurrentControlSet of inspected operating system"));
  printf ("%-20s %s\n", "inspect-get-windows-software-hive", _("get the path of the Windows software hive"));
  printf ("%-20s %s\n", "inspect-get-windows-system-hive", _("get the path of the Windows system hive"));
  printf ("%-20s %s\n", "inspect-get-windows-systemroot", _("get Windows systemroot of inspected operating system"));
  printf ("%-20s %s\n", "inspect-is-live", _("get live flag for install disk"));
  printf ("%-20s %s\n", "inspect-is-multipart", _("get multipart flag for install disk"));
  printf ("%-20s %s\n", "inspect-is-netinst", _("get netinst (network installer) flag for install disk"));
  printf ("%-20s %s\n", "inspect-list-applications", _("get list of applications installed in the operating system"));
  printf ("%-20s %s\n", "inspect-list-applications2", _("get list of applications installed in the operating system"));
  printf ("%-20s %s\n", "inspect-os", _("inspect disk and return list of operating systems found"));
  printf ("%-20s %s\n", "internal-exit", _("cause the daemon to exit (internal use only)"));
  printf ("%-20s %s\n", "is-blockdev", _("test if block device"));
  printf ("%-20s %s\n", "is-chardev", _("test if character device"));
  printf ("%-20s %s\n", "is-config", _("is in configuration state"));
  printf ("%-20s %s\n", "is-dir", _("test if a directory"));
  printf ("%-20s %s\n", "is-fifo", _("test if FIFO (named pipe)"));
  printf ("%-20s %s\n", "is-file", _("test if a regular file"));
  printf ("%-20s %s\n", "is-lv", _("test if mountable is a logical volume"));
  printf ("%-20s %s\n", "is-socket", _("test if socket"));
  printf ("%-20s %s\n", "is-symlink", _("test if symbolic link"));
  printf ("%-20s %s\n", "is-whole-device", _("test if a device is a whole device"));
  printf ("%-20s %s\n", "is-zero", _("test if a file contains all zero bytes"));
  printf ("%-20s %s\n", "is-zero-device", _("test if a device contains all zero bytes"));
  printf ("%-20s %s\n", "isoinfo", _("get ISO information from primary volume descriptor of ISO file"));
  printf ("%-20s %s\n", "isoinfo-device", _("get ISO information from primary volume descriptor of device"));
  printf ("%-20s %s\n", "journal-close", _("close the systemd journal"));
  printf ("%-20s %s\n", "journal-get", _("read the current journal entry"));
  printf ("%-20s %s\n", "journal-get-data-threshold", _("get the data threshold for reading journal entries"));
  printf ("%-20s %s\n", "journal-get-realtime-usec", _("get the timestamp of the current journal entry"));
  printf ("%-20s %s\n", "journal-next", _("move to the next journal entry"));
  printf ("%-20s %s\n", "journal-open", _("open the systemd journal"));
  printf ("%-20s %s\n", "journal-set-data-threshold", _("set the data threshold for reading journal entries"));
  printf ("%-20s %s\n", "journal-skip", _("skip forwards or backwards in the journal"));
  printf ("%-20s %s\n", "kill-subprocess", _("kill the hypervisor"));
  printf ("%-20s %s\n", "launch", _("launch the backend"));
  printf ("%-20s %s\n", "lcd", _("change working directory"));
  printf ("%-20s %s\n", "lchown", _("change file owner and group"));
  printf ("%-20s %s\n", "ldmtool-create-all", _("scan and create Windows dynamic disk volumes"));
  printf ("%-20s %s\n", "ldmtool-diskgroup-disks", _("return the disks in a Windows dynamic disk group"));
  printf ("%-20s %s\n", "ldmtool-diskgroup-name", _("return the name of a Windows dynamic disk group"));
  printf ("%-20s %s\n", "ldmtool-diskgroup-volumes", _("return the volumes in a Windows dynamic disk group"));
  printf ("%-20s %s\n", "ldmtool-remove-all", _("remove all Windows dynamic disk volumes"));
  printf ("%-20s %s\n", "ldmtool-scan", _("scan for Windows dynamic disks"));
  printf ("%-20s %s\n", "ldmtool-scan-devices", _("scan for Windows dynamic disks"));
  printf ("%-20s %s\n", "ldmtool-volume-hint", _("return the hint field of a Windows dynamic disk volume"));
  printf ("%-20s %s\n", "ldmtool-volume-partitions", _("return the partitions in a Windows dynamic disk volume"));
  printf ("%-20s %s\n", "ldmtool-volume-type", _("return the type of a Windows dynamic disk volume"));
  printf ("%-20s ", "less");
  printf (_("alias for '%s'"), "more");
  putchar ('\n');
  printf ("%-20s %s\n", "lgetxattr", _("get a single extended attribute"));
  printf ("%-20s %s\n", "lgetxattrs", _("list extended attributes of a file or directory"));
  printf ("%-20s %s\n", "list-9p", _("list 9p filesystems"));
  printf ("%-20s %s\n", "list-devices", _("list the block devices"));
  printf ("%-20s %s\n", "list-disk-labels", _("mapping of disk labels to devices"));
  printf ("%-20s %s\n", "list-dm-devices", _("list device mapper devices"));
  printf ("%-20s %s\n", "list-events", _("list event handlers"));
  printf ("%-20s %s\n", "list-filesystems", _("list filesystems"));
  printf ("%-20s %s\n", "list-ldm-partitions", _("list all Windows dynamic disk partitions"));
  printf ("%-20s %s\n", "list-ldm-volumes", _("list all Windows dynamic disk volumes"));
  printf ("%-20s %s\n", "list-md-devices", _("list Linux md (RAID) devices"));
  printf ("%-20s %s\n", "list-partitions", _("list the partitions"));
  printf ("%-20s %s\n", "ll", _("list the files in a directory (long format)"));
  printf ("%-20s %s\n", "llz", _("list the files in a directory (long format with SELinux contexts)"));
  printf ("%-20s %s\n", "ln", _("create a hard link"));
  printf ("%-20s %s\n", "ln-f", _("create a hard link"));
  printf ("%-20s %s\n", "ln-s", _("create a symbolic link"));
  printf ("%-20s %s\n", "ln-sf", _("create a symbolic link"));
  printf ("%-20s %s\n", "lremovexattr", _("remove extended attribute of a file or directory"));
  printf ("%-20s %s\n", "ls", _("list the files in a directory"));
  printf ("%-20s %s\n", "ls0", _("get list of files in a directory"));
  printf ("%-20s %s\n", "lsetxattr", _("set extended attribute of a file or directory"));
  printf ("%-20s %s\n", "lstat", _("get file information for a symbolic link"));
  printf ("%-20s %s\n", "lstatlist", _("lstat on multiple files"));
  printf ("%-20s %s\n", "lstatns", _("get file information for a symbolic link"));
  printf ("%-20s %s\n", "lstatnslist", _("lstat on multiple files"));
  printf ("%-20s %s\n", "luks-add-key", _("add a key on a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-close", _("close a LUKS device"));
  printf ("%-20s %s\n", "luks-format", _("format a block device as a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-format-cipher", _("format a block device as a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-kill-slot", _("remove a key from a LUKS encrypted device"));
  printf ("%-20s %s\n", "luks-open", _("open a LUKS-encrypted block device"));
  printf ("%-20s %s\n", "luks-open-ro", _("open a LUKS-encrypted block device read-only"));
  printf ("%-20s %s\n", "lvcreate", _("create an LVM logical volume"));
  printf ("%-20s %s\n", "lvcreate-free", _("create an LVM logical volume in % remaining free space"));
  printf ("%-20s %s\n", "lvm-canonical-lv-name", _("get canonical name of an LV"));
  printf ("%-20s %s\n", "lvm-clear-filter", _("clear LVM device filter"));
  printf ("%-20s %s\n", "lvm-remove-all", _("remove all LVM LVs, VGs and PVs"));
  printf ("%-20s %s\n", "lvm-scan", _("scan for LVM physical volumes, volume groups and logical volumes"));
  printf ("%-20s %s\n", "lvm-set-filter", _("set LVM device filter"));
  printf ("%-20s %s\n", "lvremove", _("remove an LVM logical volume"));
  printf ("%-20s %s\n", "lvrename", _("rename an LVM logical volume"));
  printf ("%-20s %s\n", "lvresize", _("resize an LVM logical volume"));
  printf ("%-20s %s\n", "lvresize-free", _("expand an LV to fill free space"));
  printf ("%-20s %s\n", "lvs", _("list the LVM logical volumes (LVs)"));
  printf ("%-20s %s\n", "lvs-full", _("list the LVM logical volumes (LVs)"));
  printf ("%-20s %s\n", "lvuuid", _("get the UUID of a logical volume"));
  printf ("%-20s %s\n", "lxattrlist", _("lgetxattr on multiple files"));
  printf ("%-20s %s\n", "man", _("open the manual"));
  printf ("%-20s ", "manual");
  printf (_("alias for '%s'"), "man");
  putchar ('\n');
  printf ("%-20s %s\n", "max-disks", _("maximum number of disks that may be added"));
  printf ("%-20s %s\n", "md-create", _("create a Linux md (RAID) device"));
  printf ("%-20s %s\n", "md-detail", _("obtain metadata for an MD device"));
  printf ("%-20s %s\n", "md-stat", _("get underlying devices from an MD device"));
  printf ("%-20s %s\n", "md-stop", _("stop a Linux md (RAID) device"));
  printf ("%-20s ", "memsize");
  printf (_("alias for '%s'"), "set-memsize");
  putchar ('\n');
  printf ("%-20s %s\n", "mkdir", _("create a directory"));
  printf ("%-20s %s\n", "mkdir-mode", _("create a directory with a particular mode"));
  printf ("%-20s %s\n", "mkdir-p", _("create a directory and parents"));
  printf ("%-20s %s\n", "mkdtemp", _("create a temporary directory"));
  printf ("%-20s %s\n", "mke2fs", _("create an ext2/ext3/ext4 filesystem on device"));
  printf ("%-20s %s\n", "mke2fs-J", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2fs-JL", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2fs-JU", _("make ext2/3/4 filesystem with external journal"));
  printf ("%-20s %s\n", "mke2journal", _("make ext2/3/4 external journal"));
  printf ("%-20s %s\n", "mke2journal-L", _("make ext2/3/4 external journal with label"));
  printf ("%-20s %s\n", "mke2journal-U", _("make ext2/3/4 external journal with UUID"));
  printf ("%-20s %s\n", "mkfifo", _("make FIFO (named pipe)"));
  printf ("%-20s %s\n", "mkfs", _("make a filesystem"));
  printf ("%-20s %s\n", "mkfs-b", _("make a filesystem with block size"));
  printf ("%-20s %s\n", "mkfs-btrfs", _("create a btrfs filesystem"));
  printf ("%-20s %s\n", "mklost-and-found", _("make lost+found directory on an ext2/3/4 filesystem"));
  printf ("%-20s %s\n", "mkmountpoint", _("create a mountpoint"));
  printf ("%-20s %s\n", "mknod", _("make block, character or FIFO devices"));
  printf ("%-20s %s\n", "mknod-b", _("make block device node"));
  printf ("%-20s %s\n", "mknod-c", _("make char device node"));
  printf ("%-20s %s\n", "mksquashfs", _("create a squashfs filesystem"));
  printf ("%-20s %s\n", "mkswap", _("create a swap partition"));
  printf ("%-20s %s\n", "mkswap-L", _("create a swap partition with a label"));
  printf ("%-20s %s\n", "mkswap-U", _("create a swap partition with an explicit UUID"));
  printf ("%-20s %s\n", "mkswap-file", _("create a swap file"));
  printf ("%-20s %s\n", "mktemp", _("create a temporary file"));
  printf ("%-20s %s\n", "modprobe", _("load a kernel module"));
  printf ("%-20s %s\n", "more", _("view a file"));
  printf ("%-20s %s\n", "mount", _("mount a guest disk at a position in the filesystem"));
  printf ("%-20s %s\n", "mount-9p", _("mount 9p filesystem"));
  printf ("%-20s %s\n", "mount-local", _("mount on the local filesystem"));
  printf ("%-20s %s\n", "mount-local-run", _("run main loop of mount on the local filesystem"));
  printf ("%-20s %s\n", "mount-loop", _("mount a file using the loop device"));
  printf ("%-20s %s\n", "mount-options", _("mount a guest disk with mount options"));
  printf ("%-20s %s\n", "mount-ro", _("mount a guest disk, read-only"));
  printf ("%-20s %s\n", "mount-vfs", _("mount a guest disk with mount options and vfstype"));
  printf ("%-20s %s\n", "mountable-device", _("extract the device part of a mountable"));
  printf ("%-20s %s\n", "mountable-subvolume", _("extract the subvolume part of a mountable"));
  printf ("%-20s %s\n", "mountpoints", _("show mountpoints"));
  printf ("%-20s %s\n", "mounts", _("show mounted filesystems"));
  printf ("%-20s %s\n", "mv", _("move a file"));
  printf ("%-20s ", "network");
  printf (_("alias for '%s'"), "set-network");
  putchar ('\n');
  printf ("%-20s %s\n", "nr-devices", _("return number of whole block devices (disks) added"));
  printf ("%-20s %s\n", "ntfs-3g-probe", _("probe NTFS volume"));
  printf ("%-20s %s\n", "ntfscat-i", _("download a file to the local machine given its inode"));
  printf ("%-20s %s\n", "ntfsclone-in", _("restore NTFS from backup file"));
  printf ("%-20s %s\n", "ntfsclone-out", _("save NTFS to backup file"));
  printf ("%-20s %s\n", "ntfsfix", _("fix common errors and force Windows to check NTFS"));
  printf ("%-20s %s\n", "ntfsresize", _("resize an NTFS filesystem"));
  printf ("%-20s %s\n", "ntfsresize-size", _("resize an NTFS filesystem (with size)"));
  printf ("%-20s %s\n", "parse-environment", _("parse the environment and set handle flags accordingly"));
  printf ("%-20s %s\n", "parse-environment-list", _("parse the environment and set handle flags accordingly"));
  printf ("%-20s %s\n", "part-add", _("add a partition to the device"));
  printf ("%-20s %s\n", "part-del", _("delete a partition"));
  printf ("%-20s %s\n", "part-disk", _("partition whole disk with a single primary partition"));
  printf ("%-20s %s\n", "part-expand-gpt", _("move backup GPT header to the end of the disk"));
  printf ("%-20s %s\n", "part-get-bootable", _("return true if a partition is bootable"));
  printf ("%-20s %s\n", "part-get-disk-guid", _("get the GUID of a GPT-partitioned disk"));
  printf ("%-20s %s\n", "part-get-gpt-attributes", _("get the attribute flags of a GPT partition"));
  printf ("%-20s %s\n", "part-get-gpt-guid", _("get the GUID of a GPT partition"));
  printf ("%-20s %s\n", "part-get-gpt-type", _("get the type GUID of a GPT partition"));
  printf ("%-20s %s\n", "part-get-mbr-id", _("get the MBR type byte (ID byte) from a partition"));
  printf ("%-20s %s\n", "part-get-mbr-part-type", _("get the MBR partition type"));
  printf ("%-20s %s\n", "part-get-name", _("get partition name"));
  printf ("%-20s %s\n", "part-get-parttype", _("get the partition table type"));
  printf ("%-20s %s\n", "part-init", _("create an empty partition table"));
  printf ("%-20s %s\n", "part-list", _("list partitions on a device"));
  printf ("%-20s %s\n", "part-resize", _("resize a partition"));
  printf ("%-20s %s\n", "part-set-bootable", _("make a partition bootable"));
  printf ("%-20s %s\n", "part-set-disk-guid", _("set the GUID of a GPT-partitioned disk"));
  printf ("%-20s %s\n", "part-set-disk-guid-random", _("set the GUID of a GPT-partitioned disk to random value"));
  printf ("%-20s %s\n", "part-set-gpt-attributes", _("set the attribute flags of a GPT partition"));
  printf ("%-20s %s\n", "part-set-gpt-guid", _("set the GUID of a GPT partition"));
  printf ("%-20s %s\n", "part-set-gpt-type", _("set the type GUID of a GPT partition"));
  printf ("%-20s %s\n", "part-set-mbr-id", _("set the MBR type byte (ID byte) of a partition"));
  printf ("%-20s %s\n", "part-set-name", _("set partition name"));
  printf ("%-20s %s\n", "part-to-dev", _("convert partition name to device name"));
  printf ("%-20s %s\n", "part-to-partnum", _("convert partition name to partition number"));
  printf ("%-20s ", "path");
  printf (_("alias for '%s'"), "set-path");
  putchar ('\n');
  printf ("%-20s ", "pgroup");
  printf (_("alias for '%s'"), "set-pgroup");
  putchar ('\n');
  printf ("%-20s ", "pid");
  printf (_("alias for '%s'"), "get-pid");
  putchar ('\n');
  printf ("%-20s %s\n", "ping-daemon", _("ping the guest daemon"));
  printf ("%-20s %s\n", "pread", _("read part of a file"));
  printf ("%-20s %s\n", "pread-device", _("read part of a device"));
  printf ("%-20s ", "program");
  printf (_("alias for '%s'"), "set-program");
  putchar ('\n');
  printf ("%-20s %s\n", "pvchange-uuid", _("generate a new random UUID for a physical volume"));
  printf ("%-20s %s\n", "pvchange-uuid-all", _("generate new random UUIDs for all physical volumes"));
  printf ("%-20s %s\n", "pvcreate", _("create an LVM physical volume"));
  printf ("%-20s %s\n", "pvremove", _("remove an LVM physical volume"));
  printf ("%-20s %s\n", "pvresize", _("resize an LVM physical volume"));
  printf ("%-20s %s\n", "pvresize-size", _("resize an LVM physical volume (with size)"));
  printf ("%-20s %s\n", "pvs", _("list the LVM physical volumes (PVs)"));
  printf ("%-20s %s\n", "pvs-full", _("list the LVM physical volumes (PVs)"));
  printf ("%-20s %s\n", "pvuuid", _("get the UUID of a physical volume"));
  printf ("%-20s %s\n", "pwrite", _("write to part of a file"));
  printf ("%-20s %s\n", "pwrite-device", _("write to part of a device"));
  printf ("%-20s ", "qemu");
  printf (_("alias for '%s'"), "set-qemu");
  putchar ('\n');
  printf ("%-20s %s\n", "read-file", _("read a file"));
  printf ("%-20s %s\n", "read-lines", _("read file as lines"));
  printf ("%-20s %s\n", "readdir", _("read directories entries"));
  printf ("%-20s %s\n", "readlink", _("read the target of a symbolic link"));
  printf ("%-20s %s\n", "readlinklist", _("readlink on multiple files"));
  printf ("%-20s %s\n", "realpath", _("canonicalized absolute pathname"));
  printf ("%-20s ", "recovery-proc");
  printf (_("alias for '%s'"), "set-recovery-proc");
  putchar ('\n');
  printf ("%-20s %s\n", "remount", _("remount a filesystem with different options"));
  printf ("%-20s %s\n", "remove-drive", _("remove a disk image"));
  printf ("%-20s %s\n", "removexattr", _("remove extended attribute of a file or directory"));
  printf ("%-20s %s\n", "rename", _("rename a file on the same filesystem"));
  printf ("%-20s %s\n", "reopen", _("close and reopen libguestfs handle"));
  printf ("%-20s %s\n", "resize2fs", _("resize an ext2, ext3 or ext4 filesystem"));
  printf ("%-20s %s\n", "resize2fs-M", _("resize an ext2, ext3 or ext4 filesystem to the minimum size"));
  printf ("%-20s %s\n", "resize2fs-size", _("resize an ext2, ext3 or ext4 filesystem (with size)"));
  printf ("%-20s %s\n", "rm", _("remove a file"));
  printf ("%-20s %s\n", "rm-f", _("remove a file ignoring errors"));
  printf ("%-20s %s\n", "rm-rf", _("remove a file or directory recursively"));
  printf ("%-20s %s\n", "rmdir", _("remove a directory"));
  printf ("%-20s %s\n", "rmmountpoint", _("remove a mountpoint"));
  printf ("%-20s %s\n", "rsync", _("synchronize the contents of two directories"));
  printf ("%-20s %s\n", "rsync-in", _("synchronize host or remote filesystem with filesystem"));
  printf ("%-20s %s\n", "rsync-out", _("synchronize filesystem with host or remote filesystem"));
  printf ("%-20s ", "run");
  printf (_("alias for '%s'"), "launch");
  putchar ('\n');
  printf ("%-20s ", "scratch");
  printf (_("alias for '%s'"), "add-drive-scratch");
  putchar ('\n');
  printf ("%-20s %s\n", "scrub-device", _("scrub (securely wipe) a device"));
  printf ("%-20s %s\n", "scrub-file", _("scrub (securely wipe) a file"));
  printf ("%-20s %s\n", "scrub-freespace", _("scrub (securely wipe) free space"));
  printf ("%-20s ", "selinux");
  printf (_("alias for '%s'"), "set-selinux");
  putchar ('\n');
  printf ("%-20s %s\n", "selinux-relabel", _("relabel parts of the filesystem"));
  printf ("%-20s %s\n", "set-append", _("add options to kernel command line"));
  printf ("%-20s %s\n", "set-attach-method", _("set the backend"));
  printf ("%-20s %s\n", "set-autosync", _("set autosync mode"));
  printf ("%-20s %s\n", "set-backend", _("set the backend"));
  printf ("%-20s %s\n", "set-backend-setting", _("set a single per-backend settings string"));
  printf ("%-20s %s\n", "set-backend-settings", _("replace per-backend settings strings"));
  printf ("%-20s %s\n", "set-cachedir", _("set the appliance cache directory"));
  printf ("%-20s %s\n", "set-direct", _("enable or disable direct appliance mode"));
  printf ("%-20s %s\n", "set-e2attrs", _("set ext2 file attributes of a file"));
  printf ("%-20s %s\n", "set-e2generation", _("set ext2 file generation of a file"));
  printf ("%-20s %s\n", "set-e2label", _("set the ext2/3/4 filesystem label"));
  printf ("%-20s %s\n", "set-e2uuid", _("set the ext2/3/4 filesystem UUID"));
  printf ("%-20s %s\n", "set-hv", _("set the hypervisor binary"));
  printf ("%-20s %s\n", "set-identifier", _("set the handle identifier"));
  printf ("%-20s %s\n", "set-label", _("set filesystem label"));
  printf ("%-20s %s\n", "set-libvirt-requested-credential", _("pass requested credential back to libvirt"));
  printf ("%-20s %s\n", "set-libvirt-supported-credentials", _("set libvirt credentials supported by calling program"));
  printf ("%-20s %s\n", "set-memsize", _("set memory allocated to the hypervisor"));
  printf ("%-20s %s\n", "set-network", _("set enable network flag"));
  printf ("%-20s %s\n", "set-path", _("set the search path"));
  printf ("%-20s %s\n", "set-pgroup", _("set process group flag"));
  printf ("%-20s %s\n", "set-program", _("set the program name"));
  printf ("%-20s %s\n", "set-qemu", _("set the hypervisor binary (usually qemu)"));
  printf ("%-20s %s\n", "set-recovery-proc", _("enable or disable the recovery process"));
  printf ("%-20s %s\n", "set-selinux", _("set SELinux enabled or disabled at appliance boot"));
  printf ("%-20s %s\n", "set-smp", _("set number of virtual CPUs in appliance"));
  printf ("%-20s %s\n", "set-tmpdir", _("set the temporary directory"));
  printf ("%-20s %s\n", "set-trace", _("enable or disable command traces"));
  printf ("%-20s %s\n", "set-uuid", _("set the filesystem UUID"));
  printf ("%-20s %s\n", "set-uuid-random", _("set a random UUID for the filesystem"));
  printf ("%-20s %s\n", "set-verbose", _("set verbose mode"));
  printf ("%-20s %s\n", "setcon", _("set SELinux security context"));
  printf ("%-20s %s\n", "setenv", _("set an environment variable"));
  printf ("%-20s %s\n", "setxattr", _("set extended attribute of a file or directory"));
  printf ("%-20s %s\n", "sfdisk", _("create partitions on a block device"));
  printf ("%-20s %s\n", "sfdiskM", _("create partitions on a block device"));
  printf ("%-20s %s\n", "sfdisk-N", _("modify a single partition on a block device"));
  printf ("%-20s %s\n", "sfdisk-disk-geometry", _("display the disk geometry from the partition table"));
  printf ("%-20s %s\n", "sfdisk-kernel-geometry", _("display the kernel geometry"));
  printf ("%-20s %s\n", "sfdisk-l", _("display the partition table"));
  printf ("%-20s %s\n", "sh", _("run a command via the shell"));
  printf ("%-20s %s\n", "sh-lines", _("run a command via the shell returning lines"));
  printf ("%-20s %s\n", "shutdown", _("shutdown the hypervisor"));
  printf ("%-20s %s\n", "sleep", _("sleep for some seconds"));
  printf ("%-20s ", "smp");
  printf (_("alias for '%s'"), "set-smp");
  putchar ('\n');
  printf ("%-20s %s\n", "sparse", _("create a sparse disk image and add"));
  printf ("%-20s %s\n", "stat", _("get file information"));
  printf ("%-20s %s\n", "statns", _("get file information"));
  printf ("%-20s %s\n", "statvfs", _("get file system statistics"));
  printf ("%-20s %s\n", "strings", _("print the printable strings in a file"));
  printf ("%-20s %s\n", "strings-e", _("print the printable strings in a file"));
  printf ("%-20s %s\n", "supported", _("list supported groups of commands"));
  printf ("%-20s %s\n", "swapoff-device", _("disable swap on device"));
  printf ("%-20s %s\n", "swapoff-file", _("disable swap on file"));
  printf ("%-20s %s\n", "swapoff-label", _("disable swap on labeled swap partition"));
  printf ("%-20s %s\n", "swapoff-uuid", _("disable swap on swap partition by UUID"));
  printf ("%-20s %s\n", "swapon-device", _("enable swap on device"));
  printf ("%-20s %s\n", "swapon-file", _("enable swap on file"));
  printf ("%-20s %s\n", "swapon-label", _("enable swap on labeled swap partition"));
  printf ("%-20s %s\n", "swapon-uuid", _("enable swap on swap partition by UUID"));
  printf ("%-20s %s\n", "sync", _("sync disks, writes are flushed through to the disk image"));
  printf ("%-20s %s\n", "syslinux", _("install the SYSLINUX bootloader"));
  printf ("%-20s %s\n", "tail", _("return last 10 lines of a file"));
  printf ("%-20s %s\n", "tail-n", _("return last N lines of a file"));
  printf ("%-20s %s\n", "tar-in", _("unpack tarfile to directory"));
  printf ("%-20s %s\n", "tar-out", _("pack directory into tarfile"));
  printf ("%-20s %s\n", "tgz-in", _("unpack compressed tarball to directory"));
  printf ("%-20s %s\n", "tgz-out", _("pack directory into compressed tarball"));
  printf ("%-20s %s\n", "time", _("print elapsed time taken to run a command"));
  printf ("%-20s ", "tmpdir");
  printf (_("alias for '%s'"), "set-tmpdir");
  putchar ('\n');
  printf ("%-20s %s\n", "touch", _("update file timestamps or create a new file"));
  printf ("%-20s ", "trace");
  printf (_("alias for '%s'"), "set-trace");
  putchar ('\n');
  printf ("%-20s %s\n", "truncate", _("truncate a file to zero size"));
  printf ("%-20s %s\n", "truncate-size", _("truncate a file to a particular size"));
  printf ("%-20s %s\n", "tune2fs", _("adjust ext2/ext3/ext4 filesystem parameters"));
  printf ("%-20s %s\n", "tune2fs-l", _("get ext2/ext3/ext4 superblock details"));
  printf ("%-20s %s\n", "txz-in", _("unpack compressed tarball to directory"));
  printf ("%-20s %s\n", "txz-out", _("pack directory into compressed tarball"));
  printf ("%-20s %s\n", "umask", _("set file mode creation mask (umask)"));
  printf ("%-20s %s\n", "umount", _("unmount a filesystem"));
  printf ("%-20s %s\n", "umount-all", _("unmount all filesystems"));
  printf ("%-20s %s\n", "umount-local", _("unmount a locally mounted filesystem"));
  printf ("%-20s ", "unmount");
  printf (_("alias for '%s'"), "umount");
  putchar ('\n');
  printf ("%-20s ", "unmount-all");
  printf (_("alias for '%s'"), "umount-all");
  putchar ('\n');
  printf ("%-20s %s\n", "unsetenv", _("unset an environment variable"));
  printf ("%-20s %s\n", "upload", _("upload a file from the local machine"));
  printf ("%-20s %s\n", "upload-offset", _("upload a file from the local machine with offset"));
  printf ("%-20s %s\n", "user-cancel", _("cancel the current upload or download operation"));
  printf ("%-20s %s\n", "utimens", _("set timestamp of a file with nanosecond precision"));
  printf ("%-20s %s\n", "utsname", _("appliance kernel version"));
  printf ("%-20s ", "verbose");
  printf (_("alias for '%s'"), "set-verbose");
  putchar ('\n');
  printf ("%-20s %s\n", "version", _("get the library version number"));
  printf ("%-20s %s\n", "vfs-label", _("get the filesystem label"));
  printf ("%-20s %s\n", "vfs-minimum-size", _("get minimum filesystem size"));
  printf ("%-20s %s\n", "vfs-type", _("get the Linux VFS type corresponding to a mounted device"));
  printf ("%-20s %s\n", "vfs-uuid", _("get the filesystem UUID"));
  printf ("%-20s %s\n", "vg-activate", _("activate or deactivate some volume groups"));
  printf ("%-20s %s\n", "vg-activate-all", _("activate or deactivate all volume groups"));
  printf ("%-20s %s\n", "vgchange-uuid", _("generate a new random UUID for a volume group"));
  printf ("%-20s %s\n", "vgchange-uuid-all", _("generate new random UUIDs for all volume groups"));
  printf ("%-20s %s\n", "vgcreate", _("create an LVM volume group"));
  printf ("%-20s %s\n", "vglvuuids", _("get the LV UUIDs of all LVs in the volume group"));
  printf ("%-20s %s\n", "vgmeta", _("get volume group metadata"));
  printf ("%-20s %s\n", "vgpvuuids", _("get the PV UUIDs containing the volume group"));
  printf ("%-20s %s\n", "vgremove", _("remove an LVM volume group"));
  printf ("%-20s %s\n", "vgrename", _("rename an LVM volume group"));
  printf ("%-20s %s\n", "vgs", _("list the LVM volume groups (VGs)"));
  printf ("%-20s %s\n", "vgs-full", _("list the LVM volume groups (VGs)"));
  printf ("%-20s %s\n", "vgscan", _("rescan for LVM physical volumes, volume groups and logical volumes"));
  printf ("%-20s %s\n", "vguuid", _("get the UUID of a volume group"));
  printf ("%-20s ", "vi");
  printf (_("alias for '%s'"), "edit");
  putchar ('\n');
  printf ("%-20s %s\n", "wc-c", _("count characters in a file"));
  printf ("%-20s %s\n", "wc-l", _("count lines in a file"));
  printf ("%-20s %s\n", "wc-w", _("count words in a file"));
  printf ("%-20s %s\n", "wipefs", _("wipe a filesystem signature from a device"));
  printf ("%-20s %s\n", "write", _("create a new file"));
  printf ("%-20s %s\n", "write-append", _("append content to end of file"));
  printf ("%-20s %s\n", "write-file", _("create a file"));
  printf ("%-20s %s\n", "xfs-admin", _("change parameters of an XFS filesystem"));
  printf ("%-20s %s\n", "xfs-growfs", _("expand an existing XFS filesystem"));
  printf ("%-20s %s\n", "xfs-info", _("get geometry of XFS filesystem"));
  printf ("%-20s %s\n", "xfs-repair", _("repair an XFS filesystem"));
  printf ("%-20s %s\n", "yara-destroy", _("destroy previously loaded yara rules"));
  printf ("%-20s %s\n", "yara-load", _("load yara rules within libguestfs"));
  printf ("%-20s %s\n", "yara-scan", _("scan a file with the loaded yara rules"));
  printf ("%-20s %s\n", "zegrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zegrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zero", _("write zeroes to the device"));
  printf ("%-20s %s\n", "zero-device", _("write zeroes to an entire device"));
  printf ("%-20s %s\n", "zero-free-space", _("zero free space in a filesystem"));
  printf ("%-20s %s\n", "zerofree", _("zero unused inodes and disk blocks on ext2/3 filesystem"));
  printf ("%-20s %s\n", "zfgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zfgrepi", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zfile", _("determine file type inside a compressed file"));
  printf ("%-20s %s\n", "zgrep", _("return lines matching a pattern"));
  printf ("%-20s %s\n", "zgrepi", _("return lines matching a pattern"));
  printf ("    %s\n",          _("Use -h <cmd> / help <cmd> to show detailed help for a command."));
}

