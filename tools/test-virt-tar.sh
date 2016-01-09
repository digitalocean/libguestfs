#!/bin/bash -
# libguestfs
# Copyright (C) 2009-2016 Red Hat Inc.
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

export LANG=C
set -e

# Read out the test directory using virt-tar.
$srcdir/virt-tar -x ../test-data/phony-guests/fedora.img /bin test.tar

if [ "$(tar tf test.tar | sort)" != "./
./ls
./test1
./test2
./test3
./test4
./test5
./test6
./test7" ]; then
    echo "$0: error: unexpected output in tarball from virt-tar"
    exit 1
fi

rm test.tar
