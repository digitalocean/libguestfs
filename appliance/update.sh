#!/bin/bash -
# appliance/update.sh.  Generated from update.sh.in by configure.
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
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

# Update the init script or daemon inside an existing initramfs.
# Avoids the timeconsuming rebuild.

unset CDPATH

set -e

if [ "REDHAT" = "REDHAT" ]; then
  cd ..
  output=appliance/initramfs.fedora-11.x86_64.img

  # Create the init script.
  febootstrap-install initramfs appliance/../appliance/init /init 0755 root.root

  # Copy the daemon into the filesystem.
  febootstrap-install initramfs daemon/guestfsd /sbin/guestfsd 0755 root.root

  # Generate final image.
  febootstrap-to-initramfs initramfs > $output-t
  mv $output-t $output
  ls -lh $output
elif [ "REDHAT" = "DEBIAN" ]; then
  cd ../appliance

  output=initramfs.fedora-11.x86_64.img
  vmlinuz=vmlinuz.fedora-11.x86_64

  ln -sf debian/debirf-libguestfs_fedora-11*.cgz $output
  ln -sf debian/vmlinuz-* $vmlinuz
fi

