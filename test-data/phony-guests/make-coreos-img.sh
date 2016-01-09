#!/bin/bash -
# libguestfs
# Copyright (C) 2015 Red Hat Inc.
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

# Make a CoreOS image which is enough to fool the inspection heuristics.

export LANG=C
set -e

# lsb-release file.
cat > archlinux.release <<'EOF'
DISTRIB_ID=CoreOS
DISTRIB_RELEASE=647.0.0
DISTRIB_CODENAME="Red Dog"
DISTRIB_DESCRIPTION="CoreOS 647.0.0"
EOF

# Create a disk image.
guestfish <<EOF
sparse coreos.img-t 512M
run

part-init /dev/sda gpt
part-add /dev/sda p 4096 266239
part-add /dev/sda p 266240 270335
part-add /dev/sda p 270336 532479
part-add /dev/sda p 532480 794623
part-add /dev/sda p 794624 -4096

part-set-name /dev/sda 1 EFI_SYSTEM
part-set-bootable /dev/sda 1 true
part-set-name /dev/sda 2 BIOS-BOOT
part-set-name /dev/sda 3 USR-A
part-set-name /dev/sda 4 USR-B
part-set-name /dev/sda 5 ROOT

mkfs fat /dev/sda1
mkfs ext4 /dev/sda3
set-label /dev/sda3 USR-A
set-uuid /dev/sda3 01234567-0123-0123-0123-012345678901
mkfs ext4 /dev/sda5
set-label /dev/sda5 ROOT
set-uuid /dev/sda5 01234567-0123-0123-0123-012345678902

# Enough to fool inspection API.
mount /dev/sda5 /
mkdir-p /etc/coreos
mkdir /usr
mount /dev/sda3 /usr
mkdir /usr/bin
mkdir /usr/lib64
mkdir /usr/local
mkdir-p /usr/share/coreos/

ln-s usr/bin /bin
ln-s usr/lib64 /lib64
ln-s lib64 /lib
mkdir /root
mkdir /home

write /etc/coreos/update.conf "GROUP=stable"
upload archlinux.release /usr/share/coreos/lsb-release
ln-s ../usr/share/coreos/lsb-release /etc/lsb-release
write /etc/hostname "coreos.invalid"

EOF

rm archlinux.release
mv coreos.img-t coreos.img
