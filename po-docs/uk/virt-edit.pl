
=head1 НАЗВА

virt-edit - Edit a file in a virtual machine

=head1 КОРОТКИЙ ОПИС

 virt-edit [--options] domname file

 virt-edit [--options] disk.img [disk.img ...] file

 virt-edit [domname|disk.img] file -e 'expr'

=head1 WARNING

You must I<not> use C<virt-edit> on live virtual machines.  If you do this,
you risk disk corruption in the VM.  C<virt-edit> tries to stop you from
doing this, but doesn't catch all cases.

=head1 ОПИС

C<virt-edit> is a command line tool to edit C<file> where C<file> exists in
the named virtual machine (or disk image).

If you want to just view a file, use L<virt-cat(1)>.

For more complex cases you should look at the L<guestfish(1)> tool (see
L</USING GUESTFISH> below).

C<virt-edit> cannot be used to create a new file, nor to edit multiple
files.  L<guestfish(1)> can do that and much more.

=head1 EXAMPLES

Edit the named files interactively:

 virt-edit mydomain /boot/grub/grub.conf

 virt-edit mydomain /etc/passwd

For Windows guests, some Windows paths are understood:

 virt-edit mywindomain 'c:\autoexec.bat'

You can also edit files non-interactively (see L</NON-INTERACTIVE EDITING>
below).  To change the init default level to 5:

 virt-edit mydomain /etc/inittab -e 's/^id:.*/id:5:initdefault:/'

=head1 OPTIONS

=over 4

=item B<--help>

Display brief help.

=item B<--version>

Display version number and exit.

=item B<--backup extension> | B<-b extension>

Create a backup of the original file I<in the guest disk image>.  The backup
has the original filename with C<extension> added.

Usually the first character of C<extension> would be a dot C<.> so you would
write:

 virt-edit -b .orig [etc]

By default, no backup file is made.

=item B<--connect URI> | B<-c URI>

If using libvirt, connect to the given I<URI>.  If omitted, then we connect
to the default libvirt hypervisor.

If you specify guest block devices directly, then libvirt is not used at
all.

=item B<--format> raw

Specify the format of disk images given on the command line.  If this is
omitted then the format is autodetected from the content of the disk image.

If disk images are requested from libvirt, then this program asks libvirt
for this information.  In this case, the value of the format parameter is
ignored.

If working with untrusted raw-format guest disk images, you should ensure
the format is always specified.

=item B<--expr EXPR> | B<-e EXPR>

Instead of launching the external editor, non-interactively apply the Perl
expression C<EXPR> to each line in the file.  See L</NON-INTERACTIVE
EDITING> below.

Be careful to properly quote the expression to prevent it from being altered
by the shell.

=back

=head1 NON-INTERACTIVE EDITING

C<virt-edit> normally calls out to C<$EDITOR> (or vi) so the system
administrator can interactively edit the file.

There are two ways also to use C<virt-edit> from scripts in order to make
automated edits to files.  (Note that although you I<can> use C<virt-edit>
like this, it's less error-prone to write scripts directly using the
libguestfs API and Augeas for configuration file editing.)

The first method is to temporarily set C<$EDITOR> to any script or program
you want to run.  The script is invoked as C<$EDITOR tmpfile> and it should
update C<tmpfile> in place however it likes.

The second method is to use the I<-e> parameter of C<virt-edit> to run a
short Perl snippet in the style of L<sed(1)>.  For example to replace all
instances of C<foo> with C<bar> in a file:

 virt-edit domname filename -e 's/foo/bar/'

The full power of Perl regular expressions can be used (see L<perlre(1)>).
For example to delete root's password you could do:

 virt-edit domname /etc/passwd -e 's/^root:.*?:/root::/'

What really happens is that the snippet is evaluated as a Perl expression
for each line of the file.  The line, including the final C<\n>, is passed
in C<$_> and the expression should update C<$_> or leave it unchanged.

To delete a line, set C<$_> to the empty string.  For example, to delete the
C<apache> user account from the password file you can do:

 virt-edit mydomain /etc/passwd -e '$_ = "" if /^apache:/'

To insert a line, prepend or append it to C<$_>.  However appending lines to
the end of the file is rather difficult this way since there is no concept
of "last line of the file" - your expression just doesn't get called again.
You might want to use the first method (setting C<$EDITOR>) if you want to
do this.

The variable C<$lineno> contains the current line number.  As is
traditional, the first line in the file is number C<1>.

The return value from the expression is ignored, but the expression may call
C<die> in order to abort the whole program, leaving the original file
untouched.

Remember when matching the end of a line that C<$_> may contain the final
C<\n>, or (for DOS files) C<\r\n>, or if the file does not end with a
newline then neither of these.  Thus to match or substitute some text at the
end of a line, use this regular expression:

 /some text(\r?\n)?$/

Alternately, use the perl C<chomp> function, being careful not to chomp
C<$_> itself (since that would remove all newlines from the file):

 my $m = $_; chomp $m; $m =~ /some text$/

=head1 WINDOWS PATHS

C<virt-edit> has a limited ability to understand Windows drive letters and
paths (eg. C<E:\foo\bar.txt>).

If and only if the guest is running Windows then:

=over 4

=item *

Drive letter prefixes like C<C:> are resolved against the Windows Registry
to the correct filesystem.

=item *

Any backslash (C<\>) characters in the path are replaced with forward
slashes so that libguestfs can process it.

=item *

The path is resolved case insensitively to locate the file that should be
edited.

=back

There are some known shortcomings:

=over 4

=item *

Some NTFS symbolic links may not be followed correctly.

=item *

NTFS junction points that cross filesystems are not followed.

=back

=head1 USING GUESTFISH

L<guestfish(1)> is a more powerful, lower level tool which you can use when
C<virt-edit> doesn't work.

Using C<virt-edit> is approximately equivalent to doing:

 guestfish --rw -i -d domname edit /file

where C<domname> is the name of the libvirt guest, and C</file> is the full
path to the file.

The command above uses libguestfs's guest inspection feature and so does not
work on guests that libguestfs cannot inspect, or on things like arbitrary
disk images that don't contain guests.  To edit a file on a disk image
directly, use:

 guestfish --rw -a disk.img -m /dev/sda1 edit /file

where C<disk.img> is the disk image, C</dev/sda1> is the filesystem within
the disk image to edit, and C</file> is the full path to the file.

C<virt-edit> cannot create new files.  Use the guestfish commands C<touch>,
C<write> or C<upload> instead:

 guestfish --rw -i -d domname touch /newfile

 guestfish --rw -i -d domname write /newfile "new content"

 guestfish --rw -i -d domname upload localfile /newfile

C<virt-edit> cannot edit multiple files, but guestfish can do it like this:

 guestfish --rw -i -d domname edit /file1 : edit /file2

=head1 ЗМІННІ СЕРЕДОВИЩА

=over 4

=item C<EDITOR>

If set, this string is used as the editor.  It may contain arguments,
eg. C<"emacs -nw">

If not set, C<vi> is used.

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 ТАКОЖ ПЕРЕГЛЯНЬТЕ

L<guestfs(3)>, L<guestfish(1)>, L<virt-cat(1)>, L<virt-copy-in(1)>,
L<virt-tar-in(1)>, L<Sys::Guestfs(3)>, L<Sys::Guestfs::Lib(3)>,
L<Sys::Virt(3)>, L<http://libguestfs.org/>, L<perl(1)>, L<perlre(1)>.

=head1 AUTHOR

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 АВТОРСЬКІ ПРАВА

Copyright (C) 2009-2011 Red Hat Inc.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 675 Mass
Ave, Cambridge, MA 02139, USA.

