=encoding utf8

=head1 НАЗВА

virt-list-filesystems - List filesystems in a virtual machine or disk image

=head1 КОРОТКИЙ ОПИС

 virt-list-filesystems [--параметри] -d назва_домену

 virt-list-filesystems [--параметри] образ.img [образ.img ...]

=head1 ЗАСТАРІЛЕ

This tool is obsolete.  Use L<virt-filesystems(1)> as a more flexible
replacement.

=head1 ОПИС

C<virt-list-filesystems> is a command line tool to list the filesystems that
are contained in a virtual machine or disk image.

C<virt-list-filesystems> is just a simple wrapper around L<libguestfs(3)>
functionality.  For more complex cases you should look at the
L<guestfish(1)> tool.

=head1 ПАРАМЕТРИ

=over 4

=item B<--help>

Показати коротку довідку.

=item B<--version>

Показати дані щодо версії і завершити роботу.

=item B<-c адреса>

=item B<--connect адреса>

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

=item B<-l>

=item B<--long>

With this option, C<virt-list-filesystems> displays the type of each
filesystem too (where "type" means C<ext3>, C<xfs> etc.)

=item B<-a>

=item B<--all>

Normally we only show mountable filesystems.  If this option is given then
swap devices are shown too.

=back

=head1 ЕКРАНУВАННЯ СИМВОЛІВ У ОБОЛОНЦІ

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 ТАКОЖ ПЕРЕГЛЯНЬТЕ

L<guestfs(3)>, L<guestfish(1)>, L<virt-cat(1)>, L<virt-tar(1)>,
L<virt-filesystems(1)>, L<virt-list-partitions(1)>, L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>, L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 АВТОР

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 АВТОРСЬКІ ПРАВА

© Red Hat Inc., 2009

