# libguestfs generated file
# WARNING: THIS FILE IS GENERATED FROM:
#   generator/ *.ml
# ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
#
# Copyright (C) 2009-2015 Red Hat Inc.
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

 my $g = Sys::Guestfs->new ();
 $g->add_drive_opts ('guest.img', format => 'raw');
 $g->launch ();
 $g->mount ('/dev/sda1', '/');
 $g->touch ('/hello');
 $g->shutdown ();
 $g->close ();

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
$VERSION = '0.456';

require XSLoader;
XSLoader::load ('Sys::Guestfs');

=item $g = Sys::Guestfs->new ([environment => 0,] [close_on_exit => 0]);

Create a new guestfs handle.

If the optional argument C<environment> is false, then
the C<GUESTFS_CREATE_NO_ENVIRONMENT> flag is set.

If the optional argument C<close_on_exit> is false, then
the C<GUESTFS_CREATE_NO_CLOSE_ON_EXIT> flag is set.

=cut

sub new {
  my $proto = shift;
  my $class = ref ($proto) || $proto;
  my %flags = @_;

  my $flags = 0;
  $flags |= 1 if exists $flags{environment} && !$flags{environment};
  $flags |= 2 if exists $flags{close_on_exit} && !$flags{close_on_exit};

  my $g = Sys::Guestfs::_create ($flags);
  my $self = { _g => $g, _flags => $flags };
  bless $self, $class;

  # If we don't do this, the program name is always set to 'perl'.
  my $program = $0;
  $program =~ s{.*/}{};
  $self->set_program ($program);

  return $self;
}

=item $g->close ();

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

=item $Sys::Guestfs::EVENT_LIBVIRT_AUTH

See L<guestfs(3)/GUESTFS_EVENT_LIBVIRT_AUTH>.

=cut

our $EVENT_LIBVIRT_AUTH = 0x100;

=item $Sys::Guestfs::EVENT_WARNING

See L<guestfs(3)/GUESTFS_EVENT_WARNING>.

=cut

our $EVENT_WARNING = 0x200;

=item $Sys::Guestfs::EVENT_ALL

See L<guestfs(3)/GUESTFS_EVENT_ALL>.

=cut

our $EVENT_ALL = 0x3ff;

=item $event_handle = $g->set_event_callback (\&cb, $event_bitmask);

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

=item $g->delete_event_callback ($event_handle);

This removes the callback which was previously registered using
C<set_event_callback>.

=item $str = Sys::Guestfs::event_to_string ($events);

C<$events> is either a single event or a bitmask of events.
This returns a printable string, useful for debugging.

Note that this is a class function, not a method.

=item $errnum = $g->last_errno ();

This returns the last error number (errno) that happened on the
handle C<$g>.

If successful, an errno integer not equal to zero is returned.

If no error number is available, this returns 0.
See L<guestfs(3)/guestfs_last_errno> for more details of why
this can happen.

You can use the standard Perl module L<Errno(3)> to compare
the numeric error returned from this call with symbolic
errnos:

 $g->mkdir ("/foo");
 if ($g->last_errno() == Errno::EEXIST()) {
   # mkdir failed because the directory exists already.
 }

=cut

=item $g->acl_delete_def_file ($dir);

This function deletes the default POSIX Access Control List (ACL)
attached to directory C<dir>.

=item $acl = $g->acl_get_file ($path, $acltype);

This function returns the POSIX Access Control List (ACL) attached
to C<path>.  The ACL is returned in "long text form" (see L<acl(5)>).

The C<acltype> parameter may be:

=over 4

=item C<access>

Return the ordinary (access) ACL for any file, directory or
other filesystem object.

=item C<default>

Return the default ACL.  Normally this only makes sense if
C<path> is a directory.

=back

=item $g->acl_set_file ($path, $acltype, $acl);

This function sets the POSIX Access Control List (ACL) attached
to C<path>.

The C<acltype> parameter may be:

=over 4

=item C<access>

Set the ordinary (access) ACL for any file, directory or
other filesystem object.

=item C<default>

Set the default ACL.  Normally this only makes sense if
C<path> is a directory.

=back

The C<acl> parameter is the new ACL in either "long text form"
or "short text form" (see L<acl(5)>).  The new ACL completely
replaces any previous ACL on the file.  The ACL must contain the
full Unix permissions (eg. C<u::rwx,g::rx,o::rx>).

If you are specifying individual users or groups, then the
mask field is also required (eg. C<m::rwx>), followed by the
C<u:I<ID>:...> and/or C<g:I<ID>:...> field(s).  A full ACL
string might therefore look like this:

 u::rwx,g::rwx,o::rwx,m::rwx,u:500:rwx,g:500:rwx
 \ Unix permissions / \mask/ \      ACL        /

You should use numeric UIDs and GIDs.  To map usernames and
groupnames to the correct numeric ID in the context of the
guest, use the Augeas functions (see C<$g-E<gt>aug_init>).

=item $g->add_cdrom ($filename);

This function adds a virtual CD-ROM disk image to the guest.

The image is added as read-only drive, so this function is equivalent
of C<$g-E<gt>add_drive_ro>.

I<This function is deprecated.>
In new code, use the L</add_drive_ro> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $nrdisks = $g->add_domain ($dom [, libvirturi => $libvirturi] [, readonly => $readonly] [, iface => $iface] [, live => $live] [, allowuuid => $allowuuid] [, readonlydisk => $readonlydisk] [, cachemode => $cachemode] [, discard => $discard] [, copyonread => $copyonread]);

This function adds the disk(s) attached to the named libvirt
domain C<dom>.  It works by connecting to libvirt, requesting
the domain and domain XML from libvirt, parsing it for disks,
and calling C<$g-E<gt>add_drive_opts> on each one.

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
C<$g-E<gt>add_drive_opts>.

=item $g->add_drive ($filename [, readonly => $readonly] [, format => $format] [, iface => $iface] [, name => $name] [, label => $label] [, protocol => $protocol] [, server => $server] [, username => $username] [, secret => $secret] [, cachemode => $cachemode] [, discard => $discard] [, copyonread => $copyonread]);

This function adds a disk image called F<filename> to the handle.
F<filename> may be a regular host file or a host device.

When this function is called before C<$g-E<gt>launch> (the
usual case) then the first time you call this function,
the disk appears in the API as F</dev/sda>, the second time
as F</dev/sdb>, and so on.

In libguestfs E<ge> 1.20 you can also call this function
after launch (with some restrictions).  This is called
"hotplugging".  When hotplugging, you must specify a
C<label> so that the new disk gets a predictable name.
For more information see L<guestfs(3)/HOTPLUGGING>.

You don't necessarily need to be root when using libguestfs.  However
you obviously do need sufficient permissions to access the filename
for whatever operations you want to perform (ie. read access if you
just want to read the image or write access if you want to modify the
image).

This call checks that F<filename> exists.

F<filename> may be the special string C<"/dev/null">.
See L<guestfs(3)/NULL DISKS>.

The optional arguments are:

=over 4

=item C<readonly>

If true then the image is treated as read-only.  Writes are still
allowed, but they are stored in a temporary snapshot overlay which
is discarded at the end.  The disk that you add is not modified.

=item C<format>

This forces the image format.  If you omit this (or use C<$g-E<gt>add_drive>
or C<$g-E<gt>add_drive_ro>) then the format is automatically detected.
Possible formats include C<raw> and C<qcow2>.

Automatic detection of the format opens you up to a potential
security hole when dealing with untrusted raw-format images.
See CVE-2010-3851 and RHBZ#642934.  Specifying the format closes
this security hole.

=item C<iface>

This rarely-used option lets you emulate the behaviour of the
deprecated C<$g-E<gt>add_drive_with_if> call (q.v.)

=item C<name>

The name the drive had in the original guest, e.g. F</dev/sdb>.
This is used as a hint to the guest inspection process if
it is available.

=item C<label>

Give the disk a label.  The label should be a unique, short
string using I<only> ASCII characters C<[a-zA-Z]>.
As well as its usual name in the API (such as F</dev/sda>),
the drive will also be named F</dev/disk/guestfs/I<label>>.

See L<guestfs(3)/DISK LABELS>.

=item C<protocol>

The optional protocol argument can be used to select an alternate
source protocol.

See also: L<guestfs(3)/REMOTE STORAGE>.

=over 4

=item C<protocol = "file">

F<filename> is interpreted as a local file or device.
This is the default if the optional protocol parameter
is omitted.

=item C<protocol = "ftp"|"ftps"|"http"|"https"|"tftp">

Connect to a remote FTP, HTTP or TFTP server.
The C<server> parameter must also be supplied - see below.

See also: L<guestfs(3)/FTP, HTTP AND TFTP>

=item C<protocol = "gluster">

Connect to the GlusterFS server.
The C<server> parameter must also be supplied - see below.

See also: L<guestfs(3)/GLUSTER>

=item C<protocol = "iscsi">

Connect to the iSCSI server.
The C<server> parameter must also be supplied - see below.

See also: L<guestfs(3)/ISCSI>.

=item C<protocol = "nbd">

Connect to the Network Block Device server.
The C<server> parameter must also be supplied - see below.

See also: L<guestfs(3)/NETWORK BLOCK DEVICE>.

=item C<protocol = "rbd">

Connect to the Ceph (librbd/RBD) server.
The C<server> parameter must also be supplied - see below.
The C<username> parameter may be supplied.  See below.
The C<secret> parameter may be supplied.  See below.

See also: L<guestfs(3)/CEPH>.

=item C<protocol = "sheepdog">

Connect to the Sheepdog server.
The C<server> parameter may also be supplied - see below.

See also: L<guestfs(3)/SHEEPDOG>.

=item C<protocol = "ssh">

Connect to the Secure Shell (ssh) server.

The C<server> parameter must be supplied.
The C<username> parameter may be supplied.  See below.

See also: L<guestfs(3)/SSH>.

=back

=item C<server>

For protocols which require access to a remote server, this
is a list of server(s).

 Protocol       Number of servers required
 --------       --------------------------
 file           List must be empty or param not used at all
 ftp|ftps|http|https|tftp  Exactly one
 gluster        Exactly one
 iscsi          Exactly one
 nbd            Exactly one
 rbd            Zero or more
 sheepdog       Zero or more
 ssh            Exactly one

Each list element is a string specifying a server.  The string must be
in one of the following formats:

 hostname
 hostname:port
 tcp:hostname
 tcp:hostname:port
 unix:/path/to/socket

If the port number is omitted, then the standard port number
for the protocol is used (see F</etc/services>).

=item C<username>

For the C<ftp>, C<ftps>, C<http>, C<https>, C<iscsi>, C<rbd>, C<ssh>
and C<tftp> protocols, this specifies the remote username.

If not given, then the local username is used for C<ssh>, and no authentication
is attempted for ceph.  But note this sometimes may give unexpected results, for
example if using the libvirt backend and if the libvirt backend is configured to
start the qemu appliance as a special user such as C<qemu.qemu>.  If in doubt,
specify the remote username you want.

=item C<secret>

For the C<rbd> protocol only, this specifies the 'secret' to use when
connecting to the remote device.  It must be base64 encoded.

If not given, then a secret matching the given username will be looked up in the
default keychain locations, or if no username is given, then no authentication
will be used.

=item C<cachemode>

Choose whether or not libguestfs will obey sync operations (safe but slow)
or not (unsafe but fast).  The possible values for this string are:

=over 4

=item C<cachemode = "writeback">

This is the default.

Write operations in the API do not return until a L<write(2)>
call has completed in the host [but note this does not imply
that anything gets written to disk].

Sync operations in the API, including implicit syncs caused by
filesystem journalling, will not return until an L<fdatasync(2)>
call has completed in the host, indicating that data has been
committed to disk.

=item C<cachemode = "unsafe">

In this mode, there are no guarantees.  Libguestfs may cache
anything and ignore sync requests.  This is suitable only
for scratch or temporary disks.

=back

=item C<discard>

Enable or disable discard (a.k.a. trim or unmap) support on this
drive.  If enabled, operations such as C<$g-E<gt>fstrim> will be able
to discard / make thin / punch holes in the underlying host file
or device.

Possible discard settings are:

=over 4

=item C<discard = "disable">

Disable discard support.  This is the default.

=item C<discard = "enable">

Enable discard support.  Fail if discard is not possible.

=item C<discard = "besteffort">

Enable discard support if possible, but don't fail if it is not
supported.

Since not all backends and not all underlying systems support
discard, this is a good choice if you want to use discard if
possible, but don't mind if it doesn't work.

=back

=item C<copyonread>

The boolean parameter C<copyonread> enables copy-on-read support.
This only affects disk formats which have backing files, and causes
reads to be stored in the overlay layer, speeding up multiple reads
of the same area of disk.

The default is false.

=back

=item $g->add_drive_opts ($filename [, readonly => $readonly] [, format => $format] [, iface => $iface] [, name => $name] [, label => $label] [, protocol => $protocol] [, server => $server] [, username => $username] [, secret => $secret] [, cachemode => $cachemode] [, discard => $discard] [, copyonread => $copyonread]);

This is an alias of L</add_drive>.

=cut

sub add_drive_opts {
  &add_drive (@_)
}

=pod

=item $g->add_drive_ro ($filename);

This function is the equivalent of calling C<$g-E<gt>add_drive_opts>
with the optional parameter C<GUESTFS_ADD_DRIVE_OPTS_READONLY> set to 1,
so the disk is added read-only, with the format being detected
automatically.

=item $g->add_drive_ro_with_if ($filename, $iface);

This is the same as C<$g-E<gt>add_drive_ro> but it allows you
to specify the QEMU interface emulation to use at run time.

I<This function is deprecated.>
In new code, use the L</add_drive> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->add_drive_scratch ($size [, name => $name] [, label => $label]);

This command adds a temporary scratch drive to the handle.  The
C<size> parameter is the virtual size (in bytes).  The scratch
drive is blank initially (all reads return zeroes until you start
writing to it).  The drive is deleted when the handle is closed.

The optional arguments C<name> and C<label> are passed through to
C<$g-E<gt>add_drive>.

=item $g->add_drive_with_if ($filename, $iface);

This is the same as C<$g-E<gt>add_drive> but it allows you
to specify the QEMU interface emulation to use at run time.

I<This function is deprecated.>
In new code, use the L</add_drive> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $nrdisks = $g->add_libvirt_dom ($dom [, readonly => $readonly] [, iface => $iface] [, live => $live] [, readonlydisk => $readonlydisk] [, cachemode => $cachemode] [, discard => $discard] [, copyonread => $copyonread]);

This function adds the disk(s) attached to the libvirt domain C<dom>.
It works by requesting the domain XML from libvirt, parsing it for
disks, and calling C<$g-E<gt>add_drive_opts> on each one.

In the C API we declare C<void *dom>, but really it has type
C<virDomainPtr dom>.  This is so we don't need E<lt>libvirt.hE<gt>.

The number of disks added is returned.  This operation is atomic:
if an error is returned, then no disks are added.

This function does some minimal checks to make sure the libvirt
domain is not running (unless C<readonly> is true).  In a future
version we will try to acquire the libvirt lock on each disk.

Disks must be accessible locally.  This often means that adding disks
from a remote libvirt connection (see L<http://libvirt.org/remote.html>)
will fail unless those disks are accessible via the same device path
locally too.

The optional C<live> flag controls whether this call will try
to connect to a running virtual machine C<guestfsd> process if
it sees a suitable E<lt>channelE<gt> element in the libvirt
XML definition.  The default (if the flag is omitted) is never
to try.  See L<guestfs(3)/ATTACHING TO RUNNING DAEMONS> for more
information.

The optional C<readonlydisk> parameter controls what we do for
disks which are marked E<lt>readonly/E<gt> in the libvirt XML.
See C<$g-E<gt>add_domain> for possible values.

The other optional parameters are passed directly through to
C<$g-E<gt>add_drive_opts>.

=item $g->aug_clear ($augpath);

Set the value associated with C<path> to C<NULL>.  This
is the same as the L<augtool(1)> C<clear> command.

=item $g->aug_close ();

Close the current Augeas handle and free up any resources
used by it.  After calling this, you have to call
C<$g-E<gt>aug_init> again before you can use any other
Augeas functions.

=item %nrnodescreated = $g->aug_defnode ($name, $expr, $val);

Defines a variable C<name> whose value is the result of
evaluating C<expr>.

If C<expr> evaluates to an empty nodeset, a node is created,
equivalent to calling C<$g-E<gt>aug_set> C<expr>, C<value>.
C<name> will be the nodeset containing that single node.

On success this returns a pair containing the
number of nodes in the nodeset, and a boolean flag
if a node was created.

=item $nrnodes = $g->aug_defvar ($name, $expr);

Defines an Augeas variable C<name> whose value is the result
of evaluating C<expr>.  If C<expr> is NULL, then C<name> is
undefined.

On success this returns the number of nodes in C<expr>, or
C<0> if C<expr> evaluates to something which is not a nodeset.

=item $val = $g->aug_get ($augpath);

Look up the value associated with C<path>.  If C<path>
matches exactly one node, the C<value> is returned.

=item $g->aug_init ($root, $flags);

Create a new Augeas handle for editing configuration files.
If there was any previous Augeas handle associated with this
guestfs session, then it is closed.

You must call this before using any other C<$g-E<gt>aug_*>
commands.

C<root> is the filesystem root.  C<root> must not be NULL,
use F</> instead.

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
environment variable or call C<$g-E<gt>set_memsize>.

=item C<AUG_NO_STDINC> = 8

Do not use standard load path for modules.

=item C<AUG_SAVE_NOOP> = 16

Make save a no-op, just record what would have been changed.

=item C<AUG_NO_LOAD> = 32

Do not load the tree in C<$g-E<gt>aug_init>.

=back

To close the handle, you can call C<$g-E<gt>aug_close>.

To find out more about Augeas, see L<http://augeas.net/>.

=item $g->aug_insert ($augpath, $label, $before);

Create a new sibling C<label> for C<path>, inserting it into
the tree before or after C<path> (depending on the boolean
flag C<before>).

C<path> must match exactly one existing node in the tree, and
C<label> must be a label, ie. not contain F</>, C<*> or end
with a bracketed index C<[N]>.

=item $label = $g->aug_label ($augpath);

The label (name of the last element) of the Augeas path expression
C<augpath> is returned.  C<augpath> must match exactly one node, else
this function returns an error.

=item $g->aug_load ();

Load files into the tree.

See C<aug_load> in the Augeas documentation for the full gory
details.

=item @matches = $g->aug_ls ($augpath);

This is just a shortcut for listing C<$g-E<gt>aug_match>
C<path/*> and sorting the resulting nodes into alphabetical order.

=item @matches = $g->aug_match ($augpath);

Returns a list of paths which match the path expression C<path>.
The returned paths are sufficiently qualified so that they match
exactly one node in the current tree.

=item $g->aug_mv ($src, $dest);

Move the node C<src> to C<dest>.  C<src> must match exactly
one node.  C<dest> is overwritten if it exists.

=item $nrnodes = $g->aug_rm ($augpath);

Remove C<path> and all of its children.

On success this returns the number of entries which were removed.

=item $g->aug_save ();

This writes all pending changes to disk.

The flags which were passed to C<$g-E<gt>aug_init> affect exactly
how files are saved.

=item $g->aug_set ($augpath, $val);

Set the value associated with C<path> to C<val>.

In the Augeas API, it is possible to clear a node by setting
the value to NULL.  Due to an oversight in the libguestfs API
you cannot do that with this call.  Instead you must use the
C<$g-E<gt>aug_clear> call.

=item $nodes = $g->aug_setm ($base, $sub, $val);

Change multiple Augeas nodes in a single operation.  C<base> is
an expression matching multiple nodes.  C<sub> is a path expression
relative to C<base>.  All nodes matching C<base> are found, and then
for each node, C<sub> is changed to C<val>.  C<sub> may also be C<NULL>
in which case the C<base> nodes are modified.

This returns the number of nodes modified.

=item $g->available (\@groups);

This command is used to check the availability of some
groups of functionality in the appliance, which not all builds of
the libguestfs appliance will be able to provide.

The libguestfs groups, and the functions that those
groups correspond to, are listed in L<guestfs(3)/AVAILABILITY>.
You can also fetch this list at runtime by calling
C<$g-E<gt>available_all_groups>.

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

C<$g-E<gt>feature_available> is the same as this call, but
with a slightly simpler to use API: that call returns a boolean
true/false instead of throwing an error.

=item *

You must call C<$g-E<gt>launch> before calling this function.

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
See also C<$g-E<gt>version>.

=back

See also C<$g-E<gt>filesystem_available>.

=item @groups = $g->available_all_groups ();

This command returns a list of all optional groups that this
daemon knows about.  Note this returns both supported and unsupported
groups.  To find out which ones the daemon can actually support
you have to call C<$g-E<gt>available> / C<$g-E<gt>feature_available>
on each member of the returned list.

See also C<$g-E<gt>available>, C<$g-E<gt>feature_available>
and L<guestfs(3)/AVAILABILITY>.

=item $g->base64_in ($base64file, $filename);

This command uploads base64-encoded data from C<base64file>
to F<filename>.

=item $g->base64_out ($filename, $base64file);

This command downloads the contents of F<filename>, writing
it out to local file C<base64file> encoded as base64.

=item $g->blkdiscard ($device);

This discards all blocks on the block device C<device>, giving
the free space back to the host.

This operation requires support in libguestfs, the host filesystem,
qemu and the host kernel.  If this support isn't present it may give
an error or even appear to run but do nothing.  You must also
set the C<discard> attribute on the underlying drive (see
C<$g-E<gt>add_drive_opts>).

=item $zeroes = $g->blkdiscardzeroes ($device);

This call returns true if blocks on C<device> that have been
discarded by a call to C<$g-E<gt>blkdiscard> are returned as
blocks of zero bytes when read the next time.

If it returns false, then it may be that discarded blocks are
read as stale or random data.

=item %info = $g->blkid ($device);

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

=item $g->blockdev_flushbufs ($device);

This tells the kernel to flush internal buffers associated
with C<device>.

This uses the L<blockdev(8)> command.

=item $blocksize = $g->blockdev_getbsz ($device);

This returns the block size of a device.

Note: this is different from both I<size in blocks> and
I<filesystem block size>.  Also this setting is not really
used by anything.  You should probably not use it for
anything.  Filesystems have their own idea about what
block size to choose.

This uses the L<blockdev(8)> command.

=item $ro = $g->blockdev_getro ($device);

Returns a boolean indicating if the block device is read-only
(true if read-only, false if not).

This uses the L<blockdev(8)> command.

=item $sizeinbytes = $g->blockdev_getsize64 ($device);

This returns the size of the device in bytes.

See also C<$g-E<gt>blockdev_getsz>.

This uses the L<blockdev(8)> command.

=item $sectorsize = $g->blockdev_getss ($device);

This returns the size of sectors on a block device.
Usually 512, but can be larger for modern devices.

(Note, this is not the size in sectors, use C<$g-E<gt>blockdev_getsz>
for that).

This uses the L<blockdev(8)> command.

=item $sizeinsectors = $g->blockdev_getsz ($device);

This returns the size of the device in units of 512-byte sectors
(even if the sectorsize isn't 512 bytes ... weird).

See also C<$g-E<gt>blockdev_getss> for the real sector size of
the device, and C<$g-E<gt>blockdev_getsize64> for the more
useful I<size in bytes>.

This uses the L<blockdev(8)> command.

=item $g->blockdev_rereadpt ($device);

Reread the partition table on C<device>.

This uses the L<blockdev(8)> command.

=item $g->blockdev_setbsz ($device, $blocksize);

This call does nothing and has never done anything
because of a bug in blockdev.  B<Do not use it.>

If you need to set the filesystem block size, use the
C<blocksize> option of C<$g-E<gt>mkfs>.

I<This function is deprecated.>
In new code, use the L</mkfs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->blockdev_setra ($device, $sectors);

Set readahead (in 512-byte sectors) for the device.

This uses the L<blockdev(8)> command.

=item $g->blockdev_setro ($device);

Sets the block device named C<device> to read-only.

This uses the L<blockdev(8)> command.

=item $g->blockdev_setrw ($device);

Sets the block device named C<device> to read-write.

This uses the L<blockdev(8)> command.

=item $g->btrfs_balance_cancel ($path);

Cancel a running balance on a btrfs filesystem.

=item $g->btrfs_balance_pause ($path);

Pause a running balance on a btrfs filesystem.

=item $g->btrfs_balance_resume ($path);

Resume a paused balance on a btrfs filesystem.

=item %status = $g->btrfs_balance_status ($path);

Show the status of a running or paused balance on a btrfs filesystem.

=item $g->btrfs_device_add (\@devices, $fs);

Add the list of device(s) in C<devices> to the btrfs filesystem
mounted at C<fs>.  If C<devices> is an empty list, this does nothing.

=item $g->btrfs_device_delete (\@devices, $fs);

Remove the C<devices> from the btrfs filesystem mounted at C<fs>.
If C<devices> is an empty list, this does nothing.

=item $g->btrfs_filesystem_balance ($fs);

Balance the chunks in the btrfs filesystem mounted at C<fs>
across the underlying devices.

=item $g->btrfs_filesystem_defragment ($path [, flush => $flush] [, compress => $compress]);

Defragment a file or directory on a btrfs filesystem. compress is one of zlib or lzo.

=item $g->btrfs_filesystem_resize ($mountpoint [, size => $size]);

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

=item $g->btrfs_filesystem_sync ($fs);

Force sync on the btrfs filesystem mounted at C<fs>.

=item $g->btrfs_fsck ($device [, superblock => $superblock] [, repair => $repair]);

Used to check a btrfs filesystem, C<device> is the device file where the
filesystem is stored.

=item $g->btrfs_image (\@source, $image [, compresslevel => $compresslevel]);

This is used to create an image of a btrfs filesystem.
All data will be zeroed, but metadata and the like is preserved.

=item $g->btrfs_qgroup_assign ($src, $dst, $path);

Add qgroup C<src> to parent qgroup C<dst>. This command can group
several qgroups into a parent qgroup to share common limit.

=item $g->btrfs_qgroup_create ($qgroupid, $subvolume);

Create a quota group (qgroup) for subvolume at C<subvolume>.

=item $g->btrfs_qgroup_destroy ($qgroupid, $subvolume);

Destroy a quota group.

=item $g->btrfs_qgroup_limit ($subvolume, $size);

Limit the size of a subvolume which's path is C<subvolume>. C<size>
can have suffix of G, M, or K. 

=item $g->btrfs_qgroup_remove ($src, $dst, $path);

Remove qgroup C<src> from the parent qgroup C<dst>.

=item @qgroups = $g->btrfs_qgroup_show ($path);

Show all subvolume quota groups in a btrfs filesystem, including their
usages.

=item $g->btrfs_quota_enable ($fs, $enable);

Enable or disable subvolume quota support for filesystem which contains C<path>.

=item $g->btrfs_quota_rescan ($fs);

Trash all qgroup numbers and scan the metadata again with the current config.

=item $g->btrfs_replace ($srcdev, $targetdev, $mntpoint);

Replace device of a btrfs filesystem. On a live filesystem, duplicate the data
to the target device which is currently stored on the source device.
After completion of the operation, the source device is wiped out and
removed from the filesystem.

The C<targetdev> needs to be same size or larger than the C<srcdev>. Devices
which are currently mounted are never allowed to be used as the C<targetdev>.

=item $g->btrfs_rescue_chunk_recover ($device);

Recover the chunk tree of btrfs filesystem by scanning the devices one by one.

=item $g->btrfs_rescue_super_recover ($device);

Recover bad superblocks from good copies.

=item $g->btrfs_scrub_cancel ($path);

Cancel a running scrub on a btrfs filesystem.

=item $g->btrfs_scrub_resume ($path);

Resume a previously canceled or interrupted scrub on a btrfs filesystem.

=item $g->btrfs_scrub_start ($path);

Reads all the data and metadata on the filesystem, and uses checksums
and the duplicate copies from RAID storage to identify and repair any
corrupt data.

=item %status = $g->btrfs_scrub_status ($path);

Show status of running or finished scrub on a btrfs filesystem.

=item $g->btrfs_set_seeding ($device, $seeding);

Enable or disable the seeding feature of a device that contains
a btrfs filesystem.

=item $g->btrfs_subvolume_create ($dest [, qgroupid => $qgroupid]);

Create a btrfs subvolume.  The C<dest> argument is the destination
directory and the name of the subvolume, in the form F</path/to/dest/name>.
The optional parameter C<qgroupid> represents the qgroup which the newly
created subvolume will be added to.

=item $g->btrfs_subvolume_create_opts ($dest [, qgroupid => $qgroupid]);

This is an alias of L</btrfs_subvolume_create>.

=cut

sub btrfs_subvolume_create_opts {
  &btrfs_subvolume_create (@_)
}

=pod

=item $g->btrfs_subvolume_delete ($subvolume);

Delete the named btrfs subvolume or snapshot.

=item $id = $g->btrfs_subvolume_get_default ($fs);

Get the default subvolume or snapshot of a filesystem mounted at C<mountpoint>.

=item @subvolumes = $g->btrfs_subvolume_list ($fs);

List the btrfs snapshots and subvolumes of the btrfs filesystem
which is mounted at C<fs>.

=item $g->btrfs_subvolume_set_default ($id, $fs);

Set the subvolume of the btrfs filesystem C<fs> which will
be mounted by default.  See C<$g-E<gt>btrfs_subvolume_list> to
get a list of subvolumes.

=item %btrfssubvolumeinfo = $g->btrfs_subvolume_show ($subvolume);

Return detailed information of the subvolume.

=item $g->btrfs_subvolume_snapshot ($source, $dest [, ro => $ro] [, qgroupid => $qgroupid]);

Create a snapshot of the btrfs subvolume C<source>.
The C<dest> argument is the destination directory and the name
of the snapshot, in the form F</path/to/dest/name>. By default
the newly created snapshot is writable, if the value of optional
parameter C<ro> is true, then a readonly snapshot is created. The
optional parameter C<qgroupid> represents the qgroup which the
newly created snapshot will be added to.

=item $g->btrfs_subvolume_snapshot_opts ($source, $dest [, ro => $ro] [, qgroupid => $qgroupid]);

This is an alias of L</btrfs_subvolume_snapshot>.

=cut

sub btrfs_subvolume_snapshot_opts {
  &btrfs_subvolume_snapshot (@_)
}

=pod

=item $g->btrfstune_enable_extended_inode_refs ($device);

This will Enable extended inode refs.

=item $g->btrfstune_enable_skinny_metadata_extent_refs ($device);

This enable skinny metadata extent refs.

=item $g->btrfstune_seeding ($device, $seeding);

Enable seeding of a btrfs device, this will force a fs readonly
so that you can use it to build other filesystems.

=item $ptr = $g->c_pointer ();

In non-C language bindings, this allows you to retrieve the underlying
C pointer to the handle (ie. C<$g-E<gt>h *>).  The purpose of this is
to allow other libraries to interwork with libguestfs.

=item $canonical = $g->canonical_device_name ($device);

This utility function is useful when displaying device names to
the user.  It takes a number of irregular device names and
returns them in a consistent format:

=over 4

=item F</dev/hdX>

=item F</dev/vdX>

These are returned as F</dev/sdX>.  Note this works for device
names and partition names.  This is approximately the reverse of
the algorithm described in L<guestfs(3)/BLOCK DEVICE NAMING>.

=item F</dev/mapper/VG-LV>

=item F</dev/dm-N>

Converted to F</dev/VG/LV> form using C<$g-E<gt>lvm_canonical_lv_name>.

=back

Other strings are returned unmodified.

=item $cap = $g->cap_get_file ($path);

This function returns the Linux capabilities attached to C<path>.
The capabilities set is returned in text form (see L<cap_to_text(3)>).

If no capabilities are attached to a file, an empty string is returned.

=item $g->cap_set_file ($path, $cap);

This function sets the Linux capabilities attached to C<path>.
The capabilities set C<cap> should be passed in text form
(see L<cap_from_text(3)>).

=item $rpath = $g->case_sensitive_path ($path);

This can be used to resolve case insensitive paths on
a filesystem which is case sensitive.  The use case is
to resolve paths which you have read from Windows configuration
files or the Windows Registry, to the true path.

The command handles a peculiarity of the Linux ntfs-3g
filesystem driver (and probably others), which is that although
the underlying filesystem is case-insensitive, the driver
exports the filesystem to Linux as case-sensitive.

One consequence of this is that special directories such
as F<C:\windows> may appear as F</WINDOWS> or F</windows>
(or other things) depending on the precise details of how
they were created.  In Windows itself this would not be
a problem.

Bug or feature?  You decide:
L<http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1>

C<$g-E<gt>case_sensitive_path> attempts to resolve the true case of
each element in the path. It will return a resolved path if either the
full path or its parent directory exists. If the parent directory
exists but the full path does not, the case of the parent directory
will be correctly resolved, and the remainder appended unmodified. For
example, if the file C<"/Windows/System32/netkvm.sys"> exists:

=over 4

=item C<$g-E<gt>case_sensitive_path> ("/windows/system32/netkvm.sys")

"Windows/System32/netkvm.sys"

=item C<$g-E<gt>case_sensitive_path> ("/windows/system32/NoSuchFile")

"Windows/System32/NoSuchFile"

=item C<$g-E<gt>case_sensitive_path> ("/windows/system33/netkvm.sys")

I<ERROR>

=back

I<Note>:
Because of the above behaviour, C<$g-E<gt>case_sensitive_path> cannot
be used to check for the existence of a file.

I<Note>:
This function does not handle drive names, backslashes etc.

See also C<$g-E<gt>realpath>.

=item $content = $g->cat ($path);

Return the contents of the file named C<path>.

Because, in C, this function returns a C<char *>, there is no
way to differentiate between a C<\0> character in a file and
end of string.  To handle binary files, use the C<$g-E<gt>read_file>
or C<$g-E<gt>download> functions.

=item $checksum = $g->checksum ($csumtype, $path);

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

To get the checksum for a device, use C<$g-E<gt>checksum_device>.

To get the checksums for many files, use C<$g-E<gt>checksums_out>.

=item $checksum = $g->checksum_device ($csumtype, $device);

This call computes the MD5, SHAx or CRC checksum of the
contents of the device named C<device>.  For the types of
checksums supported see the C<$g-E<gt>checksum> command.

=item $g->checksums_out ($csumtype, $directory, $sumsfile);

This command computes the checksums of all regular files in
F<directory> and then emits a list of those checksums to
the local output file C<sumsfile>.

This can be used for verifying the integrity of a virtual
machine.  However to be properly secure you should pay
attention to the output of the checksum command (it uses
the ones from GNU coreutils).  In particular when the
filename is not printable, coreutils uses a special
backslash syntax.  For more information, see the GNU
coreutils info file.

=item $g->chmod ($mode, $path);

Change the mode (permissions) of C<path> to C<mode>.  Only
numeric modes are supported.

I<Note>: When using this command from guestfish, C<mode>
by default would be decimal, unless you prefix it with
C<0> to get octal, ie. use C<0700> not C<700>.

The mode actually set is affected by the umask.

=item $g->chown ($owner, $group, $path);

Change the file owner to C<owner> and group to C<group>.

Only numeric uid and gid are supported.  If you want to use
names, you will need to locate and parse the password file
yourself (Augeas support makes this relatively easy).

=item $count = $g->clear_backend_setting ($name);

If there is a backend setting string matching C<"name"> or
beginning with C<"name=">, then that string is removed
from the backend settings.

This call returns the number of strings which were removed
(which may be 0, 1 or greater than 1).

See L<guestfs(3)/BACKEND>, L<guestfs(3)/BACKEND SETTINGS>.

=item $output = $g->command (\@arguments);

This call runs a command from the guest filesystem.  The
filesystem must be mounted, and must contain a compatible
operating system (ie. something Linux, with the same
or compatible processor architecture).

The single parameter is an argv-style list of arguments.
The first element is the name of the program to run.
Subsequent elements are parameters.  The list must be
non-empty (ie. must contain a program name).  Note that
the command runs directly, and is I<not> invoked via
the shell (see C<$g-E<gt>sh>).

The return value is anything printed to I<stdout> by
the command.

If the command returns a non-zero exit status, then
this function returns an error message.  The error message
string is the content of I<stderr> from the command.

The C<$PATH> environment variable will contain at least
F</usr/bin> and F</bin>.  If you require a program from
another location, you should provide the full path in the
first parameter.

Shared libraries and data files required by the program
must be available on filesystems which are mounted in the
correct places.  It is the caller's responsibility to ensure
all filesystems that are needed are mounted at the right
locations.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $g->command_lines (\@arguments);

This is the same as C<$g-E<gt>command>, but splits the
result into a list of lines.

See also: C<$g-E<gt>sh_lines>

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $g->compress_device_out ($ctype, $device, $zdevice [, level => $level]);

This command compresses C<device> and writes it out to the local
file C<zdevice>.

The C<ctype> and optional C<level> parameters have the same meaning
as in C<$g-E<gt>compress_out>.

=item $g->compress_out ($ctype, $file, $zfile [, level => $level]);

This command compresses F<file> and writes it out to the local
file F<zfile>.

The compression program used is controlled by the C<ctype> parameter.
Currently this includes: C<compress>, C<gzip>, C<bzip2>, C<xz> or C<lzop>.
Some compression types may not be supported by particular builds of
libguestfs, in which case you will get an error containing the
substring "not supported".

The optional C<level> parameter controls compression level.  The
meaning and default for this parameter depends on the compression
program being used.

=item $g->config ($hvparam, $hvvalue);

This can be used to add arbitrary hypervisor parameters of the
form I<-param value>.  Actually it's not quite arbitrary - we
prevent you from setting some parameters which would interfere with
parameters that we use.

The first character of C<hvparam> string must be a C<-> (dash).

C<hvvalue> can be NULL.

=item $g->copy_attributes ($src, $dest [, all => $all] [, mode => $mode] [, xattributes => $xattributes] [, ownership => $ownership]);

Copy the attributes of a path (which can be a file or a directory)
to another path.

By default C<no> attribute is copied, so make sure to specify any
(or C<all> to copy everything).

The optional arguments specify which attributes can be copied:

=over 4

=item C<mode>

Copy part of the file mode from C<source> to C<destination>. Only the
UNIX permissions and the sticky/setuid/setgid bits can be copied.

=item C<xattributes>

Copy the Linux extended attributes (xattrs) from C<source> to C<destination>.
This flag does nothing if the I<linuxxattrs> feature is not available
(see C<$g-E<gt>feature_available>).

=item C<ownership>

Copy the owner uid and the group gid of C<source> to C<destination>.

=item C<all>

Copy B<all> the attributes from C<source> to C<destination>. Enabling it
enables all the other flags, if they are not specified already.

=back

=item $g->copy_device_to_device ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size] [, sparse => $sparse] [, append => $append]);

The four calls C<$g-E<gt>copy_device_to_device>,
C<$g-E<gt>copy_device_to_file>,
C<$g-E<gt>copy_file_to_device>, and
C<$g-E<gt>copy_file_to_file>
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

If the destination is a file and the C<append> flag is not set,
then the destination file is truncated.  If the C<append> flag is
set, then the copy appends to the destination file.  The C<append>
flag currently cannot be set for devices.

If the C<sparse> flag is true then the call avoids writing
blocks that contain only zeroes, which can help in some situations
where the backing disk is thin-provisioned.  Note that unless
the target is already zeroed, using this option will result
in incorrect copying.

=item $g->copy_device_to_file ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size] [, sparse => $sparse] [, append => $append]);

See C<$g-E<gt>copy_device_to_device> for a general overview
of this call.

=item $g->copy_file_to_device ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size] [, sparse => $sparse] [, append => $append]);

See C<$g-E<gt>copy_device_to_device> for a general overview
of this call.

=item $g->copy_file_to_file ($src, $dest [, srcoffset => $srcoffset] [, destoffset => $destoffset] [, size => $size] [, sparse => $sparse] [, append => $append]);

See C<$g-E<gt>copy_device_to_device> for a general overview
of this call.

This is B<not> the function you want for copying files.  This
is for copying blocks within existing files.  See C<$g-E<gt>cp>,
C<$g-E<gt>cp_a> and C<$g-E<gt>mv> for general file copying and
moving functions.

=item $g->copy_in ($localpath, $remotedir);

C<$g-E<gt>copy_in> copies local files or directories recursively into
the disk image, placing them in the directory called C<remotedir>
(which must exist).

Wildcards cannot be used.

=item $g->copy_out ($remotepath, $localdir);

C<$g-E<gt>copy_out> copies remote files or directories recursively
out of the disk image, placing them on the host disk in a local
directory called C<localdir> (which must exist).

To download to the current directory, use C<.> as in:

 C<$g-E<gt>copy_out> /home .

Wildcards cannot be used.

=item $g->copy_size ($src, $dest, $size);

This command copies exactly C<size> bytes from one source device
or file C<src> to another destination device or file C<dest>.

Note this will fail if the source is too short or if the destination
is not large enough.

I<This function is deprecated.>
In new code, use the L</copy_device_to_device> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->cp ($src, $dest);

This copies a file from C<src> to C<dest> where C<dest> is
either a destination filename or destination directory.

=item $g->cp_a ($src, $dest);

This copies a file or directory from C<src> to C<dest>
recursively using the C<cp -a> command.

=item $g->cp_r ($src, $dest);

This copies a file or directory from C<src> to C<dest>
recursively using the C<cp -rP> command.

Most users should use C<$g-E<gt>cp_a> instead.  This command
is useful when you don't want to preserve permissions, because
the target filesystem does not support it (primarily when
writing to DOS FAT filesystems).

=item $g->cpio_out ($directory, $cpiofile [, format => $format]);

This command packs the contents of F<directory> and downloads
it to local file C<cpiofile>.

The optional C<format> parameter can be used to select the format.
Only the following formats are currently permitted:

=over 4

=item C<newc>

New (SVR4) portable format.  This format happens to be compatible
with the cpio-like format used by the Linux kernel for initramfs.

This is the default format.

=item C<crc>

New (SVR4) portable format with a checksum.

=back

=item $g->dd ($src, $dest);

This command copies from one source device or file C<src>
to another destination device or file C<dest>.  Normally you
would use this to copy to or from a device or partition, for
example to duplicate a filesystem.

If the destination is a device, it must be as large or larger
than the source file or device, otherwise the copy will fail.
This command cannot do partial copies
(see C<$g-E<gt>copy_device_to_device>).

I<This function is deprecated.>
In new code, use the L</copy_device_to_device> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $index = $g->device_index ($device);

This function takes a device name (eg. "/dev/sdb") and
returns the index of the device in the list of devices.

Index numbers start from 0.  The named device must exist,
for example as a string returned from C<$g-E<gt>list_devices>.

See also C<$g-E<gt>list_devices>, C<$g-E<gt>part_to_dev>.

=item $output = $g->df ();

This command runs the C<df> command to report disk space used.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.
Use C<$g-E<gt>statvfs> from programs.

=item $output = $g->df_h ();

This command runs the C<df -h> command to report disk space used
in human-readable format.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.
Use C<$g-E<gt>statvfs> from programs.

=item $g->disk_create ($filename, $format, $size [, backingfile => $backingfile] [, backingformat => $backingformat] [, preallocation => $preallocation] [, compat => $compat] [, clustersize => $clustersize]);

Create a blank disk image called F<filename> (a host file)
with format C<format> (usually C<raw> or C<qcow2>).
The size is C<size> bytes.

If used with the optional C<backingfile> parameter, then a snapshot
is created on top of the backing file.  In this case, C<size> must
be passed as C<-1>.  The size of the snapshot is the same as the
size of the backing file, which is discovered automatically.  You
are encouraged to also pass C<backingformat> to describe the format
of C<backingfile>.

If F<filename> refers to a block device, then the device is
formatted.  The C<size> is ignored since block devices have an
intrinsic size.

The other optional parameters are:

=over 4

=item C<preallocation>

If format is C<raw>, then this can be either C<sparse> or C<full>
to create a sparse or fully allocated file respectively.  The default
is C<sparse>.

If format is C<qcow2>, then this can be either C<off> or
C<metadata>.  Preallocating metadata can be faster when doing lots
of writes, but uses more space.  The default is C<off>.

=item C<compat>

C<qcow2> only:
Pass the string C<1.1> to use the advanced qcow2 format supported
by qemu E<ge> 1.1.

=item C<clustersize>

C<qcow2> only:
Change the qcow2 cluster size.  The default is 65536 (bytes) and
this setting may be any power of two between 512 and 2097152.

=back

Note that this call does not add the new disk to the handle.  You
may need to call C<$g-E<gt>add_drive_opts> separately.

=item $format = $g->disk_format ($filename);

Detect and return the format of the disk image called F<filename>.
F<filename> can also be a host device, etc.  If the format of the
image could not be detected, then C<"unknown"> is returned.

Note that detecting the disk format can be insecure under some
circumstances.  See L<guestfs(3)/CVE-2010-3851>.

See also: L<guestfs(3)/DISK IMAGE FORMATS>

=item $backingfile = $g->disk_has_backing_file ($filename);

Detect and return whether the disk image F<filename> has a
backing file.

Note that detecting disk features can be insecure under some
circumstances.  See L<guestfs(3)/CVE-2010-3851>.

=item $size = $g->disk_virtual_size ($filename);

Detect and return the virtual size in bytes of the disk image
called F<filename>.

Note that detecting disk features can be insecure under some
circumstances.  See L<guestfs(3)/CVE-2010-3851>.

=item $kmsgs = $g->dmesg ();

This returns the kernel messages (C<dmesg> output) from
the guest kernel.  This is sometimes useful for extended
debugging of problems.

Another way to get the same information is to enable
verbose messages with C<$g-E<gt>set_verbose> or by setting
the environment variable C<LIBGUESTFS_DEBUG=1> before
running the program.

=item $g->download ($remotefilename, $filename);

Download file F<remotefilename> and save it as F<filename>
on the local machine.

F<filename> can also be a named pipe.

See also C<$g-E<gt>upload>, C<$g-E<gt>cat>.

=item $g->download_offset ($remotefilename, $filename, $offset, $size);

Download file F<remotefilename> and save it as F<filename>
on the local machine.

F<remotefilename> is read for C<size> bytes starting at C<offset>
(this region must be within the file or device).

Note that there is no limit on the amount of data that
can be downloaded with this call, unlike with C<$g-E<gt>pread>,
and this call always reads the full amount unless an
error occurs.

See also C<$g-E<gt>download>, C<$g-E<gt>pread>.

=item $g->drop_caches ($whattodrop);

This instructs the guest kernel to drop its page cache,
and/or dentries and inode caches.  The parameter C<whattodrop>
tells the kernel what precisely to drop, see
L<http://linux-mm.org/Drop_Caches>

Setting C<whattodrop> to 3 should drop everything.

This automatically calls L<sync(2)> before the operation,
so that the maximum guest memory is freed.

=item $sizekb = $g->du ($path);

This command runs the C<du -s> command to estimate file space
usage for C<path>.

C<path> can be a file or a directory.  If C<path> is a directory
then the estimate includes the contents of the directory and all
subdirectories (recursively).

The result is the estimated size in I<kilobytes>
(ie. units of 1024 bytes).

=item $g->e2fsck ($device [, correct => $correct] [, forceall => $forceall]);

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

=item $g->e2fsck_f ($device);

This runs C<e2fsck -p -f device>, ie. runs the ext2/ext3
filesystem checker on C<device>, noninteractively (I<-p>),
even if the filesystem appears to be clean (I<-f>).

I<This function is deprecated.>
In new code, use the L</e2fsck> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $output = $g->echo_daemon (\@words);

This command concatenates the list of C<words> passed with single spaces
between them and returns the resulting string.

You can use this command to test the connection through to the daemon.

See also C<$g-E<gt>ping_daemon>.

=item @lines = $g->egrep ($regex, $path);

This calls the external C<egrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->egrepi ($regex, $path);

This calls the external C<egrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $equality = $g->equal ($file1, $file2);

This compares the two files F<file1> and F<file2> and returns
true if their content is exactly equal, or false otherwise.

The external L<cmp(1)> program is used for the comparison.

=item $existsflag = $g->exists ($path);

This returns C<true> if and only if there is a file, directory
(or anything) with the given C<path> name.

See also C<$g-E<gt>is_file>, C<$g-E<gt>is_dir>, C<$g-E<gt>stat>.

=item $g->extlinux ($directory);

Install the SYSLINUX bootloader on the device mounted at F<directory>.
Unlike C<$g-E<gt>syslinux> which requires a FAT filesystem, this can
be used on an ext2/3/4 or btrfs filesystem.

The F<directory> parameter can be either a mountpoint, or a
directory within the mountpoint.

You also have to mark the partition as "active"
(C<$g-E<gt>part_set_bootable>) and a Master Boot Record must
be installed (eg. using C<$g-E<gt>pwrite_device>) on the first
sector of the whole disk.
The SYSLINUX package comes with some suitable Master Boot Records.
See the L<extlinux(1)> man page for further information.

Additional configuration can be supplied to SYSLINUX by
placing a file called F<extlinux.conf> on the filesystem
under F<directory>.  For further information
about the contents of this file, see L<extlinux(1)>.

See also C<$g-E<gt>syslinux>.

=item $g->fallocate ($path, $len);

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

=item $g->fallocate64 ($path, $len);

This command preallocates a file (containing zero bytes) named
C<path> of size C<len> bytes.  If the file exists already, it
is overwritten.

Note that this call allocates disk blocks for the file.
To create a sparse file use C<$g-E<gt>truncate_size> instead.

The deprecated call C<$g-E<gt>fallocate> does the same,
but owing to an oversight it only allowed 30 bit lengths
to be specified, effectively limiting the maximum size
of files created through that call to 1GB.

Do not confuse this with the guestfish-specific
C<alloc> and C<sparse> commands which create
a file in the host and attach it as a device.

=item $isavailable = $g->feature_available (\@groups);

This is the same as C<$g-E<gt>available>, but unlike that
call it returns a simple true/false boolean result, instead
of throwing an exception if a feature is not found.  For
other documentation see C<$g-E<gt>available>.

=item @lines = $g->fgrep ($pattern, $path);

This calls the external C<fgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->fgrepi ($pattern, $path);

This calls the external C<fgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $description = $g->file ($path);

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

See also: L<file(1)>, C<$g-E<gt>vfs_type>, C<$g-E<gt>lstat>,
C<$g-E<gt>is_file>, C<$g-E<gt>is_blockdev> (etc), C<$g-E<gt>is_zero>.

=item $arch = $g->file_architecture ($filename);

This detects the architecture of the binary F<filename>,
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

=item "arm"

32 bit ARM.

=item "aarch64"

64 bit ARM.

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

=item $size = $g->filesize ($file);

This command returns the size of F<file> in bytes.

To get other stats about a file, use C<$g-E<gt>stat>, C<$g-E<gt>lstat>,
C<$g-E<gt>is_dir>, C<$g-E<gt>is_file> etc.
To get the size of block devices, use C<$g-E<gt>blockdev_getsize64>.

=item $fsavail = $g->filesystem_available ($filesystem);

Check whether libguestfs supports the named filesystem.
The argument C<filesystem> is a filesystem name, such as
C<ext3>.

You must call C<$g-E<gt>launch> before using this command.

This is mainly useful as a negative test.  If this returns true,
it doesn't mean that a particular filesystem can be created
or mounted, since filesystems can fail for other reasons
such as it being a later version of the filesystem,
or having incompatible features, or lacking the right
mkfs.E<lt>I<fs>E<gt> tool.

See also C<$g-E<gt>available>, C<$g-E<gt>feature_available>,
L<guestfs(3)/AVAILABILITY>.

=item $g->fill ($c, $len, $path);

This command creates a new file called C<path>.  The initial
content of the file is C<len> octets of C<c>, where C<c>
must be a number in the range C<[0..255]>.

To fill a file with zero bytes (sparsely), it is
much more efficient to use C<$g-E<gt>truncate_size>.
To create a file with a pattern of repeating bytes
use C<$g-E<gt>fill_pattern>.

=item $g->fill_dir ($dir, $nr);

This function, useful for testing filesystems, creates C<nr>
empty files in the directory C<dir> with names C<00000000>
through C<nr-1> (ie. each file name is 8 digits long padded
with zeroes).

=item $g->fill_pattern ($pattern, $len, $path);

This function is like C<$g-E<gt>fill> except that it creates
a new file of length C<len> containing the repeating pattern
of bytes in C<pattern>.  The pattern is truncated if necessary
to ensure the length of the file is exactly C<len> bytes.

=item @names = $g->find ($directory);

This command lists out all files and directories, recursively,
starting at F<directory>.  It is essentially equivalent to
running the shell command C<find directory -print> but some
post-processing happens on the output, described below.

This returns a list of strings I<without any prefix>.  Thus
if the directory structure was:

 /tmp/a
 /tmp/b
 /tmp/c/d

then the returned list from C<$g-E<gt>find> F</tmp> would be
4 elements:

 a
 b
 c
 c/d

If F<directory> is not a directory, then this command returns
an error.

The returned list is sorted.

=item $g->find0 ($directory, $files);

This command lists out all files and directories, recursively,
starting at F<directory>, placing the resulting list in the
external file called F<files>.

This command works the same way as C<$g-E<gt>find> with the
following exceptions:

=over 4

=item *

The resulting list is written to an external file.

=item *

Items (filenames) in the result are separated
by C<\0> characters.  See L<find(1)> option I<-print0>.

=item *

The result list is not sorted.

=back

=item $device = $g->findfs_label ($label);

This command searches the filesystems and returns the one
which has the given label.  An error is returned if no such
filesystem can be found.

To find the label of a filesystem, use C<$g-E<gt>vfs_label>.

=item $device = $g->findfs_uuid ($uuid);

This command searches the filesystems and returns the one
which has the given UUID.  An error is returned if no such
filesystem can be found.

To find the UUID of a filesystem, use C<$g-E<gt>vfs_uuid>.

=item $status = $g->fsck ($fstype, $device);

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

=item $g->fstrim ($mountpoint [, offset => $offset] [, length => $length] [, minimumfreeextent => $minimumfreeextent]);

Trim the free space in the filesystem mounted on C<mountpoint>.
The filesystem must be mounted read-write.

The filesystem contents are not affected, but any free space
in the filesystem is "trimmed", that is, given back to the host
device, thus making disk images more sparse, allowing unused space
in qcow2 files to be reused, etc.

This operation requires support in libguestfs, the mounted
filesystem, the host filesystem, qemu and the host kernel.
If this support isn't present it may give an error or even
appear to run but do nothing.

See also C<$g-E<gt>zero_free_space>.  That is a slightly
different operation that turns free space in the filesystem
into zeroes.  It is valid to call C<$g-E<gt>fstrim> either
instead of, or after calling C<$g-E<gt>zero_free_space>.

=item $append = $g->get_append ();

Return the additional kernel options which are added to the
libguestfs appliance kernel command line.

If C<NULL> then no options are added.

=item $backend = $g->get_attach_method ();

Return the current backend.

See C<$g-E<gt>set_backend> and L<guestfs(3)/BACKEND>.

I<This function is deprecated.>
In new code, use the L</get_backend> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $autosync = $g->get_autosync ();

Get the autosync flag.

=item $backend = $g->get_backend ();

Return the current backend.

This handle property was previously called the "attach method".

See C<$g-E<gt>set_backend> and L<guestfs(3)/BACKEND>.

=item $val = $g->get_backend_setting ($name);

Find a backend setting string which is either C<"name"> or
begins with C<"name=">.  If C<"name">, this returns the
string C<"1">.  If C<"name=">, this returns the part
after the equals sign (which may be an empty string).

If no such setting is found, this function throws an error.
The errno (see C<$g-E<gt>last_errno>) will be C<ESRCH> in this
case.

See L<guestfs(3)/BACKEND>, L<guestfs(3)/BACKEND SETTINGS>.

=item @settings = $g->get_backend_settings ();

Return the current backend settings.

This call returns all backend settings strings.  If you want to
find a single backend setting, see C<$g-E<gt>get_backend_setting>.

See L<guestfs(3)/BACKEND>, L<guestfs(3)/BACKEND SETTINGS>.

=item $cachedir = $g->get_cachedir ();

Get the directory used by the handle to store the appliance cache.

=item $direct = $g->get_direct ();

Return the direct appliance mode flag.

=item $attrs = $g->get_e2attrs ($file);

This returns the file attributes associated with F<file>.

The attributes are a set of bits associated with each
inode which affect the behaviour of the file.  The attributes
are returned as a string of letters (described below).  The
string may be empty, indicating that no file attributes are
set for this file.

These attributes are only present when the file is located on
an ext2/3/4 filesystem.  Using this call on other filesystem
types will result in an error.

The characters (file attributes) in the returned string are
currently:

=over 4

=item 'A'

When the file is accessed, its atime is not modified.

=item 'a'

The file is append-only.

=item 'c'

The file is compressed on-disk.

=item 'D'

(Directories only.)  Changes to this directory are written
synchronously to disk.

=item 'd'

The file is not a candidate for backup (see L<dump(8)>).

=item 'E'

The file has compression errors.

=item 'e'

The file is using extents.

=item 'h'

The file is storing its blocks in units of the filesystem blocksize
instead of sectors.

=item 'I'

(Directories only.)  The directory is using hashed trees.

=item 'i'

The file is immutable.  It cannot be modified, deleted or renamed.
No link can be created to this file.

=item 'j'

The file is data-journaled.

=item 's'

When the file is deleted, all its blocks will be zeroed.

=item 'S'

Changes to this file are written synchronously to disk.

=item 'T'

(Directories only.)  This is a hint to the block allocator
that subdirectories contained in this directory should be
spread across blocks.  If not present, the block allocator
will try to group subdirectories together.

=item 't'

For a file, this disables tail-merging.
(Not used by upstream implementations of ext2.)

=item 'u'

When the file is deleted, its blocks will be saved, allowing
the file to be undeleted.

=item 'X'

The raw contents of the compressed file may be accessed.

=item 'Z'

The compressed file is dirty.

=back

More file attributes may be added to this list later.  Not all
file attributes may be set for all kinds of files.  For
detailed information, consult the L<chattr(1)> man page.

See also C<$g-E<gt>set_e2attrs>.

Don't confuse these attributes with extended attributes
(see C<$g-E<gt>getxattr>).

=item $generation = $g->get_e2generation ($file);

This returns the ext2 file generation of a file.  The generation
(which used to be called the "version") is a number associated
with an inode.  This is most commonly used by NFS servers.

The generation is only present when the file is located on
an ext2/3/4 filesystem.  Using this call on other filesystem
types will result in an error.

See C<$g-E<gt>set_e2generation>.

=item $label = $g->get_e2label ($device);

This returns the ext2/3/4 filesystem label of the filesystem on
C<device>.

I<This function is deprecated.>
In new code, use the L</vfs_label> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $uuid = $g->get_e2uuid ($device);

This returns the ext2/3/4 filesystem UUID of the filesystem on
C<device>.

I<This function is deprecated.>
In new code, use the L</vfs_uuid> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $hv = $g->get_hv ();

Return the current hypervisor binary.

This is always non-NULL.  If it wasn't set already, then this will
return the default qemu binary name.

=item $challenge = $g->get_libvirt_requested_credential_challenge ($index);

Get the challenge (provided by libvirt) for the C<index>'th
requested credential.  If libvirt did not provide a challenge,
this returns the empty string C<"">.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item $defresult = $g->get_libvirt_requested_credential_defresult ($index);

Get the default result (provided by libvirt) for the C<index>'th
requested credential.  If libvirt did not provide a default result,
this returns the empty string C<"">.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item $prompt = $g->get_libvirt_requested_credential_prompt ($index);

Get the prompt (provided by libvirt) for the C<index>'th
requested credential.  If libvirt did not provide a prompt,
this returns the empty string C<"">.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item @creds = $g->get_libvirt_requested_credentials ();

This should only be called during the event callback
for events of type C<GUESTFS_EVENT_LIBVIRT_AUTH>.

Return the list of credentials requested by libvirt.  Possible
values are a subset of the strings provided when you called
C<$g-E<gt>set_libvirt_supported_credentials>.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item $memsize = $g->get_memsize ();

This gets the memory size in megabytes allocated to the
hypervisor.

If C<$g-E<gt>set_memsize> was not called
on this handle, and if C<LIBGUESTFS_MEMSIZE> was not set,
then this returns the compiled-in default value for memsize.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $network = $g->get_network ();

This returns the enable network flag.

=item $path = $g->get_path ();

Return the current search path.

This is always non-NULL.  If it wasn't set already, then this will
return the default path.

=item $pgroup = $g->get_pgroup ();

This returns the process group flag.

=item $pid = $g->get_pid ();

Return the process ID of the hypervisor.  If there is no
hypervisor running, then this will return an error.

This is an internal call used for debugging and testing.

=item $program = $g->get_program ();

Get the program name.  See C<$g-E<gt>set_program>.

=item $hv = $g->get_qemu ();

Return the current hypervisor binary (usually qemu).

This is always non-NULL.  If it wasn't set already, then this will
return the default qemu binary name.

I<This function is deprecated.>
In new code, use the L</get_hv> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $recoveryproc = $g->get_recovery_proc ();

Return the recovery process enabled flag.

=item $selinux = $g->get_selinux ();

This returns the current setting of the selinux flag which
is passed to the appliance at boot time.  See C<$g-E<gt>set_selinux>.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $smp = $g->get_smp ();

This returns the number of virtual CPUs assigned to the appliance.

=item $state = $g->get_state ();

This returns the current state as an opaque integer.  This is
only useful for printing debug and internal error messages.

For more information on states, see L<guestfs(3)>.

=item $tmpdir = $g->get_tmpdir ();

Get the directory used by the handle to store temporary files.

=item $trace = $g->get_trace ();

Return the command trace flag.

=item $mask = $g->get_umask ();

Return the current umask.  By default the umask is C<022>
unless it has been set by calling C<$g-E<gt>umask>.

=item $verbose = $g->get_verbose ();

This returns the verbose messages flag.

=item $context = $g->getcon ();

This gets the SELinux security context of the daemon.

See the documentation about SELINUX in L<guestfs(3)>,
and C<$g-E<gt>setcon>

=item $xattr = $g->getxattr ($path, $name);

Get a single extended attribute from file C<path> named C<name>.
This call follows symlinks.  If you want to lookup an extended
attribute for the symlink itself, use C<$g-E<gt>lgetxattr>.

Normally it is better to get all extended attributes from a file
in one go by calling C<$g-E<gt>getxattrs>.  However some Linux
filesystem implementations are buggy and do not provide a way to
list out attributes.  For these filesystems (notably ntfs-3g)
you have to know the names of the extended attributes you want
in advance and call this function.

Extended attribute values are blobs of binary data.  If there
is no extended attribute named C<name>, this returns an error.

See also: C<$g-E<gt>getxattrs>, C<$g-E<gt>lgetxattr>, L<attr(5)>.

=item @xattrs = $g->getxattrs ($path);

This call lists the extended attributes of the file or directory
C<path>.

At the system call level, this is a combination of the
L<listxattr(2)> and L<getxattr(2)> calls.

See also: C<$g-E<gt>lgetxattrs>, L<attr(5)>.

=item @paths = $g->glob_expand ($pattern);

This command searches for all the pathnames matching
C<pattern> according to the wildcard expansion rules
used by the shell.

If no paths match, then this returns an empty list
(note: not an error).

It is just a wrapper around the C L<glob(3)> function
with flags C<GLOB_MARK|GLOB_BRACE>.
See that manual page for more details.

Notice that there is no equivalent command for expanding a device
name (eg. F</dev/sd*>).  Use C<$g-E<gt>list_devices>,
C<$g-E<gt>list_partitions> etc functions instead.

=item @lines = $g->grep ($regex, $path [, extended => $extended] [, fixed => $fixed] [, insensitive => $insensitive] [, compressed => $compressed]);

This calls the external C<grep> program and returns the
matching lines.

The optional flags are:

=over 4

=item C<extended>

Use extended regular expressions.
This is the same as using the I<-E> flag.

=item C<fixed>

Match fixed (don't use regular expressions).
This is the same as using the I<-F> flag.

=item C<insensitive>

Match case-insensitive.  This is the same as using the I<-i> flag.

=item C<compressed>

Use C<zgrep> instead of C<grep>.  This allows the input to be
compress- or gzip-compressed.

=back

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $g->grep_opts ($regex, $path [, extended => $extended] [, fixed => $fixed] [, insensitive => $insensitive] [, compressed => $compressed]);

This is an alias of L</grep>.

=cut

sub grep_opts {
  &grep (@_)
}

=pod

=item @lines = $g->grepi ($regex, $path);

This calls the external C<grep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->grub_install ($root, $device);

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
it may be that you need to create a F</boot/grub/device.map>
file first that contains the mapping between grub device names
and Linux device names.  It is usually sufficient to create
a file containing:

 (hd0) /dev/vda

replacing F</dev/vda> with the name of the installation device.

=back

=item @lines = $g->head ($path);

This command returns up to the first 10 lines of a file as
a list of strings.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $g->head_n ($nrlines, $path);

If the parameter C<nrlines> is a positive number, this returns the first
C<nrlines> lines of the file C<path>.

If the parameter C<nrlines> is a negative number, this returns lines
from the file C<path>, excluding the last C<nrlines> lines.

If the parameter C<nrlines> is zero, this returns an empty list.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $dump = $g->hexdump ($path);

This runs C<hexdump -C> on the given C<path>.  The result is
the human-readable, canonical hex dump of the file.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $g->hivex_close ();

Close the current hivex handle.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $g->hivex_commit ($filename);

Commit (write) changes to the hive.

If the optional F<filename> parameter is null, then the changes
are written back to the same hive that was opened.  If this is
not null then they are written to the alternate filename given
and the original hive is left untouched.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $nodeh = $g->hivex_node_add_child ($parent, $name);

Add a child node to C<parent> named C<name>.

This is a wrapper around the L<hivex(3)> call of the same name.

=item @nodehs = $g->hivex_node_children ($nodeh);

Return the list of nodes which are subkeys of C<nodeh>.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $g->hivex_node_delete_child ($nodeh);

Delete C<nodeh>, recursively if necessary.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $child = $g->hivex_node_get_child ($nodeh, $name);

Return the child of C<nodeh> with the name C<name>, if it exists.
This can return C<0> meaning the name was not found.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $valueh = $g->hivex_node_get_value ($nodeh, $key);

Return the value attached to C<nodeh> which has the
name C<key>, if it exists.  This can return C<0> meaning
the key was not found.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $name = $g->hivex_node_name ($nodeh);

Return the name of C<nodeh>.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $parent = $g->hivex_node_parent ($nodeh);

Return the parent node of C<nodeh>.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $g->hivex_node_set_value ($nodeh, $key, $t, $val);

Set or replace a single value under the node C<nodeh>.  The
C<key> is the name, C<t> is the type, and C<val> is the data.

This is a wrapper around the L<hivex(3)> call of the same name.

=item @valuehs = $g->hivex_node_values ($nodeh);

Return the array of (key, datatype, data) tuples attached to C<nodeh>.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $g->hivex_open ($filename [, verbose => $verbose] [, debug => $debug] [, write => $write]);

Open the Windows Registry hive file named F<filename>.
If there was any previous hivex handle associated with this
guestfs session, then it is closed.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $nodeh = $g->hivex_root ();

Return the root node of the hive.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $key = $g->hivex_value_key ($valueh);

Return the key (name) field of a (key, datatype, data) tuple.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $datatype = $g->hivex_value_type ($valueh);

Return the data type field from a (key, datatype, data) tuple.

This is a wrapper around the L<hivex(3)> call of the same name.

=item $databuf = $g->hivex_value_utf8 ($valueh);

This calls C<$g-E<gt>hivex_value_value> (which returns the
data field from a hivex value tuple).  It then assumes that
the field is a UTF-16LE string and converts the result to
UTF-8 (or if this is not possible, it returns an error).

This is useful for reading strings out of the Windows registry.
However it is not foolproof because the registry is not
strongly-typed and fields can contain arbitrary or unexpected
data.

=item $databuf = $g->hivex_value_value ($valueh);

Return the data field of a (key, datatype, data) tuple.

This is a wrapper around the L<hivex(3)> call of the same name.

See also: C<$g-E<gt>hivex_value_utf8>.

=item $content = $g->initrd_cat ($initrdpath, $filename);

This command unpacks the file F<filename> from the initrd file
called F<initrdpath>.  The filename must be given I<without> the
initial F</> character.

For example, in guestfish you could use the following command
to examine the boot script (usually called F</init>)
contained in a Linux initrd or initramfs image:

 initrd-cat /boot/initrd-<version>.img init

See also C<$g-E<gt>initrd_list>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @filenames = $g->initrd_list ($path);

This command lists out files contained in an initrd.

The files are listed without any initial F</> character.  The
files are listed in the order they appear (not necessarily
alphabetical).  Directory names are listed as separate items.

Old Linux kernels (2.4 and earlier) used a compressed ext2
filesystem as initrd.  We I<only> support the newer initramfs
format (compressed cpio files).

=item $wd = $g->inotify_add_watch ($path, $mask);

Watch C<path> for the events listed in C<mask>.

Note that if C<path> is a directory then events within that
directory are watched, but this does I<not> happen recursively
(in subdirectories).

Note for non-C or non-Linux callers: the inotify events are
defined by the Linux kernel ABI and are listed in
F</usr/include/sys/inotify.h>.

=item $g->inotify_close ();

This closes the inotify handle which was previously
opened by inotify_init.  It removes all watches, throws
away any pending events, and deallocates all resources.

=item @paths = $g->inotify_files ();

This function is a helpful wrapper around C<$g-E<gt>inotify_read>
which just returns a list of pathnames of objects that were
touched.  The returned pathnames are sorted and deduplicated.

=item $g->inotify_init ($maxevents);

This command creates a new inotify handle.
The inotify subsystem can be used to notify events which happen to
objects in the guest filesystem.

C<maxevents> is the maximum number of events which will be
queued up between calls to C<$g-E<gt>inotify_read> or
C<$g-E<gt>inotify_files>.
If this is passed as C<0>, then the kernel (or previously set)
default is used.  For Linux 2.6.29 the default was 16384 events.
Beyond this limit, the kernel throws away events, but records
the fact that it threw them away by setting a flag
C<IN_Q_OVERFLOW> in the returned structure list (see
C<$g-E<gt>inotify_read>).

Before any events are generated, you have to add some
watches to the internal watch list.  See: C<$g-E<gt>inotify_add_watch> and
C<$g-E<gt>inotify_rm_watch>.

Queued up events should be read periodically by calling
C<$g-E<gt>inotify_read>
(or C<$g-E<gt>inotify_files> which is just a helpful
wrapper around C<$g-E<gt>inotify_read>).  If you don't
read the events out often enough then you risk the internal
queue overflowing.

The handle should be closed after use by calling
C<$g-E<gt>inotify_close>.  This also removes any
watches automatically.

See also L<inotify(7)> for an overview of the inotify interface
as exposed by the Linux kernel, which is roughly what we expose
via libguestfs.  Note that there is one global inotify handle
per libguestfs instance.

=item @events = $g->inotify_read ();

Return the complete queue of events that have happened
since the previous read call.

If no events have happened, this returns an empty list.

I<Note>: In order to make sure that all events have been
read, you must call this function repeatedly until it
returns an empty list.  The reason is that the call will
read events up to the maximum appliance-to-host message
size and leave remaining events in the queue.

=item $g->inotify_rm_watch ($wd);

Remove a previously defined inotify watch.
See C<$g-E<gt>inotify_add_watch>.

=item $arch = $g->inspect_get_arch ($root);

This returns the architecture of the inspected operating system.
The possible return values are listed under
C<$g-E<gt>file_architecture>.

If the architecture could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $distro = $g->inspect_get_distro ($root);

This returns the distro (distribution) of the inspected operating
system.

Currently defined distros are:

=over 4

=item "archlinux"

Arch Linux.

=item "buildroot"

Buildroot-derived distro, but not one we specifically recognize.

=item "centos"

CentOS.

=item "cirros"

Cirros.

=item "coreos"

CoreOS.

=item "debian"

Debian.

=item "fedora"

Fedora.

=item "freebsd"

FreeBSD.

=item "freedos"

FreeDOS.

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

=item "netbsd"

NetBSD.

=item "openbsd"

OpenBSD.

=item "opensuse"

OpenSUSE.

=item "oraclelinux"

Oracle Linux.

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

=item "sles"

SuSE Linux Enterprise Server or Desktop.

=item "suse-based"

Some openSuSE-derived distro.

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

=item %drives = $g->inspect_get_drive_mappings ($root);

This call is useful for Windows which uses a primitive system
of assigning drive letters (like F<C:\>) to partitions.
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
See also C<$g-E<gt>inspect_get_mountpoints>,
C<$g-E<gt>inspect_get_filesystems>.

=item @filesystems = $g->inspect_get_filesystems ($root);

This returns a list of all the filesystems that we think
are associated with this operating system.  This includes
the root filesystem, other ordinary filesystems, and
non-mounted devices like swap partitions.

In the case of a multi-boot virtual machine, it is possible
for a filesystem to be shared between operating systems.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$g-E<gt>inspect_get_mountpoints>.

=item $format = $g->inspect_get_format ($root);

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

=item $hostname = $g->inspect_get_hostname ($root);

This function returns the hostname of the operating system
as found by inspection of the guest's configuration files.

If the hostname could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $icon = $g->inspect_get_icon ($root [, favicon => $favicon] [, highquality => $highquality]);

This function returns an icon corresponding to the inspected
operating system.  The icon is returned as a buffer containing a
PNG image (re-encoded to PNG if necessary).

If it was not possible to get an icon this function returns a
zero-length (non-NULL) buffer.  I<Callers must check for this case>.

Libguestfs will start by looking for a file called
F</etc/favicon.png> or F<C:\etc\favicon.png>
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

=item $major = $g->inspect_get_major_version ($root);

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

=item $minor = $g->inspect_get_minor_version ($root);

This returns the minor version number of the inspected operating
system.

If the version could not be determined, then C<0> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$g-E<gt>inspect_get_major_version>.

=item %mountpoints = $g->inspect_get_mountpoints ($root);

This returns a hash of where we think the filesystems
associated with this operating system should be mounted.
Callers should note that this is at best an educated guess
made by reading configuration files such as F</etc/fstab>.
I<In particular note> that this may return filesystems
which are non-existent or not mountable and callers should
be prepared to handle or ignore failures if they try to
mount them.

Each element in the returned hashtable has a key which
is the path of the mountpoint (eg. F</boot>) and a value
which is the filesystem that would be mounted there
(eg. F</dev/sda1>).

Non-mounted devices such as swap devices are I<not>
returned in this list.

For operating systems like Windows which still use drive
letters, this call will only return an entry for the first
drive "mounted on" F</>.  For information about the
mapping of drive letters to partitions, see
C<$g-E<gt>inspect_get_drive_mappings>.

Please read L<guestfs(3)/INSPECTION> for more details.
See also C<$g-E<gt>inspect_get_filesystems>.

=item $packageformat = $g->inspect_get_package_format ($root);

This function and C<$g-E<gt>inspect_get_package_management> return
the package format and package management tool used by the
inspected operating system.  For example for Fedora these
functions would return C<rpm> (package format), and
C<yum> or C<dnf> (package management).

This returns the string C<unknown> if we could not determine the
package format I<or> if the operating system does not have
a real packaging system (eg. Windows).

Possible strings include:
C<rpm>, C<deb>, C<ebuild>, C<pisi>, C<pacman>, C<pkgsrc>.
Future versions of libguestfs may return other strings.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $packagemanagement = $g->inspect_get_package_management ($root);

C<$g-E<gt>inspect_get_package_format> and this function return
the package format and package management tool used by the
inspected operating system.  For example for Fedora these
functions would return C<rpm> (package format), and
C<yum> or C<dnf> (package management).

This returns the string C<unknown> if we could not determine the
package management tool I<or> if the operating system does not have
a real packaging system (eg. Windows).

Possible strings include: C<yum>, C<dnf>, C<up2date>,
C<apt> (for all Debian derivatives),
C<portage>, C<pisi>, C<pacman>, C<urpmi>, C<zypper>.
Future versions of libguestfs may return other strings.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $product = $g->inspect_get_product_name ($root);

This returns the product name of the inspected operating
system.  The product name is generally some freeform string
which can be displayed to the user, but should not be
parsed by programs.

If the product name could not be determined, then the
string C<unknown> is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $variant = $g->inspect_get_product_variant ($root);

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
See also C<$g-E<gt>inspect_get_product_name>,
C<$g-E<gt>inspect_get_major_version>.

=item @roots = $g->inspect_get_roots ();

This function is a convenient way to get the list of root
devices, as returned from a previous call to C<$g-E<gt>inspect_os>,
but without redoing the whole inspection process.

This returns an empty list if either no root devices were
found or the caller has not called C<$g-E<gt>inspect_os>.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $name = $g->inspect_get_type ($root);

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

=item "openbsd"

OpenBSD.

=item "hurd"

GNU/Hurd.

=item "dos"

MS-DOS, FreeDOS and others.

=item "minix"

MINIX.

=item "unknown"

The operating system type could not be determined.

=back

Future versions of libguestfs may return other strings here.
The caller should be prepared to handle any string.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $controlset = $g->inspect_get_windows_current_control_set ($root);

This returns the Windows CurrentControlSet of the inspected guest.
The CurrentControlSet is a registry key name such as C<ControlSet001>.

This call assumes that the guest is Windows and that the
Registry could be examined by inspection.  If this is not
the case then an error is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $systemroot = $g->inspect_get_windows_systemroot ($root);

This returns the Windows systemroot of the inspected guest.
The systemroot is a directory path such as F</WINDOWS>.

This call assumes that the guest is Windows and that the
systemroot could be determined by inspection.  If this is not
the case then an error is returned.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $live = $g->inspect_is_live ($root);

If C<$g-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if a live image
was detected on the disk.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $multipart = $g->inspect_is_multipart ($root);

If C<$g-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if the disk is
part of a set.

Please read L<guestfs(3)/INSPECTION> for more details.

=item $netinst = $g->inspect_is_netinst ($root);

If C<$g-E<gt>inspect_get_format> returns C<installer> (this
is an install disk), then this returns true if the disk is
a network installer, ie. not a self-contained install CD but
one which is likely to require network access to complete
the install.

Please read L<guestfs(3)/INSPECTION> for more details.

=item @applications = $g->inspect_list_applications ($root);

Return the list of applications installed in the operating system.

I<Note:> This call works differently from other parts of the
inspection API.  You have to call C<$g-E<gt>inspect_os>, then
C<$g-E<gt>inspect_get_mountpoints>, then mount up the disks,
before calling this.  Listing applications is a significantly
more difficult operation which requires access to the full
filesystem.  Also note that unlike the other
C<$g-E<gt>inspect_get_*> calls which are just returning
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

I<This function is deprecated.>
In new code, use the L</inspect_list_applications2> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @applications2 = $g->inspect_list_applications2 ($root);

Return the list of applications installed in the operating system.

I<Note:> This call works differently from other parts of the
inspection API.  You have to call C<$g-E<gt>inspect_os>, then
C<$g-E<gt>inspect_get_mountpoints>, then mount up the disks,
before calling this.  Listing applications is a significantly
more difficult operation which requires access to the full
filesystem.  Also note that unlike the other
C<$g-E<gt>inspect_get_*> calls which are just returning
data cached in the libguestfs handle, this call actually reads
parts of the mounted filesystems during the call.

This returns an empty list if the inspection code was not able
to determine the list of applications.

The application structure contains the following fields:

=over 4

=item C<app2_name>

The name of the application.  For Red Hat-derived and Debian-derived
Linux guests, this is the package name.

=item C<app2_display_name>

The display name of the application, sometimes localized to the
install language of the guest operating system.

If unavailable this is returned as an empty string C<"">.
Callers needing to display something can use C<app2_name> instead.

=item C<app2_epoch>

For package managers which use epochs, this contains the epoch of
the package (an integer).  If unavailable, this is returned as C<0>.

=item C<app2_version>

The version string of the application or package.  If unavailable
this is returned as an empty string C<"">.

=item C<app2_release>

The release string of the application or package, for package
managers that use this.  If unavailable this is returned as an
empty string C<"">.

=item C<app2_arch>

The architecture string of the application or package, for package
managers that use this.  If unavailable this is returned as an empty
string C<"">.

=item C<app2_install_path>

The installation path of the application (on operating systems
such as Windows which use installation paths).  This path is
in the format used by the guest operating system, it is not
a libguestfs path.

If unavailable this is returned as an empty string C<"">.

=item C<app2_trans_path>

The install path translated into a libguestfs path.
If unavailable this is returned as an empty string C<"">.

=item C<app2_publisher>

The name of the publisher of the application, for package
managers that use this.  If unavailable this is returned
as an empty string C<"">.

=item C<app2_url>

The URL (eg. upstream URL) of the application.
If unavailable this is returned as an empty string C<"">.

=item C<app2_source_package>

For packaging systems which support this, the name of the source
package.  If unavailable this is returned as an empty string C<"">.

=item C<app2_summary>

A short (usually one line) description of the application or package.
If unavailable this is returned as an empty string C<"">.

=item C<app2_description>

A longer description of the application or package.
If unavailable this is returned as an empty string C<"">.

=back

Please read L<guestfs(3)/INSPECTION> for more details.

=item @roots = $g->inspect_os ();

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
C<$g-E<gt>inspect_get_*> functions in order to query further
information about each operating system, such as the name
and version.

This function uses other libguestfs features such as
C<$g-E<gt>mount_ro> and C<$g-E<gt>umount_all> in order to mount
and unmount filesystems and look at the contents.  This should
be called with no disks currently mounted.  The function may also
use Augeas, so any existing Augeas handle will be closed.

This function cannot decrypt encrypted disks.  The caller
must do that first (supplying the necessary keys) if the
disk is encrypted.

Please read L<guestfs(3)/INSPECTION> for more details.

See also C<$g-E<gt>list_filesystems>.

=item $flag = $g->is_blockdev ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a block device
with the given C<path> name.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a block device also causes the
function to return true.

This call only looks at files within the guest filesystem.  Libguestfs
partitions and block devices (eg. F</dev/sda>) cannot be used as the
C<path> parameter of this call.

See also C<$g-E<gt>stat>.

=item $flag = $g->is_blockdev_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_blockdev>.

=cut

sub is_blockdev_opts {
  &is_blockdev (@_)
}

=pod

=item $busy = $g->is_busy ();

This always returns false.  This function is deprecated with no
replacement.  Do not use this function.

For more information on states, see L<guestfs(3)>.

=item $flag = $g->is_chardev ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a character device
with the given C<path> name.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a chardev also causes the
function to return true.

See also C<$g-E<gt>stat>.

=item $flag = $g->is_chardev_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_chardev>.

=cut

sub is_chardev_opts {
  &is_chardev (@_)
}

=pod

=item $config = $g->is_config ();

This returns true iff this handle is being configured
(in the C<CONFIG> state).

For more information on states, see L<guestfs(3)>.

=item $dirflag = $g->is_dir ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a directory
with the given C<path> name.  Note that it returns false for
other objects like files.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a directory also causes the
function to return true.

See also C<$g-E<gt>stat>.

=item $dirflag = $g->is_dir_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_dir>.

=cut

sub is_dir_opts {
  &is_dir (@_)
}

=pod

=item $flag = $g->is_fifo ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a FIFO (named pipe)
with the given C<path> name.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a FIFO also causes the
function to return true.

See also C<$g-E<gt>stat>.

=item $flag = $g->is_fifo_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_fifo>.

=cut

sub is_fifo_opts {
  &is_fifo (@_)
}

=pod

=item $fileflag = $g->is_file ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a regular file
with the given C<path> name.  Note that it returns false for
other objects like directories.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a file also causes the
function to return true.

See also C<$g-E<gt>stat>.

=item $fileflag = $g->is_file_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_file>.

=cut

sub is_file_opts {
  &is_file (@_)
}

=pod

=item $launching = $g->is_launching ();

This returns true iff this handle is launching the subprocess
(in the C<LAUNCHING> state).

For more information on states, see L<guestfs(3)>.

=item $lvflag = $g->is_lv ($device);

This command tests whether C<device> is a logical volume, and
returns true iff this is the case.

=item $ready = $g->is_ready ();

This returns true iff this handle is ready to accept commands
(in the C<READY> state).

For more information on states, see L<guestfs(3)>.

=item $flag = $g->is_socket ($path [, followsymlinks => $followsymlinks]);

This returns C<true> if and only if there is a Unix domain socket
with the given C<path> name.

If the optional flag C<followsymlinks> is true, then a symlink
(or chain of symlinks) that ends with a socket also causes the
function to return true.

See also C<$g-E<gt>stat>.

=item $flag = $g->is_socket_opts ($path [, followsymlinks => $followsymlinks]);

This is an alias of L</is_socket>.

=cut

sub is_socket_opts {
  &is_socket (@_)
}

=pod

=item $flag = $g->is_symlink ($path);

This returns C<true> if and only if there is a symbolic link
with the given C<path> name.

See also C<$g-E<gt>stat>.

=item $flag = $g->is_whole_device ($device);

This returns C<true> if and only if C<device> refers to a whole block
device. That is, not a partition or a logical device.

=item $zeroflag = $g->is_zero ($path);

This returns true iff the file exists and the file is empty or
it contains all zero bytes.

=item $zeroflag = $g->is_zero_device ($device);

This returns true iff the device exists and contains all zero bytes.

Note that for large devices this can take a long time to run.

=item %isodata = $g->isoinfo ($isofile);

This is the same as C<$g-E<gt>isoinfo_device> except that it
works for an ISO file located inside some other mounted filesystem.
Note that in the common case where you have added an ISO file
as a libguestfs device, you would I<not> call this.  Instead
you would call C<$g-E<gt>isoinfo_device>.

=item %isodata = $g->isoinfo_device ($device);

C<device> is an ISO device.  This returns a struct of information
read from the primary volume descriptor (the ISO equivalent of the
superblock) of the device.

Usually it is more efficient to use the L<isoinfo(1)> command
with the I<-d> option on the host to analyze ISO files,
instead of going through libguestfs.

For information on the primary volume descriptor fields, see
L<http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descriptor>

=item $g->journal_close ();

Close the journal handle.

=item @fields = $g->journal_get ();

Read the current journal entry.  This returns all the fields
in the journal as a set of C<(attrname, attrval)> pairs.  The
C<attrname> is the field name (a string).

The C<attrval> is the field value (a binary blob, often but
not always a string).  Please note that C<attrval> is a byte
array, I<not> a \0-terminated C string.

The length of data may be truncated to the data threshold
(see: C<$g-E<gt>journal_set_data_threshold>,
C<$g-E<gt>journal_get_data_threshold>).

If you set the data threshold to unlimited (C<0>) then this call
can read a journal entry of any size, ie. it is not limited by
the libguestfs protocol.

=item $threshold = $g->journal_get_data_threshold ();

Get the current data threshold for reading journal entries.
This is a hint to the journal that it may truncate data fields to
this size when reading them (note also that it may not truncate them).
If this returns C<0>, then the threshold is unlimited.

See also C<$g-E<gt>journal_set_data_threshold>.

=item $usec = $g->journal_get_realtime_usec ();

Get the realtime (wallclock) timestamp of the current journal entry.

=item $more = $g->journal_next ();

Move to the next journal entry.  You have to call this
at least once after opening the handle before you are able
to read data.

The returned boolean tells you if there are any more journal
records to read.  C<true> means you can read the next record
(eg. using C<$g-E<gt>journal_get>), and C<false> means you
have reached the end of the journal.

=item $g->journal_open ($directory);

Open the systemd journal located in F<directory>.  Any previously
opened journal handle is closed.

The contents of the journal can be read using C<$g-E<gt>journal_next>
and C<$g-E<gt>journal_get>.

After you have finished using the journal, you should close the
handle by calling C<$g-E<gt>journal_close>.

=item $g->journal_set_data_threshold ($threshold);

Set the data threshold for reading journal entries.
This is a hint to the journal that it may truncate data fields to
this size when reading them (note also that it may not truncate them).
If you set this to C<0>, then the threshold is unlimited.

See also C<$g-E<gt>journal_get_data_threshold>.

=item $rskip = $g->journal_skip ($skip);

Skip forwards (C<skip E<ge> 0>) or backwards (C<skip E<lt> 0>) in the
journal.

The number of entries actually skipped is returned (note S<C<rskip E<ge> 0>>).
If this is not the same as the absolute value of the skip parameter
(C<|skip|>) you passed in then it means you have reached the end or
the start of the journal.

=item $g->kill_subprocess ();

This kills the hypervisor.

Do not call this.  See: C<$g-E<gt>shutdown> instead.

I<This function is deprecated.>
In new code, use the L</shutdown> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->launch ();

You should call this after configuring the handle
(eg. adding drives) but before performing any actions.

Do not call C<$g-E<gt>launch> twice on the same handle.  Although
it will not give an error (for historical reasons), the precise
behaviour when you do this is not well defined.  Handles are
very cheap to create, so create a new one for each launch.

=item $g->lchown ($owner, $group, $path);

Change the file owner to C<owner> and group to C<group>.
This is like C<$g-E<gt>chown> but if C<path> is a symlink then
the link itself is changed, not the target.

Only numeric uid and gid are supported.  If you want to use
names, you will need to locate and parse the password file
yourself (Augeas support makes this relatively easy).

=item $g->ldmtool_create_all ();

This function scans all block devices looking for Windows
dynamic disk volumes and partitions, and creates devices
for any that were found.

Call C<$g-E<gt>list_ldm_volumes> and C<$g-E<gt>list_ldm_partitions>
to return all devices.

Note that you B<don't> normally need to call this explicitly,
since it is done automatically at C<$g-E<gt>launch> time.
However you might want to call this function if you have
hotplugged disks or have just created a Windows dynamic disk.

=item @disks = $g->ldmtool_diskgroup_disks ($diskgroup);

Return the disks in a Windows dynamic disk group.  The C<diskgroup>
parameter should be the GUID of a disk group, one element from
the list returned by C<$g-E<gt>ldmtool_scan>.

=item $name = $g->ldmtool_diskgroup_name ($diskgroup);

Return the name of a Windows dynamic disk group.  The C<diskgroup>
parameter should be the GUID of a disk group, one element from
the list returned by C<$g-E<gt>ldmtool_scan>.

=item @volumes = $g->ldmtool_diskgroup_volumes ($diskgroup);

Return the volumes in a Windows dynamic disk group.  The C<diskgroup>
parameter should be the GUID of a disk group, one element from
the list returned by C<$g-E<gt>ldmtool_scan>.

=item $g->ldmtool_remove_all ();

This is essentially the opposite of C<$g-E<gt>ldmtool_create_all>.
It removes the device mapper mappings for all Windows dynamic disk
volumes

=item @guids = $g->ldmtool_scan ();

This function scans for Windows dynamic disks.  It returns a list
of identifiers (GUIDs) for all disk groups that were found.  These
identifiers can be passed to other C<$g-E<gt>ldmtool_*> functions.

This function scans all block devices.  To scan a subset of
block devices, call C<$g-E<gt>ldmtool_scan_devices> instead.

=item @guids = $g->ldmtool_scan_devices (\@devices);

This function scans for Windows dynamic disks.  It returns a list
of identifiers (GUIDs) for all disk groups that were found.  These
identifiers can be passed to other C<$g-E<gt>ldmtool_*> functions.

The parameter C<devices> is a list of block devices which are
scanned.  If this list is empty, all block devices are scanned.

=item $hint = $g->ldmtool_volume_hint ($diskgroup, $volume);

Return the hint field of the volume named C<volume> in the disk
group with GUID C<diskgroup>.  This may not be defined, in which
case the empty string is returned.  The hint field is often, though
not always, the name of a Windows drive, eg. C<E:>.

=item @partitions = $g->ldmtool_volume_partitions ($diskgroup, $volume);

Return the list of partitions in the volume named C<volume> in the disk
group with GUID C<diskgroup>.

=item $voltype = $g->ldmtool_volume_type ($diskgroup, $volume);

Return the type of the volume named C<volume> in the disk
group with GUID C<diskgroup>.

Possible volume types that can be returned here include:
C<simple>, C<spanned>, C<striped>, C<mirrored>, C<raid5>.
Other types may also be returned.

=item $xattr = $g->lgetxattr ($path, $name);

Get a single extended attribute from file C<path> named C<name>.
If C<path> is a symlink, then this call returns an extended
attribute from the symlink.

Normally it is better to get all extended attributes from a file
in one go by calling C<$g-E<gt>getxattrs>.  However some Linux
filesystem implementations are buggy and do not provide a way to
list out attributes.  For these filesystems (notably ntfs-3g)
you have to know the names of the extended attributes you want
in advance and call this function.

Extended attribute values are blobs of binary data.  If there
is no extended attribute named C<name>, this returns an error.

See also: C<$g-E<gt>lgetxattrs>, C<$g-E<gt>getxattr>, L<attr(5)>.

=item @xattrs = $g->lgetxattrs ($path);

This is the same as C<$g-E<gt>getxattrs>, but if C<path>
is a symbolic link, then it returns the extended attributes
of the link itself.

=item @mounttags = $g->list_9p ();

List all 9p filesystems attached to the guest.  A list of
mount tags is returned.

=item @devices = $g->list_devices ();

List all the block devices.

The full block device names are returned, eg. F</dev/sda>.

See also C<$g-E<gt>list_filesystems>.

=item %labels = $g->list_disk_labels ();

If you add drives using the optional C<label> parameter
of C<$g-E<gt>add_drive_opts>, you can use this call to
map between disk labels, and raw block device and partition
names (like F</dev/sda> and F</dev/sda1>).

This returns a hashtable, where keys are the disk labels
(I<without> the F</dev/disk/guestfs> prefix), and the values
are the full raw block device and partition names
(eg. F</dev/sda> and F</dev/sda1>).

=item @devices = $g->list_dm_devices ();

List all device mapper devices.

The returned list contains F</dev/mapper/*> devices, eg. ones created
by a previous call to C<$g-E<gt>luks_open>.

Device mapper devices which correspond to logical volumes are I<not>
returned in this list.  Call C<$g-E<gt>lvs> if you want to list logical
volumes.

=item %fses = $g->list_filesystems ();

This inspection command looks for filesystems on partitions,
block devices and logical volumes, returning a list of C<mountables>
containing filesystems and their type.

The return value is a hash, where the keys are the devices
containing filesystems, and the values are the filesystem types.
For example:

 "/dev/sda1" => "ntfs"
 "/dev/sda2" => "ext2"
 "/dev/vg_guest/lv_root" => "ext4"
 "/dev/vg_guest/lv_swap" => "swap"

The key is not necessarily a block device. It may also be an opaque
'mountable' string which can be passed to C<$g-E<gt>mount>.

The value can have the special value "unknown", meaning the
content of the device is undetermined or empty.
"swap" means a Linux swap partition.

This command runs other libguestfs commands, which might include
C<$g-E<gt>mount> and C<$g-E<gt>umount>, and therefore you should
use this soon after launch and only when nothing is mounted.

Not all of the filesystems returned will be mountable.  In
particular, swap partitions are returned in the list.  Also
this command does not check that each filesystem
found is valid and mountable, and some filesystems might
be mountable but require special options.  Filesystems may
not all belong to a single logical operating system
(use C<$g-E<gt>inspect_os> to look for OSes).

=item @devices = $g->list_ldm_partitions ();

This function returns all Windows dynamic disk partitions
that were found at launch time.  It returns a list of
device names.

=item @devices = $g->list_ldm_volumes ();

This function returns all Windows dynamic disk volumes
that were found at launch time.  It returns a list of
device names.

=item @devices = $g->list_md_devices ();

List all Linux md devices.

=item @partitions = $g->list_partitions ();

List all the partitions detected on all block devices.

The full partition device names are returned, eg. F</dev/sda1>

This does not return logical volumes.  For that you will need to
call C<$g-E<gt>lvs>.

See also C<$g-E<gt>list_filesystems>.

=item $listing = $g->ll ($directory);

List the files in F<directory> (relative to the root directory,
there is no cwd) in the format of 'ls -la'.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.

=item $listing = $g->llz ($directory);

List the files in F<directory> in the format of 'ls -laZ'.

This command is mostly useful for interactive sessions.  It
is I<not> intended that you try to parse the output string.

=item $g->ln ($target, $linkname);

This command creates a hard link using the C<ln> command.

=item $g->ln_f ($target, $linkname);

This command creates a hard link using the C<ln -f> command.
The I<-f> option removes the link (C<linkname>) if it exists already.

=item $g->ln_s ($target, $linkname);

This command creates a symbolic link using the C<ln -s> command.

=item $g->ln_sf ($target, $linkname);

This command creates a symbolic link using the C<ln -sf> command,
The I<-f> option removes the link (C<linkname>) if it exists already.

=item $g->lremovexattr ($xattr, $path);

This is the same as C<$g-E<gt>removexattr>, but if C<path>
is a symbolic link, then it removes an extended attribute
of the link itself.

=item @listing = $g->ls ($directory);

List the files in F<directory> (relative to the root directory,
there is no cwd).  The '.' and '..' entries are not returned, but
hidden files are shown.

=item $g->ls0 ($dir, $filenames);

This specialized command is used to get a listing of
the filenames in the directory C<dir>.  The list of filenames
is written to the local file F<filenames> (on the host).

In the output file, the filenames are separated by C<\0> characters.

C<.> and C<..> are not returned.  The filenames are not sorted.

=item $g->lsetxattr ($xattr, $val, $vallen, $path);

This is the same as C<$g-E<gt>setxattr>, but if C<path>
is a symbolic link, then it sets an extended attribute
of the link itself.

=item %statbuf = $g->lstat ($path);

Returns file information for the given C<path>.

This is the same as C<$g-E<gt>stat> except that if C<path>
is a symbolic link, then the link is stat-ed, not the file it
refers to.

This is the same as the L<lstat(2)> system call.

I<This function is deprecated.>
In new code, use the L</lstatns> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @statbufs = $g->lstatlist ($path, \@names);

This call allows you to perform the C<$g-E<gt>lstat> operation
on multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a list of stat structs, with a one-to-one
correspondence to the C<names> list.  If any name did not exist
or could not be lstat'd, then the C<st_ino> field of that structure
is set to C<-1>.

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.
See also C<$g-E<gt>lxattrlist> for a similarly efficient call
for getting extended attributes.

I<This function is deprecated.>
In new code, use the L</lstatnslist> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item %statbuf = $g->lstatns ($path);

Returns file information for the given C<path>.

This is the same as C<$g-E<gt>statns> except that if C<path>
is a symbolic link, then the link is stat-ed, not the file it
refers to.

This is the same as the L<lstat(2)> system call.

=item @statbufs = $g->lstatnslist ($path, \@names);

This call allows you to perform the C<$g-E<gt>lstatns> operation
on multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a list of stat structs, with a one-to-one
correspondence to the C<names> list.  If any name did not exist
or could not be lstat'd, then the C<st_ino> field of that structure
is set to C<-1>.

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.
See also C<$g-E<gt>lxattrlist> for a similarly efficient call
for getting extended attributes.

=item $g->luks_add_key ($device, $key, $newkey, $keyslot);

This command adds a new key on LUKS device C<device>.
C<key> is any existing key, and is used to access the device.
C<newkey> is the new key to add.  C<keyslot> is the key slot
that will be replaced.

Note that if C<keyslot> already contains a key, then this
command will fail.  You have to use C<$g-E<gt>luks_kill_slot>
first to remove that key.

=item $g->luks_close ($device);

This closes a LUKS device that was created earlier by
C<$g-E<gt>luks_open> or C<$g-E<gt>luks_open_ro>.  The
C<device> parameter must be the name of the LUKS mapping
device (ie. F</dev/mapper/mapname>) and I<not> the name
of the underlying block device.

=item $g->luks_format ($device, $key, $keyslot);

This command erases existing data on C<device> and formats
the device as a LUKS encrypted device.  C<key> is the
initial key, which is added to key slot C<slot>.  (LUKS
supports 8 key slots, numbered 0-7).

=item $g->luks_format_cipher ($device, $key, $keyslot, $cipher);

This command is the same as C<$g-E<gt>luks_format> but
it also allows you to set the C<cipher> used.

=item $g->luks_kill_slot ($device, $key, $keyslot);

This command deletes the key in key slot C<keyslot> from the
encrypted LUKS device C<device>.  C<key> must be one of the
I<other> keys.

=item $g->luks_open ($device, $key, $mapname);

This command opens a block device which has been encrypted
according to the Linux Unified Key Setup (LUKS) standard.

C<device> is the encrypted block device or partition.

The caller must supply one of the keys associated with the
LUKS block device, in the C<key> parameter.

This creates a new block device called F</dev/mapper/mapname>.
Reads and writes to this block device are decrypted from and
encrypted to the underlying C<device> respectively.

If this block device contains LVM volume groups, then
calling C<$g-E<gt>vgscan> followed by C<$g-E<gt>vg_activate_all>
will make them visible.

Use C<$g-E<gt>list_dm_devices> to list all device mapper
devices.

=item $g->luks_open_ro ($device, $key, $mapname);

This is the same as C<$g-E<gt>luks_open> except that a read-only
mapping is created.

=item $g->lvcreate ($logvol, $volgroup, $mbytes);

This creates an LVM logical volume called C<logvol>
on the volume group C<volgroup>, with C<size> megabytes.

=item $g->lvcreate_free ($logvol, $volgroup, $percent);

Create an LVM logical volume called F</dev/volgroup/logvol>,
using approximately C<percent> % of the free space remaining
in the volume group.  Most usefully, when C<percent> is C<100>
this will create the largest possible LV.

=item $lv = $g->lvm_canonical_lv_name ($lvname);

This converts alternative naming schemes for LVs that you
might find to the canonical name.  For example, F</dev/mapper/VG-LV>
is converted to F</dev/VG/LV>.

This command returns an error if the C<lvname> parameter does
not refer to a logical volume.

See also C<$g-E<gt>is_lv>, C<$g-E<gt>canonical_device_name>.

=item $g->lvm_clear_filter ();

This undoes the effect of C<$g-E<gt>lvm_set_filter>.  LVM
will be able to see every block device.

This command also clears the LVM cache and performs a volume
group scan.

=item $g->lvm_remove_all ();

This command removes all LVM logical volumes, volume groups
and physical volumes.

=item $g->lvm_set_filter (\@devices);

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

=item $g->lvremove ($device);

Remove an LVM logical volume C<device>, where C<device> is
the path to the LV, such as F</dev/VG/LV>.

You can also remove all LVs in a volume group by specifying
the VG name, F</dev/VG>.

=item $g->lvrename ($logvol, $newlogvol);

Rename a logical volume C<logvol> with the new name C<newlogvol>.

=item $g->lvresize ($device, $mbytes);

This resizes (expands or shrinks) an existing LVM logical
volume to C<mbytes>.  When reducing, data in the reduced part
is lost.

=item $g->lvresize_free ($lv, $percent);

This expands an existing logical volume C<lv> so that it fills
C<pc>% of the remaining free space in the volume group.  Commonly
you would call this with pc = 100 which expands the logical volume
as much as possible, using all remaining free space in the volume
group.

=item @logvols = $g->lvs ();

List all the logical volumes detected.  This is the equivalent
of the L<lvs(8)> command.

This returns a list of the logical volume device names
(eg. F</dev/VolGroup00/LogVol00>).

See also C<$g-E<gt>lvs_full>, C<$g-E<gt>list_filesystems>.

=item @logvols = $g->lvs_full ();

List all the logical volumes detected.  This is the equivalent
of the L<lvs(8)> command.  The "full" version includes all fields.

=item $uuid = $g->lvuuid ($device);

This command returns the UUID of the LVM LV C<device>.

=item @xattrs = $g->lxattrlist ($path, \@names);

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
See also C<$g-E<gt>lstatlist> for a similarly efficient call
for getting standard stats.

=item $disks = $g->max_disks ();

Return the maximum number of disks that may be added to a
handle (eg. by C<$g-E<gt>add_drive_opts> and similar calls).

This function was added in libguestfs 1.19.7.  In previous
versions of libguestfs the limit was 25.

See L<guestfs(3)/MAXIMUM NUMBER OF DISKS> for additional
information on this topic.

=item $g->md_create ($name, \@devices [, missingbitmap => $missingbitmap] [, nrdevices => $nrdevices] [, spare => $spare] [, chunk => $chunk] [, level => $level]);

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

=item %info = $g->md_detail ($md);

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

=item @devices = $g->md_stat ($md);

This call returns a list of the underlying devices which make
up the single software RAID array device C<md>.

To get a list of software RAID devices, call C<$g-E<gt>list_md_devices>.

Each structure returned corresponds to one device along with
additional status information:

=over 4

=item C<mdstat_device>

The name of the underlying device.

=item C<mdstat_index>

The index of this device within the array.

=item C<mdstat_flags>

Flags associated with this device.  This is a string containing
(in no specific order) zero or more of the following flags:

=over 4

=item C<W>

write-mostly

=item C<F>

device is faulty

=item C<S>

device is a RAID spare

=item C<R>

replacement

=back

=back

=item $g->md_stop ($md);

This command deactivates the MD array named C<md>.  The
device is stopped, but it is not destroyed or zeroed.

=item $g->mkdir ($path);

Create a directory named C<path>.

=item $g->mkdir_mode ($path, $mode);

This command creates a directory, setting the initial permissions
of the directory to C<mode>.

For common Linux filesystems, the actual mode which is set will
be C<mode & ~umask & 01777>.  Non-native-Linux filesystems may
interpret the mode in other ways.

See also C<$g-E<gt>mkdir>, C<$g-E<gt>umask>

=item $g->mkdir_p ($path);

Create a directory named C<path>, creating any parent directories
as necessary.  This is like the C<mkdir -p> shell command.

=item $dir = $g->mkdtemp ($tmpl);

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

=item $g->mke2fs ($device [, blockscount => $blockscount] [, blocksize => $blocksize] [, fragsize => $fragsize] [, blockspergroup => $blockspergroup] [, numberofgroups => $numberofgroups] [, bytesperinode => $bytesperinode] [, inodesize => $inodesize] [, journalsize => $journalsize] [, numberofinodes => $numberofinodes] [, stridesize => $stridesize] [, stripewidth => $stripewidth] [, maxonlineresize => $maxonlineresize] [, reservedblockspercentage => $reservedblockspercentage] [, mmpupdateinterval => $mmpupdateinterval] [, journaldevice => $journaldevice] [, label => $label] [, lastmounteddir => $lastmounteddir] [, creatoros => $creatoros] [, fstype => $fstype] [, usagetype => $usagetype] [, uuid => $uuid] [, forcecreate => $forcecreate] [, writesbandgrouponly => $writesbandgrouponly] [, lazyitableinit => $lazyitableinit] [, lazyjournalinit => $lazyjournalinit] [, testfs => $testfs] [, discard => $discard] [, quotatype => $quotatype] [, extent => $extent] [, filetype => $filetype] [, flexbg => $flexbg] [, hasjournal => $hasjournal] [, journaldev => $journaldev] [, largefile => $largefile] [, quota => $quota] [, resizeinode => $resizeinode] [, sparsesuper => $sparsesuper] [, uninitbg => $uninitbg]);

C<mke2fs> is used to create an ext2, ext3, or ext4 filesystem
on C<device>.

The optional C<blockscount> is the size of the filesystem in blocks.
If omitted it defaults to the size of C<device>.  Note if the
filesystem is too small to contain a journal, C<mke2fs> will
silently create an ext2 filesystem instead.

=item $g->mke2fs_J ($fstype, $blocksize, $device, $journal);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on C<journal>.  It is equivalent
to the command:

 mke2fs -t fstype -b blocksize -J device=<journal> <device>

See also C<$g-E<gt>mke2journal>.

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mke2fs_JL ($fstype, $blocksize, $device, $label);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on the journal labeled C<label>.

See also C<$g-E<gt>mke2journal_L>.

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mke2fs_JU ($fstype, $blocksize, $device, $uuid);

This creates an ext2/3/4 filesystem on C<device> with
an external journal on the journal with UUID C<uuid>.

See also C<$g-E<gt>mke2journal_U>.

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mke2journal ($blocksize, $device);

This creates an ext2 external journal on C<device>.  It is equivalent
to the command:

 mke2fs -O journal_dev -b blocksize device

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mke2journal_L ($blocksize, $label, $device);

This creates an ext2 external journal on C<device> with label C<label>.

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mke2journal_U ($blocksize, $uuid, $device);

This creates an ext2 external journal on C<device> with UUID C<uuid>.

I<This function is deprecated.>
In new code, use the L</mke2fs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mkfifo ($mode, $path);

This call creates a FIFO (named pipe) called C<path> with
mode C<mode>.  It is just a convenient wrapper around
C<$g-E<gt>mknod>.

Unlike with C<$g-E<gt>mknod>, C<mode> B<must> contain only permissions
bits.

The mode actually set is affected by the umask.

=item $g->mkfs ($fstype, $device [, blocksize => $blocksize] [, features => $features] [, inode => $inode] [, sectorsize => $sectorsize] [, label => $label]);

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

=item $g->mkfs_opts ($fstype, $device [, blocksize => $blocksize] [, features => $features] [, inode => $inode] [, sectorsize => $sectorsize] [, label => $label]);

This is an alias of L</mkfs>.

=cut

sub mkfs_opts {
  &mkfs (@_)
}

=pod

=item $g->mkfs_b ($fstype, $blocksize, $device);

This call is similar to C<$g-E<gt>mkfs>, but it allows you to
control the block size of the resulting filesystem.  Supported
block sizes depend on the filesystem type, but typically they
are C<1024>, C<2048> or C<4096> only.

For VFAT and NTFS the C<blocksize> parameter is treated as
the requested cluster size.

I<This function is deprecated.>
In new code, use the L</mkfs> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mkfs_btrfs (\@devices [, allocstart => $allocstart] [, bytecount => $bytecount] [, datatype => $datatype] [, leafsize => $leafsize] [, label => $label] [, metadata => $metadata] [, nodesize => $nodesize] [, sectorsize => $sectorsize]);

Create a btrfs filesystem, allowing all configurables to be set.
For more information on the optional arguments, see L<mkfs.btrfs(8)>.

Since btrfs filesystems can span multiple devices, this takes a
non-empty list of devices.

To create general filesystems, use C<$g-E<gt>mkfs>.

=item $g->mklost_and_found ($mountpoint);

Make the C<lost+found> directory, normally in the root directory
of an ext2/3/4 filesystem.  C<mountpoint> is the directory under
which we try to create the C<lost+found> directory.

=item $g->mkmountpoint ($exemptpath);

C<$g-E<gt>mkmountpoint> and C<$g-E<gt>rmmountpoint> are
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

C<$g-E<gt>mkmountpoint> is not compatible with C<$g-E<gt>umount_all>.
You may get unexpected errors if you try to mix these calls.  It is
safest to manually unmount filesystems and remove mountpoints after use.

C<$g-E<gt>umount_all> unmounts filesystems by sorting the paths
longest first, so for this to work for manual mountpoints, you
must ensure that the innermost mountpoints have the longest
pathnames, as in the example code above.

For more details see L<https://bugzilla.redhat.com/show_bug.cgi?id=599503>

Autosync [see C<$g-E<gt>set_autosync>, this is set by default on
handles] can cause C<$g-E<gt>umount_all> to be called when the handle
is closed which can also trigger these issues.

=item $g->mknod ($mode, $devmajor, $devminor, $path);

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
C<$g-E<gt>mknod_b>, C<$g-E<gt>mknod_c> or C<$g-E<gt>mkfifo>
which are wrappers around this command which bitwise OR
in the appropriate constant for you.

The mode actually set is affected by the umask.

=item $g->mknod_b ($mode, $devmajor, $devminor, $path);

This call creates a block device node called C<path> with
mode C<mode> and device major/minor C<devmajor> and C<devminor>.
It is just a convenient wrapper around C<$g-E<gt>mknod>.

Unlike with C<$g-E<gt>mknod>, C<mode> B<must> contain only permissions
bits.

The mode actually set is affected by the umask.

=item $g->mknod_c ($mode, $devmajor, $devminor, $path);

This call creates a char device node called C<path> with
mode C<mode> and device major/minor C<devmajor> and C<devminor>.
It is just a convenient wrapper around C<$g-E<gt>mknod>.

Unlike with C<$g-E<gt>mknod>, C<mode> B<must> contain only permissions
bits.

The mode actually set is affected by the umask.

=item $g->mkswap ($device [, label => $label] [, uuid => $uuid]);

Create a Linux swap partition on C<device>.

The option arguments C<label> and C<uuid> allow you to set the
label and/or UUID of the new swap partition.

=item $g->mkswap_opts ($device [, label => $label] [, uuid => $uuid]);

This is an alias of L</mkswap>.

=cut

sub mkswap_opts {
  &mkswap (@_)
}

=pod

=item $g->mkswap_L ($label, $device);

Create a swap partition on C<device> with label C<label>.

Note that you cannot attach a swap label to a block device
(eg. F</dev/sda>), just to a partition.  This appears to be
a limitation of the kernel or swap tools.

I<This function is deprecated.>
In new code, use the L</mkswap> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mkswap_U ($uuid, $device);

Create a swap partition on C<device> with UUID C<uuid>.

I<This function is deprecated.>
In new code, use the L</mkswap> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->mkswap_file ($path);

Create a swap file.

This command just writes a swap file signature to an existing
file.  To create the file itself, use something like C<$g-E<gt>fallocate>.

=item $path = $g->mktemp ($tmpl [, suffix => $suffix]);

This command creates a temporary file.  The
C<tmpl> parameter should be a full pathname for the
temporary directory name with the final six characters being
"XXXXXX".

For example: "/tmp/myprogXXXXXX" or "/Temp/myprogXXXXXX",
the second one being suitable for Windows filesystems.

The name of the temporary file that was created
is returned.

The temporary file is created with mode 0600
and is owned by root.

The caller is responsible for deleting the temporary
file after use.

If the optional C<suffix> parameter is given, then the suffix
(eg. C<.txt>) is appended to the temporary name.

See also: C<$g-E<gt>mkdtemp>.

=item $g->modprobe ($modulename);

This loads a kernel module in the appliance.

=item $g->mount ($mountable, $mountpoint);

Mount a guest disk at a position in the filesystem.  Block devices
are named F</dev/sda>, F</dev/sdb> and so on, as they were added to
the guest.  If those block devices contain partitions, they will have
the usual names (eg. F</dev/sda1>).  Also LVM F</dev/VG/LV>-style
names can be used, or 'mountable' strings returned by
C<$g-E<gt>list_filesystems> or C<$g-E<gt>inspect_get_mountpoints>.

The rules are the same as for L<mount(2)>:  A filesystem must
first be mounted on F</> before others can be mounted.  Other
filesystems can only be mounted on directories which already
exist.

The mounted filesystem is writable, if we have sufficient permissions
on the underlying device.

Before libguestfs 1.13.16, this call implicitly added the options
C<sync> and C<noatime>.  The C<sync> option greatly slowed
writes and caused many problems for users.  If your program
might need to work with older versions of libguestfs, use
C<$g-E<gt>mount_options> instead (using an empty string for the
first parameter if you don't want any options).

=item $g->mount_9p ($mounttag, $mountpoint [, options => $options]);

Mount the virtio-9p filesystem with the tag C<mounttag> on the
directory C<mountpoint>.

If required, C<trans=virtio> will be automatically added to the options.
Any other options required can be passed in the optional C<options>
parameter.

=item $g->mount_local ($localmountpoint [, readonly => $readonly] [, options => $options] [, cachetimeout => $cachetimeout] [, debugcalls => $debugcalls]);

This call exports the libguestfs-accessible filesystem to
a local mountpoint (directory) called C<localmountpoint>.
Ordinary reads and writes to files and directories under
C<localmountpoint> are redirected through libguestfs.

If the optional C<readonly> flag is set to true, then
writes to the filesystem return error C<EROFS>.

C<options> is a comma-separated list of mount options.
See L<guestmount(1)> for some useful options.

C<cachetimeout> sets the timeout (in seconds) for cached directory
entries.  The default is 60 seconds.  See L<guestmount(1)>
for further information.

If C<debugcalls> is set to true, then additional debugging
information is generated for every FUSE call.

When C<$g-E<gt>mount_local> returns, the filesystem is ready,
but is not processing requests (access to it will block).  You
have to call C<$g-E<gt>mount_local_run> to run the main loop.

See L<guestfs(3)/MOUNT LOCAL> for full documentation.

=item $g->mount_local_run ();

Run the main loop which translates kernel calls to libguestfs
calls.

This should only be called after C<$g-E<gt>mount_local>
returns successfully.  The call will not return until the
filesystem is unmounted.

B<Note> you must I<not> make concurrent libguestfs calls
on the same handle from another thread.

You may call this from a different thread than the one which
called C<$g-E<gt>mount_local>, subject to the usual rules
for threads and libguestfs (see
L<guestfs(3)/MULTIPLE HANDLES AND MULTIPLE THREADS>).

See L<guestfs(3)/MOUNT LOCAL> for full documentation.

=item $g->mount_loop ($file, $mountpoint);

This command lets you mount F<file> (a filesystem image
in a file) on a mount point.  It is entirely equivalent to
the command C<mount -o loop file mountpoint>.

=item $g->mount_options ($options, $mountable, $mountpoint);

This is the same as the C<$g-E<gt>mount> command, but it
allows you to set the mount options as for the
L<mount(8)> I<-o> flag.

If the C<options> parameter is an empty string, then
no options are passed (all options default to whatever
the filesystem uses).

=item $g->mount_ro ($mountable, $mountpoint);

This is the same as the C<$g-E<gt>mount> command, but it
mounts the filesystem with the read-only (I<-o ro>) flag.

=item $g->mount_vfs ($options, $vfstype, $mountable, $mountpoint);

This is the same as the C<$g-E<gt>mount> command, but it
allows you to set both the mount options and the vfstype
as for the L<mount(8)> I<-o> and I<-t> flags.

=item %mps = $g->mountpoints ();

This call is similar to C<$g-E<gt>mounts>.  That call returns
a list of devices.  This one returns a hash table (map) of
device name to directory where the device is mounted.

=item @devices = $g->mounts ();

This returns the list of currently mounted filesystems.  It returns
the list of devices (eg. F</dev/sda1>, F</dev/VG/LV>).

Some internal mounts are not shown.

See also: C<$g-E<gt>mountpoints>

=item $g->mv ($src, $dest);

This moves a file from C<src> to C<dest> where C<dest> is
either a destination filename or destination directory.

See also: C<$g-E<gt>rename>.

=item $nrdisks = $g->nr_devices ();

This returns the number of whole block devices that were
added.  This is the same as the number of devices that would
be returned if you called C<$g-E<gt>list_devices>.

To find out the maximum number of devices that could be added,
call C<$g-E<gt>max_disks>.

=item $status = $g->ntfs_3g_probe ($rw, $device);

This command runs the L<ntfs-3g.probe(8)> command which probes
an NTFS C<device> for mountability.  (Not all NTFS volumes can
be mounted read-write, and some cannot be mounted at all).

C<rw> is a boolean flag.  Set it to true if you want to test
if the volume can be mounted read-write.  Set it to false if
you want to test if the volume can be mounted read-only.

The return value is an integer which C<0> if the operation
would succeed, or some non-zero value documented in the
L<ntfs-3g.probe(8)> manual page.

=item $g->ntfsclone_in ($backupfile, $device);

Restore the C<backupfile> (from a previous call to
C<$g-E<gt>ntfsclone_out>) to C<device>, overwriting
any existing contents of this device.

=item $g->ntfsclone_out ($device, $backupfile [, metadataonly => $metadataonly] [, rescue => $rescue] [, ignorefscheck => $ignorefscheck] [, preservetimestamps => $preservetimestamps] [, force => $force]);

Stream the NTFS filesystem C<device> to the local file
C<backupfile>.  The format used for the backup file is a
special format used by the L<ntfsclone(8)> tool.

If the optional C<metadataonly> flag is true, then I<only> the
metadata is saved, losing all the user data (this is useful
for diagnosing some filesystem problems).

The optional C<rescue>, C<ignorefscheck>, C<preservetimestamps>
and C<force> flags have precise meanings detailed in the
L<ntfsclone(8)> man page.

Use C<$g-E<gt>ntfsclone_in> to restore the file back to a
libguestfs device.

=item $g->ntfsfix ($device [, clearbadsectors => $clearbadsectors]);

This command repairs some fundamental NTFS inconsistencies,
resets the NTFS journal file, and schedules an NTFS consistency
check for the first boot into Windows.

This is I<not> an equivalent of Windows C<chkdsk>.  It does I<not>
scan the filesystem for inconsistencies.

The optional C<clearbadsectors> flag clears the list of bad sectors.
This is useful after cloning a disk with bad sectors to a new disk.

=item $g->ntfsresize ($device [, size => $size] [, force => $force]);

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
possible to call C<$g-E<gt>ntfsresize> multiple times on a
single filesystem without booting into Windows between each resize.

=back

See also L<ntfsresize(8)>.

=item $g->ntfsresize_opts ($device [, size => $size] [, force => $force]);

This is an alias of L</ntfsresize>.

=cut

sub ntfsresize_opts {
  &ntfsresize (@_)
}

=pod

=item $g->ntfsresize_size ($device, $size);

This command is the same as C<$g-E<gt>ntfsresize> except that it
allows you to specify the new size (in bytes) explicitly.

I<This function is deprecated.>
In new code, use the L</ntfsresize> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->parse_environment ();

Parse the program's environment and set flags in the handle
accordingly.  For example if C<LIBGUESTFS_DEBUG=1> then the
'verbose' flag is set in the handle.

I<Most programs do not need to call this>.  It is done implicitly
when you call C<$g-E<gt>create>.

See L<guestfs(3)/ENVIRONMENT VARIABLES> for a list of environment
variables that can affect libguestfs handles.  See also
L<guestfs(3)/guestfs_create_flags>, and
C<$g-E<gt>parse_environment_list>.

=item $g->parse_environment_list (\@environment);

Parse the list of strings in the argument C<environment>
and set flags in the handle accordingly.
For example if C<LIBGUESTFS_DEBUG=1> is a string in the list,
then the 'verbose' flag is set in the handle.

This is the same as C<$g-E<gt>parse_environment> except that
it parses an explicit list of strings instead of the program's
environment.

=item $g->part_add ($device, $prlogex, $startsect, $endsect);

This command adds a partition to C<device>.  If there is no partition
table on the device, call C<$g-E<gt>part_init> first.

The C<prlogex> parameter is the type of partition.  Normally you
should pass C<p> or C<primary> here, but MBR partition tables also
support C<l> (or C<logical>) and C<e> (or C<extended>) partition
types.

C<startsect> and C<endsect> are the start and end of the partition
in I<sectors>.  C<endsect> may be negative, which means it counts
backwards from the end of the disk (C<-1> is the last sector).

Creating a partition which covers the whole disk is not so easy.
Use C<$g-E<gt>part_disk> to do that.

=item $g->part_del ($device, $partnum);

This command deletes the partition numbered C<partnum> on C<device>.

Note that in the case of MBR partitioning, deleting an
extended partition also deletes any logical partitions
it contains.

=item $g->part_disk ($device, $parttype);

This command is simply a combination of C<$g-E<gt>part_init>
followed by C<$g-E<gt>part_add> to create a single primary partition
covering the whole disk.

C<parttype> is the partition table type, usually C<mbr> or C<gpt>,
but other possible values are described in C<$g-E<gt>part_init>.

=item $bootable = $g->part_get_bootable ($device, $partnum);

This command returns true if the partition C<partnum> on
C<device> has the bootable flag set.

See also C<$g-E<gt>part_set_bootable>.

=item $guid = $g->part_get_gpt_guid ($device, $partnum);

Return the GUID of numbered GPT partition C<partnum>.

=item $guid = $g->part_get_gpt_type ($device, $partnum);

Return the type GUID of numbered GPT partition C<partnum>. For MBR partitions,
return an appropriate GUID corresponding to the MBR type. Behaviour is undefined
for other partition types.

=item $idbyte = $g->part_get_mbr_id ($device, $partnum);

Returns the MBR type byte (also known as the ID byte) from
the numbered partition C<partnum>.

Note that only MBR (old DOS-style) partitions have type bytes.
You will get undefined results for other partition table
types (see C<$g-E<gt>part_get_parttype>).

=item $partitiontype = $g->part_get_mbr_part_type ($device, $partnum);

This returns the partition type of an MBR partition
numbered C<partnum> on device C<device>.

It returns C<primary>, C<logical>, or C<extended>.

=item $name = $g->part_get_name ($device, $partnum);

This gets the partition name on partition numbered C<partnum> on
device C<device>.  Note that partitions are numbered from 1.

The partition name can only be read on certain types of partition
table.  This works on C<gpt> but not on C<mbr> partitions.

=item $parttype = $g->part_get_parttype ($device);

This command examines the partition table on C<device> and
returns the partition table type (format) being used.

Common return values include: C<msdos> (a DOS/Windows style MBR
partition table), C<gpt> (a GPT/EFI-style partition table).  Other
values are possible, although unusual.  See C<$g-E<gt>part_init>
for a full list.

=item $g->part_init ($device, $parttype);

This creates an empty partition table on C<device> of one of the
partition types listed below.  Usually C<parttype> should be
either C<msdos> or C<gpt> (for large disks).

Initially there are no partitions.  Following this, you should
call C<$g-E<gt>part_add> for each partition required.

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

=item @partitions = $g->part_list ($device);

This command parses the partition table on C<device> and
returns the list of partitions found.

The fields in the returned structure are:

=over 4

=item B<part_num>

Partition number, counting from 1.

=item B<part_start>

Start of the partition I<in bytes>.  To get sectors you have to
divide by the device's sector size, see C<$g-E<gt>blockdev_getss>.

=item B<part_end>

End of the partition in bytes.

=item B<part_size>

Size of the partition in bytes.

=back

=item $g->part_set_bootable ($device, $partnum, $bootable);

This sets the bootable flag on partition numbered C<partnum> on
device C<device>.  Note that partitions are numbered from 1.

The bootable flag is used by some operating systems (notably
Windows) to determine which partition to boot from.  It is by
no means universally recognized.

=item $g->part_set_gpt_guid ($device, $partnum, $guid);

Set the GUID of numbered GPT partition C<partnum> to C<guid>.  Return an
error if the partition table of C<device> isn't GPT, or if C<guid> is not a
valid GUID.

=item $g->part_set_gpt_type ($device, $partnum, $guid);

Set the type GUID of numbered GPT partition C<partnum> to C<guid>. Return an
error if the partition table of C<device> isn't GPT, or if C<guid> is not a
valid GUID.

See L<http://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs>
for a useful list of type GUIDs.

=item $g->part_set_mbr_id ($device, $partnum, $idbyte);

Sets the MBR type byte (also known as the ID byte) of
the numbered partition C<partnum> to C<idbyte>.  Note
that the type bytes quoted in most documentation are
in fact hexadecimal numbers, but usually documented
without any leading "0x" which might be confusing.

Note that only MBR (old DOS-style) partitions have type bytes.
You will get undefined results for other partition table
types (see C<$g-E<gt>part_get_parttype>).

=item $g->part_set_name ($device, $partnum, $name);

This sets the partition name on partition numbered C<partnum> on
device C<device>.  Note that partitions are numbered from 1.

The partition name can only be set on certain types of partition
table.  This works on C<gpt> but not on C<mbr> partitions.

=item $device = $g->part_to_dev ($partition);

This function takes a partition name (eg. "/dev/sdb1") and
removes the partition number, returning the device name
(eg. "/dev/sdb").

The named partition must exist, for example as a string returned
from C<$g-E<gt>list_partitions>.

See also C<$g-E<gt>part_to_partnum>, C<$g-E<gt>device_index>.

=item $partnum = $g->part_to_partnum ($partition);

This function takes a partition name (eg. "/dev/sdb1") and
returns the partition number (eg. C<1>).

The named partition must exist, for example as a string returned
from C<$g-E<gt>list_partitions>.

See also C<$g-E<gt>part_to_dev>.

=item $g->ping_daemon ();

This is a test probe into the guestfs daemon running inside
the libguestfs appliance.  Calling this function checks that the
daemon responds to the ping message, without affecting the daemon
or attached block device(s) in any other way.

=item $content = $g->pread ($path, $count, $offset);

This command lets you read part of a file.  It reads C<count>
bytes of the file, starting at C<offset>, from file C<path>.

This may read fewer bytes than requested.  For further details
see the L<pread(2)> system call.

See also C<$g-E<gt>pwrite>, C<$g-E<gt>pread_device>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $content = $g->pread_device ($device, $count, $offset);

This command lets you read part of a block device.  It reads C<count>
bytes of C<device>, starting at C<offset>.

This may read fewer bytes than requested.  For further details
see the L<pread(2)> system call.

See also C<$g-E<gt>pread>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $g->pvchange_uuid ($device);

Generate a new random UUID for the physical volume C<device>.

=item $g->pvchange_uuid_all ();

Generate new random UUIDs for all physical volumes.

=item $g->pvcreate ($device);

This creates an LVM physical volume on the named C<device>,
where C<device> should usually be a partition name such
as F</dev/sda1>.

=item $g->pvremove ($device);

This wipes a physical volume C<device> so that LVM will no longer
recognise it.

The implementation uses the C<pvremove> command which refuses to
wipe physical volumes that contain any volume groups, so you have
to remove those first.

=item $g->pvresize ($device);

This resizes (expands or shrinks) an existing LVM physical
volume to match the new size of the underlying device.

=item $g->pvresize_size ($device, $size);

This command is the same as C<$g-E<gt>pvresize> except that it
allows you to specify the new size (in bytes) explicitly.

=item @physvols = $g->pvs ();

List all the physical volumes detected.  This is the equivalent
of the L<pvs(8)> command.

This returns a list of just the device names that contain
PVs (eg. F</dev/sda2>).

See also C<$g-E<gt>pvs_full>.

=item @physvols = $g->pvs_full ();

List all the physical volumes detected.  This is the equivalent
of the L<pvs(8)> command.  The "full" version includes all fields.

=item $uuid = $g->pvuuid ($device);

This command returns the UUID of the LVM PV C<device>.

=item $nbytes = $g->pwrite ($path, $content, $offset);

This command writes to part of a file.  It writes the data
buffer C<content> to the file C<path> starting at offset C<offset>.

This command implements the L<pwrite(2)> system call, and like
that system call it may not write the full data requested.  The
return value is the number of bytes that were actually written
to the file.  This could even be 0, although short writes are
unlikely for regular files in ordinary circumstances.

See also C<$g-E<gt>pread>, C<$g-E<gt>pwrite_device>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $nbytes = $g->pwrite_device ($device, $content, $offset);

This command writes to part of a device.  It writes the data
buffer C<content> to C<device> starting at offset C<offset>.

This command implements the L<pwrite(2)> system call, and like
that system call it may not write the full data requested
(although short writes to disk devices and partitions are
probably impossible with standard Linux kernels).

See also C<$g-E<gt>pwrite>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $content = $g->read_file ($path);

This calls returns the contents of the file C<path> as a
buffer.

Unlike C<$g-E<gt>cat>, this function can correctly
handle files that contain embedded ASCII NUL characters.

=item @lines = $g->read_lines ($path);

Return the contents of the file named C<path>.

The file contents are returned as a list of lines.  Trailing
C<LF> and C<CRLF> character sequences are I<not> returned.

Note that this function cannot correctly handle binary files
(specifically, files containing C<\0> character which is treated
as end of string).  For those you need to use the C<$g-E<gt>read_file>
function and split the buffer into lines yourself.

=item @entries = $g->readdir ($dir);

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
get a simple list of names, use C<$g-E<gt>ls>.  To get a printable
directory for human consumption, use C<$g-E<gt>ll>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $link = $g->readlink ($path);

This command reads the target of a symbolic link.

=item @links = $g->readlinklist ($path, \@names);

This call allows you to do a C<readlink> operation
on multiple files, where all files are in the directory C<path>.
C<names> is the list of files from this directory.

On return you get a list of strings, with a one-to-one
correspondence to the C<names> list.  Each string is the
value of the symbolic link.

If the L<readlink(2)> operation fails on any name, then
the corresponding result string is the empty string C<"">.
However the whole operation is completed even if there
were L<readlink(2)> errors, and so you can call this
function with names where you don't know if they are
symbolic links already (albeit slightly less efficient).

This call is intended for programs that want to efficiently
list a directory contents without making many round-trips.

=item $rpath = $g->realpath ($path);

Return the canonicalized absolute pathname of C<path>.  The
returned path has no C<.>, C<..> or symbolic link path elements.

=item $g->remount ($mountpoint [, rw => $rw]);

This call allows you to change the C<rw> (readonly/read-write)
flag on an already mounted filesystem at C<mountpoint>,
converting a readonly filesystem to be read-write, or vice-versa.

Note that at the moment you must supply the "optional" C<rw>
parameter.  In future we may allow other flags to be adjusted.

=item $g->remove_drive ($label);

This function is conceptually the opposite of C<$g-E<gt>add_drive_opts>.
It removes the drive that was previously added with label C<label>.

Note that in order to remove drives, you have to add them with
labels (see the optional C<label> argument to C<$g-E<gt>add_drive_opts>).
If you didn't use a label, then they cannot be removed.

You can call this function before or after launching the handle.
If called after launch, if the backend supports it, we try to hot
unplug the drive: see L<guestfs(3)/HOTPLUGGING>.  The disk B<must not>
be in use (eg. mounted) when you do this.  We try to detect if the
disk is in use and stop you from doing this.

=item $g->removexattr ($xattr, $path);

This call removes the extended attribute named C<xattr>
of the file C<path>.

See also: C<$g-E<gt>lremovexattr>, L<attr(5)>.

=item $g->rename ($oldpath, $newpath);

Rename a file to a new place on the same filesystem.  This is
the same as the Linux L<rename(2)> system call.  In most cases
you are better to use C<$g-E<gt>mv> instead.

=item $g->resize2fs ($device);

This resizes an ext2, ext3 or ext4 filesystem to match the size of
the underlying device.

See also L<guestfs(3)/RESIZE2FS ERRORS>.

=item $g->resize2fs_M ($device);

This command is the same as C<$g-E<gt>resize2fs>, but the filesystem
is resized to its minimum size.  This works like the I<-M> option
to the C<resize2fs> command.

To get the resulting size of the filesystem you should call
C<$g-E<gt>tune2fs_l> and read the C<Block size> and C<Block count>
values.  These two numbers, multiplied together, give the
resulting size of the minimal filesystem in bytes.

See also L<guestfs(3)/RESIZE2FS ERRORS>.

=item $g->resize2fs_size ($device, $size);

This command is the same as C<$g-E<gt>resize2fs> except that it
allows you to specify the new size (in bytes) explicitly.

See also L<guestfs(3)/RESIZE2FS ERRORS>.

=item $g->rm ($path);

Remove the single file C<path>.

=item $g->rm_f ($path);

Remove the file C<path>.

If the file doesn't exist, that error is ignored.  (Other errors,
eg. I/O errors or bad paths, are not ignored)

This call cannot remove directories.
Use C<$g-E<gt>rmdir> to remove an empty directory,
or C<$g-E<gt>rm_rf> to remove directories recursively.

=item $g->rm_rf ($path);

Remove the file or directory C<path>, recursively removing the
contents if its a directory.  This is like the C<rm -rf> shell
command.

=item $g->rmdir ($path);

Remove the single directory C<path>.

=item $g->rmmountpoint ($exemptpath);

This calls removes a mountpoint that was previously created
with C<$g-E<gt>mkmountpoint>.  See C<$g-E<gt>mkmountpoint>
for full details.

=item $g->rsync ($src, $dest [, archive => $archive] [, deletedest => $deletedest]);

This call may be used to copy or synchronize two directories
under the same libguestfs handle.  This uses the L<rsync(1)>
program which uses a fast algorithm that avoids copying files
unnecessarily.

C<src> and C<dest> are the source and destination directories.
Files are copied from C<src> to C<dest>.

The optional arguments are:

=over 4

=item C<archive>

Turns on archive mode.  This is the same as passing the
I<--archive> flag to C<rsync>.

=item C<deletedest>

Delete files at the destination that do not exist at the source.

=back

=item $g->rsync_in ($remote, $dest [, archive => $archive] [, deletedest => $deletedest]);

This call may be used to copy or synchronize the filesystem
on the host or on a remote computer with the filesystem
within libguestfs.  This uses the L<rsync(1)> program
which uses a fast algorithm that avoids copying files unnecessarily.

This call only works if the network is enabled.  See
C<$g-E<gt>set_network> or the I<--network> option to
various tools like L<guestfish(1)>.

Files are copied from the remote server and directory
specified by C<remote> to the destination directory C<dest>.

The format of the remote server string is defined by L<rsync(1)>.
Note that there is no way to supply a password or passphrase
so the target must be set up not to require one.

The optional arguments are the same as those of C<$g-E<gt>rsync>.

=item $g->rsync_out ($src, $remote [, archive => $archive] [, deletedest => $deletedest]);

This call may be used to copy or synchronize the filesystem within
libguestfs with a filesystem on the host or on a remote computer.
This uses the L<rsync(1)> program which uses a fast algorithm that
avoids copying files unnecessarily.

This call only works if the network is enabled.  See
C<$g-E<gt>set_network> or the I<--network> option to
various tools like L<guestfish(1)>.

Files are copied from the source directory C<src> to the
remote server and directory specified by C<remote>.

The format of the remote server string is defined by L<rsync(1)>.
Note that there is no way to supply a password or passphrase
so the target must be set up not to require one.

The optional arguments are the same as those of C<$g-E<gt>rsync>.

Globbing does not happen on the C<src> parameter.  In programs
which use the API directly you have to expand wildcards yourself
(see C<$g-E<gt>glob_expand>).  In guestfish you can use the C<glob>
command (see L<guestfish(1)/glob>), for example:

 ><fs> glob rsync-out /* rsync://remote/

=item $g->scrub_device ($device);

This command writes patterns over C<device> to make data retrieval
more difficult.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $g->scrub_file ($file);

This command writes patterns over a file to make data retrieval
more difficult.

The file is I<removed> after scrubbing.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $g->scrub_freespace ($dir);

This command creates the directory C<dir> and then fills it
with files until the filesystem is full, and scrubs the files
as for C<$g-E<gt>scrub_file>, and deletes them.
The intention is to scrub any free space on the partition
containing C<dir>.

It is an interface to the L<scrub(1)> program.  See that
manual page for more details.

=item $g->set_append ($append);

This function is used to add additional options to the
libguestfs appliance kernel command line.

The default is C<NULL> unless overridden by setting
C<LIBGUESTFS_APPEND> environment variable.

Setting C<append> to C<NULL> means I<no> additional options
are passed (libguestfs always adds a few of its own).

=item $g->set_attach_method ($backend);

Set the method that libguestfs uses to connect to the backend
guestfsd daemon.

See L<guestfs(3)/BACKEND>.

I<This function is deprecated.>
In new code, use the L</set_backend> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->set_autosync ($autosync);

If C<autosync> is true, this enables autosync.  Libguestfs will make a
best effort attempt to make filesystems consistent and synchronized
when the handle is closed
(also if the program exits without closing handles).

This is enabled by default (since libguestfs 1.5.24, previously it was
disabled by default).

=item $g->set_backend ($backend);

Set the method that libguestfs uses to connect to the backend
guestfsd daemon.

This handle property was previously called the "attach method".

See L<guestfs(3)/BACKEND>.

=item $g->set_backend_setting ($name, $val);

Append C<"name=value"> to the backend settings string list.
However if a string already exists matching C<"name">
or beginning with C<"name=">, then that setting is replaced.

See L<guestfs(3)/BACKEND>, L<guestfs(3)/BACKEND SETTINGS>.

=item $g->set_backend_settings (\@settings);

Set a list of zero or more settings which are passed through to
the current backend.  Each setting is a string which is interpreted
in a backend-specific way, or ignored if not understood by the
backend.

The default value is an empty list, unless the environment
variable C<LIBGUESTFS_BACKEND_SETTINGS> was set when the handle
was created.  This environment variable contains a colon-separated
list of settings.

This call replaces all backend settings.  If you want to replace
a single backend setting, see C<$g-E<gt>set_backend_setting>.
If you want to clear a single backend setting, see
C<$g-E<gt>clear_backend_setting>.

See L<guestfs(3)/BACKEND>, L<guestfs(3)/BACKEND SETTINGS>.

=item $g->set_cachedir ($cachedir);

Set the directory used by the handle to store the appliance
cache, when using a supermin appliance.  The appliance is
cached and shared between all handles which have the same
effective user ID.

The environment variables C<LIBGUESTFS_CACHEDIR> and C<TMPDIR>
control the default value: If C<LIBGUESTFS_CACHEDIR> is set, then
that is the default.  Else if C<TMPDIR> is set, then that is
the default.  Else F</var/tmp> is the default.

=item $g->set_direct ($direct);

If the direct appliance mode flag is enabled, then stdin and
stdout are passed directly through to the appliance once it
is launched.

One consequence of this is that log messages aren't caught
by the library and handled by C<$g-E<gt>set_log_message_callback>,
but go straight to stdout.

You probably don't want to use this unless you know what you
are doing.

The default is disabled.

=item $g->set_e2attrs ($file, $attrs [, clear => $clear]);

This sets or clears the file attributes C<attrs>
associated with the inode F<file>.

C<attrs> is a string of characters representing
file attributes.  See C<$g-E<gt>get_e2attrs> for a list of
possible attributes.  Not all attributes can be changed.

If optional boolean C<clear> is not present or false, then
the C<attrs> listed are set in the inode.

If C<clear> is true, then the C<attrs> listed are cleared
in the inode.

In both cases, other attributes not present in the C<attrs>
string are left unchanged.

These attributes are only present when the file is located on
an ext2/3/4 filesystem.  Using this call on other filesystem
types will result in an error.

=item $g->set_e2generation ($file, $generation);

This sets the ext2 file generation of a file.

See C<$g-E<gt>get_e2generation>.

=item $g->set_e2label ($device, $label);

This sets the ext2/3/4 filesystem label of the filesystem on
C<device> to C<label>.  Filesystem labels are limited to
16 characters.

You can use either C<$g-E<gt>tune2fs_l> or C<$g-E<gt>get_e2label>
to return the existing label on a filesystem.

I<This function is deprecated.>
In new code, use the L</set_label> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->set_e2uuid ($device, $uuid);

This sets the ext2/3/4 filesystem UUID of the filesystem on
C<device> to C<uuid>.  The format of the UUID and alternatives
such as C<clear>, C<random> and C<time> are described in the
L<tune2fs(8)> manpage.

You can use C<$g-E<gt>vfs_uuid> to return the existing UUID
of a filesystem.

I<This function is deprecated.>
In new code, use the L</set_uuid> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->set_hv ($hv);

Set the hypervisor binary that we will use.  The hypervisor
depends on the backend, but is usually the location of the
qemu/KVM hypervisor.  For the uml backend, it is the location
of the C<linux> or C<vmlinux> binary.

The default is chosen when the library was compiled by the
configure script.

You can also override this by setting the C<LIBGUESTFS_HV>
environment variable.

Note that you should call this function as early as possible
after creating the handle.  This is because some pre-launch
operations depend on testing qemu features (by running C<qemu -help>).
If the qemu binary changes, we don't retest features, and
so you might see inconsistent results.  Using the environment
variable C<LIBGUESTFS_HV> is safest of all since that picks
the qemu binary at the same time as the handle is created.

=item $g->set_label ($mountable, $label);

Set the filesystem label on C<mountable> to C<label>.

Only some filesystem types support labels, and libguestfs supports
setting labels on only a subset of these.

=over 4

=item ext2, ext3, ext4

Labels are limited to 16 bytes.

=item NTFS

Labels are limited to 128 unicode characters.

=item XFS

The label is limited to 12 bytes.  The filesystem must not
be mounted when trying to set the label.

=item btrfs

The label is limited to 256 bytes and some characters are
not allowed.  Setting the label on a btrfs subvolume will set the
label on its parent filesystem.  The filesystem must not be mounted
when trying to set the label.

=item fat

The label is limited to 11 bytes.

=back

If there is no support for changing the label
for the type of the specified filesystem,
set_label will fail and set errno as ENOTSUP.

To read the label on a filesystem, call C<$g-E<gt>vfs_label>.

=item $g->set_libvirt_requested_credential ($index, $cred);

After requesting the C<index>'th credential from the user,
call this function to pass the answer back to libvirt.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item $g->set_libvirt_supported_credentials (\@creds);

Call this function before setting an event handler for
C<GUESTFS_EVENT_LIBVIRT_AUTH>, to supply the list of credential types
that the program knows how to process.

The C<creds> list must be a non-empty list of strings.
Possible strings are:

=over 4

=item C<username>

=item C<authname>

=item C<language>

=item C<cnonce>

=item C<passphrase>

=item C<echoprompt>

=item C<noechoprompt>

=item C<realm>

=item C<external>

=back

See libvirt documentation for the meaning of these credential types.

See L<guestfs(3)/LIBVIRT AUTHENTICATION> for documentation and example code.

=item $g->set_memsize ($memsize);

This sets the memory size in megabytes allocated to the
hypervisor.  This only has any effect if called before
C<$g-E<gt>launch>.

You can also change this by setting the environment
variable C<LIBGUESTFS_MEMSIZE> before the handle is
created.

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $g->set_network ($network);

If C<network> is true, then the network is enabled in the
libguestfs appliance.  The default is false.

This affects whether commands are able to access the network
(see L<guestfs(3)/RUNNING COMMANDS>).

You must call this before calling C<$g-E<gt>launch>, otherwise
it has no effect.

=item $g->set_path ($searchpath);

Set the path that libguestfs searches for kernel and initrd.img.

The default is C<$libdir/guestfs> unless overridden by setting
C<LIBGUESTFS_PATH> environment variable.

Setting C<path> to C<NULL> restores the default path.

=item $g->set_pgroup ($pgroup);

If C<pgroup> is true, child processes are placed into
their own process group.

The practical upshot of this is that signals like C<SIGINT> (from
users pressing C<^C>) won't be received by the child process.

The default for this flag is false, because usually you want
C<^C> to kill the subprocess.  Guestfish sets this flag to
true when used interactively, so that C<^C> can cancel
long-running commands gracefully (see C<$g-E<gt>user_cancel>).

=item $g->set_program ($program);

Set the program name.  This is an informative string which the
main program may optionally set in the handle.

When the handle is created, the program name in the handle is
set to the basename from C<argv[0]>.  If that was not possible,
it is set to the empty string (but never C<NULL>).

=item $g->set_qemu ($hv);

Set the hypervisor binary (usually qemu) that we will use.

The default is chosen when the library was compiled by the
configure script.

You can also override this by setting the C<LIBGUESTFS_HV>
environment variable.

Setting C<hv> to C<NULL> restores the default qemu binary.

Note that you should call this function as early as possible
after creating the handle.  This is because some pre-launch
operations depend on testing qemu features (by running C<qemu -help>).
If the qemu binary changes, we don't retest features, and
so you might see inconsistent results.  Using the environment
variable C<LIBGUESTFS_HV> is safest of all since that picks
the qemu binary at the same time as the handle is created.

I<This function is deprecated.>
In new code, use the L</set_hv> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->set_recovery_proc ($recoveryproc);

If this is called with the parameter C<false> then
C<$g-E<gt>launch> does not create a recovery process.  The
purpose of the recovery process is to stop runaway hypervisor
processes in the case where the main program aborts abruptly.

This only has any effect if called before C<$g-E<gt>launch>,
and the default is true.

About the only time when you would want to disable this is
if the main process will fork itself into the background
("daemonize" itself).  In this case the recovery process
thinks that the main program has disappeared and so kills
the hypervisor, which is not very helpful.

=item $g->set_selinux ($selinux);

This sets the selinux flag that is passed to the appliance
at boot time.  The default is C<selinux=0> (disabled).

Note that if SELinux is enabled, it is always in
Permissive mode (C<enforcing=0>).

For more information on the architecture of libguestfs,
see L<guestfs(3)>.

=item $g->set_smp ($smp);

Change the number of virtual CPUs assigned to the appliance.  The
default is C<1>.  Increasing this may improve performance, though
often it has no effect.

This function must be called before C<$g-E<gt>launch>.

=item $g->set_tmpdir ($tmpdir);

Set the directory used by the handle to store temporary files.

The environment variables C<LIBGUESTFS_TMPDIR> and C<TMPDIR>
control the default value: If C<LIBGUESTFS_TMPDIR> is set, then
that is the default.  Else if C<TMPDIR> is set, then that is
the default.  Else F</tmp> is the default.

=item $g->set_trace ($trace);

If the command trace flag is set to 1, then libguestfs
calls, parameters and return values are traced.

If you want to trace C API calls into libguestfs (and
other libraries) then possibly a better way is to use
the external L<ltrace(1)> command.

Command traces are disabled unless the environment variable
C<LIBGUESTFS_TRACE> is defined and set to C<1>.

Trace messages are normally sent to C<stderr>, unless you
register a callback to send them somewhere else (see
C<$g-E<gt>set_event_callback>).

=item $g->set_uuid ($device, $uuid);

Set the filesystem UUID on C<device> to C<uuid>.
If this fails and the errno is ENOTSUP,
means that there is no support for changing the UUID
for the type of the specified filesystem.

Only some filesystem types support setting UUIDs.

To read the UUID on a filesystem, call C<$g-E<gt>vfs_uuid>.

=item $g->set_uuid_random ($device);

Set the filesystem UUID on C<device> to a random UUID.
If this fails and the errno is ENOTSUP,
means that there is no support for changing the UUID
for the type of the specified filesystem.

Only some filesystem types support setting UUIDs.

To read the UUID on a filesystem, call C<$g-E<gt>vfs_uuid>.

=item $g->set_verbose ($verbose);

If C<verbose> is true, this turns on verbose messages.

Verbose messages are disabled unless the environment variable
C<LIBGUESTFS_DEBUG> is defined and set to C<1>.

Verbose messages are normally sent to C<stderr>, unless you
register a callback to send them somewhere else (see
C<$g-E<gt>set_event_callback>).

=item $g->setcon ($context);

This sets the SELinux security context of the daemon
to the string C<context>.

See the documentation about SELINUX in L<guestfs(3)>.

=item $g->setxattr ($xattr, $val, $vallen, $path);

This call sets the extended attribute named C<xattr>
of the file C<path> to the value C<val> (of length C<vallen>).
The value is arbitrary 8 bit data.

See also: C<$g-E<gt>lsetxattr>, L<attr(5)>.

=item $g->sfdisk ($device, $cyls, $heads, $sectors, \@lines);

This is a direct interface to the L<sfdisk(8)> program for creating
partitions on block devices.

C<device> should be a block device, for example F</dev/sda>.

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

See also: C<$g-E<gt>sfdisk_l>, C<$g-E<gt>sfdisk_N>,
C<$g-E<gt>part_init>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->sfdiskM ($device, \@lines);

This is a simplified interface to the C<$g-E<gt>sfdisk>
command, where partition sizes are specified in megabytes
only (rounded to the nearest cylinder) and you don't need
to specify the cyls, heads and sectors parameters which
were rarely if ever used anyway.

See also: C<$g-E<gt>sfdisk>, the L<sfdisk(8)> manpage
and C<$g-E<gt>part_disk>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->sfdisk_N ($device, $partnum, $cyls, $heads, $sectors, $line);

This runs L<sfdisk(8)> option to modify just the single
partition C<n> (note: C<n> counts from 1).

For other parameters, see C<$g-E<gt>sfdisk>.  You should usually
pass C<0> for the cyls/heads/sectors parameters.

See also: C<$g-E<gt>part_add>

I<This function is deprecated.>
In new code, use the L</part_add> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $partitions = $g->sfdisk_disk_geometry ($device);

This displays the disk geometry of C<device> read from the
partition table.  Especially in the case where the underlying
block device has been resized, this can be different from the
kernel's idea of the geometry (see C<$g-E<gt>sfdisk_kernel_geometry>).

The result is in human-readable format, and not designed to
be parsed.

=item $partitions = $g->sfdisk_kernel_geometry ($device);

This displays the kernel's idea of the geometry of C<device>.

The result is in human-readable format, and not designed to
be parsed.

=item $partitions = $g->sfdisk_l ($device);

This displays the partition table on C<device>, in the
human-readable output of the L<sfdisk(8)> command.  It is
not intended to be parsed.

See also: C<$g-E<gt>part_list>

I<This function is deprecated.>
In new code, use the L</part_list> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $output = $g->sh ($command);

This call runs a command from the guest filesystem via the
guest's F</bin/sh>.

This is like C<$g-E<gt>command>, but passes the command to:

 /bin/sh -c "command"

Depending on the guest's shell, this usually results in
wildcards being expanded, shell expressions being interpolated
and so on.

All the provisos about C<$g-E<gt>command> apply to this call.

=item @lines = $g->sh_lines ($command);

This is the same as C<$g-E<gt>sh>, but splits the result
into a list of lines.

See also: C<$g-E<gt>command_lines>

=item $g->shutdown ();

This is the opposite of C<$g-E<gt>launch>.  It performs an orderly
shutdown of the backend process(es).  If the autosync flag is set
(which is the default) then the disk image is synchronized.

If the subprocess exits with an error then this function will return
an error, which should I<not> be ignored (it may indicate that the
disk image could not be written out properly).

It is safe to call this multiple times.  Extra calls are ignored.

This call does I<not> close or free up the handle.  You still
need to call C<$g-E<gt>close> afterwards.

C<$g-E<gt>close> will call this if you don't do it explicitly,
but note that any errors are ignored in that case.

=item $g->sleep ($secs);

Sleep for C<secs> seconds.

=item %statbuf = $g->stat ($path);

Returns file information for the given C<path>.

This is the same as the L<stat(2)> system call.

I<This function is deprecated.>
In new code, use the L</statns> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item %statbuf = $g->statns ($path);

Returns file information for the given C<path>.

This is the same as the L<stat(2)> system call.

=item %statbuf = $g->statvfs ($path);

Returns file system statistics for any mounted file system.
C<path> should be a file or directory in the mounted file system
(typically it is the mount point itself, but it doesn't need to be).

This is the same as the L<statvfs(2)> system call.

=item @stringsout = $g->strings ($path);

This runs the L<strings(1)> command on a file and returns
the list of printable strings found.

The C<strings> command has, in the past, had problems with
parsing untrusted files.  These are mitigated in the current
version of libguestfs, but see L<guestfs(3)/CVE-2014-8484>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @stringsout = $g->strings_e ($encoding, $path);

This is like the C<$g-E<gt>strings> command, but allows you to
specify the encoding of strings that are looked for in
the source file C<path>.

Allowed encodings are:

=over 4

=item s

Single 7-bit-byte characters like ASCII and the ASCII-compatible
parts of ISO-8859-X (this is what C<$g-E<gt>strings> uses).

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

The C<strings> command has, in the past, had problems with
parsing untrusted files.  These are mitigated in the current
version of libguestfs, but see L<guestfs(3)/CVE-2014-8484>.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $g->swapoff_device ($device);

This command disables the libguestfs appliance swap
device or partition named C<device>.
See C<$g-E<gt>swapon_device>.

=item $g->swapoff_file ($file);

This command disables the libguestfs appliance swap on file.

=item $g->swapoff_label ($label);

This command disables the libguestfs appliance swap on
labeled swap partition.

=item $g->swapoff_uuid ($uuid);

This command disables the libguestfs appliance swap partition
with the given UUID.

=item $g->swapon_device ($device);

This command enables the libguestfs appliance to use the
swap device or partition named C<device>.  The increased
memory is made available for all commands, for example
those run using C<$g-E<gt>command> or C<$g-E<gt>sh>.

Note that you should not swap to existing guest swap
partitions unless you know what you are doing.  They may
contain hibernation information, or other information that
the guest doesn't want you to trash.  You also risk leaking
information about the host to the guest this way.  Instead,
attach a new host device to the guest and swap on that.

=item $g->swapon_file ($file);

This command enables swap to a file.
See C<$g-E<gt>swapon_device> for other notes.

=item $g->swapon_label ($label);

This command enables swap to a labeled swap partition.
See C<$g-E<gt>swapon_device> for other notes.

=item $g->swapon_uuid ($uuid);

This command enables swap to a swap partition with the given UUID.
See C<$g-E<gt>swapon_device> for other notes.

=item $g->sync ();

This syncs the disk, so that any writes are flushed through to the
underlying disk image.

You should always call this if you have modified a disk image, before
closing the handle.

=item $g->syslinux ($device [, directory => $directory]);

Install the SYSLINUX bootloader on C<device>.

The device parameter must be either a whole disk formatted
as a FAT filesystem, or a partition formatted as a FAT filesystem.
In the latter case, the partition should be marked as "active"
(C<$g-E<gt>part_set_bootable>) and a Master Boot Record must be
installed (eg. using C<$g-E<gt>pwrite_device>) on the first
sector of the whole disk.
The SYSLINUX package comes with some suitable Master Boot Records.
See the L<syslinux(1)> man page for further information.

The optional arguments are:

=over 4

=item F<directory>

Install SYSLINUX in the named subdirectory, instead of in the
root directory of the FAT filesystem.

=back

Additional configuration can be supplied to SYSLINUX by
placing a file called F<syslinux.cfg> on the FAT filesystem,
either in the root directory, or under F<directory> if that
optional argument is being used.  For further information
about the contents of this file, see L<syslinux(1)>.

See also C<$g-E<gt>extlinux>.

=item @lines = $g->tail ($path);

This command returns up to the last 10 lines of a file as
a list of strings.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item @lines = $g->tail_n ($nrlines, $path);

If the parameter C<nrlines> is a positive number, this returns the last
C<nrlines> lines of the file C<path>.

If the parameter C<nrlines> is a negative number, this returns lines
from the file C<path>, starting with the C<-nrlines>th line.

If the parameter C<nrlines> is zero, this returns an empty list.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

=item $g->tar_in ($tarfile, $directory [, compress => $compress]);

This command uploads and unpacks local file C<tarfile> into F<directory>.

The optional C<compress> flag controls compression.  If not given,
then the input should be an uncompressed tar file.  Otherwise one
of the following strings may be given to select the compression
type of the input file: C<compress>, C<gzip>, C<bzip2>, C<xz>, C<lzop>.
(Note that not all builds of libguestfs will support all of these
compression types).

=item $g->tar_in_opts ($tarfile, $directory [, compress => $compress]);

This is an alias of L</tar_in>.

=cut

sub tar_in_opts {
  &tar_in (@_)
}

=pod

=item $g->tar_out ($directory, $tarfile [, compress => $compress] [, numericowner => $numericowner] [, excludes => $excludes]);

This command packs the contents of F<directory> and downloads
it to local file C<tarfile>.

The optional C<compress> flag controls compression.  If not given,
then the output will be an uncompressed tar file.  Otherwise one
of the following strings may be given to select the compression
type of the output file: C<compress>, C<gzip>, C<bzip2>, C<xz>, C<lzop>.
(Note that not all builds of libguestfs will support all of these
compression types).

The other optional arguments are:

=over 4

=item C<excludes>

A list of wildcards.  Files are excluded if they match any of the
wildcards.

=item C<numericowner>

If set to true, the output tar file will contain UID/GID numbers
instead of user/group names.

=back

=item $g->tar_out_opts ($directory, $tarfile [, compress => $compress] [, numericowner => $numericowner] [, excludes => $excludes]);

This is an alias of L</tar_out>.

=cut

sub tar_out_opts {
  &tar_out (@_)
}

=pod

=item $g->tgz_in ($tarball, $directory);

This command uploads and unpacks local file C<tarball> (a
I<gzip compressed> tar file) into F<directory>.

I<This function is deprecated.>
In new code, use the L</tar_in> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->tgz_out ($directory, $tarball);

This command packs the contents of F<directory> and downloads
it to local file C<tarball>.

I<This function is deprecated.>
In new code, use the L</tar_out> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->touch ($path);

Touch acts like the L<touch(1)> command.  It can be used to
update the timestamps on a file, or, if the file does not exist,
to create a new zero-length file.

This command only works on regular files, and will fail on other
file types such as directories, symbolic links, block special etc.

=item $g->truncate ($path);

This command truncates C<path> to a zero-length file.  The
file must exist already.

=item $g->truncate_size ($path, $size);

This command truncates C<path> to size C<size> bytes.  The file
must exist already.

If the current file size is less than C<size> then
the file is extended to the required size with zero bytes.
This creates a sparse file (ie. disk blocks are not allocated
for the file until you write to it).  To create a non-sparse
file of zeroes, use C<$g-E<gt>fallocate64> instead.

=item $g->tune2fs ($device [, force => $force] [, maxmountcount => $maxmountcount] [, mountcount => $mountcount] [, errorbehavior => $errorbehavior] [, group => $group] [, intervalbetweenchecks => $intervalbetweenchecks] [, reservedblockspercentage => $reservedblockspercentage] [, lastmounteddirectory => $lastmounteddirectory] [, reservedblockscount => $reservedblockscount] [, user => $user]);

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
C<$g-E<gt>tune2fs_l>.  For precise details of how tune2fs
works, see the L<tune2fs(8)> man page.

=item %superblock = $g->tune2fs_l ($device);

This returns the contents of the ext2, ext3 or ext4 filesystem
superblock on C<device>.

It is the same as running C<tune2fs -l device>.  See L<tune2fs(8)>
manpage for more details.  The list of fields returned isn't
clearly defined, and depends on both the version of C<tune2fs>
that libguestfs was built against, and the filesystem itself.

=item $g->txz_in ($tarball, $directory);

This command uploads and unpacks local file C<tarball> (an
I<xz compressed> tar file) into F<directory>.

I<This function is deprecated.>
In new code, use the L</tar_in> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->txz_out ($directory, $tarball);

This command packs the contents of F<directory> and downloads
it to local file C<tarball> (as an xz compressed tar archive).

I<This function is deprecated.>
In new code, use the L</tar_out> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $oldmask = $g->umask ($mask);

This function sets the mask used for creating new files and
device nodes to C<mask & 0777>.

Typical umask values would be C<022> which creates new files
with permissions like "-rw-r--r--" or "-rwxr-xr-x", and
C<002> which creates new files with permissions like
"-rw-rw-r--" or "-rwxrwxr-x".

The default umask is C<022>.  This is important because it
means that directories and device nodes will be created with
C<0644> or C<0755> mode even if you specify C<0777>.

See also C<$g-E<gt>get_umask>,
L<umask(2)>, C<$g-E<gt>mknod>, C<$g-E<gt>mkdir>.

This call returns the previous umask.

=item $g->umount ($pathordevice [, force => $force] [, lazyunmount => $lazyunmount]);

This unmounts the given filesystem.  The filesystem may be
specified either by its mountpoint (path) or the device which
contains the filesystem.

=item $g->umount_opts ($pathordevice [, force => $force] [, lazyunmount => $lazyunmount]);

This is an alias of L</umount>.

=cut

sub umount_opts {
  &umount (@_)
}

=pod

=item $g->umount_all ();

This unmounts all mounted filesystems.

Some internal mounts are not unmounted by this call.

=item $g->umount_local ([retry => $retry]);

If libguestfs is exporting the filesystem on a local
mountpoint, then this unmounts it.

See L<guestfs(3)/MOUNT LOCAL> for full documentation.

=item $g->upload ($filename, $remotefilename);

Upload local file F<filename> to F<remotefilename> on the
filesystem.

F<filename> can also be a named pipe.

See also C<$g-E<gt>download>.

=item $g->upload_offset ($filename, $remotefilename, $offset);

Upload local file F<filename> to F<remotefilename> on the
filesystem.

F<remotefilename> is overwritten starting at the byte C<offset>
specified.  The intention is to overwrite parts of existing
files or devices, although if a non-existent file is specified
then it is created with a "hole" before C<offset>.  The
size of the data written is implicit in the size of the
source F<filename>.

Note that there is no limit on the amount of data that
can be uploaded with this call, unlike with C<$g-E<gt>pwrite>,
and this call always writes the full amount unless an
error occurs.

See also C<$g-E<gt>upload>, C<$g-E<gt>pwrite>.

=item $g->user_cancel ();

This function cancels the current upload or download operation.

Unlike most other libguestfs calls, this function is signal safe and
thread safe.  You can call it from a signal handler or from another
thread, without needing to do any locking.

The transfer that was in progress (if there is one) will stop shortly
afterwards, and will return an error.  The errno (see
L</guestfs_last_errno>) is set to C<EINTR>, so you can test for this
to find out if the operation was cancelled or failed because of
another error.

No cleanup is performed: for example, if a file was being uploaded
then after cancellation there may be a partially uploaded file.  It is
the caller's responsibility to clean up if necessary.

There are two common places that you might call C<$g-E<gt>user_cancel>:

In an interactive text-based program, you might call it from a
C<SIGINT> signal handler so that pressing C<^C> cancels the current
operation.  (You also need to call L</guestfs_set_pgroup> so that
child processes don't receive the C<^C> signal).

In a graphical program, when the main thread is displaying a progress
bar with a cancel button, wire up the cancel button to call this
function.

=item $g->utimens ($path, $atsecs, $atnsecs, $mtsecs, $mtnsecs);

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

=item %uts = $g->utsname ();

This returns the kernel version of the appliance, where this is
available.  This information is only useful for debugging.  Nothing
in the returned structure is defined by the API.

=item %version = $g->version ();

Return the libguestfs version number that the program is linked
against.

Note that because of dynamic linking this is not necessarily
the version of libguestfs that you compiled against.  You can
compile the program, and then at runtime dynamically link
against a completely different F<libguestfs.so> library.

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
Use C<$g-E<gt>available> or C<$g-E<gt>feature_available> instead.

=item $label = $g->vfs_label ($mountable);

This returns the label of the filesystem on C<mountable>.

If the filesystem is unlabeled, this returns the empty string.

To find a filesystem from the label, use C<$g-E<gt>findfs_label>.

=item $fstype = $g->vfs_type ($mountable);

This command gets the filesystem type corresponding to
the filesystem on C<mountable>.

For most filesystems, the result is the name of the Linux
VFS module which would be used to mount this filesystem
if you mounted it without specifying the filesystem type.
For example a string such as C<ext3> or C<ntfs>.

=item $uuid = $g->vfs_uuid ($mountable);

This returns the filesystem UUID of the filesystem on C<mountable>.

If the filesystem does not have a UUID, this returns the empty string.

To find a filesystem from the UUID, use C<$g-E<gt>findfs_uuid>.

=item $g->vg_activate ($activate, \@volgroups);

This command activates or (if C<activate> is false) deactivates
all logical volumes in the listed volume groups C<volgroups>.

This command is the same as running C<vgchange -a y|n volgroups...>

Note that if C<volgroups> is an empty list then B<all> volume groups
are activated or deactivated.

=item $g->vg_activate_all ($activate);

This command activates or (if C<activate> is false) deactivates
all logical volumes in all volume groups.

This command is the same as running C<vgchange -a y|n>

=item $g->vgchange_uuid ($vg);

Generate a new random UUID for the volume group C<vg>.

=item $g->vgchange_uuid_all ();

Generate new random UUIDs for all volume groups.

=item $g->vgcreate ($volgroup, \@physvols);

This creates an LVM volume group called C<volgroup>
from the non-empty list of physical volumes C<physvols>.

=item @uuids = $g->vglvuuids ($vgname);

Given a VG called C<vgname>, this returns the UUIDs of all
the logical volumes created in this volume group.

You can use this along with C<$g-E<gt>lvs> and C<$g-E<gt>lvuuid>
calls to associate logical volumes and volume groups.

See also C<$g-E<gt>vgpvuuids>.

=item $metadata = $g->vgmeta ($vgname);

C<vgname> is an LVM volume group.  This command examines the
volume group and returns its metadata.

Note that the metadata is an internal structure used by LVM,
subject to change at any time, and is provided for information only.

=item @uuids = $g->vgpvuuids ($vgname);

Given a VG called C<vgname>, this returns the UUIDs of all
the physical volumes that this volume group resides on.

You can use this along with C<$g-E<gt>pvs> and C<$g-E<gt>pvuuid>
calls to associate physical volumes and volume groups.

See also C<$g-E<gt>vglvuuids>.

=item $g->vgremove ($vgname);

Remove an LVM volume group C<vgname>, (for example C<VG>).

This also forcibly removes all logical volumes in the volume
group (if any).

=item $g->vgrename ($volgroup, $newvolgroup);

Rename a volume group C<volgroup> with the new name C<newvolgroup>.

=item @volgroups = $g->vgs ();

List all the volumes groups detected.  This is the equivalent
of the L<vgs(8)> command.

This returns a list of just the volume group names that were
detected (eg. C<VolGroup00>).

See also C<$g-E<gt>vgs_full>.

=item @volgroups = $g->vgs_full ();

List all the volumes groups detected.  This is the equivalent
of the L<vgs(8)> command.  The "full" version includes all fields.

=item $g->vgscan ();

This rescans all block devices and rebuilds the list of LVM
physical volumes, volume groups and logical volumes.

=item $uuid = $g->vguuid ($vgname);

This command returns the UUID of the LVM VG named C<vgname>.

=item $g->wait_ready ();

This function is a no op.

In versions of the API E<lt> 1.0.71 you had to call this function
just after calling C<$g-E<gt>launch> to wait for the launch
to complete.  However this is no longer necessary because
C<$g-E<gt>launch> now does the waiting.

If you see any calls to this function in code then you can just
remove them, unless you want to retain compatibility with older
versions of the API.

I<This function is deprecated.>
In new code, use the L</launch> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $chars = $g->wc_c ($path);

This command counts the characters in a file, using the
C<wc -c> external command.

=item $lines = $g->wc_l ($path);

This command counts the lines in a file, using the
C<wc -l> external command.

=item $words = $g->wc_w ($path);

This command counts the words in a file, using the
C<wc -w> external command.

=item $g->wipefs ($device);

This command erases filesystem or RAID signatures from
the specified C<device> to make the filesystem invisible to libblkid.

This does not erase the filesystem itself nor any other data from the
C<device>.

Compare with C<$g-E<gt>zero> which zeroes the first few blocks of a
device.

=item $g->write ($path, $content);

This call creates a file called C<path>.  The content of the
file is the string C<content> (which can contain any 8 bit data).

See also C<$g-E<gt>write_append>.

=item $g->write_append ($path, $content);

This call appends C<content> to the end of file C<path>.  If
C<path> does not exist, then a new file is created.

See also C<$g-E<gt>write>.

=item $g->write_file ($path, $content, $size);

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

=item $g->xfs_admin ($device [, extunwritten => $extunwritten] [, imgfile => $imgfile] [, v2log => $v2log] [, projid32bit => $projid32bit] [, lazycounter => $lazycounter] [, label => $label] [, uuid => $uuid]);

Change the parameters of the XFS filesystem on C<device>.

Devices that are mounted cannot be modified.
Administrators must unmount filesystems before this call
can modify parameters.

Some of the parameters of a mounted filesystem can be examined
and modified using the C<$g-E<gt>xfs_info> and
C<$g-E<gt>xfs_growfs> calls.

=item $g->xfs_growfs ($path [, datasec => $datasec] [, logsec => $logsec] [, rtsec => $rtsec] [, datasize => $datasize] [, logsize => $logsize] [, rtsize => $rtsize] [, rtextsize => $rtextsize] [, maxpct => $maxpct]);

Grow the XFS filesystem mounted at C<path>.

The returned struct contains geometry information.  Missing
fields are returned as C<-1> (for numeric fields) or empty
string.

=item %info = $g->xfs_info ($pathordevice);

C<pathordevice> is a mounted XFS filesystem or a device containing
an XFS filesystem.  This command returns the geometry of the filesystem.

The returned struct contains geometry information.  Missing
fields are returned as C<-1> (for numeric fields) or empty
string.

=item $status = $g->xfs_repair ($device [, forcelogzero => $forcelogzero] [, nomodify => $nomodify] [, noprefetch => $noprefetch] [, forcegeometry => $forcegeometry] [, maxmem => $maxmem] [, ihashsize => $ihashsize] [, bhashsize => $bhashsize] [, agstride => $agstride] [, logdev => $logdev] [, rtdev => $rtdev]);

Repair corrupt or damaged XFS filesystem on C<device>.

The filesystem is specified using the C<device> argument which should be
the device name of the disk partition or volume containing the filesystem.
If given the name of a block device, C<xfs_repair> will attempt to find
the raw device associated with the specified block device and will use
the raw device instead.

Regardless, the filesystem to be repaired must be unmounted, otherwise,
the resulting filesystem may be inconsistent or corrupt.

The returned status indicates whether filesystem corruption was
detected (returns C<1>) or was not detected (returns C<0>).

=item @lines = $g->zegrep ($regex, $path);

This calls the external C<zegrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->zegrepi ($regex, $path);

This calls the external C<zegrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $g->zero ($device);

This command writes zeroes over the first few blocks of C<device>.

How many blocks are zeroed isn't specified (but it's I<not> enough
to securely wipe the device).  It should be sufficient to remove
any partition tables, filesystem superblocks and so on.

If blocks are already zero, then this command avoids writing
zeroes.  This prevents the underlying device from becoming non-sparse
or growing unnecessarily.

See also: C<$g-E<gt>zero_device>, C<$g-E<gt>scrub_device>,
C<$g-E<gt>is_zero_device>

=item $g->zero_device ($device);

This command writes zeroes over the entire C<device>.  Compare
with C<$g-E<gt>zero> which just zeroes the first few blocks of
a device.

If blocks are already zero, then this command avoids writing
zeroes.  This prevents the underlying device from becoming non-sparse
or growing unnecessarily.

=item $g->zero_free_space ($directory);

Zero the free space in the filesystem mounted on F<directory>.
The filesystem must be mounted read-write.

The filesystem contents are not affected, but any free space
in the filesystem is freed.

Free space is not "trimmed".  You may want to call
C<$g-E<gt>fstrim> either as an alternative to this,
or after calling this, depending on your requirements.

=item $g->zerofree ($device);

This runs the I<zerofree> program on C<device>.  This program
claims to zero unused inodes and disk blocks on an ext2/3
filesystem, thus making it possible to compress the filesystem
more effectively.

You should B<not> run this program if the filesystem is
mounted.

It is possible that using this program can damage the filesystem
or data on the filesystem.

=item @lines = $g->zfgrep ($pattern, $path);

This calls the external C<zfgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->zfgrepi ($pattern, $path);

This calls the external C<zfgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item $description = $g->zfile ($meth, $path);

This command runs F<file> after first decompressing C<path>
using C<method>.

C<method> must be one of C<gzip>, C<compress> or C<bzip2>.

Since 1.0.63, use C<$g-E<gt>file> instead which can now
process compressed files.

I<This function is deprecated.>
In new code, use the L</file> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->zgrep ($regex, $path);

This calls the external C<zgrep> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=item @lines = $g->zgrepi ($regex, $path);

This calls the external C<zgrep -i> program and returns the
matching lines.

Because of the message protocol, there is a transfer limit
of somewhere between 2MB and 4MB.  See L<guestfs(3)/PROTOCOL LIMITS>.

I<This function is deprecated.>
In new code, use the L</grep> call instead.

Deprecated functions will not be removed from the API, but the
fact that they are deprecated indicates that there are problems
with correct use of these functions.

=cut

use vars qw(%guestfs_introspection);
%guestfs_introspection = (
  "acl_delete_def_file" => {
    ret => 'void',
    args => [
      [ 'dir', 'string(path)', 0 ],
    ],
    name => "acl_delete_def_file",
    description => "delete the default POSIX ACL of a directory",
  },
  "acl_get_file" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'acltype', 'string', 1 ],
    ],
    name => "acl_get_file",
    description => "get the POSIX ACL attached to a file",
  },
  "acl_set_file" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'acltype', 'string', 1 ],
      [ 'acl', 'string', 2 ],
    ],
    name => "acl_set_file",
    description => "set the POSIX ACL attached to a file",
  },
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
      cachemode => [ 'cachemode', 'string', 6 ],
      discard => [ 'discard', 'string', 7 ],
      copyonread => [ 'copyonread', 'bool', 8 ],
    },
    name => "add_domain",
    description => "add the disk(s) from a named libvirt domain",
  },
  "add_drive" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    optargs => {
      readonly => [ 'readonly', 'bool', 0 ],
      format => [ 'format', 'string', 1 ],
      iface => [ 'iface', 'string', 2 ],
      name => [ 'name', 'string', 3 ],
      label => [ 'label', 'string', 4 ],
      protocol => [ 'protocol', 'string', 5 ],
      server => [ 'server', 'string list', 6 ],
      username => [ 'username', 'string', 7 ],
      secret => [ 'secret', 'string', 8 ],
      cachemode => [ 'cachemode', 'string', 9 ],
      discard => [ 'discard', 'string', 10 ],
      copyonread => [ 'copyonread', 'bool', 11 ],
    },
    name => "add_drive",
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
  "add_drive_scratch" => {
    ret => 'void',
    args => [
      [ 'size', 'int64', 0 ],
    ],
    optargs => {
      name => [ 'name', 'string', 0 ],
      label => [ 'label', 'string', 1 ],
    },
    name => "add_drive_scratch",
    description => "add a temporary scratch drive",
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
  "add_libvirt_dom" => {
    ret => 'int',
    args => [
      [ 'dom', 'pointer(virDomainPtr)', 0 ],
    ],
    optargs => {
      readonly => [ 'readonly', 'bool', 0 ],
      iface => [ 'iface', 'string', 1 ],
      live => [ 'live', 'bool', 2 ],
      readonlydisk => [ 'readonlydisk', 'string', 3 ],
      cachemode => [ 'cachemode', 'string', 4 ],
      discard => [ 'discard', 'string', 5 ],
      copyonread => [ 'copyonread', 'bool', 6 ],
    },
    name => "add_libvirt_dom",
    description => "add the disk(s) from a libvirt domain",
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
  "aug_label" => {
    ret => 'string',
    args => [
      [ 'augpath', 'string', 0 ],
    ],
    name => "aug_label",
    description => "return the label from an Augeas path expression",
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
  "aug_setm" => {
    ret => 'int',
    args => [
      [ 'base', 'string', 0 ],
      [ 'sub', 'nullable string', 1 ],
      [ 'val', 'string', 2 ],
    ],
    name => "aug_setm",
    description => "set multiple Augeas nodes",
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
  "blkdiscard" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blkdiscard",
    description => "discard all blocks on a device",
  },
  "blkdiscardzeroes" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "blkdiscardzeroes",
    description => "return true if discarded blocks are read as zeroes",
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
  "blockdev_setra" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'sectors', 'int', 1 ],
    ],
    name => "blockdev_setra",
    description => "set readahead",
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
  "btrfs_balance_cancel" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_balance_cancel",
    description => "cancel a running or paused balance",
  },
  "btrfs_balance_pause" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_balance_pause",
    description => "pause a running balance",
  },
  "btrfs_balance_resume" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_balance_resume",
    description => "resume a paused balance",
  },
  "btrfs_balance_status" => {
    ret => 'struct btrfsbalance',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_balance_status",
    description => "show the status of a running or paused balance",
  },
  "btrfs_device_add" => {
    ret => 'void',
    args => [
      [ 'devices', 'string(device) list', 0 ],
      [ 'fs', 'string(path)', 1 ],
    ],
    name => "btrfs_device_add",
    description => "add devices to a btrfs filesystem",
  },
  "btrfs_device_delete" => {
    ret => 'void',
    args => [
      [ 'devices', 'string(device) list', 0 ],
      [ 'fs', 'string(path)', 1 ],
    ],
    name => "btrfs_device_delete",
    description => "remove devices from a btrfs filesystem",
  },
  "btrfs_filesystem_balance" => {
    ret => 'void',
    args => [
      [ 'fs', 'string(path)', 0 ],
    ],
    name => "btrfs_filesystem_balance",
    description => "balance a btrfs filesystem",
  },
  "btrfs_filesystem_defragment" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    optargs => {
      flush => [ 'flush', 'bool', 0 ],
      compress => [ 'compress', 'string', 1 ],
    },
    name => "btrfs_filesystem_defragment",
    description => "defragment a file or directory",
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
  "btrfs_filesystem_sync" => {
    ret => 'void',
    args => [
      [ 'fs', 'string(path)', 0 ],
    ],
    name => "btrfs_filesystem_sync",
    description => "sync a btrfs filesystem",
  },
  "btrfs_fsck" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      superblock => [ 'superblock', 'int64', 0 ],
      repair => [ 'repair', 'bool', 1 ],
    },
    name => "btrfs_fsck",
    description => "check a btrfs filesystem",
  },
  "btrfs_image" => {
    ret => 'void',
    args => [
      [ 'source', 'string(device) list', 0 ],
      [ 'image', 'string(path)', 1 ],
    ],
    optargs => {
      compresslevel => [ 'compresslevel', 'int', 0 ],
    },
    name => "btrfs_image",
    description => "create an image of a btrfs filesystem",
  },
  "btrfs_qgroup_assign" => {
    ret => 'void',
    args => [
      [ 'src', 'string', 0 ],
      [ 'dst', 'string', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "btrfs_qgroup_assign",
    description => "add a qgroup to a parent qgroup",
  },
  "btrfs_qgroup_create" => {
    ret => 'void',
    args => [
      [ 'qgroupid', 'string', 0 ],
      [ 'subvolume', 'string(path)', 1 ],
    ],
    name => "btrfs_qgroup_create",
    description => "create a subvolume quota group",
  },
  "btrfs_qgroup_destroy" => {
    ret => 'void',
    args => [
      [ 'qgroupid', 'string', 0 ],
      [ 'subvolume', 'string(path)', 1 ],
    ],
    name => "btrfs_qgroup_destroy",
    description => "destroy a subvolume quota group",
  },
  "btrfs_qgroup_limit" => {
    ret => 'void',
    args => [
      [ 'subvolume', 'string(path)', 0 ],
      [ 'size', 'int64', 1 ],
    ],
    name => "btrfs_qgroup_limit",
    description => "limit the size of a subvolume",
  },
  "btrfs_qgroup_remove" => {
    ret => 'void',
    args => [
      [ 'src', 'string', 0 ],
      [ 'dst', 'string', 1 ],
      [ 'path', 'string(path)', 2 ],
    ],
    name => "btrfs_qgroup_remove",
    description => "remove a qgroup from its parent qgroup",
  },
  "btrfs_qgroup_show" => {
    ret => 'struct btrfsqgroup list',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_qgroup_show",
    description => "show subvolume quota groups",
  },
  "btrfs_quota_enable" => {
    ret => 'void',
    args => [
      [ 'fs', 'string(mountable_or_path)', 0 ],
      [ 'enable', 'bool', 1 ],
    ],
    name => "btrfs_quota_enable",
    description => "enable or disable subvolume quota support",
  },
  "btrfs_quota_rescan" => {
    ret => 'void',
    args => [
      [ 'fs', 'string(mountable_or_path)', 0 ],
    ],
    name => "btrfs_quota_rescan",
    description => "trash all qgroup numbers and scan the metadata again with the current config",
  },
  "btrfs_replace" => {
    ret => 'void',
    args => [
      [ 'srcdev', 'string(device)', 0 ],
      [ 'targetdev', 'string(device)', 1 ],
      [ 'mntpoint', 'string(path)', 2 ],
    ],
    name => "btrfs_replace",
    description => "replace a btrfs managed device with another device",
  },
  "btrfs_rescue_chunk_recover" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "btrfs_rescue_chunk_recover",
    description => "recover the chunk tree of btrfs filesystem",
  },
  "btrfs_rescue_super_recover" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "btrfs_rescue_super_recover",
    description => "recover bad superblocks from good copies",
  },
  "btrfs_scrub_cancel" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_scrub_cancel",
    description => "cancel a running scrub",
  },
  "btrfs_scrub_resume" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_scrub_resume",
    description => "resume a previously canceled or interrupted scrub",
  },
  "btrfs_scrub_start" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_scrub_start",
    description => "read all data from all disks and verify checksums",
  },
  "btrfs_scrub_status" => {
    ret => 'struct btrfsscrub',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "btrfs_scrub_status",
    description => "show status of running or finished scrub",
  },
  "btrfs_set_seeding" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'seeding', 'bool', 1 ],
    ],
    name => "btrfs_set_seeding",
    description => "enable or disable the seeding feature of device",
  },
  "btrfs_subvolume_create" => {
    ret => 'void',
    args => [
      [ 'dest', 'string(path)', 0 ],
    ],
    optargs => {
      qgroupid => [ 'qgroupid', 'string', 0 ],
    },
    name => "btrfs_subvolume_create",
    description => "create a btrfs subvolume",
  },
  "btrfs_subvolume_delete" => {
    ret => 'void',
    args => [
      [ 'subvolume', 'string(path)', 0 ],
    ],
    name => "btrfs_subvolume_delete",
    description => "delete a btrfs subvolume or snapshot",
  },
  "btrfs_subvolume_get_default" => {
    ret => 'int64',
    args => [
      [ 'fs', 'string(mountable_or_path)', 0 ],
    ],
    name => "btrfs_subvolume_get_default",
    description => "get the default subvolume or snapshot of a filesystem",
  },
  "btrfs_subvolume_list" => {
    ret => 'struct btrfssubvolume list',
    args => [
      [ 'fs', 'string(mountable_or_path)', 0 ],
    ],
    name => "btrfs_subvolume_list",
    description => "list btrfs snapshots and subvolumes",
  },
  "btrfs_subvolume_set_default" => {
    ret => 'void',
    args => [
      [ 'id', 'int64', 0 ],
      [ 'fs', 'string(path)', 1 ],
    ],
    name => "btrfs_subvolume_set_default",
    description => "set default btrfs subvolume",
  },
  "btrfs_subvolume_show" => {
    ret => 'hash',
    args => [
      [ 'subvolume', 'string(path)', 0 ],
    ],
    name => "btrfs_subvolume_show",
    description => "return detailed information of the subvolume",
  },
  "btrfs_subvolume_snapshot" => {
    ret => 'void',
    args => [
      [ 'source', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      ro => [ 'ro', 'bool', 0 ],
      qgroupid => [ 'qgroupid', 'string', 1 ],
    },
    name => "btrfs_subvolume_snapshot",
    description => "create a btrfs snapshot",
  },
  "btrfstune_enable_extended_inode_refs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "btrfstune_enable_extended_inode_refs",
    description => "enable extended inode refs",
  },
  "btrfstune_enable_skinny_metadata_extent_refs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "btrfstune_enable_skinny_metadata_extent_refs",
    description => "enable skinny metadata extent refs",
  },
  "btrfstune_seeding" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'seeding', 'bool', 1 ],
    ],
    name => "btrfstune_seeding",
    description => "enable or disable seeding of a btrfs device",
  },
  "c_pointer" => {
    ret => 'int64',
    args => [
    ],
    name => "c_pointer",
    description => "return the C pointer to the guestfs_h handle",
  },
  "canonical_device_name" => {
    ret => 'string',
    args => [
      [ 'device', 'string', 0 ],
    ],
    name => "canonical_device_name",
    description => "return canonical device name",
  },
  "cap_get_file" => {
    ret => 'string',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "cap_get_file",
    description => "get the Linux capabilities attached to a file",
  },
  "cap_set_file" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'cap', 'string', 1 ],
    ],
    name => "cap_set_file",
    description => "set the Linux capabilities attached to a file",
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
  "clear_backend_setting" => {
    ret => 'int',
    args => [
      [ 'name', 'string', 0 ],
    ],
    name => "clear_backend_setting",
    description => "remove a single per-backend settings string",
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
      [ 'hvparam', 'string', 0 ],
      [ 'hvvalue', 'nullable string', 1 ],
    ],
    name => "config",
    description => "add hypervisor parameters",
  },
  "copy_attributes" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      all => [ 'all', 'bool', 0 ],
      mode => [ 'mode', 'bool', 1 ],
      xattributes => [ 'xattributes', 'bool', 2 ],
      ownership => [ 'ownership', 'bool', 3 ],
    },
    name => "copy_attributes",
    description => "copy the attributes of a path (file/directory) to another",
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
      sparse => [ 'sparse', 'bool', 3 ],
      append => [ 'append', 'bool', 4 ],
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
      sparse => [ 'sparse', 'bool', 3 ],
      append => [ 'append', 'bool', 4 ],
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
      sparse => [ 'sparse', 'bool', 3 ],
      append => [ 'append', 'bool', 4 ],
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
      sparse => [ 'sparse', 'bool', 3 ],
      append => [ 'append', 'bool', 4 ],
    },
    name => "copy_file_to_file",
    description => "copy from source file to destination file",
  },
  "copy_in" => {
    ret => 'void',
    args => [
      [ 'localpath', 'string', 0 ],
      [ 'remotedir', 'string(path)', 1 ],
    ],
    name => "copy_in",
    description => "copy local files or directories into an image",
  },
  "copy_out" => {
    ret => 'void',
    args => [
      [ 'remotepath', 'string(path)', 0 ],
      [ 'localdir', 'string', 1 ],
    ],
    name => "copy_out",
    description => "copy remote files or directories out of an image",
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
  "cp_r" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    name => "cp_r",
    description => "copy a file or directory recursively",
  },
  "cpio_out" => {
    ret => 'void',
    args => [
      [ 'directory', 'string', 0 ],
      [ 'cpiofile', 'string(filename)', 1 ],
    ],
    optargs => {
      format => [ 'format', 'string', 0 ],
    },
    name => "cpio_out",
    description => "pack directory into cpio file",
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
  "device_index" => {
    ret => 'int',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "device_index",
    description => "convert device to index",
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
  "disk_create" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
      [ 'format', 'string', 1 ],
      [ 'size', 'int64', 2 ],
    ],
    optargs => {
      backingfile => [ 'backingfile', 'string', 0 ],
      backingformat => [ 'backingformat', 'string', 1 ],
      preallocation => [ 'preallocation', 'string', 2 ],
      compat => [ 'compat', 'string', 3 ],
      clustersize => [ 'clustersize', 'int', 4 ],
    },
    name => "disk_create",
    description => "create a blank disk image",
  },
  "disk_format" => {
    ret => 'string',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "disk_format",
    description => "detect the disk format of a disk image",
  },
  "disk_has_backing_file" => {
    ret => 'bool',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "disk_has_backing_file",
    description => "return whether disk has a backing file",
  },
  "disk_virtual_size" => {
    ret => 'int64',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "disk_virtual_size",
    description => "return virtual size of a disk",
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
  "extlinux" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "extlinux",
    description => "install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem",
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
  "feature_available" => {
    ret => 'bool',
    args => [
      [ 'groups', 'string list', 0 ],
    ],
    name => "feature_available",
    description => "test availability of some parts of the API",
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
  "filesystem_available" => {
    ret => 'bool',
    args => [
      [ 'filesystem', 'string', 0 ],
    ],
    name => "filesystem_available",
    description => "check if filesystem is available",
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
  "fill_dir" => {
    ret => 'void',
    args => [
      [ 'dir', 'string(path)', 0 ],
      [ 'nr', 'int', 1 ],
    ],
    name => "fill_dir",
    description => "fill a directory with empty files",
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
  "fstrim" => {
    ret => 'void',
    args => [
      [ 'mountpoint', 'string(path)', 0 ],
    ],
    optargs => {
      offset => [ 'offset', 'int64', 0 ],
      length => [ 'length', 'int64', 1 ],
      minimumfreeextent => [ 'minimumfreeextent', 'int64', 2 ],
    },
    name => "fstrim",
    description => "trim free space in a filesystem",
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
    description => "get the backend",
  },
  "get_autosync" => {
    ret => 'bool',
    args => [
    ],
    name => "get_autosync",
    description => "get autosync mode",
  },
  "get_backend" => {
    ret => 'string',
    args => [
    ],
    name => "get_backend",
    description => "get the backend",
  },
  "get_backend_setting" => {
    ret => 'string',
    args => [
      [ 'name', 'string', 0 ],
    ],
    name => "get_backend_setting",
    description => "get a single per-backend settings string",
  },
  "get_backend_settings" => {
    ret => 'string list',
    args => [
    ],
    name => "get_backend_settings",
    description => "get per-backend settings",
  },
  "get_cachedir" => {
    ret => 'string',
    args => [
    ],
    name => "get_cachedir",
    description => "get the appliance cache directory",
  },
  "get_direct" => {
    ret => 'bool',
    args => [
    ],
    name => "get_direct",
    description => "get direct appliance mode flag",
  },
  "get_e2attrs" => {
    ret => 'string',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "get_e2attrs",
    description => "get ext2 file attributes of a file",
  },
  "get_e2generation" => {
    ret => 'int64',
    args => [
      [ 'file', 'string(path)', 0 ],
    ],
    name => "get_e2generation",
    description => "get ext2 file generation of a file",
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
  "get_hv" => {
    ret => 'string',
    args => [
    ],
    name => "get_hv",
    description => "get the hypervisor binary",
  },
  "get_libvirt_requested_credential_challenge" => {
    ret => 'string',
    args => [
      [ 'index', 'int', 0 ],
    ],
    name => "get_libvirt_requested_credential_challenge",
    description => "challenge of i'th requested credential",
  },
  "get_libvirt_requested_credential_defresult" => {
    ret => 'string',
    args => [
      [ 'index', 'int', 0 ],
    ],
    name => "get_libvirt_requested_credential_defresult",
    description => "default result of i'th requested credential",
  },
  "get_libvirt_requested_credential_prompt" => {
    ret => 'string',
    args => [
      [ 'index', 'int', 0 ],
    ],
    name => "get_libvirt_requested_credential_prompt",
    description => "prompt of i'th requested credential",
  },
  "get_libvirt_requested_credentials" => {
    ret => 'string list',
    args => [
    ],
    name => "get_libvirt_requested_credentials",
    description => "get list of credentials requested by libvirt",
  },
  "get_memsize" => {
    ret => 'int',
    args => [
    ],
    name => "get_memsize",
    description => "get memory allocated to the hypervisor",
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
    description => "get PID of hypervisor",
  },
  "get_program" => {
    ret => 'const string',
    args => [
    ],
    name => "get_program",
    description => "get the program name",
  },
  "get_qemu" => {
    ret => 'const string',
    args => [
    ],
    name => "get_qemu",
    description => "get the hypervisor binary (usually qemu)",
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
  "get_tmpdir" => {
    ret => 'string',
    args => [
    ],
    name => "get_tmpdir",
    description => "get the temporary directory",
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
    optargs => {
      extended => [ 'extended', 'bool', 0 ],
      fixed => [ 'fixed', 'bool', 1 ],
      insensitive => [ 'insensitive', 'bool', 2 ],
      compressed => [ 'compressed', 'bool', 3 ],
    },
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
  "hivex_close" => {
    ret => 'void',
    args => [
    ],
    name => "hivex_close",
    description => "close the current hivex handle",
  },
  "hivex_commit" => {
    ret => 'void',
    args => [
      [ 'filename', 'nullable string', 0 ],
    ],
    name => "hivex_commit",
    description => "commit (write) changes back to the hive",
  },
  "hivex_node_add_child" => {
    ret => 'int64',
    args => [
      [ 'parent', 'int64', 0 ],
      [ 'name', 'string', 1 ],
    ],
    name => "hivex_node_add_child",
    description => "add a child node",
  },
  "hivex_node_children" => {
    ret => 'struct hivex_node list',
    args => [
      [ 'nodeh', 'int64', 0 ],
    ],
    name => "hivex_node_children",
    description => "return list of nodes which are subkeys of node",
  },
  "hivex_node_delete_child" => {
    ret => 'void',
    args => [
      [ 'nodeh', 'int64', 0 ],
    ],
    name => "hivex_node_delete_child",
    description => "delete a node (recursively)",
  },
  "hivex_node_get_child" => {
    ret => 'int64',
    args => [
      [ 'nodeh', 'int64', 0 ],
      [ 'name', 'string', 1 ],
    ],
    name => "hivex_node_get_child",
    description => "return the named child of node",
  },
  "hivex_node_get_value" => {
    ret => 'int64',
    args => [
      [ 'nodeh', 'int64', 0 ],
      [ 'key', 'string', 1 ],
    ],
    name => "hivex_node_get_value",
    description => "return the named value",
  },
  "hivex_node_name" => {
    ret => 'string',
    args => [
      [ 'nodeh', 'int64', 0 ],
    ],
    name => "hivex_node_name",
    description => "return the name of the node",
  },
  "hivex_node_parent" => {
    ret => 'int64',
    args => [
      [ 'nodeh', 'int64', 0 ],
    ],
    name => "hivex_node_parent",
    description => "return the parent of node",
  },
  "hivex_node_set_value" => {
    ret => 'void',
    args => [
      [ 'nodeh', 'int64', 0 ],
      [ 'key', 'string', 1 ],
      [ 't', 'int64', 2 ],
      [ 'val', 'buffer', 3 ],
    ],
    name => "hivex_node_set_value",
    description => "set or replace a single value in a node",
  },
  "hivex_node_values" => {
    ret => 'struct hivex_value list',
    args => [
      [ 'nodeh', 'int64', 0 ],
    ],
    name => "hivex_node_values",
    description => "return list of values attached to node",
  },
  "hivex_open" => {
    ret => 'void',
    args => [
      [ 'filename', 'string(path)', 0 ],
    ],
    optargs => {
      verbose => [ 'verbose', 'bool', 0 ],
      debug => [ 'debug', 'bool', 1 ],
      write => [ 'write', 'bool', 2 ],
    },
    name => "hivex_open",
    description => "open a Windows Registry hive file",
  },
  "hivex_root" => {
    ret => 'int64',
    args => [
    ],
    name => "hivex_root",
    description => "return the root node of the hive",
  },
  "hivex_value_key" => {
    ret => 'string',
    args => [
      [ 'valueh', 'int64', 0 ],
    ],
    name => "hivex_value_key",
    description => "return the key field from the (key, datatype, data) tuple",
  },
  "hivex_value_type" => {
    ret => 'int64',
    args => [
      [ 'valueh', 'int64', 0 ],
    ],
    name => "hivex_value_type",
    description => "return the data type from the (key, datatype, data) tuple",
  },
  "hivex_value_utf8" => {
    ret => 'string',
    args => [
      [ 'valueh', 'int64', 0 ],
    ],
    name => "hivex_value_utf8",
    description => "return the data field from the (key, datatype, data) tuple",
  },
  "hivex_value_value" => {
    ret => 'buffer',
    args => [
      [ 'valueh', 'int64', 0 ],
    ],
    name => "hivex_value_value",
    description => "return the data field from the (key, datatype, data) tuple",
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
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_arch",
    description => "get architecture of inspected operating system",
  },
  "inspect_get_distro" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_distro",
    description => "get distro of inspected operating system",
  },
  "inspect_get_drive_mappings" => {
    ret => 'hash',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_drive_mappings",
    description => "get drive letter mappings",
  },
  "inspect_get_filesystems" => {
    ret => 'string list',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_filesystems",
    description => "get filesystems associated with inspected operating system",
  },
  "inspect_get_format" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_format",
    description => "get format of inspected operating system",
  },
  "inspect_get_hostname" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_hostname",
    description => "get hostname of the operating system",
  },
  "inspect_get_icon" => {
    ret => 'buffer',
    args => [
      [ 'root', 'string(mountable)', 0 ],
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
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_major_version",
    description => "get major version of inspected operating system",
  },
  "inspect_get_minor_version" => {
    ret => 'int',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_minor_version",
    description => "get minor version of inspected operating system",
  },
  "inspect_get_mountpoints" => {
    ret => 'hash',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_mountpoints",
    description => "get mountpoints of inspected operating system",
  },
  "inspect_get_package_format" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_package_format",
    description => "get package format used by the operating system",
  },
  "inspect_get_package_management" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_package_management",
    description => "get package management tool used by the operating system",
  },
  "inspect_get_product_name" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_product_name",
    description => "get product name of inspected operating system",
  },
  "inspect_get_product_variant" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
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
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_type",
    description => "get type of inspected operating system",
  },
  "inspect_get_windows_current_control_set" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_windows_current_control_set",
    description => "get Windows CurrentControlSet of inspected operating system",
  },
  "inspect_get_windows_systemroot" => {
    ret => 'string',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_get_windows_systemroot",
    description => "get Windows systemroot of inspected operating system",
  },
  "inspect_is_live" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_is_live",
    description => "get live flag for install disk",
  },
  "inspect_is_multipart" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_is_multipart",
    description => "get multipart flag for install disk",
  },
  "inspect_is_netinst" => {
    ret => 'bool',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_is_netinst",
    description => "get netinst (network installer) flag for install disk",
  },
  "inspect_list_applications" => {
    ret => 'struct application list',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_list_applications",
    description => "get list of applications installed in the operating system",
  },
  "inspect_list_applications2" => {
    ret => 'struct application2 list',
    args => [
      [ 'root', 'string(mountable)', 0 ],
    ],
    name => "inspect_list_applications2",
    description => "get list of applications installed in the operating system",
  },
  "inspect_os" => {
    ret => 'string list',
    args => [
    ],
    name => "inspect_os",
    description => "inspect disk and return list of operating systems found",
  },
  "internal_exit" => {
    ret => 'void',
    args => [
    ],
    name => "internal_exit",
    description => "cause the daemon to exit (internal use only)",
  },
  "internal_test" => {
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
      ostringlist => [ 'ostringlist', 'string list', 4 ],
    },
    name => "internal_test",
    description => "internal test function - do not use",
  },
  "internal_test_63_optargs" => {
    ret => 'void',
    args => [
    ],
    optargs => {
      opt1 => [ 'opt1', 'int', 0 ],
      opt2 => [ 'opt2', 'int', 1 ],
      opt3 => [ 'opt3', 'int', 2 ],
      opt4 => [ 'opt4', 'int', 3 ],
      opt5 => [ 'opt5', 'int', 4 ],
      opt6 => [ 'opt6', 'int', 5 ],
      opt7 => [ 'opt7', 'int', 6 ],
      opt8 => [ 'opt8', 'int', 7 ],
      opt9 => [ 'opt9', 'int', 8 ],
      opt10 => [ 'opt10', 'int', 9 ],
      opt11 => [ 'opt11', 'int', 10 ],
      opt12 => [ 'opt12', 'int', 11 ],
      opt13 => [ 'opt13', 'int', 12 ],
      opt14 => [ 'opt14', 'int', 13 ],
      opt15 => [ 'opt15', 'int', 14 ],
      opt16 => [ 'opt16', 'int', 15 ],
      opt17 => [ 'opt17', 'int', 16 ],
      opt18 => [ 'opt18', 'int', 17 ],
      opt19 => [ 'opt19', 'int', 18 ],
      opt20 => [ 'opt20', 'int', 19 ],
      opt21 => [ 'opt21', 'int', 20 ],
      opt22 => [ 'opt22', 'int', 21 ],
      opt23 => [ 'opt23', 'int', 22 ],
      opt24 => [ 'opt24', 'int', 23 ],
      opt25 => [ 'opt25', 'int', 24 ],
      opt26 => [ 'opt26', 'int', 25 ],
      opt27 => [ 'opt27', 'int', 26 ],
      opt28 => [ 'opt28', 'int', 27 ],
      opt29 => [ 'opt29', 'int', 28 ],
      opt30 => [ 'opt30', 'int', 29 ],
      opt31 => [ 'opt31', 'int', 30 ],
      opt32 => [ 'opt32', 'int', 31 ],
      opt33 => [ 'opt33', 'int', 32 ],
      opt34 => [ 'opt34', 'int', 33 ],
      opt35 => [ 'opt35', 'int', 34 ],
      opt36 => [ 'opt36', 'int', 35 ],
      opt37 => [ 'opt37', 'int', 36 ],
      opt38 => [ 'opt38', 'int', 37 ],
      opt39 => [ 'opt39', 'int', 38 ],
      opt40 => [ 'opt40', 'int', 39 ],
      opt41 => [ 'opt41', 'int', 40 ],
      opt42 => [ 'opt42', 'int', 41 ],
      opt43 => [ 'opt43', 'int', 42 ],
      opt44 => [ 'opt44', 'int', 43 ],
      opt45 => [ 'opt45', 'int', 44 ],
      opt46 => [ 'opt46', 'int', 45 ],
      opt47 => [ 'opt47', 'int', 46 ],
      opt48 => [ 'opt48', 'int', 47 ],
      opt49 => [ 'opt49', 'int', 48 ],
      opt50 => [ 'opt50', 'int', 49 ],
      opt51 => [ 'opt51', 'int', 50 ],
      opt52 => [ 'opt52', 'int', 51 ],
      opt53 => [ 'opt53', 'int', 52 ],
      opt54 => [ 'opt54', 'int', 53 ],
      opt55 => [ 'opt55', 'int', 54 ],
      opt56 => [ 'opt56', 'int', 55 ],
      opt57 => [ 'opt57', 'int', 56 ],
      opt58 => [ 'opt58', 'int', 57 ],
      opt59 => [ 'opt59', 'int', 58 ],
      opt60 => [ 'opt60', 'int', 59 ],
      opt61 => [ 'opt61', 'int', 60 ],
      opt62 => [ 'opt62', 'int', 61 ],
      opt63 => [ 'opt63', 'int', 62 ],
    },
    name => "internal_test_63_optargs",
    description => "internal test function - do not use",
  },
  "internal_test_close_output" => {
    ret => 'void',
    args => [
    ],
    name => "internal_test_close_output",
    description => "internal test function - do not use",
  },
  "internal_test_only_optargs" => {
    ret => 'void',
    args => [
    ],
    optargs => {
      test => [ 'test', 'int', 0 ],
    },
    name => "internal_test_only_optargs",
    description => "internal test function - do not use",
  },
  "internal_test_rbool" => {
    ret => 'bool',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rbool",
    description => "internal test function - do not use",
  },
  "internal_test_rboolerr" => {
    ret => 'bool',
    args => [
    ],
    name => "internal_test_rboolerr",
    description => "internal test function - do not use",
  },
  "internal_test_rbufferout" => {
    ret => 'buffer',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rbufferout",
    description => "internal test function - do not use",
  },
  "internal_test_rbufferouterr" => {
    ret => 'buffer',
    args => [
    ],
    name => "internal_test_rbufferouterr",
    description => "internal test function - do not use",
  },
  "internal_test_rconstoptstring" => {
    ret => 'const nullable string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rconstoptstring",
    description => "internal test function - do not use",
  },
  "internal_test_rconstoptstringerr" => {
    ret => 'const nullable string',
    args => [
    ],
    name => "internal_test_rconstoptstringerr",
    description => "internal test function - do not use",
  },
  "internal_test_rconststring" => {
    ret => 'const string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rconststring",
    description => "internal test function - do not use",
  },
  "internal_test_rconststringerr" => {
    ret => 'const string',
    args => [
    ],
    name => "internal_test_rconststringerr",
    description => "internal test function - do not use",
  },
  "internal_test_rhashtable" => {
    ret => 'hash',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rhashtable",
    description => "internal test function - do not use",
  },
  "internal_test_rhashtableerr" => {
    ret => 'hash',
    args => [
    ],
    name => "internal_test_rhashtableerr",
    description => "internal test function - do not use",
  },
  "internal_test_rint" => {
    ret => 'int',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rint",
    description => "internal test function - do not use",
  },
  "internal_test_rint64" => {
    ret => 'int64',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rint64",
    description => "internal test function - do not use",
  },
  "internal_test_rint64err" => {
    ret => 'int64',
    args => [
    ],
    name => "internal_test_rint64err",
    description => "internal test function - do not use",
  },
  "internal_test_rinterr" => {
    ret => 'int',
    args => [
    ],
    name => "internal_test_rinterr",
    description => "internal test function - do not use",
  },
  "internal_test_rstring" => {
    ret => 'string',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rstring",
    description => "internal test function - do not use",
  },
  "internal_test_rstringerr" => {
    ret => 'string',
    args => [
    ],
    name => "internal_test_rstringerr",
    description => "internal test function - do not use",
  },
  "internal_test_rstringlist" => {
    ret => 'string list',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rstringlist",
    description => "internal test function - do not use",
  },
  "internal_test_rstringlisterr" => {
    ret => 'string list',
    args => [
    ],
    name => "internal_test_rstringlisterr",
    description => "internal test function - do not use",
  },
  "internal_test_rstruct" => {
    ret => 'struct lvm_pv',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rstruct",
    description => "internal test function - do not use",
  },
  "internal_test_rstructerr" => {
    ret => 'struct lvm_pv',
    args => [
    ],
    name => "internal_test_rstructerr",
    description => "internal test function - do not use",
  },
  "internal_test_rstructlist" => {
    ret => 'struct lvm_pv list',
    args => [
      [ 'val', 'string', 0 ],
    ],
    name => "internal_test_rstructlist",
    description => "internal test function - do not use",
  },
  "internal_test_rstructlisterr" => {
    ret => 'struct lvm_pv list',
    args => [
    ],
    name => "internal_test_rstructlisterr",
    description => "internal test function - do not use",
  },
  "internal_test_set_output" => {
    ret => 'void',
    args => [
      [ 'filename', 'string', 0 ],
    ],
    name => "internal_test_set_output",
    description => "internal test function - do not use",
  },
  "is_blockdev" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
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
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
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
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
    name => "is_dir",
    description => "test if a directory",
  },
  "is_fifo" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
    name => "is_fifo",
    description => "test if FIFO (named pipe)",
  },
  "is_file" => {
    ret => 'bool',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
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
    optargs => {
      followsymlinks => [ 'followsymlinks', 'bool', 0 ],
    },
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
  "is_whole_device" => {
    ret => 'bool',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "is_whole_device",
    description => "test if a device is a whole device",
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
  "isoinfo" => {
    ret => 'struct isoinfo',
    args => [
      [ 'isofile', 'string(path)', 0 ],
    ],
    name => "isoinfo",
    description => "get ISO information from primary volume descriptor of ISO file",
  },
  "isoinfo_device" => {
    ret => 'struct isoinfo',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "isoinfo_device",
    description => "get ISO information from primary volume descriptor of device",
  },
  "journal_close" => {
    ret => 'void',
    args => [
    ],
    name => "journal_close",
    description => "close the systemd journal",
  },
  "journal_get" => {
    ret => 'struct xattr list',
    args => [
    ],
    name => "journal_get",
    description => "read the current journal entry",
  },
  "journal_get_data_threshold" => {
    ret => 'int64',
    args => [
    ],
    name => "journal_get_data_threshold",
    description => "get the data threshold for reading journal entries",
  },
  "journal_get_realtime_usec" => {
    ret => 'int64',
    args => [
    ],
    name => "journal_get_realtime_usec",
    description => "get the timestamp of the current journal entry",
  },
  "journal_next" => {
    ret => 'bool',
    args => [
    ],
    name => "journal_next",
    description => "move to the next journal entry",
  },
  "journal_open" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "journal_open",
    description => "open the systemd journal",
  },
  "journal_set_data_threshold" => {
    ret => 'void',
    args => [
      [ 'threshold', 'int64', 0 ],
    ],
    name => "journal_set_data_threshold",
    description => "set the data threshold for reading journal entries",
  },
  "journal_skip" => {
    ret => 'int64',
    args => [
      [ 'skip', 'int64', 0 ],
    ],
    name => "journal_skip",
    description => "skip forwards or backwards in the journal",
  },
  "kill_subprocess" => {
    ret => 'void',
    args => [
    ],
    name => "kill_subprocess",
    description => "kill the hypervisor",
  },
  "launch" => {
    ret => 'void',
    args => [
    ],
    name => "launch",
    description => "launch the backend",
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
  "ldmtool_create_all" => {
    ret => 'void',
    args => [
    ],
    name => "ldmtool_create_all",
    description => "scan and create Windows dynamic disk volumes",
  },
  "ldmtool_diskgroup_disks" => {
    ret => 'string list',
    args => [
      [ 'diskgroup', 'string', 0 ],
    ],
    name => "ldmtool_diskgroup_disks",
    description => "return the disks in a Windows dynamic disk group",
  },
  "ldmtool_diskgroup_name" => {
    ret => 'string',
    args => [
      [ 'diskgroup', 'string', 0 ],
    ],
    name => "ldmtool_diskgroup_name",
    description => "return the name of a Windows dynamic disk group",
  },
  "ldmtool_diskgroup_volumes" => {
    ret => 'string list',
    args => [
      [ 'diskgroup', 'string', 0 ],
    ],
    name => "ldmtool_diskgroup_volumes",
    description => "return the volumes in a Windows dynamic disk group",
  },
  "ldmtool_remove_all" => {
    ret => 'void',
    args => [
    ],
    name => "ldmtool_remove_all",
    description => "remove all Windows dynamic disk volumes",
  },
  "ldmtool_scan" => {
    ret => 'string list',
    args => [
    ],
    name => "ldmtool_scan",
    description => "scan for Windows dynamic disks",
  },
  "ldmtool_scan_devices" => {
    ret => 'string list',
    args => [
      [ 'devices', 'string(device) list', 0 ],
    ],
    name => "ldmtool_scan_devices",
    description => "scan for Windows dynamic disks",
  },
  "ldmtool_volume_hint" => {
    ret => 'string',
    args => [
      [ 'diskgroup', 'string', 0 ],
      [ 'volume', 'string', 1 ],
    ],
    name => "ldmtool_volume_hint",
    description => "return the hint field of a Windows dynamic disk volume",
  },
  "ldmtool_volume_partitions" => {
    ret => 'string list',
    args => [
      [ 'diskgroup', 'string', 0 ],
      [ 'volume', 'string', 1 ],
    ],
    name => "ldmtool_volume_partitions",
    description => "return the partitions in a Windows dynamic disk volume",
  },
  "ldmtool_volume_type" => {
    ret => 'string',
    args => [
      [ 'diskgroup', 'string', 0 ],
      [ 'volume', 'string', 1 ],
    ],
    name => "ldmtool_volume_type",
    description => "return the type of a Windows dynamic disk volume",
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
  "list_disk_labels" => {
    ret => 'hash',
    args => [
    ],
    name => "list_disk_labels",
    description => "mapping of disk labels to devices",
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
  "list_ldm_partitions" => {
    ret => 'string list',
    args => [
    ],
    name => "list_ldm_partitions",
    description => "list all Windows dynamic disk partitions",
  },
  "list_ldm_volumes" => {
    ret => 'string list',
    args => [
    ],
    name => "list_ldm_volumes",
    description => "list all Windows dynamic disk volumes",
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
  "llz" => {
    ret => 'string',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "llz",
    description => "list the files in a directory (long format with SELinux contexts)",
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
  "ls0" => {
    ret => 'void',
    args => [
      [ 'dir', 'string(path)', 0 ],
      [ 'filenames', 'string(filename)', 1 ],
    ],
    name => "ls0",
    description => "get list of files in a directory",
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
  "lstatns" => {
    ret => 'struct statns',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "lstatns",
    description => "get file information for a symbolic link",
  },
  "lstatnslist" => {
    ret => 'struct statns list',
    args => [
      [ 'path', 'string(path)', 0 ],
      [ 'names', 'string list', 1 ],
    ],
    name => "lstatnslist",
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
  "lvcreate_free" => {
    ret => 'void',
    args => [
      [ 'logvol', 'string', 0 ],
      [ 'volgroup', 'string', 1 ],
      [ 'percent', 'int', 2 ],
    ],
    name => "lvcreate_free",
    description => "create an LVM logical volume in % remaining free space",
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
  "max_disks" => {
    ret => 'int',
    args => [
    ],
    name => "max_disks",
    description => "maximum number of disks that may be added",
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
  "md_stat" => {
    ret => 'struct mdstat list',
    args => [
      [ 'md', 'string(device)', 0 ],
    ],
    name => "md_stat",
    description => "get underlying devices from an MD device",
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
  "mke2fs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      blockscount => [ 'blockscount', 'int64', 0 ],
      blocksize => [ 'blocksize', 'int64', 1 ],
      fragsize => [ 'fragsize', 'int64', 2 ],
      blockspergroup => [ 'blockspergroup', 'int64', 3 ],
      numberofgroups => [ 'numberofgroups', 'int64', 4 ],
      bytesperinode => [ 'bytesperinode', 'int64', 5 ],
      inodesize => [ 'inodesize', 'int64', 6 ],
      journalsize => [ 'journalsize', 'int64', 7 ],
      numberofinodes => [ 'numberofinodes', 'int64', 8 ],
      stridesize => [ 'stridesize', 'int64', 9 ],
      stripewidth => [ 'stripewidth', 'int64', 10 ],
      maxonlineresize => [ 'maxonlineresize', 'int64', 11 ],
      reservedblockspercentage => [ 'reservedblockspercentage', 'int', 12 ],
      mmpupdateinterval => [ 'mmpupdateinterval', 'int', 13 ],
      journaldevice => [ 'journaldevice', 'string', 14 ],
      label => [ 'label', 'string', 15 ],
      lastmounteddir => [ 'lastmounteddir', 'string', 16 ],
      creatoros => [ 'creatoros', 'string', 17 ],
      fstype => [ 'fstype', 'string', 18 ],
      usagetype => [ 'usagetype', 'string', 19 ],
      uuid => [ 'uuid', 'string', 20 ],
      forcecreate => [ 'forcecreate', 'bool', 21 ],
      writesbandgrouponly => [ 'writesbandgrouponly', 'bool', 22 ],
      lazyitableinit => [ 'lazyitableinit', 'bool', 23 ],
      lazyjournalinit => [ 'lazyjournalinit', 'bool', 24 ],
      testfs => [ 'testfs', 'bool', 25 ],
      discard => [ 'discard', 'bool', 26 ],
      quotatype => [ 'quotatype', 'bool', 27 ],
      extent => [ 'extent', 'bool', 28 ],
      filetype => [ 'filetype', 'bool', 29 ],
      flexbg => [ 'flexbg', 'bool', 30 ],
      hasjournal => [ 'hasjournal', 'bool', 31 ],
      journaldev => [ 'journaldev', 'bool', 32 ],
      largefile => [ 'largefile', 'bool', 33 ],
      quota => [ 'quota', 'bool', 34 ],
      resizeinode => [ 'resizeinode', 'bool', 35 ],
      sparsesuper => [ 'sparsesuper', 'bool', 36 ],
      uninitbg => [ 'uninitbg', 'bool', 37 ],
    },
    name => "mke2fs",
    description => "create an ext2/ext3/ext4 filesystem on device",
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
    optargs => {
      blocksize => [ 'blocksize', 'int', 0 ],
      features => [ 'features', 'string', 1 ],
      inode => [ 'inode', 'int', 2 ],
      sectorsize => [ 'sectorsize', 'int', 3 ],
      label => [ 'label', 'string', 4 ],
    },
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
  "mkfs_btrfs" => {
    ret => 'void',
    args => [
      [ 'devices', 'string(device) list', 0 ],
    ],
    optargs => {
      allocstart => [ 'allocstart', 'int64', 0 ],
      bytecount => [ 'bytecount', 'int64', 1 ],
      datatype => [ 'datatype', 'string', 2 ],
      leafsize => [ 'leafsize', 'int', 3 ],
      label => [ 'label', 'string', 4 ],
      metadata => [ 'metadata', 'string', 5 ],
      nodesize => [ 'nodesize', 'int', 6 ],
      sectorsize => [ 'sectorsize', 'int', 7 ],
    },
    name => "mkfs_btrfs",
    description => "create a btrfs filesystem",
  },
  "mklost_and_found" => {
    ret => 'void',
    args => [
      [ 'mountpoint', 'string(path)', 0 ],
    ],
    name => "mklost_and_found",
    description => "make lost+found directory on an ext2/3/4 filesystem",
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
    optargs => {
      label => [ 'label', 'string', 0 ],
      uuid => [ 'uuid', 'string', 1 ],
    },
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
  "mktemp" => {
    ret => 'string',
    args => [
      [ 'tmpl', 'string(path)', 0 ],
    ],
    optargs => {
      suffix => [ 'suffix', 'string', 0 ],
    },
    name => "mktemp",
    description => "create a temporary file",
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
      [ 'mountable', 'string(mountable)', 0 ],
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
  "mount_local" => {
    ret => 'void',
    args => [
      [ 'localmountpoint', 'string', 0 ],
    ],
    optargs => {
      readonly => [ 'readonly', 'bool', 0 ],
      options => [ 'options', 'string', 1 ],
      cachetimeout => [ 'cachetimeout', 'int', 2 ],
      debugcalls => [ 'debugcalls', 'bool', 3 ],
    },
    name => "mount_local",
    description => "mount on the local filesystem",
  },
  "mount_local_run" => {
    ret => 'void',
    args => [
    ],
    name => "mount_local_run",
    description => "run main loop of mount on the local filesystem",
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
      [ 'mountable', 'string(mountable)', 1 ],
      [ 'mountpoint', 'string', 2 ],
    ],
    name => "mount_options",
    description => "mount a guest disk with mount options",
  },
  "mount_ro" => {
    ret => 'void',
    args => [
      [ 'mountable', 'string(mountable)', 0 ],
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
      [ 'mountable', 'string(mountable)', 2 ],
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
  "nr_devices" => {
    ret => 'int',
    args => [
    ],
    name => "nr_devices",
    description => "return number of whole block devices (disks) added",
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
  "ntfsclone_in" => {
    ret => 'void',
    args => [
      [ 'backupfile', 'string(filename)', 0 ],
      [ 'device', 'string(device)', 1 ],
    ],
    name => "ntfsclone_in",
    description => "restore NTFS from backup file",
  },
  "ntfsclone_out" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'backupfile', 'string(filename)', 1 ],
    ],
    optargs => {
      metadataonly => [ 'metadataonly', 'bool', 0 ],
      rescue => [ 'rescue', 'bool', 1 ],
      ignorefscheck => [ 'ignorefscheck', 'bool', 2 ],
      preservetimestamps => [ 'preservetimestamps', 'bool', 3 ],
      force => [ 'force', 'bool', 4 ],
    },
    name => "ntfsclone_out",
    description => "save NTFS to backup file",
  },
  "ntfsfix" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      clearbadsectors => [ 'clearbadsectors', 'bool', 0 ],
    },
    name => "ntfsfix",
    description => "fix common errors and force Windows to check NTFS",
  },
  "ntfsresize" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      size => [ 'size', 'int64', 0 ],
      force => [ 'force', 'bool', 1 ],
    },
    name => "ntfsresize",
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
  "parse_environment" => {
    ret => 'void',
    args => [
    ],
    name => "parse_environment",
    description => "parse the environment and set handle flags accordingly",
  },
  "parse_environment_list" => {
    ret => 'void',
    args => [
      [ 'environment', 'string list', 0 ],
    ],
    name => "parse_environment_list",
    description => "parse the environment and set handle flags accordingly",
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
  "part_get_gpt_guid" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_gpt_guid",
    description => "get the GUID of a GPT partition",
  },
  "part_get_gpt_type" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_gpt_type",
    description => "get the type GUID of a GPT partition",
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
  "part_get_mbr_part_type" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_mbr_part_type",
    description => "get the MBR partition type",
  },
  "part_get_name" => {
    ret => 'string',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
    ],
    name => "part_get_name",
    description => "get partition name",
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
  "part_set_gpt_guid" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'guid', 'string', 2 ],
    ],
    name => "part_set_gpt_guid",
    description => "set the GUID of a GPT partition",
  },
  "part_set_gpt_type" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'partnum', 'int', 1 ],
      [ 'guid', 'string', 2 ],
    ],
    name => "part_set_gpt_type",
    description => "set the type GUID of a GPT partition",
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
  "pvchange_uuid" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "pvchange_uuid",
    description => "generate a new random UUID for a physical volume",
  },
  "pvchange_uuid_all" => {
    ret => 'void',
    args => [
    ],
    name => "pvchange_uuid_all",
    description => "generate new random UUIDs for all physical volumes",
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
  "remount" => {
    ret => 'void',
    args => [
      [ 'mountpoint', 'string(path)', 0 ],
    ],
    optargs => {
      rw => [ 'rw', 'bool', 0 ],
    },
    name => "remount",
    description => "remount a filesystem with different options",
  },
  "remove_drive" => {
    ret => 'void',
    args => [
      [ 'label', 'string', 0 ],
    ],
    name => "remove_drive",
    description => "remove a disk image",
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
  "rename" => {
    ret => 'void',
    args => [
      [ 'oldpath', 'string(path)', 0 ],
      [ 'newpath', 'string(path)', 1 ],
    ],
    name => "rename",
    description => "rename a file on the same filesystem",
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
  "rm_f" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "rm_f",
    description => "remove a file ignoring errors",
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
  "rsync" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      archive => [ 'archive', 'bool', 0 ],
      deletedest => [ 'deletedest', 'bool', 1 ],
    },
    name => "rsync",
    description => "synchronize the contents of two directories",
  },
  "rsync_in" => {
    ret => 'void',
    args => [
      [ 'remote', 'string', 0 ],
      [ 'dest', 'string(path)', 1 ],
    ],
    optargs => {
      archive => [ 'archive', 'bool', 0 ],
      deletedest => [ 'deletedest', 'bool', 1 ],
    },
    name => "rsync_in",
    description => "synchronize host or remote filesystem with filesystem",
  },
  "rsync_out" => {
    ret => 'void',
    args => [
      [ 'src', 'string(path)', 0 ],
      [ 'remote', 'string', 1 ],
    ],
    optargs => {
      archive => [ 'archive', 'bool', 0 ],
      deletedest => [ 'deletedest', 'bool', 1 ],
    },
    name => "rsync_out",
    description => "synchronize filesystem with host or remote filesystem",
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
      [ 'backend', 'string', 0 ],
    ],
    name => "set_attach_method",
    description => "set the backend",
  },
  "set_autosync" => {
    ret => 'void',
    args => [
      [ 'autosync', 'bool', 0 ],
    ],
    name => "set_autosync",
    description => "set autosync mode",
  },
  "set_backend" => {
    ret => 'void',
    args => [
      [ 'backend', 'string', 0 ],
    ],
    name => "set_backend",
    description => "set the backend",
  },
  "set_backend_setting" => {
    ret => 'void',
    args => [
      [ 'name', 'string', 0 ],
      [ 'val', 'string', 1 ],
    ],
    name => "set_backend_setting",
    description => "set a single per-backend settings string",
  },
  "set_backend_settings" => {
    ret => 'void',
    args => [
      [ 'settings', 'string list', 0 ],
    ],
    name => "set_backend_settings",
    description => "replace per-backend settings strings",
  },
  "set_cachedir" => {
    ret => 'void',
    args => [
      [ 'cachedir', 'nullable string', 0 ],
    ],
    name => "set_cachedir",
    description => "set the appliance cache directory",
  },
  "set_direct" => {
    ret => 'void',
    args => [
      [ 'direct', 'bool', 0 ],
    ],
    name => "set_direct",
    description => "enable or disable direct appliance mode",
  },
  "set_e2attrs" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
      [ 'attrs', 'string', 1 ],
    ],
    optargs => {
      clear => [ 'clear', 'bool', 0 ],
    },
    name => "set_e2attrs",
    description => "set ext2 file attributes of a file",
  },
  "set_e2generation" => {
    ret => 'void',
    args => [
      [ 'file', 'string(path)', 0 ],
      [ 'generation', 'int64', 1 ],
    ],
    name => "set_e2generation",
    description => "set ext2 file generation of a file",
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
  "set_hv" => {
    ret => 'void',
    args => [
      [ 'hv', 'string', 0 ],
    ],
    name => "set_hv",
    description => "set the hypervisor binary",
  },
  "set_label" => {
    ret => 'void',
    args => [
      [ 'mountable', 'string(mountable)', 0 ],
      [ 'label', 'string', 1 ],
    ],
    name => "set_label",
    description => "set filesystem label",
  },
  "set_libvirt_requested_credential" => {
    ret => 'void',
    args => [
      [ 'index', 'int', 0 ],
      [ 'cred', 'buffer', 1 ],
    ],
    name => "set_libvirt_requested_credential",
    description => "pass requested credential back to libvirt",
  },
  "set_libvirt_supported_credentials" => {
    ret => 'void',
    args => [
      [ 'creds', 'string list', 0 ],
    ],
    name => "set_libvirt_supported_credentials",
    description => "set libvirt credentials supported by calling program",
  },
  "set_memsize" => {
    ret => 'void',
    args => [
      [ 'memsize', 'int', 0 ],
    ],
    name => "set_memsize",
    description => "set memory allocated to the hypervisor",
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
  "set_program" => {
    ret => 'void',
    args => [
      [ 'program', 'string', 0 ],
    ],
    name => "set_program",
    description => "set the program name",
  },
  "set_qemu" => {
    ret => 'void',
    args => [
      [ 'hv', 'nullable string', 0 ],
    ],
    name => "set_qemu",
    description => "set the hypervisor binary (usually qemu)",
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
  "set_tmpdir" => {
    ret => 'void',
    args => [
      [ 'tmpdir', 'nullable string', 0 ],
    ],
    name => "set_tmpdir",
    description => "set the temporary directory",
  },
  "set_trace" => {
    ret => 'void',
    args => [
      [ 'trace', 'bool', 0 ],
    ],
    name => "set_trace",
    description => "enable or disable command traces",
  },
  "set_uuid" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
      [ 'uuid', 'string', 1 ],
    ],
    name => "set_uuid",
    description => "set the filesystem UUID",
  },
  "set_uuid_random" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "set_uuid_random",
    description => "set a random UUID for the filesystem",
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
  "shutdown" => {
    ret => 'void',
    args => [
    ],
    name => "shutdown",
    description => "shutdown the hypervisor",
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
  "statns" => {
    ret => 'struct statns',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    name => "statns",
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
  "syslinux" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      directory => [ 'directory', 'string', 0 ],
    },
    name => "syslinux",
    description => "install the SYSLINUX bootloader",
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
    optargs => {
      compress => [ 'compress', 'string', 0 ],
    },
    name => "tar_in",
    description => "unpack tarfile to directory",
  },
  "tar_out" => {
    ret => 'void',
    args => [
      [ 'directory', 'string', 0 ],
      [ 'tarfile', 'string(filename)', 1 ],
    ],
    optargs => {
      compress => [ 'compress', 'string', 0 ],
      numericowner => [ 'numericowner', 'bool', 1 ],
      excludes => [ 'excludes', 'string list', 2 ],
    },
    name => "tar_out",
    description => "pack directory into tarfile",
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
      [ 'pathordevice', 'string(dev_or_path)', 0 ],
    ],
    optargs => {
      force => [ 'force', 'bool', 0 ],
      lazyunmount => [ 'lazyunmount', 'bool', 1 ],
    },
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
  "umount_local" => {
    ret => 'void',
    args => [
    ],
    optargs => {
      retry => [ 'retry', 'bool', 0 ],
    },
    name => "umount_local",
    description => "unmount a locally mounted filesystem",
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
  "user_cancel" => {
    ret => 'void',
    args => [
    ],
    name => "user_cancel",
    description => "cancel the current upload or download operation",
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
  "utsname" => {
    ret => 'struct utsname',
    args => [
    ],
    name => "utsname",
    description => "appliance kernel version",
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
      [ 'mountable', 'string(mountable)', 0 ],
    ],
    name => "vfs_label",
    description => "get the filesystem label",
  },
  "vfs_type" => {
    ret => 'string',
    args => [
      [ 'mountable', 'string(mountable)', 0 ],
    ],
    name => "vfs_type",
    description => "get the Linux VFS type corresponding to a mounted device",
  },
  "vfs_uuid" => {
    ret => 'string',
    args => [
      [ 'mountable', 'string(mountable)', 0 ],
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
  "vgchange_uuid" => {
    ret => 'void',
    args => [
      [ 'vg', 'string', 0 ],
    ],
    name => "vgchange_uuid",
    description => "generate a new random UUID for a volume group",
  },
  "vgchange_uuid_all" => {
    ret => 'void',
    args => [
    ],
    name => "vgchange_uuid_all",
    description => "generate new random UUIDs for all volume groups",
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
  "vgmeta" => {
    ret => 'buffer',
    args => [
      [ 'vgname', 'string', 0 ],
    ],
    name => "vgmeta",
    description => "get volume group metadata",
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
    description => "wait until the hypervisor launches (no op)",
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
  "wipefs" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    name => "wipefs",
    description => "wipe a filesystem signature from a device",
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
  "xfs_admin" => {
    ret => 'void',
    args => [
      [ 'device', 'string(device)', 0 ],
    ],
    optargs => {
      extunwritten => [ 'extunwritten', 'bool', 0 ],
      imgfile => [ 'imgfile', 'bool', 1 ],
      v2log => [ 'v2log', 'bool', 2 ],
      projid32bit => [ 'projid32bit', 'bool', 3 ],
      lazycounter => [ 'lazycounter', 'bool', 4 ],
      label => [ 'label', 'string', 5 ],
      uuid => [ 'uuid', 'string', 6 ],
    },
    name => "xfs_admin",
    description => "change parameters of an XFS filesystem",
  },
  "xfs_growfs" => {
    ret => 'void',
    args => [
      [ 'path', 'string(path)', 0 ],
    ],
    optargs => {
      datasec => [ 'datasec', 'bool', 0 ],
      logsec => [ 'logsec', 'bool', 1 ],
      rtsec => [ 'rtsec', 'bool', 2 ],
      datasize => [ 'datasize', 'int64', 3 ],
      logsize => [ 'logsize', 'int64', 4 ],
      rtsize => [ 'rtsize', 'int64', 5 ],
      rtextsize => [ 'rtextsize', 'int64', 6 ],
      maxpct => [ 'maxpct', 'int', 7 ],
    },
    name => "xfs_growfs",
    description => "expand an existing XFS filesystem",
  },
  "xfs_info" => {
    ret => 'struct xfsinfo',
    args => [
      [ 'pathordevice', 'string(dev_or_path)', 0 ],
    ],
    name => "xfs_info",
    description => "get geometry of XFS filesystem",
  },
  "xfs_repair" => {
    ret => 'int',
    args => [
      [ 'device', 'string(dev_or_path)', 0 ],
    ],
    optargs => {
      forcelogzero => [ 'forcelogzero', 'bool', 0 ],
      nomodify => [ 'nomodify', 'bool', 1 ],
      noprefetch => [ 'noprefetch', 'bool', 2 ],
      forcegeometry => [ 'forcegeometry', 'bool', 3 ],
      maxmem => [ 'maxmem', 'int64', 4 ],
      ihashsize => [ 'ihashsize', 'int64', 5 ],
      bhashsize => [ 'bhashsize', 'int64', 6 ],
      agstride => [ 'agstride', 'int64', 7 ],
      logdev => [ 'logdev', 'string', 8 ],
      rtdev => [ 'rtdev', 'string', 9 ],
    },
    name => "xfs_repair",
    description => "repair an XFS filesystem",
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
  "zero_free_space" => {
    ret => 'void',
    args => [
      [ 'directory', 'string(path)', 0 ],
    ],
    name => "zero_free_space",
    description => "zero free space in a filesystem",
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

# Add aliases to the introspection hash.
my %ielem0 = %{$guestfs_introspection{add_drive}};
$guestfs_introspection{add_drive_opts} = \%ielem0;
my %ielem1 = %{$guestfs_introspection{btrfs_subvolume_create}};
$guestfs_introspection{btrfs_subvolume_create_opts} = \%ielem1;
my %ielem2 = %{$guestfs_introspection{btrfs_subvolume_snapshot}};
$guestfs_introspection{btrfs_subvolume_snapshot_opts} = \%ielem2;
my %ielem3 = %{$guestfs_introspection{grep}};
$guestfs_introspection{grep_opts} = \%ielem3;
my %ielem4 = %{$guestfs_introspection{is_blockdev}};
$guestfs_introspection{is_blockdev_opts} = \%ielem4;
my %ielem5 = %{$guestfs_introspection{is_chardev}};
$guestfs_introspection{is_chardev_opts} = \%ielem5;
my %ielem6 = %{$guestfs_introspection{is_dir}};
$guestfs_introspection{is_dir_opts} = \%ielem6;
my %ielem7 = %{$guestfs_introspection{is_fifo}};
$guestfs_introspection{is_fifo_opts} = \%ielem7;
my %ielem8 = %{$guestfs_introspection{is_file}};
$guestfs_introspection{is_file_opts} = \%ielem8;
my %ielem9 = %{$guestfs_introspection{is_socket}};
$guestfs_introspection{is_socket_opts} = \%ielem9;
my %ielem10 = %{$guestfs_introspection{mkfs}};
$guestfs_introspection{mkfs_opts} = \%ielem10;
my %ielem11 = %{$guestfs_introspection{mkswap}};
$guestfs_introspection{mkswap_opts} = \%ielem11;
my %ielem12 = %{$guestfs_introspection{ntfsresize}};
$guestfs_introspection{ntfsresize_opts} = \%ielem12;
my %ielem13 = %{$guestfs_introspection{tar_in}};
$guestfs_introspection{tar_in_opts} = \%ielem13;
my %ielem14 = %{$guestfs_introspection{tar_out}};
$guestfs_introspection{tar_out_opts} = \%ielem14;
my %ielem15 = %{$guestfs_introspection{umount}};
$guestfs_introspection{umount_opts} = \%ielem15;

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
   print "\$g->set_verbose is available\n";
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
 $Sys::Guestfs::guestfs_introspection{mkfs}
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
    name => "mkfs",
    description => "make a filesystem",
  }

To test if particular features are supported by the current
build, use the L</feature_available> method like the example below.  Note
that the appliance must be launched first.

 $g->feature_available ( ["augeas"] );

For further discussion on this topic, refer to
L<guestfs(3)/AVAILABILITY>.

=head1 STORING DATA IN THE HANDLE

The handle returned from L</new> is a hash reference.  The hash
normally contains some elements:

 {
   _g => [private data used by libguestfs],
   _flags => [flags provided when creating the handle]
 }

Callers can add other elements to this hash to store data for their own
purposes.  The data lasts for the lifetime of the handle.

Any fields whose names begin with an underscore are reserved
for private use by libguestfs.  We may add more in future.

It is recommended that callers prefix the name of their field(s)
with some unique string, to avoid conflicts with other users.

=head1 COPYRIGHT

Copyright (C) 2009-2015 Red Hat Inc.

=head1 LICENSE

Please see the file COPYING.LIB for the full license.

=head1 SEE ALSO

L<guestfs(3)>,
L<guestfish(1)>,
L<http://libguestfs.org>.

=cut
