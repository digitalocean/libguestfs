=encoding utf8

=head1 名前

virt-list-filesystems - 仮想マシンまたはディスクイメージのファイルシステムの一覧表示

=head1 書式

 virt-list-filesystems [--options] domname

 virt-list-filesystems [--options] disk.img [disk.img ...]

=head1 非推奨

This tool is obsolete.  Use L<virt-filesystems(1)> as a more flexible
replacement.

=head1 説明

C<virt-list-filesystems> is a command line tool to list the filesystems that
are contained in a virtual machine or disk image.

C<virt-list-filesystems> is just a simple wrapper around L<libguestfs(3)>
functionality.  For more complex cases you should look at the
L<guestfish(1)> tool.

=head1 オプション

=over 4

=item B<--help>

簡単なヘルプを表示します。

=item B<--version>

バージョン番号を表示して終了します。

=item B<-c URI>

=item B<--connect URI>

libvirt を使用していると、指定された I<URI> に接続します。  省略すると、デフォルトの libvirt ハイパーバイザーに接続します。

仮想マシンのブロックデバイスを直接指定すると、libvirt はまったく使用されません。

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

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 関連項目

L<guestfs(3)>, L<guestfish(1)>, L<virt-cat(1)>, L<virt-tar(1)>,
L<virt-filesystems(1)>, L<virt-list-partitions(1)>, L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>, L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 著者

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2009 Red Hat Inc.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 51
Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

