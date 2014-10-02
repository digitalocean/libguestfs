#!/bin/sh

set -e

pkglist_to_deps() {
    echo -n 'appliance:Depends='
    sed -e 's,^iproute2\?,iproute2 | iproute,' \
        -e 's,^\(gfs-tools\|gfs2-tools\|gfs2-utils\),gfs2-utils | gfs2-tools | gfs-tools,' \
        -e 's,^\(kmod\|module-init-tools\),kmod | module-init-tools,' \
        -e 's,^\(systemd\|sysvinit\),systemd | sysvinit,' \
        -e 's,^\(libsystemd-[a-z1-9-]*0\),libsystemd0 | \1,' \
        -e '/^\(bash\|coreutils\|e2fsprogs\|findutils\|grep\|gzip\|libc-bin\|sed\|tar\|util\-linux\)$/d' \
        | tr '\n' ','
}

for p in gfs2 hfsplus jfs nilfs reiserfs rescue rsync xfs zfs
do
    cat debian/libguestfs-$p/usr/lib/*-*/guestfs/supermin.d/packages-$p \
        |  pkglist_to_deps \
        >> debian/libguestfs-$p.substvars
done

cat debian/libguestfs0/usr/lib/*-*/guestfs/supermin.d/packages \
    |  pkglist_to_deps \
    >> debian/libguestfs0.substvars
