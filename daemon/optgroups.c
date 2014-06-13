/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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

#include "daemon.h"
#include "optgroups.h"

static int
dummy_available (void)
{
  return 1;
}

#define optgroup_augeas_available dummy_available
#define optgroup_realpath_available dummy_available

struct optgroup optgroups[] = {
  { "acl", optgroup_acl_available },
  { "augeas", optgroup_augeas_available },
  { "blkdiscard", optgroup_blkdiscard_available },
  { "blkdiscardzeroes", optgroup_blkdiscardzeroes_available },
  { "btrfs", optgroup_btrfs_available },
  { "extlinux", optgroup_extlinux_available },
  { "fstrim", optgroup_fstrim_available },
  { "gdisk", optgroup_gdisk_available },
  { "grub", optgroup_grub_available },
  { "hivex", optgroup_hivex_available },
  { "inotify", optgroup_inotify_available },
  { "journal", optgroup_journal_available },
  { "ldm", optgroup_ldm_available },
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
  { "realpath", optgroup_realpath_available },
  { "rsync", optgroup_rsync_available },
  { "scrub", optgroup_scrub_available },
  { "selinux", optgroup_selinux_available },
  { "syslinux", optgroup_syslinux_available },
  { "wipefs", optgroup_wipefs_available },
  { "xfs", optgroup_xfs_available },
  { "xz", optgroup_xz_available },
  { "zerofree", optgroup_zerofree_available },
  { NULL, NULL }
};
