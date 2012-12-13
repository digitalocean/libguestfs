#!/bin/bash -
# libguestfs
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
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# Test if we can handle qemu death from the kill-subprocess command.

set -e

if [ "$(../../fish/guestfish get-attach-method)" != "appliance" ]; then
    echo "$0: test skipped because default attach-method is not 'appliance'"
    exit 77
fi

rm -f test1.img

../../fish/guestfish -N disk <<'EOF'
# Kill the subprocess.
kill-subprocess

# XXX The following sleep should NOT be necessary.
-sleep 1

# We should now be able to rerun the subprocess.
add test1.img
run
ping-daemon
EOF

rm -f test1.img
