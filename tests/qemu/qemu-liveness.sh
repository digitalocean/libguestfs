#!/bin/bash -
# libguestfs
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

# Boot and check that writes work.
# Note this is the first boot test that we run, so it's looking for
# all sorts of qemu/kernel/supermin problems.

set -e

. $srcdir/../../test-data/guestfs-hashsums.sh

rm -f liveness1.img

guestfish sparse liveness1.img 100M
liveness1_md5sum="$(do_md5 liveness1.img)"

guestfish <<'EOF'
add liveness1.img format:raw
run

part-disk /dev/sda mbr

mkfs ext2 /dev/sda1
mount /dev/sda1 /

write /test "This is a test"

EOF

# Verify that the disk has changed.
if [ "$(do_md5 liveness1.img)" = "$liveness1_md5sum" ]; then
    echo "***** ERROR *****"
    echo "Write operations are not modifying an attached disk."
    echo
    echo "Check to see if any errors or warnings are printed above."
    exit 1
fi

rm liveness1.img
