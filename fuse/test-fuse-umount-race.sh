#!/bin/bash -
# libguestfs
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

# https://bugzilla.redhat.com/show_bug.cgi?id=838592
# This tests that the --pid-file option can be used to fix the race.

unset CDPATH
set -e
#set -v

if [ -n "$SKIP_TEST_FUSE_SH" ]; then
    echo "$0: test skipped because environment variable is set."
    exit 77
fi

if [ ! -w /dev/fuse ]; then
    echo "SKIPPING guestmount test, because there is no /dev/fuse."
    exit 77
fi

rm -f test.qcow2 test-copy.qcow2 test.pid
rm -rf mp

# Make a copy of the Fedora image so we can write to it then discard it.
qemu-img create -F raw -b ../tests/guests/fedora.img -f qcow2 test.qcow2

mkdir mp
./guestmount -a test.qcow2 -m /dev/VG/Root --pid-file test.pid mp
cp $0 mp/test-umount

# Save the PID of guestmount.
pid="$(cat test.pid)"

timeout=10

count=$timeout
while ! fusermount -u mp && [ $count -gt 0 ]; do
    sleep 1
    ((count--))
done
if [ $count -eq 0 ]; then
    echo "$0: fusermount failed after $timeout seconds"
    exit 1
fi

# Wait for guestmount to exit.
count=$timeout
while kill -0 "$pid" 2>/dev/null && [ $count -gt 0 ]; do
    sleep 1
    ((count--))
done
if [ $count -eq 0 ]; then
    echo "$0: wait for guestmount to exit failed after $timeout seconds"
    exit 1
fi

# It should now be safe to copy and read the disk image.
cp test.qcow2 test-copy.qcow2

if [ "$(../fish/guestfish -a test-copy.qcow2 --ro -i is-file /test-umount)" != "true" ]; then
    echo "$0: test failed"
    exit 1
fi

rm test.qcow2 test-copy.qcow2
rm -f test.pid
rm -r mp
