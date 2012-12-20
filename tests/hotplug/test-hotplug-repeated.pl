#!/usr/bin/perl
# Copyright (C) 2012 Red Hat Inc.
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
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# Test repeatedly hotplugging a single disk.

use strict;
use warnings;

use Sys::Guestfs;

my $g = Sys::Guestfs->new ();

# Skip the test if the default attach-method isn't libvirt, since only
# the libvirt backend supports hotplugging.
my $attach_method = $g->get_attach_method ();
unless ($attach_method eq "libvirt" || $attach_method =~ /^libvirt:/) {
    print "$0: test skipped because attach-method ($attach_method) is not libvirt\n";
    exit 77
}

$g->launch ();

# Create a temporary disk.
open FILE, ">test1.img" or die "test1.img: $!";
truncate FILE, 512 * 1024 * 1024 or die "test1.img: truncate: $!";
close FILE;

my $start_t = time ();
while (time () - $start_t <= 60) {
    $g->add_drive ("test1.img", label => "a", format => "raw");
    $g->remove_drive ("a");
}

# There should be no drives remaining.
my @devices = $g->list_devices ();
die unless 0 == @devices;

$g->shutdown ();
$g->close ();

unlink "test1.img";

exit 0
