#!/bin/bash -
# appliance/make-initramfs.sh.  Generated from make-initramfs.sh.in by configure.
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

# This is called from the Makefile to build the initramfs.

unset CDPATH

set -e

cd ..

modules="
-i augeas-libs
-i bash
-i binutils
-i coreutils
-i dosfstools
-i file
-i grub
-i iputils
-i kernel
-i lvm2
-i MAKEDEV
-i module-init-tools
-i net-tools
-i ntfs-3g
-i ntfsprogs
-i procps
-i strace
-i util-linux-ng
-i zerofree
"

# Decide on names for the final output.  These have to match Makefile.am.
output=appliance/initramfs.fedora-11.x86_64.img
koutput=appliance/vmlinuz.fedora-11.x86_64
rm -f $output
rm -f $koutput

# Create the basic initramfs.
febootstrap $modules -u updates-released-f11 fedora-11 initramfs 

# /sysroot is where the guest root filesystem will be mounted.
febootstrap-run initramfs -- mkdir -p --mode=0777 /sysroot

# Create /tmp if it is missing.
febootstrap-run initramfs -- mkdir -p --mode=0777 /tmp

# Nuke some stuff.  The kernel pulls mkinitrd and plymouth which pulls in
# all of Python.  Sheez.
(cd initramfs && find -name '*plymouth*' -print0) |
  xargs -0 febootstrap-run initramfs -- rm -rf
(cd initramfs && find -name '*python*' -print0) |
  xargs -0 febootstrap-run initramfs -- rm -rf

# In Fedora >= 11, it pulls in all of Perl from somewhere.  Nuke from orbit.
febootstrap-run initramfs -- rm -rf /usr/lib/perl5 /usr/lib64/perl5

# Anaconda?  JPEG images?
febootstrap-run initramfs -- rm -rf /usr/lib/anaconda-runtime

# Modules take up nearly half of the image.  It's a rough guess that
# we don't need many drivers (which take up most of the space).
(cd initramfs && find lib/modules/*/kernel \
  -name '*.ko' \
  -a ! -name 'virtio.ko' \
  -a ! -name 'virtio_net.ko' \
  -a ! -name 'virtio_pci.ko' \
  -a ! -name 'virtio_ring.ko' \
  -a ! -name 'ext2.ko' \
  -a ! -name 'ext3.ko' \
  -a ! -name 'ext4*.ko' \
  -a ! -name 'crc16.ko' \
  -a ! -name 'jbd.ko' \
  -a ! -name 'jbd2.ko' \
  -a ! -name 'fuse.ko' \
  -a ! -name 'vfat.ko' \
  -a ! -name 'fat.ko' \
  -a ! -name 'udf.ko' \
  -a ! -name 'crc_itu_t.ko' \
  -a ! -name 'nls_utf8.ko' \
  -a ! -name 'dm-*.ko' \
  -a ! -name 'cramfs.ko' \
  -a ! -name 'squashfs.ko' \
  -a -print0 ) |
  xargs -0 febootstrap-run initramfs -- rm

# Pull the kernel out into the current directory.  We don't want it in
# the initramfs image.
cp initramfs/boot/vmlinuz* $koutput
febootstrap-run initramfs -- rm -rf boot

# Minimize the image.
febootstrap-minimize initramfs

# Add some missing configuration files.
if [ ! -f initramfs/etc/hosts ]; then
    cat > hosts.new <<'__EOF__'
127.0.0.1 guestfs localhost.localdomain localhost
::1       localhost6.localdomain6 localhost6
__EOF__
    febootstrap-install initramfs hosts.new /etc/hosts 0644 root.root
    rm hosts.new
fi

if [ ! -f initramfs/etc/fstab ]; then
    febootstrap-run initramfs -- touch /etc/fstab
fi

echo nameserver 10.0.2.3 > resolv.conf.new
febootstrap-install initramfs resolv.conf.new /etc/resolv.conf 0644 root.root
rm resolv.conf.new

# Create the init script.
cat > init.new <<'__EOF__'
#!/bin/sh
echo Starting /init script ...
PATH=/sbin:/usr/sbin:$PATH
mount -t tmpfs none /dev
mkdir /dev/pts /dev/shm /dev/mapper
MAKEDEV mem null port zero core full ram tty console fd \
  hda hdb hdc hdd sda sdb sdc sdd loop sd
mknod /dev/ptmx c 5 2; chmod 0666 /dev/ptmx
mknod /dev/random c 1 8;  chmod 0666 /dev/random
mknod /dev/urandom c 1 9; chmod 0444 /dev/urandom
mount -t proc /proc /proc
mount -t sysfs /sys /sys
mount -t devpts -o gid=5,mode=620 /dev/pts /dev/pts
ln -sf /proc/self/fd/0 /dev/stdin
ln -sf /proc/self/fd/1 /dev/stdout
ln -sf /proc/self/fd/2 /dev/stderr
modprobe virtio_pci
modprobe virtio_net
modprobe dm_mod ||:
/sbin/ifconfig lo 127.0.0.1
/sbin/ifconfig eth0 10.0.2.10
/sbin/route add default gw 10.0.2.2
lvm vgscan --ignorelockingfailure
lvm vgchange -ay --ignorelockingfailure
exec guestfsd -f
__EOF__

febootstrap-install initramfs init.new /init 0755 root.root
rm init.new

# Just in case the kernel isn't looking for /init, make /sbin/init
# be our script, not the real init.
#febootstrap-run initramfs -- ln -f /init /sbin/init

# Copy the daemon into the filesystem.
febootstrap-install initramfs daemon/guestfsd /sbin/guestfsd 0755 root.root

# Generate final image.
febootstrap-to-initramfs initramfs > $output-t
mv $output-t $output
ls -lh $output
ls -lh $koutput
