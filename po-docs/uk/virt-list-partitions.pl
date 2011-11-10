=encoding utf8

=head1 НАЗВА

virt-list-partitions - List partitions in a virtual machine or disk image

=head1 КОРОТКИЙ ОПИС

 virt-list-partitions [--параметри] назва_домену

 virt-list-partitions [--параметри] диск.img [диск.img ...]

=head1 ОПИС

This tool is obsolete.  Use L<virt-filesystems(1)> as a more flexible
replacement.

C<virt-list-partitions> is a command line tool to list the partitions that
are contained in a virtual machine or disk image.  It is mainly useful as a
first step to using L<virt-resize(1)>.

C<virt-list-partitions> is just a simple wrapper around L<libguestfs(3)>
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

=item B<-h>

=item B<--human-readable>

Show sizes in human-readable form (eg. "1G").

=item B<-l>

=item B<--long>

With this option, C<virt-list-partitions> displays the type and size of each
partition too (where "type" means C<ext3>, C<pv> etc.)

=item B<-t>

=item B<--total>

Display the total size of each block device (as a separate row or rows).

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 ТАКОЖ ПЕРЕГЛЯНЬТЕ

L<guestfs(3)>, L<guestfish(1)>, L<virt-filesystems(1)>,
L<virt-list-filesystems(1)>, L<virt-resize(1)>, L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>, L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 АВТОР

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 АВТОРСЬКІ ПРАВА

© Red Hat Inc., 2009–2010

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

Ця програма поширюється у сподіванні, що вона буде корисною, але БЕЗ
БУДЬ-ЯКИХ ГАРАНТІЙНИХ ЗОБОВ’ЯЗАНЬ; навіть без очевидної гарантії
ПРАЦЕЗДАТНОСТІ або ПРИДАТНОСТІ ДЛЯ ВИКОРИСТАННЯ З ПЕВНОЮ МЕТОЮ. Докладніше
про це можна дізнатися з GNU General Public License.

Ви маєте отримати копію GNU General Public License разом з цією програмою;
якщо це не так, повідомте про факт за адресою Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

