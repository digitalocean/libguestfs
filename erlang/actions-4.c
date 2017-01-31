/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/erlang.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <erl_interface.h>
/* We should switch over to using
  #include <ei.h>
instead of erl_interface.
*/

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

#include "actions.h"

ETERM *
run_add_cdrom (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    return make_error ("add_cdrom");

  return erl_mk_atom ("ok");
}

ETERM *
run_add_libvirt_dom (ETERM *message)
{
  void * /* virDomainPtr */ dom = POINTER_NOT_IMPLEMENTED ("virDomainPtr");

  struct guestfs_add_libvirt_dom_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "readonly")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK;
      optargs_s.readonly = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "iface")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK;
      optargs_s.iface = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "live")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK;
      optargs_s.live = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "readonlydisk")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK;
      optargs_s.readonlydisk = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "cachemode")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
      optargs_s.cachemode = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "discard")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
      optargs_s.discard = erl_iolist_to_string (hd_value);
    }
    else
    if (atom_equals (hd_name, "copyonread")) {
      optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK;
      optargs_s.copyonread = get_bool (hd_value);
    }
    else
      return unknown_optarg ("add_libvirt_dom", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_add_libvirt_dom_argv (g, dom, optargs);
  if ((optargs_s.bitmask & GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK))
    free ((char *) optargs_s.iface);
  if ((optargs_s.bitmask & GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK))
    free ((char *) optargs_s.readonlydisk);
  if ((optargs_s.bitmask & GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK))
    free ((char *) optargs_s.cachemode);
  if ((optargs_s.bitmask & GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK))
    free ((char *) optargs_s.discard);
  if (r == -1)
    return make_error ("add_libvirt_dom");

  return erl_mk_int (r);
}

ETERM *
run_aug_init (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int flags = get_int (ARG (1));
  int r;

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    return make_error ("aug_init");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_insert (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int before = get_bool (ARG (2));
  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    return make_error ("aug_insert");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_load (ETERM *message)
{
  int r;

  r = guestfs_aug_load (g);
  if (r == -1)
    return make_error ("aug_load");

  return erl_mk_atom ("ok");
}

ETERM *
run_aug_rm (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    return make_error ("aug_rm");

  return erl_mk_int (r);
}

ETERM *
run_aug_set (ETERM *message)
{
  CLEANUP_FREE char *augpath = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    return make_error ("aug_set");

  return erl_mk_atom ("ok");
}

ETERM *
run_blkid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_blkid (g, device);
  if (r == NULL)
    return make_error ("blkid");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_blockdev_setra (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int sectors = get_int (ARG (1));
  int r;

  r = guestfs_blockdev_setra (g, device, sectors);
  if (r == -1)
    return make_error ("blockdev_setra");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_scrub_start (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_btrfs_scrub_start (g, path);
  if (r == -1)
    return make_error ("btrfs_scrub_start");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_scrub_status (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_btrfsscrub *r;

  r = guestfs_btrfs_scrub_status (g, path);
  if (r == NULL)
    return make_error ("btrfs_scrub_status");

  ETERM *rt = make_btrfsscrub (r);
  guestfs_free_btrfsscrub (r);
  return rt;
}

ETERM *
run_btrfs_subvolume_create (ETERM *message)
{
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (0));

  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "qgroupid")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK;
      optargs_s.qgroupid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("btrfs_subvolume_create", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);
  if ((optargs_s.bitmask & GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK))
    free ((char *) optargs_s.qgroupid);
  if (r == -1)
    return make_error ("btrfs_subvolume_create");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_set_default (ETERM *message)
{
  int64_t id = get_int64 (ARG (0));
  CLEANUP_FREE char *fs = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  if (r == -1)
    return make_error ("btrfs_subvolume_set_default");

  return erl_mk_atom ("ok");
}

ETERM *
run_btrfs_subvolume_snapshot (ETERM *message)
{
  CLEANUP_FREE char *source = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));

  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "ro")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK;
      optargs_s.ro = get_bool (hd_value);
    }
    else
    if (atom_equals (hd_name, "qgroupid")) {
      optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK;
      optargs_s.qgroupid = erl_iolist_to_string (hd_value);
    }
    else
      return unknown_optarg ("btrfs_subvolume_snapshot", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);
  if ((optargs_s.bitmask & GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK))
    free ((char *) optargs_s.qgroupid);
  if (r == -1)
    return make_error ("btrfs_subvolume_snapshot");

  return erl_mk_atom ("ok");
}

ETERM *
run_canonical_device_name (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_canonical_device_name (g, device);
  if (r == NULL)
    return make_error ("canonical_device_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_case_sensitive_path (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    return make_error ("case_sensitive_path");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_copy_size (ETERM *message)
{
  CLEANUP_FREE char *src = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *dest = erl_iolist_to_string (ARG (1));
  int64_t size = get_int64 (ARG (2));
  int r;

  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1)
    return make_error ("copy_size");

  return erl_mk_atom ("ok");
}

ETERM *
run_debug_upload (ETERM *message)
{
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tmpname = erl_iolist_to_string (ARG (1));
  int mode = get_int (ARG (2));
  int r;

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1)
    return make_error ("debug_upload");

  return erl_mk_atom ("ok");
}

ETERM *
run_download_offset (ETERM *message)
{
  CLEANUP_FREE char *remotefilename = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *filename = erl_iolist_to_string (ARG (1));
  int64_t offset = get_int64 (ARG (2));
  int64_t size = get_int64 (ARG (3));
  int r;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1)
    return make_error ("download_offset");

  return erl_mk_atom ("ok");
}

ETERM *
run_findfs_uuid (ETERM *message)
{
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL)
    return make_error ("findfs_uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_fstrim (ETERM *message)
{
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (0));

  struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "offset")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
      optargs_s.offset = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "length")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
      optargs_s.length = get_int64 (hd_value);
    }
    else
    if (atom_equals (hd_name, "minimumfreeextent")) {
      optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
      optargs_s.minimumfreeextent = get_int64 (hd_value);
    }
    else
      return unknown_optarg ("fstrim", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_fstrim_argv (g, mountpoint, optargs);
  if (r == -1)
    return make_error ("fstrim");

  return erl_mk_atom ("ok");
}

ETERM *
run_get_autosync (ETERM *message)
{
  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    return make_error ("get_autosync");

  return make_bool (r);
}

ETERM *
run_get_e2uuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    return make_error ("get_e2uuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_libvirt_requested_credential_challenge (ETERM *message)
{
  int index = get_int (ARG (0));
  char *r;

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (r == NULL)
    return make_error ("get_libvirt_requested_credential_challenge");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_get_pid (ETERM *message)
{
  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    return make_error ("get_pid");

  return erl_mk_int (r);
}

ETERM *
run_get_selinux (ETERM *message)
{
  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    return make_error ("get_selinux");

  return make_bool (r);
}

ETERM *
run_grepi (ETERM *message)
{
  CLEANUP_FREE char *regex = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (1));
  char **r;

  r = guestfs_grepi (g, regex, path);
  if (r == NULL)
    return make_error ("grepi");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_hexdump (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    return make_error ("hexdump");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_hivex_node_children (ETERM *message)
{
  int64_t nodeh = get_int64 (ARG (0));
  struct guestfs_hivex_node_list *r;

  r = guestfs_hivex_node_children (g, nodeh);
  if (r == NULL)
    return make_error ("hivex_node_children");

  ETERM *rt = make_hivex_node_list (r);
  guestfs_free_hivex_node_list (r);
  return rt;
}

ETERM *
run_inspect_get_format (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_format (g, root);
  if (r == NULL)
    return make_error ("inspect_get_format");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_get_hostname (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL)
    return make_error ("inspect_get_hostname");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_inspect_is_multipart (ETERM *message)
{
  CLEANUP_FREE char *root = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1)
    return make_error ("inspect_is_multipart");

  return make_bool (r);
}

ETERM *
run_internal_test_rbool (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_internal_test_rbool (g, val);
  if (r == -1)
    return make_error ("internal_test_rbool");

  return make_bool (r);
}

ETERM *
run_internal_test_rhashtable (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_internal_test_rhashtable (g, val);
  if (r == NULL)
    return make_error ("internal_test_rhashtable");

  ETERM *rt = make_table (r);
  guestfs_int_free_string_list (r);
  return rt;
}

ETERM *
run_internal_test_rstringlist (ETERM *message)
{
  CLEANUP_FREE char *val = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_internal_test_rstringlist (g, val);
  if (r == NULL)
    return make_error ("internal_test_rstringlist");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_internal_test_rstringlisterr (ETERM *message)
{
  char **r;

  r = guestfs_internal_test_rstringlisterr (g);
  if (r == NULL)
    return make_error ("internal_test_rstringlisterr");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_is_busy (ETERM *message)
{
  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    return make_error ("is_busy");

  return make_bool (r);
}

ETERM *
run_is_ready (ETERM *message)
{
  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    return make_error ("is_ready");

  return make_bool (r);
}

ETERM *
run_ldmtool_scan (ETERM *message)
{
  char **r;

  r = guestfs_ldmtool_scan (g);
  if (r == NULL)
    return make_error ("ldmtool_scan");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_lgetxattrs (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
  if (r == NULL)
    return make_error ("lgetxattrs");

  ETERM *rt = make_xattr_list (r);
  guestfs_free_xattr_list (r);
  return rt;
}

ETERM *
run_list_dm_devices (ETERM *message)
{
  char **r;

  r = guestfs_list_dm_devices (g);
  if (r == NULL)
    return make_error ("list_dm_devices");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_list_ldm_volumes (ETERM *message)
{
  char **r;

  r = guestfs_list_ldm_volumes (g);
  if (r == NULL)
    return make_error ("list_ldm_volumes");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_luks_format (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *key = erl_iolist_to_string (ARG (1));
  int keyslot = get_int (ARG (2));
  int r;

  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1)
    return make_error ("luks_format");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvm_canonical_lv_name (ETERM *message)
{
  CLEANUP_FREE char *lvname = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL)
    return make_error ("lvm_canonical_lv_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_lvrename (ETERM *message)
{
  CLEANUP_FREE char *logvol = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *newlogvol = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    return make_error ("lvrename");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvresize (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int mbytes = get_int (ARG (1));
  int r;

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    return make_error ("lvresize");

  return erl_mk_atom ("ok");
}

ETERM *
run_lvuuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_lvuuid (g, device);
  if (r == NULL)
    return make_error ("lvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_mke2fs_J (ETERM *message)
{
  CLEANUP_FREE char *fstype = erl_iolist_to_string (ARG (0));
  int blocksize = get_int (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  CLEANUP_FREE char *journal = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    return make_error ("mke2fs_J");

  return erl_mk_atom ("ok");
}

ETERM *
run_mke2journal_U (ETERM *message)
{
  int blocksize = get_int (ARG (0));
  CLEANUP_FREE char *uuid = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    return make_error ("mke2journal_U");

  return erl_mk_atom ("ok");
}

ETERM *
run_mknod_c (ETERM *message)
{
  int mode = get_int (ARG (0));
  int devmajor = get_int (ARG (1));
  int devminor = get_int (ARG (2));
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (3));
  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    return make_error ("mknod_c");

  return erl_mk_atom ("ok");
}

ETERM *
run_mount_options (ETERM *message)
{
  CLEANUP_FREE char *options = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *mountable = erl_iolist_to_string (ARG (1));
  CLEANUP_FREE char *mountpoint = erl_iolist_to_string (ARG (2));
  int r;

  r = guestfs_mount_options (g, options, mountable, mountpoint);
  if (r == -1)
    return make_error ("mount_options");

  return erl_mk_atom ("ok");
}

ETERM *
run_ntfsfix (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));

  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (1);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "clearbadsectors")) {
      optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
      optargs_s.clearbadsectors = get_bool (hd_value);
    }
    else
      return unknown_optarg ("ntfsfix", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_ntfsfix_argv (g, device, optargs);
  if (r == -1)
    return make_error ("ntfsfix");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_add (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *prlogex = erl_iolist_to_string (ARG (1));
  int64_t startsect = get_int64 (ARG (2));
  int64_t endsect = get_int64 (ARG (3));
  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    return make_error ("part_add");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_get_gpt_guid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_gpt_guid (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_gpt_guid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_part_get_mbr_id (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  int r;

  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1)
    return make_error ("part_get_mbr_id");

  return erl_mk_int (r);
}

ETERM *
run_part_get_mbr_part_type (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_mbr_part_type (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_mbr_part_type");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_part_get_name (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int partnum = get_int (ARG (1));
  char *r;

  r = guestfs_part_get_name (g, device, partnum);
  if (r == NULL)
    return make_error ("part_get_name");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_part_init (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *parttype = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    return make_error ("part_init");

  return erl_mk_atom ("ok");
}

ETERM *
run_part_to_partnum (ETERM *message)
{
  CLEANUP_FREE char *partition = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_part_to_partnum (g, partition);
  if (r == -1)
    return make_error ("part_to_partnum");

  return erl_mk_int (r);
}

ETERM *
run_pvuuid (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  char *r;

  r = guestfs_pvuuid (g, device);
  if (r == NULL)
    return make_error ("pvuuid");

  ETERM *rt = erl_mk_string (r);
  free (r);
  return rt;
}

ETERM *
run_readlinklist (ETERM *message)
{
  CLEANUP_FREE char *path = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE_STRING_LIST char **names = get_string_list (ARG (1));
  char **r;

  r = guestfs_readlinklist (g, path, names);
  if (r == NULL)
    return make_error ("readlinklist");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_rmmountpoint (ETERM *message)
{
  CLEANUP_FREE char *exemptpath = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    return make_error ("rmmountpoint");

  return erl_mk_atom ("ok");
}

ETERM *
run_scrub_device (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    return make_error ("scrub_device");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_cachedir (ETERM *message)
{
  CLEANUP_FREE char *cachedir;
  if (atom_equals (ARG (0), "undefined"))
    cachedir = NULL;
  else
    cachedir = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_set_cachedir (g, cachedir);
  if (r == -1)
    return make_error ("set_cachedir");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_e2attrs (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *attrs = erl_iolist_to_string (ARG (1));

  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  ETERM *optargst = ARG (2);
  while (!ERL_IS_EMPTY_LIST (optargst)) {
    ETERM *hd = ERL_CONS_HEAD (optargst);
    ETERM *hd_name = ERL_TUPLE_ELEMENT (hd, 0);
    ETERM *hd_value = ERL_TUPLE_ELEMENT (hd, 1);

    if (atom_equals (hd_name, "clear")) {
      optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
      optargs_s.clear = get_bool (hd_value);
    }
    else
      return unknown_optarg ("set_e2attrs", hd_name);
    optargst = ERL_CONS_TAIL (optargst);
  }

  int r;

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
  if (r == -1)
    return make_error ("set_e2attrs");

  return erl_mk_atom ("ok");
}

ETERM *
run_set_e2label (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *label = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    return make_error ("set_e2label");

  return erl_mk_atom ("ok");
}

ETERM *
run_sh_lines (ETERM *message)
{
  CLEANUP_FREE char *command = erl_iolist_to_string (ARG (0));
  char **r;

  r = guestfs_sh_lines (g, command);
  if (r == NULL)
    return make_error ("sh_lines");

  ETERM *rt = make_string_list (r);
  guestfs_int_free_string_list (r);

  return rt;
}

ETERM *
run_shutdown (ETERM *message)
{
  int r;

  r = guestfs_shutdown (g);
  if (r == -1)
    return make_error ("shutdown");

  return erl_mk_atom ("ok");
}

ETERM *
run_swapon_file (ETERM *message)
{
  CLEANUP_FREE char *file = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    return make_error ("swapon_file");

  return erl_mk_atom ("ok");
}

ETERM *
run_tgz_out (ETERM *message)
{
  CLEANUP_FREE char *directory = erl_iolist_to_string (ARG (0));
  CLEANUP_FREE char *tarball = erl_iolist_to_string (ARG (1));
  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    return make_error ("tgz_out");

  return erl_mk_atom ("ok");
}

ETERM *
run_umask (ETERM *message)
{
  int mask = get_int (ARG (0));
  int r;

  r = guestfs_umask (g, mask);
  if (r == -1)
    return make_error ("umask");

  return erl_mk_int (r);
}

ETERM *
run_wipefs (ETERM *message)
{
  CLEANUP_FREE char *device = erl_iolist_to_string (ARG (0));
  int r;

  r = guestfs_wipefs (g, device);
  if (r == -1)
    return make_error ("wipefs");

  return erl_mk_atom ("ok");
}
