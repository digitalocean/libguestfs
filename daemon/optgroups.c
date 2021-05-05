/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <caml/mlvalues.h>

#include "daemon.h"
#include "optgroups.h"

static int
dummy_available (void)
{
  return 1;
}

struct optgroup optgroups[] = {
  { "acl", optgroup_acl_available },
  { "augeas", dummy_available },
  { "blkdiscard", optgroup_blkdiscard_available },
  { "blkdiscardzeroes", optgroup_blkdiscardzeroes_available },
  { "btrfs", optgroup_btrfs_available },
  { "extlinux", optgroup_extlinux_available },
  { "f2fs", optgroup_f2fs_available },
  { "fstrim", optgroup_fstrim_available },
  { "gdisk", optgroup_gdisk_available },
  { "grub", optgroup_grub_available },
  { "hivex", optgroup_hivex_available },
  { "inotify", optgroup_inotify_available },
  { "journal", optgroup_journal_available },
  { "ldm", optgroup_ldm_available },
  { "libtsk", optgroup_libtsk_available },
  { "libyara", optgroup_libyara_available },
  { "linuxcaps", optgroup_linuxcaps_available },
  { "linuxfsuuid", optgroup_linuxfsuuid_available },
  { "linuxmodules", optgroup_linuxmodules_available },
  { "linuxxattrs", optgroup_linuxxattrs_available },
  { "luks", optgroup_luks_available },
  { "lvm2", optgroup_lvm2_available },
  { "mdadm", optgroup_mdadm_available },
  { "mknod", optgroup_mknod_available },
  { "ntfs3g", optgroup_ntfs3g_available },
  { "ntfsprogs", optgroup_ntfsprogs_available },
  { "realpath", dummy_available },
  { "rsync", optgroup_rsync_available },
  { "scrub", optgroup_scrub_available },
  { "selinux", optgroup_selinux_available },
  { "selinuxrelabel", optgroup_selinuxrelabel_available },
  { "sleuthkit", optgroup_sleuthkit_available },
  { "squashfs", optgroup_squashfs_available },
  { "syslinux", optgroup_syslinux_available },
  { "wipefs", optgroup_wipefs_available },
  { "xfs", optgroup_xfs_available },
  { "xz", optgroup_xz_available },
  { "zerofree", optgroup_zerofree_available },
  { NULL, NULL }
};

/* Wrappers so these functions can be called from OCaml code. */
extern value guestfs_int_daemon_optgroup_acl_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_acl_available (value unitv)
{
  return Val_bool (optgroup_acl_available ());
}

extern value guestfs_int_daemon_optgroup_blkdiscard_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_blkdiscard_available (value unitv)
{
  return Val_bool (optgroup_blkdiscard_available ());
}

extern value guestfs_int_daemon_optgroup_blkdiscardzeroes_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_blkdiscardzeroes_available (value unitv)
{
  return Val_bool (optgroup_blkdiscardzeroes_available ());
}

extern value guestfs_int_daemon_optgroup_btrfs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_btrfs_available (value unitv)
{
  return Val_bool (optgroup_btrfs_available ());
}

extern value guestfs_int_daemon_optgroup_extlinux_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_extlinux_available (value unitv)
{
  return Val_bool (optgroup_extlinux_available ());
}

extern value guestfs_int_daemon_optgroup_f2fs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_f2fs_available (value unitv)
{
  return Val_bool (optgroup_f2fs_available ());
}

extern value guestfs_int_daemon_optgroup_fstrim_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_fstrim_available (value unitv)
{
  return Val_bool (optgroup_fstrim_available ());
}

extern value guestfs_int_daemon_optgroup_gdisk_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_gdisk_available (value unitv)
{
  return Val_bool (optgroup_gdisk_available ());
}

extern value guestfs_int_daemon_optgroup_grub_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_grub_available (value unitv)
{
  return Val_bool (optgroup_grub_available ());
}

extern value guestfs_int_daemon_optgroup_hivex_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_hivex_available (value unitv)
{
  return Val_bool (optgroup_hivex_available ());
}

extern value guestfs_int_daemon_optgroup_inotify_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_inotify_available (value unitv)
{
  return Val_bool (optgroup_inotify_available ());
}

extern value guestfs_int_daemon_optgroup_journal_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_journal_available (value unitv)
{
  return Val_bool (optgroup_journal_available ());
}

extern value guestfs_int_daemon_optgroup_ldm_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_ldm_available (value unitv)
{
  return Val_bool (optgroup_ldm_available ());
}

extern value guestfs_int_daemon_optgroup_libtsk_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_libtsk_available (value unitv)
{
  return Val_bool (optgroup_libtsk_available ());
}

extern value guestfs_int_daemon_optgroup_libyara_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_libyara_available (value unitv)
{
  return Val_bool (optgroup_libyara_available ());
}

extern value guestfs_int_daemon_optgroup_linuxcaps_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_linuxcaps_available (value unitv)
{
  return Val_bool (optgroup_linuxcaps_available ());
}

extern value guestfs_int_daemon_optgroup_linuxfsuuid_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_linuxfsuuid_available (value unitv)
{
  return Val_bool (optgroup_linuxfsuuid_available ());
}

extern value guestfs_int_daemon_optgroup_linuxmodules_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_linuxmodules_available (value unitv)
{
  return Val_bool (optgroup_linuxmodules_available ());
}

extern value guestfs_int_daemon_optgroup_linuxxattrs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_linuxxattrs_available (value unitv)
{
  return Val_bool (optgroup_linuxxattrs_available ());
}

extern value guestfs_int_daemon_optgroup_luks_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_luks_available (value unitv)
{
  return Val_bool (optgroup_luks_available ());
}

extern value guestfs_int_daemon_optgroup_lvm2_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_lvm2_available (value unitv)
{
  return Val_bool (optgroup_lvm2_available ());
}

extern value guestfs_int_daemon_optgroup_mdadm_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_mdadm_available (value unitv)
{
  return Val_bool (optgroup_mdadm_available ());
}

extern value guestfs_int_daemon_optgroup_mknod_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_mknod_available (value unitv)
{
  return Val_bool (optgroup_mknod_available ());
}

extern value guestfs_int_daemon_optgroup_ntfs3g_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_ntfs3g_available (value unitv)
{
  return Val_bool (optgroup_ntfs3g_available ());
}

extern value guestfs_int_daemon_optgroup_ntfsprogs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_ntfsprogs_available (value unitv)
{
  return Val_bool (optgroup_ntfsprogs_available ());
}

extern value guestfs_int_daemon_optgroup_rsync_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_rsync_available (value unitv)
{
  return Val_bool (optgroup_rsync_available ());
}

extern value guestfs_int_daemon_optgroup_scrub_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_scrub_available (value unitv)
{
  return Val_bool (optgroup_scrub_available ());
}

extern value guestfs_int_daemon_optgroup_selinux_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_selinux_available (value unitv)
{
  return Val_bool (optgroup_selinux_available ());
}

extern value guestfs_int_daemon_optgroup_selinuxrelabel_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_selinuxrelabel_available (value unitv)
{
  return Val_bool (optgroup_selinuxrelabel_available ());
}

extern value guestfs_int_daemon_optgroup_sleuthkit_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_sleuthkit_available (value unitv)
{
  return Val_bool (optgroup_sleuthkit_available ());
}

extern value guestfs_int_daemon_optgroup_squashfs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_squashfs_available (value unitv)
{
  return Val_bool (optgroup_squashfs_available ());
}

extern value guestfs_int_daemon_optgroup_syslinux_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_syslinux_available (value unitv)
{
  return Val_bool (optgroup_syslinux_available ());
}

extern value guestfs_int_daemon_optgroup_wipefs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_wipefs_available (value unitv)
{
  return Val_bool (optgroup_wipefs_available ());
}

extern value guestfs_int_daemon_optgroup_xfs_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_xfs_available (value unitv)
{
  return Val_bool (optgroup_xfs_available ());
}

extern value guestfs_int_daemon_optgroup_xz_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_xz_available (value unitv)
{
  return Val_bool (optgroup_xz_available ());
}

extern value guestfs_int_daemon_optgroup_zerofree_available (value);

/* NB: This is a "noalloc" call. */
value
guestfs_int_daemon_optgroup_zerofree_available (value unitv)
{
  return Val_bool (optgroup_zerofree_available ());
}

