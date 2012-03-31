# libguestfs generated file
# WARNING: THIS FILE IS GENERATED FROM:
#   generator/generator_*.ml
# ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
#
# Copyright (C) 2009-2012 Red Hat Inc.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

=pod

=head1 NAME

Sys::Guestfs - Perl bindings for libguestfs

=head1 SYNOPSIS

 use Sys::Guestfs;

 my $h = Sys::Guestfs->new ();
 $h->add_drive_opts ('guest.img', format => 'raw');
 $h->launch ();
 $h->mount_options ('', '/dev/sda1', '/');
 $h->touch ('/hello');
 $h->sync ();

=head1 DESCRIPTION

The C<Sys::Guestfs> module provides a Perl XS binding to the
libguestfs API for examining and modifying virtual machine
disk images.

Amongst the things this is good for: making batch configuration
changes to guests, getting disk used/free statistics (see also:
virt-df), migrating between virtualization systems (see also:
virt-p2v), performing partial backups, performing partial guest
clones, cloning guests and changing registry/UUID/hostname info, and
much else besides.

Libguestfs uses Linux kernel and qemu code, and can access any type of
guest filesystem that Linux and qemu can, including but not limited
to: ext2/3/4, btrfs, FAT and NTFS, LVM, many different disk partition
schemes, qcow, qcow2, vmdk.

Libguestfs provides ways to enumerate guest storage (eg. partitions,
LVs, what filesystem is in each LV, etc.).  It can also run commands
in the context of the guest.  Also you can access filesystems over
FUSE.

See also L<Sys::Guestfs::Lib(3)> for a set of useful library
functions for using libguestfs from Perl, including integration
with libvirt.

=head1 ERRORS

All errors turn into calls to C<croak> (see L<Carp(3)>).

The error string from libguestfs is directly available from
C<$@>.  Use the C<last_errno> method if you want to get the errno.

=head1 METHODS

=over 4

=cut

package Sys::Guestfs;

use strict;
use warnings;

# This version number changes whenever a new function
# is added to the libguestfs API.  It is not directly
# related to the libguestfs version number.
use vars qw($VERSION);
$VERSION = '0.304';

require XSLoader;
XSLoader::load ('Sys::Guestfs');

=item $h = Sys::Guestfs->new ();

Create a new guestfs handle.

=cut

sub new {
  my $proto = shift;
  my $class = ref ($proto) || $proto;

  my $g = Sys::Guestfs::_create ();
  my $self = { _g => $g };
  bless $self, $class;
  return $self;
}

=item $h->close ();

Explicitly close the guestfs handle.

B<Note:> You should not usually call this function.  The handle will
be closed implicitly when its reference count goes to zero (eg.
when it goes out of scope or the program ends).  This call is
only required in some exceptional cases, such as where the program
may contain cached references to the handle 'somewhere' and you
really have to have the close happen right away.  After calling
C<close> the program must not call any method (including C<close>)
on the handle (but the implicit call to C<DESTROY> that happens
when the final reference is cleaned up is OK).

=item $Sys::Guestfs::EVENT_CLOSE

See L<guestfs(3)/GUESTFS_EVENT_CLOSE>.

=cut

our $EVENT_CLOSE = 0x1;

=item $Sys::Guestfs::EVENT_SUBPROCESS_QUIT

See L<guestfs(3)/GUESTFS_EVENT_SUBPROCESS_QUIT>.

=cut

our $EVENT_SUBPROCESS_QUIT = 0x2;

=item $Sys::Guestfs::EVENT_LAUNCH_DONE

See L<guestfs(3)/GUESTFS_EVENT_LAUNCH_DONE>.

=cut

our $EVENT_LAUNCH_DONE = 0x4;

=item $Sys::Guestfs::EVENT_PROGRESS

See L<guestfs(3)/GUESTFS_EVENT_PROGRESS>.

=cut

our $EVENT_PROGRESS = 0x8;

=item $Sys::Guestfs::EVENT_APPLIANCE

See L<guestfs(3)/GUESTFS_EVENT_APPLIANCE>.

=cut

our $EVENT_APPLIANCE = 0x10;

=item $Sys::Guestfs::EVENT_LIBRARY

See L<guestfs(3)/GUESTFS_EVENT_LIBRARY>.

=cut

our $EVENT_LIBRARY = 0x20;

=item $Sys::Guestfs::EVENT_TRACE

See L<guestfs(3)/GUESTFS_EVENT_TRACE>.

=cut

our $EVENT_TRACE = 0x40;

=item $Sys::Guestfs::EVENT_ENTER

See L<guestfs(3)/GUESTFS_EVENT_ENTER>.

=cut

our $EVENT_ENTER = 0x80;

=item $event_handle = $h->set_event_callback (\&cb, $event_bitmask);

Register C<cb> as a callback function for all of the events
in C<$event_bitmask> (one or more C<$Sys::Guestfs::EVENT_*> flags
logically or'd together).

This function returns an event handle which
can be used to delete the callback using C<delete_event_callback>.

The callback function receives 4 parameters:

 &cb ($event, $event_handle, $buf, $array)

=over 4

=item $event

The event which happened (equal to one of C<$Sys::Guestfs::EVENT_*>).

=item $event_handle

The event handle.

=item $buf

For some event types, this is a message buffer (ie. a string).

=item $array

For some event types (notably progress events), this is
an array of integers.

=back

You should carefully read the documentation for
L<guestfs(3)/guestfs_set_event_callback> before using
this function.

=item $h->delete_event_callback ($event_handle);

This removes the callback which was previously registered using
C<set_event_callback>.

=item $errnum = $h->last_errno ();

This returns the last error number (errno) that happened on the
handle C<$h>.

If successful, an errno integer not equal to zero is returned.

If no error number is available, this returns 0.
See L<guestfs(3)/guestfs_last_errno> for more details of why
this can happen.

You can use the standard Perl module L<Errno(3)> to compare
the numeric error returned from this call with symbolic
errnos:

 $h->mkdir ("/foo");
 if ($h->last_errno() == Errno::EEXIST()) {
   # mkdir failed because the directory exists already.
 }

=item $h->user_cancel ();

Cancel current transfer.  This is safe to call from Perl signal
handlers and threads.

=cut

=item $h->add_cdrom ($filename);

This function adds a virtual CD-ROM disk image to the guest.

This is equivalent to the qemu parameter I<-cdrom filename>.

Notes:

=over 4

=item *

This call checks for the existence of C<filename>.  This
stops you from specifying other types of drive which are supported
by qemu such as C<nbd:> and C<http:> URLs.  To specify those, use
the general C<$h-E<gt>config> call instead.

=item *

If you just want to add an ISO file (often you use this as an
efficient way to transfer large files into the guest), then you
should probably use C<$h-E<gt>add_drive_ro> instead.

=back

I<This function is deprecated.>
In new code, use the L</add_drive_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $nrdisks = $h->add_domain ($dom [, libvirturi => $libvirturi] [, readonly => $readonly] [, iface => $iface] [, live => $live] [, allowuuid => $allowuuid] [, readonlydisk => $readonlydisk]);

This function adds the disk(s) attached to the named libvirt
domain C<dom>.  It works by connecting to libvirt, requesting
the domain and domain XML from libvirt, parsing it for disks,
and calling C<$h-E<gt>add_drive_opts> on each one.

The number of disks added is returned.  This operation is atomic:
if an error is returned, then no disks are added.

This function does some minimal checks to make sure the libvirt
domain is not running (unless C<readonly> is true).  In a future
version we will try to acquire the libvirt lock on each disk.

Disks must be accessible locally.  This often means that adding disks
from a remote libvirt connection (see L<http://libvirt.org/remote.html>)
will fail unless those disks are accessible via the same device path
locally too.

The optional C<libvirturi> parameter sets the libvirt URI
(see L<http://libvirt.org/uri.html>).  If this is not set then
we connect to the default libvirt URI (or one set through an
environment variable, see the libvirt documentation for full
details).

The optional C<live> flag controls whether this call will try
to connect to a running virtual machine C<guestfsd> process if
it sees a suitable E<lt>channelE<gt> element in the libvirt
XML definition.  The default (if the flag is omitted) is never
to try.  See L<guestfs(3)/ATTACHING TO RUNNING DAEMONS> for more
information.

If the C<allowuuid> flag is true (default is false) then a UUID
I<may> be passed instead of the domain name.  The C<dom> string is
treated as a UUID first and looked up, and if that lookup fails
then we treat C<dom> as a name as usual.

The optional C<readonlydisk> parameter controls what we do for
disks which are marked E<lt>readonly/E<gt> in the libvirt XML.
Possible values are:

=over 4

=item readonlydisk = "error"

If C<readonly> is false:

The whole call is aborted with an error if any disk with
the E<lt>readonly/E<gt> flag is found.

If C<readonly> is true:

Disks with the E<lt>readonly/E<gt> flag are added read-only.

=item readonlydisk = "read"

If C<readonly> is false:

Disks with the E<lt>readonly/E<gt> flag are added read-only.
Other disks are added read/write.

If C<readonly> is true:

Disks with the E<lt>readonly/E<gt> flag are added read-only.

=item readonlydisk = "write" (default)

If C<readonly> is false:

Disks with the E<lt>readonly/E<gt> flag are added read/write.

If C<readonly> is true:

Disks with the E<lt>readonly/E<gt> flag are added read-only.

=item readonlydisk = "ignore"

If C<readonly> is true or false:

Disks with the E<lt>readonly/E<gt> flag are skipped.

=back

The other optional parameters are passed directly through to
C<$h-E<gt>add_drive_opts>.

=item $h->add_drive ($filename);

This function is the equivalent of calling C<$h-E<gt>add_drive_opts>
with no optional parameters, so the disk is added writable, with
the format being detected automatically.

Automatic detection of the format opens you up to a potential
security hole when dealing with untrusted raw-format images.
See CVE-2010-3851 and RHBZ#642934.  Specifying the format closes
this security hole.  Therefore you should think about replacing
calls to this function with calls to C<$h-E<gt>add_drive_opts>,
and specifying the format.

=item $h->add_drive_opts ($filename [, readonly => $readonly] [, format => $format] [, iface => $iface] [, name => $name]);

This function adds a virtual machine disk image C<filename> to
libguestfs.  The first time you call this function, the disk
appears as C</dev/sda>, the second time as C</dev/sdb>, and
so on.

You don't necessarily need to be root when using libguestfs.  However
you obviously do need sufficient permissions to access the filename
for whatever operations you want to perform (ie. read access if you
just want to read the image or write access if you want to modify the
image).

This call checks that C<filename> exists.

The optional arguments are:

=over 4

=item C<readonly>

If true then the image is treated as read-only.  Writes are still
allowed, but they are stored in a temporary snapshot overlay which
is discarded at the end.  The disk that you add is not modified.

=item C<format>

This forces the image format.  If you omit this (or use C<$h-E<gt>add_drive>
or C<$h-E<gt>add_drive_ro>) then the format is automatically detected.
Possible formats include C<raw> and C<qcow2>.

Automatic detection of the format opens you up to a potential
security hole when dealing with untrusted raw-format images.
See CVE-2010-3851 and RHBZ#642934.  Specifying the format closes
this security hole.

=item C<iface>

This rarely-used option lets you emulate the behaviour of the
deprecated C<$h-E<gt>add_drive_with_if> call (q.v.)

=item C<name>

The name the drive had in the original guest, e.g. /dev/sdb. This is used as a
hint to the guest inspection process if it is available.

=back

=item $h->add_drive_ro ($filename);

This function is the equivalent of calling C<$h-E<gt>add_drive_opts>
with the optional parameter C<GUESTFS_ADD_DRIVE_OPTS_READONLY> set to 1,
so the disk is added read-only, with the format being detected
automatically.

=item $h->add_drive_ro_with_if ($filename, $iface);

This is the same as C<$h-E<gt>add_drive_ro> but it allows you
to specify the QEMU interface emulation to use at run time.

I<This function is deprecated.>
In new code, use the L</add_drive_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->add_drive_with_if ($filename, $iface);

This is the same as C<$h-E<gt>add_drive> but it allows you
to specify the QEMU interface emulation to use at run time.

I<This function is deprecated.>
In new code, use the L</add_drive_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->aug_clear ($augpath);

Set the value associated with C<path> to C<NULL>.  This
is the same as the L<augtool(1)> C<clear> command.

=item $h->aug_close ();

Close the current Augeas handle and free up any resources
used by it.  After calling this, you have to call
C<$h-E<gt>aug_init> again before you can use any other
Augeas functions.

=item %nrnodescreated = $h->aug_defnode ($name, $expr, $val);

Defines a variable C<name> whose value is the result of
evaluating C<expr>.

If C<expr> evaluates to an empty nodeset, a node is created,
equivalent to calling C<$h-E<gt>aug_set> C<expr>, C<value>.
C<name> will be the nodeset containing that single node.

On success this returns a pair containing the
number of nodes in the nodeset, and a boolean flag
if a node was created.

=item $nrnodes = $h->aug_defvar ($name, $expr);

Defines an Augeas variable C<name> whose value is the result
of evaluating C<expr>.  If C<expr> is NULL, then C<name> is
undefined.

On success this returns the number of nodes in C<expr>, or
C<0> if C<expr> evaluates to something which is not a nodeset.

=item $val = $h->aug_get ($augpath);

Look up the value associated with C<path>.  If C<path>
matches exactly one node, the C<value> is returned.

=item $h->aug_init ($root, $flags);

Create a new Augeas handle for editing configuration files.
If there was any previous Augeas handle associated with this
guestfs session, then it is closed.

You must call this before using any other C<$h-E<gt>aug_*>
commands.

C<root> is the filesystem root.  C<root> must not be NULL,
use C</> instead.

The flags are the same as the flags defined in
E<lt>augeas.hE<gt>, the logical I<or> of the following
integers:

=over 4

=item C<AUG_SAVE_BACKUP> = 1

Keep the original file with a C<.augsave> extension.

=item C<AUG_SAVE_NEWFILE> = 2

Save changes into a file with extension C<.augnew>, and
do not overwrite original.  Overrides C<AUG_SAVE_BACKUP>.

=item C<AUG_TYPE_CHECK> = 4

Typecheck lenses.

This option is only useful when debugging Augeas lenses.  Use
of this option may require additional memory for the libguestfs
appliance.  You may need to set the C<LIBGUESTFS_MEMSIZE>
environment variable or call C<$h-E<gt>set_memsize>.

=item C<AUG_NO_STDINC> = 8

Do not use standard load path for modules.

=item C<AUG_SAVE_NOOP> = 16

Make save a no-op, just record what would have been changed.

=item C<AUG_NO_LOAD> = 32

Do not load the tree in C<$h-E<gt>aug_init>.

=back

To close the handle, you can call C<$h-E<gt>aug_close>.

To find out more about Augeas, see L<http://augeas.net/>.

=item $h->aug_insert ($augpath, $label, $before);

Create a new sibling C<label> for C<path>, inserting it into
the tree before or after C<path> (depending on the boolean
flag C<before>).

C<path> must match exactly one existing node in the tree, and
C<label> must be a label, ie. not contain C</>, C<*> or end
with a bracketed index C<[N]>.

=item $h->aug_load ();

Load files into the tree.

See C<aug_load> in the Augeas documentation for the full gory
details.

=item @matches = $h->aug_ls ($augpath);

This is just a shortcut for listing C<$h-E<gt>aug_match>
C<path/*> and sorting the resulting nodes into alphabetical order.

=item @matches = $h->aug_match ($augpath);

Returns a list of paths which match the path expression C<path>.
The returned paths are sufficiently qualified so that they match
exactly one node in the current tree.

=item $h->aug_mv ($src, $dest);

Move the node C<src> to C<dest>.  C<src> must match exactly
one node.  C<dest> is overwritten if it exists.

=item $nrnodes = $h->aug_rm ($augpath);

Remove C<path> and all of its children.

On success this returns the number of entries which were removed.

=item $h->aug_save ();

This writes all pending changes to disk.

The flags which were passed to C<$h-E<gt>aug_init> affect exactly
how files are saved.

=item $h->aug_set ($augpath, $val);

Set the value associated with C<path> to C<val>.

In the Augeas API, it is possible to clear a node by setting
the value to NULL.  Due to an oversight in the libguestfs API
you cannot do that with this call.  Instead you must use the
C<$h-E<gt>aug_clear> call.

=item $h->available (\@groups);

This command is used to check the availability of some
groups of functionality in the appliance, which not all builds of
the libguestfs appliance will be able to provide.

The libguestfs groups, and the functions that those
groups correspond to, are listed in L<guestfs(3)/AVAILABILITY>.
You can also fetch this list at runtime by calling
C<$h-E<gt>available_all_groups>.

The argument C<groups> is a list of group names, eg:
C<["inotify", "augeas"]> would check for the availability of
the Linux inotify functions and Augeas (configuration file
editing) functions.

The command returns no error if I<all> requested groups are available.

It fails with an error if one or more of the requested
groups is unavailable in the appliance.

If an unknown group name is included in the
list of groups then an error is always returned.

I<Notes:>

=over 4

=item *

You must call C<$h-E<gt>launch> before calling this function.

The reason is because we don't know what groups are
supported by the appliance/daemon until it is running and can
be queried.

=item *

If a group of functions is available, this does not necessarily
mean that they will work.  You still have to check for errors
when calling individual API functions even if they are
available.

=item *

It is usually the job of distro packagers to build
complete functionality into the libguestfs appliance.
Upstream libguestfs, if built from source with all
requirements satisfied, will support everything.

=item *

This call was added in version C<1.0.80>.  In previous
versions of libguestfs all you could do would be to speculatively
execute a command to find out if the daemon implemented it.
See also C<$h-E<gt>version>.

=back

=item @groups = $h->available_all_groups ();

This command returns a list of all optional groups that this
daemon knows about.  Note this returns both supported and unsupported
groups.  To find out which ones the daemon can actually support
you have to call C<$h-E<gt>available> on each member of the
returned list.

See also C<$h-E<gt>available> and L<guestfs(3)/AVAILABILITY>.

=item $h->base64_in ($base64file, $filename);

This command uploads base64-encoded data from C<base64file>
to C<filename>.

=item $h->base64_out ($filename, $base64file);

This command downloads the contents of C<filename>, writing
it out to local file C<base64file> encoded as base64.

=item %info = $h->blkid ($device);

This command returns block device attributes for C<device>. The following fields are
usually present in the returned hash. Other fields may also be present.

=over

=item C<UUID>

The uuid of this device.

=item C<LABEL>

The label of this device.

=item C<VERSION>

The version of blkid command.

=item C<TYPE>

The filesystem type or RAID of this device.

=item C<USAGE>

The usage of this device, for example C<filesystem> or C<raid>.

=back

=item $h->blockdev_flushbufs ($device);

This tells the kernel to flush internal buffers associated
with C<device>.

This uses the L<blockdev(8)> command.

=item $blocksize = $h->blockdev_getbsz ($device);

This returns the block size of a device.

(Note this is different from both I<size in blocks> and
I<filesystem block size>).

This uses the L<blockdev(8)> command.

=item $ro = $h->blockdev_getro ($device);

Returns a boolean indicating if the block device is read-only
(true if read-only, false if not).

This uses the L<blockdev(8)> command.

=item $sizeinbytes = $h->blockdev_getsize64 ($device);

This returns the size of the device in bytes.

See also C<$h-E<gt>blockdev_getsz>.

This uses the L<blockdev(8)> command.

=item $sectorsize = $h->blockdev_getss ($device);

This returns the size of sectors on a block device.
Usually 512, but can be larger for modern devices.

(Note, this is not the size in sectors, use C<$h-E<gt>blockdev_getsz>
for that).

This uses the L<blockdev(8)> command.

=item $sizeinsectors = $h->blockdev_getsz ($device);

This returns the size of the device in units of 512-byte sectors
(even if the sectorsize isn't 512 bytes ... weird).

See also C<$h-E<gt>blockdev_getss> for the real sector size of
the device, and C<$h-E<gt>blockdev_getsize64> for the more
useful I<size in bytes>.

This uses the L<blockdev(8)> command.

=item $h->blockdev_rereadpt ($device);

Reread the partition table on C<device>.

This uses the L<blockdev(8)> command.

=item $h->blockdev_setbsz ($device, $blocksize);

This sets the block size of a device.

(Note this is different from both I<size in blocks> and
I<filesystem block size>).

This uses the L<blockdev(8)> command.

=item $h->blockdev_setro ($device);

Sets the block device named C<device> to read-only.

This uses the L<blockdev(8)> command.

=item $h->blockdev_setrw ($device);

Sets the block device named C<device> to read-write.

This uses the L<blockdev(8)> command.

=item $h->btrfs_filesystem_resize ($mountpoint [, size => $size]);

This command resizes a btrfs filesystem.

Note that unlike other resize calls, the filesystem has to be
mounted and the parameter is the mountpoint not the device
(this is a requirement of btrfs itself).

The optional parameters are:

=over 4

=item C<size>

The new size (in bytes) of the filesystem.  If omitted, the filesystem
is resized to the maximum size.

=back

See also L<btrfs(8)>.

=item $rpath = $h->case_sensitive_path ($path);

This can be used to resolve case insensitive paths on
a filesystem which is case sensitive.  The use case is
to resolve paths which you have read from Windows configuration
files or the Windows Registry, to the true path.

The command handles a peculiarity of the Linux ntfs-3g
filesystem driver (and probably others), which is that although
the underlying filesystem is case-insensitive, the driver
exports the filesystem to Linux as case-sensitive.

One consequence of this is that special directories such
as C<c:\windows> may appear as C</WINDOWS> or C</windows>
(or other things) depending on the precise details of how
they were created.  In Windows itself this would not be
a problem.

Bug or feature?  You decide:
L<http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1>

This function resolves the true case of each element in the
path and returns the case-sensitive path.

Thus C<$h-E<gt>case_sensitive_path> ("/Windows/System32")
might return C<"/WINDOWS/system32"> (the exact return value
would depend on details of how the directories were originally
created under Windows).

I<Note>:
This function does not handle drive names, backslashes etc.

See also C<$h-E<gt>realpath>.

=item $content = $h->cat ($path);

Return the contents of the file named C<path>.

Note that this function cannot correctly handle binary files
(specifically, files containing C<\0> character which is treated
as end of string).  For those you need to use the C<$h-E<gt>read_file>
or C<$h-E<gt>download> functions which have a more complex interface.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $checksum = $h->checksum ($csumtype, $path);

This call computes the MD5, SHAx or CRC checksum of the
file named C<path>.

The type of checksum to compute is given by the C<csumtype>
parameter which must have one of the following values:

=over 4

=item C<crc>

Compute the cyclic redundancy check (CRC) specified by POSIX
for the C<cksum> command.

=item C<md5>

Compute the MD5 hash (using the C<md5sum> program).

=item C<sha1>

Compute the SHA1 hash (using the C<sha1sum> program).

=item C<sha224>

Compute the SHA224 hash (using the C<sha224sum> program).

=item C<sha256>

Compute the SHA256 hash (using the C<sha256sum> program).

=item C<sha384>

Compute the SHA384 hash (using the C<sha384sum> program).

=item C<sha512>

Compute the SHA512 hash (using the C<sha512sum> program).

=back

The checksum is returned as a printable string.

To get the checksum for a device, use C<$h-E<gt>checksum_device>.

To get the checksums for many files, use C<$h-E<gt>checksums_out>.

=item $checksum = $h->checksum_device ($csumtype, $device);

This call computes the MD5, SHAx or CRC checksum of the
contents of the device named C<device>.  For the types of
checksums supported see the C<$h-E<gt>checksum> command.

=item $h->checksums_out ($csumtype, $directory, $sumsfile);

This command computes the checksums of all regular files in
C<directory> and then emits a list of those checksums to
the local output file C<sumsfile>.

This can be used for verifying the integrity of a virtual
machine.  However to be properly secure you should pay
attention to the output of the checksum command (it uses
the ones from GNU coreutils).  In particular when the
filename is not printable, coreutils uses a special
backslash syntax.  For more information, see the GNU
coreutils info file.

=item $h->chmod ($mode, $path);

Change the mode (permissions) of C<path> to C<mode>.  Only
numeric modes are supported.

I<Note>: When using this command from guestfish, C<mode>
by default would be decimal, unless you prefix it with
C<0> to get octal, ie. use C<0700> not C<700>.

The mode actually set is affected by the umask.

=item $h->chown ($owner, $group, $path);

Change the file owner to C<owner> and group to C<group>.

Only numeric uid and gid are supported.  If you want to use
names, you will need to locate and parse the password file
yourself (Augeas support makes this relatively easy).

=item $output = $h->command (\@arguments);

This call runs a command from the guest filesystem.  The
filesystem must be mounted, and must contain a compatible
operating system (ie. something Linux, with the same
or compatible processor architecture).

The single parameter is an argv-style list of arguments.
The first element is the name of the program to run.
Subsequent elements are parameters.  The list must be
non-empty (ie. must contain a program name).  Note that
the command runs directly, and is I<not> invoked via
the shell (see C<$h-E<gt>sh>).

The return value is anything printed to I<stdout> by
the command.

If the command returns a non-zero exit status, then
this function returns an error message.  The error message
string is the content of I<stderr> from the command.

The C<$PATH> environment variable will contain at least
C</usr/bin> and C</bin>.  If you require a program from
another location, you should provide the full path in the
first parameter.

Shared libraries and data files required by the program
must be available on filesystems which are mounted in the
correct places.  It is the caller's responsibility to ensure
all filesystems that are needed are mounted at the right
locations.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->command_lines (\@arguments);

This is the same as C<$h-E<gt>command>, but splits the
result into a list of lines.

See also: C<$h-E<gt>sh_lines>

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->compress_device_out ($ctype, $device, $zdevice [, level => $level]);

This command compresses C<device> and writes it out to the local
file C<zdevice>.

The C<ctype> and optional C<level> parameters have the same meaning
as in C<$h-E<gt>compress_out>.

=item $h->compress_out ($ctype, $file, $zfile [, level => $level]);

This command compresses C<file> and writes it out to the local
file C<zfile>.

The compression program used is controlled by the C<ctype> parameter.
Currently this includes: C<compress>, C<gzip>, C<bzip2>, C<xz> or C<lzop>.
Some compression types may not be supported by particular builds of
libguestfs, in which case you will get an error containing the
substring "not supported".

The optional C<level> parameter controls compression level.  The
meaning and default for this parameter depends on the compression
program being used.

=item $h->config ($qemuparam, $qemuvalue);

This can be used to add arbitrary qemu command line parameters
of the form I<-param value>.  Actually it's not quite arbitrary - we
prevent you from setting some parameters which would interfere with
parameters that we use.

The first character of C<param> string must be a C<-> (dash).

C<value> can be NULL.

=item $h->copy_device_to_device ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size]);

The four calls C<$h-E<gt>copy_device_to_device>,
C<$h-E<gt>copy_device_to_file>,
C<$h-E<gt>copy_file_to_device>, and
C<$h-E<gt>copy_file_to_file>
let you copy from a source (device|file) to a destination
(device|file).

Partial copies can be made since you can specify optionally
the source offset, destination offset and size to copy.  These
values are all specified in bytes.  If not given, the offsets
both default to zero, and the size defaults to copying as much
as possible until we hit the end of the source.

The source and destination may be the same object.  However
overlapping regions may not be copied correctly.

If the destination is a file, it is created if required.  If
the destination file is not large enough, it is extended.

=item $h->copy_device_to_file ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size]);

See C<$h-E<gt>copy_device_to_device> for a general overview
of this call.

=item $h->copy_file_to_device ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size]);

See C<$h-E<gt>copy_device_to_device> for a general overview
of this call.

=item $h->copy_file_to_file ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size]);

See C<$h-E<gt>copy_device_to_device> for a general overview
of this call.

This is B<not> the function you want for copying files.  This
is for copying blocks within existing files.  See C<$h-E<gt>cp>,
C<$h-E<gt>cp_a> and C<$h-E<gt>mv> for general file copying and
moving functions.

=item $h->copy_size ($src, $dest, $size);

This command copies exactly C<size> bytes from one source device
or file C<src> to another destination device or file C<dest>.

Note this will fail if the source is too short or if the destination
is not large enough.

I<This function is deprecated.>
In new code, use the L</copy_device_to_device> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->cp ($src, $dest);

This copies a file from C<src> to C<dest> where C<dest> is
either a destination filename or destination directory.

=item $h->cp_a ($src, $dest);

This copies a file or directory from C<src> to C<dest>
recursively using the C<cp -a> command.

=item $h->dd ($src, $dest);

This command copies from one source device or file C<src>
to another destination device or file C<dest>.  Normally you
would use this to copy to or from a device or partition, for
example to duplicate a filesystem.

If the destination is a device, it must be as large or larger
than the source file or device, otherwise the copy will fail.
This command cannot do partial copies
(see C<$h-E<gt>copy_device_to_device>).

I<This function is deprecated.>
In new code, use the L</copy_device_to_device> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $output = $h->df ();

This command runs the C<df> command to report disk space used.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.
Use C<$h-E<gt>statvfs> from programs.

=item $output = $h->df_h ();

This command runs the C<df -h> command to report disk space used
in human-readable format.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.
Use C<$h-E<gt>statvfs> from programs.

=item $kmsgs = $h->dmesg ();

This returns the kernel messages (C<dmesg> output) from
the guest kernel.  This is sometimes useful for extended
debugging of problems.

Another way to get the same information is to enable
verbose messages with C<$h-E<gt>set_verbose> or by setting
the environment variable C<LIBGUESTFS_DEBUG=1> before
running the program.

=item $h->download ($remotefilename, $filename);

Download file C<remotefilename> and save it as C<filename>
on the local machine.

C<filename> can also be a named pipe.

See also C<$h-E<gt>upload>, C<$h-E<gt>cat>.

=item $h->download_offset ($remotefilename, $filename, $offset, $size);

Download file C<remotefilename> and save it as C<filename>
on the local machine.

C<remotefilename> is read for C<size> bytes starting at C<offset>
(this region must be within the file or device).

Note that there is no limit on the amount of data that
can be downloaded with this call, unlike with C<$h-E<gt>pread>,
and this call always reads the full amount unless an
error occurs.

See also C<$h-E<gt>download>, C<$h-E<gt>pread>.

=item $h->drop_caches ($whattodrop);

This instructs the guest kernel to drop its page cache,
and/or dentries and inode caches.  The parameter C<whattodrop>
tells the kernel what precisely to drop, see
L<http://linux-mm.org/Drop_Caches>

Setting C<whattodrop> to 3 should drop everything.

This automatically calls L<sync(2)> before the operation,
so that the maximum guest memory is freed.

=item $sizekb = $h->du ($path);

This command runs the C<du -s> command to estimate file space
usage for C<path>.

C<path> can be a file or a directory.  If C<path> is a directory
then the estimate includes the contents of the directory and all
subdirectories (recursively).

The result is the estimated size in I<kilobytes>
(ie. units of 1024 bytes).

=item $h->e2fsck ($device [, correct => $correct] [, forceall => $forceall]);

This runs the ext2/ext3 filesystem checker on C<device>.
It can take the following optional arguments:

=over 4

=item C<correct>

Automatically repair the file system. This option will cause e2fsck
to automatically fix any filesystem problems that can be safely
fixed without human intervention.

This option may not be specified at the same time as the C<forceall> option.

=item C<forceall>

Assume an answer of 'yes' to all questions; allows e2fsck to be used
non-interactively.

This option may not be specified at the same time as the C<correct> option.

=back

=item $h->e2fsck_f ($device);

This runs C<e2fsck -p -f device>, ie. runs the ext2/ext3
filesystem checker on C<device>, noninteractively (I<-p>),
even if the filesystem appears to be clean (I<-f>).

This command is only needed because of C<$h-E<gt>resize2fs>
(q.v.).  Normally you should use C<$h-E<gt>fsck>.

=item $output = $h->echo_daemon (\@words);

This command concatenates the list of C<words> passed with single spaces
between them and returns the resulting string.

You can use this command to test the connection through to the daemon.

See also C<$h-E<gt>ping_daemon>.

=item @lines = $h->egrep ($regex, $path);

This calls the external C<egrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->egrepi ($regex, $path);

This calls the external C<egrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $equality = $h->equal ($file1, $file2);

This compares the two files C<file1> and C<file2> and returns
true if their content is exactly equal, or false otherwise.

The external L<cmp(1)> program is used for the comparison.

=item $existsflag = $h->exists ($path);

This returns C<true> if and only if there is a file, directory
(or anything) with the given C<path> name.

See also C<$h-E<gt>is_file>, C<$h-E<gt>is_dir>, C<$h-E<gt>stat>.

=item $h->fallocate ($path, $len);

This command preallocates a file (containing zero bytes) named
C<path> of size C<len> bytes.  If the file exists already, it
is overwritten.

Do not confuse this with the guestfish-specific
C<alloc> command which allocates a file in the host and
attaches it as a device.

I<This function is deprecated.>
In new code, use the L</fallocate64> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->fallocate64 ($path, $len);

This command preallocates a file (containing zero bytes) named
C<path> of size C<len> bytes.  If the file exists already, it
is overwritten.

Note that this call allocates disk blocks for the file.
To create a sparse file use C<$h-E<gt>truncate_size> instead.

The deprecated call C<$h-E<gt>fallocate> does the same,
but owing to an oversight it only allowed 30 bit lengths
to be specified, effectively limiting the maximum size
of files created through that call to 1GB.

Do not confuse this with the guestfish-specific
C<alloc> and C<sparse> commands which create
a file in the host and attach it as a device.

=item @lines = $h->fgrep ($pattern, $path);

This calls the external C<fgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->fgrepi ($pattern, $path);

This calls the external C<fgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $description = $h->file ($path);

This call uses the standard L<file(1)> command to determine
the type or contents of the file.

This call will also transparently look inside various types
of compressed file.

The exact command which runs is C<file -zb path>.  Note in
particular that the filename is not prepended to the output
(the I<-b> option).

The output depends on the output of the underlying L<file(1)>
command and it can change in future in ways beyond our control.
In other words, the output is not guaranteed by the ABI.

See also: L<file(1)>, C<$h-E<gt>vfs_type>, C<$h-E<gt>lstat>,
C<$h-E<gt>is_file>, C<$h-E<gt>is_blockdev> (etc), C<$h-E<gt>is_zero>.

=item $arch = $h->file_architecture ($filename);

This detects the architecture of the binary C<filename>,
and returns it if known.

Currently defined architectures are:

=over 4

=item "i386"

This string is returned for all 32 bit i386, i486, i586, i686 binaries
irrespective of the precise processor requirements of the binary.

=item "x86_64"

64 bit x86-64.

=item "sparc"

32 bit SPARC.

=item "sparc64"

64 bit SPARC V9 and above.

=item "ia64"

Intel Itanium.

=item "ppc"

32 bit Power PC.

=item "ppc64"

64 bit Power PC.

=back

Libguestfs may return other architecture strings in future.

The function works on at least the following types of files:

=over 4

=item *

many types of Un*x and Linux binary

=item *

many types of Un*x and Linux shared library

=item *

Windows Win32 and Win64 binaries

=item *

Windows Win32 and Win64 DLLs

Win32 binaries and DLLs return C<i386>.

Win64 binaries and DLLs return C<x86_64>.

=item *

Linux kernel modules

=item *

Linux new-style initrd images

=item *

some non-x86 Linux vmlinuz kernels

=back

What it can't do currently:

=over 4

=item *

static libraries (libfoo.a)

=item *

Linux old-style initrd as compressed ext2 filesystem (RHEL 3)

=item *

x86 Linux vmlinuz kernels

x86 vmlinuz images (bzImage format) consist of a mix of 16-, 32- and
compressed code, and are horribly hard to unpack.  If you want to find
the architecture of a kernel, use the architecture of the associated
initrd or kernel module(s) instead.

=back

=item $size = $h->filesize ($file);

This command returns the size of C<file> in bytes.

To get other stats about a file, use C<$h-E<gt>stat>, C<$h-E<gt>lstat>,
C<$h-E<gt>is_dir>, C<$h-E<gt>is_file> etc.
To get the size of block devices, use C<$h-E<gt>blockdev_getsize64>.

=item $h->fill ($c, $len, $path);

This command creates a new file called C<path>.  The initial
content of the file is C<len> octets of C<c>, where C<c>
must be a number in the range C<[0..255]>.

To fill a file with zero bytes (sparsely), it is
much more efficient to use C<$h-E<gt>truncate_size>.
To create a file with a pattern of repeating bytes
use C<$h-E<gt>fill_pattern>.

=item $h->fill_pattern ($pattern, $len, $path);

This function is like C<$h-E<gt>fill> except that it creates
a new file of length C<len> containing the repeating pattern
of bytes in C<pattern>.  The pattern is truncated if necessary
to ensure the length of the file is exactly C<len> bytes.

=item @names = $h->find ($directory);

This command lists out all files and directories, recursively,
starting at C<directory>.  It is essentially equivalent to
running the shell command C<find directory -print> but some
post-processing happens on the output, described below.

This returns a list of strings I<without any prefix>.  Thus
if the directory structure was:

 /tmp/a
 /tmp/b
 /tmp/c/d

then the returned list from C<$h-E<gt>find> C</tmp> would be
4 elements:

 a
 b
 c
 c/d

If C<directory> is not a directory, then this command returns
an error.

The returned list is sorted.

See also C<$h-E<gt>find0>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->find0 ($directory, $files);

This command lists out all files and directories, recursively,
starting at C<directory>, placing the resulting list in the
external file called C<files>.

This command works the same way as C<$h-E<gt>find> with the
following exceptions:

=over 4

=item *

The resulting list is written to an external file.

=item *

Items (filenames) in the result are separated
by C<\0> characters.  See L<find(1)> option I<-print0>.

=item *

This command is not limited in the number of names that it
can return.

=item *

The result list is not sorted.

=back

=item $device = $h->findfs_label ($label);

This command searches the filesystems and returns the one
which has the given label.  An error is returned if no such
filesystem can be found.

To find the label of a filesystem, use C<$h-E<gt>vfs_label>.

=item $device = $h->findfs_uuid ($uuid);

This command searches the filesystems and returns the one
which has the given UUID.  An error is returned if no such
filesystem can be found.

To find the UUID of a filesystem, use C<$h-E<gt>vfs_uuid>.

=item $status = $h->fsck ($fstype, $device);

This runs the filesystem checker (fsck) on C<device> which
should have filesystem type C<fstype>.

The returned integer is the status.  See L<fsck(8)> for the
list of status codes from C<fsck>.

Notes:

=over 4

=item *

Multiple status codes can be summed together.

=item *

A non-zero return code can mean "success", for example if
errors have been corrected on the filesystem.

=item *

Checking or repairing NTFS volumes is not supported
(by linux-ntfs).

=back

This command is entirely equivalent to running C<fsck -a -t fstype device>.

=item $append = $h->get_append ();

Return the additional kernel options which are added to the
guest kernel command line.

If C<NULL> then no options are added.

=item $attachmethod = $h->get_attach_method ();

Return the current attach method.  See C<$h-E<gt>set_attach_method>.

=item $autosync = $h->get_autosync ();

Get the autosync flag.

=item $direct = $h->get_direct ();

Return the direct appliance mode flag.

=item $label = $h->get_e2label ($device);

This returns the ext2/3/4 filesystem label of the filesystem on
C<device>.

I<This function is deprecated.>
In new code, use the L</vfs_label> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $uuid = $h->get_e2uuid ($device);

This returns the ext2/3/4 filesystem UUID of the filesystem on
C<device>.

I<This function is deprecated.>
In new code, use the L</vfs_uuid> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $memsize = $h->get_memsize ();

This gets the memory size in megabytes allocated to the
qemu subprocess.

If C<$h-E<gt>set_memsize> was not called
on this handle, and if C<LIBGUESTFS_MEMSIZE> was not set,
then this returns the compiled-in default value for memsize.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $network = $h->get_network ();

This returns the enable network flag.

=item $path = $h->get_path ();

Return the current search path.

This is always non-NULL.  If it wasn't set already, then this will
return the default path.

=item $pgroup = $h->get_pgroup ();

This returns the process group flag.

=item $pid = $h->get_pid ();

Return the process ID of the qemu subprocess.  If there is no
qemu subprocess, then this will return an error.

This is an internal call used for debugging and testing.

=item $qemu = $h->get_qemu ();

Return the current qemu binary.

This is always non-NULL.  If it wasn't set already, then this will
return the default qemu binary name.

=item $recoveryproc = $h->get_recovery_proc ();

Return the recovery process enabled flag.

=item $selinux = $h->get_selinux ();

This returns the current setting of the selinux flag which
is passed to the appliance at boot time.  See C<$h-E<gt>set_selinux>.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $smp = $h->get_smp ();

This returns the number of virtual CPUs assigned to the appliance.

=item $state = $h->get_state ();

This returns the current state as an opaque integer.  This is
only useful for printing debug and internal error messages.

For more information on states, see L<guestfs(3)>.

=item $trace = $h->get_trace ();

Return the command trace flag.

=item $mask = $h->get_umask ();

Return the current umask.  By default the umask is C<022>
unless it has been set by calling C<$h-E<gt>umask>.

=item $verbose = $h->get_verbose ();

This returns the verbose messages flag.

=item $context = $h->getcon ();

This gets the SELinux security context of the daemon.

See the documentation about SELINUX in L<guestfs(3)>,
and C<$h-E<gt>setcon>

=item $xattr = $h->getxattr ($path, $name);

Get a single extended attribute from file C<path> named C<name>.
This call follows symlinks.  If you want to lookup an extended
attribute for the symlink itself, use C<$h-E<gt>lgetxattr>.

Normally it is better to get all extended attributes from a file
in one go by calling C<$h-E<gt>getxattrs>.  However some Linux
filesystem implementations are buggy and do not provide a way to
list out attributes.  For these filesystems (notably ntfs-3g)
you have to know the names of the extended attributes you want
in advance and call this function.

Extended attribute values are blobs of binary data.  If there
is no extended attribute named C<name>, this returns an error.

See also: C<$h-E<gt>getxattrs>, C<$h-E<gt>lgetxattr>, L<attr(5)>.

=item @xattrs = $h->getxattrs ($path);

This call lists the extended attributes of the file or directory
C<path>.

At the system call level, this is a combination of the
L<listxattr(2)> and L<getxattr(2)> calls.

See also: C<$h-E<gt>lgetxattrs>, L<attr(5)>.

=item @paths = $h->glob_expand ($pattern);

This command searches for all the pathnames matching
C<pattern> according to the wildcard expansion rules
used by the shell.

If no paths match, then this returns an empty list
(note: not an error).

It is just a wrapper around the C L<glob(3)> function
with flags C<GLOB_MARK|GLOB_BRACE>.
See that manual page for more details.

=item @lines = $h->grep ($regex, $path);

This calls the external C<grep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->grepi ($regex, $path);

This calls the external C<grep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->grub_install ($root, $device);

This command installs GRUB 1 (the Grand Unified Bootloader) on
C<device>, with the root directory being C<root>.

Notes:

=over 4

=item *

There is currently no way in the API to install grub2, which
is used by most modern Linux guests.  It is possible to run
the grub2 command from the guest, although see the
caveats in L<guestfs(3)/RUNNING COMMANDS>.

=item *

This uses C<grub-install> from the host.  Unfortunately grub is
not always compatible with itself, so this only works in rather
narrow circumstances.  Careful testing with each guest version
is advisable.

=item *

If grub-install reports the error
"No suitable drive was found in the generated device map."
it may be that you need to create a C</boot/grub/device.map>
file first that contains the mapping between grub device names
and Linux device names.  It is usually sufficient to create
a file containing:

 (hd0) /dev/vda

replacing C</dev/vda> with the name of the installation device.

=back

=item @lines = $h->head ($path);

This command returns up to the first 10 lines of a file as
a list of strings.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->head_n ($nrlines, $path);

If the parameter C<nrlines> is a positive number, this returns the first
C<nrlines> lines of the file C<path>.

If the parameter C<nrlines> is a negative number, this returns lines
from the file C<path>, excluding the last C<nrlines> lines.

If the parameter C<nrlines> is zero, this returns an empty list.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $dump = $h->hexdump ($path);

This runs C<hexdump -C> on the given C<path>.  The result is
the human-readable, canonical hex dump of the file.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $content = $h->initrd_cat ($initrdpath, $filename);

This command unpacks the file C<filename> from the initrd file
called C<initrdpath>.  The filename must be given I<without> the
initial C</> character.

For example, in guestfish you could use the following command
to examine the boot script (usually called C</init>)
contained in a Linux initrd or initramfs image:

 initrd-cat /boot/initrd-<version>.img init

See also C<$h-E<gt>initrd_list>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @filenames = $h->initrd_list ($path);

This command lists out files contained in an initrd.

The files are listed without any initial C</> character.  The
files are listed in the order they appear (not necessarily
alphabetical).  Directory names are listed as separate items.

Old Linux kernels (2.4 and earlier) used a compressed ext2
filesystem as initrd.  We I<only> support the newer initramfs
format (compressed cpio files).

=item $wd = $h->inotify_add_watch ($path, $mask);

Watch C<path> for the events listed in C<mask>.

Note that if C<path> is a directory then events within that
directory are watched, but this does I<not> happen recursively
(in subdirectories).

Note for non-C or non-Linux callers: the inotify events are
defined by the Linux kernel ABI and are listed in
C</usr/include/sys/inotify.h>.

=item $h->inotify_close ();

This closes the inotify handle which was previously
opened by inotify_init.  It removes all watches, throws
away any pending events, and deallocates all resources.

=item @paths = $h->inotify_files ();

This function is a helpful wrapper around C<$h-E<gt>inotify_read>
which just returns a list of pathnames of objects that were
touched.  The returned pathnames are sorted and deduplicated.

=item $h->inotify_init ($maxevents);

This command creates a new inotify handle.
The inotify subsystem can be used to notify events which happen to
objects in the guest filesystem.

C<maxevents> is the maximum number of events which will be
queued up between calls to C<$h-E<gt>inotify_read> or
C<$h-E<gt>inotify_files>.
If this is passed as C<0>, then the kernel (or previously set)
default is used.  For Linux 2.6.29 the default was 16384 events.
Beyond this limit, the kernel throws away events, but records
the fact that it threw them away by setting a flag
C<IN_Q_OVERFLOW> in the returned structure list (see
C<$h-E<gt>inotify_read>).

Before any events are generated, you have to add some
watches to the internal watch list.  See: C<$h-E<gt>inotify_add_watch> and
C<$h-E<gt>inotify_rm_watch>.

Queued up events should be read periodically by calling
C<$h-E<gt>inotify_read>
(or C<$h-E<gt>inotify_files> which is just a helpful
wrapper around C<$h-E<gt>inotify_read>).  If you don't
read the events out often enough then you risk the internal
queue overflowing.

The handle should be closed after use by calling
C<$h-E<gt>inotify_close>.  This also removes any
watches automatically.

See also L<inotify(7)> for an overview of the inotify interface
as exposed by the Linux kernel, which is roughly what we expose
via libguestfs.  Note that there is one global inotify handle
per libguestfs instance.

=item @events = $h->inotify_read ();

Return the complete queue of events that have happened
since the previous read call.

If no events have happened, this returns an empty list.

I<Note>: In order to make sure that all events have been
read, you must call this function repeatedly until it
returns an empty list.  The reason is that the call will
read events up to the maximum appliance-to-host message
size and leave remaining events in the queue.

=item $h->inotify_rm_watch ($wd);

Remove a previously defined inotify watch.
See C<$h-E<gt>inotify_add_watch>.

=item $arch = $h->inspect_get_arch ($root);

This returns the architecture of the inspected operating system.
The possible return values are listed under
C<$h-E<gt>file_architecture>.

If the architecture could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $distro = $h->inspect_get_distro ($root);

This returns the distro (distribution) of the inspected operating
system.

Currently defined distros are:

=over 4

=item "archlinux"

Arch Linux.

=item "centos"

CentOS.

=item "debian"

Debian.

=item "fedora"

Fedora.

=item "gentoo"

Gentoo.

=item "linuxmint"

Linux Mint.

=item "mageia"

Mageia.

=item "mandriva"

Mandriva.

=item "meego"

MeeGo.

=item "opensuse"

OpenSUSE.

=item "pardus"

Pardus.

=item "redhat-based"

Some Red Hat-derived distro.

=item "rhel"

Red Hat Enterprise Linux.

=item "scientificlinux"

Scientific Linux.

=item "slackware"

Slackware.

=item "ttylinux"

ttylinux.

=item "ubuntu"

Ubuntu.

=item "unknown"

The distro could not be determined.

=item "windows"

Windows does not have distributions.  This string is
returned if the OS type is Windows.

=back

Future versions of libguestfs may return other strings here.
The caller should be prepared to handle any string.

Please read L<guestfs(3)/INSPECTION> for more details.

=item %drives = $h->inspect_get_drive_mappings ($root);

This call is useful for Windows which uses a primitive system
of assigning drive letters (like "C:") to partitions.
This inspection API examines the Windows Registry to find out
how disks/partitions are mapped to drive letters, and returns
a hash table as in the example below:

 C      =>     /dev/vda2
 E      =>     /dev/vdb1
 F      =>     /dev/vdc1

Note that keys are drive letters.  For Windows, the key is
case insensitive and just contains the drive letter, without
the customary colon separator character.

In future we may support other operating systems that also used drive
letters, but the keys for those might not be case insensitive
and might be longer than 1 character.  For example in OS-9,
hard drives were named C<h0>, C<h1> etc.

For Windows guests, currently only hard drive mappings are
returned.  Removable disks (eg. DVD-ROMs) are ignored.

For guests that do not use drive mappings, or if the drive mappings
could not be determined, this returns an empty hash table.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$h-E<gt>inspect_get_mountpoints>,
C<$h-E<gt>inspect_get_filesystems>.

=item @filesystems = $h->inspect_get_filesystems ($root);

This returns a list of all the filesystems that we think
are associated with this operating system.  This includes
the root filesystem, other ordinary filesystems, and
non-mounted devices like swap partitions.

In the case of a multi-boot virtual machine, it is possible
for a filesystem to be shared between operating systems.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$h-E<gt>inspect_get_mountpoints>.

=item $format = $h->inspect_get_format ($root);

This returns the format of the inspected operating system.  You
can use it to detect install images, live CDs and similar.

Currently defined formats are:

=over 4

=item "installed"

This is an installed operating system.

=item "installer"

The disk image being inspected is not an installed operating system,
but a I<bootable> install disk, live CD, or similar.

=item "unknown"

The format of this disk image is not known.

=back

Future versions of libguestfs may return other strings here.
The caller should be prepared to handle any string.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $hostname = $h->inspect_get_hostname ($root);

This function returns the hostname of the operating system
as found by inspection of the guest's configuration files.

If the hostname could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $icon = $h->inspect_get_icon ($root [, favicon => $favicon] [, highquality => $highquality]);

This function returns an icon corresponding to the inspected
operating system.  The icon is returned as a buffer containing a
PNG image (re-encoded to PNG if necessary).

If it was not possible to get an icon this function returns a
zero-length (non-NULL) buffer.  I<Callers must check for this case>.

Libguestfs will start by looking for a file called
C</etc/favicon.png> or C<C:\etc\favicon.png>
and if it has the correct format, the contents of this file will
be returned.  You can disable favicons by passing the
optional C<favicon> boolean as false (default is true).

If finding the favicon fails, then we look in other places in the
guest for a suitable icon.

If the optional C<highquality> boolean is true then
only high quality icons are returned, which means only icons of
high resolution with an alpha channel.  The default (false) is
to return any icon we can, even if it is of substandard quality.

Notes:

=over 4

=item *

Unlike most other inspection API calls, the guest's disks must be
mounted up before you call this, since it needs to read information
from the guest filesystem during the call.

=item *

B<Security:> The icon data comes from the untrusted guest,
and should be treated with caution.  PNG files have been
known to contain exploits.  Ensure that libpng (or other relevant
libraries) are fully up to date before trying to process or
display the icon.

=item *

The PNG image returned can be any size.  It might not be square.
Libguestfs tries to return the largest, highest quality
icon available.  The application must scale the icon to the
required size.

=item *

Extracting icons from Windows guests requires the external
C<wrestool> program from the C<icoutils> package, and
several programs (C<bmptopnm>, C<pnmtopng>, C<pamcut>)
from the C<netpbm> package.  These must be installed separately.

=item *

Operating system icons are usually trademarks.  Seek legal
advice before using trademarks in applications.

=back

=item $major = $h->inspect_get_major_version ($root);

This returns the major version number of the inspected operating
system.

Windows uses a consistent versioning scheme which is I<not>
reflected in the popular public names used by the operating system.
Notably the operating system known as "Windows 7" is really
version 6.1 (ie. major = 6, minor = 1).  You can find out the
real versions corresponding to releases of Windows by consulting
Wikipedia or MSDN.

If the version could not be determined, then C<0> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $minor = $h->inspect_get_minor_version ($root);

This returns the minor version number of the inspected operating
system.

If the version could not be determined, then C<0> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$h-E<gt>inspect_get_major_version>.

=item %mountpoints = $h->inspect_get_mountpoints ($root);

This returns a hash of where we think the filesystems
associated with this operating system should be mounted.
Callers should note that this is at best an educated guess
made by reading configuration files such as C</etc/fstab>.
I<In particular note> that this may return filesystems
which are non-existent or not mountable and callers should
be prepared to handle or ignore failures if they try to
mount them.

Each element in the returned hashtable has a key which
is the path of the mountpoint (eg. C</boot>) and a value
which is the filesystem that would be mounted there
(eg. C</dev/sda1>).

Non-mounted devices such as swap devices are I<not>
returned in this list.

For operating systems like Windows which still use drive
letters, this call will only return an entry for the first
drive "mounted on" C</>.  For information about the
mapping of drive letters to partitions, see
C<$h-E<gt>inspect_get_drive_mappings>.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$h-E<gt>inspect_get_filesystems>.

=item $packageformat = $h->inspect_get_package_format ($root);

This function and C<$h-E<gt>inspect_get_package_management> return
the package format and package management tool used by the
inspected operating system.  For example for Fedora these
functions would return C<rpm> (package format) and
C<yum> (package management).

This returns the string C<unknown> if we could not determine the
package format I<or> if the operating system does not have
a real packaging system (eg. Windows).

Possible strings include:
C<rpm>, C<deb>, C<ebuild>, C<pisi>, C<pacman>, C<pkgsrc>.
Future versions of libguestfs may return other strings.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $packagemanagement = $h->inspect_get_package_management ($root);

C<$h-E<gt>inspect_get_package_format> and this function return
the package format and package management tool used by the
inspected operating system.  For example for Fedora these
functions would return C<rpm> (package format) and
C<yum> (package management).

This returns the string C<unknown> if we could not determine the
package management tool I<or> if the operating system does not have
a real packaging system (eg. Windows).

Possible strings include: C<yum>, C<up2date>,
C<apt> (for all Debian derivatives),
C<portage>, C<pisi>, C<pacman>, C<urpmi>, C<zypper>.
Future versions of libguestfs may return other strings.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $product = $h->inspect_get_product_name ($root);

This returns the product name of the inspected operating
system.  The product name is generally some freeform string
which can be displayed to the user, but should not be
parsed by programs.

If the product name could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $variant = $h->inspect_get_product_variant ($root);

This returns the product variant of the inspected operating
system.

For Windows guests, this returns the contents of the Registry key
C<HKLM\Software\Microsoft\Windows NT\CurrentVersion>
C<InstallationType> which is usually a string such as
C<Client> or C<Server> (other values are possible).  This
can be used to distinguish consumer and enterprise versions
of Windows that have the same version number (for example,
Windows 7 and Windows 2008 Server are both version 6.1,
but the former is C<Client> and the latter is C<Server>).

For enterprise Linux guests, in future we intend this to return
the product variant such as C<Desktop>, C<Server> and so on.  But
this is not implemented at present.

If the product variant could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$h-E<gt>inspect_get_product_name>,
C<$h-E<gt>inspect_get_major_version>.

=item @roots = $h->inspect_get_roots ();

This function is a convenient way to get the list of root
devices, as returned from a previous call to C<$h-E<gt>inspect_os>,
but without redoing the whole inspection process.

This returns an empty list if either no root devices were
found or the caller has not called C<$h-E<gt>inspect_os>.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $name = $h->inspect_get_type ($root);

This returns the type of the inspected operating system.
Currently defined types are:

=over 4

=item "linux"

Any Linux-based operating system.

=item "windows"

Any Microsoft Windows operating system.

=item "freebsd"

FreeBSD.

=item "netbsd"

NetBSD.

=item "hurd"

GNU/Hurd.

=item "unknown"

The operating system type could not be determined.

=back

Future versions of libguestfs may return other strings here.
The caller should be prepared to handle any string.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $controlset = $h->inspect_get_windows_current_control_set ($root);

This returns the Windows CurrentControlSet of the inspected guest.
The CurrentControlSet is a registry key name such as C<ControlSet001>.

This call assumes that the guest is Windows and that the
Registry could be examined by inspection.  If this is not
the case then an error is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $systemroot = $h->inspect_get_windows_systemroot ($root);

This returns the Windows systemroot of the inspected guest.
The systemroot is a directory path such as C</WINDOWS>.

This call assumes that the guest is Windows and that the
systemroot could be determined by inspection.  If this is not
the case then an error is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $live = $h->inspect_is_live ($root);

If C<$h-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if a live image
was detected on the disk.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $multipart = $h->inspect_is_multipart ($root);

If C<$h-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if the disk is
part of a set.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $netinst = $h->inspect_is_netinst ($root);

If C<$h-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if the disk is
a network installer, ie. not a self-contained install CD but
one which is likely to require network access to complete
the install.

Please read L<guestfs(3)/INSPECTION> for more details.

=item @applications = $h->inspect_list_applications ($root);

Return the list of applications installed in the operating system.

I<Note:> This call works differently from other parts of the
inspection API.  You have to call C<$h-E<gt>inspect_os>, then
C<$h-E<gt>inspect_get_mountpoints>, then mount up the disks,
before calling this.  Listing applications is a significantly
more difficult operation which requires access to the full
filesystem.  Also note that unlike the other
C<$h-E<gt>inspect_get_*> calls which are just returning
data cached in the libguestfs handle, this call actually reads
parts of the mounted filesystems during the call.

This returns an empty list if the inspection code was not able
to determine the list of applications.

The application structure contains the following fields:

=over 4

=item C<app_name>

The name of the application.  For Red Hat-derived and Debian-derived
Linux guests, this is the package name.

=item C<app_display_name>

The display name of the application, sometimes localized to the
install language of the guest operating system.

If unavailable this is returned as an empty string C<"">.
Callers needing to display something can use C<app_name> instead.

=item C<app_epoch>

For package managers which use epochs, this contains the epoch of
the package (an integer).  If unavailable, this is returned as C<0>.

=item C<app_version>

The version string of the application or package.  If unavailable
this is returned as an empty string C<"">.

=item C<app_release>

The release string of the application or package, for package
managers that use this.  If unavailable this is returned as an
empty string C<"">.

=item C<app_install_path>

The installation path of the application (on operating systems
such as Windows which use installation paths).  This path is
in the format used by the guest operating system, it is not
a libguestfs path.

If unavailable this is returned as an empty string C<"">.

=item C<app_trans_path>

The install path translated into a libguestfs path.
If unavailable this is returned as an empty string C<"">.

=item C<app_publisher>

The name of the publisher of the application, for package
managers that use this.  If unavailable this is returned
as an empty string C<"">.

=item C<app_url>

The URL (eg. upstream URL) of the application.
If unavailable this is returned as an empty string C<"">.

=item C<app_source_package>

For packaging systems which support this, the name of the source
package.  If unavailable this is returned as an empty string C<"">.

=item C<app_summary>

A short (usually one line) description of the application or package.
If unavailable this is returned as an empty string C<"">.

=item C<app_description>

A longer description of the application or package.
If unavailable this is returned as an empty string C<"">.

=back

Please read L<guestfs(3)/INSPECTION> for more details.

=item @roots = $h->inspect_os ();

This function uses other libguestfs functions and certain
heuristics to inspect the disk(s) (usually disks belonging to
a virtual machine), looking for operating systems.

The list returned is empty if no operating systems were found.

If one operating system was found, then this returns a list with
a single element, which is the name of the root filesystem of
this operating system.  It is also possible for this function
to return a list containing more than one element, indicating
a dual-boot or multi-boot virtual machine, with each element being
the root filesystem of one of the operating systems.

You can pass the root string(s) returned to other
C<$h-E<gt>inspect_get_*> functions in order to query further
information about each operating system, such as the name
and version.

This function uses other libguestfs features such as
C<$h-E<gt>mount_ro> and C<$h-E<gt>umount_all> in order to mount
and unmount filesystems and look at the contents.  This should
be called with no disks currently mounted.  The function may also
use Augeas, so any existing Augeas handle will be closed.

This function cannot decrypt encrypted disks.  The caller
must do that first (supplying the necessary keys) if the
disk is encrypted.

Please read L<guestfs(3)/INSPECTION> for more details.

See also C<$h-E<gt>list_filesystems>.

=item $flag = $h->is_blockdev ($path);

This returns C<true> if and only if there is a block device
with the given C<path> name.

See also C<$h-E<gt>stat>.

=item $busy = $h->is_busy ();

This returns true iff this handle is busy processing a command
(in the C<BUSY> state).

For more information on states, see L<guestfs(3)>.

=item $flag = $h->is_chardev ($path);

This returns C<true> if and only if there is a character device
with the given C<path> name.

See also C<$h-E<gt>stat>.

=item $config = $h->is_config ();

This returns true iff this handle is being configured
(in the C<CONFIG> state).

For more information on states, see L<guestfs(3)>.

=item $dirflag = $h->is_dir ($path);

This returns C<true> if and only if there is a directory
with the given C<path> name.  Note that it returns false for
other objects like files.

See also C<$h-E<gt>stat>.

=item $flag = $h->is_fifo ($path);

This returns C<true> if and only if there is a FIFO (named pipe)
with the given C<path> name.

See also C<$h-E<gt>stat>.

=item $fileflag = $h->is_file ($path);

This returns C<true> if and only if there is a regular file
with the given C<path> name.  Note that it returns false for
other objects like directories.

See also C<$h-E<gt>stat>.

=item $launching = $h->is_launching ();

This returns true iff this handle is launching the subprocess
(in the C<LAUNCHING> state).

For more information on states, see L<guestfs(3)>.

=item $lvflag = $h->is_lv ($device);

This command tests whether C<device> is a logical volume, and
returns true iff this is the case.

=item $ready = $h->is_ready ();

This returns true iff this handle is ready to accept commands
(in the C<READY> state).

For more information on states, see L<guestfs(3)>.

=item $flag = $h->is_socket ($path);

This returns C<true> if and only if there is a Unix domain socket
with the given C<path> name.

See also C<$h-E<gt>stat>.

=item $flag = $h->is_symlink ($path);

This returns C<true> if and only if there is a symbolic link
with the given C<path> name.

See also C<$h-E<gt>stat>.

=item $zeroflag = $h->is_zero ($path);

This returns true iff the file exists and the file is empty or
it contains all zero bytes.

=item $zeroflag = $h->is_zero_device ($device);

This returns true iff the device exists and contains all zero bytes.

Note that for large devices this can take a long time to run.

=item $h->kill_subprocess ();

This kills the qemu subprocess.  You should never need to call this.

=item $h->launch ();

Internally libguestfs is implemented by running a virtual machine
using L<qemu(1)>.

You should call this after configuring the handle
(eg. adding drives) but before performing any actions.

=item $h->lchown ($owner, $group, $path);

Change the file owner to C<owner> and group to C<group>.
This is like C<$h-E<gt>chown> but if C<path> is a symlink then
the link itself is changed, not the target.

Only numeric uid and gid are supported.  If you want to use
names, you will need to locate and parse the password file
yourself (Augeas support makes this relatively easy).

=item $xattr = $h->lgetxattr ($path, $name);

Get a single extended attribute from file C<path> named C<name>.
If C<path> is a symlink, then this call returns an extended
attribute from the symlink.

Normally it is better to get all extended attributes from a file
in one go by calling C<$h-E<gt>getxattrs>.  However some Linux
filesystem implementations are buggy and do not provide a way to
list out attributes.  For these filesystems (notably ntfs-3g)
you have to know the names of the extended attributes you want
in advance and call this function.

Extended attribute values are blobs of binary data.  If there
is no extended attribute named C<name>, this returns an error.

See also: C<$h-E<gt>lgetxattrs>, C<$h-E<gt>getxattr>, L<attr(5)>.

=item @xattrs = $h->lgetxattrs ($path);

This is the same as C<$h-E<gt>getxattrs>, but if C<path>
is a symbolic link, then it returns the extended attributes
of the link itself.

=item @mounttags = $h->list_9p ();

List all 9p filesystems attached to the guest.  A list of
mount tags is returned.

=item @devices = $h->list_devices ();

List all the block devices.

The full block device names are returned, eg. C</dev/sda>.

See also C<$h-E<gt>list_filesystems>.

=item @devices = $h->list_dm_devices ();

List all device mapper devices.

The returned list contains C</dev/mapper/*> devices, eg. ones created
by a previous call to C<$h-E<gt>luks_open>.

Device mapper devices which correspond to logical volumes are I<not>
returned in this list.  Call C<$h-E<gt>lvs> if you want to list logical
volumes.

=item %fses = $h->list_filesystems ();

This inspection command looks for filesystems on partitions,
block devices and logical volumes, returning a list of devices
containing filesystems and their type.

The return value is a hash, where the keys are the devices
containing filesystems, and the values are the filesystem types.
For example:

 "/dev/sda1" => "ntfs"
 "/dev/sda2" => "ext2"
 "/dev/vg_guest/lv_root" => "ext4"
 "/dev/vg_guest/lv_swap" => "swap"

The value can have the special value "unknown", meaning the
content of the device is undetermined or empty.
"swap" means a Linux swap partition.

This command runs other libguestfs commands, which might include
C<$h-E<gt>mount> and C<$h-E<gt>umount>, and therefore you should
use this soon after launch and only when nothing is mounted.

Not all of the filesystems returned will be mountable.  In
particular, swap partitions are returned in the list.  Also
this command does not check that each filesystem
found is valid and mountable, and some filesystems might
be mountable but require special options.  Filesystems may
not all belong to a single logical operating system
(use C<$h-E<gt>inspect_os> to look for OSes).

=item @devices = $h->list_md_devices ();

List all Linux md devices.

=item @partitions = $h->list_partitions ();

List all the partitions detected on all block devices.

The full partition device names are returned, eg. C</dev/sda1>

This does not return logical volumes.  For that you will need to
call C<$h-E<gt>lvs>.

See also C<$h-E<gt>list_filesystems>.

=item $listing = $h->ll ($directory);

List the files in C<directory> (relative to the root directory,
there is no cwd) in the format of 'ls -la'.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.

=item $h->ln ($target, $linkname);

This command creates a hard link using the C<ln> command.

=item $h->ln_f ($target, $linkname);

This command creates a hard link using the C<ln -f> command.
The I<-f> option removes the link (C<linkname>) if it exists already.

=item $h->ln_s ($target, $linkname);

This command creates a symbolic link using the C<ln -s> command.

=item $h->ln_sf ($target, $linkname);

This command creates a symbolic link using the C<ln -sf> command,
The I<-f> option removes the link (C<linkname>) if it exists already.

=item $h->lremovexattr ($xattr, $path);

This is the same as C<$h-E<gt>removexattr>, but if C<path>
is a symbolic link, then it removes an extended attribute
of the link itself.

=item @listing = $h->ls ($directory);

List the files in C<directory> (relative to the root directory,
there is no cwd).  The '.' and '..' entries are not returned, but
hidden files are shown.

This command is mostly useful for interactive sessions.  Programs
should probably use C<$h-E<gt>readdir> instead.

=item $h->lsetxattr ($xattr, $val, $vallen, $path);

This is the same as C<$h-E<gt>setxattr>, but if C<path>
is a symbolic link, then it sets an extended attribute
of the link itself.

=item %statbuf = $h->lstat ($path);

Returns file information for the given C<path>.

This is the same as C<$h-E<gt>stat> except that if C<path>
is a symbolic link, then the link is stat-ed, not the file it
refers to.

This is the same as the C<lstat(2)> system call.

=item @statbufs = $h->lstatlist ($path, \@names);

This call allows you to perform the C<$h-E<gt>lstat> operation
on multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a list of stat structs, with a one-to-one
correspondence to the C<names> list.  If any name did not exist
or could not be lstat'd, then the C<ino> field of that structure
is set to C<-1>.

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.
See also C<$h-E<gt>lxattrlist> for a similarly efficient call
for getting extended attributes.  Very long directory listings
might cause the protocol message size to be exceeded, causing
this call to fail.  The caller must split up such requests
into smaller groups of names.

=item $h->luks_add_key ($device, $key, $newkey, $keyslot);

This command adds a new key on LUKS device C<device>.
C<key> is any existing key, and is used to access the device.
C<newkey> is the new key to add.  C<keyslot> is the key slot
that will be replaced.

Note that if C<keyslot> already contains a key, then this
command will fail.  You have to use C<$h-E<gt>luks_kill_slot>
first to remove that key.

=item $h->luks_close ($device);

This closes a LUKS device that was created earlier by
C<$h-E<gt>luks_open> or C<$h-E<gt>luks_open_ro>.  The
C<device> parameter must be the name of the LUKS mapping
device (ie. C</dev/mapper/mapname>) and I<not> the name
of the underlying block device.

=item $h->luks_format ($device, $key, $keyslot);

This command erases existing data on C<device> and formats
the device as a LUKS encrypted device.  C<key> is the
initial key, which is added to key slot C<slot>.  (LUKS
supports 8 key slots, numbered 0-7).

=item $h->luks_format_cipher ($device, $key, $keyslot, $cipher);

This command is the same as C<$h-E<gt>luks_format> but
it also allows you to set the C<cipher> used.

=item $h->luks_kill_slot ($device, $key, $keyslot);

This command deletes the key in key slot C<keyslot> from the
encrypted LUKS device C<device>.  C<key> must be one of the
I<other> keys.

=item $h->luks_open ($device, $key, $mapname);

This command opens a block device which has been encrypted
according to the Linux Unified Key Setup (LUKS) standard.

C<device> is the encrypted block device or partition.

The caller must supply one of the keys associated with the
LUKS block device, in the C<key> parameter.

This creates a new block device called C</dev/mapper/mapname>.
Reads and writes to this block device are decrypted from and
encrypted to the underlying C<device> respectively.

If this block device contains LVM volume groups, then
calling C<$h-E<gt>vgscan> followed by C<$h-E<gt>vg_activate_all>
will make them visible.

Use C<$h-E<gt>list_dm_devices> to list all device mapper
devices.

=item $h->luks_open_ro ($device, $key, $mapname);

This is the same as C<$h-E<gt>luks_open> except that a read-only
mapping is created.

=item $h->lvcreate ($logvol, $volgroup, $mbytes);

This creates an LVM logical volume called C<logvol>
on the volume group C<volgroup>, with C<size> megabytes.

=item $lv = $h->lvm_canonical_lv_name ($lvname);

This converts alternative naming schemes for LVs that you
might find to the canonical name.  For example, C</dev/mapper/VG-LV>
is converted to C</dev/VG/LV>.

This command returns an error if the C<lvname> parameter does
not refer to a logical volume.

See also C<$h-E<gt>is_lv>.

=item $h->lvm_clear_filter ();

This undoes the effect of C<$h-E<gt>lvm_set_filter>.  LVM
will be able to see every block device.

This command also clears the LVM cache and performs a volume
group scan.

=item $h->lvm_remove_all ();

This command removes all LVM logical volumes, volume groups
and physical volumes.

=item $h->lvm_set_filter (\@devices);

This sets the LVM device filter so that LVM will only be
able to "see" the block devices in the list C<devices>,
and will ignore all other attached block devices.

Where disk image(s) contain duplicate PVs or VGs, this
command is useful to get LVM to ignore the duplicates, otherwise
LVM can get confused.  Note also there are two types
of duplication possible: either cloned PVs/VGs which have
identical UUIDs; or VGs that are not cloned but just happen
to have the same name.  In normal operation you cannot
create this situation, but you can do it outside LVM, eg.
by cloning disk images or by bit twiddling inside the LVM
metadata.

This command also clears the LVM cache and performs a volume
group scan.

You can filter whole block devices or individual partitions.

You cannot use this if any VG is currently in use (eg.
contains a mounted filesystem), even if you are not
filtering out that VG.

=item $h->lvremove ($device);

Remove an LVM logical volume C<device>, where C<device> is
the path to the LV, such as C</dev/VG/LV>.

You can also remove all LVs in a volume group by specifying
the VG name, C</dev/VG>.

=item $h->lvrename ($logvol, $newlogvol);

Rename a logical volume C<logvol> with the new name C<newlogvol>.

=item $h->lvresize ($device, $mbytes);

This resizes (expands or shrinks) an existing LVM logical
volume to C<mbytes>.  When reducing, data in the reduced part
is lost.

=item $h->lvresize_free ($lv, $percent);

This expands an existing logical volume C<lv> so that it fills
C<pc>% of the remaining free space in the volume group.  Commonly
you would call this with pc = 100 which expands the logical volume
as much as possible, using all remaining free space in the volume
group.

=item @logvols = $h->lvs ();

List all the logical volumes detected.  This is the equivalent
of the L<lvs(8)> command.

This returns a list of the logical volume device names
(eg. C</dev/VolGroup00/LogVol00>).

See also C<$h-E<gt>lvs_full>, C<$h-E<gt>list_filesystems>.

=item @logvols = $h->lvs_full ();

List all the logical volumes detected.  This is the equivalent
of the L<lvs(8)> command.  The "full" version includes all fields.

=item $uuid = $h->lvuuid ($device);

This command returns the UUID of the LVM LV C<device>.

=item @xattrs = $h->lxattrlist ($path, \@names);

This call allows you to get the extended attributes
of multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a flat list of xattr structs which must be
interpreted sequentially.  The first xattr struct always has a zero-length
C<attrname>.  C<attrval> in this struct is zero-length
to indicate there was an error doing C<lgetxattr> for this
file, I<or> is a C string which is a decimal number
(the number of following attributes for this file, which could
be C<"0">).  Then after the first xattr struct are the
zero or more attributes for the first named file.
This repeats for the second and subsequent files.

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.
See also C<$h-E<gt>lstatlist> for a similarly efficient call
for getting standard stats.  Very long directory listings
might cause the protocol message size to be exceeded, causing
this call to fail.  The caller must split up such requests
into smaller groups of names.

=item $h->md_create ($name, \@devices [, missingbitmap => $missingbitmap] [, nrdevices => $nrdevices] [, spare => $spare] [, chunk => $chunk] [, level => $level]);

Create a Linux md (RAID) device named C<name> on the devices
in the list C<devices>.

The optional parameters are:

=over 4

=item C<missingbitmap>

A bitmap of missing devices.  If a bit is set it means that a
missing device is added to the array.  The least significant bit
corresponds to the first device in the array.

As examples:

If C<devices = ["/dev/sda"]> and C<missingbitmap = 0x1> then
the resulting array would be C<[E<lt>missingE<gt>, "/dev/sda"]>.

If C<devices = ["/dev/sda"]> and C<missingbitmap = 0x2> then
the resulting array would be C<["/dev/sda", E<lt>missingE<gt>]>.

This defaults to C<0> (no missing devices).

The length of C<devices> + the number of bits set in
C<missingbitmap> must equal C<nrdevices> + C<spare>.

=item C<nrdevices>

The number of active RAID devices.

If not set, this defaults to the length of C<devices> plus
the number of bits set in C<missingbitmap>.

=item C<spare>

The number of spare devices.

If not set, this defaults to C<0>.

=item C<chunk>

The chunk size in bytes.

=item C<level>

The RAID level, which can be one of:
I<linear>, I<raid0>, I<0>, I<stripe>, I<raid1>, I<1>, I<mirror>,
I<raid4>, I<4>, I<raid5>, I<5>, I<raid6>, I<6>, I<raid10>, I<10>.
Some of these are synonymous, and more levels may be added in future.

If not set, this defaults to C<raid1>.

=back

=item %info = $h->md_detail ($md);

This command exposes the output of 'mdadm -DY E<lt>mdE<gt>'.
The following fields are usually present in the returned hash.
Other fields may also be present.

=over

=item C<level>

The raid level of the MD device.

=item C<devices>

The number of underlying devices in the MD device.

=item C<metadata>

The metadata version used.

=item C<uuid>

The UUID of the MD device.

=item C<name>

The name of the MD device.

=back

=item $h->md_stop ($md);

This command deactivates the MD array named C<md>.  The
device is stopped, but it is not destroyed or zeroed.

=item $h->mkdir ($path);

Create a directory named C<path>.

=item $h->mkdir_mode ($path, $mode);

This command creates a directory, setting the initial permissions
of the directory to C<mode>.

For common Linux filesystems, the actual mode which is set will
be C<mode & ~umask & 01777>.  Non-native-Linux filesystems may
interpret the mode in other ways.

See also C<$h-E<gt>mkdir>, C<$h-E<gt>umask>

=item $h->mkdir_p ($path);

Create a directory named C<path>, creating any parent directories
as necessary.  This is like the C<mkdir -p> shell command.

=item $dir = $h->mkdtemp ($tmpl);

This command creates a temporary directory.  The
C<tmpl> parameter should be a full pathname for the
temporary directory name with the final six characters being
"XXXXXX".

For example: "/tmp/myprogXXXXXX" or "/Temp/myprogXXXXXX",
the second one being suitable for Windows filesystems.

The name of the temporary directory that was created
is returned.

The temporary directory is created with mode 0700
and is owned by root.

The caller is responsible for deleting the temporary
directory and its contents after use.

See also: L<mkdtemp(3)>

=item $h->mke2fs_J ($fstype, $blocksize, $device, $journal);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on C<journal>.  It is equivalent
to the command:

 mke2fs -t fstype -b blocksize -J device=<journal> <device>

See also C<$h-E<gt>mke2journal>.

=item $h->mke2fs_JL ($fstype, $blocksize, $device, $label);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on the journal labeled C<label>.

See also C<$h-E<gt>mke2journal_L>.

=item $h->mke2fs_JU ($fstype, $blocksize, $device, $uuid);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on the journal with UUID C<uuid>.

See also C<$h-E<gt>mke2journal_U>.

=item $h->mke2journal ($blocksize, $device);

This creates an ext2 external journal on C<device>.  It is equivalent
to the command:

 mke2fs -O journal_dev -b blocksize device

=item $h->mke2journal_L ($blocksize, $label, $device);

This creates an ext2 external journal on C<device> with label C<label>.

=item $h->mke2journal_U ($blocksize, $uuid, $device);

This creates an ext2 external journal on C<device> with UUID C<uuid>.

=item $h->mkfifo ($mode, $path);

This call creates a FIFO (named pipe) called C<path> with
mode C<mode>.  It is just a convenient wrapper around
C<$h-E<gt>mknod>.

The mode actually set is affected by the umask.

=item $h->mkfs ($fstype, $device);

This creates a filesystem on C<device> (usually a partition
or LVM logical volume).  The filesystem type is C<fstype>, for
example C<ext3>.

=item $h->mkfs_b ($fstype, $blocksize, $device);

This call is similar to C<$h-E<gt>mkfs>, but it allows you to
control the block size of the resulting filesystem.  Supported
block sizes depend on the filesystem type, but typically they
are C<1024>, C<2048> or C<4096> only.

For VFAT and NTFS the C<blocksize> parameter is treated as
the requested cluster size.

I<This function is deprecated.>
In new code, use the L</mkfs_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->mkfs_opts ($fstype, $device [, blocksize => $blocksize] [, features => $features] [, inode => $inode] [, sectorsize => $sectorsize]);

This function creates a filesystem on C<device>.  The filesystem
type is C<fstype>, for example C<ext3>.

The optional arguments are:

=over 4

=item C<blocksize>

The filesystem block size.  Supported block sizes depend on the
filesystem type, but typically they are C<1024>, C<2048> or C<4096>
for Linux ext2/3 filesystems.

For VFAT and NTFS the C<blocksize> parameter is treated as
the requested cluster size.

For UFS block sizes, please see L<mkfs.ufs(8)>.

=item C<features>

This passes the I<-O> parameter to the external mkfs program.

For certain filesystem types, this allows extra filesystem
features to be selected.  See L<mke2fs(8)> and L<mkfs.ufs(8)>
for more details.

You cannot use this optional parameter with the C<gfs> or
C<gfs2> filesystem type.

=item C<inode>

This passes the I<-I> parameter to the external L<mke2fs(8)> program
which sets the inode size (only for ext2/3/4 filesystems at present).

=item C<sectorsize>

This passes the I<-S> parameter to external L<mkfs.ufs(8)> program,
which sets sector size for ufs filesystem.

=back

=item $h->mkmountpoint ($exemptpath);

C<$h-E<gt>mkmountpoint> and C<$h-E<gt>rmmountpoint> are
specialized calls that can be used to create extra mountpoints
before mounting the first filesystem.

These calls are I<only> necessary in some very limited circumstances,
mainly the case where you want to mount a mix of unrelated and/or
read-only filesystems together.

For example, live CDs often contain a "Russian doll" nest of
filesystems, an ISO outer layer, with a squashfs image inside, with
an ext2/3 image inside that.  You can unpack this as follows
in guestfish:

 add-ro Fedora-11-i686-Live.iso
 run
 mkmountpoint /cd
 mkmountpoint /sqsh
 mkmountpoint /ext3fs
 mount /dev/sda /cd
 mount-loop /cd/LiveOS/squashfs.img /sqsh
 mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs

The inner filesystem is now unpacked under the /ext3fs mountpoint.

C<$h-E<gt>mkmountpoint> is not compatible with C<$h-E<gt>umount_all>.
You may get unexpected errors if you try to mix these calls.  It is
safest to manually unmount filesystems and remove mountpoints after use.

C<$h-E<gt>umount_all> unmounts filesystems by sorting the paths
longest first, so for this to work for manual mountpoints, you
must ensure that the innermost mountpoints have the longest
pathnames, as in the example code above.

For more details see L<https://bugzilla.redhat.com/show_bug.cgi?id=599503>

Autosync [see C<$h-E<gt>set_autosync>, this is set by default on
handles] can cause C<$h-E<gt>umount_all> to be called when the handle
is closed which can also trigger these issues.

=item $h->mknod ($mode, $devmajor, $devminor, $path);

This call creates block or character special devices, or
named pipes (FIFOs).

The C<mode> parameter should be the mode, using the standard
constants.  C<devmajor> and C<devminor> are the
device major and minor numbers, only used when creating block
and character special devices.

Note that, just like L<mknod(2)>, the mode must be bitwise
OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK (otherwise this call
just creates a regular file).  These constants are
available in the standard Linux header files, or you can use
C<$h-E<gt>mknod_b>, C<$h-E<gt>mknod_c> or C<$h-E<gt>mkfifo>
which are wrappers around this command which bitwise OR
in the appropriate constant for you.

The mode actually set is affected by the umask.

=item $h->mknod_b ($mode, $devmajor, $devminor, $path);

This call creates a block device node called C<path> with
mode C<mode> and device major/minor C<devmajor> and C<devminor>.
It is just a convenient wrapper around C<$h-E<gt>mknod>.

The mode actually set is affected by the umask.

=item $h->mknod_c ($mode, $devmajor, $devminor, $path);

This call creates a char device node called C<path> with
mode C<mode> and device major/minor C<devmajor> and C<devminor>.
It is just a convenient wrapper around C<$h-E<gt>mknod>.

The mode actually set is affected by the umask.

=item $h->mkswap ($device);

Create a swap partition on C<device>.

=item $h->mkswap_L ($label, $device);

Create a swap partition on C<device> with label C<label>.

Note that you cannot attach a swap label to a block device
(eg. C</dev/sda>), just to a partition.  This appears to be
a limitation of the kernel or swap tools.

=item $h->mkswap_U ($uuid, $device);

Create a swap partition on C<device> with UUID C<uuid>.

=item $h->mkswap_file ($path);

Create a swap file.

This command just writes a swap file signature to an existing
file.  To create the file itself, use something like C<$h-E<gt>fallocate>.

=item $h->modprobe ($modulename);

This loads a kernel module in the appliance.

The kernel module must have been whitelisted when libguestfs
was built (see C<appliance/kmod.whitelist.in> in the source).

=item $h->mount ($device, $mountpoint);

Mount a guest disk at a position in the filesystem.  Block devices
are named C</dev/sda>, C</dev/sdb> and so on, as they were added to
the guest.  If those block devices contain partitions, they will have
the usual names (eg. C</dev/sda1>).  Also LVM C</dev/VG/LV>-style
names can be used.

The rules are the same as for L<mount(2)>:  A filesystem must
first be mounted on C</> before others can be mounted.  Other
filesystems can only be mounted on directories which already
exist.

The mounted filesystem is writable, if we have sufficient permissions
on the underlying device.

Before libguestfs 1.13.16, this call implicitly added the options
C<sync> and C<noatime>.  The C<sync> option greatly slowed
writes and caused many problems for users.  If your program
might need to work with older versions of libguestfs, use
C<$h-E<gt>mount_options> instead (using an empty string for the
first parameter if you don't want any options).

=item $h->mount_9p ($mounttag, $mountpoint [, options => $options]);

Mount the virtio-9p filesystem with the tag C<mounttag> on the
directory C<mountpoint>.

If required, C<trans=virtio> will be automatically added to the options.
Any other options required can be passed in the optional C<options>
parameter.

=item $h->mount_loop ($file, $mountpoint);

This command lets you mount C<file> (a filesystem image
in a file) on a mount point.  It is entirely equivalent to
the command C<mount -o loop file mountpoint>.

=item $h->mount_options ($options, $device, $mountpoint);

This is the same as the C<$h-E<gt>mount> command, but it
allows you to set the mount options as for the
L<mount(8)> I<-o> flag.

If the C<options> parameter is an empty string, then
no options are passed (all options default to whatever
the filesystem uses).

=item $h->mount_ro ($device, $mountpoint);

This is the same as the C<$h-E<gt>mount> command, but it
mounts the filesystem with the read-only (I<-o ro>) flag.

=item $h->mount_vfs ($options, $vfstype, $device, $mountpoint);

This is the same as the C<$h-E<gt>mount> command, but it
allows you to set both the mount options and the vfstype
as for the L<mount(8)> I<-o> and I<-t> flags.

=item %mps = $h->mountpoints ();

This call is similar to C<$h-E<gt>mounts>.  That call returns
a list of devices.  This one returns a hash table (map) of
device name to directory where the device is mounted.

=item @devices = $h->mounts ();

This returns the list of currently mounted filesystems.  It returns
the list of devices (eg. C</dev/sda1>, C</dev/VG/LV>).

Some internal mounts are not shown.

See also: C<$h-E<gt>mountpoints>

=item $h->mv ($src, $dest);

This moves a file from C<src> to C<dest> where C<dest> is
either a destination filename or destination directory.

=item $status = $h->ntfs_3g_probe ($rw, $device);

This command runs the L<ntfs-3g.probe(8)> command which probes
an NTFS C<device> for mountability.  (Not all NTFS volumes can
be mounted read-write, and some cannot be mounted at all).

C<rw> is a boolean flag.  Set it to true if you want to test
if the volume can be mounted read-write.  Set it to false if
you want to test if the volume can be mounted read-only.

The return value is an integer which C<0> if the operation
would succeed, or some non-zero value documented in the
L<ntfs-3g.probe(8)> manual page.

=item $h->ntfsresize ($device);

This command resizes an NTFS filesystem, expanding or
shrinking it to the size of the underlying device.

I<Note:> After the resize operation, the filesystem is marked
as requiring a consistency check (for safety).  You have to boot
into Windows to perform this check and clear this condition.
Furthermore, ntfsresize refuses to resize filesystems
which have been marked in this way.  So in effect it is
not possible to call ntfsresize multiple times on a single
filesystem without booting into Windows between each resize.

See also L<ntfsresize(8)>.

I<This function is deprecated.>
In new code, use the L</ntfsresize_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->ntfsresize_opts ($device [, size => $size] [, force => $force]);

This command resizes an NTFS filesystem, expanding or
shrinking it to the size of the underlying device.

The optional parameters are:

=over 4

=item C<size>

The new size (in bytes) of the filesystem.  If omitted, the filesystem
is resized to fit the container (eg. partition).

=item C<force>

If this option is true, then force the resize of the filesystem
even if the filesystem is marked as requiring a consistency check.

After the resize operation, the filesystem is always marked
as requiring a consistency check (for safety).  You have to boot
into Windows to perform this check and clear this condition.
If you I<don't> set the C<force> option then it is not
possible to call C<$h-E<gt>ntfsresize_opts> multiple times on a
single filesystem without booting into Windows between each resize.

=back

See also L<ntfsresize(8)>.

=item $h->ntfsresize_size ($device, $size);

This command is the same as C<$h-E<gt>ntfsresize> except that it
allows you to specify the new size (in bytes) explicitly.

I<This function is deprecated.>
In new code, use the L</ntfsresize_opts> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->part_add ($device, $prlogex, $startsect, $endsect);

This command adds a partition to C<device>.  If there is no partition
table on the device, call C<$h-E<gt>part_init> first.

The C<prlogex> parameter is the type of partition.  Normally you
should pass C<p> or C<primary> here, but MBR partition tables also
support C<l> (or C<logical>) and C<e> (or C<extended>) partition
types.

C<startsect> and C<endsect> are the start and end of the partition
in I<sectors>.  C<endsect> may be negative, which means it counts
backwards from the end of the disk (C<-1> is the last sector).

Creating a partition which covers the whole disk is not so easy.
Use C<$h-E<gt>part_disk> to do that.

=item $h->part_del ($device, $partnum);

This command deletes the partition numbered C<partnum> on C<device>.

Note that in the case of MBR partitioning, deleting an
extended partition also deletes any logical partitions
it contains.

=item $h->part_disk ($device, $parttype);

This command is simply a combination of C<$h-E<gt>part_init>
followed by C<$h-E<gt>part_add> to create a single primary partition
covering the whole disk.

C<parttype> is the partition table type, usually C<mbr> or C<gpt>,
but other possible values are described in C<$h-E<gt>part_init>.

=item $bootable = $h->part_get_bootable ($device, $partnum);

This command returns true if the partition C<partnum> on
C<device> has the bootable flag set.

See also C<$h-E<gt>part_set_bootable>.

=item $idbyte = $h->part_get_mbr_id ($device, $partnum);

Returns the MBR type byte (also known as the ID byte) from
the numbered partition C<partnum>.

Note that only MBR (old DOS-style) partitions have type bytes.
You will get undefined results for other partition table
types (see C<$h-E<gt>part_get_parttype>).

=item $parttype = $h->part_get_parttype ($device);

This command examines the partition table on C<device> and
returns the partition table type (format) being used.

Common return values include: C<msdos> (a DOS/Windows style MBR
partition table), C<gpt> (a GPT/EFI-style partition table).  Other
values are possible, although unusual.  See C<$h-E<gt>part_init>
for a full list.

=item $h->part_init ($device, $parttype);

This creates an empty partition table on C<device> of one of the
partition types listed below.  Usually C<parttype> should be
either C<msdos> or C<gpt> (for large disks).

Initially there are no partitions.  Following this, you should
call C<$h-E<gt>part_add> for each partition required.

Possible values for C<parttype> are:

=over 4

=item B<efi>

=item B<gpt>

Intel EFI / GPT partition table.

This is recommended for >= 2 TB partitions that will be accessed
from Linux and Intel-based Mac OS X.  It also has limited backwards
compatibility with the C<mbr> format.

=item B<mbr>

=item B<msdos>

The standard PC "Master Boot Record" (MBR) format used
by MS-DOS and Windows.  This partition type will B<only> work
for device sizes up to 2 TB.  For large disks we recommend
using C<gpt>.

=back

Other partition table types that may work but are not
supported include:

=over 4

=item B<aix>

AIX disk labels.

=item B<amiga>

=item B<rdb>

Amiga "Rigid Disk Block" format.

=item B<bsd>

BSD disk labels.

=item B<dasd>

DASD, used on IBM mainframes.

=item B<dvh>

MIPS/SGI volumes.

=item B<mac>

Old Mac partition format.  Modern Macs use C<gpt>.

=item B<pc98>

NEC PC-98 format, common in Japan apparently.

=item B<sun>

Sun disk labels.

=back

=item @partitions = $h->part_list ($device);

This command parses the partition table on C<device> and
returns the list of partitions found.

The fields in the returned structure are:

=over 4

=item B<part_num>

Partition number, counting from 1.

=item B<part_start>

Start of the partition I<in bytes>.  To get sectors you have to
divide by the device's sector size, see C<$h-E<gt>blockdev_getss>.

=item B<part_end>

End of the partition in bytes.

=item B<part_size>

Size of the partition in bytes.

=back

=item $h->part_set_bootable ($device, $partnum, $bootable);

This sets the bootable flag on partition numbered C<partnum> on
device C<device>.  Note that partitions are numbered from 1.

The bootable flag is used by some operating systems (notably
Windows) to determine which partition to boot from.  It is by
no means universally recognized.

=item $h->part_set_mbr_id ($device, $partnum, $idbyte);

Sets the MBR type byte (also known as the ID byte) of
the numbered partition C<partnum> to C<idbyte>.  Note
that the type bytes quoted in most documentation are
in fact hexadecimal numbers, but usually documented
without any leading "0x" which might be confusing.

Note that only MBR (old DOS-style) partitions have type bytes.
You will get undefined results for other partition table
types (see C<$h-E<gt>part_get_parttype>).

=item $h->part_set_name ($device, $partnum, $name);

This sets the partition name on partition numbered C<partnum> on
device C<device>.  Note that partitions are numbered from 1.

The partition name can only be set on certain types of partition
table.  This works on C<gpt> but not on C<mbr> partitions.

=item $device = $h->part_to_dev ($partition);

This function takes a partition name (eg. "/dev/sdb1") and
removes the partition number, returning the device name
(eg. "/dev/sdb").

The named partition must exist, for example as a string returned
from C<$h-E<gt>list_partitions>.

See also C<$h-E<gt>part_to_partnum>.

=item $partnum = $h->part_to_partnum ($partition);

This function takes a partition name (eg. "/dev/sdb1") and
returns the partition number (eg. C<1>).

The named partition must exist, for example as a string returned
from C<$h-E<gt>list_partitions>.

See also C<$h-E<gt>part_to_dev>.

=item $h->ping_daemon ();

This is a test probe into the guestfs daemon running inside
the qemu subprocess.  Calling this function checks that the
daemon responds to the ping message, without affecting the daemon
or attached block device(s) in any other way.

=item $content = $h->pread ($path, $count, $offset);

This command lets you read part of a file.  It reads C<count>
bytes of the file, starting at C<offset>, from file C<path>.

This may read fewer bytes than requested.  For further details
see the L<pread(2)> system call.

See also C<$h-E<gt>pwrite>, C<$h-E<gt>pread_device>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $content = $h->pread_device ($device, $count, $offset);

This command lets you read part of a file.  It reads C<count>
bytes of C<device>, starting at C<offset>.

This may read fewer bytes than requested.  For further details
see the L<pread(2)> system call.

See also C<$h-E<gt>pread>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->pvcreate ($device);

This creates an LVM physical volume on the named C<device>,
where C<device> should usually be a partition name such
as C</dev/sda1>.

=item $h->pvremove ($device);

This wipes a physical volume C<device> so that LVM will no longer
recognise it.

The implementation uses the C<pvremove> command which refuses to
wipe physical volumes that contain any volume groups, so you have
to remove those first.

=item $h->pvresize ($device);

This resizes (expands or shrinks) an existing LVM physical
volume to match the new size of the underlying device.

=item $h->pvresize_size ($device, $size);

This command is the same as C<$h-E<gt>pvresize> except that it
allows you to specify the new size (in bytes) explicitly.

=item @physvols = $h->pvs ();

List all the physical volumes detected.  This is the equivalent
of the L<pvs(8)> command.

This returns a list of just the device names that contain
PVs (eg. C</dev/sda2>).

See also C<$h-E<gt>pvs_full>.

=item @physvols = $h->pvs_full ();

List all the physical volumes detected.  This is the equivalent
of the L<pvs(8)> command.  The "full" version includes all fields.

=item $uuid = $h->pvuuid ($device);

This command returns the UUID of the LVM PV C<device>.

=item $nbytes = $h->pwrite ($path, $content, $offset);

This command writes to part of a file.  It writes the data
buffer C<content> to the file C<path> starting at offset C<offset>.

This command implements the L<pwrite(2)> system call, and like
that system call it may not write the full data requested.  The
return value is the number of bytes that were actually written
to the file.  This could even be 0, although short writes are
unlikely for regular files in ordinary circumstances.

See also C<$h-E<gt>pread>, C<$h-E<gt>pwrite_device>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $nbytes = $h->pwrite_device ($device, $content, $offset);

This command writes to part of a device.  It writes the data
buffer C<content> to C<device> starting at offset C<offset>.

This command implements the L<pwrite(2)> system call, and like
that system call it may not write the full data requested
(although short writes to disk devices and partitions are
probably impossible with standard Linux kernels).

See also C<$h-E<gt>pwrite>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $content = $h->read_file ($path);

This calls returns the contents of the file C<path> as a
buffer.

Unlike C<$h-E<gt>cat>, this function can correctly
handle files that contain embedded ASCII NUL characters.
However unlike C<$h-E<gt>download>, this function is limited
in the total size of file that can be handled.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->read_lines ($path);

Return the contents of the file named C<path>.

The file contents are returned as a list of lines.  Trailing
C<LF> and C<CRLF> character sequences are I<not> returned.

Note that this function cannot correctly handle binary files
(specifically, files containing C<\0> character which is treated
as end of line).  For those you need to use the C<$h-E<gt>read_file>
function which has a more complex interface.

=item @entries = $h->readdir ($dir);

This returns the list of directory entries in directory C<dir>.

All entries in the directory are returned, including C<.> and
C<..>.  The entries are I<not> sorted, but returned in the same
order as the underlying filesystem.

Also this call returns basic file type information about each
file.  The C<ftyp> field will contain one of the following characters:

=over 4

=item 'b'

Block special

=item 'c'

Char special

=item 'd'

Directory

=item 'f'

FIFO (named pipe)

=item 'l'

Symbolic link

=item 'r'

Regular file

=item 's'

Socket

=item 'u'

Unknown file type

=item '?'

The L<readdir(3)> call returned a C<d_type> field with an
unexpected value

=back

This function is primarily intended for use by programs.  To
get a simple list of names, use C<$h-E<gt>ls>.  To get a printable
directory for human consumption, use C<$h-E<gt>ll>.

=item $link = $h->readlink ($path);

This command reads the target of a symbolic link.

=item @links = $h->readlinklist ($path, \@names);

This call allows you to do a C<readlink> operation
on multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a list of strings, with a one-to-one
correspondence to the C<names> list.  Each string is the
value of the symbolic link.

If the C<readlink(2)> operation fails on any name, then
the corresponding result string is the empty string C<"">.
However the whole operation is completed even if there
were C<readlink(2)> errors, and so you can call this
function with names where you don't know if they are
symbolic links already (albeit slightly less efficient).

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.
Very long directory listings might cause the protocol
message size to be exceeded, causing
this call to fail.  The caller must split up such requests
into smaller groups of names.

=item $rpath = $h->realpath ($path);

Return the canonicalized absolute pathname of C<path>.  The
returned path has no C<.>, C<..> or symbolic link path elements.

=item $h->removexattr ($xattr, $path);

This call removes the extended attribute named C<xattr>
of the file C<path>.

See also: C<$h-E<gt>lremovexattr>, L<attr(5)>.

=item $h->resize2fs ($device);

This resizes an ext2, ext3 or ext4 filesystem to match the size of
the underlying device.

I<Note:> It is sometimes required that you run C<$h-E<gt>e2fsck_f>
on the C<device> before calling this command.  For unknown reasons
C<resize2fs> sometimes gives an error about this and sometimes not.
In any case, it is always safe to call C<$h-E<gt>e2fsck_f> before
calling this function.

=item $h->resize2fs_M ($device);

This command is the same as C<$h-E<gt>resize2fs>, but the filesystem
is resized to its minimum size.  This works like the I<-M> option
to the C<resize2fs> command.

To get the resulting size of the filesystem you should call
C<$h-E<gt>tune2fs_l> and read the C<Block size> and C<Block count>
values.  These two numbers, multiplied together, give the
resulting size of the minimal filesystem in bytes.

=item $h->resize2fs_size ($device, $size);

This command is the same as C<$h-E<gt>resize2fs> except that it
allows you to specify the new size (in bytes) explicitly.

=item $h->rm ($path);

Remove the single file C<path>.

=item $h->rm_rf ($path);

Remove the file or directory C<path>, recursively removing the
contents if its a directory.  This is like the C<rm -rf> shell
command.

=item $h->rmdir ($path);

Remove the single directory C<path>.

=item $h->rmmountpoint ($exemptpath);

This calls removes a mountpoint that was previously created
with C<$h-E<gt>mkmountpoint>.  See C<$h-E<gt>mkmountpoint>
for full details.

=item $h->scrub_device ($device);

This command writes patterns over C<device> to make data retrieval
more difficult.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $h->scrub_file ($file);

This command writes patterns over a file to make data retrieval
more difficult.

The file is I<removed> after scrubbing.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $h->scrub_freespace ($dir);

This command creates the directory C<dir> and then fills it
with files until the filesystem is full, and scrubs the files
as for C<$h-E<gt>scrub_file>, and deletes them.
The intention is to scrub any free space on the partition
containing C<dir>.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $h->set_append ($append);

This function is used to add additional options to the
guest kernel command line.

The default is C<NULL> unless overridden by setting
C<LIBGUESTFS_APPEND> environment variable.

Setting C<append> to C<NULL> means I<no> additional options
are passed (libguestfs always adds a few of its own).

=item $h->set_attach_method ($attachmethod);

Set the method that libguestfs uses to connect to the back end
guestfsd daemon.  Possible methods are:

=over 4

=item C<appliance>

Launch an appliance and connect to it.  This is the ordinary method
and the default.

=item C<unix:I<path>>

Connect to the Unix domain socket I<path>.

This method lets you connect to an existing daemon or (using
virtio-serial) to a live guest.  For more information, see
L<guestfs(3)/ATTACHING TO RUNNING DAEMONS>.

=back

=item $h->set_autosync ($autosync);

If C<autosync> is true, this enables autosync.  Libguestfs will make a
best effort attempt to make filesystems consistent and synchronized
when the handle is closed
(also if the program exits without closing handles).

This is enabled by default (since libguestfs 1.5.24, previously it was
disabled by default).

=item $h->set_direct ($direct);

If the direct appliance mode flag is enabled, then stdin and
stdout are passed directly through to the appliance once it
is launched.

One consequence of this is that log messages aren't caught
by the library and handled by C<$h-E<gt>set_log_message_callback>,
but go straight to stdout.

You probably don't want to use this unless you know what you
are doing.

The default is disabled.

=item $h->set_e2label ($device, $label);

This sets the ext2/3/4 filesystem label of the filesystem on
C<device> to C<label>.  Filesystem labels are limited to
16 characters.

You can use either C<$h-E<gt>tune2fs_l> or C<$h-E<gt>get_e2label>
to return the existing label on a filesystem.

=item $h->set_e2uuid ($device, $uuid);

This sets the ext2/3/4 filesystem UUID of the filesystem on
C<device> to C<uuid>.  The format of the UUID and alternatives
such as C<clear>, C<random> and C<time> are described in the
L<tune2fs(8)> manpage.

You can use either C<$h-E<gt>tune2fs_l> or C<$h-E<gt>get_e2uuid>
to return the existing UUID of a filesystem.

=item $h->set_memsize ($memsize);

This sets the memory size in megabytes allocated to the
qemu subprocess.  This only has any effect if called before
C<$h-E<gt>launch>.

You can also change this by setting the environment
variable C<LIBGUESTFS_MEMSIZE> before the handle is
created.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $h->set_network ($network);

If C<network> is true, then the network is enabled in the
libguestfs appliance.  The default is false.

This affects whether commands are able to access the network
(see L<guestfs(3)/RUNNING COMMANDS>).

You must call this before calling C<$h-E<gt>launch>, otherwise
it has no effect.

=item $h->set_path ($searchpath);

Set the path that libguestfs searches for kernel and initrd.img.

The default is C<$libdir/guestfs> unless overridden by setting
C<LIBGUESTFS_PATH> environment variable.

Setting C<path> to C<NULL> restores the default path.

=item $h->set_pgroup ($pgroup);

If C<pgroup> is true, child processes are placed into
their own process group.

The practical upshot of this is that signals like C<SIGINT> (from
users pressing C<^C>) won't be received by the child process.

The default for this flag is false, because usually you want
C<^C> to kill the subprocess.  Guestfish sets this flag to
true when used interactively, so that C<^C> can cancel
long-running commands gracefully (see C<$h-E<gt>user_cancel>).

=item $h->set_qemu ($qemu);

Set the qemu binary that we will use.

The default is chosen when the library was compiled by the
configure script.

You can also override this by setting the C<LIBGUESTFS_QEMU>
environment variable.

Setting C<qemu> to C<NULL> restores the default qemu binary.

Note that you should call this function as early as possible
after creating the handle.  This is because some pre-launch
operations depend on testing qemu features (by running C<qemu -help>).
If the qemu binary changes, we don't retest features, and
so you might see inconsistent results.  Using the environment
variable C<LIBGUESTFS_QEMU> is safest of all since that picks
the qemu binary at the same time as the handle is created.

=item $h->set_recovery_proc ($recoveryproc);

If this is called with the parameter C<false> then
C<$h-E<gt>launch> does not create a recovery process.  The
purpose of the recovery process is to stop runaway qemu
processes in the case where the main program aborts abruptly.

This only has any effect if called before C<$h-E<gt>launch>,
and the default is true.

About the only time when you would want to disable this is
if the main process will fork itself into the background
("daemonize" itself).  In this case the recovery process
thinks that the main program has disappeared and so kills
qemu, which is not very helpful.

=item $h->set_selinux ($selinux);

This sets the selinux flag that is passed to the appliance
at boot time.  The default is C<selinux=0> (disabled).

Note that if SELinux is enabled, it is always in
Permissive mode (C<enforcing=0>).

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $h->set_smp ($smp);

Change the number of virtual CPUs assigned to the appliance.  The
default is C<1>.  Increasing this may improve performance, though
often it has no effect.

This function must be called before C<$h-E<gt>launch>.

=item $h->set_trace ($trace);

If the command trace flag is set to 1, then libguestfs
calls, parameters and return values are traced.

If you want to trace C API calls into libguestfs (and
other libraries) then possibly a better way is to use
the external ltrace(1) command.

Command traces are disabled unless the environment variable
C<LIBGUESTFS_TRACE> is defined and set to C<1>.

Trace messages are normally sent to C<stderr>, unless you
register a callback to send them somewhere else (see
C<$h-E<gt>set_event_callback>).

=item $h->set_verbose ($verbose);

If C<verbose> is true, this turns on verbose messages.

Verbose messages are disabled unless the environment variable
C<LIBGUESTFS_DEBUG> is defined and set to C<1>.

Verbose messages are normally sent to C<stderr>, unless you
register a callback to send them somewhere else (see
C<$h-E<gt>set_event_callback>).

=item $h->setcon ($context);

This sets the SELinux security context of the daemon
to the string C<context>.

See the documentation about SELINUX in L<guestfs(3)>.

=item $h->setxattr ($xattr, $val, $vallen, $path);

This call sets the extended attribute named C<xattr>
of the file C<path> to the value C<val> (of length C<vallen>).
The value is arbitrary 8 bit data.

See also: C<$h-E<gt>lsetxattr>, L<attr(5)>.

=item $h->sfdisk ($device, $cyls, $heads, $sectors, \@lines);

This is a direct interface to the L<sfdisk(8)> program for creating
partitions on block devices.

C<device> should be a block device, for example C</dev/sda>.

C<cyls>, C<heads> and C<sectors> are the number of cylinders, heads
and sectors on the device, which are passed directly to sfdisk as
the I<-C>, I<-H> and I<-S> parameters.  If you pass C<0> for any
of these, then the corresponding parameter is omitted.  Usually for
'large' disks, you can just pass C<0> for these, but for small
(floppy-sized) disks, sfdisk (or rather, the kernel) cannot work
out the right geometry and you will need to tell it.

C<lines> is a list of lines that we feed to C<sfdisk>.  For more
information refer to the L<sfdisk(8)> manpage.

To create a single partition occupying the whole disk, you would
pass C<lines> as a single element list, when the single element being
the string C<,> (comma).

See also: C<$h-E<gt>sfdisk_l>, C<$h-E<gt>sfdisk_N>,
C<$h-E<gt>part_init>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->sfdiskM ($device, \@lines);

This is a simplified interface to the C<$h-E<gt>sfdisk>
command, where partition sizes are specified in megabytes
only (rounded to the nearest cylinder) and you don't need
to specify the cyls, heads and sectors parameters which
were rarely if ever used anyway.

See also: C<$h-E<gt>sfdisk>, the L<sfdisk(8)> manpage
and C<$h-E<gt>part_disk>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $h->sfdisk_N ($device, $partnum, $cyls, $heads, $sectors, $line);

This runs L<sfdisk(8)> option to modify just the single
partition C<n> (note: C<n> counts from 1).

For other parameters, see C<$h-E<gt>sfdisk>.  You should usually
pass C<0> for the cyls/heads/sectors parameters.

See also: C<$h-E<gt>part_add>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $partitions = $h->sfdisk_disk_geometry ($device);

This displays the disk geometry of C<device> read from the
partition table.  Especially in the case where the underlying
block device has been resized, this can be different from the
kernel's idea of the geometry (see C<$h-E<gt>sfdisk_kernel_geometry>).

The result is in human-readable format, and not designed to
be parsed.

=item $partitions = $h->sfdisk_kernel_geometry ($device);

This displays the kernel's idea of the geometry of C<device>.

The result is in human-readable format, and not designed to
be parsed.

=item $partitions = $h->sfdisk_l ($device);

This displays the partition table on C<device>, in the
human-readable output of the L<sfdisk(8)> command.  It is
not intended to be parsed.

See also: C<$h-E<gt>part_list>

I<This function is deprecated.>
In new code, use the L</part_list> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $output = $h->sh ($command);

This call runs a command from the guest filesystem via the
guest's C</bin/sh>.

This is like C<$h-E<gt>command>, but passes the command to:

 /bin/sh -c "command"

Depending on the guest's shell, this usually results in
wildcards being expanded, shell expressions being interpolated
and so on.

All the provisos about C<$h-E<gt>command> apply to this call.

=item @lines = $h->sh_lines ($command);

This is the same as C<$h-E<gt>sh>, but splits the result
into a list of lines.

See also: C<$h-E<gt>command_lines>

=item $h->sleep ($secs);

Sleep for C<secs> seconds.

=item %statbuf = $h->stat ($path);

Returns file information for the given C<path>.

This is the same as the C<stat(2)> system call.

=item %statbuf = $h->statvfs ($path);

Returns file system statistics for any mounted file system.
C<path> should be a file or directory in the mounted file system
(typically it is the mount point itself, but it doesn't need to be).

This is the same as the C<statvfs(2)> system call.

=item @stringsout = $h->strings ($path);

This runs the L<strings(1)> command on a file and returns
the list of printable strings found.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @stringsout = $h->strings_e ($encoding, $path);

This is like the C<$h-E<gt>strings> command, but allows you to
specify the encoding of strings that are looked for in
the source file C<path>.

Allowed encodings are:

=over 4

=item s

Single 7-bit-byte characters like ASCII and the ASCII-compatible
parts of ISO-8859-X (this is what C<$h-E<gt>strings> uses).

=item S

Single 8-bit-byte characters.

=item b

16-bit big endian strings such as those encoded in
UTF-16BE or UCS-2BE.

=item l (lower case letter L)

16-bit little endian such as UTF-16LE and UCS-2LE.
This is useful for examining binaries in Windows guests.

=item B

32-bit big endian such as UCS-4BE.

=item L

32-bit little endian such as UCS-4LE.

=back

The returned strings are transcoded to UTF-8.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->swapoff_device ($device);

This command disables the libguestfs appliance swap
device or partition named C<device>.
See C<$h-E<gt>swapon_device>.

=item $h->swapoff_file ($file);

This command disables the libguestfs appliance swap on file.

=item $h->swapoff_label ($label);

This command disables the libguestfs appliance swap on
labeled swap partition.

=item $h->swapoff_uuid ($uuid);

This command disables the libguestfs appliance swap partition
with the given UUID.

=item $h->swapon_device ($device);

This command enables the libguestfs appliance to use the
swap device or partition named C<device>.  The increased
memory is made available for all commands, for example
those run using C<$h-E<gt>command> or C<$h-E<gt>sh>.

Note that you should not swap to existing guest swap
partitions unless you know what you are doing.  They may
contain hibernation information, or other information that
the guest doesn't want you to trash.  You also risk leaking
information about the host to the guest this way.  Instead,
attach a new host device to the guest and swap on that.

=item $h->swapon_file ($file);

This command enables swap to a file.
See C<$h-E<gt>swapon_device> for other notes.

=item $h->swapon_label ($label);

This command enables swap to a labeled swap partition.
See C<$h-E<gt>swapon_device> for other notes.

=item $h->swapon_uuid ($uuid);

This command enables swap to a swap partition with the given UUID.
See C<$h-E<gt>swapon_device> for other notes.

=item $h->sync ();

This syncs the disk, so that any writes are flushed through to the
underlying disk image.

You should always call this if you have modified a disk image, before
closing the handle.

=item @lines = $h->tail ($path);

This command returns up to the last 10 lines of a file as
a list of strings.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->tail_n ($nrlines, $path);

If the parameter C<nrlines> is a positive number, this returns the last
C<nrlines> lines of the file C<path>.

If the parameter C<nrlines> is a negative number, this returns lines
from the file C<path>, starting with the C<-nrlines>th line.

If the parameter C<nrlines> is zero, this returns an empty list.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->tar_in ($tarfile, $directory);

This command uploads and unpacks local file C<tarfile> (an
I<uncompressed> tar file) into C<directory>.

To upload a compressed tarball, use C<$h-E<gt>tgz_in>
or C<$h-E<gt>txz_in>.

=item $h->tar_out ($directory, $tarfile);

This command packs the contents of C<directory> and downloads
it to local file C<tarfile>.

To download a compressed tarball, use C<$h-E<gt>tgz_out>
or C<$h-E<gt>txz_out>.

=item $h->tgz_in ($tarball, $directory);

This command uploads and unpacks local file C<tarball> (a
I<gzip compressed> tar file) into C<directory>.

To upload an uncompressed tarball, use C<$h-E<gt>tar_in>.

=item $h->tgz_out ($directory, $tarball);

This command packs the contents of C<directory> and downloads
it to local file C<tarball>.

To download an uncompressed tarball, use C<$h-E<gt>tar_out>.

=item $h->touch ($path);

Touch acts like the L<touch(1)> command.  It can be used to
update the timestamps on a file, or, if the file does not exist,
to create a new zero-length file.

This command only works on regular files, and will fail on other
file types such as directories, symbolic links, block special etc.

=item $h->truncate ($path);

This command truncates C<path> to a zero-length file.  The
file must exist already.

=item $h->truncate_size ($path, $size);

This command truncates C<path> to size C<size> bytes.  The file
must exist already.

If the current file size is less than C<size> then
the file is extended to the required size with zero bytes.
This creates a sparse file (ie. disk blocks are not allocated
for the file until you write to it).  To create a non-sparse
file of zeroes, use C<$h-E<gt>fallocate64> instead.

=item $h->tune2fs ($device [, force => $force] [, maxmountcount => $maxmountcount] [, mountcount => $mountcount] [, errorbehavior => $errorbehavior] [, group => $group] [, intervalbetweenchecks => $intervalbetweenchecks] [, reservedblockspercentage => $reservedblockspercentage] [, lastmounteddirectory => $lastmounteddirectory] [, reservedblockscount => $reservedblockscount] [, user => $user]);

This call allows you to adjust various filesystem parameters of
an ext2/ext3/ext4 filesystem called C<device>.

The optional parameters are:

=over 4

=item C<force>

Force tune2fs to complete the operation even in the face of errors.
This is the same as the tune2fs C<-f> option.

=item C<maxmountcount>

Set the number of mounts after which the filesystem is checked
by L<e2fsck(8)>.  If this is C<0> then the number of mounts is
disregarded.  This is the same as the tune2fs C<-c> option.

=item C<mountcount>

Set the number of times the filesystem has been mounted.
This is the same as the tune2fs C<-C> option.

=item C<errorbehavior>

Change the behavior of the kernel code when errors are detected.
Possible values currently are: C<continue>, C<remount-ro>, C<panic>.
In practice these options don't really make any difference,
particularly for write errors.

This is the same as the tune2fs C<-e> option.

=item C<group>

Set the group which can use reserved filesystem blocks.
This is the same as the tune2fs C<-g> option except that it
can only be specified as a number.

=item C<intervalbetweenchecks>

Adjust the maximal time between two filesystem checks
(in seconds).  If the option is passed as C<0> then
time-dependent checking is disabled.

This is the same as the tune2fs C<-i> option.

=item C<reservedblockspercentage>

Set the percentage of the filesystem which may only be allocated
by privileged processes.
This is the same as the tune2fs C<-m> option.

=item C<lastmounteddirectory>

Set the last mounted directory.
This is the same as the tune2fs C<-M> option.

=item C<reservedblockscount>
Set the number of reserved filesystem blocks.
This is the same as the tune2fs C<-r> option.

=item C<user>

Set the user who can use the reserved filesystem blocks.
This is the same as the tune2fs C<-u> option except that it
can only be specified as a number.

=back

To get the current values of filesystem parameters, see
C<$h-E<gt>tune2fs_l>.  For precise details of how tune2fs
works, see the L<tune2fs(8)> man page.

=item %superblock = $h->tune2fs_l ($device);

This returns the contents of the ext2, ext3 or ext4 filesystem
superblock on C<device>.

It is the same as running C<tune2fs -l device>.  See L<tune2fs(8)>
manpage for more details.  The list of fields returned isn't
clearly defined, and depends on both the version of C<tune2fs>
that libguestfs was built against, and the filesystem itself.

=item $h->txz_in ($tarball, $directory);

This command uploads and unpacks local file C<tarball> (an
I<xz compressed> tar file) into C<directory>.

=item $h->txz_out ($directory, $tarball);

This command packs the contents of C<directory> and downloads
it to local file C<tarball> (as an xz compressed tar archive).

=item $oldmask = $h->umask ($mask);

This function sets the mask used for creating new files and
device nodes to C<mask & 0777>.

Typical umask values would be C<022> which creates new files
with permissions like "-rw-r--r--" or "-rwxr-xr-x", and
C<002> which creates new files with permissions like
"-rw-rw-r--" or "-rwxrwxr-x".

The default umask is C<022>.  This is important because it
means that directories and device nodes will be created with
C<0644> or C<0755> mode even if you specify C<0777>.

See also C<$h-E<gt>get_umask>,
L<umask(2)>, C<$h-E<gt>mknod>, C<$h-E<gt>mkdir>.

This call returns the previous umask.

=item $h->umount ($pathordevice);

This unmounts the given filesystem.  The filesystem may be
specified either by its mountpoint (path) or the device which
contains the filesystem.

=item $h->umount_all ();

This unmounts all mounted filesystems.

Some internal mounts are not unmounted by this call.

=item $h->upload ($filename, $remotefilename);

Upload local file C<filename> to C<remotefilename> on the
filesystem.

C<filename> can also be a named pipe.

See also C<$h-E<gt>download>.

=item $h->upload_offset ($filename, $remotefilename, $offset);

Upload local file C<filename> to C<remotefilename> on the
filesystem.

C<remotefilename> is overwritten starting at the byte C<offset>
specified.  The intention is to overwrite parts of existing
files or devices, although if a non-existant file is specified
then it is created with a "hole" before C<offset>.  The
size of the data written is implicit in the size of the
source C<filename>.

Note that there is no limit on the amount of data that
can be uploaded with this call, unlike with C<$h-E<gt>pwrite>,
and this call always writes the full amount unless an
error occurs.

See also C<$h-E<gt>upload>, C<$h-E<gt>pwrite>.

=item $h->utimens ($path, $atsecs, $atnsecs, $mtsecs, $mtnsecs);

This command sets the timestamps of a file with nanosecond
precision.

C<atsecs, atnsecs> are the last access time (atime) in secs and
nanoseconds from the epoch.

C<mtsecs, mtnsecs> are the last modification time (mtime) in
secs and nanoseconds from the epoch.

If the C<*nsecs> field contains the special value C<-1> then
the corresponding timestamp is set to the current time.  (The
C<*secs> field is ignored in this case).

If the C<*nsecs> field contains the special value C<-2> then
the corresponding timestamp is left unchanged.  (The
C<*secs> field is ignored in this case).

=item %version = $h->version ();

Return the libguestfs version number that the program is linked
against.

Note that because of dynamic linking this is not necessarily
the version of libguestfs that you compiled against.  You can
compile the program, and then at runtime dynamically link
against a completely different C<libguestfs.so> library.

This call was added in version C<1.0.58>.  In previous
versions of libguestfs there was no way to get the version
number.  From C code you can use dynamic linker functions
to find out if this symbol exists (if it doesn't, then
it's an earlier version).

The call returns a structure with four elements.  The first
three (C<major>, C<minor> and C<release>) are numbers and
correspond to the usual version triplet.  The fourth element
(C<extra>) is a string and is normally empty, but may be
used for distro-specific information.

To construct the original version string:
C<$major.$minor.$release$extra>

See also: L<guestfs(3)/LIBGUESTFS VERSION NUMBERS>.

I<Note:> Don't use this call to test for availability
of features.  In enterprise distributions we backport
features from later versions into earlier versions,
making this an unreliable way to test for features.
Use C<$h-E<gt>available> instead.

=item $label = $h->vfs_label ($device);

This returns the filesystem label of the filesystem on
C<device>.

If the filesystem is unlabeled, this returns the empty string.

To find a filesystem from the label, use C<$h-E<gt>findfs_label>.

=item $fstype = $h->vfs_type ($device);

This command gets the filesystem type corresponding to
the filesystem on C<device>.

For most filesystems, the result is the name of the Linux
VFS module which would be used to mount this filesystem
if you mounted it without specifying the filesystem type.
For example a string such as C<ext3> or C<ntfs>.

=item $uuid = $h->vfs_uuid ($device);

This returns the filesystem UUID of the filesystem on
C<device>.

If the filesystem does not have a UUID, this returns the empty string.

To find a filesystem from the UUID, use C<$h-E<gt>findfs_uuid>.

=item $h->vg_activate ($activate, \@volgroups);

This command activates or (if C<activate> is false) deactivates
all logical volumes in the listed volume groups C<volgroups>.

This command is the same as running C<vgchange -a y|n volgroups...>

Note that if C<volgroups> is an empty list then B<all> volume groups
are activated or deactivated.

=item $h->vg_activate_all ($activate);

This command activates or (if C<activate> is false) deactivates
all logical volumes in all volume groups.

This command is the same as running C<vgchange -a y|n>

=item $h->vgcreate ($volgroup, \@physvols);

This creates an LVM volume group called C<volgroup>
from the non-empty list of physical volumes C<physvols>.

=item @uuids = $h->vglvuuids ($vgname);

Given a VG called C<vgname>, this returns the UUIDs of all
the logical volumes created in this volume group.

You can use this along with C<$h-E<gt>lvs> and C<$h-E<gt>lvuuid>
calls to associate logical volumes and volume groups.

See also C<$h-E<gt>vgpvuuids>.

=item @uuids = $h->vgpvuuids ($vgname);

Given a VG called C<vgname>, this returns the UUIDs of all
the physical volumes that this volume group resides on.

You can use this along with C<$h-E<gt>pvs> and C<$h-E<gt>pvuuid>
calls to associate physical volumes and volume groups.

See also C<$h-E<gt>vglvuuids>.

=item $h->vgremove ($vgname);

Remove an LVM volume group C<vgname>, (for example C<VG>).

This also forcibly removes all logical volumes in the volume
group (if any).

=item $h->vgrename ($volgroup, $newvolgroup);

Rename a volume group C<volgroup> with the new name C<newvolgroup>.

=item @volgroups = $h->vgs ();

List all the volumes groups detected.  This is the equivalent
of the L<vgs(8)> command.

This returns a list of just the volume group names that were
detected (eg. C<VolGroup00>).

See also C<$h-E<gt>vgs_full>.

=item @volgroups = $h->vgs_full ();

List all the volumes groups detected.  This is the equivalent
of the L<vgs(8)> command.  The "full" version includes all fields.

=item $h->vgscan ();

This rescans all block devices and rebuilds the list of LVM
physical volumes, volume groups and logical volumes.

=item $uuid = $h->vguuid ($vgname);

This command returns the UUID of the LVM VG named C<vgname>.

=item $h->wait_ready ();

This function is a no op.

In versions of the API E<lt> 1.0.71 you had to call this function
just after calling C<$h-E<gt>launch> to wait for the launch
to complete.  However this is no longer necessary because
C<$h-E<gt>launch> now does the waiting.

If you see any calls to this function in code then you can just
remove them, unless you want to retain compatibility with older
versions of the API.

I<This function is deprecated.>
In new code, use the L</launch> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $chars = $h->wc_c ($path);

This command counts the characters in a file, using the
C<wc -c> external command.

=item $lines = $h->wc_l ($path);

This command counts the lines in a file, using the
C<wc -l> external command.

=item $words = $h->wc_w ($path);

This command counts the words in a file, using the
C<wc -w> external command.

=item $h->write ($path, $content);

This call creates a file called C<path>.  The content of the
file is the string C<content> (which can contain any 8 bit data).

See also C<$h-E<gt>write_append>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->write_append ($path, $content);

This call appends C<content> to the end of file C<path>.  If
C<path> does not exist, then a new file is created.

See also C<$h-E<gt>write>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->write_file ($path, $content, $size);

This call creates a file called C<path>.  The contents of the
file is the string C<content> (which can contain any 8 bit data),
with length C<size>.

As a special case, if C<size> is C<0>
then the length is calculated using C<strlen> (so in this case
the content cannot contain embedded ASCII NULs).

I<NB.> Owing to a bug, writing content containing ASCII NUL
characters does I<not> work, even if the length is specified.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</write> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $h->zegrep ($regex, $path);

This calls the external C<zegrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->zegrepi ($regex, $path);

This calls the external C<zegrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $h->zero ($device);

This command writes zeroes over the first few blocks of C<device>.

How many blocks are zeroed isn't specified (but it's I<not> enough
to securely wipe the device).  It should be sufficient to remove
any partition tables, filesystem superblocks and so on.

If blocks are already zero, then this command avoids writing
zeroes.  This prevents the underlying device from becoming non-sparse
or growing unnecessarily.

See also: C<$h-E<gt>zero_device>, C<$h-E<gt>scrub_device>,
C<$h-E<gt>is_zero_device>

=item $h->zero_device ($device);

This command writes zeroes over the entire C<device>.  Compare
with C<$h-E<gt>zero> which just zeroes the first few blocks of
a device.

If blocks are already zero, then this command avoids writing
zeroes.  This prevents the underlying device from becoming non-sparse
or growing unnecessarily.

=item $h->zerofree ($device);

This runs the I<zerofree> program on C<device>.  This program
claims to zero unused inodes and disk blocks on an ext2/3
filesystem, thus making it possible to compress the filesystem
more effectively.

You should B<not> run this program if the filesystem is
mounted.

It is possible that using this program can damage the filesystem
or data on the filesystem.

=item @lines = $h->zfgrep ($pattern, $path);

This calls the external C<zfgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->zfgrepi ($pattern, $path);

This calls the external C<zfgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $description = $h->zfile ($meth, $path);

This command runs C<file> after first decompressing C<path>
using C<method>.

C<method> must be one of C<gzip>, C<compress> or C<bzip2>.

Since 1.0.63, use C<$h-E<gt>file> instead which can now
process compressed files.

I<This function is deprecated.>
In new code, use the L</file> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $h->zgrep ($regex, $path);

This calls the external C<zgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $h->zgrepi ($regex, $path);

This calls the external C<zgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=cut

use vars qw(%guestfs_introspection);
%guestfs_introspection = (
  "add_cdrom" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "add_cdrom",
    description => "add a CD-ROM disk image to examine",
  },
  "add_domain" => {
    ret => 'int',
    args => [
      [ 'dom', 'string', 0 ],
    ],
    optargs => {
      libvirturi => [ 'libvirturi', 'string', 0 ],
      readonly => [ 'readonly', 'bool', 1 ],
      iface => [ 'iface', 'string', 2 ],
      live => [ 'live', 'bool', 3 ],
      allowuuid => [ 'allowuuid', 'bool', 4 ],
      readonlydisk => [ 'readonlydisk', 'string', 5 ],
    },
    name => "add_domain",
    description => "add the disk(s) from a named libvirt domain",
  },
  "add_drive" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "add_drive",
    description => "add an image to examine or modify",
  },
  "add_drive_opts" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    optargs => {
      readonly => [ 'readonly', 'bool', 0 ],
      format => [ 'format', 'string', 1 ],
      iface => [ 'iface', 'string', 2 ],
      name => [ 'name', 'string', 3 ],
    },
    name => "add_drive_opts",
    description => "add an image to examine or modify",
  },
  "add_drive_ro" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "add_drive_ro",
    description => "add a drive in snapshot mode (read-only)",
  },
  "add_drive_ro_with_if" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
      [ 'iface', 'string', 1 ],
    ],
    name => "add_drive_ro_with_if",
    description => "add a drive read-only specifying the QEMU block emulation to use",
  },
  "add_drive_with_if" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
      [ 'iface', 'string', 1 ],
    ],
    name => "add_drive_with_if",
    description => "add a drive specifying the QEMU block emulation to use",
  },
  "aug_clear" => {
    ret => 'void',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_clear",
    description => "clear Augeas path",
  },
  "aug_close" => {
    ret => 'void',
    args => [
    ],
    name => "aug_close",
    description => "close the current Augeas handle",
  },
  "aug_defnode" => {
    ret => 'struct int_bool',
    args => [
      [ 'name', 'string', 0 ],
      [ 'expr', 'string', 1 ],
      [ 'val', 'string', 2 ],
    ],
    name => "aug_defnode",
    description => "define an Augeas node",
  },
  "aug_defvar" => {
    ret => 'int',
    args => [
      [ 'name', 'string', 0 ],
      [ 'expr', 'nullable string', 1 ],
    ],
    name => "aug_defvar",
    description => "define an Augeas variable",
  },
  "aug_get" => {
    ret => 'string',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_get",
    description => "look up the value of an Augeas path",
  },
  "aug_init" => {
    ret => 'void',
    args => [
      [ 'root', 'string(path)', 0 ],
      [ 'flags', 'int', 1 ],
    ],
    name => "aug_init",
    description => "create a new Augeas handle",
  },
  "aug_insert" => {
    ret => 'void',
    args => [
      [ 'augpath', 'string', 0 ],
      [ 'label', 'string', 1 ],
      [ 'before', 'bool', 2 ],
    ],
    name => "aug_insert",
    description => "insert a sibling Augeas node",
  },
  "aug_load" => {
    ret => 'void',
    args => [
    ],
    name => "aug_load",
    description => "load files into the tree",
  },
  "aug_ls" => {
    ret => 'string list',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_ls",
    description => "list Augeas nodes under augpath",
  },
  "aug_match" => {
    ret => 'string list',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_match",
    description => "return Augeas nodes which match augpath",
  },
  "aug_mv" => {
    ret => 'void',
    args => [
      [ 'src', 'string', 0 ],
      [ 'dest', 'string', 1 ],
    ],
    name => "aug_mv",
    description => "move Augeas node",
  },
  "aug_rm" => {
    ret => 'int',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_rm",
    description => "remove an Augeas path",
  },
  "aug_save" => {
    ret => 'void',
    args => [
    ],
    name => "aug_save",
    description => "write all pending Augeas changes to disk",
  },
  "aug_set" => {
    ret => 'void',
    args => [
      [ 'augpath', 'string', 0 ],
      [ 'val', 'string', 1 ],
    ],
    name => "aug_set",
    description => "set Augeas path to value",
  },
  "available" => {
    ret => 'void',
    args => [
      [ 'groups', 'string list', 0 ],
    ],
    name => "available",
    description => "test availability of some parts of the API",
  },
  "available_all_groups" => {
    ret => 'string list',
    args => [
    ],
    name => "available_all_groups",
    description => "return a list of all optional groups",
  },
  "base64_in" => {
    ret => 'void',
    args => [
      [ 'base64file', 'string(filename)', 0 ],
      [ 'filename', 'string(path)', 1 ],
    ],
    name => "base64_in",
    description => "upload base64-encoded data to file",
  },
  "base64_out" => {
    ret => 'void',
    args => [
      [ 'filename', 'string(path)', 0 ],
      [ 'base64file', 'string(filename)', 1 ],
    ],
    name => "base64_out",
    description => "download file and encode as base64",
  },
  "blkid" => {
    ret => 'hash',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blkid",
    description => "print block device attributes",
  },
  "blockdev_flushbufs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_flushbufs",
    description => "flush device buffers",
  },
  "blockdev_getbsz" => {
    ret => 'int',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_getbsz",
    description => "get blocksize of block device",
  },
  "blockdev_getro" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_getro",
    description => "is block device set to read-only",
  },
  "blockdev_getsize64" => {
    ret => 'int64',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_getsize64",
    description => "get total size of device in bytes",
  },
  "blockdev_getss" => {
    ret => 'int',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_getss",
    description => "get sectorsize of block device",
  },
  "blockdev_getsz" => {
    ret => 'int64',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_getsz",
    description => "get total size of device in 512-byte sectors",
  },
  "blockdev_rereadpt" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_rereadpt",
    description => "reread partition table",
  },
  "blockdev_setbsz" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'blocksize', 'int', 1 ],
    ],
    name => "blockdev_setbsz",
    description => "set blocksize of block device",
  },
  "blockdev_setro" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_setro",
    description => "set block device to read-only",
  },
  "blockdev_setrw" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blockdev_setrw",
    description => "set block device to read-write",
  },
  "btrfs_filesystem_resize" => {
    ret => 'void',
    args => [
      [ 'mountpoint', 'string(path)', 0 ],
    ],
    optargs => {
      size => [ 'size', 'int64', 0 ],
    },
    name => "btrfs_filesystem_resize",
    description => "resize a btrfs filesystem",
  },
  "case_sensitive_path" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "case_sensitive_path",
    description => "return true path on case-insensitive filesystem",
  },
  "cat" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "cat",
    description => "list the contents of a file",
  },
  "checksum" => {
    ret => 'string',
    args => [
      [ 'csumtype', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "checksum",
    description => "compute MD5, SHAx or CRC checksum of file",
  },
  "checksum_device" => {
    ret => 'string',
    args => [
      [ 'csumtype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "checksum_device",
    description => "compute MD5, SHAx or CRC checksum of the contents of a device",
  },
  "checksums_out" => {
    ret => 'void',
    args => [
      [ 'csumtype', 'string', 0 ],
      [ 'directory', 'string(path)', 1 ],
      [ 'sumsfile', 'string(filename)', 2 ],
    ],
    name => "checksums_out",
    description => "compute MD5, SHAx or CRC checksum of files in a directory",
  },
  "chmod" => {
    ret => 'void',
    args => [
      [ 'mode', 'int', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "chmod",
    description => "change file mode",
  },
  "chown" => {
    ret => 'void',
    args => [
      [ 'owner', 'int', 0 ],
      [ 'group', 'int', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "chown",
    description => "change file owner and group",
  },
  "command" => {
    ret => 'string',
    args => [
      [ 'arguments', 'string list', 0 ],
    ],
    name => "command",
    description => "run a command from the guest filesystem",
  },
  "command_lines" => {
    ret => 'string list',
    args => [
      [ 'arguments', 'string list', 0 ],
    ],
    name => "command_lines",
    description => "run a command, returning lines",
  },
  "compress_device_out" => {
    ret => 'void',
    args => [
      [ 'ctype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
      [ 'zdevice', 'string(filename)', 2 ],
    ],
    optargs => {
      level => [ 'level', 'int', 0 ],
    },
    name => "compress_device_out",
    description => "output compressed device",
  },
  "compress_out" => {
    ret => 'void',
    args => [
      [ 'ctype', 'string', 0 ],
      [ 'file', 'string(path)', 1 ],
      [ 'zfile', 'string(filename)', 2 ],
    ],
    optargs => {
      level => [ 'level', 'int', 0 ],
    },
    name => "compress_out",
    description => "output compressed file",
  },
  "config" => {
    ret => 'void',
    args => [
      [ 'qemuparam', 'string', 0 ],
      [ 'qemuvalue', 'nullable string', 1 ],
    ],
    name => "config",
    description => "add qemu parameters",
  },
  "copy_device_to_device" => {
    ret => 'void',
    args => [
      [ 'src', 'string(device)', 0 ],
      [ 'dest', 'string(device)', 1 ],
    ],
    optargs => {
      srcoffset => [ 'srcoffset', 'int64', 0 ],
      destoffset => [ 'destoffset', 'int64', 1 ],
      size => [ 'size', 'int64', 2 ],
    },
    name => "copy_device_to_device",
    description => "copy from source device to destination device",
  },
  "copy_device_to_file" => {
    ret => 'void',
    args => [
      [ 'src', 'string(device)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      srcoffset => [ 'srcoffset', 'int64', 0 ],
      destoffset => [ 'destoffset', 'int64', 1 ],
      size => [ 'size', 'int64', 2 ],
    },
    name => "copy_device_to_file",
    description => "copy from source device to destination file",
  },
  "copy_file_to_device" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(device)', 1 ],
    ],
    optargs => {
      srcoffset => [ 'srcoffset', 'int64', 0 ],
      destoffset => [ 'destoffset', 'int64', 1 ],
      size => [ 'size', 'int64', 2 ],
    },
    name => "copy_file_to_device",
    description => "copy from source file to destination device",
  },
  "copy_file_to_file" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      srcoffset => [ 'srcoffset', 'int64', 0 ],
      destoffset => [ 'destoffset', 'int64', 1 ],
      size => [ 'size', 'int64', 2 ],
    },
    name => "copy_file_to_file",
    description => "copy from source file to destination file",
  },
  "copy_size" => {
    ret => 'void',
    args => [
      [ 'src', 'string(dev_or_path)', 0 ],
      [ 'dest', 'string(dev_or_path)', 1 ],
      [ 'size', 'int64', 2 ],
    ],
    name => "copy_size",
    description => "copy size bytes from source to destination using dd",
  },
  "cp" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    name => "cp",
    description => "copy a file",
  },
  "cp_a" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    name => "cp_a",
    description => "copy a file or directory recursively",
  },
  "dd" => {
    ret => 'void',
    args => [
      [ 'src', 'string(dev_or_path)', 0 ],
      [ 'dest', 'string(dev_or_path)', 1 ],
    ],
    name => "dd",
    description => "copy from source to destination using dd",
  },
  "debug" => {
    ret => 'string',
    args => [
      [ 'subcmd', 'string', 0 ],
      [ 'extraargs', 'string list', 1 ],
    ],
    name => "debug",
    description => "debugging and internals",
  },
  "debug_cmdline" => {
    ret => 'string list',
    args => [
    ],
    name => "debug_cmdline",
    description => "debug the QEMU command line (internal use only)",
  },
  "debug_drives" => {
    ret => 'string list',
    args => [
    ],
    name => "debug_drives",
    description => "debug the drives (internal use only)",
  },
  "debug_upload" => {
    ret => 'void',
    args => [
      [ 'filename', 'string(filename)', 0 ],
      [ 'tmpname', 'string', 1 ],
      [ 'mode', 'int', 2 ],
    ],
    name => "debug_upload",
    description => "upload a file to the appliance (internal use only)",
  },
  "df" => {
    ret => 'string',
    args => [
    ],
    name => "df",
    description => "report file system disk space usage",
  },
  "df_h" => {
    ret => 'string',
    args => [
    ],
    name => "df_h",
    description => "report file system disk space usage (human readable)",
  },
  "dmesg" => {
    ret => 'string',
    args => [
    ],
    name => "dmesg",
    description => "return kernel messages",
  },
  "download" => {
    ret => 'void',
    args => [
      [ 'remotefilename', 'string(dev_or_path)', 0 ],
      [ 'filename', 'string(filename)', 1 ],
    ],
    name => "download",
    description => "download a file to the local machine",
  },
  "download_offset" => {
    ret => 'void',
    args => [
      [ 'remotefilename', 'string(dev_or_path)', 0 ],
      [ 'filename', 'string(filename)', 1 ],
      [ 'offset', 'int64', 2 ],
      [ 'size', 'int64', 3 ],
    ],
    name => "download_offset",
    description => "download a file to the local machine with offset and size",
  },
  "drop_caches" => {
    ret => 'void',
    args => [
      [ 'whattodrop', 'int', 0 ],
    ],
    name => "drop_caches",
    description => "drop kernel page cache, dentries and inodes",
  },
  "du" => {
    ret => 'int64',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "du",
    description => "estimate file space usage",
  },
  "e2fsck" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      correct => [ 'correct', 'bool', 0 ],
      forceall => [ 'forceall', 'bool', 1 ],
    },
    name => "e2fsck",
    description => "check an ext2/ext3 filesystem",
  },
  "e2fsck_f" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "e2fsck_f",
    description => "check an ext2/ext3 filesystem",
  },
  "echo_daemon" => {
    ret => 'string',
    args => [
      [ 'words', 'string list', 0 ],
    ],
    name => "echo_daemon",
    description => "echo arguments back to the client",
  },
  "egrep" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "egrep",
    description => "return lines matching a pattern",
  },
  "egrepi" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "egrepi",
    description => "return lines matching a pattern",
  },
  "equal" => {
    ret => 'bool',
    args => [
      [ 'file1', 'string(path)', 0 ],
      [ 'file2', 'string(path)', 1 ],
    ],
    name => "equal",
    description => "test if two files have equal contents",
  },
  "exists" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "exists",
    description => "test if file or directory exists",
  },
  "fallocate" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'len', 'int', 1 ],
    ],
    name => "fallocate",
    description => "preallocate a file in the guest filesystem",
  },
  "fallocate64" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'len', 'int64', 1 ],
    ],
    name => "fallocate64",
    description => "preallocate a file in the guest filesystem",
  },
  "fgrep" => {
    ret => 'string list',
    args => [
      [ 'pattern', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "fgrep",
    description => "return lines matching a pattern",
  },
  "fgrepi" => {
    ret => 'string list',
    args => [
      [ 'pattern', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "fgrepi",
    description => "return lines matching a pattern",
  },
  "file" => {
    ret => 'string',
    args => [
      [ 'path', 'string(dev_or_path)', 0 ],
    ],
    name => "file",
    description => "determine file type",
  },
  "file_architecture" => {
    ret => 'string',
    args => [
      [ 'filename', 'string(path)', 0 ],
    ],
    name => "file_architecture",
    description => "detect the architecture of a binary file",
  },
  "filesize" => {
    ret => 'int64',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "filesize",
    description => "return the size of the file in bytes",
  },
  "fill" => {
    ret => 'void',
    args => [
      [ 'c', 'int', 0 ],
      [ 'len', 'int', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "fill",
    description => "fill a file with octets",
  },
  "fill_pattern" => {
    ret => 'void',
    args => [
      [ 'pattern', 'string', 0 ],
      [ 'len', 'int', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "fill_pattern",
    description => "fill a file with a repeating pattern of bytes",
  },
  "find" => {
    ret => 'string list',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "find",
    description => "find all files and directories",
  },
  "find0" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
      [ 'files', 'string(filename)', 1 ],
    ],
    name => "find0",
    description => "find all files and directories, returning NUL-separated list",
  },
  "findfs_label" => {
    ret => 'string',
    args => [
      [ 'label', 'string', 0 ],
    ],
    name => "findfs_label",
    description => "find a filesystem by label",
  },
  "findfs_uuid" => {
    ret => 'string',
    args => [
      [ 'uuid', 'string', 0 ],
    ],
    name => "findfs_uuid",
    description => "find a filesystem by UUID",
  },
  "fsck" => {
    ret => 'int',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "fsck",
    description => "run the filesystem checker",
  },
  "get_append" => {
    ret => 'const nullable string',
    args => [
    ],
    name => "get_append",
    description => "get the additional kernel options",
  },
  "get_attach_method" => {
    ret => 'string',
    args => [
    ],
    name => "get_attach_method",
    description => "get the attach method",
  },
  "get_autosync" => {
    ret => 'bool',
    args => [
    ],
    name => "get_autosync",
    description => "get autosync mode",
  },
  "get_direct" => {
    ret => 'bool',
    args => [
    ],
    name => "get_direct",
    description => "get direct appliance mode flag",
  },
  "get_e2label" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "get_e2label",
    description => "get the ext2/3/4 filesystem label",
  },
  "get_e2uuid" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "get_e2uuid",
    description => "get the ext2/3/4 filesystem UUID",
  },
  "get_memsize" => {
    ret => 'int',
    args => [
    ],
    name => "get_memsize",
    description => "get memory allocated to the qemu subprocess",
  },
  "get_network" => {
    ret => 'bool',
    args => [
    ],
    name => "get_network",
    description => "get enable network flag",
  },
  "get_path" => {
    ret => 'const string',
    args => [
    ],
    name => "get_path",
    description => "get the search path",
  },
  "get_pgroup" => {
    ret => 'bool',
    args => [
    ],
    name => "get_pgroup",
    description => "get process group flag",
  },
  "get_pid" => {
    ret => 'int',
    args => [
    ],
    name => "get_pid",
    description => "get PID of qemu subprocess",
  },
  "get_qemu" => {
    ret => 'const string',
    args => [
    ],
    name => "get_qemu",
    description => "get the qemu binary",
  },
  "get_recovery_proc" => {
    ret => 'bool',
    args => [
    ],
    name => "get_recovery_proc",
    description => "get recovery process enabled flag",
  },
  "get_selinux" => {
    ret => 'bool',
    args => [
    ],
    name => "get_selinux",
    description => "get SELinux enabled flag",
  },
  "get_smp" => {
    ret => 'int',
    args => [
    ],
    name => "get_smp",
    description => "get number of virtual CPUs in appliance",
  },
  "get_state" => {
    ret => 'int',
    args => [
    ],
    name => "get_state",
    description => "get the current state",
  },
  "get_trace" => {
    ret => 'bool',
    args => [
    ],
    name => "get_trace",
    description => "get command trace enabled flag",
  },
  "get_umask" => {
    ret => 'int',
    args => [
    ],
    name => "get_umask",
    description => "get the current umask",
  },
  "get_verbose" => {
    ret => 'bool',
    args => [
    ],
    name => "get_verbose",
    description => "get verbose mode",
  },
  "getcon" => {
    ret => 'string',
    args => [
    ],
    name => "getcon",
    description => "get SELinux security context",
  },
  "getxattr" => {
    ret => 'buffer',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'name', 'string', 1 ],
    ],
    name => "getxattr",
    description => "get a single extended attribute",
  },
  "getxattrs" => {
    ret => 'struct xattr list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "getxattrs",
    description => "list extended attributes of a file or directory",
  },
  "glob_expand" => {
    ret => 'string list',
    args => [
      [ 'pattern', 'string(path)', 0 ],
    ],
    name => "glob_expand",
    description => "expand a wildcard path",
  },
  "grep" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "grep",
    description => "return lines matching a pattern",
  },
  "grepi" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "grepi",
    description => "return lines matching a pattern",
  },
  "grub_install" => {
    ret => 'void',
    args => [
      [ 'root', 'string(path)', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "grub_install",
    description => "install GRUB 1",
  },
  "head" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "head",
    description => "return first 10 lines of a file",
  },
  "head_n" => {
    ret => 'string list',
    args => [
      [ 'nrlines', 'int', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "head_n",
    description => "return first N lines of a file",
  },
  "hexdump" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "hexdump",
    description => "dump a file in hexadecimal",
  },
  "initrd_cat" => {
    ret => 'buffer',
    args => [
      [ 'initrdpath', 'string(path)', 0 ],
      [ 'filename', 'string', 1 ],
    ],
    name => "initrd_cat",
    description => "list the contents of a single file in an initrd",
  },
  "initrd_list" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "initrd_list",
    description => "list files in an initrd",
  },
  "inotify_add_watch" => {
    ret => 'int64',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'mask', 'int', 1 ],
    ],
    name => "inotify_add_watch",
    description => "add an inotify watch",
  },
  "inotify_close" => {
    ret => 'void',
    args => [
    ],
    name => "inotify_close",
    description => "close the inotify handle",
  },
  "inotify_files" => {
    ret => 'string list',
    args => [
    ],
    name => "inotify_files",
    description => "return list of watched files that had events",
  },
  "inotify_init" => {
    ret => 'void',
    args => [
      [ 'maxevents', 'int', 0 ],
    ],
    name => "inotify_init",
    description => "create an inotify handle",
  },
  "inotify_read" => {
    ret => 'struct inotify_event list',
    args => [
    ],
    name => "inotify_read",
    description => "return list of inotify events",
  },
  "inotify_rm_watch" => {
    ret => 'void',
    args => [
      [ 'wd', 'int', 0 ],
    ],
    name => "inotify_rm_watch",
    description => "remove an inotify watch",
  },
  "inspect_get_arch" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_arch",
    description => "get architecture of inspected operating system",
  },
  "inspect_get_distro" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_distro",
    description => "get distro of inspected operating system",
  },
  "inspect_get_drive_mappings" => {
    ret => 'hash',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_drive_mappings",
    description => "get drive letter mappings",
  },
  "inspect_get_filesystems" => {
    ret => 'string list',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_filesystems",
    description => "get filesystems associated with inspected operating system",
  },
  "inspect_get_format" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_format",
    description => "get format of inspected operating system",
  },
  "inspect_get_hostname" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_hostname",
    description => "get hostname of the operating system",
  },
  "inspect_get_icon" => {
    ret => 'buffer',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    optargs => {
      favicon => [ 'favicon', 'bool', 0 ],
      highquality => [ 'highquality', 'bool', 1 ],
    },
    name => "inspect_get_icon",
    description => "get the icon corresponding to this operating system",
  },
  "inspect_get_major_version" => {
    ret => 'int',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_major_version",
    description => "get major version of inspected operating system",
  },
  "inspect_get_minor_version" => {
    ret => 'int',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_minor_version",
    description => "get minor version of inspected operating system",
  },
  "inspect_get_mountpoints" => {
    ret => 'hash',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_mountpoints",
    description => "get mountpoints of inspected operating system",
  },
  "inspect_get_package_format" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_package_format",
    description => "get package format used by the operating system",
  },
  "inspect_get_package_management" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_package_management",
    description => "get package management tool used by the operating system",
  },
  "inspect_get_product_name" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_product_name",
    description => "get product name of inspected operating system",
  },
  "inspect_get_product_variant" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_product_variant",
    description => "get product variant of inspected operating system",
  },
  "inspect_get_roots" => {
    ret => 'string list',
    args => [
    ],
    name => "inspect_get_roots",
    description => "return list of operating systems found by last inspection",
  },
  "inspect_get_type" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_type",
    description => "get type of inspected operating system",
  },
  "inspect_get_windows_current_control_set" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_windows_current_control_set",
    description => "get Windows CurrentControlSet of inspected operating system",
  },
  "inspect_get_windows_systemroot" => {
    ret => 'string',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_get_windows_systemroot",
    description => "get Windows systemroot of inspected operating system",
  },
  "inspect_is_live" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_is_live",
    description => "get live flag for install disk",
  },
  "inspect_is_multipart" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_is_multipart",
    description => "get multipart flag for install disk",
  },
  "inspect_is_netinst" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_is_netinst",
    description => "get netinst (network installer) flag for install disk",
  },
  "inspect_list_applications" => {
    ret => 'struct application list',
    args => [
      [ 'root', 'string(device)', 0 ],
    ],
    name => "inspect_list_applications",
    description => "get list of applications installed in the operating system",
  },
  "inspect_os" => {
    ret => 'string list',
    args => [
    ],
    name => "inspect_os",
    description => "inspect disk and return list of operating systems found",
  },
  "internal_autosync" => {
    ret => 'void',
    args => [
    ],
    name => "internal_autosync",
    description => "internal autosync operation",
  },
  "is_blockdev" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_blockdev",
    description => "test if block device",
  },
  "is_busy" => {
    ret => 'bool',
    args => [
    ],
    name => "is_busy",
    description => "is busy processing a command",
  },
  "is_chardev" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_chardev",
    description => "test if character device",
  },
  "is_config" => {
    ret => 'bool',
    args => [
    ],
    name => "is_config",
    description => "is in configuration state",
  },
  "is_dir" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_dir",
    description => "test if a directory",
  },
  "is_fifo" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_fifo",
    description => "test if FIFO (named pipe)",
  },
  "is_file" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_file",
    description => "test if a regular file",
  },
  "is_launching" => {
    ret => 'bool',
    args => [
    ],
    name => "is_launching",
    description => "is launching subprocess",
  },
  "is_lv" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "is_lv",
    description => "test if device is a logical volume",
  },
  "is_ready" => {
    ret => 'bool',
    args => [
    ],
    name => "is_ready",
    description => "is ready to accept commands",
  },
  "is_socket" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_socket",
    description => "test if socket",
  },
  "is_symlink" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_symlink",
    description => "test if symbolic link",
  },
  "is_zero" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "is_zero",
    description => "test if a file contains all zero bytes",
  },
  "is_zero_device" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "is_zero_device",
    description => "test if a device contains all zero bytes",
  },
  "kill_subprocess" => {
    ret => 'void',
    args => [
    ],
    name => "kill_subprocess",
    description => "kill the qemu subprocess",
  },
  "launch" => {
    ret => 'void',
    args => [
    ],
    name => "launch",
    description => "launch the qemu subprocess",
  },
  "lchown" => {
    ret => 'void',
    args => [
      [ 'owner', 'int', 0 ],
      [ 'group', 'int', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "lchown",
    description => "change file owner and group",
  },
  "lgetxattr" => {
    ret => 'buffer',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'name', 'string', 1 ],
    ],
    name => "lgetxattr",
    description => "get a single extended attribute",
  },
  "lgetxattrs" => {
    ret => 'struct xattr list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "lgetxattrs",
    description => "list extended attributes of a file or directory",
  },
  "list_9p" => {
    ret => 'string list',
    args => [
    ],
    name => "list_9p",
    description => "list 9p filesystems",
  },
  "list_devices" => {
    ret => 'string list',
    args => [
    ],
    name => "list_devices",
    description => "list the block devices",
  },
  "list_dm_devices" => {
    ret => 'string list',
    args => [
    ],
    name => "list_dm_devices",
    description => "list device mapper devices",
  },
  "list_filesystems" => {
    ret => 'hash',
    args => [
    ],
    name => "list_filesystems",
    description => "list filesystems",
  },
  "list_md_devices" => {
    ret => 'string list',
    args => [
    ],
    name => "list_md_devices",
    description => "list Linux md (RAID) devices",
  },
  "list_partitions" => {
    ret => 'string list',
    args => [
    ],
    name => "list_partitions",
    description => "list the partitions",
  },
  "ll" => {
    ret => 'string',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "ll",
    description => "list the files in a directory (long format)",
  },
  "ln" => {
    ret => 'void',
    args => [
      [ 'target', 'string', 0 ],
      [ 'linkname', 'string(path)', 1 ],
    ],
    name => "ln",
    description => "create a hard link",
  },
  "ln_f" => {
    ret => 'void',
    args => [
      [ 'target', 'string', 0 ],
      [ 'linkname', 'string(path)', 1 ],
    ],
    name => "ln_f",
    description => "create a hard link",
  },
  "ln_s" => {
    ret => 'void',
    args => [
      [ 'target', 'string', 0 ],
      [ 'linkname', 'string(path)', 1 ],
    ],
    name => "ln_s",
    description => "create a symbolic link",
  },
  "ln_sf" => {
    ret => 'void',
    args => [
      [ 'target', 'string', 0 ],
      [ 'linkname', 'string(path)', 1 ],
    ],
    name => "ln_sf",
    description => "create a symbolic link",
  },
  "lremovexattr" => {
    ret => 'void',
    args => [
      [ 'xattr', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "lremovexattr",
    description => "remove extended attribute of a file or directory",
  },
  "ls" => {
    ret => 'string list',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "ls",
    description => "list the files in a directory",
  },
  "lsetxattr" => {
    ret => 'void',
    args => [
      [ 'xattr', 'string', 0 ],
      [ 'val', 'string', 1 ],
      [ 'vallen', 'int', 2 ],
      [ 'path', 'string(path)', 3 ],
    ],
    name => "lsetxattr",
    description => "set extended attribute of a file or directory",
  },
  "lstat" => {
    ret => 'struct stat',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "lstat",
    description => "get file information for a symbolic link",
  },
  "lstatlist" => {
    ret => 'struct stat list',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'names', 'string list', 1 ],
    ],
    name => "lstatlist",
    description => "lstat on multiple files",
  },
  "luks_add_key" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'newkey', 'string(key)', 2 ],
      [ 'keyslot', 'int', 3 ],
    ],
    name => "luks_add_key",
    description => "add a key on a LUKS encrypted device",
  },
  "luks_close" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "luks_close",
    description => "close a LUKS device",
  },
  "luks_format" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'keyslot', 'int', 2 ],
    ],
    name => "luks_format",
    description => "format a block device as a LUKS encrypted device",
  },
  "luks_format_cipher" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'keyslot', 'int', 2 ],
      [ 'cipher', 'string', 3 ],
    ],
    name => "luks_format_cipher",
    description => "format a block device as a LUKS encrypted device",
  },
  "luks_kill_slot" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'keyslot', 'int', 2 ],
    ],
    name => "luks_kill_slot",
    description => "remove a key from a LUKS encrypted device",
  },
  "luks_open" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'mapname', 'string', 2 ],
    ],
    name => "luks_open",
    description => "open a LUKS-encrypted block device",
  },
  "luks_open_ro" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'key', 'string(key)', 1 ],
      [ 'mapname', 'string', 2 ],
    ],
    name => "luks_open_ro",
    description => "open a LUKS-encrypted block device read-only",
  },
  "lvcreate" => {
    ret => 'void',
    args => [
      [ 'logvol', 'string', 0 ],
      [ 'volgroup', 'string', 1 ],
      [ 'mbytes', 'int', 2 ],
    ],
    name => "lvcreate",
    description => "create an LVM logical volume",
  },
  "lvm_canonical_lv_name" => {
    ret => 'string',
    args => [
      [ 'lvname', 'string(device)', 0 ],
    ],
    name => "lvm_canonical_lv_name",
    description => "get canonical name of an LV",
  },
  "lvm_clear_filter" => {
    ret => 'void',
    args => [
    ],
    name => "lvm_clear_filter",
    description => "clear LVM device filter",
  },
  "lvm_remove_all" => {
    ret => 'void',
    args => [
    ],
    name => "lvm_remove_all",
    description => "remove all LVM LVs, VGs and PVs",
  },
  "lvm_set_filter" => {
    ret => 'void',
    args => [
      [ 'devices', 'string(device) list', 0 ],
    ],
    name => "lvm_set_filter",
    description => "set LVM device filter",
  },
  "lvremove" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "lvremove",
    description => "remove an LVM logical volume",
  },
  "lvrename" => {
    ret => 'void',
    args => [
      [ 'logvol', 'string', 0 ],
      [ 'newlogvol', 'string', 1 ],
    ],
    name => "lvrename",
    description => "rename an LVM logical volume",
  },
  "lvresize" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'mbytes', 'int', 1 ],
    ],
    name => "lvresize",
    description => "resize an LVM logical volume",
  },
  "lvresize_free" => {
    ret => 'void',
    args => [
      [ 'lv', 'string(device)', 0 ],
      [ 'percent', 'int', 1 ],
    ],
    name => "lvresize_free",
    description => "expand an LV to fill free space",
  },
  "lvs" => {
    ret => 'string list',
    args => [
    ],
    name => "lvs",
    description => "list the LVM logical volumes (LVs)",
  },
  "lvs_full" => {
    ret => 'struct lvm_lv list',
    args => [
    ],
    name => "lvs_full",
    description => "list the LVM logical volumes (LVs)",
  },
  "lvuuid" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "lvuuid",
    description => "get the UUID of a logical volume",
  },
  "lxattrlist" => {
    ret => 'struct xattr list',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'names', 'string list', 1 ],
    ],
    name => "lxattrlist",
    description => "lgetxattr on multiple files",
  },
  "md_create" => {
    ret => 'void',
    args => [
      [ 'name', 'string', 0 ],
      [ 'devices', 'string(device) list', 1 ],
    ],
    optargs => {
      missingbitmap => [ 'missingbitmap', 'int64', 0 ],
      nrdevices => [ 'nrdevices', 'int', 1 ],
      spare => [ 'spare', 'int', 2 ],
      chunk => [ 'chunk', 'int64', 3 ],
      level => [ 'level', 'string', 4 ],
    },
    name => "md_create",
    description => "create a Linux md (RAID) device",
  },
  "md_detail" => {
    ret => 'hash',
    args => [
      [ 'md', 'string(device)', 0 ],
    ],
    name => "md_detail",
    description => "obtain metadata for an MD device",
  },
  "md_stop" => {
    ret => 'void',
    args => [
      [ 'md', 'string(device)', 0 ],
    ],
    name => "md_stop",
    description => "stop a Linux md (RAID) device",
  },
  "mkdir" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "mkdir",
    description => "create a directory",
  },
  "mkdir_mode" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'mode', 'int', 1 ],
    ],
    name => "mkdir_mode",
    description => "create a directory with a particular mode",
  },
  "mkdir_p" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "mkdir_p",
    description => "create a directory and parents",
  },
  "mkdtemp" => {
    ret => 'string',
    args => [
      [ 'tmpl', 'string(path)', 0 ],
    ],
    name => "mkdtemp",
    description => "create a temporary directory",
  },
  "mke2fs_J" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'blocksize', 'int', 1 ],
      [ 'device', 'string(device)', 2 ],
      [ 'journal', 'string(device)', 3 ],
    ],
    name => "mke2fs_J",
    description => "make ext2/3/4 filesystem with external journal",
  },
  "mke2fs_JL" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'blocksize', 'int', 1 ],
      [ 'device', 'string(device)', 2 ],
      [ 'label', 'string', 3 ],
    ],
    name => "mke2fs_JL",
    description => "make ext2/3/4 filesystem with external journal",
  },
  "mke2fs_JU" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'blocksize', 'int', 1 ],
      [ 'device', 'string(device)', 2 ],
      [ 'uuid', 'string', 3 ],
    ],
    name => "mke2fs_JU",
    description => "make ext2/3/4 filesystem with external journal",
  },
  "mke2journal" => {
    ret => 'void',
    args => [
      [ 'blocksize', 'int', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "mke2journal",
    description => "make ext2/3/4 external journal",
  },
  "mke2journal_L" => {
    ret => 'void',
    args => [
      [ 'blocksize', 'int', 0 ],
      [ 'label', 'string', 1 ],
      [ 'device', 'string(device)', 2 ],
    ],
    name => "mke2journal_L",
    description => "make ext2/3/4 external journal with label",
  },
  "mke2journal_U" => {
    ret => 'void',
    args => [
      [ 'blocksize', 'int', 0 ],
      [ 'uuid', 'string', 1 ],
      [ 'device', 'string(device)', 2 ],
    ],
    name => "mke2journal_U",
    description => "make ext2/3/4 external journal with UUID",
  },
  "mkfifo" => {
    ret => 'void',
    args => [
      [ 'mode', 'int', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "mkfifo",
    description => "make FIFO (named pipe)",
  },
  "mkfs" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "mkfs",
    description => "make a filesystem",
  },
  "mkfs_b" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'blocksize', 'int', 1 ],
      [ 'device', 'string(device)', 2 ],
    ],
    name => "mkfs_b",
    description => "make a filesystem with block size",
  },
  "mkfs_opts" => {
    ret => 'void',
    args => [
      [ 'fstype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    optargs => {
      blocksize => [ 'blocksize', 'int', 0 ],
      features => [ 'features', 'string', 1 ],
      inode => [ 'inode', 'int', 2 ],
      sectorsize => [ 'sectorsize', 'int', 3 ],
    },
    name => "mkfs_opts",
    description => "make a filesystem",
  },
  "mkmountpoint" => {
    ret => 'void',
    args => [
      [ 'exemptpath', 'string', 0 ],
    ],
    name => "mkmountpoint",
    description => "create a mountpoint",
  },
  "mknod" => {
    ret => 'void',
    args => [
      [ 'mode', 'int', 0 ],
      [ 'devmajor', 'int', 1 ],
      [ 'devminor', 'int', 2 ],
      [ 'path', 'string(path)', 3 ],
    ],
    name => "mknod",
    description => "make block, character or FIFO devices",
  },
  "mknod_b" => {
    ret => 'void',
    args => [
      [ 'mode', 'int', 0 ],
      [ 'devmajor', 'int', 1 ],
      [ 'devminor', 'int', 2 ],
      [ 'path', 'string(path)', 3 ],
    ],
    name => "mknod_b",
    description => "make block device node",
  },
  "mknod_c" => {
    ret => 'void',
    args => [
      [ 'mode', 'int', 0 ],
      [ 'devmajor', 'int', 1 ],
      [ 'devminor', 'int', 2 ],
      [ 'path', 'string(path)', 3 ],
    ],
    name => "mknod_c",
    description => "make char device node",
  },
  "mkswap" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "mkswap",
    description => "create a swap partition",
  },
  "mkswap_L" => {
    ret => 'void',
    args => [
      [ 'label', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "mkswap_L",
    description => "create a swap partition with a label",
  },
  "mkswap_U" => {
    ret => 'void',
    args => [
      [ 'uuid', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "mkswap_U",
    description => "create a swap partition with an explicit UUID",
  },
  "mkswap_file" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "mkswap_file",
    description => "create a swap file",
  },
  "modprobe" => {
    ret => 'void',
    args => [
      [ 'modulename', 'string', 0 ],
    ],
    name => "modprobe",
    description => "load a kernel module",
  },
  "mount" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'mountpoint', 'string', 1 ],
    ],
    name => "mount",
    description => "mount a guest disk at a position in the filesystem",
  },
  "mount_9p" => {
    ret => 'void',
    args => [
      [ 'mounttag', 'string', 0 ],
      [ 'mountpoint', 'string', 1 ],
    ],
    optargs => {
      options => [ 'options', 'string', 0 ],
    },
    name => "mount_9p",
    description => "mount 9p filesystem",
  },
  "mount_loop" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
      [ 'mountpoint', 'string(path)', 1 ],
    ],
    name => "mount_loop",
    description => "mount a file using the loop device",
  },
  "mount_options" => {
    ret => 'void',
    args => [
      [ 'options', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
      [ 'mountpoint', 'string', 2 ],
    ],
    name => "mount_options",
    description => "mount a guest disk with mount options",
  },
  "mount_ro" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'mountpoint', 'string', 1 ],
    ],
    name => "mount_ro",
    description => "mount a guest disk, read-only",
  },
  "mount_vfs" => {
    ret => 'void',
    args => [
      [ 'options', 'string', 0 ],
      [ 'vfstype', 'string', 1 ],
      [ 'device', 'string(device)', 2 ],
      [ 'mountpoint', 'string', 3 ],
    ],
    name => "mount_vfs",
    description => "mount a guest disk with mount options and vfstype",
  },
  "mountpoints" => {
    ret => 'hash',
    args => [
    ],
    name => "mountpoints",
    description => "show mountpoints",
  },
  "mounts" => {
    ret => 'string list',
    args => [
    ],
    name => "mounts",
    description => "show mounted filesystems",
  },
  "mv" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    name => "mv",
    description => "move a file",
  },
  "ntfs_3g_probe" => {
    ret => 'int',
    args => [
      [ 'rw', 'bool', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "ntfs_3g_probe",
    description => "probe NTFS volume",
  },
  "ntfsresize" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "ntfsresize",
    description => "resize an NTFS filesystem",
  },
  "ntfsresize_opts" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      size => [ 'size', 'int64', 0 ],
      force => [ 'force', 'bool', 1 ],
    },
    name => "ntfsresize_opts",
    description => "resize an NTFS filesystem",
  },
  "ntfsresize_size" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'size', 'int64', 1 ],
    ],
    name => "ntfsresize_size",
    description => "resize an NTFS filesystem (with size)",
  },
  "part_add" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'prlogex', 'string', 1 ],
      [ 'startsect', 'int64', 2 ],
      [ 'endsect', 'int64', 3 ],
    ],
    name => "part_add",
    description => "add a partition to the device",
  },
  "part_del" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_del",
    description => "delete a partition",
  },
  "part_disk" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'parttype', 'string', 1 ],
    ],
    name => "part_disk",
    description => "partition whole disk with a single primary partition",
  },
  "part_get_bootable" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_bootable",
    description => "return true if a partition is bootable",
  },
  "part_get_mbr_id" => {
    ret => 'int',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_mbr_id",
    description => "get the MBR type byte (ID byte) from a partition",
  },
  "part_get_parttype" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "part_get_parttype",
    description => "get the partition table type",
  },
  "part_init" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'parttype', 'string', 1 ],
    ],
    name => "part_init",
    description => "create an empty partition table",
  },
  "part_list" => {
    ret => 'struct partition list',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "part_list",
    description => "list partitions on a device",
  },
  "part_set_bootable" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'bootable', 'bool', 2 ],
    ],
    name => "part_set_bootable",
    description => "make a partition bootable",
  },
  "part_set_mbr_id" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'idbyte', 'int', 2 ],
    ],
    name => "part_set_mbr_id",
    description => "set the MBR type byte (ID byte) of a partition",
  },
  "part_set_name" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'name', 'string', 2 ],
    ],
    name => "part_set_name",
    description => "set partition name",
  },
  "part_to_dev" => {
    ret => 'string',
    args => [
      [ 'partition', 'string(device)', 0 ],
    ],
    name => "part_to_dev",
    description => "convert partition name to device name",
  },
  "part_to_partnum" => {
    ret => 'int',
    args => [
      [ 'partition', 'string(device)', 0 ],
    ],
    name => "part_to_partnum",
    description => "convert partition name to partition number",
  },
  "ping_daemon" => {
    ret => 'void',
    args => [
    ],
    name => "ping_daemon",
    description => "ping the guest daemon",
  },
  "pread" => {
    ret => 'buffer',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'count', 'int', 1 ],
      [ 'offset', 'int64', 2 ],
    ],
    name => "pread",
    description => "read part of a file",
  },
  "pread_device" => {
    ret => 'buffer',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'count', 'int', 1 ],
      [ 'offset', 'int64', 2 ],
    ],
    name => "pread_device",
    description => "read part of a device",
  },
  "pvcreate" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "pvcreate",
    description => "create an LVM physical volume",
  },
  "pvremove" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "pvremove",
    description => "remove an LVM physical volume",
  },
  "pvresize" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "pvresize",
    description => "resize an LVM physical volume",
  },
  "pvresize_size" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'size', 'int64', 1 ],
    ],
    name => "pvresize_size",
    description => "resize an LVM physical volume (with size)",
  },
  "pvs" => {
    ret => 'string list',
    args => [
    ],
    name => "pvs",
    description => "list the LVM physical volumes (PVs)",
  },
  "pvs_full" => {
    ret => 'struct lvm_pv list',
    args => [
    ],
    name => "pvs_full",
    description => "list the LVM physical volumes (PVs)",
  },
  "pvuuid" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "pvuuid",
    description => "get the UUID of a physical volume",
  },
  "pwrite" => {
    ret => 'int',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'content', 'buffer', 1 ],
      [ 'offset', 'int64', 2 ],
    ],
    name => "pwrite",
    description => "write to part of a file",
  },
  "pwrite_device" => {
    ret => 'int',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'content', 'buffer', 1 ],
      [ 'offset', 'int64', 2 ],
    ],
    name => "pwrite_device",
    description => "write to part of a device",
  },
  "read_file" => {
    ret => 'buffer',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "read_file",
    description => "read a file",
  },
  "read_lines" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "read_lines",
    description => "read file as lines",
  },
  "readdir" => {
    ret => 'struct dirent list',
    args => [
      [ 'dir', 'string(path)', 0 ],
    ],
    name => "readdir",
    description => "read directories entries",
  },
  "readlink" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "readlink",
    description => "read the target of a symbolic link",
  },
  "readlinklist" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'names', 'string list', 1 ],
    ],
    name => "readlinklist",
    description => "readlink on multiple files",
  },
  "realpath" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "realpath",
    description => "canonicalized absolute pathname",
  },
  "removexattr" => {
    ret => 'void',
    args => [
      [ 'xattr', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "removexattr",
    description => "remove extended attribute of a file or directory",
  },
  "resize2fs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "resize2fs",
    description => "resize an ext2, ext3 or ext4 filesystem",
  },
  "resize2fs_M" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "resize2fs_M",
    description => "resize an ext2, ext3 or ext4 filesystem to the minimum size",
  },
  "resize2fs_size" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'size', 'int64', 1 ],
    ],
    name => "resize2fs_size",
    description => "resize an ext2, ext3 or ext4 filesystem (with size)",
  },
  "rm" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "rm",
    description => "remove a file",
  },
  "rm_rf" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "rm_rf",
    description => "remove a file or directory recursively",
  },
  "rmdir" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "rmdir",
    description => "remove a directory",
  },
  "rmmountpoint" => {
    ret => 'void',
    args => [
      [ 'exemptpath', 'string', 0 ],
    ],
    name => "rmmountpoint",
    description => "remove a mountpoint",
  },
  "scrub_device" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "scrub_device",
    description => "scrub (securely wipe) a device",
  },
  "scrub_file" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "scrub_file",
    description => "scrub (securely wipe) a file",
  },
  "scrub_freespace" => {
    ret => 'void',
    args => [
      [ 'dir', 'string(path)', 0 ],
    ],
    name => "scrub_freespace",
    description => "scrub (securely wipe) free space",
  },
  "set_append" => {
    ret => 'void',
    args => [
      [ 'append', 'nullable string', 0 ],
    ],
    name => "set_append",
    description => "add options to kernel command line",
  },
  "set_attach_method" => {
    ret => 'void',
    args => [
      [ 'attachmethod', 'string', 0 ],
    ],
    name => "set_attach_method",
    description => "set the attach method",
  },
  "set_autosync" => {
    ret => 'void',
    args => [
      [ 'autosync', 'bool', 0 ],
    ],
    name => "set_autosync",
    description => "set autosync mode",
  },
  "set_direct" => {
    ret => 'void',
    args => [
      [ 'direct', 'bool', 0 ],
    ],
    name => "set_direct",
    description => "enable or disable direct appliance mode",
  },
  "set_e2label" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'label', 'string', 1 ],
    ],
    name => "set_e2label",
    description => "set the ext2/3/4 filesystem label",
  },
  "set_e2uuid" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'uuid', 'string', 1 ],
    ],
    name => "set_e2uuid",
    description => "set the ext2/3/4 filesystem UUID",
  },
  "set_memsize" => {
    ret => 'void',
    args => [
      [ 'memsize', 'int', 0 ],
    ],
    name => "set_memsize",
    description => "set memory allocated to the qemu subprocess",
  },
  "set_network" => {
    ret => 'void',
    args => [
      [ 'network', 'bool', 0 ],
    ],
    name => "set_network",
    description => "set enable network flag",
  },
  "set_path" => {
    ret => 'void',
    args => [
      [ 'searchpath', 'nullable string', 0 ],
    ],
    name => "set_path",
    description => "set the search path",
  },
  "set_pgroup" => {
    ret => 'void',
    args => [
      [ 'pgroup', 'bool', 0 ],
    ],
    name => "set_pgroup",
    description => "set process group flag",
  },
  "set_qemu" => {
    ret => 'void',
    args => [
      [ 'qemu', 'nullable string', 0 ],
    ],
    name => "set_qemu",
    description => "set the qemu binary",
  },
  "set_recovery_proc" => {
    ret => 'void',
    args => [
      [ 'recoveryproc', 'bool', 0 ],
    ],
    name => "set_recovery_proc",
    description => "enable or disable the recovery process",
  },
  "set_selinux" => {
    ret => 'void',
    args => [
      [ 'selinux', 'bool', 0 ],
    ],
    name => "set_selinux",
    description => "set SELinux enabled or disabled at appliance boot",
  },
  "set_smp" => {
    ret => 'void',
    args => [
      [ 'smp', 'int', 0 ],
    ],
    name => "set_smp",
    description => "set number of virtual CPUs in appliance",
  },
  "set_trace" => {
    ret => 'void',
    args => [
      [ 'trace', 'bool', 0 ],
    ],
    name => "set_trace",
    description => "enable or disable command traces",
  },
  "set_verbose" => {
    ret => 'void',
    args => [
      [ 'verbose', 'bool', 0 ],
    ],
    name => "set_verbose",
    description => "set verbose mode",
  },
  "setcon" => {
    ret => 'void',
    args => [
      [ 'context', 'string', 0 ],
    ],
    name => "setcon",
    description => "set SELinux security context",
  },
  "setxattr" => {
    ret => 'void',
    args => [
      [ 'xattr', 'string', 0 ],
      [ 'val', 'string', 1 ],
      [ 'vallen', 'int', 2 ],
      [ 'path', 'string(path)', 3 ],
    ],
    name => "setxattr",
    description => "set extended attribute of a file or directory",
  },
  "sfdisk" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'cyls', 'int', 1 ],
      [ 'heads', 'int', 2 ],
      [ 'sectors', 'int', 3 ],
      [ 'lines', 'string list', 4 ],
    ],
    name => "sfdisk",
    description => "create partitions on a block device",
  },
  "sfdiskM" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'lines', 'string list', 1 ],
    ],
    name => "sfdiskM",
    description => "create partitions on a block device",
  },
  "sfdisk_N" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'cyls', 'int', 2 ],
      [ 'heads', 'int', 3 ],
      [ 'sectors', 'int', 4 ],
      [ 'line', 'string', 5 ],
    ],
    name => "sfdisk_N",
    description => "modify a single partition on a block device",
  },
  "sfdisk_disk_geometry" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "sfdisk_disk_geometry",
    description => "display the disk geometry from the partition table",
  },
  "sfdisk_kernel_geometry" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "sfdisk_kernel_geometry",
    description => "display the kernel geometry",
  },
  "sfdisk_l" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "sfdisk_l",
    description => "display the partition table",
  },
  "sh" => {
    ret => 'string',
    args => [
      [ 'command', 'string', 0 ],
    ],
    name => "sh",
    description => "run a command via the shell",
  },
  "sh_lines" => {
    ret => 'string list',
    args => [
      [ 'command', 'string', 0 ],
    ],
    name => "sh_lines",
    description => "run a command via the shell returning lines",
  },
  "sleep" => {
    ret => 'void',
    args => [
      [ 'secs', 'int', 0 ],
    ],
    name => "sleep",
    description => "sleep for some seconds",
  },
  "stat" => {
    ret => 'struct stat',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "stat",
    description => "get file information",
  },
  "statvfs" => {
    ret => 'struct statvfs',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "statvfs",
    description => "get file system statistics",
  },
  "strings" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "strings",
    description => "print the printable strings in a file",
  },
  "strings_e" => {
    ret => 'string list',
    args => [
      [ 'encoding', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "strings_e",
    description => "print the printable strings in a file",
  },
  "swapoff_device" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "swapoff_device",
    description => "disable swap on device",
  },
  "swapoff_file" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "swapoff_file",
    description => "disable swap on file",
  },
  "swapoff_label" => {
    ret => 'void',
    args => [
      [ 'label', 'string', 0 ],
    ],
    name => "swapoff_label",
    description => "disable swap on labeled swap partition",
  },
  "swapoff_uuid" => {
    ret => 'void',
    args => [
      [ 'uuid', 'string', 0 ],
    ],
    name => "swapoff_uuid",
    description => "disable swap on swap partition by UUID",
  },
  "swapon_device" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "swapon_device",
    description => "enable swap on device",
  },
  "swapon_file" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "swapon_file",
    description => "enable swap on file",
  },
  "swapon_label" => {
    ret => 'void',
    args => [
      [ 'label', 'string', 0 ],
    ],
    name => "swapon_label",
    description => "enable swap on labeled swap partition",
  },
  "swapon_uuid" => {
    ret => 'void',
    args => [
      [ 'uuid', 'string', 0 ],
    ],
    name => "swapon_uuid",
    description => "enable swap on swap partition by UUID",
  },
  "sync" => {
    ret => 'void',
    args => [
    ],
    name => "sync",
    description => "sync disks, writes are flushed through to the disk image",
  },
  "tail" => {
    ret => 'string list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "tail",
    description => "return last 10 lines of a file",
  },
  "tail_n" => {
    ret => 'string list',
    args => [
      [ 'nrlines', 'int', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "tail_n",
    description => "return last N lines of a file",
  },
  "tar_in" => {
    ret => 'void',
    args => [
      [ 'tarfile', 'string(filename)', 0 ],
      [ 'directory', 'string(path)', 1 ],
    ],
    name => "tar_in",
    description => "unpack tarfile to directory",
  },
  "tar_out" => {
    ret => 'void',
    args => [
      [ 'directory', 'string', 0 ],
      [ 'tarfile', 'string(filename)', 1 ],
    ],
    name => "tar_out",
    description => "pack directory into tarfile",
  },
  "test0" => {
    ret => 'void',
    args => [
      [ 'str', 'string', 0 ],
      [ 'optstr', 'nullable string', 1 ],
      [ 'strlist', 'string list', 2 ],
      [ 'b', 'bool', 3 ],
      [ 'integer', 'int', 4 ],
      [ 'integer64', 'int64', 5 ],
      [ 'filein', 'string(filename)', 6 ],
      [ 'fileout', 'string(filename)', 7 ],
      [ 'bufferin', 'buffer', 8 ],
    ],
    optargs => {
      obool => [ 'obool', 'bool', 0 ],
      oint => [ 'oint', 'int', 1 ],
      oint64 => [ 'oint64', 'int64', 2 ],
      ostring => [ 'ostring', 'string', 3 ],
    },
    name => "test0",
    description => "internal test function - do not use",
  },
  "test0rbool" => {
    ret => 'bool',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rbool",
    description => "internal test function - do not use",
  },
  "test0rboolerr" => {
    ret => 'bool',
    args => [
    ],
    name => "test0rboolerr",
    description => "internal test function - do not use",
  },
  "test0rbufferout" => {
    ret => 'buffer',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rbufferout",
    description => "internal test function - do not use",
  },
  "test0rbufferouterr" => {
    ret => 'buffer',
    args => [
    ],
    name => "test0rbufferouterr",
    description => "internal test function - do not use",
  },
  "test0rconstoptstring" => {
    ret => 'const nullable string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rconstoptstring",
    description => "internal test function - do not use",
  },
  "test0rconstoptstringerr" => {
    ret => 'const nullable string',
    args => [
    ],
    name => "test0rconstoptstringerr",
    description => "internal test function - do not use",
  },
  "test0rconststring" => {
    ret => 'const string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rconststring",
    description => "internal test function - do not use",
  },
  "test0rconststringerr" => {
    ret => 'const string',
    args => [
    ],
    name => "test0rconststringerr",
    description => "internal test function - do not use",
  },
  "test0rhashtable" => {
    ret => 'hash',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rhashtable",
    description => "internal test function - do not use",
  },
  "test0rhashtableerr" => {
    ret => 'hash',
    args => [
    ],
    name => "test0rhashtableerr",
    description => "internal test function - do not use",
  },
  "test0rint" => {
    ret => 'int',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rint",
    description => "internal test function - do not use",
  },
  "test0rint64" => {
    ret => 'int64',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rint64",
    description => "internal test function - do not use",
  },
  "test0rint64err" => {
    ret => 'int64',
    args => [
    ],
    name => "test0rint64err",
    description => "internal test function - do not use",
  },
  "test0rinterr" => {
    ret => 'int',
    args => [
    ],
    name => "test0rinterr",
    description => "internal test function - do not use",
  },
  "test0rstring" => {
    ret => 'string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rstring",
    description => "internal test function - do not use",
  },
  "test0rstringerr" => {
    ret => 'string',
    args => [
    ],
    name => "test0rstringerr",
    description => "internal test function - do not use",
  },
  "test0rstringlist" => {
    ret => 'string list',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rstringlist",
    description => "internal test function - do not use",
  },
  "test0rstringlisterr" => {
    ret => 'string list',
    args => [
    ],
    name => "test0rstringlisterr",
    description => "internal test function - do not use",
  },
  "test0rstruct" => {
    ret => 'struct lvm_pv',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rstruct",
    description => "internal test function - do not use",
  },
  "test0rstructerr" => {
    ret => 'struct lvm_pv',
    args => [
    ],
    name => "test0rstructerr",
    description => "internal test function - do not use",
  },
  "test0rstructlist" => {
    ret => 'struct lvm_pv list',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "test0rstructlist",
    description => "internal test function - do not use",
  },
  "test0rstructlisterr" => {
    ret => 'struct lvm_pv list',
    args => [
    ],
    name => "test0rstructlisterr",
    description => "internal test function - do not use",
  },
  "tgz_in" => {
    ret => 'void',
    args => [
      [ 'tarball', 'string(filename)', 0 ],
      [ 'directory', 'string(path)', 1 ],
    ],
    name => "tgz_in",
    description => "unpack compressed tarball to directory",
  },
  "tgz_out" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
      [ 'tarball', 'string(filename)', 1 ],
    ],
    name => "tgz_out",
    description => "pack directory into compressed tarball",
  },
  "touch" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "touch",
    description => "update file timestamps or create a new file",
  },
  "truncate" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "truncate",
    description => "truncate a file to zero size",
  },
  "truncate_size" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'size', 'int64', 1 ],
    ],
    name => "truncate_size",
    description => "truncate a file to a particular size",
  },
  "tune2fs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      force => [ 'force', 'bool', 0 ],
      maxmountcount => [ 'maxmountcount', 'int', 1 ],
      mountcount => [ 'mountcount', 'int', 2 ],
      errorbehavior => [ 'errorbehavior', 'string', 3 ],
      group => [ 'group', 'int64', 4 ],
      intervalbetweenchecks => [ 'intervalbetweenchecks', 'int', 5 ],
      reservedblockspercentage => [ 'reservedblockspercentage', 'int', 6 ],
      lastmounteddirectory => [ 'lastmounteddirectory', 'string', 7 ],
      reservedblockscount => [ 'reservedblockscount', 'int64', 8 ],
      user => [ 'user', 'int64', 9 ],
    },
    name => "tune2fs",
    description => "adjust ext2/ext3/ext4 filesystem parameters",
  },
  "tune2fs_l" => {
    ret => 'hash',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "tune2fs_l",
    description => "get ext2/ext3/ext4 superblock details",
  },
  "txz_in" => {
    ret => 'void',
    args => [
      [ 'tarball', 'string(filename)', 0 ],
      [ 'directory', 'string(path)', 1 ],
    ],
    name => "txz_in",
    description => "unpack compressed tarball to directory",
  },
  "txz_out" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
      [ 'tarball', 'string(filename)', 1 ],
    ],
    name => "txz_out",
    description => "pack directory into compressed tarball",
  },
  "umask" => {
    ret => 'int',
    args => [
      [ 'mask', 'int', 0 ],
    ],
    name => "umask",
    description => "set file mode creation mask (umask)",
  },
  "umount" => {
    ret => 'void',
    args => [
      [ 'pathordevice', 'string', 0 ],
    ],
    name => "umount",
    description => "unmount a filesystem",
  },
  "umount_all" => {
    ret => 'void',
    args => [
    ],
    name => "umount_all",
    description => "unmount all filesystems",
  },
  "upload" => {
    ret => 'void',
    args => [
      [ 'filename', 'string(filename)', 0 ],
      [ 'remotefilename', 'string(dev_or_path)', 1 ],
    ],
    name => "upload",
    description => "upload a file from the local machine",
  },
  "upload_offset" => {
    ret => 'void',
    args => [
      [ 'filename', 'string(filename)', 0 ],
      [ 'remotefilename', 'string(dev_or_path)', 1 ],
      [ 'offset', 'int64', 2 ],
    ],
    name => "upload_offset",
    description => "upload a file from the local machine with offset",
  },
  "utimens" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'atsecs', 'int64', 1 ],
      [ 'atnsecs', 'int64', 2 ],
      [ 'mtsecs', 'int64', 3 ],
      [ 'mtnsecs', 'int64', 4 ],
    ],
    name => "utimens",
    description => "set timestamp of a file with nanosecond precision",
  },
  "version" => {
    ret => 'struct version',
    args => [
    ],
    name => "version",
    description => "get the library version number",
  },
  "vfs_label" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "vfs_label",
    description => "get the filesystem label",
  },
  "vfs_type" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "vfs_type",
    description => "get the Linux VFS type corresponding to a mounted device",
  },
  "vfs_uuid" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "vfs_uuid",
    description => "get the filesystem UUID",
  },
  "vg_activate" => {
    ret => 'void',
    args => [
      [ 'activate', 'bool', 0 ],
      [ 'volgroups', 'string list', 1 ],
    ],
    name => "vg_activate",
    description => "activate or deactivate some volume groups",
  },
  "vg_activate_all" => {
    ret => 'void',
    args => [
      [ 'activate', 'bool', 0 ],
    ],
    name => "vg_activate_all",
    description => "activate or deactivate all volume groups",
  },
  "vgcreate" => {
    ret => 'void',
    args => [
      [ 'volgroup', 'string', 0 ],
      [ 'physvols', 'string(device) list', 1 ],
    ],
    name => "vgcreate",
    description => "create an LVM volume group",
  },
  "vglvuuids" => {
    ret => 'string list',
    args => [
      [ 'vgname', 'string', 0 ],
    ],
    name => "vglvuuids",
    description => "get the LV UUIDs of all LVs in the volume group",
  },
  "vgpvuuids" => {
    ret => 'string list',
    args => [
      [ 'vgname', 'string', 0 ],
    ],
    name => "vgpvuuids",
    description => "get the PV UUIDs containing the volume group",
  },
  "vgremove" => {
    ret => 'void',
    args => [
      [ 'vgname', 'string', 0 ],
    ],
    name => "vgremove",
    description => "remove an LVM volume group",
  },
  "vgrename" => {
    ret => 'void',
    args => [
      [ 'volgroup', 'string', 0 ],
      [ 'newvolgroup', 'string', 1 ],
    ],
    name => "vgrename",
    description => "rename an LVM volume group",
  },
  "vgs" => {
    ret => 'string list',
    args => [
    ],
    name => "vgs",
    description => "list the LVM volume groups (VGs)",
  },
  "vgs_full" => {
    ret => 'struct lvm_vg list',
    args => [
    ],
    name => "vgs_full",
    description => "list the LVM volume groups (VGs)",
  },
  "vgscan" => {
    ret => 'void',
    args => [
    ],
    name => "vgscan",
    description => "rescan for LVM physical volumes, volume groups and logical volumes",
  },
  "vguuid" => {
    ret => 'string',
    args => [
      [ 'vgname', 'string', 0 ],
    ],
    name => "vguuid",
    description => "get the UUID of a volume group",
  },
  "wait_ready" => {
    ret => 'void',
    args => [
    ],
    name => "wait_ready",
    description => "wait until the qemu subprocess launches (no op)",
  },
  "wc_c" => {
    ret => 'int',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "wc_c",
    description => "count characters in a file",
  },
  "wc_l" => {
    ret => 'int',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "wc_l",
    description => "count lines in a file",
  },
  "wc_w" => {
    ret => 'int',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "wc_w",
    description => "count words in a file",
  },
  "write" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'content', 'buffer', 1 ],
    ],
    name => "write",
    description => "create a new file",
  },
  "write_append" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'content', 'buffer', 1 ],
    ],
    name => "write_append",
    description => "append content to end of file",
  },
  "write_file" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'content', 'string', 1 ],
      [ 'size', 'int', 2 ],
    ],
    name => "write_file",
    description => "create a file",
  },
  "zegrep" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zegrep",
    description => "return lines matching a pattern",
  },
  "zegrepi" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zegrepi",
    description => "return lines matching a pattern",
  },
  "zero" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "zero",
    description => "write zeroes to the device",
  },
  "zero_device" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "zero_device",
    description => "write zeroes to an entire device",
  },
  "zerofree" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "zerofree",
    description => "zero unused inodes and disk blocks on ext2/3 filesystem",
  },
  "zfgrep" => {
    ret => 'string list',
    args => [
      [ 'pattern', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zfgrep",
    description => "return lines matching a pattern",
  },
  "zfgrepi" => {
    ret => 'string list',
    args => [
      [ 'pattern', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zfgrepi",
    description => "return lines matching a pattern",
  },
  "zfile" => {
    ret => 'string',
    args => [
      [ 'meth', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zfile",
    description => "determine file type inside a compressed file",
  },
  "zgrep" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zgrep",
    description => "return lines matching a pattern",
  },
  "zgrepi" => {
    ret => 'string list',
    args => [
      [ 'regex', 'string', 0 ],
      [ 'path', 'string(path)', 1 ],
    ],
    name => "zgrepi",
    description => "return lines matching a pattern",
  },
);

1;

=back

=head1 AVAILABILITY

From time to time we add new libguestfs APIs.  Also some libguestfs
APIs won't be available in all builds of libguestfs (the Fedora
build is full-featured, but other builds may disable features).
How do you test whether the APIs that your Perl program needs are
available in the version of C<Sys::Guestfs> that you are using?

To test if a particular function is available in the C<Sys::Guestfs>
class, use the ordinary Perl UNIVERSAL method C<can(METHOD)>
(see L<perlobj(1)>).  For example:

 use Sys::Guestfs;
 if (defined (Sys::Guestfs->can ("set_verbose"))) {
   print "\$h->set_verbose is available\n";
 }

Perl does not offer a way to list the arguments of a method, and
from time to time we may add extra arguments to calls that take
optional arguments.  For this reason, we provide a global hash
variable C<%guestfs_introspection> which contains the arguments
and their types for each libguestfs method.  The keys of this
hash are the method names, and the values are an hashref
containing useful introspection information about the method
(further fields may be added to this in future).

 use Sys::Guestfs;
 $Sys::Guestfs::guestfs_introspection{mkfs_opts}
 => {
    ret => 'void',                    # return type
    args => [                         # required arguments
      [ 'fstype', 'string', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    optargs => {                      # optional arguments
      blocksize => [ 'blocksize', 'int', 0 ],
      features => [ 'features', 'string', 1 ],
      inode => [ 'inode', 'int', 2 ],
      sectorsize => [ 'sectorsize', 'int', 3 ],
    },
    name => "mkfs_opts",
    description => "make a filesystem",
  }

To test if particular features are supported by the current
build, use the L</available> method like the example below.  Note
that the appliance must be launched first.

 $h->available ( ["augeas"] );

Since the L</available> method croaks if the feature is not supported,
you might also want to wrap this in an eval and return a boolean.
In fact this has already been done for you: use
L<Sys::Guestfs::Lib(3)/feature_available>.

For further discussion on this topic, refer to
L<guestfs(3)/AVAILABILITY>.

=head1 STORING DATA IN THE HANDLE

The handle returned from L</new> is a hash reference.  The hash
normally contains a single element:

 {
   _g => [private data used by libguestfs]
 }

Callers can add other elements to this hash to store data for their own
purposes.  The data lasts for the lifetime of the handle.

Any fields whose names begin with an underscore are reserved
for private use by libguestfs.  We may add more in future.

It is recommended that callers prefix the name of their field(s)
with some unique string, to avoid conflicts with other users.

=head1 COPYRIGHT

Copyright (C) 2009-2012 Red Hat Inc.

=head1 LICENSE

Please see the file COPYING.LIB for the full license.

=head1 SEE ALSO

L<guestfs(3)>,
L<guestfish(1)>,
L<http://libguestfs.org>,
L<Sys::Guestfs::Lib(3)>.

=cut
