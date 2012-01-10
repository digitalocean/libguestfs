/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

struct optgroup optgroups[] = {
  { "augeas", optgroup_augeas_available },
  { "btrfs", optgroup_btrfs_available },
  { "grub", optgroup_grub_available },
  { "inotify", optgroup_inotify_available },
  { "linuxfsuuid", optgroup_linuxfsuuid_available },
  { "linuxmodules", optgroup_linuxmodules_available },
  { "linuxxattrs", optgroup_linuxxattrs_available },
  { "luks", optgroup_luks_available },
  { "lvm2", optgroup_lvm2_available },
  { "mknod", optgroup_mknod_available },
  { "ntfs3g", optgroup_ntfs3g_available },
  { "ntfsprogs", optgroup_ntfsprogs_available },
  { "realpath", optgroup_realpath_available },
  { "scrub", optgroup_scrub_available },
  { "selinux", optgroup_selinux_available },
  { "xz", optgroup_xz_available },
  { "zerofree", optgroup_zerofree_available },
  { NULL, NULL }
};
