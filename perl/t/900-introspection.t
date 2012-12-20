# libguestfs Perl bindings -*- perl -*-
# Copyright (C) 2011 Red Hat Inc.
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

# Test %guestfs_introspection.

use strict;
use warnings;
use Test::More tests => 10;

use Errno;

use Sys::Guestfs;

my %add_drive = %{$Sys::Guestfs::guestfs_introspection{add_drive}};
ok(1);

is ($add_drive{ret}, "void");
is ($add_drive{args}[0][0], "filename");
is ($add_drive{args}[0][1], "string");
is ($add_drive{args}[0][2], 0);

# In libguestfs >= 1.19.19, this is an alias.
my %add_drive_opts = %{$Sys::Guestfs::guestfs_introspection{add_drive_opts}};
ok(1);

ok (exists $add_drive_opts{optargs});
ok (exists $add_drive_opts{optargs}->{readonly});
is ($add_drive_opts{optargs}->{readonly}[0], "readonly");
is ($add_drive_opts{optargs}->{readonly}[1], "bool");
