=encoding utf8

=head1 名前

virt-make-fs - tar アーカイブまたはファイルからファイルシステムの作成

=head1 書式

 virt-make-fs [--options] input.tar output.img

 virt-make-fs [--options] input.tar.gz output.img

 virt-make-fs [--options] directory output.img

=head1 説明

Virt-make-fs is a command line tool for creating a filesystem from a tar
archive or some files in a directory.  It is similar to tools like
L<mkisofs(1)>, L<genisoimage(1)> and L<mksquashfs(1)>.  Unlike those tools,
it can create common filesystem types like ext2/3 or NTFS, which can be
useful if you want to attach these filesystems to existing virtual machines
(eg. to import large amounts of read-only data to a VM).

空のディスクを使用するには L<virt-format(1)> を使用します。

Basic usage is:

 virt-make-fs input output.img

where C<input> is either a directory containing files that you want to add,
or a tar archive (either uncompressed tar or gzip-compressed tar); and
C<output.img> is a disk image.  The input type is detected automatically.
The output disk image defaults to a raw ext2 sparse image unless you specify
extra flags (see L</OPTIONS> below).

=head2 ファイルシステム形式

The default filesystem type is C<ext2>.  Just about any filesystem type that
libguestfs supports can be used (but I<not> read-only formats like
ISO9660).  Here are some of the more common choices:

=over 4

=item I<ext3>

Note that ext3 filesystems contain a journal, typically 1-32 MB in size.  If
you are not going to use the filesystem in a way that requires the journal,
then this is just wasted overhead.

=item I<ntfs> または I<vfat>

Useful if exporting data to a Windows guest.

I<Note for vfat>: The tar archive or local directory must only contain files
which are owned by root (ie. UID:GID = 0:0).  The reason is that the tar
program running within libguestfs is unable to change the ownership of
non-root files, since vfat itself does not support this.

=item I<minix>

Lower overhead than C<ext2>, but certain limitations on filename length and
total filesystem size.

=back

=head3 例

 virt-make-fs --type=minix input minixfs.img

=head2 TO PARTITION OR NOT TO PARTITION

Optionally virt-make-fs can add a partition table to the output disk.

Adding a partition can make the disk image more compatible with certain
virtualized operating systems which don't expect to see a filesystem
directly located on a block device (Linux doesn't care and will happily
handle both types).

On the other hand, if you have a partition table then the output image is no
longer a straight filesystem.  For example you cannot run L<fsck(8)>
directly on a partitioned disk image.  (However libguestfs tools such as
L<guestfish(1)> and L<virt-resize(1)> can still be used).

=head3 例

MBR パーティションを追加します:

 virt-make-fs --partition -- input disk.img

If the output disk image could be terabyte-sized or larger, it's better to
use an EFI/GPT-compatible partition table:

 virt-make-fs --partition=gpt --size=+4T --format=qcow2 input disk.img

=head2 EXTRA SPACE

Unlike formats such as tar and squashfs, a filesystem does not "just fit"
the files that it contains, but might have extra space.  Depending on how
you are going to use the output, you might think this extra space is wasted
and want to minimize it, or you might want to leave space so that more files
can be added later.  Virt-make-fs defaults to minimizing the extra space,
but you can use the I<--size> flag to leave space in the filesystem if you
want it.

An alternative way to leave extra space but not make the output image any
bigger is to use an alternative disk image format (instead of the default
"raw" format).  Using I<--format=qcow2> will use the native QEmu/KVM qcow2
image format (check your hypervisor supports this before using it).  This
allows you to choose a large I<--size> but the extra space won't actually be
allocated in the image until you try to store something in it.

Don't forget that you can also use local commands including L<resize2fs(8)>
and L<virt-resize(1)> to resize existing filesystems, or rerun virt-make-fs
to build another image from scratch.

=head3 例

 virt-make-fs --format=qcow2 --size=+200M input output.img

=head1 オプション

=over 4

=item B<--help>

簡単なヘルプを表示します。

=item B<--version>

バージョン番号を表示して終了します。

=item B<--debug>

デバッグ情報を有効にします。

=item B<--size=E<lt>NE<gt>>

=item B<--size=+E<lt>NE<gt>>

=item B<-s E<lt>NE<gt>>

=item B<-s +E<lt>NE<gt>>

Use the I<--size> (or I<-s>) option to choose the size of the output image.

If this option is I<not> given, then the output image will be just large
enough to contain all the files, with not much wasted space.

To choose a fixed size output disk, specify an absolute number followed by
b/K/M/G/T/P/E to mean bytes, Kilobytes, Megabytes, Gigabytes, Terabytes,
Petabytes or Exabytes.  This must be large enough to contain all the input
files, else you will get an error.

To leave extra space, specify C<+> (plus sign) and a number followed by
b/K/M/G/T/P/E to mean bytes, Kilobytes, Megabytes, Gigabytes, Terabytes,
Petabytes or Exabytes.  For example: I<--size=+200M> means enough space for
the input files, and (approximately) an extra 200 MB free space.

Note that virt-make-fs estimates free space, and therefore will not produce
filesystems containing precisely the free space requested.  (It is much more
expensive and time-consuming to produce a filesystem which has precisely the
desired free space).

=item B<--format=E<lt>fmtE<gt>>

=item B<-F E<lt>fmtE<gt>>

出力するディスクイメージ形式を選択します。

デフォルトは C<raw> です (スパースな raw 形式のディスクイメージ)。

For other choices, see the L<qemu-img(1)> manpage.  The only other choice
that would really make sense here is C<qcow2>.

=item B<--type=E<lt>fsE<gt>>

=item B<-t E<lt>fsE<gt>>

Choose the output filesystem type.

デフォルトは C<ext2> です。

Any filesystem which is supported read-write by libguestfs can be used here.

=item B<--partition>

=item B<--partition=E<lt>parttypeE<gt>>

このフラグが指定されていると、出力ディスクイメージに MBR パーティションテーブルを追加します。

You can change the partition table type, eg. I<--partition=gpt> for large
disks.

Note that if you just use a lonesome I<--partition>, the Perl option parser
might consider the next parameter to be the partition type.  For example:

 virt-make-fs --partition input.tar output.img

would cause virt-make-fs to think you wanted to use a partition type of
C<input.tar> which is completely wrong.  To avoid this, use I<--> (a double
dash) between options and the input and output arguments:

 virt-make-fs --partition -- input.tar output.img

For MBR, virt-make-fs sets the partition type byte automatically.

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 関連項目

L<guestfish(1)>, L<virt-format(1)>, L<virt-resize(1)>, L<virt-tar-in(1)>,
L<mkisofs(1)>, L<genisoimage(1)>, L<mksquashfs(1)>, L<mke2fs(8)>,
L<resize2fs(8)>, L<guestfs(3)>, L<Sys::Guestfs(3)>,
L<http://libguestfs.org/>.

=head1 バグ

バグを報告するとき、デバッグを有効にして、I<完全な> 出力を記録してください:

 export LIBGUESTFS_DEBUG=1
 virt-make-fs --debug [...] > /tmp/virt-make-fs.log 2>&1

/tmp/virt-make-fs.log を L<https://bugzilla.redhat.com/> の新しいバグ報告に添付します

=head1 著者

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2010-2012 Red Hat Inc.

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

