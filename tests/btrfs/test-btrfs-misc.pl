#!/usr/bin/perl
# libguestfs
# Copyright (C) 2013 Red Hat Inc.
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

# Miscellaneous btrfs features.

use strict;
use warnings;

use Sys::Guestfs;

# Allow the test to be skipped since btrfs is often broken.
exit 77 if $ENV{SKIP_TEST_BTRFS_MISC_PL};

my $g = Sys::Guestfs->new ();

$g->add_drive_scratch (1024*1024*1024);
$g->launch ();

# If btrfs is not available, bail.
unless ($g->feature_available (["btrfs"])) {
    warn "$0: skipping test because btrfs is not available\n";
    exit 77;
}

$g->part_disk ("/dev/sda", "mbr");

$g->mkfs_btrfs (["/dev/sda1"]);

# Setting label.
$g->set_label ("/dev/sda1", "newlabel");
my $label = $g->vfs_label ("/dev/sda1");
die "unexpected label: expecting 'newlabel' but got '$label'"
    unless $label eq "newlabel";

$g->shutdown ();
$g->close ();
