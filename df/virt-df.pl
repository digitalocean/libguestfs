#!/usr/bin/perl -w
# virt-df
# Copyright (C) 2009 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

use warnings;
use strict;

use Sys::Guestfs;
use Sys::Guestfs::Lib qw(open_guest get_partitions resolve_windows_path
  inspect_all_partitions inspect_partition
  inspect_operating_systems mount_operating_system inspect_in_detail);
use Pod::Usage;
use Getopt::Long;
use Data::Dumper;
use File::Temp qw/tempdir/;
use XML::Writer;
use Locale::TextDomain 'libguestfs';

=encoding utf8

=head1 NAME

virt-df - Display free space on virtual filesystems

=head1 SYNOPSIS

 virt-df [--options]

 virt-df [--options] domname

 virt-df [--options] disk.img [disk.img ...]

=head1 DESCRIPTION

C<virt-df> is a command line tool to display free space on virtual
machine filesystems.  Unlike other tools, it doesn't just display the
amount of space allocated to a virtual machine, but can look inside
the virtual machine to see how much space is really being used.

It is like the L<df(1)> command, but for virtual machines, except that
it also works for Windows virtual machines.

If used without any arguments, C<virt-df> checks with libvirt to get a
list of all active and inactive guests, and performs a C<df>-type
operation on each one in turn, printing out the results.

If used with any argument(s), C<virt-df> performs a C<df>-type
operation on either the single named libvirt domain, or on the disk
image(s) listed on the command line (which must all belong to a single
VM).  In this mode (with arguments), C<virt-df> will I<only work for a
single guest>.  If you want to run on multiple guests, then you have
to invoke C<virt-df> multiple times.

Use the C<--csv> option to get a format which can be easily parsed by
other programs.  Other options are mostly similar to standard C<df>
options.  See below for the complete list.

=head1 OPTIONS

=over 4

=cut

my $help;

=item B<--help>

Display brief help.

=cut

my $version;

=item B<--version>

Display version number and exit.

=cut

my $uri;

=item B<--connect URI> | B<-c URI>

If using libvirt, connect to the given I<URI>.  If omitted, then we
connect to the default libvirt hypervisor.

If you specify guest block devices directly, then libvirt is not used
at all.

=cut

my $csv;

=item B<--csv>

Write out the results in CSV format (comma-separated values).
This format can be imported easily into databases and spreadsheets.

=cut

my $human;

=item B<--human-readable> | B<-h>

Print sizes in human-readable format.

=cut

my $inodes;

=item B<--inodes> | B<-i>

Print inodes instead of blocks.

=back

=cut

GetOptions ("help|?" => \$help,
	    "version" => \$version,
	    "connect|c=s" => \$uri,
            "csv" => \$csv,
            "human-readable|human|h" => \$human,
            "inodes|i" => \$inodes,
    ) or pod2usage (2);
pod2usage (1) if $help;
if ($version) {
    my $g = Sys::Guestfs->new ();
    my %h = $g->version ();
    print "$h{major}.$h{minor}.$h{release}$h{extra}\n";
    exit
}

# Open the guest handle.

if (@ARGV == 0) {
    my $conn;

    if ($uri) {
	$conn = Sys::Virt->new (readonly => 1, address => $uri);
    } else {
	$conn = Sys::Virt->new (readonly => 1);
    }

    my @doms = $conn->list_defined_domains ();
    push @doms, $conn->list_domains ();

    my @domnames = map { $_->get_name () } @doms;

    if (@domnames) {
	print_title ();
	foreach (@domnames) {
	    do_df ($_);
	}
    }
} else {
    print_title ();
    do_df (@ARGV);
}

sub do_df
{
    my $g;

    if ($uri) {
	$g = open_guest (\@_, address => $uri);
    } else {
	$g = open_guest (\@_);
    }

    $g->launch ();
    $g->wait_ready ();

    my @partitions = get_partitions ($g);

    # Think of a printable name for this domain.  Just choose the
    # first parameter passed to this function, which will work for
    # most cases (it'll either be the domain name or the first disk
    # image name).
    my $domname = $_[0];

    # Mount each partition in turn, and if mountable, do a statvfs on it.
    foreach my $partition (@partitions) {
	my %stat;
	eval {
	    $g->mount_ro ($partition, "/");
	    %stat = $g->statvfs ("/");
	};
	if (!$@) {
	    print_stat ($domname, $partition, \%stat);
	}
	$g->umount_all ();
    }
}

sub print_stat
{
    my $domname = shift;
    my $partition = shift;
    my $stat = shift;

    my @cols = ($domname, $partition);

    if (!$inodes) {
	my $bsize = $stat->{bsize};	# block size
	my $blocks = $stat->{blocks};	# total number of blocks
	my $bfree = $stat->{bfree};	# blocks free (total)
	my $bavail = $stat->{bavail};	# blocks free (for non-root users)

	my $factor = $bsize / 1024;

	push @cols, $blocks*$factor;	# total 1K blocks
	push @cols, ($blocks-$bfree)*$factor; # total 1K blocks used
	push @cols, $bavail*$factor;	# total 1K blocks available

	# XXX %used column comes out different from the native 'df'
	# program.  Need to check how 'df' calculates this.
	push @cols, 100.0 - 100.0 * $bavail / $blocks;

	if ($human) {
	    $cols[2] = human_size ($cols[2]);
	    $cols[3] = human_size ($cols[3]);
	    $cols[4] = human_size ($cols[4]);
	}
    } else {
	my $files = $stat->{files};	# total number of inodes
	my $ffree = $stat->{ffree};	# inodes free (total)
	my $favail = $stat->{favail};	# inodes free (for non-root users)

	push @cols, $files;
	push @cols, $files-$ffree;
	push @cols, $ffree;

	# XXX %used column comes out different from the native 'df'
	# program.  Need to check how 'df' calculates this.
	push @cols, 100.0 - 100.0 * $favail / $files;
    }

    print_cols (@cols);
}

sub print_title
{
    my @cols = (__"Virtual Machine", __"Filesystem");
    if (!$inodes) {
	if (!$human) {
	    push @cols, __"1K-blocks";
	} else {
	    push @cols, __"Size";
	}
	push @cols, __"Used";
	push @cols, __"Available";
	push @cols, __"Use%";
    } else {
	push @cols, __"Inodes";
	push @cols, __"IUsed";
	push @cols, __"IFree";
	push @cols, __"IUse%";
    }

    if (!$csv) {
	# ignore $cols[0] in this mode
	printf "%-36s%10s %10s %10s %5s\n",
	  $cols[1], $cols[2], $cols[3], $cols[4], $cols[5];
    } else {
	print (join (",", @cols), "\n");
    }
}

sub print_cols
{
    if (!$csv) {
	my $label = sprintf "%s:%s", $_[0], $_[1];

	printf ("%-36s", $label);
	print "\n"," "x32 if length ($label) > 36;

	my $percent = sprintf "%3.1f%%", $_[5];
	printf ("%10s %10s %10s %5s\n", $_[2], $_[3], $_[4], $percent);
    } else {
	printf ("\"%s\",\"%s\",%d,%d,%d,%.1f%%\n", @_);
    }
}

# Convert a number of 1K blocks to a human-readable number.
sub human_size
{
    local $_ = shift;

    if ($_ < 1024) {
	sprintf "%dK", $_;
    } elsif ($_ < 1024 * 1024) {
	sprintf "%.1fM", ($_ / 1024);
    } else {
	sprintf "%.1fG", ($_ / 1024 / 1024);
    }
}

=head1 SEE ALSO

L<guestfs(3)>,
L<guestfish(1)>,
L<Sys::Guestfs(3)>,
L<Sys::Guestfs::Lib(3)>,
L<Sys::Virt(3)>,
L<http://libguestfs.org/>.

=head1 AUTHOR

Richard W.M. Jones L<http://et.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2009 Red Hat Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
