=encoding utf8

=head1 名前

virt-tar - 仮想マシンへのファイルの展開またはアップロード

=head1 書式

 virt-tar [--options] -x domname directory tarball

 virt-tar [--options] -u domname tarball directory

 virt-tar [--options] disk.img [disk.img ...] -x directory tarball

 virt-tar [--options] disk.img [disk.img ...] -u tarball directory

=head1 非推奨

このツールは推奨されません。  代わりに L<virt-copy-in(1)>, L<virt-copy-out(1)>,
L<virt-tar-in(1)>, L<virt-tar-out(1)> を使用してください。

=head1 例

仮想マシンから C</home> をローカルの tar ファイルにダウンロードします:

 virt-tar -x domname /home home.tar

 virt-tar -zx domname /home home.tar.gz

ローカルの tar ファイルをアップロードして、仮想マシンの C</tmp> に展開します:

 virt-tar -u domname uploadstuff.tar /tmp

 virt-tar -zu domname uploadstuff.tar.gz /tmp

=head1 警告

You must I<not> use C<virt-tar> with the I<-u> option (upload) on live
virtual machines.  If you do this, you risk disk corruption in the VM.
C<virt-tar> tries to stop you from doing this, but doesn't catch all cases.

You can use I<-x> (extract) on live virtual machines, but you might get
inconsistent results or errors if there is filesystem activity inside the
VM.  If the live VM is synched and quiescent, then C<virt-tar> will usually
work, but the only way to guarantee consistent results is if the virtual
machine is shut down.

=head1 説明

C<virt-tar> is a general purpose archive tool for downloading and uploading
parts of a guest filesystem.  There are many possibilities: making backups,
uploading data files, snooping on guest activity, fixing or customizing
guests, etc.

If you want to just view a single file, use L<virt-cat(1)>.  If you just
want to edit a single file, use L<virt-edit(1)>.  For more complex cases you
should look at the L<guestfish(1)> tool.

There are two modes of operation: I<-x> (eXtract) downloads a directory and
its contents (recursively) from the virtual machine into a local tarball.
I<-u> uploads from a local tarball, unpacking it into a directory inside the
virtual machine.  You cannot use these two options together.

In addition, you may need to use the I<-z> (gZip) option to enable
compression.  When uploading, you have to specify I<-z> if the upload file
is compressed because virt-tar won't detect this on its own.

C<virt-tar> can only handle tar (optionally gzipped) format tarballs.  For
example it cannot do PKZip files or bzip2 compression.  If you want that
then you'll have to rebuild the tarballs yourself.  (This is a limitation of
the L<libguestfs(3)> API).

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

=item B<-x>

=item B<--extract>

=item B<--download>

=item B<-u>

=item B<--upload>

Use I<-x> to extract (download) a directory from a virtual machine to a
local tarball.

Use I<-u> to upload and unpack from a local tarball into a virtual machine.
Please read the L</WARNING> section above before using this option.

これらのオプションのいずれかを正確に指定する必要があります。

=item B<-z>

=item B<--gzip>

Specify that the input or output tarball is gzip-compressed.

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 関連項目

L<guestfs(3)>, L<guestfish(1)>, L<virt-cat(1)>, L<virt-edit(1)>,
L<virt-copy-in(1)>, L<virt-copy-out(1)>, L<virt-tar-in(1)>,
L<virt-tar-out(1)>, L<Sys::Guestfs(3)>, L<Sys::Guestfs::Lib(3)>,
L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 著者

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2009 Red Hat Inc.

