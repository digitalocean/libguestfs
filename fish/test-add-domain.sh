#!/bin/bash -
# libguestfs
# Copyright (C) 2010 Red Hat Inc.
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

# Test add-domain command.

set -e

rm -f test1.img test2.img test3.img test4.img test.xml test.out

cwd="$(pwd)"

./guestfish sparse test1.img 1M
./guestfish sparse test2.img 1M
./guestfish sparse test3.img 1M
./guestfish sparse test4.img 1M

# Libvirt test XML, see libvirt.git/examples/xml/test/testnode.xml
cat > test.xml <<EOF
<node>
  <domain type="test">
    <name>guest</name>
    <os>
      <type>hvm</type>
      <boot dev='hd'/>
    </os>
    <memory>524288</memory>
    <devices>
      <disk type="file">
        <source file="$cwd/test1.img"/>
        <target dev="hda"/>
      </disk>
      <disk type="file">
        <driver name="qemu" type="raw"/>
        <source file="$cwd/test2.img"/>
        <target dev="hdb"/>
      </disk>
      <disk type="file">
        <driver name="qemu" type="qcow2"/>
        <source file="$cwd/test3.img"/>
        <target dev="hdc"/>
      </disk>
      <disk type="file">
        <driver name="qemu" type="raw"/>
        <source file="$cwd/test4.img"/>
        <target dev="hdd"/>
        <readonly/>
      </disk>
    </devices>
  </domain>
</node>
EOF

./guestfish >test.out <<EOF
  domain guest libvirturi:test://$cwd/test.xml readonly:true
  debug-drives
EOF
grep -sq "test1.img readonly" test.out
! grep -sq "test1.img.*format" test.out
grep -sq "test2.img readonly format=raw" test.out
grep -sq "test3.img readonly format=qcow2" test.out

# Test readonlydisk = "ignore".
./guestfish >test.out <<EOF
  -domain guest libvirturi:test://$cwd/test.xml readonly:true readonlydisk:ignore
  debug-drives
EOF
grep -sq "test1.img" test.out
grep -sq "test2.img" test.out
grep -sq "test3.img" test.out
! grep -sq "test4.img" test.out

# Test atomicity.
rm test3.img

./guestfish >test.out <<EOF
  -domain guest libvirturi:test://$cwd/test.xml readonly:true
  debug-drives
EOF
! grep -sq "test1.img" test.out
! grep -sq "test2.img" test.out
! grep -sq "test3.img" test.out
! grep -sq "test4.img" test.out

rm -f test1.img test2.img test3.img test4.img test.xml test.out
