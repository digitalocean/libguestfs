/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/python.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2017 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef GUESTFS_PYTHON_ACTIONS_H_
#define GUESTFS_PYTHON_ACTIONS_H_

#include "guestfs.h"
#include "guestfs-internal-frontend.h"

#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
#endif

#ifndef HAVE_PYCAPSULE_NEW
typedef struct {
  PyObject_HEAD
  guestfs_h *g;
} Pyguestfs_Object;
#endif

static inline guestfs_h *
get_handle (PyObject *obj)
{
  assert (obj);
  assert (obj != Py_None);
#ifndef HAVE_PYCAPSULE_NEW
  return ((Pyguestfs_Object *) obj)->g;
#else
  return (guestfs_h*) PyCapsule_GetPointer(obj, "guestfs_h");
#endif
}

static inline PyObject *
put_handle (guestfs_h *g)
{
  assert (g);
#ifndef HAVE_PYCAPSULE_NEW
  return
    PyCObject_FromVoidPtrAndDesc ((void *) g, (char *) "guestfs_h", NULL);
#else
  return PyCapsule_New ((void *) g, "guestfs_h", NULL);
#endif
}

extern void guestfs_int_py_extend_module (PyObject *module);

extern PyObject *guestfs_int_py_create (PyObject *self, PyObject *args);
extern PyObject *guestfs_int_py_close (PyObject *self, PyObject *args);
extern PyObject *guestfs_int_py_set_event_callback (PyObject *self, PyObject *args);
extern PyObject *guestfs_int_py_delete_event_callback (PyObject *self, PyObject *args);
extern PyObject *guestfs_int_py_event_to_string (PyObject *self, PyObject *args);
extern char **guestfs_int_py_get_string_list (PyObject *obj);
extern PyObject *guestfs_int_py_put_string_list (char * const * const argv);
extern PyObject *guestfs_int_py_put_table (char * const * const argv);

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
extern PyObject *guestfs_int_py_put_application (struct guestfs_application *application);
#endif
#ifdef GUESTFS_HAVE_STRUCT_APPLICATION2
extern PyObject *guestfs_int_py_put_application2 (struct guestfs_application2 *application2);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSBALANCE
extern PyObject *guestfs_int_py_put_btrfsbalance (struct guestfs_btrfsbalance *btrfsbalance);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSQGROUP
extern PyObject *guestfs_int_py_put_btrfsqgroup (struct guestfs_btrfsqgroup *btrfsqgroup);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSSCRUB
extern PyObject *guestfs_int_py_put_btrfsscrub (struct guestfs_btrfsscrub *btrfsscrub);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME
extern PyObject *guestfs_int_py_put_btrfssubvolume (struct guestfs_btrfssubvolume *btrfssubvolume);
#endif
#ifdef GUESTFS_HAVE_STRUCT_DIRENT
extern PyObject *guestfs_int_py_put_dirent (struct guestfs_dirent *dirent);
#endif
#ifdef GUESTFS_HAVE_STRUCT_HIVEX_NODE
extern PyObject *guestfs_int_py_put_hivex_node (struct guestfs_hivex_node *hivex_node);
#endif
#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
extern PyObject *guestfs_int_py_put_hivex_value (struct guestfs_hivex_value *hivex_value);
#endif
#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
extern PyObject *guestfs_int_py_put_inotify_event (struct guestfs_inotify_event *inotify_event);
#endif
#ifdef GUESTFS_HAVE_STRUCT_INT_BOOL
extern PyObject *guestfs_int_py_put_int_bool (struct guestfs_int_bool *int_bool);
#endif
#ifdef GUESTFS_HAVE_STRUCT_ISOINFO
extern PyObject *guestfs_int_py_put_isoinfo (struct guestfs_isoinfo *isoinfo);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_LV
extern PyObject *guestfs_int_py_put_lvm_lv (struct guestfs_lvm_lv *lvm_lv);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_PV
extern PyObject *guestfs_int_py_put_lvm_pv (struct guestfs_lvm_pv *lvm_pv);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_VG
extern PyObject *guestfs_int_py_put_lvm_vg (struct guestfs_lvm_vg *lvm_vg);
#endif
#ifdef GUESTFS_HAVE_STRUCT_MDSTAT
extern PyObject *guestfs_int_py_put_mdstat (struct guestfs_mdstat *mdstat);
#endif
#ifdef GUESTFS_HAVE_STRUCT_PARTITION
extern PyObject *guestfs_int_py_put_partition (struct guestfs_partition *partition);
#endif
#ifdef GUESTFS_HAVE_STRUCT_STAT
extern PyObject *guestfs_int_py_put_stat (struct guestfs_stat *stat);
#endif
#ifdef GUESTFS_HAVE_STRUCT_STATNS
extern PyObject *guestfs_int_py_put_statns (struct guestfs_statns *statns);
#endif
#ifdef GUESTFS_HAVE_STRUCT_STATVFS
extern PyObject *guestfs_int_py_put_statvfs (struct guestfs_statvfs *statvfs);
#endif
#ifdef GUESTFS_HAVE_STRUCT_TSK_DIRENT
extern PyObject *guestfs_int_py_put_tsk_dirent (struct guestfs_tsk_dirent *tsk_dirent);
#endif
#ifdef GUESTFS_HAVE_STRUCT_UTSNAME
extern PyObject *guestfs_int_py_put_utsname (struct guestfs_utsname *utsname);
#endif
#ifdef GUESTFS_HAVE_STRUCT_VERSION
extern PyObject *guestfs_int_py_put_version (struct guestfs_version *version);
#endif
#ifdef GUESTFS_HAVE_STRUCT_XATTR
extern PyObject *guestfs_int_py_put_xattr (struct guestfs_xattr *xattr);
#endif
#ifdef GUESTFS_HAVE_STRUCT_XFSINFO
extern PyObject *guestfs_int_py_put_xfsinfo (struct guestfs_xfsinfo *xfsinfo);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_LV
extern PyObject *guestfs_int_py_put_lvm_lv_list (struct guestfs_lvm_lv_list *lvm_lvs);
#endif
#ifdef GUESTFS_HAVE_STRUCT_DIRENT
extern PyObject *guestfs_int_py_put_dirent_list (struct guestfs_dirent_list *dirents);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSQGROUP
extern PyObject *guestfs_int_py_put_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *btrfsqgroups);
#endif
#ifdef GUESTFS_HAVE_STRUCT_TSK_DIRENT
extern PyObject *guestfs_int_py_put_tsk_dirent_list (struct guestfs_tsk_dirent_list *tsk_dirents);
#endif
#ifdef GUESTFS_HAVE_STRUCT_PARTITION
extern PyObject *guestfs_int_py_put_partition_list (struct guestfs_partition_list *partitions);
#endif
#ifdef GUESTFS_HAVE_STRUCT_STATNS
extern PyObject *guestfs_int_py_put_statns_list (struct guestfs_statns_list *statnss);
#endif
#ifdef GUESTFS_HAVE_STRUCT_APPLICATION2
extern PyObject *guestfs_int_py_put_application2_list (struct guestfs_application2_list *application2s);
#endif
#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
extern PyObject *guestfs_int_py_put_inotify_event_list (struct guestfs_inotify_event_list *inotify_events);
#endif
#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
extern PyObject *guestfs_int_py_put_application_list (struct guestfs_application_list *applications);
#endif
#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
extern PyObject *guestfs_int_py_put_hivex_value_list (struct guestfs_hivex_value_list *hivex_values);
#endif
#ifdef GUESTFS_HAVE_STRUCT_XATTR
extern PyObject *guestfs_int_py_put_xattr_list (struct guestfs_xattr_list *xattrs);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_PV
extern PyObject *guestfs_int_py_put_lvm_pv_list (struct guestfs_lvm_pv_list *lvm_pvs);
#endif
#ifdef GUESTFS_HAVE_STRUCT_LVM_VG
extern PyObject *guestfs_int_py_put_lvm_vg_list (struct guestfs_lvm_vg_list *lvm_vgs);
#endif
#ifdef GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME
extern PyObject *guestfs_int_py_put_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *btrfssubvolumes);
#endif
#ifdef GUESTFS_HAVE_STRUCT_MDSTAT
extern PyObject *guestfs_int_py_put_mdstat_list (struct guestfs_mdstat_list *mdstats);
#endif
#ifdef GUESTFS_HAVE_STRUCT_HIVEX_NODE
extern PyObject *guestfs_int_py_put_hivex_node_list (struct guestfs_hivex_node_list *hivex_nodes);
#endif
#ifdef GUESTFS_HAVE_STRUCT_STAT
extern PyObject *guestfs_int_py_put_stat_list (struct guestfs_stat_list *stats);
#endif

#ifdef GUESTFS_HAVE_ACL_DELETE_DEF_FILE
extern PyObject *guestfs_int_py_acl_delete_def_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ACL_GET_FILE
extern PyObject *guestfs_int_py_acl_get_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ACL_SET_FILE
extern PyObject *guestfs_int_py_acl_set_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_CDROM
extern PyObject *guestfs_int_py_add_cdrom (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DOMAIN
extern PyObject *guestfs_int_py_add_domain (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_OPTS
extern PyObject *guestfs_int_py_add_drive (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO
extern PyObject *guestfs_int_py_add_drive_ro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF
extern PyObject *guestfs_int_py_add_drive_ro_with_if (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_SCRATCH
extern PyObject *guestfs_int_py_add_drive_scratch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_WITH_IF
extern PyObject *guestfs_int_py_add_drive_with_if (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ADD_LIBVIRT_DOM
extern PyObject *guestfs_int_py_add_libvirt_dom (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_CLEAR
extern PyObject *guestfs_int_py_aug_clear (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_CLOSE
extern PyObject *guestfs_int_py_aug_close (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_DEFNODE
extern PyObject *guestfs_int_py_aug_defnode (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_DEFVAR
extern PyObject *guestfs_int_py_aug_defvar (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_GET
extern PyObject *guestfs_int_py_aug_get (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_INIT
extern PyObject *guestfs_int_py_aug_init (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_INSERT
extern PyObject *guestfs_int_py_aug_insert (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_LABEL
extern PyObject *guestfs_int_py_aug_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_LOAD
extern PyObject *guestfs_int_py_aug_load (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_LS
extern PyObject *guestfs_int_py_aug_ls (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_MATCH
extern PyObject *guestfs_int_py_aug_match (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_MV
extern PyObject *guestfs_int_py_aug_mv (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_RM
extern PyObject *guestfs_int_py_aug_rm (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_SAVE
extern PyObject *guestfs_int_py_aug_save (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_SET
extern PyObject *guestfs_int_py_aug_set (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AUG_SETM
extern PyObject *guestfs_int_py_aug_setm (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AVAILABLE
extern PyObject *guestfs_int_py_available (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_AVAILABLE_ALL_GROUPS
extern PyObject *guestfs_int_py_available_all_groups (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BASE64_IN
extern PyObject *guestfs_int_py_base64_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BASE64_OUT
extern PyObject *guestfs_int_py_base64_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLKDISCARD
extern PyObject *guestfs_int_py_blkdiscard (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLKDISCARDZEROES
extern PyObject *guestfs_int_py_blkdiscardzeroes (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLKID
extern PyObject *guestfs_int_py_blkid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS
extern PyObject *guestfs_int_py_blockdev_flushbufs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETBSZ
extern PyObject *guestfs_int_py_blockdev_getbsz (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETRO
extern PyObject *guestfs_int_py_blockdev_getro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSIZE64
extern PyObject *guestfs_int_py_blockdev_getsize64 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSS
extern PyObject *guestfs_int_py_blockdev_getss (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSZ
extern PyObject *guestfs_int_py_blockdev_getsz (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_REREADPT
extern PyObject *guestfs_int_py_blockdev_rereadpt (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETBSZ
extern PyObject *guestfs_int_py_blockdev_setbsz (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRA
extern PyObject *guestfs_int_py_blockdev_setra (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRO
extern PyObject *guestfs_int_py_blockdev_setro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRW
extern PyObject *guestfs_int_py_blockdev_setrw (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_CANCEL
extern PyObject *guestfs_int_py_btrfs_balance_cancel (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_PAUSE
extern PyObject *guestfs_int_py_btrfs_balance_pause (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_RESUME
extern PyObject *guestfs_int_py_btrfs_balance_resume (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_STATUS
extern PyObject *guestfs_int_py_btrfs_balance_status (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_ADD
extern PyObject *guestfs_int_py_btrfs_device_add (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_DELETE
extern PyObject *guestfs_int_py_btrfs_device_delete (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE
extern PyObject *guestfs_int_py_btrfs_filesystem_balance (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT
extern PyObject *guestfs_int_py_btrfs_filesystem_defragment (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE
extern PyObject *guestfs_int_py_btrfs_filesystem_resize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SHOW
extern PyObject *guestfs_int_py_btrfs_filesystem_show (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC
extern PyObject *guestfs_int_py_btrfs_filesystem_sync (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_FSCK
extern PyObject *guestfs_int_py_btrfs_fsck (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_IMAGE
extern PyObject *guestfs_int_py_btrfs_image (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN
extern PyObject *guestfs_int_py_btrfs_qgroup_assign (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_CREATE
extern PyObject *guestfs_int_py_btrfs_qgroup_create (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_DESTROY
extern PyObject *guestfs_int_py_btrfs_qgroup_destroy (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_LIMIT
extern PyObject *guestfs_int_py_btrfs_qgroup_limit (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_REMOVE
extern PyObject *guestfs_int_py_btrfs_qgroup_remove (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_SHOW
extern PyObject *guestfs_int_py_btrfs_qgroup_show (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_ENABLE
extern PyObject *guestfs_int_py_btrfs_quota_enable (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_RESCAN
extern PyObject *guestfs_int_py_btrfs_quota_rescan (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_REPLACE
extern PyObject *guestfs_int_py_btrfs_replace (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER
extern PyObject *guestfs_int_py_btrfs_rescue_chunk_recover (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER
extern PyObject *guestfs_int_py_btrfs_rescue_super_recover (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_CANCEL
extern PyObject *guestfs_int_py_btrfs_scrub_cancel (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_RESUME
extern PyObject *guestfs_int_py_btrfs_scrub_resume (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_START
extern PyObject *guestfs_int_py_btrfs_scrub_start (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_STATUS
extern PyObject *guestfs_int_py_btrfs_scrub_status (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SET_SEEDING
extern PyObject *guestfs_int_py_btrfs_set_seeding (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS
extern PyObject *guestfs_int_py_btrfs_subvolume_create (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE
extern PyObject *guestfs_int_py_btrfs_subvolume_delete (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT
extern PyObject *guestfs_int_py_btrfs_subvolume_get_default (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST
extern PyObject *guestfs_int_py_btrfs_subvolume_list (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT
extern PyObject *guestfs_int_py_btrfs_subvolume_set_default (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW
extern PyObject *guestfs_int_py_btrfs_subvolume_show (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS
extern PyObject *guestfs_int_py_btrfs_subvolume_snapshot (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS
extern PyObject *guestfs_int_py_btrfstune_enable_extended_inode_refs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS
extern PyObject *guestfs_int_py_btrfstune_enable_skinny_metadata_extent_refs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_SEEDING
extern PyObject *guestfs_int_py_btrfstune_seeding (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_C_POINTER
extern PyObject *guestfs_int_py_c_pointer (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CANONICAL_DEVICE_NAME
extern PyObject *guestfs_int_py_canonical_device_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CAP_GET_FILE
extern PyObject *guestfs_int_py_cap_get_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CAP_SET_FILE
extern PyObject *guestfs_int_py_cap_set_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CASE_SENSITIVE_PATH
extern PyObject *guestfs_int_py_case_sensitive_path (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CAT
extern PyObject *guestfs_int_py_cat (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CHECKSUM
extern PyObject *guestfs_int_py_checksum (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CHECKSUM_DEVICE
extern PyObject *guestfs_int_py_checksum_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CHECKSUMS_OUT
extern PyObject *guestfs_int_py_checksums_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CHMOD
extern PyObject *guestfs_int_py_chmod (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CHOWN
extern PyObject *guestfs_int_py_chown (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CLEAR_BACKEND_SETTING
extern PyObject *guestfs_int_py_clear_backend_setting (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COMMAND
extern PyObject *guestfs_int_py_command (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COMMAND_LINES
extern PyObject *guestfs_int_py_command_lines (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COMPRESS_DEVICE_OUT
extern PyObject *guestfs_int_py_compress_device_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COMPRESS_OUT
extern PyObject *guestfs_int_py_compress_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CONFIG
extern PyObject *guestfs_int_py_config (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_ATTRIBUTES
extern PyObject *guestfs_int_py_copy_attributes (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_DEVICE
extern PyObject *guestfs_int_py_copy_device_to_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_FILE
extern PyObject *guestfs_int_py_copy_device_to_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_DEVICE
extern PyObject *guestfs_int_py_copy_file_to_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_FILE
extern PyObject *guestfs_int_py_copy_file_to_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_IN
extern PyObject *guestfs_int_py_copy_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_OUT
extern PyObject *guestfs_int_py_copy_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_COPY_SIZE
extern PyObject *guestfs_int_py_copy_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CP
extern PyObject *guestfs_int_py_cp (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CP_A
extern PyObject *guestfs_int_py_cp_a (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CP_R
extern PyObject *guestfs_int_py_cp_r (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_CPIO_OUT
extern PyObject *guestfs_int_py_cpio_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DD
extern PyObject *guestfs_int_py_dd (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DEBUG
extern PyObject *guestfs_int_py_debug (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DEBUG_DRIVES
extern PyObject *guestfs_int_py_debug_drives (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DEBUG_UPLOAD
extern PyObject *guestfs_int_py_debug_upload (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DEVICE_INDEX
extern PyObject *guestfs_int_py_device_index (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DF
extern PyObject *guestfs_int_py_df (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DF_H
extern PyObject *guestfs_int_py_df_h (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DISK_CREATE
extern PyObject *guestfs_int_py_disk_create (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DISK_FORMAT
extern PyObject *guestfs_int_py_disk_format (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DISK_HAS_BACKING_FILE
extern PyObject *guestfs_int_py_disk_has_backing_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DISK_VIRTUAL_SIZE
extern PyObject *guestfs_int_py_disk_virtual_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DMESG
extern PyObject *guestfs_int_py_dmesg (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD
extern PyObject *guestfs_int_py_download (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_BLOCKS
extern PyObject *guestfs_int_py_download_blocks (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_INODE
extern PyObject *guestfs_int_py_download_inode (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_OFFSET
extern PyObject *guestfs_int_py_download_offset (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DROP_CACHES
extern PyObject *guestfs_int_py_drop_caches (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_DU
extern PyObject *guestfs_int_py_du (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_E2FSCK
extern PyObject *guestfs_int_py_e2fsck (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_E2FSCK_F
extern PyObject *guestfs_int_py_e2fsck_f (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ECHO_DAEMON
extern PyObject *guestfs_int_py_echo_daemon (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_EGREP
extern PyObject *guestfs_int_py_egrep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_EGREPI
extern PyObject *guestfs_int_py_egrepi (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_EQUAL
extern PyObject *guestfs_int_py_equal (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_EXISTS
extern PyObject *guestfs_int_py_exists (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_EXTLINUX
extern PyObject *guestfs_int_py_extlinux (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FALLOCATE
extern PyObject *guestfs_int_py_fallocate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FALLOCATE64
extern PyObject *guestfs_int_py_fallocate64 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FEATURE_AVAILABLE
extern PyObject *guestfs_int_py_feature_available (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FGREP
extern PyObject *guestfs_int_py_fgrep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FGREPI
extern PyObject *guestfs_int_py_fgrepi (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILE
extern PyObject *guestfs_int_py_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILE_ARCHITECTURE
extern PyObject *guestfs_int_py_file_architecture (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILESIZE
extern PyObject *guestfs_int_py_filesize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILESYSTEM_AVAILABLE
extern PyObject *guestfs_int_py_filesystem_available (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILESYSTEM_WALK
extern PyObject *guestfs_int_py_filesystem_walk (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILL
extern PyObject *guestfs_int_py_fill (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILL_DIR
extern PyObject *guestfs_int_py_fill_dir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FILL_PATTERN
extern PyObject *guestfs_int_py_fill_pattern (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FIND
extern PyObject *guestfs_int_py_find (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FIND0
extern PyObject *guestfs_int_py_find0 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FINDFS_LABEL
extern PyObject *guestfs_int_py_findfs_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FINDFS_UUID
extern PyObject *guestfs_int_py_findfs_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FSCK
extern PyObject *guestfs_int_py_fsck (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_FSTRIM
extern PyObject *guestfs_int_py_fstrim (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_APPEND
extern PyObject *guestfs_int_py_get_append (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_ATTACH_METHOD
extern PyObject *guestfs_int_py_get_attach_method (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_AUTOSYNC
extern PyObject *guestfs_int_py_get_autosync (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND
extern PyObject *guestfs_int_py_get_backend (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTING
extern PyObject *guestfs_int_py_get_backend_setting (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTINGS
extern PyObject *guestfs_int_py_get_backend_settings (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_CACHEDIR
extern PyObject *guestfs_int_py_get_cachedir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_DIRECT
extern PyObject *guestfs_int_py_get_direct (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_E2ATTRS
extern PyObject *guestfs_int_py_get_e2attrs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_E2GENERATION
extern PyObject *guestfs_int_py_get_e2generation (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_E2LABEL
extern PyObject *guestfs_int_py_get_e2label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_E2UUID
extern PyObject *guestfs_int_py_get_e2uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_HV
extern PyObject *guestfs_int_py_get_hv (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_IDENTIFIER
extern PyObject *guestfs_int_py_get_identifier (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE
extern PyObject *guestfs_int_py_get_libvirt_requested_credential_challenge (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT
extern PyObject *guestfs_int_py_get_libvirt_requested_credential_defresult (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT
extern PyObject *guestfs_int_py_get_libvirt_requested_credential_prompt (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS
extern PyObject *guestfs_int_py_get_libvirt_requested_credentials (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_MEMSIZE
extern PyObject *guestfs_int_py_get_memsize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_NETWORK
extern PyObject *guestfs_int_py_get_network (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_PATH
extern PyObject *guestfs_int_py_get_path (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_PGROUP
extern PyObject *guestfs_int_py_get_pgroup (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_PID
extern PyObject *guestfs_int_py_get_pid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_PROGRAM
extern PyObject *guestfs_int_py_get_program (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_QEMU
extern PyObject *guestfs_int_py_get_qemu (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_RECOVERY_PROC
extern PyObject *guestfs_int_py_get_recovery_proc (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_SELINUX
extern PyObject *guestfs_int_py_get_selinux (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_SMP
extern PyObject *guestfs_int_py_get_smp (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_SOCKDIR
extern PyObject *guestfs_int_py_get_sockdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_STATE
extern PyObject *guestfs_int_py_get_state (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_TMPDIR
extern PyObject *guestfs_int_py_get_tmpdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_TRACE
extern PyObject *guestfs_int_py_get_trace (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_UMASK
extern PyObject *guestfs_int_py_get_umask (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GET_VERBOSE
extern PyObject *guestfs_int_py_get_verbose (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GETCON
extern PyObject *guestfs_int_py_getcon (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GETXATTR
extern PyObject *guestfs_int_py_getxattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GETXATTRS
extern PyObject *guestfs_int_py_getxattrs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GLOB_EXPAND_OPTS
extern PyObject *guestfs_int_py_glob_expand (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GREP_OPTS
extern PyObject *guestfs_int_py_grep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GREPI
extern PyObject *guestfs_int_py_grepi (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_GRUB_INSTALL
extern PyObject *guestfs_int_py_grub_install (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HEAD
extern PyObject *guestfs_int_py_head (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HEAD_N
extern PyObject *guestfs_int_py_head_n (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HEXDUMP
extern PyObject *guestfs_int_py_hexdump (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_CLOSE
extern PyObject *guestfs_int_py_hivex_close (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_COMMIT
extern PyObject *guestfs_int_py_hivex_commit (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD
extern PyObject *guestfs_int_py_hivex_node_add_child (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_CHILDREN
extern PyObject *guestfs_int_py_hivex_node_children (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD
extern PyObject *guestfs_int_py_hivex_node_delete_child (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_CHILD
extern PyObject *guestfs_int_py_hivex_node_get_child (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_VALUE
extern PyObject *guestfs_int_py_hivex_node_get_value (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_NAME
extern PyObject *guestfs_int_py_hivex_node_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_PARENT
extern PyObject *guestfs_int_py_hivex_node_parent (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_SET_VALUE
extern PyObject *guestfs_int_py_hivex_node_set_value (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_VALUES
extern PyObject *guestfs_int_py_hivex_node_values (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_OPEN
extern PyObject *guestfs_int_py_hivex_open (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_ROOT
extern PyObject *guestfs_int_py_hivex_root (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_KEY
extern PyObject *guestfs_int_py_hivex_value_key (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_TYPE
extern PyObject *guestfs_int_py_hivex_value_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_UTF8
extern PyObject *guestfs_int_py_hivex_value_utf8 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_VALUE
extern PyObject *guestfs_int_py_hivex_value_value (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INITRD_CAT
extern PyObject *guestfs_int_py_initrd_cat (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INITRD_LIST
extern PyObject *guestfs_int_py_initrd_list (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_ADD_WATCH
extern PyObject *guestfs_int_py_inotify_add_watch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_CLOSE
extern PyObject *guestfs_int_py_inotify_close (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_FILES
extern PyObject *guestfs_int_py_inotify_files (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_INIT
extern PyObject *guestfs_int_py_inotify_init (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_READ
extern PyObject *guestfs_int_py_inotify_read (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INOTIFY_RM_WATCH
extern PyObject *guestfs_int_py_inotify_rm_watch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ARCH
extern PyObject *guestfs_int_py_inspect_get_arch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DISTRO
extern PyObject *guestfs_int_py_inspect_get_distro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS
extern PyObject *guestfs_int_py_inspect_get_drive_mappings (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS
extern PyObject *guestfs_int_py_inspect_get_filesystems (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FORMAT
extern PyObject *guestfs_int_py_inspect_get_format (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_HOSTNAME
extern PyObject *guestfs_int_py_inspect_get_hostname (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ICON
extern PyObject *guestfs_int_py_inspect_get_icon (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION
extern PyObject *guestfs_int_py_inspect_get_major_version (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION
extern PyObject *guestfs_int_py_inspect_get_minor_version (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS
extern PyObject *guestfs_int_py_inspect_get_mountpoints (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT
extern PyObject *guestfs_int_py_inspect_get_package_format (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT
extern PyObject *guestfs_int_py_inspect_get_package_management (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME
extern PyObject *guestfs_int_py_inspect_get_product_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT
extern PyObject *guestfs_int_py_inspect_get_product_variant (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ROOTS
extern PyObject *guestfs_int_py_inspect_get_roots (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_TYPE
extern PyObject *guestfs_int_py_inspect_get_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET
extern PyObject *guestfs_int_py_inspect_get_windows_current_control_set (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT
extern PyObject *guestfs_int_py_inspect_get_windows_systemroot (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_LIVE
extern PyObject *guestfs_int_py_inspect_is_live (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_MULTIPART
extern PyObject *guestfs_int_py_inspect_is_multipart (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_NETINST
extern PyObject *guestfs_int_py_inspect_is_netinst (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS
extern PyObject *guestfs_int_py_inspect_list_applications (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2
extern PyObject *guestfs_int_py_inspect_list_applications2 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INSPECT_OS
extern PyObject *guestfs_int_py_inspect_os (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_EXIT
extern PyObject *guestfs_int_py_internal_exit (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST
extern PyObject *guestfs_int_py_internal_test (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_63_OPTARGS
extern PyObject *guestfs_int_py_internal_test_63_optargs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT
extern PyObject *guestfs_int_py_internal_test_close_output (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS
extern PyObject *guestfs_int_py_internal_test_only_optargs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOL
extern PyObject *guestfs_int_py_internal_test_rbool (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR
extern PyObject *guestfs_int_py_internal_test_rboolerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT
extern PyObject *guestfs_int_py_internal_test_rbufferout (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR
extern PyObject *guestfs_int_py_internal_test_rbufferouterr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING
extern PyObject *guestfs_int_py_internal_test_rconstoptstring (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR
extern PyObject *guestfs_int_py_internal_test_rconstoptstringerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRING
extern PyObject *guestfs_int_py_internal_test_rconststring (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR
extern PyObject *guestfs_int_py_internal_test_rconststringerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE
extern PyObject *guestfs_int_py_internal_test_rhashtable (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR
extern PyObject *guestfs_int_py_internal_test_rhashtableerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT
extern PyObject *guestfs_int_py_internal_test_rint (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64
extern PyObject *guestfs_int_py_internal_test_rint64 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64ERR
extern PyObject *guestfs_int_py_internal_test_rint64err (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINTERR
extern PyObject *guestfs_int_py_internal_test_rinterr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRING
extern PyObject *guestfs_int_py_internal_test_rstring (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR
extern PyObject *guestfs_int_py_internal_test_rstringerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST
extern PyObject *guestfs_int_py_internal_test_rstringlist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR
extern PyObject *guestfs_int_py_internal_test_rstringlisterr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCT
extern PyObject *guestfs_int_py_internal_test_rstruct (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR
extern PyObject *guestfs_int_py_internal_test_rstructerr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST
extern PyObject *guestfs_int_py_internal_test_rstructlist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR
extern PyObject *guestfs_int_py_internal_test_rstructlisterr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT
extern PyObject *guestfs_int_py_internal_test_set_output (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_BLOCKDEV_OPTS
extern PyObject *guestfs_int_py_is_blockdev (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_BUSY
extern PyObject *guestfs_int_py_is_busy (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_CHARDEV_OPTS
extern PyObject *guestfs_int_py_is_chardev (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_CONFIG
extern PyObject *guestfs_int_py_is_config (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_DIR_OPTS
extern PyObject *guestfs_int_py_is_dir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_FIFO_OPTS
extern PyObject *guestfs_int_py_is_fifo (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_FILE_OPTS
extern PyObject *guestfs_int_py_is_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_LAUNCHING
extern PyObject *guestfs_int_py_is_launching (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_LV
extern PyObject *guestfs_int_py_is_lv (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_READY
extern PyObject *guestfs_int_py_is_ready (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_SOCKET_OPTS
extern PyObject *guestfs_int_py_is_socket (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_SYMLINK
extern PyObject *guestfs_int_py_is_symlink (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_WHOLE_DEVICE
extern PyObject *guestfs_int_py_is_whole_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_ZERO
extern PyObject *guestfs_int_py_is_zero (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_IS_ZERO_DEVICE
extern PyObject *guestfs_int_py_is_zero_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ISOINFO
extern PyObject *guestfs_int_py_isoinfo (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ISOINFO_DEVICE
extern PyObject *guestfs_int_py_isoinfo_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_CLOSE
extern PyObject *guestfs_int_py_journal_close (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET
extern PyObject *guestfs_int_py_journal_get (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD
extern PyObject *guestfs_int_py_journal_get_data_threshold (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC
extern PyObject *guestfs_int_py_journal_get_realtime_usec (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_NEXT
extern PyObject *guestfs_int_py_journal_next (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_OPEN
extern PyObject *guestfs_int_py_journal_open (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD
extern PyObject *guestfs_int_py_journal_set_data_threshold (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SKIP
extern PyObject *guestfs_int_py_journal_skip (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_KILL_SUBPROCESS
extern PyObject *guestfs_int_py_kill_subprocess (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LAUNCH
extern PyObject *guestfs_int_py_launch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LCHOWN
extern PyObject *guestfs_int_py_lchown (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_CREATE_ALL
extern PyObject *guestfs_int_py_ldmtool_create_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS
extern PyObject *guestfs_int_py_ldmtool_diskgroup_disks (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME
extern PyObject *guestfs_int_py_ldmtool_diskgroup_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES
extern PyObject *guestfs_int_py_ldmtool_diskgroup_volumes (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_REMOVE_ALL
extern PyObject *guestfs_int_py_ldmtool_remove_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN
extern PyObject *guestfs_int_py_ldmtool_scan (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES
extern PyObject *guestfs_int_py_ldmtool_scan_devices (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_HINT
extern PyObject *guestfs_int_py_ldmtool_volume_hint (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS
extern PyObject *guestfs_int_py_ldmtool_volume_partitions (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE
extern PyObject *guestfs_int_py_ldmtool_volume_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LGETXATTR
extern PyObject *guestfs_int_py_lgetxattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LGETXATTRS
extern PyObject *guestfs_int_py_lgetxattrs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_9P
extern PyObject *guestfs_int_py_list_9p (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_DEVICES
extern PyObject *guestfs_int_py_list_devices (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_DISK_LABELS
extern PyObject *guestfs_int_py_list_disk_labels (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_DM_DEVICES
extern PyObject *guestfs_int_py_list_dm_devices (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_FILESYSTEMS
extern PyObject *guestfs_int_py_list_filesystems (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_PARTITIONS
extern PyObject *guestfs_int_py_list_ldm_partitions (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_VOLUMES
extern PyObject *guestfs_int_py_list_ldm_volumes (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_MD_DEVICES
extern PyObject *guestfs_int_py_list_md_devices (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LIST_PARTITIONS
extern PyObject *guestfs_int_py_list_partitions (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LL
extern PyObject *guestfs_int_py_ll (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LLZ
extern PyObject *guestfs_int_py_llz (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LN
extern PyObject *guestfs_int_py_ln (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LN_F
extern PyObject *guestfs_int_py_ln_f (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LN_S
extern PyObject *guestfs_int_py_ln_s (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LN_SF
extern PyObject *guestfs_int_py_ln_sf (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LREMOVEXATTR
extern PyObject *guestfs_int_py_lremovexattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LS
extern PyObject *guestfs_int_py_ls (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LS0
extern PyObject *guestfs_int_py_ls0 (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LSETXATTR
extern PyObject *guestfs_int_py_lsetxattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LSTAT
extern PyObject *guestfs_int_py_lstat (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LSTATLIST
extern PyObject *guestfs_int_py_lstatlist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LSTATNS
extern PyObject *guestfs_int_py_lstatns (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LSTATNSLIST
extern PyObject *guestfs_int_py_lstatnslist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_ADD_KEY
extern PyObject *guestfs_int_py_luks_add_key (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_CLOSE
extern PyObject *guestfs_int_py_luks_close (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT
extern PyObject *guestfs_int_py_luks_format (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT_CIPHER
extern PyObject *guestfs_int_py_luks_format_cipher (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_KILL_SLOT
extern PyObject *guestfs_int_py_luks_kill_slot (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN
extern PyObject *guestfs_int_py_luks_open (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN_RO
extern PyObject *guestfs_int_py_luks_open_ro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVCREATE
extern PyObject *guestfs_int_py_lvcreate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVCREATE_FREE
extern PyObject *guestfs_int_py_lvcreate_free (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVM_CANONICAL_LV_NAME
extern PyObject *guestfs_int_py_lvm_canonical_lv_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVM_CLEAR_FILTER
extern PyObject *guestfs_int_py_lvm_clear_filter (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVM_REMOVE_ALL
extern PyObject *guestfs_int_py_lvm_remove_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVM_SET_FILTER
extern PyObject *guestfs_int_py_lvm_set_filter (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVREMOVE
extern PyObject *guestfs_int_py_lvremove (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVRENAME
extern PyObject *guestfs_int_py_lvrename (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVRESIZE
extern PyObject *guestfs_int_py_lvresize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVRESIZE_FREE
extern PyObject *guestfs_int_py_lvresize_free (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVS
extern PyObject *guestfs_int_py_lvs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVS_FULL
extern PyObject *guestfs_int_py_lvs_full (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LVUUID
extern PyObject *guestfs_int_py_lvuuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_LXATTRLIST
extern PyObject *guestfs_int_py_lxattrlist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MAX_DISKS
extern PyObject *guestfs_int_py_max_disks (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MD_CREATE
extern PyObject *guestfs_int_py_md_create (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MD_DETAIL
extern PyObject *guestfs_int_py_md_detail (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MD_STAT
extern PyObject *guestfs_int_py_md_stat (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MD_STOP
extern PyObject *guestfs_int_py_md_stop (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKDIR
extern PyObject *guestfs_int_py_mkdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKDIR_MODE
extern PyObject *guestfs_int_py_mkdir_mode (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKDIR_P
extern PyObject *guestfs_int_py_mkdir_p (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKDTEMP
extern PyObject *guestfs_int_py_mkdtemp (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2FS
extern PyObject *guestfs_int_py_mke2fs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2FS_J
extern PyObject *guestfs_int_py_mke2fs_J (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JL
extern PyObject *guestfs_int_py_mke2fs_JL (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JU
extern PyObject *guestfs_int_py_mke2fs_JU (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL
extern PyObject *guestfs_int_py_mke2journal (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_L
extern PyObject *guestfs_int_py_mke2journal_L (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_U
extern PyObject *guestfs_int_py_mke2journal_U (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKFIFO
extern PyObject *guestfs_int_py_mkfifo (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKFS_OPTS
extern PyObject *guestfs_int_py_mkfs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKFS_B
extern PyObject *guestfs_int_py_mkfs_b (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKFS_BTRFS
extern PyObject *guestfs_int_py_mkfs_btrfs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKLOST_AND_FOUND
extern PyObject *guestfs_int_py_mklost_and_found (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKMOUNTPOINT
extern PyObject *guestfs_int_py_mkmountpoint (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKNOD
extern PyObject *guestfs_int_py_mknod (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKNOD_B
extern PyObject *guestfs_int_py_mknod_b (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKNOD_C
extern PyObject *guestfs_int_py_mknod_c (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKSWAP_OPTS
extern PyObject *guestfs_int_py_mkswap (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKSWAP_L
extern PyObject *guestfs_int_py_mkswap_L (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKSWAP_U
extern PyObject *guestfs_int_py_mkswap_U (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKSWAP_FILE
extern PyObject *guestfs_int_py_mkswap_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MKTEMP
extern PyObject *guestfs_int_py_mktemp (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MODPROBE
extern PyObject *guestfs_int_py_modprobe (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT
extern PyObject *guestfs_int_py_mount (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_9P
extern PyObject *guestfs_int_py_mount_9p (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL
extern PyObject *guestfs_int_py_mount_local (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL_RUN
extern PyObject *guestfs_int_py_mount_local_run (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOOP
extern PyObject *guestfs_int_py_mount_loop (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_OPTIONS
extern PyObject *guestfs_int_py_mount_options (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_RO
extern PyObject *guestfs_int_py_mount_ro (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNT_VFS
extern PyObject *guestfs_int_py_mount_vfs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNTABLE_DEVICE
extern PyObject *guestfs_int_py_mountable_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNTABLE_SUBVOLUME
extern PyObject *guestfs_int_py_mountable_subvolume (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNTPOINTS
extern PyObject *guestfs_int_py_mountpoints (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MOUNTS
extern PyObject *guestfs_int_py_mounts (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_MV
extern PyObject *guestfs_int_py_mv (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NR_DEVICES
extern PyObject *guestfs_int_py_nr_devices (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFS_3G_PROBE
extern PyObject *guestfs_int_py_ntfs_3g_probe (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSCAT_I
extern PyObject *guestfs_int_py_ntfscat_i (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_IN
extern PyObject *guestfs_int_py_ntfsclone_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_OUT
extern PyObject *guestfs_int_py_ntfsclone_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSFIX
extern PyObject *guestfs_int_py_ntfsfix (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_OPTS
extern PyObject *guestfs_int_py_ntfsresize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_SIZE
extern PyObject *guestfs_int_py_ntfsresize_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT
extern PyObject *guestfs_int_py_parse_environment (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST
extern PyObject *guestfs_int_py_parse_environment_list (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_ADD
extern PyObject *guestfs_int_py_part_add (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_DEL
extern PyObject *guestfs_int_py_part_del (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_DISK
extern PyObject *guestfs_int_py_part_disk (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_EXPAND_GPT
extern PyObject *guestfs_int_py_part_expand_gpt (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_BOOTABLE
extern PyObject *guestfs_int_py_part_get_bootable (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_DISK_GUID
extern PyObject *guestfs_int_py_part_get_disk_guid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_GUID
extern PyObject *guestfs_int_py_part_get_gpt_guid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_TYPE
extern PyObject *guestfs_int_py_part_get_gpt_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_ID
extern PyObject *guestfs_int_py_part_get_mbr_id (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_PART_TYPE
extern PyObject *guestfs_int_py_part_get_mbr_part_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_NAME
extern PyObject *guestfs_int_py_part_get_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_GET_PARTTYPE
extern PyObject *guestfs_int_py_part_get_parttype (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_INIT
extern PyObject *guestfs_int_py_part_init (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_LIST
extern PyObject *guestfs_int_py_part_list (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_BOOTABLE
extern PyObject *guestfs_int_py_part_set_bootable (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID
extern PyObject *guestfs_int_py_part_set_disk_guid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID_RANDOM
extern PyObject *guestfs_int_py_part_set_disk_guid_random (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_GUID
extern PyObject *guestfs_int_py_part_set_gpt_guid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_TYPE
extern PyObject *guestfs_int_py_part_set_gpt_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_MBR_ID
extern PyObject *guestfs_int_py_part_set_mbr_id (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_SET_NAME
extern PyObject *guestfs_int_py_part_set_name (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_TO_DEV
extern PyObject *guestfs_int_py_part_to_dev (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PART_TO_PARTNUM
extern PyObject *guestfs_int_py_part_to_partnum (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PING_DAEMON
extern PyObject *guestfs_int_py_ping_daemon (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PREAD
extern PyObject *guestfs_int_py_pread (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PREAD_DEVICE
extern PyObject *guestfs_int_py_pread_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID
extern PyObject *guestfs_int_py_pvchange_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID_ALL
extern PyObject *guestfs_int_py_pvchange_uuid_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVCREATE
extern PyObject *guestfs_int_py_pvcreate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVREMOVE
extern PyObject *guestfs_int_py_pvremove (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVRESIZE
extern PyObject *guestfs_int_py_pvresize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVRESIZE_SIZE
extern PyObject *guestfs_int_py_pvresize_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVS
extern PyObject *guestfs_int_py_pvs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVS_FULL
extern PyObject *guestfs_int_py_pvs_full (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PVUUID
extern PyObject *guestfs_int_py_pvuuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PWRITE
extern PyObject *guestfs_int_py_pwrite (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_PWRITE_DEVICE
extern PyObject *guestfs_int_py_pwrite_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_READ_FILE
extern PyObject *guestfs_int_py_read_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_READ_LINES
extern PyObject *guestfs_int_py_read_lines (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_READDIR
extern PyObject *guestfs_int_py_readdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_READLINK
extern PyObject *guestfs_int_py_readlink (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_READLINKLIST
extern PyObject *guestfs_int_py_readlinklist (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_REALPATH
extern PyObject *guestfs_int_py_realpath (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_REMOUNT
extern PyObject *guestfs_int_py_remount (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_REMOVE_DRIVE
extern PyObject *guestfs_int_py_remove_drive (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_REMOVEXATTR
extern PyObject *guestfs_int_py_removexattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RENAME
extern PyObject *guestfs_int_py_rename (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS
extern PyObject *guestfs_int_py_resize2fs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_M
extern PyObject *guestfs_int_py_resize2fs_M (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_SIZE
extern PyObject *guestfs_int_py_resize2fs_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RM
extern PyObject *guestfs_int_py_rm (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RM_F
extern PyObject *guestfs_int_py_rm_f (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RM_RF
extern PyObject *guestfs_int_py_rm_rf (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RMDIR
extern PyObject *guestfs_int_py_rmdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RMMOUNTPOINT
extern PyObject *guestfs_int_py_rmmountpoint (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RSYNC
extern PyObject *guestfs_int_py_rsync (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RSYNC_IN
extern PyObject *guestfs_int_py_rsync_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_RSYNC_OUT
extern PyObject *guestfs_int_py_rsync_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SCRUB_DEVICE
extern PyObject *guestfs_int_py_scrub_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SCRUB_FILE
extern PyObject *guestfs_int_py_scrub_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SCRUB_FREESPACE
extern PyObject *guestfs_int_py_scrub_freespace (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SELINUX_RELABEL
extern PyObject *guestfs_int_py_selinux_relabel (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_APPEND
extern PyObject *guestfs_int_py_set_append (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_ATTACH_METHOD
extern PyObject *guestfs_int_py_set_attach_method (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_AUTOSYNC
extern PyObject *guestfs_int_py_set_autosync (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND
extern PyObject *guestfs_int_py_set_backend (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTING
extern PyObject *guestfs_int_py_set_backend_setting (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTINGS
extern PyObject *guestfs_int_py_set_backend_settings (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_CACHEDIR
extern PyObject *guestfs_int_py_set_cachedir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_DIRECT
extern PyObject *guestfs_int_py_set_direct (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_E2ATTRS
extern PyObject *guestfs_int_py_set_e2attrs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_E2GENERATION
extern PyObject *guestfs_int_py_set_e2generation (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_E2LABEL
extern PyObject *guestfs_int_py_set_e2label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_E2UUID
extern PyObject *guestfs_int_py_set_e2uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_HV
extern PyObject *guestfs_int_py_set_hv (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_IDENTIFIER
extern PyObject *guestfs_int_py_set_identifier (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_LABEL
extern PyObject *guestfs_int_py_set_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL
extern PyObject *guestfs_int_py_set_libvirt_requested_credential (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS
extern PyObject *guestfs_int_py_set_libvirt_supported_credentials (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_MEMSIZE
extern PyObject *guestfs_int_py_set_memsize (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_NETWORK
extern PyObject *guestfs_int_py_set_network (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_PATH
extern PyObject *guestfs_int_py_set_path (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_PGROUP
extern PyObject *guestfs_int_py_set_pgroup (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_PROGRAM
extern PyObject *guestfs_int_py_set_program (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_QEMU
extern PyObject *guestfs_int_py_set_qemu (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_RECOVERY_PROC
extern PyObject *guestfs_int_py_set_recovery_proc (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_SELINUX
extern PyObject *guestfs_int_py_set_selinux (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_SMP
extern PyObject *guestfs_int_py_set_smp (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_TMPDIR
extern PyObject *guestfs_int_py_set_tmpdir (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_TRACE
extern PyObject *guestfs_int_py_set_trace (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_UUID
extern PyObject *guestfs_int_py_set_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_UUID_RANDOM
extern PyObject *guestfs_int_py_set_uuid_random (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SET_VERBOSE
extern PyObject *guestfs_int_py_set_verbose (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SETCON
extern PyObject *guestfs_int_py_setcon (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SETXATTR
extern PyObject *guestfs_int_py_setxattr (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISK
extern PyObject *guestfs_int_py_sfdisk (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISKM
extern PyObject *guestfs_int_py_sfdiskM (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISK_N
extern PyObject *guestfs_int_py_sfdisk_N (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISK_DISK_GEOMETRY
extern PyObject *guestfs_int_py_sfdisk_disk_geometry (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY
extern PyObject *guestfs_int_py_sfdisk_kernel_geometry (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SFDISK_L
extern PyObject *guestfs_int_py_sfdisk_l (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SH
extern PyObject *guestfs_int_py_sh (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SH_LINES
extern PyObject *guestfs_int_py_sh_lines (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SHUTDOWN
extern PyObject *guestfs_int_py_shutdown (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SLEEP
extern PyObject *guestfs_int_py_sleep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_STAT
extern PyObject *guestfs_int_py_stat (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_STATNS
extern PyObject *guestfs_int_py_statns (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_STATVFS
extern PyObject *guestfs_int_py_statvfs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_STRINGS
extern PyObject *guestfs_int_py_strings (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_STRINGS_E
extern PyObject *guestfs_int_py_strings_e (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_DEVICE
extern PyObject *guestfs_int_py_swapoff_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_FILE
extern PyObject *guestfs_int_py_swapoff_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_LABEL
extern PyObject *guestfs_int_py_swapoff_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_UUID
extern PyObject *guestfs_int_py_swapoff_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPON_DEVICE
extern PyObject *guestfs_int_py_swapon_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPON_FILE
extern PyObject *guestfs_int_py_swapon_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPON_LABEL
extern PyObject *guestfs_int_py_swapon_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SWAPON_UUID
extern PyObject *guestfs_int_py_swapon_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SYNC
extern PyObject *guestfs_int_py_sync (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_SYSLINUX
extern PyObject *guestfs_int_py_syslinux (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TAIL
extern PyObject *guestfs_int_py_tail (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TAIL_N
extern PyObject *guestfs_int_py_tail_n (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TAR_IN_OPTS
extern PyObject *guestfs_int_py_tar_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TAR_OUT_OPTS
extern PyObject *guestfs_int_py_tar_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TGZ_IN
extern PyObject *guestfs_int_py_tgz_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TGZ_OUT
extern PyObject *guestfs_int_py_tgz_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TOUCH
extern PyObject *guestfs_int_py_touch (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TRUNCATE
extern PyObject *guestfs_int_py_truncate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TRUNCATE_SIZE
extern PyObject *guestfs_int_py_truncate_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TUNE2FS
extern PyObject *guestfs_int_py_tune2fs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TUNE2FS_L
extern PyObject *guestfs_int_py_tune2fs_l (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TXZ_IN
extern PyObject *guestfs_int_py_txz_in (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_TXZ_OUT
extern PyObject *guestfs_int_py_txz_out (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UMASK
extern PyObject *guestfs_int_py_umask (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UMOUNT_OPTS
extern PyObject *guestfs_int_py_umount (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UMOUNT_ALL
extern PyObject *guestfs_int_py_umount_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UMOUNT_LOCAL
extern PyObject *guestfs_int_py_umount_local (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UPLOAD
extern PyObject *guestfs_int_py_upload (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UPLOAD_OFFSET
extern PyObject *guestfs_int_py_upload_offset (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_USER_CANCEL
extern PyObject *guestfs_int_py_user_cancel (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UTIMENS
extern PyObject *guestfs_int_py_utimens (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_UTSNAME
extern PyObject *guestfs_int_py_utsname (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VERSION
extern PyObject *guestfs_int_py_version (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VFS_LABEL
extern PyObject *guestfs_int_py_vfs_label (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VFS_MINIMUM_SIZE
extern PyObject *guestfs_int_py_vfs_minimum_size (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VFS_TYPE
extern PyObject *guestfs_int_py_vfs_type (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VFS_UUID
extern PyObject *guestfs_int_py_vfs_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE
extern PyObject *guestfs_int_py_vg_activate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE_ALL
extern PyObject *guestfs_int_py_vg_activate_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID
extern PyObject *guestfs_int_py_vgchange_uuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID_ALL
extern PyObject *guestfs_int_py_vgchange_uuid_all (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGCREATE
extern PyObject *guestfs_int_py_vgcreate (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGLVUUIDS
extern PyObject *guestfs_int_py_vglvuuids (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGMETA
extern PyObject *guestfs_int_py_vgmeta (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGPVUUIDS
extern PyObject *guestfs_int_py_vgpvuuids (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGREMOVE
extern PyObject *guestfs_int_py_vgremove (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGRENAME
extern PyObject *guestfs_int_py_vgrename (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGS
extern PyObject *guestfs_int_py_vgs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGS_FULL
extern PyObject *guestfs_int_py_vgs_full (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGSCAN
extern PyObject *guestfs_int_py_vgscan (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_VGUUID
extern PyObject *guestfs_int_py_vguuid (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WAIT_READY
extern PyObject *guestfs_int_py_wait_ready (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WC_C
extern PyObject *guestfs_int_py_wc_c (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WC_L
extern PyObject *guestfs_int_py_wc_l (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WC_W
extern PyObject *guestfs_int_py_wc_w (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WIPEFS
extern PyObject *guestfs_int_py_wipefs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WRITE
extern PyObject *guestfs_int_py_write (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WRITE_APPEND
extern PyObject *guestfs_int_py_write_append (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_WRITE_FILE
extern PyObject *guestfs_int_py_write_file (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_XFS_ADMIN
extern PyObject *guestfs_int_py_xfs_admin (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_XFS_GROWFS
extern PyObject *guestfs_int_py_xfs_growfs (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_XFS_INFO
extern PyObject *guestfs_int_py_xfs_info (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_XFS_REPAIR
extern PyObject *guestfs_int_py_xfs_repair (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZEGREP
extern PyObject *guestfs_int_py_zegrep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZEGREPI
extern PyObject *guestfs_int_py_zegrepi (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZERO
extern PyObject *guestfs_int_py_zero (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZERO_DEVICE
extern PyObject *guestfs_int_py_zero_device (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZERO_FREE_SPACE
extern PyObject *guestfs_int_py_zero_free_space (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZEROFREE
extern PyObject *guestfs_int_py_zerofree (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZFGREP
extern PyObject *guestfs_int_py_zfgrep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZFGREPI
extern PyObject *guestfs_int_py_zfgrepi (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZFILE
extern PyObject *guestfs_int_py_zfile (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZGREP
extern PyObject *guestfs_int_py_zgrep (PyObject *self, PyObject *args);
#endif
#ifdef GUESTFS_HAVE_ZGREPI
extern PyObject *guestfs_int_py_zgrepi (PyObject *self, PyObject *args);
#endif

#endif /* GUESTFS_PYTHON_ACTIONS_H_ */
