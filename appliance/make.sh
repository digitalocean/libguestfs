#!/bin/bash -
# appliance/make.sh.  Generated from make.sh.in by configure.
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
set -x

if [ "REDHAT" = "REDHAT" ]; then
  cd ..
  # Decide on names for the final output.  These have to match Makefile.am.
  output=appliance/initramfs.fedora-11.x86_64.img
  koutput=appliance/vmlinuz.fedora-11.x86_64
  rm -f $output
  rm -f $koutput

  # Create the basic initramfs.
  exec 5<appliance/packagelist
  packages=
  while read pkg 0<&5; do
      packages="$packages -i $pkg"
  done
  exec 5<&-

  febootstrap $packages -u http://www.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/updates/11/x86_64/ fedora-11 initramfs http://www.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/releases/11/Fedora/x86_64/os/

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

  # Don't need any firmware.
  febootstrap-run initramfs -- rm -rf /lib/firmware

  # Don't need any keyboard maps.
  febootstrap-run initramfs -- rm -rf /lib/kbd

  # Remove anything in home directory.  Because of the potential for disaster
  # we don't put a slash before 'home'.
  (cd initramfs && echo home/*) |
    xargs febootstrap-run initramfs -- rm -rf

  # Remove /var/lib/yum stuff.
  febootstrap-run initramfs -- rm -rf /var/lib/yum

  # Remove some unreadable binaries which are incompatible with
  # the supermin appliance.  Since these binaries can't be read
  # from the host filesystem, they generate warnings like:
  #   cpio: ./usr/bin/chfn: Cannot open: Permission denied
  # These binaries are not needed for operation of the appliance.
  febootstrap-run initramfs -- rm -f \
    /usr/bin/chfn \
    /usr/bin/chsh \
    /usr/libexec/pt_chown \
    /usr/sbin/groupdel \
    /usr/sbin/groupadd \
    /usr/sbin/useradd \
    /usr/sbin/tzdata-update \
    /usr/sbin/userdel \
    /usr/sbin/usermod \
    /usr/sbin/groupmod \
    /usr/sbin/groupmems \
    /sbin/unix_update \
    $(cd initramfs && echo usr/sbin/glibc_post_upgrade.*)

  # Kernel modules take up nearly half of the image.  Only include ones
  # which are on the whitelist.
  exec 5<appliance/kmod.whitelist
  whitelist=
  while read kmod 0<&5; do
      whitelist="$whitelist -a -not -name $kmod"
  done
  exec 5<&-

  (cd initramfs && \
    find lib/modules/*/kernel -name '*.ko' $whitelist -a -print0 ) |
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

  ls -lh $koutput

  # Now directly run the update script to copy/update the daemon in the
  # initramfs.
  cd appliance && bash update.sh

elif [ "REDHAT" = "DEBIAN" ]; then
  cd ../appliance
  debirf make -n debian
  mkdir -p ../initramfs
  touch ../initramfs/fakeroot.log
fi

