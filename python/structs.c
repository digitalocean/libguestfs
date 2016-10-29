/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/python.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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

/* This has to be included first, else definitions conflict with
 * glibc header files.  Python is broken.
 */
#define PY_SSIZE_T_CLEAN 1
#include <Python.h>

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "actions.h"

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
PyObject *
guestfs_int_py_put_application (struct guestfs_application *application)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "app_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_name));
#else
                        PyUnicode_FromString (application->app_name));
#endif
  PyDict_SetItemString (dict, "app_display_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_display_name));
#else
                        PyUnicode_FromString (application->app_display_name));
#endif
  PyDict_SetItemString (dict, "app_epoch",
                        PyLong_FromLong (application->app_epoch));
  PyDict_SetItemString (dict, "app_version",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_version));
#else
                        PyUnicode_FromString (application->app_version));
#endif
  PyDict_SetItemString (dict, "app_release",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_release));
#else
                        PyUnicode_FromString (application->app_release));
#endif
  PyDict_SetItemString (dict, "app_install_path",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_install_path));
#else
                        PyUnicode_FromString (application->app_install_path));
#endif
  PyDict_SetItemString (dict, "app_trans_path",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_trans_path));
#else
                        PyUnicode_FromString (application->app_trans_path));
#endif
  PyDict_SetItemString (dict, "app_publisher",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_publisher));
#else
                        PyUnicode_FromString (application->app_publisher));
#endif
  PyDict_SetItemString (dict, "app_url",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_url));
#else
                        PyUnicode_FromString (application->app_url));
#endif
  PyDict_SetItemString (dict, "app_source_package",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_source_package));
#else
                        PyUnicode_FromString (application->app_source_package));
#endif
  PyDict_SetItemString (dict, "app_summary",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_summary));
#else
                        PyUnicode_FromString (application->app_summary));
#endif
  PyDict_SetItemString (dict, "app_description",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application->app_description));
#else
                        PyUnicode_FromString (application->app_description));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION2
PyObject *
guestfs_int_py_put_application2 (struct guestfs_application2 *application2)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "app2_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_name));
#else
                        PyUnicode_FromString (application2->app2_name));
#endif
  PyDict_SetItemString (dict, "app2_display_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_display_name));
#else
                        PyUnicode_FromString (application2->app2_display_name));
#endif
  PyDict_SetItemString (dict, "app2_epoch",
                        PyLong_FromLong (application2->app2_epoch));
  PyDict_SetItemString (dict, "app2_version",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_version));
#else
                        PyUnicode_FromString (application2->app2_version));
#endif
  PyDict_SetItemString (dict, "app2_release",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_release));
#else
                        PyUnicode_FromString (application2->app2_release));
#endif
  PyDict_SetItemString (dict, "app2_arch",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_arch));
#else
                        PyUnicode_FromString (application2->app2_arch));
#endif
  PyDict_SetItemString (dict, "app2_install_path",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_install_path));
#else
                        PyUnicode_FromString (application2->app2_install_path));
#endif
  PyDict_SetItemString (dict, "app2_trans_path",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_trans_path));
#else
                        PyUnicode_FromString (application2->app2_trans_path));
#endif
  PyDict_SetItemString (dict, "app2_publisher",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_publisher));
#else
                        PyUnicode_FromString (application2->app2_publisher));
#endif
  PyDict_SetItemString (dict, "app2_url",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_url));
#else
                        PyUnicode_FromString (application2->app2_url));
#endif
  PyDict_SetItemString (dict, "app2_source_package",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_source_package));
#else
                        PyUnicode_FromString (application2->app2_source_package));
#endif
  PyDict_SetItemString (dict, "app2_summary",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_summary));
#else
                        PyUnicode_FromString (application2->app2_summary));
#endif
  PyDict_SetItemString (dict, "app2_description",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_description));
#else
                        PyUnicode_FromString (application2->app2_description));
#endif
  PyDict_SetItemString (dict, "app2_spare1",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_spare1));
#else
                        PyUnicode_FromString (application2->app2_spare1));
#endif
  PyDict_SetItemString (dict, "app2_spare2",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_spare2));
#else
                        PyUnicode_FromString (application2->app2_spare2));
#endif
  PyDict_SetItemString (dict, "app2_spare3",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_spare3));
#else
                        PyUnicode_FromString (application2->app2_spare3));
#endif
  PyDict_SetItemString (dict, "app2_spare4",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (application2->app2_spare4));
#else
                        PyUnicode_FromString (application2->app2_spare4));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSBALANCE
PyObject *
guestfs_int_py_put_btrfsbalance (struct guestfs_btrfsbalance *btrfsbalance)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "btrfsbalance_status",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (btrfsbalance->btrfsbalance_status));
#else
                        PyUnicode_FromString (btrfsbalance->btrfsbalance_status));
#endif
  PyDict_SetItemString (dict, "btrfsbalance_total",
                        PyLong_FromUnsignedLongLong (btrfsbalance->btrfsbalance_total));
  PyDict_SetItemString (dict, "btrfsbalance_balanced",
                        PyLong_FromUnsignedLongLong (btrfsbalance->btrfsbalance_balanced));
  PyDict_SetItemString (dict, "btrfsbalance_considered",
                        PyLong_FromUnsignedLongLong (btrfsbalance->btrfsbalance_considered));
  PyDict_SetItemString (dict, "btrfsbalance_left",
                        PyLong_FromUnsignedLongLong (btrfsbalance->btrfsbalance_left));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSQGROUP
PyObject *
guestfs_int_py_put_btrfsqgroup (struct guestfs_btrfsqgroup *btrfsqgroup)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "btrfsqgroup_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (btrfsqgroup->btrfsqgroup_id));
#else
                        PyUnicode_FromString (btrfsqgroup->btrfsqgroup_id));
#endif
  PyDict_SetItemString (dict, "btrfsqgroup_rfer",
                        PyLong_FromUnsignedLongLong (btrfsqgroup->btrfsqgroup_rfer));
  PyDict_SetItemString (dict, "btrfsqgroup_excl",
                        PyLong_FromUnsignedLongLong (btrfsqgroup->btrfsqgroup_excl));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSSCRUB
PyObject *
guestfs_int_py_put_btrfsscrub (struct guestfs_btrfsscrub *btrfsscrub)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "btrfsscrub_data_extents_scrubbed",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_data_extents_scrubbed));
  PyDict_SetItemString (dict, "btrfsscrub_tree_extents_scrubbed",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_tree_extents_scrubbed));
  PyDict_SetItemString (dict, "btrfsscrub_data_bytes_scrubbed",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_data_bytes_scrubbed));
  PyDict_SetItemString (dict, "btrfsscrub_tree_bytes_scrubbed",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_tree_bytes_scrubbed));
  PyDict_SetItemString (dict, "btrfsscrub_read_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_read_errors));
  PyDict_SetItemString (dict, "btrfsscrub_csum_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_csum_errors));
  PyDict_SetItemString (dict, "btrfsscrub_verify_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_verify_errors));
  PyDict_SetItemString (dict, "btrfsscrub_no_csum",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_no_csum));
  PyDict_SetItemString (dict, "btrfsscrub_csum_discards",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_csum_discards));
  PyDict_SetItemString (dict, "btrfsscrub_super_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_super_errors));
  PyDict_SetItemString (dict, "btrfsscrub_malloc_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_malloc_errors));
  PyDict_SetItemString (dict, "btrfsscrub_uncorrectable_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_uncorrectable_errors));
  PyDict_SetItemString (dict, "btrfsscrub_unverified_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_unverified_errors));
  PyDict_SetItemString (dict, "btrfsscrub_corrected_errors",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_corrected_errors));
  PyDict_SetItemString (dict, "btrfsscrub_last_physical",
                        PyLong_FromUnsignedLongLong (btrfsscrub->btrfsscrub_last_physical));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME
PyObject *
guestfs_int_py_put_btrfssubvolume (struct guestfs_btrfssubvolume *btrfssubvolume)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "btrfssubvolume_id",
                        PyLong_FromUnsignedLongLong (btrfssubvolume->btrfssubvolume_id));
  PyDict_SetItemString (dict, "btrfssubvolume_top_level_id",
                        PyLong_FromUnsignedLongLong (btrfssubvolume->btrfssubvolume_top_level_id));
  PyDict_SetItemString (dict, "btrfssubvolume_path",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (btrfssubvolume->btrfssubvolume_path));
#else
                        PyUnicode_FromString (btrfssubvolume->btrfssubvolume_path));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_DIRENT
PyObject *
guestfs_int_py_put_dirent (struct guestfs_dirent *dirent)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "ino",
                        PyLong_FromLongLong (dirent->ino));
#ifdef HAVE_PYSTRING_ASSTRING
  PyDict_SetItemString (dict, "ftyp",
                        PyString_FromStringAndSize (&dirent->ftyp, 1));
#else
  PyDict_SetItemString (dict, "ftyp",
                        PyUnicode_FromStringAndSize (&dirent->ftyp, 1));
#endif
  PyDict_SetItemString (dict, "name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (dirent->name));
#else
                        PyUnicode_FromString (dirent->name));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_NODE
PyObject *
guestfs_int_py_put_hivex_node (struct guestfs_hivex_node *hivex_node)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_node_h",
                        PyLong_FromLongLong (hivex_node->hivex_node_h));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
PyObject *
guestfs_int_py_put_hivex_value (struct guestfs_hivex_value *hivex_value)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_value_h",
                        PyLong_FromLongLong (hivex_value->hivex_value_h));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
PyObject *
guestfs_int_py_put_inotify_event (struct guestfs_inotify_event *inotify_event)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "in_wd",
                        PyLong_FromLongLong (inotify_event->in_wd));
  PyDict_SetItemString (dict, "in_mask",
                        PyLong_FromUnsignedLong (inotify_event->in_mask));
  PyDict_SetItemString (dict, "in_cookie",
                        PyLong_FromUnsignedLong (inotify_event->in_cookie));
  PyDict_SetItemString (dict, "in_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (inotify_event->in_name));
#else
                        PyUnicode_FromString (inotify_event->in_name));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_INT_BOOL
PyObject *
guestfs_int_py_put_int_bool (struct guestfs_int_bool *int_bool)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "i",
                        PyLong_FromLong (int_bool->i));
  PyDict_SetItemString (dict, "b",
                        PyLong_FromLong (int_bool->b));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_ISOINFO
PyObject *
guestfs_int_py_put_isoinfo (struct guestfs_isoinfo *isoinfo)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "iso_system_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_system_id));
#else
                        PyUnicode_FromString (isoinfo->iso_system_id));
#endif
  PyDict_SetItemString (dict, "iso_volume_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_volume_id));
#else
                        PyUnicode_FromString (isoinfo->iso_volume_id));
#endif
  PyDict_SetItemString (dict, "iso_volume_space_size",
                        PyLong_FromUnsignedLong (isoinfo->iso_volume_space_size));
  PyDict_SetItemString (dict, "iso_volume_set_size",
                        PyLong_FromUnsignedLong (isoinfo->iso_volume_set_size));
  PyDict_SetItemString (dict, "iso_volume_sequence_number",
                        PyLong_FromUnsignedLong (isoinfo->iso_volume_sequence_number));
  PyDict_SetItemString (dict, "iso_logical_block_size",
                        PyLong_FromUnsignedLong (isoinfo->iso_logical_block_size));
  PyDict_SetItemString (dict, "iso_volume_set_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_volume_set_id));
#else
                        PyUnicode_FromString (isoinfo->iso_volume_set_id));
#endif
  PyDict_SetItemString (dict, "iso_publisher_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_publisher_id));
#else
                        PyUnicode_FromString (isoinfo->iso_publisher_id));
#endif
  PyDict_SetItemString (dict, "iso_data_preparer_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_data_preparer_id));
#else
                        PyUnicode_FromString (isoinfo->iso_data_preparer_id));
#endif
  PyDict_SetItemString (dict, "iso_application_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_application_id));
#else
                        PyUnicode_FromString (isoinfo->iso_application_id));
#endif
  PyDict_SetItemString (dict, "iso_copyright_file_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_copyright_file_id));
#else
                        PyUnicode_FromString (isoinfo->iso_copyright_file_id));
#endif
  PyDict_SetItemString (dict, "iso_abstract_file_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_abstract_file_id));
#else
                        PyUnicode_FromString (isoinfo->iso_abstract_file_id));
#endif
  PyDict_SetItemString (dict, "iso_bibliographic_file_id",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (isoinfo->iso_bibliographic_file_id));
#else
                        PyUnicode_FromString (isoinfo->iso_bibliographic_file_id));
#endif
  PyDict_SetItemString (dict, "iso_volume_creation_t",
                        PyLong_FromLongLong (isoinfo->iso_volume_creation_t));
  PyDict_SetItemString (dict, "iso_volume_modification_t",
                        PyLong_FromLongLong (isoinfo->iso_volume_modification_t));
  PyDict_SetItemString (dict, "iso_volume_expiration_t",
                        PyLong_FromLongLong (isoinfo->iso_volume_expiration_t));
  PyDict_SetItemString (dict, "iso_volume_effective_t",
                        PyLong_FromLongLong (isoinfo->iso_volume_effective_t));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_LV
PyObject *
guestfs_int_py_put_lvm_lv (struct guestfs_lvm_lv *lvm_lv)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "lv_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->lv_name));
#else
                        PyUnicode_FromString (lvm_lv->lv_name));
#endif
  PyDict_SetItemString (dict, "lv_uuid",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromStringAndSize (lvm_lv->lv_uuid, 32));
#else
                        PyBytes_FromStringAndSize (lvm_lv->lv_uuid, 32));
#endif
  PyDict_SetItemString (dict, "lv_attr",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->lv_attr));
#else
                        PyUnicode_FromString (lvm_lv->lv_attr));
#endif
  PyDict_SetItemString (dict, "lv_major",
                        PyLong_FromLongLong (lvm_lv->lv_major));
  PyDict_SetItemString (dict, "lv_minor",
                        PyLong_FromLongLong (lvm_lv->lv_minor));
  PyDict_SetItemString (dict, "lv_kernel_major",
                        PyLong_FromLongLong (lvm_lv->lv_kernel_major));
  PyDict_SetItemString (dict, "lv_kernel_minor",
                        PyLong_FromLongLong (lvm_lv->lv_kernel_minor));
  PyDict_SetItemString (dict, "lv_size",
                        PyLong_FromUnsignedLongLong (lvm_lv->lv_size));
  PyDict_SetItemString (dict, "seg_count",
                        PyLong_FromLongLong (lvm_lv->seg_count));
  PyDict_SetItemString (dict, "origin",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->origin));
#else
                        PyUnicode_FromString (lvm_lv->origin));
#endif
  if (lvm_lv->snap_percent >= 0)
    PyDict_SetItemString (dict, "snap_percent",
                          PyFloat_FromDouble ((double) lvm_lv->snap_percent));
  else {
    Py_INCREF (Py_None);
    PyDict_SetItemString (dict, "snap_percent", Py_None);
  }
  if (lvm_lv->copy_percent >= 0)
    PyDict_SetItemString (dict, "copy_percent",
                          PyFloat_FromDouble ((double) lvm_lv->copy_percent));
  else {
    Py_INCREF (Py_None);
    PyDict_SetItemString (dict, "copy_percent", Py_None);
  }
  PyDict_SetItemString (dict, "move_pv",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->move_pv));
#else
                        PyUnicode_FromString (lvm_lv->move_pv));
#endif
  PyDict_SetItemString (dict, "lv_tags",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->lv_tags));
#else
                        PyUnicode_FromString (lvm_lv->lv_tags));
#endif
  PyDict_SetItemString (dict, "mirror_log",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->mirror_log));
#else
                        PyUnicode_FromString (lvm_lv->mirror_log));
#endif
  PyDict_SetItemString (dict, "modules",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_lv->modules));
#else
                        PyUnicode_FromString (lvm_lv->modules));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_PV
PyObject *
guestfs_int_py_put_lvm_pv (struct guestfs_lvm_pv *lvm_pv)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "pv_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_pv->pv_name));
#else
                        PyUnicode_FromString (lvm_pv->pv_name));
#endif
  PyDict_SetItemString (dict, "pv_uuid",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromStringAndSize (lvm_pv->pv_uuid, 32));
#else
                        PyBytes_FromStringAndSize (lvm_pv->pv_uuid, 32));
#endif
  PyDict_SetItemString (dict, "pv_fmt",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_pv->pv_fmt));
#else
                        PyUnicode_FromString (lvm_pv->pv_fmt));
#endif
  PyDict_SetItemString (dict, "pv_size",
                        PyLong_FromUnsignedLongLong (lvm_pv->pv_size));
  PyDict_SetItemString (dict, "dev_size",
                        PyLong_FromUnsignedLongLong (lvm_pv->dev_size));
  PyDict_SetItemString (dict, "pv_free",
                        PyLong_FromUnsignedLongLong (lvm_pv->pv_free));
  PyDict_SetItemString (dict, "pv_used",
                        PyLong_FromUnsignedLongLong (lvm_pv->pv_used));
  PyDict_SetItemString (dict, "pv_attr",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_pv->pv_attr));
#else
                        PyUnicode_FromString (lvm_pv->pv_attr));
#endif
  PyDict_SetItemString (dict, "pv_pe_count",
                        PyLong_FromLongLong (lvm_pv->pv_pe_count));
  PyDict_SetItemString (dict, "pv_pe_alloc_count",
                        PyLong_FromLongLong (lvm_pv->pv_pe_alloc_count));
  PyDict_SetItemString (dict, "pv_tags",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_pv->pv_tags));
#else
                        PyUnicode_FromString (lvm_pv->pv_tags));
#endif
  PyDict_SetItemString (dict, "pe_start",
                        PyLong_FromUnsignedLongLong (lvm_pv->pe_start));
  PyDict_SetItemString (dict, "pv_mda_count",
                        PyLong_FromLongLong (lvm_pv->pv_mda_count));
  PyDict_SetItemString (dict, "pv_mda_free",
                        PyLong_FromUnsignedLongLong (lvm_pv->pv_mda_free));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_VG
PyObject *
guestfs_int_py_put_lvm_vg (struct guestfs_lvm_vg *lvm_vg)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "vg_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_vg->vg_name));
#else
                        PyUnicode_FromString (lvm_vg->vg_name));
#endif
  PyDict_SetItemString (dict, "vg_uuid",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromStringAndSize (lvm_vg->vg_uuid, 32));
#else
                        PyBytes_FromStringAndSize (lvm_vg->vg_uuid, 32));
#endif
  PyDict_SetItemString (dict, "vg_fmt",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_vg->vg_fmt));
#else
                        PyUnicode_FromString (lvm_vg->vg_fmt));
#endif
  PyDict_SetItemString (dict, "vg_attr",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_vg->vg_attr));
#else
                        PyUnicode_FromString (lvm_vg->vg_attr));
#endif
  PyDict_SetItemString (dict, "vg_size",
                        PyLong_FromUnsignedLongLong (lvm_vg->vg_size));
  PyDict_SetItemString (dict, "vg_free",
                        PyLong_FromUnsignedLongLong (lvm_vg->vg_free));
  PyDict_SetItemString (dict, "vg_sysid",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_vg->vg_sysid));
#else
                        PyUnicode_FromString (lvm_vg->vg_sysid));
#endif
  PyDict_SetItemString (dict, "vg_extent_size",
                        PyLong_FromUnsignedLongLong (lvm_vg->vg_extent_size));
  PyDict_SetItemString (dict, "vg_extent_count",
                        PyLong_FromLongLong (lvm_vg->vg_extent_count));
  PyDict_SetItemString (dict, "vg_free_count",
                        PyLong_FromLongLong (lvm_vg->vg_free_count));
  PyDict_SetItemString (dict, "max_lv",
                        PyLong_FromLongLong (lvm_vg->max_lv));
  PyDict_SetItemString (dict, "max_pv",
                        PyLong_FromLongLong (lvm_vg->max_pv));
  PyDict_SetItemString (dict, "pv_count",
                        PyLong_FromLongLong (lvm_vg->pv_count));
  PyDict_SetItemString (dict, "lv_count",
                        PyLong_FromLongLong (lvm_vg->lv_count));
  PyDict_SetItemString (dict, "snap_count",
                        PyLong_FromLongLong (lvm_vg->snap_count));
  PyDict_SetItemString (dict, "vg_seqno",
                        PyLong_FromLongLong (lvm_vg->vg_seqno));
  PyDict_SetItemString (dict, "vg_tags",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (lvm_vg->vg_tags));
#else
                        PyUnicode_FromString (lvm_vg->vg_tags));
#endif
  PyDict_SetItemString (dict, "vg_mda_count",
                        PyLong_FromLongLong (lvm_vg->vg_mda_count));
  PyDict_SetItemString (dict, "vg_mda_free",
                        PyLong_FromUnsignedLongLong (lvm_vg->vg_mda_free));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_MDSTAT
PyObject *
guestfs_int_py_put_mdstat (struct guestfs_mdstat *mdstat)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "mdstat_device",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (mdstat->mdstat_device));
#else
                        PyUnicode_FromString (mdstat->mdstat_device));
#endif
  PyDict_SetItemString (dict, "mdstat_index",
                        PyLong_FromLong (mdstat->mdstat_index));
  PyDict_SetItemString (dict, "mdstat_flags",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (mdstat->mdstat_flags));
#else
                        PyUnicode_FromString (mdstat->mdstat_flags));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_PARTITION
PyObject *
guestfs_int_py_put_partition (struct guestfs_partition *partition)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "part_num",
                        PyLong_FromLong (partition->part_num));
  PyDict_SetItemString (dict, "part_start",
                        PyLong_FromUnsignedLongLong (partition->part_start));
  PyDict_SetItemString (dict, "part_end",
                        PyLong_FromUnsignedLongLong (partition->part_end));
  PyDict_SetItemString (dict, "part_size",
                        PyLong_FromUnsignedLongLong (partition->part_size));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STAT
PyObject *
guestfs_int_py_put_stat (struct guestfs_stat *stat)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "dev",
                        PyLong_FromLongLong (stat->dev));
  PyDict_SetItemString (dict, "ino",
                        PyLong_FromLongLong (stat->ino));
  PyDict_SetItemString (dict, "mode",
                        PyLong_FromLongLong (stat->mode));
  PyDict_SetItemString (dict, "nlink",
                        PyLong_FromLongLong (stat->nlink));
  PyDict_SetItemString (dict, "uid",
                        PyLong_FromLongLong (stat->uid));
  PyDict_SetItemString (dict, "gid",
                        PyLong_FromLongLong (stat->gid));
  PyDict_SetItemString (dict, "rdev",
                        PyLong_FromLongLong (stat->rdev));
  PyDict_SetItemString (dict, "size",
                        PyLong_FromLongLong (stat->size));
  PyDict_SetItemString (dict, "blksize",
                        PyLong_FromLongLong (stat->blksize));
  PyDict_SetItemString (dict, "blocks",
                        PyLong_FromLongLong (stat->blocks));
  PyDict_SetItemString (dict, "atime",
                        PyLong_FromLongLong (stat->atime));
  PyDict_SetItemString (dict, "mtime",
                        PyLong_FromLongLong (stat->mtime));
  PyDict_SetItemString (dict, "ctime",
                        PyLong_FromLongLong (stat->ctime));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STATNS
PyObject *
guestfs_int_py_put_statns (struct guestfs_statns *statns)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "st_dev",
                        PyLong_FromLongLong (statns->st_dev));
  PyDict_SetItemString (dict, "st_ino",
                        PyLong_FromLongLong (statns->st_ino));
  PyDict_SetItemString (dict, "st_mode",
                        PyLong_FromLongLong (statns->st_mode));
  PyDict_SetItemString (dict, "st_nlink",
                        PyLong_FromLongLong (statns->st_nlink));
  PyDict_SetItemString (dict, "st_uid",
                        PyLong_FromLongLong (statns->st_uid));
  PyDict_SetItemString (dict, "st_gid",
                        PyLong_FromLongLong (statns->st_gid));
  PyDict_SetItemString (dict, "st_rdev",
                        PyLong_FromLongLong (statns->st_rdev));
  PyDict_SetItemString (dict, "st_size",
                        PyLong_FromLongLong (statns->st_size));
  PyDict_SetItemString (dict, "st_blksize",
                        PyLong_FromLongLong (statns->st_blksize));
  PyDict_SetItemString (dict, "st_blocks",
                        PyLong_FromLongLong (statns->st_blocks));
  PyDict_SetItemString (dict, "st_atime_sec",
                        PyLong_FromLongLong (statns->st_atime_sec));
  PyDict_SetItemString (dict, "st_atime_nsec",
                        PyLong_FromLongLong (statns->st_atime_nsec));
  PyDict_SetItemString (dict, "st_mtime_sec",
                        PyLong_FromLongLong (statns->st_mtime_sec));
  PyDict_SetItemString (dict, "st_mtime_nsec",
                        PyLong_FromLongLong (statns->st_mtime_nsec));
  PyDict_SetItemString (dict, "st_ctime_sec",
                        PyLong_FromLongLong (statns->st_ctime_sec));
  PyDict_SetItemString (dict, "st_ctime_nsec",
                        PyLong_FromLongLong (statns->st_ctime_nsec));
  PyDict_SetItemString (dict, "st_spare1",
                        PyLong_FromLongLong (statns->st_spare1));
  PyDict_SetItemString (dict, "st_spare2",
                        PyLong_FromLongLong (statns->st_spare2));
  PyDict_SetItemString (dict, "st_spare3",
                        PyLong_FromLongLong (statns->st_spare3));
  PyDict_SetItemString (dict, "st_spare4",
                        PyLong_FromLongLong (statns->st_spare4));
  PyDict_SetItemString (dict, "st_spare5",
                        PyLong_FromLongLong (statns->st_spare5));
  PyDict_SetItemString (dict, "st_spare6",
                        PyLong_FromLongLong (statns->st_spare6));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STATVFS
PyObject *
guestfs_int_py_put_statvfs (struct guestfs_statvfs *statvfs)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "bsize",
                        PyLong_FromLongLong (statvfs->bsize));
  PyDict_SetItemString (dict, "frsize",
                        PyLong_FromLongLong (statvfs->frsize));
  PyDict_SetItemString (dict, "blocks",
                        PyLong_FromLongLong (statvfs->blocks));
  PyDict_SetItemString (dict, "bfree",
                        PyLong_FromLongLong (statvfs->bfree));
  PyDict_SetItemString (dict, "bavail",
                        PyLong_FromLongLong (statvfs->bavail));
  PyDict_SetItemString (dict, "files",
                        PyLong_FromLongLong (statvfs->files));
  PyDict_SetItemString (dict, "ffree",
                        PyLong_FromLongLong (statvfs->ffree));
  PyDict_SetItemString (dict, "favail",
                        PyLong_FromLongLong (statvfs->favail));
  PyDict_SetItemString (dict, "fsid",
                        PyLong_FromLongLong (statvfs->fsid));
  PyDict_SetItemString (dict, "flag",
                        PyLong_FromLongLong (statvfs->flag));
  PyDict_SetItemString (dict, "namemax",
                        PyLong_FromLongLong (statvfs->namemax));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_TSK_DIRENT
PyObject *
guestfs_int_py_put_tsk_dirent (struct guestfs_tsk_dirent *tsk_dirent)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "tsk_inode",
                        PyLong_FromUnsignedLongLong (tsk_dirent->tsk_inode));
#ifdef HAVE_PYSTRING_ASSTRING
  PyDict_SetItemString (dict, "tsk_type",
                        PyString_FromStringAndSize (&tsk_dirent->tsk_type, 1));
#else
  PyDict_SetItemString (dict, "tsk_type",
                        PyUnicode_FromStringAndSize (&tsk_dirent->tsk_type, 1));
#endif
  PyDict_SetItemString (dict, "tsk_size",
                        PyLong_FromLongLong (tsk_dirent->tsk_size));
  PyDict_SetItemString (dict, "tsk_name",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (tsk_dirent->tsk_name));
#else
                        PyUnicode_FromString (tsk_dirent->tsk_name));
#endif
  PyDict_SetItemString (dict, "tsk_flags",
                        PyLong_FromUnsignedLong (tsk_dirent->tsk_flags));
  PyDict_SetItemString (dict, "tsk_atime_sec",
                        PyLong_FromLongLong (tsk_dirent->tsk_atime_sec));
  PyDict_SetItemString (dict, "tsk_atime_nsec",
                        PyLong_FromLongLong (tsk_dirent->tsk_atime_nsec));
  PyDict_SetItemString (dict, "tsk_mtime_sec",
                        PyLong_FromLongLong (tsk_dirent->tsk_mtime_sec));
  PyDict_SetItemString (dict, "tsk_mtime_nsec",
                        PyLong_FromLongLong (tsk_dirent->tsk_mtime_nsec));
  PyDict_SetItemString (dict, "tsk_ctime_sec",
                        PyLong_FromLongLong (tsk_dirent->tsk_ctime_sec));
  PyDict_SetItemString (dict, "tsk_ctime_nsec",
                        PyLong_FromLongLong (tsk_dirent->tsk_ctime_nsec));
  PyDict_SetItemString (dict, "tsk_crtime_sec",
                        PyLong_FromLongLong (tsk_dirent->tsk_crtime_sec));
  PyDict_SetItemString (dict, "tsk_crtime_nsec",
                        PyLong_FromLongLong (tsk_dirent->tsk_crtime_nsec));
  PyDict_SetItemString (dict, "tsk_nlink",
                        PyLong_FromLongLong (tsk_dirent->tsk_nlink));
  PyDict_SetItemString (dict, "tsk_link",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (tsk_dirent->tsk_link));
#else
                        PyUnicode_FromString (tsk_dirent->tsk_link));
#endif
  PyDict_SetItemString (dict, "tsk_spare1",
                        PyLong_FromLongLong (tsk_dirent->tsk_spare1));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_UTSNAME
PyObject *
guestfs_int_py_put_utsname (struct guestfs_utsname *utsname)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "uts_sysname",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (utsname->uts_sysname));
#else
                        PyUnicode_FromString (utsname->uts_sysname));
#endif
  PyDict_SetItemString (dict, "uts_release",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (utsname->uts_release));
#else
                        PyUnicode_FromString (utsname->uts_release));
#endif
  PyDict_SetItemString (dict, "uts_version",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (utsname->uts_version));
#else
                        PyUnicode_FromString (utsname->uts_version));
#endif
  PyDict_SetItemString (dict, "uts_machine",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (utsname->uts_machine));
#else
                        PyUnicode_FromString (utsname->uts_machine));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_VERSION
PyObject *
guestfs_int_py_put_version (struct guestfs_version *version)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "major",
                        PyLong_FromLongLong (version->major));
  PyDict_SetItemString (dict, "minor",
                        PyLong_FromLongLong (version->minor));
  PyDict_SetItemString (dict, "release",
                        PyLong_FromLongLong (version->release));
  PyDict_SetItemString (dict, "extra",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (version->extra));
#else
                        PyUnicode_FromString (version->extra));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_XATTR
PyObject *
guestfs_int_py_put_xattr (struct guestfs_xattr *xattr)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "attrname",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (xattr->attrname));
#else
                        PyUnicode_FromString (xattr->attrname));
#endif
  PyDict_SetItemString (dict, "attrval",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromStringAndSize (xattr->attrval, xattr->attrval_len));
#else
                        PyBytes_FromStringAndSize (xattr->attrval, xattr->attrval_len));
#endif
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_XFSINFO
PyObject *
guestfs_int_py_put_xfsinfo (struct guestfs_xfsinfo *xfsinfo)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "xfs_mntpoint",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (xfsinfo->xfs_mntpoint));
#else
                        PyUnicode_FromString (xfsinfo->xfs_mntpoint));
#endif
  PyDict_SetItemString (dict, "xfs_inodesize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_inodesize));
  PyDict_SetItemString (dict, "xfs_agcount",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_agcount));
  PyDict_SetItemString (dict, "xfs_agsize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_agsize));
  PyDict_SetItemString (dict, "xfs_sectsize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_sectsize));
  PyDict_SetItemString (dict, "xfs_attr",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_attr));
  PyDict_SetItemString (dict, "xfs_blocksize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_blocksize));
  PyDict_SetItemString (dict, "xfs_datablocks",
                        PyLong_FromUnsignedLongLong (xfsinfo->xfs_datablocks));
  PyDict_SetItemString (dict, "xfs_imaxpct",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_imaxpct));
  PyDict_SetItemString (dict, "xfs_sunit",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_sunit));
  PyDict_SetItemString (dict, "xfs_swidth",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_swidth));
  PyDict_SetItemString (dict, "xfs_dirversion",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_dirversion));
  PyDict_SetItemString (dict, "xfs_dirblocksize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_dirblocksize));
  PyDict_SetItemString (dict, "xfs_cimode",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_cimode));
  PyDict_SetItemString (dict, "xfs_logname",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (xfsinfo->xfs_logname));
#else
                        PyUnicode_FromString (xfsinfo->xfs_logname));
#endif
  PyDict_SetItemString (dict, "xfs_logblocksize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_logblocksize));
  PyDict_SetItemString (dict, "xfs_logblocks",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_logblocks));
  PyDict_SetItemString (dict, "xfs_logversion",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_logversion));
  PyDict_SetItemString (dict, "xfs_logsectsize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_logsectsize));
  PyDict_SetItemString (dict, "xfs_logsunit",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_logsunit));
  PyDict_SetItemString (dict, "xfs_lazycount",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_lazycount));
  PyDict_SetItemString (dict, "xfs_rtname",
#ifdef HAVE_PYSTRING_ASSTRING
                        PyString_FromString (xfsinfo->xfs_rtname));
#else
                        PyUnicode_FromString (xfsinfo->xfs_rtname));
#endif
  PyDict_SetItemString (dict, "xfs_rtextsize",
                        PyLong_FromUnsignedLong (xfsinfo->xfs_rtextsize));
  PyDict_SetItemString (dict, "xfs_rtblocks",
                        PyLong_FromUnsignedLongLong (xfsinfo->xfs_rtblocks));
  PyDict_SetItemString (dict, "xfs_rtextents",
                        PyLong_FromUnsignedLongLong (xfsinfo->xfs_rtextents));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_LV
PyObject *
guestfs_int_py_put_lvm_lv_list (struct guestfs_lvm_lv_list *lvm_lvs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_lvs->len);
  for (i = 0; i < lvm_lvs->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_lvm_lv (&lvm_lvs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_DIRENT
PyObject *
guestfs_int_py_put_dirent_list (struct guestfs_dirent_list *dirents)
{
  PyObject *list;
  size_t i;

  list = PyList_New (dirents->len);
  for (i = 0; i < dirents->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_dirent (&dirents->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSQGROUP
PyObject *
guestfs_int_py_put_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *btrfsqgroups)
{
  PyObject *list;
  size_t i;

  list = PyList_New (btrfsqgroups->len);
  for (i = 0; i < btrfsqgroups->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_btrfsqgroup (&btrfsqgroups->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_TSK_DIRENT
PyObject *
guestfs_int_py_put_tsk_dirent_list (struct guestfs_tsk_dirent_list *tsk_dirents)
{
  PyObject *list;
  size_t i;

  list = PyList_New (tsk_dirents->len);
  for (i = 0; i < tsk_dirents->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_tsk_dirent (&tsk_dirents->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_PARTITION
PyObject *
guestfs_int_py_put_partition_list (struct guestfs_partition_list *partitions)
{
  PyObject *list;
  size_t i;

  list = PyList_New (partitions->len);
  for (i = 0; i < partitions->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_partition (&partitions->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STATNS
PyObject *
guestfs_int_py_put_statns_list (struct guestfs_statns_list *statnss)
{
  PyObject *list;
  size_t i;

  list = PyList_New (statnss->len);
  for (i = 0; i < statnss->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_statns (&statnss->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION2
PyObject *
guestfs_int_py_put_application2_list (struct guestfs_application2_list *application2s)
{
  PyObject *list;
  size_t i;

  list = PyList_New (application2s->len);
  for (i = 0; i < application2s->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_application2 (&application2s->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
PyObject *
guestfs_int_py_put_inotify_event_list (struct guestfs_inotify_event_list *inotify_events)
{
  PyObject *list;
  size_t i;

  list = PyList_New (inotify_events->len);
  for (i = 0; i < inotify_events->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_inotify_event (&inotify_events->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
PyObject *
guestfs_int_py_put_application_list (struct guestfs_application_list *applications)
{
  PyObject *list;
  size_t i;

  list = PyList_New (applications->len);
  for (i = 0; i < applications->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_application (&applications->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
PyObject *
guestfs_int_py_put_hivex_value_list (struct guestfs_hivex_value_list *hivex_values)
{
  PyObject *list;
  size_t i;

  list = PyList_New (hivex_values->len);
  for (i = 0; i < hivex_values->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_hivex_value (&hivex_values->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_XATTR
PyObject *
guestfs_int_py_put_xattr_list (struct guestfs_xattr_list *xattrs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (xattrs->len);
  for (i = 0; i < xattrs->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_xattr (&xattrs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_PV
PyObject *
guestfs_int_py_put_lvm_pv_list (struct guestfs_lvm_pv_list *lvm_pvs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_pvs->len);
  for (i = 0; i < lvm_pvs->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_lvm_pv (&lvm_pvs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_VG
PyObject *
guestfs_int_py_put_lvm_vg_list (struct guestfs_lvm_vg_list *lvm_vgs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_vgs->len);
  for (i = 0; i < lvm_vgs->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_lvm_vg (&lvm_vgs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME
PyObject *
guestfs_int_py_put_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  PyObject *list;
  size_t i;

  list = PyList_New (btrfssubvolumes->len);
  for (i = 0; i < btrfssubvolumes->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_btrfssubvolume (&btrfssubvolumes->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_MDSTAT
PyObject *
guestfs_int_py_put_mdstat_list (struct guestfs_mdstat_list *mdstats)
{
  PyObject *list;
  size_t i;

  list = PyList_New (mdstats->len);
  for (i = 0; i < mdstats->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_mdstat (&mdstats->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_NODE
PyObject *
guestfs_int_py_put_hivex_node_list (struct guestfs_hivex_node_list *hivex_nodes)
{
  PyObject *list;
  size_t i;

  list = PyList_New (hivex_nodes->len);
  for (i = 0; i < hivex_nodes->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_hivex_node (&hivex_nodes->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STAT
PyObject *
guestfs_int_py_put_stat_list (struct guestfs_stat_list *stats)
{
  PyObject *list;
  size_t i;

  list = PyList_New (stats->len);
  for (i = 0; i < stats->len; ++i)
    PyList_SetItem (list, i, guestfs_int_py_put_stat (&stats->val[i]));
  return list;
};
#endif

