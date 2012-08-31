=encoding utf8

=head1 名前

virt-list-partitions - 仮想マシンまたはディスクイメージのパーティションの一覧表示

=head1 書式

 virt-list-partitions [--options] domname

 virt-list-partitions [--options] disk.img [disk.img ...]

=head1 非推奨

This tool is obsolete.  Use L<virt-filesystems(1)> as a more flexible
replacement.

=head1 説明

C<virt-list-partitions>
は、仮想マシンまたはディスクイメージに含まれるパーティションを一覧表示するためのコマンドラインツールです。おもに L<virt-resize(1)>
を使用するための最初の手順として有用です。

C<virt-list-partitions> は L<libguestfs(3)> の機能の簡単なラッパーです。より複雑な場合に対しては
L<guestfish(1)> ツールを参照してください。

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

=item B<-h>

=item B<--human-readable>

容量を読みやすい形式で表示します（例: "1G"）。

=item B<-l>

=item B<--long>

このオプションを用いると、 C<virt-list-partitions> は各パーティションの形式と容量も表示します（ここで "形式" は
C<ext3>, C<pv> などを意味します）。

=item B<-t>

=item B<--total>

各ブロックデバイスの合計容量を（別の列として）表示します。

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 関連項目

L<guestfs(3)>, L<guestfish(1)>, L<virt-filesystems(1)>,
L<virt-list-filesystems(1)>, L<virt-resize(1)>, L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>, L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 著者

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2009-2012 Red Hat Inc.

