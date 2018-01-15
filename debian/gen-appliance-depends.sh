#!/bin/sh

set -ex

pkglist_to_deps() {
    echo -n 'appliance:Depends='
    sed -e 's,^iproute2\?,iproute2 | iproute,' \
        -e 's,^\(gfs-tools\|gfs2-tools\|gfs2-utils\),gfs2-utils | gfs2-tools | gfs-tools,' \
        -e 's,^\(kmod\|module-init-tools\),kmod | module-init-tools,' \
        -e 's,^\(systemd-sysv\|sysvinit-core\),systemd-sysv | sysvinit-core,' \
        -e 's,^\(libsystemd-[a-z1-9-]*0\),libsystemd0 | \1,' \
        -e 's,^\(util-linux\|fdisk\),fdisk | util-linux (<< 2.29.2),' \
        -e '/^\(bash\|coreutils\|findutils\|grep\|gzip\|libc-bin\|sed\|tar\)$/d' \
        | tr '\n' ','
    echo
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
