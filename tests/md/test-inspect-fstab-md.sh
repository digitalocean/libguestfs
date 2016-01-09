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

# Test the handling of MD devices specified in /etc/fstab

set -e
export LANG=C

if [ -n "$SKIP_TEST_INSPECT_FSTAB_MD_SH" ]; then
    echo "$0: test skipped because environment variable is set."
    exit 77
fi

rm -f inspect-fstab-md-{1,2}.img inspect-fstab-md.fstab inspect-fstab-md.output

# First, test the regular fedora image, which specifies /boot as /dev/md0
cp ../../test-data/phony-guests/fedora-md1.img inspect-fstab-md-1.img
cp ../../test-data/phony-guests/fedora-md2.img inspect-fstab-md-2.img

guestfish -i inspect-fstab-md-[12].img <<'EOF' | sort > inspect-fstab-md.output
  exists /boot/grub/grub.conf
EOF

if [ "$(cat inspect-fstab-md.output)" != "true" ]; then
    echo "$0: /boot not correctly mounted (/dev/md0)"
    exit 1
fi

# Test inspection when /boot is specfied as /dev/md/boot
cat <<'EOF' > inspect-fstab-md.fstab
/dev/VG/Root / ext2 default 0 0
/dev/md/boot /boot ext2 default 0 0
EOF

guestfish -a inspect-fstab-md-1.img -a inspect-fstab-md-2.img <<'EOF'
  run
  mount /dev/VG/Root /
  upload inspect-fstab-md.fstab /etc/fstab
EOF

guestfish -i inspect-fstab-md-[12].img <<'EOF' | sort > inspect-fstab-md.output
  exists /boot/grub/grub.conf
EOF

if [ "$(cat inspect-fstab-md.output)" != "true" ]; then
    echo "$0: error: /boot not correctly mounted (/dev/md/boot)"
    cat inspect-fstab-md.output
    exit 1
fi

rm inspect-fstab-md.fstab
rm inspect-fstab-md-[12].img
rm inspect-fstab-md.output
