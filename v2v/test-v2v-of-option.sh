#!/bin/bash -
# libguestfs virt-v2v test script
# Copyright (C) 2014 Red Hat Inc.
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

# Test virt-v2v -of (format conversion) option.

unset CDPATH
export LANG=C
set -e

if [ -n "$SKIP_TEST_V2V_OF_OPTION_SH" ]; then
    echo "$0: test skipped because environment variable is set"
    exit 77
fi

if [ "$(guestfish get-backend)" = "uml" ]; then
    echo "$0: test skipped because UML backend does not support network or qcow2"
    exit 77
fi

abs_top_builddir="$(cd ..; pwd)"
libvirt_uri="test://$abs_top_builddir/test-data/phony-guests/guests.xml"

f=../test-data/phony-guests/windows.img
if ! test -f $f || ! test -s $f; then
    echo "$0: test skipped because phony Windows image was not created"
    exit 77
fi

export VIRT_TOOLS_DATA_DIR="$srcdir/../test-data/fake-virt-tools"

d=test-v2v-of-option.d
rm -rf $d
mkdir $d

$VG virt-v2v --debug-gc \
    -i libvirt -ic "$libvirt_uri" windows \
    -o local -os $d -of qcow2

# Test the disk is qcow2 format.
if [ "$(guestfish disk-format $d/windows-sda)" != qcow2 ]; then
    echo "$0: test failed: output is not qcow2"
    exit 1
fi

rm -r $d
