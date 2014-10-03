#!/bin/sh

set -ex

cd debian/tmp/usr/lib/*-*/guestfs/supermin.d
cp -n packages packages.orig

for p in gfs2 hfsplus jfs nilfs reiserfs rsync xfs zfs; do
    sed -i -e "/$p/d" packages
    grep -F  "$p" < packages.orig > packages-$p || true
done

sed -i -e "/^\(iputils\|lsof\|openssh-server\|strace\|vim\)/d" packages

grep "^\(iputils\|lsof\|openssh-server\|strace\|vim\)" \
    < packages.orig > packages-rescue

rm -f packages.orig
